#ifndef _ENERGY_DEL_H
#define _ENERGY_DEL_H

extern union BYTE_DEF gPD_Data_valid_flag;//b0  0--powerdown save data crc invalid  1--powerdown save data crc valid
                                          //b1  0--powerdown energy data  invalid   1--powerdown energy data  valid
                                          //b2  0--powerdown data are all 0 or ff   1--powerdown data are not all 0 or ff
                                          //b3  0--is innormal reset                1--is normal reset

extern void Check_Energy_main(unsigned char kind);
extern void Write_TO_Cal_PowerDown_Energy_add(void);
#endif


