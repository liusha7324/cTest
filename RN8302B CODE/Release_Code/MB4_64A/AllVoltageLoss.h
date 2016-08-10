/*-------------------------------------------------------------------
Filename:AllVoltageLoss.h
Functions:	Declare the variable and functions defined in
			AllVoltageLoss.c as "extern". 
--------------------------------------------------------------------*/
#ifndef	_AllVoltageLoss_h
#define	_AllVoltageLoss_h

#define     PDOPEN6515RELAYTIME 102

extern	void	AllVoltageLoss_WakingUp_Counter_Updating(void);	/*INT3:"全失压脉冲中断服务程序"*/
/*"取得全失压事件记录地址、条数和全失压时间，由上电处理主程序调用"*/
extern	void	Get_AllVoltageLoss_Event_Address_Times(unsigned int *Event_Pointer,				/*"全失压事件记录的RAM指针"*/
											   unsigned char *Event_Number,					/*"本次掉电期间全失压事件记录的条数"*/

											   unsigned long *AllVoltageLoss_Minute_Time);	/*"本次掉电期间全失压发生的时间：分钟"*/

extern void	AllVoltageLoss_SecondCounter_Updating(void);	/*"更新全失压时间(秒)和本次掉电期间的开始和结束的事件记录(RAM中)：
													  		在低功耗的秒中断服务程序中调用"*/
extern unsigned char Check_PD_Curr_Vality(void);//ganjp 20091104
extern struct	ALLVOLTAGELOSS_STRUCTURE AllVoltageLoss_Structure;	
extern void AllVoltageLoss_init_Measure(void);//ganjp 20090325
extern void AllVoltageLoss_Close_Measure(void);//ganjp 20090325
extern void Read_Curr_Powerdown(void);//ganjp 20090325
extern unsigned char Check_Open_power(void);
extern unsigned char Check_All_lossvoltage_Start(void);


extern volatile unsigned long PD_max_curr;//ganjp 20090325
extern unsigned char Curr_Valid_flag;//ganjp 20090325
extern unsigned long AllVoltageLoss_counter;//ganjp 20090330
extern unsigned char Curr_RD_flag;
extern struct   PD_CURRENT_STRUCT  PD_curr;//ganjp 20091103
extern unsigned char L_PD_Last_T;//ganjp 20091103
extern unsigned char lastpdreadcurrtime;   
//extern unsigned char Curr_OK;//ganjp 20091224

extern void Read_Volt_Powerdown(void);

extern struct	PDVOLT_STRUCTURE  pdvoltdata;

#endif 
