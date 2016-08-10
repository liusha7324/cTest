/******************************************************************************************
*                      fine:      multi.c                                                  *
*                      function:  others functions                                          *
*******************************************************************************************/  

#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "att7022_operation.h"
#include "initram.h"
#include "Demand.h"
#include "MB_Showmain.h"
#include "MB_Keymain.h"
//#include "MB_Iccard.h"
#include "seg.h" 
#include "AllVoltageLoss.h"
#include "multi.h"   //mw added 080131
#include "Freeze.h"  //fxf  added081027
#include "File_System.h"  //add by pc 081208
#include "Measure_Interface.h" 
#include "Pay_def.h"
#include "Ex_Pay_For_Fun.h"		//payment
#include "ICcard.h"
#include "Energy_Del.h"
#include "BackLight_Ctrl.h"///
#include "eventnew.h"
#include "Clock_time.H"
#include "MB_BASE_FUN.h"


extern unsigned  char OverPowerAlarmFlag;//ganjp 20091127
extern unsigned int CrcEvent0Flag;
extern unsigned long Event0BeginAmpHour[36];
extern unsigned int CrcEventPowerDownData;
extern unsigned int CrcVoltStatData;
extern unsigned long Event_AmpHour[3];
extern struct VoltStatistic_Data VoltStat[4];

#define OneMinuteb                TimeChontrolBeginFlag.bit.b0
#define OneSecondb                TimeChontrolBeginFlag.bit.b1
#define TenMinuteb                TimeChontrolBeginFlag.bit.b2
#define ThirtydMinuteb            TimeChontrolBeginFlag.bit.b3
#define TwoMinuteb                TimeChontrolBeginFlag.bit.b4
#define OneMinuteThirtSb          TimeChontrolBeginFlag.bit.b5
#define FiveSecond                TimeChontrolBeginFlag.bit.b6
#define FiveSecondb               TimeChontrolBeginFlag.bit.b7

unsigned char Err_Back_Energy_Num; /*"备份内卡写入和读出出错次数"*/
unsigned char OLD_TRAFF_RATE;  /*"上次查询费率号"*/
unsigned long Light_Back_Time;  /*"背光点亮起始时刻"*/
unsigned int Event_Data;  /*"全失压数据内存地址"*/
unsigned char Event_Num;  /*"全失压发生次数"*/
unsigned long Event_Time; /*"全失压发生时间"*/
unsigned char ErrEnergyNumber; /*"备份内卡时，所有数据出错时次数"*/
//unsigned char OpenRailCover_times; /*"端盖打开后延时"*/  //change by pc 081020
//unsigned char OpenUpCover_times;   /*"上盖打开后延时"*/  //change by pc 081020
//unsigned char WriteEE_Or_F=0;    /*"数据备份时写EE还是写铁电"*/
struct ENERGY_BACK  energy_back;
unsigned char ClockBatteryClear_Flag[8];  //add by pc 090116
unsigned char ClockBatteryClearCounter;
unsigned char TempClockBatteryClearCounter;  //add by pc 090302
//---------GANJP 20090701----------------------------
unsigned char Light_Back_Up_Flag;/*"背光点亮标志，0:按键，FF:红外"*/
unsigned char workroom_cnt=0;/*"工厂状态进入时需要延时1秒"*/
unsigned char RamData_Valid_flag[16];/*"低功耗下Ram数据有效标志"*/
unsigned int  powerup_init_time;/*"上电初始化时间 单位ms"*/

void PowerUpProcese(void);
void PowerUpLossTotalVoltage(void);
void FeedWatchdog(void);
void CheckPowerDown(void);                                
void Measure(void);                         
void OpenCoverCheck(void);        
void Clear_Bill(void);            
void Bill(void);                                                                                                 
              
void BackupDataToEeprom(void);    
void FindTriff(void);
void DemandPowerUpShift(void);
void DemandPowerUpResume(void);
unsigned char  BackUpEnergyToRam(void);
void Monitor_Program(void);
void Light_Back_Led(void);
void Close_Back_Light(void);
void CheckTriffDateChange(unsigned char );
void CheckEnergyPassZero(void);
void CheckState(void);
void FreezeData_All(unsigned char ,unsigned char );
void CheckState_New645(void);//Fuxf add 20081114
signed long Cal_EnergyLimit(void); // trend move 2008-12-5 15:04:09
void Check_If_Clear_all(void);
void CheckDailySlotDateChange(unsigned char kind);

void RailEnergyValidity(void);//add by zlp
unsigned char TimeUPLimit(void);//add by zlp
void ResetTime(void); //add by zlp


void Bill_New(void);
unsigned char Check_Billdate_Validity(unsigned char* date,unsigned char number);
extern unsigned char  Clear_All_New(unsigned long);	//payment
unsigned int CRC(unsigned char *startaddr, unsigned int len);

void Meter_Staut_Check_And_Count(void);///king chen add 121214

void Event_Report_Status_Chk(unsigned char kind);
void Get_Event_Report_Status(union EVENT_REPORT_STATUS *EventReportStatus);

 void Clear_ALLEventReportInfo_NO_ACK(void);
 void EventReportState_Expand(unsigned char Nbyte, unsigned char n,unsigned char State);
void ESAM_ErrReport(void);
void SwitchOn_Report(void);
void SwitchOff_Report(void);
void Overdraft_Report(void);
unsigned char CheckBatteryVoltValid(void);
/*" 上电全显和延时，360×8＝2880ms"*/
void PowerUpProcese(void)
{
   unsigned int tn;     
   IF_Powerup_Savedata=0;   /*" 延时标志"*/
   IF_Powerup_Readdata=0;   /*" 读数标志"*/
   IF_Powerup_Billdata=0;   /*" 上电结算标志"*/
   InitMainRegeist();
   IntoPowerDownFlag=0;
	 CheckPowerDown();
	 //pd0_6=1;  //reset down cpu;
   //p0_6=0;
	 pd5_2 = 1;	
	 PULSE_PWR=1;
   pd6_4=1;                 /*"看门狗"*/
	 Delay(10); 	
	 //p0_6=1; 
	
   CheckPowerDown();
   IntoPowerDownFlag=0;
   FeedWatchdog();
   Delay(60); 
	 InitPort();				//LDH:20050921

   /// LED_ALARM=1;///king chen mark 121214
    SWITCH_CLEW=1;
    BackLight_Ctrl(POWER_UP_LIGHT_MODE,0,0,FULLSCREEN_EVENT);///king chen add 130304
	 Delay(2);
	 Show_Initialize(0);		        //LDH:20050921
   FeedWatchdog();
   Delay(60);  
   pd6_4=1;
   FeedWatchdog();
   CheckPowerDown();
   Delay(60);
      
   FeedWatchdog();
   CheckPowerDown();
   Delay(60);   
   FeedWatchdog();
   CheckPowerDown();
   //Delay(60);   				//denoted by LDH 20070428
   FeedWatchdog();
   CheckPowerDown();
   //Delay(60);   				//denoted by LDH 20070428
   FeedWatchdog();
   CheckPowerDown();
   IF_Powerup_Savedata=1;
   CheckPowerDown();
   if(0==CheckBatteryVoltValid()) 
   {
   for(tn=0;tn<48;tn++)
   {
   if(tn==36)/*"电能表在上电时应全屏显示5s，开白色背光，同时跳闸灯和报警灯亮2s，便于检测人员检查"*/
   {
      ///LED_ALARM=0;///king chen mark 121214
      ///SWITCH_CLEW=0;///king chen mark 121214
   }
   Delay(50);   				
   CheckPowerDown();
   }
   }
}


/*"上电清零时，保存需量空间和全失压数据"*/
struct SHIFT_DATA
{
   unsigned char *prt_scr;
   unsigned int  len;
};

void DemandPowerUpShift(void)
{
  unsigned char uni=0;
  unsigned int n=0;
  unsigned char *prt_des = (unsigned char *)&CommB;
  struct SHIFT_DATA Source_data[18]={{(unsigned char *)&This_Month_Data.Energy_Record, sizeof(struct ENERGY_RECORD)},
  	                                {(unsigned char *)&JustMeter_Parameter, sizeof(struct JUSTMETER_PARAMETER)},
  	                                {(unsigned char *)&Meter_Parameter, sizeof(struct METER_PARAMETER)},
  	                                {(unsigned char *)&Powerdown_Save_Data, sizeof(struct POWERDOWN_SAVE_DATA)},
  	                                {(unsigned char *)&energy_rail, sizeof(struct ENERGY_RAIL_ADD_BUFFER)},
  	                                {(unsigned char *)&Event_Power_Net_Flag, 8},  	                                  	                                  	                                
  	                                {(unsigned char *)&Event0BeginAmpHour, 164}, /*"此处包含下面6项内容"*/
  	                                {(unsigned char *)&Event_AmpHour, 12},                                    
  	                                {(unsigned char *)&VoltStat, 192},
  	                                {(unsigned char *)&PD_curr, sizeof(struct	PD_CURRENT_STRUCT)},
  	                                {(unsigned char *)&Valid_IntoPowerdown_Flag, 8},
                                    {(unsigned char *)&ClockBatteryClear_Flag, 8},
                                    {(unsigned char *)&ClockBatteryClearCounter, 2},
                                    {(unsigned char *)&Event_Power_Net_Timeticks, 192},
                                    {(unsigned char *)&pdvoltdata, sizeof(struct PDVOLT_STRUCTURE)},
                                    {(unsigned char *)&pdopencovercheckdata[0], sizeof(struct	PDOPENCOVER_STRUCTURE)*2},
                                    {(unsigned char *)&powerup_init_time, 2},
                                    {(unsigned char *)&rtc_lossvolt_flag, 4}
  	                               };
  for(uni = 0; uni < 18; uni++)
  {
  	for(n = 0; n < Source_data[uni].len; n++)
  	*(prt_des++) = *(Source_data[uni].prt_scr++);
  }    
}

/*"上电清零时，保存需量空间和全失压数据"*/
void DemandPowerUpResume(void)
{
  unsigned char uni=0;
  unsigned int n=0;
  unsigned char *prt_des = (unsigned char *)&CommB;
  struct SHIFT_DATA Source_data[18]={{(unsigned char *)&This_Month_Data.Energy_Record, sizeof(struct ENERGY_RECORD)},
  	                                {(unsigned char *)&JustMeter_Parameter, sizeof(struct JUSTMETER_PARAMETER)},
  	                                {(unsigned char *)&Meter_Parameter, sizeof(struct METER_PARAMETER)},
  	                                {(unsigned char *)&Powerdown_Save_Data, sizeof(struct POWERDOWN_SAVE_DATA)},
  	                                {(unsigned char *)&energy_rail, sizeof(struct ENERGY_RAIL_ADD_BUFFER)},
  	                                {(unsigned char *)&Event_Power_Net_Flag, 8}, 
  	                                {(unsigned char *)&Event0BeginAmpHour, 164}, /*"此处包含下面6项内容"*/
  	                                {(unsigned char *)&Event_AmpHour, 12},                                    
  	                                {(unsigned char *)&VoltStat, 192},
  	                                {(unsigned char *)&PD_curr, sizeof(struct	PD_CURRENT_STRUCT)},
  	                                {(unsigned char *)&Valid_IntoPowerdown_Flag, 8},
                                    {(unsigned char *)&ClockBatteryClear_Flag, 8},
                                    {(unsigned char *)&ClockBatteryClearCounter, 2},
                                    {(unsigned char *)&Event_Power_Net_Timeticks, 192},
                                    {(unsigned char *)&pdvoltdata, sizeof(struct PDVOLT_STRUCTURE)},
                                    {(unsigned char *)&pdopencovercheckdata[0], sizeof(struct	PDOPENCOVER_STRUCTURE)*2},
                                    {(unsigned char *)&powerup_init_time, 2},
                                    {(unsigned char *)&rtc_lossvolt_flag, 4}
  									                };
  for(uni = 0; uni < 18; uni++)
  {
  	for(n = 0; n < Source_data[uni].len; n++)
  	 *(Source_data[uni].prt_scr++) = *(prt_des++);
  }    
}



#if(ALLLOSSVOLTAGE_MODE == 0)	
/*"上电全失压数据存内卡"*/
void PowerUpLossTotalVoltage(void)
{
        unsigned char unc;  //add by pc 081208
        unsigned int uni;
        unsigned int tempuni;  //add by pc 081208
        unsigned char WriteNum;  /*"全失压次数，最多10次"*/
        unsigned char BeginAddr; /*"全失压起始地址"*/
        unsigned long curr_temp=0;
        
        
        Get_AllVoltageLoss_Event_Address_Times((unsigned int*)&Event_Data,(unsigned char *)&Event_Num,(unsigned long *)&Event_Time);
        
        //Event_Power_Net_Times.TotalLostVoltage_Times+=Event_Num;
        Event_Power_Net_Times.Phase3LostVolt_Times+=Event_Num;  //change by pc 081208
        if(Event_Num>10)
        {
            WriteNum=10;
            BeginAddr=(Event_Num)%10;
        }
        else  
        {
            WriteNum=Event_Num;  
            BeginAddr=0;
        }
        
        if(WriteNum)
        {
                
           for(uni=0;uni<WriteNum;uni++)  
           {
               //------ begin time ------//
		           for(unc=0;unc<=5;unc++)
	                Co.b[400+unc]=*((unsigned char *)Event_Data+16*((BeginAddr+uni)%10)+5-unc);
	             //------ end time ------//
	             for(unc=0;unc<=5;unc++)
	                Co.b[406+unc]=*((unsigned char *)Event_Data+16*((BeginAddr+uni)%10)+11-unc);
	             //------ begin curr ------//
	             //WRLC256(POWERDOWNSAVEMAXCURR_ROM,&Co.b[412],4,3,1);
	             //------ begin curr ------//
	             if(Meter_Parameter.parameter1.MeterMode[2].bit.b0)
	             	{
	             	 curr_temp = *((unsigned long *)(Event_Data+16*((BeginAddr+uni)%10)+12));//ganjp 20090326 
	             //--------ganjp 20090326-----------------
	             if(curr_temp == 0)
	             *((unsigned long *)&Co.b[412])=0xFFFFFFFF;
			else
			*((unsigned long *)&Co.b[412])=curr_temp;
	             	}
			else
			{
			//------ begin curr ------//
	             *((unsigned long *)&Co.b[412])=0xFFFFFFFF;
	             //------ begin curr ------//
			}
			//--------ganjp 20090326-----------------
	             //391-401 3 phase lost voltage
	             if(Event_Power_Net_Pointer.Phase3LostVolt_P<10)
	             	Event_Power_Net_Pointer.Phase3LostVolt_P++;
	             else
	             	Event_Power_Net_Pointer.Phase3LostVolt_P=0;
	             tempuni=391L+Event_Power_Net_Pointer.Phase3LostVolt_P;
		           FeedWatchdog();
	             Write_File(tempuni,0,16,&Co.b[400]);
	             FeedWatchdog();
                //Event_Power_Net_Pointer.TotalLostVoltage_P++;
                //if(Event_Power_Net_Pointer.TotalLostVoltage_P>10)
                //   Event_Power_Net_Pointer.TotalLostVoltage_P=0;
                //WRLC256(TOTALLOSTVOLTAGE_ROM+Event_Power_Net_Pointer.TotalLostVoltage_P*10,(unsigned char *)Event_Data+10*((BeginAddr+uni)%10),10,2,0);      
           }   
           //Event_Power_Net_Timeticks.TotalLostVoltage_Times_Ticks+=(Event_Time);
           Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks+=Event_Time;  //add by pc 081208
           
           WRLC256(PHASE3LOSTVOLT_P_ROM,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,1,0,0);
           WRLC256(PHASE3LOSTVOLT_TIMES_ROM,(unsigned char *)&Event_Power_Net_Times.Phase3LostVolt_Times,4,0,0);
           WRLC256(PHASE3LOSTVOLT_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,4,0,0);
           FeedWatchdog();  //change by pc 081208
           //WRLC256(EVENT_POWER_NET_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks,sizeof(struct EVENT_POWER_NET_TIMETICKS),3,0);   
           //WRLC256(EVENT_POWER_NET_POINTER_ROM,(unsigned char *)&Event_Power_Net_Pointer,sizeof(struct EVENT_POWER_NET_POINTER),3,0);
	   //WRLC256(EVENT_POWER_NET_TIMES_ROM,(unsigned char *)&Event_Power_Net_Times,sizeof(struct EVENT_POWER_NET_TIMES),3,0);
	}
	
	
}
#endif
/********************************************************
*     1. weed output dog                                *
*     2. when wdi is float wd is invalid                *
*********************************************************/ 
void	FeedWatchdog(void)
{
	if(!IntoPowerDownFlag)/*"低功耗下不喂狗"*/
		WDI=~WDI;
}
/********************************************************
*     1. power up check power down                      *
*     2.                                                *
*********************************************************/
void CheckPowerDown(void)
{
   if(!IntoPowerDownFlag)/*"低功耗下不需检测是否掉电"*/
   {
   	if(!V_D)
	{
	    Delay(5);   
	    if(!V_D)
	    {	
	        asm(" int #31"); /*"进低功耗"*/
	    }
	}
   }	
}

void Measure(void)
{
  //////TDK6515//////
  Check_If_Writting_Pulse_Constant_To_Card();
  Voltage_Phase_Deal();
  Energy_Accumulation_Unit_10Wh();	         //Accumulating Energy,resolution limiting=0.01kW.h
//  Output_On_3_In_1_Terminal_Reset();
  //////TDK6515//////
}


/*" 开盖检测，每妙调用一次，60妙内只准记一次事件记录"*/
void OpenCoverCheck(void)
{        
        OpenBoxCoverEvent_Check();        
}


///*" 上电加掉电数据，过零，费率变化时，强制备份；每10分钟备份电量"*/
///*" ErrEnergyNumber，所有数据出错时加1，大于5时，强制备份内卡"*/
///*" Err_Back_Energy_Num，备份数据读写出错，大于10时，强制备份内卡"*/
///*" BK_Energy_Addr, 为0，写0内卡，为1，写1内卡"*/
///*" This_Month_Data.Energy_Record.csadd， 备份内卡的次序 "*/
//void BackupDataToEeprom(void)
//{
//       
//	//unsigned char i=0;
//	//unsigned int datad=0;
//	//unsigned int uni=0;
//	//unsigned char cs=0;
//	unsigned char bkep;
//	
//	
//        if(BackUpEnergyToRam())  /*"检查内存数据是否正确"*/
//        { 
//              if(WriteEE_Or_F)
//              {
//              	  WriteEE_Or_F=0;
//              	  WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
//                  FeedWatchdog();  
//              }
//              else
//              {
//                    /*if(!BK_Energy_Addr)
//                    {
//                       This_Month_Data.Energy_Record.csadd++;
//                       
//                       WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),3,0);
//                       FeedWatchdog();  
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[0],0);
//                       FeedWatchdog();  
//                       //WRLC256(MINUTE_COPY_ENERGY_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[0],0);
//                       //FeedWatchdog();  
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&Co,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[0],1);
//                       FeedWatchdog();  
//                       
//                       
//                    }
//                    else
//                    {
//                       This_Month_Data.Energy_Record.csadd++;
//                       
//                       WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),3,0);
//                       FeedWatchdog();  
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[1],0);
//                       FeedWatchdog();  
//                       //WRLC256(MINUTE_COPY_ENERGY_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[1],0);
//                       //FeedWatchdog();  
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&Co,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[1],1);
//                       FeedWatchdog();  
//                    }*/
//                    //modify by zlp
//                    if(!BK_Energy_Addr)
//                    	{
//                    	     bkep=0;
//                    	}
//		       else
//		       {
//		            bkep=1;
//		       }
////			This_Month_Data.Energy_Record.csadd++;
//                       
//                       WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
//                       FeedWatchdog();  
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
//                       FeedWatchdog();  
//                       //WRLC256(MINUTE_COPY_ENERGY_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[0],0);
//                       //FeedWatchdog();  
//                       /*
//                       WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&Co,sizeof(struct ENERGY_RECORD),WriteWhitchEeprom[bkep],1);
//                       FeedWatchdog();      
//                    
//                    datad=sizeof(struct ENERGY_RECORD);
//                    cs=0xff;
//                    for(uni=0;uni<datad;uni++)
//                    {
//                       if(Co.b[uni]!=*((unsigned char *)&This_Month_Data+uni))
//                       {
//                           cs=0;
//                           break;
//                       }
//                    }
//                    if(cs)
//                    {
//                       BK_Energy_Addr=~BK_Energy_Addr;
//                       Err_Back_Energy_Num=0;
//                    }
//                    else 
//                    {
//                       Err_Back_Energy_Num++;
//                       if(Err_Back_Energy_Num>=10)
//                         BK_Energy_Addr=~BK_Energy_Addr; 
//                    } 
//                    *///change by zlp for:Err_Back_Energy_Num no be used by other place
//                    BK_Energy_Addr=~BK_Energy_Addr;
//                    ErrEnergyNumber=0;
//              }
//         Write_TO_Cal_PowerDown_Energy_add(0);
//        }
//
//}


/*"============================================================"*/
/*"函数名：Bill_New"*/
/*"用途：结算主函数"*/
/*"参数：无"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
void Bill_New(void)
{
    unsigned char num;	
    
    if (YEAR_BILL_FLAG) {
        if (is_year_bill_date(&softdate)) {
            Pre_Bill(&MainSoftDate.Year);
		Check_Energy_main(1);
        }
    } 

    for(num=0;num<3;num++) {
        if((Meter_Parameter.parameter1.AutoBillDayHour[num].Day==softdate.Day)
            &&(Meter_Parameter.parameter1.AutoBillDayHour[num].Hour==softdate.Hour)
            &&(softdate.Min==0)) 
            {
		if (num==0 )		//payment
		  	{
		  	if (YEAR_BILL_FLAG)
		 	 	Pre_Moneth_Updata();
			else
	         		Pre_Bill(&MainSoftDate.Year);
		  	}     	    
            Retort_New(num,(unsigned char *)&softdate);
            break;
        }
    }   
}
/*"============================================================"*/
/*"函数名：Check_Billdate_Validity"*/
/*"用途：检查结算日期有效函数"*/
/*"参数：无"*/
/*"返回：sort=0:有效结算日数目，有效结算日序号
sort=1:是否可以设置"*/
/*"版本：1.00"*/
/*"============================================================"*/
unsigned char Check_Billdate_Validity(unsigned char* date,unsigned char number)
{
    unsigned char num,add,billdata;   

    /*"默认第一结算日为有效"*/ 
    add=1;	
    billdata=0x07;
    for(num=2;num>0;num--)    
    {          
	    if((Meter_Parameter.parameter1.AutoBillDayHour[num].Day==0x99)&&(Meter_Parameter.parameter1.AutoBillDayHour[num].Hour==0x99))
	    {
            billdata&=~(0x01<<num);
        }
        else
        {
            add++;               
        }
    }

    billdata|=(add<<4);
    if(number==0xff)   
          return billdata; 
            
    return 0xff;
}
/*"费率变化时，强制备份数据"*/
void FindTriff(void)
{
        int2ic &= 0xf8;
        if(OLD_TRAFF_RATE!=TRAFF_RATE)
        {
           ErrEnergyNumber=7;	
         //  BackupDataToEeprom();
		 Check_Energy_main(1);
           OLD_TRAFF_RATE=TRAFF_RATE;
        }
        int2ic |= 0x01;
}
/*"内存数据检查"*/
/*"result＝0，不存内卡"*/
//unsigned char  BackUpEnergyToRam(void)//modify by zlp
//{
//
//   unsigned char result=0;
//   unsigned char flag=1;
//    result=EnergyAutoRectifyLevel1();
//    RailEnergyValidity();
//   if(result==0xff)//all error
//   {
//       flag=0;
//   }
//   return flag;
//}

/*"监控程序"*/
void Monitor_Program(void)
{
       if(Time500flag)
       {
          /// Flash_Led_Pannel();///king chen mark 121214
           ///if(!(Meter_Parameter.parameter1.MeterMode[1].byte&0x30))
              Output_On_3_In_1_Terminal_Set(7);            /*"辅助端子根据模式字和电表当前状态输出报警"*/
           //Check_If_Reset_Terminal_Alarm();
           Time500flag=0;
       } 
       
       if(OneSecond_Event)
       {
           OneSecond_Event=0;
            
           if(CompareBytes((unsigned char *)&Other_Data.LastJusttime,(unsigned char *)&softdate,3)!=0)
           {
             Other_Data.LastJusttime=softdate;
             Other_Data.JusttimesAdd=0;					
			       WRLC256(LASTJUSTTIME_ROM,(unsigned char *)&Other_Data.LastJusttime,8,0,0);
		   }

           Check_Event_Show_Data(0);

       }
        
       if(OneMinuteThirtS)  //30s 500ms
       {
           if(CheckRamTime()) 
           {
              ReadRTC();	
           }
           OneMinuteThirtS=0; 
       }       
       
      if(ThirtydMinute)         //5-15-25....m 20s 500ms 
      {
         int2ic &= 0xf8;      
         CheckEeprom();   
         int2ic |= 0x01;
         int2ic &= 0xf8;
         //BackupDataToEeprom();
			   Check_Energy_main(1);
         if(0xff==O1ther_Meter_Parameter.WorkRoomState)
         WRLC256(WORKROOM_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoom_RunTime,4,0,0);///king chen add 130322
         int2ic |= 0x01;
         ThirtydMinute=0;
         TenMinute=0;
      }
      
      if(TenMinute)         //5-15-25....m 20s 500ms 
      {
         int2ic &= 0xf8;   
         CheckEeprom();   
         int2ic |= 0x01;  
         TenMinute=0;
			   int2ic &= 0xf8;
			   Check_Event_Show_Data(0xff);
         int2ic |= 0x01;
      }
              
       int2ic &= 0xf8;
       CheckEnergyPassZero();
       int2ic |= 0x01;
       
    if(TimeUPLimit())
	  ResetTime();	
       
}

#if 0
//LDH20060711
void Light_Back_Led(void)	/*"只有在三相中的最高电压大于75％Un时才点亮背光"*/
{		    
		    if((VoltageGreaterThanThreshold_Flag==1)||(auxiliary_power_flag==1))     /*"最大的相电压是否大于门槛的标志"*/	
		    	{
        		    BACK_LIGHT_ON=1;
        		    Light_Back_Time=GetNowTime();
        	    }
        	else
        	        BACK_LIGHT_ON=0;
}


void Close_Back_Light(void)
{
       unsigned long Light_Back_time_temp;
       
       if(BACK_LIGHT_ON)
        {   
            if(Light_Back_Up_Flag==0xff)
                Light_Back_time_temp=2l*1000l*Meter_Parameter.parameter1.DisplayNumber*Meter_Parameter.parameter1.CycleDisplayTime;
            else if(Light_Back_Up_Flag==0x55)		//XN
                Light_Back_time_temp=0xffffffff;
            else if(Light_Back_Up_Flag==0xaa)
                Light_Back_time_temp=0;
            else if(Light_Back_Up_Flag==0x99)
		  Light_Back_time_temp=Meter_Parameter.parameter2.ShowNoKeyRetTime*1000L ;///king chen add 130205			
            else
                Light_Back_time_temp=60000;
            
             if((Light_Back_Up_Flag!=0x11)&&(!GetTimeCount(Light_Back_Time,Light_Back_time_temp))
             &&(Displayfinish_flag==1)&&(light_backled_flag==0))
            {
                BACK_LIGHT_ON=0;
                Light_Back_Up_Flag=0;
              //LDH20060711
             }
           ///if((VoltageGreaterThanThreshold_Flag==0)&&(auxiliary_power_flag==0))     /*"最大的相电压是否大于门槛的标志"*/
            /// if(closebacklight_flag==0xff)///king chen mark 130304
		///   BACK_LIGHT_ON=0;
              //LDH20060711
        }
}
#endif

/***type  ****/
//#define FOR_TRIFF_DATE             0x01        
//#define FOR_DAILYSLOT_DATE         0x02
void CheckChange(unsigned char kind,unsigned char type )
{
	 double long time;
	 struct DATEANDTIME_DEF            temp_date;
	 struct SWITCH_ITEM   *switchPtr;
	 unsigned char i;
	 unsigned char num,MAX_NUMBER_FREEZE;
	 unsigned int Addr;
	 unsigned char IsNeedChange=0;//init for safe
	 unsigned int freezefilename;
	 struct DATEANDTIME_DEF  temp_date1;
	 
	 if(type==FOR_TRIFF_DATE)
	 {
	    switchPtr=&Meter_Parameter.parameter1.TriffSwitch;
		  num=2;
		  MAX_NUMBER_FREEZE=MAX_NUMBER_FREEZE_TRIFF_CHANGE;
		  Addr=TRIFFSWITCH_ROM;
      freezefilename=FREEZE_TRIFF_CHANGE_SORT_START_FILE;
	 }
	 else if(type==FOR_DAILYSLOT_DATE)
	 {
	    switchPtr=&Meter_Parameter.parameter1.DailySlotSwitch;
		  num=3;
		  MAX_NUMBER_FREEZE=MAX_NUMBER_FREEZE_DAILYSLOT_CHANGE;
		  Addr=DAILYSLOTSWITCH_ROM;
		  freezefilename=FREEZE_DAILYSLOT_CHANGE_START_FILE;
	 }
	 temp_date=softdate;
	 temp_date.Sec=switchPtr->SwitchDate.Sec; 
	 
	 temp_date1=switchPtr->SwitchDate;
	 temp_date1.Sec=0;
	 
	 if((switchPtr->SwitchDate.Month!=0x00)&&(switchPtr->SwitchDate.Month!=0x99)&&(CheckTime((unsigned char *)&temp_date1)))
	 {	 
	    if(CompareBytes((unsigned char *)&temp_date,(unsigned char *)&(switchPtr->SwitchDate),5)>=0)
       	 IsNeedChange=1;
	 }
	 
	 if(IsNeedChange)
	 {
	      if((switchPtr->SwitchDate.Month!=0x99)&&(switchPtr->SwitchDate.Month!=0x00))
	     	{
	     	   if(!switchPtr->WhitchSlotIsNow)
				     switchPtr->WhitchSlotIsNow=1;
		       else 
		         switchPtr->WhitchSlotIsNow=0;
		       
		       for(i=0;i<7;i++)
	         {
	           *((unsigned char *)&switchPtr->SwitchDate.Year+i)=0x00; /*"切换后，必须从新设置时间才能下次切换；"*/
	         }        
			
		       ClearEvent_EventBegin((unsigned char *)&(switchPtr->FreezeData_addr),freezefilename);/*"冻结清零判断处理"*/
			     FreezeDateProgram(freezefilename+(switchPtr->FreezeData_addr),1, (unsigned char *)&softdate);///king chen modify 130609
		       switchPtr->FreezeData_addr=(switchPtr->FreezeData_addr+1)%MAX_NUMBER_FREEZE;
	      }
		    else
		    {
			     switchPtr->WhitchSlotIsNow=0;
			  }
			      
		    WRLC256(Addr,(unsigned char *)switchPtr,sizeof(struct SWITCH_ITEM),0,0);//write parameter	
	      Set_Meter_para_Deal(Addr);
	}
	 
}



/*"============================================================"*/
/*"函数名：CheckEnergyPassZero"*/
/*"用途：电量翻转处理；"*/
/*"参数：无"*/
/*"返回：无"*/
/*"作者：lxw 版本：1.00"*/
/*"trend 2008-12-6 9:34:47 新645时修改 版本V1.10"*/
/*"============================================================"*/
void CheckEnergyPassZero(void)
{
	unsigned int uni;
	unsigned char res=0;
                      
	for(uni=0;uni<6*MAXTRIFF+3*6;uni++)
	{
		if((*((unsigned long *)&This_Month_Data+uni))>Cal_EnergyLimit())
		{
			p3_2=1;
			EnergyPassZeroRecord();  //add by pc 081214               
		  *((unsigned long *)&This_Month_Data+uni)=0;
		  res=0xff;
		  /*"如果是总电量，记录翻转次数 tren 2008-12-6 9:31:48"*/
		  if((uni<6*MAXTRIFF)&&((uni%MAXTRIFF)==0))
		  	This_Month_Data.Energy_Record.EnergyPassMAXTimes[uni/MAXTRIFF]++;
		}
	}	
		
	if(res==0xff)
	{
		ErrEnergyNumber=7;	/*"强制存内卡"*/
		This_Month_Data.Energy_Record.crc_cal = CRC((unsigned char*)&This_Month_Data,
	                                               sizeof(struct ENERGY_RECORD) - 2);
		//BackupDataToEeprom();
		Check_Energy_main(1);
  }
   
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CheckState(void)
{
        //state1
        if(Meter_States.Meter_Flag.bit.Battery3_Err || Meter_States.Meter_Flag.bit.Battery1_Err)
           Meter_States.Meter_Status1.bit.Battery_Status=1;
        else  Meter_States.Meter_Status1.bit.Battery_Status=0;
        
        //state3
        if(Event_Power_Net_Flag.bit.VoltageReserve)
           Meter_States.Meter_Status3.bit.VoltagePhaseRevers=1;
        else  Meter_States.Meter_Status3.bit.VoltagePhaseRevers=0;
        
        if(Event_Power_Net_Flag.bit.LostCurrent_A )
           Meter_States.Meter_Status3.bit.LossCurrent_A=1;
        else  Meter_States.Meter_Status3.bit.LossCurrent_A=0;
        
        if(Event_Power_Net_Flag.bit.LostCurrent_B)
           Meter_States.Meter_Status3.bit.LossCurrent_B=1;
        else  Meter_States.Meter_Status3.bit.LossCurrent_B=0;
        
        if(Event_Power_Net_Flag.bit.LostCurrent_C)
           Meter_States.Meter_Status3.bit.LossCurrent_C=1;
        else  Meter_States.Meter_Status3.bit.LossCurrent_C=0;
        
        //state4
        if(Event_Power_Net_Flag.bit.OverPowerAlarm)
           Meter_States.Meter_Status4.byte|=1;
        else  Meter_States.Meter_Status4.byte&=0xfe;
        
        if(SWITCH_FACT_DEFINE)	//payment	//SWITCH_TOGGLE
           Meter_States.Meter_Status4.byte|=2;
        else  Meter_States.Meter_Status4.byte&=0xfd;
        
        if(Meter_States.Meter_Flag.bit.Battery1_Err)
           Meter_States.Meter_Status4.bit.LowClockBattery=1;
        else  Meter_States.Meter_Status4.bit.LowClockBattery=0;
        
        if(Meter_States.Meter_Flag.bit.Battery3_Err)
           Meter_States.Meter_Status4.bit.LowBattery=1;
        else  Meter_States.Meter_Status4.bit.LowBattery=0;
        
        //PowerNet_Status
        if(Meter_Parameter.parameter1.LocalFunctionMode.bit.b0==1)
        {
         if(Event_Power_Net_Flag.bit.LostVoltage_A)
           Meter_States.PowerNet_Status.bit.BreakPhase_A=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_A=0;
        }
        else
        {
        if(Event_Power_Net_Flag.bit.BreakPhase_A)
           Meter_States.PowerNet_Status.bit.BreakPhase_A=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_A=0;
        }

        if(Meter_Parameter.parameter1.LocalFunctionMode.bit.b0==1)
        {
         if(Event_Power_Net_Flag.bit.LostVoltage_B)
           Meter_States.PowerNet_Status.bit.BreakPhase_B=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_B=0;
        }
        else
        {
        if(Event_Power_Net_Flag.bit.BreakPhase_B)
           Meter_States.PowerNet_Status.bit.BreakPhase_B=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_B=0;
        }

        if(Meter_Parameter.parameter1.LocalFunctionMode.bit.b0==1)
        {
         if(Event_Power_Net_Flag.bit.LostVoltage_C)
           Meter_States.PowerNet_Status.bit.BreakPhase_C=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_C=0;
        }
        else
        {
        if(Event_Power_Net_Flag.bit.BreakPhase_C)
           Meter_States.PowerNet_Status.bit.BreakPhase_C=1;
        else  Meter_States.PowerNet_Status.bit.BreakPhase_C=0;
        }
        
        if(Event_Power_Net_Flag.bit.OverVoltage_A)
           Meter_States.PowerNet_Status.bit.OverVoltage_A=1;
        else  Meter_States.PowerNet_Status.bit.OverVoltage_A=0;
        
        if(Event_Power_Net_Flag.bit.OverVoltage_B)
           Meter_States.PowerNet_Status.bit.OverVoltage_B=1;
        else  Meter_States.PowerNet_Status.bit.OverVoltage_B=0;
        
        if(Event_Power_Net_Flag.bit.OverVoltage_C)
           Meter_States.PowerNet_Status.bit.OverVoltage_C=1;
        else  Meter_States.PowerNet_Status.bit.OverVoltage_C=0;
        
        
        //Week_Status
        Meter_States.Week_Status.byte=softdate.Week;
        

        //Comm_Rate
        Meter_States.Comm_Rate[0].byte=Meter_Parameter.parameter1.Commrate[0].byte;
        Meter_States.Comm_Rate[1].byte=Meter_Parameter.parameter1.Commrate[1].byte;
        Meter_States.Comm_Rate[2].byte=Meter_Parameter.parameter1.Commrate[2].byte;
        
        
       //err code 
       if(Meter_States.Meter_Flag.bit.Eeprom_Err1)
          Meter_States.Err_Infor.bit.Eeprom_Err=1;
       else  Meter_States.Err_Infor.bit.Eeprom_Err=0;
       
       if(Meter_States.Meter_Flag.bit.Battery1_Err)
          Meter_States.Err_Infor.bit.BatteryClK_Err=1;  
       else Meter_States.Err_Infor.bit.BatteryClK_Err=0;      
       
       if(Meter_States.Meter_Flag.bit.Battery3_Err)
          Meter_States.Err_Infor.bit.BatteryDIS_Err=1;  
       else Meter_States.Err_Infor.bit.BatteryDIS_Err=0;       
       
       if(Event_Power_Net_Flag.bit.VoltageReserve)   
          Meter_States.Err_Infor.bit.VoltageReserve=1;  
       else Meter_States.Err_Infor.bit.VoltageReserve=0;       
       //mw modified 2009-10-09
       if(Event_Power_Net_Flag.bit.LostVoltage_A ||Event_Power_Net_Flag.bit.LostVoltage_B ||Event_Power_Net_Flag.bit.LostVoltage_C )
          Meter_States.Err_Infor.bit.LossVoltage=1; 
       else  Meter_States.Err_Infor.bit.LossVoltage=0;  
       
       if(Event_Power_Net_Flag.bit.OverVoltage_A ||Event_Power_Net_Flag.bit.OverVoltage_B ||Event_Power_Net_Flag.bit.OverVoltage_C )
          Meter_States.Err_Infor.bit.OverVoltage=1; 
       else  Meter_States.Err_Infor.bit.OverVoltage=0;  
       
       //mw modified 2009-10-09
       if(Event_Power_Net_Flag.bit.LostCurrent_A ||Event_Power_Net_Flag.bit.LostCurrent_B ||Event_Power_Net_Flag.bit.LostCurrent_C )
          Meter_States.Err_Infor.bit.LossCurrent=1;   
       else Meter_States.Err_Infor.bit.LossCurrent=0;     
       
       if(Event_Power_Net_Flag.bit.BreakPhase_A ||Event_Power_Net_Flag.bit.BreakPhase_B||Event_Power_Net_Flag.bit.BreakPhase_C)
          Meter_States.Err_Infor.bit.BreakPhase=1;   
       else Meter_States.Err_Infor.bit.BreakPhase=0;     
       
       
       if(Event_Power_Net_Flag.bit.OverPowerAlarm)
          Meter_States.Err_Infor.bit.OverPower=1;
       else  Meter_States.Err_Infor.bit.OverPower=0; 
        
       if(Meter_States.Meter_Flag.bit.Rtc_Err1)
          Meter_States.Err_Infor.bit.Rtc_Err=1;    
       else  Meter_States.Err_Infor.bit.Rtc_Err=0;       
          
          
       
       
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"参数纠错，主循环调用"*/
void Meter_Para_Check(void)
{
	unsigned char uni = 0;
	if(IntoPowerDownFlag==0)     /*"正常上电执行，低功耗不执行"*/
	{
	 ///if(Meter_Parameter.parameter2.EnergyPoint!=2 && Meter_Parameter.parameter2.EnergyPoint!=3)
	 if(Meter_Parameter.parameter2.EnergyPoint > 3)
	    Meter_Parameter.parameter2.EnergyPoint=2;  
	 ///if(Meter_Parameter.parameter2.PowerPoint!=2 && Meter_Parameter.parameter2.PowerPoint!=3 && Meter_Parameter.parameter2.PowerPoint!=4)
	  if(Meter_Parameter.parameter2.PowerPoint > MAXDAUTOVALUE)
	    Meter_Parameter.parameter2.PowerPoint=4; 
//	 for(uni = 0; uni < 3; uni++)
//	 {
//	 	if(Meter_Parameter.parameter1.Commrate[uni].bit.B1200 != 1
//	 	 &&Meter_Parameter.parameter1.Commrate[uni].bit.B2400 != 1
//	 	 &&Meter_Parameter.parameter1.Commrate[uni].bit.B4800 != 1
//	 	 &&Meter_Parameter.parameter1.Commrate[uni].bit.B9600 != 1) 
//	 	 {
//	 	 	Meter_Parameter.parameter1.Commrate[uni].byte=0; 	
//	    Meter_Parameter.parameter1.Commrate[uni].bit.B2400=1;
//	 	 }
//	 }
	 
	}
}

//
/********************************************************/ 
/*"新645 运行 状态字，主循环调用"*/
//fuxf 081114  add
void CheckState_New645(void)
{
        //state1
        if(Meter_States.Meter_Flag.bit.Battery1_Err)
           NEW645Meter_States.Meter_Status1.bit.Battery1_Status=1;
        else  NEW645Meter_States.Meter_Status1.bit.Battery1_Status=0;
         if(Meter_States.Meter_Flag.bit.Battery3_Err)
           NEW645Meter_States.Meter_Status1.bit.Battery2_Status=1;
        else  NEW645Meter_States.Meter_Status1.bit.Battery2_Status=0;

        NEW645Meter_States.Meter_Status1.bit.CtrCircleErr=SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE;
        
        NEW645Meter_States.Meter_Status1.bit.EsamErr=0;
        if(ESAM_ERR_DEFINE)	// && MACRO_ESAM_FLAG)
		       NEW645Meter_States.Meter_Status1.bit.EsamErr=1;
		       
		    NEW645Meter_States.Meter_Status1.bit.ProgrammeErr=0;
		    
		    NEW645Meter_States.Meter_Status1.bit.EepromErr=Meter_States.Err_Infor.bit.Eeprom_Err;
		    
		    NEW645Meter_States.Meter_Status1.bit.ClockErr=Meter_States.Err_Infor.bit.Rtc_Err;
               
        //state7
        if(Event_Power_Net_Flag.bit.VoltageReserve)
           NEW645Meter_States.Meter_Status7.bit.VoltagePhaseRevers=1;
        else  NEW645Meter_States.Meter_Status7.bit.VoltagePhaseRevers=0;
		    
        NEW645Meter_States.Meter_Status7.bit.OverDemand=(Event_Power_Net_Flag.bit.Over1RDemand|Event_Power_Net_Flag.bit.Over2RDemand
        |Event_Power_Net_Flag.bit.Over3RDemand|Event_Power_Net_Flag.bit.Over4RDemand
        |Event_Power_Net_Flag.bit.OverPaADemand|Event_Power_Net_Flag.bit.OverNeADemand);      

        //  if(IntoPowerDownFlag)
        //   NEW645Meter_States.Meter_Status7.bit.PowerDown=1;
        //else  NEW645Meter_States.Meter_Status7.bit.PowerDown=0; 
        NEW645Meter_States.Meter_Status7.bit.PowerDown=Event_Power_Net_Flag.bit.PowerDownEvent;

		if(Event_Power_Net_Flag.bit.VoltImBalanceEvent)
           NEW645Meter_States.Meter_Status7.bit.VoltageImbalance=1;
        else  NEW645Meter_States.Meter_Status7.bit.VoltageImbalance=0;

      if(Event_Power_Net_Flag.bit.CurrImBalanceEvent)
           NEW645Meter_States.Meter_Status7.bit.CurrentImbalance=1;
        else  NEW645Meter_States.Meter_Status7.bit.CurrentImbalance=0;
          //if()
          // NEW645Meter_States.Meter_Status7.bit.AuxiliaryPower=1;
        //else  NEW645Meter_States.Meter_Status7.bit.AuxiliaryPower=0; 	

		  
        //state3
        if(Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow==0)
           NEW645Meter_States.Meter_Status3.bit.WhitchSlotIsNow=0;
        else  NEW645Meter_States.Meter_Status3.bit.WhitchSlotIsNow=1;

	      if(Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow==0)
           NEW645Meter_States.Meter_Status3.bit.WhitchDialySlotIsNow=0;
        else  NEW645Meter_States.Meter_Status3.bit.WhitchDialySlotIsNow=1;
				
	if(!IntoPowerDownFlag)  	
	{
        	if(auxiliary_power_flag==0)
        	{
           	NEW645Meter_States.Meter_Status3.bit.Power_Mode1=0;
		NEW645Meter_States.Meter_Status3.bit.Power_Mode2=0;
        	}
        	else  if(auxiliary_power_flag==1)
        	{
           	NEW645Meter_States.Meter_Status3.bit.Power_Mode1=1;
		NEW645Meter_States.Meter_Status3.bit.Power_Mode2=0;
        	}
	}
	else if(IntoPowerDownFlag)
	{
           	NEW645Meter_States.Meter_Status3.bit.Power_Mode1=0;
		NEW645Meter_States.Meter_Status3.bit.Power_Mode2=1;	
	}
	
        //NEW645Meter_States.Meter_Status3.bit.Program_Allow=0;
        //if(Show_flag.bit.keystoke==1)
        //   NEW645Meter_States.Meter_Status3.bit.Program_Allow=1;
        //else  NEW645Meter_States.Meter_Status3.bit.Program_Allow=0;	

if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))	//payment
{
       if(SWITCH_TOGGLE)		//payment
          NEW645Meter_States.Meter_Status3.bit.Relay_Status=1;
       else  NEW645Meter_States.Meter_Status3.bit.Relay_Status=0;
}

        //state4
		
        if(Event_Power_Net_Flag.bit.BreakPhase_A)
           NEW645Meter_States.Meter_Status4.bit.BreakPhase=1;
        else  NEW645Meter_States.Meter_Status4.bit.BreakPhase=0;
        
        if(Event_Power_Net_Flag.bit.BreakPhase_B)
           NEW645Meter_States.Meter_Status5.bit.BreakPhase=1;
        else  NEW645Meter_States.Meter_Status5.bit.BreakPhase=0;
        
        if(Event_Power_Net_Flag.bit.BreakPhase_C)
           NEW645Meter_States.Meter_Status6.bit.BreakPhase=1;
        else  NEW645Meter_States.Meter_Status6.bit.BreakPhase=0;

        
        if(Event_Power_Net_Flag.bit.OverVoltage_A)
           NEW645Meter_States.Meter_Status4.bit.OverVoltage=1;
        else  NEW645Meter_States.Meter_Status4.bit.OverVoltage=0;
        
        if(Event_Power_Net_Flag.bit.OverVoltage_B)
           NEW645Meter_States.Meter_Status5.bit.OverVoltage=1;
        else  NEW645Meter_States.Meter_Status5.bit.OverVoltage=0;
        
        if(Event_Power_Net_Flag.bit.OverVoltage_C)
           NEW645Meter_States.Meter_Status6.bit.OverVoltage=1;
        else  NEW645Meter_States.Meter_Status6.bit.OverVoltage=0;
        
        //------  //add by pc 090721
        if(Event_Power_Net_Flag.bit.VoltageDown_A)
           NEW645Meter_States.Meter_Status4.bit.FailVoltage=1;
        else  NEW645Meter_States.Meter_Status4.bit.FailVoltage=0;
        
        if(Event_Power_Net_Flag.bit.VoltageDown_B)
           NEW645Meter_States.Meter_Status5.bit.FailVoltage=1;
        else  NEW645Meter_States.Meter_Status5.bit.FailVoltage=0;
        
        if(Event_Power_Net_Flag.bit.VoltageDown_C)
           NEW645Meter_States.Meter_Status6.bit.FailVoltage=1;
        else  NEW645Meter_States.Meter_Status6.bit.FailVoltage=0;
        
        if(Event_Power_Net_Flag.bit.OverCurrent_A)
           NEW645Meter_States.Meter_Status4.bit.OverCurrent=1;
        else  NEW645Meter_States.Meter_Status4.bit.OverCurrent=0;
        
        if(Event_Power_Net_Flag.bit.OverCurrent_B)
           NEW645Meter_States.Meter_Status5.bit.OverCurrent=1;
        else  NEW645Meter_States.Meter_Status5.bit.OverCurrent=0;
        
        if(Event_Power_Net_Flag.bit.OverCurrent_C)
           NEW645Meter_States.Meter_Status6.bit.OverCurrent=1;
        else  NEW645Meter_States.Meter_Status6.bit.OverCurrent=0;
        //------  //add by pc 090721
        //------  //add by pc 090817
        if(Event_Power_Net_Flag.bit.UpLoad_A)
           NEW645Meter_States.Meter_Status4.bit.OverLoad=1;
        else  NEW645Meter_States.Meter_Status4.bit.OverLoad=0;
        
        if(Event_Power_Net_Flag.bit.UpLoad_B)
           NEW645Meter_States.Meter_Status5.bit.OverLoad=1;
        else  NEW645Meter_States.Meter_Status5.bit.OverLoad=0;
        
        if(Event_Power_Net_Flag.bit.UpLoad_C)
           NEW645Meter_States.Meter_Status6.bit.OverLoad=1;
        else  NEW645Meter_States.Meter_Status6.bit.OverLoad=0;
        //------  //add by pc 090817
        
        if(Event_Power_Net_Flag.bit.LostCurrent_A )
           NEW645Meter_States.Meter_Status4.bit.LossCurrent=1;
        else  NEW645Meter_States.Meter_Status4.bit.LossCurrent=0;
        
        if(Event_Power_Net_Flag.bit.LostCurrent_B)
           NEW645Meter_States.Meter_Status5.bit.LossCurrent=1;
        else  NEW645Meter_States.Meter_Status5.bit.LossCurrent=0;
        
        if(Event_Power_Net_Flag.bit.LostCurrent_C )
           NEW645Meter_States.Meter_Status6.bit.LossCurrent=1;
        else  NEW645Meter_States.Meter_Status6.bit.LossCurrent=0;        
    
        if(Event_Power_Net_Flag.bit.LostVoltage_A)
           NEW645Meter_States.Meter_Status4.bit.LossVoltage=1;
        else  NEW645Meter_States.Meter_Status4.bit.LossVoltage=0;
        
        if(Event_Power_Net_Flag.bit.LostVoltage_B)
           NEW645Meter_States.Meter_Status5.bit.LossVoltage=1;
        else  NEW645Meter_States.Meter_Status5.bit.LossVoltage=0;
        
        if(Event_Power_Net_Flag.bit.LostVoltage_C)
           NEW645Meter_States.Meter_Status6.bit.LossVoltage=1;
        else  NEW645Meter_States.Meter_Status6.bit.LossVoltage=0;          
       
         if(Event_Power_Net_Flag.bit.PowerReverse_A)
           NEW645Meter_States.Meter_Status4.bit.TideWay=1;
        else  NEW645Meter_States.Meter_Status4.bit.TideWay=0;
        
        if(Event_Power_Net_Flag.bit.PowerReverse_B)
           NEW645Meter_States.Meter_Status5.bit.TideWay=1;
        else  NEW645Meter_States.Meter_Status5.bit.TideWay=0;
        
        if(Event_Power_Net_Flag.bit.PowerReverse_C)
           NEW645Meter_States.Meter_Status6.bit.TideWay=1;
        else  NEW645Meter_States.Meter_Status6.bit.TideWay=0; 

        if(Event_Power_Net_Flag.bit.CurrReverse)
           NEW645Meter_States.Meter_Status7.bit.CurrentPhaseReverse=1;
        else  NEW645Meter_States.Meter_Status7.bit.CurrentPhaseReverse=0;

        if(Event_Power_Net_Flag.bit.OverFactor)
           NEW645Meter_States.Meter_Status7.bit.OverFactor=1;
        else  NEW645Meter_States.Meter_Status7.bit.OverFactor=0;        
         if(Event_Power_Net_Flag.bit.FailCurrent_A)
           NEW645Meter_States.Meter_Status4.bit.BreakCurrent=1;
        else  NEW645Meter_States.Meter_Status4.bit.BreakCurrent=0;
        
        if(Event_Power_Net_Flag.bit.FailCurrent_B)
           NEW645Meter_States.Meter_Status5.bit.BreakCurrent=1;
        else  NEW645Meter_States.Meter_Status5.bit.BreakCurrent=0;
        
        if(Event_Power_Net_Flag.bit.FailCurrent_C)
           NEW645Meter_States.Meter_Status6.bit.BreakCurrent=1;
        else  NEW645Meter_States.Meter_Status6.bit.BreakCurrent=0; 
      
        if(Event_Power_Net_Flag.bit.CurrFarImB)
           NEW645Meter_States.Meter_Status7.bit.CurrentGraveImbalance=1;
        else  NEW645Meter_States.Meter_Status7.bit.CurrentGraveImbalance=0;
        
        NEW645Meter_States.Meter_Status7.bit.OpenBox=Event_Power_Net_Flag.bit.OpenBoxEvent;
        NEW645Meter_States.Meter_Status7.bit.OpenCover=Event_Power_Net_Flag.bit.OpenCoverEvent;

          if(Event_Power_Net_Flag.bit.OpenBoxEvent)
           NEW645Meter_States.OpenCoverStates.bit.b0=1;
        else             
           NEW645Meter_States.OpenCoverStates.bit.b0=0;

        if(Event_Power_Net_Flag.bit.OpenCoverEvent)
           NEW645Meter_States.OpenCoverStates.bit.b1=1;
        else             
           NEW645Meter_States.OpenCoverStates.bit.b1=0;
        
	   /*"单方向表有功电能方向改变"*/
	    if((Meter_States.Meter_Status1.bit.ActivePower_Direct!=0)&&(((Meter_Parameter.parameter1.MeterMode[0].byte)&0x40)!=0))
		      Err_Code.bit.ENERGY_DIRECT_CHANGE=1;
		else			
		      Err_Code.bit.ENERGY_DIRECT_CHANGE=0;
}
/********************************************************/ 

/*"============================================================"*/
/*"函数名：Cal_EnergyLimit"*/
/*"用途：电量翻转参数设置"*/
/*"参数：无"*/
/*"返回：无"*/
/*"作者：mw 版本：1.00"*/
/*"trend 2008-12-6 9:35:30 新645修改，版本V1.10"*/
/*"============================================================"*/

signed long Cal_EnergyLimit(void)
{
	return 999999999l;
}
/*"============================================================"*/
/*"函数名：Check_If_Clear_all"*/
/*"用途：检查是否在清电表的 时候掉电"*/
/*"参数：无"*/
/*"返回：无"*/
/*"//added by fxf	090106"*/
/*"============================================================"*/
void Check_If_Clear_all()
{
     unsigned int uni,flag=0,crctemp1=0,crctemp2=0;

     if((Other_Data.CommClearFlagCurrEE.Clear_All_Flag==0xff)&&(O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag==0xff))
	 {
            crctemp1=Crc16l((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag,5);
            crctemp2=Crc16l((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag,5);
            if((crctemp1==Other_Data.CommClearFlagCurrEE.Comm_Clear_Crc_Data)&&(crctemp2==O1ther_Meter_Parameter.CommClearFlagCurrFF.Comm_Clear_Crc_Data))
            {  
                 Clear_All_New(0xffffffff);		
            }
            flag=0xff;
     } 
     for(uni=0;uni<sizeof(struct COMMCLEARSTRDEF);uni++)
     {
         *((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag+uni)=0;
         *((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag+uni)=0;
     }
     Other_Data.CommClearFlagCurrEE.Comm_Clear_Crc_Data=Crc16l((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag,5);
     O1ther_Meter_Parameter.CommClearFlagCurrFF.Comm_Clear_Crc_Data=Crc16l((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag,5);
     if(flag==0xff)
     {
          WRLC256(COMMCLEARFLAGCURRFF_ROM,(unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF,sizeof(struct COMMCLEARSTRDEF),0,0);
	      FeedWatchdog();
          WRLC256(COMMCLEARFLAGCURREE_ROM,(unsigned char *)&Other_Data.CommClearFlagCurrEE,sizeof(struct COMMCLEARSTRDEF),0,0);
          CheckPowerDown();
     }

     for(uni=0;uni<3;uni++)
         Comm_Firrespon_SecDispos_Uart[uni]=0xff;

     return;     
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------------//
void ClearClockBatteryTime(void)
{	
	unsigned char i;
	if(IsChangeBattery())
	{
	     if(ClockBatteryClearCounter>=2)
	    {
	         Other_Data.BatteryWorkTime1=0;
	        WRLC256(BATTERYWORKTIME1_ROM,(unsigned char *)&Other_Data.BatteryWorkTime1,4,0,0);
	    }
	   for(i=0;i<8;i++)
	   {
	         ClockBatteryClear_Flag[i]=0;
	   }
	   ClockBatteryClearCounter=0;
	  TempClockBatteryClearCounter=0;	 	
	}
	
}
unsigned char IsChangeBattery(void)
{
    unsigned char i;
    unsigned char temp[8]= {0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0};
    for(i=0;i<8;i++)
   {
   	   if(ClockBatteryClear_Flag[i]!=temp[i])
	   	return 0;
   }
   return 1;
}           

//test ganjp 20100331
unsigned int CRC(unsigned char *startaddr, unsigned int len)
{
	unsigned int i=0;
	unsigned int result = 0;
	
	crcd = 0;
	crcmr = 0x00;
	
	for(i=0; i<len; i++)
	{
		crcin = *startaddr;
		startaddr++;
	}
	result=crcd+0x55aa;
	return result;	
}

/*"电表状态处理，计数"*/
void Meter_Staut_Check_And_Count(void)
{
	///unsigned int uni;
	if(!O1ther_Meter_Parameter.WorkRoomState)
	{
	if(IntoPowerDownFlag==0)  /*"正常上电执行，低功耗不执行"*/
	{
	if(!J1 )
	   {
	   	{
	   		Delay(5);
	   		if(!J1)
	   		{
	   		  workroom_cnt++;
	   		   if(workroom_cnt>1)
	   		   {
				workroom_cnt=0;
				O1ther_Meter_Parameter.WorkRoomState=0xff;
	   			O1ther_Meter_Parameter.WorkRoom_RunTime=0;
	   			////for(uni=0;uni<6;uni++)
	   			////   *((unsigned char *)&O1ther_Meter_Parameter.WorkRoomStateDate+uni)=0;
	   			WRLC256(WORKROOMSTATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoomState,1,0,0);
				WRLC256(WORKROOM_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoom_RunTime,4,0,0); 
	   		   }
	   		}
	   		else
	   		{
	   		   workroom_cnt=0;
	   		}
	   	}
	   }	
	else
	   {
   		workroom_cnt=0;
	   }
	}
      }
      else
      {
    	O1ther_Meter_Parameter.WorkRoom_RunTime++;
       if(O1ther_Meter_Parameter.WorkRoom_RunTime>WORKROOMSTATE_RUNTIME)
       	{
       	O1ther_Meter_Parameter.WorkRoom_RunTime=0;
		O1ther_Meter_Parameter.WorkRoomState=0x00;
		WRLC256(WORKROOMSTATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoomState,1,0,0);
		WRLC256(WORKROOM_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoom_RunTime,4,0,0); 
	   	}
      }
}
union EVENT_REPORT_STATUS  Event_Status;/*"当前事件状态，与真实事件状态保持同步"*/
union EVENT_REPORT_STATUS  Event_Report_Status;/*"事件主动上报状态，与上报状态保持同步，事件发生时置位,收到复位主动上报状态字命令后清零对应位"*/
///union EVENT_REPORT_STATUS  Event_Reported_Status;/*"已上报事件状态字，未上报时置0，上报后置1，事件结束后和上电初始化时置0"*/
unsigned char   Event_Report_flag;/*"需进行事件上报标志，0 不需要上报 0xff 有事件需要上报"*/
//unsigned char   open_cover_reported;/*"eventout已经主动上报开盖事件，开盖事件重新发生前不重复上报"*/
struct EVENT_REPORT_STATUS_TIMES Event_Report_Status_Times;/*"事件上报期间，事件发生的次数"*/
union EVENTSTATUS_FLAG EventStatus_flag;/*"事件上报中进行事件记录本身没有发生标识,使用该标志表示事件发生"*/
union EVENT_REPORT_STATUS  Event_Report_Status_Backup;/*"对当前检测到的事件主动上报状态进行备份，用于判断是否将当前主动上报状态字存EE"*/
union EVENT_REPORT_STATUS  Event_Report_Status_communication;/*"通信抄读主动上报状态字时,对当前主动上报状态字进行备份"*/
unsigned char   Event_Report_Iterate_flag;/*"主动上报状态字采用后续帧模式抄读后需清零"*/

/*"函数功能:根据当前事件状态，判断是否需要进行事件上报"*/
/*"输入参数: kind:0表示电表上电模式，1表示电表正常运行模式"*/
/*"输出参数:"*/
/*"调用说明:主循环中每秒调用，在事件判断函数之后调用"*/
void Event_Report_Status_Chk(unsigned char kind)
{
unsigned char i = 0;
union EVENT_REPORT_STATUS EventReportStatus;

/*"0"*/
Event_Status.bit.Switch_err = EventStatus_flag.bit.Switch_err;/*"内置继电器错误"*/ 
Event_Status.bit.ESAM_err = EventStatus_flag.bit.ESAM_err;
Event_Status.bit.Eeprom_init_err = 0;
Event_Status.bit.Clock_Battery_Volt_low =  Event_Power_Net_Flag.bit.ClockBatteryEvent;
Event_Status.bit.Code_err = 0;
Event_Status.bit.Memorizer_err = 0;

Event_Status.bit.Clock_err = EventStatus_flag.bit.Clock_err;/*"运行时钟乱"*/ 
///Event_Status.byte[0] &= Meter_Parameter.parameter1.EventReportMode.byte[0];
/*"1"*/
Event_Status.bit.LowPower_Battery_Volt_low = Event_Power_Net_Flag.bit.DisplayBatteryEvent;
Event_Status.bit.Overdraft = EventStatus_flag.bit.Overdraft;///(REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE |REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE |REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE) ;
Event_Status.bit.Open_Meter_Cover = (Event_Power_Net_Flag.bit.OpenCoverEvent |eventstatusinfo.bit.powerdownopencover) ;
Event_Status.bit.Open_Rail_Cover = (Event_Power_Net_Flag.bit.OpenBoxEvent |eventstatusinfo.bit.powerdownopenbox) ;
Event_Status.bit.ConstantMagnet_event = Event_Power_Net_Flag.bit.ConstantMagnet;
Event_Status.bit.PowerAbnormal_event = EventStatus_flag.bit.PowerAbnormal_event;/*"电源异常"*/
Event_Status.bit.Switch_off = EventStatus_flag.bit.Switch_off;
Event_Status.bit.Switch_on = EventStatus_flag.bit.Switch_on;
///Event_Status.byte[1] &= Meter_Parameter.parameter1.EventReportMode.byte[1];
/*"2"*/
Event_Status.bit.LostVolt_A = (Event_Power_Net_Flag.bit.LostVoltage_A );
Event_Status.bit.LowVolt_A = (Event_Power_Net_Flag.bit.VoltageDown_A);
Event_Status.bit.OverVolt_A = (Event_Power_Net_Flag.bit.OverVoltage_A);
Event_Status.bit.LossCurr_A = (Event_Power_Net_Flag.bit.LostCurrent_A);
Event_Status.bit.OverCurr_A = (Event_Power_Net_Flag.bit.OverCurrent_A);
Event_Status.bit.UpLoad_A = (Event_Power_Net_Flag.bit.UpLoad_A);
Event_Status.bit.PowerReserve_A = (Event_Power_Net_Flag.bit.PowerReverse_A);
Event_Status.bit.BreakPhase_A = (Event_Power_Net_Flag.bit.BreakPhase_A);
///Event_Status.byte[2] &= Meter_Parameter.parameter1.EventReportMode.byte[2];
/*"3"*/
Event_Status.bit.BreakCurr_A = (Event_Power_Net_Flag.bit.FailCurrent_A);
///Event_Status.byte[3] &= Meter_Parameter.parameter1.EventReportMode.byte[3];
/*"4"*/
Event_Status.bit.LostVolt_B = (Event_Power_Net_Flag.bit.LostVoltage_B);
Event_Status.bit.LowVolt_B = (Event_Power_Net_Flag.bit.VoltageDown_B);
Event_Status.bit.OverVolt_B = (Event_Power_Net_Flag.bit.OverVoltage_B);
Event_Status.bit.LossCurr_B = (Event_Power_Net_Flag.bit.LostCurrent_B);
Event_Status.bit.OverCurr_B = (Event_Power_Net_Flag.bit.OverCurrent_B);
Event_Status.bit.UpLoad_B = (Event_Power_Net_Flag.bit.UpLoad_B);
Event_Status.bit.PowerReserve_B = (Event_Power_Net_Flag.bit.PowerReverse_B);
Event_Status.bit.BreakPhase_B = (Event_Power_Net_Flag.bit.BreakPhase_B);
///Event_Status.byte[4] &= Meter_Parameter.parameter1.EventReportMode.byte[2];
/*"5"*/
Event_Status.bit.BreakCurr_B = (Event_Power_Net_Flag.bit.FailCurrent_B);
///Event_Status.byte[5] &= Meter_Parameter.parameter1.EventReportMode.byte[3];
/*"6"*/
Event_Status.bit.LostVolt_C = (Event_Power_Net_Flag.bit.LostVoltage_C);
Event_Status.bit.LowVolt_C = (Event_Power_Net_Flag.bit.VoltageDown_C);
Event_Status.bit.OverVolt_C = (Event_Power_Net_Flag.bit.OverVoltage_C);
Event_Status.bit.LossCurr_C = (Event_Power_Net_Flag.bit.LostCurrent_C);
Event_Status.bit.OverCurr_C = (Event_Power_Net_Flag.bit.OverCurrent_C);
Event_Status.bit.UpLoad_C = (Event_Power_Net_Flag.bit.UpLoad_C);
Event_Status.bit.PowerReserve_C = (Event_Power_Net_Flag.bit.PowerReverse_C);
Event_Status.bit.BreakPhase_C = (Event_Power_Net_Flag.bit.BreakPhase_C);
///Event_Status.byte[6] &= Meter_Parameter.parameter1.EventReportMode.byte[2];
/*"7"*/
Event_Status.bit.BreakCurr_C = (Event_Power_Net_Flag.bit.FailCurrent_C);
///Event_Status.byte[7] &= Meter_Parameter.parameter1.EventReportMode.byte[3];
/*"8"*/
Event_Status.bit.VoltReverse = (Event_Power_Net_Flag.bit.VoltageReserve);
Event_Status.bit.CurrReverse = (Event_Power_Net_Flag.bit.CurrReverse);
Event_Status.bit.VoltImbalance = (Event_Power_Net_Flag.bit.VoltImBalanceEvent);
Event_Status.bit.CurrImbalance = (Event_Power_Net_Flag.bit.CurrImBalanceEvent);
Event_Status.bit.auxiliaryPower_event = 0;///(EventStatus_flag.bit.auxiliaryPower_event);
Event_Status.bit.PowerDown = (Event_Power_Net_Flag.bit.PowerDownEvent);
Event_Status.bit.OverDemand = (Event_Power_Net_Flag.bit.OverPaADemand |Event_Power_Net_Flag.bit.OverNeADemand
	                                            |Event_Power_Net_Flag.bit.Over1RDemand  |Event_Power_Net_Flag.bit.Over2RDemand
	                                            |Event_Power_Net_Flag.bit.Over3RDemand  |Event_Power_Net_Flag.bit.Over4RDemand);
Event_Status.bit.Factor_Low = (Event_Power_Net_Flag.bit.OverFactor);
///Event_Status.byte[8] &= Meter_Parameter.parameter1.EventReportMode.byte[4];
/*"9"*/
Event_Status.bit.CurrCriticalImbalance = (Event_Power_Net_Flag.bit.CurrFarImB);
Event_Status.bit.TotalPowerReverse = (EventStatus_flag.bit.powertreverse);
Event_Status.bit.AllLostVoltage = (Event_Power_Net_Flag.bit.Phase3LostVolt);
///Event_Status.byte[9] &= Meter_Parameter.parameter1.EventReportMode.byte[5];

/*"10"*/
Event_Status.bit.Program_event = (Event_Power_Net_Flag.bit.ProgrammeEvent);
Event_Status.bit.Meter_clear = (EventStatus_flag.bit.Meter_clear);
Event_Status.bit.Demand_clear = (EventStatus_flag.bit.Demand_clear);
Event_Status.bit.Event_clear = (EventStatus_flag.bit.Event_clear);
Event_Status.bit.AdjustTime_event = (EventStatus_flag.bit.AdjustTime_event);
Event_Status.bit.ProgDailySlot = (EventStatus_flag.bit.ProgDailySlot);
Event_Status.bit.ProgYearSlot = (EventStatus_flag.bit.ProgYearSlot);
Event_Status.bit.ProgWeek = (EventStatus_flag.bit.ProgWeek);
///Event_Status.byte[10] &= Meter_Parameter.parameter1.EventReportMode.byte[6];

/*"11"*/
Event_Status.bit.ProgHoliday = (EventStatus_flag.bit.ProgHoliday);
Event_Status.bit.ProgAEMode = (EventStatus_flag.bit.ProgAEMode);
Event_Status.bit.ProgNEMode1 = (EventStatus_flag.bit.ProgNEMode1);
Event_Status.bit.ProgNEMode2 = (EventStatus_flag.bit.ProgNEMode2);
Event_Status.bit.ProgBillDay = (EventStatus_flag.bit.ProgBillDay);
Event_Status.bit.ProgTriffPrice = (EventStatus_flag.bit.ProgTriffPrice);
Event_Status.bit.ProgStepPrice = (EventStatus_flag.bit.ProgStepPrice);
Event_Status.bit.PSWUpdate = (EventStatus_flag.bit.PSWUpdate);
///Event_Status.byte[11] &= Meter_Parameter.parameter1.EventReportMode.byte[7];

for(i = 0; i < 96; i++)
{
/*"当某事件发生时事件主动上报状态相应位置位，"*/
/*"保证该事件结束后只要该状态字未抄读，"*/
/*"该事件状态需保持，抄读后复位"*/
if(Event_Status.byte[i>>3] & (0x01 << (i & 0x07)))
{
    if(*((unsigned char *)&Event_Report_Status_Times + i))
         Event_Report_Status.byte[i>>3] |= (0x01 << (i & 0x07));
///O1ther_Meter_Parameter.EventReport_TotalTimes++;
}
#if 0
else/*"事件已上报状态在事件结束后需置位，表示该事件需重新上报"*/
{
if(Event_Reported_Status.byte[i>>3] & (0x01 << (i & 0x07)))/*"结束时只清已上报事件的事件上报状态位，保证未上报事件不被清零"*/
{
Event_Report_Status.byte[i>>3] &= ~(0x01 << (i & 0x07));
Event_Reported_Status.byte[i>>3] &= ~(0x01 << (i & 0x07));
}
}
#endif
}

if(CompareBytes((unsigned char *)&Event_Report_Status_Backup, (unsigned char *)&Event_Report_Status, 12)!=0)
{ 
    WRLC256(EVENT_REPORT_STATUS_ROM,(unsigned char *)&Event_Report_Status,sizeof(union EVENT_REPORT_STATUS),0,0);
   for(i=0; i<12 ; i++)
        Event_Report_Status_Backup.byte[i]=Event_Report_Status.byte[i];
   WRLC256(EVENT_REPORT_STATUS_BACKUP_ROM,(unsigned char *)&Event_Report_Status_Backup,sizeof(union EVENT_REPORT_STATUS),0,0);
    ///WRLC256(EVENTREPORT_TOTALTIMES_ROM,(unsigned char *)&O1ther_Meter_Parameter.EventReport_TotalTimes_Backup,1,0,0);
    ///O1ther_Meter_Parameter.EventReport_TotalTimes_Backup = O1ther_Meter_Parameter.EventReport_TotalTimes;
   ///WRLC256(EVENTREPORT_TOTALTIMES_BACKUP_ROM,(unsigned char *)&O1ther_Meter_Parameter.EventReport_TotalTimes_Backup,1,0,0);
   
}

for(i=0 ; i<3; i++)
{
    if(0 != EventStatus_flag.byte[i])
    {
       EventStatus_flag.byte[i]=0;
       WRLC256((EVENTSTATUS_FLAG_ROM+i),(unsigned char *)&EventStatus_flag.byte[i],1,0,0);
    }
}

if(1==kind)/*"掉电前有事件需要上报，如果电表上电时不能将EventOut拉低，电表运行时才会将EventOut拉低"*/
{
for(i = 0; i < 12; i++)/*"只要有没有上报的事件就需要重新上报事件"*/
{
///EventReportStatus.byte[i] = (Event_Report_Status.byte[i] &  (~Event_Reported_Status.byte[i]));
EventReportStatus.byte[i] = Event_Report_Status.byte[i] ;
if(0 != EventReportStatus.byte[i])
{
Event_Report_flag = 0xff;
MK_EVENT = 1;
break;
}
}
}

}
/*"函数功能:获取事件上报状态字，根据当前事件状态、主动上报事件状态和已上报事件状态确定"*/
/*"输入参数:"*/
/*"输出参数:"*/
/*"调用说明:协议树读处理接口函数中调用"*/
void Get_Event_Report_Status(union EVENT_REPORT_STATUS *EventReportStatus)
{
unsigned char i = 0;

for(i = 0; i < 12; i++)
{
///EventReportStatus->byte[i] = (Event_Report_Status.byte[i] & (~Event_Reported_Status.byte[i]));
///Event_Report_Status.byte[i] = 0;/*"通信抄读后事件上报状态字复位"*/
///Event_Reported_Status.byte[i] |= EventReportStatus->byte[i];/*"已上报状态字在上报后置1"*/           
EventReportStatus->byte[i] = Event_Report_Status.byte[i] ;
}
///Event_Report_flag = 0;
///MK_EVENT = 0;
Event_Report_Iterate_flag=0;
}

/*"函数功能:抄读主动上报状态字后30分钟内未收到复位主动上报状态字,则清主动上报状态字"*/
/*"输入参数:"*/
/*"输出参数:"*/
/*"调用说明:主循环中每秒调用，在事件记录函数之前调用"*/
 void Clear_ALLEventReportInfo_NO_ACK(void)
 {
    unsigned int uni;
    unsigned char wflag;
     union EVENT_REPORT_STATUS ResetEventReportStatus;

            if(O1ther_Meter_Parameter.ResetEventReport_flag)
            {
        	if(O1ther_Meter_Parameter.EventReport_RunTime<(Meter_Parameter.parameter1.ResetReportTime*60L))/*"等待30分钟"*/
        	{
                 O1ther_Meter_Parameter.EventReport_RunTime++; 
        	}
            else/*"30分钟没有收到复位主动上报状态字,且收到复位主动上报状态字时，没有新的事件记录发生,清主动上报状态字"*/
            {                
               for(uni=0; uni<12; uni++)
               {
               ResetEventReportStatus.byte[uni]=Event_Report_Status_communication.byte[uni]^Event_Report_Status.byte[uni];
               }
                
               Clear_EventReportStatus_And_Times(ResetEventReportStatus);
               
                 wflag=0;
                 for(uni=0; uni<12; uni++)
                 {
                    if(Event_Report_Status_communication.byte[uni] != 0x00)
                    {
                    	wflag=1;
                    }
                    Event_Report_Status_communication.byte[uni] = 0x00;
                 }
                 if(wflag!=0)
                 {
                   WRLC256(EVENT_REPORT_STATUS_COMM_ROM,(unsigned char *)&Event_Report_Status_communication,sizeof(union EVENT_REPORT_STATUS),0,0);
                 }
            }
            }

 }
/*"函数功能:根据当前状态位实现该位状态的清零与置一"*/
/*"输入参数:Nbyte:表示第几个字节，n:表示的是第几位，State:表示的是当前位状态"*/
/*"输出参数:"*/
/*"调用说明:在事件记录函数里调用"*/
void EventReportState_Expand(unsigned char Nbyte, unsigned char n,unsigned char State)
{
if((State << n)==(EventStatus_flag.byte[Nbyte] & (0x01 << n)))
        {
         if(State)
             Clrbit(EventStatus_flag.byte[Nbyte],n);
         else
             Setbit(EventStatus_flag.byte[Nbyte],n);
        WRLC256((EVENTSTATUS_FLAG_ROM +Nbyte), (unsigned char *)&EventStatus_flag.byte[Nbyte],1,0,0);
        }
}

void ESAM_ErrReport(void)
{
    if((!EventStatus_flag.bit.ESAM_err)&&(Meter_Parameter.parameter1.EventReportMode.byte[0] & 0x02))
        {
            if(ESAM_ERR_DEFINE)
        	{/*"主动上报处理ESAM错误"*/
        	{
        	EventReportState_Expand(3, 2, 0);  
        	}
            if(Event_Report_Status_Times.ESAM_err_times != 255)
        	{
        	Event_Report_Status_Times.ESAM_err_times = 255;
        	Save_EventReportTimes(ESAM_ERR_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ESAM_err_times);
        	} 
        	}
        }
    else
        {
        	if(0==ESAM_ERR_DEFINE)
        	{/*"主动上报处理ESAM错误"*/
        	EventReportState_Expand(3, 2, 1);  
        	}
        }
}
void SwitchOn_Report(void)/*"继电器判成功合闸"*/
{
       if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x80) 
       {
       if(O1ther_Meter_Parameter.SwitchOn_Report)
       {
          if(((FLAG_SWITCH_ACT_MODE)&&(FAR_CLOSE_RECORD_DEFINE) && (Active_power[0]>0))
            ||((!FLAG_SWITCH_ACT_MODE)&&(FAR_CLOSE_RECORD_DEFINE)))
          {
            if(!EventStatus_flag.bit.Switch_on)
            {
            O1ther_Meter_Parameter.SwitchOn_Report = 0;
            WRLC256(SWITCHON_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOn_Report,1,0,0);
            EventReportState_Expand(3, 1, 0);  
            Save_EventReportTimes(SWITCH_ON_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Switch_on_times);   
            }
          }
       }
       }
}

void SwitchOff_Report(void)/*"继电器判成功跳闸"*/
{
   if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x40) 
   {
       if(O1ther_Meter_Parameter.SwitchOff_Report)
       {
         if(FAR_OPEN_RECORD_DEFINE)	
          {
            if(!EventStatus_flag.bit.Switch_off)
            {
            O1ther_Meter_Parameter.SwitchOff_Report=0;
            WRLC256(SWITCHOFF_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOff_Report,1,0,0);
            EventReportState_Expand(3, 7, 0);  
            Save_EventReportTimes(SWITCH_OFF_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Switch_off_times);   
            }
          }
       }
   }
}

void Overdraft_Report(void)/*"透支事件上报"*/
{
 if((!EventStatus_flag.bit.Overdraft )&&(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x02))/*"透支上报功能"*/
  {
   if((Show_flag.bit.Overdraft) ||(Show_flash_falg.bit.Overdraft))
    {
        {
          EventReportState_Expand(3, 0, 0);  
        }
    
    if(Event_Report_Status_Times.Overdraft_times != 255)
       {
         Event_Report_Status_Times.Overdraft_times = 255;
	  Save_EventReportTimes(OVERDRAFT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Overdraft_times);
       }
   }
 }
  else
  {
    if((0==Show_flag.bit.Overdraft)&&(0==Show_flash_falg.bit.Overdraft))
    {
     EventReportState_Expand(3, 0, 1);  
  }
  }
}
/*"检测电表上电时刻低功耗电池电压是否为欠压功能"*/
unsigned char CheckBatteryVoltValid(void)
{
	unsigned char result=0;
	unsigned char unc;
	
	powerup_init_time=METER_POWERUP_INITTIME;
	
	for(unc=0;unc<16;unc++)
	{
		if(RamData_Valid_flag[unc]!=unc)
		{
			return 0;  /*"RAM乱 没有电池"*/
		}
	}
	
	if(0==Meter_Parameter.parameter1.MeterMode[0].bit.b4) /*"模式字1的b4为0表示上电判低功耗电池是否欠压功能"*/ 
	{
		if(VB3_OK1==1)
	  {
	     Delay(1);
	     if(VB3_OK1==1)
       {
     	   result=1;  /*"IO口检测到有电池"*/
     	   powerup_init_time=powerup_init_time-2400;/*"上电初始化时间减少2.4s"*/
       }  
	  }
	}
  
	return result;
}
