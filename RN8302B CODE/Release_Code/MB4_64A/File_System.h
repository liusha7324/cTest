/*************************************************************************
                                  *  "Name:File_System.h "*
                                  *"Function:File_System Header File"*
  *************************************************************************/
#ifndef _FILE_SYSTEM_H_
#define _FILE_SYSTEM_H_

#define FS_START_PAGE		4096		/*"�ļ�ϵͳ��ʼ��ַ"*/
#define FS_FLAG_NUM		3				/*"��־��"*/
#define PAGE_NUM                    4096                /*"Fs ��ҳ��"*/
#define TEMP_FILE_NUM           3                     /*"��ʱ�ļ�����"*/            
#define TEMP_FILE			1996				/*"��ʱ�ļ�0"*/
#define TEMP_FILE1			1997				/*"��ʱ�ļ�1"*/  
#define TEMP_FILE2			1998				/*"��ʱ�ļ�2"*/  	                   	

//----------Fuxf added 100105-------------------------------------------
#define MAX_BYTE_NUM                   256               
#define MAX_FILE_NUM                   2000   
#define START_ERROR_CORRECT_PAGE_NUM   7096   
#define ERROR_PAGE_MAX_LIMIT           10  

/*"File_System ���ݽṹ"*/
struct Fs_Node
{
	unsigned char dat[64];    /*"�ڵ�����"*/
	unsigned int  next;                         /*"��һ�ڵ��ַ"*/
};

/*"File_System λ��־"*/
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

/*"File_System ���������"*/
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

extern int Fs_Init(void);                               /*"��ʽ���ļ�ϵͳ"*/
extern unsigned int Write_File(unsigned int file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Read_File(unsigned int  file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Delete_File(unsigned int file_name);
extern void Fs_Rename(unsigned int src_filename,unsigned int dest_filename);
extern int Free_List_Rebuild(void);         /*"�����б����¹���"*/
#endif
