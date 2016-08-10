#include "defmcro.h"
//#include "Wireless.h"
#include "defdata.h"
#include "ram.h"
#include "comm.h"
#include "MB_Showmain.h"
#include "ICcard.h"
// #include "multi.h"  

//extern unsigned  char OverPowerAlarmFlag;
extern unsigned char ChenkPasserwordFlag;         /*"测试用户权限标志"*/
//union BYTE_BIT GPRS_Event_Status[10];	//payment
//union BYTE_BIT GPRS_Event_OldStatus[10];
//unsigned char  uartxcomm;
//unsigned char GPRS_Status;//bit7 0:outline  1:inline  
//                                          //bit0~bit2  0:no signal  1~4:signal strenth bad~good
unsigned long GPRS_Status_Time;


//int Read_event_GPRS(void);	
int Set_GPRS_State_Allow(void);
int Set_GPRS_State(void);
int Get_GPRS_State(void);
void GPRS_Signal_Stength_Lcd_show(void);
void Reset_Wireless_State(void);

/*"============================================================"*/
/*"函数名：GPRS_Signal_Stength_Lcd_show"*/
/*"用途：无线通信状态置显示 "*/
/*"参数：无"*/
/*"返回：无"*/
/*"调用：主循环调用"*/
/*"作者：GANJP    "*/
/*"============================================================"*/
void GPRS_Signal_Stength_Lcd_show(void)
{
if((GPRS_Status&0x80) != 0)
	Show_flag.bit.Base = 1;
else
	Show_flag.bit.Base = 0;
switch((GPRS_Status&0x07))
{
case 0:
	Show_flag.bit.Signal1 = 0;
	Show_flag.bit.Signal2 = 0;
	Show_flag.bit.Signal3 = 0;
	Show_flag.bit.Signal4 = 0;
	break;
case 1:
	Show_flag.bit.Signal1 = 1;
	Show_flag.bit.Signal2 = 0;
	Show_flag.bit.Signal3 = 0;
	Show_flag.bit.Signal4 = 0;
	break;
case 2:
	Show_flag.bit.Signal1 = 1;
	Show_flag.bit.Signal2 = 1;
	Show_flag.bit.Signal3 = 0;
	Show_flag.bit.Signal4 = 0;
	break;
case 3:
	Show_flag.bit.Signal1 = 1;
	Show_flag.bit.Signal2 = 1;
	Show_flag.bit.Signal3 = 1;
	Show_flag.bit.Signal4 = 0;
	break;
case 4:
	Show_flag.bit.Signal1 = 1;
	Show_flag.bit.Signal2 = 1;
	Show_flag.bit.Signal3 = 1;
	Show_flag.bit.Signal4 = 1;
	break;
	default: 
	Show_flag.bit.Signal1 = 0;
	Show_flag.bit.Signal2 = 0;
	Show_flag.bit.Signal3 = 0;
	Show_flag.bit.Signal4 = 0;
	break;
}
}

void Reset_Wireless_State(void)
{
if(!GetTimeCount(GPRS_Status_Time,120l*1000l))
{
GPRS_Status=0;
GPRS_Status_Time=GetNowTime();
}
}

/*"============================================================"*/
/*"函数名：Read_event_GPRS"*/
/*"用途：事件状态字读后方法(事件状态字发生变化后模块主动抄读) "*/
/*"参数：无"*/
/*"返回：0"*/
/*"调用：读事件状态字后调用"*/
/*"作者：GANJP    "*/
/*"============================================================"*/
//int Read_event_GPRS(void)		//payment
//{
//	if(uartxcomm==2)
//		{
//		GPRS_Event_Status[2].bit.b7=0;/*"购电事件抄读完后清标志"*/
//              Event_DIS=0;
//		}	
//	return 0;
//}


int Set_GPRS_State(void)
{
GPRS_Status = *Co.c.addr5;
GPRS_Status_Time=GetNowTime();	  
ChenkPasserwordFlag=0xff;    
return 0;
}

int Get_GPRS_State(void)
{
		return 0;
}

