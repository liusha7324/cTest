/*"DL645-2007通讯设计"*/
/*"trend 2008-4-23 11:32:09 V1.00"*/
/*"设计方法：协议树，查表"*/
/*"数据文件保存在645DATA.c"*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#ifndef _TREE_LEAF_DEF_
#define _TREE_LEAF_DEF_

#define RAM_MATH	 			    0x8000  
#define EEPROM_MATH	 		    0x8001 

struct COMM_STAUT
{
	unsigned char password_level;/*"密码级别"*/
	unsigned char meter_staut;/*"电表状态：1工厂，2实验室，3现场"*/
};
struct ITERATE_TREE_FLAG{
 	
	unsigned int num;/*"同一个叶子重复遍历的序号，重叠叶子使用"*/
	unsigned int last_num;/*"当次遍历的最后序号，重叠叶子使用"*/
	union  BYTE_BIT flag;/*"b0=1;有后续帧。B1=1在同一个叶子下遍历，即num有用"*/
	unsigned int    File_name;/*"   事件抄读的文件名"*/
	unsigned char Set_Prarmeter_flag;/*"写参数的时候防止多次调用函数标志"*/
	unsigned char  Show_bit_flag;/*"显示时候处理位标志"*/
	unsigned int  Back_Flame_Serial;/*"后续帧序号"*/
	unsigned int last_num_save;/*"上次遍历的最后序，用于重新读后续帧"*/
};
struct TREEADDR_FLASH
{
	//unsigned char addr;
	//unsigned int filename;
	//unsigned char path;
	unsigned long  addr:12;
	unsigned long filename:16;
	unsigned long path:4;

};
struct TREEADDR_RAM
{
	//unsigned char addr[3];
	//unsigned char path;
	unsigned long addr:28;
	unsigned long path:4;
};

union TREEADDR{
	unsigned long	val;
	struct TREEADDR_RAM ram; 	
	struct TREEADDR_RAM  eeprom;	
	struct TREEADDR_FLASH flash;	
};

#endif

extern struct ITERATE_TREE_FLAG Iterate_Tree_Flag[4];	
extern struct COMM_STAUT Comm_Staut;
extern unsigned int Leaf_num_now;
extern union ID Read_Com_ID;


extern signed int    TransferData_New(union ID id,unsigned char *P, unsigned int L,
                         unsigned char formatdata,unsigned char *format,unsigned char mode,
                         unsigned char data_len,unsigned char uartx);
//extern unsigned char Ram_math_Add(unsigned char * startaddr,unsigned char * getbuff ,
//											unsigned char math_mode,unsigned char format,
//											unsigned char Ass_num,unsigned char Ass_addr);
extern unsigned char math_Add(unsigned char * startaddr,unsigned char * getbuff ,
							   unsigned char math_mode,unsigned char format,
							   unsigned char Ass_num,unsigned char Ass_addr, unsigned int  file_name);
//extern unsigned char Eeprom_math(unsigned char mode,unsigned int startaddr,unsigned char * getbuff ,
//											unsigned char math_mode,unsigned char format,
//											unsigned char Ass_num,unsigned char Ass_addr,
//											unsigned char driver);
//extern unsigned char Ram_math_Demand(unsigned char * startaddr,unsigned char * getbuff ,
//											unsigned char math_mode,unsigned char format,
//											unsigned char Ass_num,unsigned char Ass_addr);
extern unsigned char math_Demand(unsigned char * startaddr,unsigned char * getbuff ,
								    unsigned char math_mode,unsigned char format,
								    unsigned char Ass_num,unsigned char Ass_addr, unsigned int file_name);
//extern unsigned char Eeprom_math_Demand(unsigned int startaddr,unsigned char * getbuff ,
//											unsigned char math_mode,unsigned char format,
//											unsigned char Ass_num,unsigned char Ass_addr,
//											unsigned char driver);
extern int Check_Data_valid(unsigned char  *buff_t, unsigned char len);

//----------------------------------------------------------------------

