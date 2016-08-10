/*"**********************************************************************************"*/
#ifndef  _far_pay_h_
#define  _far_pay_h_

#define NUM_MS_PER_MINUTE   60000UL     /*"1分钟用毫秒表示"*/
#define UART_IR             1           /*" 红外通道 "*/
/*"**********************************************************************************"*/
/*"数据结构定义"*/
struct Authentication_Instruction
{
	unsigned char cryptograph1[8];								/*"密文1"*/
	unsigned char	random_number1[8];							/*"随机数1"*/
	unsigned char disperse_gene[8];							/*"分散因子 (2013新规范使用表号作为分散因子 )"*/
};

struct Authentication_Responsion
{
	unsigned char	random_number2[4];							/*"随机数2"*/
	unsigned char	esam_serial_number[8];						/*"ESAM序列号"*/	
};

struct Far_Identity_Authentication_Define
{
	struct Authentication_Instruction Instruction;					/*"身份认证指令"*/
	struct Authentication_Responsion Responsion;					/*"应答并返回随机数2"*/
};

struct Far_Buy_Money_Data_Define
{
	unsigned long buy_money;									/*"购电金额"*/
	unsigned long buy_count;									/*"购电次数"*/
	unsigned char mac1[4];									/*"MAC 1"*/
	unsigned char disperse_gene[8];							/*"分散因子"*/
	unsigned char user_id[6];									/*"户号"*/
	unsigned char mac2[4];									/*"MAC2"*/
};

struct Open_Close_Switch_Command_Define
{
	unsigned char open_close_switch_control;					/*"拉合闸控制字"*/
	unsigned int  open_close_switch_report_emergency_time;	/*"拉合闸告警时间"*/
	unsigned int open_close_switch_enable_time;				/*"拉合闸操作时效性"*/
	unsigned char Year;										/*"时间戳"*/
    unsigned char Month;
    unsigned char Day;
    unsigned char Hour;
    unsigned char Min;
    unsigned char Sec;		
};

union SECURITY_AUTH_ERR_INFORMATION
{
    struct
      {  
	unsigned char OTHER_ERR:1;		/*"--其他错误----"*/
	unsigned char REPEAT_INCREASE_ERR:1;		/*"--重复充值----------------"*/
	unsigned char ESAM_AUTH_ERR:1;	/*"--ESAM验证失败-----------"*/
	unsigned char IDENTITY_AUTH_ERR:1;	/*"--身份认证失败---------"*/
	unsigned char CLIENT_ID_ERR:1;			/*"--客户编号不匹配-------"*/
	unsigned char BUY_COUNT_ERR:1;			/*"--购电次数错---"*/
	unsigned char BUY_MONEY_OVER_ERR:1;				/*"--电费超囤积---"*/
	unsigned char addr_err:1;			/*"--地址错误---"*/
	unsigned char HANG_ERR:1;						/*"挂起状态"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
	unsigned char :1;						/*"--保留------------"*/
      }bit;
      unsigned int intd;  
}; 
#define OTHER_ERR_DEFINE							Far_Security_Auth_Err_Info.bit.OTHER_ERR
#define REPEAT_INCREASE_ERR_DEFINE				Far_Security_Auth_Err_Info.bit.REPEAT_INCREASE_ERR
#define ESAM_AUTH_ERR_DEFINE						Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR
#define IDENTITY_AUTH_ERR_DEFINE					Far_Security_Auth_Err_Info.bit.IDENTITY_AUTH_ERR
#define CLIENT_ID_ERR_DEFINE						Far_Security_Auth_Err_Info.bit.CLIENT_ID_ERR
#define BUY_COUNT_ERR_DEFINE						Far_Security_Auth_Err_Info.bit.BUY_COUNT_ERR
#define BUY_MONEY_OVER_ERR_DEFINE				Far_Security_Auth_Err_Info.bit.BUY_MONEY_OVER_ERR
#define SERR_ADDR_ERR_DEFINE				Far_Security_Auth_Err_Info.bit.addr_err
#define HANG_ERR_DEFINE						    Far_Security_Auth_Err_Info.bit.HANG_ERR

/*"命令解密后的 明文格式 (N1～Nm解密后的明文数据为R1～R8)"*/
struct cmd_plaintext {
    unsigned char code;         /*"命令控制码 "*/
    unsigned char rsv;          /*"保留字节"*/
    struct DATA_TIME deadline;  /*"命令截止日期 "*/
};

//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
/*"**********************************************************************************"*/
extern struct _Pre_Payment_Para            Pre_Payment_Para;
//extern struct _Pre_Power_Down_Save_Data    Pre_Power_Down_Save_Data;
extern struct _Pre_Payment_Data            Pre_Payment_Data;
extern struct Far_Identity_Authentication_Define Far_Identity_Auth_Data;		/*"远程身份认证数据"*/
extern unsigned char Far_Identity_Auth_Ok_Flag;						 	/*"远程身份认证成功标志"*/
extern unsigned long Far_Identity_Auth_Ok_Time;						 	/*"身份认证时间--"*/
extern unsigned int Esam_Far_Identity_Auth_Valid_Time;						/*"ESAM身份认证有效时长"*/
extern unsigned char Far_Spec_Order_Flag;
extern unsigned int  R_ID_Remain_Time;
extern unsigned char Far_InfraredFlag; 
extern unsigned int  R_Infrared_Remain_Time;
extern unsigned long Far_Infrared_Auth_Ok_Time;
extern unsigned long FarOpenTime;
//extern unsigned char FayMidefyFlag;


extern unsigned char Far_Password_Check(unsigned char *  ,unsigned char *  ,unsigned char *);

/*"**********************************************************************************"*/
extern void Far_Prepayment_Read_Write(unsigned char );			/*"远程费控读数据"*/
extern void Far_Control(unsigned char );	
extern void Far_Switch_Control(unsigned char);

extern unsigned char cmd_0x98_mode_decipher(unsigned char uartx, unsigned char cmd_code);
extern void clear_psw_upd_info(void);
extern void get_meter_para_from_esam(void);
extern unsigned char check_and_update_psw_to_esam(void);
extern unsigned char get_psw_status_wd_from_esam(void);
extern void record_esam_oprate_err(void);
extern void end_infrared_auth(void);
extern unsigned char is_test_psw_status(void);


extern unsigned char refund_money(signed long money);
#endif
/**************************************************/



