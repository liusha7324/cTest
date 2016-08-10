#ifndef _H_DEMAND_
#define _H_DEMAND_

#include "sfr64a.h"
#include "defdata.h"
#include "MB_BASE_FUN.h"

#define MAX_DEMAND_AREA              60
#define MAX_DEMAND_TYPE 							8

//define data types//////////////////////////////////////////////////////////////
struct DATETIME_DEMAND
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Minute;
};

//struct DEMAND_DATA
//{
//	unsigned long GMinuteData[8]; //data accumulated per minute
//	unsigned char GChanged; //minute data changed flag
//
//	unsigned long GDemandArea[15][4]; //accumulation area for 15 windows 
//	unsigned char Flags[4]; //flag to judge whether RAM data has been crashed	
//	unsigned char CheckSum; //check sum for DemandArea and GMinuteData	
//};

struct DEMAND_AREA
{
	unsigned long energy_l[6];
	unsigned long energy_h[6];
	unsigned long time;
	
};

struct DEMAND_DATA_NEW
{
	struct DEMAND_AREA Demand_Area[MAX_DEMAND_AREA];/*"需量用电量记录单元 单位0.000001KWH"*/	
	unsigned char Head[2];
	unsigned char Rail[2];		
	unsigned char CheckSum; //check sum for DEMAND_DATA_NEW 
};
//define global data variables///////////////////////////////////////////////////
//extern unsigned long GMinuteData[8]; //data accumulated per minute
//extern unsigned char GChanged; //minute data changed flag




//unsigned long GDemandArea[15][4]; //accumulation area for 15 windows 

extern unsigned char TRAFF_RATE; //current triff rate number
extern struct DEMAND_DATA_NEW Demand_Data_New;
//define functions///////////////////////////////////////////////////////////////

extern struct DEMAND_CONTROL GDemandControl; //control information for demand
extern unsigned long  Last_Average_Value[MAX_DEMAND_TYPE][MAXTRIFF];  //add by pc 081106
extern signed long	Current_Demand[2];
//extern struct DEMAND_DATA DemandData;

//extern unsigned long GDemandArea[15][4]; //accumulation area for 15 windows 

extern unsigned char demand_start;	
extern unsigned char demand_init;


//define functions///////////////////////////////////////////////////////////////


extern int ClearDemandArea(unsigned char mode);
extern void Demand_New_Init(void);
extern void Demand_New_Main(void);
extern void Demand_Accumulator(void);

extern unsigned char DemandputoutNum;
extern unsigned char DemandOutPutflagdata;
extern void Demand_Triff_Change(void);
extern unsigned long  Last_Average_Value[8][MAXTRIFF];/*"当前需量存储空间"*///fxf 081203
#endif
 