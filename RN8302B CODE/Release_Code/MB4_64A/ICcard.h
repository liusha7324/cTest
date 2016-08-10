//ICcard.h



#ifndef _ICCARD_H_
#define _ICCARD_H_


//#define RELAY_DRIVE_TYPE	1	/*"���ü̵���1:�ߵ�ƽ����,0:�͵�ƽ����"*/
#define RELAY_ACT_TIME			5	/*"���ü̵���,5���ڲ������෴����"*/
#define RELAY_NEXT_PULSE_TIME	2	/*"���ü̵���,2�����һ������"*/
#define RELAY_PLUSE_CNT			2	/*"���ü̵�������ʱ��2������"*/
#define RELAY_ERR_CHECK_TIME	3	/*"�̵����������ʱ��--�������3��"*/

//------------------------------------------
//#define RMB					UNSIGNED_LONG	//payment		/*""*/
#define FAY_PASS_INC_ERR                0x10                    	/*"��Կ��"*/
#define FAY_PASS_MODFIY_ERR                0x16                    /*"��Կ���´�"*/



/*" ����Զ��Ԥ���ѿ����� "*/
#define GWFAR_USER_CARD                   0x01       /*" �û��� "*/
	#define  GWFAR_USER_CARD_NEW    	0x01	/*" �¿� "*/
	#define  GWFAR_USER_CARD_BUY		0x02	/*" ���翨 "*/
	#define  GWFAR_USER_CARD_BACK		0x03	/*" ���� "*/

#define GWFAR_MOD_PASSWORD_CARD           0x02       /*" �޸���Կ�� "*/
#define GWFAR_RES_PASSWORD_CARD           0x03       /*" �ָ���Կ�� "*/
#define GWFAR_PARA_SET_CARD               0x04       /*" �������ÿ� "*/
#define GWFAR_READ_ESAM_CARD              0x05       /*" ESAM���ݻس��� "*/
#define GWFAR_INIT_CARD                   0x06       /*" �������ÿ� "*/
#define GWFAR_MOD_METERID_CARD            0x07       /*" ������ÿ� "*/
#define GWFAR_ADDD_MONEY_CARD            0x08       /*" ���ӵ�ѿ� "*/
#define GWFAR_RELAY_TEST_CARD            0x09       /*" �̵������Կ� "*/

//---
#define UN_TYPE_CARD 				0x00
#define NEW_CARD 						0x01
#define BUY_CARD 						0x02
#define FILL_CARD 						0x03  
#define USER_CHANGE_CARD 	0x04
#define DELUSE_CARD 				0x05
#define CHECK_CARD 					0x06
#define TRIFF_CARD 					0x07
#define RELAY_CARD 					0x08
#define SET_IN_CARD					0x09
#define PASSWORD_CARD 			0x10
#define CHANGE_CARD 				0x11
#define ADD_MONEY_CARD 		0x12
#define MOD_METERID_CARD	0X13

#define Card_Display_Card    	0x00
#define Card_Display_Good   	0x01
#define Card_Display_Err      	0x02

#define SEL_ESAM						ESAM
#define SEL_CPU							CPU
#define GOOD 								CPU_CARD_SUCCESS	//0x00EE
#define PRE_DISP_LIMIT			10000000000

#define CARD_BACK_USER_SEL			1
#define CARD_BACK_CHECK_SEL		2
#define CARD_BACK_CHANGE_SEL	3
//#define CARD_BACK_USER_LEN		18
//#define CARD_BACK_CHECK_LEN		27
//#define CARD_BACK_CHANGE_LEN	17



//----------------------------------------------------//		//Li Update
#define  GOOD_DEFINE				0
#define  VOLTAGE_LOW_DEFINE       	1				/*"Li_��Ƶ�ѹ����"*/
#define  ESAM_ERROR_DEFINE       		2				/*"Li_����ESAM����"*/ //
#define  ESAM_RESET_DEFINE			3				/*"Li_ESAM��λ����"*/
#define  ICCARD_RESET_DEFINE		4				/*"Li_��Ƭ��λ����"*/
#define  IDCARD_ERROR_DEFINE		5				/*"Li_�����֤����"*/
#define  EXID_ERROR_DEFINE 			6				/*"Li_�ⲿ��֤����"*/
#define  UNISSUED_ERROR_DEFINE   	7				/*"Li_δ���еĿ�Ƭ->���Ķ�CPU���ļ�����6B00���� "*/
#define  CARDTYPE_ERROR_DEFINE   	8				/*"Li_�����ʹ���"*/
#define  CARD_NO_INS_DEFINE   		9				/*"��Ƭ����δ��Ȩ(��Կ״̬��Ϊ��Կʱ�����Ԥ�ÿ�)"*/
#define  MAC_ERROR_DEFINE   		10				/*"MACУ�����"*/
#define  METER_NUM_DEFINE      		11				/*"Li_��Ų�һ��"*/
#define  CLIENT_NUM_DEFINE       		12				/*"Li_�ͻ���Ų�һ��"*/
#define  CARD_SN_DEFINE				13				/*"Li_�����кŲ�һ��"*/
#define  CARDFILE_FORMAT_DEFINE	14				/*"Li_��Ƭ�ļ���ʽ���Ϸ�"*/
#define  BUYCARD_ERROR_DEFINE		15				/*"Li_���翨����δ������"*/
#define  UPCARD_ERROR_DEFINE 		16				/*"Li_��������δ������"*/
#define  BUYNUM_ERROR_DEFINE   		17				/*"Li_�����������"*/
#define  USER_BACK_WRITE_DEFINE   	18				/*"�û�����д��Ϣ�ļ���Ϊ�� "*/
#define  OPCARD_ERROR_DEFINE   		19       	    		/*"Li_������Ƭ����"*/
#define  MOVE_CARD_DEFINE			20				/*"Li_��ǰ�ο�"*/
#define  HOARD_AMOUNT_DEFINE     	21		 	    	/*"Li_ʣ����ڻ�"*/
//#define  AMMETER_HANG_DEFINE      	22				/*"Li_������"*/




//---
#define NEW_CARD_CODE						0xFFFFFF80+NEW_CARD
#define BUY_CARD_CODE						0xFFFFFF80+BUY_CARD
#define FILL_CARD_CODE 						0xFFFFFF80+FILL_CARD  
#define DELUSE_CARD_CODE 				0xFFFFFF80+DELUSE_CARD
#define USER_CHANGE_CARD_CODE 	0xFFFFFF80+USER_CHANGE_CARD
#define TRIFF_CARD_CODE 					0xFFFFFF80+TRIFF_CARD
#define SET_IN_CARD_CODE					0xFFFFFF80+SET_IN_CARD
#define CHANGE_CARD_CODE 				0xFFFFFF80+CHANGE_CARD
#define BASE_MONEY_ID									0x04000401	//
#define HIRE_MONEY_ID									0x04000402	//
#define REMAIN_MONEY_ALARM1_LIMIT_ID	0x04001001
#define REMAIN_MONEY_ALARM2_LIMIT_ID	0x04001002
#define REMAIN_MONEY_TICK_LIMIT_ID		0x04001003
#define REMAIN_MONEY_HOARD_LIMIT_ID	0x04001004
#define OVERPOWER_PLUS_LIMIT_ID				0x04001010
#define POWER_PERIOD_ID								0x04001011
#define OVERPOWER_TIME_LIMIT_ID				0x04001012
#define TRIFF1_ID												0x04050101
#define TRIFF2_ID												0x04050201
#define C_T_ID														0x04000306
#define P_T_ID														0x04000307
#define SYSID_ID													0x04000501	//
#define USERID_ID												0x04000502	//
#define METERID_ID											0x04000503	//
#define CARDID_ID												0x04000504	//
#define TRIFFSWITCHDATE_ID							0x04000108
#define STEPSWITCHDATE_ID							0x04000109
#define METER_RUN_STATE_ID						0x04000601	//
#define MONEY_POINT_ID									0x04000701	//
#define BUY_COUNT_ID										0x04000602	//
#define STEP_NUM_ID											0x04000207
#define ENERGY_STEP1_ID								0x04060001
#define ENERGY_STEP2_ID								0x04060101
#define TRIFF_STEP1_ID									0x04060201
#define TRIFF_STEP2_ID									0x04060301
#define PAY_FOR_USERS_FLAG1_ID				0x04000810
#define PAY_FOR_USERS_FLAG2_ID				0x04000811
#define PAY_FOR_USERS_FLAG3_ID				0x04000812
#define PAY_FOR_USERS_FLAG4_ID				0x04000813
#define PAY_FOR_USERS_FLAG5_ID				0x04000814
#define PAY_FOR_USERS_FLAG11_ID				0x04000803
#define PAY_FOR_USERS_FLAG12_ID				0x04000815
#define TRIFF_TABLE1_ID									0x04050001
#define ENERGY_STEP_TABLE1_ID					0x04050102
#define ENERGY_STEP_TABLE2_ID					0x04060102
#define TRIFF_STEP_TABLE1_ID						0x04050101
#define TRIFF_STEP_TABLE2_ID						0x04060101
#define OPENSWITCHDELAYTIME_ID				0x0E00010D
#define CLOSESWITCHDELAYTIME_ID				0x0E00010E
#define YEARSLOTNUMBLE_ID							0x04000201
#define DAILYSLOTTABLENUMBLE_ID				0x04000202
#define DAILYSLOTNUMBLE_ID							0x04000203
#define WEEKENDTABLE_ID								0x04000802
#define YEARTABLE_ID										0x04010000
#define DAYTABLE_ID											0x04010001
#define HOLIDAY_ID											0x04030001
#define YEARSLOTNUMBLE2_ID							0x0E000211
#define DAILYSLOTTABLENUMBLE2_ID			0x0E000212
#define DAILYSLOTNUMBLE2_ID						0x0E000213
#define WEEKENDTABLE2_ID								0x0E000216
#define YEARTABLE2_ID										0X04020000
#define DAYTABLE2_ID										0X04020001

//----
#define IC_GET_PLUS_REMAIN					0x01
#define IC_GET_NEGA_REMAIN				0x02
#define IC_GET_PLUS_ACTIVE					0x03
#define IC_GET_ENERGY_RECORD			0x04
#define IC_GET_ALARM_LIMIT					0x05
#define IC_GET_ZERO									0x10

//fun sel
#define MACRO_FAY_CONTROL_FLAG	Meter_Parameter.parameter1.MeterTypeMode.bit.b5
//#define MACRO_ESAM_FLAG			Meter_Parameter.parameter1.MeterTypeMode.bit.b4

//#define CARRIER_DY_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b7	/*"1:����"*/
//#define CARRIER_XC_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b6	/*"1:����"*/
//#define CARRIER_DX_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b5	/*"1:����"*/
//#define CARRIER_QL_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b4	/*"1:Ǯ��"*/
//#define CARRIER_RXK_FLAG		Meter_Parameter.parameter1.CarrierMode.bit.b4	/*"1:��˹��"*/

#define MACRO_LOCAL_PAY_FLAG	Meter_Parameter.parameter1.MeterMode[1].bit.b5
#define PRE_MONEY_POINT			Pre_Payment_Para.Money_Point
//#define TRIFF_P					Pre_Payment_Para.Curr_Triff_Point
//#define STEP_P					Pre_Payment_Para.Curr_Step_Point
//#define TRIFF_BAK_P			((Pre_Payment_Para.Curr_Triff_Point+1)&0x01)


union ICcard_Flag1
    {
    struct
        {
        unsigned char DISP_SIGN_FLAG:1;			/*"1:��ʾ������ʣ������"*/
		 unsigned char DISP_MONEY_FLAG:1;		/*"1:��ʾʣ����"*/
        unsigned char DISP_PLUS_FLAG:1;			/*"1:��ʾ��ʣ����"*/
        unsigned char DISP_NEGA_FLAG:1;			/*"1:��ʾ��ʣ����"*/
        unsigned char DISP_MYRIAD_FLAG:1;		/*"1:��ʾ��ʾ��(Ԫ),��ʣ���(���)����79999999ʱ"*/
        unsigned char GPRS_MODEL:1;			/*"����--> 1:��;0:��"*/ 	
        unsigned char CARRIER_MODEL:1;		/*"�ز�--> 1:��;0:��"*/ 	
        unsigned char SWITCH_ACT_MODE:1;	/*"��բ�̵���--> 1:����,��ƽ��ʽ;0:����,���巽ʽ[�޼̵���ʱѡ������]"*/ 	
        }bit;
    unsigned char  intd;
    };
extern union ICcard_Flag1 ICcard_Flag1;

#define DISP_SIGN_FLAG_DEFINE  		ICcard_Flag1.bit.DISP_SIGN_FLAG
#define DISP_MONEY_FLAG_DEFINE  		ICcard_Flag1.bit.DISP_MONEY_FLAG
#define DISP_PLUS_FLAG_DEFINE  		ICcard_Flag1.bit.DISP_PLUS_FLAG
#define DISP_NEGA_FLAG_DEFINE  		ICcard_Flag1.bit.DISP_NEGA_FLAG
#define DISP_MYRIAD_FLAG_DEFINE  		ICcard_Flag1.bit.DISP_MYRIAD_FLAG
#define FLAG_GPRS_MODEL				ICcard_Flag1.bit.GPRS_MODEL
#define FLAG_CARRIER_MODEL				ICcard_Flag1.bit.CARRIER_MODEL
#define FLAG_SWITCH_ACT_MODE			ICcard_Flag1.bit.SWITCH_ACT_MODE

struct CardErrId
{
	unsigned int oldID;
	unsigned char newID;
};
#define CARDERRID_LENGTH  sizeof(struct CardErrId)

//-----------------------------------------------------
struct USECARD_INFOR_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char syeID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long triffBottom[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char buyTime[6];
	unsigned char triffSwitchDate[4];
	unsigned char	Cs;
	unsigned char End;
};

struct PARACARD_INFOR_FILE
{
  	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char triffSwitchDate[4];
	unsigned char Cs;
	unsigned char End;
};

struct RIFFCARD_TIMEZONE_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char yearSlotNumble;
	unsigned char yearTable[4][4];
	unsigned char dailySlotTableNumble;
	unsigned char dayTable[4][12][3];
	unsigned char holiday[13][3];
	unsigned char weekEndTable;
	unsigned char Cs;
	unsigned char End;
};

struct ADDCARD_COMMAND_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char userID[5];
	long               buyMoney;
	unsigned int    buyCount;
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE1
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char userID[5];
	unsigned char oldMeterID[5];
	unsigned char newMeterID[5];
	unsigned char meterRunstate;
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE2
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char triffSwitchDate[4];
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE3
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long buyMoney;
	unsigned int   	buyCount;
	unsigned long triffEnergy[5];
	unsigned long tickMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTime;
	unsigned char unlawfulCardCount;
	unsigned char Cs;
	unsigned char End;	  
};

//---back write---
struct User_Back_Infor
{
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long lastBuyMoney;
	unsigned int 	buyCount;
	unsigned long triffEnergy[5];
	unsigned long overZeroMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowSwTime;
	unsigned char unlawfulCardCount;
};

struct Check_Back_Infor
{
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long lastBuyMoney;
	unsigned int 	buyCount;
	unsigned long triffEnergy[5];
	unsigned long triff[4];
	unsigned long overZeroMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowSwTime;
	unsigned char unlawfulCardCount;
	unsigned char meterStatus;
	unsigned char writeBackTime[6];
};

//-------------------------------------
extern char maxSetpNum;
extern unsigned char display_Remain_Flag;		/*"0xF0:��ʾʣ����"*/
extern unsigned char Card_Type;
extern signed long Remain_Money_Temp;
extern unsigned long Remain_Money_Plus;
extern unsigned long Remain_Money_Nega;
extern unsigned long Power_Plus_Number;			/*"--���帺����--"*/
extern unsigned long Power_Count_Time;			/*"--���ɼ���ʱ��--"*/
//extern unsigned long currentTriff[];
extern unsigned char Card_WR_Buff[512];
extern unsigned char Dir_Return_Flag;                      /*" ֱ�ӻ�д��־ "*/
extern unsigned char Para_Updata_Flag;              /*" �������±�־ "*/
extern unsigned char Para_Updata_Flag_Suc;
extern unsigned char Meter_Ins_Flag;
extern unsigned long buyBeforMoney;					/*"����ǰʣ����"*/
extern unsigned long Remain_Money_Plus;			/*"��ʣ����"*/
extern unsigned long Remain_Money_Nega;		/*"������"*/
extern unsigned char eventReportTime;			/*"���¼�δ�ϱ�ʱ,�͵�ƽ�͸ߵ�ƽ��5��"*/
extern unsigned char clearFlag;
extern union ID CurrReadId;				/*"��ǰ������ʱ��ID"*/	
//extern unsigned char CurrReadMode;		/*"��ǰ������ʱ�Ķ�ģʽ"*/
extern unsigned char RunStepNum;			/*"ʵ�����е��ݶ���"*/
extern unsigned char G_Rec_Disp_Flg;

//---
extern void ICcard_Main(void);
extern void Pre_Init(void);
extern void Pre_Display(unsigned char );
extern void Pre_Display_Char_Flash(void);
extern void Pay_Minute_Act(void);
extern void Find_PassInf_Status(void);
extern unsigned char Pre_Static_Display_Remain(void);
extern void Pre_Get_OverZero_Money(void);
extern void FarSwitchControl(unsigned char uartx);
extern void buy_money_event(unsigned char *);
extern void far_conrol_event(unsigned char *);
extern void far_close_event(unsigned char *);
extern int Get_Pay_Flag(void);
extern int Get_FarControl_Flag(void);
extern int Get_Payment_Flag(void);
extern int Set_PayMod2(void);
extern int Set_CT(void);
extern int Set_PT(void);
extern int Set_Triff_Price(void);
extern int Set_Step_Price(void);
extern int  Set_TriffPrice_Num(unsigned char num);
extern int Set_Step_Num(void);
extern int Set_PassNumber(void);
extern int Get_Plus_Money(void);
extern int Get_Nega_Money(void);
extern int Get_Remain_Money(void);
extern int Get_Remain_Energy(void);
extern int Get_OPCard_StatusByte(void);
extern int Get_Month_Energy(void);
extern int Get_Year_Energy(void);
extern int Get_OpCardErr_ID(void);
extern int Get_OpCardErr_ID2(void);
extern int Get_OpCardErr_Cmd(void);
extern int Get_OpCardErr_Cmd2(void);

extern int Get_Pre_UserD(void);
extern int Set_Pre_UserD(void);
extern int Get_Money_Flag(void);
extern int Get_Energy_Flag(void);
extern int Get_Current_Triff(void);
extern int Set_Bak_Setp_Para(void);
extern int Set_Bak_Setp_Para(void);
extern int Get_Meter_ID(void);
extern int Set_Meter_ID(void);
extern void getRelayType(void);
extern void getCarrierGprs(void);
extern int Set_PaySwitchDate(void);
extern int Set_Ne_RelayActTime(void);
extern int Set_InfaIdenTime(void);
extern int Set_PassWord(void);
extern int Set_Wai_RelayActEnergy(void);
extern unsigned char getCardErrConver(unsigned char inData);
extern unsigned char Cal_Add_CS(unsigned char * ,unsigned char );
extern void Reverse_data(unsigned char *, unsigned int );
extern void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len);
extern unsigned char Judge_Remain_Money_Over(unsigned long );
extern void Meter_Money_And_Count_Updata( unsigned long ,unsigned long );
extern unsigned char Updata_Esam_Return_File(unsigned char Order_Kind, unsigned long ,unsigned long);
extern unsigned char GetRelayPort_Status(void);
extern void Pay_For_Event_Period(const unsigned char * Para_Point ,unsigned char mode );
extern unsigned char F_E_BurseFreezeData(void);
extern int Get_TriffPrice2(void);
extern int Set_TriffPrice2(void);
extern int Set_Yer_Bill_Data(void);
extern int Refundmentment_Money(void);

/*"ȡ��ǰ���ʼ��ƽ�ȵ��(�Ĵ�,��ʾʱ��)"*/
extern int Get_Current_Triff(void);
extern int Get_cur_which_step(void);

#endif	//_ICCARD_H_
