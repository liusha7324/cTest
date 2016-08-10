/*"***************************************************************"*/
/*"国网方案CPU卡数据结构数据处理                                  "*/
/*"参考文件：智能电能表信息交换安全认证技术规范(IC卡)0724.doc     "*/
/*"刘新润                                                         "*/
/*"日期：2009年7月27日                                            "*/
/*"***************************************************************"*/
#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "Pay_def.h"
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "ICcard.h"
#include "I2C_operation.h"
 #include "multi.h"
#include "Card_File.h"
#include "Card_Data.h"
#include "Measure_Interface.h" 



//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*"Meter_Parameter.WhitchSlotIsNow:当前时区标志 "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:当前时段标志 "*/
/*"Pre_Payment_Para.Curr_Triff_Point:当前费率标志，阶梯下当前阶梯标志 "*/
/*" 0:表示当前运行第一套，1表示当前运行第二套"*/
/*" 
/*" 费率信息文件1、2 "*/
//struct Triff_Data
//	{
//	unsigned long Triff[63];
//	};
//#define LENGTH_TRIFF_DATA  sizeof(struct Triff_Data)
void Deal_Triff_Data(unsigned char * Source_Point,unsigned char Mode)
	{
	unsigned char j,k;
	struct Triff_Data *triff_data;
	unsigned char *Triff_Point;
	
	k = Mode&0x01;	/*"0:当前套,	0x01:备用套"*/
	Mode &=0x80;	/*"0:分时费率,0x80:梯度参数"*/

	triff_data = (struct Triff_Data *)Source_Point;
	if (!Mode)	//modify triff
		{
		Triff_Point = (unsigned char *)&Pre_Payment_Para.Triff[k][0];
		for( j=0;j<(PRE_MAX_TRIFF);j++ )
			{
			Reverse_data((unsigned char *)&(triff_data->Triff[j]),4);
			BcdToHex(4,(unsigned char *)&(triff_data->Triff[j]),Triff_Point+j*4);
			}
		Pay_EE_W(TRIFF_EE+k*(4*PRE_MAX_TRIFF),(unsigned char *)&(Pre_Payment_Para.Triff[k][0]),(PRE_MAX_TRIFF)*4,3,		
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	else		//modify step
		{
		Triff_Point=(unsigned char *)&Pre_Payment_Para.Energy_Step[k][0];
		for(j=0;j<MAX_STEP; j++)			//Li Update 20130104
		{
			Reverse_data((unsigned char *)&(triff_data->Grads_Value[j]),4);
			BcdToHex(4,(unsigned char *)&(triff_data->Grads_Value[j]),Triff_Point+j*4);
		}
		
		Triff_Point=(unsigned char *)&Pre_Payment_Para.Triff_Step[k][0];
		for(j=0;j<MAX_STEP+1; j++)			//Li Update 20130104
		{
			Reverse_data((unsigned char *)&(triff_data->Grads_Price[j]),4);
			BcdToHex(4,(unsigned char *)&(triff_data->Grads_Price[j]),Triff_Point+j*4);
		}

		Triff_Point=(unsigned char *)&Pre_Payment_Para.Year_BillDate[k][0];
		for(j=0;j<4; j++)
		{
			if ( k == 0)
			{/*" 设置当前套时，查看年结算日有无变化"*/
				if (My_Memcmp(&Pre_Payment_Para.Year_BillDate[0][j].Month, (unsigned char *)&(triff_data->Bill_Date[j][0]) ,3)!=0)
				{
					Bill_Date_Change_Switch_DEFINE=1;
				}
			}
			//*(Triff_Point+j)=(unsigned char *)&(Triff_Data->Bill_Date[j]);			/*"卡赋表"*/
			My_Memcpy(Triff_Point+j*3,(unsigned char *)&(triff_data->Bill_Date[j][0]),3);		
		}
		Pay_EE_W(ENERGY_STEP_EE+k*4*(MAX_STEP),(unsigned char *)&(Pre_Payment_Para.Energy_Step[k][0]),MAX_STEP*4,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		Pay_EE_W(TRIFF_STEP_EE+k*4*(MAX_STEP+1),(unsigned char *)&(Pre_Payment_Para.Triff_Step[k][0]),(MAX_STEP+1)*4,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		Pay_EE_W(YEAR_BILLDATE_EE+k*(12),(unsigned char *)&(Pre_Payment_Para.Year_BillDate[k][0]),3*4,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		if (k)	/*"设置备用套梯度参数时,要多设置一个梯度切换时间的参数"*/
		{
			My_Memcpy(&Pre_Payment_Para.StepSwitchDate.Year,(unsigned char *)&(triff_data->Grad_Switch_Date[0]),5);		
			Pay_EE_W(STEPSWITCHDATE_EE,(unsigned char *)&(Pre_Payment_Para.StepSwitchDate.Year),5,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		}
		else
		{
			/*"设置当前套梯度参数时,要判断是执行年梯度还是月梯度"*/
			switch_year_stage_mouth_stage();
			RunStepNum=get_run_step_num();
		}
	}
	//-------------------------------------------------------//
}
//------------------------------------------------------------------
//------------------------------------------------------------------
/*" 钱包文件没有对应的处理函数 "*/

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 参数卡共用数据1 "*/
//struct Para_Table1
//	{
//	unsigned char Meter_ID[6];               /*" 表号 "*/
//	unsigned char Client_ID[6];              /*" 客户编号 "*/
//	unsigned char Card_Kind;                 /*" 电卡类型 "*/
//	};
//#define LENGTH_PARA_TABLE1  sizeof(struct Para_Table1)

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 参数卡共用数据2 "*/
//struct Para_Table2
//	{
//	unsigned char User_Kind;                 /*" 用户类型 "*/
//	unsigned char Para_UpData_Flag;          /*" 参数更新标志位 "*/
//	};
//#define LENGTH_PARA_TABLE2  sizeof(struct Para_Table2)
#pragma SECTION program ROM_PRG2
void Deal_Para_Table2(unsigned char * Source_Point,unsigned char Mode)
	{
	struct Para_Table2 *Para_Table2;

	Para_Table2 = (struct Para_Table2 *)Source_Point;
	if( Para_Updata_Flag&0x80 )
		{
		Pre_Payment_Para.User_Kind = Para_Table2->User_Kind;
		Pay_EE_W(USER_KIND_EE,&Pre_Payment_Para.User_Kind,1,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	}
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 参数卡共用数据3 "*/
//struct Para_Table3
//	{
//	unsigned long Remain_Money_Alarm1_Limit; /*" 报警金额1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" 报警金额2 "*/
//	unsigned char Current_CT[3];             /*" 电流互感器变比 "*/
//	unsigned char Voltage_PT[3];             /*" 电压互感器变比 "*/
//	};
//#define LENGTH_PARA_TABLE3  sizeof(struct Para_Table3)
void Deal_Para_Table3(unsigned char * Source_Point,unsigned char Mode)
	{
	unsigned long Data_Temp;
	struct Para_Table3 *Para_Table3;
  
	Para_Table3 = (struct Para_Table3 *)Source_Point;	
	
	if( Para_Updata_Flag&0x80 )
		{
		Reverse_data((unsigned char *)&(Para_Table3->Remain_Money_Alarm1_Limit),4);
		BcdToHex(4,(unsigned char *)&(Para_Table3->Remain_Money_Alarm1_Limit),(unsigned char *)&Pre_Payment_Para.Remain_Money_Alarm1_Limit);

		Reverse_data((unsigned char *)&(Para_Table3->Remain_Money_Alarm2_Limit),4);
		BcdToHex(4,(unsigned char *)&(Para_Table3->Remain_Money_Alarm2_Limit),(unsigned char *)&Pre_Payment_Para.Remain_Money_Alarm2_Limit);

//		Reverse_data((unsigned char *)&(Para_Table3->Remain_Money_Hoard_Limit),4);
//		BcdToHex(4,(unsigned char *)&(Para_Table3->Remain_Money_Hoard_Limit),(unsigned char *)&Pre_Payment_Para.Remain_Money_Hoard_Limit);

//		Reverse_data((unsigned char *)&(Para_Table3->Remain_Money_Tick_Limit),4);
//		BcdToHex(4,(unsigned char *)&(Para_Table3->Remain_Money_Tick_Limit),(unsigned char *)&Pre_Payment_Para.Remain_Money_Tick_Limit);

		Pay_EE_W(REMAIN_MONEY_ALARM1_LIMIT_EE,(unsigned char *)&Pre_Payment_Para.Remain_Money_Alarm1_Limit,8,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	

		Reverse_data((unsigned char *)&(Para_Table3->Current_CT[0]),3);
		BcdToHex(3,(unsigned char *)&(Para_Table3->Current_CT[0]),(unsigned char *)&Pre_Payment_Para.C_T);
		*(((unsigned char *)&Pre_Payment_Para.C_T)+3) = 0;

		Reverse_data((unsigned char *)&(Para_Table3->Voltage_PT[0]),3);
		BcdToHex(3,(unsigned char *)&(Para_Table3->Voltage_PT[0]),(unsigned char *)&Pre_Payment_Para.P_T);
		*(((unsigned char *)&Pre_Payment_Para.P_T)+3) = 0;

		Pay_EE_W(C_T_EE,(unsigned char *)&Pre_Payment_Para.C_T,8,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	}
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*"Meter_Parameter.WhitchSlotIsNow:当前时区标志 "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:当前时段标志 "*/
/*"Pre_Payment_Para.Curr_Triff_Point:当前费率标志，阶梯下当前阶梯标志 "*/
/*" 0:表示当前运行第一套，1表示当前运行第二套"*/
/*" 
/*" 参数卡共用数据4 "*/
//struct Para_Table4
//	{
//	unsigned char Triff_Switch_Time[5];      /*" 两套分时费率切换时间 "*/
//	};
//#define LENGTH_PARA_TABLE4  sizeof(struct Para_Table4)
void Deal_Para_Table4(unsigned char * Source_Point,unsigned char Mode)
	{
	struct Para_Table4 *Para_Table4;

	Para_Table4 = (struct Para_Table4 *)Source_Point;	


	if( Para_Updata_Flag&0x02 )
		{
		My_Memcpy((unsigned char *)&Pre_Payment_Para.TriffSwitchDate.Year,(unsigned char *)&(Para_Table4->Triff_Switch_Time[0]),5);
		Pay_EE_W(TRIFFSWITCHDATE_EE,&(Pre_Payment_Para.TriffSwitchDate.Year),7,3,
				   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
	}

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 购电卡文件数据结构 "*/
//struct Buy_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" 用户类型 "*/
//	unsigned char Para_UpData_Flag;          /*" 参数更新标志位 "*/
//	unsigned char No_Use0[4];      /*" 保留 "*/
//	unsigned char Triff_Switch_Time[5];      /*" 两套分时费率切换时间 "*/
//	unsigned char No_Use1;                      /*" 保留 "*/
//	unsigned long Remain_Money_Alarm1_Limit; /*" 报警金额1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" 报警金额2 "*/
//	unsigned char Current_CT[3];             /*" 电流互感器变比 "*/
//	unsigned char Voltage_PT[3];             /*" 电压互感器变比 "*/
//	unsigned char Meter_ID[6];               /*" 表号 "*/
//	unsigned char Client_ID[6];              /*" 客户编号 "*/
//	unsigned char Card_Kind;                 /*" 电卡类型 "*/
//	};
//#define LENGTH_BUY_PARA_INF_FILE  sizeof(struct Buy_Para_Inf_File)
void Deal_Buy_Para_Inf_File(unsigned char * Source_Point,unsigned char Mode,unsigned char Buy_Card_Kind)
	{
	unsigned char i;
	struct Buy_Para_Inf_File *Buy_Para_Inf_File;
  
	Buy_Para_Inf_File = (struct Buy_Para_Inf_File *)Source_Point;

	if (Buy_Card_Kind ==GWFAR_USER_CARD_NEW)
		{
		Deal_Para_Table2((unsigned char *)&(Buy_Para_Inf_File->User_Kind),Mode);
		Deal_Para_Table3((unsigned char *)&(Buy_Para_Inf_File->Remain_Money_Alarm1_Limit),Mode);
		}
	//Deal_Para_Table1((unsigned char *)&(Buy_Para_Inf_File->Meter_ID),Mode);
	Deal_Para_Table4((unsigned char *)&(Buy_Para_Inf_File->Triff_Switch_Time),Mode);
	}
#if 0	
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*"Meter_Parameter.WhitchSlotIsNow:当前时区标志 "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:当前时段标志 "*/
/*"Pre_Payment_Para.Curr_Triff_Point:当前费率标志，阶梯下当前阶梯标志 "*/
/*" 0:表示当前运行第一套，1表示当前运行第二套"*/
/*" 
/*" 参数卡共用数据5 "*/
//struct Para_Table5
//	{
//	unsigned long Para_Card_Version;      /*" 现场参数设置卡版本号 "*/
//	};
//#define LENGTH_PARA_TABLE5  sizeof(struct Para_Table5)
void Deal_Para_Table5(unsigned char * Source_Point,unsigned char Mode)
	{
//	struct Para_Table5 *Para_Table5;

//	Para_Table5 = (struct Para_Table5 *)Source_Point;	

//	if( Para_Updata_Flag&0x20 )
//		{
//		My_Memcpy((unsigned char *)&Pre_Payment_Para.Para_Card_Version,(unsigned char *)&(Para_Table5->Para_Card_Version),4);
//		Pay_EE_W(PARA_CARD_VERSION_EE,(unsigned char *)&(Pre_Payment_Para.Para_Card_Version),4,3,
//				   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
//		}
	}
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 参数信息数据,专门给现场参数设置卡用 "*/
//struct Set_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" 用户类型 "*/
//	unsigned char Para_UpData_Flag;          /*" 参数更新标志位 "*/
//	unsigned long Para_Card_Version;      /*" 现场参数设置卡版本号 "*/
//	unsigned char Triff_Switch_Time[5];      /*" 两套分时费率切换时间 "*/
//	unsigned char No_Use1;                      /*" 保留 "*/
//	};
//#define LENGTH_SET_PARA_INF_FILE  sizeof(struct Set_Para_Inf_File)
void Deal_Set_Para_Inf_File(unsigned char * Source_Point,unsigned char Mode)
	{
	unsigned char i;
	struct Set_Para_Inf_File *Set_Para_Inf_File;
  
	Set_Para_Inf_File = (struct Set_Para_Inf_File *)Source_Point;

	Deal_Para_Table2((unsigned char *)&(Set_Para_Inf_File->User_Kind),Mode);
	Deal_Para_Table5((unsigned char *)&(Set_Para_Inf_File->Para_Card_Version),Mode);
	Deal_Para_Table4((unsigned char *)&(Set_Para_Inf_File->Triff_Switch_Time),Mode);
	}
#endif
//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 参数信息数据,专门给参数预制卡用 "*/
/*" 参数预置卡 "*/
//struct Init_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" 用户类型 "*/
//	unsigned char Para_UpData_Flag;          /*" 参数更新标志位 "*/
//	unsigned long Para_Card_Version;      /*" 现场参数设置卡版本号 "*/
//	unsigned char Triff_Switch_Time[5];      /*" 两套分时费率切换时间 "*/
//	unsigned char No_Use1;                      /*" 保留 "*/
//	unsigned long Remain_Money_Alarm1_Limit; /*" 报警金额1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" 报警金额2 "*/
//	unsigned char Current_CT[3];             /*" 电流互感器变比 "*/
//	unsigned char Voltage_PT[3];             /*" 电压互感器变比 "*/
//	};
//#define LENGTH_INIT_PARA_INF_FILE  sizeof(struct Init_Para_Inf_File)

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:函数调用模式，1：写调用，0：读调用 "*/
/*"BIT7 :1：写调用，0：读调用 "*/
/*"BIT0~BIT6 表示更新第几梯度 "*/
/*"Source_Point：写调用模式下，为数据来源。 "*/
/*"读调用模式下，为数据去处 "*/
/*"处理以下数据结构中的数据 "*/
/*"需要使用receive_send_buffer做缓冲 "*/
/*" 
/*" 回写数据,给用户卡，ESAM用 "*/
//struct Run_Inf_Data
//	{	
//	unsigned char User_Kind;					/*" 用户类型 "*/
//	unsigned char Current_CT[3];				/*" 电流互感器变比 "*/
//	unsigned char Voltage_PT[3];				/*" 电压互感器变比 "*/	
//	unsigned char Meter_ID[6];					/*" 表号 "*/
//	unsigned char Client_ID[6];				/*" 客户编号 "*/
//	unsigned long Remain_Money;				/*" 剩余金额 "*/
//	unsigned long Buy_Count;					/*" 购电次数 "*/
//	unsigned long Low_Zero_Money;				/*" 过零金额 "*/
//	unsigned char Password_Info[4];			/*" 密钥信息，包括：状态，方式，条数，版本 "*/
//	unsigned char Unlawful_Card_Count[3];		/*" 非法卡插入次数 "*/
//	unsigned char Return_DT[5];				/*" 返写日期时间 "*/
//	};
//#define LENGTH_RUN_INF_DATA  sizeof(struct Run_Inf_Data)
void Deal_Run_Inf_Data(unsigned char * Source_Point,unsigned char Mode,unsigned long Money,unsigned long cnt)
	{
	struct Run_Inf_Data *Run_Inf_Data;
	unsigned long UL_Temp,UL_Temp2;
	unsigned int Temp1,temp2;
	signed long Remain_Money_Temp;
	unsigned long Money_Nega;

	Run_Inf_Data = (struct Run_Inf_Data *)Source_Point;

	/*"保留"*/
	Run_Inf_Data->User_Kind=0;
	 
	/*"用户编号，表号，用户类型"*/
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,6,&Run_Inf_Data->Client_ID[0]);
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,METER_ID_ESAM,6,&Run_Inf_Data->Meter_ID[0]);
	//Get_File_Data(ESAM,ESAM_PARA_INF_FILE,USER_KIND_ESAM,1,&Run_Inf_Data->User_Kind);
	
//	My_Memcpy(&(Run_Inf_Data->Client_ID[0]),&(Pre_Payment_Para.UserID[0]),6);
//	My_Memcpy(&(Run_Inf_Data->Meter_ID[0]),&(Pre_Payment_Para.MeterID[0]),6);
//	Run_Inf_Data->User_Kind = Pre_Payment_Para.User_Kind;

 	Pre_Get_OverZero_Money();

	if (Mode==0xB1)	/*"购电卡"*/
		{
		Remain_Money_Temp=Pre_Power_Down_Save_Data.Remain_Money+Money;
		if (Remain_Money_Temp<=0)
			{
			Money_Nega = 0-Remain_Money_Temp;
			Remain_Money_Temp=0;
			}
		else
			{
			Money_Nega = 0;
			}
		UL_Temp=cnt;
		}
	else
		{
		Remain_Money_Temp=Remain_Money_Plus;
		UL_Temp=Pre_Payment_Para.Buy_Count;
		Money_Nega = Remain_Money_Nega;
		}
 	/*"剩余电费 "*/
 	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Remain_Money),(unsigned char *)&Remain_Money_Temp,4);

	/*"购电次数 "*/
	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Buy_Count),(unsigned char *)&UL_Temp,4);

 	/*"过零电费 "*/
 	HexToBcd(4,(unsigned char *)&Money_Nega, (unsigned char *)&UL_Temp);
 	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Low_Zero_Money),(unsigned char *)&UL_Temp,4);

	/*"CT "*/
	UL_Temp=0;
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,CURRENT_CT_ESAM,3,(unsigned char *)&UL_Temp);
	My_memcpyRev((unsigned char *)&UL_Temp2,(unsigned char *)&UL_Temp,4);
	UL_Temp2>>=8;
	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Current_CT),(unsigned char *)&UL_Temp2,3);

	/*"PT "*/
	UL_Temp=0;
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,VOLTAGE_PT_BUY_CARD,3,(unsigned char *)&UL_Temp);
	My_memcpyRev((unsigned char *)&UL_Temp2,(unsigned char *)&UL_Temp,4);
	UL_Temp2>>=8;
	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Voltage_PT),(unsigned char *)&UL_Temp2,3);
  
	//    /*" 密钥信息 "*/
	//	Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,0,4,Run_Inf_Data->Password_Info);
	/*"保留"*/
	My_Memcpy((unsigned char *)&(Run_Inf_Data->Password_Info[0]),0,4);

 	/*"非法卡插入次数 "*/
 	Run_Inf_Data->Unlawful_Card_Count[0] = 0;
	temp2 = ( unsigned int )Pre_Payment_Data.Unlawful_Card_Count;
	HexToBcd(2,(unsigned char *)&temp2, (unsigned char *)&Temp1);
 	Run_Inf_Data->Unlawful_Card_Count[2] =(unsigned char )Temp1;
	Temp1>>=8;
	Run_Inf_Data->Unlawful_Card_Count[1] =(unsigned char )Temp1;

	/*"返写日期时间 "*/
 	My_Memcpy((unsigned char *)&(Run_Inf_Data->Return_DT[0]),(unsigned char *)(&softdate),5);
	}

