extern void	IniRam(void);
extern unsigned char CheckEnergyRom1AndRom2(unsigned char *ram1,unsigned char *ram2); 
extern unsigned char checkEnergyRight(unsigned char *scr_addr,unsigned char number,
                               unsigned char *des_addr,unsigned long range,
                               unsigned char comflag);
extern void Write_TO_Cal_PowerDown_Energy_add(void);      
extern void SetDefault(void);                         
extern void Retort_New(unsigned char,unsigned char*);

extern unsigned char TotalEnergyRight( struct ENERGY_RECORD *scr_addr,const unsigned char which);
extern unsigned char  ALL_TotalEnergyRight(struct ENERGY_RECORD *scr_addr);
extern unsigned char  EnergyAutoRectifyLevel1(void);
extern unsigned char EnergyAutoRectifyLevel2(void);
//extern unsigned char WhichEnergyMoreRight( struct ENERGY_RECORD *ram1, struct ENERGY_RECORD *ram2,unsigned long range);
extern void Powerdown_to_ThisMonth(void);
//extern unsigned char CheckPowerDownSave(void);
extern unsigned char CheckEnergyPowerEnergy(struct ENERGY_POWERDOWN  *ram);
//extern unsigned char CALC_CS(unsigned char *ram, unsigned int length);
extern void ReadMeterPara(void);
extern unsigned char IsNormalReset(unsigned char type); 
extern unsigned char IsHaveSaveData(void);
extern void Clear_Savedata_flag(void);
extern unsigned char ReadEepromEnergy(void);
extern unsigned char ReadBlock(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName);//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						 	 						 	 		
extern unsigned char IsNormalResetWrite(void);

extern void Check_New(void);
extern void Para_Process_main(void);
extern unsigned char ReadEeprom(void);
extern void Para_Process_run(void);
extern union   BYTE_DEF  Parameter_flag[5]; //b0----1 ram err ,resume err                       0 ok,king chen modify 121226
                                     //b1----1 ram err  eeprom err read eeprom err       0 ok
                                     //b2----1 Eeprom and ram parameter err              0 ok
                                     //b3----1 ram ok ,write eeprom err                  0 ok
                                     //b4----1 ram ok ,read eeprom err                   0 ok
                                     //b5----
                                     //b6----
                                     //b7----
extern unsigned int para_err_times;


