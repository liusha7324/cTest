#ifndef _BACK_LIGHT_CTRL_H
#define _BACK_LIGHT_CTRL_H
/*"�������ģʽ����"*/
enum  BACK_LIGHT_CTRL_MODE
{
       CLOSE_MODE = 0,                   /*"����ر�,ֻ���ڳ�ʱ����Ƶ���ģʽ�ر�"*/
	CONTINUOUS_LIGHT_MODE,  /*"��������ģʽ"*/
	FIX_TIME_LIGHT_MODE,       /*"����ʱ�䱳�����ģʽ"*/
	IC_CARD_LIGHT_MODE,        /*"�忨�������ģʽ"*/
	POWER_UP_LIGHT_MODE,    /*"�ϵ米�����ģʽ"*/
	BLINK_MODE,                         /*"��˸ģʽ"*/
	MAX_MODE,
};         
/*"���ⳤ��Դ����"*/
enum  BACK_LIGHT_CTRL_SOURCE
{
       EVENT = 0,                              /*"�¼�����"*/
	PAY_EVENT,                             /*"Ԥ����"*/
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

/*"���ⳤ��Դ"*/
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
unsigned long BackLight_start;        /*"�����������ʱ����ʼʱ��"*/
unsigned int    time;                         /*"�����������ʱ��(��λ��)"*/
unsigned int    remain_time;           /*"����ر�ʣ��ʱ��(��λ��)"*/
#ifdef  BACK_LIGHT_BLINK_MODE
unsigned char period;                      /*"������˸������ʱ��(��λ5ms)"*/
unsigned char blink_times;             /*"������˸����"*/
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