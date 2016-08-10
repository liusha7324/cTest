/*"***************************************************************"*/
/*"��������CPU�����ݽṹ���ݴ���                                  "*/
/*"�ο��ļ������ܵ��ܱ���Ϣ������ȫ��֤�����淶(IC��)0724.doc     "*/
/*"������                                                         "*/
/*"���ڣ�2009��7��27��                                            "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*"Meter_Parameter.WhitchSlotIsNow:��ǰʱ����־ "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:��ǰʱ�α�־ "*/
/*"Pre_Payment_Para.Curr_Triff_Point:��ǰ���ʱ�־�������µ�ǰ���ݱ�־ "*/
/*" 0:��ʾ��ǰ���е�һ�ף�1��ʾ��ǰ���еڶ���"*/
/*" 
/*" ������Ϣ�ļ�1��2 "*/
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
	
	k = Mode&0x01;	/*"0:��ǰ��,	0x01:������"*/
	Mode &=0x80;	/*"0:��ʱ����,0x80:�ݶȲ���"*/

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
			{/*" ���õ�ǰ��ʱ���鿴����������ޱ仯"*/
				if (My_Memcmp(&Pre_Payment_Para.Year_BillDate[0][j].Month, (unsigned char *)&(triff_data->Bill_Date[j][0]) ,3)!=0)
				{
					Bill_Date_Change_Switch_DEFINE=1;
				}
			}
			//*(Triff_Point+j)=(unsigned char *)&(Triff_Data->Bill_Date[j]);			/*"������"*/
			My_Memcpy(Triff_Point+j*3,(unsigned char *)&(triff_data->Bill_Date[j][0]),3);		
		}
		Pay_EE_W(ENERGY_STEP_EE+k*4*(MAX_STEP),(unsigned char *)&(Pre_Payment_Para.Energy_Step[k][0]),MAX_STEP*4,3,
				(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		Pay_EE_W(TRIFF_STEP_EE+k*4*(MAX_STEP+1),(unsigned char *)&(Pre_Payment_Para.Triff_Step[k][0]),(MAX_STEP+1)*4,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		Pay_EE_W(YEAR_BILLDATE_EE+k*(12),(unsigned char *)&(Pre_Payment_Para.Year_BillDate[k][0]),3*4,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		if (k)	/*"���ñ������ݶȲ���ʱ,Ҫ������һ���ݶ��л�ʱ��Ĳ���"*/
		{
			My_Memcpy(&Pre_Payment_Para.StepSwitchDate.Year,(unsigned char *)&(triff_data->Grad_Switch_Date[0]),5);		
			Pay_EE_W(STEPSWITCHDATE_EE,(unsigned char *)&(Pre_Payment_Para.StepSwitchDate.Year),5,3,
						(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);		//Li Update 20130104
		}
		else
		{
			/*"���õ�ǰ���ݶȲ���ʱ,Ҫ�ж���ִ�����ݶȻ������ݶ�"*/
			switch_year_stage_mouth_stage();
			RunStepNum=get_run_step_num();
		}
	}
	//-------------------------------------------------------//
}
//------------------------------------------------------------------
//------------------------------------------------------------------
/*" Ǯ���ļ�û�ж�Ӧ�Ĵ����� "*/

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ��������������1 "*/
//struct Para_Table1
//	{
//	unsigned char Meter_ID[6];               /*" ��� "*/
//	unsigned char Client_ID[6];              /*" �ͻ���� "*/
//	unsigned char Card_Kind;                 /*" �翨���� "*/
//	};
//#define LENGTH_PARA_TABLE1  sizeof(struct Para_Table1)

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ��������������2 "*/
//struct Para_Table2
//	{
//	unsigned char User_Kind;                 /*" �û����� "*/
//	unsigned char Para_UpData_Flag;          /*" �������±�־λ "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ��������������3 "*/
//struct Para_Table3
//	{
//	unsigned long Remain_Money_Alarm1_Limit; /*" �������1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" �������2 "*/
//	unsigned char Current_CT[3];             /*" ������������� "*/
//	unsigned char Voltage_PT[3];             /*" ��ѹ��������� "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*"Meter_Parameter.WhitchSlotIsNow:��ǰʱ����־ "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:��ǰʱ�α�־ "*/
/*"Pre_Payment_Para.Curr_Triff_Point:��ǰ���ʱ�־�������µ�ǰ���ݱ�־ "*/
/*" 0:��ʾ��ǰ���е�һ�ף�1��ʾ��ǰ���еڶ���"*/
/*" 
/*" ��������������4 "*/
//struct Para_Table4
//	{
//	unsigned char Triff_Switch_Time[5];      /*" ���׷�ʱ�����л�ʱ�� "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ���翨�ļ����ݽṹ "*/
//struct Buy_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" �û����� "*/
//	unsigned char Para_UpData_Flag;          /*" �������±�־λ "*/
//	unsigned char No_Use0[4];      /*" ���� "*/
//	unsigned char Triff_Switch_Time[5];      /*" ���׷�ʱ�����л�ʱ�� "*/
//	unsigned char No_Use1;                      /*" ���� "*/
//	unsigned long Remain_Money_Alarm1_Limit; /*" �������1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" �������2 "*/
//	unsigned char Current_CT[3];             /*" ������������� "*/
//	unsigned char Voltage_PT[3];             /*" ��ѹ��������� "*/
//	unsigned char Meter_ID[6];               /*" ��� "*/
//	unsigned char Client_ID[6];              /*" �ͻ���� "*/
//	unsigned char Card_Kind;                 /*" �翨���� "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*"Meter_Parameter.WhitchSlotIsNow:��ǰʱ����־ "*/
/*"Meter_Parameter.WhitchDailySlotIsNow:��ǰʱ�α�־ "*/
/*"Pre_Payment_Para.Curr_Triff_Point:��ǰ���ʱ�־�������µ�ǰ���ݱ�־ "*/
/*" 0:��ʾ��ǰ���е�һ�ף�1��ʾ��ǰ���еڶ���"*/
/*" 
/*" ��������������5 "*/
//struct Para_Table5
//	{
//	unsigned long Para_Card_Version;      /*" �ֳ��������ÿ��汾�� "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ������Ϣ����,ר�Ÿ��ֳ��������ÿ��� "*/
//struct Set_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" �û����� "*/
//	unsigned char Para_UpData_Flag;          /*" �������±�־λ "*/
//	unsigned long Para_Card_Version;      /*" �ֳ��������ÿ��汾�� "*/
//	unsigned char Triff_Switch_Time[5];      /*" ���׷�ʱ�����л�ʱ�� "*/
//	unsigned char No_Use1;                      /*" ���� "*/
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
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ������Ϣ����,ר�Ÿ�����Ԥ�ƿ��� "*/
/*" ����Ԥ�ÿ� "*/
//struct Init_Para_Inf_File
//	{
//	unsigned char User_Kind;                 /*" �û����� "*/
//	unsigned char Para_UpData_Flag;          /*" �������±�־λ "*/
//	unsigned long Para_Card_Version;      /*" �ֳ��������ÿ��汾�� "*/
//	unsigned char Triff_Switch_Time[5];      /*" ���׷�ʱ�����л�ʱ�� "*/
//	unsigned char No_Use1;                      /*" ���� "*/
//	unsigned long Remain_Money_Alarm1_Limit; /*" �������1 "*/
//	unsigned long Remain_Money_Alarm2_Limit; /*" �������2 "*/
//	unsigned char Current_CT[3];             /*" ������������� "*/
//	unsigned char Voltage_PT[3];             /*" ��ѹ��������� "*/
//	};
//#define LENGTH_INIT_PARA_INF_FILE  sizeof(struct Init_Para_Inf_File)

//------------------------------------------------------------------
//------------------------------------------------------------------
/*"Mode:��������ģʽ��1��д���ã�0�������� "*/
/*"BIT7 :1��д���ã�0�������� "*/
/*"BIT0~BIT6 ��ʾ���µڼ��ݶ� "*/
/*"Source_Point��д����ģʽ�£�Ϊ������Դ�� "*/
/*"������ģʽ�£�Ϊ����ȥ�� "*/
/*"�����������ݽṹ�е����� "*/
/*"��Ҫʹ��receive_send_buffer������ "*/
/*" 
/*" ��д����,���û�����ESAM�� "*/
//struct Run_Inf_Data
//	{	
//	unsigned char User_Kind;					/*" �û����� "*/
//	unsigned char Current_CT[3];				/*" ������������� "*/
//	unsigned char Voltage_PT[3];				/*" ��ѹ��������� "*/	
//	unsigned char Meter_ID[6];					/*" ��� "*/
//	unsigned char Client_ID[6];				/*" �ͻ���� "*/
//	unsigned long Remain_Money;				/*" ʣ���� "*/
//	unsigned long Buy_Count;					/*" ������� "*/
//	unsigned long Low_Zero_Money;				/*" ������ "*/
//	unsigned char Password_Info[4];			/*" ��Կ��Ϣ��������״̬����ʽ���������汾 "*/
//	unsigned char Unlawful_Card_Count[3];		/*" �Ƿ���������� "*/
//	unsigned char Return_DT[5];				/*" ��д����ʱ�� "*/
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

	/*"����"*/
	Run_Inf_Data->User_Kind=0;
	 
	/*"�û���ţ���ţ��û�����"*/
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,6,&Run_Inf_Data->Client_ID[0]);
	Get_File_Data(ESAM,ESAM_PARA_INF_FILE,METER_ID_ESAM,6,&Run_Inf_Data->Meter_ID[0]);
	//Get_File_Data(ESAM,ESAM_PARA_INF_FILE,USER_KIND_ESAM,1,&Run_Inf_Data->User_Kind);
	
//	My_Memcpy(&(Run_Inf_Data->Client_ID[0]),&(Pre_Payment_Para.UserID[0]),6);
//	My_Memcpy(&(Run_Inf_Data->Meter_ID[0]),&(Pre_Payment_Para.MeterID[0]),6);
//	Run_Inf_Data->User_Kind = Pre_Payment_Para.User_Kind;

 	Pre_Get_OverZero_Money();

	if (Mode==0xB1)	/*"���翨"*/
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
 	/*"ʣ���� "*/
 	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Remain_Money),(unsigned char *)&Remain_Money_Temp,4);

	/*"������� "*/
	My_memcpyRev((unsigned char *)&(Run_Inf_Data->Buy_Count),(unsigned char *)&UL_Temp,4);

 	/*"������ "*/
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
  
	//    /*" ��Կ��Ϣ "*/
	//	Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,0,4,Run_Inf_Data->Password_Info);
	/*"����"*/
	My_Memcpy((unsigned char *)&(Run_Inf_Data->Password_Info[0]),0,4);

 	/*"�Ƿ���������� "*/
 	Run_Inf_Data->Unlawful_Card_Count[0] = 0;
	temp2 = ( unsigned int )Pre_Payment_Data.Unlawful_Card_Count;
	HexToBcd(2,(unsigned char *)&temp2, (unsigned char *)&Temp1);
 	Run_Inf_Data->Unlawful_Card_Count[2] =(unsigned char )Temp1;
	Temp1>>=8;
	Run_Inf_Data->Unlawful_Card_Count[1] =(unsigned char )Temp1;

	/*"��д����ʱ�� "*/
 	My_Memcpy((unsigned char *)&(Run_Inf_Data->Return_DT[0]),(unsigned char *)(&softdate),5);
	}

