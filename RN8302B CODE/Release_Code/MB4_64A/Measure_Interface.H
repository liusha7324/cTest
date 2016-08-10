#ifndef _Measure_Interface_h_
#define _Measure_Interface_h_

#include "Defdata.h"
#include "RN8302B_Meter.h" 


#define ENERGY_VALUE_01KWH		10000			/*"0.01kW.h"*/
#define ENERGY_VALUE_001KWH		1000			/*"0.001kW.h"*/
#define ANHOUR_VALUE_01ANH		360000			/*"将0.0001An.s转换成0.01An.h"*/
#define KA2H_01						360000000		/*"将0.0000001kA2s转换成0.01kA2h:(I*I)/10000*0.0000001kA2s"*/
#define MV2H_01						3600000000		/*"将0.00000001MV2s转换成0.01MV2h:(V*V)/1000000*0.00000001MV2s"*/
#define Hechengwucha_01				3600			/*"将100Pi/Pr*s转换成0.01Pi/Pr*h"*/

#define PULSE_WIDTH              80
#define ENERGY_VALUE_1MWH_100MWH    100   /*"change 1mwh to 100mwh "*/
#define ENERGY_VALUE_100MWH_001WH   10    /*"change 100mwh to 0.001kwh "*/

/*"校表参数结构体的大小必须为4的整数倍"*/
struct JUSTMETER_PARAMETER
{
    struct stMeter_Meas_Pra   rMeter_Meas_Pra;
    struct stMeter_Power_Pra  rMeter_Power_Pra;
    struct stMeter_Config_Pra  rMeter_Config_Pra;
    struct stMeter_Extra_Pra   rMeter_Extra_Pra;

    struct stMeter_Spec_Pra   rMeter_Spec_Pra;

    UINT16  wResv;        /*"增加一个2字节的保留参数，使校表参数结构体的大小为4的整数倍"*/
    UINT16  wPraCrc;     
};


#define POWER_LIMIT                 JustMeter_Parameter.rMeter_Spec_Pra.dwPwrLimit
#define ENERGY_LIMIT                JustMeter_Parameter.rMeter_Spec_Pra.dwEngLimit

#define VOLT_LIMIT                     (JustMeter_Parameter.rMeter_Spec_Pra.dwVoltSpec * 3L)
#define VOLT_SPEC                      JustMeter_Parameter.rMeter_Spec_Pra.dwVoltSpec
#define CURR_SPEC                      JustMeter_Parameter.rMeter_Spec_Pra.dwCurrSpec
#define PULSE_CONST_H              JustMeter_Parameter.rMeter_Spec_Pra.dwCFConstH


extern struct JUSTMETER_PARAMETER   JustMeter_Parameter;

extern UINT32 angle[3];

extern UINT8 auxiliary_power_flag;  

extern union byte_def flag_communication_with_measuring_board;
#define Abnormal_Phase_I_sequence	flag_communication_with_measuring_board.bit.b5
#define Abnormal_Phase_sequence		flag_communication_with_measuring_board.bit.b6  /*"1:abnormal phase sequence,0:normal phase sequence"*/
#define Meter_331_LostVoltage_B		flag_communication_with_measuring_board.bit.b7  /*"331表B相失压"*/

extern volatile UINT32 temperatrue;

extern BOOL _fgMeter_Noload;
extern UINT8 Pulse_Constant_Writting;

extern UINT8 Volt_Region;
extern UINT8 Curr_Region;

#define V_REGION    Volt_Region     
#define I_REGION    Curr_Region 
extern UINT8 load_flag;      /*"校表参数加载标志 0：不需要 0xff:需要"*/ 

extern void vMeter_RstDir(BOOL fgDir);
extern void vMeter_RstOut(BOOL fgLevel);
extern void vMeter_SleepDir(BOOL fgDir);
extern void vMeter_SleepOut(BOOL fgLevel);

extern void vMeter_SPI_Init(void);
extern BOOL vMeter_SPI_WriteReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen);
extern BOOL vMeter_SPI_ReadReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen);

extern void Deal_PulseConst_Init(void);
extern UINT8 fgMeter_Com_Process(UINT8 *commad_addr, UINT8 *reg_addr, 
                                 UINT8 *sour_addr, UINT8 *des_addr);
extern BOOL fgMeter_PowerOn_Init(void);
extern void vMeter_VoltCurrSpecInit(void);
extern void Measure_Deal_Every_Second(void);
extern void Energy_Accumulation_Unit_10Wh(void);
extern void Middle_Energy_Accumulation_PerSecond_Main_Program(void);
extern void Get_Quadrant_Value(UINT16 *Quadrant_P);
extern UINT8 Send_Pulse_Constant_Data_to_Meter(UINT8 kind,UINT32 Acconst);
extern UINT8 Check_RAM_CRC(UINT8 *source_addr, UINT16 comp_value, UINT16 crc_len);
extern void Delay_Wait(UINT16 unit_10_uS);
extern void Just_meter_PD(void);
extern void Init_Relation_Meter_Apply(void);
extern UINT32 Get_Max_Value(UINT32 X,UINT32 Y,UINT32 Z);
extern void Just_para_Power_on(void);
extern void Check_If_Writting_Pulse_Constant_To_Card(void);
extern void Voltage_Phase_Deal(void);
extern BOOL fgJustParaRamCrcOk(void);
extern BOOL fgJustParaHandler(void);

extern void vMeter_ResInterface(void);
extern BOOL fgJustParaPDLoad(void);


#endif
