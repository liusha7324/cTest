/*----------Powerdown_LDH.h-----------------*/
#ifndef	_Powerdown_LDH_h
#define	_Powerdown_LDH_h

//extern	unsigned char Display_Wakeup_Flag;			/*"��Ҫ��ʾ�ĵ͹��Ļ��ѱ�־�����⻽�Ѻ�#S3����ʱ��λ"*/
extern	void	AllVoltageLoss_WakingUp_Counter_Updating(void);		/*INT3:"ȫʧѹ�����жϷ������"*/
extern	void	AllVoltageLoss_PowerDown_Init(void);				/*"����͹���ǰȫʧѹ���ݵĳ�ʼ��"*/
extern	unsigned int AllVoltageLoss_WakingUp_Counter;

extern	void	Laser_Wakeup_Int(void);					//INT5 service routine of M30620FCPFP
extern	void	Powerdown(void);
extern	void	Power_Down_Program(void);
extern	void	Save_Data_for_PowerDown(void);
extern	void	LowPower_Cycle(void);
extern	void	Jmp_Lowpower_Cycle(void);
extern	void	Fill_Vector_Table_in_RAM(void);		/*"�����ж�������RAM��"*/
extern  void	Init_TB1_2(void);
extern void	Prepare_for_Wait_Mode(void);
extern void	Dispose_Interrupt_for_PowerDown(void);
extern void	Dispose_IO_for_PowerDown(void);
extern      void	Switch_to_125KClock(void);   // mw added 2010-04-30 
extern  void	Init_TB0(void);						/*"TB0��ʼ����timer mode,fc32,2ms"*/

#endif
