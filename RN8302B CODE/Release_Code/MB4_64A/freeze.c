/*"冻结程序 for DL645-2007"*/
/*"creat by trend "*/
/*"ver 1.0 2008-10-25 10:54:27"*/
#include  "defmcro.h"
#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "Freeze.h"
#include "File_System.h"   //mw added 2009-02-12
#include "Multi.h"
#include "Measure_Interface.h" 
#include "ICcard.h"
#include "645_2007.h"
#include "pay_def.h"
#include "Ex_Pay_For_Fun.h"
#include "LoadRecord.h"

#define  MAX_DAYFREEZE_POWERUP_STRIDE    7       /*"上电补日冻结数据点最大个数"*/


///unsigned char DayFreezePowerupComplete;        /*"上电补日冻结数据完成标志"*/
///unsigned int stridebill_dot_num = 0;/*""*/
///unsigned int stridefreeze_dot_num = 0;/*""*/
///unsigned int stridefreezePrebill_dot_num = 0;/*""*/

//#pragma SECTION rom UserROMData
const unsigned char DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned long DateToDays(TDateTime* rpDateTime);
unsigned char DateTimeToInt(TDateTime* rpDateTime, unsigned long *pSeconds);
void IntToDate(unsigned long rInt, TDate* rpDate);
void IntToDateTime(unsigned long rInt, TDateTime* rpDateTime);
signed int GetSkipedTimeFlags(TDateTime* rpTime1, TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax);
void PowerUpDayFreeze(void);
///void Dayfreeze_Recompense(TDateTime * StrideFreeze_Dot_List, unsigned char demand_zero_flag,unsigned int stridebill_dot_start_num,unsigned int freezeday_num );///king chen add 130105
void Dayfreeze_Recompense(unsigned char  demand_flag, unsigned char * StrideFreeze_Dot);///king chen modify 130609
unsigned char ComparentTime(unsigned char *t1, unsigned char *t2);///king chen add 130302

void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime);///king chen modify 130609
void Day_freeze(unsigned char sort);
void FreezeDateProgram_HourOrDay(unsigned char kind1,unsigned char  kind2,unsigned char  sort);
void Clear_HDFreezeData(void);
void PoweronFreeze_Deal(void);
void Freeze_Period(void);
void Freeze_Day(void);
void Clear_Freeze_Period(void);
void ClearFreezeCommDeal(unsigned long Data_ID);

//#pragma SECTION program program_protect

//unsigned char  Freeze_Flag_DayHour[2];	

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"============================================================"*/
/*"函数名：Freeze_Main"*/
/*"用途：冻结模块主函数"*/
/*"参数：无"*/
/*"返回：无"*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
void Freeze_Main(void)
{
    unsigned char pointer=0;	
	if(IntoPowerDownFlag==0)     /*"正常上电执行，低功耗不执行"*/
	{
		 if(((Meter_Parameter.freeze_parameter.FreezeDate[3]==softdate.Month)||(Meter_Parameter.freeze_parameter.FreezeDate[3]==0x99))
		 	&&((Meter_Parameter.freeze_parameter.FreezeDate[2]==softdate.Day)||(Meter_Parameter.freeze_parameter.FreezeDate[2]==0x99))
		 	&&((Meter_Parameter.freeze_parameter.FreezeDate[1]==softdate.Hour)||(Meter_Parameter.freeze_parameter.FreezeDate[1]==0x99)) 
		 	&& (Meter_Parameter.freeze_parameter.FreezeDate[0]==softdate.Min))
	   {  	                		  	
         	
         	ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr
	        ,FREEZE_TIME_SORT_START_FILE);/*"冻结清零判断处理"*/
         			
         	pointer=O1ther_Meter_Parameter.FreezeData_Time_addr;
		   		FreezeDateProgram(FREEZE_TIME_SORT_START_FILE+pointer, 1, (unsigned char *)&softdate);///king chen modify 130609
		   	  pointer++;
		   		pointer%=MAX_NUMBER_FREEZE_TIME;
					O1ther_Meter_Parameter.FreezeData_Time_addr=pointer;
				  WRLC256(FREEZE_TIME_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr,1,0,0);
				  ////Set_Meter_para_Deal(FREEZE_TIME_ADDR_ROM);
				  FeedWatchdog(); 
	       
	   } 
	            	  
	   Freeze_Period();
	   Freeze_Day();
    }
}

/*"============================================================"*/
/*"函数名：Freeze_Period"*/
/*"用途：周期冻结主函数"*/
/*"参数：无"*/
/*"返回：无"*/
/*"作者：fuxf 版本：1.00"*/
/*"============================================================"*/
void Freeze_Period(void)
{
        unsigned int  uni,freeze_interval,pointer=0;				
		struct DATEANDTIME_DEF		temp_date;		
		signed long  long time1;	

        //if((Meter_Parameter.New645_Freeze_Period_Mode.byte&0x03)==0)
        //    return ;

        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Sec=0;
        if(CheckTime((unsigned char *)&Meter_Parameter.freeze_parameter.Freeze_Period_Date)==0)
            return ;

		if((Meter_Parameter.freeze_parameter.Freeze_Period_Interval==0)||(Meter_Parameter.freeze_parameter.Freeze_Period_Interval>60))
			  freeze_interval=60; 			 
		else 		
		    freeze_interval=Meter_Parameter.freeze_parameter.Freeze_Period_Interval;

		temp_date=softdate;
		temp_date.Sec=Meter_Parameter.freeze_parameter.Freeze_Period_Date.Sec;
		time1=ComTime((unsigned char *)&temp_date,(unsigned char *)&Meter_Parameter.freeze_parameter.Freeze_Period_Date);

		time1=time1/60;
		if((time1>=0)&&((time1%freeze_interval)==0))
		{
			        pointer=O1ther_Meter_Parameter.FreezeData_Period_addr;
	            for(uni=0;uni<5;uni++) 		   				 
	               *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)&softdate+uni);	    
						
				      *((unsigned long *)&Co.b[300+5])=This_Month_Data.Energy_Record.Plus_Active[0];   
				      *((unsigned long *)&Co.b[300+9])=This_Month_Data.Energy_Record.Nega_Active[0];   
				      WRLC256(FREEZEDATA_PERIOD_ROM+pointer*13,(unsigned char *)&Co.b[300],13,0,0);
                      CheckPowerDown();
                      
					    pointer++;
		   				pointer%=MAX_NUMBER_FREEZE_PERIOD;
							O1ther_Meter_Parameter.FreezeData_Period_addr=pointer;
		   				WRLC256(FREEZE_PERIOD_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Period_addr,1,0,0);
		   				///Set_Meter_para_Deal(FREEZE_PERIOD_ADDR_ROM);
		   	            FeedWatchdog(); 			
		}
		
		return ;
}

/*"============================================================================="*/
/*"冻结数据 2008-7-9 15:31:06"*/
/*"  --------------------------------------------------------------------------"*/
/*"    kind1: 1 瞬时冻结2  时区切换,3 日时段表切换   ；"*/
/*"   *  kind2:  POINT  当前冻结的指针*"*/
/*"   *  kind3: 表示存内卡还是FLASH *"*////king chen mark 130609
/*"   *  demand_zero_flag:  1 表示需量存实际需量, 0表示需量值清零 *"*/
/*"   *  freezetime: 表示冻结的时间 *"*/
/*"    * 本函数只适用于MAXTRIFF <=15的情形*"*/
/*"冻结过程中掉电不补!added by fxf	2009-07-10"*/
/*"============================================================================="*/
void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime)///king chen modify 130609
{
     unsigned int uni,i,addr;
     unsigned int data_length;
	   struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
	   struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
	   
 	   p3_2=1;

	  data_length=5+sizeof(struct  FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA)+sizeof(struct FREEZE_POWER_DATA); 
   
      for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;   
	   /*"冻结时间"*/   
	  for(uni=0;uni<5;uni++) 
	       ////*((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)&softdate+uni);
               *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)freezetime+uni);
		
	  /*"冻结电能量"*/   
	  for(i=0;i<6;i++)
	  {
	        for(uni=0;uni<MAXTRIFF;uni++)
				*((unsigned long *)&Co.b[300+5]+MAXTRIFF*i+uni)=*((unsigned long *)&This_Month_Data.Energy_Record.Plus_Active[0]+MAXTRIFF*i+uni);
      }

		/*"冻结需量"*/	
	  addr=5+sizeof(struct  FREEZE_ENERGY_DATA);						 
	  Freeze_Demand_Data=(struct FREEZE_DEMAND_DATA *)&Co.b[300+addr];
      
 if(demand_zero_flag)
   {
     for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].Demand;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].Demand;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].time[i];
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].time[i];
    	}
     }
  }
 else
 {
     for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=0x00000000;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=0x00000000;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=0x00;
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=0x00;
    	}
     }
}
     /*"冻结变量"*/
	  addr=5+sizeof(struct	FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA);						
	  Freeze_Power_Data=(struct FREEZE_POWER_DATA *)&Co.b[300+addr];
		 	
	  for(uni=0;uni<4;uni++)
	  {
	     	Freeze_Power_Data->Active_power_t[uni]=COMM_Active_power[uni];
			Freeze_Power_Data->Reactive_power_t[uni]=COMM_Reactive_power[uni];				 
	  }
	  
	 CheckPowerDown();
	
	 Write_File(file_name,0,data_length,&Co.b[300]);

	 /*"电子钱包冻结"*/
	 if((file_name>=FREEZE_DAY_START_FILE)&&(file_name<(FREEZE_DAY_START_FILE+MAX_NUMBER_FREEZE_DAY)))								/*"Li_日冻结才有效"*/		//Li Update 20130506
		 F_E_BurseFreezeData();			//Li Update 20130320

     FeedWatchdog();     
	 CheckPowerDown();  
}


/*"============================================================"*/
/*"函数名：Freeze_Day"*/
/*"用途：日冻结"*/
/*"参数：无"*/
/*"返回：无"*/
/*"//added by fxf	2009-09-10"*/
/*"============================================================"*/
void Freeze_Day(void)
{
  unsigned int pointer;
  
	if((Meter_Parameter.freeze_parameter.FreezeDay_Hour==softdate.Hour)&&(Meter_Parameter.freeze_parameter.FreezeDay_Min==softdate.Min))
	{		
      ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr
	    ,FREEZE_DAY_START_FILE);/*"冻结清零判断处理"*/ 
	     
	    pointer=O1ther_Meter_Parameter.FreezeData_Day_Addr;
	    FreezeDateProgram(FREEZE_DAY_START_FILE+pointer, 1, (unsigned char *)&softdate);///king chen modify 130609
  	  pointer++;
  	  pointer%=MAX_NUMBER_FREEZE_DAY;	
      O1ther_Meter_Parameter.FreezeData_Day_Addr=pointer;
      WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr,1,0,0); 
      ///Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
      
	    O1ther_Meter_Parameter.DayFreezeReferenceDate=softdate;///king chen add 130302
	    O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
	    WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); 
  }
      
}
/*"============================================================"*/
/*"函数名：Clear_Freeze"*/
/*"用途：清冻结数据"*/
/*"参数：无"*/
/*"返回：无"*/
/*"NOTE：freeze.c",Initram.c,Interrupt.c,main.c,comm.c,comm.h,AllVoltageloss.c*/

/*"//added by FXF	2009-03-12"*/
/*"============================================================"*/




unsigned char  Clear_Freeze(void)
{ 	
		unsigned int i,length;
		CheckPowerDown();
	 	O1ther_Meter_Parameter.FreezeData_Time_addr=EVENT_CLAER_STATUS;	
		O1ther_Meter_Parameter.FreezeData_Moment_addr=EVENT_CLAER_STATUS; 	
		Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr=EVENT_CLAER_STATUS;				
		Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr=EVENT_CLAER_STATUS;		
		O1ther_Meter_Parameter.FreezeData_Period_addr=0; 	
		O1ther_Meter_Parameter.FreezeData_Day_Addr=EVENT_CLAER_STATUS; 
		WRLC256(FREEZE_TIME_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr,4,0,0);
		WRLC256(FREEZE_DALIYSLOT_ADDR_ROM,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr,1,0,0);
		WRLC256(FREEZE_TRIFF_ADDR_ROM,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr,1,0,0);
		
		///Set_Meter_para_Deal(FREEZE_TIME_ADDR_ROM);
		Set_Meter_para_Deal(FREEZE_DALIYSLOT_ADDR_ROM);

		Event_Meter_Pro_Pointer.Energypasszero_P=EVENT_CLAER_STATUS;		
		WRLC256(ENERGYPASSZERO_P_ROM,(unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P,1,0,0);
		FeedWatchdog(); 

		Pay_For_Event_Point.Triff_Switch_Event_P = EVENT_CLAER_STATUS;
		Pay_For_Event_Point.Step_Switch_Event_P = EVENT_CLAER_STATUS;
		Pay_For_Event_Point.E_Burse_Event_P = EVENT_CLAER_STATUS;
		WRLC256(TRIFF_SWITCH_EVENT_P_EE,(unsigned char *)&Pay_For_Event_Point.Triff_Switch_Event_P,2,0,0);
		WRLC256(E_BURSE_EVENT_P_EE,(unsigned char *)&Pay_For_Event_Point.E_Burse_Event_P,1,0,0);

        //Delete_File(FREEZE_TIME_SORT_START_FILE);
        //Delete_File(FREEZE_MOMENT_SORT_START_FILE);
        //Delete_File(FREEZE_TRIFF_CHANGE_SORT_START_FILE);
        //Delete_File(FREEZE_DAILYSLOT_CHANGE_START_FILE);
        //Delete_File(FREEZE_DAY_START_FILE);
        //Delete_File(FREEZE_ENERGYPASSZERO_START_FILE);		

        Clear_Freeze_Period();
            
		return 0xff;
}


void  Clear_Freeze_Period(void)
{ 	
		/*""unsigned int i,length;

		for(i=0;i<254;i++)
				Co.b[400+i]=0xFF;

		for(i=0;i<13;i++)
		{
		       WRLC256(FREEZEDATA_PERIOD_ROM+i*254,(unsigned char *)&Co.b[400],254,0,0);		
		       FeedWatchdog(); 
               CheckPowerDown();
		}
"*/
		WRLC256(FREEZEDATA_PERIOD_ROM, 0, 13 * 254, 0, 0);
}

/*"******************************************************************************"*/
/*"函 数 名：DateToDays"*/
/*"功    能：日期转换成距离2000年1月1日的天数"*/
/*" 说    明：需要先对日期的合法性进行检查	"*/
/*" 入口参数："*/
/*"	rpDateTime: 日期时间数据"*/
/*" 返 回 值:"*/
/*" 设   计：Hezhaohui             创建时间: 2011-11-11"*/
/*"******************************************************************************"*/



unsigned long DateToDays(TDateTime* rpDateTime)
{
	unsigned char nYear;
	unsigned char nMonth;
	unsigned char nDay;	
	unsigned long nDays;
	int i;
	
	nYear  = OB_H(rpDateTime->Year);
	nMonth = OB_H(rpDateTime->Month);
	nDay   = OB_H(rpDateTime->Day);
	
	nDays = ((365 << 2) + 1) * (nYear >> 2);
	nYear &= 0x03;
	
	nDays += nYear * 365;
	
	for(i=0; i<nMonth-1; i++)
	{
		nDays += DaysOfMonth[i];
	}
	
	nDays += nDay;
	
	if((nYear > 0) || (nMonth > 2))
	{
		nDays++;
	}
	
	return nDays-1;
}


/*"******************************************************************************"*/
/*" 函 数 名：DateTimeToInt"*/
/*" 功    能：日期时间数据转换为距离2000年1月1日0时0分0秒的秒数"*/
/*" 说    明：需要先对日期的合法性进行检查	"*/
/*" 入口参数："*/
/*"	rpDateTime: 日期时间数据"*/
/*" 返 回 值:"*/
/*" 设   计：Hezhaohui             创建时间: 2011-11-11"*/
/*"******************************************************************************"*/
unsigned char DateTimeToInt(TDateTime* rpDateTime, unsigned long *pSeconds)
{
	if(0 == CheckDateTime(rpDateTime))
	{
	    return 0;
	}
	*pSeconds = DateToDays(rpDateTime) * 24L * 60L * 60L;
	*pSeconds += OB_H(rpDateTime->Hour) * 60L * 60L;
	*pSeconds += OB_H(rpDateTime->Minute) * 60L;
	*pSeconds += OB_H(rpDateTime->Second);
	
	return 1;
}





/*"******************************************************************************"*/
/*" 函 数 名：CheckDateTime"*/
/*" 功    能：检查日期数据是否合法"*/
/*" 说    明：检查日期时间数据是否都为BCD码，且数据正确，不判断星期是否是日期一致，采用24小时制"*/
/*"     由于年份只采用一个字节，对于00年只对2000有效，2100~2900需重写"*/
/*" 入口参数："*/
/*" rpDateTime: 日期时间数据"*/
/*" 返 回 值:"*/
/*"  TRUE-数据合法"*/
/*"  FALSE-不合法"*/
/*" 设   计：Hezhaohui             创建时间: 2011-11-11"*/
/*"******************************************************************************"*/
unsigned char CheckDateTime(TDateTime* rpDateTime)					//HeZhaoHui    20131010
{
 unsigned char nMaxDay; 
  
 if(OB_H(rpDateTime->Second) > 99 || OB_H(rpDateTime->Minute) > 99
   || OB_H(rpDateTime->Hour) > 99 || OB_H(rpDateTime->Day) > 99
     || OB_H(rpDateTime->Month) > 99 || OB_H(rpDateTime->Year) > 99
	   || OB_H(rpDateTime->Week) > 7)
 {
  return 0;
 }

 
 if(rpDateTime->Hour > 0x23 || rpDateTime->Minute > 0x59 || rpDateTime->Second > 0x59)
 {
  return 0;
 }
 
 if(rpDateTime->Month < 1 || rpDateTime->Month > 0x12)
 {
  return 0;
 }
 
 nMaxDay = DaysOfMonth[OB_H(rpDateTime->Month)-1]; 
 if(((rpDateTime->Year & 0x13) == 0 || (rpDateTime->Year & 0x13) == 0x12) && rpDateTime->Month == 0x02) 
 {
  nMaxDay++;
 }
 if((0 == rpDateTime->Day) || (OB_H(rpDateTime->Day) > nMaxDay))
 {
  return 0;
 }
  
 return 1;
}





/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：IntToDate"*/
/*" 功    能：距离2000年1月1日的天数转换成年月日"*/
/*" 说    明：	   "*/
/*" 入口参数："*/
/*"	rInt：距离2000年1月1日的天数"*/
/*"	rpDate： 日期时间数据"*/
/*" 返 回 值:"*/
/*" 设   计：Hezhaohui             创建时间: 2011-11-11"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
void IntToDate(unsigned long rInt, TDate* rpDate)
{
	unsigned long tmp1;
	unsigned long tmp2;
	unsigned char nFlag;
	
	int i;
	
	
	tmp1 = rInt / (365*3+366);
	tmp2 = rInt % (365*3+366);
	rpDate->Year = (tmp1 << 2);
	
	nFlag = 0;
	
	if (tmp2 > (31 + 28 - 1))
	{
		tmp2--;
		nFlag = 1;
	}
	
	
	tmp1 = tmp2 / 365L;
	tmp2 = tmp2 % 365L;
	rpDate->Year += tmp1;
	
	tmp2++;
	
	
	for(i=0; i<12; i++)
	{
		if(tmp2 > DaysOfMonth[i])
		{
			tmp2 -= DaysOfMonth[i];
		}
		else
		{
			break;
		}
	}
	rpDate->Month = i+1;
	
	
	rpDate->Day = tmp2;
	
	
	if(nFlag && rpDate->Month == 2 && (rpDate->Year & 0x03) == 0)
	{
		rpDate->Day++;
	}
	
	
	rpDate->Year = OH_B(rpDate->Year);
	rpDate->Month = OH_B(rpDate->Month);
	rpDate->Day = OH_B(rpDate->Day);
}
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：IntToDateTime"*/
/*" 功    能：距离2000年1月1日0点0分0秒的秒数转换成年月日时分秒"*/
/*" 说    明：需确保输入数据的正确性，函数本身不做判断"*/
/*" 入口参数："*/
/*"    rInt：距离2000年1月1日0点0分0秒的秒数"*/
/*"    rpDateTime： 日期时间数据"*/
/*" 返 回 值:"*/
/*" 设   计：Hezhaohui             创建时间: 2011-11-11"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
void IntToDateTime(unsigned long rInt, TDateTime* rpDateTime)
{
    TDate nDate;
    unsigned long nRemainSeconds;
    unsigned long nDays;     
    nDays = rInt / (60L*60L*24L);
    nRemainSeconds = rInt % (60L*60L*24L);     
    IntToDate(nDays, &nDate);
    rpDateTime->Year  = nDate.Year;
    rpDateTime->Month = nDate.Month;
    rpDateTime->Day   = nDate.Day;     
    rpDateTime->Week = (nDays - 6) % 7;     
    rpDateTime->Hour = nRemainSeconds / 3600L;
    nRemainSeconds = nRemainSeconds % 3600L;
    rpDateTime->Minute = nRemainSeconds / 60L;
    rpDateTime->Second = nRemainSeconds % 60L;     // transform hour, minute and second to BCD
    rpDateTime->Hour = OH_B(rpDateTime->Hour);
    rpDateTime->Minute = OH_B(rpDateTime->Minute);
    rpDateTime->Second = OH_B(rpDateTime->Second);
}

/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：GetSkipedTimeFlags"*/
/*" 功    能：计算两个时间点之间跨越的设定时标数，并获取距离结束时间最近的若干个的时标集，按时间先后  逆序 排列 "*/
/*" 说    明："*/
/*"    起始时间、结束时间、设定时标必须为BCD码"*/
/*"    查找时标点包括结束时间点，但不包括起始时间点，如开始时间为2012-12-19 00:00:00，结束时间为2012-12-20 00:00:00"*/
/*"    如果设定时标为99-99-99 00:00:00，查找日过零点，则找到2012-12-20 00:00:00一个时标点"*/
/*" 入口参数："*/
/*"    rpTime1: 起始时间 week补0"*/
/*"    rpTime2: 结束时间 week补0"*/
/*"    rpTimeFlag: 设定时标，99代表通配，当低位有通配符时，高位自动通配 "*/
/*"    rpResult: 返回的查找到的时标集，按时间先后  逆序 排列 "*/
/*"    rMax:     rpResult中最大返回个数 "*/
/*" 返 回 值:"*/
/*"    查找到的时标个数， 0代表没有找到，-1代表输入参数有误 "*/
/*" 设   计：Hezhaohui             创建时间: 2012-12-20"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
int GetSkipedTimeFlags(TDateTime* rpTime1,TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax)
{
    unsigned long nTime1;
    unsigned long nTime2;
    unsigned long nDateTimeInt; /*"用来查找的时间，整数类型"*/
    
    int nCount; //count of results
    int nRunTimes; // count of while loops
    int i;
    
    unsigned char nMode; /*"时标类型"*/
    TDateTime nDateTime; /*"用来查找的时间，结构体类型"*/    

    // check input parameters
    if(0 == DateTimeToInt(rpTime1, &nTime1))
    {
        return -1;
    }
    if(0 == DateTimeToInt(rpTime2, &nTime2))
    {
        return -1;
    }       
   
    // find out time flag type
    for(nMode = 6; nMode > 0; nMode--)
    {
        if(*(((unsigned char*) rpTimeFlag) + nMode - 1) == 0x99)
        {
            break;
        }
    }

    // check valitation of rpTimeFlag    
    nDateTime = *rpTimeFlag;
    switch(nMode)
    {
        case 6:
            nDateTime.Second= 0;
        case 5:
            nDateTime.Minute = 0;
        case 4:
            nDateTime.Hour = 0;
        case 3:
            nDateTime.Day = 1;
        case 2:
            nDateTime.Month = 1;
        case 1:
            nDateTime.Year = 1;
        default:
            break;
    }
    nDateTime.Week = 0;
    if(0 == CheckTime((unsigned char *)&nDateTime))
    {
        return -1;
    }

    //if start time larger than end time, return error flag
    if(nTime1 > nTime2)
    {
        return 0;///king chen modify 130609
    }
    
    // make a time with 99 replaced by time2
    for(i = 6; i > nMode; i--)
    {
        *(((unsigned char*) &nDateTime) + i - 1) = *(((unsigned char*) rpTimeFlag) + i - 1);
    }
    for(i = nMode; i > 0; i--)
    {
        *(((unsigned char*) &nDateTime) + i - 1) = *(((unsigned char*) rpTime2) + i - 1);
    }    
    nDateTime.Week = 0;

    //if combined time invalid, return error flag
    if(0 == DateTimeToInt(&nDateTime, &nDateTimeInt))
    {
        return -1;
    }

    
    nCount = 0;
    nRunTimes = 0;
    while((nDateTimeInt > nTime1) && (nCount < rMax))// decrease result time to find out all time-flags
    {
        unsigned long nInterval;
        IntToDateTime(nDateTimeInt, &nDateTime);
        if(nDateTimeInt <= nTime2)
        {
            rpResult->Year = nDateTime.Year;
            rpResult->Month = nDateTime.Month;
            rpResult->Day = nDateTime.Day;
            rpResult->Hour = nDateTime.Hour;
            rpResult->Minute = nDateTime.Minute;
            rpResult->Second = nDateTime.Second;
            rpResult->Week = 0;
            rpResult++;
            nCount++;
        }
        switch(nMode)
        {
        case 6:
            nInterval = 1;
            break;
        case 5:
            nInterval = 60L;
            break;
        case 4:
            nInterval = (60L * 60L);
            break;
        case 3:
            nInterval = (24L * 60L * 60L);
            break;
        case 2:
        {
            unsigned char nYear = OB_H(nDateTime.Year);
            unsigned char nMonth = OB_H(nDateTime.Month);
            if(nMonth == 1)
            {
                nMonth = 12;
            } else
            {
                nMonth--;
            }
            nInterval = DaysOfMonth[nMonth - 1];
            if((nMonth == 2) && ((nYear & 0x03) == 0))
            {
                nInterval++;
            }
            nInterval *= (24L * 60L * 60L);
        }
            break;
        case 1:
        {
            unsigned char nYear = OB_H(nDateTime.Year);
			unsigned char nMonth = OB_H(nDateTime.Month); 
			unsigned char nDay = OB_H(nDateTime.Day); 
            nInterval = 365;
			if((((nYear & 0x03) == 0) && ((nMonth > 2)|| ((nMonth==0x02) && (nDay == 29)) )) ||(((nYear & 0x03) == 0x01) && (nMonth < 3))) 		//HeZhaoHui 20131009
			{
                nInterval++;
            }
            nInterval *= (24L * 60L * 60L);
        }
            break;
        case 0:
            nInterval = nTime2 - nTime1;
            break;
        }
        nDateTimeInt -= nInterval;

        nRunTimes++;
        if(nRunTimes > (rMax + 1))
        {
            break;       
        }
    }
    
    return nCount;
}


#pragma SECTION program ROM_PRG2

void PowerUpDayFreeze(void)
{
 ///unsigned int uni,addr;
 ///unsigned int file_name=0,data_length=0;
 ///unsigned int pointer=0;

///unsigned char DayFreezePowerupComplete;        /*"上电补日冻结数据完成标志"*/
 int stridebill_dot_num = 0;/*""*/
 int stridefreeze_dot_num = 0;/*""*/
 int stridefreezePrebill_dot_num = 0;/*""*/

 
 unsigned int freezeday_num;
 unsigned int stridebill_dot_start_num;///king chen add 130105
 
  unsigned char billdaygreater_flag=0;///king chen add 130228
  ///unsigned char FlashIsEmpty=0;///king chen mark 130302
  
  struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
  struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
  
 struct DATEANDTIME_DEF LastDayfreezeTime_temp;///king chen add 130319
 struct DATEANDTIME_DEF LastDayfreezeTime;/*"最近一次日冻结时间"*/
 struct DATEANDTIME_DEF Now_time;/*"上电时刻时间"*/
 struct DATEANDTIME_DEF DayFreeze_Dot;/*"设置的日冻结点"*/
 struct DATEANDTIME_DEF FirstBillDay_Dot;/*"设置的第一结算日"*/
 struct DATEANDTIME_DEF StrideBill_Dot_List[12];/*"掉电期间跨过的第一结算日时间点列表，最多查找最近12个"*/
 struct DATEANDTIME_DEF StrideFreeze_Dot_List[MAX_DAYFREEZE_POWERUP_STRIDE];
 struct DATEANDTIME_DEF StrideFreezePreBill_Dot_List[MAX_DAYFREEZE_POWERUP_STRIDE];

    Now_time = softdate;
/*"日冻结数据点时间参数"*/   
    DayFreeze_Dot.Year = 0x99;
    DayFreeze_Dot.Month= 0x99;
    DayFreeze_Dot.Day= 0x99;
    DayFreeze_Dot.Hour= Meter_Parameter.freeze_parameter.FreezeDay_Hour;
    DayFreeze_Dot.Min= Meter_Parameter.freeze_parameter.FreezeDay_Min;
    DayFreeze_Dot.Sec = 0;
    DayFreeze_Dot.Week= 0;
/*"第一结算日数据点时间参数"*/
    FirstBillDay_Dot.Year = 0x99;
    FirstBillDay_Dot.Month= 0x99;
    FirstBillDay_Dot.Day= Meter_Parameter.parameter1.AutoBillDayHour[0].Day;
    FirstBillDay_Dot.Hour= Meter_Parameter.parameter1.AutoBillDayHour[0].Hour;
    FirstBillDay_Dot.Min= 0;
    FirstBillDay_Dot.Sec = 0;
    FirstBillDay_Dot.Week= 0;
   #if 0  
    ///WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,1); 
     LastDayfreezeTime=O1ther_Meter_Parameter.DayFreezeReferenceDate;///king chen add 130302
	 
/// if((Check_Data_valid(&Co.b[300],data_length)==-1) && (Meter_Parameter.freeze_parameter.FreezeData_Day_Addr==0))
/// 	{
//// 	stridefreeze_dot_num = GetSkipedTimeFlags((TDateTime *)&Powerdown_Save_Data.date, (TDateTime *)&Now_time, 
///		                                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreeze_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE);
/// 	FlashIsEmpty=1;
///	LastDayfreezeTime=Powerdown_Save_Data.date;
	
 ///      	if( (stridefreeze_dot_num<MAX_DAYFREEZE_POWERUP_STRIDE)&&(Powerdown_Save_Data.date.Hour==Meter_Parameter.freeze_parameter.FreezeDay_Hour)
///				&&(Powerdown_Save_Data.date.Min>=Meter_Parameter.freeze_parameter.FreezeDay_Min)
///				&&(Powerdown_Save_Data.date.Min<=(Meter_Parameter.freeze_parameter.FreezeDay_Min+2))
///				&&(O1ther_Meter_Parameter.Dayfreeze_flag==0))
///				{				
///				stridefreeze_dot_num+=1;
///				StrideFreeze_Dot_List[stridefreeze_dot_num-1]=Powerdown_Save_Data.date;	   
///				}	
 ///	}

 if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))
	{
         pointer=Meter_Parameter.freeze_parameter.FreezeData_Day_Addr;///king chen add 130302
         if(pointer==0)
             pointer=MAX_NUMBER_FREEZE_DAY -1;
         else
             pointer=pointer -1;
 
         file_name=FREEZE_DAY_START_FILE+pointer;
         data_length=5;
         for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;
         Read_File(file_name, 0,data_length,&Co.b[300]);
 
         LastDayfreezeTime.Year=Co.b[300];
         LastDayfreezeTime.Month=Co.b[301];
         LastDayfreezeTime.Day=Co.b[302];
         LastDayfreezeTime.Hour=Co.b[303];
         LastDayfreezeTime.Min=Co.b[304];
         LastDayfreezeTime.Sec=0;
         LastDayfreezeTime.Week=0;
		 
	  if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))
		return ;
	}
 #endif
 
  
 
  LastDayfreezeTime=O1ther_Meter_Parameter.DayFreezeReferenceDate;///king chen add 130302
  
 /// if(ComparentTime((unsigned char *)&LastDayfreezeTime, (unsigned char *)&Powerdown_Save_Data.date)==ResultLarger)///king chen mark 130319
/// 	      return ;
///  else
      if(O1ther_Meter_Parameter.PowerOnDayfreeze_flag!=4)///king chen add 130322
 	{
 	 LastDayfreezeTime_temp=LastDayfreezeTime;
 	 LastDayfreezeTime = Powerdown_Save_Data.date;
  	}
 ///if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))///king chen add 130422
 ///{
 ///   LastDayfreezeTime=softdate;
///    WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); ///king chen add 130422
///    return ;
 ///}
if((!CheckTime((unsigned char *)&Now_time)) ||(!CheckTime((unsigned char *)&LastDayfreezeTime)))
        return ;	
 
if((0 == O1ther_Meter_Parameter.PowerOnDayfreeze_flag) ||(4 == O1ther_Meter_Parameter.PowerOnDayfreeze_flag))/*"POWER UP DAY FREEZE NOT COMPLETE"*/
{
 ///O1ther_Meter_Parameter.PowerOnDayfreeze_flag=0;
 WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen modify 130228

   stridebill_dot_num = GetSkipedTimeFlags((TDateTime *)&LastDayfreezeTime, (TDateTime *)&Now_time, 
		                                                   (TDateTime *)&FirstBillDay_Dot, (TDateTime *)&StrideBill_Dot_List[0], 2);
  
  stridefreeze_dot_num = GetSkipedTimeFlags((TDateTime *)&LastDayfreezeTime, (TDateTime *)&Now_time, 
		                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreeze_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE);
  
 if((stridefreeze_dot_num>=0)&& (stridefreeze_dot_num<MAX_DAYFREEZE_POWERUP_STRIDE)&&(O1ther_Meter_Parameter.PowerOnDayfreeze_flag!=4)
                            &&(Powerdown_Save_Data.date.Hour==Meter_Parameter.freeze_parameter.FreezeDay_Hour)
				&&(Powerdown_Save_Data.date.Min==Meter_Parameter.freeze_parameter.FreezeDay_Min)
				&&(ComparentTime((unsigned char *)&LastDayfreezeTime_temp, (unsigned char *)&Powerdown_Save_Data.date)!=ResultEqual)
				&&(Powerdown_Save_Data.date.Sec<=2)) ///king chen add 130510
				{
				stridefreeze_dot_num+=1;
				StrideFreeze_Dot_List[stridefreeze_dot_num-1]=Powerdown_Save_Data.date;///king chen modify 130105				
				}
 
if(stridefreeze_dot_num>MAX_DAYFREEZE_POWERUP_STRIDE)	
    return ;

if((stridebill_dot_num > 0)&&(stridefreeze_dot_num>0))/*"掉电期间至少1次跨过第一结算日"*/
    {
    /*"查找第一结算日前的日冻结点"*/
    if((stridefreeze_dot_num)&&(Meter_Parameter.parameter1.MeterMode[2].bit.b6))///king chen modify 130313
       stridefreezePrebill_dot_num = GetSkipedTimeFlags((TDateTime *)&StrideFreeze_Dot_List[stridefreeze_dot_num-1], (TDateTime *)&StrideBill_Dot_List[stridebill_dot_num-1], 
		                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreezePreBill_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE) ;
    if(stridefreezePrebill_dot_num )/*"GetSkipedTimeFlags()查找函数:查找时标点包括结束时间点，但不包括起始时间点，所以如果找到需要加1"*/
		  stridefreezePrebill_dot_num +=1;///king chen add 130105
    else if(0==stridefreezePrebill_dot_num )///king chen add 130228
    	{
    	if((stridefreeze_dot_num)&&(Meter_Parameter.parameter1.MeterMode[2].bit.b6))///king chen modify 130316
    	{
    	 
    	  billdaygreater_flag=ComparentTime( (unsigned char *)&StrideBill_Dot_List[stridebill_dot_num-1],(unsigned char *)&StrideFreeze_Dot_List[stridefreeze_dot_num-1]); 
	 
    	  if((billdaygreater_flag==ResultLarger) || (billdaygreater_flag==ResultEqual))
    	       stridefreezePrebill_dot_num=1;
    	  else if(billdaygreater_flag==ResultSmaller)
    	       stridefreezePrebill_dot_num=0;    	
    	}
    	}
	
    if(stridefreezePrebill_dot_num > 0)/*"补日冻结数据点有跨过第一结算日"*/
    {    
    if(stridefreeze_dot_num >= stridefreezePrebill_dot_num)
    {
    	CheckPowerDown();
    for(freezeday_num = 0; freezeday_num < stridefreezePrebill_dot_num; freezeday_num++)/*"第一结算日前的日冻结点"*/
    	{
    	/*"补日冻结数据，需量数据取上电时刻当前需量值"*/
    	/*"日冻结数据时标为StrideFreezePreBill_Dot_List列表中逆序存储"*/
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 0,stridebill_dot_start_num, freezeday_num);	
        stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
        Dayfreeze_Recompense(1,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);
    	}    
    for(freezeday_num = 0;freezeday_num< (stridefreeze_dot_num - stridefreezePrebill_dot_num); freezeday_num++)/*"第一结算日后的日冻结点"*/
    	{
    	/*"补日冻结数据，需量数据补0值"*/
    	/*"日冻结数据时标为StrideFreeze_Dot_List列表中逆序存储"*/
    	////stridebill_dot_start_num=stridefreeze_dot_num - stridefreezePrebill_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 1,stridebill_dot_start_num, freezeday_num);	
       stridebill_dot_start_num=stridefreeze_dot_num - stridefreezePrebill_dot_num - freezeday_num -1;
        Dayfreeze_Recompense(0,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);
    	}
    }    
    }
    else/*"补日冻结数据点没有跨过第一结算日，都落在第一结算日后面"*/
    {
    CheckPowerDown();
    /*"补日冻结数据，需量数据补0值"*/
      for(freezeday_num = 0; freezeday_num< stridefreeze_dot_num; freezeday_num++)/*"第一结算日前的日冻结点"*/
    	{
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 1,stridebill_dot_start_num, freezeday_num);	
    	stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
    	Dayfreeze_Recompense(0,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);	
    	}
    }
   }
    else if((stridebill_dot_num == 0)&&(stridefreeze_dot_num>0))/*"掉电期间没有跨过第一结算日，需量数据补上电时刻当前需量值"*/
    {
    CheckPowerDown();
    /*"补日冻结数据，需量数据取上电时刻当前需量值"*/
  for(freezeday_num= 0; freezeday_num< stridefreeze_dot_num; freezeday_num++)/*"第一结算日前的日冻结点"*/
    	{
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 0,stridebill_dot_start_num, freezeday_num);	
    	stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
    	Dayfreeze_Recompense(1,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);	
    	}
   }
 O1ther_Meter_Parameter.PowerOnDayfreeze_flag=1;
 WRLC256(POWERONDAYFREEZE_FLAG_ROM ,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen modify 130228	
}


}



 #if 0 
/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：Dayfreeze_Recompense"*/
/*" 功    能：上电补日冻结数据 "*/
/*" 说    明："*/
/*" 入口参数："*/
/*"    StrideFreeze_Dot_List: 查找到的时标集，按时间先后  逆序 排列 "*/
/*"    demand_zero_flag: 日冻结需量补零的标志，补零时则为1，否则为0"*/
/*"    stridebill_dot_start_num: 本次补日冻结数据的第一个数据的起始点"*/
/*"    freezeday_num: 日冻结补冻的当前点 "*/
///king chen add 130105
   
void Dayfreeze_Recompense(TDateTime * StrideFreeze_Dot_List, unsigned char demand_zero_flag,unsigned int stridebill_dot_start_num,unsigned int freezeday_num )
{

   unsigned int uni,i,addr;
   unsigned int  file_name=0,data_length=0;
   unsigned int pointer=0;
   
  struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
  struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
  
    	/*"补日冻结数据，需量数据取上电时刻当前需量值"*/
	/*"日冻结数据时标为StrideFreezePreBill_Dot_List列表中逆序存储"*/
       p3_2=1;

       pointer=Meter_Parameter.freeze_parameter.FreezeData_Day_Addr;

       file_name=FREEZE_DAY_START_FILE+pointer;
       data_length=5+sizeof(struct  FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA)+sizeof(struct FREEZE_POWER_DATA); 
   
       for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;   
	   /*"冻结时间"*/   

               {
                for(uni=0;uni<3;uni++) 
	        *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)StrideFreeze_Dot_List+(stridebill_dot_start_num-1 -freezeday_num)*7 + uni);
	        
		 Co.b[303]=Meter_Parameter.freeze_parameter.FreezeDay_Hour;
		 Co.b[304]=Meter_Parameter.freeze_parameter.FreezeDay_Min;
               }
       
               {
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Year=Co.b[300];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Month=Co.b[301];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Day=Co.b[302];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Hour=Co.b[303];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Min=Co.b[304];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
               O1ther_Meter_Parameter.DayFreezeReferenceDate.Week=0;
	       }
	   
	       	
	  /*"冻结电能量"*/   
  	     for(i=0;i<6;i++)
  	     {
	        for(uni=0;uni<MAXTRIFF;uni++)
				*((unsigned long *)&Co.b[300+5]+MAXTRIFF*i+uni)=*((unsigned long *)&This_Month_Data.Energy_Record.Plus_Active[0]+MAXTRIFF*i+uni);
  	     }

		/*"冻结需量"*/	
	  addr=5+sizeof(struct  FREEZE_ENERGY_DATA);						 
	  Freeze_Demand_Data=(struct FREEZE_DEMAND_DATA *)&Co.b[300+addr];
   if(!demand_zero_flag)
   {
    for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].Demand;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].Demand;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].time[i];
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].time[i];
    	}
     }
    }
    else
    {
    for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=0x00;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=0x00;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=0x00;
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=0x00;
    	}
     }
    }
     /*"冻结变量"*/
	  addr=5+sizeof(struct	FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA);						
	  Freeze_Power_Data=(struct FREEZE_POWER_DATA *)&Co.b[300+addr];

	
	  for(uni=0;uni<4;uni++)
	  {
	     	///Freeze_Power_Data->Active_power_t[uni]=COMM_Active_power[uni];///king  chen mark 121214
	     	///Freeze_Power_Data->Reactive_power_t[uni]=COMM_Reactive_power[uni];
	     	Freeze_Power_Data->Active_power_t[uni]=0x00;///king chen modify 130228
	     	Freeze_Power_Data->Reactive_power_t[uni]=0x00;
	  }
	
	 	
	 {
	     Write_File(file_name,0,data_length,&Co.b[300]);
	 }

	 O1ther_Meter_Parameter.PowerOnDayfreeze_flag=4;/*"表示掉电补日冻结已经开始，并且至少是补了一个日冻结"*/
	 WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen add 130322


	 /*"电子钱包冻结"*/
	 F_E_BurseFreezeData();			//Li Update 20130319
	 
	 FeedWatchdog(); 
	 pointer++;
	 pointer%=MAX_NUMBER_FREEZE_DAY;	
        Meter_Parameter.freeze_parameter.FreezeData_Day_Addr=pointer;
        WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.FreezeData_Day_Addr,1,0,0); 
        
	 WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); ///king chen add 130302
		
	Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
	 FeedWatchdog();
    
}
     #endif
///#pragma SECTION program ROM_PRG2
/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：Dayfreeze_Recompense"*/
/*" 功    能：上电补日冻结数据 "*/
/*" 说    明："*/
/*" 入口参数："*/
/*"    demand_zero_flag: 日冻补结需量标志，需量补实际值时为1，需量补零时则为0"*/
/*"    StrideFreeze_Dot: 查找到的时标集，按时间先后  逆序 排列 "*/
void Dayfreeze_Recompense(unsigned char  demand_flag, unsigned char * StrideFreeze_Dot)///king chen modify 130609
{
    unsigned char pointer;
    
    ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr
	  ,FREEZE_DAY_START_FILE);/*"冻结清零判断处理"*/ 
    
    pointer=O1ther_Meter_Parameter.FreezeData_Day_Addr;
	  FreezeDateProgram(FREEZE_DAY_START_FILE+pointer,demand_flag, (unsigned char *)StrideFreeze_Dot);
  	pointer++;
  	pointer%=MAX_NUMBER_FREEZE_DAY;	
    O1ther_Meter_Parameter.FreezeData_Day_Addr=pointer;
    WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr,1,0,0); 
   /// Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
    
    O1ther_Meter_Parameter.PowerOnDayfreeze_flag=4;/*"表示掉电补日冻结已经开始，并且至少是补了一个日冻结"*/
	  WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen add 130322
	  O1ther_Meter_Parameter.DayFreezeReferenceDate=(*((struct DATEANDTIME_DEF *)StrideFreeze_Dot));///king chen add 130302
	  O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
	  WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); 

}
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" 函 数 名：ComparentTime"*/
/*" 功    能：比较t1,t2两个时间的大小,比较到分钟为止,使用时请注意自己比较的时间是否需要比较到分钟"*/
/*" 说    明：	   "*/
/*" 入口参数："*/
/*"	t1：时间1"*/
/*"	t2：时间2"*/
/*" 返 回 值:ResultSmaller, t1<t2;ResultLarger ,t1>t2;ResultEqual, t1=t2"*/
unsigned char ComparentTime(unsigned char *t1, unsigned char *t2)
{
  unsigned char uni;
  
   for(uni=0;uni<5;uni++)
  	{
  	   if(*t1<*t2)
		return ResultSmaller;
	   else if(*t1>*t2)
		return ResultLarger;
	   t1++;
	   t2++;
  	}

    return ResultEqual;

}
//-------------------------------------------------------------------------------------//
#define   NULL  (void*)0
const unsigned long Clearfreeze_ID[9]={0x0500FFFF,          /*"定时冻结"*/
                                                             0x0501FFFF,          /*"瞬时冻结"*/
                                                             0x0502FFFF,          /*"时区切换冻结"*/
                                                             0x0503FFFF,          /*"时段表切换冻结"*/
                                                             0x0506FFFF,          /*"日冻结"*/
								     0x0512FFFF,          /*"电量翻转冻结"*/
								     0x0505FFFF,          /*"分时费率切换冻结"*/
								     0x0507FFFF,		/*"两套梯度切换冻结"*/
								     0x050802FF};      	/*"剩余金额日冻结"*/
const struct CLEARFREEZE_STRU  ClearFreeze_Leaf[9]={
		       {FREEZE_TIME_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr, FREEZE_TIME_SORT_START_FILE},
			{FREEZE_MOMENT_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Moment_addr, FREEZE_MOMENT_SORT_START_FILE},
			{FREEZE_TRIFF_ADDR_ROM, (unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr, FREEZE_TRIFF_CHANGE_SORT_START_FILE},
			{FREEZE_DALIYSLOT_ADDR_ROM, (unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr, FREEZE_DAILYSLOT_CHANGE_START_FILE},
			{FREEZE_DAY_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr, FREEZE_DAY_START_FILE},
			{ENERGYPASSZERO_P_ROM, (unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P, FREEZE_ENERGYPASSZERO_START_FILE},
			{TRIFF_SWITCH_EVENT_P_EE, (unsigned char *)&Pay_For_Event_Point.Triff_Switch_Event_P, TRIFF_SWITCH_EVENT_FILE},
			{STEP_SWITCH_EVENT_P_EE, (unsigned char *)&Pay_For_Event_Point.Step_Switch_Event_P, STEP_SWITCH_EVENT_FILE},
			{E_BURSE_EVENT_P_OFFSET, (unsigned char *)&Pay_For_Event_Point.E_Burse_Event_P, E_BURSE_EVENT_FILE}
                                                                                     };
void ClearFreezeCommDeal(unsigned long Data_ID)
{
unsigned char uni = 0;
const struct CLEARFREEZE_STRU *Freeze_Node;
unsigned char search_ok = 0;

if(IntoPowerDownFlag == 0xff)/*"为防止低功耗显示进入，导致只清清零标识，不清FLASH中数据问题"*/
{
return;
}

/*"忽略最后两个字节匹配查找数据标识"*/
for(uni = 0; uni < ((sizeof(Clearfreeze_ID)) / sizeof(unsigned long)); uni++)
{
if((Clearfreeze_ID[uni] & 0xffff0000) == (Data_ID & 0xffff0000))
{
Freeze_Node=( const struct CLEARFREEZE_STRU *)&ClearFreeze_Leaf[uni];
search_ok = 0xff;
break;
}
}


if(search_ok == 0xff)/*"查找数据标识成功"*/
{
if((Freeze_Node->Pointer) != NULL)/*"事件指针不为空"*/
{
CheckPowerDown();
if((*(Freeze_Node->Pointer)) == EVENT_CLAER_STATUS)/*"事件指针为清零状态，需清除事件FLASH中保存数据"*/
	{
	Delete_File(Freeze_Node->Filename_begin);
	if ((Data_ID & 0xffff0000)==0x05080000)		/*"剩余金额日冻结有64个文件"*/
		{
		Delete_File(Freeze_Node->Filename_begin+32);
		Delete_File(Freeze_Node->Filename_begin+64);
		}		
	*(Freeze_Node->Pointer) = 0;
	WRLC256((Freeze_Node->Pointer_addr),0,1,0,0);
	Set_Meter_para_Deal(Freeze_Node->Pointer_addr);
	}
}
}
}
//------------------------------------------------------------------------------
