/*-------------------------------------------------------------------
Filename:Init_program_LDH.C
Functions:	Initiallize INT1(SPI_DRDY);
			Initiallize RAM buffer used by communication_with_3827.c
--------------------------------------------------------------------*/
#include	"defmcro.h"
#include	"ram.h"
#include	"att7022_operation.h"
#include "Measure_Interface.h" 

void	Disable_INT1(void);
void	Enable_INT1(void);
void	Initiallize_INT1(void);
void	Initiallize_INT3(void);	/*"初始化全失压脉冲中断"*/

void	Disable_INT3(void);		/*"关闭全失压脉冲中断"*/

void	Enable_INT3(void);		/*"打开全失压脉冲中断"*/

void	Init_SIO3(void);							//Initiallize SIO3
void	Initiallize_RAM_Buffer_Used_by_LDH(void);

void	Poweron_Reset_Measuring_Board(void);
void	Initiallize_INT5(void);	/*"初试化激光点亮中断"*/
void	Disable_INT5(void);		/*"关闭激光点亮中断"*/
void	Enable_INT5(void);		/*"打开激光点亮中断"*/

void	Disable_INT7(void);
void	Enable_INT7(void);
void	Initiallize_INT7(void);

/*---------------------------------------------- */
void	Initiallize_INT1(void)
{
			Disable_INT1();
			ifsr1=1;			  //INT1 Interrupt Polarity Switching bit:0--One edge,1--Both edge
			pol_int1ic=0;		//Select falling edge interrupt
			int1ic&=0xF7;		//Clear IR register bit of INT1			
			Enable_INT1();
}

/*---------------------------------------------- */		
void	Disable_INT1(void)
{
			int1ic&=0xF8;		//INT1 IPL=0
}

/*---------------------------------------------- */		
void	Enable_INT1(void)
{
			int1ic|=0x05;		//INT1 IPL=5					
}
/*---------------------------------------------- */		

/*---------------------------------------------- */		
	

/*---------------------------------------------- */		
//void	Init_SIO3(void)				//Initiallize SIO3
//		{							//After Reset S3C=B'01000000,S3BRG=indeterminate
//			/*****
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm30=1;
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm31=0;					//Internal synchronous clock:f8sio
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				//sm32=1;				//Sout3 output disable(high impedance)
//				sm32=0;					//Sout3 output
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				//sm33=0;				// SIO3 funtions as general I/O port
//				sm33=1;					// SOUT3 output,CLK3 function
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm34=0;					//Tx at falling edge,Rx at rising edge
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm35=0;					//LSB first
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm36=1;					//internal clock
//			prc2=1;					//S3C(Control register of SIO3) Write Enable
//				sm37=1;					//Effective when sm33=0:Sout3 initial value="high"
//			*****/	
//			prc2=1;
//			s3c=0xc9;
//
//			//prc2=0;					//S3C(Control register of SIO3) Write Disable
//			
//			s3brg=12;				//Tclk=(12+1)*2*8/10M=20.8uS>15uS (MIN Tclk=15uS)
//		}
		

/*---------------------------------------------- */		
//void	Initiallize_RAM_Buffer_Used_by_LDH(void)
//		{
//			unsigned int i;
//			
//			//flag_comm_3827_status_byte=0;
//			//flag_measuring_operating_byte=0;
//			flag_used_to_check_communication_byte=0;
//			flag_power_direction_byte=0;
//			
//			//checksum_from_measuring_board=0;
//			//reset_measuring_board_starting_time=0;
//			//check_measuring_time_starting_time=0;
//			//SUB_RST_Released_starting_time=0;
//			//SPI_DRDY_Counter_LastTime_Starting_Time=0;
//			//SPI_DRDY_Counter=0;
//			//SPI_DRDY_Counter_LastTime=0;
//			
//			
//			//voltage_scale_parameter=1;			//341,3*220V
//			//current_scale_parameter=0;			//1.5(6)A
//			
//			//Display_Wakeup_Flag=0;				/*"需要显示的低功耗唤醒标志，激光唤醒和#S3唤醒时置位"*/
//			
//			for(i=0;i<180;i++)
//				att7022_data_buffer[i]=0;
//			for(i=0;i<4;i++)
//				{
//					Active_power[i]=0;
//					Reactive_power[i]=0;
//					Visual_power[i]=0;
//					Factor[i]=0;
//					if(i<=2)
//						{
//							Volt[i]=0;
//							Curr[i]=0;
//							Freq[i]=0;
//						}
//				}
//				
//			Voltage_scale=0;
//			Current_scale=0;
//			//Active_power_pulse_constant=0;
//			//Reactive_power_pulse_constant=0;
//			for(i=0;i<9;i++)
//				Meter_soft_adjustment_value[i]=0;
//				
//			Alarm_SwitchToggle_Terminal_Status=0;	/*"报警和跳闸辅助端子状态"*/
//			
//		}



/*---------------------------------------------- */		
////void	Poweron_Reset_Measuring_Board(void)
////		{
////
//////			SUB_RST=0;				//LDH:20050921
//////			Delay_Wait(800);		//800*10uS
//////			SUB_RST=1;		
////		}
		
/*---------------------------------------------- */
void	Initiallize_INT5(void)	/*"初试化激光点亮中断"*/
		{
			Disable_INT5();
			ifsr7=1;			//Select INT5 interrupt,because SI/O4 and INT5 share the same interrupt vector			
			ifsr5=0;			//INT5 Interrupt Polarity Switching bit:0--One edge,1--Both edge
			int5ic&=0xF7;		//Clear IR register bit of INT5			
			Enable_INT5();		/*"打开激光点亮中断"*/
		}
/*---------------------------------------------- */
void	Disable_INT5(void)		/*"关闭激光点亮中断"*/
		{
			//int5ic&=0xF8;		//INT5 IPL=0
			int5ic=0x00;		//INT5 IPL=0
			pol_int5ic=0;		//Select falling edge interrupt
			int5ic=0x00;		//INT5 IPL=0
//			ifsr7=0;			//Select SI/O4 interrupt,because SI/O4 and INT5 share the same interrupt vector
		}
/*---------------------------------------------- */
void	Enable_INT5(void)		/*"打开激光点亮中断"*/
		{
//			ifsr7=1;			//Select INT5 interrupt,because SI/O4 and INT5 share the same interrupt vector
//			int5ic&=0xF7;		//Clear IR register bit of INT5	
			int5ic=0x06;		//INT5 IPL=6
				
		}
		
		
void	Initiallize_INT7(void)
{
			Disable_INT7();
			ifsr31=1;			  //INT1 Interrupt Polarity Switching bit:0--One edge,1--Both edge
			pol_int7ic=0;		//Select falling edge interrupt
			int7ic&=0xF7;		//Clear IR register bit of INT1			
			Enable_INT7();
}
void	Disable_INT7(void)
{
			int7ic&=0xF8;		//INT1 IPL=0
}		
void	Enable_INT7(void)
{
			int7ic|=0x05;		//INT1 IPL=5					
}
		
		 