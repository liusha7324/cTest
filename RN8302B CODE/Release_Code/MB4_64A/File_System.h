/*************************************************************************
                                  *  "Name:File_System.h "*
                                  *"Function:File_System Header File"*
  *************************************************************************/
#ifndef _FILE_SYSTEM_H_
#define _FILE_SYSTEM_H_

#define FS_START_PAGE		4096		/*"文件系统起始地址"*/
#define FS_FLAG_NUM		3				/*"标志数"*/
#define PAGE_NUM                    4096                /*"Fs 总页数"*/
#define TEMP_FILE_NUM           3                     /*"临时文件总数"*/            
#define TEMP_FILE			1996				/*"临时文件0"*/
#define TEMP_FILE1			1997				/*"临时文件1"*/  
#define TEMP_FILE2			1998				/*"临时文件2"*/  	                   	

//----------Fuxf added 100105-------------------------------------------
#define MAX_BYTE_NUM                   256               
#define MAX_FILE_NUM                   2000   
#define START_ERROR_CORRECT_PAGE_NUM   7096   
#define ERROR_PAGE_MAX_LIMIT           10  

/*"File_System 数据结构"*/
struct Fs_Node
{
	unsigned char dat[64];    /*"节点数据"*/
	unsigned int  next;                         /*"下一节点地址"*/
};

/*"File_System 位标志"*/
struct Fs_BitFlag
{
	char init_flag:1;
	char bad_flag:1;
	char end_flag:1;
	char del_flag:1;
	char alt_flag:1;
	char :1;
	char :1;
	char :1;
};

/*"File_System 存铁电变量"*/
struct Fs_variable_def
{
     unsigned int Corrcet_Err_StartPage;
     unsigned int SEC_Backup_1_Page;
     unsigned int SEC_Backup_2_Page;
     unsigned int Good_Block_Num;
     unsigned int Bad_Block_Num;
     unsigned int SEC_Backup_3_Page;
     unsigned int SEC_Backup_4_Page;
};

extern int Fs_Init(void);                               /*"格式化文件系统"*/
extern unsigned int Write_File(unsigned int file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Read_File(unsigned int  file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Delete_File(unsigned int file_name);
extern void Fs_Rename(unsigned int src_filename,unsigned int dest_filename);
extern int Free_List_Rebuild(void);         /*"空闲列表重新构建"*/
#endif
