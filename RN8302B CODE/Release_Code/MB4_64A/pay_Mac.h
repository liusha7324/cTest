/*"**********************************************************************************"*/
/*" �Զ����־�� "*/
union Pay_For_Users_Flag1
    {
    struct
        {
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM1:1;    /*" 1:ʣ���ѵ��ڱ�������1 "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM2:1;    /*" 1:ʣ���ѵ��ڱ�������2 "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_ZERO:1;      /*" 1:ʣ���ѵ����� "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_TICK:1;      /*" 1:ʣ���ѵ�����Ƿ���� "*/
        unsigned char REMAIN_MONEY_OPEN_SWITCH:1;         /*" 1:ʣ������բ��־ "*/
        unsigned char STEP1_OR_STEP2:1;						/*" 1:�۷�ѡ�ݶȷ���2��0���۷�ѡ�ݶȷ���1 "*/
        unsigned char REMAIN_MONEY_LOW_ZERO_FREE:1;       /*" 1:ʣ���ѵ������Ѿ��忨��� "*/
        unsigned char REMAIN_MONEY_LOW_ALARM2_FREE:1;     /*" 1:ʣ���ѵ��ڱ�������2�Ѿ��忨��� "*/
        }bit;
    unsigned char  intd;
    };
#define FIRST_REMAIN_MONEY_LOW_ALARM1_DEFINE  Pre_Payment_Para.Pay_For_Users_Flag1.bit.FIRST_REMAIN_MONEY_LOW_ALARM1
#define FIRST_REMAIN_MONEY_LOW_ALARM2_DEFINE  Pre_Payment_Para.Pay_For_Users_Flag1.bit.FIRST_REMAIN_MONEY_LOW_ALARM2
#define FIRST_REMAIN_MONEY_LOW_ZERO_DEFINE    Pre_Payment_Para.Pay_For_Users_Flag1.bit.FIRST_REMAIN_MONEY_LOW_ZERO
#define FIRST_REMAIN_MONEY_LOW_TICK_DEFINE    Pre_Payment_Para.Pay_For_Users_Flag1.bit.FIRST_REMAIN_MONEY_LOW_TICK
#define REMAIN_MONEY_OPEN_SWITCH_DEFINE       Pre_Payment_Para.Pay_For_Users_Flag1.bit.REMAIN_MONEY_OPEN_SWITCH
#define STEP1_OR_STEP2_DEFINE               Pre_Payment_Para.Pay_For_Users_Flag1.bit.STEP1_OR_STEP2
#define REMAIN_MONEY_LOW_ZERO_FREE_DEFINE     Pre_Payment_Para.Pay_For_Users_Flag1.bit.REMAIN_MONEY_LOW_ZERO_FREE
#define REMAIN_MONEY_LOW_ALARM2_FREE_DEFINE   Pre_Payment_Para.Pay_For_Users_Flag1.bit.REMAIN_MONEY_LOW_ALARM2_FREE
/*"**********************************************************************************"*/
/*" Ԥ����ģʽ��1 "*/
union Pay_For_Users_Flag2
    {
    struct
        {
        unsigned char REMAIN_MONEY_LOW_ZERO_SWITCH:1;      /*" 1:��ʣ����С�ڵ���0ʱ������բ(��Ƿ��Ч�������) "*/
        unsigned char REMAIN_MONEY_LOW_ALARM2_SWITCH:1;    /*" 1:��ʣ����С�ڵ��ڱ�������2ʱ����բ���� "*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char REMAIN_MONEY_LOW_ALARM1_SHOW:1;      /*" 1:��ʣ����С�ڵ��ڱ�������1ʱ��ͣ��ʣ���� "*/ 
        }bit;
    unsigned char  intd;
    };
#define REMAIN_MONEY_LOW_ZERO_SWITCH_DEFINE        Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ZERO_SWITCH
#define REMAIN_MONEY_LOW_ALARM2_SWITCH_DEFINE      Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ALARM2_SWITCH
//#define 
//#define 
#define REMAIN_MONEY_LOW_ALARM1_SHOW_DEFINE        Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ALARM1_SHOW
/*"**********************************************************************************"*/
/*" Ԥ����ģʽ��2 "*/
union Pay_For_Users_Flag3
    {
    struct
        {
        unsigned char CLOSE_KEY_NE_RELAY:1;	/*" 1:���ñ�,��բʱ����Ҫ����"*/ 
        unsigned char FRIEND_DAY_CLOSE:1;		/*" 1:���粻�����բ"*/ 
        unsigned char PUBLIC_CONTROL_RELAY:1;	/*" 1:������������բ"*/ 
        unsigned char CLOSE_KEY_WAI_RELAY:1;	/*" 1:���ñ�,��բʱ����Ҫ����"*/ 
        unsigned char WAION_ESAM:1;    			/*" 1:�����Թܻ�ESAM,Զ��ֻ��3����Կ"*/ 
        unsigned char :1;
        unsigned char Fay_30ALimit:1;			/*"1:Զ��30A�������ƹ���"*/ 
        unsigned char Local_30ALimit:1;      	/*"1:����30A�������ƹ���"*/ 
        }bit;
    unsigned char  intd;
    };
#define CLOSE_KEY_NE_RELAY_DEFINE		Pre_Payment_Para.Pay_For_Users_Flag3.bit.CLOSE_KEY_NE_RELAY
#define FRIEND_DAY_CLOSE_DEFINE      	Pre_Payment_Para.Pay_For_Users_Flag3.bit.FRIEND_DAY_CLOSE
#define PUBLIC_CONTROL_RELAY_DEFINE 	Pre_Payment_Para.Pay_For_Users_Flag3.bit.PUBLIC_CONTROL_RELAY
#define CLOSE_KEY_WAI_RELAY_DEFINE 		Pre_Payment_Para.Pay_For_Users_Flag3.bit.CLOSE_KEY_WAI_RELAY
#define WAION_ESAM_DEFINE 				Pre_Payment_Para.Pay_For_Users_Flag3.bit.WAION_ESAM
//#define 
#define Fay_30ALimit_DEFINE           	Pre_Payment_Para.Pay_For_Users_Flag3.bit.Fay_30ALimit
#define Local_30ALimit_DEFINE         	Pre_Payment_Para.Pay_For_Users_Flag3.bit.Local_30ALimit
/*"**********************************************************************************"*/
/*" Ԥ����ģʽ��3"*/
union Pay_For_Users_Flag4
    {
    struct
        {
        unsigned char SWITCH_ERR:1;				/*"1:����ESAM,  0:��ʽESAM"*/	//ESAM_TEST
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B1:1;
        unsigned char SpicReq_SC:1;		/*"1:�Ĵ�����Ҫ���(֧�ַᡢƽ����ˮ�ڵ�ۣ�֧�ְ���ʱ�����������ʱ���¼�)"*/	//spicial require
        }bit;
    unsigned char  intd;
    };
#define SWITCH_ERR_DEFINE                  Pre_Payment_Para.Pay_For_Users_Flag4.bit.SWITCH_ERR

//#define SpicReq_SC_DEFINE                  Pre_Payment_Para.Pay_For_Users_Flag4.bit.SpicReq_SC

/*"**********************************************************************************"*/
/*" �Ѻ���������ģʽ�� "*/
union Pay_For_Users_Flag5
    {
    struct
        {
        unsigned char FRIEND_SUNDAY:1;                /*" 1:���չ��� "*/
        unsigned char FRIEND_MONDAY:1;                /*" 1:��һ���� "*/
        unsigned char FRIEND_TUSEDAY:1;               /*" 1:�ܶ����� "*/
        unsigned char FRIEND_WEDNESDAY:1;             /*" 1:�������� "*/
        unsigned char FRIEND_THURSDAY:1;              /*" 1:���Ĺ��� "*/
        unsigned char FRIEND_FRIDAY:1;                /*" 1:���幤�� "*/
        unsigned char FRIEND_SATURDAY:1;              /*" 1:�������� "*/ 
        unsigned char :1;
        }bit;
    unsigned char  intd;
    };
#define FRIEND_SUNDAY_DEFINE       Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_SUNDAY
#define FRIEND_MONDAY_DEFINE       Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_MONDAY
#define FRIEND_TUSEDAY_DEFINE      Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_TUSEDAY
#define FRIEND_WEDNESDAY_DEFINE    Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_WEDNESDAY
#define FRIEND_THURSDAY_DEFINE     Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_THURSDAY
#define FRIEND_FRIDAY_DEFINE       Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_FRIDAY
#define FRIEND_SATURDAY_DEFINE     Pre_Payment_Para.Pay_For_Users_Flag5.bit.FRIEND_SATURDAY
//#define 

/*"**********************************************************************************"*/
/*" Զ��Ԥ����״̬�� "*/
union Pay_For_Users_Flag6
    {
    struct
        {
        unsigned char FAY_CTL_RES:1;       			/*"1:Ӧ��֡�����ӵ��ܱ�����״̬"*/
        unsigned char Curr_30A_Flg:1;				/*"1:���ñ�ĵ�ǰ��������30A"*/
        unsigned char Curr_30A_Start_Cnt:1;			/*"1:��30A�����·�����բ����,��ʼ��ʱ"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char Pay_Buy_Money_Flg:1;			/*"1:Զ�̿��������硢�˷ѷ�����ǿ��2�α���,��ֹ���ϵ��,��ƽ���͹��ı���2�θ�λ���ʱ,ȡ�����������ݵ�����,��ʹ��Ѷ�ʧ"*/
        unsigned char RecFlg:1;						/*"1:���¼���¼�����仯ʱ��������ʾ���ݣ�ʹ�����ڵ͹�������ʾ"*/
        unsigned char COMM_ALL_AA:1;				/*"1:ȫA��ַͨ���ʱ,03�����������ݻس���״̬��ѯ��������֤�������֤������Ƚ�"*/
        }bit;
    unsigned char  intd;
    };
#define FAY_CTL_RES_DEFINE    		Pay_For_Users_Flag6.bit.FAY_CTL_RES
#define CURR_30A_FLG_DEFINE     	Pay_For_Users_Flag6.bit.Curr_30A_Flg
#define CURR_30A_START_CNT_DEFINE 	Pay_For_Users_Flag6.bit.Curr_30A_Start_Cnt
//#define
//#define 
#define PAY_BUY_MONEY_FLG_DEFINE    Pay_For_Users_Flag6.bit.Pay_Buy_Money_Flg
#define REC_FLG_DEFINE				Pay_For_Users_Flag6.bit.RecFlg
#define COMM_ALL_AA_DEFINE    		Pay_For_Users_Flag6.bit.COMM_ALL_AA
/*"**********************************************************************************"*/
/*" �������״̬�� "*/
union Pay_For_Users_Flag7
    {
    struct
        {
        unsigned char OVER_POWER_CLUE:1;                /*" 1:��������ʾ "*/
        unsigned char REMAIN_MONEY_LOW_ALARM1_CLUE:1;   /*" 1:ʣ���ѵ��ڱ�������1��ʾ "*/ 
        unsigned char REMAIN_MONEY_LOW_ALARM2_CLUE:1;   /*" 1:ʣ���ѵ��ڱ�������2��ʾ "*/ 
        unsigned char REMAIN_MONEY_LOW_ZERO_CLUE:1;     /*" 1:ʣ���ѵ�������ʾ "*/
        unsigned char REMAIN_MONEY_LOW_TICK_CLUE:1;     /*" 1:ʣ���ѵ�����Ƿ������ʾ "*/
        unsigned char SWITCH_ERR_CLUE:1;                /*" �̵���������ʾ(���ü̵���)"*/
        unsigned char ESAM_ERR:1;						/*" 1:ESAM���� "*/
        unsigned char Wai_SWITCH_ERR:1;					/*"���ü̵�������"*/
        }bit;
    unsigned char  intd;
    };
#define OVER_POWER_CLUE_DEFINE                   Pay_For_Users_Flag7.bit.OVER_POWER_CLUE
#define REMAIN_MONEY_LOW_ALARM1_CLUE_DEFINE      Pay_For_Users_Flag7.bit.REMAIN_MONEY_LOW_ALARM1_CLUE
#define REMAIN_MONEY_LOW_ALARM2_CLUE_DEFINE      Pay_For_Users_Flag7.bit.REMAIN_MONEY_LOW_ALARM2_CLUE
#define REMAIN_MONEY_LOW_ZERO_CLUE_DEFINE        Pay_For_Users_Flag7.bit.REMAIN_MONEY_LOW_ZERO_CLUE
#define REMAIN_MONEY_LOW_TICK_CLUE_DEFINE        Pay_For_Users_Flag7.bit.REMAIN_MONEY_LOW_TICK_CLUE
#define SWITCH_ERR_CLUE_DEFINE                   Pay_For_Users_Flag7.bit.SWITCH_ERR_CLUE
#define ESAM_ERR_DEFINE							Pay_For_Users_Flag7.bit.ESAM_ERR
#define Wai_SWITCH_ERR_DEFINE                   Pay_For_Users_Flag7.bit.Wai_SWITCH_ERR
/*"**********************************************************************************"*/
/*" ���״̬�� "*/
union Pay_For_Users_Flag8
    {
    struct
        {
        unsigned char BuyCountZero:1;		/*" 1:����ʱ�������Ϊ0,Ҳ�ܿ���"*/
        unsigned char :1;
        unsigned char :1;	/*""*/
        unsigned char :1;	/*""*/
        unsigned char :1;   /*""*/
        unsigned char :1;	/*""*/
        unsigned char SWITCH_PROHIBIT_ACT:1;	/*" 1:��բ�̵�����ֹ����"*/
        unsigned char SWITCH_PREPARE_STATE:1;	/*" �̵���׼��������״̬->1:��բ,0:��բ"*/
        }bit;
    unsigned char  intd;
    };
//#define BuyCountZero_DEFINE			Pay_For_Users_Flag8.bit.BuyCountZero
//#define 
//#define 
//#define 
//#define 
//#define 
#define SWITCH_PROHIBIT_ACT_DEFINE   	Pay_For_Users_Flag8.bit.SWITCH_PROHIBIT_ACT
#define SWITCH_PREPARE_STATE_DEFINE   	Pay_For_Users_Flag8.bit.SWITCH_PREPARE_STATE
/*"**********************************************************************************"*/
/*"�����������״̬�֣�2014Ҫ��"*/
union _FAY_CTL_RES_ERR
    {
    struct
        {
        unsigned char Hang:1;       	/*"������:����ڹ���״̬ʱ����"*/
        unsigned char MacErr:1;			/*"MAC����:���Ľ���MACУ�����"*/
	    unsigned char PassErr:1;		/*"�������/δ��Ȩ:���δ�ἰ�Ĵ����쳣Ӧ��ʱ�����ظô�����"*/
        unsigned char NoIden:1;			/*"�����֤��ʱ:�����֤��ʱ�����δ���������֤ʱ����"*/
        unsigned char TimeErr:1;		/*"ִ��ʱ����Ч:������Ч��ֹʱ��ʧЧ"*/
        unsigned char OpenFriErr:1;		/*"��բʧ��(����):��ǰ��ƴ��ڱ���״̬�½��յ���բ����ʱ����"*/
        unsigned char WarnFriErr:1;		/*"Ԥ��բʧ��(����):��ǰ��ƴ��ڱ���״̬�½��յ�Ԥ��բ����ʱ����"*/
        unsigned char WarnTimeErr:1;	/*"Ԥ��բ����ʱ����Ч:Ԥ��բ����ʱ��Ϊ0��R2=0��"*/		
		unsigned char WarnOpenErr:1;	/*"Ԥ��բʧ��(��բ):��ǰ��ƴ���Զ����բ���߱�����բ������2�����㡢͸֧���ޣ�ʱ���յ�Ԥ��բ����ʱ����"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B15:1;
        }bit;
    unsigned int  intd;
    };

//#define
//#define
//#define 
//#define 
//#define 
//#define 
//#define 
/*"**********************************************************************************"*/
/*"��������ִ��״̬�֣�2014Ҫ��"*/
union _FAY_CTL_RES_OK
    {
    struct
        {
        unsigned char DirCls:1; 	/*"ֱ�Ӻ�բ:�����ղ��ɹ�����ֱ�Ӻ�բ����ʱӦ�� "*/
        unsigned char AllowCls:1;	/*"�����բ:�����ղ��ɹ�������բ��������ʱӦ��"*/
        unsigned char DirOpen:1;	/*"ֱ����բ:�����ղ��ɹ�������բ�����ǰ��բ��ʱʱ������Ϊ0ʱ��ʱӦ��"*/
        unsigned char DelayOpen:1;	/*"��ʱ��բ(��բ��ʱʱ��):�����ղ��ɹ�������բ�����ǰ��բ��ʱʱ������Ϊ��0ʱ��ʱӦ��"*/
        unsigned char Warn:1;		/*"Ԥ��բ:�����ղ��ɹ�����Ԥ��բ���Ԥ��բ��ֱ�Ӻ�բ��Ԥ��բ���բ���������Ҳ����ڴ������ʱ״��ʱӦ��"*/
        unsigned char CurrDelay:1;	/*"��ʱ��բ(�����):�����ղ��ɹ�������բ��Ԥ��բ���Ԥ��բ��ֱ�Ӻ�բ��Ԥ��բ���բ���������Ҵ��ڴ������ʱ״��ʱӦ��"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char Friend:1;		/*"����:�����ղ��ɹ�������������ʱӦ��"*/
        unsigned char FriFree:1;	/*"������:�����ղ��ɹ���������������ʱӦ��"*/
        unsigned char Alarm:1;		/*"����:�����ղ��ɹ�������������ʱӦ��"*/
        unsigned char AlarmFree:1;	/*"�������:�����ղ��ɹ����������������ʱӦ��"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B15:1;
        }bit;
    unsigned int  intd;
    };
/*"**********************************************************************************"*/
/*" �������״̬��8������բ������״̬�� (���������ļ�Ҫ��) "*/
union Pay_For_Users_Flag10
    {
    struct
        {
        unsigned char RELAY_ORDER_STATE:1;         /*" ����բ����״̬��0:��բ��1����բ "*/
        unsigned char RELAY_CURR_STATE:1;          /*" ����բʵ��״̬��0:��բ��1����բ "*/
        unsigned char SWITCH_MODE:1;					/*"��ǰ����բ��ʽ(0��ƽ,1��������)"*/
        unsigned char button_free_far_alarm_cmd:1;          /*" �Ѿ��������Զ�̱���(�̵�������) "*/
        unsigned char button_free_low_zero_alarm:1;         /*" �Ѿ�����������С��0���� "*/
        unsigned char button_free_low_alarm2:1;             /*" �Ѿ�����������С�ڱ������2���� "*/
        unsigned char :1;
        unsigned char :1;
        unsigned char ALARM_ORDER_STATE:1;          /*" ��������״̬��0:������1�������� "*/
        unsigned char ALARM_CURR_STATE:1;           /*" ����ʵ��״̬��0:������1�������� "*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;       
        }bit;
    unsigned int  intd;
    };
#define SWITCH_MODE_DEFINE         		 		Pay_For_Users_Flag10.bit.SWITCH_MODE
#define BUTTON_FREE_FAR_ALRAM_DEFINE               Pay_For_Users_Flag10.bit.button_free_far_alarm_cmd 
#define BUTTON_FREE_LOW_ZERO_ALARM_DEFINE          Pay_For_Users_Flag10.bit.button_free_low_zero_alarm 
#define BUTTON_FREE_LOW_ALARM2_DEFINE              Pay_For_Users_Flag10.bit.button_free_low_alarm2  
//#define 
//#define 
//#define
//#define 
//#define 
//#define 
//#define 
//#define 
/*"**********************************************************************************"*/
/*" ����բ������������ (���������ļ�Ҫ��) "*/
union Pay_For_Users_Flag11
    {
    struct
        {
        unsigned char REALY_ON_OFF_KIND:1;        /*" ����բ��ʽ��0��ƽ��1�������壩 "*/
        unsigned char LCD_TRIFF_SLOT:1;              /*"Һ���٢���������(0��ʾ1��2��ʱ�Σ�1��ʾ1��2�׷���)"*/
        unsigned char EVENT_REPORT_MODE_SELECT:1;  /*"�����ϱ�ģʽ (0�����ú�����־��1���ú�����־)"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        }bit;
    unsigned char  intd;
    };
#define REALY_ON_OFF_KIND_DEFINE         Pre_Payment_Para.Pay_For_Users_Flag11.bit.REALY_ON_OFF_KIND
#define LCD_TRIFF_SLOT_DEFINE        	 Pre_Payment_Para.Pay_For_Users_Flag11.bit.LCD_TRIFF_SLOT
#define EVENT_REPORT_MODE_SELECT_DEFINE        	 Pre_Payment_Para.Pay_For_Users_Flag11.bit.EVENT_REPORT_MODE_SELECT

//#define
//#define
//#define 
//#define 
//#define 
//#define 
//#define 
/*"**********************************************************************************"*/
/*" �Զ�����籣���־�� "*/
union Pay_For_Users_Flag12
    {
    struct
        {
        unsigned char TRIFF_SWITCH_FLAG:1;        /*" 1:�����Ѿ��л� "*/
        unsigned char STEP_SWITCH_FLAG:1;         /*" 1:�ݶ��Ѿ��л� "*/
        unsigned char FAR_OPEN_PREPARE:1;    /*" 1:Զ�̷�����բ����,�̵���׼������"*/
        unsigned char Wai_SWITCH_CLOSE:1;	/*"1:���ñ��Ѿ��ɹ���բ(�жϵ��й�����)"*/
        unsigned char FAR_OPEN_SWITCH:1;  	/*"1:Զ����բ��־ "*/
        unsigned char NOT_CLOSE_BY_30A:1; 	/*"1: ����30A����������ƶ�û����բ"*/
        unsigned char FAR_OPEN_ALARM:1;    	/*"1:Զ�̱�����־ "*/
        unsigned char FAR_CLOSE_ALARM:1;  		/*"1:Զ�̱�����־ "*/
        }bit;
    unsigned char  intd;
    };
#define TRIFF_SWITCH_FLAG_DEFINE       	Pre_Payment_Para.Pay_For_Users_Flag12.bit.TRIFF_SWITCH_FLAG
#define STEP_SWITCH_FLAG_DEFINE       	Pre_Payment_Para.Pay_For_Users_Flag12.bit.STEP_SWITCH_FLAG
#define FAR_OPEN_PREPARE_DEFINE		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE
#define Wai_SWITCH_CLOSE_DEFINE		Pre_Payment_Para.Pay_For_Users_Flag12.bit.Wai_SWITCH_CLOSE
#define FAR_OPEN_SWITCH_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH
#define NOT_CLOSE_BY_30A_DEFINE     	Pre_Payment_Para.Pay_For_Users_Flag12.bit.NOT_CLOSE_BY_30A
#define FAR_OPEN_ALARM_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_ALARM
#define FAR_CLOSE_ALARM_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_CLOSE_ALARM

/*"**********************************************************************************"*/
/*" �Զ�����籣���־�� "*/
union Pay_For_Users_Flag13
    {
    struct
        {
        unsigned char METER_IN_FRIEND_DAY:1;/*"1:�����־ "*/
        unsigned char REMAIN_MONEY_OVER_CLUB:1;
		unsigned char FAR_WARN_1D:1;		/*"1:Ԥ��բ(��ʱʱ�䵽ֱ�Ӻ�բ)"*/
		unsigned char FAR_WARN_1E:1;   		/*"1:Ԥ��բ(��ʱʱ�䵽��բ����)"*/
	 	unsigned char FAR_OPEN_CMD:1;    		/*" 1:Զ�̷�����բ����,Ҫ������բ"*/
        unsigned char FAR_OPRATE_ID:1;		/*" 1:Զ����բ����"*/
        unsigned char OPRATE_ID_CLOSE:1;	/*" 1:��բ��������Զ����բ"*/
        unsigned char SWITCH_ALLOW_CLOSE:1;	/*" 1:���ø��ɿ���,���ð�(�Ϸ����·�)������3����к�բ"*/
        }bit;
    unsigned char  intd;
    };
#define METER_IN_FRIEND_DAY_DEFINE             Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY
#define REMAIN_MONEY_OVER_CLUB_DEFINE      Pre_Payment_Para.Pay_For_Users_Flag13.bit.REMAIN_MONEY_OVER_CLUB
#define FAR_WARN_1D_DEFINE     				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D
#define FAR_WARN_1E_DEFINE    				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E
#define FAR_OPEN_CMD_DEFINE    				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPEN_CMD
#define FAR_OPRATE_ID_DEFINE    			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID
#define OPRATE_ID_CLOSE_DEFINE    			Pre_Payment_Para.Pay_For_Users_Flag13.bit.OPRATE_ID_CLOSE
#define SWITCH_ALLOW_CLOSE_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag13.bit.SWITCH_ALLOW_CLOSE

/*"**********************************************************************************"*/
/*" �Զ�����籣���־�� "*/
union Pay_For_Users_Flag14
    {
    struct
        {
        unsigned char FAR_OPEN_RECORD:1;
        unsigned char FAR_CLOSE_RECORD:1;
        unsigned char SWITCH_FACT:1;		/*"�̵���ʵ��״̬1:��բ,0:��բ"*/
        unsigned char FUN_BUY_FLAG:1;
        unsigned char FRIEND_RELEASE_SWITCH_FLAG:1;
        unsigned char DIRECT_CLOSE_SWITCH:1;
        unsigned char is_year_bill:1;       /*" ��ǰ�Ƿ����������� "*/
        unsigned char CREATE_ZERO:1;		/*"1:�������Ϊ0������,�������Ϊ1ʱ�ܽ��ܿ������͹��翨"*/ 
        }bit;
    unsigned char  intd;
    };
#define FAR_OPEN_RECORD_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.FAR_OPEN_RECORD
#define FAR_CLOSE_RECORD_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.FAR_CLOSE_RECORD
#define SWITCH_FACT_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT
#define FUN_BUY_FLAG_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.FUN_BUY_FLAG

#define FRIEND_RELEASE_SWITCH_FLAG_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.FRIEND_RELEASE_SWITCH_FLAG
#define DIRECT_CLOSE_SWITCH_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.DIRECT_CLOSE_SWITCH



#define YEAR_BILL_FLAG              Pre_Payment_Para.Pay_For_Users_Flag14.bit.is_year_bill
#define CREATE_ZERO_DEFINE  		Pre_Payment_Para.Pay_For_Users_Flag14.bit.CREATE_ZERO

/*"**********************************************************************************"*/
/*" �Զ�����籣���־�� "*/
union Pay_For_Users_Flag15
    {
    struct
        {
        unsigned char LocalOpen:1;				/*"1:�����ѿ���"*/
        unsigned char FarOpen:1;				/*"1:Զ���ѿ���"*/
        unsigned char RelayErrFlag:1;			/*"1:�����˸��ɿ�������,0:�����¼�����.�����籣�桿"*/
        unsigned char RelayErrCheck:1;			/*"1:�Ѽ�⵽����������,�������η�ת֮��ֻ����һ��"*/		
        unsigned char :1;
        unsigned char :1;
        unsigned char PowerOnYearBill_flag:1;
        unsigned char to_upd_psw:1;
        }bit;
    unsigned char  intd;
    };
#define STATUS_LOCALOPEN_DEFINE			Pre_Payment_Para.Pay_For_Users_Flag15.bit.LocalOpen
#define STATUS_FAROPEN_DEFINE			Pre_Payment_Para.Pay_For_Users_Flag15.bit.FarOpen
#define STATUS_RELAYERR_DEFINE			Pre_Payment_Para.Pay_For_Users_Flag15.bit.RelayErrFlag
#define RelayErrCheck_DEFINE			Pre_Payment_Para.Pay_For_Users_Flag15.bit.RelayErrCheck
//#define 
//#define
#define POWERONYEARBILL_FLAG_DEFINE		Pre_Payment_Para.Pay_For_Users_Flag15.bit.PowerOnYearBill_flag
#define TO_UPD_PSW_DEFINE				Pre_Payment_Para.Pay_For_Users_Flag15.bit.to_upd_psw

//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
//#define 
//#define
/*"**********************************************************************************"*/
/*" �Զ����־�� "*/
union Pay_For_Users_Flag16
    {
    struct
        {
        unsigned char REMAIN_BAG_DOING:1;		/*"1=Զ�̲�ѯʱǮ���ļ��Ѿ��۳���־"*/
        unsigned char EVENT_OCCUR:1;			/*"1:���¼��ϱ�Ҫ��"*/
        unsigned char WAI_RELAY_PULSE_DOING:1;	/*"0 �� ���ü̵������巽ʽδִ����բ����"*/
        unsigned char LCD_Triff_Flag:1;			/*"Һ��������ʾ"*/
        unsigned char LCD_Step_Flag:1;				
        unsigned char :1;
        unsigned char Bill_Date_Change_Switch:1;	/*"1:�ݶ��л�ʱ��������ղ�ͬ"*/
        unsigned char Bill_Date_Change_Modify:1;	/*"1:�ݶ��л�ʱ��������ղ�ͬ"*/
        }bit;
    unsigned char  intd;
    };
#define REMAIN_BAG_DOING_DEFINE         	Pay_For_Users_Flag16.bit.REMAIN_BAG_DOING   
#define EVENT_OCCUR_DEFINE					Pay_For_Users_Flag16.bit.EVENT_OCCUR
#define WAI_RELAY_PULSE_DOING_DEFINE		Pay_For_Users_Flag16.bit.WAI_RELAY_PULSE_DOING
#define LCD_TRIFF_FLAG_DEFINE				Pay_For_Users_Flag16.bit.LCD_Triff_Flag
#define LCD_STEP_FLAG_DEFINE				Pay_For_Users_Flag16.bit.LCD_Step_Flag
//#define 
#define	Bill_Date_Change_Switch_DEFINE		Pay_For_Users_Flag16.bit.Bill_Date_Change_Switch
#define	Bill_Date_Change_Modify_DEFINE		Pay_For_Users_Flag16.bit.Bill_Date_Change_Modify


/*"**********************************************************************************"*/


