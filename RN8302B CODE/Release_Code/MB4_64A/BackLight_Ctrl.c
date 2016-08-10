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

enum  BACK_LIGHT_CTRL_MODE  BackLightModeNow; /*"��ǰ�������ģʽ"*/
union BACK_LIGHT_SOURCE  BackLightSource;/*"���ⳤ��Դ"*/
struct BLACK_LIGHT_CTRL     BackLightCtrl;/*"�������"*/

void BackLight_Ctrl(enum  BACK_LIGHT_CTRL_MODE mode, unsigned int time,
                                     unsigned char blink_times, enum  BACK_LIGHT_CTRL_SOURCE  ctrl_source);
void BackLight_RemainTime_Dec(void);
void BackLight_driver(void);

#ifdef  BACK_LIGHT_BLINK_MODE
void BackLightBlink(void);
#endif

/*"=============================================================="*/
/*"����˵����������ƹ��ú����ӿ�"*/
/*"���������mode               �������ģʽ "*/
/*"                            time                �����������ʱ��(��λ��) ��0��ʾ��ʱ�����"*/
/*"                                                  ��˸ģʽ��ʾ���ư�����(��λΪ5ms)"*/
/*"                            blink_times      ������˸����"*/
/*"                            ctrl_source       ���ⳣ������Դ"*/
/*"�����������"*/
/*"��    �أ���  "*/
/*"��    �ߣ�GANJP  �汾��1.00"*/
/*"================================================================"*/

void BackLight_Ctrl(enum  BACK_LIGHT_CTRL_MODE mode, unsigned int time,
                                     unsigned char blink_times, enum  BACK_LIGHT_CTRL_SOURCE  ctrl_source)
{

switch(mode)
{
case CLOSE_MODE:
	/*"����������Դ����ʱ����Ӧ��λ��0"*/
	BackLightSource.byte[ctrl_source>>3] &= ~(0x01 << (ctrl_source - (ctrl_source>>3<<3)));
	break;
case  CONTINUOUS_LIGHT_MODE:
case  POWER_UP_LIGHT_MODE:
	/*"����������Դ��ʱ����Ӧ��λ��1"*/
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
	if(BackLightCtrl.remain_time < time)/*"��ǰ�������ʣ��ʱ��С����Ҫ�����ʱ�������¿���ʱ��"*/
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
/*"����˵�����������ʣ��ʱ����㣬ÿ�����"*/
/*"�����������"*/
/*"�����������"*/
/*"��    �أ���  "*/
/*"��    �ߣ�GANJP  �汾��1.00"*/
/*"================================================================"*/
void BackLight_RemainTime_Dec(void)
{
if(BackLightCtrl.remain_time > 0)
{
BackLightCtrl.remain_time--;
}
}
/*"=============================================================="*/
/*"����˵����������������������ݵ�ǰ�������ģʽ"*/
/*"                            ������˸��������������ʱ������˳����"*/
/*"�����������"*/
/*"�����������"*/
/*"��    �أ���  "*/
/*"��    �ߣ�GANJP  �汾��1.00"*/
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
       if((VoltageGreaterThanThreshold_Flag==1)||(auxiliary_power_flag==1))     /*"�������ѹ�Ƿ�����ż��ı�־"*/
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
/*"����˵����������˸����������������5ms��ʱ�жϷ������е��ã���֤ʱЧ��"*/
/*"�����������"*/
/*"�����������"*/
/*"��    �أ���  "*/
/*"��    �ߣ�GANJP  �汾��1.00"*/
/*"================================================================"*/
void BackLightBlink(void)
{
if(BLINK_MODE == BackLightModeNow)
{
if((VoltageGreaterThanThreshold_Flag==1)||(auxiliary_power_flag==1))     /*"�������ѹ�Ƿ�����ż��ı�־"*/
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
