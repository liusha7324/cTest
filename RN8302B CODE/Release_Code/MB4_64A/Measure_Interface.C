#include  "defmcro.h"
#include	"ram.h"
#include	"eeprom.h"
#include	"comm.h"
#include  "Demand.h"
#include	"Init_program_LDH.H"
#include	"I2C_operation.h"
#include	"MB_Showmain.h"
#include	"interrupt.h"
#include  "att7022_operation.h"
#include  "MB_Keymain.h"
#include  "Multi.h"
#include  "Demand.h"
#include  "Initcpu.h"
#include  "pay_def.h"	//payment
#include	"iccard.h"		
#include	"Ex_Pay_For_Fun.h"
#include  "Defdata.h"
#include  <math.h>
#include  <float.h>
#include "Flash_API_M16C.h"
#include "AllVoltageLoss.h"

#include "Measure_Interface.h" 

struct JUSTMETER_PARAMETER   JustMeter_Parameter;

union byte_def flag_communication_with_measuring_board;
union byte_def flag_power_direction;

#define	flag_power_direction_byte		      flag_power_direction.byte
#define	Phase_A_Reactive_Power_Direction	flag_power_direction.bit.b0	//1:"-",0:"+"
#define	Phase_B_Reactive_Power_Direction	flag_power_direction.bit.b1	//1:"-",0:"+"
#define	Phase_C_Reactive_Power_Direction	flag_power_direction.bit.b2	//1:"-",0:"+"
#define	Sum_Reactive_Power_Direction		  flag_power_direction.bit.b3	//1:"-",0:"+"
#define	Phase_A_Active_Power_Direction		flag_power_direction.bit.b4	//1:"-",0:"+"
#define	Phase_B_Active_Power_Direction		flag_power_direction.bit.b5	//1:"-",0:"+"
#define	Phase_C_Active_Power_Direction		flag_power_direction.bit.b6	//1:"-",0:"+"
#define	Sum_Active_Power_Direction		    flag_power_direction.bit.b7	//1:"-",0:"+"

UINT16 FRE_CONST_Q;/*"无功脉冲分频数"*/
UINT16 FRE_CONST_P;/*"有功脉冲分频数"*/
UINT8 Pulse_Constant_Writting;

volatile UINT32 temperatrue;

BOOL _fgMeter_Noload = FALSE;


UINT8 TRAFF_RATE;			 //current fee number[1,...,24]
 
UINT8 Volt_Region = 1;
UINT8 Curr_Region = 0;

UINT32 Enery_Increment;          /*"电量累加的步长：10代表电能显示小数位为2，1代表电能显示小数位为3"*/
UINT8 auxiliary_power_flag;  
 
UINT32 angle[3];


UINT32 Volt_Phase[3];

UINT8 load_flag;      /*"校表参数加载标志 0：不需要 0xff:需要"*/ 
UINT32 tempamphour[3];

enum
{
    JUST_PARA_FROM_NULL,
    JUST_PARA_FROM_RAM,
    JUST_PARA_FROM_FLASH,	
    JUST_PARA_FROM_E2PROM,
    JUST_PARA_FROM_DEFAULT
};

UINT8 _bJustParaFrom = JUST_PARA_FROM_NULL;

UINT8 Clear_Cal_Parameter(void);
UINT8 Inti_Eeprom_Cal_Para(void);
void Measure_Deal_Every_Second(void);
void Dispose_Data_Received_From_Mesuring_Meter(void);
UINT8 Test_Power_Limit_and_Convert_Data(void);
void	Middle_Energy_Accumulation_PerSecond(void);
void	Get_Quadrant_Value(UINT16 *Quadrant_P);
void Energy_Accumulation_Unit_10Wh(void);
UINT8 Updating_Energy_Source_Destination(UINT32 *Source,UINT32 *Destination);
UINT8 Updating_Source_Destination(UINT32 *Source,UINT32 *Destination,UINT32 Step);
UINT32 Get_Max_Value(UINT32 X,UINT32 Y,UINT32 Z);
void	Middle_Energy_Accumulation_PerSecond_Main_Program(void);
void Init_Relation_Meter_Apply(void);
void DealPulseConst(UINT32 inC,UINT16 *outC);
void Deal_PulseConst_Init(void);
void InitTimeA2(void);
void InitTimeB4(void);
void InitTimeB1(void);
void InitTimeB5(void);
UINT8 Send_Pulse_Constant_Data_to_Meter(UINT8 kind,UINT32 Acconst);
void Check_If_Writting_Pulse_Constant_To_Card(void);
void Voltage_Phase_Deal(void);
void	Calculate_Arccos_FA(void);
FP64 atan_FA(FP64 x);

UINT32 Voltage_AC_Calculate(UINT32 Uab,UINT32 Ubc,UINT32 angle);
UINT8 WR_Check_eeprom(UINT16 Addr, UINT8* SourceP, UINT8* CompP, 
                              UINT8 Data_length, UINT8 OperationType);
void Check_Voltage_Threshold(void);
UINT8 Activepower_Direct_Change_Chk(void);
UINT8 Check_RAM_CRC(UINT8 *source_addr, UINT16 comp_value, UINT16 crc_len);
UINT8 Check_ROM_Just_Para(UINT16 eeprom_addr, UINT16 data_len, UINT8 kind);
void Cal_para_Resume(UINT8 bType);
void	Delay_Wait(UINT16 unit_10_uS);
void Just_para_Power_on(void);
void Just_meter_PD(void);


/*"******************************************************"*/
/*"计量芯片相关引脚配置函数"*/
/*"******************************************************"*/
/*"Reset 控制引脚"*/
void vMeter_RstDir(BOOL fgDir)
{
    if(fgDir)  
    {
        pd0 |= (1<<6);    /*"输出引脚"*/
    }
    else
    {
        pd0 &= ~(1<<6);  /*"输入引脚"*/
    }
}

void vMeter_RstOut(BOOL fgLevel)
{
    if(fgLevel)
    {
        p0_6 = 1;      /*"输出高电平"*/
    }
    else
    {
        p0_6 = 0;      /*"输出低电平"*/
    }
}

/*"Sleep 控制引脚"*/
void vMeter_SleepDir(BOOL fgDir)
{
    if(fgDir)  
    {
        pd0 |= (1<<4);     /*"输出引脚"*/
    }
    else
    {
        pd0 &= ~(1<<4);  /*"输入引脚"*/
    }
}

void vMeter_SleepOut(BOOL fgLevel)
{
    if(fgLevel)
    {
        p8_7 = 1;   /*"输出高电平"*/
    }
    else
    {
        p8_7 = 0;  /*"输出低电平"*/
    }
}

/*"SPI 相关引脚"*/
#define METER_SPI_CS_DIR(x)         ((x)? (pd0 |= (1<<7)):(pd0 &= ~(1<<7)))
#define METER_SPI_CS(x)                  ((x)?( p0_7 = 1):(p0_7 = 0)) 

#define METER_SPI_CLK_DIR(x)       do{  prcr|=0x04; ((x)? (pd9 |= (1<<0)):(pd9 &= ~(1<<0))); }while(0)
#define METER_SPI_CLK(x)                ((x)?(p9_0 = 1):(p9_0 = 0))    

#define METER_SPI_MISO_DIR(x)     do{  prcr|=0x04; ((x)? (pd9 |= (1<<1)):(pd9 &= ~(1<<1))); }while(0)
#define METER_SPI_MISO                 ( p9_1)

#define METER_SPI_MOSI_DIR(x)     do{  prcr|=0x04; ((x)? (pd9 |= (1<<2)):(pd9 &= ~(1<<2))); }while(0)
#define METER_SPI_MOSI(x)              ((x)?( p9_2 = 1):(p9_2 = 0))   

/*"******************************************************"*/
/*"计量芯片SPI通信相关函数"*/
/*"******************************************************"*/

#define DELAY_US  4
void vMeter_SPI_Init(void)
{
    prc2 = 1;

    METER_SPI_CS_DIR(SV_PIN_OUTPUT);
    METER_SPI_CS(SV_LOW);

    METER_SPI_CLK_DIR(SV_PIN_OUTPUT);
    METER_SPI_CLK(SV_LOW);

    METER_SPI_MOSI_DIR(SV_PIN_OUTPUT);
    METER_SPI_MOSI(SV_LOW);

    METER_SPI_MISO_DIR(SV_PIN_INPUT);
}

void vMeter_SPI_WriteByte(UINT8 bData)
{
	UINT8 i;
	
	for(i=0;i<8;i++)
	{
		METER_SPI_CLK(SV_HIGH);
		vDelay_Us(2);	
		if(bData & 0x80)
		{
			METER_SPI_MOSI(SV_HIGH);
			//vDelay_Us(6);
		}
		else
		{
			METER_SPI_MOSI(SV_LOW);
			//vDelay_Us(6);
		}
		vDelay_Us(2);
		METER_SPI_CLK(SV_LOW);
		vDelay_Us(4);
		bData <<= 1;
	}


	METER_SPI_MOSI(SV_HIGH);
	
	vDelay_Us(6);
}


UINT8 vMeter_SPI_ReadByte(void)
{
    UINT8 i,dwTemp=0;
    for(i=0;i<8;i++)
    {
    	dwTemp<<=1;
		METER_SPI_CLK(SV_HIGH);
		vDelay_Us(4);
		METER_SPI_CLK(SV_LOW);
		vDelay_Us(2);
		if(METER_SPI_MISO)
        {
            dwTemp |= 0x01;
        }
		vDelay_Us(2);
    }
    return	dwTemp;
}

BOOL vMeter_SPI_WriteReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen)
{
    UINT8 ii,jj,temp,chksum;
	BOOL fgRet = TRUE;

	if((bLen == 0)||(bLen > 4))
	{
		return(FALSE);
	}

	/*"Step 1: 初始化SPI通信端口"*/
	METER_SPI_CS(SV_LOW);   
	vDelay_Us(5);

	METER_SPI_MISO_DIR(SV_PIN_INPUT);
	METER_SPI_MOSI_DIR(SV_PIN_OUTPUT);

	/*发送地8位址*/
	temp = (UINT8)(bAddr & 0x00ff);
	chksum = temp;
	vMeter_SPI_WriteByte( temp);
		
	/*发送8位CMD*/
	temp = (((UINT8)(bAddr >> 4))& 0xf0)+ 0x80;;
	chksum += temp;
	vMeter_SPI_WriteByte( temp);
		
	/*接收数据*/
	for(jj = bLen; jj > 0;jj--)
	{
		vMeter_SPI_WriteByte( pdwData[jj-1]);
		chksum += pdwData[jj-1];
	}
	
	chksum = ~chksum;
	vMeter_SPI_WriteByte(chksum);
			
    /*"Step 4: 结束SPI通信"*/
    vDelay_Us(DELAY_US);

    METER_SPI_CS(SV_HIGH);
    METER_SPI_CLK(SV_HIGH);
	return (fgRet);
}



BOOL vMeter_SPI_ReadReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen)
{
    UINT8 ii,jj,temp,chksum;
	BOOL fgRet = TRUE;

	if((bLen == 0)||(bLen > 4))
	{
		return(FALSE);
	}

	/*"Step 1: 初始化SPI通信端口"*/
	METER_SPI_CS(SV_LOW);   
	vDelay_Us(5);

	METER_SPI_MISO_DIR(SV_PIN_INPUT);
	METER_SPI_MOSI_DIR(SV_PIN_OUTPUT);

	/*发送地8位址*/
	temp = (UINT8)(bAddr & 0x00ff);
	chksum = temp;
	vMeter_SPI_WriteByte( temp);
		
	/*发送8位CMD*/
	temp = ((UINT8)(bAddr >> 4))& 0xf0;
	chksum += temp;
	vMeter_SPI_WriteByte( temp);
		
	/*接收数据*/
	for(jj = bLen; jj > 0;jj--)
	{
		pdwData[jj-1] = vMeter_SPI_ReadByte(); 
		chksum += pdwData[jj-1];
	}
	chksum = ~chksum;	
	if(vMeter_SPI_ReadByte()!=chksum)  
	{
		fgRet = FALSE;
	}
		
    /*"Step 4: 结束SPI通信"*/
    vDelay_Us(DELAY_US);

    METER_SPI_CS(SV_HIGH);
    METER_SPI_CLK(SV_HIGH);
	return (fgRet);
}




/*"============================================================
函数说明：根据校表命令进行通信处理
输入参数：commad_addr:操作类：0x20 写校表参数 0x23 读校表参数
          reg_addr   ：Meter寄存器地址
          sour_addr  ：输入数据地址                  
输出参数：des_addr   : 输出数据地址
返    回：ret_value  ：0 操作失败  0xff 操作成功
修改时间：2011年5月20日
作    者       ： RZR  
============================================================"*/
UINT8 fgMeter_Com_Process(UINT8 *commad_addr, UINT8 *reg_addr, 
                                  UINT8 *sour_addr, UINT8 *des_addr)
{
    UINT8 ret_value=0;
    UINT16 uni = 0;
    UINT32 parameter_w,temp;
    UINT16  wAddr;
    UINT16 wTemp;
    UINT8 bLen;

    switch(*commad_addr)
    {
        case 0x20:  /*"校表参数写命令处理"*/
            
            /*"场外状态禁止写校表参数"*/
            if(O1ther_Meter_Parameter.WorkRoomState == 0)
            {
                return (0);
            }

            /*"***************************************************"*/
            /*"校表状态控制命令处理"*/
            /*"***************************************************"*/
            if(*(reg_addr) == 0xFA)
            {
                if(*(sour_addr + 3) == 1)
                {
                    _rMeter_State_Buffer.bCalState = SV_CAL_STATE_START;
                    return (1);
                }
                else if(*(sour_addr + 3) == 2)
                {
                    if(Clear_Cal_Parameter())
                    {
                        vMeter_VoltCurrSpecInit(); 
                        return (1);
                    }
                    else
                    {
                        return (0);
                    }
                }
                else if(*(sour_addr+3) == 3)
                {
                    _rMeter_State_Buffer.bCalState = SV_CAL_STATE_END;
                #ifndef WS_SUPPORT_SIMULATION
                    FlashErase(8);
                #endif

                    FlashWrite((UINT8 far*)0xE000, (UINT8 far*)&JustMeter_Parameter,sizeof(struct JUSTMETER_PARAMETER));
                }
                
                return (1);
            }

            /*"***************************************************"*/
            /*"校表参数设置命令处理"*/
            /*"***************************************************"*/

            /*"非法校表地址，返回错误"*/
            if((*(reg_addr) < 0x80) || (*(reg_addr) > (0xc0 + METER_SPEC_PRA_SIZE - 1)))  
            {
                return (0);
            }

            /*"非校表状态，不允许写参数"*/
            if(_rMeter_State_Buffer.bCalState != SV_CAL_STATE_START)
            {
                return (0);
            }

            /*"校表数据BUFFER高低字节转换"*/
            for(uni = 0; uni < 4; uni++)
            {
                *((UINT8*)&parameter_w + uni) = *(sour_addr + 3 - uni);
            }


            if(!fgMeter_Com_JustParaSet(*reg_addr, parameter_w))
            {
                return (0);
            }

            /*"***************************************************"*/
            /*"校表参数保存处理"*/
            /*"***************************************************"*/
            if((*(reg_addr) >= 0x80) && ((*reg_addr) < (0x80 + METER_MEAS_PRA_SIZE)))
            {
                bLen = 2;
                wAddr=((*reg_addr) -0x80) * 2;
            }     
            else if((*(reg_addr) >= 0x90) && ((*reg_addr) < (0x90 + METER_POWER_PRA_SIZE)))
            {
                bLen = 2;
                wAddr=((*reg_addr) -0x90 + METER_MEAS_PRA_SIZE) * 2;
            }  
            else if((*(reg_addr) >= 0xa0) && ((*reg_addr) < (0xa0 + METER_CONFIG_PRA_SIZE)))
            {
                bLen = 2;
                wAddr=((*reg_addr)-0xa0 + METER_MEAS_PRA_SIZE + METER_POWER_PRA_SIZE) * 2;
            }    
            else if((*(reg_addr) >= 0xb0)&&((*reg_addr) < (0xb0 + METER_EXTRA_PRA_SIZE)))
            {
                bLen = 4;
                wAddr=((*reg_addr) -0xb0)*4 + (METER_MEAS_PRA_SIZE + METER_POWER_PRA_SIZE + METER_CONFIG_PRA_SIZE) * 2;
            }    
            else  if((*(reg_addr) >= 0xc0)&&((*reg_addr) < (0xc0 + METER_SPEC_PRA_SIZE)))
            {
                bLen = 4;
                wAddr = ((*reg_addr) - 0xc0 + METER_EXTRA_PRA_SIZE) * 4 + (METER_MEAS_PRA_SIZE + METER_POWER_PRA_SIZE + METER_CONFIG_PRA_SIZE ) * 2;
            }
            else
            {
                 return (0);
            }

            ret_value = WR_Check_eeprom(JUSTMETER_PARA_ROM + wAddr,(UINT8*)&parameter_w,(UINT8*)&temp,bLen,0);
            if(ret_value == 0)
            {
                return (0);
            }

            /*"***************************************************"*/
            /*"校表参数CRC处理"*/
            /*"***************************************************"*/
            JustMeter_Parameter.wPraCrc = CRC((UINT8*)&JustMeter_Parameter,sizeof(struct JUSTMETER_PARAMETER) - 2);
            ret_value = WR_Check_eeprom(JUSTMETER_PARA_ROM + sizeof(struct JUSTMETER_PARAMETER) - 2, 
                                        (UINT8*)&JustMeter_Parameter.wPraCrc,(UINT8*)&temp,2,0);

            if(ret_value == 0)
            {
                return (0);
            }
            if(((*reg_addr) == 0xc0) || ((*reg_addr) == 0xc1))
            {
                vMeter_VoltCurrSpecInit();  
            }

            break;
        case 0x23:  /*"校表参数读命令处理"*/
            
            ret_value = 0xff;	
            if(((*reg_addr) >= 0x30) && ((*reg_addr) < (0x30 + METER_MEAS_PRA_SIZE)))
            {
                *reg_addr -= 0x30;
                wTemp = *((UINT16 *)&JustMeter_Parameter.rMeter_Meas_Pra.wUGainA + *reg_addr);
                
                *((UINT32 *)des_addr) = (UINT32)wTemp & 0x0000ffff;
            }
            else if(((*reg_addr) >= 0x40) && ((*reg_addr) < (0x40 + METER_POWER_PRA_SIZE)))
            {
                *reg_addr -= 0x40;
                wTemp = *((UINT16 *)&JustMeter_Parameter.rMeter_Power_Pra.wPGainA+ *reg_addr);
                
                *((UINT32 *)des_addr) = (UINT32)wTemp & 0x0000ffff;	
            }
            else if(((*reg_addr) >= 0x50) && ((*reg_addr) < (0x50 + METER_CONFIG_PRA_SIZE)))
            {
                *reg_addr -= 0x50;
                wTemp = *((UINT16 *)&JustMeter_Parameter.rMeter_Config_Pra.bWMSW + *reg_addr);
                
                *((UINT32 *)des_addr) = (UINT32)wTemp & 0x0000ffff;	
            }		
            else if(((*reg_addr) >= 0x60) && ((*reg_addr) < (0x60 + METER_EXTRA_PRA_SIZE)))
            {
                *reg_addr -= 0x60;
               // wTemp = *((UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg+ *reg_addr);
                
                *((UINT32 *)des_addr) = *((UINT32 *)&JustMeter_Parameter.rMeter_Extra_Pra.dwEMUCfg+ *reg_addr);	
            }	 
            else if(((*reg_addr) >= 0x70)&&((*reg_addr) < (0x70 + METER_SPEC_PRA_SIZE)))   
            {
                *reg_addr -= 0x70;

                *((UINT32 *)des_addr) =  *((UINT32*)&JustMeter_Parameter.rMeter_Spec_Pra.dwVoltSpec + *reg_addr);
            }
            else
            {
                ret_value = 0;	
            }

            break;
        case 0x26:   /*"校表参数块读命令处理"*/
            if((((*reg_addr) & 0x0f) - 0x0a) < 3)
            {
                if((((*reg_addr) & 0x0f) - 0x0a) == 0)
                {
                    for(uni = 0; uni < sizeof(struct JUSTMETER_PARAMETER); uni++)
                    {
                        *(des_addr + uni) = *((UINT8 *)&JustMeter_Parameter + uni);
                    }
                }
                else if((((*reg_addr) & 0x0f) - 0x0a) == 1)
                {
                    WRLC256(JUSTMETER_PARA_ROM,des_addr,sizeof(struct JUSTMETER_PARAMETER),0,1);  
                }
                else
                {
                    FlashRead((FLASH_PTR_TYPE)0xe000, (BUF_PTR_TYPE)des_addr,sizeof(struct JUSTMETER_PARAMETER));
                }

                ret_value = 0xff;
            }
            break;
        case 0x27:   /*"其它参数读命令处理"*/
            if((*reg_addr) == 0x00)
            {
                *((UINT32 *)des_addr) = (UINT32)_rMeter_State_Buffer.bRstType;
            }
            else if((*reg_addr) == 0x01)
            {
                *((UINT32 *)des_addr) = (UINT32)_rMeter_State_Buffer.wRstCnt;
            }
            else if((*reg_addr) == 0x02)
            {
                *((UINT32 *)des_addr) = (UINT32)_bJustParaFrom;
            }
            else if((*reg_addr) == 0x03)
            {
                *((UINT32 *)des_addr) = (UINT32)_rMeter_State_Buffer.fgPraLoadOk;
            }
            else if((*reg_addr) == 0x04)
            {
                *((UINT32 *)des_addr) = (UINT32)_rMeter_State_Buffer.bCalState;
            }
        #ifdef WS_ERR_OFFSET_FUNC
            else if(((*reg_addr) >= 0x05)&&((*reg_addr) < (0x05 + METER_ERROFFSET_PRA_SIZE)))
            {
                *reg_addr -= 0x05;
                *((UINT32 *)des_addr) = (UINT32)(*((UINT16*)&_rMeter_ErrOffset_Pra.wGainAVal + *reg_addr));
            }
        #endif

            ret_value = 0xff;	
            break;

        default:
            break;
    }
    
    return (ret_value);
}

/*"============================================================
函数说明：清校表参数，校表参数恢复为缺省值
输入参数：无                  
输出参数：无
返    回：ret_value  ：0 操作失败  0xff 操作成功
作者：GANJP  版本：1.00
============================================================"*/
UINT8 Clear_Cal_Parameter(void)
{
    UINT8 ret_value;

    ret_value=FALSE;
    
    ret_value = Inti_Eeprom_Cal_Para();

    if(ret_value)
    {
        ret_value=fgMeter_Para_Init();
    }
    
    return(ret_value);
}

/*"***************************************"*/
/*"RAM和E2PROM中校表参数还原"*/
/*"***************************************"*/
UINT8 Inti_Eeprom_Cal_Para(void)
{
    UINT8 i;
    BOOL ret_value = FALSE;
    UINT16 wTemp,wTemp1;
    UINT32 dwTemp,dwTemp1;
    UINT16 para_len = 0;
    UINT8 bParaPos;

    para_len = sizeof(struct JUSTMETER_PARAMETER);

/*"***************************************"*/
/*"Step 1:RAM和E2PROM中校表参数清零"*/
/*"***************************************"*/
    for(i = 0; i < para_len; i++)
    {
        *((UINT8*)&JustMeter_Parameter + i) = 0;
    }

    WRLC256(JUSTMETER_PARA_ROM, (UINT8*)&JustMeter_Parameter,para_len, 0, 0);

/*"***************************************"*/
/*"Step 2:RAM和E2PROM中校表参数还原成默认值"*/
/*"***************************************"*/
    bParaPos = METER_MEAS_PRA_SIZE + METER_POWER_PRA_SIZE + METER_CONFIG_PRA_SIZE;

    for(i = 0; i < bParaPos; i++)
    {
        ret_value = FALSE;
        wTemp = *((UINT16 far*)&_rMeter_JustPraDef + i);
        ret_value = WR_Check_eeprom(JUSTMETER_PARA_ROM + i*2, (UINT8*)&wTemp,(UINT8*)&wTemp1,2,0);
        if(!ret_value)
        {
            return(ret_value);
        }
        
        *((UINT16 far*)&JustMeter_Parameter + i) = *((UINT16 far*)&_rMeter_JustPraDef + i);
    }

    for(i = 0; i < METER_SPEC_PRA_SIZE + METER_EXTRA_PRA_SIZE; i++)
    {
        ret_value = FALSE;
        dwTemp = *((UINT32 far*)&_rMeter_JustPraDef.rMeter_Extra_Pra_Init + i);
        ret_value = WR_Check_eeprom((JUSTMETER_PARA_ROM + bParaPos*2 + i*4),(UINT8*)&dwTemp,(UINT8*)&dwTemp1,4,0);
        if(!ret_value)
        {
            return(ret_value);
        }
        
        *((UINT32 far*)&JustMeter_Parameter.rMeter_Extra_Pra+ i) = *((UINT32 far*)&_rMeter_JustPraDef.rMeter_Extra_Pra_Init + i);
    }

/*"***************************************"*/
/*"Step 3:计算CRC并保存"*/
/*"***************************************"*/
    if(ret_value)
    {
        ret_value = FALSE;
        JustMeter_Parameter.wPraCrc = CRC((UINT8*)&JustMeter_Parameter,para_len - 2);
        ret_value = WR_Check_eeprom(JUSTMETER_PARA_ROM + para_len - 2, 
                                   (UINT8*)&JustMeter_Parameter.wPraCrc,(UINT8*)&wTemp, 2, 0);
    }

    return(ret_value);
}

void PowerUp_RailEnergy_Check(BOOL fgCheck)
{
    UINT32 dwMaxVal;
    UINT8 unc;
    UINT8 und;

#ifdef WS_METER_ENERGY_TRANSFER
    dwMaxVal = 1800000000; /*" =500000*3600"*/
#else
    dwMaxVal = 500000;
#endif

    if(fgCheck)
    {
        for(unc = 0; unc < 24; unc++)
        {
            if(*((UINT32 *)&energy_rail.Rail_Plus_Active[0]+unc) > dwMaxVal)
            {
                *((UINT32 *)&energy_rail.Rail_Plus_Active[0]+unc)=0;
            }
        }
    }
    else
    {
        for(unc = 0; unc < 24; unc++)
        {
            *((UINT32 *)&energy_rail.Rail_Plus_Active[0]+unc)=0;
        }
    }

    for(und=0;und<2;und++)
    {
        for(unc = 0; unc < MAXTRIFF; unc++)
        {
            if((*(&energy_rail.Total_Plus_Active_100mwh[unc]+und*MAXTRIFF)) > ENERGY_VALUE_100MWH_001WH)
            {
                (*(&energy_rail.Total_Plus_Active_100mwh[unc]+und*MAXTRIFF))=0;
            }
        }
    }
}

BOOL fgMeter_PowerOn_Init(void)       
{
    BOOL fgRet = FALSE;
    UINT8 i;
	UINT32 temp;

    vMeter_Version();
	
    vMeter_Init(METER_RST_TYPE_PWRUP);

    if(fgMeter_Para_Load()) 
    {
        _rMeter_State_Buffer.fgPraLoadOk = TRUE;
        fgRet = TRUE;
    }

    PowerUp_RailEnergy_Check(fgRet);  

    return(fgRet);
}

void Measure_Deal_Every_Second(void)
{
  	BOOL fgRet = FALSE;

   	fgRet = fgMeter_Function(); 
    
    if((!fgRet)&&(_rMeter_State_Buffer.bCalState == SV_CAL_STATE_END))
    {
        _rMeter_State_Buffer.bDataRdErrCnt++;
        if(_rMeter_State_Buffer.bDataRdErrCnt >= METER_DATA_RDERR_TIMES)
        {
            vMeter_Init(METER_RST_TYPE_RDERR);  	
        }
    }
    else
    {
        _rMeter_State_Buffer.bDataRdErrCnt = 0;        
    }
    
}

void Dispose_Data_Received_From_Mesuring_Meter(void)
{
    BOOL fgRet = FALSE;

    fgRet = Test_Power_Limit_and_Convert_Data();

    if((!fgRet)&&(_rMeter_State_Buffer.bCalState == SV_CAL_STATE_END))
    {
        _rMeter_State_Buffer.bDataValErrCnt++;
        if( _rMeter_State_Buffer.bDataValErrCnt >= METER_DATA_VALERR_TIMES)
        {
            vMeter_Init(METER_RST_TYPE_VALERR);
        }
    }
    else
    {
         _rMeter_State_Buffer.bDataValErrCnt = 0;
    }
}


/*"============================================================
函数说明：检测IDT90E36计量数据合法性(在有效的数据范围内)
输入参数：无                  
输出参数：无
返    回：return_value TRUE DATA VALID FALSE DATA INVALID
作者：GANJP  版本：1.00
============================================================"*/					
UINT8 Test_Power_Limit_and_Convert_Data(void)
{
    UINT8 return_value = TRUE;
    UINT32 temp;
    UINT8 i;

    for(i = 0; i < 4; i++)
    {
        if(_rMeter_Data_Buffer.dwP[i] < POWER_LIMIT)
            Active_power[i] = _rMeter_Data_Buffer.dwP[i];
        else
            return_value=FALSE;
    }

    for(i = 0; i < 4; i++)
    {
        if(_rMeter_Data_Buffer.dwQ[i] < POWER_LIMIT)
            Reactive_power[i] = _rMeter_Data_Buffer.dwQ[i];
        else
            return_value=FALSE;
    }

    for(i = 0; i < 4; i++)
    {
        if(_rMeter_Data_Buffer.dwS[i] < POWER_LIMIT)
            Visual_power[i] = _rMeter_Data_Buffer.dwS[i];
        else
            return_value=FALSE;
    }	

    for(i = 0; i < 3; i++)
    {
       // if(_rMeter_Data_Buffer.dwVolt[i] < VOLT_LIMIT)
        {
            Volt[i] = _rMeter_Data_Buffer.dwVolt[i];
            Voltc[i] = _rMeter_Data_Buffer.dwVolt[i];
        }
       // else
        {
       //     return_value=FALSE;
        }
    }

    for(i=0;i<3;i++)
    {
        Curr[i] = _rMeter_Data_Buffer.dwCurr[i];
    }

    if((V_REGION==0)||(V_REGION==3))   /*"331三相三线"*/
    {
        Volt[1]=0;
        Curr[1]=0;
    }

    if((V_REGION==0)||(V_REGION==3))
        N_Current = 0;
    else
        N_Current = _rMeter_Data_Buffer.dwNCurrCal;

    for(i=0;i<3;i++)
    {
        Freq[i] = _rMeter_Data_Buffer.dwFre[i];
    }

    for(i=0;i<=3;i++)
    {
        Factor[i] = _rMeter_Data_Buffer.dwPF[i];
    }

    /*"功率方向处理"*/
    flag_power_direction_byte = _rMeter_Data_Buffer.bPowerDir;
    if(Activepower_Direct_Change_Chk())
    {
        ClearDemandArea(0);
    }
    
    Meter_States.Meter_Status1.bit.ActivePower_Direct=Sum_Active_Power_Direction;
    Meter_States.Meter_Status1.bit.ReActivePower_Direct=Sum_Reactive_Power_Direction;
    Meter_States.Meter_Status2.byte = (flag_power_direction_byte & 0xf0)>>4;
    Meter_States.Meter_Status2.byte |= ((flag_power_direction_byte & 0x0f)<<4);

    //------------FuXF ADD 081114---------------------------------
    NEW645Meter_States.Meter_Status1.bit.ActivePower_Direct=Sum_Active_Power_Direction;
    NEW645Meter_States.Meter_Status1.bit.ReActivePower_Direct=Sum_Reactive_Power_Direction;
    NEW645Meter_States.Meter_Status2.intd = (flag_power_direction_byte & 0x70)>>4;
    NEW645Meter_States.Meter_Status2.intd |= ((flag_power_direction_byte & 0x07)<<4);

     /*"电压和电流相序处理"*/
    if((_rMeter_Data_Buffer.bState0 & (1<<STATE0_VOLT_PHASE_SEQU))!=0)
        Abnormal_Phase_sequence=1;		 
    else
        Abnormal_Phase_sequence=0;		 
    if((_rMeter_Data_Buffer.bState0 & (1<<STATE0_CURR_PHASE_SEQU))!=0)
        Abnormal_Phase_I_sequence=1;		 
    else
        Abnormal_Phase_I_sequence=0;		 

    if((V_REGION==0)||(V_REGION==3))
    {/*"331表ABC失压时都不判逆相序"*/
        if((Volt[0]<650000l)||(Volt[2]<650000l)||(Meter_331_LostVoltage_B==1))
            Abnormal_Phase_sequence=0;
        
        if((Volt[0]<100000l)||(Volt[2]<100000l))
            Meter_331_LostVoltage_B=0; 
    }

    if((V_REGION==0)||(V_REGION==3))
    {/*"331表功率因数强制为0 fxf add 090505"*/
        Factor[2]=0;
    }

    /*"温度处理"*/
    temperatrue = (UINT32)(_rMeter_Data_Buffer.lTemp);  

    /*"潜动标志处理"*/
    if(_rMeter_Data_Buffer.fgNoLoad == 0)
    {
        _fgMeter_Noload = FALSE;
    }
    else
    {
        _fgMeter_Noload = TRUE;
    }

    return return_value;
}

/*"============================================================
函数说明：计量尾数累加，每秒调用
输入参数：无                  
输出参数：无
返    回：无
作者：GANJP  版本：1.00
============================================================"*/		
void	Middle_Energy_Accumulation_PerSecond(void)
{
    SINT16 i;
    UINT16 quadrant[4];					                   //quadrant value(0~3) of Sum,A,B,C
    UINT32 *temp_value;
    UINT32 dwReactEnergy;

    Get_Quadrant_Value(quadrant);				                 //get quadrant value(0~3) of Sum,A,B,C

    for(i = 0;i <= 3;i++)
    {
        if((quadrant[i] == 0) || (quadrant[i] == 3))	                               /*"累加总/A/B/C正向有功电量中间单元"*/
        {
            energy_rail.Rail_Plus_Active[i] += _rMeter_Data_Buffer.dwActEnergy[i];
            if(i == 0)
            {
                Active_energy_per_sec = _rMeter_Data_Buffer.dwActEnergy[i];
            }	
        }      
        else									                                                 /*"累加总/A/B/C反向有功电量中间单元"*/
        {
            energy_rail.Rail_Nega_Active[i] += _rMeter_Data_Buffer.dwActEnergy[i];
            if(i == 0)
            {
                Active_energy_per_sec = _rMeter_Data_Buffer.dwActEnergy[i];
            }
        }

        dwReactEnergy = _rMeter_Data_Buffer.dwReActEnergy[i];
        energy_rail.Rail_Quad_Reactive[i][quadrant[i]] += dwReactEnergy;
        if(0 == i)
        {
            Reactive_energy_per_sec = dwReactEnergy ;
        }  

        /*"累加完每秒电量的增量后，应清零"*/
        _rMeter_Data_Buffer.dwActEnergy[i] = 0;    
        _rMeter_Data_Buffer.dwReActEnergy[i] = 0;
    #ifdef WS_METER_SUPPORT_SENERGY	
        _rMeter_Data_Buffer.dwSEnergy[i] = 0;
    #endif	
    }

    /*"累加A/B/C相安时值中间单元，单位为0.0001安培.秒"*/
    for(i = 0;i <= 2;i++)
        tempamphour[i] += Curr[i];

    energy_rail.crc_cal = CRC((UINT8*)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2);

}

/*"============================================================
函数说明：Get quadrant value(0~3) of Sum,A,B,C in the Quadrant_P pointer
输入参数：无                  
输出参数：Quadrant_P   计算象限结果存储地址指针
返    回：无
作者：GANJP  版本：1.00
============================================================"*/		
void	Get_Quadrant_Value(UINT16 *Quadrant_P)
{	
    UINT8 P,Q,factor,temp_P,temp_Q;
    UINT16 i;

    factor=0x08;
    P=flag_power_direction_byte>>4;			                 /*sum_P,c_P,b_P,a_P,sum_Q,c_Q,b_Q,a_Q*/
    Q=flag_power_direction_byte&0x0f;

    for(i = 0;i <= 3;i++)
    {
        temp_P = P&factor;
        temp_Q = Q&factor;
        if(temp_P == temp_Q)
        {
            if(temp_P == 0)
                Quadrant_P[i] = 0;  /*"1st quadrant"*/
            else
                Quadrant_P[i] = 2;  /*"3rd quadrant"*/
        }
        else
        {
            if((temp_P == 0) && (temp_Q))
                Quadrant_P[i] = 3;  /*"4th quadrant"*/
            else
                Quadrant_P[i] = 1;  /*"2nd quadrant"*/
        }
        factor >>= 1;         			
    }
    
    /*"到目前为止求出的象限的顺序为：总/C/B/A"*/
    temp_P = Quadrant_P[3];			                 /*"C和A对调"*/
    Quadrant_P[3] = Quadrant_P[1];	
    Quadrant_P[1] = temp_P;
    /*"求出的象限的顺序为：总/A/B/C"*/	
}	

/*"============================================================
函数说明：电量数据进位主函数（进位最小单位0.01或0.001），主循环调用
输入参数：无                  
输出参数：无
返    回：无
作者：GANJP  版本：1.00
============================================================"*/	
void Energy_Accumulation_Unit_10Wh(void)	           //Accumulating Energy,resolution limiting=0.01kW.h
{
    UINT16 quad;	           //quad:0,1,2,3,corresponding to 1st,2nd,3rd,4th quadrant
    UINT16 phase,phase1;	                   //phase:0,1,2,corresponding to Phase A,Phase B,Phase C
    UINT32 *Sour;
    UINT32 *Dest;
    UINT32 temp;
    UINT8 crc_cal_flag = 0;
    UINT8 crc_rail_flag=0;
    UINT8 i;
    UINT8 j;
    UINT32 energy_1mwh_100mwh;
  		
    if (!SpicReq_SC_DEFINE)
    {
        if((TRAFF_RATE<1)||(TRAFF_RATE>(MAXTRIFF-1)))
            TRAFF_RATE=1;
    }
    else
    {	/*"四川特殊要求"*/
        if (TRAFF_RATE==0x00 || TRAFF_RATE>4)
            TRAFF_RATE=1;
    }
  	
 #ifdef WS_METER_ENERGY_TRANSFER
      energy_1mwh_100mwh=360000;
 #else  
      energy_1mwh_100mwh=ENERGY_VALUE_1MWH_100MWH;
 #endif
    for(i=0;i<2;i++)/*"0-总和分费率正向有功电量累加 1-总和分费率反向有功电量累加"*/
    {
        for(j=0;j<ENERGY_VALUE_100MWH_001WH;j++)
        {
            if((*(&energy_rail.Rail_Plus_Active[0]+i*4))>=energy_1mwh_100mwh)
            {
                (*(&energy_rail.Rail_Plus_Active[0]+i*4))-=energy_1mwh_100mwh;
                (*(&energy_rail.Total_Plus_Active_100mwh[0]+i*MAXTRIFF))++;
                (*(&energy_rail.Total_Plus_Active_100mwh[TRAFF_RATE]+i*MAXTRIFF))++;
                crc_rail_flag=1;
            }
            
            if((*(&energy_rail.Total_Plus_Active_100mwh[0]+i*MAXTRIFF))>=ENERGY_VALUE_100MWH_001WH)
            {
                (*(&energy_rail.Total_Plus_Active_100mwh[0]+i*MAXTRIFF))-=ENERGY_VALUE_100MWH_001WH;
                (*(&This_Month_Data.Energy_Record.Plus_Active[0]+i*MAXTRIFF))+=1;
                crc_cal_flag = 0xff;
            }
            
            if((*(&energy_rail.Total_Plus_Active_100mwh[TRAFF_RATE]+i*MAXTRIFF))>=ENERGY_VALUE_100MWH_001WH)
            {
                (*(&energy_rail.Total_Plus_Active_100mwh[TRAFF_RATE]+i*MAXTRIFF))-=ENERGY_VALUE_100MWH_001WH;
                (*(&This_Month_Data.Energy_Record.Plus_Active[TRAFF_RATE]+i*MAXTRIFF))+=1;
                if((i==0)||((i==1)&&(Meter_Parameter.parameter1.Activem_Erengy_Mode.byte==0x05)))
                {
                    Remain_Money_Duct(1);	//payment
                }
                crc_cal_flag = 0xff;
            }
        }
    }	
	
    //Dispose sum 4 quadrants reactive power and its current fee energy
    for(quad=0;quad<=3;quad++)
    {	/*"累加合相无功的4相限无功电量"*/
        Sour=&(energy_rail.Rail_Quad_Reactive[0][quad]);     //[PHASE:sum,A,B,C][QUAD:0,1,2,3]
        Dest=&(This_Month_Data.Energy_Record.Quad_Reactive[quad][0]);//[QUAD][sum,fee 1,...]
        if(Updating_Energy_Source_Destination(Sour,Dest))
        {
            This_Month_Data.Energy_Record.Quad_Reactive[quad][TRAFF_RATE]+=Enery_Increment;	//[QUAD][sum,fee 1,...]   

            crc_cal_flag = 0xff;              
        }
    }
	
    //Dispose positive active power of Phase A,B,C
    for(phase=0;phase<=2;phase++)
    {
        Sour=&(energy_rail.Rail_Plus_Active[phase+1]);       //[PHASE:sum,A,B,C]
        Dest=&(This_Month_Data.Energy_Record.Phase_Plus_Active[phase]);	 //[PHASE:A,B,C]
        if(Updating_Energy_Source_Destination(Sour,Dest))
            crc_cal_flag = 0xff;           
    }
	
    //Dispose negative active power of Phase A,B,C
    for(phase=0;phase<=2;phase++)
    {
        Sour=&(energy_rail.Rail_Nega_Active[phase+1]);       //[PHASE:sum,A,B,C]
        Dest=&(This_Month_Data.Energy_Record.Phase_Nega_Active[phase]);	 //[PHASE:A,B,C]
        if(Updating_Energy_Source_Destination(Sour,Dest))
            crc_cal_flag = 0xff;  
    }

  //Dispose 4 quadrants reactive power of Phase A,B,C
    for(phase=0;phase<=2;phase++)
    for(quad=0;quad<=3;quad++)
    {
        Sour=&(energy_rail.Rail_Quad_Reactive[phase+1][quad]);	   //[PHASE:sum,A,B,C][quad]
        Dest=&(This_Month_Data.Energy_Record.Phase_Reactive[phase][quad]);	   //[PHASE:A,B,C][quad]
        if(Updating_Energy_Source_Destination(Sour,Dest))
            crc_cal_flag = 0xff;           
    }	
	
    /*"求A/B/C相的安时值：单位为0.1An.h"*/
    for(phase=0;phase<=2;phase++)
    {
        Sour=&(tempamphour[phase]);
        Dest=&temp; 
        if(Updating_Source_Destination(Sour,Dest,ANHOUR_VALUE_01ANH))//liuyq added 2009-9-15 
        {
            Event_AmpHour[phase]=Event_AmpHour[phase]+1;  //change by pc 081020	
        }
    }	 
    
    if(crc_cal_flag)
    {
        This_Month_Data.Energy_Record.crc_cal = CRC((UINT8*)&This_Month_Data,
        sizeof(struct ENERGY_RECORD) - 2);
    }
    
    if(crc_cal_flag||crc_rail_flag)
    {
        energy_rail.crc_cal = CRC((UINT8*)&energy_rail,
                 sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2);  
    } 

	/*"求铜损、铁损和互感器合成误差"*/
  //********************************************************************
  //#define KA2H_01	360000000	/*"将0.0000001kA2s转换成0.01kA2h:(I*I)/10000*0.0000001kA2s"*/
  //#define MV2H_01	3600000000	/*"将0.00000001MV2s转换成0.01MV2h:(V*V)/1000000*0.00000001MV2s"*/
  //#define	Hechengwucha_01	3600	/*"将100Pi/Pr*s转换成0.01Pi/Pr*h"*/
  /*"下面三个定义放入struct POWERDOWN_SAVE_DATA中"*/
  //UINT32 Rail_Tongsun[4];	/*sum,A,B,C*/
  //UINT32 Rail_Tiesun[4];	/*sum,A,B,C*/
  //UINT32 Rail_Hechengwucha[4];	/*sum,A,B,C*/

  /*"下面三个定义放入struct ENERGY_POWERDOWN中"*/
  //UINT32 Tongsun[4];	/*sum,A,B,C*/
  //UINT32 Tiesun[4];	/*sum,A,B,C*/
  //UINT32 Hechengwucha[4];	/*sum,A,B,C*/

  //********************************************************************
//  for(phase=0;phase<=3;phase++)
//  {
//    Updating_Source_Destination(&Powerdown_Save_Data.Rail_Tongsun[phase],
//    &This_Month_Data.Energy_Record.Tongsun[phase],KA2H_01);
//    //This_Month_Data.Energy_Record.Tongsun[0]+=1;
//    Updating_Source_Destination(&Powerdown_Save_Data.Rail_Tiesun[phase],
//    &This_Month_Data.Energy_Record.Tiesun[phase],MV2H_01);
//    //This_Month_Data.Energy_Record.Tiesun[0]+=1;
//    Updating_Source_Destination(&Powerdown_Save_Data.Rail_Hechengwucha[phase],
//    &This_Month_Data.Energy_Record.Hechengwucha[phase],Hechengwucha_01);
//    //This_Month_Data.Energy_Record.Hechengwucha[0]+=1;
//  }	
}
/*"============================================================
函数说明：电量进位处理，根据电能显示小数位数（2、3）
          采用不同的累加方式，解决总和各分费率电量之和有差异的问题
输入参数：Source：源数据指针（及计量尾数）                  
输出参数：Destination：目标数据指针（及当前电量数据）
返    回：return_value 0 没有进位  1 有进位
作者：GANJP  版本：1.00
============================================================"*/	
UINT8 Updating_Energy_Source_Destination(UINT32 *Source,UINT32 *Destination)
{	
    UINT8 return_value;
    
    /*"电量为3位小数"*/	
    Enery_Increment=1;
#ifdef WS_METER_ENERGY_TRANSFER
    return_value = Updating_Source_Destination(Source, Destination, 3600000);
#else  
    return_value = Updating_Source_Destination(Source, Destination, ENERGY_VALUE_001KWH);
#endif

    return return_value;
}

/*"============================================================
函数说明：检测电量是否需要进位处理（计量尾数是否大于设定的进位阀值）
输入参数：Source：源数据指针（及计量尾数）                  
输出参数：Destination：目标数据指针（及当前电量数据）
返    回：return_value  0 没有进位  1 有进位
作者：GANJP  版本：1.00
============================================================"*/	
UINT8 Updating_Source_Destination(UINT32 *Source,UINT32 *Destination,UINT32 Step)
{		
    if(Step > 0)
    {
        if(*Source>=Step)			
        {
            *Source-=Step;			   //Source is substracted by Step.
            (*Destination)++;		   //Destination is added by 0.01.
            return 1;
        }
        else
            return 0;	
    }
    else
    {
        return 0;
    }

}

UINT32 Get_Max_Value(UINT32 X,UINT32 Y,UINT32 Z)
{ 
    UINT32 tempvalue;

    tempvalue = X;
    if(Y>X)
        tempvalue = Y;
    
    if(tempvalue <Z)
        tempvalue = Z;
    
    return tempvalue;		
}
void Middle_Energy_Accumulation_PerSecond_Main_Program(void)
{
    Dispose_Data_Received_From_Mesuring_Meter();
    Middle_Energy_Accumulation_PerSecond();
    Check_Voltage_Threshold();
    if((Meter_Parameter.parameter1.MeterMode[0].bit.b7==0) || (demand_start == 0xff)) //change by pc 120727
    {
        Demand_Accumulator();
    }
    Read_Sign_Instance_Variable();
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void Init_Relation_Meter_Apply(void)
{
    Deal_PulseConst_Init();
    //InitTimeB0();
    //InitTimeB2();
    InitTimeA2();
    InitTimeB4();
    InitTimeB1();
    InitTimeB5();
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void DealPulseConst(UINT32 inC,UINT16 *outC)
{
    *outC=0;
    if(inC)
    {
        if((PULSE_CONST_H %inC) ==0)
        {
            *outC=PULSE_CONST_H / inC -1 ;
        }
        else
        {
            *outC = 0;
        }
    }	 
}
void Deal_PulseConst_Init(void)
{
    DealPulseConst(Meter_Parameter.parameter1.ActivePulseConst,&FRE_CONST_P);
    DealPulseConst(Meter_Parameter.parameter1.ReactivePulseConst,&FRE_CONST_Q);
    Pulse_Constant_Writting=0;
}

/*"**********有功脉冲计数处理**********"*/
void InitTimeA2(void)
{
    ta2ic=0x00;
    if(!IntoPowerDownFlag)
    {	
        ta2mr=0x01;//ganjp 20090213 old is 0x09
        tabsr &= ~0x04;  //add by jiehuang 20130708 must stop counting,then value is writen to both reload register and counter

        //FRE_CONST_P=3;
        ta2=FRE_CONST_P;     /*"有功脉冲分频系数"*/
        //prcr|=0x04;
        udf=0;
        //udf&=0xfb;    
        trgsr&=0xf3;
        tabsr |= 0x04;
        ta2ic=0x07;
    }
    else
    {
        InitTimeA2_PowerDown();
    }
}


void InitTimeB4(void)
{
    tb4ic=0x00;

    ifsr2a&=0x7f;
    tb4mr=0x01;
    tbsr&=~0x40;   //add by jiehuang 20130708 must stop counting,then value is writen to both reload register and counter

    tb4=FRE_CONST_Q;        /*"无功脉冲分频系数"*/
    //prcr|=0x04;
    tbsr|=0x40;
    tb4ic=0x07;
}
void InitTimeB1(void)
{	
    UINT32 temp_con;
    tb1ic=0x00;

    tb1mr=0x80;
    temp_con=PULSE_WIDTH;
    if((temp_con>=10)&&(temp_con<=120))
    {
        temp_con=(temp_con*3125L)/10L;//old is 10000
        tb1=temp_con;
    }
    else
        tb1=0x61a7;

    //tbsr|=0x40;
    //ifsr2a&=0x7f;
    tb1ic=0x07;
}

void InitTimeB5(void)
{
    UINT32 temp_con;//modified 2007-06-12
    tb5ic=0x00;

    tb5mr=0x80;
    temp_con=PULSE_WIDTH;
    if((temp_con>=10)&&(temp_con<=120))
    {
        temp_con=(temp_con*3125L)/10L;
        tb5=temp_con;
    }
    else
        tb5=0x61a7;

    //tbsr|=0x80;
    tb5ic=0x07;
}

#pragma INTERRUPT TimerA3_Int
void  TimerA3_Int(void)
{
//  R_EOUT=0;
//  //Pluse_Timer_Q=0;                                   /*"Pluse_Timer_Q计时达到80mS将R_EOUT还原为0"*/
//  tbsr|=0x40;
//  //ta3=FRE_CONST_Q;                                     /*"重置A3计数器计数因子"*/
//  R_EOU1=0;  
}

#pragma INTERRUPT TimerA2_Int
void  TimerA2_Int(void)
{
    if(!IntoPowerDownFlag)	
    {
        A_EOUT=0;
        //Pluse_Timer_P=0;                                     /*"Pluse_Timer_P计时达到80mS后将A_EOUT引脚置零"*/
        tbsr|=0x80;
        //ta2=FRE_CONST_P;                                     /*"重置B4计数器的计数因子"*/      
        A_EOU1=1;
    }
    else
    {
        TimerA2_Int_Interrupt();
    }
}

#pragma INTERRUPT TimerB4_Int
void  TimerB4_Int(void)
{
    //  R_EOUT=1;
    //  tbsr&=0xbf;
    //  
    //  R_EOU1=1;   
    R_EOUT=0;
    tabsr|=0x40;
    R_EOU1=1;  
}
#pragma INTERRUPT TB1_Int
void	TB1_Int(void)								/*"TB1定时器中断服务程序"*/
{

    R_EOUT=1;
    tabsr&=0xbf;

    R_EOU1=0;  
}

#pragma INTERRUPT TimerB5_Int
void  TimerB5_Int(void)
{
    A_EOUT=1;
    tbsr&=0x7f;

    A_EOU1=0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////**********
UINT8 Send_Pulse_Constant_Data_to_Meter(UINT8 kind,UINT32 Acconst)
{
    UINT8 retvalue;
    UINT32 temp;

    retvalue=0;      
    if(kind <2)
    {
        temp=Acconst;
        if(temp!=0)
        {
            temp=PULSE_CONST_H % temp;
            if(temp==0)
            {
                Pulse_Constant_Writting=1;
                if(kind)
                    Meter_Parameter.parameter1.ReactivePulseConst=Acconst;
                else
                    Meter_Parameter.parameter1.ActivePulseConst=Acconst;
                
                retvalue=1;
            }
        }
    }
    
    //liuyq modify 2009-9-15 end
    return(retvalue);
}
//////**********
void Check_If_Writting_Pulse_Constant_To_Card(void)
{	
    if(Pulse_Constant_Writting==1)
    {
        WRLC256(ACTIVEPULSECONST_ROM,(UINT8 *)&Meter_Parameter.parameter1.ActivePulseConst,8,0,0);
        Set_Meter_para_Deal(ACTIVEPULSECONST_ROM);
        Pulse_Constant_Writting=0;

        asm("FCLR I");
        Init_Relation_Meter_Apply();
        asm("FSET I");
    }
}

void Voltage_Phase_Deal(void)
{
    FP32 temp;

    if(_rMeter_State_Buffer.fgDataReady)
    {
        if((V_REGION==0)||(V_REGION==3))  /*"331三相三线"*/
        {
            Voltc[1]=Voltage_AC_Calculate(Volt[0], Volt[2], angle[1]);//ganjp 20090409

            Volt_Phase[0]=Volt[0]/1000L;
            Volt_Phase[1]=Voltc[1]/1000L;
            Volt_Phase[2]=Volt[2]/1000L;
            if((Volt_Phase[0]!=0)&&(Volt_Phase[1]!=0)&&(Volt_Phase[2]!=0))
            {
                temp=Volt[0]+Volt[2];
                //if(Voltc[1]!=0)
                temp=temp/Voltc[1];
                if((temp<=1.10)&&(temp>=0.90))
                {
                    //temp=Volt[0]+Volt[2];
                    temp=Voltc[1];
                    if(((Volt[0]/temp)>0.1)&&((Volt[2]/temp)>0.1))
                    {
                        Meter_331_LostVoltage_B_break=1;
                    }
                    else//ganjp 20091123 for B phase loss voltage
                    {
                        Meter_331_LostVoltage_B_break=0;
                    }
                }
                else
                {
                    Meter_331_LostVoltage_B_break=0;          //lxw 
                }
            }       
        }
        
        _rMeter_State_Buffer.fgDataReady = FALSE;
    }
}

//////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define	PI			3.14159
#define	PI_2		1.57079
#define Iterative_N	10					/*"迭代次数"*/

void	Calculate_Arccos_FA(void)		/*"求总,A,B,C的相角"*/
{
    FP64	FA;
    UINT16 i;
    UINT16 quadrant[4];					//quadrant value(0~3) of Sum,A,B,C			
    UINT32 Imax;

    Get_Quadrant_Value(quadrant);				//get quadrant value(0~3) of Sum,A,B,C

    Imax=Get_Max_Value(Curr[0],Curr[1],Curr[2]);

    /*----------- Flash Active Power Direction ---------------------*/
    if(Imax>=Meter_Parameter.parameter1.EventJudgeIn/1000L)
    {	/*"电流大于启动电流时才计算相角"*/
        for(i=0;i<=3;i++)
        {
            //CosFA=(FP64)Factor[i]/1000000.0;
            //FA=acos(CosFA);					/*"单位：弧度"*/


            if(Active_power[i]<=5)				 /*"防止除零溢出,有功功率小于0.000005kW"*/
            {                                                            
                if(Reactive_power[i] <= 5)  //modified by jiehuang 20120920 to sovle phase angle will be 90 degree,while phase current is downing
                {
                    Phase_Angle[i] = 0;	
                }
                else
                {
                    Phase_Angle[i] = 9000L;			
                }	
            }
            else
            {   
                FA=atan_FA((FP64)Reactive_power[i]/Active_power[i]);
                FA=(FA*18000.0)/PI;				/*"化成角度"*//*"取2位小数"*/
                //FA=FA*100.0;					
                Phase_Angle[i]=(UINT32)FA;
            }
            
            switch(quadrant[i])
            {
                case 0:				/*"第1象限"*/
                    break;
                case 1:				/*"第2象限"*/
                    Phase_Angle[i]=18000-Phase_Angle[i];
                    break;	
                case 2:				/*"第3象限"*/
                    Phase_Angle[i]=18000+Phase_Angle[i];
                    break;	
                default:			/*"第4象限"*/
                    Phase_Angle[i]=36000-Phase_Angle[i];
                    break;
            }
        }

        for(i=1;i<=3;i++)
        {
            if(Curr[i-1]<Meter_Parameter.parameter1.EventJudgeIn/1000L)
                Phase_Angle[i]=0;			/*"分相电流小于启动电流时，其相角强制置为0"*/															
        }					
    }
    else
    {	/*"所有分相电流都小于启动电流时，所有相角强制置为0"*/
        Phase_Angle[0]=0;
        Phase_Angle[1]=0;
        Phase_Angle[2]=0;
        Phase_Angle[3]=0;
    }

    if((V_REGION==0)||(V_REGION==3))			
        Phase_Angle[2]=0;

    for(i=0;i<4;i++)
    {
        if(Phase_Angle[i]==36000)
            Phase_Angle[i]=0;
    }
}

/*--------------------------------------------------------------------------------*/		
FP64 atan_FA(FP64 x)
{
    SINT16 i, sgn, ixi, ix2p1;
    FP64 a;

    if (x > 1) 
    {
        sgn = 1;
        x = 1 / x;
    } 
    else if (x < -1) 
    {
        sgn = -1;
        x = 1 / x;
    } 
    else 
    {
        sgn = 0;
    }
    
    for (a = 0, i =Iterative_N; i >= 1; i--)
    {
        ix2p1 = i * 2 + 1;
        ixi = i * i;
        a = ((FP64)ixi * x * x) / ((FP64)ix2p1 + a);
    }
    
    if (sgn > 0)
        return PI_2 - x / (1 + a);
    if (sgn < 0)
        return -PI_2 - x / (1 + a);
    
    return x / (1 + a);
}

/*"============================================================"*/
/*"已知AB /CB电压，计算AC电压"*/
/*"算法优化方案：c*c = a*a + b*b - 2abcosθ = (a-b)*(a-b) + 2ab(1-cosθ)
更多的采用加减法代替乘法运算，减少程序空间和提高运算速度"*/
/*"============================================================"*/
UINT32  Voltage_AC_Calculate(UINT32 Uab,UINT32 Ubc,UINT32 angle)
{
    UINT32 temp;
    FP32 temp_f= 0.0;
    FP32  L = 0.0;
    FP32 temp_f1 = 0.0;
    FP32 temp_f2 = 0.0;

    if(angle>18000)
        angle=36000-angle;

    temp_f1 = angle * PI;
    temp_f = temp_f1  / 18000l;
    temp_f2 = cosf(temp_f);/*"cosθ"*/

    temp_f1  = 2 * Uab ;
    temp_f1  = temp_f1* Ubc ;/*"2ab"*/

    temp_f = (Uab - Ubc) * (Uab - Ubc);/*"(a-b)*(a-b)"*/

    L = temp_f + temp_f1 * (1 - temp_f2);/*"(a-b)*(a-b) + 2ab(1-cosθ)"*/

    L = sqrt(L);  
    temp = (UINT32)L;
    
    return temp;
}
/*"============================================================"*/
//liuyq added 2009-9-16 start
/*"
* 函数介绍：读/写内卡中校表参数，读/写后再抄读该数据进行比较确保数据正确，3次异常报错，
* 输入参数：Addr：         数据内卡地址
            Data_length：  数据长度
            OperationType：操作方式 0:write check  1:read check
* 输出参数：SourceP：      数据保存地址
            CompP：        比较数据地址
* 返    回：0xff：读/写正确  0：读/写错误
/*"============================================================"*/

UINT8 WR_Check_eeprom(UINT16 Addr, UINT8* SourceP, UINT8* CompP, UINT8 Data_length, UINT8 OperationType)
{
    UINT8 i,j;

    for(i=0;i<3;i++)
    {
        WRLC256(Addr,SourceP,Data_length,0,OperationType);
        if(!OperationType)
            Delay(10);
        
        WRLC256(Addr,CompP,Data_length,0,1);
        for(j=0; j<Data_length;j++)
        {
            if((*(SourceP+j)) != (*(CompP+j)))
                break;
        }
        if(j==Data_length)
            break;
    }
    
    if(j==Data_length)
        return TRUE;
    
    return FALSE;
}

/*"------ganjp20091031---------"*/
/*"check if the direction of activepower changed"*/
UINT8 Activepower_Direct_Change_Chk(void)
{
    UINT8 comp = 0;
    UINT8 result = 0;

    comp = (_rMeter_Data_Buffer.bPowerDir & (1<<POWERDIR_ACT_POWER_SUM)) >> 3;
    if(comp != (Meter_States.Meter_Status1.byte & 0x10))
        result = 0xff;

    return result;
}

/*"============================================================
函数说明：计算CRC校验并进行比较确认数据是否有效
输入参数：source_addr：需要进行CRC校验的数据源地址
          comp_value ：CRC比较值（原CRC计算值）
          crc_len    ：数据长度（进行CRC计算的数据长度）
输出参数：无
返    回：ret_value  ：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
============================================================"*/
UINT8 Check_RAM_CRC(UINT8 *source_addr, UINT16 comp_value, UINT16 crc_len)
{
    UINT16  comp_crc = 0;
    UINT8 ret_value = 0;

    comp_crc =  CRC(source_addr,crc_len);

    if(comp_value == comp_crc)
    {
        ret_value = 1;
    }	
    
    return (ret_value);
}

/*"==============================================================
函数说明：检查EEPROM/FLASHROM中校表数据有效性(CRC校验和累加和校验)
输入参数：eeprom_addr：需要进行检查的数据源地址 （内卡地址）
          data_len   ：数据长度（进行检查的数据长度）
          kind       : 0 EEPROM   1:FLASHROM
输出参数：无
返    回：ret_value  ：0 数据无效  1 数据有效
作    者：GANJP  版本：1.00
================================================================"*/
UINT8 Check_ROM_Just_Para(UINT16 eeprom_addr, UINT16 data_len, UINT8 kind)
{
    UINT8 ret_value = 0;
    UINT16 uni;
    UINT8 times = 0;

    if((UINT8)data_len &(UINT8)3) /*"检查数据长度是否为4字节的整数倍"*/
        return 0; 

    for(times = 0; times < 3; times++)	
    {
        for(uni = 0; uni < data_len; uni++)
            Co.b[500 + uni] = 0;

        if(kind == 0) /*"E2PROM"*/
        {
            WRLC256(eeprom_addr,(UINT8 *)&Co.b[500],data_len,0,1);
        }	  	  
        else if(kind ==1) /*"FLASH"*/
        {
            FlashRead((FLASH_PTR_TYPE)eeprom_addr,(BUF_PTR_TYPE)&Co.b[500],data_len);
        }			
        else
        {
        
        }	  		
        ret_value = Check_RAM_CRC((UINT8 *)&Co.b[500],*((UINT16 *)&Co.b[500 + data_len - 2]),(data_len -2));//check crc

        if(ret_value)
        {
            break;
        }	  	
        else
        {
            Delay(20);
        }	  	
    }			

    return (ret_value);
}

/*"**************************************************************"*/
/*"bType = 0，将E2PROM或FLASH中校表参数恢复到JustMeter_Parameter"*/
/*"bType = 1，将默认校表参数恢复到JustMeter_Parameter"*/
/*"**************************************************************"*/
void Cal_para_Resume(UINT8 bType)
{
    UINT8 i = 0;
    UINT16  wLen = 0;

    wLen = sizeof(struct JUSTMETER_PARAMETER);

    /*"Step 1: 校表参数清零"*/
    for(i = 0; i < wLen; i++)
        *((UINT8 *)&JustMeter_Parameter + i) = 0;

    /*"Step 2: 校表参数重置"*/
    if(bType == 0)
    {
        for(i = 0; i < wLen; i++)
            *((UINT8 *)&JustMeter_Parameter + i) = Co.b[500 + i];
    }
    else
    {
        for(i = 0; i < sizeof(stMeter_JustPraDef); i++)
        {
            *((UINT8 *)&JustMeter_Parameter + i) = *((UINT8 far*)&_rMeter_JustPraDef + i);
        }	
        JustMeter_Parameter.wPraCrc = CRC((UINT8*)&JustMeter_Parameter,wLen - 2);	
    }
}

void	Delay_Wait(UINT16 unit_10_uS)
{
    UINT16 i;
    UINT16 j;
    UINT16 nop_number=3;

    for(i=0;i<=unit_10_uS;i++)
    for(j=0;j<nop_number;j++)
        asm("nop");			
}

BOOL fgJustParaRamCrcOk(void)
{
    BOOL fgRet = FALSE;

    fgRet = Check_RAM_CRC((UINT8 *)&JustMeter_Parameter, 
                            JustMeter_Parameter.wPraCrc, sizeof(struct JUSTMETER_PARAMETER) -2);

    return(fgRet);
}

void Just_para_Power_on(void)
{
    UINT8 data_valid = 0;
    UINT8 i;

    /*"RAM中校表参数合法性检测"*/
    data_valid = fgJustParaRamCrcOk();

    if((data_valid == 0)||(_bJustParaFrom == JUST_PARA_FROM_NULL)||(_bJustParaFrom == JUST_PARA_FROM_DEFAULT))
    {
        for(i = 0;i < 20;i++)
        {
            /*"FLASH中校表参数合法性检测"*/
            data_valid = Check_ROM_Just_Para(0xe000, sizeof(struct JUSTMETER_PARAMETER), 1);
            if(data_valid)
            {
                Cal_para_Resume(0);
                _bJustParaFrom = JUST_PARA_FROM_FLASH;
                break;
            } 
            else
            {
                /*"E2PROM中校表参数合法性检测"*/
                data_valid = Check_ROM_Just_Para(JUSTMETER_PARA_ROM, sizeof(struct JUSTMETER_PARAMETER), 0);
                if(data_valid)
                {
                    Cal_para_Resume(0);
                    _bJustParaFrom = JUST_PARA_FROM_E2PROM;
                    break;
                }
                else
                {
                    Delay(10);
                }
            }

            FeedWatchdog();  
            CheckPowerDown();

        }
        
        /*"FLASH和E2PROM中校表参数都不合法时，使用默认校表参数"*/ 
        if(i >= 20)
        {
            Cal_para_Resume(1);
            _bJustParaFrom = JUST_PARA_FROM_DEFAULT;
        }
    }
    else
    {
        _bJustParaFrom = JUST_PARA_FROM_RAM;
    }

    Meter_States.Meter_Flag.bit.Energymodule_Err = 0;	
}

void vMeter_VoltCurrSpecInit(void)
{
    switch(VOLT_SPEC)
    {
        case 1000000:   /*"100V"*/ 
            V_REGION = 0;
            break;
        case 2200000:   /*"220V"*/ 
            V_REGION = 1;
            break;
        case 577000:    /*"57.7V"*/ 
            V_REGION = 2; 
            break;
        case 3800000:   /*"380V"*/ 
            V_REGION = 3;
            break;
        default:
            V_REGION = 1;
            break;
    }

    switch(CURR_SPEC)
    {
        case 15000:      /*"1.5(6)A"*/ 
            I_REGION = 0;
            break;
        case 3000:       /*"0.3(1.2)A"*/ 
            I_REGION = 1;
            break;
        case 1000:       /*"0.1(1)A"*/ 
            I_REGION = 2;
            break;
        case 10000:     /*"1(10)A"*/ 
            I_REGION = 3;
            break;
        case 50000:      /*"5(60)A"*/ 
            I_REGION = 4;
            break;
        case 100000:    /*"10(100)A"*/ 
            I_REGION = 5;
            break;
        case 300000:     /*"30(100)A"*/ 
            I_REGION = 6;
            break;
        case 200000:     /*"20(80)A"*/ 
            I_REGION = 7;
            break;
        default:
            I_REGION = 0;
            break;
    }
}

BOOL fgJustparaOkChk(void)
{
    BOOL fgRet = FALSE;
    BOOL fgJustParaDef = FALSE;

    if(_bJustParaFrom == JUST_PARA_FROM_DEFAULT)
    {
        fgJustParaDef = TRUE;
    }

    Just_para_Power_on();

    fgRet = fgJustParaRamCrcOk();

    if(fgRet)
    {
        if((Meter_States.Meter_Flag.bit.Energymodule_Err == 1) ||(fgJustParaDef&&(_bJustParaFrom != JUST_PARA_FROM_DEFAULT)))
        {
            vMeter_VoltCurrSpecInit();
            _rMeter_State_Buffer.fgPraLoadOk = FALSE;
        }
        Meter_States.Meter_Flag.bit.Energymodule_Err = 0;	
    }
    else
    {
        Meter_States.Meter_Flag.bit.Energymodule_Err = 1;	
    }

    return (fgRet);
}

UINT8 _bJustParaDefCycle = 0;
BOOL fgJustParaHandler(void)
{
    if(_rMeter_State_Buffer.bCalState == SV_CAL_STATE_START) 
    {
    #ifdef WS_ERR_OFFSET_FUNC
        vMeter_ErrOffsetAdjust(TRUE);
    #endif	
        return(TRUE);
    }
    else
    {
        /*"Type 1:RAM中校表参数每秒检测CRC"*/
        if(fgJustParaRamCrcOk())
        {
            Meter_States.Meter_Flag.bit.Energymodule_Err = 0;
        }
        else
        {
            Meter_States.Meter_Flag.bit.Energymodule_Err = 1;
            if(!fgJustparaOkChk())
            {
                return(FALSE);
            }
        }

        /*"Type 2:校表参数为默认值时，在厂外状态下，每5秒重新读取校表参数"*/
        if((O1ther_Meter_Parameter.WorkRoomState == 0) && (_bJustParaFrom == JUST_PARA_FROM_DEFAULT))  
        {
            _bJustParaDefCycle++;
            if(_bJustParaDefCycle >= 5)  
            {
                _bJustParaDefCycle = 0;
                if(!fgJustparaOkChk())
                {
                    return(FALSE);
                }
            }
        }

        /*"Type 3:加载校表参数"*/
        if(!_rMeter_State_Buffer.fgPraLoadOk)
        {
            if(fgMeter_Para_Load())
            {
                _rMeter_State_Buffer.fgPraLoadOk = TRUE;
            }
            else
            {
                return(FALSE);
            }
        }

        /*"Type 4:计量芯片中参数检测"*/
        if(!fgMeter_ICPraOk())
        {
            return(FALSE);
        }

    #ifdef WS_ERR_OFFSET_FUNC
        /*"Type 5:比差和角差分段补偿"*/
        vMeter_ErrOffsetAdjust(FALSE);
    #endif	

        return(TRUE);
    }
}

BOOL fgJustParaPDLoad(void)
{
    BOOL fgRet = FALSE;

    fgRet = fgMeter_Para_Load();

    return (fgRet);
}
/*"==============================================================
函数说明：掉电情况下加载校表参数，只加载电流系数，用于全失压判断           
输入参数：无
输出参数：无  
返    回：无
作    者：GANJP  版本：1.00
================================================================"*/
void Just_meter_PD(void)
{
    UINT8 result=0xff;

    if(load_flag == 0xff)
    {
        if(L_PD_Last_T > (PDOPEN6515RELAYTIME+2))
        {
            result = fgJustParaPDLoad();
            if(result != 0)
            {
                load_flag = 0;
            }
            else
            {
                Delay(4); 
                result = fgJustParaPDLoad();
                if(result != 0)
                {
                    load_flag = 0;
                }
            }  
        }
    }
}

/*"函数功能:计量接口特殊函数，此处插入按键主接口函数，提高按键查询频率"*/
/*"输入参数:无"*/
/*"输出参数:无"*/
/*"调用说明:计量主接口函数中调用"*/
void vMeter_ResInterface(void)
{
    CheckPowerDown();

    Key_Main();
}




