
#ifndef PAY_FOR_FUN_H
#define PAY_FOR_FUN_H

//struct _Pre_Power_Down_Save_Data    Pre_Power_Down_Save_Data;
#define Pre_Power_Down_Save_Data	This_Month_Data.Energy_Record.Pre_Save_Data
struct _Pre_Payment_Data            Pre_Payment_Data;
struct _Pre_Payment_Para            Pre_Payment_Para;
struct _Pay_For_Event_Point         Pay_For_Event_Point;         /*" 事件记录指针定义 "*/

struct _OPCard_Error_format  OPCard_Error_format;



unsigned char Buy_ID; 
unsigned char Pay_Para_Read_EE;                                 /*" 最新数据当前保存的内卡位置 "*/
unsigned char No_Ram_EE;                                 /*" RAM没有对应结构的数据查找正确的内卡地址 "*/
unsigned long Next_Energy_Step;                           /*" 下一个梯度值 "*/
unsigned long Curr_Money;                                 /*" 当前电费 "*/
unsigned long Curr_Money_T;                                 /*" 当前分时电费 "*/
unsigned long Curr_Money_S;                                 /*" 当前梯度电费 "*/

unsigned char Buzzer_Alarm_SWitch_Flag;
union  BYTE_BIT Buzzer_Alarm_Control;	/*"按键解除声报警"*/
union  BYTE_BIT Buzzer_Alarm_Control_Flag;	/*"欠电费产生一次声报警"*/


struct YEAR_BILLDATE_DEF  R_YearBillDate;



/*" BIT 0  Comm Alarm "*/
/*" BIT 1  MONEY LOW ALARM1 "*/
/*" BIT 2  MONEY LOW ALARM2 "*/
/*" BIT 3  MONEY LOW ZERO "*/
/*" BIT 4  MONEY LOW TICK "*/
/*" BIT 5  OVER POWER "*/
/*" BIT 6  SWITCH ERR "*/
/*" BIT 7  FAR CONTROL"*/

unsigned char Relay_Alarm_SWitch_Flag[2][2];                    /*" [0][X]:报警，[1][X]:跳闸 "*/
                                                                /*" [X][0]:主模式，[X][1]:跟随 "*/
/*" ALARM RELAY "*/                           /*" Switch RELAY "*/
/*" BIT 0  OVER POWER "*/                     /*" BIT 0  OVER POWER "*/
/*" BIT 1  ERROR "*/                          /*" BIT 1  保留 "*/
/*" BIT 2  MONEY LOW ALARM2 "*/               /*" BIT 2  MONEY LOW ALARM2 "*/
/*" BIT 3  MONEY LOW ZERO "*/                 /*" BIT 3  MONEY LOW ZERO "*/
/*"                   "*/                     /*" BIT 4  MONEY LOW TICK "*/
/*" BIT 5  FAR CONTROL"*/                 	/*" BIT 5  FAR CONTROL"*/
/*"                   "*/                 	/*" BIT 6  FAR WARN"*/

																
unsigned char Switch_Test_Time;
//unsigned char Switch_Test_Flag=0;
#define Switch_Test_Flag	Pre_Payment_Para.Switch_Test_Num


union Pay_For_Users_Flag6  Pay_For_Users_Flag6;   /*" 表计远程状态字 "*/
union Pay_For_Users_Flag7  Pay_For_Users_Flag7;   /*" 表计运行状态字 "*/
union Pay_For_Users_Flag8  Pay_For_Users_Flag8;   /*" 表计状态字 "*/
union Pay_For_Users_Flag16 Pay_For_Users_Flag16;  /*" 电表自定义状态字 "*/
union Pay_For_Users_Flag10 Pay_For_Users_Flag10;
union _FAY_CTL_RES_ERR  Fay_Ctl_Res_Err;
union _FAY_CTL_RES_OK 	Fay_Ctl_Res_Ok;




unsigned char Curr_Step_Triff;  /*" 当然梯度费率指示 "*/
unsigned char Curr_Step_Triff_1;
unsigned long Nei_Relay_Do_Energy;
unsigned long Nei_Relay_Do_Time;
extern unsigned char R_CARD_ERROR_INFO;
extern unsigned char cpucard_number[8];        /*"cpu卡号, 分散因子"*/
extern unsigned char oprateCode[4];

/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 购电事件记录参数入口 "*/
/*" 参考3月5日协议版本 "*/
#pragma SECTION rom UserROMData
const struct Event_format Buy_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&Pre_Payment_Para.Buy_Count),4,
    (unsigned char *)(&Pre_Payment_Data.Last_Buy_Money),4,
    (unsigned char *)(&buyBeforMoney),4,
    (unsigned char *)(&Remain_Money_Plus),4,
    (unsigned char *)(&Pre_Payment_Data.Total_Buy_Money),4+0x8000,
};
const struct Pay_Time_Drop_Event_format Buy_Event=
{
    (const unsigned char *)Buy_Event_format,
    BUY_EVENT_FILE,
    BUY_EVENT_NUMBER,
    BUY_EVENT_P_OFFSET,
    buy_money_event,
};


//-----------------------------------------------------------------------//
/*"插卡异常"*/					//Li Update 20130106
#pragma SECTION rom UserROMData
const struct Event_format OPCardErr_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&Co.b[500]),8,
    (unsigned char *)(&R_CARD_ERROR_INFO),1,
    (unsigned char *)(&OPCard_Error_format.CMD[0]),5,
    (unsigned char *)(&OPCard_Error_format.Response[0]),2,
    (unsigned char *)(&Pre_Payment_Para.Buy_Count),2,
    (unsigned char *)(&Remain_Money_Plus),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),4+0x8000,
};



const struct Pay_Time_Drop_Event_format OPCardErr_Event=
{
	 (const unsigned char *)OPCardErr_Event_format,
    OPCARD_ERROR_EVENT_FILE,
    OPCARD_ERROR_EVENT_NUMBER,
    OPCARD_ERROR_EVENT_P_OFFSET,
    0,
};
#if 0
//-----------------------------------------------------------------------//
/*"月结算日事件,暂时没用"*/	
#pragma SECTION rom UserROMData
const struct Event_format Month_Bill_Event_format[]=
{
    (unsigned char *)(&softdate),4+0x8000,
};

const struct Pay_Time_Drop_Event_format Month_Bill_Event=
{
	 (const unsigned char *)Month_Bill_Event_format,
    Month_Bill_EVENT_FILE,
    Month_Bill_EVENT_NUMBER,
    Month_Bill_EVENT_P_OFFSET,
    0,
};	
#endif

//-----------------------------------------------------------------------//
/*"退费记录"*/				//Li Update 20130106
#pragma SECTION rom UserROMData
const struct Event_format Refundment_Event_format[]=
{
    (unsigned char *)(&softdate),6,							/*"退费日期"*/
    (unsigned char *)(&Pre_Payment_Para.Buy_Count),2,	/*"退费前购电次数"*/
    (unsigned char *)(&Pre_Payment_Para.SendBack_Money),4,	/*"退费金额"*/		
    (unsigned char *)(&buyBeforMoney),4,					/*"退费前剩余金额"*/		
    (unsigned char *)(&Remain_Money_Plus),4+0x8000,		/*"退费后剩余金额"*/	
};



const struct Pay_Time_Drop_Event_format Refundment_Event=
{
	 (const unsigned char *)Refundment_Event_format,
    REFUNDMENT_EVENT_FILE,
    REFUNDMENT_EVENT_NUMBER,
    REFUNDMENT_EVENT_P_OFFSET,
    0,
};	

//-----------------------------------------------------------------------//


//-----------------------------------------------------------------------//
/*"负荷开关误动作"*/		//Li Update 20130106
#pragma SECTION rom UserROMData
const struct Event_format RelayErr_Event_format[]=
{
    (unsigned char *)(&softdate),6,
	(unsigned char *)(&Co.b[510]),6,	//(&Pre_Payment_Data.PowerDownTime[0])
    (unsigned char *)(&Co.b[500]),1,
	(unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),4+0x8000,
};
const struct Event_format_d RelayErr_Event_format_d[]=
{
    0x01,0x06,
    0x02,0x06,
    0x01,0x01,
    0x01,0x04,
    0x01,0x04,
    0x02,0x04,
    0x02,0x04,
};


const struct Pay_Period_Event_format RelayErr_Event=
{
	(const unsigned char *)RelayErr_Event_format,
	(const unsigned char *)RelayErr_Event_format_d,
    RELAYERR_EVENT_FILE,
    RELAYERR_EVENT_NUMBER,
    RELAYERR_AREA_EE,
    RELAYERR_EVENT_P_OFFSET,
    0,
};	
//-----------------------------------------------------------------------//



//-----------------------------------------------------------------------//
/*"费率表编程记录"*/		//Li Update 20130107
#pragma SECTION rom UserROMData
const struct Event_format ProgramTriff_Event_format[]=
{
	(unsigned char *)(&softdate),6,
	(unsigned char *)(&oprateCode),4,
	(unsigned char *)(& Pre_Payment_Para.Triff[0][0]),4*(PRE_MAX_TRIFF),	//PRE_MAX_TRIFF
	(unsigned char *)(& Pre_Payment_Para.Triff[1][0]),4*(PRE_MAX_TRIFF)+0x8000,	//PRE_MAX_TRIFF
};


const struct Pay_Time_Drop_Event_format ProgramTriff_Event=
{
	(const unsigned char *)ProgramTriff_Event_format,
    PROGRAMTRIFF_EVENT_FILE,
    PROGRAMTRIFF_EVENT_NUMBER,
    PROGRAMTRIFF_EVENT_P_OFFSET,
    0,
};	
//-----------------------------------------------------------------------//



//-----------------------------------------------------------------------//
/*"阶梯表编程记录"*/		//Li Update 20130107
#pragma SECTION rom UserROMData
const struct Event_format ProgramStep_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&oprateCode),4,
	(unsigned char *)(& Pre_Payment_Para.Energy_Step[0][0]),4*MAX_STEP,
	(unsigned char *)(& Pre_Payment_Para.Triff_Step[0][0]),4*(MAX_STEP+1),
	(unsigned char *)(& Pre_Payment_Para.Year_BillDate[0][0]),3*4,
	(unsigned char *)(& Pre_Payment_Para.Energy_Step[1][0]),4*MAX_STEP,
	(unsigned char *)(& Pre_Payment_Para.Triff_Step[1][0]),4*(MAX_STEP+1),
	(unsigned char *)(& Pre_Payment_Para.Year_BillDate[1][0]),3*4+0x8000,
};


const struct Pay_Time_Drop_Event_format ProgramStep_Event=
{
	(const unsigned char *)ProgramStep_Event_format,
    PROGRAMSTEP_EVENT_FILE,
    PROGRAMSTEP_EVENT_NUMBER,
    PROGRAMSTEP_EVENT_P_OFFSET,
    0,
};	
//-----------------------------------------------------------------------//


//-----------------------------------------------------------------------//
/*"电子钱包记录"*/		//Li Update 20130107
#pragma SECTION rom UserROMData
const struct Event_format E_Burse_Event_format[]=
{
    (unsigned char *)(&Pre_Payment_Para.Buy_Count),2,
	(unsigned char *)(&Remain_Money_Plus),4,
	(unsigned char *)(&Remain_Money_Nega),4+0x8000,
	//(unsigned char *)(& Remain_Money_Plus),5+0x8000,
};


const struct Pay_Time_Drop_Event_format E_Burse_Event=
{
	(const unsigned char *)E_Burse_Event_format,
    E_BURSE_EVENT_FILE,
    E_BURSE_EVENT_NUMBER,
    E_BURSE_EVENT_P_OFFSET,
    0,
};	
//-----------------------------------------------------------------------//









//-----------------------------------------------------------------------//
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 远程跳合闸录事件记录参数入口 "*/
/*
const struct Event_format Far_On_Event_format[]=
    {
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&softdate),4,        " 操作者代码 "
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[0][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[1][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[2][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[3][0]),4,
    (unsigned char *)(&Volt[0]),12,
    (unsigned char *)(&COMM_Curr[0]),60,
//    (unsigned char *)(&Curr[0]),60,
    (unsigned char *)(&This_Month_Data.Energy_Record.Phase_Plus_Active[0]),72+0x8000,
    };
*/
#pragma SECTION rom UserROMData
const struct Event_format Far_On_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&softdate),4,        /*" 操作者代码 QQQ bug ??? oprateCode "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[0][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[1][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[2][0]),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[3][0]),4+0x8000,
};
const struct Pay_Time_Drop_Event_format Far_On_Event=
{
    (const unsigned char *)Far_On_Event_format,
    FAR_CONTROL_EVENT_FILE,
    FAR_CONTROL_EVENT_NUMBER,
    FAR_CONTROL_EVENT_P_OFFSET,
    far_conrol_event,
};
const struct Pay_Time_Drop_Event_format Far_OFF_Event=
{
    (const unsigned char *)Far_On_Event_format,
    FAR_CONTROL_FREE_EVENT_FILE,
    FAR_CONTROL_FREE_EVENT_NUMBER,
    FAR_CONTROL_FREE_EVENT_P_OFFSET,
    far_close_event,
};


/*"远程密钥更新事件"*/
#pragma SECTION rom UserROMData
const struct Event_format Far_Key_Updata_format[]=
{
    	(unsigned char *)(&softdate),6,
	(unsigned char *)(&Pre_Payment_Data.oprateCode[0]),4,
	(unsigned char *)(&Pre_Payment_Para.PassWord_Num),1,
	(unsigned char *)(&Co.b[500]),4+0x8000,		/*"密钥更新前状态"*/ //&Pre_Payment_Para.Far_Key_StatusByte
};

const struct Pay_Time_Drop_Event_format Far_Key_Updata_Event=
{
    (const unsigned char *)Far_Key_Updata_format,
    FAR_KEY_UPDATA_EVENT_FILE,
    FAR_KEY_UPDATA_EVENT_NUMBER,
    FAR_KEY_UPDATA_EVENT_P_OFFSET,
    0,
};

/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 冻结事件参数入口 "*/
/*" 参考3月5日协议版本 "*/
/*"本冻结长度为248字节,当超过255字节时要特殊处理"*/
#pragma SECTION rom UserROMData
const struct Event_format Hour_Freeze_Event_format[]=
{
    (unsigned char *)(&softdate),6,                                              /*" 时间 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),36,         /*" 正向有功总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),36,         /*" 反向有功总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[0][0]),36,    /*" 1象限总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[1][0]),36,    /*" 2象限总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[2][0]),36,    /*" 3象限总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[3][0]),36,    /*" 4象限总及各费率电能 "*/
    (unsigned char *)(&This_Month_Data.Demand_Record.Demand.Plus_Active[0]),81,  /*" 正向有功总总及各费率需量及需量时间 "*/
    (unsigned char *)(&This_Month_Data.Demand_Record.Demand.Nega_Active[0]),81,  /*" 反向有功总总及各费率需量及需量时间 "*/
    (unsigned char *)(&COMM_Active_power[0]),32+0x8000,                          /*" 正向总ABC以及反向总ABC功率 "*/
	//    (unsigned char *)(&Active_power[0]),32+0x8000,                                 /*" 正向总ABC以及反向总ABC功率 "*/
};

/*
const struct Pay_Time_Drop_Event_format Hour_Freeze_Event=
    {
    (const unsigned char *)Hour_Freeze_Event_format,
    HOUR_FREEZE_EVENT_FILE,
    HOUR_FREEZE_EVENT_NUMBER,
    HOUR_FREEZE_EVENT_P_OFFSET,
    0,
    };*/
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 预付费结算事件参数入口 "*/

/*"const struct Event_format Money_Balance_Event_format[]=
    {
    (unsigned char *)(&Pre_Power_Down_Save_Data.Total_User_Money),4+0x8000,
    };

const struct Pay_Time_Drop_Event_format Money_Balance_Event=
    {
    (const unsigned char *)Money_Balance_Event_format,
    MONEY_BALANCE_EVENT_FILE,
    MONEY_BALANCE_EVENT_NUMBER,
    MONEY_BALANCE_EVENT_P_OFFSET,
    0,
    };"*/
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 电价切换/修改事件记录参数入口 "*/
/*#pragma SECTION rom UserROMData
const struct Event_format Triff_Switch_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&Pre_Payment_Para.Triff[0][0]),16,
    (unsigned char *)(&Pre_Payment_Para.Triff[1][0]),16,
    (unsigned char *)(&Pre_Power_Down_Save_Data.Remain_Money),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),20,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),20+0x8000,
};*/

/*" 参考3月5日协议版本 "*/
#pragma SECTION rom UserROMData
const struct Pay_Time_Drop_Event_format Triff_Switch_Event=
{
//    (const unsigned char *)Triff_Switch_Event_format,
    (const unsigned char *)Hour_Freeze_Event_format,
    TRIFF_SWITCH_EVENT_FILE,
    TRIFF_SWITCH_EVENT_NUMBER,
    TRIFF_SWITCH_EVENT_P_OFFSET,
    0,
};
/*
const struct Pay_Time_Drop_Event_format Triff_Updata_Event=
    {
    (const unsigned char *)Triff_Switch_Event_format,
    TRIFF_UPDATA_EVENT_FILE,
    TRIFF_UPDATA_EVENT_NUMBER,
    TRIFF_UPDATA_EVENT_P_OFFSET,
    0,
    };*/
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" 梯度切换/修改事件记录参数入口 "*/
/*#pragma SECTION rom UserROMData
const struct Event_format Step_Switch_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&Pre_Payment_Para.Energy_Step[0][0]),72,
    (unsigned char *)(&Pre_Power_Down_Save_Data.Remain_Money),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),20,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),20+0x8000,
};*/

/*" 参考3月5日协议版本 "*/
#pragma SECTION rom UserROMData
const struct Pay_Time_Drop_Event_format Step_Switch_Event=
{
	//    (const unsigned char *)Step_Switch_Event_format,
    (const unsigned char *)Hour_Freeze_Event_format,
    STEP_SWITCH_EVENT_FILE,
    STEP_SWITCH_EVENT_NUMBER,
    STEP_SWITCH_EVENT_P_OFFSET,
    0,
};
/*
const struct Pay_Time_Drop_Event_format Step_Updata_Event=
    {
    (const unsigned char *)Step_Switch_Event_format,
    STEP_UPDATA_EVENT_FILE,
    STEP_UPDATA_EVENT_NUMBER,
    STEP_UPDATA_EVENT_P_OFFSET,
    0,
    };*/

/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*"struct Check_format
    {
    unsigned int Eeprom_Addr;
    unsigned char * Addr;   0表示该数据在RAM没有备份
    unsigned int Length;
    unsigned char Flag;     BIT0对应EE0，BIT1对应EE1，BIT2对应EE2，BIT3对应EE3，
                            BIT7=1表示是最后一帧数据 
    如果该组数据是指向铁链，则表示紧接着的那组数据和上组数据是同一类数据
    }; "*/
/*    
#pragma SECTION rom UserROMData
const struct Check_format Pay_Check_format[]=
{
    PRE_PAYMENT_DATA_EE,(unsigned char *)(&Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,0x03,
    PRE_PAYMENT_PARA_EE,(unsigned char *)(&Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,0x03,
    PAY_FOR_EVENT_POINT_EE,(unsigned char *)(&Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,0x03+0x80,
};*/
/*"**********************************************************************************"*/


unsigned char Pay_Para_Check(const struct Check_format *,unsigned char );
unsigned char Pay_EE_W(unsigned int,unsigned char * ,unsigned int,unsigned char,
                       unsigned char *,unsigned int,unsigned int);

void Pay_For_Para_Init(void);
void Pay_For_Para_Read(void);
void Pay_For_Para_Down_Save(void);
void Pay_For_Data_Save(void);
unsigned char Pay_Para_Check( const struct Check_format *,unsigned char);
unsigned int Get_Event_Data(const unsigned char *,unsigned char *);

unsigned int Get_Event_Data_d(const unsigned char *,const unsigned char *,
	                               unsigned char *,unsigned int,unsigned char);


void Alarm_Relay_Control(void );
void Switch_Relay_Control(void );
void Switch_Plus_Start(unsigned char);
void Switch_Plus_Drive(void);

void Relay_Deal(unsigned char);

void Pay_Event_Record_Clear(void);
void Pay_Event_Record_Data_Clear(void);
void Pay_Money_Clear(void);
void Pay_Data_Clear(void);

void Buzzer_Pay_Cortrol(unsigned int ,unsigned char ,unsigned char );

void lxrBcd_Hex(unsigned char ,unsigned char *);
unsigned long Calculate_20000101_Day(unsigned char * );
unsigned char dayer_acu(unsigned char ,unsigned char ,unsigned char );
unsigned char CharBCDBIN(unsigned char  );
unsigned long Calculate_Time(unsigned char * ,unsigned char * ,unsigned char );
void Find_Step_Curr_Triff(void);

void Find_Step_Curr_Triff_1(void);
void Find_Step_Curr_Triff_2(void);
int Pre_Duct_Data_Clear(void);
void Pay_Event_Record_Data(void);
void Run_Triff_Switch(unsigned char);
void Pay_For_Event_Dot(const unsigned char * );



//extern void FeedWatchdog(void);

#endif	//PAY_FOR_FUN_H


