/*"DL645-2007ͨѶ���"*/
/*"trend 2008-4-23 11:32:09 V1.00"*/
/*"��Ʒ�����Э���������"*/
/*"�����ļ�������645DATA.c"*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "I2C_operation.h"
#include "645_2007.h"
#include "MB_BASE_FUN.h"
#include "MB_Showmain.h"
#include "645Data.h" /*"Э���������ݱ�"*/
#include "LoadRecord.h"
#include "datachange.h"
#include "File_System.h"
#include "LoadRecord.h"
#include "Freeze.h"
#include "Comm.h"
#include "eventnew.h"
#include "Multi.h"
#include "Initram.h"

#include "pay_def.h"
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "ICcard.h"	//payment
#include "Far_pay.h"	//farpayment 
#include "Measure_Interface.h" 



#define MAX_FUN_BUFF_SIZE	 			32    

#define REVISE_ADDR_TYPE	 			0  
#define REVISE_FILE_TYPE	 			0x08  

struct CHECK_NODE_ID_BIT
{
	unsigned char low:1;
	unsigned char zip1:1;
	unsigned char zip2:1;
	unsigned char num1 :2;
	unsigned char num2 :2;
	unsigned char error:1;
};

union CHECK_NODE_ID_RET{
	char	byte;
	struct CHECK_NODE_ID_BIT bit;		
};

unsigned int tree_error;
struct COMM_STAUT Comm_Staut;
struct ITERATE_TREE_FLAG Iterate_Tree_Flag[4];		//uart=3  show
unsigned char Comm_Data_valid_flag;        //fxf add 081109    
unsigned char Read_event_first_flag;/*"�����ڷ������¼���־fxf add 090301    "*/
extern volatile unsigned char IntoPowerDownFlag;
unsigned int Leaf_num_now=0;
union ID Read_Com_ID;
unsigned char eventfreezereadflag;


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
signed int  TransferData_New(union ID id,unsigned char *P, unsigned int L,
                         unsigned char formatdata,unsigned char *format,     
                         unsigned char mode,unsigned char data_len,unsigned char uartx);
unsigned char Search_node(union ID id,unsigned int node_addr,unsigned int * addr ,unsigned char uzip);
unsigned char Check_Node_ID(union ID id,const struct TREE_NODE *node,unsigned char uzip);
unsigned int Search_Protocol_Tree(union ID id,unsigned char* flag);
signed int Traverse_Node(unsigned int node_addr,unsigned char type,unsigned char *buff,
												unsigned int len,unsigned char mode,
												unsigned char formatdata,unsigned char *format,
												union ID id,unsigned char data_len,unsigned char uartx);
unsigned char search_leaf(unsigned int node_addr,unsigned int *addr);
signed int Get_Leaf_Data(unsigned int leaf_addr,unsigned char *buff,
												unsigned char formatdata,unsigned char *format,
												unsigned int Revise,unsigned int Revise_file,unsigned char uartx);

signed int Set_Leaf_Data(unsigned int leaf_addr,unsigned char *buff,
												unsigned char formatdata,unsigned char *format,
												unsigned int Revise,unsigned char uartx);


unsigned char Ram_math(unsigned char mode,unsigned char * startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr);
unsigned char math_Demand(unsigned char * startaddr,unsigned char * getbuff ,
							 unsigned char math_mode,unsigned char format,
							 unsigned char Ass_num,unsigned char Ass_addr, unsigned int file_name);
unsigned char Eeprom_math(unsigned char mode,unsigned int startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr,
											unsigned char driver);
unsigned char math_Add(unsigned char * startaddr,unsigned char * getbuff ,
						unsigned char math_mode,unsigned char format,
						unsigned char Ass_num,unsigned char Ass_addr,
						unsigned int  file_name);

unsigned char Flash_math(unsigned char mode,unsigned int startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr,
											unsigned int filename);

int Check_Data_valid(unsigned char  * buff_t, unsigned char len);//FXF add

unsigned int Revise_Addr(unsigned int leaf_addr,const struct COMMUNAL_REVISE *REVISE ,unsigned char ID,unsigned type);
unsigned char get_leaf_cyc_para(unsigned int node,unsigned char *start,unsigned char *end);

unsigned char set_zip_id(unsigned char *zip_id,unsigned char num,unsigned char level);
unsigned char push_zip_info(unsigned char val,unsigned char num);

unsigned char Check_Event_Id_Valid(union ID id);
void Prep_Event_Ram(union ID id);
unsigned char Get_Event_OneData(union ID id,unsigned char mode,unsigned char leaf_num,
                                unsigned char *databuff,unsigned char *show_para);
unsigned char Get_Id1_max(unsigned char id3);
unsigned char Get_Event_AllData(union ID id,unsigned char uartx,unsigned char max_len,unsigned char *databuff);


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������TransferData_New"*/
/*"��;����д����"*/
/*"������mode=0 ����ʼ 1 ����֡ 2 д�� 3��ʾ"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/

#define EVENTREADNODEALNUM  19
const struct EVENTREADNODEALSTRUCTURE READNODEALEVENT[EVENTREADNODEALNUM]=
  {
  	{0x03,0x03,0x30,0x30,0x00,0x00,0x01,0x0A,&Event_Power_Net_Times.ProgrammeEvent_Times},
  	{0x03,0x03,0x30,0x30,0x01,0x01,0x01,0x0A,&Event_Meter_Pro_Times.ClearMeterRecord_Times},
  	{0x03,0x03,0x30,0x30,0x02,0x02,0x01,0x0A,&Event_Meter_Pro_Times.ClearDemandRecord_Times},
  	{0x03,0x03,0x30,0x30,0x03,0x03,0x01,0x0A,&Event_Meter_Pro_Times.ClearEventRecord_Times},
  	{0x03,0x03,0x30,0x30,0x04,0x04,0x01,0x0A,&Event_Meter_Pro_Times.AdjustTimeRecord_Times},
  	{0x03,0x03,0x30,0x30,0x05,0x05,0x01,0x0A,&Event_Meter_Pro_Times.ProgDailySlotRecord_Times},
  	{0x03,0x03,0x30,0x30,0x06,0x06,0x01,0x0A,&Event_Meter_Pro_Times.ProgYearSlotRecord_Times},
  	{0x03,0x03,0x30,0x30,0x07,0x07,0x01,0x0A,&Event_Meter_Pro_Times.ProgWeekRecord_Times},
  	{0x03,0x03,0x30,0x30,0x09,0x09,0x01,0x0A,&Event_Meter_Pro_Times.ProgAEModeRecord_Times},
  	{0x03,0x03,0x30,0x30,0x0A,0x0A,0x01,0x0A,&Event_Meter_Pro_Times.ProgNEMode1Record_Times},
  	{0x03,0x03,0x30,0x30,0x0B,0x0B,0x01,0x0A,&Event_Meter_Pro_Times.ProgNEMode2Record_Times},
  	{0x03,0x03,0x30,0x30,0x0C,0x0C,0x01,0x0A,&Event_Meter_Pro_Times.ProgBillDayRecord_Times},
  	{0x03,0x03,0x30,0x30,0x0F,0x0F,0x01,0x0A,&Pre_Payment_Data.TriffProgNum},
  	{0x03,0x03,0x30,0x30,0x10,0x10,0x01,0x0A,&Pre_Payment_Data.StepProgNum},
  	{0x03,0x03,0x30,0x30,0x12,0x12,0x01,0x0A,&Pre_Payment_Data.Far_Key_Updata_Count},
  	{0x03,0x03,0x30,0x30,0x13,0x13,0x01,0x0A,&Pre_Payment_Data.OPCard_Error_Num},
  	{0x03,0x03,0x36,0x36,0x00,0x00,0x01,0x0A,&Pre_Payment_Data.Relay_Error_Num},
  	{0x1D,0x1D,0x00,0x00,0x01,0xFF,0x01,0x0A,&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks},
  	{0x1E,0x1E,0x00,0x00,0x01,0xFF,0x01,0x0A,&Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks}
  };

signed int  TransferData_New(union ID id,unsigned char *P, unsigned int L,
                         unsigned char formatdata,unsigned char *format,     
                         unsigned char mode,unsigned char data_len,unsigned char uartx)
{
	unsigned int uni,node_point;
	signed int i_ret;
	unsigned char node_type;
	tree_error=0;
	/*"�建��"*/
	for(uni=0;uni<500;uni++)
		Co.b[uni]=0;
	Show_ID_vatiy=0;
	
	eventfreezereadflag=0;
	
	if((mode!=2)&&((id.d[3]==0x03)||((id.d[3]>=0x10)&&(id.d[3]<=0x21))||((id.d[3]==0x0E)&&(id.d[2]>=0x18)&&(id.d[2]<=0x30))
	               ||(id.d[3]==0x05)))
		{
		 eventfreezereadflag=1;
		 if(id.d[3]!=0x05)/*"ͨ�ų����¼���¼����������¼�������������㴦��"*/
		 	{
		 	ClearEventCommDeal(id.l);
		 	}
		 else/*"ͨ�ų����������ݣ�������Ķ���������������㴦��"*/
		 	{
		 	ClearFreezeCommDeal(id.l);
		 	}
		}
	 
	  
	if(eventfreezereadflag==1)
	{
		
		for(uni=0;uni<EVENTREADNODEALNUM;uni++)
		{
			if((id.d[3]>=READNODEALEVENT[uni].id3minvalue)&&(id.d[3]<=READNODEALEVENT[uni].id3maxvalue)
			 &&(id.d[2]>=READNODEALEVENT[uni].id2minvalue)&&(id.d[2]<=READNODEALEVENT[uni].id2maxvalue)
			 &&(id.d[1]>=READNODEALEVENT[uni].id1minvalue)&&(id.d[1]<=READNODEALEVENT[uni].id1maxvalue)
			 &&(id.d[0]>=READNODEALEVENT[uni].id0minvalue)&&(id.d[0]<=READNODEALEVENT[uni].id0maxvalue)
			 &&((*READNODEALEVENT[uni].eventtimespointer)>=id.d[0]))
	    {
	       eventfreezereadflag=0;
	       break;
	    }
		}
		
	}

	/*if (!MACRO_LOCAL_PAY_FLAG)	//payment
		{
		if (((id.l>=0x05050001)&&(id.l<=0x0505FFFF))		// triff bill
		||((id.l>=0x05070001)&&(id.l<=0x0507FFFF)))	// setp bill
			{
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			return 0;
			}
		}
	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		{
		if (((id.l>=0x1D000001)&&(id.l<=0x1D00FFFF))		// open record
		||((id.l>=0x1E000001)&&(id.l<=0x1E00FFFF)))	// close record
			{
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			return 0;
			}
		}*/

	CurrReadId=id;			//newpay
	//CurrReadMode=mode;
	/*"����Э����"*/
	node_point=Search_Protocol_Tree(id,&node_type);
	if(node_point!=0xffff)
	{	/*"�����ڵ�"*/
		if(mode==0x00)
		{  
             if((data_len-4)!=0)
				return 0;
		}
		else if(mode==0x01)
		{
			if((data_len-5)!=0)/*" �ж����ݳ���"*/
				return 0;
		}
		else if(mode==0x02)
		 {
		 	i_ret=0xff;
			Co.c.addr5=P;
		}
		else if(mode==0x03)
		{	
			i_ret=0;			
		}
		else 
		return 0;		
		
		i_ret=Traverse_Node(node_point,node_type,P,L,mode, formatdata,format,id,data_len,uartx);
		return i_ret;
	}
	else
	{		
		if( ((id.d[3]==0x06)&&(id.d[2]<=0x06)&&(id.d[1]==0)&&(id.d[0]<=0x02))
            || ((id.d[3]==0x06)&&(id.d[2]==0x10)&&(id.d[1]<=8)) )
		{/*"��������"*/
			if(IntoPowerDownFlag!=0)
			{/*"�͹����²�������FLASH����"*/
					return 0;
			}
            if (id.d[2]!=0x10)
            {
    			if(mode==0)
    			{
    				if((id.d[0]==0)&&(data_len!=5)) return 0;
    				if((id.d[0]==1)&&(data_len!=10)) return 0;
    				if((id.d[0]==2)&&(data_len!=5)) return 0;
    			}
    			else if(mode==1)
    			{
    				if(data_len!=5) return 0;
    			}
    			else
    			{
    				return 0;
    			}
            }
            else
            {
                if (check_id_error(id.d[0], id.d[1]))
                {
                    Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
                    return 0;
                }
                if(mode==0)
    			{
    				if(data_len!=10) return 0;
                    if(BCD2Byte(cx[3].command[0], &user_req_pnt)<0)
            			return 0;/*"�����ݿ���"*/
                    if(user_req_pnt > MAX_NEED_PNT || user_req_pnt == 0)
                    {
                        return 0;
                    }
    			}
    			else if(mode==1)
    			{
    				if(data_len!=5) return 0;
    			}
    			else
    			{
    				return 0;
    			}
            }
		 	cx[3].readloadrecord=1;
				
			i_ret=PrepareCommunication(id,(unsigned char *)&cx[3].command[0],P,mode,uartx);
			if((i_ret&0x8000)!=0)
			{/*"�к���֡"*/
				Iterate_Tree_Flag[uartx].flag.bit.b0=1;
				return i_ret&0x7fff;
			}
			else
			{/*"�޺���֡"*/
			       if(mode == 1)/*"������֡ģʽ"*/
				{
				Iterate_Tree_Flag[uartx].flag.bit.b5 = 1;/*"����֡���һ֡����"*/
				//Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
				}
				Iterate_Tree_Flag[uartx].flag.bit.b0=0;
				
				return i_ret&0x7fff;
			}
	   
		}
		else if((id.d[3]==0x0E)&&(id.d[2]==0x0E)&&(id.d[1]==0)&&(id.d[0]<=0x07))/*"�ڲ��������"*/
		{
			i_ret=Set_Read_Block_Para(id,P,data_len,mode);
			
			return i_ret;
		}
		else if(Check_Event_Id_Valid(id)==1)
		{
		  if((mode==1)||(mode==2)||((mode==3)&&(id.d[1]==0xff)))/*"�����������֡,д����ʾ"*/
		    return 0;
		  
		  Show_ID_vatiy=0xFF;
		  if(IntoPowerDownFlag)/*"�͹����²��ܶ�FLASH"*/
   		  return 0;
   		
   		Iterate_Tree_Flag[uartx].num=0;
   		Iterate_Tree_Flag[uartx].flag.bit.b1=0;
   		Iterate_Tree_Flag[uartx].flag.bit.b3=0;
   		Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0;
	    
	    if(mode==0x00)/*"��ʼ��"*/
	    {		
		    Iterate_Tree_Flag[uartx].flag.bit.b0=0;
		    Iterate_Tree_Flag[uartx].flag.bit.b5=0;	
		    Iterate_Tree_Flag[uartx].last_num=0;
		    Iterate_Tree_Flag[uartx].last_num_save=0;
		    Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
	    }
   		
   		Prep_Event_Ram(id);
		  
		  if(id.d[1]==0xff)/*"���һ���¼�������������"*/
		  {
		  	i_ret=Get_Event_AllData(id,uartx,L,P);
		  }
		  else
		  {
		  	i_ret=Get_Event_OneData(id,mode,L,P,format);
		  }
		  
		  return i_ret;
		}
		else
		{
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			return 0; /*"����Э����ʧ��"*/
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"����Э���������� "*/
unsigned int Search_Protocol_Tree(union ID id,unsigned char* flag)
{
	unsigned int node_addr,node_temp;
	unsigned char node_mode,ret;
	if(Protocol_Tree_Root[id.d[3]]==0xFFFF)
		return 0xffff;/*"�Ҳ������ڵ�"*/
//	if(id.d[3]!=Protocol_Tree_Node[Protocol_Tree_Root[id.d[3]]+3])
//		return 0xffff;/*"���ڵ����"*/
	
	node_temp=Protocol_Tree_Root[id.d[3]];
	
	ret=Search_node(id,node_temp,&node_addr,0);	
	
	if((ret&0x80)!=0)
		{
			/*"û�ҵ�"*/
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			return 0xffff;		
		}
	else
	{/*"�ҵ�"*/
		*flag=ret;
		return node_addr;
	}
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�жϽڵ��Ƿ�Ϸ���ָ��Ľڵ�ָ���Ƿ�Ϸ�"*/
unsigned char check_node(const unsigned char *node)
{
	const unsigned char *p_temp;	
	
	p_temp=(const unsigned char *)&Protocol_Tree_Node[0];
	if(node<p_temp) 
		return 0xff;/*"ָ�봦�ڷǷ�����"*/
	if((node-p_temp)>sizeof( Protocol_Tree_Node)) 
		return 0xff;/*"ָ�봦�ڷǷ�����"*/
		
	return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�жϽڵ��ڵ�ָ���������Ϊff��ʾ�ڵ������feָ�볬��Χ��0����"*/
unsigned char check_node_point(unsigned int node)
{

	if(node==0xffff)
		return 0xff;
	else if((node*sizeof(struct TREE_NODE))>sizeof( Protocol_Tree_Node))
		return 0xfe;/*"ָ�봦�ڷǷ�����"*/
	else
		return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"���ҽڵ㺯��������Ƕ����"*/
unsigned char Search_node(union ID id,unsigned int node_addr,unsigned int * addr ,unsigned char uzip)
{
	union CHECK_NODE_ID_RET ret,ret_bak;
	unsigned int Node_temp;
	const struct TREE_NODE *tree_node;
	const unsigned char *p_temp1,*p_temp2;
	
	do{
		
			tree_node=(const struct TREE_NODE *)&Protocol_Tree_Node[node_addr];
			if((ret.byte=check_node((const unsigned char *)tree_node))==0xff)
				{
					tree_error=node_addr;
					return 0xfe;
				}
			
			ret.byte=Check_Node_ID(id,tree_node,uzip);
			if(ret.bit.error==1)
				{
					/*"�Ǳ��ڵ�"*/
					if(tree_node->Next_Node!=0xffff)
						{
							/*"ָ��ͬ����һ���ڵ�"*/
							node_addr=tree_node->Next_Node;
							//uzip=0x0;
						}
					else
						{
							/*"�����ϼ��ڵ� ������ʵ��Ϊʧ�ܳ��ڣ�������ڱ��ڵ��·����ϼ��ڵ�Ҳ�������ҵ�"*/
									return 0xff;
						}
				}
			else
				{
					if(ret.bit.low==0)
					{
						/*"�ҵ����ݱ�ʶ��Ӧ�Ľڵ��Ҷ��"*/
						//*node_mode=tree_node->Node_mode;
						*addr=node_addr;
						return ret.byte;
					}
					else
					{
						/*"���¼��ڵ�"*/
						ret_bak.byte=ret.byte;
						Node_temp=tree_node->Low_Node;	
						uzip|=ret.byte;
						ret.byte=Search_node(id,Node_temp,addr,uzip);
						if(ret.byte==0xff)
							return 0xff;
    				
						return ret.byte|ret_bak.byte;
					}
				}
	 }while(1);
	
		return 0xff;
		
	
		
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�ж��Ƿ��ҵ��ڵ�"*/
/*"����ֵ b0��1�¼��ڵ� 0���ڵ�"*/
/*"       b1��1ѹ�� 0��ѹ��"*/
/*"       b2��1�ڵ� 0Ҷ�ӡ�"*/
/*"       b3��1�� 0�ǿ顤"*/
/*"       b5-b4��0-3 nѹ���ţ�DI(n)��"*/
/*"       b7��1���Ҵ��� 0��ȷ��"*/
unsigned char Check_Node_ID(union ID id,const struct TREE_NODE *node,unsigned char uzip)
{
	unsigned char i,block;
	union CHECK_NODE_ID_RET ret;
	unsigned long *Node_ID,*Node_ID_Mark;
	union ID id_temp;
	const struct COMMUNAL_RANGE *Communal_Range;	
	unsigned char *Ram_id_Addr;
	unsigned char   ID_start=0,ID_end=0;	

	if(node->Node_mode.bit.ID_Enable==1)/*"���ݱ�ʶ��Ч"*/
		{
			if((id.l == node->ID)&&(node->Node_mode.bit.num==0xf)) 
				return 0;/*"���ݱ�ʶ���"*/
				
			/*"���ʶ"*/
			id_temp.l=node->ID;
			block=0xff;
				for(i=0;i<4;i++)
				{				
						if(id_temp.d[i]==0xFF)
						{	
							block=i;
							break;
						}				
				}
			

			ret.byte=uzip;
			for(i=0;i<4;i++)
			{
				if(((i==ret.bit.num1)&&(ret.bit.zip1==1))||((i==ret.bit.num2)&&(ret.bit.zip2==1)))
					{
					}
				else
					{
						if((i!=node->Node_mode.bit.num)&&(i!=block))
						{
							if(id.d[i]!=id_temp.d[i])
							{	
								return 0xff;
							}
						}
					}
			}

		    Communal_Range=(const struct COMMUNAL_RANGE  *)&Protocol_Range[node->Range_ID];	
	      if(Communal_Range->ID_Start<0x100)
		    {		
			  	ID_start=Communal_Range->ID_Start;
		    }
	      else
		    {				
				  Ram_id_Addr=(unsigned char *)Communal_Range->ID_Start;
				  ID_start=*Ram_id_Addr;
		    }
	
	      if(Communal_Range->ID_End<0x100)
		    {	
				ID_end=Communal_Range->ID_End;
				//if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"���ʱ����¼���¼�еķ�����"*/
				//	{
				//	if (Pre_Payment_Para.TriffPriceNum>4)
				//		ID_end=Pre_Payment_Para.TriffPriceNum-1;
				//	}
				//else 
				if ((CurrReadId.l==0x040501FF)||(CurrReadId.l==0x040502FF))
					{
					if (SpicReq_SC_DEFINE)
						ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"ע3����ȡ���ʵ�����ݿ�ʱ���������õ���ʱ�α������أ���ǰ��ʱ�α�������Ϊ�����ͷ��ؼ�����ʵ��"*/
					else
						ID_end=Pre_Payment_Para.TriffPriceNum; /*"������Ϊ���٣����ض�����ʵ��"*/
					}
					
		    }
	      else
		    {			
				  Ram_id_Addr=(unsigned char  *)Communal_Range->ID_End;
				  if((Communal_Range->ID_End) ==((unsigned int)&Max_Triff_Current))/*"����RAM��ַ�ж��Ƿ��ڳ�����������"*////kc debug 140807
				     {
				       if((CurrReadId.d[3]!=0x05)&&(CurrReadId.d[1]!=0xFF))
				       {
				        ID_end=MAXTRIFF-1;
				       }
				       else
				       {
				        ID_end=*Ram_id_Addr;
				       }
				     }
                               else
                               {
				       ID_end=*Ram_id_Addr;
                               }
		    }
	
			if(node->Node_mode.bit.mode==0)
				{
					/*"�����Ҷ��"*/
					if(block!=0xff)
						return 0xff;/*"Ҷ�Ӳ����ܳ��ֿ鳭��ʶ"*/
					if(node->Node_mode.bit.num!=0xf)
					{
						if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
						{
							ret.byte=push_zip_info(uzip,node->Node_mode.bit.num);
							ret.bit.low=0;	
							return ret.byte;/*"���ݱ�ʶ�ڷ�Χ��,�Ǳ�Ҷ�� ѹ����Ҷ��"*/		
						}
						else
						{
							return 0xff;/*"���ݱ�ʶ����Χ"*/
						}	
						
					}
					else
					{
						ret.byte=0;
						return ret.byte;/*"���ݱ�ʶ�ڷ�Χ��,�Ǳ�Ҷ�� δѹ����Ҷ��"*/
					}
											
				}
			else 
				{
					/*"����ǽڵ�"*/
					if(block!=0xff)
						{
								
							if(node->Node_mode.bit.num!=0xf)
							{
							if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
								{									
										if(node->Node_mode.bit.Low_Node_Num==1)/*"�¼��ڵ������ݱ�ʶ"*/
										{	
											ret.byte=push_zip_info(uzip,node->Node_mode.bit.num)	;
											if(id.d[block]!=id_temp.d[block])
												ret.bit.low=1;
											else
												ret.bit.low=0;
											
															
											return ret.byte;/*"���ݱ�ʶ�ڷ�Χ�ڣ��Ǳ��ڵ���"*/
											
										}
									
								}
							}
							else
							{
								
								ret.byte=0;
								ret.bit.low=1;
												
								return ret.byte;/*"���ݱ�ʶ�ڷ�Χ�ڣ��Ǳ��ڵ���"*/
							}					  
						}
					else
						{
						if(node->Node_mode.bit.num!=0xf)
							{
							if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
								{
									
										ret.byte=push_zip_info(uzip,node->Node_mode.bit.num)	;
										if(node->Node_mode.bit.Low_Node_Num==1)/*"�¼��ڵ������ݱ�ʶ"*/
											ret.bit.low=1;
										else
											ret.bit.low=0;
										return ret.byte;/*"���ݱ�ʶ�ڷ�Χ�ڣ��Ǳ��ڵ���"*/
																		
								}
						  }
						  else
							{
								ret.byte=0;
//								ret.bit.low=0;
//								ret.bit.zip1=1;
//								ret.bit.num1=node->Node_mode.bit.num;			
													
								return ret.byte;
							}
						}
				}
		}
	return 0xff;	
		
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"ͬ��ѭ�����¼���Ƕ���ã��ϼ�����"*/
signed int Traverse_Node_sub(unsigned int node_addr,unsigned char *buff,
												unsigned int len,unsigned char mode,
												unsigned char formatdata,unsigned char *format,
												unsigned char level,unsigned char data_len,
												unsigned char *zip_id,unsigned char uartx)
{
	const struct TREE_LEAF *Tree_Leaf;
	const struct TREE_NODE *Tree_Node;
	const struct COMMUNAL_REVISE 		*Communal_Revise;
	const struct COMMUNAL_ID		 *Communal_Id;
	const struct REVISE_ID          *REVISE_ID;
	unsigned int node,Revise,Revise_file;
	unsigned char zip_leaf_start,zip_leaf_end,getlen,ret,i,id_n,block_flag;
	signed int i_ret;
	
	node=node_addr;
	getlen=0;/*"?"*/
	//flag=0;	
/*"������ڵ㲻�ǵ�һ��ڵ���ô��Ҫ���㣬��Ϊѹ�������ѭ������"*/
	zip_leaf_start=0xff;
	zip_leaf_end=0xff;
	id_n=0xff;
	if(level!=0)
	{
		get_leaf_cyc_para(node_addr,&zip_leaf_start,&zip_leaf_end);				
	}
	
	do
	{
		Tree_Node=(const struct TREE_NODE *)&Protocol_Tree_Node[node];
		block_flag=Tree_Node->Node_mode.bit.zip;
		
		if(Tree_Node->Node_mode.bit.mode==0)
		{	
			/*"����˽ڵ�ָ�����Ҷ�ӣ���д����"*/
			i_ret=0;
			/*"Ҷ��"*/
			Tree_Leaf=(const struct TREE_LEAF *)&Protocol_Tree_Leaf[Tree_Node->Low_Node];
			Communal_Id      =(const struct COMMUNAL_ID 			*)&Protocol_Id[Tree_Leaf->Communal_Id];
			REVISE_ID        =(const struct REVISE_ID         *)&Protocol_Revise_Id[Tree_Leaf->Communal_Addr_Id];
	
			/*"����zip�����ַ������ֵ"*/
			/*"�����ַ����ֵ���ȼ����һ�飬Ȼ���ڵ�һ������ϼ���ڶ���"*/	
			id_n=set_zip_id(zip_id,zip_leaf_start,id_n);
			Revise=0;
			Revise_file=0;
			for(i=0;i<2;i++)
			{
				Communal_Revise=(const struct COMMUNAL_REVISE *)&Protocol_Revise[REVISE_ID->Revise_Id[i]];
				Revise+=Revise_Addr(0,Communal_Revise,*(zip_id+i),REVISE_ADDR_TYPE);
				Revise_file+=Revise_Addr(0,Communal_Revise,*(zip_id+i),REVISE_FILE_TYPE);
			}
			
			if((mode==0x00)||(mode==0x01))/*"��"*/
			{          
			  Iterate_Tree_Flag[uartx].num++;
				Leaf_num_now=Iterate_Tree_Flag[uartx].num;
				if(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num)
					i_ret=Get_Leaf_Data(Tree_Node->Low_Node,buff+getlen,formatdata,format,Revise,Revise_file,uartx);
				
				if(i_ret==0xff) 
					{
						Iterate_Tree_Flag[uartx].flag.bit.b3=1;/*"��λ��ƥ���־"*/
						return 0;
					}

				if(i_ret==0x99)
					i_ret=1;/*" λҶ�ӱ������⴦��"*/
				
				if(getlen+i_ret<len)
					{
					   getlen+=i_ret;
					   
					}
				else
					{/*"buf�Ѿ������˳��Ⱥ���֡����"*/
						Iterate_Tree_Flag[uartx].flag.bit.b0=1;/*"��������־"*/
						Iterate_Tree_Flag[uartx].flag.bit.b1=1;/*"��������־"*/
						Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
						Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].num-1;
						return getlen;
					}
			}
			else if(mode==0x02)/*"д"*/
			{
				i_ret=Set_Leaf_Data(Tree_Node->Low_Node,buff+getlen,formatdata,format,Revise,uartx);
				if(i_ret==0)   return 0;
				if(i_ret==0x99)  i_ret=0;/*" λҶ�ӱ������⴦��"*/
				getlen+=i_ret;
			}
			else /*"   ��ʾ"*/
			{     
     			  Iterate_Tree_Flag[uartx].num++;
				if(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num)
				{	
					i_ret=Get_Leaf_Data(Tree_Node->Low_Node,buff+getlen,formatdata,format,Revise,Revise_file,uartx);
										
					if(i_ret!=0)
					{ 
					       if(i_ret==0x99) 
						   {
						   		Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].num;
								i_ret=1;
							}/*" λҶ�ӱ������⴦��"*/
						
						 	   
						 	  /*" ������ʾ��Ҫ�Ĵ����ʽ����ʾ��ʽID "*/	
							if(Iterate_Tree_Flag[uartx].flag.bit.b4==1)
							    *format=Communal_Id->Communal_Trans_Id;
							else
								*format=Communal_Id->Communal_Show_Id;

							format++;
					 	 	  *((unsigned int *)format)=Tree_Leaf->Communal_Showinfo_Id;

						  	return i_ret;
					}
				}					
			}
			/*****************************************/
			/*****************************************/
		}
		else
		{
			id_n=set_zip_id(zip_id,zip_leaf_start,id_n);
			i_ret=Traverse_Node_sub(Tree_Node->Low_Node,buff+getlen,len-getlen,mode,formatdata,format,
																level+1,data_len,zip_id,uartx);
																
				        
			getlen=getlen+i_ret;

			if(((mode==0x00)||(mode==0x01))&&(i_ret==0x00)&&(Iterate_Tree_Flag[uartx].flag.bit.b3==1))  return 0;/*"������ʧ�ܳ��� fuxf add 081228  "*/
			
			if(Iterate_Tree_Flag[uartx].flag.bit.b1==1)    return getlen;  /*"��������־"*/			   	
	
			if((mode==0x02)&&(i_ret==0))				return 0;     						 /*"   д����ʧ�ܳ���"*/					
			
			if((mode==0x03)&&(i_ret==0xff))        return 0;   					/*"   ��ʽ����ȷ   ��ʾʧ�ܳ���"*/	

			if((mode==0x03)&&(i_ret!=0))        return getlen;   					/*"   ��ʾ����"*/	
			
			
		}
		/*"����"*/				

		if(level==0)
		{
			/*"�����ĸ��ڵ��������"*/
			if(mode == 1)/*"������֡ģʽ"*/
			{
					Iterate_Tree_Flag[uartx].flag.bit.b5 = 1;/*"����֡���һ֡����"*/
				  Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
						//Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].num-1;
			}
			return getlen;
		}
		if(zip_leaf_start<zip_leaf_end)
		{/*"��ѹ��,δ�������"*/
			zip_leaf_start++;
			ret=0;	
		}
		else
		{/*"��ɱ���"*/
			ret=check_node_point(Tree_Node->Next_Node);
			node=Tree_Node->Next_Node;	
			id_n=set_zip_id(zip_id,0xff,id_n);
			id_n=0xff;
		}
		if(((mode==0x00)||(mode==0x01))&&(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num))
			{	
				if(block_flag==1)
				{	/*"��ӿ�ָ���0xaa"*/
					*(buff+getlen)=0xAA;
					getlen++;
				}
			}
		/*"ret==0��һ��ͬ���ڵ���Ч"*/
		/*"ret==0xff����һ��ͬ���ڵ㷵���ϼ��׶�"*/			
	}while(ret==0);
	return getlen;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�ҵ��ڵ�������д�ڵ�������"*/
/*"node_addr, ��Ҫ��д�Ľڵ��λ��"*/
/*"*buff,     ����"*/
/*"len,       �����С ���ݴ˴�С��֡  "*/
/*"mode        ģʽ,b0=0����b0=1д��b1=0��ʼ��ȡ��b1=1������ȡ"*/
/*"formatdata, ���ݸ�ʽ"*/
/*"*format,    ������ʱ�ķ��ظ�ʽ"*/
/*"data_len ����֡���������ݳ���"*/
signed int Traverse_Node(unsigned int node_addr,unsigned char type,unsigned char *buff,
												unsigned int len,unsigned char mode,
												unsigned char formatdata,unsigned char *format,
												union ID id,unsigned char data_len,unsigned char uartx)
{

	unsigned char i,getlen,zip_id[2];
	signed int i_ret; 
	union CHECK_NODE_ID_RET zip;
	
	/*"��ѹ����ID���д���"*/
	zip.byte=type;	
	if(zip.bit.zip1==1)
       zip_id[0]=id.d[zip.bit.num1];	
	else
		zip_id[0]=0xff;	
		
	if(zip.bit.zip2==1)
		zip_id[1]=id.d[zip.bit.num2];
	else
		zip_id[1]=0xff;
	
	/*"����֡��Ϣ"*/
	Iterate_Tree_Flag[uartx].num=0;
	Iterate_Tree_Flag[uartx].flag.bit.b1=0;
	Iterate_Tree_Flag[uartx].flag.bit.b3=0;
	Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0;	
	Leaf_num_now=0;
	
	/*"��ʼ����д���ݱ���"*/
	for(i=0;i<32;i++)
	  Readdata_buff[i]=0;
    Read_Com_ID=id;

	if(mode==0x00)/*"��ʼ��"*/
	{		
		Iterate_Tree_Flag[uartx].flag.bit.b0=0;
		Iterate_Tree_Flag[uartx].flag.bit.b5=0;	
		Iterate_Tree_Flag[uartx].last_num=0;
		Iterate_Tree_Flag[uartx].last_num_save=0;
		Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
	}
	else if(mode==0x01)/*"������"*/
	{
			if((Iterate_Tree_Flag[uartx].flag.bit.b0==0) && (Iterate_Tree_Flag[uartx].flag.bit.b5==0))/*"��������־"*/
			{
				if(0xff != Event_Report_flag)
				{
					return 0;
				}
				  
			}
			else   
				{				
				Iterate_Tree_Flag[uartx].flag.bit.b0=0;	
				
				}
			/*"���һ֡������󣬶�����ֻ֡�����ض����һ֡����֡"*/
			if((Iterate_Tree_Flag[uartx].flag.bit.b5==1) && (Iterate_Tree_Flag[uartx].flag.bit.b2 == 0))
				{
				if(0xff != Event_Report_flag)/*"��������س����һ֡���ݣ�ֻ�����¼������ϱ�"*/
				{
					return 0;
				}	
				else
				{
				Iterate_Tree_Flag[uartx].last_num = 0;
				}
				}
			else
				{
				Iterate_Tree_Flag[uartx].flag.bit.b5=0;	
				}
							

			if(Iterate_Tree_Flag[uartx].flag.bit.b2==1)
				{	
					Iterate_Tree_Flag[uartx].flag.bit.b2=0;
					Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].last_num_save;
				}
	}		
	else 	if(mode==0x03)
	{			
			if(((id.l>=0x04000501)&&(id.l<=0x04000906)&&(id.l!=0x04000802))	
				||((id.l>=0x0e000001)&&(id.l<=0x0e00000A))
				||(id.l==0x0E000901)
				||(id.l==0x04001101)
				||((id.l>=0x0400E201)&&(id.l<=0x0400E203)))			//payment
			{/*"�ڴ˴�����λҶ�����ݱ�ʶ"*/		
				  Iterate_Tree_Flag[uartx].Show_bit_flag=0xff;
			}	
			else
			{			
			    Iterate_Tree_Flag[uartx].Show_bit_flag=0;
			}
			if((Iterate_Tree_Flag[uartx].Show_bit_flag==0xff)&&(len!=0))/*"   λ��ʽ����FXF 20081124 "*/
			{
				  if(len==1)
				  {
				     Iterate_Tree_Flag[uartx].last_num=8; /*"λҶ����ʾȡ������"*/		
				  }
				  else	if(len==2)
				  {
					   Iterate_Tree_Flag[uartx].last_num=16; 
				  }
				  else
					   return 0;
			}
			else
			{
			      Iterate_Tree_Flag[uartx].last_num=len; /*"��ʾȡ������"*/	
			}
	}

	if(mode!=0x02)
	{
		Read_event_first_flag=PrepNewFirstEventData(id.l);
	}
	else
	{
		Read_event_first_flag=0;
	}
	
	getlen=0;
	i_ret=Traverse_Node_sub(node_addr,buff,len,mode,formatdata,format,0,data_len,zip_id,uartx);	

	if((mode==0x03)&&(i_ret==0xff))        return 0;   /*"    �ڶ�Ҷ�����ݸ�ʽ����ȷ  ��ʾʧ�ܳ���"*/	

	return i_ret;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"����Ҷ�ӵ�ַ"*/
unsigned char search_leaf(unsigned int node_addr,unsigned int *addr)
{
	const struct TREE_NODE *tree_node;
	unsigned char ret;
	
	tree_node=(const struct TREE_NODE *)&Protocol_Tree_Node[node_addr];
	if(check_node((const unsigned char *)tree_node)==0xff)
		{			
			return 0xFF; /*"�Ƿ���ַ"*/
		}
	
	if(tree_node->Node_mode.bit.mode==0)
		{
			*addr=node_addr;
			return 0;
		}
	else
		{
			if(check_node_point(tree_node->Low_Node)==0xff)
				{
					
					return 0xff;
				}
			ret=search_leaf(tree_node->Low_Node,addr);
			return ret;
		}
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
signed int Get_Leaf_Data(unsigned int leaf_addr,unsigned char *buff,
												unsigned char formatdata,unsigned char *format,
												unsigned int Revise,unsigned int Revise_file,unsigned char uartx)
{
	unsigned char format_temp,save_format_temp,dbuf[MAX_FUN_BUFF_SIZE],i,s_len,ret;
	const struct TREE_LEAF *Tree_Leaf;
	const struct COMMUNAL_FORMAT 		*Communal_Save;
	const struct COMMUNAL_FORMAT 		*Communal_Trans;
	const struct COMMUNAL_FORMAT 		*Communal_Show;
	const struct COMMUNAL_PURVIEW 	*Communal_Purview;
	const struct COMMUNAL_FUNCTION 	*Communal_Function;
	const struct COMMUNAL_MATHINFO	*Communal_Mathinfo;
	const struct COMMUNAL_ID				*Communal_Id;

	union TREEADDR Treeaddr;
	signed char  exp_temp;
	unsigned char  bit_temp,ctemp,unit_temp;	
	unsigned char *Ram_Data_Addr;
	unsigned char math_mode;
	unsigned  int  uni,f_temp, Bit_data=0,file_name=0;//FXF add 
       unsigned char Data_valid_flag=0xff;        //fxf add 081109     
       signed long Demand_data =0;
       unsigned long add_temp = 0;
	ret=0;
	Comm_Data_valid_flag=0xff;
	Tree_Leaf=(const struct TREE_LEAF *) &Protocol_Tree_Leaf[leaf_addr];
	Communal_Purview =(const struct COMMUNAL_PURVIEW *)&Protocol_Purview[Tree_Leaf->Communal_Purview_Id];
	Communal_Function=(const struct COMMUNAL_FUNCTION *)&Protocol_Function[Tree_Leaf->Communal_Function_Id];
	Communal_Id=(const struct COMMUNAL_ID *)&Protocol_Id[Tree_Leaf->Communal_Id];
	Communal_Save=(const struct COMMUNAL_FORMAT	*)&Protocol_Format[Communal_Id->Communal_Save_Id];
	Communal_Trans=(const struct COMMUNAL_FORMAT  *)&Protocol_Format[Communal_Id->Communal_Trans_Id];
	Communal_Show=(const struct COMMUNAL_FORMAT  *)&Protocol_Format[Communal_Id->Communal_Show_Id];
	Communal_Mathinfo=(const struct COMMUNAL_MATHINFO *)&Protocol_MATHINFO[Tree_Leaf->Communal_Math_Mode_Id];
	/*"�ж������ݵ�Ȩ��"*/
	if(Comm_Staut.meter_staut==0x11)/*"����"*/
		ctemp=0x01;
	else if(Comm_Staut.meter_staut==0x22)/*"ʵ����"*/
		ctemp=0x02;
	else /*"�ֳ�"*/
		ctemp=0x04;
	if(((Communal_Purview->read_mode&ctemp)&0x07)==0)
	{
		Meter_States.ErrOfInformation.bit.Invalid_Password=1;
		return 0;/*"�ڴ�״̬�²������"*/	
	}	

	if(Communal_Function->OnRead!=0)
    {			/*"-1��ʾ�������ݲ���������ڶ�������"*/	
				if(Communal_Function->OnRead()==-1)
							   return 0;							
    }

/*"ȡ��Ϸ�ʽ��"*/	
	if(Communal_Mathinfo->math_mode<0x100)
		{		/*"ֻ��һ�ֽ���ЧΪ������"*/
				math_mode=Communal_Mathinfo->math_mode;
		}
	else
		{
				/*"���ֽ���ЧΪ��ַ"*/
				Ram_Data_Addr=(unsigned char *)Communal_Mathinfo->math_mode;
				math_mode=*Ram_Data_Addr;
		}
	/*"�洢�����ݵĳ���"*/	
	s_len=sizeof_format(Communal_Save->format);
	
	save_format_temp=Communal_Save->format;
	/*"ȡ��������dbuf�Ŀ�ʼ�ֽڣ��������ϼ��������"*/	
	for(i=0;i<MAX_FUN_BUFF_SIZE;i++)
		dbuf[i]=0;	

	 Treeaddr.val=Tree_Leaf->addr;
	 if(Read_event_first_flag==0xff)
	 {
	 		Treeaddr.flash.path=0x00;
            Show_ID_vatiy=0xff;
	 }
	 
	switch(Treeaddr.val&0xf0000000)
	{
		case _RAM:/*"�ڴ�����"*/
			 if(Read_event_first_flag==0xff)
	        {   
	             f_temp=Treeaddr.flash.addr+Revise;
				if(f_temp>=400)
					        return   0;
                Ram_Data_Addr=(unsigned char *)&TempEventData[f_temp];
	        }
			else
			{
				Ram_Data_Addr=(unsigned char *)((Treeaddr.ram.addr)+Revise);
			}

			ret=Ram_math(Communal_Mathinfo->math_type,Ram_Data_Addr,(unsigned char *)&dbuf[0],math_mode,Communal_Save->format,
															Communal_Mathinfo->Ass_data_num,Communal_Mathinfo->Ass_data_addr);
				s_len=ret;			
		
			break;
		case _EEPROM1:
			f_temp=Treeaddr.eeprom.addr+Revise;

			ret=Eeprom_math(Communal_Mathinfo->math_type,f_temp,(unsigned char *)&dbuf[0],math_mode,Communal_Save->format,
										Communal_Mathinfo->Ass_data_num,Communal_Mathinfo->Ass_data_addr,0);
			s_len=ret;
	
			/*"�����ݶ�����dbuf[0]"*/
			break;
		case _FLASH:
            Show_ID_vatiy=0xff;
			if(IntoPowerDownFlag!=0)  /*"�͹����²�������FLASH����"*/
				return 0;
			file_name=Treeaddr.flash.filename+Revise_file;
			f_temp=Treeaddr.flash.addr+Revise;			
			ret=Flash_math(Communal_Mathinfo->math_type,f_temp,(unsigned char *)&dbuf[0],math_mode,Communal_Save->format,
										Communal_Mathinfo->Ass_data_num,Communal_Mathinfo->Ass_data_addr,file_name);
			s_len=ret;		
			
		break;
		default:    
	      ret=0; break;
	}

	/*"  ��������,���ȫΪOXFF����ʾ����Ч FXF ADD 081109 "*/
		if(((Check_Data_valid(dbuf,s_len)==-1)&&(Communal_Mathinfo->math_type!=1)
		&&(!((Communal_Mathinfo->math_type==0)&&((save_format_temp==SIGNED_LONG)||(save_format_temp==SIGNED_INT)||(save_format_temp==SIGNED_CHAR)))))
		||(Comm_Data_valid_flag==0))
					 Data_valid_flag=0; 

			
		if(uartx==0x03)  	 Iterate_Tree_Flag[uartx].Show_bit_flag=0x00;
			
			
		
	
/*"���ƺ͵�λ ��С����  ��ת��"*/
	if(formatdata==COMMFORMAT)
	{	
			if(Communal_Trans->exp==Mauto)
        exp_temp=-2;
    	else if(Communal_Trans->exp==Dauto)
        exp_temp=-4;  
		else if (Communal_Trans->exp==RMB_Mauto)		//payment
				exp_temp=-2;
			else	
			  exp_temp=Communal_Trans->exp;

			format_temp=Communal_Trans->format;
			unit_temp=Communal_Trans->unit;
	}
	else if(formatdata==SHOWFORMAT)
	{	
			if(Communal_Show->exp==Mauto)
        		///if((Meter_Parameter.parameter2.EnergyPoint>=2)&&(Meter_Parameter.parameter2.EnergyPoint<=4))
        		if(Meter_Parameter.parameter2.EnergyPoint<4)
        		 	exp_temp=0-Meter_Parameter.parameter2.EnergyPoint;
        		else
        		 	exp_temp=-2;
  	 	else if(Communal_Show->exp==Dauto)
        		///if((Meter_Parameter.parameter2.PowerPoint>=2)&&(Meter_Parameter.parameter2.PowerPoint<=4))
        		if(Meter_Parameter.parameter2.PowerPoint <= MAXDAUTOVALUE)
        			exp_temp=0-Meter_Parameter.parameter2.PowerPoint;
        		else
        			exp_temp=-4;  
		else if (Communal_Show->exp==RMB_Mauto)		//payment	
			{
				if (PRE_MONEY_POINT==2)
						exp_temp=-2;
					else
						exp_temp=0;
			}
			else	
				exp_temp=Communal_Show->exp;
		/*"û����ʾ��ʽʱ��ʹ��ͨ�Ÿ�ʽ"*/
		if(Communal_Show->format==0)     					
		{   
		     format_temp=Communal_Trans->format;				 
			 unit_temp=Communal_Trans->unit;
			 Iterate_Tree_Flag[uartx].flag.bit.b4=1;
		}			
		else     
		{
			format_temp=Communal_Show->format;				
			unit_temp=Communal_Show->unit;			
			Iterate_Tree_Flag[uartx].flag.bit.b4=0;
		}
	}	
	else 
	{
			exp_temp=Communal_Trans->exp;
			format_temp=formatdata;		
			unit_temp=0;
	}

	 /*"�����͹�����������"*/                  
	if(((Communal_Trans->exp==Dauto)||(Communal_Show->exp==Dauto))&&(Data_valid_flag==0xff))
	{
            for(i=0;i<ret;i++)/*"�޳�ȫ0"*/
            {
                if(dbuf[i]!=0)
                    break;
            }
            if(i!=ret)
            {
                if(Communal_Save->format!=BCD3BYTE)
                {
                    Demand_data=*((signed long *)&dbuf[0]);
                    ///if((exp_temp>=-4)&&(exp_temp<=-2))
                    if((exp_temp>=((-1)*(MAXDAUTOVALUE-1)))&&(exp_temp<=0))
                    {
                        add_temp=5L*ten_seq(MAXDAUTOVALUE-1+exp_temp);
                    }
                    else if(exp_temp==((-1)*(MAXDAUTOVALUE)))
                    {
                        add_temp=0;
                    }
			              else
			              {
			                return 0;
			              }
			        if(Demand_data>=0)
				        Demand_data+=add_temp;
			        else
				        Demand_data-=add_temp;
			        *((signed long *)&dbuf[0])=Demand_data;
                } 
            }
	}   
		
	if(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num)	 //FXF ADD 081109	
	{
			if(Data_valid_flag==0xff)	 //FXF ADD 081109	
				{
				  ret=data_change(&dbuf[0],buff,save_format_temp,format_temp,
														Communal_Save->unit,unit_temp,Communal_Save->exp,exp_temp);		
			  }
			else  
				{
						ret=sizeof_format(format_temp);
						for(i=0;i<ret;i++)
							    *(buff+i)=dbuf[i];
							    
						if(eventfreezereadflag==1)
						{
							  for(i=0;i<ret;i++)
							    *(buff+i)=0;
						}
									
				}	
	}
	else
	{
	 	 ret=0;	
	}

	*format=format_temp;
	FeedWatchdog();
		
	return ret;	
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
signed int Set_Leaf_Data(unsigned int leaf_addr,unsigned char *buff,
												unsigned char formatdata,unsigned char *format,
												unsigned int Revise,unsigned char uartx)
{
	unsigned char format_temp,dbuf[MAX_FUN_BUFF_SIZE],i,s_len;
	const struct TREE_LEAF *Tree_Leaf;
	const struct COMMUNAL_FORMAT 		*Communal_Save;
	const struct COMMUNAL_FORMAT 		*Communal_Trans;
	const struct COMMUNAL_PURVIEW 	*Communal_Purview;
	const struct COMMUNAL_FUNCTION 	*Communal_Function;
	const struct COMMUNAL_MATHINFO	*Communal_Mathinfo;
	const struct COMMUNAL_ID				*Communal_Id;
	
	unsigned char *Ram_Data_Addr;
	unsigned char math_mode,trans_format_temp,bit_temp,password_level;
	signed long l_temp;
	unsigned long *pl_remp,Eeprom_addr,ul_temp;
	unsigned int Save_bit=0,Tran_bit=0,Bit_data=0;
	int ret=0;
	signed char  exp_temp;		
	
	Tree_Leaf=(const struct TREE_LEAF *) &Protocol_Tree_Leaf[leaf_addr];
	Communal_Purview =(const struct COMMUNAL_PURVIEW  *)&Protocol_Purview[Tree_Leaf->Communal_Purview_Id];
	Communal_Function=(const struct COMMUNAL_FUNCTION *)&Protocol_Function[Tree_Leaf->Communal_Function_Id];
	Communal_Id      =(const struct COMMUNAL_ID 			*)&Protocol_Id[Tree_Leaf->Communal_Id];
	Communal_Save    =(const struct COMMUNAL_FORMAT		*)&Protocol_Format[Communal_Id->Communal_Save_Id];
	Communal_Trans   =(const struct COMMUNAL_FORMAT   *)&Protocol_Format[Communal_Id->Communal_Trans_Id];
	Communal_Mathinfo=(const struct COMMUNAL_MATHINFO *)&Protocol_MATHINFO[Tree_Leaf->Communal_Math_Mode_Id];
		if(Comm_Staut.meter_staut==0x11)/*"����"*/
			i=0;
		else if(Comm_Staut.meter_staut==0x22)/*"ʵ����"*/
			i=1;
		else /*"�ֳ�"*/
			i=2;		
			
		if(Check_Parameter_Len_IS_ok(Communal_Trans->format)==-1)  /*"�����ò�����ʱ��Գ����ж�fxf 081218"*/
			{
				Meter_States.ErrOfInformation.bit.Invalid_Data=1;
				return 0;
			}
		/*"   ���� Ȩ����Ϊ0����ʾ����дfxf 081122"*/
		if(Communal_Purview->write_mode[i]==0x00)
		{
				Meter_States.ErrOfInformation.bit.Invalid_Password=1;
				return 0;
		}			
				
		/*"   ��Ҫ�ж�����fxf 081122"*/
		if( Far_Spec_Order_Flag != 0xFF )		//payment
			{
			if((Communal_Purview->write_mode[i]&0x01)==0x00)	
				{
					if((Communal_Purview->write_mode[i]&0x02)==0x02)
						password_level=0;/*"0������"*/
					else if((Communal_Purview->write_mode[i]&0x04)==0x04)
						password_level=1;/*"1������"*/
					else if((Communal_Purview->write_mode[i]&0x08)==0x08)
						password_level=2;/*"2������"*/
					else if((Communal_Purview->write_mode[i]&0x10)==0x10)
						password_level=3;/*"3������"*/
					else if((Communal_Purview->write_mode[i]&0x20)==0x20)
						password_level=4;/*"4������"*/
					else if((Communal_Purview->write_mode[i]&0x40)==0x40)
						password_level=5;/*"5������"*/
					else password_level=9;/*"ĩ������"*/
					
					if((Comm_Staut.password_level)>password_level)
					{			
						Meter_States.ErrOfInformation.bit.Invalid_Password=1;
						return 0;/*"�ڴ�����ȼ��²���д"*/
					}
					
				}
			}

		if (((Communal_Purview->write_mode[i]&0x80)!=0)&&(Far_Spec_Order_Flag!=0xFF))   //payment
		{
			Meter_States.ErrOfInformation.bit.Invalid_Password=1;
			return 0;/*"��ҪǦ�ⰴ�����£�����û�а��£�����д"*/
		}


	/*"д֮ǰ�ĺ���һ���������������Ƿ��޺ͼ�¼�¼�"*/		
	 if((Communal_Function->OnWrite_Beford!=0)&&(Iterate_Tree_Flag[uartx].Set_Prarmeter_flag==0))//FXF ADD  081115
	{
	 	if(Communal_Function->OnWrite_Beford()==-1) /*"  д����ʧ��"*/
					return 0;	

		Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0xff;
	 }
	 
			
	/*"д������ݵĳ���"*/	
	if(formatdata==COMMFORMAT)
	{	
		if(Communal_Trans->exp==Mauto)/*"���ó�ʼ����"*/
        	exp_temp=-2;     
		else if (Communal_Trans->exp==RMB_Mauto)		//payment
        	exp_temp=-2;     
	    else	
			  exp_temp=Communal_Trans->exp;
			
		format_temp=Communal_Trans->format;
	}
	else
	{	
		format_temp=formatdata; 
	}

	s_len=sizeof_format(format_temp);
	/*"��Ҫд�����ݷ�buf"*/	
	for(i=0;i<MAX_FUN_BUFF_SIZE;i++)
		dbuf[i]=0;



	ret=data_change(buff,&dbuf[0],format_temp,Communal_Save->format,
					Communal_Trans->unit,Communal_Save->unit,
					exp_temp,Communal_Save->exp);		

	if(ret==0xff)  	return 0;
	else      	ret=0;

/*"��ʼ����"*/	
	switch(Tree_Leaf->addr&0xf0000000)
	{
		case _RAM:/*"�ڴ�����"*/
				Ram_Data_Addr=(unsigned char *)Tree_Leaf->addr;
			
				for(i=0;i<s_len;i++)
					*(Ram_Data_Addr+Revise+i)=dbuf[i];
				
		break;
		case _EEPROM1:			
				Eeprom_addr=((Tree_Leaf->addr)&0x0fffffff)+Revise;				
				if ((Eeprom_addr>=PRE_PAYMENT_PARA_EE)&&(Eeprom_addr<PAY_FOR_EVENT_POINT_EE))		//payment
					{
					Pay_EE_W(Eeprom_addr,(unsigned char *)&dbuf[0],s_len,3,
							(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
					}
				else if((Eeprom_addr>=METER_PARAMETER_ROM)&&(Eeprom_addr<JUSTMETER_PARA_ROM))
					{
					s_len=sizeof_format(Communal_Save->format);
					WRLC256(Eeprom_addr,(unsigned char *)&dbuf[0],s_len,0,0);						
					//WRLC256(Eeprom_addr,(unsigned char *)&dbuf[0],s_len,WriteWhitchEeprom[1],0);	
					}
					else
					{
							WRLC256(Eeprom_addr,(unsigned char *)&dbuf[0],s_len,0,0);	
					}
						
				FeedWatchdog();
				if((Eeprom_addr>=METER_PARAMETER_ROM)&&(Eeprom_addr<JUSTMETER_PARA_ROM))
				{
					Ram_Data_Addr=(unsigned char *)&Meter_Parameter;
					ul_temp=METER_PARAMETER_ROM;
					Ram_Data_Addr+=Eeprom_addr-ul_temp;
					WRLC256(Eeprom_addr,Ram_Data_Addr,s_len,0,1);	
					Set_Meter_para_Deal(Eeprom_addr);	
				}
				else if ((Eeprom_addr>=PRE_PAYMENT_PARA_EE)&&(Eeprom_addr<PAY_FOR_EVENT_POINT_EE))		//payment
				{
					ul_temp=PRE_PAYMENT_PARA_EE;
					Ram_Data_Addr=(unsigned char *)&Pre_Payment_Para;
					Ram_Data_Addr+=Eeprom_addr-ul_temp;
					WRLC256(Eeprom_addr,Ram_Data_Addr,s_len,0,1);		
				}
		break;		
		case _FLASH:
			     return 0;			
		break;
		default:    
	      return 0;
		
	}

	if((Communal_Function->OnWrite_End!=0)&&(Iterate_Tree_Flag[uartx].Set_Prarmeter_flag==0))
	{
		ret=Communal_Function->OnWrite_End();
		Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0xff;
	}
	

	if(ret==0)
		return s_len;
	else 
		return 0;
		
}
unsigned char Ram_math(unsigned char mode,unsigned char * startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr)
{
	unsigned char i,ret;
	switch(mode)
	{
		case 0:
			ret=sizeof_format(format);
			memcpy(getbuff,startaddr,sizeof_format(format));
			break;
		case 1:
			//ret=Ram_math_Add(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr);
			ret=math_Add(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr, RAM_MATH);
			break;
		case 0xfe:
			//ret=Ram_math_Demand(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr);
			ret=math_Demand(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr, RAM_MATH);
			break;			
		default:
			ret=-1;	
		
	}
	return ret;
}
/*"*****************************************************************************"*/
/*"  Function:       math_Add"*/
/*"  Description:    ������ϼ���,�����������ģʽ�֣������������ֵ"*/
/*"  Calls:"*/
/*"  Called By:"*/
/*"  Input:          startaddr  ������ϼ���������ʼ��ַָ��,"*/
/*"                             ���ΪEEPROM��FLASH��ָ��ָ�����EEPROM��FLASH��ַ"*/
/*"                  math_mode  ��ϼ���ģʽ"*/
/*"                  format     ���ݸ�ʽ"*/
/*"                  Ass_num    ������ϼ����Ա��"*/
/*"                  Ass_addr   ������ϼ����Աƫ�Ƶ�ַ"*/
/*"                  filename   0~5000 Ϊflash�ļ�����"*/
/*"                             RAM_DEMAND_MATH��ʾRAM������"*/
/*"                             EEPROM_DEMAND_MATH��ʾEEPROM������"*/
/*""*/
/*"  Output:         getbuff  ��ϼ�����"*/
/*""*/
/*"  Return:         ���ݳ���"*/
/*"  Others:"*/
/*"*****************************************************************************"*/
unsigned char math_Add(unsigned char * startaddr,unsigned char * getbuff ,
						unsigned char math_mode,unsigned char format,
						unsigned char Ass_num,unsigned char Ass_addr, unsigned int  file_name)
{
	unsigned char *Ram_UC_Data_Addr;
	unsigned char i,j,s_len;
	signed long buff[4];
	signed long long sum=0;
	unsigned int i_ret = 0xff;
		 
	s_len=sizeof_format(format);
	for(i=0;i<4;i++)
		buff[i]=0;
	
	
	/*"ȡ��"*/
	for(i=0;i<Ass_num;i++)
	{
		Ram_UC_Data_Addr=(unsigned char *)&buff[i];
		switch(file_name)
	      {
	        case RAM_MATH:
	        for(j = 0; j < s_len; j++)
	        {
	            *(Ram_UC_Data_Addr + j) = *(startaddr + Ass_addr * i + j);
	        }
	        break;
	       case EEPROM_MATH:
	        i_ret = ReadBlock(*((unsigned int *)startaddr) + Ass_addr * i,Ram_UC_Data_Addr,s_len, 0);
	        break;
	       default:
	        i_ret=Read_File(file_name,*((unsigned int *)startaddr) + Ass_addr * i, s_len, Ram_UC_Data_Addr);
	        break;
	    }		

        /*"  �����¼���¼���������,���������һ��ȫΪOXFF����ʾ��?FXF ADD 081109 "*/
		if((Check_Data_valid((unsigned char *)&buff[i], s_len) == -1) || (i_ret == 0))
		{	
			Comm_Data_valid_flag=0;
			for(i=0;i<4;i++)
			{
				*(getbuff+i)=0xff;
			}
			return 4;
		}		
	}	
	
		
	/*"���"*/
	for(i=0;i<Ass_num;i++)
	{
		switch(math_mode&0x03)
		{
			case 0x01:
				sum+=buff[i];
				break;
			case 0x02:
				sum-=buff[i];
				break;
//			default:
//				sum+=0;
		}
		math_mode>>=2;
	}
	sum%=800000000l;
	Ram_UC_Data_Addr=(unsigned char *)&sum;
	for(i=0;i<4;i++)
	{
		*(getbuff+i)=*(Ram_UC_Data_Addr+i);
	}
	return 4;
}

/*"*****************************************************************************"*/
/*"  Function:       math_Demand"*/
/*"  Description:    ������ϼ���,�����������ģʽ�֣������������ֵ"*/
/*"  Calls:          "*/
/*"  Called By:      "*/
/*"  Input:          startaddr  ������ϼ���������ʼ��ַָ��,"*/
/*"                             ���ΪEEPROM��FLASH��ָ��ָ�����EEPROM��FLASH��ַ"*/
/*"                  math_mode  ��ϼ���ģʽ"*/
/*"                  format     ���ݸ�ʽ      "*/
/*"                  Ass_num    ������ϼ����Ա��"*/
/*"                  Ass_addr   ������ϼ����Աƫ�Ƶ�ַ"*/
/*"                  filename   0~5000 Ϊflash�ļ�����"*/
/*"                             RAM_DEMAND_MATH��ʾRAM������        "*/
/*"                             EEPROM_DEMAND_MATH��ʾEEPROM������"*/
/*"                  "*/
/*"  Output:         getbuff  ��ϼ����� "*/
/*"  "*/
/*"  Return:         ���ݳ���"*/
/*"  Others:         "*/
/*"*****************************************************************************"*/
unsigned char math_Demand(unsigned char * startaddr,unsigned char * getbuff ,
							 unsigned char math_mode,unsigned char format,
							 unsigned char Ass_num,unsigned char Ass_addr, unsigned int file_name)
{
	unsigned char *Ram_UC_Data_Addr;
	unsigned char i,j;
	unsigned char buff[4][9];
	struct DEMAND_DATA_FORM *point;
	struct DEMAND_DATA_FORM temp;	
	unsigned int i_ret = 0xff;
	
	for(i=0;i<4;i++)
		for(j=0;j<9;j++)
			buff[i][j]=0;	
	/*"ȡ��"*/
	for(i=0;i<Ass_num;i++)
	{
		switch(file_name)
		{
		case RAM_MATH:
			for(j = 0; j < 9; j++)
			{
				buff[i][j] = *(startaddr + Ass_addr * i + j);
			}	
			i_ret = 9;
			break;
		case EEPROM_MATH:
			 i_ret = ReadBlock(*((unsigned int *)startaddr) + Ass_addr * i,(unsigned char *)&buff[i], 9, 0);

			break;
		default:
			i_ret=Read_File(file_name, *((unsigned int *)startaddr) + Ass_addr * i,  9, (unsigned char *)&buff[i]);

			break;
		}
		if((Check_Data_valid((unsigned char *)&buff[i],9)==-1)||(i_ret==0))
		{
		    Comm_Data_valid_flag=0;
		    for(j=0;j<9;j++)
		    {
		        *(getbuff+j)=0xff;
		    }
		    return 9;
		}
	}			
	
	/*"���"*/
	temp.Demand=0;
	for(i=0;i<5;i++)
			temp.time[i]=0;
	for(i=0;i<Ass_num;i++)
	{
		if((math_mode&0x03)!=0)
		{
			point=(struct DEMAND_DATA_FORM *)&buff[i][0];	
			if(point->Demand>temp.Demand)
				{
					temp.Demand=point->Demand;
					memcpy((unsigned char*)&temp.time[0],(unsigned char*)&point->time[0],5);
				}
		}
		math_mode>>=2;
	}
	
	Ram_UC_Data_Addr=(unsigned char *)&temp.Demand;
	for(i=0;i<9;i++)
	{
		*(getbuff+i)=*(Ram_UC_Data_Addr+i);
	}
	return 9;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
unsigned char Flash_math(unsigned char mode,unsigned int startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr,
											unsigned int filename)
{
	unsigned char slen=0,ret=0,i=0;
	unsigned int  addr_temp = 0;

	addr_temp = startaddr;
	
	switch(mode)
	{
		case 0:
			slen=sizeof_format(format);
        	ret=Read_File(filename,startaddr,slen,getbuff);
			if(ret==0)
			{	
         			for(i=0;i<slen;i++)
				{
					*(getbuff+i)=0xff;
				}
				return slen;
			}
			break;
		case 1:
			//ret=Flash_math_Add(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr,filename);
			ret=math_Add((unsigned char *)&addr_temp,getbuff,math_mode,format,Ass_num,Ass_addr,filename);
			break;
		case 0xfe:
			//ret=Flash_math_Demand(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr,filename);
			ret=math_Demand((unsigned char *)&addr_temp,getbuff,math_mode,format,Ass_num,Ass_addr,filename);
			break;			
		default:
			ret=-1;	
		
	}
	return ret;
}


unsigned char Eeprom_math(unsigned char mode,unsigned int startaddr,unsigned char * getbuff ,
											unsigned char math_mode,unsigned char format,
											unsigned char Ass_num,unsigned char Ass_addr,
											unsigned char driver)
{
	unsigned char ret;
	unsigned int  adrr_temp = 0;
	
	adrr_temp = startaddr;
	
	switch(mode)
	{
		case 0:
			ret=sizeof_format(format);
			WRLC256(startaddr,getbuff,ret,0,1);
			break;
		case 1:
			//ret=Eeprom_math_Add(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr,driver);
			ret=math_Add((unsigned char *)&adrr_temp,getbuff,math_mode,format,Ass_num,Ass_addr,EEPROM_MATH);
			break;
		case 0xfe:
			//ret=Eeprom_math_Demand(startaddr,getbuff,math_mode,format,Ass_num,Ass_addr,driver);
			ret=math_Demand((unsigned char *)&adrr_temp,getbuff,math_mode,format,Ass_num,Ass_addr,EEPROM_MATH);
			break;			
		default:
			ret=-1;	
		
	}
	return ret;
}

/*"                      "*/                                                                  
/*"����: ������ݵ���Ч�ԣ����������ȫ��Ϊ0xff ,����-1,"*/
/*"**���򷵻���ЧΪ0"*/
int Check_Data_valid(unsigned char  *buff_t, unsigned char len)
{
    unsigned char i;    

	for(i=0;i<len;i++)
	{
		  if((*(buff_t+i))!=0xff)	  	
		  	return  0;		  
	}	

	return -1;
}
/*"*********************************************************************/          

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������"*/
/*"��;����ַ��������"*/
/*"������"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
unsigned int Revise_Addr(unsigned int leaf_addr,const struct COMMUNAL_REVISE *REVISE ,unsigned char ID,unsigned type)
{
	unsigned char Revise_Max_Num,num;
	signed char basce;
	unsigned char *Ram_Data_Addr;
	if((REVISE->Revise_Mode&0x08)!=type)/*"�ļ���ƫ�ƴ˴�����������"*/
		return leaf_addr;
	if((REVISE->Revise_Mode&0x01)==0)
		return leaf_addr;
	if(REVISE->Revise_Basce<0x100)
	{		
		basce=REVISE->Revise_Basce;
	}
	else
	{
		Ram_Data_Addr=(unsigned char*)REVISE->Revise_Basce;
		basce=*Ram_Data_Addr;
	}

	Revise_Max_Num=REVISE->Revise_Max_Num;
	if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"���ʱ����¼���¼�еķ�����"*/
		{
		if (SpicReq_SC_DEFINE)
			{
			if ((Revise_Max_Num==4))
				Revise_Max_Num=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"���ʲ������̼�¼������ʱ�α������м�¼��������ʱ�α���Ϊ3ʱ���������¼��NΪ12"*/
			}
		else 
			{
			if ((Revise_Max_Num==4)&&(Pre_Payment_Para.TriffPriceNum>4))
				Revise_Max_Num=Pre_Payment_Para.TriffPriceNum;
			}
		}
	
	/*"ƫ�Ʋ�����Ч�����򲻲�������"*/
	if((REVISE->Revise_Mode&0x02)!=0)
	{
		/*"��ƫ��"*/
		if((REVISE->Revise_Mode&0x04)==0)
		{/*"��ѭ��"*/
			if(ID>basce)
				return leaf_addr;
			num=basce-ID;
		}
		else
		{/*"ѭ��"*/
        if((REVISE->Revise_Mode&0x10)==0)
        {
			    if(ID>basce)
				     num=basce+Revise_Max_Num-ID;
			     else
				    num=basce-ID;
       }
			 else
			 {
			     if(ID>basce+1)
				    num=basce+1+Revise_Max_Num-ID;
			     else
				    num=basce+1-ID;
      }
		}
	}
	else
	{
		/*"��ƫ��"*/
		if((REVISE->Revise_Mode&0x04)==0)
		{/*"��ѭ��"*/
			if(ID+basce>Revise_Max_Num)
				return leaf_addr;
			num=basce+ID;
		}
		else
		{/*"ѭ��"*/
			if(ID+basce>Revise_Max_Num)
				num=basce+ID-Revise_Max_Num;
			else
				num=basce+ID;
		}
	}
	
	leaf_addr+=(num*REVISE->Revise_Size);
	return leaf_addr;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
unsigned char get_leaf_cyc_para(unsigned int node,unsigned char *start,unsigned char *end)
{
	const struct TREE_NODE *Tree_Node;
	const struct COMMUNAL_RANGE *Communal_Range;	
	unsigned char *Ram_Id_Addr;
	unsigned char  ID_start=0,ID_end=0;	

	
	Tree_Node=(const struct TREE_NODE *)&Protocol_Tree_Node[node];
	Communal_Range=(const struct COMMUNAL_RANGE  *)&Protocol_Range[Tree_Node->Range_ID];
	if(Communal_Range->ID_Start<0x100)
		{		
				ID_start=Communal_Range->ID_Start;
		}
	else
		{				
				Ram_Id_Addr=(unsigned char *)Communal_Range->ID_Start;
				ID_start=*Ram_Id_Addr;
		}
	
	if(Communal_Range->ID_End<0x100)
		{	
			ID_end=Communal_Range->ID_End;
			if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"���ʱ����¼���¼�еķ�����"*/
				{
				if (SpicReq_SC_DEFINE)
					{
					if ((ID_end==3))
						ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"���ʲ������̼�¼������ʱ�α������м�¼��������ʱ�α���Ϊ3ʱ���������¼��NΪ12"*/
					}
				else 
					{
					if ((ID_end==3)&&(Pre_Payment_Para.TriffPriceNum>4))
						ID_end=Pre_Payment_Para.TriffPriceNum-1;
					}
				}
			else if ((CurrReadId.l==0x040501FF)||(CurrReadId.l==0x040502FF))
				{
				if (SpicReq_SC_DEFINE)
					ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"ע3����ȡ���ʵ�����ݿ�ʱ���������õ���ʱ�α������أ���ǰ��ʱ�α�������Ϊ�����ͷ��ؼ�����ʵ��"*/
				else
					ID_end=Pre_Payment_Para.TriffPriceNum; /*"������Ϊ���٣����ض�����ʵ��"*/
				}			
		}
	else
		{			
				  Ram_Id_Addr=(unsigned char *)Communal_Range->ID_End;
				  if((Communal_Range->ID_End) ==((unsigned int)&Max_Triff_Current))/*"����RAM��ַ�ж��Ƿ��ڳ�����������"*////kc debug 140807
				     {
				       if((CurrReadId.d[3]!=0x05)&&(CurrReadId.d[1]!=0xFF))
				       {
				        ID_end=MAXTRIFF-1;
				       }
				       else
				       {
				        ID_end=*Ram_Id_Addr;
				       }
				     }
                               else
                               {
				       ID_end=*Ram_Id_Addr;
                               }
		    }
	/*"������ڵ㲻�ǵ�һ��ڵ���ô��Ҫ���㣬��Ϊѹ�������ѭ������"*/
	
		if(Tree_Node->Node_mode.bit.num!=0xf)
		{
			*start=ID_start;
			*end=ID_end;
		}
		else
		{
			*start=0XFF;
			*end=0xFF;
		}
			
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*""*/
unsigned char set_zip_id(unsigned char *zip_id,unsigned char num,unsigned char level)
{
	if(level==0xff)
	{	
		if(*zip_id==0xff)
		{
			*zip_id=num;
			return 0;	
		}
		else if(*(zip_id+1)==0xff)	
		{	
			*(zip_id+1)=num;
			return 1;	
		}
		else
			return -1;
	}
	else
	{	
		*(zip_id+level)=num;
		return level;
	}
		
					
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
unsigned char push_zip_info(unsigned char val,unsigned char num)
{
	union CHECK_NODE_ID_RET ret;
	ret.byte=val;
	if(ret.bit.zip1!=1)
	{
		ret.bit.zip1=1;
		ret.bit.num1=num;
	}	
	else if(ret.bit.zip2!=1)
	{
		ret.bit.zip2=1;
		ret.bit.num2=num;
	}	
	return ret.byte;
}

//------------------------------------------------------------------------------------------//

unsigned char Check_Event_Id_Valid(union ID id) /*"0x01 ���ݱ�ʶ��Ч,0x00 ���ݱ�ʶ��Ч"*/
{
	unsigned char res;
	unsigned char id2_max;
	unsigned char id1_max;
	unsigned char id0_max;
	unsigned char id2_min;
	unsigned char id1_min;
	unsigned char id0_min;
	
	res=0;
	
	switch(id.d[3])
	{		
		case 0x19:/*"����"*/
		case 0x1A:/*"����"*/
		 id2_max=0x03;
	   id1_max=0x31;
	   id0_max=0x0A;
	   id2_min=0x01;
	   id1_min=0x01;
	   id0_min=0x01;
		break;
		
		default:
		 return 0;
		break;
	}
	
	if((id.d[2]>=id2_min)&&(id.d[2]<=id2_max)
	  &&(((id.d[1]>=id1_min)&&(id.d[1]<=id1_max))||(id.d[1]==0xff))
	  &&(id.d[0]>=id0_min)&&(id.d[0]<=id0_max))
	{
	  res=1;
  }
	
	return res;
}

#define MAX_FILE_NUMBER 32
void Prep_Event_Ram(union ID id)
{
	unsigned char dealkind;
	unsigned int  file_name_base;
	unsigned char file_name_pointer;
	unsigned char event_flag;
	unsigned char event_len;
	unsigned char amphourkind;

	
	dealkind=0;

	
	switch(id.l&0xffff0000)
	{
		case 0x19010000:
		case 0x19020000:
		case 0x19030000:  /*"A B C �����"*/
		  file_name_base=OVERCURR_A_BEGINFILE+(id.d[2]-1)*((unsigned int)32);
		  file_name_pointer=*(&Event_Power_Net_Pointer.OverCurrent_A_P+(id.d[2]-1));
		  event_len=243; 
		break;
		
		case 0x1A010000:
		case 0x1A020000:
		case 0x1A030000:  /*"A B C �����"*/
		  file_name_base=FAILCURR_A_BEGINFILE+(id.d[2]-1)*((unsigned int)32);
		  file_name_pointer=*(&Event_Power_Net_Pointer.FailCurrent_A_P+(id.d[2]-1));
		  event_len=243; 
		break;
	}
	
	file_name_pointer=file_name_pointer%MAX_FILE_NUMBER;
	if(file_name_pointer>=(id.d[0]-1))
	  file_name_pointer=file_name_pointer-(id.d[0]-1);
	else
	  file_name_pointer=MAX_FILE_NUMBER-(id.d[0]-1)+file_name_pointer;
	file_name_base=file_name_base+file_name_pointer;
	
	if(id.d[0]>1)
	  event_flag=0;
	
	if(dealkind==0)/*"ʧ���ദ��"*/
	{
		Read_File(file_name_base,0,event_len,&TempEventData[0]);
	}
}


const unsigned char DATA_POSITION_K0[53]={  0,  6, 10, 14, 14, 30, 42, 54, 54,102,
                                          108,117,126,135, 34, 46, 70, 70,104,111,
                                          120,129,137, 38, 50, 86, 86,106,114,123,
                                          132,139,243,243,247,251,141,147,151,155,
                                          155,171,183,195,195,175,187,211,211,179,
                                          191,227,227};

unsigned char Get_Event_OneData(union ID id,unsigned char mode,unsigned char leaf_num,
                                unsigned char *databuff,unsigned char *show_para)
{
	unsigned char dealkind;
	unsigned char data_position;
	unsigned char save_format;
	unsigned char output_format;
	unsigned char save_unit;
	unsigned char output_unit;
	signed char   save_exp;
	signed char   output_exp;
	unsigned char i;
	unsigned char format_sel_id;
	unsigned char res;
	
	
	save_format=0;
	output_format=0;
	save_unit=0;
	output_unit=0;
	save_exp=0;
	output_exp=0;
	dealkind=0;
	format_sel_id=0;
	
	switch(id.d[3])
	{
		case 0x19:/*"����"*/
		case 0x1A:/*"����"*/
		 if(id.d[1]<=0x20)
		 {
		   format_sel_id=id.d[1];
		   data_position=DATA_POSITION_K0[id.d[1]-1];
		 }
		 else
		 {
		   format_sel_id=id.d[1]+0x04;
		   data_position=DATA_POSITION_K0[id.d[1]+0x04-1];
		 }
		break;
	}

	switch(format_sel_id)
	{
		case 0x01:/*"ʱ��"*/
		case 0x25:
		  save_format=_YYMMDDHHMMSS;
	    output_format=_YYMMDDHHMMSS;
	    if(mode==3)
	    {
	    	output_format=_YYMMDD;
	    	if(leaf_num>=1)
	    	  output_format=_HHMMSS;
	    }
		break;
		
		case 0x02:/*"�������й�����"*/
		case 0x26:
		case 0x06:/*"���������й�����"*/
		case 0x0f:
		case 0x18:
		case 0x2A:
		case 0x2E:
		case 0x32:
		  save_format=UNSIGNED_LONG;
	    output_format=UBCD4BYTE;
	    save_unit=KWH_UNIT;
	    output_unit=KWH_UNIT;
	    save_exp=-3;
	    output_exp=Mauto;
		break;
		
		case 0x03:/*"�����й�����"*/
		case 0x07:
		case 0x10:
		case 0x19:
		case 0x27:
		case 0x2B:
		case 0x2F:
		case 0x33:
		  save_format=UNSIGNED_LONG;
	    output_format=UBCD4BYTE;
	    save_unit=KWH_UNIT;
	    output_unit=KWH_UNIT;
	    save_exp=-3;
	    output_exp=Mauto;
		break;
		
		case 0x04:/*"����޹�1"*/
		case 0x08:
		case 0x11:
		case 0x1A:
		case 0x28:
		case 0x2C:
		case 0x30:
		case 0x34:
		  save_format=SIGNED_LONG;
	    output_format=BCD4BYTE;
	    save_unit=KVARH_UNIT;
	    output_unit=KVARH_UNIT;
	    save_exp=-3;
	    output_exp=Mauto;
	    dealkind=1;
	  break;
	  
		case 0x05:/*"����޹�2"*/
		case 0x09:
		case 0x12:
		case 0x1B:
		case 0x29:
		case 0x2D:
		case 0x31:
		case 0x35:
		  save_format=SIGNED_LONG;
	    output_format=BCD4BYTE;
	    save_unit=KVARH_UNIT;
	    output_unit=KVARH_UNIT;
	    save_exp=-3;
	    output_exp=Mauto;
	    dealkind=2;
		break;
		
		case 0x0A:/*"��ѹ"*/
		case 0x13:
		case 0x1C:
		  save_format=UBCD2BYTE;
	    output_format=UBCD2BYTE;
	    save_unit=V_UNIT;
	    output_unit=V_UNIT;
	    save_exp=-1;
	    output_exp=-1;
		break;
		
		case 0x0B:/*"����"*/
		case 0x14:
		case 0x1D:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=A_UNIT;
	    output_unit=A_UNIT;
	    save_exp=-3;
	    output_exp=-3;
		break;
		
		case 0x0C:/*"�й�����"*/
		case 0x15:
		case 0x1E:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=KW_UNIT;
	    output_unit=KW_UNIT;
	    save_exp=-4;
	    output_exp=Dauto;
		break;
		
		case 0x0D:/*"�޹�����"*/
		case 0x16:
		case 0x1F:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=KVAR_UNIT;
	    output_unit=KVAR_UNIT;
	    save_exp=-4;
	    output_exp=Dauto;
		break;
		
		case 0x0E:/*"��������"*/
		case 0x17:
		case 0x20:
		  save_format=BCD2BYTE;
	    output_format=BCD2BYTE;
	    save_exp=-3;
	    output_exp=-3;
		break;
		
		case 0x21:/*"�ܰ�ʱֵ"*/
		  save_format=UNSIGNED_LONG;
	    output_format=UBCD4BYTE;
	    save_unit=AH_UNIT;
	    output_unit=AH_UNIT;
	    save_exp=-2;
	    output_exp=-2;
	    dealkind=3;
	  break;
	  
		case 0x22:/*"��ʱֵ"*/
		case 0x23:
		case 0x24:
		  save_format=UNSIGNED_LONG;
	    output_format=UBCD4BYTE;
	    save_unit=AH_UNIT;
	    output_unit=AH_UNIT;
	    save_exp=-2;
	    output_exp=-2;
		break;	
	}
  
	if(mode==3)/*"��ʾ��ʽ���"*/
	{
		for(i=0;i<sizeof(Protocol_Format)/sizeof(struct COMMUNAL_FORMAT);i++)
		{
			if((Protocol_Format[i].format==output_format)&&(Protocol_Format[i].unit==output_unit)
			&&(Protocol_Format[i].exp==output_exp))
			{
				show_para[0]=i;
				break;
			}
		}
		if(i>=sizeof(Protocol_Format)/sizeof(struct COMMUNAL_FORMAT))
		 return 0;
		
		for(i=0;i<sizeof(Protocol_Showinfo)/sizeof(struct COMMUNAL_SHOWINFO);i++)
		{
			if((Protocol_Showinfo[i].schar[0]==0)&&(Protocol_Showinfo[i].schar[1]==0)&&(Protocol_Showinfo[i].schar[2]==0)
			&&(Protocol_Showinfo[i].schar[3]==0)&&(Protocol_Showinfo[i].schar[4]==0))
			{
				show_para[1]=i;
				show_para[2]=0;
				break;
			}
		}
		if(i>=sizeof(Protocol_Showinfo)/sizeof(struct COMMUNAL_SHOWINFO))
		 return 0;
	}
	
	/*"ȡ��"*/
	if(dealkind==0)
	{
		for(i=0;i<sizeof_format(save_format);i++)
		 Co.b[300+i]=TempEventData[data_position+i];
	}
	if((dealkind==1)||(dealkind==2))/*"����޹�"*/
	{
		i=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
		if(dealkind==2)
		 i=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
		math_Add(&TempEventData[data_position],&Co.b[300],i,SIGNED_LONG,4,4, RAM_MATH);
	}
	if(dealkind==3)/*"�ܰ�ʱֵ"*/
	{
		math_Add(&TempEventData[data_position],&Co.b[300],0x15,UNSIGNED_LONG,3,4, RAM_MATH);
	}
    
	/*"С���㴦��"*/
	if(mode==0)/*"ͨ��"*/
	{
		if(output_exp==Mauto)
      output_exp=-2;
    if(output_exp==Dauto)
      output_exp=-4;
	}
	else/*"��ʾ"*/
	{
		if(output_exp==Mauto)
    {
       if(Meter_Parameter.parameter2.EnergyPoint<4)
         output_exp=0-Meter_Parameter.parameter2.EnergyPoint;
       else
         output_exp=-2;
    }
  	if(output_exp==Dauto)
    {
       if(Meter_Parameter.parameter2.PowerPoint <= MAXDAUTOVALUE)
          output_exp=0-Meter_Parameter.parameter2.PowerPoint;
       else
        	output_exp=-4; 
    }
	}
	
	for(i=0;i<sizeof_format(save_format);i++)
	{
		 if(Co.b[300+i]!=0xff)
		   break;
	}
	if((i>=sizeof_format(save_format))&&(save_format!=SIGNED_LONG))
	{
		for(i=0;i<sizeof_format(output_format);i++)
	  {
		  databuff[i]=0;
	  }
	}
	else
	{
	  data_change(&Co.b[300],&databuff[0],save_format,output_format,save_unit,output_unit,save_exp,output_exp);
	}
	
	
	
	res=sizeof_format(output_format);
	
	return res;
}

unsigned char Get_Id1_max(unsigned char id3)
{
	unsigned char res;
	
	res=0;
	
	switch(id3)
	{
		case 0x19:/*"����"*/
		case 0x1A:/*"����"*/
		 res=0x31;
		break;
	}
	
	return res;
}

unsigned char Get_Event_AllData(union ID id,unsigned char uartx,unsigned char max_len,unsigned char *databuff)
{
	unsigned char data_len;
	unsigned char i;
	unsigned char j;
	
	data_len=0;
	
	for(i=0x01;i<=Get_Id1_max(id.d[3]);i++)
	{
		id.d[1]=i;
		j=Get_Event_OneData(id,0,0,databuff+data_len,&Co.b[600]);
		if(data_len+j<max_len)
		{
				data_len+=j;
		}
		else/*"û�п��Ǻ���֡"*/
		{
				break;
		}
	}
	
	return data_len;
}

