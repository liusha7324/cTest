/*"**********************************************************************************"*/
/*" CPU���ӿڵ�·��Դ���ã� "*/
/*" ��MB3V7.0Ӳ��ԭ��Ϊ�� "*/

/*" UART "*/
/*" ռ��UART2 "*/

/*" I/O�˿� "*/
/*" ��MB3V7.0Ϊ�� "*/
/*" P4_4   UART�л�����                                       IC_IN/CARD_CTR1 "*/
/*" P5_4   UART�л�����                                       Card/RS485 "*/
/*" �л�����ԭ��ο�4052B "*/
/*" A0��P4_4��   A1��P5_4�� "*/
/*" 0            0                       UART�л���ESAM "*/
/*" 0            1                       UART�л���RS485 "*/
/*" 1            0                       UART�л���CPU�� "*/
/*" 1            1                       UART�л����ز� "*/

/*" P4_2   ESAM�����������                                 IC_OUT/CPU_CLK_Ctr "*/
/*" P4_3   ESAM��λ����                                       PSAM_RST "*/ 
/*" P2_5   ESAM�ϵ����                                       PASM_PWR "*/

/*" P5_5   CPU�������������/�߼����ܿ���CLK�ź�            IC_CLK/CPU_CLK_CTRL "*/
/*" P4_1   CPU����λ����/�߼����ܿ���λ����                   IC_RST "*/
/*" P4_0   CPU���ϵ����/�߼����ܿ��ϵ����                   IC_PWR "*/
/*" P4_5   CPU����λ�ź�/�߼����ܿ���λ�ź�                   IC_SW "*/

/*" ���Ź�ι������ "*/
/*" ��������200���ֽ����ϣ� "*/
/*" RAM��200���ֽ����ϣ� "*/

/*"**********************************************************************************"*/
/*" I/O��Ԥ���壬��ͬ��MCU���ܲ�һ�� "*/
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
/*" ����������� "*/
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
/*" Ԥ���嶨��,�й���CPU�ײ�����Ĵ��� "*/
#define FAR_COMM         0        
#define CPU              1
#define ESAM             2
#define ZB_COMM          3

#define OUTPUT           1
#define INPUT            0
#define ERR              0xFF
#define OK               0x00
/*"**********************************************************************************"*/
/*" ������붨��,�й���CPU�ײ�����Ĵ��� "*/
#define CPU_CARD_COMM_DELAY_ERR     0x0014           /*" CPU�����մ� "*/

#define CPU_CARD_SUCCESS            0xFFFF           /*" ���������ȷ "*/


/*"**********************************************************************************"*/
/*" CPU��״̬�ֶ��� "*/
#define Read_Binary      0xb0    /*"��CPU�����������ļ�"*/ 
#define Read_Record      0xb2    /*"��CPU������¼�ļ�"*/                  
#define Get_Challenge    0x84    /*"��CPU��ȡ�����"*/              
#define Get_Response     0xc0    /*"��CPU��ȡ��Ӧ����"*/

#define Update_Binary    0xd6    //�޸Ķ������ļ� 
#define Append_Record    0xe2    //���Ӽ�¼               
#define Update_Record    0xdc    //�޸ļ�¼         
#define Write_Key        0xd4    //���ӻ��޸���Կ   
#define Increase         0x32    //���                      
#define Decrease         0x30    //�ۿ�   
/*"**********************************************************************************"*/
/*" �ײ㺯������ "*/

extern void Receive_Data_To_Cpucard(void);            /*" ���ڽ��պ��� "*/

extern unsigned char Check_CPU_Occur(void);           /*" ���CPU���Ƿ�����δ���ο� "*/
                                                      /*" 0x00��ʾ�����п���~0��ʾ�����޿� "*/
extern void CPU_VCC_Control(unsigned char );          /*" CPU���ϵ�I/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/
extern void CPU_CLK_Control(unsigned char );          /*" CPU���������I/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/
extern void CPU_RST_Control(unsigned char );          /*" CPU����λI/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/

extern void ESAM_VCC_Control(unsigned char );         /*" ESAM���ϵ�I/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/
extern void ESAM_CLK_Control(unsigned char );         /*" ESAM���������I/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/
extern void ESAM_RST_Control(unsigned char );         /*" ESAM����λI/O�ڿ��� "*/
                                                      /*" ��ڲ�����ʾ��Ҫ���Ƶ�I/O�ڵ�ƽ��0����1 "*/

extern void CPU_ESAM_CARD_Control(unsigned char);     /*" �����л����� "*/


extern void Cpu_Card_IO_Init(void);                   /*" CPU����UART�ڣ�����I/O�ڳ�ʼ�� "*/
extern void Cpu_Card_IO_Reset(void);                  /*" CPU����UART�ڣ�����I/O���ͷ� "*/

extern void Cpu_PowOff(void);                         /*" CPU���µ� "*/
extern void Cpu_Reset_Cool(void);                     /*" CPU���临λ "*/

extern void Esam_PowOff(void);                        /*" ESAM���µ� "*/
extern void Esam_Reset_Cool(void);                    /*" ESAM���临λ "*/

extern void Enable_Serial_Receive(void);              /*" ʹ��serial  ���գ���ֹserial ���� "*/
extern void Enable_Serial_Send(void);                 /*" ʹ��serial  ���ͣ���ֹserial ���� "*/
extern unsigned char Wait_Receive(unsigned char );    /*" ���յȴ� "*/
                                               /*" ��ڲ�������ȴ����յ����ݳ��� "*/
                                               /*" FF��ʾ������Ӧ��00��ʾ��ȷ��Ӧ "*/
extern unsigned char Cpucard_Atr(void);               /*" CPU����λӦ��,FF��ʾ������Ӧ��00��ʾ��ȷ��Ӧ "*/
extern unsigned char Esamcard_Atr(void);              /*" ESAM����λӦ��,FF��ʾ������Ӧ��00��ʾ��ȷ��Ӧ "*/

//void select_communication_port(unsigned char); /*" ѡ��UART��ָ��λ�� "*/

extern unsigned char Internal_Auth(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                               /*" �ڲ���������� "*/
extern unsigned char External_Auth(unsigned char ,unsigned char ,unsigned char *);
                                               /*" �ڲ���������� "*/
extern unsigned char Cpucard_Esamcard_Internal_Auth(unsigned char );   
                                               /*" �ڲ���֤ "*/
                                               /*" FF��ʾ������Ӧ��00��ʾ��ȷ��Ӧ "*/
extern unsigned char Cpucard_External_Auth(void);     /*" CPU���ⲿ��֤ "*/
                                               /*" FF��ʾ������Ӧ��00��ʾ��ȷ��Ӧ "*/

extern unsigned char Select_File(unsigned char ,unsigned char ,unsigned char );
                                               /*" �ļ�ѡ���������ѡ��ESAM��CPU���е�ĳ���ļ� "*/
                                               /*" �����д����� "*/
extern unsigned char Read(unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char );
                                               /*" �ڲ���������� "*/
extern unsigned char Write(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                               /*" �ڲ���������� "*/

extern unsigned char Card_Write(unsigned char,unsigned char *,unsigned char,unsigned char  );
                                               /*" ����дCPU����ESAM�� "*/
                                               /*" �����д����� "*/
extern unsigned char Cpu_card_Block_Write(unsigned char ,unsigned char *,unsigned char ,unsigned int  );

extern unsigned char Card_Read(unsigned char ,unsigned char *,unsigned char,unsigned char  );
                                               /*" ��CPU����ESAM�������� "*/
                                               /*" �����д����� "*/

extern void My_Memcpy(unsigned char *,unsigned char *,unsigned char); /*" ����ת�� "*/
extern unsigned char My_Memcmp(unsigned char *,unsigned char *,unsigned char); /*" ���ݱȽ� "*/

extern void Pay_IO_Init(void);
extern void Cpu_Card_IO_Powerdown(void);                       /*" ����CPU����ص�·��ʼ������ "*/

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
extern void Cpucard_Serial_Init(void);/*" ���ڳ�ʼ�� "*/
extern void cpucard_serial_release(void);
extern unsigned char Judge_Return_Flag(void);
extern void Receive_Data_To_Cpucard_CPU(void);
extern void Receive_Data_To_Cpucard(void);

/*"**********************************************************************************"*/
/*" ����˵�� "*/
extern unsigned int receive_data_length;      /*"ʵ�ʽ��յ���CPU����ESAM�����ݵĳ��ȣ��ֽڸ�����"*/
extern unsigned char cpucard_number[8];        /*"cpu����, ��ɢ����"*/
extern unsigned int press_card_state;          /*"����cpu�����״̬��־������"*/ 
extern unsigned char receive_send_buffer[]; /*"����\����CPU����ESAM�����ݵĻ���������Կ��AE=174"*/
extern unsigned char CommunicationPortMode;
extern unsigned char Far_Comm_Init_NO;

extern unsigned char Esam_Err_Count;
extern unsigned long Reamin_Money_ESAM_Dec_Time;


