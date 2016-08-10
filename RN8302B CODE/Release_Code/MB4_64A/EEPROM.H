/*********************************************************************************************
*                      fine: eeprom.h                                                        *
*                      size: 21355 bytes                                                     *
**********************************************************************************************/  



#ifndef _EEPROM_H_
#define _EEPROM_H_
//---------eeprom total define---------------------------------
//10 byte
#define     BEGIN_ROM                            0
//216
#define     PRIMARYDATA_ROM											 BEGIN_ROM+10
//14*3=42
#define     YEARSLOT_ROM                         PRIMARYDATA_ROM+24*9    
//8*14*3=336
#define     DAILYSLOT_ROM                        YEARSLOT_ROM+sizeof(struct YEARSLOT)
//254*4=1016
#define     HOLIDAYSLOT_ROM                      DAILYSLOT_ROM+sizeof(struct DAILYSLOT)
//42
#define     YEARSLOT2_ROM                        HOLIDAYSLOT_ROM+sizeof(struct HOLIDAYSLOT)
//336
#define     DAILYSLOT2_ROM                       YEARSLOT2_ROM+sizeof(struct YEARSLOT)
//10*99=990
#define     CYCLEDISPLAYTABLE_A_ROM              DAILYSLOT2_ROM+sizeof(struct DAILYSLOT)
//10*99=990
#define     CYCLEDISPLAYTABLE_B_ROM              CYCLEDISPLAYTABLE_A_ROM+sizeof(struct CYCLEDISPLAYTABLE_A)
//10
#define     EEPROM_FLAG_ROM                      CYCLEDISPLAYTABLE_B_ROM+sizeof(struct CYCLEDISPLAYTABLE_B)
//205
#define     OTHER_DATA_ROM                       EEPROM_FLAG_ROM+10 
//296*14 = 4144
#define     ENERGY_RECORD_ROM                    OTHER_DATA_ROM+sizeof(struct OTHER_DATA)
//6*9*9*14 = 6804
#define     DEMAND_RECORD_ROM                    ENERGY_RECORD_ROM+sizeof(struct ENERGY_RECORD)*MAXMONTHSAVE 
//14*4
#define     MONTH_BILL_NUM_ROM                  DEMAND_RECORD_ROM+sizeof(struct DEMAND_RECORD)*MAXMONTHSAVE  ///king chen add 130312
//296+486 = 782                  
#define     THIS_MONTH_DATA_ROM                MONTH_BILL_NUM_ROM +4*MAXMONTHSAVE 
//14                 
#define     FS_FLAG_START                        THIS_MONTH_DATA_ROM+sizeof(struct THIS_MONTH_DATA_EEPROM)
//8000
#define     FILE_INDEX_LEN                       FS_FLAG_START+14           
//990
#define     SHOW_POWERDOWN_CYC_DATA_ROM          (FILE_INDEX_LEN+492*6L)
////990
#define     SHOW_POWERDOWN_KEY_DATA_ROM          SHOW_POWERDOWN_CYC_DATA_ROM+sizeof(struct Show_Powerdown_Data_Struct)*99
//21
#define     OTHER_METER_PARAMETER_ROM          SHOW_POWERDOWN_KEY_DATA_ROM+sizeof(struct Show_Powerdown_Data_Struct)*120 // (FILE_INDEX_LEN+492*6L)
//296
#define     F_ENERGY_RECORD                      OTHER_METER_PARAMETER_ROM+sizeof(struct OTHER_METER_PARAMETER)
//128
#define     POWERDOWN_SAVE_DATA_ROM              F_ENERGY_RECORD+sizeof(struct ENERGY_RECORD)+ (64 - (F_ENERGY_RECORD+sizeof(struct ENERGY_RECORD))%64)
//ENERGY RAIL DATA 110
#define     ENERGY_RAIL_DATA_ROM                 POWERDOWN_SAVE_DATA_ROM+sizeof(struct POWERDOWN_SAVE_DATA)
//64                                 
#define     EVENT_POWER_NET_POINTER_ROM          ENERGY_RAIL_DATA_ROM+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        
//35                                   
#define     EVENT_METER_PRO_POINTER_ROM          EVENT_POWER_NET_POINTER_ROM+sizeof(struct EVENT_POWER_NET_POINTER)     
//240                                                                                                                  
#define     EVENT_POWER_NET_TIMES_ROM            EVENT_METER_PRO_POINTER_ROM+sizeof(struct EVENT_METER_PRO_POINTER)     
//140                                                                                                                  
#define     EVENT_METER_PRO_TIMES_ROM            EVENT_POWER_NET_TIMES_ROM+sizeof(struct EVENT_POWER_NET_TIMES)         
//256                                                                                                                
#define     EVENT_POWER_NET_TIMETICKS_ROM        EVENT_METER_PRO_TIMES_ROM+sizeof(struct EVENT_METER_PRO_TIMES)  
//3
/*"事件总清零的时候下面内卡数据采用分块清零，内卡结构改变时需注意ClearEventAll函数中相关处理"*/
#define     LASTLOSTVOLT_A_ROM                   EVENT_POWER_NET_TIMETICKS_ROM+sizeof(struct EVENT_POWER_NET_TIMETICKS)
//42+3*48+12= 198
#define     LASTLOSTVOLT_B_ROM             LASTLOSTVOLT_A_ROM+255L
#define     LASTLOSTVOLT_C_ROM             LASTLOSTVOLT_B_ROM+255L
#define     LASTOPENCOVEREVENT_ROM         LASTLOSTVOLT_C_ROM+255L
#define     LASTOPENBOXEVENT_ROM           LASTOPENCOVEREVENT_ROM+60L
#define     LASTPHASE3LOSTVOLT_ROM         LASTOPENBOXEVENT_ROM+60L
#define     LASTPOWERDOWNEVENT_ROM         LASTPHASE3LOSTVOLT_ROM+16L
#define     LASTPROGRAMME_ROM                     (LASTPOWERDOWNEVENT_ROM+12L)
#define     LASTLOSTVOLTBEGINTIME_A_ROM          LASTPROGRAMME_ROM+50L
#define     LASTLOSTVOLTENDTIME_A_ROM            LASTLOSTVOLTBEGINTIME_A_ROM+6
#define     LASTLOSTVOLTBEGINTIME_B_ROM          LASTLOSTVOLTENDTIME_A_ROM+6
#define     LASTLOSTVOLTENDTIME_B_ROM            LASTLOSTVOLTBEGINTIME_B_ROM+6
#define     LASTLOSTVOLTBEGINTIME_C_ROM          LASTLOSTVOLTENDTIME_B_ROM+6
#define     LASTLOSTVOLTENDTIME_C_ROM            LASTLOSTVOLTBEGINTIME_C_ROM+6

#define     LOSTVOLTENERGY_A_ROM                 LASTLOSTVOLTENDTIME_C_ROM+6
#define     LOSTVOLTENERGY_B_ROM                 LOSTVOLTENERGY_A_ROM+8
#define     LOSTVOLTENERGY_C_ROM                 LOSTVOLTENERGY_B_ROM+8

#define     OVERDEMANDMAXDEMAND_ROM              LOSTVOLTENERGY_C_ROM+8
#define     MAXCURRIMBALANCERATE_ROM             OVERDEMANDMAXDEMAND_ROM+sizeof(struct DEMAND_DATA_FORM)*6L
#define     MAXVOLTIMBALANCERATE_ROM             MAXCURRIMBALANCERATE_ROM + 4
#define     MAXCURRFARIMBALANCERATE_ROM          MAXVOLTIMBALANCERATE_ROM + 4
#define     LOSTVOLTAGETIME                      MAXCURRFARIMBALANCERATE_ROM + 4
#define     VOLTSTATISTICDATA_A_ROM              LOSTVOLTAGETIME+6L
#define     VOLTSTATISTICDATA_B_ROM              VOLTSTATISTICDATA_A_ROM+sizeof(struct VoltStatistic_Data)
#define     VOLTSTATISTICDATA_C_ROM              VOLTSTATISTICDATA_B_ROM+sizeof(struct VoltStatistic_Data)
#define     VOLTSTATISTICDATA_T_ROM              VOLTSTATISTICDATA_C_ROM+sizeof(struct VoltStatistic_Data)

#define     EVENTSTATUS_FLAG_ROM             VOLTSTATISTICDATA_T_ROM+sizeof(struct VoltStatistic_Data)+64L

#define     EVENT_REPORT_STATUS_ROM      EVENTSTATUS_FLAG_ROM+sizeof(union EVENTSTATUS_FLAG)

#define     EVENT_REPORT_STATUS_BACKUP_ROM    EVENT_REPORT_STATUS_ROM + sizeof(union EVENT_REPORT_STATUS)

#define     EVENT_REPORT_STATUS_COMM_ROM       EVENT_REPORT_STATUS_BACKUP_ROM+sizeof(union EVENT_REPORT_STATUS)

#define     EVENT_REPORT_STATUS_TIMES_ROM     EVENT_REPORT_STATUS_COMM_ROM+sizeof(union EVENT_REPORT_STATUS)

#define     GLOADRECORD_ROM                      (EVENT_REPORT_STATUS_TIMES_ROM+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)

#define     BAKBLOCKADDRESS_ROM                  GLOADRECORD_ROM+BLOCKADDRESSLEN+FIRSTFLAGLEN+LOADRECORDFLAGLEN+64L 
#define     FREEZEDATA_PERIOD_ROM                BAKBLOCKADDRESS_ROM+BLOCKADDRESSLEN+64L  
#define     LOADRECORD_DAYINDEX_Y          FREEZEDATA_PERIOD_ROM+13*254L+64L
#define     LOADRECORD_DAYINDEX_H                LOADRECORD_DAYINDEX_Y + 366
#define     F_EEPROM_FLAG_ROM                    LOADRECORD_DAYINDEX_H + 366*3 +64L

#define     END_ROM1                             0x7fe0 //24c256 max addr is 0x7fff
//128
#define     JUSTMETER_PARA_ROM                   END_ROM1 - sizeof(struct JUSTMETER_PARAMETER)
//614
#define     METER_PARAMETER_ROM  							   JUSTMETER_PARA_ROM - sizeof(struct METER_PARAMETER)
//1024
#define     PAY_EEPROM_DEFINE_EE                 METER_PARAMETER_ROM-LENGTH_PAY_EEPROM_DEFINE //payment

 


/********************************************************************************************************************/
//------------------BLOCK ADDR DEFINE-----------------
/********************************************************************************************************************/

//-------OTHER_DATA---------
#define     BATTERYWORKTIME1_ROM                 OTHER_DATA_ROM             
#define     BATTERYWORKTIME2_ROM                 BATTERYWORKTIME1_ROM+4    

#define     PASSWORDERR_ROM                      BATTERYWORKTIME2_ROM+4 
#define     CLEAR_PASSWORDERR_FLAG_ROM           PASSWORDERR_ROM+MAX_PASS_NUM*sizeof(struct PASSWORDERR) 
#define     LASTCLEARDEMANDDATE_ROM              CLEAR_PASSWORDERR_FLAG_ROM+1

//#define     LASTCLEARDEMANDDATE_ROM              BATTERYWORKTIME2_ROM+4 

          
#define     LASTJUSTTIME_ROM                     LASTCLEARDEMANDDATE_ROM+sizeof(struct DATEANDTIME_DEF)  
#define     JUSTTIMESADD_ROM				             LASTJUSTTIME_ROM+sizeof(struct DATEANDTIME_DEF)    
#define     PROGRAMDATE_ROM                      JUSTTIMESADD_ROM+1  
#define     LASTCLEARDEMANDDATECM_ROM            PROGRAMDATE_ROM+sizeof(struct DATEANDTIME_DEF)    
#define     COMMCLEARFLAGCURREE_ROM				       LASTCLEARDEMANDDATECM_ROM+sizeof(struct DATEANDTIME_DEF)


//------THIS_MONTH_DATA_ROM-----------
#define     THISM_ENERGY_RECORD                  THIS_MONTH_DATA_ROM                     	                         
#define     THISM_DEMAND_RECORD      	           THISM_ENERGY_RECORD+sizeof(struct ENERGY_RECORD)  


//------OTHER_METER_PARAMETER----------
#define    WORKROOMSTATE_ROM                     OTHER_METER_PARAMETER_ROM
#define    WORKROOMFLAG_ROM                      WORKROOMSTATE_ROM+1
#define    WORKROOMSTATEDATE_ROM            WORKROOMFLAG_ROM+1
#define    WORKROOM_RUNTIME_ROM              WORKROOMSTATEDATE_ROM+7 ///king chen add 121214
#define    PPROGRAMKEYSTART_FLAG_ROM      WORKROOM_RUNTIME_ROM+4 
#define    PROGRAMKEYTIMEADD_ROM              PPROGRAMKEYSTART_FLAG_ROM+1                    	                   
#define    COMMCLEARFLAGCURRFF_ROM          PROGRAMKEYTIMEADD_ROM+4  
#define    JUSTMETER_ROM                               COMMCLEARFLAGCURRFF_ROM + sizeof(struct COMMCLEARSTRDEF)     
#define    OUTPUTMODEL_ROM                          JUSTMETER_ROM+1        
#define    POWERONDAYFREEZE_FLAG_ROM     OUTPUTMODEL_ROM+1
#define    DAYFREEZEREFERENCEDATE_ROM    POWERONDAYFREEZE_FLAG_ROM+1///king chen add 130302
#define    POWERONRETORT_FLAG_ROM           DAYFREEZEREFERENCEDATE_ROM+7
#define    EVENTREPORT_RUNTIME_ROM     POWERONRETORT_FLAG_ROM +1
#define    RESETEVENTREPORT_FLAG_ROM   EVENTREPORT_RUNTIME_ROM +2

#define    OLDSEGPARAMETER_ROM                   (RESETEVENTREPORT_FLAG_ROM + 1)
#define    BILL_FLAG_ROM			 			(OLDSEGPARAMETER_ROM+4 )     
#define    BILL_ADDR_ROM			 			(BILL_FLAG_ROM+1)		
#define    BILL_DM_FLAG_ROM			 		(BILL_ADDR_ROM+1)		
#define    BILL_DM_ADDR_ROM			 		(BILL_DM_FLAG_ROM+1)	
#define    LASTENERGYBILLDATE_ROM                (BILL_DM_ADDR_ROM+1)

#define    FREEZE_TIME_ADDR_ROM                    (LASTENERGYBILLDATE_ROM+sizeof(struct DATEANDTIME_DEF))
#define    FREEZE_MOMENT_ADDR_ROM                (FREEZE_TIME_ADDR_ROM+1)
#define    FREEZE_PERIOD_ADDR_ROM                (FREEZE_MOMENT_ADDR_ROM+1) 
#define    FREEZE_DAY_ADDR_ROM                   (FREEZE_PERIOD_ADDR_ROM+1)

#define    SWITCHON_REPORT_ROM                   (FREEZE_DAY_ADDR_ROM+1)
#define    SWITCHOFF_REPORT_ROM                   (SWITCHON_REPORT_ROM+1)

//------EVENT_REPORT_STATUS_TIMES---------------///
#define   SWITCH_ERR_TIMES_ROM                           EVENT_REPORT_STATUS_TIMES_ROM
#define   ESAM_ERR_TIMES_ROM                                SWITCH_ERR_TIMES_ROM + 1
#define   EEPROM_INIT_ERR_TIMES_ROM                   ESAM_ERR_TIMES_ROM + 1
#define   CLOCK_BATTERY_VOLT_LOW_TIMES_ROM    EEPROM_INIT_ERR_TIMES_ROM +1
#define   CODE_ERR_TIMES_ROM                                 CLOCK_BATTERY_VOLT_LOW_TIMES_ROM +1
#define   MEMORIZER_ERR_TIMES_ROM                       CODE_ERR_TIMES_ROM + 1
//
#define   CLOCK_ERR_TIMES_ROM                                MEMORIZER_ERR_TIMES_ROM+2

#define   LOWPOWER_BATTERY_VOLT_LOW_TIMES_ROM    CLOCK_ERR_TIMES_ROM + 1
#define   OVERDRAFT_TIMES_ROM                                       LOWPOWER_BATTERY_VOLT_LOW_TIMES_ROM + 1
#define   OPEN_METER_COVER_TIMES_ROM                         OVERDRAFT_TIMES_ROM + 1
#define   OPEN_METER_RAIL_TIMES_ROM                            OPEN_METER_COVER_TIMES_ROM  + 1
#define   CONSTANTMAGNET_EVENT_TIMES_ROM                OPEN_METER_RAIL_TIMES_ROM  + 1
#define   POWERABNORMAL_EVENT_TIMES_ROM                  CONSTANTMAGNET_EVENT_TIMES_ROM  + 1
#define   SWITCH_OFF_TIMES_ROM                                      POWERABNORMAL_EVENT_TIMES_ROM  + 1
#define   SWITCH_ON_TIMES_ROM                                        SWITCH_OFF_TIMES_ROM  + 1

#define   LOSTVOLT_A_TIMES_ROM                                       SWITCH_ON_TIMES_ROM  + 1
#define   LOWTVOLT_A_TIMES_ROM                                      LOSTVOLT_A_TIMES_ROM  + 1
#define   OVERVOLT_A_TIMES_ROM                                       LOWTVOLT_A_TIMES_ROM  + 1
#define   LOSSCURR_A_TIMES_ROM                                       OVERVOLT_A_TIMES_ROM  + 1
#define   OVERCURR_A_TIMES_ROM                                       LOSSCURR_A_TIMES_ROM  + 1
#define   UPLOAD_A_EVENT_TIMES_ROM                                OVERCURR_A_TIMES_ROM   + 1
#define   POWERRESERVE_A_TIMES_ROM                               UPLOAD_A_EVENT_TIMES_ROM + 1
#define   BREAKPHASE_A_EVENT_TIMES_ROM                        POWERRESERVE_A_TIMES_ROM  + 1

#define   BREAKCURR_A_TIMES_ROM                                   BREAKPHASE_A_EVENT_TIMES_ROM   + 1
//
//
//
//
//
//
//

#define   LOSTVOLT_B_TIMES_ROM                                       BREAKCURR_A_TIMES_ROM  + 8
#define   LOWTVOLT_B_TIMES_ROM                                      LOSTVOLT_B_TIMES_ROM  + 1
#define   OVERVOLT_B_TIMES_ROM                                       LOWTVOLT_B_TIMES_ROM  + 1
#define   LOSSCURR_B_TIMES_ROM                                       OVERVOLT_B_TIMES_ROM  + 1
#define   OVERCURR_B_TIMES_ROM                                       LOSSCURR_B_TIMES_ROM  + 1
#define   UPLOAD_B_EVENT_TIMES_ROM                               OVERCURR_B_TIMES_ROM   + 1
#define   POWERRESERVE_B_TIMES_ROM                               UPLOAD_B_EVENT_TIMES_ROM  + 1
#define   BREAKPHASE_B_EVENT_TIMES_ROM                       POWERRESERVE_B_TIMES_ROM  + 1

#define   BREAKCURR_B_TIMES_ROM                                   BREAKPHASE_B_EVENT_TIMES_ROM + 1
//
//
//
//
//
//
//

#define   LOSTVOLT_C_TIMES_ROM                                       BREAKCURR_B_TIMES_ROM  + 8
#define   LOWTVOLT_C_TIMES_ROM                                      LOSTVOLT_C_TIMES_ROM  + 1
#define   OVERVOLT_C_TIMES_ROM                                       LOWTVOLT_C_TIMES_ROM  + 1
#define   LOSSCURR_C_TIMES_ROM                                       OVERVOLT_C_TIMES_ROM  + 1
#define   OVERCURR_C_TIMES_ROM                                       LOSSCURR_C_TIMES_ROM  + 1
#define   UPLOAD_C_EVENT_TIMES_ROM                               OVERCURR_C_TIMES_ROM   + 1
#define   POWERRESERVE_C_TIMES_ROM                               UPLOAD_C_EVENT_TIMES_ROM  + 1
#define   BREAKPHASE_C_EVENT_TIMES_ROM                        POWERRESERVE_C_TIMES_ROM  + 1

#define   BREAKCURR_C_TIMES_ROM                                   BREAKPHASE_C_EVENT_TIMES_ROM   + 1
//
//
//
//
//
//
//
#define   VOLTREVERSE_TIMES_ROM                                   BREAKCURR_C_TIMES_ROM  + 8
#define   CURRREVERSE_EVENT_TIMES_ROM                      VOLTREVERSE_TIMES_ROM + 1
#define   VOLTIMBALANCE_TIMES_ROM                               CURRREVERSE_EVENT_TIMES_ROM    + 1
#define   CURRIMBALANCE_TIMES_ROM                               VOLTIMBALANCE_TIMES_ROM  + 1
#define   AUXILIARYPOWER_EVENT_TIMES_ROM                  CURRIMBALANCE_TIMES_ROM  + 1
#define   POWERDOWN_EVENT_TIMES_ROM                           AUXILIARYPOWER_EVENT_TIMES_ROM  + 1
#define   OVERDEMAND_TIMES_ROM                                      POWERDOWN_EVENT_TIMES_ROM  + 1
#define   FACTOR_LOW_TIMES_ROM                                      OVERDEMAND_TIMES_ROM  + 1

#define   CURRCRITICALIMBALANCE_TIMES_ROM                  FACTOR_LOW_TIMES_ROM  + 1
#define   TOTALPOWERREVERSE_TIMES_ROM                        CURRCRITICALIMBALANCE_TIMES_ROM  + 1
#define   ALLLOSTVOLTAGE_TIMES_ROM                                TOTALPOWERREVERSE_TIMES_ROM  + 1
//
//
//
//
//

#define   PROGRAM_EVENT_TIMES_ROM                                ALLLOSTVOLTAGE_TIMES_ROM  + 6
#define   METER_CLEAR_TIMES_ROM                                     PROGRAM_EVENT_TIMES_ROM  + 1
#define   DEMAND_CLEAR_TIMES_ROM                                  METER_CLEAR_TIMES_ROM  + 1
#define   EVENT_CLEAR_TIMES_ROM                                     DEMAND_CLEAR_TIMES_ROM  + 1
#define   ADJUSTTIME_EVENT_TIMES_ROM                           EVENT_CLEAR_TIMES_ROM  + 1
#define   PROGDAILYSLOT_TIMES_ROM                                 ADJUSTTIME_EVENT_TIMES_ROM  + 1
#define   PROGYEARSLOT_TIMES_ROM                                  PROGDAILYSLOT_TIMES_ROM   + 1
#define   PROGWEEK_TIMES_ROM                                         PROGYEARSLOT_TIMES_ROM   + 1

#define   PROGHOLIDAY_TIMES_ROM                                     PROGWEEK_TIMES_ROM  + 1
#define   PROGAEMODE_TIMES_ROM                                      PROGHOLIDAY_TIMES_ROM  + 1
#define   PROGNEMODE1_TIMES_ROM                                     PROGAEMODE_TIMES_ROM  + 1
#define   PROGNEMODE2_TIMES_ROM                                     PROGNEMODE1_TIMES_ROM  + 1
#define   PROGBILLDAY_TIMES_ROM                                       PROGNEMODE2_TIMES_ROM  + 1
#define   PROGTRIFFPRICE_TIMES_ROM                                  PROGBILLDAY_TIMES_ROM + 1
#define   PROGSTEPPRICE_TIMES_ROM                                  PROGTRIFFPRICE_TIMES_ROM + 1
#define   PSWUPDATE_TIMES_ROM                                  PROGSTEPPRICE_TIMES_ROM + 1

//------METER_PARAMETER---------------  
#define    PARAMETER1_ROM                        METER_PARAMETER_ROM
#define    PARAMETER2_ROM                        PARAMETER1_ROM + sizeof(struct PARAMETER1)
#define    EVENT_PARAMETER_ROM                   PARAMETER2_ROM + sizeof(struct PARAMETER2)
#define    FREEZE_PARAMETER_ROM             EVENT_PARAMETER_ROM + sizeof(struct EVENT_PARAMETER)
////#define    NEW_PARAMETER_ROM                FREEZE_PARAMETER_ROM + sizeof(struct FREEZE_PARAMETER)///king chen mark 121226

#define PARAMETER1_MBR_ADDR(member) ( PARAMETER1_ROM + (unsigned long)(&((struct PARAMETER1 *)0)->member) )

//------PARAMETER1--------------------
#define    ACTIVEPULSECONST_ROM                  PARAMETER1_ROM
#define    REACTIVEPULSECONST_ROM                ACTIVEPULSECONST_ROM+4                         
#define    BCDCOMMADDR1_ROM                      REACTIVEPULSECONST_ROM+4    
#define    BCDCOMMADDR2_ROM                      BCDCOMMADDR1_ROM+6             
#define    BCDCOMMADDR3_ROM                      BCDCOMMADDR2_ROM+6 
#define    METERMODE1_ROM                        BCDCOMMADDR3_ROM+6  
#define    METERMODE2_ROM                        METERMODE1_ROM+1                  
#define    METERMODE3_ROM                        METERMODE2_ROM+1                  
#define    METERMODE4_ROM                        METERMODE3_ROM+1  
#define    METERMODE_ALARM_FLAG_ROM   METERMODE4_ROM+1  //#define    METERMODE5_ROM    METERMODE4_ROM+1 
#define    METERMODE_LEDALARM_FLAG_ROM   METERMODE_ALARM_FLAG_ROM+4 //LCD_LED_Speaker_Terminal
#define    METERMODE_SPEAKERALARM_FLAG_ROM   METERMODE_LEDALARM_FLAG_ROM+4
#define    METERMODE_TERMINALALARM_FLAG_ROM   METERMODE_SPEAKERALARM_FLAG_ROM+4
#define    DEMANDPERIOD_ROM                    METERMODE_TERMINALALARM_FLAG_ROM+4             
#define    DEMANDSKIPPERIOD_ROM                  DEMANDPERIOD_ROM+1             
#define    CYCLEDISPLAYTIME_ROM                  DEMANDSKIPPERIOD_ROM+1   
#define    DISPLAYNUMBER_ROM                     CYCLEDISPLAYTIME_ROM+1    
#define    AUTOBILLDAYHOUR_1_ROM                 DISPLAYNUMBER_ROM+1
#define    AUTOBILLDAYHOUR_2_ROM                 AUTOBILLDAYHOUR_1_ROM+2 
#define    AUTOBILLDAYHOUR_3_ROM                 AUTOBILLDAYHOUR_2_ROM+2 
#define	   ACTIVEM_ERENGY_MODE_ROM	             AUTOBILLDAYHOUR_3_ROM+2 
#define    REACTIVEM_ERENGY_1_MODE_ROM           ACTIVEM_ERENGY_MODE_ROM+1          
#define    REACTIVEM_ERENGY_2_MODE_ROM           REACTIVEM_ERENGY_1_MODE_ROM+1  
#define    METERTYPEMODE_ROM                     REACTIVEM_ERENGY_2_MODE_ROM+1  
#define    CARRIERMODE_ROM                     METERTYPEMODE_ROM+1   //payment
#define    COMMRATE0_ROM                         CARRIERMODE_ROM+1          
#define    COMMRATE1_ROM                         COMMRATE0_ROM+1    
#define    COMMRATE2_ROM                         COMMRATE1_ROM+1     
#define    COMMRATE3_ROM                         COMMRATE2_ROM+1 
//#define    VI_REGULATION_ROM                     COMMRATE2_ROM+1
#define    SLOTPAREMETER1_ROM                    COMMRATE3_ROM+1//VI_REGULATION_ROM+2
#define    SLOTPAREMETER2_ROM                    SLOTPAREMETER1_ROM+sizeof(struct SLOTPAREMETER)  
#define    TRIFFSWITCH_ROM                       SLOTPAREMETER2_ROM+sizeof(struct SLOTPAREMETER)
    #define    WHITCHSLOTISNOW_ROM                    TRIFFSWITCH_ROM
    #define    TRIFFSWITCHDATE_ROM                    (WHITCHSLOTISNOW_ROM+1)
    #define    FREEZE_TRIFF_ADDR_ROM                  (TRIFFSWITCHDATE_ROM+7)
    #define    DROPPROTECTFLAG_TRIFF_ROM          (FREEZE_TRIFF_ADDR_ROM+1)
#define    DAILYSLOTSWITCH_ROM                   TRIFFSWITCH_ROM+sizeof(struct SWITCH_ITEM)
    #define     WHITCHDALIYSLOTISNOW_ROM                DAILYSLOTSWITCH_ROM
    #define     DALIYSLOTSWITCHDATE_ROM                 (WHITCHDALIYSLOTISNOW_ROM+1)
    #define     FREEZE_DALIYSLOT_ADDR_ROM               (DALIYSLOTSWITCHDATE_ROM+7)
    #define     DROPPROTECTFLAG_DALIYSLOT_ROM       (FREEZE_DALIYSLOT_ADDR_ROM+1)
#define    KEYDISPLAYNUMBER_ROM                  DAILYSLOTSWITCH_ROM+sizeof(struct SWITCH_ITEM)
#define    CLEARPASSWORD_ROM                     KEYDISPLAYNUMBER_ROM+2        
#define    CLEARDEMANDPASSWORD_ROM               CLEARPASSWORD_ROM+4            
#define    PROGRAMMPASSWORD_ROM                  CLEARDEMANDPASSWORD_ROM+4 	// 2JI
#define    OTHER_PASSWORD_ROM                    PROGRAMMPASSWORD_ROM+4
#define    PASSWORD4_ROM                    	OTHER_PASSWORD_ROM+4	// 4JI
#define    USERCLASS_ROM                         PASSWORD4_ROM+4
#define    EVENTJUDGEIN_ROM                      USERCLASS_ROM+3 
#define     DISPIN_ROM                                 EVENTJUDGEIN_ROM + 4  
#define    EVENT_REPORT_MODE_ROM        DISPIN_ROM + 1
#define    LOCALFUNCTIONMODE_ROM        EVENT_REPORT_MODE_ROM + sizeof(union EVENT_REPORT_MODE) 
#define    RESETREPORTTIME_ROM        LOCALFUNCTIONMODE_ROM + 1
#define    PARAMETER1_CRC_ROM              RESETREPORTTIME_ROM + 1


//DISP_In

//---------PARAMETER2--------------------
#define    ASCII_METERMANAGE_CODE                PARAMETER2_ROM    
#define    ASCII_V_REGYLATION                    ASCII_METERMANAGE_CODE+32    
#define    ASCII_I_REGYLATION                    ASCII_V_REGYLATION+6    
#define    ASCII_MAX_I                      		 ASCII_I_REGYLATION+6    
#define    ASCII_ACTIVE_ACCU                  	 ASCII_MAX_I+6    
#define    ASCII_REACTIVE_ACCU                   ASCII_ACTIVE_ACCU+4    
#define    ASCII_METER_MODER                     ASCII_REACTIVE_ACCU+4    
#define    ASCII_MANAFACTURE_DAY                 ASCII_METER_MODER+10    
#define    ASCII_PROTOCOLl_VERSION               ASCII_MANAFACTURE_DAY+10 
#define    ASCII_FACTORY_HARDWARE_VERSION        ASCII_PROTOCOLl_VERSION+16
#define    ASCII_FACTORY_SOFEWARE_VERSION        ASCII_FACTORY_HARDWARE_VERSION+32   
#define    ASCII_FACTORY_NUMBER_VERSION          ASCII_FACTORY_SOFEWARE_VERSION+32
#define    ENERGYPOINT_ROM                       ASCII_FACTORY_NUMBER_VERSION+32                            
#define    POWERPOINT_ROM                        ENERGYPOINT_ROM+1  
#define	   LOADDAY_ROM                           POWERPOINT_ROM+1   
#define    PULSEWIDTH_ROM                        LOADDAY_ROM+1  
#define    BCDMETERID_ROM                        PULSEWIDTH_ROM+2            
#define    BCDUSERID_ROM                         BCDMETERID_ROM+6               
#define    BCDDEVICEID_ROM                       BCDUSERID_ROM+6 
#define    LOADRECORDMODE_ROM                    BCDDEVICEID_ROM+6              
#define    LOADRECOEDBEGINTIME_ROM               LOADRECORDMODE_ROM+1           
#define    LOADRECORDPERIOD_ROM                  LOADRECOEDBEGINTIME_ROM+sizeof(struct DATEANDTIME_DEF)  
                     
#define    OPENSWITCHDELAYTIME_ROM               LOADRECORDPERIOD_ROM+12
#define    CLOSESWITCHDELAYTIME_ROM              OPENSWITCHDELAYTIME_ROM+1 
#define    SHOWNOKEYRETTIME_ROM                  CLOSESWITCHDELAYTIME_ROM+1
#define    METERLOCKTIMES_ROM                    SHOWNOKEYRETTIME_ROM+2
#define    PLUSENERGYDATA_ROM                  	 METERLOCKTIMES_ROM+1
#define    NEGAENERGYDATA_ROM                  	 PLUSENERGYDATA_ROM+4
#define    EXITPROGRAMETIME_ROM               	 NEGAENERGYDATA_ROM+4    
#define    BRODCASTJUSTTTIMES_ROM                EXITPROGRAMETIME_ROM+2
#define    JFPG_EXPRESSTRIFF_ROM                 BRODCASTJUSTTTIMES_ROM+1
#define    POWERONFULLSCREENTIME_ROM             JFPG_EXPRESSTRIFF_ROM+63
#define    LONGITUDE_ROM                         POWERONFULLSCREENTIME_ROM+1
#define    LATITUDE_ROM                          LONGITUDE_ROM+4
#define    HEIGHT_ROM                            LATITUDE_ROM+4
#define    METERSOFTIDNUMBER_ROM                 HEIGHT_ROM+4
#define    PARAMETER2_CRC_ROM                    METERSOFTIDNUMBER_ROM+8

               
//--------EVENT PARAMETER---------------------
#define    VOLTAGEHEALTH_UPSET_ROM               EVENT_PARAMETER_ROM                
#define    VOLTAGEHEALTH_DOWNSET_ROM             VOLTAGEHEALTH_UPSET_ROM+4      
#define    VOLTAGECHECK_UPSET_ROM                VOLTAGEHEALTH_DOWNSET_ROM+4    
#define    VOLTAGECHECK_DOWNSET_ROM              VOLTAGECHECK_UPSET_ROM+4       		 										  
#define    JUDGELOSSVOLTAGESECOND_ROM   				 VOLTAGECHECK_DOWNSET_ROM+4 
#define    JUDGEBREAKPHASESECOND_ROM    				 JUDGELOSSVOLTAGESECOND_ROM+1
#define    JUDGELOSTCURR_T_ROM          				 JUDGEBREAKPHASESECOND_ROM+1
#define    JUDGELOSTCURR_I_ROM          				 JUDGELOSTCURR_T_ROM+1
#define    JUDGEBREAKPHASEI_ROM         				 JUDGELOSTCURR_I_ROM+8
#define    PAADEMANDLIMIT_ROM           				 JUDGEBREAKPHASEI_ROM+4
#define    NEADEMANDLIMIT_ROM           				 PAADEMANDLIMIT_ROM+4
#define    CRITICALVOLTAGE_ROM          				 NEADEMANDLIMIT_ROM+4
#define    JUDGEOVERVOLT_V_ROM                   CRITICALVOLTAGE_ROM+1
#define    JUDGECURRIMBALANCEN_ROM               JUDGEOVERVOLT_V_ROM+2
#define    JUDGEVOLTIMBALANCEN_ROM               JUDGECURRIMBALANCEN_ROM+4
#define    JUDGELOSSVOLTAGE_ROM                  JUDGEVOLTIMBALANCEN_ROM+4  
#define    JUDGELOSSVOLTAGENV_ROM                JUDGELOSSVOLTAGE_ROM+4                           
#define    JUDGEVOLTDOWN_V_ROM                   JUDGELOSSVOLTAGENV_ROM+1
#define    JUDGEOVERCURRENTI_ROM                 JUDGEVOLTDOWN_V_ROM+2                 
#define    JUDGELOSTVOLTSV_ROM                   JUDGEOVERCURRENTI_ROM+4
#define    JUDGELOSTVOLTEV_ROM                   JUDGELOSTVOLTSV_ROM+2
#define    JUDGEVOLTDOWNT_ROM                    JUDGELOSTVOLTEV_ROM+2
#define    JUDGEOVERVOLTT_ROM                    JUDGEVOLTDOWNT_ROM+1
#define    JUDGEBREAKPHASEV_ROM                  JUDGEOVERVOLTT_ROM+1
#define    JUDGEVOLTIMBALANCET_ROM               JUDGEBREAKPHASEV_ROM+2
#define    JUDGECURRIMBALANCET_ROM               JUDGEVOLTIMBALANCET_ROM+1
#define    JUDGELOSTCURRSV_ROM                   JUDGECURRIMBALANCET_ROM+1
#define    JUDGEOVERCURRENT_ROM                  JUDGELOSTCURRSV_ROM+2
#define    JUDGEPOWERREVERSEP_ROM                JUDGEOVERCURRENT_ROM+1
#define    JUDGEPOWERREVERSET_ROM                JUDGEPOWERREVERSEP_ROM+4
#define    JUDGEUPLOADP_ROM                      JUDGEPOWERREVERSET_ROM+1
#define    JUDGEUPLOADT_ROM                      JUDGEUPLOADP_ROM+4
#define    JUDGEOVERDEMANDP_ROM                  JUDGEUPLOADT_ROM+1
#define    JUDGEOVERFACTORN_ROM                  JUDGEOVERDEMANDP_ROM+4
#define    JUDGEOVERFACTORT_ROM                  JUDGEOVERFACTORN_ROM+2
#define    JUDGECURRFARIMBN_ROM                  JUDGEOVERFACTORT_ROM+1
#define    JUDGECURRFARIMBT_ROM                  JUDGECURRFARIMBN_ROM+2
#define    JUDGEFAILCURRSV_ROM                   JUDGECURRFARIMBT_ROM+1
#define    JUDGEFAILCURRI_ROM                    JUDGEFAILCURRSV_ROM+2
#define    JUDGEFAILCURRT_ROM                    JUDGEFAILCURRI_ROM+4
#define    JUDGEOVERDEMANDN_ROM                  JUDGEFAILCURRT_ROM+1
#define    JUDGEOVERDEMANDT_ROM                  JUDGEOVERDEMANDN_ROM+4
#define    JUDGECURRIMBMINI_ROM                  JUDGEOVERDEMANDT_ROM+1
#define    JUDGEABCPOWERREVERSEP_ROM             JUDGECURRIMBMINI_ROM+4
#define    JUDGEABCPOWERREVERSET_ROM             JUDGEABCPOWERREVERSEP_ROM+4
#define    AD_SAMPLE_VREF_ROM                       JUDGEABCPOWERREVERSET_ROM+1
#define    CLOCKBATTERY_VOLT_LOW_THRESHOLD_ROM       AD_SAMPLE_VREF_ROM+2
#define    DISPLAYBATTERY_VOLT_LOW_THRESHOLD_ROM     CLOCKBATTERY_VOLT_LOW_THRESHOLD_ROM+2
#define    EVENT_PARAMETER_CRC_ROM               DISPLAYBATTERY_VOLT_LOW_THRESHOLD_ROM+2

//---------FREEZE_PARAMETER------------------
#define    FREEZEDATE_ROM                        FREEZE_PARAMETER_ROM
#define    FREEZEDATEFLAG_ROM                    FREEZEDATE_ROM+4
#define    FREEZE_PERIOD_DATE                    FREEZEDATEFLAG_ROM+1
#define    FREEZE_PERIOD_INTERVAL                FREEZE_PERIOD_DATE+7
#define    FREEZE_DAY_HOUR                       FREEZE_PERIOD_INTERVAL+1             
#define    FREEZE_DAY_MIN                        FREEZE_DAY_HOUR+1   
#define    NEW645_FREEZE_TIME_MODE_ROM           FREEZE_DAY_MIN+1
#define    NEW645_FREEZE_MOMENT_MODE_ROM         NEW645_FREEZE_TIME_MODE_ROM+1
#define    NEW645_FREEZE_PROMISE_MODE_ROM        NEW645_FREEZE_MOMENT_MODE_ROM+1
#define    NEW645_FREEZE_PERIOD_MODE_ROM         NEW645_FREEZE_PROMISE_MODE_ROM+1
#define    NEW645_FREEZE_DAY_MODE_ROM            NEW645_FREEZE_PERIOD_MODE_ROM+1
#define    FREEZE_PARAMETER_CRC_ROM           NEW645_FREEZE_DAY_MODE_ROM+1

///--------NEW_PARAMETER----------------------- ////king  chen mark 121226
///#define    DAYFREEZE_FLAG_ROM                       NEW_PARAMETER_ROM
///#define    POWERONDAYFREEZE_FLAG_ROM       DAYFREEZE_FLAG_ROM+1
///#define    POWERONFULLSCREENTIME_ROM        POWERONDAYFREEZE_FLAG_ROM+1
///#define    NEW_PARAMETER_CRC_ROM                POWERONFULLSCREENTIME_ROM+1

#define    BREAKPHASE_A_TIMES_ROM                    EVENT_POWER_NET_TIMES_ROM   
#define    BREAKPHASE_B_TIMES_ROM                    BREAKPHASE_A_TIMES_ROM+4  
#define    BREAKPHASE_C_TIMES_ROM                    BREAKPHASE_B_TIMES_ROM+4        
#define    LOSTVOLTAGE_A_TIMES_ROM                   BREAKPHASE_C_TIMES_ROM+4                     
#define    LOSTVOLTAGE_B_TIMES_ROM                   LOSTVOLTAGE_A_TIMES_ROM+4                 
#define    LOSTVOLTAGE_C_TIMES_ROM                   LOSTVOLTAGE_B_TIMES_ROM+4
//#define    LOSTVOLTAGE_AB_TIMES_ROM                  LOSTVOLTAGE_C_TIMES_ROM+4
//#define    LOSTVOLTAGE_AC_TIMES_ROM                  LOSTVOLTAGE_AB_TIMES_ROM+2
//#define    LOSTVOLTAGE_BC_TIMES_ROM                  LOSTVOLTAGE_AC_TIMES_ROM+2
//#define    LOSTVOLTAGE_ABC_TIMES_ROM                 LOSTVOLTAGE_BC_TIMES_ROM+2   
//#define    TOTALLOSTVOLTAGE_TIMES_ROM                LOSTVOLTAGE_ABC_TIMES_ROM+2  //mw closed 2009-09-03                 
#define	   LOSTCURRENT_A_TIMES_ROM                   LOSTVOLTAGE_C_TIMES_ROM+4
#define    LOSTCURRENT_B_TIMES_ROM                   LOSTCURRENT_A_TIMES_ROM+4              
#define    LOSTCURRENT_C_TIMES_ROM                   LOSTCURRENT_B_TIMES_ROM+4
//#define    LOSTCURRENT_AB_TIMES_ROM                  LOSTCURRENT_C_TIMES_ROM+4   
//#define    LOSTCURRENT_AC_TIMES_ROM                  LOSTCURRENT_AB_TIMES_ROM+2 
//#define    LOSTCURRENT_BC_TIMES_ROM                  LOSTCURRENT_AC_TIMES_ROM+2
//#define    TOTALLOSTCURRENT_TIMES_ROM                LOSTCURRENT_BC_TIMES_ROM+2   //mw closed 2009-09-03
#define	   POWERREVERSE_T_TIMES_ROM                  LOSTCURRENT_C_TIMES_ROM+4   
#define    POWERREVERSE_A_TIMES_ROM                  POWERREVERSE_T_TIMES_ROM+4
#define    POWERREVERSE_B_TIMES_ROM                  POWERREVERSE_A_TIMES_ROM+4
#define    POWERREVERSE_C_TIMES_ROM	                 POWERREVERSE_B_TIMES_ROM+4
//#define	   UPVOLTAGECHECK_A_TIMES_ROM                POWERREVERSE_C_TIMES_ROM+4
//#define	   OKVOLTAGECHECK_A_TIMES_ROM                UPVOLTAGECHECK_A_TIMES_ROM+2
//#define	   DOWNVOLTAGECHECK_A_TIMES_ROM              OKVOLTAGECHECK_A_TIMES_ROM+2
//#define	   UPVOLTAGECHECK_B_TIMES_ROM                DOWNVOLTAGECHECK_A_TIMES_ROM+2
//#define    OKVOLTAGECHECK_B_TIMES_ROM                UPVOLTAGECHECK_B_TIMES_ROM+2
//#define    DOWNVOLTAGECHECK_B_TIMES_ROM              OKVOLTAGECHECK_B_TIMES_ROM+2
//#define    UPVOLTAGECHECK_C_TIMES_ROM                DOWNVOLTAGECHECK_B_TIMES_ROM+2
//#define    OKVOLTAGECHECK_C_TIMES_ROM                UPVOLTAGECHECK_C_TIMES_ROM+2
//#define    DOWNVOLTAGECHECK_C_TIMES_ROM              OKVOLTAGECHECK_C_TIMES_ROM+2
#define	   OVERPOWERALARM_TIMES_ROM                   POWERREVERSE_C_TIMES_ROM+4//DOWNVOLTAGECHECK_C_TIMES_ROM+2
//#define	   OVERVISUALPOWER_TIMES_ROM                 OVERPOWERALARM_TIMES_ROM+4  
#define	   VOLTAGERESERVE_TIMES_ROM                  OVERPOWERALARM_TIMES_ROM+4  //OVERVISUALPOWER_TIMES_ROM+2
#define	   OVERVOLTAGE_A_TIMES_ROM                   VOLTAGERESERVE_TIMES_ROM+4
#define    OVERVOLTAGE_B_TIMES_ROM                   OVERVOLTAGE_A_TIMES_ROM+4
#define    OVERVOLTAGE_C_TIMES_ROM                   OVERVOLTAGE_B_TIMES_ROM+4    
//#define	   CURRIMBALANCE_A_TIMES_ROM                 OVERVOLTAGE_C_TIMES_ROM+4
//#define    CURRIMBALANCE_B_TIMES_ROM                 CURRIMBALANCE_A_TIMES_ROM+2
//#define    CURRIMBALANCE_C_TIMES_ROM                 CURRIMBALANCE_B_TIMES_ROM+2
#define    POWERDOWN_TIMES_ROM                       OVERVOLTAGE_C_TIMES_ROM+4//CURRIMBALANCE_C_TIMES_ROM+2
#define    PROGRAMMEEVENT_TIMES_ROM                  POWERDOWN_TIMES_ROM+4
#define    VOLTSTATISTIC_A_TIMES_ROM                 PROGRAMMEEVENT_TIMES_ROM+4
#define    VOLTSTATISTIC_B_TIMES_ROM                 VOLTSTATISTIC_A_TIMES_ROM+4
#define    VOLTSTATISTIC_C_TIMES_ROM                 VOLTSTATISTIC_B_TIMES_ROM+4
#define    VOLTSTATISTIC_T_TIMES_ROM                 VOLTSTATISTIC_C_TIMES_ROM+4
//#define    OPENCOVEREVENT_TIMES_ROM                  PROGRAMMEEVENT_TIMES_ROM+4  //mw moved 2009-09-03
#define    OVERPAADEMAND_TIMES_ROM                   VOLTSTATISTIC_T_TIMES_ROM + 4//PROGRAMMEEVENT_TIMES_ROM+4
#define    OVERNEADEMAND_TIMES_ROM                   OVERPAADEMAND_TIMES_ROM+4
#define    OVER1RDEMAND_TIMES_ROM         	         OVERNEADEMAND_TIMES_ROM+4
#define    OVER2RDEMAND_TIMES_ROM         	         OVER1RDEMAND_TIMES_ROM+4
#define    OVER3RDEMAND_TIMES_ROM         	         OVER2RDEMAND_TIMES_ROM+4
#define    OVER4RDEMAND_TIMES_ROM         	         OVER3RDEMAND_TIMES_ROM+4
#define    OPENCOVEREVENT_TIMES_ROM         	       OVER4RDEMAND_TIMES_ROM+4
#define    OPENBOXEVENT_TIMES_ROM                    OPENCOVEREVENT_TIMES_ROM+4   //mw modified 2009-09-03
#define    PHASE3LOSTVOLT_TIMES_ROM                  OPENBOXEVENT_TIMES_ROM+4
#define    CURRFARIMB_TIMES_ROM                     (PHASE3LOSTVOLT_TIMES_ROM+4) //OVERFACTOR_C_TIMES_ROM+4
#define    CONSTANTMAGNET_TIMES_ROM                 (CURRFARIMB_TIMES_ROM+4) //FAILCURRENT_C_TIMES_ROM+4
#define    POWERABNORMAL_TIMES_ROM                   CONSTANTMAGNET_TIMES_ROM+4 
#define    CURRIMBALANCEEVENT_TIMES_ROM              (POWERABNORMAL_TIMES_ROM + 4)//ADJUSTMETEREVENT_TIMES_ROM+4
#define    VOLTIMBALANCEEVENT_TIMES_ROM              CURRIMBALANCEEVENT_TIMES_ROM+4
#define    VOLTAGEDOWN_A_TIMES_ROM                   VOLTIMBALANCEEVENT_TIMES_ROM+4
#define    VOLTAGEDOWN_B_TIMES_ROM                   VOLTAGEDOWN_A_TIMES_ROM+4
#define    VOLTAGEDOWN_C_TIMES_ROM                   VOLTAGEDOWN_B_TIMES_ROM+4
#define    OVERCURRENT_A_TIMES_ROM                   VOLTAGEDOWN_C_TIMES_ROM+4
#define    OVERCURRENT_B_TIMES_ROM                   OVERCURRENT_A_TIMES_ROM+4
#define    OVERCURRENT_C_TIMES_ROM                   OVERCURRENT_B_TIMES_ROM+4
#define    UPLOAD_A_TIMES_ROM                        OVERCURRENT_C_TIMES_ROM+4
#define    UPLOAD_B_TIMES_ROM                        UPLOAD_A_TIMES_ROM+4
#define    UPLOAD_C_TIMES_ROM                        UPLOAD_B_TIMES_ROM+4
#define    CURRREVERSE_TIMES_ROM                     UPLOAD_C_TIMES_ROM+4
#define    OVERFACTOR_TIMES_ROM                      CURRREVERSE_TIMES_ROM+4
#define    OVERFACTOR_A_TIMES_ROM                    OVERFACTOR_TIMES_ROM+4
#define    OVERFACTOR_B_TIMES_ROM                    OVERFACTOR_A_TIMES_ROM+4
#define    OVERFACTOR_C_TIMES_ROM                    OVERFACTOR_B_TIMES_ROM+4
#define    FAILCURRENT_A_TIMES_ROM                  OVERFACTOR_C_TIMES_ROM+4 //CURRFARIMB_TIMES_ROM+4
#define    FAILCURRENT_B_TIMES_ROM                   FAILCURRENT_A_TIMES_ROM+4
#define    FAILCURRENT_C_TIMES_ROM                   FAILCURRENT_B_TIMES_ROM+4
#define    CLOCKBATTERYEVENT_TIMES_ROM               FAILCURRENT_C_TIMES_ROM+4//PHASE3LOSTVOLT_TIMES_ROM+4
#define    DISPLAYBATTERYEVENT_TIMES_ROM             CLOCKBATTERYEVENT_TIMES_ROM+4
#define    ADJUSTMETEREVENT_TIMES_ROM                DISPLAYBATTERYEVENT_TIMES_ROM+4
//-----------------------------//

#define     RESETCPU_TIMES_ROM                       EVENT_METER_PRO_TIMES_ROM  
#define     SETPRIMARY_TIMES_ROM                     RESETCPU_TIMES_ROM+4
#define     RUNCLOCKERROR_TIMES_ROM                  SETPRIMARY_TIMES_ROM+4
#define     POWERUPCLOCKERROR_TIMES_ROM              RUNCLOCKERROR_TIMES_ROM+4
#define     ADJUSTENERGY_TIMES_ROM                   POWERUPCLOCKERROR_TIMES_ROM+4
#define     EEPROMERR_TIMES_ROM                      ADJUSTENERGY_TIMES_ROM+4
#define     ADJUSTTIMEOVERT_TIMES_ROM                (EEPROMERR_TIMES_ROM+4)  
#define     ENERGYPASSZERO_TIMES_ROM                 ADJUSTTIMEOVERT_TIMES_ROM + 4
#define     RST90E36_TIMES_ROM                       ENERGYPASSZERO_TIMES_ROM+4
#define     CLEARMETERRECORD_TIMES_ROM               RST90E36_TIMES_ROM+4
#define     ADJUSTTIMERECORD_TIMES_ROM               CLEARMETERRECORD_TIMES_ROM+4
#define     CLEARDEMANDRECORD_TIMES_ROM              ADJUSTTIMERECORD_TIMES_ROM+4
#define     CLEAREVENTRECORD_TIMES_ROM               CLEARDEMANDRECORD_TIMES_ROM+4
#define     PROGWEEKRECORD_TIMES_ROM                 CLEAREVENTRECORD_TIMES_ROM+4
#define     PROGAEMODERECORD_TIMES_ROM               PROGWEEKRECORD_TIMES_ROM+4
#define     PROGNEMODE1RECORD_TIMES_ROM              PROGAEMODERECORD_TIMES_ROM+4
#define     PROGNEMODE2RECORD_TIMES_ROM              PROGNEMODE1RECORD_TIMES_ROM+4
#define     PROGBILLDAYRECORD_TIMES_ROM              PROGNEMODE2RECORD_TIMES_ROM+4
#define     PROGYEARSLOTRECORD_TIMES_ROM             PROGBILLDAYRECORD_TIMES_ROM+4
#define     PROGDAILYSLOTRECORD_TIMES_ROM            PROGYEARSLOTRECORD_TIMES_ROM+4
#define     PROGHOLIDAYRECORD_TIMES_ROM              PROGDAILYSLOTRECORD_TIMES_ROM+4
#define     OVERPOWERCLOSESWIT_TIMES_ROM             (PROGHOLIDAYRECORD_TIMES_ROM+4)
                                                                                                               


#define     BREAKPHASE_A_P_ROM                    EVENT_POWER_NET_POINTER_ROM   
#define     BREAKPHASE_B_P_ROM                    BREAKPHASE_A_P_ROM+1       
#define     BREAKPHASE_C_P_ROM                    BREAKPHASE_B_P_ROM+1     
#define     LOSTVOLTAGE_A_P_ROM                   BREAKPHASE_C_P_ROM+1                   
#define     LOSTVOLTAGE_B_P_ROM                   LOSTVOLTAGE_A_P_ROM+1               
#define     LOSTVOLTAGE_C_P_ROM                   LOSTVOLTAGE_B_P_ROM+1   
//#define     LOSTVOLTAGE_AB_P_ROM                  LOSTVOLTAGE_C_P_ROM+1    //mw modified 2009-10-09 Begin
//#define     LOSTVOLTAGE_AC_P_ROM                  LOSTVOLTAGE_AB_P_ROM+1
//#define     LOSTVOLTAGE_BC_P_ROM                  LOSTVOLTAGE_AC_P_ROM+1
//#define     LOSTVOLTAGE_ABC_P_ROM                 LOSTVOLTAGE_BC_P_ROM+1   
//#define     TOTALLOSTVOLTAGE_P_ROM                LOSTVOLTAGE_ABC_P_ROM+1                   
#define     LOSTCURRENT_A_P_ROM                   LOSTVOLTAGE_C_P_ROM+1                
#define     LOSTCURRENT_B_P_ROM                   LOSTCURRENT_A_P_ROM+1                    
#define     LOSTCURRENT_C_P_ROM                   LOSTCURRENT_B_P_ROM+1      
//#define     LOSTCURRENT_AB_P_ROM                  LOSTCURRENT_C_P_ROM+1       
//#define	    LOSTCURRENT_AC_P_ROM                  LOSTCURRENT_AB_P_ROM+1        
//#define     LOSTCURRENT_BC_P_ROM                  LOSTCURRENT_AC_P_ROM+1   
//#define	    TOTALLOSTCURRENT_P_ROM                LOSTCURRENT_BC_P_ROM+1
#define     POWERREVERSE_T_P_ROM                  LOSTCURRENT_C_P_ROM+1    //mw modified 2009-10-09 End
#define     POWERREVERSE_A_P_ROM                  POWERREVERSE_T_P_ROM+1
#define     POWERREVERSE_B_P_ROM                  POWERREVERSE_A_P_ROM+1
#define     POWERREVERSE_C_P_ROM                  POWERREVERSE_B_P_ROM+1	 
//#define	    UPVOLTAGECHECK_A_P_ROM                POWERREVERSE_C_P_ROM+1  
//#define	    UPVOLTAGECHECK_B_P_ROM                UPVOLTAGECHECK_A_P_ROM+1  
//#define	    UPVOLTAGECHECK_C_P_ROM                UPVOLTAGECHECK_B_P_ROM+1  
//#define	    OKVOLTAGECHECK_A_P_ROM                UPVOLTAGECHECK_C_P_ROM+1  
//#define     OKVOLTAGECHECK_B_P_ROM                OKVOLTAGECHECK_A_P_ROM+1  
//#define     OKVOLTAGECHECK_C_P_ROM                OKVOLTAGECHECK_B_P_ROM+1  
//#define	    DOWNVOLTAGECHECK_A_P_ROM              OKVOLTAGECHECK_C_P_ROM+1 
//#define     DOWNVOLTAGECHECK_B_P_ROM              DOWNVOLTAGECHECK_A_P_ROM+1 
//#define     DOWNVOLTAGECHECK_C_P_ROM              DOWNVOLTAGECHECK_B_P_ROM+1
#define	    OVERPOWERALARM_P_ROM                  POWERREVERSE_C_P_ROM+1//DOWNVOLTAGECHECK_C_P_ROM+1
//#define	    OVERVISUALPOWER_P_ROM                 OVERPOWERALARM_P_ROM+1
#define	    VOLTAGERESERVE_P_ROM                  OVERPOWERALARM_P_ROM+1//OVERVISUALPOWER_P_ROM+1
#define	    OVERVOLTAGE_A_P_ROM                   VOLTAGERESERVE_P_ROM+1
#define     OVERVOLTAGE_B_P_ROM                   OVERVOLTAGE_A_P_ROM+1 
#define     OVERVOLTAGE_C_P_ROM                   OVERVOLTAGE_B_P_ROM+1
//#define	    CURRIMBALANCE_A_P_ROM                 OVERVOLTAGE_C_P_ROM+1
//#define     CURRIMBALANCE_B_P_ROM                 CURRIMBALANCE_A_P_ROM+1
//#define     CURRIMBALANCE_C_P_ROM                 CURRIMBALANCE_B_P_ROM+1
//#define	    SINGLEVOLTDOWN70_P_ROM                CURRIMBALANCE_C_P_ROM+1
#define     POWERDOWN_P_ROM                       OVERVOLTAGE_C_P_ROM+1//SINGLEVOLTDOWN70_P_ROM+1
#define     PROGRAMMEEVENT_P_ROM                  POWERDOWN_P_ROM+1
//#define     OPENCOVEREVENT_P_ROM                  PROGRAMMEEVENT_P_ROM+1   //mw moved 2009-09-03
#define     VOLTSTATISTIC_A_P_ROM                 PROGRAMMEEVENT_P_ROM+1
#define     VOLTSTATISTIC_B_P_ROM                 VOLTSTATISTIC_A_P_ROM+1
#define     VOLTSTATISTIC_C_P_ROM                 VOLTSTATISTIC_B_P_ROM+1
#define     VOLTSTATISTIC_T_P_ROM                 VOLTSTATISTIC_C_P_ROM+1
#define     OVERPAADEMAND_P_ROM                   VOLTSTATISTIC_T_P_ROM+1
#define     OVERNEADEMAND_P_ROM                   OVERPAADEMAND_P_ROM+1
#define     OVER1RDEMAND_P_ROM                    OVERNEADEMAND_P_ROM+1
#define     OVER2RDEMAND_P_ROM                    OVER1RDEMAND_P_ROM+1
#define     OVER3RDEMAND_P_ROM                    OVER2RDEMAND_P_ROM+1
#define     OVER4RDEMAND_P_ROM                    OVER3RDEMAND_P_ROM+1
#define     OPENCOVEREVENT_P_ROM                  OVER4RDEMAND_P_ROM+1
#define     OPENBOXEVENT_P_ROM                    OPENCOVEREVENT_P_ROM+1
#define     PHASE3LOSTVOLT_P_ROM                  OPENBOXEVENT_P_ROM+1
#define     CURRFARIMB_P_ROM                      (PHASE3LOSTVOLT_P_ROM+1)//OVERFACTOR_C_P_ROM+1
#define     CONSTANTMAGNET_P_ROM                  (CURRFARIMB_P_ROM+1)//FAILCURRENT_C_P_ROM+1
#define     POWERABNORMAL_P_ROM                   CONSTANTMAGNET_P_ROM+1  
#define     CURRIMBALANCEEVENT_P_ROM              (POWERABNORMAL_P_ROM + 1)//ADJUSTMETEREVENT_P_ROM+1
#define     VOLTIMBALANCEEVENT_P_ROM              CURRIMBALANCEEVENT_P_ROM+1
#define     VOLTAGEDOWN_A_P_ROM                   VOLTIMBALANCEEVENT_P_ROM+1
#define     VOLTAGEDOWN_B_P_ROM                   VOLTAGEDOWN_A_P_ROM+1
#define     VOLTAGEDOWN_C_P_ROM                   VOLTAGEDOWN_B_P_ROM+1
#define     OVERCURRENT_A_P_ROM                   VOLTAGEDOWN_C_P_ROM+1
#define     OVERCURRENT_B_P_ROM                   OVERCURRENT_A_P_ROM+1
#define     OVERCURRENT_C_P_ROM                   OVERCURRENT_B_P_ROM+1
#define     UPLOAD_A_P_ROM                        OVERCURRENT_C_P_ROM+1
#define     UPLOAD_B_P_ROM                        UPLOAD_A_P_ROM+1
#define     UPLOAD_C_P_ROM                        UPLOAD_B_P_ROM+1
#define     CURRREVERSE_P_ROM                     UPLOAD_C_P_ROM+1
#define     OVERFACTOR_P_ROM                      CURRREVERSE_P_ROM+1
#define     OVERFACTOR_A_P_ROM                    OVERFACTOR_P_ROM+1
#define     OVERFACTOR_B_P_ROM                    OVERFACTOR_A_P_ROM+1
#define     OVERFACTOR_C_P_ROM                    OVERFACTOR_B_P_ROM+1
#define     FAILCURRENT_A_P_ROM                   (OVERFACTOR_C_P_ROM+1)//CURRFARIMB_P_ROM+1
#define     FAILCURRENT_B_P_ROM                   FAILCURRENT_A_P_ROM+1
#define     FAILCURRENT_C_P_ROM                   FAILCURRENT_B_P_ROM+1
#define     CLOCKBATTERYEVENT_P_ROM               (FAILCURRENT_C_P_ROM+1)//PHASE3LOSTVOLT_P_ROM+1
#define     DISPLAYBATTERYEVENT_P_ROM             CLOCKBATTERYEVENT_P_ROM+1
#define     ADJUSTMETEREVENT_P_ROM                DISPLAYBATTERYEVENT_P_ROM+1

#define      RESETCPU_P_ROM                      EVENT_METER_PRO_POINTER_ROM      
#define	     SETPRIMARY_P_ROM                    RESETCPU_P_ROM+1
#define	     RUNCLOCKERROR_P_ROM                 SETPRIMARY_P_ROM+1
#define      POWERUPCLOCKERROR_P_ROM             RUNCLOCKERROR_P_ROM+1
#define      ADJUSTENERGY_P_ROM                  POWERUPCLOCKERROR_P_ROM+1
#define      EEPROMERR_P_ROM                     ADJUSTENERGY_P_ROM+1
#define	     ADJUSTTIMEOVERT_P_ROM               EEPROMERR_P_ROM+1
#define	     ENERGYPASSZERO_P_ROM                ADJUSTTIMEOVERT_P_ROM + 1
#define	     RST90E36_P_ROM                      ENERGYPASSZERO_P_ROM+1
#define	     CLEARMETERRECORD_P_ROM              RST90E36_P_ROM+1
#define	     ADJUSTTIMERECORD_P_ROM              CLEARMETERRECORD_P_ROM+1
#define	     CLEARDEMANDRECORD_P_ROM             ADJUSTTIMERECORD_P_ROM+1
#define	     CLEAREVENTRECORD_P_ROM              CLEARDEMANDRECORD_P_ROM+1
#define	     PROGWEEKRECORD_P_ROM                CLEAREVENTRECORD_P_ROM+1
#define	     PROGAEMODERECORD_P_ROM              PROGWEEKRECORD_P_ROM+1
#define	     PROGNEMODE1RECORD_P_ROM             PROGAEMODERECORD_P_ROM+1
#define	     PROGNEMODE2RECORD_P_ROM             PROGNEMODE1RECORD_P_ROM+1
#define	     PROGBILLDAYRECORD_P_ROM             PROGNEMODE2RECORD_P_ROM+1
#define	     PROGYEARSLOTRECORD_P_ROM            PROGBILLDAYRECORD_P_ROM+1
#define	     PROGDAILYSLOTRECORD_P_ROM           PROGYEARSLOTRECORD_P_ROM+1
#define	     PROGHOLIDAYRECORD_P_ROM             PROGDAILYSLOTRECORD_P_ROM+1
#define	     OVERPOWERCLOSESWIT_P_ROM            PROGHOLIDAYRECORD_P_ROM+1 
                                                                                                            
//------//

//------METER_PARAMETER---------------  
#define    BLOCKADDRESS_ROM                      GLOADRECORD_ROM
#define    FIRSTFLAG_ROM                         BLOCKADDRESS_ROM+BLOCKADDRESSLEN
#define    LOADRECORDFLAG_ROM                    FIRSTFLAG_ROM+FIRSTFLAGLEN

//------//
/*"重新调理累计时间结构mw modified 2009-09-03 Begin "*/
#define   LOSTVOLT_A_TIMETICKS_ROM               EVENT_POWER_NET_TIMETICKS_ROM           
#define   LOSTVOLT_B_TIMETICKS_ROM               LOSTVOLT_A_TIMETICKS_ROM+4                 
#define   LOSTVOLT_C_TIMETICKS_ROM               LOSTVOLT_B_TIMETICKS_ROM+4
#define   VOLTAGERESERVE_TIMETICKS_ROM       LOSTVOLT_C_TIMETICKS_ROM+4
#define   PHASE3LOSTVOLT_TIMETICKS_ROM       VOLTAGERESERVE_TIMETICKS_ROM+4
#define	LOSTCURRENT_A_TIMETICKS_ROM          PHASE3LOSTVOLT_TIMETICKS_ROM+4                     
#define   LOSTCURRENT_B_TIMETICKS_ROM          LOSTCURRENT_A_TIMETICKS_ROM+4                    
#define   LOSTCURRENT_C_TIMETICKS_ROM          LOSTCURRENT_B_TIMETICKS_ROM+4    
#define   BREAKPHASE_A_TIMETICKS_ROM           LOSTCURRENT_C_TIMETICKS_ROM+4   
#define   BREAKPHASE_B_TIMETICKS_ROM           BREAKPHASE_A_TIMETICKS_ROM+4        
#define   BREAKPHASE_C_TIMETICKS_ROM           BREAKPHASE_B_TIMETICKS_ROM+4
#define	VOLTAGEDOWN_A_TIMETICKS_ROM        BREAKPHASE_C_TIMETICKS_ROM+4
#define	VOLTAGEDOWN_B_TIMETICKS_ROM        VOLTAGEDOWN_A_TIMETICKS_ROM+4
#define   VOLTAGEDOWN_C_TIMETICKS_ROM        VOLTAGEDOWN_B_TIMETICKS_ROM+4
#define   OVERPAADEMAND_TIMETICKS_ROM        VOLTAGEDOWN_C_TIMETICKS_ROM+4
#define   OVERNEADEMAND_TIMETICKS_ROM        OVERPAADEMAND_TIMETICKS_ROM+4
#define   POWERREVERSE_A_TIMETICKS_ROM       OVERNEADEMAND_TIMETICKS_ROM+4
#define   POWERREVERSE_B_TIMETICKS_ROM       POWERREVERSE_A_TIMETICKS_ROM+4
#define   POWERREVERSE_C_TIMETICKS_ROM       POWERREVERSE_B_TIMETICKS_ROM+4
#define	OVERVOLT_A_TIMETICKS_ROM               POWERREVERSE_C_TIMETICKS_ROM+4
#define   OVERVOLT_B_TIMETICKS_ROM               OVERVOLT_A_TIMETICKS_ROM+4
#define   OVERVOLT_C_TIMETICKS_ROM               OVERVOLT_B_TIMETICKS_ROM+4 
#define   CURRIMBEVENT_TIMETICKS_ROM           OVERVOLT_C_TIMETICKS_ROM+4
#define	VOLTIMBEVENT_TIMETICKS_ROM            CURRIMBEVENT_TIMETICKS_ROM+4
#define   OVERCURRENT_A_TIMETICKS_ROM          VOLTIMBEVENT_TIMETICKS_ROM+4
#define   OVERCURRENT_B_TIMETICKS_ROM          OVERCURRENT_A_TIMETICKS_ROM+4
#define   OVERCURRENT_C_TIMETICKS_ROM          OVERCURRENT_B_TIMETICKS_ROM+4
#define   UPLOAD_A_TIMETICKS_ROM                   OVERCURRENT_C_TIMETICKS_ROM+4
#define   UPLOAD_B_TIMETICKS_ROM                   UPLOAD_A_TIMETICKS_ROM+4
#define   UPLOAD_C_TIMETICKS_ROM        	         UPLOAD_B_TIMETICKS_ROM+4
#define   NOUSE_0_TIMETICKS_ROM     		         UPLOAD_C_TIMETICKS_ROM+4
#define   NOUSE_1_TIMETICKS_ROM     		         NOUSE_0_TIMETICKS_ROM+4
#define	OVERPOWERALARM_TIMETICKS_ROM       NOUSE_1_TIMETICKS_ROM+4       
#define   NOUSE_2_TIMETICKS_ROM     		         OVERPOWERALARM_TIMETICKS_ROM+4
#define   NOUSE_3_TIMETICKS_ROM     		         NOUSE_2_TIMETICKS_ROM+4
#define   NOUSE_4_TIMETICKS_ROM     		         NOUSE_3_TIMETICKS_ROM+4
#define   NOUSE_5_TIMETICKS_ROM     		         NOUSE_4_TIMETICKS_ROM+4
#define   OVERFACTOR_A_TIMETICKS_ROM     		     NOUSE_5_TIMETICKS_ROM+4
#define   OVERFACTOR_B_TIMETICKS_ROM     		     OVERFACTOR_A_TIMETICKS_ROM+4
#define   OVERFACTOR_C_TIMETICKS_ROM     		     OVERFACTOR_B_TIMETICKS_ROM+4
#define   CURRREVERSE_TIMETICKS_ROM              OVERFACTOR_C_TIMETICKS_ROM+4
#define   OVERFACTOR_TIMETICKS_ROM               CURRREVERSE_TIMETICKS_ROM+4
#define   CURRFARIMB_TIMETICKS_ROM               OVERFACTOR_TIMETICKS_ROM+4
#define   FAILCURRENT_A_TIMETICKS_ROM          CURRFARIMB_TIMETICKS_ROM+4
#define   FAILCURRENT_B_TIMETICKS_ROM          FAILCURRENT_A_TIMETICKS_ROM+4
#define   FAILCURRENT_C_TIMETICKS_ROM          FAILCURRENT_B_TIMETICKS_ROM+4
#define   NOUSE_15_TIMETICKS_ROM     		   FAILCURRENT_C_TIMETICKS_ROM+4     
#define   NOUSE_16_TIMETICKS_ROM     		   NOUSE_15_TIMETICKS_ROM+4      
//#define   NOUSE_17_TIMETICKS_ROM                    NOUSE_16_TIMETICKS_ROM+4
#define 	OKVOLTCHECK_A_TIMETICKS_ROM          NOUSE_16_TIMETICKS_ROM+4       
#define   UPVOLTCHECK_A_TIMETICKS_ROM          OKVOLTCHECK_A_TIMETICKS_ROM+4
#define   DOWNVOLTCHECK_A_TIMETICKS_ROM     UPVOLTCHECK_A_TIMETICKS_ROM+4 
#define   OKVOLTCHECK_B_TIMETICKS_ROM          DOWNVOLTCHECK_A_TIMETICKS_ROM+4
#define   UPVOLTCHECK_B_TIMETICKS_ROM          OKVOLTCHECK_B_TIMETICKS_ROM+4
#define   DOWNVOLTCHECK_B_TIMETICKS_ROM     UPVOLTCHECK_B_TIMETICKS_ROM+4
#define 	NOUSE_18_TIMETICKS_ROM                     DOWNVOLTCHECK_B_TIMETICKS_ROM+4
#define   NOUSE_19_TIMETICKS_ROM                     NOUSE_18_TIMETICKS_ROM+4
#define	OKVOLTCHECK_C_TIMETICKS_ROM           NOUSE_19_TIMETICKS_ROM+4
#define   UPVOLTCHECK_C_TIMETICKS_ROM           OKVOLTCHECK_C_TIMETICKS_ROM+4
#define   DOWNVOLTCHECK_C_TIMETICKS_ROM      UPVOLTCHECK_C_TIMETICKS_ROM+4
#define	NOUSE_20_TIMETICKS_ROM                     DOWNVOLTCHECK_C_TIMETICKS_ROM+4
#define   NOUSE_21_TIMETICKS_ROM                     NOUSE_20_TIMETICKS_ROM+4
#define   NOUSE_22_TIMETICKS_ROM                     NOUSE_21_TIMETICKS_ROM+4
#define   NOUSE_23_TIMETICKS_ROM                     NOUSE_22_TIMETICKS_ROM+4
#define   NOUSE_24_TIMETICKS_ROM                     NOUSE_23_TIMETICKS_ROM+4
/*"重新调理累计时间结构mw modified 2009-09-03 End  "*/


#endif                                                                  
/****************************************--------end------***********************************/ 
