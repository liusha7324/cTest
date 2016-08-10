/*"************************************************************"*/
/*"  Copyright (C), 1988-1999, Wasion Group  "*/
/*"  FileName:     HT7038_Meter.h  "*/
/*"  Description:  HT7038_Meter driver file  "*/
/*"  Author:    jiehuang      "*/
/*"  Version :  1.0        "*/
/*"  Date:   2015/09/28  "*/
/*"  Funciton list:  "*/


/*"  History:         "*/
/*"  <author>   <time>    <version >       <desc>  "*/
/*"  jiehuang   2015/09/28    1.0           build this moudle  "*/
/*"***********************************************************"*/
  
#ifndef __RN8302B_Meter_H__
#define __RN8302B_Meter_H__

/*"***************************************************"*/
/*"�������ͼ��궨��"*/
/*"***************************************************"*/
typedef unsigned char BOOL;           /*"��������1�ֽ�"*/
typedef unsigned char UINT8;          /*"�޷���1�ֽ�"*/
typedef signed char SINT8;             /*"�з���1�ֽ�"*/
typedef unsigned int UINT16;         /*"�޷���2�ֽ�"*/
typedef signed int SINT16;             /*"�з���2�ֽ�"*/
typedef unsigned long UINT32;       /*"�޷���4�ֽ�"*/
typedef signed long SINT32;           /*"�з���4�ֽ�"*/
typedef unsigned long long UINT64;   /*"�޷���8�ֽ�"*/
typedef signed long long SINT64;       /*"�з���8�ֽ�"*/
typedef float FP32;       /*"�����ȸ�����"*/
typedef double FP64;    /*"˫���ȸ�����"*/

#define FALSE      0
#define TRUE       1

#define SV_PIN_INPUT         0
#define SV_PIN_OUTPUT      1

#define SV_LOW           0
#define SV_HIGH          1

/*"***************************************************"*/
/*"��������汾ѡ��"*/
/*"***************************************************"*/
#define WS_METER_SW_VER     0x16061400


#define WS_STATEGRID_VERSION
#ifdef WS_STATEGRID_VERSION
#define WS_ERR_OFFSET_FUNC      /*"add by jie huang 2013/06/21 to support error offset funcion"*/ 
//#define WS_ERR_OFFSET_EXTRA    /*"add by jie huang 2013/10/09 to support self heating and 5 order harm offset"*/
#endif


/*"***************************************************"*/
/*"ͨ�ù��ܺ궨��"*/
/*"***************************************************"*/
//#define WS_SUPPORT_SIMULATION    /*"add by jie huang 2011/05/13 to support simulation function"*/ 


#define WS_METER_SPEC_STATUS_DEAL   /*"add by jiehuang 20110623 to deal with meter special status"*/ 
#define WS_METER_ENERGY_TRANSFER    /*"add by jiehuang 2011/08/16 to solve energy accumulation issue"*/ 
//#define WS_METER_SUPPORT_SENERGY   
#define WS_METER_SUPPORT_SRMS   /*"add by jiehuang 2015/10/22 to support S power calculate by RMS"*/ 
//#define WS_METER_CURR_FILTER  /*"���HT7038оƬ�򾲵��и�Ӧ����������  �ƽ� 2015/12/10"*/ 


/*"***************************************************"*/
/*"��������buffer������"*/
/*"***************************************************"*/
typedef struct _stMeter_Data_Buffer
{
    UINT32 dwVolt[3];  /*"ABC���ѹ ��λ0.0001V"*/
    UINT32 dwCurr[3]; /*"ABC����� ��λ0.0001A"*/

    UINT32 dwNCurr;  /*"���ߵ�������ֵ ��λ0.0001A"*/
    UINT32 dwNCurrCal;  /*"���ߵ�������ֵ ��λ0.0001A"*/

    UINT8 bPowerDir;  /*"���ʷ���"*/
    UINT32 dwP[4];   /*"TABC�й����� ��λ1mW"*/
    UINT32 dwQ[4];   /*"TABC�޹����� ��λ1mVar"*/
    UINT32 dwS[4];   /*"TABC���ڹ��� ��λ1mVA"*/

    UINT32 dwFre[3];  /*"Ƶ�� ��λ0.000001Hz"*/

    UINT32 dwUAngle[3];  /*"ABC��ѹ���� ��λ0.01��"*/ 
	UINT32 dwIAngle[3];  /*"ABC��ѹ���� ��λ0.01��"*/ 
    UINT32 dwPAngle[3];  /*"ABC��ѹ��������� ��λ0.01��"*/

    UINT32 dwPF[4];  /*"TABC�������� ��λ0.000001"*/

    SINT32 lTemp;  /*"�¶� ��λ0.1��"*/

    UINT8 bState0;
    UINT8 bState1;
    UINT8 bState2;

    BOOL fgNoLoad ;  /*"Ǳ����־"*/

    UINT32 dwActEnergy[4];  /*"TABC�й����� ��λ1mWS"*/
    UINT32 dwReActEnergy[4];  /*"TABC�޹����� ��λ1mWS"*/
#ifdef WS_METER_SUPPORT_SENERGY	
    UINT32 dwSEnergy[4];  /*"TABC���ڵ��� ��λ1mWS"*/
#endif	
}stMeter_Data_Buffer;


/*"***************************************************"*/
/*"���ʷ���bPowerDir��bitλ����"*/
/*"8��bit�ֱ��ʾTABC�й����޹��Ĺ��ʷ���bitֵΪ0��ʾ����Ϊ1��ʾ����"*/
/*"***************************************************"*/
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

/*"***************************************************"*/
/*"EMUState�Ĵ�����bitλ����"*/
/*"***************************************************"*/
#define EMUSTATE_U_ORDER              3
#define EMUSTATE_I_ORDER               4

#define EMUSTATE_ACT_NoLoad_A               0
#define EMUSTATE_ACT_NoLoad_B               1
#define EMUSTATE_ACT_NoLoad_C               2
#define EMUSTATE_REACT_NoLoad_A             4
#define EMUSTATE_REACT_NoLoad_B             5
#define EMUSTATE_REACT_NoLoad_C             6


/*"***************************************************"*/
/*"״̬0 bState0��bitλ����"*/
/*"***************************************************"*/
enum
{
    STATE0_RESERVED0,
    STATE0_RESERVED1,
    STATE0_VOLT_PHASE_SEQU,   /*"bitֵΪ0��ʾ������Ϊ1��ʾ������"*/
    STATE0_CURR_PHASE_SEQU,   /*"bitֵΪ0��ʾ������Ϊ1��ʾ������"*/
    STATE0_RESERVED4,
    STATE0_RESERVED5,
    STATE0_RESERVED6,
    STATE0_RESERVED7
};

/*"***************************************************"*/
/*"����״̬buffer������"*/
/*"***************************************************"*/
typedef struct _stMeter_State_Buffer
{
    UINT32 dwVersion;

    UINT8 bCalState;

    BOOL fgPraLoadOk;
    BOOL fgDataReady;

    UINT8 bRstType;
    UINT16 wRstCnt;

    UINT8 bICPraChkState;
    UINT8 bICPraErrCnt;

    UINT8 bDataRdErrCnt;
    UINT8 bDataValErrCnt;

}stMeter_State_Buffer;

/*"***************************************************"*/
/*"����ģ����غ궨��"*/
/*"***************************************************"*/
/*"������λ���Ͷ���"*/
enum
{
    METER_RST_TYPE_PWRUP,
    METER_RST_TYPE_PWRDOWN,

    METER_RST_TYPE_PRAERR,
    METER_RST_TYPE_RDERR,
    METER_RST_TYPE_VALERR,

    METER_RST_TYPE_MAX
};

/*"��������ģʽ���Ͷ���"*/
enum
{
    PM_SLEEP,
    PM_NORMAL
};

/*"�������Ͷ���"*/
enum
{
    READ_ENERGY_ACT,
    READ_ENERGY_REACT,
#ifdef WS_METER_SUPPORT_SENERGY		
    READ_ENERGY_S,
#endif	
    READ_ENERGY_MAX
};

enum
{
    READ_ENERGY_NORMAL,
    READ_ENERGY_PD
};

/*"����оƬ�������״̬��"*/
enum
{
    IC_PRA_CHK_STATE_CONFIG,   //check stMeter_Config_Pra
    IC_PRA_CHK_STATE_EXTRA,     //check stMeter_Extra_Pra
    IC_PRA_CHK_STATE_MEAS,       //check stMeter_Meas_Pra
    IC_PRA_CHK_STATE_POWER,    //check stMeter_Power_Pra
    IC_PRA_CHK_STATE_OTHER      //check other para
};

/*"����ģ���ϵ�����"*/
#define SV_WMSW           0xA2
#define SV_SOFTRST        0xFA

/*"����оƬУ�������д����"*/
#define SV_CALI_PRA_RWEN         0xE5
#define SV_CALI_PRA_RWDIS        0xDC

/*"����ģ��У��״̬"*/
#define SV_CAL_STATE_START    0x5a
#define SV_CAL_STATE_END        0x0

/*"����ģ�������������������"*/
#define  METER_IC_PRAERR_TIMES   6
#define  METER_DATA_RDERR_TIMES   10
#define  METER_DATA_VALERR_TIMES   6

#ifdef WS_METER_CURR_FILTER
#define METER_CURR_FILTER_LEN    4
#endif

/*"***************************************************"*/
/*"У�������ؽṹ��"*/
/*"***************************************************"*/
#define METER_CONFIG_PRA_SIZE   (sizeof(struct stMeter_Meas_Pra)/2)
struct stMeter_Config_Pra    /*"���ò����ṹ��"*/
{ 
    UINT16 bWMSW; 
	UINT16 bModeSel; 
    UINT16 wAdcCfg;
    UINT16 HFConst1;
    UINT16 wPStart_PS;
	UINT16 wPStart_Q;
};



#define METER_MEAS_PRA_SIZE   (sizeof(struct stMeter_Meas_Pra)/2)
struct stMeter_Meas_Pra     /*"���������ṹ��"*/
{ 
    UINT16 wUGainA;
    UINT16 wUGainB;
    UINT16 wUGainC;
    UINT16 wIGainA;
    UINT16 wIGainB;
    UINT16 wIGainC;
};

#define METER_POWER_PRA_SIZE   (sizeof(struct stMeter_Power_Pra)/2)
struct stMeter_Power_Pra   /*"���ʲ����ṹ��"*/
{ 
	UINT16 wPGainA;
    UINT16 wPGainB;
    UINT16 wPGainC;
    UINT16 wPhiA;
    UINT16 wPhiB;
    UINT16 wPhiC;
	UINT16 wPoffsetAL;
    UINT16 wPoffsetBL;
    UINT16 wPoffsetCL;
	UINT16 wQoffsetAL;
    UINT16 wQoffsetBL;
    UINT16 wQoffsetCL;
};

#define METER_EXTRA_PRA_SIZE   (sizeof(struct stMeter_Extra_Pra)/4)
struct stMeter_Extra_Pra    /*"��չ�����ṹ��"*/
{ 
    UINT32 dwEMUCfg;
    UINT32 dwEMUCtrl;
    UINT32 dwCFCfg;

};
#define METER_SPEC_PRA_SIZE   (sizeof(struct stMeter_Spec_Pra)/4)                                         
struct stMeter_Spec_Pra   /*"�������ṹ��"*/
{
    UINT32 dwVoltSpec;        
    UINT32 dwCurrSpec;        
    UINT32 dwPwrLimit;           
    UINT32 dwEngLimit;                
    UINT32 dwCFConstH;
	UINT32 dwVoltRatio;
	UINT32 dwCurrRatio;

#ifdef WS_ERR_OFFSET_FUNC
    UINT32 dwGainOffsetNode;
    UINT32 dwGainAOffsetVal;
    UINT32 dwGainBOffsetVal;
    UINT32 dwGainCOffsetVal;

    UINT32 dwPhiOffsetNode;
    UINT32 dwPhiAOffsetVal;
    UINT32 dwPhiBOffsetVal;
    UINT32 dwPhiCOffsetVal;
#endif

#ifdef WS_ERR_OFFSET_EXTRA
    UINT32 dwExtraOffsetVal;
#endif
};

/*"Ĭ��У������ṹ�������ݵ�λ�ñ����� JUSTMETER_PARAMETER ��ͬ"*/
typedef struct _stMeter_JustPraDef
{
    UINT16 rMeter_Meas_Pra_Init[METER_MEAS_PRA_SIZE];
    UINT16 rMeter_Power_Pra_Init[METER_POWER_PRA_SIZE];
    UINT16 rMeter_Config_Pra_Init[METER_CONFIG_PRA_SIZE];
    UINT32 rMeter_Extra_Pra_Init[METER_EXTRA_PRA_SIZE];
    UINT32 rMeter_Spec_Pra_Init[METER_SPEC_PRA_SIZE];
}stMeter_JustPraDef;


#ifdef WS_ERR_OFFSET_FUNC
#define METER_ERROFFSET_PRA_SIZE   (sizeof(stMeter_ErrOffset_Pra)/2)
typedef struct _stMeter_ErrOffset_Pra
{
    UINT16 wGainAVal;
    UINT16 wGainBVal;
    UINT16 wGainCVal;

    UINT16 wPhiAVal;
    UINT16 wPhiBVal;
    UINT16 wPhiCVal;

}stMeter_ErrOffset_Pra;

extern stMeter_ErrOffset_Pra _rMeter_ErrOffset_Pra;
#endif


/*"***************************************************"*/
/*"����ģ���ⲿ��������������"*/
/*"***************************************************"*/
 
extern stMeter_Data_Buffer  _rMeter_Data_Buffer;
extern stMeter_State_Buffer  _rMeter_State_Buffer;

extern const stMeter_JustPraDef _rMeter_JustPraDef;

extern void vDelay_Us(UINT16 wCnt);
extern void vDelay_Ms(UINT16 wCnt);
extern void vMeter_Version(void);
extern void vMeter_Init(UINT8 bType);

extern BOOL fgMeter_Para_Init(void);
extern BOOL fgMeter_Function(void);
extern BOOL fgMeter_Com_JustParaSet(UINT8 bCommAddr,UINT32 dwCalData);
extern BOOL fgMeter_Para_Load(void);    
extern BOOL fgMeter_ICPraOk(void);
 
extern BOOL fgMeter_GetVolt(void);
extern BOOL fgMeter_GetCurr(void);
extern BOOL fgMeter_GetEnergy_Pd(void);

#ifdef WS_ERR_OFFSET_FUNC
extern void vMeter_ErrOffsetPraSave(void);
extern void vMeter_ErrOffsetPraSave1(UINT8 bIndex);
extern void vMeter_ErrOffsetAdjust(BOOL fgInCal);
#endif

#endif


