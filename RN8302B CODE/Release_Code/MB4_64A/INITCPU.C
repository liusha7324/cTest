#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "multi.h"
#include "initram.h"
#include "att7022_operation.h"
#include "Measure_Interface.h" 
/*"and bu trend 2004-12-08"*/
#include "MB_Showmain.h"
#include "MB_Keymain.h"
#include "Powerdown_LDH.h"

#include "ICcard.h"	//payment


void    InitTimeA0(void);
void    InitMainRegeist(void);
void	InitPort(void); 
void    InitInterrupt(void);
//void	IniEeprom(void);
void    IniUART(void);
void	IniBoad(void); 
//void    IniMeasure(void);   
void    Initrcpps(void); 
void    CheckEeprom(void);
void    InitTimeA2_PowerDown(void);
void InitTimeA3(void);


unsigned char PDFlagRam1[15]; 
unsigned char EEpromErrNum[4];
union  BYTE_BIT Eeprom_Flag;



void InitPort(void)
{
	p0_5=0;
	pd0=0xed;    	// payment
///////	IR_FAR_EN		p0_0	//
///////	RELAY_TYPE_SEL	p0_1				//payment
///////	A_EOUT               	p0_2	// high
///////	R_EOUT              	p0_3	// high
///////	TDK71M6515_SIG_PORT         p0_4	// 
///////	SWITCH(CLOSE)	p0_5	//
///////	TDK71M6515_RESET_PORT       p0_6	//Reset mesuring ATT7022
///////	TDK71M6515_CS_PORT          p0_7	//Chip_Select mesuring ATT7022 
        p0=0xdf;

	getRelayType();		//payment
        
        pd1=0x4B;		 /*"空脚P10,P16必须输出低电平，SCL_LCD输出高电平"*/  
////////IC_CLK/CPU_CLK 	p1_0 
////////LED_ALARM          	p1_1  
////////CUPCARD_RXD    	p1_2	 
////////CUPCARD_TXD     	p1_3	  
////////J1                       	p1_4   //Meter_Clear and Meter_Calibration Jump
////////ALL_V_LOSS         	p1_5   //All_Voltage_Loss Signal 
////////SWITCH_CLEW     	p1_6   /*"继电器状态指示灯"*/	//payment
////////LASER_WKP          	p1_7 	//Laser Wakeup
        p1=0x48;///king chen modify 121214

        pd2=0x0d;                  /*"空脚P25必须输出低电平，CAL_SCL,CAL_SDA输出高电平"*/
        //NC                  p2_0
        //J10_                     p2_1
        //SCL_LCD                   p2_2
        //BACK_LIGHT_PWR                  p2_3
        //CAL_SDA                  p2_4
        //Event_DIS                 p2_5	//
        //A_EOU1                   p2_6	//
        //R_EOU1                   p2_7	//
	      p2=0x1C;

	      //p3_4=0;
	      pd3=0xec;
        //RTC1_SDA                 p3_0                                                                                                                                                                                                                                                                                                                           
        //RTC1_SCL                 p3_1                                                                                                                                                                                                                                                                                                                           
        //MEM_PWR                  p3_2   /*"内卡电源控制"*/                                                                                                                                                                                                                                                                                            
        //ALARM_SND                p3_3   /*"蜂鸣器控制"*/                                                                                                                                                                                                                                                                                             
        //SWITCH(OPEN)    	p3_4	//
        //ALARM          		p3_5                                                                                                                                                                                                                                                                                                     
        //SECOND_EN                p3_6	//Enable second pulse to output from auxiliary terminals (#15,#16)                                                                                                                                                                                                                                                      
        //DEMAND_TIME_SW                   p3_7	//Demand_cycle signal                                                                                                                                                                                                                                                                          
	p3=0xC0;

       pd4=0xBF;					
       //IC_PWR                	p4_0	//IC card interfacor power control	//payment
       //IC_RST                 	p4_1    
       //event_out                 	p4_2    
       //PSAM_RST              	p4_3    
       //HT1623_CS             	p4_4  	//HT1623_CS  
       //IC_SW                  	p4_5	//IC card is presen or absent.
       //PSAM_RXD             	p4_6
       //PSAM_TXD             	p4_7	
	p4=0x90;
	
        pd5=0xD4;													
        //VBB                      p5_0   //Allways connect to Vbb 
        //VB1_OK                   p5_1	  //Status of RTC1's battery
        //NC                p5_2	  /*"计量7022和脉冲电源控制"*/ 
        //VB3_OK1                  p5_3	  //External battery's status (circuit_short test)
        //CARD_RX /RST_ZB                 p5_4   //Allways connect to GND
        //VSS                      p5_5   //Allways connect to GND
        //MEM_SCL                  p5_6    
        //MEM_SDA                  p5_7    
        p5=0xD0;					
        
        pd6=0xbb;
        //MEM_WP                   p6_0    
        //RE_DE0                   p6_1	//Tx/Rx control of 1st RS485
        //RXD0                     p6_2    
        //TXD0                     p6_3    
        //WDI                      p6_4   //Updating signal of Watchdog chip 
        //RE_DE2                   p6_5	//Tx/Rx control of 2st RS485
        //RXD1                     p6_6    
        //TXD1                     p6_7    
        p6=0xbb;		/*"TXD0和TXD1必须输出高电平"*/
        
        pd7=0xDd;			
        //TXD2                     p7_0    
        //RXD2                     p7_1    
        //PWM                      p7_2	//38.4kHz signal used to modify ir remote transmit 
        //IR_FAR_SELECT/IR_FAR_PWR  p7_3   //0:select IR_FAR Rx,1:select OPTICAL_HEADER Rx
        //SDA_LCD                  p7_4    
        //7022_CF1                 p7_5    
        //ESAM_CLK                p7_6 
        //7022_CF2                 p7_7
        p7=0x51;
        
        pd8=0xC1;	                /*"遥控器输入应该变为输入脚"*/
        //0x01;
        //IR_FAR_PWR /LCD_PWR              p8_0	//IR_FAR and IIC memory CARD circuit power control
        //REMOTE_CONTROL_IN        p8_1	/*"遥控器输入"*/ 
        //SECONG_PULSE             p8_2	//Second Pulse from DS1375 
        //NC                        p8_3
        //V_D                      p8_4 //Power_Drop Signal 
        //VCC1                     p8_5	//Always connected to VBB 
        //XCOUT                    p8_6    
        //XCIN                     p8_7    
        p8=0xC1;		  /*"有电时LCD_PWR输出低电平"*/
        //0x01;
        
        prcr|=0x04;		  /*"必须加这1句"*/
        pd9=0x65;
        //7022_SCK                 p9_0   
        //7022_SDI                 p9_1   
        //7022_SDO                 p9_2   
        //PULSE_WID_MESURE         p9_3/*"接38kHz手抄器信号"*/  
        //DB161_CS  / 7022_CF2     p9_4   
        //DB161_SCK                p9_5   
        //DB161_SI                 p9_6   
        //DB161_SO                 p9_7   
        p9=0x00;                        

	 p10_0 = 0;
        pd10=0xAd;	//0x22
        //SWITCH(OPEN)                p10_0	                                    
        //STA                    p10_1	//CARRIER STA CHECK
        //KEY6                     p10_2	//RAIL_COVER SENSOR                 
        //KEY5                     p10_3	//SEALED_COVER SENSOR               
        //KEY1                     p10_4	//#S1 PUSHBUTTON                    
        //NC                     p10_5	//#S2 PUSHBUTTON                    
        //KEY3                     p10_6	//#S3 PUSHBUTTON                    
        //KEY4                     p10_7	//#S4 PUSHBUTTON(SEALED PUSHBUTTON)
        p10=0xA0; 					
        
        
        pu15=pu16=1;  //pu15:P6_4 to P6_7 Pull-Up UART1
                      //pu16:P7_0 to P7_3 Pull-Up UART2
}


void InitTimeA0(void)
{
	ta0mr=0;
	ta0=0xc350;     //(f1/n+1);
	//udf&=0xfe;
	tabsr|=0x01;
	ta0ic=0x03;
}

void InitTimeA2_PowerDown(void)
{
	//mw modified 2010-04-30

	
	//ta2mr=0xC0;
        //ta2=0x03FF;
        //ta2s=0;
        //ta2ic=0x03;
	//@@@@@@@@@@@@@@@
	ta2mr=0xC0;
	tacs1=0x0D;
	ta2=0xF423;
        ta2s=0;
        ta2ic=0x03;
	//@@@@@@@@@@@@@@@	
}

/*"****ESAM CLK****"*/
void InitTimeA3(void)	//payment
{
//	  ta3mr=0x01;//ganjp 20090213 old is 0x09
//	  ta3=FRE_CONST_Q;                 /*"无功脉冲分频系数"*/
//	  //prcr|=0x04;
//	  //udf&=0xf7;
//	  udf=0;
//	  trgsr&=0xcf;
//	  ta3ic=0x07;

      ta3mr=0x04; /*"定时器模式"*/
      ta3=0;                 /*"10M 2分频"*/
      udf=0;
//     trgsr&=0xcf;
      ta3ic=0x00; /*"禁止中断"*/
}

void InitMainRegeist(void)
{
	prcr|=0x02;
	pm0=0xc0;         //single chip mode,PM03 is soft reset bit
	prcr|=0x02;
	pm1=0x0B;         //PM12 is whach dog bit,0-interrupt,1-reset
	prcr=0x00;
	
	prcr|=0x01;
	cm0=0x00;         //b0b1:0 0 : I/O port P5_7,
	                  //b2:0 : Do not stop peripheral function clock in wait mode
	                  //b3:XCIN-XCOUT Drive 0 : LOW
	                  //b4:0 : XCIN-XCOUT generation function
	                  //b5:Main Clock Stop Bit 0 : On
	                  //b6:Main Clock Division,0 : CM16 and CM17 valid
	                  //b7:System Clock Select Bit,0 : Main clock,
	prcr|=0x01;
	cm1=0x30;         //b0:0 : Clock on
	                  //b1:0 : Main clock
	                  //b2b3b4:000
	                  //b5:XIN-XOUT Drive Capacity,1 : HIGH
	                  //b6b7:Main Clock Division,0 0 : No division mode
	prcr|=0x01;
	cm2=0x00;         //b1:System Clock,0: Main clock or PLL clock
	prcr|=0x01;
	pclkr=0x03;       //b1:Timers A, B Clock Select,1 : f1
	                  //b2:SI/O Clock Select Bit,1 : f1
	prcr=0x00;
	
	pm1=0x0B;      //pm10=1  /*"数据闪存有效位"*/
cm1=0x30;      //CM14=1  125kHz on-chip oscillator off
			pcr=0x60;      //key input enable  INT6/INT7disable  CEC output disable 
u5c0=0x18;     /*"禁止CTS/RTS功能"*/
u6c0=0x18;
u7c0=0x18;
			prcr|=0x40;  
			prg2c=0x00;    /*"程序ROM2有效"*/
      		u5mr&=0xf8;	 /*"串口变为普通I/O口"*/
			u6mr&=0xf8;		
			u7mr&=0xf8;   

	
}
void InitInterrupt(void)
{
	s0ric=0x03;
	s0tic=0x03;
	s1ric=0x03;
	s1tic=0x03;
	s2ric=0x03;
	s2tic=0x03;
	InitTimeA0();
	InitTimeA3();
	//////ATT7022B//////
	Init_Relation_Meter_Apply();
	//////ATT7022B//////
	//InitTimeA2();
	Initrcpps();
	Init_TB0();
	
	pcr6=1;  //change by pc 121218
	int7ic&=0xF8;
	int1ic&=0xF8;
	
	int2ic = 0x01;
	ifsr2=0; 
	
	asm("fset	i");


}
/********************************************************
*     1. check eeprom                                   *
*     2.                                                *
*********************************************************/
//void	IniEeprom(void)
//{
//	unsigned uni;
//
//	CheckEeprom();
//}

void     IniUART(void)
{
        Init_Comm(0);
        
        Init_Comm(1);
        
        Init_Comm(2);
}
           
//void    IniMeasure(void)
//{
//   Output_On_3_In_1_Terminal_Set(0);
//}        
/********************************************************
*     1. rtc pps interrupt                              *
*     2.                                                *
*********************************************************/	
void    Initrcpps(void)
{
	int0ic=0x04;
	ifsr0=0; 
}

void CheckEeprom(void)
{
        unsigned int i=0,j=0;
        unsigned char flag=0;

        unsigned char result=0;
                   

        Eeprom_Flag.byte=0;
        Err_Code.bit.MEM_ERR=0;      /*"add by dhy 090506"*/     
        do
        {    
           i++;   
       
          WRLC256(0,(unsigned char *)&Co,4,0,1);
			    if((*((unsigned char*)&Co+0)==0x23) &&(*((unsigned char*)&Co+1)==0x45) 
			      &&(*((unsigned char*)&Co+2)==0x67)&&(*((unsigned char*)&Co+3)==0x89))
			        flag=0xff;			         
        }while(!flag && i<50);
        
        if(!flag)
        {
           Eeprom_Flag.bit.b0=1;           
        }

         if(Eeprom_Flag.bit.b0)
        {
           Co.b[0]=0x23;			
			     Co.b[1]=0x45;
			     Co.b[2]=0x67;
			     Co.b[3]=0x89;
        }
        
        if(Eeprom_Flag.bit.b0)
        {    
        	   WRLC256(0,(unsigned char *)&Co,4,0,0); 
             EEpromErrNum[0]++;
             if(EEpromErrNum[0]>=2)
             {
                if(!Meter_States.Meter_Flag.bit.Eeprom_Err1)
                   result=0xff;   
                Meter_States.Meter_Flag.bit.Eeprom_Err1=1;  
                EEpromErrNum[0]=0;
             }                
        }
        else
        {
             EEpromErrNum[0]=0;
             Meter_States.Meter_Flag.bit.Eeprom_Err1=0;   
        }
  
        if(result)
        {
	         EepromErrorRecord();  //change by pc 081214
	         Err_Code.bit.MEM_ERR=1;/*"add by dhy 090506"*/
        }                     
}
 