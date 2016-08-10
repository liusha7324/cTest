#ifndef PAY_DEF_H
#define PAY_DEF_H

#include "pay_Mac.h"

#define NUM_ERR_TO_HANG     200     /*"���ٴδ���������"*/
#define AUTH_ERR_LIMIT      100     /*"������֤������ٴκ�����֤ Ĭ��15"*/

#define NUM_PSW_INFO        32       /*"��Կ������"*/
#define BIT_MASK_ALL_PSW_UPD    ((1UL << NUM_PSW_INFO) - 1UL) /*"������Կ���Ѿ�����λͼ"*/
#define SZ_PSW_INFO         36      /*"������Կ����(��������Կ��Ϣ)"*/
#define SZ_PSW_INFO_MAC     (36 + 4)/*"������Կ��MAC����"*/

#define Pay_Eeprom_Buffer   Co.b                                /*" ���������� "*/


#define	ALARM_BUZZER_DIRECT            pd3_3
#define	ALARM_BUZZER                   p3_3   /*"����������"*///20050604 



#define	SWITCH_CLEW              p1_6   /*"�̵���״ָ̬ʾ"*/
#define	SWITCH_CLEW_DIRECT       pd1_6   /*"�̵���״ָ̬ʾ"*/

#define SIG_TRIFF                      0x01
#define Mul_TRIFF                      0x02

#define DOUT_MONEY_BOTTOM         100000l
//#define MAX_STEP                                 8
#define MAX_STEP                                 6			//Li Update 20121231   /*"�ݶ���"*/
#define PRE_MAX_TRIFF                       32          //MAXTRIFF


#define	RELAY_TYPE_SEL				p0_1	/*"�̵�����ʽ->0:����,1:����"*/ 

#define	RST_ZB_DIRECT            			pd5_4
//#define	RST_ZB              	  			p5_4   	/*"��λ���͵�ƽ��Ч��"*/ 
/*"�������"*/
#define	ALARM_RELAY_DIRECT          	pd3_5
#define	ALARM_RELAY                    	p3_5
	/*"���ü̵���"*/
#define	SWITCH_RELAY_DIRECT    	 		pd10_0		//pd3_4
#define	SWITCH_RELAY             	  		p10_0   	//p3_4
	/*"���ü̵���"*/
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
//      signed long Remain_Money;                     /*" ʣ���� 0.01Ԫ "*/
//    unsigned long Remain_Money_bottom;              /*" ʣ����β�� 0.0001Ԫ "*/
//	//unsigned long Total_User_Money;                 /*" �ۼ��õ��� "*/
//	//unsigned long Far_On_Time;                      /*" Զ����բ��ʱ�� "*/
//    unsigned long Energy_Next_Step;                 /*" ����һ���ݵ�ʣ����� "*/
//    unsigned long Month_Total_Energy;               /*" �µ��� "*/
//    unsigned int  Crc_Cs;                           /*" CRCЧ��� "*/
//    };
//#define LENGTH_PRE_POWER_DOWN_SAVE_DATA       sizeof( struct _Pre_Power_Down_Save_Data )
#define LENGTH_PRE_POWER_DOWN_SAVE_DATA     sizeof( struct PRE_SAVE_DATA)

/*"**********************************************************************************"*/
/*" ���粻��Ҫ�����Ԥ�������� "*/
/*" RAM "*/
struct _Pre_Payment_Data
    {
    unsigned long Last_Buy_Money;			   		/*" �ϴι����� 0.01Ԫ    HEX  "*/
    unsigned long Total_Buy_Money;			  		/*" �ۼƹ����� 0.01Ԫ    HEX  "*/
	unsigned long Bef_Month_Total_Energy;			/*"��һ�µ��� "*/	
	unsigned long Bef_Year_Total_Energy[4];			/*"��1~4�������й����ۼ��õ��� "*/
	struct  PRE_YEAR_BILLDATE_DEF Year_Total_Energy_Date;   /*"��ǰ�������й����ۼ�ʱ��"*/
	struct  PRE_YEAR_BILLDATE_DEF Pre_Year_BillDate[4];		/*"��1��������ս���ʱ�� - ��4��������ս���ʱ�� "*/
	unsigned char oprateCode[4];
	unsigned long CurrMoneyT;						/*"��ǰ��ʱ��� "*/
	unsigned char HangMeterNum;						/*"��������� "*/
	unsigned int  OPCard_StatusByte;				/*"�忨״̬��"*/
	unsigned char Esam_Identity[5];					/*"ESAM����ʶ����"*/
    unsigned char OverPowerSw_Time;					/*"��������բ����"*/
	unsigned char Reserve_User[4];					/*"��ʱ����"*/
	
	unsigned char Year_Bill_Point;					/*"�궳��ָ��"*/
	
	struct FARCONTROLEVENT FARCONTROLEVENT;			/*"��/��բ����"*/
	unsigned long TriffProgNum;						/*"���ʱ���ܴ���"*/
	unsigned long StepProgNum;						/*"�ݶȱ���ܴ���"*/
	unsigned long Relay_Error_Num;					/*"���ɿ��������ܴ���"*/
    unsigned long Back_Money_Count;            		/*"�˷��ܴ���"*/
    unsigned long Far_Key_Updata_Count;            	/*"Զ���޸���Կ�ܴ���"*/
	unsigned long OPCard_Error_Num;					/*"�쳣�忨�ܴ���"*/
    unsigned long Unlawful_Card_Count;            	/*"�Ƿ��忨����"*/

//    unsigned int  	Total_Buy_Money_Over_Time;              /*" �ۼƹ������������   "*/
//    unsigned long 	Total_Duct_Base_Money;                  /*" �ۼƿ۳�������� 0.01Ԫ    HEX  "*/
//    unsigned int  	Total_Duct_Base_Money_Over_Time;        /*" �ۼƿ۳���������������   "*/
//    unsigned long 	Total_Duct_Hire_Money;                  /*" �ۼƿ۳������� 0.01Ԫ    HEX  "*/
//    unsigned int  	Total_Duct_Hire_Money_Over_Time;        /*" �ۼƿ۳��������������   "*/	
//    unsigned char   Last_Buy_Time[5];             /*"����۵�ʱ��"*/
//    unsigned char   PowerDownTime[6];             /*"����ʱ��"*/
//	  unsigned char E_Burse_BuyNum;					/*"����Ǯ���������"*/
//    unsigned long Far_On_Count;                   /*"Զ����բ�ܴ��� "*/
//    unsigned long Step_Switch_Count;              /*"�ݶ��л��ܴ��� "*/
//    unsigned int  Triff_Updata_Count;       		/*"����޸��ܴ��� "*/
//    unsigned long Step_Updata_Count;              /*"�ݶ��޸��ܴ��� "*/
//	  unsigned char Month_Bill_Point;				/*"�¶���ָ��"*/

    unsigned int    Crc_Cs;                         /*" CRCЧ��� "*/
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
/*" Ԥ���Ѳ��� "*/
/*" RAM "*/
struct _Pre_Payment_Para
    {
    unsigned long Base_Money;                         /*" ������� 0.01Ԫ    HEX  "*/
    unsigned long Hire_Money;                         /*" ������ 0.01Ԫ    HEX  "*/
    unsigned long Remain_Money_Alarm1_Limit;          /*" ʣ������ʾ��������1 0.0001Ԫ    HEX  "*/
    unsigned long Remain_Money_Alarm2_Limit;          /*" ʣ������բ��������2 0.0001Ԫ    HEX  "*/
    unsigned long Remain_Money_Tick_Limit;            /*" ʣ������Ƿ���� 0.0001Ԫ    HEX  "*/
    unsigned long Remain_Money_Hoard_Limit;           /*" ʣ���Ѷڻ����� 0.01Ԫ    HEX  "*/
    unsigned long Triff[2][PRE_MAX_TRIFF];               /*" ���� 0.0001Ԫ    HEX  "*/
    unsigned long Multiple;                           /*" ���� HEX  "*/
    unsigned long C_T;                                /*" CT HEX  "*/
    unsigned long P_T;                                /*" PT HEX  "*/
    unsigned char SysID[6];                           /*" ϵͳ�� "*/
    unsigned char UserID[6];                          /*" �û��� "*/
    unsigned char MeterID[6];                         /*" ��� "*/
    unsigned char CardID;                         		/*"����"*/
	unsigned char User_Kind;                          /*" �û����� "*/
    struct DATEANDTIME_DEF TriffSwitchDate;           /*" �·��ʿ�ʼ����ʱ��"*/
    struct DATEANDTIME_DEF StepSwitchDate;            /*" ���ݶȿ�ʼ����ʱ��"*/
    unsigned char Meter_Run_State;                    /*" �������״̬��00����/01��װ/02���� "*/	
    unsigned char Money_Point;                        /*" ���С��λ "*/
    unsigned long Buy_Count;                          /*" ������� "*/
    unsigned char Step_Num[2];                        /*"�ݶ���"*/
    unsigned long Energy_Step[2][MAX_STEP];                  /*"��X�ݶ�ֵ X=1,2,3,4����"*/
    unsigned long Triff_Step[2][MAX_STEP+1];                   /*"���(����)"*/

	struct YEAR_BILLDATE_DEF  Year_BillDate[2][4]; 			/*"�������"*/		//Li Update 20130104

	
    union Pay_For_Users_Flag1  Pay_For_Users_Flag1;   /*" Ԥ���ѱ���״̬�� "*/
    union Pay_For_Users_Flag2  Pay_For_Users_Flag2;   /*" Ԥ����ģʽ��1 "*/
    union Pay_For_Users_Flag3  Pay_For_Users_Flag3;   /*" Ԥ����ģʽ��2 "*/
    union Pay_For_Users_Flag4  Pay_For_Users_Flag4;   /*" Ԥ����ģʽ��3 "*/
    union Pay_For_Users_Flag5  Pay_For_Users_Flag5;   /*" �������Ѻ�״̬�� "*/
	union Pay_For_Users_Flag11 Pay_For_Users_Flag11;  /*" ����բ������������(���������ļ�Ҫ��) "*/
    union Pay_For_Users_Flag12 Pay_For_Users_Flag12;  /*" �Զ�����籣���־�� "*/
    union Pay_For_Users_Flag13 Pay_For_Users_Flag13;  /*" �Զ�����籣���־�� "*/
    union Pay_For_Users_Flag14 Pay_For_Users_Flag14;  /*" �Զ�����籣���־�� "*/
    union Pay_For_Users_Flag15 Pay_For_Users_Flag15;  /*" �Զ�����籣���־�� "*/

//    unsigned char Triff_Table[2][4];                  /*" ���ʱ�"*/
//    unsigned long Energy_Step_Table[2][8][3];         /*" �ݶȱ�"*/
//    unsigned long Triff_Step_Table[2][6][4];          /*" �ݶȷ��ʱ�"*/
	unsigned char InfrIdenTime;               /*"������֤ʱЧ"*/  //infrared identification
	unsigned char Switch_Test_Num;			/*"�̵�������ʱ��������"*/
	unsigned long Far_Key_StatusByte;        	/*"��Կ״̬��"*/	/*"Li_0 ��ʾ������Կ(��Կ),1 ��ʾ��ʽ��Կ(˽Կ) "*/
//	unsigned long OverPower_Plus_Limit;   			/*"�����,���ʸ���������"*/
//	unsigned char Power_Period;      						/*"�����ϼ���ʱ��"*/
//	unsigned char	OverPower_Time_Limit;			/*"��������բ��������"*/

	unsigned long Para_Card_Version;           /*"�ֳ��������ÿ��汾��,�ϵ��ʼ��Ҫ����"*/
	unsigned int CurrLimitProTime;                 /*"����բ���Ƶ������ޱ�����ʱʱ��(����)"*/
	//unsigned char Curr_Step_Point;                 /*"��ǰ�ݶȷ���ָ��"*/

	unsigned char PassWord_Kind;                 /*"��Կ����"*/
	unsigned long Close_Switch_Limit;           /*"ʣ���Ѻ�բ�޶�"*/
	unsigned char TriffPriceNum;           		/*"����ʱʹ�õķ�����"*/
	unsigned char Far_Day_Follow;			/*"Զ����֤�ո���"*/
	unsigned char Card_Reset_Inf[8];           /*"CPU�����к�"*/
	unsigned int Far_Open_Delay;			 /*"��բ��ʱ(��բ�ϵ�ǰ�澯ʱ��)"*/
	unsigned int Far_Close_Delay;			 /*"Ԥ��բ���բ��ʱ(��բͨ��ǰ�澯ʱ��)"*/
	unsigned int RelayActTime;			 	/*"���ü̵������巽ʽ��բά��ʱ��,��λ:mS"*/
	unsigned int RelayActEnergy;			 /*"���ü̵������巽ʽ�ٴ���բ����,��λ:Wh"*/
	unsigned long CurrLimit;			 		/*"�̵�����բ���Ƶ�������ֵ(���ñ��������XXX.XXXAʱ��24Сʱ�ڲ���բ)"*/

	unsigned char PassWord_Num;				 /*"��Կ������ "*/		//Li Update 20130104
	unsigned char psw_status;				 /*"��Կ״̬ (��Կ���³ɹ���ʱ����������Կ״̬Ϊ���µ�)"*/

	unsigned int ID_Ins_Time;				/*"�����֤��Чʱ��"*/

	unsigned long SendBack_Money;			/*"�˷ѽ��"*/

    unsigned int  Crc_Cs;                             /*" CRCЧ��� "*/
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
	
	#define  PASSWORDNUM_EE					CURRLIMIT_EE+4				/*"��Կ����"*/
    #define  PSW_STATUS_EE					(PASSWORDNUM_EE+1)
    #define  ID_INS_TIME_EE					(PSW_STATUS_EE+1)	 
	#define  SENDBACK_MONEY					ID_INS_TIME_EE+2

	
/*"**********************************************************************************"*/
/*" Ԥ�����¼���¼ָ�� "*/
/*" EE "*/
struct _Pay_For_Event_Point
    {
    unsigned char Buy_Event_P;                             /*" �����¼���¼ָ�� "*/
    unsigned char Far_Control_Event_P;                     /*" Զ����բ�¼���¼ָ�� "*/
    unsigned char Far_Control_Free_Event_P;                /*" Զ����բ����¼���¼ָ�� "*/
    unsigned char Triff_Switch_Event_P;                    /*" �����л��¼���¼ָ�� "*/
    unsigned char Step_Switch_Event_P;                     /*" �ݶ��л��¼���¼ָ�� "*/
    unsigned char Remain_Money_Alarm1_Event_P;             /*" ʣ���ѵ��ڱ�������1�¼���¼ָ�� "*/
    unsigned char Remain_Money_Alarm2_Event_P;             /*" ʣ���ѵ��ڱ�������2�¼���¼ָ�� "*/
    unsigned char Remain_Money_Zero_Event_P;               /*" ʣ���ѵ���0�¼���¼ָ�� "*/
    unsigned char Remain_Money_Tick_Event_P;               /*" ʣ���ѵ�����Ƿ�����¼���¼ָ�� "*/
    unsigned char Money_Balance_Event_P;                   /*" Ԥ�������ݽ���ָ�� "*/
    unsigned char Triff_Updata_Event_P;                    /*" �����޸��¼���¼ָ�� "*/
    unsigned char Step_Updata_Event_P;                     /*" �ݶ��޸��¼���¼ָ�� "*/
    unsigned char Far_Key_Updata_Event_P;              	/*" ��Կ�����¼���¼ָ�� "*/	
	unsigned char OPCard_Error_Event_P;					/*" �忨�쳣�¼���¼ָ�� "*/	//Li Update 20130106
	unsigned char Refundment_Event_P;						/*"�˷ѽ���¼���¼ָ��"*/		//Li Update 20130106
	unsigned char RelayErr_Event_P;						/*"���ɿ��������¼���¼ָ��"*/	
	unsigned char YearBillDate_Event_P;					/*"��������¼���¼ָ��"*/		//Li Update 20130109 
	unsigned char ProgramTriff_Event_P;						/*"���ʱ����¼���¼ָ��"*/	
	unsigned char ProgramStep_Event_P;						/*"�ݶȱ����¼���¼ָ��"*/	
	unsigned char E_Burse_Event_P;							/*"����Ǯ���¼���¼ָ��"*/
	unsigned char Month_Bill_Event_P;							/*"�½����ռ�¼ָ��"*/
    unsigned int  Crc_Cs;                                  /*" �ۼ�Ч��� "*/
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
/*" ����Ϊ�鶨�壬��ʵ�� "*/
/*"**********************************************************************************"*/
/*" �¼���¼�������� "*/
#define BUY_EVENT_NUMBER                      		32L			/*"��Ӧ��һ���ƫ����"*/
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
/*" �ļ������� "*/
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
	unsigned char psw_info[NUM_PSW_INFO][SZ_PSW_INFO_MAC];   /*"������Կ��Ϣ(36�ֽ�struct Far_Deal_070301FF_format, ÿ��Ԥ��4�ֽڵ�MAC)"*/
    unsigned long upd_flg;  /*"��Կ����λͼ: ��ӦλΪ1��ʾ��Ӧ��Կ���µ���EEPROM"*/
    unsigned char pwd_stat; /*"����ȫ����Կ״̬����ʼ��Ϊһ�������ܱ�ʹ��ֵ�������ж���������Ƿ���ʵ���� "*/
    unsigned char seq_num ; /*"��¼��Կ���"*/
};
#define LEN_UPD_PSW_IF  sizeof(struct upd_psw_info)
#define UPD_PSW_INFO_EE (PAY_PSW_UPD_INFO_EE)
#define UPD_PSW_FLG     (UPD_PSW_INFO_EE + NUM_PSW_INFO * SZ_PSW_INFO_MAC)
#define UPD_PSW_STAT     (UPD_PSW_FLG + sizeof(unsigned long))
#define UPD_SEQ_NUM     (UPD_PSW_STAT+ 1)


/*"**********************************************************************************"*/
/*" EEPRON���ݽṹ���� "*/
/*"**********************************************************************************"*/
/*" EEPROM�����Ԥ���������ڿ��ṹ "*/
/*" ���EEPRON0��EEPROM1 "*/

struct _Pay_Eeprom_Define
    {
	struct _Pre_Payment_Data               Pre_Payment_Data;              /*" �ϵ�����޸�ʱд "*/
    struct _Pre_Payment_Para               Pre_Payment_Para;              /*" �ϵ�����޸�ʱд "*/ 
    struct _Pay_For_Event_Point            Pay_For_Event_Point;           /*" �޸�ʱ��д "*/
	unsigned char       					RelayErr_Area[29];     	 /*"�̵���������ʱ���Ա������ݵ��ڿ��ռ�"*/
	struct upd_psw_info 				psw_info;   			/*"������Կ������Ϣ ������Կ��"*/
	unsigned char    					Pre_Tmp[29];		/*"��ʱ����"*/	
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
/*"BIT0��1����Ӧ���ݿ�ʼ��Ч"*/
/*"BIT1��1����Ӧ���ݽ�����Ч"*/
/*"BIT2��1������"*/
/*"BIT3��1������"*/
/*"BIT4��1������"*/
/*"BIT5��1������"*/
/*"BIT6��1��������4���ֽڵ����ݼ���"*/
/*"BIT7��1����������"*/
    unsigned char format1;
    };

typedef void (* Event_Spec_Deal)(unsigned char *);
typedef unsigned char  (* Event_Spec_Deal_R)(unsigned char *);

/*"**********************************************************************************"*/
/*"ʱ����¼���¼���ݸ�ʽ"*/
struct Pay_Period_Event_format
    {
    const unsigned char *Data_Point;         /*" �¼���¼���� "*/
    const unsigned char *Data_Point_Format;  /*" �¼���¼���ݸ�ʽ "*/
    unsigned int Head_File_Addr;             /*" �¼��ļ��׵�ַ "*/
    unsigned int Event_Record_Number;        /*" �¼���¼���� "*/
    unsigned int EE3_Addr;                   /*" �¼���¼������ַ "*/
    unsigned char Event_Point_Offset;        /*" �¼�ָ��ƫ���� "*/
    Event_Spec_Deal Period_Event_Spec_Deal;  /*" �¼����⴦���� "*/
    };

/*"**********************************************************************************"*/
/*"˲����¼���¼���ݸ�ʽ"*/
struct Pay_Time_Drop_Event_format
    {
    const unsigned char *Data_Point;         /*" �¼���¼���� "*/
    unsigned int Head_File_Addr;             /*" �¼��ļ��׵�ַ "*/
    unsigned int Event_Record_Number;        /*" �¼���¼���� "*/
    unsigned char Event_Point_Offset;        /*" �¼�ָ��ƫ���� "*/
    Event_Spec_Deal Drop_Event_Spec_Deal;    /*" �¼����⴦���� "*/
    };

/*"**********************************************************************************"*/
/*"�ϵ�������Ϸ��Ե����ݸ�ʽ"*/
struct Check_format
    {
    unsigned int Eeprom_Addr;
    unsigned char * Addr;
    unsigned int Length;
    unsigned char Flag;     /*" 1����ʾ�ڵ�����дEE3��0����ʾEE1��EE2��10���ӱ��棬���λΪ1��ʾ�����һ֡���� "*/
    };












#endif	//PAY_DEF_H

