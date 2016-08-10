///#include "ram.h"	

#include "defdata.h"
#include "Interrupt.h"

#include "ram.h"
//#include "sfr64a.h"
#include "MB_Showmain.h"
//#include "comm.h" 
#include "ICcard.h" 
#include "Card_Data.h"
#include "Card_File.h"

#include "pay_def.h"
#include "Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "comm.h"
#include "Far_pay.h"

//#include "pay_Mac.h"


/*"**************************************************************************"*/
/*" 延时_104us "*/                                                                                                           

void Delay_104us(unsigned int _104us)
    {
    static unsigned char Delay_64us_i2;

    while(_104us)
        {
        for(Delay_64us_i2=78;Delay_64us_i2>0;Delay_64us_i2--)
					;  /*"10MHz:80"*/
        _104us--;
        }
    }
/*"**************************************************************************"*/
/*" 延时_74.4us "*/                                                                                                           

void Delay_74us(unsigned int _74us)
    {
    static unsigned char Delay_64us_i2;

    while(_74us)
        {
        for(Delay_64us_i2=55;Delay_64us_i2>0;Delay_64us_i2--)
					;  /*"10MHz:80"*/
        _74us--;
        }
    }
/*"**************************************************************************"*/
/*" 判断卡是否在 "*/
unsigned char Check_CPU_Occur(void)
    {
    CPU_SW_DIRECT  = INPUT;
    Delay_104us(1);
    if( CommunicationPortMode != ESAM )
        {
        if( !CPU_SW )
            return ERR;
        else
            return OK;
        }
    else
        return OK;
    }
/*"**************************************************************************"*/
/*" CPU卡的上电VCC控制 "*/
void CPU_VCC_Control(unsigned char output)
    {
    CPU_VCC_DIRECT = OUTPUT;
    CPU_VCC_OUTPUT = output;
    Delay_104us(10);			
    }
/*"**************************************************************************"*/
/*" CPU卡的CLK控制 "*/
void CPU_CLK_Control(unsigned char output)
    {
    CPU_CLK_DIRECT = OUTPUT;
    CPU_CLK_OUTPUT = output;
    Delay_104us(1);
    }
/*"**************************************************************************"*/
/*" CPU卡的RST控制 "*/
void CPU_RST_Control(unsigned char output)
    {
    CPU_RST_DIRECT   = OUTPUT;
    CPU_RST_OUTPUT   = output;    	
    Delay_104us(1);		
    }
/*"**************************************************************************"*/
/*" ESAM卡的上电VCC控制 "*/
void ESAM_VCC_Control(unsigned char output)
    {
    ESAM_VCC_DIRECT = OUTPUT;
    ESAM_VCC_OUTPUT = output;    	
    Delay_104us(10);			
    }
/*"************************************************************************** "*/
/*" ESAM卡的CLK控制 "*/
void ESAM_CLK_Control(unsigned char output)
    {
    ta3s = output;
//    tabsr |=0x08;/*"启动定时器"*/
//    ESAM_CLK_DIRECT = OUTPUT;
//    ESAM_CLK_OUTPUT = output;    	
    Delay_104us(1);		
    }

/*"**************************************************************************"*/
/*" ESAM卡的RST控制 "*/
void ESAM_RST_Control(unsigned char output)
    {
    ESAM_RST_DIRECT = OUTPUT;
    ESAM_RST_OUTPUT = output;    	
    Delay_104us(1);
    }

/*"**************************************************************************"*/
/*" 串口切换控制控制 "*/
/*" 0：切换到CSAM卡部分 "*/
/*" 1：切换到CPU卡部分 "*/
/*" 2；切换到红外 "*/
/*" 3；切换到载波（保留） "*/
void CPU_ESAM_CARD_Control(unsigned char output)
    {
	CommunicationPortMode = output;
    }
/*"**************************************************************************"*/
/*"串口初始化"*/
void Cpucard_Serial_Init(void)
    {             
    unsigned int uni;
    unsigned char data;
	
//    u7brg=46;   /*"64,10MHz,13409.7bps"*/
//    u7c0=0x18;
//    s7tic=0;
//    s7ric=0;
//    u7mr=0x75;

	   uni=u6rb;
	   re_u6c1=1;
	   re_u6c1=0;
	   uni=u6rb;
	   re_u6c1=1;
	   re_u6c1=0;
	   u6c1=0;
	   data=u6rbl;
	   u6mr=0x70;
	   u6mr=0x75;
	   u6c0=0x18;
	   u6irs=1;
	   u6brg=64;/*"64,10MHz,9600bps"*/
	   te_u6c1=0;
	   re_u6c1=1;
    s6tic=0;
    s6ric=3;

	   uni=u7rb;
	   re_u7c1=1;
	   re_u7c1=0;
	   uni=u7rb;
	   re_u7c1=1;
	   re_u7c1=0;
	   u7c1=0;
	   data=u7rbl;
	   u7mr=0x70;
	   u7mr=0x75;
	   u7c0=0x18;
	   u7irs=1;
	   u7brg=46;/*"46,10MHz,13409.7bps"*/
	   te_u7c1=0;
	   re_u7c1=1;
    s7tic=0;
    s7ric=3;

	
    }
/*"**************************************************************************"*/
/*"串口释放"*/
void cpucard_serial_release(void)
    {
 //   Far_Comm_Init_NO = 0x5A;
 //   Init_Comm(1);
//	Far_Comm_Init_NO = 0;
	s6ric=0;
	s6tic=0;
	re_u6c1=0;
	te_u6c1=0;

	s7ric=0;
	s7tic=0;
	re_u7c1=0;
	te_u7c1=0;
	CPU_ESAM_CARD_Control(FAR_COMM);
    }
/*"**************************************************************************"*/
/*"使能serial  接收，禁止serial 发送"*/
void Enable_Serial_Receive(void)
    {
    unsigned char temp;

	if( CommunicationPortMode==ESAM )
		Delay_74us(11);
	else
		Delay_104us(11);
	    s7ric=0;
           s6ric=0;
	if( CommunicationPortMode==ESAM )
		Delay_74us(11);
	else
		Delay_104us(11);
    receive_data_length = 0;
	if( CommunicationPortMode==ESAM )
		{
		    temp=u7rb;
		  
		    te_u7c1=0;
		    re_u7c1=1;
		    s7ric=3;

		    temp=u6rb;
		  
		    te_u6c1=0;
		    re_u6c1=0;
			}
	else
		{
		    temp=u6rb;
		  
		    te_u6c1=0;
		    re_u6c1=1;
		    s6ric=3;
		    temp=u7rb;
		  
		    te_u7c1=0;
		    re_u7c1=0;


		}
    }
/*"**************************************************************************"*/
/*"串口发送1个字节"*/
void Send_1Byte(unsigned char data)
    {
	    if( CommunicationPortMode==ESAM )
	    	{
		    while(1)
		        if(ti_u7c1==1)
		            break;
		    u7tbl=data;                 /*" TXBUF0=data;"*/
	    	}
	else
		{
		    while(1)
		        if(ti_u6c1==1)
		            break;
		    u6tbl=data;                 /*" TXBUF0=data;"*/

		}
   }
/*"**************************************************************************"*/
/*" 使能serial  发送，禁止serial  接收 "*/
void Enable_Serial_Send(void)
    {
    Delay_104us(1);
	if( CommunicationPortMode==ESAM )
		{
		    s7ric=0;
		    te_u7c1=1;
		    re_u7c1=0; 
			
		    s6ric=0;
		    te_u6c1=0;
		    re_u6c1=0; 
		}
	else
		{
		    s7ric=0;
		    te_u7c1=0;
		    re_u7c1=0; 
			
		    s6ric=0;
		    te_u6c1=1;
		    re_u6c1=0; 

		}
    }

/*"**************************************************************************"*/
/*"CPUCard 串口中断程序 接收"*/
void Receive_Data_To_Cpucard(void)
    {
    union data
        {
        unsigned char c[2];
        unsigned int  i;
        }d={0,0};
    if(ir_s7ric) 
        {
        ir_s7ric=0; 
        return;
        }
    s7ric=0;

    d.i=u7rb;
    if(!(d.c[1]&0x80))
        {
        if(receive_data_length>CARD_BUFFER_LENGTH)
            receive_data_length=0;           //88
        receive_send_buffer[receive_data_length]=d.c[0];    

        receive_data_length++;
        }
    else
        {
        u7mr=0x70;
        u7mr=0x75;
        }
    s7ric=3;
    }
/*"**************************************************************************"*/
/*"CPUCard 串口中断程序 接收"*/
void Receive_Data_To_Cpucard_CPU(void)
    {
    union data
        {
        unsigned char c[2];
        unsigned int  i;
        }d={0,0};
    if(ir_s6ric) 
        {
        ir_s6ric=0; 
        return;
        }
    s6ric=0;

    d.i=u6rb;
    if(!(d.c[1]&0x80))
        {
        if(receive_data_length>CARD_BUFFER_LENGTH)
            receive_data_length=0;           //88
        receive_send_buffer[receive_data_length]=d.c[0];    

        receive_data_length++;
        }
    else
        {
        u6mr=0x70;
        u6mr=0x75;
        }
    s6ric=3;
    }
/*"**************************************************************************"*/
/*" CPU卡下电 "*/
void Cpu_PowOff(void)
    {
    CPU_RST_Control(1);
    CPU_CLK_Control(1);
    CPU_VCC_Control(1);
    }
/*"**************************************************************************"*/
/*" CPU卡冷复位 "*/
void Cpu_Reset_Cool(void)
    {
    CPU_RST_Control(1);
    CPU_CLK_Control(1);
    CPU_VCC_Control(0);
    Delay_104us(100);
    CPU_CLK_Control(0);
    CPU_RST_Control(0);
    }

/*"**************************************************************************"*/
/*" ESAM卡下电 "*/
void Esam_PowOff(void)
    {
    ESAM_RST_Control(0);
    ESAM_CLK_Control(0);
    ESAM_VCC_Control(0);
    }
/*"**************************************************************************"*/
/*" ESAM卡冷复位 "*/
void Esam_Reset_Cool(void)
    {
    ESAM_RST_Control(0);
    ESAM_CLK_Control(0);
    ESAM_VCC_Control(1);
    Delay_104us(100);
    ESAM_CLK_Control(1);
    ESAM_RST_Control(1);
    }

/*"**************************************************************************"*/
/*" 上电IO口初始化 "*/
void Pay_IO_Init(void)
    {
    	if (MACRO_LOCAL_PAY_FLAG)
    		{
		CPU_SW_DIRECT= INPUT;
    		}
	else
		{
		CPU_SW_DIRECT= OUTPUT;
		CPU_SW=0;
		}

	CPU_VCC_DIRECT	= OUTPUT;
	CPU_CLK_DIRECT 	= OUTPUT;
	CPU_RST_DIRECT 	= OUTPUT;
	CPU_VCC_OUTPUT	=0;
	CPU_CLK_OUTPUT	=0;
	CPU_RST_OUTPUT	=0;

	ESAM_VCC_DIRECT= OUTPUT;
//	ESAM_CLK_DIRECT = OUTPUT;
	ESAM_RST_DIRECT = OUTPUT;
	ESAM_VCC_OUTPUT=0;
//	ESAM_CLK_OUTPUT =0;
	ESAM_RST_OUTPUT =0;


	RELAY_CHECK_DIRECT=INPUT;

	CPU_ESAM_CARD_Control(FAR_COMM);
    }
/*"**************************************************************************"*/
/*" 掉电CPU卡相关电路初始化处理 "*/
void Cpu_Card_IO_Powerdown(void)
{
	if ((!MACRO_LOCAL_PAY_FLAG) && (!MACRO_FAY_CONTROL_FLAG))
		return;

	cpucard_serial_release();

	CPU_SW_DIRECT       		= INPUT;
	CPU_RST_OUTPUT=0;
	CPU_CLK_OUTPUT=0;
	CPU_VCC_OUTPUT=0; 
	CPU_VCC_DIRECT     	 	= INPUT;
	CPU_CLK_DIRECT        		= INPUT;
	CPU_RST_DIRECT            	= INPUT;
	ESAM_RST_OUTPUT=0;
	ta3s=0;	//ESAM_CLK
	ESAM_VCC_OUTPUT=0;
	ESAM_VCC_DIRECT     		= INPUT;
	//ESAM_CLK_DIRECT      	= INPUT;
	ESAM_RST_DIRECT            	= INPUT;
    }
/*"**************************************************************************"*/
/*" CPU卡部分电路初始化,包括UART "*/
void Cpu_Card_IO_Init(void)
    {
    Pay_IO_Init();
    Cpu_PowOff();
    Esam_PowOff();
    }

/*"**************************************************************************"*/
/*" CPU卡部分电路释放,包括UART "*/
void Cpu_Card_IO_Reset(void)
    {
    Cpu_PowOff();
    Esam_PowOff();
    cpucard_serial_release();
    }
/*"**************************************************************************"*/
/*" 接收等待（字节数） "*/
unsigned char Wait_Receive(unsigned char length)
    {  
    unsigned int i;
    unsigned char temp;
    unsigned long j;
    unsigned char receive_data_length_Follow;
    j=0;
	receive_data_length_Follow = receive_data_length;
    for( ;receive_data_length<length; )
        {
        FeedWatchdog();
        j++;
	if( receive_data_length_Follow != receive_data_length )
		{
		receive_data_length_Follow = receive_data_length;
		j=0;
		}
        if( j>17812l )
            {
            press_card_state = CPU_CARD_COMM_DELAY_ERR;
            return ERR;
            }
        }
    return OK;
    }
/*"**************************************************************************"*/
/*" 判断返回标志的合法性 "*/    
unsigned char Judge_Return_Flag(void)
    {
    if( R_CARD_ERROR_INFO != GOOD_DEFINE )
        {
        return ERR;
        }
    if(Check_CPU_Occur())			
        {
	R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
        return ERR;
        }
    return OK;
    }
/*******************************************************************************/	
void My_Memcpy(unsigned char *to,unsigned char *from,unsigned char len)
    {	
    unsigned char count;	
 
    for(count=0;count<len;count++)
    	{
       if(from==0 )
    	     *(to+count)=0;  
		else
            *(to+count)=*(from+count);
    	}
    }

/*"比较2个时间的前后"*/	
unsigned char My_Memcmp(unsigned char *to,unsigned char *from,unsigned char lc)
    {	
    unsigned char count,flag;
	unsigned char Com_Flag;
 
    flag=0;

    for(count=0;count<lc;count++)
        {
        if( from==0 )
			Com_Flag = 0;			
		else
			Com_Flag =  *(from+count);
		
        if( *(to+count) > Com_Flag )
            {
            flag=1;
            break;
            }
        else if( *(to+count) < Com_Flag )
            {
            flag=2;
            break;
            }
        } 
    return(flag); 
    }

/*"**************************************************************************"*/
/*" 接收、判断CPU卡复位应答信号 "*/
unsigned char Cpucard_Atr(void)
	{
	unsigned char Length;

	CPU_ESAM_CARD_Control(CPU);
	if(Check_CPU_Occur())			
		{
		R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
		return ERR;
		}
    
	Enable_Serial_Send();
	Enable_Serial_Receive();
	Cpu_Reset_Cool();

	if( Wait_Receive(2) )
		{
		R_CARD_ERROR_INFO=ICCARD_RESET_DEFINE;
		return ERR;
		}
	Length  = receive_send_buffer[1];
	Length &=0x0F;
	Length +=4;
	if( Wait_Receive(Length) )
		{
		R_CARD_ERROR_INFO=ICCARD_RESET_DEFINE;
		return ERR;
		}

	if((receive_send_buffer[0]!=0x3b)||
	(receive_send_buffer[2]!=0)||(receive_send_buffer[3]!=0))
		{
		R_CARD_ERROR_INFO=ICCARD_RESET_DEFINE;			//Li Update 20121220			/*"Li_错误信息字(卡片复位错误)"*/
		return ERR;  
		}  
	FeedWatchdog();
	memcpy(cpucard_number,receive_send_buffer+Length-8,8);
	return OK;  
	}
/*"**************************************************************************"*/
/*"接收、判断SAM卡复位应答信号"*/                                                                  
unsigned char Esamcard_Atr(void)
	{
	unsigned char Length;
	
	CPU_ESAM_CARD_Control(ESAM);
    
	Enable_Serial_Send();
	Enable_Serial_Receive();
	Esam_Reset_Cool();

	if( Wait_Receive(2) )
		{
		R_CARD_ERROR_INFO=ESAM_RESET_DEFINE;
		return ERR;
		}
	Length  = receive_send_buffer[1];
	Length &=0x0F;
	Length +=4;
	if( Wait_Receive(Length) )
		{
		R_CARD_ERROR_INFO=ESAM_RESET_DEFINE;
		return ERR;
		}

	if((receive_send_buffer[0]!=0x3b)||
	(receive_send_buffer[2]!=0)||(receive_send_buffer[3]!=0))
		{
		R_CARD_ERROR_INFO=ESAM_RESET_DEFINE;				//Li Update 20121220			/*"Li_错误信息字(ESAM 复位错误)"*/
		return ERR;  
		}  
	FeedWatchdog();
	return OK;  
	ESAM_ERR_DEFINE=0;	/*"只要远程认证或者本地插卡成功，则立即清除ESAM错误"*/
	}

/*"**************************************************************************"*/
/*"内部认证，CPU卡0x0088,ESAM卡0x80fa;p1:为0时加密,为1时解密；p2:密钥标识号"*/                 
/*"address为需要加密的数据首地址"*/                                                                                
unsigned char Internal_Auth(unsigned char cla,unsigned char ins,unsigned char t_p1,
              unsigned char t_p2,unsigned char lc,unsigned char *address)
    {
	unsigned char Order_Head[4];

	Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,lc,address,0,CommunicationPortMode,0)== OK )
		return OK;
	if (press_card_state!=CPU_CARD_COMM_DELAY_ERR)
		R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
    return ERR;
    }

/*"**************************************************************************"*/
/*"外部认证，p2:密钥标识号, address为需要解密的数据首地址"*/
unsigned char External_Auth(unsigned char t_p2,unsigned char lc,unsigned char *address)
    {
	unsigned char Order_Head[4];

	Order_Head[0] = 0x00;
	Order_Head[1] = 0x82;
	Order_Head[2] = 0x00;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,lc,address,0,CommunicationPortMode,0)== OK )
		return OK;

	if (press_card_state!=CPU_CARD_COMM_DELAY_ERR)
		R_CARD_ERROR_INFO=EXID_ERROR_DEFINE;
    return ERR;
    }
//**************************************************************************
/*"cpu卡：文件选择 :3f01 "*/
unsigned char Select_File(unsigned char t_p1,unsigned char date1,unsigned char date2)
    {
		unsigned char Order_Head[4];
		unsigned char W_Data[2];
		
		Order_Head[0] = 0;
		Order_Head[1] = 0xa4;
		Order_Head[2] = 0;
		Order_Head[3] = 0;
		W_Data[0] = date1;
		W_Data[1] = date2;
		if( CPU_Card_Driver((const unsigned char *)Order_Head,2,W_Data,0,CommunicationPortMode,0)== OK )
			return OK;

	return ERR;
    }
/*"**************************************************************************"*/
/*"读二进制文件，ins=0xb0,         读出记录文件，ins=0xb2"*/                                                          
/*"取随机数，ins=0x84,?            取响应数据，ins=0xc0"*/             
unsigned char Read(unsigned char cla,unsigned char ins,unsigned char t_p1,
                   unsigned char t_p2,unsigned char len)
    {     
	unsigned char Order_Head[4];

	Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;

	if( CPU_Card_Driver((const unsigned char *)Order_Head,0,0,len,CommunicationPortMode,0)== OK )
		return OK;

    return ERR; 	
    }
    
/*"**************************************************************************"*/
/*"修改二进制文件，ins=0xd6   追加记录文件,ins=0xe2    修改记录 ,ins=0xdc "*/
/*"增加或修改密钥:ins=0xd4    存款：ins=0x32         扣款：ins=0x30  "*/
unsigned char Write(unsigned char cla,unsigned char ins,unsigned char t_p1,
                    unsigned char t_p2,unsigned char lc,unsigned char *address)
    {

	unsigned char Order_Head[4];

	Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,lc,address,0,CommunicationPortMode,0)== OK )
		return OK;

	return ERR; 	
	}    
/*"**************************************************************************"*/
unsigned char Cpucard_Esamcard_Internal_Auth(unsigned char cardType)   /*"内部认证"*/
{
    if(Check_CPU_Occur())			
        {
	R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
        return ERR;
        }

	//------------------------------------------------------------------------//
	if ((cardType==GWFAR_USER_CARD)||(cardType==GWFAR_INIT_CARD) ||(!O1ther_Meter_Parameter.WorkRoomState))
	{
		CPU_ESAM_CARD_Control(ESAM);
		if( Read(0,Read_Binary,0x99,0x01,0x08) != OK )
	    {
	        return ERR;
	    }
		memcpy(ESAM_number,receive_send_buffer,8);

		if( Read(0,Get_Challenge,0,0,8) != OK )
	    {
			return ERR;
	    }
		My_Memcpy(receive_send_buffer+100,receive_send_buffer,8);	// EsamRand8

		if (Internal_Auth(0x80,0xfa,0,1,8,cpucard_number)!=OK)
		    return ERR;

		if (Internal_Auth(0x80,0xfa,0,0,8,receive_send_buffer+100)!=OK)
		    return ERR;
		My_Memcpy(receive_send_buffer+110,receive_send_buffer,8);	// K1
		
	//CPU	
		CPU_ESAM_CARD_Control(CPU);
		if( Internal_Auth(0,0x88,0,1,8,receive_send_buffer+100) != OK )
			return ERR;
	    
		if(My_Memcmp(receive_send_buffer+110,receive_send_buffer,8))  
	    {
		R_CARD_ERROR_INFO=IDCARD_ERROR_DEFINE;
	        return ERR;      
	    }  
	}

    return OK;  	/*"内部认证结束"*/  
}

/*"**************************************************************************"*/
unsigned char Cpucard_External_Auth(void)
    {

    if(Check_CPU_Occur())			
        {
	R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
        return ERR;
        }
    CPU_ESAM_CARD_Control(CPU);    /*"串口通向CPU卡。 "*/  
    
    Read(0,Get_Challenge,0,0,8);  /*"取CPU卡随即数 "*/ 
    if( Judge_Return_Flag() )
	    return ERR;

    My_Memcpy(receive_send_buffer+150,receive_send_buffer,8);  /*"转移随机数 "*/  
    CPU_ESAM_CARD_Control(ESAM);   /*"串口通向ESAM卡"*/

    if (Internal_Auth(0x80,0xfa,0,2,8,cpucard_number)!=OK)      /*"加密ESAM随机数"*/
	    return ERR;

    if (Internal_Auth(0x80,0xfa,0,0,8,receive_send_buffer+150)!=OK)
	    return ERR;

    CPU_ESAM_CARD_Control(CPU);    /*"串口通向CPU卡"*/
    My_Memcpy(receive_send_buffer+100,receive_send_buffer,8);     /*"转移随机数"*/      

    if( External_Auth(2,8,receive_send_buffer+100) != OK )
    {
		return ERR;
    }

    return OK;  /*"CPU卡外部认证结束"*/                                  
    }

/*"**************************************************************************"*/
/*" 功能：CPU卡底层读写函数 "*/
/*" 文件名：CPU_Card_Driver "*/
/*" Order_Head：命令头域 "*/
/*" 包括：CLA  INS  P1  P2  "*/
/*" Length_LC：写数据长度   "*/
/*" W_Data：写数据 "*/
/*" Length_LE: 读数据长度 "*/
/*" Change_Door: 读写通道 ESAM还是CPU "*/
/*" Spec_Length_LE: 特殊的后续数据帧长度,0:表示无特殊长度，直接取61 XX,"*/
/*" 非0表示为特殊后续数据帧，不取61 XX "*/
unsigned char CPU_Card_Driver(const unsigned char *Order_Head,
										 unsigned char Length_LC,
			                             unsigned char *W_Data,
			                             unsigned char Length_LE,
			                             unsigned char Change_Door,
			                             unsigned char Spec_Length_LE)
	{
	unsigned char i,cmdLen;//,Order_Head_Byte[4];
    
	CPU_ESAM_CARD_Control(Change_Door);
	if(Check_CPU_Occur())			
		{
		R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
		return ERR;
		}
	Enable_Serial_Send();
	for( i=0;i<4;i++ )
		{
//		Order_Head_Byte[i] = *(Order_Head+i);
		Send_1Byte(*(Order_Head+i)); 
		}
		
	if( Length_LC !=0 )
	{
		Send_1Byte(Length_LC);
		cmdLen=Length_LC;
	}
	else if( Length_LE !=0 )
	{
		Send_1Byte(Length_LE);
		cmdLen=Length_LE;
	}
	else
	{
		Send_1Byte(0);
		cmdLen=0;
	}
	
	Enable_Serial_Receive();
	FeedWatchdog();
	if( Wait_Receive(1) )
		{
		for( i=0;i<4;i++ )
			OPCard_Error_format.CMD[i]=Order_Head[i];
		OPCard_Error_format.CMD[4]=cmdLen;
		if (Change_Door==ESAM)
			R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
		else
			R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
		return ERR;
		}
//	if(receive_send_buffer[0]!=Order_Head_Byte[1])
	if(receive_send_buffer[0]!=*(Order_Head+1))
		{
		for( i=0;i<4;i++ )
			OPCard_Error_format.CMD[i]=Order_Head[i];
		OPCard_Error_format.CMD[4]=cmdLen;
		if (Change_Door==ESAM)
			R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
		else
			R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;		
		return ERR;
		}

	receive_data_length = 0;
	if( Length_LC !=0 )
		{
		Enable_Serial_Send();
		for( i=0;i<Length_LC;i++ )
			Send_1Byte(*(W_Data+i));
		Enable_Serial_Receive();
		}

	if( Wait_Receive(2+Length_LE) )
		{
        	for( i=0;i<4;i++ )
			OPCard_Error_format.CMD[i]=Order_Head[i];
		OPCard_Error_format.CMD[4]=cmdLen;
		if (Change_Door==ESAM)
			R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
		else
			R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
		return ERR;
		}
	if(receive_send_buffer[0+Length_LE]==0x61)
		{
		if( *(Order_Head+1)!= Get_Response )
			{
	        	if(Spec_Length_LE!=0 )
				i = Spec_Length_LE;
			else
				i = receive_send_buffer[1+Length_LE];
	        	if(Read(0,Get_Response,0,0,i )==OK ) 
	       	    	return OK;
		        else
		        {
		        	for( i=0;i<4;i++ )
					OPCard_Error_format.CMD[i]=Order_Head[i];
				OPCard_Error_format.CMD[4]=cmdLen;
				OPCard_Error_format.Response[0]=receive_send_buffer[0+Length_LE];	//Li Update20121231
				OPCard_Error_format.Response[1]=receive_send_buffer[1+Length_LE];
				if (Change_Door==ESAM)
					R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
				else
					R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;		
                record_esam_oprate_err();
				return ERR;
		        }
			}
		else
			return OK;
		}
	else if((receive_send_buffer[0+Length_LE]==0x90)&&(receive_send_buffer[1+Length_LE]==0))
		return OK; 

	if (Change_Door==ESAM)
		R_CARD_ERROR_INFO=ESAM_ERROR_DEFINE;
	else
		R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;	
	if (Change_Door==CPU)
		{
		if ((receive_send_buffer[0+Length_LE]==0x6B)&&(receive_send_buffer[1+Length_LE]==0))
			{
			R_CARD_ERROR_INFO=UNISSUED_ERROR_DEFINE;
			}
		}
	/*"测试软件要求返回6988时报MAC校验错误"*/
	if ((receive_send_buffer[0+Length_LE]==0x69)&&(receive_send_buffer[1+Length_LE]==0x88))
		R_CARD_ERROR_INFO=MAC_ERROR_DEFINE;

	for( i=0;i<4;i++ )
		OPCard_Error_format.CMD[i]=Order_Head[i];
	OPCard_Error_format.CMD[4]=cmdLen;	
	OPCard_Error_format.Response[0]=receive_send_buffer[0+Length_LE];	//Li Update20121231
	OPCard_Error_format.Response[1]=receive_send_buffer[1+Length_LE];	
    record_esam_oprate_err();
	return ERR;
	}
#if 0
/*"**************************************************************************"*/
/*" 功能：钱包文件剩余电费读出给CPU卡 "*/
unsigned char Remain_Money_Moneybag_To_Cpu_Step(unsigned char Rec_Addr,unsigned char Rec_Offset)
	{
	unsigned char count,temp_buffer_2[30],Order_Head[4];

	
	CPU_ESAM_CARD_Control(CPU);
	if(Read(0,Get_Challenge,0,0,4)!=OK)
		return ERR;

	temp_buffer_2[0]=receive_send_buffer[0];   
	temp_buffer_2[1]=receive_send_buffer[1];
	temp_buffer_2[2]=receive_send_buffer[2];
	temp_buffer_2[3]=receive_send_buffer[3];
	temp_buffer_2[4]=0x04;
	temp_buffer_2[5]=0xD6;
	temp_buffer_2[6]=0x82;
	temp_buffer_2[7]=Rec_Offset;
	temp_buffer_2[8]=0x08;/*" 6字节为0x0A,4字节为0x08 "*/

	My_Memcpy(temp_buffer_2+9,cpucard_number,8);
	CPU_ESAM_CARD_Control(ESAM);

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xB2;
	Order_Head[2] = Rec_Addr;
	Order_Head[3] = 0x0C;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x11,temp_buffer_2,0,CommunicationPortMode,0x08)!= OK )/*" 6字节为0x0A,4字节为0x08 "*/
		return ERR;

	CPU_ESAM_CARD_Control(CPU);
	My_Memcpy(temp_buffer_2,receive_send_buffer,0x08);/*" 6字节为0x0A,4字节为0x08 "*/

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xD6;
	Order_Head[2] = 0x82;
	Order_Head[3] = Rec_Offset;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x08,temp_buffer_2,0,CommunicationPortMode,0)!= OK )/*" 6字节为0x0A,4字节为0x08 "*/

		return ERR;

    return OK;
	}
#endif
/*"**************************************************************************"*/
/*" 功能：钱包文件剩余电费或购电次数初始化 "*/
/*" Length_LE: 读数据长度 "*/
unsigned char Remain_Money_Moneybag_Step(unsigned char Rec_Addr,unsigned char Rec_Offset)
	{
	unsigned char temp_buffer_2[30],Order_Head[4];
	
	CPU_ESAM_CARD_Control(ESAM);					/*"Li_ESAM"*/
	if(Read(0,Get_Challenge,0,0,4)!=OK)				/*"Li_"*/
	{
	   return ERR;
	}
	temp_buffer_2[0]=receive_send_buffer[0];   
	temp_buffer_2[1]=receive_send_buffer[1];
	temp_buffer_2[2]=receive_send_buffer[2];
	temp_buffer_2[3]=receive_send_buffer[3];
	temp_buffer_2[4]=0x04;
	temp_buffer_2[5]=0xDC;							
	temp_buffer_2[6]=Rec_Addr;						// 3.0x01     4.0x03		//Li Update 20130221
	temp_buffer_2[7]=0x0C;
//	temp_buffer_2[8]=0x10;
	temp_buffer_2[8]=0x08;							/*"Li_这位表示长度即LC"*/
	CPU_ESAM_CARD_Control(CPU);					/*"Li_CPU"*/

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xB0;
	Order_Head[2] = 0x85;							//0x82;		//Li Update 20130220
	Order_Head[3] = Rec_Offset;					// 1.0x00    2.0x04
	if( CPU_Card_Driver((const unsigned char *)Order_Head,9,temp_buffer_2,0,CommunicationPortMode,0x08)!= OK )
	{				/*"Li_明文+MAC方式读取参数预置卡钱包文件的4字节购电金额"*/  //Li Update 20130221
	   return ERR;
	}
				
//	My_Memcpy(temp_buffer_2,cpucard_number,8);
//	My_Memcpy(temp_buffer_2+8,receive_send_buffer,0x08);
	My_Memcpy(temp_buffer_2,receive_send_buffer,0x08);

	if (Rec_Addr==0x03)	/*"比较购电次数"*/
		{
		if (My_Memcmp(temp_buffer_2, 0, 4))
			{
			R_CARD_ERROR_INFO=BUYNUM_ERROR_DEFINE;
			return ERR;
			}
		}

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xDC;						
	Order_Head[2] = Rec_Addr;					// 3.0x01     4.0x03
	Order_Head[3] = 0x0C;
	if(Check_CPU_Occur())			
		{
		R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
		return ERR;
		}
	CPU_ESAM_CARD_Control(ESAM);
		
//	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x10,temp_buffer_2,0,CommunicationPortMode,0)!= OK )
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x08,temp_buffer_2,0,CommunicationPortMode,0)!= OK )
	{				/*"Li_明文+MAC方式写入ESAM初始化钱包预置金额"*/  //Li Update 20130221
	   return ERR;
	}
	return OK;
	}
/*"**************************************************************************"*/
/*" 功能：钱包文件初始化 "*/
/*" Length_LE: 读数据长度 "*/
unsigned char Remain_Money_Moneybag_Init(void)
	{
	if( Remain_Money_Moneybag_Step(3,4) != OK )
		return ERR;
	
	if( Remain_Money_Moneybag_Step(1,0) !=OK )
		return ERR;

    return OK;
	}
#if 0
/*"**************************************************************************"*/
/*" 功能：剩余电费钱包文件读到ESAM数据回抄卡 "*/
unsigned char Remain_Money_Moneybag_To_Cpu(void)
	{
	if( Remain_Money_Moneybag_To_Cpu_Step(1,0) !=OK )
		return ERR;
	if( Remain_Money_Moneybag_To_Cpu_Step(3,4) != OK )
		return ERR;
	return OK;
	}
#endif
/*"**************************************************************************"*/
/*" 功能：读ESAM钱包文件剩余电费和购电次数 "*/
unsigned char Read_Esam_Moneybag_File(unsigned char * Moneybag_Data_Point)
	{	
  
	CPU_ESAM_CARD_Control(ESAM);
	if(Read(0,0xb2,0x01,0x0C,0x04)!=OK) 
	{
		return ERR; 
	}
	My_memcpyRev(Moneybag_Data_Point,receive_send_buffer,4);
	if(Read(0,0xb2,0x03,0x0c,0x04)!=OK)
    {
		return ERR; 
	}
	My_memcpyRev(Moneybag_Data_Point+4,receive_send_buffer,4);
	return OK;  
	}
/*"**************************************************************************"*/
/*" 功能：ESAM剩余电费扣除 "*/
/*" 电费扣减时用 "*/
unsigned char Esam_Remain_Money_Dec(void)
	{
	unsigned char Order_Head[4];
	struct Moneybag_Data Moneybag_Data;

  	Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data);

	if( Pre_Power_Down_Save_Data.Remain_Money>0 )
		{
		if( Pre_Power_Down_Save_Data.Remain_Money<=Moneybag_Data.Remain_Money )
			Moneybag_Data.Remain_Money -= Pre_Power_Down_Save_Data.Remain_Money;
		else
			Moneybag_Data.Remain_Money = 0;
			
		}
	if(Moneybag_Data.Remain_Money>0)
		{
		Reverse_data((unsigned char *)&Moneybag_Data.Remain_Money,4);
		Order_Head[0] = 0x80;
		Order_Head[1] = 0x30;
		Order_Head[2] = 0x00;
		Order_Head[3] = 0x0C;
		if( CPU_Card_Driver((const unsigned char *)&Order_Head[0],4,(unsigned char *)&Moneybag_Data.Remain_Money,0,CommunicationPortMode,0)!= OK )
			return ERR;
		}
	return OK;
	}
/*"**************************************************************************"*/
/*" 功能：ESAM钱包文件剩余电费扣除函数 (捎带完成ESAM自检报错) "*/
/*" 电量走字的时候用 "*/
/*" Flag=0走字的时候调用，Flag＝1上电或掉电的时候调用 "*/
//unsigned long Reamin_Money_ESAM;

void Esam_Remain_Money_Do(unsigned char Flag)
{
	unsigned long Esam_Money_Temp;
	unsigned char Esam_Do_Flag;
	unsigned char Esam_Err_Flag;


	//ESAM_ERR_DEFINE = 0;
	
	//Li Upadate 20121215    if ((!MACRO_FAY_CONTROL_FLAG) && (!MACRO_LOCAL_PAY_FLAG))	
	//Li Upadate 20121215   	return;												/*"Li_远程阀控功能:无，预付费功能:无"*/

	if (IntoPowerDownFlag)
		return;
	if( Far_Identity_Auth_Ok_Flag == 0xFF )
		return;
	Esam_Do_Flag = 0;
	if( Flag )
	{
		//	Esam_Money_Temp = 100L;
		Esam_Do_Flag = 0xFF;
		Reamin_Money_ESAM_Dec_Time=GetNowTime();
	}
	else
	{
		//Li Upadate 20121215   if(GetTimeCount(Reamin_Money_ESAM_Dec_Time,900000l)==0)
		if(GetTimeCount(Reamin_Money_ESAM_Dec_Time,1800000l)==0)			/*"Li_每30分钟判断一次"*/
		//	if(GetTimeCount(Reamin_Money_ESAM_Dec_Time,60000l)==0)
		{
			Esam_Do_Flag = 0xFF;
			Reamin_Money_ESAM_Dec_Time=GetNowTime();
		}
	}
	
	//		Esam_Money_Temp = Reamin_Money_ESAM;
	//		if( Esam_Money_Temp>=Pre_Power_Down_Save_Data.Remain_Money )
	//			{
	//			if( Esam_Money_Temp!=0 && Pre_Power_Down_Save_Data.Remain_Money==0 )
	//				Esam_Money_Temp=100L;
	//			else
	//				Esam_Money_Temp-=Pre_Power_Down_Save_Data.Remain_Money;
	//			}
	//		else
	//			Esam_Money_Temp=100L;
	//		}
	
	
	if( Esam_Do_Flag == 0xFF )
	{
		REMAIN_BAG_DOING_DEFINE = 0;
		//	ESAM_ERR_DEFINE = 0;
		Esam_Err_Flag = 0;
		CPU_ESAM_CARD_Control(ESAM);
		Cpucard_Serial_Init();

		if( Esamcard_Atr() != OK )						/*"Li_判断ESAM模块"*/
			Esam_Err_Flag = 1;
		else
		{
			memcpy(Pre_Payment_Data.Esam_Identity,receive_send_buffer,5);	/*"ESAM复位信息:xxxxxxxxxx+8字节ESAM序列号"*/
			/*"南瑞:3B69000043;融通:3B69000041;新国网ESAM:3B69000041"*/
	    		if(MACRO_LOCAL_PAY_FLAG)    /*" 预付费功能打开 "*/
	    		{
					if( Esam_Remain_Money_Dec() != OK)
						Esam_Err_Flag = 1;
	    		}
			//	Reamin_Money_ESAM = Pre_Power_Down_Save_Data.Remain_Money;
		}
		if( Esam_Err_Flag )
			Esam_Err_Count++;
		else
			Esam_Err_Count = 0;


		
		//Li Update 20121215   if( Esam_Err_Count>=4 || (Esam_Err_Flag && Flag) )	
		if( ( (Esam_Err_Count>=2)&& MACRO_LOCAL_PAY_FLAG)  || (Esam_Err_Flag && Flag) )
		{
			ESAM_ERR_DEFINE = 1;
			Esam_Err_Count = 4;
		}
		else
			ESAM_ERR_DEFINE = 0;
		
		Cpu_Card_IO_Reset();
	}
}
/*"**************************************************************************"*/
/*" 功能：钱包文件剩余电费累加 "*/
/*" 新卡和购电卡用 "*/
unsigned char Remain_Money_Moneybag_Add(unsigned char File_Name,unsigned char Offset,
												unsigned char * Remain_Money_Point)
	{
	unsigned char count,temp_buffer_2[30],Order_Head[4];

	
	CPU_ESAM_CARD_Control(ESAM);
	if(Read(0,Get_Challenge,0,0,4)!=OK)
	{
		return ERR;
	}
	temp_buffer_2[0]=receive_send_buffer[0];   
	temp_buffer_2[1]=receive_send_buffer[1];
	temp_buffer_2[2]=receive_send_buffer[2];
	temp_buffer_2[3]=receive_send_buffer[3];
	temp_buffer_2[4]=0x84;
	temp_buffer_2[5]=0x32;
	temp_buffer_2[6]=0x01;
	temp_buffer_2[7]=0x0C;
//	temp_buffer_2[8]=0x14;
	temp_buffer_2[8]=0x0C;
	CPU_ESAM_CARD_Control(CPU);

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xB0;
	Order_Head[2] = 0x80+File_Name;
	Order_Head[3] = Offset;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,9,temp_buffer_2,0,CommunicationPortMode,0x0C)!= OK )
	{
		return ERR;
	}
	if( Remain_Money_Point != 0 )
		{
		My_memcpyRev(Remain_Money_Point,receive_send_buffer,4);
		My_memcpyRev(Remain_Money_Point+4,receive_send_buffer+4,4);
		}
	else
		{
		My_Memcpy(temp_buffer_2,receive_send_buffer,0x0C);
		Order_Head[0] = 0x84;
		Order_Head[1] = 0x32;
		Order_Head[2] = 0x01;
		Order_Head[3] = 0x0C;
		if(Check_CPU_Occur())			
			{
			R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
			return ERR;
			}
		CPU_ESAM_CARD_Control(ESAM);
		if( CPU_Card_Driver((const unsigned char *)Order_Head,0x0C,temp_buffer_2,0,CommunicationPortMode,0)!= OK )/*" 6字节为0x18,4字节为0x14 "*/
		{
			return ERR;
		}
	}
    return OK;
	}
/*"**************************************************************************"*/
/*" 功能：得到Esam或CPU文件中信息 "*/
/*" 数据拜访顺序为高位在低字节 "*/
unsigned char Get_File_Data(unsigned char Door,unsigned char File,unsigned char Offset,
							unsigned char Length,unsigned char * Point)
	{
	CPU_ESAM_CARD_Control(Door);
	if( Read(0,Read_Binary,0x80+File,Offset,Length) != OK )
		return ERR;
	if( Door==ESAM )
		My_Memcpy(Point,receive_send_buffer,Length);
	else
		My_memcpyRev(Point,receive_send_buffer,Length);
	return OK;
	}
/*"**************************************************************************"*/
/*" 功能：Esam其他文件更新 "*/
/*" Cpu_File_Name: "*/
/*" Esam_File_Name: "*/
/*" Cpu_Start_Addr: "*/
/*" Esam_Start_Addr: "*/
/*" Updata_Data_L: "*/
unsigned char Esam_File_Updata(unsigned char Cpu_File_Name,
									unsigned char Esam_File_Name,
							   		unsigned char Cpu_Start_Addr,
							   		unsigned char Esam_Start_Addr,
							   		unsigned char Updata_Data_L,
							   		unsigned char * Data_Output_Point)
	{
	unsigned char count,ret,temp_buffer_2[30],Order_Head[4];
	unsigned char Head_Length;

	
	CPU_ESAM_CARD_Control(ESAM);
	if(Read(0,Get_Challenge,0,0,4)!=OK)		/*"Li_取用户卡随机数用于返写MAC计算"*/
	{
		return ERR;
	}
	temp_buffer_2[0]=receive_send_buffer[0];   
	temp_buffer_2[1]=receive_send_buffer[1];
	temp_buffer_2[2]=receive_send_buffer[2];
	temp_buffer_2[3]=receive_send_buffer[3];
	temp_buffer_2[4]=0x04;
	temp_buffer_2[5]=0xD6;
	temp_buffer_2[6]=0x80+Esam_File_Name;
	temp_buffer_2[7]=Esam_Start_Addr;
//	temp_buffer_2[8]=Updata_Data_L+12;
	temp_buffer_2[8]=Updata_Data_L+4;
	if( Meter_Ins_Flag == 0xFF )
		{
		Head_Length = 0x11;
		temp_buffer_2[9] = 0x00;
		temp_buffer_2[10] = 0x00;
		My_Memcpy(&temp_buffer_2[11],&Meter_Parameter.parameter2.BcdMeterID[0],6);
		}
	else
		Head_Length = 0x09;
	
	CPU_ESAM_CARD_Control(CPU);

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xB0;
	Order_Head[2] = 0x80+Cpu_File_Name;
	Order_Head[3] = Cpu_Start_Addr;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,Head_Length,temp_buffer_2,0,CommunicationPortMode,Updata_Data_L+4)!= OK )
	{
		return ERR;
	}

//	My_Memcpy(Co.b,cpucard_number,8);

//	My_Memcpy(Co.b+8,receive_send_buffer,Updata_Data_L+4);
	My_Memcpy(Co.b,receive_send_buffer,Updata_Data_L+4);

	if( Data_Output_Point!=0 )
		My_Memcpy(Data_Output_Point,receive_send_buffer,Updata_Data_L);

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xD6;
	Order_Head[2] = 0x80+Esam_File_Name;
	Order_Head[3] = Esam_Start_Addr;
	if(Check_CPU_Occur())			
		{
		R_CARD_ERROR_INFO=MOVE_CARD_DEFINE;
		return ERR;
		}
	CPU_ESAM_CARD_Control(ESAM);
	
//	if( CPU_Card_Driver((const unsigned char *)Order_Head,Updata_Data_L+12,&Co.b[0],0,CommunicationPortMode,0)!= OK )
	if( CPU_Card_Driver((const unsigned char *)Order_Head,Updata_Data_L+4,&Co.b[0],0,CommunicationPortMode,0)!= OK )
	{
		R_CARD_ERROR_INFO=MAC_ERROR_DEFINE;
		return ERR;
	}

	return OK;
	}
/*"**************************************************************************"*/
/*" 功能：CPU卡其他文件更新 "*/
/*" Cpu_File_Name: "*/
/*" Esam_File_Name: "*/
/*" Cpu_Start_Addr: "*/
/*" Esam_Start_Addr: "*/
/*" Updata_Data_L: "*/
unsigned char Cpu_File_Updata(unsigned char Cpu_File_Name,
								    unsigned char Esam_File_Name,
							   		unsigned char Cpu_Start_Addr,
							   		unsigned char Esam_Start_Addr,
							   		unsigned char Updata_Data_L)
	{
	unsigned char count,ret,temp_buffer_2[30],Order_Head[4];

	
	CPU_ESAM_CARD_Control(CPU);
	if(Read(0,Get_Challenge,0,0,4)!=OK)
	{
		return ERR;
	}
	temp_buffer_2[0]=receive_send_buffer[0];   
	temp_buffer_2[1]=receive_send_buffer[1];
	temp_buffer_2[2]=receive_send_buffer[2];
	temp_buffer_2[3]=receive_send_buffer[3];
	temp_buffer_2[4]=0x04;
	temp_buffer_2[5]=0xD6;
	temp_buffer_2[6]=0x80+Cpu_File_Name;
	temp_buffer_2[7]=Cpu_Start_Addr;
	temp_buffer_2[8]=Updata_Data_L+4;

	My_Memcpy(temp_buffer_2+9,cpucard_number,8);

	CPU_ESAM_CARD_Control(ESAM);

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xB0;
	Order_Head[2] = 0x80+Esam_File_Name;
	Order_Head[3] = Esam_Start_Addr;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x11,temp_buffer_2,0,CommunicationPortMode,Updata_Data_L+4)!= OK )
	{
		return ERR;
	}

	CPU_ESAM_CARD_Control(CPU);

	My_Memcpy(Co.b,receive_send_buffer,Updata_Data_L+4); 

	Order_Head[0] = 0x04;
	Order_Head[1] = 0xD6;
	Order_Head[2] = 0x80+Cpu_File_Name;
	Order_Head[3] = Cpu_Start_Addr;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,Updata_Data_L+4,&Co.b[0],0,CommunicationPortMode,0)!= OK )
	{
		R_CARD_ERROR_INFO=MAC_ERROR_DEFINE;
		return ERR;
	}

	return OK;
	}
#if 0
/*"**************************************************************************"*/
/*" 功能：CPU卡计数器文件更新 "*/
/*" CPU_File_Name: "*/
/*" CPU_Counter_Length: "*/
/*"计数器减一8030001404+00000001 "*/
unsigned char CPU_Counter_Dec(unsigned char CPU_File_Name,unsigned char CPU_Counter_Length)
	{
	unsigned char Order_Head[4];
	
	CPU_ESAM_CARD_Control(CPU);
	Order_Head[0] = 0;
	Order_Head[1] = 0;
	Order_Head[2] = 0;
	Order_Head[3] = 1;
	if(Write(0x80,0x30,00,CPU_File_Name,CPU_Counter_Length,Order_Head)!=OK)
		return ERR;

	return OK;
	}

/*"**************************************************************************"*/
/*" 功能：密钥更新 "*/
/*"801a1e0108+0000+ 表号 "*/
/*"801a1e0208+0000+表号"*/
/*"801a1e0608+0000+表号"*/
/*"801a1e0708+0000+表号"*/
/*"bfe6000203010300"*/               
/*"bfe6000203010500"*/
/*"bfe6000203010900"*/
/*"bfe6000203010a00"*/
/*"84d401ff20+ DATA"*/               
/*"84d401ff20+ DATA"*/
/*"84d401ff20+ DATA"*/
/*"84d401ff20+ DATA"*/
unsigned char Esam_Safe_Password_Updata(unsigned char Password_Addr,
											    unsigned char Password_Off,
											    unsigned char Card_ID)
	{
	unsigned char Order_Head[4],temp_buffer_2[32];
	unsigned char i;

	CPU_ESAM_CARD_Control(CPU);
	Order_Head[0] = 0x80;
	Order_Head[1] = 0x1A;
	Order_Head[2] = 0x1E;
	Order_Head[3] = Password_Addr;
	temp_buffer_2[0] = 0;
	temp_buffer_2[1] = 0;
	My_Memcpy(temp_buffer_2+2,(unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6); 
	if( Card_ID==GWFAR_RES_PASSWORD_CARD )
		{
		for( i=0;i<8;i++ )
			temp_buffer_2[i] = 0;
		temp_buffer_2[7] = 1;
		}
	if( CPU_Card_Driver((const unsigned char *)Order_Head,8,temp_buffer_2,0,CommunicationPortMode,0)!= OK )
		return ERR;

	Order_Head[0] = 0xBF;
	Order_Head[1] = 0xE6;
	Order_Head[2] = 0x00;
	Order_Head[3] = 0x02;

	temp_buffer_2[0] = 0x01;
	temp_buffer_2[1] = Password_Off;
	temp_buffer_2[2] = 0x00;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,3,temp_buffer_2,0,CommunicationPortMode,0)!= OK )
		return ERR;

	My_Memcpy(temp_buffer_2,receive_send_buffer,0x20); 

	CPU_ESAM_CARD_Control(ESAM);
	Order_Head[0] = 0x84;
	Order_Head[1] = 0xD4;
	Order_Head[2] = 0x01;
	Order_Head[3] = 0xFF;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x20,temp_buffer_2,0,CommunicationPortMode,0)!= OK )
		return ERR;

	return OK;
	}

/*"**************************************************************************"*/
/*" 功能：密钥更新 "*/
unsigned char PassWord_Updata(unsigned char Card_ID)
	{
	unsigned char i;
	
	if( Esam_Safe_Password_Updata(1,3,Card_ID) != OK )
		return ERR;
	if( Esam_Safe_Password_Updata(2,5,Card_ID) != OK )
		return ERR;
	if( Esam_Safe_Password_Updata(6,9,Card_ID) != OK )
		return ERR;
	if( Esam_Safe_Password_Updata(7,0x0A,Card_ID) != OK )
		return ERR;

	CPU_ESAM_CARD_Control(CPU);
	if( Read(0x00,Read_Binary,0x83,0x04,0x80 ) != OK )
		return ERR;

	My_Memcpy(Card_WR_Buff,receive_send_buffer,0x80); 
	
	CPU_ESAM_CARD_Control(ESAM);
	for(i=0;i<3;i++)
		{
		if(Write(0x84,0xd4,1,0xff,0x20,&Card_WR_Buff[32*i])!=OK)
			{
			press_card_state =	CPU_CARD_SIC_ERR;
			R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
			return ERR; 
			}
		} 
	
	for(i=3;i<4;i++)
		{
		if(Write(0x84,0xd4,1,0x00,0x20,&Card_WR_Buff[32*i])!=OK)
			{
			press_card_state =	CPU_CARD_SIC_ERR;
			R_CARD_ERROR_INFO=OPCARD_ERROR_DEFINE;
			return ERR; 
			}
		} 
	return OK;
	}
#endif


//===============================================================//
//Function:
//Description:
//Parameter:
//Author:
//Date:
//===============================================================//
/*"内置继电器状态检测 (对于内置负荷开关，增加检测电路，检测实际状态)"*/
unsigned char GetRelayPort_Status(void)
{
	unsigned char l_temp;

	l_temp = RELAY_CHECK_INTPUT;
	return l_temp;
}





//===============================================================//


