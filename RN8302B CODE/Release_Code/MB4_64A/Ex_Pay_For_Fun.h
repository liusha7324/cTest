
//extern struct _Pre_Power_Down_Save_Data    Pre_Power_Down_Save_Data;
#define Pre_Power_Down_Save_Data	This_Month_Data.Energy_Record.Pre_Save_Data
extern struct _Pre_Payment_Data            Pre_Payment_Data;
extern struct _Pre_Payment_Para            Pre_Payment_Para;
extern struct _Pay_For_Event_Point         Pay_For_Event_Point;         /*" �¼���¼ָ�붨�� "*/

extern unsigned char Buy_ID; 
extern unsigned char Relay_Alarm_SWitch_Flag[2][2];
extern unsigned char Buzzer_Alarm_SWitch_Flag;
extern union  BYTE_BIT Buzzer_Alarm_Control;
extern unsigned long Curr_Money;                                 /*" ��ǰ��� "*/
extern unsigned long Curr_Money_T;                             /*" ��ǰ��ʱ��� "*/
extern unsigned long Curr_Money_S;                             /*" ��ǰ�ݶȵ�� "*/
extern unsigned char relayPlusTime;			/*"���ü̵���,2�����һ������"*/
extern unsigned char relayPlusCnt;			/*"���ü̵�������ʱ�������"*/
extern unsigned char R_CARD_ERROR_INFO;

extern union Pay_For_Users_Flag6  Pay_For_Users_Flag6;   /*" ���Զ��״̬�� "*/
extern union Pay_For_Users_Flag7  Pay_For_Users_Flag7;   /*" �������״̬�� "*/
extern union Pay_For_Users_Flag8  Pay_For_Users_Flag8;   /*" ���״̬�� "*/
extern union Pay_For_Users_Flag16 Pay_For_Users_Flag16;  /*" ����Զ���״̬�� "*/
extern union Pay_For_Users_Flag10 Pay_For_Users_Flag10;
extern union _FAY_CTL_RES_ERR 	Fay_Ctl_Res_Err;
extern union _FAY_CTL_RES_OK 	Fay_Ctl_Res_Ok;



extern unsigned char Curr_Step_Triff;  /*" ��Ȼ�ݶȷ���ָʾ "*/
extern unsigned char Curr_Step_Triff_1;  /*" ��Ȼ�ݶȷ���ָʾ "*/
extern unsigned long Nei_Relay_Do_Energy;
extern unsigned long Nei_Relay_Do_Time;

extern unsigned char Curr_Period_Flag; /*" ��ǰʱ�α��־0~7��Ӧ1~8ʱ�� "*/


/*"**********************************************************************************"*/
extern unsigned int Prepare_CRC_Check(unsigned char * ,unsigned int );


extern void My_Memcpy(unsigned char *,unsigned char *,unsigned char); /*" ����ת�� "*/

extern unsigned char Pay_EE_W(unsigned int,unsigned char * ,unsigned int,
                              unsigned char,unsigned char *,unsigned int,unsigned int);

extern unsigned char ClearPaymentEventRecord(unsigned long ,unsigned long );
extern void Pay_Money_Clear(void);
extern void Pay_Data_Clear(void);
extern void Pay_Data_All_Clear(void);
extern void Pre_Moneth_Updata(void);
extern void Pre_Bill(unsigned char *);


extern unsigned char is_year_bill_date(struct DATEANDTIME_DEF *cur);
extern int Pre_Duct_Data_Clear(void);
//?????????extern unsigned char pay_Led_Alarm(void);
/*" ��������غ��� "*/
extern void Buzzer_Init(void);
extern void Buzzer_Second_Active(void);
extern unsigned char Buzzer_Active(void);
extern void Buzzer_Pay_Cortrol(unsigned int,unsigned char,unsigned char);
extern void Inttupt_Buzzer_Deal(void);
/*" �̵�����غ��� "*/
extern void Relay_Deal_Init(void);
extern void Drive_Act_Repair(void);
extern void Relay_Deal(unsigned char);
/*"Һ�����ⱨ�� "*/
extern void Lcd_Light_Control(void);
extern void Pay_Led(void);

/*" �忨����������� "*/
extern void Card_Alarm_Switch(void);

/*" �۷� "*/
extern void Remain_Money_Duct(unsigned char);

/*" ʣ���ѱ��� "*/
extern void Remain_Money_Alarm_Judge(void);

/*" �ϵ縳ȱʡ���������жϲ����Ϸ��� "*/
extern void Pay_For_Para_Init(void);
extern void Pay_For_Para_Read(void);

/*" Ԥ���Ѳ�������д�ڿ� "*/
extern void Pay_For_Para_Down_Save(void);
extern void Pay_For_Data_Save(void);
extern void Pay_For_Para_Down_Check(void);
extern void Pay_Event_Record_Data(void);

extern void Pay_Event_Record_Clear(void);

extern void Find_Step_Curr_Triff_2(void);


/*"**********************************************************************************"*/
/*"˲����¼���¼���ݸ�ʽ"*/
extern void Pay_For_Event_Dot(const unsigned char * );
extern const struct Pay_Time_Drop_Event_format Buy_Event;
extern const struct Pay_Time_Drop_Event_format Far_On_Event;
extern const struct Pay_Time_Drop_Event_format Far_OFF_Event;
extern const struct Pay_Time_Drop_Event_format Triff_Switch_Event;
extern const struct Pay_Time_Drop_Event_format Triff_Updata_Event;
extern const struct Pay_Time_Drop_Event_format Step_Switch_Event;
extern const struct Pay_Time_Drop_Event_format Step_Updata_Event;
extern const struct Pay_Time_Drop_Event_format Far_Key_Updata_Event;
extern const struct Pay_Time_Drop_Event_format OPCardErr_Event;		//Li Update 20130106		OPCardErr_Event_format
extern const struct Pay_Period_Event_format RelayErr_Event;
extern const struct Pay_Time_Drop_Event_format ProgramTriff_Event;
extern const struct Pay_Time_Drop_Event_format ProgramStep_Event;
extern const struct Pay_Time_Drop_Event_format E_Burse_Event;
extern const struct Pay_Time_Drop_Event_format Refundment_Event;



	
/*" ʱ�������¼���¼ "*/
extern void Pay_For_Event_Period(const unsigned char * ,unsigned char );


/*" ����жϷ����л� "*/
extern void Run_Triff_Switch(unsigned char);


/*" ʵʱ��־���±�־_ "*/
extern void Pay_Real_Flag_Updata(void);

/*" ʵʱ��־���±�־_ "*/
extern void Hour_Freeze_Run(void);

extern void lxrBcd_Hex(unsigned char ,unsigned char *);

extern void Find_Curr_Money(void);
extern void Switch_Plus_Start(unsigned char);
extern void Switch_Plus_Drive(void);
extern void Button_Alarm_Switch(void);
extern void switch_year_stage_mouth_stage(void);
extern unsigned char get_run_step_num(void);

extern void Current_Over_30A_Function(void);

