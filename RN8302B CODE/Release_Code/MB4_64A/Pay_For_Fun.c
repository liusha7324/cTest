/*"**********************************************************************************"*/
/*" Ԥ���ѵײ㺯�� "*/
/*" �������������� "*/
/*" �����ڣ�2009��01��12�� "*/
/*" �װ汾��1.00 "*/

#include "defdata.h"

#include "Pay_def.h"

#include "EEPROM.H"
#include "Initram.h"
#include "ram.h"
#include "Demand.h"
#include "I2C_operation.h"
#include "File_System.h"
#include "att7022_operation.h"
#include "comm.h"
#include "interrupt.h"
#include "MB_Showmain.h"
#include "MB_Keymain.h"
#include "Multi.h"
#include "Eventnew.h"
#include "Measure_Interface.h" 
#include "ICcard.h"
#include "Pay_For_Fun.h"
#include "Ex_Cpucard_Driver.h"

#include "Far_pay.h"
#include "BackLight_Ctrl.h"



/*"**********************************************************************************"*/
/*" ������������س��� "*/

/*" ������������ر��� "*/
unsigned long Curr_Time;
unsigned char Buzzer_Cortrol_Time;
unsigned char Buzzer_Control_Number ;
unsigned int Buzzer_Control_Period ;
unsigned int Err_Enery=0;
unsigned char switchDriveTime=0;			/*"���ü̵�������������"*/
unsigned char relayPlusTime=0;			/*"���ü̵���,2�����һ������"*/
unsigned char relayPlusCnt=0;				/*"���ü̵�������ʱ�������"*/
unsigned int switchDriveTimeWai=0;		/*"���ü̵�������������"*/


unsigned char R_TestFlag=0;
//unsigned int Curr_Over_30A_Time;	/*"���ü̵����ڵ���30Aʱ������բ������ʼ��ʱ��24Сʱ����բ"*/
//struct DATEANDTIME_DEF Curr_Over_30A_START_Time;	/*"���ü̵����ڵ���30Aʱ������բ������ʼʱ�̣�24Сʱ����բ"*/
unsigned long Curr_Over_30A_START_Time=0;	/*"���ü̵����ڵ���30Aʱ������բ������ʼʱ�̣�24Сʱ����բ"*/

/*"�Ĵ�����Ҫ��"*/
/*"���طѿر���Ҫ֧�������Ĵ���ˮ�ڡ���ˮ�ڡ�ƽˮ�����׼��ڵ�ۣ����4.3.4���еķ��ʵ�۲�����˵����"*/
/*"ע1�����ʵ�۲���������ʱ�α������з��飬ÿ4�����ʵ��һ�飬��32�����ʵ�۷�Ϊ8�飬������ʱ�α�Ŷ�Ӧһ����ʵ��"*/
unsigned char Curr_Period_Flag=0; /*" ��ǰʱ�α��־0~7��Ӧ1~8ʱ�� "*/

extern unsigned  char OverPowerAlarmFlag;
extern unsigned char Relay_Pro_Act_Time;
extern unsigned char RelayErrCheckNum;
extern unsigned char RelayOkCheckNum;
extern unsigned char RelayActStaCheckNum;

extern void Show_Err_Type(char type);
/*"�ѿ���عⱨ��"*/
/*
unsigned char pay_Led_Alarm(void)
{
	unsigned char ret=0;
	if ((PAY_LED_RELAY_ERR_EFINE && SWITCH_ERR_CLUE_DEFINE)
	|| (PAY_LED_ESAM_ERR_DEFINE && ESAM_ERR_DEFINE && MACRO_ESAM_FLAG)
	|| (PAY_FOR_LED_ALARM_DEFINE &&
		(((REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE||REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE||REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE)&&MACRO_LOCAL_PAY_FLAG) 	"Ƿ���"
		|| FAR_OPEN_ALARM_DEFINE ))) 		"Զ�̱���"
		//|| ((!METER_IN_FRIEND_DAY_DEFINE)&&(FAR_OPEN_PREPARE_DEFINE || FAR_OPEN_SWITCH_DEFINE))))) 	"Զ����բ"	
		ret=1;
	return ret;
}
*/

void Pay_Led(void)
{
	if ((REMAIN_MONEY_LOW_TICK_CLUE_DEFINE&&(!METER_IN_FRIEND_DAY_DEFINE))
	|| REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE	/*"���ڱ�������1��������� "*/
	|| REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE	
	|| REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE
	|| FAR_OPEN_ALARM_DEFINE
	|| (FAR_OPEN_PREPARE_DEFINE||(CURR_30A_FLG_DEFINE && Relay_Alarm_SWitch_Flag[1][0])) 	/*"��բ������ʱ������ �� �������ʱ������"*/
	)
        {
           /// if((Light_Back_Up_Flag!=0x55)||(!BACK_LIGHT_ON))
           /// {
		///	Light_Back_Up_Flag=0x55;
		///	Light_Back_Led();   /// 
            ///}
            BackLight_Ctrl(CONTINUOUS_LIGHT_MODE,0,0,PAY_EVENT);///king chen add 130305
           // else
            //{
	//		Light_Back_Time=GetNowTime();
        //    }
      }
      else
      {
	///	if(Light_Back_Up_Flag==0x55)///
	///		Light_Back_Up_Flag=0xaa;
	BackLight_Ctrl(CLOSE_MODE,0,0,PAY_EVENT);///king chen add 130305
      }
}

/*" �������ϵ��ʼ�� "*/
void Buzzer_Init(void)
    {
    Buzzer_Cortrol_Time = 0;
    ALARM_BUZZER_DIRECT = OUTPUT;
	
	if (FAR_WARN_1D_DEFINE||FAR_WARN_1E_DEFINE)
		{
		if (SWITCH_FACT_DEFINE) /*"Ԥ��բʹ�����բ������ʱʱ���ڵ��磬�ϵ��������բ"*/
			{
			FarOpenTime=GetNowTime()-Pre_Payment_Para.Far_Close_Delay*60000;
			}
		else
			{		
			//Curr_Over_30A_START_Time=GetNowTime()-Pre_Payment_Para.CurrLimitProTime*60000;		/*"�ϵ�������30A��������δ��բ����������բ"*/
			FAR_WARN_1D_DEFINE=0;	/*"����ǰ�����30A��������δ��բ���ϵ�����Ԥ��բ���̵������ں�բ״̬"*/
			FAR_WARN_1E_DEFINE=0;
			Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
			 	    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			}
		}
	else if ((!SWITCH_FACT_DEFINE) && ( (NOT_CLOSE_BY_30A_DEFINE == 1) || (FAR_OPEN_PREPARE_DEFINE == 1) ) )
		{
		Curr_Over_30A_START_Time=GetNowTime()-Pre_Payment_Para.CurrLimitProTime*60000;	/*"�ϵ�������30A��������δ��բ����������բ"*/
		CURR_30A_START_CNT_DEFINE=1;	/*"�����ϵ���Ƿ����30A����Ҫ��բ"*/
		}
    }

/*" ÿ����� "*/
void Buzzer_Second_Active(void)
    {
	unsigned long CurrLimit;

    if( Buzzer_Cortrol_Time!=0 )
        Buzzer_Cortrol_Time--;
	
	if(FLAG_SWITCH_ACT_MODE==0)	/*"���ñ�����Ƿ����30A"*/
		{
		CurrLimit=Pre_Payment_Para.CurrLimit*10;	/*"����Ϊ4λС��,������ֵΪ3λС��"*/
		//if ((!SWITCH_FACT_DEFINE)&&		/*"��բ�����"*/
		if (Pre_Payment_Para.CurrLimit	/*"��ֵ��Ϊ0�ž������ƹ���"*/
		&&((Curr[0]>CurrLimit) ||(Curr[1] >CurrLimit) ||(Curr[2] >CurrLimit)))  /*"����24Сʱ�е�������30A,����բ"*/
			CURR_30A_FLG_DEFINE=1;
		else
			{
			CURR_30A_START_CNT_DEFINE=0;	/*"��բ��������Ǵ��������բ���´���բʱ�����ж��Ƿ���������"*/
			CURR_30A_FLG_DEFINE=0;
			Curr_Over_30A_START_Time=0;
			}
		}

	if( Switch_Test_Time !=0 )
        Switch_Test_Time --;

	if( Nei_Relay_Do_Time !=0 )
		Nei_Relay_Do_Time--;
	
    }

//unsigned char Curr_60_Sec_Delay;
/*" ��ǰ��������30 A���� "*/
//void Current_Over_30A_Function(void)
//{
//	if (CURR_30A_START_CNT_DEFINE)  /*"����24Сʱ�е�������30A,����բ"*/
//		{
//		if (Curr_Over_30A_Time<9999)
//			Curr_Over_30A_Time++;
//		}
//}

/*" ÿ����ѭ������ "*/
unsigned char Buzzer_Active(void)
{
	//    VoltageGreaterThanThreshold_Flag = 1;
    if(VoltageGreaterThanThreshold_Flag==0)
	/*"�������ѹ�Ƿ�����ż��ı�־"*/
    {
        Buzzer_Control_Number = 0;
		//Buzzer_Cortrol_Time = 0xFF;
		//return;
    }
    else
	{
      if(Buzzer_Cortrol_Time==0 )             /*" �ñ������������ۼ�,���ǵ�Ϊ0ʱ���� "*/
      {
        /*" ����������Ƿ���Ҫ���� "*/
        if( (Buzzer_Alarm_SWitch_Flag&0x01) 
		//||((PAY_FOR_SOUND_ALARM_DEFINE==1)&&(Buzzer_Alarm_SWitch_Flag&Buzzer_Alarm_Control.byte))
		) 
        {
            if( Buzzer_Control_Number ==0 )
                Curr_Time = 0;
            Buzzer_Control_Number = 0xFF;   /*" 0xFF��ʾ���޴��� "*/
            Buzzer_Control_Period = 200;    /*" 200��ʾ1��İ����� "*/
        }
        else
        {
            Buzzer_Control_Number = 0;
        }
      }
    }
}
/*"**********************************************************************************"*/
/*" �������жϵ��ú��� "*/
/*" 5ms��ʱ���жϵ��� "*/
/*" Ŀ�ģ���֤������������������ "*/
void Inttupt_Buzzer_Deal(void)
{
    //if( Buzzer_Control_Number != 0 )			//Li Update 20130118
	if( (Buzzer_Control_Number != 0) && VoltageGreaterThanThreshold_Flag)
	{
        if( Buzzer_Control_Period != 0 ) /*" 0��ʾ���� "*/
        {
            Curr_Time++;
            if( (Curr_Time) > Buzzer_Control_Period )
            {
                Curr_Time = 0;
                ALARM_SND = ~ALARM_SND;
                if( (!ALARM_SND) && ( Buzzer_Control_Number != 0xFF ) )
                    Buzzer_Control_Number--;
            }
        }
        else
            ALARM_SND = 1;
    }
    else
        ALARM_SND = 0;
}
/*"**********************************************************************************"*/
/*" IC������ɹ���ʧ�ܺ�ĵ��� "*/
/*" ���������쳣����ʱ�Ĳ�����ֵ "*/
/*" Control_Period�����ư�����,��λ��5ms "*/
/*" Control_Number�����ƴ��� "*/
/*" Control_Time������ʱ�� �� "*/
void Buzzer_Pay_Cortrol(unsigned int Control_Period,unsigned char Control_Number,unsigned char Control_Time)
    {
    Buzzer_Cortrol_Time = Control_Time;
    Buzzer_Control_Number = Control_Number;
    Buzzer_Control_Period = Control_Period;
    }

/*"**********************************************************************************"*/
/*" �̵���������س��� "*/
/*" Output: "*/
/*" BIT0����ʾҪ����ĵ�ƽ�� "*/
/*" BIT7��1��ʾ���������̵��� "*/
/*"       0��ʾ������բ�̵��� "*/
/*" return:OK��ʾ�ɹ����� "*/
/*"        ERR��ʾû�гɹ����� "*/
#pragma SECTION rom UserROMData
const unsigned long Voltage_Spec[4]={10000L,22000L,5770L,38000L};
unsigned char Relay_Driver(unsigned char Output)
	{
    unsigned char i,k,V_OK=0,V_OK2=0;
    unsigned long V80,V70,V65;

	k=V_REGION;
	if (k>3)	/*"��ֹV_REGION����(��Ҫ��δУ��ʱ)"*/
		k=2;
	
	V80 = 79l*Voltage_Spec[k];
	V70 = 69l*Voltage_Spec[k];
	V65 = 64l*Voltage_Spec[k];
	for( i=0;i<3;i++ )
	{
		if (Volt[i] > V80)
			{
			V_OK=2;
			break;
			}
		if (Volt[i] > V70)
			{
			V_OK++;
			}
		if(Volt[i] > V65)
		{
			V_OK2++;
		}
	}
	if(Meter_Parameter.parameter1.LocalFunctionMode.bit.b5 == 0)
	{/*" û�д�3��65%��ѹ������բ��������ģʽ��"*/
		V_OK2 = 0;
	}
	k = Output&0x01;

//V_OK=2;	//test

	if( Output&0x80 )	/*"�����̵�������"*/
		{
		if((V_OK>=2) || (k!=1) || auxiliary_power_flag)	/*"������Դ����ʱ,�����̵�����������"*/
			{
			//if( ALARM_RELAY_STATE_DEFINE != k )
				//{
				ALARM_RELAY = k;
				//ALARM_RELAY_STATE_DEFINE = k;
				return OK;
				//}
			}
		}
	else				/*"��բ�̵�������"*/
		{
			if ((V_OK>=2) || ((FLAG_SWITCH_ACT_MODE)&&(k!=1)) || (V_OK2>=3))
			{
			if( METER_IN_FRIEND_DAY_DEFINE )
				Switch_Plus_Start(0);
			else //if( SWITCH_RELAY_STATE_DEFINE != k )
				{
				Switch_Plus_Start(k);
				}
			return OK;
			}
		}
		
	return ERR;
	}

void Relay_Act_Record(unsigned char mode)
{
	//SWITCH_FACT_DEFINE=mode;
	if (mode)
		{
		Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks++;
		if (Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks>999999)
			Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks=0;
		FAR_OPEN_RECORD_DEFINE = 1;
		FAR_CLOSE_RECORD_DEFINE = 0;
		//SWITCH_FACT_DEFINE=1;
		Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
	 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		Pay_EE_W(FARSWITCH_TICKS_EE,(unsigned char *)&(Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks),4,3,
				 (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		Pay_For_Event_Dot((const unsigned char *)&Far_On_Event);
        
            EventReportState_Expand(3, 1, 1); 
            O1ther_Meter_Parameter.SwitchOn_Report=0;
            WRLC256(SWITCHON_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOn_Report,1,0,0);
            O1ther_Meter_Parameter.SwitchOff_Report=1;
            WRLC256(SWITCHOFF_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOff_Report,1,0,0); 

            ///Save_EventReportTimes(SWITCH_OFF_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Switch_off_times); 
		}
	else
		{
		Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks++;
		if (Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks>999999)
			Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks=0;
		FAR_CLOSE_RECORD_DEFINE = 1;
		FAR_OPEN_RECORD_DEFINE = 0;
		Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
	 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		Pay_EE_W(FARSCLOSE_TIMES_EE,(unsigned char *)&(Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks),4,3,
				 (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		Pay_For_Event_Dot((const unsigned char *)&Far_OFF_Event);
        ///if (!FLAG_SWITCH_ACT_MODE)/*"���ü̵���"*/
        ///{
         ///   EventReportState_Expand(3, 1, 0);  
         ///   Save_EventReportTimes(SWITCH_ON_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Switch_on_times);   
        ///}
        ///else
            EventReportState_Expand(3, 7, 1); 
            O1ther_Meter_Parameter.SwitchOff_Report=0;
            WRLC256(SWITCHOFF_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOff_Report,1,0,0);
            O1ther_Meter_Parameter.SwitchOn_Report=1;
            WRLC256(SWITCHON_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOn_Report,1,0,0); 
		}
	RelayErrCheckNum=0;
	RelayOkCheckNum=0;
	RelayActStaCheckNum=RELAY_ERR_CHECK_TIME+1;
}

/*"�����̵�����������,��ƽ�ø�"*/
/*"mode	1:��բ,0:��բ"*/
void Switch_Plus_Start(unsigned char mode)
{
	if (IntoPowerDownFlag)
		return;
if (FLAG_SWITCH_ACT_MODE)		//wai------
	{
	SWITCH_PREPARE_STATE_DEFINE=mode;
	if( WAI_RELAY_PULSE_DOING_DEFINE==0 || mode==0)
		{
		if (REALY_ON_OFF_KIND_DEFINE && mode)
			{
			switchDriveTimeWai=Pre_Payment_Para.RelayActTime/5;
			if (!switchDriveTimeWai)
				switchDriveTimeWai=80;///king chen modify 130218
			}
		else if ((!REALY_ON_OFF_KIND_DEFINE) && (!mode))	//wai
			{
			if (!Switch_Test_Flag)
				{
				if ((CLOSE_KEY_WAI_RELAY_DEFINE)&&(!SWITCH_ALLOW_CLOSE_DEFINE))
					return;
				}
			}
		//SWITCH_FACT_DEFINE=mode;
		SWITCH_ALLOW_CLOSE_DEFINE=0;
		SWITCH_RELAY=mode;
		Nei_Relay_Do_Energy = 0;
		WAI_RELAY_PULSE_DOING_DEFINE = 1;
		if (mode)
			{
			Nei_Relay_Do_Time = 12;
			if((!FAR_OPEN_RECORD_DEFINE) && (!Switch_Test_Flag))		//record
				{
				//SWITCH_FACT_DEFINE=mode;
				Relay_Act_Record(mode);
				}
			}
		else
			{
			WAI_RELAY_PULSE_DOING_DEFINE = 0;
			if((!FAR_CLOSE_RECORD_DEFINE)  && (!Switch_Test_Flag))		//record
				{
				//SWITCH_FACT_DEFINE=mode;
				Relay_Act_Record(mode);
				}
			}
			if (SWITCH_FACT_DEFINE!=mode)
				{
				SWITCH_FACT_DEFINE=mode;
				RelayErrCheck_DEFINE=0;
				Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),2,3,
			 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				}
			if (Switch_Test_Flag>0)
				{
				Switch_Test_Flag--;
				Pay_EE_W(Switch_Test_Num_EE,(unsigned char *)&(Pre_Payment_Para.Switch_Test_Num),1,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				}				
		}
	else
		{
		if( REALY_ON_OFF_KIND_DEFINE && FLAG_SWITCH_ACT_MODE && SWITCH_FACT_DEFINE )
			{
			if( Nei_Relay_Do_Time ==0 )
				SWITCH_RELAY=0;
			}
		}
	}
else		//-----------ne------------------------
	{
	if (CURR_30A_FLG_DEFINE && mode && 		/*"����30A����բ����"*/
		((Fay_30ALimit_DEFINE && Relay_Alarm_SWitch_Flag[1][0]&0x60) 		/*"Զ������"*/
		|| (Local_30ALimit_DEFINE && Relay_Alarm_SWitch_Flag[1][0]&0x1D)))	/*"��������"*/
		{
		if (NOT_CLOSE_BY_30A_DEFINE == 0)
		{
			NOT_CLOSE_BY_30A_DEFINE = 1;
			Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
					 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE); 				
		}
				
		if (!CURR_30A_START_CNT_DEFINE)
			{
			CURR_30A_START_CNT_DEFINE = 1;		/*"��ʼ����"*/
			Curr_Over_30A_START_Time=GetNowTime();
			return;
			}
		else
			{
			//if ((Curr_Over_30A_Time<Pre_Payment_Para.CurrLimitProTime)&&(ComTime(&softdate.Year,&Curr_Over_30A_START_Time.Year)<86400L))	/*"24Сʱ(24*60*60)�ڲ���բ[����޸�ʱ����������ʱ���жϣ�����޸�ʱ����ǰ�����Լ�ʱ24Сʱ�ж�]"*/ /*"1395L:����1395��Ϊ1440����"*/
			if (GetTimeCount(Curr_Over_30A_START_Time,Pre_Payment_Para.CurrLimitProTime*60000))	/*"24Сʱ(24*60*60)�ڲ���բ"*/ 
				return;
			}
		//Curr_Over_30A_Time=0;
		//My_Memcpy(&Curr_Over_30A_START_Time.Year,0,6);
		}
	
	SWITCH_PREPARE_STATE_DEFINE=mode;
	if (mode!=SWITCH_FACT_DEFINE)
		{
		relayPlusCnt=0;
		relayPlusTime=RELAY_NEXT_PULSE_TIME;
		SWITCH_PROHIBIT_ACT_DEFINE=0;
		}
	if ((relayPlusCnt>=RELAY_PLUSE_CNT)
		|| (SWITCH_PROHIBIT_ACT_DEFINE))
		return;

	Curr_Over_30A_START_Time=0;		/*"30A���Ʊ�־����"*/
	CURR_30A_START_CNT_DEFINE=0;	/*"���������բ���ٷ���բ���ٷ���բʱ������ʱ24Сʱ"*/
	SWITCH_PROHIBIT_ACT_DEFINE=1;
	if (!mode)
		{
		if ((relayPlusTime==RELAY_NEXT_PULSE_TIME)&&(!Switch_Test_Flag))
			{
			if ((!CLOSE_KEY_NE_RELAY_DEFINE)&&(!SWITCH_ALLOW_CLOSE_DEFINE))
				return;
			}
		}
	SWITCH_ALLOW_CLOSE_DEFINE=0;
	if (NOT_CLOSE_BY_30A_DEFINE == 1)
	{
		NOT_CLOSE_BY_30A_DEFINE = 0;
		Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
				 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE); 				
	}
	relayPlusCnt++;	
	//OPEN
	switchDriveTime=40;	// 24*5=120ms
	if (mode)
		{
		SWITCH_CLOSE=0;
		SWITCH_OPEN=1;
		if((!FAR_OPEN_RECORD_DEFINE) && (!Switch_Test_Flag))				//record
			{
			Relay_Act_Record(mode);
			}
		}
	//CLOSE
	else
		{
		SWITCH_OPEN=0;
		SWITCH_CLOSE=1;
		if((!FAR_CLOSE_RECORD_DEFINE) && (!Switch_Test_Flag))			//record
			{
			Relay_Act_Record(mode);
			}
		}
	Relay_Pro_Act_Time=0;
	if (SWITCH_FACT_DEFINE!=mode)
		{
		SWITCH_FACT_DEFINE=mode;
		RelayErrCheck_DEFINE=0;
		Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),2,3,
	 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		//RelayErrCheck_DEFINE=1;
		//Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
		//		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	if (Switch_Test_Flag>0)
		{
		Switch_Test_Flag--;
		Pay_EE_W(Switch_Test_Num_EE,(unsigned char *)&(Pre_Payment_Para.Switch_Test_Num),1,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}		
	}

}

/*"�����̵�����������120�����,��ƽ�õ�"*/
void Switch_Plus_Drive(void)
{
	if (!FLAG_SWITCH_ACT_MODE)
		{
		if ((((SWITCH_OPEN)) || ((SWITCH_CLOSE)) ))
			{
			if(switchDriveTime!=0 )
				switchDriveTime--;
			else
				{
				SWITCH_OPEN=0;
				SWITCH_CLOSE=0;
				}
			}
		}
	else
		{
		if (REALY_ON_OFF_KIND_DEFINE && SWITCH_RELAY)
			{
			if(switchDriveTimeWai!=0 )
				switchDriveTimeWai--;
			else
				{
				SWITCH_RELAY=0;
				}
			}
		}
}


/*" ���ü̵��� "*/
void Relay_Control(void)
    {
    unsigned char i,j,k,l;

	//if (Meter_Parameter.MeterMode[1].bit.b4)
	//	{
	//	if (Pre_Payment_Data.OverPowerSw_Time>=Pre_Payment_Para.OverPower_Time_Limit && Pre_Payment_Para.OverPower_Time_Limit!=0)
	//		Relay_Alarm_SWitch_Flag[1][0] |= 0x01;
	//	else if (!OverPowerAlarmFlag)
	//		Relay_Alarm_SWitch_Flag[1][0] &= 0xFE;
	//	}
	//else
	//	Relay_Alarm_SWitch_Flag[1][0] &= 0xFE;

	/*"������յ���վ��բ���澯����ʱ,Bit6��1,����Bit6��0"*/	/*"��ˢ��BIT6���������̵���"*/
	if ((!METER_IN_FRIEND_DAY_DEFINE)&&( FAR_OPEN_PREPARE_DEFINE || FAR_OPEN_SWITCH_DEFINE ||FAR_WARN_1D_DEFINE ||FAR_WARN_1E_DEFINE))
		NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=1;
	else
		NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=0;
    
    j = 0x80;
    for( i=0;i<2;i++ )
        {
        l = j;
        if( Relay_Alarm_SWitch_Flag[i][0] != 0 )
            {
            l++;
            }
        Relay_Driver(l);
        j<<=1;
        }
    }

/*"**********************************************************************************"*/
/*" �̵����ӿں��� "*/
/*" ÿ����ã���̵�����⿨ʱ����� "*/
/*" Flag��1��ʾ�Ǽ̵�����⿨���ã�10���ָ� "*/
/*" ÿ����� "*/
void Relay_Deal(unsigned char Flag)
    {
    unsigned char i;
    if( Flag==1 && Switch_Test_Time ==0 )
        {
        Switch_Test_Flag=2;
        Switch_Test_Time = 15;
        if( ALARM_RELAY )
			i=0x80;
		else
			i = 0x81;
        Relay_Driver(i);
        //if( SWITCH_RELAY )
        //if (SWITCH_OPEN_STATE_DEFINE)

		if( REALY_ON_OFF_KIND_DEFINE && FLAG_SWITCH_ACT_MODE )
			{
			WAI_RELAY_PULSE_DOING_DEFINE = 0;
			i = 1;
			}
		else
			{
			if (SWITCH_FACT_DEFINE)
					i=0;
				else
					i = 1;
			}
        Relay_Driver(i);
        }

	if( REALY_ON_OFF_KIND_DEFINE && FLAG_SWITCH_ACT_MODE && Switch_Test_Time==11)
		{
		Relay_Driver(1);
		}


    if( Switch_Test_Time <=1 )
        {
        Relay_Control();
        }
    }
/*"**********************************************************************************"*/
/*" �̵����ϵ��ʼ������ "*/
void Relay_Deal_Init(void)
    {
    Switch_Test_Time = 0;
    Relay_Alarm_SWitch_Flag[0][0] = 0;
    Relay_Alarm_SWitch_Flag[0][1] = 0;
    Relay_Alarm_SWitch_Flag[1][0] = 0;
    Relay_Alarm_SWitch_Flag[1][1] = 0;
	ALARM_RELAY_DIRECT =  OUTPUT;
	ALARM_RELAY=0;
	SWITCH_CLEW_DIRECT =  OUTPUT;
	if(1==Displayfinish_flag)///king chen add 130117
	SWITCH_CLEW=0;
	WAI_RELAY_PULSE_DOING_DEFINE = 0;
    }

/*"�̵�������ά��"*/
void Drive_Act_Repair(void)
{
	if (!FLAG_SWITCH_ACT_MODE)
	{
		relayPlusCnt=0;
		relayPlusTime=RELAY_NEXT_PULSE_TIME;
		SWITCH_PROHIBIT_ACT_DEFINE=0;
	}
}

/*"**********************************************************************************"*/

/*" ʣ���ѿۼ��������� "*/
/*" ʣ����С��λ��2λ "*/
/*" ����С��λ��4λ "*/
/*" Enery_Inc��10����ʾ�����ۼӲ���Ϊ0.01Kwh  "*/
/*"            1 ����ʾ�����ۼӲ���Ϊ0.001Kwh "*/
void Remain_Money_Dec(unsigned char Enery_Inc )
    {
    unsigned long Money_Bottom;
    unsigned long Money_Duct_Temp;
      signed long Remain_Money_Temp;
    unsigned char Flag1,Flag2;
	unsigned long long tt1;

	Curr_Money = Curr_Money_T+Curr_Money_S;

	if(!MACRO_LOCAL_PAY_FLAG)
		return;

    if( Pre_Payment_Para.C_T == 0 )
        Pre_Payment_Para.C_T = 1;
    
    if( Pre_Payment_Para.P_T == 0 )
        Pre_Payment_Para.P_T = 1;

    tt1 = Pre_Payment_Para.C_T;
	tt1 *= Pre_Payment_Para.P_T;

	if( tt1> (unsigned long long)99999l )
		{
		Pre_Payment_Para.C_T = 1;
		Pre_Payment_Para.P_T = 1;
		}
    
    Remain_Money_Temp = Pre_Power_Down_Save_Data.Remain_Money;

	Money_Bottom  = Curr_Money;
	Money_Bottom *= Enery_Inc;

    Flag1 =  *((unsigned char *)&Remain_Money_Temp+3)&0x80;
	
    Money_Duct_Temp  = (Money_Bottom/DOUT_MONEY_BOTTOM);
    
    //if( !MULTIPLE_FORCE_1_DEFINE )
        {
        Money_Duct_Temp *= Pre_Payment_Para.C_T;
        Money_Duct_Temp *= Pre_Payment_Para.P_T;
        }
    
    Remain_Money_Temp -= Money_Duct_Temp;
    Flag2 =  *((unsigned char *)&Remain_Money_Temp+3)&0x80;
    if(! (Flag1 && (!Flag2)) )
        Pre_Power_Down_Save_Data.Remain_Money = Remain_Money_Temp;

    tt1 = (Money_Bottom%DOUT_MONEY_BOTTOM);
    //if( !MULTIPLE_FORCE_1_DEFINE )
        {
        tt1*= Pre_Payment_Para.C_T;
        tt1*= Pre_Payment_Para.P_T;
        }
    tt1+=Pre_Power_Down_Save_Data.Remain_Money_bottom;//+=Money_Duct_Temp;

    if( tt1>=DOUT_MONEY_BOTTOM )
        {
        Money_Duct_Temp = tt1/DOUT_MONEY_BOTTOM;
        Remain_Money_Temp -=Money_Duct_Temp;
	tt1%=DOUT_MONEY_BOTTOM;
        Pre_Power_Down_Save_Data.Remain_Money_bottom=tt1;

        Flag2 =  *((unsigned char *)&Remain_Money_Temp+3)&0x80;
        if(! (Flag1 && (!Flag2)) )
            Pre_Power_Down_Save_Data.Remain_Money = Remain_Money_Temp;
        }
	Pre_Power_Down_Save_Data.Remain_Money_bottom=tt1;

	
	//Powerdown_Save_Data.crc_cal = CRC((unsigned char*)&Powerdown_Save_Data,
	//                           sizeof(struct POWERDOWN_SAVE_DATA) - 2);
    }

/*"��ȡ��ǰ���ʵ��"*/
void GetCurrTriffPrice(void)
{
	if (SpicReq_SC_DEFINE)	/*"�Ĵ�����Ҫ��"*/
		{
		Curr_Money_T = Pre_Payment_Para.Triff[0][Curr_Period_Flag*4+TRAFF_RATE-1];
		}
	else
		{
		Curr_Money_T = Pre_Payment_Para.Triff[0][TRAFF_RATE-1];
		}
	
	if (Pre_Payment_Data.CurrMoneyT!=Curr_Money_T)
		{
		Pre_Payment_Data.CurrMoneyT=Curr_Money_T;
		Pay_EE_W(CURRMONEYT_EE,(unsigned char *)&(Pre_Payment_Data.CurrMoneyT),4,3,
               (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		}
}

/*"**********************************************************************************"*/
/*" ��ʱʱ���ʣ���ѿ۳�������� "*/
/*" �ݶ�ģʽʱʣ���ѿ۳�������� "*/
/*" �ݶ��µ����ۼ� "*/
/*" ����һ���ݵ���ֵ�ۼ� "*/
/*" �ݶȷ��ʸ��� "*/
/*" �ݶȵ�ѿۼ� "*/
/*" 0.001Kwh��0.01Kwhʱ�ۼ� "*/
/*" Enery_Inc��10����ʾ�����ۼӲ���Ϊ0.01Kwh  "*/
/*"            1 ����ʾ�����ۼӲ���Ϊ0.001Kwh "*/
unsigned char TRAFF_RATE_Tmp=0;
void Remain_Money_Duct(unsigned char Enery_Inc)
    {
    unsigned char TRAFF_RATE_a,TRAFF_RATE_b=0;
	unsigned char Flag1;
	unsigned long Energy_Temp,Curr_Use_Energy;

	unsigned char tmp;

	tmp=int2ic;
	int2ic&=0xf8;

	if (Meter_Parameter.parameter2.EnergyPoint <= 2 )/*" ������ʾλ��Ϊ2λС��ʱ����0.1KWH�ſ�һ�η�"*/
	{
		Pre_Power_Down_Save_Data.duct_eng += Enery_Inc;
		if (Pre_Power_Down_Save_Data.duct_eng < 10)
		{
			int2ic|=tmp;
			return;
		}
		Enery_Inc = 10;
		Pre_Power_Down_Save_Data.duct_eng -= 10;
	}
	else if (Pre_Power_Down_Save_Data.duct_eng > 0)/*" С��λ����2λ��3λʱ"*/
	{
		if (Pre_Power_Down_Save_Data.duct_eng <= 10)
			Enery_Inc += Pre_Power_Down_Save_Data.duct_eng;
		Pre_Power_Down_Save_Data.duct_eng = 0;
	}
		
	if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)
		{
		/*"��������ʽ�̵�������:�Ͽ�ʱ�ߵ�0.1Kwh"*/ 
		//if ((!FLAG_SWITCH_ACT_MODE) && SWITCH_FACT_DEFINE)	//ne
		if( REALY_ON_OFF_KIND_DEFINE && FLAG_SWITCH_ACT_MODE && SWITCH_FACT_DEFINE )
			{
			Nei_Relay_Do_Energy+=Enery_Inc;
			if (!Pre_Payment_Para.RelayActEnergy)
				Pre_Payment_Para.RelayActEnergy=100;		// 0.1Kwh
			if( Nei_Relay_Do_Energy>=Pre_Payment_Para.RelayActEnergy )
				{
				Nei_Relay_Do_Energy = 0;
				WAI_RELAY_PULSE_DOING_DEFINE = 0;
				}
			}
		else
			Nei_Relay_Do_Energy = 0;
		
		/*"�̵�������:�Ͽ�ʱ�ߵ�0.5Kwh"*/ 
		/*if (SWITCH_FACT_DEFINE)
			{
			Err_Enery+=Enery_Inc;
			if (Err_Enery>500)			// 0.5Kwh
				{
				SWITCH_ERR_CLUE_DEFINE=1;
				Err_Enery=0;
				}
			}
		else
			{
			SWITCH_ERR_CLUE_DEFINE=0;
			Err_Enery=0;
			}*/
		}
	
    if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))    /*" Ԥ���ѹ��ܴ� "*/
    	{
    	int2ic|=tmp;
        return;
    	}
	Flag1 = 0;

	GetCurrTriffPrice();

		Pre_Power_Down_Save_Data.Month_Total_Energy += Enery_Inc;
		if (YEAR_BILL_FLAG)
			{
			Pre_Power_Down_Save_Data.Year_Total_Energy+= Enery_Inc;
			Curr_Use_Energy=Pre_Power_Down_Save_Data.Year_Total_Energy;
			}
		else
			{
			Curr_Use_Energy=Pre_Power_Down_Save_Data.Month_Total_Energy;
			}
		if (Pre_Power_Down_Save_Data.Energy_Next_Step>Enery_Inc)
			Pre_Power_Down_Save_Data.Energy_Next_Step   -= Enery_Inc;
		else
			Pre_Power_Down_Save_Data.Energy_Next_Step=0;
		if (TRAFF_RATE_Tmp!=TRAFF_RATE)
			{
			TRAFF_RATE_Tmp = TRAFF_RATE;
			Next_Energy_Step=0;
			}

        if( Curr_Use_Energy >= Next_Energy_Step )
            {
            Energy_Temp = Curr_Use_Energy;
			Energy_Temp -= Next_Energy_Step;

			if( ( Energy_Temp>0 && Energy_Temp <10 ) && (Enery_Inc==10)) 	/*"���Ե���С��λ��Ϊ�ж�����"*/	//(Meter_Parameter.parameter2.EnergyPoint==2) )
				{
				Flag1 = 0xFF;
				Enery_Inc = 10;	/*"������ݶ�ֵΪ3000������С��λ��3��Ϊ2�����õ������ܻ���3λС��ʱ�ߵĸ�λ��"*/
				Enery_Inc -=( unsigned char )Energy_Temp; /*"����Ϊ291������һ���ݶ�ǰ��9����(10-1)���Ի�֮ǰ�ĵ�ۿ۷�"*/
				Remain_Money_Dec(Enery_Inc);
				}
			
            //if( !STEP1_OR_STEP2_DEFINE )
            //    Find_Step_Curr_Triff_1();
            //else
                Find_Step_Curr_Triff_2();

			if( Flag1 == 0xFF )
				{
				Remain_Money_Dec(( unsigned char )Energy_Temp);
				}
            }

	if( Flag1 == 0 )
		{
    	Remain_Money_Dec(Enery_Inc);
		}
	Pre_Get_OverZero_Money();
	int2ic|=tmp;
//	if( Far_Identity_Auth_Ok_Flag != 0xFF )
//		Esam_Remain_Money_Do(0);
    }


/*"**********************************************************************************"*/
/*"��ȡʵ�����е��ݶ���"*/
unsigned char get_run_step_num(void)
{
	unsigned char i,ret=0;
    unsigned char equal;

	if (MACRO_LOCAL_PAY_FLAG)
		{
		for (i=0; i<MAX_STEP; i++)
			{
			if (Pre_Payment_Para.Energy_Step[0][i])
				break;
			}
		if (i>=MAX_STEP)		/*"�ݶ�ֵΪ0,��ִ���ݶȵ��"*/
			return 0;

		ret=1;
        equal = 0;
		for (i=0; i< (MAX_STEP - 1); i++) 
		{
			if ((Pre_Payment_Para.Energy_Step[0][i+1] > Pre_Payment_Para.Energy_Step[0][i])) {
			    ret++;
                if (equal > 0) {
                    ret += equal;
                    equal = 0;
                }
			}
            if ((Pre_Payment_Para.Energy_Step[0][i+1] == Pre_Payment_Para.Energy_Step[0][i])) {
                equal++;
            }
            if ((Pre_Payment_Para.Energy_Step[0][i+1] < Pre_Payment_Para.Energy_Step[0][i])) {
                break;
            }
		}
		}
	return ret;
}

/*" ������һ���ݶȵĽ���ֵ�Ͷ�Ӧ�Ľ��ݷ��� "*/
/*" �õ�����һ�����ݵĵ�����ֵ "*/
/*" ������ʱ�ͽ��ݻ����л���ʱ����� "*/
void Find_Step_Curr_Triff_2(void)
    {
    unsigned char i;
	unsigned long tempL,Curr_Use_Energy;
    
    //P = Pre_Payment_Para.Curr_Step_Point;
	
	if( RunStepNum ==0 )
		{
		Curr_Money_S = 0;
		return;
		}

    if( RunStepNum>MAX_STEP )
        RunStepNum = 1;

	if (YEAR_BILL_FLAG)
		{
		Curr_Use_Energy=Pre_Power_Down_Save_Data.Year_Total_Energy;
		}
	else
		{
		Curr_Use_Energy=Pre_Power_Down_Save_Data.Month_Total_Energy;
		}        
    Next_Energy_Step = 99999999l;
    for( i=0;i<RunStepNum;i++ )
        {
        if( Curr_Use_Energy <= (Pre_Payment_Para.Energy_Step[0][i]*10 ))
            {
            Next_Energy_Step = Pre_Payment_Para.Energy_Step[0][i];
            break;
            }
        }
	Curr_Step_Triff = i;
	Curr_Step_Triff_1 = i+1;
	tempL=Pre_Power_Down_Save_Data.Energy_Next_Step;
    if( i==0 )
        Pre_Power_Down_Save_Data.Energy_Next_Step = Pre_Payment_Para.Energy_Step[0][0];
    else if( i==RunStepNum )
        Pre_Power_Down_Save_Data.Energy_Next_Step = 99999999l;
    else
        {
        Pre_Power_Down_Save_Data.Energy_Next_Step = Pre_Payment_Para.Energy_Step[0][i];
        if( Pre_Power_Down_Save_Data.Energy_Next_Step > Pre_Payment_Para.Energy_Step[0][i-1] )
            Pre_Power_Down_Save_Data.Energy_Next_Step -= Pre_Payment_Para.Energy_Step[0][i-1];
        else
            Pre_Power_Down_Save_Data.Energy_Next_Step  = 0;
        }
    Pre_Power_Down_Save_Data.Energy_Next_Step *= 10;
    Next_Energy_Step                          *= 10;
    Curr_Money_S = Pre_Payment_Para.Triff_Step[0][i];
	if (tempL!=Pre_Power_Down_Save_Data.Energy_Next_Step)
		Pay_For_Data_Save();
    }


/*"**********************************************************************************"*/
/*"**********************************************************************************"*/


/*"**********************************************************************************"*/
/*" ʣ���ѱ�����բ��غ��� "*/

/*"**********************************************************************************"*/
/*" ʣ���ѱ�������բ�����ж� "*/
void Remain_Money_Alarm_Judge(void)
{
    unsigned char i;
    signed long Remain_Money_Temp;
    //if( ((Meter_Parameter.MeterMode[1].byte)&0x20)==0 )    /*" Ԥ���ѹ��ܴ� "*/
    //    {
    //    return;
    //    }

	if (IntoPowerDownFlag)
		return;

	/*" ʣ����С�ڵ��ڱ�������1 "*/
    if (MACRO_LOCAL_PAY_FLAG &&  Pre_Payment_Para.Remain_Money_Alarm1_Limit>0 && Pre_Power_Down_Save_Data.Remain_Money <= (signed long)(Pre_Payment_Para.Remain_Money_Alarm1_Limit))  /*"Li_ʣ������ʾ��������>0,��>ʣ����"*/
    {
        REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE = 1;   /*" �������״̬���ñ�����־ "*/

        //Buzzer_Alarm_SWitch_Flag |=0x02;           /*" ������������־ "*/
		//if (!Buzzer_Alarm_Control_Flag.bit.b1)
		//{
		//	Buzzer_Alarm_Control_Flag.bit.b1=1;		/*"Li_Ƿ��Ѳ���һ��������"*/
		//	Buzzer_Alarm_Control.bit.b1=1;			/*"Li_���������������"*/
		//}

        if( FIRST_REMAIN_MONEY_LOW_ALARM1_DEFINE == 0 )  /*" �����¼���¼������־ "*/
        {
            FIRST_REMAIN_MONEY_LOW_ALARM1_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
 
        }
    }
    else
    {
        REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE = 0;
        
        //Buzzer_Alarm_SWitch_Flag &=0xFD;
		//Buzzer_Alarm_Control.bit.b1=0;
		//Buzzer_Alarm_Control_Flag.bit.b1=0;
        
        if( FIRST_REMAIN_MONEY_LOW_ALARM1_DEFINE == 1 )
        {
            FIRST_REMAIN_MONEY_LOW_ALARM1_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
        }
    }
	/*" ʣ����С�ڱ�������2 "*/
    if(MACRO_LOCAL_PAY_FLAG && Pre_Payment_Para.Remain_Money_Alarm2_Limit>0 && Pre_Power_Down_Save_Data.Remain_Money <= (signed long)(Pre_Payment_Para.Remain_Money_Alarm2_Limit) )
    {
        REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE = 1;/*" �������״̬���ñ�����־ "*/
        
        //Buzzer_Alarm_SWitch_Flag |=0x04;/*" ������������־ "*/
		//if (!Buzzer_Alarm_Control_Flag.bit.b2)
		//{
		//	Buzzer_Alarm_Control_Flag.bit.b2=1;
		//	Buzzer_Alarm_Control.bit.b2=1;
		//}
        
        if( !REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE ) /*" ��δ�����忨������� "*/
        {
            if (BUTTON_FREE_LOW_ALARM2_DEFINE) {
                Relay_Alarm_SWitch_Flag[0][0] &= 0xFB;
            } else {
                Relay_Alarm_SWitch_Flag[0][0] |= 0x04;        /*" �����̵�����բ������־ "*/
            }
            if( REMAIN_MONEY_LOW_ALARM2_SWITCH_DEFINE )   /*" ��բ�̵����Ƿ�������բ���� "*/
                Relay_Alarm_SWitch_Flag[1][0] |= 0x04;    /*" ��բ�̵�����բ������־ "*/
            else
                Relay_Alarm_SWitch_Flag[1][0] &= 0xFB;                
        }
        else
        {
            Relay_Alarm_SWitch_Flag[0][0] &= 0xFB;
            Relay_Alarm_SWitch_Flag[1][0] &= 0xFB;
        }

        if( !FIRST_REMAIN_MONEY_LOW_ALARM2_DEFINE )
        {
            FIRST_REMAIN_MONEY_LOW_ALARM2_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_On_Event);
        }
    }
    else
    {
        if( FIRST_REMAIN_MONEY_LOW_ALARM2_DEFINE  )
        {
            FIRST_REMAIN_MONEY_LOW_ALARM2_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_OFF_Event);
        }

        REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE = 0;
        
        //Buzzer_Alarm_SWitch_Flag &=0xFB;
		//Buzzer_Alarm_Control.bit.b2=0;
		//Buzzer_Alarm_Control_Flag.bit.b2=0;
        
        Relay_Alarm_SWitch_Flag[0][0] &= 0xFB;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xFB;
        if( REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE )
        {
            REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
        }

        if (BUTTON_FREE_LOW_ALARM2_DEFINE) {
            BUTTON_FREE_LOW_ALARM2_DEFINE = 0;
        }
    }
	/*" ʣ����С��0 ,�¹淶������ʾ"*/
	//	REMAIN_MONEY_LOW_ZERO_SWITCH_DEFINE = 1;/*" ʣ����С��0 ,�¹淶������ʾ"*/
	if(MACRO_LOCAL_PAY_FLAG &&  Pre_Power_Down_Save_Data.Remain_Money <= 0 )
	{
		if( FIRST_REMAIN_MONEY_LOW_ZERO_DEFINE == 0 )
		{
			FIRST_REMAIN_MONEY_LOW_ZERO_DEFINE = 1;
			Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
					(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_On_Event);
		}
		REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE = 1;
        
		if( (!REMAIN_MONEY_LOW_ZERO_FREE_DEFINE) )
		{
            if (BUTTON_FREE_LOW_ZERO_ALARM_DEFINE) {
                Relay_Alarm_SWitch_Flag[0][0] &= 0xF7;
                //Buzzer_Alarm_SWitch_Flag &=0xF7;
    			//Buzzer_Alarm_Control.bit.b3=0;
    			//Buzzer_Alarm_Control_Flag.bit.b3=0;
            } else {
                Relay_Alarm_SWitch_Flag[0][0] |= 0x08;
                
                //Buzzer_Alarm_SWitch_Flag |= 0x08;
    			//if (!Buzzer_Alarm_Control_Flag.bit.b3)
    			//{
    			//	Buzzer_Alarm_Control_Flag.bit.b3=1;
    			//	Buzzer_Alarm_Control.bit.b3=1;
    			//}
            }
			
			if ( !REMAIN_MONEY_LOW_ZERO_SWITCH_DEFINE )
				Relay_Alarm_SWitch_Flag[1][0] |= 0x08;
			else
				Relay_Alarm_SWitch_Flag[1][0] &= 0xF7;
		}
		else
		{
		    //Buzzer_Alarm_SWitch_Flag &=0xF7;
			//Buzzer_Alarm_Control.bit.b3=0;
			//Buzzer_Alarm_Control_Flag.bit.b3=0;
		        
		    Relay_Alarm_SWitch_Flag[0][0] &= 0xF7;
		    Relay_Alarm_SWitch_Flag[1][0] &= 0xF7;
		}
	}
    else
    {
        if( FIRST_REMAIN_MONEY_LOW_ZERO_DEFINE )
        {
            FIRST_REMAIN_MONEY_LOW_ZERO_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_OFF_Event);
		}
        REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE = 0;
        
        //Buzzer_Alarm_SWitch_Flag &=0xF7;
		//Buzzer_Alarm_Control.bit.b3=0;
		//Buzzer_Alarm_Control_Flag.bit.b3=0;
        
        Relay_Alarm_SWitch_Flag[0][0] &= 0xF7;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xF7;
        if( REMAIN_MONEY_LOW_ZERO_FREE_DEFINE )
        {
            REMAIN_MONEY_LOW_ZERO_FREE_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);            	
        }
        if (BUTTON_FREE_LOW_ZERO_ALARM_DEFINE) {
            BUTTON_FREE_LOW_ZERO_ALARM_DEFINE = 0;
        }
    }
	/*" ʣ����С����Ƿ���� "*/
    Remain_Money_Temp = Pre_Payment_Para.Remain_Money_Tick_Limit;
    Remain_Money_Temp = 0 - Remain_Money_Temp;
    if(MACRO_LOCAL_PAY_FLAG &&  Pre_Power_Down_Save_Data.Remain_Money <= Remain_Money_Temp )
    {
        if( !FIRST_REMAIN_MONEY_LOW_TICK_DEFINE )
        {
            FIRST_REMAIN_MONEY_LOW_TICK_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_On_Event);
		}

		if( !REMAIN_MONEY_OVER_CLUB_DEFINE )
		{
			REMAIN_MONEY_OVER_CLUB_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
		
        REMAIN_MONEY_LOW_TICK_CLUE_DEFINE = 1;
		Relay_Alarm_SWitch_Flag[0][0] |= 0x10;
        Relay_Alarm_SWitch_Flag[1][0] |= 0x10;
        
        //Buzzer_Alarm_SWitch_Flag |=0x10;
		//if (!Buzzer_Alarm_Control_Flag.bit.b4)
		//{
		//	Buzzer_Alarm_Control_Flag.bit.b4=1;
		//	Buzzer_Alarm_Control.bit.b4=1;
		//}        
    }
    else 
    {
        if( FIRST_REMAIN_MONEY_LOW_TICK_DEFINE )
        {
           	FIRST_REMAIN_MONEY_LOW_TICK_DEFINE = 0;
           	Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                     (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_OFF_Event);
		}
        REMAIN_MONEY_LOW_TICK_CLUE_DEFINE = 0;
    }

	if( (!MACRO_LOCAL_PAY_FLAG) ||  Pre_Power_Down_Save_Data.Remain_Money >(signed long)Pre_Payment_Para.Close_Switch_Limit)
	{
		if( REMAIN_MONEY_OVER_CLUB_DEFINE )
		{
			REMAIN_MONEY_OVER_CLUB_DEFINE = 0;
            Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			//for (i=0;i<4;i++)	oprateCode[i]=0xFF;
			//Pay_For_Event_Dot((const unsigned char *)&Far_On_Event);
		}
		Relay_Alarm_SWitch_Flag[0][0] &= 0xEF;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xEF;
        
        //Buzzer_Alarm_SWitch_Flag&=0xEF;
        //Buzzer_Alarm_Control.bit.b4=0;
		//Buzzer_Alarm_Control_Flag.bit.b4=0;
	}
	else
	{
		if( REMAIN_MONEY_OVER_CLUB_DEFINE )
		{
			Relay_Alarm_SWitch_Flag[0][0] |= 0x10;
			Relay_Alarm_SWitch_Flag[1][0] |= 0x10;
			//Buzzer_Alarm_SWitch_Flag |=0x10;
			//if (!Buzzer_Alarm_Control_Flag.bit.b4)
			//{
			//	Buzzer_Alarm_Control_Flag.bit.b4=1;
			//	Buzzer_Alarm_Control.bit.b4=1;
			//}
		}
	}
	
	if (FAR_OPEN_SWITCH_DEFINE)	//FAR
	{
		Relay_Alarm_SWitch_Flag[1][0]|=0x20;
	}
	else
	{
		Relay_Alarm_SWitch_Flag[1][0]&=(~0x20);
	}

	if (FAR_WARN_1D_DEFINE||FAR_WARN_1E_DEFINE)	/*"Ԥ��բ"*/
		{
		Relay_Alarm_SWitch_Flag[1][0]|=0x40;	/*"Ԥ��բ״̬"*/
		if (!SWITCH_FACT_DEFINE) /*"δ��բ��һֱˢ�¿�ʼʱ��"*/
			FarOpenTime=GetNowTime();
		else if (!GetTimeCount(FarOpenTime,Pre_Payment_Para.Far_Close_Delay*60000))	/*"Ԥ��բ��ʱʱ�䵽"*/
			{
			Relay_Alarm_SWitch_Flag[1][0]&=(~0x40);
			if (FAR_WARN_1D_DEFINE && SWITCH_FACT_DEFINE)	/*"ֱ�Ӻ�բ"*/
				SWITCH_ALLOW_CLOSE_DEFINE=1;
			FAR_WARN_1D_DEFINE=0;	/*"Ԥ��բ���"*/
			FAR_WARN_1E_DEFINE=0;
			Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
			 	    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);			
			}
		}
	else
		Relay_Alarm_SWitch_Flag[1][0]&=(~0x40);

    if( Relay_Alarm_SWitch_Flag[1][0] & 0x1C )
		REMAIN_MONEY_OPEN_SWITCH_DEFINE = 1;
    else
		REMAIN_MONEY_OPEN_SWITCH_DEFINE = 0;

	if (FAR_OPEN_ALARM_DEFINE)
	{
        if (BUTTON_FREE_FAR_ALRAM_DEFINE) {
            Relay_Alarm_SWitch_Flag[0][0] &= (~0x20);
        } else {
		    Relay_Alarm_SWitch_Flag[0][0]|=0x20;
        }
	}
	else
	{
		Relay_Alarm_SWitch_Flag[0][0] &= (~0x20);
        if (BUTTON_FREE_FAR_ALRAM_DEFINE) {
            BUTTON_FREE_FAR_ALRAM_DEFINE = 0;
        }
	}
	
}

/*"**********************************************************************************"*/
/*" �忨���ʣ���ѱ�������բ "*/
void Card_Alarm_Switch(void)
{
    if( REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE )
        {
        if( !REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE )
            {
            REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
            }
        Relay_Alarm_SWitch_Flag[0][0] &= 0xFB;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xFB;
        }
    if( REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE )
        {
        if( !REMAIN_MONEY_LOW_ZERO_FREE_DEFINE )
            {
            REMAIN_MONEY_LOW_ZERO_FREE_DEFINE = 1;
            Pay_EE_W(PAY_FOR_USERS_FLAG1_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag1),1,3,
                       (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
            }
        Relay_Alarm_SWitch_Flag[0][0] &= 0xF7;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xF7;
        }
	//if(OverPowerAlarmFlag)
	//	{
	//	if (!Event_Power_Net_Flag.OverPowerAlarm && (Pre_Payment_Data.OverPowerSw_Time<Pre_Payment_Para.OverPower_Time_Limit || Pre_Payment_Para.OverPower_Time_Limit==0))
	//		{
	//		OverPowerAlarmFlag=0;
	//		Relay_Alarm_SWitch_Flag[1][0] &= 0xFE;
	//		}
	//	}
	
	Remain_Money_Alarm_Judge();
	if( Switch_Test_Time ==0 )
		{
		Relay_Control();
		}
	/*"���ڱ��طѿر�,Զ�������բ��,�忨��բ"*/
	if ((!SWITCH_ALLOW_CLOSE_DEFINE)
	&& (!SWITCH_PREPARE_STATE_DEFINE)
	//&& (FAR_CLOSE_SWITCH_DEFINE || METER_IN_FRIEND_DAY_DEFINE)
	&& SWITCH_FACT_DEFINE )
		{
		SWITCH_ALLOW_CLOSE_DEFINE=1;
		//Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		//		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}	
}



//======================================================//
//
//
//
//
/*" ������������̵������ "*/
void Button_Alarm_Switch(void)
{
    if( REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE )
    {
        if( !BUTTON_FREE_LOW_ALARM2_DEFINE ) {
            BUTTON_FREE_LOW_ALARM2_DEFINE = 1;
            //Pay_EE_W(PAY_FOR_USERS_FLAG2_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag2),1,3,
            //           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
        }
        Relay_Alarm_SWitch_Flag[0][0] &= 0xFB;
    }
	
    if( REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE )
    {
        if( !BUTTON_FREE_LOW_ZERO_ALARM_DEFINE )
        {
            BUTTON_FREE_LOW_ZERO_ALARM_DEFINE = 1;
            //Pay_EE_W(PAY_FOR_USERS_FLAG2_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag2),1,3,
            //          (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
        }
        Relay_Alarm_SWitch_Flag[0][0] &= 0xF7;
    }

    if (FAR_OPEN_ALARM_DEFINE) 
    {
        if( !BUTTON_FREE_FAR_ALRAM_DEFINE )
        {
            BUTTON_FREE_FAR_ALRAM_DEFINE = 1;
            //Pay_EE_W(PAY_FOR_USERS_FLAG2_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag2),1,3,
            //          (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
        }
        Relay_Alarm_SWitch_Flag[0][0] &= (~0x20);
    }
    
	Relay_Control();
}
//======================================================//







/*"**********************************************************************************"*/
/*" �����Ӧ��Ԥ�����¼���¼"*/
unsigned char ClearPaymentEventRecord(unsigned long cleareventman,unsigned long cleareventflag)
{
	unsigned char result=0;
	//unsigned int uni=0;

	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		return 0;

	if (clearFlag)
		return 0;

	//clear buy money event
	if((cleareventflag==0xFFFFFFFF)
	||((cleareventflag==0x0333FFFF)&&((NEW645Meter_States.Meter_Status3.intd&0x0200)==0x0200))	//money
	||((cleareventflag==0x0332FFFF)&&((NEW645Meter_States.Meter_Status3.intd&0x0100)==0x0100)))	//engery
	{
		result=0xFF;
		//for(uni=BUY_EVENT_FILE;uni<(BUY_EVENT_FILE+BUY_EVENT_NUMBER);uni++ )
	    //    {
	    //    CheckPowerDown();
	    //    Delete_File(uni);
	    //    FeedWatchdog();
	    //    }
		//Delete_File(BUY_EVENT_FILE);
		//Pay_For_Event_Point.Buy_Event_P=0;
		//Pay_EE_W(BUY_EVENT_P_EE,(unsigned char *)&(Pay_For_Event_Point.Buy_Event_P),1,3,
     	//	(unsigned char *)&(Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);
	    Pay_Event_Record_Clear();
	}
#if 0
	//clear far control switch event
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1D00FFFF))	
	{
		//CheckPowerDown();
		//if(cleareventflag!=0xFFFFFFFF)
		//  ClearEventRecord(cleareventman,cleareventflag);
		result=0xFF;
		for(uni=FAR_CONTROL_EVENT_FILE;uni<(FAR_CONTROL_EVENT_FILE+FAR_CONTROL_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks=0;
		Pay_EE_W(FARSWITCH_TICKS_EE,(unsigned char *)&(Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks),4,3,
       		(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}
	
	//clear far control close event
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1E00FFFF))	
	{
		//CheckPowerDown();
		//if(cleareventflag!=0xFFFFFFFF)
		//  ClearEventRecord(cleareventman,cleareventflag);
		result=0xFF;
		for(uni=FAR_CONTROL_FREE_EVENT_FILE;uni<(FAR_CONTROL_FREE_EVENT_FILE+FAR_CONTROL_FREE_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks=0;
		Pay_EE_W(FARSCLOSE_TIMES_EE,(unsigned char *)&(Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks),4,3,
				 (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}

	/*"��Կ����"*/
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033012FF))	
	{
		result=0xFF;
		for(uni=FAR_KEY_UPDATA_EVENT_FILE;uni<(FAR_KEY_UPDATA_EVENT_FILE+FAR_KEY_UPDATA_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.Far_Key_Updata_Count=0;
		Pay_EE_W(Far_Key_Updata_Count_EE,(unsigned char*)&Pre_Payment_Data.Far_Key_Updata_Count,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033013FF))	
	{
		result=0xFF;
		for(uni=OPCARD_ERROR_EVENT_FILE;uni<(OPCARD_ERROR_EVENT_FILE+OPCARD_ERROR_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.OPCard_Error_Num=0;
		Pay_EE_W(OPCARD_ERROR_NUM_EE,(unsigned char*)&Pre_Payment_Data.OPCard_Error_Num,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}

	/*"���ʱ���"*/
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x03300FFF))	
	{
		result=0xFF;
		for(uni=PROGRAMTRIFF_EVENT_FILE;uni<(PROGRAMTRIFF_EVENT_FILE+PROGRAMTRIFF_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.TriffProgNum=0;
		Pay_EE_W(TriffProgNum_EE,(unsigned char*)&Pre_Payment_Data.TriffProgNum,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}
    /*"���ݱ���"*/
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033010FF))	
	{
		result=0xFF;
		for(uni=PROGRAMSTEP_EVENT_FILE;uni<(PROGRAMSTEP_EVENT_FILE+PROGRAMSTEP_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.StepProgNum=0;
		Pay_EE_W(StepProgNum_EE,(unsigned char*)&Pre_Payment_Data.StepProgNum,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}	
    /*"�˷Ѽ�¼"*/
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033400FF))	
	{
		result=0xFF;
		for(uni=REFUNDMENT_EVENT_FILE;uni<(REFUNDMENT_EVENT_FILE+REFUNDMENT_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.Back_Money_Count=0;
		Pay_EE_W(Back_Money_Count_EE,(unsigned char*)&Pre_Payment_Data.Back_Money_Count,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		FeedWatchdog();
	}	
    /*"���ɿ�������"*/
	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033600FF))	
	{
		result=0xFF;
		for(uni=RELAYERR_EVENT_FILE;uni<(RELAYERR_EVENT_FILE+RELAYERR_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
		Pre_Payment_Data.Relay_Error_Num=0;
		Pay_EE_W(Relay_Error_Num_EE,(unsigned char*)&Pre_Payment_Data.Relay_Error_Num,4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		WRLC256(RELAYERR_AREA_EE,0,29,0,0);
		FeedWatchdog();
	}
	
	/*if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x050802FF))
	{
		result=0xFF;
		for(uni=Month_Bill_EVENT_FILE;uni<(Month_Bill_EVENT_FILE+Month_Bill_EVENT_NUMBER);uni++ )
	        {
	        CheckPowerDown();
	        Delete_File(uni);
	        FeedWatchdog();
	        }
	}	*/
#endif		
	return result;
}

/*"**********************************************************************************"*/
/*"���ʣ������������ѿ����ݺ��¼���¼"*/
void Pay_Data_All_Clear(void)
    {
	//if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
	//	return;

	if (clearFlag)
		return;
    Pay_Data_Clear();
    Pay_Event_Record_Clear();
    }

/*"���ʣ����"*/
void Pay_Money_Clear(void)
{
	unsigned int i;

	//if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
	//	return;
	if (clearFlag)
		return;
	
	for( i=0;i<LENGTH_PRE_POWER_DOWN_SAVE_DATA;i++ )
		*(((unsigned char *)&Pre_Power_Down_Save_Data)+i) = 0;
	Pay_For_Data_Save();
    FeedWatchdog();	
}


/*"**********************************************************************************"*/
/*"���ʣ������������ѿ�����"*/
void Pay_Data_Clear(void)
    {
    unsigned int i;
	
	if (clearFlag)
		return;

    for( i=0;i<LENGTH_PRE_PAYMENT_DATA;i++ )
        *(((unsigned char *)&Pre_Payment_Data)+i) = 0;
    Pay_EE_W(PRE_PAYMENT_DATA_EE,(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,3,
            (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
    
    FeedWatchdog();
    Pre_Payment_Para.Meter_Run_State = 0;
    Pre_Payment_Para.Buy_Count       = 0;
	CREATE_ZERO_DEFINE=0;	//GS
	My_Memcpy(Pre_Payment_Para.Card_Reset_Inf, 0, 8);
	TRIFF_SWITCH_FLAG_DEFINE=1;
	STEP_SWITCH_FLAG_DEFINE=1;
	//FAR_CLOSE_PREPARE_DEFINE=0;
/*"����ʼ��(ʣ�����͸֧��ͬʱΪ0),���ߵ�������,���Ӧ���ں�բ,����״̬��3��BIT4Ϊ��,�̵���ָʾ��Ϊ��"*/
	FAR_OPEN_ALARM_DEFINE = 0;
	FAR_OPEN_SWITCH_DEFINE=0;
	Wai_SWITCH_CLOSE_DEFINE=1;	/*"�����������߳�ʼ��Ǯ��ʱ��״̬��3�ͼ̵���ָʾΪ��բ״̬�������ݵ��״̬ˢ�£��������ñ����ǰ������բ״̬�������󵽹���һֱ������բ״̬�����������״̬��ͳһ������"*/
	FAR_WARN_1D_DEFINE=0;
	FAR_WARN_1E_DEFINE=0;
	SWITCH_ALLOW_CLOSE_DEFINE=1;	/*"�����ص���բ״̬�������Ǻ�բ����״̬"*/

	STATUS_LOCALOPEN_DEFINE=0;
	STATUS_FAROPEN_DEFINE=0;
	RelayErrCheck_DEFINE=0;

	//-----------------------------------//
	Pay_EE_W(METER_RUN_STATE_EE,(unsigned char*)&Pre_Payment_Para.Meter_Run_State,6,0,			//Meter_Run_State,Buy_Count
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	Pay_EE_W(CARD_RESET_INF_EE,(unsigned char*)&Pre_Payment_Para.Card_Reset_Inf[0],8,0,
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,4,0,	//Flag12,13,14,15
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	
	
    //Pay_EE_W(PRE_PAYMENT_PARA_EE,(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,3,
    //        (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	Pre_Duct_Data_Clear();
    }
/*"**********************************************************************************"*/
/*" ��������е��¼���¼ "*/
void Pay_Event_Record_Clear(void)
    {
    CheckPowerDown();
    FeedWatchdog();	
    Delete_File(BUY_EVENT_FILE);
	Pay_For_Event_Point.Buy_Event_P=0;
	Pay_EE_W(BUY_EVENT_P_EE,(unsigned char *)&(Pay_For_Event_Point.Buy_Event_P),1,3,
        (unsigned char *)&(Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);

#if 0		
	Pay_Event_Record_Data_Clear();
	My_Memcpy((unsigned char *)&Pay_For_Event_Point, 0, sizeof(struct _Pay_For_Event_Point));
	Pay_EE_W(BUY_EVENT_P_EE,(unsigned char *)&(Pay_For_Event_Point.Buy_Event_P),sizeof(struct _Pay_For_Event_Point),3,
            (unsigned char *)&(Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);	
	//if(STATUS_RELAYERR_DEFINE)
	//	WRLC256(RELAYERR_AREA_EE,&TempEventData[0],21,0,1);	
	WRLC256(RELAYERR_AREA_EE,0,29,0,0);
    	for( i=PAY_EVENT_FILE_NAME;i<PAY_EVENT_RECORD_END;i++ )
	        {
	        Delete_File(i);
	        FeedWatchdog();
	        }
	for( i=PROGRAMTRIFF_EVENT_FILE;i<(PROGRAMTRIFF_EVENT_FILE+PROGRAMTRIFF_EVENT_NUMBER);i++ )
		{
	        Delete_File(i);
	        FeedWatchdog();
	        }
#endif	
    }

/*"**********************************************************************************"*/
/*" ��������е��¼���¼������� "*/
#if 0
void Pay_Event_Record_Data_Clear(void)
{
	My_Memcpy((unsigned char *)&Pre_Payment_Data.FARCONTROLEVENT, 0, 36);	// len=9*4
	Pay_EE_W(FARCONTROLEVENT_EE,(unsigned char *)&(Pre_Payment_Data.FARCONTROLEVENT),36,3,
                       (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
}
#endif	
/*"**********************************************************************************"*/
int Pre_Duct_Data_Clear(void)
{
	Next_Energy_Step=0;
	return 0;
}

/*"�������ʱ,�µ���ʵʱ����"*/
void Pre_Moneth_Updata(void)
{
    My_Memcpy( (unsigned char *)&Pre_Payment_Data.Bef_Month_Total_Energy,(unsigned char *)&Pre_Power_Down_Save_Data.Month_Total_Energy,4);
	Pay_EE_W(Bef_Month_Total_Energy_EE,(unsigned char *)&(Pre_Payment_Data.Bef_Month_Total_Energy),4,3,
               (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Month_Total_Energy,0,4);
	Pay_For_Data_Save();
}
/*"**********************************************************************************"*/
/*"������ݶȽ���"*/
//time:YYMMDDHHMM
void Pre_Bill(unsigned char *time)
{
	unsigned char P;
	unsigned char i;
	if (YEAR_BILL_FLAG)
	{
		P=Pre_Payment_Data.Year_Bill_Point;
       	My_Memcpy( (unsigned char *)&Pre_Payment_Data.Bef_Year_Total_Energy[P],
            (unsigned char *)&Pre_Power_Down_Save_Data.Year_Total_Energy,4);
        Pay_EE_W(Bef_Year_Total_Energy_EE+P*4,(unsigned char *)&(Pre_Payment_Data.Bef_Year_Total_Energy[P]),4,3,
            (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);

      	My_Memcpy((unsigned char *)&Pre_Payment_Data.Pre_Year_BillDate[P], time, 4);
		Pay_EE_W(PRE_YEAR_BILLDATE_EE+P*4,(unsigned char *)&(Pre_Payment_Data.Pre_Year_BillDate[P]),sizeof(struct  PRE_YEAR_BILLDATE_DEF),3,
	       		 (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);

		Pre_Payment_Data.Year_Bill_Point++;
		if (Pre_Payment_Data.Year_Bill_Point >= 4)
			Pre_Payment_Data.Year_Bill_Point = 0;
		Pay_EE_W(Year_Bill_Point_EE,(unsigned char *)&(Pre_Payment_Data.Year_Bill_Point),1,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Year_Total_Energy,0,4);
		My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Energy_Next_Step,0,4);
	}
	else
	{
		My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Energy_Next_Step,0,4);
		Pre_Moneth_Updata();
	}

	Pay_For_Data_Save();
}




unsigned char is_exist_year_bill_date(void)
{
	unsigned char i;
	
	struct YEAR_BILLDATE_DEF *date;
	for (i = 0; i < 4; i++) {
		date = &Pre_Payment_Para.Year_BillDate[0][i];

        /*" mouth 1 - 12 "*/
        /*" day 1 - 28"*/
        /*" hour 0 - 23"*/
        if ( ((date->Month > 0) && (date->Month <= 0x12))
            && ((date->Day > 0) && (date->Day <= 0x28))
            && (date->Hour <= 0x23)) {
            return 1;
        }
	}
	return 0;
}

//extern void Retort_New(unsigned char,unsigned char*);

/*" QQQ  �½��ݺ�����ݻ����л�ʱ ���н��� "*/
void Bill_for_switch(void)
{
    Pre_Bill(&MainSoftDate.Year);

/*    
	My_Memcpy( (unsigned char *)&Pre_Payment_Data.Bef_Year_Total_Energy,0,4);
	Pay_EE_W(Bef_Year_Total_Energy_EE,(unsigned char *)&(Pre_Payment_Data.Bef_Year_Total_Energy),4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	My_Memcpy((unsigned char *)&Pre_Payment_Data.Pre_Year_BillDate[0], 0, sizeof(struct  PRE_YEAR_BILLDATE_DEF)*4);
	Pay_EE_W(PRE_YEAR_BILLDATE_EE,(unsigned char *)&(Pre_Payment_Data.Pre_Year_BillDate[0]),sizeof(struct  PRE_YEAR_BILLDATE_DEF)*4,3,
			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	Pre_Payment_Data.Year_Bill_Point = 0;
	Pay_EE_W(Year_Bill_Point_EE,(unsigned char *)&(Pre_Payment_Data.Year_Bill_Point),1,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);

	My_Memcpy( (unsigned char *)&Pre_Payment_Data.Bef_Month_Total_Energy,0,4);
	Pay_EE_W(Bef_Month_Total_Energy_EE,(unsigned char *)&(Pre_Payment_Data.Bef_Month_Total_Energy),4,3,
			(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Energy_Next_Step,0,4);
	My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Month_Total_Energy,0,4);    
	Pay_For_Data_Save();*/

}

/*" �½��ݺ�����ݵ��л� "*/
void switch_year_stage_mouth_stage(void)
{
    if (is_exist_year_bill_date()) 
	{
		if (Bill_Date_Change_Switch_DEFINE)//|| (!YEAR_BILL_FLAG)  /*"����130722,����������л�ʱ�����㵱ǰ����õ���"*/
			Bill_for_switch();				/*"�忨�����л�ʱ,��ǰ���������Ч�ͽ��� "*/
        if (YEAR_BILL_FLAG == 0) {
            /*"���½������"*/
            YEAR_BILL_FLAG = 1;
			Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
		 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);   //Li Update 20121225
			Retort_New(0,(unsigned char *)&softdate);	/*"���½������->�½����л�������������¶��õ���ת��ʱ��ͬʱת�浱ǰ����1��12�����յ���"*/
        }
    } 
	else 
	{
        if (YEAR_BILL_FLAG == 1)
		{
            /*"���������½���"*/
            Bill_for_switch();
            YEAR_BILL_FLAG = 0;
			Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
		 			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);   //Li Update 20121225
        }
    }
	Bill_Date_Change_Switch_DEFINE=0;
	Bill_Date_Change_Modify_DEFINE=0;
}

/*" �жϵ�ǰʱ���Ƿ���������� "*/
/*" struct DATEANDTIME_DEF *cur: ���жϵ�ʱ��ָ�� "*/
/*" ��������ղ�����������շ���1�����򷵻�0 "*/
unsigned char is_year_bill_date(struct DATEANDTIME_DEF *cur)
{
    //unsigned char P;
    unsigned char i;
    struct YEAR_BILLDATE_DEF *date;
    
    //P = Pre_Payment_Para.Curr_Step_Point;

    for (i = 0; i < 4; i++) {
        date = &Pre_Payment_Para.Year_BillDate[0][i];
        if (date->Month == cur->Month && date->Day == cur->Day 
            && date->Hour == cur->Hour && cur->Min == 0) {
            return 1;
        }
    }
    return 0;
}


/*"**********************************************************************************"*/
/*" �õ��¼���¼���� "*/
/*" �������¼���¼�Ͷ��¼���¼����ʼ���ݼ�¼ "*/
/*" Point������ "*/
/*" Point1����֯������ݻ����� "*/
unsigned int Get_Event_Data(const unsigned char *Point,unsigned char *Point1)
    {
    unsigned char i,j,k;
    unsigned int Length;
    const struct Event_format * Data_Point;
    
    Data_Point = (const struct Event_format *)Point;
    
    Length = 0;
    for( i=0;;i++ )
        {
        FeedWatchdog();
        j = Data_Point[i].Length&0x00FF;
        for(k=0;k<j;k++)
            {
            Point1[Length] = *(Data_Point[i].Addr+k);
            Length++;
            }
        if( Data_Point[i].Length&0x8000 )
            break;
        }
    return Length;
    }

/*"**********************************************************************************"*/
/*" �õ��¼���¼���� "*/
/*" ���¼���¼������ʱ��õ����� "*/
/*" Point ���� "*/
/*" Point2 ���ݸ�ʽ "*/
/*" Point1 ��֯������ݻ����� "*/
/*" EE3_Addr ���ݵ�EE3��ַ "*/
unsigned int Get_Event_Data_d(const unsigned char *Point,const unsigned char *Point2,
                              unsigned char *Point1,unsigned int EE3_Addr,unsigned char mode)
    {
    unsigned char j,k,l;
    unsigned int Length,i;
    const struct Event_format * Data_Point;
    const struct Event_format_d * Data_Point_d;
    union Long_To_Char Temp[2];
    
    Data_Point   = (const struct Event_format *)Point;
    Data_Point_d = (const struct Event_format_d *)Point2;
    
    Length = 0;
    for( i=0;;i++ )
        {
        FeedWatchdog();
        j = Data_Point[i].Length&0x00FF;
        if( ((Data_Point_d[i].format)&0x01)==0x01 )
            {
/*" ��ʼ��Ч��������Ч������ "*/
            if( mode == 0 )
            	{
                for(k=0;k<j;k++)
                    {
                    Point1[Length] = *(Data_Point[i].Addr+k);
                    Length++;
                    }
            	}
			else
				{
                WRLC256(EE3_Addr+Length,Point1+Length,j,0,1);
                Length+=j;
				}
            }
        else if( ((Data_Point_d[i].format)&0x02)==0x02 )
            {
/*" ��ʼ��Ч��������Ч������ "*/
            if( mode == 0 )
            	{
                for(k=0;k<j;k++)
                    {
                    Point1[Length] = 0x0;	//09.10.31
                    Length++;
                    }
            	}
			else
				{
                for(k=0;k<j;k++)
                    {
                    Point1[Length] = *(Data_Point[i].Addr+k);
                    Length++;
                    }
				}
            }
        else if( Data_Point_d[i].format&0x80==0x80 )
            {
/*" ��ʼ��Ч�ҽ�����Ч�����ݣ���ʾ���������ݣ� "*/
            if(  Data_Point_d[i].format&0x40==0x40 )
                {
/*" ��ʾ��4�ֽڵ��������� "*/
                for(k=0;k<j;)
                    {
                    for( l=0;l<4;l++ )
                        {
                        Temp[0].U_char[l] = *(Data_Point[i].Addr+k);
                        k++;
                        }
                    WRLC256(EE3_Addr+Length,Temp[1].U_char,4,0,1);

                    if( Temp[0].U_long < Temp[1].U_long )
                        Temp[0].U_long +=99999999;
                    Temp[0].U_long -=Temp[1].U_long;

                    for( l=0;l<4;l++ )
                        {
                        Point1[Length] = Temp[0].U_char[l];
                        Length++;
                        }
                    }
                }
            }
		else
		    Length+=j;
        if( Data_Point[i].Length&0x8000 )
            break;
        }
    return Length;
    }

/*"**********************************************************************************"*/
/*" ʱ�������¼���¼ "*/
void Pay_For_Event_Period(const unsigned char * Para_Point ,unsigned char mode )
    {
    unsigned char i;
    unsigned int Length;

    const unsigned char *Data_Point;         /*" �����¼���¼���� "*/
    const unsigned char *Data_Point_Format;  /*" �����¼���¼���ݸ�ʽ�����ָ�� "*/
    unsigned int Head_File_Addr;             /*" �����¼��ļ��׵�ַ "*/
    unsigned int Event_Record_Number;        /*" �����¼���¼���� "*/
    unsigned int EE3_Addr;                   /*" �¼���¼������ַ "*/
    unsigned char Event_Point_Offset;        /*" ˲�㹺���¼�ָ��ƫ���� "*/
    Event_Spec_Deal  Event_Spec_Deal1;


    Data_Point          = (*((const struct Pay_Period_Event_format *)Para_Point)).Data_Point;
    Data_Point_Format   = (*((const struct Pay_Period_Event_format *)Para_Point)).Data_Point_Format;
    Head_File_Addr      = (*((const struct Pay_Period_Event_format *)Para_Point)).Head_File_Addr;
    Event_Record_Number = (*((const struct Pay_Period_Event_format *)Para_Point)).Event_Record_Number;
    EE3_Addr            = (*((const struct Pay_Period_Event_format *)Para_Point)).EE3_Addr;
    Event_Point_Offset  = (*((const struct Pay_Period_Event_format *)Para_Point)).Event_Point_Offset;
    Event_Spec_Deal1    = (*((const struct Pay_Period_Event_format *)Para_Point)).Period_Event_Spec_Deal;

	ClearEvent_EventBegin((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset,Head_File_Addr); /*"���������־���¼���¼ʱ������"*/

    if( Event_Record_Number == 0 )
        return;

    Length = Get_Event_Data_d(Data_Point,Data_Point_Format,Pay_Eeprom_Buffer,EE3_Addr,mode);
    if( Event_Spec_Deal1 != 0 )
        Event_Spec_Deal1(Pay_Eeprom_Buffer);

	if( mode==0 )
        {
/*" �¼���¼��ʼ������ʼ���ݱ������� "*/
        WRLC256(EE3_Addr,Pay_Eeprom_Buffer,Length,0,0);
        }

    i = *((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset);
    if( i>=Event_Record_Number )
        i = 0;
    if( mode==1 )
    	{
	    if( i==0 )
		  	i=Event_Record_Number-1;
		else
		  	i--;
		Head_File_Addr+=i;
		Write_File(Head_File_Addr,0,Length,Pay_Eeprom_Buffer); 
		REC_FLG_DEFINE=1;
    	}

    if( mode==0 )
    	{
        i++;
        if( i>=Event_Record_Number )
            i = 0;
        *((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset) = i;
        Length = PAY_FOR_EVENT_POINT_EE+Event_Point_Offset;
        Pay_EE_W(Length,((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset),1,3,
                         (unsigned char *)&Pay_For_Event_Point,LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);
    	}
    }



/*"**********************************************************************************"*/
/*" ʱ�������¼���¼,ֱ�Ӽ�¼��FLASH "*/
void Pay_For_Event_Dot(const unsigned char * Para_Point )
    {
    unsigned char i;
    unsigned int Length;
//    const struct Pay_Time_Drop_Event_format * a;
    const unsigned char *Data_Point;         /*" ˲�㹺���¼���¼���� "*/
    unsigned int Head_File_Addr;             /*" ˲�㹺���¼��ļ��׵�ַ "*/
    unsigned int Event_Record_Number;        /*" ˲�㹺���¼���¼���� "*/
    unsigned char Event_Point_Offset;        /*" ˲�㹺���¼�ָ��ƫ���� "*/
    Event_Spec_Deal  Event_Spec_Deal1;

//    a = ((const struct Pay_Time_Drop_Event_format *)Para_Point);

    Data_Point          = (*((const struct Pay_Time_Drop_Event_format *)Para_Point)).Data_Point;
    Head_File_Addr      = (*((const struct Pay_Time_Drop_Event_format *)Para_Point)).Head_File_Addr;
    Event_Record_Number = (*((const struct Pay_Time_Drop_Event_format *)Para_Point)).Event_Record_Number;
    Event_Point_Offset  = (*((const struct Pay_Time_Drop_Event_format *)Para_Point)).Event_Point_Offset;
    Event_Spec_Deal1    = (*((const struct Pay_Time_Drop_Event_format *)Para_Point)).Drop_Event_Spec_Deal;

	ClearEvent_EventBegin((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset,Head_File_Addr);	/*"���������־���¼���¼ʱ������"*/

    if( Event_Record_Number == 0 )
        return;

    Length = Get_Event_Data(Data_Point,Pay_Eeprom_Buffer);

    if( Event_Spec_Deal1 != 0 )
        Event_Spec_Deal1(Pay_Eeprom_Buffer);

    i = *((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset);/*"������һ���¼�Ѿ����浽ʲôλ���ˣ������˼���"*/

    if( i>=Event_Record_Number )
        i = 0;

    Head_File_Addr+=i;
    Write_File(Head_File_Addr,0,Length,Pay_Eeprom_Buffer);/*"ÿ���¼���һ���ļ�"*/
    i++;
    if( i>=Event_Record_Number )
        i = 0;
    *((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset) = i;
    Length = PAY_FOR_EVENT_POINT_EE+Event_Point_Offset;

    Pay_EE_W(Length,((unsigned char *)&Pay_For_Event_Point+Event_Point_Offset),1,3,
                     (unsigned char *)&Pay_For_Event_Point,LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);

	REC_FLG_DEFINE=1;
    }
#if 0
/*"**********************************************************************************"*/
#pragma SECTION rom UserROMData
const unsigned char Pay_Init_Para[]=
{
0,0,0,0,                 /*" ������� 0    HEX  "*/
0,0,0,0,                 /*" ������ 0    HEX  "*/
0xB8,0x0B,0x00,0x00,     /*" ʣ������ʾ��������1 (30.00Ԫ)   HEX  "*/
//0xD0,0x07,0x00,0x00,     /*" ʣ������բ��������2 (20.00Ԫ)   HEX  "*/
0x00,0x00,0x00,0x00,     /*" ʣ������բ��������2 (�����Ƽ�����Ϊ0Ԫ)   HEX  "*/
0x10,0x27,0x00,0x00,     /*" ʣ������Ƿ���� (100.00Ԫ)    	HEX  "*/
0xFF,0xE0,0xF5,0x05,     /*" ʣ���Ѷڻ����� (999999.99Ԫ)	HEX  "*/

0x10,0x27,0x00,0x00,     /*" ��һ�׷���1 0.5500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���2 0.6000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���3 0.6500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���4 0.7000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���5 0.7500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���6 0.8000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���7 0.8500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" ��һ�׷���8 0.9000Ԫ    HEX  "*/

0x10,0x27,0x00,0x00,     /*" �ڶ��׷���1 0.5500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���2 0.6000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���3 0.6500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���4 0.7000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���5 0.7500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���6 0.8000Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���7 0.8500Ԫ    HEX  "*/
0x10,0x27,0x00,0x00,     /*" �ڶ��׷���8 0.9000Ԫ    HEX  "*/

1,0,0,0,                 /*" ���� 1  "*/
1,0,0,0,                 /*" CT 1  "*/
1,0,0,0,                 /*" PT 1  "*/
0,0,0,0,0,0,             /*" ϵͳ�� "*/
0,0,0,0,0,0,             /*" �û��� "*/
0,0,0,0,0,0,             /*" ��� "*/
0,                       /*" ���� "*/
0,                       /*" �û����� "*/
0,0,0,0,0,0,0,  /*" �·��ʿ�ʼ����ʱ�� "*/
0,0,0,0,0,0,0,  /*" ���ݶȿ�ʼ����ʱ�� "*/
0,                       /*" �������״̬��00����/01��װ/02���� "*/
2,                       /*" ���С��λ "*/
0,0,0,0,               /*" ������� "*/
0,                       /* �ݶ��� */
0,
0x10,0x27,0x00,0x00,     /* ��һ�׵�1�ݶ�ֵ,100.00 X=1,2,3,4���� */
0x20,0x4E,0x00,0x00,     /* ��һ�׵�2�ݶ�ֵ,200.00 X=1,2,3,4���� */
0x30,0x75,0x00,0x00,     /* ��һ�׵�3�ݶ�ֵ,300.00 X=1,2,3,4���� */
0x40,0x9C,0x00,0x00,     /* ��һ�׵�4�ݶ�ֵ,400.00 X=1,2,3,4���� */
0x50,0xC3,0x00,0x00,     /* ��һ�׵�5�ݶ�ֵ,500.00 X=1,2,3,4���� */
0x60,0xEA,0x00,0x00,     /* ��һ�׵�6�ݶ�ֵ,600.00 X=1,2,3,4���� */
//0x70,0x11,0x01,0x00,     /* ��һ�׵�7�ݶ�ֵ,700.00 X=1,2,3,4���� */
//0x80,0x38,0x01,0x00,     /* ��һ�׵�8�ݶ�ֵ,800.00 X=1,2,3,4���� */

0x10,0x27,0x00,0x00,     /* �ڶ��׵�1�ݶ�ֵ,100.00 X=1,2,3,4���� */
0x20,0x4E,0x00,0x00,     /* �ڶ��׵�2�ݶ�ֵ,200.00 X=1,2,3,4���� */
0x30,0x75,0x00,0x00,     /* �ڶ��׵�3�ݶ�ֵ,300.00 X=1,2,3,4���� */
0x40,0x9C,0x00,0x00,     /* �ڶ��׵�4�ݶ�ֵ,400.00 X=1,2,3,4���� */
0x50,0xC3,0x00,0x00,     /* �ڶ��׵�5�ݶ�ֵ,500.00 X=1,2,3,4���� */
0x60,0xEA,0x00,0x00,     /* �ڶ��׵�6�ݶ�ֵ,600.00 X=1,2,3,4���� */
//0x70,0x11,0x01,0x00,     /* �ڶ��׵�7�ݶ�ֵ,700.00 X=1,2,3,4���� */
//0x80,0x38,0x01,0x00,     /* �ڶ��׵�8�ݶ�ֵ,800.00 X=1,2,3,4���� */


0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)1 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)2 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)3 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)4 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)5 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)6 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)7 ,0.00*/ 
//0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)8 ,0.00*/ 
//0x00,0x00,0x00,0x00,     /* ��һ�׷��ʵ��(�ݶ�)9 ,0.00*/ 


0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)1 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)2 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)3 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)4 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)5 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)6 ,0.00*/ 
0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)7 ,0.00*/ 
//0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)8 ,0.00*/ 
//0x00,0x00,0x00,0x00,     /* �ڶ��׷��ʵ��(�ݶ�)9 ,0.00*/

0x99,0x99,0x99,		   /*"�������"*/	
0x99,0x99,0x99,
0x99,0x99,0x99,
0x99,0x99,0x99,
0x99,0x99,0x99,
0x99,0x99,0x99,
0x99,0x99,0x99,
0x99,0x99,0x99,

0,                       		/*" Ԥ���ѱ���״̬��"*/
0x03,                       	/*" Ԥ����ģʽ��1 "*/
0x00,                       /*" Ԥ����ģʽ��2 "*/
0xC0                   		/*" Ԥ����ģʽ��3 "*/
//0x3E,                    /*" �Ѻ���������ģʽ�� "*/
//0,								/*" ����բ������������"*/
//0,                       	/*" �Զ�����籣���־�� "*/
};
#define LENGTH_PAY_INIT_PARA   sizeof(Pay_Init_Para)
#endif
/*"**********************************************************************************"*/
/*" Ԥ���Ѳ�����һ���ϵ縳��ʼֵ "*/
void Pay_For_Para_Init(void)
    {
    unsigned int i;
    
    //WRLC256(PAY_EEPROM_DEFINE_EE,0,LENGTH_PAY_EEPROM_DEFINE,0,0);

    for( i=0;i<LENGTH_PRE_POWER_DOWN_SAVE_DATA;i++ )
        *(((unsigned char *)&Pre_Power_Down_Save_Data)+i) = 0;
    Pre_Power_Down_Save_Data.Remain_Money = 50000;
	Pay_For_Data_Save();
	Pay_For_Para_Down_Save();

    for( i=0;i<LENGTH_PRE_PAYMENT_DATA;i++ )
        *(((unsigned char *)&Pre_Payment_Data)+i) = 0;
    Pay_EE_W(PRE_PAYMENT_DATA_EE,(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,3,
            (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
	
    for( i=0;i<LENGTH_PRE_PAYMENT_PARA;i++ )
        *(((unsigned char *)&Pre_Payment_Para)+i) = 0;	//Pay_Init_Para[i];
   	Pre_Payment_Para.ID_Ins_Time=30;
	Pre_Payment_Para.Remain_Money_Alarm1_Limit=500;
	Pre_Payment_Para.Remain_Money_Alarm2_Limit=100;
	Pre_Payment_Para.Remain_Money_Tick_Limit=1000;
	Pre_Payment_Para.Remain_Money_Hoard_Limit=99999999;
	Pre_Payment_Para.Close_Switch_Limit=200;
	//Pre_Payment_Para.Far_Open_Delay = 0;
	Pre_Payment_Para.TriffPriceNum=4;	/*"������4"*/
	for (i=0;i<2;i++ )
		{
		Pre_Payment_Para.Triff[i][0]=5000;
		Pre_Payment_Para.Triff[i][1]=4900;
		Pre_Payment_Para.Triff[i][2]=4800;
		Pre_Payment_Para.Triff[i][3]=4700;
		}
	//for ( i=0;i<MAX_STEP;i++ )	/*"�ݶ�ֵ"*/
	//	{
	//	Pre_Payment_Para.Energy_Step[0][i]=10000*(i+1);
	//	Pre_Payment_Para.Energy_Step[1][i]=10000*(i+1);
	//	}
	for ( i=0;i<4;i++ )
		{
		Pre_Payment_Para.Year_BillDate[0][i].Month=0x99;
		Pre_Payment_Para.Year_BillDate[0][i].Day=0x99;
		Pre_Payment_Para.Year_BillDate[0][i].Hour=0x99;		
		Pre_Payment_Para.Year_BillDate[1][i].Month=0x99;
		Pre_Payment_Para.Year_BillDate[1][i].Day=0x99;
		Pre_Payment_Para.Year_BillDate[1][i].Hour=0x99;
		}
	Pre_Payment_Para.C_T=1;
	Pre_Payment_Para.P_T=1;
	Pre_Payment_Para.InfrIdenTime=30;
	Pre_Payment_Para.CurrLimit=30000;		/*"30.000A"*/
	Pre_Payment_Para.CurrLimitProTime=1440;
		
	Pre_Payment_Para.Money_Point=2;
	Pre_Payment_Para.Pay_For_Users_Flag2.intd=0x02;	/*" Ԥ����ģʽ��1 "*/
	Pre_Payment_Para.Pay_For_Users_Flag3.intd=0xC0;	/*" Ԥ����ģʽ��2 "*/
//    Pre_Payment_Para.OverPower_Plus_Limit=200;
//    Pre_Payment_Para.Power_Period=1;
//    Pre_Payment_Para.OverPower_Time_Limit=5;
	TRIFF_SWITCH_FLAG_DEFINE=1;
	Wai_SWITCH_CLOSE_DEFINE=1;	/*"����ʼ�������ñ��ں�բ״̬"*/

	STEP_SWITCH_FLAG_DEFINE=1;
	FAR_CLOSE_RECORD_DEFINE=1;				/*"ʹ����ں�բ״̬�ϵ��ʼ���󣬲��Ǻ�բ��¼"*/
	//Pre_Payment_Para.Curr_Triff_Point=0;
	//Pre_Payment_Para.Curr_Step_Point = 0;
	//Pre_Payment_Para.ID_Ins_Counter =0;
	//Pre_Payment_Para.psw_status = 0;
	Pre_Payment_Para.RelayActTime=400;		// 400ms///king chen modify 130218
	Pre_Payment_Para.RelayActEnergy=100;	// 100=0.1kWh
	Pre_Payment_Para.PassWord_Num=20;
	Pay_EE_W(PRE_PAYMENT_PARA_EE,(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,3,
		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

    for( i=0;i<LENGTH_PAY_FOR_EVENT_POINT;i++ )
        *(((unsigned char *)&Pay_For_Event_Point)+i) = 0;
    Pay_EE_W(PAY_FOR_EVENT_POINT_EE,(unsigned char *)&(Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,3,
            (unsigned char *)&(Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,PAY_FOR_EVENT_POINT_EE);

	WRLC256(RELAYERR_AREA_EE,0,(LENGTH_PAY_EEPROM_DEFINE-LENGTH_PRE_PAYMENT_DATA-LENGTH_PRE_PAYMENT_PARA-LENGTH_PAY_FOR_EVENT_POINT),0,0);
    }
    
/*"**********************************************************************************"*/
/*" Ԥ���Ѳ��������ϵ�� "*/
/*" �����жϿ��ڲ����Ƿ���� "*/
/*" �����һƬ�ڿ������������жϵڶ�Ƭ�ڿ������Ƿ���� "*/
void Pay_For_Para_Read(void)
    {
	ReadBlock(PRE_PAYMENT_DATA_EE,(unsigned char *)(&Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,0);
	if ((Pre_Payment_Data.OPCard_StatusByte>2)||(Pre_Payment_Data.Reserve_User[0]>0))
		{
		ReadBlock(PRE_PAYMENT_DATA_EE,(unsigned char *)(&Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,0);
		if ((Pre_Payment_Data.OPCard_StatusByte>2)||(Pre_Payment_Data.Reserve_User[0]>0))
			{
			ReadBlock(PRE_PAYMENT_DATA_EE,(unsigned char *)(&Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,0);
			}
		}
	
	ReadBlock(PRE_PAYMENT_PARA_EE,(unsigned char *)(&Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,0);
	if ((Pre_Payment_Para.Money_Point!=2)||(Pre_Payment_Para.Base_Money>0))
		{
		ReadBlock(PRE_PAYMENT_PARA_EE,(unsigned char *)(&Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,0);
		if ((Pre_Payment_Para.Money_Point!=2)||(Pre_Payment_Para.Base_Money>0))
			{
			ReadBlock(PRE_PAYMENT_PARA_EE,(unsigned char *)(&Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,0);
			}
		}
	
	ReadBlock(PAY_FOR_EVENT_POINT_EE,(unsigned char *)(&Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,0);
	if ((Pay_For_Event_Point.Remain_Money_Alarm1_Event_P>0)||(Pay_For_Event_Point.Remain_Money_Tick_Event_P>0))
		{
		ReadBlock(PAY_FOR_EVENT_POINT_EE,(unsigned char *)(&Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,0);
		if ((Pay_For_Event_Point.Remain_Money_Alarm1_Event_P>0)||(Pay_For_Event_Point.Remain_Money_Tick_Event_P>0))
			{
			ReadBlock(PAY_FOR_EVENT_POINT_EE,(unsigned char *)(&Pay_For_Event_Point),LENGTH_PAY_FOR_EVENT_POINT,0);
			}
		}

    }

/*" Ԥ�������ݴ��ڿ� "*/
void Pay_For_Data_Save(void)
    {
	This_Month_Data.Energy_Record.crc_cal = CRC((unsigned char*)&This_Month_Data.Energy_Record,
	                               sizeof(struct ENERGY_RECORD) - 2);
	//WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data.Energy_Record,sizeof(struct ENERGY_RECORD),0,0);
    }

/*"**********************************************************************************"*/
/*"����ʱ��Ҫ���������"*/
void Pay_For_Para_Down_Save(void)
{
    WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0); 
}


/*"**********************************************************************************"*/
/*" Ԥ���Ѳ����ڿ�д "*/
/*" EE_Addr����Ҫд��EEPROM��ַ  "*/
/*" * W_Point����Ҫд�����ݵ�RAMָ�� "*/
/*" Data_Length����Ҫд�����ݳ��� "*/
/*" EE_CS����Ҫд���ڿ�λ�ã�BIT0��ӦEE0��BIT1��ӦEE1��BIT2��ӦEE2��BIT3��ӦEE3�� "*/
/*"                          BIT7=1��ʾ��������RAM��ַ "*/
/*" * Struct_Point����������RAM�������ṹ���׵�ַ "*/
/*" Struct_Length���������ڶ�Ӧ�Ľṹ�ĳ��� "*/
unsigned char Pay_EE_W(unsigned int EE_Addr, unsigned char * W_Point,unsigned int Data_Length,
                       unsigned char EE_CS,unsigned char * Struct_Point,unsigned int Struct_Length,
                       unsigned int EE_Struct_Addr)
    {
    unsigned char i,Ctrl,l;
    union Int_To_Char Crc_Cs,Crc_Cs1;
	unsigned char tmp;

	tmp=int2ic;
	int2ic&=0xf8;
//    if( EE_CS&0x80 )
//        {
//        if( No_Ram_EE >1 )
//            No_Ram_EE = 0;
//        WRLC256(EE_Addr,Pay_Eeprom_Buffer,Data_Length,0,1);
//        WRLC256(EE_Struct_Addr+Struct_Length-2,(unsigned char *)&Crc_Cs1.U_int,2,No_Ram_EE,1);
//        Crc_Cs.U_int = CRC( Pay_Eeprom_Buffer,Data_Length );
//        Crc_Cs1.U_char[0]-=Crc_Cs.U_char[0];
//        Crc_Cs1.U_char[1]^=Crc_Cs.U_char[1];
//        Crc_Cs.U_int = CRC( W_Point,Data_Length );
//        Crc_Cs1.U_char[0]+=Crc_Cs.U_char[0];
//        Crc_Cs1.U_char[1]^=Crc_Cs.U_char[1];
//        }
//    else
//        {
        Crc_Cs1.U_int = CRC( Struct_Point,Struct_Length-2 );
        Struct_Point[Struct_Length-2] = Crc_Cs1.U_char[0];
        Struct_Point[Struct_Length-1] = Crc_Cs1.U_char[1];
//        } 
    
//    Ctrl = 0x01;
//    for( i=0;i<4;i++ )
//        {
//        if( Ctrl & EE_CS )
//            {
            WRLC256(EE_Addr,W_Point,Data_Length,0,0);
            WRLC256(EE_Struct_Addr+Struct_Length-2,(unsigned char *)&Crc_Cs1.U_int,2,0,0);
//            }
//        Ctrl<<=1;
//        }
	int2ic|=tmp;

	return 0;
    }
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/

#if 0
/*"**********************************************************************************"*/
/*" ���� ������ʱ��ָ��Ĳ�ֵ "*/
/*" Hear_Point��ͷʱ��ָ�� �꣬�£��գ�ʱ���֣��� "*/
/*" End_Point�� βʱ��ָ�� �꣬�£��գ�ʱ���֣��� "*/
/*" Return_Data_Format�����ص����ݸ�ʽ0���꣬1���£�2���գ�3��ʱ��4���֣�5���� "*/
unsigned long Calculate_Time_Mid(unsigned long In_data,unsigned char Mul,unsigned char Add,unsigned char Dec)
    {
    unsigned long Temp;
    
    In_data *= Mul;
    In_data += CharBCDBIN(Add);
    Temp     = CharBCDBIN(Dec);
    if( In_data > Temp )
        In_data -= Temp;
    else
        In_data = 0;
    return In_data;
    }

unsigned long Calculate_Time(unsigned char * Head_Point,unsigned char * End_Point,unsigned char Return_Data_Format)
    {
    unsigned long Return_Data,Day_Temp1;
    unsigned char i;
    
    i = 0;
    Return_Data = 0;
    Return_Data = Calculate_Time_Mid(Return_Data,1,(*Head_Point),(*End_Point));
    if( i == Return_Data_Format )
        return Return_Data;
    i++;
    Return_Data = Calculate_Time_Mid(Return_Data,12,(*(Head_Point+1)),(*(End_Point+1)));
    if( i == Return_Data_Format )
        return Return_Data;
    i++;
    Return_Data = Calculate_20000101_Day(Head_Point);
    Day_Temp1   = Calculate_20000101_Day(End_Point);
    if(Return_Data>=Day_Temp1)
        Return_Data -= Day_Temp1;
    else
        Return_Data = 0;    
    if( i == Return_Data_Format )
        return Return_Data;    
    i++;
    Return_Data = Calculate_Time_Mid(Return_Data,24,(*(Head_Point+3)),(*(End_Point+3)));
    if( i == Return_Data_Format )
        return Return_Data;
    i++;
    Return_Data = Calculate_Time_Mid(Return_Data,60,(*(Head_Point+4)),(*(End_Point+4)));
    if( i == Return_Data_Format )
        return Return_Data;
    i++;
    Return_Data = Calculate_Time_Mid(Return_Data,60,(*(Head_Point+5)),(*(End_Point+5)));
    return Return_Data;
    }
/*"**********************************************************************************"*/
/*" ���� ���������ڼ����2000��1��1�յ�����"*/
const unsigned char Month_Day[12]={0,31,59,90,120,151,181,212,243,18,49,79};
unsigned long Calculate_20000101_Day(unsigned char * Date_Point)
    {
     unsigned char i,Year_Temp,Month_Temp,Day_Temp;
     unsigned long Day_Num;
    Day_Num=0;
    Year_Temp  = *Date_Point;
    Month_Temp = *(Date_Point+1);
    Day_Temp   = *(Date_Point+2);
    lxrBcd_Hex(1,&Year_Temp);
    lxrBcd_Hex(1,&Month_Temp);
    lxrBcd_Hex(1,&Day_Temp);
    for(i=0;i<Year_Temp;i++)
        {
        if( (i&0x03)==0x00 )
            Day_Num+=366;
        else
            Day_Num+=365;
        }
    if( Month_Temp>9 )
        Day_Num+=255;
    if(	(Year_Temp&0x03)==0x00 && Month_Temp>2)
       	Day_Num++;

    Day_Num+=Month_Day[Month_Temp-1]+Day_Temp-1;
    return Day_Num;
    }

/*"**********************************************************************************"*/
/*" ���ܣ�����ÿ���µ����� "*/
unsigned char dayer_acu(unsigned char month,unsigned char year,unsigned char HEX)
    {
    unsigned char   dayer; 
    lxrBcd_Hex(1,&year);
    switch(month)
        {
        case 0x01:
        case 0x03:
        case 0x05:
        case 0x07:
        case 0x08:
        case 0x10:
        case 0x12:
            if(HEX)             dayer=31;
            else                dayer=0x31;
	    break;
        case 0x02: 
            if( (year&0x03)==0x00 )
                {
                if(HEX)          dayer=29;
                else             dayer=0x29;
                }
            else
                {
                if(HEX)          dayer=28;
                else             dayer=0x28;
                }
            break;
        default:
            {
            if(HEX)              dayer=30;
            else                 dayer=0x30;
            }
        }
    return dayer;
    }
/*"**********************************************************************************"*/
/*"���ܣ�һ���ֽڵ�BCDת��ΪHEX "*/
unsigned char CharBCDBIN(unsigned char byte )
    {
    unsigned char unc;
    unc=((byte&0xF0)>>4)*10+(byte&0x0F);
    return(unc); 
    }
/*"**********************************************************************************"*/
/*"**********************************************************************************"*/
#endif

/*"**********************************************************************************"*/
/*" ���ܣ�bcd ��ת��Ϊhex "*/
/*" number������ת���ĸ��� "*/
/*" *Point1������ת�������ݵ���ڵ�ַ��ת����ɺ�ĳ��ڵ�ַ "*/
void lxrBcd_Hex(unsigned char number,unsigned char *Point1)
    {
    unsigned char c;
    unsigned long hex,back;
    hex=0;
    for(c=0;c<number*2;c++)
        {
        hex=hex<<1;
        back=hex;
        hex=back+(hex<<2);
        hex+=((*(Point1+c/2)&0xf0)>>4);
        *(Point1+c/2)<<=4;
        }
    for(c=0;c<number;c++)
        {
        *(Point1+number-c-1)=hex;
        hex=hex>>8;
        }
    }

void Find_Curr_Money(void)
{
	Find_Step_Curr_Triff_2();
	Curr_Money_T=Pre_Payment_Data.CurrMoneyT;
	Curr_Money = Curr_Money_T+Curr_Money_S;
}

char check_date_is_all_0x99(unsigned char *p)
{
	if((*(p+0)==0x99)&&(*(p+1)==0x99)&&(*(p+2)==0x99)&&(*(p+3)==0x99)&&(*(p+4)==0x99))
		return 1;
	else
		return 0;
}


char SwitchDateIsOk(unsigned char *p)
{ 
      unsigned char n;

      if((*(p+0)==0)&&(*(p+1)==0)&&(*(p+2)==0)&&(*(p+3)==0)&&(*(p+4)==0))
            return OK;

      for(n=0;n<5;n++)
      {
        Co.c.h[n]=*(p+n);
        if(!CheckBCD(*(p+n)))
              return ERR;	
      }

      if(Co.c.h[0]<=0x99 && Co.c.h[1]<=0x12 && Co.c.h[1] && Co.c.h[2] 
      &&(OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))
      &&Co.c.h[3]<=0x23 && Co.c.h[4]<=0x59)
            return OK;
      else 
            return ERR;
}

/*"**********************************************************************************"*/
/*" ����жϷ����л� "*/
/*" Flag:0�ϵ���� "*/
/*"      1ÿ����� "*/
void Run_Triff_Switch(unsigned char Flag)
{
	unsigned char tmp;
    unsigned char i,j;
	unsigned char has;/*" �Ƿ��д��л���"*/

	if( IntoPowerDownFlag )
		return;
	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		return;

	tmp=int2ic;
	int2ic&=0xF8;

    //STEP1_OR_STEP2_DEFINE = 1;
	has = 1;
	j = My_Memcmp(&(Pre_Payment_Para.TriffSwitchDate.Year),0,5);
	if( j==0 )
		{
		has = 0;
		}
	else
		{
		if (check_date_is_all_0x99(&(Pre_Payment_Para.TriffSwitchDate.Year)))
			{
			has= 0;
			}
		}
	if (has)
	{
		TRIFF_SWITCH_FLAG_DEFINE = 0;	//XN
		LCD_TRIFF_FLAG_DEFINE=1;
	}
	else
	{
		if(!TRIFF_SWITCH_FLAG_DEFINE )
        {
       	TRIFF_SWITCH_FLAG_DEFINE = 1;
		Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
		 	 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    	}
		LCD_TRIFF_FLAG_DEFINE=0;
	}

	has = 1;
	j = My_Memcmp(&(Pre_Payment_Para.StepSwitchDate.Year),0,5);
	if( j==0 )
		{
		has = 0;
		}
	else
		{
			if (check_date_is_all_0x99(&(Pre_Payment_Para.StepSwitchDate.Year)))
			{
			has = 0;
			}
		}
	if (has)
	{
		STEP_SWITCH_FLAG_DEFINE = 0;	//XN
		LCD_STEP_FLAG_DEFINE=1;
	}
	else
	{
	    if(!STEP_SWITCH_FLAG_DEFINE)
	       	{
	    	STEP_SWITCH_FLAG_DEFINE = 1;
			Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
				    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	       	}
		LCD_STEP_FLAG_DEFINE=0;
	}

	/*"��ʱ����л�"*/
	j = My_Memcmp(&(softdate.Year),&(Pre_Payment_Para.TriffSwitchDate.Year),5);
	if( j==0 || (j==1) )	//XN
	{
        if(!TRIFF_SWITCH_FLAG_DEFINE )
        {
            if (j==1)	/*"����л�ʱ��С�ڵ�ǰʱ�䣬�ж��л�ʱ��ĺϷ���"*/
            	{
            	if (SwitchDateIsOk(&Pre_Payment_Para.TriffSwitchDate.Year))
            		{
            		LCD_TRIFF_FLAG_DEFINE=0;
					j=99;
            		}
            	}
			if (j<2)
				{
	            TRIFF_SWITCH_FLAG_DEFINE = 1;
			    Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
				 	    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	            //if(Pre_Payment_Para.Curr_Triff_Point == 0 )
				//	    Pre_Payment_Para.Curr_Triff_Point = 1;
				//	else
				//		Pre_Payment_Para.Curr_Triff_Point = 0;
				//    Pay_EE_W(CURR_TRIFF_POINT_EE,&(Pre_Payment_Para.Curr_Triff_Point),1,3,
				//		    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				My_Memcpy((unsigned char *)&Pre_Payment_Para.Triff[0][0],(unsigned char *)&Pre_Payment_Para.Triff[1][0],4*(PRE_MAX_TRIFF));
				Pay_EE_W(TRIFF_EE,(unsigned char *)&Pre_Payment_Para.Triff[0][0],4*(PRE_MAX_TRIFF),3,
				   		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);				
				My_Memcpy(&(Pre_Payment_Para.TriffSwitchDate.Year),0,7);
		    	Pay_EE_W(TRIFFSWITCHDATE_EE,&(Pre_Payment_Para.TriffSwitchDate.Year),7,3,
				    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		    	Pay_For_Event_Dot((const unsigned char *)&Triff_Switch_Event);
			    Pre_Duct_Data_Clear();
				}
	    }
	}
	int2ic|=tmp;
	
	tmp=int2ic;
	int2ic&=0xF8;
	
	/*"�ݶȵ���л�"*/
	j = My_Memcmp(&(softdate.Year),&(Pre_Payment_Para.StepSwitchDate.Year),5);
    //if( j==0 || (j==1 && Flag==0) )
	if (j==0 || (j==1))	//>=
        {
    	if (!STEP_SWITCH_FLAG_DEFINE ) 
            {
            if (j==1)	/*"����л�ʱ��С�ڵ�ǰʱ�䣬�ж��л�ʱ��ĺϷ���"*/
            	{
            	if (SwitchDateIsOk(&Pre_Payment_Para.StepSwitchDate.Year))
            		{
            		LCD_STEP_FLAG_DEFINE=0;
					j=99;
            		}
            	}
			if (j<2)
				{
				STEP_SWITCH_FLAG_DEFINE = 1;
			    Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
					    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	           	//if(Pre_Payment_Para.Curr_Step_Point == 0 )
				//    Pre_Payment_Para.Curr_Step_Point = 1;
				//else
				//	Pre_Payment_Para.Curr_Step_Point = 0;
			   // Pay_EE_W(CURR_STEP_POINT_EE,&(Pre_Payment_Para.Curr_Step_Point),1,3,
				//		    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				for (i=0;i<4;i++)
					{
					if (My_Memcmp(&Pre_Payment_Para.Year_BillDate[0][i].Month,&Pre_Payment_Para.Year_BillDate[1][i].Month,3)!=0)
						{
						Bill_Date_Change_Switch_DEFINE=1;
						break;
						}
					}
				My_Memcpy((unsigned char *)&Pre_Payment_Para.Energy_Step[0][0],(unsigned char *)&Pre_Payment_Para.Energy_Step[1][0],4*(MAX_STEP));
				My_Memcpy((unsigned char *)&Pre_Payment_Para.Triff_Step[0][0],(unsigned char *)&Pre_Payment_Para.Triff_Step[1][0],4*(MAX_STEP+1));
				My_Memcpy((unsigned char *)&Pre_Payment_Para.Year_BillDate[0][0],(unsigned char *)&Pre_Payment_Para.Year_BillDate[1][0],3*4);
				Pay_EE_W(ENERGY_STEP_EE,(unsigned char *)&Pre_Payment_Para.Energy_Step[0][0],4*(MAX_STEP),3,
				   		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				Pay_EE_W(TRIFF_STEP_EE,(unsigned char *)&Pre_Payment_Para.Triff_Step[0][0],4*(MAX_STEP+1),3,
				   		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
				Pay_EE_W(YEAR_BILLDATE_EE,(unsigned char *)&Pre_Payment_Para.Year_BillDate[0][0],3*4,3,
				   		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		    	My_Memcpy(&(Pre_Payment_Para.StepSwitchDate.Year),0,7);
		    	Pay_EE_W(STEPSWITCHDATE_EE,&(Pre_Payment_Para.StepSwitchDate.Year),7,3,
					(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	            switch_year_stage_mouth_stage();
		    	Pay_For_Event_Dot((const unsigned char *)&Step_Switch_Event);
			    Pre_Duct_Data_Clear();
				RunStepNum=get_run_step_num();				
				}
			}
        }
	int2ic|=tmp;
	GetCurrTriffPrice();
	Find_Step_Curr_Triff_2();
	Curr_Money = Curr_Money_T+Curr_Money_S;
}

    


