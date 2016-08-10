#ifndef _PUBLIC_
#define _PUBLIC_

//include  declaration//////////////////////////////////////////////////////////
//#include "drivers.h"

//type declaration//////////////////////////////////////////////////////////////
union WORD_DEF1
{
	unsigned short AsUShort;
	short AsShort;
	struct
	{
		unsigned char Byte0;
		unsigned char Byte1;
	}AsBytes;
};

union DWORD_DEF1
{
	unsigned long AsULong;
	long AsLong;
	struct
	{
		unsigned char Byte0;
		unsigned char Byte1;
		unsigned char Byte2;
		unsigned char Byte3;
	}AsBytes;
	struct
	{
		union WORD_DEF1 Word0;
		union WORD_DEF1 Word1;
	}AsWords;
};

struct Date
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Week;
};

struct Time
{
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
};

struct DATETIME
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Week;
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
};
struct DATA_TIME
{
  unsigned char Year;
  unsigned char Month;
  unsigned char Day;
  unsigned char Hour;
  unsigned char Min;
  unsigned char Sec;
};
//variable declaration//////////////////////////////////////////////////////////


//function declaration//////////////////////////////////////////////////////////
int BCD2Byte(unsigned char src_data, unsigned char *dest_data);

#endif

/*"-----------------------------------------------------------------------------"*/
/*"通用函数库"*/
/*"-----------------------------------------------------------------------------"*/
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
/*"存储路径"*/
#define _RAM       0x00000000
#define _EEPROM1   0x10000000
#define _EEPROM3   0x20000000
#define _FLASH 		 0x30000000
/*"格式"*/
#define HEX_FORMAT	 			0x00
#define SIGNED_LONG 			0x01
#define SIGNED_INT 				0x02
#define SIGNED_CHAR 			0x03
#define UNSIGNED_LONG 		0x04
#define UNSIGNED_INT 			0x05
#define UNSIGNED_CHAR 		0x06
#define ASCII_SIX_LENGTH	 			0x07
#define ASCII_TEN_LENGTH	 			0x08
#define ASCII_SIXTEEN_LENGTH 	  0x09
#define ASCII_THIRTY_TWO_LENGTH	0x0A
#define _NN_H							0x0B 
#define _NN_L							0x0C 
#define ASCII_FOUR_LENGTH	 			0x0D
#define  SHOW_CODE	 			0x0E
#define  THREE_BYTE	 			0x0F

#define BCD_FORMAT	 			0x10
#define BCD1BYTE					0x11
#define BCD2BYTE					0x12
#define BCD3BYTE					0x13
#define BCD4BYTE					0x14
//#define BCD5BYTE					0x15
#define UBCD1BYTE					0x16
#define UBCD2BYTE					0x17
#define UBCD3BYTE					0x18
#define UBCD4BYTE					0x19
//#define UBCD5BYTE					0x1A

#define TIME_FORMAT	 			0x20
#define _YYMMDD						0x21
#define _HHMMSS						0x22
#define _YYMMDDHHMM				0x23
#define _MMDDHHMM					0x24
#define _YYMMDDHHMMSS     0x25
#define _MMDD	 		0x26
#define _HHMM	 		0x27
#define _DDHH	 		0x28
#define _NN_MMDD	 	0x29    //TRIFF  HHMM
#define _NN_HHMM 	0x2A
#define _NN_YYMMDD	 	0x2B
#define _WW_YYMMDD	 	0x2C
#define _DDHHMM	 	0x2D


#define BIT_FORMAT         0x30 //by fxf 080131
#define BIT_0                     0x30 
#define BIT_1       	             0x31 
#define BIT_2          		0x32 
#define BIT_3     			0x33 
#define BIT_4     			0x34
#define BIT_5     		         0x35 
#define BIT_6       		           0x36 
#define BIT_7     			   0x37
#define BIT_8      			  0x38 
#define BIT_9      				 0x39 
#define BIT_A       			  0x3A 
#define BIT_B       			  0x3B 
#define BIT_C      			   0x3C 
#define BIT_D      			 	 0x3D 
#define BIT_E       			  0x3E
#define BIT_F      			  0x3F //by fxf 080131

#define ID_CODE_ONE_FORMAT         0x40 
#define ID_CODE_TWO_FORMAT        0x41 
#define ID_CODE_THREE_FORMAT      0x42 
#define ID_CODE_FOUR_FORMAT       0x43

#define RMB_Mauto       0x50		//payment


#define DEMAND_AND_TIME	 	0xA0


/*"单位"*/
#define NONE_UNIT					0x00
#define KWH_UNIT					0x01			
#define WH_UNIT           0x02
#define KVARH_UNIT				0x03			
#define VARH_UNIT         0x04
#define KW_UNIT           0x05
#define W_UNIT            0x06
#define KVAR_UNIT         0x07
#define VAR_UNIT          0x08
#define KV_UNIT           0x09
#define V_UNIT            0x0A
#define KA_UNIT           0x0B
#define A_UNIT            0x0C
#define SECOND_UNIT       0x0D
#define MINUTE_UNIT       0x0E
#define HOUR_UNIT         0x0F
#define DAY_UNIT          0x10
#define DEGREE_UNIT       0x11
#define KVA_UNIT          0x12 
#define HZ_UNIT           0x13 
#define AH_UNIT           0x14
#define YUAN_UNIT			0x15 






    
