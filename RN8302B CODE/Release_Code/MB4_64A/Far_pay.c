/*"**********************************************************************************"*/
/*"��������: Զ��Ԥ���Ѻ���-------"*/
/*"����:����SM1�㷨Զ��Ԥ����----"*/
/*"Creat   : ��־-----------------------------"*/
/*"����: 2008-08-25-------------------------"*/
#include "Defdata.h"
#include "Interrupt.h"
#include "eeprom.h"
#include "I2C_operation.h"
#include "comm.h"
#include "ram.h"
#include "MB_Showmain.h"
#include "Measure_Interface.h" 
#include "Energy_Del.H"
#include "Pay_def.h"
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "Far_pay.h"
#include "ICcard.h"
#include "645_2007.h"
#include "Card_File.h"
#include "ICcard.h"
#include "MB_Keymain.h"///king chen add 130204
#include "Flash_API_M16C.h"

#include "Multi.h"

#define  B_FL             200				/*"ͨѶ��������ѯ�ܳ���"*/
/*"**********************************************************************************"*/
/*" ������붨��,�й���CPU�ײ�����Ĵ��� "*/
#define FAR_ESAM_ATR_ERR       			0x0020           /*" ESAM��λ�� "*/
#define FAR_SELECT_FILE_ERR      			0x0021           /*" �ļ�ѡ��� "*/ 
#define FAR_READ_FILE_ERR      			0x0022           /*" �ļ����� "*/ 
#define FAR_DATA_HEAD_ERR				0x0023           /*" ������68ͷ�� "*/ 
#define FAR_DATA_END_ERR       			0x0024           /*" ������16β�� "*/
#define FAR_DATA_CHECK_ERR			0x0025    	/*" ������Ч��� "*/
#define FAR_EXT_AUTH_ERR				0x0026           /*" �ⲿ��֤�� "*/
#define FAR_INT_AUTH_ERR				0x0027           /*" �ڲ���֤�� "*/
#define FAR_SEC_COMP_ERR				0x0028           /*" ���ıȽϴ� "*/
#define FAR_WRITE_FILE_ERR				0x0029           /*" �ļ�д�� "*/
#define FAR_COMM_DELAY_ERR			0x0030    	/*" ESAM ���մ� "*/

#define FAR_SUCCESS            				0xFFFF           /*" ���������ȷ "*/

/*"**********************************************************************************"*/
/*"---------�ڲ�����---------"*/
union SECURITY_AUTH_ERR_INFORMATION Far_Security_Auth_Err_Info;	/*��ȫ��֤������Ϣ��*/
struct Far_Identity_Authentication_Define Far_Identity_Auth_Data;			/*"Զ�������֤����"*/
unsigned int Esam_Far_Identity_Auth_Valid_Time;					/*"ESAM�����֤��Чʱ��"*/
unsigned char Far_Identity_Auth_Ok_Flag;						 		/*"Զ�������֤�ɹ���־"*/
unsigned long Far_Identity_Auth_Ok_Time;						 		/*"�����֤ʱ��--"*/
unsigned char *far_data_p;											/*"����ָ��"*/
unsigned char esam_number[8];										/*"ESAM�����к�,��ɢ����"*/

unsigned char Far_Spec_Order_Flag;
unsigned long FarOpenTime=0;
unsigned long FarCloseTime=0;
unsigned long Remain_Money_Bag_Do_Time;

unsigned char Far_InfraredFlag = 0;           /*" ������֤ͨ����־ "*/
unsigned long Far_Infrared_Auth_Ok_Time = 0;	/*" ������֤ͨ��ʱ��(��λ:ms) "*/	

unsigned int  R_ID_Remain_Time=0; 				/*"�����֤ʣ��ʱ��(��λ:����)"*/
unsigned int  R_Infrared_Remain_Time=0; 	/*"������֤ʣ��ʱ��(��λ:����)"*/

unsigned char Far_Read_Esam(unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char *);
//void Data_Dec_0X33(unsigned char * ,unsigned int );					//Li Update 20121225
unsigned char Far_Deal_Order_0x03(unsigned char *,unsigned char  );
unsigned char Far_Deal_Control(unsigned char *);
/*"**********************************************************************************"*/
/*"---------�ⲿ����---------------"*/
extern unsigned char Relay_Alarm_SWitch_Flag[2][2];

extern unsigned long    Clear_all_oper_code;
extern unsigned long    Clear_demand_oper_code;
extern unsigned char    buy_money_OK_flag;

extern unsigned char oprateCode[];

 unsigned char rand4[4];

/*"**********************************************************************************"*/
/*"---------�ڲ���������---------"*/
void Far_Prepayment_Read_Write(unsigned char );				/*"Զ�̷ѿض�����"*/
unsigned char Far_TransferData_New(union ID id,unsigned char *, unsigned int ,unsigned char formatdata,unsigned char ,unsigned char ,unsigned char );
unsigned char Far_Init_Esam(void);  
unsigned char Far_Esamcard_Internal_Auth(unsigned char *); 
unsigned char Far_Read_Esam(unsigned char ,unsigned char ,unsigned char ,
			unsigned char ,unsigned char ,unsigned char * );
unsigned char Far_Write_Esam(unsigned char ,unsigned char ,unsigned char ,
			unsigned char ,unsigned char ,unsigned char *,unsigned char  ); 
unsigned char Find_Do_Money_Bag(void);
unsigned char Find_T1_Para(unsigned char * );
void invalid_psw_upd_flag(void);
unsigned char write_psw_status_wd_to_esam(unsigned long psw);
unsigned char CheckCmdTime(unsigned char * Point);

//unsigned char FayMidefyFlag=0;	/*"�����޸�����"*/

/*"**********************************************************************************"*/
/*"---------�ⲿ��������---------"*/
extern void My_memcpyRev(unsigned char *,unsigned char *,unsigned char );
extern void tr_show_wait(int time);
//#pragma SECTION program program_protect
/*" ����-0x33ת�� "*/
void My_Memcpy_Dec_0x33(	unsigned char * To_Point, unsigned char * From_Point, 
								unsigned char Offset,unsigned char Length,unsigned char Max_Limit)
	{
	unsigned char i;
	for(i=0;i<Length;i++) 
		{
		*(To_Point+i)=*(From_Point+Offset)-0x33;
		Offset++;
		if(Offset>=Max_Limit) 
			Offset=0;	    
		}
	}

/*" ��¼ESAM����ʧ�ܣ�����ʧ��200�μ�Ϊ���� "*/
void record_esam_oprate_err(void)
{
	if (Show_flag.bit.Ing)	/*"���ز�������¼"*/
		return;

    if (Pre_Payment_Data.HangMeterNum < 0xff) {
	    Pre_Payment_Data.HangMeterNum++;
        Pay_EE_W(HANGMETER_EE,(unsigned char *)&(Pre_Payment_Data.HangMeterNum),1,3,
                (unsigned char *)&(Pre_Payment_Data),LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
    }
	if (Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		HANG_ERR_DEFINE=1;
	}
}

/*" ����0x98������ģʽ���� (����������0x1A������������������0x19�����¼����㣨0x1B��) "*/
/*" uartx: ���ںţ�cmd_code: 645����Ŀ����� "*/
/*" �ɹ�����1 ʧ�ܷ���0 "*/
unsigned char cmd_0x98_mode_decipher(unsigned char uartx, unsigned char cmd_code)
{
	unsigned char ok, i;
	struct FindCommand_Result *pc;
    struct cmd_plaintext *cmd;
    unsigned char expire;
    unsigned char file;
    unsigned char plain_len;

    if ((uartx == UART_IR) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0;
    }

    if (Far_Identity_Auth_Ok_Flag != 0xFF) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0;
    }
    
    if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
		return 0;
	}

	Meter_States.ErrOfInformation.byte=0;
	
	pc = CurrPC;
	far_data_p = CommBP;
	

    /*" ����������ʼֵpc->addrָ��PAλ��"*/
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p, pc->addr, pc->len, B_FL);
    /*" ��������ߴ���"*/
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
	My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);

	press_card_state = CPU_CARD_SUCCESS;	/*" ��ֹ�ײ����"*/

	ok = 0;
	Cpucard_Serial_Init();	/*"��ʼ��ESAM����"*/
	if(Far_Init_Esam() != OK) {
        Meter_States.ErrOfInformation.bit.Invalid_Data = 1;
        return 0;
	}

    if (cmd_code == 0x1A) {
        /*" �������� "*/
        file = 0x94;
    } else {
        /*" �¼����������� "*/
        file = 0x97;
    }
    cmd = (struct cmd_plaintext *)(WriteDateBuff + 8);
	if( pc->len == 28 ) {/*"8�ֽ����롢�����ߴ���  + 20�ֽ�����"*/
		Reverse_data(WriteDateBuff+8,20);
		if( Write(0x04,0xD6,file,0x00,0x14,WriteDateBuff+8) == OK) {/*"����ʹ�� ���������ļ� "*/
            if (cmd_code == 0x1B) {
                plain_len = 12;
            } else {
                plain_len = 8;
            }
            if( Read(0,Read_Binary,file,0,plain_len) == OK ) {
                if (cmd_code == 0x1B) {/*"�ٽ�����װ������645֡"*/
                    My_memcpyRev(far_data_p + pc->addr + 8,receive_send_buffer + 2, 10);
                    for (i = 0; i < 10; i++) {
                        far_data_p[pc->addr + 8 + i] += 0x33;
                    }
                    pc->len = 18;/*"���롢�����ߴ��롢�����¼���¼���ݱ�ʶ��6�ֽڵĽ�ֹ����"*/
                }
				My_Memcpy(WriteDateBuff+8,receive_send_buffer, plain_len);
                cmd = (struct cmd_plaintext *)(WriteDateBuff + 8);
				ok = 0xff;
            }
        } else {
			//press_card_state = FAY_PASS_INC_ERR;
            //displayCharTimeLen(DISP_IC_ERR,10,0);	/*"QQQ ��ʾIC�忨����(IC--xx)"*/  
			//record_esam_oprate_err();
        }
    }
	cpucard_serial_release();
    if (ok) {
        /*" ��������� ���� ��ֹ����С�ڵ�ǰʱ���ʾ������"*/
        expire = CheckCmdTime(WriteDateBuff + 8);
        if ((cmd->code != cmd_code) || expire) {
            if (expire) {
                Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
            } else {
                Meter_States.ErrOfInformation.bit.Invalid_Data = 1;
            }
            return 0;
        }
        return 1;
    }
    Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
    return 0;
}

/*" ������0x03(��ȫ��֤����)���� "*/
void Far_Prepayment_Read_Write(unsigned char uartx)
{  
	unsigned char mode;
	struct FindCommand_Result *pc;
	unsigned char i_ret;
	
	AppointTrasfPortBuff(uartx);
	pc = CurrPC;
	far_data_p = CommBP;

/*" ����������ʼֵpc->addrָ��DI0λ��"*/
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p,pc->addr,pc->len,B_FL);
/*" ��������ߴ���"*/
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
    My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);
    
/*" �������ݱ�ʶ"*/
	My_Memcpy((unsigned char*)&(pc->id.d), WriteDateBuff, 4);

  
	pc->idt.l=pc->id.l;  
	
	press_card_state = CPU_CARD_SUCCESS;	/*" ��ֹ�ײ����"*/
	Far_Security_Auth_Err_Info.intd = 0;		/*��ȫ��֤������Ϣ��*/
    OTHER_ERR_DEFINE = 1;
    if (IntoPowerDownFlag) {
        if ((pc->idt.l == 0x078003ff) || (pc->idt.l == 0x070003ff)) {
            pc->ct=0xc3; 
            Co.c.len=2;
            pc->lena=2;
            memcpy((unsigned char *)&far_data_p[10], (unsigned char *)&Far_Security_Auth_Err_Info.intd, 2);
        } else {
            pc->ct = 0;
        }
        return;
    }

     mode = 0;
    /*"������֤"*/
    if ((pc->idt.l == 0x078003ff) || (pc->idt.l == 0x070003ff)) {
        if (uartx == UART_IR) {/*"�Ǻ���ͨ��"*/
            i_ret = Far_TransferData_New(pc->idt,WriteDateBuff,0,COMMFORMAT,mode,pc->len,uartx);
        } else {
            i_ret = ERR;
        }
    } else if( ( Far_Identity_Auth_Ok_Flag==0xFF ) || ( pc->idt.l == 0x70000FF )) {
        if ((uartx == UART_IR) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)) {
            IDENTITY_AUTH_ERR_DEFINE = 1;
            i_ret = ERR;
        } else {
            /*" �����֤ͨ�������ܱ������״̬���ٴ��յ������֤��������ñ��״̬ "*/
            if( ( Far_Identity_Auth_Ok_Flag == 0xFF ) && ( pc->idt.l == 0x70000FF ) ) {
                Event_Power_Net_Flag.bit.ProgrammeEvent = 0;
            }
            //if (pc->All_AA_Address)
			//	COMM_ALL_AA_DEFINE=1;
			//else
			//	COMM_ALL_AA_DEFINE=0;
            i_ret=Far_TransferData_New(pc->idt,WriteDateBuff,0,COMMFORMAT,mode,pc->len,uartx);
        }
    } else {
		i_ret=ERR;
		IDENTITY_AUTH_ERR_DEFINE = 1;
		//press_card_state = FAY_PASS_INC_ERR;
		//record_esam_oprate_err();
		//displayCharTimeLen(DISP_IC_ERR,10,0);
    }
		
	if(i_ret==OK) 	/*"��д���ݳɹ�"*/
		{
		pc->ct=0x83; 										
		pc->lena=Co.c.len;
		return;
		}
	

	pc->ct=0xc3; 
	Co.c.len=2;
	pc->lena=2;
	if(( Far_Security_Auth_Err_Info.intd & 0xFFFE ) != 0 )
		Far_Security_Auth_Err_Info.intd &= 0xFFFE;
	memcpy((unsigned char *)&far_data_p[10], (unsigned char *)&Far_Security_Auth_Err_Info.intd, 2);
	return;
}

/*" ������0x1C���� "*/
void Far_Control(unsigned char uartx)
{
	unsigned char mode, ok;
	struct FindCommand_Result *pc;
	unsigned char i_ret;
	//unsigned char Password_List[4];

	AppointTrasfPortBuff(uartx);
	pc = CurrPC;
	far_data_p = CommBP;

/*" ����������ʼֵpc->addrָ��PAλ��"*/
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p,pc->addr,pc->len,B_FL);
/*" ��������ߴ���"*/
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
	My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);
/*" ��������"*/
	//My_Memcpy((unsigned char*)&(Password_List[0]), WriteDateBuff, 4);

	press_card_state = CPU_CARD_SUCCESS;	/*" ��ֹ�ײ����"*/
	Far_Security_Auth_Err_Info.intd=0;		/*��ȫ��֤������Ϣ��*/

	FAY_CTL_RES_DEFINE=0;
	Fay_Ctl_Res_Ok.intd=0;
	Fay_Ctl_Res_Err.intd=0;
	ok = 0;
	/*"�߰�ȫ��֤·��"*/
	if (WriteDateBuff[0] == 0x98)
		{
		if (WriteDateBuff[3]==1)	/*"��P2=1ʱ��Ӧ��֡�а���2�ֽڵ�״̬��"*/
			FAY_CTL_RES_DEFINE=1;

		if ((!MACRO_FAY_CONTROL_FLAG) || ((uartx == UART_IR) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)))
			 Fay_Ctl_Res_Err.bit.PassErr=1;
		else if (Far_Identity_Auth_Ok_Flag!=0xFF)
			Fay_Ctl_Res_Err.bit.NoIden=1;
		else if (Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG)
			Fay_Ctl_Res_Err.bit.Hang=1;
		else
			{
			Cpucard_Serial_Init();	/*"��ʼ��ESAM����"*/
			if(Far_Init_Esam()==OK)
				{
				if( pc->len == 28 )
					{
					Reverse_data(WriteDateBuff+8,20);
					if( Write(0x04,0xD6,0x88,0x00,0x14,WriteDateBuff+8)==OK)
						{
						if( Read(0,Read_Binary,0x88,0,8) == OK )
							{
							My_Memcpy(WriteDateBuff+8,receive_send_buffer, 8);
							ok = 0xff;
							}
						}
					else
						{
							if (R_CARD_ERROR_INFO==MAC_ERROR_DEFINE)	/*"������ȷʵMAC����ʱ���Żظ�MAC��"*/
								Fay_Ctl_Res_Err.bit.MacErr=1;
							else
								Fay_Ctl_Res_Err.bit.PassErr=1;		/*"��������������ʱ���ظ������"*/
							ESAM_AUTH_ERR_DEFINE=1;
						}
					}
				}
			cpucard_serial_release();
			if( ok !=0 )
				ok = Far_Deal_Control(WriteDateBuff+8);
			}
		}
	/*" ������ͨ645������� "*/
	//else if ((Password_List[0] == 0x02) && (O1ther_Meter_Parameter.WorkRoomState||PUBLIC_CONTROL_RELAY_DEFINE) )	/*"����,���ߴ���������բ"*/ 
	else if (MACRO_FAY_CONTROL_FLAG&&((WriteDateBuff[0]==0x02)||(WriteDateBuff[0]==0x04)))	//&&(O1ther_Meter_Parameter.WorkRoomState||PUBLIC_CONTROL_RELAY_DEFINE))	/*"����"*/ 
	{
		//ok = 0x02;
//#ifdef  PASSWORD_MODE
		ok = 2;

		//if(O1ther_Meter_Parameter.WorkRoomState!=0)
		//	Comm_Staut.meter_staut=0x11;/*"����״̬"*/
		//else Comm_Staut.meter_staut=0x33;/*"    �ֳ� ״̬fuxf add 081209  "*/
		
		if (!O1ther_Meter_Parameter.WorkRoomState)
			{
			ok=CheckPasswordRight((unsigned char *)&WriteDateBuff[0]);
			//Comm_Staut.password_level=ok; 
			if (ok<=9)	/*"������ȷ"*/
				{
				if (!(Other_Data.PasswordErr[ok].flag))
					{
					//cx[3].passerword=ok; 
					Clear_PasswordErr(1,ok);		    
					ok=0xff;
					}
				else		/*"�����������Ȩ�޲���"*/
					{
					ok=0;
					}
				}
			else 	/*"���뼶�𳬷�ΧOR���뼶���ڷ�Χ�ڵ����������"*/
				{
				if(ok!=0xff)	/*"���뼶���ڷ�Χ�ڵ����������"*/
					CheckPasswoerErr(ok&0x7f);
				ok=0;
				Fay_Ctl_Res_Err.bit.PassErr=1;
				}
			}
//#endif
		if( ok !=0 )
			{
			Reverse_data(WriteDateBuff+10, 6);
			if (O1ther_Meter_Parameter.WorkRoomState || WriteDateBuff[8]==0x1B || WriteDateBuff[8]==0x1C)	/*"��������ֻ�����բ"*/
				{
				ok = Far_Deal_Control(WriteDateBuff+8 );
				}
			else
				{
				Fay_Ctl_Res_Err.bit.PassErr=1;
				ok=0;
				}
			}
		}
		else
		{
		Fay_Ctl_Res_Err.bit.PassErr=1;
		}

	if( ok != 0 )
		{
		pc->ct=0x9C;
		Co.c.len=0;
		pc->lena=0;
		if (FAY_CTL_RES_DEFINE)
		{
			far_data_p[10]=Fay_Ctl_Res_Ok.intd&0xFF;
			far_data_p[11]=Fay_Ctl_Res_Ok.intd>>8;
			Co.c.len+=2;
			pc->lena+=2;
		}
		}
	else
		{
		pc->ct=0xDC;
		if (FAY_CTL_RES_DEFINE)
			{
			if (Fay_Ctl_Res_Err.intd==0)
				Fay_Ctl_Res_Err.bit.PassErr=1;
			far_data_p[10]=Fay_Ctl_Res_Err.intd&0xFF;
			far_data_p[11]=Fay_Ctl_Res_Err.intd>>8;
			Co.c.len=2;
			pc->lena=2;			
			}
		else
			{
			Co.c.len=1;
			pc->lena=1;
			if(Meter_States.ErrOfInformation.byte==0)
				{
				if (Fay_Ctl_Res_Err.intd)
					Meter_States.ErrOfInformation.bit.Invalid_Password=1;
				else
					Meter_States.ErrOfInformation.bit.Invalid_Data=1;
				}
			far_data_p[10]=Meter_States.ErrOfInformation.byte;
			}
		}
	
	return ;
}

/*"��������Զ�̷ѿض�д����"*/
unsigned char Far_TransferData_New (union ID id,unsigned char *P_in, unsigned int L,
                         unsigned char formatdata,unsigned char mode,unsigned char data_len,unsigned char uartx)
{
	unsigned int ret;

	ret = OK;
	Cpucard_Serial_Init();	/*"��ʼ��ESAM����"*/
    /*"Զ�������֤ || ������֤��  ��Ҫ��ʼ��ESAM"*/
	if( (id.l == 0x70000FF) || ((id.l == 0x078003ff) && (Far_Identity_Auth_Ok_Flag == 0)))
		{
		if( Esamcard_Atr() != OK )
			{
			ret = ERR;
			}
		else
			memcpy(esam_number,receive_send_buffer+5,8);
		}

	if( ret==OK )
		{
		Far_Init_Esam();
		if (COMM_ALL_AA_DEFINE 
			&& (id.l!=0x070000FF) 	/*"�����֤"*/
			&& (id.l!=0x070002FF)	/*"�����֤ʧЧ"*/
			&& (id.l!=0x078001FF) 	/*"���ݻس�"*/
			&& (id.l!=0x078102FF) 	/*"״̬��ѯ"*/
			&& (id.l!=0x078003FF) 	/*"����ָ��"*/
			&& (id.l!=0x070003FF)	/*"������֤"*/
			&& (id.l!=0x078002FF))	/*"����Ա�"*/
			ret = ERR;
		else
			ret =  Far_Deal_Order_0x03(P_in,data_len) ;
		}
	cpucard_serial_release();	/*"�ͷ�ESAM����"*/
	return ret;
}

/*" ��ʼ��ESAM "*/
unsigned char Far_Init_Esam(void)
{
	unsigned char ret;

	CPU_ESAM_CARD_Control(ESAM);
/*" 20130302: �����������Զ�̿��ƺͰ�ȫ��֤���������ִ��"*/
/*	
	if( (Select_File(0,0x3f,0x00))!=OK) 
	    return ERR;
*/	
	return OK;
}

void get_meter_para_from_esam(void)
{
    unsigned char ret;
    unsigned char BcdMeterID[6];
    unsigned long psw;

    ret = OK;

	if (IntoPowerDownFlag) {
		return;
	}
    CPU_ESAM_CARD_Control(ESAM);
    Cpucard_Serial_Init();
    ret = Esamcard_Atr();
    if (ret != OK) {
        Cpu_Card_IO_Reset();
        return;
    }
	if( Select_File(0,0x3F,00) != OK ) {
        Cpu_Card_IO_Reset();
	    return;
	}
    ret = Get_File_Data(ESAM,ESAM_PARA_INF_FILE,METER_ID_ESAM,6, BcdMeterID);
    if (ret == OK) {
        if (My_Memcmp(&Meter_Parameter.parameter2.BcdMeterID[0] ,BcdMeterID, 6) != 0) {
            My_Memcpy(&Meter_Parameter.parameter2.BcdMeterID[0] ,BcdMeterID, 6);
            WRLC256(BCDMETERID_ROM,(unsigned char*)&Meter_Parameter.parameter2.BcdMeterID[0],6,0,0);
        	Set_Meter_para_Deal(BCDMETERID_ROM);
        }
    }
    
#if 0   /*" Ϊ�����ϰ汾 "*/
    ret = Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,4,4, (unsigned char *)&psw);
    if (ret == OK) {
        if (psw == 0xFFFF0F00UL || psw == 0x000FFFFFUL) {
            psw = 0xFFFF0F00UL;
            Write(0,Update_Binary,0x80+ESAM_PASSWORD_INF_FILE,0,4, (unsigned char *)&psw);
            psw = 0;
            Write(0,Update_Binary,0x80+ESAM_PASSWORD_INF_FILE,4,4, (unsigned char *)&psw);
        }
    } else {
        ret = Esamcard_Atr();
        if (ret != OK) {
            cpucard_serial_release();
            return;
        }
    	if( Select_File(0,0x3F,00) != OK ) {
            cpucard_serial_release();
    	    return;
    	}
    }
#endif

    ret = Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,0,4, (unsigned char *)&psw);/*"˽Կ: psw == 0xFFFF0F00"*/
    if (ret != OK) {
        Cpu_Card_IO_Reset();
        return;
    }
#if 0
    if (psw == 0x000FFFFFUL) {/*" �ϰ汾��һ���л�������°汾 : ������תһ������д����Կ��Ϣ�ļ� "*/
        ret = write_psw_status_wd_to_esam(psw);
        if (ret != OK) {
            /*" �ݴ� �˴�������"*/
        }
        psw = 0xFFFF0F00;
    }
#endif    
    Reverse_data((unsigned char *)&psw, 4);
    if (Pre_Payment_Para.Far_Key_StatusByte != psw) {
        Pre_Payment_Para.Far_Key_StatusByte = psw;
        Pay_EE_W(FAR_KEY_STATUSBYTE_EE,(unsigned char *)&(Pre_Payment_Para.Far_Key_StatusByte),4,3,
                (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    }
    Cpu_Card_IO_Reset();
}

unsigned char write_psw_status_wd_to_esam(unsigned long psw)
{
    unsigned char ret;
    unsigned char buf[4];

    My_memcpyRev(buf, (unsigned char *)&psw, 4);
    ret = Write(0,Update_Binary,0x80+ESAM_PASSWORD_INF_FILE,0,4, buf);
    if (ret == ERR) {
        //press_card_state = FAY_PASS_MODFIY_ERR;
        //displayCharTimeLen(DISP_IC_ERR,10,0);
    }
    return ret;
}




/*"Զ��ϵͳ�����֤"*/
unsigned char Far_Esamcard_Internal_Auth(unsigned char *Point)   
{
    unsigned long long factor;
    unsigned char meter_id[8];
    unsigned char ok;	

    factor = *(unsigned long long *)(Point+16);/*" 01 00 00 00 00 00 00 00"*/
    Reverse_data(Point+16, 8);                 /*" 00 00 00 00 00 00 00 01"*/
    meter_id[0] = 0;
    meter_id[1] = 0;
    My_Memcpy(&meter_id[2], (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
    My_Memcpy((unsigned char *)&Far_Identity_Auth_Data.Instruction.cryptograph1[0], Point, sizeof(struct Authentication_Instruction));
    /*" ��������֤�´��ķ�ɢ���Ӻ�6�ֽ����Ų���ȣ����ش��� �����ǳ��ڷ��ɵ㣬�����ش���) "*/
    if (My_Memcmp(Point + 18, meter_id + 2, 6) != 0) {
        if (O1ther_Meter_Parameter.WorkRoomState) {
            if (factor == 0x0000000000000001ULL || factor == 0x0ULL) {
                /*" ʹ�÷�ɢ���� "*/
                My_Memcpy(meter_id, Point + 16, 8);
            }
        } else {
            return ERR;
        }
    }
    
	My_memcpyRev(Card_WR_Buff+110, Point, 8);       /*"ת������1"*/    
	My_memcpyRev(Card_WR_Buff+100, Point+8, 8);     /*"ת�������1"*/    
	//My_Memcpy(Card_WR_Buff+1, &Far_Identity_Auth_Data.Instruction.disperse_gene[0], 8);      /*"ת��ɢ����1"*/ 

	CPU_ESAM_CARD_Control(ESAM);      /*"����ͨ��ESAM��"*/
	ok = Internal_Auth(0x80,0xfa,0,3,8, meter_id); /*"��ɢESAM ��Կ"*/
	if( ok != OK )
		return ERR;

	ok = Internal_Auth(0x80,0xfa,0,0,8,Card_WR_Buff+100); /*" �õ�ESAM��������� "*/
	if( ok != OK )
		return ERR;

	if(My_Memcmp(Card_WR_Buff+110,receive_send_buffer,8))  
		{
		//far_press_state= FAR_SEC_COMP_ERR;
		return ERR;      
		}
	return OK;  /*"�ڲ���֤����"*/  
}


/*" ��ESAM������MAC "*/
unsigned char Far_Read_Esam(unsigned char cla,unsigned char ins,unsigned char t_p1,
              unsigned char t_p2,unsigned char lc,unsigned char *address)
{
	unsigned char Order_Head[4];

    
    My_memcpyRev((unsigned char *)&Card_WR_Buff, (unsigned char *)&Far_Identity_Auth_Data.Instruction.random_number1[4], 4);
	//My_Memcpy(Card_WR_Buff, rand4, 4);/*"20130304ʹ������������ݻس� ״̬��ѯMACУ�����"*/
	Card_WR_Buff[4]=0x04;
	Card_WR_Buff[5]=0xd6;
	Card_WR_Buff[6]=0x86;
	if( ins == Read_Record ) {
		Card_WR_Buff[7]=0;
        Card_WR_Buff[8] = lc+12;	/*" 20130318:��Ҫ��Ϊ12������״̬��ѯ�ᱨMACУ����� "*/
    } else {
		Card_WR_Buff[7]=t_p2;
        Card_WR_Buff[8]=lc+12;	//data+mac+disperse_gene /*"QQQ LC�¹淶û��ȷ���� ���Ե�"*/
    }
	
	//My_Memcpy((unsigned char *)&Card_WR_Buff[9], (unsigned char *)&Far_Identity_Auth_Data.Instruction.disperse_gene[0], 8);
    Card_WR_Buff[9] = 0x00;
    Card_WR_Buff[10] = 0x00;
    My_Memcpy(Card_WR_Buff + 11, (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
    Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x11,Card_WR_Buff,0,CommunicationPortMode,lc+4)!= OK ) {
		ESAM_AUTH_ERR_DEFINE =1;
	    return ERR;
    }

	return OK;
}


/*" дESAM�� ����MAC  д"*/
/*" lc ������4�ֽ�MAC�ĳ��� "*/
unsigned char Far_Write_Esam(unsigned char cla,unsigned char ins,unsigned char t_p1,
			unsigned char t_p2,unsigned char lc,unsigned char *address,unsigned char Flag )
{
	unsigned char i;   
	unsigned char Order_Head[4];

	CPU_ESAM_CARD_Control(ESAM);

    switch (Flag) {
    case 0:/*"������MAC�ֱ�ת"*/
        My_memcpyRev((unsigned char *)&Card_WR_Buff[0], address,lc);
	    My_memcpyRev((unsigned char *)&Card_WR_Buff[lc], address+lc,4); 
        break;
    case 1:
        My_memcpyRev((unsigned char *)&Card_WR_Buff[0], address,lc+4);
        break;
    case 2:/*"������MAC�����÷�ת (������׼����Card_WR_Buff��) "*/
        break;
    default:
        return ERR;
    }

	Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,lc+4,Card_WR_Buff,0,CommunicationPortMode,0)!= OK )
		{
		ESAM_AUTH_ERR_DEFINE =1;
		//press_card_state = FAY_PASS_INC_ERR;
        //displayCharTimeLen(DISP_IC_ERR,10,0);  
		return ERR;
		}
    
	return OK;
}


struct Far_645_Frame_0x03
	{
	unsigned char Data_ID[4];
//	unsigned char PassWord[4];
	unsigned char Do_man[4];
	};
#define LENGTH_FAR_645_FRAME_0X03      sizeof(struct Far_645_Frame_0x03)

/*"**************************************************************************"*/
/*" ���ݻس�"*/
/*" ֧��07800101,078001FF "*/
/*" Data_Point:��:8�ֽ����ݻس���ʶ "*/
/*"            ��:8�ֽ����ݻس���ʶ+�س�������+MAC "*/
/*"**************************************************************************"*/
struct Far_Read_078001FF_Format
	{
	unsigned int	Data_Length;
	unsigned int	Data_Start_Addr;
	unsigned int	File;
	unsigned int	Name;
	};
#define LENGTH_FAR_READ_078001FF_FORMAT  sizeof( struct Far_Read_078001FF_Format )

//-----------------------------------------------------------------------------
unsigned char Far_Deal_078001FF(unsigned char *Data_Point )
	{
	struct Far_Read_078001FF_Format	* Far_Read_078001FF_Format;
	unsigned char * Point;
	unsigned char Offset;

//	My_memcpyRev(Card_WR_Buff, Data_Point, LENGTH_FAR_READ_078001FF_FORMAT);
	Far_Read_078001FF_Format = (struct Far_Read_078001FF_Format	*)Data_Point;

//	if( Select_File(0, *(((unsigned char *)&(Far_Read_078001FF_Format->Name))+1), (unsigned char)(Far_Read_078001FF_Format->Name)) != OK )
//		return ERR;
    if( Find_Do_Money_Bag() ) {
        Esam_Remain_Money_Dec();
        Updata_Esam_Return_File(0x11,0,0);
    }
	if( Far_Read_078001FF_Format->File == 0x01 )
		{
//		if( (unsigned char)(Far_Read_078001FF_Format->Data_Start_Addr )== 0x00 )
//			Offset = 0x01;
//		else
//			Offset = 0x03;
		if(Far_Read_Esam(0x04,Read_Record,0x01,0x0C,0x04,Data_Point)!=OK)
			return ERR;
		My_Memcpy(far_data_p+14, Data_Point, LENGTH_FAR_READ_078001FF_FORMAT);
		My_memcpyRev( far_data_p+22,receive_send_buffer,4 );
		My_memcpyRev( far_data_p+26,receive_send_buffer+4,4 );
		

		if(Far_Read_Esam(0x04,Read_Record,0x03,0x0C,0x04,Data_Point)!=OK)
			return ERR;	
		My_memcpyRev( far_data_p+30,receive_send_buffer,4 );
		My_memcpyRev( far_data_p+34,receive_send_buffer+4,4 );
		Co.c.len = 24;
		
		}
	else
		{
/*"04b082��83��84��86��+ P2(ƫ�Ƶ�ַ)��11+4�ֽ������1+04d686+00+LC+8�ֽڷ�ɢ���ӡ�
LC����Ҫ��ȡ���������ݣ�MAC+��ɢ���ӵ��ܳ��ȣ�����1�ֽڵ�ʮ����������"*/

		if(Far_Read_Esam(0x04,Read_Binary,0x80+(unsigned char)(Far_Read_078001FF_Format->File),
											 (unsigned char)(Far_Read_078001FF_Format->Data_Start_Addr),
											 (unsigned char)(Far_Read_078001FF_Format->Data_Length), 
											 Data_Point)!=OK)
			return ERR;
//		}
		My_Memcpy(far_data_p+14, Data_Point, LENGTH_FAR_READ_078001FF_FORMAT);
		My_memcpyRev( far_data_p+22,receive_send_buffer,((unsigned char)(Far_Read_078001FF_Format->Data_Length)) );
		My_memcpyRev( far_data_p+22+((unsigned char)(Far_Read_078001FF_Format->Data_Length)),receive_send_buffer+((unsigned char)(Far_Read_078001FF_Format->Data_Length)), 4);
//	Co.c.len = ((unsigned char)(Far_Read_078001FF_Format->Data_Length))+12;

		Co.c.len = ((unsigned char)(Far_Read_078001FF_Format->Data_Length))+12;
		}
	
//	My_memcpyRev( far_data_p+14,receive_send_buffer,((unsigned char)(Far_Read_078001FF_Format->Data_Length)) );
//	My_memcpyRev( far_data_p+14+((unsigned char)(Far_Read_078001FF_Format->Data_Length)),receive_send_buffer+((unsigned char)(Far_Read_078001FF_Format->Data_Length)), 4);
//	Co.c.len = ((unsigned char)(Far_Read_078001FF_Format->Data_Length))+4;
	return OK;
	}


/*"**************************************************************************"*/
/*" ��ѯ״̬"*/
/*" ֧��07810201 "*/
/*" Data_Point:��:�� "*/
/*"            ��:���ݸ�ʽ���� "*/
/*"**************************************************************************"*/
struct Far_Read_07810201_Format
	{
	unsigned long	Remain_Money;
	unsigned char	Remain_Money_Mac[4];
	unsigned long	Buy_Count;
	unsigned char	Buy_Count_MAC[4];
	unsigned char Client_ID[6];
	unsigned long psw_stat_word;
	};
#define LENGTH_FAR_READ_07810201_FORMAT  sizeof( struct Far_Read_07810201_Format )
//-----------------------------------------------------------------------------
unsigned char Far_Deal_07810201(unsigned char *Data_Point )
	{
	struct Far_Read_07810201_Format	*Far_Read_07810201_Format;

	Far_Read_07810201_Format = (struct Far_Read_07810201_Format *)(far_data_p+14);

	if( Find_Do_Money_Bag() ) {
		Esam_Remain_Money_Dec();
        Updata_Esam_Return_File(0x11,0,0);
	}

	if(Far_Read_Esam(0x04,Read_Record,1,0x0c,4,0)!=OK)
		return ERR;
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Remain_Money), receive_send_buffer,4);
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Remain_Money_Mac[0]), receive_send_buffer+4,4);
	
	if(Far_Read_Esam(0x04,Read_Record,3,0x0c,4,0)!=OK)
		return ERR;
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Buy_Count), receive_send_buffer,4);
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Buy_Count_MAC[0]), receive_send_buffer+4,4);

    /*" QQQ ����Ƿ�� ? Ҫ��ΪFar_Read_Esam "*/
    if( Get_File_Data(ESAM,ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,6,(unsigned char *)&(Far_Read_07810201_Format->Client_ID[0])) != OK )
		return ERR;
	//if( Far_Read_Esam(04,Read_Binary,0x80+ESAM_PARA_INF_FILE,CLIENT_ID_ESAM, 6, 0) != OK )
	//	return ERR;

	Reverse_data((unsigned char *)&(Far_Read_07810201_Format->Client_ID[0]),6);
    if( Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,0,4, (unsigned char *)&Far_Read_07810201_Format->psw_stat_word) != OK ) {
        return ERR;
    }
    Reverse_data((unsigned char *)&Far_Read_07810201_Format->psw_stat_word, 4);
	//Far_Read_07810201_Format->psw_stat_word = Pre_Payment_Para.Far_Key_StatusByte;
	
	Co.c.len = LENGTH_FAR_READ_07810201_FORMAT;
	return OK;
	}
/*"**************************************************************************"*/
/*" ��ѯ״̬"*/
/*" ֧��078102FF "*/
/*" Data_Point:��:�� "*/
/*"            ��:���ݸ�ʽ���� "*/
/*"**************************************************************************"*/
unsigned char Far_Deal_078102FF(unsigned char * Data_Point )
	{
	return Far_Deal_07810201(Data_Point);
	}


/*" ��ESAM���к� "*/
unsigned char read_esam_serial_num(unsigned char *esam_number)
{
    if (Read(0,Read_Binary,0x99,1,8) == OK) {
        memcpy(esam_number,receive_send_buffer,8);
        return OK;
    } else {
        return ERR;
    }
}

/*"**************************************************************************"*/
/*" �����֤"*/
/*" ֧��070000FF "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Read_070000FF_Format_In
	{
	unsigned char cryptograph1[8];								/*"����1"*/
	unsigned char	random_number1[8];							/*"�����1"*/
	unsigned char disperse_gene[8];								/*"��ɢ����"*/
	};
#define LENGTH_FAR_READ_070000FF_FORMAT_IN  sizeof( struct Far_Read_070000FF_Format_In )
//-----------------------------------------------------------------------------
struct Far_Read_070000FF_Format_Out
	{
	unsigned char	random_number2[4];							/*"�����2"*/
	unsigned char	esam_serial_number[8];						/*"ESAM���к�"*/	
	};
#define LENGTH_FAR_READ_070000FF_FORMAT_OUT  sizeof( struct Far_Read_070000FF_Format_Out )
//-----------------------------------------------------------------------------
unsigned char Far_Deal_070000FF(unsigned char * Data_Point )
{
	struct Far_Read_070000FF_Format_In	* Far_Read_070000FF_Format_In;
	struct Far_Read_070000FF_Format_Out	Far_Read_070000FF_Format_Out;

	Far_Read_070000FF_Format_In = (struct Far_Read_070000FF_Format_In *)Data_Point;

//	if( (Esamcard_Atr() )!=OK )
//		{
//		far_press_state=FAR_ESAM_ATR_ERR;
//		return ERR;
//		}
//	memcpy(esam_number,receive_send_buffer+5,8);
	
//	if( Select_File(0,0x3F,0) != OK )
//		{
//		return ERR;
//		}	
	
	if(Far_Esamcard_Internal_Auth(Data_Point)==OK) {
		if( Read(0,Get_Challenge,0,0,4) != OK ) {
			return ERR;
        }
		My_memcpyRev(far_data_p+14,receive_send_buffer,4);     /*"ת�������2"*/ 
        My_Memcpy(rand4,receive_send_buffer,4);
        
        if (read_esam_serial_num(esam_number) != OK) {
			return ERR;
        }
		My_memcpyRev(far_data_p+18,esam_number,8);     /*"ת��ESAM���к�"*/
        //My_Memcpy(far_data_p+18,esam_number,8);     /*"ת��ESAM���к� (���Ҳ����)"*/
		

/*"�����֤��Чʱ����ʼ��"*/
		Far_Identity_Auth_Ok_Flag=0xFF;	
		Far_Identity_Auth_Ok_Time=GetNowTime();
		//if(Far_Read_Esam(04,Read_Binary,0x80+ESAM_PARA_INF_FILE,IDENTITY_AUTH_TIME_ESAM, 2, 0)!=OK)
		//	return ERR;
		//lxrBcd_Hex(2,(unsigned char *) &receive_send_buffer[0]);
		//My_memcpyRev((unsigned char *)&Esam_Far_Identity_Auth_Valid_Time, (unsigned char *)&receive_send_buffer[0], 2);
		Esam_Far_Identity_Auth_Valid_Time=Pre_Payment_Para.ID_Ins_Time;

		if(Esam_Far_Identity_Auth_Valid_Time==0)
			Esam_Far_Identity_Auth_Valid_Time=5;

        R_ID_Remain_Time = Esam_Far_Identity_Auth_Valid_Time;

        //invalid_psw_upd_flag();
		
		Co.c.len = LENGTH_FAR_READ_070000FF_FORMAT_OUT;
		return OK;
    }
    
	IDENTITY_AUTH_ERR_DEFINE = 1;
	//press_card_state = FAY_PASS_INC_ERR;
    //displayCharTimeLen(DISP_IC_ERR,10,0);   
    //record_esam_oprate_err();
	return ERR;
}


/*"**************************************************************************"*/
/*" �����֤ʱЧ����"*/
/*" ֧��070001FF "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
struct Far_Deal_070001FF_format
	{
	unsigned int Identity_Limit;
	unsigned char Identity_Limit_Mac[4];
	};
#define LENGTH_FAR_DEAL_070001FF_FORMAT      sizeof(struct Far_Deal_070001FF_format)
//-----------------------------------------------------------------------------
unsigned char Far_Deal_070001FF(unsigned char * Data_Point )
	{
	struct Far_Deal_070001FF_format  *Far_Deal_070001FF_format;

	Far_Deal_070001FF_format = (struct Far_Deal_070001FF_format  *)Data_Point;
	
//	Reverse_data((unsigned char *)&(Far_Deal_070001FF_format->Identity_Limit),2)
//	Reverse_data((unsigned char *)&(Far_Deal_070001FF_format->Identity_Limit_Mac[0]),4)

    if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		HANG_ERR_DEFINE = 1;
		return ERR;
	}

	if( Far_Deal_070001FF_format->Identity_Limit == 0 ) {
		return ERR;
	}

	if( Far_Write_Esam(0x04,Update_Binary,0x80+ESAM_PARA_INF_FILE,IDENTITY_AUTH_TIME_ESAM,0x02,Data_Point,0)!=OK)
		{
		return ERR;
		}
/*" ����RAM�ò��� "*/
	if(Far_Read_Esam(04,Read_Binary,0x80+ESAM_PARA_INF_FILE,IDENTITY_AUTH_TIME_ESAM, 2, 0)!=OK)
		return ERR;
    
	Far_Identity_Auth_Ok_Time=GetNowTime();
	lxrBcd_Hex(2,(unsigned char *) &receive_send_buffer[0]);
	My_memcpyRev((unsigned char *)&Esam_Far_Identity_Auth_Valid_Time, (unsigned char *)&receive_send_buffer[0], 2);
	if(Esam_Far_Identity_Auth_Valid_Time==0)
		Esam_Far_Identity_Auth_Valid_Time=5;

	Pre_Payment_Para.ID_Ins_Time=Esam_Far_Identity_Auth_Valid_Time;
	Pay_EE_W(ID_INS_TIME_EE,(unsigned char *)&(Pre_Payment_Para.ID_Ins_Time),2,3,
			   (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	
	Co.c.len = 0;
	
	return OK;
	}


/*"**************************************************************************"*/
/*" �����֤ʧЧ"*/
/*" ֧��07000201 "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Deal_07000201_format
	{
	unsigned char Client_ID[6];
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned long psw_stat_word;
	};
#define LENGTH_FAR_DEAL_07000201_FORMAT      sizeof(struct Far_Deal_07000201_format)
unsigned char Far_Deal_07000201(unsigned char * Data_Point )
	{
	struct Far_Deal_07000201_format * Far_Deal_07000201_format;
	Far_Deal_07000201_format = (struct Far_Deal_07000201_format *)(far_data_p+14);

	if( Find_Do_Money_Bag() )
		Esam_Remain_Money_Dec();

	if(Far_Read_Esam(0x04,Read_Record,1,0x0c,4,0)!=OK)
		return ERR;
	My_memcpyRev((unsigned char *)&(Far_Deal_07000201_format->Remain_Money), receive_send_buffer,4);
	
	if(Far_Read_Esam(0x04,Read_Record,3,0x0c,4,0)!=OK)
		return ERR;
	My_memcpyRev((unsigned char *)&(Far_Deal_07000201_format->Buy_Count), receive_send_buffer,4);

	if( Get_File_Data(ESAM,ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,6,(unsigned char *)&(Far_Deal_07000201_format->Client_ID[0])) != OK )
		return ERR;

	Reverse_data((unsigned char *)&(Far_Deal_07000201_format->Client_ID[0]),6);
    
    //Far_Deal_07000201_format->psw_stat_word = Pre_Payment_Para.Far_Key_StatusByte;
    //Reverse_data((unsigned char *)&(Far_Deal_07000201_format->psw_stat_word), 4);
    if( Get_File_Data(ESAM,ESAM_PASSWORD_INF_FILE,0,4, (unsigned char *)&Far_Deal_07000201_format->psw_stat_word) != OK ) {
        return ERR;
    }
    Reverse_data((unsigned char *)&Far_Deal_07000201_format->psw_stat_word, 4);

    
	Far_Identity_Auth_Ok_Flag=0;
    R_ID_Remain_Time = 0;
	Esam_PowOff();
//	cpucard_serial_release();
	
	Co.c.len = LENGTH_FAR_DEAL_07000201_FORMAT;
	return OK;
	}
/*"**************************************************************************"*/
/*" �����֤ʧЧ"*/
/*" ֧��07000201 "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
unsigned char Far_Deal_070002FF(unsigned char * Data_Point )
	{
	return Far_Deal_07000201(Data_Point);
	}

#define FILE_NUM        0  /*" �ļ���� "*/
#define FILE_DATA_OFF   1  /*" ƫ�Ƶ�ַ "*/
#define WRITE_DATA_OFF  3  /*" д������� "*/
/*" ����д��Ϣ�ļ� "*/
unsigned char Far_Deal_write_info_file(unsigned char * Data_Point)
{
    unsigned char file, ok;
    unsigned int off;
    unsigned char dat_len;

    file = Data_Point[FILE_NUM];
    off = Data_Point[FILE_DATA_OFF] | (Data_Point[FILE_DATA_OFF + 1] << 8);
    dat_len = CurrPC->len - LENGTH_FAR_645_FRAME_0X03 - 7;/*" �ļ���� ƫ�Ƶ�ַ MAC �ϼ�7�ֽ� "*/

    if (Select_File(0, 0, file) != OK) {
        return ERR;
    }
    Reverse_data(Data_Point + WRITE_DATA_OFF, dat_len);/*"���ݷ�ת"*/
    Reverse_data(Data_Point + WRITE_DATA_OFF + dat_len, 4);/*"MAC��ת"*/
    //ok = Write(0x04, Update_Binary, (unsigned char)off, (unsigned char)(off>>8), dat_len + 4, Data_Point + WRITE_DATA_OFF);
    ok = Write(0x04, Update_Binary, (unsigned char)(off>>8), (unsigned char)off, dat_len + 4, Data_Point + WRITE_DATA_OFF);
    if (ok != OK) {
        return ERR;
    }
/*
    if(Far_Write_Esam(0x04, Update_Binary, 0x80 + file, off, dat_len, Data_Point + WRITE_DATA_OFF, 0) != OK) {
		return ERR;
    }
*/
    Co.c.len = 0;
    return OK;
}

#if 0
/*" ����д��Ϣ�ļ� "*/
unsigned char Far_Deal_070005FF(unsigned char * Data_Point )
{
    unsigned char file;
    unsigned int off;
    unsigned char dat_len;
    unsigned char ok;
    unsigned char plain_len; 

    file = Data_Point[FILE_NUM];
    off = Data_Point[FILE_DATA_OFF] | (Data_Point[FILE_DATA_OFF + 1] << 8);
    dat_len = CurrPC->len - LENGTH_FAR_645_FRAME_0X03 - 7;/*" �ļ���� ƫ�Ƶ�ַ MAC �ϼ�7�ֽ� "*/

    if (Select_File(0, 0, file) != OK) {
        return ERR;
    }
    
    Reverse_data(Data_Point + WRITE_DATA_OFF, dat_len);/*"���ݷ�ת"*/
    Reverse_data(Data_Point + WRITE_DATA_OFF + dat_len, 4);/*"MAC��ת"*/
    ok = Write(0x04, Update_Binary, (unsigned char)(off>>8), (unsigned char)off, dat_len + 4, Data_Point + WRITE_DATA_OFF);
    if (ok != OK) {
        return ERR;
    }

    Co.c.len = 0;    
    return OK;
}
#endif

/*"**************************************************************************"*/
/*" ����
/*" ֧��070101FF "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Deal_070101FF_format
	{
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned char BagMoney_Mac[4];
	unsigned char Client_ID[6];
	unsigned char Client_ID_Mac[4];
	};
#define LENGTH_FAR_DEAL_070101FF_FORMAT      sizeof(struct Far_Deal_070101FF_format)
unsigned char Far_Deal_070101FF(unsigned char * Data_Point )
{
    unsigned char Client_ID[6];
	struct Far_Deal_070101FF_format * Far_Deal_070101FF_format;
	struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		HANG_ERR_DEFINE = 1;
		return ERR;
	}

	if(!MACRO_LOCAL_PAY_FLAG)
		return ERR;

    if (!O1ther_Meter_Parameter.WorkRoomState && is_test_psw_status()) {
        return ERR;
    }

	Far_Deal_070101FF_format = (struct Far_Deal_070101FF_format *)Data_Point;

    /*" �Ѿ���������Ҫ�жϿͻ�����Ƿ�һ�� "*/
    if (STATUS_FAROPEN_DEFINE || STATUS_LOCALOPEN_DEFINE) {
        if(Far_Read_Esam(04,Read_Binary,0x80+ESAM_PARA_INF_FILE,CLIENT_ID_ESAM, 6, 0)!=OK) {
            return ERR;
        }
        My_memcpyRev(Client_ID, receive_send_buffer, 6);
        if (My_Memcmp(Far_Deal_070101FF_format->Client_ID, Client_ID, 6) != 0) {
            CLIENT_ID_ERR_DEFINE = 1;
            return ERR;
        }
    }

    if( Far_Deal_070101FF_format->Buy_Count != 0 &&  Far_Deal_070101FF_format->Buy_Count != 1) {
        BUY_COUNT_ERR_DEFINE = 1;
        return ERR;
    }

	//if(Pre_Payment_Para.Meter_Run_State != 0)
	//	return ERR;
 
	if( Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data) != OK ) {
        ESAM_AUTH_ERR_DEFINE = 1;
		return ERR;
	}

    if (Far_Deal_070101FF_format->Buy_Count != Moneybag_Data.Buy_Count) {
        if( Far_Deal_070101FF_format->Buy_Count != (Moneybag_Data.Buy_Count + 1)) {
            //press_card_state = FAY_PASS_INC_ERR;
            BUY_COUNT_ERR_DEFINE = 1;
            //far_press_state = FAR_OPEN_ACCOUNT_BUY_CNT_ERR;
            return ERR;
        }
        /*" �жϱ��ι���Ķڻ�����  "*/
    	if( Judge_Remain_Money_Over( Far_Deal_070101FF_format->Remain_Money ) != OK ) {
    		BUY_MONEY_OVER_ERR_DEFINE=1;
            //far_press_state = FAR_RECHARGE_MONEY_OVER;
    		return ERR;
        }

        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Remain_Money), 4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Buy_Count), 4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->BagMoney_Mac[0]), 4);
        /*" ��ֵ���8432010c14+4�ֽڹ�����+4�ֽڹ������+4�ֽ�MAC+��ɢ���ӡ� "*/
        if( Write(0x84,Increase,0x01,0x0C,0x0C,((unsigned char *)&Far_Deal_070101FF_format->Remain_Money)) != OK) {
            return ERR;
        }
        
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Remain_Money),4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Buy_Count),4);
        Meter_Money_And_Count_Updata(Far_Deal_070101FF_format->Remain_Money,Far_Deal_070101FF_format->Buy_Count );
		PAY_BUY_MONEY_FLG_DEFINE=1;	/*"��Ѹı��ǿ�Ʊ���"*/
    }
	
    /*" �����û��� "*/
	if( Far_Write_Esam(0x04,Update_Binary,0x80+ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,0x06,(Far_Deal_070101FF_format->Client_ID),0)!=OK) {
		return ERR;
	}
	
	STATUS_FAROPEN_DEFINE = 1;
	Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
			(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	
    /*" ���»��źͱ��״̬ "*/
	My_memcpyRev(Pre_Payment_Para.UserID,Far_Deal_070101FF_format->Client_ID,6);
	Pay_EE_W(USERID_EE,(unsigned char *)&(Pre_Payment_Para.UserID[0]),6,3,
		          (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	Pre_Payment_Para.Meter_Run_State = 0x03;
	Pay_EE_W(METER_RUN_STATE_EE,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
		           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	Co.c.len = 0;
	return OK;
}

/*"**************************************************************************"*/
/*" ��ֵ"*/
/*" ֧��070102FF
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Deal_070102FF_format
	{
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned char BagMoney_Mac[4];
	unsigned char Client_ID[6];
	unsigned char Client_ID_Mac[4];
	};
#define LENGTH_FAR_DEAL_070102FF_FORMAT      sizeof(struct Far_Deal_070102FF_format)
unsigned char Far_Deal_070102FF(unsigned char * Data_Point )
	{
	struct Far_Deal_070102FF_format  * Far_Deal_070102FF_format;
	struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		HANG_ERR_DEFINE = 1;
		return ERR;
	}

	if(!MACRO_LOCAL_PAY_FLAG)
		return ERR;
    
    if (!O1ther_Meter_Parameter.WorkRoomState && is_test_psw_status()) {
        return ERR;
    }

	if( Pre_Payment_Para.Meter_Run_State!=3 ) 	
		return ERR;

	if( Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data) != OK )
		return ERR;

	Far_Deal_070102FF_format = (struct Far_Deal_070102FF_format  *)Data_Point;

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Client_ID[0]),6);

	if( My_Memcmp(Pre_Payment_Para.UserID,&Far_Deal_070102FF_format->Client_ID[0],6) != 0 )
		{
		CLIENT_ID_ERR_DEFINE = 1;
		return ERR;
		}

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Client_ID[0]),6);

	CPU_ESAM_CARD_Control(ESAM);
	if( Far_Write_Esam(0x04,Update_Binary,0x80+ESAM_PARA_INF_FILE,CLIENT_ID_ESAM,0x06,(Far_Deal_070102FF_format->Client_ID),0)!=OK)
		return ERR;

	if( Far_Deal_070102FF_format->Buy_Count == Moneybag_Data.Buy_Count)
		{
		REPEAT_INCREASE_ERR_DEFINE = 1;
		return ERR;
		}
	
	if( Far_Deal_070102FF_format->Buy_Count != (Moneybag_Data.Buy_Count+1))
		{
		BUY_COUNT_ERR_DEFINE = 1;
		return ERR;
		}

	/*" �жϱ��ι���Ķڻ�����  "*/
	if( Judge_Remain_Money_Over(Far_Deal_070102FF_format->Remain_Money) != OK )
		{
		BUY_MONEY_OVER_ERR_DEFINE=1;
		return ERR;
		}

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Remain_Money),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Buy_Count),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->BagMoney_Mac[0]),4);

	if( Write(0x84,Increase,0x01,0x0C,0x0C,((unsigned char *)&Far_Deal_070102FF_format->Remain_Money))!=OK)
		{
		return ERR;
		}
    /*" ������� ���� ʣ���� + ���ν��׽�� "*/
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Remain_Money),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Buy_Count),4);
	Meter_Money_And_Count_Updata(Far_Deal_070102FF_format->Remain_Money,Far_Deal_070102FF_format->Buy_Count );
	PAY_BUY_MONEY_FLG_DEFINE=1;	/*"��Ѹı��ǿ�Ʊ���"*/

	Co.c.len = 0;
	return OK;
	}

/*"**************************************************************************"*/
/*" Ǯ����ʼ�� "*/
/*" ֧��070103FF "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Deal_070103FF_format
{
	unsigned long	Remain_Money;
	unsigned char   Remain_Mac1[4];
	unsigned long	Buy_Count;
	unsigned char   Buy_Count_Mac[4];
};
#define LENGTH_FAR_DEAL_070103FF_FORMAT      sizeof(struct Far_Deal_070103FF_format)
unsigned char Far_Deal_070103FF(unsigned char * Data_Point )
{
    struct Far_Deal_070103FF_format *data;
    struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
		HANG_ERR_DEFINE = 1;
		return ERR;
	}
    
    if (MACRO_LOCAL_PAY_FLAG == 0) {/*"���Ǳ��طѿر�"*/
        return ERR;
    }

    if ((!O1ther_Meter_Parameter.WorkRoomState)&&Pre_Payment_Para.Far_Key_StatusByte) {/*"������������Կ״̬Ϊ0(������Կ)�½���"*/
        return ERR;
    }
    data = (struct Far_Deal_070103FF_format *)Data_Point;
    if (data->Buy_Count != 0) {
        BUY_COUNT_ERR_DEFINE = 1;
        return ERR;
    }

    Reverse_data((unsigned char *)&(data->Remain_Money),4);
    Reverse_data((unsigned char *)&(data->Remain_Mac1[0]),4);
    Reverse_data((unsigned char *)&(data->Buy_Count),4);
    Reverse_data((unsigned char *)&(data->Buy_Count_Mac[0]),4);
    CPU_ESAM_CARD_Control(ESAM);
    if( Write(0x04,0xDC,0x01,0x0C,0x08,((unsigned char *)&data->Remain_Money))!=OK)
    {
        return ERR;
    }

    data->Buy_Count = 0;    /*" ��������̶�Ϊ0 "*/
    if( Write(0x04,0xDC,0x03,0x0C,0x08,((unsigned char *)&data->Buy_Count))!=OK)
    {
        return ERR;
    }
    Reverse_data((unsigned char *)&(data->Remain_Money),4);
    Reverse_data((unsigned char *)&(data->Buy_Count),4);        

    /*" QQQ ����<DL-T 645-2007 ͨ��Э��-�޶�20121012.doc>  ����һϵ�в����ο����ǲ���Ԥ�ÿ��Ĳ���"*/
    /*" ʣ���ѣ��ϴι���Ѻ��ۼƹ���ѣ����������ʼ�� "*/
    //Read_Esam_Moneybag_File((unsigned char * )&Moneybag_Data);
    Clear_all_oper_code = CurrPC->Programer_code;
    memcpy(&oprateCode[0], (unsigned char *)&Clear_all_oper_code, 4);
	clearFlag=0;
	Pay_Money_Clear();
    Pay_Data_All_Clear();
    clearFlag = 3;	/*"����ظ���ִ�е��������У�����ѿ�����"*/

    Pre_Power_Down_Save_Data.Remain_Money = 0;
    Meter_Money_And_Count_Updata(data->Remain_Money, data->Buy_Count );

    Set_which_Responsion_Flag(0, 0xff);

//  Pre_Power_Down_Save_Data.Remain_Money = Moneybag_Data.Remain_Money;
//  Pre_Payment_Data.Total_Buy_Money=( unsigned long long )Moneybag_Data.Remain_Money;
//  Pre_Payment_Data.Last_Buy_Money=Moneybag_Data.Remain_Money;
//  Pay_EE_W(LAST_BUY_MONEY_EE,(unsigned char*)&Pre_Payment_Data.Last_Buy_Money,12,3,
//             (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
//  Pre_Payment_Para.Buy_Count = Moneybag_Data.Buy_Count;
//  Pay_EE_W(BUY_COUNT_EE,(unsigned char *)&(Pre_Payment_Para.Buy_Count),4,3,
//                     (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
//  Pay_For_Data_Save();

    //Pre_Payment_Para.Para_Card_Version=0;
    //Pay_EE_W(PARA_CARD_VERSION_EE,(unsigned char *)&(Pre_Payment_Para.Para_Card_Version),4,3,
    //           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    Pre_Payment_Para.Meter_Run_State=0;
    Pay_EE_W(METER_RUN_STATE_EE,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
               (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	/*"��ʼ���ɹ������ʣ���Ѻ�͸֧����޶Ϊ0�����բ�����������Զ���բ"*/
	//if (Pre_Power_Down_Save_Data.Remain_Money || Pre_Payment_Para.Remain_Money_Tick_Limit)
	//	SWITCH_ALLOW_CLOSE_DEFINE=1;
	if( REMAIN_MONEY_OVER_CLUB_DEFINE )
	{
		REMAIN_MONEY_OVER_CLUB_DEFINE = 0;
		Pay_EE_W(PAY_FOR_USERS_FLAG13_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		           (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		Relay_Alarm_SWitch_Flag[0][0] &= 0xEF;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xEF;
	}
	Remain_Money_Alarm_Judge();	/*"��Ҫ��բ�ı�־������"*/
	Card_Alarm_Switch();		/*"�������բ��־"*/

    Co.c.len = 0;
	return OK;
}

/*"**************************************************************************"*/
/*" ��Կ����(2012�����±�׼)"*/
/*" ֧��070301FF "*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------
struct Far_Deal_070301FF_format
{
	unsigned char sum;      /*" ��Կ������ "*/
    unsigned char rsv;      /*" ���� "*/
    unsigned char number;   /*" ��Կ��� "*/
    unsigned char status;   /*" ��Կ״̬��־λ (00-����״̬��01-��ʽ״̬) "*/
	unsigned char PassWord[32];
};
#define LENGTH_FAR_DEAL_070301FF_FORMAT      sizeof(struct Far_Deal_070301FF_format)

/*" ���������Կ������Ϣ����ʼ��������Կ���³���ʱ��Ҫ����,Ҫ��Կ���µĻ���Ҫ��ͷ���� "*/
void clear_psw_upd_info(void)
{
    unsigned long upd_flg;
    unsigned char pwd_stat;
    unsigned char seq_num;

    upd_flg = 0;
    pwd_stat = 0;
    seq_num = 0;
    WRLC256(UPD_PSW_FLG, (unsigned char *)(&upd_flg), 4, 0, OP_WR);
    //WRLC256(UPD_PSW_STAT, (unsigned char *)(&pwd_stat), 1, 0, OP_WR);
   // WRLC256(UPD_SEQ_NUM, (unsigned char *)(&seq_num), 1, 0, OP_WR);
}

/*" �ж��Ƿ��ڲ�����Կ״̬ "*/
/*" ����ֵ: 1(������Կ״̬)��0(��ʽ��Կ״̬) "*/
unsigned char is_test_psw_status(void)
{
    unsigned long psw_msk;

    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);

    if ((Pre_Payment_Para.Far_Key_StatusByte & psw_msk) == psw_msk) {
        return 0;
    } else {
        return 1;/*"����һ����Կ���ڲ���״̬����ʾ����״̬"*/
    }
}

/*" ����ռ�����Կ��Ϣ�Ƿ���Ч "*/
unsigned char check_collected_psw_info(void)
{
    unsigned char i;
    unsigned char ret;
    unsigned char status;
    struct Far_Deal_070301FF_format  *p_psw_info;
    unsigned char psw_data[4];

    status = 0;
    ret = OK;
    p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
    
    for (i = 0; i < Pre_Payment_Para.PassWord_Num; i++) {
		WRLC256(UPD_PSW_INFO_EE + i * SZ_PSW_INFO_MAC, psw_data, 4, 0, OP_RD);
        if (i == 0) {
            status = p_psw_info->status;
        }
        if (p_psw_info->status != status || p_psw_info->sum != Pre_Payment_Para.PassWord_Num
            || p_psw_info->number != i) {
            ret = ERR;
            break;
        }
    }

    return ret;
}


unsigned char updata_all_psw_info(void)
{
    unsigned char i;
    unsigned char para2;
    unsigned char psw_data[SZ_PSW_INFO_MAC];
    struct Far_Deal_070301FF_format  *p_psw_info;
    unsigned long upd_flg;
    unsigned long psw_msk;

    if (check_collected_psw_info() != OK) {
        return ERR;
    }

	My_Memcpy(&Co.b[500],(unsigned char *)&Pre_Payment_Para.Far_Key_StatusByte,4);	/*"��Կ����ǰ״̬"*/
    CPU_ESAM_CARD_Control(ESAM);
    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);
    p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
    for (i = 0; i < Pre_Payment_Para.PassWord_Num; i++) {
		WRLC256(UPD_PSW_INFO_EE + i * SZ_PSW_INFO_MAC, psw_data, SZ_PSW_INFO, 0, OP_RD);
        p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
        /*"������Կ���84d401FF20+��Կ"*/
        if (i == 0) {
            para2 = 0;
        } else {
            para2 = 0xFF;
        }
        if (Write(0x84,Write_Key,0x01,para2,32, psw_data + 4) != OK) {
            if (i != 0) {
                break;
            }
        }

        /*" ���¶�Ӧ��Կ��״̬λ "*/
        if (p_psw_info->status) {
            Pre_Payment_Para.Far_Key_StatusByte |= (0x1UL << i);
            //NEW645Meter_States.psw_status_word |= (0x1 << i);

        } else {
            Pre_Payment_Para.Far_Key_StatusByte &= ~(0x1UL << i);
            //NEW645Meter_States.psw_status_word &= ~(0x1 << i);
        }
    }
    /*"QQQ ���������Ӧ�ý�EEPROM����Ϣ����� "*/
    clear_psw_upd_info();

    /*" ������Կ״̬ "*/
    if (Pre_Payment_Para.psw_status != p_psw_info->status) {
        //Far_Identity_Auth_Ok_Flag = 0;/*"���������Կ���º��ַ���һ������������Բ��������֤ʧЧ"*/
        //R_ID_Remain_Time = 0;
        Pre_Payment_Para.psw_status = p_psw_info->status;
        Pay_EE_W(PSW_STATUS_EE,(unsigned char *)&(Pre_Payment_Para.psw_status),1,3,
                    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    }
    Pre_Payment_Para.Far_Key_StatusByte &= psw_msk;
    write_psw_status_wd_to_esam(Pre_Payment_Para.Far_Key_StatusByte);
    Pay_EE_W(FAR_KEY_STATUSBYTE_EE,(unsigned char*)&Pre_Payment_Para.Far_Key_StatusByte,4,3,
        (unsigned char*)&Pre_Payment_Para,LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

    Pre_Payment_Data.Far_Key_Updata_Count++;
    if (Pre_Payment_Data.Far_Key_Updata_Count>999999)
        Pre_Payment_Data.Far_Key_Updata_Count=0;
    Pay_EE_W(Far_Key_Updata_Count_EE,(unsigned char*)&Pre_Payment_Data.Far_Key_Updata_Count,4,3,(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE); 
    Pay_For_Event_Dot((const unsigned char *)&Far_Key_Updata_Event);
    	if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x80) 
    	{
       EventReportState_Expand(1, 7, 0);  
      Save_EventReportTimes(PSWUPDATE_TIMES_ROM, (unsigned char *)&Event_Report_Status_Times.PSWUpdate_times);
    	}
        FeedWatchdog();
        
    return OK;
}

/*" ����Ƿ�Ҫ������Կ���£�����Ҫ����� "*/
unsigned char check_and_update_psw_to_esam(void)
{
    unsigned long upd_flg;
    unsigned long psw_msk;
    unsigned char ret;

	if (IntoPowerDownFlag)
		return OK;

    ret = OK;
    if (TO_UPD_PSW_DEFINE) {
        CPU_ESAM_CARD_Control(ESAM);
        Cpucard_Serial_Init();
        if (Far_Identity_Auth_Ok_Flag == 0) {
            ret = Esamcard_Atr();
        }
        ret = updata_all_psw_info();
        cpucard_serial_release();
        
        TO_UPD_PSW_DEFINE = 0;
        Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
               (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    }
    
    return ret;
}

#if 0
/*" ��Ч�ڿ��еĲ���������Կ������Ϣ "*/
void invalid_psw_upd_flag(void)
{
    unsigned long old_upd_flg;  
    unsigned long psw_msk;

    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);
    WRLC256(UPD_PSW_FLG, (unsigned char *)(&old_upd_flg), 4, 0, OP_RD);
    if (old_upd_flg != 0 && old_upd_flg != psw_msk) {
        old_upd_flg = 0;
        WRLC256(UPD_PSW_FLG, (unsigned char *)(&old_upd_flg), 4, 0, OP_WR);
    }
}
#endif

unsigned char Far_PassWord_Updata_all(unsigned char *Data_Point)
{
    struct Far_Deal_070301FF_format  *psw_upd_info;
    unsigned char PassWord_Inf[4],PassWord_Inf_T,Addr_Ctrl,ClearVerFlg;
    unsigned char i, j;
    unsigned char buf[48];
    unsigned char *psw_info;
    unsigned char num_cur;/*"��ǰ����´�����Կ����"*/
    unsigned char *psw_data;
    unsigned long upd_flg;
    unsigned char pwd_stat;/*"����ȫ����Կ״̬"*/
    unsigned long psw_msk;

    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);

    psw_upd_info  =  (struct Far_Deal_070301FF_format  *)Data_Point;
    //Get_File_Data(ESAM,ESAM_FAR_PASSWORD_INF_FILE,0,4,&PassWord_Inf[0]);

    num_cur = (CurrPC->len - 8 - 4) / SZ_PSW_INFO; /*" 8�ֽڵ����ݱ�ʶ�������ߴ��룻4�ֽڵ�MAC "*/
    if (num_cur == 0) {
        return ERR;  
    }
    for (i = 0; i < num_cur; i++) {
        Reverse_data((unsigned char *)&psw_upd_info[i], 36);
    }
    Reverse_data((unsigned char *)(psw_upd_info + i), 4);/*" MAC��ת "*/
    
    pwd_stat = psw_upd_info[0].status;

#if 0
    /*" �����������Կ������������е���Կ��������һ�� "*/
    if (psw_upd_info->sum != Pre_Payment_Para.PassWord_Num) {/*"Pre_Payment_Para.PassWord_Num�ĳ�ʼ��"*/
        clear_psw_upd_info();
        press_card_state = FAY_PASS_MODFIY_ERR;
        displayCharTimeLen(DISP_IC_ERR,10,0);
        return ERR; 
    }

    if (seq_num != psw_upd_info[0].number) {/*"��ʾ������"*/
        clear_psw_upd_info();
        press_card_state = FAY_PASS_MODFIY_ERR;
        displayCharTimeLen(DISP_IC_ERR,10,0);
        return ERR; 
    }
#endif  
    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = 0;
    }

    psw_info = buf + 8;
    for (i = 0; i < num_cur; i++) {
        /*" �����и�����Կ����Կ״̬λ�Ƿ�һ�� �Լ� ��Կ��� ˳���Ƿ��  "*/
        if (psw_upd_info[i].status != pwd_stat || psw_upd_info[i].sum != Pre_Payment_Para.PassWord_Num
            || psw_upd_info[i].number >= Pre_Payment_Para.PassWord_Num) {
            //clear_psw_upd_info();
            //press_card_state = FAY_PASS_MODFIY_ERR;
            //displayCharTimeLen(DISP_IC_ERR,10,0);
            return ERR;     
        }
        /*" ������� "*/
        for(j=0; j<SZ_PSW_INFO; j++) {
			psw_info[j] ^= *((unsigned char *)(&psw_upd_info[i]) + j);
		}
#if 0
        seq_num++;
        if (seq_num > Pre_Payment_Para.PassWord_Num) {/*" ���µ���Կ������������Կ���������� "*/
            clear_psw_upd_info();
            press_card_state = FAY_PASS_MODFIY_ERR;
            displayCharTimeLen(DISP_IC_ERR,10,0);
            return ERR; 
        }
#endif
    }

    My_Memcpy(psw_info + SZ_PSW_INFO, (unsigned char *)(psw_upd_info + i), 4);/*" 4���ֽڵ�MAC������� "*/
    
    //My_Memcpy(buf, (unsigned char *)&Far_Identity_Auth_Data.Instruction.disperse_gene[0], 8);
    //if (SWITCH_ERR_DEFINE && (!pwd_stat))					//test	/*"����ǲ���ESAM,�ָ���Կʱ��1��ɢ"*/
	//    buf[7]=1;
    //else
	My_Memcpy(buf+2, (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
    /*" ����MACУ�� "*/
    CPU_ESAM_CARD_Control(ESAM);
    if (Write(0x04,Update_Binary,0x96,0x00,0x30,buf) != OK) {
		if (pwd_stat == 0)
		{
			My_Memcpy(buf, 0, 8);
			buf[7] = 1;
			if (Write(0x04,Update_Binary,0x96,0x00,0x30,buf) != OK)
			{
				ESAM_AUTH_ERR_DEFINE = 1;
	        	return ERR;	
			}
		}
		else
		{
	        ESAM_AUTH_ERR_DEFINE = 1;
	        return ERR;
		}
    }

    /*" У��ͨ��������Կ�������� "*/
    WRLC256(UPD_PSW_FLG, (unsigned char *)(&upd_flg), 4, 0, OP_RD);
    for (i = 0; i < num_cur; i++) {
        //My_Memcpy(psw_info, (unsigned char *)(psw_upd_info + i), SZ_PSW_INFO);/*"���psw_info�����4�ֽ��Ѿ���������ε�MAC��Ϣ"*/
		WRLC256(UPD_PSW_INFO_EE + psw_upd_info[i].number * SZ_PSW_INFO_MAC, (unsigned char *)(&psw_upd_info[i]), 36, 0, OP_WR);/*"���浽��Ӧ��eepromλ��(ÿ����MAC�������MAC)"*/
        upd_flg |= (1UL << psw_upd_info[i].number);
    }
    WRLC256(UPD_PSW_FLG, (unsigned char *)(&upd_flg), 4, 0, OP_WR);
    if ((upd_flg == psw_msk) && (check_collected_psw_info() == OK)) {
        TO_UPD_PSW_DEFINE = 1;
        Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
               (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
    }

    Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
        (unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
    
    /*"������Կ�����ò���֤�ò�һ���Ը���"*/
    //if (check_and_update_psw_to_esam() == ERR) {
    //    return ERR;
    //}
    
    Co.c.len = 0;
    return OK;
}

/*" ����������֤ "*/
void end_infrared_auth(void)
{
    Far_InfraredFlag = 0;
    Far_Infrared_Auth_Ok_Time = 0;
    R_Infrared_Remain_Time = 0;
}

/*" ������֤���� "*/
unsigned char Far_Deal_07800301(unsigned char *Data_Point)
{
    unsigned char ret;

    end_infrared_auth();
    My_memcpyRev(far_data_p+14,Meter_Parameter.parameter2.BcdMeterID,6);     /*"���"*/


    CPU_ESAM_CARD_Control(ESAM);      /*"����ͨ��ESAM��"*/
    if (read_esam_serial_num(esam_number) != OK ) {
    	return ERR;
    }
    My_memcpyRev(far_data_p+20,esam_number,8);     /*" ת��ESAM���к� "*/

    Card_WR_Buff[0] = 0;
    Card_WR_Buff[1] = 0;
    My_Memcpy(&Card_WR_Buff[2], &Meter_Parameter.parameter2.BcdMeterID[0], 6);

	ret = Internal_Auth(0x80,0xfa,0,3,8, Card_WR_Buff); /*"��ɢESAM ��Կ"*/
    if (ret != OK) {
        ESAM_AUTH_ERR_DEFINE = 1;
        return ERR;
    }

    Reverse_data(Data_Point, 8);
	ret = Internal_Auth(0x80,0xfa,0,0,8,Data_Point); /*" �õ�ESAM��������� "*/
    if (ret != OK) {
        ESAM_AUTH_ERR_DEFINE = 1;
        return ERR;
    }
    My_memcpyRev(far_data_p+28,receive_send_buffer,8);     /*" ת�������1����K1 "*/

    /*"��ȡESAM����� Rand2"*/
	if( Read(0,Get_Challenge,0,0,8) != OK ) {
    	return ERR;
	}
    My_memcpyRev(far_data_p+36,receive_send_buffer,8);     /*" ת�������2 "*/

    Co.c.len = 30;
    return OK;
}

/*" ������ָ֤�� "*/
unsigned char Far_Deal_07000301(unsigned char *Data_Point)
{

    if (IntoPowerDownFlag) {
		return ERR;
	}
    Reverse_data(Data_Point, 8);
    if (External_Auth(8, 8, Data_Point) != OK) {
        ESAM_AUTH_ERR_DEFINE = 1;
    	return ERR;
    }
    
    Far_InfraredFlag = 1;
    Far_Infrared_Auth_Ok_Time = GetNowTime();
    R_Infrared_Remain_Time = Pre_Payment_Para.InfrIdenTime;

    /*" ������֤�������֤ʧЧ "*/
    Far_Identity_Auth_Ok_Flag = 0;
    R_ID_Remain_Time = 0;
    
    Co.c.len = 0;
    return OK;
}



/*"����Ҫ�Ƚϵĵ�һ���������ֹ��ַ"*/
#define SKIP_ADDR1_START    0xE000UL
#define SKIP_ADDR1_END      0x14000UL

/*"����Ҫ�Ƚϵĵڶ����������ֹ��ַ"*/
#define SKIP_ADDR2_START    0xC0000UL   
#define SKIP_ADDR2_END      0x100000UL

/*"����ռ��С"*/
#define CODE_SPACE_SZ       0x100000UL   

#define FACTOR_NEED_LEN     16
#define DATA_NEED_LEN       256

static unsigned char check_compare_addr(unsigned long factor_addr, unsigned long data_addr)
{
    /*" ����ռ�ֻ��: 0x10000 - 0x14000; 0xc0000 - 0xffe00 "*/
    if ( ((factor_addr >= SKIP_ADDR1_START && factor_addr < SKIP_ADDR1_END) || (factor_addr >= SKIP_ADDR2_START && factor_addr < SKIP_ADDR2_END)) 
        && ((data_addr >= SKIP_ADDR1_START && data_addr < SKIP_ADDR1_END) || (data_addr >= SKIP_ADDR2_START && data_addr < SKIP_ADDR2_END)) ){
        return OK;
    } else {
        return ERR;
    }
/*"���������factor_addr��data_addr��Ϊ0"*/
#if 0
    if ((factor_addr >= SKIP_ADDR1_START && factor_addr <= SKIP_ADDR1_END)
        || (factor_addr >= SKIP_ADDR2_START && factor_addr <= SKIP_ADDR2_END)) {
        return ERR;
    }
    
    if ((data_addr >= SKIP_ADDR1_START && data_addr <= SKIP_ADDR1_END)
        || (data_addr >= SKIP_ADDR2_START && data_addr <= SKIP_ADDR2_END)) {
        return ERR;
    }   
#endif
}


/*"  ������ȶ����� "*/
unsigned char Far_Deal_078002FF(unsigned char * Data_Point)			
{
    unsigned int i, j;
    unsigned char ok, ret;
    unsigned char psw_idx;
    unsigned long factor_addr;
    unsigned long data_addr;
    unsigned char factor[16];
    unsigned int factor_rd_len;
    unsigned int data_rd_len;

    psw_idx = Data_Point[1];
    factor_addr = (unsigned long)Data_Point[2] | (((unsigned long)Data_Point[3])<<8) | (((unsigned long)Data_Point[4])<<16) | (((unsigned long)Data_Point[5])<<24);
    data_addr = (unsigned long)Data_Point[6] | (((unsigned long)Data_Point[7])<<8) | (((unsigned long)Data_Point[8])<<16) | (((unsigned long)Data_Point[9])<<24);

    if (check_compare_addr(factor_addr, data_addr) != OK) {
        SERR_ADDR_ERR_DEFINE = 1;
        return ERR;    
    }

    factor_rd_len = FACTOR_NEED_LEN;
/*
    if ((factor_addr + FACTOR_NEED_LEN - 1 >= SKIP_ADDR2_START) && (factor_addr < SKIP_ADDR2_START)) {
        factor_rd_len = SKIP_ADDR2_START - factor_addr;
    }
*/

    if (((factor_addr + FACTOR_NEED_LEN - 1) >= SKIP_ADDR1_END) && (factor_addr < SKIP_ADDR1_END)) {
        factor_rd_len = SKIP_ADDR1_END - factor_addr;
    }
	if (((factor_addr + FACTOR_NEED_LEN - 1) >= SKIP_ADDR2_END) && (factor_addr < SKIP_ADDR2_END)) {
        factor_rd_len = SKIP_ADDR2_END - factor_addr;
    }

    data_rd_len = DATA_NEED_LEN;
/*
    if ((data_addr + DATA_NEED_LEN - 1 >= SKIP_ADDR2_START) && (data_addr < SKIP_ADDR2_START)) {
        data_rd_len = SKIP_ADDR2_START - data_addr;
    }
*/
    if (((data_addr + DATA_NEED_LEN - 1) >= SKIP_ADDR1_END) && (data_addr < SKIP_ADDR1_END)) {
        data_rd_len = SKIP_ADDR1_END - data_addr;
    }
	if (((data_addr + DATA_NEED_LEN - 1) >= SKIP_ADDR2_END) && (data_addr < SKIP_ADDR2_END)) {
        data_rd_len = SKIP_ADDR2_END - data_addr;
    }

    ret = FlashRead((FLASH_PTR_TYPE)factor_addr,(BUF_PTR_TYPE)factor, factor_rd_len);
    if (ret) {
        return ERR; 
    }
    ret = FlashRead((FLASH_PTR_TYPE)data_addr,(BUF_PTR_TYPE)Card_WR_Buff, data_rd_len);
    if (ret) {
        return ERR; 
    }
    //read_code((FLASH_PTR_TYPE)factor_addr,(BUF_PTR_TYPE)factor, factor_rd_len);
    //read_code((FLASH_PTR_TYPE)data_addr,(BUF_PTR_TYPE)Card_WR_Buff, data_rd_len);

    /*"��λ"*/
    if (factor_rd_len < FACTOR_NEED_LEN) {
        factor[factor_rd_len] = 0x80;
        for (i = factor_rd_len + 1; i<FACTOR_NEED_LEN; i++) {
            factor[i] = 0x0;
        }
    }
    /*"��λ"*/
    if (data_rd_len < DATA_NEED_LEN) {
        Card_WR_Buff[data_rd_len] = 0x80;
        for (i = data_rd_len + 1; i<DATA_NEED_LEN; i++) {
            Card_WR_Buff[i] = 0x0;
        }
    }

    for (i=0; i<8; i++) {
        factor[i] ^= factor[8 + i];
    }
    for (i=1; i<4; i++) {
        for (j=0; j<64; j++) {
            Card_WR_Buff[j] ^= Card_WR_Buff[64 * i + j];
        }
    }

    ok = Write(0x80, 0xfa, 0x00, psw_idx, 8, factor);
    if (ok != OK) {
        ESAM_AUTH_ERR_DEFINE = 1;
        return ERR;
    }

    ok = Write(0x80, 0xfa, 0x01, 0x00, 64, Card_WR_Buff);
    if (ok != OK) {
        ESAM_AUTH_ERR_DEFINE = 1;
        return ERR;
    }

    My_memcpyRev(far_data_p+14, receive_send_buffer, 64);/* ��ò�������������K1 */
    //My_Memcpy(far_data_p+14, receive_send_buffer, 64);
    Co.c.len = 64;
    return OK;
}

#if 0
unsigned char read_code(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes)
{
    unsigned int i;

    for (i = 0; i < bytes; i++) {
        buffer_addr[i] = flash_addr[i];
    }
}

#define FACTOR_NEED_LEN_NO_ESAM     256

/*"����Ƿ��������16�ֽڵ�0x00"*/
unsigned char check_is_exist_16byte_00(unsigned char *buf, unsigned int len)
{
    int num;
    int i;
    unsigned char exist;

    exist = 0;
    num = 0;
    for (i = 0 ; i < len; i++) {
        if (buf[i] == 0) {
            num++;
        } else {
            num = 0;
        }
        if (num == 16) {
            exist = 1;
            break;
        }
    }
    return exist;
}


/*"  û��ESAM�ĵ�� ����ȶ����� "*/
unsigned char Far_meter_code_compare_no_esam(unsigned char * Data_Point)			
{
    unsigned int i, j;
    unsigned char ok;
    unsigned char psw_idx;
    unsigned long factor_addr;
    unsigned long data_addr;
    unsigned char *factor;
    unsigned int factor_rd_len;
    unsigned int data_rd_len;

    psw_idx = Data_Point[1];
    factor_addr = Data_Point[2] | (Data_Point[3]<<8) | (Data_Point[4]<<16) | (Data_Point[5]<<24);
    data_addr = Data_Point[6] | (Data_Point[7]<<8) | (Data_Point[8]<<16) | (Data_Point[9]<<24);

    if (check_compare_addr(factor_addr, data_addr) != OK) {
        SERR_ADDR_ERR_DEFINE = 1;
        return ERR;    
    }

    if (psw_idx != 0) {
        return ERR; 
    }

    factor_rd_len = FACTOR_NEED_LEN_NO_ESAM;

    if ((factor_addr + FACTOR_NEED_LEN_NO_ESAM - 1 >= SKIP_ADDR2_START) && (factor_addr < SKIP_ADDR2_START)) {
        factor_rd_len = SKIP_ADDR2_START - factor_addr;
    }

    if ((factor_addr + FACTOR_NEED_LEN_NO_ESAM - 1 >= CODE_SPACE_SZ) && (factor_addr < CODE_SPACE_SZ)) {
        factor_rd_len = CODE_SPACE_SZ - factor_addr;
    }

    data_rd_len = DATA_NEED_LEN;

    if ((data_addr + DATA_NEED_LEN - 1 >= SKIP_ADDR2_START) && (data_addr < SKIP_ADDR2_START)) {
        data_rd_len = SKIP_ADDR2_START - data_addr;
    }

    if ((data_addr + DATA_NEED_LEN - 1 >= CODE_SPACE_SZ) && (data_addr < CODE_SPACE_SZ)) {
        data_rd_len = CODE_SPACE_SZ - data_addr;
    }
    
    factor = &Card_WR_Buff[256];
    FlashRead((FLASH_PTR_TYPE)factor_addr,(BUF_PTR_TYPE)factor, factor_rd_len);
    FlashRead((FLASH_PTR_TYPE)data_addr,(BUF_PTR_TYPE)Card_WR_Buff, data_rd_len);

    /*"��λ"*/
    if (factor_rd_len < FACTOR_NEED_LEN_NO_ESAM) {
        factor[factor_rd_len] = 0x80;
        for (i = factor_rd_len + 1; i<FACTOR_NEED_LEN_NO_ESAM; i++) {
            factor[i] = 0x0;
        }
    }
    
    if (check_is_exist_16byte_00(factor, FACTOR_NEED_LEN_NO_ESAM)) {
        SERR_ADDR_ERR_DEFINE = 1;
        return ERR;   
    }
    
    /*"��λ"*/
    if (data_rd_len < DATA_NEED_LEN) {
        Card_WR_Buff[data_rd_len] = 0x80;
        for (i = data_rd_len + 1; i<DATA_NEED_LEN; i++) {
            Card_WR_Buff[i] = 0x0;
        }
    }

    for (i=1; i<4; i++) {
        for (j=0; j<64; j++) {
            factor[j] ^= factor[64 * i + j];
        }
    }

    for (i=1; i<4; i++) {
        for (j=0; j<64; j++) {
            Card_WR_Buff[j] ^= Card_WR_Buff[64 * i + j];
        }
    }

    for (j=0; j<64; j++) {
        Card_WR_Buff[j] ^= factor[j];
    }


    My_memcpyRev(far_data_p+14, Card_WR_Buff, 64);/* ���ش������� */
    Co.c.len = 64;
    return OK;
}
#endif

#pragma SECTION program ROM_PRG2
/*" Ǯ���˷� "*/
unsigned char Far_Deal_Refundment(unsigned char * Data_Point)
{
    signed long money;
    unsigned char Order_Head[4];
    signed long Remain_Money;
	struct Moneybag_Data Moneybag_Data;

    if (FUN_BUY_FLAG_DEFINE == 0) {
        return ERR;
    }

    Esam_Remain_Money_Dec();
    Pre_Get_OverZero_Money();
    buyBeforMoney = Remain_Money_Plus;

    Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data);
    
    if( Far_Write_Esam(0x04,Update_Binary,0x8c,0x00,0x10,Data_Point,0) != OK) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return ERR;
    }

    if( Read(0,Read_Binary,0x8c,0,8) != OK ) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return ERR;
    }

    My_memcpyRev((unsigned char *)&money, receive_send_buffer, 4);
    My_memcpyRev(Data_Point, receive_send_buffer, 4);
    My_Memcpy(Card_WR_Buff, receive_send_buffer, 8);

    if (money > Moneybag_Data.Remain_Money) {
        return ERR;
    }

    Order_Head[0] = 0x84;
	Order_Head[1] = 0x30;
	Order_Head[2] = 0x02;
	Order_Head[3] = 0x0C;
	if( CPU_Card_Driver((const unsigned char *)&Order_Head[0],8, Card_WR_Buff,0,CommunicationPortMode,0) != OK ) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
		return ERR;
	}

    Pre_Payment_Para.SendBack_Money = money;
    /*" ���µ���е�ʣ���� "*/
    Pre_Power_Down_Save_Data.Remain_Money -= money;
    Pay_For_Data_Save();
    Pre_Get_OverZero_Money();
    
    Pre_Payment_Data.Back_Money_Count++;
    if (Pre_Payment_Data.Back_Money_Count > 999999)
        Pre_Payment_Data.Back_Money_Count = 0;
    Pay_EE_W(Back_Money_Count_EE,(unsigned char*)&Pre_Payment_Data.Back_Money_Count,4,3,(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);     
    Pay_For_Event_Dot((const unsigned char *)&Refundment_Event);
    
    FUN_BUY_FLAG_DEFINE = 0;
    Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
             (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	PAY_BUY_MONEY_FLG_DEFINE=1;	/*"��Ѹı��ǿ�Ʊ���"*/

    return OK;
}


/*"**************************************************************************"*/
/*" ��������03�Ĵ������"*/
/*" Data_Point:��:���ݸ�ʽ���� "*/
/*"            ��:���ݸ�ʽ���� "*/
//-----------------------------------------------------------------------------

struct Far_645_Frame_Flag_0x03
	{
	unsigned char Data_ID[4];
	unsigned char Source_Length;				/*" =���ݳ���+4(ID)+4(�����ߴ���) "*/
	Event_Spec_Deal_R Far_645_Order_0x03;    /*" �¼������� "*/
	};
#define LENGTH_FAR_645_FRAME_FLAG_0X03   sizeof(struct Far_645_Frame_Flag_0x03)


const struct Far_645_Frame_Flag_0x03  Far_645_Frame_Flag_0x03_List[]=
	{
	0xFF,0x01,0x80,0x07,16,Far_Deal_078001FF,/*" ���ݻس�"*/

	0x01,0x02,0x81,0x07,8,Far_Deal_07810201,/*" ״̬��ѯ "*/
	0xFF,0x02,0x81,0x07,8,Far_Deal_078102FF,/*" ״̬��ѯ "*/    

	0xFF,0x00,0x00,0x07,32,Far_Deal_070000FF,/*" �����֤"*/

	0xFF,0x01,0x00,0x07,14,Far_Deal_070001FF,/*" �����֤ʱЧ����"*/

	0x01,0x02,0x00,0x07,8,Far_Deal_07000201,/*" �����֤ʧЧ"*/
	0xFF,0x02,0x00,0x07,8,Far_Deal_070002FF,/*" �����֤ʧЧ"*/

    0xFF,0x04,0x00,0x07,0xff,Far_Deal_write_info_file,/*" ����д��Ϣ�ļ� "*/
    0xFF,0x05,0x00,0x07,0xff,Far_Deal_write_info_file,/*" ����д��Ϣ�ļ� "*/

	0xFF,0x01,0x01,0x07,30,Far_Deal_070101FF,/*" ���� "*/

	0xFF,0x02,0x01,0x07,30,Far_Deal_070102FF,/*" ��ֵ"*/


	0xFF,0x01,0x03,0x07,0xff,Far_PassWord_Updata_all,/*" ��Կ���� "*/
	
	0xFF,0x03,0x01,0x07,24,Far_Deal_070103FF,			/*" Ǯ����ʼ�� "*/

	//0x01,0x03,0x80,0x07,16,Far_Deal_07800301,			/*"������֤����"*/
	0xFF,0x03,0x80,0x07,16,Far_Deal_07800301,			/*"������֤����"*/

	//0x01,0x03,0x00,0x07,16,Far_Deal_07000301,			/*"������ָ֤��"*/
	0xFF,0x03,0x00,0x07,16,Far_Deal_07000301,			/*"������ָ֤��"*/

    0xFF,0x02,0x80,0x07,18,Far_Deal_078002FF,			/*"  ������ȶ����� "*/
    //0xFF,0x03,0x01,0x07,18,Far_Deal_Refundment,			/*"  Ǯ���˷� "*/
	
	};
#define LENGTH_FAR_645_FRAME_FLAG_LIST_0X03     sizeof(Far_645_Frame_Flag_0x03_List)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

unsigned char Far_Deal_Order_0x03(unsigned char * Data_Point ,unsigned char Source_Length)
	{
	unsigned int Length;
	unsigned char i;
	struct Far_645_Frame_Flag_0x03  Far_645_Frame_Flag_0x03;
	struct Far_645_Frame_0x03         *Far_645_Frame_0x03;

	Far_645_Frame_0x03 = (struct Far_645_Frame_0x03 *)Data_Point;

	Length = LENGTH_FAR_645_FRAME_FLAG_LIST_0X03;
	Length/=LENGTH_FAR_645_FRAME_FLAG_0X03;

	for( i=0;i<Length;i++ )
		{
		if(	(Far_645_Frame_Flag_0x03_List[i].Data_ID[0] == Far_645_Frame_0x03->Data_ID[0] )&& 
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[1] == Far_645_Frame_0x03->Data_ID[1] )&&
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[2] == Far_645_Frame_0x03->Data_ID[2] )&&
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[3] == Far_645_Frame_0x03->Data_ID[3] ) ) 
			break;
		}
	if( i==Length )
		return ERR;


	if( Source_Length != Far_645_Frame_Flag_0x03_List[i].Source_Length 
        && Far_645_Frame_Flag_0x03_List[i].Source_Length != 0xff)/*" 0xff��ʾ���ݳ��Ȳ��� "*/
		return ERR;			
	if( Far_645_Frame_Flag_0x03_List[i].Far_645_Order_0x03 !=0 )
		{
		if( Far_645_Frame_Flag_0x03_List[i].Far_645_Order_0x03(Data_Point+LENGTH_FAR_645_FRAME_0X03) == OK )
			return OK;
		}
	return ERR;
	}

/*"**************************************************************************"*/
/*" ��һ�����Զ��д������"*/
/*" ֧�ֱ�3 "*/
/*" Data_Point:��:ָ��L DI0 DI1 DI2 DI3...... "*/
/*"            ��:���ݸ�ʽ���� "*/
/*" ��������ȷ �������ݸ�ʽת������ͨд���ݸ�ʽ�����ú���д����"*/
/*" ����������ֱ�Ӵ����˳�"*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct Far_645_Frame_T1
	{
//	unsigned char Data_ID[4];
	unsigned char PassWord[4];
	unsigned char Do_man[4];
	};
#define LENGTH_FAR_645_FRAME_T1        sizeof(struct Far_645_Frame_T1 )
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct Far_Deal_Para_Flag_T1
	{
	unsigned char Data_ID[4];
	unsigned char Esam_File;
	unsigned int  Esam_Offset;
	unsigned char Esam_Length;
	};
#define LENGTH_FAR_DEAL_PARA_FLAG_T1      sizeof(struct Far_Deal_Para_Flag_T1)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#pragma SECTION rom UserROMData
const struct Far_Deal_Para_Flag_T1 Far_Deal_Para_List_T1[] = 
	{
	0x08,0x01,0x00,0x04, 0x02,TRIFF_SWITCH_TIME_ESAM,0x05,   /*"���׷�ʱ���ʵ���л�ʱ��"*/
    0x09,0x01,0x00,0x04, 0x04,GRADE_SWITCH_OFF,0x05,   /*"���׽����л�ʱ��"*/
	0x06,0x03,0x00,0x04, 0x02,CURRENT_CT_ESAM,0x03,   /*"�������������"*/
	0x07,0x03,0x00,0x04, 0x02,VOLTAGE_PT_ESAM,0x03,   /*"��ѹ���������"*/
    0x02,0x04,0x00,0x04, 0x02,METER_ID_ESAM,0x06,   /*"���"*/
	0x0E,0x04,0x00,0x04, 0x02,CLIENT_ID_ESAM,0x06,   /*"�ͻ����"*/
	0x01,0x10,0x00,0x04, 0x02,REMAIN_MONEY_ALARM1_LIMIT_ESAM,0x04,   /*"�������1��ֵ"*/
	0x02,0x10,0x00,0x04, 0x02,REMAIN_MONEY_ALARM2_LIMIT_ESAM,0x04,   /*"�������2��ֵ"*/

    //0x01,0x01,0x05,0x04, 0x03,TRIFF1_OFF,0x04,   /*"��һ�׷���1"*/
	//0x02,0x01,0x05,0x04, 0x03,TRIFF1_OFF+4,0x04,   /*"��һ�׷���2"*/
	//0x03,0x01,0x05,0x04, 0x03,TRIFF1_OFF+8,0x04,   /*"��һ�׷���3"*/
	//0x04,0x01,0x05,0x04, 0x03,TRIFF1_OFF+12,0x04,   /*"��һ�׷���4"*/
    0xFF,0x01,0x05,0x04, 0x03,TRIFF1_OFF,128,   /*"��һ�׷������ݿ�"*/

    //0x01,0x02,0x05,0x04, 0x04,TRIFF1_OFF,0x04,   /*"�ڶ��׷���1"*/
	//0x02,0x02,0x05,0x04, 0x04,TRIFF1_OFF+4,0x04,   /*"�ڶ��׷���2"*/
	//0x03,0x02,0x05,0x04, 0x04,TRIFF1_OFF+8,0x04,   /*"�ڶ��׷���3"*/
	//0x04,0x02,0x05,0x04, 0x04,TRIFF1_OFF+12,0x04,   /*"�ڶ��׷���4"*/
	0xFF,0x02,0x05,0x04, 0x04,TRIFF1_OFF,128,   /*"�ڶ��׷������ݿ�"*/

//    0xFF,0x03,0x05,0x04, 0x04,TRIFF1_OFF,128,   /*"�����׷������ݿ�(�����׾��������ף�Ҫ���⴦��)"*/
    
	//0x01,0x00,0x06,0x04, 0x03,GRADE1_OFF,0x04,       /*"��һ�׵�1����ֵ"*/
	//0x02,0x00,0x06,0x04, 0x03,GRADE1_OFF+4,0x04,     /*"��һ�׵�2����ֵ"*/
	//0x03,0x00,0x06,0x04, 0x03,GRADE1_OFF+8,0x04,     /*"��һ�׵�3����ֵ"*/
	//0x04,0x00,0x06,0x04, 0x03,GRADE1_OFF+12,0x04,    /*"��һ�׵�4����ֵ"*/
    //0x05,0x00,0x06,0x04, 0x03,GRADE1_OFF+16,0x04,     /*"��һ�׵�5����ֵ"*/
    //0x06,0x00,0x06,0x04, 0x03,GRADE1_OFF+20,0x04,    /*"��һ�׵�6����ֵ"*/
    0xFF,0x04,0x06,0x04, 0x03,GRADE1_OFF,64,    /*"��һ�׽���ֵ���ݿ�"*/

	//0x01,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF,0x04,       /*"��һ�׽��ݵ��1"*/
	//0x02,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+4,0x04,     /*"��һ�׽��ݵ��2"*/
	//0x03,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+8,0x04,     /*"��һ�׽��ݵ��3"*/
	//0x04,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+12,0x04,    /*"��һ�׽��ݵ��4"*/
    //0x05,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+16,0x04,     /*"��һ�׽��ݵ��5"*/
    //0x06,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+20,0x04,    /*"��һ�׽��ݵ��6"*/
    //0x07,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF+24,0x04,    /*"��һ�׽��ݵ��7"*/
//    0xFF,0x01,0x06,0x04, 0x03,GRADE1_PRICE_OFF,28,    /*"��һ�׽��ݵ�����ݿ�"*/

	//0x01,0x02,0x06,0x04, 0x04,GRADE1_OFF,0x04,       /*"�ڶ��׵�1����ֵ"*/
	//0x02,0x02,0x06,0x04, 0x04,GRADE1_OFF+4,0x04,     /*"�ڶ��׵�2����ֵ"*/
	//0x03,0x02,0x06,0x04, 0x04,GRADE1_OFF+8,0x04,     /*"�ڶ��׵�3����ֵ"*/
	//0x04,0x02,0x06,0x04, 0x04,GRADE1_OFF+12,0x04,    /*"�ڶ��׵�4����ֵ"*/
    //0x05,0x02,0x06,0x04, 0x04,GRADE1_OFF+16,0x04,     /*"�ڶ��׵�5����ֵ"*/
    //0x06,0x02,0x06,0x04, 0x04,GRADE1_OFF+20,0x04,    /*"�ڶ��׵�6����ֵ"*/
    0xFF,0x05,0x06,0x04, 0x04,GRADE1_OFF,64,    /*"�ڶ��׽���ֵ���ݿ�"*/

	//0x01,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF,0x04,       /*"�ڶ��׽��ݵ��1"*/
	//0x02,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+4,0x04,     /*"�ڶ��׽��ݵ��2"*/
	//0x03,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+8,0x04,     /*"�ڶ��׽��ݵ��3"*/
	//0x04,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+12,0x04,    /*"�ڶ��׽��ݵ��4"*/
    //0x05,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+16,0x04,     /*"�ڶ��׽��ݵ��5"*/
    //0x06,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+20,0x04,    /*"�ڶ��׽��ݵ��6"*/
    //0x07,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF+24,0x04,    /*"�ڶ��׽��ݵ��7"*/
//    0xff,0x03,0x06,0x04, 0x04,GRADE1_PRICE_OFF,28,    /*"�ڶ��׽��ݵ�����ݿ�"*/

    //0xFF,0x04,0x06,0x04, 0x04,GRADE1_OFF,55,      /*"�����׽��ݲ������ݿ�: �����׽���ֵ , ���ݵ��, ������"*/

	};
#define LENGTH_FAR_DEAL_PARA_LIST_T1              sizeof(Far_Deal_Para_List_T1 )

#pragma SECTION program ROM_PRG2
#if 0
/*"�����������Ƿ�Ϸ�"*/
/*"time: ������ո�ʽMMDDhh"*/
unsigned char year_bill_date_is_err(unsigned char *time)
{
    if ((time[0] == 0x99) && (time[1] == 0x99) && (time[2] == 0x99)) {
        return 0;
    }
    /*" mouth "*/
    if ((time[0] > 0x12) || (time[0] <= 0x0)) {
        return 1;
    }
    /*" day "*/
    if ((time[1] > 0x28) || (time[1] <= 0x0)) {
        return 1;
    }
    /*" hour "*/
    if (time[2] > 0x23) {
        return 1;
    }

    return 0;
}
#endif

/*"�Ƿ���һ�����"*/
unsigned char is_T1_para(unsigned char * id)
{
    unsigned char i;
    unsigned int Length;
    unsigned char res;

    Length = LENGTH_FAR_DEAL_PARA_LIST_T1;
    Length /= LENGTH_FAR_DEAL_PARA_FLAG_T1;

    res = 0;
    for(i = 0;i < Length; i++ ) {
        if( Far_Deal_Para_List_T1[i].Data_ID[0] == id[0] && 
            Far_Deal_Para_List_T1[i].Data_ID[1] == id[1] &&
            Far_Deal_Para_List_T1[i].Data_ID[2] == id[2] &&
            Far_Deal_Para_List_T1[i].Data_ID[3] == id[3] ) {
            res = 1;
            break;
        }
    }
    /*" 0xFF,0x01,0x05,0x04 "*/
    /*" 0xFF,0x02,0x05,0x04 "*/
    if ((id[1] == 0x01 || id[1] == 0x02) &&  id[2] == 0x05 && id[3] == 0x04) {
        res = 1;
    }
    //if ( &&  id[2] == 0x05 && id[3] == 0x04) {
    //   res = 1;
   // }
    /*" 0xFF,0x04,0x06,0x04 "*/
    if ((id[1] == 0x04 || id[1] == 0x05) &&  id[2] == 0x06 && id[3] == 0x04) {
        res = 1;
    }
    /*" 0xFF,0x05,0x06,0x04 "*/
    //if ( &&  id[2] == 0x06 && id[3] == 0x04) {
    //    res = 1;
    //}
    return res;
}

unsigned char is_T3_para(unsigned char * id)
{
    unsigned char res;

    res = 0;
    /*" 0x01,0x13,0x00,0x04 "*/
    if( (id[0] == 0x01 && id[1] == 0x13 &&  id[2] == 0x00 && id[3] == 0x04) ||(id[0] == 0x03 && id[1] == 0x15 &&  id[2] == 0x00 && id[3] == 0x04)) {
        res = 1;
    }
    return res;
}


unsigned char Far_Deal_Para_T1(unsigned char * ID_Point,unsigned char * Data_Point ,unsigned char *Source_Length)
{
	unsigned char i,j;
	unsigned int Length;
	struct Far_Deal_Para_Flag_T1  Far_Deal_Para_Flag_T1;
	struct Far_645_Frame_T1  * Far_645_Frame_T1;
    unsigned char *data;
    unsigned long id;
    unsigned char last;
    unsigned char *dst;

//	if( Pre_Payment_Para.ID_Ins_Counter>=15 )
//		return ERR;
	dst = Card_WR_Buff;
	Far_645_Frame_T1 = (struct Far_645_Frame_T1  *)Data_Point;

	Length = LENGTH_FAR_DEAL_PARA_LIST_T1;
	Length/=LENGTH_FAR_DEAL_PARA_FLAG_T1;

	for( i=0;i<Length;i++ )
	{
		if(	Far_Deal_Para_List_T1[i].Data_ID[0] == *(ID_Point+0) && 
			Far_Deal_Para_List_T1[i].Data_ID[1] == *(ID_Point+1) &&
			Far_Deal_Para_List_T1[i].Data_ID[2] == *(ID_Point+2) &&
			Far_Deal_Para_List_T1[i].Data_ID[3] == *(ID_Point+3) ) 
		{
			break;
		}
	}
	if( i==Length )
		return ERR;

	for( j=0;j<LENGTH_FAR_DEAL_PARA_FLAG_T1;j++ )
		*(((unsigned char *)(&Far_Deal_Para_Flag_T1))+j) = *(((const unsigned char *)&Far_Deal_Para_List_T1[i])+j);

    id = *(unsigned long far*)Far_Deal_Para_List_T1[i].Data_ID;

    switch (id) {
    //case 0x040501ff:/*"��ǰ�׷������ݿ�"*/
    case 0x040502ff:/*"�����׷������ݿ�"*/
        if( ( *Source_Length) % 4 != 0 || ( *Source_Length) < 16) {
            return ERR;	
        }
        Far_Deal_Para_Flag_T1.Esam_Length = *Source_Length - 16;/*"���ݱ�ʶ ���� �����ߴ��� MAC"*/
        data = Data_Point + LENGTH_FAR_645_FRAME_T1;
        for (j=0; j < Far_Deal_Para_Flag_T1.Esam_Length / 4; j++) {
            My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        }
        My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        if(Far_Write_Esam(0x04,Update_Binary,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Card_WR_Buff, 2)!=OK) {
    		//Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
    		return ERR;
	    } 
        last = j - 1;/*" �����һ�����ʵ�۲���32�����ʵ�� "*/
        if (last < 31) {
            for (j; j < 32; j++) {
               data[ 4 * j + 0] = data[ 4 * last + 0];
               data[ 4 * j + 1] = data[ 4 * last + 1];
               data[ 4 * j + 2] = data[ 4 * last + 2];
               data[ 4 * j + 3] = data[ 4 * last + 3];
            }
            *Source_Length += (4 * (31 - last));
        }
        break;
    //case 0x040604FF:/*"��ǰ�׽��ݲ������ݿ�"*/
    case 0x040605FF:/*"�����׽��ݲ������ݿ�"*/
        if( ( *Source_Length) != (Far_Deal_Para_List_T1[i].Esam_Length+16) )
    		return ERR;	
        
        data = Data_Point + LENGTH_FAR_645_FRAME_T1;
        for (j=0; j < 6 + 7; j++) {/*"6������ֵ + 7�����ݵ��"*/
            My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        }
        dst = dst + 4 * j;
        data = data + 4 * j;
        for (j=0; j < 4; j++) {/*"4���������"*/
            My_memcpyRev(dst + 3 * j, data + 3 * j, 3);
            /*
            if (year_bill_date_is_err(dst + 3 * j)) {
                Meter_States.ErrOfInformation.bit.Invalid_Data = 1;
                return ERR;
            }
            */
        }

        My_memcpyRev(dst + 3 * j, data + 3 * j, 4);
        if(Far_Write_Esam(0x04,Update_Binary,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Card_WR_Buff, 2)!=OK) {
    		//Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
    		return ERR;
	    } 
        break;
    case 0x0400040E:/*"�ͻ��������"*/
        if (MACRO_LOCAL_PAY_FLAG) {/*"���طѿص��ܱ�ͻ����ֻ������ʱ�޸ģ���֧��Զ���޸�"*/
            //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
            return ERR;
        }
        /*" ��break����������Ĵ��� "*/
    case 0x04000402:/*"�������"*/
        if (Pre_Payment_Para.Far_Key_StatusByte) {/*"��š��ͻ����ֻ������������Կ״̬��ӦΪ������Կ������"*/
            //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
            return ERR;
        }
        /*" ��break������Ҫ����default�Ĵ��� "*/
    default:
        if( ( *Source_Length) != (Far_Deal_Para_List_T1[i].Esam_Length+16) )
    		return ERR;	
        if(Far_Write_Esam(0x04,Update_Binary,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Data_Point+LENGTH_FAR_645_FRAME_T1,0)!=OK) {
		    //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
		    return ERR;
	    }    
    }	

#if 0
    /* 0xFF,0x03,0x05,0x04 �Լ� 0xFF,0x04,0x06,0x04 �ǶԱ����׵�д��Ҫ�жϵ�ǰ�������ף����������� */
    if ( (ID_Point[0] == 0xFF && ID_Point[1] == 0x03 && ID_Point[2] == 0x05 && ID_Point[3] == 0x04 )
        || (ID_Point[0] == 0xFF && ID_Point[1] == 0x04 && ID_Point[2] == 0x06 && ID_Point[3] == 0x04 )) 
    {
        if (Pre_Payment_Para.Curr_Triff_Point == 0) 
		{/*" ��ǰ���ǵ�һ�� "*/
            Far_Deal_Para_Flag_T1.Esam_File = USER_CARD_TRIFF_2_FILE;
        } 
		else 
		{/*" ��ǰ���ǵڶ��� "*/
            Far_Deal_Para_Flag_T1.Esam_File = USER_CARD_TRIFF_1_FILE;
        }
    }
#endif


/*" ������֡��ɱ�׼645��ʽ"*/
	( *Source_Length)-=0x04;
	return OK;
}


/*"**************************************************************************"*/
/*" �ڶ������Զ��д������"*/
/*" ֧�ֱ�A5 "*/
/*" Data_Point:��:ָ��L DI0 DI1 DI2 DI3...... "*/
/*"            ��:���ݸ�ʽ���� "*/
/*" ��������ȷ �������ݸ�ʽת������ͨд���ݸ�ʽ�����ú���д����"*/
/*" ����������ֱ�Ӵ����˳�"*/
/*"**************************************************************************"*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct Far_645_Frame_T2
	{
//	unsigned char Length;
//	unsigned char Data_ID[4];
	unsigned char PassWord[4];
	unsigned char Do_man[4];
	};
#define LENGTH_FAR_645_FRAME_T2        sizeof(struct Far_645_Frame_T2 )
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct Far_Deal_Para_Flag_T2
	{
	unsigned char Data_ID[4];
	unsigned char Source_Length;				/*"�������ݳ���"*/
	unsigned char TX_Length;					/*"ʵ�����ݳ���"*/
	};
#define LENGTH_FAR_DEAL_PARA_FLAG_T2      sizeof(struct Far_Deal_Para_Flag_T2)

/*" DL/T645-2007 ���๦�ܵ��ܱ�ͨ��Э�顷�������ļ������ݱ�ʶ��DI2��Ϊ���֣�����DI2ģ5�Ľ�����жϲ����ĸ����������ļ���"*/
/*"���ݱ�ʶDI2ģ5 = 0�����ò��������ļ�1��"*/
/*"���ݱ�ʶDI2ģ5 = 1�����ò��������ļ�2��"*/
/*"���ݱ�ʶDI2ģ5 = 2�����ò��������ļ�3��"*/
/*"���ݱ�ʶDI2ģ5 = 3�����ò��������ļ�4��"*/
/*"���ݱ�ʶDI2ģ5 = 4�����ò��������ļ�5��"*/
#pragma SECTION rom UserROMData
const unsigned char Data_ID_Offset[]=
{0x09,0x10,0x11,0x12,0x13};
unsigned char Far_Deal_Para_T2(unsigned char * ID_Point,unsigned char * Data_Point,unsigned char *Soure_Length )
	{
	unsigned char i,j,Block_Flag, blk_sz;
	unsigned char commaFlg;			/*"��,�Ÿ�ʽ������"*/		//Li Update 20121225
	struct Far_Deal_Para_Flag_T2  Far_Deal_Para_Flag_T2;
	struct Far_645_Frame_T2  * Far_645_Frame_T2;
	unsigned char ID_a,ID_b,ID_c,ID_d;
    unsigned long id;
    signed long money;

    if (is_T1_para(ID_Point) || is_T3_para(ID_Point)) {
        //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return ERR;
    }

	Far_645_Frame_T2 = (struct Far_645_Frame_T2  *)Data_Point;

    id = *(unsigned long *)ID_Point;
	ID_a = *(ID_Point+3 );
	ID_b = *(ID_Point+2 );
	ID_c = *(ID_Point+1 );
	ID_d = *(ID_Point+0 );
	Block_Flag = 0x00;

	Far_Deal_Para_Flag_T2.Data_ID[0] = *(ID_Point+0 );	
	Far_Deal_Para_Flag_T2.Data_ID[1] = *(ID_Point+1 );
	Far_Deal_Para_Flag_T2.Data_ID[2] = *(ID_Point+2 );
	Far_Deal_Para_Flag_T2.Data_ID[3] = *(ID_Point+3 );

    commaFlg = 0;
    blk_sz = 0;
    Block_Flag = 0;
	//FayMidefyFlag=0;
	//if ((ID_a==0x04) && (ID_b==0x00) && (ID_c==0x0C) && (ID_d<=MAX_PASS_NUM))	/*"ͨ�����İ����������ݱ�־����02��04������"*/
	//	{
	//	FayMidefyFlag=0xC0+ID_d-1;
	//	}
    //else 
    if (ID_a==0x04 &&  ( ID_b>=0x01 && ID_b<=0x02 ) && ID_c==0x00 && ID_d<=0x08) {/*" ʱ����ʱ�α����� "*/
        blk_sz = 3;
		Block_Flag = 0xFF;
    } else if (ID_a == 0x0E && ID_b == 0x00 &&  ( ID_c >= 0x03 && ID_c <= 0x08 )  && ID_d == 0xff) {/*" ���ʼ���� "*/
        blk_sz = 4;
		Block_Flag = 0xFF;
		}
	else if ((ID_a==0x04) && (ID_b==0x04) && (ID_c>=0x01 && ID_c<=0x04) && (ID_d>=0x01 && ID_d<=0x78))   /*" ����ѭ�ԺͰ��� "*/
		{
		commaFlg=1;
		}

	Far_Deal_Para_Flag_T2.Source_Length = ( *Soure_Length)-16;/*" 16 = 04H�����ݱ�ʶ��+04H�����룩+04H�������ߴ��룩+04(MAC)"*/

 	i = *(ID_Point+2 );
	i%=5;
	j = Data_ID_Offset[i];
	if ((ID_a==0x04) && (ID_b==0x80) && (ID_c==0x00) && (ID_d<=0x03))			 /*"Li_��������汾��/Ӳ���汾�ţ����ұ��"*/ 	//Li Update 20121225  
		j=Data_ID_Offset[0];	

    if (id == 0x04001006) {/*"�˷ѽ��"*/
        if (Far_Deal_Refundment(Data_Point + LENGTH_FAR_645_FRAME_T2) == OK) {
            ( *Soure_Length) = 12;
            return OK;
        } else {
            return ERR;
        }
    } 
   
	if( Far_Write_Esam(0x04,Update_Binary,0x80+j,0x00,Far_Deal_Para_Flag_T2.Source_Length,Data_Point+LENGTH_FAR_645_FRAME_T2,0)!=OK)
	{
	//Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
	return ERR;
	}
    
	if( Read(0x00, Read_Binary, 0x80+j, 0x00, 1) != OK )
		return ERR;

	Far_Deal_Para_Flag_T2.TX_Length = receive_send_buffer[0]-4;/*"QQQ ��ȥ4�ֽڵ�MAC���õ����ǰ������ݱ�ʶ��645���ݲ��ֳ���"*/
    if (Far_Deal_Para_Flag_T2.TX_Length > 192) {/*"WriteDateBuff ֻ��200�ֽڣ�ǰ8�ֽڱ�����������ߴ��룬��192�ֽڿ���"*/
        return ERR;
    }
	if( Read(0x00, Read_Binary, 0x80+j, 0x00, Far_Deal_Para_Flag_T2.TX_Length+5) != OK )
		return ERR;

	Reverse_data(receive_send_buffer+1,4);/*" ��4�ֽ������ݱ�ʶ �ǵ�һ�ֽ���ʲô "*/
	if( My_Memcmp(receive_send_buffer+1,Far_Deal_Para_Flag_T2.Data_ID,4) != 0 )
		return ERR;

	if (commaFlg)						/*"ѭ�Զ��Ÿ�ʽ"*/		/*"Li_ѭ�Զ��Ÿ�ʽ��Ҫ��ת"*/	//Li Update 20121225
	{
		My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2, receive_send_buffer+5, 4);
		memcpy(Data_Point+LENGTH_FAR_645_FRAME_T2+4, receive_send_buffer+5+4, 1);
	}
	//else if ((FayMidefyFlag&0xF0)==0xC0)
	//	{
	//	/*"�����޸�2�����룬��λ������112233������˳��Ϊ02332211"*/
	//	/*"�����޸�2�����룬��λ������11223302�����ܺ�Ϊ11223302�������Ϊ02332211����ԭΪ�����޸������˳��"*/
	//	My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2, receive_send_buffer+5, 4);
	//	}	
	else if( Block_Flag == 0 )			/*"�����������"*/	
	{
		My_Memcpy(Data_Point+LENGTH_FAR_645_FRAME_T2, 0, 32);
        switch (id) {
        case 0x0400040F:/*"���ܱ�λ����Ϣ: 4 4 3��ʽ"*/
            My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2, receive_send_buffer+5, 4);
            My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2 + 4, receive_send_buffer + 9, 4);
            My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2 + 8, receive_send_buffer+ 13, 3);
            break;
        case 0x0e000005:
        case 0x0e00000c:
        case 0x0e00000d:
            /*" Һ��������������������ӱ���ģʽ�� ���跴ת (4�����ֽ�)"*/
            My_Memcpy(Data_Point+LENGTH_FAR_645_FRAME_T2, receive_send_buffer+5, Far_Deal_Para_Flag_T2.TX_Length);
            break;
        default:
		    My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2, receive_send_buffer+5, Far_Deal_Para_Flag_T2.TX_Length);
            break;                
        }
	}
	else								/*"���ݿ����"*/	
	{
		Block_Flag = Far_Deal_Para_Flag_T2.TX_Length/blk_sz;
		for( i=0;i<Block_Flag;i++ )
			{
			My_memcpyRev(Data_Point+LENGTH_FAR_645_FRAME_T2+i*blk_sz, receive_send_buffer+5+i*blk_sz, blk_sz);
			}
	}
    
	( *Soure_Length) =Far_Deal_Para_Flag_T2.TX_Length+12;
	return OK;
	}


/*" �ж��Ƿ��һ���ڶ�������"*/
unsigned char Far_Password_Check(unsigned char * ID_Point,unsigned char * Point ,unsigned char *Length)
	{
	unsigned char ret;

	ret = OK;
	Far_Spec_Order_Flag = 0;

	My_Memcpy(&oprateCode[0], Point+4, 4);

	if( *(Point)==0x99  || *(Point)==0x98 )
		{
		if(Pre_Payment_Data.HangMeterNum >= NUM_ERR_TO_HANG) {
            //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
			return ERR;
		}
		if( Far_Identity_Auth_Ok_Flag != 0xFF ) {
            //Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
			return ERR;
		}
		
		Cpucard_Serial_Init();	/*"��ʼ��ESAM����"*/

//		if(Far_Init_Esam()!=0)
//			ret = ERR;
		Far_Spec_Order_Flag  = 0xFF;

		if( *(Point)==0x99 )
			{
			ret = Far_Deal_Para_T1(ID_Point,Point ,Length) ;
			}
		else
			{
			ret = Far_Deal_Para_T2(ID_Point,Point ,Length);
			}
	
		cpucard_serial_release();	/*"�ͷ�ESAM����"*/
		*(Point)=0x04;
		My_Memcpy(Point+1, &Meter_Parameter.parameter1.ClearPassword[3][1], 3);
		}
	else
		{
            if (is_T3_para(ID_Point)) {
                    ret = OK;
            } else {
    		 if (O1ther_Meter_Parameter.WorkRoomState)
    		 	ret = OK;
    		 else
    		 	ret = ERR;
            }
		}
	return ret;
	}

/*"�����������Ч��ֹʱ��ĺϷ���"*/
unsigned char CheckCmdTime(unsigned char * Point)
{
	if ((*(Point+2)==0x99)&&(*(Point+3)==0x99)&&(*(Point+4)==0x99)&&(*(Point+5)==0x99)&&(*(Point+6)==0x99)&&(*(Point+7)==0x99))
	{
		;
	}
	else	/*"���ʱ��Ϸ���"*/
	{
		if ((0==CheckTime(Point+2))||(My_Memcmp(Point+2,&(softdate.Year),6)==2))	/*"ʱ���ʽ���Ϸ� �� ʱ���ڵ�ǰʱ��֮ǰ"*/
		{
			return ERR;
		}
	}
	return OK;
}

/*" ����Զ�̿���֡ "*/
unsigned char Far_Deal_Control(unsigned char * Point)
	{
	unsigned char ok;
	unsigned char Control_Flag;
	//double long TimeLen;

	ok = 0xFF;
	Control_Flag = (* Point);

	if (CheckCmdTime(Point)==ERR)
		{
		Fay_Ctl_Res_Err.bit.TimeErr=1;
		return 0;
		}
		
	if( Control_Flag==0x1A )	
		{
		if ((!METER_IN_FRIEND_DAY_DEFINE))			/*"Li_���û�б���"*/
			{
			if (!FAR_OPEN_SWITCH_DEFINE)				/*"Li_Զ����բ��־û���Ļ�"*/
			{
				if (!FAR_OPRATE_ID_DEFINE)				/*"Li_���ԭ��Զ����բû��"*/
				{
					FAR_OPRATE_ID_DEFINE=1;				/*"Li_��բ"*/
					Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
						(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
				}
			}
			else
				FAR_OPRATE_ID_DEFINE=0;
			//FAR_CLOSE_PREPARE_DEFINE=0;
			//FAR_CLOSE_SWITCH_DEFINE = 0;
			FAR_OPEN_PREPARE_DEFINE=1;
			FAR_OPEN_CMD_DEFINE=1;
			FarOpenTime=GetNowTime();
			//FAR_CLOSE_PREPARE_DEFINE=0;
			if( Control_Flag==0x1A )							/*"Li_�����բ����"*/
			 	FAR_OPEN_CMD_DEFINE=1;							/*"Li_��բ��־��1"*/
			FAR_WARN_1D_DEFINE=0;	/*"(����4)��բ�Զ��ָ�ʱ������У��յ�Զ����բ�����硢ֱ�Ӻ�բ����բ��������ʱ��������բ�Զ��ָ�������ִ����Ӧ����"*/
			FAR_WARN_1E_DEFINE=0;
			//----------------------------------------------------//
			if (Pre_Payment_Para.Far_Open_Delay)		/*"���ж��Ƿ�����բ��ʱ"*/
				Fay_Ctl_Res_Ok.bit.DelayOpen=1;
			else
				{
				if (CURR_30A_FLG_DEFINE)
					Fay_Ctl_Res_Ok.bit.CurrDelay=1;
				else
					Fay_Ctl_Res_Ok.bit.DirOpen=1;
				}
			}
		else
			{
			ok = 0;
			Fay_Ctl_Res_Err.bit.OpenFriErr=1;
			}
		}
	else if( Control_Flag==0x1B || Control_Flag==0x1C )	/*"Li_��բ����/���ӿ�������0x1C(ֱͬ�Ӻ�բ)"*/
		{
		FAR_OPRATE_ID_DEFINE=0;
		if ( (Relay_Alarm_SWitch_Flag[1][0]&0x60)	/*"Զ��������բ"*/
			|| ( (Relay_Alarm_SWitch_Flag[1][0] & 0x0c)  && ( Control_Flag == 0x1C )))
			OPRATE_ID_CLOSE_DEFINE=1;
		if (OPRATE_ID_CLOSE_DEFINE)
			{
			if (!FAR_OPRATE_ID_DEFINE)
				{
				FAR_OPRATE_ID_DEFINE=1;
				Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
					(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
				}
			}
		FAR_OPEN_SWITCH_DEFINE = 0;
		FAR_OPEN_PREPARE_DEFINE=0;
		//FAR_CLOSE_PREPARE_DEFINE=1;
		//FarCloseTime=GetNowTime();
		//------------------------------------------------//
		FAR_OPEN_CMD_DEFINE=0;

		if( Control_Flag==0x1C )
		{
			if( SWITCH_FACT_DEFINE )			/*"Li_�̵���ʵ��״̬,1Ϊ��բ��0Ϊ��բ"*/
				SWITCH_ALLOW_CLOSE_DEFINE = 1;	/*" QQQ ֱ�Ӻ�բ:���൱���Ѿ��������ø��ɿ����ˣ���Ҫ���˾�ֱ�Ӻ�բ "*/
			Fay_Ctl_Res_Ok.bit.DirCls=1;
			Card_Alarm_Switch();/*"���طѿر���Ԥ��բ����£������ֶ���բ���յ�ֱ�Ӻ�բ����ʱҲ��բ"*/
		}
		else
			Fay_Ctl_Res_Ok.bit.AllowCls=1;
		FAR_WARN_1D_DEFINE=0;	/*"(����4)��բ�Զ��ָ�ʱ������У��յ�Զ����բ�����硢ֱ�Ӻ�բ����բ��������ʱ��������բ�Զ��ָ�������ִ����Ӧ����"*/
		FAR_WARN_1E_DEFINE=0;
		}
	else if( Control_Flag==0x2A )					/*"Li_����"*/
		{
		FAR_OPEN_ALARM_DEFINE = 1;
		FAR_CLOSE_ALARM_DEFINE = 0;
		Fay_Ctl_Res_Ok.bit.Alarm=1;
		}
	else if( Control_Flag==0x2B )					/*"Li_�������"*/
		{
		FAR_OPEN_ALARM_DEFINE = 0;
		FAR_CLOSE_ALARM_DEFINE = 1;
		Fay_Ctl_Res_Ok.bit.AlarmFree=1;
		}
	else if( Control_Flag==0x3A )					/*"Li_����"*/
		{
		FAR_OPRATE_ID_DEFINE=0;
		if (SWITCH_FACT_DEFINE)						/*"Li_�̵���ʵ��״̬: 1,��բ 0,��բ"*/
			{
			if (!FAR_OPRATE_ID_DEFINE)				/*"Li_Զ����բ����"*/
				{
				FAR_OPRATE_ID_DEFINE=1;
				Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
					(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
				}
			}
		else
			FAR_OPRATE_ID_DEFINE=0;
		METER_IN_FRIEND_DAY_DEFINE = 1;				/*"Li_�����־"*/
		FAR_OPEN_PREPARE_DEFINE=0;
		if (!FRIEND_DAY_CLOSE_DEFINE)
			{
			FAR_OPEN_SWITCH_DEFINE = 0;
			//FAR_CLOSE_PREPARE_DEFINE=1;
			}
		//-----------------------------------------//
		else
		{            /*"��բ��Զ�̵���"*/
			if (FAR_OPEN_SWITCH_DEFINE  )  
				FRIEND_RELEASE_SWITCH_FLAG_DEFINE = 1;
		}
		Fay_Ctl_Res_Ok.bit.Friend=1;
		FAR_WARN_1D_DEFINE=0;	/*"(����4)��բ�Զ��ָ�ʱ������У��յ�Զ����բ�����硢ֱ�Ӻ�բ����բ��������ʱ��������բ�Զ��ָ�������ִ����Ӧ����"*/
		FAR_WARN_1E_DEFINE=0;
		}
	else if( Control_Flag==0x3B )					/*"Li_������"*/
		{
		if (METER_IN_FRIEND_DAY_DEFINE)
			{
			if ((!SWITCH_FACT_DEFINE)&&(FAR_OPEN_PREPARE_DEFINE||FAR_OPEN_SWITCH_DEFINE))
				{
				if (!FAR_OPRATE_ID_DEFINE)
					{
					FAR_OPRATE_ID_DEFINE=1;
					Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
						(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
					}
				}
			else
				FAR_OPRATE_ID_DEFINE=0;
			METER_IN_FRIEND_DAY_DEFINE = 0;
		 //------------------------------------------------//
			FAR_OPEN_CMD_DEFINE=0;
			if ( FRIEND_DAY_CLOSE_DEFINE )       /*"���粻�����բ,����Ҫ����ʱʱ����բ"*/
				{
					if(  FAR_OPEN_SWITCH_DEFINE  ) /*"QQQ ��˼�Ǳ���ǰ��׼����բ��״̬�������˳�������������բ������"*/ 
					{
						//FAR_CLOSE_PREPARE_DEFINE=0;
						//FAR_CLOSE_SWITCH_DEFINE = 0;
						FAR_OPEN_SWITCH_DEFINE = 0;
						FAR_OPEN_PREPARE_DEFINE=1;
						FarOpenTime=GetNowTime();
					}
				}
		 //------------------------------------------------//	
			}
		Fay_Ctl_Res_Ok.bit.FriFree=1;
		}
	else if ((Control_Flag==0x1D)||(Control_Flag==0x1E)) 
		{
		if (METER_IN_FRIEND_DAY_DEFINE)
			{
			Fay_Ctl_Res_Err.bit.WarnFriErr=1;
			ok=0;
			}
		else if (FAR_OPEN_PREPARE_DEFINE || (SWITCH_FACT_DEFINE&&(!FAR_WARN_1D_DEFINE)&&(!FAR_WARN_1E_DEFINE)))	/*"��բ(������Ԥ��բ)����ʧ��"*/	//(Relay_Alarm_SWitch_Flag[1][0]&0x3F)
			{
			Fay_Ctl_Res_Err.bit.WarnOpenErr=1;	/*"(����4)��բ�Զ��ָ������ڱ��硢Զ����բ������ʱ������բ�������شﵽ͸֧������բ�����شﵽ�������2 ���߹�����բʱ�����ط���"*/
			ok=0;
			}
		else if (0==*(Point+1))
			{
			Fay_Ctl_Res_Err.bit.WarnTimeErr=1;
			ok=0;
			}
		else
			{
			if (Control_Flag==0x1D)
				FAR_WARN_1D_DEFINE=1;	/*"Ԥ��բ(��ʱʱ�䵽ֱ�Ӻ�բ)"*/
			else
				FAR_WARN_1D_DEFINE=0;	/*"Ԥ��բ(��ʱʱ�䵽��բ����)"*/
			FAR_WARN_1E_DEFINE=!FAR_WARN_1D_DEFINE;
			Pre_Payment_Para.Far_Close_Delay=*(Point+1);
			Pre_Payment_Para.Far_Close_Delay*=5;	/*"���÷�Χ(01H~FFH)*5����"*/
            Pay_EE_W(FAR_CLOSE_DELAY_EE,(unsigned char *)&(Pre_Payment_Para.Far_Close_Delay),2,3,
                               (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
            FarOpenTime=GetNowTime();	/*"(����4)��բ�Զ��ָ�ʱ��������ٴν��յ���բ�Զ��ָ������Ʒ���ȷ��֡�������Ե�ǰ������������ʱʱ�����¿�ʼ��ʱ"*/
			if (CURR_30A_FLG_DEFINE)
				Fay_Ctl_Res_Ok.bit.CurrDelay=1;
			else
				Fay_Ctl_Res_Ok.bit.Warn=1;

			FAR_OPRATE_ID_DEFINE=1;
			Pay_EE_W(OPRATECODE_EE,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
				(unsigned char*)&Pre_Payment_Data,LENGTH_PRE_PAYMENT_DATA,PRE_PAYMENT_DATA_EE);
			}
		}
	else
		{
		ok = 0;
		Fay_Ctl_Res_Err.bit.PassErr=1;
		}
	//save FLAG12,FLAG13
	 Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),2,3,
		 	    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);

	Far_Switch_Control(1);
	Drive_Act_Repair();
	
	return ok;
	}

/*" Զ����բ����								"*/
/*" 	"��բ��ʱʱ��"��Ӧ��բ����ʹ��,	"*/
/*" 	�û�����Ԥ������һ��ʱ��ֵ,��Զ���·���բ����ʱ,	"*/
/*" 	���ܱ��յ������ȱ���,���趨ʱ��֮��ִ����բ.		"*/
/*" 	�˲���һ������Լ���վ���Ʋ���,  						"*/
/*" 	��һ�����𵽱����û��õ簲ȫ���� 							"*/
/*"  kind:0:power up,	1:run  														"*/
void Far_Switch_Control(unsigned char kind)
{
	if (kind)
		{
		/*"��բǰ����ʱ������,�������ñ��������30Aά��24Сʱ��,"��բ"�ַ���˸"*/
		if ((!SWITCH_FACT_DEFINE) && (!METER_IN_FRIEND_DAY_DEFINE)
			&& (FAR_OPEN_PREPARE_DEFINE||(CURR_30A_FLG_DEFINE && Relay_Alarm_SWitch_Flag[1][0])))
			displayCharOnOff(DISP_CHAR_SWITCH,1,1);
		else
			{
			displayCharOnOff(DISP_CHAR_SWITCH,0,1);
			/*"�յ������բ��,�ֶ���բǰ,"��բ"�ַ�ֹͣ��ʾ(ʵ�ʺ�׼��������բ����ʾ)"*/
			if (SWITCH_FACT_DEFINE && SWITCH_PREPARE_STATE_DEFINE)
				displayCharOnOff(DISP_CHAR_SWITCH,1,0);
			else
				displayCharOnOff(DISP_CHAR_SWITCH,0,0);
			}
		/*"�յ������բ��,�ֶ���բǰ,��բָʾ����˸"*/
		if((Displayfinish_flag==1)&&(light_AlarmSwitchLED==0))///king chen modify 130204
		{		
		if (SWITCH_FACT_DEFINE&&(!SWITCH_PREPARE_STATE_DEFINE))
			SWITCH_CLEW=!SWITCH_CLEW;
		else
			{
			SWITCH_CLEW=NEW645Meter_States.Meter_Status3.bit.Relay_Status;
			//if (SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE)	/*"��բ���Ƶ����ɹ�(��բ״̬),��ʱ��բ�ַ�Ϩ��,��բ����"*/
			//	SWITCH_CLEW=!SWITCH_FACT_DEFINE;
			//else
			//	SWITCH_CLEW=SWITCH_FACT_DEFINE;
			}
		}
		}

	if (IntoPowerDownFlag)
		return;
	if (!MACRO_FAY_CONTROL_FLAG)
		return;
	
	if (((kind==1) && FAR_OPEN_PREPARE_DEFINE && (!GetTimeCount(FarOpenTime,Pre_Payment_Para.Far_Open_Delay*60000)))
		||((kind==0) && FAR_OPEN_PREPARE_DEFINE)
		|| (SWITCH_FACT_DEFINE && FAR_OPEN_PREPARE_DEFINE))
		{
		//FAR_CLOSE_SWITCH_DEFINE = 0;
		FAR_OPEN_PREPARE_DEFINE=0;
		if( !FAR_OPEN_SWITCH_DEFINE  )
			{
			FAR_OPEN_SWITCH_DEFINE = 1;
			//Pay_EE_W(PAY_FOR_USERS_FLAG14_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
		 	//		(unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);	//Li Update 20121225
			}
		 Pay_EE_W(PAY_FOR_USERS_FLAG12_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
	 	    (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
		}
}

unsigned char Find_Do_Money_Bag(void)
	{	
	unsigned char Result;

	Result = 0x00;
	if( REMAIN_BAG_DOING_DEFINE==0)
		{
		REMAIN_BAG_DOING_DEFINE = 1;
		Remain_Money_Bag_Do_Time = GetNowTime();
		Reamin_Money_ESAM_Dec_Time=GetNowTime();
		Result = 0xFF;
		}
	else
		{
		if(GetTimeCount(Remain_Money_Bag_Do_Time,900000l)==0)
			{
			Result = 0xFF;
			REMAIN_BAG_DOING_DEFINE = 0;
			Remain_Money_Bag_Do_Time = GetNowTime();
			Reamin_Money_ESAM_Dec_Time=GetNowTime();
			}
		}
	return Result;
	}





