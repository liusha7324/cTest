/*-------------------------------------------------------------------
Filename:AllVoltageLoss.h
Functions:	Declare the variable and functions defined in
			AllVoltageLoss.c as "extern". 
--------------------------------------------------------------------*/
#ifndef	_AllVoltageLoss_h
#define	_AllVoltageLoss_h

#define     PDOPEN6515RELAYTIME 102

extern	void	AllVoltageLoss_WakingUp_Counter_Updating(void);	/*INT3:"ȫʧѹ�����жϷ������"*/
/*"ȡ��ȫʧѹ�¼���¼��ַ��������ȫʧѹʱ�䣬���ϵ紦�����������"*/
extern	void	Get_AllVoltageLoss_Event_Address_Times(unsigned int *Event_Pointer,				/*"ȫʧѹ�¼���¼��RAMָ��"*/
											   unsigned char *Event_Number,					/*"���ε����ڼ�ȫʧѹ�¼���¼������"*/

											   unsigned long *AllVoltageLoss_Minute_Time);	/*"���ε����ڼ�ȫʧѹ������ʱ�䣺����"*/

extern void	AllVoltageLoss_SecondCounter_Updating(void);	/*"����ȫʧѹʱ��(��)�ͱ��ε����ڼ�Ŀ�ʼ�ͽ������¼���¼(RAM��)��
													  		�ڵ͹��ĵ����жϷ�������е���"*/
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
