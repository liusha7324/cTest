#ifndef COMM_H
#define COMM_H
/*extern unsigned char Comm1B[230];
extern unsigned char Comm2B[230];
extern unsigned char Comm3B[230];*///liuyq delete 2009-8-20
extern unsigned char CommB[3][230];
extern unsigned char ProgramEventFlag;
extern union  BYTE_BIT JustMeterDataFlag;
extern struct DATEANDTIME_DEF JustMeterDateFlag;   /*"教表起始时间"*/
extern unsigned char  JustMeterFlag;               /*"教表起始标志"*/
extern struct FindCommand_Result cx[4];           /*"gjp added 070713通讯结果"*/
extern unsigned char    Readdata_buff[32];/*" 读数据缓冲区间"*/
/*"    ************************   读有符号变量* ************************   "*/
extern signed long     COMM_Curr[3];/*"当前电流"*/
extern signed long     COMM_Factor[4];/*"当前功率因素"*/           
extern signed long     COMM_Active_power[4];/*"当前有功功率"*/
extern signed long     COMM_Reactive_power[4];/*"当前无功功率"*/
extern signed long     COMM_Visual_power[4];/*"当前视在功率"*/
extern signed long	    COMM_Current_Demand[2];/*"当前需量存储空间"*/
extern unsigned char    Freeze_Flag_DayHour[2];																									/*"0 有功"*/

extern unsigned char    Comm_DailyOrYear_Slot;/*"通信先应答后处理"*/
extern unsigned char    Comm_Firrespon_SecDispos_Buff[42];/*"通信先应答后处理操作前数据"*/																								/*"1 无功"*/
extern unsigned char    Comm_Firrespon_SecDispos_Uart[3];

/*"  ************************     读有符号变量*************************    "*/
//extern unsigned char  uartxcomm;
//extern union BYTE_BIT GPRS_Event_Status[];			//payment
//extern union BYTE_BIT GPRS_Event_OldStatus[];


extern unsigned char GPRS_Status;//bit7 0:outline  1:inline  //MB4
                                          //bit0~bit2  0:no signal  1~4:signal strenth bad~good
extern  unsigned int  Voltage_ad_data[2];///king chen add 121214
extern unsigned char Displayfinish_flag;///king chen add 121214
extern unsigned int  FullScreenTime;///king chen add 121214	
extern volatile unsigned  char ad_Flag;  ///king chen debug
extern volatile unsigned  char ad_finish_Flag;///king chen add 121226
extern unsigned long meter_model_ok;///king chen add 130104
///extern unsigned char closebacklight_flag;///king chen add 130228
extern volatile unsigned int  fix_ad_data ;///king chen add 130730

extern unsigned long comm_plus_energy_01wh[MAXTRIFF][2]; /*"通讯和显示4位小数的正向有功电量 0小数 1整数"*/
extern unsigned long comm_nega_energy_01wh[MAXTRIFF][2]; /*"通讯和显示4位小数的反向有功电量 0小数 1整数"*/

extern void Init_Comm(unsigned char);
extern void Interr_Comm_R(unsigned char);
extern void Interr_Comm_W(unsigned char);
extern void Communication(unsigned char,unsigned char,unsigned char);
extern unsigned char FindComCommand(unsigned char,unsigned char);
extern unsigned char AnswerComCommand(unsigned char,unsigned char);
extern signed int    TransferData(union ID ,unsigned char *,unsigned int,unsigned char,
                                  unsigned char*,unsigned char );
extern unsigned long GetNowTime(void);  
extern unsigned char GetTimeCount(unsigned long,unsigned long); 
extern unsigned char F_Ar(unsigned char,unsigned char);  
//extern unsigned char OB_H(unsigned char);  
//extern unsigned char OH_B(unsigned char);
//extern unsigned char Cal_Cs(unsigned char *,unsigned char,unsigned char);    
extern void ReadData(unsigned char);   
extern void WriteData(void);   
extern void BroadcastJustTime(void);
extern void WriteAddress(void);
extern void WriteBaud(void);    
extern void WritePassword(void);
extern void ClearDemand(void); 
extern unsigned char R_W_Data(void);
extern unsigned char ReadLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
extern unsigned char WriteLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void HexToACK(unsigned char *,unsigned char *,unsigned int );	   
extern void BcdToHex(unsigned int,unsigned char *,unsigned char * );	   
extern void ACKToHex(unsigned char *,unsigned char *,unsigned int );  
extern unsigned char GetRecordAddr(unsigned char,unsigned char,unsigned char);  
extern void Delay(unsigned int);
extern unsigned char CalDay(unsigned char,unsigned char);
extern double long ComTime(unsigned char *,unsigned char *);
//extern unsigned char CheckTime(unsigned char *);

extern unsigned char  ClearDemandCommAndKey(unsigned char ,unsigned char);
extern void Clear_PasswordErr(unsigned char,unsigned char );
extern void CheckProgramKeyState(void); 
extern void IC_Set_Program(void);
//extern void Clear_Energy_All(void);//liuyq delete 2009-8-21

extern signed int FreezeEvent_Energy(unsigned char * ,unsigned char * );
/********************new 645 add by fxf081116***************/
extern int  Read_SystemTime_YMDH(void);
extern int  Read_SystemTime_HMS(void);
extern int  Set_SystemTime_YMDH(void);
extern int  Set_SystemTime_HMS(void);
extern int  Set_DemandPeriod(void);
extern int  Set_DemandSkipPeriod(void);
extern int  Set_Activem_Erengy_Mode(void);
extern int  Set_REActivem_Erengy_1_Mode(void);
extern int  Set_REActivem_Erengy_2_Mode(void);
extern int	Set_ActivePulseConst(void);
extern int  Set_Erengypoint(void);
extern int  Set_BILL_Day(void);
extern int  Set_SlotParemeter(void);
extern int  Set_YearSlot(void);
extern int  Set_ProgWeek(void);
extern int  Set_Holiday(void);
extern int  Set_DailySlot(void);
extern int  Set_LoadRecoedBeginTime(void);
extern int  Set_LoadRecoedPeriod(void);
extern int  Set_MeterMode(void);
extern int  Set_Meterlocktimes(void);
extern int  Set_OutputModel(void);
extern int  Exit_WorkRoomState(void);
extern int  Read_primary_energy(void);
extern int  Set_primary_energy(void);
extern int  Read_WorkRoomState(void);
extern int  Read_Freeze_Bit_0_data(void);
extern int  Read_Freeze_Bit_1_data(void);
extern int  Read_Freeze_Bit_2_data(void);
extern int  Read_Freeze_Bit_3_data(void);
extern int  Read_Freeze_Bit_4_data(void);
extern int  Read_Freeze_Bit_5_data(void);
extern int  Read_Freeze_Bit_6_data(void);
extern int  Read_Freeze_Bit_7_data(void);
extern int  Read_Freeze_Block_data(void);
extern int  Read_Meter_lock_times(void);
extern int  Check_Parameter_Len_IS_ok(unsigned char trans_format);
extern int  Pre_No_use_leaf_data(void);
extern int  Set_Display_Number(void);
extern int  Set_Commrate(void);
extern int  Read_Freeze_Date(void);
extern int  Set_CycleDisplayTime(void);
extern int  Read_Far_IR_Commate();
extern int  Set_CriticalVoltage(void);
extern int  Set_CommAddr(void);
extern int  Set_Show_USER_Code(void);
extern int  Read_Sign_Instance_Variable(void);
extern int  Read_Meter_Temperature(void);
extern int  Read_YearSlot_Table(void);
extern int  Read_DailySlot_Table(void);
extern int  Comm_Initialize_FLASH(void);
extern int  Read_Last_loss_voltage_start_time(void);
extern int  Read_Last_loss_voltage_end_time(void);
extern int Set_Freeze_Period_Begin_time(void);
extern int Set_Freeze_Period(void);
extern int Set_TriffSwitchDate(void);
extern int Set_Cycle_Key_Display(void);
extern int  Read_Meter_FILEDATE_VI(void);

extern unsigned char* CommBP;
extern struct FindCommand_Result * CurrPC;
extern unsigned char WriteDateBuff[];
extern int Set_ShowNoKeyRetTime(void);
extern unsigned char CheckPasswordRight(unsigned char *);
extern void CheckPasswoerErr(unsigned char );
extern void AppointTrasfPortBuff(unsigned char );
extern unsigned int Crc16l(unsigned char *ptr,unsigned char len);
extern void Set_which_Responsion_Flag(unsigned char Which,unsigned char flag);
extern int Set_JFPG_Triff(void);

extern void Set_Meter_para_Deal(unsigned int rom_addr);
extern int  Read_Display_Number(void);  //lfy add  2011-3-11

//extern int Set_GPRS_State(void);//ganjp20091029
extern int Read_LostVoltEnergy(void);
extern int Read_LostVolt_AllEnergy(void);
extern void RTC_Init(void);///king chen add 121214
extern void PowerOn_FullScreen_TimeDetection(void);///king chen add 121214

extern int ReadClockBatteryVoltage(void);
extern int ReadDisplayBatteryVoltage(void);

extern int ReadEventReportInfo(void);
extern int GetEventReportMode(void);
extern int SetEventReportMode(void);

extern int SetPowerOnFullScreenTime(void);

extern int Set_SystemTime_YMDHHMS(void);

extern int GetMeterSoftIdNumber(void);
extern int SetMeterSoftIdNumber(void);

extern int GetNowMonthComActiveEnergy(void);
extern int GetLastMonthComActiveEnergy(void);

extern int Set_Freeze_Day(void);

extern int ReadEnergy01Wh(void);

extern int ResetEventReportInfo(void);
extern void Clear_EventReportStatus_And_Times(union EVENT_REPORT_STATUS EventReportStatus);
extern int Set_ResetReportTime(void);

extern int Set_Read_Block_Para(union ID id,unsigned char *rBuffer,unsigned char data_len,unsigned char mode);

#endif
/********************new 645 add by fxf081116***************/
