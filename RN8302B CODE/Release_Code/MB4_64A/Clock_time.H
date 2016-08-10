#ifndef _CLOCK_TIME_H
#define _CLOCK_TIME_H

extern unsigned char AddTime(void);
extern unsigned char PowerUp_Init_RTC(unsigned char neweeprom, double long *datatime);
extern void ReadRTC(void); 
extern unsigned char  CheckRamTime(void);

extern unsigned long rtc_lossvolt_flag;
extern unsigned char rtc_lossdata_flag;

#endif //end _CLOCK_TIME_H

