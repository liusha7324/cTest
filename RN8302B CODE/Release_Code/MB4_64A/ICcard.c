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
union byte_def IC_FLAG;								/*"bit1:1.卡处理完成"*/
char maxSetpNum=0;						/*"最大梯度数"*/
unsigned char display_Remain_Flag=0;		/*"0xF0:显示剩余电费(0x80:固定);0x0F:显示卡相关"*/
//unsigned char display_ICErr_Flag=0;			/*"IC卡错误显示1:显示0:消失"*/
unsigned char buy_money_OK_flag=0;		/*"购电成功时,显示"购电",防止"速"显示"*/
unsigned char Card_Type=0;							/*"卡类型"*/
unsigned long buyBeforMoney=0;					/*"购电前剩余电费修改为无符号型数据"*/
signed long Remain_Money_Temp;			/*"带符号剩余电费(显示用)"*/
unsigned long Remain_Money_Plus=0;			/*"正剩余电费"*/
unsigned long Remain_Money_Nega=0;		/*"过零电费"*/
//unsigned char energyMoeny_flag=0;			/*"0:预付费电量,1:预付费电费"*/
//unsigned long Power_Plus_Number=0;		/*"--脉冲负荷数--"*/
//unsigned long Power_Count_Time=0;  			/*"--符合计算时间--"*/
//unsigned char overpower_plus_flag=0;		/*"--超负荷标志--"*/
unsigned char clearFlag=0;					/*"1:预置卡总清零时不再清除费控数据"*/
unsigned char Card_WR_Buff[512];
//unsigned long oldTriff[4];
//unsigned char currentTriff[4*(MAX_STEP*2+1)+3];
unsigned char oprateCode[4];
union ICcard_Flag1 ICcard_Flag1;
//unsigned char Curr_Err=0;
unsigned char UpPowerSecond=0;			/*"上电时,驱动继电器动作一次"*/
unsigned char Relay_Pro_Act_Time=0;		/*"继电器无动作150分钟后,内置继电器重复动作一次"*/


//unsigned char eventReportTime;
unsigned char Buy_Money_Flag;  	/*"bit0:回写,bit3:保存卡序号,开户卡置开户状态,bit4:设参,bit7:充值"*/
unsigned char Para_Updata_Flag;              /*" 参数更新标志 "*/
unsigned char Para_Updata_Flag_Suc;              /*" 参数更新标志 "*/
unsigned char Meter_Ins_Flag;
union ID CurrReadId;				/*"当前读数据时的ID"*/	
//unsigned char CurrReadMode;		/*"当前读数据时的读模式"*/
unsigned char RunStepNum=0;		/*"实际运行的梯度数"*/

unsigned char R_CARD_ERROR_INFO;				/*"Li_错误信息字"*/
unsigned char RelayErrCheckNum=0;				/*"继电器错误检测次数变量"*/
unsigned char RelayOkCheckNum=0;				/*"继电器正确检测次数变量"*/
unsigned char RelayActStaCheckNum=0;			/*"继电器动作3秒后,刷新状态字3和跳闸指示灯"*/
//unsigned char G_Rec_Disp_Flg=0;					/*"1:有事件记录发生变化时，保存显示内容，使其能在低功耗下显示"*/


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
/*"IC卡主函数"*/
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
            R_ID_Remain_Time = (remain + (NUM_MS_PER_MINUTE - 1)) / NUM_MS_PER_MINUTE;/*"不足1分钟按1分钟处理"*/
        }
    }

    if (Far_InfraredFlag) {
        infrare_valid_time = Pre_Payment_Para.InfrIdenTime * NUM_MS_PER_MINUTE;    /*"红外认证通过后30分钟(用毫秒表示)有效"*/
        now = GetNowTime();
		if(GetTimeCount(Far_Infrared_Auth_Ok_Time, infrare_valid_time) == 0) {
			end_infrared_auth();
        } else {
            remain = infrare_valid_time - (now - Far_Infrared_Auth_Ok_Time);
            R_Infrared_Remain_Time = (remain + (NUM_MS_PER_MINUTE - 1)) / NUM_MS_PER_MINUTE;/*"不足1分钟按1分钟处理"*/
        }
    }

	if( MainSoftDate.Day != Pre_Payment_Para.Far_Day_Follow )	/*"过零点时，清挂起状态(密文认证闭锁)"*/
		{
		Pre_Payment_Para.Far_Day_Follow = MainSoftDate.Day;
		Pay_EE_W(FAR_DAY_FOLLOW_EE,(unsigned char *)&(Pre_Payment_Para.Far_Day_Follow),1,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

		Pre_Payment_Data.HangMeterNum=0;						//Li Update 20130105
		HANG_ERR_DEFINE=0;
		Pay_EE_W(HANGMETER_EE,(unsigned char *)&(Pre_Payment_Data.HangMeterNum),1,3,
				    (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
		
		for(Lev=0;Lev<MAX_PASS_NUM;Lev++)	/*"过零点时，清明文密码闭锁"*/
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
		/*"购电后强制备份,防止购电后,再掉上电表计进入低功耗被第2次复位打断,取出备份区数据的数据,致使电费丢失"*/
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
	NEW645Meter_States.Meter_Status3.bit.MeterType_L=0;		/*"HL:00非预付费,01预付费电量表,10预付费电费表"*/
	NEW645Meter_States.Meter_Status3.bit.MeterType_H=MACRO_LOCAL_PAY_FLAG;

	NEW645Meter_States.Meter_Status3.bit.WhitchTriffIsNow=0;
	NEW645Meter_States.Meter_Status3.bit.WhitchStepIsNow=0;

    if (MACRO_LOCAL_PAY_FLAG)
    {
    	NEW645Meter_States.Meter_Status3.bit.local_open_account=!STATUS_LOCALOPEN_DEFINE;	/*"远程_0:开户,1:未开户"*/
    	NEW645Meter_States.Meter_Status3.bit.far_open_account=!STATUS_FAROPEN_DEFINE;		/*"远程_0:开户,1:未开户"*/
    }
	NEW645Meter_States.Meter_Status3.bit.keep_power_status=METER_IN_FRIEND_DAY_DEFINE;	/*"保电状态"*/	
}

//use of ReadEepromEnergy()	
/*"上电调用一次"*/
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
	SWITCH_PROHIBIT_ACT_DEFINE=1;	/*"上电时刻内置继电器不动作"*/
	Pre_Payment_Data.OPCard_StatusByte=0;
	RelayActStaCheckNum=RELAY_ERR_CHECK_TIME;	/*"上电后重新判 继电器故障 "*/
}

/*"卡显示函数"*/
/*"mode-->Card_Display_Err:		显示错误代码	"*/
/*"				Card_Display_Card:	显示CARD		"*/
/*"				Card_Display_Good:	显示GOOD		"*/
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
						displayCharTimeLen(DISP_CHAR_HOARD,5,0);			/*"Li_电费超囤积门限错误"*/
					displayCharTimeLen(DISP_IC_ERR,5,0);			
				}
				//Li Update 20121212    Buzzer_Pay_Cortrol(30,5,5);			/*"Li_错误时:鸣5  声,开关各150ms"*/
				Buzzer_Pay_Cortrol(25,3,5);			 /*"短鸣为 125ms，短鸣间隔也为 125ms"*/
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
				Buzzer_Pay_Cortrol(125,1,5);						/*"长鸣为 625ms"*/
				break;
		}
}

/*"每分钟调用"*/
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

/*"记录负荷开关误动作"*/
void Relay_Error_Rec(unsigned char mode)
{
	if (!mode)	/*"误动作发生"*/
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
	else		/*"误动作结束"*/
	{
		if (mode==0x99)
			My_Memcpy(&Co.b[510], &Powerdown_Save_Data.date.Year, 6);	/*"上电时补"*/
		else
			My_Memcpy(&Co.b[510], &MainSoftDate.Year, 6);
		mode=1;
		STATUS_RELAYERR_DEFINE=0;
      	EventReportState_Expand(3, 3, 1);
	}
	Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
		   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	
	Pay_For_Event_Period((const unsigned char *)&RelayErr_Event,mode);	/*"电能表停止工作时结束存在的负荷开关误动作记录"*/
}

/*"电能表停止工作时结束存在的负荷开关误动作记录(上电补)"*/
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

/*"如果表内负荷开关实际状态与电表发给负荷开关的命令状态不一致,且持续5s以上"*/
/*"如果外置负荷开关跳闸后有电流,且持续5s以上"*/
void Pay_Relay_Err_Check(void)
{
	unsigned long CurrErrFlag;

	if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)		/*"Li_此处要加一个条件_有远程阀控且有预付费"*/
	{
		if (FLAG_SWITCH_ACT_MODE==0)	/*"内置表"*/
		{
			if (SWITCH_FACT_DEFINE&&((Active_power[0]>0) || (GetRelayPort_Status()==0))			/*"跳闸状态下, 功率≠0W 或者 反馈状态=通"*/ //_fgMeter_Noload==flase 
				|| (!SWITCH_FACT_DEFINE)&&((Active_power[0]==0)&&(GetRelayPort_Status()==1)))	/*"合闸状态下, 反馈状态=断"*/
			{
				RelayErrCheckNum++;
				RelayOkCheckNum=0;
				if(RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)
				{
					if ((!STATUS_RELAYERR_DEFINE)&&(!RelayErrCheck_DEFINE))	/*"动作反转前只记录一次"*/
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
		else	/*"外置继电器"*/
		{
			#if 0	/*"外置继电器合闸也判断故障"*/
			/*"外置继电器 跳闸后检测到有功功率连续2秒 或者 合闸后检测到有功功率为0连续2秒"*/
			if ((SWITCH_FACT_DEFINE && (Active_power[0]>0)) 
			|| ((!SWITCH_FACT_DEFINE) && (Active_power[0]==0)))
			{
				RelayOkCheckNum=0;
				RelayErrCheckNum++;
				if (RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)	/*"在2s内输出第一次检测结果"*/
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
				if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)	/*"有功率就灭，无功率就亮"*/
				{
					if (STATUS_RELAYERR_DEFINE)
						Relay_Error_Rec(1);
					Wai_SWITCH_ERR_DEFINE=0;
				}
			}			
			#endif

			/*"外置继电器断开后有连续2秒电流"*/
			if (SWITCH_FACT_DEFINE)
			{
				if (Active_power[0]>0)	/*"功率≠0W"*/
				{
					RelayErrCheckNum++;
					if (RelayErrCheckNum>=RELAY_ERR_CHECK_TIME)	/*"在5s内输出第一次检测结果"*/
						{
						if ((!STATUS_RELAYERR_DEFINE)&&(!RelayErrCheck_DEFINE))	/*"动作反转前只记录一次"*/
							Relay_Error_Rec(0);
						Wai_SWITCH_ERR_DEFINE=1;
						}
				}
				else
				{
					RelayErrCheckNum=0;
					RelayOkCheckNum++;
					if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)	/*"有功率就灭，无功率就亮"*/
					{
						if (STATUS_RELAYERR_DEFINE)
							Relay_Error_Rec(1);
						Wai_SWITCH_ERR_DEFINE=0;
					}
				}
				if (Wai_SWITCH_CLOSE_DEFINE)	/*"跳闸状态时,清除成功合闸标志"*/
				{
					Wai_SWITCH_CLOSE_DEFINE=0;
					Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
							 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);					
				}
			}
			else
			{
				if (STATUS_RELAYERR_DEFINE)	/*"外置表记录继电器故障后,合闸记结束"*/
					Relay_Error_Rec(1);

				RelayErrCheckNum=0;				
				RelayOkCheckNum++;
				if (RelayOkCheckNum>=RELAY_ERR_CHECK_TIME)
				{
					if ((Active_power[0]>0)&&(!Wai_SWITCH_CLOSE_DEFINE)) /*"合闸状态下检测到功率,才认为合闸成功,该结果保存至继电器跳闸"*/
					{
						Wai_SWITCH_CLOSE_DEFINE=1;
						Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char*)&Pre_Payment_Para.Pay_For_Users_Flag12,1,0, 
								 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);					
					}
					else if (!Wai_SWITCH_CLOSE_DEFINE) /*"合闸成功后不再判断"*/
					{
						Wai_SWITCH_ERR_DEFINE=1; /*"合闸状态下未检测到功率,认为继电器故障,只在状态字1中体现，既不记错误记录也不上报"*/
					}
				}
				if (Wai_SWITCH_CLOSE_DEFINE)
					Wai_SWITCH_ERR_DEFINE=0;
			}	

		}
	}
}

/*"刷新继状字3的BIT4位继电器状态"*/
void Relay_Status_Check(void)
{
	if (RelayActStaCheckNum)
		RelayActStaCheckNum--;
	if (!RelayActStaCheckNum)	/*"继电器动作3秒后,再刷新状态字3和跳闸指示灯"*/
	{
		if (SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE || ((!Wai_SWITCH_CLOSE_DEFINE) && (FLAG_SWITCH_ACT_MODE==1) && (SWITCH_FACT_DEFINE == 0)))	/*"继电器故障 或者 外置表未合闸成功(合闸后未检测到功率)"*/
			NEW645Meter_States.Meter_Status3.bit.Relay_Status=!SWITCH_FACT_DEFINE;
		else
		{
			NEW645Meter_States.Meter_Status3.bit.Relay_Status=SWITCH_FACT_DEFINE;
			SwitchOn_Report();
			SwitchOff_Report();
		}
	}
}

/*"实时刷新提示房子符号和锁标志，低功耗下要显示"*/
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
	if ((Pre_Payment_Data.HangMeterNum>=NUM_ERR_TO_HANG)||flg)	/*"电表锁死、或者密码错误闭锁"*/
		Show_flag.bit.lock=1;
	else
		Show_flag.bit.lock=0;

}
	
/*"闪烁显示预付费相关符号(每秒调用一次)"*/
void Pre_Display_Char_Flash(void)
{
	//union Long_To_Char progman;
	unsigned char Wai_Relay_Err=0;

	Pay_Status_Flag();
	Pay_Relay_Err_Check();
	Relay_Status_Check();

	/*"当电表收到主站跳闸、告警命令时,Bit6置1,否则Bit6置0"*/
	//if ((!METER_IN_FRIEND_DAY_DEFINE)&&( FAR_OPEN_PREPARE_DEFINE || FAR_OPEN_SWITCH_DEFINE ||FAR_WARN_1D_DEFINE ||FAR_WARN_1E_DEFINE))
	//	NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=1;
	//else
	//	NEW645Meter_States.Meter_Status3.bit.SwitchCommandStatus=0;

	/*"剩余金额等于或小于预置的报警阀值时,Bit7置1,电表报警,提示用户购电;否则Bit7置0"*/
	if (REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE 
		|| REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE
		|| FAR_OPEN_ALARM_DEFINE)
		NEW645Meter_States.Meter_Status3.bit.SwitchAlarmStatus=1;
	else
		NEW645Meter_States.Meter_Status3.bit.SwitchAlarmStatus=0;	

	NEW645Meter_States.Meter_Status3.bit.Program_Allow=Show_flag.bit.keystoke;
	NEW645Meter_States.Meter_Status3.bit.Identity_Flg=Far_Identity_Auth_Ok_Flag;

	Find_PassInf_Status();
		
	/*"提示请购电"*/
	NEW645Meter_States.Meter_Status1.bit.Overdraft=0;
	Show_flash_falg.bit.Recharge=0;
	Show_flag.bit.Overdraft=0;
	Show_flash_falg.bit.Overdraft=0;	
	if ((MACRO_FAY_CONTROL_FLAG && FAR_OPEN_ALARM_DEFINE)
	||(MACRO_LOCAL_PAY_FLAG && (REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE||REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE||REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE||REMAIN_MONEY_LOW_TICK_CLUE_DEFINE) && (!buy_money_OK_flag)))
		{
		Show_flash_falg.bit.Recharge=1;			/*"请购电"*/
		if ((Pre_Power_Down_Save_Data.Remain_Money<0) && MACRO_LOCAL_PAY_FLAG)
			{
			NEW645Meter_States.Meter_Status1.bit.Overdraft=1;
			if (REMAIN_MONEY_LOW_TICK_CLUE_DEFINE&&(!METER_IN_FRIEND_DAY_DEFINE))
				{
				Show_flag.bit.Overdraft=1;		/*"达到透支门限"*/
				//Show_flash_falg.bit.Overdraft=0;
				}
			else
				{
				//Show_flag.bit.Overdraft=0;		
				Show_flash_falg.bit.Overdraft=1;	/*"正在透支,未达到透支门限"*/
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

	/*"上电后,继电器驱动"*/
	if (UpPowerSecond<=20)
		{
		UpPowerSecond++;
		if (FLAG_SWITCH_ACT_MODE)	/*"上电后,外置继电器按掉电前状态驱动1次"*/
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
			if (UpPowerSecond>=15)		/*"对于内置继电器,在上电15秒时驱动1次"*/
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

/*"  是否固定显示剩余电费"*/
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

/*"计算过零电费"*/
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
/*"卡处理"*/
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
	Buzzer_Pay_Cortrol(0,0,1);							/*"Li_插卡蜂鸣器报警"*/
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
		cpucard_number[i]=0xFF;						/*"卡序列号清零"*/		//Li Update 20130106
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
		R_CARD_ERROR_INFO=VOLTAGE_LOW_DEFINE;					//Li Update 20121220		  /*"Li_错误信息字(表计电压过低)"*/ 
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
		if (R_CARD_ERROR_INFO==ICCARD_RESET_DEFINE || R_CARD_ERROR_INFO == CARDTYPE_ERROR_DEFINE || R_CARD_ERROR_INFO == UNISSUED_ERROR_DEFINE	/*"反插卡或者卡类型错"*/ 
		|| R_CARD_ERROR_INFO == IDCARD_ERROR_DEFINE ||  R_CARD_ERROR_INFO == EXID_ERROR_DEFINE || R_CARD_ERROR_INFO == CARD_NO_INS_DEFINE	/*"身份认证不通过"*/ 
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
		Pay_For_Event_Dot((const unsigned char *)&OPCardErr_Event);			/*"插卡异常写Flash"*/
		//---------------------------------------------------------//
	}
	else
	{
		Pre_Get_OverZero_Money();
		Pre_Display(Card_Display_Good);
		Pre_Payment_Data.OPCard_StatusByte=0x0001;
	}
	//OutCardInCycshow();		/*"拨卡后回到循显第一屏"*/
	buy_money_OK_flag=0;

	if (clearFlag>10)	/*"插预置卡显示读卡成功后再清零"*/
		{
		memcpy(&progman.U_char[0], &oprateCode[0], 4);
		ClearMeterRecord(progman.U_long);
		Clear_All_New(progman.U_long);
		//clearFlag=0;
		}	
}

/*"卡类型判断"*/
unsigned char Card_Operate(void)
	{
	unsigned char i,Add_CS;
	unsigned char ret=0;
	unsigned char length;

	Far_Identity_Auth_Ok_Flag = 0;
    R_ID_Remain_Time = 0;

	BackLight_Ctrl(IC_CARD_LIGHT_MODE, 60,0,CARD_OPERATE_EVENT);	/*"给卡提供的电压稳定后,点亮背光"*/
	displayReadCard(READ_CARD_IN);		/*"屏幕上显示"读卡中" "*/
	
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

	if (Pre_Payment_Para.Far_Key_StatusByte)	/*"私钥下不允许插预置卡"*/
		{
		if (Card_Type==GWFAR_INIT_CARD)
			{
			R_CARD_ERROR_INFO=CARD_NO_INS_DEFINE;
			return ERR;
			}
		}
	else
		{
		if (Card_Type==GWFAR_USER_CARD)	/*"公钥下不允许插用户卡"*/
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
		case GWFAR_USER_CARD:									/*" 用户卡 "*/
			ret=Buy_Card();
			break;
		//case GWFAR_MOD_PASSWORD_CARD:						/*" 修改密钥卡 "*/
		//case GWFAR_RES_PASSWORD_CARD: 						/*" 恢复密钥卡 "*/
		//	ret=Password_Card();
		//	break;
		//case GWFAR_PARA_SET_CARD:								/*" 参数设置卡 "*/
		//	ret=Triff_Card();
		//	break;
		//case GWFAR_READ_ESAM_CARD:							/*" ESAM数据回抄卡 "*/
		//	ret=Check_Card();
		//	break;
		case GWFAR_INIT_CARD:									/*" 出厂设置卡 "*/
				ret=Set_In_Card();
			break;	
		//case GWFAR_MOD_METERID_CARD:							/*" 表号设置卡 "*/
		//		ret=Modify_MeterID_Card();
		//	break;
		//case GWFAR_ADDD_MONEY_CARD:								/*" 增加电量卡 "*/
		//	ret = Add_Money_Card();
		//	break;
		case GWFAR_RELAY_TEST_CARD:								/*" 继电器测试卡 "*/
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
		default: 													/*"卡类型或状态不对"*/
			R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;				//Li Update 20121220			/*"Li_信息错误字(卡类型错误)"*/
			ret=1;
			break;
		}
	if( ret==OK )
		CardProgrammeEvent();
	return ret;
	}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"位:  更新是否更新标志"*/
/*"Bit0	费率电价当前套 "*/
/*"Bit1	费率电价备用套 "*/
/*"Bit2	梯度参数当前套 "*/
/*"Bit3	梯度参数备用套 "*/
/*"Bit4	保留 "*/
/*"Bit5	保留 "*/
/*"Bit6	保留 "*/
/*"Bit7	其他参数 "*/
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*" 开户卡,购电卡，比较合法性"*/
unsigned char Judge_User_Card_OK(unsigned char Card_Kind,unsigned long card_Buy_Count)
{
	struct Buy_Para_Inf_File *file;	
	
	file=(struct Buy_Para_Inf_File *)&Card_WR_Buff[4];
	Buy_Money_Flag = 0x01;

	/*"购电卡类型错"*/
	if( Card_Kind !=GWFAR_USER_CARD_NEW && Card_Kind !=GWFAR_USER_CARD_BUY && Card_Kind !=GWFAR_USER_CARD_BACK)
	{
		R_CARD_ERROR_INFO=CARDTYPE_ERROR_DEFINE;				//Li Update 20121224					/*"Li_信息错误字(卡类型错误)"*/
	 	return ERR;
	}

	/*" 判断表号"*/
	if( My_Memcmp(&(file->Meter_ID[0]),(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6) )
	{
		R_CARD_ERROR_INFO=METER_NUM_DEFINE;				//Li Update 20121224					/*"Li_信息错误字(表号错误)"*/
		return ERR;
	}

//	if (!STATUS_LOCALOPEN_DEFINE)
//	{
//		if ( Card_Kind ==GWFAR_USER_CARD_BUY)	/*"P265:对于远程开户的电能表，只接受开户卡和补卡操作，不接受购电卡操作"*/
//		{
//			R_CARD_ERROR_INFO=BUYCARD_ERROR_DEFINE;
//			return ERR;
//		}
		//else if ( Card_Kind ==GWFAR_USER_CARD_NEW)	/*"本地未开户&表中购电次数大于 1 时,不认购电卡"*/
		//{
			//if (Pre_Payment_Para.Buy_Count>1)		  /*"大于2后怎么购电"*/
			//	{
			//	R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;
			//	return ERR;
			//	}
		//}		
//	}
	/*"只要表计状态为运行状态，则必须比较用户号"*/
	if (  Pre_Payment_Para.Meter_Run_State==0x03 ) 
	{
		/*"判断客户编号"*/
		if( My_Memcmp(Pre_Payment_Para.UserID,file->Client_ID,6) )		//I_B  B_B	/*"I_*:开户卡步骤,B_*:用户卡步骤"*/
		{
			R_CARD_ERROR_INFO=CLIENT_NUM_DEFINE;				/*"客户编号不一致"*/
			return ERR;
		}
		if( Card_Kind == GWFAR_USER_CARD_BUY )	//B_B
		{
			if( My_Memcmp(Pre_Payment_Para.Card_Reset_Inf, cpucard_number, 8) )
			{
				R_CARD_ERROR_INFO=CARD_SN_DEFINE;			/*"Li_信息错误字(卡类型错误)"*/
			 	return ERR;
			}
		}
	}
	else
	{
		if (Card_Kind==GWFAR_USER_CARD_BUY)	/*"未开户,不认购电卡"*/
		{
			R_CARD_ERROR_INFO=BUYCARD_ERROR_DEFINE;
			return ERR;
		}
		else if ( Card_Kind==GWFAR_USER_CARD_BACK)	/*"未开户,不认补卡"*/
		{
			R_CARD_ERROR_INFO=UPCARD_ERROR_DEFINE;
			return ERR;
		}
	}

	CPU_ESAM_CARD_Control(CPU);
	Read(0,Read_Binary,0x80+USER_CARD_RUN_INF_FILE,0,1);/*" 获取用户卡的运行信息文件 "*/
	CPU_ESAM_CARD_Control(ESAM);	
	/*"购电次数比较"*/
	if ( Card_Kind==GWFAR_USER_CARD_NEW )
	{
		if (card_Buy_Count>1)		//I_C 
		{
			R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;		/*"开户卡中的购电次数是否为0或1"*/
		 	return ERR;				
		}
	}
	//I_D B_C
	//l_flag = My_Memcmp((unsigned char *)&card_Buy_Count,(unsigned char *)&Pre_Payment_Para.Buy_Count,4);	/*"Li_(卡内的)与(表内的)比较"*/
	if(card_Buy_Count == Pre_Payment_Para.Buy_Count)			/*"如果卡内购电次数=表内购电次(内卡中的次数)"*/
	{
		if ( receive_send_buffer[0] != 0x68 )	//I_E B_D		/*"返写为空"*/
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
		if (card_Buy_Count == (Pre_Payment_Para.Buy_Count + 1))	/*"购电次数=表内购电次数+1"*/
		{
			if ( receive_send_buffer[0] == 0x68 )	/*"返写不为空"*/	//I_F
			{
				R_CARD_ERROR_INFO=USER_BACK_WRITE_DEFINE;	/*"用户卡返写信息文件不为空 "*/
				return OK;	//to I_M B_K
			}
			Buy_Money_Flag |= 0x08;	
			//to OK
		}
		else
		{
			R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;		/*"(购电次数错误)"*/ /*"购电次数>表内购电次数+1"*/
		 	return OK;	//to I_M B_K
		}
	}
	else
	{
		//if( Card_Kind!=GWFAR_USER_CARD_BACK)	//I_L
		//{
		Buy_Money_Flag |= 0x08;		/*"保存序列号,置开户状态"*/
		//}
		return OK;	//to I_L B_K
	}
	//--------------------------------------------------------------------------------------------------------------//
	//I_G B_F
	Buy_Money_Flag|=0x90;	/*"允许充值,允许修改参数,返回用户卡,提示成功"*/
	
	return OK;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"判断本次购电的囤积门限"*/

unsigned char Judge_Remain_Money_Over(unsigned long Curr_Buy_Money) 
	{
	signed long Money_Count_T,Money_Count_T1;

	if (Curr_Buy_Money>0x77359400)
		return ERR;

	Money_Count_T =  (signed long)Pre_Power_Down_Save_Data.Remain_Money;
	Money_Count_T+= (signed long)Curr_Buy_Money;
		
	Money_Count_T1 = (signed long)Pre_Payment_Para.Remain_Money_Hoard_Limit;
	if (!Money_Count_T1)
		Money_Count_T1=99999999;	/*"如果囤积金额限值设为 0，在充值时按照999999.99 处理"*/
	if( Money_Count_T>Money_Count_T1 )
		return ERR;

	/*" 剩余电费大于2千万也不允许进表 "*/
	if( Money_Count_T > 0x77359400 )  
		return ERR;
	return OK;
	}

unsigned char Card_Set_Para_to_Meter(unsigned char Buy_Card_Kind)
{
	/*"其它参数"*/
	Deal_Buy_Para_Inf_File(Card_WR_Buff+450+4,0x80,GWFAR_USER_CARD_NEW);
	/*"当前套费率参数"*/
	if ((Buy_Card_Kind==GWFAR_USER_CARD_NEW)&&(Para_Updata_Flag & 0x01))
	    {
		Pre_Payment_Data.TriffProgNum++;
		Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
				(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
		Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"编程费率记录"*/	
		if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x20) 
		{
		   EventReportState_Expand(1, 5, 0);  
		   Save_EventReportTimes(PROGTRIFFPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgTriffPrice_times);
		}
	    Deal_Triff_Data(Card_WR_Buff+4,0x00);
	    }
	/*"备用套费率参数"*/
	if (Para_Updata_Flag & 0x02)
	    {
	    //if (Buy_Card_Kind==GWFAR_USER_CARD_NEW)
	    	{
	    	Pre_Payment_Data.TriffProgNum++;
			Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
					(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
			Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"编程费率记录"*/
			if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x20) 
			{
			   EventReportState_Expand(1, 5, 0);  
			   Save_EventReportTimes(PROGTRIFFPRICE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgTriffPrice_times);
			}
	    	}
	    Deal_Triff_Data(Card_WR_Buff+220+4,0x01);
	    }
	/*"当前梯度参数"*/
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
	/*"备用套梯度参数"*/
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
	if (Para_Updata_Flag & 0x0A)      /*"如果修改了备用套参数(切换时间也会修改)"*/
	    Run_Triff_Switch(0);
	//if (Bill_Date_Change_Modify_DEFINE)
	//	switch_year_stage_mouth_stage();	/*"修改当前年结算日，进行年结算"*/
	if (Para_Updata_Flag)			 /*"若插卡时没有进行参数更新，不记录编程事件记录"*/
		Para_Updata_Flag_Suc=0xFF;
}

/*" 参数信息文件处理 "*/	
/*"Buy_Card_Kind=0x01:更新当前套"*/	
unsigned char Card_Set_Para(unsigned char Buy_Card_Kind)
{
	/*"其它参数信息文件处理 "*/		
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

	/*"当前套费率参数"*/
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
	/*"备用套费率参数"*/
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
	
	/*"当前梯度参数"*/
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
	/*"备用套梯度参数"*/
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
	//if ( Para_Updata_Flag & 0x0A )		/*"如果修改了备用套参数(切换时间也会修改)"*/
	//	Run_Triff_Switch(0);
	//Para_Updata_Flag_Suc=0xFF;


	
	return OK;
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*"开户卡,购电卡"*/
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
	/*" 外部认证  "*/
	if( Cpucard_External_Auth() != OK )		/*Li_外部认证*/
		{
		//R_CARD_ERROR_INFO=EXID_ERROR_DEFINE;
		return ERR;
		}

	/*"读CPU卡中的剩余电费和购电次数 "*/
	if( Remain_Money_Moneybag_Add(USER_CARD_MONEYBAG_FILE,REMAIN_MONEY_CPU_ESAM,(unsigned char *)&Moneybag_Data) != OK )
		return ERR;
	Buy_Card_Kind = file->Card_Kind;
	My_Memcpy(UserID,file->Client_ID,6);			/*"Li_将客户编号复制到UserID里"*/	
	buy_money_OK_flag=0xB0;
					
	/*" 判断卡的合法条件  "*/
	if( Judge_User_Card_OK( Buy_Card_Kind ,Moneybag_Data.Buy_Count) != OK )
		return ERR;
	
	if ( Buy_Money_Flag&0x80 )
	{
		/*" 判断本次购电的囤积门限  "*/
		if( Judge_Remain_Money_Over(Moneybag_Data.Remain_Money) != OK )
		{
			R_CARD_ERROR_INFO=HOARD_AMOUNT_DEFINE;					/*"Li_信息错误字(剩余金额超囤积错误)"*/   //Li Update 20121223
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
		Para_Updata_Flag&=0x0A;	/*"编程记录中的更新标志位按照实际更新的参数进行记录"*/
	if(Buy_Money_Flag&0x10)
		{
		if (Card_Set_Para(Buy_Card_Kind))
			return ERR;
		}
	if (Buy_Money_Flag&0x80)
	{
		/*"ESAM钱包文件更新"*/
		if(Remain_Money_Moneybag_Add(USER_CARD_MONEYBAG_FILE,REMAIN_MONEY_CPU_ESAM,0)!=OK)
			{
			Read_Esam_Moneybag_File((unsigned char *)&Esam_Moneybag_Data);
			if (Esam_Moneybag_Data.Buy_Count!=Moneybag_Data.Buy_Count)
				return ERR;
			R_CARD_ERROR_INFO=GOOD_DEFINE;
			/*"如果ESAM内次数==卡内购电次数，则忽略ESAM充值错误(兼容上次插卡更新了ESAM就提前拨卡的情况)"*/
			}
	}
	/*"回写文件处理"*/
	flg=0x11;
	if (Buy_Money_Flag&0x80)
		flg=0xB1;
	Updata_Esam_Return_File(flg,Moneybag_Data.Remain_Money,Moneybag_Data.Buy_Count);
	if (Cpu_File_Updata(USER_CARD_RUN_INF_FILE,ESAM_RUN_INF_FILE,0,0,LENGTH_RUN_INF_DATA+6)!=OK)
		return ERR;
	
	/*"参数信息文件处理"*/
	if (Buy_Money_Flag&0x10)
	{
		My_memcpyRev(&oprateCode[0], &cpucard_number[4], 4);	/*"操作者代码赋值"*/
		Card_Set_Para_to_Meter(GWFAR_USER_CARD_NEW);
	}

	/*"保存卡序号,新卡置开户状态"*/
	if (Buy_Money_Flag&0x08)
	{
		if (Buy_Card_Kind==GWFAR_USER_CARD_NEW) 
		{
			STATUS_LOCALOPEN_DEFINE=1;
			Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
				   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			/*"插入购电次数为 0 且返写信息文件为空的开户卡,应该更新客户编号"*/
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
		/*" 剩余电费购电次数，上次购电费和累计购电费更新 "*/
		Meter_Money_And_Count_Updata(Moneybag_Data.Remain_Money,Moneybag_Data.Buy_Count );
		/*"购电后强制备份,防止购电后,再掉上电表计进入低功耗被第2次复位打断,取出备份区数据的数据,致使电费丢失"*/
		Check_Energy_main(1);
		Check_Energy_main(1);
		
		buy_money_OK_flag++;
		/*" 新卡保存用户号和变更表计运行状态 "*/
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


	/*"此处增加的程序目的不明确，暂时屏蔽"*/
	//if ( Buy_Money_Flag&0x10 )
	//{
	//	if ( (Para_Updata_Flag & 0x04) && STEP_SWITCH_FLAG_DEFINE )		/*"Li_修改了当前梯度,且已经切换了"*/	
	//	{
	//		Pre_Bill(&MainSoftDate.Year);				/*"Li_设置结算日时,当前月/年度用电量清零"*/	//Li Update 20130219
	//	}
	//}
	
	if (R_CARD_ERROR_INFO!=GOOD_DEFINE)
		return ERR;
	return OK;
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/*"出厂预制卡"*/
unsigned char Set_In_Card(void)
	{
	unsigned char i;
	unsigned char ret=OK;
	unsigned long buy_money;
	unsigned char tempTriffDate[5];
	struct Moneybag_Data Moneybag_Data;
	struct Far_Deal_070103FF_format *data;

	/*"Li_增加密钥类型判断，如果是私钥,返回错误"*/   //Li Update  20130122 
	//if(Pre_Payment_Para.Far_Key_StatusByte)	  /*"Li_如果为正式密钥，返回错误"*/  
	//{
	//	return ERR;
	//}

	/*"钱包文件初始化 "*/
	if( Remain_Money_Moneybag_Init() != OK ) 
		return ERR;

	/*"剩余电费，上次购电费和累计购电费，购电次数初始化 "*/
	if(Read_Esam_Moneybag_File( (unsigned char * )&Moneybag_Data)!=OK)
		return ERR;

	Para_Updata_Flag = Card_WR_Buff[5];
	/*"参数信息文件处理 "*/
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

	//if ( Para_Updata_Flag & 0x03 )	/*"预置卡不能记"*/
	//{
	//	Pre_Payment_Data.TriffProgNum++;
	//	Pay_EE_W(TriffProgNum_EE,(unsigned char *)&(Pre_Payment_Data.TriffProgNum),4,3,
	//			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
	//	Pay_For_Event_Dot((const unsigned char *)&ProgramTriff_Event);	/*"编程费率记录"*/
	//}
	//if ( Para_Updata_Flag & 0x0C )
	//{
	//	Pre_Payment_Data.StepProgNum++;
	//	Pay_EE_W(StepProgNum_EE,(unsigned char *)&(Pre_Payment_Data.StepProgNum),4,3,
	//			(unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);	
	//	Pay_For_Event_Dot((const unsigned char *)&ProgramStep_Event);	/*"梯度编程记录"*/
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


	/*" 运行信息文件 "*/
	if( Updata_Esam_Return_File(0x11,0,0) != OK )
		ret=ERR;

	clearFlag=12;	/*"标志大于10,插预置卡总清零时不显示clear"*/

/*"初始化成功后，如果剩余电费和透支金额限额都为0电表跳闸，否则立即自动合闸"*/
	if( REMAIN_MONEY_OVER_CLUB_DEFINE )
	{
		REMAIN_MONEY_OVER_CLUB_DEFINE = 0;
		Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		Relay_Alarm_SWitch_Flag[0][0] &= 0xEF;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xEF;		
	}
	Remain_Money_Alarm_Judge();	/*"将要跳闸的标志都置上"*/

	return ret;
	}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/*"继电器测试卡"*/
unsigned char Relay_TEST_Card(void)
	{	
	Relay_Deal(1);
	
	//Pre_Payment_Para.Far_Key_StatusByte=0;
	//Pay_EE_W(FAR_KEY_STATUSBYTE_EE,(unsigned char *)&(Pre_Payment_Data.Far_Key_StatusByte),4,3,
	//		   (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);

	return OK;
	}
/*"卡拨出处理"*/
void Card_pull_out(void)
{
	IC_FLAG.byte=0;
	buy_money_OK_flag=0;
	Card_Type=0;
}


/*"将原数据前后倒置地复制到目标数据"*/
void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len)
	{	
	unsigned char i;	

	for(i=0;i<len;i++)
		*(to+i)=*(from+len-1-i);
	}

/*"将数据前后倒置"*/
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



/*"购电事件临时数据赋值"*/
void buy_money_event(unsigned char *p)
{
	;
}

/*"远程控制事件临时数据赋值"*/
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

/*"合闸控制事件临时数据赋值"*/
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
/*"是否具有费控控制功能"*/
int Get_Pay_Flag(void)
{
	if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)		/*"费控表"*/
		return 0;

	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	return -1;
}

/*"是否具有远程控制功能(是否带ESAM)"*/
//int Get_FarControl_Flag(void)
//{
	//if (MACRO_FAY_CONTROL_FLAG)		/*"远程控制"*/
//		return 0;

	//Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	//return -1;
//}

/*"HL:00非预付费,01预付费电量表,10预付费电费表"*/
/*"是否为本地费控表"*/
int Get_Payment_Flag(void)
{
	if (MACRO_LOCAL_PAY_FLAG)	/*"本地费控表"*/
		return OK;
	
	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;		/*"非本地费控表,不允许抄读金额数据"*/
	return -1;
}

/*"是否为预付电费表"*/
int Get_Money_Flag(void)
{
	//if ((NEW645Meter_States.Meter_Status3.intd&0x0200)==0x0200)		/*"预付电费"*/
	if (Get_Payment_Flag()!=OK)	/*"是否为本地费控表"*/
		return -1;
	
	return OK;
}

/*"  	是否为预付电量表"*/
/*
int Get_Energy_Flag(void)
{
	if ((NEW645Meter_States.Meter_Status3.intd&0x0100)==0x0100)		预付电量
		return 0;
	
	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	return -1;
}
*/

int Get_cur_which_step(void)
{
	if (Get_Payment_Flag()!=OK)	/*"是否为本地费控表"*/
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


/*"取正的剩余电费"*/
int Get_Plus_Money(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=OK)	/*"是否为本地费控表"*/
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

/*"取透支电费"*/
int Get_Nega_Money(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=OK)	/*"是否为本地费控表"*/
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

/*"  	取剩余电费"*/
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

/*"取剩余电量"*/
/*
int Get_Remain_Energy(void)
{
	int ret=0;
	
	Pre_Get_OverZero_Money();
	ret=Get_Energy_Flag();

	return ret;
}
*/

/*"插卡状态字在读取后置未知"*/
int Get_OPCard_StatusByte(void)
{
	if (Get_Payment_Flag()!=OK)	/*"是否为本地费控表"*/
		return -1;
	Readdata_buff[0]=Pre_Payment_Data.OPCard_StatusByte;
 	Pre_Payment_Data.OPCard_StatusByte=0;
	return OK;
}

/*"取当前月电量"*/
int Get_Month_Energy(void)
{
	if (Get_Pay_Flag()!=OK)	/*"是否为本地费控表"*/
		return -1;
	
	//if (YEAR_BILL_FLAG)
	//	My_Memcpy(Readdata_buff,0,4);
	//else
	//	My_Memcpy(Readdata_buff,(unsigned char *)&Pre_Power_Down_Save_Data.Month_Total_Energy,4);
		
	return OK;
}

/*"取当前年电量"*/
int Get_Year_Energy(void)
{
	if (Get_Pay_Flag()!=OK)	/*"是否为本地费控表"*/
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

/*"  	设CT变比"*/
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

/*"  	设PT变比"*/
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

/*"  	设费率电价"*/
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

/*"取当前费率尖峰平谷电价(四川,显示时用)"*/
int Get_Current_Triff(void)
{
	unsigned char Curr_Period_Dec=0; /*"显示正在用电时段的尖峰平谷电价"*/
	
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
/*"设费率电价"*/
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

/*"  	设梯度电价"*/
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
/*"设年结算日"*/
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

/*"  	设梯度数"*/
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

/*"  	设梯度数"*/
int  Set_Step_Num(void)
{
	int ret=0;

	if (Get_Payment_Flag()!=0)
		return -1;

	if (*Co.c.addr5>MAX_STEP)
		return -1;
	
	return ret;
}

/*"设密钥条数"*/
int Set_PassNumber(void)
{
	if (*Co.c.addr5>0x20)	//hex	//max 32 
		return -1;
	return 0;
}

/*"取客户编号"*/
int Get_Pre_UserD(void)
{
	//if (Get_Payment_Flag()!=0)
	//	return -1;	
	My_Memcpy(Readdata_buff,0,6);
	My_memcpyRev(Readdata_buff,(unsigned char*)&Pre_Payment_Para.UserID[0],6);
	return 0;
}

/*"  	设客户编号"*/
int Set_Pre_UserD(void)
{
	//if (Get_Payment_Flag()!=0)
	//	return -1;
	if (MACRO_LOCAL_PAY_FLAG)	/*"本地费控电能表客户编号只允许开户时修改，不支持远程修改"*/
		return -1;
	My_Memcpy(Readdata_buff,Co.c.addr5,6);
	My_memcpyRev((unsigned char *)&Pre_Payment_Para.UserID[0],Readdata_buff,6);
	Pay_EE_W(USERID_EE,(unsigned char*)&Pre_Payment_Para.UserID[0],6,0,
			 (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	
	return 0;
}

/*"  	取表号"*/
int Get_Meter_ID(void)
{
	My_Memcpy(Readdata_buff,0,6);
	My_memcpyRev(Readdata_buff,(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
	return 0;
}

/*"  	设表号"*/
int Set_Meter_ID(void)
{
	/*"只能在公钥状态下设置表号"*/
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

/*"设置分时电价切换时间、梯度参数切换时间"*/
int Set_PaySwitchDate(void)
{ 
	if (Get_Payment_Flag()!=0)
		return -1;

      return Set_TriffSwitchDate();
}

/*"外置继电器脉冲方式跳闸维持时间"*/
int Set_Ne_RelayActTime(void)
{
	 unsigned int tmp;

	tmp=*((unsigned int *)Co.c.addr5);
	//if (tmp<0x100)
	//	return -1;	 
	 //if (tmp%0x100!=0)
	 //	return -1;
	if (tmp<0x05)	/*"不能小于5毫秒"*/
		return -1;
	//if ((tmp%0x05)!=0)
	// 	return -1;
	
	return 0;
}

/*"红外认证有效时间"*/
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

/*"明文2级、4级密码"*/
int Set_PassWord(void)
{ 
	unsigned char tmp;

	tmp=*((unsigned char *)Co.c.addr5);
	tmp+=1;	/*"04000C03对应2级密码，04000C05对应4级密码"*/
	if (tmp!=cx[3].idt.d[0])
		return -1;
	
	return 0;
}


/*"退费功能"*/
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
		FLAG_SWITCH_ACT_MODE=0;	//ne		/*"Li_内置短接，低有效"*/

//		FLAG_SWITCH_ACT_MODE=0;	//ne		/*"Li_内置短接，低有效"*/
}

/*"IC卡修改参数编程记录"*/
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
/*" 判断文件数据结构的帧头帧尾和效验和是否合法 "*/
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
/*" 剩余电费购电次数，上次购电费和累计购电费更新 "*/
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

	if (SWITCH_FACT_DEFINE && (FAR_WARN_1D_DEFINE||FAR_WARN_1E_DEFINE))	/*"预跳闸延时恢复过程中,插卡购电直接合闸，远程购电立即合闸允许或者直接合闸"*/
		{
		FarOpenTime=GetNowTime()+Pre_Payment_Para.Far_Close_Delay*60000;	/*"立即结束预跳闸"*/
		if (!Far_Identity_Auth_Ok_Flag)
			SWITCH_ALLOW_CLOSE_DEFINE=1;	/*"插卡购电直接合闸"*/
		}	
	}

#if 0
/*" 退费处理 "*/
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

        /*" 更新ESAM中的钱包文件 "*/
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
       /*" 更新电表中的剩余金额 "*/
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
/*" 处理回写文件 "*/
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
/*"计算累加效验和 "*/
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
	//if(Pre_Power_Down_Save_Data.Remain_Money>=0)					/*"正常状态"*/
	//{
	//	Co.b[0] = 0;
	//	My_Memcpy((unsigned char *)&Co.b[1],(unsigned char *)&Remain_Money_Plus,4);
	//}
	//else					/*"透支金额"*/
	//{
	//	Co.b[0] = 0x01;
	//	My_Memcpy((unsigned char *)&Co.b[1],(unsigned char *)&Remain_Money_Nega,4);		
	//}
	Pay_For_Event_Dot((const unsigned char *)&E_Burse_Event);	/*"编程费率记录"*/	//Li Update 20130107 
}



