/*"**********************************************************************************"*/
/*" 自定义标志字 "*/
union Pay_For_Users_Flag1
    {
    struct
        {
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM1:1;    /*" 1:剩余电费低于报警门限1 "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM2:1;    /*" 1:剩余电费低于报警门限2 "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_ZERO:1;      /*" 1:剩余电费低于零 "*/
        unsigned char FIRST_REMAIN_MONEY_LOW_TICK:1;      /*" 1:剩余电费低于赊欠门限 "*/
        unsigned char REMAIN_MONEY_OPEN_SWITCH:1;         /*" 1:剩余电费跳闸标志 "*/
        unsigned char STEP1_OR_STEP2:1;						/*" 1:扣费选梯度方案2，0：扣费选梯度方案1 "*/
        unsigned char REMAIN_MONEY_LOW_ZERO_FREE:1;       /*" 1:剩余电费低于零已经插卡解除 "*/
        unsigned char REMAIN_MONEY_LOW_ALARM2_FREE:1;     /*" 1:剩余电费低于报警门限2已经插卡解除 "*/
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
/*" 预付费模式字1 "*/
union Pay_For_Users_Flag2
    {
    struct
        {
        unsigned char REMAIN_MONEY_LOW_ZERO_SWITCH:1;      /*" 1:当剩余电费小于等于0时，不跳闸(赊欠有效的情况下) "*/
        unsigned char REMAIN_MONEY_LOW_ALARM2_SWITCH:1;    /*" 1:当剩余电费小于等于报警门限2时，跳闸报警 "*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char REMAIN_MONEY_LOW_ALARM1_SHOW:1;      /*" 1:当剩余电费小于等于报警门限1时，停显剩余电费 "*/ 
        }bit;
    unsigned char  intd;
    };
#define REMAIN_MONEY_LOW_ZERO_SWITCH_DEFINE        Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ZERO_SWITCH
#define REMAIN_MONEY_LOW_ALARM2_SWITCH_DEFINE      Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ALARM2_SWITCH
//#define 
//#define 
#define REMAIN_MONEY_LOW_ALARM1_SHOW_DEFINE        Pre_Payment_Para.Pay_For_Users_Flag2.bit.REMAIN_MONEY_LOW_ALARM1_SHOW
/*"**********************************************************************************"*/
/*" 预付费模式字2 "*/
union Pay_For_Users_Flag3
    {
    struct
        {
        unsigned char CLOSE_KEY_NE_RELAY:1;	/*" 1:内置表,合闸时不需要按健"*/ 
        unsigned char FRIEND_DAY_CLOSE:1;		/*" 1:保电不解除跳闸"*/ 
        unsigned char PUBLIC_CONTROL_RELAY:1;	/*" 1:开启明文跳合闸"*/ 
        unsigned char CLOSE_KEY_WAI_RELAY:1;	/*" 1:外置表,合闸时不需要按健"*/ 
        unsigned char WAION_ESAM:1;    			/*" 1:国网自管户ESAM,远程只有3条密钥"*/ 
        unsigned char :1;
        unsigned char Fay_30ALimit:1;			/*"1:远程30A电流限制功能"*/ 
        unsigned char Local_30ALimit:1;      	/*"1:本地30A电流限制功能"*/ 
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
/*" 预付费模式字3"*/
union Pay_For_Users_Flag4
    {
    struct
        {
        unsigned char SWITCH_ERR:1;				/*"1:测试ESAM,  0:正式ESAM"*/	//ESAM_TEST
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B1:1;
        unsigned char SpicReq_SC:1;		/*"1:四川特殊要求澹(支持丰、平、枯水期电价，支持按日时段数抄读费率编程事件)"*/	//spicial require
        }bit;
    unsigned char  intd;
    };
#define SWITCH_ERR_DEFINE                  Pre_Payment_Para.Pay_For_Users_Flag4.bit.SWITCH_ERR

//#define SpicReq_SC_DEFINE                  Pre_Payment_Para.Pay_For_Users_Flag4.bit.SpicReq_SC

/*"**********************************************************************************"*/
/*" 友好日周休日模式字 "*/
union Pay_For_Users_Flag5
    {
    struct
        {
        unsigned char FRIEND_SUNDAY:1;                /*" 1:周日工作 "*/
        unsigned char FRIEND_MONDAY:1;                /*" 1:周一工作 "*/
        unsigned char FRIEND_TUSEDAY:1;               /*" 1:周二工作 "*/
        unsigned char FRIEND_WEDNESDAY:1;             /*" 1:周三工作 "*/
        unsigned char FRIEND_THURSDAY:1;              /*" 1:周四工作 "*/
        unsigned char FRIEND_FRIDAY:1;                /*" 1:周五工作 "*/
        unsigned char FRIEND_SATURDAY:1;              /*" 1:周六工作 "*/ 
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
/*" 远程预付费状态字 "*/
union Pay_For_Users_Flag6
    {
    struct
        {
        unsigned char FAY_CTL_RES:1;       			/*"1:应答帧中增加电能表运行状态"*/
        unsigned char Curr_30A_Flg:1;				/*"1:内置表的当前电流大于30A"*/
        unsigned char Curr_30A_Start_Cnt:1;			/*"1:在30A电流下发了拉闸命令,开始计时"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char Pay_Buy_Money_Flg:1;			/*"1:远程开户、购电、退费发生后强制2次备份,防止掉上电后,表计进入低功耗被第2次复位打断时,取出备份区数据的数据,致使电费丢失"*/
        unsigned char RecFlg:1;						/*"1:有事件记录发生变化时，保存显示内容，使其能在低功耗下显示"*/
        unsigned char COMM_ALL_AA:1;				/*"1:全A地址通配符时,03命令允许数据回抄、状态查询、红外认证、身份认证、程序比较"*/
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
/*" 表计运行状态字 "*/
union Pay_For_Users_Flag7
    {
    struct
        {
        unsigned char OVER_POWER_CLUE:1;                /*" 1:超功率提示 "*/
        unsigned char REMAIN_MONEY_LOW_ALARM1_CLUE:1;   /*" 1:剩余电费低于报警门限1提示 "*/ 
        unsigned char REMAIN_MONEY_LOW_ALARM2_CLUE:1;   /*" 1:剩余电费低于报警门限2提示 "*/ 
        unsigned char REMAIN_MONEY_LOW_ZERO_CLUE:1;     /*" 1:剩余电费低于零提示 "*/
        unsigned char REMAIN_MONEY_LOW_TICK_CLUE:1;     /*" 1:剩余电费低于赊欠门限提示 "*/
        unsigned char SWITCH_ERR_CLUE:1;                /*" 继电器故障提示(内置继电器)"*/
        unsigned char ESAM_ERR:1;						/*" 1:ESAM错误 "*/
        unsigned char Wai_SWITCH_ERR:1;					/*"外置继电器故障"*/
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
/*" 表计状态字 "*/
union Pay_For_Users_Flag8
    {
    struct
        {
        unsigned char BuyCountZero:1;		/*" 1:开户时购电次数为0,也能开户"*/
        unsigned char :1;
        unsigned char :1;	/*""*/
        unsigned char :1;	/*""*/
        unsigned char :1;   /*""*/
        unsigned char :1;	/*""*/
        unsigned char SWITCH_PROHIBIT_ACT:1;	/*" 1:跳闸继电器禁止动作"*/
        unsigned char SWITCH_PREPARE_STATE:1;	/*" 继电器准备动作的状态->1:跳闸,0:合闸"*/
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
/*"控制命令错误状态字，2014要求"*/
union _FAY_CTL_RES_ERR
    {
    struct
        {
        unsigned char Hang:1;       	/*"电表挂起:电表处于挂起状态时返回"*/
        unsigned char MacErr:1;			/*"MAC错误:密文解密MAC校验错误"*/
	    unsigned char PassErr:1;		/*"密码错误/未授权:表格未提及的错误，异常应答时均返回该错误字"*/
        unsigned char NoIden:1;			/*"身份认证超时:身份认证超时后或者未进行身份认证时返回"*/
        unsigned char TimeErr:1;		/*"执行时间无效:命令有效截止时间失效"*/
        unsigned char OpenFriErr:1;		/*"跳闸失败(保电):当前表计处于保电状态下接收到跳闸命令时返回"*/
        unsigned char WarnFriErr:1;		/*"预跳闸失败(保电):当前表计处于保电状态下接收到预跳闸命令时返回"*/
        unsigned char WarnTimeErr:1;	/*"预跳闸持续时间无效:预跳闸持续时间为0（R2=0）"*/		
		unsigned char WarnOpenErr:1;	/*"预跳闸失败(跳闸):当前表计处于远程跳闸或者本地跳闸（报警2、过零、透支门限）时接收到预跳闸命令时返回"*/
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
/*"控制命令执行状态字，2014要求"*/
union _FAY_CTL_RES_OK
    {
    struct
        {
        unsigned char DirCls:1; 	/*"直接合闸:电表接收并成功解析直接合闸命令时应答 "*/
        unsigned char AllowCls:1;	/*"允许合闸:电表接收并成功解析合闸允许命令时应答"*/
        unsigned char DirOpen:1;	/*"直接跳闸:电表接收并成功解析拉闸命令（当前跳闸延时时间设置为0时）时应答"*/
        unsigned char DelayOpen:1;	/*"延时跳闸(跳闸延时时间):电表接收并成功解析拉闸命令（当前跳闸延时时间设置为非0时）时应答"*/
        unsigned char Warn:1;		/*"预跳闸:电表接收并成功解析预跳闸命令（预跳闸后直接合闸、预跳闸后合闸允许），并且不处于大电流延时状况时应答"*/
        unsigned char CurrDelay:1;	/*"延时跳闸(大电流):电表接收并成功解析跳闸、预跳闸命令（预跳闸后直接合闸、预跳闸后合闸允许），并且处于大电流延时状况时应答"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char Friend:1;		/*"保电:电表接收并成功解析保电命令时应答"*/
        unsigned char FriFree:1;	/*"保电解除:电表接收并成功解析保电解除命令时应答"*/
        unsigned char Alarm:1;		/*"报警:电表接收并成功解析报警命令时应答"*/
        unsigned char AlarmFree:1;	/*"报警解除:电表接收并成功解析报警解除命令时应答"*/
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B15:1;
        }bit;
    unsigned int  intd;
    };
/*"**********************************************************************************"*/
/*" 电表运行状态字8（拉合闸、报警状态） (国网备案文件要求) "*/
union Pay_For_Users_Flag10
    {
    struct
        {
        unsigned char RELAY_ORDER_STATE:1;         /*" 拉合闸命令状态，0:合闸，1：拉闸 "*/
        unsigned char RELAY_CURR_STATE:1;          /*" 拉合闸实际状态，0:合闸，1：拉闸 "*/
        unsigned char SWITCH_MODE:1;					/*"当前拉合闸方式(0电平,1连续脉冲)"*/
        unsigned char button_free_far_alarm_cmd:1;          /*" 已经按键解除远程报警(继电器报警) "*/
        unsigned char button_free_low_zero_alarm:1;         /*" 已经按键解除电费小于0报警 "*/
        unsigned char button_free_low_alarm2:1;             /*" 已经按键解除电费小于报警金额2报警 "*/
        unsigned char :1;
        unsigned char :1;
        unsigned char ALARM_ORDER_STATE:1;          /*" 报警命令状态，0:报警，1：不报警 "*/
        unsigned char ALARM_CURR_STATE:1;           /*" 报警实际状态，0:报警，1：不报警 "*/
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
/*" 拉合闸、报警特征字 (国网备案文件要求) "*/
union Pay_For_Users_Flag11
    {
    struct
        {
        unsigned char REALY_ON_OFF_KIND:1;        /*" 拉合闸方式（0电平，1连续脉冲） "*/
        unsigned char LCD_TRIFF_SLOT:1;              /*"液晶①②字样意义(0显示1、2套时段，1显示1、2套费率)"*/
        unsigned char EVENT_REPORT_MODE_SELECT:1;  /*"主动上报模式 (0不启用后续标志，1启用后续标志)"*/
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
/*" 自定义掉电保存标志字 "*/
union Pay_For_Users_Flag12
    {
    struct
        {
        unsigned char TRIFF_SWITCH_FLAG:1;        /*" 1:费率已经切换 "*/
        unsigned char STEP_SWITCH_FLAG:1;         /*" 1:梯度已经切换 "*/
        unsigned char FAR_OPEN_PREPARE:1;    /*" 1:远程发了跳闸命令,继电器准备动作"*/
        unsigned char Wai_SWITCH_CLOSE:1;	/*"1:外置表已经成功合闸(判断到有功率了)"*/
        unsigned char FAR_OPEN_SWITCH:1;  	/*"1:远程跳闸标志 "*/
        unsigned char NOT_CLOSE_BY_30A:1; 	/*"1: 由于30A大电流的限制而没有跳闸"*/
        unsigned char FAR_OPEN_ALARM:1;    	/*"1:远程报警标志 "*/
        unsigned char FAR_CLOSE_ALARM:1;  		/*"1:远程报警标志 "*/
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
/*" 自定义掉电保存标志字 "*/
union Pay_For_Users_Flag13
    {
    struct
        {
        unsigned char METER_IN_FRIEND_DAY:1;/*"1:保电标志 "*/
        unsigned char REMAIN_MONEY_OVER_CLUB:1;
		unsigned char FAR_WARN_1D:1;		/*"1:预跳闸(延时时间到直接合闸)"*/
		unsigned char FAR_WARN_1E:1;   		/*"1:预跳闸(延时时间到合闸允许)"*/
	 	unsigned char FAR_OPEN_CMD:1;    		/*" 1:远程发了跳闸命令,要按键合闸"*/
        unsigned char FAR_OPRATE_ID:1;		/*" 1:远程跳闸代码"*/
        unsigned char OPRATE_ID_CLOSE:1;	/*" 1:合闸的起因是远程跳闸"*/
        unsigned char SWITCH_ALLOW_CLOSE:1;	/*" 1:内置负荷开关,采用按(上翻或下翻)键超过3秒进行合闸"*/
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
/*" 自定义掉电保存标志字 "*/
union Pay_For_Users_Flag14
    {
    struct
        {
        unsigned char FAR_OPEN_RECORD:1;
        unsigned char FAR_CLOSE_RECORD:1;
        unsigned char SWITCH_FACT:1;		/*"继电器实际状态1:跳闸,0:合闸"*/
        unsigned char FUN_BUY_FLAG:1;
        unsigned char FRIEND_RELEASE_SWITCH_FLAG:1;
        unsigned char DIRECT_CLOSE_SWITCH:1;
        unsigned char is_year_bill:1;       /*" 当前是否是年结算阶梯 "*/
        unsigned char CREATE_ZERO:1;		/*"1:购电次数为0开户后,购电次数为1时能接受开户卡和购电卡"*/ 
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
/*" 自定义掉电保存标志字 "*/
union Pay_For_Users_Flag15
    {
    struct
        {
        unsigned char LocalOpen:1;				/*"1:本地已开户"*/
        unsigned char FarOpen:1;				/*"1:远程已开户"*/
        unsigned char RelayErrFlag:1;			/*"1:发生了负荷开关误动作,0:误动作事件结束.【掉电保存】"*/
        unsigned char RelayErrCheck:1;			/*"1:已检测到发生了误动作,开关两次反转之间只进行一次"*/		
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
/*" 自定义标志字 "*/
union Pay_For_Users_Flag16
    {
    struct
        {
        unsigned char REMAIN_BAG_DOING:1;		/*"1=远程查询时钱包文件已经扣除标志"*/
        unsigned char EVENT_OCCUR:1;			/*"1:有事件上报要求"*/
        unsigned char WAI_RELAY_PULSE_DOING:1;	/*"0 ＝ 外置继电器脉冲方式未执行跳闸操作"*/
        unsigned char LCD_Triff_Flag:1;			/*"液晶费率显示"*/
        unsigned char LCD_Step_Flag:1;				
        unsigned char :1;
        unsigned char Bill_Date_Change_Switch:1;	/*"1:梯度切换时，年结算日不同"*/
        unsigned char Bill_Date_Change_Modify:1;	/*"1:梯度切换时，年结算日不同"*/
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


