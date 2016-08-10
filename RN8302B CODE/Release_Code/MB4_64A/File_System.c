/******************************************************************************************************
                                *  " Name:  File_System.c "      *
                                *"Function: Flash File System  " *
                                *           "   for  new DL_645"      *
********************************************************************************************************/
#include "File_System.h"
#include "LoadRecord.h"
#include "I2C_operation.h"
#include "Eeprom.h"
#include "defmcro.h"
#include "multi.h"
#include "Freeze.h"

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//Function Declare
int Fs_Init(void);
unsigned int Write_File(unsigned int file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
unsigned int Read_File(unsigned int  file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
unsigned int  Delete_File(unsigned int  file_name);
void Fs_Rename(unsigned int src_filename,unsigned int dest_filename);
unsigned char Init_CheckNode(unsigned int page);
void Init_DealNode(unsigned int page);
unsigned char Write_CheckNode(unsigned char *buff,unsigned int page,unsigned char block);
signed int Write_Data(unsigned int *next,unsigned int *page,unsigned char *block);
void Switch_Free_List(unsigned int *next,unsigned int *Fs_Flag);
int Free_List_Rebuild(void);
unsigned char Rebuild_CheckNode(unsigned int page);
void  Rebuild_DealNode(unsigned int page);
void Fs_Protect(unsigned char flag1,unsigned char flag2,unsigned int fs_name,unsigned char mode);
extern void Delay(unsigned int);
extern void show_build_char(void); 
extern void SetNewFlag(unsigned char type);

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//Variable Declare
unsigned char switch_flag,last_block,jump_out;
unsigned int last_node,last_page;
unsigned int good_block[8],Fs_Index_Len[2];
struct Fs_variable_def Fs_variable;
struct Fs_BitFlag fs_bit;
struct Fs_Node fs_node;

extern unsigned char Fs_Buff[528]; 

//Function MainBody
/*"******************************************************************************************************
                                  *"����: �ļ�ϵͳ��ʽ��"*
                                  *"����: ��ʽ���ļ�ϵͳ,��һ���ϵ����"*  
                                  * "1�� ���Ҳ���������"*
                                  * "2�� �����ļ�ϵͳ��������#1 "*
******************************************************************************************************"*/
int Fs_Init(void)
{   

   show_build_char();
   WRLC256(EEPROM_FLAG_ROM+5,0,3,0,0);
	if(Chip_Erase()==-1)/*"FlashӲ���д����ⱨ��"*/
	{
			ALARM_SND=1;
			while(1)
			{     
              ///  LED_ALARM=~LED_ALARM;///king chen mark 121214
                Delay(500);
               	FeedWatchdog();
			}	 
    }
    else
    {
          SetNewFlag(1);
    }
    
    return 0;
}
    
/*"******************************************************************************************************"*/
/*"                                  *   "����: �ļ�д����"*"*/
/*"                                  *   "����: д���¼���¼"*"*/
/*"                                  *   " ����ֵ:�ļ�����------ д��ɹ�          " *"*/
/*"                                  *   "   0 ------ д��ʧ��"*"*/
/*"                                  *   "  0xffff ------ Ӳ����       "*"*/
/*"*******************************************************************************************************"*/
unsigned int Write_File(unsigned int file_name,unsigned int addr,unsigned int offset,unsigned char * buff)
{      
	unsigned char result;
	unsigned int uni,badnum,Ntray;       
    unsigned int file_page;         
    unsigned long file_name_T;
    union FlashAddr32M FlashAddr;

    char vd_check;

    if((file_name>MAX_FILE_FREEZE_NUM)||(offset==0))
        return 0;

    vd_check=int2ic;
    file_name_T=file_name;
    if(file_name_T<MAX_FILE_EVENT_SORT_NUM)
    {
        if((addr+offset)>MAX_BYTE_NUM)
            return 0;

        FlashAddr.addr=FILE_EVENT_SORT_STARTPAGE+(file_name_T<<8);
        FlashAddr.AsByte.Byte0=addr;    
    
        result=1;
        Ntray=0;
        badnum=0;
        while((result==1)&&(badnum<1))
        {
            CheckPowerDown();
            int2ic &= 0xf8;
            //save data
            if(FlashAddr.SectorAddr.Sdummy==0)/*"������"*/
            {
                //if(Check_Sector_Have_Erased(FlashAddr.addr))
                {
                    Sector_Erase(FlashAddr.addr);
                    CheckPowerDown();
                }
            }
           
            if(Write_Page(FlashAddr.addr,buff,offset)!=0)		    
                return 0;
            
            //check data if ok
            //Read_Data_Bytes(FlashAddr.addr,Fs_Buff,offset);

            //if(CompareBytes(Fs_Buff,buff,offset))       
            //    result=1;  
            //else
                result=0; 

            badnum++;
        }
    }
    else if(file_name_T<MAX_FILE_FREEZE_NUM)
    {
        if(((addr+offset)>MAX_BYTE_NUM_FREEZE))//||((addr+offset)<MAX_BYTE_NUM))
            return 0;

        FlashAddr.addr=FILE_FREEZE_SORT_STARTPAGE+((file_name_T-FREEZE_SORT_START_FILE)<<8)*2L;
        FlashAddr.addr+=addr;    
    
        result=1;
        Ntray=0;
        badnum=0;
        while((result==1)&&(badnum<1))
        {
            CheckPowerDown();
            int2ic &= 0xf8;
            //save data
            if(FlashAddr.SectorAddr.Sdummy==0)/*"������"*/
            {/*"��������е�����ô��?"*/
                //if(Check_Sector_Have_Erased(FlashAddr.addr))/*"��Ҫ����ʱ��Ҫ���?"*/
                {
                    Sector_Erase(FlashAddr.addr);
                    CheckPowerDown();
                }
            }

           if(Write_Page(FlashAddr.addr,buff,MAX_BYTE_NUM)!=0)		    
                return 0;

           if((addr+offset)>MAX_BYTE_NUM)
           {/*"һ���ļ�����256�ֽڣ���ҳ"*/
                FlashAddr.PageAddr.Paddr+=1;
                if((FlashAddr.PageAddr.Paddr%PAGE_NUM_PER_SECTOR_EVENT)==0)/*"�ڶ�ҳ��������0"*/
                    return 0;
                FlashAddr.PageAddr.Pdummy=0;
                if(Write_Page(FlashAddr.addr,buff+MAX_BYTE_NUM,offset-MAX_BYTE_NUM)!=0)		    
                    return 0;
           }
            
            //check data if ok
           //Read_Data_Bytes(FlashAddr.addr,Fs_Buff,offset);

           //if(CompareBytes(Fs_Buff,buff,offset))       
           //     result=1;  
           //else
                result=0; 

           badnum++;
        }
    }
    else
        return 0;

    int2ic=vd_check&0x1f;
    
	return offset;
}
/*"*********************************************************************************************************
                                  *   "����: �ļ�������"*
                                  *   " ����: �����¼���¼"*
                                  *   "����ֵ:�ļ�����------ �ɹ�"           *
                                  *   "  0  ------ ����ʧ��"        *
*********************************************************************************************************"*/
unsigned int Read_File(unsigned int  file_name,unsigned int addr,unsigned int offset,unsigned char * buff)
{
	unsigned int page,base_addr,end_addr;  
    unsigned int file_page;          /*"�ļ�����,����"*/
    union FlashAddr32M FlashAddr;
    unsigned long file_name_T;

    file_name_T=file_name;
    if((file_name>=MAX_FILE_FREEZE_NUM)||((addr+offset)>=MAX_BYTE_NUM_FREEZE)||(offset==0))
		 return 0;

    if(file_name_T<MAX_FILE_EVENT_SORT_NUM)
        FlashAddr.addr=FILE_EVENT_SORT_STARTPAGE+(file_name_T<<8);
    else
        FlashAddr.addr=FILE_FREEZE_SORT_STARTPAGE+((file_name_T-FREEZE_SORT_START_FILE)<<8)*2L;

    FlashAddr.addr+=addr;    
    Read_Data_Bytes(FlashAddr.addr,buff,offset);
    FeedWatchdog();
        
	return offset;
    
}
/*"************************************************************************************************************
                                  *   "����: �ļ�ɾ������"*
                                  *   " ����: ɾ���¼���¼"*
                                  *   "����ֵ:�ļ�ռ�鳤��------ �ɹ�          " *
                                  *   " 0  ------ û�и��ļ�   "   *
************************************************************************************************************"*/
unsigned int  Delete_File(unsigned int file_name)
{
    union FlashAddr32M FlashAddr;
    unsigned long file_name_T;
    unsigned int uni,file_num;

    file_name_T=file_name;    
    if(file_name<MAX_FILE_EVENT_SORT_NUM)
    {
        if((file_name%32)!=0)
		 return 0;

        int2ic &=0xf8;
        FlashAddr.addr=FILE_EVENT_SORT_STARTPAGE+(file_name_T<<8);
        FlashAddr.SectorAddr.Sdummy=0;
        Sector_Erase(FlashAddr.addr);
        FlashAddr.SectorAddr.Saddr++;
        Sector_Erase(FlashAddr.addr); 
        int2ic |=0x01;
    }
    else if(file_name<MAX_FILE_FREEZE_NUM)
    {
        if((file_name%8)!=0)
		 return 0;

        int2ic &=0xf8;
        if((file_name<FREEZE_MOMENT_SORT_START_FILE)||
            ((file_name>=FREEZE_DAY_START_FILE)&&(file_name<FREEZE_ENERGYPASSZERO_START_FILE)))
        {
            file_num=MAX_FILE_FREEZE_TIME_SORT_NUM;
        }
		else if (file_name==PROGRAMTRIFF_EVENT_FILE)
		{
			file_num=PROGRAMTRIFF_EVENT_NUMBER;
		}
        else 
        {
            file_num=MAX_FILE_FREEZE_MOMENT_SORT_NUM;
        }
        FlashAddr.addr=FILE_FREEZE_SORT_STARTPAGE;
        FlashAddr.SectorAddr.Sdummy=0;
        FlashAddr.SectorAddr.Saddr+=(file_name_T-FREEZE_SORT_START_FILE)/8;

        file_num=file_num/8;           
        for(uni=0;uni<file_num;uni++)
        {
            Sector_Erase(FlashAddr.addr);
            FlashAddr.SectorAddr.Saddr++;
            FeedWatchdog();
        }
        
        int2ic |=0x01;
    }
    else
    {
       return 0;
    }
    
    return  1;
     
}


/*"***************************"*/
