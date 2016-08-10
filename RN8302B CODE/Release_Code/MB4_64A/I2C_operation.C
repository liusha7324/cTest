//#include	"sfr62p.h"
#include	"defmcro.h"
#include	"defdata.h"
#include	"comm.h"
#include "ram.h"
#include "datachange.h"
#include "eventnew.h"
#include "Multi.h"
#include "interrupt.h"
#include "MB_BASE_FUN.h"
#include "Clock_time.H"

#define OUTPUT           1
#define INPUT            0
#define ERR              0xFF
#define OK               0x00

#define HIGH             1
#define LOW              0

/*----------- FM24C256 I2C CONFIGURATION ------------*/
#define	MEM_SCL                  p5_6    
#define	MEM_SDA                  p5_7    		
#define	MEM_WP                   p6_0   

#define	MEM_SCL_DR                  pd5_6    
#define	MEM_SDA_DR                   pd5_7    		
#define	MEM_WP_DR                    pd6_0  


#define		POLL_ACK_TIMES					15
#define		IIC_DELAY_TIME					2
#define		IIC_SCL_HIGH_TIME				1
#define		IIC_SCL_LOW_TIME				1
#define		SDA_SCL_TIME					2

#define		IIC_ACK_WAIT_TIMES			   90

#define		FM24C256_1_Slave_Addr			0xA2	//U10


extern	void	Delay_Wait(unsigned int unit_10_uS);


void I2C_Transmit(unsigned char Byte_Transmitted);
					
unsigned char I2C_Receive(void);			
					  		
void I2C_Start(void);

void I2C_Restart(void);			
			   
void I2C_Stop(void);
			   
unsigned char I2C_Poll_ACK(void);			
					  		
void	I2C_Send_ACK(void);

void	I2C_Send_NACK(void);
				  		
void	IIC_Delay(int number);

//Return 0x00:No ACK,0xFF:Good ACK		             
unsigned char I2C_Transmit_N_Bytes(unsigned char	*Data_Buffer,
		                     		       unsigned int  Data_Length);

//return 0:No ACK,0xFF:Good ACK
unsigned char Write_Read_FM24C256(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName,		//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						 	 		unsigned char OperationType);	//OperationType=0:write,1:read
						 	 		
void	FM24C256_WP_Operation_Pre_Writting(void);
void	FM24C256_WP_Operation_Post_Writting(void);

void	PowerOn_PCF8576(void);
void	PowerOff_PCF8576(void);
																 									 			
						 			
unsigned char IIC_ACK_WAIT(unsigned char Byte_Transmitted);	

unsigned char IIC_SOFT_RESET(void);	

void Check_IIC_State(void);

unsigned char Week_data_change(unsigned char Week,unsigned char kind);	

void Clock_powerdown_record(unsigned char kind);   				
										
/*---------------------------------------------- */
//return 0:No ACK,0xFF:Good ACK/*"注意：如果DataPointer=0，则规定长度和地址的内卡单元清零"*/
unsigned char Write_Read_FM24C256(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName,		//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						 	 		unsigned char OperationType)	//OperationType=0:write,1:read
	{		
		unsigned int  DataPointer_Value;
		unsigned char Byte_to_be_Written;

		unsigned int i,uni;
		unsigned char return_value=0xff;
		unsigned char SlaveAddr_CardAddr[3];
		unsigned int WEe_Addr;

		unsigned char int2ic_tempbak = 0;//ganjp 20090714
		
		DataPointer_Value=(unsigned int)DataPointer;/*"如果数据指针的值为零，则规定长度和地址的内卡单元清零"*/
		
		WEe_Addr=Card_Addr;
		
		if(Card_Addr>0x7FFF)//Card address out of the range
			return 0;		
		if(Data_Length==0)	//Nothing to be written
			return 0;
		if((Data_Length+(unsigned int)Card_Addr)>0x8000)	//To avoid rolling address
			return 0;
									
		SlaveAddr_CardAddr[0]=FM24C256_1_Slave_Addr;		//Slave_Addr 
		SlaveAddr_CardAddr[1]=(unsigned char)(Card_Addr>>8);			//Card address high byte	
		SlaveAddr_CardAddr[2]=(unsigned char)(Card_Addr&0x00FF);		//Card address low byte
		
		/*--- Writting card slave address and memory address in the card begins.---*/ 
		//---------ganjp 20090714----------------
		int2ic_tempbak = int2ic;
		int2ic &= 0xf8;
		//---------ganjp 20090714---------------
		if(OperationType==0)						//Write Data		
			FM24C256_WP_Operation_Pre_Writting(); 
		 
		I2C_Start();			
			   		
		for(i=0;i<3;i++)
			{
				I2C_Transmit(SlaveAddr_CardAddr[i]);
							 
				if(I2C_Poll_ACK()==0)
					{
						return_value=0;
						break;
					}
				else	return_value=0xff;
			}
		/*--- Writting card slave address and memory address in the card ends.---*/
		
		/*--- Writting/Reading data to/from card begins.---*/  
		if(return_value)
		{
		 if(OperationType==0)					//Write Data
		  {		    		
		   for(i=0;i<Data_Length;i++)
			 {
			 	if(DataPointer_Value)
					Byte_to_be_Written=DataPointer[i];
				else
					Byte_to_be_Written=0;
				
				I2C_Transmit(Byte_to_be_Written);
							 
				if(I2C_Poll_ACK()==0)
					{
						return_value=0;
						break;
					}
				else	return_value=0xff;
				
				WEe_Addr++;
				if(!(WEe_Addr%64))
				{
				FeedWatchdog(); 
					I2C_Stop();			//0-7			   		
 //                  Delay(10);
			   	if(IIC_ACK_WAIT(SlaveAddr_CardAddr[0]) == 0)
					  {
					  	return_value=0;
						  break;
					  }
			   		
			   		I2C_Start();			
			   		
			   		SlaveAddr_CardAddr[1]=(unsigned char)(WEe_Addr>>8);			//Card address high byte	
		        SlaveAddr_CardAddr[2]=(unsigned char)(WEe_Addr&0x00FF);		//Card address low byte
		                        
		        for(uni=0;uni<3;uni++)
			      {
			      	I2C_Transmit(SlaveAddr_CardAddr[uni]);
			      				 
			      	if(I2C_Poll_ACK()==0)
			      		{
			      			return_value=0;
			      			break;
			      		}
			      	else	return_value=0xff;
			      }
				}	
			 }
			 
			 I2C_Stop();			
//			 Delay(10);
			 if(IIC_ACK_WAIT(SlaveAddr_CardAddr[0]) == 0)
			 	{
			 		//	return_value=0;
			     // break;
			 	}
			 	I2C_Stop();
		   if(OperationType==0)						//Write Data
			 FM24C256_WP_Operation_Post_Writting();	
				  
			 int2ic = int2ic_tempbak;	   //ganjp 20090714
		     return	return_value;	
		    
		 }	 
		/*--- Writting data to card ends.---*/
		
		else				//Read Data
			{
				I2C_Restart();			//0-7
			   		
			  I2C_Transmit((SlaveAddr_CardAddr[0]|0x01));
				if(I2C_Poll_ACK()==0)
					{
						return_value=0;
					}
				else	return_value=0xff;
				
				if(return_value)
				 for(i=0;i<Data_Length;i++)
          {
           DataPointer[i]=I2C_Receive();
					 if(i!=(Data_Length-1))  		                        	
					    I2C_Send_ACK();
				    else
				    	I2C_Send_NACK();			
                  }
			}			/*--- Reading data from card ends.---*/
		}
			
	I2C_Stop();			
			   		
	if(OperationType==0)						//Write Data
		FM24C256_WP_Operation_Post_Writting();	
		
	int2ic = int2ic_tempbak;	   //ganjp 20090714
		
	return	return_value;		
	}						 	
		
             				  		       			  		      
/*---------------------------------------------- */
void I2C_Transmit(unsigned char Byte_Transmitted)
	{
		int i;					
		
		MEM_SDA_DR = OUTPUT;//make SDA to be output pin
		for(i=0;i<=7;i++)
			{
				if((Byte_Transmitted&0x80))
				 {	//SDA=1							
					 MEM_SDA    = HIGH;  	//SDA=1					
				 }
				else
				 {	//SDA=0
				 	MEM_SDA    = LOW;		//SDA goes low.
				 }
				asm("nop");
				MEM_SCL    = HIGH;  //SCL goes high.
				IIC_Delay(IIC_SCL_HIGH_TIME);
				
				MEM_SCL    = LOW;  //SCL goes low.
				Byte_Transmitted<<=1;
				if(i==7)
					MEM_SDA_DR = INPUT;	//make SDA to be input pin
			}
	}

/*---------------------------------------------- */	
unsigned char I2C_Receive(void)	
	{
		int	i;
		unsigned char return_value=0;

		MEM_SCL_DR = OUTPUT;//make SCL to be output pin
		MEM_SCL    = LOW;  //SCL goes low.		
		MEM_SDA_DR = INPUT;//make SDA to be output pin
		for(i=0;i<=7;i++)
			{
				MEM_SCL    = HIGH;  //SCL goes high.
				IIC_Delay(IIC_SCL_HIGH_TIME);
				if(MEM_SDA!=0)
					return_value|=0x01;
				MEM_SCL    = LOW;  //SCL goes low.		
				IIC_Delay(IIC_SCL_LOW_TIME);
				if(i<7)
					return_value<<=1;
			}
		MEM_SDA_DR = OUTPUT;			//make SDA to be output pin
		MEM_SDA    = LOW;  //SDA goes low.
		return	return_value;
	}	

/*---------------------------------------------- */
void I2C_Start(void)			
	{
		MEM_SCL_DR = OUTPUT;//make SCL to be output pin
		MEM_SDA_DR = OUTPUT;//make SDA to be output pin
		MEM_SCL    = HIGH;  //SCL goes high.
		MEM_SDA    = HIGH;  //SDA goes high.
		IIC_Delay(SDA_SCL_TIME);
		MEM_SDA    = LOW;  //SDA goes low.
		IIC_Delay(SDA_SCL_TIME);
		MEM_SCL    = LOW;  //SCL goes low.			
	}

/*---------------------------------------------- */	
void I2C_Restart(void)
	{		
		MEM_SDA    = HIGH;  //SDA goes high.
		asm("nop");
		MEM_SCL    = HIGH;  //SCL goes high.
		IIC_Delay(SDA_SCL_TIME);
		MEM_SDA    = LOW;  //SDA goes low.
		IIC_Delay(SDA_SCL_TIME);
		MEM_SCL    = LOW;  //SCL goes low.							
	}

/*---------------------------------------------- */	
void I2C_Stop(void)	
	{
		MEM_SCL    = HIGH;  //SCL goes high.
		MEM_SDA    = LOW;  //SDA goes low.
		IIC_Delay(SDA_SCL_TIME);
		MEM_SDA    = HIGH;  //SDA goes high.
		Delay_Wait(4);			//wait 40uS
		MEM_SCL_DR = INPUT;//make SCL to be input pin
		MEM_SDA_DR = INPUT;//make SDA to be input pin	
	}

/*---------------------------------------------- */	
unsigned char I2C_Poll_ACK(void)			
{
	unsigned int Poll_ACK_Times=POLL_ACK_TIMES;
	unsigned char return_value=0;
	
	MEM_SDA_DR = INPUT;//make SDA to be input pin	
	MEM_SCL    = HIGH;  //SCL goes high.
	IIC_Delay(SDA_SCL_TIME);
	while(Poll_ACK_Times)
		{	
			Poll_ACK_Times--;
			if(MEM_SDA==0)
				{
					return_value=0xff;
					break;
				}
		}
	MEM_SCL    = LOW;  //SCL goes low.	
	IIC_Delay(SDA_SCL_TIME);
	MEM_SDA_DR = OUTPUT;//make SDA to be output pin	
	IIC_Delay(SDA_SCL_TIME);
	MEM_SDA    = LOW;  //SDA goes low.
	return	return_value;
}

/*---------------------------------------------- */
void	I2C_Send_ACK(void)
{
	MEM_SDA    = LOW;  //SDA goes low.
	MEM_SCL    = HIGH;  //SCL goes high.			
	IIC_Delay(IIC_SCL_HIGH_TIME);
	MEM_SCL    = 	LOW;	//SCL goes low.
	
}

/*---------------------------------------------- */	
void	I2C_Send_NACK()	
{
	MEM_SDA    = HIGH;  		//SDA goes high.
	MEM_SCL    = HIGH;		//SCL goes high
	IIC_Delay(IIC_SCL_HIGH_TIME);
	MEM_SCL    = 	LOW;		//SCL goes low.	
	MEM_SDA    = LOW;		//SDA goes low.		
}					  		  

unsigned char IIC_ACK_WAIT(unsigned char Byte_Transmitted)
{
	unsigned char return_value=0;
	unsigned int IIC_ACK_WAIT_Times=IIC_ACK_WAIT_TIMES;
	
	while(IIC_ACK_WAIT_Times)
	{
		IIC_ACK_WAIT_Times--;
		I2C_Start();	
	  		   		
	  I2C_Transmit(Byte_Transmitted);
	  						 
	  if(I2C_Poll_ACK())
	  	{
	  		return_value=0XFF;
	  		break;
	  	}
	}
	return return_value;
}
/*"soft reset of iic"*/
unsigned char IIC_SOFT_RESET(void)
{
	unsigned char i=0;
	
	I2C_Start();	
			   				
  MEM_SDA_DR = OUTPUT;//make SDA to be output pin
  
	for(i=0;i<9;i++)/*"输出9个1"*/
		{							
			MEM_SDA    = HIGH;  		//SDA goes high.	
			asm("nop");
			asm("nop");
			MEM_SCL    = HIGH;		//SCL goes high
			IIC_Delay(IIC_SCL_HIGH_TIME);
			
			MEM_SCL    = 	LOW;		//SCL goes low.	
			asm("nop");			
		}		
	I2C_Restart();			
	IIC_Delay(IIC_SCL_HIGH_TIME);
	I2C_Stop();
}
/*"============================================================
函数说明：上电检测IIC是否空闲，不空闲，执行软复位
输入参数：无 
输出参数：无
返    回：无  
作    者：GANJP  版本：1.00
============================================================"*/
void Check_IIC_State(void)
{
	MEM_SDA_DR = INPUT;//make SDA to be input pin	
	IIC_Delay(IIC_SCL_HIGH_TIME);
	IIC_Delay(IIC_SCL_HIGH_TIME);
	if(MEM_SDA==0)
		{
			IIC_Delay(IIC_SCL_HIGH_TIME);
	    IIC_Delay(IIC_SCL_HIGH_TIME);
	    if(MEM_SDA==0)
	    	{
	    		IIC_SOFT_RESET();
	    	}
		}
	
}
/*---------------------------------------------- */

void	FM24C256_WP_Operation_Pre_Writting(void)
{			
	MEM_WP_DR = OUTPUT;//WP becomes output pin.
  MEM_WP    = LOW;   //WP goes low.
}

/*---------------------------------------------- */

void	FM24C256_WP_Operation_Post_Writting(void)
{
	MEM_WP_DR = OUTPUT;//WP becomes output pin.
	MEM_WP    = HIGH;		//WP goes high.
	MEM_WP_DR = INPUT;	//WP becomes input pin.
}

/*---------------------------------------------- */
void	IIC_Delay(int number)
{	
	asm("nop");
}					  

/*---------------------------------------------- */		
void	PowerOn_PCF8576(void)
		{
			unsigned char uni;
			
			pd8_0=1;				//LCD_POWER becoms output pin.
			asm("nop");
			p8_0=1;					//LCD_POWER goes high.
			for(uni = 0; uni < 50; uni++)//powerdown lcd control problem
			{
				asm("nop");
			}
			
			p7_4=1;					//SDA_LCD
			p2_2=1;					//SCL_LCD
			pd7_4=1;
			pd2_2=1;
			
			
		}

/*---------------------------------------------- */		
void	PowerOff_PCF8576(void)
		{
			pd8_0=1;				//LCD_POWER becoms output pin.
			asm("nop");
			p8_0=0;					//LCD_POWER goes low.
			asm("nop");
			//pd7_6=0;				//LCD_POWER becoms input pin.
		}
    
/*"*********************************************************
8025T I2C操作接口
*********************************************************"*/
#define SET		1
#define CLEAR	0

#define TRUE           1
#define FALSE          0

#define RET_OK         1
#define RET_FAIL       0

#define  NULL           0

#define IICCLK    		p3_1		/*"IIC的时钟线"*/
#define M_IICCLK		  pd3_1

#define IICSDA    		p3_0		/*"IIC的数据线"*/
#define M_IICSDA		  pd3_0

#define IICREDOTIMES	2
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
unsigned char IIC_SendChar(unsigned char inCh);
unsigned char IIC_ReadChar(unsigned char ask);
unsigned char I2cWrite(unsigned char dev,unsigned char adr,unsigned char len,unsigned char *pr);


void StartI2cPort(void)
{
	IICCLK=CLEAR;
	M_IICCLK=OUTPUT;
//	U_IICCLK=SET;
	
	IICSDA=CLEAR;
	M_IICSDA=OUTPUT;
//	U_IICSDA=SET;
}

void StopI2cPort(void)
{
	
	IICSDA=CLEAR;
	M_IICSDA=INPUT;
//	U_IICSDA=CLEAR;
	
	IICCLK=CLEAR;
	M_IICCLK=INPUT;
//	U_IICCLK=CLEAR;
}


/*"************************************************
Function: IIC_Start
Description: IIC启动Start信号
Global: 无
Calls:  无
Input:  无
Output: 无
Return: 无
Others: 无
************************************************"*/
void IIC_Start(void)
{
	IICCLK=CLEAR;
	M_IICCLK=OUTPUT;	
	IIC_Delay(SDA_SCL_TIME);
	IICSDA=SET;
	M_IICSDA=OUTPUT;
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
	IICCLK=SET;
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
	asm("nop");
	IICSDA=CLEAR;
	IIC_Delay(SDA_SCL_TIME);
	IICCLK=CLEAR;
	IIC_Delay(SDA_SCL_TIME);
}

/*"************************************************
Function: IIC_Stop
Description: IIC启动Stop信号
Global: 无
Calls:  无
Input:  无
Output: 无
Return: 无
Others: 无
************************************************"*/
void IIC_Stop(void)
{
	IICCLK=CLEAR;
	M_IICCLK=OUTPUT;
	IIC_Delay(SDA_SCL_TIME);
	IICSDA=CLEAR;
	M_IICSDA=OUTPUT;
	IIC_Delay(SDA_SCL_TIME);
	IICCLK=SET;
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
	IICSDA=SET;
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
}

/*"************************************************
Function: IIC_SendChar
Description: IIC总线发送一字节
Global: 无
Calls:  无
Input:  
    inCh：要发送字节
Output: 无
Return: 无
Others: 无
************************************************"*/
unsigned char IIC_SendChar(unsigned char inCh)
{
	unsigned char bitp;
	unsigned char result;
	
	bitp=8;
	M_IICSDA=OUTPUT;
	while(bitp--)
		{
		IICCLK=CLEAR;
		IIC_Delay(SDA_SCL_TIME);
		if(inCh&0x80) IICSDA=SET;
			else IICSDA=CLEAR;
		inCh<<=1;	
		IIC_Delay(SDA_SCL_TIME);
		IICCLK=SET;
		IIC_Delay(SDA_SCL_TIME);
		IIC_Delay(SDA_SCL_TIME);   
		}	
	
//	asm("PUSHC FLG");
//	asm("FCLR I");

	IICCLK=CLEAR;
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
	IIC_Delay(SDA_SCL_TIME);
    IICSDA=SET;
	M_IICSDA=INPUT; 
	IICCLK=SET;
	IIC_Delay(SDA_SCL_TIME);
	if(IICSDA)
    {
         result=FALSE;
    }
    else 
    {
        result=TRUE;
    }

//	asm("POPC FLG");	

	IIC_Delay(SDA_SCL_TIME);
	
	IICCLK=CLEAR;
	IIC_Delay(SDA_SCL_TIME);
	IICSDA=CLEAR;	
	IIC_Delay(SDA_SCL_TIME);
	
	return result;
}

/*"************************************************
Function: IIC_ReadChar
Description: 从IIC总线接收一字节
Global: 无
Calls:  无
Input:  无
Output: 无
Return: 
    接收到的字节
Others: 无
************************************************"*/
unsigned char IIC_ReadChar(unsigned char ask)
{
	unsigned char bitp;
	unsigned char result=0;
	unsigned char temp;
	
	M_IICSDA=INPUT;
	bitp=8;

	while(bitp--)
	{
		IIC_Delay(SDA_SCL_TIME);
		IIC_Delay(SDA_SCL_TIME);
		IICCLK=SET;
		result<<=1;
		IIC_Delay(SDA_SCL_TIME);
		if(IICSDA) result|=0x01;
			else result&=0xFE;
		IIC_Delay(SDA_SCL_TIME);
		IICCLK=CLEAR;
	}
	
	IICCLK=CLEAR;
	IIC_Delay(SDA_SCL_TIME);

	M_IICSDA=OUTPUT;	
	if(ask) IICSDA=CLEAR;
		else IICSDA=SET;

	IIC_Delay(SDA_SCL_TIME);
	
	IICCLK=SET;
    IIC_Delay(SDA_SCL_TIME);
    IIC_Delay(SDA_SCL_TIME);
    IIC_Delay(SDA_SCL_TIME);
    IICCLK=CLEAR;

    IIC_Delay(SDA_SCL_TIME);
    IICSDA=CLEAR;
    IIC_Delay(SDA_SCL_TIME);

 return result;
}



unsigned char I2cWrite(unsigned char dev,unsigned char adr,unsigned char len,unsigned char *pr)
{
unsigned char result;
unsigned char times;
unsigned char *ptemp;
unsigned char templen;

	dev&=0xFE;
	times=IICREDOTIMES;

	StartI2cPort();
		
	do
	{
		result=RET_OK;	
		IIC_Stop();
		IIC_Start();
		templen=len;
		ptemp=pr;
		if(!IIC_SendChar(dev))
		{
			result=RET_FAIL;
			continue;
		}		
		
		if(!IIC_SendChar(adr))			
		{
			result=RET_FAIL;
			continue;
		}

		while(templen--)
		{
		//	RESET_WATCH_DOG;
			if(ptemp == NULL)
			{
				if(!IIC_SendChar(0))
				{
					result=RET_FAIL;
					break;
				}		
			}
			else
			{
				if(!IIC_SendChar(*ptemp++))
				{
					result=RET_FAIL;
					break;
				}		
			}
		}
	
		if(result) break;
	}while(times--);

	IIC_Stop();
	StopI2cPort();
	
return result;
}


unsigned char I2cRead(unsigned char dev,unsigned int adr,unsigned char len,unsigned char *pr)
{
unsigned char result;
unsigned char times;
unsigned char *ptemp;
unsigned char templen;
	
	times=IICREDOTIMES;
	StartI2cPort();
		
	do
	{
	result = RET_OK;	
	IIC_Stop();
	IIC_Start();
	templen=len;
	ptemp=pr;
	
	dev&=0xFE;
	if(!IIC_SendChar(dev))
		{
		result=RET_FAIL;
		continue;
		}		

	if(!IIC_SendChar((unsigned char)adr))			
	 		{
	 		result=RET_FAIL;
		continue;
	 		}
	IIC_Start();
	dev|=0x01;
	if(!IIC_SendChar(dev))
		{
		result=RET_FAIL;
		continue;
		}		
	while(templen--)
		{
//		RESET_WATCH_DOG;	

		*ptemp++=IIC_ReadChar(templen);
		}
	if(result) break;
	}while(times--);
	
	IIC_Stop();
	StopI2cPort();
	
return result;
}
/*"*********************************************************
时钟芯片接口
*********************************************************"*/

#define R8025DEV	0b01100100

#define R8025SECA	0x00

#define R8025TCONA	0x0d
#define R8025TCON1	0x00
#define R8025TCON2	0x00
#define R8025TCON3	0xe0	//lxf 2009.7.23 0x60

#define CLOCK_ERR   Meter_States.Meter_Flag.bit.Rtc_Err1
union   BYTE_BIT    Rtc_state;
//#define NOEEPADDRESS	0x00


unsigned char DateWeekTime[7];
#pragma SECTION rom UserROMData
const unsigned char DefaultTime[]={0x30,0x59,0x23,0x03,0x31,0x12,0x08};

void ClockChipInit(unsigned char def);
void ClockChipRead(unsigned char  *t);
void ClockChipWrite(unsigned char   *t);
void ClockChipOpenSec(void);
void ClockChipCloseSec(void);

//#define CLOCK_CHIP	RX8025T


/*"************************************************
Function: ClockChipInit
Description: 时钟芯片初始化
Global: 无
Calls:  无
Input:  def:0,初始化时间和控制寄存器
			1,初始化控制寄存器 
Output: 无
Return: 无
Others: 无
************************************************"*/
void ClockChipInit(unsigned char def)
{
  unsigned char uni = 0;
	unsigned char temp;
	unsigned char count[1] = {0};
	unsigned char contorl[3]={R8025TCON1,R8025TCON2,R8025TCON3};			
	
	Rtc_state.bit.b0 = I2cRead(R8025DEV,R8025TCONA+1,sizeof(count),count);	/*"判断数据丢失标志濉"*/
	count[0]&=0x02;
	if(count[0])
		{
			Clock_powerdown_record(0);
			if(IF_Powerup_Billdata==0)
      {
        rtc_lossvolt_flag=0xa5a5;
      }
		}	
//		MeterStatus.Bit.RTCOK=TRUE;

	
	Rtc_state.bit.b0 = I2cWrite(R8025DEV,R8025TCONA,sizeof(contorl),contorl);  
  	if(!def)
  		{
		for(temp=0;temp<sizeof(DateWeekTime);temp++)
			{
			DateWeekTime[temp]=DefaultTime[temp];
			}
		Rtc_state.bit.b0=I2cWrite(R8025DEV,R8025SECA,sizeof(DateWeekTime),DateWeekTime);
		}		
	Rtc_state.bit.b0=I2cRead(R8025DEV,R8025SECA,sizeof(DateWeekTime),DateWeekTime);	
//	CLOCK_ERR = !Rtc_state.bit.b0;
}
/*"************************************************
Function: ClockChipRead
Description: 读时钟芯片
Global: 无
Calls:  无
Input:  
    inRegAddr： 时钟芯片的寄存器地址
    inCount：   读取字节数
Output: 无
    outpBuf：   读取数据的存放位置
Return: 无
Others: 无
************************************************"*/
void ClockChipRead(unsigned char *t)
{
	unsigned char temp[1]={0};
	unsigned char contorl[3]={R8025TCON1,R8025TCON2,R8025TCON3};	
	unsigned char uni = 0;
//	if(FLG_SYSTEM_RUNMODE == SYSTEMRUNMODE_NORMAL)
		{
		Rtc_state.bit.b0 = I2cRead(R8025DEV,R8025TCONA+1,sizeof(temp),temp);
		temp[0]&=0x02;
		if(temp[0])	
			{
        if((0xff != IntoPowerDownFlag)&&(IF_Powerup_Savedata==1)&&(CheckTime((unsigned char *)&softdate)))
        {
        	Clock_powerdown_record(1);
        	Rtc_state.bit.b0 = I2cWrite(R8025DEV,R8025TCONA,sizeof(contorl),contorl);
        	ClockChipWrite((unsigned char *)&softdate);
        }
			}
		}
	Rtc_state.bit.b0 = I2cRead(R8025DEV,R8025SECA,sizeof(DateWeekTime),DateWeekTime);
	if(Rtc_state.bit.b0 == 0)
		{
			for(uni = 0; uni < 7; uni++)
			{
				DateWeekTime[uni] = 0;
			}
		}
//	CLOCK_ERR = !Rtc_state.bit.b0;
    *t       = DateWeekTime[6];          
	*(t + 1) = DateWeekTime[5]&0x1f;     
	*(t + 2) = DateWeekTime[4]&0x3f;     
	*(t + 3) = DateWeekTime[2]&0x3f;     
	*(t + 4) = DateWeekTime[1]&0x7f;     
	*(t + 5) = DateWeekTime[0]&0x7f;     
	*(t + 6) = Week_data_change(DateWeekTime[3],1);
	
	if(CheckTime(t)==0)
	{
		for(uni = 0; uni < 7; uni++)
		{
				*(t+uni) = 0;
		}
	}
		    
}


/*"************************************************
Function: ClockChipWrite
Description: 写时钟芯片
Global: 无
Calls:  无
Input:  
    inRegAddr： 时钟芯片的寄存器地址
    inCount：   写入字节数
    inpBuf：    写入数据的存放位置
Output: 无
Return: 无
Others: 无
************************************************"*/
void ClockChipWrite(unsigned char  *t)
{	
	CalWeek(t);
    DateWeekTime[6] = *t;//((*t).Year) ;	
	DateWeekTime[5] = *(t+1); //((*t).Month) ;	
	DateWeekTime[4] = *(t+2);//((*t).Day) ;	
	DateWeekTime[2] = *(t+3);//((*t).Hour) ;	
	DateWeekTime[1] = *(t+4);//((*t).Min) ;	
	DateWeekTime[0] = *(t+5);//((*t).Sec) ;	
	DateWeekTime[3] = Week_data_change(*(t+6),0);//(*t).Week;	    
	Rtc_state.bit.b0 = I2cWrite(R8025DEV,R8025SECA,sizeof(DateWeekTime),DateWeekTime);
//	CLOCK_ERR = !Rtc_state.bit.b0;
//	MeterStatus.Bit.RTCOK = FALSE;
}


/*"************************************************
Function: ClockChipCloseSec
Description: 关闭秒脉冲
Global: 无
Calls:  无
Input:  
		ChipType:0,RX8025
				 1,RX8025T
Output: 无
Return: 无
Others: 无
************************************************"*/
void ClockChipCloseSec(void)
{
	unsigned char temp;
	unsigned char contorl[3]={0x00,0x00,0xc0};	//0x40 lxf 2009.7.23
	
	if(IF_Powerup_Billdata==0)/*"电池上电时"*/
  {
    I2cRead(R8025DEV,R8025TCONA+1,1,&temp);	/*"判断数据丢失标志濉"*/
    if((temp&0x02)!=0)
    {
      rtc_lossvolt_flag=0xa5a5;
    }
  }
	
	I2cWrite(R8025DEV,R8025TCONA,sizeof(contorl),contorl);

}

/*"============================================================
函数说明：周次格式转换函数
          
输入参数：Week 输入周次
          kind 转换方向  0 softdate --> rtcdata
                         1 rtcdata  --> softdata
输出参数：无
返    回：ret_week  返回转换后周次格式  
作    者：GANJP  版本：1.00
============================================================"*/        
unsigned char Week_data_change(unsigned char Week,unsigned char kind)
{
	unsigned char ret_week = 0;
	unsigned char uni = 0;
	if(kind == 0)//write in to 8025T
		{
			ret_week = 1;
			ret_week <<= Week;
		}
	else        //read from 8025T
		{
			for(uni = 0; uni < 7; uni++)
			{
				if((Week & 0x01) == 1)
					{
						ret_week = uni;
						break;
					}
					Week >>= 0x01;
			}
		}	
	
	return (ret_week);
}
/*"============================================================
函数说明：检测到时钟芯片失电标志处理函数,置时钟错误标志，记录相应
          事件记录
输入参数：kind   0 powerup check  1 run check
输出参数：无
返    回：无   
作    者：GANJP  版本：1.00
============================================================"*/
void Clock_powerdown_record(unsigned char kind)
{
	unsigned char uni;
	
	for(uni=0;uni<5;uni++)
	{
	    Co.b[405+uni]=uni;
	}
	Co.b[410]=0x08;
	
	if(kind == 0)
	  PowerUpClockErrorRecord();
	else
		RunClockErrorRecord();	
  	
}