/************************************************************
  Copyright (C), 1988-1999, Wasion Group 
  FileName:     71M6545_Meter.c
  Description:  71M6545_Meter driver file
  Author:    jiehuang,wumin      
  Version :  1.0        
  Date:   2015/08/06 
  Funciton list:

  
  History:         
      <author>              <time>    <version >    <desc>
      jiehuang,wumin  2015/08/06    1.0           build this moudle  
***********************************************************/
#include  "Defdata.h"
#include  "ram.h"
#include  "Multi.h"
#include  "interrupt.h"
#include  <math.h>
#include  <float.h>
#include  "HT7038_Meter.h" 
#include  "Measure_Interface.h"

#pragma SECTION program ROM_PRG2   

//****************************************************************
//Meter  register define     
//****************************************************************
#define REG_RESERVE   0x00
#define REG_P_A        0x01
#define REG_P_B        0x02
#define REG_P_C        0x03
#define REG_P_T        0x04
#define REG_Q_A        0x05
#define REG_Q_B        0x06
#define REG_Q_C        0x07
#define REG_Q_T        0x08
#define REG_S_A        0x09
#define REG_S_B        0x0A
#define REG_S_C        0x0B
#define REG_S_T        0x0C

#define REG_U_A       0x0D
#define REG_U_B       0x0E
#define REG_U_C       0x0F
#define REG_I_A        0x10
#define REG_I_B        0x11
#define REG_I_C        0x12
#define REG_I_N        0x13

#define REG_PF_A       0x14
#define REG_PF_B       0x15
#define REG_PF_C       0x16
#define REG_PF_T       0x17

#define REG_FRE       0x19

#define REG_AENERGY_A       0x1E
#define REG_AENERGY_B       0x1F
#define REG_AENERGY_C       0x20
#define REG_AENERGY_T       0x21

#define REG_RENERGY_A       0x22
#define REG_RENERGY_B       0x23
#define REG_RENERGY_C       0x24
#define REG_RENERGY_T       0x25

#define REG_TEMPRAW          0x26
#define REG_VERION              0x27

#define RSPIDATA 		     0x28

#define REG_ANGLE_UAB        0x29
#define REG_ANGLE_UAC        0x2A
#define REG_TEMP                  0x2B
#define REG_SFLAG         	      0x2C     /*"计量状态标志寄存器"*/

#define REG_WFLAG 	             0x30     /*"电量溢出标志寄存器"*/

#define REG_PFLAG         		0x3D     /*"功率方向标志寄存器"*/
#define REG_ADD_CHK         	0x3F

//****************************************************************
//parameters declare
//****************************************************************
INT16U _wMeter_ICParaErrCnt;

INT8U  _bMeter_DataRdErrCnt;    //read data error times
INT8U _bMeter_DataValErrCnt;   //the value of data error times

INT8U _bMeter_RstType = METER_RST_TYPE_PWRUP;    
INT16U _wMeter_RstCnt = 0;    

stMeter_Data_Buffer _rMeter_Data_Buffer;

BOOL _fgMeter_DataReady = FALSE;
BOOL _fgMeter_NeedLoadPara = FALSE;

INT32U _dwMeter_Version = WS_METER_SW_VER;

INT8U tdk6545_rw_flag;
INT8U TDK6545_ready_flag;    /*"6545忙标志(CE处理) 0：忙 0xff:空闲"*/
INT16U  ready_relay_times;    /*"CE中断结束910ms后如果SPI通信使能仍开放，需暂时关闭使能，以免正在SPI通信的时候来了CE中断"*/

INT32U mid_eng_temp[8];/*"保存上次读取6545电量数据，如果两次读取电量数据相差超过设定值报错，防止电量跳变"*/

INT32U _dwTestHj00 = 0;
INT32U _dwTestHj01 = 0;

//****************************************************************
//MACRO define
//****************************************************************
#define  METER_IC_PARA_ERR_TIMES    6

#define WRITE_6545_BASE_ADDR    0x400
#define READ_6545_BASE_ADDR    0x690
#define MAX_6545_ADDR    297	//!!!!!!should be updated

#define ENERGY_MAXVALUE     (0x1000000L) //0x1000000 for test,0x1000000 for product

#define TDK71M6545_READ_COMMAND 0x80	//should not use the com 0x80
#define TDK71M6545_WRITE_COMMAND 0x40
#define TDK71M6545_STATE_ERROR1 0x03 
#define TDK71M6545_STATE_ERROR2 0x80
#define TDK71M6545_STATE_ERROR  0x83 

//****************************************************************
//Meter  function declare
//****************************************************************
BOOL fgMeter_GetAllModeEnergy(INT8U wRegAddr, INT32U* pdwEnergy);
BOOL fgMeter_GetEnergy(void);
BOOL fgMeter_GetAngle(void);
BOOL fgMeter_GetTemp(void);
BOOL fgMeter_ICParaChk(INT16U wRegAddr,INT16U wRamData);

BOOL fgMeter_GetVolt(void);
BOOL fgMeter_GetCurr(void);
BOOL fgMeter_GetNCurr(void);
BOOL fgMeter_GetP(void);
BOOL fgMeter_GetQ(void);
BOOL fgMeter_GetS(void);
BOOL fgMeter_GetPF(void);
BOOL fgMeter_GetFreq(void);
BOOL fgMeter_GetState(void);

const INT16U _wMeter_71M6545_Addr[][2] = {//write =0,read=1
    //0x00-0x07
    {0x0, 0},//no use
    {0x01,READ_6545_BASE_ADDR+4},//a active power
    {0x02,READ_6545_BASE_ADDR+8},//b acitve power
    {0x03,READ_6545_BASE_ADDR+12},//c active power
    {0x04,READ_6545_BASE_ADDR},//total active power	
    {0x05,READ_6545_BASE_ADDR+20},//a reactive power
    {0x06,READ_6545_BASE_ADDR+24},//b reactive power
    {0x07,READ_6545_BASE_ADDR+28},//c reactive power 
    //0x08-0x0f
    {0x08,READ_6545_BASE_ADDR+16},//totaol reactive power
    {0x09,READ_6545_BASE_ADDR+36},//a app power
    {0x0a,READ_6545_BASE_ADDR+40},//b app power
    {0x0b,READ_6545_BASE_ADDR+44},//c app power
    {0x0c,READ_6545_BASE_ADDR+32},// total app power
    {0x0d,READ_6545_BASE_ADDR+48},// a volt
    {0x0e,READ_6545_BASE_ADDR+52},// b volt
    {0x0f,READ_6545_BASE_ADDR+56},// c volt
    //0x10-0x17
    {0x10,READ_6545_BASE_ADDR+60},// a curr
    {0x11,READ_6545_BASE_ADDR+64},// b curr
    {0x12,READ_6545_BASE_ADDR+68},// c curr
    {0x13,READ_6545_BASE_ADDR+172},// irmst,l curr
    {0x14,READ_6545_BASE_ADDR+88},// a pf
    {0x15,READ_6545_BASE_ADDR+92},// B PF
    {0x16,READ_6545_BASE_ADDR+96},// C PF
    {0x17,READ_6545_BASE_ADDR+84},// TOTAL PF
    //0x18-0x1f
    {0x18,READ_6545_BASE_ADDR+168},//calculating from three phase current
    {0x19,READ_6545_BASE_ADDR+72},//frequncy
    {0x1a,READ_6545_BASE_ADDR+265},//a apparant energy,butter add,2011.8.24
    {0x1b,READ_6545_BASE_ADDR+269},//b apparant energy
    {0x1c,READ_6545_BASE_ADDR+273},//c apparant energy          modified by Qin
    {0x1d,READ_6545_BASE_ADDR+277},//total apparant energy      modified by Qin
    {0x1e,READ_6545_BASE_ADDR+104},// a active erengy
    {0x1f,READ_6545_BASE_ADDR+108},// b active erengy
    //0x20-0x27
    {0x20,READ_6545_BASE_ADDR+112},// c active erengy
    {0x21,READ_6545_BASE_ADDR+116},// total active erengy
    {0x22,READ_6545_BASE_ADDR+120},// a reactive erengy
    {0x23,READ_6545_BASE_ADDR+124},// b reactive erengy
    {0x24,READ_6545_BASE_ADDR+128},// c reactive erengy
    {0x25,READ_6545_BASE_ADDR+132},// total reactive erengy
    {0x26,READ_6545_BASE_ADDR+225},// temperature adjust
    {0x27,READ_6545_BASE_ADDR+229},// firmware version
    //0x28-0x2f
    {0x28,READ_6545_BASE_ADDR+233},// reserve spi read data,byte232
    {0x29,READ_6545_BASE_ADDR+217},// degree of phase a to b 
    {0x2a,READ_6545_BASE_ADDR+221},// degree of phase b to c
    {0x2b,READ_6545_BASE_ADDR+181},//temperature,2011.8.21 lijunmodified
    {0x2c,READ_6545_BASE_ADDR+237},// c reactive erengy
    {0x2d,READ_6545_BASE_ADDR+241},// reserve spi wirte data1
    {0x2e,READ_6545_BASE_ADDR+245},// reserve spi wirte data2
    {0x2f,READ_6545_BASE_ADDR+281},// thd_w,added by Butter,2012.11.20
    //0x30-0x37
    {0x30,READ_6545_BASE_ADDR+249},// erengy flag
    {0x31,READ_6545_BASE_ADDR+104},// clear a active erengy,addr is no used
    {0x32,READ_6545_BASE_ADDR+108},// clear b active erengy
    {0x33,READ_6545_BASE_ADDR+112},// clear c active erengy
    {0x34,READ_6545_BASE_ADDR+116},// clear total active erengy
    {0x35,READ_6545_BASE_ADDR+120},// clear a reactive erengy
    {0x36,READ_6545_BASE_ADDR+124},// clear b reactive erengy
    {0x37,READ_6545_BASE_ADDR+128},// clear c reactive erengy
    //0x38-0x3f
    {0x38,READ_6545_BASE_ADDR+132},// clear total active erengy,addr is no used
    {0x39,READ_6545_BASE_ADDR+285},// add for xxYYMMDD  by qin
    {0x3a,READ_6545_BASE_ADDR+289},// add for WWHHMMSS  by qin
    {0x3b,READ_6545_BASE_ADDR+293},// Thd Voltage
    {0x3c,READ_6545_BASE_ADDR+297},// Thd Current
    {0x3d,READ_6545_BASE_ADDR+253},// clear a reactive erengy
    {0x3e,READ_6545_BASE_ADDR+257},// cali data checksum1
    {0x3f,READ_6545_BASE_ADDR+261}// cali data checksum2,cmd=5f
};

//****************************************************************
//Meter just para default value
//****************************************************************
#pragma SECTION rom UserROMData
const stMeter_Just_Para_Def _rMeter_Just_Para_Def = 
{      
    //stMeter_71M6545_Cal_Para_Init
    {
        0x00000000,           //METERMODE       0
        0x00002e67,           //PLUS CONST      1
        0x00000018,           //RESERVE         2
        0x00004000,           //I_PainA         3
        0x00004000,           //V_PainA         4
        0x00004000,           //I_PainB         5
        0x00004000,           //V_PainB         6
        0x00004000,           //I_PainC         7
        0x00004000,           //V_PainC         8
        0x00004000,           //PHASE_A         9
        0x00004000,           //PHASE_B         A
        0x00004000,           //PHASE_C         B
        0x000D1F60,           //TEMP            C
        0x00000000,           //ACTIVE_Imin     D
        0x00000000,           //REACTIVE_Imin   E
        0x00000001,           //EaddMode        F
        0x00000001,           //VMAX            16
        0x00000007,           //IMAX            17
        0x000F8DE8,           //Add_CHK         18
    },
    //stMeter_Spec_Para_Val_Init
    {  
        0x0e297d00,  //dwPwrLimit                              
        0x0001adb0,  //dwEngLimit                    
        0x00002ee0,  //dwCFconstH       	
    }
};

//****************************************************************
//Meter  delay function
//****************************************************************
void vDelay_Us(INT16U wCnt)
{
    while(wCnt--);
}

void vDelay_Ms(INT16U wCnt)   
{
    INT16U i;
    while(wCnt--)
    {
        FeedWatchdog();
        for (i = 0;i < 1412;i++);
    }
}

//****************************************************************
//Meter  SPI function
//****************************************************************
//SPI pin
#define METER_SPI_CS_DIR(x)         ((x)? (pd0 |= (1<<7)):(pd0 &= ~(1<<7)))
#define METER_SPI_CS(x)                  ((x)?( p0_7 = 1):(p0_7 = 0)) 

#define METER_SPI_CLK_DIR(x)       do{  prcr|=0x04; ((x)? (pd9 |= (1<<0)):(pd9 &= ~(1<<0))); }while(0)
#define METER_SPI_CLK(x)                ((x)?(p9_0 = 1):(p9_0 = 0))    

#define METER_SPI_MISO_DIR(x)     do{  prcr|=0x04; ((x)? (pd9 |= (1<<1)):(pd9 &= ~(1<<1))); }while(0)
#define METER_SPI_MISO                  ((p9_1)? 0:1)

#define METER_SPI_MOSI_DIR(x)     do{  prcr|=0x04; ((x)? (pd9 |= (1<<2)):(pd9 &= ~(1<<2))); }while(0)
#define METER_SPI_MOSI(x)              ((x)?( p9_2 = 1):(p9_2 = 0))   

#define TDK71M6545_SIG_PORT      p0_4

#define DELAY_US  4

void vMeter_SPI_Init(void)
{
    prc2 = 1;

    METER_SPI_CS_DIR(SV_PIN_OUTPUT);
    METER_SPI_CS(SV_HIGH);

    METER_SPI_CLK_DIR(SV_PIN_OUTPUT);
    METER_SPI_CLK(SV_HIGH);

    METER_SPI_MOSI_DIR(SV_PIN_OUTPUT);
    METER_SPI_MOSI(SV_HIGH);

    METER_SPI_MISO_DIR(SV_PIN_INPUT);
}

void vWrite_TDK71M6515_Data(INT8U bRegAddr,INT32U dwData)
{
    INT8U buffer[5],temp,*pointer;
    INT8U i,j;
    INT8U tdk6545_write_count,tdk6545_state; 
    INT16U tdk6545_addr;

    tdk6545_addr=WRITE_6545_BASE_ADDR;
    bRegAddr&=0x3f;//add by lijun,6545 write command is 0xxxxxxx
    vDelay_Us(200);
    
    pointer=(INT8U *)&dwData;//small endian to big endian.
    buffer[4]=*pointer;
    pointer++;
    buffer[3]=*pointer;
    pointer++;
    buffer[2]=*pointer;
    pointer++;
    buffer[1]=*pointer;
    buffer[0]=bRegAddr;//send cmd

    //	    asm("	FCLR I");
    tdk6545_write_count=0;//first time to write
    
    do{       
        METER_SPI_CS_DIR(SV_PIN_OUTPUT);
        METER_SPI_CS(SV_LOW);
        if(tdk6545_write_count) 	/*"不是第一次操作spi"*/
        {
            vDelay_Ms(5);
            //Delay1(5);//delay 5ms
        }
        
        METER_SPI_CLK(SV_LOW);
        METER_SPI_CS(SV_LOW);
        vDelay_Us(20);                        //6515 answer time

        for(i = 0; i < 30; i++)
        {
            if(METER_SPI_MISO == 0)
            {
                vDelay_Us(2);
                if(METER_SPI_MISO == 0)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                vDelay_Us(2);
            }
        }

        temp=(INT8U )((tdk6545_addr>>8)&0xff);
        for( i = 0;i <8;i++)// high addr
        {
            if((temp&0x80) == 0x80)
            {
                METER_SPI_MOSI(SV_HIGH);
            }
            else
            {
                METER_SPI_MOSI(SV_LOW);
            }		
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //8 nop
            METER_SPI_CLK(SV_HIGH);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //10 nop
            temp <<= 1;
            METER_SPI_CLK(SV_LOW);	
        }

        temp=(INT8U )(tdk6545_addr&0xff);
        for( i = 0;i <8;i++)// lower addr
        {
            if((temp&0x80) == 0x80)
            {
                METER_SPI_MOSI(SV_HIGH);
            }
            else
            {
                METER_SPI_MOSI(SV_LOW);
            }		
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //8 nop
            METER_SPI_CLK(SV_HIGH);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //10 nop
            temp <<= 1;
            METER_SPI_CLK(SV_LOW);	
        }

        //vDelay_Us(20);
        //	   command_rw_6515|=TDK71M6545_WRITE_COMMAND;
        bRegAddr =TDK71M6545_WRITE_COMMAND;//modified by lijun,2011.8.21,the cmd is stored in buffer[0].
        temp=bRegAddr;
        for( i = 0;i <8;i++)// write write command
        {
            if((temp&0x80) == 0x80)
            {
                METER_SPI_MOSI(SV_HIGH);
            }
            else
            {
                METER_SPI_MOSI(SV_LOW);
            }		
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //8 nop
            METER_SPI_CLK(SV_HIGH);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //10 nop
            temp <<= 1;
            METER_SPI_CLK(SV_LOW);	
        }

        /*"需要根据6515的反应速度定*/
        vDelay_Us(30); 
        tdk6545_state=0;//get tdk state
        for(i = 0;i < 8;i++)
        {
            METER_SPI_CLK(SV_HIGH);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //10 nop
            if(METER_SPI_MISO)
            {
                asm("nop");
                asm("nop");
                if(METER_SPI_MISO)
                {
                    tdk6545_state=tdk6545_state|0x01;     
                }
            }	
            asm("nop");
            asm("nop");
            METER_SPI_CLK(SV_LOW);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //10 nop
            if(i!=7)
            {
                tdk6545_state<<=1;
            }
        }

        tdk6545_state = tdk6545_state;
        vDelay_Us(30);
        tdk6545_write_count++;
    }while((tdk6545_state&TDK71M6545_STATE_ERROR)&&(tdk6545_write_count<=3));

    if(tdk6545_write_count>3)
    {
        //6545 communication error???
        tdk6545_rw_flag=1;	
        //		   asm("	FSET I");
        return;
    }  

    for(i=0;i<5;i++)
    {	   
        for(j=0;j<8;j++)
        {
            if((buffer[i]&0x80) == 0x80)
            {
                METER_SPI_MOSI(SV_HIGH);
            }
            else
            {
                METER_SPI_MOSI(SV_LOW);
            }		
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            // 6 nop  
            METER_SPI_CLK(SV_HIGH);
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            //8 nop
            buffer[i] <<= 1;
            METER_SPI_CLK(SV_LOW);	
        }                					
    }			

    METER_SPI_CS(SV_HIGH);
    //	asm("	FSET I");	
}

INT32U dwRead_TDK71M6515_Data(INT8U bRegAddr)
{
  	INT8U i,j,temp,*pointer;
  	INT32U paradata_6515;
  	INT16U tdk6545_addr;
  	INT8U tdk6545_state;//read 6545 state
	INT8U tdk6545_read_count;
	INT32U *point;
    
  	temp=0;
	tdk6545_state=0;
  	paradata_6515=0; 
  	tdk6545_read_count=0;	  
    
  	//add io init
  	if(bRegAddr==0x5f)
		bRegAddr=0x3f;//array 3f
		
 	tdk6545_addr=_wMeter_71M6545_Addr[bRegAddr][1];
  	if((tdk6545_addr < READ_6545_BASE_ADDR) || (tdk6545_addr > (READ_6545_BASE_ADDR + MAX_6545_ADDR)))
  	{
	  	return 0xffffffff;	//error addr,should be took care 
	}
 
  	vDelay_Us(30);
	//	asm("	FCLR I");
	do
	{	
		METER_SPI_CS_DIR(SV_PIN_OUTPUT);
		METER_SPI_CS(SV_HIGH);
  		if(tdk6545_read_count) 	//"不是第一次操作spi"
		{
			vDelay_Ms(5);//delay 5ms
		}
  		METER_SPI_CLK(SV_LOW);   
  		METER_SPI_CS(SV_LOW);
  
  		tdk6545_state=0;
  		vDelay_Us(12);                        //delay uS

  		for(i = 0; i < 20; i++)
  		{
  			if(METER_SPI_MISO == 0)
    		{
    			vDelay_Us(2);
      			if(METER_SPI_MISO == 0)
      			{
      				break;
				}
      			else
        			continue;
    		}
    		else
    		{
      			vDelay_Us(2);
    		}

  		}
  
  		temp=(INT8U)((tdk6545_addr>>8)&0xff);
//---------ganjp 20090305--------------------	  
	  	for( i = 0;i <8;i++)//high addr
		{
			if((temp&0x80) == 0x80)
			{
				METER_SPI_MOSI(SV_HIGH);
			}
			else
			{
				METER_SPI_MOSI(SV_LOW);
			}		
			asm("nop");
		  	asm("nop");
			asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
			//7 nop
			METER_SPI_CLK(SV_HIGH);
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop"); 
			asm("nop"); 
			asm("nop");
			//13 nop
			temp <<= 1;
			METER_SPI_CLK(SV_LOW);	
		}
	  
	  	//low addr
	 	temp=(INT8U)(tdk6545_addr&0xff);

	 	for( i = 0;i <8;i++)//high addr
		{
			if((temp&0x80) == 0x80)
			{
				METER_SPI_MOSI(SV_HIGH);
			}
			else
			{
				METER_SPI_MOSI(SV_LOW);
			}		
			asm("nop");
		  	asm("nop");
			asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
			//7 nop
			METER_SPI_CLK(SV_HIGH);
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop"); 
			asm("nop"); 
			asm("nop");
			//13 nop
			temp <<= 1;
			METER_SPI_CLK(SV_LOW);	
		}	
      
      	vDelay_Us(28);                        //delay 28uS
	  
	  	//read command
	  	bRegAddr=TDK71M6545_READ_COMMAND|bRegAddr;
	 	temp=bRegAddr;
		for( i = 0;i <8;i++)//command
		{
			if((temp&0x80) == 0x80)
			{
				METER_SPI_MOSI(SV_HIGH);
			}
			else
			{
				METER_SPI_MOSI(SV_LOW);
			}		
			asm("nop");
		  	asm("nop");
			asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
			//7 nop
			METER_SPI_CLK(SV_HIGH);
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop"); 
			asm("nop"); 
			asm("nop");
			//13 nop
			temp <<= 1;
			METER_SPI_CLK(SV_LOW);	
		}
      
  		vDelay_Us(30); 
  		//get tdk state
  		tdk6545_state=0;//get tdk state
  		temp=0;
		for(i = 0;i < 8;i++)
		{
			METER_SPI_CLK(SV_HIGH);
			asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
			//10  nop
			if(METER_SPI_MISO)
	      	{
	        	asm("nop");
	          	asm("nop");
	      		if(METER_SPI_MISO)
	           	{
	           		temp=temp|0x01;     
	      		}
	       	}	
		  	asm("nop");
		  	asm("nop");
			METER_SPI_CLK(SV_LOW);
			asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
	    	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
		  	asm("nop");
			//10 nop
	      	if(i!=7)
	      	{
	       		temp<<=1;
	      	}
		}  
                		
  		tdk6545_state=temp;
  		vDelay_Us(30);
		tdk6545_read_count++;
	
	}while((tdk6545_state&TDK71M6545_STATE_ERROR)&&(tdk6545_read_count<=3));
	//“状态错误时，延时再读，超过3次报错”

	
	if(tdk6545_read_count>3)
	{
		tdk6545_rw_flag=1;
		return 0;
	}   

   	FeedWatchdog();		

	pointer= (INT8U *)&paradata_6515; 
	pointer++;
	pointer++;
	pointer++; 
	  
	for(i=0;i<4;i++)
	{
		temp=0;
		for(j=0;j<=7;j++)
		{
	      	METER_SPI_CLK(SV_HIGH);
	       	asm("nop");
	     	asm("nop");
	    	asm("nop");
	  		asm("nop");
			asm("nop");
	       	asm("nop");
	     	asm("nop");
	    	asm("nop");
	  		asm("nop");
			asm("nop");	                            
			//10 nop
	       	if(METER_SPI_MISO)
	 		{
				asm("nop");
				asm("nop");
	  			//asm("nop");
	    		if(METER_SPI_MISO)
	    		{
					temp=temp|0x01;  
	          	}
	       	}
	     	asm("nop");
	  		asm("nop");
	      	METER_SPI_CLK(SV_LOW);
	       	asm("nop");
	     	asm("nop");
	    	asm("nop");
	  		asm("nop");
			asm("nop");
	       	asm("nop");
	     	asm("nop");
	    	asm("nop");
	  		asm("nop");
			asm("nop");
	       	asm("nop");
	     	asm("nop");
	    	asm("nop");
	  		asm("nop");
			asm("nop");
			//15 nop
			if(j!=7)  
			{
				temp<<=1;
			}
		}
	             
		*pointer=temp;
		pointer--;
		vDelay_Us(5);
	}	
     
 	METER_SPI_CS(SV_HIGH);
    
  	return(paradata_6515);
}

INT8U Compare_6515Read_Data(INT8U bRegAddr,INT32U* data_comp)
{
      INT8U i,ret_value;
      INT32U tempdata;

	  ret_value=0;
      vDelay_Us(500);      //modified by lijun,2011.5.6,200-500  
      for(i=0;i<3;i++)
      {
             tempdata=dwRead_TDK71M6515_Data(0x28);
            if(tempdata == *data_comp)
            {
                  ret_value = 1;
                  break;
            }
            else
            {
                  ret_value = 0;
                  //////2006-06-21
                  //vDelay_Us(24);
                  vDelay_Ms(20);                                          /*"延时20mS"*/
                  *data_comp = dwRead_TDK71M6515_Data(bRegAddr);
                  //////2006-06-21 
            }
      }
      return(ret_value);
}

/*"**********TDK71M6515写数据比较**********"*/
INT8U Compare_6515Write_Data(INT8U bRegAddr,INT32U dwData)
{
    INT8U i,ret_value,*pointer;
    INT32U tempdata;

    ret_value=0;
    vDelay_Us(500);  //500us
    pointer=(INT8U *)&dwData;
    for(i=0;i<3;i++)
    {
        tempdata=dwRead_TDK71M6515_Data(0x2d);
        if(tempdata == (dwData&0xffffffff))
        { 
            ret_value = 1;
            break;
        }
        else
        {
            ret_value = 0;
            vDelay_Us(24);
            //Delay1(20); 
            vDelay_Ms(20);/*"延时20mS"*/
            //////2006-06-21 
            vWrite_TDK71M6515_Data(bRegAddr,dwData);
        }
    }
    
    return(ret_value);
}

INT8U ReadAndCheck_TDK71M6515(INT8U bRegAddr, INT32U* DataBuff)
{
      *DataBuff=dwRead_TDK71M6515_Data(bRegAddr);      
      return Compare_6515Read_Data(bRegAddr,DataBuff);
}

void vMeter_71M6545_WriteCtrl(BOOL fgCtrl)
{
    if(fgCtrl == SV_ENABLE)
    {
        vWrite_TDK71M6515_Data(0x93,0x55aa55aa);      /*"校表数据写使能"*/
        vDelay_Ms(1); 
        vWrite_TDK71M6515_Data(0x92,0x00000001);      /*"校表数据写使能"*/
    }
    else
    {
        vWrite_TDK71M6515_Data(0x92,0x00000000);      /*"校表数据写关闭"*/
        vDelay_Ms(1); 
        vWrite_TDK71M6515_Data(0x93,0x00000000);      /*"校表数据写关闭"*/
    }
}

void TDK6545_Ready_Check(void)
{
    if(TDK71M6545_SIG_PORT == 1)/*"检测CE中断结束，TDK71M6545_SIG_PORT由高变低"*/
    {
        ready_relay_times = 0;
        TDK6545_ready_flag = FALSE; 	
    }
    else
    {
        if(ready_relay_times !=0)/*"CE中断结束后隔5ms后再判一次，以免是干扰信号"*/
        {
            TDK6545_ready_flag = TRUE;/*"打开SPI通信使能"*/
        }	
        
        ready_relay_times++;
        /*"CE中断结束850ms后如果SPI通信使能仍开放，需暂时关闭使能，以免正在SPI通信的时候来了CE中断"*/
        if((ready_relay_times > 170) && (TDK6545_ready_flag == TRUE))
        {
            TDK6545_ready_flag = FALSE;
        }
    }

}

//****************************************************************
//Meter  software version
//****************************************************************
void vMeter_Version(void)
{
    INT8U bTemp = 0;

#if defined(WS_DEMO_VERSION)
    bTemp = 0x00;
#endif

    _dwMeter_Version = WS_METER_SW_VER + bTemp;
}


//****************************************************************
//Meter  Init function
//****************************************************************
//pre init Meter,load para in next cycle(delay >300ms) make sure 71M6545 run steady after reset
void vMeter_Init(INT8U bType)
{
    INT16U i;

    FeedWatchdog();	 
    CheckPowerDown();

    /***********************************************/
    //Step 1:Meter pin initialize
    /***********************************************/
    vMeter_SPI_Init();   

    FeedWatchdog();	 
    CheckPowerDown();

    /***********************************************/
    //Step 2:Meter parameters  initialize
    /***********************************************/
    _wMeter_ICParaErrCnt = 0;

    _bMeter_DataRdErrCnt = 0;
    _bMeter_DataValErrCnt = 0;

    _bMeter_RstType = bType;
    _wMeter_RstCnt++;
    if(_wMeter_RstCnt >= 60000) //less than 2^16
    {
        _wMeter_RstCnt = 0;
    }

    for(i = 0;i < sizeof(stMeter_Data_Buffer);i++)   
        *((INT8U*)&_rMeter_Data_Buffer + i) = 0;

    _fgMeter_NeedLoadPara = TRUE;

    FeedWatchdog();
    CheckPowerDown();

}

//****************************************************************
//Meter para init function
//****************************************************************  
BOOL fgMeter_71M6545_Pra_Init(void)
{
    INT8U i,bRegAddr;
    BOOL fgRet = FALSE;

    FeedWatchdog();	 
    CheckPowerDown();

    vMeter_71M6545_WriteCtrl(SV_ENABLE);

    for(i = 0x00;i < 0x12;i++)
    {
        if(i == 0x0c)//not need just temparature parameter
        {
            continue;
        }     
        
        bRegAddr = i + 0x80;
        vWrite_TDK71M6515_Data(bRegAddr, *((INT32U*)&JustMeter_Parameter.stMeter_71M6545_Para_Val + i));
        fgRet = Compare_6515Write_Data(bRegAddr,*((INT32U*)&JustMeter_Parameter.stMeter_71M6545_Para_Val + i));
        if(!fgRet)
        {
            break;
        }	
    }

    vMeter_71M6545_WriteCtrl(SV_DISABLE);

    if(fgRet)
    {
        vDelay_Ms(450);          
        
        fgRet = FALSE;
        if(dwRead_TDK71M6515_Data(REG_ADD_CHK) == JustMeter_Parameter.stMeter_71M6545_Para_Val.Add_CHK)
        {
            fgRet = TRUE;
        }
    }

    return(fgRet);   
}

BOOL fgMeter_Para_Init(void)
{
    BOOL fgRet = FALSE;

    FeedWatchdog();	 
    CheckPowerDown();

    /***********************************************/
    //Step 1:Meter paramter init
    /***********************************************/ 
    fgRet = fgMeter_71M6545_Pra_Init();
    if(!fgRet)  
        return(fgRet); 

    return(TRUE);
}

BOOL fgMeter_Para_Load(void)    
{    
    INT8U i;
    BOOL fgRet=FALSE;

    if(fgJustParaRamCrcOk())
    {
        for(i=0;i<10;i++)
        {
            fgRet = fgMeter_Para_Init();
            if(fgRet)
            {
                break;
            }
            else
            {
                vDelay_Ms(1);
            }
        }	  
    }
    else
    {
        Meter_States.Meter_Flag.bit.Energymodule_Err = 1;
    }

    return(fgRet);
}

BOOL fgMeter_Com_JustParaSet(INT8U bCommAddr,INT32U dwCalData)  
{
    BOOL  fgRet = FALSE;
    INT8U i;
    INT32U *pl;

    i = bCommAddr - 0x80;

    if(i < (0x00 + (METER_71M6545_PARA_SIZE - 1)))
    {
        pl= (INT32U *)&JustMeter_Parameter.stMeter_71M6545_Para_Val.meter_mode; 
        pl+= i;
        *pl= dwCalData;

        vMeter_71M6545_WriteCtrl(SV_ENABLE);

        vWrite_TDK71M6515_Data(i,dwCalData);	
        vDelay_Ms(1);  
        fgRet = Compare_6515Write_Data(i,dwCalData); 

        vMeter_71M6545_WriteCtrl(SV_DISABLE);
    }	 
    else if((i >= 0x20)&&(i < (0x20 + METER_SPEC_PRA_SIZE )))
    {
        i -= 0x20;

        if(i == 2)
        {
            if(dwCalData%100 != 0) //add by jiehuang 20150311,PULSE_CONST_H must be multiple of 100 
            {
                return(FALSE);
            }
            Pulse_Constant_Writting = 1;
        }

        pl = (INT32U *)&JustMeter_Parameter.stMeter_Spec_Para_Val.dwPwrLimit; 
        pl += i;
        *pl = dwCalData;

        fgRet = TRUE;
        }
        else
        {
            fgRet = FALSE;
        }

    return(fgRet);
}

//****************************************************************
//Meter data and status get function
//****************************************************************
BOOL fgMeter_Function(void)
{ 
    BOOL fgRet = FALSE;

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

    fgRet = fgMeter_GetTemp();
    if(!fgRet)
        return(FALSE);   		

    vMeter_ResInterface();

    fgRet = fgMeter_GetEnergy();
    if(!fgRet)
        return(FALSE);   

    _fgMeter_DataReady = TRUE;

    return (TRUE);

}

//****************************************************************
//Meter  macro define
//****************************************************************
#ifdef WS_DEAL_71M6545_SPEC_STATUS
INT32U dwMeter_VoltJudgeZero(void)
{
    INT32U dwRet;
    
    /*"判电压为0的阀值为 2% 额定电压"*/
    dwRet = VOLT_SPEC / 50;

    return(dwRet);
}

INT32U dwMeter_CurrJudgeZero(void)
{
    INT32U dwRet;

    /*"判电流为0的阀值为潜动电流"*/
    dwRet = CURR_SPEC / 1000;
    dwRet *= JustMeter_Parameter.stMeter_71M6545_Para_Val.reserve_current;
    dwRet += 5;
    dwRet /= 10; 

    return(dwRet);
}

INT32U dwMeter_PJudgeZero(void)
{
    INT32U dwTemp;
    INT32U dwRet;

    /*"判有功功率为0的阀值为潜动功率"*/
    dwTemp = CURR_SPEC / 1000;
    dwTemp *= JustMeter_Parameter.stMeter_71M6545_Para_Val.reserve_current;
    dwTemp *= (VOLT_SPEC / 1000);

    dwRet = (INT32U)(dwTemp / 1000);

    return(dwRet);
}

INT32U dwMeter_QJudgeZero(void)
{
    INT32U dwTemp;
    INT32U dwRet;

    /*"判有功功率为0的阀值为潜动功率"*/
    dwTemp = CURR_SPEC / 1000;
    dwTemp *= JustMeter_Parameter.stMeter_71M6545_Para_Val.reserve_current;
    dwTemp *= (VOLT_SPEC / 1000);

    dwRet = (INT32U)(dwTemp / 1000);
    
    return(dwRet);
}
#endif

BOOL fgMeter_GetVolt(void)
{    
    INT8U ii,jj;
    INT32U dwTemp;

#ifdef WS_DEAL_71M6545_SPEC_STATUS
    INT32U dwVoltJudgeZero;
    dwVoltJudgeZero = dwMeter_VoltJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 3;ii++)
    {        
        for(jj = 0;jj < 3;jj++)
        {  
            if(ReadAndCheck_TDK71M6515(REG_U_A + ii,(INT32U *)&dwTemp))
            { 
                if(dwTemp < 0x80000000)
                {
                #ifdef WS_DEAL_71M6545_SPEC_STATUS
                    if(dwTemp < dwVoltJudgeZero)  // if the value is less than VOLT_SPEC*2/100, make the value be 0
                    {
                        dwTemp = 0;
                    }
                #endif	
                    _rMeter_Data_Buffer.dwVolt[ii] = dwTemp;
                    break; 
                }
            }	   	 	 	 
        }

        if(jj == 3)  //read 3 times still error, return false
        {
            return(FALSE);
        }
    }
    
    return(TRUE);
}	

BOOL fgMeter_GetCurr(void)
{    
    INT8U ii,jj;
    INT32U dwTemp;

#ifdef WS_DEAL_71M6545_SPEC_STATUS
    INT32U dwCurrJudgeZero;
    dwCurrJudgeZero = dwMeter_CurrJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 3;ii++)
    {        
        for(jj = 0;jj < 3;jj++)
        {  
            if(ReadAndCheck_TDK71M6515(REG_I_A + ii,(INT32U *)&dwTemp))
            { 
            #ifdef WS_DEAL_71M6545_SPEC_STATUS
                if(dwTemp < CURR_SPEC / 50)   /*"电流在2%额定电流以下，电流采取特殊处理"*/
                {
                    if(_rMeter_Data_Buffer.dwVolt[ii] != 0) 
                    {
                        if(_rMeter_Data_Buffer.dwS[ii + 1] == 0)  //apparent power ==0
                        {
                            if(dwTemp < dwCurrJudgeZero)	
                            {
                                dwTemp = 0;
                            }
                        }
                        else
                        {
                            dwTemp = (INT32U)(100000 * ((FP32)(_rMeter_Data_Buffer.dwS[ii + 1]) / (_rMeter_Data_Buffer.dwVolt[ii]))); //because _rMeter_Data_Buffer.dwS[ii + 1]*100000 is  overflow(too large),so we need change them to float type
                        }	
                    }
                    else
                    {   
                        if(dwTemp < dwCurrJudgeZero)	
                        {
                            dwTemp = 0;
                        }
                    }
                }				
            #endif

                _rMeter_Data_Buffer.dwCurr[ii] = dwTemp;
                break; 
            }
        }	   	 	 	 

        if(jj == 3)  //read 3 times still error, return false
        {
            return(FALSE);
        }
    }

    return(TRUE);
}

BOOL fgMeter_GetNCurr(void)
{
    INT8U jj;
    INT32U dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    for(jj = 0;jj < 3;jj++)
    {  
        if(ReadAndCheck_TDK71M6515(REG_I_N,(INT32U *)&dwTemp))
        { 
            //add by jiehuang 20120921 to sovle N current special status
        #ifdef WS_DEAL_71M6545_SPEC_STATUS   
            if((_rMeter_Data_Buffer.dwCurr[0] == 0) && (_rMeter_Data_Buffer.dwCurr[1] == 0) && (_rMeter_Data_Buffer.dwCurr[2] == 0))   
            {
                dwTemp = 0;
            }
        #endif			

            _rMeter_Data_Buffer.dwNCurrCal = dwTemp;
            break; 
        }
    }			  

    if(jj == 3)  //read 3 times still error, return false
    {
        return(FALSE);
    }

    return(TRUE);
}

BOOL fgMeter_GetP(void)
{
    INT8U ii,jj;
    INT32U dwTemp;

#ifdef WS_DEAL_71M6545_SPEC_STATUS
    INT32U dwPJudgeZero;
    dwPJudgeZero = dwMeter_PJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {        
        for(jj = 0;jj < 3;jj++)
        {  
            if(ReadAndCheck_TDK71M6515(REG_P_A + ii,(INT32U *)&dwTemp))
            { 
                if(dwTemp & 0x80000000)
                {
                    dwTemp = 0x100000000 - dwTemp;
                    _rMeter_Data_Buffer.bPowerDir |= (1 << (POWERDIR_ACT_POWER_A + ii));
                }
                else
                {
                    _rMeter_Data_Buffer.bPowerDir &= ~(1 << (POWERDIR_ACT_POWER_A + ii));
                }

            #ifdef WS_DEAL_71M6545_SPEC_STATUS
                if(ii != 3)
                {
                    if(_rMeter_Data_Buffer.dwVolt[ii] != 0)   
                    {
                        if(_rMeter_Data_Buffer.dwCurr[ii] < CURR_SPEC / 20)   /*"电流在5%额定电流以下，功率采取特殊处理"*/
                        {
                            if(dwTemp < dwPJudgeZero)  
                            {
                                dwTemp = 0;
                            }
                        }
                        else
                        {
                            /*"电流在5%额定电流以上，功率不做处理"*/
                        }
                    }
                    else
                    {
                        dwTemp = 0;
                    }
                }
            #endif	

                //set power direct positive when power less than no load power 
                if(dwTemp == 0)
                {
                    if(ii != 3)
                    {
                        _rMeter_Data_Buffer.bPowerDir &= ~(1 << (POWERDIR_ACT_POWER_A + ii));
                    }
                }
			
                if(ii == 3)
                {
                    _rMeter_Data_Buffer.dwP[0] = dwTemp;
                }
                else
                {
                    _rMeter_Data_Buffer.dwP[ii + 1] = dwTemp;
                }
                break; 
            }
        }	
        
        if(jj == 3)  //read 3 times still error, return false
        {
            return(FALSE);
        }
    }    

#ifdef WS_DEAL_71M6545_SPEC_STATUS	 
    //maybe sum is larger than dwPowerJudgeZero,but A,B and C are lesser than dwPowerJudgeZero
    if((_rMeter_Data_Buffer.dwP[1] == 0) && (_rMeter_Data_Buffer.dwP[2] == 0) && (_rMeter_Data_Buffer.dwP[3] == 0))   
    {
        _rMeter_Data_Buffer.dwP[0] = 0;
        _rMeter_Data_Buffer.bPowerDir &= ~(1 << POWERDIR_ACT_POWER_SUM);
    }
#endif	

    return(TRUE);
}

BOOL fgMeter_GetQ(void)
{
    INT8U ii,jj;
    INT32U dwTemp;

#ifdef WS_DEAL_71M6545_SPEC_STATUS
    INT32U dwQJudgeZero;
    dwQJudgeZero = dwMeter_QJudgeZero();
#endif

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii=0;ii<4;ii++)
    {        
        for(jj=0;jj<3;jj++)
        {  
            if(ReadAndCheck_TDK71M6515(REG_Q_A + ii,(INT32U *)&dwTemp))
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

            #ifdef WS_DEAL_71M6545_SPEC_STATUS
                if(ii != 3)
                {
                    if(_rMeter_Data_Buffer.dwVolt[ii] != 0)   
                    {
                        if(_rMeter_Data_Buffer.dwCurr[ii] < CURR_SPEC / 20)   /*"电流在5%额定电流以下，功率采取特殊处理"*/
                        {
                            if(dwTemp < dwQJudgeZero)  
                            {
                                dwTemp = 0;
                            }
                        }
                        else
                        {
                            /*"电流在5%额定电流以上，功率不做处理"*/
                        }
                    }
                    else
                    {
                        dwTemp = 0;
                    }
                }
            #endif

                //set power direct positive when power less than no load power 
                if(dwTemp == 0)
                {
                    if(ii != 3)
                    {
                        _rMeter_Data_Buffer.bPowerDir &= ~(1 << (POWERDIR_REACT_POWER_A + ii));
                    }
                }

                if(ii==3)
                {
                    _rMeter_Data_Buffer.dwQ[0] = dwTemp;
                }
                else
                {
                    _rMeter_Data_Buffer.dwQ[ii + 1] = dwTemp;
                }

                break; 
            }
        }	
        
        if(jj == 3)  //read 3 times still error, return false
        {
            return(FALSE);
        }
    }

#ifdef WS_DEAL_71M6545_SPEC_STATUS	 
    //maybe sum is larger than dwPowerJudgeZero,but A,B and C are lesser than dwPowerJudgeZero
    if((_rMeter_Data_Buffer.dwQ[1] == 0) && (_rMeter_Data_Buffer.dwQ[2] == 0) && (_rMeter_Data_Buffer.dwQ[3] == 0))   
    {
        _rMeter_Data_Buffer.dwQ[0] = 0;
        _rMeter_Data_Buffer.bPowerDir &= ~(1 << POWERDIR_REACT_POWER_SUM);
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

BOOL fgMeter_GetS(void)
{
    INT8U ii;
    FP32  fTemp0,fTemp1,fTemp2;

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {
        fTemp0 = (FP32)_rMeter_Data_Buffer.dwP[ii];       
        fTemp1 = (FP32)_rMeter_Data_Buffer.dwQ[ii];       

        fTemp2 = S_cal(fTemp0,fTemp1);

        _rMeter_Data_Buffer.dwS[ii] = (INT32U)fTemp2;
    }

    return(TRUE);
}

BOOL fgMeter_GetPF(void)
{
    INT8U ii;
    INT32U temp0,temp1,temp2;

    FeedWatchdog();	                
    CheckPowerDown();

    for(ii = 0;ii < 4;ii++)
    {
        temp0 = _rMeter_Data_Buffer.dwP[ii];	  
        temp1 = _rMeter_Data_Buffer.dwS[ii];	  

        if(temp1 != 0)
        {
            temp2 = (INT32U)(1000000 * ((FP32)temp0 / temp1));
        }
        else
        { 
            temp2 = 1000000;  //add by jie huang 2012/09/13 if app power is zero, set power factor is 1
        }

        _rMeter_Data_Buffer.dwPF[ii] = temp2;       			   
    }

    return(TRUE);
}

BOOL fgMeter_GetFreq(void)
{
    INT8U jj;
    INT32U dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    for(jj = 0;jj < 3;jj++)
    {  
        if(ReadAndCheck_TDK71M6515(REG_FRE,(INT32U *)&dwTemp))
        { 
            if(dwTemp < 0x80000000)
            {
            #ifdef WS_DEAL_71M6545_SPEC_STATUS
                if(dwTemp < 44500000)
                {
                    dwTemp = 44500000;
                }
                else if(dwTemp > 65500000)
                {
                    dwTemp = 65500000;
                }

                //add by jie huang 2012/08/07 to sovle all the voltage of A B C is 0, but freq value is not 0 issue
                if((_rMeter_Data_Buffer.dwVolt[0] == 0) && (_rMeter_Data_Buffer.dwVolt[1] == 0) && (_rMeter_Data_Buffer.dwVolt[2] == 0))   
                {
                    dwTemp = 0;
                }
            #endif

                _rMeter_Data_Buffer.dwFre[0] = dwTemp;
                _rMeter_Data_Buffer.dwFre[1] = dwTemp;
                _rMeter_Data_Buffer.dwFre[2] = dwTemp;
                
                break;
            }
        }
    }			  

    if(jj == 3)  //read 3 times still error, return false
    {
        return(FALSE);
    }
    
    return(TRUE);
}

void vMeter_State_Handler(INT32U dwState)
{
    INT8U bTemp = 0;

    if(((dwState & (1 << SFLAG_A_NOLOAD)) != 0)&&((dwState & (1 << SFLAG_B_NOLOAD)) != 0)
            &&((dwState & (1 << SFLAG_C_NOLOAD)) != 0))
    {
        _rMeter_Data_Buffer.fgNoLoad = TRUE;
    }
    else
    {
        _rMeter_Data_Buffer.fgNoLoad = FALSE;
    }

    if((dwState & (1 << SFLAG_CURR_ORDER_ERR)) != 0)
    {
        if((V_REGION == 0)||(V_REGION == 3))
        {
            // 3P3W do not judge current phase sequ,set flag as 0
        }
        else
        {
            if((_rMeter_Data_Buffer.dwCurr[0] > 0) && (_rMeter_Data_Buffer.dwCurr[1] > 0)
                    && (_rMeter_Data_Buffer.dwCurr[2] > 0))   //add by jiehuang 20110818 to solve the meter will show current abnormal sequ at IA=IB=IC=0
            {
                bTemp |= (1 << STATE0_CURR_PHASE_SEQU); 
            }
        }
    }

    if((dwState & (1 << SFLAG_VOLT_ORDER_ERR)) != 0)
    {
        if((V_REGION == 0) || (V_REGION == 3))
        {
            if(angle[1]  < 16000)  //  UAC < 16000
            {
                bTemp |= (1 << STATE0_VOLT_PHASE_SEQU); 
            }
        }
        else
        {
            bTemp |= (1 << STATE0_VOLT_PHASE_SEQU); 
        }	
    }

    _rMeter_Data_Buffer.bState0 = bTemp;
}

BOOL fgMeter_GetState(void)
{
    INT8U jj;
    INT32U dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    for(jj = 0;jj < 3;jj++)
    {
        if(ReadAndCheck_TDK71M6515(REG_SFLAG,(INT32U *)&dwTemp))
        {
            vMeter_State_Handler(dwTemp);        
            break;
        }
    }

    if(jj == 3)  //read 3 times still error, return false
    {
        return(FALSE);
    }

    return(TRUE);
}

BOOL fgMeter_GetAllModeEnergy(INT8U wRegAddr, INT32U* pdwEnergy)
{
    BOOL fgRet = TRUE;
    INT8U ii,bOffset;
    INT32U dwTemp,dwTemp1,dwTempWFlag,dwEnergy;  
    INT32U dwEnergyLimit;

    dwEnergyLimit = ENERGY_LIMIT;

    if(wRegAddr == REG_AENERGY_A)    /*"有功电量"*/        
    {
        bOffset = 0;
    }
    else  /*"无功电量"*/      
    {
        bOffset = 4;
    }

    /*"STEP 1 清零电量BUFF"*/        
    for(ii = 0;ii < 4;ii++) 	
    {
        pdwEnergy[ii] = 0;
    }	

    /*"STEP 2 读电量溢出标志"*/        
    if(!ReadAndCheck_TDK71M6515(REG_WFLAG,(INT32U *)&dwTempWFlag))
    {
        return(FALSE);
    }
    dwTempWFlag &= 0x000000FF; 

    /*"STEP 3 读电量"*/        
    for(ii = 0;ii < 4;ii++) 	
    {
        if(ReadAndCheck_TDK71M6515(wRegAddr + ii,(INT32U *)&dwTemp))
        {
            dwTemp1 = dwTemp;
            if(dwTempWFlag & (0x01 << (ii + bOffset)))
            {
                dwTemp1 += ENERGY_MAXVALUE;
            }

            if(dwTemp1 > mid_eng_temp[ii + bOffset])
            {
                dwTemp1 -= mid_eng_temp[ii + bOffset];
                if(dwTemp1 > dwEnergyLimit)
                {
                    dwEnergy = 0;
                    fgRet = FALSE;
                }
                else
                {
                    dwEnergy = dwTemp1;
                }
            }
            else
            {
                dwEnergy = 0;
            }

            mid_eng_temp[ii + bOffset] =  dwTemp;
        }
        else
        {
            dwEnergy = 0;
            fgRet = FALSE;
        }

        if(ii == 3)
        {
            pdwEnergy[0] = (INT32U)dwEnergy;
        }
        else
        {
            pdwEnergy[ii + 1] = (INT32U)dwEnergy;
        }
    }	

    return(fgRet);	   
}

/*************************************************************
 Function:            BOOL fgMeter_GetSubEnergy(INT8U bMode)
Description:          read  energy
Input Parameter:    none
Output Parameter:  none
Return:                 BOOL
Modify Time:          2011-05-20
Author:                 jie huang
*************************************************************/
BOOL fgMeter_GetSubEnergy(INT8U bMode)
{
    BOOL fgRet = FALSE;

    switch(bMode)
    {
        case READ_ENERGY_ACT:
            fgRet = fgMeter_GetAllModeEnergy(REG_AENERGY_A,(INT32U*)_rMeter_Data_Buffer.dwActEnergy);
            break;   
        case READ_ENERGY_REACT:
            fgRet = fgMeter_GetAllModeEnergy(REG_RENERGY_A,(INT32U*)_rMeter_Data_Buffer.dwReActEnergy);
            break;
        default:
            break;
    }

    return(fgRet); 	    
}

BOOL fgMeter_GetEnergy(void)
{
    BOOL fgRet = TRUE;
    INT8U ii;

    for(ii = 0;ii < READ_ENERGY_MAX;ii++)
    {
        FeedWatchdog();	                
        CheckPowerDown();

        if(!fgMeter_GetSubEnergy(ii))
        {
            fgRet = FALSE;
        }
    }

    return(fgRet);
}

/*************************************************************
 Function:            BOOL fgMeter_GetAngle(void)
Description:          get angle
Input Parameter:    none
Output Parameter:  angle[]
Return:                 BOOL
Modify Time:          2011-05-20
Author:                 jie huang
*************************************************************/
BOOL fgMeter_GetAngle(void)
{    
    INT8U ii,jj;
    INT32U dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    _rMeter_Data_Buffer.dwUAngle[0] = 0;

    for(ii = 0;ii < 2;ii++)
    {        
        for(jj = 0;jj < 3;jj++)
        {  
            if(ReadAndCheck_TDK71M6515(REG_ANGLE_UAB + ii,(INT32U *)&dwTemp))
            { 
                if(dwTemp < 0x80000000)
                {
                    _rMeter_Data_Buffer.dwUAngle[ii + 1] = dwTemp;
                    break; 
                }
            }	   	 	 	 
        }

        if(jj == 3)  //read 3 times still error, return false
        {
            return(FALSE);
        }
    }

    return(TRUE);
}

/*************************************************************
 Function:            BOOL fgMeter_GetTemp(void)
Description:          get temperature
Input Parameter:    none
Output Parameter:  none
Return:                 BOOL
Modify Time:          2011-05-19
Author:                 jie huang
*************************************************************/
BOOL fgMeter_GetTemp(void)
{
    INT8U jj;
    INT32U dwTemp;

    FeedWatchdog();	                
    CheckPowerDown();

    for(jj = 0;jj < 3;jj++)
    {
        if(ReadAndCheck_TDK71M6515(REG_TEMP,(INT32U*)&dwTemp))
        {
            if(dwTemp & 0x80000000)
            {
                dwTemp = 0x100000000 - dwTemp;
                _rMeter_Data_Buffer.lTemp = -((INT32S)dwTemp);
            }
            else
            {
                _rMeter_Data_Buffer.lTemp = (INT32S)dwTemp;
            }

            break;
        }
    }

    if(jj == 3)  //read 3 times still error, return false
    {
        return(FALSE);
    }

    return(TRUE);
}

//****************************************************************
//Meter IC para check
//****************************************************************
BOOL fgMeter_ICParaOk(void)
{
    BOOL fgRet = FALSE;
    INT32U dwTemp;

    if(ReadAndCheck_TDK71M6515(REG_ADD_CHK,&dwTemp))
    {
        if(dwTemp == JustMeter_Parameter.stMeter_71M6545_Para_Val.Add_CHK)
        {
            fgRet = TRUE;
        }
    }

    if(!fgRet)
    {
        _wMeter_ICParaErrCnt++;
        if(_wMeter_ICParaErrCnt >= METER_IC_PARA_ERR_TIMES)
        {
            vMeter_Init(METER_RST_TYPE_PRAERR);
        }
    }
    else
    {
        _wMeter_ICParaErrCnt = 0;
    }

    return(fgRet);
}
 
