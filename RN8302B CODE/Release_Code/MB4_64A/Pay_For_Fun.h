
#ifndef PAY_FOR_FUN_H
#define PAY_FOR_FUN_H

//struct _Pre_Power_Down_Save_Data    Pre_Power_Down_Save_Data;
#define Pre_Power_Down_Save_Data	This_Month_Data.Energy_Record.Pre_Save_Data
struct _Pre_Payment_Data            Pre_Payment_Data;
struct _Pre_Payment_Para            Pre_Payment_Para;
struct _Pay_For_Event_Point         Pay_For_Event_Point;         /*" �¼���¼ָ�붨�� "*/

struct _OPCard_Error_format  OPCard_Error_format;



unsigned char Buy_ID; 
unsigned char Pay_Para_Read_EE;                                 /*" �������ݵ�ǰ������ڿ�λ�� "*/
unsigned char No_Ram_EE;                                 /*" RAMû�ж�Ӧ�ṹ�����ݲ�����ȷ���ڿ���ַ "*/
unsigned long Next_Energy_Step;                           /*" ��һ���ݶ�ֵ "*/
unsigned long Curr_Money;                                 /*" ��ǰ��� "*/
unsigned long Curr_Money_T;                                 /*" ��ǰ��ʱ��� "*/
unsigned long Curr_Money_S;                                 /*" ��ǰ�ݶȵ�� "*/

unsigned char Buzzer_Alarm_SWitch_Flag;
union  BYTE_BIT Buzzer_Alarm_Control;	/*"�������������"*/
union  BYTE_BIT Buzzer_Alarm_Control_Flag;	/*"Ƿ��Ѳ���һ��������"*/


struct YEAR_BILLDATE_DEF  R_YearBillDate;



/*" BIT 0  Comm Alarm "*/
/*" BIT 1  MONEY LOW ALARM1 "*/
/*" BIT 2  MONEY LOW ALARM2 "*/
/*" BIT 3  MONEY LOW ZERO "*/
/*" BIT 4  MONEY LOW TICK "*/
/*" BIT 5  OVER POWER "*/
/*" BIT 6  SWITCH ERR "*/
/*" BIT 7  FAR CONTROL"*/

unsigned char Relay_Alarm_SWitch_Flag[2][2];                    /*" [0][X]:������[1][X]:��բ "*/
                                                                /*" [X][0]:��ģʽ��[X][1]:���� "*/
/*" ALARM RELAY "*/                           /*" Switch RELAY "*/
/*" BIT 0  OVER POWER "*/                     /*" BIT 0  OVER POWER "*/
/*" BIT 1  ERROR "*/                          /*" BIT 1  ���� "*/
/*" BIT 2  MONEY LOW ALARM2 "*/               /*" BIT 2  MONEY LOW ALARM2 "*/
/*" BIT 3  MONEY LOW ZERO "*/                 /*" BIT 3  MONEY LOW ZERO "*/
/*"                   "*/                     /*" BIT 4  MONEY LOW TICK "*/
/*" BIT 5  FAR CONTROL"*/                 	/*" BIT 5  FAR CONTROL"*/
/*"                   "*/                 	/*" BIT 6  FAR WARN"*/

																
unsigned char Switch_Test_Time;
//unsigned char Switch_Test_Flag=0;
#define Switch_Test_Flag	Pre_Payment_Para.Switch_Test_Num


union Pay_For_Users_Flag6  Pay_For_Users_Flag6;   /*" ���Զ��״̬�� "*/
union Pay_For_Users_Flag7  Pay_For_Users_Flag7;   /*" �������״̬�� "*/
union Pay_For_Users_Flag8  Pay_For_Users_Flag8;   /*" ���״̬�� "*/
union Pay_For_Users_Flag16 Pay_For_Users_Flag16;  /*" ����Զ���״̬�� "*/
union Pay_For_Users_Flag10 Pay_For_Users_Flag10;
union _FAY_CTL_RES_ERR  Fay_Ctl_Res_Err;
union _FAY_CTL_RES_OK 	Fay_Ctl_Res_Ok;




unsigned char Curr_Step_Triff;  /*" ��Ȼ�ݶȷ���ָʾ "*/
unsigned char Curr_Step_Triff_1;
unsigned long Nei_Relay_Do_Energy;
unsigned long Nei_Relay_Do_Time;
extern unsigned char R_CARD_ERROR_INFO;
extern unsigned char cpucard_number[8];        /*"cpu����, ��ɢ����"*/
extern unsigned char oprateCode[4];

/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
/*" �����¼���¼������� "*/
/*" �ο�3��5��Э��汾 "*/
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
/*"�忨�쳣"*/					//Li Update 20130106
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
/*"�½������¼�,��ʱû��"*/	
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
/*"�˷Ѽ�¼"*/				//Li Update 20130106
#pragma SECTION rom UserROMData
const struct Event_format Refundment_Event_format[]=
{
    (unsigned char *)(&softdate),6,							/*"�˷�����"*/
    (unsigned char *)(&Pre_Payment_Para.Buy_Count),2,	/*"�˷�ǰ�������"*/
    (unsigned char *)(&Pre_Payment_Para.SendBack_Money),4,	/*"�˷ѽ��"*/		
    (unsigned char *)(&buyBeforMoney),4,					/*"�˷�ǰʣ����"*/		
    (unsigned char *)(&Remain_Money_Plus),4+0x8000,		/*"�˷Ѻ�ʣ����"*/	
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
/*"���ɿ�������"*/		//Li Update 20130106
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
/*"���ʱ��̼�¼"*/		//Li Update 20130107
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
/*"���ݱ��̼�¼"*/		//Li Update 20130107
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
/*"����Ǯ����¼"*/		//Li Update 20130107
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
/*" Զ������բ¼�¼���¼������� "*/
/*
const struct Event_format Far_On_Event_format[]=
    {
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&softdate),4,        " �����ߴ��� "
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
    (unsigned char *)(&softdate),4,        /*" �����ߴ��� QQQ bug ??? oprateCode "*/
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


/*"Զ����Կ�����¼�"*/
#pragma SECTION rom UserROMData
const struct Event_format Far_Key_Updata_format[]=
{
    	(unsigned char *)(&softdate),6,
	(unsigned char *)(&Pre_Payment_Data.oprateCode[0]),4,
	(unsigned char *)(&Pre_Payment_Para.PassWord_Num),1,
	(unsigned char *)(&Co.b[500]),4+0x8000,		/*"��Կ����ǰ״̬"*/ //&Pre_Payment_Para.Far_Key_StatusByte
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
/*" �����¼�������� "*/
/*" �ο�3��5��Э��汾 "*/
/*"�����᳤��Ϊ248�ֽ�,������255�ֽ�ʱҪ���⴦��"*/
#pragma SECTION rom UserROMData
const struct Event_format Hour_Freeze_Event_format[]=
{
    (unsigned char *)(&softdate),6,                                              /*" ʱ�� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),36,         /*" �����й��ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),36,         /*" �����й��ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[0][0]),36,    /*" 1�����ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[1][0]),36,    /*" 2�����ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[2][0]),36,    /*" 3�����ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Energy_Record.Quad_Reactive[3][0]),36,    /*" 4�����ܼ������ʵ��� "*/
    (unsigned char *)(&This_Month_Data.Demand_Record.Demand.Plus_Active[0]),81,  /*" �����й����ܼ�����������������ʱ�� "*/
    (unsigned char *)(&This_Month_Data.Demand_Record.Demand.Nega_Active[0]),81,  /*" �����й����ܼ�����������������ʱ�� "*/
    (unsigned char *)(&COMM_Active_power[0]),32+0x8000,                          /*" ������ABC�Լ�������ABC���� "*/
	//    (unsigned char *)(&Active_power[0]),32+0x8000,                                 /*" ������ABC�Լ�������ABC���� "*/
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
/*" Ԥ���ѽ����¼�������� "*/

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
/*" ����л�/�޸��¼���¼������� "*/
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

/*" �ο�3��5��Э��汾 "*/
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
/*" �ݶ��л�/�޸��¼���¼������� "*/
/*#pragma SECTION rom UserROMData
const struct Event_format Step_Switch_Event_format[]=
{
    (unsigned char *)(&softdate),6,
    (unsigned char *)(&Pre_Payment_Para.Energy_Step[0][0]),72,
    (unsigned char *)(&Pre_Power_Down_Save_Data.Remain_Money),4,
    (unsigned char *)(&This_Month_Data.Energy_Record.Plus_Active[0]),20,
    (unsigned char *)(&This_Month_Data.Energy_Record.Nega_Active[0]),20+0x8000,
};*/

/*" �ο�3��5��Э��汾 "*/
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
    unsigned char * Addr;   0��ʾ��������RAMû�б���
    unsigned int Length;
    unsigned char Flag;     BIT0��ӦEE0��BIT1��ӦEE1��BIT2��ӦEE2��BIT3��ӦEE3��
                            BIT7=1��ʾ�����һ֡���� 
    �������������ָ�����������ʾ�����ŵ��������ݺ�����������ͬһ������
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


