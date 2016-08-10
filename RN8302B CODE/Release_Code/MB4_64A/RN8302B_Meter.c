/*"************************************************************"*/
/*"  Copyright (C), 1988-1999, Wasion Group  "*/
/*"  FileName:     HT7038_Meter.c  "*/
/*"  Description:  HT7038_Meter driver file  "*/
/*"  Author:    jiehuang      "*/
/*"  Version :  1.0        "*/
/*"  Date:   2015/09/28  "*/
/*"  Funciton list:  "*/


/*"  History:         "*/
/*"  <author>   <time>    <version >       <desc>  "*/
/*"  jiehuang   2015/09/28    1.0           build this moudle  "*/
/*"***********************************************************"*/
#include  "Defdata.h"
#include  "ram.h"
#include  "Multi.h"
#include  "interrupt.h"
#include  <math.h>
#include  <float.h>
#include  "RN8302B_Meter.h" 
#include  "Measure_Interface.h"

#pragma SECTION program ROM_PRG2   

/*"****************************************************************"*/
/*"  Meter  register define  :全波计量参数寄存器"*/   
/*"****************************************************************"*/
#define  r_UA               0x07                    /*"A相电压有效值"*/
#define  r_UB               0x08                    /*"B相电压有效值"*/
#define  r_UC               0x09                    /*"C相电压有效值"*/
#define  r_USUM             0x0A                    /*"电压矢量和有效值"*/
#define  r_IA               0x0B                    /*"A相电流有效值"*/
#define  r_IB               0x0C                    /*"B相电流有效值"*/
#define  r_IC               0x0D                    /*"C相电流有效值"*/
#define  r_IN               0x0E                    /*"零线电流有效值"*/
#define  r_ISUM             0x10                    /*"电流矢量和有效值"*/
#define  r_PA               0x14                    /*"A相有功功率"*/
#define  r_PB               0x15                    /*"B相有功功率"*/
#define  r_PC               0x16                    /*"C相有功功率"*/
#define  r_PT               0x17                    /*"合相有功功率"*/
#define  r_QA               0x18                    /*"A相无功功率"*/
#define  r_QB               0x19                    /*"B相无功功率"*/
#define  r_QC               0x1A                    /*"C相无功功率"*/
#define  r_QT               0x1B                    /*"合相无功功率"*/
#define  r_SA               0x1C                    /*"A相视在功率"*/
#define  r_SB               0x1D                    /*"B相视在功率"*/
#define  r_SC               0x1E                    /*"C相视在功率"*/
#define  r_STA              0x1F                    /*"RMS合相视在功率"*/

#define  r_PfA              0x20                    /*"A相功率因数"*/
#define  r_PfB              0x21                    /*"B相功率因数"*/
#define  r_PfC              0x22                    /*"C相功率因数"*/
#define  r_PfTV             0x4D                    /*"PQS合相功率因数"*/

#define  r_PfTA             0x23                    /*"RMS合相功率因数"*/
#define  r_PAFCnt           0x24                    /*"A相有功快速脉冲计数"*/
#define  r_PBFCnt           0x25                    /*"B相有功快速脉冲计数"*/
#define  r_PCFCnt           0x26                    /*"C相有功快速脉冲计数"*/
#define  r_PTFCnt           0x27                    /*"合相有功快速脉冲计数"*/

#define  r_EPA              0x30                    /*"A相有功能量寄存器"*/
#define  r_EPB              0x31                    /*"B相有功能量寄存器"*/
#define  r_EPC              0x32                    /*"C相有功能量寄存器"*/
#define  r_EPT              0x33                    /*"合相有功能量寄存器"*/
#define  r_EQA              0x3C                    /*"A相无功能量寄存器"*/
#define  r_EQB              0x3D                    /*"B相无功能量寄存器"*/
#define  r_EQC              0x3E                    /*"C相无功能量寄存器"*/
#define  r_EQT              0x3F                    /*"合相无功能量寄存器"*/
#define  r_ESA              0x48                    /*"A相视在能量寄存器"*/
#define  r_ESB              0x49                    /*"B相视在能量寄存器"*/
#define  r_ESC              0x4A                    /*"C相视在能量寄存器"*/
#define  r_EST              0x4B                    /*"RMS合相视在能量寄存器"*/

#define  r_YUA           	0x50                    /*"采样通道UA基波相角寄存器"*/
#define  r_YUB           	0x51                    /*"采样通道UB基波相角寄存器"*/
#define  r_YUC           	0x52                    /*"采样通道UC基波相角寄存器"*/
#define  r_YIA        	    0x53                    /*"采样通道IA基波相角寄存器"*/
#define  r_YIB              0x54                    /*"采样通道IB基波相角寄存器"*/
#define  r_YIC           	0x55                    /*"采样通道IC基波相角寄存器"*/
#define  r_YIN           	0x56                    /*"采样通道IN基波相角寄存器"*/
#define  r_UFreq            0x57                    /*"电压线频率"*/


/*"****************************************************************"*/
/*"  Meter  register define  :配置和状态寄存器"*/   
/*"****************************************************************"*/
#define  w_PRTH1L           0x106          /*"2字节，相位分段校正电流阈值1下限"*/            
#define  w_PRTH1H           0x107          /*"2字节，相位分段校正电流阈值1上限"*/
#define  w_PRTH2L           0x108          /*"2字节，相位分段校正电流阈值2下限"*/ 
#define  w_PRTH2H           0x109          /*"2字节，相位分段校正电流阈值2上限"*/

#define  w_UgainA           0x113          /*"2字节，采样通道UA通道增益"*/
#define  w_UgainB           0x114          /*"2字节，采样通道UB通道增益"*/
#define  w_UgainC           0x115          /*"2字节，采样通道UC通道增益"*/
#define  w_IgainA           0x116          /*"2字节，采样通道IA通道增益"*/
#define  w_IgainB           0x117          /*"2字节，采样通道IB通道增益"*/
#define  w_IgainC           0x118          /*"2字节，采样通道IC通道增益"*/
#define  w_IgainN           0x119          /*"2字节，采样通道IN通道增益"*/

#define  w_PGainA           0x128          /*"2字节，A相有功功率增益"*/
#define  w_PGainB           0x129          /*"2字节，B相有功功率增益"*/ 
#define  w_PGainC           0x12A          /*"2字节，C相有功功率增益"*/
#define  w_QGainA           0x12B          /*"2字节，A相无功功率增益"*/
#define  w_QGainB           0x12C          /*"2字节，B相无功功率增益"*/ 
#define  w_QGainC           0x12D          /*"2字节，C相无功功率增益"*/

#define  w_PhiA             0x131          /*"2字节，A相有功相位校正-低段"*/
#define  w_PhiB             0x132          /*"2字节，B相有功相位校正-低段"*/
#define  w_PhiC             0x133          /*"2字节，C相有功相位校正-低段"*/
#define  w_QPhiA            0x134          /*"2字节，A相无功相位校正-低段"*/
#define  w_QPhiB            0x135          /*"2字节，B相无功相位校正-低段"*/
#define  w_QPhiC            0x136          /*"2字节，C相无功相位校正-低段"*/

#define  w_PoffsetA         0x137          /*"2字节，A相有功功率偏置校正"*/
#define  w_PoffsetB         0x138          /*"2字节，B相有功功率偏置校正"*/
#define  w_PoffsetC         0x139          /*"2字节，C相有功功率偏置校正"*/
#define  w_QoffsetA         0x13A          /*"2字节，A相无功功率偏置校正"*/
#define  w_QoffsetB         0x13B          /*"2字节，B相无功功率偏置校正"*/
#define  w_QoffsetC         0x13C          /*"2字节，C相无功功率偏置校正"*/



#define  w_HFConst1         0x100          /*"2字节，高频脉冲计数寄存器1"*/
#define  w_HFConst2         0x101          /*"2字节，高频脉冲计数寄存器2"*/
#define  w_IStart_PS        0x102          /*"2字节，有功视在启动电流阈值寄存器"*/
#define  w_IStart_Q         0x103          /*"2字节，无功启动电流阈值寄存器"*/

#define  w_CFCFG            0x160          /*"3字节，CF引脚配置寄存器"*/
#define  w_EMUCFG           0x161          /*"3字节，EMU配置寄存器"*/
#define  w_EMUCON           0x162          /*"3字节，EMU控制寄存器"*/
#define  w_WSAVECON         0x163          /*"1字节，采样数据写缓存控制寄存器"*/

#define  w_PQSign           0x166          /*"2字节，有功无功功率方向寄存器"*/
#define  w_Noload           0x167          /*"2字节，潜动启动状态寄存器"*/
#define  w_PHASES           0x169          /*"2字节，相电压电流状态寄存器"*/

#define  r_CheckSum1        0x16A          /*"3字节，EMM校表和配置寄存器校验和"*/
#define  r_CheckSum2        0x18B          /*"2字节，NVM1、NVM2、系统配置寄存器校验和"*/

#define  w_WREN             0x180          /*"1字节，写使能寄存器"*/ 
#define  w_WMSW             0x181          /*"1字节，工作模式切换寄存器"*/ 
#define  w_SOFTRST          0x182          /*"1字节，软件复位寄存器"*/
#define  w_ADCCFG           0x183          /*"2字节，ADC配置寄存器"*/
#define  w_MODSEL           0x186          /*"1字节，三相四线/三相三线模式选择寄存器"*/


#define  r_RData            0x18C          /*"4字节，上一次SPI读出的数据"*/
#define  r_WData            0x18D          /*"3字节，上一次SPI写入的数据"*/

#define  r_DeviceID         0x18F          /*"3字节，Device ID,默认值0x830200"*/


/*"***************************************************"*/
/*"变量定义"*/
/*"***************************************************"*/
stMeter_Data_Buffer _rMeter_Data_Buffer;
stMeter_State_Buffer _rMeter_State_Buffer = 
    {WS_METER_SW_VER,SV_CAL_STATE_END,FALSE,FALSE,METER_RST_TYPE_PWRUP,0,IC_PRA_CHK_STATE_CONFIG,0,0,0};


/*"***************************************************"*/
/*"函数声明"*/
/*"***************************************************"*/
BOOL fgMeter_GetVolt(void);
BOOL fgMeter_GetCurr(void);
BOOL fgMeter_GetNCurr(void);
BOOL fgMeter_GetP(void);
BOOL fgMeter_GetQ(void);
BOOL fgMeter_GetS(void);
BOOL fgMeter_GetPF(void);
BOOL fgMeter_GetFreq(void);
BOOL fgMeter_GetState(void);
BOOL fgMeter_GetAngle(void);
BOOL fgMeter_GetEnergy(void);

/*"***************************************************"*/
/*"校表参数默认值"*/
/*"***************************************************"*/
#pragma SECTION rom UserROMData
const stMeter_JustPraDef _rMeter_JustPraDef = 
{      
    /*"rMeter_Meas_Pra_Init"*/
    {  
        0x0000,   /*"wUGainA"*/          
        0x0000,   /*"wUGainB"*/          
        0x0000,   /*"wUGainC"*/          
        0x0000,   /*"wIGainA"*/      
        0x0000,   /*"wIGainB"*/          
        0x0000,   /*"wIGainC"*/            
    },  

    /*"rMeter_Power_Pra_Init"*/
    {  
		0x0000,    /*"wPGainA"*/       
        0x0000,    /*"wPGainB"*/     
        0x0000,    /*"wPGainC"*/    
        0x0000,    /*"wPhiA"*/       
        0x0000,    /*"wPhiB"*/           
        0x0000,    /*"wPhiC"*/  
        0x0000,    /*"wPoffsetA"*/      
        0x0000,    /*"wPoffsetB"*/     
        0x0000,    /*"wPoffsetC"*/    
       	0x0000,    /*"wQoffsetA"*/             
        0x0000,    /*"wQoffsetB"*/        
        0x0000,    /*"wQoffsetC"*/ 
                     
    },

    /*"rMeter_Config_Pra_Init"*/
    {  
        0x00A2,        /*"bWMSW"*/            
        0x0000,        /*"bModeSel"*/ 
        0x0000,      /*"wAdcCfg"*/ 
        0x2267,      /*"HFConst1"*/         
        0x0D1B,      /*"wPStart_PS"*/ 
        0x1062,      /*"wPStart_Q"*/ 
    }, 

    /*"rMeter_Extra_Pra_Init"*/
    {  
        0x00400000,    /*"dwEMUCfg"*/      
        0x00777777,    /*"dwEMUCtrl"*/       
        0x00043210,    /*"dwCFCfg"*/ 
    }, 

    /*"rMeter_Spec_Pra_Init"*/
    {
        0x002191C0,  /*"dwVoltSpec (220V)"*/        
        0x00003A98,  /*"dwCurrSpec (1.5A)"*/           
        0x016A8C80,  /*"dwPwrLimit"*/                              
        0x00002AF8,  /*"dwEngLimit"*/                    
        0x00001900,  /*"dwCFconstH"*/ 
        0x0320002F,  /*dwVoltRatio*/
        0x012C00C8,  /*dwCurrRatio*/

    #ifdef WS_ERR_OFFSET_FUNC
        0x00000000,  /*"dwGainOffsetNode (unit is IB,IB,0.01IB,0.01IB)"*/
        0x00000000,  /*"dwGainAOffsetVal"*/
        0x00000000,  /*"dwGainBOffsetVal"*/
        0x00000000,  /*"dwGainCOffsetVal"*/

        0x00000000,  /*"dwPhiOffsetNode  (unit is IB,IB,0.01IB,0.01IB)"*/
        0x00000000,  /*"dwPhiAOffsetVal"*/
        0x00000000,  /*"dwPhiBOffsetVal"*/
        0x00000000,  /*"dwPhiCOffsetVal"*/
    #endif

    #ifdef WS_ERR_OFFSET_EXTRA
        0x00000000   /*"dwExtraOffsetVal"*/
    #endif
    }
};


/*"***************************************************"*/
/*"延时函数定义"*/
/*"***************************************************"*/
void vDelay_Us(UINT16 wCnt)
{
    while(wCnt--);
}

void vDelay_Ms(UINT16 wCnt)   
{
    UINT16 ii;
    
    while(wCnt--)
    {
        FeedWatchdog();
        for (ii = 0;ii < 1412;ii++);
    }
}


/*"***************************************************"*/
/*"通信函数定义"*/
/*"***************************************************"*/

BOOL fgMeter_SPI_ReadChkData(UINT16 bAddr,UINT32 *pdwData,UINT8 bLen)  
{
    UINT8 ii;
    BOOL fgRet = FALSE;
    UINT32 dwTemp0,dwTemp1;
	dwTemp0=0;
	dwTemp1=0;
    for(ii = 0;ii < 3;ii++)
    {
		if(vMeter_SPI_ReadReg( bAddr, (UINT8 *)&dwTemp0, bLen))
		{
			vDelay_Us(10);
			if(vMeter_SPI_ReadReg(r_RData,(UINT8 *)&dwTemp1,4))
			{
				if(dwTemp0==dwTemp1)
				{
					fgRet = TRUE;
           			*pdwData = dwTemp0;
            		break;	
				}
			}
		}
        vDelay_Us(100);
    }
    return (fgRet);
}
BOOL fgMeter_SPI_WriteChkData(UINT16 bAddr,UINT32 dwData,UINT8 bLen)  
{
    UINT8 ii;
    BOOL fgRet = FALSE;
    UINT32 dwTemp1;
	dwTemp1=0;

    for(ii = 0;ii < 3;ii++)
    {
    	
		if(vMeter_SPI_WriteReg( bAddr, (UINT8 *)&dwData, bLen))
		{
			vDelay_Us(20);
			if(vMeter_SPI_ReadReg(r_WData,(UINT8 *)&dwTemp1,3))
			{
				if(dwData==dwTemp1)
				{
					fgRet = TRUE;
            		break;	
				}
			}
		}
        vDelay_Us(100);
    }
    return (fgRet);
}

BOOL fgMeter_CaliPraWEn(BOOL fgCtrl)
{
    BOOL fgRet = FALSE;

    if(fgCtrl)
    {
        fgRet = fgMeter_SPI_WriteChkData(w_WREN,SV_CALI_PRA_RWEN,1);  
    }
    else
    {
        fgRet = fgMeter_SPI_WriteChkData(w_WREN,SV_CALI_PRA_RWDIS,1);  
    }

    return(fgRet);   
}

BOOL fgMeter_SPI_WriteChkData2(UINT16 bAddr,UINT32 dwData,UINT8 bLen) 
{
    BOOL fgRet = TRUE;

    if(!fgMeter_CaliPraWEn(TRUE))
    {
        return(FALSE);
    }

    if(!fgMeter_SPI_WriteChkData(bAddr,dwData,bLen))  
    {
        fgRet = FALSE;   	
    }

    if((bAddr == w_PGainA) || (bAddr == w_PGainB) || (bAddr == w_PGainC))
    {
        if(!fgMeter_SPI_WriteChkData(w_QGainA + (bAddr - w_PGainA),dwData,bLen))  
        {
            fgRet = FALSE;   	
        }  
    }
	if((bAddr == w_PhiA) || (bAddr == w_PhiB) || (bAddr == w_PhiC))
    {
        if(!fgMeter_SPI_WriteChkData(w_QPhiA + (bAddr - w_PhiA),dwData,bLen))  
        {
            fgRet = FALSE;   	
        }  
    }

    if(!fgMeter_CaliPraWEn(FALSE))  
    {
        return(FALSE);
    }
    return (fgRet);
}


/*"***************************************************"*/
/*"初始化模块函数定义"*/
/*"***************************************************"*/
void vMeter_Version(void)
{
    UINT8 bTemp = 0;

#if defined(WS_STATEGRID_VERSION)
    bTemp = 0x00;
#endif

    _rMeter_State_Buffer.dwVersion = WS_METER_SW_VER + bTemp;
}

 void vMeter_ModeSet(UINT8 bMode)
{
    vMeter_SleepDir(SV_PIN_OUTPUT);

    switch(bMode)
    {
        case PM_SLEEP:
            vMeter_SleepOut(SV_HIGH);
            break;
        case PM_NORMAL:
            vMeter_SleepOut(SV_LOW);
            break;
        default:
            vMeter_SleepOut(SV_LOW);
            break;
    }
}


void vMeter_Init(UINT8 bType)
{
    UINT16 ii;

    FeedWatchdog();	 
    CheckPowerDown();

    /*"Step 1:计量芯片复位、工作模式设置和通信引脚配置"*/
    vMeter_RstDir(SV_PIN_OUTPUT);
    vMeter_RstOut(SV_HIGH);
    vDelay_Ms(5);
    vMeter_RstOut(SV_LOW);
    vDelay_Ms(10);
    vMeter_RstOut(SV_HIGH);
    vDelay_Ms(5);

    vMeter_ModeSet(PM_NORMAL);

    vMeter_SPI_Init();   

    FeedWatchdog();	 
    CheckPowerDown();

	fgMeter_CaliPraWEn(TRUE);
	fgMeter_SPI_WriteChkData(w_WMSW,SV_WMSW,1);
	fgMeter_SPI_WriteChkData(w_SOFTRST,SV_SOFTRST,1);
	/*"计量芯片稳定时间60ms"*/
    for(ii=0;ii<3;ii++)
    {
        vDelay_Ms(20); 
        CheckPowerDown();
    }

    /*"Step 2:计量模块变量初始化"*/
    for(ii = 0;ii < sizeof(stMeter_Data_Buffer);ii++)
    {
        *((UINT8*)&_rMeter_Data_Buffer + ii) = 0;
    }

    _rMeter_State_Buffer.bCalState = SV_CAL_STATE_END;
    _rMeter_State_Buffer.fgPraLoadOk = FALSE;
    _rMeter_State_Buffer.fgDataReady = FALSE;

    _rMeter_State_Buffer.bRstType = bType;
    _rMeter_State_Buffer.wRstCnt++;
    if(_rMeter_State_Buffer.wRstCnt >= 60000) 
    {
        _rMeter_State_Buffer.wRstCnt = 0;
    }

    _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_CONFIG;
    _rMeter_State_Buffer.bICPraErrCnt = 0;
    
    _rMeter_State_Buffer.bDataRdErrCnt= 0;
    _rMeter_State_Buffer.bDataValErrCnt= 0;

    FeedWatchdog();
    CheckPowerDown();

}


const UINT16 _bMeter_Config_Pra_Addr[METER_CONFIG_PRA_SIZE] = 
                         {w_WMSW,w_MODSEL,w_ADCCFG,w_HFConst1,w_IStart_PS,w_IStart_Q};
const UINT8 _bMeter_Config_Pra_Len[METER_CONFIG_PRA_SIZE] = 
                         {1,1,2,2,2,2};
BOOL fgMeter_Config_Pra_Init(void)
{
    UINT8 ii;
	BOOL fgRet2 = FALSE;

    FeedWatchdog();	 
    CheckPowerDown();

    for(ii = 0;ii < METER_CONFIG_PRA_SIZE;ii++)
    {
		if(!fgMeter_SPI_WriteChkData(_bMeter_Config_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Config_Pra.bWMSW + ii),*((UINT8 *)&_bMeter_Config_Pra_Len+ ii)))
		{
            return(FALSE);  
        }  
    }	   

    return(TRUE);   
}


const UINT16 _bMeter_Extra_Pra_Addr[METER_EXTRA_PRA_SIZE] = 
                        {w_EMUCFG,w_EMUCON,w_CFCFG};
BOOL fgMeter_Extra_Pra_Init(void)
{
    UINT8 ii;

    FeedWatchdog();	 
    CheckPowerDown();

    for(ii = 0;ii < METER_EXTRA_PRA_SIZE;ii++)
    {
        if(!fgMeter_SPI_WriteChkData(_bMeter_Extra_Pra_Addr[ii],*((UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg + ii),3))
        {
            return(FALSE);  
        }  
    }	   
    return(TRUE);   
}

const UINT16 _bMeter_Meas_Pra_Addr[METER_MEAS_PRA_SIZE] = 
                        {w_UgainA,w_UgainB,w_UgainC,w_IgainA,w_IgainB,w_IgainC};
BOOL fgMeter_Meas_Pra_Init(void)
{
    UINT8 ii;

    FeedWatchdog();	 
    CheckPowerDown();

    for(ii = 0;ii < METER_MEAS_PRA_SIZE;ii++) 
    {
		if(!fgMeter_SPI_WriteChkData(_bMeter_Meas_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA + ii),2))
        {
            return(FALSE);  
        }  
    } 
    return(TRUE);   
}


const UINT16 _bMeter_Power_Pra_Addr[METER_POWER_PRA_SIZE] = 
                        {w_PGainA,w_PGainB,w_PGainC,w_PhiA,w_PhiB,w_PhiC,
                         	w_PoffsetA,w_PoffsetB,w_PoffsetC,w_QoffsetA,w_QoffsetB,w_QoffsetC};
                                        
BOOL fgMeter_Power_Pra_Init(void)
{
    UINT8 ii;

    FeedWatchdog();	 
    CheckPowerDown();

    for(ii = 0;ii < METER_POWER_PRA_SIZE;ii++) 
    {
        if(!fgMeter_SPI_WriteChkData(_bMeter_Power_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA+ ii),2))
        {
            return(FALSE);  
        }  
    }
	
	for(ii=0;ii<3;ii++) 
    {
        if(!fgMeter_SPI_WriteChkData(w_QGainA + ii,*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA + ii),2))
        {
            return(FALSE);  
        }  

        if(!fgMeter_SPI_WriteChkData(w_QPhiA + ii,*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPhiA + ii),2))
        {
            return(FALSE);  
        }  
    }
    return(TRUE);   
}


BOOL fgMeter_CleanEnergy(void)
{
    UINT8 ii;
    UINT32 dwTemp;

    FeedWatchdog();	 
    CheckPowerDown();
    
    for(ii = 0;ii < 4;ii++)
    {
        if(!fgMeter_SPI_ReadChkData(r_EPA+ ii,(UINT32 *)&dwTemp,3))
        {
            return(FALSE);
        }
    }
	for(ii = 0;ii < 4;ii++)
    {
        if(!fgMeter_SPI_ReadChkData(r_EQA+ ii,(UINT32 *)&dwTemp,3))
        {
            return(FALSE);
        }
    }

#ifdef WS_METER_SUPPORT_SENERGY		
    for(ii = 0;ii < 4;ii++)
    {
        if(!fgMeter_SPI_ReadChkData(r_ESA + ii,(UINT32 *)&dwTemp,3))
        {
            return(FALSE);
        }
    }
#endif  

    return(TRUE);
}

BOOL fgMeter_Reg_Init(void)
{
    if(!fgMeter_Config_Pra_Init())  
    {
        return(FALSE);
    }

    if(!fgMeter_Extra_Pra_Init())  
    {
        return(FALSE);
    }

    if(!fgMeter_Meas_Pra_Init())  
    {
        return(FALSE);
    }

    if(!fgMeter_Power_Pra_Init())  
    {
        return(FALSE);
    }

    return(TRUE);
}

BOOL fgMeter_Para_Init(void)
{
    BOOL fgRet = TRUE;

    FeedWatchdog();	 
    CheckPowerDown();

/*"***************************************"*/
/*"Step 1:计量芯片寄存器初始化
/*"***************************************"*/
    if(!fgMeter_CaliPraWEn(TRUE))
    {
        return(FALSE);
    }

    if(!fgMeter_Reg_Init())  
    {
        fgRet = FALSE;
    }

    if(!fgMeter_CaliPraWEn(FALSE))  
    {
        return(FALSE);
    }
    
/*"***************************************"*/
/*"Step 2:计量误差动态补偿参数初始化、电量清零 "*/
/*"***************************************"*/
#ifdef WS_ERR_OFFSET_FUNC
    vMeter_ErrOffsetPraSave();
#endif

    /*"加载完参数后 清电量寄存器"*/
    if(!fgMeter_CleanEnergy())  
    {
        return(FALSE);
    }

    return(fgRet);
}

BOOL fgMeter_Para_Load(void)    
{    
    UINT8 ii;
    BOOL fgRet = FALSE;
		
	JustMeter_Parameter.wPraCrc = CRC((UINT8*)&JustMeter_Parameter,sizeof(struct JUSTMETER_PARAMETER) - 2);
    if(fgJustParaRamCrcOk())
    {
        for(ii = 0;ii < 10;ii++)
        {
            if(fgMeter_Para_Init())
            {
                fgRet = TRUE;
                break;
            }
            
            vDelay_Ms(1);
        }	  
    }
    else
    {
        Meter_States.Meter_Flag.bit.Energymodule_Err = 1;
    }

    return(fgRet);
}

/*"***************************************************"*/
/*"校表模块函数定义"*/
/*"***************************************************"*/
BOOL fgMeter_Com_JustParaSet(UINT8 bAddr,UINT32 dwData)  
{
    UINT16 *p;
    UINT32 *pl;
    BOOL  fgRet = FALSE;
    UINT8 ii;
    UINT16 cal_value;

    ii = bAddr - 0x80;
    
    cal_value = (UINT16)dwData&0xffff;

    if(ii < (0x00 + METER_MEAS_PRA_SIZE))
    {
        p = (UINT16 *)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA; 
        p += ii;
        *p = cal_value;
        fgRet = fgMeter_SPI_WriteChkData2(_bMeter_Meas_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA + ii),2);

    }	
    else if((ii >= 0x10)&&(ii < (0x10 + METER_POWER_PRA_SIZE )))
    {
        ii -= 0x10;
        p = (UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA; 
        p += ii;
        *p = cal_value;
        fgRet = fgMeter_SPI_WriteChkData2(_bMeter_Power_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA+ ii),2);
    #ifdef WS_ERR_OFFSET_FUNC
        if(ii < METER_ERROFFSET_PRA_SIZE)
        {
            vMeter_ErrOffsetPraSave1(ii);
        }
    #endif
    
    }
    else if((ii >= 0x20)&&(ii < (0x20 + METER_CONFIG_PRA_SIZE )))
    {
        ii -= 0x20;
        p = (UINT16 *)&JustMeter_Parameter.rMeter_Config_Pra.bWMSW; 
        p += ii;
        *p = cal_value;
        fgRet = fgMeter_SPI_WriteChkData2(_bMeter_Config_Pra_Addr[ii],*((UINT16 *)&JustMeter_Parameter.rMeter_Config_Pra.bWMSW + ii),*((UINT8 *)&_bMeter_Config_Pra_Len+ ii));
    } 
    else if((ii >= 0x30)&&(ii < (0x30 + METER_EXTRA_PRA_SIZE )))
    {
        ii -= 0x30;
        pl = (UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg; 
        pl += ii;
        *pl = dwData;
		fgRet = fgMeter_SPI_WriteChkData2(_bMeter_Extra_Pra_Addr[ii],*((UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg + ii),3);
    }   
    else if((ii >= 0x40)&&(ii < (0x40 + METER_SPEC_PRA_SIZE )))
    {
        ii -= 0x40;

        /*"高频脉冲常数应该是3600000000的分频"*/
        if(ii == 4)  
        {
            if(3600000000%dwData != 0) 
            {
                return(FALSE);
            }
            Pulse_Constant_Writting = 1;
        }

        pl = (UINT32 *)&JustMeter_Parameter.rMeter_Spec_Pra.dwVoltSpec; 
        pl += ii;
        *pl = dwData;

        fgRet = TRUE;
    }
    else
    {
        fgRet = FALSE;
    }
    return(fgRet);
}

/*"***************************************************"*/
/*"测量与计量模块函数定义"*/
/*"***************************************************"*/
BOOL fgMeter_Function(void)
{ 
    BOOL fgRet = FALSE;
	UINT32 dwTemp;

    fgRet = fgMeter_GetVolt();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetCurr();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetNCurr();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetP();
    if(!fgRet)
        return(FALSE);   

    vMeter_ResInterface();

    fgRet = fgMeter_GetQ();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetS();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetPF();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetFreq();
    if(!fgRet)
        return(FALSE);   

    vMeter_ResInterface();

    fgRet = fgMeter_GetAngle();
    if(!fgRet)
        return(FALSE);   

    fgRet = fgMeter_GetState();
    if(!fgRet)
        return(FALSE);   

    vMeter_ResInterface();

    fgRet = fgMeter_GetEnergy();
    if(!fgRet)
        return(FALSE);   

     _rMeter_State_Buffer.fgDataReady = TRUE;
    return (TRUE);
}


#ifdef WS_METER_SPEC_STATUS_DEAL
UINT32 dwMeter_VoltJudgeZero(void)
{
    UINT32 dwRet;

    /*"电压判断为0的阀值为2%额定电压"*/
    dwRet = VOLT_SPEC / 50;  

    return(dwRet);
}

UINT32 dwMeter_CurrJudgeZero(void)
{
    UINT32 dwTemp0,dwTemp1;
    UINT32 dwRet;

    /*"电流判断为0的阀值为0.4%额定电流"*/
    dwTemp0 = CURR_SPEC / 250;  
    dwTemp1 = 35;

    if(dwTemp0 > dwTemp1)
    {
        dwRet = dwTemp0;
    }
    else
    {
        dwRet = dwTemp1;
    }

    return(dwRet);
}

UINT32 dwMeter_PJudgeZero(void)
{
	UINT32 Ratio_CT,Ratio_R3;
	UINT32 dwRet;
	UINT64 ddwTemp;

    /*"有功功率判断为0的阀值为起动功率"*/
	Ratio_CT = (UINT16)((JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0xFFFF0000)>>16);
	Ratio_R3 = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0x0000FFFF);

	ddwTemp = (UINT64)JustMeter_Parameter.rMeter_Config_Pra.wPStart_PS * 16 * 1250 * Ratio_CT / Ratio_R3 * VOLT_SPEC /10000; 
	ddwTemp >>= 21;
	dwRet = (UINT32)ddwTemp;

    return(dwRet);
}

UINT32 dwMeter_QJudgeZero(void)
{
	UINT32 Ratio_CT,Ratio_R3;
	UINT32 dwRet;
	UINT64 ddwTemp;

    /*"无功功率判断为0的阀值为1.5倍有功起动功率"*/
	Ratio_CT = (UINT16)((JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0xFFFF0000)>>16);
	Ratio_R3 = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0x0000FFFF);

	ddwTemp = (UINT64)JustMeter_Parameter.rMeter_Config_Pra.wPStart_Q* 16 * 1250 * Ratio_CT / Ratio_R3 * VOLT_SPEC /10000; 
	ddwTemp >>= 21;
	dwRet = (UINT32)ddwTemp;

    return(dwRet);
}
#endif

BOOL fgMeter_GetVolt(void)
{    
    UINT8 ii;
    UINT32 dwRatio_R1,dwRatio_R2;
    UINT32 dwTemp;
	UINT64 ddwTemp_Volt;

#ifdef WS_METER_SPEC_STATUS_DEAL
    UINT32 dwVoltJudgeZero;
    dwVoltJudgeZero = dwMeter_VoltJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();
	
	dwRatio_R1 = (UINT16)((JustMeter_Parameter.rMeter_Spec_Pra.dwVoltRatio&0xFFFF0000)>>16);
	dwRatio_R2 = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwVoltRatio&0x0000FFFF);
    for(ii = 0;ii < 3;ii++)
    {        
        if(fgMeter_SPI_ReadChkData( r_UA+ii, (UINT32 *)&dwTemp , 4 ))
        { 
			ddwTemp_Volt = (UINT64)dwTemp * 125 * (dwRatio_R1*100 + dwRatio_R2) / dwRatio_R2;
			ddwTemp_Volt >>= 21;

		#ifdef WS_METER_SPEC_STATUS_DEAL
            /*"电压在2%额定电压以下，电压采取特殊处理"*/
            if(ddwTemp_Volt < dwVoltJudgeZero)   
            {
                ddwTemp_Volt = 0;
            }
        #endif
			_rMeter_Data_Buffer.dwVolt[ii] = (UINT32)ddwTemp_Volt;
        }
        else
        {
            return(FALSE);  /*"读寄存器3次出错，返回FALSE"*/
        }
    }

    return(TRUE);
}	

BOOL fgMeter_GetCurr(void)
{    
    UINT8 ii;
	UINT32 Ratio_CT,Ratio_R3;
    UINT32 dwTemp;
	UINT64 ddwTemp_Curr;

#ifdef WS_METER_SPEC_STATUS_DEAL
    UINT32 dwCurrJudgeZero;
    dwCurrJudgeZero = dwMeter_CurrJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();
	Ratio_CT = (UINT16)((JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0xFFFF0000)>>16);
	Ratio_R3 = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0x0000FFFF);
    for(ii = 0;ii < 3;ii++)
    {        
        if(fgMeter_SPI_ReadChkData( r_IA+ii, (UINT32 *)&dwTemp , 4 ))
        {
			ddwTemp_Curr = (UINT64)dwTemp * 1250 * Ratio_CT / Ratio_R3;
			ddwTemp_Curr >>= 21;
			

		#ifdef WS_METER_SPEC_STATUS_DEAL
            if(ddwTemp_Curr < CURR_SPEC / 50)  /*"电流在2%额定电流以下，电流采取特殊处理"*/	
            {
                if(_rMeter_Data_Buffer.dwVolt[ii] != 0) 
                {
                    if(_rMeter_Data_Buffer.dwS[ii + 1] == 0) 
                    {
                        if(ddwTemp_Curr < dwCurrJudgeZero)	
                        {
                            ddwTemp_Curr = 0;
                        }
                    }
                    else
                    {
                        /*"由于_rMeter_Data_Buffer.dwS[ii + 1]*100000会溢出，所以转成浮点数运算"*/
                        ddwTemp_Curr = (UINT32)(100000*((FP32)_rMeter_Data_Buffer.dwS[ii + 1] / _rMeter_Data_Buffer.dwVolt[ii])); 
                    }	
                }
                else
                {   
                    if(ddwTemp_Curr < dwCurrJudgeZero)	
                    {
                        ddwTemp_Curr = 0;
                    }
                }        
            }				
        #endif
			_rMeter_Data_Buffer.dwCurr[ii] = (UINT32)ddwTemp_Curr;
        }				
        else 
        {
            return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
        }
    }

    return(TRUE);
}

BOOL fgMeter_GetNCurr(void)
{
	UINT32 Ratio_CT,Ratio_R3;
    UINT32 dwTemp;
	UINT64 ddwTemp_NCurr;
    
    FeedWatchdog();	                
    CheckPowerDown();
	Ratio_CT = (UINT16)((JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0xFFFF0000)>>16);
	Ratio_R3 = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwCurrRatio&0x0000FFFF);

 	if(fgMeter_SPI_ReadChkData( r_IN, (UINT32 *)&dwTemp , 4 ))
    { 
    #ifdef WS_METER_SPEC_STATUS_DEAL   
        if((_rMeter_Data_Buffer.dwCurr[0] == 0) && (_rMeter_Data_Buffer.dwCurr[1] == 0) && (_rMeter_Data_Buffer.dwCurr[2] == 0))   
        {
            dwTemp = 0;
        }
    #endif			
		ddwTemp_NCurr = (UINT64)dwTemp * 1250 * Ratio_CT / Ratio_R3;
		ddwTemp_NCurr >>= 21;
    	_rMeter_Data_Buffer.dwNCurrCal = (UINT32)ddwTemp_NCurr;     
    }			  
    else 
    {
        return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
    }

    return(TRUE);
}

BOOL fgMeter_GetP(void)
{
    UINT8 ii;
    UINT32 dwTemp;
	UINT64 ddwTemp_p;

#ifdef WS_METER_SPEC_STATUS_DEAL
    UINT32 dwPJudgeZero;
    dwPJudgeZero = dwMeter_PJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {        
        if(fgMeter_SPI_ReadChkData(r_PA+ ii,(UINT32 *)&dwTemp,4))
        {	
            if(dwTemp & 0x80000000)
            {
                dwTemp = 0x100000000 - dwTemp;
                _rMeter_Data_Buffer.bPowerDir |= (1<<(POWERDIR_ACT_POWER_A + ii));
            }
            else
            {
                _rMeter_Data_Buffer.bPowerDir &= ~(1<<(POWERDIR_ACT_POWER_A + ii));
            }

        #ifdef WS_METER_SPEC_STATUS_DEAL	 
            if(ii != 3)
            {
                if(_rMeter_Data_Buffer.dwVolt[ii] != 0)   
                {
                    if(_rMeter_Data_Buffer.dwCurr[ii] < CURR_SPEC / 25)   /*"电流在4%额定电流以下，功率采取特殊处理"*/
                    {
                        if(dwTemp < dwPJudgeZero)  
                        {
                            dwTemp = 0;
                        }
                    }
                    else
                    {
                        /*"电流在4%额定电流以上，功率不做处理"*/
                    }
                }
                else
                {
                    dwTemp = 0;
                }
            }
        #endif	
			     /*Kp = 9*5^11/(2^10*EC*HFConst1)*/
			ddwTemp_p = (UINT64)dwTemp * 439453125 / PULSE_CONST_H / JustMeter_Parameter.rMeter_Config_Pra.HFConst1;
			ddwTemp_p >>= 10;
		
             /*"当功率在潜动功率以下时，将功率方向设置为正"*/
            if(dwTemp == 0)
            {
                if(ii != 3)
                {
                    _rMeter_Data_Buffer.bPowerDir &= ~(1<<(POWERDIR_ACT_POWER_A + ii));
                }
            }

            if(ii == 3)
            {
                _rMeter_Data_Buffer.dwP[0] = (UINT32)ddwTemp_p;
            }
            else
            {
                _rMeter_Data_Buffer.dwP[ii + 1] = (UINT32)ddwTemp_p;
            }				
        }
        else 
        {
            return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
        }
    }	

#ifdef WS_METER_SPEC_STATUS_DEAL	 
    /*"当分相功率都在潜动功率以下时，将合相功率设置为0，方向设置为正"*/
    if((_rMeter_Data_Buffer.dwP[1] == 0)&&(_rMeter_Data_Buffer.dwP[2] == 0)&&(_rMeter_Data_Buffer.dwP[3] == 0))   
    {
        _rMeter_Data_Buffer.dwP[0] = 0;
        _rMeter_Data_Buffer.bPowerDir &= ~(1<<POWERDIR_ACT_POWER_SUM);
    }
#endif	

    return(TRUE);
}

BOOL fgMeter_GetQ(void)
{
    UINT8 ii;
    UINT32 dwTemp;
	UINT64 ddwTemp_Q;

#ifdef WS_METER_SPEC_STATUS_DEAL
    UINT32 dwQJudgeZero;
    dwQJudgeZero = dwMeter_QJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {        
        if(fgMeter_SPI_ReadChkData(r_QA + ii,(UINT32 *)&dwTemp,4))
        { 
            if(dwTemp & 0x80000000)
            {
                dwTemp = 0x100000000 - dwTemp;
                _rMeter_Data_Buffer.bPowerDir |= (1<<(POWERDIR_REACT_POWER_A + ii));
            }
            else
            {
                _rMeter_Data_Buffer.bPowerDir &= ~(1<<(POWERDIR_REACT_POWER_A + ii));
            }

        #ifdef WS_METER_SPEC_STATUS_DEAL	 
            if(ii != 3)
            {
                if(_rMeter_Data_Buffer.dwVolt[ii] != 0)   
                {
                    if(_rMeter_Data_Buffer.dwCurr[ii] < CURR_SPEC / 25)   /*"电流在4%额定电流以下，功率采取特殊处理"*/
                    {
                        if(dwTemp < dwQJudgeZero)  
                        {
                            dwTemp = 0;
                        }
                    }
                    else
                    {
                        /*"电流在4%额定电流以上，功率不做处理"*/
                    }
                }
                else
                {
                    dwTemp = 0;
                }
            }
        #endif	
			/*Kq = 9*5^11/(2^10*EC*HFConst1)*/
			ddwTemp_Q = (UINT64)dwTemp * 439453125 / PULSE_CONST_H / JustMeter_Parameter.rMeter_Config_Pra.HFConst1;
			ddwTemp_Q >>= 10;

            /*"当功率在潜动功率以下时，将功率方向设置为正"*/ 
            if(dwTemp == 0)
            {
                if(ii != 3)
                {
                    _rMeter_Data_Buffer.bPowerDir &= ~(1<<(POWERDIR_REACT_POWER_A + ii));
                }
            }

            if(ii==3)
            {
                _rMeter_Data_Buffer.dwQ[0] = (UINT32)ddwTemp_Q; 
            }
            else
            {
                _rMeter_Data_Buffer.dwQ[ii + 1] = (UINT32)ddwTemp_Q; 
            }
        }
        else 
        {
            return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
        }
    }       

#ifdef WS_METER_SPEC_STATUS_DEAL	 
    /*"当分相功率都在潜动功率以下时，将合相功率设置为0，方向设置为正"*/
    if((_rMeter_Data_Buffer.dwQ[1] == 0)&&(_rMeter_Data_Buffer.dwQ[2] == 0)&&(_rMeter_Data_Buffer.dwQ[3] == 0))   
    {
        _rMeter_Data_Buffer.dwQ[0] = 0;
        _rMeter_Data_Buffer.bPowerDir &= ~(1<<POWERDIR_REACT_POWER_SUM);
    }
#endif

    return(TRUE);
}

FP32 S_cal(FP32 a,FP32 b)
{
    FP32 c;
    FP32 d;
    
    c=a*a+b*b;
    d=sqrtf(c);

    return(d);
}

#ifndef WS_METER_SUPPORT_SRMS
BOOL fgMeter_GetS(void)
{
    UINT8 ii;
    FP32 fTemp0,fTemp1,fTemp2;
    
    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {
        fTemp0 = (FP32)_rMeter_Data_Buffer.dwP[ii];       
        fTemp1 = (FP32)_rMeter_Data_Buffer.dwQ[ii];       

        fTemp2 = S_cal(fTemp0,fTemp1);

        _rMeter_Data_Buffer.dwS[ii] = (UINT32)fTemp2;
    }

    return(TRUE);
}

#else
void vMeter_CalSubS(UINT8 bPhase,UINT32 *pdwData)
{
    FP32  fTemp0,fTemp1,fTemp2;

    fTemp0 = (FP32)_rMeter_Data_Buffer.dwP[bPhase];       
    fTemp1 = (FP32)_rMeter_Data_Buffer.dwQ[bPhase];       

    fTemp2 = S_cal(fTemp0,fTemp1);

    *pdwData = (UINT32)fTemp2;
}

BOOL fgMeter_GetSubS(UINT8 bPhase,UINT32 *pdwData)
{
    UINT32 dwTemp;
	UINT64 ddwTemp_S;

    if(fgMeter_SPI_ReadChkData(r_SA + bPhase,(UINT32 *)&dwTemp,4))
    {		
    #ifdef WS_METER_SPEC_STATUS_DEAL	 
        if(bPhase != 3)
        {
            if(_rMeter_Data_Buffer.dwVolt[bPhase] != 0)   
            {
                
            }
            else
            {
                dwTemp = 0;
            }
        }
    #endif	
		/*Ks = 9*5^11/(2^10*EC*HFConst1)*/
		ddwTemp_S = (UINT64)dwTemp * 439453125 / PULSE_CONST_H / JustMeter_Parameter.rMeter_Config_Pra.HFConst1;
		ddwTemp_S >>= 10;

        *pdwData = (UINT32)ddwTemp_S;		
    }
    else 
    {
        return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
    }

    return(TRUE);
}

BOOL fgMeter_GetS(void)
{
    UINT8 ii;
    UINT32 dwTempCal,dwTempGet;
	UINT64 ddwTemp_S;

    FeedWatchdog();	                
    CheckPowerDown();

    if((V_REGION == 0) || (V_REGION == 3))   /*"三相三线视在功率采用PQ计算的方式"*/
    {
        for(ii = 0;ii < 4;ii++)
        {        
            vMeter_CalSubS(ii,(UINT32 *)&dwTempCal); 

            _rMeter_Data_Buffer.dwS[ii] = dwTempCal;
        }
    }    
    else   /*"三相四线视在功率4%IB电流以下采用PQ计算的方式，以上采取UI方式"*/
    {
        for(ii = 0;ii < 3;ii++)
        {        
            vMeter_CalSubS(ii + 1,(UINT32 *)&dwTempCal); 
            
            if(_rMeter_Data_Buffer.dwCurr[ii] < CURR_SPEC / 25)  /*"电流在4%额定电流以下"*/	
            {
                _rMeter_Data_Buffer.dwS[ii + 1] = dwTempCal;
            }
            else
            {
                if(!fgMeter_GetSubS(ii,(UINT32 *)&dwTempGet))
                {
                    return(FALSE);   
                }

                /*"视在功率取计算值和测量值中的最大者，避免出现视在功率测量值比有功功率或无功功率小的情况"*/
                if(dwTempGet > dwTempCal)
                {
                    _rMeter_Data_Buffer.dwS[ii + 1] = dwTempGet;
                }
                else
                {
                    _rMeter_Data_Buffer.dwS[ii + 1] = dwTempCal;
                }
            }
        }

        vMeter_CalSubS(0,(UINT32 *)&dwTempCal); 
        
        if((_rMeter_Data_Buffer.dwCurr[0] < CURR_SPEC / 25) && (_rMeter_Data_Buffer.dwCurr[1] < CURR_SPEC / 25)  
            && (_rMeter_Data_Buffer.dwCurr[2] < CURR_SPEC / 25))
        {
            _rMeter_Data_Buffer.dwS[0] = dwTempCal;
        }
        else
        {
            if(!fgMeter_GetSubS(3,(UINT32 *)&dwTempGet))
            {
                return(FALSE);   
            }

             /*"视在功率取计算值和测量值中的最大者，避免出现视在功率测量值比有功功率或无功功率小的情况"*/
            if(dwTempGet > dwTempCal)
            {
                _rMeter_Data_Buffer.dwS[0] = dwTempGet;
            }
            else
            {
                _rMeter_Data_Buffer.dwS[0] = dwTempCal;
            }
        }        
    }
        
#ifdef WS_METER_SPEC_STATUS_DEAL	 
    /*"当分相功率都在潜动功率以下时，将合相功率设置为0"*/
    if((_rMeter_Data_Buffer.dwS[1] == 0)&&(_rMeter_Data_Buffer.dwS[2] == 0)&&(_rMeter_Data_Buffer.dwS[3] == 0))   
    {
        _rMeter_Data_Buffer.dwS[0] = 0;
    }
#endif	

    return(TRUE);
}
#endif

BOOL fgMeter_GetPF(void)
{
    UINT8 ii;
    UINT32 temp0,temp1,temp2;
    
    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {
        temp0 = _rMeter_Data_Buffer.dwP[ii];	  
        temp1 = _rMeter_Data_Buffer.dwS[ii];	  

        if(temp1 != 0)
        {
            temp2 = (UINT32)(1000000 * ((FP32)temp0 / temp1));
        #ifdef WS_METER_SPEC_STATUS_DEAL	 
            if(temp2 > 1000000)   
            {
                temp2 = 1000000; 
            }
        #endif	
        }
        else
        { 
            temp2 = 1000000;  /*"add by jie huang 2012/09/13 if app power is zero, set power factor is 1"*/
        }

        _rMeter_Data_Buffer.dwPF[ii] = temp2;       			   
    }

    return(TRUE);
}

BOOL fgMeter_GetFreq(void)
{
    UINT32 dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    if(fgMeter_SPI_ReadChkData(r_UFreq,(UINT32 *)&dwTemp,3))
    { 
        dwTemp=(UINT32)(1000000*((FP32)65536000 / dwTemp));
        
    #ifdef WS_METER_SPEC_STATUS_DEAL
        if(dwTemp < 44500000)
        {
            dwTemp = 44500000;
        }
        else if(dwTemp > 65500000)
        {
            dwTemp = 65500000;
        }

       /*"add by jie huang 2012/08/07 to sovle all the voltage of A B C is 0, but freq value is not 0 issue"*/
        if((_rMeter_Data_Buffer.dwVolt[0] == 0)&&(_rMeter_Data_Buffer.dwVolt[1] == 0)&&(_rMeter_Data_Buffer.dwVolt[2] == 0))   
        {
            dwTemp = 0;
        }
    #endif

        _rMeter_Data_Buffer.dwFre[0] = dwTemp;
        _rMeter_Data_Buffer.dwFre[1] = dwTemp;
        _rMeter_Data_Buffer.dwFre[2] = dwTemp;

    }			
    else 
    {
        return(FALSE);    /*"读寄存器3次出错，返回FALSE"*/
    }

    return(TRUE);
}


BOOL vMeter_EMUState_Handler(void)
{
    BOOL fgRet = FALSE;
	/*a<b<c and c<a<b    */
	if(_rMeter_Data_Buffer.dwIAngle[0] < _rMeter_Data_Buffer.dwIAngle[1])
	{
		if((_rMeter_Data_Buffer.dwIAngle[1] < _rMeter_Data_Buffer.dwIAngle[2])||(_rMeter_Data_Buffer.dwIAngle[2] < _rMeter_Data_Buffer.dwIAngle[0]))
		{
			fgRet = FALSE;
		}
	}/* b<c<a    */
	else if((_rMeter_Data_Buffer.dwIAngle[1] < _rMeter_Data_Buffer.dwIAngle[2])&&(_rMeter_Data_Buffer.dwIAngle[2] < _rMeter_Data_Buffer.dwIAngle[0]))
	{
		fgRet = FALSE;
	}
	else
	{
		fgRet = TRUE;
	}
	return(fgRet);
}

BOOL fgMeter_GetState(void)
{
    UINT32 dwTemp;
	UINT8 bTemp = 0;
	BOOL fgRet = FALSE;

    FeedWatchdog();	                
    CheckPowerDown();

    if(fgMeter_SPI_ReadChkData(w_PHASES,(UINT32 *)&dwTemp,2))
    {
		if((dwTemp & (1 << EMUSTATE_U_ORDER)) != 0)
    	{
       	 	if((V_REGION == 0) || (V_REGION == 3))
        	{
            	if(angle[1]  < 16000)  /*" UAC < 16000"*/
            	{
                	bTemp |= (1 << STATE0_VOLT_PHASE_SEQU); 
            	}
        	}
        	else
	        {
	            bTemp |= (1 << STATE0_VOLT_PHASE_SEQU); 
	        }	
    	}
		fgRet = vMeter_EMUState_Handler();
	    if(fgRet)
	    {
	        if((V_REGION == 0) || (V_REGION == 3))
	        {
	            
	        }
	        else
	        {
	            if((_rMeter_Data_Buffer.dwCurr[0] > 0) && (_rMeter_Data_Buffer.dwCurr[1] > 0)
	                        && (_rMeter_Data_Buffer.dwCurr[2] > 0))   //"add by jiehuang 20110818 to solve the meter will show current abnormal sequ at IA=IB=IC=0"
	            {
	                bTemp |= (1 << STATE0_CURR_PHASE_SEQU); 
	            }
	        }
	    }
    }
    else
    {
        return(FALSE);    
    }
	_rMeter_Data_Buffer.bState0 = bTemp;
	
    if(fgMeter_SPI_ReadChkData(w_Noload,(UINT32 *)&dwTemp,2))
    {

	    if(((dwTemp & (1 << EMUSTATE_ACT_NoLoad_A)) != 0) && ((dwTemp & (1 << EMUSTATE_ACT_NoLoad_B)) != 0)&& ((dwTemp & (1 << EMUSTATE_ACT_NoLoad_C)) != 0)
	                    && ((dwTemp & (1 << EMUSTATE_REACT_NoLoad_A)) != 0)&& ((dwTemp & (1 << EMUSTATE_REACT_NoLoad_B)) != 0)&& ((dwTemp & (1 << EMUSTATE_REACT_NoLoad_C)) != 0))
	    {
	        _rMeter_Data_Buffer.fgNoLoad = TRUE;
	    }
	    else
	    {
	        _rMeter_Data_Buffer.fgNoLoad = FALSE;
	    }
    }
    else
    {
        return(FALSE);    
    }

    return(TRUE);
}

UINT32 dwIncludedAngleCal(UINT32 dwAngleA, UINT32 dwAngleB)
{
    UINT32 dwAngleRet;

    if(dwAngleB >= dwAngleA)
    {
        dwAngleRet = dwAngleB - dwAngleA;
    }
    else
    {
        dwAngleRet = 36000 + dwAngleB - dwAngleA;
    }

    return(dwAngleRet);
}



BOOL fgMeter_GetAngle(void)
{
    UINT32 dwTemp,dwTemp2[6];
	UINT64 ddwTemp_Angle;
	UINT8 ii;

    FeedWatchdog();	                
    CheckPowerDown();
	for(ii=0;ii<6;ii++)
	{
		fgMeter_SPI_ReadChkData(r_YUA+ii,(UINT32 *)&dwTemp,3);
		/*  K=36000/2^24   */
		ddwTemp_Angle = (UINT64)dwTemp * 1125;
		ddwTemp_Angle >>= 19;

		dwTemp2[ii]=(UINT32)ddwTemp_Angle;
	}
	for(ii=0;ii<3;ii++)
	{
		_rMeter_Data_Buffer.dwUAngle[ii]=dwTemp2[ii];
		_rMeter_Data_Buffer.dwIAngle[ii]=dwTemp2[ii+3];
	}
	angle[0] = _rMeter_Data_Buffer.dwUAngle[1] - _rMeter_Data_Buffer.dwUAngle[0];  /*"UAB"*/
	angle[1] = _rMeter_Data_Buffer.dwUAngle[2] - _rMeter_Data_Buffer.dwUAngle[0];  /*"UAC"*/
	angle[2] = dwIncludedAngleCal(_rMeter_Data_Buffer.dwUAngle[1],_rMeter_Data_Buffer.dwUAngle[2]); /*"UBC"*/
	return(TRUE);
}


BOOL fgMeter_GetAllModeEnergy(UINT16 bAddr, UINT32* pdwEnergy,UINT8 bMode)
{
    BOOL fgRet = TRUE;
    UINT8 ii;
    UINT32 dwTemp,dwTemp1;  
    UINT32 dwEnergyLimit;
    UINT64 ddwEnergyVal;

#ifdef WS_METER_ENERGY_TRANSFER
    dwEnergyLimit = ENERGY_LIMIT*3600;  
#else
    dwEnergyLimit = ENERGY_LIMIT;
#endif

    for(ii = 0;ii < 4;ii++) 	
    {    
        if(!fgMeter_SPI_ReadChkData(bAddr+ii,(UINT32 *)&dwTemp,3))
        {
            ddwEnergyVal = 0;  
            fgRet = FALSE;
        }
        else
        {
            ddwEnergyVal = (UINT64)dwTemp * (3600000000 / PULSE_CONST_H);

            if((bMode == READ_ENERGY_PD) && (bAddr == r_EPA))
            {
                if(!fgMeter_SPI_ReadChkData(r_PAFCnt + ii, (UINT32*)&dwTemp1,3))
                {
                    fgRet = FALSE;
                }
                else
                {
                    if(dwTemp1 & 0x20000)
                    {
                        dwTemp1 = 0x40000 - dwTemp1;
                    }
                
                    ddwEnergyVal += (UINT64)dwTemp1 * (3600000000 / PULSE_CONST_H) / JustMeter_Parameter.rMeter_Config_Pra.HFConst1/2;
                }
            }
            
            if(ddwEnergyVal > dwEnergyLimit)
            {
                ddwEnergyVal = 0;
                fgRet = FALSE;
            }
        }
            
        if(ii == 3)
        {
            pdwEnergy[0] = (UINT32)ddwEnergyVal;
        }
        else
        {
            pdwEnergy[ii + 1] = (UINT32)ddwEnergyVal;
        }		
    }	

    return(fgRet);	   
}

BOOL fgMeter_GetSubEnergy(UINT8 bMode)
{
    BOOL fgRet = FALSE;

    FeedWatchdog();	                
    CheckPowerDown();
        
    switch(bMode)
    {
        case READ_ENERGY_ACT:
            fgRet = fgMeter_GetAllModeEnergy(r_EPA,(UINT32*)_rMeter_Data_Buffer.dwActEnergy,READ_ENERGY_NORMAL);
            break;	
        case READ_ENERGY_REACT:
            fgRet = fgMeter_GetAllModeEnergy(r_EQA,(UINT32*)_rMeter_Data_Buffer.dwReActEnergy,READ_ENERGY_NORMAL);
            break;
    #ifdef WS_METER_SUPPORT_SENERGY		
        case READ_ENERGY_S:
            fgRet = fgMeter_GetAllModeEnergy(r_ESA,(UINT32*)_rMeter_Data_Buffer.dwSEnergy,READ_ENERGY_NORMAL);
            break;
    #endif	     
        default:
            break;
    }

    return(fgRet); 	    
}

BOOL fgMeter_GetEnergy(void)
{
    BOOL fgRet = TRUE;
    UINT8 ii;

    for(ii = 0;ii < READ_ENERGY_MAX;ii++)
    {
        if(!fgMeter_GetSubEnergy(ii))
        {
            fgRet = FALSE;
        }
    }

    return(fgRet);
}

BOOL fgMeter_GetEnergy_Pd(void)
{
    BOOL fgRet = TRUE;

    if(!fgMeter_GetAllModeEnergy(r_EPA,(UINT32*)_rMeter_Data_Buffer.dwActEnergy,READ_ENERGY_PD))
    {
        fgRet = FALSE;
    }

    return(fgRet);
}

/*"***************************************************"*/
/*"容错模块函数定义"*/
/*"***************************************************"*/
BOOL fgMeter_ICPraRegChk(UINT16 bAddr,UINT32 dwRamVal,UINT8 bLen)
{
    UINT8 ii;
    BOOL fgRet = FALSE;
    UINT32 dwTemp0,dwTemp1;
	dwTemp0=0;
	dwTemp1=0;
    for(ii = 0;ii < 3;ii++)
    {
        vMeter_SPI_ReadReg(bAddr,(UINT8 *)&dwTemp0,bLen);
        vDelay_Us(20);
        vMeter_SPI_ReadReg(bAddr,(UINT8 *)&dwTemp1,bLen);

        if((dwTemp0 == dwTemp1) && (dwTemp0 == dwRamVal))
        {
            fgRet = TRUE;
            break;
        }
        
        vDelay_Us(100);
    }

    return (fgRet);
}

UINT32 dwMeter_ICPraCS_Cal(UINT16* pwData,UINT8 bLen,UINT32 dwBaseVal)
{
    UINT8 ii;
    UINT32 dwRetCS;

    dwRetCS = dwBaseVal;
    
    for(ii = 0;ii < bLen;ii++)
    {
        dwRetCS += *(pwData + ii);

    }

    dwRetCS &= 0x00ffffff;
    
    return(dwRetCS);
}

UINT32 dwMeter_ICPraCS_Cal_32(UINT32* pwData,UINT8 bLen,UINT32 dwBaseVal)
{
    UINT8 ii;
    UINT32 dwRetCS;

    dwRetCS = dwBaseVal;
    
    for(ii = 0;ii < bLen;ii++)
    {
        dwRetCS += *(pwData + ii);

    }

    dwRetCS &= 0x00ffffff;
	dwRetCS = (~dwRetCS)&0x00ffffff;
    
    return(dwRetCS);
}

UINT32 dwMeter_ICPraCS2_Cal(UINT16* pwData,UINT8 bLen,UINT32 dwBaseVal)
{
    UINT8 ii;
    UINT32 dwRetCS;

    dwRetCS = dwBaseVal;
    
    for(ii = 0;ii < bLen;ii++)
    {
        dwRetCS += *(pwData + ii);

    }

    dwRetCS &= 0x0000ffff;
	dwRetCS = (~dwRetCS)&0x0000ffff;
    
    return(dwRetCS);
}
BOOL fgMeter_ICPraCS_Chk(void)
{
    UINT32 dwTempCS;

     dwTempCS = 0x008197F3;
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Config_Pra.HFConst1),
                                                        METER_CONFIG_PRA_SIZE-3,dwTempCS);
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA),
                                                        METER_MEAS_PRA_SIZE,dwTempCS);

#ifdef WS_ERR_OFFSET_FUNC
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal),METER_ERROFFSET_PRA_SIZE,dwTempCS);
	dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal),6,dwTempCS);
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPoffsetAL),
                                                        METER_POWER_PRA_SIZE - METER_ERROFFSET_PRA_SIZE,dwTempCS);

#else
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA),
                                                        METER_POWER_PRA_SIZE,dwTempCS);
    dwTempCS = dwMeter_ICPraCS_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA),
                                                        6,dwTempCS);
#endif
   
    dwTempCS = dwMeter_ICPraCS_Cal_32(((UINT32*)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg),
                                                       METER_EXTRA_PRA_SIZE,dwTempCS);
    if(!fgMeter_ICPraRegChk(r_CheckSum1,dwTempCS,3))
    {
        return(FALSE);
    }
	dwTempCS = 0x00001624;
	dwTempCS = dwMeter_ICPraCS2_Cal(((UINT16*)&JustMeter_Parameter.rMeter_Config_Pra.bModeSel),
                                                        2,dwTempCS);
    if(!fgMeter_ICPraRegChk(r_CheckSum2,dwTempCS,2))
    {
        return(FALSE);
    }
	
    return(TRUE);
}

BOOL fgMeter_ICPraChkState(void)
{
    UINT8 i;
	switch(_rMeter_State_Buffer.bICPraChkState)
    {
        case IC_PRA_CHK_STATE_CONFIG:
            {
                for(i=0;i<METER_CONFIG_PRA_SIZE;i++)
                {
                    if(!fgMeter_SPI_WriteChkData(_bMeter_Config_Pra_Addr[i],*((UINT16 *)&JustMeter_Parameter.rMeter_Config_Pra.bWMSW + i),*((UINT8 *)&_bMeter_Config_Pra_Len+ i)))
					{
                        return(FALSE);	
                    }
                }
            }
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_EXTRA;
            break;
            
        case IC_PRA_CHK_STATE_EXTRA:
            {
                for(i=0;i<METER_EXTRA_PRA_SIZE;i++)
                {
					if(!fgMeter_ICPraRegChk(_bMeter_Extra_Pra_Addr[i],*((UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg + i),3))
					{
                        return(FALSE);	
                    }
                }
            }
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_MEAS;
            break;
            
        case IC_PRA_CHK_STATE_MEAS:
            {
                for(i=0;i<METER_MEAS_PRA_SIZE;i++)
                {  
					if(!fgMeter_ICPraRegChk(_bMeter_Meas_Pra_Addr[i],*((UINT16 *)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA + i),2))
					{
                        return(FALSE);
                    }  
                }
            }
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_POWER;
            break;	
            
        case IC_PRA_CHK_STATE_POWER:
            {
            #ifdef WS_ERR_OFFSET_FUNC
				for(i=0;i<METER_ERROFFSET_PRA_SIZE;i++) 
                {
                    if (!fgMeter_ICPraRegChk(_bMeter_Power_Pra_Addr[i],*((UINT16 *)&_rMeter_ErrOffset_Pra.wGainAVal + i),2))
                    {
                        return(FALSE);
                    }
                }  

                for(i=0;i<3;i++) 
                {
                    if (!fgMeter_ICPraRegChk(w_QGainA + i,*((UINT16 *)&_rMeter_ErrOffset_Pra.wGainAVal + i),2))
                    {
                        return(FALSE);
                    }
                    
                    if (!fgMeter_ICPraRegChk(w_QPhiA + i,*((UINT16 *)&_rMeter_ErrOffset_Pra.wPhiAVal + i),2))
                    {
                        return(FALSE);
                    }
                } 
				
				for(i = METER_ERROFFSET_PRA_SIZE;i < METER_POWER_PRA_SIZE;i++) 
                {
                    if (!fgMeter_ICPraRegChk(_bMeter_Power_Pra_Addr[i],*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA + i),2))
                    {
                        return(FALSE);
                    }
                }  
            #else
                for(i=0;i<METER_POWER_PRA_SIZE;i++)
                {
                    if(!fgMeter_ICPraRegChk(_bMeter_Power_Pra_Addr[i],*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA+ i),2))
                    {
                        return(FALSE);
                    }
                }

				for(i=0;i<3;i++)
                {
                    if (!fgMeter_ICPraRegChk(w_QGainA + i,*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA + i),2))
                    {
                        return(FALSE);
                    }

                    if (!fgMeter_ICPraRegChk(w_QPhiA + i,*((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPhiA + i),2))
                    {
                        return(FALSE);
                    }
                }

            #endif
            }
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_OTHER;
            break;

        case IC_PRA_CHK_STATE_OTHER:
            {
                
            }
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_CONFIG;
            break;	
            
        default:
            _rMeter_State_Buffer.bICPraChkState = IC_PRA_CHK_STATE_CONFIG;
            break;
    }

    return(TRUE);
}


BOOL fgMeter_ICPraChk(void)
{
    BOOL fgRet = TRUE;

    FeedWatchdog();	                
    CheckPowerDown();

    if(!fgMeter_ICPraCS_Chk())
    {
        return(FALSE);
    } 

    if(!fgMeter_ICPraChkState())
    {
        fgRet = FALSE;
    }


    return(fgRet);
}

BOOL fgMeter_ICPraOk(void)
{
    BOOL fgRet = FALSE;

    fgRet = fgMeter_ICPraChk();

    if(!fgRet)
    {
        _rMeter_State_Buffer.bICPraErrCnt++;
        if(_rMeter_State_Buffer.bICPraErrCnt >= METER_IC_PRAERR_TIMES)
        {
            vMeter_Init(METER_RST_TYPE_PRAERR);
        }
    }
    else
    {
        _rMeter_State_Buffer.bICPraErrCnt = 0;
    }

    return(fgRet);
}

#ifdef WS_ERR_OFFSET_FUNC
stMeter_ErrOffset_Pra _rMeter_ErrOffset_Pra;

enum
{
	METER_CURR_SPEC_INDEX_0A,
	METER_CURR_SPEC_INDEX_0_3A,  
	METER_CURR_SPEC_INDEX_1A,        
	METER_CURR_SPEC_INDEX_1_5A,   
	METER_CURR_SPEC_INDEX_5A,        

	METER_CURR_SPEC_INDEX_MAX
};

/*"功率增益补偿节点和参数"*/
#define GAIN_NODE_0_3A     0
#define GAIN_PRA_0_3A       0

#define GAIN_NODE_1A     0
#define GAIN_PRA_1A       0

#define GAIN_NODE_1_5A     0
#define GAIN_PRA_1_5A       0

#define GAIN_NODE_5A     0
#define GAIN_PRA_5A       0

/*"相位补偿节点和参数"*/
#define PHI_NODE_0_3A     0x04020A02
#define PHI_PRA_0_3A       0x00000000

#define PHI_NODE_1A      0x45093208
#define PHI_PRA_1A        0x00000000

#define PHI_NODE_1_5A     0x04020A02
#define PHI_PRA_1_5A       0x00000000

#define PHI_NODE_5A     0x0C060A02
#define PHI_PRA_5A       0x00000000

/*"0,0.3A,1A,1.5A,5A"*/
const UINT32 _dwMeter_ErrOffSetGainNode[METER_CURR_SPEC_INDEX_MAX] = 
										{0,GAIN_NODE_0_3A,GAIN_NODE_1A,GAIN_NODE_1_5A,GAIN_NODE_5A};

const UINT32 _dwMeter_ErrOffSetGainPra[METER_CURR_SPEC_INDEX_MAX]  = 
										{0,GAIN_PRA_0_3A,GAIN_PRA_1A,GAIN_PRA_1_5A,GAIN_PRA_5A};

const UINT32 _dwMeter_ErrOffSetPhiNode[METER_CURR_SPEC_INDEX_MAX] = 
										{0,PHI_NODE_0_3A,PHI_NODE_1A,PHI_NODE_1_5A,PHI_NODE_5A};

const UINT32 _dwMeter_ErrOffSetPhiPra[METER_CURR_SPEC_INDEX_MAX]  =   
										{0,PHI_PRA_0_3A,PHI_PRA_1A,PHI_PRA_1_5A,PHI_PRA_5A};


void vMeter_ErrOffsetPraSave(void)
{
    UINT8 ii;

    for(ii = 0;ii < METER_ERROFFSET_PRA_SIZE;ii++)
    {
        *((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal + ii) = *((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA+ ii);
    }
}

void vMeter_ErrOffsetPraSave1(UINT8 bIndex)
{
    *((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal + bIndex) = *((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA + bIndex);
}

SINT8 cMeter_ErrOffsetAddVal(UINT32 dwNode,UINT32 dwVal,UINT32 dwRatio)
{
    UINT8 i;
    UINT32 dwNode0,dwNode1,dwNode2,dwNode3;
    SINT8 cVal0,cVal1,cVal2,cVal3;
    FP32 fAddVal;
    SINT8 cAddVal;

    /*"do not need adjust when node = 0 or val =0"*/
    if((dwNode == 0) || (dwVal == 0))
    {
        return(0);
    }

    dwNode0 = (UINT32)((UINT8)dwNode);
    cVal0 = (SINT8)((UINT8)dwVal);

    /*" less than dwNode0"*/
    if(dwRatio <= dwNode0)
    {
        cAddVal = cVal0;
        return(cAddVal);
    }

    /*" between dwNode1 and dwNode0"*/
    dwNode1 = (UINT32)((UINT8)(dwNode >> 8));
    cVal1 = (SINT8)((UINT8)(dwVal >> 8));

    if(dwRatio <= dwNode1)
    {
        fAddVal = cVal0 + (cVal1 - cVal0) * ((FP32)(dwRatio - dwNode0) / (dwNode1 - dwNode0));

        if(fAddVal >= 0)
        {
            cAddVal = fAddVal + 0.5;
        }
        else
        {
            cAddVal = fAddVal - 0.5;
        }

        return(cAddVal);
    }

    /*" between IB and dwNode1"*/
    if(dwRatio <= 100)
    {
        fAddVal = cVal1 + (0 - cVal1) * ((FP32)(dwRatio - dwNode1) / (100 - dwNode1));

        if(fAddVal >= 0)
        {
            cAddVal = fAddVal + 0.5;
        }
        else
        {
            cAddVal = fAddVal - 0.5;
        }

        return(cAddVal);
    }

    /*" between dwNode2 and IB"*/
    dwNode2 = (UINT32)((UINT8)(dwNode >> 16)) * 100;
    cVal2 = (SINT8)((UINT8)(dwVal >> 16));

    if(dwRatio <= dwNode2)
    {
        fAddVal = 0 + (cVal2 - 0) * ((FP32)(dwRatio - 100) / (dwNode2 - 100));

        if(fAddVal >= 0)
        {
            cAddVal = fAddVal + 0.5;
        }
        else
        {
            cAddVal = fAddVal - 0.5;
        }

        return(cAddVal);
    }

    /*" between dwNode3 and dwNode2"*/
    dwNode3 = (UINT32)((UINT8)(dwNode >> 24)) * 100;
    cVal3 = (SINT8)((UINT8)(dwVal >> 24));

    if(dwRatio <= dwNode3)
    {
        fAddVal = cVal2 + (cVal3 - cVal2) * ((FP32)(dwRatio - dwNode2) / (dwNode3 - dwNode2));

        if(fAddVal >= 0)
        {
            cAddVal = fAddVal + 0.5;
        }
        else
        {
            cAddVal = fAddVal - 0.5;
        }

        return(cAddVal);
    }

    /*"biger than dwNode3"*/
    cAddVal = cVal3;
    
    return(cAddVal);
}

UINT16 wMeter_ErrOffsetGainVal(SINT8 cOffsetVal,UINT16 wBasePra)
{
    SINT16 iTemp;
    UINT16 wSetPra;

    iTemp = (SINT16)wBasePra;

    iTemp = iTemp + cOffsetVal;

    wSetPra = (UINT16)iTemp;

    return(wSetPra);
} 

UINT16 wMeter_ErrOffsetPhiVal(SINT8 cOffsetVal,UINT16 wBasePra)
{
    SINT16 iTemp;
    UINT16 wSetPra;

    iTemp = (SINT16)wBasePra;

    iTemp = iTemp + cOffsetVal;

    wSetPra = (UINT16)iTemp;

    return(wSetPra);
} 

UINT8 bMeter_ErrOffsetCurrSpec(void)
{
    UINT8 bRet = 0;

    switch(CURR_SPEC)
    {
        case 3000:
            bRet = METER_CURR_SPEC_INDEX_0_3A;
            break;
        case 10000:
            bRet = METER_CURR_SPEC_INDEX_1A;
            break;
        case 15000:
            bRet = METER_CURR_SPEC_INDEX_1_5A;
            break;		
        case 50000:
            bRet = METER_CURR_SPEC_INDEX_5A;
            break;
        default:
            bRet = METER_CURR_SPEC_INDEX_0A;
            break;
    }

    return(bRet);
}


#ifdef WS_ERR_OFFSET_EXTRA
UINT16 _wMeter_SelfHeatTime = 0;

enum
{
    SELFHEAT_OFFSET_NULL,    /*"do not offset"*/
    SELFHEAT_OFFSET_L1,    /*"gain offset half val, phi offset all val"*/
    SELFHEAT_OFFSET_L2,    /*"gain and phi offset all val"*/
};

UINT8 bMeter_SelfHeatOffsetLevel(BOOL fgInCal)
{
    UINT32 dwCurrTL,dwCurrTH;
    BOOL fgSelfHeat;

    UINT8 bType = SELFHEAT_OFFSET_NULL;

    if(fgInCal)
    {
        return(SELFHEAT_OFFSET_NULL);
    }

    if(CURR_SPEC == 50000)
    {
        dwCurrTL = 550000;   /*"55A"*/
        dwCurrTH = 650000;  /*"65A"*/
    }
    else if(CURR_SPEC == 15000)
    {
        dwCurrTL = 55000;    /*"5.5A"*/
        dwCurrTH = 65000;   /*"6.5A"*/
    }	
    else
    {
        return(SELFHEAT_OFFSET_NULL);
    }

    fgSelfHeat = FALSE;

    if((V_REGION==0)||(V_REGION==3)) 
    {
        if(((_rMeter_Data_Buffer.dwCurr[0] >= dwCurrTL) && (_rMeter_Data_Buffer.dwCurr[0] < dwCurrTH)) 
                    && ((_rMeter_Data_Buffer.dwCurr[2] >= dwCurrTL) && (_rMeter_Data_Buffer.dwCurr[2] < dwCurrTH)))
        {
            fgSelfHeat = TRUE;
        }
    }
    else
    {
        if(((_rMeter_Data_Buffer.dwCurr[0] >= dwCurrTL) && (_rMeter_Data_Buffer.dwCurr[0] < dwCurrTH)) 
                    && ((_rMeter_Data_Buffer.dwCurr[1] >= dwCurrTL) && (_rMeter_Data_Buffer.dwCurr[1] < dwCurrTH))
                    && ((_rMeter_Data_Buffer.dwCurr[2] >= dwCurrTL) && (_rMeter_Data_Buffer.dwCurr[2] < dwCurrTH)))
        {
            fgSelfHeat = TRUE;
        }
    }

    if(fgSelfHeat)
    {
        if(_wMeter_SelfHeatTime < 600)  /*"10 mins"*/
        {
            _wMeter_SelfHeatTime++;
        }

        if(_wMeter_SelfHeatTime < 300)  /*"[0,5) mins"*/
        {
            bType = SELFHEAT_OFFSET_NULL;
        }
        else if(_wMeter_SelfHeatTime < 600) /*"[5,10) mins"*/
        {
            bType = SELFHEAT_OFFSET_L1;
        }
        else  /*"[10,-) mins "*/
        {
            bType = SELFHEAT_OFFSET_L2;
        }
    }
    else
    {
        _wMeter_SelfHeatTime = 0;
    }

    return(bType);
}


SINT8 cMeter_SelfHeatOffsetCal(UINT8 bType,BOOL fgGain)
{
    SINT8 cAddVal;
    UINT16 wOffset;

    if(bType == SELFHEAT_OFFSET_NULL)
    {
        return(0);
    }

    cAddVal = 0;  /*"must init to 0"*/

    wOffset = (UINT16)JustMeter_Parameter.rMeter_Spec_Pra.dwExtraOffsetVal;

    if(bType == SELFHEAT_OFFSET_L1)
    {
        if(fgGain)
        {
            cAddVal  = ((SINT8)((UINT8)(wOffset >> 8))) / 2;
        }
        else
        {
            cAddVal  =  (SINT8)((UINT8)wOffset);
        }
    }
    else  if(bType == SELFHEAT_OFFSET_L2)
    {
        if(fgGain)
        {
            cAddVal  =  (SINT8)((UINT8)(wOffset >> 8));
        }
        else
        {
            cAddVal  =  (SINT8)((UINT8)wOffset);
        }
    }

    return(cAddVal);
}


SINT8 cMeter_Harm5thOffsetCal(BOOL fgInCal,UINT8 bPhase)
{
    SINT8 cAddVal;
    UINT16 wOffset;
    UINT32 dwCurrTL,dwCurrTH;
    UINT32 dwCurrReTL,dwCurrReTH;
    UINT32 dwCurrTL1,dwCurrTH1;

    cAddVal = 0;  /*"must init to 0"*/

    if(fgInCal)
    {
        return(0);
    }

    if(CURR_SPEC == 50000)
    {
        dwCurrTL = 220000;   /*"22A"*/
        dwCurrTH = 260000;  /*"26A"*/

        dwCurrReTL = 260000;
        dwCurrReTH = 297000;	

        dwCurrTL1 = 303000;   
        dwCurrTH1 = 450000; 
    }
    else if(CURR_SPEC == 15000)
    {
        dwCurrTL = 22000;   /*"2.2A"*/  
        dwCurrTH = 26000;  /*"2.6A"*/

        dwCurrReTL = 26000;
        dwCurrReTH = 29700;	

        dwCurrTL1 = 30300;   
        dwCurrTH1 = 45000; 
    }	
    else
    {
        return(0);
    }

    wOffset = (UINT16)(JustMeter_Parameter.rMeter_Spec_Pra.dwExtraOffsetVal>>16);

    if((_rMeter_Data_Buffer.dwCurr[bPhase] >= dwCurrTL)&&(_rMeter_Data_Buffer.dwCurr[bPhase] < dwCurrTH))
    {
        /*"5 order harm phase 0"*/
        cAddVal  =  (SINT8)((UINT8)(wOffset>>8));
    }
    else if((_rMeter_Data_Buffer.dwCurr[bPhase] >= dwCurrReTL)&&(_rMeter_Data_Buffer.dwCurr[bPhase] < dwCurrReTH))
    {
        /*"5 order harm phase 180"*/
        cAddVal  =  (SINT8)((UINT8)wOffset);
    }
    else if((_rMeter_Data_Buffer.dwCurr[bPhase] >= dwCurrTL1)&&(_rMeter_Data_Buffer.dwCurr[bPhase] < dwCurrTH1))
    {
        /*"5 order harm reserve offset"*/
        cAddVal  =  (SINT8)((UINT8)(wOffset>>8));
    }

    return(cAddVal);
}

#endif

void vMeter_ErrOffsetAdjust(BOOL fgInCal)
{
    UINT8 i;
    UINT8 bCurrSpecNo;
    UINT8 bSelfHeatLevel;
    BOOL fgPraChanged = FALSE;
    SINT8 cOffsetVal;
    UINT16 wBasePra,wSetPra;

    UINT16 *pCurrPra;
    UINT32 dwTemp;
    UINT32 dwCurrRatio;
    UINT32 dwNode,dwVal;

    FeedWatchdog();	                
    CheckPowerDown();

    bCurrSpecNo = bMeter_ErrOffsetCurrSpec();

#ifdef WS_ERR_OFFSET_EXTRA
    bSelfHeatLevel = bMeter_SelfHeatOffsetLevel(fgInCal);
#endif

    for(i=0;i<3;i++)
    {
        /*" step 1: calculate current ratio"*/		
        dwTemp = _rMeter_Data_Buffer.dwCurr[i];
        dwTemp = dwTemp*100;
        dwCurrRatio = (UINT32)(((FP32)dwTemp/CURR_SPEC) + 0.5);

        /*"step 2:  gain offset"*/
        if((JustMeter_Parameter.rMeter_Spec_Pra.dwGainOffsetNode == 0) && (!fgInCal))  /*"use stable offset pra"*/
        {
            dwNode = _dwMeter_ErrOffSetGainNode[bCurrSpecNo];
            dwVal = _dwMeter_ErrOffSetGainPra[bCurrSpecNo];
        }
        else  /*"use dynamic offset pra"*/
        {
            dwNode = JustMeter_Parameter.rMeter_Spec_Pra.dwGainOffsetNode;
            dwVal = *((UINT32*)&JustMeter_Parameter.rMeter_Spec_Pra.dwGainAOffsetVal + i);
        }

        cOffsetVal = cMeter_ErrOffsetAddVal(dwNode,dwVal,dwCurrRatio);

    #ifdef WS_ERR_OFFSET_EXTRA
        cOffsetVal = cOffsetVal + cMeter_SelfHeatOffsetCal(bSelfHeatLevel,TRUE);

        cOffsetVal = cOffsetVal + cMeter_Harm5thOffsetCal(fgInCal,i);
    #endif

        wBasePra = *((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA + i);
        wSetPra = wMeter_ErrOffsetGainVal(cOffsetVal,wBasePra);

        pCurrPra = ((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal + i);
        if(wSetPra != *pCurrPra)
        {
            fgPraChanged = TRUE;
            *pCurrPra = wSetPra;
			fgMeter_SPI_WriteChkData2(w_PGainA + i,wSetPra,2);

        }

        /*"step 3:  phi offset"*/
        if((JustMeter_Parameter.rMeter_Spec_Pra.dwPhiOffsetNode == 0) && (!fgInCal)) /*"use stable offset pra"*/
        {
            dwNode = _dwMeter_ErrOffSetPhiNode[bCurrSpecNo];
            dwVal = _dwMeter_ErrOffSetPhiPra[bCurrSpecNo];
        }
        else   /*"use dynamic offset pra"*/
        {
            dwNode = JustMeter_Parameter.rMeter_Spec_Pra.dwPhiOffsetNode;
            dwVal = *((UINT32*)&JustMeter_Parameter.rMeter_Spec_Pra.dwPhiAOffsetVal + i);
        }

        cOffsetVal = cMeter_ErrOffsetAddVal(dwNode,dwVal,dwCurrRatio);

    #ifdef WS_ERR_OFFSET_EXTRA
        cOffsetVal = cOffsetVal + cMeter_SelfHeatOffsetCal(bSelfHeatLevel,FALSE);
    #endif

        wBasePra = *((UINT16*)&JustMeter_Parameter.rMeter_Power_Pra.wPhiA + i);
        wSetPra = wMeter_ErrOffsetPhiVal(cOffsetVal,wBasePra);

        pCurrPra = ((UINT16*)&_rMeter_ErrOffset_Pra.wPhiAVal + i);
        if(wSetPra != *pCurrPra)
        {
            fgPraChanged = TRUE;
            *pCurrPra = wSetPra;
			fgMeter_SPI_WriteChkData2(w_PhiA + i,wSetPra,2);
        }
    }

    /*"step 4:  CS update"*/
    if(fgPraChanged)
    {

    }
}

#endif

