/*--------------------------------------------------------------------------
//Powerdown Test Program
---------------------------------------------------------------------------*/
#include		"defmcro.h"
#include		"defdata.h"
#include		"ram.h"
#include		"eeprom.h"
#include		"I2C_operation.h"
#include		"att7022_operation.h"
#include		"HT_1623.h"
#include		"Init_program_LDH.H"
#include		"MB_Keymain.h"
#include                "interrupt.h"
#include                "comm.h"
#include "Measure_Interface.h" 

extern	unsigned char pdmode1;
volatile  unsigned int TB3_counter;   //mw modified 2009-02-12

#define	IR_PULSE_MIN			30						/*"在TIME_INTERVAL (ms)内所计38kHz调制信号的最小脉冲数"*/
#define	TIME_INTERVAL			1024				 		/*"在TIME_INTERVAL (ms)内的时间间隔内至少收到IR_PULSE_MIN个脉冲"*/

void init_TB0_for_pulse(void);

#pragma INTERRUPT Laser_Wakeup_Int			//INT5 service routine of M30620FCPFP
//#pragma INTERRUPT TB3_Int					/*"TB3计数器中断服务程序"*/
#pragma INTERRUPT TB0_Int		
//#pragma INTERRUPT TB1_Int					/*"TB1定时器中断服务程序(fc32,2ms)"*/


void	Dispose_Interrupt_for_PowerDown(void);
void	Dispose_IO_for_PowerDown(void);

void	Prepare_for_Wait_Mode(void);
	

void	Init_TB0(void);						/*"TB0初始化：timer mode,fc32,2ms"*/
void	Init_TB1(void);						/*"TB1初始化：timer mode,fc32,1秒"*/
void	Init_TB3(void);						/*"TB3初始化：event counter mode,初值为IR_PULSE_MIN"*/
void	Init_TB1_2(void);
void	Switch_to_125KClock(void); //mw added 2010-04-30
		
/*-----------------------------------------------------------------------*/
void	Laser_Wakeup_Int(void)			//INT5 service routine of M30620FCPFP
		{
		//mw modified 2010-04-30
		/////////////////////Begin	
	  Disable_INT5();				/*"关闭激光点亮中断"*/
		if(pdmode3 == 0)
		{
		prcr|=0x01;
		cm1=0x20;   /*"BIT7\BIT6和其它125KHZ同"*/ 
		prcr|=0x01;
		cm2=0x02;    
		prcr|=0x01;
		pclkr=0x03;   
		
		prcr|=0x01;
		cm0=0x20; 	/*"最后关主晶振MW "*/	

		prcr=0x00;
		}
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");	
	  asm("nop");
	  asm("nop");
	  asm("nop");
	  asm("nop"); 
	  asm("nop");
	  asm("nop");
	  asm("nop");
	  asm("nop"); 	 	  
    	  	Init_TB0();					/*"TB0初始化：timer mode,fc32,2ms"*/
    	  	Init_TB3();					/*"TB3初始化：event counter mode,初值为IR_PULSE_MIN"*/			    	  				
    	  	//Disable_INT5();				/*"关闭激光点亮中断"*/
		}
		
/*-----------------------------------------------------------------------*/
//void	TB3_Int(void)							/*"TB3计数器中断服务程序(计38kHZ的调制脉冲数)"*/
void	TB0_Int(void)	
		{
		unsigned char Hz_50 = 0;
		if(0xff != IntoPowerDownFlag)
		{
		DEMAND_TIME_SW = 1;
		tabsr &= 0xdf;	
		}
		else
		{
		//BOOLEAN  port_value;
	//pd1_1=1;
	//port_value=p1_1;
	//p1_1=~port_value;	
	Disable_INT5();		
				
			tabsr&=0xdf;				//	
			tbsr&=0xdf;				//		
	               TB3_counter=tb3;			
		       TB3_counter=0x7fff-TB3_counter+1; //for debug
			//if((tb3ic&0x08)==0)			//	
			if((TB3_counter>20)&&(TB3_counter<300))   //mw modified 2010-05-11
			{
				if(Meter_Parameter.parameter1.MeterMode[1].bit.b7 == 0)
				{
				    if((TB3_counter>48)&&(TB3_counter<52))
				   {	
					Hz_50 = 0x5a;
				   }
				}
				if(((TB3_counter>90)&&(TB3_counter<110)) || (0x5a == Hz_50))
				{
					Enable_INT5();						
				}
				else 
				{
					
					 if((pdmode1==0)&&(pdmode2==0)&&(farwakeupreadyflag==0))
					 {
					    farwakeupreadyflag=0x33;
					    keykick=0xff;  //mw modified 2010-05-04
				   }
					
				}
			}
			else 
			{
					Enable_INT5();			
			}
			tb0ic&=0xf7;					/*"清TB0溢出标志"*/
			tb3ic&=0xf7;					/*"清TB3溢出标志"*/
		}
	
		}

/*-----------------------------------------------------------------------*/		
//void	TB1_Int(void)								/*"TB1定时器中断服务程序(fc32,1秒)"*/
//		{
//
//        			Initiallize_INT3();			/*"初始化全失压脉冲中断"*/
//        			Initiallize_INT5();			/*"初试化激光点亮中断"*/
//
//				tabsr&=0xbf;				/*"停止TB1定时器"*/
//				tb1ic=0x00;					/*"清TB1中断请求位，将TB1的中断级别设为0级,关闭TB1定时中断"*/
//
//		}

/*-----------------------------------------------------------------------*/		
void	Init_TB0(void)						/*"TB0初始化：timer mode,fc32,2ms"*/
		{
		if(0xff == IntoPowerDownFlag)
		{
			//tb0mr=0xc0;						/*timer mode,fc32*/
			//tb0=TIME_INTERVAL;				/*"TIME_INTERVAL/1024秒"*/
			//tb0ic=0x06;						/*"清TB0中断请求位，将TB0的中断级别设为0级"*/
			//tabsr|=0x20;					/*"起动TB0定时器"*/
			//@@@@@@@@@@@@@@@@@new 
			tb0mr=0xc0;						
			//tb0=TIME_INTERVAL;	
			tb0=0x3D08;	
			tbcs0=0x09;  //not sure 
			tb0ic=0x06;						
			tabsr|=0x20;					

			//mw modified 2010-04-30
									
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		}
		else
		{
			init_TB0_for_pulse();
		}
					
		}

/*-----------------------------------------------------------------------*/		
void	Init_TB3(void)					/*"TB3初始化：event counter mode,初值为IR_PULSE_MIN"*/
		{

        	
			tb3mr=0x01;						/*event counter mode,count TB3IN falling and rising edges*/
			tb3=0x7FFF;		//mw modified 081113		
			tb3ic=0x00;						/*"清TB3中断请求位，将TB3的中断级别设为6级"*/
			tbsr|=0x20;						/*"起动TB3计数器"*/
			//@@@@@@@@@@@@@@@@@@@ timer mode  500ms 
			//tb3mr=0xC0;						/*timer mode,fc32*/
			//tb3=TIME_INTERVAL;				/*"TIME_INTERVAL"*/
			//tb3ic=0x00;						/*"清TB0中断请求位，将TB0的中断级别设为0级"*/
			//tbsr|=0x20;					
			//@@@@@@@@@@@@@@@@@@@
		}


/*-----------------------------------------------------------------------*/		

/*-----------------------------------------------------------------------*/		
void	Dispose_Interrupt_for_PowerDown(void)
		{
			asm("FCLR	I");	
			
			
			ifsr=0x80;					/*"中断向量8对应的中断源为INT5"*/
			ifsr2a=0x00;				/*"中断向量7对应的中断源为TB3"*/
			
			u0mr&=0xf8;					/*"串口0变为普通I/O口"*/
			u1mr&=0xf8;					/*"串口1变为普通I/O口"*/
			u2mr&=0xf8;					/*"串口2变为普通I/O口"*/
                        
            prcr|=0x04;					//PRC2=1,SI/O3,SI/O4 control register write enable
            sm33=0;						//SI/O3 Port becomes Input/output port
            prcr|=0x04;					//PRC2=1,SI/O3,SI/O4 control register write enable
            sm43=0;						//SI/O4 Port becomes Input/output port			
			
			ta1mr=0x23;					/*"TA1OUT变成普通IO口"*/
			ta0ic=0x00;					/*"禁止TA0中断"*/
			ta1ic=0x00;					/*"禁止TA1中断"*/
			ta2ic=0x00;					/*"禁止TA2中断"*/
			ta3ic=0x00;					/*"禁止TA3中断"*/
			ta4ic=0x00;					/*"禁止TA4中断"*/
			tb0ic=0x00;					/*"禁止TB0中断"*/
			tb1ic=0x00;					/*"禁止TB1中断"*/
			tb2ic=0x00;					/*"禁止TB2中断"*/
			tb3ic=0x00;					/*"禁止TB3中断"*/
			tb4ic=0x00;					/*"禁止TB4中断"*/
			tb5ic=0x00;					/*"禁止TB5中断"*/
			
			s0tic=0;					/*"串口0的发送中断级别置为0,IR=0"*/
			s1tic=0;					/*"串口1的发送中断级别置为0,IR=0"*/
			s2tic=0;					/*"串口2的发送中断级别置为0,IR=0"*/
			
			s0ric=0;					/*"串口0的接收中断级别置为0,IR=0"*/
			s1ric=0;					/*"串口1的接收中断级别置为0,IR=0"*/
			s2ric=0;					/*"串口2的接收中断级别置为0,IR=0"*/
			
			s3ic=0;						/*"SIO3的中断级别置为0,IR=0"*/
			s4ic=0;						/*"SIO4的中断级别置为0,IR=0"*/	
					
			int0ic=0;					/*"INT0的中断级别置为0,IR=0"*/
			int1ic=0;					/*"INT1的中断级别置为0,IR=0"*/
			int2ic=0;					/*"INT2的中断级别置为0,IR=0"*/
			int3ic=0;					/*"INT3(全失压信号)的中断级别置为0,IR=0"*/
			int4ic=0;					/*"INT4的中断级别置为0,IR=0"*/
			int5ic=0;					/*"INT5(激光点亮信号)的中断级别置为0,IR=0"*/
			
			kupic=0;					/*"键盘中断的中断级别置为0,IR=0"*/
			
			
			u5mr&=0xf8;		/*"串口5/6/7变为普通I/O口"*/
					u6mr&=0xf8;		
					u7mr&=0xf8;  
					int6ic=0;	         /*"禁止INT6/INT7"*/
					int7ic=0;
					pcr6=0;  //change by pc 121218
									
		}



/*"---刚刚掉电(电容还有电)---------"*/
void	Dispose_IO_for_PowerDown(void)
		{
		
		    PULSE_PWR=0;            /*"关闭计量电源"*/

        pd0=0xE1;               /*"先使A_DIR,R_DIR,A_EOUT,R_EOUT变为输入状态，以免掉电时出脉冲"*/   
///////	FLASH_CS           	p0_0	//
///////	RELAY_TYPE_SEL  	p0_1	//
///////	A_EOUT                   p0_2	// 
///////	R_EOUT                   p0_3	// 
///////	TDK71M6515_SIG_PORT         p0_4	// 
///////	SWITCH(CLOSE)   	p0_5	/*"内置继电器关"*/	// payment
///////	TDK71M6515_RESET_PORT       p0_6	//Reset mesuring ATT7022
///////	TDK71M6515_CS_PORT          p0_7	//Chip_Select mesuring ATT7022 
        p0=0x00;
          

        pd1=0x0B;	//0x4F	  
////////IC_CLK/CPU_CLK  	p1_0 
////////LED_ALARM          		p1_1  
////////CUPCARD_RXD    		p1_2	 
////////CUPCARD_TXD     		p1_3
////////J1                       p1_4   //Meter_Clear and Meter_Calibration Jump
////////ALL_V_LOSS               p1_5   //All_Voltage_Loss Signal 
////////SWITCH_CLEW           p1_6   /*"继电器状态指示灯"*/	//payment
////////LASER_WKP                p1_7 	//Laser Wakeup
        p1=0x08;

        pd2=0x0d;    //0x3d           //p2_1 dispose 2010-04-21 output 0, old is 0x1d 
        //ESAM_PWR                  p2_0
        //magic_detect1                       p2_1  //p2_1 dispose 2010-04-21 
        //SCL_LCD                   p2_2  //p2_2 dispose 2010-04-21 
        //Back_Light_On                 p2_3  //p2_3 dispose 2010-04-21 output 0,same as before 
        //magic_detect2                 p2_4     //p2_4  dispose 2010-04-21 
        //Event_DIS->railcover_open_detect               p2_5		//carry	//OFF
        //A_EOU1->lowpower_battary_volt                   p2_6	//
        //R_EOU1->clock_battary_volt                   p2_7	//
        p2=0x00;
            
        pd3=0xEc;
        //RTC1_SDA                 p3_0                                                                                                                                                                                                                                                                                                                           
        //RTC1_SCL                 p3_1                                                                                                                                                                                                                                                                                                                           
        //MEM_PWR                  p3_2   /*"内卡电源控制"*/                                                                                                                                                                                                                                                                                            
        //ALARM_SND                p3_3   /*"蜂鸣器控制"*/                                                                                                                                                                                                                                                                                             
        //SWITCH(OPEN)->relay_status    	p3_4	/*"内置继电器关/外置继电器驱动"*/	//payment
        //ALARM          		p3_5     	/*"报警继电器驱动"*/
        //SEC_DEM_CTR                p3_6   //p3_6  dispose 2010-04-21                                                                                                                                                                                                                                        
        //DEMAND                   p3_7	//Demand_cycle signal                                                                                                                                                                                                                                                                          
        p3=0x04;                   //arthor2007-04-17 p3=0x00;
           
      	pd4=0x9F;	//0xff	//11.06				
       //IC_PWR                	p4_0	//IC card interfacor power control	//payment
       //IC_RST                 	p4_1    
       //NC ->mk_event        p4_2    
       //PSAM_RST              	p4_3    
       //HT1623_CS             	p4_4  	//HT1623_CS  
       //IC_SW                  	p4_5	//IC card is presen or absent.
       //PSAM_RXD             	p4_6
       //PSAM_TXD             	p4_7	
     	p4=0x80; 
        	
        pd5=0xCF;													
        //VBB                      p5_0   //Allways connect to Vbb 
        //VB1_OK                   p5_1	  //Status of RTC1's battery
        //PULSE_PWR->NC                p5_2	  /*"计量7022和脉冲电源控制"*/ 
        //VB3_OK1                  p5_3	  //External battery's status (circuit_short test)
        //CARD_RX                      p5_4   //Allways connect to GND
        //VSS                      p5_5   //Allways connect to GND
        //MEM_SCL                  p5_6    
        //MEM_SDA                  p5_7    
        p5=0x00;
        	
        pd6=0xbb;
        //MEM_WP                   p6_0    
        //RE_DE0                   p6_1	//Tx/Rx control of 1st RS485
        //RXD0                     p6_2    
        //TXD0                     p6_3    
        //WDI                      p6_4   //Updating signal of Watchdog chip 
        //RE_DE2                   p6_5	//Tx/Rx control of 2st RS485
        //RXD1                     p6_6    
        //TXD1                     p6_7    
        p6=0xbb;		            /*"TXD0和TXD1必须输出高电平"*/
        	
        pd7=0xFD;			
        //TXD2                     p7_0    
        //RXD2                     p7_1    
        //PWM                      p7_2	  //38.4kHz signal used to modify ir remote transmit 
        //IR_FAR_PWR            p7_3   //IR_FAR_PWR dispose 2010-04-21 
        //SDA_LCD                  p7_4    
        //7022_CF1                 p7_5    
        //PSAM_CLK                p7_6 	//payment
        //7022_CF2->NC                 p7_7
        p7=0x01;
        	
        pd8=0xC5;  //old is 0xCD;	           //P8_6 dispose 2010-04-21    //P8_7 dispose 2010-04-21   
        //LCD_POWER               p8_0  //p8_0 dispose 2010-04-21 
        //REMOTE_CONTROL_IN        p8_1	/*"遥控器输入"*/ 
        //SECONG_PULSE             p8_2	//Second Pulse from DS1375 
        //NC->meter_cover_open_detect                        p8_3    //P8_3 dispose 2010-04-21
        //V_D                      p8_4 //Power_Drop Signal 
        //VCC1                     p8_5	//Always connected to VBB 
        //NC                    p8_6    //P8_6 dispose 2010-04-21 output 0, old is input 
        //NC                     p8_7     //P8_7 dispose 2010-04-21 output 0, old is input 
        p8=0x01;
        
        	
        
        prcr|=0x04;		           /*"必须加这1句"*/
        pd9=0xF7;                  /*"使p9_3(TB3IN)为输入脚"*/
        //7022_SCK                 p9_0   
        //7022_SDI                 p9_1   
        //7022_SDO                 p9_2   
        //PULSE_WID_MESURE         p9_3/*"接38kHz手抄器信号"*/  
        //DB161_CS ->CF2                p9_4   
        //DB161_SCK                p9_5   
        //DB161_SI                 p9_6   
        //DB161_SO                 p9_7   
        p9=0x00;

	      p10_0=0;
        pd10=0x83;                 /*"#S1和#S3必须为输入"*/
        //DB161_RDY->SWITCH_TOGGLE                p10_0	                                    
        //NC                       p10_1	//OPTICAL_HEADER prsent sensor      
        //KEY6 ->A_EOU1                    p10_2	//RAIL_COVER SENSOR                 
        //KEY5 ->R_EOU1                    p10_3	//SEALED_COVER SENSOR               
        //KEY1                     p10_4	//#S1 PUSHBUTTON                    
        //KEY2->MK_SET                     p10_5	//#S2 PUSHBUTTON                    
        //KEY3                     p10_6	//#S3 PUSHBUTTON                    
        //KEY4->PULSE_PWR                     p10_7	//#S4 PUSHBUTTON(SEALED PUSHBUTTON)
        p10=0x00;
         
        pu20=0;
        pu15=0;
        pu16=0;

        adst    = 0; /*"单次AD，进入低功耗下时将AD采样关闭"*/
        adstby =0;
		}



/*"----完全掉电的情况------------------------------------------------"*/

void	Prepare_for_Wait_Mode(void)
		{
		
        pd0=0xed;
///////	IR_FAR_EN->FLASH_CS           	p0_0	//
///////	RELAY_TYPE_SEL  	p0_1	//
///////	A_EOUT                   p0_2	// 
///////	R_EOUT                   p0_3	// 
///////	TDK71M6515_SIG_PORT         p0_4	// 
///////	SWITCH(CLOSE)   	p0_5	/*"内置继电器关"*/	// payment
///////	TDK71M6515_RESET_PORT       p0_6	//Reset mesuring ATT7022
///////	TDK71M6515_CS_PORT          p0_7	//Chip_Select mesuring ATT7022 
        p0=0x00;  
        	
        pd1=0x5F;
////////IC_CLK/CPU_CLK  	p1_0 	//payment
////////LED_ALARM          		p1_1  
////////CUPCARD_RXD    		p1_2	 
////////CUPCARD_TXD     		p1_3
////////J1                       p1_4   //Meter_Clear and Meter_Calibration Jump
////////ALL_V_LOSS               p1_5   //All_Voltage_Loss Signal 
////////SWITCH_CLEW           p1_6   /*"继电器状态指示灯"*/	//payment
////////LASER_WKP                p1_7 	//Laser Wakeup
        p1=0x00;
        	
        pd2=0x0D;    //0xff              
        //TIME_SW                  p2_0
        //NC->MAGIC_DETECT1                       p2_1  //p2_1 dispose 2010-04-21 
        //SCL_LCD                   p2_2  //p2_2 dispose 2010-04-21 
        //Back_Light_On                  p2_3  //p2_3 dispose 2010-04-21 output 0,same as before 
        //CAL_WP->MAGIC_DETECT2                  p2_4    //p2_4  dispose 2010-04-21 
        //Event_DIS->RAIL_COVER_DETECT               p2_5		//carry
        //A_EOU1-> LOWPWER_BATTARY_DETECT                  p2_6	//
        //R_EOU1->CLOCK_BATTARY_DETECT                   p2_7	//
        p2=0x00;
            
        pd3=0xEC;
        //RTC1_SDA                 p3_0                                                                                                                                                                                                                                                                                                                           
        //RTC1_SCL                 p3_1                                                                                                                                                                                                                                                                                                                           
        //MEM_PWR                  p3_2   /*"内卡电源控制"*/                                                                                                                                                                                                                                                                                            
        //ALARM_SND                p3_3   /*"蜂鸣器控制"*/                                                                                                                                                                                                                                                                                             
        //SWITCH(OPEN) ->REALY_STATUS   	p3_4	/*"内置继电器关/外置继电器驱动"*/	//payment
        //ALARM          		p3_5     	/*"报警继电器驱动"*/
        //SEC_DEM_CTR                p3_6	   //p3_6  dispose 2010-04-21                                                                                                                                                                                      
        //DEMAND                   p3_7	//Demand_cycle signal                                                                                                                                                                                                                                                                          
        p3=0x00;
           
        pd4=0xDF;
       //IC_PWR                	p4_0	//IC card interfacor power control	//payment
       //IC_RST                 	p4_1    
       //NC ->MK_EVENT                		p4_2    
       //PSAM_RST              	p4_3    
       //HT1623_CS             	p4_4  	//HT1623_CS  
       //IC_SW                  	p4_5	//IC card is presen or absent.
       //PSAM_RXD             	p4_6
       //PSAM_TXD             	p4_7	
        p4=0x00; 
        	
        pd5=0xFE;													
        //VBB                      p5_0   //Allways connect to Vbb 
        //VB1_OK                   p5_1	  //Status of RTC1's battery
        //PULSE_PWR->NC                p5_2	  /*"计量7022和脉冲电源控制"*/ 
        //VB3_OK1                  p5_3	  //External battery's status (circuit_short test)
        //VSS                      p5_4   //Allways connect to GND
        //VSS                      p5_5   //Allways connect to GND
        //MEM_SCL                  p5_6    
        //MEM_SDA                  p5_7    
        p5=0x00;
        	
        pd6=0xFF;
        //MEM_WP                   p6_0    
        //RE_DE0                   p6_1	//Tx/Rx control of 1st RS485
        //RXD0                     p6_2    
        //TXD0                     p6_3    
        //WDI                      p6_4   //Updating signal of Watchdog chip 
        //RE_DE2                   p6_5	//Tx/Rx control of 2st RS485
        //RXD1                     p6_6    
        //TXD1                     p6_7    
        p6=0x00;		            
        	
        pd7=0xFF;			
        //TXD2                     p7_0    
        //RXD2                     p7_1    
        //PWM                      p7_2	  //38.4kHz signal used to modify ir remote transmit 
        //IR_FAR_PWR            p7_3    //IR_FAR_PWR dispose 2010-04-21 
        //SDA_LCD                  p7_4    
        //7022_CF1                 p7_5    
        //PSAM_CLK                p7_6 	//payment
        //7022_CF2->NC                 p7_7
        p7=0x00;
        	
        pd8=0xC7;  //old is 0xCF;	      //P8_6 dispose 2010-04-21 //P8_7 dispose 2010-04-21          
        //LCD_POWER               p8_0	  //p8_0 dispose 2010-04-21 
        //REMOTE_CONTROL_IN        p8_1	/*"遥控器输入"*/ 
        //SECONG_PULSE             p8_2	//Second Pulse from DS1375 
        //NC->METER_COVER_OPEN_DETECT                         p8_3    //P8_3 dispose 2010-04-21
        //V_D                      p8_4 //Power_Drop Signal 
        //VCC1                     p8_5	//Always connected to VBB 
        //NC                    p8_6     //P8_6 dispose 2010-04-21 output 0,old is input 
        //NC                     p8_7     //P8_7 dispose 2010-04-21 
        p8=0x00;		  
        	
        prcr|=0x04;		           /*"必须加这1句"*/
        pd9=0xF7;                  /*"使p9_3(TB3IN)为输入脚"*/
        //7022_SCK                 p9_0   
        //7022_SDI                 p9_1   
        //7022_SDO                 p9_2   
        //PULSE_WID_MESURE         p9_3/*"接38kHz手抄器信号"*/  
        //DB161_CS->CF2                 p9_4   
        //DB161_SCK                p9_5   
        //DB161_SI                 p9_6   
        //DB161_SO                 p9_7   
        p9=0x00;
        	
        pd10=0xa3;                 /*"#S1和#S3必须为输入"*/
        //0x83
        //DB161_RDY->SWITCH_TOGGLE                p10_0	                                    
        //NC                       p10_1	//OPTICAL_HEADER prsent sensor      
        //KEY6->A_EOU1                     p10_2	//RAIL_COVER SENSOR                 
        //KEY5->R_EOU1                     p10_3	//SEALED_COVER SENSOR               
        //KEY1                     p10_4	//#S1 PUSHBUTTON                    
        //NC->MK_SET                     p10_5	//#S2 PUSHBUTTON                    
        //KEY3                     p10_6	//#S3 PUSHBUTTON                    
        //KEY4->PULSE_PWR                     p10_7	//#S4 PUSHBUTTON(SEALED PUSHBUTTON)
        p10=0x00;  						        	     
		} 
		


void	Switch_to_125KClock(void)			
	{
		/////////////////////Begin	       
		prcr|=0x01;
		//cm1=0x80;   
		cm1=0x20;   /*"125k低功耗模式"*/ 
		//cm1=0x00;   /*"125k非低功耗模式"*/ 		
		prcr|=0x01;
		cm2=0x02;    
		prcr|=0x01;
		pclkr=0x03;   
		
		prcr|=0x01;
		//cm0=0x24;    
		cm0=0x20; 	/*"最后关主晶振MW "*/	

		prcr=0x00;
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");	
		/////////////////////END
        }



void init_TB0_for_pulse(void)
{
   tb0ic=0x00;
	
   tb0mr=0x80;
  
   tb0=0x61a7;
   //tbsr|=0x80;
   tb0ic=0x03;
}

