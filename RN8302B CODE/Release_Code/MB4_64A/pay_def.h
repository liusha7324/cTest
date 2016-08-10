#ifndef PAY_DEF_H
#define PAY_DEF_H

#include "pay_Mac.h"

#define NUM_ERR_TO_HANG     200     /*"多少次错误后电表挂起"*/
#define AUTH_ERR_LIMIT      100     /*"连续认证错误多少次后不再认证 默认15"*/

#define NUM_PSW_INFO        32       /*"密钥总条数"*/
#define BIT_MASK_ALL_PSW_UPD    ((1UL << NUM_PSW_INFO) - 1UL) /*"所有密钥都已经更新位图"*/
#define SZ_PSW_INFO         36      /*"单条密钥长度(包含了密钥信息)"*/
#define SZ_PSW_INFO_MAC     (36 + 4)/*"单条密钥加MAC长度"*/

#define Pay_Eeprom_Buffer   Co.b                                /*" 缓冲区复用 "*/


#define	ALARM_BUZZER_DIRECT            pd3_3
#define	ALARM_BUZZER                   p3_3   /*"蜂鸣器控制"*///20050604 



#define	SWITCH_CLEW              p1_6   /*"继电器状态指示"*/
#define	SWITCH_CLEW_DIRECT       pd1_6   /*"继电器状态指示"*/

#define SIG_TRIFF                      0x01
#define Mul_TRIFF                      0x02

#define DOUT_MONEY_BOTTOM         100000l
//#define MAX_STEP                                 8
#define MAX_STEP                                 6			//Li Update 20121231   /*"梯度数"*/
#define PRE_MAX_TRIFF                       32          //MAXTRIFF


#define	RELAY_TYPE_SEL				p0_1	/*"继电器方式->0:外置,1:内置"*/ 

#define	RST_ZB_DIRECT            			pd5_4
//#define	RST_ZB              	  			p5_4   	/*"复位（低电平有效）"*/ 
/*"报警输出"*/
#define	ALARM_RELAY_DIRECT          	pd3_5
#define	ALARM_RELAY                    	p3_5
	/*"外置继电器"*/
#define	SWITCH_RELAY_DIRECT    	 		pd10_0		//pd3_4
#define	SWITCH_RELAY             	  		p10_0   	//p3_4
	/*"内置继电器"*/
#define	SWITCH_OPEN_DIRECT           	 	pd10_0  	//pd3_4
#define	SWITCH_OPEN                   		p10_0  		//p3_4	//SWITCH_TOGGLE Relay open Signal
#define	SWITCH_CLOSE_DIRECT        		pd0_5
#define	SWITCH_CLOSE                   	p0_5	//SWITCH_TOGGLE Relay close Signal

#define SWITCH_STATUS_CHECK_DIRECT		pd3_4
#define SWITCH_STATUS_CHECK				p3_4




union Int_To_Char
    {
    unsigned int U_int;
    unsigned char U_char[2];
    };
union Long_To_Char
    {
    unsigned long U_long;
    unsigned int U_int[2];
    unsigned char U_char[4];
    };    

struct FARCONTROLEVENT
{
	unsigned long farSwitch_Ticks;
	unsigned long farClose_Ticks;
};
#define FARSWITCH_TICKS_EE			FARCONTROLEVENT_EE
#define FARSCLOSE_TIMES_EE			FARSWITCH_TICKS_EE+4




//-------------3 byte-----------------------
struct YEAR_BILLDATE_DEF				//Li Update 20130104
{
       unsigned char Month;
       unsigned char Day;
	   unsigned char Hour;
};


//-------------4 byte-----------------------
struct PRE_YEAR_BILLDATE_DEF				//Li Update 20130104
{
       unsigned char YEAR;
       unsigned char Month;
	   unsigned char Day;
	   unsigned char Hour;
};

struct PRE_MONTH_BILLDATE_DEF
{
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Min;
};

/*"**********************************************************************************"*/
/*"**********************************************************************************"*/


/*"**********************************************************************************"*/
//struct _Pre_Power_Down_Save_Data
//    {
//      signed long Remain_Money;                     /*" 剩余电费 0.01元 "*/
//    unsigned long Remain_Money_bottom;              /*" 剩余电费尾数 0.0001元 "*/
//	//unsigned long Total_User_Money;                 /*" 累计用电金额 "*/
//	//unsigned long Far_On_Time;                      /*" 远程跳闸总时间 "*/
//    unsigned long Energy_Next_Step;                 /*" 距下一阶梯的剩余电量 "*/
//    unsigned long Month_Total_Energy;               /*" 月电量 "*/
//    unsigned int  Crc_Cs;                           /*" CRC效验和 "*/
//    };
//#define LENGTH_PRE_POWER_DOWN_SAVE_DATA       sizeof( struct _Pre_Power_Down_Save_Data )
#define LENGTH_PRE_POWER_DOWN_SAVE_DATA     sizeof( struct PRE_SAVE_DATA)

/*"**********************************************************************************"*/
/*" 掉电不需要保存的预付费数据 "*/
/*" RAM "*/
struct _Pre_Payment_Data
    {
    unsigned long Last_Buy_Money;			   		/*" 上次购电金额 0.01元    HEX  "*/
    unsigned long Total_Buy_Money;			  		/*" 累计购电金额 0.01元    HEX  "*/
	unsigned long Bef_Month_Total_Energy;			/*"上一月电量 "*/	
	unsigned long Bef_Year_Total_Energy[4];			/*"上1~4年度组合有功总累计用电量 "*/
	struct  PRE_YEAR_BILLDATE_DEF Year_Total_Energy_Date;   /*"当前年度组合有功总累计时间"*/
	struct  PRE_YEAR_BILLDATE_DEF Pre_Year_BillDate[4];		/*"上1次年结算日结算时间 - 上4次年结算日结算时间 "*/
	unsigned char oprateCode[4];
	unsigned long CurrMoneyT;						/*"当前分时电费 "*/
	unsigned char HangMeterNum;						/*"电表挂起次数 "*/
	unsigned int  OPCard_StatusByte;				/*"插卡状态字"*/
	unsigned char Esam_Identity[5];					/*"ESAM厂家识别码"*/
    unsigned char OverPowerSw_Time;					/*"过负荷跳闸次数"*/
	unsigned char Reserve_User[4];					/*"暂时保留"*/
	
	unsigned char Year_Bill_Point;					/*"年冻结指针"*/
	
	struct FARCONTROLEVENT FARCONTROLEVENT;			/*"拉/合闸次数"*/
	unsigned long TriffProgNum;						/*"费率编程总次数"*/
	unsigned long StepProgNum;						/*"梯度编程总次数"*/
	unsigned long Relay_Error_Num;					/*"负荷开关误动作总次数"*/
    unsigned long Back_Money_Count;            		/*"退费总次数"*/
    unsigned long Far_Key_Updata_Count;            	/*"远程修改密钥总次数"*/
	unsigned long OPCard_Error_Num;					/*"异常插卡总次数"*/
    unsigned long Unlawful_Card_Count;            	/*"非法插卡次数"*/

//    unsigned int  	Total_Buy_Money_Over_Time;              /*" 累计购电金额溢出次数   "*/
//    unsigned long 	Total_Duct_Base_Money;                  /*" 累计扣除基本电费 0.01元    HEX  "*/
//    unsigned int  	Total_Duct_Base_Money_Over_Time;        /*" 累计扣除基本电费溢出次数   "*/
//    unsigned long 	Total_Duct_Hire_Money;                  /*" 累计扣除变损电费 0.01元    HEX  "*/
//    unsigned int  	Total_Duct_Hire_Money_Over_Time;        /*" 累计扣除变损电费溢出次数   "*/	
//    unsigned char   Last_Buy_Time[5];             /*"最近售电时间"*/
//    unsigned char   PowerDownTime[6];             /*"掉电时间"*/
//	  unsigned char E_Burse_BuyNum;					/*"电子钱包购电次数"*/
//    unsigned long Far_On_Count;                   /*"远程跳闸总次数 "*/
//    unsigned long Step_Switch_Count;              /*"梯度切换总次数 "*/
//    unsigned int  Triff_Updata_Count;       		/*"电价修改总次数 "*/
//    unsigned long Step_Updata_Count;              /*"梯度修改总次数 "*/
//	  unsigned char Month_Bill_Point;				/*"月冻结指针"*/

    unsigned int    Crc_Cs;                         /*" CRC效验和 "*/
    };
#define LENGTH_PRE_PAYMENT_DATA       sizeof( struct _Pre_Payment_Data )
    #define LAST_BUY_MONEY_EE                    	PRE_PAYMENT_DATA_EE			// 4
    #define TOTAL_BUY_MONEY_EE                     	LAST_BUY_MONEY_EE+4			// 4
	#define Bef_Month_Total_Energy_EE				TOTAL_BUY_MONEY_EE+4		// 4
	#define Bef_Year_Total_Energy_EE				Bef_Month_Total_Energy_EE+4	// 4*4
	#define YEAR_TOTAL_ENERGY_DATE_EE				Bef_Year_Total_Energy_EE+4*4// 4
	#define PRE_YEAR_BILLDATE_EE					YEAR_TOTAL_ENERGY_DATE_EE+4	// 4*4
	#define OPRATECODE_EE							PRE_YEAR_BILLDATE_EE+4*4	// 4
	#define CURRMONEYT_EE							OPRATECODE_EE+4			// 4
	#define HANGMETER_EE							CURRMONEYT_EE+4			// 1
	#define OPCARD_STATUSBYTE_EE					HANGMETER_EE+1			// 2
	#define Esam_Identity_EE						OPCARD_STATUSBYTE_EE+2	// 5
	#define OVERPOWERSW_TIME_EE						Esam_Identity_EE+5		// 1
	#define RESERVE_USER_EE							OVERPOWERSW_TIME_EE+1	// 4

	#define Year_Bill_Point_EE                     	RESERVE_USER_EE+4		// 1

	#define FARCONTROLEVENT_EE						Year_Bill_Point_EE+1	// 8
	#define TriffProgNum_EE							FARCONTROLEVENT_EE+8	// 4
	#define StepProgNum_EE							TriffProgNum_EE+4		// 4
	#define Relay_Error_Num_EE						StepProgNum_EE+4		// 4
	#define Back_Money_Count_EE				 		Relay_Error_Num_EE+4	// 4
	#define Far_Key_Updata_Count_EE					Back_Money_Count_EE+4	// 4
	#define OPCARD_ERROR_NUM_EE						Far_Key_Updata_Count_EE+4// 4
    #define UNLAWFUL_CARD_COUNT_EE					OPCARD_ERROR_NUM_EE+4	// 4

//	#define E_BURSE_BUYNUM_EE							Relay_Error_Num_EE+4
//  #define MONTH_BILL_POINT_EE						(E_BURSE_BUYNUM_EE+1)
//	#define LAST_BUY_TIME_EE							 OVERPOWERSW_TIME_EE+4
//	#define FAR_ON_COUNT_EE                            LAST_BUY_TIME_EE+5
//	#define PowerDownTime_EE                     	FAR_ON_COUNT_EE+4
//  #define TRIFF_UPDATA_COUNT_EE                     PowerDownTime_EE +6
//	#define STEP_SWITCH_COUNT_EE                      TRIFF_UPDATA_COUNT_EE +2
//	#define STEP_UPDATA_COUNT_EE                      STEP_SWITCH_COUNT_EE+4
//    #define TOTAL_BUY_MONEY_OVER_TIME_EE             TOTAL_BUY_MONEY_EE+4
//    #define TOTAL_DUCT_BASE_MONEY_EE                 TOTAL_BUY_MONEY_OVER_TIME_EE+2
//    #define TOTAL_DUCT_BASE_MONEY_OVER_TIME_EE       TOTAL_DUCT_BASE_MONEY_EE+4
//    #define TOTAL_DUCT_HIRE_MONEY_EE                 TOTAL_DUCT_BASE_MONEY_OVER_TIME_EE+2
//    #define TOTAL_DUCT_HIRE_MONEY_OVER_TIME_EE       TOTAL_DUCT_HIRE_MONEY_EE+4

/*"**********************************************************************************"*/
/*" 预付费参数 "*/
/*" RAM "*/
struct _Pre_Payment_Para
    {
    unsigned long Base_Money;                         /*" 基本电费 0.01元    HEX  "*/
    unsigned long Hire_Money;                         /*" 变损电费 0.01元    HEX  "*/
    unsigned long Remain_Money_Alarm1_Limit;          /*" 剩余电费显示报警门限1 0.0001元    HEX  "*/
    unsigned long Remain_Money_Alarm2_Limit;          /*" 剩余电费跳闸报警门限2 0.0001元    HEX  "*/
    unsigned long Remain_Money_Tick_Limit;            /*" 剩余电费赊欠门限 0.0001元    HEX  "*/
    unsigned long Remain_Money_Hoard_Limit;           /*" 剩余电费囤积门限 0.01元    HEX  "*/
    unsigned long Triff[2][PRE_MAX_TRIFF];               /*" 费率 0.0001元    HEX  "*/
    unsigned long Multiple;                           /*" 倍率 HEX  "*/
    unsigned long C_T;                                /*" CT HEX  "*/
    unsigned long P_T;                                /*" PT HEX  "*/
    unsigned char SysID[6];                           /*" 系统号 "*/
    unsigned char UserID[6];                          /*" 用户号 "*/
    unsigned char MeterID[6];                         /*" 表号 "*/
    unsigned char CardID;                         		/*"保留"*/
	unsigned char User_Kind;                          /*" 用户类型 "*/
    struct DATEANDTIME_DEF TriffSwitchDate;           /*" 新费率开始日期时间"*/
    struct DATEANDTIME_DEF StepSwitchDate;            /*" 新梯度开始日期时间"*/
    unsigned char Meter_Run_State;                    /*" 电表运行状态，00厂内/01安装/02运行 "*/	
    unsigned char Money_Point;                        /*" 电费小数位 "*/
    unsigned long Buy_Count;                          /*" 购电次数 "*/
    unsigned char Step_Num[2];                        /*"梯度数"*/
    unsigned long Energy_Step[2][MAX_STEP];                  /*"第X梯度值 X=1,2,3,4减少"*/
    unsigned long Triff_Step[2][MAX_STEP+1];                   /*"电价(费率)"*/

	struct YEAR_BILLDATE_DEF  Year_BillDate[2][4]; 			/*"年结算日"*/		//Li Update 20130104

	
    union Pay_For_Users_Flag1  Pay_For_Users_Flag1;   /*" 预付费报警状态字 "*/
    union Pay_For_Users_Flag2  Pay_For_Users_Flag2;   /*" 预付费模式字1 "*/
    union Pay_For_Users_Flag3  Pay_For_Users_Flag3;   /*" 预付费模式字2 "*/
    union Pay_For_Users_Flag4  Pay_For_Users_Flag4;   /*" 预付费模式字3 "*/
    union Pay_For_Users_Flag5  Pay_For_Users_Flag5;   /*" 周休日友好状态字 "*/
	union Pay_For_Users_Flag11 Pay_For_Users_Flag11;  /*" 拉合闸、报警特征字(国网备案文件要求) "*/
    union Pay_For_Users_Flag12 Pay_For_Users_Flag12;  /*" 自定义掉电保存标志字 "*/
    union Pay_For_Users_Flag13 Pay_For_Users_Flag13;  /*" 自定义掉电保存标志字 "*/
    union Pay_For_Users_Flag14 Pay_For_Users_Flag14;  /*" 自定义掉电保存标志字 "*/
    union Pay_For_Users_Flag15 Pay_For_Users_Flag15;  /*" 自定义掉电保存标志字 "*/

//    unsigned char Triff_Table[2][4];                  /*" 费率表"*/
//    unsigned long Energy_Step_Table[2][8][3];         /*" 梯度表"*/
//    unsigned long Triff_Step_Table[2][6][4];          /*" 梯度费率表"*/
	unsigned char InfrIdenTime;               /*"红外认证时效"*/  //infrared identification
	unsigned char Switch_Test_Num;			/*"继电器测试时动作次数"*/
	unsigned long Far_Key_StatusByte;        	/*"密钥状态字"*/	/*"Li_0 表示测试密钥(公钥),1 表示正式密钥(私钥) "*/
//	unsigned long OverPower_Plus_Limit;   			/*"最大功率,功率负荷脉冲数"*/
//	unsigned char Power_Period;      						/*"最大符合计算时间"*/
//	unsigned char	OverPower_Time_Limit;			/*"过负荷跳闸次数门限"*/

	unsigned long Para_Card_Version;           /*"现场参数设置卡版本号,上电初始化要请零"*/
	unsigned int CurrLimitProTime;                 /*"超拉闸控制电流门限保护延时时间(分钟)"*/
	//unsigned char Curr_Step_Point;                 /*"当前梯度费率指针"*/

	unsigned char PassWord_Kind;                 /*"密钥类型"*/
	unsigned long Close_Switch_Limit;           /*"剩余电费合闸限额"*/
	unsigned char TriffPriceNum;           		/*"抄读时使用的费率数"*/
	unsigned char Far_Day_Follow;			/*"远程认证日跟随"*/
	unsigned char Card_Reset_Inf[8];           /*"CPU卡序列号"*/
	unsigned int Far_Open_Delay;			 /*"跳闸延时(跳闸断电前告警时间)"*/
	unsigned int Far_Close_Delay;			 /*"预跳闸后合闸延时(合闸通电前告警时间)"*/
	unsigned int RelayActTime;			 	/*"外置继电器脉冲方式跳闸维持时间,单位:mS"*/
	unsigned int RelayActEnergy;			 /*"外置继电器脉冲方式再次跳闸电量,单位:Wh"*/
	unsigned long CurrLimit;			 		/*"继电器拉闸控制电流门限值(内置表电流超过XXX.XXXA时，24小时内不跳闸)"*/

	unsigned char PassWord_Num;				 /*"密钥总条数 "*/		//Li Update 20130104
	unsigned char psw_status;				 /*"密钥状态 (密钥更新成功的时候更新这个密钥状态为最新的)"*/

	unsigned int ID_Ins_Time;				/*"身份认证有效时间"*/

	unsigned long SendBack_Money;			/*"退费金额"*/

    unsigned int  Crc_Cs;                             /*" CRC效验和 "*/
    };
#define LENGTH_PRE_PAYMENT_PARA       sizeof( struct _Pre_Payment_Para )
    #define BASE_MONEY_EE                     PRE_PAYMENT_PARA_EE
    #define  HIRE_MONEY_EE                    BASE_MONEY_EE+4
    #define  REMAIN_MONEY_ALARM1_LIMIT_EE     HIRE_MONEY_EE+4
    #define  REMAIN_MONEY_ALARM2_LIMIT_EE     REMAIN_MONEY_ALARM1_LIMIT_EE+4
    #define  REMAIN_MONEY_TICK_LIMIT_EE       REMAIN_MONEY_ALARM2_LIMIT_EE+4
    #define  REMAIN_MONEY_HOARD_LIMIT_EE      REMAIN_MONEY_TICK_LIMIT_EE+4
    #define  TRIFF_EE                         REMAIN_MONEY_HOARD_LIMIT_EE+4
    #define  TRIFF2_EE					TRIFF_EE+(PRE_MAX_TRIFF)*4
    #define  MULTIPLE_EE                      	TRIFF2_EE+(PRE_MAX_TRIFF)*4
    #define  C_T_EE                           MULTIPLE_EE+4
    #define  P_T_EE                           C_T_EE+4
    #define  SYSID_EE                         P_T_EE+4
    #define  USERID_EE                        SYSID_EE+6
    #define  METERID_EE                       USERID_EE+6
    #define  CARDID_EE                        METERID_EE+6
	#define  USER_KIND_EE                       CARDID_EE+1
    #define  TRIFFSWITCHDATE_EE              USER_KIND_EE+1    
    #define  STEPSWITCHDATE_EE                TRIFFSWITCHDATE_EE+sizeof(struct DATEANDTIME_DEF)
    #define  METER_RUN_STATE_EE               STEPSWITCHDATE_EE+sizeof(struct DATEANDTIME_DEF)
    #define  MONEY_POINT_EE                   METER_RUN_STATE_EE+1 
    #define  BUY_COUNT_EE                     MONEY_POINT_EE+1
    #define  STEP_NUM_EE                      BUY_COUNT_EE+4
    #define  ENERGY_STEP_EE                   STEP_NUM_EE+2
    #define  ENERGY_STEP2_EE             		ENERGY_STEP_EE+(MAX_STEP*4)
    #define  TRIFF_STEP_EE                    		ENERGY_STEP2_EE+(MAX_STEP*4)
    #define  TRIFF_STEP2_EE				TRIFF_STEP_EE+((MAX_STEP+1)*4)
    #define  YEAR_BILLDATE_EE				TRIFF_STEP2_EE+((MAX_STEP+1)*4)		//Li Update 20130104
    #define  YEAR_BILLDATE2_EE			YEAR_BILLDATE_EE+12	

	#define  PAY_FOR_USERS_FLAG1_EE       	YEAR_BILLDATE2_EE+12		//TRIFF_STEP_EE+((MAX_STEP+1)*8)
	#define  PAY_FOR_USERS_FLAG2_EE        	PAY_FOR_USERS_FLAG1_EE+1
	#define  PAY_FOR_USERS_FLAG3_EE       	PAY_FOR_USERS_FLAG2_EE+1
	#define  PAY_FOR_USERS_FLAG4_EE       	PAY_FOR_USERS_FLAG3_EE+1
	#define  PAY_FOR_USERS_FLAG5_EE       	PAY_FOR_USERS_FLAG4_EE+1
	#define  PAY_FOR_USERS_FLAG11_EE     	PAY_FOR_USERS_FLAG5_EE+1
	#define  PAY_FOR_USERS_FLAG12_EE     	PAY_FOR_USERS_FLAG11_EE+1
	#define  PAY_FOR_USERS_FLAG13_EE     	PAY_FOR_USERS_FLAG12_EE+1
	#define  PAY_FOR_USERS_FLAG14_EE     	PAY_FOR_USERS_FLAG13_EE+1
	#define  PAY_FOR_USERS_FLAG15_EE     	PAY_FOR_USERS_FLAG14_EE+1
	
	//#define  TRIFF_TABLE_EE                   		PAY_FOR_USERS_FLAG15_EE+1
	//#define  ENERGY_STEP_TABLE_EE             	TRIFF_TABLE_EE+8
	//#define  TRIFF_STEP_TABLE_EE              	ENERGY_STEP_TABLE_EE+192

	#define  InfrIdenTime_EE              	PAY_FOR_USERS_FLAG15_EE+1
	#define  Switch_Test_Num_EE				InfrIdenTime_EE+1
	#define  FAR_KEY_STATUSBYTE_EE   		Switch_Test_Num_EE+1
	
	#define  PARA_CARD_VERSION_EE        		FAR_KEY_STATUSBYTE_EE+4
	#define  CurrLimitProTime_EE        		PARA_CARD_VERSION_EE+4
	
	#define  PASSWORD_KIND_EE                    CurrLimitProTime_EE+2
	#define  CLOSE_SWITCH_LIMIT_EE			PASSWORD_KIND_EE +1
	#define  TriffPriceNum_EE					CLOSE_SWITCH_LIMIT_EE+4
	#define  FAR_DAY_FOLLOW_EE				TriffPriceNum_EE+1
	#define  CARD_RESET_INF_EE				FAR_DAY_FOLLOW_EE+1
	#define  FAR_OPEN_DELAY_EE				CARD_RESET_INF_EE+8
	#define  FAR_CLOSE_DELAY_EE			FAR_OPEN_DELAY_EE+2
	#define  RELAYACTTIME_EE				FAR_CLOSE_DELAY_EE+2
	#define  RELAYACTENERGY_EE				RELAYACTTIME_EE+2
	#define  CURRLIMIT_EE					RELAYACTENERGY_EE+2
	
	#define  PASSWORDNUM_EE					CURRLIMIT_EE+4				/*"密钥条数"*/
    #define  PSW_STATUS_EE					(PASSWORDNUM_EE+1)
    #define  ID_INS_TIME_EE					(PSW_STATUS_EE+1)	 
	#define  SENDBACK_MONEY					ID_INS_TIME_EE+2

	
/*"**********************************************************************************"*/
/*" 预付费事件记录指针 "*/
/*" EE "*/
struct _Pay_For_Event_Point
    {
    unsigned char Buy_Event_P;                             /*" 购电事件记录指针 "*/
    unsigned char Far_Control_Event_P;                     /*" 远程跳闸事件记录指针 "*/
    unsigned char Far_Control_Free_Event_P;                /*" 远程跳闸解除事件记录指针 "*/
    unsigned char Triff_Switch_Event_P;                    /*" 费率切换事件记录指针 "*/
    unsigned char Step_Switch_Event_P;                     /*" 梯度切换事件记录指针 "*/
    unsigned char Remain_Money_Alarm1_Event_P;             /*" 剩余电费低于报警门限1事件记录指针 "*/
    unsigned char Remain_Money_Alarm2_Event_P;             /*" 剩余电费低于报警门限2事件记录指针 "*/
    unsigned char Remain_Money_Zero_Event_P;               /*" 剩余电费低于0事件记录指针 "*/
    unsigned char Remain_Money_Tick_Event_P;               /*" 剩余电费低于赊欠门限事件记录指针 "*/
    unsigned char Money_Balance_Event_P;                   /*" 预付费数据结算指针 "*/
    unsigned char Triff_Updata_Event_P;                    /*" 费率修改事件记录指针 "*/
    unsigned char Step_Updata_Event_P;                     /*" 梯度修改事件记录指针 "*/
    unsigned char Far_Key_Updata_Event_P;              	/*" 密钥更新事件记录指针 "*/	
	unsigned char OPCard_Error_Event_P;					/*" 插卡异常事件记录指针 "*/	//Li Update 20130106
	unsigned char Refundment_Event_P;						/*"退费金额事件记录指针"*/		//Li Update 20130106
	unsigned char RelayErr_Event_P;						/*"负荷开关误动作事件记录指针"*/	
	unsigned char YearBillDate_Event_P;					/*"年结算日事件记录指针"*/		//Li Update 20130109 
	unsigned char ProgramTriff_Event_P;						/*"费率表编程事件记录指针"*/	
	unsigned char ProgramStep_Event_P;						/*"梯度表编程事件记录指针"*/	
	unsigned char E_Burse_Event_P;							/*"电子钱包事件记录指针"*/
	unsigned char Month_Bill_Event_P;							/*"月结算日记录指针"*/
    unsigned int  Crc_Cs;                                  /*" 累加效验和 "*/
    };
#define LENGTH_PAY_FOR_EVENT_POINT       sizeof( struct _Pay_For_Event_Point )

#define BUY_EVENT_P_EE                       		PAY_FOR_EVENT_POINT_EE
#define FAR_CONTROL_EVENT_P_EE               	BUY_EVENT_P_EE+1
#define FAR_CONTROL_FREE_EVENT_P_EE    	FAR_CONTROL_EVENT_P_EE+1
#define TRIFF_SWITCH_EVENT_P_EE            	FAR_CONTROL_FREE_EVENT_P_EE+1
#define STEP_SWITCH_EVENT_P_EE            		TRIFF_SWITCH_EVENT_P_EE+1
#define REMAIN_MONEY_ALARM1_EVENT_P_EE 	STEP_SWITCH_EVENT_P_EE+1
#define REMAIN_MONEY_ALARM2_EVENT_P_EE 	REMAIN_MONEY_ALARM1_EVENT_P_EE+1
#define REMAIN_MONEY_ZERO_EVENT_P_EE       REMAIN_MONEY_ALARM2_EVENT_P_EE+1
#define REMAIN_MONEY_TICK_EVENT_P_EE       	REMAIN_MONEY_ZERO_EVENT_P_EE+1
#define MONEY_BALANCE_EVENT_P_EE           	REMAIN_MONEY_TICK_EVENT_P_EE+1
#define TRIFF_UPDATA_EVENT_P_EE             	MONEY_BALANCE_EVENT_P_EE+1
#define STEP_UPDATA_EVENT_P_EE              	TRIFF_UPDATA_EVENT_P_EE+1
#define FAR_KEY_UPDATA_EVENT_P_EE              	STEP_UPDATA_EVENT_P_EE+1
#define OPCARD_ERROR_EVENT_P_EE				FAR_KEY_UPDATA_EVENT_P_EE+1
#define REFUNDMENT_EVENT_P_EE					OPCARD_ERROR_EVENT_P_EE+1
#define RELAYERR_EVENT_P_EE					REFUNDMENT_EVENT_P_EE+1
#define YEARBILLDATE_EVENT_P_EE				RELAYERR_EVENT_P_EE+1
#define PROGRAMTRIFF_EVENT_P_EE 				YEARBILLDATE_EVENT_P_EE+1
#define PROGRAMSTEP_EVENT_P_EE				PROGRAMTRIFF_EVENT_P_EE+1
#define E_BURSE_EVENT_P_EE						PROGRAMSTEP_EVENT_P_EE+1
#define Month_Bill_EVENT_P_EE					E_BURSE_EVENT_P_EE+1
/*"**********************************************************************************"*/
#define BUY_EVENT_P_OFFSET                       		0
#define FAR_CONTROL_EVENT_P_OFFSET          			1
#define FAR_CONTROL_FREE_EVENT_P_OFFSET 				2
#define TRIFF_SWITCH_EVENT_P_OFFSET              	3
#define STEP_SWITCH_EVENT_P_OFFSET               	4
#define REMAIN_MONEY_ALARM1_EVENT_P_OFFSET			5
#define REMAIN_MONEY_ALARM2_EVENT_P_OFFSET 			6
#define REMAIN_MONEY_ZERO_EVENT_P_OFFSET   			7
#define REMAIN_MONEY_TICK_EVENT_P_OFFSET   			8
#define MONEY_BALANCE_EVENT_P_OFFSET        			9
#define TRIFF_UPDATA_EVENT_P_OFFSET       			10
#define STEP_UPDATA_EVENT_P_OFFSET         			11
#define FAR_KEY_UPDATA_EVENT_P_OFFSET         		12
#define OPCARD_ERROR_EVENT_P_OFFSET					13						//Li Update 20130106
#define REFUNDMENT_EVENT_P_OFFSET					14						//Li Update 20130106
#define RELAYERR_EVENT_P_OFFSET						15						//Li Update 20130106
#define YEARBILLDATE_EVENT_P_OFFSET					16
#define PROGRAMTRIFF_EVENT_P_OFFSET					17						//Li Update 20130107
#define PROGRAMSTEP_EVENT_P_OFFSET					18						//Li Update 20130107
#define E_BURSE_EVENT_P_OFFSET						19
#define Month_Bill_EVENT_P_OFFSET						20
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 以下为虚定义，无实体 "*/
/*"**********************************************************************************"*/
/*" 事件记录次数定义 "*/
#define BUY_EVENT_NUMBER                      		32L			/*"对应第一最大偏移量"*/
#define FAR_CONTROL_EVENT_NUMBER               		32L
#define FAR_CONTROL_FREE_EVENT_NUMBER     			32L
//#define TRIFF_SWITCH_EVENT_NUMBER             		32L
//#define STEP_SWITCH_EVENT_NUMBER               		32L
#define REMAIN_MONEY_ALARM1_EVENT_NUMBER   			32L
#define REMAIN_MONEY_ALARM2_EVENT_NUMBER  			32L
#define REMAIN_MONEY_ZERO_EVENT_NUMBER      			32L
#define REMAIN_MONEY_TICK_EVENT_NUMBER        		32L
#define MONEY_BALANCE_EVENT_NUMBER           		32L
#define TRIFF_UPDATA_EVENT_NUMBER              		32L
#define STEP_UPDATA_EVENT_NUMBER               		32L
#define FAR_KEY_UPDATA_EVENT_NUMBER               	32L
#define OPCARD_ERROR_EVENT_NUMBER					32L	

#define REFUNDMENT_EVENT_NUMBER						32L

#define RELAYERR_EVENT_NUMBER							32L
//#define PROGRAMTRIFF_EVENT_NUMBER					32L
#define PROGRAMSTEP_EVENT_NUMBER						32L
#define E_BURSE_EVENT_NUMBER							96L
#define Month_Bill_EVENT_NUMBER							32L
/*"**********************************************************************************"*/
/*" 文件名定义 "*/
/*"**********************************************************************************"*/
#define PAY_EVENT_FILE_NAME                 		2560L

#define BUY_EVENT_FILE 						(PAY_EVENT_FILE_NAME)											// 2560
#define FAR_CONTROL_EVENT_FILE 			(BUY_EVENT_FILE+BUY_EVENT_NUMBER)									// 2592
#define FAR_CONTROL_FREE_EVENT_FILE 		(FAR_CONTROL_EVENT_FILE+FAR_CONTROL_EVENT_NUMBER)				// 2624
//#define TRIFF_SWITCH_EVENT_FILE             	(FAR_CONTROL_FREE_EVENT_FILE+FAR_CONTROL_FREE_EVENT_NUMBER)	// 
//#define STEP_SWITCH_EVENT_FILE              	(TRIFF_SWITCH_EVENT_FILE+TRIFF_SWITCH_EVENT_NUMBER)			// 
#define FAR_KEY_UPDATA_EVENT_FILE              	(FAR_CONTROL_FREE_EVENT_FILE+FAR_CONTROL_FREE_EVENT_NUMBER)	// 2656
//#define REMAIN_MONEY_ALARM1_EVENT_FILE	
//#define REMAIN_MONEY_ALARM2_EVENT_FILE	
//#define REMAIN_MONEY_ZERO_EVENT_FILE        
//#define REMAIN_MONEY_TICK_EVENT_FILE 		
//#define MONEY_BALANCE_EVENT_FILE  		
//#define TRIFF_UPDATA_EVENT_FILE 			
//#define STEP_UPDATA_EVENT_FILE 			
#define OPCARD_ERROR_EVENT_FILE				(FAR_KEY_UPDATA_EVENT_FILE+FAR_KEY_UPDATA_EVENT_NUMBER)		// 2688	
#define REFUNDMENT_EVENT_FILE					(OPCARD_ERROR_EVENT_FILE+OPCARD_ERROR_EVENT_NUMBER)		// 2720
#define RELAYERR_EVENT_FILE					(REFUNDMENT_EVENT_FILE+REFUNDMENT_EVENT_NUMBER)				// 2752	
//#define PROGRAMTRIFF_EVENT_FILE1				(RELAYERR_EVENT_FILE+RELAYERR_EVENT_NUMBER)				// 
#define PROGRAMSTEP_EVENT_FILE				(RELAYERR_EVENT_FILE+RELAYERR_EVENT_NUMBER)					// 2784
#define E_BURSE_EVENT_FILE						(PROGRAMSTEP_EVENT_FILE+PROGRAMSTEP_EVENT_NUMBER)		// 2816
#define Month_Bill_EVENT_FILE					(E_BURSE_EVENT_FILE+E_BURSE_EVENT_NUMBER)				// 2848


#define PAY_EVENT_RECORD_END                		(Month_Bill_EVENT_FILE+Month_Bill_EVENT_NUMBER)		//2944	//MAX:3200

//#define PROGRAMTRIFF_EVENT_FILE		3048
/*"**********************************************************************************"*/


//-------------------------------------------------------------------------------------//
//Li Update 20130104
//-------------------------------------------------------------------------------------//
//-------------6 byte-----------------------
struct DATEANDTIME_6BYTE_DEF
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Min;
	unsigned char Sec;
};


struct _OPCard_Error_format
{
	//struct DATEANDTIME_6BYTE_DEF  Date;
	//unsigned char				   CardError;
	unsigned char				   CMD[5];
	unsigned char				   Response[2];
};

#define LENGTH_OPCARD_EEPROM_DEFINE       sizeof( struct _OPCard_Error_format )
//-------------------------------------------------------------------------------------//

struct upd_psw_info
{
	unsigned char psw_info[NUM_PSW_INFO][SZ_PSW_INFO_MAC];   /*"保存密钥信息(36字节struct Far_Deal_070301FF_format, 每条预留4字节的MAC)"*/
    unsigned long upd_flg;  /*"密钥更新位图: 对应位为1表示对应密钥更新到了EEPROM"*/
    unsigned char pwd_stat; /*"保存全局密钥状态，初始化为一个不可能被使用值，用于判断这个变量是否被真实更新 "*/
    unsigned char seq_num ; /*"记录密钥编号"*/
};
#define LEN_UPD_PSW_IF  sizeof(struct upd_psw_info)
#define UPD_PSW_INFO_EE (PAY_PSW_UPD_INFO_EE)
#define UPD_PSW_FLG     (UPD_PSW_INFO_EE + NUM_PSW_INFO * SZ_PSW_INFO_MAC)
#define UPD_PSW_STAT     (UPD_PSW_FLG + sizeof(unsigned long))
#define UPD_SEQ_NUM     (UPD_PSW_STAT+ 1)


/*"**********************************************************************************"*/
/*" EEPRON数据结构定义 "*/
/*"**********************************************************************************"*/
/*" EEPROM定义的预付费数据内卡结构 "*/
/*" 存放EEPRON0和EEPROM1 "*/

struct _Pay_Eeprom_Define
    {
	struct _Pre_Payment_Data               Pre_Payment_Data;              /*" 上电读，修改时写 "*/
    struct _Pre_Payment_Para               Pre_Payment_Para;              /*" 上电读，修改时写 "*/ 
    struct _Pay_For_Event_Point            Pay_For_Event_Point;           /*" 修改时读写 "*/
	unsigned char       					RelayErr_Area[29];     	 /*"继电器错误发生时用以保存数据的内卡空间"*/
	struct upd_psw_info 				psw_info;   			/*"保存密钥更新信息 包括密钥等"*/
	unsigned char    					Pre_Tmp[29];		/*"临时数据"*/	
    };
#define LENGTH_PAY_EEPROM_DEFINE       sizeof( struct _Pay_Eeprom_Define )


	#define PRE_PAYMENT_DATA_EE               PAY_EEPROM_DEFINE_EE
	#define PRE_PAYMENT_PARA_EE               PRE_PAYMENT_DATA_EE+LENGTH_PRE_PAYMENT_DATA
	#define PAY_FOR_EVENT_POINT_EE            PRE_PAYMENT_PARA_EE+LENGTH_PRE_PAYMENT_PARA

	#define RELAYERR_AREA_EE   				PAY_FOR_EVENT_POINT_EE+LENGTH_PAY_FOR_EVENT_POINT
	#define PAY_PSW_UPD_INFO_EE     		RELAYERR_AREA_EE+29
	#define Pre_Tmp_EE 						PAY_PSW_UPD_INFO_EE+sizeof(struct upd_psw_info)


/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
struct Event_format
    {
    unsigned char * Addr;
    unsigned int Length;
    };
struct Event_format_d
    {
    unsigned char format;
/*"BIT0：1：对应数据开始有效"*/
/*"BIT1：1：对应数据结束有效"*/
/*"BIT2：1：保留"*/
/*"BIT3：1：保留"*/
/*"BIT4：1：保留"*/
/*"BIT5：1：保留"*/
/*"BIT6：1：电量等4个字节的数据减法"*/
/*"BIT7：1：数据增量"*/
    unsigned char format1;
    };

typedef void (* Event_Spec_Deal)(unsigned char *);
typedef unsigned char  (* Event_Spec_Deal_R)(unsigned char *);

/*"**********************************************************************************"*/
/*"时间段事件记录数据格式"*/
struct Pay_Period_Event_format
    {
    const unsigned char *Data_Point;         /*" 事件记录数据 "*/
    const unsigned char *Data_Point_Format;  /*" 事件记录数据格式 "*/
    unsigned int Head_File_Addr;             /*" 事件文件首地址 "*/
    unsigned int Event_Record_Number;        /*" 事件记录条数 "*/
    unsigned int EE3_Addr;                   /*" 事件记录铁链地址 "*/
    unsigned char Event_Point_Offset;        /*" 事件指针偏移量 "*/
    Event_Spec_Deal Period_Event_Spec_Deal;  /*" 事件特殊处理函数 "*/
    };

/*"**********************************************************************************"*/
/*"瞬间点事件记录数据格式"*/
struct Pay_Time_Drop_Event_format
    {
    const unsigned char *Data_Point;         /*" 事件记录数据 "*/
    unsigned int Head_File_Addr;             /*" 事件文件首地址 "*/
    unsigned int Event_Record_Number;        /*" 事件记录条数 "*/
    unsigned char Event_Point_Offset;        /*" 事件指针偏移量 "*/
    Event_Spec_Deal Drop_Event_Spec_Deal;    /*" 事件特殊处理函数 "*/
    };

/*"**********************************************************************************"*/
/*"上电检查参数合法性的数据格式"*/
struct Check_format
    {
    unsigned int Eeprom_Addr;
    unsigned char * Addr;
    unsigned int Length;
    unsigned char Flag;     /*" 1：表示在掉电有写EE3，0：表示EE1和EE2有10分钟保存，最高位为1表示是最后一帧数据 "*/
    };












#endif	//PAY_DEF_H

