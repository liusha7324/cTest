#include "sfr64a.h"
#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "multi.h"
#include "ram.h"
#include "seg.h"
#include "loadrecord.h"
#include "AllVoltageLoss.h"
#include "att7022_operation.h"
#include "freeze.h"    //mw added 2009-02-14
#include "Measure_Interface.h" 
#include "initram.h"
#include "MB_Showmain.h"
#include "File_System.h"
#include "ICcard.h"
#include "eventnew.h"
#include "pay_def.h"	//payment
#include "Ex_Pay_For_Fun.h"

#define  CRC_CAL_RECTIFY     0X5A

unsigned char BK_Energy_Addr;  //0xff-shoult write F_ENERGY_RECORD ,0-shoult write THIS_MONTH_DATA_ROM
                               //backup energy in turn
union BYTE_DEF gPD_Data_valid_flag;//b0  0--powerdown save data crc invalid  1--powerdown save data crc valid
                                   //b1  0--powerdown energy data  invalid   1--powerdown energy data  valid
                                   //b2  0--powerdown data are all 0 or ff   1--powerdown data are not all 0 or ff
                                   //b3  0--is innormal reset                1--is normal reset
void Check_Energy_main(unsigned char kind);
unsigned char Energy_Deal_Run(void);
unsigned char PD_data_chk(void);
unsigned char PD_energy_Deal(void);
void Write_TO_Cal_PowerDown_Energy_add(void);
unsigned char  ALL_TotalEnergyRight(struct ENERGY_RECORD *scr_addr);
unsigned char  Check_Eeprom_energy_zero(void);
void RecordRectifyEnergyEvent(unsigned char Recordflag,unsigned char Rectifytype);
void Powerup_rail_energy_deal(void);
void Clear_Energy_Deal(void);
/*"============================================================
函数说明：检查电量数据主函数
输入参数：kind 0 上电检查      
               1 运行检查（每30分钟检查一次）
               2 电量清零或设置初始值处理
输出参数：无
返    回：无  
作    者：GANJP  版本：1.00
============================================================"*/
void Check_Energy_main(unsigned char kind)
{
	union BYTE_DEF ret_value;
	
	ret_value.byte = 0;
	if(kind == 0)//powerup deal
		{
			ret_value.byte = Energy_Deal_Run();
			if((ret_value.bit.b0 == 0) && ((ret_value.byte & 0x06) != 0))
				{
					This_Month_Data.Energy_Record.crc_cal += CRC_CAL_RECTIFY;
					PD_energy_Deal();
				}
			else
				{
					PD_data_chk();
				/*"RAM中电量有效且已经成功备份到内卡中，则需求清上电电量处理标志"*/
				/*"防止异常情况下电量重复累加的问题"*/
				if(ret_value.bit.b3 != 0)
				{
					Clear_Savedata_flag();
				}					
				}
			Powerup_rail_energy_deal();
		}
	else if(kind == 1)//run deal
		{
			ret_value.byte = Energy_Deal_Run();
			if(energy_rail.crc_cal == CRC((unsigned char*)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2))
			{
        WRLC256(ENERGY_RAIL_DATA_ROM,(unsigned char *)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER),0,0);
      }
		}
	else if(kind == 2)//clear energy
		{
			Clear_Energy_Deal();
		}
		
	Write_TO_Cal_PowerDown_Energy_add();
}
/*"============================================================
函数说明：检查RAM中电量数据是否有效
输入参数：scr_addr RAM中数据地址
输出参数：无
返    回：data_valid  ：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Check_RAM_energy(struct ENERGY_RECORD *scr_addr)
{
	unsigned char data_valid = 0;
	
	data_valid = Check_RAM_CRC((unsigned char *)scr_addr,          //check crc validity
	                            scr_addr->crc_cal,
	                            sizeof(struct ENERGY_RECORD)- 2);
	if(data_valid)
		{
			data_valid = ALL_TotalEnergyRight(scr_addr);
		}
	
	return (data_valid);
} 
/*"============================================================
函数说明：检查eeprom中电量数据是否有效
输入参数：eeprom_addr  eeprom中数据地址
输出参数：无
返    回：data_valid  ：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Check_Eeprom_energy(unsigned int eeprom_addr)
{
	unsigned char data_valid = 0;
	unsigned int uni;
	
	for(uni = 0; uni < sizeof(struct ENERGY_RECORD); uni++)
	  Co.b[300 + uni] = 0;
	
	ReadBlock(eeprom_addr, (unsigned char*)&Co.b[300],sizeof(struct ENERGY_RECORD),0); 
	
	data_valid = Check_RAM_energy((struct ENERGY_RECORD *)&Co.b[300]);
			
	return (data_valid);
}

/*"============================================================
函数说明：电量数据恢复
输入参数：ROM1_addr  EEPROM主备份地址
          ROM2_addr  EEPROM副备份地址
          RAM_addr   RAM中数据地址
          kind       恢复类型 1 RAM TO ROM1_addr AND ROM2_addr in turn
                              2 ROM1_addr TO RAM AND ROM2_addr
                              3 ROM2_addr TO RAM AND ROM1_addr
输出参数：无
返    回：ret_value  ：0 恢复失败  1 恢复成功
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Energy_Data_Resume(unsigned int ROM1_addr,unsigned int ROM2_addr,
                                 unsigned char *RAM_addr,unsigned char kind)
{
	unsigned char ret_value = 0;
	unsigned int  eeprom_addr;
	unsigned int  len = 0;
	
	switch(kind)
	{
		case 0x01:
			len = sizeof(struct ENERGY_RECORD);
			This_Month_Data.Energy_Record.crc_cal = CRC((unsigned char*)&This_Month_Data,len - 2);
			if(BK_Energy_Addr)
				eeprom_addr = ROM1_addr;
			else
				eeprom_addr = ROM2_addr;
			if(!IntoPowerDownFlag)
				{
					ret_value = WRLC256(eeprom_addr,(unsigned char *)&This_Month_Data,         //resume to back rom inturn
		    	                    sizeof(struct ENERGY_RECORD),0,0); 
		    	BK_Energy_Addr = ~BK_Energy_Addr; 
				}
			                     
			break;
		case 0x02:
			ReadBlock(THIS_MONTH_DATA_ROM, (unsigned char*)&This_Month_Data, 
			          sizeof(struct ENERGY_RECORD),0);                                    //resume to ram
			if(0xff != IntoPowerDownFlag) 
			{
			ret_value = WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,         //resume to back rom
			                    sizeof(struct ENERGY_RECORD),0,0); 
			}
			
			break;
		case 0x03:
			ReadBlock(F_ENERGY_RECORD, (unsigned char*)&This_Month_Data, 
			          sizeof(struct ENERGY_RECORD),0);                                     //resume to ram
			if(0xff != IntoPowerDownFlag) 
			{
			ret_value = WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,     //resume to main rom
			                    sizeof(struct ENERGY_RECORD),0,0); 
			}			
			break;
		default: break;
	}
	return (ret_value);
}
/*"============================================================
函数说明：比较EEPROM中两备份电量数据哪个更有效
输入参数：ROM1_addr  EEPROM主备份地址
          ROM2_addr  EEPROM副备份地址
          range      数据有效范围
输出参数：无
返    回：ret_value  ：1 ROM1_addr 更有效  2 ROM2_addr更有效  0 数据超范围 报错
作    者：GANJP  版本：1.00
============================================================"*/
#define  INDEX_ENERGYPASSMAXTIMES   (24*MAXTRIFF+72)
unsigned char WhichEnergyMoreRight(unsigned int ROM1_addr,unsigned int ROM2_addr,unsigned long range)
{
   unsigned int i;
   unsigned long rom1Total=0;
   unsigned long rom2Total=0;
   
   for(i = 0; i < sizeof(struct ENERGY_RECORD); i++)
	  Co.b[300 + i] = 0;
	  
   ReadBlock(ROM1_addr, (unsigned char*)&Co.b[300], sizeof(struct ENERGY_RECORD),0); 
                                     
   for(i=0;i<6;i++)
   {
       rom1Total+=((*((unsigned long *)&Co.b[300]+i*MAXTRIFF))
                  +(*((unsigned char *)&Co.b[300]+INDEX_ENERGYPASSMAXTIMES+i))*1000000000l);
   }
   
   ReadBlock(ROM2_addr, (unsigned char*)&Co.b[300], sizeof(struct ENERGY_RECORD),0); 
                                     
   for(i=0;i<6;i++)
   {
       rom2Total+=((*((unsigned long *)&Co.b[300]+i*MAXTRIFF))
                  +(*((unsigned char *)&Co.b[300]+INDEX_ENERGYPASSMAXTIMES+i))*1000000000l);
   }
   
   if(ABS(rom1Total-rom2Total) < range) 
   	{
   		if(rom1Total > rom2Total)
      {
        return 1;//in range and ram1Total>ram2Total
      }
      else
      {
      	return 2;//in range and ram2Total>ram1Tota1
      }
   	}
   else
   	{
   		return 0;//over range
   	}     
}

/*"============================================================
函数说明：运行过程中电量数据处理,RAM中数据有效，备份RAM中数据到EEPROM，否则
          检查EEPROM中数据（主数据THIS_MONTH_DATA_ROM和备份数据F_ENERGY_RECORD）;
          EEPROM中数据都正确，取最大数据进行恢复，否则取有效数据进行恢复，都不正
          确，报警。RAM中数据不正确记录电量纠错事件
输入参数：无
输出参数：无
返    回：ret_value        b0 ram data validity               0 invalid  1 valid
	                         b1 this_month eeprom data validity 0 invalid  1 valid
	                         b2 back data in eeprom validity    0 invalid  1 valid	                         
作    者：GANJP  版本：1.00
============================================================"*/
#define RecordStart    0
#define RecordEnd     1
#define nocare           0    

unsigned char Energy_Deal_Run(void)
{
	union BYTE_DEF ret_value;/*b0 ram data validity               0 invalid  1 valid
	                           b1 this_month eeprom data validity 0 invalid  1 valid
	                           b2 back data in eeprom validity    0 invalid  1 valid*/
	                           //b3 ram data valid and back to eeprom ok ganjp added 2013-02-27
	unsigned char which = 0;
	unsigned int uni = 0;
	unsigned char resume_ok = 0;//energy resume ok flag 0 resume err  1resume ok
	
	ret_value.byte = 0;
	
	ret_value.bit.b0 = Check_RAM_energy((struct ENERGY_RECORD *)&This_Month_Data);
	if(ret_value.bit.b0 == 0)//ram data err
		{
			ret_value.bit.b1 = Check_Eeprom_energy(THIS_MONTH_DATA_ROM);
			ret_value.bit.b2 = Check_Eeprom_energy(F_ENERGY_RECORD);
			if(!IntoPowerDownFlag)
			RecordRectifyEnergyEvent(RecordStart,ret_value.byte);
			
			switch(ret_value.byte&0x06)
			{
				case 0x02:                                                    //this month rom data right
					Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                             (unsigned char *)&This_Month_Data,2);					
					break;
				case 0x04:                                                   //the back rom data right
					Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                             (unsigned char *)&This_Month_Data,3);
					break;                           
				case 0x06:                                                    //both right
					which = WhichEnergyMoreRight(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,600000);
					if(which == 1)
						{
							Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                                 (unsigned char *)&This_Month_Data,2);				
						}
					else if(which == 2)
						{
							Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                                 (unsigned char *)&This_Month_Data,3);		
						}
					else if(which == 0)
						{
							//////energy err!!!!!!!!!!
							Meter_States.Meter_Flag.bit.Eeprom_Data_Err = 1;
							Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                                 (unsigned char *)&This_Month_Data,2);
						}
					else
						{
							
						}
					break;
				case 0x00://both err
					//////energy err!!!!!!!!!!
					Meter_States.Meter_Flag.bit.Eeprom_Data_Err = 1;
					Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                                 (unsigned char *)&This_Month_Data,2);
					break;
				default: break;
			}
		if(!IntoPowerDownFlag)	
		RecordRectifyEnergyEvent(RecordEnd,nocare);
		}
	else                    //ram data right
		{
			resume_ok = Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                                         (unsigned char *)&This_Month_Data,1);
			if(resume_ok != 0)
			{
				ret_value.bit.b3 = 1;
			}
		}
//	if(ret_value.byte == 0)	
//		{
//			ret_value.bit.b3 = Check_Eeprom_energy_zero();
//			if(ret_value.bit.b3)
//				{
//					for(uni=0;uni<sizeof(struct ENERGY_RECORD);uni++)//clear This_Month_Data
//		       {
//		       	*((unsigned char *)&This_Month_Data.Energy_Record+uni) = 0;
//		       }
//				}
//		}
	return (ret_value.byte);
}

/*"============================================================
函数说明：检查RAM中掉电存数数据有效性
输入参数：struct POWERDOWN_SAVE_DATA *PD_Save_data  掉电存数数据指针
输出参数：无
返    回：ret_value  0  无效   1 有效  
作    者：GANJP  版本：1.00
============================================================"*/
#define  DIFFERENCE_LIMIT     100l
unsigned char CheckPowerDownSave(struct POWERDOWN_SAVE_DATA *PD_Save_data)
{
  unsigned int i;
  unsigned int j;
  unsigned char ret_value=0;
  unsigned int length=0;  
  
  
  ret_value = IsNormalReset(0);
  if(ret_value == 0)
  	{
  		return 0;
  	}
  else
  	{
  		gPD_Data_valid_flag.bit.b3 = 1;
  	}
  
  length=sizeof(struct POWERDOWN_SAVE_DATA);  

  for(i=0;i<(length-2);i++)
  {
     if(((*((unsigned char *)PD_Save_data+i))!=0) && ((*((unsigned char *)PD_Save_data+i))!=0xff))
         {
         	   gPD_Data_valid_flag.bit.b2 = 1;
         	   break;   
         }
  }
  if(i == (length-2))
  	{
  		gPD_Data_valid_flag.bit.b2 = 0;
  	}

  ret_value = Check_RAM_CRC((unsigned char *)PD_Save_data, PD_Save_data->crc_cal, length-2);
  if(ret_value)        //crc right
  	{
  		gPD_Data_valid_flag.bit.b0 = 1;
  		for(i=0;i<6;i++)
       {
         /*"总和分费率电量之差不能大于DIFFERENCE_LIMIT"*/
         if((*((unsigned int*)PD_Save_data+i*2))>=(*((unsigned int*)PD_Save_data+i*2+1)))
           j=(*((unsigned int*)PD_Save_data+i*2))-(*((unsigned int*)PD_Save_data+i*2+1));
         else
           j=(*((unsigned int*)PD_Save_data+i*2+1))-(*((unsigned int*)PD_Save_data+i*2));
         
         if(j>DIFFERENCE_LIMIT)
         {
         	gPD_Data_valid_flag.bit.b1 = 0;
             return 0;
         }	
       }
      for(i=0;i<12;i++)
       {
       	/*"30分钟电量不能大于65kWh"*/
          if(*((unsigned int*)PD_Save_data+i)>65000)
          	{
          		gPD_Data_valid_flag.bit.b1 = 0;
          		return 0;
          	}
             
       }
      gPD_Data_valid_flag.bit.b1 = 1;
      return 1;	  				
  	}
  else
  	{
  		gPD_Data_valid_flag.bit.b0 = 0;
  		return 0;
  	}      
  return (ret_value);
}

/*"============================================================
函数说明：掉电存数数据累加到当前运行电量中
输入参数：struct POWERDOWN_SAVE_DATA *PD_Save_data  掉电存数数据指针
输出参数：无
返    回：ret_value  0  无效   1 有效  
作    者：GANJP  版本：1.00
============================================================"*/
void Powerdown_to_ThisMonth(void)
{   
  unsigned int i;
  unsigned char resume_ok = 0;//energy resume ok flag 0 resume err  1 resume ok

CheckPowerDown();
	for(i=0;i<6;i++)
	{
	  *((unsigned long *)&This_Month_Data+MAXTRIFF*i+0)+=*((unsigned int *)&Powerdown_Save_Data+2*i+0);
	  *((unsigned long *)&This_Month_Data+MAXTRIFF*i+Powerdown_Save_Data.fee)+=*((unsigned int *)&Powerdown_Save_Data+2*i+1);
	}
	for(i=0;i<72;i++)
	{
	  *((unsigned char *)&This_Month_Data.Energy_Record.Phase_Plus_Active+i)=*((unsigned char *)&Powerdown_Save_Data.energy_powerdown.Phase_Plus_Active+i);
	}
      for(i= 0; i <sizeof(struct PRE_SAVE_DATA);i++ )
	{
	    *((unsigned char *)&This_Month_Data.Energy_Record.Pre_Save_Data+i) = *((unsigned char *)&Powerdown_Save_Data.Pre_Save_Data + i);
	}
	
//	This_Month_Data.Energy_Record.crc_cal = CRC((unsigned char*)&This_Month_Data,
//	                                             sizeof(struct ENERGY_RECORD) - 2);
  
	resume_ok = Energy_Data_Resume(THIS_MONTH_DATA_ROM,F_ENERGY_RECORD,
                             (unsigned char *)&This_Month_Data,1);
/*"电量处理完成且成功备份到内卡后清上电电量处理标志，"*/
/*"防止备份不成功的异常情况下漏补电量"*/
if(resume_ok != 0)
{
    Clear_Savedata_flag();
}
  
  CheckPowerDown();
}

/*"============================================================
函数说明：掉电存数数据处理合法性判断
输入参数：无
输出参数：无
返    回：ret_value  0 无效    1 有效  
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char PD_data_chk(void)
{
	unsigned char ret_value = 0;
	
		//---------check power save data------------------------ 
	    ret_value = CheckPowerDownSave((struct POWERDOWN_SAVE_DATA *)&Powerdown_Save_Data);	
	      if(ret_value == 0)	//ram err
	      		{
	      		ReadBlock(POWERDOWN_SAVE_DATA_ROM, (unsigned char*)&Powerdown_Save_Data, sizeof(struct POWERDOWN_SAVE_DATA),0);
	      		ret_value = CheckPowerDownSave((struct POWERDOWN_SAVE_DATA *)&Powerdown_Save_Data);  		
			/*if (ret_value==0) 
				Pay_For_Para_Down_Check();	//payment*/
	      		}	
 
  return (ret_value);
}

/*"============================================================
函数说明：掉电存数数据处理（上电This_Month_data在RAM中数据无效时需要调用）
输入参数：无
输出参数：无
返    回：ret_value  0 失败    1 成功  
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char PD_energy_Deal(void)
{
	unsigned char ret_value = 0;
	
	ret_value = PD_data_chk();
	if(ret_value)
  	{
  		if(IsHaveSaveData())
  			{
  				Powerdown_to_ThisMonth();
  			} 
		else
			{
			      This_Month_Data.Energy_Record.crc_cal -= CRC_CAL_RECTIFY;
			}
  	}	
	else
	{
	      This_Month_Data.Energy_Record.crc_cal -= CRC_CAL_RECTIFY;	      
	}
  return (ret_value);
}

/*"============================================================
函数说明：每30分钟备份当前电量（总和当前费率），用于掉电存数时计算差值
输入参数：无
输出参数：无
返    回：无  
作    者：GANJP  版本：1.00
============================================================"*/
void Write_TO_Cal_PowerDown_Energy_add(void)
{
  unsigned int i;
  
  for(i=0;i<6;i++)
  {
	*((unsigned long *)&Cal_PowerDown_Energy_add+2*i+0)=*((unsigned long *)&This_Month_Data+MAXTRIFF*i+0);
  *((unsigned long *)&Cal_PowerDown_Energy_add+2*i+1)=*((unsigned long *)&This_Month_Data+MAXTRIFF*i+TRAFF_RATE); 
  }     
	   
}


/*”某项总和尖峰平谷的差范围是否越界“*/
/*  
  PLUS_ACTIVE_INDEX     0
  NEGE_ACTIVE_INDEX     1
  QUAD_1_RECTIVE_INDEX  2
  QUAD_2_RECTIVE_INDEX  3
  QUAD_3_RECTIVE_INDEX  4
  QUAD_4_RECTIVE_INDEX  5 */

#define  ENERGY_DIFFERENCE_LIMIT     6000l
unsigned char TotalEnergyRight( struct ENERGY_RECORD *scr_addr,const unsigned char which)
{
    unsigned char i;
    unsigned long total=0;
    unsigned long AddTotal=0;
    unsigned long EnergyLimit;

    EnergyLimit=Cal_EnergyLimit();
    
    total=*((unsigned long *)scr_addr+which*MAXTRIFF);   
    
     for(i=1;i<MAXTRIFF;i++)
     {
          AddTotal+=*((unsigned long *)scr_addr+which*MAXTRIFF+i);
          if(AddTotal>EnergyLimit)
         {
               AddTotal-=EnergyLimit;
          }
     }
   
     if(ABS(total-AddTotal)<ENERGY_DIFFERENCE_LIMIT || (EnergyLimit-ABS(total-AddTotal))<ENERGY_DIFFERENCE_LIMIT)
     {
        return 0xff;
     }
     else
     {
        return 0x0;//error
     } 
};

/*”所有6项总和尖峰平谷的差范围是否越界“*/
unsigned char  ALL_TotalEnergyRight(struct ENERGY_RECORD *scr_addr)
{
   unsigned char i;
   for(i=0;i<6;i++)
   {
      if(TotalEnergyRight(scr_addr,i)==0)
       return 0;//error
   }
  return 1;//right
}


/*"做电量纠错记录"*/
//Recordflag=0 start ,1 end    Rectifytype mean: rectify flag,when  record end use: nocare 
void RecordRectifyEnergyEvent(unsigned char Recordflag,unsigned char Rectifytype)
{
      unsigned char unc;
      unsigned int  uni;
      
      if(Recordflag==RecordStart)
      	{
      		//------pointer ---------//
      		Event_Meter_Pro_Pointer.AdjustEnergy_P++;	   
          if(Event_Meter_Pro_Pointer.AdjustEnergy_P > 31)
             Event_Meter_Pro_Pointer.AdjustEnergy_P=0;  
		              
      	 //------time---------//
      	  for(unc=0;unc<5;unc++)
            Co.b[300+unc]=*((unsigned char *)&softdate+unc);
	      //------flag---------//
	        Co.b[305]=Rectifytype;
		 //------rectify before: energy---------//
	        for(unc=0;unc<216;unc++)  //216=54*4
	        {
	        		Co.b[306+unc]=*((unsigned char *)&This_Month_Data.Energy_Record+unc);
	        }
	      FeedWatchdog();
        uni=ADJUSTENERGY_1_BEGINFILE + Event_Meter_Pro_Pointer.AdjustEnergy_P;
        Write_File(uni,0,222,&Co.b[300]);
        FeedWatchdog();
      	}
	else
	{
	      //------rectify end: energy ---------//
	     for(unc=0;unc<216;unc++)  //216=54*4
	     {
	        Co.b[300+unc]=*((unsigned char *)&This_Month_Data.Energy_Record+unc);
	     }    
       //write to flash here     
	     uni=ADJUSTENERGY_2_BEGINFILE + Event_Meter_Pro_Pointer.AdjustEnergy_P;
       FeedWatchdog();
       Write_File(uni,0,216,&Co.b[300]);
       FeedWatchdog(); 
       Save_EventTimesANDPointer_4byte(ADJUSTENERGY_P_ROM,ADJUSTENERGY_TIMES_ROM,
	     ((unsigned char *)&Event_Meter_Pro_Pointer.AdjustEnergy_P),
	     (&Event_Meter_Pro_Times.AdjustEnergy_Times));             
	}
}
/*"============================================================
函数说明：检查EEPROM中电量值是否都为0
输入参数：无
输出参数：无
返    回：ret_value   0 no    1  yes   
作    者：GANJP  版本：1.00
============================================================"*/
//unsigned char Check_Eeprom_energy_zero(void)
//{
//	unsigned char ret_value = 1;
//	unsigned int uni;	
//	
//	ReadBlock(THIS_MONTH_DATA_ROM, (unsigned char*)&Co.b[300],sizeof(struct ENERGY_RECORD),0); 
//	
//	for(uni = 0; uni < sizeof(struct ENERGY_RECORD); uni++)
//	{
//		if(Co.b[300 + uni] != 0)
//			{
//				ret_value = 0;
//				break;
//			}
//	}
//	if(ret_value != 0)
//		{
//			ReadBlock(F_ENERGY_RECORD, (unsigned char*)&Co.b[300],sizeof(struct ENERGY_RECORD),0); 
//				
//	    for(uni = 0; uni < sizeof(struct ENERGY_RECORD); uni++)
//	    {
//	    	if(Co.b[300 + uni] != 0)
//	    		{
//	    			ret_value = 0;
//	    			break;
//	    		}
//	    }
//		}
//
//	return (ret_value);
//}
/*"============================================================
函数说明：上电检查RAM中电量尾数值是否合法，不合法清零尾数空间，
          将丢失尾数电量。
输入参数：无
输出参数：无
返    回：无     
作    者：GANJP  版本：1.00
============================================================"*/
//#define  RAILENERGY_VALIDITY_LIMIT    500000l
void Powerup_rail_energy_deal(void)
{
	unsigned char data_valid = 0;
	unsigned int  uni = 0;
	
	data_valid = Check_RAM_CRC((unsigned char *)&energy_rail, energy_rail.crc_cal,
	                            sizeof(struct ENERGY_RAIL_ADD_BUFFER)- 2);//check crc validity
	if(data_valid == 0)//data invalid
		{
			ReadBlock(ENERGY_RAIL_DATA_ROM, (unsigned char*)&energy_rail, sizeof(struct ENERGY_RAIL_ADD_BUFFER),0);
      data_valid = Check_RAM_CRC((unsigned char *)&energy_rail, energy_rail.crc_cal,
	                                sizeof(struct ENERGY_RAIL_ADD_BUFFER)- 2);//check crc validity 
	    if(data_valid == 0)
	    	{
	    		for(uni = 0; uni < sizeof(struct ENERGY_RAIL_ADD_BUFFER); uni++)
			    {
			    	*((unsigned char *)&energy_rail + uni) = 0;//clear rail energy data
			    }
	    	}			
		}
	//else   //crc ok
	//	{
	//		for(uni = 0; uni < 24; uni++)
	//		{
	//			if(*((unsigned long *)&energy_rail.Rail_Plus_Active[0]+uni)>RAILENERGY_VALIDITY_LIMIT)
	//				{
	//					*((unsigned long *)&energy_rail.Rail_Plus_Active[0]+uni)=0;
	//				}
	//		}
	//	}
}

/*"============================================================
函数说明：电量清零或设置初始值后需重新计算CRC校验和，并备份到内卡
输入参数：无
输出参数：无
返    回：无     
作    者：GANJP  版本：1.00
============================================================"*/
void Clear_Energy_Deal(void)
{
	unsigned int length = 0;
	
  length = sizeof(struct ENERGY_RECORD);
	This_Month_Data.Energy_Record.crc_cal 
	                  = CRC((unsigned char*)&This_Month_Data,length - 2);
	                  
	WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,         
			    sizeof(struct ENERGY_RECORD),0,0);
			    
	WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,   
			    sizeof(struct ENERGY_RECORD),0,0);
}
