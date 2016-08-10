/***************************************************
*         event.h                                  *
*                                                  *
***************************************************/ 
#ifndef  _event_h_
#define  _event_h_
typedef unsigned char (*TSave_General_Event)(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char *tempdatep);
typedef unsigned char (*TSpec_Event)(unsigned int Card_Addr,		//Address in FM24C256
							 		unsigned char *DataPointer,	//DataPointer-->Data Address to be written
						 	 		unsigned int Data_Length,		//Data length to be written
						 	 		unsigned char DeviceName,		//DeviceName=0:FM24C256_1,1:FM24C256_2,2:FM24C256_3
						 	 		unsigned char OperationType);
typedef unsigned char (*TGeneral_Event)(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
extern unsigned  char Clear_Demand_Mode;
//------ New 645 Variable Declaration  ------//
extern unsigned char EventEnergyValid_Flag;
extern unsigned long Event_AmpHour[3];
extern unsigned char EventCriticalVoltage_Flag;
extern unsigned char TempEventData[400];
extern unsigned long lostvoltenergyall[2];
extern unsigned long lostvoltenergy[6];
//extern unsigned long lostvoltenergyreaddata[6];
//extern unsigned char Phase3LostVoltTimeValidFlag;
//------ New 645 Variable Declaration  ------//

//extern unsigned char Event(unsigned char);  //change by pc 081129
//extern void Event1(unsigned long);  //change by pc 081214
extern void EventTimeAdd(void);
//extern void ReadyDataForFreeze(unsigned char );  //change by pc 081214
//------ New 645 Function Declaration  ------//
extern void New2007_Event(void);
extern void EventRecordAdjustEnergy(void);
extern void EventData_PowerDown_Save(void);
extern unsigned char EventData_PowerOn_Check(void);
extern unsigned char EventRecord_Poweron_Check(void);
extern void PowerDownEvent_OnCheck(void);
extern unsigned int ProgrammeEvent(unsigned long,unsigned long);
extern unsigned int ClearMeterRecord(unsigned long);
//extern void OpenCoverEventCheck(void);
extern void VoltStatSetDefault(void);
extern void VoltStatInit(void);
extern void VoltStatisticCheck(void);
extern void OverDemandEvent(void);
extern unsigned int AdjustTimeRecord(unsigned long);
extern unsigned int ClearDemandRecord(unsigned long);
extern unsigned int ProgWeekRecord(unsigned long,unsigned char);
extern unsigned int ProgAEModeRecord(unsigned long,unsigned char);
extern unsigned int ProgNEMode1Record(unsigned long,unsigned char);
extern unsigned int ProgNEMode2Record(unsigned long,unsigned char);
extern unsigned int ProgBillDayRecord(unsigned long,unsigned char *);
extern unsigned int ProgYearSlotRecord(unsigned long);
extern unsigned int ProgDailySlotRecord(unsigned long);
//extern void ProgHolidayRecord(unsigned long);
extern unsigned char ClearNewEventRecord(unsigned long,unsigned long);
//extern void AdjustMeterEvent(unsigned char);
extern int   PrepVoltStatReadData(void);
extern void ResetCpuEvent_OnCheck(void);
extern void RunClockErrorRecord(void);
extern void PowerUpClockErrorRecord(void);
extern void EepromErrorRecord(void);
extern void EnergyPassZeroRecord(void);
//extern void PdSaveImBalanceData(void);
extern void SetPrimaryRecord(void);
extern void EepromEventSetDefault(void);
//extern unsigned char PrepFirstEventData(unsigned long);
//extern void PowerDownSaveMaxCurr(void);
extern void EMeterPowerdownRecord(void);
extern unsigned int ClearEventRecord(unsigned long,unsigned long);
extern unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,
															unsigned char  progoldvaluep,unsigned char sort);
extern void OpenBoxCoverEvent_Check(void);
extern void EventFlagPowerOnInit(void);
extern void ProgrammeEventEnd_Check_Payment(void);
extern void ProgrammeEventEnd_Check(void);
extern void VoltStatisticFunc(void);
extern void AdjustMeterRecord(void);
extern unsigned char PrepNewFirstEventData(unsigned long);
extern unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times);
extern unsigned long  Prepare_For_EventLastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer);
//extern unsigned char Refresh_EventData_ForLastTime(unsigned long eventcode);
extern void Refresh_EventData(unsigned long eventcode);
extern unsigned char Refresh_AddTime(unsigned long eventcode);
extern void ClearEventDate_BatteryPowerOn(void);
extern int PrepLostVoltEnergyData(unsigned long);

extern void PowerAbnormalEventCheck(void);

extern void ClockBatteryDisplayBattery_Event(void);

extern void PdOpenCoverCheckInit(unsigned char);
extern void PdOpenCoverCheck(void);
extern void PdOpenCoverCheckPowerUpDeal(void);

extern void ClearEventAll(void);
extern void ClearEventCommDeal(unsigned long eventID);
extern void ClearEventDataPowerOn(void);
extern void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file);

//------ New 645 Function Declaration  ------//

extern union  BYTE_BIT VoltCheck_N[3][2];
extern struct VoltStatistic_Data VoltStat[4];
//ganjp 20090702
//extern void OpenBoxEvent_B(void);
//extern void OpenBoxEvent_S(void);
extern const unsigned long Clearevent_ID[74];

extern struct	PDOPENCOVER_STRUCTURE  pdopencovercheckdata[2];

extern union EVENTSTATUS eventstatusinfo;

extern unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times);
#endif
/**************************************************/

 
