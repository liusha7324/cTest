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
/*"�ڵ㶨��"*/
/*"����				������	������												��˵��                        "*/
/*"ID					��4		�����ݱ�ʶ										��	                              "*/
/*"Node_mode	��1		���ڵ�ģʽ										��Bit0��1�ڵ㣻0Ҷ��    "*/
/*"						��			��														��Bit1��1���ڵ��ID��Ч��0��Ч                 "*/
/*"						��			��														��Bit2��1���ڵ�����ѹ����0��                   "*/
/*"						��			��														��Bit3��1�¼��ڵ������ݱ�ʶ��0��               "*/
/*"						��			��														��Bit4-Bit7��ѹ�������ݱ�ʶ                    "*/
/*"ID_Start		��1		��ѹ�����ݱ�ʶ����ʼֵ				����ѹ��ʱ��Ч"*/
/*"ID_end			��1		��ѹ�����ݱ�ʶ�Ľ���ֵ				����ѹ��ʱ��Ч  "*/
/*"High_Node	��2		���ϼ��ڵ��ַ	         			��         "*/
/*"Next_Node	��2		���¸�ͬ���ڵ��ַ	     			��         "*/
/*"Low_Node		��2		���¼��ڵ��ַ/Ҷ�Ӷ����ַ	��"*/
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
/*"��ַ����"*/
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
/*"Ȩ��"*/
struct COMMUNAL_PURVIEW
{
	unsigned char read_mode;
	unsigned char	write_mode[3];
};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"����"*/
struct COMMUNAL_FUNCTION
{
		TOn_Write_Event OnWrite_Beford;
		TOn_Write_Event OnWrite_End;
		TOn_Read_Event OnRead;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"��ʾ"*/
struct COMMUNAL_SHOWINFO
{
   unsigned char schar[5];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"���"*/
struct COMMUNAL_MATHINFO
{	
	unsigned char Ass_data_addr;
	unsigned char Ass_data_num;
	unsigned int 	math_mode;
	unsigned char math_type;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"��ʽ"*/
struct COMMUNAL_FORMAT
{
	unsigned char format;
	unsigned char unit;
	  signed char exp;
};
struct COMMUNAL_ID
{	
	unsigned char Communal_Save_Id;   /*"�洢��ʽ"*/
	unsigned char Communal_Trans_Id;  /*"�����ʽ"*/
	unsigned char Communal_Show_Id;  /*"�����ʽ"*/	
};

struct COMMUNAL_RANGE 
{	
	unsigned int ID_Start;   /*"�洢��ʽ"*/
	unsigned int ID_End;  /*"�����ʽ"*/
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"Ҷ�Ӷ���"*/
/*"����										������	������				��˵��"*/
/*"addr										��4		����ַ				��"*/
/*"Communal_Addr_Id				��1		����ַ����ID	�����е�ַ�����Ĳ�������Ҫ����ѹ�����ݵĵ�ַ����"*/
/*"Communal_Math_Mode_Id	��1		�������ϢID	��"*/
/*"Communal_Id						��1		����ʽ��ϢID	��"*/
/*"Communal_Purview_Id		��1		��Ȩ����ϢID	��"*/
/*"Communal_Function_Id		��1		��������ϢID	��"*/
/*"Communal_Showinfo_Id		��2		����ʾ��ϢID	��"*/

struct TREE_LEAF
{
	unsigned long addr;
	unsigned char Communal_Addr_Id;
	unsigned char	Communal_Math_Mode_Id;	
	unsigned char Communal_Id;
	unsigned char Communal_Purview_Id;/*"��дȨ��"*/	
	unsigned char Communal_Function_Id;/*"��д����"*/
	unsigned char Communal_Showinfo_Id;/*"��ʾ���ñ�ID"*/
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
