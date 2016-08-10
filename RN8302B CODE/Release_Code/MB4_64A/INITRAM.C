 #include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "multi.h"
#include "ram.h"
#include "seg.h"
#include "Energy_Del.H"
#include "Clock_time.H"
#include "loadrecord.h"
#include "AllVoltageLoss.h"
#include "att7022_operation.h"
#include "freeze.h"    //mw added 2009-02-14
#include "Measure_Interface.h" 
#include "initram.h"
#include "MB_Showmain.h"
#include "File_System.h"
#include "ICcard.h"

#include "pay_def.h"	//payment
#include "Far_pay.h"
#include "Ex_Pay_For_Fun.h"

#include "PowerUpRetort.h"///king chen add 130308
#pragma SECTION rom UserROMData
const unsigned char  EEPROM_AND_FLASH_NEW_FLAG[3]={0xC9,0xCA,0x64};///150611,DSZY331/DTZY341-B2-2-7
const unsigned char SegDataInEeprom1[24]={
                                          0x01,0x00,0x00,
                                          0x02,0x00,0x03,
                                          0x03,0x00,0x06,
                                          0x04,0x00,0x09,
                                          0x01,0x00,0x12,
                                          0x02,0x00,0x15,
                                          0x03,0x00,0x18,
                                          0x04,0x00,0x21};
const unsigned char SegDataInEeprom2[24]={
                                          0x01,0x01,0x01,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06,
                                          0x02,0x01,0x06};
const unsigned char DisplayInEepromA1[]={   
//					    0x81,0x00,0x07,0x0e,  0x00, //070081
                                            0x01,0x01,0x00,0x04,  0x00,  //01    
                                            0x02,0x01,0x00,0x04,  0x00,  //02        
#if (MODULE_LOCAL_PAY_FLAG)
                                            0x00,0x02,0x90,0x00,  0x00,  // 03	//payment
#endif
                                            0x00,0x00,0x00,0x00,  0x00,  //03      
                                            0x00,0x00,0x01,0x00,  0x00,  //04     
                                            0x00,0x01,0x01,0x00,  0x00,  //05  
                                            0x00,0x02,0x01,0x00,  0x00,  //06  
                                            0x00,0x03,0x01,0x00,  0x00,  //07   
                                            0x00,0x04,0x01,0x00,  0x00,  //08   
                                            0x00,0x00,0x01,0x01,  0x00,  //09    
#if ((!MODULE_LOCAL_PAY_FLAG) && (!MODULE_FAY_PAY_FLAG))
                                            0x00,0x00,0x03,0x00,  0x00,  //10       
                                            0x00,0x00,0x04,0x00,  0x00,  //11
#endif
                                            0x00,0x00,0x05,0x00,  0x00,  //12         
                                            0x00,0x00,0x06,0x00,  0x00,  //13 
                                            0x00,0x00,0x07,0x00,  0x00,  //14
                                            0x00,0x00,0x08,0x00,  0x00,  //15
                                            0x00,0x00,0x02,0x00,  0x00,  //16
                                            0x00,0x01,0x02,0x00,  0x00,  //17
                                            0x00,0x02,0x02,0x00,  0x00,  //18
                                            0x00,0x03,0x02,0x00,  0x00,  //19
                                            0x00,0x04,0x02,0x00,  0x00   //20
 						//  0x88,0x88,0x88,0x88, 0x00 //added by lfy
                                           };

										  	
const unsigned char DisplayInEepromB1[]={                                                      
                                            0x01,0x01,0x00,0x04,  0x00,  //01     
                                            0x02,0x01,0x00,0x04,  0x00,  //02        
#if (MODULE_LOCAL_PAY_FLAG)
                                            0x00,0x02,0x90,0x00,  0x00,  // 03	//payment
#endif
                                            0x00,0x00,0x00,0x00,  0x00,  //03     
                                            0x00,0x00,0x01,0x00,  0x00,  //04      
                                            0x00,0x01,0x01,0x00,  0x00,  //05      
                                            0x00,0x02,0x01,0x00,  0x00,  //06     
                                            0x00,0x03,0x01,0x00,  0x00,  //07      
                                            0x00,0x04,0x01,0x00,  0x00,  //08     
                                            0x00,0x00,0x01,0x01,  0x00,  //09     
                                            0x00,0x00,0x01,0x01,  0x01,  //10     
                                            0x00,0x00,0x01,0x01,  0x02,  //11
                                            0x00,0x00,0x02,0x00,  0x00,  //12          
                                            0x00,0x01,0x02,0x00,  0x00,  //13     
                                            0x00,0x02,0x02,0x00,  0x00,  //14      
                                            0x00,0x03,0x02,0x00,  0x00,  //15
                                            0x00,0x04,0x02,0x00,  0x00,  //16
                                            0x00,0x00,0x02,0x01,  0x00,  //17
                                            0x00,0x00,0x02,0x01,  0x01,  //18
                                            0x00,0x00,0x02,0x01,  0x02,  //19
#if ((!MODULE_LOCAL_PAY_FLAG) && (!MODULE_FAY_PAY_FLAG))
                                            0x00,0x00,0x03,0x00,  0x00,  //20
                                            0x00,0x00,0x04,0x00,  0x00,  //21
#endif
                                            0x00,0x00,0x05,0x00,  0x00,  //22
                                            0x00,0x00,0x06,0x00,  0x00,  //23
                                            0x00,0x00,0x07,0x00,  0x00,  //24
                                            0x00,0x00,0x08,0x00,  0x00,  //25
                                            0x01,0x00,0x01,0x00,  0x00,  //26
                                            0x01,0x01,0x01,0x00,  0x00,  //27
                                            0x01,0x02,0x01,0x00,  0x00,  //28
                                            0x01,0x03,0x01,0x00,  0x00,  //29
                                            0x01,0x04,0x01,0x00,  0x00,  //30
                                            0x01,0x00,0x01,0x01,  0x00,  //31
                                            0x01,0x00,0x01,0x01,  0x01,  //32
                                            0x01,0x00,0x01,0x01,  0x02,  //33
                                            0x01,0x00,0x02,0x00,  0x00,  //34
                                            0x01,0x01,0x02,0x00,  0x00,  //35
                                            0x01,0x02,0x02,0x00,  0x00,  //36
                                            0x01,0x03,0x02,0x00,  0x00,  //37
                                            0x01,0x04,0x02,0x00,  0x00,  //38
                                            0x01,0x00,0x02,0x01,  0x00,  //39
                                            0x01,0x00,0x02,0x01,  0x01,  //40
                                            0x01,0x00,0x02,0x01,  0x02,  //41
                                            0x01,0x00,0x05,0x00,  0x00,  //42
                                            0x01,0x00,0x06,0x00,  0x00,  //43
                                            0x01,0x00,0x07,0x00,  0x00,  //44
                                            0x01,0x00,0x08,0x00,  0x00,  //45
                                            0x01,0x04,0x00,0x04,  0x01,  //46
                                            0x01,0x04,0x00,0x04,  0x00,  //47
                                            0x03,0x07,0x00,0x04,  0x00,  //48
                                            0x09,0x04,0x00,0x04,  0x00,  //49
                                            0x0a,0x04,0x00,0x04,  0x00,  //50
                                            0x0a,0x00,0x80,0x02,  0x00,  //51                                              
                                            0x01,0x00,0x30,0x03,  0x00,  //52//0x06,0x02,0x00,0x0e,  0x00,  //52
                                            0x01,0x00,0x30,0x03,  0x01,  // 0x06,0x02,0x00,0x0e,  0x01,  //53
                                            0x01,0x00,0x00,0x10,  0x00,  //54
                                            0x02,0x00,0x00,0x10,  0x00,  //55
                                            0x01,0x01,0x00,0x10,  0x00,  //56
                                            0x01,0x01,0x00,0x10,  0x01,  //57
                                            0x01,0x02,0x00,0x10,  0x00,  //58
                                            0x01,0x02,0x00,0x10,  0x01,  //59
                                            0x01,0x02,0x01,0x10,  0x00,  //60
                                            0x01,0x26,0x01,0x10,  0x00,  //61
                                            0x01,0x03,0x01,0x10,  0x00,  //62
                                            0x01,0x27,0x01,0x10,  0x00,  //63
                                            0x01,0x02,0x02,0x10,  0x00,  //64
                                            0x01,0x26,0x02,0x10,  0x00,  //65
                                            0x01,0x03,0x02,0x10,  0x00,  //66
                                            0x01,0x27,0x02,0x10,  0x00,  //67
                                            0x01,0x02,0x03,0x10,  0x00,  //68
                                            0x01,0x26,0x03,0x10,  0x00,  //69
                                            0x01,0x03,0x03,0x10,  0x00,  //70
                                            0x01,0x27,0x03,0x10,  0x00,  //71
                                            0x00,0x01,0x01,0x02,  0x00,  //72
                                            0x00,0x02,0x01,0x02,  0x00,  //73
                                            0x00,0x03,0x01,0x02,  0x00,  //74
                                            0x00,0x01,0x02,0x02,  0x00,  //75
                                            0x00,0x02,0x02,0x02,  0x00,  //76
                                            0x00,0x03,0x02,0x02,  0x00,  //77
                                            0x00,0x00,0x03,0x02,  0x00,  //78
                                            0x00,0x01,0x03,0x02,  0x00,  //79
                                            0x00,0x02,0x03,0x02,  0x00,  //80
                                            0x00,0x03,0x03,0x02,  0x00,  //81
                                            0x00,0x00,0x06,0x02,  0x00,  //82
                                            0x00,0x01,0x06,0x02,  0x00,  //83
                                            0x00,0x02,0x06,0x02,  0x00,  //84
                                            0x00,0x03,0x06,0x02,  0x00,  //85
#if (MODULE_LOCAL_PAY_FLAG)                                            
                                            0x01,0xEC,0x00,0x04,  0x00,  // 	current triff
                                            0x02,0xEC,0x00,0x04,  0x00,  // 
                                            0x03,0xEC,0x00,0x04,  0x00,  // 
                                            0x04,0xEC,0x00,0x04,  0x00,  // 
//                                            0x01,0xED,0x00,0x04,  0x00,  // 	current step
//                                            0x02,0xED,0x00,0x04,  0x00,  // 
//                                            0x03,0xED,0x00,0x04,  0x00,  // 
//                                            0x04,0xED,0x00,0x04,  0x00,  // 
//                                            0x01,0xEE,0x00,0x04,  0x00,  // 	current step triff
//                                            0x02,0xEE,0x00,0x04,  0x00,  // 
//                                            0x03,0xEE,0x00,0x04,  0x00,  // 
//                                            0x04,0xEE,0x00,0x04,  0x00,  // 
//                                            0x05,0xEE,0x00,0x04,  0x00,  // 
                                            0x01,0x10,0x00,0x04,  0x00,  // 	alarm1
                                             0x02,0x10,0x00,0x04,  0x00,  // 	alarm2
                                            0x01,0x02,0x90,0x00,  0x00,  //       tick money
#endif
                                            0x01,0x0b,0x00,0x04,  0x00  };// 101
											
struct  RAMSTRUCT
{
	
  unsigned int  Addr;
  unsigned char *Pinter;
  unsigned int  Len;
};  
union   BYTE_DEF  Parameter_flag[5]; //b0----1 ram err ,resume err                       0 ok,king chen modify 121226
                                     //b1----1 ram err  eeprom err read eeprom err       0 ok
                                     //b2----1 Eeprom and ram parameter err              0 ok
                                     //b3----1 ram ok ,write eeprom err                  0 ok
                                     //b4----1 ram ok ,read eeprom err                   0 ok
                                     //b5----
                                     //b6----
                                     //b7----
union   BYTE_DEF RamPara_valid_flag;
unsigned int para_err_times;

void	IniRam(void);
unsigned char IsNewEeprom(void);
unsigned char IsNewEepromOrFlash(unsigned char );//type :EEPROM_FLAG,FLASH_FLAG,
void SetNewFlag(unsigned char type);//type :EEPROM_FLAG,FLASH_FLAG, //add by zlp
void SetDefault(void);
unsigned char ReadEeprom(void);
void   WriteDefaultTime(void);
unsigned char IsNormalReset(unsigned char type);//modify by zlp
                              
unsigned char IsHaveSaveData(void);
void Clear_Savedata_flag(void);
unsigned char IsNormalResetWrite(void);
void Set_Default_Para(void);
unsigned char Check_Para_Def(void);
void Set_Flash_Default(void);
void Retort_New(unsigned char ,unsigned char *);
void powerup_check_year_bill(void);
void Check_New(void);
//liuyq adde for program size 2009-8-6
unsigned char ReadBlock(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName);//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
					   
//liuyq added for program size 2009-8-6

void RecordRectifyEnergyEvent(unsigned char Recordflag,unsigned char Rectifytype);//add by zlp
extern char Check_Show_Flash_Data(unsigned char ,unsigned char ,unsigned char ,unsigned char *);
/***********************************************************************************

***********************************************************************************/
unsigned char Check_eeprom_data_validity(unsigned int rom_addr, unsigned int len);
unsigned char Ram_data_powerup_process(unsigned char *ram_addr, unsigned int rom_addr, unsigned int len);
void          Para_Process_main(void);
void          PowerUp_Check_BatteryWorkTime(double long data); 
void Para_Process_run(void);
/*"============================================================
函数说明：检查RAM中数据合法性，并初始化RAM中数据
输入参数：无
输出参数：无
返    回：无  
作    者：GANJP  版本：1.00
============================================================"*/
void  IniRam(void)
{
  unsigned char ISNewE=0;
  unsigned int uni,i=0;
  double long data = 0;
  unsigned char result3,time_value = 0;
	
  InitSIO4();
		
	if(IsNewEeprom())//first powerup
	{	       
	   SetDefault();
	   FeedWatchdog(); 
	   ISNewE=0xFF;
	}	
	else
	{
    Para_Process_main();
    CheckPowerDown();
    FeedWatchdog();
       
	  ReadEeprom();	
	  CheckPowerDown();
	  FeedWatchdog();
	  CheckPowerDown();
	  Check_Energy_main(0);
	  	  
	}
	
    Set_Flash_Default();//add by fuxf
	#if(ALLLOSSVOLTAGE_MODE == 0)	
	PowerUpLossTotalVoltage();  //change by pc 081208
	#endif
	FeedWatchdog();
	CheckPowerDown();
	Just_para_Power_on();			  
	vMeter_VoltCurrSpecInit();
	
	FeedWatchdog();
	ClearEventDataPowerOn();/*"上电补请事件、冻结文件"*/
	
	if((!IntoPowerDownFlag)&&(ISNewE==0)){
		EventData_PowerOn_Check();
		VoltStatInit();
		EventRecord_Poweron_Check();  //add by pc 081020
		//FeedWatchdog();
		//PowerUpLossTotalVoltage();  //add by pc 081208
		//PoweronFreeze_Deal();  //mw added 2009-02-13
	}	
	FeedWatchdog();
	
	time_value = PowerUp_Init_RTC(ISNewE, &data);
	IF_Powerup_Savedata=1;
    IF_Powerup_Readdata=1;
    IF_Powerup_Billdata=0;
	if((time_value&0x0f) == 0x0f)				  	      	
	{
		//power up bill here
		Check_New();
    VoltStatisticCheck();
    ///PowerUp_Check_EventReport_RunTime(data);
  }
	
	CheckPowerDown();
	if(IsNormalReset(1))
	{
		if((time_value&0x0f) == 0x0f)				  	      	
	  {
	    PowerUp_Check_BatteryWorkTime(data);
    }
  }
  IF_Powerup_Billdata=1;
	Clear_Savedata_flag();/*"防止初始化过程中异常情况未能清电量处理标志，初始化完成后补清一下"*/
	O1ther_Meter_Parameter.PowerOnDayfreeze_flag=0;///king chen add 130322
	WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen add 130322
	O1ther_Meter_Parameter.PowerOnRetort_flag=0;
	WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322

	POWERONYEARBILL_FLAG_DEFINE = 0;			//Li Update 20130419
    Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	FeedWatchdog();
	CheckChange(0,FOR_TRIFF_DATE); //modify by zlp
	CheckChange(0,FOR_DAILYSLOT_DATE);
	Seg();
	FeedWatchdog();
	OLD_TRAFF_RATE=TRAFF_RATE;
	FeedWatchdog();
	Write_TO_Cal_PowerDown_Energy_add();	
	O1ther_Meter_Parameter.OutputModel=0;/*"   上电默认为秒脉冲 "*/			
	
}



#define EEPROM_FLAG    0
#define FLASH_FLAG      1
/********************************************************
*     1. check new eeprom                               *
*     2.                                                *
*********************************************************/
unsigned char IsNewEeprom(void)
{

     return IsNewEepromOrFlash(0);//modify by zlp	
}
unsigned char IsNewEepromOrFlash(unsigned char type)//type :EEPROM_FLAG,FLASH_FLAG,
{
    
	///unsigned char data[3];///king chen mark 130116
	unsigned char flag=0x00;
	unsigned long times=0;
	unsigned int addr;

	unsigned char data_backup1[3];///king chen add 130116
	unsigned char data_backup2[3];
	unsigned char work_flag=0x00;
	unsigned char rerurn_vlaue_ee1=0;
	unsigned char rerurn_vlaue_ee2=0;
    
	if(type==EEPROM_FLAG)
		addr=EEPROM_FLAG_ROM;
	else if(type==FLASH_FLAG)
		addr=EEPROM_FLAG_ROM+5;
	
///	WRLC256(addr,(unsigned char *)&data,3,0,1);
///	if((data[0]!=EEPROM_AND_FLASH_NEW_FLAG[0] ) || (data[1]!=EEPROM_AND_FLASH_NEW_FLAG[1] ) || (data[2]!=EEPROM_AND_FLASH_NEW_FLAG[2] ))
///	{
///	   WRLC256(addr,(unsigned char *)&data,3,0,1);
///	   if((data[0]!=EEPROM_AND_FLASH_NEW_FLAG[0] ) || (data[1]!=EEPROM_AND_FLASH_NEW_FLAG[1] ) || (data[2]!=EEPROM_AND_FLASH_NEW_FLAG[2] ))
///	   {
///	      do
///	      {
///	      	 Delay(1);
///	      	 times++;
///	      	 if(!J1)
///	      	 {
///	      	    Delay(50);
///	      	    if(!J1)
///	      	    {
	      	       //display	
///	      	       flag=0xFF;
///	      	    }
///	      	 }
///	      }while(times<20 && (!flag));
///	   }
///	} 
///	return flag;
     do
     {
     Delay(1);
     times++;
      if(!J1)
      { 
        Delay(50);
        if(!J1)
         {	      	       
           work_flag=0xFF;
         }
      }
     }while((times<20)&&(!work_flag));///king chen modify 130130
     
     times=0;
     if(work_flag)
     {
     do
     	{
     	  CheckPowerDown();
         rerurn_vlaue_ee1=WRLC256(addr,(unsigned char *)&data_backup1,3,0,1);
         Delay(10);
         rerurn_vlaue_ee2=WRLC256(addr,(unsigned char *)&data_backup2,3,0,1);
         times++;
         if((rerurn_vlaue_ee1==0xff)&&(rerurn_vlaue_ee2==0xff))
         {
         if((data_backup1[0]==data_backup2[0])&&(data_backup1[1]==data_backup2[1])&&(data_backup1[2]==data_backup2[2]))
           {
	  	    if((data_backup1[0]!=EEPROM_AND_FLASH_NEW_FLAG[0] ) || (data_backup1[1]!=EEPROM_AND_FLASH_NEW_FLAG[1] ) || (data_backup1[2]!=EEPROM_AND_FLASH_NEW_FLAG[2] ))
	  	      flag=0xFF;
           }
         }
     	}while((times<5) && (!flag));
     }
      return flag;
}
void SetNewFlag(unsigned char type)//type :EEPROM_FLAG,FLASH_FLAG, add by zlp
{
      unsigned char SetVlue[3]={	EEPROM_AND_FLASH_NEW_FLAG[0],
	  						EEPROM_AND_FLASH_NEW_FLAG[1],
	  						EEPROM_AND_FLASH_NEW_FLAG[2]};
      unsigned int addr;
      if(type==EEPROM_FLAG)
	  addr=EEPROM_FLAG_ROM;
      else if(type==FLASH_FLAG)
	  addr=EEPROM_FLAG_ROM+5;
      
      CheckPowerDown();
      WRLC256(addr,(unsigned char *)&SetVlue,3,0,0);
}
/********************************************************
*     1.                                                *
*     2.                                                *
*********************************************************/
void SetDefault(void)
{
	unsigned int uni=0,unj=0;
	unsigned int i=0,j=0,k=0;
	 unsigned int DAILYSLOT_ADDR[2]={DAILYSLOT_ROM,
                                   //DAILYSLOT_ROM+42,
                                   DAILYSLOT2_ROM,
                                   //DAILYSLOT2_ROM+42
                                  };
   unsigned int YEARSLOT_ADDR[2]={YEARSLOT_ROM, YEARSLOT2_ROM};


		FeedWatchdog(); 
	
//		for(uni=0;uni<32;uni++)
//		{
//			WRLC256(uni*1024,0,1024,0,0); //add protect
//	    FeedWatchdog();
//		}
    while(unj < JUSTMETER_PARA_ROM)
		 {
		  if((unj+1024)<JUSTMETER_PARA_ROM)
		    uni=1024;
		  else
		    uni=JUSTMETER_PARA_ROM-unj;
	    WRLC256(unj,0,uni,0,0); //add protect
      FeedWatchdog();
	    unj=unj+uni;                                       	                                              
		 }        
		for(uni=0;uni<sizeof(struct ENERGY_RECORD);uni++)
		{
			*((unsigned char *)&This_Month_Data.Energy_Record+uni) = 0;
		}
		for(uni = 0; uni < sizeof(struct ENERGY_RAIL_ADD_BUFFER); uni++)
			{
				*((unsigned char *)&energy_rail + uni) = 0;//clear rail energy data
			}
		for(uni=0;uni<sizeof(struct POWERDOWN_SAVE_DATA);uni++)
		{
			*((unsigned char *)&Powerdown_Save_Data+uni) = 0;
		}
		for(uni=0;uni<sizeof(struct EVENT_POWER_NET_TIMETICKS);uni++)
		{
			*((unsigned char *)&Event_Power_Net_Timeticks+uni) = 0;
		}
		for(uni=0;uni<sizeof(struct EVENT_POWER_NET_FLAG);uni++)
		{
			*((unsigned char *)&Event_Power_Net_Flag+uni) = 0;//lfy 2011-08-01
		}

		//mw added 2010-06-05
				
		Check_Energy_main(2);
		FeedWatchdog();
    Set_Default_Para();
    FeedWatchdog();    	
			
	    /*" 初始化时段表数据"*/
	  	for(uni=0;uni<sizeof(SegDataInEeprom1);uni++)
			Co.b[uni]=SegDataInEeprom1[uni];

        for(uni=0;uni<6;uni++)
           for(unj=0;unj<3;unj++)
                Co.b[uni*3+unj+24]=SegDataInEeprom1[21+unj];  

        for(uni=1;uni<8;uni++)
           for(unj=0;unj<42;unj++)
                Co.b[uni*42+unj]=Co.b[unj];    
	  
       for(i=0;i<2;i++)
       { 
            WRLC256(DAILYSLOT_ADDR[i],( unsigned char *)&Co,42*8,0,0);
       }

        /*" 初始化时区表数据 "*/
       for(uni=0;uni<sizeof(SegDataInEeprom2);uni++)
			Co.b[uni]=SegDataInEeprom2[uni];

       for(uni=0;uni<6;uni++)
           for(unj=0;unj<3;unj++)
                Co.b[uni*3+unj+24]=SegDataInEeprom2[21+unj];    
	 
       for(i=0;i<2;i++)
       {
            WRLC256(YEARSLOT_ADDR[i],( unsigned char *)&Co,42,0,0);
       }

        /*" 初始化公假日数据 "*/
  //     for(uni=0;uni<254;uni++)
  //     {
  //          Co.b[uni*4+0]=0x01;          
  //          Co.b[uni*4+1]=0x01;          
  //          Co.b[uni*4+2]=0x01;  
  //          Co.b[uni*4+3]=0x00;    
  //     }
 //      WRLC256(HOLIDAYSLOT_ROM,( unsigned char *)&Co,254*4,0,0);

       /*" 初始化显示数据 "*/
       for(uni=0;uni<sizeof(DisplayInEepromA1);uni++)
			Co.b[uni]=DisplayInEepromA1[uni];

       WRLC256(CYCLEDISPLAYTABLE_A_ROM,( unsigned char *)&Co,sizeof(DisplayInEepromA1),0,0);

       for(uni=0;uni<sizeof(DisplayInEepromB1);uni++)
			Co.b[uni]=DisplayInEepromB1[uni];
	   
       WRLC256(CYCLEDISPLAYTABLE_B_ROM,( unsigned char *)&Co,sizeof(DisplayInEepromB1),0,0);

       for(uni=0;uni<sizeof(DisplayInEepromA1);uni++)
		   Co.b[uni]=0;
       WRLC256(CYCLEDISPLAYTABLE_A_ROM+99*5,( unsigned char *)&Co,sizeof(DisplayInEepromA1),0,0);

      for(uni=0;uni<sizeof(DisplayInEepromB1);uni++)
		Co.b[uni]=0;
     WRLC256(CYCLEDISPLAYTABLE_B_ROM+120*5,(unsigned char *)&Co,sizeof(DisplayInEepromB1),0,0);
	  
	  VoltStatSetDefault();
	  Clear_Freeze_Period();//add by fxf 090301
	  FeedWatchdog();      
	  Check_Show_Flash_Data(0xff,0,0xff,0);
	  FeedWatchdog();
      clear_psw_upd_info();

	  
	  Pay_For_Para_Init();      //payment
	Write_TO_Cal_PowerDown_Energy_add();
	FeedWatchdog();	

  Co.b[0]=0x23;			
	Co.b[1]=0x45;
	Co.b[2]=0x67;
	Co.b[3]=0x89;  
  WRLC256(0,(unsigned char *)&Co,4,0,0);     
  
  FeedWatchdog();

	SetNewFlag(EEPROM_FLAG);       
}  
/********************************************************
*     1. read/write block                        *
*     2.                                                *
*********************************************************/
unsigned char ReadBlock(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName		//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						)	
{
	unsigned char result1,num;
	
	FeedWatchdog();
	result1=0;
	num=0;
	do
	{
		result1=WRLC256(Card_Addr,DataPointer,Data_Length,DeviceName,1);
		num++;
		if(num>=4)
		{
			 //Meter_States.Meter_Flag.bit.Eeprom_Err1=1;
			 //display
		}
	}while(!result1 && num<=4);
	
	return (result1);
} 

/********************************************************
*     1. read DATA from eeprom                        *
*     2.                                                *
*********************************************************/   
unsigned char ReadEeprom(void)//modify by zlp
{       
       unsigned char i;
	struct  RAMSTRUCT   ReadStruct[9]=
	{
			   			   
	 {EVENT_POWER_NET_POINTER_ROM,  (unsigned char *)&Event_Power_Net_Pointer,   sizeof(struct EVENT_POWER_NET_POINTER)},
	 {EVENT_POWER_NET_TIMES_ROM,    (unsigned char *)&Event_Power_Net_Times,     sizeof(struct EVENT_POWER_NET_TIMES)},
	 {EVENT_METER_PRO_TIMES_ROM,    (unsigned char *)&Event_Meter_Pro_Times,     sizeof(struct EVENT_METER_PRO_TIMES)},
	 {EVENT_METER_PRO_POINTER_ROM,  (unsigned char *)&Event_Meter_Pro_Pointer,   sizeof(struct EVENT_METER_PRO_POINTER)},
	 // {EVENT_POWER_NET_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks, sizeof(struct EVENT_POWER_NET_TIMETICKS)},
   // {GLOADRECORD_ROM,              (unsigned char*)&LoadRecord,                 sizeof(struct LOADRECORD_NEW)},
   {SHOW_POWERDOWN_CYC_DATA_ROM,  (unsigned char *)&Show_Powerdown_Cyc_Data[0],sizeof(struct Show_Powerdown_Data_Struct)*99L},
   {SHOW_POWERDOWN_KEY_DATA_ROM,  (unsigned char *)&Show_Powerdown_Key_Data[0],sizeof(struct Show_Powerdown_Data_Struct)*120L} ,// lfy changed 2011-03-15
   {OTHER_METER_PARAMETER_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoomState, sizeof(struct OTHER_METER_PARAMETER)},
   {OTHER_DATA_ROM,           (unsigned char *)&Other_Data,                           sizeof(struct OTHER_DATA)},
   {THIS_MONTH_DATA_ROM + sizeof(struct ENERGY_RECORD),(unsigned char *)&This_Month_Data.Demand_Record,sizeof(struct DEMAND_RECORD)},	        
  };
	     
	for(i=0;i<9;i++)
	{
	  ReadBlock(ReadStruct[i].Addr,ReadStruct[i].Pinter,ReadStruct[i].Len,0);
	  FeedWatchdog();
	  CheckPowerDown();
	}
    
    WRLC256(EVENTSTATUS_FLAG_ROM,(unsigned char *)&EventStatus_flag.byte[0],4,0,1);
    WRLC256(EVENT_REPORT_STATUS_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times,sizeof(struct EVENT_REPORT_STATUS_TIMES),0,1);
    FeedWatchdog();
    WRLC256(EVENT_REPORT_STATUS_ROM,(unsigned char *)&Event_Report_Status,sizeof(union EVENT_REPORT_STATUS),0,1);
    WRLC256(EVENT_REPORT_STATUS_BACKUP_ROM,(unsigned char *)&Event_Report_Status_Backup,sizeof(union EVENT_REPORT_STATUS),0,1);
    FeedWatchdog();
    WRLC256(EVENT_REPORT_STATUS_COMM_ROM,(unsigned char *)&Event_Report_Status_communication,sizeof(union EVENT_REPORT_STATUS),0,1);
    
	Pay_For_Para_Read();	//payment
	Pre_Init();


	return 1;
}
/*"计算累加和"*/
//unsigned char CALC_CS(unsigned char *ram, unsigned int length)
//{
//   unsigned int i;
//   unsigned char cs=0;
//   for(i=0;i<length;i++)
//   {
//        cs+=*(ram+i);
//   }
//   return cs;
//}

/********************************************************
*     1. use if bill when power up                      *
*     2.  type 0 no clear   F_EEPROM_FLAG_ROM  ;   1 clear it                           *
*********************************************************/
unsigned char IsNormalReset(unsigned char type)
{
	unsigned char uni;
	unsigned char data[3];
	ReadBlock(F_EEPROM_FLAG_ROM+3,(unsigned char *)data,3,0);// mark here
	if((data[0]!=0xA5) || (data[1]!=0xA5) || (data[2]!=0xA5))
	{
	   return 0;
	}
	if(type)
	{	
		for(uni=0;uni<3;uni++)
		   data[uni]=0;
		WRLC256(F_EEPROM_FLAG_ROM+3,(unsigned char *)&data,3,0,0);
	}
	return 1;
}

unsigned char IsHaveSaveData(void)
{
	unsigned int uni; 
	unsigned char result=0xFF;
	unsigned char data[3];
	
	WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,3,1);
	if((data[0]!=0xA5) || (data[1]!=0xA5) || (data[2]!=0xA5))
	{
	   WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,3,1);
	   if((data[0]!=0xA5) || (data[1]!=0xA5) || (data[2]!=0xA5))
	   {
	       result=0x00; 
	   }
	} 
	
//	for(uni=0;uni<3;uni++)
//	   data[uni]=0;
//	if(!IntoPowerDownFlag)      
//	   WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,3,0);
	
	return result;
	
}

void Clear_Savedata_flag(void)
{
	unsigned int uni; 
	unsigned char data[3];
	
	for(uni=0;uni<3;uni++)
	   data[uni]=0;
	if(!IntoPowerDownFlag)      
	   WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,3,0);
}

unsigned char IsNormalResetWrite(void)
{
   if(IsNormalReset(0))
   {
   	  PowerDownEvent_OnCheck();
   	  PowerAbnormalEventCheck();
   	  EMeterPowerdownRecord();  
	    return 1;
   }
	 else
	 {
	    ResetCpuEvent_OnCheck();   
	    return 0;
	 }
}
//unsigned char IsHaveSaveData(void) 
//{
//	unsigned int uni; 
//	unsigned char data[3];
//	ReadBlock(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,3);
//	if((data[0]!=0xA5) || (data[1]!=0xA5) || (data[2]!=0xA5))
//	{
//	   return 0;
//	}
//	for(uni=0;uni<3;uni++)
//	   data[uni]=0;
//	if(!IntoPowerDownFlag)      
//	 {
//	     WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,0,0);
//	 }
//	return 1;
//}

/*"============================================================================="*/
/*"结算电量"*/
/*"2009-09-22"*/
/*"============================================================================="*/
void Bill_Energy(unsigned char *billdate)
{
        unsigned int uni=0;
        unsigned char csadd=0;
        unsigned int length=0;
        unsigned char pointer=0,pointer1=0;
        
        p3_2=1;//arthor2007-04-17
        
     /* " 保存本月数据到具体历史空间"*/
		 
        length=sizeof(struct ENERGY_RECORD);
        
        for(uni=0; uni<length; uni++)
        {  
           Co.b[uni]=*((unsigned char *)&This_Month_Data.Energy_Record+uni);
     //      csadd+=Co.b[uni];
        }
      //  Co.b[uni]=csadd;//add by zlp

        WRLC256(O1ther_Meter_Parameter.Bill_Addr*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM,(unsigned char *)&Co,sizeof(struct ENERGY_RECORD),0,0);
        FeedWatchdog();
	 WRLC256(MONTH_BILL_NUM_ROM+O1ther_Meter_Parameter.Bill_Addr*4,(unsigned char *)billdate,4,0,0);///king chen add 130312

       // WRLC256(Meter_Parameter.Bill_Addr*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM,(unsigned char *)&Co,sizeof(struct ENERGY_RECORD),1,0);
       // Write_FM24C256_MULTI(Meter_Parameter.bill_state.Bill_Addr*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),FM24C256_1AND2); 
        CheckPowerDown();//fx add 090927
      
	      /*"将下一个历史空间清空"*/	
        pointer=O1ther_Meter_Parameter.Bill_Addr;
        pointer++;
        pointer%=14;
        WRLC256(pointer*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM,0,sizeof(struct ENERGY_RECORD),0,0);
                
        CheckPowerDown();//fx add 090927
                
        /*"备份本月数据"*/	
        WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0); 
        FeedWatchdog();  
       
        CheckPowerDown();//fx add 090927

}
/*"============================================================"*/
/*"函数名：Retort_New"*/
/*"用途：结算 存数 函数"*/
/*"参数：无"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
void Retort_New(unsigned char DemandDataBillFlag,unsigned char *billtime)
{        
        Bill_Energy((unsigned char *)billtime);
        ClearDemandCommAndKey(2,DemandDataBillFlag);
        Write_TO_Cal_PowerDown_Energy_add();
        CheckPowerDown();

        O1ther_Meter_Parameter.Bill_Flag=0xFF;
        O1ther_Meter_Parameter.Bill_Addr++;
        O1ther_Meter_Parameter.Bill_Addr%=MAXMONTHSAVE;
        O1ther_Meter_Parameter.Bill_DM_Addr++;
        O1ther_Meter_Parameter.Bill_DM_Addr%=MAXMONTHSAVE;
        O1ther_Meter_Parameter.LastEnergyBillDate=*((struct DATEANDTIME_DEF *)billtime);
        WRLC256(BILL_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.Bill_Flag,11,0,0);
        ///Set_Meter_para_Deal(BILL_FLAG_ROM);       
       // WRLC256(BILL_FLAG_ROM,(unsigned char *)&Meter_Parameter.Bill_Flag,11,1,0);
       // FeedWatchdog();
      // Write_FM24C256_MULTI(BILL_FLAG_ROM,(unsigned char *)&Meter_Parameter.bill_state.Bill_Flag,11,FM24C256_1AND2);
        CheckPowerDown();
}

#if 0
/*"============================================================"*/
/*"函数名：CalculateTime"*/
/*"用途：推算下一小时的时间"*/
/*"参数：无"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
unsigned char  CalculateHour(unsigned char* travertime)
{
     unsigned char data[4];
     unsigned char uni=0;   
   
     for(uni=0;uni<4;uni++)
        data[uni]=OB_H(*(travertime+uni));
      
     if(data[3]<23)
     {
      	data[3]++;
     }
     else
     {
      	data[3]=0;
      	if(data[2]<CalDay(data[0],data[1]) )
      	{
      	    data[2]++;
      	}
      	else
      	{
      	    data[2]=1;
      	    if(data[1]<12)
      	    {
      	    	data[1]++;
      	    }
      	    else
      	    {
      	    	data[1]=1; 
              if(data[0]<99)
      	    	{
      	    	    data[0]++;
      	    	}
      	    	else
      	    	{
      	    	    data[0]=0;                        
      	    	}
      	    }           
      	 }
      }      

   for(uni=0;uni<4;uni++)
      *(travertime+uni)=OH_B(data[uni]);
      
   return 1;   
}


/*" 上电补年结算 "*/
void powerup_check_year_bill(void)
{   
    int  num,nHour_add,pnumm;   
    unsigned char bill_date_flag;
    struct DATEANDTIME_DEF powd_date1,poweron_date2;

     /*" QQQ 先处理下电点 "*/
     if(CompareBytes((unsigned char *)&Powerdown_Save_Data.date,(unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate,4)>0)
     {
        if (is_year_bill_date(&Powerdown_Save_Data.date)) {
            Pre_Bill(&Powerdown_Save_Data.date.Year);
        }
     } 
     else if(CompareBytes((unsigned char *)&Powerdown_Save_Data.date,(unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate,4)<0)
     {/*"修改时间到最后一次结算时间前面"*/ 
         Meter_Parameter.bill_state.LastEnergyBillDate=Powerdown_Save_Data.date;
         WRLC256(LASTENERGYBILLDATE_ROM,(unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate,7,0,0);	
         Set_Meter_para_Deal(LASTENERGYBILLDATE_ROM); 

     }

     return;    
}
#endif


/*"============================================================"*/
/*"函数名：Check_New"*/
/*"用途：上电补结算函数"*/
/*"参数：无"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
void Check_New(void)
{	
	/// int  num,nHour_add,pnumm;	///king chen mark 130425
     ///unsigned char bill_date_flag;
     ///struct DATEANDTIME_DEF powd_date1,poweron_date2;

	 //     if(!Meter_Parameter.parameter1.MeterMode[2].bit.b6)/*"增加模式字3的BIT6为上电补结算控制位"*/
 	 //       return;
    

     if (YEAR_BILL_FLAG) 						/*" 如果是年计算阶梯，补年结算，并返回 "*/
	 {	
	    if( (Meter_Parameter.parameter1.MeterMode[2].bit.b6) && (POWERONYEARBILL_FLAG_DEFINE==0) )	 /*"增加模式字3的BIT6为上电补结算控制位"*/
		{
			PowerUpYearBill();						//Li Update 20130312
		}
	 }

     PowerUpRetort();
}


/*"============================================================"*/
/*"函数名："*/
/*"用途：设置默认参数"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
struct  CRCSTRUCT
{
	
  unsigned char  *Pinter;
  unsigned int  *crc_cal;
  unsigned int  Len;
};
void Set_Default_Para(void)
{
	unsigned int uni=0,unj=0;
	unsigned int i=0,j=0,k=0;

  struct  CRCSTRUCT   CrcStruct[4]=
  {
	  {(unsigned char *)&Meter_Parameter.parameter1,       (unsigned int *)&Meter_Parameter.parameter1.crc_cal,      sizeof(struct PARAMETER1)-2},
	  {(unsigned char *)&Meter_Parameter.parameter2,       (unsigned int *)&Meter_Parameter.parameter2.crc_cal,      sizeof(struct PARAMETER2)-2},
	  {(unsigned char *)&Meter_Parameter.event_parameter,  (unsigned int *)&Meter_Parameter.event_parameter.crc_cal, sizeof(struct EVENT_PARAMETER)-2},
	  {(unsigned char *)&Meter_Parameter.freeze_parameter, (unsigned int *)&Meter_Parameter.freeze_parameter.crc_cal,sizeof(struct FREEZE_PARAMETER)-2}
///	  {(unsigned char *)&Meter_Parameter.new_parameter, (unsigned int *)&Meter_Parameter.new_parameter.crc_cal,sizeof(struct NEW_PARAMETER)-2} ///king chen mark 121226
  };
	
	for(uni = 0; uni < sizeof(struct METER_PARAMETER); uni++)
	{
		*((unsigned char *)&Meter_Parameter + uni) = 0;
	}
	 for(uni=0;uni<4;uni++)
   {
      Meter_Parameter.parameter1.Commrate[uni].byte=0; 	
	    Meter_Parameter.parameter1.Commrate[uni].bit.B2400=1;
   }
   
   for(uni=0;uni<6;uni++)
   {
      Meter_Parameter.parameter1.BcdCommAddr[0][uni]=0x11; 	
	    Meter_Parameter.parameter1.BcdCommAddr[1][uni]=0x11;
	    Meter_Parameter.parameter1.BcdCommAddr[2][uni]=0x11;
	    
	    Meter_Parameter.parameter2.BcdMeterID[uni]=0;
   }
   Meter_Parameter.parameter2.BcdMeterID[5]=0x01;
   
	for(uni=0;uni<MAX_PASS_NUM;uni++)
	{
	    Meter_Parameter.parameter1.ClearPassword[uni][0]=uni;
	}

	Meter_Parameter.parameter1.ClearPassword[2][1]=0x56;   	
	Meter_Parameter.parameter1.ClearPassword[2][2]=0x34;   
	Meter_Parameter.parameter1.ClearPassword[2][3]=0x12;   

	Meter_Parameter.parameter1.ClearPassword[4][1]=0x78;   	
	Meter_Parameter.parameter1.ClearPassword[4][2]=0x56;   
	Meter_Parameter.parameter1.ClearPassword[4][3]=0x34;   

//	if(WR_Check_eeprom(JUSTMETER_PARA_ROM + 18*4+4,(unsigned char *)&JustMeter_Parameter.plus_const_BCD,(unsigned char *)&plus_comp,4,1))
//	{
//	     JustMeter_Parameter.plus_const_BCD=plus_temp;
//	}
//	if( (JustMeter_Parameter.plus_const_BCD < 1800000) && (JustMeter_Parameter.plus_const_BCD > 10))
//		{
//		if((JustMeter_Parameter.plus_const_BCD%10) == 0)
//			{
//			Meter_Parameter.parameter1.ActivePulseConst=JustMeter_Parameter.plus_const_BCD/10l;         
//	    Meter_Parameter.parameter1.ReactivePulseConst=JustMeter_Parameter.plus_const_BCD/10l;  
//			}
//		else
//			{
//			Meter_Parameter.parameter1.ActivePulseConst=JustMeter_Parameter.plus_const_BCD;         
//	    Meter_Parameter.parameter1.ReactivePulseConst=JustMeter_Parameter.plus_const_BCD;  
//			}
//		}
//	else
//		{
		Meter_Parameter.parameter1.ActivePulseConst=400;         
	  Meter_Parameter.parameter1.ReactivePulseConst=400;  
//		}  
	//----------------------------------------------------------------------     
	Meter_Parameter.parameter1.DemandPeriod=15;             
	Meter_Parameter.parameter1.DemandSkipPeriod=1;         
	Meter_Parameter.parameter1.CycleDisplayTime=5;                 
#if (MODULE_LOCAL_PAY_FLAG)				//payment
{
	Meter_Parameter.parameter1.DisplayNumber=19;
	Meter_Parameter.parameter1.KeyDisplayNumber=92;
}
#elif (MODULE_FAY_PAY_FLAG)
{
	Meter_Parameter.parameter1.DisplayNumber=18;
	Meter_Parameter.parameter1.KeyDisplayNumber=84;
}
#else
{
	Meter_Parameter.parameter1.DisplayNumber=20;
	Meter_Parameter.parameter1.KeyDisplayNumber=86;
}
#endif
	Meter_Parameter.parameter2.EnergyPoint=2;              
	Meter_Parameter.parameter2.PowerPoint=4;               
	
	Meter_Parameter.parameter1.AutoBillDayHour[0].Day=1;              
	Meter_Parameter.parameter1.AutoBillDayHour[0].Hour=0;
	Meter_Parameter.parameter1.AutoBillDayHour[1].Day=0x99;           
	Meter_Parameter.parameter1.AutoBillDayHour[1].Hour=0x99;   
	Meter_Parameter.parameter1.AutoBillDayHour[2].Day=0x99;        
	Meter_Parameter.parameter1.AutoBillDayHour[2].Hour=0x99; 
       ///Meter_Parameter.bill_state.LastEnergyBillDate.Month=0x01;///king chen mark 130308
       ///Meter_Parameter.bill_state.LastEnergyBillDate.Day=0x01;
	Meter_Parameter.parameter2.LoadDay=1;                  
	Meter_Parameter.parameter2.PulseWidth=PULSE_WIDTH;//80;    
	O1ther_Meter_Parameter.OutputModel=0x00;                       
	Meter_Parameter.parameter1.SlotParemeter[0].YearSlotNumble=2;         
	Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble=2;   
	Meter_Parameter.parameter1.SlotParemeter[0].DailySlotNumble=8;        
	Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=4;   
	Meter_Parameter.parameter1.SlotParemeter[0].WeekEndTable=1; 
	Meter_Parameter.parameter1.SlotParemeter[0].Week_Status.byte=0x7F;          
	Meter_Parameter.parameter1.SlotParemeter[0].HollidayNumble=0;         
	Meter_Parameter.parameter1.SlotParemeter[1].YearSlotNumble=2;         
	Meter_Parameter.parameter1.SlotParemeter[1].DailySlotTableNumble=2;   
	Meter_Parameter.parameter1.SlotParemeter[1].DailySlotNumble=8;        
	Meter_Parameter.parameter1.SlotParemeter[1].TriffNumble=4;   
	Meter_Parameter.parameter1.SlotParemeter[1].WeekEndTable=1; 
	Meter_Parameter.parameter1.SlotParemeter[1].Week_Status.byte=0x7F;              
	Meter_Parameter.parameter1.SlotParemeter[1].HollidayNumble=0;  
	                                                                                  
	Meter_Parameter.event_parameter.JudgeLossVoltage=75;
	Meter_Parameter.event_parameter.JudgeLossVoltageNV=78;  //change by pc 081225  
//	I_REGION=3;  ////10(40)A
//	V_REGION=1;  //220V
	Meter_Parameter.parameter1.EventJudgeIn=100000;
	Meter_Parameter.parameter1.DISP_In=1;  //mw added 2012.05.03
//------------ganjp 2009-5-6---------------------------------        
//       Write_Read_Cal24C02(0x100,(unsigned char *)&temp_i,1,1);
//	Write_Read_Cal24C02(0x104,(unsigned char *)&temp_v,1,1);	
//	if((temp_i > 10) || (temp_v > 4))
//		{
//		Write_Read_Cal24C02(0x104,(unsigned char *)&Meter_Parameter.parameter1.VI_Regulation + 1,1,0);
//              Write_Read_Cal24C02(0x100,(unsigned char *)&Meter_Parameter.parameter1.VI_Regulation,1,0);
//		}    
//-------------------------------------------------------
	Meter_Parameter.event_parameter.VoltageHealth_UpSet=2400;   
	Meter_Parameter.event_parameter.VoltageHealth_DownSet=2000; 
	Meter_Parameter.event_parameter.VoltageCheck_UpSet=2620;    
	Meter_Parameter.event_parameter.VoltageCheck_DownSet=1780;  //change by pc 081028 
	Meter_Parameter.parameter1.MeterMode[0].byte=0x0B;
	Meter_Parameter.parameter1.MeterMode[1].byte=0x06;	//payment
	Meter_Parameter.parameter1.MeterMode[2].byte=0x70;///king chen modify 130311
	Meter_Parameter.parameter1.MeterMode[3].byte=0x03;
	Meter_Parameter.parameter1.MeterMode_Alarm_Flag.Alarm_Flag=0x00401383;//MeterMode[4].byte=0x06;
   Meter_Parameter.parameter1.MeterMode_LedAlarm_Flag.Alarm_Flag=0x000f;
   Meter_Parameter.parameter1.MeterMode_SpeakerAlarm_Flag.Alarm_Flag=0x0000;
   Meter_Parameter.parameter1.MeterMode_TerminalAlarm_Flag.Alarm_Flag=0x00401383;
   Meter_Parameter.parameter1.MeterTypeMode.byte=0x00;  
	Meter_Parameter.parameter1.CarrierMode.byte=0x80;
   Meter_Parameter.parameter1.LocalFunctionMode.byte=0x00; 
   
#if (MODULE_CARRIER_FLAG || MODULE_FAY_PAY_FLAG)	//payment
{
	Meter_Parameter.parameter1.MeterMode[0].bit.b3=1;	//comm2 set data
#if (MODULE_LOCAL_PAY_FLAG)
		Meter_Parameter.parameter1.MeterMode[1].bit.b5=1;	//payment
#endif
#if (MODULE_FAY_PAY_FLAG)
		Meter_Parameter.parameter1.MeterTypeMode.bit.b5=1;
#endif
}
#endif

	Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte=0x41;// FXF ADD 081027
	Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte=0x14;// FXF ADD 081027
	Meter_Parameter.parameter1.Activem_Erengy_Mode.byte=0x05;	
	Meter_Parameter.parameter2.LoadRecordMode.byte=0x3F;
	Meter_Parameter.parameter2.ExitProgrameTime=240;  //mw added 070515
	Meter_Parameter.event_parameter.JudgeLossVoltageSecond=60; //mw added 070515
	Meter_Parameter.event_parameter.JudgeBreakPhaseSecond=60; //mw added 070808  change by pc 081028
	
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Year=0;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Month=0x01;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Day=0x01;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Hour=0;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Min=0;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Sec=0;
	Meter_Parameter.parameter2.LoadRecoedBeginTime.Week=0;
	
	for(uni=0;uni<6;uni++)
	   Meter_Parameter.parameter2.LoadRecordPeriod[uni]=15;
	Meter_Parameter.freeze_parameter.FreezeDate[0]=0x00; 
	Meter_Parameter.freeze_parameter.FreezeDate[1]=0x12; 
	Meter_Parameter.freeze_parameter.FreezeDate[2]=0x99; // FXF ADD 081027
	Meter_Parameter.freeze_parameter.FreezeDate[3]=0x99; // FXF ADD 081027
	Meter_Parameter.freeze_parameter.FreezeDay_Hour=0; 
	Meter_Parameter.freeze_parameter.FreezeDay_Min=0; 
	Meter_Parameter.freeze_parameter.New645_Freeze_Time_Mode.byte=0xff;// FXF ADD 081118
	Meter_Parameter.freeze_parameter.New645_Freeze_Moment_Mode.byte=0xff;// FXF ADD 081118
	Meter_Parameter.freeze_parameter.New645_Freeze_Promise_Mode.byte=0xff;// FXF ADD 081118
	Meter_Parameter.freeze_parameter.New645_Freeze_Period_Mode.byte=0x03;// 
	Meter_Parameter.freeze_parameter.New645_Freeze_Day_Mode.byte=0xff;// FXF ADD 081118

        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Year=0x10;
        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Month=0x01;
        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Day=0x01;
        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Hour=0x00;
        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Min=0x00;
        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Sec=0x00;
       Meter_Parameter.freeze_parameter.Freeze_Period_Date.Week=0x00;
        
	Meter_Parameter.freeze_parameter.Freeze_Period_Interval=60; 	
	Meter_Parameter.parameter2.Meterlocktimes=0x03;  // mw added 070510
	
	Meter_Parameter.event_parameter.JudgeLostCurr_I[0]=75;  //add by pc 081028
	Meter_Parameter.event_parameter.JudgeLostCurr_I[1]=750;  //add by pc 081028
	Meter_Parameter.event_parameter.JudgeLostCurr_T=60;      //add by pc 081028
	Meter_Parameter.event_parameter.CriticalVoltage=60;      //add by pc 081028
	Meter_Parameter.event_parameter.JudgeBreakPhaseI=75;     //add by pc 081028
	Meter_Parameter.event_parameter.PaADemandLimit=47520;    //add by pc 081028
	Meter_Parameter.event_parameter.NeADemandLimit=47520;    //add by pc 081028
	Meter_Parameter.event_parameter.JudgeOverVolt_V=2640;     //add by pc 081028
	Meter_Parameter.event_parameter.JudgeCurrImBalanceN=3000;  //add by pc 081216
	Meter_Parameter.event_parameter.JudgeVoltImBalanceN=2000;  //add by pc 081216
	Meter_Parameter.event_parameter.JudgeVoltDown_V=1716;        //add by pc 090721
	Meter_Parameter.event_parameter.JudgeOverCurrentI=60;   //add by pc 090721	  
	Meter_Parameter.parameter2.ShowNoKeyRetTime=60;
	Meter_Parameter.event_parameter.JudgeLostVoltSV=1716;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeLostVoltEV=1870;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeVoltDownT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeOverVoltT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeBreakPhaseV=1320;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeVoltImBalanceT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeCurrImBalanceT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeLostCurrSV=1540;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeOverCurrentT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgePowerReverseP=17;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgePowerReverseT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeABCPowerReverseP=17;
	Meter_Parameter.event_parameter.JudgeABCPowerReverseT=60;
	Meter_Parameter.event_parameter.JudgeUpLoadP=15840;   	/*"过载事件有功功率触发下限"*/
	Meter_Parameter.event_parameter.JudgeUpLoadT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeOverDemandP=47520;   /*"有功需量超限事件需量触发下限"*/
	Meter_Parameter.event_parameter.JudgeOverFactorN=300;   //add by pc 090929
	Meter_Parameter.event_parameter.JudgeOverFactorT=60;   //add by pc 090929
	Meter_Parameter.event_parameter.JudgeCurrFarImBN=9000;   //add by pc 091007
	Meter_Parameter.event_parameter.JudgeCurrFarImBT=60;   //add by pc 091007
	Meter_Parameter.event_parameter.JudgeFailCurrSV=1320;   //add by pc 091007
	Meter_Parameter.event_parameter.JudgeFailCurrI=75;   //add by pc 091007
	Meter_Parameter.event_parameter.JudgeFailCurrT=60;   //add by pc 091007
	Meter_Parameter.event_parameter.JudgeOverDemandN=47520;   //add by pc 090927
	Meter_Parameter.event_parameter.JudgeOverDemandT=60;   //add by pc 090927
	Meter_Parameter.event_parameter.AD_Sample_Vref=490;
	Meter_Parameter.event_parameter.ClockBattery_volt_Low_Threshold=261;
	Meter_Parameter.event_parameter.DisplayBattery_volt_Low_Threshold=481;
	Meter_Parameter.parameter2.BroadcastJustTtimes=1;
	Meter_Parameter.event_parameter.JudgeCurrImBMinI=50;   
    Meter_Parameter.parameter2.JFPG_ExpressTriff[0]=1;    //JIAN
    Meter_Parameter.parameter2.JFPG_ExpressTriff[1]=2;    //FENG
    Meter_Parameter.parameter2.JFPG_ExpressTriff[2]=3;    //PING
    Meter_Parameter.parameter2.JFPG_ExpressTriff[3]=4;    //GU
	Max_Triff_Current=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble; //add by fxf  090227	

	Meter_Parameter.parameter2.PowerOnFullScreenTime=0x05;///king chen modify 130204
	Meter_Parameter.parameter1.ResetReportTime=30;
/*"主动上报模式默认开启上报事项如下：开表盖，恒定磁场，过流，电表清零"*/
    for(i = 0; i < 8; i++)
    	{
    	Meter_Parameter.parameter1.EventReportMode.byte[i] = 0x00;
    	}
	Meter_Parameter.parameter1.EventReportMode.byte[1] = 0x14;
	Meter_Parameter.parameter1.EventReportMode.bit.OverCurr = 1;
	Meter_Parameter.parameter1.EventReportMode.bit.Meter_clear= 1;

	
	Meter_Parameter.parameter1.UserClass[0]=1;
	
	Meter_Parameter.parameter2.Longitude=0;
	Meter_Parameter.parameter2.Latitude=0;
	Meter_Parameter.parameter2.Height=0;
	for(uni=0;uni<8;uni++)
	   Meter_Parameter.parameter2.MeterSoftIdNumber[uni]=0xAA;
	
	for(i = 0; i < 4; i++)
	{
		*(CrcStruct[i].crc_cal) = CRC(CrcStruct[i].Pinter, CrcStruct[i].Len);
	}
 	k=sizeof(struct METER_PARAMETER);

		FeedWatchdog();  
		WRLC256(METER_PARAMETER_ROM,(unsigned char *)&Meter_Parameter,sizeof(struct METER_PARAMETER),0,0);		
		FeedWatchdog();
		WRLC256(END_ROM1,(unsigned char *)&k,2,0,0);	
		
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"函数名："*/
/*"用途：判断参数定义是否改变"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
unsigned char Check_Para_Def(void)
{
	unsigned int k,j;
	unsigned char flag;
	unsigned long times=0;
	if(IntoPowerDownFlag!=0) return 0;
	flag=0;
	WRLC256(END_ROM1,(unsigned char *)&k,2,0,1);
	j=sizeof(struct METER_PARAMETER);
	if(j!=k)
	{
		do
	      {
	      	 Delay(1);
	      	 times++;
	      	 if(!J1)
	      	 {
	      	    Delay(50);
	      	    if(!J1)
	      	    {
	      	       //display	
	      	       flag=0xFF;
	      	    }
	      	 }
	      }while(times<20 && (!flag));
	}	
	return flag;
}
/*"============================================================"*/
/*"函数名："*/
/*"用途：把初始化FLASH 和初始化其他参数分开"*/
/*"参数："*/
/*"返回："*/
/*"作者：Fuxf 版本：1.00"*/
/*"============================================================"*/
void Set_Flash_Default(void)
{
 	
     if(IsNewEepromOrFlash(FLASH_FLAG))
    {
          if(Fs_Init()==0)             
          {
              Show_Initialize(0);
          }
    }
		
}
/*"============================================================
函数说明：检查eeprom中数据是否有效
输入参数：rom_addr  eeprom中数据地址
          len       数据长度
输出参数：无
返    回：data_valid  ：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Check_eeprom_data_validity(unsigned int rom_addr, unsigned int len)
{
	unsigned int uni = 0;
	
	unsigned char data_valid = 0;
	unsigned char *addr;
	unsigned int  crc_value = 0;
	unsigned char ret_value = 0;
	
	addr = &Co.b[300];
	
	for(uni = 0; uni < len; uni++)
	
	*(addr + uni) = 0;
	
	ret_value = ReadBlock(rom_addr, addr, len, 0);		
	
	if(ret_value != 0)
		{
			crc_value =*((unsigned int *)(addr + len - 2));
	
	    data_valid = Check_RAM_CRC(addr, crc_value, (len - 2));	//check crc validity
		}
	else
		{
			data_valid = 2;
		}								   
	return (data_valid);
}
/*"============================================================
函数说明：RAM中数据上电处理，RAM中数据有效，以RAM中数据为准，
          RAM中数据无效时，读取相应EEPROM中数据进行有效性判读
          如果EEPROM中数据有效，恢复RAM中数据，如果无效，则报
          数据乱警告
输入参数：ram_addr  RAM中数据地址
          rom_addr  eeprom中数据地址
          len       数据长度
输出参数：无
返    回：data_valid：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Ram_data_powerup_process(unsigned char *ram_addr, unsigned int rom_addr, unsigned int len)
{	
	unsigned char data_valid = 0;
	unsigned int  crc_val = 0;
	unsigned char eeprom_valid = 0;
	unsigned int uni = 0;
	union   BYTE_DEF result;
	 
	result.byte = 0;
	
	crc_val =*((unsigned int *)(ram_addr + len -2));
	
		
	data_valid = Check_RAM_CRC(ram_addr, crc_val, len - 2);//check crc validity
	
	if(data_valid != 0)
		{			
			if(Meter_Parameter.parameter1.DemandPeriod > 99)
				{
					RamPara_valid_flag.bit.b0 = 1;
				}
				
			if((Meter_Parameter.parameter1.DemandPeriod/Meter_Parameter.parameter1.DemandSkipPeriod) > 15 ||
			   (Meter_Parameter.parameter1.DemandPeriod%Meter_Parameter.parameter1.DemandSkipPeriod) != 0)
			  {
			  	RamPara_valid_flag.bit.b1 = 1;
			  }	
			if((Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble > MAXTRIFF) ||
				 (Meter_Parameter.parameter1.SlotParemeter[0].YearSlotNumble > MAXYEARSLOT) ||
				 (Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble > MAXDAILYSLOTTABLE) ||
				 (Meter_Parameter.parameter1.SlotParemeter[0].DailySlotNumble > MAXDAILYSLOT) ||
				 (Meter_Parameter.parameter1.SlotParemeter[0].WeekEndTable > MAXDAILYSLOTTABLE))
				{
					RamPara_valid_flag.bit.b2 = 1;
				}		
			if((Meter_Parameter.parameter2.EnergyPoint > 3) ||
				 (Meter_Parameter.parameter2.PowerPoint > MAXDAUTOVALUE))
				{
					RamPara_valid_flag.bit.b3 = 1;
				}		
			if(Meter_Parameter.parameter2.PulseWidth != PULSE_WIDTH)
				{
					RamPara_valid_flag.bit.b4 = 1;
				}
		}

	if((data_valid == 0) || ((RamPara_valid_flag.byte & 0x1f) != 0))//ram data err
		{
			for(uni = 0; uni < len ; uni++)//clear ram data
			{
				*(ram_addr + uni) = 0;
			}
			data_valid = Check_eeprom_data_validity(rom_addr, len);
			
			if(data_valid == 1)//eeprom data ok 
				{
					data_valid = ReadBlock(rom_addr, ram_addr, len, 0);//resume data to ram
					if(data_valid == 0)
						{
							result.bit.b0 = 1;
						}
				}
			else
				{
					ReadBlock(rom_addr, ram_addr, len, 0);//resume data to ram
					if(data_valid == 2)//read err
						{
							result.bit.b1 = 1;
						}
					else
						{
							result.bit.b2 = 1;
							para_err_times++;
						}
				}
		}
	else
		{
			eeprom_valid = Check_eeprom_data_validity(rom_addr, len);
			if(eeprom_valid == 0)
				{
					data_valid = WRLC256(rom_addr,ram_addr,len,0,0);//eeprom err ,resume eeprom
					if(data_valid == 0)
						{
							result.bit.b3 = 1;
						}
				}
			else if(eeprom_valid == 2)
				{
					result.bit.b4 = 1;
				}
		}
	
	return (result.byte);
}
/*"============================================================
函数说明：RAM中参数数据上电处理主函数
输入参数：无
输出参数：无
返    回：无  ：
作    者：GANJP  版本：1.00
============================================================"*/
void Para_Process_main(void)
{
	unsigned char i = 0;
//	union BYTE_DEF Err_inf; 
	
	struct  RAMSTRUCT   RamStruct[4]=///king chen modify 121226
  {
	  {PARAMETER1_ROM,           (unsigned char *)&Meter_Parameter.parameter1,           sizeof(struct PARAMETER1)},
	  {PARAMETER2_ROM,           (unsigned char *)&Meter_Parameter.parameter2,           sizeof(struct PARAMETER2)},
	  {EVENT_PARAMETER_ROM,      (unsigned char *)&Meter_Parameter.event_parameter,      sizeof(struct EVENT_PARAMETER)},
	  {FREEZE_PARAMETER_ROM,     (unsigned char *)&Meter_Parameter.freeze_parameter,     sizeof(struct FREEZE_PARAMETER)}
///	  {NEW_PARAMETER_ROM,           (unsigned char *)&Meter_Parameter.new_parameter,           sizeof(struct NEW_PARAMETER)}   ///king chen add 121226
	
//	  {OTHER_METER_PARAMETER_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoomState, sizeof(struct OTHER_METER_PARAMETER)},
//	  {OTHER_DATA_ROM,           (unsigned char *)&Other_Data,                           sizeof(struct OTHER_DATA)}	        
  };
  
 // Err_inf.byte = 0;
 for(i = 0; i < 4; i++)
 {
 	 Parameter_flag[i].byte = 0;
 }  
  if(Check_Para_Def()==0xff)
	{
		FeedWatchdog();
		Set_Default_Para();
		FeedWatchdog(); 
	}
	else
		{
			RamPara_valid_flag.byte = 0;
			for(i = 0; i < 4; i++)
       {
       	Parameter_flag[i].byte = Ram_data_powerup_process(RamStruct[i].Pinter, RamStruct[i].Addr, RamStruct[i].Len);
       	
//       	if(Ram_data_powerup_process(RamStruct[i].Pinter, RamStruct[i].Addr, RamStruct[i].Len) != 0)
//       		{
//       			Parameter_flag[i].byte |= (0x01 << i);
//       		}
       	FeedWatchdog();
       }  
//      if(Err_inf.byte != 0)
//      	{
//      		////alarm!!!!!!!!!
//      		Meter_States.Meter_Flag.bit.Parameter_Data_Err = 1;
////      		for(i = 0; i< 5; i++)
////      		{
////      			WRLC256(RamStruct[i].Addr,RamStruct[i].Pinter,RamStruct[i].Len,0,1);
////      			FeedWatchdog();
////      		}
//   	}
		}  

   Max_Triff_Current=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble; //add by fxf  090227
}
/*"============================================================
函数说明：上电补充电池工作时间等
输入参数：无
输出参数：无
返    回：无  ：
作    者：FUXF  版本：1.00
============================================================"*/
void PowerUp_Check_BatteryWorkTime(double long data)  
{
     unsigned char uni,result3=0xff;
     
	 data/=60;
	 for(uni=0;uni<8;uni++)
	 {
	       if(Valid_IntoPowerdown_Flag[uni]!=uni) 
	       {
	           result3=0;
	           break;
	       }
	 }
	 if(result3)
	       Other_Data.BatteryWorkTime1+=data;
	 Other_Data.BatteryWorkTime2+=data;
	       
	 WRLC256(BATTERYWORKTIME1_ROM,(unsigned char *)&Other_Data.BatteryWorkTime1,8,0,0);
        
}

/*"============================================================
函数说明：上电电表参数处理出错情况下，运行过程中的参数处理
输入参数：无
输出参数：无
返    回：无  ：
作    者：GANJP  版本：1.00
============================================================"*/
void Para_Process_run(void)
{
	unsigned char ret_value = 0;
	unsigned char uni;
	struct  RAMSTRUCT   RamStruct[4]=///king chen modify 121226
  {
	  {PARAMETER1_ROM,           (unsigned char *)&Meter_Parameter.parameter1,           sizeof(struct PARAMETER1)},
	  {PARAMETER2_ROM,           (unsigned char *)&Meter_Parameter.parameter2,           sizeof(struct PARAMETER2)},
	  {EVENT_PARAMETER_ROM,      (unsigned char *)&Meter_Parameter.event_parameter,      sizeof(struct EVENT_PARAMETER)},
	  {FREEZE_PARAMETER_ROM,     (unsigned char *)&Meter_Parameter.freeze_parameter,     sizeof(struct FREEZE_PARAMETER)}
///	  {NEW_PARAMETER_ROM,           (unsigned char *)&Meter_Parameter.new_parameter,           sizeof(struct NEW_PARAMETER)}   ///king chen modify 121226
  };
	for(uni = 0; uni < 4; uni++)///king chen modify 121226
	{
		if((Parameter_flag[uni].byte & 0x1b) != 0)
		  {
		  	if(Parameter_flag[uni].bit.b0 == 1)
		  		{
		  			ret_value = ReadBlock(RamStruct[uni].Addr, RamStruct[uni].Pinter, RamStruct[uni].Len, 0);//resume data to ram
		  			if(ret_value)
		  				{
		  					Parameter_flag[uni].bit.b0 = 0;
		  				}
		  		}
		  	if(Parameter_flag[uni].bit.b1 == 1)
		  		{
		  			ret_value = Check_eeprom_data_validity(RamStruct[uni].Addr, RamStruct[uni].Len);
		  			if(ret_value == 1)
		  				{
		  					ret_value = ReadBlock(RamStruct[uni].Addr, RamStruct[uni].Pinter, RamStruct[uni].Len, 0);//resume data to ram
					      if(ret_value == 0)
					      	{
					      		Parameter_flag[uni].bit.b0 = 1;
					      		Parameter_flag[uni].bit.b1 = 0;
					      	}
					      else
					      	{
					      		Parameter_flag[uni].bit.b1 = 0;
					      	}
		  				}
		  			else
		  				{
		  					if(ret_value == 0)
		  						{
		  							Parameter_flag[uni].bit.b2 = 1;
		  							Parameter_flag[uni].bit.b1 = 0;
							      para_err_times++;
		  						}
		  				}
		  		}
		  	if(Parameter_flag[uni].bit.b3 == 1)
		  		{
		  			ret_value = WRLC256(RamStruct[uni].Addr, RamStruct[uni].Pinter, RamStruct[uni].Len, 0, 0);//eeprom err ,resume eeprom
		  			if(ret_value != 0)
		  				{
		  					Parameter_flag[uni].bit.b3 = 0;
		  				}
		  		}
		  	if(Parameter_flag[uni].bit.b4 == 1)
		  		{
		  			ret_value = Check_eeprom_data_validity(RamStruct[uni].Addr, RamStruct[uni].Len);
		  			if(ret_value == 0)
		  				{
		  					ret_value = WRLC256(RamStruct[uni].Addr, RamStruct[uni].Pinter, RamStruct[uni].Len, 0, 0);//eeprom err ,resume eeprom
		  			    if(ret_value == 0)
		  			    	{
		  			    		Parameter_flag[uni].bit.b3 = 1;
		  			    		Parameter_flag[uni].bit.b4 = 0;
		  			    	}
		  			    else
		  			    	{
		  			    		Parameter_flag[uni].bit.b4 = 0;
		  			    	}
		  				}
		  			else
		  				{
		  					if(ret_value == 1)
		  						{
		  							Parameter_flag[uni].bit.b4 = 0;
		  						}
		  				}
		  		}
		  }
	}	
}

/*"======================END=================================="*/
