/*"冻结程序 for DL645-2007"*/
/*"creat by trend "*/
/*"ver 1.0 2008-10-25 10:54:27"*/
#include "datachange.h"



extern void Freeze_Main(void);
extern void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime);///king chen modify 130609
extern void Record_HDFreeze(void); 
extern void Day_freeze(unsigned char sort);
extern void Clear_HDFreezeData(void);
extern void PoweronFreeze_Deal(void);
extern unsigned char  Clear_Freeze(void);
extern void  Clear_Freeze_Period(void);	
extern void PowerUpDayFreeze(void);///king chen add 121214

extern unsigned char ComparentTime(unsigned char *t1, unsigned char *t2);///king chen add 130308

extern void ClearFreezeCommDeal(unsigned long Data_ID);


#ifndef _FREEZE_H_
#define _FREEZE_H_

#define ResultSmaller   1
#define ResultEqual       2
#define ResultLarger     3

typedef struct _DATE_TIME
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
	unsigned char Week;
}TDateTime, *PDateTime;

typedef struct _DATE
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
}TDate, *PDate;

struct FREEZE_ENERGY_DATA
{
	unsigned long  Plus_Active[MAXTRIFF]; 
	unsigned long  Nega_Active[MAXTRIFF];
	
	unsigned long  Quad_Reactive[4][MAXTRIFF];
};
struct FREEZE_DEMAND_DATA
{
	unsigned long  Plus_Active_Demand[MAXTRIFF];
	unsigned char  Plus_Active_Demand_Time[MAXTRIFF][5];
	unsigned long  Nega_Active_Demand[MAXTRIFF];
	unsigned char  Nega_Active_Demand_Time[MAXTRIFF][5];

};
struct FREEZE_POWER_DATA
{
	signed long Active_power_t[4];
	signed long Reactive_power_t[4];
};
struct FREEZE_DATA//415 bytes
{
	unsigned char  Time[5];
	struct FREEZE_ENERGY_DATA Energy;
	struct FREEZE_DEMAND_DATA Demand;
	struct FREEZE_POWER_DATA Power;
};

struct CLEARFREEZE_STRU
{
unsigned int     Pointer_addr;                   /*"指针内卡地址"*/
unsigned char    *Pointer;  		                 /*"指针"*/
unsigned int     Filename_begin;                 /*"文件起始"*/
};
extern const unsigned long Clearfreeze_ID[9];
#endif


int GetSkipedTimeFlags(TDateTime* rpTime1, TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax);///king chen add 130308
unsigned char CheckDateTime(TDateTime* rpDateTime);				//HeZhaoHui   20131010

