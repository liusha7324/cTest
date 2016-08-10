///extern void	Flash_Led_Pannel(void);							//flash P+,P-,Q+,Q-,Alarm,Battery,Phase_Break,Current_Lose on LED_PANNEL///king chen mark 121214
extern void	Set_or_Clear_LCD_Flash_Flag(void);				/*"置LCD显示标志：当前象限、电流反向和相别、失压失流相别、电池报警"*/
extern void	Toggle_Loudspeaker(void);		/*"是否有报警，是否输出声报警"*/
extern void	Output_On_3_In_1_Terminal_Set(unsigned char Call_Condition);	
		/*"三合一辅助端子输出置位","此函数应在下列情况下调用：费率切换(Call_Condition=1)和需量周期到(Call_Condition=2)、
		  上电和修改三合一辅助端子模式字(Call_Condition=0)"*/
//extern void	Output_On_3_In_1_Terminal_Reset(void);	
		/*"三合一辅助端子输出复位","此函数应在主循环中调用"*/
extern void	Calculate_Arccos_FA(void);		/*"求总,A,B,C的相角"*/
extern void	Clear_LCD_Current_Flash_Flag(void);		/*"清电流反向和Ia,Ib,Ic闪烁标志"*/
extern void	Check_If_Reset_Terminal_Alarm(void);		/*"检查是否取消辅助端子报警输出"*/

extern void SoundAlarmEndCheck(void);  //add by pc 090824
extern void SoundAlarmInit(void);  //add by pc 090824

extern void Check_Voltage_Threshold(void);

extern 	union byte_def Alarm_SwitchToggle_Terminal;
#define	Alarm_SwitchToggle_Terminal_Status	Alarm_SwitchToggle_Terminal.byte	/*"报警和跳闸辅助端子状态"*/
#define	TimeOrDemandCycle					Alarm_SwitchToggle_Terminal.bit.b0	/*"报警辅助端子输出需量周期/时段投切标志"*/
#define	Error_Alarm							Alarm_SwitchToggle_Terminal.bit.b1	/*"报警辅助端子输出错误报警标志"*/
#define	OverPower_Alarm						Alarm_SwitchToggle_Terminal.bit.b2	/*"报警辅助端子输出超功率报警标志"*/
#define	OweFee_Alarm						Alarm_SwitchToggle_Terminal.bit.b3	/*"报警辅助端子输出欠费报警标志"*/
#define	Reserve_1							Alarm_SwitchToggle_Terminal.bit.b4	/*"保留"*/
#define	Reserve_2							Alarm_SwitchToggle_Terminal.bit.b5	/*"保留"*/
#define	OverPower_SwitchOff					Alarm_SwitchToggle_Terminal.bit.b6	/*"跳闸辅助端子输出超功率跳闸标志"*/
#define	OweFee_SwitchOff					Alarm_SwitchToggle_Terminal.bit.b7	/*"跳闸辅助端子输出欠费跳闸标志"*/
extern 	unsigned long	Alarm_Terminal_Set_Starting_Time;						/*"报警辅助端子开始置位的时间"*/
extern unsigned char auxiliary_power_flag;

extern unsigned char	VoltageGreaterThanThreshold_Flag;
extern unsigned char	VoltageGreaterThanCritical_Flag;  //add by pc 081227
extern unsigned char	VoltageGreaterThanICcard_Flag;	//payment
extern const unsigned long P_Flash_Current_Threshold[10];
