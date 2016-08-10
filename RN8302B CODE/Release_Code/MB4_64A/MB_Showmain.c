/*" MB2表通用版显示程序 (v0.1 bata0322)  		"*/
/*"液晶屏图号 .122						 		"*/
/*"Creat by TREND 2004-12-01 for shanghai		"*/
/*"Edit  by TREND 2005-03-22 for 通用版 		"*/

//---------------------------------------------------------------------------


//#include "sfr62p.h"
#include "I2C_operation.h"
#include "HT_1623.h"
#include "Demand.h"
#include "showcfg.h"
#include "defdata.h"
#include "defmcro.h"
#include "comm.h" //for TransferData
#include "MB_Showmain.h"
#include "MB_Keymain.h"
#include "ram.h" 
#include "645_2007.h"
#include "MB_Base_Fun.h"
#include "645Data.h" 
#include "interrupt.h"
#include "pay_def.h"								//payment
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "ICcard.h"
#include "Measure_Interface.h" 

#define SELECT_DEVICE1	   		0//: 1st PCF8576
#define SELECT_DEVICE2	   		1//: 2nd PCF8576
#define SELECT_DEVICE3	   		2//: 3rd PCF8576
#pragma SECTION rom UserROMData
const unsigned char FILE_DATE[3]={0x15,0x06,0x28};

#define I_X			0              /*"S2"*/
#define I_Y			0x1            
#define II_X			1		/*"S3"*/
#define II_Y			0x1              
#define III_X			1		/*"S4"*/	
#define III_Y			0x2              
#define IV_X			0		/*"5"*/
#define IV_Y			0x4

#define ONE_X				27		/*"S74 ①"*/
#define ONE_Y				0x1             
#define TWO_X				27		/*"S75 ②"*/
#define TWO_Y				0x2              

#define J_X				17		/*"S51 尖"*/
#define J_Y				0x2
#define F_X				16	/*"S52 峰"*/
#define F_Y				0x2
#define P_X				17		/*"S54 平"*/
#define P_Y				0x8
#define G_X				16		/*"S55 谷"*/
#define G_Y				0x8

//payment
#define FIRST_X				17		/*"S49 第1套梯度"*/
#define FIRST_Y				0x1             
#define SECOND_X			16		/*"S50 第2套梯度"*/
#define SECOND_Y			0x1              

#define STEP1_X				17		/*"S25 梯度1"*/
#define STEP1_Y				0x4
#define STEP2_X				01		/*"S26 梯度2"*/
#define STEP2_Y				0x4
#define STEP3_X				01		/*"S27 梯度3"*/
#define STEP3_Y				0x8
#define STEP4_X				00		/*"S28 梯度4"*/
#define STEP4_Y				0x8


#define BATTERIES1_X	27		/*"S76 BATTERIES1"*/
#define BATTERIES1_Y	0x8                  
#define BATTERIES2_X	24    	/*"S77 BATTERIES2"*/
#define BATTERIES2_Y	0x8                   

#define Ua_X			31	       /*"S64 Ua"*/         
#define Ua_Y			0x1                        
#define Ub_X			31		/*"S65 Ub"*/         
#define Ub_Y			0x2                        
#define Uc_X			31	       /*"S66 Uc"*/         
#define Uc_Y			0x4                      
                                                   
#define Ia_X			29		/*"S69 Ia"*/       
#define Ia_Y			0x4                        
#define Ib_X			26		/*"S71 Ib"*/      
#define Ib_Y			0x8                       
#define Ic_X			27		/*"S73 Ic"*/      
#define Ic_Y			0x4                       
                                                   
#define _Ia_X			28		/*"S68 -Ia"*/ 
#define _Ia_Y			0x4                      
#define _Ib_X			29    	/*"S70-Ib"*/
#define _Ib_Y			0x8                      
#define _Ic_X			26          /*"S72 -Ic"*/
#define _Ic_Y			0X4                       

#define LOCK_X  		       30		/*"S89 LOCK"*/ 
#define LOCK_y  		       0x4                  
#define KEYSTOKE_X 		30    	/*"S88 KEYSTOKE"*/  
#define KEYSTOKE_Y 		0x8                              
#define HOME_X			30      /*"S90 HOME"*/
#define HOME_Y			0x2                 
#define BELL_X			30      /*"S91 BELL"*/ 
#define BELL_Y			0x1      

//#define NOT_ENOUGH_X	6      /*" 赊欠"*/
//#define NOT_ENOUGH_Y	0x4

#define ATHWART_X		31      /*"S67 逆相序"*/
#define ATHWART_Y		0x8


//---------------------------------------------------------------------------
//public funtion
char Show_Main(unsigned long show_code,char *show_buffer,unsigned long user_code,unsigned char user_code_len);
int Show_Initialize(char flag);
char Show_Char_Main(char show_char,char On_Off);
void clear_show_lcd(void);
void tr_show_wait(int time);
void cursor_flash(int cursor);
char show_on_lcd(char* show_ram,int start_add,int len);
char conver_data0(char* show_data,char* show_ram,int start_add,int len);
char conver_data1(char* show_data,char* show_ram,int start_add,int len);
char reconver_char(char show_val,char addr);
char lcd_special_cortrol(char cortrol_code);
void Lcd_Power_On(void);
void Lcd_Power_Off(void);
char show_on_lcd_only_send_data(char* show_ram,int start_add,int len);
//char Disp_Map(unsigned long old_showcode,unsigned long *new_showcode, unsigned char *flag);
void Ascll_Bcd(unsigned char *input,unsigned char *output, int len);
//---------------------------------------------------------------------------
//private funtion
//const struct SHOW_TABLE* search_recoed(unsigned long show_code);
char conver_char(char* show_char,char* show_ram);
void show_user_code(long code,unsigned char code_len,char * char_buf,char* data_buf);
//char set_point(char data_precision,int line,char* point_buf);

int bcd_un_zip(char* input,char* output,int len);
void long_to_bcd(unsigned long input,char* output);
void exchange_data(char *input,char *output,int len);
extern int Check_Data_valid(unsigned char  *buff_t, unsigned char len);

extern void SetShowErrNum(unsigned char *,unsigned char *);  //change by pc 120828	
//---------------------------------------------------------------------------
//public variable
char vram[MAX_LINE_NUM+3][MAX_DATA_NUM];

union Show_falg_word_def Show_flag;
union Show_falg_word_def Show_flash_falg; 
union ERR_INFORM_FLG Err_Infor1_New;
union Show_Err_Code Err_Code;
unsigned char set_cycle_num;

//payment
unsigned long dispCardCharTime=0;
unsigned long dispCardCharTimeLen=0;
unsigned long dispCharHoardTime=0;
unsigned long dispCharHoardTimeLen=0;
unsigned long dispCardDataTime=0;
unsigned long dispCardDataTimeLen=0;
unsigned int meterDispErr_ID=0;         		/*"电能表出错信息码:代号"*/ 
union BYTE_BIT dispPaymentFlag;				/*"BIT0 锁屏显示错误代码时,按键/红外/插卡盘解除"*/ 
union BYTE_BIT dispCharFlag[2];

/*"[0]---------------------------[1]对应位:拨卡是否消失"*/
/*"bit0	1:显示--CARD--"*/
/*"Bit1	1:显示插卡字符"*/
/*"bit2	1:显示卡错误代码	"*/
/*"bit3	1:显示表号H"*/
/*"bit4	1:显示表号L"*/
/*"bit5	1:显示购电前剩余电费"*/
/*"bit6	1:显示欠电费数据		,1:显示囤积字符"*/
/*"bit7	1:显示插用户卡后的剩余电费"*/

char leaf_flag;
char ret_flag;
unsigned char show_mode1;/*"处于新C套显示标志"*/
unsigned char show_leaf_flag;/*"C1套或A套未定义用户代码时显示叶子号的标志"*/
//unsigned char show_mode; /*"新老显示标志"*/
unsigned char fshow_flag;
unsigned char refreshFlag=0;/*"闪烁周期为2秒"*/



#define NOSHOWIDNUM	   	11

#pragma SECTION rom UserROMData
/*"***********"不能显示的项目"***********"*/
const unsigned long NO_SHOW[NOSHOWIDNUM]={0X4000403,0X400040B,0X400040C,0X400040D,0X4800001,0X4800002,0X4800003,0X040005ff,
                                          0x0090E101,0x0090E201,0x04001501};		//payment
//---------------------------------------------------------------------------
//private variable

/*"新旧显示代码映射数据结构"*/
struct SHOW_TABLE{
    unsigned long old_showcode; 
    unsigned long new_showcode;
    unsigned char flag;
};

extern int cyc_show_num;
extern union byte_def key_flag;


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//***************************************************************************
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char Show_Main(unsigned long show_code,char *show_buffer,unsigned long user_code,unsigned char user_code_len)
{
    char show_data_buf[MAX_LINE_NUM+1][MAX_DATA_NUM];    
    char show_char_buf[MAX_CHAR_NUM];    
    char temp_buf[6];  
    char temp_buf1[6];
    char temp[8];
    const struct SHOW_TABLE *p_show_table;
    struct COM_SHOW_TABLE  pcom_show_table;
    char ret,delete_zore_number,no_user_number,sign;
    int i_temp,i_temp_1;
    union byte_def transf_temp;
    union ID  idt;
    char no_this_code=1;                           /*"显示代码不存在*/
    unsigned long new_showcode;
    char flag,point,asc_len,no_del,temp_data;
    signed char trans_exp,trans_exp_org;
	unsigned char Show_Main_T1;
    unsigned char  result;/*"有效数据标识该变量为1，无效数据标识该变量为0"*/
    /*"显示显示代码"*/
    long_to_bcd(show_code,&temp_buf[0]);

    bcd_un_zip(&temp_buf[0],&show_data_buf[1][0],4);
    bcd_un_zip(&temp_buf[0],&temp[0],4);
     /*"高位和叶子号显示初始为空"*/
	 show_data_buf[0][8]=0x13;
	 show_data_buf[1][8]=0x13;
        show_data_buf[1][9]=0x13;
	Show_flash_falg.bit.I  = 0;
	Show_flash_falg.bit.II = 0;
	Show_flash_falg.bit.III= 0;
	Show_flash_falg.bit.IV = 0;
	ret = 0;
       result=0;
	 for(i_temp=0;i_temp<MAX_CHAR_NUM;i_temp++) /*"符号标志清0"*/
       {
    	 show_char_buf[i_temp]=0;	
       }
	  if(show_code==0x0e070002||show_code==0x0e070080||show_code==0x88888888||show_code==0xffffff05 )						
	  {
          result=1;
		   /*"配置文件表中未找到"*/
	   	 if(show_code==0x0e070002)
		   {
			    /*"显示电表版本号"*/
		 	    temp_buf[0]=FILE_DATE[0];						/*"归档时间 年"*/	
		 	   // temp_buf[0]=testID;
			    temp_buf[1]=FILE_DATE[1];						/*"归档时间 月"*/	
			    //temp_buf[1]=testID2;
		    	    temp_buf[2]=FILE_DATE[2];						/*"归档时间 日"*/	
			    temp_buf[3]=I_REGION; 	/*"电流量程"*/
			    temp_buf[4]=V_REGION; 	/*"电压量程"*/
			    bcd_un_zip(&temp_buf[0],&show_data_buf[0][0],3);
			   // bcd_un_zip(&temp_buf[3],&show_data_buf[0][6],2);
			    show_data_buf[0][6]=temp_buf[3];
                         show_data_buf[0][7]=temp_buf[4];
		   }	
                 else if(show_code==0x0e070080)
                 {
                         Err_Infor1_New=Meter_States.Err_Infor;
	                  Err_Infor1_New.bit.VoltageReserve=Err_Infor1_New.bit.Rtc_Err;
	                  Err_Infor1_New.bit.LossVoltage=Err_Infor1_New.bit.OverPower;
	                 Err_Infor1_New.bit.LossCurrent=Err_Infor1_New.bit.BreakPhase;
	                 Err_Infor1_New.bit.BatteryClK_Err=0;
	                 Err_Infor1_New.bit.BatteryDIS_Err=0;
	                 Err_Infor1_New.bit.OverVoltage=0;
                        temp_buf[0]=(char)Err_Infor1_New.intd;
                        show_data_buf[0][7]=temp_buf[0]&0x01;
			   show_data_buf[0][6]=(temp_buf[0]&0x02)>>1;
			   show_data_buf[0][5]=(temp_buf[0]&0x04)>>2;
			   show_data_buf[0][4]=(temp_buf[0]&0x08)>>3;
			   show_data_buf[0][3]=(temp_buf[0]&0x10)>>4;
			   show_data_buf[0][2]=(temp_buf[0]&0x20)>>5;
			   show_data_buf[0][1]=(temp_buf[0]&0x40)>>6;
			   show_data_buf[0][0]=(temp_buf[0]&0x80)>>7;                     
                 }
		  else if(show_code==0x88888888)/*"全屏显示"*/
		  {
		  	  for(i_temp=0;i_temp<13;i_temp++)
			  {
				Show_flash_falg.byte[i_temp]=0;	/*"清闪烁"*/
			  }

                        for(i_temp=0;i_temp<MAX_CHAR_NUM;i_temp++) 
    	                           show_char_buf[i_temp]=0xff;                      
			    for(i_temp_1=0;i_temp_1<MAX_DATA_NUM-1;i_temp_1++)
				     show_data_buf[0][i_temp_1]=0x08;	
			    for(i_temp_1=0;i_temp_1<MAX_DATA_NUM;i_temp_1++)
				     show_data_buf[1][i_temp_1]=0x08;
		  }
		  else if(show_code==0xffffff05) //change by pc 120828
		  {
		  	show_data_buf[0][0]=0x13;
		  	show_data_buf[0][1]=0x13;
		  	show_data_buf[0][2]=0x0e;
		  	show_data_buf[0][3]=0x11;
		  	show_data_buf[0][4]=0x11;
		  	show_data_buf[0][5]=0x10;
		  	SetShowErrNum(&show_data_buf[0][6],&show_data_buf[0][7]);		  	
		  }	
		  
    }
    else
    {
        unsigned int n=0,fflag=0;	
        for(n=0;n<500;n++)
	         Co.b[n]=0;

	i_temp=0;
	idt.l=show_code;
	if((idt.l==0x04000401)||(idt.l==0x04000402)||(idt.l==0x04001104)||(idt.l==0x04800004)||(idt.l==0x0400040E)||(idt.l==0x0400010C)
	||((idt.l&0xffff00ff)==0x00600000)||((idt.l&0xffff00ff)==0x00610000))
	   {
	         if(leaf_flag==0)
	         	leaf_flag=1;
	         else if(leaf_flag==1)
	         	leaf_flag=0;
	   }
	   else if ((idt.l&0xFFFFFF00)==0x03301300)
	   	{
			if(leaf_flag==2)
				leaf_flag=3;
			else if(leaf_flag==3)
				leaf_flag=2;
			else if(leaf_flag==5)
				leaf_flag=6;
			else if(leaf_flag==6)
				leaf_flag=5;
	   	}

	   /*"数据缓冲区只有6个字节，大于6个字节及数据块不显示"*/
	      no_this_code=1;
	      for(n=0;n<NOSHOWIDNUM;n++)	//payment
	      {
	         if(idt.l==NO_SHOW[n]||(idt.l&0xff00)==0xff00||(((idt.l&0xff)==0xff)&&(idt.l!=0x040604ff)&&(idt.l!=0x040605ff)))
	         {
                     ret=0;
                     no_this_code=0;
                    break;
               }
             }

		if((idt.l==0x0090E100)||(idt.l==0x0090E200))	//payment
			{
			idt.l++;	//hex to bcd display
			}
		if(idt.l==0x0090E101||idt.l==0x0090E201)		//payment
			DISP_SIGN_FLAG_DEFINE=1;
		if(idt.l==0x0090E201)
			DISP_MONEY_FLAG_DEFINE=1;
		if(idt.l==0x00900200)
			DISP_PLUS_FLAG_DEFINE=1;
		if(idt.l==0x00900201)
			DISP_NEGA_FLAG_DEFINE=1;

	 if(no_this_code!=0)
        {
           ret=TransferData_New(idt,&temp_buf1[0], (unsigned int)leaf_flag,
               SHOWFORMAT,(unsigned char *)&pcom_show_table, 0x03,0,0x03);
           
          if(ret==0)
          {
            result=0;
            if(IntoPowerDownFlag) 
            {
                if((show_which_now==1)&&(Show_Powerdown_Cyc_Data[cyc_show_num].Show_FlashData_flag.vatiryflag==1))
                    fflag=0xff;
                else if((show_which_now==2)&&(Show_Powerdown_Key_Data[cyc_show_num].Show_FlashData_flag.vatiryflag==1))
                    fflag=0xff;
            }
            if((Show_ID_vatiy==0xff)&&(fflag==0xff))
            { 
                if(show_which_now==1)
                {
                   for(n=0;n<6;n++)
                        temp_buf1[n]=Show_Powerdown_Cyc_Data[cyc_show_num].showbuff[n];
                   pcom_show_table=Show_Powerdown_Cyc_Data[cyc_show_num].Powerdown_show_table;
                   ret=Show_Powerdown_Cyc_Data[cyc_show_num].Show_FlashData_flag.falshDatalen;
                }
                else if(show_which_now==2)
                {
                   for(n=0;n<6;n++)
                        temp_buf1[n]= Show_Powerdown_Key_Data[cyc_show_num].showbuff[n];
                   pcom_show_table=Show_Powerdown_Key_Data[cyc_show_num].Powerdown_show_table;
                   ret=Show_Powerdown_Key_Data[cyc_show_num].Show_FlashData_flag.falshDatalen;
                }
                else
                 ret=0;
             }          
           }
        }

	 if((idt.l==0x04000401)||(idt.l==0x04000402)||(idt.l==0x04001104)||(idt.l==0x04800004)||(idt.l==0x0400040E)||(idt.l==0x0400010C)
	 ||((idt.l&0xffff00ff)==0x00600000)||((idt.l&0xffff00ff)==0x00610000))
	    {
	         if(leaf_flag==0)
	         	leaf_flag=1;
	         else if(leaf_flag==1)
	         	leaf_flag=0;
	    }
	   else if ((idt.l&0xFFFFFF00)==0x03301300)
	   	{
			if(leaf_flag==2)
				leaf_flag=3;
			else if(leaf_flag==3)
				leaf_flag=2;
			else if(leaf_flag==5)
				leaf_flag=6;
			else if(leaf_flag==6)
				leaf_flag=5;
	   	}

	 if(show_leaf_flag==1&&ret!=0)
            bcd_un_zip(&leaf_flag,&show_data_buf[1][8],1);

		if (DISP_MONEY_FLAG_DEFINE)		//payment
			DISP_MONEY_FLAG_DEFINE=0;
		if (DISP_PLUS_FLAG_DEFINE)
			DISP_PLUS_FLAG_DEFINE=0;
		if (DISP_NEGA_FLAG_DEFINE)
			DISP_NEGA_FLAG_DEFINE=0;
		
              if(ret==0)
		{
        	 show_data_buf[i_temp][0]=0x11;
           	 show_data_buf[i_temp][1]=0x0e;	
        	 show_data_buf[i_temp][2]=0x0a;
        	 show_data_buf[i_temp][3]=0x0d;
               show_data_buf[i_temp][4]=0x13;
               show_data_buf[i_temp][5]=0x0e;
        	 show_data_buf[i_temp][6]=0x11;
        	 show_data_buf[i_temp][7]=0x11;
		 for(i_temp=0;i_temp<MAX_CHAR_NUM;i_temp++)				
   		 {
   		       show_char_buf[i_temp]=0;
   		 }   	
        }
	else		  
	{ 
              result=1;
	         exchange_data(&temp_buf1[0],&temp_buf[0],ret);/*"数据顺序整理"*/
        	  /*"*************"显示单位"************"*/
        	  for(n=0;n<UNITLEN;n++) 
        	  {
        	      if(Protocol_Format[pcom_show_table.address0].unit==SHOW_UNIT[n].trans_unit)
        	     	{
        	     	     show_char_buf[6]|=SHOW_UNIT[n].unit[0]; 	
			     show_char_buf[9]|=SHOW_UNIT[n].unit[1]; 	
			      break; 
        	     	} 	  
        	  }

        	  trans_exp=Protocol_Format[pcom_show_table.address0].exp;
		  trans_exp_org=trans_exp;
        	  /*"************"显示小数点"**********"*/ 
        	  if(trans_exp==Mauto)
        	  {
        	  	  ///switch(Meter_Parameter.parameter2.EnergyPoint)
        	  	  ///{
        	  	  ///   case 3: trans_exp=-3;break;
        	  	  ///   case 4: trans_exp=-4;break;
        	  	  ///   default: trans_exp=-2;break;
        	  	  ///}
        	  	if(Meter_Parameter.parameter2.EnergyPoint < 4)
        	  	{
        	  	trans_exp = 0 - Meter_Parameter.parameter2.EnergyPoint;
        	  	}
		       else
			{
			trans_exp = -2;
			}        
        	  }
        	  if(trans_exp==Dauto)
        	  {
        	      ///switch(Meter_Parameter.parameter2.PowerPoint)
        	      ///{
        	      ///   case 2: trans_exp=-2;break;	
        	      ///   case 3: trans_exp=-3;break;
        	      ///   default: trans_exp=-4;break;
        	      ///}
        	    if(Meter_Parameter.parameter2.PowerPoint <= MAXDAUTOVALUE)
        	  	{
        	  	trans_exp = 0 - Meter_Parameter.parameter2.PowerPoint;
        	  	}
		      else
			{
			trans_exp = -4;
			}      
        	  }
			if(trans_exp==RMB_Mauto)	//payment
				{
				if (PRE_MONEY_POINT==2)
					{
					trans_exp=-2;
					if(DISP_SIGN_FLAG_DEFINE)		//display"-0.01"
						{
						DISP_SIGN_FLAG_DEFINE=0;
						if (temp_buf[0]==0xFF && temp_buf[1]==0xFF && temp_buf[2]==0xFF && temp_buf[3]==0xFF)
							{
							temp_buf[0]=0x80;
							temp_buf[1]=0x00;
							temp_buf[2]=0x00;
							temp_buf[3]=0x01;
							}
						}
					}
				else
					{
					trans_exp=0;
					if(DISP_SIGN_FLAG_DEFINE)		//display"-0.01"
						{
						DISP_SIGN_FLAG_DEFINE=0;
						if (temp_buf[0]==0xFF && temp_buf[1]==0xFF && temp_buf[2]==0xFF && temp_buf[3]==0xFF)
							{
							temp_buf[0]=0x00;
							temp_buf[1]=0x00;
							temp_buf[2]=0x00;
							temp_buf[3]=0x00;
							}
						}
					}
				}
        	  point=0;
	         for(n=0;n<EXPLEN;n++)
	         {
	              if(trans_exp==SHOW_POINT[n].trans_exp)
	              {
	                  show_char_buf[13]|=SHOW_POINT[n].point;
	                  point=-SHOW_POINT[n].trans_exp; 
	                  break;	
	              }    	
	         } 		              
           /*"**********"显示数据格式"**********"*/
	     delete_zore_number=0;
            no_user_number=0;
	     sign=0;
            switch (Protocol_Format[pcom_show_table.address0].format)   
            {
                case _NN_H:
		  case _NN_L:
		  	if(_NN_L == Protocol_Format[pcom_show_table.address0].format)
		  	{
		  		show_char_buf[7]|=0x04;/*"负号S53"*/
		  	}
			for(n = 0; n < 3; n++)
			{
			bcd_un_zip(&temp_buf[n],&show_data_buf[i_temp][0 + (n*3)],1);
			}             	
              	show_data_buf[i_temp][2]=0x10;
              	show_data_buf[i_temp][5]=0x10;              	
                break;
                case BCD1BYTE:
	         case SIGNED_CHAR:
		  case UBCD1BYTE:
		  case UNSIGNED_CHAR:
		   	 bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-4],1);
			 if((BCD1BYTE == Protocol_Format[pcom_show_table.address0].format) ||
			     (SIGNED_CHAR == Protocol_Format[pcom_show_table.address0].format))
			 	{
			 	 if(Check_Data_valid(&temp_buf[0],1)==0)
		   	       {
		   	        show_data_buf[i_temp][6]&=0xf7; 
			        sign=1;
			       }
			 	}		   	 
			   delete_zore_number=7-point;
			   no_user_number=MAX_DATA_NUM-4;
		 break;
		  case ID_CODE_ONE_FORMAT: 
		   	      bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-4],1);
		   	      delete_zore_number=6;
			      no_user_number=MAX_DATA_NUM-4;
		   break;		 
               case BCD2BYTE:
	        case SIGNED_INT: 
		 case UBCD2BYTE:
		 case UNSIGNED_INT: 
		 	    bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-6],2);
			    if((BCD2BYTE == Protocol_Format[pcom_show_table.address0].format) ||
			     (SIGNED_INT == Protocol_Format[pcom_show_table.address0].format))
			    	{
			    	if(Check_Data_valid(&temp_buf[0],2)==0)
		 	       {
		 	          show_data_buf[i_temp][4]&=0xf7;
		 	          sign=1; 
		 	        }
			    	}
		   	      delete_zore_number=7-point;
			      no_user_number=MAX_DATA_NUM-6;
		   break;
		  case ID_CODE_TWO_FORMAT: 
		   	      bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-6],2);
		   	      delete_zore_number=4;
			      no_user_number=MAX_DATA_NUM-6;
		   break;
		   case BCD3BYTE:
		   case UBCD3BYTE:
		   case THREE_BYTE:
		  	     bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-8],3);
			     if(BCD3BYTE == Protocol_Format[pcom_show_table.address0].format)
			     {
			     	if(Check_Data_valid(&temp_buf[0],3)==0)
		   	       {
		   	           show_data_buf[i_temp][2]&=0xf7; 
		   	           sign=1;
		   	        }
			     }
		   	      delete_zore_number=7-point;
			      no_user_number=MAX_DATA_NUM-8;
		    break;
                   case BCD4BYTE:
		     case SIGNED_LONG: 
		     case UBCD4BYTE:
		     case UNSIGNED_LONG:	
		   	      bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-10],4);
			      if((BCD4BYTE == Protocol_Format[pcom_show_table.address0].format) ||
			     (SIGNED_LONG == Protocol_Format[pcom_show_table.address0].format))
			     {
			      	if(Check_Data_valid(&temp_buf[0],4)==0)
		   	       {
		   	             show_data_buf[i_temp][0]&=0xf7; 
		   	             sign=1;
		   	       }
			     }
		   	     delete_zore_number=7-point;
			     no_user_number=MAX_DATA_NUM-10;
		     break;		     
			case ID_CODE_FOUR_FORMAT:
		   	       bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-10],4);
		   	       delete_zore_number=0;
			       no_user_number=MAX_DATA_NUM-10;
			       sign=0;
		     break;
		     case SHOW_CODE:
		             bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-10],4);
                           bcd_un_zip(&temp_buf[4],&show_data_buf[1][MAX_DATA_NUM-2],1);
		     break;
		     case _YYMMDDHHMM:     /*"年月日时分"*/              
		     case _YYMMDDHHMMSS: 
		   	       bcd_un_zip(&temp_buf[1],&show_data_buf[i_temp][MAX_DATA_NUM-10],4); 
                            /*"显示小数点"*/
                            show_char_buf[13]|=0x2c;       /*" dp2、dp5、dp8"*/
		     break;
		     case _WW_YYMMDD: /*"周年月日"*/
			       bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-8],3);
                            show_data_buf[i_temp][0]=temp_buf[3];
			       show_data_buf[i_temp][1]=0x13; 
                            /*"显示小数点"*/
		              show_char_buf[13]|=0x28;         /*"dp5、dp8"*/
		      break;	
                    case  _MMDDHHMM:	/*"月日时分"*/
                            bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-10],4);  
		              /*"显示小数点"*/
		              show_char_buf[13]|=0x2c;       /*" dp2、dp5、dp8"*/
		      break;
		      case _HHMMSS:
			  	if(Meter_Parameter.parameter1.MeterMode[1].bit.b2==1)
			  	{					
					show_char_buf[13]|=0x80;//DP7
			  	}
				show_char_buf[13]|=0x20;       /*"dp8"*/
				if((idt.l&0xFF000000)==0x01000000)/*"需量发生时间显示格式，只显示时分"*/
				{
				    bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][4],2);
              	           delete_zore_number=MAX_DATA_NUM-6;
              	           no_user_number=MAX_DATA_NUM-6;
				    
				}
				else                                          /*"其他时间显示格式，显示时分秒"*/
				{
					bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][2],3);
              	              delete_zore_number=MAX_DATA_NUM-8;
              	              no_user_number=MAX_DATA_NUM-8;
					if(Meter_Parameter.parameter1.MeterMode[1].bit.b2==1)
				      {
				           show_char_buf[3]|=0x80;//DP4
				      }
				      show_char_buf[13]|=0x08;       /*"dp5"*/
				}
	              if((idt.l==0x04000101)||(idt.l==0x04000102)||(idt.l==0x0400010C))
                    {
        	             show_char_buf[14]|=0x01;  //add by pc 120509
                     }
			break;
                    case _YYMMDD:
				case _DDHHMM:
				if( ((idt.l==0x04000101)||((idt.l==0x0400010C)&&(Protocol_Format[pcom_show_table.address0].format== _YYMMDD ))) 
				&& (Meter_Parameter.parameter1.MeterMode[1].bit.b3) )
					{
					Show_Main_T1 = MAX_DATA_NUM-10;
					}
				else
					{
					Show_Main_T1 = MAX_DATA_NUM-8;
					}
					
			       bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][Show_Main_T1],3);
              	       delete_zore_number=Show_Main_T1;
              	       no_user_number=Show_Main_T1;

			if( Show_Main_T1==(MAX_DATA_NUM-10))
				{
                            	show_data_buf[i_temp][6]=0x13;
			        show_data_buf[i_temp][7]=softdate.Week;
				show_char_buf[13]|=0x0C;      	/*"dp5、dp2"*/
				}
			else
				{
				show_char_buf[13]|=0x28;       /*"dp5、dp8"*/
				}
		               /*"显示小数点"*/
                           // show_char_buf[3]|=0x80;       /*"dp4"*/
                   
        if((idt.l==0x04000101)||(idt.l==0x04000102)||(idt.l==0x0400010C))
        {
        	show_char_buf[14]|=0x01;  //add by pc 120509
        }
        
                   break;
                   case _MMDD:
		     case _DDHH:
			       bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-6],1);
			       //show_data_buf[i_temp][5]=0x10;
			       bcd_un_zip(&temp_buf[1],&show_data_buf[i_temp][MAX_DATA_NUM-4],1);
              	       delete_zore_number=MAX_DATA_NUM-6;
              	       no_user_number=MAX_DATA_NUM-6;
              	       sign=0;  
				show_char_buf[13]|=0x20;
		     break;
		     case _HHMM:
			 	bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][MAX_DATA_NUM-6],2);
              	       delete_zore_number=MAX_DATA_NUM-6;
              	       no_user_number=MAX_DATA_NUM-6;
              	       sign=0;  
				if(Meter_Parameter.parameter1.MeterMode[1].bit.b2==1)
			  	{					
					show_char_buf[13]|=0x80;//DP7
			  	}
				show_char_buf[13]|=0x20;//DP8
			 	break;
		     case _NN_MMDD:
		     case _NN_HHMM:
			 	for(n = 0; n < 3; n++)
			       {
			       bcd_un_zip(&temp_buf[n],&show_data_buf[i_temp][0 + (n*3)],1);
			       }         
			       show_data_buf[i_temp][2]=0x10;     /*"-"*/
			       show_data_buf[i_temp][5]=0x10;     /*"-"*/
		      break;
		      case _NN_YYMMDD:
			        bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][0],4);    
		               /*"显示小数点"*/
		               if(idt.l!=0xe000207)
		               {
			             show_char_buf[13]|=0x2c;       /*" dp2、dp5、dp8"*/
			        }
				 else
				{
					show_data_buf[i_temp][2]=0x13;
					show_data_buf[i_temp][3]=0x13;
				}
		      break;
		      case ASCII_SIX_LENGTH:
				point=0;asc_len=0;flag=0;
				Ascll_Bcd((unsigned char *)&temp_buf[0],(unsigned char *)&temp_buf1[0], ret); 
				if(idt.l==0x4000404)   /*"额定电压"*/
					show_char_buf[6]|=0x40; 	/*"V"*/
				else if((idt.l==0x4000405)||(idt.l==0x4000406)) /*"额定电流、最大电流"*/
				{
					show_char_buf[6]|=0x20;/*"A"*/
				}
				for(n=0;n<6;n++)
				{
					if(temp_buf1[n]>=0x0a&&temp_buf1[n]!=46)
						break;
					else
						asc_len++;
					if(temp_buf1[n]==46)
						point=n;
				}
				if(asc_len==0)
				{
					for(n=0;n<7;n++)
						show_data_buf[i_temp][n]=19;					
					show_data_buf[i_temp][7]=0;
					break;
				}
				for(n=0;n<asc_len;n++)
				{
					if(point==0)
						show_data_buf[i_temp][8-asc_len+n]=temp_buf1[n];
					else
					{
						if(n<point)
							show_data_buf[i_temp][9-asc_len+n]=temp_buf1[n];
						else if(n>point)
							show_data_buf[i_temp][9-asc_len+n-1]=temp_buf1[n];
					}
				}
				if(point!=0)
				{
					point=asc_len-point-1;
					for(n=0;n<point;n++)
					{
						if(temp_buf1[n]!=0)
							flag=1;	
					}
					if(flag==0)
						delete_zore_number=6;
					else
						delete_zore_number=7;
					no_user_number=9-asc_len;
					switch(point)
					{
						case 1: show_char_buf[13]|=0x40; break;   /*"dp9"*/
						case 2: show_char_buf[13]|=0x20; break;   /*"dp8"*/
						case 3: show_char_buf[13]|=0x10; break;   /*"dp6"*/
						default: break;
					}
				}
				else
				{
					delete_zore_number=7;
					no_user_number=8-asc_len;
				}				 
		     break;
		     case ASCII_FOUR_LENGTH:
          			point=0;flag=0,asc_len=0;
                            Ascll_Bcd((unsigned char *)&temp_buf[0],(unsigned char *)&temp_buf1[0],ret);
                            show_data_buf[i_temp][7]=19;
				for(n=0;n<4;n++)
				{
				       if(temp_buf1[n]==83||temp_buf1[n]==115)
      						 flag=1;
				   	if(temp_buf1[n]>=0x0a&&temp_buf1[n]!=46) 
				    		 break;
					else asc_len++;
					if(temp_buf1[n]==46)
      					       point=n;
				}
			 	 if(asc_len==0||temp_buf1[1]!=46)
			  	{
			     		for(n=0;n<5;n++)
   						 show_data_buf[i_temp][n]=19;
   					if(temp_buf1[0]<0x0a)
   						show_data_buf[i_temp][5]=temp_buf1[0];
   					else
   					       show_data_buf[i_temp][5]=0;
  					 show_data_buf[i_temp][6]=0;
					 show_char_buf[13]|=0x20;   /*"dp8"*/  
					break;
			 	 }
			  	 if(flag==0)
			   		show_char_buf[13]|=0x20;   /*"dp8"*/
			   	 else
			   	 {
			   	       show_char_buf[13]|=0x10;   /*"dp6"*/
			   		show_data_buf[i_temp][6]=0x13;
			   	 }
                             if(temp_buf1[0]<0x0a)
				       show_data_buf[i_temp][5-flag]=temp_buf1[0];
				 else
				       show_data_buf[i_temp][5-flag]=19;
				 if(temp_buf1[2]<0x0a)
				       show_data_buf[i_temp][6-flag]=temp_buf1[2];
			        else
				       show_data_buf[i_temp][6-flag]=19;
				  if(temp_buf1[3]<0x0a)
				       show_data_buf[i_temp][7-flag]=temp_buf1[3];
				  else
				     	show_data_buf[i_temp][7-flag]=19;
			   	  no_user_number=5-flag;	      	
	      	                delete_zore_number=5-flag;
		       break;
                   default:
                            bcd_un_zip(&temp_buf[0],&show_data_buf[i_temp][0],4);
                            delete_zore_number=7-point;
            }
           /*"波特率"*/
           if((idt.l&0xfffffff0)==0x4000700)
           {
                show_data_buf[i_temp][3]=19;
           	  switch(temp_buf1[0])
           	  {
           	     case 0x20: 				 	 
					show_data_buf[i_temp][4]=9;
                                   show_data_buf[i_temp][5]=6;
					break;
           	     case 0x10: 
					show_data_buf[i_temp][4]=4;
           	                     show_data_buf[i_temp][5]=8;
					break;
           	     case 0x08: 
				       show_data_buf[i_temp][4]=2;
           	                     show_data_buf[i_temp][5]=4;
					break;
           	     case 0x04: 
					show_data_buf[i_temp][4]=1;
           	                     show_data_buf[i_temp][5]=2;
					break;
           	     default: 
				 	show_data_buf[i_temp][4]=2;
           	                     show_data_buf[i_temp][5]=4;
				 	break;
           	  }
           	  show_data_buf[i_temp][6]=0;
           	  show_data_buf[i_temp][7]=0;
           	  delete_zore_number=3;
           	  no_user_number=3;
           }
	     if(Meter_Parameter.parameter1.MeterMode[3].bit.b3==0)
            {
           		/*"前面没有数据的清0"*/
		     for(n=0;n<no_user_number;n++)					
                  {
            		 show_data_buf[i_temp][n]=0;	
            	     }
				      /*"去掉前导0"*/
           	     for(n=0;n<delete_zore_number;n++)
           	     {
           		    if(show_data_buf[i_temp][n]==0)
           		    {
           			   show_data_buf[i_temp][n]=0x13;
           		    }
           		    else
           		    {
           			   break;
           		    }
           	     }
             }
            else
            {
           	    for(n=0;n<no_user_number;n++)					
            	    {
            		 show_data_buf[i_temp][n]=0x13;	
            	    }
           }

		if((Meter_Parameter.parameter1.MeterMode[2].bit.b7 == 1) && (idt.l==0x00900201)&&(Pre_Power_Down_Save_Data.Remain_Money<0))	/*"透支金额前面显示负号(有透支时)"*/
		   {
			   sign=1;
		   }
		
	if (SpicReq_SC_DEFINE)	 /*"四川要求: 显示当前剩余电费字符,并固定显示为-"*/
	{
		if (idt.l==0x00900201)
			{
			sign=1;					/*"显示为-"*/
			show_char_buf[14]|=0x01;	/*"显示当前"*/
			 show_char_buf[2]|=0x04;	/*"显示剩余"*/
			}
	}
			
			     /*"在有效整数前一位加负号"*/
           if(sign==1)
           {
            	  if( ((temp_buf[0]&0x80)!=0)||(idt.l==0x00900201) )
            	  {
            	      	if(((A_UNIT==Protocol_Format[pcom_show_table.address0].unit)&&(BCD3BYTE==Protocol_Format[pcom_show_table.address0].format))
                       ||((KW_UNIT==Protocol_Format[pcom_show_table.address0].unit)&&(BCD4BYTE==Protocol_Format[pcom_show_table.address0].format))
            	         ||((KVAR_UNIT==Protocol_Format[pcom_show_table.address0].unit)&&(BCD4BYTE==Protocol_Format[pcom_show_table.address0].format))
            	         ||((KVA_UNIT==Protocol_Format[pcom_show_table.address0].unit)&&(BCD4BYTE==Protocol_Format[pcom_show_table.address0].format))
            	         ||(0xc0==(Protocol_Showinfo[pcom_show_table.address1].schar[1]&0xc0)))  
            	        {                         
            	         show_char_buf[2]|=0x12;
            	        }
                      else
                      {
                      if(show_data_buf[i_temp][0]>0&&show_data_buf[i_temp][0]<=7)
                          show_char_buf[7]|=0x04;
                      else
                      {
            		        if(n!=0)
            		        {
            			      show_data_buf[i_temp][n-1]=0x10;
            		        }
            		        else
            		       {
            			     show_data_buf[i_temp][n]=0x10;
            		       }
                      }
            	      	  }
			//if(idt.l>=0x02020100 && idt.l<=0x02050300)/*"电流和功率点亮反向字符"*/
			//	show_char_buf[2]|=0x12;
            	  }   
           }

	  		//payment	//add 1-
		 	//if ((idt.l&0xFFFFFF00==0x04060400)		// 1st setp energy/price
			//	||(idt.l&0xFFFFFF00==0x04060500))	// 2st setp energy/price
			//	{
			//	temp_data=(char)(idt.l&0xFF);
			//	bcd_un_zip(&temp_data,&show_data_buf[i_temp][0],1);
			//	show_data_buf[i_temp][0]=show_data_buf[i_temp][1];
			//	show_data_buf[i_temp][1]=0x10;
			//	}

			show_data_buf[i_temp][8]=0x13;

			/*"显示费率"*/
	  if((Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x80)!=0)
	  {
                if(temp[5]!=0)					/*"不是总电量"*/
	  	  {
		       switch((Meter_Parameter.parameter2.JFPG_ExpressTriff[temp[5]-1]))//(temp[5])
		       {
                          case 1:  show_char_buf[4]|=0x02;break;    /*"尖S21"*/
                          case 2:  show_char_buf[4]|=0x01;break;    /*"峰S22"*/
                          case 3:  show_char_buf[5]|=0x10;break;    /*"平S23"*/
                          case 4:  show_char_buf[5]|=0x20;break;    /*"谷S24"*/
                          default: break;
                     }
		  }
		  else
		  {
			    show_char_buf[4]|=0x20;			    /*"点亮'总' S20"*/
		  }
         }

	  /*"尖,峰,平,谷电价"*/	//payment
	if ((idt.l&0xffffff00)==0x04050100 || (idt.l&0xffffff00)==0x04050200 || (idt.l&0xffffff00)==0x0400EC00)
		{
		temp_data=(char)(idt.l&0xFF); /*"防止04050111等显示出费率字符"*/
		switch (temp_data)		
			{
			case 1:  show_char_buf[4]|=0x02;break;    /*"尖S21"*/
			case 2:  show_char_buf[4]|=0x01;break;    /*"峰S22"*/
			case 3:  show_char_buf[5]|=0x10;break;    /*"平S23"*/
			case 4:  show_char_buf[5]|=0x20;break;    /*"谷S24"*/
			}
		}
	/*"本月、上月、上上月，上x月"*/
	  if((Protocol_Showinfo[pcom_show_table.address1].schar[3]&0x01)!=0)
	  {
		 if(temp[7]==0)					    /*"当前"*/
		 {
		       show_char_buf[14]|=0x01;		   /*"点亮'当前' s6"*/
  //                   show_char_buf[1]|=0x02;              /*"点亮'月's9"*/
		       show_data_buf[0][8]=0x13;
  			if (idt.l==0x000B0000)			/*"天津站要求:当前1月总用电量"*/	//payment
				show_char_buf[1]|=0x80;	/*"点亮'1' s8"*/
		 }
		 else
	        {
		       show_data_buf[0][8]=temp[7]%10;/*"1号8字等于显示代码第3位"*/	
		       if((temp[7]/10)==1)
			{
			     show_char_buf[1]|=0x80;					/*"点亮'1' s8"*/
		       }
		       show_char_buf[14]|=0x02;						/*"点亮'上' s7"*/
		       show_char_buf[1]|=0x02;  				/*"点亮'月' s9"*/	
		 }	
	   }
	  else if ((Protocol_Showinfo[pcom_show_table.address1].schar[3]&0x02)!=0)/*"上x"*/
	  {
		  
		  show_char_buf[14]|=0x02;						/*"点亮'上' s7"*/
		  show_data_buf[0][8]=temp[7]%10;                       /*"1号8字等于显示代码第3位"*/	
		  if((temp[7]/10)==1)
		  {
			  show_char_buf[1]|=0x80;					/*"点亮'1' s8"*/
		  }
	  }	
	  else
	  {
		   show_data_buf[0][8]=0x13;	
	  }

	   /*"组合无功或正向无功、反向无功"*/
	  if((Protocol_Showinfo[pcom_show_table.address1].schar[0]&0x01)!=0)/*"组合"*/
	  {
	  	    if((Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x01)!=0)/*"1"*/
	  	    {
			   if(Meter_Parameter.parameter1.MeterMode[3].bit.b4==1)			/*"如果模式字4 bit4为1,显示正向"*/
			   {
				    show_char_buf[2]|=0x22;						/*"点亮'正' s12 '向'S13"*/
			   }
			   else
			   {
				    show_char_buf[1]|=0x01;	/*"组合S10"*/					
				    show_char_buf[3]|=0x01;	/*"I   S18"*/						
			   }
	  	    }
		    else if((Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x02)!=0)/*"2"*/
		    {
			   if(Meter_Parameter.parameter1.MeterMode[3].bit.b4==1)			/*"如果模式字4 bit4为1,显示正向"*/
			   {
				    show_char_buf[2]|=0x12;						/*"点亮'反' s12 '向'S13"*/
			   }
			   else
			   {
				    show_char_buf[1]|=0x01;	/*"组合S10"*/					
				    show_char_buf[3]|=0x02;	/*"II  S17"*/						
			   }
		    }
		    else if(((Protocol_Showinfo[pcom_show_table.address1].schar[0]&0x01)!=0) 
				&& (Meter_Parameter.parameter1.MeterMode[3].bit.b5==1))
			   show_char_buf[1]|=0x01;	/*"组合S10"*/	
			   /*"20120726mw组合有功显示组合受模式字4 b5位控制"*/
	  }
	  else
	  {
	  	    if((Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x01)!=0)
				    show_char_buf[3]|=0x01;	/*"I   S18"*/						
		    if((Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x02)!=0)
				    show_char_buf[3]|=0x02;	/*"II  S17"*/						
	  }

	  show_char_buf[1]|=(Protocol_Showinfo[pcom_show_table.address1].schar[0]&0x0e); 
        show_char_buf[14]|=((Protocol_Showinfo[pcom_show_table.address1].schar[0]&0xf0)>>4); 
        show_char_buf[2]|=Protocol_Showinfo[pcom_show_table.address1].schar[1]; 
        show_char_buf[3]|=(Protocol_Showinfo[pcom_show_table.address1].schar[2]&0x7c); 
        show_char_buf[4]|=(Protocol_Showinfo[pcom_show_table.address1].schar[3]&0xfc); 
        show_char_buf[5]|=(Protocol_Showinfo[pcom_show_table.address1].schar[4]&0xce); 

	if (DISP_MYRIAD_FLAG_DEFINE)	//payment
		{
		DISP_MYRIAD_FLAG_DEFINE=0;
		if (trans_exp_org==RMB_Mauto)
			show_char_buf[5]|=0x01;
		}
	if ((idt.l&0xfffff0ff)==0x040600ff)	/*"显示阶梯参数时,用第一行的8字对应显示第几阶梯数据"*/
		{
		if (leaf_flag<0x0D)	/*"仅梯度电量和电价显示8，结算日不显示"*/
			{
			if (leaf_flag>0x05)	/*"阶梯电价"*/
				show_data_buf[0][8]=leaf_flag-0x05;                       /*"1号8字显示"*/
			else				/*"阶梯电量"*/
				show_data_buf[0][8]=leaf_flag+1;
			}
		}

	 /*"显示无功电量的时候现实无功组合方式"*/
	  if((Protocol_Showinfo[pcom_show_table.address1].schar[4]&0x01)!=0)/*"配置表中Flag3为是否需要闪烁象限组合标志"*/
	  {
		   if((temp[3]%2)==1)/*"组合无功1"*/
		   {
	//		   if(Meter_Parameter.MeterMode[3].bit.b7==1)
			    {	
				     Show_flash_falg.bit.I=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b0|Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b1;
				     Show_flash_falg.bit.II=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b2|Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b3;
				     Show_flash_falg.bit.III=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b4|Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b5;
				     Show_flash_falg.bit.IV=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b6|Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.bit.b7;
			    }
		    	
			    Show_flag.bit.I=0;
			    Show_flag.bit.II=0;
			    Show_flag.bit.III=0;
			    Show_flag.bit.IV=0;
		   }		
		   else/*"组合无功2"*/
		   {
	//		    if(Meter_Parameter.MeterMode[3].bit.b7==1)
			    {
				     Show_flash_falg.bit.I=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b0|Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b1;
				     Show_flash_falg.bit.II=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b2|Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b3;
				     Show_flash_falg.bit.III=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b4|Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b5;
				     Show_flash_falg.bit.IV=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b6|Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.bit.b7;
			    }
		     /* else
			    {
				     Show_flash_falg.bit.I=Meter_Parameter.REActivem_Erengy_2_Mode.bit.b0|Meter_Parameter.REActivem_Erengy_2_Mode.bit.b1;
				     Show_flash_falg.bit.IV=Meter_Parameter.REActivem_Erengy_2_Mode.bit.b2|Meter_Parameter.REActivem_Erengy_2_Mode.bit.b3;
				     Show_flash_falg.bit.III=Meter_Parameter.REActivem_Erengy_2_Mode.bit.b4|Meter_Parameter.REActivem_Erengy_2_Mode.bit.b5;
				     Show_flash_falg.bit.II=Meter_Parameter.REActivem_Erengy_2_Mode.bit.b6|Meter_Parameter.REActivem_Erengy_2_Mode.bit.b7;
			    }*/
		 	    Show_flag.bit.I=0;
			    Show_flag.bit.II=0;
			    Show_flag.bit.III=0;
			    Show_flag.bit.IV=0;	
		   }		
		 
	  }
	  else
	  {
		   Show_flash_falg.bit.I  = 0;
		   Show_flash_falg.bit.II = 0;
		   Show_flash_falg.bit.III= 0;
		   Show_flash_falg.bit.IV = 0;	
	  }
	  
        }
		
    }

   	/*"显示用户定义显示代码"*/
       show_user_code(user_code,user_code_len,&show_char_buf[0],&show_data_buf[1][0]);
       conver_data0(&show_data_buf[0][0],show_buffer,0,MAX_DATA_NUM-1);				/*"9个 1->9"*/
       conver_data1(&show_data_buf[1][0],show_buffer+2*(MAX_DATA_NUM-2),0,MAX_DATA_NUM+1);	/*"10个 10->19"*/
       conver_char(&show_char_buf[0],show_buffer);

	  if((ret!=0x00)&&(show_mode1==1))
        {
	     leaf_flag++;
	     ret_flag=TransferData_New(idt,&temp_buf1[0], (unsigned int)leaf_flag,
                SHOWFORMAT,(unsigned char *)&pcom_show_table, 0x03,0,0x03);    /*"判断同节点的下一叶子是否存在"*/    
	     leaf_flag--;
	  }
      if(0 ==result)
        return 2;
      else
        return 0;
}

/*"*****************************************************************************************************
                    *"    名称: 显示代码映射函数    "*
                    *"    功能: 将老显示代码中电量、需量及需量 "*
                    *"                 时间代码映射为新显示代码  "*
                    *"    参数: old_showcode---老显示代码,*new_showcode---新显示代码, "*
                    *"                *flag---需量及需量时间标志:0, 需量,   1, 需量时间  "*
                    *"    返回值: 1, 是电量、需量及需量时间老显示代码  0, 不是"*
******************************************************************************************************"*/
//char Disp_Map(unsigned long old_showcode,unsigned long *new_showcode, unsigned char *flag)
//{
//	  unsigned char showcode,*pointer,temp;
	  
//	  pointer=(unsigned char *)&old_showcode;
//	  *flag=0;
//	  if(*(pointer+3)!=0x00)
//	  {
//	  	 return 0;
//	  }
//	  if((*(pointer+2)&0xff)<0x03)
//	  {
//	  	 showcode=*(pointer+1);
//   	 showcode=(showcode&0xf0)>>4;                   
//    	 *(unsigned char *)new_showcode=showcode;    /*"时间赋值给新显示代码的第1位"*/
//    	 showcode=*pointer&0x0f;
//    	 *((unsigned char *)new_showcode+1)=showcode;  /*"费率赋值给新显示代码第2位"*/
//    	 temp=*(pointer+1)&0x0f;
//    	 showcode=(*pointer&0xf0)>>4;
    	 
    	 
//       if(*(pointer+2)==0x00)	  /*"电量"*/
 //      {     
 //       	if((*(pointer+1)&0xf0)>0xc0)                 /*"上xx月不超过12"*/
 //       	{
 //       	   return 0; 
 //       	}                      
 //   	    *((unsigned char *)new_showcode+3)=0x00;  /*"0x00赋值给新显示代码第4位"*/
 //   	    if(temp==0) 
  //  	    {  
 //   	       if((*((unsigned char *)new_showcode+1)>0x08)||((*pointer&0xf0)>0x70))
//    	       {
//    	       	  return 0;
//    	       }
//             if(showcode==0x01) *((unsigned char *)new_showcode+2)=0x03;
//             else if(showcode==0x02) *((unsigned char *)new_showcode+2)=0x02;
 //            else *((unsigned char *)new_showcode+2)=showcode+0x01;
 //   	    }
 //         else
 //         {
 //            if(((*pointer&0xf0)>0x30)||((*pointer&0x0f)!=0))
 //            {
 //            	  return 0;
 //            }
 //            switch(temp)
  //           {
  //              case 0x01: if(showcode==0x01) *((unsigned char *)new_showcode+2)=0x17;         
  //          	             else if(showcode==0x02) *((unsigned char *)new_showcode+2)=0x16;
 //           	             else *((unsigned char *)new_showcode+2)=0x15+showcode;
  //          	  break;
 //           	  case 0x02: if(showcode==0x01) *((unsigned char *)new_showcode+2)=0x2b;
 //           	             else if(showcode==0x02) *((unsigned char *)new_showcode+2)=0x2a;
 //           	             else *((unsigned char *)new_showcode+2)=0x29+showcode;
  //          	  break;
  //          	  case 0x03: if(showcode==0x01) *((unsigned char *)new_showcode+2)=0x3f;
  //          	             else if(showcode==0x02) *((unsigned char *)new_showcode+2)=0x3e;
  //          	             else *((unsigned char *)new_showcode+2)=0x3d+showcode;
 //           	  break;
 //           	  default: return 0;
 //            }
 //         }       
 //      }
       
       
 //      else if((*(pointer+2)==0x01)||(*(pointer+2)==0x02))   /*"需量及需量时间"*/
  //     {
  //      	if((*(pointer+1)&0xf0)>0x30||((*pointer&0x0f)>0x08)||((*pointer&0xf0)>0x30)||(*(pointer+1)&0x0f)!=0x00)   
  //      	{
  //      	   return 0; 
  //      	}               
  //  	    *((unsigned char *)new_showcode+3)=0x01;  /*"0x01赋值给新显示代码第4位"*/
 //   	    if((*(pointer+2)&0x0f)==0x02)
 //   	    {
 //  	   	   *flag=1;        /*"1：需量时间"*/
 //   	   	}
 //   	    if(showcode==0x01) *((unsigned char *)new_showcode+2)=0x03;
 //   	    else if(showcode==0x02) *((unsigned char *)new_showcode+2)=0x02;
 //   	    else *((unsigned char *)new_showcode+2)=showcode+0x01;
 //      }
  //  }
//	else if(*(pointer+2)==0x08)	  //payment		/*"预付费"*/
//		{
//			if(*(pointer+1)>=0x10 && *(pointer+1)<=0xA0)	  /*"购电记录"*/
//				{
//				if ((*(pointer+1)&0x0F)>=0 || *(pointer)<=1 || *(pointer)>=7)
//					return 0;
//				*((unsigned char *)new_showcode+3)=0x07;
//				*((unsigned char *)new_showcode+2)=0x04;
//				*((unsigned char *)new_showcode+1)=*(pointer)-1;
//				*((unsigned char *)new_showcode+0)=*(pointer+1)>>4;
//				}
//			else if(*(pointer+1)>=0x01 && *(pointer+1)<=0x02)	  /*"费率"*/
//				{
//				if (*(pointer)<=0 || *(pointer)>=MAXTRIFF)
//					return 0;
//				*((unsigned char *)new_showcode+3)=0x04;
//				*((unsigned char *)new_showcode+2)=0x05;
//				*((unsigned char *)new_showcode+1)=*(pointer+1);
//				*((unsigned char *)new_showcode+0)=*(pointer);
//				}
//			else
//				 return 0;
//		}
//    else
//    {
//    	 return 0;
//    }
//    return 1;
//}

/*"ASCLL 码转换成HEX码"*/
void Ascll_Bcd(unsigned char *input,unsigned char *output,int len)
{
   unsigned char i;
   
   for(i=0;i<len;i++)
   {       
      if((*(input+i)<58)&&(*(input+i)>47))    /*"0~9"*/
      {
         *(output+i)=*(input+i)-48;
      }
      else if((*(input+i)<70)&&(*(input+i)>64))  /*"A~F"*/
      {
         *(output+i)=*(input+i)-55;
      }
      else if((*(input+i)==46)||(*(input+i)==83)||(*(input+i)==115))  /*"	ASCLL码NUL,小数点，S"*/  
      {            
	    *(output+i)=*(input+i); 
      }
      else 
      {
         *(output+i)=32;
      } 
   }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//char set_point(char data_precision,int line,char* point_buf)
//{
//	/*char ret;
//	ret=0;
//	switch (data_precision)
//	{
//		case bcd8d2:
//			ret=0x40;
//			break;
//		case bcd8d3:
//			if (line==0)
//				ret=0x0;
//			break;	
//		case bcd8d4:
//			if (line!=0)
//				ret=0x10;
//			break;
//		case None:
//			ret=0x00;
//			break;
//		
//	}
//	return ret;*/
//}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//search show table from show config file
/*"在配置文件表中寻找对应show_code的纪录"*/
/*"没有找到相应的纪录,返回NULL"*/
/*"找到相应的纪录，返回对应纪录的指针"*/
/*"采用二分法查找，配置文件以show_code为索引由小到大已经排序"*/
//const struct SHOW_TABLE* search_recoed(unsigned long show_code)
//{
//	const struct SHOW_TABLE *p_show_table_head,*p_show_table_tail,*p_show_table_mid;
//	unsigned long l_table_len;
//	unsigned long temp;
	//const char * cp_temp;
	
	
//	l_table_len=SHOWTABLELEN;                          	/*"得到配置文件的记录长度，即屏数"*/
//	l_table_len--;
	
//	temp =(unsigned long) SHOWTABLE;					/*"用temp转送是避免编译警告"*/	
//	p_show_table_head=(const struct SHOW_TABLE *)temp;	/*"将SHOWTABLE的首地址赋给一个指向SHOW_TABLE结构体的指针，叫头指针"*/
//	p_show_table_tail=p_show_table_head+l_table_len;	/*"将SHOWTABLE的最后条记录的地址赋给一个指向SHOW_TABLE结构体的指针，叫尾指针"*/
	
//	if(show_code<p_show_table_head->old_showcode||show_code>p_show_table_tail->old_showcode) 
//	{
		/*"由于配置文件以show_code为索引由小到大已经排序"*/
		/*"如果show_code比第一个还小，比最后一个还大，那么在配置文件表中不可能找到相应的纪录"*/
//		return 0;
//	}
	/*"下面开始查找，如果头尾地址倒置表示在配置表中找不到。"*/
//	while(p_show_table_head<=p_show_table_tail)
//	{
//		l_table_len=p_show_table_tail-p_show_table_head;		
//		p_show_table_mid=p_show_table_head+l_table_len/2;	/*"在头尾指针间取中点"*/
//		
//		if(show_code<p_show_table_mid->old_showcode)				/*"如果show_code比中点值小"*/
//		{													/*"将尾指针指向中点"*/
//			p_show_table_tail=p_show_table_mid-1;			/*"继续查找"*/
//		}		
//		else if(show_code>p_show_table_mid->old_showcode)			/*"如果show_code比中点值大"*/
//		{													/*"将头指针指向中点"*/
//			p_show_table_head=p_show_table_mid+1;			/*"继续查找"*/		
//		}		
//		else
//		{													/*"如果show_code等于中点值，表示找到"*/		
//			return p_show_table_mid;						/*"返回中点地址，退出查找"*/
//		}
		
		
//	}
//	return 0;												/*"从while循环中退出的条件是头尾地址倒置，表示在配置表中找不到"*/
//}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"将2进制值分解,用于显示，因为显示需要的是一位一位的显示"*/
/*"比如将 0x123456AB 码分解为 0x0102030405060A0B"*/
int bcd_un_zip(char* input,char* output,int len)
{
	int i_temp,ret;
	char c_temp;
	ret=0;
	for(i_temp=0;i_temp<len;i_temp++)
	{
		
		c_temp=(*input)&0xf0;
		c_temp>>=4;
		* output=c_temp;
		output++;
		ret++;
		
		c_temp=(*input)&0x0f;
		* output=c_temp;
		output++;
		ret++;
		input++;
	}
	
	return ret;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"将长整形数转换成4byte char"*/
/*"因为长整形数存储的是低位在前，转换成高位在前，一共4byte"*/
void long_to_bcd(unsigned long input,char* output)
{
	char *pc_temp;
	int i_temp;
	pc_temp=(char*)&input;
	output+=3;
	
	for(i_temp=0;i_temp<4;i_temp++)
	{
		*output=*pc_temp;
		output--;
		pc_temp++;
	}	
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"高低字节掉头"*/
void exchange_data(char *input,char *output,int len)
{
   unsigned char i;
    
   output+=len-1;
   for(i=0;i<len;i++)
   {
	    *output=*input;
	    output--;
	    input++;
   }	
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"将8字译码1-9号"*/
char conver_data0(char* show_data,char* show_ram,int start_add,int len)
{
    int i_temp;
    char c_temp,c_temp1;

    c_temp=*(show_data+1);
    *(show_data+1)=*(show_data+2);
    *(show_data+2)=c_temp;
    for(i_temp=start_add;i_temp<start_add+len;i_temp++)     
    {
	  if(*show_data<21)
	       *show_ram=TABLE_1_3_5_DISPLAY_CODE[*show_data];
	  else
	       *show_ram=0;
          c_temp=*show_ram;
          if(i_temp==8)           /*"1号8字需特殊处理"*/
          {
               *(show_ram-13)|=c_temp&0x0f;
               *(show_ram-12)|=(c_temp&0xf0)>>4;
           }
           else
           {
                *show_ram=(c_temp&0x0f)<<4;
                show_ram++;
                *show_ram=c_temp&0xf0;
           }
          show_data++;
          show_ram++;
    }
  *(show_ram-1)=0;
    return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"将8字译码10-19号"*/
char conver_data1(char* show_data,char* show_ram,int start_add,int len)
{
    int i_temp;
    union byte_def b_char;
    union byte_def b_temp;
    
    for(i_temp=start_add;i_temp<start_add+len;i_temp++)
    {
	if(*show_data<21)
	     *show_ram=TABLE_1_3_5_DISPLAY_CODE[*show_data];
	else
	     *show_ram=0;
        b_char.byte=*show_ram;
        if(i_temp==8||i_temp==9)
        {
             b_temp.bit.b3=b_char.bit.b0;
             b_temp.bit.b2=b_char.bit.b1;
             b_temp.bit.b1=b_char.bit.b2;
             b_temp.bit.b0=0;
             *(show_ram-14)|=b_temp.byte&0x0f;
             b_temp.bit.b3=b_char.bit.b4;
             b_temp.bit.b2=b_char.bit.b5;
             b_temp.bit.b1=b_char.bit.b6;
             b_temp.bit.b0=b_char.bit.b7;
             *(show_ram-13)|=b_temp.byte&0x0f;
             show_ram++;
        }
        else
        {
             *show_ram=(b_char.byte&0x0f)<<4;
              show_ram++;
             *show_ram=b_char.byte&0xf0;
        }
        show_data++;
        show_ram++;
    }
	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"字符位置位"*/
char conver_char(char* show_char,char* show_ram)
{
	union byte_def b_char;
       union byte_def b_ram;    
	int i_temp,uni;
	char *p_temp1,*p_temp2,c_temp;

       for(i_temp=0;i_temp<MAX_CHAR_NUM;i_temp++)
       {
             if(i_temp<13)
             {
             	   if(i_temp==2)
			show_ram+=2;
                 if(i_temp==8)
                      show_ram+=4;
                  *show_ram|=(*show_char&0x0f);
                  show_ram++;
                  *show_ram|=(*show_char&0xf0)>>4;
                  show_ram++;
                  show_char++;
             }
             else if(i_temp==13)
             {
                 c_temp=*show_char;
                 show_ram-=32;
                 for(uni=0;uni<8;uni++)
                 {
                      b_char.byte=(c_temp<<7-uni)&0x80;
                      *show_ram|=b_char.byte;
                      show_ram+=2;
                 }
             }
             else if(i_temp==14)
             {
                  show_char++;
                  c_temp=*show_char;
                  *(show_ram-11)|=(c_temp&0x0f);
                  *(show_ram+2)|=(c_temp&0x10)<<3;/*"DP10"*/
                  *(show_ram+4)|=(c_temp&0x20)<<2;/*"S79"*/
                  *(show_ram+6)|=(c_temp&0x40)<<1;/*"DP11"*/
		   *(show_ram+10)|=(c_temp&0x80);/*"DP12"*/
             }
       }
       return 0;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*"向LCD送数"*/
char show_on_lcd(char* show_ram,int start_add,int len)
{
	unsigned char tmp;
	int i_temp;
	char* pc_temp;
    
	if(start_add+len>SHOW_RAM_NUM)
		return 1;

	/*"点亮或闪烁座标"*/
	if((Show_flag.byte[0]&0x05) ||(Show_flag.byte[1]&0x03)||(Show_flash_falg.byte[0]&0x05)||(Show_flash_falg.byte[1]&0x03))
		Show_flag.bit.XY=1;
	else
		Show_flag.bit.XY=0;
		
	if(IntoPowerDownFlag==0)     /*"正常上电执行,低功耗不执行"*/		
	{
		if (MACRO_LOCAL_PAY_FLAG)
			{
			if (RunStepNum>0)	/*"梯度"*/		//payment	||MACRO_FAY_CONTROL_FLAG
				{
				/*"当前运行第1,2,3,4 阶梯电价"*/
				switch(Curr_Step_Triff)
				{
					case 0:
						*(show_ram+STEP1_X)|=STEP1_Y;
						break;
					case 1:
						*(show_ram+STEP2_X)|=STEP2_Y;
						break;
					case 2:
						*(show_ram+STEP3_X)|=STEP3_Y;
						break;
					case 3:
						*(show_ram+STEP4_X)|=STEP4_Y;
						break;
					case 4:													//Li Update 20130115
						*(show_ram+STEP1_X)|=STEP1_Y;
						*(show_ram+STEP4_X)|=STEP4_Y;
						break;
					case 5:
						*(show_ram+STEP2_X)|=STEP2_Y;
						*(show_ram+STEP4_X)|=STEP4_Y;
						break;
					case 6:
						*(show_ram+STEP3_X)|=STEP3_Y;
						*(show_ram+STEP4_X)|=STEP4_Y;
						break;
					}
				}
				if (RunStepNum>0)
					*(show_ram+FIRST_X)|=FIRST_Y;
				/*"当前使用第1,2 套阶梯电价"*/
				if(LCD_STEP_FLAG_DEFINE)			/*"当前梯度值不为全0，且梯度切换时间不为0，才显示三解形的1和2指示符"*/
					*(show_ram+SECOND_X)|=SECOND_Y;
		}
		/*"当前费率号"*/
		if(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble==0)
		{
			
		}		
		else if(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble<=(MAXTRIFF-1))
		{
			switch(Meter_Parameter.parameter2.JFPG_ExpressTriff[TRAFF_RATE-1])
			{
				case 1:
					*(show_ram+J_X)|=J_Y;	/*"显示'尖' "*/
				break;
				case 2:
					*(show_ram+F_X)|=F_Y; 	/*"显示'峰' "*/
				break;
				case 3:
					*(show_ram+P_X)|=P_Y; 	/*"显示'平' "*/
				break;
				case 4:
					*(show_ram+G_X)|=G_Y; 	/*"显示'谷' "*/
				break;
			}
			
		}	
		//else
		//{
		
		//}
		/*"当前费率表号"*/
		if(Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble!=0)
		{	if(!LCD_TRIFF_SLOT_DEFINE)
			{
				switch(Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow)
				{
				    case 0:
						*(show_ram+ONE_X)|=ONE_Y;		/*"显示'①' "*/
					break;                                
					case 1:                             
						*(show_ram+TWO_X)|=TWO_Y; 		/*"显示'②'"*/
					break;
					//	case 2:                               
						//	*(show_ram+THREE_X)|=THREE_Y; 	/*"显示'③' "*/
					//	break;
					//	case 3:
					//		*(show_ram+FOUR_X)|=FOUR_Y; 	/*"显示'④' "*/
					//	break;
				}
			}
			else 
			{
				if(!LCD_TRIFF_FLAG_DEFINE)
				{
					*(show_ram+ONE_X)|=ONE_Y;		/*"显示'①' "*/
				}
				else
				{
					*(show_ram+ONE_X)|=ONE_Y;		/*"显示'①' "*/
					*(show_ram+TWO_X)|=TWO_Y; 		/*"显示'②'"*/
				}
			}
		}

		/*"点亮"*/	
		tmp=Check_CPU_Occur();
		if (Show_flag.bit.Success || Show_flag.bit.Fail)		//payment
			{
				if ((dispCharFlag[1].bit.b1==1 && tmp==0xFF)
					|| (!GetTimeCount(dispCardCharTime,dispCardCharTimeLen*1000)))
					{
					Show_flag.bit.Read_card=0;
					*(show_ram+28)&=0xFE;
					Show_flag.bit.Ing=0;
					Show_flag.bit.Success=0;
					*(show_ram+29)&=0xFC;
					Show_flag.bit.Fail=0;
					*(show_ram+26)&=0xFE;
					dispCharFlag[1].bit.b1=0;
					}
			}
		if (Show_flag.bit.Stock_up)
			{
			if ((dispCharFlag[1].bit.b6==1 && tmp==0xFF)
					|| (!GetTimeCount(dispCharHoardTime,dispCharHoardTimeLen*1000)))
				{
				Show_flag.bit.Stock_up=0;
				*(show_ram+24)&=0xFB;
				dispCharFlag[1].bit.b6=0;
				}
			}
	}	
	Find_PassInf_Status();	//payment
	
	if(Show_flag.bit.RS2==1)
	  *(show_ram+22)|=0x0a;
	  
	*show_ram|=Show_flag.byte[0];
	*(show_ram+1)|=Show_flag.byte[1];
	*(show_ram+20)|=Show_flag.byte[2];
	*(show_ram+22)|=(Show_flag.byte[3]&0x03);
        if(Show_flag.bit.RS1==1)
            *(show_ram+22)|=0x06;
	*(show_ram+23)|=Show_flag.byte[4];
	*(show_ram+24)|=Show_flag.byte[5];
	*(show_ram+26)|=Show_flag.byte[6];
	*(show_ram+27)|=Show_flag.byte[7];
	*(show_ram+28)|=Show_flag.byte[8];
	*(show_ram+29)|=Show_flag.byte[9];
	*(show_ram+30)|=Show_flag.byte[10];
	*(show_ram+31)|=Show_flag.byte[11];
	
	
	/*"闪烁"*/
	if(Show_flash_falg.bit.flash_flag)
	{
		if(refreshFlag)
		{
			Show_flash_falg.bit.flash_flag=0;
			refreshFlag=0;
		}
		else
			refreshFlag++;
	*show_ram|=Show_flash_falg.byte[0];
	*(show_ram+1)|=Show_flash_falg.byte[1];
	*(show_ram+20)|=Show_flash_falg.byte[2];
	*(show_ram+23)|=Show_flash_falg.byte[4];
	*(show_ram+24)|=Show_flash_falg.byte[5];
	*(show_ram+26)|=Show_flash_falg.byte[6];
	*(show_ram+27)|=Show_flash_falg.byte[7];
	*(show_ram+28)|=Show_flash_falg.byte[8];
	*(show_ram+29)|=Show_flash_falg.byte[9];
	*(show_ram+30)|=Show_flash_falg.byte[10];
	*(show_ram+31)|=Show_flash_falg.byte[11];
	}	
	else
	{
		if(refreshFlag)
			{
			Show_flash_falg.bit.flash_flag=1;
			refreshFlag=0;
			}
		else
			refreshFlag++;
	*show_ram&=(~Show_flash_falg.byte[0]);
	*(show_ram+1)&=(~Show_flash_falg.byte[1]);
	*(show_ram+20)&=(~Show_flash_falg.byte[2]);
	*(show_ram+23)&=(~Show_flash_falg.byte[4]);
	*(show_ram+24)&=(~Show_flash_falg.byte[5]);
	*(show_ram+26)&=(~Show_flash_falg.byte[6]);
	*(show_ram+27)&=(~Show_flash_falg.byte[7]);
	*(show_ram+28)&=(~Show_flash_falg.byte[8]);
	*(show_ram+29)&=(~Show_flash_falg.byte[9]);
	*(show_ram+30)&=(~Show_flash_falg.byte[10]);
	*(show_ram+31)&=(~Show_flash_falg.byte[11]);
	}	
		
	
	HT1623_SEND_DATA(start_add*2,show_ram,len);
	/*if(start_add<20)
		{
			if(start_add+len<20)
				SendDispData_PCF8576(show_ram,len,SELECT_DEVICE1,start_add*2);
			else if(start_add+len<40)
			{
				SendDispData_PCF8576(show_ram,20-start_add,SELECT_DEVICE1,start_add*2);
				SendDispData_PCF8576(show_ram+(20-start_add),len-(20-start_add),SELECT_DEVICE2,0);
			}
			else
			{
				SendDispData_PCF8576(show_ram,20-start_add,SELECT_DEVICE1,start_add*2);
				SendDispData_PCF8576(show_ram+(20-start_add),20,SELECT_DEVICE2,0);	
				SendDispData_PCF8576(show_ram+(40-start_add),len-(40-start_add),SELECT_DEVICE3,0);	
			}
			
		}
	else if(start_add<40)		
		{
			if(len<20)
				SendDispData_PCF8576(show_ram,len,SELECT_DEVICE2,(start_add-20)*2);
			else
			{
				SendDispData_PCF8576(show_ram,40-start_add,SELECT_DEVICE2,(start_add-20)*2);
				SendDispData_PCF8576(show_ram+(40-start_add),len-(40-start_add),SELECT_DEVICE3,0);
			}
		}
	else
	{
		SendDispData_PCF8576(show_ram,len,SELECT_DEVICE3,(start_add-40)*2);	
	}*/
	
	
	for (i_temp=start_add;i_temp<start_add+len ;i_temp++)
    {
         vram[i_temp/MAX_DATA_NUM][i_temp%MAX_DATA_NUM]=*show_ram;         
         show_ram++;       
    }
    
    /*if(Show_flag.bit.lock)
    	Show_Char_Main(LOCK_V,1);
    if(Show_flag.bit.keystoke)
    	Show_Char_Main(KEYSTOKE_V,1);
    if(Show_flag.bit.key)
    	Show_Char_Main(KEY_V,1);
    if(Show_flag.bit.batteries1)
    	Show_Char_Main(BATTERIES1_V,1);
    if(Show_flag.bit.batteries2)
    	Show_Char_Main(BATTERIES2_V,1);
    if(Show_flag.bit.batteries3)
    	Show_Char_Main(BATTERIES3_V,1);
    if(Show_flag.bit.BT)
    	Show_Char_Main(BT_V,1);
    if(Show_flag.bit.RS1)
    	Show_Char_Main(RS1_V,1);
    if(Show_flag.bit.RS2)
    	Show_Char_Main(RS2_V,1);*/
    
    /*if(Show_flash_falg.bit.flash_flag)
    {
    	Show_flash_falg.bit.flash_flag=0;
    	//if(Show_flash_falg.bit.reverse)	Show_Char_Main(REVERSE_V,0);
    	//if(Show_flash_falg.bit.F_ActivePower)	Show_Char_Main(F_ACTIVEPOWER_V,0);
    	//if(Show_flash_falg.bit.B_ActivePower)	Show_Char_Main(B_ACTIVEPOWER_V,0);
    	//if(Show_flash_falg.bit.F_ReactivePower)	Show_Char_Main(F_REACTIVEPOWEr_V,0);
    	//if(Show_flash_falg.bit.B_ReactivePower)	Show_Char_Main(B_REACTIVEPOWER_V,0);
    	if(Show_flash_falg.bit.Ua)	Show_Char_Main(Ua_V,0);
    	if(Show_flash_falg.bit.Ub)	Show_Char_Main(Ub_V,0);
    	if(Show_flash_falg.bit.Uc)	Show_Char_Main(Uc_V,0);
    	if(Show_flash_falg.bit.Ia)	Show_Char_Main(Ia_V,0);
    	if(Show_flash_falg.bit.Ib)	Show_Char_Main(Ib_V,0);
    	if(Show_flash_falg.bit.Ic)	Show_Char_Main(Ic_V,0);
    }
    else
    {
    	Show_flash_falg.bit.flash_flag=1;	
    	if(Show_flash_falg.bit.reverse)	Show_Char_Main(REVERSE_V,1);
    	if(Show_flash_falg.bit.F_ActivePower)	Show_Char_Main(F_ACTIVEPOWER_V,1);
    	if(Show_flash_falg.bit.B_ActivePower)	Show_Char_Main(B_ACTIVEPOWER_V,1);
    	if(Show_flash_falg.bit.F_ReactivePower)	Show_Char_Main(F_REACTIVEPOWEr_V,1);
    	if(Show_flash_falg.bit.B_ReactivePower)	Show_Char_Main(B_REACTIVEPOWER_V,1);
    	if(Show_flash_falg.bit.Ua)	Show_Char_Main(Ua_V,1);
    	if(Show_flash_falg.bit.Ub)	Show_Char_Main(Ub_V,1);
    	if(Show_flash_falg.bit.Uc)	Show_Char_Main(Uc_V,1);
    	if(Show_flash_falg.bit.Ia)	Show_Char_Main(Ia_V,1);
    	if(Show_flash_falg.bit.Ib)	Show_Char_Main(Ib_V,1);
    	if(Show_flash_falg.bit.Ic)	Show_Char_Main(Ic_V,1);
    	
    	
    }*/
    	

    return 0;	
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char lcd_special_show(char show_code)
{
    unsigned char uc_temp[60];
    int i_temp,i_temp_1;
    if(lcd_special_cortrol(0)==0)
    {
        if(show_code==0)
            for (i_temp=0;i_temp<48 ;i_temp++)
            	uc_temp[i_temp]=0;
        else if(show_code==1)
            for (i_temp=0;i_temp<48 ;i_temp++)
            	uc_temp[i_temp]=0xff;
//        else if(show_code==7)
//        {
//        	for(i_temp=0;i_temp<48 ;i_temp++)
//        	{
//        		for (i_temp_1=0;i_temp_1<60 ;i_temp_1++)
//            	{
//            		uc_temp[i_temp_1]=0;
//            		
//            	}
//            	for (i_temp_1=0;i_temp_1<8 ;i_temp_1++)
//            	{
//        			uc_temp[i_temp]=1<<i_temp_1;
//        			//SendDispData_PCF8576(&uc_temp[0],20,SELECT_DEVICE1,0);
//					//SendDispData_PCF8576(&uc_temp[20],20,SELECT_DEVICE2,0);
//					//SendDispData_PCF8576(&uc_temp[40],20,SELECT_DEVICE3,0);
//					HT1623_SEND_DATA(0,&uc_temp[0],SHOW_RAM_NUM);
//					tr_show_wait(0x7ff0);
//					tr_show_wait(0x7ff0);
//					tr_show_wait(0x7fff);
//					tr_show_wait(0x7fff);
//					tr_show_wait(0x7fff);
//					tr_show_wait(0x7fff);
//					tr_show_wait(0x7fff);
//					//tr_show_wait(0x7fff);
//					//tr_show_wait(0x7fff);
//					//tr_show_wait(0x7fff);
//
//				}
//				tr_show_wait(0x7fff);
//				tr_show_wait(0x7fff);
//				tr_show_wait(0x7fff);
//				tr_show_wait(0x7fff);
//				tr_show_wait(0x7fff);
//				tr_show_wait(0x7fff);
//				//tr_show_wait(0x7fff);
//				//tr_show_wait(0x7fff);
//				//tr_show_wait(0x7fff);
//				//tr_show_wait(0x7fff);
//				
//			}
//        	return 2;
//        }
    }
    else
    {
        return 1;
    }
    //SendDispData_PCF8576(&uc_temp[0],20,SELECT_DEVICE1,0);
	//SendDispData_PCF8576(&uc_temp[0],20,SELECT_DEVICE2,0);
	//SendDispData_PCF8576(&uc_temp[0],8,SELECT_DEVICE3,0);
	HT1623_SEND_DATA(0,&uc_temp[0],SHOW_RAM_NUM);
    return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char lcd_special_cortrol(char cortrol_code)
{
    switch (cortrol_code)
    {
      case 0x0:
      	//Normal_Mode ENABLED 
        //Display_Enable_PCF8576(0);
        HT1623_LCD_ON();
      break;
      case 0x01:
        //Normal_Mode DISENABLED
        //Display_Disable_PCF8576(0);
        HT1623_LCD_OFF();
      break;
      case 0x10:
      	//POWER_SAVING_MODE ENABLED 
        //Display_Enable_PCF8576(1);
        HT1623_SYS_EN();		/*"开振荡器"*/
		HT1623_LCD_ON();		/*"开LCD显示"*/
      break;
      case 0x11:
      	//POWER_SAVING_MODE DISENABLED
        //Display_Disable_PCF8576(1);
        HT1623_SYS_DIS();		/*"关振荡器和偏压发生器"*/
        HT1623_LCD_OFF();
      break;
      default: ;
      return 1;
    }
    return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void cursor_flash(int cursor)
{
	char* temp;
	char temp1[2];
    
	temp=&vram[0][0];
	temp+=cursor;
       temp1[0]=*temp&0x8f; 
       *temp=temp1[0];
       temp++;
       temp1[1]=*temp&0x0f; 
       *temp=temp1[1];
	HT1623_SEND_DATA(cursor,&temp1[0],2);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void clear_show_ram(char* show_ram)
{
    int i_temp;
    for (i_temp=0;i_temp<SHOW_RAM_NUM;i_temp++)
    {
        *(show_ram+i_temp)=0;
    }

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void clear_show_lcd(void)
{
    lcd_special_show(0);
    clear_show_ram(&vram[0][0]);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Lcd_Power_On(void)
{
	PowerOn_PCF8576();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Lcd_Power_Off(void)
{
	PowerOff_PCF8576();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int Show_Initialize (char flag)
{
	//Init_PCF8576(0);
	//lcd_special_show(7);
		
	
	if(flag==0)/*"正常初始化"*/
	{
		HT1623_INIT_IN_NORMAL_MODE();
		lcd_special_show(1);
	}
	else if(flag==1)	/*"低功耗初始化"*/
	{
		HT1623_INIT_IN_POWERDOWN_MODE();	
		//lcd_special_show(0x10);
	}
	else if(flag==2)
	{
		HT1623_INIT_IN_NORMAL_MODE();
	}
	
	
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void tr_show_wait(int time)//time=1 delay 4.8us,time +1  delay +3.0us
{
	unsigned char unc;
	int temp_time;
	temp_time=time;
	do{
		for(unc=4;unc>0;unc--);
		temp_time--;
	  } while(temp_time>=0);
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void show_user_code(long code,unsigned char code_len,char * char_buf,char* data_buf)
{
	/*"显示用户定义显示代码"*/
	char temp_buf[5]; 
	union byte_def transf_temp;   	
	int i_temp;
	
 	if((code_len!=0)&&(code_len<=8))
	{
		long_to_bcd(code,&temp_buf[0]);	
		bcd_un_zip(&temp_buf[0],data_buf,4);
		for(i_temp=0;i_temp<8-(code_len&0xf);i_temp++)					
             {
        	     if(*(data_buf+i_temp)==0xf&&fshow_flag==1)
        		   *(data_buf+i_temp)=0x10;	
        	     else
        		   *(data_buf+i_temp)=0x13;	
              }

	} 
}

//payment	
//------------------------------------------------------------------------
/*"mode	指定字符"*/
/*"	READ_CARD_IN			显示字符"读卡中"*/
/*"	DISP_ERR_DATA		显示错误(ERR-xxxx)"*/
/*"	DISP_CARD			显示"CArd",显示字符"读卡中"*/
void displayReadCard(unsigned char mode)		
{
	unsigned char i;
	unsigned char buff;
	char show_data_buf[9];
	char show_buf[SHOW_RAM_NUM];
		
	switch (mode)
		{
		case READ_CARD_IN:
			Show_flag.bit.Read_card=1;
			Show_flag.bit.Ing=1;
			Show_flag.bit.Success=0;
			Show_flag.bit.Fail=0;
			(*(&vram[0][0]+29))&=0xFC;
			show_on_lcd(&vram[0][0],0,32);
			break;
#if 0
		case DISP_CARD:
			show_data_buf[0]=0x13;
			show_data_buf[1]=0x13;
			show_data_buf[2]=0x13;
			show_data_buf[3]=0x13;
			show_data_buf[4]=0x0C;	//C
			show_data_buf[5]=0x0A;	//A
			show_data_buf[6]=0x11;	//r
			show_data_buf[7]=0x0D;	//d
			show_data_buf[8]=0x13;
			for(i=16;i<32;i++)
				show_buf[i]=0;
			conver_data0(show_data_buf,show_buf,0,MAX_DATA_NUM-1);				/*"9个 1->9"*/
			clear_show_lcd();
			Show_flag.bit.Read_card=1;
			Show_flag.bit.Ing=1;
			Show_flag.bit.Success=0;
			Show_flag.bit.Fail=0;
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);			
			break;
		case DISP_ERR_DATA:
			show_data_buf[0]=0x0E;	//E
			show_data_buf[1]=0x11;	//r
			show_data_buf[2]=0x11;	//r
			show_data_buf[3]=0x10;	//-
			buff =(unsigned char)(meterDispErr_ID>>8);
			show_data_buf[4]=buff/0x10;
			show_data_buf[5]=buff%0x10;
			buff=(unsigned char)(meterDispErr_ID&0xFF);
			show_data_buf[6]=buff/0x10;
			show_data_buf[7]=buff%0x10;
			show_data_buf[8]=0x13;
			for(i=16;i<32;i++)
				show_buf[i]=0;
			conver_data0(show_data_buf,show_buf,0,MAX_DATA_NUM-1);				/*"9个 1->9"*/
			clear_show_lcd();
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			break;
#endif						
		}
}


/*"mode	指定字符"*/
/*"	DISP_CHAR_SWITCH				"拉闸""*/
/*"	DISP_CHAR_ALARM				"报警指示""*/
/*"	DISP_CHAR_HOME					"公钥(实验室)符号""*/
/*"	DISP_CHAR_KEYSTOKE			"编程符号""*/
/*" 	DISP_CHAR_BUY					"请购电""*/
/*"	DISP_CHAR_TICK					"透支""*/
/*"onOff	0:消失,1:显示"*/
/*"flash		0:常显,1:闪烁"*/
void displayCharOnOff(unsigned char mode,unsigned char onOff,unsigned char flash)
{
	switch (mode)
		{
		case DISP_CHAR_SWITCH:
			if (flash)
				Show_flash_falg.bit.Break_switch=onOff;
			else
				Show_flag.bit.Break_switch=onOff;
			break;
#if 0			
		case DISP_CHAR_ALARM:
			if (flash)
				Show_flash_falg.bit.Bell=onOff;
			else
				Show_flag.bit.Bell=onOff;
			break;
		case DISP_CHAR_HOME:
			if (flash)
				Show_flash_falg.bit.Home=onOff;
			else
				Show_flag.bit.Home=onOff;
			break;
		case DISP_CHAR_KEYSTOKE:
			if (flash)
				Show_flash_falg.bit.keystoke=onOff;
			else
				Show_flag.bit.keystoke=onOff;
			break;
		case DISP_CHAR_BUY:
			if (flash)
				Show_flash_falg.bit.Recharge=onOff;
			else
				Show_flag.bit.Recharge=onOff;
			break;
		case DISP_CHAR_TICK:
			if (flash)
				Show_flash_falg.bit.Overdraft=onOff;
			else
				Show_flag.bit.Overdraft=onOff;
			break;
#endif			
		}
}


/*"mode	指定字符"*/
/*"	READ_CARD_SUCCESS	"显示:读卡成功""*/
/*"	READ_CARD_FAIL			"显示:读卡失败""*/
/*"	DISP_CHAR_HOARD		"囤积""*/
/*"	DISP_REMAIN_DATA		"显示剩余电费数据""*/
/*"	DISP_DEFICIT_DATA		"显示欠电费数据""*/
/*"	DISP_BEFOR_REMAIN	"显示上一次购电前剩余电费后自动显示当前剩余电量""*/
/*"	DISP_IC_ERR					"显示IC插卡错误(ERR--xx)""*/
/*"	DISP_METTER_ID			"显示表号""*/
/*"	DISP_CHAR_GOOD		"显示:GOOD""*/
/*"timeLen	显示时间长度,以秒为单位(作为显示开关0xFF:开,0:关)"*/
/*"flag			拨卡是否消失(1:拨卡就消失)"*/
void displayCharTimeLen(unsigned char mode,unsigned char timeLen,unsigned char flag)
{
	unsigned char i;
	unsigned char buff;
	unsigned char buff1;
	char show_data_buf[9];
	char show_buf[40];
	
	switch (mode)
		{
		case READ_CARD_SUCCESS:		/*"显示读卡成功提示符"*/
			Show_flag.bit.Read_card=1;
			Show_flag.bit.Ing=0;
			(*(&vram[0][0]+29))&=0xFD;
			Show_flag.bit.Fail=0;
			(*(&vram[0][0]+26))&=0xFE;
			Show_flag.bit.Success=1;
			dispCardCharTimeLen=timeLen;
			dispCardCharTime=GetNowTime();
			dispCharFlag[1].bit.b1=flag;
			show_on_lcd(&vram[0][0],0,SHOW_RAM_NUM);
			break;			
		case READ_CARD_FAIL:		/*"显示读卡失败提示符"*/
			Show_flag.bit.Read_card=1;
			Show_flag.bit.Ing=0;
			Show_flag.bit.Success=0;
			(*(&vram[0][0]+29))&=0xFC;
			Show_flag.bit.Fail=1;
			dispCardCharTimeLen=timeLen;
			dispCardCharTime=GetNowTime();
			dispCharFlag[1].bit.b1=flag;
			show_on_lcd(&vram[0][0],0,32);
			break;
		case DISP_CHAR_HOARD:		/*"显示囤积提示符"*/
			dispCharHoardTimeLen=timeLen;
			dispCharHoardTime=GetNowTime();
			Show_flag.bit.Stock_up=1;
			dispCharFlag[1].bit.b6=flag;
			break;
		case DISP_REMAIN_DATA:		/*"显示当前剩余金额"*/
			leaf_flag=0;
		//	buff=show_mode;
		//	show_mode=1;
			//Show_Main(0x00080078,&show_buf[0],0,0);
			Show_Main(0x00900200,&show_buf[0],0,0);
			for(i=16;i<32;i+=2)
				{
				show_buf[i]&=0x8F;
				show_buf[i+1]&=0x0F;
				}
			for(i=18;i<22;i++)
				show_buf[i]&=0xF0;
		//	show_mode=buff;
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			dispCharFlag[0].bit.b7=1;
			dispCharFlag[1].bit.b7=flag;
			break;
		case DISP_BEFOR_REMAIN:		/*"显示购电前剩余金额2秒,接着显示当前剩余金额"*/
			dispCharFlag[0].bit.b5=1;
			leaf_flag=0;
			Show_Main(0x0090E401,&show_buf[0],0,0);	/*"显示购电前剩余金额"*/
			for(i=16;i<32;i+=2)
				{
				show_buf[i]&=0x8F;
				show_buf[i+1]&=0x0F;
				}
			for(i=18;i<22;i++)
				show_buf[i]&=0xF0;
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			dispCharFlag[0].bit.b5=1;
			dispCharFlag[1].bit.b5=flag;
			break;
		case DISP_IC_ERR:
			show_data_buf[0]=0x13;
			show_data_buf[1]=0x13;
			show_data_buf[2]=0x0E;	//E
			show_data_buf[3]=0x11;	//r
			show_data_buf[4]=0x11;	//r
			show_data_buf[5]=0x10;	//-
			buff=getCardErrConver((unsigned char)press_card_state);
			show_data_buf[6]=buff/0x10;
			show_data_buf[7]=buff%0x10;
			show_data_buf[8]=0x13;
			for(i=16;i<32;i++)
				show_buf[i]=0;
			conver_data0(show_data_buf,show_buf,0,MAX_DATA_NUM-1);				/*"9个 1->9"*/
			clear_show_lcd();
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			dispCharFlag[0].bit.b2=1;
			dispCharFlag[1].bit.b2=flag;
			break;
#if 0
		case DISP_CHAR_GOOD:
			show_data_buf[0]=0x13;
			show_data_buf[1]=0x13;
			show_data_buf[2]=0x13;
			show_data_buf[3]=0x13;
			show_data_buf[4]=0x09;	//G
			show_data_buf[5]=0x14;	//o
			show_data_buf[6]=0x14;	//o
			show_data_buf[7]=0x0D;	//d
			show_data_buf[8]=0x13;
			for(i=16;i<32;i++)
				show_buf[i]=0;
			conver_data0(show_data_buf,show_buf,0,MAX_DATA_NUM-1);				/*"9个 1->9"*/
			clear_show_lcd();
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			dispCharFlag[0].bit.b0=1;
			dispCharFlag[1].bit.b0=flag;
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			break;
		case DISP_DEFICIT_DATA:
			leaf_flag=0;
		//	buff=show_mode;
		//	show_mode=1;
			Show_Main(0x00900101,&show_buf[0],0,0);
			for(i=16;i<32;i+=2)
				{
				show_buf[i]&=0x8F;
				show_buf[i+1]&=0x0F;
				}
			for(i=18;i<22;i++)
				show_buf[i]&=0xF0;
		//	show_mode=buff;
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			dispCharFlag[0].bit.b6=1;
			break;			
		case DISP_METTER_ID:
		//	buff=show_mode;
		//	show_mode=1;
			buff1=leaf_flag;
			if (dispCharFlag[0].bit.b3)	/*"显示完表号高6位,接着显示低6位"*/
				{
				leaf_flag=1;	//L
				dispCharFlag[0].bit.b4=1;
				dispCharFlag[1].bit.b4=flag;
				}
			else
				leaf_flag=0;	//H
			Show_Main(0x04000402,&show_buf[0],0,0);
			for(i=16;i<32;i+=2)
				{
				show_buf[i]&=0x8F;
				show_buf[i+1]&=0x0F;
				}
			for(i=18;i<22;i++)
				show_buf[i]&=0xF0;
		//	show_mode=buff;
			leaf_flag=buff1;
			show_on_lcd(show_buf,0,SHOW_RAM_NUM);
			dispCardDataTimeLen=timeLen;
			dispCardDataTime=GetNowTime();
			dispCharFlag[0].bit.b3=1;
			dispCharFlag[1].bit.b3=flag;
			break;
#endif			
		}
}

void dispPaymentChar(void)
{
	unsigned char tmp;

	tmp=Check_CPU_Occur();
	if (dispCharFlag[0].bit.b0)
		{
		if ((dispCharFlag[1].bit.b0==1 && tmp==0xFF)
				|| (!GetTimeCount(dispCardDataTime,dispCardDataTimeLen*1000)))
			{
			dispCharFlag[0].bit.b0=0;
			dispCharFlag[1].bit.b0=0;
			}
		}
	else if (dispCharFlag[0].bit.b2)
		{
		if ((dispCharFlag[1].bit.b2==1 && tmp==0xFF)
				|| (!GetTimeCount(dispCardDataTime,dispCardDataTimeLen*1000)))
			{
			dispCharFlag[0].bit.b2=0;
			dispCharFlag[1].bit.b2=0;
			}
		}
#if 0	
	else if (dispCharFlag[0].bit.b3)
		{
		if (dispCharFlag[1].bit.b3==1 && tmp==0xFF)
			{
			dispCharFlag[0].bit.b3=0;
			dispCharFlag[1].bit.b3=0;
			}
		 if (!GetTimeCount(dispCardDataTime,dispCardDataTimeLen*1000))
			{
				displayCharTimeLen(DISP_METTER_ID,dispCardDataTimeLen,dispCharFlag[1].bit.b3);
				dispCharFlag[0].bit.b3=0;
				dispCharFlag[1].bit.b3=0;
			}
		}
#endif	
	else if (dispCharFlag[0].bit.b4)
		{
		if ((dispCharFlag[1].bit.b4==1 && tmp==0xFF)
				|| (!GetTimeCount(dispCardDataTime,dispCardDataTimeLen*1000)))
			{
			dispCharFlag[0].bit.b4=0;
			dispCharFlag[1].bit.b4=0;
			}
		}
	else if (dispCharFlag[0].bit.b5)
		{
		tmp=Check_CPU_Occur();
		if (dispCharFlag[1].bit.b5==1 && tmp==0xFF)
			{
			dispCharFlag[0].bit.b5=0;
			dispCharFlag[1].bit.b5=0;
			}
		if (!GetTimeCount(dispCardDataTime,2*1000))	/*"显示2秒后,接着显示当前剩余电费"*/
			{
			displayCharTimeLen(DISP_REMAIN_DATA,dispCardDataTimeLen,dispCharFlag[1].bit.b5);
			dispCharFlag[0].bit.b5=0;
			dispCharFlag[1].bit.b5=0;
			}
		}
	else if (dispCharFlag[0].bit.b7)
		{
		if ((dispCharFlag[1].bit.b7==1 && tmp==0xFF)
				|| (!GetTimeCount(dispCardDataTime,dispCardDataTimeLen*1000)))
			{
			dispCharFlag[0].bit.b7=0;
			dispCharFlag[1].bit.b7=0;
			}
		}

	if (!dispCharFlag[0].byte)
		OutCardInCycshow();		/*"拨卡后提示显示完后,回到循显第一屏"*/
}

void Disp_Char_Clear(void)
{
	Show_flag.bit.Read_card=0;
	Show_flag.bit.Ing=0;
	Show_flag.bit.Success=0;
	Show_flag.bit.Fail=0;
	Show_flag.bit.Stock_up=0;
	dispCharFlag[0].byte=0;
	dispPaymentFlag.bit.b0=1;
	display_Remain_Flag=0;	
}

