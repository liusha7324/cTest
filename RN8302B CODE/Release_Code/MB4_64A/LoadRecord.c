/*"MB3��ͨ�ð渺������ (VER 1.0 bata0406)										 "*/
/*"Created By Trend 2005-04-06 (�ںγ��Գ���������޸�) 		                 "*/
/*"Edit    By Trend 2005-07-11 (��MB3���������Э��ʱ�޸�) 		                    "*/
/*"Edit    By Trend 2009-01-11 (��MB3�����DL645-2007Э��ʱ�޸�) 		              "*/
/*"Edit    By Trend 2009-02-01 (��MB3����ӹ���Ҫ��ʱ�޸ģ������¼���ȸ�Ϊ������)"*/

#include "MB_BASE_FUN.h"
#include "eeprom.h"
#include "defdata.h"
#include "ram.h"
#include "sfr64a.h"
#include "LoadRecord.h"
#include "I2C_operation.h"
#include "eventnew.h"
#include "COMM.h"
#include "645_2007.h"
#include "Demand.h"
#include "datachange.h"
#include "Multi.h"
#include "initram.h" 

#define INVALID_LD_BLK  0xFFFF
#define  F_SIZE_LD      196  /*"֡��������ֽ���"*/
#define MAX_READ_TM_MS  500
#define USE_5MIN_IDX    1

#define IDX_PERIORD      5
#define HOUR_PER_SECTOR  42 /*" 5������������ֻ��1024�ֽڣ��ɷ�42Сʱ����,���0- 41"*/
#define IDX_SZ_PER_HOUR  (12*2)/*" һ��Сʱ��12�����������0 - 11"*/

#define FST_5MIN_IDX_ADDR 0x300000UL
#define FST_5MIN_IDX_SECT (FST_5MIN_IDX_ADDR/4096)



#define CS p0_0  //p9_4
#define RDY p10_0

/*FLASH OPER ID*/
#define WRITE_ENABLE_ID             0x06  
#define WRITE_DISABLE_ID            0x04 
#define READ_STATUS_REGISTER_ID     0x05  
#define WRITE_STATUS_REGISTER_ID    0x01 
#define CHIP_ERASE_ID               0x60  
#define SECTOR_ERASE_ID             0x20  
#define READ_DATA_ID                0x03  
#define WRITE_PAGE_ID               0x02  
#define READ_MANUFACTURER_AND_DEVICE_ID  0x9F  
/*END FLASH OPER ID*/


//#define BLOCK_LENGTH 33
#define RECORD_LENGTH 131
#define BYTE_LENGTH 528
//#define PAGE_LENGTH 4096
#define RECORD_FIRST_PAGE 56
#define SORT_START_PAGE 50
#define R_DelayTime      300000 /*"3������û���ܵ���ȷ�ֽڣ���ʼ������"*/
#define CO_C_START 400
//---------------------------------------------------------------------------
//----------------------fuxf add 100421--------------------------------------------
#define BLOCK_LENGTH 32/*"ÿ��32�ֽ�"*/
#define SECTOR_PAGE_NUM 128/*"ÿ������128����"*/
#define PAGE_LENGTH 256/*"ÿҳ256�ֽ�"*/
#define SECTOR_LENGTH 512/*"һ��512����"*/
#define RECORD_FIRST_SECTOR 0x00014000/*"��������20������ʼ"*/
#define RECORD_END_SECTOR   0x001FFFFF/*"�������������"*/

#define MAX_BLOCK_NUM        62976/*"ÿ��32�ֽ�"*/
#define DATA_NUM_SECTOR      492/*"data����"*/
#define INDEX_NUM_SECTOR     20/*"20��������"*/
//---------------------fuxf add end 100421---------------------------------------------
//---------------------------------------------------------------------------

extern unsigned char My_Memcmp(unsigned char *,unsigned char *,unsigned char);
extern void Byte2BCD(unsigned char src_data, unsigned char *dest_data);
//---------------------------------------------------------------------------
//public funtion
int WriteBuffer(unsigned int rStartAddr, unsigned int rLength, unsigned char *rData);
void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag,struct DATA_TIME *rDate);
int SwitchPage(void);
int ReadData_To_Cob(unsigned int  *rPageAddr,unsigned char kind);//liuyq added 2009-9-1
void ReadBuffer(unsigned int rStartAddr, unsigned int rLen,unsigned char * rData);
int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
int SaveBuffer(unsigned int rPageAddress);
int LoadToBuffer(unsigned int rPageAddress);
unsigned char GetRecordLength(const unsigned char rMode);
int InitSIO4(void);
int FindRecord(struct DATA_TIME *rDate, unsigned int *rpage,unsigned char sort);
int SaveIndex(struct DATA_TIME *rDate);
int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx);
int InitLoadRecord(void);
void First_InitLoadRecord(void);

void Minute_Power(char channel);
void Write_Enable(void);
void Write_Disable(void);
unsigned char Read_Status_Register(void);
unsigned char Write_Status_Register(unsigned char status);
void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);
int  Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
unsigned char Continuously_Program(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
int  Chip_Erase(void);
int  Sector_Erase(unsigned long FlashAddr);
int  Check_Sector_Have_Erased(unsigned long Faddr);
int  Get_Physicaladdress_From_Block(unsigned int block,unsigned long *addr);
int  Get_Block_From_PhysicalAddress(unsigned int* block,unsigned long addr);

//---------------------------------------------------------------------------
//private funtion
int Find_Next_Record(int channel,unsigned int *rblock, unsigned char sort);
int Find_Last_Record(int channel,unsigned int *rPage);
int Find_First_Record(unsigned int *rblock,unsigned char sort);
int Find_Near_Record(unsigned int *rblock,unsigned char sort);
int Find_Addr_Record(unsigned int *rPage, unsigned int *rByte, int addr);
int Find_Data_Record(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort);

int Get_Next_Record_Addr(unsigned int Page,unsigned int *rPage,unsigned char sort);
unsigned char Add_Addr( signed int num,unsigned int *rPage);
void Change_SortAddr(unsigned char rSaveFlag,unsigned int rPage);
int Get_SortAddr(unsigned int Page,unsigned int *rPage,unsigned char sort);
int Get_SortAddr1(unsigned int Page,unsigned int *rPage,unsigned char sort);
int Get_TotalAddr(unsigned int Page,unsigned int *rPage);
unsigned char Page_equal(unsigned int Page,unsigned int *rPage,unsigned char sort);
unsigned char Cover_Addr_Find(unsigned int nPage,unsigned int *rPage);
void Save_SortIndex(unsigned char rSaveFlag,unsigned int rblock);
int SaveLoadRecord(void);

extern void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len);
extern unsigned char Card_WR_Buff[512];


void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4);
void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
void ConverseString(unsigned char *p,unsigned char n);


void SaveDayIndex(struct DATA_TIME *rDate);
int ThisDayHaveRecord(struct DATA_TIME *rDate);
void AddOneDay(struct DATA_TIME *rDate);
void AddOneHour(struct DATA_TIME *rDate);
int Find_Data_Record_New(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort,unsigned char kind);

//---------------------------------------------------------------------------
//public variable
//struct LOADRECORD LoadRecord;
struct MINUTE_POWER_DATA Minute_Power_Data;
unsigned char Read_Count[3];
unsigned char Fs_Buff[528];        /*"Added by dhy for File_System 081201"*/
unsigned char Dat_Num;
struct DATA_TIME  Set_LoadRecoed_Btime;

struct LOADRECORD_NEW LoadRecord;
unsigned char First_Sort[6];
union FLASH_ERR_STATUS_FLAG  FlashErrStatus;
unsigned long FlashEaseTimes=0;


unsigned char user_req_pnt;

const unsigned char BIT_UNC[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
#pragma SECTION rom UserROMData
const unsigned int day_num[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
	
/*=========================MX25l3208d=======================================*/
void Write_Data(unsigned char wdata)
{
	s4trr = wdata;
	while((s4ic & 0x08) == 0);
	s4ic &= 0xF7;
}
void Read_Data(unsigned char *rdata)
{
    s4trr = 0xFF;
	while((s4ic & 0x08) == 0);
    *rdata=s4trr;
	s4ic &= 0xF7;
}
void Write_Command(unsigned char command)
{
	//make CS low to start transmission
	CS = 0;
	//command code
	s4trr = command;
	while((s4ic & 0x08) == 0);
	s4ic &= 0xF7;
	CS = 1;
}
/*"дʹ��"*/
void Write_Enable(void)
{
	union BYTE_BIT state;
    unsigned int Ndelay=0;

	Write_Command(WRITE_ENABLE_ID);
    do
	{
		state.byte=Read_Status_Register();
		FeedWatchdog();
        Ndelay++;
	}while((!state.bit.b1)&&(Ndelay<1000));

}
/*"ȡ��дʹ��"*/
void Write_Disable(void)
{
    union BYTE_BIT state;
    unsigned int Ndelay=0;

	Write_Command(WRITE_DISABLE_ID);
    do
	{
		state.byte=Read_Status_Register();
		FeedWatchdog();
        Ndelay++;
	}while((state.bit.b1)&&(Ndelay<1000));
}
/*"��״̬�Ĵ���"*/
unsigned char Read_Status_Register(void)
{
	unsigned char RDSR;

    CS=0;
    Write_Data(READ_STATUS_REGISTER_ID);	
    Read_Data(&RDSR);
	CS=1;
	return RDSR;
}

//#pragma SECTION program ROM_PRG2

unsigned char Write_Status_Register(unsigned char status)
{
	unsigned int unc=0;

    Write_Enable();    
	CS=0;    
    Write_Data(WRITE_STATUS_REGISTER_ID);
    Write_Data(status);
    CS=1;
    Write_Disable();
    return 1;
}
/*"������"*/
void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen)
{
	union FlashAddr32M addrUnion;
	unsigned int i;

    if((rlen==0)||(rlen>512))
    {
      return ;
    }
	//make CS low to start transmission
	CS = 0;

	//comand code 
    Write_Data(READ_DATA_ID);
	
	addrUnion.addr= FlashAddr;
	//byte2 of address    
	Write_Data(addrUnion.AsByte.Byte2);
	//byte1 of address
	Write_Data(addrUnion.AsByte.Byte1);
	//byte0 of address
	Write_Data(addrUnion.AsByte.Byte0);
	//recieve data
	for(i=0; i<rlen; i++)
	{   
        Read_Data(&RcvBuff[i]);
	}	

    //make CS high to stop transmission
	CS = 1;
}

/*"ҳд"*/
int Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen)
{
	union FlashAddr32M addrUnion;
	unsigned int i;
	union BYTE_BIT state;
	unsigned char unc=0;
    unsigned int Ndelay=0;

    addrUnion.addr=FlashAddr;
    if(((addrUnion.AsByte.Byte0+tlen)>256)||(tlen==0))
    {
      return -1;
    }
	Write_Enable();

    //make CS low to start transmission
	CS = 0;
    
	//comand code
    Write_Data(WRITE_PAGE_ID);
	
	addrUnion.addr= FlashAddr;
	//byte2 of address 
    Write_Data(addrUnion.AsByte.Byte2);
	//byte1 of address
    Write_Data(addrUnion.AsByte.Byte1);
	//byte0 of address
    Write_Data(addrUnion.AsByte.Byte0);

	//tx data
	for(i=0; i<tlen; i++)
	{    
        Write_Data(WriteBuff[i]);
	}	
	//make CS high to stop transmission
	CS = 1;    
    Delay(1);

	do
	{
		state.byte=Read_Status_Register();
        Ndelay++;
        FeedWatchdog();
	}while((state.bit.b0)&&(Ndelay<=50000));

    //protect
    Write_Disable();
    
    if(Ndelay<50000)
        return 0;
    else
        return -1;
}
/*unsigned char Continuously_Program(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen)
{
	union FlashAddr32M addrUnion;
	unsigned int i;
	union BYTE_BIT state;
	unsigned char unc=0;

    if((tlen==0)||(tlen%2!=0))
    {
      	return -1;
    }
	//make CS low to start transmission
	Write_Enable();

	CS = 0;

	//comand code
    Write_Data(0xAD);
	
	addrUnion.addr= FlashAddr;
	//byte2 of address
    Write_Data(addrUnion.AsByte.Byte2);
	//byte1 of address
    Write_Data(addrUnion.AsByte.Byte1);
	//byte0 of address
    Write_Data(addrUnion.AsByte.Byte0);

    //byte0
    Write_Data(WriteBuff[0]);
	//byte1
	Write_Data(WriteBuff[1]);

	CS=1;
    for(unc=0;unc<50;unc++);
	//tx data
	for(i=1; i<(tlen>>1); i++)
	{
		CS=0;
        Write_Data(0xAD);
		//data
        Write_Data(WriteBuff[2*i]);
		//data
        Write_Data(WriteBuff[2*i+1]);
		CS=1;
	    for(unc=0;unc<50;unc++);
	}	
	//make CS high to stop transmission
	CS = 1;

	Write_Disable();
    do
	{    
	    i++;
		state.byte=Read_Status_Register();
		FeedWatchdog();
	}while(state.bit.b0&&i<5000);
    
	return 1;
} */
/*"******************************************************************************************************
                                  *"����: Chip_Erase  "*
                                  *"����: FLASHƬ���� "*  
                                  * "����ֵ:0:��д�ɹ�"*
                                  *"-1:��дʧ��       "*
******************************************************************************************************"*/
int Chip_Erase(void)
{
	union BYTE_BIT state;
    unsigned long Ndelay=0;

	Write_Enable();

    CS=0;
    Write_Data(CHIP_ERASE_ID);
	CS=1;
    
    Delay(5);
	do
	{
		state.byte=Read_Status_Register();
        Delay(1);
        Ndelay++;
        CheckPowerDown();
	}while((state.bit.b0)&&(Ndelay<=100000L));

    Write_Disable();

    if(Ndelay<100000L)
        return 0;
    else
        return -1;
    
}
/*"******************************************************************************************************
                                  *"����: Sector_Erase  "*
                                  *"����: FLASH�������� "*  
                                  * "����ֵ:0:��д�ɹ�"*
                                  *"-1:��дʧ��       "*
******************************************************************************************************"*/
int Sector_Erase(unsigned long FlashAddr)
{
	union FlashAddr32M addrUnion;
	union BYTE_BIT state;
    unsigned long Ndelay=0;

	Write_Enable();	
	
	CS=0;
    Write_Data(SECTOR_ERASE_ID);

	addrUnion.addr= FlashAddr;
	//byte2 of address
	//byte2 of address 
    Write_Data(addrUnion.AsByte.Byte2);
	//byte1 of address
    Write_Data(addrUnion.AsByte.Byte1);
	//byte0 of address
    Write_Data(addrUnion.AsByte.Byte0);
	CS=1;
    
    Delay(5);
	do
	{
		state.byte=Read_Status_Register();
        Delay(1);
        Ndelay++;
        CheckPowerDown();/*"�ڲ�д�����е������͹���"*/
        
    }while((state.bit.b0)&&(Ndelay<=500));

    Write_Disable();

    FlashEaseTimes++;
    
    if(Ndelay<500)
        return 0;
    else
        return -1;

}
/*"********************************************************************
������:unsigned int ReadID(void) ��FLASH ID
����ֵ:(unsigned char)*ManufacturerID ȡ�õĹ���ID��ַ��
                   (unsigned char)*DeviceID     ȡ�õ��豸ID��ַ
********************************************************************"*/
void ReadID(unsigned char *ManufacturerID,unsigned char*DeviceID)
{
    unsigned int unc;

    CS=0;

    for(unc=0;unc<255;unc++);
    Write_Data(READ_MANUFACTURER_AND_DEVICE_ID);
    Read_Data(ManufacturerID);
    Read_Data(DeviceID);

    CS=1;
}
/*=====================End MX25l3208d=======================================*/

/*"============================================================"*/
/*"��������ReadBuffCob"*/
/*"��;����һ���������߼�¼���ݴ���Co.b"*/
/*"���أ�1:���ش���
         0:��ȷ"*/
/*"��    �ߣ�Fuxf  �汾��1.00  ʱ��:10-04-18"*/
/*"============================================================"*/
//#pragma SECTION program ROM_PRG2
int ReadData_To_Cob(unsigned int* rblockAddr,unsigned char kind)
{
     unsigned char i,tmp,nLength;     
     unsigned int  nblock,mmblock;
     union FlashAddr32M FlashAddr;
     struct DATEANDTIME_DEF   recordtime;

     nblock=*rblockAddr;  
     
     if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddr.addr))
         return -1;

     /*"first block"*/
     nLength = (kind >= 2)?7:BLOCK_LENGTH;
     Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&Co.b[0],nLength); 
     DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&recordtime);
     recordtime.Sec=0;
     if((Co.b[0]!=0xaa)||(Co.b[1]>4)||(Co.b[1]==0)||(!CheckTime((unsigned char*)&recordtime.Year)))
		return -1;
     
     mmblock=nblock+Co.b[1];
     
     if(kind==0 || kind == 3)/*"ֻ��Ҫȡ�ü�¼�ĵ�һ����"*/
        return 0;

    /*"Get Other Block Data"*/
    if(kind==1)/*"ֻ��Ҫȡ���Ӹÿ鿪ʼ��һ����¼����"*/
    {
        tmp=BLOCK_LENGTH;
        nblock++;
        for(i=1;i<Co.b[1];i++)
        {
              if(nblock>=MAX_BLOCK_NUM)
              {   /*"��ת"*/           
                 nblock=0;
                 FlashAddr.addr=RECORD_FIRST_SECTOR;
              }
             
              if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddr.addr))
                return -1;
              Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&Co.b[tmp],BLOCK_LENGTH);
              tmp+=BLOCK_LENGTH;
              nblock++;
        }
        return 1;
    }
    /*Get Next Block NUMBER*/
    if(mmblock>=MAX_BLOCK_NUM)
    {
        //mmblock=0;
        mmblock = mmblock % MAX_BLOCK_NUM;
    }    
   
    *rblockAddr=mmblock;
    FeedWatchdog();
	return 2;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
unsigned char NeedToRecord(struct DATA_TIME *rTime)
{
	unsigned char mask;
	unsigned char i;
	unsigned char flag;
	unsigned int timeCounter;
	unsigned char temp;

	mask = 0x01;
	flag = 0;

	if(Meter_Parameter.parameter2.LoadRecordMode.byte==0)
	{
		return 0;
	}
	

	BCD2Byte(rTime->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(rTime->Min, &temp);
	timeCounter += temp;
	
	for(i=0; i<6; i++)
	{
		//if((mask & 0x3F) != 0)//liuyq delete 2009-8-28
		{
			if(timeCounter % Meter_Parameter.parameter2.LoadRecordPeriod[i] == 0)
				flag |= mask;
		}
		mask <<= 1;
	}
    
	return (Meter_Parameter.parameter2.LoadRecordMode.byte & flag);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ComposeRecord1(struct RECORD1 *rRecord)
{	
	unsigned int i;
	unsigned char* p;
    /*" ��ѹ/����/Ƶ�ʣ�"*/	
	p = (unsigned char*)&rRecord->VA[0];
	for(i=0; i<3; i++)
	{
		FormatBCD(Volt[i]/100, p, 3);
		p +=  3;
	}
	/*"������ABC�������ÿ��3�ֽڣ���9�ֽ�,��λ��0.001A��"*/
 	for(i=0; i<3; i++)
	{
		data_change((unsigned char *)&COMM_Curr[i],p,SIGNED_LONG,BCD3BYTE,0,0,-4,-3);		
		p +=  3;
	}
    
	/*"Ƶ�ʣ�       A�ࣨ2�ֽ�,��λ��0.01Hz��"*/
	FormatBCD(Freq[0]/10000, rRecord->Freq, 2);/*"ԭʼ����Ϊ��ȷ��0.000001HZ,4byte������ֻ��Ҫ��ȷ��0.01v,2byte"*/
			
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ComposeRecord2(struct RECORD2 *rRecord)
{
      /*"���޹����ʣ�"*/	
      unsigned char i;
      union byte_def temp_byte;
      unsigned char * pointer1;
      unsigned char* pointer2;
      unsigned char* SourceDP[4] = {0};      
	
	  /*"�޹������־�ֽڣ�1�ֽڣ�0-3λΪ�ܡ�a��b��cԪ������4�ֽ�Ϊ0��"*/
      temp_byte.bit.b0=Meter_States.Meter_Status2.bit.ActiveDirection_T;
      temp_byte.bit.b1=Meter_States.Meter_Status2.bit.ActiveDirection_A;
      temp_byte.bit.b2=Meter_States.Meter_Status2.bit.ActiveDirection_B;
      temp_byte.bit.b3=Meter_States.Meter_Status2.bit.ActiveDirection_C;
      rRecord->ActiveFlag=temp_byte.byte&0x0f;
      temp_byte.bit.b4=Meter_States.Meter_Status2.bit.ReactiveDirection_T;
      temp_byte.bit.b5=Meter_States.Meter_Status2.bit.ReactiveDirection_A;
      temp_byte.bit.b6=Meter_States.Meter_Status2.bit.ReactiveDirection_B;
      temp_byte.bit.b7=Meter_States.Meter_Status2.bit.ReactiveDirection_C;
      rRecord->ReactiveFlag=temp_byte.byte>>4;

      pointer1 = (unsigned char*)&Minute_Power_Data.Active_power_last_data[0];
      for(i=0;i<8;i++)
      {
            if(temp_byte.byte&(1<<i))
                  *((signed long*)pointer1) = 0 - (*((signed long*)pointer1));
            if(i==0)
                  pointer2 = rRecord->PAll;
            else if(i==4)
                   pointer2 = rRecord->RAll;
            else
                   pointer2 = rRecord->PA + (i-1)*3;
           data_change(pointer1,pointer2,SIGNED_LONG,BCD3BYTE,0,0,-6,-4);
            pointer1+=4;
      }
      for(i=0; i<4; i++)
      {
            if(!i)
                   pointer2 = rRecord->SALL;
            else
                   pointer2 = rRecord->SA + (i-1)*3;
            FormatBCD(Visual_power[i]/100, pointer2, 3);
      }
      return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ComposeRecord3(struct RECORD3 *rRecord)
{
    /*"����������"*/
    int i;
	unsigned char* p;

	p = &rRecord->Factor[0];
	for(i=0; i<4; i++)
	{
		data_change((unsigned char *)&COMM_Factor[i],p,SIGNED_LONG,BCD2BYTE,0,0,-6,-3);
		p += 2;
	}
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ComposeRecord4(struct RECORD4 *rRecord)
{
	rRecord->PP=This_Month_Data.Energy_Record.Plus_Active[0];
	rRecord->NP=This_Month_Data.Energy_Record.Nega_Active[0];	
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ComposeRecord5(struct RECORD5 *rRecord)
{
	rRecord->Quad1=This_Month_Data.Energy_Record.Quad_Reactive[0][0];
	rRecord->Quad2=This_Month_Data.Energy_Record.Quad_Reactive[1][0];
	rRecord->Quad3=This_Month_Data.Energy_Record.Quad_Reactive[2][0];
	rRecord->Quad4=This_Month_Data.Energy_Record.Quad_Reactive[3][0];
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern unsigned long  Last_Average_Value[8][MAXTRIFF];  //add by trend 2008-12-25 13:09:40

int ComposeRecord6(struct RECORD6 *rRecord)
{
	unsigned long l_temp;
    /*"��ǰ������"*/
	data_change((unsigned char *)&Current_Demand[0],rRecord->DemandActive,SIGNED_LONG,BCD3BYTE,0,0,-6,-4);	

    /*"�޹�������3�ֽ�,��λ��0.1var��"*/
	data_change((unsigned char *)&Current_Demand[1],rRecord->DemandReactive,SIGNED_LONG,BCD3BYTE,0,0,-6,-4);	
	return 0;
}
/*"============================================================"*/
/*"��������Check_Show_FlashData"*/
/*"���Ҹ���BLOCK�ŵ������ַ"*/
/*"������block:  ��ţ�
         addr:ʵ�ʵ�ַ"*/
/*"���أ�0:������Χ"*/
/*"��    �ߣ�Fuxf �汾��1.00"*/
/*"============================================================"*/
int Get_Physicaladdress_From_Block(unsigned int block,unsigned long *addr)
{
    union FlashAddr32M FlashAddr;

    if(block>MAX_BLOCK_NUM)
        return 0;

    /*get sector addr*/
    FlashAddr.addr=RECORD_FIRST_SECTOR;
    FlashAddr.SectorAddr.Saddr+=block/SECTOR_PAGE_NUM;
    /*get block addr*/
    FlashAddr.SectorAddr.Sdummy=(block%SECTOR_PAGE_NUM)*BLOCK_LENGTH;

    *addr=FlashAddr.addr;    
    return 1;
}
/*"============================================================"*/
/*"��������Get_Block_From_PhysicalAddress"*/
/*"���Ҹ����������ַBLOCK��"*/
/*"������block:  ��ţ�
         addr:ʵ�ʵ�ַ"*/
/*"���أ�0:������Χ"*/
/*"��    �ߣ�Fuxf  �汾��1.00"*/
/*"============================================================"*/
int Get_Block_From_PhysicalAddress(unsigned int* block,unsigned long addr)
{
    union FlashAddr32M FlashAddr;
    unsigned int nnblock;

    FlashAddr.addr=addr;
    if((FlashAddr.addr<RECORD_FIRST_SECTOR)||(FlashAddr.addr>RECORD_END_SECTOR)||((FlashAddr.addr%BLOCK_LENGTH)!=0))
        return -1;

    FlashAddr.addr-=RECORD_FIRST_SECTOR;
    nnblock=FlashAddr.SectorAddr.Saddr;
    nnblock*=SECTOR_PAGE_NUM;
    nnblock+=FlashAddr.SectorAddr.Sdummy/BLOCK_LENGTH;

    if(nnblock>MAX_BLOCK_NUM)
        return -1;
    
    *block=nnblock;
    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"��������������,ÿ���ӵ���һ��"*/
int SaveLoadRecord(void)
{
	unsigned char nSaveFlag; //load record save flag ,bit0-bit5 as type1-type6 
	unsigned char *nRecord;
	unsigned char nLength; //length of record
	unsigned int nPage;//page address
	unsigned int nByte;//byte address
	signed int ret;
	unsigned char tmp;
	unsigned char nHour;//hour tag of record
	unsigned char nMinute;//minute tag of record
	struct DATA_TIME nDate;
    unsigned int oldblock,nblock,needsave;//block address
	unsigned int i;
	unsigned char nNeedSaveIndex;//=1 need; =0 needn't
    union FlashAddr32M FlashAddre;

	
	/*"ʱ������"*/
	nDate.Year = softdate.Year;
	nDate.Month = softdate.Month;
	nDate.Day = softdate.Day;
	nDate.Hour = softdate.Hour;
	nDate.Min = softdate.Min;
       
    //WRLC256(LOADRECORD_BEGIN_TIME_ROM,(unsigned char *)&Set_LoadRecoed_Btime,5,3,1);
    ret=CompareBytes((unsigned char *)&Meter_Parameter.parameter2.LoadRecoedBeginTime,(unsigned char *)&nDate, 5);
    if(ret==1)   /*"����������ʼ��¼ʱ�仹δ��"*/
        return 0;

	/*"�ж��Ƿ���Ҫ���渺�����ߣ�����Ҫ�����ļ�������"*/
	nSaveFlag = NeedToRecord(&nDate);
	if(nSaveFlag==0)
		return 0;
	
	ret=CompareBytes((unsigned char *)&LoadRecord.LastRecordTime,(unsigned char *)&nDate, 5);
	/*"�趨��ǰ�������߼�¼�ı���λ��"*/
	if(ret >= 0)
	{   //if current == last record time, relocate current record
		if(nDate.Min == 0)
		{
			LoadRecord.LoadRecordFlag.NeedSaveIndex = 1;/*"�ñ�־����Ҫ��������"*/
		}
        /*"�޸�ʱ�䵽�����֮ǰ"*/
        Find_First_Record(&oldblock,0);
        ReadData_To_Cob(&oldblock,0);
        if(CompDateTime4ByteAnd5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&nDate)>0)
        {
           First_InitLoadRecord();
        }
	}
    
	oldblock = LoadRecord.BlockAddress;
	//LoadRecord.BlockAddress = oldblock;
    
	/*"���ɸ������߼�¼"*/
	nRecord = (unsigned char *)&Co.b[2];
	Co.b[0]=0xAA;
	nLength=ComposeRecord(nRecord,nSaveFlag,&nDate);	
	nLength+=2;
	if(nLength%BLOCK_LENGTH==0)                       
		Co.b[1]=nLength/BLOCK_LENGTH;
	else
		Co.b[1]=nLength/BLOCK_LENGTH+1;

    /*"����"*/
    nblock=oldblock;    
    tmp=0;
    needsave=0xffff;
    for(i=0;i<Co.b[1];i++)
    {
        if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddre.addr))
            return -1;

        if(FlashAddre.SectorAddr.Sdummy==0)
        {   /*"������"*/  
            if(FlashAddre.addr>RECORD_END_SECTOR)/*"�õ����һ������,��ת����"*/
            {
                nblock=0;
                FlashAddre.addr=RECORD_FIRST_SECTOR;
            }
            if((FlashAddre.addr==RECORD_FIRST_SECTOR)&&(LoadRecord.LastBlockAddress!=0))
            {
                LoadRecord.LoadRecordFlag.reStart=1;/*"�Ѿ����ǵ�һҳ��־"*/
                WRLC256(LOADRECORDFLAG_ROM,(unsigned char*)&LoadRecord.LoadRecordFlag,LOADRECORDFLAGLEN,0,0);
            }
            Sector_Erase(FlashAddre.addr);
            needsave=nblock;
        }
        Write_Page(FlashAddre.addr,&Co.b[tmp],BLOCK_LENGTH);
        tmp+=BLOCK_LENGTH;
        nblock++;
    }
  
    Change_SortAddr(nSaveFlag,oldblock);
		
	/*"�ж��Ƿ���Ҫ����Сʱ����"*/
	if((nDate.Year != LoadRecord.LastRecordTime.Year)
        || (nDate.Month != LoadRecord.LastRecordTime.Month)
		|| (nDate.Day != LoadRecord.LastRecordTime.Day)
		|| (nDate.Hour != LoadRecord.LastRecordTime.Hour))
	{
		LoadRecord.LoadRecordFlag.NeedSaveIndex = 1;
	}

    LoadRecord.LastBlockAddress     = oldblock;
    if(nblock>=MAX_BLOCK_NUM)
    {
        nblock=0;
    }
#if USE_5MIN_IDX
    if ( (My_Memcmp(&nDate.Year, &LoadRecord.LastRecordTime.Year, 4) != 0) 
        || ((OB_H(nDate.Min)/5) != (OB_H(LoadRecord.LastRecordTime.Min)/5)))
    {
        Save_5Min_Index(&nDate);
    }
#endif
    LoadRecord.BlockAddress         = nblock;
    LoadRecord.LastRecordTime       = nDate;
    LoadRecord.LastRecordTime.Sec   = 0;


	/*"��������"*/
	if(LoadRecord.LoadRecordFlag.NeedSaveIndex == 1)
	{
        LoadRecord.LoadRecordFlag.NeedSaveIndex = 0;
        SaveDayIndex(&nDate);
#if (USE_5MIN_IDX == 0)
		if(SaveIndex(&nDate) == 0)
		{
            ;
		}
#endif
	}

  Save_SortIndex(nSaveFlag,needsave);
    
	LoadRecord.LoadRecordPointer++;
  i=BLOCKADDRESS_ROM;
  if(LoadRecord.LoadRecordPointer%2==1)
    i=BAKBLOCKADDRESS_ROM;
	WRLC256(i,(unsigned char*)&LoadRecord,BLOCKADDRESSLEN,0,0);
	
	return 0;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag, 
	struct DATA_TIME *rDate)
{
	unsigned char mask;
	unsigned char ind;
	unsigned char sum;
	unsigned char i;
	
	//Compose record header
	DateTimeNoSec5ByteTo4Byte((struct DATE_TIMENOSEC_5BYTE *)rDate,(union DATE_TIMENOSEC_4BYTE *)&rBuffer[0]);/*"ʱ��"*/


	rBuffer[4] = rSaveFlag;//Meter_Parameter.LoadRecordMode.byte;
								/*"ÿ����¼��ģʽ�֣���ʾ����ʱ������Ҫ���Ǽ������ݣ�"*/
								/*"b0=1�����1��"*/
								/*"b1=1�����2��"*/
								/*"b2=1�����3��"*/
								/*"b3=1�����4��"*/
								/*"b4=1�����5��"*/
								/*"b5=1�����6��"*/
                                
	//Compose record body
	//rSaveFlag=0x3f;	/*"6������ȫ����"*/
		
	mask = 0x01;
	ind =5;
	while(mask < 0x40)
	{
		if((mask & rSaveFlag) != 0)
		{
			switch(mask)
			{
				case 0x01:
					ComposeRecord1((struct RECORD1*)&rBuffer[ind]);
					ind += sizeof(struct RECORD1);
					break;
				case 0x02:
					ComposeRecord2((struct RECORD2*)&rBuffer[ind]);
					ind += sizeof(struct RECORD2);
					break;
				case 0x04:
					ComposeRecord3((struct RECORD3*)&rBuffer[ind]);
					ind += sizeof(struct RECORD3);
					break;
				case 0x08:
					ComposeRecord4((struct RECORD4*)&rBuffer[ind]);
					ind += sizeof(struct RECORD4);                         //16--32
					mask <<= 1;/*"��������4�����ݱ��뱣����࣬ʹ��mask <<= 1;�����ظ�"*/
				case 0x10:
					ComposeRecord5((struct RECORD5*)&rBuffer[ind]);
					ind += sizeof(struct RECORD5);                         //16--32
					break;
				default:
					ComposeRecord6((struct RECORD6*)&rBuffer[ind]);
					ind += sizeof(struct RECORD6);;
					break;
			}			
		}
		
		mask <<= 1;
	}

	/*"У��ͣ���ʱ���һ���ֽڿ�ʼ"*/
	sum = 0;
	for(i=0; i<ind; i++)
	{
		sum += rBuffer[i];
	}
	rBuffer[ind] = sum;	
	
	return ind+1;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma SECTION rom UserROMData
const unsigned char Clase_Length[6] = {6, 16, 8, 8, 42, 20};

unsigned char GetRecordLength(const unsigned char rMode)
{
	
	unsigned char nMask;
	unsigned char result=0;
	unsigned char i;
	
	result = 5;
	nMask=0x20;
	for(i=0; i<6; i++)
	{
		if((nMask & rMode) != 0)
		{
			result += Clase_Length[i];
		}
		nMask>>=1;
	}

    if((rMode&0x08)!=0&&(rMode&0x10)==0)
        result+=16;
	return result;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int InitSIO4(void)
{
	int result;
	unsigned char Status_Register;
    unsigned char ManufacturerID;
    unsigned char DeviceID;
	
	result = 0;
	
	prc2 = 1;
	s4c =0xE9;
	prc2 = 1;
	s4brg = 0x00;
	
	prc2 = 1;
	//pd9_4 = 1;	
	pd0_0 = 1;

    Status_Register=Read_Status_Register();
    if(Status_Register&0x0c)
    Write_Status_Register(0x00);

    ReadID(&ManufacturerID,&DeviceID);
    
	return result;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"�������������Ҽ�¼"*/
#if USE_5MIN_IDX
int FindRecord(struct DATA_TIME *rDate, unsigned int *rPage,unsigned char sort)
{
    int ret;
    unsigned int min_blk;
    unsigned int nReadPage;
    struct DATA_TIME req_tm;
    unsigned char min;

    memcpy(&req_tm.Year, &rDate->Year, 6);
    min = OB_H(req_tm.Min);
    min = (min/IDX_PERIORD) * IDX_PERIORD;
    nReadPage= INVALID_LD_BLK;
    while (min < 60)
    {
        ret = get_5min_idx_by_time(&req_tm, &min_blk);
        if (ret == 0)
        {
            ret = find_record_in_cur_5min_frm_min_idx(sort, req_tm, 1, min_blk, &nReadPage);  
            if (ret == 0)
            {
                *rPage = nReadPage;
        	    return 0;
            }
        }

        min += IDX_PERIORD;
        req_tm.Min = OH_B(min);
    }
    return -1;
}
#else

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
unsigned char check_search_time(unsigned long base,unsigned long loc,unsigned long maxlim)
{
	signed long sl_temp;
	signed char ret;
	sl_temp=loc-base;
	sl_temp=ABS(sl_temp);
	if((sl_temp>=0)&&(sl_temp<maxlim)) 
		ret=0;
	else 	
		ret=0xff;
	return ret;
}

int FindRecord(struct DATA_TIME *rDate, unsigned int *rPage,unsigned char sort)
{
	int result;
	unsigned int nHoursTotal;
	unsigned char tmp;
	unsigned int nPage;
	unsigned int nByte;
	unsigned int uni;	
	struct DATA_TIME  Date,Date_temp;
	unsigned long l_time,lh_basc,req_time;
    unsigned int  nblock,getblock;
    union FlashAddr32M FlashAddr;	
	
	result = 0;
    /*
	nHoursTotal = 0;
	BCD2Byte(rDate->Month, &tmp);
	nHoursTotal += day_num[tmp-1] * 24;
	BCD2Byte(rDate->Day, &tmp);
	nHoursTotal += (tmp - 1) * 24;
	BCD2Byte(rDate->Hour, &tmp);
	nHoursTotal += tmp;	
	*/
    nHoursTotal = get_hour_in_year(rDate);
    /*"��������"*/
    FlashAddr.addr=0;
    FlashAddr.SectorAddr.Saddr =nHoursTotal/512;
    FlashAddr.SectorAddr.Sdummy=(nHoursTotal%512)*2L;
    Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&nblock,2);
	if(nblock>=MAX_BLOCK_NUM)/*"��������ȷ"*/
		return -1;

    getblock=nblock;
    if(ReadData_To_Cob((unsigned int*)&nblock,2)!=2)
		return -1;

	/*"��Сʱ�����ҵ��ĸ��ɼ�¼"*/
	DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
	Date.Sec=0;
    if(TimeToLong(Date,&l_time)!= 0)
		return -1;
    
	memcpy((unsigned char *)&Date_temp,(unsigned char *)rDate,4);/*"Сʱ0��"*/
	Date_temp.Min=0;
	Date_temp.Sec=0;
	if(TimeToLong(Date_temp,&lh_basc)!= 0)
		return -1;
    
	memcpy((unsigned char *)&Date_temp,(unsigned char *)rDate,5);/*"��Ҫ���ҵ�ʱ��"*/
	Date_temp.Sec=0;
	if(TimeToLong(Date_temp,&req_time)!= 0)
		return -1;			
	if(check_search_time(lh_basc,l_time,3600l)==0xff)
		return -2;		/*"����ʱ��������ƥ��"*/

	tmp=0xff;
    if(sort!=0)
        tmp=Co.b[6]&(0x01<<(sort-1));
    while((l_time<req_time)||(tmp==0))
    {
           FeedWatchdog();
           getblock=nblock;
           if(ReadData_To_Cob(&nblock,2)!=2)
			    return -1;

           if(sort!=0)
              tmp=Co.b[6]&(0x01<<(sort-1));
           if(l_time>=req_time&&tmp!=0)
           {
               *rPage=getblock;
               return 0;
           }		
           
           if((getblock>=LoadRecord.LastBlockAddress)&&(0==LoadRecord.LoadRecordFlag.reStart))
           {      
                if(sort!=0&&tmp==0)
                    return -1;
                else
                {
                    *rPage=getblock;
                    return 0;
                }
            }
		    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
		    Date.Sec=0;
		    if(TimeToLong(Date,&l_time)!= 0)
			     return -1;
            if(check_search_time(lh_basc,l_time,3600l)!=0)
			     return -2;		/*"����ʱ����������"*/              
      }
	
      *rPage = getblock;
	  return 0;
}
#endif



unsigned int get_hour_in_year(struct DATA_TIME *rDate)
{
    unsigned int nHoursTotal;
	unsigned char tmp;
    
    nHoursTotal = 0;
    BCD2Byte(rDate->Month, &tmp);
    nHoursTotal += day_num[tmp-1] * 24;
    BCD2Byte(rDate->Day, &tmp);
    nHoursTotal += (tmp - 1) * 24;
    BCD2Byte(rDate->Hour, &tmp);
    nHoursTotal += tmp;                     /*"��������"*/

    return nHoursTotal;
}

#if USE_5MIN_IDX
int Save_5Min_Index(struct DATA_TIME *rDate)
{
    unsigned int nHoursTotal;
	//unsigned char tmp;
	unsigned int nPage;
	unsigned int nByte;
    union FlashAddr32M FlashAddr, FlashAddrstart;
    
    unsigned char minute;
    //unsigned long nMinute;
    unsigned int hour_sec;
    unsigned int hour_addr;/*" ���Сʱ�������ڵ��׵�ַ"*/
    unsigned int min_addr;
    unsigned char part1;
    unsigned int nblock,mblock;

    nblock=LoadRecord.LastBlockAddress;
    
    nHoursTotal = get_hour_in_year(rDate);
    minute = OB_H(rDate->Min);
    //nMinute = nHoursTotal * 60 + minute;
    
    hour_sec = nHoursTotal / HOUR_PER_SECTOR;
    hour_addr = (nHoursTotal % HOUR_PER_SECTOR)*IDX_SZ_PER_HOUR;
    min_addr = hour_addr + (minute/IDX_PERIORD)*2;
    
    FlashAddr.SectorAddr.Saddr = FST_5MIN_IDX_SECT + hour_sec;
    FlashAddr.SectorAddr.Sdummy = min_addr;

    if(FlashAddr.SectorAddr.Sdummy==0)
    {   /*"������"*/          
        Sector_Erase(FlashAddr.addr); 
    }
    else
    {
        Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&mblock,2);
        if(mblock!=0xffff)
        {
            FlashAddrstart=FlashAddr;
            FlashAddrstart.SectorAddr.Sdummy=0;
            for(nByte=0;nByte<4;nByte++)
            {
                Read_Data_Bytes(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256);
                FlashAddrstart.addr+=256;
            }
            FeedWatchdog();
            CheckPowerDown();
            *((unsigned int*)&Co.b[FlashAddr.SectorAddr.Sdummy])=nblock;
            for(nByte=FlashAddr.SectorAddr.Sdummy+2;nByte<1024;nByte++)
                Co.b[nByte]=0xff;
            FlashAddrstart.SectorAddr.Sdummy=0;
            Sector_Erase(FlashAddr.addr); 
            for(nByte=0;nByte<4;nByte++)
            {
                if(Write_Page(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256)==-1)
                    return -1;
                FlashAddrstart.addr+=256;
            }   
            return 0;
        }          
    }
    
    if(Write_Page(FlashAddr.addr,(unsigned char*)&nblock,2)==0)
        return 0;
    else
        return -1;
}

int get_5min_idx_by_time(struct DATA_TIME *rDate, unsigned int *blk)
{
    unsigned int nHoursTotal;
	//unsigned char tmp;
	unsigned int nPage;
	unsigned int nByte;
    union FlashAddr32M FlashAddr, FlashAddrstart;
    
    unsigned char minute;
    //unsigned long nMinute;
    unsigned int hour_sec;
    unsigned int hour_addr;/*" ���Сʱ�������ڵ��׵�ַ"*/
    unsigned int min_addr;
    unsigned char part1;
    unsigned int nblock,mblock;

    nHoursTotal = get_hour_in_year(rDate);
    minute = OB_H(rDate->Min);
    //nMinute = nHoursTotal * 60 + minute;
    
    hour_sec = nHoursTotal / HOUR_PER_SECTOR;
    hour_addr = (nHoursTotal % HOUR_PER_SECTOR)*IDX_SZ_PER_HOUR;
    min_addr = hour_addr + (minute/IDX_PERIORD)*2;
    
    FlashAddr.SectorAddr.Saddr = FST_5MIN_IDX_SECT + hour_sec;
    FlashAddr.SectorAddr.Sdummy = min_addr;

    Read_Data_Bytes(FlashAddr.addr,(unsigned char*)blk,2);
    if(*blk >= MAX_BLOCK_NUM)
        return -1;
    else
        return 0;

}
#endif

#if (USE_5MIN_IDX == 0)

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int SaveIndex(struct DATA_TIME *rDate)
{
	unsigned int nHoursTotal;
	unsigned char tmp;
	unsigned int nPage;
	unsigned int nByte;
    unsigned int nblock,mblock;
    union FlashAddr32M FlashAddr,FlashAddrstart;

    nblock=LoadRecord.LastBlockAddress;

    /*
	nHoursTotal = 0;
	BCD2Byte(rDate->Month, &tmp);
	nHoursTotal += day_num[tmp-1] * 24;
	BCD2Byte(rDate->Day, &tmp);
	nHoursTotal += (tmp - 1) * 24;
	BCD2Byte(rDate->Hour, &tmp);
	nHoursTotal += tmp;
       */
    nHoursTotal = get_hour_in_year(rDate);

	//read index to find address of the first of this hour
    FlashAddr.addr=0;
    FlashAddr.SectorAddr.Saddr =nHoursTotal/512;
    FlashAddr.SectorAddr.Sdummy=(nHoursTotal%512)*2L;
	if((FlashAddr.addr<RECORD_FIRST_SECTOR)&&((FlashAddr.SectorAddr.Sdummy<1024)))/*"ÿ������ֻ��1K����"*/
	{
        if(FlashAddr.SectorAddr.Sdummy==0)
        {   /*"������"*/          
            Sector_Erase(FlashAddr.addr); 
        }
        else
        {/*"����Сʱ����"*/ 
            Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&mblock,2);
            if(mblock!=0xffff)
            {
                FlashAddrstart=FlashAddr;
                FlashAddrstart.SectorAddr.Sdummy=0;
                for(nByte=0;nByte<4;nByte++)
                {
                    Read_Data_Bytes(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256);
                    FlashAddrstart.addr+=256;
                }
                FeedWatchdog();
                CheckPowerDown();
                *((unsigned int*)&Co.b[FlashAddr.SectorAddr.Sdummy])=nblock;
                for(nByte=FlashAddr.SectorAddr.Sdummy+2;nByte<1024;nByte++)
                    Co.b[nByte]=0xff;
                FlashAddrstart.SectorAddr.Sdummy=0;
                Sector_Erase(FlashAddr.addr); 
                for(nByte=0;nByte<4;nByte++)
                {
                    if(Write_Page(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256)==-1)
                        return -1;
                    FlashAddrstart.addr+=256;
                }   
                return 0;
            }            
        }

        if(Write_Page(FlashAddr.addr,(unsigned char*)&nblock,2)==0)
           return 0;
    }   
    
    return -1;
    
}
#endif

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"ͨѶ�ӿں���"*/
int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx)
{
	unsigned char read_mode,Data_number,sum,read_class,read_addr;	
	unsigned int nReadPage;//page address
	unsigned int nReadByte;//byte address
	unsigned int Sort_Len;
	int ret,i;
	struct DATA_TIME Read_Data;
	volatile struct RECORD *pRecord;
	volatile	struct RECORD1 *Record1;
	volatile	struct RECORD2 *Record2;
	volatile	struct RECORD3 *Record3;
	volatile	struct RECORD4 *Record4;
	volatile	struct RECORD5 *Record5;
	volatile	struct RECORD6 *Record6;
	unsigned char *pBuf,*temp_buf;
	union byte_def mode_word;
	signed long Power_temp;
	unsigned char mask;
	
	//*total_len=0;
	
	if((LoadRecord.BlockAddress==0)&&(LoadRecord.LastBlockAddress==0))
	{
			return 0;
	}
	
	if (id.d[2] == 0x10)
	{
        return read_record_base_time_id(id, rCommand, rBuffer, mode, uartx);
	}
    
	/*"uartxͨ����"*/	
	read_mode=id.d[0];	/*"������ģʽ"*/
								/*"0x01������������"*/
								/*"0x03���ϴζ�������"*/
								/*"0x00������ʱ��"*/
								/*"0x02�������"*/
								/*"0x04���ϴζ���"*/
								/*"0x05��0��ַ"*/
	switch(id.d[2])
	{
		case 0:read_class=0x3f;break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:read_class= 1<<(id.d[2] -1);break;
		default: return 0;
	}
	if(mode==0)
	{				
		Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
		if(BCD2Byte(*(rCommand), &Read_Count[uartx])<0)
			return 0;/*"�����ݿ���"*/

        if(Read_Count[uartx]==0)
        {
            cx[3].readloadrecord=0;
            return 0;
        }

		switch(read_mode)
		{
			case 0x01:
				Read_Data.Sec = 0;
				Read_Data.Min=	*(rCommand+1);
				Read_Data.Hour=		*(rCommand+2);
				Read_Data.Day=		*(rCommand+3);
				Read_Data.Month=	*(rCommand+4);
				Read_Data.Year=		*(rCommand+5);
                if (CheckTime(&Read_Data.Year) == 0)
                {
                    cx[3].readloadrecord=0;/*" �����ᱨ��������"*/
                    return 0;
                }
				ret=Find_Data_Record_New(&nReadPage,&Read_Data,id.d[2],0);
				break;	
			case 0x03:
				ret=Find_Next_Record(uartx,&nReadPage,id.d[2]);
				break;	
			case 0x00:
				ret=Find_First_Record(&nReadPage,id.d[2]);
				break;	
			case 0x02:
				if(Read_Count[uartx]!=1)  { cx[3].readloadrecord=0; return 0;}
				ret=Find_Near_Record(&nReadPage,id.d[2]);			
				break;	
			case 0x04:
				ret=Find_Last_Record(uartx,&nReadPage);
				break;	
			case 0x05:
				ret=Find_Addr_Record(&nReadPage,&nReadByte,0);
				break;	
		}

		if(ret!=0) 
			return 0;
	}
	else
	{
		Data_number=*rCommand;
		if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)==Data_number)
		{/*"����Ŀ�ŵ�����һ֡�Ŀ��+1,������һ֡"*/
			if(Read_Count[uartx]!=0)
				ret=Find_Next_Record(uartx,&nReadPage,id.d[2]);		
			else
				return 0x8000;
			if(ret!=0) return 0x8000;
		}
		else if(Iterate_Tree_Flag[uartx].Back_Flame_Serial==Data_number)
		{/*"����Ŀ�ŵ�����һ֡�Ŀ��,�ط���һ֡"*/
			ret=Find_Last_Record(uartx,&nReadPage);
			if(ret!=0) return 0x8000;
				
		}
		else
		{
			return 0x8000;
		}
		
	}
	
	if(ReadData_To_Cob(&nReadPage,1)!=1)
	   return 0;	

	Sort_Len=Co.b[1]*BLOCK_LENGTH;
	if(Co.b[1]>4||Co.b[1]==0)
		return 0;
	if(id.d[2]!=0)
	{
		if((Co.b[6]&0x01<<id.d[2]-1)==0)
			return 0;
	}
    
  if(CompDateTime4ByteAnd5Byte((union DATE_TIMENOSEC_4BYTE*)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE*)&softdate)>0)
    return 0;
    
	LoadRecord.ReadHistory[uartx].Last_Read_BlockAddress=nReadPage;/*"���汾�ζ�ȡ��ҳ��ַ"*/  
  Dat_Num=GetRecordLength(Co.b[6]);
	/*"�Ƚ�У���"*/	
	sum = 0;
	for(i=0; i<Dat_Num; i++)
	{
		sum += Co.b[i+2];
	}
	if(sum!=Co.b[Dat_Num+2])/*"У��ʹ�"*/
	{
		pBuf=rBuffer;
		*(pBuf++)=0xE0;
		*(pBuf++)=0xE0;	
	}	
	else
	{
	
	
		pRecord=(struct RECORD *)&Co.b[2];
		
		pBuf=rBuffer;
		*(pBuf++)=0xA0;
		*(pBuf++)=0xA0;	
		pBuf++;/*"����������"*/
		
		DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)pBuf);
		ConverseString(pBuf,5);
		pBuf+=5;
		
		read_addr=2+sizeof(struct RECORD);
		mask = 0x01;
		while(mask < 0x40)
		{
			if((mask&pRecord->Mode_Byte  ) != 0)
			{
				switch(mask)
				{
					case 0x01:
						Record1=(struct RECORD1 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD1);
						if((mask&read_class) != 0)
						{
							temp_buf=(unsigned char *)&Record1->VA[0];
							for(i=0;i<3;i++)
							{
								*pBuf = temp_buf[i*3]>>4;
								*pBuf |= (temp_buf[i*3+1]<<4);
								pBuf++;
								*pBuf = temp_buf[i*3+1]>>4;
								*pBuf |= (temp_buf[i*3+2]<<4);
								pBuf++;
							}
							temp_buf+=9;
							memcpy(pBuf, temp_buf, 11);
							pBuf += 11;
						}
						break;
					case 0x02:
						Record2=(struct RECORD2 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD2);
						if((mask&read_class) != 0)
						{					
							for(i=0;i<24;i++)
							{
								if(i==0)
									temp_buf=(unsigned char *)&Record2->PAll[0];
								else if(i==3)
									temp_buf=(unsigned char *)&Record2->PA[0];
								else if(i==12)
									temp_buf=(unsigned char *)&Record2->RAll[0];
								else if(i==15)
									temp_buf=(unsigned char *)&Record2->RA[0];
								*pBuf=*temp_buf;
								pBuf++;	
								temp_buf++;
							}
						}
						break;
					case 0x04:
						Record3=(struct RECORD3 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD3);
						if((mask&read_class) != 0)
						{
							memcpy(pBuf,(unsigned char *)&Record3->Factor[0], 8);
							pBuf += 8;
						}
						break;
					case 0x08:
						Record4=(struct RECORD4 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD4);
						Record5=(struct RECORD5 *)&Co.b[read_addr];
						if((mask&read_class) != 0)
						{
							FormatBCD(format_data(Record4->PP,0)/(10),pBuf,4);							
							pBuf+=4;
							FormatBCD(format_data(Record4->NP,0)/(10),pBuf,4);							
							pBuf+=4;
							for(i=0;i<2;i++)
							{
								if(!i)
									sum = Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
								else
									sum = Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
								math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
													sum,SIGNED_LONG,4,4, RAM_MATH);
								FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

								if(Power_temp<0)
									*(pBuf+3)|=0x80;
								else
									*(pBuf+3)&=0x7f;

								pBuf+=4;
							}
						}
						break;
					case 0x10:
						Record5=(struct RECORD5 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD5);						
						if((mask&read_class) != 0)
						{
							for(i=0;i<4;i++)
							{
								FormatBCD(format_data(*((unsigned long *)Record5 +i),0)/(10),pBuf,4);							
								pBuf+=4;
							}
						}
						break;
					default:
						if((pRecord->Mode_Byte&0x08)!=0&&(pRecord->Mode_Byte&0x10)==0)
							read_addr+=16;
						Record6=(struct RECORD6 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD5);						
						if((mask&read_class) != 0)
						{
							memcpy(pBuf, (unsigned char *)&Record6->DemandActive[0], 6);
							pBuf += 6;
						}
						break;
				}			
			}
			//else//liuyq delete 2009-8-27
			{			
				*pBuf=0xAA;
				pBuf++;
			}
			
			
			mask <<= 1;
		}
	}
	//*(rBuffer+2)=pBuf-rBuffer+2;
	*(rBuffer+2)=pBuf-rBuffer-3; 
	sum = 0;
	for(i=0; i<pBuf-rBuffer; i++)
	{
		sum += *(rBuffer+i);
	}
	*(pBuf++)=sum;
	*(pBuf++)=0xe5;

	if(mode!=0)
		{
			if(Iterate_Tree_Flag[uartx].Back_Flame_Serial!=Data_number)
			{	
				Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
				Read_Count[uartx]--;
			}
			//*(pBuf++)=Iterate_Tree_Flag[uartx].Back_Flame_Serial;
		}
	else
		{
			Read_Count[uartx]--;
		}
	
	if(Read_Count[uartx]!=0)
	{
	  FeedWatchdog();
	  if(Find_Next_Record(uartx,&nReadPage,id.d[2])!=0)
	    Read_Count[uartx]=0;
  }

	if(Read_Count[uartx]!=0)
		return (pBuf-rBuffer)|0x8000;
	else
		return pBuf-rBuffer;
	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"��ʼ����������"*/
int InitLoadRecord(void)
{
	unsigned int i;
	unsigned char flag;
	struct LOADRECORD_NEW *pointer;
	
	CheckPowerDown();
	FeedWatchdog();
	
	flag=0;
	i=BLOCKADDRESSLEN+FIRSTFLAGLEN+LOADRECORDFLAGLEN+64+BLOCKADDRESSLEN;
	
	if(ReadBlock(GLOADRECORD_ROM,&Co.b[300],i,0)!=0)
	{
		for(i=0;i<sizeof(struct LOADRECORD_NEW);i++)
		  *((unsigned char*)&LoadRecord+i)=0;
		for(i=0;i<(BLOCKADDRESSLEN+FIRSTFLAGLEN+LOADRECORDFLAGLEN);i++)
		  *((unsigned char*)&LoadRecord+i)=Co.b[300+i];
		
		i=BLOCKADDRESSLEN+FIRSTFLAGLEN+LOADRECORDFLAGLEN+64;
		pointer=(struct LOADRECORD_NEW *)(&Co.b[300+i]);
		
		if(((*pointer).LoadRecordPointer>LoadRecord.LoadRecordPointer)
		&&(!(((*pointer).BlockAddress >MAX_BLOCK_NUM)||(((*pointer).BlockAddress ==0)&&((*pointer).LastBlockAddress ==0)))))
		{
			for(i=0;i<BLOCKADDRESSLEN;i++)
		    *((unsigned char*)&LoadRecord+i)=*((unsigned char*)pointer+i);
		}
		
		if((LoadRecord.BlockAddress >MAX_BLOCK_NUM)||((LoadRecord.BlockAddress ==0)&&(LoadRecord.LastBlockAddress ==0)))/*"�������߻�����������"*/
		{
			flag=1;
		}
	}
	else
	{
		flag=1;
	}
	
	CheckPowerDown();
	FeedWatchdog();
	
	if(flag==1)
	{
		First_InitLoadRecord();/*"��������ĸ������߻�������д���ڿ���"*/
	}
	else
	{
	  LoadRecord.LoadRecordPointer=0;
	  WRLC256(BLOCKADDRESS_ROM,(unsigned char*)&LoadRecord,BLOCKADDRESSLEN,0,0);
	  WRLC256(BAKBLOCKADDRESS_ROM,(unsigned char*)&LoadRecord,BLOCKADDRESSLEN,0,0);
	}
	
	for(i=0;i<sizeof(struct MINUTE_POWER_DATA);i++)
		*((unsigned char *)&Minute_Power_Data+i)=0;
 
	return flag;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"���Ҹ�����¼��ַ��������¼"*/
int Get_Next_Record_Addr(unsigned int Page,unsigned int *rPage,unsigned char sort)
{
    unsigned int nnblock,startblock,endblock,checknum;
    union FlashAddr32M FlashAddr,FlashAddrstart,FlashAddrEnd;
    unsigned char uni,flag,sortemp,nSave;
    struct DATEANDTIME_DEF   recordtime;

    if((LoadRecord.LoadRecordFlag.reStart==0)&&(Page>=LoadRecord.LastBlockAddress))
        return -1;  

    recordtime = softdate;
    flag       = 0;
    nnblock    = Page;    
    if(sort==0)/*"sum"*/
    {
        if(0==LoadRecord.LoadRecordFlag.reStart)/*"uncovering"*/
        {   
            if(ReadData_To_Cob(&nnblock,2)!=2)
                return -1;
        }
        else/*"have covered"*/
        {            
            checknum=LoadRecord.BlockAddress;
            if(checknum%SECTOR_PAGE_NUM==0)
                endblock=LoadRecord.LastBlockAddress;
            else
                endblock=LoadRecord.BlockAddress;
            if(!Get_Physicaladdress_From_Block(endblock,(unsigned long*)&FlashAddrEnd.addr))
                return -1; 
            if(!Get_Physicaladdress_From_Block(nnblock,(unsigned long *)&FlashAddr.addr))
                return -1;   
            
            if(FlashAddr.SectorAddr.Saddr!=FlashAddrEnd.SectorAddr.Saddr)
            {  
                if(ReadData_To_Cob(&nnblock,2)!=2)
                        return -1;                   
            }
            else
            { 
                if(nnblock<LoadRecord.LastBlockAddress)
                {
                    if(ReadData_To_Cob(&nnblock,2)!=2)
                        return -1;          
                }
                else
                {
                    FlashAddr.SectorAddr.Saddr++;
                    if(FlashAddr.addr>=RECORD_END_SECTOR)
                        FlashAddr.addr=RECORD_FIRST_SECTOR;
                    FlashAddr.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&startblock,FlashAddr.addr);
                    nnblock=startblock; 
                    for(uni=0;uni<4;uni++)
                    {
                       if(ReadData_To_Cob(&startblock,2)==2)                      
                       {
                           break;
                       }
                       startblock++;
                       nnblock=startblock;                   
                    }
                    if(uni==4)
                        return -1;
                }
            }
        }
     }
     else
     {
        checknum=LoadRecord.BlockAddress;
        if(checknum%SECTOR_PAGE_NUM==0)
            endblock=LoadRecord.LastBlockAddress;
        else
            endblock=LoadRecord.BlockAddress;
        if(!Get_Physicaladdress_From_Block(endblock,(unsigned long *)&FlashAddrstart.addr))
             return -1;
        if(ReadData_To_Cob(&nnblock,2)!=2)
              return -1;    

        sortemp=0;
        endblock=nnblock;
        checknum=0;
        while(checknum<DATA_NUM_SECTOR)
        {   
                if((0==LoadRecord.LoadRecordFlag.reStart)&&(endblock>LoadRecord.LastBlockAddress))
                    return -1;

                if(!Get_Physicaladdress_From_Block(endblock,(unsigned long *)&FlashAddrEnd.addr))
                            return -1;
                if(FlashAddrstart.SectorAddr.Saddr==FlashAddrEnd.SectorAddr.Saddr)
                { 
                    while(endblock<=LoadRecord.LastBlockAddress)
                    {
                        nnblock=endblock;
                        if(ReadData_To_Cob(&endblock,2)!=2)
                            return -1; 
                        sortemp=Co.b[6]&(0x01<<(sort-1));
                        if(sortemp!=0)/*"Find data way out"*/
                        {
                            *rPage=nnblock;
                            return 0;                     
                        }             
                    }
                    FlashAddrEnd=FlashAddrstart;
                    FlashAddrEnd.SectorAddr.Saddr++;
                    if(FlashAddrEnd.addr>=RECORD_END_SECTOR)
                        FlashAddrEnd.addr=RECORD_FIRST_SECTOR;
                    FlashAddrEnd.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr); 
                }
                          
                nSave=0;
                startblock=endblock/SECTOR_PAGE_NUM;
                WRLC256(FILE_INDEX_LEN+startblock*6+(sort-1),(unsigned char*)&nSave,1,0,1);

                if(nSave<SECTOR_PAGE_NUM)
                {
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr);  
                    nnblock=endblock;
                    if(ReadData_To_Cob(&endblock,2)!=2)
                        return -1; 
                    sortemp=Co.b[6]&(0x01<<(sort-1));
                    if(sortemp!=0)/*"Find data way out"*/
                    {
                      break;
                    }                    
                }
                else
                {
                    FlashAddrEnd.SectorAddr.Saddr++;
                    if(FlashAddrEnd.addr>=RECORD_END_SECTOR)
                       FlashAddrEnd.addr=RECORD_FIRST_SECTOR;
                    FlashAddrEnd.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr);                    
                }             
                checknum++;
                FeedWatchdog();
         }
         if(checknum>=DATA_NUM_SECTOR)
             return  -1;
     }   
     
     *rPage=nnblock;
     return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"�����ϴζ�ȡ�ü�¼��������¼"*/
int Find_Next_Record(int channel,unsigned int *rblock,unsigned char sort)
{
       	unsigned int nblock,nByte;

       	if(sort==0)
       	{
            	nblock=LoadRecord.LastBlockAddress;
       	}
       	else
       	{
            	nblock=LoadRecord.LastBlockAddress1[sort-1];
       	}
	
	if((LoadRecord.ReadHistory[channel].Last_Read_BlockAddress==nblock))
	{
		return -1;
	}	
	else
	{
		if(Get_Next_Record_Addr(LoadRecord.ReadHistory[channel].Last_Read_BlockAddress,rblock,sort)==-1)
		     return -1;	
	}
       
	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"�����ϴζ�ȡ�ü�¼"*/
int Find_Last_Record(int channel,unsigned int *rPage)
{
	*rPage=LoadRecord.ReadHistory[channel].Last_Read_BlockAddress;
	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"��������ļ�¼"*/
int Find_First_Record(unsigned int *rblock,unsigned char sort)
{
	unsigned int num;
	unsigned char ret;
    
	if(LoadRecord.LoadRecordFlag.reStart==0)/*"��¼δ������Ҳ���ǵ�һ����¼û�б����ǹ�"*/
	{
          if(sort==0)
          {
		      *rblock=0;/*"���Ե�ַ�ĵ�һ����¼��������ļ�¼"*/
          }
          else
          {        
              *rblock=LoadRecord.FirstBlockAddress1[sort-1];
          }
	}	
	else/*"��¼��������Ҳ���ǵ�һ����¼�Ѿ��������ǹ�"*/
	{ 
	     if(Get_Next_Record_Addr(LoadRecord.LastBlockAddress,rblock,sort)==-1)
			     return -1;	
              
        /*"����"*/
		/*if(ReadData_To_Cob(rblock))
			return -1;
		//liuyq modify 2009-9-1 end
			
		num=0;
		
		while((Co.b[0]!=0xaa)&&(num<=*rblock))
		{	
			FeedWatchdog();
			num=*rblock;
			ret=Add_Addr(BLOCK_LENGTH,rblock);
			if(ret==1)
			{				
				if(ReadData_To_Cob(rblock))
					return -1;
				//liuyq modify 2009-9-1 end
				
			}		
		}	
		if(Co.b[0]!=0xaa||Co.b[1]>4||Co.b[1]==0)
			return -1;*/
	}
	
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"��������ļ�¼"*/
int Find_Near_Record(unsigned int *rblock,unsigned char sort)
{
       if(sort==0)
       {
	        *rblock=LoadRecord.LastBlockAddress;
       }
       else
       {
            *rblock=LoadRecord.LastBlockAddress1[sort-1];
       }
	return 0;
}
//#pragma SECTION program program_protect
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"���Ҹ�����ַ�ļ�¼"*/
int Find_Addr_Record(unsigned int *rPage, unsigned int *rByte,int addr)
{
	*rPage=RECORD_FIRST_PAGE+(addr/4);			
	*rByte=(addr%4)*RECORD_LENGTH;
	return 0;	
}

#if 0
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"���Ҹ���ʱ��ļ�¼"*/
int Find_Data_Record(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort)
{
	int ret;
	if((ret=FindRecord(rDate,rPage,sort))==0)
	{	
		if(LoadRecord.LoadRecordFlag.reStart==0)/*"��¼δ������Ҳ���ǵ�һ����¼û�б����ǹ�"*/
		{
			if(*rPage>LoadRecord.LastBlockAddress)
			//	ret= -1;
			//else if(*rPage==LoadRecord.LastBlockAddress)
			{
				//if(*rByte>LoadRecord.LastByteAddress)
					ret=-1;			
			}				
		}		
	}
	return ret;	
}
#endif

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"��һ���ϵ��ʼ����������"*/
void First_InitLoadRecord(void)
{
    unsigned int unc;
    union FlashAddr32M Flashaddr;
    unsigned char saveflag[6];
    
	LoadRecord.LoadRecordFlag.reStart=0;
	LoadRecord.BlockAddress =0;
	LoadRecord.LastBlockAddress= 0;
	LoadRecord.LoadRecordPointer=0;
    
	LoadRecord.LastRecordTime.Year = 0x00;
	LoadRecord.LastRecordTime.Month = 0x01;
	LoadRecord.LastRecordTime.Day = 0x01;
	LoadRecord.LastRecordTime.Hour = 0x00;
	LoadRecord.LastRecordTime.Min = 0x00;
    
    LoadRecord.First_Flag.byte=0x3f;

	for(unc=0;unc<6;unc++)
	{
		LoadRecord.FirstBlockAddress1[unc]=INVALID_LD_BLK;
		LoadRecord.LastBlockAddress1[unc]=0;
	}
	
	
	WRLC256(BLOCKADDRESS_ROM,(unsigned char*)&LoadRecord,BLOCKADDRESSLEN+FIRSTFLAGLEN+LOADRECORDFLAGLEN,0,0);
	
	WRLC256(BAKBLOCKADDRESS_ROM,(unsigned char*)&LoadRecord,BLOCKADDRESSLEN,0,0);
	
	for(unc=0;unc<6;unc++)
	{
    saveflag[unc]=0xff;
  }
	
  WRLC256(FILE_INDEX_LEN,(unsigned char *)&saveflag[0],6,0,0);
  FeedWatchdog();
  
  WRLC256(LOADRECORD_DAYINDEX_Y,0,366,0,0);
	FeedWatchdog();	
    
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Minute_Power(char channel)
{
	int i;
	char c_temp;
	union byte_def temp_byte1;
	//union byte_def temp_byte2;//liuyq delete 2009-9-1
	unsigned long l_tmep;
	/*"�������"*/

	for(i=0;i<4;i++)
	{
		c_temp=0x01;
		c_temp<<=i;
		//if(!(((temp_byte1.byte&c_temp)==1)&&(Meter_Parameter.MeterMode[0].bit.b6==0)))/*"������ǵ�ǰ����Ϊ���������˫�����"*/
		{
			
			Minute_Power_Data.Active_power_sum[i]+=Active_power[i];			
			Minute_Power_Data.Active_power_num[i]++;  
			
		}
		//if(!(((temp_byte2.byte&c_temp)==1)&&(Meter_Parameter.MeterMode[0].bit.b6==0)))/*"������ǵ�ǰ����Ϊ���������˫�����"*/
		{
			Minute_Power_Data.Reactive_power_sum[i]+=Reactive_power[i];
			Minute_Power_Data.Reactive_power_num[i]++;
		}
	}    

	if(channel!=0)/*"���ֵ���"*/
	{
		for(i=0;i<4;i++)
		{
			l_tmep=Minute_Power_Data.Active_power_num[i];
			Minute_Power_Data.Active_power_last_data[i]=Minute_Power_Data.Active_power_sum[i]/l_tmep;
			l_tmep=Minute_Power_Data.Reactive_power_num[i];
			Minute_Power_Data.Reactive_power_last_data[i]=Minute_Power_Data.Reactive_power_sum[i]/l_tmep;
			Minute_Power_Data.Active_power_sum[i]=0;
			Minute_Power_Data.Reactive_power_sum[i]=0;
			Minute_Power_Data.Active_power_num[i]=0;  
			Minute_Power_Data.Reactive_power_num[i]=0;
		
		}
	}

	Active_power_Per_Mintue=ABS(Minute_Power_Data.Active_power_last_data[0]);
}



//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Change_SortAddr(unsigned char rSaveFlag,unsigned int rblock)
{
       unsigned char unc,first,last,flag,pointer;

       flag=0;
       pointer=LoadRecord.First_Flag.byte;
       for(unc=0;unc<6;unc++)
       {
            first=LoadRecord.First_Flag.byte&(0x01<<unc);
            if((rSaveFlag&first)!=0)
            {
                 LoadRecord.FirstBlockAddress1[unc]=rblock;
                 pointer&=~(0x01<<unc);
                 flag=0xff;
            }
            last=rSaveFlag;
            if((last&(0x01<<unc))!=0)
            {
                LoadRecord.LastBlockAddress1[unc]=rblock;
            }
       }
       if(flag==0xff)
       {
            LoadRecord.First_Flag.byte=pointer;
            WRLC256(FIRSTFLAG_ROM,(unsigned char*)&LoadRecord.First_Flag.byte,FIRSTFLAGLEN,0,0);
       }
}
/*"******************************************************************************************************"*/
/*"     *   "����:����ÿ���������һ��洢ĳ��Ŀ�ź���"                    *"*/
/*"     *   " ����ֵ:��                                                    " *"*/
/*"*******************************************************************************************************"*/
void Save_SortIndex(unsigned char rSaveFlag,unsigned int rblock)
{
      unsigned char unc,flag=0,nSave[6];
      unsigned int temp,temp1;
      unsigned int nblock;
      char vd_check;

      vd_check=int2ic;
      
      if(((LoadRecord.LastBlockAddress%SECTOR_PAGE_NUM)>(LoadRecord.BlockAddress%SECTOR_PAGE_NUM))
        &&(LoadRecord.BlockAddress%SECTOR_PAGE_NUM!=0))/*"������"*/
      {         
         nblock=LoadRecord.BlockAddress;
         temp=nblock/SECTOR_PAGE_NUM;
         temp1=nblock%SECTOR_PAGE_NUM;
         for(unc=0;unc<6;unc++)
            nSave[unc]=0xff; 
         flag=0xff;
      }
      else
      { 
         nblock=LoadRecord.LastBlockAddress;         
         temp=nblock/SECTOR_PAGE_NUM;
         temp1=nblock%SECTOR_PAGE_NUM;
         WRLC256(FILE_INDEX_LEN+temp*6,(unsigned char *)&nSave[0],6,0,1);
      }
      
      /*"��¼�������ĸ������ݵĵ�һ���������ڿ��"*/
      for(unc=0;unc<6;unc++)
      {
           if(((rSaveFlag&(0x01<<unc))!=0)&&(nSave[unc]==0xff))
           {
                nSave[unc]=temp1;
                flag=0xff;
           } 
      }
      
      if(flag==0xff)
      {
          WRLC256(FILE_INDEX_LEN+temp*6,(unsigned char *)&nSave[0],6,0,0);
      }
      //for(unc=0;unc<6;unc++)
      //    First_Sort[unc]=nSave[unc];

     int2ic=vd_check&0x1f;      
}

void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4)
{
	(*t4).bit.Year=OB_H((*t5).Year);
	(*t4).bit.Month=OB_H((*t5).Month);
	(*t4).bit.Day=OB_H((*t5).Day);
	(*t4).bit.Hour=OB_H((*t5).Hour);
	(*t4).bit.Minute=OB_H((*t5).Minute);
}

void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5)
{
	(*t5).Year=OH_B((*t4).bit.Year);
	(*t5).Month=OH_B((*t4).bit.Month);
	(*t5).Day=OH_B((*t4).bit.Day);
	(*t5).Hour=OH_B((*t4).bit.Hour);
	(*t5).Minute=OH_B((*t4).bit.Minute);
}

signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5)
{
	struct DATE_TIMENOSEC_5BYTE t;
	unsigned char result;
	
	DateTimeNoSec4ByteTo5Byte(t4,&t);
	
	result=CompareBytes((unsigned char *)&t,(unsigned char*)t5,5);
	
	return result;
}

void ConverseString(unsigned char *p,unsigned char n)
{
	unsigned char i;
	unsigned char j;
	
	for(i=0;i<n/2;i++)
	{
		j=p[i];
		p[i]=p[n-1-i];
		p[n-1-i]=j;
	}
	
}

int Find_Data_Record_New(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort,unsigned char kind)
{
	int ret;
	unsigned char findflag;
	unsigned int  i;
	
	if((ret=FindRecord(rDate,rPage,sort))==0)
	{	
		if(LoadRecord.LoadRecordFlag.reStart==0)/*"��¼δ������Ҳ���ǵ�һ����¼û�б����ǹ�"*/
		{
			if(*rPage>LoadRecord.LastBlockAddress)
			{
				return -1;		
			}				
		}		
	}
	
	if((Meter_Parameter.parameter1.LocalFunctionMode.bit.b3==0)&&(kind==0x00))
	{
		return ret;
	}
	
	findflag=0;
	
	if(ret!=0)
	{
		WRLC256(LOADRECORD_DAYINDEX_Y,&Co.b[300],366,0,1);
		FeedWatchdog();
		AddOneHour(rDate);
		for(i=0;i<366;i++)
		{
			if(ThisDayHaveRecord(rDate)==0)
			{
				findflag=1;
				break;
			}
			if(i<365)
			{
				AddOneDay(rDate);
			}
		}
		if(findflag==1)
		{
		  ret=FindRecord(rDate,rPage,sort);
		}
	}
	if(ret==0)
	{
		if(LoadRecord.LoadRecordFlag.reStart==0)/*"��¼δ������Ҳ���ǵ�һ����¼û�б����ǹ�"*/
		{
			if(*rPage>LoadRecord.LastBlockAddress)
			{
				return -1;		
			}				
		}	
	}
	
	return ret;	
}

int find_lst_record_frm_tm(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort)
{
    struct DATA_TIME tm;
    unsigned int blk;
    unsigned int tmp_blk;
    unsigned char i;
    int ret;
    struct DATA_TIME  Date;
    unsigned char sz;

    *rPage = INVALID_LD_BLK;
    memcpy(&tm.Year, &rDate->Year, 6);
    ret = Find_Data_Record_New(&blk, &tm, sort, 1);
    if (ret == 0)
    {
        tmp_blk = blk;
        for (i = 0; i < 8; i++)
        {/*" һ��ѭ��4�ξ��˳�"*/
            if (tmp_blk > 0)
            {
                tmp_blk--;
            }
            else
            {
                if(LoadRecord.LoadRecordFlag.reStart==0)
                {/*" �ߵ�����̫��������"*/
                    return -1;    
                }
                else
                {
                    tmp_blk = MAX_BLOCK_NUM - 1;
                }
            }
            ret = ReadData_To_Cob(&tmp_blk, 3);
            if (ret == 0)
            {
                *rPage = tmp_blk;
                break;
            }
        }
#if 0
        ret = ReadData_To_Cob(&blk, 3);
        if (ret)
        {
            return -1;
        }
        sz = Co.b[1];
        if(LoadRecord.LoadRecordFlag.reStart==0)
        {
            *rPage = blk - sz;
        }
        else
        {
            if (blk < sz)
            {
                *rPage = MAX_BLOCK_NUM - sz;
            }
            else
            {
                *rPage = blk - sz;
            }
        }
#endif
    }
    else
    {
        Find_Near_Record(&blk, sort);
        ret = ReadData_To_Cob(&blk, 3);
        if (ret)
        {
            return -1;
        }
        DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
        if (My_Memcmp(&Date.Year, &rDate->Year, 5) == 2)
        {/*" ʱ��С�������"*/
            *rPage = blk;
        }
    }

    if (*rPage == INVALID_LD_BLK)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


void SaveDayIndex(struct DATA_TIME *rDate)
{
	unsigned char i;
	unsigned char savehoursflag;
	unsigned char nhours[3];
	unsigned char nyears;
	unsigned int  ndays;
  
	i=OB_H(rDate->Month);
	ndays=day_num[i-1]+OB_H(rDate->Day)-1;
	
	if(ndays<366)
	{
		FeedWatchdog();
		nyears=0;
		savehoursflag=0;
		WRLC256(LOADRECORD_DAYINDEX_Y+ndays,&i,1,0,1);
		WRLC256(LOADRECORD_DAYINDEX_H+ndays*3,&nhours[0],3,0,1);
		if(i!=((rDate->Year)+1))
		{
			nyears=(rDate->Year)+1;
			nhours[0]=0;
			nhours[1]=0;
			nhours[2]=0;
		}
		i=OB_H(rDate->Hour);
		if(i<24)
		{
		  if((nhours[i/8]&BIT_UNC[i%8])==0)
		  {
		    nhours[i/8]=nhours[i/8]|BIT_UNC[i%8];
		    savehoursflag=1;
		  }
		}
		if(nyears!=0)
		{
			WRLC256(LOADRECORD_DAYINDEX_Y+ndays,&nyears,1,0,0);
		}
		if(savehoursflag==1)
		{
			WRLC256(LOADRECORD_DAYINDEX_H+ndays*3,&nhours[0],3,0,0);
		}
	}
    
}


/*" ����ֵ: 0�м�¼��-1�޼�¼"*/
int ThisDayHaveRecord(struct DATA_TIME *rDate)
{
	unsigned char i;
	unsigned char nyears;
	unsigned int  ndays;
	unsigned char nhours[3];
	unsigned char starthour;
	unsigned char result;
  
  result=-1;
  
	i=OB_H(rDate->Month);
	ndays=day_num[i-1]+OB_H(rDate->Day)-1;
	starthour=OB_H(rDate->Hour);
	if(ndays<366)
	{
		FeedWatchdog();
		nyears=Co.b[300+ndays];
		if(nyears==((rDate->Year)+1))
		{
			WRLC256(LOADRECORD_DAYINDEX_H+ndays*3,&nhours[0],3,0,1);
			if(starthour<24)
			{
				for(i=starthour;i<24;i++)
				{
					if((nhours[i/8]&BIT_UNC[i%8])!=0)
		      {
		        rDate->Hour=OH_B(i);
		        result=0;
		        break;
		      }
			 }
			}
		}
	}
	
	return result;
}


extern const unsigned char DaysOfMonth[12];
/*" ʱ�����len���ӣ��γ�һ���µĺϷ���ʱ��"*/
/*" len ��󲻻ᳬ��99���� "*/
void time_add_minute(struct DATA_TIME *req_tm, unsigned int len)
{
    unsigned int timeCounter;
	unsigned char temp;
    unsigned char nMaxDay; 
    unsigned char min;
    unsigned char hour;
    unsigned char day;
    unsigned char month;
    unsigned char year;

    //if ()/*" �������Сʱ"*/ 
    //{
    //}

    BCD2Byte(req_tm->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(req_tm->Min, &temp);
	timeCounter += temp;

    timeCounter += len;  
    hour = timeCounter/60;
    if (hour >= 24)
    {
        //temp = 0;
        hour = hour % 24;/*"����Сʱ"*/
        day = OB_H(req_tm->Day);
        day++;
        req_tm->Day = OH_B(day);
        //req_tm->Day++;
        nMaxDay = DaysOfMonth[OB_H(req_tm->Month)-1]; 
         if((req_tm->Year & 0x03) == 0  && req_tm->Month == 0x02) 
         {
          nMaxDay++;
         }
        if (req_tm->Day > OH_B(nMaxDay))
        {
            req_tm->Day = 0x01;
            month = OB_H(req_tm->Month);
            month++;
            req_tm->Month = OH_B(month);
            //req_tm->Month++;
            if(req_tm->Month > 0x12)
            {
                req_tm->Month = 0x01;
                year = OB_H(req_tm->Year);
                year++;
                req_tm->Year = OH_B(year);
                //req_tm->Year++;
            }
        }
    }
    Byte2BCD(hour, &req_tm->Hour);
    min = timeCounter%60;
    Byte2BCD(min, &req_tm->Min);
}

//unsigned char sum;
unsigned int remain_skip_pnt;/*" ʣ�����Ҫ������ʱ��� "*/
unsigned int sum_done_pnt; /*" �к���֡������£�ǰ���ܹ��Ѿ������˶��ٸ�ʱ��� "*/
unsigned int next_record_block; /*" ��һ����¼�Ŀ�� "*/
unsigned int fst_not_rd_blk; /*" �ҵ��ĵ�һ����Ч��ʱ��㣬��������ǰ���пսڵ��û��ʹ�� "*/

//unsigned char last_hour_remain_pnt;/*" ��һ��Ӧ��֡�����һ��Сʱ�л�ʣ���δ������� "*/
//unsigned char last_hour_to_end; /*" ��һ��Ӧ��֡�����һ��Сʱ���м�¼�����꣬�Ѿ������Сʱ���һ���� "*/

//struct DATA_TIME last_req_tm;   /*" ��һ��Ӧ��֡����ȡ�ļ�¼ʱ�� "*/


unsigned char sort_base_type[9] = {0, 1, 1, 2, 2, 3, 4, 5, 6};
unsigned char last_frm_len;

static unsigned char sort;
static unsigned char per_len;
static unsigned int period;
unsigned char lst_pnt_data[16];


int check_id_error(unsigned char di0, unsigned char di1)
{
    int ret;

    ret = -1;
    switch(di1)
    {
    case 1:
        if((di0 > 0 && di0 < 4) || di0 == 0xFF)
            ret = 0;
        break;
    case 2:
        if((di0 > 0 && di0 < 4) || di0 == 0xFF)
            ret = 0;
        break;   
    case 3:
        if(( di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 4:
        if((di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 
#if 1
    case 5:
        if((di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 6:
        if((di0 >= 1 && di0 <= 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 7:
        if((di0 >= 1 && di0 <= 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 8:
        if((di0 >= 1 && di0 <= 2) || di0 == 0xFF)
            ret = 0;
        break; 
#endif
    default:
        break;
    }  
    return ret;
}

unsigned char find_sort_off(unsigned char sort, unsigned char rMode)
{
	unsigned char nMask;
	unsigned char off;
	unsigned char i;
	
	off = 2+sizeof(struct RECORD);
	for(i=1; i<sort; i++)
	{
        nMask = (0x01 << (i - 1));
		if((nMask & rMode) != 0)
		{
			off += Clase_Length[6 - i];
		}
	}

    if(sort == 6 && (rMode&0x08)!=0 && (rMode&0x10)==0)/////
        off+=16;
	return off;
}

#if 0
int get_data_blk_offset(union ID id, unsigned char sort, unsigned char mask,
    unsigned int start_blk, unsigned int *blk, unsigned int *offset, unsigned char *len)
{
    unsigned char off;

    off = 7;
    switch (sort)
    {
    case 1:
        *blk = start_blk;
        switch(id.d[0])
        {
        case 1:
            *offset = id.d[1]*9 + 7;
            *len = 3;
            break;
        case 2:
            *offset = id.d[1]*9 + 7 + 3;
            *len = 3;
            break;
        case 3:
            *offset = id.d[1]*9 + 7 + 3 + 3;
            *len = 3;
            break;
        case 0xFF:
            *offset = id.d[1]*9 + 7;
            *len = 9;
            break;
        default:
            break;
        }
        break;
    case 2:
        if (mask & 0x01)
        {
            off += 20;
        }

        break;
        
    }
    return 0;
}
#endif

#if 0
/*" ʱ��req_tm���ڵ����Сʱ����ʱ��req_tm���м���ʱ��������¼���ɼ�¼ "*/
/*" req_tm ����ǰ�Ѿ�����������˶��� "*/
unsigned int num_record_in_cur_hour(struct DATA_TIME *req_tm, unsigned int period)
{
    unsigned int sum;
    unsigned char minute;
#if 0
    sum = 0;
    minute = OB_H(req_tm->Min);
    while(minute <= 59)
    {
        sum++;
        minute += period;
    }
#else
    sum = (59 - OB_H(req_tm->Min)) / period + 1;
#endif
    return sum;
}
#endif

/*" ��ȡ�������ݱ�ʶ�����ݳ��� "*/
unsigned char get_single_id_data_len(unsigned char di0, unsigned char di1)
{
    unsigned char len;
    
    switch(di1)
    {
    case 1:
        len = (di0 == 0xff)? 6: 2;
        break;
    case 2:
        len = (di0 == 0xff)? 9: 3;
        break;   
    case 3:
        len = (di0 == 0xff)? 12: 3;
        break; 
    case 4:
        len = (di0 == 0xff)? 12: 3;
        break;
#if 1
    case 5:
        len = (di0 == 0xff)? 8: 2;
        break; 
    case 6:
        len = (di0 == 0xff)? 16: 4;
        break; 
    case 7:
        len = (di0 == 0xff)? 16: 4;
        break; 
    case 8:
        len = (di0 == 0xff)? 6: 3;
        break; 
#endif
    default:
        len = 0;
    }
    return len;
}

void get_data_from_cob_base_id(unsigned char di0, unsigned char di1, unsigned char *pBuf)
{
    unsigned char read_mode,Data_number,sum,read_class,read_addr;
    unsigned char *temp_buf;
    unsigned char i;
    unsigned char sort;
    volatile struct RECORD *pRecord;
	volatile	struct RECORD1 *Record1;
	volatile	struct RECORD2 *Record2;
	volatile	struct RECORD3 *Record3;
	volatile	struct RECORD4 *Record4;
	volatile	struct RECORD5 *Record5;
	volatile	struct RECORD6 *Record6;
    signed long Power_temp;
    unsigned char *src;

    src = pBuf;
    sort = sort_base_type[di1];

    pRecord = (struct RECORD *)&Co.b[2];
    read_addr = find_sort_off(sort, pRecord->Mode_Byte);
    switch(di1)
    {
    case 1:
        Record1=(struct RECORD1 *)&Co.b[read_addr];
        temp_buf=(unsigned char *)&Record1->VA[0];
        
        if (di0== 0XFF)
        {
    		for(i=0;i<3;i++)/*" 3���ѹ ÿ��2�ֽ� "*/
    		{
    			*pBuf = temp_buf[i*3]>>4;
    			*pBuf |= (temp_buf[i*3+1]<<4);
    			pBuf++;
    			*pBuf = temp_buf[i*3+1]>>4;
    			*pBuf |= (temp_buf[i*3+2]<<4);
    			pBuf++;
    		}
        }
        else
        {
            i = di0 - 1;
			*pBuf = temp_buf[i*3]>>4;
			*pBuf |= (temp_buf[i*3+1]<<4);
			pBuf++;
			*pBuf = temp_buf[i*3+1]>>4;
			*pBuf |= (temp_buf[i*3+2]<<4);
			pBuf++;
        }
        break;
    case 2:
        Record1=(struct RECORD1 *)&Co.b[read_addr];
        temp_buf=(unsigned char *)&Record1->IA[0];
        if (di0== 0XFF)
        {
    		memcpy(pBuf, temp_buf, 9);/*" 3����� ÿ��3�ֽ� 2�ֽ�Ƶ�� "*/
            pBuf += 9;
        }
        else
        {
            i = di0 - 1;
            memcpy(pBuf, temp_buf + i*3, 3);
            pBuf += 3;
        }
        break;   
    case 3:/*" �й����� "*/
        Record2=(struct RECORD2 *)&Co.b[read_addr];		
        if (di0== 0XFF)
        {
            memcpy(pBuf, &Record2->PAll[0], 3);/*" 3���ֽڵ����й����� "*/
            memcpy(pBuf + 3, &Record2->PA[0], 3*3);/*"9���ֽڵ� A,B,C���й�����"*/
        }
        else
        {
            if (di0 == 0x00)
            {
                memcpy(pBuf, &Record2->PAll[0], 3);
            }
            else
            {
                temp_buf = &Record2->PA[0];
                memcpy(pBuf, temp_buf + (di0 - 1)*3, 3);
            }
        }
        break; 
    case 4:/*" �޹����� "*/
        Record2=(struct RECORD2 *)&Co.b[read_addr];		
        if (di0== 0XFF)
        {
            memcpy(pBuf, &Record2->RAll[0], 3);/*" 3���ֽڵ����޹����� "*/
            memcpy(pBuf + 3, &Record2->RA[0], 3*3);/*"9���ֽڵ� A,B,C���޹�����"*/
        }
        else
        {
            if (di0 == 0x00)
            {
                memcpy(pBuf, &Record2->RAll[0], 3);
            }
            else
            {
                temp_buf = &Record2->RA[0];
                memcpy(pBuf, temp_buf + (di0 - 1)*3, 3);
            }
        }
        break;
#if 1
    case 5:/*" �ܹ������� "*/
        Record3=(struct RECORD3 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
            memcpy(pBuf,(unsigned char *)&Record3->Factor[0], 8);
        }
        else
        {
            temp_buf = &Record3->Factor[0];
            memcpy(pBuf, temp_buf + di0*2 , 2);
        }
        break; 
    case 6:/*"�й����޹������ܵ��������ݿ�"*/
        Record4=(struct RECORD4 *)&Co.b[read_addr];
		read_addr+=sizeof(struct RECORD4);
		Record5=(struct RECORD5 *)&Co.b[read_addr];
        if (di0 == 0XFF || di0 == 0x01)
        {
    		FormatBCD(format_data(Record4->PP,0)/(10),pBuf,4);	/*"�����й��ܵ���"*/						
    		pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x02)
        {
    		FormatBCD(format_data(Record4->NP,0)/(10),pBuf,4);	/*"�����й��ܵ���"*/						
    		pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x03)
        {
            sum = Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;/*"����޹�1�ܵ���"*/
            math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
								sum,SIGNED_LONG,4,4, RAM_MATH);
			FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

			if(Power_temp<0)
				*(pBuf+3)|=0x80;
			else
				*(pBuf+3)&=0x7f;

			pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x04)
        {
            sum = Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;/*"����޹�2�ܵ���"*/
            math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
								sum,SIGNED_LONG,4,4, RAM_MATH);
			FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

			if(Power_temp<0)
				*(pBuf+3)|=0x80;
			else
				*(pBuf+3)&=0x7f;

			pBuf+=4;
        }
        break; 
    case 7:/*" �������޹��������ݿ� "*/
        Record5=(struct RECORD5 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
    		for(i=0;i<4;i++)
    		{
    			FormatBCD(format_data(*((unsigned long *)Record5 +i),0)/(10),pBuf,4);							
    			pBuf+=4;
    		}
        }
        else
        {
            FormatBCD(format_data(*((unsigned long *)Record5 +(di0 - 1)),0)/(10),pBuf,4);							
        }
        break; 
    case 8:/*" ��ǰ�����������ݿ� "*/
		Record6=(struct RECORD6 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
            memcpy(pBuf, (unsigned char *)&Record6->DemandActive[0], 6);
        }
        else
        {
            memcpy(pBuf, &Record6->DemandActive[0] + (di0 - 1)*3, 3);
        }
        break; 
#endif
    default:
        break; 
    }
    if (di1 == 6 || di1 == 7)
    {
        memcpy(lst_pnt_data, src, per_len);
    }

}


void memset(unsigned char *dst, unsigned char data, unsigned char len)
{
    unsigned char i;

    for(i=0; i<len; i++)
    {
        dst[i] = data;
    }
    return;
}

void patch_no_data_pnt(unsigned char di0, unsigned char di1, unsigned char *pBuf, struct DATA_TIME *rDate)
{
    unsigned int blk;
    int ret;
    
    if (di1 == 6 || di1 == 7)
    {
        if (sum_done_pnt == 0)
        {
            ret = find_lst_record_frm_tm(&blk, rDate, sort);
            if (ret == 0)
            {
                ret = ReadData_To_Cob(&blk,1);
                get_data_from_cob_base_id(di0, di1, pBuf);
            }
            else
            {
                memcpy(pBuf, lst_pnt_data, per_len);
            }
        }
        else
        {
            memcpy(pBuf, lst_pnt_data, per_len);
        }
    }
    else
    {
        memset(pBuf, 0xFF, per_len);
    }
}




struct DATA_TIME lst_record_tm;
unsigned long l_lst_record;
unsigned char cur_hour_empty;
unsigned long rd_ld_time;


#if (USE_5MIN_IDX == 0)
/*" �ڵ�ǰСʱ�ڲ�����һ����¼�����ϴβ��ҵ��ļ�¼ʱ�俪ʼ���� "*/
int find_next_record_in_cur_hour_frm_lst_time(unsigned long req_time,
    unsigned long lst_tm, unsigned char sort, unsigned int *rPage)
{
    unsigned int  nblock,getblock;
    unsigned char tmp;
    struct DATA_TIME  Date;

    getblock = next_record_block;
    nblock = getblock;
    tmp = 0;
    if (lst_tm == req_time)
    {
        *rPage = getblock;
        return 0;
    }
    while(lst_tm < req_time)
    {
           FeedWatchdog();
           getblock = nblock;
           if(ReadData_To_Cob(&nblock,2)!=2)/*" ��ȡ��ǰ������ͷ�� �� ��ȡ������¼��� "*/
			    return -1;

           if(sort != 0)
              tmp = Co.b[6]&(0x01<<(sort-1));
           /*
           if(lst_tm>=req_time&&tmp!=0)
           {
               *rPage=getblock;
               return 0;
           }		
           */

		    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
		    Date.Sec=0;
		    if(TimeToLong(Date,&lst_tm)!= 0)
			     return -1;
            if(lst_tm == req_time && tmp != 0)/*" QQQ �᲻������ѭ�� "*/
            {
                *rPage=getblock;
                return 0;   
            }
            if (lst_record_tm.Hour != Date.Hour)/*" hour ����һ���� �˳�"*/
            {
                return -2;
            }

            /*" ��һ����¼�Ѿ������һ����¼�� �Ͳ�Ҫ�����²����� "*/
           if((getblock>=LoadRecord.LastBlockAddress)&&(0==LoadRecord.LoadRecordFlag.reStart))
           {      
                return -1;
            }
            //if(check_search_time(lh_basc,lst_tm,3600l)!=0)
			//     return -2;		/*"����ʱ����������"*/              
    }
    
    return -1;
}


/*"��һ��Сʱ�ĵ�һ��ʱ��㣬��������ʱ�������� "*/
/*"���Сʱ���κμ�¼����cur_hour_empty"*/
/*"��һ��ʱ����м�¼�����ȡ���ݣ�"*/
/*" ��һ��ʱ����޼�¼,��¼���Сʱǰ��Ҫ�������ٸ��㵽remain_skip_pnt "*/
/*" ������ζ����һ��������� "*/
void get_fst_pnt_from_time_in_hour(struct DATA_TIME req_tm, unsigned char *pBuf, union ID id)
{
    unsigned int nReadPage, nblk;//page / block address
    int ret;
    unsigned char skip_in_hour;
    struct DATA_TIME this_tm;
    unsigned long l_this;
    unsigned long l_req;

    cur_hour_empty = 0;

    ret = Find_Data_Record_New(&nReadPage,&req_tm, sort, 0);
    if (ret)/*" ���Сʱ�������κμ�¼ "*/
    {
        patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
        cur_hour_empty = 1;
    }
    else
    {
        ReadData_To_Cob(&nReadPage, 3);
        DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&this_tm);
        //TimeToLong(this_tm, &l_this);
        //TimeToLong(req_tm, &l_req);
        //skip_in_hour = (l_this - l_req)/60/period;
        skip_in_hour = (OB_H(this_tm.Min)- OB_H(req_tm.Min))/period;
        if (skip_in_hour > 0)
        {/*" ���Сʱǰskip_in_hour - 1�����ǿյ� "*/
            patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
            remain_skip_pnt = (skip_in_hour - 1);
            fst_not_rd_blk = nReadPage;
        }
        else
        {
            ret = ReadData_To_Cob(&nReadPage,1);
            get_data_from_cob_base_id(id.d[0], id.d[1], pBuf);
            next_record_block = nReadPage + Co.b[1];/*" ��һ����¼����ʼ��� "*/
            if(next_record_block >= MAX_BLOCK_NUM)
            {
                next_record_block = next_record_block % MAX_BLOCK_NUM;
            }
        }
        
    }
}

#endif


//#pragma SECTION program program_protect

void AddOneHour(struct DATA_TIME *rDate)
{
	unsigned char data[4];
  unsigned char i;
   
  for(i=0;i<4;i++)
    data[i]=OB_H(*((unsigned char *)rDate+i));
  
  if(data[3]<23)
  {
     data[3]++;
  }
  else
  {
     data[3]=0;
     if( data[2]<CalDay(data[0],data[1]) )
     {
      	data[2]++;
     }
     else                        
     {
      	data[2]=1;
      	if(data[1]<12)               
      	{
      	   data[1]++;
      	}
      	else
      	{
      	   data[1]=1; 
      	   data[0]=(data[0]+1)%100;
      	}
     }
  }
              
  for(i=0;i<4;i++)
   *((unsigned char *)rDate+i)=OH_B(data[i]);
  rDate->Min=0;
  rDate->Sec=0;
}

void AddOneDay(struct DATA_TIME *rDate)
{
	unsigned char data[3];
  unsigned char i;
   
  for(i=0;i<3;i++)
    data[i]=OB_H(*((unsigned char *)rDate+i));

  if( data[2]<CalDay(data[0],data[1]) )
  {
     data[2]++;
  }
  else                        
  {
     data[2]=1;
     if(data[1]<12)               
     {
      	data[1]++;
     }
     else
     {
      	data[1]=1; 
      	data[0]=(data[0]+1)%100;
     }
  }

            
  for(i=0;i<3;i++)
   *((unsigned char *)rDate+i)=OH_B(data[i]);
  rDate->Hour=0;
  rDate->Min=0;
  rDate->Sec=0;
}

#if USE_5MIN_IDX

/*" ��min_blkָ���Ŀ�ſ�ʼ����req_tmָ���ļ�¼��������²�5�� "*/
/*" req_tm: ָ��ʱ��; cmp: ʱ��Ƚ����ͣ�Ϊ0ʱ���ϸ���ȣ�Ϊ1ʱ����ڵ���"*/
/*" min_blk: ��5�����������Ǹ��鿪ʼ����;read_blk: ������ҵ��Ŀ��"*/
int find_record_in_cur_5min_frm_min_idx(unsigned char st, struct DATA_TIME req_tm, unsigned char cmp,unsigned int min_blk, unsigned int *read_blk)
{
    unsigned int  nblock,getblock, tmp_blk;
    unsigned char tmp;
    struct DATA_TIME  Date;
    unsigned char i;
    unsigned char res;
    int ret;
    unsigned char j;

    getblock = min_blk;
    nblock = min_blk;
    tmp = 0xff;

    for(i = 0; i < IDX_PERIORD; i++)
    {
           FeedWatchdog();
           getblock = nblock;
           ret = ReadData_To_Cob(&nblock,2);/*" ��ȡ��ǰ������ͷ�� �� ��ȡ������¼��� "*/
#if 0
           if(i == 0 && ret != 2 && LoadRecord.LoadRecordFlag.reStart == 1)
           {
                tmp_blk = nblock;
                for (j = 0; j < 19; j++)/*" 5���ӵļ�¼���ռ��20��"*/
                {
                    if (tmp_blk < MAX_BLOCK_NUM - 1)
                    {
                        tmp_blk++;
                    }
                    else
                    {
                        tmp_blk = 0;
                    }
                    getblock = tmp_blk;
                    ret = ReadData_To_Cob(&tmp_blk, 2);
                    if (ret == 2)
                    {
                        nblock = tmp_blk;
                        break;
                    }
                }
           }
#endif
           if (ret != 2)
           {
			    return -1;
           }

           if(st != 0)
              tmp = Co.b[6]&(0x01<<(st - 1));

		    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
		    Date.Sec=0;

            if (My_Memcmp(&Date.Year, &req_tm.Year, 4) != 0)/*" hour ����һ���� �˳�"*/
            {
                return -2;
            }

            res = My_Memcmp(&Date.Year, &req_tm.Year, 5);
            if( tmp != 0)
            {
                if ((res == 0) || ((res == 1) && (cmp == 1)))
                {
                    *read_blk = getblock;
                    return 0;   
                }
            }


            /*" ��һ����¼�Ѿ������һ����¼�� �Ͳ�Ҫ�����²����� "*/
           if((getblock>=LoadRecord.LastBlockAddress)&&(0==LoadRecord.LoadRecordFlag.reStart))
           {      
                return -1;
            }
    }
    
    return -1;
}

int read_n_pnt_record_from_time(struct DATA_TIME req_tm, unsigned char req_pnt, unsigned char need_tm, 
    union ID id,unsigned char *rCommand, unsigned char *rBuffer, char mode)
{
    unsigned int nReadPage, nblk;//page / block address
    unsigned int timeCounter;
    int ret;    
    unsigned char *pBuf;        
    unsigned char pnt;
    struct DATA_TIME this_tm;
    unsigned long l_this;
    unsigned long l_req;
    unsigned char cur_off, lst_off;
    unsigned int min_blk;/*" 5����������Ӧ�Ŀ��"*/
    
    if (need_tm)
    {
        My_memcpyRev(rBuffer, (unsigned char *)&req_tm, 5);
        pBuf = rBuffer + 5;/*"ǰ��5���ֽ�ʱ��"*/
    }
    else
    {
        pBuf = rBuffer;
    }

    lst_off = 0xff; /*" ������һ���㶼��ȥ��ȡ������"*/
    for (pnt = 0; pnt < req_pnt; pnt++)
    {
        ret = CompareBytes((unsigned char *)&MainSoftDate,(unsigned char *)&req_tm, 5);
        if(ret == -1) 

        {/*" ���ʱ����ʱ����ڵ�ǰʱ�䣬���ٳ������ó������"*/
            sum_done_pnt = user_req_pnt;
            break;
        }
        cur_off = OB_H(req_tm.Min)/IDX_PERIORD;
        if ((cur_off != lst_off) || (req_tm.Hour != lst_record_tm.Hour))
        {
            ret = get_5min_idx_by_time(&req_tm, &min_blk);
            if (ret < 0)
            {
                //memset(pBuf, 0xFF, per_len);
                min_blk = INVALID_LD_BLK;
            }
            else
            {
                next_record_block = min_blk;
            }

            lst_off = cur_off;
        }
        
        /*" ����5��������˳�����²���"*/
        if (min_blk != INVALID_LD_BLK)
        {
            ret = find_record_in_cur_5min_frm_min_idx(sort, req_tm, 0, next_record_block, &nReadPage);
            if (ret < 0)
            {
                patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
                /*" ���ʱ���û�м�¼�����¸�ʱ�������м�¼ "*/
            }
            else
            {
                ret = ReadData_To_Cob(&nReadPage,1);
                get_data_from_cob_base_id(id.d[0], id.d[1], pBuf);
                next_record_block = nReadPage  + Co.b[1];
                if(next_record_block >= MAX_BLOCK_NUM)
                {
                    next_record_block = next_record_block % MAX_BLOCK_NUM;
                }
            }
        }
        else
        {   /*" ���5���������Ҳ�������ô���5���ӵĵ㶼��FF"*/
            patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
        }
        
        memcpy(&lst_record_tm.Year, &req_tm.Year, 5);
        //TimeToLong(lst_record_tm, &l_lst_record);
        time_add_minute(&req_tm, period);/*" ��һ�����ʱ�� "*/
        pBuf += per_len;
        sum_done_pnt++;
        if (!GetTimeCount(rd_ld_time, MAX_READ_TM_MS))
        {
            break;
        }
    }   
    if (pnt == 0)
    {/*" һ���㶼û�з��ؿ� "*/
        return 0;
    }
    else
    {
        return pBuf-rBuffer;
    }
}

#else

int read_n_pnt_record_from_time(struct DATA_TIME req_tm, unsigned char req_pnt, unsigned char need_tm, 
    union ID id,unsigned char *rCommand, unsigned char *rBuffer, char mode)
{
    unsigned int nReadPage, nblk;//page / block address
    unsigned int timeCounter;
    int ret;    
    unsigned char *pBuf;        
    unsigned char pnt;
    struct DATA_TIME this_tm;
    unsigned long l_this;
    unsigned long l_req;

    if (need_tm)
    {
        My_memcpyRev(rBuffer, (unsigned char *)&req_tm, 5);
        pBuf = rBuffer + 5;/*"ǰ��5���ֽ�ʱ��"*/
    }
    else
    {
        pBuf = rBuffer;
    }
    
    for (pnt = 0; pnt < req_pnt; pnt++)
    {
        if (pnt == 0 && sum_done_pnt == 0)/*" ��һ���� "*/
        {
            get_fst_pnt_from_time_in_hour(req_tm, pBuf, id);
        }
        else/*" ������ "*/
        {
            if(req_tm.Hour == lst_record_tm.Hour)
            {
                if (cur_hour_empty || remain_skip_pnt > 0)
                {
                    patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
                    if(remain_skip_pnt > 0)
                        remain_skip_pnt--;   
                }
                else
                {
                    if (fst_not_rd_blk != INVALID_LD_BLK)
                    {
                        nReadPage = fst_not_rd_blk;
                        fst_not_rd_blk = INVALID_LD_BLK;
                        ret = 0;
                    }
                    else
                    {
                        TimeToLong(req_tm, &l_req);
                        ret = find_next_record_in_cur_hour_frm_lst_time(l_req , l_lst_record, sort, &nReadPage);
                    }
                    if (ret < 0)
                    {
                        patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
                        /*" ���ʱ���û�м�¼�����¸�ʱ�������м�¼ "*/
                    }
                    else
                    {
                        ret = ReadData_To_Cob(&nReadPage,1);
                        get_data_from_cob_base_id(id.d[0], id.d[1], pBuf);
                        next_record_block = nReadPage  + Co.b[1];
                        if(next_record_block >= MAX_BLOCK_NUM)
                        {
                            next_record_block = next_record_block % MAX_BLOCK_NUM;
                        }
                    }
                }
            }
            else
            {
                get_fst_pnt_from_time_in_hour(req_tm, pBuf, id);
            }
        }
        memcpy(&lst_record_tm.Year, &req_tm.Year, 5);
        TimeToLong(lst_record_tm, &l_lst_record);
        time_add_minute(&req_tm, period);/*" ��һ�����ʱ�� "*/
        pBuf += per_len;
        sum_done_pnt++;
        if (!GetTimeCount(rd_ld_time, MAX_READ_TM_MS))
        {
            break;
        }
    }   

    return pBuf-rBuffer;
}
#endif



void time_align(struct DATA_TIME *tm)
{
    unsigned int timeCounter;
	unsigned char temp;
    unsigned int mod;
    
    BCD2Byte(tm->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(tm->Min, &temp);
	timeCounter += temp;

    //period = Meter_Parameter.parameter2.LoadRecordPeriod[sort - 1];
    mod = timeCounter % period;
    if(mod != 0)
    {/*" QQQ ʱ�䲻���� ��������ж��� "*/
        time_add_minute(tm, (period - mod));
    }

}

int check_time_pass_fst_record(struct DATA_TIME *req_tm)
{

    unsigned int blk;
    struct DATA_TIME this_tm;
    int ret;
    unsigned char reStart;
    struct DATA_TIME tm;
    
    unsigned long this_l;
    unsigned long req_l;
    unsigned char pnt;
    
    ret = Find_First_Record(&blk, 0);
    if(ret < 0)
    {
        return ret;
    }

    ret = ReadData_To_Cob(&blk, 3);
    if(ret < 0)
    {
        return ret;
    }
    this_tm.Sec = 0;
    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&this_tm);
    time_align(req_tm);
    if (CompareBytes((unsigned char *)req_tm, (unsigned char *)&this_tm, 5) < 0)
    {/*" ������ʼ��ʱ��С�ڵ�һ����¼��ʱ�䣬��ʱ��ӵ�һ����¼��ʱ�����"*/
        time_align(&this_tm);
        TimeToLong(this_tm, &this_l);

        memcpy(&tm.Year, &req_tm->Year,  6);
        TimeToLong(tm, &req_l);
        pnt = (this_l - req_l)/60UL/period;
        if (pnt >= user_req_pnt)
        {
            user_req_pnt = 0;
        }
        else
        {
            user_req_pnt -= pnt;
        }
        memcpy(&req_tm->Year, &this_tm.Year, 5);
    }
    
    
    return 0;
}




/*" �µĸ������߶�ȡ��ʽ������ʱ������ݱ�ʶ��ȡ��������ȡ96���� "*/
/*" id:���ݱ�ʶ�� rCommand: �������ݣ�rBuffer: ָ��645����ƫ��14�ĵط�"*/
/*" mode: �Ƿ�Ϊ����֡��ȡ�� uartx: ͨ��"*/
int read_record_base_time_id(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
								char mode,unsigned char uartx)
{
    struct DATA_TIME req_tm;
    unsigned int timeCounter;
	unsigned char temp;
    unsigned char type;
    unsigned int mod;
    int ret;
    unsigned char max_pnt;
    unsigned char req_num;
    unsigned char seq;

    rd_ld_time = GetNowTime();
    type = id.d[1];
    sort = sort_base_type[type];
    if (LoadRecord.FirstBlockAddress1[sort - 1] == INVALID_LD_BLK)
    {
        return 0;
    }

    per_len = get_single_id_data_len(id.d[0], id.d[1]);
    if (mode == 0)
        max_pnt = (F_SIZE_LD - 5) / per_len;
    else
        max_pnt = (F_SIZE_LD - 1) / per_len;
    if (max_pnt > user_req_pnt)
    {
        max_pnt = user_req_pnt;
    }
    //max_pnt = 16;// test

    period = Meter_Parameter.parameter2.LoadRecordPeriod[sort - 1];
    
    if (mode == 0)
    {
        Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
        lst_record_tm.Sec = 0;
        req_tm.Sec = 0;
        req_tm.Min =	*(rCommand+1);
    	req_tm.Hour = *(rCommand+2);
    	req_tm.Day = *(rCommand+3);
    	req_tm.Month = *(rCommand+4);
    	req_tm.Year = *(rCommand+5);
        if (CheckTime(&req_tm.Year) == 0)
        {
            cx[3].readloadrecord=0;/*" �����ᱨ��������"*/
            return 0;
        }
        ret = check_time_pass_fst_record(&req_tm);
        if(ret < 0)
            return 0;
        if (user_req_pnt == 0)
        {
            return 0;
        }
        if (id.d[1] == 6 || id.d[1] == 7)
        {
            memset(lst_pnt_data, 0xFF, per_len);
        }
#if 0
        ret = CompareBytes((unsigned char *)&MainSoftDate,(unsigned char *)&req_tm, 5);
        if(ret == -1)   
            return 0;

        //type = id.d[1];
        //sort = sort_base_type[type];
        //period = Meter_Parameter.parameter2.LoadRecordPeriod[sort - 1];
        //per_len = get_single_id_data_len(id.d[0], id.d[1]);

        BCD2Byte(req_tm.Hour, &temp);
    	timeCounter = temp * 60;
    	BCD2Byte(req_tm.Min, &temp);
    	timeCounter += temp;

        mod = timeCounter % period;
        if(mod != 0)
        {/*" QQQ ʱ�䲻���� ��������ж��� "*/
            time_add_minute(&req_tm, (period - mod));
        }
#endif
        sum_done_pnt = 0;
        next_record_block = INVALID_LD_BLK;
        fst_not_rd_blk = INVALID_LD_BLK;
        req_num = (max_pnt > user_req_pnt)?user_req_pnt:max_pnt;
        ret = read_n_pnt_record_from_time(req_tm, req_num, 1, id, rCommand, rBuffer, mode);
        last_frm_len = ret&0xff;
        memcpy(&Card_WR_Buff[256], rBuffer, last_frm_len);
    }
    else
    {
        seq = *rCommand;
        if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1) == seq)
		{/*"����Ŀ�ŵ�����һ֡�Ŀ��+1,������һ֡"*/
            if(sum_done_pnt + max_pnt <= user_req_pnt)
            {
                req_num = max_pnt;
            }
            else
            {
                req_num = user_req_pnt - sum_done_pnt;
            }
            req_tm.Sec = 0;
            memcpy(&req_tm.Year, &lst_record_tm.Year, 5);
            time_add_minute(&req_tm, period);/*" ��һ�����ʱ�� "*/
            ret = read_n_pnt_record_from_time(req_tm, req_num, 0, id, rCommand, rBuffer, mode); 
            last_frm_len = ret&0xff;
            memcpy(&Card_WR_Buff[256], rBuffer, last_frm_len);
		}
		else if(Iterate_Tree_Flag[uartx].Back_Flame_Serial == seq)
		{/*"����Ŀ�ŵ�����һ֡�Ŀ��,�ط���һ֡"*/
			memcpy(rBuffer, &Card_WR_Buff[256],last_frm_len);
            ret = last_frm_len;
		}
		else
		{
			return 0x8000;/*" �쳣 "*/
		}

        if(Iterate_Tree_Flag[uartx].Back_Flame_Serial != seq)
		{	
			Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
		}
                    
    }
    if (sum_done_pnt < user_req_pnt)
    {
        ret |= 0x8000;
    }
    return ret;
}





/*"*****************************END********************************"*/
