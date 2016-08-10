/*********************************************************************************************
*                      fine: ram.h                                                           *
*                      size: 3579 bytes                                                     *
**********************************************************************************************/ 

#ifndef  _RAM_H_
#define  _RAM_H_

#include "defdata.h"



//-----------------public variable-----------------------------
extern volatile unsigned long                     Freq[4]; 
extern volatile unsigned long                     Volt[3];
extern volatile unsigned long                     Voltc[3];
extern volatile unsigned long                     Curr[3];
extern volatile unsigned long                     Factor[4];           
extern volatile unsigned long                     Active_power[4];
extern volatile unsigned long                     Reactive_power[4];
extern volatile unsigned long                     Active_energy_per_sec;
extern volatile unsigned long                     Reactive_energy_per_sec;
extern volatile unsigned long                     Visual_power[4];
extern volatile unsigned char                     Reactive_phase[4];
extern volatile unsigned long                     Phase_Angle[4];
extern volatile unsigned long                     N_Current;
 
extern volatile struct METER_STATES               Meter_States;

extern volatile struct NEW645METER_STATES             NEW645Meter_States;//FXF ADD 081114

extern volatile struct METER_PARAMETER            Meter_Parameter;

extern union EVENT_POWER_NET_FLAG       Event_Power_Net_Flag;
//extern union EVENT_POWER_NET_FLAG       Event_Power_Net_Old_Flag; //mw closed 2009-10-09
//extern struct EVENT_METER_PROGRAM_FLAG   Event_Meter_Program_Flag;  //mw closed 2009-10-09
extern struct EVENT_POWER_NET_POINTER    Event_Power_Net_Pointer;
extern struct EVENT_METER_PRO_POINTER    Event_Meter_Pro_Pointer;
extern struct EVENT_POWER_NET_TIMES      Event_Power_Net_Times;
extern struct EVENT_METER_PRO_TIMES      Event_Meter_Pro_Times;
extern struct EVENT_POWER_NET_TIMETICKS  Event_Power_Net_Timeticks;

extern struct POWERDOWN_SAVE_DATA        Powerdown_Save_Data;

extern struct ENERGY_RAIL_ADD_BUFFER     energy_rail;

extern struct THIS_MONTH_DATA            This_Month_Data;

//extern struct MINUTE_COPY_ENERGY         Minute_Copy_Energy;

extern struct OTHER_DATA                 Other_Data;

//extern struct LOSSVOLTAGE_ENERGY         LossVoltage_Energy;  //change by pc 081124

//extern struct LOSSCURRENT_ENERGY         LossCurrent_Energy;  //change by pc 081124

//extern struct TOTAL_POWERRESERVE_ENERGY  PowerReserve_Energy; //change by pc 081124

extern struct POWERRESERVE_ENERGY_SING   CurrentImbalance_Energy[3];

extern union  CoBuff                     Co; 

extern unsigned char                     WriteWhitchEeprom[3];

extern struct ENERGY_POWERDOWN           Cal_PowerDown_Energy_add;

extern union  BYTE_BIT                   TimeChontrolFlag;

extern union  BYTE_BIT                   ProgramRunPhaseFlag;

extern union  BYTE_BIT                   WriteTimeFlag;

extern union  BYTE_BIT                   Event_Time_Flag;
extern union  BYTE_BIT                   Alarm_Map_Flag[3];

extern struct DATEANDTIME_DEF            MainSoftDate;

extern struct DATEANDTIME_DEF            MainRamDate1;

extern struct DATEANDTIME_DEF            MainRamDate2;

extern struct OTHER_METER_PARAMETER      O1ther_Meter_Parameter; /*"掉电保存的某些参数"*/
extern unsigned char                     Max_Triff_Current; /*" 当前最大费率"*/
extern volatile unsigned long         Active_power_Per_Mintue;    /*" 一分钟有功平均功率"*/
//extern unsigned char                     Single_Voltage_Down_70_Persent;  /*"单相电压低于70％标志"*/

extern volatile int Temperature_Current;//fuxf 20090512
extern struct Show_Powerdown_Data_Struct Show_Powerdown_Cyc_Data[99];
extern struct Show_Powerdown_Data_Struct Show_Powerdown_Key_Data[120];
extern unsigned char Show_ID_vatiy;
extern union EVENT_POWER_NET_FLAG       Show_Powerdown_Net_Flag_Backup; 
extern unsigned char Show_flash_poweron_vatiy;
extern unsigned char show_which_now;

//extern struct PEAK_METER_PARAMETER       Peak_Meter_Parameter;
//extern struct PEAK_THIS_MONTH_DATA       Peak_This_Month_Data;

//------------------------------------------------------------------
extern void Check_Max_Imbalance_Rate(void);

#endif

/****************************************--------end------***********************************/ 
