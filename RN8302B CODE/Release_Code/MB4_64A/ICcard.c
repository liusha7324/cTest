//ICcard.c
//------------------------------------------
#include "Defdata.h"
#include "Defmcro.h"
#include "comm.h"  //for GetNowTime()
#include "I2C_operation.h"
#include "interrupt.h"
#include "MB_Keymain.h"
#include "MB_Showmain.h"
#include "HT_1623.H"
#include "ram.h"		//for Meter_parameter
#include "MB_BASE_FUN.h"
#include "Initram.h"
#include "Att7022_operation.h"
#include "Demand.h"
#include "File_System.h"
#include "EVENTNEW.H"
#include "Multi.h"
#include "eeprom.h"
#include "freeze.h"
#include "Measure_Interface.h" 
#include "Energy_Del.H"

#include "Pay_def.h"
#include "Card_File.h"
#include "Far_pay.h"
#include "Ex_Card_Data.h"
#include "Ex_Pay_For_Fun.h"
#include "Ex_Cpucard_Driver.h"
#include "ICcard.h"

#include "BackLight_Ctrl.h"
//------------------------------------------
union byte_def IC_FLAG;								/*"bit1:1.���������"*/
char maxSetpNum=0;						/*"����ݶ���"*/
unsigned char display_Remain_Flag=0;		/*"0xF0:��ʾʣ����(0x80:�̶�);0x0F:��ʾ�����"*/
//unsigned char display_ICErr_Flag=0;			/*"IC��������ʾ1:��ʾ0:��ʧ"*/
unsigned char buy_money_OK_flag=0;		/*"����ɹ�ʱ,��ʾ"����",��ֹ"��"��ʾ"*/
unsigned char Card_Type=0;							/*"������"*/
unsigned long buyBeforMoney=0;					/*"����ǰʣ�����޸�Ϊ�޷���������"*/
signed long Remain_Money_Temp;			/*"������ʣ����(��ʾ��)"*/
unsigned long Remain_Money_Plus=0;			/*"��ʣ����"*/
unsigned long Remain_Money_Nega=0;		/*"������"*/
//unsigned char energyMoeny_flag=0;			/*"0:Ԥ���ѵ���,1:Ԥ���ѵ��"*/
//unsigned long Power_Plus_Number=0;		/*"--���帺����--"*/
//unsigned long Power_Count_Time=0;  			/*"--���ϼ���ʱ��--"*/
//unsigned char overpower_plus_flag=0;		/*"--�����ɱ�־--"*/
unsigned char clearFlag=0;					/*"1:Ԥ�ÿ�������ʱ��������ѿ�����"*/
unsigned char Card_WR_Buff[512];
//unsigned long oldTriff[4];
//unsigned char currentTriff[4*(MAX_STEP*2+1)+3];
unsigned char oprateCode[4];
union ICcard_Flag1 ICcard_Flag1;
//unsigned char Curr_Err=0;
unsigned char UpPowerSecond=0;			/*"�ϵ�ʱ,�����̵�������һ��"*/
unsigned char Relay_Pro_Act_Time=0;		/*"�̵����޶���150���Ӻ�,���ü̵����ظ�����һ��"*/


//unsigned char eventReportTime;
unsigned char Buy_Money_Flag;  	/*"bit0:��д,bit3:���濨���,�������ÿ���״̬,bit4:���,bit7:��ֵ"*/
unsigned char Para_Updata_Flag;              /*" �������±�־ "*/
unsigned char Para_Updata_Flag_Suc;              /*" �������±�־ "*/
unsigned char Meter_Ins_Flag;
union ID CurrReadId;				/*"��ǰ������ʱ��ID"*/	
//unsigned char CurrReadMode;		/*"��ǰ������ʱ�Ķ�ģʽ"*/
unsigned char RunStepNum=0;		/*"ʵ�����е��ݶ���"*/

unsigned char R_CARD_ERROR_INFO;				/*"Li_������Ϣ��"*/
unsigned char RelayErrCheckNum=0;				/*"�̵����������������"*/
unsigned char RelayOkCheckNum=0;				/*"�̵�����ȷ����������"*/
unsigned char RelayActStaCheckNum=0;			/*"�̵�������3���,ˢ��״̬��3����բָʾ��"*/
//unsigned char G_Rec_Disp_Flg=0;					/*"1:���¼���¼�����仯ʱ��������ʾ���ݣ�ʹ�����ڵ͹�������ʾ"*/


extern union SECURITY_AUTH_ERR_INFORMATION Far_Security_Auth_Err_Info;
extern struct _OPCard_Error_format  OPCard_Error_format;
extern unsigned long    Clear_all_oper_code;	
extern unsigned long    Clear_demand_oper_code;
extern unsigned char Curr_Period_Flag;

//------------------------------------------

//internal
void Card_Judge(void);
void Card_pull_out(void);
void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len);
void Reverse_data(unsigned char *data,unsigned int len);
void Energy_Change_Process(void);
unsigned char Get_PreData(unsigned char *data,unsigned char selSrc);
unsigned char Jude_Hoard_Money(unsigned long money,unsigned long hoardLimit);
unsigned char SetIn_card_write_back(void);
unsigned char User_card_write_back(unsigned char mode);
unsigned char Card_Operate(void);

unsigned char Buy_Card(void);
unsigned char Check_Card(void);
unsigned char Triff_Card(void);
unsigned char Relay_TEST_Card(void);
unsigned char Set_In_Card(void);
unsigned char Password_Card(void);
unsigned char Add_Money_Card(void);
unsigned char Modify_MeterID_Card(void);

unsigned int CardProgrammeEvent(void);
void Meter_Money_And_Count_Updata( unsigned long ,unsigned long );
unsigned char Frame_Judge(unsigned char * ,unsigned char );
unsigned char Updata_Esam_Return_File(unsigned char, unsigned long ,unsigned long);
unsigned char Cal_Add_CS(unsigned char * ,unsigned char );
unsigned char Judge_Remain_Money_Over(unsigned long );
//extern
void ICcard_Main(void);
void Pre_Init(void);
void Pre_Display(unsigned char );
void Pre_Display_Char_Flash(void);
unsigned char Pre_Static_Display_Remain(void);
void Pre_Get_OverZero_Money(void);
void FarSwitchControl(unsigned char uartx);
void buy_money_event(unsigned char *);
void far_conrol_event(unsigned char *);
void far_close_event(unsigned char *);
void getCarrierGprs(void);
void Pay_Relay_Err_End(void);
void Pay_Relay_Err_Check(void);

extern unsigned char  Clear_All_New(unsigned long);


#pragma SECTION rom UserROMData
/*"1~3:31, 4~10:32,       11~13:33, 14~18:34, 19~20:35, 21:36"*/
const unsigned char CARD_ERR_INF[]=
{0, 1,1,1,    2,2,2,2,2,2,2, 3,3,3,        4,4,4,4,4,   5,5,          6};

//----------------------------------------------
//#pragma SECTION program program_protect
//use of main.c	
/*"IC��������"*/
void ICcard_Main(void)
{
	unsigned char i,Lev;
	unsigned long Esam_Far_Identity_Auth_Valid_Time_T;
    unsigned long infrare_valid_time;
    unsigned long now;
    unsigned long remain;

	if( Far_Identity_Auth_Ok_Flag==0xFF ) {
		Esam_Far_Identity_Auth_Valid_Time_T = Esam_Far_Identity_Auth_Valid_Time;
		Esam_Far_Identity_Auth_Valid_Time_T *= NUM_MS_PER_MINUTE;
        now = GetNowTime();
		if(GetTimeCount(Far_Identity_Auth_Ok_Time,Esam_Far_Identity_Auth_Valid_Time_T) == 0) {
			Far_Identity_Auth_Ok_Flag = 0;
            R_ID_Remain_Time = 0;	
        } else {
            remain = Esam_Far_Identity_Auth_Valid_Time_T - (now - Far_Identity_Auth_Ok_Time);
            R_ID_Remain_Time = (remain + (NUM_MS_PER_MINUTE - 1)) / NUM_MS_PER_MINUTE;/*"����1���Ӱ�1���Ӵ���"*/
        }
    }

    if (Far_InfraredFlag) {
        infrare_valid_time = Pre_Payment_Para.InfrIdenTime * NUM_MS_PER_MINUTE;    /*"������֤ͨ����30����(�ú����ʾ)��Ч"*/
        now = GetNowTime();
		if(GetTimeCount(Far_Infrared_Auth_Ok_Time, infrare_valid_time) == 0) {
			end_infrared_auth();
        } else {
            remain = infrare_valid_time - (now - Far_Infrared_Auth_Ok_Time);
            R_Infrared_Remain_Time = (remain + (NUM_MS_PER_MINUTE - 1)) / NUM_MS_PER_MINUTE;/*"����1���Ӱ�1���Ӵ���"*/
        }
    }

	if( MainSoftDate.Day != Pre_Payment_Para.Far_Day_Follow )	/*"�����ʱ�������״̬(������֤����)"*/
		{
		Pre_Payment_Para.Far_Day_Follow = MainSoftDate.Day;
		Pay_EE_W(FAR_DAY_FOLLOW_EE,(unsigned char *)&(Pre_Payment_Para.Far_Day_Follow),1,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

		Pre_Payment_Data.HangMeterNum=0;						//Li Update 20130105
		HANG_ERR_DEFINE=0;
		Pay_EE_W(HANGMETER_EE,(unsigned char *)&(Pre_Payment_Data.HangMeterNum),1,3,
				    (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		
		for(Lev=0;Lev<MAX_PASS_NUM;Lev++)	/*"�����ʱ���������������"*/
			{
			for(i=0;i<sizeof(struct PASSWORDERR);i++)
				*((unsigned char *)&Other_Data.PasswordErr[Lev]+i)=0;
			}
		WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,MAX_PASS_NUM*sizeof(struct PASSWORDERR)+1,0,0);
			
		//if( Pre_Payment_Para.ID_Ins_Counter>= AUTH_ERR_LIMIT )
		//	{
		//	Pre_Payment_Para.ID_Ins_Counter = 0;
		//	Pay_EE_W(ID_INS_COUNTER_EE,(unsigned char *)&(Pre_Payment_Para.ID_Ins_Counter),1,3,
		//		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		//	}
		}

	if (PAY_BUY_MONEY_FLG_DEFINE)
		{
		PAY_BUY_MONEY_FLG_DEFINE=0;
		/*"�����ǿ�Ʊ���,��ֹ�����,�ٵ��ϵ��ƽ���͹��ı���2�θ�λ���,ȡ�����������ݵ�����,��ʹ��Ѷ�ʧ"*/
		Check_Energy_main(1);
		Check_Energy_main(1);
		}
	if (REC_FLG_DEFINE)
		{
		REC_FLG_DEFINE=0;
		Check_Show_Flash_Data(0xff,0,0xff,0);
		}
	//--------------------------------------------------//


	if(!MACRO_LOCAL_PAY_FLAG)
		{
		return;
		}

	for (i=0;i<8;i++)
	{
		if(Check_CPU_Occur())
		{
			Card_pull_out();
			return;
		}
	}
	if(IC_FLAG.bit.b1==0)
		{
		Card_Judge();
		IC_FLAG.bit.b1=1;
		}

	}

void Pay_Status_Flag(void)
{
	maxSetpNum=Pre_Payment_Para.Step_Num[0]+1;
	NEW645Meter_States.Meter_Status3.bit.MeterType_L=0;		/*"HL:00��Ԥ����,01Ԥ���ѵ�����,10Ԥ���ѵ�ѱ�"*/
	NEW645Meter_States.Meter_Status3.bit.MeterType_H=MACRO_LOCAL_PAY_FLAG;

	NEW645Meter_States.Meter_Status3.bit.WhitchTriffIsNow=0;
	NEW645Meter_States.Meter_Status3.bit.WhitchStepIsNow=0;

    if (MACRO_LOCAL_PAY_FLAG)
    {
    	NEW645Meter_States.Meter_Status3.bit.local_open_account=!STATUS_LOCALOPEN_DEFINE;	/*"Զ��_0:����,1:δ����"*/
    	NEW645Meter_States.Meter_Status3.bit.far_open_account=!STATUS_FAROPEN_DEFINE;		/*"Զ��_0:����,1:δ����"*/
    }
	NEW645Meter_States.Meter_Status3.bit.keep_power_status=METER_IN_FRIEND_DAY_DEFINE;	/*"����״̬"*/	
}

//use of ReadEepromEnergy()	
/*"�ϵ����һ��"*/
void Pre_Init(void)
{
	Buzzer_Init();	
	Relay_Deal_Init();

	Pay_For_Users_Flag10.intd=0;
	IC_FLAG.byte=0;
	ICcard_Flag1.intd=0;
	IC_FLAG.bit.b1=1;		//don't read card when power up

	getRelayType();
	if (SWITCH_FACT_DEFINE)
		{
		FAR_OPEN_RECORD_DEFINE=1;
		FAR_CLOSE_RECORD_DEFINE=0;
		}
	else
		{
		FAR_OPEN_RECORD_DEFINE=0;
		FAR_CLOSE_RECORD_DEFINE=1;
		}	
	if (!MACRO_LOCAL_PAY_FLAG)	//model
	{
		ESAM_RST_Control(0);
		ESAM_CLK_Control(0);
		ESAM_VCC_Control(0);
		if (!MACRO_FAY_CONTROL_FLAG)
		{
			SWITCH_CLOSE=0;
			SWITCH_OPEN=0;
			SWITCH_RELAY=0;
			SWITCH_FACT_DEFINE=0;
			displayCharOnOff(DISP_CHAR_SWITCH,0,0);
		}
	}

	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		return;
	Pre_Get_OverZero_Money();
	SWITCH_PREPARE_STATE_DEFINE=1;
	Far_Switch_Control(0);
	Pay_Relay_Err_End();
	RunStepNum=get_run_step_num();
	NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=0;
	NEW645Meter_States.Meter_Status3.bit.SwitchAlarmStatus=0;	
	Pay_Status_Flag();

	SWITCH_ALLOW_CLOSE_DEFINE=0;
	SWITCH_PROHIBIT_ACT_DEFINE=1;	/*"�ϵ�ʱ�����ü̵���������"*/
	Pre_Payment_Data.OPCard_StatusByte=0;
	RelayActStaCheckNum=RELAY_ERR_CHECK_TIME;	/*"�ϵ�������� �̵������� "*/
}

/*"����ʾ����"*/
/*"mode-->Card_Display_Err:		��ʾ�������	"*/
/*"				Card_Display_Card:	��ʾCARD		"*/
/*"				Card_Display_Good:	��ʾGOOD		"*/
void Pre_Display(unsigned char mode)
{
	switch(mode)
		{
		case Card_Display_Card:
				displayReadCard(READ_CARD_IN);
				break;
		case Card_Display_Err:
				if(Check_CPU_Occur())
				{
					R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
				}
				displayCharTimeLen(READ_CARD_FAIL,5,0);
				if (R_CARD_ERROR_INFO==MOVE_CARD_DEFINE)
				{
					displayCharTimeLen(DISP_IC_ERR,5,0);
				}
				else
				{
					if (R_CARD_ERROR_INFO==HOARD_AMOUNT_DEFINE)
						displayCharTimeLen(DISP_CHAR_HOARD,5,0);			/*"Li_��ѳ��ڻ����޴���"*/
					displayCharTimeLen(DISP_IC_ERR,5,0);			
				}
				//Li Update 20121212    Buzzer_Pay_Cortrol(30,5,5);			/*"Li_����ʱ:��5  ��,���ظ�150ms"*/
				Buzzer_Pay_Cortrol(25,3,5);			 /*"����Ϊ 125ms���������ҲΪ 125ms"*/
				//clearFlag=0;
				break;
				
		case Card_Display_Good:
				//if (clearFlag)
				//	{
				//	My_Memcpy((unsigned char *)&Clear_all_oper_code,&oprateCode[0],4);	
				//	Set_which_Responsion_Flag(0,0xff);
				//	}
				if (buy_money_OK_flag>0xB0)
					{
					displayCharTimeLen(READ_CARD_SUCCESS,7,0);	// 7=2+5
					displayCharTimeLen(DISP_BEFOR_REMAIN,5,0);
					}
				else
					{
					displayCharTimeLen(READ_CARD_SUCCESS,5,0);
					displayCharTimeLen(DISP_REMAIN_DATA,5,0);
					}
				//Li Update 20121212    Buzzer_Pay_Cortrol(50,1,5);			
				Buzzer_Pay_Cortrol(125,1,5);						/*"����Ϊ 625ms"*/
				break;
		}
}

/*"ÿ���ӵ���"*/
void Pay_Minute_Act(void)
{
	Relay_Pro_Act_Time++;
	if (Relay_Pro_Act_Time>=150)
		{
		Relay_Pro_Act_Time=0;
		Drive_Act_Repair();
		if (!SWITCH_FACT_DEFINE)
			{
			SWITCH_ALLOW_CLOSE_DEFINE=1;
			}
		}
	//Current_Over_30A_Function();
}

/*"��¼���ɿ�������"*/
void Relay_Error_Rec(unsigned char mode)
{
	if (!mode)	/*"��������"*/
	{
		Pre_Payment_Data.Relay_Error_Num++;
		Pay_EE_W(Relay_Error_Num_EE,(unsigned char *)&(Pre_Payment_Data.Relay_Error_Num),4,3,
				(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);						
		Co.b[500]=GetRelayPort_Status();
		//Pay_For_Event_Period((const unsigned char *)&RelayErr_Event,0);
		STATUS_RELAYERR_DEFINE=1;
		RelayErrCheck_DEFINE=1; 
        if(Meter_Parameter.parameter1.EventReportMode.byte[0] & 0x01)
        {
		if(!EventStatus_flag.bit.Switch_err)
		{
	    	EventReportState_Expand(3, 3, 0);
			Save_EventReportTimes(SWITCH_ERR_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Switch_err_times);
		}
        }
	}
	else		/*"��������"*/
	{
		if (mode==0x99)
			My_Memcpy(&Co.b[510], &Powerdown_Save_Data.date.Year, 6);	/*"�ϵ�ʱ��"*/
		else
			My_Memcpy(&Co.b[510], &MainSoftDate.Year, 6);
		mode=1;
		STATUS_RELAYERR_DEFINE=0;
      	EventReportState_Expand(3, 3, 1);
	}
	Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
		   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	
	Pay_For_Event_Period((const unsigned char *)&RelayErr_Event,mode);	/*"���ܱ�ֹͣ����ʱ�������ڵĸ��ɿ���������¼"*/
}

/*"���ܱ�ֹͣ����ʱ�������ڵĸ��ɿ���������¼(�ϵ粹)"*/
void Pay_Relay_Err_End(void)
{
	if (STATUS_RELAYERR_DEFINE&&(!IntoPowerDownFlag))
	{
		Relay_Error_Rec(0x99);
	}
	RelayErrCheckNum=0;
	RelayOkCheckNum=0;
	SWITCH_ERR_CLUE_DEFINE=0;
}

/*"������ڸ��ɿ���ʵ��״̬���������ɿ��ص�����״̬��һ��,�ҳ���5s����"*/
/*"������ø��ɿ�����բ���е���,�ҳ���5s����"*/
void Pay_Relay_Err_Check(void)
{
	unsigned long CurrErrFlag;

	if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)		/*"Li_�˴�Ҫ��һ������_��Զ�̷�������Ԥ����"*/
	{
		if (FLAG_SWITCH_ACT_MODE==0)	/*"���ñ�"*/
		{
			if (SWITCH_FACT_DEFINE&&((Active_power[0]>0) || (GetRelayPort_Status()==0))			/*"��բ״̬��, ���ʡ�0W ���� ����״̬=ͨ"*/ //_fgMeter_Noload==flase 
				|| (!SWITCH_FACT_DEFINE)&&((Active_power[0]==0)&&(GetRelayPort_Status()==1)))	/*"��բ״̬��, ����״̬=��"*/
			{
				RelayErrCheckNum++;
				RelayOkCheckNum=0;
				if(RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)
				{
					if ((!STATUS_RELAYERR_DEFINE)&&(!RelayErrCheck_DEFINE))	/*"������תǰֻ��¼һ��"*/
					{
						Relay_Error_Rec(0);
					}
					SWITCH_ERR_CLUE_DEFINE=1;
				}
			}
			else
			{
				RelayErrCheckNum=0;
				RelayOkCheckNum++;
				if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)
				{
					//if ((GetRelayPort_Status()==SWITCH_FACT_DEFINE))
					//{
						if (STATUS_RELAYERR_DEFINE)
						{
							Relay_Error_Rec(1);
						}
						SWITCH_ERR_CLUE_DEFINE=0;
					//}
				}
			}
		}
		else	/*"���ü̵���"*/
		{
			#if 0	/*"���ü̵�����բҲ�жϹ���"*/
			/*"���ü̵��� ��բ���⵽�й���������2�� ���� ��բ���⵽�й�����Ϊ0����2��"*/
			if ((SWITCH_FACT_DEFINE && (Active_power[0]>0)) 
			|| ((!SWITCH_FACT_DEFINE) && (Active_power[0]==0)))
			{
				RelayOkCheckNum=0;
				RelayErrCheckNum++;
				if (RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)	/*"��2s�������һ�μ����"*/
					{
					if (!STATUS_RELAYERR_DEFINE)
						Relay_Error_Rec(0);
					Wai_SWITCH_ERR_DEFINE=1;
					}
			}
			else
			{
				RelayErrCheckNum=0;
				RelayOkCheckNum++;
				if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)	/*"�й��ʾ����޹��ʾ���"*/
				{
					if (STATUS_RELAYERR_DEFINE)
						Relay_Error_Rec(1);
					Wai_SWITCH_ERR_DEFINE=0;
				}
			}			
			#endif

			/*"���ü̵����Ͽ���������2�����"*/
			if (SWITCH_FACT_DEFINE)
			{
				if (Active_power[0]>0)	/*"���ʡ�0W"*/
				{
					RelayErrCheckNum++;
					if (RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)	/*"��5s�������һ�μ����"*/
						{
						if ((!STATUS_RELAYERR_DEFINE)&&(!RelayErrCheck_DEFINE))	/*"������תǰֻ��¼һ��"*/
							Relay_Error_Rec(0);
						Wai_SWITCH_ERR_DEFINE=1;
						}
				}
				else
				{
					RelayErrCheckNum=0;
					RelayOkCheckNum++;
					if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)	/*"�й��ʾ����޹��ʾ���"*/
					{
						if (STATUS_RELAYERR_DEFINE)
							Relay_Error_Rec(1);
						Wai_SWITCH_ERR_DEFINE=0;
					}
				}
				if (Wai_SWITCH_CLOSE_DEFINE)	/*"��բ״̬ʱ,����ɹ���բ��־"*/
				{
					Wai_SWITCH_CLOSE_DEFINE=0;
					Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
							 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);					
				}
			}
			else
			{
				if (STATUS_RELAYERR_DEFINE)	/*"���ñ��¼�̵������Ϻ�,��բ�ǽ���"*/
					Relay_Error_Rec(1);

				RelayErrCheckNum=0;				
				RelayOkCheckNum++;
				if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)
				{
					if ((Active_power[0]>0)&&(!Wai_SWITCH_CLOSE_DEFINE)) /*"��բ״̬�¼�⵽����,����Ϊ��բ�ɹ�,�ý���������̵�����բ"*/
					{
						Wai_SWITCH_CLOSE_DEFINE=1;
						Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
								 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);					
					}
					else if (!Wai_SWITCH_CLOSE_DEFINE) /*"��բ�ɹ������ж�"*/
					{
						Wai_SWITCH_ERR_DEFINE=1; /*"��բ״̬��δ��⵽����,��Ϊ�̵�������,ֻ��״̬��1�����֣��Ȳ��Ǵ����¼Ҳ���ϱ�"*/
					}
				}
				if (Wai_SWITCH_CLOSE_DEFINE)
					Wai_SWITCH_ERR_DEFINE=0;
			}	

		}
	}
}

/*"ˢ�¼�״��3��BIT4λ�̵���״̬"*/
void Relay_Status_Check(void)
{
	if (RelayActStaCheckNum)
		RelayActStaCheckNum--;
	if (!RelayActStaCheckNum)	/*"�̵�������3���,��ˢ��״̬��3����բָʾ��"*/
	{
		if (SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE || ((!Wai_SWITCH_CLOSE_DEFINE) && (FLAG_SWITCH_ACT_MODE==1) && (SWITCH_FACT_DEFINE == 0)))	/*"�̵������� ���� ���ñ�δ��բ�ɹ�(��բ��δ��⵽����)"*/
			NEW645Meter_States.Meter_Status3.bit.Relay_Status=!SWITCH_FACT_DEFINE;
		else
		{
			NEW645Meter_States.Meter_Status3.bit.Relay_Status=SWITCH_FACT_DEFINE;
			SwitchOn_Report();
			SwitchOff_Report();
		}
	}
}

/*"ʵʱˢ����ʾ���ӷ��ź�����־���͹�����Ҫ��ʾ"*/
void Find_PassInf_Status(void)
{
	unsigned char uni,flg=0;
	
	if ((!is_test_psw_status())
		//|| (((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))&&(!MACRO_ESAM_FLAG))
		)
		{
		Show_flag.bit.Home=0;
		}
	else
		{
		Show_flag.bit.Home=1;
		}

	for(uni=0;uni<MAX_PASS_NUM;uni++)
	{
		if(Other_Data.PasswordErr[uni].flag)
		{
			flg=1;            
		    break;
		}
	}
	if ((Pre_Payment_Data.HangMeterNum>=NUM_ERR_TO_HANG)||flg)	/*"�����������������������"*/
		Show_flag.bit.lock=1;
	else
		Show_flag.bit.lock=0;

}
	
/*"��˸��ʾԤ������ط���(ÿ�����һ��)"*/
void Pre_Display_Char_Flash(void)
{
	//union Long_To_Char progman;
	unsigned char Wai_Relay_Err=0;

	Pay_Status_Flag();
	Pay_Relay_Err_Check();
	Relay_Status_Check();

	/*"������յ���վ��բ���澯����ʱ,Bit6��1,����Bit6��0"*/
	//if ((!METER_IN_FRIEND_DAY_DEFINE)&&( FAR_OPEN_PREPARE_DEFINE || FAR_OPEN_SWITCH_DEFINE ||FAR_WARN_1D_DEFINE ||FAR_WARN_1E_DEFINE))
	//	NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=1;
	//else
	//	NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=0;

	/*"ʣ������ڻ�С��Ԥ�õı�����ֵʱ,Bit7��1,�����,��ʾ�û�����;����Bit7��0"*/
	if (REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE 
		|| REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE
		|| FAR_OPEN_ALARM_DEFINE)
		NEW645Meter_States.Meter_Status3.bit.SwitchAlarmStatus=1;
	else
		NEW645Meter_States.Meter_Status3.bit.SwitchAlarmStatus=0;	

	NEW645Meter_States.Meter_Status3.bit.Program_Allow=Show_flag.bit.keystoke;
	NEW645Meter_States.Meter_Status3.bit.Identity_Flg=Far_Identity_Auth_Ok_Flag;

	Find_PassInf_Status();
		
	/*"��ʾ�빺��"*/
	NEW645Meter_States.Meter_Status1.bit.Overdraft=0;
	Show_flash_falg.bit.Recharge=0;
	Show_flag.bit.Overdraft=0;
	Show_flash_falg.bit.Overdraft=0;	
	if ((MACRO_FAY_CONTROL_FLAG && FAR_OPEN_ALARM_DEFINE)
	||(MACRO_LOCAL_PAY_FLAG && (REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE||REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE||REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE||REMAIN_MONEY_LOW_TICK_CLUE_DEFINE) && (!buy_money_OK_flag)))
		{
		Show_flash_falg.bit.Recharge=1;			/*"�빺��"*/
		if ((Pre_Power_Down_Save_Data.Remain_Money<0) && MACRO_LOCAL_PAY_FLAG)
			{
			NEW645Meter_States.Meter_Status1.bit.Overdraft=1;
			if (REMAIN_MONEY_LOW_TICK_CLUE_DEFINE&&(!METER_IN_FRIEND_DAY_DEFINE))
				{
				Show_flag.bit.Overdraft=1;		/*"�ﵽ͸֧����"*/
				//Show_flash_falg.bit.Overdraft=0;
				}
			else
				{
				//Show_flag.bit.Overdraft=0;		
				Show_flash_falg.bit.Overdraft=1;	/*"����͸֧,δ�ﵽ͸֧����"*/
				}
			}
		//else
		//	{
		//	NEW645Meter_States.Meter_Status1.bit.Overdraft=0;
		//	Show_flag.bit.Overdraft=0;
		//	Show_flash_falg.bit.Overdraft=0;
		//	}
		}
	//else
	//	{
	//	}
      Overdraft_Report();
    
	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		return;
	
	//if (!SWITCH_FACT_DEFINE)
	//	SWITCH_ERR_CLUE_DEFINE=0;
	
	//Lcd_Light_Control();
	Far_Switch_Control(1);

	/*"�ϵ��,�̵�������"*/
	if (UpPowerSecond<=20)
		{
		UpPowerSecond++;
		if (FLAG_SWITCH_ACT_MODE)	/*"�ϵ��,���ü̵���������ǰ״̬����1��"*/
			{
			if (UpPowerSecond>=1)
				{
				UpPowerSecond+=100;
				if (!SWITCH_FACT_DEFINE)
					SWITCH_ALLOW_CLOSE_DEFINE=1;
				Switch_Plus_Start(SWITCH_FACT_DEFINE);
				}
			}
		else
			{
			if (UpPowerSecond>=15)		/*"�������ü̵���,���ϵ�15��ʱ����1��"*/
				{
				UpPowerSecond+=100;
				Drive_Act_Repair();
				if (!SWITCH_FACT_DEFINE)
					{
					SWITCH_ALLOW_CLOSE_DEFINE=1;
					}
				}
			}
		}
		
	if (relayPlusTime>0)
		{
		relayPlusTime--;
		if ((!relayPlusTime) && (relayPlusCnt<RELAY_PLUSE_CNT))
			SWITCH_PROHIBIT_ACT_DEFINE=0;
		}
}

/*"  �Ƿ�̶���ʾʣ����"*/
unsigned char Pre_Static_Display_Remain(void)
{
	unsigned char ret=0;

	if (REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE 
		&& REMAIN_MONEY_LOW_ALARM1_SHOW_DEFINE 
		&& (display_Remain_Flag<<1==0x0)
		&& (Check_CPU_Occur()==0xFF)
		&& MACRO_LOCAL_PAY_FLAG)
		{
		display_Remain_Flag|=0x80;
		ret=1;
		}
	else
		{
		display_Remain_Flag&=0x7F;
		}
	return ret;
}

/*"���������"*/
void Pre_Get_OverZero_Money(void)
{
	if (Pre_Power_Down_Save_Data.Remain_Money<0)
		{
		Remain_Money_Plus=0;
		Remain_Money_Nega=0-Pre_Power_Down_Save_Data.Remain_Money;
		}
	else
		{
		Remain_Money_Plus=Pre_Power_Down_Save_Data.Remain_Money;
		Remain_Money_Nega=0;
		}
}

//------------------------------------------------------------------------
/*"������"*/
void Card_Judge(void)
{
	char i,ret;
	union Long_To_Char progman;
	
	tr_show_wait(100);
	if(Check_CPU_Occur())
	{
		Card_pull_out();
		return;
	}
	Buzzer_Pay_Cortrol(0,0,1);							/*"Li_�忨����������"*/
	key_flag.bit.b0=0;	//prenting key,insert card
	Card_Type=0x00;
	press_card_state=GOOD;
	R_CARD_ERROR_INFO=GOOD_DEFINE;
	
	buy_money_OK_flag=0;
	Full_show_time_Limit=0;
	OPCard_Error_format.Response[0]=0;				//Li Update 20121231
	OPCard_Error_format.Response[1]=0;
	My_Memcpy(OPCard_Error_format.CMD,0,5);
	 for(i=0;i<8;i++)
		cpucard_number[i]=0xFF;						/*"�����к�����"*/		//Li Update 20130106
	//Disp_Char_Clear();
	FeedWatchdog();
	if(Check_CPU_Occur())
	{
		R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
		return;
	}
    Event_Power_Net_Flag.bit.ProgrammeEvent = 0;
	if (VoltageGreaterThanICcard_Flag || auxiliary_power_flag)
	{
		Cpucard_Serial_Init();
		ret=Card_Operate();	//Card Operate
		Cpu_Card_IO_Reset();
		///Light_Back_Up_Flag=0;		//Li Update 20121231,
		///Light_Back_Led();
		BackLight_Ctrl(IC_CARD_LIGHT_MODE, 60,0,CARD_JUDGE_EVENT);///king chen modify 130305
	}
	else
	{
		ret=0xFF;
		R_CARD_ERROR_INFO=VOLTAGE_LOW_DEFINE;					//Li Update 20121220		  /*"Li_������Ϣ��(��Ƶ�ѹ����)"*/ 
	}
	Card_Alarm_Switch();
	if (R_CARD_ERROR_INFO!=GOOD_DEFINE)
		ret=ERR;
	if(ret!=OK)
	{
		if(Check_CPU_Occur())			
			{
			R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
			}	
		if (R_CARD_ERROR_INFO==ICCARD_RESET_DEFINE || R_CARD_ERROR_INFO == CARDTYPE_ERROR_DEFINE || R_CARD_ERROR_INFO == UNISSUED_ERROR_DEFINE	/*"���忨���߿����ʹ�"*/ 
		|| R_CARD_ERROR_INFO == IDCARD_ERROR_DEFINE ||  R_CARD_ERROR_INFO == EXID_ERROR_DEFINE || R_CARD_ERROR_INFO == CARD_NO_INS_DEFINE	/*"�����֤��ͨ��"*/ 
		|| R_CARD_ERROR_INFO == MAC_ERROR_DEFINE)
			{
			Pre_Payment_Data.Unlawful_Card_Count++;
			Pay_EE_W(UNLAWFUL_CARD_COUNT_EE,(unsigned char*)&Pre_Payment_Data.Unlawful_Card_Count,4,3,
				(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
			}
		FeedWatchdog();
		Pre_Display(Card_Display_Err);
		Pre_Payment_Data.OPCard_StatusByte=0x0002;
		//---------------------------------------------------------//
		//My_Memcpy((unsigned char*)&OPCard_Error_format.Date,(unsigned char*)&MainSoftDate,6);
		//OPCard_Error_format.CardError=R_CARD_ERROR_INFO;
		Reverse_data((unsigned char*)&OPCard_Error_format.CMD[0],5);
		Reverse_data((unsigned char*)&OPCard_Error_format.Response[0],2);
		//WRLC256(PAY_OPCARD_EVENT_EE,(unsigned char*)&OPCard_Error_format,sizeof(struct _OPCard_Error_format),0,0);
		Pre_Get_OverZero_Money();
		Pre_Payment_Data.OPCard_Error_Num++;
		Pay_EE_W(OPCARD_ERROR_NUM_EE,(unsigned char*)&Pre_Payment_Data.OPCard_Error_Num,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		My_memcpyRev(&Co.b[500],cpucard_number,8);
		Pay_For_Event_Dot((const unsigned char *)&OPCardErr_Event);			/*"�忨�쳣дFlash"*/
		//---------------------------------------------------------//
	}
	else
	{
		Pre_Get_OverZero_Money();
		Pre_Display(Card_Display_Good);
		Pre_Payment_Data.OPCard_StatusByte=0x0001;
	}
	//OutCardInCycshow();		/*"������ص�ѭ�Ե�һ��"*/
	buy_money_OK_flag=0;

	if (clearFlag>10)	/*"��Ԥ�ÿ���ʾ�����ɹ���������"*/
		{
		memcpy(&progman.U_char[0], &oprateCode[0], 4);
		ClearMeterRecord(progman.U_long);
		Clear_All_New(progman.U_long);
		//clearFlag=0;
		}	
}

/*"�������ж�"*/
unsigned char Card_Operate(void)
	{
	unsigned char i,Add_CS;
	unsigned char ret=0;
	unsigned char length;

	Far_Identity_Auth_Ok_Flag = 0;
    R_ID_Remain_Time = 0;

	BackLight_Ctrl(IC_CARD_LIGHT_MODE, 60,0,CARD_OPERATE_EVENT);	/*"�����ṩ�ĵ�ѹ�ȶ���,��������"*/
	displayReadCard(READ_CARD_IN);		/*"��Ļ����ʾ"������" "*/
	
	//-----------------------------------------------------------------//
//CPU
	if( Cpucard_Atr() != OK )
		return ERR;

	if( Select_File(0,0xDF,1) != OK )
		return ERR;

//ESAM
	if( Esamcard_Atr() != OK )
		return ERR;
	
	if( Select_File(0,0x3F,00) != OK )
		return ERR;

	CPU_ESAM_CARD_Control(CPU);
	//-----------------------------------------------------------------//
	if( Read(0,Read_Binary,0x80+1,0,4) != OK )
	{
		R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
		return ERR;
	}
	if(receive_send_buffer[0]!=0x68)
	{
		R_CARD_ERROR_INFO=CARDFILE_FORMAT_DEFINE;
		return ERR;
	}		
	Card_Type=receive_send_buffer[1];
	if (Card_Type==0x00)
		{
		R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;
		return ERR;
		}
	
	length= receive_send_buffer[3];
	length+=6;

	if( Read(0,Read_Binary,0x80+1,0,length) != OK )
		{
		R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
		return ERR;
		}
	if( Frame_Judge(&receive_send_buffer[0],length)!= OK )
		return ERR;

//card operate
	My_Memcpy(Card_WR_Buff,receive_send_buffer,length);

	if (Pre_Payment_Para.Far_Key_StatusByte)	/*"˽Կ�²������Ԥ�ÿ�"*/
		{
		if (Card_Type==GWFAR_INIT_CARD)
			{
			R_CARD_ERROR_INFO=CARD_NO_INS_DEFINE;
			return ERR;
			}
		}
	else
		{
		if (Card_Type==GWFAR_USER_CARD)	/*"��Կ�²�������û���"*/
			{
			R_CARD_ERROR_INFO=CARD_NO_INS_DEFINE;
			return ERR;
			}			
		}
	//------------------------------------------------------------------//
	if( Cpucard_Esamcard_Internal_Auth(Card_Type) != OK )	
	{
		return ERR;
	}
	//------------------------------------------------------------------//
//	Esam_Remain_Money_Do(1);
	if( Esam_Remain_Money_Dec() != OK )
		{
		return ERR;
		}

	CPU_ESAM_CARD_Control(CPU);
	Para_Updata_Flag = 0;
	Para_Updata_Flag_Suc = 0;
	Meter_Ins_Flag = 0;

	FeedWatchdog();
	switch (Card_Type)
		{
		case GWFAR_USER_CARD:									/*" �û��� "*/
			ret=Buy_Card();
			break;
		//case GWFAR_MOD_PASSWORD_CARD:						/*" �޸���Կ�� "*/
		//case GWFAR_RES_PASSWORD_CARD: 						/*" �ָ���Կ�� "*/
		//	ret=Password_Card();
		//	break;
		//case GWFAR_PARA_SET_CARD:								/*" �������ÿ� "*/
		//	ret=Triff_Card();
		//	break;
		//case GWFAR_READ_ESAM_CARD:							/*" ESAM���ݻس��� "*/
		//	ret=Check_Card();
		//	break;
		case GWFAR_INIT_CARD:									/*" �������ÿ� "*/
				ret=Set_In_Card();
			break;	
		//case GWFAR_MOD_METERID_CARD:							/*" ������ÿ� "*/
		//		ret=Modify_MeterID_Card();
		//	break;
		//case GWFAR_ADDD_MONEY_CARD:								/*" ���ӵ����� "*/
		//	ret = Add_Money_Card();
		//	break;
		case GWFAR_RELAY_TEST_CARD:								/*" �̵������Կ� "*/
			if (O1ther_Meter_Parameter.WorkRoomState)
				{
				ret = Relay_TEST_Card();
				}
			else
				{
				R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;
				ret=1;
				}
			break;
		default: 													/*"�����ͻ�״̬����"*/
			R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;				//Li Update 20121220			/*"Li_��Ϣ������(�����ʹ���)"*/
			ret=1;
			break;
		}
	if( ret==OK )
		CardProgrammeEvent();
	return ret;
	}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"λ:  �����Ƿ���±�־"*/
/*"Bit0	���ʵ�۵�ǰ�� "*/
/*"Bit1	���ʵ�۱����� "*/
/*"Bit2	�ݶȲ�����ǰ�� "*/
/*"Bit3	�ݶȲ��������� "*/
/*"Bit4	���� "*/
/*"Bit5	���� "*/
/*"Bit6	���� "*/
/*"Bit7	�������� "*/
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*" ������,���翨���ȽϺϷ���"*/
unsigned char Judge_User_Card_OK(unsigned char Card_Kind,unsigned long card_Buy_Count)
{
	struct Buy_Para_Inf_File *file;	
	
	file=(struct Buy_Para_Inf_File *)&Card_WR_Buff[4];
	Buy_Money_Flag = 0x01;

	/*"���翨���ʹ�"*/
	if( Card_Kind !=GWFAR_USER_CARD_NEW && Card_Kind !=GWFAR_USER_CARD_BUY && Card_Kind !=GWFAR_USER_CARD_BACK)
	{
		R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;				//Li Update 20121224					/*"Li_��Ϣ������(�����ʹ���)"*/
	 	return ERR;
	}

	/*" �жϱ��"*/
	if( My_Memcmp(&(file->Meter_ID[0]),(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6) )
	{
		R_CARD_ERROR_INFO=METER_NUM_DEFINE;				//Li Update 20121224					/*"Li_��Ϣ������(��Ŵ���)"*/
		return ERR;
	}

//	if (!STATUS_LOCALOPEN_DEFINE)
//	{
//		if ( Card_Kind ==GWFAR_USER_CARD_BUY)	/*"P265:����Զ�̿����ĵ��ܱ�ֻ���ܿ������Ͳ��������������ܹ��翨����"*/
//		{
//			R_CARD_ERROR_INFO=BUYCARD_ERROR_DEFINE;
//			return ERR;
//		}
		//else if ( Card_Kind ==GWFAR_USER_CARD_NEW)	/*"����δ����&���й���������� 1 ʱ,���Ϲ��翨"*/
		//{
			//if (Pre_Payment_Para.Buy_Count>1)		  /*"����2����ô����"*/
			//	{
			//	R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;
			//	return ERR;
			//	}
		//}		
//	}
	/*"ֻҪ���״̬Ϊ����״̬�������Ƚ��û���"*/
	if (  Pre_Payment_Para.Meter_Run_State==0x03 ) 
	{
		/*"�жϿͻ����"*/
		if( My_Memcmp(Pre_Payment_Para.UserID,file->Client_ID,6) )		//I_B  B_B	/*"I_*:����������,B_*:�û�������"*/
		{
			R_CARD_ERROR_INFO=CLIENT_NUM_DEFINE;				/*"�ͻ���Ų�һ��"*/
			return ERR;
		}
		if( Card_Kind == GWFAR_USER_CARD_BUY )	//B_B
		{
			if( My_Memcmp(Pre_Payment_Para.Card_Reset_Inf, cpucard_number, 8) )
			{
				R_CARD_ERROR_INFO=CARD_SN_DEFINE;			/*"Li_��Ϣ������(�����ʹ���)"*/
			 	return ERR;
			}
		}
	}
	else
	{
		if (Card_Kind==GWFAR_USER_CARD_BUY)	/*"δ����,���Ϲ��翨"*/
		{
			R_CARD_ERROR_INFO=BUYCARD_ERROR_DEFINE;
			return ERR;
		}
		else if ( Card_Kind==GWFAR_USER_CARD_BACK)	/*"δ����,���ϲ���"*/
		{
			R_CARD_ERROR_INFO=UPCARD_ERROR_DEFINE;
			return ERR;
		}
	}

	CPU_ESAM_CARD_Control(CPU);
	Read(0,Read_Binary,0x80+USER_CARD_RUN_INF_FILE,0,1);/*" ��ȡ�û�����������Ϣ�ļ� "*/
	CPU_ESAM_CARD_Control(ESAM);	
	/*"��������Ƚ�"*/
	if ( Card_Kind==GWFAR_USER_CARD_NEW )
	{
		if (card_Buy_Count>1)		//I_C 
		{
			R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;		/*"�������еĹ�������Ƿ�Ϊ0��1"*/
		 	return ERR;				
		}
	}
	//I_D B_C
	//l_flag = My_Memcmp((unsigned char *)&card_Buy_Count,(unsigned char *)&Pre_Payment_Para.Buy_Count,4);	/*"Li_(���ڵ�)��(���ڵ�)�Ƚ�"*/
	if(card_Buy_Count == Pre_Payment_Para.Buy_Count)			/*"������ڹ������=���ڹ����(�ڿ��еĴ���)"*/
	{
		if ( receive_send_buffer[0] != 0x68 )	//I_E B_D		/*"��дΪ��"*/
		{
			Buy_Money_Flag |= 0x018;	// to I_J B_I
			return OK;
		}
		else
		{
			if ( Card_Kind==GWFAR_USER_CARD_BUY )
				return OK;	//to B_K
			else
			{
				if( My_Memcmp(Pre_Payment_Para.Card_Reset_Inf, cpucard_number, 8)==0 )	//I_E
				 	return OK;	//to I_M
				else
					{
					R_CARD_ERROR_INFO=CARD_SN_DEFINE;
					return ERR;
					}
			}
		}
	}
	else if(card_Buy_Count > Pre_Payment_Para.Buy_Count)			
	{
		if (card_Buy_Count == (Pre_Payment_Para.Buy_Count + 1))	/*"�������=���ڹ������+1"*/
		{
			if ( receive_send_buffer[0] == 0x68 )	/*"��д��Ϊ��"*/	//I_F
			{
				R_CARD_ERROR_INFO=USER_BACK_WRITE_DEFINE;	/*"�û�����д��Ϣ�ļ���Ϊ�� "*/
				return OK;	//to I_M B_K
			}
			Buy_Money_Flag |= 0x08;	
			//to OK
		}
		else
		{
			R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;		/*"(�����������)"*/ /*"�������>���ڹ������+1"*/
		 	return OK;	//to I_M B_K
		}
	}
	else
	{
		//if( Card_Kind!=GWFAR_USER_CARD_BACK)	//I_L
		//{
		Buy_Money_Flag |= 0x08;		/*"�������к�,�ÿ���״̬"*/
		//}
		return OK;	//to I_L B_K
	}
	//--------------------------------------------------------------------------------------------------------------//
	//I_G B_F
	Buy_Money_Flag|=0x90;	/*"�����ֵ,�����޸Ĳ���,�����û���,��ʾ�ɹ�"*/
	
	return OK;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"�жϱ��ι���Ķڻ�����"*/

unsigned char Judge_Remain_Money_Over(unsigned long Curr_Buy_Money) 
	{
	signed long Money_Count_T,Money_Count_T1;

	if (Curr_Buy_Money>0x77359400)
		return ERR;

	Money_Count_T =  (signed long)Pre_Power_Down_Save_Data.Remain_Money;
	Money_Count_T+= (signed long)Curr_Buy_Money;
		
	Money_Count_T1 = (signed long)Pre_Payment_Para.Remain_Money_Hoard_Limit;
	if (!Money_Count_T1)
		Money_Count_T1=99999999;	/*"����ڻ������ֵ��Ϊ 0���ڳ�ֵʱ����999999.99 ����"*/
	if( Money_Count_T>Money_Count_T1 )
		return ERR;

	/*" ʣ���Ѵ���2ǧ��Ҳ��������� "*/
	if( Money_Count_T > 0x77359400 )  
		return ERR;
	return OK;
	}

unsigned char Card_Set_Para_to_Meter(unsigned char Buy_Card_Kind)
{
	/*"��������"*/
	Deal_Buy_Para_Inf_File(Card_WR_Buff+450+4,0x80,GWFAR_USER_CARD_NEW);
	/*"��ǰ�׷��ʲ���"*/
	if ((Buy_Card_Kind==GWFAR_USER_CARD_NEW)&&(Para_Updata_Flag & 0x01))
	    {
		Pre_Payment_Data.TriffProgNum++;
		Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
				(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
		Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"��̷��ʼ�¼"*/	
		if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x20) 
		{
		   EventReportState_Expand(1, 5, 0);  
		   Save_EventReportTimes(PROGTRIFFPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgTriffPrice_times);
		}
	    Deal_Triff_Data(Card_WR_Buff+4,0x00);
	    }
	/*"�����׷��ʲ���"*/
	if (Para_Updata_Flag & 0x02)
	    {
	    //if (Buy_Card_Kind==GWFAR_USER_CARD_NEW)
	    	{
	    	Pre_Payment_Data.TriffProgNum++;
			Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
					(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
			Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"��̷��ʼ�¼"*/
			if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x20) 
			{
			   EventReportState_Expand(1, 5, 0);  
			   Save_EventReportTimes(PROGTRIFFPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgTriffPrice_times);
			}
	    	}
	    Deal_Triff_Data(Card_WR_Buff+220+4,0x01);
	    }
	/*"��ǰ�ݶȲ���"*/
	if ((Buy_Card_Kind==GWFAR_USER_CARD_NEW)&&( Para_Updata_Flag & 0x04 ))
	    {
		Pre_Payment_Data.StepProgNum++;
		Pay_EE_W(StepProgNum_EE,(unsigned char *)&(Pre_Payment_Data.StepProgNum),4,3,
				(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
		Pay_For_Event_Dot((const unsigned char *)&ProgramStep_Event);	   
		if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x40) 
    	{
	       EventReportState_Expand(1, 6, 0);  
	       Save_EventReportTimes(PROGSTEPPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgStepPrice_times);
    	}      
        FeedWatchdog();
	    Deal_Triff_Data(Card_WR_Buff+4,0x80);
		//Bill_Date_Change_Modify_DEFINE=1;
	    }
	/*"�������ݶȲ���"*/
	if (Para_Updata_Flag & 0x08)
	    {
	    //if (Buy_Card_Kind==GWFAR_USER_CARD_NEW)
	    	{
			Pre_Payment_Data.StepProgNum++;
			Pay_EE_W(StepProgNum_EE,(unsigned char *)&(Pre_Payment_Data.StepProgNum),4,3,
					(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
			Pay_For_Event_Dot((const unsigned char *)&ProgramStep_Event);	   
			if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x40) 
	    	{
		       EventReportState_Expand(1, 6, 0);  
		       Save_EventReportTimes(PROGSTEPPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgStepPrice_times);
	    	}      
	        FeedWatchdog();
	    	}
	    Deal_Triff_Data(Card_WR_Buff+220+4,0x81);
	    }
	if (Para_Updata_Flag & 0x0A)      /*"����޸��˱����ײ���(�л�ʱ��Ҳ���޸�)"*/
	    Run_Triff_Switch(0);
	//if (Bill_Date_Change_Modify_DEFINE)
	//	switch_year_stage_mouth_stage();	/*"�޸ĵ�ǰ������գ����������"*/
	if (Para_Updata_Flag)			 /*"���忨ʱû�н��в������£�����¼����¼���¼"*/
		Para_Updata_Flag_Suc=0xFF;
}

/*" ������Ϣ�ļ����� "*/	
/*"Buy_Card_Kind=0x01:���µ�ǰ��"*/	
unsigned char Card_Set_Para(unsigned char Buy_Card_Kind)
{
	/*"����������Ϣ�ļ����� "*/		
	if ((Buy_Card_Kind ==GWFAR_USER_CARD_NEW)&&(Para_Updata_Flag & 0x80))
		{
		if( Esam_File_Updata(USER_CARD_PARA_INF_FILE,
								ESAM_PARA_INF_FILE,
								BUY_PARA_INF_FILE_BUY_CARD,
								ESAM_PARA_INF_FILE_ESAM,
								2,
								Card_WR_Buff+450+BUY_PARA_INF_FILE_BUY_CARD) != OK )
			return ERR;
		if( Esam_File_Updata(USER_CARD_PARA_INF_FILE,
								ESAM_PARA_INF_FILE,
								REMAIN_MONEY_ALARM1_LIMIT_BUY_CARD,
								REMAIN_MONEY_ALARM1_LIMIT_ESAM,
								14,
								Card_WR_Buff+450+REMAIN_MONEY_ALARM1_LIMIT_BUY_CARD) != OK )
			return ERR;
		}
	if( Para_Updata_Flag & 0x02 )
		{
		if( Esam_File_Updata(USER_CARD_PARA_INF_FILE,
								ESAM_PARA_INF_FILE,
								TRIFF_SWITCH_TIME_BUY_CARD,
								TRIFF_SWITCH_TIME_ESAM,
								5,
								Card_WR_Buff+450+TRIFF_SWITCH_TIME_BUY_CARD) != OK )
			return ERR;
		}
	//Deal_Buy_Para_Inf_File(Card_WR_Buff+4,0x80);

	/*"��ǰ�׷��ʲ���"*/
	if ((Buy_Card_Kind ==GWFAR_USER_CARD_NEW)&&( Para_Updata_Flag & 0x01 ))
		{
		if( Esam_File_Updata(INIT_CARD_TRIFF_1_FILE,
								ESAM_TRIFF_1_FILE,
								0,
								0,
								132,
								Card_WR_Buff) !=OK )
			return ERR;
		//Deal_Triff_Data(Card_WR_Buff+4,0x00);
		}
	/*"�����׷��ʲ���"*/
	if ( Para_Updata_Flag & 0x02 )
		{
		if( Esam_File_Updata(INIT_CARD_TRIFF_2_FILE,
								ESAM_TRIFF_2_FILE,
								0,
								0,
								132,
								Card_WR_Buff+220) !=OK )
			return ERR;
		//Deal_Triff_Data(Card_WR_Buff+220+4,0x01);
		}
	
	/*"��ǰ�ݶȲ���"*/
	if ((Buy_Card_Kind ==GWFAR_USER_CARD_NEW)&&( Para_Updata_Flag & 0x04 ))
		{
		if( Esam_File_Updata(INIT_CARD_TRIFF_1_FILE,
								ESAM_TRIFF_1_FILE,
								132,
								132,
								64,
								Card_WR_Buff+132) !=OK )
			return ERR;
		//Deal_Triff_Data(Card_WR_Buff+4,0x80);
		}
	/*"�������ݶȲ���"*/
	if ( Para_Updata_Flag & 0x08 )
		{
		if( Esam_File_Updata(INIT_CARD_TRIFF_2_FILE,
								ESAM_TRIFF_2_FILE,
								132,
								132,
								64+5,
								Card_WR_Buff+220+132) !=OK )
			return ERR;
		//Deal_Triff_Data(Card_WR_Buff+220+4,0x81);
		}
	//if ( Para_Updata_Flag & 0x0A )		/*"����޸��˱����ײ���(�л�ʱ��Ҳ���޸�)"*/
	//	Run_Triff_Switch(0);
	//Para_Updata_Flag_Suc=0xFF;


	
	return OK;
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"������,���翨"*/
unsigned char Buy_Card(void)
{
	unsigned char i,flg,Buy_Card_Kind,UserID[6];
	struct Moneybag_Data Moneybag_Data;
	struct Moneybag_Data Esam_Moneybag_Data;
	struct Buy_Para_Inf_File  * file;

    if (is_test_psw_status()) {
        R_CARD_ERROR_INFO = CARD_NO_INS_DEFINE;
        return ERR;
    }

	file=(struct Buy_Para_Inf_File *)(&Card_WR_Buff[4]);
	/*" �ⲿ��֤  "*/
	if( Cpucard_External_Auth() != OK )		/*Li_�ⲿ��֤*/
		{
		//R_CARD_ERROR_INFO=EXID_ERROR_DEFINE;
		return ERR;
		}

	/*"��CPU���е�ʣ���Ѻ͹������ "*/
	if( Remain_Money_Moneybag_Add(USER_CARD_MONEYBAG_FILE,REMAIN_MONEY_CPU_ESAM,(unsigned char *)&Moneybag_Data) != OK )
		return ERR;
	Buy_Card_Kind = file->Card_Kind;
	My_Memcpy(UserID,file->Client_ID,6);			/*"Li_���ͻ���Ÿ��Ƶ�UserID��"*/	
	buy_money_OK_flag=0xB0;
					
	/*" �жϿ��ĺϷ�����  "*/
	if( Judge_User_Card_OK( Buy_Card_Kind ,Moneybag_Data.Buy_Count) != OK )
		return ERR;
	
	if ( Buy_Money_Flag&0x80 )
	{
		/*" �жϱ��ι���Ķڻ�����  "*/
		if( Judge_Remain_Money_Over(Moneybag_Data.Remain_Money) != OK )
		{
			R_CARD_ERROR_INFO=HOARD_AMOUNT_DEFINE;					/*"Li_��Ϣ������(ʣ����ڻ�����)"*/   //Li Update 20121223
			return ERR;
		}
	}
	
	Esam_File_Updata(USER_CARD_PARA_INF_FILE,
							ESAM_PARA_INF_FILE,
							USER_KIND_BUY_CARD,
							USER_KIND_ESAM,
							2,
							Card_WR_Buff+USER_KIND_BUY_CARD);

	if (Buy_Money_Flag&0x08)
	{
		if  (Buy_Card_Kind== GWFAR_USER_CARD_NEW) 
		{
			if (Esam_File_Updata(USER_CARD_PARA_INF_FILE,
							ESAM_PARA_INF_FILE,
							CLIENT_ID_BUY_CARD,
							CLIENT_ID_ESAM,
							6,
							Card_WR_Buff+CLIENT_ID_BUY_CARD) !=OK)
			return ERR;
		}
	}
	Para_Updata_Flag = file->Para_UpData_Flag;
	if (Buy_Card_Kind!=GWFAR_USER_CARD_NEW)
		Para_Updata_Flag&=0x0A;	/*"��̼�¼�еĸ��±�־λ����ʵ�ʸ��µĲ������м�¼"*/
	if(Buy_Money_Flag&0x10)
		{
		if (Card_Set_Para(Buy_Card_Kind))
			return ERR;
		}
	if (Buy_Money_Flag&0x80)
	{
		/*"ESAMǮ���ļ�����"*/
		if(Remain_Money_Moneybag_Add(USER_CARD_MONEYBAG_FILE,REMAIN_MONEY_CPU_ESAM,0)!=OK)
			{
			Read_Esam_Moneybag_File((unsigned char *)&Esam_Moneybag_Data);
			if (Esam_Moneybag_Data.Buy_Count!=Moneybag_Data.Buy_Count)
				return ERR;
			R_CARD_ERROR_INFO=GOOD_DEFINE;
			/*"���ESAM�ڴ���==���ڹ�������������ESAM��ֵ����(�����ϴβ忨������ESAM����ǰ���������)"*/
			}
	}
	/*"��д�ļ�����"*/
	flg=0x11;
	if (Buy_Money_Flag&0x80)
		flg=0xB1;
	Updata_Esam_Return_File(flg,Moneybag_Data.Remain_Money,Moneybag_Data.Buy_Count);
	if (Cpu_File_Updata(USER_CARD_RUN_INF_FILE,ESAM_RUN_INF_FILE,0,0,LENGTH_RUN_INF_DATA+6)!=OK)
		return ERR;
	
	/*"������Ϣ�ļ�����"*/
	if (Buy_Money_Flag&0x10)
	{
		My_memcpyRev(&oprateCode[0], &cpucard_number[4], 4);	/*"�����ߴ��븳ֵ"*/
		Card_Set_Para_to_Meter(GWFAR_USER_CARD_NEW);
	}

	/*"���濨���,�¿��ÿ���״̬"*/
	if (Buy_Money_Flag&0x08)
	{
		if (Buy_Card_Kind==GWFAR_USER_CARD_NEW) 
		{
			STATUS_LOCALOPEN_DEFINE=1;
			Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
				   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			/*"���빺�����Ϊ 0 �ҷ�д��Ϣ�ļ�Ϊ�յĿ�����,Ӧ�ø��¿ͻ����"*/
			My_Memcpy(Pre_Payment_Para.UserID,UserID,6);
		    	Pay_EE_W(USERID_EE,(unsigned char *)&(Pre_Payment_Para.UserID[0]),6,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			Pre_Payment_Para.Meter_Run_State=0x03;
		    	Pay_EE_W(METER_RUN_STATE_EE,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
		if (Buy_Card_Kind != GWFAR_USER_CARD_BUY)
		{
			My_Memcpy(Pre_Payment_Para.Card_Reset_Inf, cpucard_number, 8);
			Pay_EE_W(CARD_RESET_INF_EE,(unsigned char *)&(Pre_Payment_Para.Card_Reset_Inf[0]),8,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}		
	}

	Pre_Get_OverZero_Money();
	buyBeforMoney = Remain_Money_Plus;		
	if( Buy_Money_Flag&0x80 )
	{
		/*" ʣ���ѹ���������ϴι���Ѻ��ۼƹ���Ѹ��� "*/
		Meter_Money_And_Count_Updata(Moneybag_Data.Remain_Money,Moneybag_Data.Buy_Count );
		/*"�����ǿ�Ʊ���,��ֹ�����,�ٵ��ϵ��ƽ���͹��ı���2�θ�λ���,ȡ�����������ݵ�����,��ʹ��Ѷ�ʧ"*/
		Check_Energy_main(1);
		Check_Energy_main(1);
		
		buy_money_OK_flag++;
		/*" �¿������û��źͱ���������״̬ "*/
		/*if( Buy_Card_Kind==GWFAR_USER_CARD_NEW )
		{
			My_Memcpy(Pre_Payment_Para.UserID,UserID,6);
		    	Pay_EE_W(USERID_EE,(unsigned char *)&(Pre_Payment_Para.UserID[0]),6,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			Pre_Payment_Para.Meter_Run_State=0x03;
		    	Pay_EE_W(METER_RUN_STATE_EE,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}*/
	}


	/*"�˴����ӵĳ���Ŀ�Ĳ���ȷ����ʱ����"*/
	//if ( Buy_Money_Flag&0x10 )
	//{
	//	if ( (Para_Updata_Flag & 0x04) && STEP_SWITCH_FLAG_DEFINE )		/*"Li_�޸��˵�ǰ�ݶ�,���Ѿ��л���"*/	
	//	{
	//		Pre_Bill(&MainSoftDate.Year);				/*"Li_���ý�����ʱ,��ǰ��/����õ�������"*/	//Li Update 20130219
	//	}
	//}
	
	if (R_CARD_ERROR_INFO!=GOOD_DEFINE)
		return ERR;
	return OK;
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/*"����Ԥ�ƿ�"*/
unsigned char Set_In_Card(void)
	{
	unsigned char i;
	unsigned char ret=OK;
	unsigned long buy_money;
	unsigned char tempTriffDate[5];
	struct Moneybag_Data Moneybag_Data;
	struct Far_Deal_070103FF_format *data;

	/*"Li_������Կ�����жϣ������˽Կ,���ش���"*/   //Li Update  20130122 
	//if(Pre_Payment_Para.Far_Key_StatusByte)	  /*"Li_���Ϊ��ʽ��Կ�����ش���"*/  
	//{
	//	return ERR;
	//}

	/*"Ǯ���ļ���ʼ�� "*/
	if( Remain_Money_Moneybag_Init() != OK ) 
		return ERR;

	/*"ʣ���ѣ��ϴι���Ѻ��ۼƹ���ѣ����������ʼ�� "*/
	if(Read_Esam_Moneybag_File( (unsigned char * )&Moneybag_Data)!=OK)
		return ERR;

	Para_Updata_Flag = Card_WR_Buff[5];
	/*"������Ϣ�ļ����� "*/
	if (Card_Set_Para(GWFAR_USER_CARD_NEW))
		return ERR;
    Card_Set_Para_to_Meter(GWFAR_USER_CARD_NEW);
	
	//My_memcpyRev(&progman.U_char[0], &cpucard_number[4], 4);
	clearFlag=0;
	Pay_Money_Clear();
	Pay_Data_All_Clear();
	My_memcpyRev(&oprateCode[0], &cpucard_number[4], 4);
	//Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
	//		(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	
	My_Memcpy(Pre_Payment_Para.Card_Reset_Inf, 0, 8);
	Pay_EE_W(CARD_RESET_INF_EE,(unsigned char *)&(Pre_Payment_Para.Card_Reset_Inf[0]),8,3,
		            		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	
	Pre_Power_Down_Save_Data.Remain_Money = 0;
	Meter_Money_And_Count_Updata(Moneybag_Data.Remain_Money,Moneybag_Data.Buy_Count);

	//if ( Para_Updata_Flag & 0x03 )	/*"Ԥ�ÿ����ܼ�"*/
	//{
	//	Pre_Payment_Data.TriffProgNum++;
	//	Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
	//			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
	//	Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"��̷��ʼ�¼"*/
	//}
	//if ( Para_Updata_Flag & 0x0C )
	//{
	//	Pre_Payment_Data.StepProgNum++;
	//	Pay_EE_W(StepProgNum_EE,(unsigned char *)&(Pre_Payment_Data.StepProgNum),4,3,
	//			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
	//	Pay_For_Event_Dot((const unsigned char *)&ProgramStep_Event);	/*"�ݶȱ�̼�¼"*/
	//}	

	Pre_Payment_Para.Meter_Run_State=0;
	Pay_EE_W(METER_RUN_STATE_EE,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
			   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	buy_money_OK_flag=0xB0;
	//Pre_Payment_Para.Far_Key_StatusByte=0;
	//Pay_EE_W(FAR_KEY_STATUSBYTE_EE,(unsigned char *)&(Pre_Payment_Data.Far_Key_StatusByte),4,3,
	//		   (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
	//CREATE_ZERO_DEFINE=0;	//GS
	//Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
	// 		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	


	/*" ������Ϣ�ļ� "*/
	if( Updata_Esam_Return_File(0x11,0,0) != OK )
		ret=ERR;

	clearFlag=12;	/*"��־����10,��Ԥ�ÿ�������ʱ����ʾclear"*/

/*"��ʼ���ɹ������ʣ���Ѻ�͸֧����޶Ϊ0�����բ�����������Զ���բ"*/
	if( REMAIN_MONEY_OVER_CLUB_DEFINE )
	{
		REMAIN_MONEY_OVER_CLUB_DEFINE = 0;
		Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		Relay_Alarm_SWitch_Flag[0][0] &= 0xEF;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xEF;		
	}
	Remain_Money_Alarm_Judge();	/*"��Ҫ��բ�ı�־������"*/

	return ret;
	}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/*"�̵������Կ�"*/
unsigned char Relay_TEST_Card(void)
	{	
	Relay_Deal(1);
	
	//Pre_Payment_Para.Far_Key_StatusByte=0;
	//Pay_EE_W(FAR_KEY_STATUSBYTE_EE,(unsigned char *)&(Pre_Payment_Data.Far_Key_StatusByte),4,3,
	//		   (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);

	return OK;
	}
/*"����������"*/
void Card_pull_out(void)
{
	IC_FLAG.byte=0;
	buy_money_OK_flag=0;
	Card_Type=0;
}


/*"��ԭ����ǰ���õظ��Ƶ�Ŀ������"*/
void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len)
	{	
	unsigned char i;	

	for(i=0;i<len;i++)
		*(to+i)=*(from+len-1-i);
	}

/*"������ǰ����"*/
void Reverse_data(unsigned char *data, unsigned int len)
	{
	unsigned char c_temp;
	unsigned char *pc_temp;
	unsigned int i;
	
	pc_temp=data;
	pc_temp+=len-1;
	for(i=0;i<len/2;i++)
		{
		c_temp=*data;
		*data=*pc_temp;
		*pc_temp=c_temp;
		data++;
		pc_temp--;
		}
	}



/*"�����¼���ʱ���ݸ�ֵ"*/
void buy_money_event(unsigned char *p)
{
	;
}

/*"Զ�̿����¼���ʱ���ݸ�ֵ"*/
void far_conrol_event(unsigned char *p)
{
	unsigned char i;

	if (FAR_OPRATE_ID_DEFINE)
		{
		FAR_OPRATE_ID_DEFINE=0;
		Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	else
		{
		for (i=0;i<4;i++)	Pre_Payment_Data.oprateCode[i]=0xFF;
		}
	memcpy(p+6,(unsigned char *)&Pre_Payment_Data.oprateCode[0],4);
	//Pre_Payment_Data.Far_On_Count++;
	//Pay_EE_W(FAR_ON_COUNT_EE,(unsigned char*)&Pre_Payment_Data.Far_On_Count,4,3,(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
}

/*"��բ�����¼���ʱ���ݸ�ֵ"*/
void far_close_event(unsigned char *p)
{
	unsigned char i,flag=0;

	if (OPRATE_ID_CLOSE_DEFINE||METER_IN_FRIEND_DAY_DEFINE)
		{
		OPRATE_ID_CLOSE_DEFINE=0;
		flag=1;
		}
	else
		{
		for (i=0;i<4;i++)	Pre_Payment_Data.oprateCode[i]=0xFF;
		}
	if (FAR_OPRATE_ID_DEFINE)
		{
		FAR_OPRATE_ID_DEFINE=0;
		flag=1;
		}	
	if (flag)
		{
		Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	memcpy(p+6,(unsigned char *)&Pre_Payment_Data.oprateCode[0],4);
	//Pre_Payment_Data.Far_On_Count++;
	//Pay_EE_W(FAR_ON_COUNT_EE,(unsigned char*)&Pre_Payment_Data.Far_On_Count,4,3,(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
}

				
//------------------------------------------------------------------------
/*"�Ƿ���зѿؿ��ƹ���"*/
int Get_Pay_Flag(void)
{
	if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)		/*"�ѿر�"*/
		return 0;

	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	return -1;
}

/*"�Ƿ����Զ�̿��ƹ���(�Ƿ��ESAM)"*/
//int Get_FarControl_Flag(void)
//{
	//if (MACRO_FAY_CONTROL_FLAG)		/*"Զ�̿���"*/
//		return 0;

	//Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	//return -1;
//}

/*"HL:00��Ԥ����,01Ԥ���ѵ�����,10Ԥ���ѵ�ѱ�"*/
/*"�Ƿ�Ϊ���طѿر�"*/
int Get_Payment_Flag(void)
{
	if (MACRO_LOCAL_PAY_FLAG)	/*"���طѿر�"*/
		return OK;
	
	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;		/*"�Ǳ��طѿر�,���������������"*/
	return -1;
}

/*"�Ƿ�ΪԤ����ѱ�"*/
int Get_Money_Flag(void)
{
	//if ((NEW645Meter_States.Meter_Status3.intd&0x0200)==0x0200)		/*"Ԥ�����"*/
	if (Get_Payment_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		return -1;
	
	return OK;
}

/*"  	�Ƿ�ΪԤ��������"*/
/*
int Get_Energy_Flag(void)
{
	if ((NEW645Meter_States.Meter_Status3.intd&0x0100)==0x0100)		Ԥ������
		return 0;
	
	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	return -1;
}
*/

int Get_cur_which_step(void)
{
	if (Get_Payment_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
	{
		Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;	
		return -1;
	}
	
	if (RunStepNum>0)
	{
		Readdata_buff[0] = Curr_Step_Triff + 1;
	}
	else
	{
		Readdata_buff[0] = 0;
	}
	return OK;
}


/*"ȡ����ʣ����"*/
int Get_Plus_Money(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		{
		Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;	
		return -1;
		}
	
	Pre_Get_OverZero_Money();
	Remain_Money_Temp=Pre_Power_Down_Save_Data.Remain_Money;
	if (DISP_PLUS_FLAG_DEFINE && (Remain_Money_Plus>=100000000L))
		{
		DISP_MYRIAD_FLAG_DEFINE=1;
		Remain_Money_Plus/=10000L;
		}

	//HexToBcd(4,(unsigned char  *)&Remain_Money_Plus,Readdata_buff);

	return ret;
}

/*"ȡ͸֧���"*/
int Get_Nega_Money(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		return -1;
	
	Pre_Get_OverZero_Money();
	Remain_Money_Temp=Pre_Power_Down_Save_Data.Remain_Money;
	if (DISP_NEGA_FLAG_DEFINE && (Remain_Money_Nega>=80000000L))
		{
		DISP_MYRIAD_FLAG_DEFINE=1;
		Remain_Money_Nega/=10000L;
		}

	return ret;
}

/*"  	ȡʣ����"*/
int Get_Remain_Money(void)
{
	int ret=0;
	
	Pre_Get_OverZero_Money();
	Remain_Money_Temp=Pre_Power_Down_Save_Data.Remain_Money;
	ret=Get_Money_Flag();

	if (DISP_MONEY_FLAG_DEFINE && (Remain_Money_Temp>=80000000L || Remain_Money_Temp<=-80000000L))
		{
		DISP_MYRIAD_FLAG_DEFINE=1;
		Remain_Money_Temp/=10000L;
		}
	
	return ret;
}

/*"ȡʣ�����"*/
/*
int Get_Remain_Energy(void)
{
	int ret=0;
	
	Pre_Get_OverZero_Money();
	ret=Get_Energy_Flag();

	return ret;
}
*/

/*"�忨״̬���ڶ�ȡ����δ֪"*/
int Get_OPCard_StatusByte(void)
{
	if (Get_Payment_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		return -1;
	Readdata_buff[0]=Pre_Payment_Data.OPCard_StatusByte;
 	Pre_Payment_Data.OPCard_StatusByte=0;
	return OK;
}

/*"ȡ��ǰ�µ���"*/
int Get_Month_Energy(void)
{
	if (Get_Pay_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		return -1;
	
	//if (YEAR_BILL_FLAG)
	//	My_Memcpy(Readdata_buff,0,4);
	//else
	//	My_Memcpy(Readdata_buff,(unsigned char *)&Pre_Power_Down_Save_Data.Month_Total_Energy,4);
		
	return OK;
}

/*"ȡ��ǰ�����"*/
int Get_Year_Energy(void)
{
	if (Get_Pay_Flag()!=OK)	/*"�Ƿ�Ϊ���طѿر�"*/
		return -1;
	
	if (YEAR_BILL_FLAG)
	{
		//-----------------------------------------------------------------------//
		//Li Update 20130507
		//-----------------------------------------------------------------------//
		Pre_Payment_Data.Year_Total_Energy_Date.YEAR	= MainSoftDate.Year;	
		Pre_Payment_Data.Year_Total_Energy_Date.Month = MainSoftDate.Month;
		Pre_Payment_Data.Year_Total_Energy_Date.Day = MainSoftDate.Day;
		Pre_Payment_Data.Year_Total_Energy_Date.Hour = MainSoftDate.Hour;
		//-----------------------------------------------------------------------//
	}
	else
	{
		My_Memcpy((unsigned char *)&Pre_Payment_Data.Year_Total_Energy_Date,0,sizeof(struct  PRE_YEAR_BILLDATE_DEF));
	}
		
	return OK;
}

/*int Set_PayMod2(void)
{
	union Pay_For_Users_Flag3 tmp;

	if (Get_Pay_Flag()!=0)
		return -1;
//	My_Memcpy((unsigned char *)&tmp, Co.c.addr5,1);
//	if (tmp.bit.TRIFF_OR_STEP_FLAG!=Pre_Payment_Para.Pay_For_Users_Flag3.bit.TRIFF_OR_STEP_FLAG)
//		{
//		Pre_Payment_Para.Curr_Triff_Point=0;
//		Pay_EE_W(CURR_TRIFF_POINT_EE,&(Pre_Payment_Para.Curr_Triff_Point),1,3,
//			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
//		}
	return 0;
}*/

/*"  	��CT���"*/
int  Set_CT(void)
{
	unsigned long tmp=0;
	int ret=0;
	float tt1;

	if (Get_Payment_Flag()!=0)
		return -1;

	BcdToHex(3,Co.c.addr5,(unsigned char *)&tmp);
	if (tmp==0)
		return -1;
	//if (MULTIPLE_FORCE_1_DEFINE && (tmp!=1))
	//	return -1;
	tt1=tmp;
	tt1 *= Pre_Payment_Para.P_T;
	if(tt1>99999L)
		return -1;

	return ret;
}

/*"  	��PT���"*/
int  Set_PT(void)
{
	unsigned long tmp=0;
	int ret=0;
	float tt1;
	
	if (Get_Payment_Flag()!=0)
		return -1;
	BcdToHex(3,Co.c.addr5,(unsigned char *)&tmp);
	if (tmp==0)
		return -1;
	//if (MULTIPLE_FORCE_1_DEFINE && (tmp!=1))
	//	return -1;
	tt1=tmp;
	tt1 *= Pre_Payment_Para.C_T;
	if(tt1>99999L)
		return -1;

	return ret;
}

/*"  	����ʵ��"*/
int  Set_Triff_Price(void)
{
	if (Get_Payment_Flag()!=0)
		return -1;
	Pre_Payment_Data.TriffProgNum++;
	Pay_EE_W(TriffProgNum_EE,(unsigned char *)&Pre_Payment_Data.TriffProgNum,4,3,
			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);
	//Pre_Duct_Data_Clear();
	if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x20) 
	{
       EventReportState_Expand(1, 5, 0);  
       Save_EventReportTimes(PROGTRIFFPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgTriffPrice_times);
	}
	return 0;
}

/*"ȡ��ǰ���ʼ��ƽ�ȵ��(�Ĵ�,��ʾʱ��)"*/
int Get_Current_Triff(void)
{
	unsigned char Curr_Period_Dec=0; /*"��ʾ�����õ�ʱ�εļ��ƽ�ȵ��"*/
	
	if (Get_Money_Flag()!=0)
		return -1;
	
	if (SpicReq_SC_DEFINE)
		{
		Curr_Period_Dec=Curr_Period_Flag;
		}
	My_Memcpy((unsigned char *)&Readdata_buff[0],(unsigned char *)&Pre_Payment_Para.Triff[0][Curr_Period_Dec*4],16);
	return 0;
}

#if 0
/*"����ʵ��"*/
int  Set_Triff_Price_After(void)
{
	unsigned char i,len;
	
	len=Co.c.len-12;
	len/=4;
	for (i=len; i<(PRE_MAX_TRIFF); i++)		//?
		{
		Pre_Payment_Para.Triff[1][i]=Pre_Payment_Para.Triff[1][len-1];
		}
	return 0;
}
#endif

/*"  	���ݶȵ��"*/
int  Set_Step_Price(void)
{
	if (Get_Payment_Flag()!=0)
		return -1;
	Pre_Payment_Data.StepProgNum++;
	Pay_EE_W(StepProgNum_EE,(unsigned char *)&Pre_Payment_Data.StepProgNum,4,3,
			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	Pay_For_Event_Dot((const unsigned char *)&ProgramStep_Event);
	Pre_Duct_Data_Clear();
    	if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x40) 
    	{
       EventReportState_Expand(1, 6, 0);  
       Save_EventReportTimes(PROGSTEPPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgStepPrice_times);
    	}      
        FeedWatchdog();
	return 0;
}
#if 0
/*"���������"*/
int Set_Yer_Bill_Data(void)				//Li Update 20130221
{
      unsigned char n;

	if((*(Co.c.addr5+0)==0x99)&&(*(Co.c.addr5+1)==0x99)&&(*(Co.c.addr5+2)==0x99))
		;
	else
		{
		for(n=0;n<3;n++)
			{
			Co.c.h[3-n]=*(Co.c.addr5+n);
			if(!CheckBCD(*(Co.c.addr5+n)))
				return -1;	
			}
		if (Co.c.h[1]<=0x12 && Co.c.h[1] && Co.c.h[2] 
				&&(OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))
				&&Co.c.h[3]<=0x23)
			;
		else 
			return -1;		
		}

	Pre_Bill(&MainSoftDate.Year);
	return 0;
}

/*"  	���ݶ���"*/
int  Set_TriffPrice_Num(unsigned char num)
{
	//if (Get_Payment_Flag()!=0)
	//	return -1;
	//BcdToHex(1,&num,(unsigned char *)&Pre_Payment_Para.TriffPriceNum);
	Pre_Payment_Para.TriffPriceNum=num;
	Pay_EE_W(TriffPriceNum_EE,(unsigned char *)&(Pre_Payment_Para.TriffPriceNum),1,3,
		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	return 0;
}
#endif

/*"  	���ݶ���"*/
int  Set_Step_Num(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=0)
		return -1;

	if (*Co.c.addr5>MAX_STEP)
		return -1;
	
	return ret;
}

/*"����Կ����"*/
int Set_PassNumber(void)
{
	if (*Co.c.addr5>0x20)	//hex	//max 32 
		return -1;
	return 0;
}

/*"ȡ�ͻ����"*/
int Get_Pre_UserD(void)
{
	//if (Get_Payment_Flag()!=0)
	//	return -1;	
	My_Memcpy(Readdata_buff,0,6);
	My_memcpyRev(Readdata_buff,(unsigned char*)&Pre_Payment_Para.UserID[0],6);
	return 0;
}

/*"  	��ͻ����"*/
int Set_Pre_UserD(void)
{
	//if (Get_Payment_Flag()!=0)
	//	return -1;
	if (MACRO_LOCAL_PAY_FLAG)	/*"���طѿص��ܱ�ͻ����ֻ������ʱ�޸ģ���֧��Զ���޸�"*/
		return -1;
	My_Memcpy(Readdata_buff,Co.c.addr5,6);
	My_memcpyRev((unsigned char *)&Pre_Payment_Para.UserID[0],Readdata_buff,6);
	Pay_EE_W(USERID_EE,(unsigned char*)&Pre_Payment_Para.UserID[0],6,0,
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	
	return 0;
}

/*"  	ȡ���"*/
int Get_Meter_ID(void)
{
	My_Memcpy(Readdata_buff,0,6);
	My_memcpyRev(Readdata_buff,(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
	return 0;
}

/*"  	����"*/
int Set_Meter_ID(void)
{
	/*"ֻ���ڹ�Կ״̬�����ñ��"*/
	//if (MACRO_LOCAL_PAY_FLAG || (MACRO_FAY_CONTROL_FLAG && Pre_Payment_Para.Far_PassWord_Inf))
	if (Pre_Payment_Para.Far_Key_StatusByte&&(!O1ther_Meter_Parameter.WorkRoomState))	
	{
		Meter_States.ErrOfInformation.bit.Invalid_Password=1;
		return -1;
	}
	
	My_Memcpy(Readdata_buff,Co.c.addr5,6);
	My_memcpyRev((unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],Readdata_buff,6);
	WRLC256(BCDMETERID_ROM,(unsigned char*)&Meter_Parameter.parameter2.BcdMeterID[0],6,0,0);
	Set_Meter_para_Deal(BCDMETERID_ROM);
	
	return 0;
}

/*"���÷�ʱ����л�ʱ�䡢�ݶȲ����л�ʱ��"*/
int Set_PaySwitchDate(void)
{ 
	if (Get_Payment_Flag()!=0)
		return -1;

      return Set_TriffSwitchDate();
}

/*"���ü̵������巽ʽ��բά��ʱ��"*/
int Set_Ne_RelayActTime(void)
{
	 unsigned int tmp;

	tmp=*((unsigned int *)Co.c.addr5);
	//if (tmp<0x100)
	//	return -1;	 
	 //if (tmp%0x100!=0)
	 //	return -1;
	if (tmp<0x05)	/*"����С��5����"*/
		return -1;
	//if ((tmp%0x05)!=0)
	// 	return -1;
	
	return 0;
}

/*"������֤��Чʱ��"*/
int Set_InfaIdenTime(void)
{ 
	unsigned int tmp;
	
	//if (Get_Payment_Flag()!=0)
	//	return -1;

	tmp=*((unsigned int *)Co.c.addr5);
	if (tmp<0x01)
		return -1;
	
	return 0;
}

/*"����2����4������"*/
int Set_PassWord(void)
{ 
	unsigned char tmp;

	tmp=*((unsigned char *)Co.c.addr5);
	tmp+=1;	/*"04000C03��Ӧ2�����룬04000C05��Ӧ4������"*/
	if (tmp!=cx[3].idt.d[0])
		return -1;
	
	return 0;
}


/*"�˷ѹ���"*/
int Refundmentment_Money(void)
{
	if (Get_Payment_Flag()!=0)
		return -1;
	
	return 0;
	
	//My_Memcpy((unsigned char *)&Pre_Payment_Para.SendBack_Money,Co.c.addr5,4);
	//Pre_Get_OverZero_Money();
	//buyBeforMoney= Remain_Money_Plus;
	//Pre_Power_Down_Save_Data.Remain_Money = buyBeforMoney-Pre_Payment_Para.SendBack_Money;
	//Pre_Get_OverZero_Money();
	//Pre_Payment_Data.Back_Money_Count++;
	//if (Pre_Payment_Data.Back_Money_Count>999999)
	//	Pre_Payment_Data.Back_Money_Count=0;
	//Pay_EE_W(Back_Money_Count_EE,(unsigned char*)&Pre_Payment_Data.Back_Money_Count,4,3,(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE); 	
	//Pay_For_Event_Dot((const unsigned char *)&Refundment_Event);
	//return 0;
}

int Set_Wai_RelayActEnergy(void)
{
	if (*((unsigned int *)Co.c.addr5)<0x10)
		return -1;
	
	return 0;
}


void getRelayType(void)	// payment
{
	unsigned char i=0;

//	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
//		{
//		FLAG_SWITCH_ACT_MODE=1;	//wai
//		return;
//		}

	for (i=0;i<5;i++)
		{
		if (RELAY_TYPE_SEL)
			break;
		Delay(10);
		}
	if (i>=5)
		FLAG_SWITCH_ACT_MODE=1;	//wai
	else
		FLAG_SWITCH_ACT_MODE=0;	//ne		/*"Li_���ö̽ӣ�����Ч"*/

//		FLAG_SWITCH_ACT_MODE=0;	//ne		/*"Li_���ö̽ӣ�����Ч"*/
}

/*"IC���޸Ĳ�����̼�¼"*/
unsigned int CardProgrammeEvent(void)
	{
	union Long_To_Char progman,progdata;
	unsigned int ret;
	unsigned char int2ic_t;

	int2ic_t = int2ic;
	int2ic &= 0xf8;
	ret  = 0;
	if( Card_Type!=GWFAR_USER_CARD && Card_Type!=GWFAR_PARA_SET_CARD )
		return ret;
	if( Para_Updata_Flag ==0 )
		return ret;
	if( Para_Updata_Flag_Suc==0 )
		return ret;
	My_memcpyRev(&progman.U_char[0], &cpucard_number[4], 4);
	progdata.U_char[0] = Para_Updata_Flag;
	progdata.U_char[1] = Card_Type;
	progdata.U_char[3]  = 0x99;
	if( Pre_Payment_Para.Far_Key_StatusByte )
		progdata.U_char[2]  = 0x98;
	else
		progdata.U_char[2]  = 0x99;
	ProgrammeEventEnd_Check_Payment();
	ret=ProgrammeEvent(progman.U_long,progdata.U_long);
	ProgrammeEventEnd_Check_Payment();
	int2ic |= int2ic_t;
	return ret;
	}

unsigned char getCardErrConver(unsigned char inData)
{
	unsigned char ret;
	if (press_card_state==0x10||press_card_state==0x16)
		ret=press_card_state;		//fay
	else
		{
		//BcdToHex(1, &R_CARD_ERROR_INFO, &i);
		ret=0x30+CARD_ERR_INF[R_CARD_ERROR_INFO];	//loc
		}
	return ret;
}

	
//--------------------------------------------------------------------
//--------------------------------------------------------------------
/*" �ж��ļ����ݽṹ��֡ͷ֡β��Ч����Ƿ�Ϸ� "*/
unsigned char Frame_Judge(unsigned char * Point,unsigned char length)
	{
	unsigned char Cs;
	
	if(Point[0]!=0x68)
		{
		R_CARD_ERROR_INFO=CARDFILE_FORMAT_DEFINE;
		return ERR;
		}		
	if(Point[length-1]!=0x16)
		{
		R_CARD_ERROR_INFO=CARDFILE_FORMAT_DEFINE;
		return ERR;
		}
  	Cs=Cal_Add_CS(&Point[1],length-3);
	if( Cs!=Point[length-2] ) 
		{
		R_CARD_ERROR_INFO=CARDFILE_FORMAT_DEFINE;
		return ERR;
		}

	return OK;
	}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
/*" ʣ���ѹ���������ϴι���Ѻ��ۼƹ���Ѹ��� "*/
void Meter_Money_And_Count_Updata( unsigned long Curr_Buy_Money,unsigned long Curr_Buy_Money_Count )
	{
//	Remain_Money_Cal(1,Curr_Buy_Money);
	Pre_Get_OverZero_Money();
	buyBeforMoney = Remain_Money_Plus;
	Pre_Power_Down_Save_Data.Remain_Money +=Curr_Buy_Money;
	Pre_Payment_Data.Total_Buy_Money+=( unsigned long )Curr_Buy_Money;
	Pre_Payment_Data.Last_Buy_Money=Curr_Buy_Money;
	Pay_EE_W(LAST_BUY_MONEY_EE,(unsigned char*)&Pre_Payment_Data.Last_Buy_Money,12,3,
			 (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	Pre_Payment_Para.Buy_Count = Curr_Buy_Money_Count;
	Pay_EE_W(BUY_COUNT_EE,(unsigned char *)&(Pre_Payment_Para.Buy_Count),4,3,
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	FUN_BUY_FLAG_DEFINE = 1;
	Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
		 	 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	
	Pay_For_Data_Save();
	Pre_Get_OverZero_Money();
	Pay_For_Event_Dot((const unsigned char *)&Buy_Event);

	if (SWITCH_FACT_DEFINE && (FAR_WARN_1D_DEFINE||FAR_WARN_1E_DEFINE))	/*"Ԥ��բ��ʱ�ָ�������,�忨����ֱ�Ӻ�բ��Զ�̹���������բ�������ֱ�Ӻ�բ"*/
		{
		FarOpenTime=GetNowTime()+Pre_Payment_Para.Far_Close_Delay*60000;	/*"��������Ԥ��բ"*/
		if (!Far_Identity_Auth_Ok_Flag)
			SWITCH_ALLOW_CLOSE_DEFINE=1;	/*"�忨����ֱ�Ӻ�բ"*/
		}	
	}

#if 0
/*" �˷Ѵ��� "*/
unsigned char refund_money(signed long money)
{
    signed long Remain_Money;
    unsigned char Order_Head[4];
	struct Moneybag_Data Moneybag_Data;
    signed long subtract;

    if (money > Pre_Payment_Data.Last_Buy_Money) {
        return ERR;
    }
    
    if (FUN_BUY_FLAG_DEFINE) {
        Pre_Payment_Para.SendBack_Money = money;
        Esam_Remain_Money_Dec();
        Pre_Get_OverZero_Money();
        buyBeforMoney = Remain_Money_Plus;

        /*" ����ESAM�е�Ǯ���ļ� "*/
        Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data);
        if (money < Moneybag_Data.Remain_Money) {
            subtract = money;
        } else {
            subtract = Moneybag_Data.Remain_Money;
        }
    	Reverse_data((unsigned char *)&subtract,4);
    	Order_Head[0] = 0x80;
    	Order_Head[1] = 0x30;
    	Order_Head[2] = 0x00;
    	Order_Head[3] = 0x0C;
    	if( CPU_Card_Driver((const unsigned char *)&Order_Head[0],4,(unsigned char *)(&subtract),0,CommunicationPortMode,0)!= OK )
    		return ERR;
       /*" ���µ���е�ʣ���� "*/
       Pre_Power_Down_Save_Data.Remain_Money -= money;
	Pay_For_Data_Save();
       Pre_Get_OverZero_Money();

       Pre_Payment_Data.Back_Money_Count++;
    	if (Pre_Payment_Data.Back_Money_Count > 999999)
    		Pre_Payment_Data.Back_Money_Count = 0;
    	Pay_EE_W(Back_Money_Count_EE,(unsigned char*)&Pre_Payment_Data.Back_Money_Count,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE); 	
    	Pay_For_Event_Dot((const unsigned char *)&Refundment_Event);
	
    	FUN_BUY_FLAG_DEFINE = 0;
    	Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
    		 	 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);			
        return OK;
	}
    return ERR;
}
#endif

//-----------------------------------------------------------------
//-----------------------------------------------------------------
/*" �����д�ļ� "*/
unsigned char Updata_Esam_Return_File(unsigned char Order_Kind,unsigned long Money,unsigned long cnt)
	{
	unsigned char i;
	unsigned int Length;
	
	for( i=0;i<LENGTH_RUN_INF_DATA+6 ;i++)
		Co.b[i]=0;
	
	Co.b[0] = 0x68;
	Co.b[2] = 0;
	Co.b[3] = LENGTH_RUN_INF_DATA;

	Deal_Run_Inf_Data(Co.b+4,Order_Kind,Money,cnt);
	if (Order_Kind==0xB1)
		Order_Kind=0x11;
	Co.b[1] = Order_Kind;
	
	Co.b[LENGTH_RUN_INF_DATA+4] = Cal_Add_CS(Co.b+1,LENGTH_RUN_INF_DATA+3);
	Co.b[LENGTH_RUN_INF_DATA+5] = 0x16;
	
	CPU_ESAM_CARD_Control(ESAM);

//	if( Select_File(0, 0, 6) != OK )
//		return ERR;
//	if( Write(0,Update_Binary,0,0,49,Card_WR_Buff) != OK )
//		return ERR;
	
	if( Write(0,Update_Binary,0x80+ESAM_RUN_INF_FILE,0,LENGTH_RUN_INF_DATA+6,Co.b) != OK )
	{
		R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
		return ERR;
	}
	return OK;
	}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
/*"�����ۼ�Ч��� "*/
unsigned char Cal_Add_CS(unsigned char * Point,unsigned char L)
	{
	unsigned char Cs,i;

	Cs = 0;
	for(i=0;i<L;i++)
		Cs+=*Point++;
	return Cs;
	}


//===================================================================//
//Function Name:   F_E_BurseFreezeData
//
//
//===================================================================//
unsigned char F_E_BurseFreezeData(void)
{	
	Pre_Get_OverZero_Money();
	//if(Pre_Power_Down_Save_Data.Remain_Money>=0)					/*"����״̬"*/
	//{
	//	Co.b[0] = 0;
	//	My_Memcpy((unsigned char *)&Co.b[1],(unsigned char *)&Remain_Money_Plus,4);
	//}
	//else					/*"͸֧���"*/
	//{
	//	Co.b[0] = 0x01;
	//	My_Memcpy((unsigned char *)&Co.b[1],(unsigned char *)&Remain_Money_Nega,4);		
	//}
	Pay_For_Event_Dot((const unsigned char *)&E_Burse_Event);	/*"��̷��ʼ�¼"*/	//Li Update 20130107 
}



