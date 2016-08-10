extern void	InitPort(void);
//extern void	IniEeprom(void);
extern void     IniUART(void);
extern void	IniSIMCard(void);  
extern void	IniBoad(void);   
//extern void     IniMeasure(void);     
extern void     InitTimeA0(void);
extern void     InitMainRegeist(void);   
extern void     InitInterrupt(void);  
extern void     InitTimeA2_PowerDown(void);
extern void    CheckEeprom(void);
extern void 	InitTimeA3(void);	//payment


extern  unsigned char PDFlagRam1[15]; 
extern  union  BYTE_BIT Eeprom_Flag;

    
