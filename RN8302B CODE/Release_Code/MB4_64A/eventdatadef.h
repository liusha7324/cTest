#ifndef _EVENTDATADEF_H_
#define _EVENTDATADEF_H_

struct  BREAKPHASE_DATA    
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};            
           
struct  LOSTVOLTAGE_DATA               
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][6]; //total/a/b/c * Plus_Active/Nega_Active/Quad_Reactive[4]
        unsigned long amph[3];      //a/b/c ample*hour
};
          
struct  TOTALLOSTVOLTAGE_DATA  
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  LOSTCURRENT_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][6]; //total/a/b/c * Plus_Active/Nega_Active/Quad_Reactive[4]
};
          
struct  TOTALLOSTCURRENT_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  POWERREVERSE_DATA              
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][2]; //total/a/b/c * Plus_Active/Nega_Active/Quad_Reactive[4]
};

	           
struct  VOLTAGECHECK_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char  voltage[3];
};

struct CURRENTIMBALANCE_DATA
{
	    unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[2]; // Plus_Active/Nega_Active
};          
     
struct  OVERPOWERALARM_DATA             
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char power[3];
};

struct  OVERPOWERCLOSESWITCH_DATA        
{
        unsigned char begindate[5];
        unsigned char power[3];
};

struct  OVERVISUALPOWER_DATA             
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char power[3];
};

struct  ENERGYCLEAR_DATA                 
{
        unsigned char begindate[5];
        unsigned long energy[6][9];
        
};

struct  DEMANDCLEAR_DATA                 
{
        unsigned char begindate[5];
        unsigned long demand[4];  //Plus_Active/Nega_Active/Quad_Reactive[4]
        unsigned char demandtime[4][5]; 
        unsigned char flag;
};

struct  LOSSVOLTAGELOSSCURRENTCLEAR_DATA 
{
        unsigned char begindate[5];
};

struct  LOSSVOLTAGECHECKHEALTHCLEAR_DATA 
{
        unsigned char begindate[5];
};

struct  UPDAWNPOWER_DATA                 
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  RESETCPU_DATA                    
{
        unsigned char begindate[5];
};

struct  SETPRIMARY_DATA                  
{
        unsigned char begindate[5];
        unsigned long energy[MAXTRIFF]; //total/a/b/c * Plus_Active/Nega_Active/Quad_Reactive[4]
        unsigned long energy1[MAXTRIFF]; //total/a/b/c * Plus_Active/Nega_Active/Quad_Reactive[4]
        unsigned char mode;
};
struct SETREACTIVEPRIMARY_DATA
{
        unsigned char begindate[5];
        unsigned long energy[4]; 
};

struct  PROGRAMME_DATA                  
{
        unsigned char begindate[5];
        unsigned char flag1;
        unsigned char flag2;
};

struct  OPENUPCOVER_DATA                               
{
        unsigned char begindate[5];
};

struct  CLOCKBATTERY_DATA               
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  DISPLAYBATTERY_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  ADJUSTCLOCK_DATA              
{
        unsigned char beforedate[5];
        unsigned char afterdate[5];
        
};

struct  RUNCLOCKERROR_DATA              
{
        unsigned char begindate[5];
        unsigned char beforedate[5];
        unsigned char flag;
};

struct  POWERUPCLOCKERROR_DATA          
{
        unsigned char begindate[5];
        unsigned char beforedate[5];
        unsigned char flag;
};

struct  ADJUSTENERGY_DATA             
{
        unsigned char begindate[5];
        unsigned char flag;
        unsigned long energy[2][6][MAXTRIFF];
};

struct  EEPROMERR_DATA                   
{
        unsigned char begindate[5];
        unsigned char flag;
};

struct  ADJUSTMETER_DATA  
{
        unsigned char begindate[5];
        unsigned char flag;
};
struct  VOLTAGERESERVE_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  FREEZEDATA_SD_DATA
{
	   unsigned char begindate[5];
	   unsigned long energy[6];
};
struct  FREEZEDATA_ZhiDing_DATA  //mw added 070510
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};
struct  FREEZEDATA_ShunShi_DATA  //mw added 070510
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};
struct  FREEZEDATA_YueDing_DATA  //mw added 070510
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};

//----------------------  New 645  ------------------------//
//-------------------------  LostVoltage DataStruct  -------------------------//
struct LostVoltageEvent_Data
{
	unsigned long beginvolt[3];
	signed long begincurr[3];
	signed long beginactivepower[3];
	signed long beginreactivepower[3];
	signed long beginfactor[3];
	unsigned long eventenergy[4][6];
	unsigned long eventamph[3];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct LostVoltageCard_Data
{
	struct LostVoltageEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
//-------------------------  LostVoltage DataStruct  -------------------------//

//-------------------------  Power Down DataStruct   --------------------------//
struct PowerDownEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];	
};
//-------------------------  Power Down DataStruct   --------------------------//

//------------------------   Programme DataStruct    --------------------------//
struct ProgrammeEvent_Data
{
	unsigned char begintime[6];
	unsigned long mancode;
	unsigned long datacode[10];	
};
//------------------------   Programme DataStruct    ---------------------------//

//------------------------   Open Cover DataStruct   ---------------------------//
struct OpenCoverEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long beginenergy[6];
	unsigned long endenergy[6];	
};
//------------------------   Open Cover DataStruct   ---------------------------//

//------------------------   Voltage Statistic DataStruct  ----------------------//
struct VoltStatistic_Data
{
	unsigned long checktime[4];  //0-have power time 1-ok time 2-upvolt time 3-downvolt time
	unsigned long checkvolt[2];  //0-min volt 1-max volt
	unsigned char checkvolttime[2][6];  //0-min volt time  1-max volt time
	unsigned long voltratebcd[2];  //0-ok rate 1-no ok rate
	unsigned int  checkvoltbcd[2];  //0-min volt 1-max volt	
};
//------------------------   Voltage Statistic DataStruct  ----------------------//

//------------------------   LostCurrent DataStruct   ---------------------------//
struct LostCurrentEvent_Data
{
	unsigned long beginvolt[3];
	signed long begincurr[3];
	signed long beginactivepower[3];
	signed long beginreactivepower[3];
	signed long beginfactor[3];
	unsigned long eventenergy[4][6];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct LostCurrentCard_Data
{
	struct LostCurrentEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
//------------------------   LostCurrent DataStruct   ---------------------------//

//-------------------------  Voltage Reverse DataStruct  ------------------------//
struct VoltReverseEvent_Data
{
	unsigned long eventenergy[4][6];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct VoltReverseCard_Data
{
	struct VoltReverseEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
//-------------------------- Voltage Reverse DataStruct  ------------------------//

//--------------------------- Over Demand DataStruct      ----------------------------//
struct OverDemandEvent_Data
{
	unsigned long maxdemand;
	unsigned char maxdemandtime[5];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};
//--------------------------- Over Demand DataStruct     -----------------------------//
//--------------------------- Phase3 LostVolt DataStruct  ----------------------------//
struct Phase3LostVoltEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	signed long begincurr;	
};
//--------------------------- Phase3 LostVolt DataStruct  ----------------------------//
//--------------------------- OverDemandAlarm DataStruct  ----------------------------//
struct OverDemandAlarmEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long begindemand[2];	
};
//--------------------------- OverDemandAlarm DataStruct  ----------------------------//
//--------------------------- ClockBattery DataStruct     ----------------------------//
struct ClockBatteryEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];	
};
//--------------------------- ClockBattery DataStruct     ----------------------------//
//--------------------------- CurrImBalance DataStruct    ----------------------------//
struct CurrImBalanceEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long eventenergy[4][6];
	unsigned long maximbalancerate;	
};

struct CurrImBalanceCard_Data
{
	unsigned char passzerotimes[6];
	struct CurrImBalanceEvent_Data eventdata;
	unsigned char eventcs;	
};
//--------------------------- CurrImBalance DataStruct    ----------------------------//
//----------------------  New 645  ------------------------//
#endif            
 