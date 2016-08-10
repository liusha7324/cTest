/*"**********************************************************************************"*/
/*" CPU卡接口电路资源配置： "*/
/*" 以MB3V7.0硬件原理为例 "*/

/*" UART "*/
/*" 占用UART2 "*/

/*" I/O端口 "*/
/*" 以MB3V7.0为例 "*/
/*" P4_4   UART切换控制                                       IC_IN/CARD_CTR1 "*/
/*" P5_4   UART切换控制                                       Card/RS485 "*/
/*" 切换控制原理参考4052B "*/
/*" A0（P4_4）   A1（P5_4） "*/
/*" 0            0                       UART切换到ESAM "*/
/*" 0            1                       UART切换到RS485 "*/
/*" 1            0                       UART切换到CPU卡 "*/
/*" 1            1                       UART切换到载波 "*/

/*" P4_2   ESAM振荡器输出控制                                 IC_OUT/CPU_CLK_Ctr "*/
/*" P4_3   ESAM复位控制                                       PSAM_RST "*/ 
/*" P2_5   ESAM上电控制                                       PASM_PWR "*/

/*" P5_5   CPU卡振荡器输出控制/逻辑加密卡的CLK信号            IC_CLK/CPU_CLK_CTRL "*/
/*" P4_1   CPU卡复位控制/逻辑加密卡复位控制                   IC_RST "*/
/*" P4_0   CPU卡上电控制/逻辑加密卡上电控制                   IC_PWR "*/
/*" P4_5   CPU卡到位信号/逻辑加密卡到位信号                   IC_SW "*/

/*" 看门狗喂狗函数 "*/
/*" 缓冲区（200个字节以上） "*/
/*" RAM（200个字节以上） "*/

/*"**********************************************************************************"*/
/*" I/O口预定义，不同的MCU可能不一样 "*/
/*
#define CPU_SW                       p4_5

#define CPU_VCC_OUTPUT               p4_0
//#define CPU_CLK_OUTPUT               p5_5
#define CPU_RST_OUTPUT               p4_1

#define ESAM_VCC_OUTPUT              p2_0
#define ESAM_CLK_OUTPUT              p4_2
#define ESAM_RST_OUTPUT              p4_3

#define CPU_SWITCH_ESAM_OUTPUT       p4_4
#define RS485_SWITCH_CARRIER_OUTPUT  p5_4
*/
/*" 输入输出定义 "*/
/*
#define CPU_SW_DIRECT                pd4_5

#define CPU_VCC_DIRECT               pd4_0
//#define CPU_CLK_DIRECT               pd5_5
#define CPU_RST_DIRECT               pd4_1

#define ESAM_VCC_DIRECT              pd2_0
#define ESAM_CLK_DIRECT              pd4_2
#define ESAM_RST_DIRECT              pd4_3

#define CPU_SWITCH_ESAM_DIRECT       pd4_4
#define RS485_SWITCH_CARRIER_DIRECT  pd5_4
*/
/*"**********************************************************************************"*/
/*" 预定义定义,有关于CPU底层操作的错误 "*/
#define FAR_COMM         0        
#define CPU              1
#define ESAM             2
#define ZB_COMM          3

#define OUTPUT           1
#define INPUT            0
#define ERR              0xFF
#define OK               0x00
/*"**********************************************************************************"*/
/*" 错误代码定义,有关于CPU底层操作的错误 "*/
#define CPU_CARD_COMM_DELAY_ERR     0x0014           /*" CPU卡接收错 "*/

#define CPU_CARD_SUCCESS            0xFFFF           /*" 处理过程正确 "*/


/*"**********************************************************************************"*/
/*" CPU卡状态字定义 "*/
#define Read_Binary      0xb0    /*"从CPU卡读二进制文件"*/ 
#define Read_Record      0xb2    /*"从CPU卡读记录文件"*/                  
#define Get_Challenge    0x84    /*"从CPU卡取随机数"*/              
#define Get_Response     0xc0    /*"从CPU卡取响应数据"*/

#define Update_Binary    0xd6    //修改二进制文件 
#define Append_Record    0xe2    //增加记录               
#define Update_Record    0xdc    //修改记录         
#define Write_Key        0xd4    //增加或修改密钥   
#define Increase         0x32    //存款                      
#define Decrease         0x30    //扣款   
/*"**********************************************************************************"*/
/*" 底层函数定义 "*/

extern void Receive_Data_To_Cpucard(void);            /*" 串口接收函数 "*/

extern unsigned char Check_CPU_Occur(void);           /*" 检测CPU卡是否插入或未被拔卡 "*/
                                                      /*" 0x00表示卡口有卡，~0表示卡口无卡 "*/
extern void CPU_VCC_Control(unsigned char );          /*" CPU卡上电I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/
extern void CPU_CLK_Control(unsigned char );          /*" CPU卡振荡器输出I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/
extern void CPU_RST_Control(unsigned char );          /*" CPU卡复位I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/

extern void ESAM_VCC_Control(unsigned char );         /*" ESAM卡上电I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/
extern void ESAM_CLK_Control(unsigned char );         /*" ESAM卡振荡器输出I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/
extern void ESAM_RST_Control(unsigned char );         /*" ESAM卡复位I/O口控制 "*/
                                                      /*" 入口参数表示将要控制的I/O口电平：0或者1 "*/

extern void CPU_ESAM_CARD_Control(unsigned char);     /*" 串口切换控制 "*/


extern void Cpu_Card_IO_Init(void);                   /*" CPU卡的UART口，所有I/O口初始化 "*/
extern void Cpu_Card_IO_Reset(void);                  /*" CPU卡的UART口，所有I/O口释放 "*/

extern void Cpu_PowOff(void);                         /*" CPU卡下电 "*/
extern void Cpu_Reset_Cool(void);                     /*" CPU卡冷复位 "*/

extern void Esam_PowOff(void);                        /*" ESAM卡下电 "*/
extern void Esam_Reset_Cool(void);                    /*" ESAM卡冷复位 "*/

extern void Enable_Serial_Receive(void);              /*" 使能serial  接收，禁止serial 发送 "*/
extern void Enable_Serial_Send(void);                 /*" 使能serial  发送，禁止serial 接收 "*/
extern unsigned char Wait_Receive(unsigned char );    /*" 接收等待 "*/
                                               /*" 入口参数：需等待接收的数据长度 "*/
                                               /*" FF表示错误响应，00表示正确响应 "*/
extern unsigned char Cpucard_Atr(void);               /*" CPU卡复位应答,FF表示错误响应，00表示正确响应 "*/
extern unsigned char Esamcard_Atr(void);              /*" ESAM卡复位应答,FF表示错误响应，00表示正确响应 "*/

//void select_communication_port(unsigned char); /*" 选择UART口指向位置 "*/

extern unsigned char Internal_Auth(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                               /*" 内部命令，不公开 "*/
extern unsigned char External_Auth(unsigned char ,unsigned char ,unsigned char *);
                                               /*" 内部命令，不公开 "*/
extern unsigned char Cpucard_Esamcard_Internal_Auth(unsigned char );   
                                               /*" 内部认证 "*/
                                               /*" FF表示错误响应，00表示正确响应 "*/
extern unsigned char Cpucard_External_Auth(void);     /*" CPU卡外部认证 "*/
                                               /*" FF表示错误响应，00表示正确响应 "*/

extern unsigned char Select_File(unsigned char ,unsigned char ,unsigned char );
                                               /*" 文件选择命令，用于选择ESAM或CPU卡中的某个文件 "*/
                                               /*" 参数有待讨论 "*/
extern unsigned char Read(unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char );
                                               /*" 内部命令，不公开 "*/
extern unsigned char Write(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                               /*" 内部命令，不公开 "*/

extern unsigned char Card_Write(unsigned char,unsigned char *,unsigned char,unsigned char  );
                                               /*" 数据写CPU卡或ESAM卡 "*/
                                               /*" 参数有待讨论 "*/
extern unsigned char Cpu_card_Block_Write(unsigned char ,unsigned char *,unsigned char ,unsigned int  );

extern unsigned char Card_Read(unsigned char ,unsigned char *,unsigned char,unsigned char  );
                                               /*" 从CPU卡或ESAM卡读数据 "*/
                                               /*" 参数有待讨论 "*/

extern void My_Memcpy(unsigned char *,unsigned char *,unsigned char); /*" 数据转移 "*/
extern unsigned char My_Memcmp(unsigned char *,unsigned char *,unsigned char); /*" 数据比较 "*/

extern void Pay_IO_Init(void);
extern void Cpu_Card_IO_Powerdown(void);                       /*" 掉电CPU卡相关电路初始化处理 "*/

extern unsigned char Remain_Money_Moneybag_Add(unsigned char ,unsigned char,unsigned char *);
extern unsigned char Remain_Money_Moneybag_Step(unsigned char ,unsigned char );
extern unsigned char Remain_Money_Moneybag_Init(void);
extern unsigned char Esam_File_Updata(unsigned char ,unsigned char ,unsigned char ,
									  unsigned char ,unsigned char ,unsigned char *);
extern unsigned char Cpu_File_Updata(unsigned char ,unsigned char ,unsigned char ,
							   		unsigned char ,unsigned char );
extern unsigned char Remain_Money_Moneybag_To_Cpu(void);
extern unsigned char Read_Esam_Moneybag_File(unsigned char * );

extern unsigned char Esam_Remain_Money_Dec(void);
extern void Esam_Remain_Money_Do(unsigned char );
extern unsigned char  CPU_Card_Driver(const unsigned char *,unsigned char ,unsigned char *,unsigned char,unsigned char,unsigned char);
extern unsigned char Get_File_Data(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char * );
extern unsigned char CPU_Counter_Dec(unsigned char ,unsigned char );
extern unsigned char PassWord_Updata(unsigned char);
extern void Cpucard_Serial_Init(void);/*" 串口初始化 "*/
extern void cpucard_serial_release(void);
extern unsigned char Judge_Return_Flag(void);
extern void Receive_Data_To_Cpucard_CPU(void);
extern void Receive_Data_To_Cpucard(void);

/*"**********************************************************************************"*/
/*" 变量说明 "*/
extern unsigned int receive_data_length;      /*"实际接收到的CPU卡或ESAM卡数据的长度（字节个数）"*/
extern unsigned char cpucard_number[8];        /*"cpu卡号, 分散因子"*/
extern unsigned int press_card_state;          /*"处理cpu卡后的状态标志：代号"*/ 
extern unsigned char receive_send_buffer[]; /*"接收\发送CPU卡或ESAM卡数据的缓冲区，密钥卡AE=174"*/
extern unsigned char CommunicationPortMode;
extern unsigned char Far_Comm_Init_NO;

extern unsigned char Esam_Err_Count;
extern unsigned long Reamin_Money_ESAM_Dec_Time;


