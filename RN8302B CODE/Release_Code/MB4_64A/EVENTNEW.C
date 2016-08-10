/********************************************************
*                      fine: event.c                    *
*                      function:  register event        *
*********************************************************/  


#include "sfr64a.h"
#include "ram.h"
#include "I2C_operation.h"
#include "Defdata.h"
#include "Eeprom.h"
#include "Comm.h"
#include "att7022_operation.h"
#include "initcpu.h"
#include "multi.h"
#include "File_System.h"
#include "Demand.h"
#include "datachange.h"
#include "Measure_Interface.h" 
#include "initram.h"
#include "MB_Keymain.h"

#include "pay_def.h"
#include "Ex_Pay_For_Fun.h"
#include "Far_pay.h"	//farpayment 
#include "ICcard.h"
#include "AllVoltageLoss.h"//ganjp 20090326
#include "Energy_Del.h"
#include "interrupt.h"  //mw added 2010-05-30
#include "freeze.h"

#include "Measure_Interface.h"

#include "Clock_time.H"

//---------- declaration ----------//
//---------- declaration ----------//

/*********** define  variable ***************************/
//union  BYTE_BIT     LossVoltage_Flag;  /*"ABC三相失压标志"*/ 
//union  BYTE_BIT     LossCurrent_Flag;  /*"ABC三相失流标志"*/

//union  BYTE_BIT     LossVoltage_Display_Flag; /*"ABC三相显示失压标志，提前开始，推迟结束"*/
//union  BYTE_BIT     LossCurrent_Display_Flag; /*"ABC三相显示失流标志，提前开始，推迟结束"*/

union  BYTE_BIT     ProgramFlag[2];           /*"编程标识字"*/
struct EVENT_POWER_NET_POINTER   Event_N;     /*"电网事件记录连续次数"*/											/*"30秒计数器"*/
union  EVENT_POWER_NET_FLAG      Event_B;     /*"电网事件记录开始标志"*/													/*"开始起始标志"*/
union  EVENT_POWER_NET_FLAG      Event_S;     /*"电网事件记录结束标识"*/

//unsigned char *epointer;      /*"事件记录内卡指针"*/  //change by pc 081222
//unsigned int  eaddr;          /*"事件记录内卡首地址"*/  //change by pc 081222
//unsigned int  elength;        /*"事件记录长度"*/  //change by pc 081222
//unsigned int  edatalength;    /*"事件记录时走的电量数据结构长度"*/  //change by pc 081222
//union  BYTE_BIT eComflag;     /*"写事件记录时，分类"*/  //change by pc 081222
//unsigned char *raddr;         /*"事件记录时走的电量的内存地址"*/  //change by pc 081222
//unsigned char echannel;       /*"过压写事件记录时，分类"*/  //change by pc 081222
//unsigned char Program_mode[2]; /*"编程标识字"*/  //change by pc 081214
struct DATEANDTIME_DEF OverPowerAlarmTime;  /*"超功率报警起始时间"*/
unsigned  char OverPowerAlarmFlag;        /*"超功率跳闸标志，0－合闸，1－跳闸"*/
unsigned  char Clear_Demand_Mode;         /*"清需模式"*/
//unsigned  char VoltageReserve_Flag;   /*"电压逆相序"*/  //change by pc 081129

//unsigned char Check_LossVoltage_AC_331[2];  /*"三相三线，B相失压时，不判AC相计数器"*/

//unsigned  char count_forwait;

//------------------------  New 645 Variable  ------------------------//
unsigned char EventCriticalVoltage_Flag=0;
unsigned char EventDataValid_Flag=0;
unsigned char EventTimeTicksValid_Flag=0;  //mw added 2010-06-01
unsigned char EventEnergyValid_Flag=0;
unsigned char currimbalancecs=0;
unsigned char voltimbalancecs=0;
unsigned long EventUn=0;
unsigned long EventIb=0;

struct PowerDown_EventSave_Data  PdEventData;

//unsigned char opencoverdate[6];  //mw closed 2009-09-03
//unsigned char openboxdate[6];     //mw closed 2009-09-03
///unsigned char opencoverdate[2][6];  //mw added  2009-09-03
unsigned char TempEventData[400]={0};
//unsigned char NowJudge331BLostVoltFlag=0;
//unsigned char NowJudge331BBreakPhaseFlag=0;
unsigned long lostvoltenergyall[2];
unsigned long lostvoltenergy[6];
//unsigned long lostvoltenergyreaddata[6];
//unsigned char Phase3LostVoltTimeValidFlag=0;

struct VoltStatistic_Data VoltStat[4];  //0-A Phase 1-B Phase 2-C Phase 3-T Phase
unsigned long Event_AmpHour[3];
/*"为了上电时数据转移方便采用块移，下面6个数据项的定义必须定义在一起"*/
unsigned long Event0BeginAmpHour[36];
unsigned int CrcEvent0Flag;
unsigned int CrcEventPowerDownData;
unsigned int CrcVoltStatData;
unsigned int CrcEventTimeTicks;  //mw added 2010-06-01
unsigned long maximbalancerate[3];  //0-curr 1-volt 2-far curr


unsigned long savemaximbalancerate[3];  //0-curr 1-volt 2-far curr
unsigned char VoltStatTimeCounter;

extern unsigned char Read_event_first_flag;
//------------------------  New 645 Variable  ------------------------//

struct	PDOPENCOVER_STRUCTURE  pdopencovercheckdata[2];

struct DEMAND_DATA_FORM overdemandmaxdemand[6];

unsigned char powerreversetflag[2];
unsigned char powerreversetcnt[2];

unsigned long eventmaxvolt;
unsigned long eventminvolt;
unsigned long eventmaxcurr;
unsigned long eventmincurr;
unsigned long eventavgcurr;

union EVENTSTATUS eventstatusinfo;

struct	RST90E36_STRUCTURE rst90e36info;

unsigned char lostvoltagetime[3][2];

/*********** define  function ***************************/
//unsigned char Event(unsigned char);  //change by pc 081129
//void Event1(unsigned long);  //change by pc 081214
//void WriteEvent(unsigned char ,unsigned int,unsigned long);  //change by pc 081129
void EventTimeAdd(void);
//void WriteEventToE(void);  //change by pc 081214
//void Write_PowerReserve_Energy(unsigned char,unsigned char,unsigned char);
//void ReadyDataForFreeze(unsigned char );  //change by pc 081214
///extern void FreezeDateProgram(unsigned char ,unsigned char,unsigned char);
extern void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime);///king chen modify 130609
//-------------------------  New 645 Declaration  ----------------------//
void New2007_Event(void);
void InitNew2007Event(void);
//void EventRecordAdjustEnergy(void);
unsigned int EventData_crc(void);//ganjp 2010-05-28
void EventData_PowerDown_Save(void);
unsigned char EventData_PowerOn_Check(void);
unsigned char EventRecord_Poweron_Check(void);
void LostVoltageEvent(void);
//unsigned char Save_LostVoltBegin_Data(unsigned int);
//unsigned char Save_LostVoltageEnd_Data(unsigned int,unsigned int,unsigned char,unsigned char);
//unsigned char Save_LostVoltPdEnd_Data(unsigned int,unsigned int,unsigned char,unsigned char *);
void PowerDownEvent_OnCheck(void);
unsigned int ProgrammeEvent(unsigned long,unsigned long);
void ProgrammeEventEnd_Check(void);
void ProgrammeEventEnd_Check_Payment(void);
unsigned int ClearMeterRecord(unsigned long);
//void OpenCoverEventCheck(void);
void VoltStatisticEvent(void);
void VoltStatisticFunc(void);
void VoltStatSetDefault(void);
void VoltStatInit(void);
void VoltStatisticCheck(void);
void VoltStatisticBill(void);
//unsigned char Save_LostCurrBegin_Data(unsigned int);
//unsigned char Save_LostCurrEnd_Data(unsigned int,unsigned int,unsigned char,unsigned char);
//unsigned char Save_LostCurrPdEnd_Data(unsigned int,unsigned int,unsigned char,unsigned char *);
void LostCurrentEvent(void);
void BreakPhaseEvent(void);
//unsigned char Save_VoltReverseB_Data(unsigned int);
//unsigned char Save_VoltReverseE_Data(unsigned int,unsigned int,unsigned char,unsigned char);
//unsigned char Save_VoltReversePdE_Data(unsigned int,unsigned int,unsigned char,unsigned char *);
void VoltReverseEvent(void);

void OverDemandEvent(void);
void PrepOverDemandFirstEventData(unsigned long);

void PowerReverseEvent(void);
void ALLPowerReverseEvent(void);
unsigned int AdjustTimeRecord(unsigned long);
unsigned int ClearDemandRecord(unsigned long);
unsigned int ClearEventRecord(unsigned long,unsigned long);
unsigned int ProgWeekRecord(unsigned long,unsigned char);
//unsigned int ProgAEModeRecord(unsigned long,unsigned char);
//unsigned int ProgNEMode1Record(unsigned long,unsigned char);
//unsigned int ProgNEMode2Record(unsigned long,unsigned char);
unsigned int ProgBillDayRecord(unsigned long,unsigned char *);
unsigned int ProgYearSlotRecord(unsigned long);
unsigned int ProgDailySlotRecord(unsigned long);
//void ProgHolidayRecord(unsigned long);
//void OpenBoxEventCheck(void);
void OverVoltageEvent(void);
unsigned char ClearNewEventRecord(unsigned long,unsigned long);
void Phase3LostVoltEvent(void);
void OverDemandAlarmEvent(void);
//void ClockBatteryEvent(void);
//void DisplayBatteryEvent(void);
//void AdjustMeterEvent(unsigned char);
int PrepVoltStatReadData(void);
void ResetCpuEvent_OnCheck(void);
void RunClockErrorRecord(void);
void PowerUpClockErrorRecord(void);
void EepromErrorRecord(void);
void EnergyPassZeroRecord(void);
void SetPrimaryRecord(void);
void EepromEventSetDefault(void);
void EMeterPowerdownRecord(void);
void VoltageDownEvent(void);
void OverCurrentEvent(void);
void SaveLostVoltTime(unsigned int,unsigned char);
void LostVoltEnergyAdd(unsigned int,unsigned char);
int   PrepLostVoltEnergyData(unsigned long);
void UpLoadEvent(void);
void CurrReverseEvent(void);
void OverFactorEvent(void);
void FailCurrentEvent(void);
unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times);

void OpenBoxCoverEvent_Check(void);
void ClockBatteryDisplayBattery_Event(void);
void CurrVoltImBalance_Event(void);
void Save_SignalPhase_Statistic(unsigned char* Statistic,
											    unsigned char* DataBuff,
											    unsigned int FOffset);
void Clear_SignalPhase_VoltStatistic_Data(unsigned char*  SignaPhase);
unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,
															unsigned char  progoldvaluep,unsigned char sort);
void Copy_ENERGY_TO_CO(unsigned int startIndex);//add by zlp
//void Copy_ENERGY_TO_CO_End(unsigned int startIndex,unsigned int  EnergyPassMAXTimesIndex);//add by zlp
//void Copy_ENERGY_FF_TO_CO(unsigned int startIndex);//add by zlp
//void Copy_AmpHour_TO_CO(unsigned int startIndex);//add by zlp
//unsigned char Save_ProgrammeEvent_Pack(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
//unsigned char Save_CurrImBalance_Pack(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
//unsigned char Save_VoltImBalance_Pack(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
//unsigned char Save_OverPaNeADemand_Pack(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
void EventFlagPowerOnInit(void);
unsigned char PrepEvent0Data(unsigned int);
unsigned long Cal_LastTime(unsigned char* eventbegintimepointer, unsigned char* eventendtimepointer);
void SaveEvent0LastTime(unsigned int,unsigned char,unsigned char*,unsigned int,unsigned long*);
void SaveEvent0BeginAmpHour(unsigned char);
void Cal_AmpHour_poweron(unsigned int eventaddr, unsigned char kind);
void SaveEvent0EndAmpHour(unsigned char);
void ClearEvent0Flag(unsigned char,unsigned char);
void MoveEventData2Flash(unsigned int,unsigned int,unsigned char *,unsigned char);
void AdjustMeterRecord(void);
void AdjustMeterRecordEndCheck(void);
unsigned char PrepLostVoltFirstEventData(unsigned int,unsigned char,unsigned char,unsigned char);
unsigned char PrepNewFirstEventData(unsigned long);
void Write_File_PdEvent(unsigned int,unsigned int,unsigned char,unsigned char *);
unsigned long  Prepare_For_EventLastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer);
//unsigned char Refresh_EventData_ForLastTime(unsigned long eventcode);
void Refresh_EventData(unsigned long eventcode);
unsigned char Refresh_AddTime(unsigned long eventcode);
void SaveEvent0LastTime_Other(unsigned int eventlasttimeaddr,
	unsigned long* eventlasttimepointer);  //mw modified 2010-06-01
void ClearEventDate_BatteryPowerOn(void);
void Check_Max_Imbalance_Rate(void);

void ConstantMagnetEventCheck(void);

void PowerAbnormalEventCheck(void);

void PdOpenCoverCheckInit(unsigned char);
void PdOpenCoverCheck(void);
unsigned char CheckOpenCoverDataValid(unsigned char);
void PdOpenCoverCheckPowerUpDeal(void);
unsigned char CheckOpenCoverState(unsigned char);

unsigned char ClearProgDailySlotRecord(unsigned long,unsigned long);
unsigned char ClearEventAddEnergy(unsigned int eventeepromaddr);
void ClearEventAll(void);
void ClearEventCommDeal(unsigned long eventID);
void ClearEventDataPowerOn(void);
void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file);

void Rst90E36Event(void);

unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times);

void Save_Event_StartData_Flash(unsigned char *eventp,unsigned int eventpaddr,
                                unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                                unsigned long *eventtimes,unsigned int eventtimesaddr);

void Save_Event_EndData_Flash(unsigned char eventp,
                              unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                              unsigned long *eventtimeticks,unsigned int eventtimeticksaddr);
                              
void Save_Record_Data_Flash(unsigned char *eventp,unsigned int eventpaddr,
                            unsigned int filename,unsigned char fileendaddr,
                            unsigned long *eventtimes,unsigned int eventtimesaddr);

void Save_Event_StartData_Eeprom(unsigned char *eventp,unsigned int eventpaddr,
                                 unsigned int eepromaddr,unsigned char len,
                                 unsigned long *eventtimes,unsigned int eventtimesaddr);

void CloseOverPowerAlarmSwitch(void);

#define   NULL  (void*)0 

/*"结构CLEAREVENT_STRU1中无用的指针请填NULL"*/
#pragma SECTION rom UserROMData
const struct CLEAREVENT_STRU  ClearEvent_Leaf[]={
{0,0,LOSTVOLTAGE_A_TIMES_ROM,LOSTVOLT_A_TIMETICKS_ROM,NULL,NULL,NULL,&Event_Power_Net_Times.LostVoltage_A_Times,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,0,12,0,0,0x41},
{LASTLOSTVOLT_A_ROM,LOSTVOLTAGE_A_P_ROM,LOSTVOLTAGE_A_TIMES_ROM,LOSTVOLT_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_A_Times,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,0x01,255,LOSTVOLT_A_BEGINFILE,10,0x9E},
{LASTLOSTVOLT_B_ROM,LOSTVOLTAGE_B_P_ROM,LOSTVOLTAGE_B_TIMES_ROM,LOSTVOLT_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_B_Times,&Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks,0x02,255,LOSTVOLT_B_BEGINFILE,21,0x9E},
{LASTLOSTVOLT_C_ROM,LOSTVOLTAGE_C_P_ROM,LOSTVOLTAGE_C_TIMES_ROM,LOSTVOLT_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_C_Times,&Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks,0x04,255,LOSTVOLT_C_BEGINFILE,32,0x9E},
{0,OVERVOLTAGE_A_P_ROM,OVERVOLTAGE_A_TIMES_ROM,OVERVOLT_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_A_Times,&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks,0x08,0,OVERVOLT_A_BEGINFILE,368,0x1E},
{0,OVERVOLTAGE_B_P_ROM,OVERVOLTAGE_B_TIMES_ROM,OVERVOLT_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_B_Times,&Event_Power_Net_Timeticks.OverVoltage_B_Times_Ticks,0x10,0,OVERVOLT_B_BEGINFILE,379,0x1E},
{0,OVERVOLTAGE_C_P_ROM,OVERVOLTAGE_C_TIMES_ROM,OVERVOLT_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_C_Times,&Event_Power_Net_Timeticks.OverVoltage_C_Times_Ticks,0x20,0,OVERVOLT_C_BEGINFILE,390,0x1E},
{0,BREAKPHASE_A_P_ROM,BREAKPHASE_A_TIMES_ROM,BREAKPHASE_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_A_Times,&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks,0x01,0,BREAKPHASE_A_BEGINFILE,159,0x1E},
{0,BREAKPHASE_B_P_ROM,BREAKPHASE_B_TIMES_ROM,BREAKPHASE_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_B_Times,&Event_Power_Net_Timeticks.BreakPhase_B_Times_Ticks,0x02,0,BREAKPHASE_B_BEGINFILE,170,0x1E},
{0,BREAKPHASE_C_P_ROM,BREAKPHASE_C_TIMES_ROM,BREAKPHASE_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_C_Times,&Event_Power_Net_Timeticks.BreakPhase_C_Times_Ticks,0x04,0,BREAKPHASE_C_BEGINFILE,181,0x1E},
{LASTPHASE3LOSTVOLT_ROM,PHASE3LOSTVOLT_P_ROM,PHASE3LOSTVOLT_TIMES_ROM,PHASE3LOSTVOLT_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.Phase3LostVolt_Times,&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,0x10,16,PHASE3LOSTVOLT_BEGINFILE,401,0x9E},
{0,VOLTAGERESERVE_P_ROM,VOLTAGERESERVE_TIMES_ROM,VOLTAGERESERVE_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.VoltageReserve_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.VoltageReserve_Times,&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks,0x08,0,VOLTREVERSE_BEGINFILE,192,0x1E},
{0,VOLTIMBALANCEEVENT_P_ROM,VOLTIMBALANCEEVENT_TIMES_ROM,VOLTIMBEVENT_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.VoltImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.VoltImBalanceEvent_Times,&Event_Power_Net_Timeticks.VoltImBalanceEvent_Times_Ticks,0x80,0,VOLTIMBALANCEEVENT_BEGINFILE,522,0x1E},
{0,CURRIMBALANCEEVENT_P_ROM,CURRIMBALANCEEVENT_TIMES_ROM,CURRIMBEVENT_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.CurrImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.CurrImBalanceEvent_Times,&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks,0x40,0,CURRIMBALANCEEVENT_BEGINFILE,511,0x1E},
{0,LOSTCURRENT_A_P_ROM,LOSTCURRENT_A_TIMES_ROM,LOSTCURRENT_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_A_Times,&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks,0x20,0,LOSTCURR_A_BEGINFILE,126,0x1E},
{0,LOSTCURRENT_B_P_ROM,LOSTCURRENT_B_TIMES_ROM,LOSTCURRENT_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_B_Times,&Event_Power_Net_Timeticks.LostCurrent_B_Times_Ticks,0x40,0,LOSTCURR_B_BEGINFILE,137,0x1E},
{0,LOSTCURRENT_C_P_ROM,LOSTCURRENT_C_TIMES_ROM,LOSTCURRENT_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_C_Times,&Event_Power_Net_Timeticks.LostCurrent_C_Times_Ticks,0x80,0,LOSTCURR_C_BEGINFILE,148,0x1E},
{0,POWERREVERSE_A_P_ROM,POWERREVERSE_A_TIMES_ROM,POWERREVERSE_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_A_Times,&Event_Power_Net_Timeticks.PowerReverse_A_Ticks,0x01,0,POWERREVERSE_A_BEGINFILE,225,0x1E},
{0,POWERREVERSE_B_P_ROM,POWERREVERSE_B_TIMES_ROM,POWERREVERSE_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_B_Times,&Event_Power_Net_Timeticks.PowerReverse_B_Ticks,0x02,0,POWERREVERSE_B_BEGINFILE,236,0x1E},
{0,POWERREVERSE_C_P_ROM,POWERREVERSE_C_TIMES_ROM,POWERREVERSE_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_C_Times,&Event_Power_Net_Timeticks.PowerReverse_C_Ticks,0x04,0,POWERREVERSE_C_BEGINFILE,247,0x1E},
{VOLTSTATISTICDATA_A_ROM,VOLTSTATISTIC_A_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],NULL,NULL,NULL,0x01,0,VOLTSTATISTIC_A_BEGINFILE,89,0x24},
{VOLTSTATISTICDATA_B_ROM,VOLTSTATISTIC_B_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],NULL,NULL,NULL,0x08,1,VOLTSTATISTIC_B_BEGINFILE,102,0x24},
{VOLTSTATISTICDATA_C_ROM,VOLTSTATISTIC_C_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],NULL,NULL,NULL,0x01,2,VOLTSTATISTIC_C_BEGINFILE,115,0x24},
{LASTPOWERDOWNEVENT_ROM,POWERDOWN_P_ROM,POWERDOWN_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.PowerDown_Times,NULL,0x40,12,POWERDOWNEVENT_BEGINFILE,43,0x8E},
{0,0,OVERPAADEMAND_TIMES_ROM,OVERPAADEMAND_TIMETICKS_ROM,NULL,NULL,NULL,&Event_Power_Net_Times.OverPaADemand_Times,&Event_Power_Net_Timeticks.OverPaADemand_Times_Ticks,0,8,0,0,0x01},
{0,OVERPAADEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.OverPaADemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,NULL,NULL,0x40,0,OVERPAADEMAND_BEGINFILE,203,0x06},
{0,OVERNEADEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.OverNeADemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,NULL,NULL,0x80,0,OVERNEADEMAND_BEGINFILE,214,0x06},
{LASTPROGRAMME_ROM,PROGRAMMEEVENT_P_ROM,PROGRAMMEEVENT_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.ProgrammeEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(unsigned char*)&PdEventData.eventflag[10].byte,&Event_Power_Net_Times.ProgrammeEvent_Times,NULL,0x10,50,PROGRAMMEEVENT_BEGINFILE,54,0x8E},
{0,CLEARDEMANDRECORD_P_ROM,CLEARDEMANDRECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ClearDemandRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ClearDemandRecord_Times,NULL,0,0,CLEARDEMANDRECORD_BEGINFILE,269,0x0C},
{0,ADJUSTTIMERECORD_P_ROM,ADJUSTTIMERECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.AdjustTimeRecord_P,NULL,NULL,&Event_Meter_Pro_Times.AdjustTimeRecord_Times,NULL,0,0,ADJUSTTIMERECORD_BEGINFILE,258,0x0C},
{0,PROGWEEKRECORD_P_ROM,PROGWEEKRECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgWeekRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ProgWeekRecord_Times,NULL,0,0,PROGWEEKRECORD_BEGINFILE,291,0x0C},
{0,PROGAEMODERECORD_P_ROM,PROGAEMODERECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgAEModeRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ProgAEModeRecord_Times,NULL,0,0,PROGAEMODERECORD_BEGINFILE,302,0x0C},
{0,PROGNEMODE1RECORD_P_ROM,PROGNEMODE1RECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgNEMode1Record_P,NULL,NULL,&Event_Meter_Pro_Times.ProgNEMode1Record_Times,NULL,0,0,PROGNEMODE1RECORD_BEGINFILE,313,0x0C},
{0,PROGNEMODE2RECORD_P_ROM,PROGNEMODE2RECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgNEMode2Record_P,NULL,NULL,&Event_Meter_Pro_Times.ProgNEMode2Record_Times,NULL,0,0,PROGNEMODE2RECORD_BEGINFILE,324,0x0C},
{0,PROGBILLDAYRECORD_P_ROM,PROGBILLDAYRECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgBillDayRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ProgBillDayRecord_Times,NULL,0,0,PROGBILLDAYRECORD_BEGINFILE,335,0x0C},
{0,PROGYEARSLOTRECORD_P_ROM,PROGYEARSLOTRECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgYearSlotRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ProgYearSlotRecord_Times,NULL,0,0,PROGYEARSLOTRECORD_BEGINFILE,346,0x0C},
//{0,PROGDAILYSLOTRECORD_P_ROM,PROGDAILYSLOTRECORD_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P,NULL,NULL,&Event_Meter_Pro_Times.ProgDailySlotRecord_Times,NULL,0,0,402,434,0x0C},
{LASTOPENCOVEREVENT_ROM,OPENCOVEREVENT_P_ROM,OPENCOVEREVENT_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OpenCoverEvent_Times,NULL,0x40,60,OPENCOVEREVENT_BEGINFILE,76,0x8E},
{LASTOPENBOXEVENT_ROM,OPENBOXEVENT_P_ROM,OPENBOXEVENT_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.OpenBoxEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OpenBoxEvent_Times,NULL,0x80,60,OPENBOXEVENT_BEGINFILE,357,0x8E},
//{0,ADJUSTTIMEOVERT_P_ROM,ADJUSTTIMEOVERT_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.AdjustTimeOverT_P,NULL,NULL,&Event_Meter_Pro_Times.AdjustTimeOverT_Times,NULL,0,0,ADJUSTTIMEOVERTRECORD_BEGINFILE,533,0x0C},
{0,VOLTAGEDOWN_A_P_ROM,VOLTAGEDOWN_A_TIMES_ROM,VOLTAGEDOWN_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_A_Times,&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks,0x08,0,VOLTDOWN_A_BEGINFILE,840,0x1E},
{0,VOLTAGEDOWN_B_P_ROM,VOLTAGEDOWN_B_TIMES_ROM,VOLTAGEDOWN_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_B_Times,&Event_Power_Net_Timeticks.VoltageDown_B_Times_Ticks,0x10,0,VOLTDOWN_B_BEGINFILE,851,0x1E},
{0,VOLTAGEDOWN_C_P_ROM,VOLTAGEDOWN_C_TIMES_ROM,VOLTAGEDOWN_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_C_Times,&Event_Power_Net_Timeticks.VoltageDown_C_Times_Ticks,0x20,0,VOLTDOWN_C_BEGINFILE,862,0x1E},
{0,OVERCURRENT_A_P_ROM,OVERCURRENT_A_TIMES_ROM,OVERCURRENT_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_A_Times,&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks,0x01,0,OVERCURR_A_BEGINFILE,873,0x1E},
{0,OVERCURRENT_B_P_ROM,OVERCURRENT_B_TIMES_ROM,OVERCURRENT_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_B_Times,&Event_Power_Net_Timeticks.OverCurrent_B_Times_Ticks,0x02,0,OVERCURR_B_BEGINFILE,884,0x1E},
{0,OVERCURRENT_C_P_ROM,OVERCURRENT_C_TIMES_ROM,OVERCURRENT_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_C_Times,&Event_Power_Net_Timeticks.OverCurrent_C_Times_Ticks,0x04,0,OVERCURR_C_BEGINFILE,895,0x1E},
{0,UPLOAD_A_P_ROM,UPLOAD_A_TIMES_ROM,UPLOAD_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_A_Times,&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks,0x08,0,UPLOAD_A_BEGINFILE,906,0x1E},
{0,UPLOAD_B_P_ROM,UPLOAD_B_TIMES_ROM,UPLOAD_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_B_Times,&Event_Power_Net_Timeticks.UpLoad_B_Times_Ticks,0x10,0,UPLOAD_B_BEGINFILE,917,0x1E},
{0,UPLOAD_C_P_ROM,UPLOAD_C_TIMES_ROM,UPLOAD_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_C_Times,&Event_Power_Net_Timeticks.UpLoad_C_Times_Ticks,0x20,0,UPLOAD_C_BEGINFILE,928,0x1E},
{0,CURRREVERSE_P_ROM,CURRREVERSE_TIMES_ROM,CURRREVERSE_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.CurrReverse_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.CurrReverse_Times,&Event_Power_Net_Timeticks.CurrReverse_Times_Ticks,0x01,0,CURRREVERSE_BEGINFILE,939,0x1E},
{0,OVERFACTOR_P_ROM,OVERFACTOR_TIMES_ROM,OVERFACTOR_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.OverFactor_Times,&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,0x02,0,OVERFACTOR_BEGINFILE,950,0x1E},
{0,FAILCURRENT_A_P_ROM,FAILCURRENT_A_TIMES_ROM,FAILCURRENT_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_A_Times,&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks,0x08,0,FAILCURR_A_BEGINFILE,961,0x1E},
{0,FAILCURRENT_B_P_ROM,FAILCURRENT_B_TIMES_ROM,FAILCURRENT_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_B_Times,&Event_Power_Net_Timeticks.FailCurrent_B_Times_Ticks,0x10,0,FAILCURR_B_BEGINFILE,972,0x1E},
{0,FAILCURRENT_C_P_ROM,FAILCURRENT_C_TIMES_ROM,FAILCURRENT_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_C_Times,&Event_Power_Net_Timeticks.FailCurrent_C_Times_Ticks,0x20,0,FAILCURR_C_BEGINFILE,983,0x1E},
{0,OVERPOWERCLOSESWIT_P_ROM,OVERPOWERCLOSESWIT_TIMES_ROM,0,(unsigned char *)&Event_Meter_Pro_Pointer.OverPowerCloseSwitch_P,NULL,NULL,&Event_Meter_Pro_Times.OverPowerCloseSwitch_Times,NULL,0,0,OVERPOWERSWIT_BEGINFILE,456,0x0C},
{0,OVER1RDEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over1RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],NULL,NULL,NULL,0x08,0,OVER1RDEMAND_BEGINFILE,2207,0x06},
{0,OVER2RDEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over2RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],NULL,NULL,NULL,0x10,0,OVER2RDEMAND_BEGINFILE,2239,0x06},
{0,OVER3RDEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over3RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],NULL,NULL,NULL,0x20,0,OVER3RDEMAND_BEGINFILE,2271,0x06},
{0,OVER4RDEMAND_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over4RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],NULL,NULL,NULL,0x40,0,OVER4RDEMAND_BEGINFILE,2303,0x06},
{0,OVERFACTOR_A_P_ROM,OVERFACTOR_A_TIMES_ROM,OVERFACTOR_A_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],NULL,&Event_Power_Net_Times.OverFactor_A_Times,&Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks,0x20,0,OVERFACTOR_A_BEGINFILE,2335,0x1E},
{0,OVERFACTOR_B_P_ROM,OVERFACTOR_B_TIMES_ROM,OVERFACTOR_B_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],NULL,&Event_Power_Net_Times.OverFactor_B_Times,&Event_Power_Net_Timeticks.OverFactor_B_Times_Ticks,0x40,0,OVERFACTOR_B_BEGINFILE,2367,0x1E},
{0,OVERFACTOR_C_P_ROM,OVERFACTOR_C_TIMES_ROM,OVERFACTOR_C_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],NULL,&Event_Power_Net_Times.OverFactor_C_Times,&Event_Power_Net_Timeticks.OverFactor_C_Times_Ticks,0x80,0,OVERFACTOR_C_BEGINFILE,2399,0x1E},
{0,CONSTANTMAGNET_P_ROM,CONSTANTMAGNET_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.ConstantMagnet_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],NULL,&Event_Power_Net_Times.ConstantMagnet_Times,NULL,0x40,0,CONSTANTMAGNET_BEGINFILE,2463,0x0E},
{0,POWERABNORMAL_P_ROM,POWERABNORMAL_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.PowerAbnormal_P,NULL,NULL,&Event_Power_Net_Times.PowerAbnormal_Times,NULL,0,0,POWERABNORMAL_BEGINFILE,2495,0x0C},
{0,POWERREVERSE_T_P_ROM,POWERREVERSE_T_TIMES_ROM,0,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_T_P,NULL,NULL,&Event_Power_Net_Times.PowerReverse_T_Times,NULL,0,0,POWERREVERSE_T_BEGINFILE,2431,0x0C},
{0,VOLTSTATISTIC_T_P_ROM,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_T_P,NULL,NULL,NULL,NULL,0,0,VOLTSTATISTIC_T_BEGINFILE,2527,0x04},
{0,CURRFARIMB_P_ROM,CURRFARIMB_TIMES_ROM,CURRFARIMB_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.CurrFarImB_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],NULL,&Event_Power_Net_Times.CurrFarImB_Times,&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks,0x04,0,CURRFARIMBALANCE_BEGINFILE,2559,0x1E},
//{0,BUY_EVENT_P_EE,0,0,(unsigned char *)&Pay_For_Event_Point.Buy_Event_P,0,0,0,NULL,0,0,BUY_EVENT_FILE,0,0x0C},
{0,FAR_CONTROL_EVENT_P_EE,FARCONTROLEVENT_EE,0,(unsigned char *)&Pay_For_Event_Point.Far_Control_Event_P,0,0,&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks,NULL,0,0,FAR_CONTROL_EVENT_FILE,0,0x0C},
{0,FAR_CONTROL_FREE_EVENT_P_EE,FARCONTROLEVENT_EE+4,0,(unsigned char *)&Pay_For_Event_Point.Far_Control_Free_Event_P,0,0,&Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks,NULL,0,0,FAR_CONTROL_FREE_EVENT_FILE,0,0x0C},
{0,FAR_KEY_UPDATA_EVENT_P_EE,Far_Key_Updata_Count_EE,0,(unsigned char *)&Pay_For_Event_Point.Far_Key_Updata_Event_P,0,0,&Pre_Payment_Data.Far_Key_Updata_Count,NULL,0,0,FAR_KEY_UPDATA_EVENT_FILE,0,0x0C},
{0,OPCARD_ERROR_EVENT_P_EE,OPCARD_ERROR_NUM_EE,0,(unsigned char *)&Pay_For_Event_Point.OPCard_Error_Event_P,0,0,&Pre_Payment_Data.OPCard_Error_Num,NULL,0,0,OPCARD_ERROR_EVENT_FILE,0,0x0C},
{0,REFUNDMENT_EVENT_P_EE,Back_Money_Count_EE,0,(unsigned char *)&Pay_For_Event_Point.Refundment_Event_P,0,0,&Pre_Payment_Data.Back_Money_Count,NULL,0,0,REFUNDMENT_EVENT_FILE,0,0x0C},
{RELAYERR_AREA_EE,RELAYERR_EVENT_P_EE,Relay_Error_Num_EE,0,(unsigned char *)&Pay_For_Event_Point.RelayErr_Event_P,&Pre_Payment_Para.Pay_For_Users_Flag15.intd,0,&Pre_Payment_Data.Relay_Error_Num,NULL,0x04,0,RELAYERR_EVENT_FILE,0,0x0E},
{0,PROGRAMTRIFF_EVENT_P_EE,TriffProgNum_EE,0,(unsigned char *)&Pay_For_Event_Point.ProgramTriff_Event_P,0,0,&Pre_Payment_Data.TriffProgNum,NULL,0,0,PROGRAMTRIFF_EVENT_FILE,0,0x0C},
{0,PROGRAMSTEP_EVENT_P_EE,StepProgNum_EE,0,(unsigned char *)&Pay_For_Event_Point.ProgramStep_Event_P,0,0,&Pre_Payment_Data.StepProgNum,NULL,0,0,PROGRAMSTEP_EVENT_FILE,0,0x0C},
{0,OVERPOWERALARM_P_ROM,OVERPOWERALARM_TIMES_ROM,OVERPOWERALARM_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Pointer.OverPowerAlarm_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],NULL,&Event_Power_Net_Times.OverPowerAlarm_Times,&Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,0x01,0,OVERPOWERALARM_BEGINFILE,1183,0x1E}
};

//modified by mw 2010-01-07

const unsigned long Clearevent_ID[74]={0x1000FFFF,0x1001FFFF,0x1002FFFF,0x1003FFFF,0x1201FFFF,
								     0x1202FFFF,0x1203FFFF,0x1301FFFF,0x1302FFFF,0x1303FFFF,
								     0x030500FF,0x1400FFFF,0x1600FFFF,0x1700FFFF,0x1801FFFF,
								     0x1802FFFF,0x1803FFFF,0x1B01FFFF,0x1B02FFFF,0x1B03FFFF,
								     0x031001FF,0x031002FF,0x031003FF,0x031100FF,0x031200FF,
								     0x031201FF,0x031202FF,0x033000FF,0x033002FF,0x033004FF,
								     0x033007FF,0x033009FF,0x03300AFF,0x03300BFF,0x03300CFF,
								     0x033006FF,0x03300DFF,0x03300EFF,
								     0x1101FFFF,0x1102FFFF,0x1103FFFF,0x1901FFFF,0x1902FFFF,
								     0x1903FFFF,0x1C01FFFF,0x1C02FFFF,0x1C03FFFF,0x1500FFFF,
								     0x1F00FFFF,0x1A01FFFF,0x1A02FFFF,0x1A03FFFF,0x034201FF,
								     0x031203FF,0x031204FF,0x031205FF,0x031206FF,
								     0x1F01FFFF,0x1F02FFFF,0x1F03FFFF,
								     0x033500FF,
								     0x033700FF,
								     0x210000FF,
								     0x031000FF,
								     0x2000FFFF,
								     0x1D00FFFF,0x1E00FFFF,0x033012FF,0x033013FF,
								     0x033400FF,0x033600FF,0x03300FFF,0x033010FF,
								     0x034200FF};

          
const unsigned long Voltage_table1[4]={1000000L,2200000L,577000L,3800000L};

union  BYTE_BIT VoltCheck_N[3][2];
//-------------------------  New 645 Declaration  ----------------------//
/*"================================================================="*/
/*"Function Name:事件累计时间                                                                 "*/
/*"Author:	PC    Modifier:	 mw   Date:2009-09-03                                                   "*/
/*"DESCRIPTION: reduced 626byte ,Eeprom.h  Defdata.h Comm.c                                  "*/
/*"调理了EVENT_POWER_NET_FLAG结构                                                        "*/
/*"调理了 EVENT_POWER_NET_TIMETICKS_ROM内卡位置                             "*/
/*"============================================================== =="*/
void EventTimeAdd()
{
	unsigned int i,j;
	unsigned char mask=0;
	
	 for(i=0;i<6;i++)  //note here only 4 ,not 6 mw 2009-09-03
	 {
		mask=*((unsigned char *)&Event_Power_Net_Flag.byte[i]);  
		for(j=0;j<8;j++)
		{
			if((mask & 0x01)!= 0)
			{
				(*((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+j+i*8L))++; 
				//saveflag=0xff;
			}
			mask >>= 1;
		}  
	 }
	//modified by mw 2010-06-02
	
	//if(saveflag)
	//   WRLC256(EVENT_POWER_NET_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks,sizeof(struct EVENT_POWER_NET_TIMETICKS),3,0);      
}                                                                    
                                          
//------------------------  New 645 Function  -----------------------//
//------------------------  Public Function       ------------------------//
#pragma SECTION rom UserROMData  
const unsigned long Vn[4]={1000000L,2200000L,577000L,3800000L};
//reduced 132byte by mw 2009-09-03
void New2007_Event(void){
	
	int2ic &= 0xf8;
	InitNew2007Event();
	int2ic |= 0x01;
  //------  Phase3 LostVolt  ------//
  Phase3LostVoltEvent();
  //------  VoltageReverse  ------//
  VoltReverseEvent();
  //------  CurrentReverse  ------//
  CurrReverseEvent();
  //------  Lost Voltage  ------//
  LostVoltageEvent();
  //------  Lost Current  ------//
  LostCurrentEvent();
  //------  Break Phase  -------//
  BreakPhaseEvent();
  //------  Power Reverse  ------//
  PowerReverseEvent();
  ALLPowerReverseEvent();
  //------  Voltage Statistic Event  ------//
  int2ic &= 0xf8;
  VoltStatisticEvent();
  int2ic |= 0x01;
  //------  Over Voltage Event  ------//
  OverVoltageEvent();
  //------  Over Demand Alarm Event ------//
  OverDemandAlarmEvent();
  //------  Adjust Meter Event  ------//
  int2ic &= 0xf8;
  AdjustMeterRecordEndCheck();
  int2ic |= 0x01;
  //-----   CurrImBalance VoltImBalance Event   ------//
  CurrVoltImBalance_Event();
  //------  VoltageDown Event  ------//
  VoltageDownEvent();
  //------  OverCurrent Event  ------//
  OverCurrentEvent();
  //------  UpLoad Event  ------//
  UpLoadEvent();
  //------  OverFactor Event  ------//
  OverFactorEvent();
  //------  FailCurrent Event  ------//
  FailCurrentEvent();
  
  OverDemandEvent();
  
  ConstantMagnetEventCheck();
  
  OpenCoverCheck();
  
  int2ic &= 0xf8;
  Rst90E36Event();
  int2ic |= 0x01;
	
}

void InitNew2007Event(void)
{
	unsigned char unc;
	unsigned long tempangleac;
	
	EventUn=1000000;
	EventIb=Meter_Parameter.parameter1.EventJudgeIn;
	// modified by mw  2009-10-09
	if(((V_REGION<=3))&&(I_REGION<=9))
	{
		EventUn=Vn[V_REGION];
	}
	
	eventmaxvolt=Volt[0];
	eventminvolt=Volt[0];
	eventmaxcurr=Curr[0];
	eventmincurr=Curr[0];
	for(unc=1;unc<3;unc++)
	{
		if((V_REGION==0 || V_REGION==3)&&(unc==1))
		  continue;
		
		if(eventmaxvolt<Volt[unc])
		  eventmaxvolt=Volt[unc];
		  
		if(eventminvolt>Volt[unc])
		  eventminvolt=Volt[unc];
		
		if(eventmaxcurr<Curr[unc])
		  eventmaxcurr=Curr[unc];
		  
		if(eventmincurr>Curr[unc])
		  eventmincurr=Curr[unc];
	}
	
	Meter_331_LostVoltage_B=0;
	if(V_REGION==0 || V_REGION==3)
	{
	  tempangleac=angle[1];
	  if(tempangleac>18000)
	    tempangleac=36000-tempangleac;
	  
	  if(Meter_331_LostVoltage_B==0)
	  {
	  	if((Meter_331_LostVoltage_B_break!=0)||((tempangleac>7400)&&(Volt[0] > 100000)&&(Volt[2] > 100000)))
	      Meter_331_LostVoltage_B=1;
	  }
	  else
	  {
	  	if((Meter_331_LostVoltage_B_break==0)&&(tempangleac<7400))
	  	  Meter_331_LostVoltage_B=0;
	  }
	  
	  eventavgcurr=(Curr[0]+Curr[2])/2;
	}
	else
	{
		Meter_331_LostVoltage_B=0;
		
		eventavgcurr=(Curr[0]+Curr[1]+Curr[2])/3;
	}
		
}

/*"============================================================
函数说明：计算掉电时事件数据的CRC值
输入参数：无
输出参数：无
返    回：crc_value  CRC校验和  
作    者：PC  版本：1.00    GANJP 1.01
============================================================"*/
unsigned int EventData_crc(void)
{
	unsigned char unc;
	unsigned int crc_value;
	
	for(unc=0;unc<3;unc++)
	{
	  *((unsigned long *)&Co.b[300]+unc)=Event_AmpHour[unc];
	  *((unsigned long *)&Co.b[456]+unc)=maximbalancerate[unc];
	}
	for(unc=0;unc<36;unc++)
	  *((unsigned long *)&Co.b[312]+unc)=Event0BeginAmpHour[unc];
	  
	crc_value = CRC(&Co.b[300],168);
	
	return (crc_value);
}

void EventData_PowerDown_Save(void){
	
	CrcEvent0Flag=CRC(&Event_Power_Net_Flag.byte[0],8);
	
	CrcEventTimeTicks=CRC((unsigned char *)&Event_Power_Net_Timeticks,192);  //mw added 2010-06-01
	
  CrcEventPowerDownData = EventData_crc();
  
	CrcVoltStatData=CRC((unsigned char*) &VoltStat[0],192);
	
}

unsigned char EventData_PowerOn_Check(void){
	unsigned char res=0;
	unsigned char unc=0;
	unsigned int tempuni,tempcrc;  //mw added 2010-06-01
	
	FeedWatchdog();
	CheckPowerDown();
	EventDataValid_Flag=0;
	EventEnergyValid_Flag=0;
	
	EventTimeTicksValid_Flag=0;  //mw added 2010-06-01
	tempcrc=0;
	tempcrc=CRC((unsigned char*)&Event_Power_Net_Timeticks,192);
	if(tempcrc==CrcEventTimeTicks)
	{
		EventTimeTicksValid_Flag=0xFF; /*"RMA累计时间有效"*/
	}
	else
	{
	  	EventTimeTicksValid_Flag=0;  /*"RMA累计时间无效，读内卡"*/
		ReadBlock(EVENT_POWER_NET_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks,
			sizeof(struct EVENT_POWER_NET_TIMETICKS),0);
		FeedWatchdog();
		
	}

	
	tempuni=CRC(&Event_Power_Net_Flag.byte[0],8);
	if(tempuni==CrcEvent0Flag){
		EventDataValid_Flag=0xFF;
	}
	else{
	   res=0;
     
     if((gPD_Data_valid_flag.byte & 0x09) == 0x09)
     	{
     		unc = ReadBlock(POWERDOWN_SAVE_DATA_ROM, &Co.b[300], sizeof(struct POWERDOWN_SAVE_DATA),0);
     		if(unc)
     			{
     				tempuni=sizeof(struct ENERGY_POWERDOWN)+sizeof(struct DATEANDTIME_DEF)+1;
     	      for(unc=0;unc<8;unc++)
     	        Event_Power_Net_Flag.byte[unc]=Co.b[300+tempuni+unc];
     	      CrcEvent0Flag=CRC(&Event_Power_Net_Flag.byte[0],8);
     	      res=0xFF;
     			} 
     			
     			    	  
     	}
     
     if(res==0){
     	 for(unc=0;unc<8;unc++)
	      Event_Power_Net_Flag.byte[unc]=0;
	     CrcEvent0Flag=0xFF;
     }
  }
  
	tempuni=EventData_crc();
	
	if(tempuni!=CrcEventPowerDownData){
		for(unc=0;unc<3;unc++)
		{
	    Event_AmpHour[unc]=0xFFFFFFFF;
	    maximbalancerate[unc]=0xFFFFFFFF;
	  }
	  for(unc=0;unc<36;unc++)
	    Event0BeginAmpHour[unc]=0xFFFFFFFF;
	  
    CrcEventPowerDownData = EventData_crc();
	}
  
	return 0;
}

unsigned char EventRecord_Poweron_Check(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int uni;
	union EVENTPOWERONDEALFLAG eventdealflag;
	unsigned char calamphourkind;
	unsigned char calamphouraddrkind;
	unsigned int eventdatakind;
	unsigned int eventdataaddr;
	unsigned char eventdataaddradjust;
	unsigned char eventdatalength;
	unsigned char eventdatafileadjust;
	unsigned char eventtimetickskind;
	unsigned int eventtimeticksaddr;
	unsigned long *eventtimetickspointer;
	unsigned int tempeventaddr0;  //lost voltage energy //max demand of over demand //max imbalance rate
	unsigned int tempeventaddr1;  //lost voltage end time
	
	FeedWatchdog();
	CheckPowerDown();
	
	if(IsNormalReset(0))
	{
		for(unc=0;unc<6;unc++)
		  Co.b[600+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		
		if((CheckTime(&Co.b[600])!=0xff))
	  {
	    for(unc=0;unc<6;unc++)
		    Co.b[600+unc]=0xff;
		  
	  }
		
		PdOpenCoverCheckPowerUpDeal();
        
		Event_Report_Status_Chk(0);
                      
		for(unc=0;unc<8;unc++)
		{
			for(und=0;und<8;und++)
			{
				if(((Event_Power_Net_Flag.byte[unc])&(0x01<<und))!=0)
				{
					eventdealflag.intd=0;
					uni=unc;
					uni=((uni<<8)|und);
					switch(uni)
					{
						case 0x0000:
						case 0x0001:
						case 0x0002:  //A B C lost voltage
						  eventdealflag.bit.b0=1;
						  calamphourkind=und;
	            calamphouraddrkind=0;
	            eventdealflag.bit.b1=1;
	            eventdatakind=0x004E;
	            eventdataaddr=LASTLOSTVOLT_A_ROM+((unsigned int)255)*und;
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdatafileadjust=0;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0;
	            eventtimeticksaddr=LOSTVOLT_A_TIMETICKS_ROM+((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
	            eventdealflag.bit.b4=1;
	            tempeventaddr0=LOSTVOLTENERGY_A_ROM+((unsigned int)8)*und;
	            eventdealflag.bit.b5=1;
	            tempeventaddr1=LASTLOSTVOLTBEGINTIME_A_ROM+((unsigned int)12)*und+6;
						break;
						
						case 0x0003:  //voltage reverse
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=VOLTREVERSE_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.VoltageReserve_P;
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=VOLTAGERESERVE_TIMETICKS_ROM;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0005:
						case 0x0006:
						case 0x0007:  //A B C lost current
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=LOSTCURR_A_BEGINFILE+((unsigned int)32)*(und-5);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.LostCurrent_A_P+(und-5));
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=LOSTCURRENT_A_TIMETICKS_ROM+((unsigned int)4)*(und-5);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks)+(und-5);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0100:
						case 0x0101:
						case 0x0102:  //A B C break phase
	            eventdealflag.bit.b0=1;
						  calamphourkind=9+und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=BREAKPHASE_A_BEGINFILE+((unsigned int)32)*(und);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.BreakPhase_A_P+und);
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=BREAKPHASE_A_TIMETICKS_ROM+((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0103:
						case 0x0104:
						case 0x0105:  //A B C voltage down
						  eventdealflag.bit.b0=1;
						  calamphourkind=und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=VOLTDOWN_A_BEGINFILE+((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.VoltageDown_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=VOLTAGEDOWN_A_TIMETICKS_ROM+((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0106:
						case 0x0107:  //over demand of active
						  eventdealflag.bit.b7=1;
						  tempeventaddr0=OVERDEMANDMAXDEMAND_ROM+((unsigned int)(und-6))*sizeof(struct DEMAND_DATA_FORM);
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0102;
	            eventdataaddr=OVERPAADEMAND_BEGINFILE+((unsigned int)32)*(und-6);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverPaADemand_P+(und-6));
	            eventdataaddradjust=6;
	            eventdatalength=15;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0200:
						case 0x0201:
						case 0x0202:  //A B C power reverse
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=POWERREVERSE_A_BEGINFILE+((unsigned int)32)*und;
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.PowerReverse_A_P+und);
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=POWERREVERSE_A_TIMETICKS_ROM+((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.PowerReverse_A_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0203:
						case 0x0204:
						case 0x0205:  //A B C over voltage
						  eventdealflag.bit.b0=1;
						  calamphourkind=3+und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=OVERVOLT_A_BEGINFILE+((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverVoltage_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=OVERVOLT_A_TIMETICKS_ROM+((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0206:
						case 0x0207:  //curr volt imbalance
						  eventdealflag.bit.b8=1;
						  tempeventaddr0=und-6;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x001E;
	            eventdataaddr=CURRIMBALANCEEVENT_BEGINFILE+((unsigned int)32)*(und-6);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.CurrImBalanceEvent_P+(und-6));
	            eventdataaddradjust=102;
	            eventdatalength=106;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=CURRIMBEVENT_TIMETICKS_ROM+((unsigned int)4)*(und-6);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks)+(und-6);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0300:
						case 0x0301:
						case 0x0302:  //A B C over current
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=OVERCURR_A_BEGINFILE+((unsigned int)32)*und;
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverCurrent_A_P+und);
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=OVERCURRENT_A_TIMETICKS_ROM+((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0303:
						case 0x0304:
						case 0x0305:  //A B C up load
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=UPLOAD_A_BEGINFILE+((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.UpLoad_A_P+(und-3));
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=UPLOAD_A_TIMETICKS_ROM+((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0400:  //over power alarm
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0002;
	            eventdataaddr=OVERPOWERALARM_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.OverPowerAlarm_P;
	            eventdataaddradjust=14;
	            eventdatalength=6;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=OVERPOWERALARM_TIMETICKS_ROM;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
		#if 0 ///			
						case 0x0401:
						case 0x0402:  //clock display battery
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0002;
	            eventdataaddr=CLOCKBATTERYEVENT_BEGINFILE+((unsigned int)32)*(und-1);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.ClockBatteryEvent_P+(und-1));
	            eventdataaddradjust=6;
	            eventdatalength=6;
	            eventdealflag.bit.b3=1;
						break;
		#endif			
						case 0x0405:
						case 0x0406:
						case 0x0407:  //A B C over factor
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=OVERFACTOR_A_BEGINFILE+((unsigned int)32)*(und-5);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverFactor_A_P+(und-5));
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=OVERFACTOR_A_TIMETICKS_ROM+((unsigned int)4)*(und-5);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks)+(und-5);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0500:  //curr reverse
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=CURRREVERSE_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.CurrReverse_P;
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=CURRREVERSE_TIMETICKS_ROM;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.CurrReverse_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0501:  //T over factor
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=OVERFACTOR_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.OverFactor_P;
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=OVERFACTOR_TIMETICKS_ROM;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.OverFactor_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0502:  //curr far imbalance
						  eventdealflag.bit.b8=1;
						  tempeventaddr0=2;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x001E;
	            eventdataaddr=CURRFARIMBALANCE_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.CurrFarImB_P;
	            eventdataaddradjust=102;
	            eventdatalength=106;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=CURRFARIMB_TIMETICKS_ROM;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0503:
						case 0x0504:
						case 0x0505:  //A B C fail current
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=FAILCURR_A_BEGINFILE+((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.FailCurrent_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=FAILCURRENT_A_TIMETICKS_ROM+((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
			
						case 0x0606:  //constant magnet
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=CONSTANTMAGNET_BEGINFILE;
	            eventdatafileadjust=Event_Power_Net_Pointer.ConstantMagnet_P;
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b3=1;
						break;
			
						case 0x0703:
						case 0x0704:
						case 0x0705:
						case 0x0706:  //over demand of reactive
						  eventdealflag.bit.b7=1;
						  tempeventaddr0=OVERDEMANDMAXDEMAND_ROM+((unsigned int)(und-1))*sizeof(struct DEMAND_DATA_FORM);
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0102;
	            eventdataaddr=OVER1RDEMAND_BEGINFILE+((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverPaADemand_P+(und-1));
	            eventdataaddradjust=6;
	            eventdatalength=15;
	            eventdealflag.bit.b3=1;
						break;
						
						default:
						break;
					}
					if(eventdealflag.intd!=0)
					{
						FeedWatchdog();
						CheckPowerDown();
						if(eventdealflag.bit.b0!=0)
						{
							if((calamphouraddrkind==0)||((calamphouraddrkind==1)&&(eventdatafileadjust<32)))
							{
							  if(EventDataValid_Flag==0xFF)
		  	        {
		  		         SaveEvent0EndAmpHour(calamphourkind);
		  	        }
		            else
		  	        {
		  		         Cal_AmpHour_poweron(eventdataaddr+eventdatafileadjust,calamphouraddrkind);
		  	        }
		  	      }
						}
						
						if(eventdealflag.bit.b7!=0)
						{
							WRLC256(tempeventaddr0,&Co.b[626],sizeof(struct DEMAND_DATA_FORM),0,1);
						}
						
						if(eventdealflag.bit.b8!=0)
						{
							if(maximbalancerate[tempeventaddr0]==0xffffffff)
                WRLC256(MAXCURRIMBALANCERATE_ROM+tempeventaddr0*4,(unsigned char *)&Co.b[606],4,0,1);
              else
                *((unsigned long *)&Co.b[606])=maximbalancerate[tempeventaddr0];
						}
						
						if(eventdealflag.bit.b1!=0)
						{
							PrepEvent0Data(eventdatakind);
		          WRLC256(eventdataaddr+eventdataaddradjust,&Co.b[300],eventdatalength,0,0);
						}
						
						if(eventdealflag.bit.b6!=0)
						{
							PrepEvent0Data(eventdatakind);
							
							if(eventdatafileadjust<32)
		            Write_File_PdEvent(eventdataaddr+eventdatafileadjust,eventdataaddradjust,eventdatalength,&Co.b[300]);
						}
						
						if(eventdealflag.bit.b2!=0)
						{
							if((eventtimetickskind==0)||((eventtimetickskind==0xff)&&(eventdatafileadjust<32)))
							{
							   SaveEvent0LastTime(eventdataaddr+eventdatafileadjust,eventtimetickskind,&Co.b[600],eventtimeticksaddr,
			                              eventtimetickspointer);
			        }
						}
						
						if(eventdealflag.bit.b3!=0)
						{
							ClearEvent0Flag(unc,(~(0x01<<und)));
						}
						
						if(eventdealflag.bit.b4!=0)
						{
							LostVoltEnergyAdd(tempeventaddr0,0xff);
						}
						
						if(eventdealflag.bit.b5!=0)
						{
							WRLC256(tempeventaddr1,&Co.b[600],6,0,0);
						}
						
					}
				}
			}
		}		
	} 
  
  for(unc=0;unc<=2;unc++){
	  Event_AmpHour[unc]=0;
	}
	
	CheckPowerDown();
	FeedWatchdog();
	return 0xFF;
} 
//------------------------  Public Function       ------------------------//


//------------------------  LostVoltage Function  ------------------------//
/*"=============================================================="*/
/*"Function Name:失压事件记录                                                            "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03      reduced 270byte           "*/
/*"DESCRIPTION: 将A\C相失压整成一块，  In order to reduce the code "*/
/*"B相条件复杂所以单独拿出来                                                "*/
/*"offset3为失压标志在相应结构中的偏移位置                   "*/
/*"=============================================================="*/
//------------------------  LostVoltage Function  ------------------------//
void LostVoltageEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned char lowvoltflag;
	unsigned int uni;
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
  //------  LostVoltage A B C  ------//
  for(und=0;und<3;und++)   
  {
	   if((V_REGION==0 || V_REGION==3)&&(und==1))		
		   continue;
	   
	   int2ic &= 0xf8;
	   
	   lowvoltflag=EventCriticalVoltage_Flag;
	   if(Meter_Parameter.parameter1.MeterMode[3].bit.b7==1)
	     lowvoltflag=Event_Power_Net_Flag.bit.PowerDownEvent;
	   
  	if((Event_Power_Net_Flag.byte[0]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeLostVoltSV!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeLostVoltSV*1000l) 
	      &&(Curr[und]>Meter_Parameter.event_parameter.JudgeLossVoltage)&&(lowvoltflag==0))
	    {
		    (*((unsigned char*)&Event_N.LostVoltage_A_P+und))++;
		    if((*((unsigned char*)&Event_N.LostVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
		    {
				  (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;
				  
				  CheckPowerDown();
				  MoveEventData2Flash(LASTLOSTVOLT_A_ROM+255L*und,(LOSTVOLT_A_BEGINFILE+und*32L),((unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P+und),255);
				  
				  PrepEvent0Data(0x002D);
		      
				  Save_Event_StartData_Eeprom((&Event_Power_Net_Pointer.LostVoltage_A_P+und),(LOSTVOLTAGE_A_P_ROM+und),
                                      (LASTLOSTVOLT_A_ROM+255L*und),141,
                                      ((unsigned long *)&Event_Power_Net_Times.LostVoltage_A_Times+und),(LOSTVOLTAGE_A_TIMES_ROM+und*4L));
				  
				  SaveEvent0BeginAmpHour(und);
				  SaveLostVoltTime(LASTLOSTVOLTBEGINTIME_A_ROM+und*12L,0xFF);
				  SaveLostVoltTime(LASTLOSTVOLTENDTIME_A_ROM+und*12L,0);
				  lostvoltagetime[und][0]=This_Month_Data.Energy_Record.EnergyPassMAXTimes[0];
			    lostvoltagetime[und][1]=This_Month_Data.Energy_Record.EnergyPassMAXTimes[1];
			    WRLC256( LOSTVOLTAGETIME+2L*und,(unsigned char*)&lostvoltagetime[und][0],2,0,0);
			    
				  Event_Power_Net_Flag.byte[0]|=offset[und];  //==1
				  if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x01) 
				  Save_EventReportTimes((LOSTVOLT_A_TIMES_ROM+und*16),((unsigned char *)&Event_Report_Status_Times.LostVolt_A_times+und*16));			  
		     }
	     }
	     else
	     {
		     (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;	
	     }
	  }
	  else
	  { 		
	   if((Meter_Parameter.event_parameter.JudgeLostVoltSV==0)||(Volt[und]>Meter_Parameter.event_parameter.JudgeLostVoltEV*1000l)
	     ||(lowvoltflag!=0))
	   {	
		   (*((unsigned char*)&Event_N.LostVoltage_A_P+und))++;
			 if((Meter_Parameter.event_parameter.JudgeLostVoltSV==0)
			   ||((*((unsigned char*)&Event_N.LostVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
			   ||(lowvoltflag!=0))	
		   {
		   	 (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;
			   SaveEvent0EndAmpHour(und);
		     PrepEvent0Data(0x004D);
		     WRLC256(LASTLOSTVOLT_A_ROM+255L*und+141L,&Co.b[300],114,0,0);
		     		  
		     SaveEvent0LastTime_Other(LOSTVOLT_A_TIMETICKS_ROM+4L*und,
			   ((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+und));	
		     LostVoltEnergyAdd(LOSTVOLTENERGY_A_ROM+und*8L,0xff);
		     SaveLostVoltTime(LASTLOSTVOLTENDTIME_A_ROM+und*12L,0xFF);
		     
		     Event_Power_Net_Flag.byte[0]&=(~offset[und]);
		   }
	    }
	    else
	    {  
		   (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;		   
	    }
	   }
	   int2ic |= 0x01;
	   FeedWatchdog();
  }
  
}
//------------------------  LostVoltage Function  ------------------------//

//------------------------  Power Down Function   ------------------------//
void PowerDownEvent_OnCheck(void)
{
	unsigned char unc;
	unsigned char result0;
	unsigned char result1;
	unsigned int uni;
	unsigned long tempunl;
	double long temptimedt;
	
	FeedWatchdog();
	
	if((Event_Power_Net_Flag.bit.Phase3LostVolt==0)&&(Event_Power_Net_Flag.bit.PowerDownEvent==0))
	{
		CheckPowerDown();
		
		result0=0;
		
		for(unc=0;unc<6;unc++)
		  Co.b[400+unc]=*(&Powerdown_Save_Data.date.Year+unc);
	  
	  if((CheckTime(&Co.b[400])!=0xff))/*"掉电时间丢失"*/
	  {
	     result0=1;
	     for(unc=0;unc<6;unc++)
		     Co.b[400+unc]=0xff;
	  }
	  else if(rtc_lossdata_flag==0x5a)/*"时钟芯片数据丢失"*/
	  {
	  	result0=1;
	  }
	  else
	  {
	  	temptimedt=ComTime((unsigned char *)&softdate,&Co.b[400]);
	  	if(temptimedt>=60)
	  	  result0=1;
	  }
		
		if(result0==1)
		{
			result1=1;
			
			if(Check_PD_Curr_Vality()==1)
			{
				if(PD_curr.Pd_Max_curr*20l>Meter_Parameter.parameter1.EventJudgeIn)
				  result1=2;
			}
			
			CheckPowerDown();
	    if(result1==2)
	    {
	    	MoveEventData2Flash(LASTPHASE3LOSTVOLT_ROM,PHASE3LOSTVOLT_BEGINFILE,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,16);
	    	
	    	*((unsigned long *)&Co.b[306])=PD_curr.Aver_curr;
		    for(unc=0;unc<6;unc++)
		    {
	        Co.b[300+unc]=Co.b[400+unc];
	        Co.b[310+unc]=0;
	      }
		    
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.Phase3LostVolt_P,PHASE3LOSTVOLT_P_ROM,
                                    LASTPHASE3LOSTVOLT_ROM,16,
                                    &Event_Power_Net_Times.Phase3LostVolt_Times,PHASE3LOSTVOLT_TIMES_ROM);
			  
			  Event_Power_Net_Flag.bit.Phase3LostVolt=1;
        if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x04)
        Save_EventReportTimes(ALLLOSTVOLTAGE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.AllLostVoltage_times);
	    }
	    else
	    {
  	    MoveEventData2Flash(LASTPOWERDOWNEVENT_ROM,POWERDOWNEVENT_BEGINFILE,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,12);
  	    
  	    for(unc=0;unc<6;unc++)
		    {
	        Co.b[300+unc]=Co.b[400+unc];
	        Co.b[306+unc]=0;
	      }
  	    
  	    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.PowerDown_P,POWERDOWN_P_ROM,
                                    LASTPOWERDOWNEVENT_ROM,12,
                                    &Event_Power_Net_Times.PowerDown_Times,POWERDOWN_TIMES_ROM);
	      
	      Event_Power_Net_Flag.bit.PowerDownEvent=1;
          if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x20)
        Save_EventReportTimes(POWERDOWN_EVENT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.PowerDown_event_times);
	    }
	    CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
		
	  }
	}
	
	if(Event_Power_Net_Flag.bit.Phase3LostVolt==1)
	{
	  CheckPowerDown();
	  unc=ReadBlock(PHASE3LOSTVOLT_TIMETICKS_ROM,(unsigned char *)&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,4,0);
    
    if(unc)
    {
	  	WRLC256(LASTPHASE3LOSTVOLT_ROM,&Co.b[300],6,0,1);
	  	
	  	for(unc=0;unc<6;unc++)
	        Co.b[410+unc]=*((unsigned char *)&softdate+unc);
		  
		  tempunl=Cal_LastTime(&Co.b[300], &Co.b[410]);
		  tempunl=tempunl/60;
		  Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks=Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks+tempunl;	
		}
	}
	
	for(unc=0;unc<sizeof(struct	PD_CURRENT_STRUCT);unc++)
		 *((unsigned char *)&PD_curr+unc)=0;
	FeedWatchdog();
	
}

//------------------------  Power Down Function   ------------------------//

//------------------------  Programme Function    ------------------------//
unsigned int ProgrammeEvent(unsigned long progman,unsigned long progdata)
{
	unsigned char unc;
	unsigned int uni;
	
	FeedWatchdog();
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==0)
	{
		MoveEventData2Flash(LASTPROGRAMME_ROM,PROGRAMMEEVENT_BEGINFILE,(unsigned char *)&Event_Power_Net_Pointer.ProgrammeEvent_P,50);
		
		for(unc=0;unc<6;unc++)
	    Co.b[300+unc]=*((unsigned char *)&softdate+unc);
	  (*((unsigned long *)&Co.b[306]))=progman;
	  (*((unsigned long *)&Co.b[310]))=progdata;
	  for(unc=0;unc<=8;unc++)
	    (*((unsigned long *)&Co.b[314]+unc))=0xffffffff;
	  
	  Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.ProgrammeEvent_P,PROGRAMMEEVENT_P_ROM,
                                 LASTPROGRAMME_ROM,50,
                                 &Event_Power_Net_Times.ProgrammeEvent_Times,PROGRAMMEEVENT_TIMES_ROM);
	  
	  Event_Power_Net_Flag.bit.ProgrammeEvent=1; 
       if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x01)
       Save_EventReportTimes(PROGRAM_EVENT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Program_event_times);
     /*fxf add 090507*/
	  Other_Data.ProgramDate=softdate; 
    WRLC256(PROGRAMDATE_ROM,(unsigned char *)&Other_Data.ProgramDate,sizeof(struct DATEANDTIME_DEF),0,0);   
	}
	else
	{
		WRLC256(LASTPROGRAMME_ROM+10,&Co.b[304],40,0,1);
		(*((unsigned long *)&Co.b[300]))=progdata;
		WRLC256(LASTPROGRAMME_ROM+10,&Co.b[300],40,0,0);	
	}
	FeedWatchdog();
	return 0xFFFF;
}

void ProgrammeEventEnd_Check(void){
	
	int2ic &= 0xf8;
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==1){
	  if((!O1ther_Meter_Parameter.WorkRoomState)&&(!Far_Identity_Auth_Ok_Flag)){
		  Event_Power_Net_Flag.bit.ProgrammeEvent=0;
	  }
  }
	int2ic |= 0x01;
}
void ProgrammeEventEnd_Check_Payment(void){
	
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==1)
	{
		 Event_Power_Net_Flag.bit.ProgrammeEvent=0;
  }
	
}

void EventFlagPowerOnInit(void)
{
	unsigned char unc;
	unsigned char clearflagvalue[8]={0x10,0,0,0xc0,0x16,0x40,0x00,0};
	
  for(unc=0;unc<8;unc++)
    Event_Power_Net_Flag.byte[unc]=(Event_Power_Net_Flag.byte[unc]&clearflagvalue[unc]);
  
  for(unc=0;unc<sizeof(struct PDVOLT_STRUCTURE);unc++)
	   *((unsigned char *)&pdvoltdata+unc)=0;
	
	for(unc=0;unc<sizeof(struct	PDOPENCOVER_STRUCTURE)*2;unc++)
		 *(((unsigned char *)&pdopencovercheckdata[0])+unc)=0;
	
	for(unc=0;unc<sizeof(struct	PD_CURRENT_STRUCT);unc++)
		 *((unsigned char *)&PD_curr+unc)=0;
  
  Alarm_Map_Flag[0].bit.b2=Event_Power_Net_Flag.bit.ClockBatteryEvent;
  ///Meter_States.Meter_Flag.bit.Battery1_Err=Event_Power_Net_Flag.bit.ClockBatteryEvent;
  Alarm_Map_Flag[0].bit.b0=Event_Power_Net_Flag.bit.DisplayBatteryEvent;
  ///Meter_States.Meter_Flag.bit.Battery3_Err=Event_Power_Net_Flag.bit.DisplayBatteryEvent;
  
  FeedWatchdog();
	
}
//------------------------  Programme Function    ------------------------//
//-------------------------  Clear Meter Function  ---------------------//
unsigned int ClearMeterRecord(unsigned long progman)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	//------  energy  ------//
	Copy_ENERGY_TO_CO(410);
	   
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearMeterRecord_P,CLEARMETERRECORD_P_ROM,
                         CLEARMETEREVENT_BEGINFILE,106,
                         &Event_Meter_Pro_Times.ClearMeterRecord_Times,CLEARMETERRECORD_TIMES_ROM);
  
	return 0xFFFF;
}
//-------------------------  Clear Meter Function  ---------------------//

//-------------------------  Voltage Statistic Function  ------------------//
/*"reduced 400 byte, mw modified 2009-09-03"*/
/*add struct VoltStatisticStruct by zlp for modify VoltStatisticEvent*/
	
void VoltStatisticEvent(void){
	unsigned char unc;
	unsigned char und;
	unsigned long tempminvolt;
	unsigned long tempmaxvolt;
	unsigned long voltstatlimitv[4];
	unsigned char eventflagm[3]={6,6,7};
	unsigned char eventflagn[3][3]={{0x01,0x02,0x04},{0x08,0x10,0x20},{0x01,0x02,0x04}};
	
	voltstatlimitv[0]=Meter_Parameter.event_parameter.VoltageCheck_DownSet*1000l;
	voltstatlimitv[1]=Meter_Parameter.event_parameter.VoltageHealth_DownSet*1000l;
	voltstatlimitv[2]=Meter_Parameter.event_parameter.VoltageHealth_UpSet*1000l;
	voltstatlimitv[3]=Meter_Parameter.event_parameter.VoltageCheck_UpSet*1000l;
	
	for(und=0;und<3;und++)
	{
		if((V_REGION==0 || V_REGION==3)&&(und==1))
	  {			
		  continue;
	  }
		
		if((Volt[und]>voltstatlimitv[2]) && (Volt[und]<voltstatlimitv[3]))
	  {
	        VoltCheck_N[und][0].byte=0x61;
	  }
	  else if((Volt[und]>=voltstatlimitv[1]) && (Volt[und]<=voltstatlimitv[2]))
	  {
	        VoltCheck_N[und][0].byte=0x52;
	  }
	  else if((Volt[und]>voltstatlimitv[0]) && (Volt[und]<voltstatlimitv[1]))
	  {
	        VoltCheck_N[und][0].byte=0x34;
	  }
	  else 
	  {
	        VoltCheck_N[und][0].byte=0x70;
	  }
	  
	  if((!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][1]))) 
	  && (!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][0]))) 
	  &&(!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][2]))))
	  {
	     if(VoltCheck_N[und][0].byte&0x07)
	     {
		      if((!(Event_B.byte[eventflagm[und]])&(eventflagn[und][1]))
		      ||((VoltCheck_N[und][0].byte&0x07)!=(VoltCheck_N[und][1].byte&0x07)))
		      {
		        *(&Event_N.VoltStatistic_A_P+und)=0;
		        VoltCheck_N[und][1]=VoltCheck_N[und][0];
		      }
		      Event_B.byte[eventflagm[und]]|=eventflagn[und][1];   
		      Event_S.byte[eventflagm[und]]&=(~eventflagn[und][1]);
		      (*(&Event_N.VoltStatistic_A_P+und))+=1;  
		      if((*(&Event_N.VoltStatistic_A_P+und))>30)
		      {
		        if(VoltCheck_N[und][0].bit.b0) 
		        {   
		          Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][1];
		        }
		        else if(VoltCheck_N[und][0].bit.b1) 
		        {   
		          Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][0]; 
		        }
		        else if(VoltCheck_N[und][0].bit.b2) 
		        {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][2];
		        }
		      }
	     }
	     else
	     {
		      Event_B.byte[eventflagm[und]]&=(~eventflagn[und][1]);   
	     }
	  }
	  else
	  {
	     if(VoltCheck_N[und][0].byte&0x70)
	     {
		     if((!(Event_S.byte[eventflagm[und]]&eventflagn[und][1])) 
		     || ((VoltCheck_N[und][0].byte&0x70)!=(VoltCheck_N[und][1].byte&0x70)))
		     {
		       *(&Event_N.VoltStatistic_A_P+und)=0;
		       VoltCheck_N[und][1]=VoltCheck_N[und][0];
		     }
		     Event_S.byte[eventflagm[und]]|=eventflagn[und][1];  
		     Event_B.byte[eventflagm[und]]&=(~eventflagn[und][1]);
		     if((*(&Event_N.VoltStatistic_A_P+und))<50)
		       (*(&Event_N.VoltStatistic_A_P+und))+=1;     
		     if((*(&Event_N.VoltStatistic_A_P+und))>30)
		     {
		      if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][1])!=0) 
		      && (VoltCheck_N[und][0].bit.b4)) 
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][1]);     
		      }
		      else if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][0])!=0) 
		      &&(VoltCheck_N[und][0].bit.b5))  
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][0]);     
		      }
		      else if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][2])!=0) 
		      && (VoltCheck_N[und][0].bit.b6)) 
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][2]);     
		      }
		     }
	     }
	     else
	     {
		     Event_S.byte[eventflagm[und]]&=(~eventflagn[und][1]);
	     }
	  }
	  
	}
	//------  A /B/C Phase Max Min Volt  ------//
	//modified by mw 2009-09-03
	for(und=0;und<4;und++)   
	{
		if(((V_REGION==0) || (V_REGION==3))&&(und==1))
		  continue;
		
		if(und<3)
		{
			tempminvolt=Volt[und];
			tempmaxvolt=Volt[und];
		}
		else
		{
			tempminvolt=eventminvolt;
			tempmaxvolt=eventmaxvolt;
		}
		
		if((tempmaxvolt<voltstatlimitv[3])&&(tempminvolt>voltstatlimitv[0])){
			
			if(VoltStat[und].checkvolt[0]==0xFFFFFFFF){
				VoltStat[und].checkvolt[0]=tempminvolt;
				for(unc=0;unc<6;unc++)
	        VoltStat[und].checkvolttime[0][unc]=*((unsigned char *)&softdate+unc);
			}
			else{
				if(VoltStat[und].checkvolt[0]>tempminvolt){
					VoltStat[und].checkvolt[0]=tempminvolt;
				  for(unc=0;unc<6;unc++)
	          VoltStat[und].checkvolttime[0][unc]=*((unsigned char *)&softdate+unc);
				}
			}
			
			if(VoltStat[und].checkvolt[1]==0xFFFFFFFF){
				VoltStat[und].checkvolt[1]=tempmaxvolt;
				for(unc=0;unc<6;unc++)
	        VoltStat[und].checkvolttime[1][unc]=*((unsigned char *)&softdate+unc);
			}
			else{
				if(VoltStat[und].checkvolt[1]<tempmaxvolt){
					VoltStat[und].checkvolt[1]=tempmaxvolt;
				  for(unc=0;unc<6;unc++)
	          VoltStat[und].checkvolttime[1][unc]=*((unsigned char *)&softdate+unc);
				}
			}
		}
	}
	
	FeedWatchdog();
	
}

void VoltStatisticBill(void)
{
	unsigned char unc;
	unsigned int tempfilename[4]={VOLTSTATISTIC_A_BEGINFILE,VOLTSTATISTIC_B_BEGINFILE,
	                              VOLTSTATISTIC_C_BEGINFILE,VOLTSTATISTIC_T_BEGINFILE};
	
	PrepVoltStatReadData();
	
	for(unc=0;unc<4;unc++)
	{
		Save_SignalPhase_Statistic((&Event_Power_Net_Pointer.VoltStatistic_A_P+unc),
											         (unsigned char*) &VoltStat[unc],
											          tempfilename[unc]);
		*((unsigned long *)&Event_Power_Net_Times.VoltStatistic_A_Times + unc) += 1;
		WRLC256(VOLTSTATISTIC_A_P_ROM+unc,(&Event_Power_Net_Pointer.VoltStatistic_A_P+unc),1,0,0);	
		WRLC256(VOLTSTATISTIC_A_TIMES_ROM + 4 * unc,
			        ((unsigned char *)&Event_Power_Net_Times.VoltStatistic_A_Times+ 4 * unc), 4, 0, 0);	
		WRLC256(VOLTSTATISTICDATA_A_ROM+unc*sizeof(struct VoltStatistic_Data),
		       (unsigned char *)&VoltStat[unc],sizeof(struct VoltStatistic_Data),0,0);
		
		FeedWatchdog();
	}
	
}

//reduced 400byte, mw added 2009-09-03
void VoltStatisticFunc(void)
{
	unsigned char unc;
	unsigned int uni;
	
	int2ic &= 0xf8;
	FeedWatchdog();
	
	VoltStatTimeCounter=(VoltStatTimeCounter+1)%60;
	
	if((0x01==softdate.Day)&&(0x00==softdate.Hour)&&(0x00==softdate.Min))
	{
		VoltStatisticBill();
	}
	else
	{
		//------  A Phase  ------//
		VoltStat[0].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)
			VoltStat[0].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)
			VoltStat[0].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)
			VoltStat[0].checktime[3]++;
		//------  B Phase  ------//
		VoltStat[1].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_B==1)
			VoltStat[1].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_B==1)
			VoltStat[1].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_B==1)
			VoltStat[1].checktime[3]++;
		//------ C Phase  ------//
		VoltStat[2].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1)
			VoltStat[2].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1)
			VoltStat[2].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1)
			VoltStat[2].checktime[3]++;
		//------ T Phase  ------//
		if((V_REGION==1) || (V_REGION==2))
	  {
		  if(((Event_Power_Net_Flag.byte[6]&0x07)!=0)&&((Event_Power_Net_Flag.byte[6]&0x38)!=0)
		  &&((Event_Power_Net_Flag.byte[7]&0x07)!=0))
		  {
		    VoltStat[3].checktime[0]++;
		  
		    if((Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)&&(Event_Power_Net_Flag.bit.OkVoltageCheck_B==1)
		    &&(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1))
			    VoltStat[3].checktime[1]++;
			  
		    if((Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.UpVoltageCheck_B==1)
		    ||(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1))
			    VoltStat[3].checktime[2]++;
			  
		    if((Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.DownVoltageCheck_B==1)
		    ||(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1))
			    VoltStat[3].checktime[3]++;
		  }
	  }
	  else
	  {
	  	if(((Event_Power_Net_Flag.byte[6]&0x07)!=0)&&((Event_Power_Net_Flag.byte[7]&0x07)!=0))
		  {
		    VoltStat[3].checktime[0]++;
		  
		    if((Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)&&(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1))
			    VoltStat[3].checktime[1]++;
			  
		    if((Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1))
			    VoltStat[3].checktime[2]++;
			  
		    if((Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1))
			    VoltStat[3].checktime[3]++;
		  }
	  }
		
		if(VoltStatTimeCounter==0)
		  WRLC256(VOLTSTATISTICDATA_A_ROM,(unsigned char *)&VoltStat[0],192,0,0);
	}
	FeedWatchdog();
	int2ic |= 0x01;
	
}

//reduced 196byte ,mw modified 2009-09-03
void VoltStatSetDefault(void)
{
	unsigned char unc;
	
	FeedWatchdog();
	
	for(unc=0;unc<4;unc++)
		Clear_SignalPhase_VoltStatistic_Data((unsigned char*)&VoltStat[unc]); 
	
	WRLC256(VOLTSTATISTICDATA_A_ROM,(unsigned char *)&VoltStat[0],sizeof(struct VoltStatistic_Data)*4,0,0);
	
	FeedWatchdog();
}

//reduced 130byte ,mw modified 2009-09-03
void VoltStatInit(void){
	unsigned char unc;
	unsigned char res;
	unsigned int uni;
	
	FeedWatchdog();
	uni=Crc16l((unsigned char*) &VoltStat[0],192);
	if(uni!=CrcVoltStatData){
	  res=0;
	  for(unc=0;unc<5;unc++){
		  
		  FeedWatchdog();
		  
	    res=WRLC256(VOLTSTATISTICDATA_A_ROM,(unsigned char *)&VoltStat[0],
	    4*sizeof(struct VoltStatistic_Data),0,1);
	  
	    if(res==0xFF)
	      break;
	  
    }
  
    if(res!=0xFF){
  	  for(unc=0;unc<4;unc++)
		    Clear_SignalPhase_VoltStatistic_Data((unsigned char*)&VoltStat[unc]);
    }
    CrcVoltStatData=Crc16l((unsigned char*) &VoltStat[0],192);
  }
	FeedWatchdog(); //modify by zlp
}

//reduced 748byte ,mw 
void VoltStatisticCheck(void)
{
	unsigned char unc;
	unsigned int Num_Month;
	
	FeedWatchdog();
	
	if((Powerdown_Save_Data.date.Year!=softdate.Year)||(Powerdown_Save_Data.date.Month!=softdate.Month))
	{
		Num_Month=( OB_H(softdate.Year)-OB_H(Powerdown_Save_Data.date.Year) )*12
		          +OB_H(softdate.Month)-OB_H(Powerdown_Save_Data.date.Month);
	}
	else
	{
		Num_Month=0;
	}
	if(Num_Month>0)
	{
		if(Num_Month>14)
		{
		  	Num_Month=14;
		}
		for(unc=0;unc<Num_Month;unc++)
		{
			CheckPowerDown();
			VoltStatisticBill();
		}
	}
}
/*"**************************************************"*/
/*"存储单一相的统计量,并清除统计缓冲区"*/
/*"Statistic->次数统计量的存储地址                       "*/
/*"DataBuff->电压统计量缓冲区                                 "*/
/*"FOffset->文件号偏移量                                             "*/
/*"**************************************************"*/
void Save_SignalPhase_Statistic(unsigned char* Statistic,
											    unsigned char* DataBuff,
											    unsigned int FOffset)
{
	unsigned int uni;
       ClearEvent_EventBegin(Statistic, FOffset);/*"电压合格率结算前清零判断处理"*/
	FeedWatchdog();
	CheckPowerDown();
	if((*(Statistic))<31)
		(*(Statistic))++;
	else
		*(Statistic)=0;
	uni=FOffset+(*(Statistic));
	Write_File(uni,0,48,DataBuff);
	Clear_SignalPhase_VoltStatistic_Data(DataBuff);
}

/*"**************************************"*/
/*"清除电压状态统计量缓冲区      "*/
/*"SignaPhase->电压统计量缓冲区         "*/
/*"**************************************"*/
void Clear_SignalPhase_VoltStatistic_Data(unsigned char*  SignaPhase)
{
	unsigned int uni,BuffSize;
	unsigned char* TempStatictis;

	TempStatictis = SignaPhase;
	BuffSize =	sizeof(struct VoltStatistic_Data);
	for(uni=0;uni < BuffSize; uni++)
	{
		if(uni <16)
			*(TempStatictis + uni) = 0;
		else
			*(TempStatictis + uni) = 0xFF;
	}
}
//-------------------------  Voltage Statistic Function  ------------------//
//----------------------  LostCurrent Function  ----------------------//
/*"================================================================="*/
/*"Function Name:失流事件记录                                                                 "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03    reduced 470byte                  "*/
/*"DESCRIPTION: 将A\B\C三相失流整成一项，In order to reduce the code "*/
/*"und=0为A相失流***und=1为B相失流***und=2为C相失流              "*/
/*"offset1\offset2\offset3为失流标志在相应结构中的偏移位置   "*/
/*"================================================================="*/
void LostCurrentEvent(void)
{
	unsigned int uni;	
	unsigned char und;		
  unsigned char offset1[3]= {1,0,0};	
  unsigned char offset2[3]= {2,2,1};			
  unsigned char offset3[3]= {0x20,0x40,0x80};
	
	for(und=0;und<3;und++)
	{
		if((V_REGION==0 || V_REGION==3)&&(und==1))
		{		
			continue;
		}
		
		int2ic &= 0xf8;
		
		if((Event_Power_Net_Flag.byte[0]&offset3[und])==0)
		{
	     if((Meter_Parameter.event_parameter.JudgeLostCurr_I[0]!=0)&&(Curr[und]<Meter_Parameter.event_parameter.JudgeLostCurr_I[0])
	       &&(eventmaxcurr>Meter_Parameter.event_parameter.JudgeLostCurr_I[1])
	       &&(Volt[und]>Meter_Parameter.event_parameter.JudgeLostCurrSV*1000l))
	     {	
		     (*((unsigned char *)&Event_N.LostCurrent_A_P+und))++;
		     if((*((unsigned char *)&Event_N.LostCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeLostCurr_T)
		     {
				   (*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
				   
				   Save_Event_StartData_Flash((&Event_Power_Net_Pointer.LostCurrent_A_P+und),(LOSTCURRENT_A_P_ROM+und),
                                      (LOSTCURR_A_BEGINFILE+und*32L),0,141,0x002D,
                                      ((unsigned long *)&Event_Power_Net_Times.LostCurrent_A_Times+und),(LOSTCURRENT_A_TIMES_ROM+und*4L));
				   
				   Event_Power_Net_Flag.byte[0]|=offset3[und];  //==1
				   if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x08)     
				   Save_EventReportTimes((LOSSCURR_A_TIMES_ROM+und*16),((unsigned char *)&Event_Report_Status_Times.LossCurr_A_times+und*16));
		   }
	   }
	   else
	   {
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
	   }
	}
	else
	{
	   if((Curr[und]>=Meter_Parameter.event_parameter.JudgeLostCurr_I[0])||(Meter_Parameter.event_parameter.JudgeLostCurr_I[0]==0))
	   {
			(*((unsigned char *)&Event_N.LostCurrent_A_P+und))++;
			if(((*((unsigned char *)&Event_N.LostCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeLostCurr_T)
			||(Meter_Parameter.event_parameter.JudgeLostCurr_I[0]==0))
			{
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
			  
			  Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P+und)),
                                 (LOSTCURR_A_BEGINFILE+und*32L),141,102,0x000D,
                                 ((unsigned long *)&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks+und),(LOSTCURRENT_A_TIMETICKS_ROM+4L*und));
			  				
				Event_Power_Net_Flag.byte[0]&=(~offset3[und]);  //  =0
			}
	   }
	   else
	   {
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
	   }
	}
	int2ic|=0x01;
	FeedWatchdog();
	}
	
}
//----------------------  LostCurrent Function  ----------------------//

//----------------------  BreakPhase Function  -----------------------//
//reduced 308byte ,mw modified 2009-09-03
void BreakPhaseEvent(void){
	unsigned char unc;
	unsigned char und;
	unsigned int uni;
	unsigned char offset[3]= {0x01,0x02,0x04};
	
	//------  A B C Phase  ------//	
	for(und=0;und<3;und++)
	{
	  if((V_REGION==0 || V_REGION==3)&&(und==1))		
		  continue;  //  331  B Phase is not include here
	  
	  int2ic &= 0xf8;
	  
  	if((Event_Power_Net_Flag.byte[1]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeBreakPhaseV!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeBreakPhaseV*1000l)
	      &&(Curr[und]<Meter_Parameter.event_parameter.JudgeBreakPhaseI)
	    	&&(EventCriticalVoltage_Flag==0))	    
	    {
			  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))++;
	   	  if((*((unsigned char *)&Event_N.BreakPhase_A_P+und))>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
	   	  {
				  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
				  
				  Save_Event_StartData_Flash((&Event_Power_Net_Pointer.BreakPhase_A_P+und),(BREAKPHASE_A_P_ROM+und),
                                     (BREAKPHASE_A_BEGINFILE+und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times+und),(BREAKPHASE_A_TIMES_ROM+und*4L));
				  
				  SaveEvent0BeginAmpHour(9+und);
				  
				  Event_Power_Net_Flag.byte[1]|=offset[und];  //==1
				  if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x80)   	  
				  Save_EventReportTimes((BREAKPHASE_A_EVENT_TIMES_ROM+und*16),((unsigned char *)&Event_Report_Status_Times.BreakPhase_A_event_times+und*16));
	   	  }
	    }
	    else
	    {
	   	 (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
	    }
	  }
	  else
	  {
	   if((Meter_Parameter.event_parameter.JudgeBreakPhaseV==0)||(Volt[und]>=Meter_Parameter.event_parameter.JudgeBreakPhaseV*1000l)
	     ||(Curr[und]>=Meter_Parameter.event_parameter.JudgeBreakPhaseI)||(EventCriticalVoltage_Flag!=0))	   
	   {	
			 (*((unsigned char *)&Event_N.BreakPhase_A_P+und))++;
	   	 if((Meter_Parameter.event_parameter.JudgeBreakPhaseV==0)
	   	   ||((*((unsigned char *)&Event_N.BreakPhase_A_P+und))>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
	   	 	 ||(EventCriticalVoltage_Flag!=0))			
			 {
				(*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;	
				
				 SaveEvent0EndAmpHour(9+und);
				 Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P+und)),
                                  (BREAKPHASE_A_BEGINFILE+und*32L),141,114,0x004D,
                                  ((unsigned long *)&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks+und),(BREAKPHASE_A_TIMETICKS_ROM+4L*und));
							
				 Event_Power_Net_Flag.byte[1]&=(~offset[und]);  //  =0	  
			 }
	    }
	    else
	    {
	   	  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
	    }
	   }
	   int2ic |= 0x01;
	   FeedWatchdog();
	}
	
}
//----------------------  BreakPhase Function  -----------------------//
//----------------------  Voltage Reverse Function  ---------------------//
void VoltReverseEvent(void)
{
  int2ic &= 0xf8;
  if(Event_Power_Net_Flag.bit.VoltageReserve==0)
	{
	   if((Abnormal_Phase_sequence!=0)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage)&&(EventCriticalVoltage_Flag==0))
	   {
		   Event_N.VoltageReserve_P++;
		   if(Event_N.VoltageReserve_P>=60)
		   {
		     Event_N.VoltageReserve_P=0;
			   
			   Save_Event_StartData_Flash((&Event_Power_Net_Pointer.VoltageReserve_P),VOLTAGERESERVE_P_ROM,
                                    VOLTREVERSE_BEGINFILE,0,102,0x000D,
                                   (&Event_Power_Net_Times.VoltageReserve_Times),VOLTAGERESERVE_TIMES_ROM);
			   
			   Event_Power_Net_Flag.bit.VoltageReserve=1;
         if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x01)   	    
         Save_EventReportTimes(VOLTREVERSE_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.VoltReverse_times);
		   }
	   }
	   else
	   {
		   Event_N.VoltageReserve_P=0;
	   }
	}
	else
	{
	   if(((Abnormal_Phase_sequence==0)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage))
	   ||(EventCriticalVoltage_Flag!=0))
	   {
		   Event_N.VoltageReserve_P++;
		   if((Event_N.VoltageReserve_P>=60)||(EventCriticalVoltage_Flag!=0))
		   {
		     Event_N.VoltageReserve_P=0;
			   
			   Save_Event_EndData_Flash(Event_Power_Net_Pointer.VoltageReserve_P,
                                  VOLTREVERSE_BEGINFILE,102,102,0x000D,
                                 ((unsigned long *)&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks),VOLTAGERESERVE_TIMETICKS_ROM);
			   				 
         Event_Power_Net_Flag.bit.VoltageReserve=0;
		   }
	   }
	   else
	   {
		   Event_N.VoltageReserve_P=0;
	   }
	}
	
	int2ic |= 0x01;
	FeedWatchdog();
	
}
//----------------------  Voltage Reverse Function  ---------------------//

//----------------------  Over Demand Function      ----------------------//
void OverDemandEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int  uni;
	unsigned char eventflag[6]={1,1,7,7,7,7};
	unsigned char offset[6]={0x40,0x80,0x08,0x10,0x20,0x40};
	unsigned int  eventfilename[6]={OVERPAADEMAND_BEGINFILE,OVERNEADEMAND_BEGINFILE,
	              OVER1RDEMAND_BEGINFILE,OVER2RDEMAND_BEGINFILE,OVER3RDEMAND_BEGINFILE,OVER4RDEMAND_BEGINFILE};
	unsigned long overdemandjudgep;
	
	for(und=0;und<6;und++)
	{
		
	  int2ic &= 0xf8;
	  
	  if(und<2)
	    overdemandjudgep=Meter_Parameter.event_parameter.JudgeOverDemandP*100l;
	  else
	    overdemandjudgep=Meter_Parameter.event_parameter.JudgeOverDemandN*100l;
	  
	  if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])==0)
	  {
	  	if((overdemandjudgep!=0)&&(Last_Average_Value[und][0]>overdemandjudgep))
	    {
	    	(*(&Event_N.OverPaADemand_P+und))++;
	    	if((*(&Event_N.OverPaADemand_P+und))>=Meter_Parameter.event_parameter.JudgeOverDemandT)
	    	{
	    	  (*(&Event_N.OverPaADemand_P+und))=0;
	    	
	    	  overdemandmaxdemand[und].Demand=Last_Average_Value[und][0];
		      for(unc=0;unc<5;unc++)
	           overdemandmaxdemand[und].time[unc]=*((unsigned char *)&softdate+unc);
	        WRLC256(OVERDEMANDMAXDEMAND_ROM+((unsigned int)und)*sizeof(struct DEMAND_DATA_FORM),
	        (unsigned char *)&overdemandmaxdemand[und],sizeof(struct DEMAND_DATA_FORM),0,0);
	        
			    Save_Event_StartData_Flash((&Event_Power_Net_Pointer.OverPaADemand_P+und),(OVERPAADEMAND_P_ROM+((unsigned int)und)),
                                      eventfilename[und],0,6,0x0001,
                                     (&Event_Power_Net_Times.OverPaADemand_Times+und),(OVERPAADEMAND_TIMES_ROM+und*4L));
			  
			    Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]|offset[und];
          if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x40)
          Save_EventReportTimes(OVERDEMAND_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.OverDemand_times);
			  }
	    }
	    else
	    {
	    	(*(&Event_N.OverPaADemand_P+und))=0;
	    }
	  }
	  else
	  {
	  	if((overdemandjudgep==0)||(Last_Average_Value[und][0]<=overdemandjudgep))
	  	{
	  		(*(&Event_N.OverPaADemand_P+und))++;
	  		if(((*(&Event_N.OverPaADemand_P+und))>=Meter_Parameter.event_parameter.JudgeOverDemandT)||(overdemandjudgep==0))
	    	{
	  		  (*(&Event_N.OverPaADemand_P+und))=0;
	  		
	  		  if((*(&Event_Power_Net_Pointer.OverPaADemand_P+und))>31)
		     	  (*(&Event_Power_Net_Pointer.OverPaADemand_P+und))=0;
		      uni=eventfilename[und]+(*(&Event_Power_Net_Pointer.OverPaADemand_P+und));
		      *((unsigned long *)&Co.b[626])=overdemandmaxdemand[und].Demand;
		      for(unc=0;unc<5;unc++)
	           Co.b[630+unc]=overdemandmaxdemand[und].time[unc];
	        PrepEvent0Data(0x0101);
		      Write_File(uni,6,15,&Co.b[300]);
		    
          Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]&(~offset[und]);
        }
	  	}
	  	else
	  	{
	  		if(overdemandmaxdemand[und].Demand<Last_Average_Value[und][0])
	  		{
	  			overdemandmaxdemand[und].Demand=Last_Average_Value[und][0];
		      for(unc=0;unc<5;unc++)
	           overdemandmaxdemand[und].time[unc]=*((unsigned char *)&softdate+unc);
	        WRLC256(OVERDEMANDMAXDEMAND_ROM+((unsigned int)und)*sizeof(struct DEMAND_DATA_FORM),
	        (unsigned char *)&overdemandmaxdemand[und],sizeof(struct DEMAND_DATA_FORM),0,0);
	  		}
	  		(*(&Event_N.OverPaADemand_P+und))=0;
	  	}
	  }
	  
	  int2ic |= 0x01;
	  FeedWatchdog();
	}
	
}


void PrepOverDemandFirstEventData(unsigned long tempunl)
{
	unsigned char eventflag;
	unsigned char offset;
	unsigned int  eventfilename;
	unsigned char und;
	unsigned char unc;
	
	switch(tempunl)
	{
			case 0x03120101:
			 eventflag=1;
			 offset=0x40;
			 eventfilename=OVERPAADEMAND_BEGINFILE;
			break;
			case 0x03120201:
			 eventflag=1;
			 offset=0x80;
			 eventfilename=OVERNEADEMAND_BEGINFILE;  
			break;
			case 0x03120301:
			 eventflag=7;
			 offset=0x08;
			 eventfilename=OVER1RDEMAND_BEGINFILE;
			break;
			case 0x03120401:
			 eventflag=7;
			 offset=0x10;
			 eventfilename=OVER2RDEMAND_BEGINFILE;  
			break;
			case 0x03120501:
			 eventflag=7;
			 offset=0x20;
			 eventfilename=OVER3RDEMAND_BEGINFILE;
			break;
			case 0x03120601:
			 eventflag=7;
			 offset=0x40;
			 eventfilename=OVER4RDEMAND_BEGINFILE;  
			break;
	}
	und=(unsigned char)((tempunl>>8)&0xff);
	und--;
	
	if((*(&Event_Power_Net_Pointer.OverPaADemand_P+und))>31)
		(*(&Event_Power_Net_Pointer.OverPaADemand_P+und))=0;
	eventfilename=eventfilename+(*(&Event_Power_Net_Pointer.OverPaADemand_P+und));
	
	Read_File(eventfilename,0,21,&TempEventData[0]);
		
	if((Event_Power_Net_Flag.byte[eventflag]&offset)!=0)
	{
	  *((unsigned long *)&Co.b[626])=overdemandmaxdemand[und].Demand;
		for(unc=0;unc<5;unc++)
	    Co.b[630+unc]=overdemandmaxdemand[und].time[unc];
	  PrepEvent0Data(0x0101);
	  for(unc=0;unc<6;unc++)
			 Co.b[300+unc]=0;
		for(unc=0;unc<15;unc++)
			 TempEventData[6+unc]=Co.b[300+unc];	
	}
	
}
//----------------------  Over Demand Function      ----------------------//

//----------------------  Power Reverse Function    ----------------------//
/*"================================================================="*/
/*"Function Name:反向事件记录                                                                 "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03     reduced 428byte                 "*/
/*"DESCRIPTION: 将A\B\C三相反向整成一项，In order to reduce the code"*/
/*"und=0为A相反向***und=1为B相反向***und=2为C相反向             "*/
/*"offset为反向标志在相应结构中的偏移位置                         "*/
/*"================================================================="*/
void PowerReverseEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;	
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
	for(und=0;und<3;und++)
	{
		if((V_REGION==0 || V_REGION==3)&&(und==1))
		{		
			continue;
		}
		
		int2ic &= 0xf8;
		
		if((Event_Power_Net_Flag.byte[2]&offset[und])==0)
		{
		   if((Meter_Parameter.event_parameter.JudgeABCPowerReverseP!=0)
		   &&(Meter_States.Meter_Status2.byte&offset[und])&& (Volt[und]>100000l)
			 &&(Active_power[und+1]>Meter_Parameter.event_parameter.JudgeABCPowerReverseP*100l))
		   {
				
				(*((unsigned char *)&Event_N.PowerReverse_A_P+und))++;
				
				if((*((unsigned char *)&Event_N.PowerReverse_A_P+und))>=Meter_Parameter.event_parameter.JudgeABCPowerReverseT)
				{
					(*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
					
					Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P+und),(POWERREVERSE_A_P_ROM+und),
                                     (POWERREVERSE_A_BEGINFILE+und*32L),0,102,0x000D,
                                     ((unsigned long *)&Event_Power_Net_Times.PowerReverse_A_Times+und),(POWERREVERSE_A_TIMES_ROM+und*4L));
					Event_Power_Net_Flag.byte[2]|=offset[und];
					if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x40)   
					Save_EventReportTimes((POWERRESERVE_A_TIMES_ROM+und*16),((unsigned char *)&Event_Report_Status_Times.PowerReserve_A_times+und*16));
				}
		   }
		   else
		   {
          (*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
		   }
		}
		else
		{
		   if((((Meter_States.Meter_Status2.byte&offset[und])==0)&& (Volt[und]>100000l))
		   ||(Meter_Parameter.event_parameter.JudgeABCPowerReverseP==0))
		   {			   
				
				(*((unsigned char *)&Event_N.PowerReverse_A_P+und))++;
				
				if(((*((unsigned char *)&Event_N.PowerReverse_A_P+und))>=Meter_Parameter.event_parameter.JudgeABCPowerReverseT)
				||(Meter_Parameter.event_parameter.JudgeABCPowerReverseP==0))
				{
					(*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
				  
				  Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P+und)),
                                   (POWERREVERSE_A_BEGINFILE+und*32L),102,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.PowerReverse_A_Ticks+und),(POWERREVERSE_A_TIMETICKS_ROM+und*4L));
				  				  
					Event_Power_Net_Flag.byte[2]&=(~offset[und]);			
				}
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;			   
		   }
		}
	  int2ic|=0x01;
	  FeedWatchdog();	
	}
	
}


void ALLPowerReverseEvent(void)
{
	unsigned int  uni;
	unsigned long judgepowerreversep;
	
	int2ic &= 0xf8;
	
	judgepowerreversep=Meter_Parameter.event_parameter.JudgePowerReverseP*100l;
	
	if(judgepowerreversep==0)
	{
		powerreversetflag[0]=0;
		powerreversetflag[1]=0;
		powerreversetcnt[0]=0;
		powerreversetcnt[1]=0;
		eventstatusinfo.bit.powertreverse=0;
		return;
	}
	
	if((Meter_States.Meter_Status2.bit.ActiveDirection_T==0)&&(Active_power[0]>judgepowerreversep))
	{
		powerreversetcnt[0]++;
		powerreversetcnt[1]=0;
		if(powerreversetcnt[0]>=Meter_Parameter.event_parameter.JudgePowerReverseT)
		{
			powerreversetflag[0]=1;
			powerreversetcnt[0]=0;
		}
	}
	else if((Meter_States.Meter_Status2.bit.ActiveDirection_T==1)&&(Active_power[0]>judgepowerreversep))
	{
		powerreversetcnt[0]=0;
		powerreversetcnt[1]++;
		if(powerreversetcnt[1]>=Meter_Parameter.event_parameter.JudgePowerReverseT)
		{
			powerreversetflag[0]=0xff;
			powerreversetcnt[1]=0;
		}
	}
	else
	{
		powerreversetcnt[0]=0;
		powerreversetcnt[1]=0;
	}
	
	if((powerreversetflag[0]!=0)&&(powerreversetflag[1]!=0)&&(powerreversetflag[0]!=powerreversetflag[1]))
	{
		Save_Event_StartData_Flash(&Event_Power_Net_Pointer.PowerReverse_T_P,POWERREVERSE_T_P_ROM,
                                POWERREVERSE_T_BEGINFILE,0,103,0x040D,
                                &Event_Power_Net_Times.PowerReverse_T_Times,POWERREVERSE_T_TIMES_ROM);
                                
		eventstatusinfo.bit.powertreverse=0;
		if(powerreversetflag[0]==0xff)
		  eventstatusinfo.bit.powertreverse=1;
       if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x02)
            {
		EventReportState_Expand(2, 3,0);
		Save_EventReportTimes(TOTALPOWERREVERSE_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.TotalPowerReverse_times);
            }
	}
	
	if((powerreversetflag[0]==0xff)&&(powerreversetflag[1]==0))
	{
		  eventstatusinfo.bit.powertreverse=1;
	}
	
	powerreversetflag[1]=powerreversetflag[0];
	
	FeedWatchdog();
	int2ic|=0x01;
}
//----------------------  Power Reverse Function    ----------------------//
//----------------------------- AdjustTime Record ----------------------------//
unsigned int AdjustTimeRecord(unsigned long progman)
{
	
	(*((unsigned long *)&Co.b[400]))=progman;
        
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.AdjustTimeRecord_P,ADJUSTTIMERECORD_P_ROM,
                         ADJUSTTIMERECORD_BEGINFILE,16,
                         &Event_Meter_Pro_Times.AdjustTimeRecord_Times,ADJUSTTIMERECORD_TIMES_ROM);
  		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x10)
  		 {
  		 EventReportState_Expand(0, 4, 0);
  		 Save_EventReportTimes(ADJUSTTIME_EVENT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.AdjustTime_event_times);
  		 }
  
	return 0xFFFF;
}
//----------------------------- AdjustTime Record ----------------------------//

//----------------------------- ClearDemand Record ---------------------------//
unsigned int ClearDemandRecord(unsigned long progman)
{
	unsigned char unc;
	unsigned int uni;
	
	for(unc=0;unc<226;unc++)
	{
	  Co.b[400+unc]=0xFF;
	}
	for(unc=0;unc<=5;unc++)
	{
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	}
	(*((unsigned long *)&Co.b[406]))=progman;
	(*((unsigned long *)&Co.b[410]))=This_Month_Data.Demand_Record.Demand.Plus_Active[0].Demand;
	(*((unsigned long *)&Co.b[414]))=This_Month_Data.Demand_Record.Demand.Nega_Active[0].Demand;
	(*((unsigned long *)&Co.b[418]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[0][0].Demand;
	(*((unsigned long *)&Co.b[422]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[1][0].Demand;
	(*((unsigned long *)&Co.b[426]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[2][0].Demand;
	(*((unsigned long *)&Co.b[430]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[3][0].Demand;
	for(unc=0;unc<=4;unc++)
	{
	  Co.b[506+unc]=This_Month_Data.Demand_Record.Demand.Plus_Active[0].time[unc];
	  Co.b[511+unc]=This_Month_Data.Demand_Record.Demand.Nega_Active[0].time[unc];
	  Co.b[516+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[0][0].time[unc];
	  Co.b[521+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[1][0].time[unc];
	  Co.b[526+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[2][0].time[unc];
	  Co.b[531+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[3][0].time[unc];
	}
	 
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearDemandRecord_P,CLEARDEMANDRECORD_P_ROM,
                         CLEARDEMANDRECORD_BEGINFILE,226,
                         &Event_Meter_Pro_Times.ClearDemandRecord_Times,CLEARDEMANDRECORD_TIMES_ROM);
 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x04)
 {
  EventReportState_Expand(0, 2, 0);
  Save_EventReportTimes(DEMAND_CLEAR_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Demand_clear_times);
 }
	return 0xFFFF;
}
//----------------------------- ClearDemand Record ---------------------------//

//----------------------------- ClearEvent Record  ---------------------------//
unsigned int ClearEventRecord(unsigned long progman,unsigned long progflag)
{
	unsigned char unc;
	unsigned int uni;
	
	show_clear_char();	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	(*((unsigned long *)&Co.b[410]))=progflag;
  
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearEventRecord_P,CLEAREVENTRECORD_P_ROM,
                          CLEAREVENTRECORD_BEGINFILE,14,
                          &Event_Meter_Pro_Times.ClearEventRecord_Times,CLEAREVENTRECORD_TIMES_ROM);
	
	return 0xFFFF;
}
//----------------------------- ClearEvent Record  ---------------------------//

//----------------------------- ProgWeek Record    ---------------------------//
unsigned int ProgWeekRecord(unsigned long progman,unsigned char progoldvalue)
{
	unsigned char unc;
	unsigned int uni;
	
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	Co.b[410]=progoldvalue;
	     
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgWeekRecord_P,PROGWEEKRECORD_P_ROM,
                         PROGWEEKRECORD_BEGINFILE,11,
                         &Event_Meter_Pro_Times.ProgWeekRecord_Times,PROGWEEKRECORD_TIMES_ROM);
      if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x80) 
      {
      EventReportState_Expand(0, 7, 0);
      Save_EventReportTimes(PROGWEEK_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgWeek_times);
      }
	return 0xFFFF;
}
//----------------------------- ProgWeek Record    ---------------------------//

//---mw modified 2009-09-03---- ProgAEMode/NEMode1/NEMode2  Record  ---------//
//reduced 244byte 
unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,unsigned char  progoldvaluep,unsigned char sort)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char * Epointer;
	unsigned int EOffset,EEROM1,EEROM2;
	unsigned long * Temp_times;
	unsigned char offset[3]={0x02,0x04,0x08};
	
	Temp_times=((unsigned long*)&Event_Meter_Pro_Times.ProgAEModeRecord_Times+sort);
	EEROM1=PROGAEMODERECORD_P_ROM+sort;
	EEROM2=PROGAEMODERECORD_TIMES_ROM+sort*4L;
	Epointer=((unsigned char*)&Event_Meter_Pro_Pointer.ProgAEModeRecord_P+sort);
	EOffset=PROGAEMODERECORD_BEGINFILE+sort*32L;
	
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	Co.b[410]=(progoldvaluep);
	
	Save_Record_Data_Flash(Epointer,EEROM1,
                         EOffset,11,
                         Temp_times,EEROM2);
      if(((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x02) &&(0==sort)) 
        ||((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x04) &&(1==sort))
        ||((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x08) &&(2==sort)))
      {
      EventStatus_flag.byte[1] |= offset[sort];
      WRLC256((EVENTSTATUS_FLAG_ROM+1),(unsigned char *)&EventStatus_flag.byte[1],1,0,0);
      Save_EventReportTimes((PROGAEMODE_TIMES_ROM + sort), ((unsigned char *)&Event_Report_Status_Times.ProgAEMode_times + sort));
      }
	return 0xFFFF;
}

//----------------------------- ProgBillDay Record ---------------------------//
unsigned int ProgBillDayRecord(unsigned long progman,unsigned char * progoldvaluep)
{
	unsigned char unc;
	unsigned int uni;
  
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	for(unc=0;unc<=5;unc++)
	  Co.b[410+unc]=*(progoldvaluep+unc);
	   
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgBillDayRecord_P,PROGBILLDAYRECORD_P_ROM,
                         PROGBILLDAYRECORD_BEGINFILE,16,
                         &Event_Meter_Pro_Times.ProgBillDayRecord_Times,PROGBILLDAYRECORD_TIMES_ROM);
if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x10) 
{
  EventReportState_Expand(1, 4, 0);
  Save_EventReportTimes(PROGBILLDAY_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgBillDay_times);
}
	return 0xFFFF;
}
//----------------------------- ProgBillDay Record ---------------------------//

//----------------------------- ProgYearSlot Record --------------------------//
unsigned int ProgYearSlotRecord(unsigned long progman)
{
	unsigned char unc;
	unsigned int uni;
  
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	FeedWatchdog();
	WRLC256(YEARSLOT_ROM,&Co.b[410],42,0,1);
	FeedWatchdog();
	WRLC256(YEARSLOT2_ROM,&Co.b[452],42,0,1);
  if(Comm_DailyOrYear_Slot==1||Comm_DailyOrYear_Slot==2)
  {
     for(unc=0;unc<42;unc++)
       Co.b[410+unc+(Comm_DailyOrYear_Slot-1)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
	 
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgYearSlotRecord_P,PROGYEARSLOTRECORD_P_ROM,
                         PROGYEARSLOTRECORD_BEGINFILE,94,
                         &Event_Meter_Pro_Times.ProgYearSlotRecord_Times,PROGYEARSLOTRECORD_TIMES_ROM);
  if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x40) 
  {
  EventReportState_Expand(0, 6, 0);
  Save_EventReportTimes(PROGYEARSLOT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgYearSlot_times);
  }
	return 0xFFFF;
}
//----------------------------- ProgYearSlot Record --------------------------//

//----------------------------- ProgDailySlot Record -------------------------//
unsigned int ProgDailySlotRecord(unsigned long progman){
	unsigned char unc=0;
	unsigned int uni=0;

	ClearEvent_EventBegin((unsigned char *)&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P, 
						    PROGDAILYSLOTRECORD_BEGINFILE);/*"日时段表编程事件清零判断处理"*/
	FeedWatchdog();
	if(Event_Meter_Pro_Pointer.ProgDailySlotRecord_P<31)
		Event_Meter_Pro_Pointer.ProgDailySlotRecord_P++;
	else
		Event_Meter_Pro_Pointer.ProgDailySlotRecord_P=0;
	for(unc=0;unc<=5;unc++)
	  Co.b[300+unc]=*((unsigned char *)&softdate+unc);
	(*((unsigned long *)&Co.b[306]))=progman;
	WRLC256(DAILYSLOT_ROM,&Co.b[310],210,0,1);
    if((Comm_DailyOrYear_Slot>0)&&(Comm_DailyOrYear_Slot<=5))
    {
        for(unc=0;unc<42;unc++)
            Co.b[310+unc+(Comm_DailyOrYear_Slot-1)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
    }
	//402-412 prog dailyslot record
	uni=PROGDAILYSLOTRECORD_BEGINFILE+Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,220,&Co.b[300]);
  FeedWatchdog();
  WRLC256(DAILYSLOT_ROM+210,&Co.b[300],126,0,1);
  if((Comm_DailyOrYear_Slot>5)&&(Comm_DailyOrYear_Slot<=8))
  {
        for(unc=0;unc<42;unc++)
            Co.b[300+unc+(Comm_DailyOrYear_Slot-6)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
  WRLC256(DAILYSLOT2_ROM,&Co.b[426],126,0,1);
  if((Comm_DailyOrYear_Slot>8)&&(Comm_DailyOrYear_Slot<=11))
  {
        for(unc=0;unc<42;unc++)
            Co.b[426+unc+(Comm_DailyOrYear_Slot-9)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
  //413-423 prog dailyslot record
  uni=PROGDAILYSLOTRECORD_BEGINFILE+32L+Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,252,&Co.b[300]);
  FeedWatchdog();
  WRLC256(DAILYSLOT2_ROM+126,&Co.b[300],210,0,1);
  if((Comm_DailyOrYear_Slot>11)&&(Comm_DailyOrYear_Slot<=16))
  {
        for(unc=0;unc<42;unc++)
            Co.b[300+unc+(Comm_DailyOrYear_Slot-12)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
  //424-434 prog dailyslot record
  uni=PROGDAILYSLOTRECORD_BEGINFILE+64L+Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,210,&Co.b[300]);
  FeedWatchdog();
  	//modified by mw 2009-09-03
	Save_EventTimesANDPointer_4byte(PROGDAILYSLOTRECORD_P_ROM,PROGDAILYSLOTRECORD_TIMES_ROM,
	((unsigned char *)&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P),
	(&Event_Meter_Pro_Times.ProgDailySlotRecord_Times)); 
  //WRLC256(PROGDAILYSLOTRECORD_P_ROM,&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P,1,3,0);
  //Event_Meter_Pro_Times.ProgDailySlotRecord_Times++;
  //WRLC256(PROGDAILYSLOTRECORD_TIMES_ROM,(unsigned char *)&Event_Meter_Pro_Times.ProgDailySlotRecord_Times,4,3,0);
	FeedWatchdog();
  		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x20)
  		 {
  		 EventReportState_Expand(0, 5, 0);
  		 Save_EventReportTimes(PROGDAILYSLOT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ProgDailySlot_times);
  		 }
	return 0xFFFF;
}
//----------------------------- ProgDailySlot Record -------------------------//

//------------------------------  OpenBox Event  ----------------------------//
/*"mw modified 2009-09-03*******************************************
*开表盖开端钮盒事件记录
*将两个事件整成一个，节省空间
*und=0为开表盖事件****und=1为开端钮盒事件记录
*offset为开盖状态标志在相应结构中的偏移位置
*Eeprom.h    Defdata.h  reduced 360byte 
**************************************************************"*/
void OpenBoxCoverEvent_Check(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[2]= {0x40,0x80};	
	unsigned int Filename[2]= {OPENCOVEREVENT_BEGINFILE,OPENBOXEVENT_BEGINFILE};	 //modified by mw 2009-10-21
	
	
	FeedWatchdog();
	
	for(und=0;und<2;und++)
	{
	  int2ic &= 0xf8;
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)			
	    {
             if(((und==0)&&(p8_3==0))||((und==1)&&(p2_5==0)))
             {
                 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))++;
		   if((*((unsigned char *)&Event_N.OpenCoverEvent_P+und))>1)
		   {
		      *((unsigned char *)&Event_N.OpenCoverEvent_P+und)=0;
		      
		      MoveEventData2Flash(LASTOPENCOVEREVENT_ROM+und*60L,Filename[und],((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P + und),60);
				  
				  PrepEvent0Data(0x0005);
		      
		      Save_Event_StartData_Eeprom(((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P+und),(OPENCOVEREVENT_P_ROM+und),
                                      (LASTOPENCOVEREVENT_ROM+und*60L),30,
                                      ((unsigned long *)&Event_Power_Net_Times.OpenCoverEvent_Times+und),(OPENCOVEREVENT_TIMES_ROM+und*4L));
		      
		      Event_Power_Net_Flag.byte[3]|=offset[und];  //==1
		      if(((Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x04)&&(0==und))  
		      ||((Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x08)&&(1==und)))
		         Save_EventReportTimes((OPEN_METER_COVER_TIMES_ROM+und),((unsigned char *)&Event_Report_Status_Times.Open_Meter_Cover_times+und));
		   }
             }
             else
             {
		  (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
             }
	    }
	else
	    {
		  if(((und==0)&&(p8_3==1))||((und==1)&&(p2_5==1)))
		   {
			(*((unsigned char *)&Event_N.OpenCoverEvent_P+und))++;
			if((*((unsigned char *)&Event_N.OpenCoverEvent_P+und))>1)
			{
				 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
				 PrepEvent0Data(0x0005);
				 WRLC256(LASTOPENCOVEREVENT_ROM+und*60L+30L,&Co.b[300],30,0,0);
				 Event_Power_Net_Flag.byte[3]&=(~offset[und]);  //  =0
			}
		   }
                else
                {
				 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
                }
	    }
    	 int2ic|=0x01;
	 FeedWatchdog();
	}
}
//------------------------------  OpenBox Event  ----------------------------//

//------------------------------  OverVoltage Event -------------------------//
/*"================================================================="*/
/*"Function Name:过压事件记录                                                                 "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03    reduced 624byte                  "*/
/*"DESCRIPTION:将A\B\C三相过压整成一项，节省空间                 "*/
/*"und=0为A相过压***und=1为B相过压***und=2为C相过压             "*/
/*"offset为过压标志在相应结构中的偏移位置                         "*/
/*"================================================================="*/
//------------------------------  OverVoltage Event -------------------------//
void OverVoltageEvent(void)
{
	unsigned char unc;
	unsigned char und;	
	unsigned int uni;
  unsigned char offset[3]= {0x08,0x10,0x20};
	
	for(und=0;und<3;und++)
	{
	  if((V_REGION==0 || V_REGION==3)&&(und==1))
	  {		
		  continue;
	  }
	  
	  int2ic &= 0xf8;
	  
	  if((Event_Power_Net_Flag.byte[2]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeOverVolt_V!=0)&&(Volt[und]>Meter_Parameter.event_parameter.JudgeOverVolt_V*1000l))
	    {
			
			  (*((unsigned char *)&Event_N.OverVoltage_A_P+und))++;
			  
			  if((*((unsigned char *)&Event_N.OverVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverVoltT)
			  {
				  *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
				  
				  Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P+und),(OVERVOLTAGE_A_P_ROM+und),
                                     (OVERVOLT_A_BEGINFILE+und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.OverVoltage_A_Times+und),(OVERVOLTAGE_A_TIMES_ROM+und*4L));
				  SaveEvent0BeginAmpHour(6+und);
				  Event_Power_Net_Flag.byte[2]|=offset[und];
			        if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x04)  			  
				  Save_EventReportTimes((OVERVOLT_A_TIMES_ROM+und*16),((unsigned char *)&Event_Report_Status_Times.OverVolt_A_times+und*16));
			}
	   }
	   else
	   {
	   	  *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
		 }
	 }
	 else
	 {
	   if((Volt[und]<=Meter_Parameter.event_parameter.JudgeOverVolt_V*1000l)||(Meter_Parameter.event_parameter.JudgeOverVolt_V==0))
	   {
				
			 (*((unsigned char *)&Event_N.OverVoltage_A_P+und))++;
			
			 if(((*((unsigned char *)&Event_N.OverVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverVoltT)
			 ||(Meter_Parameter.event_parameter.JudgeOverVolt_V==0))
			 {
				 *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
				 
				 SaveEvent0EndAmpHour(6+und);
				 Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P+und)),
                                  (OVERVOLT_A_BEGINFILE+und*32L),141,114,0x004D,
                                  ((unsigned long *)&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks+und),(OVERVOLT_A_TIMETICKS_ROM+und*4L));				
				 
				 Event_Power_Net_Flag.byte[2]&=(~offset[und]);
			 }
	   }
	   else
	   {
			   (*((unsigned char *)&Event_N.OverVoltage_A_P+und))=0;	
	   }
	 }
	 int2ic|=0x01;
	 FeedWatchdog();
	}
	
}
//------------------------------  OverVoltage Event -------------------------//
//-------------------------- Clear EventRecord Function -----------------------//
const struct VOLTCHECK_STRU  VoltCheck_ABC[]={
  {(unsigned char*)&VoltCheck_N[0][0].byte,(unsigned char*)&VoltCheck_N[0][1].byte},
  {(unsigned char*)&VoltCheck_N[1][0].byte,(unsigned char*)&VoltCheck_N[1][1].byte},
  {(unsigned char*)&VoltCheck_N[2][0].byte,(unsigned char*)&VoltCheck_N[2][1].byte},  
};

/*"================================================================="*/
/*"Function Name:清事件                                                                                "*/
/*"Modifier:	mw   Date:2009-09-03                                                                       "*/
/*"DESCRIPTION: reduced 7K byte ,Defdata.h                                                           "*/
/*"============================================================== =="*/
unsigned char ClearNewEventRecord(unsigned long cleareventman,unsigned long cleareventflag)
{
	const struct CLEAREVENT_STRU *Event_Node1;
	const struct VOLTCHECK_STRU *Temp_p;	
	union BYTE_BIT   Dispose_clearevent_flag;  
	unsigned int uni=0;
	unsigned char result_findOK=0;
	unsigned char result=0;
	unsigned int   unc=0;
	unsigned char mask=0;
    	union EVENT_REPORT_STATUS ResetEventReportStatus;
        
	Dispose_clearevent_flag.byte=0;
	
	FeedWatchdog();
	CheckPowerDown();	
		for(uni=0;uni<((sizeof(Clearevent_ID))/sizeof(unsigned long));uni++)         /*"查找数据标识"*/
		{
			if(cleareventflag==0xFFFFFFFF)
			{
				result_findOK=0x11;  /*"表示要全清"*/
				break;
			}
		 	else if(Clearevent_ID[uni]==cleareventflag)
		 	{
				result_findOK=0x01;  /*"表示只清某一类"*/
				Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[uni];
				break;
		 	}			
		}
        
            if(cleareventflag==0xFFFFFFFF)
            {
                for(uni=0; uni<12; uni++)
                {
                ResetEventReportStatus.byte[uni]=0x00;
                }
                ResetEventReportStatus.byte[10]=0x0A;/*"事件清零和电表清零不清"*/
                Clear_EventReportStatus_And_Times(ResetEventReportStatus);
   
                for(uni=0 ; uni<5; uni++)
                {
                if(0 != EventStatus_flag.byte[uni])
                {
                EventStatus_flag.byte[uni]=0;
                WRLC256((EVENTSTATUS_FLAG_ROM+uni),(unsigned char *)&EventStatus_flag.byte[uni],1,0,0);
                }
                }
            }
            
		/*"查到数据标识,根据配置标志采用分包处理"*/
		if(result_findOK) 
		{
			//ClearEventRecord(cleareventman,cleareventflag);	
			for(unc=0;unc<((sizeof(Clearevent_ID))/sizeof(unsigned long));unc++)
			{
					if(result_findOK==0x11)    
					{
						/*"全清循环处理"*/
						Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[unc];
					}
					Dispose_clearevent_flag.byte=Event_Node1->Dispose_flag;
					/*"清某一类事件分解为以下某几种组合"*/
					if((Dispose_clearevent_flag.bit.b0)==1)   /*"处理包1"*/
					{
							//Clear times and ticks according to the length of data
							CheckPowerDown();  
							result=0xFF;
							if(((Event_Node1->Times)!=NULL)&&((Event_Node1->Ticks)!=NULL)) /*"程序防护"*/
							{
								for(uni=0;uni<((Event_Node1->Length)/4);uni++)
								{
									*((Event_Node1->Times)+uni)=0;  
									*((Event_Node1->Ticks)+uni)=0;  
								}		
							}
							WRLC256((Event_Node1->Times_addr),0,(Event_Node1->Length),0,0);
							WRLC256((Event_Node1->Ticks_addr),0,(Event_Node1->Length),0,0);
							FeedWatchdog();			
					}
					if((Dispose_clearevent_flag.bit.b1)==1) /*"处理包2"*/
					{
							//Clear 2  Flags 
							CheckPowerDown();  
							result=0xFF;
							if(((Event_Node1->Flag)!=NULL))
							{
								(*(Event_Node1->Flag))&=(~(Event_Node1->Offset));  //  =0
								//(*(Event_Node1->Eventflag))&=(~(Event_Node1->Offset));  //  =0	
							}
		
					}
					if((Dispose_clearevent_flag.bit.b2)==1)  /*"处理包3"*/
					{
						//Clear   Pointer   and   File 
						result=0xFF;  
						if((Event_Node1->Pointer)!=NULL)
						{
							*(Event_Node1->Pointer)=0;
							WRLC256((Event_Node1->Pointer_addr),0,1,0,0);
						}
						//for(uni=(Event_Node1->Filename_begin);uni<=(Event_Node1->Filename_end);uni++)
						//{
							FeedWatchdog();
							CheckPowerDown();
							uni=(Event_Node1->Filename_begin);
							Delete_File(uni);
						//}
						FeedWatchdog();					
					}
					if((Dispose_clearevent_flag.bit.b3)==1)  /*"处理包4"*/
					{
						//Clear Times 
						result=0xFF;
						if((Event_Node1->Times)!=NULL)
						{
							*(Event_Node1->Times)=0; 
						}
						WRLC256((Event_Node1->Times_addr),0,4,0,0);		
					}	
					if((Dispose_clearevent_flag.bit.b4)==1)  /*"处理包5"*/
					{
						//Clear ticks 
						result=0xFF;
						if((Event_Node1->Ticks)!=NULL)
						{
							*(Event_Node1->Ticks)=0; 
							WRLC256((Event_Node1->Ticks_addr),0,4,0,0);		
						}
					}					
					if((Dispose_clearevent_flag.bit.b5)==1)  /*"处理包6"*/
					{
						/*"专清电压合格数据, pointer and file is not include "*/
						CheckPowerDown();  //ESP
						Temp_p=( const struct VOLTCHECK_STRU *)&VoltCheck_ABC[Event_Node1->Length];
						result=0xFF;
						mask=(Event_Node1->Offset);
						if((Event_Node1->Flag)!=NULL)
						{
							for(uni=0;uni<3;uni++)    /*"标志特殊处理"*/
							{
								(*(Event_Node1->Flag))&=(~mask);  //  =0
								mask <<= 1;
							}	
						}
						if(((Temp_p->Flag1)!=NULL)&&((Temp_p->Flag2)!=NULL))
						{
						*(Temp_p->Flag1)=0;  
						*(Temp_p->Flag2)=0;  	
						}
						Clear_SignalPhase_VoltStatistic_Data((unsigned char*) &VoltStat[(Event_Node1->Length)]);
						WRLC256((Event_Node1->Eeprom_addr),(unsigned char *)&VoltStat[(Event_Node1->Length)],48,0,0);
						FeedWatchdog();		
					}
					if((Dispose_clearevent_flag.bit.b6)==1)  /*"处理包7"*/
					{
						//Especially  dispose , for LostVoltage
						result=0xFF;
						for(uni=0;uni<36;uni++)  
						  TempEventData[uni]=0xFF;
						WRLC256(LASTLOSTVOLTBEGINTIME_A_ROM,&TempEventData[0],36,0,0);
						//WRLC256(LOSTVOLTENERGY_A_ROM,0,24,3,0);
						FeedWatchdog();		
					}
					if((Dispose_clearevent_flag.bit.b7)==1)  /*"处理包8"*/
					{
						//Clear  event data of eeprom
						FeedWatchdog();
						for(uni=0;uni<255;uni++)  
						  TempEventData[uni]=0xFF;	
						WRLC256((Event_Node1->Eeprom_addr),&TempEventData[0],(Event_Node1->Length),0,0);	
						FeedWatchdog();	
						result=0xFF;
					}
					
					/*"清某一类事件跳出循环，只有全清才循环"*/
					if(result_findOK==0x01)  
					break;
			}
				
		//if(result_findOK==0x11)
                //Check_Show_Flash_Data(0xff,0,0xff,0); //closed by mw 2010-01-07
		}
		/*"清负控报警特殊处理"*/
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x034200FF))
			CloseOverPowerAlarmSwitch();
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033005FF))
			result=ClearProgDailySlotRecord(cleareventman,cleareventflag);	
			
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033002FF))
		{
			for(uni=0;uni<sizeof(struct DATEANDTIME_DEF);uni++)  
				*((unsigned char *)&Other_Data.LastClearDemandDateCM+uni)=0;		
			//Other_Data.LastClearDemandDateCM=0; 
			FeedWatchdog();
 	 		WRLC256(LASTCLEARDEMANDDATECM_ROM,
				(unsigned char *)&Other_Data.LastClearDemandDateCM,sizeof(struct DATEANDTIME_DEF),0,0);
                        FeedWatchdog(); 
//			Event_Meter_Pro_Times.DemandClear_Times=0;			
//			WRLC256(DEMANDCLEAR_TIMES_ROM,(unsigned char *)&Event_Meter_Pro_Times.DemandClear_Times,2,0,0);
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x031200FF))
		{
			for(uni=0;uni<4;uni++)
			  (*(&Event_Power_Net_Times.Over1RDemand_Times+uni))=0;			
			WRLC256(OVER1RDEMAND_TIMES_ROM,(unsigned char *)&Event_Power_Net_Times.Over1RDemand_Times,16,0,0);
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x031000FF))
		{
			Clear_SignalPhase_VoltStatistic_Data((unsigned char*) &VoltStat[3]);
			WRLC256(VOLTSTATISTICDATA_T_ROM,(unsigned char *)&VoltStat[3],48,0,0);
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x210000FF))
		{
			powerreversetflag[0]=0;
	    powerreversetflag[1]=0;
	    powerreversetcnt[0]=0;
	    powerreversetcnt[1]=0;
	    eventstatusinfo.bit.powertreverse=0;
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x03300DFF))
		{
			eventstatusinfo.bit.powerdownopencover=0;
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x03300EFF))
		{
			eventstatusinfo.bit.powerdownopenbox=0;
		}
		
       if(cleareventflag==0x1000FFFF)
       {
		     WRLC256(LOSTVOLTENERGY_A_ROM,0,24,0,0);
	         FeedWatchdog();
       }
    	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1001FFFF))
			ClearEventAddEnergy(LOSTVOLTENERGY_A_ROM);
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1002FFFF))
			ClearEventAddEnergy(LOSTVOLTENERGY_B_ROM);
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1003FFFF))
			ClearEventAddEnergy(LOSTVOLTENERGY_C_ROM);
		
		if (!clearFlag)
		{
			ClearPaymentEventRecord(cleareventman,cleareventflag);		//payment
			result=0xFF;//lfy add 2011-03-18
		}
			
		if(result==0xFF)
		Check_Show_Flash_Data(0xff,0,0xff,0);	
		//modified by mw 2010-01-07
		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x08)
		 {
		        EventReportState_Expand(0, 3, 0);
                     Save_EventReportTimes(EVENT_CLEAR_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Event_clear_times);
		 }
		return result;			
}

//------ClearProgDailySlotRecord------//
unsigned char ClearProgDailySlotRecord(unsigned long cleareventman,unsigned long cleareventflag)
{
	
	Delete_File(PROGDAILYSLOTRECORD_BEGINFILE);
	Delete_File(PROGDAILYSLOTRECORD_BEGINFILE+32L);
	Delete_File(PROGDAILYSLOTRECORD_BEGINFILE+64L);
	Event_Meter_Pro_Times.ProgDailySlotRecord_Times=0;
	WRLC256(PROGDAILYSLOTRECORD_TIMES_ROM,0,4,0,0);
	Event_Meter_Pro_Pointer.ProgDailySlotRecord_P=0;
	WRLC256(PROGDAILYSLOTRECORD_P_ROM,&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P,1,0,0);
	FeedWatchdog();

	return 0xFF;	
}
//------ClearProgDailySlotRecord------//

unsigned char ClearEventAddEnergy(unsigned int eventeepromaddr){
	
	WRLC256(eventeepromaddr,0,8,0,0);
	FeedWatchdog();
	return 0xFF;
}


//-------------------------- Clear ClearEvent Function  -----------------------//
//-------------------------- Phase3 Lost Volt Function  -----------------------//
void Phase3LostVoltEvent(void){
	unsigned char unc;
	unsigned char lowvoltflag;
	unsigned int uni;
	
	int2ic &= 0xf8;
	FeedWatchdog();
	
	lowvoltflag=0;
	if(eventmaxvolt*100l<Meter_Parameter.event_parameter.CriticalVoltage*EventUn)
	  lowvoltflag=1;
	
  if(Event_Power_Net_Flag.bit.Phase3LostVolt==0)
	{
	   if((lowvoltflag==1)&&(eventmaxcurr*20>EventIb)
	     &&(Event_Power_Net_Flag.bit.PowerDownEvent==0))
	   {
		   Event_N.Phase3LostVolt_P++;
		   if(Event_N.Phase3LostVolt_P>=60)
		   {
		    Event_N.Phase3LostVolt_P=0;
			  
		    MoveEventData2Flash(LASTPHASE3LOSTVOLT_ROM,PHASE3LOSTVOLT_BEGINFILE,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,16);
		    
	      *((unsigned long *)&Co.b[622])=eventavgcurr;
	      PrepEvent0Data(0x0081);
	      
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.Phase3LostVolt_P,PHASE3LOSTVOLT_P_ROM,
                                    LASTPHASE3LOSTVOLT_ROM,10,
                                    &Event_Power_Net_Times.Phase3LostVolt_Times,PHASE3LOSTVOLT_TIMES_ROM);
		    
		    Event_Power_Net_Flag.bit.Phase3LostVolt=1; 
                if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x04)
                Save_EventReportTimes(ALLLOSTVOLTAGE_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.AllLostVoltage_times);
		   }
	    }
	    else
	    {
		   Event_N.Phase3LostVolt_P=0;
	    }
	}
	else
	{
	   if(lowvoltflag==0)
	   {
		   Event_N.Phase3LostVolt_P++;		 
		   if(Event_N.Phase3LostVolt_P>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
		   {
		    Event_N.Phase3LostVolt_P=0;
		    
		    PrepEvent0Data(0x0001);
				WRLC256(LASTPHASE3LOSTVOLT_ROM+10L,&Co.b[300],6,0,0);
				
				SaveEvent0LastTime_Other(PHASE3LOSTVOLT_TIMETICKS_ROM,
			  ((unsigned long *)&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks));
			  				
		    Event_Power_Net_Flag.bit.Phase3LostVolt=0;
		   }
	   }
	   else
	   {
		   Event_N.Phase3LostVolt_P=0;
	   }
	}
	FeedWatchdog();
	if(Event_Power_Net_Flag.bit.PowerDownEvent==0)
	{
	   if((lowvoltflag==1)&&(eventmaxcurr*20<=EventIb)
	   &&(Event_Power_Net_Flag.bit.Phase3LostVolt==0))
	   {
		   Event_N.PowerDown_P++;
		   if(Event_N.PowerDown_P>=60)
		   {
		    Event_N.PowerDown_P=0;
			  
		    MoveEventData2Flash(LASTPOWERDOWNEVENT_ROM,POWERDOWNEVENT_BEGINFILE,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,12);
		    
	      PrepEvent0Data(0x0001);
		    
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.PowerDown_P,POWERDOWN_P_ROM,
                                    LASTPOWERDOWNEVENT_ROM,6,
                                    &Event_Power_Net_Times.PowerDown_Times,POWERDOWN_TIMES_ROM);
		    
		    Event_Power_Net_Flag.bit.PowerDownEvent=1;
        if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x20)
        Save_EventReportTimes(POWERDOWN_EVENT_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.PowerDown_event_times);
		   }
	    }
	    else
	    {
		   Event_N.PowerDown_P=0;
	    }
	}
	else
	{
	   if(lowvoltflag==0)
	   {
		   Event_N.PowerDown_P++;		 
		   if(Event_N.PowerDown_P>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
		   {
		    Event_N.PowerDown_P=0;
		    
		    PrepEvent0Data(0x0001);
	      WRLC256(LASTPOWERDOWNEVENT_ROM+6L,&Co.b[300],6,0,0);
	      
		    Event_Power_Net_Flag.bit.PowerDownEvent=0;
		   }
	   }
	   else
	   {
		   Event_N.PowerDown_P=0;
	   }
	}
	
	
	EventCriticalVoltage_Flag=0;
	if((Event_Power_Net_Flag.bit.Phase3LostVolt!=0)||(Event_Power_Net_Flag.bit.PowerDownEvent!=0))
		EventCriticalVoltage_Flag=0xFF;
	
	int2ic |= 0x01;	
	FeedWatchdog();
	
}
//-------------------------- Phase3 Lost Volt Function  -----------------------//
//-------------------------- Over Demand Alarm Function -----------------------//
void OverDemandAlarmEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	
	int2ic &= 0xf8;
	if(Meter_Parameter.parameter1.UserClass[0]==2 || Meter_Parameter.parameter1.UserClass[0]==3)
  {
	   if(!Event_Power_Net_Flag.bit.OverPowerAlarm )
	   {
	      if(VoltageGreaterThanThreshold_Flag)
	      {	
	        if(((Last_Average_Value[0][0]>Meter_Parameter.event_parameter.PaADemandLimit*100l)||(Last_Average_Value[1][0]>Meter_Parameter.event_parameter.NeADemandLimit*100l)))
	        {
	        
	           *((unsigned long *)&Co.b[635])=Last_Average_Value[0][0];
	           *((unsigned long *)&Co.b[639])=Last_Average_Value[1][0];
			       Save_Event_StartData_Flash(&Event_Power_Net_Pointer.OverPowerAlarm_P,OVERPOWERALARM_P_ROM,
                                        OVERPOWERALARM_BEGINFILE,0,14,0x0201,
                                        (&Event_Power_Net_Times.OverPowerAlarm_Times),OVERPOWERALARM_TIMES_ROM);
			       Event_Power_Net_Flag.bit.OverPowerAlarm=1; 
	   	       
	   	       Output_On_3_In_1_Terminal_Set(5);
	   	       OverPowerAlarmTime=softdate;
	        }
	      }
	   }
	   else
	   {
	      if(((Last_Average_Value[0][0]<=Meter_Parameter.event_parameter.PaADemandLimit*100l)&&(Last_Average_Value[1][0]<=Meter_Parameter.event_parameter.NeADemandLimit*100l))
	      ||(!VoltageGreaterThanThreshold_Flag))
	      {
	        Save_Event_EndData_Flash(Event_Power_Net_Pointer.OverPowerAlarm_P,
                                   OVERPOWERALARM_BEGINFILE,14,6,0x0001,
                                   &Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,OVERPOWERALARM_TIMETICKS_ROM);			
		      Event_Power_Net_Flag.bit.OverPowerAlarm=0;
		      
	   	    Output_On_3_In_1_Terminal_Set(6);
	   	    OverPowerAlarmTime=softdate; 
	      }
	   }
	   
	   if(Meter_Parameter.parameter1.UserClass[0]==3)
	   {
	      FeedWatchdog();
	      if(Event_Power_Net_Flag.bit.OverPowerAlarm)
	      {
	          if(!OverPowerAlarmFlag)
	          {    
	              if(ComTime((unsigned char *)&softdate,(unsigned char *)&OverPowerAlarmTime)>Meter_Parameter.parameter2.OpenSwitchDelayTime*60l)
	              {
	              	   if(Meter_Parameter.parameter1.MeterMode[1].bit.b4)
	              	   {
	                      OverPowerAlarmFlag=0xff;
	                      Relay_Alarm_SWitch_Flag[1][0] |= 0x01;	//payment
				                Pre_Payment_Data.OverPowerSw_Time++;	//payment
	    			            *((unsigned long *)&Co.b[635])=Last_Average_Value[0][0];
	                      *((unsigned long *)&Co.b[639])=Last_Average_Value[1][0];
			                  Save_Event_StartData_Flash(&Event_Meter_Pro_Pointer.OverPowerCloseSwitch_P,OVERPOWERCLOSESWIT_P_ROM,
                                                   OVERPOWERSWIT_BEGINFILE,0,14,0x0201,
                                                   &Event_Meter_Pro_Times.OverPowerCloseSwitch_Times,OVERPOWERCLOSESWIT_TIMES_ROM);
	                   }
	              }
	          }
	      }
	      else
	      {
	          if(OverPowerAlarmFlag)
	          {
	              if((ComTime((unsigned char *)&softdate,(unsigned char *)&OverPowerAlarmTime)>Meter_Parameter.parameter2.CloseSwitchDelayTime*60l) 
	              ||(!VoltageGreaterThanThreshold_Flag))
	              {
	                   CloseOverPowerAlarmSwitch();
	              }
	          }
	      }
	   }
	   else
	   {
	      CloseOverPowerAlarmSwitch();
	   }
  }
  
  if(Meter_Parameter.parameter1.UserClass[0]==1)
	{
	    if(Event_Power_Net_Flag.bit.OverPowerAlarm)
	    {
	      ClearEvent_EventBegin((unsigned char *)&Event_Power_Net_Pointer.OverPowerAlarm_P, OVERPOWERALARM_BEGINFILE);/*"超功率报警事件清零判断处理"*/		  
	      Save_Event_EndData_Flash(Event_Power_Net_Pointer.OverPowerAlarm_P,
                                 OVERPOWERALARM_BEGINFILE,14,6,0x0001,
                                 &Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,OVERPOWERALARM_TIMETICKS_ROM);
		    Event_Power_Net_Flag.bit.OverPowerAlarm=0;
	   	  Output_On_3_In_1_Terminal_Set(6);
	   	  OverPowerAlarmTime=softdate;
	    } 
	    CloseOverPowerAlarmSwitch();
	}
	
	if(!Meter_Parameter.parameter1.MeterMode[1].bit.b4)
	{
	   CloseOverPowerAlarmSwitch();
	}
	
	int2ic |= 0x01;
	FeedWatchdog();
	
}

void CloseOverPowerAlarmSwitch(void)
{
	if(OverPowerAlarmFlag)
	{  
	   OverPowerAlarmFlag=0; 
	   Relay_Alarm_SWitch_Flag[1][0] &= 0xFE;	//payment
	}
}

//-------------------------- Over Demand Alarm Function -----------------------//
//-------------------------- Clock Battery Event Function ---------------------//
/*"==========================================================================="*/
/*"Function Name:时钟电池低功耗电池欠压事件记录                                    "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03       reduced 216byte                                                       "*/
/*"DESCRIPTION:将两个整成一项，节省空间                                                     "*/
/*"und=0为时钟电池欠压事件**und=1为低功耗电池欠压事件记录     "*/
/*"offset/offset1为电池欠压状态标志在相应结构中的偏移位置          "*/
/*"==========================================================================="*/
void ClockBatteryDisplayBattery_Event(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[2]= {0x02,0x04};	
  unsigned char offset1[2]= {0x04,0x01};	
		
	FeedWatchdog();

	for(und=0;und<2;und++)
	{
		if((Event_Power_Net_Flag.byte[4]&offset[und])==0)
		{
			if((Alarm_Map_Flag[0].byte&offset1[und])!=0) 
			{
		     Save_Event_StartData_Flash((((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und)),(CLOCKBATTERYEVENT_P_ROM+und),
                                    (CLOCKBATTERYEVENT_BEGINFILE+32L*und),0,6,0x0001,
                                    ((unsigned long *)&Event_Power_Net_Times.ClockBatteryEvent_Times+und),(CLOCKBATTERYEVENT_TIMES_ROM+und*4L));
			   Event_Power_Net_Flag.byte[4]|=offset[und];  //==1
			}
		}
		else
		{
			if((Alarm_Map_Flag[0].byte&offset1[und])==0)
			{
		    if((*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und))>31)
		    	(*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und))=0;
		    uni=CLOCKBATTERYEVENT_BEGINFILE+32L*und+(*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und));
		    PrepEvent0Data(0x0001);
		    Write_File(uni,6,6,&Co.b[300]);
			  Event_Power_Net_Flag.byte[4]&=(~offset[und]);  //  =0
			  if(und==1)
			  {
				  Other_Data.BatteryWorkTime1=0;
				  WRLC256(BATTERYWORKTIME1_ROM,(unsigned char *)&Other_Data.BatteryWorkTime1,4,0,0);	
			  }
			}
		}
		FeedWatchdog();
	}
	
}
//-------------------------- Clock Battery Event Function ---------------------//
//-------------------------- Display Battery Event Function  ------------------//
//-------------------------- Display Battery Event Function  ------------------//
//-------------------------- Adjust Meter Event Function  ---------------------//
void AdjustMeterRecord(void)
{
	unsigned char unc;
	
	if((Event_Power_Net_Flag.bit.AdjustMeterEvent==0)&&(JustMeterFlag==0xFF))
	{
		for(unc=0;unc<5;unc++)
	    Co.b[400+unc]=*((unsigned char *)&JustMeterDateFlag+unc);
	  Co.b[405]=JustMeterDataFlag.byte;
	  
		Save_Record_Data_Flash(&Event_Power_Net_Pointer.AdjustMeterEvent_P,ADJUSTMETEREVENT_P_ROM,
                            ADJUSTMETERRECORD_BEGINFILE,6,
                            &Event_Power_Net_Times.AdjustMeterEvent_Times,ADJUSTMETEREVENT_TIMES_ROM);
	  Event_Power_Net_Flag.bit.AdjustMeterEvent=1;
	}
}

void AdjustMeterRecordEndCheck(void){
	
	if(Event_Power_Net_Flag.bit.AdjustMeterEvent==1){
		
		if(ComTime((unsigned char *)&softdate,(unsigned char *)&JustMeterDateFlag)>300){
			JustMeterFlag=0;
	    JustMeterDataFlag.byte=0;
	    Event_Power_Net_Flag.bit.AdjustMeterEvent=0;
		}
		
	}
	
}
//-------------------------- Adjust Meter Event Function  ---------------------//
//-------------------------- Prepare VoltStat ReadData    ---------------------//
int  PrepVoltStatReadData(void){
	unsigned char unc;
	unsigned long tempunl;
	unsigned long tempunl0;
	unsigned long tempunl1;
	unsigned char *tempuncpointer0;
	unsigned char *tempuncpointer1;
	
	for(unc=0;unc<4;unc++){
		
		if(unc<3)
		{
			tempunl1=VoltStat[unc].checktime[1]+VoltStat[unc].checktime[2]+VoltStat[unc].checktime[3];
			tempunl0=VoltStat[unc].checktime[2]+VoltStat[unc].checktime[3];
			tempuncpointer0=(unsigned char *)&VoltStat[unc].voltratebcd[1];
			tempuncpointer1=(unsigned char *)&VoltStat[unc].voltratebcd[0];
		}
		else
		{
			tempunl1=VoltStat[unc].checktime[0];
			tempunl0=VoltStat[unc].checktime[1];
			tempuncpointer0=(unsigned char *)&VoltStat[unc].voltratebcd[0];
			tempuncpointer1=(unsigned char *)&VoltStat[unc].voltratebcd[1];
		}
		
		if(tempunl1!=0){
			tempunl=(tempunl0*10000l)/tempunl1;
			tempunl0=(tempunl0*10000l)%tempunl1;
			tempunl0=(tempunl0*10l)/tempunl1;
			if(tempunl0>=5)
				tempunl++;
			HexToBcd(3,(unsigned char *)&tempunl,tempuncpointer0);
			if(tempunl<=10000l){
				tempunl=10000l-tempunl;
				HexToBcd(3,(unsigned char *)&tempunl,tempuncpointer1);
			}
			else{
				VoltStat[unc].voltratebcd[0]=0xFFFFFFFF;
			  VoltStat[unc].voltratebcd[1]=0xFFFFFFFF;
			}	
		}
		else{
			VoltStat[unc].voltratebcd[0]=0xFFFFFFFF;
			VoltStat[unc].voltratebcd[1]=0xFFFFFFFF;
		}
		
		if(VoltStat[unc].checkvolt[0]==0xFFFFFFFF){
			VoltStat[unc].checkvoltbcd[0]=0xFFFF;
		}
		else{
			tempunl=VoltStat[unc].checkvolt[0]/1000l;
			HexToBcd(2,(unsigned char *)&tempunl,(unsigned char *)&VoltStat[unc].checkvoltbcd[0]);
		}
		if(VoltStat[unc].checkvolt[1]==0xFFFFFFFF){
			VoltStat[unc].checkvoltbcd[1]=0xFFFF;
		}
		else{
			tempunl=VoltStat[unc].checkvolt[1]/1000l;
			HexToBcd(2,(unsigned char *)&tempunl,(unsigned char *)&VoltStat[unc].checkvoltbcd[1]);
		}
	}
	return  0;
}
//-------------------------- Prepare VoltStat ReadData    ----------------------//
//-------------------------- ResetCpuEvent -------------------------------------//
void ResetCpuEvent_OnCheck(void)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ResetCPU_P,RESETCPU_P_ROM,
                         RESETCPUEVENT_BEGINFILE,6,
                         &Event_Meter_Pro_Times.ResetCPU_Times,RESETCPU_TIMES_ROM);
	
}
//-------------------------- ResetCpuEvent -------------------------------------//
//-------------------------- RunClockErrorEvent --------------------------------//
void RunClockErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.RunClockError_P,RUNCLOCKERROR_P_ROM,
                         RUNCLOCKERR_BEGINFILE,sizeof(struct RUNCLOCKERROR_DATA),
                         &Event_Meter_Pro_Times.RunClockError_Times,RUNCLOCKERROR_TIMES_ROM);

 if(Meter_Parameter.parameter1.EventReportMode.byte[0] & 0x80)   
    {
    if(!EventStatus_flag.bit.Clock_err )
    {
     EventReportState_Expand(3, 4, 0);  
     if(Event_Report_Status_Times.Clock_err_times !=255)
     {
       Event_Report_Status_Times.Clock_err_times =255;
       Save_EventReportTimes(CLOCK_ERR_TIMES_ROM ,(unsigned char *)&Event_Report_Status_Times.Clock_err_times);
     }
    }
    }
}
//-------------------------- RunClockErrorEvent --------------------------------//
//-------------------------- PowerUpClockErrorEvent ----------------------------//
void PowerUpClockErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.PowerUpClockError_P,POWERUPCLOCKERROR_P_ROM,
                         POWERUPCLOCKERR_BEGINFILE,sizeof(struct POWERUPCLOCKERROR_DATA),
                         &Event_Meter_Pro_Times.PowerUpClockError_Times,POWERUPCLOCKERROR_TIMES_ROM);
	
}
//-------------------------- PowerUpClockErrorEvent ----------------------------//
//-------------------------- EepromErrorEvent ----------------------------------//
void EepromErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&softdate+unc);
	Co.b[405]=Eeprom_Flag.byte;
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.EepromErr_P,EEPROMERR_P_ROM,
                         EEPROMERR_BEGINFILE,sizeof(struct EEPROMERR_DATA),
                         &Event_Meter_Pro_Times.EepromErr_Times,EEPROMERR_TIMES_ROM);
	
}
//-------------------------- EepromErrorEvent ----------------------------------//
//-------------------------- EnergyPassZeroEvent -------------------------------//
void EnergyPassZeroRecord(void)
{
	
	FeedWatchdog();
	
	ClearEvent_EventBegin((unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P
	,FREEZE_ENERGYPASSZERO_START_FILE);/*"冻结清零判断处理"*/
	
	if(Event_Meter_Pro_Pointer.Energypasszero_P>15)
		Event_Meter_Pro_Pointer.Energypasszero_P=0;
		
	FreezeDateProgram(FREEZE_ENERGYPASSZERO_START_FILE+Event_Meter_Pro_Pointer.Energypasszero_P,1, (unsigned char *)&softdate);///king chen modify 130609
       
	if(Event_Meter_Pro_Pointer.Energypasszero_P<=14)
		Event_Meter_Pro_Pointer.Energypasszero_P++;
	else
		Event_Meter_Pro_Pointer.Energypasszero_P=0;
	
	Save_EventTimesANDPointer_4byte(ENERGYPASSZERO_P_ROM,ENERGYPASSZERO_TIMES_ROM,
	((unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P),
	(&Event_Meter_Pro_Times.Energypasszero_Times));  	
	
	FeedWatchdog();
}
//-------------------------- EnergyPassZeroEvent -------------------------------//
//-------------------------- CurrVoltImBalanceEvent  -------------------------------//
/*"================================================================="*/
/*"Function Name:电压电流不平衡事件记录                                       "*/
/*"Author:	PC            Modifier:mw   Date:2009-09-03       reduced 688byte               "*/
/*"DESCRIPTION:将电压电流不平衡整成一项，节省空间         "*/
/*"und=0为电流不平衡****und=1为电压不平衡事件记录          "*/
/*"offset为不平衡状态标志在相应结构中的偏移位置          "*/
/*"================================================================*"*/
void CurrVoltImBalance_Event(void)
{
	unsigned char und;
	unsigned char eventflag;
	unsigned char offset;
	unsigned char *judgeimbalancedelay;
	unsigned char *eventfilenameoffset;
	unsigned int  eventfilenameoffsetaddr;
	unsigned int  eventfilename;
	unsigned long *imbalanceeventtimes;
	unsigned int  imbalanceeventtimesaddr;
	unsigned long *imbalanceeventtimeticks;
	unsigned int  imbalanceeventtimeticksaddr;
	unsigned long judgeimbalancerate;
	unsigned char judgeimbalancetime;
	unsigned long tempimbalancerate;
	unsigned long tempmaxvalue;
	unsigned long tempminvalue;

       unsigned char eventreportflag;
       
  for(und=0;und<3;und++)
  {
    int2ic &= 0xf8;
    
    switch(und)
    {
    	case 0:
    	  eventflag=2;
    	  offset=0x40;
    	  eventreportflag=1;
          
    	  judgeimbalancedelay=&Event_N.CurrImBalanceEvent_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.CurrImBalanceEvent_P;
    	  eventfilenameoffsetaddr=CURRIMBALANCEEVENT_P_ROM;
    	  
    	  eventfilename=CURRIMBALANCEEVENT_BEGINFILE;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.CurrImBalanceEvent_Times;
    	  imbalanceeventtimesaddr=CURRIMBALANCEEVENT_TIMES_ROM;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks;
    	  imbalanceeventtimeticksaddr=CURRIMBEVENT_TIMETICKS_ROM;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeCurrImBalanceN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeCurrImBalanceT;
    	  
    	  tempmaxvalue=eventmaxcurr;
    	  tempminvalue=eventmincurr;
    	break;
    	
    	case 1:
    	  eventflag=2;
    	  offset=0x80;
         eventreportflag=0;
         
    	  judgeimbalancedelay=&Event_N.VoltImBalanceEvent_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.VoltImBalanceEvent_P;
    	  eventfilenameoffsetaddr=VOLTIMBALANCEEVENT_P_ROM;
    	  
    	  eventfilename=VOLTIMBALANCEEVENT_BEGINFILE;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.VoltImBalanceEvent_Times;
    	  imbalanceeventtimesaddr=VOLTIMBALANCEEVENT_TIMES_ROM;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.VoltImBalanceEvent_Times_Ticks;
    	  imbalanceeventtimeticksaddr=VOLTIMBEVENT_TIMETICKS_ROM;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeVoltImBalanceN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeVoltImBalanceT;
    	  
    	  tempmaxvalue=eventmaxvolt;
    	  tempminvalue=eventminvolt;
    	break;
    	
    	default:
    	  eventflag=5;
    	  offset=0x04;
    	  eventreportflag=6;
          
    	  judgeimbalancedelay=&Event_N.CurrFarImB_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.CurrFarImB_P;
    	  eventfilenameoffsetaddr=CURRFARIMB_P_ROM;
    	  
    	  eventfilename=CURRFARIMBALANCE_BEGINFILE;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.CurrFarImB_Times;
    	  imbalanceeventtimesaddr=CURRFARIMB_TIMES_ROM;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks;
    	  imbalanceeventtimeticksaddr=CURRFARIMB_TIMETICKS_ROM;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeCurrFarImBN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeCurrFarImBT;
    	  
    	  tempmaxvalue=eventmaxcurr;
    	  tempminvalue=eventmincurr;
    	break;
    }
    
    tempimbalancerate=0;
    if((tempmaxvalue!=0)&&(tempmaxvalue>tempminvalue))
    {
     	if(((und==1)&&(tempmaxvalue*100l>Meter_Parameter.event_parameter.CriticalVoltage*EventUn))
     	||((und!=1)&&((tempmaxvalue*100l)>=(EventIb*5))))
     	{
  	   tempminvalue=(tempmaxvalue-tempminvalue)*100l;
  	   tempimbalancerate=tempminvalue/tempmaxvalue;
  	   tempminvalue=tempminvalue%tempmaxvalue;
  	   tempminvalue=(tempminvalue*100l)/tempmaxvalue;
  	   tempimbalancerate=tempimbalancerate*100l+tempminvalue;
  	  }
    }  
  
    if((Event_Power_Net_Flag.byte[eventflag]&offset)==0)
	  {
	    if((judgeimbalancerate!=0)&&(tempimbalancerate>=judgeimbalancerate))
	    {
			  (*judgeimbalancedelay)++;
			  if((*judgeimbalancedelay)>=judgeimbalancetime)
		   	{
				  (*judgeimbalancedelay)=0;
				  
				  Save_Event_StartData_Flash(eventfilenameoffset,eventfilenameoffsetaddr,
                                     eventfilename,0,102,0x000D,
                                     imbalanceeventtimes,imbalanceeventtimesaddr);
				  
				  maximbalancerate[und]=tempimbalancerate;
				  savemaximbalancerate[und]=maximbalancerate[und];
          WRLC256(MAXCURRIMBALANCERATE_ROM+und*4L,(unsigned char *)&savemaximbalancerate[und],4,0,0);
					
				  Event_Power_Net_Flag.byte[eventflag]|=offset;  //==1
                  		if(((Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x04) &&(0==eventreportflag))
                            ||((Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x08)&&(1==eventreportflag))
                            ||((Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x01)&&(6==eventreportflag)))
				  Save_EventReportTimes((VOLTIMBALANCE_TIMES_ROM+eventreportflag),((unsigned char *)&Event_Report_Status_Times.VoltImbalance_times+eventreportflag));
		    }
	    }
	    else
	    { 
			   (*judgeimbalancedelay)=0;
		  }
	  }
	  else
	  {
	   if((judgeimbalancerate==0)||(tempimbalancerate<judgeimbalancerate))
	   {
			 (*judgeimbalancedelay)++;
			 if((judgeimbalancerate==0)||((*judgeimbalancedelay)>=judgeimbalancetime))
			 {
				 (*judgeimbalancedelay)=0;
				 
				 *((unsigned long *)&Co.b[606])=maximbalancerate[und];
				 Save_Event_EndData_Flash((*eventfilenameoffset),
                                  eventfilename,102,106,0x001D,
                                  imbalanceeventtimeticks,imbalanceeventtimeticksaddr);				
				 
				 Event_Power_Net_Flag.byte[eventflag]&=(~offset);  //  =0
			 }
	   }
	   else
	   {
		    (*judgeimbalancedelay)=0;
		    
		    if(maximbalancerate[und]<tempimbalancerate)
		      maximbalancerate[und]=tempimbalancerate;
	   }
	 }
	 FeedWatchdog();
	 int2ic|=0x01;	
 }
  
}


void Check_Max_Imbalance_Rate(void)
{
   unsigned char und;
   unsigned char eventflag[3]={2,2,5};
	 unsigned char offset[3]={0x40,0x80,0x04};
   
   for(und=0;und<3;und++)
   {
     if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])!=0)
	   {
       if(savemaximbalancerate[und]<maximbalancerate[und])
	     {
		      savemaximbalancerate[und]=maximbalancerate[und];
          WRLC256(MAXCURRIMBALANCERATE_ROM+und*4L,(unsigned char *)&savemaximbalancerate[und],4,0,0);
          FeedWatchdog();
	     }
	   }
   }
   
}

//-------------------------- SetPrimaryEvent -----------------------------------//
void SetPrimaryRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[300+unc]=*((unsigned char *)&softdate+unc);
	
  Save_Event_StartData_Flash(&Event_Meter_Pro_Pointer.SetPrimary_P,SETPRIMARY_P_ROM,
                             SETPRIMARYRECORD_BEGINFILE,0,sizeof(struct SETPRIMARY_DATA),0x0000,
                             &Event_Meter_Pro_Times.SetPrimary_Times,SETPRIMARY_TIMES_ROM);
                     
}
//-------------------------- SetPrimaryEvent ------------------------------------//
//-------------------------- Eeprom Event SetDefault  ---------------------------//
void EepromEventSetDefault(void)
{
	FeedWatchdog();
	WRLC256(LASTLOSTVOLT_A_ROM, 0,  ((VOLTSTATISTICDATA_A_ROM) -(LASTLOSTVOLT_A_ROM)), 0, 0);
	FeedWatchdog();
}
//-------------------------- Eeprom Event SetDefault  ----------------------------//

//-------------------------PrepFirstEventDataNew----------------------//
unsigned char PrepLostVoltFirstEventData(unsigned int eventaddr,unsigned char eventaddrkind,
                                         unsigned char eventamphourkind,unsigned char eventbeginflag){
   unsigned char unc;
   
   if(eventaddrkind==0){
  	 WRLC256(eventaddr,&TempEventData[0],255,0,1);
   }
   else{
   		if(IntoPowerDownFlag)
   		{
   			Show_ID_vatiy=0xFF;
			return 0;
   		}//mw modified 2011-07-26
     		Read_File(eventaddr,0,255,&TempEventData[0]);
   }
   if(eventbeginflag!=0){
   	 SaveEvent0EndAmpHour(eventamphourkind);
		 PrepEvent0Data(0x004D);
		 for(unc=0;unc<6;unc++)
		   Co.b[300+unc]=0;
		 for(unc=0;unc<96;unc++)
		   Co.b[306+unc]=0xFF;
		 for(unc=0;unc<114;unc++)
		   TempEventData[141+unc]=Co.b[300+unc];
   }
   return 0xFF;
}

unsigned char PrepNewFirstEventData(unsigned long eventcode)
{
   unsigned char unc;
   unsigned char result;
   unsigned int uni;
   union ID id;
   
   result=0xff;
   id.l=eventcode;
   eventcode=eventcode&0xFFFF00FF;
   
   if((id.d[3]>=0x10)&&(id.d[1]==0))
   {
   	 return 0;
   }
   
   switch(eventcode)
   {
   	 case 0x10010001:
   	 case 0x10020001:
   	 case 0x10030001:
   	  PrepLostVoltFirstEventData(LASTLOSTVOLT_A_ROM+((unsigned int)255)*(id.d[2]-1),0,(id.d[2]-1),((Event_Power_Net_Flag.byte[0]>>(id.d[2]-1))&0x01));
   	 break;//A B C Lost Viltage
   	 
   	 case 0x13010001:
   	 case 0x13020001:
   	 case 0x13030001:
   	  uni=BREAKPHASE_A_BEGINFILE+32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.BreakPhase_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+8),((Event_Power_Net_Flag.byte[1]>>(id.d[2]-1))&0x01));
   	 break;//A B C Break Phase
   	 
   	 case 0x12010001:
   	 case 0x12020001:
   	 case 0x12030001:
   	  uni=OVERVOLT_A_BEGINFILE+32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.OverVoltage_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+5),((Event_Power_Net_Flag.byte[2]>>(id.d[2]+2))&0x01));
   	 break;//A B C Over Voltage
   	 
   	 case 0x11010001:
   	 case 0x11020001:
   	 case 0x11030001:
   	  uni=VOLTDOWN_A_BEGINFILE+32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.VoltageDown_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+2),((Event_Power_Net_Flag.byte[1]>>(id.d[2]+2))&0x01));
   	 break;//A B C Down Voltage
   	 
   	 case 0x16000001:
   	 case 0x17000001:
   	  if(IntoPowerDownFlag)
			{
				Show_ID_vatiy=0xFF;
				return 0;
			}
   	  
		  uni=CURRIMBALANCEEVENT_BEGINFILE+32*(1-(id.d[3]-0x16))+(*(&Event_Power_Net_Pointer.CurrImBalanceEvent_P+(1-(id.d[3]-0x16))))%32;	  
		  Read_File(uni,0,208,&TempEventData[0]);
			if(((Event_Power_Net_Flag.byte[2]>>(7-(id.d[3]-0x16)))&0x01)!=0)
			{
				 for(unc=0;unc<102;unc++)
				 {
			    TempEventData[102+unc]=0;
			   }
				 *((unsigned long *)&TempEventData[204])=maximbalancerate[(1-(id.d[3]-0x16))];
			}
		  
   	 break;//Volt Curr Imbalance
   	 
   	 case 0x20000001:
   	  if(IntoPowerDownFlag)
			{
				Show_ID_vatiy=0xFF;
				return 0;
			}
   	  
		  uni=CURRFARIMBALANCE_BEGINFILE+Event_Power_Net_Pointer.CurrFarImB_P%32;	  
		  Read_File(uni,0,208,&TempEventData[0]);
			if(Event_Power_Net_Flag.bit.CurrFarImB)
			{
				  for(unc=0;unc<102;unc++)
				  {
			      TempEventData[102+unc]=0;
			    }
				  *((unsigned long *)&TempEventData[204])=maximbalancerate[2];
			}
   	 break;//Curr Far Imbalance
   	 
   	 case 0x03120001:
		  if((id.l>=0x03120101)&&(id.l<=0x03120601))
		  {
		  	if(IntoPowerDownFlag)
			  {
				  Show_ID_vatiy=0xFF;
				  return 0;
			  }
			  PrepOverDemandFirstEventData(id.l);
		  }
		  else
		  {
		  	 result=0;
		  }
   	 break;//Over Demand
   	 
   	 case 0x03050001:
   	  WRLC256(LASTPHASE3LOSTVOLT_ROM,&TempEventData[0],16,0,1);
   	  if(Event_Power_Net_Flag.bit.Phase3LostVolt)
   	  {
   	  	for(unc=0;unc<6;unc++)
   	  	  TempEventData[10+unc]=0;
   	  }
   	 break;//Phase 3 Lost Volt
   	 
   	 case 0x03110001:
   	  WRLC256(LASTPOWERDOWNEVENT_ROM,&TempEventData[0],12,0,1);
   	  if(Event_Power_Net_Flag.bit.PowerDownEvent)
   	  {
   	  	for(unc=0;unc<6;unc++)
   	  	  TempEventData[6+unc]=0;
   	  }
   	 break;//Power Down
   	 
   	 case 0x03300001:
   	  switch(id.d[1])
   	  {
   	  	case 0x00:
   	  	 WRLC256(LASTPROGRAMME_ROM,&TempEventData[0],50,0,1);
   	  	break;//Programe
   	  	
   	  	case 0x0d:
   	  	case 0x0e:
   	  	 WRLC256(LASTOPENCOVEREVENT_ROM+60*(id.d[1]-0x0d),&TempEventData[0],60,0,1);
   	     if(((Event_Power_Net_Flag.byte[3]>>(6+(id.d[1]-0x0d)))&0x01)!=0)
   	     {
   	  	   for(unc=0;unc<30;unc++)
   	  	    TempEventData[30+unc]=0;
   	     }
   	  	break;//Open Cover Box
   	  	
   	  	default:
   	  	 result=0;
   	  	break;
   	  }
   	 break;
   	 
   	 case 0x03360001:
   	  if(STATUS_RELAYERR_DEFINE)
		  {
		    WRLC256(RELAYERR_AREA_EE,&TempEventData[0],21,0,1);
		    for(unc=0;unc<6;unc++)
		      TempEventData[6+unc]=0;
		    for(unc=0;unc<8;unc++)
		      TempEventData[21+unc]=0;
		  }
		  else
		  {
		  	result=0;
		  }
   	 break;//payment
   	 
   	 default:
   	  result=0;
   	 break;
   }
   
   if((Show_ID_vatiy==0xFF)&&(IntoPowerDownFlag))
   {
			result=0;
   }
   
   return result;
}
//-------------------------PrepFirstEventDataNew----------------------//
//-------------------------- PowerDown Save Current  ------------------------------//
 /*
 void PowerDownSaveMaxCurr(void){
	unsigned char unc=0;
	unsigned long MaxCurr=0;
	signed long SiMaxCurr=0;
	unsigned long AvgSiCurr=0;
	
	FeedWatchdog();
	MaxCurr=Curr[0];
	SiMaxCurr=COMM_Curr[0];
	if(V_REGION==1 || V_REGION==2)
  {
     for(unc=0;unc<=1;unc++)
     {
        if(MaxCurr<Curr[unc+1]){
          MaxCurr=Curr[unc+1];
          SiMaxCurr=COMM_Curr[unc+1];
        }
     }
     AvgSiCurr=(Curr[0]+Curr[1]+Curr[2])/3l;     
  }
  else
  {
     if(MaxCurr<Curr[2]){
        MaxCurr=Curr[2];
        SiMaxCurr=COMM_Curr[2];
      }
      AvgSiCurr=(Curr[0]+Curr[2])/2l; 
  }
  *((unsigned long *)&TempEventData[0])=AvgSiCurr;
  *((unsigned long *)&TempEventData[4])=MaxCurr;
  WRLC256(POWERDOWNSAVEMAXCURR_ROM,&TempEventData[0],8,3,0);
	return;
 }
 */
//-------------------------- PowerDown Save Current  ------------------------------//
//-------------------------- AdjustTime OverT -------------------------------------//
void EMeterPowerdownRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	{
		  Co.b[400+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		  Co.b[406+unc]=*((unsigned char *)&softdate+unc);
  }
	if((CheckTime(&Co.b[400])!=0xff))
	{
	  for(unc=0;unc<6;unc++)
		  Co.b[400+unc]=0xff;
	}
	
	CheckPowerDown();
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.AdjustTimeOverT_P,ADJUSTTIMEOVERT_P_ROM,
                         ADJUSTTIMEOVERTRECORD_BEGINFILE,12,
                         &Event_Meter_Pro_Times.AdjustTimeOverT_Times,ADJUSTTIMEOVERT_TIMES_ROM);
	
}
//-------------------------- AdjustTime OverT -------------------------------------//
//-------------------------- VoltageDown Event -------------------------------------//
/*"reduced 624byte,mw modified 2009-09-03"*/
void VoltageDownEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	
	
	//---------- A Phase /B Phase/C Phase----------//
	for(und=0;und<3;und++)
	{
	  if((V_REGION==0 || V_REGION==3)&&(und==1))
	  {			
		  continue;
	  }
	  
	  int2ic&=0xf8;
	  
	  if((Event_Power_Net_Flag.byte[1]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeVoltDown_V!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeVoltDown_V*1000l))
	    {
	   	   
	   	   (*((unsigned char *)&Event_N.VoltageDown_A_P+und))++;
	   	   	 
	   	   if((*((unsigned char *)&Event_N.VoltageDown_A_P+und))>=Meter_Parameter.event_parameter.JudgeVoltDownT)
	   	   {
	   	 	    (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
			      
		        Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P+und),(VOLTAGEDOWN_A_P_ROM+und),
                                       (VOLTDOWN_A_BEGINFILE+und*32L),0,141,0x002D,
                                       ((unsigned long *)&Event_Power_Net_Times.VoltageDown_A_Times+und),(VOLTAGEDOWN_A_TIMES_ROM+und*4L));
		        SaveEvent0BeginAmpHour(3+und);
		        Event_Power_Net_Flag.byte[1]|=offset[und];
		        if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x02)  
		        Save_EventReportTimes((LOWTVOLT_A_TIMES_ROM+und*16), ((unsigned char *)&Event_Report_Status_Times.LowVolt_A_times+und*16));
	   	   }
	   }
	   else
	   {
			  (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
	   }
	 }
	 else
	 {
	   if((Volt[und]>=Meter_Parameter.event_parameter.JudgeVoltDown_V*1000l)||(Meter_Parameter.event_parameter.JudgeVoltDown_V==0))
	   {
		   	
		   (*((unsigned char *)&Event_N.VoltageDown_A_P+und))++;
		   		 	
	   	 if(((*((unsigned char *)&Event_N.VoltageDown_A_P+und))>=Meter_Parameter.event_parameter.JudgeVoltDownT)
	   	 ||(Meter_Parameter.event_parameter.JudgeVoltDown_V==0))
	   	 {
	   	    (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
	   	    
				  SaveEvent0EndAmpHour(3+und);			  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P+und)),
                                   (VOLTDOWN_A_BEGINFILE+und*32L),141,114,0x004D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks+und),(VOLTAGEDOWN_A_TIMETICKS_ROM+und*4L));
		      Event_Power_Net_Flag.byte[1]&=(~offset[und]); 
	   	 }
	   }
	   else
	   {
	   	 (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;	
	   }
	 }
	 int2ic|=0x01;
	 FeedWatchdog();
	}
	
}
//-------------------------- VoltageDown Event -------------------------------------//

//-------------------------- OverCurrent Event -------------------------------------//
//reduced 624byte ,mw modified 2009-09-03
void OverCurrentEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
	//------  A /B/C Phase  ------//
	for(und=0;und<3;und++)
	{
	  if((V_REGION==0 || V_REGION==3)&&(und==1))
	  {			
		  continue;  //331 B Phase not include
	  }
	  
	  int2ic&=0xf8;
	  
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)
	  {
	   if((Meter_Parameter.event_parameter.JudgeOverCurrentI!=0)&&(Curr[und]>Meter_Parameter.event_parameter.JudgeOverCurrentI*1000l))
	   {
			 (*((unsigned char *)&Event_N.OverCurrent_A_P+und))++;
		   if((*((unsigned char *)&Event_N.OverCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverCurrentT)
		   {
		      *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
		      
		      Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P+und),(OVERCURRENT_A_P_ROM+und),
                                     (OVERCURR_A_BEGINFILE+und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.OverCurrent_A_Times+und),(OVERCURRENT_A_TIMES_ROM+und*4L));
		      Event_Power_Net_Flag.byte[3]|=offset[und];  //==1
		      if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x10)   
		      Save_EventReportTimes((OVERCURR_A_TIMES_ROM+und*16), ((unsigned char *)&Event_Report_Status_Times.OverCurr_A_times+und*16));
		   }
	   }
	   else
	   {
			*((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
	   }
	 }
	 else
	 {
	   if((Curr[und]<=Meter_Parameter.event_parameter.JudgeOverCurrentI*1000l)||(Meter_Parameter.event_parameter.JudgeOverCurrentI==0))
	   {	
			 (*((unsigned char *)&Event_N.OverCurrent_A_P+und))++;
			 
		   if(((*((unsigned char *)&Event_N.OverCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverCurrentT)
		   ||(Meter_Parameter.event_parameter.JudgeOverCurrentI==0))
		   {
		      *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
		      				  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P+und)),
                                   (OVERCURR_A_BEGINFILE+und*32L),141,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks+und),(OVERCURRENT_A_TIMETICKS_ROM+und*4L));
          Event_Power_Net_Flag.byte[3]&=(~offset[und]);
		   }
	   }
	   else
	   {
		   *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;	
	   }
	  }
    int2ic|=0x01;
	  FeedWatchdog();
	}
	
}
//-------------------------- OverCurrent Event -------------------------------------//
//-------------------------- LostVoltage Statistic ---------------------------------//
void SaveLostVoltTime(unsigned int tempeepromaddr,unsigned char savetimekind){
	unsigned char unc=0;
	unsigned char tempdate[6];
	
	if(savetimekind==0xFF){
	  for(unc=0;unc<=5;unc++)
	    tempdate[unc]=*((unsigned char *)&softdate+unc);
	}
	else{
		for(unc=0;unc<=5;unc++)
	    tempdate[unc]=0xFF;
	}
	WRLC256(tempeepromaddr,&tempdate[0],6,0,0);
	
}
 
void LostVoltEnergyAdd(unsigned int eventeepromaddr,unsigned char storekind)
{
	unsigned char tempunc=0;
	unsigned int tempuni=0,tempunj=0,tempunk=0;
	unsigned long tempunl=0,tempdata0=0;

  if(eventeepromaddr==LOSTVOLTENERGY_A_ROM)
  {
      WRLC256(LASTLOSTVOLT_A_ROM+6,(unsigned char*)&lostvoltenergy[0],8,0,1);
      tempunj=0;            
  }
  else  if(eventeepromaddr==LOSTVOLTENERGY_B_ROM)
  {
      WRLC256(LASTLOSTVOLT_B_ROM+6,(unsigned char*)&lostvoltenergy[2],8,0,1);
      tempunj=2;
  }
  else  if(eventeepromaddr==LOSTVOLTENERGY_C_ROM)
  {
      WRLC256(LASTLOSTVOLT_C_ROM+6,(unsigned char*)&lostvoltenergy[4],8,0,1);
      tempunj=4;
  }
  else
     return ;
       
  for(tempuni=0;tempuni<=1;tempuni++)
  {
     tempunk=tempunj+tempuni;
     
	   tempdata0=(*((unsigned long *)&This_Month_Data.Energy_Record+tempuni*MAXTRIFF));
	   if(tempdata0>=lostvoltenergy[tempunk])
	   {
		     lostvoltenergy[tempunk]=tempdata0-lostvoltenergy[tempunk];
		 }
	   else
	   {
		     WRLC256(LOSTVOLTAGETIME+tempunj,(unsigned char*)&lostvoltagetime[tempunj/2][0],2,0,1);
		     if(lostvoltagetime[tempunj/2][tempuni]<This_Month_Data.Energy_Record.EnergyPassMAXTimes[tempuni])  //protect not energy pass zero
		        lostvoltenergy[tempunk]= 999999999l-lostvoltenergy[tempunk]+tempdata0+1;
		 }
		 
		 tempunc=WRLC256(eventeepromaddr+tempuni*4,(unsigned char *)&tempunl,4,0,1);
		 if(tempunc==0xFF)
		 {
				lostvoltenergy[tempunk]=tempunl+lostvoltenergy[tempunk];
				if(lostvoltenergy[tempunk]>999999999l)
					 lostvoltenergy[tempunk]=lostvoltenergy[tempunk]-999999999l;
        if(storekind ==0xff)
				   WRLC256(eventeepromaddr+tempuni*4,(unsigned char *)&lostvoltenergy[tempunk],4,0,0);
		 }
	}  
	
}
 
int  PrepLostVoltEnergyData(unsigned long eventcode)
{
	unsigned char unc=0;
	unsigned char eventflag=0;
	unsigned int uni=0;
	unsigned int unj=0;
  
	if((eventcode==0x10010003)||(eventcode==0x10010004))
	{
		unc=0;
		uni=LOSTVOLTENERGY_A_ROM;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x01);
	}
	else if((eventcode==0x10020003)||(eventcode==0x10020004))
	{
		unc=1;
		uni=LOSTVOLTENERGY_B_ROM;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x02);
	}
	else if((eventcode==0x10030003)||(eventcode==0x10030004))
	{
		unc=2;
		uni=LOSTVOLTENERGY_C_ROM;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x04);
	}
	else
	{
	  return -1;
  }
  
  if(unc<3)
  {
  	if(eventflag!=0)
  	{
      LostVoltEnergyAdd(LOSTVOLTENERGY_A_ROM+(unc*8l),0);
    }
    else
    {
	     WRLC256(uni,(unsigned char *)&lostvoltenergy[unc*2],8,0,1);  
    }

    return 0;
  }
  
  return -1;	
}
 
//-------------------------- LostVoltage Statistic ---------------------------------//
//-------------------------- UpLoad Event ---------------------------------//
//reduced 520byte ,mw modified 2009-09-03
void UpLoadEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned long judgeuploadn;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	
	
	//------  A /B/C Phase  ------//
	judgeuploadn=Meter_Parameter.event_parameter.JudgeUpLoadP*100l;
	for(und=0;und<3;und++)
	{
	  if((V_REGION==0 || V_REGION==3)&&(und==1))
	  {			
		  continue;//  331 B  Phase is not include 
	  }
	  
	  int2ic &= 0xf8;
	  
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)
	  {
	   if((Meter_Parameter.event_parameter.JudgeUpLoadP!=0)&&(Active_power[und+1]>judgeuploadn))
	   {
		   
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))++;
		      
		   if((*((unsigned char *)&Event_N.UpLoad_A_P+und))>=Meter_Parameter.event_parameter.JudgeUpLoadT)
		   {
		     (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;
			   
			   Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P+und),(UPLOAD_A_P_ROM+und),
                                    (UPLOAD_A_BEGINFILE+und*32L),0,102,0x000D,
                                    ((unsigned long *)&Event_Power_Net_Times.UpLoad_A_Times+und),(UPLOAD_A_TIMES_ROM+und*4L));
			   Event_Power_Net_Flag.byte[3]|=offset[und];
			   if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x20)   
			   Save_EventReportTimes((UPLOAD_A_EVENT_TIMES_ROM+und*16), ((unsigned char *)&Event_Report_Status_Times.UpLoad_A_event_times+und*16));
		   }
	   }
	   else
	   {
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;
	   }
	  }
	  else
	  {
	   if((Active_power[und+1]<=judgeuploadn)||(Meter_Parameter.event_parameter.JudgeUpLoadP==0))
	   {
		   	
			 (*((unsigned char *)&Event_N.UpLoad_A_P+und))++;
			 
		   if(((*((unsigned char *)&Event_N.UpLoad_A_P+und))>=Meter_Parameter.event_parameter.JudgeUpLoadT)
		   ||(Meter_Parameter.event_parameter.JudgeUpLoadP==0))
		   {
		      (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;			
		      			  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P+und)),
                                   (UPLOAD_A_BEGINFILE+und*32L),102,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks+und),(UPLOAD_A_TIMETICKS_ROM+und*4L));
          Event_Power_Net_Flag.byte[3]&=(~offset[und]);
		    }
	   }
	   else
	   {
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;		
	   }
	  }
	  int2ic |= 0x01;
	  FeedWatchdog();
	}
	
}
//-------------------------- UpLoad Event ---------------------------------//
//-------------------------- CurrentReverse Event ---------------------------------//
void CurrReverseEvent(void)
{
	unsigned int uni;
  
  int2ic &= 0xf8;
  if(Event_Power_Net_Flag.bit.CurrReverse==0)
	{
	   if((Abnormal_Phase_I_sequence!=0)&&(eventmincurr*20>EventIb)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage)
	   &&(EventCriticalVoltage_Flag==0))
	   {
		   Event_N.CurrReverse_P++;
		   if(Event_N.CurrReverse_P>=60)
		   {
		     Event_N.CurrReverse_P=0;
		     
			   Save_Event_StartData_Flash(&Event_Power_Net_Pointer.CurrReverse_P,CURRREVERSE_P_ROM,
                                    CURRREVERSE_BEGINFILE,0,102,0x000D,
                                    &Event_Power_Net_Times.CurrReverse_Times,CURRREVERSE_TIMES_ROM);
			   Event_Power_Net_Flag.bit.CurrReverse=1;
         if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x02)  	   
         Save_EventReportTimes(CURRREVERSE_EVENT_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.CurrReverse_event_times);
		   }
	   }
	   else
	   {
		   Event_N.CurrReverse_P=0;
	   }
	}
	else
	{
	   if((Abnormal_Phase_I_sequence==0)||(EventCriticalVoltage_Flag!=0))
	   {
		   Event_N.CurrReverse_P++;
		   if((Event_N.CurrReverse_P>=60)||(EventCriticalVoltage_Flag!=0))
		   {
		     Event_N.CurrReverse_P=0;
		     
				 Save_Event_EndData_Flash(Event_Power_Net_Pointer.CurrReverse_P,
                                  CURRREVERSE_BEGINFILE,102,102,0x000D,
                                  &Event_Power_Net_Timeticks.CurrReverse_Times_Ticks,CURRREVERSE_TIMETICKS_ROM);				 
		     
         Event_Power_Net_Flag.bit.CurrReverse=0;
		   }
	   }
	   else
	   {
		   Event_N.CurrReverse_P=0;
	   }
	}
	int2ic |= 0x01;
	FeedWatchdog();
	
}
//-------------------------- CurrentReverse Event ---------------------------------//
//-------------------------- OverFactor Event ---------------------------------//
void OverFactorEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int  uni;
	unsigned char eventflag[4]={5,4,4,4};
	unsigned char offset[4]={0x02,0x20,0x40,0x80};
	unsigned char eventtimeticksoffset[4]={41,37,38,39};
	unsigned int  eventfilename[4]={OVERFACTOR_BEGINFILE,OVERFACTOR_A_BEGINFILE,OVERFACTOR_B_BEGINFILE,OVERFACTOR_C_BEGINFILE};
	unsigned long *eventtimeticksramaddr[4]={&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_B_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_C_Times_Ticks};
	unsigned int  eventtimetickseepromaddr[4]={OVERFACTOR_TIMETICKS_ROM,
	                                           OVERFACTOR_A_TIMETICKS_ROM,
	                                           OVERFACTOR_B_TIMETICKS_ROM,
	                                           OVERFACTOR_C_TIMETICKS_ROM};
	unsigned long judgeoverfactorn;
	unsigned long tempcurr;
	
	judgeoverfactorn=Meter_Parameter.event_parameter.JudgeOverFactorN*1000l;
	for(und=0;und<4;und++)
	{
		if((und>0)&&((V_REGION==0)||(V_REGION==3)))
      break;
		
		int2ic &= 0xf8;
      
    if(und==0)
      tempcurr=eventmaxcurr;
    else
      tempcurr=Curr[und-1];
		
		if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])==0)
		{
			if((judgeoverfactorn!=0)&&(tempcurr*20>EventIb)&&(Factor[und]<judgeoverfactorn))
			{
				(*(&Event_N.OverFactor_P+und))++;
				if((*(&Event_N.OverFactor_P+und))>=Meter_Parameter.event_parameter.JudgeOverFactorT)
				{
					(*(&Event_N.OverFactor_P+und))=0;
					
			    Save_Event_StartData_Flash((&Event_Power_Net_Pointer.OverFactor_P+und),(OVERFACTOR_P_ROM+((unsigned int)und)),
                                     eventfilename[und],0,30,0x0005,
                                     (&Event_Power_Net_Times.OverFactor_Times+und),(OVERFACTOR_TIMES_ROM+und*4L));
			    
			    Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]|offset[und];
          if((0 == und)&&(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x80))
          {
             Save_EventReportTimes(FACTOR_LOW_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Factor_Low_times);
          }
				}
			}
			else
			{
				*(&Event_N.OverFactor_P+und)=0;
			}
		}
		else
		{
			if((judgeoverfactorn==0)||(Factor[und]>=judgeoverfactorn))
			{
				(*(&Event_N.OverFactor_P+und))++;
				if(((*(&Event_N.OverFactor_P+und))>=Meter_Parameter.event_parameter.JudgeOverFactorT)||(judgeoverfactorn==0))
				{
					(*(&Event_N.OverFactor_P+und))=0;
								 
		      Save_Event_EndData_Flash((*(&Event_Power_Net_Pointer.OverFactor_P+und)),
                                   eventfilename[und],30,30,0x0005,
                                   eventtimeticksramaddr[und],eventtimetickseepromaddr[und]);
          Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]&(~offset[und]);
				}
			}
			else
			{
				*(&Event_N.OverFactor_P+und)=0;
			}
		}
		FeedWatchdog();
		int2ic |= 0x01;
	}
	
}

//-------------------------- OverFactor Event ---------------------------------//
//-------------------------- FailCurrent Event ---------------------------------//
//modified by mw 2009-09-03
void FailCurrentEvent(void)
{
	
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	

	//---------- A Phase /B Phase/C Phase----------//
	for(und=0;und<3;und++)
	{
		if((V_REGION==0 || V_REGION==3)&&(und==1))
		{			
			continue;
		}
		int2ic &= 0xf8;
		if((Event_Power_Net_Flag.byte[5]&offset[und])==0)
		{
		   if((Meter_Parameter.event_parameter.JudgeFailCurrI!=0)&&(Curr[und]<Meter_Parameter.event_parameter.JudgeFailCurrI)
		      &&(Volt[und]>Meter_Parameter.event_parameter.JudgeFailCurrSV*1000l))
		   {
				 (*((unsigned char *)&Event_N.FailCurrent_A_P+und))++;
			   if((*((unsigned char *)&Event_N.FailCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeFailCurrT)
			   {
			      //951-961 A Phase Fail Current
			      (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;
			      
		     		Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P+und),(FAILCURRENT_A_P_ROM+und),
                                       (FAILCURR_A_BEGINFILE+und*32L),0,141,0x002D,
                                       ((unsigned long *)&Event_Power_Net_Times.FailCurrent_A_Times+und),(FAILCURRENT_A_TIMES_ROM+und*4L));
		     		Event_Power_Net_Flag.byte[5]|=offset[und];
		     		if(Meter_Parameter.parameter1.EventReportMode.byte[3] & 0x01)   
		     		Save_EventReportTimes((BREAKCURR_A_TIMES_ROM +und*16), ((unsigned char *)&Event_Report_Status_Times.BreakCurr_A_times+und*16));
			   }
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;		   
		   }
		}
		else
		{
		   if((Curr[und]>=Meter_Parameter.event_parameter.JudgeFailCurrI)||(Meter_Parameter.event_parameter.JudgeFailCurrI==0))
		   {	
				 (*((unsigned char *)&Event_N.FailCurrent_A_P+und))++;
			   if(((*((unsigned char *)&Event_N.FailCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeFailCurrT)
			   ||(Meter_Parameter.event_parameter.JudgeFailCurrI==0))
			   {
			        (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;
			        
				      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P+und)),
                                       (FAILCURR_A_BEGINFILE+und*32L),141,102,0x000D,
                                       ((unsigned long *)&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks+und),(FAILCURRENT_A_TIMETICKS_ROM+und*4L));					
		      		Event_Power_Net_Flag.byte[5]&=(~offset[und]);
			   }
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;	
		   }
		}
	  int2ic |= 0x01;		
	  FeedWatchdog();
	}

}
//-------------------------- FailCurrent Event ---------------------------------//

void ConstantMagnetEventCheck(void)
{
	unsigned int  uni;
	
	int2ic &= 0xf8;
	
		
	if(Event_Power_Net_Flag.bit.ConstantMagnet==0)
	{
			if(CONSTANT_MAGNET_DET==0)
			{
				Event_N.ConstantMagnet_P++;
				if(Event_N.ConstantMagnet_P>=5)
				{
					Event_N.ConstantMagnet_P=0;
					
			    Save_Event_StartData_Flash(&Event_Power_Net_Pointer.ConstantMagnet_P,CONSTANTMAGNET_P_ROM,
                                     CONSTANTMAGNET_BEGINFILE,0,30,0x0005,
                                     &Event_Power_Net_Times.ConstantMagnet_Times,CONSTANTMAGNET_TIMES_ROM);
			    Event_Power_Net_Flag.bit.ConstantMagnet=1;
          if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x10)          		      
          Save_EventReportTimes(CONSTANTMAGNET_EVENT_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.ConstantMagnet_event_times);
				}
			}
			else
			{
				Event_N.ConstantMagnet_P=0;
			}
	}
	else
	{
			if(CONSTANT_MAGNET_DET!=0)
			{
				Event_N.ConstantMagnet_P++;
				if(Event_N.ConstantMagnet_P>=5)
				{
					Event_N.ConstantMagnet_P=0;
					
					if(Event_Power_Net_Pointer.ConstantMagnet_P>31)
					  Event_Power_Net_Pointer.ConstantMagnet_P=0;
		      uni=CONSTANTMAGNET_BEGINFILE+Event_Power_Net_Pointer.ConstantMagnet_P;
		      PrepEvent0Data(0x0005);
		      Write_File(uni,30,30,&Co.b[300]);
					
				  Event_Power_Net_Flag.bit.ConstantMagnet=0;
				}
			}
			else
			{
				Event_N.ConstantMagnet_P=0;
			}
	}
	FeedWatchdog();
	int2ic |= 0x01;
	
}

void PowerAbnormalEventCheck(void)
{
	unsigned char unc;
	unsigned int  uni;
	
	
	for(unc=0;unc<8;unc++)
	{
		if(pdvoltdata.validflag[unc]!=unc)
		  break;
	}
	if((unc>=8)&&(!((FLAG_SWITCH_ACT_MODE==0)&&(SWITCH_FACT_DEFINE!=0))))
	{
		unc=V_REGION;
		unc=unc%4;
		if((pdvoltdata.maxvolt*100)>(Vn[unc]*80))
		{
			CheckPowerDown();
			
			PrepEvent0Data(0x0005);
			for(unc=0;unc<6;unc++)
			{
		    Co.b[330+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		  }
	    if((CheckTime(&Co.b[330])!=0xff))
	    {
	     for(unc=0;unc<6;unc++)
		      Co.b[330+unc]=0xff;
	    }
	    for(unc=0;unc<36;unc++)
			{
		    Co.b[400+unc]= Co.b[300+unc];
		  }
	    
			Save_Record_Data_Flash(&Event_Power_Net_Pointer.PowerAbnormal_P,POWERABNORMAL_P_ROM,
                             POWERABNORMAL_BEGINFILE,36,
                             &Event_Power_Net_Times.PowerAbnormal_Times,POWERABNORMAL_TIMES_ROM);
        if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x20)   
        {
           EventReportState_Expand(0, 0, 0);
           Save_EventReportTimes(POWERABNORMAL_EVENT_TIMES_ROM , (unsigned char *)&Event_Report_Status_Times.PowerAbnormal_event_times);
        }
        }
	}
	pdvoltdata.maxvolt=0;
	FeedWatchdog();
	
}

//-------------------------Prep Event0 Data-------------------------//
unsigned char PrepEvent0Data(unsigned int eventkind){
	unsigned char unc;
	unsigned char eventlength;
	unsigned long tempunl;
	
	eventlength=0;
	//------B0------//
	if((eventkind&0x0001)!=0){
		//------Begin Time------//
	  for(unc=0;unc<=5;unc++)
	    Co.b[300+eventlength+unc]=*((unsigned char *)&softdate+unc);
	  eventlength=eventlength+6;
	}
	//------B1------//
	if((eventkind&0x0002)!=0){
		//------End Time------//
	  for(unc=0;unc<=5;unc++)
	    Co.b[300+eventlength+unc]=Co.b[600+unc];
	  eventlength=eventlength+6;
	}
	//------B2------//
	if((eventkind&0x0004)!=0){
		//------Total Energy------//
		for(unc=0;unc<=5;unc++)
	    *((unsigned long *)&Co.b[300+eventlength]+unc)=*((unsigned long *)&This_Month_Data.Energy_Record+unc*MAXTRIFF);
	  eventlength=eventlength+24;
	}
	//------B3------//
	if((eventkind&0x0008)!=0){
		//------ABC Energy------//
		for(unc=0;unc<=17;unc++)
	    *((unsigned long *)&Co.b[300+eventlength]+unc)=*((unsigned long *)&This_Month_Data.Energy_Record+6*MAXTRIFF+unc);
	  eventlength=eventlength+72;
	}
	//------B4------//
	if((eventkind&0x0010)!=0){
		//------Imbalance Rate------//
	  for(unc=0;unc<=3;unc++)
	    Co.b[300+eventlength+unc]=Co.b[606+unc];
	  eventlength=eventlength+4;
	}
	//------B5------//
	if((eventkind&0x0020)!=0){
		//------Volt------//
	  for(unc=0;unc<=2;unc++){
	    tempunl=Volt[unc]/1000l;
	    HexToBcd(2,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    eventlength=eventlength+2;
	  }
	  //------Curr------//
	  for(unc=0;unc<=2;unc++){
	    tempunl=Curr[unc]/10l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Curr[unc]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);   //mw modified 2010-05-26
	    eventlength=eventlength+3;
	  }
	  //------Active Power------//
	  for(unc=0;unc<=2;unc++){
	    tempunl=Active_power[unc+1]/100l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Active_power[unc+1]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);    //mw modified 2010-05-26
	    eventlength=eventlength+3;
	  }
	  //------Reactive Power------//
	  for(unc=0;unc<=2;unc++){
	    tempunl=Reactive_power[unc+1]/100l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Reactive_power[unc+1]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);    //mw modified 2010-05-26
	    eventlength=eventlength+3;
	  }
	  //------Factor------//
	  for(unc=0;unc<=2;unc++){
	    tempunl=Factor[unc+1]/1000l;
	    HexToBcd(2,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Factor[unc+1]<0)
	      Co.b[301+eventlength]=(Co.b[301+eventlength]|0x80);     //mw modified 2010-05-26
	    eventlength=eventlength+2;
	  }
	}
	//------B6------//
	if((eventkind&0x0040)!=0){
		//------AmpHour------//
	  for(unc=0;unc<12;unc++)
	    Co.b[300+eventlength+unc]=Co.b[610+unc];
	  eventlength=eventlength+12;
	}
	//------B7------//
	if((eventkind&0x0080)!=0){
		//------AvgCurr------//
	  for(unc=0;unc<4;unc++)
	    Co.b[300+eventlength+unc]=Co.b[622+unc];
	  eventlength=eventlength+4;
	}
	//------B8------//
	if((eventkind&0x0100)!=0){
		//------Maxdemand And Time------//
	  for(unc=0;unc<9;unc++)
	    Co.b[300+eventlength+unc]=Co.b[626+unc];
	  eventlength=eventlength+9;
	}
	//------B9------//
	if((eventkind&0x0200)!=0){
		//------Maxdemand------//
	  for(unc=0;unc<8;unc++)
	    Co.b[300+eventlength+unc]=Co.b[635+unc];
	  eventlength=eventlength+8;
	}
	//------B9------//
	if((eventkind&0x0400)!=0){
	  Co.b[300+eventlength]=Meter_States.Meter_Status2.bit.ActiveDirection_T;
	  eventlength=eventlength+1;
	}
	return eventlength;
	
}
/*"============================================================
函数说明：计算事件持续时间
输入参数：eventbegintimepointer 起始时刻指针
          eventendtimepointer 结束时刻指针
输出参数：无
返    回：result 事件记录持续时间（单位：秒）    
作    者：GANJP 1.01
============================================================"*/
unsigned long Cal_LastTime(unsigned char* eventbegintimepointer, unsigned char* eventendtimepointer)
{
	unsigned char unc,uni;
  unsigned long result;
  unsigned long tempunl;
  struct DATA_TIME tempdate;    
  
  result=0;
  for(uni = 0; uni < 6; uni++)
  {
  	*((unsigned char *)&tempdate + uni) = *eventendtimepointer++;
  }
	unc=TimeToLong(tempdate,&result);
	if(unc==0xFF)
		result=0xFFFFFFFF;
		
	tempunl=0;
	for(uni = 0; uni < 6; uni++)
  {
  	*((unsigned char *)&tempdate + uni) = *eventbegintimepointer++;
  }
	unc=TimeToLong(tempdate,&tempunl);
	if(unc==0xFF)
		tempunl=0xFFFFFFFF;
		
  if((result!=0xFFFFFFFF)&&(tempunl!=0xFFFFFFFF)&&(result>tempunl))
  	{
  	  result=result-tempunl;  	  
    }
   else
   	{
   		result = 0;
   	}
    
  return (result);
}
//-------------------------Prep Event0 Data-------------------------//
//-------------------------Save Event0 LastTime-------------------------//
void SaveEvent0LastTime_Other(unsigned int eventlasttimeaddr,unsigned long* eventlasttimepointer)
{
  //unsigned char unc;
  unsigned long result;

  
  //if(eventaddrkind==0){
  //	WRLC256(eventaddr,&Co.b[300],6,0,1);
  //}
  //else{
  //  Read_File(eventaddr,0,6,&Co.b[300]);
  //}

   // result = Cal_LastTime(&Co.b[300], eventendtimepointer);
   // if(result)
    	//{
    	//	(*eventlasttimepointer)=(*eventlasttimepointer)+(result/60l);
  	    WRLC256(eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
    	//}  	   
}
//-------------------------Save Event0 LastTime-------------------------//
void SaveEvent0LastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer){
  //unsigned char unc;
  unsigned long result;
 // unsigned long tempunl;
 // struct DATA_TIME tempdate;
 
 	//mw modified 2010-06-01
	if(EventTimeTicksValid_Flag==0xFF) /*"上电时候RAM中数据有效"*/
	{
		FeedWatchdog();
		WRLC256(eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
	}
	else  /*"上电时候RAM中数据无效 ， 计算累计时间差值"*/
	{
		  if(eventaddrkind==0){
		  	WRLC256(eventaddr,&Co.b[300],6,0,1);
		  }
		  else{
		    Read_File(eventaddr,0,6,&Co.b[300]);
		  }
		    result = Cal_LastTime(&Co.b[300], eventendtimepointer);
		    if(result)
		    	{
		    		(*eventlasttimepointer)=(*eventlasttimepointer)+(result/60l);
		  	    WRLC256(eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
		    	}  	
	}
}
//-------------------------Save Event0 LastTime-------------------------//
//-------------------------Save Event0 Amphour-------------------------//
void SaveEvent0BeginAmpHour(unsigned char eventkind){
	unsigned char unc;
	
	if(eventkind<12){
		for(unc=0;unc<3;unc++)
		  Event0BeginAmpHour[eventkind*3l+unc]=Event_AmpHour[unc];
	}
	
}
/*"============================================================
函数说明：上电时根据事件起始时刻的电流值计算安时值
          （上电检测RAM中数据乱时调用）
输入参数：eventaddr  事件内卡地址
          kind      最近一次事件存储位置 0 EEPROM  1 FLASH
输出参数：无
返    回：无    
作    者：GANJP 1.01
============================================================"*/
void Cal_AmpHour_poweron(unsigned int eventaddr, unsigned char kind)
{
	unsigned long curr_temp[3] = {0, 0, 0};
	unsigned long last_time = 0;
	unsigned char uni, unc;
	unsigned long AMP_temp = 0;
	if(kind==0)
		{
			WRLC256(eventaddr,&Co.b[300],141,0,1);
		}
  else
    {
      Read_File(eventaddr,0,141,&Co.b[300]);
    }
	
	last_time = Cal_LastTime(&Co.b[300], (unsigned char *)&Powerdown_Save_Data.date);
	
//	curr_temp[0] = *((unsigned long *)&Co.b[340]);
//	curr_temp[1] = *((unsigned long *)&Co.b[369]);
//	curr_temp[2] = *((unsigned long *)&Co.b[398]);
	
	for(uni = 0; uni < 3; uni++)
	{
		for(unc = 0; unc < 3; unc++)
		{
			*((unsigned char *)&curr_temp[uni] + unc) = Co.b[408 + uni * 3 + unc];
			if(unc==2)
	    	{
	   		  *((unsigned char *)&curr_temp[uni] + unc) =((*((unsigned char *)&curr_temp[uni] + unc) )&0x7F);	//Li Update 20131216
	   		}
		}
		if(curr_temp[uni] > 20l * Meter_Parameter.parameter1.EventJudgeIn)
			break;
	}
	if(uni == 3)
		{
			for(uni = 0; uni < 3; uni++)
			{
				/*"电流小数位为3位，安时值小数位数为2位，所以要除10,这里采用了4舍5入"*/
				BcdToHex(4, (unsigned char *)&curr_temp[uni], (unsigned char *)&AMP_temp);
				(*((unsigned long *)&Co.b[610]+uni)) = ((AMP_temp * last_time)/3600l + 5)/10l;
			}			
		}	
}
void SaveEvent0EndAmpHour(unsigned char eventkind){
	unsigned char unc;
	unsigned long tempdata0;
	unsigned long tempdata1;
	
	if(eventkind<12){
		for(unc=0;unc<=2;unc++){
	    tempdata0=Event0BeginAmpHour[eventkind*3l+unc];
	    tempdata1=Event_AmpHour[unc];
	    if((tempdata1>=tempdata0)&&(tempdata0!=0xFFFFFFFF)&&(tempdata1!=0xFFFFFFFF)){
	    	if((tempdata1-tempdata0)<=99999999l)
	    	  tempdata0=tempdata1-tempdata0;
	    	else
	    		tempdata0=99999999l;
	    }
	    else{
	    	tempdata0=0xFFFFFFFF;
	    }
	    (*((unsigned long *)&Co.b[610]+unc))=tempdata0;
	  }
	}
	
}
//-------------------------Save Event0 Amphour-------------------------//
//-------------------------Clear Event0 Flag-------------------------//
void ClearEvent0Flag(unsigned char eventflagn,unsigned char eventflagm){
	
	if(eventflagn<8){
		Event_Power_Net_Flag.byte[eventflagn]=Event_Power_Net_Flag.byte[eventflagn]&eventflagm;
		CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
	}
	
}
//-------------------------Clear Event0 Flag-------------------------//
//-------------------------Move Event Data To Flash-------------------------//
void MoveEventData2Flash(unsigned int eventeepromaddr,unsigned int eventfilename,unsigned char *eventfilep,unsigned char eventlength)
{
	unsigned int uni;
	
	ClearEvent_EventBegin(eventfilep,eventfilename);
	
  uni=eventfilename+(*eventfilep)%32;
  
	WRLC256(eventeepromaddr,&Co.b[300],eventlength,0,1);
	
	Write_File(uni,0,eventlength,&Co.b[300]);
	
}
//-------------------------Move Event Data To Flash-------------------------//
//-------------------------WriteFilePdEvent-------------------------//
void Write_File_PdEvent(unsigned int eventfilename,unsigned int eventfilestartaddr,
                        unsigned char eventfileoffset,unsigned char *eventfilebuff){
    unsigned char unc;
    unsigned char res;
    unsigned int uni;
    uni=Read_File(eventfilename,eventfilestartaddr,eventfileoffset,&Co.b[800]);
    res=0xFF;
    if(uni==eventfileoffset){
    	for(unc=0;unc<eventfileoffset;unc++){
    		if(Co.b[800+unc]!=0xFF){
    			res=0;
    			break;
    		}
    	}
    }
    if(res==0xFF)
      Write_File(eventfilename,eventfilestartaddr,eventfileoffset,eventfilebuff);
    
}
//-------------------------WriteFilePdEvent-------------------------//
//------------------------- New 645 Function  -----------------------//
//@mw added 2009-09-03@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times)	
{
     WRLC256(Pointer_Addr,(unsigned char *)Event_Pointer,1,0,0);
     (*(Event_times))++;
     WRLC256(Times_Addr,(unsigned char *)Event_times,4,0,0);

}


/*"调用此函数注意startIndex不能超过(1024-96)，否则Co.b会溢出"*/
void Copy_ENERGY_TO_CO(unsigned int startIndex)
{//total datalength=96
    unsigned char unc;
    unsigned long *ptr=(unsigned long *)&Co.b[startIndex];
     for(unc=0;unc<=5;unc++)
	  *ptr++=*((unsigned long *)&This_Month_Data.Energy_Record+unc*MAXTRIFF);
	for(unc=0;unc<=17;unc++)
	  *ptr++=*((unsigned long *)&This_Month_Data.Energy_Record+6*MAXTRIFF+unc);
}
/*
void Copy_ENERGY_TO_CO_End(unsigned int startIndex,unsigned int  EnergyPassMAXTimesIndex)
{
       unsigned long tempdata0=0;
	unsigned long tempdata1=0;
	unsigned char unc;
      //------  energy  ------//

       for(unc=0;unc<=5;unc++)
	{			
	       tempdata0=(*((unsigned long *)&Co.b[startIndex]+unc));
	       tempdata1=(*((unsigned long *)&This_Month_Data.Energy_Record+unc*MAXTRIFF));
	       if(tempdata1>=tempdata0)
		{
	    	      tempdata0=tempdata1-tempdata0;
	       }
	       else
		{
	    	    if((Co.b[EnergyPassMAXTimesIndex+unc]<This_Month_Data.Energy_Record.EnergyPassMAXTimes[unc]))
	    		    tempdata0=999999999l-tempdata1+tempdata0;
	    	    else
	    		    tempdata0=0xFFFFFFFF;
	       }
	        (*((unsigned long *)&Co.b[startIndex]+unc))=tempdata0;	    
	}	  
       //------  Phase energy  ------//
        for(unc=0;unc<=17;unc++)
       {
	    tempdata0=(*((unsigned long *)&Co.b[startIndex+24]+unc));
	    tempdata1=(*((unsigned long *)&This_Month_Data.Energy_Record+6*MAXTRIFF+unc));
	    if(tempdata1>=tempdata0)
	    {
	    	   tempdata0=tempdata1-tempdata0;
	    }
	    else
           {
	    	   tempdata0=999999999l-tempdata1+tempdata0;
	     }
	     (*((unsigned long *)&Co.b[startIndex+24]+unc))=tempdata0;
	  }
}
*/
/*
void Copy_ENERGY_FF_TO_CO(unsigned int startIndex)
{
    unsigned char unc;
    unsigned long *ptr=(unsigned long *)&Co.b[startIndex];
     for(unc=0;unc<=5;unc++)
	  *ptr++=0xFFFFFFFF;
    for(unc=0;unc<=17;unc++)
	  *ptr++=0xFFFFFFFF;
}
*/
/*
void Copy_AmpHour_TO_CO(unsigned int startIndex)
{
     unsigned char unc;
     unsigned long tempdata0=0;
     unsigned long tempdata1=0; 
    for(unc=0;unc<=2;unc++){
	    tempdata0=(*((unsigned long *)&Co.b[startIndex]+unc));
	    tempdata1=Event_AmpHour[unc];
	    if(tempdata1>=tempdata0){
	    	if((tempdata1-tempdata0)<=99999999l)
	    	  tempdata0=tempdata1-tempdata0;
	    	else
	    		tempdata0=99999999l;
	    }
	    else{
	    	tempdata0=0xFFFFFFFF;
	    }
	    (*((unsigned long *)&Co.b[startIndex]+unc))=tempdata0;
	  }	  
}
*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//-------------------------------------------//
				//SaveEvent0LastTime(LASTLOSTCURR_A_ROM+und*243L,0,&Co.b[400],LOSTCURRENT_A_TIMETICKS_ROM+4L*und,
			  //((unsigned long *)&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks+und));

//unsigned long  Prepare_For_EventLastTime(unsigned int eventaddr,unsigned char eventaddrkind,
//                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
//                        unsigned long* eventlasttimepointer)
//{
//  unsigned char unc;
//  unsigned long result;
//  unsigned long tempunl;
//  struct DATA_TIME tempdate;
//  
//  FeedWatchdog();
//  
//  if(eventaddrkind==0){
//  	WRLC256(eventaddr,&Co.b[300],6,0,1);
//  }
//  else{
//	if(IntoPowerDownFlag!=0)  
//	{
//		result=0;
//		return result;
//	}
//    	Read_File(eventaddr,0,6,&Co.b[300]);
//  }
//
//    result = Cal_LastTime(&Co.b[300], eventendtimepointer);
//    if(result)
//    	{
//    		result=(*eventlasttimepointer)+(result/60l);
//
//    	}  
//  
//  return result;
//  
//}
////--------------------------------------------//



//-------------------------PrepFirstEventDataNew----------------------//
///*"结构CLEAREVENT_STRU1中无用的指针请填NULL"*/
//const struct REFRESHDATA_STRU  Refreshdata_Leaf[]={
//{LASTLOSTVOLT_A_ROM,LOSTVOLT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x01,255,0x00},
//{LASTLOSTVOLT_A_ROM,LOSTVOLT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x01,255,0x00},
//{LASTLOSTVOLT_B_ROM,LOSTVOLT_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x02,255,0x00},
//{LASTLOSTVOLT_C_ROM,LOSTVOLT_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x04,255,0x00},
//
////{LASTBREAKPHASE_A_ROM,BREAKPHASE_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x01,255,0x00},
//{LASTBREAKPHASE_A_ROM,BREAKPHASE_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x01,255,0x00},
//{LASTBREAKPHASE_B_ROM,BREAKPHASE_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.BreakPhase_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x02,255,0x00},
//{LASTBREAKPHASE_C_ROM,BREAKPHASE_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.BreakPhase_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x04,255,0x00},
//
//
////{LASTLOSTCURR_A_ROM,LOSTCURRENT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x20,243,0x00},
//{LASTLOSTCURR_A_ROM,LOSTCURRENT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x20,243,0x00},
//{LASTLOSTCURR_B_ROM,LOSTCURRENT_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostCurrent_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x40,243,0x00},
//{LASTLOSTCURR_C_ROM,LOSTCURRENT_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.LostCurrent_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x80,243,0x00},
//
//
//{LASTPHASE3LOSTVOLT_ROM,PHASE3LOSTVOLT_TIMETICKS_ROM,&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x10,16,0x00},
//
//
////following is file 
//
////{OVERVOLT_A_BEGINFILE,OVERVOLT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x08,32,0xFF},
//{OVERVOLT_A_BEGINFILE,OVERVOLT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x08,32,0xFF},
//{OVERVOLT_B_BEGINFILE,OVERVOLT_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverVoltage_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x10,32,0xFF},
//{OVERVOLT_C_BEGINFILE,OVERVOLT_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverVoltage_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x20,32,0xFF},
//
//
////{VOLTDOWN_A_BEGINFILE,VOLTAGEDOWN_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x08,32,0xFF},
//{VOLTDOWN_A_BEGINFILE,VOLTAGEDOWN_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x08,32,0xFF},
//{VOLTDOWN_B_BEGINFILE,VOLTAGEDOWN_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltageDown_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x10,32,0xFF},
//{VOLTDOWN_C_BEGINFILE,VOLTAGEDOWN_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltageDown_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],0x20,32,0xFF},
//
//{CURRIMBALANCEEVENT_BEGINFILE,CURRIMBEVENT_TIMETICKS_ROM,&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.CurrImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x40,32,0xFF},
//
//{VOLTIMBALANCEEVENT_BEGINFILE,VOLTIMBEVENT_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltImBalanceEvent_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x80,32,0xFF},
//
//
//{OVERFACTOR_BEGINFILE,OVERFACTOR_TIMES_ROM,&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x02,32,0xFF},
//
////{OVERFACTOR_BEGINFILE,OVERFACTOR_TIMES_ROM,&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x02,32,0xFF},
//
//
//{POWERREVERSE_A_BEGINFILE,POWERREVERSE_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.PowerReverse_A_Ticks,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x01,32,0xFF},
//{POWERREVERSE_B_BEGINFILE,POWERREVERSE_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.PowerReverse_B_Ticks,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x02,32,0xFF},
//{POWERREVERSE_C_BEGINFILE,POWERREVERSE_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.PowerReverse_C_Ticks,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],0x04,32,0xFF},
//
//
//{FAILCURR_A_BEGINFILE,FAILCURRENT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x08,32,0xFF},
//{FAILCURR_B_BEGINFILE,FAILCURRENT_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.FailCurrent_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x10,32,0xFF},
//{FAILCURR_C_BEGINFILE,FAILCURRENT_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.FailCurrent_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x20,32,0xFF},
//
//
//{OVERCURR_A_BEGINFILE,OVERCURRENT_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x01,32,0xFF},
//{OVERCURR_B_BEGINFILE,OVERCURRENT_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverCurrent_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x02,32,0xFF},
//{OVERCURR_C_BEGINFILE,OVERCURRENT_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverCurrent_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x04,32,0xFF},
//
//{CURRREVERSE_BEGINFILE,CURRREVERSE_TIMETICKS_ROM,&Event_Power_Net_Timeticks.CurrReverse_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.CurrReverse_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],0x01,32,0xFF},
//{LASTVOLTREVERSE_ROM,VOLTAGERESERVE_TIMETICKS_ROM,&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.VoltageReserve_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],0x08,204,0x00},
//{OVERPOWERALARM_BEGINFILE,OVERPOWERALARM_TIMETICKS_ROM,&Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.OverPowerAlarm_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],0x01,32,0xFF},
//
//{UPLOAD_A_BEGINFILE,UPLOAD_A_TIMETICKS_ROM,&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x08,32,0xFF},
//{UPLOAD_B_BEGINFILE,UPLOAD_B_TIMETICKS_ROM,&Event_Power_Net_Timeticks.UpLoad_B_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x10,32,0xFF},
//{UPLOAD_C_BEGINFILE,UPLOAD_C_TIMETICKS_ROM,&Event_Power_Net_Timeticks.UpLoad_C_Times_Ticks,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],0x20,32,0xFF}
//};
//
//const unsigned long Refreshdata_ID[]={      0x10000002,0x10010002,0x10020002,0x10030002,
//								     	0x13010002,0x13020002,0x13030002,
//									0x18010002,0x18020002,0x18030002,
//									0x03050000,
//									0x12010002,0x12020002,0x12030002,
//									0x11010002,0x11020002,0x11030002,
//									0x17000002,0x16000002,  //curreimbanlance volt imbanlance
//									0x1F000002,
//									0x1B010002,0x1B020002,0x1B030002,
//									0x1A010002,0x1A020002,0x1A030002,
//									0x19010002,0x19020002,0x19030002,
//									0x15000002,0x14000002,0x03420000,                    //CurrReverse, VoltReverse,OverPowerAlarm
//									0x1C010002,0x1C020002,0x1C030002,
//									};
//
//unsigned char Refresh_AddTime(unsigned long eventcode)
//{
//	const struct REFRESHDATA_STRU *Event_Node1;
//	unsigned int uni=0;
//	unsigned char result_findOK=0;
//	unsigned char result=0;
//	unsigned int   und=0;	
//	unsigned int   eventaddr=0;	
//	unsigned char mask=0;
//    	unsigned long temp_timeadd=0;
//	
//  	 //temp_timeadd=0;
//  	 for(uni=0;uni<12;uni++)   
//   		TempEventData[uni]=0;
//
//   
//	FeedWatchdog();
//		for(uni=0;uni<((sizeof(Refreshdata_ID))/sizeof(unsigned long));uni++)         /*"查找数据标识"*/
//		{
//		 	if(Refreshdata_ID[uni]==eventcode)
//		 	{
//				result_findOK=0x01;  /*"表示分相累计时间"*/
//				//if((eventcode&0x00ff0000)==0x00000000)
//				if((eventcode)==0x10000002)  /*"现在暂时只有失压抄读总累计时间"*/
//				{
//					result_findOK=0x11;  /*"表示总累计时间"*/
//				}
//				Event_Node1=( const struct REFRESHDATA_STRU *)&Refreshdata_Leaf[uni];
//				break;
//		 	}			
//		}
//
//		/*"查到数据标识"*/
//		if(result_findOK) 
//		{
//				mask=(Event_Node1->Offset);
//
//				for(und=0;und<=2;und++)	  
//				{
//					if((Event_Node1->EE_flash_select)==0x00)  //0x00  means Get Data from EE
//					{
//						eventaddr=(Event_Node1->EE_flash_addr)+(Event_Node1->EE_File_Offset)*und;	
//					}		
//					else  //Get Data from Flash 
//					{
//						eventaddr=(Event_Node1->EE_flash_addr)+(Event_Node1->EE_File_Offset)*und
//							+(*((Event_Node1->Pointer)+und));	
//					}
//					if(((*(Event_Node1->Flag))&mask)!=0)   /*"事件发生未结束"*/
//					{
//						for(uni=0;uni<=5;uni++)
//						Co.b[400+uni]=*((unsigned char *)&softdate+uni);	
//						(*((unsigned long *)&TempEventData[0]))+=Prepare_For_EventLastTime(eventaddr,(Event_Node1->EE_flash_select),
//							&Co.b[400],(Event_Node1->Ticks_addr)+4L*und,(((unsigned long *)(Event_Node1->Ticks))+und));
//						FeedWatchdog();	
//					}
//					else    /*"已经结束"*/
//					{
//					  	FeedWatchdog();
//						WRLC256((Event_Node1->Ticks_addr)+4L*und,(unsigned char*)&temp_timeadd,4,0,1);
//						(*((unsigned long *)&TempEventData[0]))+=temp_timeadd;
//					}
//					result=0x55;
//					mask <<= 1;  
//					
//					if(result_findOK==0x01)   /*"查询分相累计时间就直接跳出"*/
//					break;	/*"查询总累计时间3次循环"*/		
//				}	
//		}
//		
//		return result;			
//}
//
//void Refresh_EventData(unsigned long eventcode)
//{
//		if(((eventcode&0x000000FF)==0x00000002)||
//		((eventcode)==0x03050000)||((eventcode)==0x03420000))  /*"刷新累计时间"*/	
//		Read_event_first_flag=Refresh_AddTime(eventcode);	
//		else
//		Read_event_first_flag=PrepNewFirstEventData(eventcode);
//}


//===================================================//
 /*"低功耗下电池上电清事件的累计时间"*/	
//===================================================//
void ClearEventDate_BatteryPowerOn(void)
{
	unsigned int i,j;
	
	/*"第一项数据 :  清事件累计时间"*/
	//===================================//
	CrcEventTimeTicks=0;
	 for(i=0;i<6;i++)  
	 {
		for(j=0;j<8;j++)
		{
		(*((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+j+i*8L))=0; 
		}  
	 }
	//===================================//

}

//===================================================//

unsigned char CheckOpenCoverState(unsigned char kind)
{
	unsigned char unc;
	unsigned char coveropennum;
	unsigned char coverclosenum;
	unsigned char result;
	
	result=0xff;
	
	if(pdopencovercheckdata[kind].recordnum>0)
	{
		unc=(pdopencovercheckdata[kind].recordnum-1)%3;
		if(pdopencovercheckdata[kind].startrecord[unc].opencoverflag==2)
		{
			if(((kind==0)&&(p8_3==0))||((kind==1)&&(p2_5==0)))
			{
				  Delay(10);
				
				if(((kind==0)&&(p8_3==0))||((kind==1)&&(p2_5==0)))
				  result=1;
			}
		}
		else
		{
			if(((kind==0)&&(p8_3==1))||((kind==1)&&(p2_5==1)))
			{
				  Delay(10);
				
				if(((kind==0)&&(p8_3==1))||((kind==1)&&(p2_5==1)))
				  result=2;
			}
		}
	}
	else
	{
	  coveropennum=0;
	  coverclosenum=0;
	  
	  for(unc=0;unc<3;unc++)
	  {
		  if(((kind==0)&&(p8_3==0))||((kind==1)&&(p2_5==0)))
		    coveropennum++;
		  else
		    coverclosenum++;
		  
		  if(unc<2)
				Delay(10);
	  }
	
	  result=1;
	  if(coveropennum<coverclosenum)
	    result=2;
	}
	return result;
}

void PdOpenCoverCheckInit(unsigned char kind)
{
	unsigned char unc;
	unsigned char und;
	struct DATEANDTIME_DEF Opencover_DateAndTime;
	
	if(kind==0)
	{
	  for(unc=0;unc<sizeof(struct	PDOPENCOVER_STRUCTURE)*2;unc++)
	  {
		  *(((unsigned char *)&pdopencovercheckdata[0])+unc)=0;
	  }
	  pdopencoverintflag[0]=0;
	  pdopencoverintflag[1]=0;
	}
	else
	{
	  ClockChipRead((unsigned char *)&Opencover_DateAndTime);
	  for(und=0;und<2;und++)
	  {
	  	pdopencovercheckdata[und].startrecord[0].opencoverflag=CheckOpenCoverState(und);
	  	pdopencovercheckdata[und].startrecord[0].startyear=Opencover_DateAndTime.Year;
		  pdopencovercheckdata[und].startrecord[0].startmonth=Opencover_DateAndTime.Month;
			pdopencovercheckdata[und].startrecord[0].startday=Opencover_DateAndTime.Day;
			pdopencovercheckdata[und].startrecord[0].starthour=Opencover_DateAndTime.Hour;
			pdopencovercheckdata[und].startrecord[0].startmin=Opencover_DateAndTime.Min;
			pdopencovercheckdata[und].startrecord[0].startsec=Opencover_DateAndTime.Sec;
	  	pdopencovercheckdata[und].recordnum=1;
	  	for(unc=0;unc<8;unc++)
	  	  pdopencovercheckdata[und].validflag[unc]=unc;
	  }
  }
}

void PdOpenCoverCheck(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned char tempcoverstatus;
	unsigned char tempreadtimeflag;
	struct DATEANDTIME_DEF Opencover_DateAndTime;
	
	tempreadtimeflag=0;
	for(unc=0;unc<2;unc++)
	{
		if(pdopencoverintflag[unc]==0x33)
		{
			pdopencoverintflag[unc]=0;
			
			if(pdopencovercheckdata[unc].recordnum<3)
			{
				tempcoverstatus=CheckOpenCoverState(unc);
				
				if((tempcoverstatus==1)||(tempcoverstatus==2))
				{
				  und=pdopencovercheckdata[unc].recordnum%3;
				  pdopencovercheckdata[unc].startrecord[und].opencoverflag=tempcoverstatus;
				  
					if(tempreadtimeflag==0)
					{
					    ClockChipRead((unsigned char *)&Opencover_DateAndTime);
					    tempreadtimeflag=1;
					}
					pdopencovercheckdata[unc].startrecord[und].startyear=Opencover_DateAndTime.Year;
					pdopencovercheckdata[unc].startrecord[und].startmonth=Opencover_DateAndTime.Month;
					pdopencovercheckdata[unc].startrecord[und].startday=Opencover_DateAndTime.Day;
					pdopencovercheckdata[unc].startrecord[und].starthour=Opencover_DateAndTime.Hour;
					pdopencovercheckdata[unc].startrecord[und].startmin=Opencover_DateAndTime.Min;
					pdopencovercheckdata[unc].startrecord[und].startsec=Opencover_DateAndTime.Sec;
				  
				  pdopencovercheckdata[unc].recordnum++;
			  }
			}
			
			if(pdopencovercheckdata[unc].recordnum>=3)
			{
				if(unc==0)
					int1ic&=0xF8;
					    
			  if(unc==1)
					int7ic&=0xF8;
			}
		}
	}
	
	NEW645Meter_States.Meter_Status7.bit.OpenBox=0;
	if(p2_5==0)
	  NEW645Meter_States.Meter_Status7.bit.OpenBox=1;
	
	
  NEW645Meter_States.Meter_Status7.bit.OpenCover=0;
	if(p8_3==0)
	  NEW645Meter_States.Meter_Status7.bit.OpenCover=1;
	
}

unsigned char CheckOpenCoverDataValid(unsigned char kind)
{
	unsigned char result;
	unsigned char unc;
	
	result=1;
	
	for(unc=0;unc<8;unc++)
	{
		if(pdopencovercheckdata[kind].validflag[unc]!=unc)
		{
			result=0;
			break;
		}
	}
	
	if(pdopencovercheckdata[kind].recordnum>3)
	  result=0;
	
	return result;
	
}

void PdOpenCoverCheckPowerUpDeal(void)
{
	unsigned char unc;
	unsigned char unc1;
	unsigned char und;
	unsigned char result;
	unsigned char tempnum[2]={0,0};
	unsigned int uni;
	unsigned char offset[2]={0x40,0x80};
	unsigned int Filename[2]={OPENCOVEREVENT_BEGINFILE,OPENBOXEVENT_BEGINFILE};
	
	for(unc=0;unc<2;unc++)
	{
		if(CheckOpenCoverDataValid(unc)==1)
		{
			if((Event_Power_Net_Flag.byte[3]&offset[unc])==0)
			{
				result=0;
				for(und=0;und<(pdopencovercheckdata[unc].recordnum%4);und++)
				{
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==1)
					{
						result=1;
						tempnum[0]=und;
					}
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==2)
					{
						if(result==1)
						{
						  result=2;
						  tempnum[1]=und;
						  break;
						}
					}
				}
				if(result!=0)
				{
					CheckPowerDown();
				  FeedWatchdog();
				  MoveEventData2Flash(LASTOPENCOVEREVENT_ROM+unc*60L,Filename[unc],((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P+unc),60);
				  
				  for(unc1=0;unc1<6;unc1++)
				  {
	    	    Co.b[300+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[tempnum[0]].startyear)+unc1);
	    		  *((unsigned long *)&Co.b[306]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*MAXTRIFF);
	    		  Co.b[330+unc1]=0;
	    		  *((unsigned long *)&Co.b[336]+unc1)=0xffffffff;
	    		  if(result==2)
	    		  {
	    		  	Co.b[330+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[tempnum[1]].startyear)+unc1);
	    		    *((unsigned long *)&Co.b[336]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*MAXTRIFF);
	    		  }
	    	  }
		      
		      Save_Event_StartData_Eeprom((&Event_Power_Net_Pointer.OpenCoverEvent_P+unc),(OPENCOVEREVENT_P_ROM+unc),
                                      (LASTOPENCOVEREVENT_ROM+unc*60L),60,
                                      ((unsigned long *)&Event_Power_Net_Times.OpenCoverEvent_Times+unc),(OPENCOVEREVENT_TIMES_ROM+unc*4L));
		    
		      if(result==1)
		      {
		        Event_Power_Net_Flag.byte[3]|=offset[unc];
		        CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
	    	  }
	    	  
	    	  if(unc==0)
	    	  {
	    	    eventstatusinfo.bit.powerdownopencover=1;
                if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x04)
                Save_EventReportTimes(OPEN_METER_COVER_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Open_Meter_Cover_times);
	    	  }
	    	  else
	    	  {
	    	    eventstatusinfo.bit.powerdownopenbox=1;
                if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x08)                                
                Save_EventReportTimes(OPEN_METER_RAIL_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.Open_Rail_Cover_times);
	    	  }
	    	  
				}
			}
			else
			{
				for(und=0;und<(pdopencovercheckdata[unc].recordnum%4);und++)
				{
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==2)
					{
						CheckPowerDown();
				    FeedWatchdog();
						
						for(unc1=0;unc1<6;unc1++)
				    {
	    	      Co.b[300+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[und].startyear)+unc1);
	    		    *((unsigned long *)&Co.b[306]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*MAXTRIFF);
	    	    }
						WRLC256(LASTOPENCOVEREVENT_ROM+unc*60L+30L,&Co.b[300],30,0,0);
						
		        Event_Power_Net_Flag.byte[3]&=(~offset[unc]);
		        CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
		        
		        break;
					}
				}
			}
			
			for(und=0;und<sizeof(struct	PDOPENCOVER_STRUCTURE);und++)
	    {
		    *(((unsigned char *)&pdopencovercheckdata[unc])+und)=0;
	    }
			
		}
	}
	
}
//#pragma SECTION program program_protect
/*"=============================================================="*/
/*"函数说明：事件总清零处理接口函数，清除RAM、EEPROM中事件记录数据，"*/
/*"                           索引修改为特殊值，后续清FLASH中文件"*/
/*"输入参数：无"*/
/*"输出参数：无"*/
/*"函数调用：电表清零接口函数中调用"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void ClearEventAll(void)
{
unsigned int uni = 0;
unsigned char eventflagmask[8]={0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00};

/*"清事件发生标志"*/
for(uni = 0; uni < 8; uni++)
{
Event_Power_Net_Flag.byte[uni] = (Event_Power_Net_Flag.byte[uni]&eventflagmask[uni]);
}
/*"事件指针索引特殊处理"*/
 /*"事件清零后指针修改为EVENT_CLAER_STATUS,事件发生和抄读时根据指针状态进行事件清零"*/
 
 /*"清电网事件索引指针、累计次数55 56 57分别是时钟电池欠压、低功耗电池欠压、校表事件记录，不清零"*/
for(uni = 0; uni < 55; uni++)
{
if(((*((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times + uni)) != 0) ||
    (*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) != 0))/*"当事件发生次数为0，且事件存储指针偏移为0表示事件未发生，事件无需清零"*/
{
*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) = EVENT_CLAER_STATUS;
*((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times + uni) = 0;
}
else
{
  if((*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni)) != EVENT_CLAER_STATUS)
    *((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) = 0;
}
}
WRLC256(EVENT_POWER_NET_POINTER_ROM, (unsigned char *)&Event_Power_Net_Pointer, 
	         sizeof(struct EVENT_POWER_NET_POINTER), 0, 0);
WRLC256(EVENT_POWER_NET_TIMES_ROM, (unsigned char *)&Event_Power_Net_Times, 
	         sizeof(struct EVENT_POWER_NET_TIMES), 0, 0);

/*"清电表操作事件索引指针0~7威胜自扩事件和8电表清零事件，不清零"*/
for(uni = CLEARMETEREVENTBEGIN; uni <= CLEARMETEREVENTEND; uni++)
{
if(((*((unsigned long *)&Event_Meter_Pro_Times.ResetCPU_Times+ uni)) != 0) ||
      (*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P + uni) != 0))/*"当事件发生次数为0，且事件存储指针偏移为0表示事件未发生，事件无需清零"*/
{
*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni) = EVENT_CLAER_STATUS;
*((unsigned long *)&Event_Meter_Pro_Times.ResetCPU_Times+ uni) = 0;
}
else
{
  if((*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni)) != EVENT_CLAER_STATUS)
    *((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni) = 0;
}
}

FeedWatchdog();
WRLC256(EVENT_METER_PRO_POINTER_ROM, (unsigned char *)&Event_Meter_Pro_Pointer, 
	         sizeof(struct EVENT_METER_PRO_POINTER), 0, 0);
WRLC256(EVENT_METER_PRO_TIMES_ROM, (unsigned char *)&Event_Meter_Pro_Times, 
	         sizeof(struct EVENT_METER_PRO_TIMES), 0, 0);
FeedWatchdog();
/*"清电网事件累计时间,全部清零"*/
for(uni = 0; uni < sizeof(struct EVENT_POWER_NET_TIMETICKS); uni++)
{
*((unsigned char *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+ uni) = 0;
}

WRLC256(EVENT_POWER_NET_TIMETICKS_ROM, (unsigned char *)&Event_Power_Net_Timeticks, 
	         sizeof(struct EVENT_POWER_NET_TIMETICKS), 0, 0);

  VoltStatSetDefault();
  EepromEventSetDefault();

for(uni = 0; uni < 2; uni++)
{
VoltCheck_N[0][uni].byte = 0;
VoltCheck_N[1][uni].byte = 0;
VoltCheck_N[2][uni].byte = 0;
powerreversetflag[uni]=0;
powerreversetcnt[uni]=0;	   
}
eventstatusinfo.byte=0; 


/*"清EEPORM中最近一次清需时间，最近一次编程时间"*/
for(uni = 0; uni < sizeof(struct DATEANDTIME_DEF); uni++)
{
 *((unsigned char *)&Other_Data.ProgramDate + uni)=0;
 *((unsigned char *)&Other_Data.LastClearDemandDateCM + uni)=0;
}
 
 WRLC256(PROGRAMDATE_ROM, (unsigned char *)&Other_Data.ProgramDate,2 * sizeof(struct DATEANDTIME_DEF),0,0);

 

/*"清预付费事件记录相关内容"*/
/*"清次数"*/
for(uni = 0; uni < 9; uni++)
{
*((unsigned long *)&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks + uni) = 0;
}
WRLC256(FARCONTROLEVENT_EE, (unsigned char *)&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks, 36, 0, 0);

/*"索引指针特殊处理"*/
for(uni = 1; uni < LENGTH_PAY_FOR_EVENT_POINT-1; uni++)
{
*((unsigned char *)&Pay_For_Event_Point.Buy_Event_P+ uni) = EVENT_CLAER_STATUS;
}
WRLC256(PAY_FOR_EVENT_POINT_EE, (unsigned char *)&Pay_For_Event_Point, LENGTH_PAY_FOR_EVENT_POINT, 0, 0);

/*"时差数据清零"*/
WRLC256(RELAYERR_AREA_EE,0,29,0,0);

 CloseOverPowerAlarmSwitch();

}
/*"=============================================================="*/
/*"函数说明：事件记录后续文件清零处理接口函数，当判断索引为特殊值时"*/
/*"                           清除相应的事件记录文件"*/
/*"输入参数：事件数据标识"*/
/*"输出参数：无"*/
/*"函数调用：通信抄读或显示事件数据、上电清事件文件接口函数中"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void ClearEventCommDeal(unsigned long eventID)
{
  unsigned char uni;
  const struct CLEAREVENT_STRU *Event_Node1;
  unsigned char search_ok = 0;
  unsigned long tempidmask;
  unsigned char dealkind;
  unsigned int  filename;
  unsigned char *eventp;
  unsigned int  eventpaddr;
  
  dealkind=0;
  filename=0;
  eventpaddr=0;

  if(IntoPowerDownFlag == 0xff)/*"为防止低功耗显示进入，导致只清清零标识，不清FLASH中数据问题"*/
  {
    return;
  }
  
  for(uni = 0; uni < ((sizeof(Clearevent_ID)) / sizeof(unsigned long)); uni++)         
  {
  	tempidmask=0xffffff00;
  	if((Clearevent_ID[uni] & 0x0000ff00) == 0x0000ff00)
  	{
  	   tempidmask=0xffff0000;
  	}
  	
    if((Clearevent_ID[uni] & tempidmask) == (eventID & tempidmask))
    {
       Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[uni];
       search_ok = 0xff;
       break;
    }
  }

if(search_ok == 0xff)/*"查找数据标识成功"*/
{
  if((Event_Node1->Pointer) != NULL)/*"事件指针不为空"*/
  {
    if((*(Event_Node1->Pointer)) == EVENT_CLAER_STATUS)/*"事件指针为清零状态，需清除事件FLASH中保存数据"*/
    {
      CheckPowerDown();
      Delete_File(Event_Node1->Filename_begin);
      *(Event_Node1->Pointer) = 0;
      WRLC256((Event_Node1->Pointer_addr),0,1,0,0);
    }
  }
}
else
{
	CheckPowerDown();
	/*"清事件事件记录没在列表中，需特殊处理"*/
	switch(eventID & 0xffffff00)
	{
		case 0x03300300:
		 dealkind=1;
     filename=CLEAREVENTRECORD_BEGINFILE;
     eventp=&Event_Meter_Pro_Pointer.ClearEventRecord_P;
     eventpaddr=CLEAREVENTRECORD_P_ROM;
		break;
		
		case 0x03300500:
		 dealkind=1;
     filename=PROGDAILYSLOTRECORD_BEGINFILE;
     eventp=&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
     eventpaddr=PROGDAILYSLOTRECORD_P_ROM;
     if(Event_Meter_Pro_Pointer.ProgDailySlotRecord_P == EVENT_CLAER_STATUS)
     {
       Delete_File(PROGDAILYSLOTRECORD_BEGINFILE+32L);
       Delete_File(PROGDAILYSLOTRECORD_BEGINFILE+64L);
     }
		break;
	}
	if(dealkind==1)
	{
		if(*eventp == EVENT_CLAER_STATUS)
    {
      Delete_File(filename);
      *eventp = 0;
      WRLC256(eventpaddr,eventp,1,0,0);
    }
	}
}
}
/*"=============================================================="*/
/*"函数说明：上电事件、冻结文件清零接口函数"*/
/*"                           上电时判断事件、冻结索引为特殊值时，需进行文件清零"*/
/*"输入参数：无"*/
/*"输出参数：无"*/
/*"函数调用：上电初始化，在事件、冻结索引初始化完成后调用"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void ClearEventDataPowerOn(void)
{
unsigned char uni = 0;

for(uni = 0; uni < ((sizeof(Clearevent_ID)) / sizeof(unsigned long)); uni++)
{
ClearEventCommDeal(Clearevent_ID[uni]);
}
ClearEventCommDeal(0x03300500);
ClearEventCommDeal(0x03300300);

for(uni = 0; uni < ((sizeof(Clearfreeze_ID)) / sizeof(unsigned long)); uni++)
{
ClearFreezeCommDeal(Clearfreeze_ID[uni]);
}
}
/*"=============================================================="*/
/*"函数说明：事件、冻结发生时事件、冻结文件清零接口函数"*/
/*"                           判断事件、冻结索引为特殊值时，需进行文件清零"*/
/*"输入参数：pEventPoint 事件、冻结存储索引指针"*/
/*"                           begin_file 事件、冻结存储起始文件名"*/
/*"输出参数：无"*/
/*"函数调用：事件、冻结发生时调用"*/
/*"返    回：无  "*/
/*"作    者：GANJP  版本：1.00"*/
/*"================================================================"*/
void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file)
{
if((*pEventPoint) == EVENT_CLAER_STATUS)/*"事件需要清零"*/
	{
	if(begin_file == PROGDAILYSLOTRECORD_BEGINFILE)
	{
		Delete_File(PROGDAILYSLOTRECORD_BEGINFILE);
		Delete_File(PROGDAILYSLOTRECORD_BEGINFILE + 32l);
		Delete_File(PROGDAILYSLOTRECORD_BEGINFILE + 64l);
	}
	else if (begin_file == E_BURSE_EVENT_FILE)	/*"剩余金额日冻结有96个文件"*/
	{
		Delete_File(E_BURSE_EVENT_FILE);
		Delete_File(E_BURSE_EVENT_FILE + 32L);
		Delete_File(E_BURSE_EVENT_FILE + 64L);
	}
	else
	{
		Delete_File(begin_file);
	}
	*pEventPoint = 0;
	}
}



void Rst90E36Event(void)
{
	unsigned char i;
	
	if(rst90e36info.totalnum<_rMeter_State_Buffer.wRstCnt)
	{
		rst90e36info.totalnum=_rMeter_State_Buffer.wRstCnt;
		
		switch(_rMeter_State_Buffer.bRstType)
		{
			case METER_RST_TYPE_PRAERR:
			  rst90e36info.praerrnum++;
			break;
			
			case METER_RST_TYPE_RDERR:
			  rst90e36info.rderrnum++;
			break;
			
			case METER_RST_TYPE_VALERR:
			  rst90e36info.valerrnum++;
			break;
		}
	}
	
	if(rst90e36info.beginflag==0)
	{
		if(((rst90e36info.praerrnum+rst90e36info.rderrnum+rst90e36info.valerrnum)>0))
		{
			rst90e36info.beginflag=1;
			rst90e36info.counter=0;
			for(i=0;i<5;i++)
			{
				rst90e36info.time[i]=*((unsigned char *)&softdate+i);
			}
		}
	}
	else
	{
		rst90e36info.counter++;
		if(rst90e36info.counter>3600)
		{
			rst90e36info.beginflag=0;
			
			FeedWatchdog();
  	  Event_Meter_Pro_Pointer.Rst90E36_P=(Event_Meter_Pro_Pointer.Rst90E36_P+1)%RST90E36_EVENT_NUMBER;
      Write_File((RET90E36_EVENT_FILE+Event_Meter_Pro_Pointer.Rst90E36_P),0,11,&rst90e36info.time[0]);
      WRLC256(RST90E36_P_ROM,&Event_Meter_Pro_Pointer.Rst90E36_P,1,0,0);
      
      Event_Meter_Pro_Times.Rst90E36_Times=Event_Meter_Pro_Times.Rst90E36_Times+rst90e36info.praerrnum+rst90e36info.rderrnum+rst90e36info.valerrnum;
      WRLC256(RST90E36_TIMES_ROM,(unsigned char *)&Event_Meter_Pro_Times.Rst90E36_Times,4,0,0);
      
	    for(i=0;i<11;i++)
	    {
	    	*(&rst90e36info.time[0]+i)=0;
	    }
		}
	}
	
}

unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times)
{
    if((*(EventReport_times))<255)
	{
           (*(EventReport_times))+=1;
	}
    else
	{
          (*(EventReport_times))=255;
	}
     WRLC256(Times_Addr,(unsigned char *)EventReport_times,1,0,0);
}

void Save_Event_StartData_Flash(unsigned char *eventp,unsigned int eventpaddr,
                                unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                                unsigned long *eventtimes,unsigned int eventtimesaddr)
{
	ClearEvent_EventBegin(eventp,filename);		
	(*eventp)=((*eventp)+1)%32;
	filename=filename+(*eventp);
  PrepEvent0Data(datakind);
	Write_File(filename,filestartaddr,fileendaddr,&Co.b[300]);
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
}

void Save_Event_EndData_Flash(unsigned char eventp,
                              unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                              unsigned long *eventtimeticks,unsigned int eventtimeticksaddr)
{
	if(eventp>31)
		eventp=0;
	filename=filename+eventp;
	PrepEvent0Data(datakind);
	Write_File(filename,filestartaddr,fileendaddr,&Co.b[300]);
	SaveEvent0LastTime_Other(eventtimeticksaddr,eventtimeticks);
}

void Save_Record_Data_Flash(unsigned char *eventp,unsigned int eventpaddr,
                            unsigned int filename,unsigned char fileendaddr,
                            unsigned long *eventtimes,unsigned int eventtimesaddr)
{
	FeedWatchdog();
	ClearEvent_EventBegin(eventp,filename);		
	(*eventp)=((*eventp)+1)%32;
	filename=filename+(*eventp);
	Write_File(filename,0,fileendaddr,&Co.b[400]);
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
	FeedWatchdog();
}

void Save_Event_StartData_Eeprom(unsigned char *eventp,unsigned int eventpaddr,
                                 unsigned int eepromaddr,unsigned char len,
                                 unsigned long *eventtimes,unsigned int eventtimesaddr)
{		
	WRLC256(eepromaddr,&Co.b[300],len,0,0);
	(*eventp)=((*eventp)+1)%32;
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
	FeedWatchdog();
}

