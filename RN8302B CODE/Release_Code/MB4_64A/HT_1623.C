#include	"defmcro.h"
#include	"defdata.h"
#include  "ram.h"
#include  "interrupt.h"

#define		HT_1623_POWER_PORT					p8_0		/*"HT1623电源控制的数据口"*/
#define		HT_1623_POWER_DIRECTION_PORT		pd8_0		/*"HT1623电源控制的方向口"*/
#define		HT_1623_CS_PORT						p4_4		/*"CS的数据口"*/
#define		HT_1623_CS_DIRECTION_PORT			pd4_4		/*"CS的方向口"*/

#define		BACKLIGHT_POWER_PORT				p2_3		/*"背光电源控制的数据口"*/
#define		BACKLIGHT_POWER_DIRECTION_PORT		pd2_3		/*"背光电源控制的方向口"*/

#define  slave_addr 0x7C       /*"//slave地址       "*/                         
#define  ICSET      0xF6       //CLOSE Display; soft reset;Frame mode;                                       
#define  ICSET1     0xF5			 //ON display;;Frame mode;
#define  ICSET2     0xF1			 //ON display;;Line mode;                                                                  
      
 
#define  DISCTL0     0xE2       //Normal   80Hz       
#define  DISCTL00    0xE0       //PS1      80Hz    
#define  DISCTL01    0xE1       //PS2      80Hz      
#define  DISCTL02    0xE3       //HP      80Hz      

                                                                      
#define  DISCTL1     0xE6       //Normal   71Hz  
#define  DISCTL10    0xE4       //PS1      71Hz     
#define  DISCTL11    0xE5       //PS2      71Hz     
#define  DISCTL12    0xE7       //HP       71Hz     

                                
#define  DISCTL2     0xEA       //Normal   64Hz                
#define  DISCTL20    0xE8       //PS1      64Hz             
#define  DISCTL21    0xE9       //PS2      64Hz             
#define  DISCTL22    0xEB       //HP       64Hz             

                            
#define  DISCTL3    0xEE       //Normal    50Hz             
#define  DISCTL30   0xEC       //PS1       50Hz                  
#define  DISCTL31   0xED       //PS2       50Hz                  
#define  DISCTL32   0xEF       //HP        50Hz                  


#define  EVRSET     0xc4       //VCC = 5V,Vping = 4.1V; 
#define  PDEVRSET   0xc2                                                                                        
    
#define  ADSET      0x00       /*"//ram起始地址"*/                         
                         
#define  APCTL      0xF8       //Normal                           
#define  APCTL1     0xFA       //ALL ON Display                                                                   
#define  APCTL2     0xF9       //ALL OFF Display                                                                             
                    
                                    
#define  SDA      p7_4             /*"//端口寄存器    "*/                                                                                  
#define  MSDA     pd7_4           /*"//端口方向寄存器 0为输出，1为输入   "*/                                                                                     
#define  SCL      p2_2                                        
#define  MSCL     pd2_2                                            

#define  INPUT    0
#define  OUTPUT   1
//unsigned char buff[24]={0xFF};
void	HT1623_INIT_IN_NORMAL_MODE(void);		/*"正常情况下初始化HT1623"*/
void	HT1623_INIT_IN_POWERDOWN_MODE(void);	/*"低功耗情况下初始化HT1623"*/

void	HT1623_SYS_DIS(void);		/*"关振荡器和偏压发生器"*/
void	HT1623_SYS_EN(void);		/*"开振荡器"*/
void	HT1623_LCD_OFF(void);		/*"关LCD显示"*/
void	HT1623_LCD_ON(void);		/*"开LCD显示"*/

/*"发送显示数据到HT1623"*/
void	HT1623_SEND_DATA(unsigned char LCD_RAM_ADDR,		/*"HT1623 LCD RAM 地址(0-95)"*/
						           unsigned char *DATA_ADDR,					/*"显示数据的缓冲区地址"*/
						           unsigned int	DATA_LENGTH);				/*"显示数据的长度"*/

void start_i2c(void);
void stop_i2c(void);
void send_byte(unsigned char tempb);
void send_byte_lcd(unsigned char tempb);
void data_display(void);
void ini_display(unsigned char kind);
//void on_display(void);
unsigned char receive_byte(void);
void reg_read(void);

unsigned char read_reg;

/*------------------------------------------------------------------------------------*/
void	HT1623_INIT_IN_NORMAL_MODE(void)		/*"正常情况下初始化HT1623"*/
		{
			HT_1623_POWER_DIRECTION_PORT=1;		/*"HT1623电源控制的方向口"*/
			HT_1623_POWER_PORT=1;				/*"HT1623电源控制的数据口"*/
			
			ini_display(0);						
		}
		
/*------------------------------------------------------------------------------------*/
void	HT1623_INIT_IN_POWERDOWN_MODE(void)		/*"低功耗情况下初始化HT1623"*/
		{
			HT_1623_POWER_DIRECTION_PORT=1;		/*"HT1623电源控制的方向口"*/			
			HT_1623_POWER_PORT=1;			//mw modified 2010-05-04
			
			ini_display(1);			
					
		}

/*------------------------------------------------------------------------------------*/
void	HT1623_SYS_DIS(void)		/*"关振荡器和偏压发生器"*/
		{
//			HT1623_SEND_A_COMMAND(SYS_DIS_COMMAND);			/*"发送1个命令到HT1623"*/
		}

/*------------------------------------------------------------------------------------*/
void	HT1623_SYS_EN(void)		/*"开振荡器"*/
		{
//			HT1623_SEND_A_COMMAND(SYS_EN_COMMAND);			/*"发送1个命令到HT1623"*/
		}
		
/*------------------------------------------------------------------------------------*/		
void	HT1623_LCD_OFF(void)		/*"关LCD显示"*/	
		{
			start_i2c();
 	    send_byte(slave_addr);   
 	
 	    send_byte(ICSET);           //ON display,Frame;
 	    stop_i2c();
		}
		
/*------------------------------------------------------------------------------------*/
void	HT1623_LCD_ON(void)			/*"开LCD显示"*/
		{
      start_i2c();
 	    send_byte(slave_addr);   
 	
 	    send_byte(ICSET1);           //ON display,Frame;
 	    stop_i2c();
		}

/*------------------------------------------------------------------------------------*/
void	HT1623_SEND_DATA(unsigned char LCD_RAM_ADDR,		/*"HT1623 LCD RAM 地址(0-95)"*/
						 unsigned char *DATA_ADDR,			/*"显示数据的缓冲区地址"*/
						 unsigned int	DATA_LENGTH)		/*"显示数据的长度"*/
{
	register unsigned char i;
  stop_i2c();
  start_i2c();
 	send_byte(slave_addr);   
 	
 	send_byte(ICSET1);           //ON display,Frame;                                            
// 	send_byte(ICSET2);         //ON display,Line;      
 	                
// 	send_byte(DISCTL0);           //Normal   80Hz                                                                                
//  send_byte(DISCTL00);           //PS1      80Hz 
//  send_byte(DISCTL01);           //PS2      80Hz 
//  send_byte(DISCTL02);           //HP       80Hz 
                                                                                             
//  send_byte(DISCTL1);            //Normal   71Hz 
//  send_byte(DISCTL10);           //PS1      71Hz 
//  send_byte(DISCTL11);           //PS2      71Hz 
//  send_byte(DISCTL12);           //HP       71Hz 
                                                                                                
//	send_byte(DISCTL2);            //Normal    64Hz 
 	send_byte(DISCTL20);           //PS1      64Hz 
// 	send_byte(DISCTL21);           //PS2      64Hz 
//	send_byte(DISCTL22);           //HP       64Hz 
                                                                                                
// 	send_byte(DISCTL3);            //Normal    50Hz 
// 	send_byte(DISCTL30);           //PS1       50Hz 
// 	send_byte(DISCTL31);           //PS2       50Hz 
//	send_byte(DISCTL32);           //HP        50Hz 

  
  if(Meter_Parameter.parameter1.MeterMode[0].bit.b5==0)
  {
    send_byte(EVRSET);             //EVR Enable Vlcd=5V,V0=3.261V; 
  }
  else
  {
  	if(IntoPowerDownFlag==0xff)
  	{
  		send_byte(PDEVRSET);
  	}
  	else
  	{
  		send_byte(EVRSET);
  	}
  }                                                                                                               
// 	send_byte(APCTL);            /*"//正常模式;   "*/                                                                                               
  send_byte(LCD_RAM_ADDR);   //	send_byte(ADSET);                                                                                         
	for(i=0;i<DATA_LENGTH;i++)
	  {
	  	send_byte_lcd(*(DATA_ADDR+i));
	  }	  
	stop_i2c();
}
/*"/******************************************************************"*/     
/*"起动总线函                     "*/                                                                 
/*"函数原型：void start_i2c();        "*/                     
/*"Function: start on the I2C bus           "*/                                   
/*"******************************************************************"*/     
void start_i2c(void)
{
 SDA=1;       
 asm("nop");
 SCL=1;
 asm("nop");
 asm("nop");
 asm("nop");
 asm("nop");
 SDA=0;                     
 asm("nop");
 asm("nop");
 asm("nop");
 asm("nop");
 SCL=0;                      
                             
}
/*"***************************************************************** "*/  
/*"停止总线函 "*/  
/*"函数原型： void stop_i2c(); "*/  
/*"Function: stop the I2C bus "*/  
/*"****************************************************************** "*/  
void stop_i2c(void)
{
 SDA=0; 
 asm("nop");
 SCL=1;
 asm("nop");
 asm("nop");
 SDA=1;
 asm("nop");
}

/*"================================================================="*/  
/*"字节?据传送函? "*/  
/*"函?原型： void send_byte(unsigned char tempb);"*/  
/*"Function: 将?据C发送出去，可以是地址，也可以是?据，发完后等?回应，并对此状态"*/  
/*"         位进行操作（不应答或非应答都使ack=0 ），发送?据?常，ack=1;ack=0"*/  
/*"         表示被控器无应答或损坏。"*/  
/*"=================================================================="*/  
void send_byte(unsigned char tempb)
{
 unsigned char bit_count;
 
 for (bit_count=0;bit_count<8;bit_count++)
  {
   if ((tempb<<bit_count)&0x80) {SDA=1;}
   else {SDA=0;}
   asm("nop");
   SCL=1;
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   SCL=0;
  }
  MSDA=INPUT;
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  
  SCL=1; 
//  if (SDA==1) ack=0;
//  else ack=1; 
  MSDA=OUTPUT;
  SCL=0;
  asm("nop");
}

void send_byte_lcd(unsigned char tempb)
{
 unsigned char bit_count;
 unsigned char show_data = 0;
 
 for(bit_count=0;bit_count<8;bit_count++)
 {
 	if((tempb >> bit_count)& 0x01)
 		show_data |= (0x80 >> bit_count);
 }
 send_byte(show_data);
}

/*
unsigned char receive_byte(void)
{
  unsigned char retc,bit_count;
  retc=0;
  MSDA=INPUT;
  for (bit_count=0;bit_count<8;bit_count++)
  {
     asm("nop");
     SCL=0;
     asm("nop");
     SCL=1;
     asm("nop");
     retc=retc<<1;
     if (SDA==1) retc++;
     // retc=retc+1;    
   }
   SCL=0;
   asm("nop");
   MSDA=OUTPUT;
   return(retc);
}


void reg_read(void)
{
	stop_i2c();
  start_i2c();
 	send_byte(slave_addr); 
 	send_byte(0x23); 
 	start_i2c();
 	send_byte(slave_addr+1); 
 	read_reg = receive_byte();
 	stop_i2c();
}
*/

/*"///////////初始化LCD-DRIVER//////////////////////"*/
// kind  0  normal  1 powerdown
void ini_display(unsigned char kind)   
{
 register  unsigned char i;
 MSCL=OUTPUT;
 MSDA=OUTPUT;
 stop_i2c();
  start_i2c();
  send_byte(slave_addr);  
  send_byte(ICSET);              //Close display  soft reset 
  
  if(Meter_Parameter.parameter1.MeterMode[0].bit.b5==0)
  {
    send_byte(EVRSET);             /*"//Vlcd=4.1v  ，若不设置则屏电压从4.1v突然到5v，视觉上会闪烁。 "*/
  }
  else
  {
  	if(IntoPowerDownFlag==0xff)
  	{
  		send_byte(PDEVRSET);
  	}
  	else
  	{
  		send_byte(EVRSET);
  	}
  }         
  send_byte(ICSET1);         /*"//no soft reset,but  显示打开           "*/
 if(kind == 0)     
   {
    //send_byte(DISCTL0);           //Normal mode ;   
    	send_byte(DISCTL20);           //PS1      64Hz 
      send_byte(ADSET); 
   }  
  else
   {
    //send_byte(DISCTL30);           //powerdown mode ;    
    	send_byte(DISCTL20);           //PS1      64Hz 
      send_byte(ADSET); 
   }                                                                                                         
                         
  for(i=0;i<35;i++)
  {
    send_byte(0x0);        /*"//清空RAM;     "*/                                  
   }                                                              
  stop_i2c();
 }

	 
