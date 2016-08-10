/**************************************************************************************************
*                      fine:     defmcro.h                                                        *
*                      function: define macro                                                     *
***************************************************************************************************/ 

#ifndef  _defmcro_h_
#define  _defmcro_h_

#include "sfr64a.h"

//====================/*"�����"*/================================================
/*"����-->x0:����;x1:�ز�+����;2:����+Ҫ��;x3..."*/
#define METER_TYPE_SEL		0x01

/*"ȫʧѹ�ж�ģʽ---->1:����5s����������Դ����һ�ε����ж��Ƿ�����ȫʧѹ����
                                           ---->0:��������ȫʧѹ����ź��ж�"*/
#define ALLLOSSVOLTAGE_MODE            1

/*"=====����ģ�鶨��====="*/	//payment
#define MODULE_LOCAL_PAY_FLAG		0	/*"���طѿ�	-->1:��,��"*/
#define MODULE_FAY_PAY_FLAG		0	/*"Զ�̷ѿ�	-->1:��,��"*/
#define MODULE_CARRIER_FLAG		0	/*"�ز�ģ��	-->1:��,��(˫485)"*/

#define CODE_SIZE_FLAG		0	/*"0:��ȥ�Ĵ��룬��ʡ�ռ�"*/

//================================================================================


//------------define macro---------------------------------------------
#define ISPTCONECT              1      //1-CT conect,0-CT not conect

#define MAXTRIFF	            9      // total + 8 tariff     
#define MAXYEARSLOT             14	   //OLD VALUE=8,MODIFYIED BY LIAO DIHONG  //FUXF 12->14 081113
#define MAXDAILYSLOTTABLE       8
#define MAXDAILYSLOT            14	   //OLD VALUE=10,MODIFYIED BY LIAO DIHONG
#define MAXHOLIDAYSLOT          254	//FUXF 120->254 081113
#define MAXMONTHSAVE            14
#define MAX_NUMBER_FREEZE_TIME           72                    /*" ��ʱ�������    "*/
#define MAX_NUMBER_FREEZE_MOMENT              16                    /*" ˲ʱ�������    "*/
#define MAX_NUMBER_FREEZE_TRIFF_CHANGE             16          /*" ʱ���л��������    "*/
#define MAX_NUMBER_FREEZE_DAILYSLOT_CHANGE             16           /*" ʱ�α��л��������    "*/
#define MAX_NUMBER_FREEZE_DAY              72          /*" �ն������    "*/
#define MAX_NUMBER_FREEZE_PERIOD          254          /*" ���ڶ������    "*/
#define MAX_NUMBER_FREEZE_ENERGYPASSZERO          16          /*" ���ڶ������    "*/
#define MAXDAUTOVALUE  6   //max demical number of demand show
#define MAX_PASS_NUM	5	 /*"�����ټ�����"*/


#define Munsignedchar  0
#define Mchar          1
#define Mint           2
#define Munsignedint   3
#define Mlong          4
#define Munsignedlong  5
#define Mfloat         6
#define MMDDhhmm       7
#define YYMMDD         8
#define HHMMSS         9
#define bcd8d2         0x0a
#define bcd8d3         0x0b
#define bcd8d4         0x0c
#define Mlongd3        0x0d
#define Mauto          0x0e
#define None	       0x0f
#define bcd4d0	       0x10
#define bcd4d2         0x11
#define bcd6d4	       0x12
#define bcd4d3         0x13 
#define Dauto          0x14
#define WEEK           0x15
#define MMDD           0x16
#define hhmm           0x17	
#define MMDDNN         0x18	
#define hhmmNN         0x19
#define NN_H	       0x1A	
#define NN_L           0x1B	
#define Event_ActiveEnergy   0x1c
#define Event_REActiveEnergy 0x1d
#define Event_BeginDate      0x1e
#define Event_EndDate        0x1f	
#define Event_Timeticks      0x21	
#define Event_Times          0x22	
#define YYMMDDhhmm           0x20
#define Error                0x23
#define BIN                  0x24 
#define BYTE0_BIN            0x25 
#define BYTE1_BIN            0x26 
#define BYTE2_BIN            0x27 
#define BYTE3_BIN            0x28 
#define BYTE4_BIN            0x29 
#define BYTE5_BIN            0x2A 
#define NN_MMDD            0x2B 

#define Ubcd8d2         0x3a   //defined by mw080131
#define Ubcd8d3         0x3b
#define Ubcd8d4         0x3c


#define SHOWFORMAT         0xfd //defined by fxf 080131

#define COMMFORMAT         0xfe

#define bcd8d0         0xff


#define DL_PROTOCOL    0x00
#define ZJ_PROTOCOL    0x01
#define WS_PROTOCOL    0x02
#define DL_AND_ZJ_PROTOCOL 0x03
#define DL_AND_WS_PROTOCOL 0x04
#define DL_AND_WS_AND_ZJ_PROTOCOL 0x05


//----------I/O port define--------------
#define	FLASH_CS	                 p0_0	//  
//#define	R_DIR                    p0_1	//
#define	A_EOUT                   p0_2	//
#define	R_EOUT                   p0_3	//
//#define	TDK71M6515_SIG_PORT         p0_4	//
#define	RLAY_OPEN                  p0_5	//
//#define	TDK71M6515_RESET_PORT       p0_6	//Reset mesuring ATT7022
//#define	TDK71M6515_CS_PORT          p0_7	//Chip_Select mesuring ATT7022 



    
#define	CPUCARD_CLK	       p1_0 
///#define	LED_ALARM                p1_1  ///king chen mark 121214 
#define	CPU_CARD_RXD          p1_2	 
#define	CPU_CARD_TXD          p1_3	  
#define	J1                               p1_4   //Meter_Clear and Meter_Calibration Jump
#define	ALL_V_LOSS               p1_5   //All_Voltage_Loss Signal 
#define	LOSE_VOLT_ALARM    p1_6   /*"�ϵ籨����"*/
#define	LASER_WKP                p1_7 	//Laser Wakeup
			
#define	ESAM_PWR                                  p2_0	//ESAM POWER CONTROL
#define	CONSTANT_MAGNET_DET           p2_1	/*"�㶨�ų����ż��"*/
#define	LCD_SCL                                      p2_2	//LCD_DRIVER_WR_CLK_PORT
#define	BACK_LIGHT_ON                         p2_3	//
#define	ALTER_MAGNET_DET                  p2_4   /*"����ų����ż��"*/
#define	KEY6                                            p2_5   /*"���˸Ǽ�ⰴ��"*/
#define	LOWPOWER_BAT_VOLT               p2_6   /*"�͹��ĵ�ص�ѹ"*/
#define	CLOCK_BAT_VOLT                       p2_7   /*"ʱ�ӵ�ص�ѹ"*/
		
#define	RTC1_SDA                   p3_0    
#define	RTC1_SCL                    p3_1    
#define	MEM_PWR                    p3_2   /*"�ڿ���Դ����"*///20050604 
#define	ALARM_SND                p3_3   /*"����������"*///20050604 
#define	RELAY_STATUS           p3_4  /*"���ü̵���״̬����"*/
#define	ALARM                         p3_5	/*"�������"*/ 
#define	SECOND_EN                p3_6	//Enable second pulse to output from auxiliary terminals (#15,#16) 
#define	DEMAND_TIME_SW     p3_7	//Demand_cycle/TIME SWITCH		//payment
	
	
	
#define	    CPUCARD_PWR                   p4_0	//IC card interfacor power control
#define	    CPUCARD_RST                   p4_1    
#define	    MK_EVENT                         p4_2    /*"�¼��ϱ�֪ͨ����"*/ 
#define	    ESAM_RST                         p4_3    
#define	    HT_1623_CS                     p4_4    
#define	    CPUCARD_SW                    p4_5	//IC card is presen or absent.  
#define	    PSAM_RXD                   p4_6	//IC card interfacor is failure.
#define	    PSAM_TXD                   p4_7	//
	
	
	
#define	VBB                      p5_0   //Allways connect to Vbb 
#define	VB1_OK                   p5_1	//Status of RTC1's battery
#define	NC                p5_2   ///*"����7022�������Դ����"*/ 
#define	VB3_OK1                  p5_3	//External battery's status (circuit_short test)
#define	RST_ZB                  	 p5_4   /*"��λ���͵�ƽ��Ч��"*/ 
#define	VSS                      p5_5   //Allways connect to GND
#define	MEM_SCL                  p5_6    
#define	MEM_SDA                  p5_7    
	
	
	
#define	MEM_WP                   p6_0    
#define	RE_DE0                   p6_1	//Tx/Rx control of 1st RS485
#define	RXD0                     p6_2    
#define	TXD0                     p6_3    
#define	WDI                      p6_4   //Updating signal of Watchdog chip 
#define RE_DE1                   p6_5	//Tx/Rx control of 2st RS485
#define	RXD1                     p6_6    
#define	TXD1                     p6_7    
	
	
	
#define	TXD2                     p7_0    
#define	RXD2                     p7_1    
#define	PWM                      p7_2	//38.4kHz signal used to modify ir remote transmit 
#define	IR_FAR_PWR               p7_3   //0:select IR_FAR Rx,1:select OPTICAL_HEADER Rx
#define	SDA_LCD                  p7_4    
#define	ATT7022_CF1              p7_5    
#define	PSAM_CLK                 p7_6   
#define	NC1                            p7_7	
	
	
	
#define	LCD_POWER                   p8_0	//IR_FAR circuit power control
#define	REMOTE_CONTROL_IN   p8_1	/*"ң��������"*/
#define	SECONG_PULSE             p8_2	//Second Pulse from DS3231 
#define	KEY5                              p8_3	//METER COVER
#define	V_D                      p8_4   //Power_Drop Signal 
#define	VCC1                     p8_5	//Always connected to VBB 
#define	XCOUT                    p8_6    
#define	XCIN                     p8_7    

#define	TDK71M6515_CLK_PORT         p9_0   
#define	TDK71M6515_TXD_PORT         p9_1   
#define	TDK71M6515_RXD_PORT         p9_2   
#define	PULSE_WID_MESURE         p9_3   /*"38kHZ�ֳ����ź�"*/
#define	ATT7022_CF2                 p9_4   
#define	DB161_SCK                p9_5   
#define	DB161_SI                 p9_6   
#define	DB161_SO                 p9_7   
	                        
	
//#define	CTR_KG	                 p10_1//  	
#define	SWITCH_TOGGLE    p10_0	/*"��բ�̵������"*/
#define	MODULE_STA          p10_1	 /*"ͨ��ģ�����ʱ��ַƥ����ȷ���0.2s�ߵ�ƽ;���͹�������ߵ�ƽ"*/	//payment
#define	A_EOU1                     p10_2	/*"�й�������"*/
#define	R_EOU1                     p10_3	/*"�޹�������"*/
#define KEY1                     p10_4	     //#S1 PUSHBUTTON
#define MK_SET                     p10_5	    /*"ģ��ʹ��"*/
#define	KEY3                      p10_6	//#S3 PUSHBUTTON
#define	PULSE_PWR           p10_7	/*"����7022�������Դ����"*/ 

#define    EVENT_CLAER_STATUS    0xa5



#define OneMinute                TimeChontrolFlag.bit.b0
#define OneSecond                TimeChontrolFlag.bit.b1
#define TenMinute                TimeChontrolFlag.bit.b2
#define ThirtydMinute            TimeChontrolFlag.bit.b3
#define TwoMinute                TimeChontrolFlag.bit.b4
#define OneMinuteThirtS          TimeChontrolFlag.bit.b5
#define Time500flag              TimeChontrolFlag.bit.b6
#define FirstIntoPowerDownFlag   TimeChontrolFlag.bit.b7



#define IF_Powerup_Savedata      ProgramRunPhaseFlag.bit.b0   //0-not save data when power up ,1-have saved 
#define IF_Powerup_Readdata      ProgramRunPhaseFlag.bit.b1   //0-not read data when power up ,1-have read 
#define IF_Powerup_Billdata      ProgramRunPhaseFlag.bit.b2   //0-not bill  when power up ,1-have billed 
#define Meter_331_LostVoltage_B_break  ProgramRunPhaseFlag.bit.b3   //0-not bill  when power up ,1-have billed 


#define WriteTimeFlag_Demand     WriteTimeFlag.bit.b0
#define Comm_Key_Clear_Demand    WriteTimeFlag.bit.b1
#define Program_Key_Flag         WriteTimeFlag.bit.b2
#define Program_Key_Up_Flag      WriteTimeFlag.bit.b3
#define OpenRailCover_Flag       WriteTimeFlag.bit.b4
#define OpenUpCover_Flag         WriteTimeFlag.bit.b5
#define ChangeFromSubToMainCLK   WriteTimeFlag.bit.b6
#define ClosePowerDownComm       WriteTimeFlag.bit.b7

#define OneSecond_Event          Event_Time_Flag.bit.b0
#define OneSecond_Eventb         Event_Time_Flag.bit.b1
#define OneMinute_Event          Event_Time_Flag.bit.b2
#define OneMinute_Eventb         Event_Time_Flag.bit.b3
#define MainSubClockChange       Event_Time_Flag.bit.b4
#define MainSubClockChangew      Event_Time_Flag.bit.b5
#define AlarmDelayFlag           Event_Time_Flag.bit.b6
#define DemandOutPutflag         Event_Time_Flag.bit.b7

#define OP_RD   1
#define OP_WR   0
#define WRLC256                  Write_Read_FM24C256
#define WEEK_END_STATES          Meter_Parameter.Week_Status.byte;
#define softdate                 MainSoftDate
//add by zlp
#define  FM24C256_1AND2   12
   
#define Setbit(x,y)  ((x)|=(1<<(y)) )/*"��X�ĵ�Yλ��1,KC"*/
#define Clrbit(x,y)  ((x)&=~(1<<(y))) /*"��X�ĵ�Yλ��0,KC"*/

#define  A_SEG    0x01
#define  B_SEG    0x02
#define  C_SEG    0x04

 #define ADDROF_ASCREEN   0x01
 #define ADDROF_B_R0M       0x20

#define FOR_TRIFF_DATE                 0x01         
#define  FOR_DAILYSLOT_DATE         0x02
//add end
//-------------------------Event BeginFile-------------------------//
#define  LOSTVOLT_A_BEGINFILE                         0L
#define  LOSTVOLT_B_BEGINFILE                         32L
#define  LOSTVOLT_C_BEGINFILE                         64L
#define  POWERDOWNEVENT_BEGINFILE                     96L
#define  PROGRAMMEEVENT_BEGINFILE                     128L
#define  CLEARMETEREVENT_BEGINFILE                    160L
#define  OPENCOVEREVENT_BEGINFILE                     192L
#define  VOLTSTATISTIC_A_BEGINFILE                    224L
#define  VOLTSTATISTIC_B_BEGINFILE                    256L
#define  VOLTSTATISTIC_C_BEGINFILE                    288L
#define  LOSTCURR_A_BEGINFILE                         320L
#define  LOSTCURR_B_BEGINFILE                         352L
#define  LOSTCURR_C_BEGINFILE                         384L
#define  BREAKPHASE_A_BEGINFILE                       416L
#define  BREAKPHASE_B_BEGINFILE                       448L
#define  BREAKPHASE_C_BEGINFILE                       480L
#define  VOLTREVERSE_BEGINFILE                        512L
#define  OVERPAADEMAND_BEGINFILE                      544L
#define  OVERNEADEMAND_BEGINFILE                      576L
#define  POWERREVERSE_A_BEGINFILE                     608L
#define  POWERREVERSE_B_BEGINFILE                     640L
#define  POWERREVERSE_C_BEGINFILE                     672L
#define  ADJUSTTIMERECORD_BEGINFILE                   704L
#define  CLEARDEMANDRECORD_BEGINFILE                  736L
#define  CLEAREVENTRECORD_BEGINFILE                   768L
#define  PROGWEEKRECORD_BEGINFILE                     800L
#define  PROGAEMODERECORD_BEGINFILE                   832L
#define  PROGNEMODE1RECORD_BEGINFILE                  864L
#define  PROGNEMODE2RECORD_BEGINFILE                  896L
#define  PROGBILLDAYRECORD_BEGINFILE                  928L
#define  PROGYEARSLOTRECORD_BEGINFILE                 960L
#define  OPENBOXEVENT_BEGINFILE                       992L
#define  OVERVOLT_A_BEGINFILE                         1024L
#define  OVERVOLT_B_BEGINFILE                         1056L
#define  OVERVOLT_C_BEGINFILE                         1088L
#define  PHASE3LOSTVOLT_BEGINFILE                     1120L
#define  OVERPOWERALARM_BEGINFILE                     1152L
#define  OVERPOWERSWIT_BEGINFILE                      1184L
#define  CLOCKBATTERYEVENT_BEGINFILE                  1216L
#define  DISPLAYBATTERYEVENT_BEGINFILE                1248L
#define  ADJUSTMETERRECORD_BEGINFILE                  1280L
#define  RESETCPUEVENT_BEGINFILE                      1312L
#define  CURRIMBALANCEEVENT_BEGINFILE                 1344L
#define  VOLTIMBALANCEEVENT_BEGINFILE                 1376L
#define  ADJUSTTIMEOVERTRECORD_BEGINFILE              1408L
#define  VOLTDOWN_A_BEGINFILE                         1440L
#define  VOLTDOWN_B_BEGINFILE                         1472L
#define  VOLTDOWN_C_BEGINFILE                         1504L
#define  OVERCURR_A_BEGINFILE                         1536L
#define  OVERCURR_B_BEGINFILE                         1568L
#define  OVERCURR_C_BEGINFILE                         1600L
#define  UPLOAD_A_BEGINFILE                           1632L
#define  UPLOAD_B_BEGINFILE                           1664L
#define  UPLOAD_C_BEGINFILE                           1696L
#define  CURRREVERSE_BEGINFILE                        1728L
#define  OVERFACTOR_BEGINFILE                         1760L
#define  FAILCURR_A_BEGINFILE                         1792L
#define  FAILCURR_B_BEGINFILE                         1824L
#define  FAILCURR_C_BEGINFILE                         1856L
#define  SETPRIMARYRECORD_BEGINFILE                   1888L
#define  RUNCLOCKERR_BEGINFILE                        1920L
#define  POWERUPCLOCKERR_BEGINFILE                    1952L
#define  EEPROMERR_BEGINFILE                          1984L
#define  PROGDAILYSLOTRECORD_BEGINFILE                2016L
#define  PROGDAILYSLOTRECORD_2_BEGINFILE              2048L
#define  PROGDAILYSLOTRECORD_3_BEGINFILE              2080L
#define  ADJUSTENERGY_1_BEGINFILE                     2112L
#define  ADJUSTENERGY_2_BEGINFILE                     2144L
#define  OVER1RDEMAND_BEGINFILE                       2176L
#define  OVER2RDEMAND_BEGINFILE                       2208L
#define  OVER3RDEMAND_BEGINFILE                       2240L
#define  OVER4RDEMAND_BEGINFILE                       2272L
#define  OVERFACTOR_A_BEGINFILE                       2304L
#define  OVERFACTOR_B_BEGINFILE                       2336L
#define  OVERFACTOR_C_BEGINFILE                       2368L
#define  POWERREVERSE_T_BEGINFILE                     2400L
#define  CONSTANTMAGNET_BEGINFILE                     2432L
#define  POWERABNORMAL_BEGINFILE                      2464L
#define  VOLTSTATISTIC_T_BEGINFILE                    2496L
#define  CURRFARIMBALANCE_BEGINFILE                   2528L
#define  EVENTBEGINFILEEND                            2559L
//-------------------------Event BeginFile-------------------------//
//----------------------------------------------------------------------
//----------Fuxf added 10415-------------------------------------------
/*"�¼���"*/
#define PAGE_NUM_PER_SECTOR_EVENT                           16               /*"ÿ����ҳ��"*/
#define MAX_BYTE_NUM                                        256              /*"ÿҳ�ֽ���"*/
#define MAX_FILE_EVENT_SORT_NUM                             3200L         /*"(�¼���)�ļ���"*/
#define EVENT_SORT_START_FILE                               0     /*"(�¼���)�ļ���ʼ�ļ�"*/
#define FILE_EVENT_SORT_STARTPAGE                           0x200000     /*"(�¼���)�ļ���ʼҳ��"*/

/*"������"*/
#define PAGE_NUM_PER_SECTOR_FREEZE                          8              /*"ÿ�����ļ���"*/
#define MAX_BYTE_NUM_FREEZE                                 512           /*"ÿҳ�ֽ���"*/
#define FILE_FREEZE_SORT_STARTPAGE                          0x2C8000     /*"��ʱ�����ļ���ʼҳ��"*/
#define FREEZE_SORT_START_FILE                              3200L     /*"��ʱ������ʼ�ļ�"*/

#define MAX_FILE_FREEZE_TIME_SORT_NUM                       72         /*"��ʱ�����ļ���"*/
#define FREEZE_TIME_SORT_START_FILE                         3200L     /*"��ʱ������ʼ�ļ�"*/
#define FILE_FREEZE_TIME_SORT_STARTPAGE                     0x2C8000     /*"��ʱ�����ļ���ʼҳ��"*/

#define MAX_FILE_FREEZE_MOMENT_SORT_NUM                     16        /*"˲ʱ�����ļ���"*/
#define FREEZE_MOMENT_SORT_START_FILE                       3272L    /*"(�¼���)�ļ���ʼ�ļ�"*/
#define FILE_FREEZE_MOMENT_SORT_STARTPAGE                   0x2D1000     /*"˲ʱζ���ļ���ʼҳ��"*/

#define MAX_FILE_FREEZE_TRIFF_CHANGE_SORT_NUM               16        /*"����ʱ�����л������ļ���"*/
#define FREEZE_TRIFF_CHANGE_SORT_START_FILE                 3288L    /*"(�¼���)�ļ���ʼ�ļ�"*/
#define FILE_FREEZE_TRIFF_CHANGE_STARTPAGE                  0x2D3000    /*"����ʱ�����л�����ʼҳ��"*/

#define MAX_FILE_FREEZE_DAILYSLOT_CHANGE_NUM                16         /*"ʱ�α��л������ļ���"*/
#define FREEZE_DAILYSLOT_CHANGE_START_FILE                  3304L   /*"(�¼���)�ļ���ʼ�ļ�"*/
#define FILE_FREEZE_DAILYSLOT_CHANGE_STARTPAGE              0x2D5000     /*"ʱ�α��л�����ļ���ʼҳ�?*/

#define MAX_FILE_FREEZE_DAY_NUM                             72         /*"�ս��ļ���"*/
#define FREEZE_DAY_START_FILE                               3320L /*"(�¼���)�ļ���ʼ�ļ�"*/
#define FILE_FREEZE_DAY_STARTPAGE                           0x2D7000     /*"�ն���ļʼҳ��"*/

#define MAX_FILE_FREEZE_ENERGYPASSZERO_NUM                  16         /*"������ת�����ļ���"*/
#define FREEZE_ENERGYPASSZERO_START_FILE                    3392L   /*"������ת�����ļ���ʼ�ļ�"*/
#define FILE_FREEZE_ENERGYPASSZERO_STARTPAGE                0x2E0000     /*"������ת����ļʼҳ��"*/


#define PROGRAMTRIFF_EVENT_FILE					3408L	/*"���ʱ��̼�¼"*/		//payment
#define PROGRAMTRIFF_EVENT_NUMBER				24		/*"���ʱ��̼�¼����"*/

#define TRIFF_SWITCH_EVENT_FILE					3432L	/*"���ʵ���л�����"*/
#define TRIFF_SWITCH_EVENT_NUMBER             	16

#define STEP_SWITCH_EVENT_FILE					3448L	/*"�ݶȵ���л�����"*/
#define STEP_SWITCH_EVENT_NUMBER             	16

#define RET90E36_EVENT_FILE					    3464L
#define RST90E36_EVENT_NUMBER           24

#define MAX_FILE_FREEZE_NUM                                 3488L         /*"(freeze)�ļ���"*/

#define WORKROOMSTATE_RUNTIME                              10L*24L*3600L  ///king chen add 121214
#define METER_MODEL_ERROR_RUNTIME                          24L*3600L*1000L  ///king chen add 130104
#define METER_POWERUP_INITTIME                          5000UL  

#endif                                
/****************************************--------end------***********************************/
                            
                            
                        
