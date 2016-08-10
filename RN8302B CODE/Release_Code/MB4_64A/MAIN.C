#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "multi.h"
#include "initram.h"
#include "LoadRecord.h"
#include "Demand.h"
#include "att7022_operation.h"
#include "seg.h" 
#include "MB_Keymain.h"
#include "MB_Showmain.h"
#include "freeze.h"
#include "Measure_Interface.h" 
//#include "MB_Iccard.h"
#include "datachange.h"

#include "pay_def.h"
#include "ICcard.h"	//payment
#include "Ex_Pay_For_Fun.h"
#include "Ex_Cpucard_Driver.h"
#include "Wireless.h"

#include "Far_pay.h"
#include "BackLight_Ctrl.h"

//-----------------public variable-----------------------------
struct DATEANDTIME_DEF            MainSoftDate;  /*"主时钟"*/

volatile unsigned long                     XXCC[4];        
volatile unsigned long                     Freq[4]; 
volatile unsigned long                     Volt[3];
volatile unsigned long                     Voltc[3];
volatile unsigned long                     Curr[3];
volatile unsigned long                     Factor[4];           
volatile unsigned long                     Active_power[4];
volatile unsigned long                       Active_energy_per_sec;
volatile unsigned long                     Reactive_power[4];
volatile unsigned long                       Reactive_energy_per_sec;
volatile unsigned long                     Visual_power[4];
volatile unsigned char                     Reactive_phase[4];
volatile unsigned long                     Phase_Angle[4];

volatile unsigned long        		  N_Current;     /*"零线电流"*/

 struct DATEANDTIME_DEF            MainRamDate1={0};  /*"时钟备份1"*/

volatile struct METER_STATES               Meter_States;

volatile struct NEW645METER_STATES             NEW645Meter_States;//Fxf 081112

volatile struct METER_PARAMETER            Meter_Parameter;

union EVENT_POWER_NET_FLAG       Event_Power_Net_Flag;   /*"电网事件记录标志"*/
//struct EVENT_METER_PROGRAM_FLAG   Event_Meter_Program_Flag;//mw closed 2009-10-09
struct EVENT_POWER_NET_POINTER    Event_Power_Net_Pointer; /*"电网事件记录指针"*/
struct EVENT_METER_PRO_POINTER    Event_Meter_Pro_Pointer;/*"电表事件记录指针"*/
struct EVENT_POWER_NET_TIMES      Event_Power_Net_Times;/*"电网事件记录次数"*/
struct EVENT_METER_PRO_TIMES      Event_Meter_Pro_Times;/*"电表事件记录次数"*/
struct EVENT_POWER_NET_TIMETICKS  Event_Power_Net_Timeticks;/*"电网事件记录累计时间"*/

struct DATEANDTIME_DEF            MainRamDate2;  /*"时钟备份2"*/

struct POWERDOWN_SAVE_DATA        Powerdown_Save_Data;

struct ENERGY_RAIL_ADD_BUFFER     energy_rail;

struct THIS_MONTH_DATA            This_Month_Data;

//struct MINUTE_COPY_ENERGY         Minute_Copy_Energy;  /*"内存电量备份"*/

//struct LOSSVOLTAGE_ENERGY         LossVoltage_Energy;  /*"失压电量"*/  //change by pc 081124

//struct LOSSCURRENT_ENERGY         LossCurrent_Energy;  /*"失流电量"*/  //change by pc 081124

//struct TOTAL_POWERRESERVE_ENERGY  PowerReserve_Energy;  /*"反向电量"*/  //change by pc 081124

struct POWERRESERVE_ENERGY_SING   CurrentImbalance_Energy[3];  /*"电流不平衡电量"*/

struct OTHER_DATA                 Other_Data;

struct ENERGY_POWERDOWN           Cal_PowerDown_Energy_add; /*"掉电保存电量"*/

union  CoBuff                     Co={0};                  /*"公用缓冲区，中断不能使用"*/

unsigned char                     WriteWhitchEeprom[3];    /*"对于从内卡读数据，备份内卡选择标志"*/

union  BYTE_BIT                   TimeChontrolFlag;       /*"程序时间控制标志"*/
union  BYTE_BIT                   ProgramRunPhaseFlag;    /*"上电程序运行阶段标志"*/
union  BYTE_BIT                   WriteTimeFlag;          /*"其他标志"*/
union  BYTE_BIT                   Event_Time_Flag;        /*"事件记录"*/
union  BYTE_BIT                   Alarm_Map_Flag[3];      /*"事件记录已发生标志"*/

struct OTHER_METER_PARAMETER      O1ther_Meter_Parameter; /*"掉电保存的某些参数"*/

unsigned char                     Max_Triff_Current=0; /*" 当前最大费率"*/
volatile unsigned long            Active_power_Per_Mintue=0;    /*" 一分钟有功平均功率"*/
//unsigned char                     Single_Voltage_Down_70_Persent;  /*"单相电压低于70％标志"*/
volatile int Temperature_Current;//fxf20090512
unsigned char sec_deal_flag;//ganjp 20090304
struct Show_Powerdown_Data_Struct Show_Powerdown_Cyc_Data[99];
struct Show_Powerdown_Data_Struct Show_Powerdown_Key_Data[120];// lfy changed 2011-03-15
unsigned char Show_ID_vatiy;
union EVENT_POWER_NET_FLAG       Show_Powerdown_Net_Flag_Backup;   
unsigned char Show_flash_poweron_vatiy;
unsigned char show_which_now;
///unsigned char ad_sample_cnt;/*"AD采样间隔"*/


void main (void)
{
	unsigned int uni;	
       
	uni=F_EEPROM_FLAG_ROM+64L;
	if(uni > PAY_EEPROM_DEFINE_EE)	//
		while(1);	

	/*"以上为程序错误检测程序"*/	

	asm("FCLR I");
	asm("FCLR I");
	
	InitMainRegeist();
	  
	InitPort();
    	 BackLight_Ctrl(POWER_UP_LIGHT_MODE,0,0,FULLSCREEN_EVENT);
	Relay_Deal_Init();	//payment
	Cpu_Card_IO_Init();
	//p7_7=1;		/*"背光打开"*/
	
	FeedWatchdog();
	Check_IIC_State();
	CheckPowerDown(); 
	
       //IniEeprom();  
       CheckEeprom();  
	
	FeedWatchdog();  	
	
	CheckPowerDown();
		
	IniRam(); 
	
	FeedWatchdog();
	Output_On_3_In_1_Terminal_Set(0);
	//Light_Back_Led();            
	
	CheckPowerDown();
	
	FeedWatchdog();
	asm("FCLR I");
	IniUART();
	
//	IniMeasure();
	
	FeedWatchdog();
	
	CheckPowerDown();
//	/*"显示初始化 2008-7-9 11:53:36"*/
//	Show_Initialize(0);
	/*"按键初始化 2008-7-9 11:53:30"*/
	Key_Initialize(0);
	/*"红外遥控初始化 2008-7-9 11:53:29"*/
	Init_IR_Ctrl();
	/*"IC卡读卡器初始化 2008-7-9 11:53:27"*/	
//	IC_Reader_Init();
	
	FeedWatchdog();
	
	CheckPowerDown();
	
	if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==0)/*"时钟同步按照老方案处理"*/
	{
	Demand_New_Init();
	}	
	
	FeedWatchdog();

 	ReadRTC();	
   
	InitInterrupt();
	
	IniUART();
	
	int2ic &= 0xf8;
	fgMeter_PowerOn_Init();
	int2ic |= 0x01;
	 
	Run_Triff_Switch(0);	//payment
	Esam_Err_Count = 0;
	Far_Identity_Auth_Ok_Flag=0;
	
	int2ic &= 0xf8;
	InitLoadRecord();
	CheckPowerDown();
	int2ic |= 0x01;  
	//-------------ganjp 20090901--------	
	if (Meter_Parameter.parameter1.MeterTypeMode.bit.b7)
		RST_ZB=0;
    /*" 上电复位第1次自检，上电过程中检测3次，3次都错误即认为ESAM错误"*/
	Esam_Remain_Money_Do(1);				/*"Li_远程表上电复位自检"*/	
	Delay(200); 
	if (Meter_Parameter.parameter1.MeterTypeMode.bit.b7)
		RST_ZB=1;
	Delay(300); 
	if (ESAM_ERR_DEFINE)
	{/*" 上电复位第2次自检，上电过程中检测3次，3次都错误即认为ESAM错误"*/
		Esam_Remain_Money_Do(1);
	}	
	FeedWatchdog();
	Delay(500); 
	if (ESAM_ERR_DEFINE)
	{/*" 上电复位第3次自检，上电过程中检测3次，3次都错误即认为ESAM错误"*/
		Esam_Remain_Money_Do(1);
	}
       ESAM_ErrReport();
	Poweron_Event_Show_Data();
	//-------------ganjp 20090901--------
	FeedWatchdog();
	Check_If_Clear_all();
	ClearClockBatteryTime();
	FullScreenTime = Meter_Parameter.parameter2.PowerOnFullScreenTime*1000;///king chen modify 130220
	cyc_show_time=GetNowTime();//lfy 090928


	Full_show_time = GetNowTime();//payment
   if(O1ther_Meter_Parameter.WorkRoomState)
   {
	   Full_show_time_Limit =15000;///king chen modify 121214
   }
   else
   {
    if(FullScreenTime>powerup_init_time)
    {
       Full_show_time_Limit =FullScreenTime -powerup_init_time;/*"上电初始化时间为5秒"*/
    }
    else
    {
      Full_show_time_Limit =0;  
    }
   }

//	Far_Comm_Init_NO = 0;
	
//	key_flag.bit.b0 = 0;
	int2ic &= 0xf8;
	EventFlagPowerOnInit();
	SoundAlarmInit();
	int2ic |= 0x01;
	
	ProgrammeEventEnd_Check();
	
       ///int2ic &= 0xf8;
	///O1ther_Meter_Parameter.PowerOnDayfreeze_flag=0;///king chen mark 130425
	///WRLC256(POWERONDAYFREEZE_FLAG_ROM ,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen modify 130228
	///O1ther_Meter_Parameter.PowerOnRetort_flag=0;
	///WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322
       ///int2ic |= 0x01;
	   
  ///BACK_LIGHT_ON=0; /*"上电时应全屏显示5s，开白色背光"*////king chen mark 121214
	meter_model_ok=GetNowTime();///king chen add 130104
	VoltageGreaterThanThreshold_Flag = 1;/*"上电初始认为电压正常，防止上电没出电压数据时处理异常"*/
	get_meter_para_from_esam();
	
    do                  
        {     
           IntoPowerDownFlag=0;             
           FeedWatchdog(); 
        
           int2ic &= 0xf8;
           Meter_Para_Check();
           int2ic |= 0x01;
           /*"通讯"*/
           int2ic &= 0xf8;
           Communication(0,0,0);
           int2ic |= 0x01;
           
           int2ic &= 0xf8;
           Key_Main();	
           int2ic |= 0x01;
           
		ICcard_Main();	//payment
           
           int2ic &= 0xf8;
           Measure();
           int2ic |= 0x01;
           
           int2ic &= 0xf8;
           SoundAlarmEndCheck();
           int2ic=0x01;
           
           CheckPowerDown();
           
           int2ic &= 0xf8;
           Monitor_Program();
           int2ic |= 0x01;
           
           int2ic &= 0xf8;
           ///Close_Back_Light();///king chen mark 130306
           Pay_Led();	//XN
           int2ic |= 0x01;

           //int2ic &= 0xf8;
           //Clear_PasswordErr(0,0);
           //int2ic |= 0x01;
           
           int2ic &= 0xf8;
           CheckProgramKeyState();
           int2ic |= 0x01;
           ProgrammeEventEnd_Check();
		int2ic &= 0xf8;
          Buzzer_Active();	//payment
          Remain_Money_Alarm_Judge();
			Relay_Deal(0);
		 int2ic |= 0x01;

	    BackLight_driver();

           if(OneMinute)         //0s 0ms
           {

              int2ic &= 0xf8;
		if((Meter_Parameter.parameter1.MeterMode[0].bit.b7==0) ||(demand_start == 0xff))
		{
		    if((Freq[0] != 0) || (auxiliary_power_flag == 1))//----ganjp 20090901
		    {
		         Demand_New_Main();
		    }
		}		
           	int2ic |= 0x01;
			
           demand_start = 0xff;/*"上电、清需量、校时后整分开始需量周期计算"*/
	    if((Meter_Parameter.parameter1.MeterMode[0].bit.b7==1) && (demand_start == 0xff) && (demand_init == 0))
	    	{
	    	int2ic &= 0xf8;
	    	Demand_New_Init();
		demand_init = 0xff;
		int2ic |= 0x01;
	    	}
                
           	
           	/*"冻结 2008-7-9 15:28:41"*/
           int2ic &= 0xf8;
           Freeze_Main();
           int2ic |= 0x01;
					 
           	int2ic &= 0xf8;
        	Bill_New();
        	int2ic |= 0x01;
        	
        	VoltStatisticFunc();
        	
        		int2ic &= 0xf8;
        	//CheckTriffDateChange(1);
        	CheckChange(1,FOR_TRIFF_DATE);//modify by zlp
        	int2ic |= 0x01;

					int2ic &= 0xf8;
					//CheckDailySlotDateChange(1);
					CheckChange(1,FOR_DAILYSLOT_DATE);//modify by zlp
        	int2ic |= 0x01;
					
        	int2ic &= 0xf8;
        	CalWeek((unsigned char *)&MainSoftDate);
        	int2ic |= 0x01;
        	
        	int2ic &= 0xf8;
        	Seg();
        	int2ic |= 0x01;
        	
        	int2ic &= 0xf8;
        	FindTriff();  /*"费率变化后，备份电量"*/
        	int2ic |= 0x01;
        	
        	int2ic &= 0xf8;
		    if((Freq[0] != 0) || (auxiliary_power_flag == 1))
			{
                Minute_Power(1);
                SaveLoadRecord();
			}
        	int2ic |= 0x01;
        	
        	OneMinute=0;
        	
        	int2ic &= 0xf8;
        	EventTimeAdd();
        	int2ic |= 0x01;

            int2ic &= 0xf8;
            Check_Max_Imbalance_Rate();
            int2ic |= 0x01;

        	int2ic &= 0xf8;
			    Esam_Remain_Money_Do(0);
        	int2ic |= 0x01;
            
        	int2ic &= 0xf8;
        	ESAM_ErrReport();
         	int2ic |= 0x01; 
            
        	int2ic &= 0xf8;
        	Para_Process_run();
        	int2ic |= 0x01;

		Pay_Minute_Act();
        
           }
           	 
           if(OneSecond)
           	{
               
		int2ic &= 0xf8;
		p3_2=0;

		if(fgJustParaHandler())
		{
		       Key_Main();
			Measure_Deal_Every_Second();
			Key_Main();
			Middle_Energy_Accumulation_PerSecond_Main_Program();
		}
		int2ic |= 0x01;

     Meter_Staut_Check_And_Count();///king chen add 121214
     int2ic &= 0xf8;
		 Set_or_Clear_LCD_Flash_Flag();
		 int2ic |= 0x01;
                
                int2ic &= 0xf8;
                Calculate_Arccos_FA();						
                int2ic |= 0x01;
                
                int2ic &= 0xf8;
        	CheckRamTime();
        	int2ic |= 0x01;
        	
			int2ic &= 0xf8;
		//payment
		Pre_Display_Char_Flash();
        	Buzzer_Second_Active();		
        	Run_Triff_Switch(1);
        	int2ic |= 0x01;
        	
        	OneSecond=0;
        	CheckState();
		CheckState_New645(); 
        #if 0
        int2ic &= 0xf8;
        ad_sample_cnt++;
        if(ad_sample_cnt>1)
        {
          ad_sample_cnt=0;
        	ReadDisplayBatteryVoltage();
        	ReadClockBatteryVoltage();
        }
        int2ic |= 0x01;
        #endif
        
       int2ic &= 0xf8;
        	 Clear_ALLEventReportInfo_NO_ACK();
       int2ic |= 0x01;
            
        New2007_Event();   
       int2ic &= 0xf8;
		    Event_Report_Status_Chk(1);
       int2ic |= 0x01;     	
                Minute_Power(0);
               //=====ganjp 20091127================

            	Reset_Wireless_State();
            	GPRS_Signal_Stength_Lcd_show();
				
		BackLight_RemainTime_Dec();
               //=====ganjp 20091127================
           	}     
           
           
        }while(1);   

}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
