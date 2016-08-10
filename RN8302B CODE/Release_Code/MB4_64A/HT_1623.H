#ifndef _HT_1623_h_
#define _HT_1623_h_

extern	void	HT1623_INIT_IN_NORMAL_MODE(void);		/*"正常情况下初始化HT1623"*/
extern	void	HT1623_INIT_IN_POWERDOWN_MODE(void);	/*"低功耗情况下初始化HT1623"*/

extern	void	HT1623_SYS_DIS(void);		/*"关振荡器和偏压发生器"*/
extern	void	HT1623_SYS_EN(void);		/*"开振荡器"*/
extern	void	HT1623_LCD_OFF(void);		/*"关LCD显示"*/
extern	void	HT1623_LCD_ON(void);		/*"开LCD显示"*/
//extern	void	HT1623_RC_32K(void);		/*"选择片上RC振荡器"*/

//extern	void	HT1623_SEND_A_COMMAND(unsigned int command);		/*"发送1个命令到HT1623"*/
//extern	void	HT1623_WRITE_MODE(unsigned char LCD_RAM_ADDR);		/*"使HT1623进入写数据模式"*/
//				/*"发送显示数据到HT1623"*/
extern	void	HT1623_SEND_DATA(unsigned char LCD_RAM_ADDR,		/*"HT1623 LCD RAM 地址(0-95)"*/
						 unsigned char *DATA_ADDR,					/*"显示数据的缓冲区地址"*/
						 unsigned int	DATA_LENGTH);				/*"显示数据的长度"*/
						 
#endif 