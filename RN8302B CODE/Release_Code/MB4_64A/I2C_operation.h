#ifndef _I2C_operation_h_
#define _I2C_operation_h_
					 				
//return 0:No ACK,0xFF:Good ACK/*"注意：如果DataPointer=0，则规定长度和地址的内卡单元清零"*/
extern unsigned char Write_Read_FM24C256(unsigned int Card_Addr,	//Address in FM24C256
							 		unsigned char *DataPointer,		//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName,		//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						 	 		unsigned char OperationType);	//OperationType=0:write,1:read
						 	 							 	 		
extern void	PowerOn_PCF8576(void);
extern void	PowerOff_PCF8576(void);
extern unsigned char IIC_SOFT_RESET(void);
extern void Check_IIC_State(void);
							 			
extern void ClockChipInit(unsigned char def);
extern void ClockChipRead(unsigned char *t);
extern void ClockChipWrite(unsigned char *t);
extern void ClockChipOpenSec(void);
extern void ClockChipCloseSec(void);
extern void IIC_Delay(int number);
#endif				 