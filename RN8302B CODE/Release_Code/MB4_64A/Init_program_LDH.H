#ifndef	_Init_program_LDH_h
#define	_Init_program_LDH_h

extern void	Disable_INT1(void);
extern void	Enable_INT1(void);
extern void	Initiallize_INT1(void);
extern void	Initiallize_INT3(void);		/*"初始化全失压脉冲中断"*/

extern void	Initiallize_INT5(void);		/*"初试化激光点亮中断"*/
extern void	Disable_INT5(void);			/*"关闭激光点亮中断"*/
extern void	Enable_INT5(void);			/*"打开激光点亮中断"*/

extern void	Disable_INT7(void);
extern void	Enable_INT7(void);
extern void	Initiallize_INT7(void);

extern void	Init_SIO3(void);			//Initiallize SIO3
extern void	Initiallize_RAM_Buffer_Used_by_LDH(void);
//extern void	Reset_Measuring_Board(void);
extern void	Poweron_Reset_Measuring_Board(void);
#endif 