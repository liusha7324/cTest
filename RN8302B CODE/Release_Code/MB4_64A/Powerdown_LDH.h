/*----------Powerdown_LDH.h-----------------*/
#ifndef	_Powerdown_LDH_h
#define	_Powerdown_LDH_h

//extern	unsigned char Display_Wakeup_Flag;			/*"需要显示的低功耗唤醒标志，激光唤醒和#S3唤醒时置位"*/
extern	void	AllVoltageLoss_WakingUp_Counter_Updating(void);		/*INT3:"全失压脉冲中断服务程序"*/
extern	void	AllVoltageLoss_PowerDown_Init(void);				/*"进入低功耗前全失压数据的初始化"*/
extern	unsigned int AllVoltageLoss_WakingUp_Counter;

extern	void	Laser_Wakeup_Int(void);					//INT5 service routine of M30620FCPFP
extern	void	Powerdown(void);
extern	void	Power_Down_Program(void);
extern	void	Save_Data_for_PowerDown(void);
extern	void	LowPower_Cycle(void);
extern	void	Jmp_Lowpower_Cycle(void);
extern	void	Fill_Vector_Table_in_RAM(void);		/*"重置中断向量表到RAM中"*/
extern  void	Init_TB1_2(void);
extern void	Prepare_for_Wait_Mode(void);
extern void	Dispose_Interrupt_for_PowerDown(void);
extern void	Dispose_IO_for_PowerDown(void);
extern      void	Switch_to_125KClock(void);   // mw added 2010-04-30 
extern  void	Init_TB0(void);						/*"TB0初始化：timer mode,fc32,2ms"*/

#endif
