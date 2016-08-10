/**************************************************************************************************
*                      fine:     defdata.h                                                        *
*                      function: define data                                                      *
***************************************************************************************************/ 
#ifndef _defdata_h_
#define _defdata_h_



#include "defmcro.h"        //macro define
#include "eventdatadef.h"       //event database define
#include "eventnew.h"
#include "MB_Base_fun.h"


//-------------1 byte----------------------
struct BIT
{
       unsigned char b0:1;
       unsigned char b1:1;
       unsigned char b2:1;
       unsigned char b3:1;
       unsigned char b4:1;
       unsigned char b5:1;
       unsigned char b6:1;
       unsigned char b7:1;
};
//-------------1 byte-----------------------
union BYTE_BIT
{
       struct BIT bit;
       unsigned char byte;
};
//-------------3 byte-----------------------
struct  TIME_DEF
{
       unsigned char Hour;
       unsigned char Minute;
       unsigned char Second;
};
//-------------4 byte-----------------------
struct DATE_DEF
{
       unsigned char Year;
       unsigned char Month;
       unsigned char Day;
       unsigned char Week;
};
//-------------7 byte-----------------------
struct DATEANDTIME_DEF
{
       unsigned char Year;
       unsigned char Month;
       unsigned char Day;
       unsigned char Hour;
       unsigned char Min;
       unsigned char Sec;
       unsigned char Week;
};

//-------------3 byte-----------------------
union METERFLAG
{                    
     struct
     {
       unsigned char Eeprom_Err1:1;
       unsigned char Eeprom_Err2:1;//no use
       unsigned char Eeprom_Err3:1;//no use
       unsigned char Eeprom_Err4:1;//no use
       unsigned char Rtc_Err1:1; 
       unsigned char Rtc_Err2:1; //no use
       unsigned char Battery1_Err:1;		//rtc1 battery error
       unsigned char Battery2_Err:1;		//rtc2 battery error
       unsigned char Battery3_Err:1;		//external battery error--added by LIAO DIHONG
       unsigned char Energymodule_Err:1;
       unsigned char Comm_Module_Err:1;//no use
       unsigned char Boad_Module_Err:1;		//load curve card error//no use
       unsigned char Ic_Card_Err:1;//no use
       
       unsigned char Eeprom_Data_Err:1;
       unsigned char Timer_Data_Err:1;  
       unsigned char Parameter_Data_Err:1; 
       unsigned char Ic_Card_Data_Err:1; 
       unsigned char Boad_Data_Err:1;

      }bit;
      unsigned int  intd; 
};


union ERR_INFORM_FLG
{
	struct
	{
		unsigned char Eeprom_Err:1;
		unsigned char Eeprom_Data_Err:1;
		unsigned char BatteryClK_Err:1;
		unsigned char BatteryDIS_Err:1;
		unsigned char VoltageReserve:1;
		unsigned char LossVoltage:1;
		unsigned char OverVoltage:1;
		unsigned char LossCurrent:1;
		unsigned char :1;
		unsigned char BreakPhase:1;
		unsigned char :1;
		unsigned char OverPower:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char Rtc_Err:1;
	}bit;
	unsigned int intd;
};
/*--------------------------------------------*/
/*--------------------------------------------*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
union NEW645METERSTATUS1
{
       struct
       {
       unsigned char :1; 
       unsigned char Demand_Mode:1;
       unsigned char Battery1_Status:1;
       unsigned char Battery2_Status:1;
       unsigned char ActivePower_Direct:1;
       unsigned char ReActivePower_Direct:1;
       unsigned char :1;
       unsigned char :1;

       unsigned char CtrCircleErr:1;	/*"控制回路错"*/
       unsigned char EsamErr:1;		/*"ESAM错"*/
       unsigned char B10:1;
       unsigned char B11:1;
       unsigned char ProgrammeErr:1;
       unsigned char EepromErr:1;
       unsigned char Overdraft:1;		/*"透支状态"*/
       unsigned char ClockErr:1;	   
       }bit;
       unsigned int  intd;                                          
}; 
////////////////////////////////

union NEW645METERSTATUS2
{
     struct
     {
       unsigned char ActiveDirection_A:1;	
       unsigned char ActiveDirection_B:1;
       unsigned char ActiveDirection_C:1;
       unsigned char :1;
       unsigned char ReactiveDirection_A:1;
       unsigned char ReactiveDirection_B:1;
       unsigned char ReactiveDirection_C:1;              
       unsigned char :1;   

       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;		   
     }bit;
     unsigned int  intd;                               
};
///////////////////////////
union NEW645METERSTATUS3
{
     struct
       {
       unsigned char WhitchDialySlotIsNow:1;
       unsigned char Power_Mode1:1;
       unsigned char Power_Mode2:1;
       unsigned char Program_Allow:1;	/*"约外认证/编程状态"*/
       unsigned char Relay_Status:1;
       unsigned char WhitchSlotIsNow:1;
       unsigned char SwitchCommandStatus:1;    	//payment
       unsigned char SwitchAlarmStatus:1; 

       unsigned char MeterType_L:1;
       unsigned char MeterType_H:1;
       unsigned char WhitchTriffIsNow:1;
       unsigned char WhitchStepIsNow:1;
       unsigned char keep_power_status:1;   /*" 保电状态 "*/
       unsigned char Identity_Flg:1;			/*"身份认证标志"*/
       unsigned char local_open_account:1;  /*" 本地开户 "*/
       unsigned char far_open_account:1;	/*" 远程开户 "*/   
       }bit;
       unsigned int  intd;                    
};
///////////////////////////
///////////////////////////
union NEW645METERSTATUS4
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
///////////////////////////
union NEW645METERSTATUS5
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
///////////////////////////
union NEW645METERSTATUS6
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
///////////////////////////
union NEW645METERSTATUS7
{
     struct
       {
       unsigned char VoltagePhaseRevers:1;
       unsigned char CurrentPhaseReverse:1;
       unsigned char VoltageImbalance:1;
       unsigned char CurrentImbalance:1;
       unsigned char AuxiliaryPower:1;
       unsigned char PowerDown:1;
       unsigned char OverDemand:1;              
       unsigned char OverFactor:1; 

       unsigned char CurrentGraveImbalance:1;
       unsigned char OpenCover:1;
       unsigned char OpenBox:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
///////////////////////////



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//-------------1 Bytes -----------------------
union METERSTATUS1
{
       struct
       {
       unsigned char Bill_Mode:1;
       unsigned char Demand_Mode:1;
       unsigned char Battery_Status:1;
       unsigned char :1;
       unsigned char ActivePower_Direct:1;
       unsigned char ReActivePower_Direct:1;
       unsigned char :1;
       unsigned char :1;
       }bit;
       unsigned char byte;                                          
};  
/*--------------------------------------------*/
//-------------1 Bytes -----------------------
union METERSTATUS2
{
     struct
     {
       unsigned char ActiveDirection_A:1;	
       unsigned char ActiveDirection_B:1;
       unsigned char ActiveDirection_C:1;
       unsigned char ActiveDirection_T:1;
       unsigned char ReactiveDirection_A:1;
       unsigned char ReactiveDirection_B:1;
       unsigned char ReactiveDirection_C:1;              
       unsigned char ReactiveDirection_T:1;       
     }bit;
     unsigned char byte;                               
};
/*--------------------------------------------*/  
//-------------1 Bytes -----------------------     
union METERSTATUS3
{
     struct
       {
       unsigned char CurrentPhaseReverse:1;
       unsigned char VoltagePhaseRevers:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char LossCurrent_A:1;
       unsigned char LossCurrent_B:1;
       unsigned char LossCurrent_C:1;              
       unsigned char :1; 
       }bit;
       unsigned char byte;                    
};
/*--------------------------------------------*/
//-------------1 Bytes -----------------------
union METERSTATUS4
{
    struct
      {
       unsigned char OverPower_Alarm:1;
       unsigned char OverPower_SwitchOff:1;
       unsigned char LowClockBattery:1;
       unsigned char :1;
       unsigned char OweFee_Alarm:1;
       unsigned char OweFee_SwitchOff:1;
       unsigned char LowBattery:1;              
       unsigned char :1;
      }bit;
      unsigned char byte;                                 
};
/*-------------------------------------------*/
//-------------1 Bytes -----------------------
union METERSTATUS5
{
     struct
      { 
       unsigned char Cover_Open:1;
       unsigned char IC_Insert:1;
       unsigned char Cal_Meter:1;
       unsigned char Set_Parameter:1;
       unsigned char Selftest_Pass:1;
       unsigned char Powerup:1;     
       unsigned char :1;              
       unsigned char :1;
      }bit;
     unsigned char byte;                                 
};
/*--------------------------------------------*/  
//-------------1 Bytes -----------------------     
union POWERNETSTATUS
{
      struct
      {
       unsigned char BreakPhase_A:1;
       unsigned char BreakPhase_B:1;
       unsigned char BreakPhase_C:1;
       unsigned char :1;
       unsigned char OverVoltage_A:1;
       unsigned char OverVoltage_B:1;
       unsigned char OverVoltage_C:1;
       unsigned char :1;
      }bit;
     unsigned char byte;                       
}; 
/*--------------------------------------------*/

/*"事件主动上报模式字定义"*/
union EVENT_REPORT_MODE
{
      struct
      {
       unsigned char Switch_err:1;/*"负荷开关误动作或拒动"*/
       unsigned char ESAM_err:1;/*"ESAM故障"*/
       unsigned char Eeprom_init_err:1;/*"内卡初始化故障"*/
       unsigned char Clock_Battery_Volt_low:1;/*"时钟电池电压低"*/
       unsigned char Code_err:1;/*"内部程序错误"*/
       unsigned char Memorizer_err:1;/*"存储器故障或损坏"*/
       unsigned char :1;/*""*/
       unsigned char Clock_err:1;/*"时钟故障"*/

	unsigned char LowPower_Battery_Volt_low:1;/*"低功耗电池欠压"*/
       unsigned char Overdraft:1;/*"欠费状态"*/
       unsigned char Open_Meter_Cover:1;/*"开表盖"*/
       unsigned char Open_Rail_Cover:1;/*"开端盖"*/
       unsigned char ConstantMagnet_event:1;/*"恒定磁场干扰"*/
       unsigned char PowerAbnormal_event:1;/*"电源异常"*/
       unsigned char Switch_off:1;/*"跳闸"*/
       unsigned char Switch_on:1;/*"合闸"*/

	unsigned char LostVolt:1;/*"失压"*/
       unsigned char LowVolt:1;/*"欠压"*/
       unsigned char OverVolt:1;/*"过压"*/
       unsigned char LossCurr:1;/*"失流"*/
       unsigned char OverCurr:1;/*"过流"*/
       unsigned char UpLoad:1;/*"过载"*/
       unsigned char PowerReserve:1;/*"功率反向"*/
       unsigned char BreakPhase:1;/*"断相"*/

	unsigned char BreakCurr:1;/*"断流"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

	unsigned char VoltReverse:1;/*"电压逆相序"*/
       unsigned char CurrReverse:1;/*"电流逆相序"*/
       unsigned char VoltImbalance:1;/*"电压不平衡"*/
       unsigned char CurrImbalance:1;/*"电流不平衡"*/
       unsigned char AuxiliaryPower_event:1;/*"辅助电源失电"*/
       unsigned char PowerDown:1;/*"掉电"*/
       unsigned char OverDemand:1;/*"超需量"*/
       unsigned char Factor_Low:1;/*"功率因数超下限"*/

	unsigned char CurrCriticalImbalance:1;/*"电流严重不平衡"*/
       unsigned char TotalPowerReverse:1;/*"总功率反向"*/
       unsigned char AllLostVoltage:1;/*"全失压"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

       unsigned char Program_event:1;/*"编程"*/
       unsigned char Meter_clear:1;/*"电表清零"*/
       unsigned char Demand_clear:1;/*"需量清零"*/
       unsigned char Event_clear:1;/*"事件清零"*/
       unsigned char AdjustTime_event:1;/*"校时事件"*/
       unsigned char ProgDailySlot:1;/*"时段表编程"*/
       unsigned char ProgYearSlot:1;/*"时区表编程"*/
       unsigned char ProgWeek:1;/*"周休日编程"*/

       unsigned char ProgHoliday:1;/*"节假日编程"*/
       unsigned char ProgAEMode:1;/*"有功组合方式编程"*/
       unsigned char ProgNEMode1:1;/*"无功组合方式1编程"*/
       unsigned char ProgNEMode2:1;/*"无功组合方式2编程"*/
       unsigned char ProgBillDay:1;/*"结算日编程"*/
       unsigned char ProgTriffPrice:1;/*"费率参数编程"*/
       unsigned char ProgStepPrice:1;/*"阶梯表编程"*/
       unsigned char PSWUpdate:1;/*"密钥更新"*/
      }bit;
	  
     unsigned char byte[8];                       
}; 

/*"事件主动上报状态字定义"*/
union EVENT_REPORT_STATUS
{
      struct
      {
       unsigned char Switch_err:1;/*"内置继电器错误"*/
       unsigned char ESAM_err:1;/*"ESAM故障"*/
       unsigned char Eeprom_init_err:1;/*"内卡初始化故障"*/
       unsigned char Clock_Battery_Volt_low:1;/*"时钟电池电压低"*/
       unsigned char Code_err:1;/*"内部程序错误"*/
       unsigned char Memorizer_err:1;/*"存储器故障或损坏"*/
       unsigned char :1;/*""*/
       unsigned char Clock_err:1;/*"时钟故障"*/

	unsigned char LowPower_Battery_Volt_low:1;/*"低功耗电池欠压"*/
       unsigned char Overdraft:1;/*"欠费状态"*/
       unsigned char Open_Meter_Cover:1;/*"开表盖"*/
       unsigned char Open_Rail_Cover:1;/*"开端盖"*/
       unsigned char ConstantMagnet_event:1;/*"恒定磁场干扰"*/
       unsigned char PowerAbnormal_event:1;/*"电源异常"*/
       unsigned char Switch_off:1;/*"跳闸"*/
       unsigned char Switch_on:1;/*"合闸"*/

	unsigned char LostVolt_A:1;/*"A相失压"*/
       unsigned char LowVolt_A:1;/*"A相欠压"*/
       unsigned char OverVolt_A:1;/*"A相过压"*/
       unsigned char LossCurr_A:1;/*"A相失流"*/
       unsigned char OverCurr_A:1;/*"A相过流"*/
       unsigned char UpLoad_A:1;/*"A相过载"*/
       unsigned char PowerReserve_A:1;/*"A相功率反向"*/
       unsigned char BreakPhase_A:1;/*"A相断相"*/

	unsigned char BreakCurr_A:1;/*"A相断流"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

	unsigned char LostVolt_B:1;/*"B相失压"*/
       unsigned char LowVolt_B:1;/*"B相欠压"*/
       unsigned char OverVolt_B:1;/*"B相过压"*/
       unsigned char LossCurr_B:1;/*"B相失流"*/
       unsigned char OverCurr_B:1;/*"B相过流"*/
       unsigned char UpLoad_B:1;/*"B相过载"*/
       unsigned char PowerReserve_B:1;/*"B相功率反向"*/
       unsigned char BreakPhase_B:1;/*"B相断相"*/

	unsigned char BreakCurr_B:1;/*"B相断流"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

	unsigned char LostVolt_C:1;/*"C相失压"*/
       unsigned char LowVolt_C:1;/*"C相欠压"*/
       unsigned char OverVolt_C:1;/*"C相过压"*/
       unsigned char LossCurr_C:1;/*"C相失流"*/
       unsigned char OverCurr_C:1;/*"C相过流"*/
       unsigned char UpLoad_C:1;/*"C相过载"*/
       unsigned char PowerReserve_C:1;/*"C相功率反向"*/
       unsigned char BreakPhase_C:1;/*"C相断相"*/

	unsigned char BreakCurr_C:1;/*"C相断流"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

	unsigned char VoltReverse:1;/*"电压逆相序"*/
       unsigned char CurrReverse:1;/*"电流逆相序"*/
       unsigned char VoltImbalance:1;/*"电压不平衡"*/
       unsigned char CurrImbalance:1;/*"电流不平衡"*/
       unsigned char auxiliaryPower_event:1;/*"辅助电源失电"*/
       unsigned char PowerDown:1;/*"掉电"*/
       unsigned char OverDemand:1;/*"超需量"*/
       unsigned char Factor_Low:1;/*"功率因数超下限"*/

	unsigned char CurrCriticalImbalance:1;/*"电流严重不平衡"*/
       unsigned char TotalPowerReverse:1;/*"总功率反向"*/
       unsigned char AllLostVoltage:1;/*"全失压"*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/
       unsigned char :1;/*""*/

       unsigned char Program_event:1;/*"编程"*/
       unsigned char Meter_clear:1;/*"电表清零"*/
       unsigned char Demand_clear:1;/*"需量清零"*/
       unsigned char Event_clear:1;/*"事件清零"*/
       unsigned char AdjustTime_event:1;/*"校时事件"*/
       unsigned char ProgDailySlot:1;/*"时段表编程"*/
       unsigned char ProgYearSlot:1;/*"时区表编程"*/
       unsigned char ProgWeek:1;/*"周休日编程"*/

       unsigned char ProgHoliday:1;/*"节假日编程"*/
       unsigned char ProgAEMode:1;/*"有功组合方式编程"*/
       unsigned char ProgNEMode1:1;/*"无功组合方式1编程"*/
       unsigned char ProgNEMode2:1;/*"无功组合方式2编程"*/
       unsigned char ProgBillDay:1;/*"结算日编程"*/
       unsigned char ProgTriffPrice:1;/*"费率参数编程"*/
       unsigned char ProgStepPrice:1;/*"阶梯表编程"*/
       unsigned char PSWUpdate:1;/*"密钥更新"*/
      }bit;
	  
     unsigned char byte[12];                       
}; 
//-------------1 Bytes -----------------------
union WEEKSTATUS
{
      struct
      {
       unsigned char Su:1;
       unsigned char Mo:1;
       unsigned char Tu:1;
       unsigned char We:1;
       unsigned char Th:1;
       unsigned char Fr:1;
       unsigned char Sa:1;
       unsigned char :1;
       
      }bit;
     unsigned char byte;  
};
/*--------------------------------------------*/
//-------------1 Bytes -----------------------
union COMMRATE
{
     struct
       {
        unsigned char :1;//fxf add 081120
        unsigned char B600:1;
	      unsigned char B1200:1;
        unsigned char B2400:1;
        unsigned char B4800:1;
        unsigned char B9600:1;
        unsigned char B19200:1;
	      unsigned char :1;
       }bit;
       unsigned char byte;
};
/*--------------------------------------------*/
//-------------1 Bytes -----------------------
union ERRORINFORMATION
{
    struct
      {  
      	unsigned char Invalid_Data:1;/*"--其他错误------------"*/
      	unsigned char Invalid_OBIS:1;/*"---无请求错误-------"*/
      	unsigned char Invalid_Password:1;/*"---密码错/未授权------------"*/
        unsigned char Invalid_COMMRATE:1;/*"---通信速率不能更改------------"*/
        unsigned char OutYearZone:1;/*"------------"*/
        unsigned char OutDailySlot:1;
        unsigned char OutTriff:1;
        unsigned char:1;
      }bit;
      unsigned char byte;  
}; 

/*--------------------------------------*/
//-------------10 Bytes -----------------------
struct METER_STATES
{
        union METERFLAG         Meter_Flag;
        union METERSTATUS1      Meter_Status1;
        union METERSTATUS2      Meter_Status2;
        union METERSTATUS3      Meter_Status3;
        union METERSTATUS4      Meter_Status4;
        union POWERNETSTATUS    PowerNet_Status;
        union ERRORINFORMATION  ErrOfInformation;
        union WEEKSTATUS        Week_Status;
        union METERSTATUS5      Meter_Status5;
        union COMMRATE          Comm_Rate[3];
        
        union BYTE_BIT          BatteryState;
        union BYTE_BIT          AlarmState;
        
        union ERR_INFORM_FLG    Err_Infor;
};

/*-----------------------------------------*/           
 //-------------10 Bytes -----------------------

struct NEW645METER_STATES
{
        union NEW645METERSTATUS1      Meter_Status1;
        union NEW645METERSTATUS2      Meter_Status2;
        union NEW645METERSTATUS3      Meter_Status3;
        union NEW645METERSTATUS4      Meter_Status4;
        union NEW645METERSTATUS5      Meter_Status5;
        union NEW645METERSTATUS6      Meter_Status6;
        union NEW645METERSTATUS7      Meter_Status7;
        union BYTE_BIT                OpenCoverStates;
        unsigned long psw_status_word;  /*" 密钥状态字 "*/
};  

   
//-------------10(58 bit) byte-----------------------      
                                                           
//-------------10(58 bit) byte-----------------------      
/*"mw modified  2009-08-22修改并重新定义了结构  "*/
/*"注意务必使EVENT_POWER_NET_TIMETICKS  结构和下面结构对应起来"*/    
//Pay attention to the following, match for the struct of EVENT_POWER_NET_TIMETICKS
union EVENT_POWER_NET_FLAG        
{
	struct                       
	{    
		unsigned char LostVoltage_A:1;                      
		unsigned char LostVoltage_B:1;                     
		unsigned char LostVoltage_C:1; 
		unsigned char VoltageReserve:1;
		unsigned char Phase3LostVolt:1;
		unsigned char LostCurrent_A:1;                     
		unsigned char LostCurrent_B:1;    
		unsigned char LostCurrent_C:1;    		
		//0-7  byte[0]
		
		unsigned char BreakPhase_A:1;   
		unsigned char BreakPhase_B:1;         
		unsigned char BreakPhase_C:1;       
		unsigned char VoltageDown_A:1;
		unsigned char VoltageDown_B:1;
		unsigned char VoltageDown_C:1;
		unsigned char OverPaADemand:1;   //
		unsigned char OverNeADemand:1;   //
		//0-7  byte[1]
		
		unsigned char PowerReverse_A:1;
		unsigned char PowerReverse_B:1;
		unsigned char PowerReverse_C:1;
		unsigned char OverVoltage_A:1;  
		unsigned char OverVoltage_B:1;  
		unsigned char OverVoltage_C:1;  
		unsigned char CurrImBalanceEvent:1;
		unsigned char VoltImBalanceEvent:1;	
		//0-7  byte[2]
		
		unsigned char OverCurrent_A:1;
		unsigned char OverCurrent_B:1;
		unsigned char OverCurrent_C:1;	
		unsigned char UpLoad_A:1;
		unsigned char UpLoad_B:1;
		unsigned char UpLoad_C:1;	
		unsigned char OpenCoverEvent:1;  
		unsigned char OpenBoxEvent:1;      
		//0-7  byte[3] 	
		
		unsigned char OverPowerAlarm:1;
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char AdjustMeterEvent:1;
		unsigned char ProgrammeEvent:1;
		unsigned char OverFactor_A:1;		
		unsigned char OverFactor_B:1;  
		unsigned char OverFactor_C:1;  
		/*" byte[4]的BIT7\BIT6\BIT5可以作扩展用，注意和累计时间结构及其内卡位置对应起来"*/ 	    	
		//0-7  byte[4] 		
		//eventflag over here 
		
		unsigned char CurrReverse:1;
		unsigned char OverFactor:1;
		unsigned char CurrFarImB:1;
		unsigned char FailCurrent_A:1;
		unsigned char FailCurrent_B:1;
		unsigned char FailCurrent_C:1;		
		unsigned char PowerDownEvent:1;  
		unsigned char :1;  	
		/*" byte[5]可以作扩展用，注意和累计时间结构及其内卡位置对应起来"*/
		/*" 新增加的事件最好放在byte[4]和byte[5]的扩展位置，否则程序有很多地方需要相应特殊处理"*/ 		
		//0-7  byte[5]   //for expand
		
		unsigned char OkVoltageCheck_A:1;  
		unsigned char UpVoltageCheck_A:1;  
		unsigned char DownVoltageCheck_A:1;  
		unsigned char OkVoltageCheck_B:1;  
		unsigned char UpVoltageCheck_B:1;  
		unsigned char DownVoltageCheck_B:1;  
		unsigned char ConstantMagnet:1;   
		unsigned char PowerAbnormal:1;	
		//0-7  byte[6]
		
		unsigned char OkVoltageCheck_C:1;  
		unsigned char UpVoltageCheck_C:1;  
		unsigned char DownVoltageCheck_C:1;   
		unsigned char Over1RDemand:1;
		unsigned char Over2RDemand:1;
		unsigned char Over3RDemand:1;
		unsigned char Over4RDemand:1;		
		unsigned char :1;
		//0-7  byte[7]		
	}bit;
	unsigned char byte[8]; 
};
                                                                                                                     
                                                           
                                                   
                                                           
                                                           
//-------------10(58 bit) byte-----------------------      
struct EVENT_POWER_NET_POINTER                             
{                                                          
    	unsigned char BreakPhase_A_P;   /*"0"*/
    	unsigned char BreakPhase_B_P;   /*"1"*/      
    	unsigned char BreakPhase_C_P;   /*"2"*/            
                                                
    	unsigned char LostVoltage_A_P;       /*"3"*/                     
	unsigned char LostVoltage_B_P;         /*"4"*/                  
	unsigned char LostVoltage_C_P;        /*"5"*/                 
	                                              
	unsigned char LostCurrent_A_P;        /*"6"*/                   
	unsigned char LostCurrent_B_P;        /*"7"*/                   
	unsigned char LostCurrent_C_P;        /*"8"*/        
	
	unsigned char PowerReverse_T_P;/*"9"*/      
	unsigned char PowerReverse_A_P;/*"10"*/      
	unsigned char PowerReverse_B_P;/*"11"*/      
	unsigned char PowerReverse_C_P;/*"12"*/
	
	unsigned char OverPowerAlarm_P;/*"13"*/      
	
	unsigned char VoltageReserve_P;/*"14"*/      
	
	unsigned char OverVoltage_A_P;/*"15"*/      
	unsigned char OverVoltage_B_P; /*"16"*/      
	unsigned char OverVoltage_C_P;/*"17"*/      
	 
  unsigned char PowerDown_P;/*"18"*/      
  
  unsigned char ProgrammeEvent_P;/*"19"*/      
  
  unsigned char VoltStatistic_A_P;/*"20"*/      
  unsigned char VoltStatistic_B_P;/*"21"*/      
  unsigned char VoltStatistic_C_P;/*"22"*/      
  unsigned char VoltStatistic_T_P;/*"23"*/      
  
  unsigned char OverPaADemand_P;/*"24"*/      
  unsigned char OverNeADemand_P;/*"25"*/      
  unsigned char Over1RDemand_P;/*"26"*/      
  unsigned char Over2RDemand_P;/*"27"*/      
  unsigned char Over3RDemand_P;/*"28"*/      
  unsigned char Over4RDemand_P;/*"29"*/       
  unsigned char OpenCoverEvent_P;  /*"30"*/      
  unsigned char OpenBoxEvent_P;/*"31"*/      
  unsigned char Phase3LostVolt_P;/*"32"*/  
  unsigned char CurrFarImB_P;/*"52->33"*/
  unsigned char ConstantMagnet_P;/*"56->34"*/        
  unsigned char PowerAbnormal_P;/*"57->35"*/   
  unsigned char CurrImBalanceEvent_P;/*"36"*/      
  unsigned char VoltImBalanceEvent_P;/*"37"*/      
  unsigned char VoltageDown_A_P;/*"38"*/      
  unsigned char VoltageDown_B_P;/*"39"*/      
  unsigned char VoltageDown_C_P;/*"40"*/      
  unsigned char OverCurrent_A_P;/*"41"*/      
  unsigned char OverCurrent_B_P;/*"42"*/      
  unsigned char OverCurrent_C_P;/*"43"*/      
  unsigned char UpLoad_A_P;/*"44"*/      
  unsigned char UpLoad_B_P;/*"45"*/      
  unsigned char UpLoad_C_P;/*"46"*/      
  unsigned char CurrReverse_P;/*"47"*/        
  unsigned char OverFactor_P;/*"48"*/      
  unsigned char OverFactor_A_P;/*"49"*/      
  unsigned char OverFactor_B_P;/*"50"*/      
  unsigned char OverFactor_C_P;/*"51"*/           
  unsigned char FailCurrent_A_P;/*"53->52"*/      
  unsigned char FailCurrent_B_P;/*"54->53"*/      
  unsigned char FailCurrent_C_P;/*"55->54"*/      
  unsigned char ClockBatteryEvent_P;/*"33->55"*/      
  unsigned char DisplayBatteryEvent_P;/*"34->56"*/      
  unsigned char AdjustMeterEvent_P;/*"35->57"*/    
       
      
};                                                         
                                                           
struct EVENT_METER_PRO_POINTER                             
{                                                           	
	unsigned char ResetCPU_P;/*"0"*/
	unsigned char SetPrimary_P;/*"1"*/
	unsigned char RunClockError_P;/*"2"*/
	unsigned char PowerUpClockError_P;/*"3"*/
	unsigned char AdjustEnergy_P;/*"4"*/
	unsigned char EepromErr_P;/*"5"*/
	unsigned char AdjustTimeOverT_P;/*6"*/
	unsigned char Energypasszero_P;/*"7"*/
	unsigned char Rst90E36_P;/*"8"*/
	unsigned char ClearMeterRecord_P;/*"9"*/
	unsigned char AdjustTimeRecord_P;/*"10"*/
	unsigned char ClearDemandRecord_P;/*"11"*/
	unsigned char ClearEventRecord_P;/*"12"*/
	unsigned char ProgWeekRecord_P;/*"13"*/
	unsigned char ProgAEModeRecord_P;/*"14"*/
	unsigned char ProgNEMode1Record_P;/*"15"*/
	unsigned char ProgNEMode2Record_P;/*"16"*/
	unsigned char ProgBillDayRecord_P;/*"17"*/
	unsigned char ProgYearSlotRecord_P;/*"18"*/
	unsigned char ProgDailySlotRecord_P;/*"19"*/
	unsigned char ProgHolidayRecord_P;/*"20"*/	
	unsigned char OverPowerCloseSwitch_P;/*"21"*/
	                                   
}; 

struct EVENT_METER_PRO_TIMES                               
{                                                                                                                                  
	unsigned long ResetCPU_Times;  /*"0"*/       	
	unsigned long SetPrimary_Times; /*"1"*/    		
	unsigned long RunClockError_Times;/*"2"*/   
	unsigned long PowerUpClockError_Times;/*"3"*/   
	unsigned long AdjustEnergy_Times;/*"4"*/   
	unsigned long EepromErr_Times;	/*"5"*/   	
	unsigned long AdjustTimeOverT_Times;/*"6"*/    			
	unsigned long Energypasszero_Times;  /*"7"*/
	unsigned long Rst90E36_Times;  /*"8"*/   	
	unsigned long ClearMeterRecord_Times;/*"9"*/   
	unsigned long AdjustTimeRecord_Times;/*"10"*/   
	unsigned long ClearDemandRecord_Times;/*"11"*/   
	unsigned long ClearEventRecord_Times;/*"12"*/   
	unsigned long ProgWeekRecord_Times;/*"13"*/   
	unsigned long ProgAEModeRecord_Times;/*"14"*/   
	unsigned long ProgNEMode1Record_Times;/*"15"*/   
	unsigned long ProgNEMode2Record_Times;/*"16"*/   
	unsigned long ProgBillDayRecord_Times;/*"17"*/   
	unsigned long ProgYearSlotRecord_Times;/*"18"*/   
	unsigned long ProgDailySlotRecord_Times;/*"19"*/   
	unsigned long ProgHolidayRecord_Times;/*"20"*/   	
	unsigned long OverPowerCloseSwitch_Times;/*"21"*/ 	
};

#define CLEARMETEREVENTBEGIN 10
#define CLEARMETEREVENTEND   21     
        
struct EVENT_POWER_NET_TIMES                               
{                                                          
  unsigned long BreakPhase_A_Times;   /*"0"*/
  unsigned long BreakPhase_B_Times;   /*"1"*/      
  unsigned long BreakPhase_C_Times;   /*"2"*/                                           
  unsigned long LostVoltage_A_Times;   /*"3"*/                   
  unsigned long LostVoltage_B_Times;    /*"4"*/                 
  unsigned long LostVoltage_C_Times; /*"5"*/
  unsigned long LostCurrent_A_Times;   /*"6"*/                  
  unsigned long LostCurrent_B_Times;      /*"7"*/               
  unsigned long LostCurrent_C_Times;          /*"8"*/
  unsigned long PowerReverse_T_Times;/*"9"*/
  unsigned long PowerReverse_A_Times;/*"10"*/
  unsigned long PowerReverse_B_Times;/*"11"*/
  unsigned long PowerReverse_C_Times;	 /*"12"*/	          	
  unsigned long OverPowerAlarm_Times;    /*"13"*/
  unsigned long VoltageReserve_Times;   /*"14"*/
  unsigned long OverVoltage_A_Times;   /*"15"*/
  unsigned long OverVoltage_B_Times;   /*"16"*/
  unsigned long OverVoltage_C_Times;   /*"17"*/  	                            
  unsigned long PowerDown_Times;/*"18"*/
  unsigned long ProgrammeEvent_Times;/*"19"*/
  unsigned long VoltStatistic_A_Times;/*"20"*/
  unsigned long VoltStatistic_B_Times;/*"21"*/
  unsigned long VoltStatistic_C_Times;/*"22"*/
  unsigned long VoltStatistic_T_Times;/*"23"*/
  unsigned long OverPaADemand_Times;/*"24"*/
  unsigned long OverNeADemand_Times;/*"25"*/
  unsigned long Over1RDemand_Times;/*"26"*/
  unsigned long Over2RDemand_Times;/*"27"*/
  unsigned long Over3RDemand_Times;/*"28"*/
  unsigned long Over4RDemand_Times;/*"29"*/
  unsigned long OpenCoverEvent_Times;    /*"30"*///Moved here by mw 2009-09-03
  unsigned long OpenBoxEvent_Times;/*"31"*/
  unsigned long Phase3LostVolt_Times;/*"32"*/
  unsigned long CurrFarImB_Times;/*"52->33"*/
  unsigned long ConstantMagnet_Times;/*"56->34"*/
  unsigned long PowerAbnormal_Times;  /*"57->35"*/
  unsigned long CurrImBalanceEvent_Times;/*"36"*/
  unsigned long VoltImBalanceEvent_Times;/*"37"*/
  unsigned long VoltageDown_A_Times;/*"38"*/
  unsigned long VoltageDown_B_Times;/*"39"*/
  unsigned long VoltageDown_C_Times;/*"40"*/
  unsigned long OverCurrent_A_Times;/*"41"*/
  unsigned long OverCurrent_B_Times;/*"42"*/
  unsigned long OverCurrent_C_Times;/*"43"*/
  unsigned long UpLoad_A_Times;/*"44"*/
  unsigned long UpLoad_B_Times;/*"45"*/
  unsigned long UpLoad_C_Times;/*"46"*/
  unsigned long CurrReverse_Times;/*"47"*/
  unsigned long OverFactor_Times;/*"48"*/
  unsigned long OverFactor_A_Times;/*"49"*/
  unsigned long OverFactor_B_Times;/*"50"*/
  unsigned long OverFactor_C_Times;/*"51"*/
  unsigned long FailCurrent_A_Times;/*"53->52"*/
  unsigned long FailCurrent_B_Times;/*"54->53"*/
  unsigned long FailCurrent_C_Times;/*"55->54"*/
  unsigned long ClockBatteryEvent_Times;/*"33->55"*/
  unsigned long DisplayBatteryEvent_Times;/*"34->56"*/
  unsigned long AdjustMeterEvent_Times;/*"35->57"*/
                         
};                                           

/*"mw modified  2009-08-22修改并重新定义了结构  "*/
/*"注意务必使EVENT_POWER_NET_FLAG  结构和下面结构对应起来"*/    
/*"注意务必使EVENT_POWER_NET_TIMETICKS  结构和EEPROM位置对应"*/    
struct EVENT_POWER_NET_TIMETICKS                           
{   
		unsigned long LostVoltage_A_Times_Ticks;                      
		unsigned long LostVoltage_B_Times_Ticks;                     
		unsigned long LostVoltage_C_Times_Ticks; 
		unsigned long VoltageReserve_Times_Ticks; 
		unsigned long Phase3LostVolt_Times_Ticks; 
		unsigned long LostCurrent_A_Times_Ticks;                     
		unsigned long LostCurrent_B_Times_Ticks;                     
		unsigned long LostCurrent_C_Times_Ticks;
		
		unsigned long BreakPhase_A_Times_Ticks;   
		unsigned long BreakPhase_B_Times_Ticks;         
		unsigned long BreakPhase_C_Times_Ticks;  
		unsigned long VoltageDown_A_Times_Ticks;
		unsigned long VoltageDown_B_Times_Ticks;
		unsigned long VoltageDown_C_Times_Ticks;
		unsigned long OverPaADemand_Times_Ticks; 
		unsigned long OverNeADemand_Times_Ticks; 

		unsigned long PowerReverse_A_Ticks;
		unsigned long PowerReverse_B_Ticks;
		unsigned long PowerReverse_C_Ticks;
		unsigned long OverVoltage_A_Times_Ticks;
		unsigned long OverVoltage_B_Times_Ticks;
		unsigned long OverVoltage_C_Times_Ticks; 		
		unsigned long CurrImBalanceEvent_Times_Ticks;
		unsigned long VoltImBalanceEvent_Times_Ticks;

		unsigned long OverCurrent_A_Times_Ticks;
		unsigned long OverCurrent_B_Times_Ticks;
		unsigned long OverCurrent_C_Times_Ticks;
		unsigned long UpLoad_A_Times_Ticks;
		unsigned long UpLoad_B_Times_Ticks;
		unsigned long UpLoad_C_Times_Ticks; 
		unsigned long Nouse_0_Times_Ticks; 
		unsigned long Nouse_1_Times_Ticks;
		
		unsigned long OverPowerAlarm_Times_Ticks;
		unsigned long Nouse_2_Times_Ticks; 
		unsigned long Nouse_3_Times_Ticks; 
		unsigned long Nouse_4_Times_Ticks; 
		unsigned long Nouse_5_Times_Ticks;
		unsigned long OverFactor_A_Times_Ticks;
		unsigned long OverFactor_B_Times_Ticks; 
		unsigned long OverFactor_C_Times_Ticks;	

		unsigned long CurrReverse_Times_Ticks;  //EEPROM not deal 
		unsigned long OverFactor_Times_Ticks;
		unsigned long CurrFarImB_Times_Ticks;
		unsigned long FailCurrent_A_Times_Ticks;
		unsigned long FailCurrent_B_Times_Ticks;
		unsigned long FailCurrent_C_Times_Ticks;     //EEPROM not deal 
		unsigned long Nouse_15_Times_Ticks; 
		unsigned long Nouse_16_Times_Ticks;
		
		unsigned long OkVoltageCheck_A_Times_Ticks;          
		unsigned long UpVoltageCheck_A_Times_Ticks;  
		unsigned long DownVoltageCheck_A_Times_Ticks;  
		unsigned long OkVoltageCheck_B_Times_Ticks; 
		unsigned long UpVoltageCheck_B_Times_Ticks;  
		unsigned long DownVoltageCheck_B_Times_Ticks; 
		unsigned long Nouse_18_Times_Ticks;
		unsigned long Nouse_19_Times_Ticks;

		unsigned long OkVoltageCheck_C_Times_Ticks;  
		unsigned long UpVoltageCheck_C_Times_Ticks;  
		unsigned long DownVoltageCheck_C_Times_Ticks;  
		unsigned long Nouse_20_Times_Ticks;
		unsigned long Nouse_21_Times_Ticks;
		unsigned long Nouse_22_Times_Ticks;
		unsigned long Nouse_23_Times_Ticks; 
		unsigned long Nouse_24_Times_Ticks;	
		
};                                                                                                                      

struct SLOTPAREMETER
{
       unsigned     char             YearSlotNumble;
       unsigned     char             DailySlotTableNumble;
       unsigned     char             DailySlotNumble;
       unsigned     char             TriffNumble;
       unsigned      int             HollidayNumble;     
       unsigned     char             WeekEndTable;  
       union        WEEKSTATUS       Week_Status;
        
};

struct  DAYHOUR_DEF
{
    unsigned char Day;
    unsigned char Hour;
};
struct SWITCH_ITEM
{
	 unsigned     char             WhitchSlotIsNow;
   struct       DATEANDTIME_DEF  SwitchDate;
   unsigned     char             FreezeData_addr;         	
   unsigned     char             DropProtectFlag;
};//add by zlp

union LCD_LED_Speaker_Terminal_ALARM_FLAG      
{
	struct                       
	{    
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char RunClockError:1; 
       unsigned char Eeprom_Err:1;		
      	unsigned char OpenBoxEvent:1;      
		unsigned char OpenCoverEvent:1;  
		unsigned char OverFactor:1;
		unsigned char VoltageReserve:1;
    
		unsigned char CurrReverse:1;
		unsigned char PowerReverse:1;
       unsigned char OverPaADemand:1;   
       unsigned char OverNeADemand:1;          
       unsigned char LostVoltage:1;  
		unsigned char BreakPhase:1;   
		unsigned char OverVoltage:1;  
		unsigned char VoltageDown:1;
    
    	unsigned char VoltImBalance:1;	      
		unsigned char CurrImBalance:1;
		unsigned char CurrFarImBalance:1;
		unsigned char LostCurrent:1;                     
		unsigned char OverCurrent:1;
		unsigned char FailCurrent:1;
		unsigned char UpLoad:1;
		unsigned char Programme:1;

       
		unsigned char OverReDemand:1;                     
		unsigned char ConstMagnet:1; 
    unsigned char EsamErr:1;  
		unsigned char CtrCircleErr:1;  
       unsigned char :1;                     
		unsigned char :1; 
    	unsigned char :1;  
		unsigned char :1;  
	}bit;
    unsigned long Alarm_Flag;
};

union TERMINALALARMFLAG      
{
	struct                       
	{    
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char RunClockError:1; 
    unsigned char Eeprom_Err:1;		
    unsigned char OpenBoxEvent:1;      
		unsigned char OpenCoverEvent:1;  
		unsigned char OverFactor:1;
		unsigned char VoltageReserve:1;
    
		unsigned char CurrReverse:1;
		unsigned char PowerReverse:1;
    unsigned char OverPaADemand:1;   
    unsigned char OverNeADemand:1;          
    unsigned char LostVoltage:1;  
		unsigned char BreakPhase:1;   
		unsigned char OverVoltage:1;  
		unsigned char VoltageDown:1;
    
    unsigned char VoltImBalance:1;	      
		unsigned char CurrImBalance:1;
		unsigned char CurrFarImBalance:1;
		unsigned char LostCurrent:1;                     
		unsigned char OverCurrent:1;
		unsigned char FailCurrent:1;
		unsigned char UpLoad:1;
		unsigned char Programme:1;

       
		unsigned char OverReDemand:1;                     
		unsigned char ConstMagnet:1; 
    unsigned char EsamErr:1;  
		unsigned char CtrCircleErr:1;  
    unsigned char :1;                     
		unsigned char :1; 
    unsigned char :1;  
		unsigned char OverPowerAlarm:1;  
	}bit;
  unsigned long Alarm_Flag;
};

//-------------322     -----------------------
struct PARAMETER1//important meter parament
{
  unsigned     long             ActivePulseConst;
  unsigned     long             ReactivePulseConst;
//  unsigned     long             LActivePulseConst;
//  unsigned     long             LReactivePulseConst;
  unsigned     char             BcdCommAddr[3][6];
  union        BYTE_BIT         MeterMode[4];
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_Alarm_Flag; /*"   液晶报警   "*/	
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_LedAlarm_Flag;/*"   灯光报警   "*/
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_SpeakerAlarm_Flag;/*"   声报警   "*/
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_TerminalAlarm_Flag;/*"   辅助端子报警   "*/
  unsigned     char             DemandPeriod;
  unsigned     char             DemandSkipPeriod;
  unsigned     char             CycleDisplayTime;
  unsigned     char             DisplayNumber;
  struct       DAYHOUR_DEF      AutoBillDayHour[3];
  union        BYTE_BIT         Activem_Erengy_Mode;         /*"   有功计量模式字   "*/		
	union        BYTE_BIT         REActivem_Erengy_1_Mode;  /*"  无功计量模式字 1  "*/
	union        BYTE_BIT         REActivem_Erengy_2_Mode;   /*"   无功计量模式字2   "*/
	/*"   上三个调理顺序091009 mw  "*/
	union        BYTE_BIT         MeterTypeMode;
	union        BYTE_BIT         CarrierMode;
  union        COMMRATE         Commrate[4];    /*"0:第1路485 1:红外   2:第2路485 3:模块通信口"*/
 // unsigned     char             VI_Regulation[2];
  struct       SLOTPAREMETER    SlotParemeter[2];
  struct       SWITCH_ITEM      TriffSwitch;
	struct       SWITCH_ITEM      DailySlotSwitch;          
	unsigned     int              KeyDisplayNumber;
	unsigned     char             ClearPassword[MAX_PASS_NUM][4];
  unsigned     char             UserClass[3];
  unsigned     long             EventJudgeIn;
  unsigned     char             DISP_In;  
  union EVENT_REPORT_MODE  EventReportMode;/*"事件上报模式字"*/
 union        BYTE_BIT             LocalFunctionMode;/*"地方特殊功能要求模式字"*/ 
   unsigned     char             ResetReportTime;/*" 主动上报状态字自复位延时间 "*/  
  unsigned     int              crc_cal;
               
};  //Note:when change the structrue need change 645 id 0E0E000B and 0E0E000C

/*"地方特殊功能要求模式字"*/ 
/*"bit0表示北京特殊要求控制位"*/
/*"bit1表示重庆特殊要求控制位"*/ 
/*"bit2表示四川特殊要求控制位"*/
#define SpicReq_SC_DEFINE	Meter_Parameter.parameter1.LocalFunctionMode.bit.b2

struct PARAMETER2//normal meter parameter
{
//-------------new 645 fxf add 081112-----------------
	unsigned     char             AscII_MeterManage_Code[32]; /*"   资产管理编码   "*/
	unsigned     char             AscII_V_Regulation[6]; /*"  额定电压  "*/	
	unsigned     char             AscII_I_Regulation[6]; /*"  额定电流  "*/
	unsigned     char             AscII_MAX_I[6]; /*"  最大电流  "*/
	unsigned     char             AscII_Active_Accu[4]; /*"  有功准确等级  "*/
	unsigned     char             AscII_Reactive_Accu[4]; /*"  无功准确等级  "*/
	unsigned     char             AscII_Meter_Moder[10]; /*"   电表型号   "*/
	unsigned     char             AscII_Manufacture_Day[10]; /*"  生产日期 "*/
	unsigned     char             AscII_Protocol_Version[16]; /*"   协议版本号   "*/	
	unsigned     char             AscII_Factory_Hardware_Version[32]; /*"   厂家硬件版本号   "*/	
	unsigned     char             AscII_Factory_Sofeware_Version[32]; /*"  厂家软件版本号   "*/	
	unsigned     char             AscII_Factory_Number_Version[32]; /*"   厂家编号 "*/		
	//------------------new 645 fxf add 081112 END--------------------------------
	unsigned     char             EnergyPoint;
  unsigned     char             PowerPoint;        
  unsigned     char             LoadDay;            
  unsigned     int              PulseWidth;
  unsigned     char             BcdMeterID[6];
  unsigned     char             BcdUserID[6];
  unsigned     char             BcdDeviceID[6]; 
  union        BYTE_BIT         LoadRecordMode;
  struct       DATEANDTIME_DEF  LoadRecoedBeginTime;
  unsigned     int              LoadRecordPeriod[6];
  
  
  unsigned     char             OpenSwitchDelayTime;
  unsigned     char             CloseSwitchDelayTime;
  
	unsigned     int              ShowNoKeyRetTime;/*"   无按键返回时间   "*/  
  unsigned     char             Meterlocktimes;
  unsigned     long             PlusEnergyData;
  unsigned     long             NegaEnergyData;
  unsigned     int              ExitProgrameTime;
  unsigned     char             BroadcastJustTtimes;
  unsigned     char             JFPG_ExpressTriff[63];
  unsigned     char             PowerOnFullScreenTime;///king chen add 121226
  signed       long             Longitude;
  signed       long             Latitude;
  signed       long             Height;
  unsigned     char             MeterSoftIdNumber[8];
  unsigned     int              crc_cal;
};  //Note:when change the structrue need change 645 id 0E0E0009 and 0E0E000A
struct EVENT_PARAMETER
{
	unsigned     long             VoltageHealth_UpSet;
  unsigned     long             VoltageHealth_DownSet;
  unsigned     long             VoltageCheck_UpSet;
  unsigned     long             VoltageCheck_DownSet;  
	unsigned     char             JudgeLossVoltageSecond;
  unsigned     char             JudgeBreakPhaseSecond;	
  unsigned     char             JudgeLostCurr_T;
  unsigned     long             JudgeLostCurr_I[2];
  unsigned     long             JudgeBreakPhaseI;
  unsigned     long             PaADemandLimit;
  unsigned     long             NeADemandLimit;
  unsigned     char             CriticalVoltage;
  unsigned     int              JudgeOverVolt_V;
  unsigned     long             JudgeCurrImBalanceN;
  unsigned     long             JudgeVoltImBalanceN;
  unsigned     long             JudgeLossVoltage;
  unsigned     char             JudgeLossVoltageNV;
  unsigned     int              JudgeVoltDown_V;
  unsigned     long             JudgeOverCurrentI;
	unsigned     int              JudgeLostVoltSV;
	unsigned     int              JudgeLostVoltEV;
	unsigned     char             JudgeVoltDownT;
	unsigned     char             JudgeOverVoltT;
	unsigned     int              JudgeBreakPhaseV;
	unsigned     char             JudgeVoltImBalanceT;
	unsigned     char             JudgeCurrImBalanceT;
	unsigned     int              JudgeLostCurrSV;
	unsigned     char             JudgeOverCurrentT;
	unsigned     long             JudgePowerReverseP;
	unsigned     char             JudgePowerReverseT;
	unsigned     long             JudgeUpLoadP;
	unsigned     char             JudgeUpLoadT;
	unsigned     long             JudgeOverDemandP;
	unsigned     int              JudgeOverFactorN;
	unsigned     char             JudgeOverFactorT;
	unsigned     int              JudgeCurrFarImBN;
	unsigned     char             JudgeCurrFarImBT;
	unsigned     int              JudgeFailCurrSV;
	unsigned     long             JudgeFailCurrI;
	unsigned     char             JudgeFailCurrT;	
  unsigned     long             JudgeOverDemandN;
  unsigned     char             JudgeOverDemandT;
  unsigned     long             JudgeCurrImBMinI;
  unsigned     long             JudgeABCPowerReverseP;
	unsigned     char             JudgeABCPowerReverseT;
    unsigned int                  AD_Sample_Vref;/*"电池电压AD采样参考电压"*/
    unsigned int                  ClockBattery_volt_Low_Threshold;/*"时钟电池欠压阀值"*/
    unsigned int                  DisplayBattery_volt_Low_Threshold;/*"低功耗电池欠压阀值"*/
  unsigned     int              crc_cal;
};  //Note:when change the structrue need change 645 id 0E0E0007
#if 0
struct BILL_STATE
{
	unsigned     long             OldSegParameter;
	unsigned     char             Bill_Flag;				//Bill Flag when across month
  unsigned     char             Bill_Addr;				//Address of history month data
  unsigned     char             Bill_DM_Flag;				//Bill Flag when across month
  unsigned     char             Bill_DM_Addr;				//Address of history month data
  struct       DATEANDTIME_DEF  LastEnergyBillDate;//Last Bill Day fx add 090925
  unsigned     int              crc_cal;
};
#endif
struct FREEZE_PARAMETER
{
	unsigned     char             FreezeDate[4];
  unsigned     char             FreezeDateFlag;
	struct       DATEANDTIME_DEF  Freeze_Period_Date;		
	unsigned     char             Freeze_Period_Interval;
	unsigned     char             FreezeDay_Hour; 
  unsigned     char             FreezeDay_Min;
	union        BYTE_BIT         New645_Freeze_Time_Mode;
	union        BYTE_BIT         New645_Freeze_Moment_Mode;
	union        BYTE_BIT         New645_Freeze_Promise_Mode;
	union        BYTE_BIT         New645_Freeze_Period_Mode;
	union        BYTE_BIT         New645_Freeze_Day_Mode;
	unsigned     int              crc_cal;
};  //Note:when change the structrue need change 645 id 0E0E0008

///struct NEW_PARAMETER///king chen mark 121226
///{
///	unsigned     char             Dayfreeze_flag;
///       unsigned     char             PowerOnDayfreeze_flag;
///	unsigned     char             PowerOnFullScreenTime;
	
///	unsigned     int                crc_cal;
///};
struct METER_PARAMETER
{
	struct PARAMETER1             parameter1;
	struct PARAMETER2             parameter2;
	struct EVENT_PARAMETER        event_parameter;
	struct FREEZE_PARAMETER       freeze_parameter;
///	struct NEW_PARAMETER       new_parameter;///king chen mark 121226
};


struct COMMCLEARSTRDEF
{
    unsigned char    Clear_All_Flag;/*"Clear_all"*/
    unsigned char    Clear_Event_Flag;/*"Clear_event"*/
    unsigned char    Clear_Demand_Flag;/*"Clear_demand"*/
    unsigned char    CommDailyProgFlag;
    unsigned char    CommYearProgFlag;    
    unsigned int     Comm_Clear_Crc_Data;/*"crc"*/    
};

    
struct OTHER_METER_PARAMETER
{
	unsigned     char             WorkRoomState;
	unsigned     char             WorkRoomFlag;
	struct       DATEANDTIME_DEF WorkRoomStateDate;
    //add for Program Key time 
    unsigned     long             WorkRoom_RunTime;///king chen add 121214
    unsigned     char             ProgramKeyStartFlag;
    unsigned     long             ProgramKeyTimeAdd;
    //add for Program power down clear
    struct       COMMCLEARSTRDEF CommClearFlagCurrFF; 
  
    unsigned     char             JustMeter;
    unsigned     char             OutputModel;    //pulse output change

    ///unsigned     char             Dayfreeze_flag;///king chen mark 130327
    unsigned     char             PowerOnDayfreeze_flag;///king chen add 121226
    struct      DATEANDTIME_DEF  DayFreezeReferenceDate;////king chen add 130302
    unsigned     char             PowerOnRetort_flag;///king chen add 120322
    unsigned     int             EventReport_RunTime;/*"抄读主动上报状态字进行时间累计,累计到30分钟,未收到复位主动上报状态命令,则清主动上报状态字"*/
    unsigned     char             ResetEventReport_flag;/*"抄读主动上报状态字则置位(1), 收到复位主动上报状态字则清零(0)"*/
    
    unsigned     long             OldSegParameter;
    unsigned     char             Bill_Flag;				//Bill Flag when across month
    unsigned     char             Bill_Addr;				//Address of history month data
    unsigned     char             Bill_DM_Flag;				//Bill Flag when across month
    unsigned     char             Bill_DM_Addr;				//Address of history month data
    struct       DATEANDTIME_DEF  LastEnergyBillDate;//Last Bill Day fx add 090925
    unsigned     char             FreezeData_Time_addr;        
    unsigned     char             FreezeData_Moment_addr;       
    unsigned     char             FreezeData_Period_addr;          
    unsigned     char             FreezeData_Day_Addr;	

    unsigned     char             SwitchOn_Report; 
    unsigned     char             SwitchOff_Report;  
//  unsigned int crc_cal;   
};


//-------------14  byte-----------------------
struct       PASSWORDERR
{
  unsigned char flag;
  unsigned char num;
  struct DATEANDTIME_DEF firsttime;
  struct DATEANDTIME_DEF secondtime;
};

//-------------16  byte-----------------------
struct OTHER_DATA
{
  unsigned     long             BatteryWorkTime1;//low power
  unsigned     long             BatteryWorkTime2;// clock
//  unsigned     long             NegaRunEnergy_T; 
//  unsigned     long             NegaRunEnergy_A; 
//  unsigned     long             NegaRunEnergy_B; 
//  unsigned     long             NegaRunEnergy_C; 

  struct       PASSWORDERR      PasswordErr[MAX_PASS_NUM];
	unsigned     char             Clear_PasswordErr_Flag;  //clear flag  

  struct       DATEANDTIME_DEF  LastClearDemandDate;
  struct       DATEANDTIME_DEF  LastJusttime;
  unsigned     char             JusttimesAdd;  
  struct       DATEANDTIME_DEF  ProgramDate;
  struct       DATEANDTIME_DEF  LastClearDemandDateCM;
	struct       COMMCLEARSTRDEF  CommClearFlagCurrEE;
//	unsigned int crc_cal;
};

struct PRE_SAVE_DATA		//payment
    {
	  signed long Remain_Money;                	/*" 剩余电费 0.01元 "*/
	unsigned long Remain_Money_bottom;	/*" 剩余电费尾数 0.0001元 "*/
	unsigned long Energy_Next_Step;      	/*" 距下一阶梯的剩余电量 "*/
	unsigned long Month_Total_Energy;     	/*" 月电量 "*/
	unsigned long Year_Total_Energy;			/*" 当前年度组合有功总累计用电量 "*/
	unsigned char duct_eng;/*" 2位小数时，走0.01KWH才扣费，记录了有多少个0.001"*/
};

//-------------337  byte-----------------------
struct ENERGY_RECORD
{				
  unsigned long  Plus_Active[MAXTRIFF]; 
	unsigned long  Nega_Active[MAXTRIFF];
	
	unsigned long  Quad_Reactive[4][MAXTRIFF];
    
  unsigned long  Phase_Plus_Active[3];
  unsigned long  Phase_Nega_Active[3];
  
  unsigned long  Phase_Reactive[3][4];
	
//  unsigned long HavePower_Times_Ticks_T;
//  
//  unsigned long HavePower_Times_Ticks_OK_A;
//  unsigned long HavePower_Times_Ticks_UP_A;
//  unsigned long HavePower_Times_Ticks_DW_A;
//  
//  unsigned long HavePower_Times_Ticks_OK_B;
//  unsigned long HavePower_Times_Ticks_UP_B;
//  unsigned long HavePower_Times_Ticks_DW_B;
//  
//  unsigned long HavePower_Times_Ticks_OK_C;
//  unsigned long HavePower_Times_Ticks_UP_C;
//  unsigned long HavePower_Times_Ticks_DW_C;
//  
//  unsigned long Tongsun[4];			/*sum,A,B,C*/
//  unsigned long Tiesun[4];			/*sum,A,B,C*/
//  unsigned long Hechengwucha[4];		/*sum,A,B,C*/
	  
//  unsigned long data[2];
	unsigned char EnergyPassMAXTimes[6];

       struct PRE_SAVE_DATA	   Pre_Save_Data;	//payment
	
	unsigned int   crc_cal;
	

}; 
//-------------every minute copy ram1 to ram2 data(include energy and time)--
struct MINUTE_COPY_ENERGY
{	
  struct ENERGY_RECORD      Energy_Record;	
  struct DATEANDTIME_DEF    date;                   	
	unsigned char             csadd;	
}; 


//-------------288  byte-----------------------
struct DEMAND_DATA_FORM
{
	unsigned long Demand;
	unsigned char time[5];
};

struct DEMAND_RECORD
{
	
        
      struct DEMAND_DATA_FORM  Plus_Active[MAXTRIFF]; 
	    struct DEMAND_DATA_FORM  Nega_Active[MAXTRIFF];
			struct DEMAND_DATA_FORM  Quad_Reactive[4][MAXTRIFF];
//	    struct DEMAND_DATA_FORM  Com1_Reactive[MAXTRIFF];
//      struct DEMAND_DATA_FORM  Com2_Reactive[MAXTRIFF];
			
			
       
	
};  

union DEMAND_TYPE
{
	struct DEMAND_RECORD Demand;
	struct DEMAND_DATA_FORM  Value[6][MAXTRIFF];
};

//-------------441 byte-----------------------
struct ENERGY_POWERDOWN//
  {
	   unsigned int  Plus_Active[2]; 
	   unsigned int  Nega_Active[2];
	   unsigned int  Quad_Reactive[4][2];	    	
	   
     unsigned long  Phase_Plus_Active[3];
     unsigned long  Phase_Nega_Active[3];
     unsigned long  Phase_Reactive[3][4];
  };


  
struct POWERDOWN_SAVE_DATA//
{
	
	struct ENERGY_POWERDOWN  energy_powerdown;  
  struct   DATEANDTIME_DEF date;	    
	unsigned char            fee;	  
	unsigned char            PdEventFlag[8];
	struct PRE_SAVE_DATA	   Pre_Save_Data;	//payment
  unsigned int             crc_cal;   
            
};

struct ENERGY_RAIL_ADD_BUFFER
{
	unsigned long  Rail_Plus_Active[4];			//Sum/Phase A/Phase B/Phase C
	unsigned long  Rail_Nega_Active[4];			//Sum/Phase A/Phase B/Phase C
	
	unsigned long  Rail_Quad_Reactive[4][4];		//1st,2nd,3rd,4th quadrant 
	
	unsigned char  Total_Plus_Active_100mwh[MAXTRIFF];			//Sum total+8triff unit 0.0001kwh
	unsigned char  Total_Nega_Active_100mwh[MAXTRIFF];			//Sum total+8triff unit 0.0001kwh
	
	unsigned int crc_cal;
};

//-------------992 byte-----------------------
struct THIS_MONTH_DATA
{

	struct ENERGY_RECORD      Energy_Record;

	union DEMAND_TYPE      Demand_Record;

};     
//-------------992 byte-----------------------
struct THIS_MONTH_DATA_EEPROM
{

	struct ENERGY_RECORD      Energy_Record;

	struct DEMAND_RECORD      Demand_Record;

};     

//-------------6930 byte-----------------------
struct EVENT_RECORD
{
	unsigned char Event_Recort [(sizeof(struct EVENT_POWER_NET_POINTER)*2
	                           +sizeof(struct EVENT_METER_PRO_POINTER))*11][9];
};

struct SINGLE_EVENT_ENERGE
{
  unsigned     long             P_Energy;	//When lost voltage, Sum/A/B/C positive active energy
	unsigned     long             N_Energy;	//When lost voltage, Sum/A/B/C reverse active energy
	unsigned     long             R_Energy[4];//When lost voltage, Sum/A/B/C four-star reactive energy
};


//-------------       -----------------------
struct LOSSVOLTAGE_ENERGY
{
	struct SINGLE_EVENT_ENERGE      Single[4];
	unsigned     long               LossVoltageIH[3];		//When lost voltage, A/B/C amp*Hour
};
//-------------       -----------------------
struct LOSSCURRENT_ENERGY
{        
	struct SINGLE_EVENT_ENERGE      Single[4];
};


struct POWERRESERVE_ENERGY_SING
{
  unsigned     long             P_PowerReserveEnergy;   
  unsigned     long             N_PowerReserveEnergy;    
};
//-------------       -----------------------
struct POWERRESERVE_ENERGY
{
	struct POWERRESERVE_ENERGY_SING Sg[4];    //when total/A/B/C powerreserve,the energy of total/A/B/C
};

struct TOTAL_POWERRESERVE_ENERGY
{
  struct POWERRESERVE_ENERGY    Single[4];  //total/A/B/C powerreserve
};

//-------------       -----------------------
struct EVENT_ENERGY
{        
  struct LOSSVOLTAGE_ENERGY     Lossvoltage_Energy[7]; 
  
  struct LOSSCURRENT_ENERGY     LOSSCURRENT_ENERGY[6];
  
  struct POWERRESERVE_ENERGY    POWERRESERVE_ENERGY[4];
  
  struct POWERRESERVE_ENERGY_SING    CurrentImbalance_Energy[3];	
};

//-------------   byte-----------------------
struct CLEAR_DEMAND_DATA
{
	struct DATEANDTIME_DEF    date;	
};
//-------------   byte-----------------------
struct AC
{
	unsigned long  Plus_Active[MAXTRIFF]; 
	unsigned long  Nega_Active[MAXTRIFF];
	unsigned int   Volt[3];
  unsigned int   Curr[3];
  unsigned char  Active_power[4][3];
  unsigned int   Reactive_power[4];
  unsigned int   Factor[4];    
  unsigned int   Freq;  
  unsigned int   Phase_Angle[4];
  unsigned char  date[5];
};
struct RC
{
	unsigned long  Quad_Reactive[4][MAXTRIFF];
  unsigned char  date[5];
};
//struct FREEZE_DATA
//{
//
//        struct AC   ac;
//	    struct RC   rc;
//	
//};

//-------------72 byte-----------------------
struct YEARSLOT
{
	unsigned char YearSlot[MAXYEARSLOT][3];
};
//-------------240 byte-----------------------
struct DAILYSLOT
{
	unsigned char DailySlot[MAXDAILYSLOTTABLE][MAXDAILYSLOT*3];
};
//-------------300 byte-----------------------
struct HOLIDAYSLOT
{
	unsigned char HolidaySlot[MAXHOLIDAYSLOT][4];  //fxf 081113 3->4 
};
//-------------4  byte-----------------------
union ID
{
  unsigned char d[4];
  unsigned int  i;
  unsigned int  new_i[2];//2008-7-9 17:54:13
  unsigned long l;
};
//-------------4  byte-----------------------
union NEW_ID
{
  unsigned char d[4];
  unsigned int  i[2];
  unsigned long l;
};
struct CYCLEDISPLAYTABLE1
{
	unsigned char flag; 
  unsigned char work[4];    
};
struct CYCLEDISPLAYTABLE2
{
	unsigned char code;
  unsigned char use[4];    
};
struct CYCLEDISPLAYTABLE_A
{
  struct CYCLEDISPLAYTABLE1 CycleDisplayTable1[99];
	struct CYCLEDISPLAYTABLE2 CycleDisplayTable2[99];
};
struct CYCLEDISPLAYTABLE_B
{
  struct CYCLEDISPLAYTABLE1 CycleDisplayTable1[120];
	struct CYCLEDISPLAYTABLE2 CycleDisplayTable2[120];
};

//-------------1500 byte-----------------------------
								
union CoBuff
{
	unsigned char b[1280];
	
	struct ENERGY_RECORD            Energy_Record;
	struct ENERGY_POWERDOWN         Energy_Powerdown;
	struct POWERDOWN_SAVE_DATA      Powerdown_Save_Data;
	struct METER_PARAMETER          Meter_Parameter;
	struct COMM
	{
	   unsigned char      num;            //no use
	   union    BYTE_BIT  com;            //b0-1(have)0(no),b1,b2,b3 so,b4-1(p)0-(n),b5,b6,b7 so
	   unsigned char*     addrr[4];       //the data ram address
	   unsigned int       addre[4];       //the data eeprom address
	   union    BYTE_BIT  flag1;          //b0-hex,b1-bcd,b2-ask,b3-ram,b4-ee,b5-e1,b6-e2,b7-e3
	   unsigned char      format;         //no use
	   unsigned char      rw;             //0-write ,1-read
	   unsigned char      len;            //every take data length
	   unsigned char*     addr5;          //the data send or read address
	   unsigned char      condition;      //no use
	   union    BYTE_BIT  flag2;          //Co.c.flag2.b0-1(data reverse),0-(no data reverse)
	   union    BYTE_BIT  flag3;          //Co.c.flag3.b0-1(have data cal),0-(no data cal);b1-1(is negtive data),0-(is p data0
	   union    BYTE_BIT  flag4;          //Co.c.flag4.b0-1(energy),0-(no energy);
	   unsigned char      calnumber;      //the number of cal
	   union DATA
	   {
	      unsigned   char      c[4];
	      unsigned   int       i[2];
	      signed     long      g;
	   }d;                                //in W_R_data,add data
	   unsigned char Convert[12];         //when change dara, use as buffer 
	   unsigned char data[4][20];    //the data buffer
	   unsigned char f[50];
	   unsigned char h[50];
 
	}c;
	struct Event
	{
	   unsigned int addr;
	   unsigned char point;
	   unsigned char * eaddr;
	   unsigned int  len;
	   unsigned int elen;
	   
    }e;
	
};
//-------------11  byte-----------------------------
struct FindCommand_Result
{
	unsigned char firstreceivecomm:1; //1:first receive command,
	unsigned char havebackframe:1; //1:have back frame
	unsigned char sendbackframe:1; //1:in send interrupt,set this flag,
	                               //in send cycle,clear this flag.
	unsigned char readloadrecord:1;
	unsigned char firstreadloadrecord:1;
	unsigned char lastreadloadrecord:1;
	unsigned char ZJ_Read_Big_Block:1;
	unsigned char ZJ_Read_Lit_Block:1;
	unsigned char ZJ_Read_Single:1;
	unsigned char ZJ_zerodata:1;
	unsigned char ZJ_overdata:1;
	unsigned char ZJ_firstzjto645:1;
	unsigned char BroadCasrAddress:1;
	unsigned char All_AA_Address;/*"全A缩位地址标志，该值为1时表示当前地址为全A地址"*/
                                       	                               
	unsigned char model;  //0-645,1-weisheng 2-645 and weisheng
	unsigned char c;      //recerved  "C"
	unsigned int  len;    //reserved  length
	unsigned char addr;   //reserved data address in buffer
	union    ID   id;     //reserved id
	unsigned char* dataaddr; //reserved data address
	
	union    ID   idt;    //send id, when many data,idt is add
	unsigned int  lent;   //the sum length of send data 
	unsigned int  lena;   //every send ,the length of data
	unsigned char ct;     //send "C"
	union    ID   idd;    //cal id, when cal send id,idd is for cpu id,idt is for comm 
	                      //when ZJ,idd is ZJ id
	unsigned char ZJ_n;   //ZJ,the num of read data.     
	unsigned char ZJ_len; //ZJ,the num of every length read data.                        
	
	unsigned char uartx;  //whitch uart
	unsigned char sum;    //in loadrecord,if have backframe,the sum is saved.
	
	unsigned char passerword;//passerword lever

	unsigned char Frame_serial;// BACK number
  unsigned long Programer_code;// caozuozhedaoma
		
	unsigned char command[10];//load record 
	
	
};

struct DEMAND_CONTROL
{
	unsigned char LastTriff; //number of last triff
	unsigned char TriffCounter; //counter of minutes for current triff
	unsigned char Pointer; //index of current block in GDemandArea
	unsigned char ClockAdjusted; //clock adjusted flag
	unsigned char TriffPointer; //first pointer of triff demand
	
	unsigned long TriffRest[4];  //rest demand of last skip time
	unsigned char HaveRest;  //flag of have TriffRest		
};


struct LOADRECORD                                                                                                 
{		                                                                                                        
  unsigned int        PageAddress; /*"未用空间起始Page地址"*/                                                            
	unsigned int        ByteAddress; /*"未用空间起始Byte地址"*/  
  unsigned int        LastPageAddress;  /*"最后一条存储取的数据的Page地址"*/                                             
	unsigned int        LastByteAddress;  /*"最后一条存储取的数据的Byte地址"*/     
  unsigned int        FirstPageAddress1[6];  /*"第1<--->6类最早一条存储取的数据的Page地址"*/                                             
	unsigned int        FirstByteAddress1[6];  /*"第1<--->6类最早一条存储取的数据的Byte地址"*/  
  unsigned int        LastPageAddress1[6];  /*"第1<--->6类最后一条存储取的数据的Page地址"*/                                             
	unsigned int        LastByteAddress1[6];  /*"第1<--->6类最后一条存储取的数据的Byte地址"*/  
  union    BYTE_BIT   First_Flag;                                           
	struct                                                                                                          
	{                                                                                                               
		unsigned int Last_Read_PageAddress; /*"最后一次读取的数据的Page地址"*/                                  
		unsigned int Last_Read_ByteAddress; /*"最后一次读取的数据的Byte地址"*/                                  
		unsigned int Next_Read_PageAddress; /*"最后一次读取的数据的下条纪录Page地址"*/                          
		unsigned int Next_Read_ByteAddress; /*"最后一次读取的数据的下条纪录Byte地址"*/                          
	}ReadHistory[3];                                                                                                
	                                                                                                                
	struct DATA_TIME    LastRecordTime; //time tag of last saved record	                                                        
                                                                                                                      
                                                                                      
	                                                                                                                
	struct                                                                                                          
	{                                                                                                               
		char NeedSaveIndex:1;	// =1 need; =0 not need	                                                        
		char reStart:1;			/*"负荷曲线记录是否覆盖第一条重头开始，需要在电表第一次初始化时清0"*/   
		char LoadRecoedBeginTime:1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
	}LoadRecordFlag;                                                                                                
	                                                                                                                
	                                                                                                                
	                                                                                                                
	unsigned int CurrentIndex;                                                                                      
	                                                                                                                
	struct DATEANDTIME_DEF            LastSaveDate;                                                                 
};   


struct	ALLVOLTAGELOSS_EVENT
{
	unsigned char Start_Second;  //add by pc 081208
	unsigned char Start_Minute;
	unsigned char Start_Hour;	
	unsigned char Start_Day;			
	unsigned char Start_Month;			
	unsigned char Start_Year;
	
	unsigned char End_Second;  //add by pc 081208
	unsigned char End_Minute;
	unsigned char End_Hour;	
	unsigned char End_Day;			
	unsigned char End_Month;			
	unsigned char End_Year;	
	unsigned long Curr_PD;//ganjp 20090326							
};	
struct	ALLVOLTAGELOSS_STRUCTURE
{
	unsigned char	Valid_AllVoltageLoss_Flag[8];					/*OK:0,1,2,3,4,5,6,7:"全失压时间有效标志：上电时用"*/
	unsigned char	AllVoltageLoss_Start_Flag;						//One AllVoltageLoss event has started.
	//unsigned char	AllVoltageLoss_End_Flag;						//One AllVoltageLoss event has ended.
	unsigned char	AllVoltageLoss_Counter_Before_Start;			/*"全失压事件开始以前连续发生全失压的时间计数器：秒"*/
	unsigned char	AllVoltageLoss_Counter_Before_End;				/*"全失压事件结束以前连续没有发生全失压的时间计数器：秒"*/
	unsigned char	AllVoltageLoss_WakingUp_Counter;				//number of INT 3 interrups persecond
	unsigned char	AllVoltageLoss_Event_Pointer_in_Powerdown_Mode;	/*"本次掉电期间全失压事件记录的指针"*/
	
	unsigned int	AllVoltageLoss_Event_Times;						/*"本次掉电期间发生全失压的次数"*/
	unsigned long	AllVoltageLoss_Time_Seconds;					//AllVoltageLoss time (unit:second) in the power down interval
	unsigned long	AllVoltageLoss_Time_Seconds_Copy;				//Copy of AllVoltageLoss time (unit:second) in the power down interval
	struct        ALLVOLTAGELOSS_EVENT	AllVoltageLoss_Event[10];			/*"本次掉电期间全失压事件记录"*/
};

//------------------------  New 645  ------------------------//
//------------------------   Public DataStruct       -------------------------//
//------------------------   Public DataStruct       -------------------------//
/*"mw modified 2009-09-03 此结构扩展到12字节，前6字节存掉电时候事件标志，后6字节存相应电量调整标志"*/
struct PowerDown_EventSave_Data
{
	union BYTE_BIT eventflag[12];  //mw modified 2009-09-03
	unsigned long amphour[3];
	unsigned char eventflagcs;	
};
//mw modified 2009-09-03 
//enentflag[0] b0 1-A Phase LostVoltage 0-A Phase not LostVoltage
//             b1 1-B Phase LostVoltage 0-B Phase not LostVoltage
//             b2 1-C Phase LostVoltage 0-C Phase not LostVoltage
//             b3 1-VoltageReserve Event    0-Voltage not Reverse
//             b4 1-Phase3LostVolt Event    0-Phase 3 not Lost Voltage
//             b5 1-A Phase LostCurrent 0-A Phase not LostCurrent
//             b6 1-B Phase LostCurrent 0-B Phase not LostCurrent
//             b7 1-C Phase LostCurrent 0-C Phase not LostCurrent
//eventflag[1] b0 1-A Phase BreakPhase  0-A Phase not BreakPhase
//             b1 1-B Phase BreakPhase  0-B Phase not BreakPhase
//             b2 1-C Phase BreakPhase  0-C Phase not BreakPhase
//             b3 1-A Phase VoltageDown 0-A Phase not VoltageDown
//             b4 1-B Phase VoltageDown 0-B Phase not VoltageDown
//             b5 1-C Phase VoltageDown 0-C Phase not VoltageDown
//             b6 1-Plus Active Demand Over 0-Plus Active Demand not Over
//             b7 1-Negtive Active Demand Over 0-Negtive Active Demand not Over
//eventflag[2] b0 1-A Phase Power Reverse 0-A Phase not Power Reverse
//             b1 1-B Phase Power Reverse 0-B Phase not Power Reverse
//             b2 1-C Phase Power Reverse 0-C Phase not Power Reverse
//             b3 1-A Phase over voltage  0-A Phase not over voltage
//             b4 1-B Phase over voltage  0-B Phase not over voltage
//             b5 1-C Phase over voltage  0-C Phase not over voltage
//             b6 1-curr imbalance event  0-not curr imbalance event
//             b7 1-volt imbalance event  0-not volt imbalance event
//eventflag[3] b0 1-A Phase OverCurrent 0-A Phase not OverCurrent
//             b1 1-B Phase OverCurrent 0-B Phase not OverCurrent
//             b2 1-C Phase OverCurrent 0-C Phase not OverCurrent
//             b3 1-A Phase UpLoad  0-A Phase not UpLoad
//             b4 1-B Phase UpLoad  0-B Phase not UpLoad
//             b5 1-C Phase UpLoad  0-C Phase not UpLoad
//             b6 1-Open Cover Event    0-Not Open Cover Event
//             b7 1-open box            0-not open box
//eventflag[4] b0 1-over demand alarm     0-not over demand alarm
//             b1 1-clock battery event   0-not clock battery event
//             b2 1-display battery event 0-not display battery event
//             b3 1-adjust meter event    0-not adjust meter event
//             b4 1-Programme Event     0-Not Programme Event
//             b5 not use
//             b6 not use
//             b7 not use
//eventflag[5] b0 1-Current Reverse  0-Current not Reverse            //New added 
//             b1 1-OverFactor 0-not OverFactor                               //New added 
//             b2 1-curr imbalance event  0-not curr imbalance event    //New added 
//             b3 1-A Phase FailCurrent 0-not         //New added 
//             b4 1-B Phase FailCurrent 0-not         //New added 
//             b5 1-C Phase FailCurrent 0-not         //New added 
//             b6 not use
//             b7 not use

//not the same as before, NOTES ,
//enentflag[6] b0 1-Ajust energy when A Phase LostVoltage 0-not
//             b1 1-Ajust energy when B Phase LostVoltage 0-not
//             b2 1-Ajust energy when C Phase LostVoltage 0-not
//             b3 1-VoltageReserve Event    0-Voltage not Reverse
//             b4 not use ,Reserve for Phase3LostVolt Event    
//             b5 1-Adjust energy when A Phase LostCurrent 0-not
//             b6 1-Adjust energy when B Phase LostCurrent 0-not
//             b7 1-Adjust energy when C Phase LostCurrent 0-not
//eventflag[7] b0 1-Adjust energy when A Phase BreakPhase  0-not
//             b1 1-Adjust energy when B Phase BreakPhase  0-not
//             b2 1-Adjust energy when C Phase BreakPhase  0-not
//             b3 1-Adjust energy when A Phase VoltageDown 0-not
//             b4 1-Adjust energy when B Phase VoltageDown 0-not
//             b5 1-Adjust energy when C Phase VoltageDown 0-not
//             b6 1-not use,Reserve for Plus Active Demand Over
//             b7 not use,Reserve for Active Demand Over 
//eventflag[8] b0 1-Adjust energy when A Phase Power Reverse 0-not
//             b1 1-Adjust energy when B Phase Power Reverse 0-not
//             b2 1-Adjust energy when C Phase Power Reverse 0-not
//             b3 1-Adjust energy when A Phase OverVoltage   0-not
//             b4 1-Adjust energy when B Phase OverVoltage   0-not
//             b5 1-Adjust energy when C Phase OverVoltage   0-not
//             b6 1-Adjust energy when curr imbalance      0-not
//             b7 1-Adjust energy when volt imbalance      0-not
//eventflag[9] b0 1-Adjust energy when A Phase OverCurrent 0-not
//             b1 1-Adjust energy when B Phase OverCurrent 0-not
//             b2 1-Adjust energy when C Phase OverCurrent 0-not
//             b3 1-Adjust energy when A Phase UpLoad        0-not
//             b4 1-Adjust energy when B Phase UpLoad        0-not
//             b5 1-Adjust energy when C Phase UpLoad        0-not
//             b6 not use, Reserve for Open Cover Event    
//             b7 not use, Reserve for open box            
//eventflag[10] b0 not use
//             b1 not use
//             b2 not use
//             b3 not use
//             b4 not use
//             b5 not use
//             b6 not use
//             b7 not use
//eventflag[11] b0 1-Adjust energy when Current Reverse    0-not         //New added 
//             b1 1-Adjust energy when OverFactor                 0-not         //New added 
//             b2 1-Adjust energy when curr imbalance             0-not         //New added 
//             b3 1-Adjust energy when A Phase FailCurrent      0-not         //New added 
//             b4 1-Adjust energy when B Phase FailCurrent      0-not         //New added 
//             b5 1-Adjust energy when C Phase FailCurrent      0-not         //New added 
//             b6 not use
//             b7 not use



//NOTES:the following is not right mw
//struct PowerDown_EventSave_Data
//{
//	union BYTE_BIT eventflag[12];
//	unsigned long amphour[3];
//	unsigned char eventflagcs;	
//};
//enentflag[0] b0 1-A Phase LostVoltage 0-A Phase not LostVoltage
//             b1 1-B Phase LostVoltage 0-B Phase not LostVoltage
//             b2 1-C Phase LostVoltage 0-C Phase not LostVoltage
//             b3 1-Programme Event     0-Not Programme Event
//             b4 1-Open Cover Event    0-Not Open Cover Event
//             b5 1-A Phase LostCurrent 0-A Phase not LostCurrent
//             b6 1-B Phase LostCurrent 0-B Phase not LostCurrent
//             b7 1-C Phase LostCurrent 0-C Phase not LostCurrent
//eventflag[1] b0 1-A Phase BreakPhase  0-A Phase not BreakPhase
//             b1 1-B Phase BreakPhase  0-B Phase not BreakPhase
//             b2 1-C Phase BreakPhase  0-C Phase not BreakPhase
//             b3 1-Voltage Reverse     0-Voltage not Reverse
//             b4 1-Plus Active Demand Over 0-Plus Active Demand not Over
//             b5 1-Negtive Active Demand Over 0-Negtive Active Demand not Over
//             b6 1-A Phase UpLoad  0-A Phase not UpLoad
//             b7 1-B Phase UpLoad  0-B Phase not UpLoad
//eventflag[2] b0 1-A Phase Power Reverse 0-A Phase not Power Reverse
//             b1 1-B Phase Power Reverse 0-B Phase not Power Reverse
//             b2 1-C Phase Power Reverse 0-C Phase not Power Reverse
//             b3 1-open box              0-not open box
//             b4 1-A Phase over voltage  0-A Phase not over voltage
//             b5 1-B Phase over voltage  0-B Phase not over voltage
//             b6 1-C Phase over voltage  0-C Phase not over voltage
//             b7 1-Phase 3 Lost Voltage  0-Phase 3 not Lost Voltage
//eventflag[3] b0 1-over demand alarm     0-not over demand alarm
//             b1 1-clock battery event   0-not clock battery event
//             b2 1-display battery event 0-not display battery event
//             b3 1-adjust meter event    0-not adjust meter event
//             b4 1-curr imbalance event  0-not curr imbalance event
//             b5 1-volt imbalance event  0-not volt imbalance event
//             b6 1-C Phase UpLoad  0-C Phase not UpLoad
//             b7 1-Current Reverse  0-Current not Reverse
//eventflag[4] b0 1-Ajust energy when A Phase LostVoltage 0-not
//              b1 1-Adjust energy when B Phase LostVoltage 0-not
//              b2 1-Adjust energy when C Phase LostVoltage 0-not
//              b3 1-Adjust energy when A Phase FailCurrent 0-not
//              b4 1-Adjust energy when B Phase FailCurrent 0-not
//              b5 1-Adjust energy when A Phase LostCurrent 0-not
//              b6 1-Adjust energy when B Phase LostCurrent 0-not
//              b7 1-Adjust energy when C Phase LostCurrent 0-not
//eventflag[5] b0 1-Adjust energy when A Phase BreakPhase  0-not
//              b1 1-Adjust energy when B Phase BreakPhase  0-not
//              b2 1-Adjust energy when C Phase BreakPhase  0-not
//              b3 1-Adjust energy when Voltage Reverse     0-not
//              b4 1-Adjust energy when curr imbalance      0-not
//              b5 1-Adjust energy when volt imbalance      0-not
//              b6 1-Adjust energy when A Phase UpLoad      0-not
//              b7 1-Adjust energy when B Phase UpLoad      0-not
//eventflag[6] b0 1-Adjust energy when A Phase Power Reverse 0-not
//              b1 1-Adjust energy when B Phase Power Reverse 0-not
//              b2 1-Adjust energy when C Phase Power Reverse 0-not
//              b3 1-Adjust energy when A Phase OverVoltage   0-not
//              b4 1-Adjust energy when B Phase OverVoltage   0-not
//              b5 1-Adjust energy when C Phase OverVoltage   0-not
//              b6 1-Adjust energy when C Phase UpLoad        0-not
//              b7 1-Adjust energy when Current Reverse       0-not
//enentflag[7] b0 1-A Phase VoltageDown 0-A Phase not VoltageDown
//             b1 1-B Phase VoltageDown 0-B Phase not VoltageDown
//             b2 1-C Phase VoltageDown 0-C Phase not VoltageDown
//             b3 1-A Phase OverCurrent 0-A Phase not OverCurrent
//             b4 1-B Phase OverCurrent 0-B Phase not OverCurrent
//             b5 1-C Phase OverCurrent 0-C Phase not OverCurrent
//             b6 1-OverFactor 0-not OverFactor
//             b7 1-Adjust energy when C Phase FailCurrent 0-not
//eventflag[8] b0 1-Adjust energy when A Phase VoltageDown 0-not
//             b1 1-Adjust energy when B Phase VoltageDown 0-not
//             b2 1-Adjust energy when C Phase VoltageDown 0-not
//             b3 1-Adjust energy when A Phase OverCurrent 0-not
//             b4 1-Adjust energy when B Phase OverCurrent 0-not
//             b5 1-Adjust energy when C Phase OverCurrent 0-not
//             b6 1-Adjust energy when OverFactor 0-not
//eventflag[9] b0 1-A Phase FailCurrent 0-A Phase not FailCurrent
//             b1 1-B Phase FailCurrent 0-B Phase not FailCurrent
//             b2 1-C Phase FailCurrent 0-C Phase not FailCurrent 
//mw closed 2009-10-09
//------------------------   Public DataStruct       -------------------------//
//------------------------  New 645  ------------------------//
struct VoltStatisticStruct{
 union BYTE_BIT *VoltCheck;  
 unsigned char bytenum;
 unsigned char OkVoltage;
 unsigned char UpVoltage;
 unsigned char DownVoltage;
 unsigned char *VoltStatistic_P;
};   
//struct PREPFIRSTEVENT_STRU1   //mw added 2009-09-03
//{
//		TGeneral_Event Function;         /*"例如失压数据存储函数指针"*/
//		unsigned int   eeprom_addr;      /*"例如失压内卡地址"*/
//		unsigned char  *Flag;            /*"例如失压发生标志"*/
//		unsigned char  *eventflag;       /*"例如失压电量错误标志"*/
//		unsigned char  Offset;           /*"例如失压相应标志在结构中的偏移位置"*/
//};	
struct PREPFIRSTEVENT_STRU   //mw added 2009-09-03
{
		TGeneral_Event Function;         /*"例如失压数据存储函数指针"*/
		unsigned int   eeprom_addr;      /*"例如失压内卡地址"*/
		unsigned char  *Flag;            /*"例如失压发生标志"*/
		unsigned char  *eventflag;       /*"例如失压电量错误标志"*/
		unsigned char  Offset;          
};
//struct PREPFIRSTEVENT_STRU2    //mw added 2009-09-03
//{
//		TSpec_Event    Function;         /*"同上"*/
//		unsigned int   eeprom_addr;
//		unsigned char  *Flag;
//		unsigned char  Offset;
//		unsigned char  length;
//};   

struct CLEAREVENT_STRU    //mw added 2009-09-03
{
		unsigned int	   Eeprom_addr;                    /*"事件内卡存储地址"*/
		unsigned int     Pointer_addr;                   /*"指针内卡地址"*/
		unsigned int     Times_addr;                     /*"累计次数内卡地址"*/
		unsigned int     Ticks_addr;		                 /*"累计时间内卡地址"*/	
		unsigned char    *Pointer;  		                 /*"指针"*/
		unsigned char    *Flag;                          /*"发生标志"*/
		unsigned char    *Eventflag;                     /*"电量调整标志"*/
		unsigned long    *Times;                         /*"累计次数"*/
		unsigned long    *Ticks;	                       /*"累计时间"*/
		unsigned char    Offset; 		                     /*"发生标志在EVENT_POWER_NET_FLAG 结构中的偏移位置"*/		
		unsigned char    Length;                         /*"长度"*/
		unsigned int     Filename_begin;                 /*"文件起始"*/
		unsigned int     Filename_end;  	               /*"文件结束"*/	
		//union BYTE_BIT   Dispose_clearevent_flag;        /*"配置标志，根据配置分解处理"*/		
		unsigned char    Dispose_flag;        /*"配置标志，根据配置分解处理"*/			
}; 
struct REFRESHDATA_STRU    //mw added 2009-09-03
{
		unsigned int	    EE_flash_addr;                    /*"事件内卡存储地址"*/
		unsigned int        Ticks_addr;		                 /*"累计时间内卡地址"*/	
		unsigned long     *Ticks;	                       /*"累计时间"*/
		unsigned char     *Pointer;  		                 /*"指针"*/		
		unsigned char     *Flag;                          /*"发生标志"*/		
		unsigned char     Offset; 		                     /*"发生标志在EVENT_POWER_NET_FLAG 结构中的偏移位置"*/
		unsigned char     EE_File_Offset; 		                     
		unsigned char     EE_flash_select;             /*"EE OR FLASH选择"*/      		
		//unsigned char    Length;                         /*"长度"*/	
		//unsigned char    Dispose_flag;        /*"配置标志，根据配置分解处理"*/			
}; 
struct VOLTCHECK_STRU    //mw added 2009-09-03
{ 		
		unsigned char  *Flag1;            
		unsigned char  *Flag2;            		
}; 
struct PD_CURRENT_STRUCT
{
    unsigned long Pd_Max_curr;
	  unsigned long Aver_curr;
	  
	  unsigned char validflag[8];
};     
struct COM_SHOW_TABLE
{
   unsigned char  address0;                        /*"ID对应的格式表地址"*/
   unsigned int   address1;                        /*"ID对应的显示配置表地址"*/
};
struct Show_Powerdown_Data_Struct
{
    struct SHOW_POWEN_DATA_fLAG
    {
        unsigned char vatiryflag:1;
        unsigned char falshDatalen:7;
    }Show_FlashData_flag;
    unsigned char showbuff[6];
    struct  COM_SHOW_TABLE  Powerdown_show_table;
};

struct	PDOPENCOVERRECORD_STRUCTURE
{
	unsigned char startyear;
	unsigned char startmonth;
	unsigned char startday;	
	unsigned char starthour;			
	unsigned char startmin;			
	unsigned char startsec;
	
	unsigned char opencoverflag;	   
};

struct	PDOPENCOVER_STRUCTURE
{
	struct PDOPENCOVERRECORD_STRUCTURE startrecord[3];
	unsigned char recordnum;
	unsigned char validflag[8];	   
};

struct	PDVOLT_STRUCTURE
{
	unsigned long volt[3];
	unsigned long maxvolt;
	
	unsigned char validflag[8];	   
};

union EVENTSTATUS
{
   struct
   {
       unsigned char powertreverse:1;
       unsigned char powerdownopencover:1;
       unsigned char powerdownopenbox:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
   }bit;
   unsigned char byte;                                          
};

struct	EVENTREADNODEALSTRUCTURE
{
	unsigned char id3minvalue;
	unsigned char	id3maxvalue;
	unsigned char id2minvalue;
	unsigned char	id2maxvalue;
	unsigned char id1minvalue;
	unsigned char	id1maxvalue;
	unsigned char id0minvalue;
	unsigned char	id0maxvalue;
	unsigned long *eventtimespointer;   
};

union EVENTPOWERONDEALFLAG
{
       struct
       {
         unsigned char b0:1;  //calculate amphour 
         unsigned char b1:1;  //write event to eeprom
         unsigned char b2:1;  //event timeticks
         unsigned char b3:1;  //clear event flag
         unsigned char b4:1;  //lost voltage add energy
         unsigned char b5:1;  //lost voltage end time
         unsigned char b6:1;  //write event to flash
         unsigned char b7:1;  //max demand of over demand

         unsigned char b8:1;  //max imbalance rate
         unsigned char b9:1;
         unsigned char b10:1;
         unsigned char b11:1;
         unsigned char b12:1;
         unsigned char b13:1;
         unsigned char b14:1;
         unsigned char b15:1;	   
       }bit;
       unsigned int  intd;                                          
};

struct	RST90E36_STRUCTURE
{
	unsigned long totalnum;
	
	unsigned char beginflag;
	unsigned int  counter;
	
	unsigned char time[5];
	unsigned int praerrnum;
	unsigned int rderrnum;
	unsigned int valerrnum;   
};

struct EVENT_REPORT_STATUS_TIMES
      {
       unsigned char Switch_err_times;/*"负荷开关误动作或拒动"*/
       unsigned char ESAM_err_times;/*"ESAM故障"*/
       unsigned char Eeprom_init_err_times;/*"内卡初始化故障"*/
       unsigned char Clock_Battery_Volt_low_times;/*"时钟电池电压低"*/
       unsigned char Code_err_times;/*"内部程序错误"*/
       unsigned char Memorizer_err_times;/*"存储器故障或损坏"*/
       unsigned char NO_Use0;
       unsigned char Clock_err_times;/*"时钟故障"*/

	unsigned char LowPower_Battery_Volt_low_times;/*"低功耗电池欠压"*/
       unsigned char Overdraft_times;/*"欠费状态"*/
       unsigned char Open_Meter_Cover_times;/*"开表盖"*/
       unsigned char Open_Rail_Cover_times;/*"开端盖"*/
       unsigned char ConstantMagnet_event_times;/*"恒定磁场干扰"*/
       unsigned char PowerAbnormal_event_times;/*"电源异常"*/
       unsigned char Switch_off_times;/*"跳闸"*/
       unsigned char Switch_on_times;/*"合闸"*/

	unsigned char LostVolt_A_times;/*"A相失压"*/
       unsigned char LowVolt_A_times;/*"A相欠压"*/
       unsigned char OverVolt_A_times;/*"A相过压"*/
       unsigned char LossCurr_A_times;/*"A相失流"*/
       unsigned char OverCurr_A_times;/*"A相过流"*/
       unsigned char UpLoad_A_event_times;/*"A相过载"*/
       unsigned char PowerReserve_A_times;/*"A相功率反向"*/
       unsigned char BreakPhase_A_event_times;/*"A相断相"*/

	unsigned char BreakCurr_A_times;/*"A相断流"*/
       unsigned char NO_Use1;
       unsigned char NO_Use2;
       unsigned char NO_Use3;
       unsigned char NO_Use4;
       unsigned char NO_Use5;
       unsigned char NO_Use6;
       unsigned char NO_Use7;

	unsigned char LostVolt_B_times;/*"B相失压"*/
       unsigned char LowVolt_B_times;/*"B相欠压"*/
       unsigned char OverVolt_B_times;/*"B相过压"*/
       unsigned char LossCurr_B_times;/*"B相失流"*/
       unsigned char OverCurr_B_times;/*"B相过流"*/
       unsigned char UpLoad_B_event_times;/*"B相过载"*/
       unsigned char PowerReserve_B_times;/*"B相功率反向"*/
       unsigned char BreakPhase_B_event_times;/*"B相断相"*/

	unsigned char BreakCurr_B_times;/*"B相断流"*/
       unsigned char NO_Use8;
       unsigned char NO_Use9;
       unsigned char NO_Use10;
       unsigned char NO_Use11;
       unsigned char NO_Use12;
       unsigned char NO_Use13;
       unsigned char NO_Use14;

	unsigned char LostVolt_C_times;/*"C相失压"*/
       unsigned char LowVolt_C_times;/*"C相欠压"*/
       unsigned char OverVolt_C_times;/*"C相过压"*/
       unsigned char LossCurr_C_times;/*"C相失流"*/
       unsigned char OverCurr_C_times;/*"C相过流"*/
       unsigned char UpLoad_C_event_times;/*"C相过载"*/
       unsigned char PowerReserve_C_times;/*"C相功率反向"*/
       unsigned char BreakPhase_C_event_times;/*"C相断相"*/

	unsigned char BreakCurr_C_times;/*"C相断流"*/
       unsigned char NO_Use15;
       unsigned char NO_Use16;
       unsigned char NO_Use17;
       unsigned char NO_Use18;
       unsigned char NO_Use19;
       unsigned char NO_Use20;
       unsigned char NO_Use21;

	unsigned char VoltReverse_times;/*"电压逆相序"*/
       unsigned char CurrReverse_event_times;/*"电流逆相序"*/
       unsigned char VoltImbalance_times;/*"电压不平衡"*/
       unsigned char CurrImbalance_times;/*"电流不平衡"*/
       unsigned char auxiliaryPower_event_times;/*"辅助电源失电"*/
       unsigned char PowerDown_event_times;/*"掉电"*/
       unsigned char OverDemand_times;/*"超需量"*/
       unsigned char Factor_Low_times;/*"功率因数超下限"*/

	unsigned char CurrCriticalImbalance_times;/*"电流严重不平衡"*/
       unsigned char TotalPowerReverse_times;/*"总功率反向"*/
       unsigned char AllLostVoltage_times;/*"全失压"*/
       unsigned char NO_Use22;
       unsigned char NO_Use23;
       unsigned char NO_Use24;
       unsigned char NO_Use25;
       unsigned char NO_Use26;

       unsigned char Program_event_times;/*"编程"*/
       unsigned char Meter_clear_times;/*"电表清零"*/
       unsigned char Demand_clear_times;/*"需量清零"*/
       unsigned char Event_clear_times;/*"事件清零"*/
       unsigned char AdjustTime_event_times;/*"校时事件"*/
       unsigned char ProgDailySlot_times;/*"时段表编程"*/
       unsigned char ProgYearSlot_times;/*"时区表编程"*/
       unsigned char ProgWeek_times;/*"周休日编程"*/

       unsigned char ProgHoliday_times;/*"节假日编程"*/
       unsigned char ProgAEMode_times;/*"有功组合方式编程"*/
       unsigned char ProgNEMode1_times;/*"无功组合方式1编程"*/
       unsigned char ProgNEMode2_times;/*"无功组合方式2编程"*/
       unsigned char ProgBillDay_times;/*"结算日编程"*/
       unsigned char ProgTriffPrice_times;/*"费率参数编程"*/
       unsigned char ProgStepPrice_times;/*"阶梯表编程"*/
       unsigned char PSWUpdate_times;/*"密钥更新"*/
      };
union EVENTSTATUS_FLAG
{
   struct
   {
       unsigned char PowerAbnormal_event:1;
       unsigned char Meter_clear:1;
       unsigned char Demand_clear:1;
       unsigned char Event_clear:1;
       unsigned char AdjustTime_event:1;
       unsigned char ProgDailySlot:1;
       unsigned char ProgYearSlot:1;
       unsigned char ProgWeek:1;
       
       unsigned char ProgHoliday:1;
       unsigned char ProgAEMode:1;
       unsigned char ProgNEMode1:1;
       unsigned char ProgNEMode2:1;
       unsigned char ProgBillDay:1;
       unsigned char ProgTriffPrice:1;
       unsigned char ProgStepPrice:1;
       unsigned char PSWUpdate:1;

       unsigned char auxiliaryPower_event:1;
       unsigned char Eeprom_init_err :1;/*"内卡初始化错误"*/
       unsigned char Memorizer_err:1;/*"存储器故障或损坏"*/
       unsigned char powertreverse:1;/*"潮流反向"*/
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       /*"该字节用于无事件记录内容且实时判断状态类，实时判断的不能统一清状态"*/
       unsigned char Overdraft:1;/*"透支"*/
       unsigned char Switch_on:1;/*"成功合闸"*/
       unsigned char ESAM_err:1;/*"ESAM 错误"*/
       unsigned char Switch_err:1;/*"内置继电器错误"*/
       unsigned char Clock_err:1;/*"运行时钟乱"*/
       unsigned char Clock_Battery_Volt_low :1;/*"时钟电池欠压"*/
       unsigned char LowPower_Battery_Volt_low:1;/*"低功耗电池欠压"*/
       unsigned char Switch_off:1;
       
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
   }bit;
   unsigned char byte[5];                                          
};	  
#endif

/****************************************--------end------***********************************/
 
