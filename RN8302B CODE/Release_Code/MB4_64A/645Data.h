#ifndef _645DATA_
#define _645DATA_

typedef int  (* TOn_Read_Event)(void);
typedef int (* TOn_Write_Event)(void);

struct MODE_BIT
{
	unsigned char mode:1;
	unsigned char ID_Enable:1;
	unsigned char zip:1;
	unsigned char Low_Node_Num:1;
	unsigned char num :4;
};
union NODE_MODE{
	char	byte;
	struct MODE_BIT bit;		
};
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"节点定义"*/
/*"属性				│长度	│名称												│说明                        "*/
/*"ID					│4		│数据标识										│	                              "*/
/*"Node_mode	│1		│节点模式										│Bit0：1节点；0叶子    "*/
/*"						│			│														│Bit1：1本节点的ID有效；0无效                 "*/
/*"						│			│														│Bit2：1本节点是有压缩；0无                   "*/
/*"						│			│														│Bit3：1下级节点有数据标识；0无               "*/
/*"						│			│														│Bit4-Bit7：压缩的数据标识                    "*/
/*"ID_Start		│1		│压缩数据标识的起始值				│有压缩时有效"*/
/*"ID_end			│1		│压缩数据标识的结束值				│有压缩时有效  "*/
/*"High_Node	│2		│上级节点地址	         			│         "*/
/*"Next_Node	│2		│下个同级节点地址	     			│         "*/
/*"Low_Node		│2		│下级节点地址/叶子对象地址	│"*/
struct TREE_NODE
{
	unsigned long ID;
	union NODE_MODE Node_mode;
	unsigned char Range_ID;
	//unsigned char ID_end;
	//unsigned int High_Node;
	unsigned int Next_Node;
	unsigned int Low_Node;
};
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"地址修正"*/
struct REVISE_ID
{
	unsigned char Revise_Id[2];
};
struct COMMUNAL_REVISE
{
	unsigned char	Revise_Mode  ; 
	unsigned int	Revise_Size   ;
	unsigned char	Revise_Max_Num;
	unsigned int  Revise_Basce;  
};



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"权限"*/
struct COMMUNAL_PURVIEW
{
	unsigned char read_mode;
	unsigned char	write_mode[3];
};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"方法"*/
struct COMMUNAL_FUNCTION
{
		TOn_Write_Event OnWrite_Beford;
		TOn_Write_Event OnWrite_End;
		TOn_Read_Event OnRead;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"显示"*/
struct COMMUNAL_SHOWINFO
{
   unsigned char schar[5];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"组合"*/
struct COMMUNAL_MATHINFO
{	
	unsigned char Ass_data_addr;
	unsigned char Ass_data_num;
	unsigned int 	math_mode;
	unsigned char math_type;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"格式"*/
struct COMMUNAL_FORMAT
{
	unsigned char format;
	unsigned char unit;
	  signed char exp;
};
struct COMMUNAL_ID
{	
	unsigned char Communal_Save_Id;   /*"存储格式"*/
	unsigned char Communal_Trans_Id;  /*"传输格式"*/
	unsigned char Communal_Show_Id;  /*"传输格式"*/	
};

struct COMMUNAL_RANGE 
{	
	unsigned int ID_Start;   /*"存储格式"*/
	unsigned int ID_End;  /*"传输格式"*/
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"叶子定义"*/
/*"属性										│长度	│名称				│说明"*/
/*"addr										│4		│地址				│"*/
/*"Communal_Addr_Id				│1		│地址修正ID	│进行地址修正的参数，主要用于压缩数据的地址修正"*/
/*"Communal_Math_Mode_Id	│1		│组合信息ID	│"*/
/*"Communal_Id						│1		│格式信息ID	│"*/
/*"Communal_Purview_Id		│1		│权限信息ID	│"*/
/*"Communal_Function_Id		│1		│方法信息ID	│"*/
/*"Communal_Showinfo_Id		│2		│显示信息ID	│"*/

struct TREE_LEAF
{
	unsigned long addr;
	unsigned char Communal_Addr_Id;
	unsigned char	Communal_Math_Mode_Id;	
	unsigned char Communal_Id;
	unsigned char Communal_Purview_Id;/*"读写权限"*/	
	unsigned char Communal_Function_Id;/*"读写方法"*/
	unsigned char Communal_Showinfo_Id;/*"显示配置表ID"*/
};
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


#endif


extern  const int Protocol_Tree_Root[34];
extern  const struct COMMUNAL_REVISE Protocol_Revise[117];
extern  const struct REVISE_ID Protocol_Revise_Id[137];
extern  const struct COMMUNAL_FORMAT Protocol_Format[138];
extern  const struct COMMUNAL_PURVIEW Protocol_Purview[10];
extern  const struct COMMUNAL_FUNCTION Protocol_Function[94];
extern  const struct TREE_NODE Protocol_Tree_Node[2913];
extern  const struct TREE_LEAF Protocol_Tree_Leaf[2464];
extern  const struct COMMUNAL_SHOWINFO Protocol_Showinfo[160];
extern  const struct COMMUNAL_ID Protocol_Id[113];
extern  const struct COMMUNAL_MATHINFO Protocol_MATHINFO[14];
extern  const struct COMMUNAL_RANGE Protocol_Range[22];
