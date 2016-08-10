/*"DL645-2007通讯设计"*/
/*"trend 2008-4-23 11:32:09 V1.00"*/
/*"设计方法：协议树，查表"*/
/*"数据文件保存在645DATA.c"*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "I2C_operation.h"
#include "645_2007.h"
#include "MB_BASE_FUN.h"
#include "MB_Showmain.h"
#include "645Data.h" /*"协议数，数据表"*/
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
unsigned char Read_event_first_flag;/*"读正在发生的事件标志fxf add 090301    "*/
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
/*"函数名：TransferData_New"*/
/*"用途：续写数据"*/
/*"参数：mode=0 读起始 1 后续帧 2 写数 3显示"*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
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
	/*"清缓冲"*/
	for(uni=0;uni<500;uni++)
		Co.b[uni]=0;
	Show_ID_vatiy=0;
	
	eventfreezereadflag=0;
	
	if((mode!=2)&&((id.d[3]==0x03)||((id.d[3]>=0x10)&&(id.d[3]<=0x21))||((id.d[3]==0x0E)&&(id.d[2]>=0x18)&&(id.d[2]<=0x30))
	               ||(id.d[3]==0x05)))
		{
		 eventfreezereadflag=1;
		 if(id.d[3]!=0x05)/*"通信抄读事件记录，需清零的事件在这里进行清零处理"*/
		 	{
		 	ClearEventCommDeal(id.l);
		 	}
		 else/*"通信抄读冻结数据，需清零的冻结在这里进行清零处理"*/
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
	/*"查找协议树"*/
	node_point=Search_Protocol_Tree(id,&node_type);
	if(node_point!=0xffff)
	{	/*"遍历节点"*/
		if(mode==0x00)
		{  
             if((data_len-4)!=0)
				return 0;
		}
		else if(mode==0x01)
		{
			if((data_len-5)!=0)/*" 判断数据长度"*/
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
		{/*"负荷曲线"*/
			if(IntoPowerDownFlag!=0)
			{/*"低功耗下不允许抄读FLASH数据"*/
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
            			return 0;/*"读数据快数"*/
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
			{/*"有后续帧"*/
				Iterate_Tree_Flag[uartx].flag.bit.b0=1;
				return i_ret&0x7fff;
			}
			else
			{/*"无后续帧"*/
			       if(mode == 1)/*"读后续帧模式"*/
				{
				Iterate_Tree_Flag[uartx].flag.bit.b5 = 1;/*"后续帧最后一帧数据"*/
				//Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
				}
				Iterate_Tree_Flag[uartx].flag.bit.b0=0;
				
				return i_ret&0x7fff;
			}
	   
		}
		else if((id.d[3]==0x0E)&&(id.d[2]==0x0E)&&(id.d[1]==0)&&(id.d[0]<=0x07))/*"内部块设参数"*/
		{
			i_ret=Set_Read_Block_Para(id,P,data_len,mode);
			
			return i_ret;
		}
		else if(Check_Event_Id_Valid(id)==1)
		{
		  if((mode==1)||(mode==2)||((mode==3)&&(id.d[1]==0xff)))/*"不允许读后续帧,写和显示"*/
		    return 0;
		  
		  Show_ID_vatiy=0xFF;
		  if(IntoPowerDownFlag)/*"低功耗下不能读FLASH"*/
   		  return 0;
   		
   		Iterate_Tree_Flag[uartx].num=0;
   		Iterate_Tree_Flag[uartx].flag.bit.b1=0;
   		Iterate_Tree_Flag[uartx].flag.bit.b3=0;
   		Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0;
	    
	    if(mode==0x00)/*"起始读"*/
	    {		
		    Iterate_Tree_Flag[uartx].flag.bit.b0=0;
		    Iterate_Tree_Flag[uartx].flag.bit.b5=0;	
		    Iterate_Tree_Flag[uartx].last_num=0;
		    Iterate_Tree_Flag[uartx].last_num_save=0;
		    Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
	    }
   		
   		Prep_Event_Ram(id);
		  
		  if(id.d[1]==0xff)/*"块读一次事件的所有数据项"*/
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
			return 0; /*"查找协议树失败"*/
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"查找协议树主函数 "*/
unsigned int Search_Protocol_Tree(union ID id,unsigned char* flag)
{
	unsigned int node_addr,node_temp;
	unsigned char node_mode,ret;
	if(Protocol_Tree_Root[id.d[3]]==0xFFFF)
		return 0xffff;/*"找不到根节点"*/
//	if(id.d[3]!=Protocol_Tree_Node[Protocol_Tree_Root[id.d[3]]+3])
//		return 0xffff;/*"根节点错误"*/
	
	node_temp=Protocol_Tree_Root[id.d[3]];
	
	ret=Search_node(id,node_temp,&node_addr,0);	
	
	if((ret&0x80)!=0)
		{
			/*"没找到"*/
			Meter_States.ErrOfInformation.bit.Invalid_OBIS=1;
			return 0xffff;		
		}
	else
	{/*"找到"*/
		*flag=ret;
		return node_addr;
	}
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"判断节点是否合法，指向的节点指针是否合法"*/
unsigned char check_node(const unsigned char *node)
{
	const unsigned char *p_temp;	
	
	p_temp=(const unsigned char *)&Protocol_Tree_Node[0];
	if(node<p_temp) 
		return 0xff;/*"指针处于非法区域"*/
	if((node-p_temp)>sizeof( Protocol_Tree_Node)) 
		return 0xff;/*"指针处于非法区域"*/
		
	return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"判断节点内的指针如果返回为ff表示节点结束，fe指针超范围，0正常"*/
unsigned char check_node_point(unsigned int node)
{

	if(node==0xffff)
		return 0xff;
	else if((node*sizeof(struct TREE_NODE))>sizeof( Protocol_Tree_Node))
		return 0xfe;/*"指针处于非法区域"*/
	else
		return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"查找节点函数，有镶嵌调用"*/
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
					/*"非本节点"*/
					if(tree_node->Next_Node!=0xffff)
						{
							/*"指向同级下一个节点"*/
							node_addr=tree_node->Next_Node;
							//uzip=0x0;
						}
					else
						{
							/*"返回上级节点 此条件实际为失败出口，如果不在本节点下返回上级节点也不可能找到"*/
									return 0xff;
						}
				}
			else
				{
					if(ret.bit.low==0)
					{
						/*"找到数据标识对应的节点或叶子"*/
						//*node_mode=tree_node->Node_mode;
						*addr=node_addr;
						return ret.byte;
					}
					else
					{
						/*"在下级节点"*/
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
/*"判断是否找到节点"*/
/*"返回值 b0：1下级节点 0本节点"*/
/*"       b1：1压缩 0无压缩"*/
/*"       b2：1节点 0叶子·"*/
/*"       b3：1块 0非块·"*/
/*"       b5-b4：0-3 n压缩号（DI(n)）"*/
/*"       b7：1查找错误 0正确·"*/
unsigned char Check_Node_ID(union ID id,const struct TREE_NODE *node,unsigned char uzip)
{
	unsigned char i,block;
	union CHECK_NODE_ID_RET ret;
	unsigned long *Node_ID,*Node_ID_Mark;
	union ID id_temp;
	const struct COMMUNAL_RANGE *Communal_Range;	
	unsigned char *Ram_id_Addr;
	unsigned char   ID_start=0,ID_end=0;	

	if(node->Node_mode.bit.ID_Enable==1)/*"数据标识有效"*/
		{
			if((id.l == node->ID)&&(node->Node_mode.bit.num==0xf)) 
				return 0;/*"数据标识相等"*/
				
			/*"块标识"*/
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
				//if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"费率表编程事件记录中的费率数"*/
				//	{
				//	if (Pre_Payment_Para.TriffPriceNum>4)
				//		ID_end=Pre_Payment_Para.TriffPriceNum-1;
				//	}
				//else 
				if ((CurrReadId.l==0x040501FF)||(CurrReadId.l==0x040502FF))
					{
					if (SpicReq_SC_DEFINE)
						ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"注3：读取费率电价数据块时，根据设置的日时段表数返回，当前日时段表数设置为几，就返回几组费率电价"*/
					else
						ID_end=Pre_Payment_Para.TriffPriceNum; /*"费率数为多少，返回多个费率电价"*/
					}
					
		    }
	      else
		    {			
				  Ram_id_Addr=(unsigned char  *)Communal_Range->ID_End;
				  if((Communal_Range->ID_End) ==((unsigned int)&Max_Triff_Current))/*"根据RAM地址判断是否在抄读电量数据"*////kc debug 140807
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
					/*"如果是叶子"*/
					if(block!=0xff)
						return 0xff;/*"叶子不可能出现块抄标识"*/
					if(node->Node_mode.bit.num!=0xf)
					{
						if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
						{
							ret.byte=push_zip_info(uzip,node->Node_mode.bit.num);
							ret.bit.low=0;	
							return ret.byte;/*"数据标识在范围内,是本叶子 压缩的叶子"*/		
						}
						else
						{
							return 0xff;/*"数据标识超范围"*/
						}	
						
					}
					else
					{
						ret.byte=0;
						return ret.byte;/*"数据标识在范围内,是本叶子 未压缩的叶子"*/
					}
											
				}
			else 
				{
					/*"如果是节点"*/
					if(block!=0xff)
						{
								
							if(node->Node_mode.bit.num!=0xf)
							{
							if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
								{									
										if(node->Node_mode.bit.Low_Node_Num==1)/*"下级节点有数据标识"*/
										{	
											ret.byte=push_zip_info(uzip,node->Node_mode.bit.num)	;
											if(id.d[block]!=id_temp.d[block])
												ret.bit.low=1;
											else
												ret.bit.low=0;
											
															
											return ret.byte;/*"数据标识在范围内，是本节点下"*/
											
										}
									
								}
							}
							else
							{
								
								ret.byte=0;
								ret.bit.low=1;
												
								return ret.byte;/*"数据标识在范围内，是本节点下"*/
							}					  
						}
					else
						{
						if(node->Node_mode.bit.num!=0xf)
							{
							if((id.d[node->Node_mode.bit.num]>=ID_start)&&(id.d[node->Node_mode.bit.num]<=ID_end))
								{
									
										ret.byte=push_zip_info(uzip,node->Node_mode.bit.num)	;
										if(node->Node_mode.bit.Low_Node_Num==1)/*"下级节点有数据标识"*/
											ret.bit.low=1;
										else
											ret.bit.low=0;
										return ret.byte;/*"数据标识在范围内，是本节点下"*/
																		
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
/*"同级循环，下级镶嵌调用，上级返回"*/
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
/*"如果本节点不是第一层节点那么需要计算，因为压缩引起的循环次数"*/
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
			/*"如果此节点指向的是叶子，读写数据"*/
			i_ret=0;
			/*"叶子"*/
			Tree_Leaf=(const struct TREE_LEAF *)&Protocol_Tree_Leaf[Tree_Node->Low_Node];
			Communal_Id      =(const struct COMMUNAL_ID 			*)&Protocol_Id[Tree_Leaf->Communal_Id];
			REVISE_ID        =(const struct REVISE_ID         *)&Protocol_Revise_Id[Tree_Leaf->Communal_Addr_Id];
	
			/*"根据zip计算地址的修正值"*/
			/*"计算地址修正值，先计算第一组，然后在第一组基础上计算第二组"*/	
			id_n=set_zip_id(zip_id,zip_leaf_start,id_n);
			Revise=0;
			Revise_file=0;
			for(i=0;i<2;i++)
			{
				Communal_Revise=(const struct COMMUNAL_REVISE *)&Protocol_Revise[REVISE_ID->Revise_Id[i]];
				Revise+=Revise_Addr(0,Communal_Revise,*(zip_id+i),REVISE_ADDR_TYPE);
				Revise_file+=Revise_Addr(0,Communal_Revise,*(zip_id+i),REVISE_FILE_TYPE);
			}
			
			if((mode==0x00)||(mode==0x01))/*"读"*/
			{          
			  Iterate_Tree_Flag[uartx].num++;
				Leaf_num_now=Iterate_Tree_Flag[uartx].num;
				if(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num)
					i_ret=Get_Leaf_Data(Tree_Node->Low_Node,buff+getlen,formatdata,format,Revise,Revise_file,uartx);
				
				if(i_ret==0xff) 
					{
						Iterate_Tree_Flag[uartx].flag.bit.b3=1;/*"单位不匹配标志"*/
						return 0;
					}

				if(i_ret==0x99)
					i_ret=1;/*" 位叶子遍历特殊处理"*/
				
				if(getlen+i_ret<len)
					{
					   getlen+=i_ret;
					   
					}
				else
					{/*"buf已经满了退出等后续帧命令"*/
						Iterate_Tree_Flag[uartx].flag.bit.b0=1;/*"读后续标志"*/
						Iterate_Tree_Flag[uartx].flag.bit.b1=1;/*"读后续标志"*/
						Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
						Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].num-1;
						return getlen;
					}
			}
			else if(mode==0x02)/*"写"*/
			{
				i_ret=Set_Leaf_Data(Tree_Node->Low_Node,buff+getlen,formatdata,format,Revise,uartx);
				if(i_ret==0)   return 0;
				if(i_ret==0x99)  i_ret=0;/*" 位叶子遍历特殊处理"*/
				getlen+=i_ret;
			}
			else /*"   显示"*/
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
							}/*" 位叶子遍历特殊处理"*/
						
						 	   
						 	  /*" 返回显示需要的传输格式和显示格式ID "*/	
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

			if(((mode==0x00)||(mode==0x01))&&(i_ret==0x00)&&(Iterate_Tree_Flag[uartx].flag.bit.b3==1))  return 0;/*"读数据失败出口 fuxf add 081228  "*/
			
			if(Iterate_Tree_Flag[uartx].flag.bit.b1==1)    return getlen;  /*"读后续标志"*/			   	
	
			if((mode==0x02)&&(i_ret==0))				return 0;     						 /*"   写参数失败出口"*/					
			
			if((mode==0x03)&&(i_ret==0xff))        return 0;   					/*"   格式不正确   显示失败出口"*/	

			if((mode==0x03)&&(i_ret!=0))        return getlen;   					/*"   显示出口"*/	
			
			
		}
		/*"结束"*/				

		if(level==0)
		{
			/*"遍历的根节点遍历结束"*/
			if(mode == 1)/*"读后续帧模式"*/
			{
					Iterate_Tree_Flag[uartx].flag.bit.b5 = 1;/*"后续帧最后一帧数据"*/
				  Iterate_Tree_Flag[uartx].last_num_save=Iterate_Tree_Flag[uartx].last_num;
						//Iterate_Tree_Flag[uartx].last_num=Iterate_Tree_Flag[uartx].num-1;
			}
			return getlen;
		}
		if(zip_leaf_start<zip_leaf_end)
		{/*"有压缩,未遍历完成"*/
			zip_leaf_start++;
			ret=0;	
		}
		else
		{/*"完成遍历"*/
			ret=check_node_point(Tree_Node->Next_Node);
			node=Tree_Node->Next_Node;	
			id_n=set_zip_id(zip_id,0xff,id_n);
			id_n=0xff;
		}
		if(((mode==0x00)||(mode==0x01))&&(Iterate_Tree_Flag[uartx].num>Iterate_Tree_Flag[uartx].last_num))
			{	
				if(block_flag==1)
				{	/*"添加块分隔符0xaa"*/
					*(buff+getlen)=0xAA;
					getlen++;
				}
			}
		/*"ret==0下一个同级节点有效"*/
		/*"ret==0xff无下一个同级节点返回上级阶段"*/			
	}while(ret==0);
	return getlen;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"找到节点后遍历读写节点主函数"*/
/*"node_addr, 需要读写的节点的位置"*/
/*"*buff,     缓存"*/
/*"len,       缓存大小 根据此大小分帧  "*/
/*"mode        模式,b0=0读、b0=1写，b1=0起始读取、b1=1后续读取"*/
/*"formatdata, 数据格式"*/
/*"*format,    读数据时的返回格式"*/
/*"data_len 命令帧数据域数据长度"*/
signed int Traverse_Node(unsigned int node_addr,unsigned char type,unsigned char *buff,
												unsigned int len,unsigned char mode,
												unsigned char formatdata,unsigned char *format,
												union ID id,unsigned char data_len,unsigned char uartx)
{

	unsigned char i,getlen,zip_id[2];
	signed int i_ret; 
	union CHECK_NODE_ID_RET zip;
	
	/*"对压缩的ID进行处理"*/
	zip.byte=type;	
	if(zip.bit.zip1==1)
       zip_id[0]=id.d[zip.bit.num1];	
	else
		zip_id[0]=0xff;	
		
	if(zip.bit.zip2==1)
		zip_id[1]=id.d[zip.bit.num2];
	else
		zip_id[1]=0xff;
	
	/*"后续帧信息"*/
	Iterate_Tree_Flag[uartx].num=0;
	Iterate_Tree_Flag[uartx].flag.bit.b1=0;
	Iterate_Tree_Flag[uartx].flag.bit.b3=0;
	Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0;	
	Leaf_num_now=0;
	
	/*"初始化读写数据变量"*/
	for(i=0;i<32;i++)
	  Readdata_buff[i]=0;
    Read_Com_ID=id;

	if(mode==0x00)/*"起始读"*/
	{		
		Iterate_Tree_Flag[uartx].flag.bit.b0=0;
		Iterate_Tree_Flag[uartx].flag.bit.b5=0;	
		Iterate_Tree_Flag[uartx].last_num=0;
		Iterate_Tree_Flag[uartx].last_num_save=0;
		Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
	}
	else if(mode==0x01)/*"读后续"*/
	{
			if((Iterate_Tree_Flag[uartx].flag.bit.b0==0) && (Iterate_Tree_Flag[uartx].flag.bit.b5==0))/*"读后续标志"*/
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
			/*"最后一帧传输完后，读后续帧只能是重读最后一帧数据帧"*/
			if((Iterate_Tree_Flag[uartx].flag.bit.b5==1) && (Iterate_Tree_Flag[uartx].flag.bit.b2 == 0))
				{
				if(0xff != Event_Report_flag)/*"如果不是重抄最后一帧数据，只能是事件主动上报"*/
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
			{/*"在此处加入位叶子数据标识"*/		
				  Iterate_Tree_Flag[uartx].Show_bit_flag=0xff;
			}	
			else
			{			
			    Iterate_Tree_Flag[uartx].Show_bit_flag=0;
			}
			if((Iterate_Tree_Flag[uartx].Show_bit_flag==0xff)&&(len!=0))/*"   位格式处理FXF 20081124 "*/
			{
				  if(len==1)
				  {
				     Iterate_Tree_Flag[uartx].last_num=8; /*"位叶子显示取数计数"*/		
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
			      Iterate_Tree_Flag[uartx].last_num=len; /*"显示取数计数"*/	
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

	if((mode==0x03)&&(i_ret==0xff))        return 0;   /*"    在读叶子数据格式不正确  显示失败出口"*/	

	return i_ret;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"查找叶子地址"*/
unsigned char search_leaf(unsigned int node_addr,unsigned int *addr)
{
	const struct TREE_NODE *tree_node;
	unsigned char ret;
	
	tree_node=(const struct TREE_NODE *)&Protocol_Tree_Node[node_addr];
	if(check_node((const unsigned char *)tree_node)==0xff)
		{			
			return 0xFF; /*"非法地址"*/
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
	/*"判读读数据的权限"*/
	if(Comm_Staut.meter_staut==0x11)/*"工厂"*/
		ctemp=0x01;
	else if(Comm_Staut.meter_staut==0x22)/*"实验室"*/
		ctemp=0x02;
	else /*"现场"*/
		ctemp=0x04;
	if(((Communal_Purview->read_mode&ctemp)&0x07)==0)
	{
		Meter_States.ErrOfInformation.bit.Invalid_Password=1;
		return 0;/*"在此状态下不允许读"*/	
	}	

	if(Communal_Function->OnRead!=0)
    {			/*"-1表示该类数据不允许读用于冻结数据"*/	
				if(Communal_Function->OnRead()==-1)
							   return 0;							
    }

/*"取组合方式字"*/	
	if(Communal_Mathinfo->math_mode<0x100)
		{		/*"只有一字节有效为立即数"*/
				math_mode=Communal_Mathinfo->math_mode;
		}
	else
		{
				/*"两字节有效为地址"*/
				Ram_Data_Addr=(unsigned char *)Communal_Mathinfo->math_mode;
				math_mode=*Ram_Data_Addr;
		}
	/*"存储的数据的长度"*/	
	s_len=sizeof_format(Communal_Save->format);
	
	save_format_temp=Communal_Save->format;
	/*"取数，放在dbuf的开始字节，如果有组合计算机算完"*/	
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
		case _RAM:/*"内存数据"*/
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
	
			/*"将数据读出到dbuf[0]"*/
			break;
		case _FLASH:
            Show_ID_vatiy=0xff;
			if(IntoPowerDownFlag!=0)  /*"低功耗下不允许抄读FLASH数据"*/
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

	/*"  对于数据,如果全为OXFF，表示无无效 FXF ADD 081109 "*/
		if(((Check_Data_valid(dbuf,s_len)==-1)&&(Communal_Mathinfo->math_type!=1)
		&&(!((Communal_Mathinfo->math_type==0)&&((save_format_temp==SIGNED_LONG)||(save_format_temp==SIGNED_INT)||(save_format_temp==SIGNED_CHAR)))))
		||(Comm_Data_valid_flag==0))
					 Data_valid_flag=0; 

			
		if(uartx==0x03)  	 Iterate_Tree_Flag[uartx].Show_bit_flag=0x00;
			
			
		
	
/*"进制和单位 和小数点  的转换"*/
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
		/*"没有显示格式时候使用通信格式"*/
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

	 /*"需量和功率四舍五入"*/                  
	if(((Communal_Trans->exp==Dauto)||(Communal_Show->exp==Dauto))&&(Data_valid_flag==0xff))
	{
            for(i=0;i<ret;i++)/*"剔除全0"*/
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
		if(Comm_Staut.meter_staut==0x11)/*"工厂"*/
			i=0;
		else if(Comm_Staut.meter_staut==0x22)/*"实验室"*/
			i=1;
		else /*"现场"*/
			i=2;		
			
		if(Check_Parameter_Len_IS_ok(Communal_Trans->format)==-1)  /*"在设置参数的时候对长度判读fxf 081218"*/
			{
				Meter_States.ErrOfInformation.bit.Invalid_Data=1;
				return 0;
			}
		/*"   密码 权限字为0，表示不能写fxf 081122"*/
		if(Communal_Purview->write_mode[i]==0x00)
		{
				Meter_States.ErrOfInformation.bit.Invalid_Password=1;
				return 0;
		}			
				
		/*"   需要判断密码fxf 081122"*/
		if( Far_Spec_Order_Flag != 0xFF )		//payment
			{
			if((Communal_Purview->write_mode[i]&0x01)==0x00)	
				{
					if((Communal_Purview->write_mode[i]&0x02)==0x02)
						password_level=0;/*"0级密码"*/
					else if((Communal_Purview->write_mode[i]&0x04)==0x04)
						password_level=1;/*"1级密码"*/
					else if((Communal_Purview->write_mode[i]&0x08)==0x08)
						password_level=2;/*"2级密码"*/
					else if((Communal_Purview->write_mode[i]&0x10)==0x10)
						password_level=3;/*"3级密码"*/
					else if((Communal_Purview->write_mode[i]&0x20)==0x20)
						password_level=4;/*"4级密码"*/
					else if((Communal_Purview->write_mode[i]&0x40)==0x40)
						password_level=5;/*"5级密码"*/
					else password_level=9;/*"末级密码"*/
					
					if((Comm_Staut.password_level)>password_level)
					{			
						Meter_States.ErrOfInformation.bit.Invalid_Password=1;
						return 0;/*"在此密码等级下不允写"*/
					}
					
				}
			}

		if (((Communal_Purview->write_mode[i]&0x80)!=0)&&(Far_Spec_Order_Flag!=0xFF))   //payment
		{
			Meter_States.ErrOfInformation.bit.Invalid_Password=1;
			return 0;/*"需要铅封按键按下，但是没有按下，不允写"*/
		}


	/*"写之前的函数一般用来检验数据是否超限和记录事件"*/		
	 if((Communal_Function->OnWrite_Beford!=0)&&(Iterate_Tree_Flag[uartx].Set_Prarmeter_flag==0))//FXF ADD  081115
	{
	 	if(Communal_Function->OnWrite_Beford()==-1) /*"  写数据失败"*/
					return 0;	

		Iterate_Tree_Flag[uartx].Set_Prarmeter_flag=0xff;
	 }
	 
			
	/*"写入的数据的长度"*/	
	if(formatdata==COMMFORMAT)
	{	
		if(Communal_Trans->exp==Mauto)/*"设置初始电量"*/
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
	/*"需要写的数据放buf"*/	
	for(i=0;i<MAX_FUN_BUFF_SIZE;i++)
		dbuf[i]=0;



	ret=data_change(buff,&dbuf[0],format_temp,Communal_Save->format,
					Communal_Trans->unit,Communal_Save->unit,
					exp_temp,Communal_Save->exp);		

	if(ret==0xff)  	return 0;
	else      	ret=0;

/*"开始存数"*/	
	switch(Tree_Leaf->addr&0xf0000000)
	{
		case _RAM:/*"内存数据"*/
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
/*"  Description:    数据组合计算,根据数据组合模式字，计算组合数据值"*/
/*"  Calls:"*/
/*"  Called By:"*/
/*"  Input:          startaddr  参与组合计算数据起始地址指针,"*/
/*"                             如果为EEPROM或FLASH，指针指向的是EEPROM或FLASH地址"*/
/*"                  math_mode  组合计算模式"*/
/*"                  format     数据格式"*/
/*"                  Ass_num    参与组合计算成员数"*/
/*"                  Ass_addr   参与组合计算成员偏移地址"*/
/*"                  filename   0~5000 为flash文件名，"*/
/*"                             RAM_DEMAND_MATH表示RAM中数据"*/
/*"                             EEPROM_DEMAND_MATH表示EEPROM中数据"*/
/*""*/
/*"  Output:         getbuff  组合计算结果"*/
/*""*/
/*"  Return:         数据长度"*/
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
	
	
	/*"取数"*/
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

        /*"  对于事件记录中组合数据,如果其中有一个全为OXFF，表示无?FXF ADD 081109 "*/
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
	
		
	/*"组合"*/
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
/*"  Description:    需量组合计算,根据需量组合模式字，计算组合需量值"*/
/*"  Calls:          "*/
/*"  Called By:      "*/
/*"  Input:          startaddr  参与组合计算数据起始地址指针,"*/
/*"                             如果为EEPROM或FLASH，指针指向的是EEPROM或FLASH地址"*/
/*"                  math_mode  组合计算模式"*/
/*"                  format     数据格式      "*/
/*"                  Ass_num    参与组合计算成员数"*/
/*"                  Ass_addr   参与组合计算成员偏移地址"*/
/*"                  filename   0~5000 为flash文件名，"*/
/*"                             RAM_DEMAND_MATH表示RAM中数据        "*/
/*"                             EEPROM_DEMAND_MATH表示EEPROM中数据"*/
/*"                  "*/
/*"  Output:         getbuff  组合计算结果 "*/
/*"  "*/
/*"  Return:         数据长度"*/
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
	/*"取数"*/
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
	
	/*"组合"*/
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
/*"作用: 检测数据的有效性，如果输入数全部为0xff ,返回-1,"*/
/*"**否则返回有效为0"*/
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
/*"函数名："*/
/*"用途：地址修正函数"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
unsigned int Revise_Addr(unsigned int leaf_addr,const struct COMMUNAL_REVISE *REVISE ,unsigned char ID,unsigned type)
{
	unsigned char Revise_Max_Num,num;
	signed char basce;
	unsigned char *Ram_Data_Addr;
	if((REVISE->Revise_Mode&0x08)!=type)/*"文件名偏移此处不做运算做"*/
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
	if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"费率表编程事件记录中的费率数"*/
		{
		if (SpicReq_SC_DEFINE)
			{
			if ((Revise_Max_Num==4))
				Revise_Max_Num=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"费率参数表编程记录根据日时段表数进行记录，例如日时段表数为3时，则该条记录中N为12"*/
			}
		else 
			{
			if ((Revise_Max_Num==4)&&(Pre_Payment_Para.TriffPriceNum>4))
				Revise_Max_Num=Pre_Payment_Para.TriffPriceNum;
			}
		}
	
	/*"偏移参数有效，否则不参与运算"*/
	if((REVISE->Revise_Mode&0x02)!=0)
	{
		/*"负偏移"*/
		if((REVISE->Revise_Mode&0x04)==0)
		{/*"不循环"*/
			if(ID>basce)
				return leaf_addr;
			num=basce-ID;
		}
		else
		{/*"循环"*/
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
		/*"正偏移"*/
		if((REVISE->Revise_Mode&0x04)==0)
		{/*"不循环"*/
			if(ID+basce>Revise_Max_Num)
				return leaf_addr;
			num=basce+ID;
		}
		else
		{/*"循环"*/
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
			if ((CurrReadId.l&0xFFFFFF00)==0x03300F00)	//newpay	/*"费率表编程事件记录中的费率数"*/
				{
				if (SpicReq_SC_DEFINE)
					{
					if ((ID_end==3))
						ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"费率参数表编程记录根据日时段表数进行记录，例如日时段表数为3时，则该条记录中N为12"*/
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
					ID_end=Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble*4;	/*"注3：读取费率电价数据块时，根据设置的日时段表数返回，当前日时段表数设置为几，就返回几组费率电价"*/
				else
					ID_end=Pre_Payment_Para.TriffPriceNum; /*"费率数为多少，返回多个费率电价"*/
				}			
		}
	else
		{			
				  Ram_Id_Addr=(unsigned char *)Communal_Range->ID_End;
				  if((Communal_Range->ID_End) ==((unsigned int)&Max_Triff_Current))/*"根据RAM地址判断是否在抄读电量数据"*////kc debug 140807
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
	/*"如果本节点不是第一层节点那么需要计算，因为压缩引起的循环次数"*/
	
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

unsigned char Check_Event_Id_Valid(union ID id) /*"0x01 数据标识有效,0x00 数据标识无效"*/
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
		case 0x19:/*"过流"*/
		case 0x1A:/*"断流"*/
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
		case 0x19030000:  /*"A B C 相过流"*/
		  file_name_base=OVERCURR_A_BEGINFILE+(id.d[2]-1)*((unsigned int)32);
		  file_name_pointer=*(&Event_Power_Net_Pointer.OverCurrent_A_P+(id.d[2]-1));
		  event_len=243; 
		break;
		
		case 0x1A010000:
		case 0x1A020000:
		case 0x1A030000:  /*"A B C 相断流"*/
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
	
	if(dealkind==0)/*"失流类处理"*/
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
		case 0x19:/*"过流"*/
		case 0x1A:/*"断流"*/
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
		case 0x01:/*"时间"*/
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
		
		case 0x02:/*"总正向有功电量"*/
		case 0x26:
		case 0x06:/*"分相正向有功电量"*/
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
		
		case 0x03:/*"反向有功电量"*/
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
		
		case 0x04:/*"组合无功1"*/
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
	  
		case 0x05:/*"组合无功2"*/
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
		
		case 0x0A:/*"电压"*/
		case 0x13:
		case 0x1C:
		  save_format=UBCD2BYTE;
	    output_format=UBCD2BYTE;
	    save_unit=V_UNIT;
	    output_unit=V_UNIT;
	    save_exp=-1;
	    output_exp=-1;
		break;
		
		case 0x0B:/*"电流"*/
		case 0x14:
		case 0x1D:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=A_UNIT;
	    output_unit=A_UNIT;
	    save_exp=-3;
	    output_exp=-3;
		break;
		
		case 0x0C:/*"有功功率"*/
		case 0x15:
		case 0x1E:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=KW_UNIT;
	    output_unit=KW_UNIT;
	    save_exp=-4;
	    output_exp=Dauto;
		break;
		
		case 0x0D:/*"无功功率"*/
		case 0x16:
		case 0x1F:
		  save_format=BCD3BYTE;
	    output_format=BCD3BYTE;
	    save_unit=KVAR_UNIT;
	    output_unit=KVAR_UNIT;
	    save_exp=-4;
	    output_exp=Dauto;
		break;
		
		case 0x0E:/*"功率因数"*/
		case 0x17:
		case 0x20:
		  save_format=BCD2BYTE;
	    output_format=BCD2BYTE;
	    save_exp=-3;
	    output_exp=-3;
		break;
		
		case 0x21:/*"总安时值"*/
		  save_format=UNSIGNED_LONG;
	    output_format=UBCD4BYTE;
	    save_unit=AH_UNIT;
	    output_unit=AH_UNIT;
	    save_exp=-2;
	    output_exp=-2;
	    dealkind=3;
	  break;
	  
		case 0x22:/*"安时值"*/
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
  
	if(mode==3)/*"显示格式输出"*/
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
	
	/*"取数"*/
	if(dealkind==0)
	{
		for(i=0;i<sizeof_format(save_format);i++)
		 Co.b[300+i]=TempEventData[data_position+i];
	}
	if((dealkind==1)||(dealkind==2))/*"组合无功"*/
	{
		i=Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
		if(dealkind==2)
		 i=Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
		math_Add(&TempEventData[data_position],&Co.b[300],i,SIGNED_LONG,4,4, RAM_MATH);
	}
	if(dealkind==3)/*"总安时值"*/
	{
		math_Add(&TempEventData[data_position],&Co.b[300],0x15,UNSIGNED_LONG,3,4, RAM_MATH);
	}
    
	/*"小数点处理"*/
	if(mode==0)/*"通信"*/
	{
		if(output_exp==Mauto)
      output_exp=-2;
    if(output_exp==Dauto)
      output_exp=-4;
	}
	else/*"显示"*/
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
		case 0x19:/*"过流"*/
		case 0x1A:/*"断流"*/
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
		else/*"没有考虑后续帧"*/
		{
				break;
		}
	}
	
	return data_len;
}

