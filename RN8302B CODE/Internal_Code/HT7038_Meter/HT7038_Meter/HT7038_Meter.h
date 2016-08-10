/************************************************************
  Copyright (C), 1988-1999, Wasion Group 
  FileName:     71M6545_Meter.h
  Description:  71M6545_Meter header file
  Author:    jiehuang,wumin      
  Version :  1.0        
  Date:   2015/08/06 
  Funciton list:

  
  History:         
      <author>    <time>    <version >    <desc>
      jiehuang,wumin  2015/08/06    1.0           build this moudle  
***********************************************************/
  
#ifndef __71M6545_Meter_H__
#define __71M6545_Meter_H__

//****************************************************************
//about basic type and macro define
//****************************************************************
typedef unsigned char          INT8U;
typedef signed char             INT8S;
typedef unsigned int            INT16U;
typedef signed int               INT16S;
typedef unsigned long          INT32U;
typedef signed long             INT32S;
typedef unsigned long long   INT64U;
typedef signed long long      INT64S;
typedef unsigned char          BOOL;
typedef float                 FP32;
typedef double              FP64;

#define FALSE   0
#define TRUE    1

#define SV_PIN_INPUT         0
#define SV_PIN_OUTPUT      1

#define SV_LOW           0
#define SV_HIGH          1

#define SV_DISABLE        0
#define SV_ENABLE         1

//****************************************************************
//about  software verison
//****************************************************************
#define WS_METER_SW_VER     0x15083100

//****************************************************************
//about Customer special funciton defined 
//****************************************************************

#define WS_DEMO_VERSION
#ifdef WS_DEMO_VERSION
 #endif

//****************************************************************
//about Common funciton defined
//****************************************************************
//#define WS_SUPPORT_SIMULATION  //add by jie huang 2011/05/13 to support simulation function


//other
#define WS_DEAL_71M6545_SPEC_STATUS  //add by jiehuang 20110623 to deal with 71M6545 special status
 

//****************************************************************
//about buffer define
//****************************************************************
typedef struct _stMeter_Data_Buffer
{
    INT32U dwVolt[3];       //ABC voltage unit 0.0001V
    INT32U dwCurr[3];      //ABC current unit 0.0001A

    INT32U dwNCurr;        //N line current sample value, unit 0.0001A
    INT32U dwNCurrCal;      //N line current calculated value, unit 0.0001A

    INT8U bPowerDir;       //power direction
    INT32U dwP[4];        //TABC active power, unit 0.000001kW
    INT32U dwQ[4];        //TABC reactive power, unit 0.000001kVar   
    INT32U dwS[4];        //TABC apparent power, unit 0.000001kVA

    INT32U dwFre[3];     //frequency, unit 0.000001Hz

    INT32U dwUAngle[3];    //ABC angle between voltage,unit 0.01 degree
    INT32U dwPAngle[3];    //ABC angle between vlotage and current, unit 0.01 degree

    INT32U dwPF[4];      //TABC power factor,unit 0.000001

    INT32S lTemp;     //temperature, UNIT: 0.1 degree

    INT8U bState0;
    INT8U bState1;
    INT8U bState2;

    BOOL fgNoLoad ;  //meter in no load flag

    INT32U dwActEnergy[4];   //TABC forward active energy
    INT32U dwReActEnergy[4];  //TABC forward reactive energy
}stMeter_Data_Buffer;

//****************************************************************
//about  bPowerDir 
//****************************************************************
/*
   power direction
   b0=1-reactive power of phase A is negative "-"
	  0-reactive power of phase A is positive "+"
  b1=1-reactive power of phase B is negative "-"
        0-reactive power of phase B is positive "+"
  b2=1-reactive power of phase C is negative "-"
        0-reactive power of phase C is positive "+"
  b3=1-reactive power of sum is negative "-"
        0-reactive power of sum is positive "+"
  b4=1-active power of phase A is negative "-"
       0-active power of phase A is positive "+"
  b5=1-active power of phase B is negative "-"
       0-active power of phase B is positive "+"
  b6=1-active power of phase C is negative "-"
       0-active power of phase C is positive "+"
  b7=1-active power of sum is negative "-"
       0-active power of sum is positive "+"
*/

enum
{
    POWERDIR_REACT_POWER_A,
    POWERDIR_REACT_POWER_B,
    POWERDIR_REACT_POWER_C,
    POWERDIR_REACT_POWER_SUM,
    POWERDIR_ACT_POWER_A,
    POWERDIR_ACT_POWER_B,
    POWERDIR_ACT_POWER_C,
    POWERDIR_ACT_POWER_SUM
};

//****************************************************************
//define bit for the REG_SFLAG register  
//****************************************************************
#define SFLAG_VOLT_ORDER_ERR    3
#define SFLAG_CURR_ORDER_ERR   4

#define SFLAG_A_NOLOAD    9
#define SFLAG_B_NOLOAD    10
#define SFLAG_C_NOLOAD    11

//****************************************************************
//about  bState0 
//****************************************************************
/*
	0:voltage normal phase sequence     
	1: voltage abnormal phase sequence
	0:current normal phase sequence
	1:currentabnormal phase sequence       
*/
enum
{
    STATE0_RESERVED0,
    STATE0_RESERVED1,
    STATE0_VOLT_PHASE_SEQU,
    STATE0_CURR_PHASE_SEQU,
    STATE0_RESERVED4,
    STATE0_RESERVED5,
    STATE0_RESERVED6,
    STATE0_RESERVED7
};

//****************************************************************
//about  energy type
//****************************************************************
enum
{
    READ_ENERGY_ACT,
    READ_ENERGY_REACT,
    READ_ENERGY_MAX
};

//****************************************************************
//about meter paramter struct
//****************************************************************
#define METER_71M6545_PARA_SIZE   (sizeof(struct stMeter_71M6545_Para)/4)
struct stMeter_71M6545_Para      
{ 
    INT32U   meter_mode;           //0:341  ;1:331     0
    INT32U   plus_const;           //PLUS CONST,000000H      1
    INT32U   reserve_current;      //潜动阀值         2
    INT32U   I_PainA;              //I_PainA,         3
    INT32U   V_PainA;              //V_PainA，        4
    INT32U   I_PainB;              //I_PainB,         5
    INT32U   V_PainB;              //V_PainB,         6
    INT32U   I_PainC;              //I_PainC,         7
    INT32U   V_PainC;              //V_PainC,         8
    INT32U   Phase_A;              //PHASE_A,         9
    INT32U   Phase_B;              //PHASE_B,         A
    INT32U   Phase_C;              //PHASE_C,         B
    INT32U   Temprature;           //TEMP,            C
    INT32U   Active_Imin;          //小电流A有功精度微调,     D
    INT32U   Reactive_Imin;        //REACTIVE_Imin,   E
    INT32U   Energy_Add_Mode;      //EaddMode,        F
    INT32U   V_region;             //VMAX,            10
    INT32U   I_region;             //IMAX,            11
    INT32U   Add_CHK;              //Add_CHK,         12
};  

#define METER_SPEC_PRA_SIZE   (sizeof(struct stMeter_Spec_Para)/4)                                         
struct stMeter_Spec_Para  //meter specs parameter
{      
    INT32U dwPwrLimit;           
    INT32U dwEngLimit;                
    INT32U dwCFConstH;             
};

//the position must match with JUSTMETER_PARAMETER !!!
typedef struct _stMeter_Just_Para_Def
{
    INT32U stMeter_71M6545_Para_Init[METER_71M6545_PARA_SIZE];
    INT32U stMeter_Spec_Para_Val_Init[METER_SPEC_PRA_SIZE];
}stMeter_Just_Para_Def;

enum
{
    METER_RST_TYPE_PWRUP,
    METER_RST_TYPE_PWRDOWN,

    METER_RST_TYPE_PRAERR,
    METER_RST_TYPE_RDERR,
    METER_RST_TYPE_VALERR,

    METER_RST_TYPE_MAX
};
 
extern INT32U _dwMeter_Version;  //Meter driver version 

extern INT8U _bMeter_DataRdErrCnt;
extern INT8U _bMeter_DataValErrCnt;
extern BOOL _fgMeter_DataReady;
extern INT8U  _bMeter_RstType;    
extern INT16U _wMeter_RstCnt;

extern BOOL _fgMeter_NeedLoadPara;

extern INT8U TDK6545_ready_flag;

extern stMeter_Data_Buffer  _rMeter_Data_Buffer;

extern void vDelay_Us(INT16U wCnt);
extern void vDelay_Ms(INT16U wCnt);

extern INT32U dwRead_TDK71M6515_Data(INT8U bRegAddr);
extern void vWrite_TDK71M6515_Data(INT8U bRegAddr,INT32U dwData);
extern void vMeter_71M6545_WriteCtrl(BOOL fgCtrl);
extern void TDK6545_Ready_Check(void);
extern void vMeter_Version(void);
extern void vMeter_Init(INT8U bType);

extern BOOL fgMeter_Para_Init(void);
extern BOOL fgMeter_Function(void);
extern BOOL fgMeter_Com_JustParaSet(INT8U bCommAddr,INT32U dwCalData);
extern BOOL fgMeter_Para_Load(void);    
extern BOOL fgMeter_ICParaOk(void);

extern BOOL fgMeter_Para_Load(void);    
extern BOOL fgMeter_GetVolt(void);
extern BOOL fgMeter_GetCurr(void);
 
#endif


