///extern void	Flash_Led_Pannel(void);							//flash P+,P-,Q+,Q-,Alarm,Battery,Phase_Break,Current_Lose on LED_PANNEL///king chen mark 121214
extern void	Set_or_Clear_LCD_Flash_Flag(void);				/*"��LCD��ʾ��־����ǰ���ޡ�������������ʧѹʧ����𡢵�ر���"*/
extern void	Toggle_Loudspeaker(void);		/*"�Ƿ��б������Ƿ����������"*/
extern void	Output_On_3_In_1_Terminal_Set(unsigned char Call_Condition);	
		/*"����һ�������������λ","�˺���Ӧ����������µ��ã������л�(Call_Condition=1)���������ڵ�(Call_Condition=2)��
		  �ϵ���޸�����һ��������ģʽ��(Call_Condition=0)"*/
//extern void	Output_On_3_In_1_Terminal_Reset(void);	
		/*"����һ�������������λ","�˺���Ӧ����ѭ���е���"*/
extern void	Calculate_Arccos_FA(void);		/*"����,A,B,C�����"*/
extern void	Clear_LCD_Current_Flash_Flag(void);		/*"����������Ia,Ib,Ic��˸��־"*/
extern void	Check_If_Reset_Terminal_Alarm(void);		/*"����Ƿ�ȡ���������ӱ������"*/

extern void SoundAlarmEndCheck(void);  //add by pc 090824
extern void SoundAlarmInit(void);  //add by pc 090824

extern void Check_Voltage_Threshold(void);

extern 	union byte_def Alarm_SwitchToggle_Terminal;
#define	Alarm_SwitchToggle_Terminal_Status	Alarm_SwitchToggle_Terminal.byte	/*"��������բ��������״̬"*/
#define	TimeOrDemandCycle					Alarm_SwitchToggle_Terminal.bit.b0	/*"�����������������������/ʱ��Ͷ�б�־"*/
#define	Error_Alarm							Alarm_SwitchToggle_Terminal.bit.b1	/*"������������������󱨾���־"*/
#define	OverPower_Alarm						Alarm_SwitchToggle_Terminal.bit.b2	/*"��������������������ʱ�����־"*/
#define	OweFee_Alarm						Alarm_SwitchToggle_Terminal.bit.b3	/*"���������������Ƿ�ѱ�����־"*/
#define	Reserve_1							Alarm_SwitchToggle_Terminal.bit.b4	/*"����"*/
#define	Reserve_2							Alarm_SwitchToggle_Terminal.bit.b5	/*"����"*/
#define	OverPower_SwitchOff					Alarm_SwitchToggle_Terminal.bit.b6	/*"��բ�������������������բ��־"*/
#define	OweFee_SwitchOff					Alarm_SwitchToggle_Terminal.bit.b7	/*"��բ�����������Ƿ����բ��־"*/
extern 	unsigned long	Alarm_Terminal_Set_Starting_Time;						/*"�����������ӿ�ʼ��λ��ʱ��"*/
extern unsigned char auxiliary_power_flag;

extern unsigned char	VoltageGreaterThanThreshold_Flag;
extern unsigned char	VoltageGreaterThanCritical_Flag;  //add by pc 081227
extern unsigned char	VoltageGreaterThanICcard_Flag;	//payment
extern const unsigned long P_Flash_Current_Threshold[10];
