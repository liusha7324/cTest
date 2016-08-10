
/*-------------------------- AllVoltageLoss Program -------------------------------
Function:	measure all_voltage_loss time and update all_voltage_loss event
Chief subfunction name:
			AllVoltageLoss_PowerDown_Init();
					//called condition:called before going into SLEEP
			AllVoltageLoss_PowerOn_Result_Updating();
					//called condition:called before going into main cycle
			AllVoltageLoss_WakingUp_Counter_Updating();
					//called condition:It's INT 3 interrupt service routine.
			AllVoltageLoss_SecondCounter_Updating();
					//called condition:called in persecond interrupt service routine
												 in powerdown mode.

------------------------------------------------------------------------------------*/
#include		"defmcro.h"
#include		"defdata.h"
#include		"Init_program_LDH.H"
#include		"I2C_operation.h"
#include "MB_Keymain.h"
//ganjp 20090326
#include         "interrupt.h"//ganjp 20090326
#include "Measure_Interface.h" 
#include	       "ram.h"//ganjp 20090326
#include	       "comm.h"
#include         "eventnew.h"
#include "AllVoltageLoss.h"

#define			Max_WakingUp_Times_Persecond		252	/*If wakeup times>252 in 1 second,it is invalid."每秒内全失压脉冲的最大次数"*///LDH20060707
#define			Min_WakingUp_Times_Persecond		35	/*If wakeup times<35 in 1 second,it is invalid."每秒内全失压脉冲的最少次数"*/
#define			AllVoltageLoss_Start_Seconds_Limit	30	/*"连续30秒都有全失压发生,1次全失压事件开始"*/
#define			AllVoltageLoss_End_Seconds_Limit	30	/*"连续30秒都没有全失压发生,1次全失压事件结束"*/
#define     READ_ATERNAL 600//GANJP 20090331

#define     MAXPDREADVOLTDELAYTIME 10
#define     MAXPDREADVOLTDELAY     200
#define     PDREADVOLTBEGINTIME    4

//=================public===================
struct	ALLVOLTAGELOSS_STRUCTURE AllVoltageLoss_Structure;	

struct   PD_CURRENT_STRUCT  PD_curr;//ganjp 20091103
volatile unsigned long PD_max_curr;//ganjp 20090325
unsigned long AllVoltageLoss_counter;//ganjp 20090330
unsigned char Curr_Valid_flag;//ganjp 20090325
unsigned char Curr_RD_flag;//ganjp 20091103
unsigned char L_PD_Last_T;//ganjp 20091103 
unsigned char lastpdreadcurrtime;  
//unsigned char Curr_OK;//ganjp 20091224
//=================private===================

struct	PDVOLT_STRUCTURE  pdvoltdata;



//=================public===================
void AllVoltageLoss_WakingUp_Counter_Updating(void);	/*INT3:"全失压脉冲中断服务程序"*/

void	AllVoltageLoss_PowerDown_Init(void);			/*"进入低功耗前全失压数据的初始化"*/
void	AllVoltageLoss_SecondCounter_Updating(void);	/*"更新全失压时间(秒)和本次掉电期间的开始和结束的事件记录(RAM中)：
													  		在低功耗的秒中断服务程序中调用"*/
													  		
/*"取得全失压事件记录地址、条数和全失压时间，由上电处理主程序调用，如果返回的全失压事件记录的条数为0,则不需要更新全失压数据的内容"*/
void	Get_AllVoltageLoss_Event_Address_Times(unsigned int *Event_Pointer,				/*"全失压事件记录的RAM指针"*/
											   unsigned char *Event_Number,					/*"本次掉电期间全失压事件记录的条数"*/
											   unsigned long *AllVoltageLoss_Minute_Time);	/*"本次掉电期间全失压发生的时间：分钟"*/

void AllVoltageLoss_Close_Measure(void);//ganjp 20090325
void Read_Curr_Powerdown(void);//ganjp 20090325
//----------------ganjp 20090927--------------
unsigned char Check_Open_power(void);
unsigned char Check_All_lossvoltage_Start(void);

//=================private===================		
void	AllVoltageLoss_PowerOn_Result_Updating(void);	/*"上电时RAM中的全失压数据处理"*/
void	Write_AllVoltageLoss_Event_In_Ram(struct ALLVOLTAGELOSS_EVENT *Event_Pointer,unsigned char *Pointer,
											unsigned char Start_End_Flag);		/*"0:开始，1:结束"*/

unsigned char 	Check_AllVoltageLoss_Data_Validity(void);	/*"检查数据的有效性"*/
void AllVoltageLoss_init_Measure(void);//ganjp 20090325
unsigned char Check_PD_Curr_Vality(void);//ganjp 20091104
//---------------------------------------------

extern void clear_show_lcd(void);

void Pd_Init_Measure(void);
void Pd_Close_Measure(void);

/*---------------------------------------------- */
#pragma INTERRUPT AllVoltageLoss_WakingUp_Counter_Updating
void	AllVoltageLoss_WakingUp_Counter_Updating(void)	/*INT3:"全失压脉冲中断服务程序"*/
		{
			AllVoltageLoss_Structure.AllVoltageLoss_WakingUp_Counter+=1;
		}
		
/*"============================================================"*/
/*"函数名：AllVoltageLoss_PowerDown_Init"*/
/*"用途：全失压数据初始化"*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：进入低功耗时调用一次"*/
/*"作者：LDH        修改:ZLP"*/
/*"============================================================"*/
void	AllVoltageLoss_PowerDown_Init(void)	/*"进入低功耗前全失压数据的初始化"*/
{
	unsigned int i;
			
	for(i=0;i<sizeof(struct	ALLVOLTAGELOSS_STRUCTURE);i++)
		 *((unsigned char *)&AllVoltageLoss_Structure.Valid_AllVoltageLoss_Flag+i)=0;
	
	for(i=0;i<sizeof(struct	PD_CURRENT_STRUCT);i++)
		 *((unsigned char *)&PD_curr+i)=0;
			
	Curr_RD_flag = 0;
	L_PD_Last_T = 0;
	lastpdreadcurrtime=0;
	load_flag=0xff;
			
	if(IF_Powerup_Billdata==0)
		Curr_RD_flag = 0xff;
}

#if(ALLLOSSVOLTAGE_MODE == 0)	
/*"============================================================"*/
/*"函数名：AllVoltageLoss_SecondCounter_Updating"*/
/*"用途：判断全失压事件起始、结束，记录事件记录，累计时
                     间和次数(数据更新在RAM中)"*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：低功耗的秒中断服务程序中调用"*/
/*"作者：LDH        修改:GANJP"*/
/*"============================================================"*/
void	AllVoltageLoss_SecondCounter_Updating(void)	
		{
		unsigned char uni;//ganjp 20090330
		unsigned int i;
			if(V_D==0)								/*"进低功耗前，要把V_D置成输入口"*/
			 {
			  if(((AllVoltageLoss_Structure.AllVoltageLoss_WakingUp_Counter>=Min_WakingUp_Times_Persecond)&&
			  	(AllVoltageLoss_Structure.AllVoltageLoss_WakingUp_Counter<=Max_WakingUp_Times_Persecond)) ||(pdmode3 == 0x33))//LDH20060707
				{  
				//-------ganjp 20090325----------------------
				if(Check_Open_power())
					{
					if(PULSE_PWR == 0)
						{
						AllVoltageLoss_init_Measure();
						pdmode3 = 0x33;
						}
					
					}	
				//-------ganjp 20090325----------------------	
					AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_End=0;
					if(AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag)
						{	/*"已经开始"*/
							AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds++;
							AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds_Copy++;
							
						}
					else
						{	/*"还没有开始"*/
							AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_Start++;
							
							if(Check_All_lossvoltage_Start())
								{	/*"新的一次全失压事件开始"*/
									AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_Start=0;
									
									Write_AllVoltageLoss_Event_In_Ram(&(AllVoltageLoss_Structure.AllVoltageLoss_Event[0]),
																	  &AllVoltageLoss_Structure.AllVoltageLoss_Event_Pointer_in_Powerdown_Mode,
																	  0);
									AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag=1;
									AllVoltageLoss_Structure.AllVoltageLoss_Event_Times++;		/*"本次掉电期间发生全失压的次数"*/
									for(i=0;i<8;i++)		/*OK:0,1,2,3,4,5,6,7:"全失压时间有效标志：掉电时置成全0,全失压发生时置成01234567,上电时用"*/
										AllVoltageLoss_Structure.Valid_AllVoltageLoss_Flag[i]=i;//LDH20081213
									
								}							
						}
				}
			  else
				{
					if(AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag)
						{	/*"已经开始，结束还不到规定的秒数，照样计时间"*/
							AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds++;
							AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds_Copy++;
						}
					//ganjp 20090401
					if(Curr_Valid_flag == 0)/*"电流有效值标志有效的情况下暂不清，躲避V3P3下降时没有脉冲的情况"*/
					AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_Start=0;
					AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_End++;
					//ganjp 20090401
					if(AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_End > 25)/*"25秒钟没有有效全失压脉冲将电流有效值标志清零"*/
					Curr_Valid_flag = 0;
					if(AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_End>=AllVoltageLoss_End_Seconds_Limit)
						{
							if(AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag)
								{
									
									Write_AllVoltageLoss_Event_In_Ram(&(AllVoltageLoss_Structure.AllVoltageLoss_Event[0]),
																	  &AllVoltageLoss_Structure.AllVoltageLoss_Event_Pointer_in_Powerdown_Mode,
																	  1);
									AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag=0;
									PD_max_curr = 0;//ganjp 20090326
									for(uni=0;uni<3;uni++)
                   {
                      Curr[uni]=0;
                   }
								}
						}
				}
			 }	
			AllVoltageLoss_Structure.AllVoltageLoss_WakingUp_Counter=0;
		}
	
/*"============================================================"*/
/*"函数名：Get_AllVoltageLoss_Event_Address_Times"*/
/*"用途：取得全失压事件记录地址、条数和全失压时间"*/
/*"参数：unsigned int *Event_Pointer:全失压事件记录的RAM指针
                     unsigned char *Event_Number:本次掉电期间全失压事件记录的条数
                     unsigned long *AllVoltageLoss_Minute_Time:本次掉电期间全失压发生的时间：分钟"*/
/*"返回：无"*/
/*"调用：上电记录全失压时调用"*/
/*"作者：LDH        修改:GANJP"*/
/*"============================================================"*/
void	Get_AllVoltageLoss_Event_Address_Times(unsigned int *Event_Pointer,				/*"全失压事件记录的RAM指针"*/
											   unsigned char *Event_Number,					/*"本次掉电期间全失压事件记录的条数"*/
											   unsigned long *AllVoltageLoss_Minute_Time)	/*"本次掉电期间全失压发生的时间：分钟"*/
		{
			unsigned char number;
			unsigned char Valid_Status;
			Valid_Status=Check_AllVoltageLoss_Data_Validity();	/*"检查数据的有效性"*/
			if(Valid_Status)
				{	/*"数据有效"*/
					AllVoltageLoss_PowerOn_Result_Updating();			/*"上电时RAM中的全失压数据处理"*/
					//if(AllVoltageLoss_Structure.AllVoltageLoss_Event_Times>=10)
					//	number=10;
					//else
						number=AllVoltageLoss_Structure.AllVoltageLoss_Event_Times;
			
					*Event_Pointer=(unsigned int)(&(AllVoltageLoss_Structure.AllVoltageLoss_Event[0]));	/*"全失压事件记录的RAM指针"*/
					*Event_Number=number;									/*"本次掉电期间全失压事件记录的条数"*/
					if(AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds>=AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds_Copy)
						*AllVoltageLoss_Minute_Time=AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds/60;			/*"本次掉电期间全失压发生的时间：分钟"*/
					else
						*AllVoltageLoss_Minute_Time=AllVoltageLoss_Structure.AllVoltageLoss_Time_Seconds_Copy/60;
				}
			else	
				{	/*"数据无效！！！"*/
					*Event_Number=0;									/*"本次掉电期间全失压事件记录的条数"*/
					*AllVoltageLoss_Minute_Time=0;						/*"本次掉电期间全失压发生的时间：分钟"*/
				}
		}
	
/*"============================================================"*/
/*"函数名：AllVoltageLoss_PowerOn_Result_Updating"*/
/*"用途：全失压正在发生上电时RAM中的全失压数据处理"*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：上电全失压记录时调用"*/
/*"作者：LDH        修改:"*/
/*"============================================================"*/
void	AllVoltageLoss_PowerOn_Result_Updating(void)	/*"上电时RAM中的全失压数据处理"*/
		{
			unsigned int i;
			//unsigned char Valid_Status;
			
			//Valid_Status=Check_AllVoltageLoss_Data_Validity();	/*"检查数据的有效性"*/
			
			//if(Valid_Status)
			//	{
					if(AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag==1)	/*"已开始的全失压事件还没有结束就上电了"*/
						{
							Write_AllVoltageLoss_Event_In_Ram(&(AllVoltageLoss_Structure.AllVoltageLoss_Event[0]),
															  &AllVoltageLoss_Structure.AllVoltageLoss_Event_Pointer_in_Powerdown_Mode,
															  1);
							AllVoltageLoss_Structure.AllVoltageLoss_Start_Flag=0;
						}					
			//	}
		}
	
/*"============================================================"*/
/*"函数名：Write_AllVoltageLoss_Event_In_Ram"*/
/*"用途：低功耗下全失压起始、结束时，写该条记录到RAM"*/
/*"参数：struct ALLVOLTAGELOSS_EVENT *Event_Pointer:写入的RAM地址(10条事件记录空间)
                     unsigned char *Pointer:该事件要写入位置的条数指针(10条事件记录空间)
                     unsigned char Start_End_Flag:0:开始，1:结束"*/
/*"返回：无"*/
/*"调用：低功耗全失压事件发生、结束时调用调用"*/
/*"作者：LDH        修改:GANJP"*/
/*"============================================================"*/
void	Write_AllVoltageLoss_Event_In_Ram(struct ALLVOLTAGELOSS_EVENT *Event_Pointer,unsigned char *Pointer,
											unsigned char Start_End_Flag)		/*"0:开始，1:结束"*/
		{
			struct	DATEANDTIME_DEF AllVoltageLoss_DateAndTime;
//			Read_Date_And_Time((unsigned char*)&AllVoltageLoss_DateAndTime,	//DatePointer-->struct DATEANDTIME_DEF
//						 		0);											//DeviceName=0:DS1375,1:RX8025
      ClockChipRead((unsigned char *)&AllVoltageLoss_DateAndTime);
			if(Start_End_Flag==0)
				{
					Event_Pointer[(*Pointer)].Start_Year=AllVoltageLoss_DateAndTime.Year;
					Event_Pointer[(*Pointer)].Start_Month=AllVoltageLoss_DateAndTime.Month;
					Event_Pointer[(*Pointer)].Start_Day=AllVoltageLoss_DateAndTime.Day;
					Event_Pointer[(*Pointer)].Start_Hour=AllVoltageLoss_DateAndTime.Hour;
					Event_Pointer[(*Pointer)].Start_Minute=AllVoltageLoss_DateAndTime.Min;
					Event_Pointer[(*Pointer)].Start_Second=AllVoltageLoss_DateAndTime.Sec;  //add by pc 081208
					Event_Pointer[(*Pointer)].Curr_PD = PD_max_curr;//ganjp 20090327
						
					Event_Pointer[(*Pointer)].End_Year=0xFF;
					Event_Pointer[(*Pointer)].End_Month=0xFF;
					Event_Pointer[(*Pointer)].End_Day=0xFF;
					Event_Pointer[(*Pointer)].End_Hour=0xFF;
					Event_Pointer[(*Pointer)].End_Minute=0xFF;
					Event_Pointer[(*Pointer)].End_Second=0xFF;  //change by pc 081208
				}
			else
				{
					Event_Pointer[(*Pointer)].End_Year=AllVoltageLoss_DateAndTime.Year;
					Event_Pointer[(*Pointer)].End_Month=AllVoltageLoss_DateAndTime.Month;
					Event_Pointer[(*Pointer)].End_Day=AllVoltageLoss_DateAndTime.Day;
					Event_Pointer[(*Pointer)].End_Hour=AllVoltageLoss_DateAndTime.Hour;
					Event_Pointer[(*Pointer)].End_Minute=AllVoltageLoss_DateAndTime.Min;
					Event_Pointer[(*Pointer)].End_Second=AllVoltageLoss_DateAndTime.Sec;  //add by pc 081208
					(*Pointer)++;
					if((*Pointer)>=10)	(*Pointer)=0;
				}

		}

/*"============================================================"*/
/*"函数名：Check_AllVoltageLoss_Data_Validity"*/
/*"用途：低功耗下全失压起始、结束时，写该条记录到RAM"*/
/*"参数：struct ALLVOLTAGELOSS_EVENT *Event_Pointer:写入的RAM地址(10条事件记录空间)
                     unsigned char *Pointer:该事件要写入位置的条数指针(10条事件记录空间)
                     unsigned char Start_End_Flag:0:开始，1:结束"*/
/*"返回：无"*/
/*"调用：低功耗全失压事件发生、结束时调用调用"*/
/*"作者：LDH        修改:"*/
/*"============================================================"*/
unsigned char 	Check_AllVoltageLoss_Data_Validity(void)	/*"检查数据的有效性"*/
		{
			unsigned char return_value=0xff;
			unsigned int i;
			for(i=0;i<8;i++)							/*OK:0,1,2,3,4,5,6,7:"全失压时间有效标志：上电时用"*/
				{
					if(AllVoltageLoss_Structure.Valid_AllVoltageLoss_Flag[i]!=i)
						{
							return_value=0;
							break;
						}
					
				}
			return return_value;
		}  

/*"============================================================"*/
/*"函数名：Check_Open_power"*/
/*"用途：check if need open meter power"*/
/*"参数：无"*/
/*"返回：0:no need ;  0xff:  need"*/
/*"调用：低功耗检测到有全失压脉冲信号时调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
unsigned char Check_Open_power(void)
{
unsigned char result = 0;
if(Meter_Parameter.parameter1.MeterMode[2].bit.b0)//record alllossvoltage current founction opened
{
if((AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_Start>=29)
	&&(Curr_Valid_flag == 0)
	&&(((AllVoltageLoss_counter % READ_ATERNAL) == 0)))////5--->6
	||(pdmode3 == 0x33))
	result = 0xff;
}
return result;
}

/*"============================================================"*/
/*"函数名：Check_All_lossvoltage_Start"*/
/*"用途：check if all lossvoltage start"*/
/*"参数：无"*/
/*"返回：0:no;  0xff:  start"*/
/*"调用：低功耗检测到有全失压脉冲信号时调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
unsigned char Check_All_lossvoltage_Start(void)
{
unsigned char result = 0;
if(AllVoltageLoss_Structure.AllVoltageLoss_Counter_Before_Start>=AllVoltageLoss_Start_Seconds_Limit)
{
if(Meter_Parameter.parameter1.MeterMode[2].bit.b0)
{
if(Curr_Valid_flag == 0xff)
result = 0xff;
}
else
{
result = 0xff;
}
}
return result;
}


#else
/*"============================================================"*/
/*"函数名：Check_PD_Curr_Vality"*/
/*"用途：检测低功耗下读取的电流值的合法性"*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：上电初始化时调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
unsigned char Check_PD_Curr_Vality(void)
{
  unsigned char unc;
  unsigned char result;
  
  result=1;
  
  for(unc = 0; unc < 8; unc++)
  {            
	  if(PD_curr.validflag[unc]!=unc)  //mw modified 2009-03-03
	  {
	    result=0;
	    break;
	  }
  }
  
  return result;
}
#endif

/*"============================================================"*/
/*"函数名：AllVoltageLoss_init_Measure"*/
/*"用途：切换到主晶振，初始化6515 SPI口，打开6515电源 "*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：Check_Open_power函数返回0xff值时调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
void AllVoltageLoss_init_Measure(void)
{
	Prepare_for_Wakeup(0);
	Delay(1);
	Pd_Init_Measure();
	load_flag = 0xff;
}

void Pd_Init_Measure(void)
{
	pd0 |= 0x0c;
	p0  |= 0x0c;
	/*"全失压开启计量芯片电源时将PM0/PM1都设置为1，让计量芯片工作在最大功耗模式，"*/
	/*"避免后面进行模式切换时，因功耗增加导致V3P3电源波动，可能不记录全失压问题"*/
	pd8_6 = 1;
	pd8_7 = 1;
	p8_6 = 1;
	p8_7 = 1;
	
	pd5_2 = 1;	
	PULSE_PWR=1;//6515 powerup
	Delay(1); 

	vMeter_Init(METER_RST_TYPE_PWRDOWN);	
	
	prcr|=0x04;		  /*"必须加这1句"*/
	pd9=0xf5;
	p9=0x05;   
	prcr=0x00;
}

/*"============================================================"*/
/*"函数名：AllVoltageLoss_Close_Measure"*/
/*"用途：关闭主晶振，初始化6515 SPI口，关闭6515电源 "*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：低功耗全失压发生时读完电流后调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
void AllVoltageLoss_Close_Measure(void)
{
	 
	 Curr_RD_flag = 0xff;
	 
	 Pd_Close_Measure(); 
           
   if((pdmode2 == 0)&&(farwakeupreadyflag==0))
   {
     Prepare_for_Wait();
   }
   pdmode3 = 0;
   
}

void Pd_Close_Measure(void)
{
	 pd8_6=1;  //pm1
   p8_6=0;
   pd8_7=1;  //pm0
   p8_7=0;
   pd0_7=0;  //cs
   p0_7=0; 
   prcr|=0x04;		  /*"必须加这1句"*/
   pd9=0xf7;  
   p9=0x00;   
   prcr=0x00; 
   pd0_6=1;  //rst
   p0_6=0;
   PULSE_PWR=0;
}

/*"============================================================"*/
/*"函数名：Read_Curr_Powerdown"*/
/*"用途：读全失压情况下的电流值"*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：低功耗全失压发生时给计量发完校表参数1S后调用"*/
/*"作者：GANJP    20090325"*/
/*"============================================================"*/
void Read_Curr_Powerdown(void)
{
	unsigned char i;
	unsigned char result;
  
	result = fgMeter_GetCurr();
	
	if(result != 0)
	{
		for(i=0;i<3;i++)
		{
			Curr[i] = _rMeter_Data_Buffer.dwCurr[i];
		}
	}      
}


extern const unsigned long Vn[4];

void Read_Volt_Powerdown(void)
{
   unsigned char ri;
   unsigned char i;
   unsigned char unc;
   unsigned char und;
   unsigned long temp_data1;
   unsigned char result;
   
   for(i=0;i<sizeof(struct PDVOLT_STRUCTURE);i++)
	   *((unsigned char *)&pdvoltdata+i)=0;
   
   if(IF_Powerup_Billdata!=0)
   {  
     clear_show_lcd(); 
     Exit_Normal_Show();
     p3_2=0;
     pd5_6=1;
     p5_6=0;
     pd5_7=1;
     p5_7=0;
     
     Pd_Init_Measure();    //open 90e32
     
     for(und=0;und<4;und++)//400ms for 90e32 steady
     {
     	 Delay(100);
     }
     
     if(fgJustParaPDLoad()!=0)//input just parameter
     {
      for(und=0;und<MAXPDREADVOLTDELAYTIME;und++)
      {
       Delay(MAXPDREADVOLTDELAY);
       if((und>=PDREADVOLTBEGINTIME)&&(V_D==0))
       {
          result=1;
	        for(i = 0; i < 3; i++)
	        {
		        _rMeter_Data_Buffer.dwVolt[i] = 0;
	        }
			
	        fgMeter_GetVolt();
	        for(i = 0; i < 3; i++)
	        {
		        temp_data1 = _rMeter_Data_Buffer.dwVolt[i];
		        if(temp_data1 < VOLT_LIMIT)
		        {
			        pdvoltdata.volt[i]=temp_data1;
		        }
		        else
		        {
			         result=0;
		        }
	        }
          
          if(result==1)
			    {
				     if((V_REGION==0)||(V_REGION==3))
			       {
				        pdvoltdata.volt[1]=0;
			       }
			
			       pdvoltdata.maxvolt=pdvoltdata.volt[0];
			       for(i=1;i<3;i++)
			       {
				        if(pdvoltdata.maxvolt<pdvoltdata.volt[i]) 
				        pdvoltdata.maxvolt=pdvoltdata.volt[i];
			       }
				     
				     i=V_REGION;
			       i=i%4;
				     if((pdvoltdata.maxvolt*100)<=(Vn[i]*80))
				     {
				     	 break;
				     }
				     
				     if(und==(MAXPDREADVOLTDELAYTIME-1))
				     { 
				       for(i=0;i<8;i++)
				          pdvoltdata.validflag[i]=i;
				     }
			    }
       }
      }
     }
     
     Pd_Close_Measure();    //close 90e32
   }
      
}

