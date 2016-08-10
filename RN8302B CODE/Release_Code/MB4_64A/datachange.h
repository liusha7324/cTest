#include "MB_Base_Fun.h"
#ifndef _DATACHANGE_
#define _DATACHANGE_



/*"-----------------------------------------------------------------------------"*/
/*"数据转换函数库"*/
/*"-----------------------------------------------------------------------------"*/
extern unsigned char sizeof_format(unsigned char format);
extern unsigned char TimeToLong(struct DATA_TIME date,unsigned long *dest_data);
//extern unsigned char LongToTime(unsigned long ltime,struct DATA_TIME *dest_data);//delete by zlp for no used
extern unsigned char data_change(unsigned char *src_data,unsigned char *dest_data,
                                 unsigned char in_format,unsigned char out_format,
				                         unsigned char in_unit,unsigned char out_unit,
					                       signed char in_exp,signed char out_exp);
extern unsigned long TimeIndex(unsigned char  *TimePtr);
extern unsigned char IsLeapYear(unsigned  char year);	  
extern void CalWeek(unsigned char *Addr); 
extern unsigned int  const       Not_Rong_Year[]; //365
extern unsigned int  const       Rong_Year[]; //366


#endif


