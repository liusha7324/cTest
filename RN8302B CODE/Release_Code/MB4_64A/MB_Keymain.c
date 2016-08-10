/*" MB2表通用版按键程序 (v0.2 bata0401)  	"*/
/*"Creat by TREND 2004-12-1 for shanghai	"*/
/*"Edit  by TREND 2005-04-1 for 通用版 		"*/
//---------------------------------------------------------------------------
//

//#include "sfr62p.h"
#include "ram.h"	//for Meter_parameter
#include "MB_Keymain.h"
#include "MB_Showmain.h"
//#include "MB_Iccard.h"
#include "comm.h"  //for GetNowTime()
#include "eeprom.h"
#include "I2C_operation.h"
#include "interrupt.h"
#include "multi.h"
#include "645_2007.h"
#include "freeze.h"
#include "Pay_def.h"
#include "Ex_Pay_For_Fun.h"
#include "ICcard.h"	//payment
#include "Init_program_LDH.H"   //for 64A// dispose 2010-04-30
#include "Powerdown_LDH.h"  //mw added 2010-05-03
#include "att7022_operation.h"
#include "BackLight_Ctrl.h"///

#define CYC_SHOW_INTERVAL 300
#define SH_MAX_KEY_SHOW_NO_KEY_TIME 60000
#define SH_CYC_SHOW_TIME 30
#define FLASH_TIME 500


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//public funtion
void Key_Initialize(TOn_Key_Click On_Click_Fun);
char Key_Main(void);
void key_interrupts(void);
//char Drop_Cyc_Show(void);
char Drop_Key_Main(void);
void Drop_Key_Initialize(TOn_Key_Click On_Click_Fun,unsigned char kind);
void Exit_Normal_Show(void);
void Enter_Dorp_Show(void);
void Set_show_code_list(int id);

void IR_Set_show_code(long code);
void IR_interrupts(void);
void IR_Timer(void);
void Init_IR_Ctrl(void);
char IR_Set_show_Main(void);

void	Goto_Wait_Exit_Wait(void);
void	Prepare_for_Wait(void);
void	Prepare_for_Wakeup(unsigned char);
void  show_clear_char(void);
extern void HT1623_SEND_DATA(unsigned char LCD_RAM_ADDR,		
						 unsigned char *DATA_ADDR,			
						 unsigned int	DATA_LENGTH);	
//---------------------------------------------------------------------------
//private funtion
//void key_interrupts(void);
char scankey(char key_buf);
void On_KeyClick_For_A_mode_show(char keyval,long time);
void On_KeyClick_For_B_mode_show(char keyval,long time);
//void On_KeyClick_For_C_mode_show(char keyval,long time);
void On_KeyClick_For_C1_mode_show(char keyval,long time);
void On_KeyClick_For_Dropshow(char keyval,long time);
void key_show_no_key_down(void);
int check_cursor_byte(unsigned long byte);
void cyc_show(void);
char IR_keydown(char keyval);
char Ir_Set_User_Show_Code(void);
void	Switch_to_Subclock(void);
void move_showcode(void);
void Cycledisp_A_eeaddr(void);
void Abnormal_Die_Disp(void);
 void show_build_char(void); 
 void show_rebuild_char(void);
//long show_code_step(long code,char step);
//---------------------------------------------------------------------------

//---------------lfy 090921--------------------
void Refresh_FailAbnormalFlag(void);
void Refresh_EventAbnormalFlag(void);
void Show_Err_Type(char type);
void Failure_Abnormal_Func(void);
void Event_Abnormal_Cycle_Show(void);
signed char Search_Event_Abnormal(unsigned char method);/*"从当前位置开始搜索下一个异常代码，0-递增搜索；1-递减搜索"*/
void On_KeyClick_For_Event_Abnomal_show(char keyval,long time);
char Check_Show_Flash_Data(unsigned char,unsigned char ,unsigned char ,unsigned char*);
char Poweron_Event_Show_Data(void);
char Check_Event_Show_Data(unsigned char);
void Refresh_Err_Show(void);//lfy 091226

void SetShowErrNum(unsigned char *,unsigned char *);  //change by pc 120828 

unsigned char  HZ_LCDCmdShow(void);///king chen add 130204

void OutCardInCycshow(void);


//public variable
struct SHOW_CODE_TABLE1 User_Defind_Table1;
struct SHOW_CODE_TABLE2 User_Defind_Table2;




//---------------------------------------------------------------------------
//private variable
char key_va,key_jump_flag;
union byte_def key_flag;/*"bit0 是否有按键按下 0没有，1有"*/
						/*"bit1 "*/
						/*"bit2	显示状态       0循显，1按显"*/
						/*"bit3"*/
						/*"bit4 通过几号按键进入 0 2#，1 4#"*/
						/*"bit5"*/
						/*"bit6"*/
						/*"bit7" 低功耗状态     0正常， 1低功耗  */
struct KEY_VAL {
        union byte_def key_value;
        unsigned int time;
		};
struct KEY_VAL temp_key_val;
struct KEY_VAL real_key_val;
unsigned long start_time; 
unsigned long last_time;
unsigned long scan_time;
unsigned long flash_time;
unsigned long last_Ir_time;

unsigned long show_code,cursor_byte,user_defind_code;
int cyc_show_num;
unsigned int  CYCLEDISPLAYTABLE_A_SCREEN;
unsigned char failure_flag;
unsigned char user_defind_code_len;
unsigned long cyc_show_time;

unsigned long Full_show_time;
unsigned long Full_show_time_Limit;

char drop_cyc_buffer[MAX_LINE_NUM+1][MAX_DATA_NUM];


unsigned char IR_Buf[4];
char IR_bit_num;
unsigned int IR_timer_counter,IR_last_time;
unsigned int IR_d_time[32];
union byte_def IR_Ctrl_flag;/*"bit0 是否有开始信息 0没有，1有"*/

unsigned long dispPaymentTime=0;	//payment

TOn_Key_Click On_Key_Click;
TOn_Set_key_Click On_Set_key_Click;

//------lfy 090927---------------------
signed char Fail_show_cnt;
signed char Event_show_cnt;
union FAIL_ABNORMALl Fail_abnormal;
union EVENT_ABNORMAL Event_abnormal;
union FAIL_ABNORMALl failabnormalshow;
union EVENT_ABNORMAL eventabnormalshow;
unsigned long Fail_show_time;
union BYTE_BIT Abnormal_Show_Mode;/*"b0：1:故障异常显示；"*/
								/*"b1：事件异常循环显示；0：自动循环显示"*/
								/*"b2：事件异常按键显示；0：按键循环显示"*/
unsigned char RefreshShow_KeyOrCyc;/*"刷新低功耗下显示数据 0F:KEY;  F0:CYC"*/

unsigned char IR_intNum=0;	//2011-06-09 add
unsigned long IR_Click_last_Scan_Time;/*"红外上一次重复码发生时刻"*/

struct SHOW_CODE_TABLE1 User_Choose_Table;	/*"选屏显示命令"*/
unsigned char  LCD_Check_State=0xff;/*"液晶屏全点亮命?--- 测试状态    0:显数据标识；0xFF 不执行"*/
unsigned char  LCD_Check_Second;	/*"液晶屏全点亮命?--- 测试状态持续时间，单位为秒"*/
unsigned long HZ_show_start_time=0;/*"显示起始时间"*/
unsigned char light_AlarmSwitchLED=0;
unsigned char light_backled_flag=0;///

unsigned long keydown_start_time;///king chen add 130205

unsigned long pd_now_show_code;             /*"低功耗当前显示数据标识"*/
unsigned long pd_now_user_def_code;         /*"低功耗当前显示用户代码"*/
unsigned char pd_now_user_def_len;          /*"低功耗当前显示用户代码长度"*/
unsigned char pd_time_show_cnt;             /*"低功耗每秒刷新时间定时器"*/

                                
#pragma SECTION rom UserROMData
const char Ir_Code_List[32]=
{
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x00,
0x0a,0x0b,0x0c,0x00,0x16,0x15,0x14,0x00,0x00,0x00,
0x17,0x00,0x0f,0x00,0x11,0x13,0x12,0x0d,0x00,0x18,
0x10,0x0e
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//***************************************************************************
//---------------------------------------------------------------------------
/*"按键中断服务程序"*/                                                                                                               
//---------------------------------------------------------------------------
void key_interrupts(void)
{
	 char port_val;
	 unsigned char result=0;
	port_val=p10;
	port_val&=0x50;
	tr_show_wait(1);
	
	if(!IntoPowerDownFlag)
	{
	   if(port_val==(p10&0x50))
	      result=0xff;
	}
	else
	{
	   if((!(p10&0x40))||(!(p10&0x10)))
	      result=0xff;
	}
	if(result)
	//if(port_val==(p10&0xf0))
	{
		start_time=GetNowTime();
		temp_key_val.key_value.byte=port_val;
		temp_key_val.time=1;
		real_key_val.time=0;
		key_flag.bit.b0=1;
//		key_jump_flag=1;
		key_flag.bit.b1=1;
		//if(key_value.bit.b7==0)
		//	key_flag.bit.b7=1;
		if(IntoPowerDownFlag==0xff)
		{
		     pdmodekeyflag=0xff;
			keykick=0xff;  //mw modified 2010-05-04
			 PowerdownStopKeyAdd=0;
			 /*
			if(pdmode1==0x33)
				key_flag.bit.b0=1;
			else if(pdmode1>0x33)
			{
				pdmode1=0x33;
				key_flag.bit.b0=1;		
			}		
			else
			{
				pdmodekeyflag=0;
				pdmode1=0x33;
				key_flag.bit.b0=0;
			}//modify by zlp
			*/
			if(pdmode1>=0x33)
			{
			    key_flag.bit.b0=1;
			}
			else
			{
			   pdmodekeyflag=0;
			    key_flag.bit.b0=0;
			}
			pdmode1=0x33;
			
			if(Meter_Parameter.parameter1.MeterMode[1].bit.b1)
	                {
	                   pdmode2=0x33;     
	                   if(pdmode2)
	                   {
	                         //p8_0=1;
	                         //pd6_6=0;   
	                         //pd6_7=1;
	                         //p6_7=1;
	                         //Init_Comm(1);
	                         //InitTimeA0();
	                         //IR_FAR_SELECT=0;
	                         //pd10_1=0;
                                 //ta1mr=0x27;
                                 //ta1=0x8000;
                                 //ta1s=0;
	                         //s1ric=0x03;
	                         //s1tic=0x03;
	                         PowerdownStopCommAdd=0;
	                   }
	                }
	                else
	                {
	                   //pd6_6=0;
					   pd7_1=0; //DEBUG
	                   
	                   //pd6_7=0;
					   pd7_0=0; //DEBUG
	                   //p6_7=1;
	                   
	                   pd7_2=0;
	                   
//	                   pd10_1=0;
	                   
	                   pdmode2=0;
	                   
	                }
			Disable_INT5();	
			// dispose a problem 2010-04-30
		}
		///else///king chen mark 130304
		///{		
               ///Light_Back_Up_Flag=0;
              /// Light_Back_Up_Flag=0x99;///king chen modify 130205
            ///   Light_Back_Led();
            ///   keydown_start_time=GetNowTime();///king chen add 130205			   
		///}
	ir_kupic=0;//del by trend for dubug 20041201
	kupic=0;	//set ipl disenable key_int
	}
	
	
	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"正常工作状态下用"*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Key_Initialize(TOn_Key_Click On_Click_Fun)
{
	union byte_def *p_temp;
	
	kupic=0;		/*"关闭按键中断"*/
	pu25=1;			/*"p10.4-p10.7 设为内部上拉"*/
	pd10_4=0;		//p10.4-p10.7 set this port is input port
	//pd10_5=0;		//p10.4-p10.7 set this port is input port
	pd10_6=0;		//p10.4-p10.7 set this port is input port
	//pd10_7=0;		//p10.4-p10.7 set this port is input port
	tr_show_wait(2);/*"延时避免一打开中断就进中断"*/
	ir_kupic=0;		/*"清按键中断请求"*/
	kupic=1;		/*"打开按键中断，设中断级别是1级"*/
	key_flag.bit.b7=0;/*"正常工作模式标志"*/
	//psc_7=0;  //del by trend for dubug 20041201
	
	leaf_flag=0;
       ret_flag=0; 
       show_mode1=0;
	show_leaf_flag=0;
	
	Fail_show_cnt=0;//lfy 090927
	Abnormal_Show_Mode.byte=0;

//       if(CYC_FLAG!=0)
               CYCLEDISPLAYTABLE_A_SCREEN=CYCLEDISPLAYTABLE_A_ROM;
//       else
//               CYCLEDISPLAYTABLE_A_SCREEN=CYCLEDISPLAYTABLE_A_ROM+5;
	//key_value.byte=0xff;
	if(On_Click_Fun)
		 On_Key_Click=On_Click_Fun;/*"设置按键事件"*/
	else
	{
		 On_Key_Click=On_KeyClick_For_A_mode_show;
		 start_time=GetNowTime();
		 SHOW_ABC_SEG(A_SEG);//MODIFY BY ZLP
		 //Show_flag.bit.A_S=1;/*"默认A套显示方案，点亮[A]"*/
		 //Show_flag.bit.B_S=0;
		 //Show_flag.bit.C_S=0;  
	}
//	cyc_show_num=0;
	if(On_Key_Click==On_KeyClick_For_A_mode_show)
	{
		Event_show_cnt=0;
		 if(Event_abnormal.byte)
		 {
		 	Abnormal_Show_Mode.bit.b1=1;
			cyc_show_num=-1;
		 	Event_Abnormal_Cycle_Show();
			Event_show_cnt++;
			return;
		 }
		 else
		 	cyc_show_num=0;
		 LCDREAD( ADDROF_ASCREEN,cyc_show_num);
		 cursor_byte=0xf;
		 cyc_show_time=GetNowTime();
	}
	else if(On_Key_Click==On_KeyClick_For_B_mode_show)	
	{	
		 LCDREAD(ADDROF_B_R0M,cyc_show_num);
		 cursor_byte=0xf;
	}
	/*else if(On_Key_Click==On_KeyClick_For_C_mode_show)
	{	
		User_Defind_Table1.default_code=0;
		User_Defind_Table2.user_code_len=0;
		User_Defind_Table1.flag=0;
		cursor_byte=0x000f0000;
		show_code=0x00000000;
		user_defind_code_len=0;
		show_mode=0;
	}*/
	else if(On_Key_Click==On_KeyClick_For_C1_mode_show)
	{	
		User_Defind_Table1.default_code=0;
		User_Defind_Table2.user_code_len=0;
		cursor_byte=0x0f000000;
		show_code=0x00000000;
		user_defind_code_len=0;
	       show_mode1=1;
		show_leaf_flag=1;
	//	show_mode=1;
	}
	else if(On_Key_Click==On_KeyClick_For_Event_Abnomal_show)
	{
		Abnormal_Show_Mode.bit.b2=1;
		Show_flag.bit.A_S=0;
		Show_flag.bit.B_S=0;
		Show_flag.bit.C_S=0;
		if(Event_show_cnt==0)
			Event_show_cnt=Search_Event_Abnormal(0);
		else if(Event_show_cnt==7)
			Event_show_cnt=Search_Event_Abnormal(1);
		Show_Err_Type(Event_show_cnt+0x50);
		key_flag.bit.b2=1;
		return;
	}
	else
	{
		/*Meter_Parameter.*/User_Defind_Table1.default_code	=show_code;
		/*Meter_Parameter.*/User_Defind_Table2.user_code=user_defind_code;
		/*Meter_Parameter.*/User_Defind_Table2.user_code_len=user_defind_code_len;
	}
	
	
	move_showcode();
//	cyc_show_time=GetNowTime();
	last_Ir_time=0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char Key_Main(void)
{
	char key_buf;
	unsigned long loc_time;
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	unsigned char EventAbnormal_copy;
//       long l_temp,l_temp_1;
	unsigned long temp_time;
       unsigned int i;
	if( key_flag.bit.b0 || IR_Ctrl_flag.bit.b0 )
		Full_show_time_Limit = 0;
//	if(GetTimeCount(Full_show_time,Full_show_time_Limit))
//		{
//		return 0;
//		}
	if(HZ_LCDCmdShow())///king chen add 130204
		return 0;
	


	EventAbnormal_copy=Event_abnormal.byte;
	Refresh_EventAbnormalFlag();
	Refresh_FailAbnormalFlag();

//       if(DIE_FLAG!=0 && key_jump_flag==0)
//       {
//           Abnormal_Die_Disp();
//           return 0xff;
//       }
//       Cycledisp_A_eeaddr();
	if(IR_Set_show_Main()==1)
		return 0x7f;
	
	temp_time=GetNowTime();	
	if(key_flag.bit.b0==0)		/*"没有按键动作，也就是没有进按键中断"*/
	{
		
	        if((kupic&0x07)==0)
		{
		        ir_kupic=0;
		        kupic=1; /*"防止因为按键过快引起按键中断被关闭，而按键无反应"*/
		}
		
		if ((dispCharFlag[0].byte&0xBD)&&(1==Displayfinish_flag))
			{
			dispPaymentChar();
			if (!GetTimeCount(dispPaymentTime,FLASH_TIME))
				{
				show_on_lcd(&vram[0][0],0,32);
				dispPaymentTime=GetNowTime();
				}
			}
		//else if (meterDispErr_ID>0 && dispPaymentFlag.bit.b0==0)
		//	{
		//	if (!GetTimeCount(dispPaymentTime,FLASH_TIME))
		//		{
		//		displayReadCard(DISP_ERR_DATA);
		//		dispPaymentTime=GetNowTime();
		//		}
		//	}
		else 
			{
			 	if(Fail_abnormal.byte && key_jump_flag==0)
     			  	{
					if(GetTimeCount(Full_show_time,Full_show_time_Limit))
						{
						cyc_show_time = GetNowTime();
						cyc_show_num=0;
                        if(O1ther_Meter_Parameter.WorkRoomState)
                        {
                            if(Time500flag)
                            {
                                Show_Main(0x0e070002,&buffer[0][0],0x0e070002,8);
                                show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
                            }
                        }
						return 0;
						}
                   PowerOn_FullScreen_TimeDetection();
                    	Abnormal_Show_Mode.bit.b0=1;
					Failure_Abnormal_Func();
     			  		return 0xff;
     			  	}

				if(key_flag.bit.b2==1)						/*"按显模式"*/
				{
					key_show_no_key_down();
				}
				else										
				{
					if(GetTimeCount(Full_show_time,Full_show_time_Limit))
						{
						cyc_show_time = GetNowTime();
						cyc_show_num=0;
                        if(O1ther_Meter_Parameter.WorkRoomState)
                        {
                            if(Time500flag)
                            {
                                Show_Main(0x0e070002,&buffer[0][0],0x0e070002,8);
                                show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
                            }
                        }
						return 0;
						}
                            PowerOn_FullScreen_TimeDetection();
				/*"故障发生后按键唤醒，循显模式下长时间无按键则返回锁屏状态"*/
					if(key_jump_flag==1 &&( (temp_time-last_time)>SH_MAX_KEY_SHOW_NO_KEY_TIME))
						key_jump_flag=0;
					if(EventAbnormal_copy==0 && Event_abnormal.byte!=0)
					{
						key_flag.bit.b2=0;
						Key_Initialize(On_KeyClick_For_A_mode_show);
					}
					else
					{
//					if(GetTimeCount(Full_show_time,Full_show_time_Limit))
//						{
//						return 0;
//						}					
					Disp_Char_Clear();
					if( Pre_Static_Display_Remain()==0)
					{
						cyc_show();		/*"循显模式"*/
					}
					else //if (display_Remain_Flag)		//payment
					{
						key_buf=display_Remain_Flag&0xF0;
						if (key_buf && (!GetTimeCount(dispPaymentTime,FLASH_TIME)))
							{
							displayCharTimeLen(DISP_REMAIN_DATA,1,0);
							dispCharFlag[0].byte=0;
							dispPaymentTime=GetNowTime();
							}
					}
					}
				}
			}
		return 0;
	}
	
	
	
	
	last_time=GetNowTime();
 	
	if(last_time-start_time<30)	/*"去抖动时间30ms"*/
	{
		scan_time=GetNowTime();
		//if(IC_FLAG.bit.b0!=1)
		//{
		//	if((flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
	    //	    {
		//	    	Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
		//	    	show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
		//	    	flash_time=GetNowTime();
	    //	    }       
	   	//}
	        return 1;	
	}
	BackLight_Ctrl(FIX_TIME_LIGHT_MODE,Meter_Parameter.parameter2.ShowNoKeyRetTime ,0,KEYDOWN_EVENT);///king chen add 130304
       
//	if (last_time-start_time>5000)	/*"按键按下时间。大于5s"*/
//	{
//		Show_Char_Main(63,1);	
//	}

    PowerOn_FullScreen_TimeDetection();
	key_buf=temp_key_val.key_value.byte;	


	

	if(scankey(key_buf)!=0x50)//||((temp_key_val.key_value.byte==0xf0)&&(temp_key_val.time<2)))
	{
		key_buf=scankey(key_buf);
		//if (key_buf&0x80)								//payment	/*"铅封按下BIT7为0"*/
		//	{
			Disp_Char_Clear();
		//	}
		/*" 1:内置负荷开关,采用按(上翻或下翻)键超过3秒进行合闸"*/	//payment
		if ((!GetTimeCount(start_time,2300)))
			{
			if ((!SWITCH_ALLOW_CLOSE_DEFINE)
			&& (!SWITCH_PREPARE_STATE_DEFINE)
			&& SWITCH_FACT_DEFINE)
				SWITCH_ALLOW_CLOSE_DEFINE=1;
			Card_Alarm_Switch();	//XN
			//Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
			//		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
			}
		Button_Alarm_Switch();				/*"在30ms防抖后，再执行按键解除功能"*/
		if(GetNowTime()-scan_time>2)
		{
			scan_time=GetNowTime();
			if(key_buf!=temp_key_val.key_value.byte)
			{
				temp_key_val.key_value.byte=key_buf;
				temp_key_val.time=1;
			}
			else
			{
				temp_key_val.time++;
				if(temp_key_val.time>3)
				{
					real_key_val.key_value.byte=temp_key_val.key_value.byte;	
					real_key_val.time=temp_key_val.time;
				}
			}
		}
//		if(IC_FLAG.bit.b0!=1)
//		{
		if (((key_buf&0x50)!=0x50) && (Pre_Static_Display_Remain()==0))		//payment	/*"铅封按下BIT7为0"*/
		{
			if((!Abnormal_Show_Mode.byte)&&(flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
	    	    {
			        Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
			        show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
			        flash_time=GetNowTime();
	    	    }
	    	    }
//	    }
	   if(last_time-start_time>120000)	/*"按键按下时间。大于5s"*/
		 {
			  key_flag.bit.b0=0;
		 }
		 return 2;	
	}
	else
	{		
		while(GetNowTime()-scan_time<5);
		if(scankey(key_buf)!=0x50)
		{
//			if(IC_FLAG.bit.b0!=1)
//			{
				if((!Abnormal_Show_Mode.byte) && (flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
	    	    {
			        Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
			        show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
			        flash_time=GetNowTime();
	    	    }
//	    	}
	    	return 2;	
		}
			
	}
	
	ir_kupic=0;
	kupic=1;	//set ipl
	
	key_flag.bit.b0=0;


	if(real_key_val.time<3)
	{
//		if(IC_FLAG.bit.b0!=1)
//		{ 	       
	   if((!Abnormal_Show_Mode.byte) && (flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
	   {
				Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
				show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
				flash_time=GetNowTime();
	   }
//	    }
	   return 1;
	}
	
	if(Fail_abnormal.byte && key_jump_flag==0)
	{
		key_jump_flag=1;
		key_flag.bit.b2=0;
		Key_Initialize(0);
		return 2;
	}
	
	loc_time=last_time-start_time;
	//key_flag.bit.b0=0;
	key_buf=real_key_val.key_value.byte;	
	/*
	switch(key_buf)
	{
		case 0xD0:	//11010000
			if(On_Key_Click)
				On_Key_Click(2,loc_time);
			break;
		case 0x70:  //01110000
			if(On_Key_Click)
				On_Key_Click(4,loc_time);
			break;
		case 0xB0:	//10110000
			if(On_Key_Click)
				On_Key_Click(3,loc_time);
			break;
		case 0xE0:	//11100000
			if(On_Key_Click)
				On_Key_Click(1,loc_time);
			
			break;
		case 0xA0:	//10010000
			if(On_Key_Click)
				On_Key_Click(5,loc_time);
			break;
	}
	*///modify by zlp
	switch(key_buf)
	{
		case 0x10:	//10110000
			key_buf=3;
			break;
		case 0x40:	//11100000
			key_buf=1;
			break;
		case 0x00:	//10010000
			key_buf=5;
			break;
	}

	if(On_Key_Click)
		On_Key_Click(key_buf,loc_time);
	if((!Abnormal_Show_Mode.bit.b2) && key_flag.bit.b2==1/*&&IC_FLAG.bit.b0!=1*/)
	{
		Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
		show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
		flash_time=GetNowTime();
	}
	return 3;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char scankey(char key_buf)
{
	return p10&0x50;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//key even for Cyc show
/*"A套显示按键响应事件"*/
void On_KeyClick_For_A_mode_show(char keyval,long time)
{
	
	char *p_temp;
	cursor_byte=0xf;
	switch	(keyval)
	{
		case 1:
		case 3:
	       /*if(time<3000)
		{
		       if(cyc_show_num>=Meter_Parameter.DisplayNumber-1)
			      cyc_show_num=0;	
		       else
			     cyc_show_num++;
						
		        WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE1))),
					  (unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),
						WriteWhitchEeprom[0],1);
				            
			   WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+100*5+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE2))),
					    (unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),
						 WriteWhitchEeprom[0],1);*/
				               
			  /*  if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
			    {
				   show_mode=0;
				    User_Defind_Table1.default_code&=0x00ffffff;
			     }
			     else
			     {
				    show_mode=1; */
			//	     leaf_flag=User_Defind_Table1.flag;
			    //  }
   
			//	move_showcode();
			//	key_flag.bit.b2=1;
				//key_flag.bit.b4=0;
		     //}			
		    // else if(time>5000)
		     //{
		     if(Event_abnormal.byte)
		     	{
		     		Event_show_cnt=0;
		     		Key_Initialize(On_KeyClick_For_Event_Abnomal_show);
		     	}
			else
			{
						SHOW_ABC_SEG(B_SEG);
			      //Show_flag.bit.A_S=0;
			      //Show_flag.bit.B_S=1;
			      //Show_flag.bit.C_S=0;				
			      cyc_show_num=0;
			      key_flag.bit.b2=1;
			      Key_Initialize(On_KeyClick_For_B_mode_show);
			}
				//WRLC256(CYCLEDISPLAYTABLE_B_ROM,
				//		(unsigned char*)&User_Defind_Table,
				//		sizeof(struct SHOW_CODE_TABLE),
				//		WriteWhitchEeprom[0],
				//		1);
				//
				//show_code=/*Meter_Parameter.*/User_Defind_Table.default_code;
				//user_defind_code=/*Meter_Parameter.*/User_Defind_Table.user_code;
				//user_defind_code_len=/*Meter_Parameter.*/User_Defind_Table.user_code_len;
				
			//}
			//else
			//{
			//}
		break;	
			
		case 2:
			
			if(time>5000)
			{
				//Show_flag.bit.A_S=0;
				//Show_flag.bit.B_S=0;
				//Show_flag.bit.C_S=1;
				SHOW_ABC_SEG(C_SEG);
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
	
				Key_Initialize(On_KeyClick_For_C1_mode_show);	
			
		/*		Show_flag.bit.A_S=0;
				Show_flag.bit.B_S=0;
				Show_flag.bit.C_S=1;
				//cursor_byte=0x000f0000;
				//show_code=0x00000000;
				//user_defind_code_len=0;
	
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
				Key_Initialize(On_KeyClick_For_C_mode_show);	*/
				
			}
			else 
			{
				
				//ClearDemandCommAndKey(1);
				
			}
		break;
		//case 3:
			/*if(time<3000)
			{
				if(cyc_show_num==0)
					cyc_show_num=Meter_Parameter.DisplayNumber-1;	
				else
					cyc_show_num--;
	
				WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE1))),
					    (unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),
						WriteWhitchEeprom[0],1);
						     
				WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+100*5+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE2))),
					    (unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),
						WriteWhitchEeprom[0],1);*/
						     		     
				/*if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
				{
					show_mode=0;
					User_Defind_Table1.default_code&=0x00ffffff;
				}
				else
				{
					show_mode=1; */
			//		leaf_flag=User_Defind_Table1.flag;
				//}
			     
			//	move_showcode();		
			//	key_flag.bit.b2=1;
				//key_flag.bit.b4=0;
				
			//}			
			//else if(time>5000)
			//{
			//	Show_flag.bit.A_S=0;
			//	Show_flag.bit.B_S=1;
			//	Show_flag.bit.C_S=0;				
			//	cyc_show_num=0;
			//	key_flag.bit.b2=1;
			//	Key_Initialize(On_KeyClick_For_B_mode_show);  /*"切换到B套显示"*/
				
				//WRLC256(CYCLEDISPLAYTABLE_B_ROM,
				//		(unsigned char*)&User_Defind_Table,
				//		sizeof(struct SHOW_CODE_TABLE),
				//		WriteWhitchEeprom[0],
				//		1);
				//
				//show_code=/*Meter_Parameter.*/User_Defind_Table.default_code;
				//user_defind_code=/*Meter_Parameter.*/User_Defind_Table.user_code;
				//user_defind_code_len=/*Meter_Parameter.*/User_Defind_Table.user_code_len;
			//}
			//else
			//{
			//}
		//break;				
		case 5:
			//if(time>=3000)
			//{
			//	ClearDemandCommAndKey(1,0);				
			//}
		break;	
	}
	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//key even for key show
/*"B套显示按键响应事件"*/
void On_KeyClick_For_B_mode_show(char keyval,long time)
{
	char *p_temp;
	cursor_byte=0xf;
	if(Meter_Parameter.parameter1.MeterMode[1].bit.b6)
	{
		if(keyval==1)
			keyval=3;
		else if(keyval==3)
			keyval=1;
	}
	switch	(keyval)
	{
		case 1:
			//if(time<3000)
			if(Event_abnormal.byte && cyc_show_num==Meter_Parameter.parameter1.KeyDisplayNumber-1)//lfy 090927
			{
				Event_show_cnt=0;
				Key_Initialize(On_KeyClick_For_Event_Abnomal_show);
			}
			else
			{
			        if(cyc_show_num>=Meter_Parameter.parameter1.KeyDisplayNumber-1)
					  cyc_show_num=0;	
				 else
					  cyc_show_num++;
						
				
				LCDREAD(ADDROF_B_R0M,cyc_show_num);
			
				 move_showcode();
				
				 key_flag.bit.b2=1;
				//key_flag.bit.b4=0;
				
			}			
			//else if(time>5000)
			//{
			//	Show_flag.bit.A_S=1;
			//	Show_flag.bit.B_S=0;
			//	Show_flag.bit.C_S=0;				
			//	cyc_show_num=0;
			//	key_flag.bit.b2=1;
			//	Key_Initialize(On_KeyClick_For_A_mode_show); /*"切换到A套显示"*/
				
				//WRLC256(CYCLEDISPLAYTABLE_A_ROM,
				//		(unsigned char*)&User_Defind_Table,
				//		sizeof(struct SHOW_CODE_TABLE),
				//		WriteWhitchEeprom[0],
				//		1);
				//
				//show_code=/*Meter_Parameter.*/User_Defind_Table.default_code;
				//user_defind_code=/*Meter_Parameter.*/User_Defind_Table.user_code;
				//user_defind_code_len=/*Meter_Parameter.*/User_Defind_Table.user_code_len;
				
			//}
			//else
			//{
			//}
			break;	
			
	  	case 2:
			
			if(time>5000)
			{
				//Show_flag.bit.A_S=0;
				//Show_flag.bit.B_S=0;
				//Show_flag.bit.C_S=1;
				SHOW_ABC_SEG(C_SEG);
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
	
				Key_Initialize(On_KeyClick_For_C1_mode_show);	
			
			/*	Show_flag.bit.A_S=0;
				Show_flag.bit.B_S=0;
				Show_flag.bit.C_S=1;
				//cursor_byte=0x000f0000;
				//show_code=0x00000000;
				//user_defind_code_len=0;
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
			
				Key_Initialize(On_KeyClick_For_C_mode_show);	*/
				
			}
			else
			{
				
				//ClearDemandCommAndKey(1);
				
			}
			
			
			break;
		  case 3:
			//if(time<3000)
			if(Event_abnormal.byte && cyc_show_num==0)//lfy 090927
			{
				Event_show_cnt=7;
				Key_Initialize(On_KeyClick_For_Event_Abnomal_show);
			}
			else
			{
                             if(cyc_show_num==0)
					  cyc_show_num=Meter_Parameter.parameter1.KeyDisplayNumber-1;	
				 else
					  cyc_show_num--;
						
				
				  LCDREAD(ADDROF_B_R0M,cyc_show_num);

				
				  move_showcode();
						
				  key_flag.bit.b2=1;
				  //key_flag.bit.b4=0;
				
			}			
			//else if(time>5000)
			//{
			//	Show_flag.bit.A_S=1;
			//	Show_flag.bit.B_S=0;
			//	Show_flag.bit.C_S=0;				
			//	cyc_show_num=0;
			//	key_flag.bit.b2=1;
			//	Key_Initialize(On_KeyClick_For_A_mode_show);  /*"切换到A套显示"*/
				
				//WRLC256(CYCLEDISPLAYTABLE_A_ROM,
				//		(unsigned char*)&User_Defind_Table,
				//		sizeof(struct SHOW_CODE_TABLE),
				//		WriteWhitchEeprom[0],
				//		1);
				//
				//show_code=/*Meter_Parameter.*/User_Defind_Table.default_code;
				//user_defind_code=/*Meter_Parameter.*/User_Defind_Table.user_code;
				//user_defind_code_len=/*Meter_Parameter.*/User_Defind_Table.user_code_len;
			//}
			//else
			//{
			//}
			break;				
		  case 5:			
		 	//if(time>=3000)
			//{
			//	ClearDemandCommAndKey(1,0);				
			//}
			break;	
	}	

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//key even for key show
/*"C套显示按键响应事件"*/
/*void On_KeyClick_For_C_mode_show(char keyval,long time)
{
	long l_temp,l_temp_1;
	switch	(keyval)
	{
		  case 1:
			l_temp=show_code&cursor_byte;
			l_temp_1=show_code&(~cursor_byte);
			l_temp=(l_temp+(0x00111111&cursor_byte))&cursor_byte;			
			if(l_temp>(0x0099C999&cursor_byte))
				show_code=l_temp_1;
			else
				show_code=l_temp_1|l_temp;			
//			if(Show_flag.bit.keystoke==0)
//			{	
//				if((show_code&0x000fffff)>=0x00090000)
//					show_code&=0x0000ffff;
//				else if((show_code&0x000fffff)>0x00080009)
//				{	
//					show_code=(show_code&0x00f00000)|0x00080000;
//					cursor_byte=0x0000000f;
//				}
//			}
			//else
			//{
			//	if(show_code<0x00800000)
			//		show_code=0x00800000;	
			//}					
			break;
		  case 2:
			if(time<1000)
			{
				if(cursor_byte>0xf)
					cursor_byte/=0x10;
				else
					cursor_byte=0x00f00000;
			}
						
			if(time>5000)
			{
				Show_flag.bit.A_S=0;
				Show_flag.bit.B_S=0;
				Show_flag.bit.C_S=1;
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
	
				Key_Initialize(On_KeyClick_For_C1_mode_show);	
			}
			else
			{
			}			
			break;	
		  case 3:
			l_temp=show_code&cursor_byte;
			l_temp_1=show_code&(~cursor_byte);
			l_temp=(l_temp-(0x00111111&cursor_byte))&cursor_byte;
			if(l_temp>(0x0099C999&cursor_byte))
				show_code=l_temp_1|(0x0099C999&cursor_byte);
			else
				show_code=l_temp_1|l_temp;			
				
//			if(Show_flag.bit.keystoke==0)
//			{	
//				if((show_code&0x000fffff)>=0x00090000)
//					show_code=0x00080000;
//				else if((show_code&0x000fffff)>0x00080009)
//				{	
//					show_code=(show_code&0x00f00000)|0x00080000;
//					cursor_byte=0x0000000f;
//				}	
//			}
			break;		
				
		case 4:
			if(time>5000)
			{
				ClearDemandCommAndKey(1,0);				
			}
			break;	
		case 5:
			if(cursor_byte<0x00f00000)
				cursor_byte*=0x10;
			else
				cursor_byte=0x0000000f;					
			break;				
	}
}*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//key even for new key show
void On_KeyClick_For_C1_mode_show(char keyval,long time)
{
	unsigned long l_temp,l_temp_1;
	switch	(keyval)
	{
		  case 1:
			l_temp=show_code&cursor_byte;
			l_temp_1=show_code&(~cursor_byte);
		      if(cursor_byte==0x0000000f)
		       {
                           if(ret_flag!=0)
			           leaf_flag++;
			      else
		             {
                                leaf_flag=0;
			           l_temp=(l_temp+(0x11111111&cursor_byte))&cursor_byte;		
			      }
		        }
		        else
		        {
		              l_temp=(l_temp+(0x11111111&cursor_byte))&cursor_byte;
			       leaf_flag=0;
			       ret_flag=0;
		         }
				   
		         if(l_temp>(0xFFFFFFFF&cursor_byte))
			      show_code=l_temp_1;
		         else
			      show_code=l_temp_1|l_temp;	
		  break;
		  case 2:
			if(time<1000)
			{
				if(cursor_byte>0xf)
					cursor_byte/=0x10;
				else
					cursor_byte=0xf0000000;
			}			
			else if(time>5000)
			{
				//Show_flag.bit.A_S=1;
				//Show_flag.bit.B_S=0;
				//Show_flag.bit.C_S=0;
				SHOW_ABC_SEG(A_SEG);
				key_flag.bit.b2=0;
				cyc_show_num=0;
				Key_Initialize(On_KeyClick_For_A_mode_show);
			}
			else
			{
			}			
			break;	
		  case 3:
			leaf_flag=0;
			ret_flag=0;
			l_temp=show_code&cursor_byte;
			l_temp_1=show_code&(~cursor_byte);
			l_temp=(l_temp-(0x11111111&cursor_byte))&cursor_byte;
			if(l_temp>(0xFFFFFFFF&cursor_byte))
				  show_code=l_temp_1|(0xFFFFFFFF&cursor_byte);
			else
				  show_code=l_temp_1|l_temp;			
			break;		
				
		  case 5:
			//if(time>=3000)
			//{
			//	ClearDemandCommAndKey(1,0);				
			//}
			break;	
			
		  case 6:                                      
			if(cursor_byte<0xf0000000)
				cursor_byte*=0x10;
			else
				cursor_byte=0x0000000f;					
			break;				
	}
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//key even for Drop show
void On_KeyClick_For_Dropshow(char keyval,long time)
{
	
	char *p_temp;
	char temp_i;
	long l_temp,bit_temp,l_temp_1;
	int *ip_temp;
	
	switch	(keyval)
	{
		case 1:
			/*if(time<3000)
			{
				if(cyc_show_num>=Meter_Parameter.DisplayNumber+Meter_Parameter.KeyDisplayNumber-1)
					cyc_show_num=0;	
				else
					cyc_show_num++;
						
				if(cyc_show_num<Meter_Parameter.DisplayNumber)
				{
					WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE1))),
							   (unsigned char*)&User_Defind_Table1,	sizeof(struct SHOW_CODE_TABLE1),
							    WriteWhitchEeprom[0],1);
							
					WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+100*5+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE2))),
							   (unsigned char*)&User_Defind_Table2,	sizeof(struct SHOW_CODE_TABLE2),
							    WriteWhitchEeprom[0],1);
					
					Show_flag.bit.A_S=1;
					Show_flag.bit.B_S=0;
					Show_flag.bit.C_S=0;*/
				    /*  if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
				      {
                                        show_mode=0;
					     User_Defind_Table1.default_code&=0x00ffffff;
				      }
				      else
		                    {
			                  show_mode=1; */
			         //          leaf_flag=User_Defind_Table1.flag;
		                    // }
				//}
				/*else
				{
					WRLC256(CYCLEDISPLAYTABLE_B_ROM+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE1))),
							(unsigned char*)&User_Defind_Table1,	sizeof(struct SHOW_CODE_TABLE1),	WriteWhitchEeprom[0],1);
							
					WRLC256(CYCLEDISPLAYTABLE_B_ROM+99*5+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE2))),
							(unsigned char*)&User_Defind_Table2,	sizeof(struct SHOW_CODE_TABLE2),	WriteWhitchEeprom[0],1);

					Show_flag.bit.A_S=0;
					Show_flag.bit.B_S=1;
					Show_flag.bit.C_S=0;*/
			             /* if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
				       {
                                         show_mode=0;
					      User_Defind_Table1.default_code&=0x00ffffff;
				        }
				        else
		                      {
			                    show_mode=1; */
			           //         leaf_flag=User_Defind_Table1.flag;
		                     // }
				//}
				
				//move_showcode();
				//key_flag.bit.b2=1;
				
			//}			
			//else if(time>5000)
			//{
				/*p_temp=(char *)&show_code;		
		
				if((*(p_temp+3)-0xa)<2)
					show_code=Meter_Parameter.CycleDisplayTable[(*(p_temp+3)-0x9)*10];
				else
					show_code=Meter_Parameter.CycleDisplayTable[0];
				cyc_show_time=GetNowTime();*/
			//}
			//else
			//{
			//}
			//break;	
			
		 // case 2:
			
		//	break;
		  case 3:
			key_flag.bit.b2=1;
			show_code=0x00000000;	/*"将==修改为=，对程序执行没有影响"*/
			Drop_Key_Initialize(On_KeyClick_For_B_mode_show,1);
			/*if(time<3000)
			{
				if(cyc_show_num==0)
					cyc_show_num=Meter_Parameter.DisplayNumber+Meter_Parameter.KeyDisplayNumber-1;	
				else
					cyc_show_num--;
						
				
				if(cyc_show_num<Meter_Parameter.DisplayNumber)
				{
					WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE1))),
						(unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),
							WriteWhitchEeprom[0],1);
							
					WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+100*5+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE2))),
						(unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),
							 WriteWhitchEeprom[0],1);	
							 
					Show_flag.bit.A_S=1;
					Show_flag.bit.B_S=0;
					Show_flag.bit.C_S=0;*/
				     /*  if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
				       {
                                        show_mode=0;
					     User_Defind_Table1.default_code&=0x00ffffff;
				       }
				       else
		                     {
			                   show_mode=1; */
			       //            leaf_flag=User_Defind_Table1.flag;
		                    // }
				//}
				/*else
				{
					WRLC256(CYCLEDISPLAYTABLE_B_ROM+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE1))),
							   (unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),WriteWhitchEeprom[0],1);
							
					WRLC256(CYCLEDISPLAYTABLE_B_ROM+99*5+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE2))),
							   (unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),WriteWhitchEeprom[0],1);
							   
					Show_flag.bit.A_S=0;
					Show_flag.bit.B_S=1;
					Show_flag.bit.C_S=0;*/
				   /*   if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
				      {
                                       show_mode=0;
					    User_Defind_Table1.default_code&=0x00ffffff;
				     }
				     else
		                   {
			                 show_mode=1; */
			          //       leaf_flag=User_Defind_Table1.flag;
		                  // }
				//}
				
				//move_showcode();
				//key_flag.bit.b2=1;
			//}			
			//else if(time>5000)
			//{
				/*p_temp=(char *)&show_code;		
		
				if((*(p_temp+3)-0xa)>0)
					show_code=Meter_Parameter.CycleDisplayTable[(*(p_temp+3)-0xb)*10];
				else
					show_code=Meter_Parameter.CycleDisplayTable[20];
				cyc_show_time=GetNowTime();*/
			//}
			//else
			//{
			//}
			//break;				
		  case 4:
			break;	
	}
	
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void key_show_no_key_down(void)
{
	int i_cursor_byte;
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	unsigned long temp_time;
	
	char *p_temp;
	char temp_i;
	long l_temp,bit_temp;
	int *ip_temp;
	
	temp_time=GetNowTime();
	//if(Show_flag.bit.A_S==1)
	//{		
	//	if(temp_time-last_time>Meter_Parameter.CycleDisplayTime*1000L*2L)  //mw modified 080226
	//	{
			//no key click exit A key show
	//		key_flag.bit.b2=0;			
	//		key_jump_flag=0;
	//		if(cyc_show_num>=Meter_Parameter.DisplayNumber-1)
	//			cyc_show_num=0;	
	//		else
	//			cyc_show_num++;
					
			
	//		WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE1))),
	//				(unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),
	//				WriteWhitchEeprom[0],1);
					
	//		WRLC256(CYCLEDISPLAYTABLE_A_SCREEN+100*5+(cyc_show_num*(sizeof(struct SHOW_CODE_TABLE2))),
	//				(unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),
	//				WriteWhitchEeprom[0],1);
		
			/* if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
		         {
                               show_mode=0;
				  User_Defind_Table1.default_code&=0x00ffffff;
			 }
			 else
		        {
			        show_mode=1; */
	//		        leaf_flag=User_Defind_Table1.flag;
		         // }
	//		 move_showcode();
				
	//		 cyc_show_time=GetNowTime();
	//	}
		
	//}
	//else if(Show_flag.bit.B_S==1)
	if(/*Show_flag.bit.B_S==1||*/Abnormal_Show_Mode.bit.b2)
	{
		if(temp_time-last_time>Meter_Parameter.parameter2.ShowNoKeyRetTime*1000L)  ///king chen modify 130304
		{
			//no key click exit B key show or exit Event abnormal show
			key_flag.bit.b2=0;
			key_jump_flag=0;
			Show_Initialize(2);
			Key_Initialize(0);			
			cyc_show_time=GetNowTime();
		}
		else
		{
			if((flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
			{
				Refresh_Err_Show();
				flash_time=GetNowTime();
			}			
		}
		return;
	}	
	else
	{
		if(temp_time-last_time>Meter_Parameter.parameter2.ShowNoKeyRetTime*1000L)///king chen modify 130304
		{
			//no key click exit  C key show
			key_flag.bit.b2=0;
			key_jump_flag=0;
			Show_Initialize(2);
			Key_Initialize(0);			
			cyc_show_time=GetNowTime();
			
		}
	}
		
	if((flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
	{
		Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
		show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
		flash_time=GetNowTime();		
	}
	else if(((flash_time/(FLASH_TIME/2)))!=(temp_time/(FLASH_TIME/2)))
	{
		if(Show_flag.bit.C_S==1)
    	     {
    		   i_cursor_byte=check_cursor_byte(cursor_byte);    		
    		   cursor_flash(30-(i_cursor_byte-1)*2);		
    	     }
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int check_cursor_byte(unsigned long byte)
{
	int temp,logxy;
	byte/=0xf;
	logxy=0;
	for(temp=0;temp<8;temp++)
	{
		if(byte>0)
		{
			byte/=0x10;
			logxy++;	
		}		
	}
	return logxy;
		
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void cyc_show(void)
{
	//cyc_show_num;
	//cyc_show_time;
	
	unsigned long relative_time,refer_time;
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	//unsigned int mode_byte; 
	char *p_temp;
	char temp_i;
	long l_temp,bit_temp;
	int *ip_temp;
	
	//refer_time=GetNowTime()-last_time;
	//if(refer_time>10*60*1000)
	//{
	//	Show_flag.bit.A_S=1;
	//	Show_flag.bit.B_S=0;
	//	Show_flag.bit.C_S=0;
	//	key_flag.bit.b2=0;
	//	Key_Initialize(On_KeyClick_For_A_mode_show);
	//	
	//}
	
	
	if(Meter_Parameter.parameter1.CycleDisplayTime==0)
		Meter_Parameter.parameter1.CycleDisplayTime=SH_CYC_SHOW_TIME;	
	relative_time=GetNowTime()-cyc_show_time;
	refer_time=Meter_Parameter.parameter1.CycleDisplayTime*1000L;
	if(relative_time>=refer_time)/*"自动循环显示完最后一屏时显示事件故障代码"*/
	{
		if(Event_abnormal.byte && Abnormal_Show_Mode.bit.b1==0 && cyc_show_num>=Meter_Parameter.parameter1.DisplayNumber-1 )
		{
			Abnormal_Show_Mode.bit.b1=1;
			Event_show_cnt=0;
		}
		if(Event_show_cnt>7 && Abnormal_Show_Mode.bit.b1==1)
			Abnormal_Show_Mode.bit.b1=0;
	}
	if(Abnormal_Show_Mode.bit.b1)
	{
		if(relative_time>=refer_time)
		{
			Event_Abnormal_Cycle_Show();
			if(Event_show_cnt>7)/*"事件异常代码显示完毕后切换到正常自动循显"*/
				Abnormal_Show_Mode.bit.b1=0;
			else
				Event_show_cnt++;
		}
		else 
		{
			if((flash_time/FLASH_TIME)!=(relative_time/FLASH_TIME))
			{
				Refresh_Err_Show();
				flash_time=GetNowTime();
			}			
		}

		if(Abnormal_Show_Mode.bit.b1)
			return;
	}
	if(relative_time<refer_time)
	{
		if((flash_time/FLASH_TIME)!=(relative_time/FLASH_TIME))
		{
			Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
			show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
			flash_time=relative_time;
		}
	}
#if	_SHOW_BLANK_SRC	
	else if(relative_time<refer_time+CYC_SHOW_INTERVAL)
	{
		clear_show_lcd();
	}	
#endif
	else
	{     
	    if(cyc_show_num>=Meter_Parameter.parameter1.DisplayNumber-1)
		  {			
			   Show_Initialize(2);
			   cyc_show_num=0;	
		  }
		  else
			   cyc_show_num++;
	
		
		   LCDREAD(  ADDROF_ASCREEN,cyc_show_num);
		 
		  move_showcode();
		   SHOW_ABC_SEG(A_SEG);
		  //Show_flag.bit.A_S=1;
		 // Show_flag.bit.B_S=0;
		 // Show_flag.bit.C_S=0;	
		  cyc_show_time=GetNowTime();
	}
	
	
}

/*"低功耗用程序"*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char Drop_Key_Main(void)
{
	char key_buf;
	unsigned long loc_time,temp_time;
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	long l_temp,l_temp_1;
	
	char *p_temp;
	
	char TriffNumble_bak;
	
	//tr_show_wait(10000);
	
	//Cycledisp_A_eeaddr();
	
	if(key_flag.bit.b0==0)
	{
		if(key_flag.bit.b2==1)
		{
			if(Powerdown_TempTimeAdd>=last_time)
				temp_time=Powerdown_TempTimeAdd-last_time;
			else
				temp_time=0xffff+Powerdown_TempTimeAdd-last_time;
			
			if(temp_time>=2L*Meter_Parameter.parameter2.ShowNoKeyRetTime)
			{
				key_flag.bit.b2=0;
				key_flag.bit.b1=1;
				cyc_show_num=0;
				On_Key_Click=On_KeyClick_For_Dropshow;
                show_which_now=0x01;
			}
		}
		if(key_flag.bit.b2==0)
		{
				
			if(key_flag.bit.b1!=1)
	        {
			   if(cyc_show_num>=Meter_Parameter.parameter1.DisplayNumber/*+Meter_Parameter.KeyDisplayNumber*/-1)
			       cyc_show_num=0;	
			   else
			       cyc_show_num++;
			}
			else
			{
			   key_flag.bit.b1=0;
			}
					
			//if(cyc_show_num<Meter_Parameter.DisplayNumber)
			//{
				LCDREAD(  ADDROF_ASCREEN,cyc_show_num);
		   		SHOW_ABC_SEG(A_SEG);
			//}
			//else
			//{
			//	WRLC256(CYCLEDISPLAYTABLE_B_ROM+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE1))),
			//	(unsigned char*)&User_Defind_Table1,sizeof(struct SHOW_CODE_TABLE1),WriteWhitchEeprom[0],1);
				
			//	WRLC256(CYCLEDISPLAYTABLE_B_ROM+99*5+((cyc_show_num-Meter_Parameter.DisplayNumber)*(sizeof(struct SHOW_CODE_TABLE2))),
			//	(unsigned char*)&User_Defind_Table2,sizeof(struct SHOW_CODE_TABLE2),WriteWhitchEeprom[0],1);
						 
	                 /*    if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
			      {
	                        show_mode=0;
	                        User_Defind_Table1.default_code&=0x00ffffff;
			     }
			    else
			    {
				  show_mode=1; */
			//	 leaf_flag=User_Defind_Table1.flag;
			  // }
			//     Show_flag.bit.A_S=0;
			 //    Show_flag.bit.B_S=1;
			 //    Show_flag.bit.C_S=0;
			//}
			
					
			
			move_showcode();
		}
		
		pd_now_show_code=show_code;
	  pd_now_user_def_code=user_defind_code;
	  pd_now_user_def_len=user_defind_code_len;
	  pd_time_show_cnt=0;
	
		Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);		
		TriffNumble_bak=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble;
		Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=0;
		Show_flag.bit.I  = Show_flash_falg.bit.I  ;
		Show_flag.bit.II = Show_flash_falg.bit.II ;
		Show_flag.bit.III= Show_flash_falg.bit.III;
		Show_flag.bit.IV = Show_flash_falg.bit.IV ;	
		
		Show_flash_falg.bit.I  = 0;
		Show_flash_falg.bit.II = 0;
		Show_flash_falg.bit.III= 0;
		Show_flash_falg.bit.IV = 0;	
		show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
		Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=TriffNumble_bak;
		//lcd_special_cortrol(0x10);
	
		ir_kupic=0;
		kupic=3;	//set ipl	
		return 0;
	}
	
	
	
	
	//key_buf=scankey(key_buf);
	
	
	last_time=Powerdown_TempTimeAdd;
	key_flag.bit.b0=0;
	key_buf=temp_key_val.key_value.byte;
	//if(key_buf!=(p10&0xf0))
	//	return 1;
	
	loc_time=30;	
	switch(key_buf)
	{
		case 0x10:	/*"00010000 因为 10.7 10.5在低功耗下设为了输出口，0"*/
			if(On_Key_Click)
				On_Key_Click(3,loc_time);
			break;
		case 0x40:	/*"01000000 因为 10.7 10.5在低功耗下设为了输出口，0"*/
			if(On_Key_Click)
				On_Key_Click(1,loc_time);
			
			break;
	}
	
	pd_now_show_code=show_code;
	pd_now_user_def_code=user_defind_code;
	pd_now_user_def_len=user_defind_code_len;
	pd_time_show_cnt=0;
	
	Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
	TriffNumble_bak=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble;
	Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=0;
	Show_flag.bit.I  = Show_flash_falg.bit.I  ;
	Show_flag.bit.II = Show_flash_falg.bit.II ;
	Show_flag.bit.III= Show_flash_falg.bit.III;
	Show_flag.bit.IV = Show_flash_falg.bit.IV ;	
	Show_flash_falg.bit.I  = 0;
	Show_flash_falg.bit.II = 0;
	Show_flash_falg.bit.III= 0;
	Show_flash_falg.bit.IV = 0;	
	show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
	Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=TriffNumble_bak;
	//lcd_special_cortrol(0x10);
	
	ir_kupic=0;
	kupic=3;	//set ipl
	return 3;
}	

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Drop_Key_Initialize(TOn_Key_Click On_Click_Fun,unsigned char kind)
{
	union byte_def *p_temp;
	char i_temp;
	kupic=0;			/*"关闭按键中断"*/                        
	//pu25=1;		        /*"p10.4-p10.7 设为内部上拉"*/            
	pd10_4=0;	        //p10.4-p10.7 set this port is input port 
	//pd10_5=1;	        //p10.4-p10.7 set this port is output port 
	//p10_5=0;
	pd10_6=0;	        //p10.4-p10.7 set this port is input port 
	//pd10_7=1;	        //p10.4-p10.7 set this port is output port 
	//p10_7=0;
	tr_show_wait(2);    /*"延时避免一打开中断就进中断"*/          
	ir_kupic=0;		    /*"清按键中断请求"*/                      
	kupic=3;	        /*"打开按键中断，设中断级别是3级"*/       
	
	key_flag.bit.b0=0;
	key_flag.bit.b7=1;	/*"低功耗工作模式标志"*/
	//psc_7=0;  //del by trend for dubug 20041201
	
	
	//key_value.byte=0xff;
	CYCLEDISPLAYTABLE_A_SCREEN=CYCLEDISPLAYTABLE_A_ROM;//lfy changed 090927
	if(On_Click_Fun!=0)
		On_Key_Click=On_Click_Fun;
	else
		{
			On_Key_Click=On_KeyClick_For_Dropshow;
			key_flag.bit.b2=0;
			//start_time=GetNowTime();
//			show_code=0x00000000;//Meter_Parameter.CycleDisplayTable[0];
//			cyc_show_num=0;
			//Set_show_code_list();
		}
	//p8_0=1;
	tr_show_wait(10000);
	cyc_show_num=0;
	key_flag.bit.b1=1;
	
	if(On_Key_Click==On_KeyClick_For_Dropshow)
	{
		LCDREAD(  ADDROF_ASCREEN,cyc_show_num);
        show_which_now=0x01;
	}
	else if(On_Key_Click==On_KeyClick_For_B_mode_show)
	{
		 LCDREAD(  ADDROF_B_R0M,cyc_show_num);
         show_which_now=0x02;
	}
 	 //p8_0=0;
	 move_showcode();
	 //cyc_show_time=GetNowTime();
	
	for(i_temp=0;i_temp<13;i_temp++)
	{
		Show_flag.byte[i_temp]=0;	
		Show_flash_falg.byte[i_temp]=0;	
	}
//	Show_flag.bit.A_S=1;
	Lcd_Power_On();
	
	if(kind==0)
	  Show_Initialize(1);
	//cyc_show_num=0;
	cyc_show_time=GetNowTime()-Meter_Parameter.parameter1.CycleDisplayTime*1000l+50;
	lcd_special_cortrol(0x10);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void	Goto_Wait_Exit_Wait(void)				/*"进入睡眠,退出睡眠"*/
		{
			asm("FSET	I");
			//asm("FCLR	I");
			asm("WAIT");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			
		}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void	Prepare_for_Wait(void)				/*"睡眠准备－送完1屏显示数据以后进入睡眠，显示时间到以后唤醒，再显示下1屏"*/
		{
											/*"关闭远红外电源"*/
											/*"关闭内卡电源"*/
											/*"红外通讯串口处理"*/
											/*"内卡总线处理"*/
											/*"时钟总线处理"*/
											/*"显示总线处理"*/
			//HT_1623_DATA_DIRECTION=1;		/*"HT_1623 DATA的方向控制寄存器"*/
			//HT_1623_DATA=0;					/*"HT_1623 DATA的寄存器"*/
			//HT_1623_WR_DIRECTION=1;			/*"HT_1623 /WR的方向控制寄存器"*/
			//HT_1623_WR=0;					/*"HT_1623 /WR的寄存器"*/			
			//Switch_to_Subclock();			/*"切换到副晶振"*/     
			Switch_to_125KClock();  //mw modified 2010-05-03
			
		}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void	Prepare_for_Wakeup(unsigned char kind)			/*"唤醒准备"*/
		{
			prcr|=0x01;  //mw added 2010
			cm1|=0x20;
			
			prcr|=0x01;						//CM0 write enable
			
			cm0&=0xdf;						/*"打开主晶振"*/
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");	
			
			prcr|=0x01;  //mw added 2010
			cm0|=0x40;	//mw added 2010/*"主晶振8分频"*/			
			
			asm("nop");
			asm("nop");
			asm("nop");
											/*"打开远红外电源"*/
											/*"打开内卡电源"*/
			//PowerOn_PCF8576();				/*"打开LCD电源"*///2005.04.12
			prcr|=0x01;  //mw added 2010
			cm1&=0xfd;						/*"CM11=0,Main clock"*/
			prcr|=0x01;  //mw added 2010
			cm2&=0xfd;						/*"CM21=0,Main clock"*/
			prcr|=0x01;  //mw added 2010
			cm0&=0x7f;						
											

										
			prcr|=0x01;  //mw added 2010
			cm0&=0xef;	//mw added 2010/*"停止副晶振"*/
			prcr|=0x01;  //mw added 2010
			cm1&=0xef;	//mw added 2010/*"打开125K内部晶振"*/	

			
			prcr&=0xfe;						//CM0 write disable
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");			
			//HT1623_INIT_IN_POWERDOWN_MODE();		/*"低功耗情况下初始化HT1623"*///2005.04.12
			if(kind!=0)
			  PowerOn_PCF8576();	
			
			//Init_TB1();						/*"TB1初始化：timer mode,fc32,1秒"*///2005.04.12
		}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//long show_code_step(long code,char step)
//{
//	char *p_temp;
//	char temp_i;
//	long l_temp,bit_temp;
//	int *ip_temp;
//	code&=0x0f00000f;
//	
//	if(step==1)	
//	{
//		p_temp=(char *)&code;		
//		ip_temp=(int *)&l_temp;
//		*ip_temp=Meter_Parameter.CycleDisplaySwitch[*(p_temp+3)-0xa];
//		ip_temp++;
//		*ip_temp=Meter_Parameter.CycleDisplaySwitch[*(p_temp+3)-0xa];
//		bit_temp=0x1;
//		bit_temp<<=((*p_temp&0xf)+1);
//		for(temp_i=(*p_temp&0xf)+1;temp_i<32;temp_i++)
//		{
//			if((bit_temp&l_temp)!=0)
//			{
//				*p_temp=temp_i&0xf;	
//				break;
//			}
//			bit_temp<<=1;
//			if(bit_temp==0)
//				break;
//		}	
//	}
//	else if(step==0xff)
//	{
//		p_temp=(char *)&code;		
//		ip_temp=(int *)&l_temp;
//		*ip_temp=Meter_Parameter.CycleDisplaySwitch[*(p_temp+3)-0xa];
//		ip_temp++;
//		*ip_temp=Meter_Parameter.CycleDisplaySwitch[*(p_temp+3)-0xa];
//		bit_temp=0x1;
//		bit_temp<<=(((*p_temp&0xf)|0x10)-1);
//		for(temp_i=((*p_temp&0xf)|0x10)-1;temp_i>=0;temp_i--)
//		{
//			if((bit_temp&l_temp)!=0)
//			{
//				*p_temp=temp_i&0xf;	
//				break;
//			}
//			bit_temp>>=1;
//			if(bit_temp==0)
//				break;
//		}
//	}
//	
//	return code;
//}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void show_clear_char(void)
{	
    unsigned char show_ram[SHOW_RAM_NUM],i;
	
    for(i=0;i<SHOW_RAM_NUM;i++)
        show_ram[i]=0;
    show_ram[2]=0x10;
    show_ram[3]=0xd0;
    show_ram[6]=0x00;
    show_ram[7]=0xd0;
    show_ram[8]=0x10;
    show_ram[9]=0xf0;
    show_ram[10]=0x70;
    show_ram[11]=0x70;
    show_ram[12]=0x00;
    show_ram[13]=0x60;
    HT1623_SEND_DATA(0,(unsigned char *)&show_ram[0],SHOW_RAM_NUM);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void show_build_char(void)
{	
    unsigned char show_ram[SHOW_RAM_NUM],i;

    for(i=0;i<SHOW_RAM_NUM;i++)
         show_ram[i]=0;		
    show_ram[2]=0x40;		
    show_ram[3]=0xf0;
    show_ram[6]=0x60;
    show_ram[7]=0xd0;
    show_ram[8]=0x60;
    show_ram[9]=0x00;
    show_ram[10]=0x00;
    show_ram[11]=0xd0;
    show_ram[12]=0x60;
    show_ram[13]=0xe0;
    HT1623_SEND_DATA(0,(unsigned char *)&show_ram[0],SHOW_RAM_NUM);
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//char Drop_Cyc_Show(void)
//{
//	char ret;
//	unsigned long relative_time,refer_time;
//	
//	
//	relative_time=GetNowTime()-cyc_show_time;
//	
//	refer_time=Meter_Parameter.CycleDisplayTime*1000l;
//	
//	if(relative_time<refer_time)
//	{
////		Show_Main(Meter_Parameter.CycleDisplayTable[cyc_show_num],&drop_cyc_buffer[0][0],user_defind_code,user_defind_code_len);				
//		
//	}		
//	else if(relative_time<refer_time+CYC_SHOW_INTERVAL)
//	{
//		lcd_special_cortrol(0x11);
//		clear_show_lcd();
//		lcd_special_cortrol(0x10);	
//		
//	}		
//	else
//	{
//		
//		if(cyc_show_num<Meter_Parameter.DisplayNumber)
//		{
//			cyc_show_num++;	
//			
//		    lcd_special_cortrol(0x11);		
//		    show_on_lcd(&drop_cyc_buffer[0][0],0,33);
//		    lcd_special_cortrol(0x10);
//		    cyc_show_time=GetNowTime();
//		}
//		else
//		{
//			cyc_show_num=0;
//			lcd_special_cortrol(0x11);
//			clear_show_lcd();
//			lcd_special_cortrol(0x10);	
//			Lcd_Power_Off();		
//			return 1;
//		}
//	
//		
//	} 	
//	return 0;	
//}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Exit_Normal_Show(void)
{
	lcd_special_cortrol(0x01);
	Lcd_Power_Off();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Enter_Dorp_Show(void)
{
//	Lcd_Power_On();
//	Show_Initialize(1);
//	//cyc_show_num=0;
	cyc_show_time=GetNowTime()-Meter_Parameter.parameter1.CycleDisplayTime*1000l+50;
//	lcd_special_cortrol(0x10);
      if(pdmode3 != 0x33)
      	{
	Prepare_for_Wakeup(1);
      	}
	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"遥控显示用"*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char IR_Set_show_Main(void)
{
	
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];	

	if (IR_intNum>=25)		
	{
	    if((Ir_Code_List[IR_Buf[2]]!=0x11)&&(0==Meter_Parameter.parameter1.MeterMode[2].bit.b2))
	   {
		   ///Light_Back_Up_Flag=0xff;
		   ///Light_Back_Led();///
		   BackLight_Ctrl(FIX_TIME_LIGHT_MODE, 2L*Meter_Parameter.parameter1.DisplayNumber*Meter_Parameter.parameter1.CycleDisplayTime,0,IR_SET_EVENT);///king chen add 130305
	   }
		IR_intNum=0;
	}
	else if(!(GetTimeCount(IR_Click_last_Scan_Time, 150)))
	{
				IR_intNum=0;
	}
	
	if(IR_Ctrl_flag.bit.b1==1)	
	{
		if((IR_Buf[0]==~IR_Buf[1])&&(IR_Buf[2]==~IR_Buf[3]))
		{
		   if((Ir_Code_List[IR_Buf[2]]!=0x11)&&(1==Meter_Parameter.parameter1.MeterMode[2].bit.b2))
		   {
		   BackLight_Ctrl(FIX_TIME_LIGHT_MODE, 2L*Meter_Parameter.parameter1.DisplayNumber*Meter_Parameter.parameter1.CycleDisplayTime,0,IR_SET_EVENT);
		   }
			key_jump_flag=1;
			last_time=GetNowTime();
			if(IR_keydown(Ir_Code_List[IR_Buf[2]])==0)
			{
				if(!Abnormal_Show_Mode.byte)
                {
					if(Ir_Code_List[IR_Buf[2]]!=0x11)	/*"固定显示剩余电费时,遥控开关键不要切换到循显"*/
					{
						Disp_Char_Clear();		//payment
						Show_Main(show_code,&buffer[0][0],user_defind_code,user_defind_code_len);
						show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
					}
				    flash_time=GetNowTime();
				    last_Ir_time=flash_time;
				    cyc_show_time=flash_time;
				}
			}
			
			
		}
		else
		{
			IR_bit_num=0;
			IR_Ctrl_flag.bit.b0=0;
			IR_Ctrl_flag.bit.b1=0;	
		}
		IR_Ctrl_flag.bit.b1=0;	
		tb2s=0;
		ta4ic=0x02;
		ta4s=1;
		return 1;	
	}
	else
	{
		if((GetNowTime()-last_Ir_time>2500)
			&&(GetNowTime()-last_Ir_time<3500)
			&&(last_Ir_time!=0)
			&&(Show_flag.bit.C_S!=1))
		{
			fshow_flag=0;
			if((!Abnormal_Show_Mode.byte) && Ir_Set_User_Show_Code()==0)
			{
				if(Show_flag.bit.A_S==1)
				{
					LCDREAD( ADDROF_ASCREEN,cyc_show_num );
					cursor_byte=0xf;
				}
				else if(Show_flag.bit.B_S==1)	
				{	
					LCDREAD(  ADDROF_B_R0M ,cyc_show_num);
				  cursor_byte=0xf;
				}
				move_showcode();
				cyc_show_time=GetNowTime();	
			}					
			return 1;
		}		
		else		
			return 0;
	}
	

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char Ir_Set_User_Show_Code(void)
{
	int number;
	unsigned long temp;
	temp=0xf;
	for(number=1;number<user_defind_code_len;number++)
	{
		temp<<=4;
		temp|=0xf;
	}
	
	user_defind_code&=temp;
	if(Show_flag.bit.A_S==1)	
	{
		for(number=0;number<Meter_Parameter.parameter1.DisplayNumber;number++)
		{
			LCDREAD( ADDROF_ASCREEN,number );
			if((user_defind_code==(User_Defind_Table2.user_code&temp))&&(User_Defind_Table2.user_code_len==user_defind_code_len))
			{
				move_showcode();
				cyc_show_time=GetNowTime();	
				SHOW_ABC_SEG(A_SEG);
			//Show_flag.bit.A_S=1;
			//Show_flag.bit.B_S=0;
			//Show_flag.bit.C_S=0;
				cursor_byte=0xf;
				return 1;
			}
			
		}
	}
	else
	{
		for(number=0;number<Meter_Parameter.parameter1.KeyDisplayNumber;number++)
		{
			LCDREAD(  ADDROF_B_R0M ,number);
			if((user_defind_code==(User_Defind_Table2.user_code&temp))&&(User_Defind_Table2.user_code_len==user_defind_code_len))	
			{
				move_showcode();
				cyc_show_time=GetNowTime();	
				SHOW_ABC_SEG(B_SEG);
			//Show_flag.bit.A_S=0;
			//Show_flag.bit.B_S=1;
			//Show_flag.bit.C_S=0;
				cursor_byte=0xf;
				return 1;
			}
		}
	}
	return 0;	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void IR_interrupts(void)
{

	tb2s=0;
	IR_timer_counter=tb2;

	if (((0x7fff-IR_timer_counter)>300)&&((0x7fff-IR_timer_counter)<15000))		//2011-07-29 add
		{
		if (((0x7fff-IR_timer_counter)>1500)&&((0x7fff-IR_timer_counter)<15000))
			IR_intNum=1;
		else if (((0x7fff-IR_timer_counter)<1500)&&(IR_intNum))
			IR_intNum++;
		IR_Click_last_Scan_Time=GetNowTime();

		}


	if(IR_Ctrl_flag.bit.b0==1)
	{
	
		if((0x7fff-IR_timer_counter>325)&&(0x7fff-IR_timer_counter<375)) //2013.03.30 mw modified 
		//if((0x7fff-IR_timer_counter>287)&&(0x7fff-IR_timer_counter<412))  /*"1.12ms正负200微秒"*/
		{
			/*"0"*/
			if(IR_bit_num<32)
			{
				IR_Buf[IR_bit_num/8]&=~(0x01<<(IR_bit_num%8));
				IR_bit_num++;
			}
		}	
		else if((0x7fff-IR_timer_counter>675)&&(0x7fff-IR_timer_counter<725))  
		//else if((0x7fff-IR_timer_counter>637)&&(0x7fff-IR_timer_counter<762)) /*"2.24ms正负200微秒"*/
		{
			/*"1"*/
			if(IR_bit_num<32)
			{
				IR_Buf[IR_bit_num/8]|=(0x01<<(IR_bit_num%8));
				IR_bit_num++;
			}
		}	
		else
		{
			/*"出现错误，退出接收"*/
			IR_bit_num=0;
			IR_Ctrl_flag.bit.b0=0;
		}
		if(IR_bit_num>=32)		
		{
			IR_Ctrl_flag.bit.b1=1;
			/*"关定时中断"*/
		}
	}
	else 
	{
		
		if((0x7fff-IR_timer_counter>4200)&&(0x7fff-IR_timer_counter<4250))
		{
			/*"start"*/
			IR_bit_num=0;
			IR_Ctrl_flag.bit.b0=1;
			IR_Ctrl_flag.bit.b1=0;
			
			
			
		}
		else
		{
		}
	}
	if(IR_Ctrl_flag.bit.b1!=1)
	{
		tb2=0x7fff;
		tb2s=1;
		ta4=0;
		ta4s=1;
	}
	else
	{
		IR_Ctrl_flag.bit.b0=0;
		tb2=0x7fff;
		tb2s=0;	
		ta4s=0;
		ta4ic=0x00;
	}
	
		


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void IR_Timer(void)
{
 	/*"1us中断"*/
 	//if(IR_timer_counter<0xf00000)
 	//	IR_timer_counter++;
 	//if(IR_timer_counter>0xf000)
 	//{
 	//	IR_timer_counter=0;
 	//	/*"关定时中断"*/
 		tb2s=0;
 	//}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Init_IR_Ctrl(void)
{
	/*"初始化TB2为定时器，10us"*/
	tb2mr=0x80;/*计数源为F32*/
	tb2=0;
	//udf|=0x08;/*"加计数"*/
	tb2s=0;
	tb2ic=0x01;
	
	/*"初始化ta4为计数器，来一个下降沿就进中断"*/
	pd8_1=0;
	ta4mr=0X01;/**/
	ta4=0;
	ta4tgl=0;
	ta4tgh=0;	
	ta4ic=0x02;	
	ta4s=1;
	//ta4os=1;
	
	IR_Ctrl_flag.bit.b0=0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char IR_keydown(char keyval)
{
//	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	long temp_l;

	if(Abnormal_Show_Mode.bit.b0==1 && keyval<=0x18)/*"故障异常显示时退出故障异常，进入自动循环显示"*/
	{
		key_jump_flag=1;
		key_flag.bit.b2=0;
		Key_Initialize(0);
		return 2;
	}

	if(keyval>0xf)
		fshow_flag=0;

	if(keyval<=0xf)
	{
		if(Abnormal_Show_Mode.byte)/*"显示异常时不响应数字按键"*/
			return 1;
		if(Show_flag.bit.C_S==1)
		{
			temp_l=keyval*(cursor_byte/0xf);
			show_code&=~cursor_byte;
			show_code|=temp_l;
			user_defind_code_len=0;
			if(cursor_byte>0xf)
				cursor_byte>>=4;
			else
			{
				/* if(show_mode==0)
				    cursor_byte=0x00f00000;
				 else*/
				  	cursor_byte=0xf0000000;
			}	
		}
		else
		{
			fshow_flag=1;
			temp_l=keyval*0x00000001;			
			if(cursor_byte==0xf)
				user_defind_code=0xFFFFFFF0;
			else
				user_defind_code<<=4;
			user_defind_code&=0xffffffff;
			user_defind_code|=temp_l;
			user_defind_code_len=check_cursor_byte(cursor_byte);
			if(cursor_byte==0xf0000000)
				cursor_byte=0xf;				
			else
				cursor_byte<<=4;
		}
				
	}			
	else if(keyval==0x13)/*"下"*/
	{
		if(On_Key_Click)
			On_Key_Click(3,100);
				
	}
	else if(keyval==0x12) /*"上"*/
	{
		
		if(On_Key_Click)
			On_Key_Click(1,100);
		
	}
	else if(keyval==0x17)	/*"左"*/
	{
		//if(Show_flag.bit.A_S==1)
		//	On_KeyClick_For_A_mode_show(2,100);
		//else if(Show_flag.bit.B_S==1)
		//	On_KeyClick_For_B_mode_show(1,6000);
		//else if(Show_flag.bit.C_S==1)
		//	On_KeyClick_For_A_mode_show(1,6000);
		//else
		//	On_KeyClick_For_B_mode_show(1,6000);
              if(Show_flag.bit.C_S==1)
		{
			/* if(show_mode==0)
			    On_KeyClick_For_C_mode_show(5,100);
			 else */
			 	  On_KeyClick_For_C1_mode_show(6,100);
		}
		else
		{
			if(On_Key_Click)
			{
				On_Key_Click(2,6000);
			}
		}
			
	}	
	else if(keyval==0x18) /*"右"*/
	{
		//if(Show_flag.bit.A_S==1)
		//	On_KeyClick_For_A_mode_show(1,6000);
		//else if(Show_flag.bit.B_S==1)
		//	On_KeyClick_For_B_mode_show(2,100);
		//else if(Show_flag.bit.C_S==1)
		//	On_KeyClick_For_C_mode_show(2,100);
		//else
		//	On_KeyClick_For_B_mode_show(1,6000);
		if(Show_flag.bit.C_S!=1)
		{
			if(On_Key_Click)
			{
				On_Key_Click(2,6000);
			}
			//On_KeyClick_For_C_mode_show(2,6000);	
		}
	  else
		{
			if(On_Key_Click)
				On_Key_Click(2,100);
		}
		 	
		
	}
	else if(keyval==0x14)/*"轮显，进A"*/
	{
		 SHOW_ABC_SEG(A_SEG);
		// Show_flag.bit.A_S=1;
		//Show_flag.bit.B_S=0;
		//Show_flag.bit.C_S=0;	
		key_flag.bit.b2=0;
		cyc_show_num=0;
		Key_Initialize(On_KeyClick_For_A_mode_show); /*"切换到A套显示"*/

		//On_KeyClick_For_B_mode_show(1,6000);		
	}
	else if(keyval==0x15)/*"查询，进B"*/
	{
		On_KeyClick_For_A_mode_show(1,6000);
	}
	else if(keyval==0x11)/*"开关"*/
	{
		///if(p2_3==0)///king chen mark 130306
		///{		
          ///Light_Back_Up_Flag=0xff;
          ///Light_Back_Led();
		///}
		///else
			////p2_3=0;
	}
	else if(keyval==0x16)/*"."*/
		{
			O1ther_Meter_Parameter.OutputModel += 1;
			if(O1ther_Meter_Parameter.OutputModel > 2)
				O1ther_Meter_Parameter.OutputModel = 0;
				
		  Output_On_3_In_1_Terminal_Set(0);
		}
	
	else
	{
		return -1;
	}
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void move_showcode(void)
{
      show_code=/*Meter_Parameter.*/User_Defind_Table1.default_code;
      user_defind_code=/*Meter_Parameter.*/User_Defind_Table2.user_code;
      user_defind_code_len=/*Meter_Parameter.*/User_Defind_Table2.user_code_len;
	if(Show_flag.bit.C_S!=1)/*"AB套"*/
	{
	    	show_leaf_flag=0;
		if(show_code==0x88888888)/*"全屏显示时忽略用户代码"*/
		{
			user_defind_code=show_code;
			user_defind_code_len=8;
		}
	 	 if(user_defind_code_len==0)/*"未设定用户代码时显示C或C1套代码"*/
      		{
      			user_defind_code=show_code;
			/*if(show_mode==0)
				   user_defind_code_len=6;
			else 
			 {  */
			 	   show_leaf_flag=1;
				   user_defind_code_len=8;
			 // }
	 	   }
      	}
}


/*"---------------------------------------"*/
/*"           函数功能：显示Err-XX               "*/
/*"           输入：XX        lfy 090927                     "*/
/*"---------------------------------------"*/
void LCDREAD(unsigned char flag,unsigned char num)
{
    unsigned int addr1,addr2;
     if(flag==ADDROF_ASCREEN)
	{
	     addr1=CYCLEDISPLAYTABLE_A_SCREEN+(num*(sizeof(struct SHOW_CODE_TABLE1)));
	     addr2=CYCLEDISPLAYTABLE_A_SCREEN+99*5+(num*(sizeof(struct SHOW_CODE_TABLE2)));;
     	}
     if(flag==ADDROF_B_R0M)
     	{
     	    addr1=CYCLEDISPLAYTABLE_B_ROM+(num*(sizeof(struct SHOW_CODE_TABLE1)));			           
	    addr2=CYCLEDISPLAYTABLE_B_ROM+120*5+(num*(sizeof(struct SHOW_CODE_TABLE1)));	
     	}
      WRLC256(addr1,
			(unsigned char*)&User_Defind_Table1,	sizeof(struct SHOW_CODE_TABLE1),	0,1);
							
	WRLC256(addr2,
			(unsigned char*)&User_Defind_Table2,	sizeof(struct SHOW_CODE_TABLE2),	0,1);
	 /*if((User_Defind_Table1.default_code&0xff000000)==0xff000000)
	 {
                    show_mode=0;
		      User_Defind_Table1.default_code&=0x00ffffff;
	 }
	else
	{
		      show_mode=1; */
		      leaf_flag=User_Defind_Table1.flag;
	//}

}
/*"点亮显示方案 A,B,C"*/
//#define  A_SEG    0x01
//#define  B_SEG    0x02
//#define  C_SEG    0x04
void  SHOW_ABC_SEG(unsigned char SEGFLAG )
{
     if(SEGFLAG&A_SEG)
     {
          Show_flag.bit.A_S=1;/*"默认A套显示方案，点亮[A]"*/
          Show_flag.bit.B_S=0;
          Show_flag.bit.C_S=0;
     }
    if(SEGFLAG&B_SEG)
     {
          Show_flag.bit.A_S=0;/*"默认B套显示方案，点亮[B]"*/
          Show_flag.bit.B_S=1;
          Show_flag.bit.C_S=0;
     }	 
     if(SEGFLAG&C_SEG)
     {
          Show_flag.bit.A_S=0;/*"默认C套显示方案，点亮[C]"*/
          Show_flag.bit.B_S=0;
          Show_flag.bit.C_S=1;
     }
}
void Show_Err_Type(char type)
{
	unsigned char show_ram[SHOW_RAM_NUM],unc;
	char  show_data_buf[9];/*"1~9"*/
	for(unc=0;unc<SHOW_RAM_NUM;unc++)
		show_ram[unc]=0;
	show_data_buf[0]=0x13;
	show_data_buf[1]=0x13;
	show_data_buf[2]=0x0E;//E
	show_data_buf[3]=0x11;//r
	show_data_buf[4]=0x11;//r
	show_data_buf[5]=0x10;//-
	bcd_un_zip(&type, &show_data_buf[6], 1);
	show_data_buf[8]=0x13;
	conver_data0(&show_data_buf[0], show_ram, 0, 9);
	HT1623_SEND_DATA(0,(unsigned char *)&show_ram[0],SHOW_RAM_NUM);
}

/*"故障异常代码显示处理函数"*/
void Failure_Abnormal_Func(void)
{
	char unc;
	unsigned char temp;
	unsigned long temp_time,refer_time;
	temp_time=GetNowTime()-Fail_show_time;
	refer_time=Meter_Parameter.parameter1.CycleDisplayTime*1000l;
	temp=Fail_abnormal.byte;
	if((Fail_show_cnt==0)||(temp_time>=refer_time))
	{
		if(Fail_show_cnt==8)
			Fail_show_cnt=0;
		for(unc=Fail_show_cnt;unc<8;)
		{
			if(temp&(0x01<<unc))
				break;
			else
			{
				if(unc==7)
					unc=0;
				else
					unc++;
				continue;
			}
		}
		Fail_show_cnt=unc;
		Fail_show_time=GetNowTime();
		Show_Err_Type(Fail_show_cnt+1);
		Fail_show_cnt++;
	}
	else if(temp_time<refer_time)
	{
		if((flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
		{
			Refresh_Err_Show();
			flash_time=GetNowTime();
		}			
	}
}

/*"事件异常代码循环显示处理函数"*/
void Event_Abnormal_Cycle_Show(void)
{
	unsigned long temp_time,refer_time;
	Event_show_cnt=Search_Event_Abnormal(0);
	if(Event_show_cnt<8)
	{
		Show_Err_Type(Event_show_cnt+0x50);
		cyc_show_time=GetNowTime();
	}
}

/*"从当前位置开始搜索下一个异常代码，0-递增搜索；1-递减搜索"*/
signed char Search_Event_Abnormal(unsigned char method)
{
	signed char unc;
	unsigned char temp;
	temp=Event_abnormal.byte;
	if(method==0)
	{
		for(unc=Event_show_cnt;unc<8;unc++)
		{
			if(temp&(0x01<<unc))
				break;
			else
				continue;
		}
	}
	else
	{	
		for(unc=Event_show_cnt;unc>=0;unc--)
		{
			if(temp&(0x01<<unc))
				break;
			else
				continue;
		}
	}
	return unc;
}

void Refresh_FailAbnormalFlag(void)
{
	failabnormalshow.byte=0;

	failabnormalshow.bit.CtrCircleErr=SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE;	//payment
	if (ESAM_ERR_DEFINE)	// && MACRO_ESAM_FLAG)
		failabnormalshow.bit.EsamErr=1;
	else
		failabnormalshow.bit.EsamErr=0;
	failabnormalshow.bit.EepromInitErr=0;
	failabnormalshow.bit.ClockBatErr=Show_flag.bit.BATTERIES1;
	failabnormalshow.bit.ProgramErr=0;
	failabnormalshow.bit.MemoryErr=Meter_States.Err_Infor.bit.Eeprom_Err ;
	failabnormalshow.bit.ClockErr=Meter_States.Err_Infor.bit.Rtc_Err;
	
	if((Meter_Parameter.parameter1.LocalFunctionMode.bit.b1==1)||(O1ther_Meter_Parameter.WorkRoomState==0xff))
	  Fail_abnormal.byte=failabnormalshow.byte;
	else
	  Fail_abnormal.byte=0;
	
	if(!Fail_abnormal.byte)
		Abnormal_Show_Mode.bit.b0=0;	
}
void Refresh_EventAbnormalFlag(void)
{
	eventabnormalshow.byte=0;
	
	if((Event_Power_Net_Flag.bit.UpLoad_A)||(Event_Power_Net_Flag.bit.UpLoad_B)||(Event_Power_Net_Flag.bit.UpLoad_C))
		eventabnormalshow.bit.OverLoad=1;
	else
		eventabnormalshow.bit.OverLoad=0;

	eventabnormalshow.bit.CurrentImbalance=Event_Power_Net_Flag.bit.CurrFarImB;
	
	if((Event_Power_Net_Flag.bit.OverVoltage_A)||(Event_Power_Net_Flag.bit.OverVoltage_B)||(Event_Power_Net_Flag.bit.OverVoltage_C))
		eventabnormalshow.bit.OverVoltage=1;
	else
		eventabnormalshow.bit.OverVoltage=0;
	
	eventabnormalshow.bit.OverPowerFactor=Event_Power_Net_Flag.bit.OverFactor;
	
	if((Event_Power_Net_Flag.bit.OverPaADemand)||(Event_Power_Net_Flag.bit.OverNeADemand))
		eventabnormalshow.bit.OverActiveDemandAlarm=1;
	else
		eventabnormalshow.bit.OverActiveDemandAlarm=0;
	
	eventabnormalshow.bit.EnergyDirectChange=Err_Code.bit.ENERGY_DIRECT_CHANGE;
	
	if((Meter_Parameter.parameter1.LocalFunctionMode.bit.b1==1)||(O1ther_Meter_Parameter.WorkRoomState==0xff))
	  Event_abnormal.byte=eventabnormalshow.byte;
	else
	  Event_abnormal.byte=0;
	
}

/*"事件异常代码按键显示处理函数"*/
void On_KeyClick_For_Event_Abnomal_show(char keyval,long time)
{
	
	char *p_temp;
	cursor_byte=0xf;
	if(Meter_Parameter.parameter1.MeterMode[1].bit.b6)
	{
		if(keyval==1)
			keyval=3;
		else if(keyval==3)
			keyval=1;
	}
	switch(keyval)
	{
		case 1:
			Event_show_cnt++;
			if(Event_show_cnt<8)
				Event_show_cnt=Search_Event_Abnormal(0);
			if(Event_show_cnt<8)
				Show_Err_Type(Event_show_cnt+0x50);
			else
			{
				Show_flag.bit.A_S=0;
				Show_flag.bit.B_S=1;
				 Show_flag.bit.C_S=0;				
				 cyc_show_num=0;
				key_flag.bit.b2=1;
				Key_Initialize(On_KeyClick_For_B_mode_show);
			}
			break;
		case 3:
			Event_show_cnt--;
			if(Event_show_cnt>=0)
				Event_show_cnt=Search_Event_Abnormal(1);
			if(Event_show_cnt>=0)
				Show_Err_Type(Event_show_cnt+0x50);
			else
			{
				Show_flag.bit.A_S=0;
				Show_flag.bit.B_S=1;
				 Show_flag.bit.C_S=0;				
				 cyc_show_num=Meter_Parameter.parameter1.KeyDisplayNumber-1;
				key_flag.bit.b2=1;
				Key_Initialize(On_KeyClick_For_B_mode_show);
			}
			break;	
		case 2:
			if(time>5000)
			{
				SHOW_ABC_SEG(C_SEG);
				key_flag.bit.b2=1;
				key_flag.bit.b4=0;
				Key_Initialize(On_KeyClick_For_C1_mode_show);	
			}
			else
			{
				//ClearDemandCommAndKey(1);
			}
			break;
		case 4:
			break;
		case 5:
			//if(time>=3000)
			//{
			//	ClearDemandCommAndKey(1,0);				
			//}
			break;
	}
	
}

/*"============================================================"*/
/*"函数名：Check_Show_FlashData"*/
/*"用途：处理低功耗下FLASH数据函数"*/
/*"参数：Checkkind:  1:Cyc
                     2:key
                     ff:Cyc + key  "*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
char Check_Show_Flash_Data(unsigned char Checkkind,unsigned char Checkshownum,unsigned char storekind,unsigned char* idd)
{
	char ret,buffer[32];
    unsigned char flag,flag11;
    int  addr,unc,unj,cyc_show_num_sta,cyc_show_num_end;
    struct SHOW_CODE_TABLE1  User_Defind_Table_temp1;
    struct COM_SHOW_TABLE  Show_Powerdown_Data;
    union ID idtemp;

    if(IntoPowerDownFlag)
        return -1;
 
    cyc_show_num_sta=Checkshownum;
    cyc_show_num_end=Checkshownum+1;   

    if((Checkkind==0x01)||(Checkkind==0xff)||(Checkkind==0xf0))
    {
        if(Checkkind==0x01)
        {
            addr=Checkshownum*(sizeof(struct SHOW_CODE_TABLE1));
            for(unj=0;unj<5;unj++)
                Co.b[500+addr+unj]=*(idd+unj);
        }
        else
        {
            if(Meter_Parameter.parameter1.DisplayNumber>99)
                Meter_Parameter.parameter1.DisplayNumber=1;
            cyc_show_num_sta=0;
            cyc_show_num_end=Meter_Parameter.parameter1.DisplayNumber;   

            addr=CYCLEDISPLAYTABLE_A_ROM;
            WRLC256(addr,(unsigned char*)&Co.b[500],sizeof(struct SHOW_CODE_TABLE1)*cyc_show_num_end,0,1);            
        }
        for(unc=cyc_show_num_sta;unc<cyc_show_num_end;unc++)
        {   
            if(unc>=99)
                return -1;
            addr=unc*(sizeof(struct SHOW_CODE_TABLE1));
            User_Defind_Table_temp1=*((struct SHOW_CODE_TABLE1 *)&Co.b[500+addr]);
            idtemp.l=User_Defind_Table_temp1.default_code;
			/*"事件或者冻结才更新备份显示项目"*/
			if (idtemp.d[3]==0x03 || (idtemp.d[3]>=0x10 && idtemp.d[3]<=0x21) || idtemp.d[3]==0x05)
			{
				/*"---各类总数据\电压合格率\累计时间---"*/
				/*"03050000	全失压总次数，总累计时间"*/
				/*"0310**00	电压合格率统计数据"*/
				/*"03110000	掉电总次数"*/
				/*"0312**00	需量超限总次数"*/
				/*"033***00	编程\清零\校时\开盖总次数\恒定磁场干扰\电源异常 总次数"*/
				/*"1***0001	总次数"*/
				/*"1***0002	总累计时间"*/
				/*"10**0003	失压期间正向有功总电量"*/
				/*"10**0004	失压期间反向有功总电量"*/
				/*"2***0001	欠压总次数"*/
				/*"2***0002	欠压总累计时间"*/
			    flag=flag11=0;
		 		if (idtemp.d[3]==0x10)	/*"失压"*/
					flag=0xFF;
				if (idtemp.l==0x03300001||idtemp.l==0x03050001||idtemp.l==0x03300D01||idtemp.l==0x03300E01||idtemp.l==0x03110001	/*"最近一次事件:编程\恒定磁场干扰\开表\开端表\掉电"*/
					||idtemp.l==0x10000101||idtemp.l==0x10000201)	/*"最近1次失压发生时刻\最近1次失压结束时刻"*/
					flag11=0xFF;
				if ((idtemp.d[3]!=0x05&&idtemp.d[0]==0x00)							/*"总次数和电压合格率"*/
					||((idtemp.d[3]>=0x10 && idtemp.d[3]<=0x21)&&idtemp.d[1]==0x00)	/*"总次数和累计时间"*/
					||((flag==0xFF&&idtemp.d[0]==0x01)||flag11==0xFF))				/*"最近一次记录"*/
					continue;	/*"查找到的数据不在FALSH中,不用更新"*/
				
	            ret=TransferData_New(idtemp,&buffer[0],(unsigned int)User_Defind_Table_temp1.flag,
	                                  SHOWFORMAT,(unsigned char *)&Show_Powerdown_Data,0x03,0,0x03);
	          
	            if((ret!=0)&&(Show_ID_vatiy==0xff))//&&(flag11==0xff))
	            {
	               if((CompareBytes((unsigned char *)&Show_Powerdown_Cyc_Data[unc].showbuff[0],(unsigned char *)&buffer[0],ret)!=0)
	                    ||(CompareBytes((unsigned char *)&Show_Powerdown_Cyc_Data[unc].Powerdown_show_table,(unsigned char *)&Show_Powerdown_Data,3)!=0)
	                    ||(Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.falshDatalen!=ret)
	                    ||(Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.vatiryflag==0))
	                {
	                    Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.vatiryflag=1;
	                    Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.falshDatalen=ret;
	                    for(unj=0;unj<6;unj++)
	                        Show_Powerdown_Cyc_Data[unc].showbuff[unj]=buffer[unj];
	                    Show_Powerdown_Cyc_Data[unc].Powerdown_show_table=Show_Powerdown_Data;
	                    //flag=0xff;
						WRLC256(SHOW_POWERDOWN_CYC_DATA_ROM+unc*sizeof(struct Show_Powerdown_Data_Struct),(unsigned char*)&Show_Powerdown_Cyc_Data[unc],sizeof(struct Show_Powerdown_Data_Struct),0,0);
	                }
	            }
	            else
	            {
	                if(Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.vatiryflag==1)
	                {
	                    Show_Powerdown_Cyc_Data[unc].Show_FlashData_flag.vatiryflag=0;
	                    //flag=0xff;
	                }
	            }
	            FeedWatchdog();
			}
            CheckPowerDown();
        }
        //if((flag==0xff)&&(storekind==0xff))
        //{   
        //    if((Checkkind==0xff)||(Checkkind==0xf0))
        //        WRLC256(SHOW_POWERDOWN_CYC_DATA_ROM,(unsigned char*)&Show_Powerdown_Cyc_Data[0],cyc_show_num_end*sizeof(struct Show_Powerdown_Data_Struct),0,0);
        //    else
        //        WRLC256(SHOW_POWERDOWN_CYC_DATA_ROM+Checkshownum*sizeof(struct Show_Powerdown_Data_Struct),(unsigned char*)&Show_Powerdown_Cyc_Data[Checkshownum],sizeof(struct Show_Powerdown_Data_Struct),0,0);
        //    FeedWatchdog();
        //    CheckPowerDown();
        //}
    }

    if(Checkkind==0xf0)
        return 0;

    if((Checkkind==0x02)||(Checkkind==0xff)||(Checkkind==0x0f))
    {
        if(Checkkind==0x02)
        {
            addr=Checkshownum*(sizeof(struct SHOW_CODE_TABLE1));
            for(unj=0;unj<5;unj++)
                Co.b[500+addr+unj]=*(idd+unj);
        }
        else
        {
            if(Meter_Parameter.parameter1.KeyDisplayNumber>120)
                Meter_Parameter.parameter1.KeyDisplayNumber=1;
            cyc_show_num_sta=0;
            cyc_show_num_end=Meter_Parameter.parameter1.KeyDisplayNumber; 
            
            addr=CYCLEDISPLAYTABLE_B_ROM;
            WRLC256(addr,(unsigned char*)&Co.b[500],sizeof(struct SHOW_CODE_TABLE1)*cyc_show_num_end,0,1);            
        }        
          
        for(unc=cyc_show_num_sta;unc<cyc_show_num_end;unc++)
        {   
            if(unc>=120)
                return -1;
            addr=unc*sizeof(struct SHOW_CODE_TABLE1);
            User_Defind_Table_temp1=*((struct SHOW_CODE_TABLE1 *)&Co.b[500+addr]);
            idtemp.l=User_Defind_Table_temp1.default_code;
			/*"事件或者冻结才更新备份显示项目"*/
			if (idtemp.d[3]==0x03 || (idtemp.d[3]>=0x10 && idtemp.d[3]<=0x21) || idtemp.d[3]==0x05)
			{
				/*"---各类总数据\电压合格率\累计时间---"*/
				/*"03050000	全失压总次数，总累计时间"*/
				/*"0310**00	电压合格率统计数据"*/
				/*"03110000	掉电总次数"*/
				/*"0312**00	需量超限总次数"*/
				/*"033***00	编程\清零\校时\开盖总次数\恒定磁场干扰\电源异常 总次数"*/
				/*"1***0001	总次数"*/
				/*"1***0002	总累计时间"*/
				/*"10**0003	失压期间正向有功总电量"*/
				/*"10**0004	失压期间反向有功总电量"*/
				/*"2***0001	欠压总次数"*/
				/*"2***0002	欠压总累计时间"*/
			    flag=flag11=0;
		 		if (idtemp.d[3]==0x10||idtemp.d[3]==0x13||idtemp.d[3]==0x14||idtemp.d[3]==0x18)	/*"失压\断相\电压逆相序\失流"*/
					flag=0xFF;
				if (idtemp.l==0x03300001||idtemp.l==0x03050001||idtemp.l==0x03300D01||idtemp.l==0x03300E01||idtemp.l==0x03110001	/*"最近一次事件:编程\恒定磁场干扰\开表\开端表\掉电"*/
					||idtemp.l==0x10000101||idtemp.l==0x10000201)	/*"最近1次失压发生时刻\最近1次失压结束时刻"*/
					flag11=0xFF;
				if ((idtemp.d[3]!=0x05&&idtemp.d[0]==0x00)							/*"总次数和电压合格率"*/
					||((idtemp.d[3]>=0x10 && idtemp.d[3]<=0x21)&&idtemp.d[1]==0x00)	/*"总次数和累计时间"*/
					||((flag==0xFF&&idtemp.d[0]==0x01)||flag11==0xFF))				/*"最近一次记录"*/
					continue;	/*"查找到的数据不在FALSH中,不用更新"*/
			
	            ret=TransferData_New(idtemp,&buffer[0], (unsigned int)User_Defind_Table_temp1.flag,
	               SHOWFORMAT,(unsigned char *)&Show_Powerdown_Data,0x03,0,0x03);
	          
	            if((ret!=0)&&(Show_ID_vatiy==0xff))//&&(flag11==0xff))
	            {
	                if((CompareBytes((unsigned char *)&Show_Powerdown_Key_Data[unc].showbuff[0],(unsigned char *)&buffer[0],ret)!=0)
	               ||(CompareBytes((unsigned char *)&Show_Powerdown_Key_Data[unc].Powerdown_show_table,(unsigned char *)&Show_Powerdown_Data,3)!=0)
	               ||(Show_Powerdown_Key_Data[unc].Show_FlashData_flag.falshDatalen!=ret)
	               ||(Show_Powerdown_Key_Data[unc].Show_FlashData_flag.vatiryflag==0))
	               {
	                    Show_Powerdown_Key_Data[unc].Show_FlashData_flag.vatiryflag=1;
	                    Show_Powerdown_Key_Data[unc].Show_FlashData_flag.falshDatalen=ret;
	                    for(unj=0;unj<6;unj++)
	                        Show_Powerdown_Key_Data[unc].showbuff[unj]=buffer[unj];
	                    Show_Powerdown_Key_Data[unc].Powerdown_show_table=Show_Powerdown_Data;
	                    //flag=0xff;
						WRLC256(SHOW_POWERDOWN_KEY_DATA_ROM+unc*sizeof(struct Show_Powerdown_Data_Struct),(unsigned char*)&Show_Powerdown_Key_Data[unc],sizeof(struct Show_Powerdown_Data_Struct),0,0);
	               }
	            }
	            else
	            {
	                if(Show_Powerdown_Key_Data[unc].Show_FlashData_flag.vatiryflag==1)
	                {
	                    Show_Powerdown_Key_Data[unc].Show_FlashData_flag.vatiryflag=0;
	                    //flag=0xff;
	                }
	            }
	            FeedWatchdog();
			}
            CheckPowerDown();
        }
        //if((flag==0xff)&&(storekind==0xff))
        //{
        //    if((Checkkind==0xff)||(Checkkind==0x0f))
        //       WRLC256(SHOW_POWERDOWN_KEY_DATA_ROM,(unsigned char*)&Show_Powerdown_Key_Data[0],cyc_show_num_end*sizeof(struct Show_Powerdown_Data_Struct),0,0);
        //    else
        //       WRLC256(SHOW_POWERDOWN_KEY_DATA_ROM+Checkshownum*sizeof(struct Show_Powerdown_Data_Struct),(unsigned char*)&Show_Powerdown_Key_Data[Checkshownum],sizeof(struct Show_Powerdown_Data_Struct),0,0);
        //    FeedWatchdog();
        //    CheckPowerDown();
        //} 
    }

    return 0;     
}	
/*"============================================================"*/
/*"函数名：Check_Event_Show_Data"*/
/*"用途：正常运行处理低功耗下FLASH数据函数"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
char Check_Event_Show_Data(unsigned char storekind)
{
    unsigned int uni,flag;

    for(uni=0;uni<6;uni++)
    {        
        if(Event_Power_Net_Flag.byte[uni]!=Show_Powerdown_Net_Flag_Backup.byte[uni])
        {
            Show_flash_poweron_vatiy=0xff;
            break;
        }
    }   
    if((storekind==0xff)&&(Show_flash_poweron_vatiy==0xff))
    {
       Check_Show_Flash_Data(RefreshShow_KeyOrCyc,0,0xff,0);    
       if(RefreshShow_KeyOrCyc!=0x0f)
            Show_flash_poweron_vatiy=0;
       RefreshShow_KeyOrCyc=~RefreshShow_KeyOrCyc;
    }
    Show_Powerdown_Net_Flag_Backup=Event_Power_Net_Flag;
}
/*"============================================================"*/
/*"函数名：Poweron_Event_Show_Data"*/
/*"用途：上电处理低功耗下FLASH数据函数"*/
/*"返回：无"*/
/*"版本：1.00"*/
/*"============================================================"*/
char Poweron_Event_Show_Data(void)
{
    Show_Powerdown_Net_Flag_Backup=Event_Power_Net_Flag;
    //if(Show_flash_poweron_vatiy==0xff)
    Check_Show_Flash_Data(0xff,0,0xff,0);
    Show_flash_poweron_vatiy=0;
    RefreshShow_KeyOrCyc=0x0f;
	return 0;
}

void Refresh_Err_Show(void)
{
	if(Abnormal_Show_Mode.bit.b0)
		Show_Err_Type(Fail_show_cnt);//lfy changed 100705
	else if(Abnormal_Show_Mode.bit.b1)
		Show_Err_Type(0x50+Event_show_cnt-1);
	else if(Abnormal_Show_Mode.bit.b2)
		Show_Err_Type(0x50+Event_show_cnt);
}

//------change by pc 120828------//
void SetShowErrNum(unsigned char *temppointer0,unsigned char *temppointer1)
{
	unsigned char i;
	unsigned char unc0;
	unsigned char unc1;
	
	unc0=0;
	unc1=0;
	if(!IntoPowerDownFlag)
	{
		if(failabnormalshow.byte!=0)
		{
			for(i=0;i<8;i++)
			{
				if(((failabnormalshow.byte)&(0x01<<i))!=0)
				{
					unc1=i+1;
					break;
				}
			}
		}
		else if(eventabnormalshow.byte!=0)
		{
			for(i=0;i<8;i++)
			{
				if(((eventabnormalshow.byte)&(0x01<<i))!=0)
				{
					unc0=5;
					unc1=i;
					break;
				}
			}
		}
	}
	*temppointer0=unc0;
	*temppointer1=unc1;
	
}

#define HZ_Recieved_LCD_show_cmd 0
#define HZ_LCD_cmd_showing     1
#define Exit_HZ_LCD_show     0xff


unsigned char  HZ_LCDCmdShow(void)///king chen add  130204
{
	unsigned char leaf_copy;
	unsigned char buffer[40];
	unsigned long temp_time;
	unsigned char result=0xff;
	unsigned char show_buffer[40];
	unsigned char unc;
	unsigned int i;
    
	if(LCD_Check_State==HZ_Recieved_LCD_show_cmd ||LCD_Check_State==HZ_LCD_cmd_showing)
	{

		if( key_flag.bit.b0)
		{
			LCD_Check_State=Exit_HZ_LCD_show;///king chen modify 130228
			///key_flag.bit.b2=0;
			///key_flag.bit.b0=0;///king chen add 130304
			///key_jump_flag=0;
			///BACK_LIGHT_ON=0;///
			///light_backled_flag=0;///
			///BackLight_Ctrl(CLOSE_MODE,0,0,LCDCMDSHOW_EVENT);///king chen add 130304
			///Show_Initialize(2);
			///Key_Initialize(0);			
			///cyc_show_time=GetNowTime();
			SHOW_ABC_SEG(B_SEG);
			 cyc_show_num=0;
			 key_flag.bit.b2=1;
			 key_flag.bit.b0=0;
			Key_Initialize(On_KeyClick_For_B_mode_show);
			BackLight_Ctrl(FIX_TIME_LIGHT_MODE,Meter_Parameter.parameter2.ShowNoKeyRetTime ,0,KEYDOWN_EVENT);///king chen add 130304
                     last_time=GetNowTime();
			if(light_AlarmSwitchLED==0xFF)
			{
                         light_AlarmSwitchLED=0;
                         SWITCH_CLEW=0;
			}
			Show_Main(show_code,&buffer[0],user_defind_code,user_defind_code_len);
			show_on_lcd(&buffer[0],0,SHOW_RAM_NUM);
			flash_time=GetNowTime();
		
			 return 0xff;
		}
		if(LCD_Check_State==HZ_Recieved_LCD_show_cmd)
		{
          
                 PowerOn_FullScreen_TimeDetection();
        
			LCD_Check_State=HZ_LCD_cmd_showing;

			for(unc=0;unc<40;unc++)
				show_buffer[unc]=0;
                    if((User_Choose_Table.default_code==0x88888888)&&(User_Choose_Table.flag==0x00))
                     {
                        //lightLED=0xFF;
                        /*"全屏点亮报警和跳闸指示灯"*/
                        light_AlarmSwitchLED=0xFF;
			   SWITCH_CLEW=1;///
                     }
			leaf_copy=leaf_flag;
			leaf_flag=User_Choose_Table.flag;
			Show_Main(User_Choose_Table.default_code,show_buffer, 0, 0);
			show_on_lcd(show_buffer, 0, SHOW_RAM_NUM);
			leaf_flag=leaf_copy;
			flash_time=GetNowTime();
			
			///BACK_LIGHT_ON=1;///
			///light_backled_flag=1;///
			BackLight_Ctrl(FIX_TIME_LIGHT_MODE,10,0,LCDCMDSHOW_EVENT);///king chen modify
			HZ_show_start_time=GetNowTime();
		}
		else
		{
			temp_time=GetNowTime();
			if(!(GetTimeCount(HZ_show_start_time, LCD_Check_Second*1000l)))
			{
				LCD_Check_State=Exit_HZ_LCD_show;
				key_flag.bit.b2=0;
				key_jump_flag=0;
				///BACK_LIGHT_ON=0;///
				///light_backled_flag=0;///
				///BackLight_Ctrl(CLOSE_MODE,0,0,LCDCMDSHOW_EVENT);///king chen mark 130312
				Show_Initialize(2);
				Key_Initialize(0);			
				cyc_show_time=GetNowTime();
                            if(light_AlarmSwitchLED==0xFF)
                             {
                                //lightLED=0;
                                /*"全屏10秒后关闭报警和跳闸指示灯"*/
                                light_AlarmSwitchLED=0;
                                SWITCH_CLEW=0;
                             }
			}
			else
			{
				if((flash_time/FLASH_TIME)!=(temp_time/FLASH_TIME))
					{
						leaf_copy=leaf_flag;
						leaf_flag=User_Choose_Table.flag;
						Show_Main(User_Choose_Table.default_code,&buffer[0],0,0);
						show_on_lcd(&buffer[0],0,SHOW_RAM_NUM);
						leaf_flag=leaf_copy;
						flash_time=GetNowTime();
					}
			}	
		}
	}
	else
	{
		result=0;
	}

	return result;
}

void OutCardInCycshow(void)
{
	key_flag.bit.b2=0;
	key_jump_flag=0;
	Key_Initialize(0);			
	cyc_show_time=GetNowTime();
}

/*"低功耗下每秒刷新时间的显示"*/
void Pd_Refresh_TimeShow_PerSec(void)
{
	char buffer[MAX_LINE_NUM+3][MAX_DATA_NUM];
	char TriffNumble_bak;
	
	if(pdmode1==0x34)/*"等待换屏状态"*/
	{
		if((pd_now_show_code==0x04000101)||(pd_now_show_code==0x04000102)||(pd_now_show_code==0x0400010c))
		{
			if(pd_time_show_cnt>=2)/*"距离上次刷新时间超过1秒"*/
			{
				pd_time_show_cnt=0;
				
				if(pdmode3 != 0x33)
      	{
	        Prepare_for_Wakeup(1);
      	}
				
				Show_Main(pd_now_show_code,&buffer[0][0],pd_now_user_def_code,pd_now_user_def_len);		
		    TriffNumble_bak=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble;
		    Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=0;
		    Show_flag.bit.I  = Show_flash_falg.bit.I  ;
		    Show_flag.bit.II = Show_flash_falg.bit.II ;
		    Show_flag.bit.III= Show_flash_falg.bit.III;
		    Show_flag.bit.IV = Show_flash_falg.bit.IV ;	
		
		    Show_flash_falg.bit.I  = 0;
		    Show_flash_falg.bit.II = 0;
		    Show_flash_falg.bit.III= 0;
		    Show_flash_falg.bit.IV = 0;	
		    show_on_lcd(&buffer[0][0],0,SHOW_RAM_NUM);
		    Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble=TriffNumble_bak;
			}
		}
	}
	
}
