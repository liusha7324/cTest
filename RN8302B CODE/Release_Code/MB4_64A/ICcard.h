//ICcard.h



#ifndef _ICCARD_H_
#define _ICCARD_H_


//#define RELAY_DRIVE_TYPE	1	/*"内置继电器1:高电平动作,0:低电平动作"*/
#define RELAY_ACT_TIME			5	/*"内置继电器,5秒内不允许相反动作"*/
#define RELAY_NEXT_PULSE_TIME	2	/*"内置继电器,2秒后发下一个脉冲"*/
#define RELAY_PLUSE_CNT			2	/*"内置继电器驱动时发2个脉冲"*/
#define RELAY_ERR_CHECK_TIME	3	/*"继电器检测错误的时长--连续检测3秒"*/

//------------------------------------------
//#define RMB					UNSIGNED_LONG	//payment		/*""*/
#define FAY_PASS_INC_ERR                0x10                    	/*"密钥错"*/
#define FAY_PASS_MODFIY_ERR                0x16                    /*"密钥更新错"*/



/*" 国网远程预付费卡类型 "*/
#define GWFAR_USER_CARD                   0x01       /*" 用户卡 "*/
	#define  GWFAR_USER_CARD_NEW    	0x01	/*" 新卡 "*/
	#define  GWFAR_USER_CARD_BUY		0x02	/*" 购电卡 "*/
	#define  GWFAR_USER_CARD_BACK		0x03	/*" 补卡 "*/

#define GWFAR_MOD_PASSWORD_CARD           0x02       /*" 修改密钥卡 "*/
#define GWFAR_RES_PASSWORD_CARD           0x03       /*" 恢复密钥卡 "*/
#define GWFAR_PARA_SET_CARD               0x04       /*" 参数设置卡 "*/
#define GWFAR_READ_ESAM_CARD              0x05       /*" ESAM数据回抄卡 "*/
#define GWFAR_INIT_CARD                   0x06       /*" 出厂设置卡 "*/
#define GWFAR_MOD_METERID_CARD            0x07       /*" 表号设置卡 "*/
#define GWFAR_ADDD_MONEY_CARD            0x08       /*" 增加电费卡 "*/
#define GWFAR_RELAY_TEST_CARD            0x09       /*" 继电器测试卡 "*/

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
#define  VOLTAGE_LOW_DEFINE       	1				/*"Li_表计电压过低"*/
#define  ESAM_ERROR_DEFINE       		2				/*"Li_操作ESAM错误"*/ //
#define  ESAM_RESET_DEFINE			3				/*"Li_ESAM复位错误"*/
#define  ICCARD_RESET_DEFINE		4				/*"Li_卡片复位错误"*/
#define  IDCARD_ERROR_DEFINE		5				/*"Li_身份认证错误"*/
#define  EXID_ERROR_DEFINE 			6				/*"Li_外部认证错误"*/
#define  UNISSUED_ERROR_DEFINE   	7				/*"Li_未发行的卡片->明文读CPU卡文件返回6B00错误 "*/
#define  CARDTYPE_ERROR_DEFINE   	8				/*"Li_卡类型错误"*/
#define  CARD_NO_INS_DEFINE   		9				/*"卡片操作未授权(密钥状态不为公钥时插参数预置卡)"*/
#define  MAC_ERROR_DEFINE   		10				/*"MAC校验错误"*/
#define  METER_NUM_DEFINE      		11				/*"Li_表号不一致"*/
#define  CLIENT_NUM_DEFINE       		12				/*"Li_客户编号不一致"*/
#define  CARD_SN_DEFINE				13				/*"Li_卡序列号不一致"*/
#define  CARDFILE_FORMAT_DEFINE	14				/*"Li_卡片文件格式不合法"*/
#define  BUYCARD_ERROR_DEFINE		15				/*"Li_购电卡插入未开户表"*/
#define  UPCARD_ERROR_DEFINE 		16				/*"Li_补卡插入未开户表"*/
#define  BUYNUM_ERROR_DEFINE   		17				/*"Li_购电次数错误"*/
#define  USER_BACK_WRITE_DEFINE   	18				/*"用户卡返写信息文件不为空 "*/
#define  OPCARD_ERROR_DEFINE   		19       	    		/*"Li_操作卡片错误"*/
#define  MOVE_CARD_DEFINE			20				/*"Li_提前拔卡"*/
#define  HOARD_AMOUNT_DEFINE     	21		 	    	/*"Li_剩余金额超囤积"*/
//#define  AMMETER_HANG_DEFINE      	22				/*"Li_电表挂起"*/




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

//#define CARRIER_DY_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b7	/*"1:东软"*/
//#define CARRIER_XC_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b6	/*"1:晓程"*/
//#define CARRIER_DX_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b5	/*"1:鼎信"*/
//#define CARRIER_QL_FLAG			Meter_Parameter.parameter1.CarrierMode.bit.b4	/*"1:钱龙"*/
//#define CARRIER_RXK_FLAG		Meter_Parameter.parameter1.CarrierMode.bit.b4	/*"1:瑞斯康"*/

#define MACRO_LOCAL_PAY_FLAG	Meter_Parameter.parameter1.MeterMode[1].bit.b5
#define PRE_MONEY_POINT			Pre_Payment_Para.Money_Point
//#define TRIFF_P					Pre_Payment_Para.Curr_Triff_Point
//#define STEP_P					Pre_Payment_Para.Curr_Step_Point
//#define TRIFF_BAK_P			((Pre_Payment_Para.Curr_Triff_Point+1)&0x01)


union ICcard_Flag1
    {
    struct
        {
        unsigned char DISP_SIGN_FLAG:1;			/*"1:显示带符号剩余数据"*/
		 unsigned char DISP_MONEY_FLAG:1;		/*"1:显示剩余金额"*/
        unsigned char DISP_PLUS_FLAG:1;			/*"1:显示正剩余金额"*/
        unsigned char DISP_NEGA_FLAG:1;			/*"1:显示负剩余金额"*/
        unsigned char DISP_MYRIAD_FLAG:1;		/*"1:显示显示万(元),当剩余电(金额)超过79999999时"*/
        unsigned char GPRS_MODEL:1;			/*"无线--> 1:有;0:无"*/ 	
        unsigned char CARRIER_MODEL:1;		/*"载波--> 1:有;0:无"*/ 	
        unsigned char SWITCH_ACT_MODE:1;	/*"跳闸继电器--> 1:外置,电平方式;0:内置,脉冲方式[无继电器时选择外置]"*/ 	
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
extern unsigned char display_Remain_Flag;		/*"0xF0:显示剩余电费"*/
extern unsigned char Card_Type;
extern signed long Remain_Money_Temp;
extern unsigned long Remain_Money_Plus;
extern unsigned long Remain_Money_Nega;
extern unsigned long Power_Plus_Number;			/*"--脉冲负荷数--"*/
extern unsigned long Power_Count_Time;			/*"--负荷计算时间--"*/
//extern unsigned long currentTriff[];
extern unsigned char Card_WR_Buff[512];
extern unsigned char Dir_Return_Flag;                      /*" 直接回写标志 "*/
extern unsigned char Para_Updata_Flag;              /*" 参数更新标志 "*/
extern unsigned char Para_Updata_Flag_Suc;
extern unsigned char Meter_Ins_Flag;
extern unsigned long buyBeforMoney;					/*"购电前剩余电费"*/
extern unsigned long Remain_Money_Plus;			/*"正剩余电费"*/
extern unsigned long Remain_Money_Nega;		/*"过零电费"*/
extern unsigned char eventReportTime;			/*"有事件未上报时,低电平和高电平各5秒"*/
extern unsigned char clearFlag;
extern union ID CurrReadId;				/*"当前读数据时的ID"*/	
//extern unsigned char CurrReadMode;		/*"当前读数据时的读模式"*/
extern unsigned char RunStepNum;			/*"实际运行的梯度数"*/
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

/*"取当前费率尖峰平谷电价(四川,显示时用)"*/
extern int Get_Current_Triff(void);
extern int Get_cur_which_step(void);

#endif	//_ICCARD_H_
