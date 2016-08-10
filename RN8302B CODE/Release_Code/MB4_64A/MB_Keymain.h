/*" MB2表通用版按键程序 (v0.2 bata0401)  	"*/
/*"Creat by TREND 2004-12-1 for shanghai	"*/
/*"Edit  by TREND 2005-04-1 for 通用版 		"*/
//for extern funtion and variable
//---------------------------------------------------------------------------
//

#define _SHOW_BLANK_SRC      0 /*"循环显示换屏是否要闪一下0不要1要"*/ 

#ifndef 	__KEYMAIN_H__
#define 	__KEYMAIN_H__

typedef void (* TOn_Key_Click)(char keyval,long time);
typedef void (* TOn_Set_key_Click)(void);


#endif

//---------------------------------------------------------------------------
//public funtion
extern void Key_Initialize(TOn_Key_Click On_Click_Fun);
extern void Set_key_Event( TOn_Set_key_Click On_Set_key_fun);
extern char Key_Main(void);
extern void key_interrupts(void);
//extern char Drop_Cyc_Show(void);
extern char Drop_Key_Main(void);
extern void Drop_Key_Initialize(TOn_Key_Click On_Click_Fun,unsigned char kind);
extern void Exit_Normal_Show(void);
extern void Enter_Dorp_Show(void);
extern void Set_show_code_list(int id);

extern void	Goto_Wait_Exit_Wait(void);
extern void	Prepare_for_Wait(void);
extern void	Prepare_for_Wakeup(unsigned char);
extern void IR_Set_show_code(long code);
extern void show_clear_char(void);

extern void IR_interrupts(void);
extern void IR_Timer(void);
extern void Init_IR_Ctrl(void);
#pragma INTERRUPT key_interrupts();
#pragma INTERRUPT IR_interrupts();
#pragma INTERRUPT IR_Timer();

//typedef void (* TOn_Key_Click)(char keyval,long time);
/*"以下定义用户配置的A、B套显示方案表，需要在内卡和电表参数中添加"*/
/*"default_code 最高字节为0xff,表示以老方式设置A、B套显示表，flag: 叶子标志"*/
struct SHOW_CODE_TABLE1 {
	          unsigned long default_code;	          
	          unsigned char flag;                           /*"叶子标志"*/
            };
struct SHOW_CODE_TABLE2 {
              unsigned long user_code;
	          unsigned char user_code_len;
            };
//---------------------lfy 090927--------------------------
struct FAIL_ABNORMAL_BIT_DEF
{
	char CtrCircleErr:1;//lfy chaged 100705
	char EsamErr:1;
	char EepromInitErr:1;
	char ClockBatErr:1;
	char ProgramErr:1;
	char MemoryErr:1;
	char :1;
	char ClockErr:1;
};
union FAIL_ABNORMALl{
	struct FAIL_ABNORMAL_BIT_DEF bit;
	unsigned char byte;
};

struct EVENT_ABNORMAL_BIT_DEF{
	char :1;
	char OverLoad:1;
	char CurrentImbalance:1;
	char OverVoltage:1;
	char OverPowerFactor:1;
	char OverActiveDemandAlarm:1;
	char EnergyDirectChange:1;
	char :1;
};
union EVENT_ABNORMAL{
	struct EVENT_ABNORMAL_BIT_DEF bit;
	unsigned char byte;
};
//----------------------------------------------------------
extern struct SHOW_CODE_TABLE1 User_Defind_Table1;
extern struct SHOW_CODE_TABLE2 User_Defind_Table2;
extern union byte_def key_flag;

extern unsigned char pdmode1;
extern unsigned long show_code,user_defind_code;
extern int cyc_show_num;
extern unsigned char user_defind_code_len;
extern unsigned long cyc_show_time;

extern unsigned long Full_show_time;
extern unsigned long Full_show_time_Limit;

extern struct SHOW_CODE_TABLE1 User_Choose_Table;	
extern unsigned char  LCD_Check_State;
extern unsigned char  LCD_Check_Second;	
extern unsigned long HZ_show_start_time;
extern unsigned char light_AlarmSwitchLED;
extern unsigned char light_backled_flag;

extern unsigned long pd_now_show_code;
extern unsigned char pd_time_show_cnt;

extern void show_build_char(void); 
 extern void show_rebuild_char(void);
 extern void LCDREAD(unsigned char flag,unsigned char num);//ADD BY ZLP

 extern void  SHOW_ABC_SEG(unsigned char SEGFLAG );//add by zlp
//struct KEY_VAL {
//        union byte_def key_value;
//        unsigned int time;
//		};
//extern struct KEY_VAL temp_key_val;
//extern struct KEY_VAL real_key_val;
//extern unsigned long start_time;  
extern union FAIL_ABNORMALl Fail_abnormal;
extern union EVENT_ABNORMAL Event_abnormal;
extern union FAIL_ABNORMALl failabnormalshow;
extern union EVENT_ABNORMAL eventabnormalshow;
extern union BYTE_BIT   Abnormal_Show_Mode;
extern char Check_Show_Flash_Data(unsigned char ,unsigned char ,unsigned char ,unsigned char *);
extern char Check_Event_Show_Data(unsigned char );
extern char Poweron_Event_Show_Data(void);

extern void Pd_Refresh_TimeShow_PerSec(void);

extern void OutCardInCycshow(void);


