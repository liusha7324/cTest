#ifndef _BACK_LIGHT_CTRL_H
#define _BACK_LIGHT_CTRL_H
/*"背光控制模式定义"*/
enum  BACK_LIGHT_CTRL_MODE
{
       CLOSE_MODE = 0,                   /*"背光关闭,只用于长时间控制点亮模式关闭"*/
	CONTINUOUS_LIGHT_MODE,  /*"持续点亮模式"*/
	FIX_TIME_LIGHT_MODE,       /*"定长时间背光点亮模式"*/
	IC_CARD_LIGHT_MODE,        /*"插卡背光点亮模式"*/
	POWER_UP_LIGHT_MODE,    /*"上电背光点亮模式"*/
	BLINK_MODE,                         /*"闪烁模式"*/
	MAX_MODE,
};         
/*"背光长控源定义"*/
enum  BACK_LIGHT_CTRL_SOURCE
{
       EVENT = 0,                              /*"事件报警"*/
	PAY_EVENT,                             /*"预付费"*/
	FULLSCREEN_EVENT,
	KEYDOWN_EVENT,
	LCDCMDSHOW_EVENT,
	UART2_EVENT,
	CARD_JUDGE_EVENT,
	CARD_OPERATE_EVENT,
	IR_SET_EVENT,
	IR_kEYDOWN_EVENT,
	MAX_SOURCE,
};    

/*"背光长控源"*/
union BACK_LIGHT_SOURCE
{
struct
{
unsigned char b0:1;
unsigned char b1:1;
unsigned char b2:1;
unsigned char b3:1;
unsigned char b4:1;
unsigned char b5:1;
unsigned char b6:1;
unsigned char b7:1;

unsigned char b8:1;
unsigned char b9:1;
unsigned char b10:1;
unsigned char b11:1;
unsigned char b12:1;
unsigned char b13:1;
unsigned char b14:1;
unsigned char b15:1;

unsigned char b16:1;
unsigned char b17:1;
unsigned char b18:1;
unsigned char b19:1;
unsigned char b20:1;
unsigned char b21:1;
unsigned char b22:1;
unsigned char b23:1;

unsigned char b24:1;
unsigned char b25:1;
unsigned char b26:1;
unsigned char b27:1;
unsigned char b28:1;
unsigned char b29:1;
unsigned char b30:1;
unsigned char b31:1;
}bit;
unsigned char byte[4];
unsigned long backlight_source;
};

struct BLACK_LIGHT_CTRL
{
unsigned long BackLight_start;        /*"背光点亮控制时长起始时刻"*/
unsigned int    time;                         /*"背光点亮控制时长(单位秒)"*/
unsigned int    remain_time;           /*"背光关闭剩余时间(单位秒)"*/
#ifdef  BACK_LIGHT_BLINK_MODE
unsigned char period;                      /*"背光闪烁半周期时长(单位5ms)"*/
unsigned char blink_times;             /*"背光闪烁次数"*/
#endif
};

extern void BackLight_Ctrl(enum  BACK_LIGHT_CTRL_MODE mode, unsigned int time,
                                     unsigned char blink_times, enum  BACK_LIGHT_CTRL_SOURCE  ctrl_source);
extern void BackLight_RemainTime_Dec(void);
extern void BackLight_driver(void);

#ifdef  BACK_LIGHT_BLINK_MODE
extern void BackLightBlink(void);
#endif

#endif