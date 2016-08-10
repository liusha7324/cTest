/*"MB2表通用版负荷曲线 (VER 1.0 bata0406)										 "*/
/*"Created By Trend 2005-04-06 (在何朝辉程序基础上修改) 		                 "*/
#ifndef _LOADRECORD_
#define _LOADRECORD_

#include "MB_BASE_FUN.h"
#include "defdata.h"
#include "ram.h"
#include "sfr64a.h"

#define MAX_NEED_PNT 96 /*" 国网要求的 至少支持96点连续抄读 "*/

#define CS   p0_0  //p9_4
#define RDY p10_0
//const declaration/////////////////////////////////////////////////////////////


//Data type declaration/////////////////////////////////////////////////////////
struct DATE_TIMENOSEC_5BYTE
{
  unsigned char Year;   //Bcd
  unsigned char Month;  //Bcd
  unsigned char Day;    //Bcd
  unsigned char Hour;   //Bcd
  unsigned char Minute; //Bcd
};

union DATE_TIMENOSEC_4BYTE
{
	unsigned long l;
	struct 
	{
		unsigned long Year:7;   //Hex
		unsigned long Month:4;  //Hex
		unsigned long Day:5;    //Hex
		unsigned long Hour:5;   //Hex
		unsigned long Minute:6; //Hex
		unsigned long :5;       
	}bit;
};


struct RECORD1
{
	unsigned char VA[3];
	unsigned char VB[3];
	unsigned char VC[3];
	unsigned char IA[3];
	unsigned char IB[3];
	unsigned char IC[3];
	unsigned char Freq[2];
};
struct RECORD2
{
	unsigned char ActiveFlag;
	unsigned char ReactiveFlag;
	unsigned char PA[3];
	unsigned char PB[3];
	unsigned char PC[3];
	unsigned char PAll[3];
	unsigned char RA[3];
	unsigned char RB[3];
	unsigned char RC[3];
	unsigned char RAll[3];
	unsigned char SA[3];
	unsigned char SB[3];
	unsigned char SC[3];
	unsigned char SALL[3];
	unsigned char no_ues[4];
};
struct RECORD3
{
	unsigned char Factor[2];
	unsigned char FactorA[2];
	unsigned char FactorB[2];
	unsigned char FactorC[2];
};
struct RECORD4
{
	unsigned long PP;
	unsigned long NP;
};
struct RECORD5
{
	unsigned long Quad1;
	unsigned long Quad2;
	unsigned long Quad3;
	unsigned long Quad4;
};
struct RECORD6
{
	unsigned char DemandActive[3];
	unsigned char DemandReactive[3];
};

struct RECORD
{
	union DATE_TIMENOSEC_4BYTE Save_DateTime;
	char Mode_Byte;
};

union LONG_BYTE
{
	long Long_data;
	unsigned char byte[4];
};

struct LOADINDEX
{
	unsigned int PageAddress : 12;
	unsigned int :2;
	unsigned int ByteAddress : 10;
};
struct MINUTE_POWER_DATA
{
	unsigned long Active_power_sum[4];
	unsigned long Reactive_power_sum[4];
	unsigned char Active_power_num[4];
	unsigned char Reactive_power_num[4];
	   signed long Active_power_last_data[4];
	   signed long Reactive_power_last_data[4];

};
struct  Sort_flag_bit_def
{
     char result:1;
     char equ:1;
     char big:1;
     char flag:1;
     char :1;
     char :1;
     char :1;
     char :1;
};
union Sort_flag_def
{
	struct  Sort_flag_bit_def bit;
	char	byte;
};

union FlashAddr32M
{
    unsigned long addr;
    struct 
	{
		unsigned char Byte0;
		unsigned char Byte1;
		unsigned char Byte2;
		unsigned char Byte3;
	}AsByte;
    struct 
	{
		unsigned long Pdummy:8;
		unsigned long Paddr:24;
	}PageAddr;
    struct 
	{
		unsigned long Sdummy:12;
		unsigned long Saddr:20;
	}SectorAddr;
};
union FLASH_ERR_STATUS_FLAG
{
    struct Flash_Err_Status_Un
    {
        char ChipEraseErr:1;
        char SectorEraseErr:1;
        char WritePageErr:1;
        char WriteEnableErr:1;
        char WriteDisableErr:1;
        char :1;
        char :1;
        char :1;
    }Flash_Err_Status_str;
    unsigned char Flash_Err_Status;
};

#define BLOCKADDRESSLEN    26         
#define FIRSTFLAGLEN       13        
#define LOADRECORDFLAGLEN  1   

struct LOADRECORD_NEW                                                                                                 
{		                                                                                                        
       //BLOCKADDRESSLEN
       unsigned int BlockAddress;            /*"未用空间起始块Block地址"*/                                                            
       unsigned int LastBlockAddress;        /*"最后一条存储取的数据的Block地址"*/                                             
       unsigned int LastBlockAddress1[6];    /*"第1<--->6类最后一条存储取的数据的Block地址"*/ 
       struct DATA_TIME  LastRecordTime;     //time tag of last saved record
       unsigned long LoadRecordPointer;  	   /*"用于比较确定最近一次存储位置"*/
       //BLOCKADDRESSLEN	
       
       //FIRSTFLAGLEN
       union    BYTE_BIT   First_Flag;   
       unsigned int FirstBlockAddress1[6];  /*"第1<--->6类最早一条存储取的数据的Block地址"*/
       //FIRSTFLAGLEN                                             
       
       //LOADRECORDFLAGLEN
       struct                                                                                                          
	     {                                                                                                               
		     char NeedSaveIndex:1;	// =1 need; =0 not need	                                                        
		     char reStart:1;			/*"负荷曲线记录是否覆盖第一条重头开始，需要在电表第一次初始化时清0"*/   
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
	     }LoadRecordFlag;
	     //LOADRECORDFLAGLEN
	     
	     struct                                                                                                          
	     {                                                                                                               
		     unsigned int Last_Read_BlockAddress; /*"最后一次读取的数据的Block地址"*/                         
       }ReadHistory[3];  	                                                                                                                
	                                                                    
};   
//Global variable declaration///////////////////////////////////////////////////
extern struct LOADRECORD_NEW LoadRecord;
extern struct DATETIME SoftDate; //Used for editing only
extern unsigned long FlashEaseTimes;

extern unsigned char user_req_pnt;

//Function declaration//////////////////////////////////////////////////////////
extern void SendByte(char *rData);

extern int WriteBuffer(unsigned int rStartAddr, unsigned int rLength, 
	unsigned char *rData);


extern unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag, struct DATA_TIME *rDate);

extern int SwitchPage(void);


extern void ReadBuffer(unsigned int rStartAddr, unsigned int rLen, 
	unsigned char * rData);


extern int SaveBuffer(unsigned int rPageAddress);

extern int LoadToBuffer(unsigned int rPageAddress);

extern unsigned char GetRecordLength(const unsigned char rMode);

extern int InitSIO4(void);

extern int FindRecord(struct DATA_TIME *rDate, unsigned int *rPage,unsigned char sort);

extern int SaveIndex(struct DATA_TIME *rDate);

extern int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx);
extern int InitLoadRecord(void);
extern void First_InitLoadRecord(void);

extern int SaveLoadRecord(void);


extern void Minute_Power(char channel);
extern void Write_Enable(void);
extern void Write_Disable(void);
extern unsigned char Read_Status_Register(void);
extern unsigned char Write_Status_Register(unsigned char status);
extern void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);
extern int  Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
extern unsigned char Continuously_Program(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
extern int  Chip_Erase(void);
extern int  Sector_Erase(unsigned long FlashAddr);
extern int Check_Sector_Have_Erased(unsigned long Faddr);
extern void FastRead_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);

extern void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4);
extern void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
extern signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);



extern int check_id_error(unsigned char di0, unsigned char di1);
extern int read_record_base_time_id(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
								char mode,unsigned char uartx);

extern void time_add_minute(struct DATA_TIME *req_tm, unsigned int len);
extern unsigned int get_hour_in_year(struct DATA_TIME *rDate);
int Save_5Min_Index(struct DATA_TIME *rDate);
int find_record_in_cur_5min_frm_min_idx(unsigned char st, struct DATA_TIME req_tm, unsigned char cmp,unsigned int min_blk, unsigned int *read_blk);
int get_5min_idx_by_time(struct DATA_TIME *rDate, unsigned int *blk);

#endif
 
