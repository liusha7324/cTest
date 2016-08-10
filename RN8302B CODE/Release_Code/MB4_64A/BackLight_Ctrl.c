#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "att7022_operation.h"
#include "initram.h"
#include "Demand.h"
#include "MB_Showmain.h"
#include "MB_Keymain.h"
//#include "MB_Iccard.h"
#include "seg.h" 
#include "AllVoltageLoss.h"
#include "multi.h"   //mw added 080131
#include "Freeze.h"  //fxf  added081027
#include "File_System.h"  //add by pc 081208
#include "Measure_Interface.h" 
#include "Pay_def.h"
#include "Ex_Pay_For_Fun.h"		//payment
#include "ICcard.h"
#include "Energy_Del.h"
#include "BackLight_Ctrl.h"

enum  BACK_LIGHT_CTRL_MODE  BackLightModeNow; /*"当前背光点亮模式"*/
union BACK_LIGHT_SOURCE  BackLightSource;/*"背光长控源"*/
struct BLACK_LIGHT_CTRL     BackLightCtrl;/*"背光控制"*/

void BackLight_Ctrl(enum  BACK_LIGHT_CTRL_MODE mode, unsigned int time,
                                     unsigned char blink_times, enum  BACK_LIGHT_CTRL_SOURCE  ctrl_source);
void BackLight_RemainTime_Dec(void);
void BackLight_driver(void);

#ifdef  BACK_LIGHT_BLINK_MODE
void BackLightBlink(void);
#endif

/*"=============================================================="*/
/*"函数说明：背光控制公用函数接口"*/
/*"输入参数：mode               背光控制模式 "*/
/*"                            time                背光点亮持续时间(单位秒) ，0表示长时间控制"*/
/*"                                                  闪烁模式表示控制半周期(单位为5ms)"*/
/*"                            blink_times      背光闪烁次数"*/
/*"                            ctrl_source       背光常亮控制源"*/
/*"输出参数：无"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/

void BackLight_Ctrl(enum  BACK_LIGHT_CTRL_MODE mode, unsigned int time,
                                     unsigned char blink_times, enum  BACK_LIGHT_CTRL_SOURCE  ctrl_source)
{

switch(mode)
{
case CLOSE_MODE:
	/*"当长控请求源结束时，相应的位清0"*/
	BackLightSource.byte[ctrl_source>>3] &= ~(0x01 << (ctrl_source - (ctrl_source>>3<<3)));
	break;
case  CONTINUOUS_LIGHT_MODE:
case  POWER_UP_LIGHT_MODE:
	/*"当长控请求源到时，相应的位置1"*/
       BackLightSource.byte[ctrl_source>>3] |= (0x01 << (ctrl_source - (ctrl_source>>3<<3)));
	if(BackLightModeNow != BLINK_MODE)
		{
		BackLightModeNow = CONTINUOUS_LIGHT_MODE;
		}
	if(POWER_UP_LIGHT_MODE ==mode)
	{
		BACK_LIGHT_ON = 1;
	}
	break;
case FIX_TIME_LIGHT_MODE:
case IC_CARD_LIGHT_MODE:
	if(BackLightCtrl.remain_time < time)/*"当前背光点亮剩余时长小于新要求点亮时长，更新控制时间"*/
	{
	       BackLightCtrl.BackLight_start = GetNowTime();
		BackLightCtrl.time = time;
		BackLightCtrl.remain_time = time;
	}
	if((BackLightModeNow != BLINK_MODE) && (BackLightModeNow != CONTINUOUS_LIGHT_MODE))
	{
		BackLightModeNow = FIX_TIME_LIGHT_MODE;
	}
	if(IC_CARD_LIGHT_MODE == mode)
	{
		BackLight_driver();
	}
	break;
#ifdef  BACK_LIGHT_BLINK_MODE
case BLINK_MODE:
	if(BackLightModeNow != BLINK_MODE)
	{
		BackLightModeNow = BLINK_MODE;
		BackLightCtrl.period= time;
		BackLightCtrl.blink_times = blink_times;
	}	
	break;
#endif
default: break;
}
}
/*"=============================================================="*/
/*"函数说明：背光点亮剩余时间计算，每秒调用"*/
/*"输入参数：无"*/
/*"输出参数：无"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void BackLight_RemainTime_Dec(void)
{
if(BackLightCtrl.remain_time > 0)
{
BackLightCtrl.remain_time--;
}
}
/*"=============================================================="*/
/*"函数说明：背光控制驱动函数根据当前背光点亮模式"*/
/*"                            按照闪烁、持续点亮、定时点亮的顺序处理"*/
/*"输入参数：无"*/
/*"输出参数：无"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void BackLight_driver(void)
{
#ifdef  BACK_LIGHT_BLINK_MODE
if(BLINK_MODE == BackLightModeNow)
{
	if(0 == BackLightCtrl.blink_times)
	{
		BackLightModeNow = CONTINUOUS_LIGHT_MODE;
	}
}
#endif

if(CONTINUOUS_LIGHT_MODE == BackLightModeNow)
{
	if(0 == BackLightSource.backlight_source)
	{
		BackLightModeNow = FIX_TIME_LIGHT_MODE;
	}
}

if(FIX_TIME_LIGHT_MODE == BackLightModeNow)
{
	if(0 == GetTimeCount(BackLightCtrl.BackLight_start, BackLightCtrl.time * 1000l))
	{
		BackLightModeNow = CLOSE_MODE;
	}
}

if(CLOSE_MODE == BackLightModeNow)
{
       BACK_LIGHT_ON = 0;
}
else if(BLINK_MODE != BackLightModeNow)
{
       if((VoltageGreaterThanThreshold_Flag==1)||(auxiliary_power_flag==1))     /*"最大的相电压是否大于门槛的标志"*/
       {
       	BACK_LIGHT_ON = 1;
       }
	else
	{
	 	BACK_LIGHT_ON = 0;	 	
	}
}
}
#ifdef  BACK_LIGHT_BLINK_MODE
unsigned char Blink_period_cnt;
/*"=============================================================="*/
/*"函数说明：背光闪烁控制驱动函数，在5ms定时中断服务函数中调用，保证时效性"*/
/*"输入参数：无"*/
/*"输出参数：无"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void BackLightBlink(void)
{
if(BLINK_MODE == BackLightModeNow)
{
if((VoltageGreaterThanThreshold_Flag==1)||(auxiliary_power_flag==1))     /*"最大的相电压是否大于门槛的标志"*/
{
Blink_period_cnt++;
if(Blink_period_cnt  >= BackLightCtrl.period)
{
Blink_period_cnt = 0;
BACK_LIGHT_ON = ~ BACK_LIGHT_ON;
}
if(BACK_LIGHT_ON == 0)
{
       if(BackLightCtrl.blink_times > 0)
	{
		BackLightCtrl.blink_times--;
	}
}
if(0 == BackLightCtrl.blink_times)
{
BackLightModeNow = CONTINUOUS_LIGHT_MODE;
}		
}
else
{
BACK_LIGHT_ON = 0;
}
}
}
#endif
