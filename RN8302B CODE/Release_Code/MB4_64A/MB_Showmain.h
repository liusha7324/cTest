/*" MB2表通用版显示程序 (v0.1 bata0322)  		"*/
/*"液晶屏图号 .122						 		"*/
/*"Creat by TREND 2004-12-01 for shanghai		"*/
/*"Edit  by TREND 2005-03-22 for 通用版 		"*/
//for extern funtion and variable
#define MAX_LINE_NUM			1
#define MAX_DATA_NUM			10
#define MAX_CHAR_NUM			15
#define MAX_BIT_NUM			117
#define SHOW_RAM_NUM                 32

#define _SHOW_HISTORY_MODE      1   /*"如果等于1显示上月上上月，为0显示上1月上2月"*/
#define _SHOW_IO_MODE      		1   /*"如果等于1显示输入输出，为0显示正向反向"*/
//---------------------------------------------------------------------------
#define CYC_B0     Show_flag.bit.BATTERIES1                                        /*"时钟电池电压不足"*/
#define CYC_B1     Err_Code.bit.ENERGY_DIRECT_CHANGE                      /*"电能方向改变"*/
#define CYC_B2     0                                                                               /*"暂未定义"*/
#define CYC_B3     0                                                                               /*"暂未定义"*/
#define CYC_B4     0                                                                               /*"暂未定义"*/
#define CYC_B5     0                                                                               /*"暂未定义"*/ 
#define CYC_B6     0                                                                               /*"暂未定义"*/
#define CYC_B7     0                                                                               /*"暂未定义"*/ 
#define DIE_B0     0                                         					    /*" 暂未定义"*/
#define DIE_B1     0                                                                               /*"内部程序错误，默认不发生"*/
#define DIE_B2     Meter_States.Err_Infor.bit.Rtc_Err                             /*"时钟错误"*/
#define DIE_B3     Meter_States.Err_Infor.bit.Eeprom_Err                       /*"存储器故障或损坏"*/
#define DIE_B4     0                                                                               /*"暂未定义"*/ 
#define DIE_B5     0                                                                               /*"暂未定义"*/ 
#define DIE_B6     0                                                                               /*"暂未定义"*/ 
#define DIE_B7     0                                                                               /*"暂未定义"*/
#define CYC_FLAG    (CYC_B0||CYC_B1||CYC_B2||CYC_B3||CYC_B4||CYC_B5||CYC_B6||CYC_B7)  /*"故障发生标志"*/ 
#define DIE_FLAG    (DIE_B1||DIE_B2||DIE_B3||DIE_B4||DIE_B5||DIE_B6||DIE_B7)          /*"故障发生标志"*/

//---------------------------------------------------------------------------
//public funtion
extern  char Show_Main(unsigned long show_code,char *show_buffer,unsigned long user_code,unsigned char user_code_len);
extern int Show_Initialize(char flag);
extern char Show_Char_Main(char show_char,char On_Off);
extern void clear_show_lcd(void);
extern void tr_show_wait(int time);
extern void cursor_flash(int cursor);
extern char show_on_lcd(char* show_ram,int start_add,int len);
extern char conver_data(char* show_data,char* show_ram,int start_add,int len);
extern char reconver_char(char show_val,char addr);
extern char lcd_special_cortrol(char cortrol_code);
extern void Lcd_Power_On(void);
extern void Lcd_Power_Off(void);
extern char show_on_lcd_only_send_data(char* show_ram,int start_add,int len);
extern int bcd_un_zip(char* input,char* output,int len);//lfy 090927
extern char conver_data0(char* show_data,char* show_ram,int start_add,int len);
//---------------------------------------------------------------------------
/*struct Show_falg_bit_def {
		char	lock:1;
		char	keystoke:1;
		char	key:1;
		char	batteries1:1;
		char	batteries2:1;
		char	batteries3:1;
		char	BT:1;
		char	RS1:1;
		char	RS2:1;
};
union Show_falg_word_def{
	struct Show_falg_bit_def bit;
	int	word;
};

struct Show_flash_falg_bit_def {
		char	reverse:1;
		char	F_ActivePower:1;
		char	B_ActivePower:1;
		char	F_ReactivePower:1;
		char	B_ReactivePower:1;
		char	Ua:1;
		char	Ub:1;
		char	Uc:1;
		char	Ia:1;
		char	Ib:1;
		char	Ic:1;
		char	flash_flag:1;
};
union Show_flash_falg_word_def{
	struct Show_flash_falg_bit_def bit;
	int	word;
};*/
//---------------------------------------------------------------------------
//public variable
extern char vram[MAX_LINE_NUM+3][MAX_DATA_NUM];
extern const unsigned char FILE_DATE[3];

//---------------------------------------------------------------------------

struct Show_falg_bit_def {
	char I:1;                       /*"S2 一象限"*/
	char XY:1;			/*"S1 座标"*/
	char IV:1;			/*"S5 四象限"*/
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

	char II:1;			/*"S3 二象限"*/
	char III:1;                   /*"S4 三象限"*/
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char Base:1;		/*"S79 基站"*/

	char Carrier_Wave:1;	    /*"载波通信s84"*/		
	char BT:1;                       /*"红外通信s85"*/
	char RS1:1;                     /*"第1路485通信"*/
	char RS2:1;                     /*"第2路485通信"*/
	char :1;
	char :1;
	char :1;
	char :1;

	char Signal4:1;	/*"S83 信号4"*/
	char Signal3:1;	/*"S82 信号3"*/
	char Signal2:1;	/*"S81信号2"*/
	char Signal1:1;	/*"S80 信号1"*/
	char :1;
	char :1;
	char :1;
	char :1;

	char Break_switch:1;	      /*"S98 拉闸"*/		
	char Overdraft:1;             /*"S97 透支"*/     
	char Stock_up:1;			/*"S78 囤积"*/ 
	char BATTERIES2:1;		/*"S77"*/
	char :1;
	char :1;
	char :1;
	char :1;
	
	char Fail:1;   		/*"S95 失败"*/
	char Recharge:1;	/*"S96 请充值"*/
	char _Ic:1;		 /*"S72"*/
	char Ib:1; 		/*"S71"*/
	char :1;
	char :1;
	char :1;
	char :1; 

   	char One:1;		/*"S74"*/
	char Two :1;		/*"S75"*/
 	char Ic:1;		/*"S73"*/
	char BATTERIES1:1; 		/*"S76"*/
	char :1;
	char :1;
	char :1;
	char :1;

    	char Read_card:1;		/*"S92 读卡"*/
	char :1;		
	char _Ia:1; 		/*"S68"*/
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

    	char Success:1;	/*"S94 成功"*/
	char Ing:1;		/*"S93 中"*/
	char Ia:1;		/*"S69"*/
	char _Ib:1;		/*"S70"*/
	char :1;
	char :1;
	char :1;
	char :1;

	char Bell:1;                         /*"报警标志S91"*/
	char Home:1;		              /*"室内标志S90"*/
	char lock:1;                        /*"锁标志S89	"*/
	char keystoke:1;                /*"按键标志S88"*/
	char :1;
	char :1;				
	char :1;			
	char :1;				

	char Ua:1;		/*"S64"*/
	char Ub:1;		/*"S65"*/	
	char Uc:1;		/*"S66"*/
	char Athwart:1;	            /*"S67 逆相序"*/			
	char :1;			
	char :1;			
	char :1;			
	char :1;	

	char :1;			
	char :1;	
  	char A_S:1;		
	char B_S:1;		
	char C_S:1;		
	char North:1;
	char key:1;
	char flash_flag:1;

//char Not_Enough:1;			
//	char Change:1;  	
//	char BATTERIES3:1;
//	char Four:1; 		
//	char NC26:1;		
//	char winter:1;
//	char Three:1;
};

union Show_falg_word_def{
	struct 	Show_falg_bit_def bit;
	char	byte[13];
};

struct Show_Err_Flag_def
{
    char CLK_BATTER_LOW:1;
    char ENERGY_DIRECT_CHANGE:1;
    char CLK_BATTER_TIME_LIMIT:1;
    char PROG_ERR:1;
    char CLK_ERR:1;
    char MEM_ERR:1;
    char UNDEF1:1;
    char UNDEF2:1;
};

union Show_Err_Code
{
    struct Show_Err_Flag_def bit;
    char byte;
};

extern unsigned char show_mode1;/*"新C套显示标志"*/
extern unsigned char show_leaf_flag;
//extern unsigned char show_mode; /*"新老显示标志"*/
extern unsigned char fshow_flag;
extern  char ret_flag;                           /*"0 时表示此节点所有的叶子都取完"*/         
extern  char leaf_flag;                          /*"取节点中第几片叶子标志"*/
extern union Show_falg_word_def Show_flag;			/*"点亮的标志"*/
extern union Show_falg_word_def Show_flash_falg; 	/*"闪烁的标志。闪烁优先"*/ 
extern union Show_Err_Code Err_Code;
extern unsigned char set_cycle_num;;

//payment
extern unsigned long dispCardDataTime;
extern unsigned long dispCardDataTimeLen;
extern unsigned int meterDispErr_ID;         		/*"电能表出错信息码:代号"*/ 
extern union BYTE_BIT dispPaymentFlag;
extern union BYTE_BIT dispCharFlag[];


#define READ_CARD_IN				1		/*"显示字符:读卡中"*/
#define DISP_ERR_DATA			2			/*"显示错误(ERR-xxxx)"*/
#define DISP_CARD				3			/*"显示CARD和读卡中"*/

#define READ_CARD_SUCCESS	10		/*"显示:读卡成功"*/
#define READ_CARD_FAIL			11		/*"显示:读卡失败"*/
#define DISP_CHAR_HOARD		12		/*"显示字符:囤积"*/
#define DISP_REMAIN_DATA		13		/*"显示当前剩余电费数据"*/
#define DISP_DEFICIT_DATA	14		/*"显示欠电费数据"*/
#define DISP_BEFOR_REMAIN	15		/*"显示上一次购电前剩余电费后自动显示当前剩余电量"*/
#define DISP_IC_ERR					16		/*"显示IC插卡错误(IC--xx)"*/
#define DISP_METTER_ID			17		/*"显示表号"*/
#define DISP_CHAR_GOOD			18		/*"显示:GOOD"*/

#define DISP_CHAR_KEYSTOKE			21		/*"编程符号"*/
#define DISP_CHAR_HOME					22		/*"公钥(实验室)符号"*/
#define DISP_CHAR_ALARM				23		/*"报警指示"*/
#define DISP_CHAR_SWITCH				24		/*"跳闸"*/
#define DISP_CHAR_BUY					25		/*"请购电"*/
#define DISP_CHAR_TICK					26		/*"透支"*/

#define METER_SOFT_ERR			0x0001			/*"程序错误"*/
#define METER_ROM_ERR			0x0002			/*"存储器出错"*/
extern void displayReadCard(unsigned char mode);
extern void displayCharTimeLen(unsigned char mode,unsigned char timeLen,unsigned char flag);
extern void displayCharOnOff(unsigned char mode,unsigned char onOff,unsigned char flash);
extern void dispPaymentChar(void);
extern void Disp_Char_Clear(void);

