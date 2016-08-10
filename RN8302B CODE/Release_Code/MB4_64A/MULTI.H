#ifndef _MULTI_H
#define _MULTI_H

struct ENERGY_BACK
{
    	    unsigned long  Plus_Active[MAXTRIFF]; 
	    unsigned long  Nega_Active[MAXTRIFF];
	
	    unsigned long  Quad_Reactive[4][MAXTRIFF];
}; 
extern unsigned char TRAFF_RATE;
extern unsigned char OLD_TRAFF_RATE;
extern unsigned char ErrEnergyNumber;
extern unsigned char WriteEE_Or_F;    /*"数据备份时写EE还是写铁电"*/
extern struct ENERGY_BACK  energy_back;
extern unsigned char ClockBatteryClear_Flag[8];  //add by pc 090116
extern unsigned char ClockBatteryClearCounter;
extern unsigned char TempClockBatteryClearCounter;  //add by pc 090302

extern unsigned char Light_Back_Up_Flag;/*"背光点亮标志，0:按键，FF:红外"*/
extern unsigned char   Event_Report_flag;/*"需进行事件上报标志，0 不需要上报 0xff 有事件需要上报"*/
extern unsigned char   open_cover_reported;/*"eventout已经主动上报开盖事件，开盖事件重新发生前不重复上报"*/
extern unsigned char RamData_Valid_flag[16];
extern union EVENT_REPORT_STATUS  Event_Report_Status;
extern struct EVENT_REPORT_STATUS_TIMES Event_Report_Status_Times;/*"事件上报期间，事件发生的次数"*/
extern union EVENTSTATUS_FLAG EventStatus_flag;
extern union EVENT_REPORT_STATUS  Event_Report_Status_Backup;
extern union EVENT_REPORT_STATUS  Event_Report_Status_communication;
extern unsigned char   Event_Report_Iterate_flag;
extern unsigned int  powerup_init_time;

extern void PowerUpProcese(void);
extern void FeedWatchdog(void);
extern void CheckPowerDown(void);
extern void Measure(void);
extern void OpenCoverCheck(void);
//extern void Clear_Bill(void);
//extern void Bill(void);
extern void ReadRTC(void);
extern void BackupDataToEeprom(void);
extern void FindTriff(void);
extern unsigned char BackUpEnergyToRam(void);
extern unsigned char  CheckRamTime(void);
extern void Monitor_Program(void);
extern void Light_Back_Led(void);
extern void Close_Back_Light(void);
//extern void CheckTriffDateChange(unsigned char ); 
extern void CheckChange(unsigned char kind,unsigned char type );//add by zlp
extern void CheckState(void);
extern void FreezeData_All(unsigned char ,unsigned char );
extern signed long Cal_EnergyLimit(void);
//extern void CheckDailySlotDateChange(unsigned char ); 
//extern void Record_HDFreeze(void); 
//extern void Day_freeze(void);
//extern void Clear_HDFreezeData(void);
extern void Bill_New(void);
extern unsigned char Check_Billdate_Validity(unsigned char* date,unsigned char number);
extern void RailEnergyValidity(void);//add by zlp
extern void CheckState_New645(void);//Fuxf add 20081114
extern void PowerUpLossTotalVoltage(void);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

extern void Meter_Para_Check(void);
extern void Check_If_Clear_all(void);
extern void ClearClockBatteryTime(void);  //add by pc 090116
extern unsigned char IsChangeBattery(void);//add by zlp
extern unsigned char  LastMouthDayNumber(void);//add by zlp
extern unsigned char ISAutoBillDay(void);//add by zlp

extern unsigned int CRC(unsigned char *startaddr, unsigned int len);
//extern void Open_Rail_Cover_Check(void);//ganjp 20090702
extern void Meter_Staut_Check_And_Count(void);///king chen add 121214

extern void Event_Report_Status_Chk(unsigned char kind);
extern void Get_Event_Report_Status(union EVENT_REPORT_STATUS *EventReportStatus);

extern void Clear_ALLEventReportInfo_NO_ACK(void);
extern void EventReportState_Expand(unsigned char Nbyte, unsigned char n,unsigned char State);
extern void ESAM_ErrReport(void);
extern void SwitchOn_Report(void);
extern void SwitchOff_Report(void);
extern void Overdraft_Report(void);
#endif
