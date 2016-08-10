/******************************************************************************************
*                      fine:      comm.c                                                  *
*                      function:  communication                                           *
*******************************************************************************************/  
#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "interrupt.h"
#include "att7022_operation.h"
#include "I2C_operation.h"
#include "Demand.h"
#include "LoadRecord.h"
#include "eventnew.h"
#include "MB_Keymain.h"
#include "MB_Showmain.h"
#include "seg.h" 
#include "initram.h" 
#include "multi.h"  //mw added070115
#include "MB_BASE_FUN.h"
#include "datachange.h"
#include "645_2007.h"
#include "Freeze.h"  //fxf  added081027
#include "File_System.h"//fxf  added081027
#include "Measure_Interface.h" 
#include "LoadRecord.h"

#include "pay_def.h"	
#include "Ex_Pay_For_Fun.h"
#include "Ex_Cpucard_Driver.h"
#include "ICcard.h"	//payment
#include "Far_pay.h"	//farpayment 
#include "Wireless.h"
#include "Energy_Del.H"
#include "BackLight_Ctrl.h"
extern union  BYTE_BIT     ProgramFlag[2];
extern struct PowerDown_EventSave_Data  PdEventData;

/*********** define  macro    *************************************************************/
#define  B_L              230    /*"通讯缓冲区总长度"*/
#define  B_FL             200    /*"通讯缓冲区查询总长度"*/
#define  R_DelayTime      120000 /*"3分钟内没有受到正确字节，初始化串口"*/
#define  R_To_T_DelayTime 150    /*"收发延时"*/
#define  T_DelayTime      15000  /*"发送延时"*/

#define  F_SIZE      196  /*"帧数据最大字节数"*/
#define  BatteryVoltage_SampleMode_AD///king chen add 130729
#pragma SECTION rom UserROMData
const unsigned char WorkroomPasswordClear[6]={0xB8,0x72,0x05,0x49,0x91,0xCD};
//const unsigned char WorkroomPassword[6]={0x85,0x3F,0xD2,0x16,0x5E,0x9A};
    
/******************************************************************************************/




/*********** extern  variable *************************************************************/

/******************************************************************************************/




/*********** define  variable *************************************************************/
unsigned char CommB[3][B_L] = {0,0};
unsigned char* CommBP;
struct FindCommand_Result * CurrPC;
unsigned long R_DelayT_Add[3];     /*"3分钟内没有受到正确字节，初始化串口"*/
unsigned long T_DelayT_Add[3];     /*"发送延时"*/
unsigned long R_To_T_DelayT_Add[3];/*"收发延时"*/
unsigned long Comm_Display_Old_Time[3]; /*"显示通讯标志起始时间"*/
unsigned char CommHead[3];  
unsigned char CommReal[3]; 
unsigned char CommPoint[3]; 
unsigned char WriteDateBuff[200] = {0};
struct FindCommand_Result cx[4];           /*"通讯结果"*/
unsigned char ChangeBand;                  /*"改变波特率标志"*/
//struct BIT Change_Far;                     /*"远红外和吸附式红外标志"*/
//unsigned long ProgramKeyTime;              /*"编程按键起始时间"*/
unsigned char ChenkPasserwordFlag;         /*"测试用户权限标志"*/

struct DATEANDTIME_DEF ProgramEventDate;    /*"编程起始时间"*/
unsigned char ProgramEventFlag;             /*"编程起始标志"*/
union  BYTE_BIT JustMeterDataFlag;          /*"教表内容标志"*/
unsigned char  JustMeterFlag;               /*"教表起始标志"*/
struct DATEANDTIME_DEF JustMeterDateFlag;   /*"教表起始时间"*/
unsigned char  datapoint;  /*"调用tranferdater（），赋指针初始变量"*/
unsigned char  user_level;

unsigned  char   Readdata_buff[32];/*" 读数据缓冲区间fxf"*/ 

unsigned long    Clear_all_oper_code=0;/*"总清零操作者代码"*/
unsigned long    Clear_event_oper_code=0;/*"qClear_event"*/
unsigned long    clear_event_ID_code=0;/*"Clear_event"*/
unsigned long    Clear_demand_oper_code=0;/*"Clear_demand"*/
unsigned long    Comm_DailyProg_oper_code;
unsigned long    Comm_YearProg_oper_code;
unsigned char    Comm_DailyOrYear_Slot;/*"通信先应答后处理"*/
unsigned char    Comm_Firrespon_SecDispos_Buff[42];/*"通信先应答后处理操作前数据"*/
unsigned char    Comm_Firrespon_SecDispos_Uart[3];

/*"    ************************   读有符号变量* ************************   "*/
signed long     COMM_Curr[3];/*"当前电流"*/
signed long     COMM_Factor[4];/*"当前功率因素"*/           
signed long     COMM_Active_power[4];/*"当前有功功率"*/
signed long     COMM_Reactive_power[4];/*"当前无功功率"*/
signed long     COMM_Visual_power[4];/*"当前视在功率"*/
unsigned char  Freeze_Flag_DayHour[2];																									/*"0 有功"*/
																								/*"1 无功"*/

/*"  ************************     读有符号变量*************************    "*/
//union BYTE_BIT GPRS_Event_Status[10];	//payment
//union BYTE_BIT GPRS_Event_OldStatus[10];
//unsigned char  uartxcomm;

unsigned char GPRS_Status;//bit7 0:outline  1:inline  	//MB4
                                          //bit0~bit2  0:no signal  1~4:signal strenth bad~good
unsigned long    Demandtempbuffer;	
/******************************************************************************************/
unsigned int  Voltage_ad_data[2] = {0x0000,0x0000};///king chen add 121214
unsigned char  Displayfinish_flag=0;///king chen add 121214
unsigned int FullScreenTime;///king chen add 121214

volatile unsigned  char ad_Flag=0;  ///king chen 121214
volatile unsigned  char ad_finish_Flag;  ///king chen add 121226
volatile unsigned int  fix_ad_data =0;///king chen add 130730
unsigned long meter_model_ok;///king chen add 130104
unsigned char meter_model_reset_flag;///king chen add 130104
///unsigned char closebacklight_flag=0;///king chen add 130228
unsigned long meter_model_reset_time;

unsigned char farinfrareddisableflag;
unsigned int pd_infrared_flag_showtime;/*"低功耗下红外通信符号显示时间"*/

unsigned long comm_plus_energy_01wh[MAXTRIFF][2]; /*"通讯和显示4位小数的正向有功电量 0小数 1整数"*/
unsigned long comm_nega_energy_01wh[MAXTRIFF][2]; /*"通讯和显示4位小数的反向有功电量 0小数 1整数"*/
unsigned char  Event_Report_reread_flag;/*"重读事件上报状态字,当Event_Report_reread_flag=1表示第一次抄读,当Event_Report_reread_flag=2表示重读"*/
/*********** define  function *************************************************************/
void Init_Comm(unsigned char);
void Interr_Comm_R(unsigned char);
void Interr_Comm_W(unsigned char);
void Communication(unsigned char,unsigned char,unsigned char);
unsigned char FindComCommand(unsigned char,unsigned char);
unsigned char AnswerComCommand(unsigned char,unsigned char);
signed int TransferData(union ID ,unsigned char *,unsigned int,unsigned char,
                           unsigned char*,unsigned char );
unsigned long GetNowTime(void);  
unsigned char GetTimeCount(unsigned long,unsigned long); 
unsigned char F_Ar(unsigned char,unsigned char);  
//unsigned char OB_H(unsigned char);  
unsigned char Cal_Cs(unsigned char *,unsigned char,unsigned char);    
void ReadData(unsigned char);   
void WriteData(unsigned char);     
void BroadcastJustTime(unsigned char);
void WriteAddress(unsigned char);
void WriteBaud(unsigned char);    
void WritePassword(unsigned char);
void ClearDemand(unsigned char); 
unsigned char R_W_Data(void);
unsigned char ReadLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
unsigned char WriteLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
unsigned char GetRecordAddr(unsigned char,unsigned char,unsigned char); 
//unsigned char OH_B(unsigned char hex);
unsigned char CalDay(unsigned char,unsigned char);  
//unsigned char CheckBCD(unsigned char data);      
//unsigned char CheckTime(unsigned char *); 
double long ComTime(unsigned char *,unsigned char *);
void Delay(unsigned int);
void JustMeter(unsigned char);
//void CheckK1(void);
unsigned char ClearDemandCommAndKey(unsigned char , unsigned char);
void ClearMeter(unsigned  char );
void Clear_PasswordErr(unsigned char,unsigned char);
void CheckProgramKeyState(void);
void CalSendDataLength(unsigned char *);
void CalSendLaterDataID(unsigned char *,unsigned char);
//void Caar(unsigned int ,unsigned char ,unsigned char);	
//void Carr(unsigned int ,unsigned char ,unsigned char);             
void  Caarr(unsigned int EEAddr ,unsigned char* RamAddr,unsigned char sort,unsigned char type);//add by zlp
void CheckPasswoerErr(unsigned char );
//void ClearEvent(unsigned char);  //change by pc 081129
unsigned char CheckPasswordRight(unsigned char *);
unsigned char CheckPasswordCanWrite(unsigned char,unsigned char);
unsigned char CheckPasswordProgram(unsigned char,unsigned char*);

signed int Event_Energy(unsigned char formatdata,unsigned char * P,unsigned char * soures,unsigned char paddr);//add by trend 2005-12-28 15:02
signed int FreezeEvent_Energy(unsigned char * ,unsigned char * );
//void Clear_Energy_All(void);//liuyq delete 2009-8-21


void ReadData_New(unsigned char uartx);
void WriteData_New(unsigned char uartx);
//void Freeze_Command_New(unsigned char uartx);
//------------------------FXF ADD 081120---
void WriteAddress_New(unsigned char uartx);
void ReadAddress_New(unsigned char uartx);
void WritePassword_New(unsigned char uartx);
void Freeze_Command_New(unsigned char uartx);
void ClearDemand_New(unsigned char uartx);
void WriteBaud_New(unsigned char uartx);
void ClearEvent_New(unsigned char uartx);
void ClearMeter_New(unsigned char uartx);
unsigned char  Clear_All_New(unsigned long );
unsigned char  Clear_Erengy(void);
unsigned char  Clear_Freeze(void);
unsigned char  CheckPasswordProgram_New(unsigned char *addr,unsigned char level);
unsigned char  Check_Can_Justtime(void);
unsigned char  DealWithJustTime(unsigned char *time_old);
void Check_Clear_Responsion(unsigned char);
void Set_Multi_Function_Terminal_Output(unsigned char uartx);
unsigned int Crc16l(unsigned char *ptr,unsigned char len);
void Set_which_Responsion_Flag(unsigned char Which,unsigned char flag);


/********************645 fuxf add ***************************************/

void  Read_SystemTime_YMDH(void);//modify by zlp
void   Read_SystemTime_HMS(void);//modify by zlp
int  Set_DemandPeriod(void);
int  Set_DemandSkipPeriod(void);
int  Set_Activem_Erengy_Mode(void);
int  Set_REActivem_Erengy_1_Mode(void);
int	 Set_REActivem_Erengy_2_Mode(void);
int	 Set_ActivePulseConst(void);
int  Set_Erengypoint(void);
int  Set_BILL_Day(void);
int  Set_SlotParemeter(void);
int  Set_YearSlot(void);
int  Set_ProgWeek(void);
int  Set_Holiday(void);
int  Set_DailySlot(void); 
int  Set_LoadRecoedBeginTime(void);
int  Set_LoadRecoedPeriod(void);
int  Set_MeterMode(void);
int  Set_Meterlocktimes(void);
int  Set_OutputModel(void);
int  Exit_WorkRoomState(void);
int  Set_primary_energy(void);
int  Read_WorkRoomState(void);
int  Read_Freeze_Bit_0_data(void);
int  Read_Freeze_Bit_1_data(void);
int  Read_Freeze_Bit_2_data(void);
int  Read_Freeze_Bit_3_data(void);
int  Read_Freeze_Bit_4_data(void);
int  Read_Freeze_Bit_5_data(void);
int  Read_Freeze_Bit_6_data(void);
int  Read_Freeze_Bit_7_data(void);
int  Read_Freeze_Block_data(void);
int  Read_Meter_lock_times(void);
int  Check_Parameter_Len_IS_ok(unsigned char trans_format);
int  Pre_No_use_leaf_data(void);
int  Set_Display_Number(void);
int  Set_Commrate(void);
int  Read_Freeze_Date(void);
int  Set_CycleDisplayTime(void);
int  Read_Far_IR_Commate(void);
int  Set_CriticalVoltage(void);
int  Set_CommAddr(void);
int  Set_Show_USER_Code(void);
int  Read_Sign_Instance_Variable(void);
int  Read_YearSlot_Table(void);
int  Read_DailySlot_Table(void);
void  Read_Last_loss_voltage_time(unsigned char type);//0 start 1 end   add by zlp
int  Read_Last_loss_voltage_start_time(void);//modify by zlp return :  int to void
int  Read_Last_loss_voltage_end_time(void);//modify by zlp return :  int to void
int Comm_Initialize_FLASH(void);
int Set_Freeze_Period_Begin_time(void);
int Set_Freeze_Period(void);
int Set_TriffSwitchDate(void);
int Set_ShowNoKeyRetTime(void);
int Set_Cycle_Key_Display(void);
int Set_JFPG_Triff(void);
int Read_Meter_FILEDATE_VI(void);
int  Read_Display_Number(void);  //lfy add  2011-3-11
int  Read_LostVoltEnergy(void);

int SetPowerOnFullScreenTime(void);

int  Set_SystemTime_YMDHHMS(void);

int GetMeterSoftIdNumber(void);
int SetMeterSoftIdNumber(void);

int GetNowMonthComActiveEnergy(void);
int GetLastMonthComActiveEnergy(void);

int Set_Freeze_Day(void);

int ResetEventReportInfo(void);
int Set_ResetReportTime(void);
/******************************************************************************************/


//
//liuyq added 2009-8-21 start
void Postfix_WriteDatetime(void);
void AppointTrasfPortBuff(unsigned char uartx);

void Set_Meter_para_Deal(unsigned int rom_addr);

void RTC_Init(void);///king chen add 121214
void PowerOn_FullScreen_TimeDetection(void);///king chen add 121214
void HZ_LCDQueryCmd(unsigned char uartx); ///king chen add 130204

unsigned char  Check_Clear_Event_If_Ok(unsigned long cleareventflag);

void Clear_EventReportStatus_And_Times(union EVENT_REPORT_STATUS EventReportStatus);

void AppointTrasfPortBuff(unsigned char uartx)
{
	if(uartx<3)
	{
		CommBP = (unsigned char*)&CommB[uartx];
	   	cx[3]=cx[uartx];
		CurrPC = (struct FindCommand_Result *)&cx[3];
	}
	else   
	{
		CommBP = &Co.b[500];
		CurrPC =(struct FindCommand_Result *)&Co.b[500];
	}
}

	//liuyq modify 2009-8-21 end
/******************************************************************************************
*       function:Communication  main program                                              *
*       imput:mode0-the uart0's control                                                   *
*             mode1-the uart1's control                                                   *
*             mode2-the uart2's control                                                   *
*             01---645                                                                    *
*             02---wasion                                                                 *
*             03---645 or wasion                                                          *
*             A7---close                                                                  *
*******************************************************************************************/
void Communication(unsigned char mode0,unsigned char mode1,unsigned char mode2)
{
	unsigned int uni, i;
	double long data;
	

	
	unsigned char Ports[3];
	unsigned char *PinAndCommBuff[3][2] ={
		{&u0c1, &u0tbl},
		{&u2c1, &u2tbl},
		{&u1c1, &u1tbl}};

	Ports[0] = mode0;
	Ports[1] = mode1;
	Ports[2] = mode2;
	
	if(!IntoPowerDownFlag)     /*"正常上电执行，低功耗不执行"*/
	{
		if(Show_flag.bit.RS1)
		{
			if(!GetTimeCount(Comm_Display_Old_Time[0],3000))
				Show_flag.bit.RS1=0;
		}
		if((Show_flag.bit.RS2!=0)||(Show_flag.bit.Carrier_Wave!=0))
		{
			if(!GetTimeCount(Comm_Display_Old_Time[2],3000))
			{
				Show_flag.bit.RS2=0;
				Show_flag.bit.Carrier_Wave=0;
			}
		}
		if(Show_flag.bit.BT)
		{
			if(!GetTimeCount(Comm_Display_Old_Time[1],3000))
				Show_flag.bit.BT=0;
		}
		if(meter_model_reset_flag)///king chen add 130104
			{
			if(!GetTimeCount(meter_model_reset_time, 200))
			   {
			    meter_model_reset_flag=0;
			    meter_model_ok=GetNowTime();	   
			    RST_ZB=1;
			   }
			}
#ifdef  DEMAND_CLR_KEY		
		if(Show_flag.bit.key)
		{
			
			data=ComTime((unsigned char*)&softdate,(unsigned char *)&Other_Data.LastClearDemandDate);
			if(ABS(data)>Meter_Parameter.parameter1.DemandPeriod*60)//MODIFY BY ZLP			 
			{
				for(uni=0;uni<sizeof(struct DATEANDTIME_DEF);uni++) 
					*((unsigned char *)&Other_Data.LastClearDemandDate+uni)=0;   
				Show_flag.bit.key=0;   
			}
		}
#endif

	}
else
{
    if(Show_flag.bit.BT)
		{
			if(!GetTimeCount(Comm_Display_Old_Time[1],pd_infrared_flag_showtime))
				Show_flag.bit.BT=0;
		}
}
	
	for(i=0; i<3;i ++)
	{
		if((i!=1) && IntoPowerDownFlag)
			continue;
		if(Ports[i]!=0xA7)
		{
			if(GetTimeCount(R_DelayT_Add[i],R_DelayTime)==0)
			{/*"R_DelayTime时间内没有受到正确字节，初始化串口"*/
				Init_Comm(i);
			}
			else
			{
				if((*PinAndCommBuff[i][0]&0x05)==0x04)//modify by zlp
				{
                    Check_Clear_Responsion(i);
                    
					if(FindComCommand(i,Ports[i]))/*"查找协议帧"*/
					{
						if((Meter_Parameter.parameter1.MeterTypeMode.bit.b7)&&(2 == i))						
						  meter_model_ok=GetNowTime();///king chen add 130104
						//uartxcomm=i;//ganjp 20091127
						*PinAndCommBuff[i][0] &=(~0x04);
						AnswerComCommand(i,cx[i].model);
						Comm_Display_Old_Time[i]=GetNowTime();    	
						if(i==0)
							Show_flag.bit.RS1=1;
						else if (i == 1)
						{
							Show_flag.bit.BT=1;
							if(IntoPowerDownFlag)
							{
							    pd_infrared_flag_showtime =1000*( Meter_Parameter.parameter1.CycleDisplayTime + 2);
							}
							//if(!IntoPowerDownFlag)
							//	{
							//	Light_Back_Up_Flag=0xFF;
							//	Light_Back_Led();  
							//	}
							PowerdownStopCommAdd=0;
                            pdmodekeyflag=0xff;
                            PowerdownStopKeyAdd=0;
						}
						else
						{
							if(Meter_Parameter.parameter1.MeterTypeMode.bit.b7==0)
							  Show_flag.bit.RS2=1;
							else
							  Show_flag.bit.Carrier_Wave=1;
						}
                        
                        Comm_Firrespon_SecDispos_Uart[i]=i;
					}
					else if((Meter_Parameter.parameter1.MeterTypeMode.bit.b7)&&(2 == i))///king chen add 130104
					{
					if(!GetTimeCount(meter_model_ok, METER_MODEL_ERROR_RUNTIME))
						{
						meter_model_reset_flag=1;
						meter_model_reset_time=GetNowTime();
						RST_ZB=0;
						}
					}
				}
				
				//else 
				if((*PinAndCommBuff[i][0]&0x05)==0x0)
				{/*"通讯关闭状态，此时是接收到完整的帧以后 TE=0发送禁止 RE=0接收禁止"*/
					if(!GetTimeCount(R_To_T_DelayT_Add[i],25))	//R_To_T_DelayTime
					{	/*"如果大于收->发切换时间，切换到发送状态"*/
						T_DelayT_Add[i]=GetNowTime();
						//re_u0c1=0;
						*PinAndCommBuff[i][0] &=(~0x04);
						//te_u0c1=1;
						*PinAndCommBuff[i][0] |=(0x01);
						//u0tbl=Comm1B[CommHead[0]];//0xFE; //after send data,clear buffer
						*PinAndCommBuff[i][1]=CommB[i][CommHead[i]];//0xFE; //after send data,clear buffer	//liuyq modify 2009-8-21 start
						CommHead[i]++;
					}  
				}			
				else if((*PinAndCommBuff[i][0]&0x05)==0x01)
				{/*"发送状态 TE=0发送禁止 RE=1接收允许"*/
					if(!GetTimeCount(T_DelayT_Add[i],T_DelayTime))
					{/*"T_DelayTime时间内没有发送字节，初始化串口"*/
						Init_Comm(i);
					}

					if(cx[i].sendbackframe)  
					{
						*PinAndCommBuff[i][0] &= 0xFE;	    
						cx[i].sendbackframe=0;
						T_DelayT_Add[i]=GetNowTime();
						AnswerComCommand(i,cx[i].model);     
					}
				}
			}
		}
		else
		{
			*PinAndCommBuff[i][0] &= (~0x01);	    
			*PinAndCommBuff[i][0] &=(~0x04);
		}
	}

}

/******************************************************************************************/
/******************************************************************************************/



/******************************************************************************************
*     1. imput:  uartx   uart0,uart1,uart2                                                *
*                                                                                         *
*******************************************************************************************/
void Init_Comm(unsigned char uartx)  //10M crystalloid
{
	unsigned char data;
	unsigned char baud,clock;

	unsigned int uni;	
		
	if(Meter_Parameter.parameter1.Commrate[uartx].bit.B1200)
	{
		baud=64;
		clock=0x01;
	} 
	else if(Meter_Parameter.parameter1.Commrate[uartx].bit.B2400)
	{
		baud=32;
		clock=0x01;
	} 
	else if(Meter_Parameter.parameter1.Commrate[uartx].bit.B4800)
	{
		baud=129;
		clock=0x00;
	} 
	else if(Meter_Parameter.parameter1.Commrate[uartx].bit.B9600)
	{
		baud=64;
		clock=0x00;
	} 	
	else   //2400 baud
	{  
		baud=32;
		clock=0x01;	  
	} 

//	if( Far_Comm_Init_NO != 0x5A )
		{
		for(uni=0;uni<B_L;uni++)//liuyq added 2009-8-25
			CommB[uartx][uni]=0;//liuyq modify 2009-8-21 
		}

		
	switch(uartx)
	{
	   case 0:
	   uni=u0rb;         //arthor 2007-2-12
	   re_u0c1=1;        //arthor 2007-2-12
	   re_u0c1=0;        //arthor 2007-2-12
	   uni=u0rb;         //arthor 2007-2-12
	   re_u0c1=1;        //arthor 2007-2-12
	   re_u0c1=0;        //arthor 2007-2-12
	   u0c1=0;
	   data=u0rbl;
	   u0mr=0x60;
	   u0mr=0x65;
	   u0c0=0x18|clock;
	   u0irs=1;
	   u0brg=baud;
	   te_u0c1=0;
	   re_u0c1=1;
	   RE_DE0=1;
	   break;
	   
	   case 1:
	   uni=u2rb;         //arthor 2007-2-12
	   re_u2c1=1;        //arthor 2007-2-12
	   re_u2c1=0;        //arthor 2007-2-12
	   uni=u2rb;         //arthor 2007-2-12
	   re_u2c1=1;        //arthor 2007-2-12
	   re_u2c1=0;        //arthor 2007-2-12	   
	   ta1mr=0x27;
     ta1=0x8000;//high length is 0xe0/f1, cycle is 0xff/f1
     ta1s=0;
	   u2c1=0;
	   data=u2rbl;
	   u2mr=0x60;
	   u2mr=0x65;
	   u2c0=0x18|0x01;
	   u2irs=1; 
	   u2brg=64;
	   te_u2c1=0;
	   re_u2c1=1;		
	   break;
	   
	   case 2:
	   uni=u1rb;         //arthor 2007-2-12
	   re_u1c1=1;        //arthor 2007-2-12
	   re_u1c1=0;        //arthor 2007-2-12
	   uni=u1rb;         //arthor 2007-2-12
	   re_u1c1=1;        //arthor 2007-2-12
	   re_u1c1=0;        //arthor 2007-2-12
	   u1c1=0;
	   data=u1rbh;
	   data=u1rbl;
	   u1mr=0x60;
	   u1mr=0x65;
	   u1irs=1; 
///if (FLAG_CARRIER_MODEL)	 	//model///king chen mark 121214
///{
///	u1c0=0x18|0x01;
///	u1brg=32;		// 2400bps	
///}
///else if (FLAG_GPRS_MODEL)	
///{
///	u1c0=0x18|0x00;
///	u1brg=64;		// 9600bps
///}
	   if (Meter_Parameter.parameter1.MeterTypeMode.bit.b7)///king chen add 121214
	   {
	   u1c0=0x18|0x01;
	   u1brg=32;		// 2400bps	
	   }
	   else
	   {
	   u1c0=0x18|clock;
	   u1brg=baud;
	   }
	   te_u1c1=0;
	   re_u1c1=1;
	   RE_DE1=1;
	   break;	   
	}
	R_DelayT_Add[uartx]=GetNowTime(); 
}  
/******************************************************************************************/                                      
                
                
                
/******************************************************************************************
*     1. imput:  uartx   uart0,uart1,uart2                                                *
*                                                                                         *
*******************************************************************************************/
void Interr_Comm_R(unsigned char uartx)
{
	 unsigned char *po1;
	 unsigned int uni;
	 union data
	{
	   unsigned char c[2];
	   unsigned int  i;
	}d={0,0};		
	
	switch(uartx)
	{
		case 0x00: if(ir_s0ric) ir_s0ric=0; po1=(unsigned char*)&CommB[0];d.i=u0rb; break;
		case 0x01: if(ir_s2ric) ir_s2ric=0; po1=(unsigned char*)&CommB[1];d.i=u2rb; break;
		case 0x02: if(ir_s1ric) ir_s1ric=0; po1=(unsigned char*)&CommB[2];d.i=u1rb; break;
		default:   po1=&Co.b[500];
	}

	
	if(!(d.c[1]&0x80))
	{                         
	   po1[CommPoint[uartx]]=d.c[0];
	   CommPoint[uartx]++;
	   if(CommPoint[uartx]>=B_FL)
	      CommPoint[uartx]=0;
	   R_DelayT_Add[uartx]=GetNowTime();     
	}
	else
	{
           switch(uartx)
	   {
	      case 0x00: u0mr=0x60;u0mr=0x65; break;
	      case 0x01: u2mr=0x60;u2mr=0x65; break;
	      case 0x02: u1mr=0x60;u1mr=0x65; break;
	   }		
	}		
}
/******************************************************************************************/



/******************************************************************************************
*     1. imput:  uartx   uart0,uart1,uart2                                                *
*                                                                                         *
*******************************************************************************************/
void Interr_Comm_W(unsigned char uartx)
{
	 unsigned char *poin1;
	 unsigned int   uni;
	
	switch(uartx)
	{
	   case 0x00: if(ir_s0tic) ir_s0tic=0; break;
	   case 0x01: if(ir_s2tic) ir_s2tic=0; break;
	   case 0x02: if(ir_s1tic) ir_s1tic=0; break;
	}	                   
	if(uartx<3)
		poin1=(unsigned char*)&CommB[uartx];//liuyq modify 2009-8-21 start
	else
    poin1=&Co.b[500];
	if(!((CommHead[uartx]>=B_L) || (CommReal[uartx]>=B_L)))
	{
	   if(CommHead[uartx]==CommReal[uartx])
	   {	
	      for(uni=0;uni<B_L;uni++)
	         poin1[uni]=0;	
	      CommHead[uartx]=CommReal[uartx]=CommPoint[uartx]=0;
	      	         
			if(cx[uartx].havebackframe)
			{
				cx[uartx].sendbackframe=1; 
				cx[uartx].lena=0;
			}
			else
			{
				switch(uartx)
				{	
					case 0:
						RE_DE0=1; 
						te_u0c1=0; 
						re_u0c1=1; 
						break;
					case 1:
						te_u2c1=0;
						re_u2c1=1; 
						break;
					case 2:  
						RE_DE1=1; 
						te_u1c1=0; 
						re_u1c1=1; 
						break;
				}
			}	      
		}
		else
		{
			switch(uartx)
			{
				case 0:  u0tbl=poin1[CommHead[uartx]]; break;
				case 1:  u2tbl=poin1[CommHead[uartx]]; break;
				case 2:  u1tbl=poin1[CommHead[uartx]]; break;
			}
			CommHead[uartx]++;	
		}
	}
	else
	{
		Init_Comm(uartx);
	}
}
/******************************************************************************************/



/******************************************************************************************
*     1. imput:  uartx   uart0,uart1,uart2                                                *
*                mode    0-645,1-weisheng,3-645 or weisheng                               *
*******************************************************************************************/
unsigned char FindComCommand(unsigned char uartx,unsigned char mode)
{
	unsigned char i,j,k;
	unsigned char *p;
	unsigned char ok,ok1,ok2;
	struct FindCommand_Result *pc;
	unsigned char aanumber=0;
	unsigned  int uni;
	unsigned char ffg=0;
	
	ok=ok1=ok2=0;
	
	if(uartx<3)
	{p=(unsigned char*)&CommB[uartx]; pc=(struct FindCommand_Result *)&cx[uartx];}
	else
	{p=&Co.b[500]; pc=(struct FindCommand_Result *)&Co.b[500];}

	if(mode==DL_PROTOCOL || mode==DL_AND_ZJ_PROTOCOL || mode==DL_AND_WS_PROTOCOL)
	{
	   for(i=0;i<B_FL;i++)
	   {
	      if(p[i]==0x16)/*"在整个通讯缓冲区查结束符16"*/
	      {/*"查找到结束符16"*/
	         for(j=0;j<B_FL-7;j++) 
	         {
	            if((p[F_Ar(i,j)]==0x68) && (j>=4))/*"在16的前j个字节找第二个68,"*/
	            {/*"找到第二个68"*/
	            	if(p[F_Ar(i,j+7)]==0x68)/*"在第二个68前7个字节找第一个68"*/
	                {/*"找到第一个68"*/
	                   if(p[F_Ar(i,j-2)]==(j-4))/*"判断L"*/
	                   {                        
					if(uartx==1)//lfy add 2011-07-29 for lightup backlight every IR command
					{
						if(!IntoPowerDownFlag)
						{
						///Light_Back_Up_Flag=0xFF;///
						///Light_Back_Led(); 
						BackLight_Ctrl(FIX_TIME_LIGHT_MODE, 2L*Meter_Parameter.parameter1.DisplayNumber*Meter_Parameter.parameter1.CycleDisplayTime,0,UART2_EVENT);///king chen add 130305
						}
					}

				//#if HOUR_ENERGY 
	                      ok=0xff;
	                      ok1=0xff;
	                      for(k=0;k<6;k++)
	                      {
	                      	 if((p[F_Ar(i,j+6-5+k)]!=Meter_Parameter.parameter1.BcdCommAddr[uartx][5-k]) &&
	                      	    (p[F_Ar(i,j+6-5+k)]!=0xAA)  && (p[F_Ar(i,j+6-5+k)]!= (0xA0   |   (Meter_Parameter.parameter1.BcdCommAddr[uartx][5-k] & 0x0f ))))
	                      	 {/*"不等于表地址或AA的缩位地址"*/
	                      	    ok=0;
	                      	    break;
	                      	 }
	                      	 else
	                      	 {
                              if(p[F_Ar(i,j+6-5+k)]==Meter_Parameter.parameter1.BcdCommAddr[uartx][5-k])
                                ok1=0;
                              else if(ok1==0) ok=0;  
                              
                              if(p[F_Ar(i,j+6-5+k)]==0xAA && (ok1!=0))
                                 aanumber+=2;
                              else if(p[F_Ar(i,j+6-5+k)]==0xAA && (ok1==0))   
                              {
                                 ok=0;/*"表地址有AA，地址错误，不响应通讯命令"*/
                                 break;
                              }
                              else if((p[F_Ar(i,j+6-5+k)]&0xf0)==0xA0)
                              {
                                   aanumber+=1;  
                                  ok1=0;
                              }
	                      	 }
	                      }
	                      
	                      ok1=0xff;
	                      for(k=0;k<6;k++)
	                      {
	                      	 if(p[F_Ar(i,j+6-k)]!=0xAA)
	                      	 {
	                      	    ok1=0;
	                      	    break;
	                      	 }
	                      }
				COMM_ALL_AA_DEFINE=0;		  
				if(ok1!=0)/*"地址为全A时，全A地址标志置位1"*/
				{
				pc->All_AA_Address = 1;
				COMM_ALL_AA_DEFINE=1;
				}
				
	                      if((ok1!=0)
								 && ((p[F_Ar(i,j-1)]!=0x01)/*"缩位地址可执行的命令"*/
	                             && (p[F_Ar(i,j-1)]!=0x09)
	                             && (p[F_Ar(i,j-1)]!=0x03)/*"远程费控协议控制码中的抄读操作需支持全A地址"*/
	                             && (p[F_Ar(i,j-1)]!=0x0A)
	                             && (p[F_Ar(i,j-1)]!=0x11)/*"读数据FXF081209"*/
	                             && (p[F_Ar(i,j-1)]!=0x12)
	                             && (p[F_Ar(i,j-1)]!=0x13)   /*"读通信地址FXF081126"*/
	                             && (p[F_Ar(i,j-1)]!=0x15)))/*"写通信地址FXF081126"*/
	                      {
	                         ok=0;
	                      } 
	                      
	                     if((aanumber>9) && ((p[F_Ar(i,j-1)]==0x04)|| (p[F_Ar(i,j-1)]==0x14)))/*"写命令的A个数不能大于9"*/
	                     {
	                        ok=0;
	                     }
	                      
	                      ok1=0xff;
	                      for(k=0;k<6;k++)
	                      {
	                      	 if(p[F_Ar(i,j+6-k)]!=0x99)
	                      	 {
	                      	    ok1=0;
	                      	    break;
	                      	 }
	                      }
	                      if((ok1!=0) && ((p[F_Ar(i,j-1)]==0x01)/*"广播地址可以执行的命令"*/
	                             || (p[F_Ar(i,j-1)]==0x0A)
	                             || (p[F_Ar(i,j-1)]==0x08)
	                             || (p[F_Ar(i,j-1)]==0x09)
	                             || (p[F_Ar(i,j-1)]==0x11)
							     || (p[F_Ar(i,j-1)]==0x12)								
								 || (p[F_Ar(i,j-1)]==0x16)
                                 || (p[F_Ar(i,j-1)]==0x1D)
                                 || (p[F_Ar(i,j-1)]==0x05)
	                             || (p[F_Ar(i,j-1)]==0x1F)))//GANJP 20090701 
	                      {
	                         ok=0xff;
	                         ffg=0xff;
	                      } 
	                      if(ok)
	                      {/*"地址正确"*/
	                         if(Cal_Cs(p,F_Ar(i,2),j+7-1)==p[F_Ar(i,1)])
	                         {/*"校验和正确"*/
	                            switch(uartx)
	                            {
	                               case 0x00: re_u0c1=0;break;
	                               case 0x01: re_u2c1=0;break;
	                               case 0x02: re_u1c1=0;break;
	                            }	
	                            pc->model=0;
	                            pc->model=DL_PROTOCOL;
	                            
	                            if(p[F_Ar(i,j-1)]!=0x02)
	                            {
	                               
	                               for(uni=0;uni<sizeof(struct FindCommand_Result);uni++)
	      	                          *((unsigned  char *)&cx[uartx]+uni)=0;
	                               if(ffg)
	                                  pc->BroadCasrAddress=1;
	                               
	                               /*" move by trend 2008-7-11 13:32:00"*/	
	                               	pc->c=p[F_Ar(i,j-1)];  //c
	                             		pc->ct=p[F_Ar(i,j-1)]; //c
	                             		pc->len=p[F_Ar(i,j-2)];//l
	                               /*"add by trend 2008-7-11 13:32:16"*/
	                               /*"区分是645-2007的命令否"*/
	                               if((pc->c==0x11)||(pc->c==0x14))
	                               	{/*"新645的数据标识是4位的"*/
	                               		pc->id.d[0]=p[F_Ar(i,j-3)]-0x33;
	                               		pc->id.d[1]=p[F_Ar(i,j-4)]-0x33;
	                               		pc->id.d[2]=p[F_Ar(i,j-5)]-0x33;
	                               		pc->id.d[3]=p[F_Ar(i,j-6)]-0x33;
	                               		pc->addr=F_Ar(i,j-7);/*"数据起始地址"*/
	                                  pc->dataaddr=p+F_Ar(i,j-7);
									  
	                               	}
				                else  if(pc->c==0x12)/*"后续帧序号FXF ADD"*/
	                               	{
	                               		pc->id.d[0]=p[F_Ar(i,j-3)]-0x33;
	                               		pc->id.d[1]=p[F_Ar(i,j-4)]-0x33;
	                               		pc->id.d[2]=p[F_Ar(i,j-5)]-0x33;
	                               		pc->id.d[3]=p[F_Ar(i,j-6)]-0x33;
	                               		pc->Frame_serial=p[F_Ar(i,j-7)]-0x33;	
	                               		pc->addr=F_Ar(i,j-7);/*"数据起始地址"*/										
	                               	}
	                               else
	                               	{
	                               		pc->id.d[0]=p[F_Ar(i,j-3)]-0x33;
	                               		pc->id.d[1]=p[F_Ar(i,j-4)]-0x33;
	                               		if((pc->c==0x01) || (pc->c==0x04)|| (pc->c==0x1F))//GANJP 20090701
	                               		{
	                                 			pc->addr=F_Ar(i,j-5);/*"数据起始地址"*/
	                                  		pc->dataaddr=p+F_Ar(i,j-5);
	                               		}
	                               		else 
	                               		{
	                                  	pc->addr=F_Ar(i,j-3);/*"数据起始地址"*/
	                                  }
	                              	}
	                               
	                             }
	                             
	                             pc->lena=0;
	                               
	                            ok2=0xff;      
	                            return 0xff;
	                         } 
	                         else
	                         {
	                         	 for(uni=0;uni<B_L;uni++)
                                     *((unsigned char *)&CommB[0][0]+B_L*uartx+uni)=0;//liuyq modify 2009-8-21 
	                         }
	                      }
	                      else
	                      {
	                      	  for(uni=0;uni<B_L;uni++)
                                     *((unsigned char *)&CommB[0][0]+B_L*uartx+uni)=0;//liuyq modify 2009-8-21 
	                      }
	                   }
	                }
	            }
	         }  
	      }	 
	   }
	}

	
	if(ChangeBand<4)
		if(uartx == (ChangeBand-1))
		{
			Init_Comm(uartx); 
			ChangeBand=0;
	   	}

	return 0;
}
/******************************************************************************************/



/******************************************************************************************
*     1. import:addr-base address                                                         *
*               offset-offset before of addr                                              *
*******************************************************************************************/
unsigned char F_Ar(unsigned char addr,unsigned char offset)
{
	if(addr>=offset)
	   return addr-offset;
	else return   B_FL+addr-offset; 
}
/******************************************************************************************/

/******************************************************************************************
*     1. import:uartx                                                                     *
*               mode-0-645,1-weisheng                                                     *
*               1.pc->ct is set in readdata                                               *
*               2.in read data check length                                               *
*******************************************************************************************/
unsigned char AnswerComCommand(unsigned char uartx,unsigned char mode)
{
	
	unsigned char i,j,k,m,n;
	unsigned char *p,*head,*rail;
	unsigned char ok;
	struct FindCommand_Result *pc;
	
	i=j=k=m=n=ok=0;
	head=(unsigned char *)&CommHead[uartx];
	rail=(unsigned char *)&CommReal[uartx];
	
	if(uartx<3)
	{
		p=(unsigned char*)&CommB[uartx]; 
		pc=(struct FindCommand_Result *)&cx[uartx]; 
	}
	else
	{
		p=&Co.b[500]; 
		pc=(struct FindCommand_Result *)&Co.b[500]; 
	}
	
	Meter_States.ErrOfInformation.byte=0;
	farinfrareddisableflag=0;	
	if(mode==DL_PROTOCOL)
	{
		if(IntoPowerDownFlag)
		{
			if(((pc->c)!=0x01) && ((pc->c)!=0x02) && ((pc->c)!=0x11)&& ((pc->c)!=0x12) 
                && ((pc->c) != 0x03)&& ((pc->c) != 0x13))
			{
				(pc->c)=0xff;   
			}
		} 
		if(uartx==0x01)
		{
			if(((pc->c==0x0C)||(pc->c==0x17)))
			{
				(pc->c)=0xff;   
			}
			if((O1ther_Meter_Parameter.WorkRoomState==0)&&((IntoPowerDownFlag!=0)||(Far_InfraredFlag==0)))
			{
				if (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)
				{
					farinfrareddisableflag=1;
					if((pc->c==0x05)||(pc->c==0x08)||(pc->c==0x15))
				  	{
					  (pc->c)=0xff;   
				  	}
				}
   
			}
		}     
		if(uartx==0x02)
		{
			if(!Meter_Parameter.parameter1.MeterMode[0].bit.b3)
			{
				if(((pc->c)!=0x01) && ((pc->c)!=0x02) && ((pc->c)!=0x0A) && ((pc->c)!=0x0C)
					&& ((pc->c)!=0x11) && ((pc->c)!=0x12)&& ((pc->c)!=0x13)
			        	&& ((pc->c)!=0x15) && ((pc->c)!=0x17)&& ((pc->c)!=0x08)
			        	&& ((pc->c)!=0x1F) && ((pc->c)!=0x9F) && ((pc->c)!=0x14))//GANJP 20090701	//payment
				{
					(pc->c)=0xff;   
				}
				if(((pc->c)==0x14) && (pc->id.l!=0x4001301)&&(pc->id.l!=0x04001503))/*"串口二没有放开设置参数的情况下允许显示在线状态和信号强度"*/
					{
						(pc->c)=0xff;  
					}
			}
		}
  	   if(!IntoPowerDownFlag){
  	   	if(auxiliary_power_flag==0){
  	   	  if((VoltageGreaterThanThreshold_Flag==0)&&(uartx==0x01)){
  	   		  (pc->c)=0xff;
  	   	  }
  	   	  if((VoltageGreaterThanCritical_Flag==0)&&(O1ther_Meter_Parameter.WorkRoomState==0)
  	   		  &&((uartx==0x00)||(uartx==0x02))&&(MACRO_LOCAL_PAY_FLAG)){
  	   		  (pc->c)=0xff;
  	   	  }
  	    }
  	   }  //add by pc 081227
	   /*" 当不为度后续帧时候清读后续标志 "*/	 
		if(pc->c!=0x12)
		{
		    Iterate_Tree_Flag[uartx].flag.bit.b0=0;
		    Iterate_Tree_Flag[uartx].flag.bit.b5=0;
		}
			
       if((pc->c>=0x01)&&(pc->c<=0x1D)&&(pc->c!=0x03)&&(pc->c!=0x06)&&(pc->c!=0x07)&&(pc->c!=0x1C))
       {
            if(!((pc->c>=0x09)&&(pc->c<=0x10)))
            {
               if(pc->BroadCasrAddress==0)
                    R_To_T_DelayT_Add[uartx]=GetNowTime(); 
            }
       }
		if(O1ther_Meter_Parameter.WorkRoomState!=0)		/*"读写时都要用到"*/
			Comm_Staut.meter_staut=0x11;/*"工厂状态"*/
		else Comm_Staut.meter_staut=0x33;/*"现场 状态"*/
		
		switch(pc->c)
		{
			case 0x01:  
	      case 0x1F://GANJP 20090701
			case 0x02: ReadData(uartx);break;
	      case 0x03: Far_Prepayment_Read_Write(uartx);break;	//payment
			case 0x04: WriteData(uartx);break;
			case 0x05: JustMeter(uartx);break;	      
			case 0x08: BroadcastJustTime(uartx);break;
			case 0x11:
                        switch(pc->id.l)
                           {
                               case 0x04040300:
                                HZ_LCDQueryCmd( uartx);   
                                break;
                                default: 
                                {
                                        Event_Report_Iterate_flag=1;
                                        Event_Report_reread_flag=1;
                                        ReadData_New(uartx); 
                                } 
                            } 
                        break;
			case 0x12: 
                        {
                                Event_Report_Iterate_flag=1;
                                ReadData_New(uartx);
                        }
                        break;
			case 0x13: ReadAddress_New(uartx);break;//change by fxf   081127
			case 0x14: WriteData_New(uartx);break;
			case 0x15: WriteAddress_New(uartx);break;//change by fxf   081127
			case 0x16: Freeze_Command_New(uartx);break;
			case 0x17: WriteBaud_New(uartx);break;//change by fxf   081127
			#ifdef  PASSWORD_MODE
			case 0x18: WritePassword_New(uartx);break;	//change fxf   pc 081127
			#endif
			case 0x19: ClearDemand_New(uartx);break;//change by fxf   081127
			case 0x1A: ClearMeter_New(uartx);break;//change by fxf  081127
			case 0x1B: ClearEvent_New(uartx);break;	//change by fxf   081127
	      case 0x1C: Far_Control(uartx);break;	//payment
	        case 0x1D: Set_Multi_Function_Terminal_Output(uartx);break;
//	      case 0x9F: CarryConfirm(uartx);break;	//payment
			default:   cx[3].ct=0;break;
		}
		n=0;
		if(cx[3].ct)
		{
			p[n++]=0x68;
			for(i=1;i<7;i++)
				p[n++]=Meter_Parameter.parameter1.BcdCommAddr[uartx][i-1];
			p[n++]=0x68;
			p[n++]=(cx[3].ct);
	      
			if(!(cx[3].c==0x05))
			{
      
       i=0;
       switch(cx[3].ct)
       {
        case 0x92:
        case 0xB2:
              i =1;
        case 0x91:
        case 0xB1:
        case 0x83:
        case 0xBC:
        case 0xBD:
              i +=2;
        case 0x81:
        case 0xA1:
        case 0x82:
        case 0xA2:
        case 0x9F:
					p[n++]=cx[3].lena+2+i;
					p[n++]=cx[3].id.d[0]+0x33;
					p[n++]=cx[3].id.d[1]+0x33;
          if(i)
           {
           	p[n++]=cx[3].id.d[2]+0x33;
           	p[n++]=cx[3].id.d[3]+0x33;
           }
          break;
          default:
					p[n++]=cx[3].lena;
          break;
                                                
        }
        
				k=0;
				for(i=0;i<cx[3].lena;i++)
					p[n+i]+=0x33;

				if((cx[3].ct==0x92)||( cx[3].ct==0xB2))/*"     后续帧    "*/
				{
					p[n+i]=cx[3].Frame_serial+0x33;
					n++;	
				}
				k=0;
			}
			else
			{
				p[n++]=cx[3].lena;
			}

			for(i=0;i<n+cx[3].lena;i++)
				k+=p[i];
			p[cx[3].lena+n++]=k;
			p[cx[3].lena+n++]=0x16;  
			*head=0;
			*rail=cx[3].lena+n;
			if(*rail>=B_L)
				Init_Comm(uartx);
			else
			{  
				switch(uartx)
				{
					case 0x00: RE_DE0=0;break;
	            case 0x01: ta1s=1; break;  //open pwm
					case 0x02: RE_DE1=0;break;
				}
	      	 
				//R_To_T_DelayT_Add[uartx]=GetNowTime(); 
			}
		}
	   
	   else if(!cx[3].ct)
		{
			Init_Comm(uartx);
		}
	}
	
	
	return 0;
}
//liuyq added 2009-8-18 start
unsigned int SpecialTimeWR(unsigned char* RamDataAddr,//the data ram address
									  unsigned char* SRDataAddr,//the data send or read address
									  unsigned char DataLen)//the data length
{
	Co.c.addrr[0]=RamDataAddr;
	Co.c.flag1.byte=0x09;
	Co.c.com.byte=0x01;
	Co.c.len=DataLen;
	Co.c.rw=0;
	Co.c.addr5=SRDataAddr;
	R_W_Data();
	return cx[3].lena;
}


unsigned int TransferLostVData(unsigned char StartFlag,
										unsigned char Mode,
										unsigned char* DataBuff )
{
	unsigned int i,j,n,m,addr;

    if(!StartFlag)
		addr = 141;
	else
		addr = 0;
	
	switch(Mode)
	{
		case 0x00:
			if((!StartFlag)&&
				(Event_Power_Net_Flag.bit.LostVoltage_A||Event_Power_Net_Flag.bit.LostVoltage_B||Event_Power_Net_Flag.bit.LostVoltage_C)
            		 )
			{      	
                		for(j=0;j<6;j++)
                    			Co.b[300+j]=0; 
           		 }
			else
			{
			for(i=0;i<3;i++)
			{
				n=0;
				//m=*((unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P+i);		
				//n=i*32+GetRecordAddr(m,0,32);
				WRLC256(LASTLOSTVOLT_A_ROM+255L*i+addr,&Co.b[300+i*6],6,0,1);
				//if(Read_File(n,addr,6,(unsigned char *)&Co.b[300+i*6])==0)
				//{
				//	for(j=0;j<6;j++)
				//		Co.b[300+i*6+j]=0x0;
				//}										    
				if(Check_Data_valid((unsigned char *)&Co.b[300+i*6],6)==-1)
				{
					for(j=0;j<6;j++)
						Co.b[300+i*6+j]=0x0;
				}
			}

			for(j=1;j<3;j++)
			{
				for(i=0;i<6;i++)
				{
					if(Co.b[300+6*j+i]>Co.b[300+i])
					{
						for(m=0;m<6;m++)
						{
							Co.b[300+m]=Co.b[300+6*j+m];
						}	
						break;	
					}
					else if(Co.b[300+6*j+i]<Co.b[300+i])
					{						    
						break;
					} 
				}
			}

			}
			
			break;
		default:
			if(Mode>3)
				return -1;
                 if((!StartFlag)&&
				((Event_Power_Net_Flag.bit.LostVoltage_A&&Mode==1)||
				(Event_Power_Net_Flag.bit.LostVoltage_B&&Mode==2)||
				(Event_Power_Net_Flag.bit.LostVoltage_C&&Mode==3)))
            		 
			{      	
                		for(j=0;j<6;j++)
                    			Co.b[300+j]=0; 
           		 }
		else{
			n=0;	
			//if(Mode==0x01)
			//	m=Event_Power_Net_Pointer.LostVoltage_A_P;
			//else if(Mode==0x02)
			//	m=Event_Power_Net_Pointer.LostVoltage_B_P;
			//else	
			//	m=Event_Power_Net_Pointer.LostVoltage_C_P;
			//n=(Mode-1)*32+GetRecordAddr(m,0,32);
			//if(Read_File(n,addr,6,(unsigned char *)&Co.b[300])==0)
			//{
			//	for(j=0;j<6;j++)
			//		Co.b[300+j]=0x0;
			//}				
			WRLC256(LASTLOSTVOLT_A_ROM+255L*(Mode-1)+addr,&Co.b[300],6,0,1);

			if(Check_Data_valid((unsigned char *)&Co.b[300],6)==-1)
			{
				for(j=0;j<6;j++)
					Co.b[300+j]=0x0;
			}
		}
			
			break;
	}
	for(j=0;j<6;j++)
		Co.b[306+j]=Co.b[305-j];
	return SpecialTimeWR((unsigned char*)&Co.b[307], DataBuff,4);
}

//liuyq added 2009-8-18 end
/******************************************************************************************/

/******************************************************************************************
*     1. import:id-the data code                                                          *
*               p-data address                                                            *
*               L-data length                                                             *
*               point-number of point of data                                             *
*               mode-0-read,1-write                                                       *
*               formatdata-ask data format                                                *
*               format-return data format address                                         *
*               Co.c.flag1.b0-hex,b1-bcd,b2-ask,b3-ram,b4-ee,b5-e1,b6-e2,b7-e3            *
*               Co.c.flag2.b0-1(data reverse),0-(no data reverse)                         *
*               Co.c.com. b0-1(have)0(no),b1,b2,b3 so,b4-1(p)0-(n),b5,b6,b7 so            *
*    2. output: the length of return data                                                 *
*******************************************************************************************/
//---return data length,0-error-------------
signed int  TransferData(union ID id,unsigned char *P, unsigned int L,
                         unsigned char formatdata,unsigned char *format,     unsigned char mode)
{
	unsigned char afg; 
	signed int    result;
	unsigned int  i,j,k,m,n;
	unsigned long datac;
	unsigned long datad;
	unsigned char wdatalen=0;
	unsigned char W_R_Length=0;
	
	for(i=0;i<500;i++)
	   Co.b[i]=0; 
	   
	wdatalen=L+6;
	ChenkPasserwordFlag=0;
	
	afg=0;
	result=255;
	i=j=k=m=n=0;
	datac=datad=0;
	
	*format=formatdata;
	
	Co.c.rw=mode;
	Co.c.addr5=P;
	afg=id.d[0]&0x0F;
	if(mode)
	{
		//if(id.i!= 0xC052)
			return -1;
	}
#if 0	
//-----------ganjp 20090701-------
	if (FLAG_CARRIER_MODEL)
		{
		if(id.i == 0x02af)		/*"东软(AF02)"*/
			{
			for (i=0;i<6;i++)
				Co.b[500+i]=Meter_Parameter.parameter1.BcdCommAddr[2][i];
			Co.c.addrr[0]=(unsigned char *)&Co.b[500];
			Co.c.flag1.byte=0x09;
			Co.c.com.byte=0x01;
			Co.c.len=6;
			if (FLAG_CARRIER_MODEL && (EVENT_OCCUR_DEFINE==1))		//model
				{
				for (i=0;i<10;i++)
					Co.b[506+i]=GPRS_Event_Status[i].byte;
				Co.c.len+=10;
				}
			Co.c.rw=0;
			Co.c.addr5=P;
			R_W_Data();
		 	return Co.c.len;
			}
		else if(id.i == 0xF365)		/*"鼎信(65F3)"*/
			{
			for (i=0;i<6;i++)
				Co.b[500+i]=Meter_Parameter.parameter1.BcdCommAddr[2][i];
			Co.c.addrr[0]=(unsigned char *)&Co.b[500];
			Co.c.flag1.byte=0x09;
			Co.c.com.byte=0x01;
			Co.c.len=6; 
			Co.c.rw=0;
			Co.c.addr5=P;
			R_W_Data();
			return 6;
			}
		}
//-----------ganjp 20090701-------
#endif
/***********************************************************************************/
/*            "较表命令"                                                            
/***********************************************************************************/	
	switch(id.d[1]&0xF0)
	{	
		case 0x00:
	          if(cx[3].c!=0x05)
	                return -1;
	          switch(id.d[1]&0x0F)
			{
			    case 0x07:
				    if(!O1ther_Meter_Parameter.WorkRoomState)
					       return  -1;
			          j=99;
			          for(i=0;i<6;i++)
			          {
			                if(*(Co.c.addr5+1+i)!=WorkroomPasswordClear[i])
			                      j=0;
			          }
			          if(j)
			          {
						      O1ther_Meter_Parameter.JustMeter=0;
						      WRLC256(JUSTMETER_ROM,(unsigned char *)&O1ther_Meter_Parameter.JustMeter,1,0,0); 
//						      Set_Meter_para_Deal(JUSTMETER_ROM);
			            FeedWatchdog();                                       
					
			            m=OTHER_DATA_ROM;
			            n=0;
			            while(m<PAY_EEPROM_DEFINE_EE)
			            {
							     if((m+1024)<PAY_EEPROM_DEFINE_EE)
								     n=1024;
							     else
								     n=PAY_EEPROM_DEFINE_EE-m;
	                 WRLC256(m,0,n,0,0); //add protect
                   FeedWatchdog(); 
	                 m=m+n;                                       	                                              
			            }                                            
			                
	  		 					VoltStatSetDefault();
	  		 					Clear_Freeze_Period();
	  		 					FeedWatchdog();
	  		 					Fs_Init();             
	  		 					FeedWatchdog();
				 ////////////////////////////// //
			            prcr|=0x02;
			            pm0=0xc8;         //single chip mode,PM03 is soft reset bit
			            Co.c.len=0;
			            Co.c.rw=1;
			            JustMeterDataFlag.bit.b4=1;
			            JustMeterFlag=0xff;
			          }
			          break; 

			    default:
			          return -1;
			}
	          break;
/***********************************************************************************/  
/*            "炬力计量芯片校表命令"                                                 
/***********************************************************************************/ 
		case 0x20:
		          if(cx[3].c!=0x05)
				return -1;
		          switch(id.d[1]&0x0F)
			{
			         case 0x00:                                                                        
					 if((cx[3].len!=0x06))
				             return -1;
         
				         if(!O1ther_Meter_Parameter.WorkRoomState)
				         {
				          return -1;
				         }
         
				          if(!fgMeter_Com_Process(P, (P+1), P+2, &Co.b[500]))
				             return -1; 

					Co.c.len=0;
					Co.c.rw=1;
					JustMeterDataFlag.bit.b2=1;
					JustMeterFlag=0xff;
					break;
				case 0x03:
				case 0x07:
					{
					      if(!fgMeter_Com_Process(P, P+1, P+2, &Co.b[500]))
							            return -1;
					      Co.c.addrr[0]=(unsigned char *)&Co.b[500];
						Co.c.flag1.byte=0x09;
						Co.c.flag2.byte=0x01;
						Co.c.com.byte=0x01;
						Co.c.len=4;
						Co.c.rw=0;
	                                        
				         }
				         break;
			         case 0x04:
	            
				      if(id.d[0] == 0x01)
				      	{
					      	Co.c.h[0]=I_REGION;
				                Co.c.h[1]=V_REGION;
				                //Co.c.h[2]=Meter_Parameter.VI_Regulation[2];
				                Co.c.addrr[0]=(unsigned char *)&Co.c.h[0];
				                Co.c.flag1.byte=0x09;
				                Co.c.com.byte=0x01;
				                Co.c.len=2;
				                Co.c.rw=0;
				      	}
				      	else
				      	{
				      		return -1;
				      	}
	                
					break;
				case 0x06:
					switch(id.d[0])
					{
						case 0xAA:
						case 0xAB:
						case 0xAC://GANJP 20090820
							fgMeter_Com_Process(P, (P+1), P+2,&Co.b[500]);
							Co.c.addrr[0]=(unsigned char *)&Co.b[500];
							Co.c.flag1.byte=0x09;
							Co.c.com.byte=0x01;
							Co.c.len=sizeof(struct JUSTMETER_PARAMETER);
							Co.c.rw=0;
							break;
			//---------debug 20101015------------------
						case 0xad:						
					           {
					          	unsigned int sta_addr = 0;
					          	unsigned int len = 0;  
					          	unsigned char data_len = 0;
					          	
					          	if(!O1ther_Meter_Parameter.WorkRoomState)
							          return  -1;
							          
					          	  sta_addr = *((unsigned int *)P+1);
					          	  len = *((unsigned int *)P + 2);  
					          	  if(len%128 == 0) 
					          	  	{
					          	  		n = len/128;
					          	  	}  		
					          	  else
					          	  	{
					          	  		n = len/128 + 1;
					          	  	}		
					                for(i=0;i<n;i++)
				 	              {
					 	                Meter_Parameter.parameter1.Commrate[0].bit.B9600=1;
					 	                Init_Comm(0);
					 	                if(i!= (n-1))
					 	                	data_len = 128;
					 	                else
					 	                	data_len = (len%128);
					 	                if(data_len == 0)
					 	                	data_len = 128;
					                    WRLC256(sta_addr+i*128,(unsigned char *)&CommB[0],data_len,0,1);  
				                     
						               	FeedWatchdog();
					                  CommHead[0] = 0;
					                  CommReal[0] = data_len;
					                  R_DelayT_Add[0]=GetNowTime();
					                  T_DelayT_Add[0]=GetNowTime();
					                 	        
						               	re_u0c1=0;
					                  te_u0c1=1;
						               	RE_DE0=0;
						               	Delay(1);

						               		u0tbl=CommB[0][CommHead[0]];//0xFE; //after send data,clear buffer
					                    CommHead[0]++;
					                    Delay(320);
					                  FeedWatchdog();        
				                  }
				                }
					          break;
					          case 0xae:
					          	Co.c.addrr[0]=(unsigned char *)&Parameter_flag;
							Co.c.flag1.byte=0x09;
							Co.c.com.byte=0x01;
							Co.c.len=5;
							Co.c.rw=0;
						          break;
					          case 0xaf:
					          	Co.c.addrr[0]=(unsigned char *)&para_err_times;
							Co.c.flag1.byte=0x09;
							Co.c.com.byte=0x01;
							Co.c.len=2;
							Co.c.rw=0;
						          break;
	        //---------debug 20101015------------------
						default:
							return -1;
							break;
					}
					break;
				case 0x05:
					//liuyq modify 2009-8-19 start
					switch(id.d[0])
					{
					    case 0x04:
					          Co.c.addrr[0]=(unsigned char *)&Active_power[0];					          
					          break;
					    case 0x08:
					         Co.c.addrr[0]=(unsigned char *)&Reactive_power[0];
					          break;
					    case 0x0d:
					    case 0x0e:
					    case 0x0f:
					          Co.c.addrr[0]=(unsigned char *)&Voltc[(id.d[0]&0x0f)-0x0d];
					          break;
					    case 0x10:
					    case 0x11:
					    case 0x12:
					          Co.c.addrr[0]=(unsigned char *)&Curr[(id.d[0]&0x0f)];
					          break;
					    case 0x01:
					    case 0x02:
					    case 0x03:
					          Co.c.addrr[0]=(unsigned char *)&Active_power[(id.d[0]&0x0f)];
					          break;  
					    case 0x05:
					    case 0x06:
					    case 0x07:
					          Co.c.addrr[0]=(unsigned char *)&Reactive_power[(id.d[0]&0x0f)-0x04];
					          break;
				//----debug ganjp 20090321-----------------------------
				              case 0x2b:
				                  Co.c.addrr[0]=(unsigned char *)&temperatrue;
				                  Co.c.flag2.byte=0x01;
				                  break;
				//----debug ganjp 20090321-----------------------------
				              default:
					              return -1; 
						  break;
					   }
				          Co.c.flag1.byte=0x0A;
				          Co.c.com.byte=0x01;
				          Co.c.flag2.byte=0x01;
				          Co.c.len=4;
				          Co.c.rw=0;
					break;    
			          default:  
				  	return -1;  
					break;
		       }                      
		     break;	 	      

/***********************************************************************************/
/*            "读本月、上月、上上月电量"                                            
/***********************************************************************************/ 	   
       //---------------0x9010--------	 	   
		case 0x90:              //9010
			Co.c.flag4.bit.b0=1;
			if(Meter_Parameter.parameter2.EnergyPoint<=2) 
			{
				Co.c.calnumber=1;
				Co.c.flag3.byte=0x01;
			}   
			switch(id.d[1]&0x0F)
			{
				case 0x00:
					if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; //liuyq added 2009-8-19
					switch(id.d[0]&0xF0)
					{
						 //---------------0x9010--------
						case 0x10:
							Co.c.addrr[0]=(unsigned char *)&This_Month_Data.Energy_Record.Plus_Active+afg*4;
							Caarr(0,Co.c.addrr[0],0,0);
                        Co.c.flag1.byte=0x0A;
							if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1)   //TF 
							{
								Co.c.flag3.bit.b3=1;
								Co.c.flag3.bit.b4=1;
								Co.c.com.byte=Meter_Parameter.parameter1.Activem_Erengy_Mode.byte;  
							}
							else Co.c.com.byte=0x01;
							break;
						//---------------0x9020------------
						case 0x20:
							Co.c.addrr[0]=(unsigned char *)&This_Month_Data.Energy_Record.Nega_Active+afg*4;
                         Co.c.flag1.byte=0x0A;
					       Co.c.com.byte=0x01;
							break;
	         
						default: 
							return (-1);//liuyq added 2009-8-19
					}
					//Co.c.flag1.byte=0x0A;
					//Co.c.com.byte=0x01;
					break;
	      //------------------0x9110-----------
				case 0x01:
					if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1;//liuyq added 2009-8-19 
					k=0;
					switch(id.d[0]&0xF0)
					{
						 //---------------0x9110-----------
					   case 0x10:
					   //---------------0x9120-----------
					   case 0x20:
						   Co.c.addrr[0]=(unsigned char *)&This_Month_Data.Energy_Record.Quad_Reactive[0]+afg*4;
						   Caarr(0, Co.c.addrr[0],0,1);
						   if((id.d[0]&0xF0)==0x10)
						      Co.c.com.byte=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
						   else  Co.c.com.byte=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;  
							Co.c.flag3.bit.b3=1;
							Co.c.flag3.bit.b4=1;
						   break;
					   //--------------- 0x9140-----------
					   case 0x40:
									k++;
					   //---------------0x9160------------
					   case 0x60:
									k++;
					   //---------------0x9150------------
					   case 0x50:
									k++;
					   //---------------0x9130------------
					   case 0x30:
						   Co.c.addrr[0]=(unsigned char *)&This_Month_Data.Energy_Record.Quad_Reactive[k]+afg*4;
						   Co.c.com.byte=0x01;
						   //Co.c.len=4;//liuyq delete 2009-8-19
							//liuyq modify 2009-8-25 end
						   break;
					   //---------------
					   default:
					   	   return -1;//liuyq modify
					   //result=-1;break;//2009-8-18
					}
					Co.c.flag1.byte=0x0A;//liuyq added 2009-8-19
					//Co.c.len=4;//liuyq added 2009-8-19
					break;
	      
	//---------------0x9410------------
				case 0x04:
	//---------------0x9810------------
				case 0x08:
	      if((id.d[1]&0x0F)==0x04) n=1;
	      else if((id.d[1]&0x0F)==0x08) n=2;
					if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; //liuyq added 2009-8-19
					switch(id.d[0]&0xF0)
					{
					 //---------------0x9410,0x9810------------
						case 0x10:
							Co.c.addre[0]=ENERGY_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_Addr,n,MAXMONTHSAVE)*sizeof(struct ENERGY_RECORD)+afg*4;
							Caarr(Co.c.addre[0],0,0,0);
							Co.c.flag1.byte=0x32;
							if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1)   //TF 
							{
								//============================
								Co.c.flag3.bit.b3=1;
								Co.c.flag3.bit.b4=1;
								//============================								
								Co.c.com.byte=Meter_Parameter.parameter1.Activem_Erengy_Mode.byte;	
							}
							else Co.c.com.byte=0x01;			
							break;
						//---------------0x9420,0x9820------------
						case 0x20:
							Co.c.addre[0]=ENERGY_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_Addr,n,MAXMONTHSAVE)*sizeof(struct ENERGY_RECORD)+4*MAXTRIFF+afg*4;
							Co.c.flag1.byte=0x32;
							Co.c.com.byte=0x01;
							break;
						//---------------
						default:
							return -1;// liuyq modify 
						//result=-1;break;//2009-8-18
					}
					//Co.c.flag1.byte=0x32;
					//Co.c.com.byte=0x01;
					break;
	      
	//---------------0x9510,0x9910------------
				case 0x05:
	//------------------
				case 0x09:
          if((id.d[1]&0x0F)==0x05) n=1;
          else if((id.d[1]&0x0F)==0x09) n=2;
             if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 
					k = 0;//liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{
						 //---------------0x9510,0x9910------------
						case 0x10:
						//---------------0x9520,0x9920------------
						case 0x20:
							Co.c.addre[0]=ENERGY_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_Addr,n,MAXMONTHSAVE)*sizeof(struct ENERGY_RECORD)+2*4*MAXTRIFF+afg*4;
							Caarr(Co.c.addre[0], 0,0,1);
							//Carr((unsigned int)Co.c.addre[0],1,0);
							//Co.c.flag1.byte=0x32;//liuyq delete 2009-8-18
							if((id.d[0]&0xF0)==0x10)
							   Co.c.com.byte=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
							else  Co.c.com.byte=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte; 
							//Co.c.len=4;//liuyq delete 2009-8-18
							Co.c.flag3.bit.b3=1;
							Co.c.flag3.bit.b4=1;
							break;
						//liuyq modify 2009-8-20 start
						
						//---------------0x9540,0x9940------------
						case 0x40:
							k++;
						//---------------0x9560,0x9960------------
						case 0x60:
							k++;
						//---------------0x9550,0x9950------------
						case 0x50:
							k++;
						case 0x30:							
							
							Co.c.addre[0]=ENERGY_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_Addr,n,MAXMONTHSAVE)*sizeof(struct ENERGY_RECORD)+(2+k)*4*MAXTRIFF+afg*4;
							//Co.c.flag1.byte=0x32;//liuyq delete 2009-8-18
							Co.c.com.byte=0x01;
							//Co.c.len=4;//liuyq delete 2009-8-18
							break;
						//---------------
						default: 
							return -1;// liuyq modify 
						//result=-1;break;//2009-8-18
					}
					Co.c.flag1.byte=0x32;//liuyq add 2009-8-18
					break;
				//------------------
			default: result=-1;break;
		}
		Co.c.len=4;//liuyq added 2009-8-19
		break;
	   
	/***********************************************************************************/
	/*            "本月、上月、上上月需量"                                              */
	/************************************************************************************/ 	
	//---------------0xA010----------
	case 0xA0:  //a010
		if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; //liuyq added 2009-8-19
		switch(id.d[1]&0x0F)
		{
			unsigned char *pointdemand;
			n = 0;//liuyq added 2009-8-20
			case 0x00:
				switch(id.d[0]&0xF0)
				{
					//---------------0xA020----------
					case 0x20:
						n++;
            	       pointdemand=((unsigned char *)&This_Month_Data.Demand_Record.Demand.Plus_Active+n*9*MAXTRIFF+afg*9);
						datac=*((unsigned long*)pointdemand);
						{
						  datac=datac/100l;
						    Co.c.len=3;
						}
						Co.c.addrr[0]=(unsigned char *)&datac;
						Co.c.flag1.byte=0x0A;
						Co.c.com.byte=0x01;
                     break;
					//---------------0xA010----------
					case 0x10:
					//liuyq modify 2009-8-20 end
						//if(afg>Meter_Parameter.SlotParemeter[0].TriffNumble)  return -1; //liuyq delete 2009-8-19
					datac=This_Month_Data.Demand_Record.Demand.Plus_Active[afg].Demand;
					datac=datac/100l;  
					if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1)//TF 
					{           
						//pointdemand=((unsigned char *)&This_Month_Data.Demand_Record.Demand.Plus_Active+n*9*MAXTRIFF+afg*9);
						datad=This_Month_Data.Demand_Record.Demand.Nega_Active[afg].Demand;
						datad=datad/100l;							
						if(datac<datad)
						{
						    datac=datad;
						}					
					}
          			   Co.c.len=3;
						Co.c.addrr[0]=(unsigned char *)&datac;
						Co.c.flag1.byte=0x0A;
						Co.c.com.byte=0x01;
		            	Co.c.rw=0; 
		            	Co.c.addr5=P;						
						break;
				//---------------
					default: //result=-1;break;//liuyq modify 2009-8-19
						return (-1);//liuyq modify 2009-8-19
				}
				break;
		//---------------0xA110----------
				case 0x01:
					//k=0x05;//liuyq added 2009-8-20  Co.c.com.byte=Meter_Parameter.REActivem_Erengy_1_Mode.byte;
					switch(id.d[0]&0xF0)
					{
						
						case 0x20:
							//k <<= 4;
						//---------------0xA110----------
						case 0x10:
							if((id.d[0]&0xF0)==0x10) k=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
							else if((id.d[0]&0xF0)==0x20) k=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
						
							math_Demand((unsigned char *)&This_Month_Data.Demand_Record.Demand.Quad_Reactive[0][afg],(unsigned char *)&Co.c.f[0],k,0,4,9*MAXTRIFF, RAM_MATH);
							datac=*((unsigned long*)&Co.c.f[0]);
							{
							datac=datac/100l;
							 Co.c.len=3;
							}
							Co.c.addrr[0]=(unsigned char *)&datac;
							Co.c.flag1.byte=0x0A;
							Co.c.com.byte=0x01;
							break;
						//---------------
						default: //result=-1;break;//liuyq modify 2009-8-19
							return (-1);//liuyq modify 2009-8-19
					}
					break;			
				case 0x08:
					n=2;
			//---------------0xA410----------
				case 0x04:
					n=1;
 					k = 0; //liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{
						
						//---------------0xA420-0xA820---------
						case 0x20:
              	       k++;
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,n,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+k*9*MAXTRIFF+afg*9;
							Co.c.flag1.byte=0x32; //=================
							{
							 Co.c.calnumber=2;
							 Co.c.flag3.byte=0x01;
							}
							Co.c.com.byte=0x01;
							Co.c.len=3;  
							Co.c.rw=0; 
							Co.c.addr5=P;
							R_W_Data();				
							datac=Demandtempbuffer;							
							if(datac==0x00ffffff)
							{
								datac=0x00ffffff;
								*((unsigned long*)(P+0))=datac;
							}	
							return Co.c.len=3;
              			break;
						//---------------0xA410-0xA810---------
						case 0x10:
					if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1) //TF 
 							{
 							k = 0; 
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,n,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+k*9*MAXTRIFF+afg*9;
							Co.c.flag1.byte=0x32;
							{
							 Co.c.calnumber=2;
							 Co.c.flag3.byte=0x01;
							}
							Co.c.com.byte=0x01;
							Co.c.len=3;
	            					Co.c.rw=0; 
	            					Co.c.addr5=P;
	            					R_W_Data();	
							cx[3].lena-=3;	
							datac=0;
							datac=*((unsigned long*)(P+0));
							*((unsigned char *)&datac+3)=0;
							FeedWatchdog();
 							k = 1; 
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,n,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+k*9*MAXTRIFF+afg*9;
							Co.c.flag1.byte=0x32;
							{
							 Co.c.calnumber=2;
							 Co.c.flag3.byte=0x01;
							}
							Co.c.com.byte=0x01;
							Co.c.len=3;
	            					Co.c.rw=0; 
	            					Co.c.addr5=P+4;
	            					R_W_Data();	
							datad=0;
							datad=*((unsigned long*)(P+4));	
							*((unsigned char *)&datad+3)=0;
							if(datac>=datad)
							{
								*((unsigned long*)(P+0))=datac;
							}
							else
							{
								*((unsigned long*)(P+0))=datad;
							}
							datad=0;
							datac=Demandtempbuffer;
							if(datac==0x00ffffff)
							{
								datac=0x00ffffff;
								*((unsigned long*)(P+0))=datac;
							}
							return Co.c.len;
 							}
							else 
							{
	 							k = 0; 
								Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,n,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+k*9*MAXTRIFF+afg*9;
								Co.c.flag1.byte=0x32;
								{
								 Co.c.calnumber=2;
								 Co.c.flag3.byte=0x01;
								}
								Co.c.com.byte=0x01;
								Co.c.len=3;
		            			Co.c.rw=0; 
								Co.c.addr5=P;
								R_W_Data();	
								datac=Demandtempbuffer;
								if(datac==0x00ffffff)
								{
									datac=0x00ffffff;
									*((unsigned long*)(P+0))=datac;
								}									
								return Co.c.len;
							}
							break;
						//---------------
						default: //result=-1;break;//liuyq modify 2009-8-19
							return (-1);//liuyq modify 2009-8-19
					}
					break;
				
				//---------------0xA910---------
				case 0x09:
					n=2;
				//---------------0xA510---------
				case 0x05:
					n=1;
				//liuyq modify 2009-8-20 end
					//k=0x05;//liuyq added 2009-8-20	
 					switch(id.d[0]&0xF0)
					{
						
						//---------------0xA520-0xA920---------
						case 0x20:
							//k <<= 4;
						//---------------0xA510-0xA910---------
						case 0x10:
	                      if((id.d[0]&0xF0)==0x10) k=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
							else if((id.d[0]&0xF0)==0x20) k=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,n,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+2*9*MAXTRIFF+afg*9;
							math_Demand((unsigned char *)&Co.c.addre[0],(unsigned char *)&Co.c.f[0],k,0,4,9*MAXTRIFF,EEPROM_MATH);
							datac=*((unsigned long*)&Co.c.f[0]);
							//Co.c.flag1.byte=0x32;
							//Co.c.com.byte=0x01;
							Co.c.addrr[0]=(unsigned char *)&datac;
							Co.c.flag1.byte=0x0A;
							Co.c.com.byte=0x01;
							Co.c.flag3.byte=0x01;

						{
							 Co.c.calnumber=2;
							 //Co.c.flag3.byte=0x01; //liuyq delete 2009-8-19
						}
							Co.c.len=3;
							//=================added by mw 2010-08-02 begin
							Co.c.rw=0; 
							Co.c.addr5=P;
							R_W_Data();	
							datad=0;
							datac=Demandtempbuffer;							
							if(datac==0x00ffffff)
							{
								datac=0x00ffffff;
								*((unsigned long*)(P+0))=datac;
							}
							return Co.c.len;
							//=================end 								
							break;
			//---------------
					default: //result=-1;break;//liuyq modify 2009-8-19
						return (-1);//liuyq modify 2009-8-19
					}
					break;

				//------------------
				default: //result=-1;break;//liuyq modify 2009-8-19
					return (-1);//liuyq modify 2009-8-19
			}
			break;
	   

/***********************************************************************************/
/*            "本月、上月、上上月需量时间"                                                        */
/************************************************************************************/
       //----------0xB010------------------
		case 0xB0:         //b010
			if(formatdata==0x00 || formatdata==MMDDhhmm)   
			{ 
				if(!formatdata) 
				{
					n=1; k=4;
				}
			}
			if(formatdata==YYMMDD) {n=0;k=3;}
			else if(formatdata==MMDD) {n=1;k=2;}
			else if(formatdata==hhmm) {n=3;k=2;}
			switch(id.d[1]&0x0F)
			{   
			    unsigned char *pointdemand;   //mw added 2010-06-09
				case 0x00:
					m = 0;//liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{
						
						case 0x10:
						 //----------0xB010------------------
                     if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 						

                     datac=This_Month_Data.Demand_Record.Demand.Plus_Active[afg].Demand;
					   datac=datac/100l;  
                    m=0;
					   if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1) //TF 
					  {           
						//pointdemand=((unsigned char *)&This_Month_Data.Demand_Record.Demand.Plus_Active+n*9*MAXTRIFF+afg*9);
						datad=This_Month_Data.Demand_Record.Demand.Nega_Active[afg].Demand;
						datad=datad/100l;							
						if(datac<datad)
						{
                         m=1;
						}					
					}
							//if(afg>Meter_Parameter.SlotParemeter[0].TriffNumble)  return -1; 
							Co.c.addre[0]=THISM_DEMAND_RECORD+m*9*MAXTRIFF+afg*9+4+n;
							Co.c.flag1.byte=0x31;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
							Co.c.addr5=P;
							Co.c.rw=0; 
						

							
							break;
             
						case 0x20://----------0xB020------------------
						//liuyq modify 2009-8-20 end
							m=1;
							if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 
							Co.c.addre[0]=THISM_DEMAND_RECORD+m*9*MAXTRIFF+afg*9+4+n;
							Co.c.flag1.byte=0x31;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
							break;
						//---------------
						default: result=-1;break;
					}
					break;
	      //----------0xB110------------------
				case 0x01:
					//i=0x05;//liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{
						
						 //----------0xB110------------------
						//----------0xB120------------------
						case 0x20:
							//i <<= 4;
						case 0x10:
							if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1;
							if((id.d[0]&0xF0)==0x10) i=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
							else if((id.d[0]&0xF0)==0x20) i=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
						//liuyq modify 2009-8-20 end
							Co.c.addre[0]=THISM_DEMAND_RECORD+2*9*MAXTRIFF+afg*9;
							math_Demand((unsigned char *)&Co.c.addre[0],(unsigned char *)&Co.c.f[0],i,0,4,9*MAXTRIFF,EEPROM_MATH);
							Co.c.addrr[0]=(unsigned char *)&Co.c.f[4+n];
							Co.c.flag1.byte=0x09;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
							break;
	         
						//---------------
						default: result=-1;break;
					}
					break;

				//----------0xB410------------------
				case 0x04:
				//----------0xB810------------------
				case 0x08:
					if((id.d[1]&0x0F)==0x04) i=1;
					else if((id.d[1]&0x0F)==0x08) i=2;
					//liuyq modify 2009-8-20 start
					j=0;//liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{						 
						//----------0xB420-0xB820-----------------
						case 0x20:
							j++;
                        if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,i,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+j*9*MAXTRIFF+afg*9+4+n;
							Co.c.flag1.byte=0x31;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
 							break;                           
						 //----------0xB410-0xB810-----------------
						//liuyq modify 2009-8-20 end
						case 0x10:
						if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 
							if(Meter_Parameter.parameter1.MeterMode[0].bit.b6==1) //TF 
							{
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,i,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+afg*9;
							Co.c.flag1.byte=0x32;
							{
							 Co.c.calnumber=2;
							 Co.c.flag3.byte=0x01;
							}
							Co.c.com.byte=0x01;
							Co.c.len=3;
	            					Co.c.rw=0; 
	            					Co.c.addr5=P;
	            					R_W_Data();	
							cx[3].lena-=3;	
							datac=0;
							datac=*((unsigned long*)(P+0));
							*((unsigned char *)&datac+3)=0;
							
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,i,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+9*MAXTRIFF+afg*9;
							Co.c.flag1.byte=0x32;
							{
							 Co.c.calnumber=2;
							 Co.c.flag3.byte=0x01;
							}
							Co.c.com.byte=0x01;
							Co.c.len=3;
	            					Co.c.rw=0; 
	            					Co.c.addr5=P+4;
	            					R_W_Data();	
							cx[3].lena-=3;	
							datad=0;
							datad=*((unsigned long*)(P+4));		
							*((unsigned char *)&datad+3)=0;
							if(datac>=datad)
							{
								j=0;								
							}
							else
							{
								j=1;
							}
							FeedWatchdog();
							}
							else
							{
								j=0;
							}
							
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,i,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+j*9*MAXTRIFF+afg*9+4+n;
							Co.c.flag1.byte=0x31;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
							Co.c.addr5=P;
							Co.c.rw=0; 	
							break;
						//---------------
						default: result=-1;break;
					}
					break;
	      
				//----------0xB510-----------------
				case 0x05:
				//----------0xB910-----------------
				case 0x09:
					if((id.d[1]&0x0F)==0x05) i=1;
					else if((id.d[1]&0x0F)==0x09) i=2;
					//liuyq modify 2009-8-20 start
					//j = 0x05; //liuyq added 2009-8-20
					switch(id.d[0]&0xF0)
					{						 
						//----------0xB520-0xB920-----------------
						case 0x20:
							//j <<= 4;
						 //----------0xB510-0xB910-----------------
						case 0x10:

						if((id.d[0]&0xf0)==0x10)
						{
						j=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
						}
						else if((id.d[0]&0xf0)==0x20) 
						{
						j=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
						}
							if(afg>Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)  return -1; 
							//liuyq modify 2009-8-20 start							
							Co.c.addre[0]=DEMAND_RECORD_ROM+GetRecordAddr(O1ther_Meter_Parameter.Bill_DM_Addr,i,MAXMONTHSAVE)*sizeof(struct DEMAND_RECORD)+2*9*MAXTRIFF+afg*9;
							math_Demand((unsigned char *)&Co.c.addre[0],(unsigned char *)&Co.c.f[0],j,0,4,9*MAXTRIFF,EEPROM_MATH);
							Co.c.addrr[0]=(unsigned char *)&Co.c.f[4+n];
							Co.c.flag1.byte=0x09;
							//Co.c.flag1.byte=0x31;
							Co.c.com.byte=0x01;
							Co.c.flag2.byte=0x01;
							Co.c.len=k;
							break;

						//---------------
						default: result=-1;break;
					}
					break;

				//------------------0xB214-----------
					case 0x02:     
						switch(id.d[0]&0xF0)
						{
							case 0x10:   //b210
								switch(id.d[0]&0x0F)
								{
									case 0x00:										
									case 0x01:
										
										Co.c.flag2.byte=0x01;
										if(formatdata==MMDDhhmm)//changed by gjp
										{
											if((id.d[0]&0x0F) == 0x01)
												SpecialTimeWR((unsigned char *)&Other_Data.LastClearDemandDateCM, P,5);
											else
												SpecialTimeWR((unsigned char *)&Other_Data.ProgramDate, P,5);
											return 5;
											//break;
						         }
						         else
						        {
											Co.c.addrr[0]=(unsigned char *)&Other_Data.ProgramDate+1;
											if((id.d[0]&0x0F) == 0x01)
												Co.c.addrr[0]=(unsigned char *)&Other_Data.LastClearDemandDateCM+1;
											Co.c.flag1.byte=0x09;
											//Co.c.com.byte=0x01;
											Co.c.flag2.byte=0x01;
											Co.c.len=4;
											break;	
										} 
										//liuyq modify 2009-8-18 end
									case 0x02:										
										Co.c.addrr[0]=(unsigned char *)&Event_Power_Net_Times.ProgrammeEvent_Times;
									case 0x03:
										
										if((id.d[0]&0x0F) == 0x03)
											Co.c.addrr[0]=(unsigned char *)&Event_Meter_Pro_Times.ClearDemandRecord_Times;
										Co.c.flag1.byte=0x0A;
										//Co.c.com.byte=0x01;
										Co.c.len=2;
										break;		
										//liuyq modify 2009-8-18 end
									case 0x04:
										
										Co.c.addrr[0]=(unsigned char *)&Other_Data.BatteryWorkTime1;
										Co.c.addre[1]=BATTERYWORKTIME1_ROM;
										Co.c.flag1.byte=0x3A;
										//Co.c.com.byte=0x01;
										Co.c.len=3;
										break;	
	
									default: 
									//result=-1;break; //liuyq delete 2009-8-20
										return (-1);//liuyq added 2009-8-20
								}
								Co.c.com.byte=0x01;
								break;                 
							default:  result=-1;break;	 
						}
						break;
              
					case 0x03:/*"-----最近一次失压起始时间------"*/
					  	switch(id.d[0]&0xF0)
						{
							case 0x10:
								switch(id.d[0]&0x0F)
								{
									case 0x00:
										i=Event_Power_Net_Times.LostVoltage_A_Times +
											  Event_Power_Net_Times.LostVoltage_B_Times +
											  Event_Power_Net_Times.LostVoltage_C_Times;
										break;
									case 0x01:
										i=Event_Power_Net_Times.LostVoltage_A_Times;
										break;
									case 0x02:
										i=Event_Power_Net_Times.LostVoltage_B_Times;
										break;
									case 0x03:
										i=Event_Power_Net_Times.LostVoltage_C_Times;
										break;										
									default:  
										return (-1);
								}
								HexToBcd(2,(unsigned char *)&i,P);
								//***********************************************/
								cx[3].lena+=2;
								return 2;//cx[3].lena;
								//***********************************************/
								break;
							case 0x20:
								switch(id.d[0]&0x0F)
								{
									case 0x00:
										//Refresh_AddTime(0x10000002);  //mw modified 2010-05-30
										//datac=(*((unsigned long *)&TempEventData[0]));
										
										datac=Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+
												Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks+
												Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks;
										break;
									case 0x01:
										//Refresh_AddTime(0x10010002);  //mw modified 2010-05-30
										//datac=(*((unsigned long *)&TempEventData[0]));										
										datac=Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks;
										break;
									case 0x02:
										//Refresh_AddTime(0x10020002);  //mw modified 2010-05-30
										//datac=(*((unsigned long *)&TempEventData[0]));										
										datac=Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks;
										break;
									case 0x03:
										//Refresh_AddTime(0x10030002);  //mw modified 2010-05-30
										//datac=(*((unsigned long *)&TempEventData[0]));										
										datac=Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks;
										break;
										
									case 0x04:
										//Refresh_AddTime(0x03050000);  //mw modified 2010-05-30
										//datac=(*((unsigned long *)&TempEventData[0]));										
									datac=Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks;
									break;
									default: //result=-1;break;//liuyq delete 2009-8-20
										return (-1);
								}
								HexToBcd(3,(unsigned char *)&datac,P);
								//********************************************/
								cx[3].lena+=3;
								return 3;//cx[3].lena;
								break;
							case 0x30:
								
								return TransferLostVData(1, id.d[0]&0x0F, P);
								//break;

              /*"----最近一次失压结束时间--------"*/
              case 0x40://-------b340--------
							
							return TransferLostVData(0, id.d[0]&0x0F, P);
							
						default: result=-1;break;
					}
					break;
              
				case 0x06:
					switch(id.d[0]&0xF0)
					{
						//------------------0xB610-0xB613-----------
						case 0x10:
							switch(id.d[0]&0x0F)
							{
								case 0x01:
								case 0x02:
								case 0x03:
									
									  datac=Volt[(id.d[0]&0x0F)-1]/10000l;
									  
									break;
								//------------
								default:
								//result=-1;break;//liuyq delete
									return (-1);//liuyq added 2009-8-19
							}
							break;
					//------------------0xB620-0xB623-----------
						case 0x20:
							switch(id.d[0]&0x0F)
							{
								case 0x01:
								case 0x02:
								case 0x03:
									
									  datac=Curr[(id.d[0]&0x0F)-1]/100l;
									Co.c.addrr[0]=(unsigned char *)&datac;
									Co.c.flag1.byte=0x0A;
									Co.c.com.byte=0x01;
									break;
								//------------
								default:
								//result=-1;break;//liuyq delete
									return (-1);//liuyq added 2009-8-19
							}
							break;
					//------------------0xB630-0xB633-----------
						case 0x30:
							switch(id.d[0]&0x0F)
							{
								case 0x00:	
								case 0x01:
								case 0x02:
								case 0x03:									
									{
									datac=Active_power[(id.d[0]&0x0F)]/100l;
									
									}	          
									break;
								case 0x04:
								case 0x05:	
									if((id.d[0]&0x0F)==0x04)
										datac=Meter_Parameter.event_parameter.PaADemandLimit;
									else
										datac=Meter_Parameter.event_parameter.NeADemandLimit;					
									datac=datac/100l;									
								default:
								//result=-1;break;//liuyq delete
									return (-1);//liuyq added 2009-8-19
							}
							break;
					//------------------0xB640-0xB643-----------
						case 0x40:
							switch(id.d[0]&0x0F)
							{
								case 0x00:	
								case 0x01:
								case 0x02:
								case 0x03:                   
                    {
									  datac=Reactive_power[(id.d[0]&0x0F)]/10000l;									  
									}
									break;
								//------------
								default:
								//result=-1;break;//liuyq delete
									return (-1);//liuyq added 2009-8-19
							}
							break;
						//------------------0xB650-0xB653-----------
						case 0x50:
							switch(id.d[0]&0x0F)
							{
								case 0x00:	
								case 0x01:
								case 0x02:
								case 0x03:									
									{
									datac=Factor[(id.d[0]&0x0F)]/1000l;									
									}	        
									break;
								//------------
								default:
									return (-1);//liuyq added 2009-8-19
							}
							break;
						default:
							return (-1);//liuyq added 2009-8-19
					}
					Co.c.addrr[0]=(unsigned char *)&datac;
					Co.c.flag1.byte=0x0A;
					Co.c.com.byte=0x01;
					Co.c.len=2;
					if(((id.d[0]&0xF0) == 0x30) && ((id.d[0]&0x0F)<0x04))
						Co.c.len=3;
					break;

              //------------------0xB710-0xB716-----------
              case 0x07:
              switch(id.d[0]&0xF0)
              	{
              		case 0x10:      //b350
              		switch(id.d[0]&0x0F)
              		{
                        
                    case 0x00:
                    case 0x01:
                    case 0x02:
                    case 0x03:
                    //Co.c.flag4.bit.b0=1;
					
                    m=0;
              	    if((id.d[0]&0x0F)==0x00)
                        {
                            datac=Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks;
                            datac+=Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks;
                            datac+=Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks;
                            datad=Event_Power_Net_Times.LostVoltage_A_Times;
                            datad+=Event_Power_Net_Times.LostVoltage_B_Times;
                            datad+=Event_Power_Net_Times.LostVoltage_C_Times;
                        }
                        else if((id.d[0]&0x0F)==0x01)
                        {
                            datac=Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks;
				   datad=Event_Power_Net_Times.LostVoltage_A_Times;		
                        }
                        else if((id.d[0]&0x0F)==0x02)
                        {
                            datac=Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks;
				   datad=Event_Power_Net_Times.LostVoltage_B_Times;
                        }
                        else if((id.d[0]&0x0F)==0x03)
                        {
                            datac=Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks;
				   datad=Event_Power_Net_Times.LostVoltage_C_Times;
                        }
                        HexToBcd(4,(unsigned char *)&datac,P);
				 HexToBcd(2,(unsigned char *)&datad,P+4);		
	                      //********************************************
	                      cx[3].lena+=6;
	                      return 6;//cx[3].lena;
	                      //********************************************
                      break;
	            
                    //------------
                    default:  result=-1;break;
                 }
					
              		break;
				default:  result=-1;break;	
              	}
			break;  
					
				//------------------
				default: result=-1;break;
			}
			break;
	   
	   
		/***********************************************************************************/
		/*"电表参数"*/
		/***********************************************************************************/
		//------------------0xC010-----------------
		case 0xC0:
			switch(id.d[1]&0x0F)
			{
				case 0x00:
					switch(id.d[0]&0xF0)
					{
						 case 0x10:
							 switch(id.d[0]&0x0F)
							{
								case 0x00:     //c010
										      	  
										if(!IntoPowerDownFlag)
										{ 
											for(n=0;n<3;n++)
												Co.c.h[3-n]=*((unsigned char*)&softdate+n);
											Co.c.h[0]=*((unsigned char*)&softdate+6); 
										}
										else if(!pdmode1 || (pdmode1 && !Meter_Parameter.parameter1.MeterMode[1].bit.b0))
										{
											// Read_Date_And_Time((unsigned char*)&Co.c.h+7,0);
											ClockChipRead((unsigned char *)(&Co.c.h+7));
											
											if(CheckTime((unsigned char *)(&Co.c.h[7])))
											{
											  for(n=0;n<3;n++)
											    Co.c.h[3-n]=Co.c.h[7+n];
											  Co.c.h[0]=Co.c.h[13];
											}
											else
											{
												for(n=0;n<3;n++)
											    Co.c.h[3-n]=*((unsigned char*)&Powerdown_Save_Data.date+n);
											  Co.c.h[0]=*((unsigned char*)&Powerdown_Save_Data.date+6);
											}
										}
										else if((pdmode1 && Meter_Parameter.parameter1.MeterMode[1].bit.b0))
										{
											 for(n=0;n<3;n++)
											    Co.c.h[3-n]=*((unsigned char*)&Powerdown_Save_Data.date+n);
											 Co.c.h[0]=*((unsigned char*)&Powerdown_Save_Data.date+6); 
										}
										Co.c.addrr[0]=(unsigned char *)&Co.c.h;
										Co.c.flag1.byte=0x09;
										Co.c.com.byte=0x01;
										Co.c.len=4; 
									break;	
								//------------------0xC011-----------------
								case 0x01:									
										if(!IntoPowerDownFlag)
										{ 
											Co.c.addrr[0]=(unsigned char*)&softdate+3;
										}
										else if(!pdmode1 || (pdmode1 && !Meter_Parameter.parameter1.MeterMode[1].bit.b0))
										{
										  //	Read_Date_And_Time((unsigned char*)&Co.c.h,0);
										  ClockChipRead((unsigned char *)&Co.c.h);
										  
											if(CheckTime((unsigned char *)(&Co.c.h[0])))
											   Co.c.addrr[0]=(unsigned char*)&Co.c.h+3;
											else
											   Co.c.addrr[0]=(unsigned char*)&Powerdown_Save_Data.date+3;
											
										}
										else if((pdmode1 && Meter_Parameter.parameter1.MeterMode[1].bit.b0))
										{
											Co.c.addrr[0]=(unsigned char*)&Powerdown_Save_Data.date+3;
										}


										Co.c.flag1.byte=0x09;
										Co.c.com.byte=0x01;
										Co.c.flag2.byte=0x01;
										Co.c.len=3; 
									break;
								default: result=-1;break;
							}
							 break;
						 //------------------0xC020-0xC021----------------
						 case 0x20:     //c020
							 switch(id.d[0]&0x0F)
							{
								case 00:	
									
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Meter_Status1.byte;
									}
									break;
								case 01:	
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.PowerNet_Status.byte;
									}
									break;
								case 02:	
									//	ProgramFlag[0].bit.b1=1;	      	      	      	                                                                              	      	            }
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.SlotParemeter[0]+7;
									Co.c.addre[0]=SLOTPAREMETER1_ROM+7;
									break;
									//************************************************************/
									case 03:	
									{
									union BYTE_BIT  modee1;									
									modee1.byte = 0xCA;
									modee1.bit.b0=Meter_Parameter.parameter1.MeterMode[1].bit.b2;
									modee1.bit.b5=Meter_Parameter.parameter1.MeterMode[1].bit.b4;
									for(i=0;i<6;i++)
										Co.b[500+i]=0;
									Co.b[500+6]=modee1.byte;   
									Co.c.addrr[0]=(unsigned char *)&Co.b[500];									
									}
									break;
								case 04:	
									{
									for(i=0;i<6;i++)
										Co.b[500+i]=0;  
									Co.b[500+6]=0x9F;//liuqy added 2009-8-19   
									Co.c.addrr[0]=(unsigned char *)&Co.b[500];
									}
									break;
								//************************************************************/
	            
								case 0x05:
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.LoadRecordMode;
									Co.c.addre[0]=LOADRECORDMODE_ROM;
									break;

								case 0x06:	
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Meter_Status2.byte;
									}
									break;
								case 0x07:	
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Meter_Status3.byte;
									}
									break;
								case 0x08:	
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Meter_Status4.byte;
									}
									break;

								default: //result=-1;break;
									return (-1);
							}
							 if(((id.d[0]&0x0F) == 2) || ((id.d[0]&0x0F) == 5))
							 	Co.c.flag1.byte=0x39;
							 else
								Co.c.flag1.byte=0x09;
							Co.c.com.byte=0x01;
							 if(((id.d[0]&0x0F) == 3) || ((id.d[0]&0x0F) == 4))
								Co.c.len=7;
							 else
								Co.c.len=1;
							break;
	      	 //------------------0xC030-0xC031----------------
	      	 case 0x30:     //c030
	      	 switch(id.d[0]&0x0F)
	      	 {
	      	    case 00:	
	      	    case 01:
	      	    Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.ActivePulseConst+(id.d[0]&0x0F)*4;
	      	    
	            {
	                Co.c.flag1.byte=0x0A;
	                Co.c.len=3;
	            }
	            Co.c.com.byte=0x01;
	            //------------------0xC032-0xC034----------------
	      	    break;
	      	    case 02:	
	      	    case 03:
	      	    case 04:
						      	    if(!formatdata)
						      	    {
								My_memcpyRev(&Readdata_buff[0],(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0]+((id.d[0]&0x0F)-2)*6,6);
								Co.c.addrr[0]=&Readdata_buff[0];	//payment
								Co.c.addre[0]=BCDMETERID_ROM+((id.d[0]&0x0F)-2)*6;
						              Co.c.flag1.byte=0x39;
						              Co.c.com.byte=0x01;
						              Co.c.len=6;
						              
						            }
	      	    break;
	      	   
	      	    default: result=-1;break;
	      	 }
	      	 break;
						 //------------------0xC040-0xC045----------------
						case 0x40:  //c040
							switch(id.d[0]&0x0F)
							{								  
								case 0x00:
								case 0x01:
								case 0x02:
								case 0x03:
								case 0x04:
								case 0x05:
									Co.c.addrr[0]=(unsigned char *)&Meter_States.Meter_Status1+(id.d[0]&0x0F);									   
								//------------------0xC046----------------
								case 0x06:
									if((id.d[0]&0x0F) == 6)
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Comm_Rate[cx[3].uartx];
									Co.c.flag1.byte=0x09;
									Co.c.com.byte=0x01;
									Co.c.len=1;
									break;      
								//------------------0xC047-0xC04D---------------
								case 0x07:
								case 0x08:
								case 0x09:
								case 0x0A:
								case 0x0B:								
									{	
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.MeterMode[(id.d[0]&0x0F)-7];
									Co.c.addre[0]=METERMODE1_ROM+(id.d[0]&0x0F)-7;									
									}
									//break;
								case 0x0C:		//payment
								case 0x0D:
									if (((id.d[0]&0x0F) >= 0x0C) && ((id.d[0]&0x0F) <= 0x0D))
										{
										Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.REActivem_Erengy_1_Mode+(id.d[0]&0x0F)-0x0C;
										Co.c.addre[0]=REACTIVEM_ERENGY_1_MODE_ROM+(id.d[0]&0x0F)-0x0C;
										}
							//------------------0xC04E---------------
								case 0x0E: 
									if((id.d[0]&0x0F) > 0x0D)
									{
										
										Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.LoadRecordMode;
										Co.c.addre[0]=LOADRECORDMODE_ROM;
//										ProgramFlag[1].bit.b2=1;
									}									
									Co.c.flag1.byte=0x39;
									Co.c.com.byte=0x01;
									Co.c.len=1;
									break;
								default:return -1;
							}
							break;	
					//------------add for parameter block deal----------------------
//						case 0x50:     //c050~c052
//	      	  switch(id.d[0]&0x0F)	
//	      	  {
//	      	  	case 0x00://block1 start addr and data len	
//	      	  		{
//	      	  			unsigned int addr1 = 0;
//	      	  			unsigned int addr2 = 0;
//	      	  			
//	      	  			addr1 = EEPROM_FLAG_ROM;
//	      	  			addr2 = YEARSLOT_ROM;
//	      	  			
//	      	  			if(!O1ther_Meter_Parameter.WorkRoomState)
//                     {
//                      return -1;
//                     }
//	      	  		  *((unsigned int *)P) = addr2;
//	      	  		  *((unsigned int *)P+1) = (addr1 - addr2);
//	      	  		}      	  		
//	      	  		
//	      	  		cx[3].lena += 4;
//								return 4;
//	      	  		break;
//	      	  	case 0x01://block2 start addr and data len
//	      	  		{
//	      	  			unsigned int addr1 = 0;
//	      	  			unsigned int addr2 = 0;
//	      	  			
//	      	  			addr1 = JUSTMETER_PARA_ROM;
//	      	  			addr2 = PAY_EEPROM_DEFINE_EE;
//	      	  			if(!O1ther_Meter_Parameter.WorkRoomState)
//                     {
//                      return -1;
//                     }
//	      	  		  *((unsigned int *)P) = addr2;
//	      	  		  *((unsigned int *)P+1) = (addr1 - addr2);
//	      	  		}
//	      	  		
//	      	  		cx[3].lena += 4;
//								return 4;
//	      	  		break;
//	      	  	case 0x02://read or write parameter 
//	      	  		{
//	      	  			unsigned int crc_cmp = 0;
//	      	  			unsigned int sta_addr = 0;
//	      	  			unsigned int len = 0;
//	      	  			
//	      	  			if(!O1ther_Meter_Parameter.WorkRoomState)
//                   {
//                    return -1;
//                   }
//                         
//	      	  			
//			          	
//	      	  			if(mode)
//	      	  			{	      
//	      	  				sta_addr = *((unsigned int *)P);
//			          	  len = *((unsigned int *)P+1);	  				
//			          	  			          	  
//			          	  if((len > 176) || (wdatalen > 188)) /*"一次最多写180个字节"
//			          		 return -1;
//			          		 
//			          		crc_cmp = CRC(P+4 ,len); 
//			          			 
//			          		if(crc_cmp == *((unsigned int*)(P+4+len)))
//			          			{
//			          				WRLC256(sta_addr,P+4,len,0,0);  /*"按照通信传输顺序，数据写内卡" 
//			          			}
//			          		else
//			          			{
//			          				return -1;
//			          			} 
//			          		return (1);                                  
//	      	  			}
//	      	  		else
//	      	  			{	
//	      	  				unsigned char buffer_data[4];
//	      	  				
//	      	  				for(i=0; i<4; i++)
//	      	  				{
//	      	  					buffer_data[i] = CommB[0][cx[0].addr+i]-0x33;
//	      	  				}
//	      	  						
//	      	  				sta_addr = *((unsigned int *)&buffer_data[0]);
//			          	  len = *((unsigned int *)&buffer_data[2]);          	  
//			          	  if(len > 176)
//			          	  	{
//			          	  		*((unsigned int *)P) = sta_addr;
//	      	  		        *((unsigned int *)P+1) = len;
//			          	  		cx[3].lena += 4;
//								        return 4;
//			          	  	}
//			          	  		
//			          	  	
//			          	  WRLC256(sta_addr,P,len,0,1);
//			          	  
//			          	  crc_cmp = CRC(P, len);
//			          	  
//			          	  *((unsigned int *)(P+len)) = crc_cmp; 
//			          	  
//			          	  cx[3].lena += (len+2);
//			          	  
//			          	  return (len+2);
//	      	  			}
//	      	  		}
//	      	  		
//	      	  		break;
//	      	  }
//	      	  break;	
	      	//------------add for parameter block deal----------------------			       	 
						default:  result=-1;break;
					}
					break; 
				case 0x01:
					switch(id.d[0]&0xF0)   //c110
					{
						 case 0x10:
							 switch(id.d[0]&0x0F)
							 {
								 case 0x01:
								 case 0x02: 
								 case 0x03: 
								 case 0x04: 				      	    
				      	    
							Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.DemandPeriod+(id.d[0]&0x0F)-1;
							Co.c.addre[0]=DEMANDPERIOD_ROM+(id.d[0]&0x0F)-1;	 
						//------------------0xC115-0xC116---------------
				      	    case 0x05: 
				      	    case 0x06: 
							if((id.d[0]&0x0F)>4)
							{
								Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.EnergyPoint+(id.d[0]&0x0F)-5;
								Co.c.addre[0]=ENERGYPOINT_ROM+(id.d[0]&0x0F)-5;
								
							}
					            Co.c.flag1.byte=0x3A;
					            Co.c.com.byte=0x01;
					            Co.c.len=1;
				      	    break;
				      	    //------------------0xC117---------------
				      	    case 0x07: 
					      	    
					      	    Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.AutoBillDayHour[0].Day;
					      	    Co.c.addre[0]=AUTOBILLDAYHOUR_1_ROM;
					            Co.c.flag1.byte=0x39;
					            Co.c.flag2.byte=0x01;
					            Co.c.com.byte=0x01;
					            Co.c.len=2;
				            
				      	    break;
				      	    
				      	    case 0x08: //-----C118--mw added 070515-----
					      	    
					      	    Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.LoadDay;
					      	    Co.c.addre[0]=LOADDAY_ROM;
					            Co.c.flag1.byte=0x39;
					            Co.c.com.byte=0x01;
					            Co.c.len=1;  
				      	    break;
							
				      	    case 0x09: //-----C119---mw added 070515----
								//liuyq modify 2009-8-19 start
								    
					      	    Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.PlusEnergyData;
					      	    Co.c.addre[0]=PLUSENERGYDATA_ROM; 	
				      	    case 0x0A: //-----C11A---mw added 070515----
								if((id.d[0]&0xF0)>9)
								{
									    
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.NegaEnergyData;
									Co.c.addre[0]=NEGAENERGYDATA_ROM;
								}
								 
						            Co.c.flag1.byte=0x39;
						            Co.c.com.byte=0x01;
						            Co.c.len=4;
					      	    break;					
					      	  	      	    
								//liuyq modify 2009-8-19 start
							//------------------
							default: result=-1;break;	
						 }
						 break; 
					//------------------0xC120-0xC124---------------
					case 0x20:
						switch(id.d[0]&0x0F)
						{
							case 0x01:
							case 0x02: 
							case 0x03:   //----------0xc123---------------------
							case 0x04: 
													      	    
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.DemandPeriod+(id.d[0]&0x0F)-1;
									Co.c.addre[0]=DEMANDPERIOD_ROM+(id.d[0]&0x0F)-1;
									Co.c.flag1.byte=0x3A;
									//Co.c.com.byte=0x01;
									Co.c.len=1;

									break; 	 
								//------------------0xC125-0xC126---------------
								case 0x05: 
								case 0x06:
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.EnergyPoint+(id.d[0]&0x0F)-5;
									Co.c.addre[0]=ENERGYPOINT_ROM+(id.d[0]&0x0F)-5;
									
									Co.c.flag1.byte=0x3A;
									//Co.c.com.byte=0x01;
									Co.c.len=1;
									break;
								//------------------0xC127---------------
								case 0x07: 
									
								Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.AutoBillDayHour[0].Day;
								Co.c.addre[0]=AUTOBILLDAYHOUR_1_ROM;
								Co.c.flag1.byte=0x39;
								Co.c.flag2.byte=0x01;
								//Co.c.com.byte=0x01;
								Co.c.len=2;

								break;
				      	    //------------------0xC128---------------
				      	    case 0x08: 
					      	    
					      	    Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.KeyDisplayNumber;
						      	    Co.c.addre[0]=KEYDISPLAYNUMBER_ROM;
						            Co.c.flag1.byte=0x3A;
														//Co.c.com.byte=0x01;
						            Co.c.len=2;
						            
					      	    break;
				      	    //------------------0xC129---------------
				      	    case 0x09: 
						      	    
						            if(formatdata)
						            {
						               union ERR_INFORM_FLG    Err_Infor1;	
						               Err_Infor1=Meter_States.Err_Infor;
						               Err_Infor1.bit.VoltageReserve=Err_Infor1.bit.Rtc_Err;
						               Err_Infor1.bit.LossVoltage=Err_Infor1.bit.OverPower;
						               Err_Infor1.bit.LossCurrent=Err_Infor1.bit.BreakPhase;
						               Err_Infor1.bit.BatteryClK_Err=0;
						               Err_Infor1.bit.BatteryDIS_Err=0;
						               Err_Infor1.bit.OverVoltage=0;
						      	       Co.c.addrr[0]=(unsigned char *)&Err_Infor1;
										
										Co.c.len=1;
									}
									else
									{
										Co.c.addrr[0]=(unsigned char *)&Meter_States.Err_Infor;
										//Co.c.flag1.byte=0x09;//liuyq delete 2009-8-19
										//Co.c.com.byte=0x01;//liuyq delete 2009-8-19
										Co.c.len=2;
									}
									Co.c.flag1.byte=0x09;
									break;

								default: 
									return -1;        //liuyq modify
								//result=-1;break; //2009-8-18	     
							}
							Co.c.com.byte=0x01;
							//liuyq modify 2009-8-19 end
							break; 

						default: result=-1;break;	
					}
					break;  
	      //------------------0xC211---------------
				case 0x02:   //c211
					switch(id.d[0]&0xF0)
					{
						case 0x10:
							switch(id.d[0]&0x0F)
							{
								case 0x01:
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.PulseWidth;
									Co.c.addre[0]=PULSEWIDTH_ROM;
									Co.c.flag1.byte=0x3A;
									Co.c.len=2;
									
									break;
	      	    //------------------0xC213---------------
//								case 0x03:
//									
//						      	    {	 
//										return -1;
//										for(n=0;n<4;n++)
//										{
//											HexToBcd(3,(unsigned char *)&Meter_Parameter.event_parameter.VoltageHealth_UpSet+n*4,&Co.c.h[n*3]);
//										}	
//										Co.c.addrr[0]=(unsigned char *)&Co.c.h;
//										Co.c.flag1.byte=0x09;
//										//Co.c.com.byte=0x01;
//										Co.c.len=12;
//									}
//									break;
								//------------------0xC214---------------
								case 0x04:
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.UserClass;
									Co.c.addre[0]=USERCLASS_ROM;
									Co.c.flag1.byte=0x39;
									//Co.c.com.byte=0x01;
									Co.c.len=1;
									
									break;
								//------------------0xC215-0xC216---------------
								case 0x05: 
								case 0x06: 
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.OpenSwitchDelayTime+(id.d[0]&0x0F)-5;
									Co.c.addre[0]=OPENSWITCHDELAYTIME_ROM+(id.d[0]&0x0F)-5;
									Co.c.flag1.byte=0x3A;
									//Co.c.com.byte=0x01;
									Co.c.len=1;
									
									break;
								//-------0xC217-----mw modified 070510----------
								case 0x07:
						      	    {	 
							      	       //HexToBcd(1,(unsigned char *)&Meter_Parameter.Meterlocktimes,&Co.c.h[0]);
							      	      Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter2.Meterlocktimes; 
										Co.c.addre[0]=METERLOCKTIMES_ROM;
										Co.c.flag1.byte=0x3A;
										//Co.c.com.byte=0x01;
										Co.c.len=1;
						      	    }
						      	    break;	


								//------------------
								default: 
									return -1;        //liuyq modify
								//result=-1;break; //2009-8-18	     
							}
							Co.c.com.byte=0x01;//liuyq added 2009-8-18

							break;   
						case 0x20:
							switch(id.d[0]&0x0F)
							{
								//------------------0xC220---------------
 
								//------------------0xC221--------------- 
								case 0x01:									
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr;
									Co.c.len=3;
									if(formatdata==NN_H)
										Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr+3;
									else if(formatdata!=NN_L)
										Co.c.len=6; 
									//liuyq modify 2009-8-18 end
									break;
									//------------------0xC222-0xC224--------------
								case 0x02:
								case 0x03:
								case 0x04:
			      	    
			      	    if((id.d[0]&0x0F)==0x03)
			      	       id.d[0]=0x24;																	
									Co.c.f[1]=0x12; Co.c.f[0]=0x00; 
									for(n=2;n<6;n++)
									{
										if(Meter_Parameter.parameter1.Commrate[(id.d[0]&0x0F)-2].byte & (1<<n))
										{   Co.c.f[1]=0x12*(n-1); break;  }
									}
									Co.c.addrr[0]=(unsigned char *)&Co.c.f[0];
									Co.c.len=2;
									break;
								//------------------0xC225-0xC226--------------
								case 0x05:
								case 0x06:
									
									Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[(id.d[0]&0x0F)-4];
									Co.c.len=3;
									if(formatdata==NN_H)
										Co.c.addrr[0]=(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[(id.d[0]&0x0F)-4]+3;
									else if(formatdata!=NN_L)
										Co.c.len=6; 
									//liuyq modify 2009-8-18 start
									break;
								default:
									return -1;        //liuyq modify
								//result=-1;break; //2009-8-18	     
							}
							Co.c.flag1.byte=0x09;//liuyq add 2009-8-18
							Co.c.com.byte=0x01;//liuyq add 2009-8-18
							break;   
						//------------------
						default: result=-1;break;	

					}
					break;  
				default: result=-1;break;	   
			}
			break;
	   default: result=-1;break;
	}        
        
	if(L)
	{
		if(Co.c.len>L)
		Co.c.len=L;
	}
	if(result>0)
	{
		if(Co.c.len)
		{   
			W_R_Length=Co.c.len;
			if(R_W_Data())
				return W_R_Length;    
			else return -1;   
		}
		else return 0;
	}
	else return result;
}
/******************************************************************************************/  


/******************************************************************************************
*     1. imput: p-whitch buffer                                                           *
*               addr-the base addr                                                        *
*               len-the number of data before addr                                        *
*******************************************************************************************/
unsigned char Cal_Cs(unsigned char *p,unsigned char addr,unsigned char len)
{
	unsigned char  i;
	unsigned char  cs;
	cs=0;
	for(i=0;i<len;i++)
	{
	   cs+=*(p+F_Ar(addr,i));
	}
	return cs;
}
/******************************************************************************************/



/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void ReadData(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok;
	struct FindCommand_Result *pc;
	unsigned int uni,unj;

	ok=0;
	uni=0;
	unj=0;
	
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	ok=0xff;
	for(uni=0;uni<500;uni++)
	  Co.b[uni]=0; 
	if(!(pc->firstreceivecomm))
	{
	   CalSendDataLength((unsigned char *)&cx[3]);
	   pc->firstreceivecomm=1;
	}
	
	if((((pc->id.i)&0x00ff)==0x00ff)
	||((farinfrareddisableflag==1)&&(!((((pc->id.i)&0xff00)==0x9000)||(((pc->id.i)&0xff00)==0x9100)
	||(pc->id.i==0xC010)||(pc->id.i==0xC011)||(pc->id.i==0xC221)||(pc->id.i==0xC225)||(pc->id.i==0xC226)||(pc->id.i==0xC032)))))
	{
	   ok=0;
	   pc->lena=pc->lent=0; 
	}
	else
	{
	  do
	  { 
	   for(uni=0;uni<500;uni++)
	      Co.b[uni]=0;      
	   if(TransferData(pc->idt,p+12+pc->lena,0,0,&datapoint,0)<0)
	      ok=0;
	   
	   CalSendLaterDataID((unsigned char *)&cx[3],uartx);   
	   unj++;
	      
	   }while(pc->lena<pc->lent && pc->lena<=195 && pc->lent && (!pc->readloadrecord) && unj<250);
	}	   
	if(!pc->readloadrecord)
	{
		if(pc->lent)
		{
			if(pc->lena>pc->lent)
				ok=0;
			else if(pc->lena==pc->lent )
				pc->havebackframe=0;
			else
			{
				pc->havebackframe=1;
				pc->lent=pc->lent-pc->lena;
			}
		}
		else
			pc->havebackframe=0;
		
		if(ok)
		{
			if(pc->havebackframe)
			{
				pc->ct|=0xA0;
				pc->havebackframe=0;
			}
			else
				pc->ct|=0x80;
		}
		else
		{
			pc->ct=0xC1; 
			Co.c.len=1;
			pc->lena=1;
			pc->lent=0;
			pc->havebackframe=0;
			
			if(farinfrareddisableflag==1)
			  Meter_States.ErrOfInformation.bit.Invalid_Password=1;
			else
			  Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			p[10]=Meter_States.ErrOfInformation.byte;         
		}
	}
	
	else
	{
		if(cx[3].lena)
		{
			pc->ct=0x81; 
		}
		else
		{
			pc->ct=0xC1; 
			pc->lent=0;
			Co.c.len=1;
			pc->lena=1;
			pc->havebackframe=0;
			p[10]=Meter_States.ErrOfInformation.byte;    
		}
	}
	  
	if(uartx < 3)
		cx[uartx] = cx[3];	   
} 

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"新645读数据"*/
void ReadData_New(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok,mode;
	struct FindCommand_Result *pc;
	unsigned int uni;
	signed int i_ret=0;
	unsigned int eventreportcnt;
    
	ok=0;
	uni=0;
	eventreportcnt=0;
    
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
	ok=0xff;
	/*"清缓冲"*/
	for(uni=0;uni<500;uni++)
		Co.b[uni]=0;
	
	pc->idt.l=pc->id.l; 

	if(pc->c==0x12)
	{		
			/*"后续帧序号不能为0 "*/
		if(pc->Frame_serial==0)		
		{
			Iterate_Tree_Flag[uartx].flag.bit.b0=0;/*" 清读后续标志 "*/
			Iterate_Tree_Flag[uartx].flag.bit.b5=0;
			ok=0;
		}
		else if(Iterate_Tree_Flag[uartx].Back_Flame_Serial==pc->Frame_serial)		
		{
			Iterate_Tree_Flag[uartx].flag.bit.b2=1;/*" 重新读上一帧数据标 "*/	
		}
		else if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)!=pc->Frame_serial)				
		{
			ok=0;		
		}
//----------------event report------------------------------- 
              /*"没有后续帧，或者不是重抄最后一帧，需返回事件上报状态字"*/
		 if(((0 == Iterate_Tree_Flag[uartx].flag.bit.b0) && (0 == Iterate_Tree_Flag[uartx].flag.bit.b5)&&(0==Iterate_Tree_Flag[uartx].flag.bit.b2)) 
		   || ((1 == Iterate_Tree_Flag[uartx].flag.bit.b5) && (0 == Iterate_Tree_Flag[uartx].flag.bit.b2))
		   ||((1 == Iterate_Tree_Flag[uartx].flag.bit.b2)&&(2==Event_Report_reread_flag)))
		{
			/*"事件需要上报,将数据标识变为事件主动上报状态字数据标识"*/
			if((Event_Report_flag == 0xff)&&(Event_Report_Iterate_flag==1)&&(Pre_Payment_Para.Pay_For_Users_Flag11.bit.EVENT_REPORT_MODE_SELECT == 1)
			&&((1==Event_Report_reread_flag)||((1 == Iterate_Tree_Flag[uartx].flag.bit.b2)&&(2==Event_Report_reread_flag))))
			{
				pc->idt.l = 0x04001501;
				cx[3].id.l = 0x04001501;
				Event_Report_reread_flag=2;
			}
			else
			{
				Iterate_Tree_Flag[uartx].flag.bit.b2=0;
				ok=0;
			}
		}
//----------------event report------------------------------- 
		mode=0x01;	
	}
	/*"取数，考虑后续帧"*/	      
	else	
	mode=0x00;
	/*"读取负荷曲线时的参数数据"*/
	if((cx[3].len>=4)&&(cx[3].len<=14))
	{
		for(uni=0;uni<cx[3].len-4;uni++)
		{    
			cx[3].command[0+uni]=*(p+cx[3].addr)-0x33;
			if(cx[3].addr>=B_FL-1)
				cx[3].addr=0;
			else cx[3].addr++;  
		}
	}
	else
			ok=0x0;

    //if((pc->idt.l>=0x04000C01)&&(pc->idt.l<=0x04000C0A))
    //{/*"用户抄读电表密码返回密码错\未授权"*/
    //      ok=0;
    //      Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
    //}
    if((farinfrareddisableflag==1)&&(!((pc->idt.l==0x04000401)||(pc->idt.l==0x04000402)||(pc->idt.l==0x04800004)
    ||(pc->idt.l==0x04000101)||(pc->idt.l==0x04000102)||(pc->idt.l==0x0400010C)||(pc->idt.l==0x00900201)||(((pc->idt.l)&0xff0000ff)==0))))
    {
    	ok=0;
      Meter_States.ErrOfInformation.bit.Invalid_Password=1;
    }
	
	if(ok==0xff) 
	{
		/*"   电量需量历史数据块抄 "*/
		if(((pc->idt.d[3]==0x00)||(pc->idt.d[3]==0x01))&&(pc->idt.d[0]==0xff)&&(pc->idt.d[1]!=0xff)&&(pc->idt.d[2]!=0xff))			
		{
			for(uni=0;uni<=0x0c;uni++)
			{
				pc->idt.d[0]=uni;
				i_ret+=TransferData_New(pc->idt,p+14+i_ret,F_SIZE,COMMFORMAT,&datapoint,mode,pc->len,uartx);
			}
		}
        /*"电网(备案)事件历史数据块抄 "*/
		else if(((pc->idt.d[3]>=0x10)&&(pc->idt.d[3]<=0x20))&&(pc->idt.d[0]==0xff)&&((pc->idt.d[1]>=0x01)&&(pc->idt.d[1]<=0x35))&&(pc->idt.d[2]<=0x03))			
		{
			for(uni=0x01;uni<=0x0A;uni++)
			{
				pc->idt.d[0]=uni;
				i_ret+=TransferData_New(pc->idt,p+14+i_ret,F_SIZE,COMMFORMAT,&datapoint,mode,pc->len,uartx);
			}
		}
		else
			i_ret=TransferData_New(pc->idt,p+14,F_SIZE,COMMFORMAT,&datapoint,mode,pc->len,uartx);
        
        if((0x04001501 == pc->idt.l ) && (i_ret >0))
        {
            *(p+26)=0xAA;/*"主动上报状态字后填写AAH作为块分隔码"*/
            eventreportcnt++;
            for(uni = 0; uni < 96; uni++)
            {
                 /*"当某事件发生时事件主动上报状态相应位置位，"*/
                /*"保证该事件结束后只要该状态字未抄读，"*/
                /*"该事件状态需保持，抄读后复位"*/
               if(Event_Report_Status.byte[uni>>3] & (0x01 << (uni & 0x07)))
               {
                  if(*((unsigned char *)&Event_Report_Status_Times + uni))
                  {
                  *(p+26+eventreportcnt)=*((unsigned char *)&Event_Report_Status_Times + uni);
                  eventreportcnt++;
                  }
               }
            }
            
               {
                  *(p+26+eventreportcnt)=0xAA;/*"主动上报事件1新增次数至主动上报事件N新增次数计为1个数据块，在主动上报事件N新增次数后填写AAH作为块分隔码"*/
                  eventreportcnt++;
               }
             
            i_ret += eventreportcnt ;

            if(!IntoPowerDownFlag)/*"防止低功耗下可以抄读主动上报状态字导致写EE，低功耗下只能抄读，不能发复位命令"*/
            {
              if(CompareBytes(&Event_Report_Status_communication.byte[0],&Event_Report_Status.byte[0],12)!=0)
              {
                for(uni=0; uni<12; uni++)
                {
                  Event_Report_Status_communication.byte[uni] = Event_Report_Status.byte[uni] ;
                }
                WRLC256(EVENT_REPORT_STATUS_COMM_ROM,(unsigned char *)&Event_Report_Status_communication,sizeof(union EVENT_REPORT_STATUS),0,0);
              }
              
              O1ther_Meter_Parameter.EventReport_RunTime=0;
            
              if(O1ther_Meter_Parameter.ResetEventReport_flag!=1)
              {
                O1ther_Meter_Parameter.ResetEventReport_flag=1;
                WRLC256(RESETEVENTREPORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.ResetEventReport_flag,1,0,0);
              }
            }
        }
	}
	
	if(i_ret==0)/*"取数失败"*/
		ok=0;
	else
	 	pc->lena=i_ret;/*"保存取数的长度"*/  

	      
	  
	if((Iterate_Tree_Flag[uartx].flag.bit.b0==1) && ok) 
	{	
		if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)==pc->Frame_serial) 
			Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
		pc->havebackframe=1;			
	}
	else if((Iterate_Tree_Flag[uartx].flag.bit.b5==1) && ok)
	{
	       if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)==pc->Frame_serial) 
			Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
		if((Event_Report_flag == 0xff)&&(Event_Report_Iterate_flag==1))/*"有事件上报时后续帧的最后一帧数据后面跟事件上报状态字数据"*/
		{
		if(Pre_Payment_Para.Pay_For_Users_Flag11.bit.EVENT_REPORT_MODE_SELECT == 1)
		{
		       pc->havebackframe=1;	
		}			
		}
		else
		{
			pc->havebackframe=0;	
		}
		
	}
	else if((Event_Report_Iterate_flag==1)&&(Event_Report_flag == 0xff) && ok)/*"有事件上报时抄读数据后面跟事件上报状态字数据后续帧"*/
	{
	if(Pre_Payment_Para.Pay_For_Users_Flag11.bit.EVENT_REPORT_MODE_SELECT == 1)
	{
		if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)==pc->Frame_serial) 
			Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
		 pc->havebackframe=1;
	}	       			
	}
	else       
	{	
		pc->havebackframe=0;
	}		
	if(ok)
	{
		if(pc->havebackframe)
		{
			pc->ct|=0xA0;/*"有后续应答"*/
			pc->havebackframe=0;
		}
		else
			pc->ct|=0x80;/*"正确应答"*/
	}
	else if(!pc->readloadrecord)
	{
		pc->ct|=0xC0; /*"错误应答"*/
		Co.c.len=1;
		pc->lena=1;
		pc->lent=0;
		pc->havebackframe=0;
		if(Meter_States.ErrOfInformation.byte==0)
			Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		p[10]=Meter_States.ErrOfInformation.byte;         
	}

	if(pc->readloadrecord && (!cx[3].lena))
	{
		pc->ct|=0x80; /*"负荷曲线错误应答"*/
		pc->lena=0;
		pc->havebackframe=0;   
	}			
	if(uartx<3)
	   cx[uartx]=cx[3];	   
}   

/********************************************************************/

/*******************************************************************/
void CheckProgramKeyState(void)
{     
   
   if(O1ther_Meter_Parameter.WorkRoomState)  
	 { 
		 Show_flash_falg.bit.keystoke=1;
   }
	 else
	 { 
		 Show_flash_falg.bit.keystoke=0;
   }
   
   if(Far_InfraredFlag==0)
   {
     Show_flag.bit.keystoke=0;
   }
   else
   {
   	 Show_flag.bit.keystoke=1;
   }
   
   Program_Key_Flag=0;
        		
}

/******************************************************************************************/



/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void WriteData(unsigned char uartx)
{
	unsigned char *p;
//	unsigned char ok;
	struct FindCommand_Result *pc;
//	unsigned int uni;
//	ok=0;
//	uni=0;
//		
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
//	//liuyq modify 2009-8-21 end
//	for(uni=0;uni<200;uni++)
//		WriteDateBuff[uni]=0; 
//	for(uni=0;uni<pc->len-2;uni++)
//	{
//		*((unsigned char *)&WriteDateBuff[0]+uni)=*(p+(pc->addr))-0x33;
//		(pc->addr)++;
//		if((pc->addr)>=B_FL) (pc->addr)=0;	  
//	}
//	
//    ok=0xff;
//    cx[3].passerword=99;
//	if(!O1ther_Meter_Parameter.WorkRoomState)	
//	{
//	    ok=CheckPasswordRight((unsigned char *)&WriteDateBuff[0]);
//	     		
//	    if(ok<=9)/*"密码正确"*/
//	    {
//	        if(!(Other_Data.PasswordErr[ok].flag))
//	        {
//	            cx[3].passerword=ok; 
//	            Clear_PasswordErr(1,ok);		    
//                ok=0xff;
//            }
//            else/*"密码闭锁返回权限不够"*/
//            {
//                ok=0;
//            }
//	    } 
//        else /*"密码级别超范围OR密码级别在范围内但是密码错误"*/
//	    {
//           if(ok!=0xff)/*"密码级别在范围内但是密码错误"*/
//            CheckPasswoerErr(ok&0x7f);
//           ok=0;
//           Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
//	    }
//	}
//	
//	if(!Program_Key_Flag  && !O1ther_Meter_Parameter.WorkRoomState)         
//	         ok=0;
//	
//	user_level=ok; //mw added 070515
//	if((ok) && (TransferData(pc->id,(unsigned char *)&WriteDateBuff[4],cx[3].len-6,0,&datapoint,1)>=0) )// && Program_Key_Flag)
//	{
//	        
//	   
//	   //Clear_PasswordErr(1);
//	   
//	   if( ((pc->id.i)!=0xc712) && ((pc->id.i)!=0xc713)  && ((pc->id.i)!=0xc010) && ((pc->id.i)!=0xc011))
//	   {
//	   //Event_Meter_Program_Flag.Programme=1;
//	   //Event1(0);
//	   //if(!ProgramEventFlag)
//	   //{
//	   //   ProgramEventDate=softdate;
//	   //   ProgramEventFlag=0xff;
//	   //}
//	     ProgrammeEvent(0xFFFFFFFF,0xFFFF0000+pc->id.i);  //change by pc 081214
//	   }
//	   Seg();
//	   FindTriff();
//	   //if(((pc->id.i)==0xc130) || ((pc->id.i)==0xc131) || ((pc->id.i)==0xc132))
//	   //{
//	    //  Set_show_code_list(pc->id.i);
//	      //WRLC256(CYCLEDISPLAYSWITCH_ROM,(unsigned char *)&Meter_Parameter.CycleDisplaySwitch,6,0,0);
//	      //WRLC256(CYCLEDISPLAYSWITCH_ROM,(unsigned char *)&Meter_Parameter.CycleDisplaySwitch,6,1,0);
//	  // }//delete by zlp because the function of Set_show_code_list is null
//	   pc->ct=0x84;
//	   Co.c.len=0;
//	   pc->lena=0;
//	}
//	else  
	{
	   pc->ct=0xC4; 
	   Co.c.len=1;
	   pc->lena=1;
	   p[10]=Meter_States.ErrOfInformation.byte;
	}
} 

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"新645写数据"*/
void WriteData_New(unsigned char uartx)
{  
	unsigned char *p;
	unsigned char ok,i;
	struct FindCommand_Result *pc;
	unsigned int uni;
	signed int i_ret=0;
	unsigned char result;
    
	ok=0xff;
	uni=0;
		
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
	for(uni=0;uni<200;uni++)
	   WriteDateBuff[uni]=0; 
	/*"密码比对"*/
	for(uni=0;uni<pc->len-4;uni++)   //fxf  2->4
	{ 
		*((unsigned char *)&WriteDateBuff[0]+uni)=*(p+(pc->addr))-0x33;
		(pc->addr)++;
		if((pc->addr)>=B_FL) (pc->addr)=0;	  
	}

	for(i=0;i<4;i++)
		*((unsigned char*)&(pc->Programer_code)+i)=WriteDateBuff[4+i];/*"操作者代码FXF"*/
		
	/*"写数"*/	    
	pc->idt.l=pc->id.l;  
	
	if((pc->idt.l == 0x04800001)||(pc->idt.l == 0x04800004))/*"软件版本号 软件备案号"*/
	{
		farinfrareddisableflag=0;
	}  
    
	if((farinfrareddisableflag==0))
	{
	 result=Far_Password_Check(pc->idt.d,(unsigned char *)&WriteDateBuff[0],(unsigned char *)&(pc->len));
	 if((result==OK)||(pc->idt.l == 0x04800001)||(pc->idt.l == 0x04800004))
	 {
        if (pc->idt.l == 0x04001006) {/*"退费金额"*/
            ProgrammeEvent(pc->Programer_code,pc->id.l);
            pc->ct=0x94;
            Co.c.len=0;
            pc->lena=0;
            return;
        }
	    		Comm_Staut.password_level=99;
		if( Far_Spec_Order_Flag != 0xFF ) 
		{
			if((!O1ther_Meter_Parameter.WorkRoomState)&&(pc->idt.l!=0x04001301)&&(pc->idt.l!=0x04001503))	
			{
			ok = 0;
			#ifdef  PASSWORD_MODE
			    ok=CheckPasswordRight((unsigned char *)&WriteDateBuff[0]);
			     		
			    if(ok<=9)/*"密码正确"*/
			    {
			          if(!(Other_Data.PasswordErr[ok].flag))
				     {
				            cx[3].passerword=ok; 
			                Comm_Staut.password_level=ok;
				            Clear_PasswordErr(1,ok);		    
			                ok=0xff;
			            }
			            else/*"密码闭锁"*/
			            {
			                ok=0;
			                //Meter_States.ErrOfInformation.bit.Invalid_Password=1;
			            }
			    } 
		        else /*"密码级别超范围OR密码级别在范围内但是密码错误"*/
			    {
			           if(ok!=0xff)/*"密码级别在范围内但是密码错误"*/
			            CheckPasswoerErr(ok&0x7f);
			           ok=0;
			           Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
			    }
			#endif
                            			   
		       if((pc->idt.l == 0x04800001)||(pc->idt.l == 0x04800004))/*"软件版本号 软件备案号"*/
		       {
		       if((WriteDateBuff[0]==0x02)&&(WriteDateBuff[1]==0x99)&&(WriteDateBuff[2]==0x99)&&(WriteDateBuff[3]==0x99))
		       {
		       	 ok = 0xFF;
		       }
		       else
		       {
		       	 Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
		       }
		       }
						
			}
		else
			ok = 0xFF;
		}
		else
		{
		if((pc->idt.l == 0x04800001)||(pc->idt.l == 0x04800004))/*"软件版本号 软件备案号"*/
		{
		      ok = 0;
		      Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
		}
		}
        
		if(ok!=0)
			{
			#if 0
			if (FayMidefyFlag)	//FJ
				{
				if ((FayMidefyFlag&0xF0)==0xC0)
					{
					uni=FayMidefyFlag&0x0F;
					//Reverse_data(&WriteDateBuff[8],4);
					if ((uni<MAX_PASS_NUM) && (WriteDateBuff[8]<MAX_PASS_NUM) && (WriteDateBuff[8]>=uni))	/*"可修改对应级和对应级后的密码"*/
						{
						for(i=0;i<4;i++)
							{
							Meter_Parameter.parameter1.ClearPassword[WriteDateBuff[8]][i]=WriteDateBuff[8+i];
							}
						WRLC256(CLEARPASSWORD_ROM+WriteDateBuff[8]*4,(unsigned char *)&Meter_Parameter.parameter1.ClearPassword[WriteDateBuff[8]][0],4,0,0);
						Set_Meter_para_Deal(CLEARPASSWORD_ROM);
						Clear_PasswordErr(1,uni);	/*"清除对应密级的闭锁次数"*/
						i_ret=4;
						}
					else
						Meter_States.ErrOfInformation.bit.Invalid_Password=1;
					}
				else
					Meter_States.ErrOfInformation.bit.Invalid_Data=1;
				FayMidefyFlag=0;	/*"解决在远程修改密码后，掉电前再次设参后密码会被修改为错误值"*/
				}
			else
				#endif
				i_ret=TransferData_New(pc->idt,(unsigned char *)&WriteDateBuff[8],0,COMMFORMAT,&datapoint,0x02,pc->len,uartx);
			}
	  }
	  else
	  {
		  Meter_States.ErrOfInformation.bit.Invalid_Password=1; 
	  }
  }
  else
  {
  	Meter_States.ErrOfInformation.bit.Invalid_Password=1;
  }
	
	if(i_ret!=0) 	/*"写数成功"*/
	 {
	 	if((pc->id.l!=0x4001301)&&(pc->id.l!=0x0E000204)&&(pc->id.l!=0x04001503))//GANJP 20091127
	     ProgrammeEvent(pc->Programer_code,pc->id.l);	

       if((pc->id.l==0x04000106)||(pc->id.l==0x04000107)
       ||(pc->id.l==0x04000101)||(pc->id.l==0x04000102)||(pc->id.l==0x0400010C))
       {
         CheckChange(0,FOR_TRIFF_DATE);
	       CheckChange(0,FOR_DAILYSLOT_DATE);
       }
     
	   Seg();
	   FindTriff();
		 if(pc->id.l==0x4000301)
        set_cycle_num=1;
          //add start by zlp 09-12-17
    /* if(pc->id.l==0x04000106 || pc->id.l==0x04000101 ||pc->id.l==0x04000102 )
     {
          if(Meter_Parameter.parameter1.TriffSwitch.SwitchDate.Month!=0 && Meter_Parameter.parameter1.TriffSwitch.SwitchDate.Day!=0)
          {
               Meter_Parameter.parameter1.TriffSwitch.SwitchDate.Sec=0;
               if(ComTime((unsigned char *)&softdate,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.SwitchDate)>0)
		           {
		               Meter_Parameter.parameter1.TriffSwitch.DropProtectFlag=1;
			             WRLC256(DROPPROTECTFLAG_TRIFF_ROM,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.DropProtectFlag,1,0,0);//write parameter	
			             Set_Meter_para_Deal(DROPPROTECTFLAG_TRIFF_ROM);
               }	   
         }
     }
	   if(pc->id.l==0x04000107 || pc->id.l==0x04000101 ||pc->id.l==0x04000102 )
	   {
	      if(Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate.Month!=0 && Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate.Day!=0)
        {
               Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate.Sec=0;
               if(ComTime((unsigned char *)&softdate,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate)>0)
		           {
		               Meter_Parameter.parameter1.DailySlotSwitch.DropProtectFlag=1;
			             WRLC256(DROPPROTECTFLAG_DALIYSLOT_ROM,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.DropProtectFlag,1,0,0);//write parameter	
			             Set_Meter_para_Deal(DROPPROTECTFLAG_DALIYSLOT_ROM);			             
		           }
        }
	   }*/
	   //add end by zlp 09-12-17
	   pc->ct=0x94;
	   Co.c.len=0;
	   pc->lena=0;
	}
	else  /*"写数失败"*/
	{
	   pc->ct=0xD4; 
	   Co.c.len=1;
	   pc->lena=1;
	   if(Meter_States.ErrOfInformation.byte==0)
	   		Meter_States.ErrOfInformation.bit.Invalid_Data=1;
	   p[10]=Meter_States.ErrOfInformation.byte;
	}
}

/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void JustMeter(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok;//,data11 liuyq delete 2009-8-24
	struct FindCommand_Result *pc;
	unsigned int uni;

	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
	ok=0x00;
	
	
	
	if(!JustMeterFlag)
	{
	      JustMeterDateFlag=softdate;
	}
	
	for(uni=0;uni<500;uni++)
		Co.b[uni]=0; 

	for(uni=0;uni<pc->len;uni++)
	{
		WriteDateBuff[uni]=*(p+(pc->addr));
		(pc->addr)++;
		if((pc->addr)>=B_FL) (pc->addr)=0;	  
	}
	 
	pc->id.d[1]=WriteDateBuff[0];
	pc->id.d[0]=WriteDateBuff[1];
			 
	if((TransferData(pc->id,(unsigned char *)&WriteDateBuff[0],0,0,&datapoint,0)>=0))
	{
		pc->ct=0x85;
		if(Co.c.rw)
		{
			*(p+10+0)=0;
			pc->lena=0;      
		}
		else
		{   
			for(uni=0;uni<Co.c.len;uni++)
			{
				*(p+10+uni)=WriteDateBuff[uni];
			}
			pc->lena=Co.c.len; 
		}

	}
	else
	{
		pc->ct=0xC5;
		Co.c.len=1;
		pc->lena=1;
		pc->lent=0;
		p[10]=Meter_States.ErrOfInformation.byte;     
	}
	AdjustMeterRecord();
}   
/******************************************************************************************/



/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void BroadcastJustTime(unsigned char uartx)
{
	unsigned char *p;
	unsigned char result,n;//ok,
	struct FindCommand_Result *pc;
	unsigned int uni;

	result=0xff;

	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
	for(uni=0;uni<500;uni++)
	   Co.b[uni]=0; 
		
	for(n=0;n<6;n++)
	{
		Co.c.f[5-n]=*(p+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	
		if(!CheckBCD(Co.c.f[5-n])) result=0;    
	}

	if(pc->len!=0x06)  result=0;  /*"判断数据长度"*/
	   
	if(result)
	{
	   
		if(CheckTime((unsigned char *)&Co.c.f[0]))
		{
			double long data=0;
			
		 	result=Check_Can_Justtime();
			  
			if(result)	
				data=ComTime((unsigned char *)&softdate,(unsigned char *)&Co.c.f[0]);	
			else 
				data=0xffff;
	      	
			/*"  在±5分钟以内  "*/
			//if(ABS(data)<300)//FXF ADD 081120
			if(ABS(data)<=300)
			{
				//data=ComTime((unsigned char *)&softdate,(unsigned char *)&Other_Data.LastJusttime);
				//if(ABS(data)>24l*3600l)/*" 每天只允许校对一次  "*/
				{	
					for(n=0;n<5;n++)
						Co.b[309-n]=*((unsigned char *)&softdate+n);

					for(n=0;n<6;n++)
					{
						*((unsigned char *)&softdate+n)=Co.c.f[n];
					}
				//	Write_Date_AndOr_Time((unsigned char *)&softdate,0,2);
				ClockChipWrite((unsigned char *)&softdate);
					MainRamDate2=MainRamDate1=MainSoftDate;
					Other_Data.LastJusttime=softdate;
                    Other_Data.JusttimesAdd++;

					WRLC256(LASTJUSTTIME_ROM,(unsigned char *)&Other_Data.LastJusttime,8,0,0);
				//	WRLC256(LASTJUSTTIME_ROM,(unsigned char *)&Other_Data.LastJusttime,7,1,0);
					
				ClearDemandArea(0);			 
			    Seg();
	            FindTriff();							
				DealWithJustTime((unsigned char *)&Co.b[305]);
				Run_Triff_Switch(0);	//payment
	      	 }
	      	 //else result=0;
	      }
	      else result=0;
	   }
	   else result=0;
        }
	pc->ct=0x00;
	
}
/******************************************************************************************/
/******************************************************************************************/
/*" 在结算时刻和零点正负10分钟内不允许广播校时  added by fxf 081204 	"*/
unsigned char Check_Can_Justtime(void)
{		
	 struct DATEANDTIME_DEF  Bill_time;	
	 unsigned char hour_temp_bill=0,B_N,result=0xff;
	 double long data=0;

	 Bill_time=softdate;	 	 
    //if(((Bill_time.Hour==0x23)&&(Bill_time.Min>=0x50))||((Bill_time.Hour==0x00)&&(Bill_time.Min<=0x10)))
	 if((Bill_time.Hour==0x00)&&((Bill_time.Min<=0x4)||((Bill_time.Min==0x5)&&(Bill_time.Sec==0x00))))
	 {/*" 零点正负5分钟内不允许广播校时,即不能跨日  "*/ 	
          return 0;
     }
     else 	if((Bill_time.Hour==0x23)&&((Bill_time.Min>=0x55)))
     {/*" 零点正负5分钟内不允许广播校时,即不能跨日  "*/ 	
          return 0;
     }
	 else
     {
	 	  result=0xff;
     }				 
  
	/*" 在结算时刻正负10分钟内不允许广播校时"*/    
     hour_temp_bill=Check_Billdate_Validity(0,0xff);
     for(B_N=0;B_N<3;B_N++)
     {
        if((hour_temp_bill>>B_N)&0x01)
        {
            Bill_time.Day=Meter_Parameter.parameter1.AutoBillDayHour[B_N].Day;
            Bill_time.Hour=Meter_Parameter.parameter1.AutoBillDayHour[B_N].Hour;
            Bill_time.Min=0;
            Bill_time.Sec=0;
            data=ComTime((unsigned char *)&softdate,(unsigned char *)&Bill_time);
            //if(data>=-600 && data<=600)           
            if(data>=-300 && data<=300)
	 	           return 0;
        }       
     }

     if(Other_Data.JusttimesAdd>=Meter_Parameter.parameter2.BroadcastJustTtimes)
        return 0;
     
	 return result;
}
/******************************************************************************************/
/******************************************************************************************/
unsigned char DealWithJustTime(unsigned char *time_old)
{
      unsigned char uni=0;
      struct DATEANDTIME_DEF      temp_date1;

      for(uni=0;uni<=4;uni++)
            *( (unsigned char *)&temp_date1+uni)=*(time_old+4-uni);

     if((CompareBytes((unsigned char *)&temp_date1,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.SwitchDate, 5)<=0)
  	    &&(CompareBytes((unsigned char *)&softdate,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.SwitchDate, 5)>=0))
  	 {
  	      // CheckTriffDateChange(0);
  	      CheckChange(0,FOR_TRIFF_DATE);

	 }
	
    if((CompareBytes((unsigned char *)&temp_date1,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate, 5)<=0)
  	  &&(CompareBytes((unsigned char *)&softdate,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate, 5)>=0))
  	{
  	      //CheckDailySlotDateChange(0);
  	      CheckChange(0,FOR_DAILYSLOT_DATE);
  	}


      return 0;
}

/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void ReadAddress_New(unsigned char uartx)
{
		unsigned char *p;
		unsigned char ok,n,result;
		struct FindCommand_Result *pc;
		unsigned int uni;	
		
		ok=0xff;
		result=0;
		uni=0;	
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
				
	if(pc->len!=0x00)
		ok=0;
		
	if(ok)
	{
		for(uni=0;uni<6;uni++)
			p[10+uni]=Meter_Parameter.parameter1.BcdCommAddr[uartx][uni];

		result=0xff;		
	}

	if(result)
	{
		pc->ct=0x93;
		Co.c.len=6;
		pc->lena=6;	
	}
	else
	{
		pc->ct=0x00; 	
	}

	if(uartx<3)
		cx[uartx]=cx[3];
	//liuyq modify 2009-8-24 end
}
/******************************************************************************************/

/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void WriteAddress_New(unsigned char uartx)
	{
	unsigned char *p;
	unsigned char ok,n,result;
	struct FindCommand_Result *pc;
		
	ok=0xff;
	result=0;
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
		
	for(n=0;n<6;n++)
	{
		Co.c.f[n]=*(p+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	 
		/*"         写地址必须是BCD 090102  by fxf               "*/
		if(!CheckBCD(Co.c.f[n]))
		{
			ok=0;				  
			break;
		}	
	}
	
	if(pc->len!=0x06)		ok=0;
	/*"         写地址时候要按编程键081201 by fxf               "*/
	if(!O1ther_Meter_Parameter.WorkRoomState)     
	{
		ok=0;
		Meter_States.ErrOfInformation.bit.Invalid_Password=1;
	}
	
	//if(!KEY2 && ok)
	if( ok)
	{
   		//for(n=0;n<200;n++);
  		// if(!KEY2)
   		{
	   
			for(n=0;n<6;n++)
			{
		   		 Meter_Parameter.parameter1.BcdCommAddr[0][n]=Meter_Parameter.parameter1.BcdCommAddr[1][n]=Co.c.f[n];
		   		 Meter_Parameter.parameter1.BcdCommAddr[2][n]=Co.c.f[n];
			}
			//liuyq modify 2009-8-24 start
			WRLC256(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[0],18,0,0);
			Set_Meter_para_Deal(BCDCOMMADDR1_ROM);
		//	WRLC256(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.BcdCommAddr[0],18,1,0);
		//	Write_FM24C256_MULTI(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[0],18,FM24C256_1AND2);
			//liuyq modify 2009-8-24 end
			result=0xff;
	  	 }		   
	 }
	
	if(result)
	{
	   pc->ct=0x95;
	   Co.c.len=0;
	   pc->lena=0;
	}
	else
	{
	   pc->ct=0x00; 	
	}		
	
}
/******************************************************************************************/
/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
void WriteBaud_New(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok,result;
	struct FindCommand_Result *pc;
	
	ok=result=0;
		
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end

	result=(*(p+cx[3].addr)-0x33); 

	if(pc->len!=0x01)  result=0xff;  /*"   判断数据长度 ADDED BY Fuxf 081218  "*/
	
	//liuyq modify 2009-8-24 satrt
	Co.c.len=1;
	pc->lena=1;
	/*"只能更改某一位"*/
	if((result==0x04)||(result==0x08)||(result==0x10)||(result==0x20))
	{
		*(unsigned char *)&Meter_Parameter.parameter1.Commrate[uartx]=*(p+cx[3].addr)-0x33;
		WRLC256(COMMRATE0_ROM+uartx,(unsigned char *)&Meter_Parameter.parameter1.Commrate[uartx],1,0,0);
		Set_Meter_para_Deal(COMMRATE0_ROM+uartx);
	//	WRLC256(COMMRATE0_ROM+uartx,(unsigned char *)&Meter_Parameter.Commrate[uartx],1,1,0);
	//	Write_FM24C256_MULTI(COMMRATE0_ROM+uartx,(unsigned char *)&Meter_Parameter.parameter1.Commrate[uartx],1,FM24C256_1AND2);
		pc->ct=0x97;
		//Co.c.len=1;
		//pc->lena=1;
		p[10]=*(p+cx[3].addr)-0x33;
    }
    else
    {
     		pc->ct=0xD7;
	   //Co.c.len=1;
	   //pc->lena=1;
	   Meter_States.ErrOfInformation.bit.Invalid_COMMRATE=1;	 
	   p[10]=Meter_States.ErrOfInformation.byte;   
	   
    }	
	if(uartx<3)
		ChangeBand = uartx +1;
	
}   

/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************
*     1. output:0x00--the time is arrive                                                  *
*               0xff--the time is no arrive                                               *
*******************************************************************************************/
#ifdef  PASSWORD_MODE
void WritePassword_New(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok,n,result,password_level;
	struct FindCommand_Result *pc;
	unsigned int uni;
        union ID id_pass;
		
	
	result=0xff;
	ok=0xff;
	
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	Meter_States.ErrOfInformation.byte=0;			
	for(n=0;n<12;n++)
	{
		Co.c.f[n]=*(p+cx[3].addr)-0x33;
		if(n<4)
			id_pass.d[n]=*(p+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	    
	}
	//liuyq modify 2009-8-21 end
	
	
	if(pc->len!=0x0C)  ok=0;  /*"   判断数据长度 ADDED BY Fuxf 081218  "*/

	if((id_pass.l<0x04000C01)||(id_pass.l>0x04000C0A)||(pc->len!=0x0C))
	{
		ok=0;
	}

    if(ok==0)						
	{
		Meter_States.ErrOfInformation.bit.Invalid_Data=1;  
		result=0;
	}
	else
	{		
		/*"  要修改的密码 级别和设置的密码级别必须相同 "*/
		n=id_pass.d[0]-1;

		if(n!=Co.c.f[8])   
		      result=0;
		else 
			password_level=Meter_Parameter.parameter1.ClearPassword[n][0];
	    
	if(result)
	     result=CheckPasswordProgram_New((unsigned char *)&Co.c.f[4],password_level);        

	if((Co.c.f[4]==0x00) &&
	    (Co.c.f[5]==0x05) &&
	      (Co.c.f[6]==0x05) &&  
	     (Co.c.f[7]==0x20) && O1ther_Meter_Parameter.WorkRoomState)
	      result=0xAA;
		
	if(result==0)
	Meter_States.ErrOfInformation.bit.Invalid_Password=1;         
	
	if((!Program_Key_Flag  && !O1ther_Meter_Parameter.WorkRoomState)||(farinfrareddisableflag==1))   
	{
	  result=0;
		Meter_States.ErrOfInformation.bit.Invalid_Password=1;    
	}
	}
	
	if(result)
	{
		if(result==0xAA)
		{
			for(uni=0;uni<10*sizeof(struct PASSWORDERR);uni++)  
				*((unsigned char *)&Other_Data.PasswordErr+uni)=0;
			Other_Data.Clear_PasswordErr_Flag=0xff; 
			//change to 10
			//liuyq modify 2009-8-24 start
			WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,10*sizeof(struct PASSWORDERR)+1,0,0);
		//	WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,10*sizeof(struct PASSWORDERR)+1,1,0);
		//	Write_FM24C256_MULTI(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,10*sizeof(struct PASSWORDERR)+1,FM24C256_1AND2);
			//liuyq modify 2009-8-24 end
		}	

	     for(n=0;n<4;n++)
	   	{
	   		Meter_Parameter.parameter1.ClearPassword[Co.c.f[8]][n]=Co.c.f[8+n];
        	}
		 //liuyq modify 2009-8-24 start
        	WRLC256(CLEARPASSWORD_ROM+Co.c.f[8]*4,(unsigned char *)&Co.c.f[8],4,0,0);
        	Set_Meter_para_Deal(CLEARPASSWORD_ROM+Co.c.f[8]*4);
	 //  	WRLC256(CLEARPASSWORD_ROM+Co.c.f[8]*4,(unsigned char *)&Co.c.f[8],4,1,0);
 	//	Write_FM24C256_MULTI(CLEARPASSWORD_ROM+Co.c.f[8]*4,(unsigned char *)&Co.c.f[8],4,FM24C256_1AND2);
		//liuyq modify 2009-8-24 end
	   	result=0xff;  	
  
	}
	

	if(result)
	{   
		pc->ct=0x98;
		Co.c.len=4;
		pc->lena=4;
		for(n=0;n<4;n++)
		{
			*(p+10+n)=Co.c.f[8+n];
		}
	}
	else 
	{
	   pc->ct=0xD8;
	   Co.c.len=1;
	   pc->lena=1;
	   if(Meter_States.ErrOfInformation.byte==0)
	   Meter_States.ErrOfInformation.bit.Invalid_Data=1;
	   p[10]=Meter_States.ErrOfInformation.byte;   
	}

	
}
#endif

//-------------------------------------------------------------------------
//---------------------------------------------------------------------------
void ClearDemand_New(unsigned char uartx)
{
	unsigned char ok,n;
  
  ok=0;
  Meter_States.ErrOfInformation.byte=0; 
  AppointTrasfPortBuff(uartx);
  WriteDateBuff[0]=CommBP[CurrPC->addr]-0x33;;
  if (WriteDateBuff[0] == 0x98) /*"表示命令是98级密文方式"*/
  {
     if(cmd_0x98_mode_decipher(uartx, 0x19) == 1) 
     {
        ok=1;
     }
  }
  else
  {
  	 if((O1ther_Meter_Parameter.WorkRoomState==0xff)&&(CurrPC->len==8))
  	 {
  	 	 ok=2;
  	 }
  	 else
  	 {
  	 	 Meter_States.ErrOfInformation.bit.Invalid_Password=1;
  	 }
  }
			
	for(n=0;n<8;n++)
	{
		if(n<4)
		   Co.c.f[n]=*(CommBP+cx[3].addr)-0x33;
		else
			*((unsigned char*)&(CurrPC->Programer_code)+n-4)=*(CommBP+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	 
	}
	
	if((ok==1)||(ok==2))
	{		
    Set_which_Responsion_Flag(2,0xff);
    Clear_demand_oper_code=CurrPC->Programer_code;
		CurrPC->ct=0x99;
		Co.c.len=0;
		CurrPC->lena=0; 
		Comm_Key_Clear_Demand=1; 
	}
	else
	{
 		CurrPC->ct=0xD9; 
		Co.c.len=1;
		CurrPC->lena=1;
		if(Meter_States.ErrOfInformation.byte==0)
			Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		CommBP[10]=Meter_States.ErrOfInformation.byte;
	}
	
}

//----------------------------------------------------//
unsigned char  Check_Clear_Event_If_Ok(unsigned  long cleareventflag)
{
	unsigned char i;
        if((cleareventflag == 0xffffffff) ||
	     (cleareventflag == 0x033005ff) ||
	     (cleareventflag == 0x0332ffff) ||
	     (cleareventflag == 0x0333ffff))
        	{
        	return 0xff;
        	}
	 for(i=0;i<(sizeof(Clearevent_ID)/sizeof(unsigned long));i++)
	 {
	    if(cleareventflag==Clearevent_ID[i])
			return 0xff;
	 }
	 return 0;
}
//----------------------------------------------------//
void ClearEvent_New(unsigned char uartx)
{
	unsigned char ok,n;
	unsigned long clearevent_code;
    
  ok=0;
  Meter_States.ErrOfInformation.byte=0;
  AppointTrasfPortBuff(uartx);
  WriteDateBuff[0]=CommBP[CurrPC->addr]-0x33;
  if (WriteDateBuff[0] == 0x98) /*"表示命令是98级密文方式"*/
  {
     if (cmd_0x98_mode_decipher(uartx, 0x1B) == 1) 
     {
        ok=1;   
     }
  }
  else
  {
  	 if((O1ther_Meter_Parameter.WorkRoomState==0xff)&&(CurrPC->len==12))
  	 {
  	 	 ok=2;
  	 }
  	 else
  	 {
  	 	 Meter_States.ErrOfInformation.bit.Invalid_Password=1;
  	 }
  }
	
	/*"模式字1允许事件清零 "*/
	if(!Meter_Parameter.parameter1.MeterMode[0].bit.b0 && !O1ther_Meter_Parameter.WorkRoomState)
	{
		if(ok!=0)	
		 	Meter_States.ErrOfInformation.bit.Invalid_Password=1;			 
		ok=0;
	}
	
	for(n=0;n<8;n++)
	{
		if(n<4)
		   Co.c.f[n]=*(CommBP+cx[3].addr)-0x33;
		else
			*((unsigned char*)&(CurrPC->Programer_code)+n-4)=*(CommBP+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	 
	}	
	
	if(ok!=0)
	{
	  for(n=0;n<4;n++)  
	  {
		  *((unsigned char*)&clearevent_code+n)=*(CommBP+cx[3].addr)-0x33; 
		  cx[3].addr++;
		  if(cx[3].addr>=B_FL) cx[3].addr=0;	 
	  }	
	
	  if(Check_Clear_Event_If_Ok(clearevent_code)!=0xff)
		  ok=0;
	}
	
	if(ok)         
	{    
		ok=0xff;  
    Set_which_Responsion_Flag(1,0xff);
		Clear_event_oper_code=CurrPC->Programer_code;
		clear_event_ID_code=clearevent_code;
	}
	
	if(ok==0xff )
	{   
		CurrPC->ct=0x9B;
		Co.c.len=0;
		CurrPC->lena=0; 
		Comm_Key_Clear_Demand=1; 
	} 
	else  
	{
		CurrPC->ct=0xDB;
		Co.c.len=1;
		CurrPC->lena=1;
		if(Meter_States.ErrOfInformation.byte==0)
			Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		CommBP[10]=Meter_States.ErrOfInformation.byte;	  
	}  
	//liuyq modify 2009-8-25 end
}

//----------------------------------------------------//
//----------------------------------------------------//
unsigned char  ClearDemandCommAndKey(unsigned char model,unsigned char billflag)
{
      unsigned int uni=0,unj=0;
      unsigned char pointer1=0; 
      unsigned char result=0xff;
	struct FindCommand_Result *pc;
	pc=(struct FindCommand_Result *)&cx[3];
      
	if((model<2))
	{
         //if((Other_Data.PasswordErr[0].flag))
         if((model==1)&&!Program_Key_Flag && !O1ther_Meter_Parameter.WorkRoomState)
         {
            result=0x00;
         }
        else
		{
			//if(ComTime((unsigned char*)&softdate,(unsigned char *)&Other_Data.LastClearDemandDate)<Meter_Parameter.DemandPeriod*60) 
			//{
			//	result=0x00;
			//} 
			//else
			{
				show_clear_char();    
#ifdef  DEMAND_CLR_KEY
				Show_flag.bit.key=1;
#endif
			}
		}
	}
	if(result) 
	{
         
		if(model<2)
		{
			if(!model)   
			{           
				/*"    记录请需量事件记录FXF ADD  "*/
				if(ClearDemandRecord(Clear_demand_oper_code)==0)
					return 0;
			}
			else  if(model==1)
			{            
				/*"    记录请需量事件记录FXF ADD  "*/
				if(ClearDemandRecord(0xffffffff)==0)
					return 0;
			}

			Other_Data.LastClearDemandDateCM=softdate; 
			FeedWatchdog();
			//liuyq modify 2009-8-24 start 
			WRLC256(LASTCLEARDEMANDDATECM_ROM,(unsigned char *)&Other_Data.LastClearDemandDateCM,sizeof(struct DATEANDTIME_DEF),0,0);
			FeedWatchdog();  
		//	WRLC256(LASTCLEARDEMANDDATECM_ROM,(unsigned char *)&Other_Data.LastClearDemandDateCM,sizeof(struct DATEANDTIME_DEF),1,0);
		//	FeedWatchdog();
 	 	//	Write_FM24C256_MULTI(LASTCLEARDEMANDDATECM_ROM,(unsigned char *)&Other_Data.LastClearDemandDateCM,sizeof(struct DATEANDTIME_DEF),FM24C256_1AND2);
   //                              FeedWatchdog(); 

			//Event_Meter_Pro_Times.DemandClear_Times++;			
			//WRLC256(DEMANDCLEAR_TIMES_ROM,(unsigned char *)&Event_Meter_Pro_Times.DemandClear_Times,2,0,0);


			Clear_Demand_Mode=model;
			if(!Clear_Demand_Mode)
				Clear_Demand_Mode=2;
#ifdef  DEMAND_CLR_KEY
			Other_Data.LastClearDemandDate=softdate; 
#endif
			FeedWatchdog();  
                             
			//liuyq modify 2009-8-24 start
			FeedWatchdog();  
			WRLC256(O1ther_Meter_Parameter.Bill_DM_Addr*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),0,0);
			//FeedWatchdog();  
			//WRLC256(Meter_Parameter.Bill_DM_Addr*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),1,0);
			//FeedWatchdog();
 	 		//Write_FM24C256_MULTI(Meter_Parameter.bill_state.Bill_DM_Addr*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),FM24C256_1AND2);
			//liuyq modify 2009-8-24 end

		}

                     if(billflag==0) 
                     {
		for(uni=0;uni<sizeof(struct DEMAND_RECORD);uni++)
		{
			*((unsigned char *)&This_Month_Data.Demand_Record.Demand+uni)=0;
		}
		ClearDemandArea(0);
		//liuyq modify 2009-8-24 start
		WRLC256(THISM_DEMAND_RECORD,0,sizeof(struct DEMAND_RECORD),0,0);
		FeedWatchdog();  
	//	WRLC256(THISM_DEMAND_RECORD,0,sizeof(struct DEMAND_RECORD),1,0);
 		//FeedWatchdog();  
	 //	Write_FM24C256_MULTI(THISM_DEMAND_RECORD,0,sizeof(struct DEMAND_RECORD),FM24C256_1AND2);
		//liuyq modify 2009-8-24 end
                     }
	   
		if(model==2)
		{
            CheckPowerDown();//fx add 090927
			pointer1=O1ther_Meter_Parameter.Bill_DM_Addr;
            if(billflag!=0)
            {       /*"非转存日对应的这个结算日需量数据补FF"*/  
                  for(unj=0;unj<=sizeof(struct DEMAND_RECORD);unj++)
	                Co.b[300+unj]=0xff;            
		//liuyq modify 2009-10-15 start
                  WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,(unsigned char *)&Co.b[300],sizeof(struct DEMAND_RECORD),0,0);
                  FeedWatchdog();  
                  //WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,(unsigned char *)&Co.b[300],sizeof(struct DEMAND_RECORD),1,0);
                  //FeedWatchdog();
	 //	Write_FM24C256_MULTI(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,(unsigned char *)&Co.b[300],sizeof(struct DEMAND_RECORD),FM24C256_1AND2);
		//liuyq modify 2009-10-15 end
                  CheckPowerDown();
            }
            /*"清除当月需量空间"*/  
            pointer1++;
            pointer1%=14;  
		//liuyq modify 2009-10-15 start
            //WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),0,0);
            //FeedWatchdog();  
            //CheckPowerDown();
            //WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),1,0);
            //FeedWatchdog();  
	        if(billflag==0)
            {
            	 WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),0,0);
            FeedWatchdog();  
             //    Write_FM24C256_MULTI(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,0,sizeof(struct DEMAND_RECORD),FM24C256_1AND2);
		        //liuyq modify 2009-10-15 end
	        }
            else
            {
                 WRLC256(pointer1*sizeof(struct DEMAND_RECORD)+DEMAND_RECORD_ROM,(unsigned char *)&This_Month_Data.Demand_Record.Demand,sizeof(struct DEMAND_RECORD),0,0);
            }
            CheckPowerDown();

            //Meter_Parameter.Bill_DM_Addr=pointer1;
            //WRLC256(BILL_DM_ADDR_ROM,(unsigned char *)&Meter_Parameter.Bill_DM_Addr,1,0,0); 
            //WRLC256(BILL_DM_ADDR_ROM,(unsigned char *)&Meter_Parameter.Bill_DM_Addr,1,1,0); 
         }
	
      }
      
      
      return result;
}
//----------------------------------------------------//
//----------------------------------------------------//
void ClearMeter_New(unsigned char uartx)
{
	unsigned char ok,n;

  ok=0;
  Meter_States.ErrOfInformation.byte=0;
  AppointTrasfPortBuff(uartx);
  WriteDateBuff[0]=CommBP[CurrPC->addr]-0x33;;
  if (WriteDateBuff[0]== 0x98) /*"表示命令是98级密文方式"*/ 
  {   /*" 本地费控表不支持清零命令， 厂内支持 "*/
     if ((!MACRO_LOCAL_PAY_FLAG) || O1ther_Meter_Parameter.WorkRoomState) {
         if(cmd_0x98_mode_decipher(uartx, 0x1A) == 1) {
            ok=1; 
         }
     }
  }
  else
  {
  	 if((O1ther_Meter_Parameter.WorkRoomState==0xff)&&(CurrPC->len==8))
  	 {
  	 	 ok=2;
  	 }
  	 else
  	 {
  	 	 Meter_States.ErrOfInformation.bit.Invalid_Password=1;
  	 }
  }
	
	if(!Meter_Parameter.parameter1.MeterMode[0].bit.b1 && !O1ther_Meter_Parameter.WorkRoomState)
	{
		if(ok!=0)		 
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;		//payment  //Meter_States.ErrOfInformation.bit.Invalid_Password=1;
		ok=0;
	}
	
	for(n=0;n<8;n++)
	{
		if(n<4)
		   Co.c.f[n]=*(CommBP+cx[3].addr)-0x33;
		else
			*((unsigned char*)&(CurrPC->Programer_code)+n-4)=*(CommBP+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	 
	}
	Clear_all_oper_code=CurrPC->Programer_code;
	
	if((ok==1)||(ok==2))
	{      
    Set_which_Responsion_Flag(0,0xff);
    CurrPC->ct=0x9A;  
		Co.c.len=0;
		CurrPC->lena=0;
	}
	else
	{
		CurrPC->ct=0xDA;
		Co.c.len=1;
		CurrPC->lena=1;
		if(Meter_States.ErrOfInformation.byte==0)
			Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		CommBP[10]=Meter_States.ErrOfInformation.byte;
	}
	
}

/******************************************************************************************
*  flag: 0x00:run clear  success,
			 0xff :power on clear                             *
*             FXF   ADD 081120                            *
*******************************************************************************************/
unsigned char  Clear_All_New(unsigned long  Oper_Code)
{   
	unsigned char n,csadd=0;
	unsigned int uni,length;
	union EVENT_REPORT_STATUS ResetEventReportStatus;
    
	p3_2=1;

    CheckPowerDown();
	if (clearFlag<10)
		show_clear_char();	
	 
	 /*" 清电能清需量   不记录此次清需量事件记录  "*/
	CheckPowerDown();
	Clear_Erengy();
    FeedWatchdog(); 
		
	/*" 清事件和不此次清事件事件记录 "*/
	CheckPowerDown();
	//ClearNewEventRecord(Oper_Code,0xffffffff);

	Pay_Data_All_Clear();	//payment
	Remain_Money_Alarm_Judge();	/*"将要跳闸的标志都置上"*/	
	Card_Alarm_Switch();		/*"解除能跳闸标志"*/		/*"修改:发了拉闸命令后，发电表清零命令电表合闸后，记了一次合闸事件记录的现象，先使继电器合闸，再清合闸记录"*/
	
	FeedWatchdog(); 
	ClearEventAll();
	
	//ClearClearEvent();
	 FeedWatchdog(); 	
	
	/*" 清负荷曲线 "*/
	CheckPowerDown();
  First_InitLoadRecord();	
	
	/*" 清冻结 "*/	
	CheckPowerDown();
    Clear_Freeze();
    FeedWatchdog(); 
    CheckPowerDown();
    Check_Show_Flash_Data(0xff,0,0xff,0);/*"清零后刷新显示数据，避免低功耗显示事件、冻结数据异常"*/
	clearFlag=0;	/*"解决初始化钱包后，再发清零命令不清费控数据的问题"*/
    ///Clear_ALLEventReportInfo();
    
     for(uni=0; uni<12; uni++)
	{
	    ResetEventReportStatus.byte[uni]=0x00;
	}              
   Clear_EventReportStatus_And_Times(ResetEventReportStatus);
   
   O1ther_Meter_Parameter.SwitchOff_Report=0;
   WRLC256(SWITCHOFF_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOff_Report,1,0,0); 
            
   for(uni=0 ; uni<5; uni++)
   {
    if(0 != EventStatus_flag.byte[uni])
    {
       EventStatus_flag.byte[uni]=0;
       WRLC256((EVENTSTATUS_FLAG_ROM+uni),(unsigned char *)&EventStatus_flag.byte[uni],1,0,0);
    }
   }
  
    if ((!MACRO_LOCAL_PAY_FLAG)&&(Pre_Payment_Para.Far_Key_StatusByte )&&(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x02))
   {
    EventReportState_Expand(0, 1, 0);
      Save_EventReportTimes(METER_CLEAR_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Meter_clear_times);   
   }

    return 0xff;
}
/*"**********FXF   ADD 081120********************"*/
unsigned char  Clear_Erengy(void)
{   
	unsigned char n;
	unsigned int uni;	
	unsigned int i;
	unsigned int k;
	unsigned int length;
		

	    /*"掉电存数电量备份数据在Check_Energy_main函数中有清零，这里无需清"*/ 
	   // for(uni=0;uni<12;uni++)
          // {
          //   *((unsigned long *)&Cal_PowerDown_Energy_add+uni)=0;
          // }
		
/*" 清当前电能量、最大需量数据 "*/
	/*" 保留剩余电费"*/	//payment
          length = sizeof(struct ENERGY_RECORD)  - (sizeof(struct PRE_SAVE_DATA) + 2);      
	   for(uni=0;uni<length;uni++)
           {
	          *((unsigned char *)&This_Month_Data.Energy_Record+uni)=0;
           }
	   length = sizeof(union DEMAND_TYPE);
	   for(uni=0;uni<length;uni++)
           {
	          *((unsigned char *)&This_Month_Data.Demand_Record+uni)=0;
           }

//--------------------------------------------------------------------------------	
/*"掉电存数数据清零"*/
       length=sizeof(struct POWERDOWN_SAVE_DATA);
	for(uni=0;uni<length;uni++)
		{
		*((unsigned char *)&Powerdown_Save_Data+uni)=0;
		}	
		Powerdown_Save_Data.crc_cal = CRC((unsigned char*)&Powerdown_Save_Data,
	                               sizeof(struct POWERDOWN_SAVE_DATA) - 2);
	  WRLC256(POWERDOWN_SAVE_DATA_ROM,(unsigned char *)&Powerdown_Save_Data,
	                                   sizeof(struct POWERDOWN_SAVE_DATA),0,0);
//--------------------------------------------------------------------------------

    /*"电量尾数清零"*/
    for(uni=0;uni<sizeof(struct ENERGY_RAIL_ADD_BUFFER);uni++)
   {
		*((unsigned char *)&energy_rail+uni)=0;
    }
    energy_rail.crc_cal = CRC((unsigned char*)&energy_rail,
	                             sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2);
    WRLC256(ENERGY_RAIL_DATA_ROM,(unsigned char *)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER),0,0);
////////////////////////////////////////////////////////////////////////////////////////     

           /*"电量备份数据在Check_Energy_main函数中有清零，这里无需清"*/
           //WRLC256(F_ENERGY_RECORD,0,sizeof(struct ENERGY_RECORD),0,0);   
           
           FeedWatchdog();  		   
	    /*"清电量需量历史数据"*/	   
           length=(sizeof(struct ENERGY_RECORD)+sizeof(struct DEMAND_RECORD));
           for(i=0;i<MAXMONTHSAVE;i++)
           {
              WRLC256(ENERGY_RECORD_ROM+i*length,0,length,0,0);
              FeedWatchdog(); 
           }
		 FeedWatchdog();    //mw added 070515
		 
	   
           /*"电量数据在Check_Energy_main函数中有清零这里只需清需量数据即可"*/  
	    length=sizeof(struct DEMAND_RECORD);
           WRLC256(THIS_MONTH_DATA_ROM + sizeof(struct ENERGY_RECORD),0,length,0,0); 
           FeedWatchdog();  
		   
		Pay_Money_Clear();		//payment		   
//---------------------------------------------------------------------------
      Check_Energy_main(2);
//----------------------------------------------------------------------------		
#ifdef  DEMAND_CLR_KEY
        Other_Data.LastClearDemandDate=softdate;   
        Show_flag.bit.key=1;
#endif
			
		  /*"  初始化需量 "*/
		  ClearDemandArea(0);
		// Demand_New_Init();
             WRLC256(MONTH_BILL_NUM_ROM,0,4*MAXMONTHSAVE ,0,0);///king chen modify 130315  
}


/*"============================================================"*/
/*"函数名：Check_Clear_Responsion"*/
/*"通信先应答 处理 "*/
/*"参数：应答串口通道"*/
/*"返回：无"*/
/*"作者：fuxf 版本：1.00"*/
/*"============================================================"*/
void Check_Clear_Responsion(unsigned char cuart)
{
    unsigned int unn,crctempEE=0,crctempFF=0;
    unsigned char flage=0,flagf=0;
    unsigned char ri;//ganjp 20091214
    
    if(IntoPowerDownFlag)
        return;
	
    if(cuart!=Comm_Firrespon_SecDispos_Uart[cuart])
        return;

    check_and_update_psw_to_esam();

    Comm_Firrespon_SecDispos_Uart[cuart]=0xff;
    
    for(unn=0;unn<5;unn++)
    {   
        flage=*((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag+unn);
        flagf=*((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag+unn);
        if((flage==0xff)&&(flagf==0xff))
	    {
            crctempEE=Crc16l((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag,5);
            crctempFF=Crc16l((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag,5);
            if((crctempEE==Other_Data.CommClearFlagCurrEE.Comm_Clear_Crc_Data)&&(crctempFF==O1ther_Meter_Parameter.CommClearFlagCurrFF.Comm_Clear_Crc_Data))
            {          
                if(unn==0)
                { 	/*"总清零先应答再清零"*/          
		            ClearMeterRecord(Clear_all_oper_code);	
		            Clear_All_New(Clear_all_oper_code); 		                        
	            }
                else if(unn==1)
                { 	/*"事件清零先应答再清零"*/         
             		 ClearEventRecord(Clear_event_oper_code,clear_event_ID_code);
			         ClearNewEventRecord(Clear_event_oper_code,clear_event_ID_code);	
                }
                else if(unn==2)
                {   /*"需量清零先应答再清零"*/   
		            ClearDemandCommAndKey(0,0);			 
	            }
                else if(unn==3)
                {	/*"时段表编程先应答再清零"*/
                    ProgDailySlotRecord(Comm_DailyProg_oper_code);
                }
                else if(unn==4)
                {    /*"时区表编程先应答再清零"*/
                    ProgYearSlotRecord(Comm_YearProg_oper_code);
                }
                else
                    return;
            }

            Set_which_Responsion_Flag(unn,0);
            return;
        }     
    }
    
}
/*"============================================================"*/
/*"函数名：Set_which_Responsion_Flag"*/
/*"通信先应答 置标志"*/
/*"参数：Which:需要设置的参数；flag:参数数据"*/
/*"返回：无"*/
/*"作者：fuxf 版本：1.00"*/
/*"============================================================"*/
void Set_which_Responsion_Flag(unsigned char Which,unsigned char flag)
{
    *((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag+Which)=flag;
    *((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag+Which)=flag;
    Other_Data.CommClearFlagCurrEE.Comm_Clear_Crc_Data=Crc16l((unsigned char *)&Other_Data.CommClearFlagCurrEE.Clear_All_Flag,5);
    O1ther_Meter_Parameter.CommClearFlagCurrFF.Comm_Clear_Crc_Data=Crc16l((unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF.Clear_All_Flag,5);
    if(Which==0)
    { 	/*"总清零先应答再清零"*/
        WRLC256(COMMCLEARFLAGCURRFF_ROM,(unsigned char *)&O1ther_Meter_Parameter.CommClearFlagCurrFF,sizeof(struct COMMCLEARSTRDEF),0,0);
	    FeedWatchdog();
        WRLC256(COMMCLEARFLAGCURREE_ROM,(unsigned char *)&Other_Data.CommClearFlagCurrEE,sizeof(struct COMMCLEARSTRDEF),0,0);
	}
}


/******************************************************************************************
*     1. output:0x00--read write error                                                    *
*               0xff--read or write ok                                                    *
*******************************************************************************************/
unsigned char R_W_Data(void)
{
	unsigned char result;
	unsigned char eepromaddr,nflag;
	unsigned int  uni,unc;
	unsigned char condition;
	unsigned char PhaseIndexExitF[4] = {0};//liuyq added 2009-8-20
	
	result=0xff;
	eepromaddr=nflag=0;
	//===============
	Demandtempbuffer=0;
	//===============
		
	if(Co.c.flag3.bit.b1)     
		nflag=0xff;   
	   	
	if(!Co.c.rw)
	{   
		//liuyq added 2009-8-20 start 
		if(Co.c.com.bit.b0 |Co.c.com.bit.b1)
			PhaseIndexExitF[0] = 1;
		if(Co.c.com.bit.b2|Co.c.com.bit.b3)
			PhaseIndexExitF[1] = 1;
		if(Co.c.com.bit.b4 | Co.c.com.bit.b5)
			PhaseIndexExitF[2] = 1;
		if(Co.c.com.bit.b6|Co.c.com.bit.b7)
			PhaseIndexExitF[3] = 1;
		//liuyq added 2009-8-20 end 
		if(Co.c.flag1.bit.b3)
		{			
			for(unc=0; unc<4; unc++)
			{
				if(PhaseIndexExitF[unc])
					for(uni=0;uni<Co.c.len;uni++)
						Co.c.data[unc][uni]=*(Co.c.addrr[unc]+uni);
			}
			//liuyq modify 2009-8-20 end
		}
		else  if(Co.c.flag1.bit.b4)
		{			
			for(unc=0; unc<4;unc++)
			{
				if(PhaseIndexExitF[unc])
					WRLC256(Co.c.addre[unc],Co.c.data[unc],Co.c.len,eepromaddr,1);
			}
			//liuyq modify 2009-8-20 end
		}
		else
		{
			return 0;
		}

		Co.c.d.g=0;

		if(Co.c.flag4.bit.b0)
		{			
			for(unc=0; unc<4;unc++)
			{
				if(PhaseIndexExitF[unc])
				{
					if(Co.c.com.byte&(1<<(2*unc)))
						Co.c.d.g+=*((unsigned long*)&Co.c.data[unc][0]);
					if(Co.c.com.byte&(1<<(2*unc+1)))
						Co.c.d.g-=*((unsigned long*)&Co.c.data[unc][0]);  
					Co.c.d.g=format_data(Co.c.d.g,1); 	  	 
				}
			}

	   if(Co.c.d.g<0)
	   {
	   	Co.c.d.g*=-1;
	   	nflag=0xff;
	   }

	     
	      for(uni=0;uni<4;uni++)
	         *((unsigned char*)&Co.c.data[0]+uni)=Co.c.d.c[uni];
	   }
	   else
	   {			
			for(unc=1;unc<4;unc++)
			{
				if(Co.c.com.byte & (1<<unc))
					for(uni=0;uni<Co.c.len;uni++)
						*((unsigned char*)&Co.c.data[0]+uni)=*((unsigned char*)&Co.c.data[unc]+uni);
			}
			
			//liuyq modify 2009-8-20 end
		}

        if(Check_Data_valid((unsigned char*)&Co.c.data[0],Co.c.len)==-1)
        {
            Co.c.flag1.bit.b0=1;
            Co.c.flag3.bit.b0=0;
        }
        
        if(Co.c.flag3.bit.b0)
		{
			Co.c.d.g=*(unsigned long*)&Co.c.data[0];
			//=======
			Demandtempbuffer=Co.c.d.g;
			//=======			
			for(uni=0;uni<Co.c.calnumber;uni++)
			{
				Co.c.d.g=Co.c.d.g/10l;
			}
			for(uni=0;uni<4;uni++)
				*((unsigned char*)&Co.c.data[0]+uni)=Co.c.d.c[uni];
		}        

		if(Co.c.flag1.bit.b0)
		{
			if(!(Co.c.flag2.byte&0x01))
			{
				for(uni=0;uni<Co.c.len;uni++)
					*(Co.c.addr5+uni)=*((unsigned char*)&Co.c.data[0]+uni);
			}
			else
			{
				for(uni=0;uni<Co.c.len;uni++)
					*(Co.c.addr5+Co.c.len-1-uni)=*((unsigned char*)&Co.c.data[0]+uni);
			}
		}
		else if(Co.c.flag1.bit.b1)
		{
			HexToBcd(Co.c.len,(unsigned char*)&Co.c.data[0],Co.c.addr5);
			if(Co.c.flag3.bit.b1) //modified by mw080131
			{
				if(nflag)
					*(Co.c.addr5+3)|=0x80;
				else    
				{
					if(Co.c.flag4.bit.b0)
						*(Co.c.addr5+3)&=0x7F;
				}
			}
			if((Co.c.flag2.byte&0x01))   
			{
				for(uni=0;uni<Co.c.len/2;uni++)
				{
					condition=*(Co.c.addr5+Co.c.len-1-uni);  
					*(Co.c.addr5+Co.c.len-1-uni)=*(Co.c.addr5+uni);
					*(Co.c.addr5+uni)=condition;
				}
			}   
		}
		else if(Co.c.flag1.bit.b2)
		{
			HexToACK((unsigned char *)&Co.c.d,Co.c.addr5,Co.c.len);
		} 
	}
	else if(Co.c.rw)
	{

//		if(Co.c.flag1.bit.b0)
//		{
//			for(uni=0;uni<Co.c.len;uni++)
//				*((unsigned char *)&Co.c.data+uni)=*(Co.c.addr5+uni);
//		}
//		else if(Co.c.flag1.bit.b1)
//		{
//			BcdToHex(Co.c.len,Co.c.addr5,(unsigned char *)&Co.c.data);
//		}
//		else if(Co.c.flag1.bit.b2)
//		{
//			ACKToHex(Co.c.addr5,(unsigned char *)&Co.c.data,Co.c.len);
//		} 
//
//		if(!(Co.c.flag2.byte&0x01))
//		{
//			//for(uni=0;uni<Co.c.len;uni++)
//			//Co.c.data[0][uni]=*((unsigned char *)&Co.c.d+uni);
//		}
//		else
//		{
//			for(uni=0;uni<Co.c.len;uni++)
//			{
//				Co.b[300+uni]=Co.c.data[0][Co.c.len-1-uni];    
//			}
//			for(uni=0;uni<Co.c.len;uni++)
//			{
//				Co.c.data[0][uni]=Co.b[300+uni];//=Co.c.data[0][Co.c.len-1-uni];    
//			}
//			//Co.c.data[0][Co.c.len-1-uni]=Co.c.data[0][Co.c.len-1-uni];//*((unsigned char *)&Co.c.d+uni);
//		}
//
//		if(Co.c.flag1.bit.b3)
//		{
//			if(Co.c.com.bit.b0)
//			{
//				for(uni=0;uni<Co.c.len;uni++)
//					*(Co.c.addrr[0]+uni)=Co.c.data[0][uni];
//			}
//		}
//		if(Co.c.flag1.bit.b4)
//		{
//			if(Co.c.com.bit.b0)
//			{
//				if(eepromaddr<2)
//				{   
//					//liuyq modify 2009-8-24 start
//					WRLC256(Co.c.addre[0],Co.c.data[0],Co.c.len,0,0);
//					Set_Meter_para_Deal(Co.c.addre[0]);
//					FeedWatchdog();  
//					//WRLC256(Co.c.addre[0],Co.c.data[0],Co.c.len,1,0);
//					//FeedWatchdog();
//					//Write_FM24C256_MULTI(Co.c.addre[0],Co.c.data[0],Co.c.len,FM24C256_1AND2);
//					//liuyq modify 2009-8-24 end
//					WRLC256(Co.c.addre[0],Co.c.data[0],Co.c.len,eepromaddr,1);
//					FeedWatchdog();  
//				}
//				else
//				{
//					WRLC256(Co.c.addre[0],Co.c.data[0],Co.c.len,0,0);
//					FeedWatchdog();  
//					WRLC256(Co.c.addre[0],Co.c.data[0],Co.c.len,0,1);
//					FeedWatchdog();  
//				}
//			}
//		}
	   
	}
	
	cx[3].lena+=Co.c.len;
	
	if(cx[3].c!=0x05)
	{
		for(uni=0;uni<300;uni++)
			Co.b[uni]=0;
	}
	
	return result;  
}


/*"****************************************************************************************"*/
/*"//  功能描述: 读系统毫秒数"*/
/*"//  返回值:   当前系统运行的总毫秒数"*/
/*"//  说    明: 由于TimeCount5ms在定时中断中被修改，由于TimeCount5ms在汇编中分两条"*/
/*"//            指令读取，在两条指令中间，中断修改数据，发生低位向高位进位，所以重"*/
/*"//            读一次，保证数据的一致性"*/
/*"******************************************************************************************"*/
unsigned long GetNowTime(void)
{
	unsigned long ret;

	ret = TimeCount5ms; // 
	if(ret != TimeCount5ms)
		ret = TimeCount5ms;
	
	return ret;
}  


/*"*****************************************************************************************"*/
/*"  功能描述: 判断延时是否满足"*/
/*"//  返回值:   0-满足  0xFF-不满足"*/
/*"//  说    明: 即使GetNowTime()<oldtime, 表示时间计数器已经溢出,两个时间之间的差"*/
/*"//            值也依然是GetNowTime()-oldtime, 不需另外处理 "*/
/*"******************************************************************************************"*/
unsigned char GetTimeCount(unsigned long oldtime,unsigned long timelength)
{
	unsigned char result;
	unsigned long data;

	data = GetNowTime() - oldtime;

	if(data >= timelength)
		result = 0x00;
	else
		result = 0xFF;	
	     
	return result;     
} 
/******************************************************************************************/


/******************************************************************************************
*     1. imput: billaddr--now addr                                                        *
*               num--which record                                                         *
*               maxn--max number                                                          *
*     2  output:addr                                                                      *
*******************************************************************************************/
unsigned char GetRecordAddr(unsigned char billaddr,unsigned char num,unsigned char maxn)
{
	unsigned char result;
	unsigned long data;
	
	if(billaddr>=num)
	   result=billaddr-num;
	else
	   result=maxn+billaddr-num;   
	     
	return result;     
} 
/******************************************************************************************/


/******************************************************************************************
*     1. use year and month cal numbers of day                                            *
*     2.                                                                                  *
*******************************************************************************************/	
unsigned char CalDay(unsigned char year,unsigned char month) //hex
{
	
	unsigned char DAY_LIMIT[12]={31,0xff,31,30,31,30,31,31,30,31,30, 31};
	if(IsLeapYear(year))
	    DAY_LIMIT[1]=29;
	else
	   DAY_LIMIT[1]=28;
	if(month>12||month==0)
	  return 31;
    return DAY_LIMIT[month-1];
}

/******************************************************************************************/
/******************************************************************************************
*     1. cal two time diffenrce                                                           *
*     2.                                                                                  *
*******************************************************************************************/
double long ComTime(unsigned char *t1,unsigned char *t2)
{
	unsigned char i,j,k,flag;
	signed   long data1,data2;
	double long result;
	unsigned char t11[6],t22[6];
	
	data1=data2=0;
	if(*(t1+0)>*(t2+0))
	   flag=0;
	else if(*(t2+0)>*(t1+0))
	   flag=0xff;
	else if(*(t1+1)>*(t2+1))
	   flag=0;
	else if(*(t2+1)>*(t1+1))
	   flag=0xff;
	else if(*(t1+2)>*(t2+2))
	   flag=0;
	else if(*(t2+2)>*(t1+2))
	   flag=0xff; 
	else if(*(t1+3)>*(t2+3))
	   flag=0;
	else if(*(t2+3)>*(t1+3))
	   flag=0xff;  
	else if(*(t1+4)>*(t2+4))
	   flag=0;
	else if(*(t2+4)>*(t1+4))
	   flag=0xff;      
	
	if(!flag)
	{
	   for(i=0;i<6;i++)
	   {
	      *(t11+i)=OB_H(*(t1+i));
	      *(t22+i)=OB_H(*(t2+i));
	   }
	}
	else
	{
	   for(i=0;i<6;i++)
	   {
	      *(t11+i)=OB_H(*(t2+i));
	      *(t22+i)=OB_H(*(t1+i));
	   }	
	}   
	   	
	for(i=1;i<*(t22+1);i++)
	{
	   data2+=CalDay(*(t22+0),i);
	}
	data2+=*(t22+2);
	
	for(i=*(t22+0);i<*(t11+0);i++)
	{
	   for(j=1;j<=12;j++)
	      data1+=CalDay(i,j);
	}
	
	for(i=1;i<*(t11+1);i++)
	{
	   data1+=CalDay(*(t11+0),i);
	}
	data1+=*(t11+2);
	
	if(!flag)
	   result=data1-data2;
	else
	   result=data2-data1;
	
	result=result*86400l+OB_H(*(t1+3))*3600l-OB_H(*(t2+3))*3600l
	                   +OB_H(*(t1+4))*60l-OB_H(*(t2+4))*60l
	                   +OB_H(*(t1+5))-OB_H(*(t2+5));   
    return result;

}
//double long ComTime(unsigned char *t1,unsigned char *t2)
//{
   /*""直接unsigned long -unsigned long 会出现错误，所以需要利用doublelong 型的a，b临时变量*/
//   double long a;
//   double long b;
//   a=TimeIndex(t1);
//   b=TimeIndex(t2);;
//    return a-b;
//}

/******************************************************************************************/
/******************************************************************************************
*     1. delay xms                                                                        *
*     2.                                                                                  *
*******************************************************************************************/
void Delay(unsigned int ms)
{
	unsigned int i,j;
	if(!IntoPowerDownFlag)
	{
	   for(i=0;i<ms;i++)
	   {
		WDI=~WDI;
		for(j=0;j<990;j++); //when  f1
	   }
	}
	else
	{
	   for(i=0;i<ms;i++)
	   {
		for(j=0;j<990;j++); //when  f8
	   }
	}
}

void CalSendDataLength(unsigned char *pointer)
{
	struct FindCommand_Result *cxp;
	unsigned char num;

	cxp=(struct FindCommand_Result*)pointer;
	        	
	num=4;//liuyq added 2009-8-25
	if(((cxp->id.d[1])&0xf0)==0xA0)
		num=3;  
           
           
	cxp->idt.i=cxp->id.i;   
	switch((cxp->id.d[1])&0xf0)
	{
		case 0x90:
		case 0xA0:
		case 0xB0:
			if(((cxp->id.i)&0x0fff)==0x0fff)
			{
				cxp->idt.i=0x0000;//0x0010|(cxp->id.i&0xf000);
				//cxp->lent=3*8*(Meter_Parameter.SlotParemeter[Meter_Parameter.WhitchSlotIsNow].TriffNumble+1)*num;
				cxp->lent=0;
			}
			else if(((cxp->id.i)&0xffff)==0xB6ff)
			{
				cxp->idt.i=0xB611;
				cxp->lent=3*2+3*2+4*3+4*2+4*2+2+4*2+4*3;
			}
			else if(((cxp->id.i)&0x03ff)==0x00ff)
			{
				cxp->idt.i=0x0010|(cxp->id.i&0xff00);
				cxp->lent=2*(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble+1)*num;
			}
			else if(((cxp->id.i)&0x03ff)==0x01ff)
			{
				cxp->idt.i=0x0010|(cxp->id.i&0xff00);
				cxp->lent=6*(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble+1)*num;
			}
			else if(((cxp->id.i)&0x03ff)==0x03ff)
			{
				cxp->idt.i=0x0010|(cxp->id.i&0xfC00);
				cxp->lent=8*(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble+1)*num;
			}
			else if(((cxp->id.i)&0xB60f)==0xB60f)
	     {
				
				num = (cxp->id.d[0])&0xf0;
				switch(num)
				{
					case 0x10:
					case 0x20:
						cxp->idt.i=0xB600 | num |0x01;
						cxp->lent=6;
						break;
					case 0x30:
					case 0x80:
						cxp->idt.i=0xB600 | num;
						cxp->lent=12;
						break;
					case 0x40:
					case 0x50:
					case 0x70:
						cxp->idt.i=0xB600 | num;
						cxp->lent=8;
						break;
					case 0x60:
						cxp->idt.i=0xB600 | num;
						cxp->lent=2;
						break;
				}
			}          
	   else
	   {
				switch (cxp->id.i)
				{
					case 0xB21f:
					case 0xB31f:
					case 0xB32f:
					case 0xB33f:
					case 0xB34f:
					case 0xA1FF:
					case 0xA3FF:
					case 0xA5FF:
					case 0xA7FF:
					case 0xA9FF:
					case 0xABFF:
					case 0xB1FF:
					case 0xB3FF:
					case 0xB5FF:
					case 0xB7FF:
					case 0xB9FF:
					case 0xBBFF:
					cxp->idt.i=0x0000;
					cxp->lent=0;  
					break;
          default:
           if(((cxp->id.i)&0x000f)==0x000f)
           {
              cxp->idt.i=0x0000|(cxp->id.i&0xfff0);
              cxp->lent=(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble+1)*num;
           }
          break;
				}
	            }
	           break;
           //***************************************          
           case 0xc0:
	           if((cxp->id.i)==0xc01f){
	           	   cxp->lent=7;
	           	   cxp->idt.i=0xc010;
	           }           
	           if((cxp->id.i)==0xc02f){
	           	   cxp->lent=21;
	               cxp->idt.i=0xc020;
	           }
                      
	           break;           
          //***************************************
        }
        cxp->idd.i=cxp->idt.i;
}


/*"============================================================================="*/
/*"作用: 检查密码错误次数,不考虑工厂状态"*/
/*"* 返回值: 无"*/
/*"//added by fxf	2009-09-10"*/
/*"============================================================================="*/
void CheckPasswoerErr(unsigned char P_Lev)
{
      if(!O1ther_Meter_Parameter.WorkRoomState)
      {    
           if(P_Lev>=MAX_PASS_NUM)   
		        return;
           if(Other_Data.PasswordErr[P_Lev].num<99)	
                Other_Data.PasswordErr[P_Lev].num++;
	       if(Other_Data.PasswordErr[P_Lev].num>=Meter_Parameter.parameter2.Meterlocktimes)
	       {
	            if(!Other_Data.PasswordErr[P_Lev].flag)
	       	        Other_Data.PasswordErr[P_Lev].firsttime=softdate;
	            Other_Data.PasswordErr[P_Lev].flag=0xff;
	       }
	       else
	       {
	            Other_Data.PasswordErr[P_Lev].firsttime=softdate;
	       }
		//fxf  modified 081127 3->10
		//liuyq modify 2009-8-24 start
		WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,MAX_PASS_NUM*sizeof(struct PASSWORDERR),0,0);
		//WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,10*sizeof(struct PASSWORDERR),1,0);
		//Write_FM24C256_MULTI(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,10*sizeof(struct PASSWORDERR),FM24C256_1AND2);
	//	Write_FM24C256_MULTI(PASSWORDERR_ROM+P_Lev*sizeof(struct PASSWORDERR),(unsigned char *)&Other_Data.PasswordErr[P_Lev],sizeof(struct PASSWORDERR),FM24C256_1AND2);
		//liuyq modify 2009-8-24 end
	   }
}

/******************************************************************************************/
/******************************************************************************************
*     1. check if change k1                                                               *
*     2.                                                                                  *
*******************************************************************************************/
void Clear_PasswordErr(unsigned char sort,unsigned char level)
{
    unsigned int uni=0,Lev=0;    
    double long data;

	if(level>=MAX_PASS_NUM)   
		return;
    if(sort)
    {
            for(uni=0;uni<sizeof(struct PASSWORDERR);uni++)
              *((unsigned char *)&Other_Data.PasswordErr[level]+uni)=0;
            WRLC256(PASSWORDERR_ROM+level*sizeof(struct PASSWORDERR),(unsigned char *)&Other_Data.PasswordErr[level],sizeof(struct PASSWORDERR),0,0);
	 }
    //else 
	//{   
	//   for(Lev=0;Lev<MAX_PASS_NUM;Lev++)
	//   {
	//	 if(Other_Data.PasswordErr[Lev].flag)
    //     {
    //      data=ComTime((unsigned char *)&softdate,(unsigned char *)&Other_Data.PasswordErr[Lev].firsttime) ;
    //      if(data<-24l*3600l || data>24l*3600l)
    //      {
    //       for(uni=0;uni<sizeof(struct PASSWORDERR);uni++)
    //          *((unsigned char *)&Other_Data.PasswordErr[Lev]+uni)=0;
	//		WRLC256(PASSWORDERR_ROM,(unsigned char *)&Other_Data.PasswordErr,MAX_PASS_NUM*sizeof(struct PASSWORDERR)+1,0,0);
    //      }  
    //     }
	//    }
    //}
}

/*"============================================================================="*/
/*"作用: 验证密码,不考虑工厂状态"*/
/*"* 返回值: 
0-9:正确;
0x80-89:密码错误;
0xff:密码级别超过10*"*/
/*"//added by fxf	2009-09-10"*/
/*"============================================================================="*/
unsigned char CheckPasswordRight(unsigned char * addr)
{
        unsigned char i,j,password_level;
        unsigned char result;

	result=0xff;    
	password_level=*addr;
	if(password_level<MAX_PASS_NUM)
	{
            for(j=0;j<4;j++)
            {
                if(*(addr+j)!=*((unsigned char *)&Meter_Parameter.parameter1.ClearPassword[password_level]+j))
                {
                        result=0;
                        break;
                }
            }
	}
	else
	{
             result=0x66;/*"密码级别超范围"*/
	}
       
    if(result==0xff) return password_level; /*"密码正确"*/      
	else if(result==0)  return 0x80|password_level;/*"密码级别在范围内但是密码错误"*/
    else   return 0xff;/*"密码级别超范围"*/
}

void  Caarr(unsigned int EEAddr ,unsigned char* RamAddr,unsigned char sort,unsigned char type)
{
   unsigned  char shift[4]={4*MAXTRIFF,4,12,4};
   unsigned num=0;
   unsigned char i;
   if(type==0)//active
   num=2;
   else if(type==1)//rective
   num=4;
   
   if(EEAddr)
   {
        for(i=0;i<num;i++)
   	 Co.c.addre[i]=EEAddr+shift[sort]*i;
	
   }
   if(RamAddr)
   {
         for(i=0;i<num;i++)
   	 Co.c.addrr[i]=RamAddr+shift[sort]*i;
   }  
}

//liuyq added 2009-8-26 start
void Postfix_WriteDatetime(void)
{
//	Write_Date_AndOr_Time((unsigned char*)&softdate,0,2);
    ClockChipWrite((unsigned char *)&softdate);
//	Read_Date_And_Time((unsigned char*)&softdate,0);
	ClockChipRead((unsigned char *)&softdate);
	Co.c.len=0; 
	if(CheckTime((unsigned char *)&softdate))
		{
			MainRamDate2=MainRamDate1=MainSoftDate;
		}
							 
	ClearDemandArea(0);
	Seg();
	FindTriff();
}

#pragma SECTION rom UserROMData
const unsigned char rominstandata[28]={0x11,0x12,0x13,
                                       0x21,0x22,0x23,
                                       0x30,0x31,0x32,0x33,
                                       0x40,0x41,0x42,0x43,
                                       0x50,0x51,0x52,0x53,
                                       0x60,
                                       0x70,0x71,0x72,0x73,
                                       0x80,0x81,0x82,0x83,0x83};
//#pragma SECTION program program_protect
void CalSendLaterDataID(unsigned char *pointer,unsigned char uartx)
{
        struct FindCommand_Result *cxp;
        unsigned char *P;
        unsigned char num;
        
        cxp=(struct FindCommand_Result*)pointer; 
	
	if(uartx<3)
		   P=(unsigned char*)&CommB[uartx]; 
	//liuyq modify 2009-8-21 end
        
        switch((cxp->idd.d[1])&0xf0)
        {
           case 0x90:
           case 0xA0:
           case 0xB0:
           
           if(((cxp->idd.i)&0xff00)==0xB600)
           {
              for(num=0;num<28;num++)
              {
                 if(rominstandata[num]==cxp->idd.d[0])
                 {
                    cxp->idd.d[0]=rominstandata[num+1];
                    break;
                 }
              }
              cxp->idt=cxp->idd; 
              if((rominstandata[num]==0x13 || 
                  rominstandata[num]==0x23 ||
                  rominstandata[num]==0x33 ||
                  rominstandata[num]==0x43 ||
                  rominstandata[num]==0x53 ||
                  rominstandata[num]==0x60 ||
                  rominstandata[num]==0x73 ||
                  rominstandata[num]==0x83) &&
                  (cxp->lent))
              {
                 *(P+12+cxp->lena)=0xAA;
                 cxp->lent++;
                 cxp->lena++;
              }   
           }
           
           else
           {
              if((cxp->idd.d[0]&0x0f)==Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble)
              {
                 if(cxp->idd.d[1]&0x01)
                 {
                    cxp->idd.d[0]=cxp->idd.d[0]+0x10;
                 }
                 else if((cxp->idd.d[0]&0xF0)==0x10)
                 {
                    cxp->idd.d[0]=cxp->idd.d[0]+0x10;
                 }
                 else if((cxp->idd.d[0]&0xF0)==0x20)
                 {
                    cxp->idd.d[0]=cxp->idd.d[0]-0x10;
                    cxp->idd.d[1]=cxp->idd.d[1]+0x01;
                 }
                 cxp->idd.d[0]=cxp->idd.d[0]&0xf0;
                 
                 if(cxp->lent)
                 {
                    *(P+12+cxp->lena)=0xAA;
                    cxp->lent++;
                    cxp->lena++;
                 }   
              } 
              else 
              {
                 cxp->idd.d[0]++;
              }
              cxp->idt=cxp->idd;
           }
           break;
           case 0xc0:
           //***********************************************************
           if((((cxp->idd.i)==0xC011) || ((cxp->idd.i)==0xC028)  ) &&
                  (cxp->lent))
           {
                  *(P+12+cxp->lena)=0xAA;
                  cxp->lent++;
                  cxp->lena++;
           }
           else
           {
                  cxp->idd.d[0]++;
                  cxp->idt=cxp->idd;
           }
           //***********************************************************
           break;
        } 
}

#ifdef  PASSWORD_MODE
/******************************************************************************************/
/*"addr:密码级别和密码 ,level为需要的密码等级   ""*/
/*"FXF  081127    ""*/
/******************************************************************************************/
unsigned char CheckPasswordProgram_New(unsigned char *addr,unsigned char level)
{
        unsigned char ok=0,Ret=0;
        if(!O1ther_Meter_Parameter.WorkRoomState)
        {
           ok=CheckPasswordRight(addr);
		   if(ok<=9)/*"密码正确"*/
	       { 
	         		if(!(Other_Data.PasswordErr[ok].flag))
	         		  {    
	          			    if(ok<=level)	         		         	
	                 			Ret=0xff;
	              			 else 	Ret=0;   

					        Clear_PasswordErr(1,ok);
	           		   }
	           		else Ret=0;	         	
	       }
	       else
	       {
	            if(ok!=0xff)/*"密码级别在范围内但是密码错误"*/
                    CheckPasswoerErr(ok&0x7f);
                Ret=0;
                Meter_States.ErrOfInformation.bit.Invalid_Password=1;                   
	       }
	    }
	    else
	    {
	              Ret=0xff;
	    }
	    return Ret;         
}
#endif

//*"============================================================"*/
/*"函数名：Freeze_Command_New"*/
/*"用途：新645冻结命令"*/
/*"参数：无"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
void Freeze_Command_New(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok;//,n liuyq delete 2009-8-24
	struct FindCommand_Result *pc;
	unsigned int uni;
	unsigned char pointer=0;//pointer1, liuyq delete 2009-8-24
	struct DATA_TIME freeze_time;
	
	//unsigned long datac=0; liuyq delete 2009-8-24
	
	unsigned int i;	
		   
	ok=0;
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
	
	for(i=0;i<4;i++)
	{
		Co.c.f[i]=*(p+cx[3].addr)-0x33;
		cx[3].addr++;
		if(cx[3].addr>=B_FL) cx[3].addr=0;	    
	}

	if( (pc->len==0x04)&&(farinfrareddisableflag==0))
	{
		ok=0xff;
		freeze_time.Year=0;
		freeze_time.Sec=0;
		
		for(i=0; i<4; i++)
		{
			if(Co.c.f[i]==0x99)
				//freeze_time.Hour=i/2;
				*((unsigned char*)&freeze_time + 4 -i) = i/2;
			else
				*((unsigned char*)&freeze_time + 4 -i) = Co.c.f[i];
		}
		
		
		//if((Co.c.f[3]==0x99)&&(Co.c.f[2]==0x99)&&(Co.c.f[1]==0x99)&&(Co.c.f[0]==0x99))
		if(*((unsigned long*)&Co.c.f[0]) == 0x99999999)
		//liuyq modify 2009-8-24 end
		{
		    /*"立即冻结"*/
		    ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Moment_addr
		    ,FREEZE_MOMENT_SORT_START_FILE);/*"冻结清零判断处理"*/
		    
		    pointer=O1ther_Meter_Parameter.FreezeData_Moment_addr;
        FreezeDateProgram(FREEZE_MOMENT_SORT_START_FILE+pointer, 1, (unsigned char *)&softdate);///king chen modify 130609
		   	pointer++;
		   	pointer%=MAX_NUMBER_FREEZE_MOMENT;		   		
		   	O1ther_Meter_Parameter.FreezeData_Moment_addr=pointer;
			//liuyq modify 2009-8-24 start
		   	WRLC256(FREEZE_MOMENT_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Moment_addr,1,0,0);
		   	////Set_Meter_para_Deal(FREEZE_MOMENT_ADDR_ROM);
		//	WRLC256(FREEZE_MOMENT_ADDR_ROM,(unsigned char *)&Meter_Parameter.FreezeData_Moment_addr,1,1,0);
		//	Write_FM24C256_MULTI(FREEZE_MOMENT_ADDR_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.FreezeData_Moment_addr,1,FM24C256_1AND2);
			//liuyq modify 2009-8-24 end
		   	FeedWatchdog(); 
				
		  }
		//else if(Time_Valid(freeze_time)==0)
		else if(CheckTime((unsigned char *)&freeze_time))
		{	/*"定时冻结"*/
			 for(i=0;i<4;i++)
				  Meter_Parameter.freeze_parameter.FreezeDate[i]=Co.c.f[i];
			 //liuyq modify 2009-8-24 start
			 WRLC256(FREEZEDATE_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.FreezeDate,4,0,0);
			 Set_Meter_para_Deal(FREEZEDATE_ROM);
		  //  	 WRLC256(FREEZEDATE_ROM,(unsigned char *)&Meter_Parameter.FreezeDate,4,1,0);
		
			// Write_FM24C256_MULTI(FREEZEDATE_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.FreezeDate,4,FM24C256_1AND2);
			 //liuyq modify 2009-8-24 end
		}
		else
		{		
			Meter_States.ErrOfInformation.bit.Invalid_Data=1;
			ok=0;/*"数据标识错误，无请求数据"*/
		
		}
	}
	else 
	{  
		if(farinfrareddisableflag==1)
			  Meter_States.ErrOfInformation.bit.Invalid_Password=1;
		else
		    Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		
		ok=0;
	}
	
	if(pc->BroadCasrAddress==0)
	{
			if(ok!=0)
			{		
				pc->ct=0x96; /*"正确应答"*/
	   		Co.c.len=0;
	   		pc->lena=0;
	   		pc->lent=0;
	   		pc->havebackframe=0;	 	   
			}
			else
			{
				pc->ct=0xD6; /*"错误应答"*/
	  		Co.c.len=1;
	  		pc->lena=1;
	   		pc->lent=0;
		 	  pc->havebackframe=0;	   
	  		p[10]=Meter_States.ErrOfInformation.byte;
		 	}
	}
	else  /*"广播冻结不应答fuxf081209   "*/
	{		
	      pc->ct=0;
	      Co.c.len=0;
	      pc->lena=0;	   
	}
}

/*"============================================================"*/
/*"函数名：Set_Multi_Function_Terminal_Output"*/
/*"用途：多功能端子输出控制设置"*/
/*"参数：无"*/
/*"返回：无"*/
/*"作者：fuxf 版本：1.00"*/
/*"============================================================"*/
void Set_Multi_Function_Terminal_Output(unsigned char uartx)
{
	unsigned char *p;
	unsigned char ok,Output;
	struct FindCommand_Result *pc;
	
	ok=Output=0;
	
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
	//liuyq modify 2009-8-21 end
		
	 Output=*(p+cx[3].addr)-0x33;
	   
	if(( pc->len==0x01)&&(Output<=2)&&(farinfrareddisableflag==0))
	{
		ok=0xff;
		if(Output==2)
	       {
			DemandputoutNum=0;
			DemandOutPutflagdata=0;
			DemandOutPutflag=0;
	       }
	       O1ther_Meter_Parameter.OutputModel=Output;
	       Output_On_3_In_1_Terminal_Set(0);
		
	}
	else 
	{  
		if(farinfrareddisableflag==1)
			  Meter_States.ErrOfInformation.bit.Invalid_Password=1;
	  else
		    Meter_States.ErrOfInformation.bit.Invalid_Data=1;
		
		ok=0;
	}
	
	if(pc->BroadCasrAddress==0)
	{
			Co.c.len=1;
	   		pc->lena=1;
	   		pc->lent=0;
	   		pc->havebackframe=0;
			if(ok!=0)
			{		
			pc->ct=0x9D; /*"正确应答"*/	   		
			p[10]=O1ther_Meter_Parameter.OutputModel;
			}
			else
			{
			pc->ct=0xDD; /*"错误应答"*/	  		
	  		p[10]=Meter_States.ErrOfInformation.byte;
		 	}
	}
	else  /*"广播不应答  "*/
	{		
	      pc->ct=0;
	      Co.c.len=0;
	      pc->lena=0;	   
	}
}
/**************************************************************/
#define YYMMDDWW  0x01
void Read_SystemTime(unsigned char type)
{
       unsigned char i=0;
 	unsigned char *p;
	if(!IntoPowerDownFlag)
	{  
		p=(unsigned char*)&softdate;
	}
	else
	{
		if(pdmode1 && Meter_Parameter.parameter1.MeterMode[1].bit.b0)
		{
		       p=(unsigned char*)&Powerdown_Save_Data.date;
           MainSoftDate=Powerdown_Save_Data.date;
		}
		else
		{
		  //     Read_Date_And_Time((unsigned char*)&Co.c.h,0);
		  ClockChipRead((unsigned char *)&Co.c.h);
		  
		  if(CheckTime((unsigned char *)(&Co.c.h[0])))
		  {
		    MainSoftDate=*((struct DATEANDTIME_DEF *)&Co.c.h);		 
		    p=(unsigned char*)&Co.c.h;
		  }
		  else
		  {
		  	p=(unsigned char*)&Powerdown_Save_Data.date;
        MainSoftDate=Powerdown_Save_Data.date;
		  }
		}
	}
	if(type==YYMMDDWW)
	{
	    for(i=0;i<3;i++)
	   *( Readdata_buff+i)=*(p+i);
	     Readdata_buff[3]=*(p+6);
	}
	if(type==HHMMSS)
	{
	    for(i=0;i<3;i++)
	 	*(Readdata_buff+i)=*(p+i+3);
	}
	
}
void  Read_SystemTime_YMDH(void)
{
     Read_SystemTime(YYMMDDWW);
}
void Read_SystemTime_HMS()
{
     Read_SystemTime(HHMMSS);
}

int  Read_WorkRoomState(void)
{
		 
	if(O1ther_Meter_Parameter.WorkRoomState)
		Readdata_buff[0]=	1;
	else	  Readdata_buff[0]=0;

	return 0;     
}

//liuyq modify 2009-8-19 start
int Read_Freezedata(unsigned char Type)
{
      if(((Read_Com_ID.new_i[1]==0x0500)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Time_Mode.byte &(1<<Type)))
      ||((Read_Com_ID.new_i[1]==0x0501)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Moment_Mode.byte &(1<<Type)))
      ||((Read_Com_ID.new_i[1]==0x0502)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Promise_Mode.byte &(1<<Type)))
      ||((Read_Com_ID.new_i[1]==0x0503)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Promise_Mode.byte &(1<<Type)))
      ||((Read_Com_ID.new_i[1]==0x0504)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Period_Mode.byte &(1<<Type)))
      ||((Get_Payment_Flag()==OK)&&(Read_Com_ID.new_i[1]==0x0505)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Promise_Mode.byte &(1<<Type)))	//payment
      ||((Get_Payment_Flag()==OK)&&(Read_Com_ID.new_i[1]==0x0507)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Promise_Mode.byte &(1<<Type)))
      ||((Read_Com_ID.new_i[1]==0x0506)&&(Meter_Parameter.freeze_parameter.New645_Freeze_Day_Mode.byte &(1<<Type))))
            return  0;     	
      else   
          {  
          	Meter_States.ErrOfInformation.bit.Invalid_OBIS=1; 
          return  -1;
		  }
}
/*" 读冻结数据第1类数据 "*/
int  Read_Freeze_Bit_0_data()
{	     	

	return Read_Freezedata(0); 	      
}

/*" 读冻结数据第2 类数据 "*/
int  Read_Freeze_Bit_1_data()
{	     	

	return Read_Freezedata(1); 	      
}
/*" 读冻结数据第3 类数据 "*/
int  Read_Freeze_Bit_2_data()
{	     	

	return Read_Freezedata(2); 	      
}
/*" 读冻结数据第4 类数据 "*/
int  Read_Freeze_Bit_3_data()
{	     	

	return Read_Freezedata(3); 	      
}
/*" 读冻结数据第5 类数据 "*/
int  Read_Freeze_Bit_4_data()
{	     	

	return Read_Freezedata(4); 	      
}
/*" 读冻结数据第6类数据 "*/
int  Read_Freeze_Bit_5_data()
{	     	

	return Read_Freezedata(5); 	      
}
/*" 读冻结数据第7类数据 "*/
int  Read_Freeze_Bit_6_data()
{	     	

	return Read_Freezedata(6); 	      
}
/*" 读冻结数据第8类数据 "*/
int  Read_Freeze_Bit_7_data()
{	     	

	return Read_Freezedata(7); 	      
}


/*" 读冻结时间 "*/
int  Read_Freeze_Date()
{	
	unsigned char i;
	for(i=0;i<4;i++)
		 Readdata_buff[i]=Meter_Parameter.freeze_parameter.FreezeDate[3-i];
		 
  return  0;
}

/*" 读调制型红外波特率固定为1200BPS "*/
int  Read_Far_IR_Commate()
{	

  Readdata_buff[0]=0x04;
	
  return  0;
}

/*" 读密码错误次数，剩余闭锁时间"*/
int  Read_Meter_lock_times()
{	

      unsigned long datac=0;
	  
	Readdata_buff[0] = 0;  
	Readdata_buff[1] = 0; 
	Readdata_buff[2] = 0;  
	Readdata_buff[3] = 0;  
#ifdef  PASSWORD_MODE
      datac=ComTime((unsigned char *)&softdate,(unsigned char *)&Other_Data.PasswordErr[4].firsttime);
      datac/=60l; 	
      if(datac>1440)
            datac=0;
      datac=1440-datac; 	
      if(!Other_Data.PasswordErr[4].flag)
            datac=0;
      				 
      HexToBcd(3,(unsigned char *)&datac,(unsigned char *)&Readdata_buff[0]); 	
      Readdata_buff[3]=OH_B(Other_Data.PasswordErr[4].num);
#endif

      return  0;
}

/*" 读电表版本号"*/
int  Read_Meter_FILEDATE_VI(void)
{	
       Readdata_buff[0]=FILE_DATE[2];						/*"归档时间 年"*/	
	   Readdata_buff[1]=FILE_DATE[1];						/*"归档时间 月"*/	
	   Readdata_buff[2]=FILE_DATE[0];						/*"归档时间 日"*/	
	   Readdata_buff[3]=(I_REGION<<4)|V_REGION; 	/*"电流量程"*//*"电压量程"*/

      return  0;
}
/*" 读电表温度"*/
int  Read_Meter_Temperature(void)
{	 
      int temp=0;
 //     Read_Temperature((int *)&temp, 0);
      Temperature_Current = temperatrue;//temp *100l / 4l;		  
      return  0;
}
int  Read_YearSlot_Table(void)
{	 
      if(Leaf_num_now>Meter_Parameter.parameter1.SlotParemeter[0].YearSlotNumble)
            return -1;
      else 
            return 0;
}
int  Read_DailySlot_Table(void)
{	 
      if(Leaf_num_now>Meter_Parameter.parameter1.SlotParemeter[0].DailySlotNumble)
            return -1;
      else 
            return 0;
}

void  Read_Last_loss_voltage_time(unsigned char type)//0 start 1 end
{	 
      unsigned char i,j,k;

      if(type==0)
            WRLC256(LASTLOSTVOLTBEGINTIME_A_ROM, (unsigned char *)&Co.b[400], 36, 0, 1);	 
      else
      {     
            if(Event_Power_Net_Flag.bit.LostVoltage_A||Event_Power_Net_Flag.bit.LostVoltage_B||Event_Power_Net_Flag.bit.LostVoltage_C)
            {      	
                for(j=0;j<6;j++)
                    Readdata_buff[j]=0; 
                return;
            }
            WRLC256(LASTLOSTVOLTBEGINTIME_A_ROM+6,(unsigned char *)&Co.b[400],30,0,1);	  	  
      }
      if(Check_Data_valid((unsigned char *)&Co.b[400],6)==-1)
      {
            for(j=0;j<6;j++)	Co.b[400+j]=0x0;
      }
      for(j=0;j<6;j++)   Readdata_buff[j]=Co.b[400+j];
		       
      for(j=1;j<3;j++)
      {
            if(Check_Data_valid((unsigned char *)&Co.b[400+12*j],6)==-1)
            {
                  for(i=0;i<6;i++)	Co.b[400+12*j+i]=0x0;
            }
            for(i=0;i<6;i++)
            {
                  if(Co.b[400+12*j+i]>Readdata_buff[i])
                  {
                        for(k=0;k<6;k++)
                           {
                              Readdata_buff[k]=Co.b[400+12*j+k];
                           }	
                           break;	
                  }
                  else if(Co.b[400+12*j+i]<Readdata_buff[i])
                  {						    
                  	  break;
                  } 
            }
      }	 
	   
      for(i=0;i<6;i++)
      {	  	
      	if(Readdata_buff[i]!=0)
      		break;
      }
      if(i==6)
      {
      	for(j=0;j<6;j++)
             Readdata_buff[j]=0xff;
      }	 
}

/*" 读最近一些失压起始时间"*/
int  Read_Last_loss_voltage_start_time(void)
{	 
     Read_Last_loss_voltage_time(0);
     
     return 0;
}
/*" 读最近一些失压结束时间"*/
int  Read_Last_loss_voltage_end_time(void)
{	 
    Read_Last_loss_voltage_time(1);
    
    return 0;
}
int  Read_LostVoltEnergy(void)
{  
    return PrepLostVoltEnergyData(Read_Com_ID.l);
}
int  Read_LostVolt_AllEnergy(void)
{
   
   PrepLostVoltEnergyData(0x10010003);
   PrepLostVoltEnergyData(0x10020003);
   PrepLostVoltEnergyData(0x10030003);
   
   lostvoltenergyall[0]=(lostvoltenergy[0]+lostvoltenergy[2]+lostvoltenergy[4])%1000000000L;
   lostvoltenergyall[1]=(lostvoltenergy[1]+lostvoltenergy[3]+lostvoltenergy[5])%1000000000L;
   
   return 0;
}

/*"读有符号瞬时量"*/
int Read_Sign_Instance_Variable(void)
{
	unsigned char n;  
	
	for(n=0;n<3;n++) 
	   COMM_Curr[n]=Curr[n];
	 
	for(n=0;n<4;n++) 
	{
		   COMM_Active_power[n]=Active_power[n];
		   COMM_Reactive_power[n]=Reactive_power[n];
		   COMM_Visual_power[n]=Visual_power[n];		
		   COMM_Factor[n]=Factor[n];		   
	}	 
		
	/*"当前功率因素"*/		
	/*"当前电流"*/
	/*"当前有功功率"*/
	/*"当前视在功率"*/
	/*"当前无功功率"*/
	
	/* T */
	if(NEW645Meter_States.Meter_Status1.bit.ActivePower_Direct==1)
	{
		COMM_Active_power[0]=0-Active_power[0];		
		COMM_Visual_power[0]=0-Visual_power[0];	
		COMM_Factor[0]=0-Factor[0];
	}
	
	if(NEW645Meter_States.Meter_Status1.bit.ReActivePower_Direct==1)
		COMM_Reactive_power[0]=0-Reactive_power[0];
	
	/* A B C */
	for(n=0;n<3;n++)
	{
		if(((NEW645Meter_States.Meter_Status2.intd>>n)&0x0001)!=0)
		{
			COMM_Curr[n]=0-Curr[n];
		  COMM_Active_power[1+n]=0-Active_power[1+n];		
		  COMM_Visual_power[1+n]=0-Visual_power[1+n];	
		  COMM_Factor[1+n]=0-Factor[1+n];
		}
		if(((NEW645Meter_States.Meter_Status2.intd>>(4+n))&0x0001)!=0)
		{
			COMM_Reactive_power[1+n]=0-Reactive_power[1+n];
		}
	}
	
  return 0;
}


/*"------------新645 写函数-----"*/
/*"作用: 新645写 系统时间函数"*/
int  Set_SystemTime_YMDH(void)
{
	unsigned char n;
	struct FindCommand_Result *pc;
        int result=0;
         
	pc=(struct FindCommand_Result *)&cx[3]; 
	
	 for(n=0;n<4;n++)
	{
		Co.c.h[3-n]=*(Co.c.addr5+n);
		if(!CheckBCD(*(Co.c.addr5+n)))
		return -1;	
	}
	 if(Co.c.h[0]<=0x99 && Co.c.h[1]<=0x12 && Co.c.h[1] && Co.c.h[2] && OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1]))
	 	&& Co.c.h[3]<=0x99)
	{
    for(n=0;n<6;n++)
		{
			Co.b[404+n]=*((unsigned char *)&softdate+n);  
			if(n<3)
				Co.b[410+n]=Co.c.h[n]; 
			else
				Co.b[410+n]=*((unsigned char *)&softdate+n); 
		}
		/*"   记录校时事  "*/
		if(AdjustTimeRecord(pc->Programer_code)==0)
			   return -1; 		
		for(n=0;n<5;n++)
			Co.b[309-n]=*((unsigned char *)&softdate+n);	
		for(n=0;n<3;n++)
			*((unsigned char*)&softdate+n)=Co.c.h[n];
		*((unsigned char*)&softdate+6)=Co.c.h[n]; 

		Postfix_WriteDatetime();	
        
	}
	 else	
		 result=-1;
	return result;
}

/*"作用: 新645写 系统时间函数"*/
int  Set_SystemTime_HMS(void)
{
	unsigned char n;
	struct FindCommand_Result *pc;
	int result=0;

	pc=(struct FindCommand_Result *)&cx[3];
	
	for(n=0;n<3;n++)
	{
		Co.c.h[2-n]=*(Co.c.addr5+n);
		if(!CheckBCD(*(Co.c.addr5+n)))
	      	return -1;      
	}
	if(Co.c.h[0]<=0x23 && Co.c.h[1]<=0x59 && Co.c.h[2]<=0x59)
	{		
		for(n=0; n<6; n++)
		{
			if(n<3)
			{
				Co.b[413+n]=Co.c.h[n]; 
				Co.b[410+n]=*((unsigned char *)&softdate+n); 
			}
			Co.b[404+n]=*((unsigned char *)&softdate+n);  
		}
       	//liuyq 2009-8-26 end
	     /*"   记录校时前的 时间 "*/
		if(AdjustTimeRecord(pc->Programer_code)==0)
		 	return -1; 			 	      	             	   	      	          
	     for(n=0;n<3;n++)
			*((unsigned char*)&softdate+n+3)=Co.c.h[n];		
		Postfix_WriteDatetime();
        
	}
	else	      	   
		result=-1;
	   
	return result;    
		
}

int  Set_SystemTime_YMDHHMS(void)
{
	unsigned char n;
	struct FindCommand_Result *pc;
	int result=0;

	pc=(struct FindCommand_Result *)&cx[3];
	
	for(n=0;n<3;n++)
	{
		Co.c.h[5-n]=*(Co.c.addr5+n);
		Co.c.h[2-n]=*(Co.c.addr5+4+n);     
	}
	Co.c.h[6]=*(Co.c.addr5+3);
	for(n=0;n<7;n++)
	{
		if(!CheckBCD(Co.c.h[n]))
	      	return -1;      
	}
	
	
	if((Co.c.h[3]<=0x23)&&(Co.c.h[4]<=0x59)&&(Co.c.h[5]<=0x59)
	  &&(Co.c.h[0]<=0x99)&&(Co.c.h[1]<=0x12)&&(Co.c.h[1]!=0)&&(Co.c.h[2]!=0)
	  &&(OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))&&(Co.c.h[6]<=0x99))
	{		
		for(n=0; n<6; n++)
		{
			Co.b[410+n]=Co.c.h[n]; 
			Co.b[404+n]=*((unsigned char *)&softdate+n);  
		}

		if(AdjustTimeRecord(pc->Programer_code)==0)
		 	return -1;
		 	 			 	      	             	   	      	          
	  for(n=0;n<6;n++)
			*((unsigned char*)&softdate+n)=Co.c.h[n];		
		Postfix_WriteDatetime();
        
       }
	else
	{	      	   
		result=-1;
	}
	   
	return result;  	
}

int Set_Period(unsigned char  Type)
{
      unsigned char Flag;
      //int result=0;

      if(((*Co.c.addr5)>0x60)||((*Co.c.addr5)==0))
            return -1; 
      Flag = OB_H(*Co.c.addr5);
      if(Type)
            Flag = Meter_Parameter.parameter1.DemandPeriod % Flag;
      else
            Flag =  Flag % Meter_Parameter.parameter1.DemandSkipPeriod;
      if(Flag)
            return -1;    
      ClearDemandArea(0);    

      return 0;
}

/*"  	设置需量周期 "*/
int  Set_DemandPeriod(void)
{
	
	return Set_Period(0);
	
}

/*"  	设置需量滑差周期 "*/
int  Set_DemandSkipPeriod(void)
{
	
	return Set_Period(1);
}

/*"  	设显示能量和需量小数点 "*/
int  Set_Erengypoint(void)
{
	int result=0;
	struct FindCommand_Result *pc;
	pc=(struct FindCommand_Result *)&cx[3];
	
	if(pc->idt.l==0x04000303)
	{
		 ///if((*Co.c.addr5)!=2 && (*Co.c.addr5)!=3)
		 if((*Co.c.addr5)>3)
			 return -1;  
	}
	else  if(pc->idt.l==0x04000304)
	{
		 ///if(((*Co.c.addr5)!=2)&&((*Co.c.addr5)!=3)&&((*Co.c.addr5)!=4))
		  if((*Co.c.addr5)>MAXDAUTOVALUE)
			return -1; 	
	}
	else
			return -1;  
	
	return 0;
}
//liuyq added 2009-8 start
/*"  	设置有无功组合方式字 "*/
int Set_Mode(unsigned char Mode)
{
	struct FindCommand_Result *pc;
	unsigned char* P;
	//int result=0;

	pc=(struct FindCommand_Result *)&cx[3];
	P = (unsigned char*)&Meter_Parameter.parameter1.Activem_Erengy_Mode;
	if(ProgAEMode_NEMode1_NEMode2_Record(pc->Programer_code,*(P+Mode),Mode)==0)
		return -1;
	
	Output_On_3_In_1_Terminal_Set(7);
	
	return 0;
}

/*"  	设置有功组合方式字 "*/
int  Set_Activem_Erengy_Mode(void)
{
	
	return Set_Mode(0);  
	//mw modified 2009-09-03
}

/*"  	设置无功组合方式1 "*/
int  Set_REActivem_Erengy_1_Mode(void)
{
	
	return Set_Mode(1);
	//mw modified 2009-09-03
}

/*"  	设置无功组和方式2 "*/
int  Set_REActivem_Erengy_2_Mode(void)
{	
	return Set_Mode(2);
	//mw modified 2009-09-03
}



/*"  	设置有功无功脉冲常熟式 "*/
int  Set_ActivePulseConst(void)
{
	//int result=0;
	unsigned long  datat=0;
	struct FindCommand_Result *pc;
	pc=(struct FindCommand_Result *)&cx[3];

	
	BcdToHex(3,Co.c.addr5,(unsigned char *)&datat);    
	                
  if(!Send_Pulse_Constant_Data_to_Meter((pc->idt.d[0]-0x09),datat))
		return -1;
	
	return 0;
}


/*"  	设置结算日 "*/
int Set_BILL_Day(void)
{
      struct FindCommand_Result *pc;
      //int result=0;
      unsigned char n;
      union byte_def billdatevaty;

      pc=(struct FindCommand_Result *)&cx[3];

      for(n=0;n<2;n++)
      {			
            if(!CheckBCD(*(Co.c.addr5+n)))
                  return -1;	
      }	

      if(pc->id.l==0x04000B01)/*"必须设置第一结算日有效,日期最大允许设置为28,结算日不允许重复"*/
      {
            if(((*(Co.c.addr5+1))>0x28)||((*(Co.c.addr5+0))>0x23) ||(!(*(Co.c.addr5+1)))) 
                  return -1; 
			//----------------------------------------------------//
			//Li Update 20130327
			//----------------------------------------------------//
			//Pre_Bill(&MainSoftDate.Year);
			My_Memcpy( (unsigned char *)&Pre_Power_Down_Save_Data.Energy_Next_Step,0,4);
			Pre_Moneth_Updata();
			Pay_For_Data_Save();
            Retort_New(0,(unsigned char *)&softdate);
			//----------------------------------------------------//
      }
      else if((pc->id.l==0x04000B02)||(pc->id.l==0x04000B03))
      {
            ///if((((*(Co.c.addr5+1))>0x28)||((*(Co.c.addr5+1))==0))&&((*(Co.c.addr5+1))!=0x99))
            ///      return -1;
            ///if(((*(Co.c.addr5+0))>0x23)&&((*(Co.c.addr5+0))!=0x99))
            ///      return -1;  
        if(((*(Co.c.addr5+0))==0x99)&&((*(Co.c.addr5+1))==0x99))
        {
        }
        else if(((*(Co.c.addr5+1))>0x28)||((*(Co.c.addr5+0))>0x23) ||(!(*(Co.c.addr5+1)))) 
        {
            return -1;
         }

      }
      else 
            return -1;

      n=pc->id.l-0x04000B01;
      if(Check_Billdate_Validity(Co.c.addr5,n)==0)/*"结算日不允许重复"*/
            return -1;

      if(ProgBillDayRecord(pc->Programer_code,(unsigned char *)&Meter_Parameter.parameter1.AutoBillDayHour[0])==0)
            return -1;

      return 0;
}

/*"  	设置时区时段表参数函数 "*/
int Set_SlotParemeter(void)
{
      struct FindCommand_Result *pc;
      unsigned char data=0;
      unsigned int data_i=0;
      //liuyq modify 2009-10-15 start
      unsigned char SoltNumbers[] = {MAXYEARSLOT, MAXDAILYSLOTTABLE, MAXDAILYSLOT,32,MAXHOLIDAYSLOT};
      unsigned long SoltMarkCode;
      
      pc=(struct FindCommand_Result *)&cx[3];
      if(pc->idt.l==0x04000205)	/*" 设公共假日数 "*/
            BcdToHex(2,Co.c.addr5,(unsigned char *)&data_i); 
      else
            BcdToHex(1,Co.c.addr5,(unsigned char *)&data); 

      
            if(pc->idt.l > 0x04000200 && pc->idt.l  <0x04000206)
             {
                  SoltMarkCode = pc->idt.l&0x000000ff;
                  if(SoltMarkCode <5)
                        data_i = data;
                  if(data_i>SoltNumbers[SoltMarkCode-1])
                  {
                        if(SoltMarkCode == 1)
                              Meter_States.ErrOfInformation.bit.OutYearZone=1;
                        else if(SoltMarkCode == 3)
                              Meter_States.ErrOfInformation.bit.OutDailySlot=1;
                        else if(SoltMarkCode == 4)
                        {
                              Meter_States.ErrOfInformation.bit.OutTriff=1;
                        }
                        return-1;
                  }
                  if(SoltMarkCode <5 && data_i==0)
                        return -1;
            }
            else
                  return -1;
	if(SoltMarkCode == 4)
		{
      Max_Triff_Current=data;
      if (Max_Triff_Current>(MAXTRIFF-1))
			  Max_Triff_Current=MAXTRIFF-1;
			
			WRLC256(SLOTPAREMETER1_ROM+3,&Max_Triff_Current,1,0,0);
			WRLC256(SLOTPAREMETER1_ROM+3,&Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble,1,0,1);
			Set_Meter_para_Deal(SLOTPAREMETER1_ROM+3);
			
			if(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble!=Max_Triff_Current)
			  return -1;
		}
      return 0;
}



/*"  	设置时段表 "*/
int Set_DailySlot(void)
{
      struct FindCommand_Result *pc;
      unsigned char i,n,slotnumber;	
      unsigned int eepromaddr;
      unsigned char result=0;
      unsigned char set_parameter_len;
      unsigned char j;
      unsigned int uni;
      unsigned int ddt[2];
      unsigned char datat[3];
	    unsigned int interval;
	    unsigned int time1,time2;

      pc=(struct FindCommand_Result *)&cx[3];
      set_parameter_len=pc->len-12;
      
      if(set_parameter_len>42)
      {
      	Meter_States.ErrOfInformation.bit.OutDailySlot=1;
      	return -1;
      }
      if((set_parameter_len==0)||((set_parameter_len%3)!=0))
      {
      	Meter_States.ErrOfInformation.bit.Invalid_Data=1;
      	return -1;
      }

      for(i=0;i<set_parameter_len;i++)
      {
        if(*(Co.c.addr5+i)!=0)
        {
            result=0xff;
            break;
         }
      }
      set_parameter_len=set_parameter_len/3;
      if(0xff==result)
      {
        for(i=0;i<set_parameter_len;i++)
        {    	
            for(n=0;n<3;n++)
            {				
                  if(!CheckBCD(*(Co.c.addr5+i*3+n)))
                        return -1;	
            }	
            if((*(Co.c.addr5+i*3+2)>0x23) || (*(Co.c.addr5+i*3+1)>0x59)|| (*(Co.c.addr5+i*3+0)>(MAXTRIFF-1))
            || (*(Co.c.addr5+i*3+0)==0))
                  return -1;
        }
        
        for(i=0;i<set_parameter_len*3;i++)
        {
      	   Co.b[300+i]=(*(Co.c.addr5+i));
        }
	      for(i=0;i<set_parameter_len-1;i++)
        {
            for(j=i+1;j<set_parameter_len;j++)
            {
                 ddt[0]=*(unsigned int*)&Co.b[301+i*3];
		             ddt[1]=*(unsigned int*)&Co.b[301+j*3];
                 if(ddt[0]>ddt[1])
                 {
                      for(uni=0;uni<3;uni++)
                      {
                          datat[uni]=Co.b[300+i*3+uni]; 
                          Co.b[300+i*3+uni]=Co.b[300+j*3+uni]; 
                          Co.b[300+j*3+uni]=datat[uni]; 
                      }
                  }
            }
        }
        for(i=0;i<set_parameter_len;i++)
        {
           time1=OB_H(Co.b[302+i*3])*((unsigned int)60)+OB_H(Co.b[301+i*3]);
           
			     if(i==set_parameter_len-1)
			   	 {
	            time2=OB_H(Co.b[302])*((unsigned int)60)+OB_H(Co.b[301]);
			   	 }
			     else
			   	 {
	            time2=OB_H(Co.b[302+(i+1)*3])*((unsigned int)60)+OB_H(Co.b[301+(i+1)*3]);
			   	 }
			   	 
			     if(time1<=time2)
			     {
			     	 interval=time2-time1;
			     }
			     else
			     {
			     	 interval=1440+time2-time1;
			     }
			     
           FeedWatchdog();
			     if(interval<15 && interval!=0)//15 minutes
			 	     return -1;
        }
        
      }
      
      if(set_parameter_len<14)
      {
      	slotnumber=14-set_parameter_len;
      	for(i=0;i<slotnumber;i++)
      	{
      		for(n=0;n<3;n++)
      		  WriteDateBuff[8+(set_parameter_len+i)*3+n]=*(Co.c.addr5+(set_parameter_len-1)*3+n);
      	}
      }
      
      Set_which_Responsion_Flag(3,0xff);      
      Comm_DailyProg_oper_code=pc->Programer_code;
      Comm_DailyOrYear_Slot=Read_Com_ID.d[0]+8*(Read_Com_ID.new_i[1]-0x0401);
      if(Read_Com_ID.new_i[1]==0x0401)
      { 
        eepromaddr=DAILYSLOT_ROM+MAXDAILYSLOT*3L*(Read_Com_ID.d[0]-1);
      }
      else
      {
        eepromaddr=DAILYSLOT2_ROM+MAXDAILYSLOT*3L*(Read_Com_ID.d[0]-1);
      }
      WRLC256(eepromaddr,&Comm_Firrespon_SecDispos_Buff[0],42,0,1);

      return 0;
}

/*"  	设置时区表 "*/
int Set_YearSlot(void)
{
      struct FindCommand_Result *pc;
      unsigned char i,n;
      unsigned char result=0;		
      unsigned char slotnumber;		
      unsigned int eepromaddr;
      unsigned char set_parameter_len;

      pc=(struct FindCommand_Result *)&cx[3];
      set_parameter_len=pc->len-12;
      
      if(set_parameter_len>42)
      {
      	Meter_States.ErrOfInformation.bit.OutYearZone=1;
      	return -1;
      }
      if((set_parameter_len==0)||((set_parameter_len%3)!=0))
      {
      	Meter_States.ErrOfInformation.bit.Invalid_Data=1;
      	return -1;
      }
      
      for(i=0;i<set_parameter_len;i++)
      {
        if(*(Co.c.addr5+i)!=0)
        {
            result=0xff;
            break;
         }
      }
      set_parameter_len=set_parameter_len/3;
      if(0xff==result)
      {
        for(i=0;i<set_parameter_len;i++)
        {   
            for(n=0;n<3;n++)
            {				
                  if(!CheckBCD(*(Co.c.addr5+i*3+n)))
                  return -1;	
            }	
            if((*(Co.c.addr5+i*3+2)>0x12) || (*(Co.c.addr5+i*3+1)>0x31) || (*(Co.c.addr5+i*3+0)>MAXDAILYSLOTTABLE)
            || (*(Co.c.addr5+i*3+0)==0))
            {
                  return -1;
            }
        }
      }
      
      if(set_parameter_len<14)
      {
      	slotnumber=14-set_parameter_len;
      	for(i=0;i<slotnumber;i++)
      	{
      		for(n=0;n<3;n++)
      		  WriteDateBuff[8+(set_parameter_len+i)*3+n]=*(Co.c.addr5+(set_parameter_len-1)*3+n);
      	}
      }
      
      Set_which_Responsion_Flag(4,0xff);
      Comm_YearProg_oper_code=pc->Programer_code;
      Comm_DailyOrYear_Slot=Read_Com_ID.d[2];
      if(Read_Com_ID.new_i[1]==0x0401)
      { 
        eepromaddr=YEARSLOT_ROM;
      }
      else
      {
        eepromaddr=YEARSLOT2_ROM;
      }
      WRLC256(eepromaddr,&Comm_Firrespon_SecDispos_Buff[0],42,0,1);

      return 0;
}

int Set_TriffSwitchDate(void)
{ 
      unsigned char n;

      if((*(Co.c.addr5+0)==0x99)&&(*(Co.c.addr5+1)==0x99)&&(*(Co.c.addr5+2)==0x99)&&(*(Co.c.addr5+3)==0x99)&&(*(Co.c.addr5+4)==0x99))
      {
      	  if(Read_Com_ID.l==0x04000106)/*"时区表固定为第一套"*/ 
      	  {
      	  	 if(Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow==1)
      	  	 {
      	  	 	 ClearEvent_EventBegin((unsigned char *)(&Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr),FREEZE_TRIFF_CHANGE_SORT_START_FILE);
			         FreezeDateProgram(FREEZE_TRIFF_CHANGE_SORT_START_FILE+Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr,1, (unsigned char *)&softdate);
		           Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr=(Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr+1)%MAX_NUMBER_FREEZE_TRIFF_CHANGE;
      	  	   Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow=0;
      	  	   WRLC256(TRIFFSWITCH_ROM,(unsigned char *)(&Meter_Parameter.parameter1.TriffSwitch),sizeof(struct SWITCH_ITEM),0,0);//write parameter	
	             Set_Meter_para_Deal(TRIFFSWITCH_ROM);
	             FeedWatchdog(); 
      	  	 }
      	  }
      	  if(Read_Com_ID.l==0x04000107)/*"时段表固定为第一套"*/  
      	  {
             if(Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow==1)
      	  	 {
      	  	 	 ClearEvent_EventBegin((unsigned char *)(&Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr),FREEZE_DAILYSLOT_CHANGE_START_FILE);
			         FreezeDateProgram(FREEZE_DAILYSLOT_CHANGE_START_FILE+Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr,1, (unsigned char *)&softdate);
		           Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr=(Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr+1)%MAX_NUMBER_FREEZE_DAILYSLOT_CHANGE;
      	  	   Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow=0;
      	  	   WRLC256(DAILYSLOTSWITCH_ROM,(unsigned char *)(&Meter_Parameter.parameter1.DailySlotSwitch),sizeof(struct SWITCH_ITEM),0,0);//write parameter	
	             Set_Meter_para_Deal(DAILYSLOTSWITCH_ROM);
	             FeedWatchdog();
      	  	 }
      	  }   
      	  return 0;
      }
      
      if((*(Co.c.addr5+0)==0)&&(*(Co.c.addr5+1)==0)&&(*(Co.c.addr5+2)==0)&&(*(Co.c.addr5+3)==0)&&(*(Co.c.addr5+4)==0))
            return 0;

      for(n=0;n<5;n++)
      {
            Co.c.h[4-n]=*(Co.c.addr5+n);
            if(!CheckBCD(*(Co.c.addr5+n)))
                  return -1;	
      }

      if(Co.c.h[0]<=0x99 && Co.c.h[1]<=0x12 && Co.c.h[1] && Co.c.h[2] 
      &&(OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))
      &&Co.c.h[3]<=0x23 && Co.c.h[4]<=0x59)
            return 0;
      else 
            return -1;
}


/*"  	设置周休日编程事件 "*/
int Set_ProgWeek(void)
{		
      unsigned char slotnumber=0; 
      struct FindCommand_Result *pc;
      //int result=0;

      pc=(struct FindCommand_Result *)&cx[3];   

      if((*(Co.c.addr5)>MAXDAILYSLOTTABLE)|| (*(Co.c.addr5)==0))
            return -1;		

      if(ProgWeekRecord(pc->Programer_code,Meter_Parameter.parameter1.SlotParemeter[0].WeekEndTable)==0)
            return -1;

      return 0;
}

/*"  	设节假日节假日日时段表号可以为0 "*/
int Set_Holiday(void)
{
      //int result=0;
      unsigned char n;

      for(n=0;n<4;n++)
      {
            Co.c.h[3-n]=*(Co.c.addr5+n);
            if(CheckBCD(*(Co.c.addr5+n))==0)
            {
                  if(((n==3)&&(*(Co.c.addr5+n)!=0xff))||(n!=3)	)				
                        return -1;	
            }
      }	

      if((Co.c.h[0]==0)&&(Co.c.h[1]==0)&&(Co.c.h[2]==0)&&(Co.c.h[3]==0))
      {
        if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x01) 
        {
        EventReportState_Expand(1, 0, 0);
        
        if(Event_Report_Status_Times.ProgHoliday_times!= 255)
        {
           Event_Report_Status_Times.ProgHoliday_times= 255;
           Save_EventReportTimes(PROGHOLIDAY_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgHoliday_times);
        }
        }
        return 0;
      }
      
      if((Co.c.h[1]>0x12)|| (Co.c.h[1]==0)
      || (OB_H(Co.c.h[2])>CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))|| (Co.c.h[2]==0)
      ||(Co.c.h[3]>MAXDAILYSLOTTABLE)||(Co.c.h[3]==0))
            return -1;
      if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x01) 
      {
      EventReportState_Expand(1, 0, 0);
        
        if(Event_Report_Status_Times.ProgHoliday_times!= 255)
        {
           Event_Report_Status_Times.ProgHoliday_times= 255;
           Save_EventReportTimes(PROGHOLIDAY_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgHoliday_times);
        }
      }
      return 0;
}


/*"  	设置负荷记录起始时间 "*/
int Set_LoadRecoedBeginTime(void)
{
      int result=-1;
      unsigned char n;
      struct DATA_TIME nDate;

      if((*(Co.c.addr5+0)==0)&&(*(Co.c.addr5+1)==0)&&(*(Co.c.addr5+2)==0)&&(*(Co.c.addr5+3)==0))
      {
            result=0;	
            for(n=0;n<4;n++)	
                  Co.c.h[n]=0;				
      }

      if(result==-1)
      {
            for(n=0;n<4;n++)
            {
                  Co.c.h[3-n]=*(Co.c.addr5+n);
                  if(!CheckBCD(*(Co.c.addr5+n)))
                        return -1;	
            }
            n=OB_H(softdate.Year);

            if(Co.c.h[0]<=0x12 && Co.c.h[0] && Co.c.h[1] &&OB_H(Co.c.h[1])<=CalDay(n,OB_H(Co.c.h[0])) &&Co.c.h[2]<=0x23 && Co.c.h[3]<=0x59)
                  result=0;
            else 
                  return -1;
      }
      /*nDate.Year=softdate.Year;
      nDate.Month=Co.c.h[0];
      nDate.Day=Co.c.h[1] ;
      nDate.Hour=Co.c.h[2];
      nDate.Min=Co.c.h[3];
      WRLC256(LOADRECORD_BEGIN_TIME_ROM,(unsigned char *)&nDate,5,3,0);*/
      Meter_Parameter.parameter2.LoadRecoedBeginTime.Year=softdate.Year;
      WRLC256(LOADRECOEDBEGINTIME_ROM,(unsigned char *)&Meter_Parameter.parameter2.LoadRecoedBeginTime,5,0,0);
      Set_Meter_para_Deal(LOADRECOEDBEGINTIME_ROM);
      First_InitLoadRecord();

      return result;
}

/*"  	设置负荷记录间隔时间 "*/
int Set_LoadRecoedPeriod(void)
{
      unsigned int result=0;
      struct FindCommand_Result *pc;
      unsigned char sort;
      
      pc=(struct FindCommand_Result *)&cx[3];

      result=*((unsigned int *)Co.c.addr5);

      if((result>0x99)||(result==0))
            return -1;    
      else 
      {
        /*
        sort = pc->idt.d[0] - 2;
        if (OB_H((unsigned char)result) != (unsigned char)Meter_Parameter.parameter2.LoadRecordPeriod[sort])
        {
            First_InitLoadRecord();
        }
        */
        return 0;  
      }

}
#pragma SECTION rom UserROMData
const unsigned char  Display_Number_ID1[]={0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,
										 0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,
										 0xC0};//lfy add  2011-3-11


const unsigned char   Display_Number_ID2[]={0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,
										 0x6E,0x6F,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,
										 0x78};
int  Read_Display_Number(void)  //lfy add  2011-3-11
{	
	unsigned char data=0;
	unsigned int uni=0;
	//unsigned char  result=0;
	
	WRLC256(KEYDISPLAYNUMBER_ROM,(unsigned char *)&data,1,0,1);		
		if(data>0x63)
		{
				for(uni=0;uni<((sizeof(Display_Number_ID2)));uni++)         
				{
				       if(Display_Number_ID2[uni]==data)
				 	{
						Readdata_buff[0]=Display_Number_ID1[uni];
						//result=0xFF;
						break;
				 	}			
				}
		}	 
		else 
		{
			HexToBcd(1,(unsigned char *)&data,(unsigned char *)&Readdata_buff);    
		}	
     return  0;
}

/*"  	设置循显和按显项目限制 "*/
int Set_Display_Number(void)
{
      unsigned int uni=0;
       unsigned char  datac=0;
	unsigned long Eeprom_addr,ul_temp;	 
	unsigned char *Ram_Data_Addr;	
     //int result=0;	
      struct FindCommand_Result *pc;//FXF ADD 081218	
      pc=(struct FindCommand_Result *)&cx[3]; 

      if((pc->idt.l==0x04000301))/*"设显示项目"*/
      {   
            if(((*Co.c.addr5)==0)||(*Co.c.addr5)>0x99)	
                  return -1;
      }
      else if(pc->idt.l==0x04000305)  /*"设按键显示屏数LFY ADDED 2011-3-11"*/  //mw modified 2010-11-01
      {
             if((*Co.c.addr5)==0)
                  return -1;  
		if(((*Co.c.addr5)&0x0F)>0x09)
		{
			return -1;  
		}
		if((*Co.c.addr5)>0x99)
		{
			if((((*Co.c.addr5)&0xF0)==0xA0)||(((*Co.c.addr5)&0xF0)==0xB0)||((*Co.c.addr5)==0xC0))
			{

				for(uni=0;uni<((sizeof(Display_Number_ID1)));uni++)         
				{
				       if(Display_Number_ID1[uni]==(*Co.c.addr5))
				 	{
						(*Co.c.addr5)=Display_Number_ID2[uni];
						break;
				 	}			
				}
			}
			else 
				return -1;  
		}	 
		else 
		{
			//BcdToHex(1, unsigned char *, unsigned char *)
			BcdToHex(1,Co.c.addr5,(unsigned char *)&datac);    
			(*Co.c.addr5)=datac;
		}
			//Eeprom_addr=KEYDISPLAYNUMBER_ROM;
			WRLC256(KEYDISPLAYNUMBER_ROM,Co.c.addr5,1,0,0);			
			/*if((Eeprom_addr>=METER_PARAMETER_ROM)&&(Eeprom_addr<JUSTMETER_PARA_ROM))
			{
					Ram_Data_Addr=(unsigned char *)&Meter_Parameter;
					ul_temp=METER_PARAMETER_ROM;
					Ram_Data_Addr+=Eeprom_addr-ul_temp;
					WRLC256(Eeprom_addr,Ram_Data_Addr,1,0,1);	
					Set_Meter_para_Deal(Eeprom_addr);	
			}	*/
			Meter_Parameter.parameter1.KeyDisplayNumber=(*Co.c.addr5);
			Set_Meter_para_Deal(KEYDISPLAYNUMBER_ROM);
      }
      else
            return -1;

      return 0;
}

/*"  	设置循显和按显项目限制 "*/
int Set_CycleDisplayTime(void)
{
      //	int result=0;		

      if((*Co.c.addr5)<0x05||(*Co.c.addr5)>0x20)	
            return -1;  

      return 0;
}
/*"设置循显和按显 "*/
int Set_Cycle_Key_Display(void)
{
      struct FindCommand_Result *pc;
      pc=(struct FindCommand_Result *)&cx[3]; 

      if((pc->id.l&0x04040100)==0x04040100)
            Check_Show_Flash_Data(0x01,(pc->id.d[0]-1),0xff,Co.c.addr5);
      else if((pc->id.l&0x04040200)==0x04040200)
            Check_Show_Flash_Data(0x02,(pc->id.d[0]-1),0xff,Co.c.addr5);
      else 
            return -1;
      
      return 0;
}

/*"  	设置通信速率 "*/
int Set_Commrate(void)
{ 
      struct FindCommand_Result *pc;//FXF ADD 081218	
      pc=(struct FindCommand_Result *)&cx[3]; 
      if((pc->id.l==0x04000701) || (pc->id.l==0x04000705))/*"    远红外、模块通信口不能设置   "*/
      {
            Meter_States.ErrOfInformation.bit.Invalid_COMMRATE=1;	
            return -1;
      }
      if((*Co.c.addr5==0x04)||(*Co.c.addr5==0x08)||(*Co.c.addr5==0x10)||(*Co.c.addr5==0x20))	
      {		
            if(pc->id.l==0x04000703)	
                  ChangeBand=0x01;
            else if(pc->id.l==0x04000702)	
                  ChangeBand=0x02;
            else if(pc->id.l==0x04000704)	
                  ChangeBand=0x03;
            else 
                  return -1;					
            return 0;
      }
      else 
      {
            Meter_States.ErrOfInformation.bit.Invalid_COMMRATE=1;	
            return -1;
      }
}

/*"  	设置模式字1-5 "*/
int Set_MeterMode(void)
{
      int result=0;
      struct FindCommand_Result *pc;

      pc=(struct FindCommand_Result *)&cx[3];

      if((pc->idt.d[0])==0x01)
      {
            if(!O1ther_Meter_Parameter.WorkRoomState)
                  return -1;
      }
      if((pc->idt.d[0])==0x02)
      {
           if(!O1ther_Meter_Parameter.WorkRoomState)
           {
                  if(((*Co.c.addr5)&0xf9)!=(Meter_Parameter.parameter1.MeterMode[1].byte&0xf9))
                       return -1;

                  if(Far_Spec_Order_Flag!=0xFF)
                       return -1;
            }         
      }
      if((pc->idt.d[0])==0x03)
      {
            if(!O1ther_Meter_Parameter.WorkRoomState)
            {
                  if(((*Co.c.addr5)&0x33)!=(Meter_Parameter.parameter1.MeterMode[2].byte&0x33))
                       return -1;

                  if(Far_Spec_Order_Flag!=0xFF)
                       return -1;
            }
      }	      	       
      Output_On_3_In_1_Terminal_Set(7);	
      return result;
}

/*"  	设置密码 错误闭锁次数 "*/
int Set_Meterlocktimes(void)
{
	//int result=0;

	if((*(Co.c.addr5)<0x01) || (*(Co.c.addr5)>0x99))
	       return -1;
	return 0;
}

/*"  	设置三合一输出状态 "*/
/*int Set_OutputModel(void)
{
	//int result=0;
	
      if(*Co.c.addr5==2)
      {
            DemandputoutNum=0;
            DemandOutPutflagdata=0;
            DemandOutPutflag=0;
      }
      Meter_Parameter.OutputModel=*Co.c.addr5;
      Output_On_3_In_1_Terminal_Set(0);
      return 0;
}*/

/*"  	设临界电压不能低于60% "*/
int Set_CriticalVoltage(void)
{
	//int result=0;
	
      if(*Co.c.addr5>0x60)
            return -1;

      return 0;
}

/*"  	设置通信地址"*/
int Set_CommAddr(void)
{
	 unsigned char n,*p;
	 int result=0;
	 struct FindCommand_Result *pc;
		
	 pc=(struct FindCommand_Result *)&cx[3];
	 p=Co.c.addr5;
	 
      for(n=0;n<6;n++)
      {		
            Co.c.f[n]=*(p+n);	
            if(!CheckBCD(Co.c.f[n]))/*"         写地址必须是BCD 090102  by fxf               "*/
                  return -1;	
            //if(((Co.c.f[n]&0xF0)==0xA0) ||((Co.c.f[n]&0x0F)==0x0A))	
            //		return -1;
      }

	for(n=0;n<6;n++)
	{
   		 Meter_Parameter.parameter1.BcdCommAddr[0][n]=Meter_Parameter.parameter1.BcdCommAddr[1][n]=Co.c.f[n];
   		 Meter_Parameter.parameter1.BcdCommAddr[2][n]=Co.c.f[n];
     }
	//liuyq modify  2009-8-24 start
	WRLC256(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[0],18,0,0);
	Set_Meter_para_Deal(BCDCOMMADDR1_ROM);
//	WRLC256(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.BcdCommAddr[0],18,1,0);
	FeedWatchdog();
//	Write_FM24C256_MULTI(BCDCOMMADDR1_ROM,(unsigned char *)&Meter_Parameter.parameter1.BcdCommAddr[0],18,FM24C256_1AND2);
	//liuyq modify 2009-8-24 end
	
   return result;
}

/*"  	设置显示用户代码"*/
int Set_Show_USER_Code(void)
{		
      unsigned char i;
      if ((*(Co.c.addr5+4)>0x8))
            return -1;
      else
            return 0;
}


/*"  	设置初始电量,输入值固定为2位小数，保存为3位小数 "*/
int  Set_primary_energy()
{  
	unsigned char n,i,j;
	int result=0;
	unsigned long datac;
	unsigned char *p_t;
	struct FindCommand_Result *pc;
	unsigned int length = 0;
	p_t=Co.c.addr5;
	pc=(struct FindCommand_Result *)&cx[3];

     n=pc->id.d[1]-3;	         
    
	if(!O1ther_Meter_Parameter.WorkRoomState)
		return -1;
	            
	for(i=0;i<MAXTRIFF;i++)
	{
		BcdToHex(4,p_t+i*4,&Co.b[400+i*4]);
				
		/*" 	6类基本电量的最大值为99999999  "*/
		if(*((unsigned long *)&Co.b[400]+i)>99999999l)
			return -1;			
	   
	   //  if(Meter_Parameter.EnergyPoint!=3)
	    {
	       *((unsigned long *)&Co.b[400]+i)=*((unsigned long *)&Co.b[400]+i)*10l;
	    }               
	}  
	       
	//if(!checkEnergyRight(&Co.b[400],1,0,0,0))  
	if(!TotalEnergyRight((struct ENERGY_RECORD *)&Co.b[400],0)//active
	     ||!TotalEnergyRight((struct ENERGY_RECORD *)&Co.b[400],1)  )//rective 
		return -1;
     	             
	//liuyq modify 2009-8-24 start
	WRLC256(PRIMARYDATA_ROM+n*4*MAXTRIFF,&Co.b[400],4*MAXTRIFF,0,0);
	FeedWatchdog(); 
	//WRLC256(PRIMARYDATA_ROM+n*4*MAXTRIFF,&Co.b[400],4*MAXTRIFF,1,0);  
	//FeedWatchdog(); 
	//Write_FM24C256_MULTI(PRIMARYDATA_ROM+n*4*MAXTRIFF,&Co.b[400],4*MAXTRIFF,FM24C256_1AND2);
	//liuyq modify 2009-8-24 end
     for(i=0;i<4*MAXTRIFF;i++)
	     {
	      	 Co.b[305+i]=Co.b[400+i]; 
	      	 Co.b[305+4*MAXTRIFF+i]=*((unsigned char *)&This_Month_Data+n*4*MAXTRIFF+i);
	     }
	      	   
	    Co.b[305+8*MAXTRIFF]=n; 
	    //Event_Meter_Program_Flag.SetPrimary=1;
	    //Event1(0);  //change by pc 081214
	    SetPrimaryRecord();  //add by pc 081218
	    //EventRecordAdjustEnergy();  //add by pc 081218  
	    FeedWatchdog();  
	    for(i=0;i<MAXTRIFF;i++)
	    {
	       BcdToHex(4,p_t+i*4,&Co.b[300+i*4]);
	      // if(Meter_Parameter.EnergyPoint!=3)
	       {
	          *((unsigned long *)&Co.b[300]+i)=*((unsigned long *)&Co.b[300]+i)*10l;
	       }
	    }    
	      	    
	    for(i=0;i<MAXTRIFF*4;i++)
	    {
	      	*((unsigned char *)&This_Month_Data+n*4*MAXTRIFF+i)=Co.b[300+i];
	    } 	      	       
	      	    
	   if(V_REGION==1 || V_REGION==2)
	      	j=3;
	   else 
	   			j=2;
	   datac=(*((unsigned long*)&This_Month_Data+n*MAXTRIFF))/j;
	   if(n==1 || n==0)
	   {
	      	for(i=0;i<3;i++)
	      	 		*((unsigned long*)&This_Month_Data.Energy_Record.Phase_Plus_Active+n*3+i)=datac; 
	      	if(j==2)   
	      	 		*((unsigned long*)&This_Month_Data.Energy_Record.Phase_Plus_Active+n*3+1)=0; 
	   }
	   else
	   {
      	  for(i=0;i<3;i++)
	      	 		*((unsigned long*)&This_Month_Data.Energy_Record.Phase_Plus_Active+6+n-2+i*4)=datac; 
	      	if(j==2)   
	      	 		*((unsigned long*)&This_Month_Data.Energy_Record.Phase_Plus_Active+6+n-2+4)=0;  
	   }
	      	    
	   for(i=0;i<4;i++)
     {
	         *((unsigned long *)&energy_rail.Rail_Plus_Active[0]+4*n+i)=0;
     }
     
     if(n<2)
     {
     	 for(i=0;i<MAXTRIFF;i++)
       {
	         *(&energy_rail.Total_Plus_Active_100mwh[0]+MAXTRIFF*n+i)=0;
       }
     }
     energy_rail.crc_cal = CRC((unsigned char*)&energy_rail,
	                             sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2);
     WRLC256(ENERGY_RAIL_DATA_ROM,(unsigned char *)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER),0,0);
               
//	   Minute_Copy_Energy.Energy_Record=This_Month_Data.Energy_Record; 	      	    
	//---------------------------------------------------------------------------
      Check_Energy_main(2);
//----------------------------------------------------------------------------      	    
//	WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
//	FeedWatchdog(); 
	//WRLC256(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),1,0);
	//FeedWatchdog(); 
	//Write_FM24C256_MULTI(THIS_MONTH_DATA_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),FM24C256_1AND2);
	//liuyq modify 2009-8-24 end
//     WRLC256(F_ENERGY_RECORD,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
//     FeedWatchdog(); 
     //WRLC256(MINUTE_COPY_ENERGY_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),0,0);
	//	 FeedWatchdog(); //liuyq delete 2009-8-24 
     //WRLC256(MINUTE_COPY_ENERGY_ROM,(unsigned char *)&This_Month_Data,sizeof(struct ENERGY_RECORD),1,0); 
     FeedWatchdog();               
                
     Write_TO_Cal_PowerDown_Energy_add();
     /*"  初始化需量 "*/
	 ClearDemandArea(0);
	// Demand_New_Init();
              
	   return  0;
}

/*"  	设置周期冻结起始时间 "*/
int Set_Freeze_Period_Begin_time(void)
{
	unsigned int n,result=0;	

    if((*(Co.c.addr5+0)==0)&&(*(Co.c.addr5+1)==0)&&(*(Co.c.addr5+2)==0)&&(*(Co.c.addr5+3)==0)&&(*(Co.c.addr5+4)==0))
            return 0;

     for(n=0;n<5;n++)
	{
		Co.c.h[4-n]=*(Co.c.addr5+n);
		if(!CheckBCD(*(Co.c.addr5+n)))
		return -1;	
	}

	if(Co.c.h[0]<=0x99 && Co.c.h[1]<=0x12 && Co.c.h[1] && Co.c.h[2] 
	 					&&(OB_H(Co.c.h[2])<=CalDay(OB_H(Co.c.h[0]),OB_H(Co.c.h[1])))
	    				&&Co.c.h[3]<=0x23 && Co.c.h[4]<=0x59)
			result=0;
	 else 
	 		return -1;
	 
	 /*"清除周期冻结数据 "*/
	/*Meter_Parameter.FreezeData_Period_addr=0; 		    
	WRLC256(FREEZE_PERIOD_ADDR_ROM,(unsigned char *)&Meter_Parameter.FreezeData_Period_addr,1,0,0);
	WRLC256(FREEZE_PERIOD_ADDR_ROM,(unsigned char *)&Meter_Parameter.FreezeData_Period_addr,1,1,0);
	FeedWatchdog(); 	
    for(n=0;n<508;n++)
				Co.b[400+n]=0xFF;
	for(n=0;n<6;n++)
	{
		       WRLC256(FREEZEDATA_PERIOD_ROM+n*508,(unsigned char *)&Co.b[400],508,2,0);		
		       FeedWatchdog(); 	
               CheckPowerDown();
	}
	WRLC256(FREEZEDATA_PERIOD_ROM+6*508,(unsigned char *)&Co.b[400],254,2,0);*/		

	 return result;  
}

/*"  	设置周期冻结间隔时间 "*/
int Set_Freeze_Period(void)
{
    if(((*Co.c.addr5)<0x01)||((*Co.c.addr5)>0x60)) 
		  return -1;
    
     return 0;
}

/*"  退出工厂状态 "*/
int  Exit_WorkRoomState()
{
		  unsigned char i;		 
      
	if(O1ther_Meter_Parameter.WorkRoomState && J1)
	{
		O1ther_Meter_Parameter.WorkRoomState=0;
		O1ther_Meter_Parameter.WorkRoom_RunTime=0;///king chen add 121214
		///for(i=0;i<6;i++)
		///	*((unsigned char *)&O1ther_Meter_Parameter.WorkRoomStateDate+i)=0;
		WRLC256(WORKROOMSTATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoomState,1,0,0); ///king chen modify 121214
		WRLC256(WORKROOM_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.WorkRoom_RunTime,4,0,0);///king chen add 121214
		return   0;
	}
	else
		return -1;
}
/*"  	无按键 返回循显时间 "*/
int Set_ShowNoKeyRetTime(void)
{
	if(*((unsigned int *)Co.c.addr5)<Meter_Parameter.parameter1.CycleDisplayTime)
	       return -1;
	else 
			return 0;
}
/*"尖峰平谷表示的费率"*/
int Set_JFPG_Triff(void)
{
    unsigned char n;
    for(n=0;n<8;n++)
    {
	    if(*(Co.c.addr5+n)>4)
	       return -1;	    
    }
    
    return 0;
}
/*"  	通信初始化FLASH 命令,执行该命令后初始化事件记录,冻结和负荷曲线 "*/
int Comm_Initialize_FLASH(void)
{		
      unsigned int i,length,result=0;
      unsigned int WInfoList[][4] = {/*"0->卡地址；1->数据长度;2->设备;3->即时数据保存地址"*/
            EVENT_POWER_NET_POINTER_ROM,sizeof(struct EVENT_POWER_NET_POINTER),0,(unsigned int)&Event_Power_Net_Pointer,
            EVENT_METER_PRO_POINTER_ROM,sizeof(struct EVENT_METER_PRO_POINTER),0,(unsigned int)&Event_Meter_Pro_Pointer,
            EVENT_POWER_NET_TIMES_ROM,sizeof(struct EVENT_POWER_NET_TIMES),0,(unsigned int)&Event_Power_Net_Times,
            EVENT_METER_PRO_TIMES_ROM,sizeof(struct EVENT_METER_PRO_TIMES),0,(unsigned int)&Event_Meter_Pro_Times,
            EVENT_POWER_NET_TIMETICKS_ROM,sizeof(struct EVENT_POWER_NET_TIMETICKS),0,(unsigned int)&Event_Power_Net_Timeticks
      };
      
      if(!O1ther_Meter_Parameter.WorkRoomState)
            return -1;
      //show_build_char();
      if (Fs_Init()==0)
      {
            ///LED_ALARM=1; ///king chen mark 121214

            /*" 清事件 "*/
            for(i=0;i<12;i++)  //mw modified 2009-09-03
                  PdEventData.eventflag[i].byte=0;
            
            eventstatusinfo.byte=0;

            VoltStatSetDefault();
            EepromEventSetDefault();
            //mw modified 2009-10-09
            length=sizeof(union EVENT_POWER_NET_FLAG);
            for(i=0;i<length;i++)
                  *( (unsigned char *)&Event_Power_Net_Flag+i)=0;

            for(i=0;i<5;i++)
            {
                  if(WInfoList[i][3])
                  {
                        for(length=0; length <WInfoList[i][1];length++)
                              *((unsigned char*)(WInfoList[i][3]+length)) = 0;
                  }
                  WRLC256(WInfoList[i][0],0,WInfoList[i][1],WInfoList[i][2],0);  				 
                  FeedWatchdog();			
            }

            /*" 清冻结 "*/
            Clear_Freeze();
		Pay_Event_Record_Clear();	//payment
            FeedWatchdog(); 	
            /*" 清负荷曲线 "*/
            First_InitLoadRecord();
            FeedWatchdog();	

           Other_Data.BatteryWorkTime1=0;
	         Other_Data.BatteryWorkTime2=0; 
	         WRLC256(BATTERYWORKTIME1_ROM,(unsigned char *)&Other_Data.BatteryWorkTime1,8,0,0);
	         FeedWatchdog();	
      }
      else
            result=-1;

      return 	  result;
}
/*" 检查设置参数的长度是否正确 "*/
int  Check_Parameter_Len_IS_ok(unsigned char trans_format)
{	
      unsigned char set_parameter_len;
      struct FindCommand_Result *pc;//FXF ADD 081218

      //int result = 0;

      pc=(struct FindCommand_Result *)&cx[3];	
      set_parameter_len=pc->len-12;

      if (pc->id.l==0x0E00020A)
      {
            if(set_parameter_len!=(MAXTRIFF - 1))
                  return -1;
            else
                  return 0;
      }
	else if ((pc->id.l==0x040501FF)||(pc->id.l==0x040502FF))		//newpay
	{
		if (set_parameter_len>(PRE_MAX_TRIFF)*4 )
			//||set_parameter_len<(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble*4
			return -1;
		else
			return 0;
	}
	else if ((pc->id.l==0x040604FF)||(pc->id.l==0x040605FF))
	{
		if (set_parameter_len!=64)
			return -1;
		else
			return 0;
	}
	  

      /*" 检查设置初始电量是否正确 "*/ 
      if((pc->id.l==0x0E0003FF)||(pc->id.l==0x0E0004FF)||(pc->id.l==0x0E0005FF)
      ||(pc->id.l==0x0E0006FF)||(pc->id.l==0x0E0007FF)||(pc->id.l==0x0E0008FF))
      {
            if(set_parameter_len!=4*MAXTRIFF)
                  return -1;
            else
                  return 0;
      }
      
      if(pc->id.l==0x0400040F)
      {
            if(set_parameter_len!=11)
              return -1;
            else
              return 0;
      }
      if(pc->id.l==0x0400010C)
      {
            if(set_parameter_len!=7)
              return -1;
            else
              return 0;
      }
      
      if((trans_format&0xf0)==0x30)//bit format
      {
            if(set_parameter_len!=1)
           return -1;
      }
      else if((trans_format==_NN_H)||(trans_format==_NN_L)||(trans_format==ID_CODE_TWO_FORMAT)||(trans_format==ID_CODE_FOUR_FORMAT))
      {
         if(pc->id.l==0x04800004) ///|| (pc->id.l==0x04001104))
         {
            if(set_parameter_len!=8)
              return -1;
         }
         else if(pc->id.l !=0x04001104)
         {   
            if(set_parameter_len!=6)
                  return-1;
         }

      }
      else if((trans_format==_NN_MMDD)||(trans_format==_NN_HHMM))
      {
            return 0;
      }
      else if(trans_format==ASCII_SIX_LENGTH)
      {
        if((pc->id.l ==0x04001503)&&(set_parameter_len!=12))
                  return-1;
      }
      else
      {
            if(set_parameter_len!=sizeof_format(trans_format))
                  return -1;
      }
      return 0;

}
/*"============================================================"*/
/*"函数名：Crc16l"*/
/*"简单CRC-CCITT算法"*/
/*"参数：ptr:需要校验的参数； len:需要校验的参数长度"*/
/*"返回：校验和"*/
/*"作者：fuxf 版本：1.00"*/
/*"============================================================"*/
unsigned int Crc16l(unsigned char *ptr,unsigned char len)
{ 

    return CRC(ptr,len);
    /*unsigned char i; 
    unsigned int crc=0;

    if(len==0)
        return 0;

    while(len--) 
    { 
        for(i=0x80; i!=0; i>>=1) 
        { 
            if((crc&0x8000)!=0) 
            {
                crc<<=1; 
                crc^=0x1021;
            }          
            else 
                crc<<=1;                     
            if((*ptr&i)!=0) 
                crc^=0x1021;                      
        } 
        ptr++; 
    } 
  
  return(crc); */
}
/*"============================================================
函数说明：计算分类参数的CRC校验值并存内卡（根据内卡地址确定是哪类参数）
          重要参数（参数1） ACTIVEPULSECONST_ROM～PARAMETER1_CRC_ROM
          一般参数（参数2） ASCII_METERMANAGE_CODE～PARAMETER2_CRC_ROM
          事件参数          VOLTAGEHEALTH_UPSET_ROM～EVENT_PARAMETER_CRC_ROM
          结算参数          OLDSEGPARAMETER_ROM～BILL_STATE_CRC_ROM
          冻结参数          FREEZEDATE_ROM～FREEZE_PARAMETER_CRC_ROM
输入参数：rom_addr 内卡地址
输出参数：无
返    回：无  
作    者：GANJP  版本：1.00
============================================================"*/
void Set_Meter_para_Deal(unsigned int rom_addr)
{	
	
	if((rom_addr >= ACTIVEPULSECONST_ROM) && (rom_addr < ASCII_METERMANAGE_CODE))
		{
			Meter_Parameter.parameter1.crc_cal = CRC((unsigned char*)&Meter_Parameter.parameter1,
			                                          sizeof(struct PARAMETER1) - 2);
			WRLC256(PARAMETER1_CRC_ROM,(unsigned char *)&Meter_Parameter.parameter1.crc_cal,2,0,0);
		}
		
	else if((rom_addr >= ASCII_METERMANAGE_CODE) && (rom_addr < VOLTAGEHEALTH_UPSET_ROM))
		{
			Meter_Parameter.parameter2.crc_cal = CRC((unsigned char*)&Meter_Parameter.parameter2,
			                                          sizeof(struct PARAMETER2) - 2);
			WRLC256(PARAMETER2_CRC_ROM,(unsigned char *)&Meter_Parameter.parameter2.crc_cal,2,0,0);
		}
		
	else if((rom_addr >= VOLTAGEHEALTH_UPSET_ROM) && (rom_addr < FREEZEDATE_ROM))
		{
			Meter_Parameter.event_parameter.crc_cal = CRC((unsigned char*)&Meter_Parameter.event_parameter,
			                                               sizeof(struct EVENT_PARAMETER) - 2);
			WRLC256(EVENT_PARAMETER_CRC_ROM,(unsigned char *)&Meter_Parameter.event_parameter.crc_cal,2,0,0);
		}
		
	///else if((rom_addr >= OLDSEGPARAMETER_ROM) && (rom_addr < FREEZEDATE_ROM))
		///{
		///	Meter_Parameter.bill_state.crc_cal = CRC((unsigned char*)&Meter_Parameter.bill_state,
		///	                                          sizeof(struct BILL_STATE) - 2);
		///	WRLC256(BILL_STATE_CRC_ROM,(unsigned char *)&Meter_Parameter.bill_state.crc_cal,2,0,0);
		///}
	
	else if((rom_addr >= FREEZEDATE_ROM) && (rom_addr < END_ROM1))
		{
			Meter_Parameter.freeze_parameter.crc_cal = CRC((unsigned char*)&Meter_Parameter.freeze_parameter,
			                                                sizeof(struct FREEZE_PARAMETER) - 2);
			WRLC256(FREEZE_PARAMETER_CRC_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.crc_cal,2,0,0);
		}
}

void PowerOn_FullScreen_TimeDetection(void)
{
 if(0==Displayfinish_flag)
       {
       Displayfinish_flag=1;
       Full_show_time_Limit=0;
	  
	  SWITCH_CLEW=0;
	  BackLight_Ctrl(CLOSE_MODE,0,0,FULLSCREEN_EVENT);
         cyc_show_time=GetNowTime();
       }
}

int ReadClockBatteryVoltage(void)///king chen add 121226
{
#ifdef BatteryVoltage_SampleMode_AD
 unsigned int i;
 unsigned char Ad_abnormal;
  if(0==IntoPowerDownFlag)  /*"正常上电执行，低功耗不执行"*/
  { 
  ad_finish_Flag=0;
  Ad_abnormal=0;
   ad_Flag=0;
    pd2_7= 0x00;                     /// input mode 
    
    adcon2  = 0x06;                    
	
    adcon0  = 0x07;                   	

    adcon1  = 0x30;                     

    for(i = 0; i< 30; i++);             

    adic    = 0x01;/*"修改优先级"*/                         
	
    adst    = 1;                      /// A/D conversion start 
 
    for(i=0;i<990;i++)
   	{
   	if(1==ad_finish_Flag)
   		{
   		Ad_abnormal=0;
		break;
   		}
	else if((0==ad_finish_Flag)&&(985==i))
		{
   		Ad_abnormal=1;
		break;
   		}
   	}
     Voltage_ad_data[0]=fix_ad_data*(unsigned long)Meter_Parameter.event_parameter.AD_Sample_Vref*30UL/(1023UL*20UL);///king chen add 130730
      if(Voltage_ad_data[0] < 245) 
        Voltage_ad_data[0]=0;
      if(Voltage_ad_data[0] >= 385) 
        Voltage_ad_data[0]=385; 
     if(!Ad_abnormal)
	return 0;
    else
	return -1;
  }
  else
  {
    return -1;
  }
  
#else

if(0==IntoPowerDownFlag)  /*"正常上电执行，低功耗不执行"*/
  { 
  if(VB1_OK==0)
  	Voltage_ad_data[0]=0;
  else
  	Voltage_ad_data[0]=360;
  }
else
	Voltage_ad_data[0]=360;

#endif
}

int ReadDisplayBatteryVoltage(void)///king chen add 121226
{
#ifdef BatteryVoltage_SampleMode_AD
   unsigned int i;
   unsigned char Ad_abnormal;
  if(0==IntoPowerDownFlag)  /*"正常上电执行，低功耗不执行"*/
  { 
  ad_finish_Flag=0;
   ad_Flag=1;
  Ad_abnormal=0; 
    pd2_6= 0x00;                     /// input mode 
    
    adcon2  = 0x06;                    
	
    adcon0  = 0x06;                   	

    adcon1  = 0x30;                     

    for(i = 0; i< 30; i++);             

    adic    = 0x01; /*"修改优先级"*/                  
	
    adst    = 1;                      /// A/D conversion start 
    
   for(i=0;i<990;i++)
   	{
   	if(1==ad_finish_Flag)
   		{
   		Ad_abnormal=0;
		break;
   		}
	else if((0==ad_finish_Flag)&&(985==i))
		{
   		Ad_abnormal=1;
		break;
   		}
   	}
    Voltage_ad_data[1]=fix_ad_data*(unsigned long)Meter_Parameter.event_parameter.AD_Sample_Vref*310UL/(1023UL*110UL);
    if(Voltage_ad_data[1] <200)
        Voltage_ad_data[1] = 0;
    if(Voltage_ad_data[1] >=660)
        Voltage_ad_data[1] = 660;
     if(!Ad_abnormal)
	return 0;
    else
	return -1;
  }
  else
  {
    return -1;
  }
  
 #else
 
if(0==IntoPowerDownFlag)  /*"正常上电执行，低功耗不执行"*/
  { 
   if(VB3_OK1==0)
  	Voltage_ad_data[1]=0;
  else
  	Voltage_ad_data[1]=600;
  }
else
      Voltage_ad_data[1]=600;

#endif
}

int ReadEventReportInfo(void)
{
union EVENT_REPORT_STATUS EventReportStatus_temp;
unsigned char unc;

Get_Event_Report_Status((union EVENT_REPORT_STATUS *)&EventReportStatus_temp);
for(unc = 0; unc < 12; unc++)
{
Readdata_buff[unc] = EventReportStatus_temp.byte[unc];
}
	return 0;
}

int GetEventReportMode(void)
{
	unsigned char unc;
	
	for(unc=0;unc<8;unc++)
	{
		Readdata_buff[unc]=Meter_Parameter.parameter1.EventReportMode.byte[unc];
	}
	
	return 0;
}

int SetEventReportMode(void)
{
	unsigned char unc;
	
	for(unc=0;unc<8;unc++)
	{
		Readdata_buff[unc]=*(Co.c.addr5+unc);
		Meter_Parameter.parameter1.EventReportMode.byte[unc]=Readdata_buff[unc];
	}
	
	WRLC256(EVENT_REPORT_MODE_ROM,&Meter_Parameter.parameter1.EventReportMode.byte[0],8,0,0);
	Set_Meter_para_Deal(EVENT_REPORT_MODE_ROM);
	
	return 0;
}

void HZ_LCDQueryCmd(unsigned char uartx)///king chen add 130204
{  
	unsigned char *p;
	struct FindCommand_Result *pc;
	unsigned int uni;
	unsigned char ok;    
	struct SHOW_CODE_TABLE1 show_code_temp;
	unsigned char ret,leaf_flag_copy;
	ok=0xff;
    
	AppointTrasfPortBuff(uartx);
	p = CommBP;
	pc = CurrPC;
    
	/*"清缓冲"*/
	for(uni=0;uni<500;uni++)
		Co.b[uni]=0;	
    
	//pc->ct=0;
	pc->idt.l=pc->id.l; 
    
	if((pc->id.l !=0x04040300) || (pc->len !=0x09))
	{
	    ok=0;
	    Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;///king chen add 130418
		//return;
	}
	if(farinfrareddisableflag==1)
  {
    	ok=0;
      Meter_States.ErrOfInformation.bit.Invalid_Password=1;
  }
	
        if(ok)
        {
	//liuyq modify 2009-8-21 end
	for(uni=0;uni<10;uni++)
	   WriteDateBuff[uni]=0; 

		for(uni=0;uni<cx[3].len-4;uni++)
		{    
			*((unsigned char *)&WriteDateBuff[0]+uni)=*(p+cx[3].addr)-0x33;
			///WriteDateBuff[uni]=*(p+cx[3].addr)-0x33;
		        (cx[3].addr)++;
		        if((cx[3].addr)>=B_FL) (cx[3].addr)=0;
		}

    

	show_code_temp.default_code=*((unsigned long *)&WriteDateBuff[0]);
	show_code_temp.flag=WriteDateBuff[4];
	if(show_code_temp.default_code==0xFFFFFFFF && show_code_temp.flag==0xFF)
	{
		show_code_temp.default_code=0x88888888;
		show_code_temp.flag=0x00;		
		//User_Choose_Table.default_code=0x88888888;
		//User_Choose_Table.flag=0x00;
	}
	//else
	//	show_code_temp=show_code_temp;
		//User_Choose_Table=show_code_temp;
	//================================
	leaf_flag_copy=leaf_flag;
	leaf_flag=show_code_temp.flag;
	ret=Show_Main(show_code_temp.default_code,&Co.b[600],0,0);
	leaf_flag=leaf_flag_copy;
	
	 if(2== ret)
	 {
          ok=0;
          Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
	   //return ;
        }

	//================================	
	if(pc->BroadCasrAddress==0)
	{
	    if(ok)
	        {
                	pc->ct=0x91;
                Co.c.len=0x05;
                pc->lena=0x05;
                pc->lent=0;
                pc->havebackframe=0;
			for(uni=0;uni<5;uni++)
			{
				*(p+14+uni)=WriteDateBuff[uni];
			}                
                	User_Choose_Table=show_code_temp;	
                	LCD_Check_Second=10;  //mw modified 2012.06.05
                	LCD_Check_State=0;
                    
                    light_AlarmSwitchLED=0;
                 
	        }
            else 
            {
                pc->ct=0xD1;
                Co.c.len=1;
                pc->lena=1;
                pc->lent=0;
                p[10]=Meter_States.ErrOfInformation.byte;                   
            }
         }
	else///king chen debug
	{
	      pc->ct=0;
	      Co.c.len=0;
	      pc->lena=0;
	      User_Choose_Table=show_code_temp;	
	      LCD_Check_Second=10;  
	      LCD_Check_State=0;
                    
	      light_AlarmSwitchLED=0;
	}
      }
        else 
        {
          if(pc->BroadCasrAddress==0)///king chen debug
	    {
		pc->ct=0xD1;
                Co.c.len=1;
                pc->lena=1;
                pc->lent=0;
                p[10]=Meter_States.ErrOfInformation.byte; 
          	}
	     else
	     	{
	     	  pc->ct=0;
	        Co.c.len=0;
	        pc->lena=0;
	     	}
		  	
        }

                    	if(uartx < 3)
		        cx[uartx] = cx[3];	
        
	
}

int SetPowerOnFullScreenTime(void)
{
    if(((*Co.c.addr5)<0x05)||((*Co.c.addr5)>0x30)) 
		  return -1;
    
    return 0;
}


int GetMeterSoftIdNumber(void)
{
	unsigned char unc;
	
	for(unc=0;unc<8;unc++)
	{
		Readdata_buff[unc]=Meter_Parameter.parameter2.MeterSoftIdNumber[unc];
	}
	
	return 0;
}

int SetMeterSoftIdNumber(void)
{
	unsigned char unc;
	
	for(unc=0;unc<8;unc++)
	{
		Readdata_buff[unc]=*(Co.c.addr5+unc);
		Meter_Parameter.parameter2.MeterSoftIdNumber[unc]=Readdata_buff[unc];
	}
	
	WRLC256(METERSOFTIDNUMBER_ROM,&Meter_Parameter.parameter2.MeterSoftIdNumber[0],8,0,0);
	Set_Meter_para_Deal(METERSOFTIDNUMBER_ROM);
	
	return 0;
}

int GetNowMonthComActiveEnergy(void)
{
	unsigned char unc;
	unsigned char result;
	unsigned int  uni;
	
	*((unsigned long *)&Readdata_buff[0])=This_Month_Data.Energy_Record.Plus_Active[0];
	*((unsigned long *)&Readdata_buff[4])=This_Month_Data.Energy_Record.Nega_Active[0];
	
	uni=O1ther_Meter_Parameter.Bill_Addr;
	if(uni>0)
	  uni--;
	else
	  uni=13;
	
	for(unc=0;unc<2;unc++)
	{
    result=WRLC256(uni*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM+unc*4*MAXTRIFF,
    &Readdata_buff[8+unc*4],4,0,1);
    
    if(result!=0xff)
      return -1;
  }
	
	for(unc=0;unc<2;unc++)
	{
		if((*((unsigned long *)&Readdata_buff[0+4*unc]))>=(*((unsigned long *)&Readdata_buff[8+4*unc])))
		{
			(*((unsigned long *)&Readdata_buff[0+4*unc]))=
			(*((unsigned long *)&Readdata_buff[0+4*unc]))-(*((unsigned long *)&Readdata_buff[8+4*unc]));
			
		}
		else
		{
			(*((unsigned long *)&Readdata_buff[0+4*unc]))=
			((unsigned long)Cal_EnergyLimit())-(*((unsigned long *)&Readdata_buff[8+4*unc]))+(*((unsigned long *)&Readdata_buff[0+4*unc]));
			
		}
	}
	
	return 0;
}

int GetLastMonthComActiveEnergy(void)
{
	unsigned char unc;
	unsigned char result;
	unsigned int  uni;
	
	uni=O1ther_Meter_Parameter.Bill_Addr;
	if(uni>0)
	  uni--;
	else
	  uni=13;
	
	for(unc=0;unc<2;unc++)
	{
    result=WRLC256(uni*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM+unc*4*MAXTRIFF,
    &Readdata_buff[unc*4],4,0,1);
    
    if(result!=0xff)
      return -1;
  }
  
  if(uni>0)
	  uni--;
	else
	  uni=13;
  
  for(unc=0;unc<2;unc++)
	{
    result=WRLC256(uni*sizeof(struct ENERGY_RECORD)+ENERGY_RECORD_ROM+unc*4*MAXTRIFF,
    &Readdata_buff[8+unc*4],4,0,1);
    
    if(result!=0xff)
      return -1;
  }
	
	for(unc=0;unc<2;unc++)
	{
		if((*((unsigned long *)&Readdata_buff[0+4*unc]))>=(*((unsigned long *)&Readdata_buff[8+4*unc])))
		{
			(*((unsigned long *)&Readdata_buff[0+4*unc]))=
			(*((unsigned long *)&Readdata_buff[0+4*unc]))-(*((unsigned long *)&Readdata_buff[8+4*unc]));
			
		}
		else
		{
			(*((unsigned long *)&Readdata_buff[0+4*unc]))=
			((unsigned long)Cal_EnergyLimit())-(*((unsigned long *)&Readdata_buff[8+4*unc]))+(*((unsigned long *)&Readdata_buff[0+4*unc]));
			
		}
	}
	
	return 0;
}
int Set_Freeze_Day(void)
{
     if(((*(Co.c.addr5+1))>0x23)||((*(Co.c.addr5+0))>0x59) ) 
                  return -1; 
      return 0;
}

int ReadEnergy01Wh(void)
{	
   unsigned char i;
   
   for(i=0;i<MAXTRIFF;i++)
   {
   	 comm_plus_energy_01wh[i][1]=This_Month_Data.Energy_Record.Plus_Active[i]/1000;
   	 comm_plus_energy_01wh[i][0]=(This_Month_Data.Energy_Record.Plus_Active[i]%1000)*10+energy_rail.Total_Plus_Active_100mwh[i];
     comm_nega_energy_01wh[i][1]=This_Month_Data.Energy_Record.Nega_Active[i]/1000;
   	 comm_nega_energy_01wh[i][0]=(This_Month_Data.Energy_Record.Nega_Active[i]%1000)*10+energy_rail.Total_Nega_Active_100mwh[i];
   }

   return  0;
}

/*"函数功能:根据复位主动上报状态字来清主动上报状态字对应位和事件上报次数对应项功能"*/
/*"输入参数:"*/
/*"输出参数:"*/
/*"调用说明:发复位主动上报状态字命令时调用"*/
int ResetEventReportInfo(void)
{
       unsigned int uni;
       unsigned char newevent_flag,returnevent_flag;
	union EVENT_REPORT_STATUS EventReportStatus_temp,ResetEventReportStatus;
    
    newevent_flag=0;/*"判断是否有新增事件发生的标识,newevent_flag=0没有新增事件，newevent_flag=1表示有新增事件"*/
    returnevent_flag=0;/*"判断复位主动上报命令里是否有对非抄读的事件复位，returnevent_flag=0表示没有;returnevent_flag=1表示有"*/

    if(0 == O1ther_Meter_Parameter.ResetEventReport_flag)/*"只有抄读主动上报状态字才执行复位主动上报状态字命令"*/
	{
        	Meter_States.ErrOfInformation.bit.Invalid_Password=1;
        	return -1;
	}
	
	for(uni=0;uni<12;uni++)
	{
		EventReportStatus_temp.byte[uni] = Readdata_buff[uni]=*(Co.c.addr5+uni);
	}

       for(uni=0; uni<12; uni++)
	{
               ResetEventReportStatus.byte[uni]=Event_Report_Status_communication.byte[uni]^Event_Report_Status.byte[uni];/*"判断是否有新增事件发生"*/
	}
    for(uni=0;uni<12;uni++)
	{
          if(0x00!=ResetEventReportStatus.byte[uni])
          {
                   newevent_flag=1;
                   break;
          }
	}
  
    if(1==newevent_flag)/*"newevent_flag=1表示有新增事件发生"*/
    {
        for(uni = 0;uni  < 96;uni++)
     {
       if(!(EventReportStatus_temp.byte[uni>>3] & (0x01 << (uni & 0x07))))/*"复位主动上报状态字为0的位才清主动上报状态字对应状态"*/
       {
        if(!(Event_Report_Status_communication.byte[uni>>3] & (0x01 << (uni & 0x07))))/*"复位主动上报状态字只能复位已经上报的，对没有上报的复位就报错"*/
        {
              returnevent_flag=1;
              break;
        }   
      }
    }
        if(1==returnevent_flag)
        {
        	Meter_States.ErrOfInformation.bit.Invalid_Password=1;
        	return -1;
	}
    }
    
     Clear_EventReportStatus_And_Times(EventReportStatus_temp);
     if(0==EventReportStatus_temp.bit.Switch_on)
     {
     O1ther_Meter_Parameter.SwitchOn_Report=0;
     WRLC256(SWITCHON_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOn_Report,1,0,0);
     }
     
     if(0==EventReportStatus_temp.bit.Switch_off)
      {
            O1ther_Meter_Parameter.SwitchOff_Report=0;
            WRLC256(SWITCHOFF_REPORT_ROM,(unsigned char *)&O1ther_Meter_Parameter.SwitchOff_Report,1,0,0); 
      }
	return 0;
}
/*"函数功能:清主动上报状态字和事件上报次数功能"*/
/*"输入参数:复位主动上报状态字"*/
/*"输出参数:"*/
/*"调用说明:根据复位主动上报状态字清对应的状态和次数"*/
void Clear_EventReportStatus_And_Times(union EVENT_REPORT_STATUS ResetEventReportStatus)
{
     unsigned int uni;
     unsigned char wflag[3];  //0-Event_Report_Status 1-Event_Report_Status_Backup 2-Event_Report_Status_Times

     wflag[0]=0;
     wflag[1]=0;
     wflag[2]=0;
     
     for(uni=0; uni<12; uni++)
     {
        if(Event_Report_Status.byte[uni]!=(Event_Report_Status.byte[uni]&ResetEventReportStatus.byte[uni]))
        {
          wflag[0]=1;
        }
        if(Event_Report_Status_Backup.byte[uni]!=(Event_Report_Status_Backup.byte[uni]&ResetEventReportStatus.byte[uni]))
        {
          wflag[1]=1;
        }
        Event_Report_Status.byte[uni] &= ResetEventReportStatus.byte[uni];
        Event_Report_Status_Backup.byte[uni]&= ResetEventReportStatus.byte[uni];
     }
       
     for(uni = 0;uni  < 96;uni++)
     {
       if(!(ResetEventReportStatus.byte[uni>>3] & (0x01 << (uni & 0x07))))/*"复位主动上报状态字为0的位才清主动上报状态字对应状态"*/
       {
         *((unsigned char *)&Event_Report_Status_Times + uni)=0;
         wflag[2]=1;
      }
    }

     if(wflag[0]!=0)
     {
       WRLC256(EVENT_REPORT_STATUS_ROM,(unsigned char *)&Event_Report_Status,sizeof(union EVENT_REPORT_STATUS),0,0);
     }
     if(wflag[1]!=0)
     {
       WRLC256(EVENT_REPORT_STATUS_BACKUP_ROM,(unsigned char *)&Event_Report_Status_Backup,sizeof(union EVENT_REPORT_STATUS),0,0);
     }
     FeedWatchdog();
     if(wflag[2]!=0)
     {
       WRLC256(EVENT_REPORT_STATUS_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times,sizeof(struct EVENT_REPORT_STATUS_TIMES),0,0);
     }
     FeedWatchdog();

     O1ther_Meter_Parameter.ResetEventReport_flag=0;
     O1ther_Meter_Parameter.EventReport_RunTime=0;
     WRLC256(EVENTREPORT_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.EventReport_RunTime,3,0,0);
     FeedWatchdog();
     
     for(uni=0; uni<12;uni++)
     {
     if(Event_Report_Status.byte[uni] !=0)
        break ;
     }
     if(uni>=12)
     {
     Event_Report_flag = 0;
     MK_EVENT = 0;
     }
     
}

int Set_ResetReportTime(void)
{
     if((*(Co.c.addr5))>0x99) 
                  return -1; 
      return 0;
}


int Set_Read_Block_Para(union ID id,unsigned char *rBuffer,unsigned char data_len,unsigned char mode)
{
	unsigned int  eepromaddr;
	unsigned char len;
	unsigned char dealflag;
	unsigned int  i;
	
	len=0;
	dealflag=0;
	
	if((O1ther_Meter_Parameter.WorkRoomState==0)||(mode==1)||(mode==3))
  {
		Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
		return 0;
	}
	
	switch(id.l)
	{
		case 0x0E0E0000:
		case 0x0E0E0001:
		case 0x0E0E0002:
		  len=165;
		  eepromaddr=CYCLEDISPLAYTABLE_A_ROM+id.d[0]*((unsigned int)165);
		break;
		
		case 0x0E0E0003:
		case 0x0E0E0004:
		case 0x0E0E0005:
		case 0x0E0E0006:
		  len=150;
		  eepromaddr=CYCLEDISPLAYTABLE_B_ROM+(id.d[0]-3)*((unsigned int)150);
		break;
		
		case 0x0E0E0007:
		  len=4;
		  eepromaddr=HOLIDAYSLOT_ROM;
		  dealflag=1;
		break;
	}
	
	if(len==0)
	{
	  return 0;
	}
	
	if(mode==0)//Read
	{
		if(dealflag==1)
		{
			for(i=0;i<4;i++)
			{
				*(rBuffer+i)=0xEE;
			}
			WRLC256(eepromaddr,&Co.b[0],((unsigned int)4)*MAXHOLIDAYSLOT,0,1);
			FeedWatchdog();
			for(i=1;i<MAXHOLIDAYSLOT;i++)
			{
				if((Co.b[0]!=Co.b[i*4])||(Co.b[1]!=Co.b[1+i*4])||(Co.b[2]!=Co.b[2+i*4])||(Co.b[3]!=Co.b[3+i*4]))
				{
				  break;
				}
			}
			if(i>=MAXHOLIDAYSLOT)
			{
				for(i=0;i<4;i++)
				{
					*(rBuffer+i)=Co.b[i];
				}
			}
		}
		else
		{
		  WRLC256(eepromaddr,rBuffer,len,0,1);
		}
	}
	else//Write
	{
		if(data_len!=(len+12))
		{
		  return 0;
		}
		
		if(dealflag==1)
		{
			for(i=0;i<6;i++)
			{
				Co.b[i]=0;
			}
			Co.b[6]=*(rBuffer);
			Co.b[2]=*(rBuffer+1);
			Co.b[1]=*(rBuffer+2);
			Co.b[0]=*(rBuffer+3);
			
			if((Co.b[0]!=0)||(Co.b[1]!=0)||(Co.b[2]!=0)||(Co.b[6]!=0))
			{
				if((CheckTime(&Co.b[0])==0)||(Co.b[6]==0)||(Co.b[6]>MAXDAILYSLOTTABLE))
				{
					return 0;
				}
			}
			
			
			for(i=0;i<MAXHOLIDAYSLOT;i++)
			{
				Co.b[i*4]=*(rBuffer);
				Co.b[1+i*4]=*(rBuffer+1);
				Co.b[2+i*4]=*(rBuffer+2);
				Co.b[3+i*4]=*(rBuffer+3);
			}
			FeedWatchdog();
			WRLC256(eepromaddr,&Co.b[0],((unsigned int)4)*MAXHOLIDAYSLOT,0,0);
		}
		else
		{
		  WRLC256(eepromaddr,rBuffer,len,0,0);
	  }		
	}
	
	FeedWatchdog();
	
	return len;
}

