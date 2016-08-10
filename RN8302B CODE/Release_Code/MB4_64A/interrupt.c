/******************************************************************************************
*                      fine:      interrupt.c                                                  *
*                      function:  interrupt functions                                          *
*******************************************************************************************/  
#include "sfr64a.h"    //mw added 2010-04-30
#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "comm.h"
#include "initram.h"
#include "initcpu.h"
#include "Powerdown_LDH.h"
#include "Init_program_LDH.H"  //mw added 2010-04-30
#include "I2C_operation.h"
#include "eventnew.h"
#include "MB_Keymain.h"
#include "Demand.h"
#include "MB_Showmain.h"
#include "Measure_Interface.h" 
#include "AllVoltageLoss.h"//ganjp 20090326
#include "multi.h"
#include "Energy_Del.H"
#include "pay_def.h"							//payment
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"
#include "ICcard.h"
#include "loadrecord.h"

#define MAX_DS_NUM 10

#define MAXFARWAKEUPTIME 1209600
#define FARWAKEUPRELAY 10
#define FARWAKEUPLIMITCYCLE 172800
#define FARWAKEUPLIMITTIMES 30

void CalPowerDownEnergy(void);
void PDIOtest(void);
void IniPdInterrupt(void);
void PDSavedata(void);
void ClearDatePoerDown(void);
void PowerDownDisplayInit(void);
void CheckPowerDownDisplayTimes(void);
void PrepareforPowerdown(void);
void TimerA2_Int_Interrupt(void);
void  Energy_Compare(unsigned long *ComPtr1,unsigned long *ComPtr2, unsigned long *aimPtr );
void	Goto_Stop_Exit_Stop(void);  //2010
void	Goto_StopMode(void);//2010
void ReadCurrPDInitMeasure(void);
void Dispose_ReadCurr_PD(void);//2010
void PreDispose_for_ClearFlag(void);//2010
void FirstEntry_Dispose(void);  //2010
void Mode_Judge(void);//2010
//void	Switch_to_125KClock_Other(void);			
void	Enable_10MAnd125K_Clock(void);
void FarWakeUpCheck(void);	

#define SH_CYC_SHOW_TIME 30    /*"低功耗循显时间"*/
#define SH_DROP_SHOW_TIME 720  /*"低功耗显示时间"*/




 unsigned  char pdmode1,pdmode2;     /*"pdmode1:低功耗处于显示；pdmode2:低功耗处于通讯；"*/
volatile unsigned  int PowerdownDisplayCyleAdd;  /*"低功耗循显计数器。"*/
volatile unsigned  int  PowerdownDisplayOverAdd; /*"低功耗循显计数器"*/ //2010
volatile unsigned  int  PowerdownStopCommAdd;    /*"低功耗唤醒3分钟计数器"*/ //2010
volatile unsigned int Powerdown_TempTimeAdd; 
/*"下面两项数据必须定义在一起，方便上电数据转移"*/
volatile unsigned char Valid_IntoPowerdown_Flag[8]; 
//volatile unsigned char Valid_PD_Curr_Flag[8]; //ganjp 20091104

unsigned char FirstInterPowerDown=0;  /*"进入wait模式前处理标志"*/
volatile unsigned  char IntoPowerDownFlag=0;  /*"进入低功耗运行标志"*/
//unsigned char Open_Enable_INT5=0;   /*"打开红外唤醒标志"*/
unsigned char pdmode2flag=0;  /*"有通讯，无显示，开显示标志"*/

unsigned  char pdmode3;     /*"pdmode3:低功耗处于全失压唤醒"*///ganjp 20090325
extern  unsigned long EventIb;//ganjp 20090325

volatile unsigned  char pdmodekeyflag; /*"低功耗按键标志"*/
volatile unsigned  char PowerdownStopKeyAdd;/*"低功耗按键计数器"*/

volatile unsigned long  PDfirst_TimeAdd;  //mw added 2010-04-30
unsigned char keykick;   //mw added 2010-04-30
volatile unsigned char pdopencoverintflag[2];
unsigned char pdwakeupinitflag;
volatile unsigned char farwakeupreadyflag;
volatile unsigned char farwakeupreadycnt;
volatile unsigned char farwakeupreadytimes;

struct DROP_SHWO_HISTORY
{
	struct DATEANDTIME_DEF	time;
	char NO;
};
struct DROP_SHWO_HISTORY drop_shwo_history[MAX_DS_NUM]; /*"上3次进入低功耗显示的时间"*/


/*"低功耗1秒钟中断"*/
//#pragma INTERRUPT TimerA2_Int

typedef unsigned char BOOLEAN;
/*"低功耗500ms 中断mw modified 2010-04-30 "*/
void  TimerA2_Int_Interrupt(void)
{
	//@@@@@@@@@@@@@@@@
	unsigned int uni=0;
	//@@@@@@@@@@@@@@@@
		 
        if(PDfirst_TimeAdd<MAXFARWAKEUPTIME)
        {
          PDfirst_TimeAdd++;
          
          if((PDfirst_TimeAdd%FARWAKEUPLIMITCYCLE)==0)
            farwakeupreadytimes=0;
        }
        //PowerdownStopCommAdd+=1;
        PowerdownDisplayCyleAdd+=1;
        PowerdownDisplayOverAdd+=1;
	//@@@@@@@@@@@@@@@@
	Powerdown_TempTimeAdd+=1;
        //@@@@@@@@@@@@@@@@
        if(pdmode1)
        {
           if(PowerdownDisplayOverAdd>=Meter_Parameter.parameter1.CycleDisplayTime*2L)/*"循环显示时间"*/
	   //if(PowerdownDisplayOverAdd>=6*2L)
	   {	
        	pdmode1=0x33;
        	PowerdownDisplayOverAdd=0;
        	//Prepare_for_Wakeup();
           }
           if(PowerdownDisplayCyleAdd>=2L*Meter_Parameter.parameter1.CycleDisplayTime*(Meter_Parameter.parameter1.DisplayNumber)) /*(Meter_Parameter.KeyDisplayNumber+Meter_Parameter.DisplayNumber))*/  /*"退出低功耗显示时间"*/
	   //if(PowerdownDisplayCyleAdd>=2L*6*(14)) 
           {
        	pdmode1=0;
        	PowerdownDisplayCyleAdd=0;
           }
           
           pd_time_show_cnt++;
        }
        
	PowerdownStopCommAdd++;
	
	if(pdmodekeyflag==0xff)
	{
		uni=60;
	}
	else
	{
		uni=2L*Meter_Parameter.parameter1.CycleDisplayTime*Meter_Parameter.parameter1.DisplayNumber;
	}
	
	if(PowerdownStopCommAdd>=uni)
	{
	        pdmode2=0;
	        PowerdownStopCommAdd=0;
	}
	
	if((pdmodekeyflag==0xff))//&&(Meter_Parameter.MeterMode[1].bit.b1==0))
	{      
		PowerdownStopKeyAdd++;
		if(PowerdownStopKeyAdd>=30*2L)
	    {
			pdmodekeyflag=0;
			PowerdownStopKeyAdd=0;
			pdmode1=0;			
			PowerdownDisplayCyleAdd=0;
			pdmode2=0;
	        PowerdownStopCommAdd=0;
		}
		else if(!pdmode1)
		{
                        pdmode1=0x33;
                        PowerdownDisplayCyleAdd=0;
        }		
	}
	//@@@@@@@@@@@@@@@@
	//if((Powerdown_TempTimeAdd>3)&&(Powerdown_TempTimeAdd<10))
	if((Powerdown_TempTimeAdd>6)&&(Powerdown_TempTimeAdd<20))
	{
		for(uni=0;uni<8;uni++)		
		Valid_IntoPowerdown_Flag[uni]=uni;
	}
	#if(ALLLOSSVOLTAGE_MODE == 0)	
	AllVoltageLoss_SecondCounter_Updating();
	#else
	
    if(L_PD_Last_T<0xff)
    {
      L_PD_Last_T++;	
    }
  
  #endif
	
 	if(IsChangeBattery())
       {
		if(TempClockBatteryClearCounter<2*3L)
	      {
		  TempClockBatteryClearCounter++;
	      }
	}
	else{
		TempClockBatteryClearCounter=0;
	}
  
  
	AllVoltageLoss_counter++;
	
	if((farwakeupreadyflag==0xaa)&&(farwakeupreadycnt<=FARWAKEUPRELAY))
	  farwakeupreadycnt++;
	 	
}

#pragma INTERRUPT Uart0T_Int
void  Uart0T_Int(void)
{
	Interr_Comm_W(0);
}

#pragma INTERRUPT Uart0R_Int
void  Uart0R_Int(void)
{
	Interr_Comm_R(0);
}

#pragma INTERRUPT Uart1T_Int
void  Uart1T_Int(void)
{
	Interr_Comm_W(2);
}

#pragma INTERRUPT Uart1R_Int
void  Uart1R_Int(void)
{
	Interr_Comm_R(2);
}

#pragma INTERRUPT Uart2T_Int
void  Uart2T_Int(void)
{
	Interr_Comm_W(1);
}

#pragma INTERRUPT Uart2R_Int
void  Uart2R_Int(void)
{
	Interr_Comm_R(1);
}



#pragma INTERRUPT Uart6T_Int
void  Uart6T_Int(void)			//payment
{
ir_s6tic = 0;
//	Interr_Comm_W(1);
}
#pragma INTERRUPT Uart6R_Int
void  Uart6R_Int(void)
{
Receive_Data_To_Cpucard_CPU();
}
#pragma INTERRUPT Uart7T_Int
void  Uart7T_Int(void)			//payment
{
ir_s7tic = 0;
//	Interr_Comm_W(1);
}
#pragma INTERRUPT Uart7R_Int
void  Uart7R_Int(void)
{
Receive_Data_To_Cpucard();
}

#pragma INTERRUPT Int1_Int
void Int1_Int(void)
{
	int1ic&=0xF7;		//Clear IR register bit of INT1
	if(pdopencoverintflag[0]!=0x33)			
	  pdopencoverintflag[0]=0x33;
}

#pragma INTERRUPT Int7_Int
void Int7_Int(void)
{
	int7ic&=0xF7;		//Clear IR register bit of INT7			
	if(pdopencoverintflag[1]!=0x33)
	  pdopencoverintflag[1]=0x33;
}


/*"进入低功耗中断"*/
#pragma INTERRUPT Int2_Int
void  Int2_Int(void)
{
	 unsigned char flag=0;
	 unsigned char data=0;  /*"有低功耗干扰继续运行"*/
	 unsigned int uni=0;
        
	if(ir_int2ic)
	   ir_int2ic=0;
	   
	
	
        do
        {
           if(!V_D)
	   {
	      Delay(10);
	      if(!V_D)
	         flag=0xff; 
	   }
	   else
	   {
	      Delay(10);
	      if(V_D)
	      {
	   	 goto endofInt1;
	      }
	   }
	}while(!flag);  
        
        
	pdmodekeyflag=0; //mw  added 2010-05-15
		
	L_PD_Last_T = 0;
	PDfirst_TimeAdd=0; 
	keykick=0;//mw modified 2010-05-04
	
	tb0s=0;
   
	//@@@@@@@@@@@@@@@@
     IIC_SOFT_RESET();
  //@@@@@@@@@@@@@@@@
     ClockChipCloseSec();
     IntoPowerDownFlag=0xff;
     PrepareforPowerdown();
	//AllVoltageLoss_PowerDown_Init();   //mw closed 2009-03-23
	FirstInterPowerDown=0; 
	pdmode1=0x00;
	pdmode2=0x00;
	pdmode3=0x00;
	//FirstIntoPowerDownFlag=0;
	ChangeFromSubToMainCLK=0;
	//Open_Enable_INT5=0;
	pdmode2flag=0;   
	Delay(100);	
	//@@@@@@@@@@@@@@@@//mw modified 2009-03-23			
	AllVoltageLoss_PowerDown_Init();	
	Powerdown_TempTimeAdd=0;
	for(uni=0;uni<8;uni++)		
	{
	  Valid_IntoPowerdown_Flag[uni]=0;
	}
  	//@@@@@@@@@@@@@@@@	
    //pdmodekeyflag=0;   //mw closed 2010-05-15
	PdOpenCoverCheckInit(0);
	
	PowerdownStopKeyAdd=0;
	
	pdwakeupinitflag=0;
	farwakeupreadyflag=0;
	farwakeupreadycnt=0;
	farwakeupreadytimes=0;
  
	ta2s=1;
  
	Read_Volt_Powerdown();
    
	PdOpenCoverCheckInit(1);
	Initiallize_INT1();
	Initiallize_INT7();
    
	do
	{
		
		FirstEntry_Dispose();
	  	
	  Mode_Judge();
	  
	  ReadCurrPDInitMeasure();
	  
	  PdOpenCoverCheck();
		
	   if(pdmode1 || pdmode2 ||pdmode3||farwakeupreadyflag)
	   {
	      pdwakeupinitflag=0;
	      while(pdmode1 || pdmode2 || pdmode3||farwakeupreadyflag)
	      {     
	        	FarWakeUpCheck();
	        	
	        	if(pdmode1 || pdmode2)
	        	{
	        		if(pdwakeupinitflag==0)
	        		{
	        			pdwakeupinitflag=0xaa;
	        			Prepare_for_Wakeup(1);
		            clear_show_lcd();  //mw added 2010-05-04 ESP
	              CheckPowerDownDisplayTimes();
	              for(uni=0;uni<200;uni++);
	              if(pdmode1)
	              {
	                p3_2=1;   
	                PowerDownDisplayInit(); 
		              /*"改低功耗下不开远红外抄读有时候出现大电流的问题"*/	
                  //	         p8_0=0; /*"关内卡电源"*/ 
		              p7_3=0;   //mw added 2010-05-04
	                p3_2=0;	
	                
	                pd_now_show_code=0;	 
	              }
	              if(Meter_Parameter.parameter1.MeterMode[1].bit.b1)
	              {
	                 if(pdmode2)
	                 {
	                    pd0_5=0; 
			                //pd0_0=0; 	//1209
				              pd7_0=1; //DEBUG 
				              p7_0=1; //DEBUG
			                p7_3=1;   //mw added 2010-05-04
	                    p3_2=1;
	                    pd8_1=0;				/*"p81变为输入口"*///20050604   
				              pd7_1=0; //DEBUG   
	                    Init_Comm(1);
	                    InitTimeA0();    //mw  dispose 2010-04-21
                      ta1mr=0x27;
                      ta1=0x8000;
                      ta1s=0;
	                    s2ric=0x03;  //mw modified 2010-05-15
	                    s2tic=0x03;  //mw modified 2010-05-15				   
	                  }
	               }
	        		}
	        		
	        		
	        	if(pdmode1 || pdmode2)//ganjp 20090330
	      		{
	      			if(pdmode2)
	         {
	             Communication(0,0,0);
	             //Open_Enable_INT5=0;
	         }
	         else 
	         {
                    asm("	FCLR I");	        
	              ta0s=0;
	              ta1s=0;
	              //s1ric=0x00;
	              //s1tic=0x00;

	              s2ric=0x00;
	              s2tic=0x00;  //mw modified 2010-05-15
	              
	              ta0ic=0x00;
	              u2mr=0x00;  //mw modified 2010-05-15	       		
	              //pd6_6=1;
				  pd7_1=1; //DEBUG
	              //p6_6=0;
				  p7_1=0; //DEBUG
	              //pd6_7=1;
				  pd7_0=1; //DEBUG
	              //p6_7=0;
				  p7_0=0; //DEBUG
	              pd7_2=1;
	              p7_2=0;
//	              pd10_1=1;   
//	              p10_1=0;   
	              pd5_6=1;
	              p5_6=0;
	              pd5_7=1;
	              p5_7=0;
	              pd6_0=1;
	              p6_0=0;
//	              pd0_5=1;
//	              p0_5=0;   
			//pd0_0=1; 	//1209
			//p0_0=0;
//	               //p8_0=0;  //p8_0 dispose 2010-04-21
			p7_3=0;   //mw added 2010-05-04
	              asm("	FSET I");
		      ChangeFromSubToMainCLK=0;	 //GJP added 2008-11-07	  
	         }
	               
	               
	               
	         if(pdmode1)
	         {
	             if(pdmode1==0x33)
	             {  	


//	                     if(!pdmode2)
//	                     {
//	                          p6_7=1; 
//	                     }
//	                     pd0_5=0; 
//	                     p8_0=1;/*"开内卡电源"*/
	                     p3_2=1;
//	                     pd8_1=0;				/*"p81变为输入口"*///20050604	
//	                     pd10_1=0;  
                       
                       for(uni=0;uni<200;uni++);
                       	   
	             	     Enter_Dorp_Show();
	             	     Drop_Key_Main();

	//pd1_1=1;
	//port_value=p1_1;
	//p1_1=~port_value;				 
	                     
						 
	             	     pdmode1++;
	             	     PowerdownDisplayOverAdd=0;
	             	     if(!pdmode2)
	             	     {
//	             	        pd0_5=1;
//	             	        p0_5=0;   
				//pd0_0=1; 	//1209
				//p0_0=0;
//	             	        //p8_0=0;   //p8_0 dispose 2010-04-21
				p7_3=0;   //mw added 2010-05-04
	             	        p3_2=0;
	                        //p6_7=0;  
							p7_0=0; //DEBUG
				 if(pdmode3 != 0x33)
				 	{
				 	Switch_to_125KClock();  
					//mw dispose 2010-04-21
				 	//Prepare_for_Wait();
				 	}
	             	        
	                        ChangeFromSubToMainCLK=0;	
	                     }
	             }
	             if((kupic&0x07)==0)
	                kupic=3;
	             if(!pdmode2)	
	             	{
	             	if(pdmode3 != 0x33)
	             		{
	             		Goto_Wait_Exit_Wait(); 
	             		}  
	             	}
	             pdmode2flag=0;
	             
	             if(Meter_Parameter.parameter1.MeterMode[2].bit.b3==1)
	             {
	               Pd_Refresh_TimeShow_PerSec(); /*"低功耗下每秒刷新时间的显示"*/  
	             } 
	         }
	         else
	         {
	             if(pdmode2 && !pdmode2flag)
	             {
	                   pd0_5=0; 
				//pd0_0=0; 	//1209
//	                   //p8_0=1;  //p8_0 dispose 2010-04-21
				p7_3=1;   //mw added 2010-05-04
	                   p3_2=1;
//	                   pd10_1=0;   
	                   for(uni=0;uni<200;uni++);
	                   PowerDownDisplayInit(); 
	                   pdmode2flag=0xff;
	                   pdmode1=0x33;
	             }
	         }
		//mw dispose 2010-04-21 B
	         //if(!pdmode2 && FirstIntoPowerDownFlag && !Open_Enable_INT5)
	         //{
	            //Enable_INT5();  
	            //Open_Enable_INT5=0xff;
	         //}
	         //FirstIntoPowerDownFlag=1;  
	         //mw dispose 2010-04-21 E
	         
	         if(pdmode2 && !ChangeFromSubToMainCLK)  /*"唤醒后，或有显示时，再唤醒，初始化通讯"*/
	         {
	            Prepare_for_Wakeup(1);
	            //pd6_7=1;
				pd7_0=1; //DEBUG
	            //p6_7=1;
				p7_0=1; //DEBUG
	            pd0_5=0; 
			//pd0_0=0; 	//1209
//	            //p8_0=1;  //p8_0 dispose 2010-04-21
		    p7_3=1;   //mw added 2010-05-04
	            p3_2=1;
	            pd8_1=0;				/*"p81变为输入口"*///20050604
	            //pd6_6=0;   
				pd7_1=0; //DEBUG
//	            pd10_1=0;   
	            Init_Comm(1);
	            InitTimeA0();  //mw  dispose 2010-04-21
//	            IR_FAR_SELECT=0;
//	            pd10_1=0;
                    ta1mr=0x27;
                    ta1=0x8000;
                    ta1s=0;
	            //s1ric=0x03;
	            //s1tic=0x03;  //mw modified 2010-05-15
	            
	            s2ric=0x03;
	            s2tic=0x03;  //mw modified 2010-05-15
				
	            ChangeFromSubToMainCLK=1;
	         }
	      		}
	      	}
	         //----------ganjp 20090325----------------------
	         ReadCurrPDInitMeasure();
	         Dispose_ReadCurr_PD();	//mw modified 2010-04-23
           PdOpenCoverCheck();
          //----------ganjp 20090325---------------------- 
	         FirstInterPowerDown=0;
	         
	      };

	   }
	
	}while(1);
   
   
   
endofInt1:
        data=0;   
}

void Mode_Judge(void)
{
	
	if(PDfirst_TimeAdd<MAXFARWAKEUPTIME)
	{
	  if((keykick==0)&&(pdmode3!=0x33)&&(pdopencoverintflag[0]!=0x33)&&(pdopencoverintflag[1]!=0x33))	
	  { 	
		  Prepare_for_Wait_Mode();
			Initiallize_INT5();	
		  Switch_to_125KClock();			
		  Goto_Wait_Exit_Wait(); 	
	  }
	}
	else
	{
	  if((pdmode1==0)&&(pdmode2==0)&&(pdopencoverintflag[0]!=0x33)&&(pdopencoverintflag[1]!=0x33))
	  {
	     PULSE_PWR = 0;
		   Prepare_for_Wait_Mode();
		   Disable_INT5();
			 tabsr&=0xdf;
			 tbsr&=0xdf;		
		   Switch_to_125KClock();
		   Goto_StopMode();
	  }
	}
	 
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	 
}

/*void	Switch_to_125KClock_Other(void)			
	{
		unsigned char uni;
		/////////////////////Begin	
		prcr|=0x01;
		//cm0=0x20; 	
		cm0=0x24; 	
		prcr|=0x01;
		//cm1=0x20;  
		cm1=0xc0;  
		prcr|=0x01;
		//cm2=0x02;    
		cm2=0x0a;    
		//prcr|=0x01;
		prcr|=0x01;
		pclkr=0x03;   
		
		prcr=0x00;
		


		
			for(uni = 0; uni < 50; uni++)//powerdown lcd control problem
			{
				asm("nop");
			}		
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");	
		/////////////////////END
        }*/

void FirstEntry_Dispose(void)
{
         unsigned int uni=0;
		 
          if(!FirstInterPowerDown)
          {
              clear_show_lcd(); 
              Exit_Normal_Show();
	      
	      FirstInterPowerDown=0xff;
	      ChangeFromSubToMainCLK=0;
	      pdmode1=0;
        pdmode2=0;
        pdmode2flag=0; 
	      pdmode3=0x00;
	      keykick=0;//mw modified 2010-05-04
	      //Open_Enable_INT5=0;
	      u2mr&=0xf8;   //mw modified 2010-05-15
	      //Prepare_for_Wait_Mode();
//	      pd0_5=1; 
//	      p0_5=0;
		//pd0_0=1; 	//1209
		//p0_0=0;
	      //p8_0=0;  //p8_0 dispose 2010-04-21
		p7_3=0;   //mw added 2010-05-04	      
	      p3_2=0;
	      //pd6_7=1;
		  pd7_0=1; //DEBUG
	      //p6_7=0;
		  p7_0=0; //DEBUG
	      ta0s=0;
	      ta1s=0;
	      //s1ric=0x00;
	      //s1tic=0x00;  //mw modified 2010-05-15

	      s2ric=0x00;
	      s2tic=0x00;  //mw modified 2010-05-15
		  
	      ta0ic=0x00;  
	      kupic=0x03;
	      //Init_TB1_2(); 
	      for(uni=0;uni<200;uni++);
	      //Prepare_for_Wait_Mode();   //mw closed 2010-05-04
	      //Prepare_for_Wait();
	      //Switch_to_125KClock();  //mw closed 2010-05-04	
	      //Initiallize_INT5();		//2010  /*"尽量最后打开，防止干扰"*/
	  }
}

void ReadCurrPDInitMeasure(void)
{
	
	if((L_PD_Last_T>=PDOPEN6515RELAYTIME) && (Curr_RD_flag == 0)&&(pdmode3 == 0))  
  {
    if(PULSE_PWR == 0)
	  {
	    pdmode3 = 0x33;
	    AllVoltageLoss_init_Measure();
	  }
  }
  
}

void Dispose_ReadCurr_PD(void)
{
  unsigned char i;
  unsigned int uni;
  		
	if(pdmode3 == 0x33)
	{    	
		Just_meter_PD();
     
	   if(L_PD_Last_T > (PDOPEN6515RELAYTIME+7))
		 {
				if(load_flag == 0)
				{
				  if(L_PD_Last_T!=lastpdreadcurrtime)
				  {
				  	lastpdreadcurrtime=L_PD_Last_T;
				  	
				    Read_Curr_Powerdown();
				
				    if((V_REGION==0)||(V_REGION==3))
				    {
						  Curr[1]=0;
				    }
				
				    PD_max_curr= Curr[0];
				    for(i=1;i<3;i++)
				    {
					    if(PD_max_curr < Curr[i])
						    PD_max_curr = Curr[i];
				    }
				
				    if((PD_max_curr * 100l > 5L* Meter_Parameter.parameter1.EventJudgeIn)
				    &&(PD_max_curr < 30 * Meter_Parameter.parameter1.EventJudgeIn)&&(V_D==0))
				    {
					     PD_curr.Pd_Max_curr = PD_max_curr;
					     if((V_REGION==0)||(V_REGION==3))
					     {
						      PD_curr.Aver_curr = (Curr[0]+Curr[2])/2;
					     }
					     else
					     {
						      PD_curr.Aver_curr = (Curr[0]+Curr[1]+Curr[2])/3;
					     }
				    }
				    else if((PD_max_curr * 100l <= 5L* Meter_Parameter.parameter1.EventJudgeIn)
				    &&(V_D==0))
				    {
					     PD_curr.Pd_Max_curr = 0;
					     PD_curr.Aver_curr = 0;
					     AllVoltageLoss_Close_Measure();
				    }
				
				    for(uni=0;uni<3;uni++)
            {
               Curr[uni]=0;
            }
        }	
				
				if(L_PD_Last_T > (PDOPEN6515RELAYTIME+11))
				{
					 if((PD_curr.Pd_Max_curr * 100l > 5L* Meter_Parameter.parameter1.EventJudgeIn)
				   &&(PD_curr.Pd_Max_curr < 30 * Meter_Parameter.parameter1.EventJudgeIn))
				   {
					    for(uni=0;uni<8;uni++)
					    {
						    PD_curr.validflag[uni]=uni;
					    }
				   }
					 AllVoltageLoss_Close_Measure();
				}
				
			  }
			  else
			  {
			  	AllVoltageLoss_Close_Measure();
			  }
			}
			
  }

}	



void IniPdInterrupt(void)
{
        InitTimeA2();
        //s1ric=0x00;
	//s1tic=0x00;  //mw modified 2010-05-15
        s2ric=0x00;
	s2tic=0x00;  //mw modified 2010-05-15
	
	kupic=0;			/*"关闭按键中断"*/                        
//	pu25=1;		        /*"p10.4-p10.7 设为内部上拉"*/            
	pd10_4=0;	        //p10.4-p10.7 set this port is input port 
	//pd10_5=1;	        //p10.4-p10.7 set this port is input port 
	//p10_5=0;  //mw added 2010-05-04
	pd10_6=0;	        //p10.4-p10.7 set this port is input port 
	//pd10_7=1;	        //p10.4-p10.7 set this port is input port   
	//p10_7=0;  //mw added 2010-05-04
	//kupic=3;	
}


void ClearDatePoerDown(void)
{
	unsigned int uni;
	unsigned int unj;
	
	for(uni=0;uni<4;uni++)
	{
             Freq[uni]=0; 
             Factor[uni]=0;           
             Active_power[uni]=0;
             Reactive_power[uni]=0;
             Visual_power[uni]=0;
             Reactive_phase[uni]=0;
             Phase_Angle[uni]=0;
			//----------------------------------  //fxf added 090310
			 COMM_Active_power[uni]=0;
			 COMM_Reactive_power[uni]=0;
			 COMM_Visual_power[uni]=0;		
			 COMM_Factor[uni]=0;			 
        }
        for(uni=0;uni<3;uni++)
        {
           Volt[uni]=0;
           Curr[uni]=0;
		       COMM_Curr[uni]=0;//fxf added 090310
        }
        N_Current=0;
        Meter_States.Meter_Status2.byte=0;
#ifdef  DEMAND_CLR_KEY
        Show_flag.bit.key=0;
#endif
        Meter_States.Err_Infor.intd=0;
				
	//----------------------------------  //fxf added 081114
        NEW645Meter_States.Meter_Status1.intd=0;	
        NEW645Meter_States.Meter_Status2.intd=0;	
        NEW645Meter_States.Meter_Status4.intd=0;	
        NEW645Meter_States.Meter_Status5.intd=0;
        NEW645Meter_States.Meter_Status6.intd=0;			
        NEW645Meter_States.Meter_Status7.intd=0x0020;
if (MACRO_LOCAL_PAY_FLAG || MACRO_FAY_CONTROL_FLAG)	//payment
        NEW645Meter_States.Meter_Status3.intd=(NEW645Meter_States.Meter_Status3.intd&0xDF07);	//payment	
else
        NEW645Meter_States.Meter_Status3.intd=(NEW645Meter_States.Meter_Status3.intd&0x0007);
		
        NEW645Meter_States.Meter_Status3.bit.Power_Mode1=0;
	NEW645Meter_States.Meter_Status3.bit.Power_Mode2=1;	
        if(Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow==0)
           NEW645Meter_States.Meter_Status3.bit.WhitchSlotIsNow=0;
        else  NEW645Meter_States.Meter_Status3.bit.WhitchSlotIsNow=1;	
	//-------------------------------------
	 Current_Demand[0]=0;	
	 Current_Demand[1]=0;	
	 Active_power_Per_Mintue=0;
	 
	 eventstatusinfo.byte=0;
	 
	 for(uni=0;uni<MAX_DEMAND_TYPE;uni++)
	 {
	   for(unj=0;unj<MAXTRIFF;unj++)
	   {
	     Last_Average_Value[uni][unj]=0;
	   }
	 }
	 
}

void PowerDownDisplayInit(void)
{
          
	   //Drop_Key_Initialize(0);	   		
	   PowerdownDisplayCyleAdd=0;
	   PowerdownDisplayOverAdd=0;	
     Fail_abnormal.byte=0;
     Event_abnormal.byte=0;
     failabnormalshow.byte=0;
     eventabnormalshow.byte=0;
     Abnormal_Show_Mode.byte=0;
	   Drop_Key_Initialize(0,0);/*"改低功耗下不开远红外抄读有时候出现大电流的问题"*/	   
}
void CheckPowerDownDisplayTimes(void)
{
  unsigned char flag=0;
	struct DATEANDTIME_DEF	Lo_time;
	unsigned char uni;
	
	drop_shwo_history[0].NO++;
	//Read_Date_And_Time((unsigned char *)&Lo_time,0);
	ClockChipRead((unsigned char *)&Lo_time);
  if(drop_shwo_history[0].NO>MAX_DS_NUM)
	{
	        if(ComTime((unsigned char *)&Lo_time,(unsigned char *)&drop_shwo_history[MAX_DS_NUM-1])<86400)
	        {
	            pdmode1=0;
		    pdmode2=0;    
		    FirstInterPowerDown=0;
	        }
		else 
		{
		    flag=0xff;    
		}
	}
	else
	{
	        flag=0xff;
	}
	if(flag)
	{
	    for(uni=0;uni<MAX_DS_NUM-1;uni++)
	    	drop_shwo_history[MAX_DS_NUM-uni-1].time=drop_shwo_history[MAX_DS_NUM-uni-2].time;
	    drop_shwo_history[0].time=Lo_time;       
	}
	
}
void PrepareforPowerdown(void)
{
        unsigned char i_temp;
        
        Dispose_Interrupt_for_PowerDown();
        Dispose_IO_for_PowerDown();
        Cpu_Card_IO_Powerdown();	//payment
        
        for(i_temp=0;i_temp<16;i_temp++)
        {
	  	    RamData_Valid_flag[i_temp]=i_temp;
	  	  }
 
	if(IF_Powerup_Billdata)  /*"上电要清零"*/
	{
	   PDSavedata();
	   ClockBatteryClear_Flag[0]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[1]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[2]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[3]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[4]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[5]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[6]=0;  //add by pc 090302
	   ClockBatteryClear_Flag[7]=0;  //add by pc 090302
	   TempClockBatteryClearCounter=0;
	   ClockBatteryClearCounter=0;      //add by pc 090302
	}
	else
	{
	   //------------------------
	   Enable_10MAnd125K_Clock();
	   //------------------------
	   //pd8_0=1;  //p8_0 dispose 2010-04-21
	   pd0_5=0;     
	   //pd0_0=0; 	//mw closed 2010-05-04  ESP
//	   //p8_0=0;  //p8_0 dispose 2010-04-21
	   //p3_2=1;  //mw closed 2010-05-04  ESP
	   pd8_1=0;				/*"p81变为输入口"*///20050604
	   //pd6_7=1;
	   pd7_0=1; //DEBUG
	   //p6_7=1;
	   p7_0=1; //DEBUG
//------------------------------------
	   Para_Process_main();
	   ReadEeprom();
	   Check_Energy_main(0);
	   Find_Curr_Money();	   
//------------------------------------
//	   pd10_1=0;   
//	   WriteWhitchEeprom[0]=0;
//		 WriteWhitchEeprom[1]=1;      
//	   ReadEeprom();
	   //clear_show_lcd();//mw closed 2010-05-04 ESP
//	   pd0_5=1;
//	   p0_5=0;
	//pd0_0=1; 	//1209
	//p0_0=0;
//	   p8_0=0;
	   p3_2=0;
	Disable_INT5();	//2010-04-30 /*"一定要加上"*/
	   
	   if(IF_Powerup_Savedata==0){
	   	ClockBatteryClear_Flag[0]=0x12;  //add by pc 090302
	    ClockBatteryClear_Flag[1]=0x34;  //add by pc 090302
	    ClockBatteryClear_Flag[2]=0x56;  //add by pc 090302
	    ClockBatteryClear_Flag[3]=0x78;  //add by pc 090302
	    ClockBatteryClear_Flag[4]=0x9A;  //add by pc 090302
	    ClockBatteryClear_Flag[5]=0xBC;  //add by pc 090302
	    ClockBatteryClear_Flag[6]=0xDE;  //add by pc 090302
	    ClockBatteryClear_Flag[7]=0xF0;  //add by pc 090302
	    TempClockBatteryClearCounter=0;
	    ClockBatteryClearCounter=0;      //add by pc 090302
	   }
	   else{
	   	ClockBatteryClear_Flag[0]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[1]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[2]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[3]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[4]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[5]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[6]=0;  //add by pc 090302
	    ClockBatteryClear_Flag[7]=0;  //add by pc 090302
	    TempClockBatteryClearCounter=0;
	    ClockBatteryClearCounter=0;      //add by pc 090302
	   }   
		//------------------------------------	  
		ClearEventDate_BatteryPowerOn();  
		//mw added 2010-06-01
		//------------------------------------
	}
	
	 /*"开副时钟"*/
	//{
           //prc0=1;  //2010 mw closed 2010-04-30
          // cm04=1;
          // prc0=1;
           //cm03=1;
        //}
        
	ClearDatePoerDown();
	key_flag.bit.b0=0;
	key_flag.bit.b7=1;
	for(i_temp=0;i_temp<MAX_DS_NUM;i_temp++)
		drop_shwo_history[i_temp].NO=0;	
	
	ta2s=0;
	ta1s=0;
	ta0s=0;
	ta3s=0;
	ta4s=0;
	tb0s=0;
	tb1s=0;
	tb2s=0;
	tb3s=0;
	tb4s=0;
	tb5s=0;
	ta2ic=0;
	int0ic=0;
	//int1ic=0;
	int2ic=0;
	int3ic=0;
	int4ic=0;
	int5ic=0;	
	asm("	FSET I");
	IniPdInterrupt();
	//ta2s=1;	
}




void PDSavedata(void)
{
        unsigned int uni=0;
	unsigned char data[10];
	unsigned char cs=0;
	unsigned int  sum=0;
	unsigned char nCheckSum;
	unsigned char *p;        
	
	//Pay_For_Para_Down_Save(); //payment
	
	This_Month_Data.Energy_Record.crc_cal = CRC((unsigned char*)&This_Month_Data,
	                               sizeof(struct ENERGY_RECORD) - 2);
	                               
	energy_rail.crc_cal = CRC((unsigned char*)&energy_rail,
	                           sizeof(struct ENERGY_RAIL_ADD_BUFFER) - 2);

	CalPowerDownEnergy();
	for(uni=0;uni<72;uni++)
	{
	    *((unsigned char *)&Powerdown_Save_Data.energy_powerdown.Phase_Plus_Active+uni)=*((unsigned char *)&This_Month_Data.Energy_Record.Phase_Plus_Active+uni);
	}
	for(uni= 0; uni < (sizeof(struct PRE_SAVE_DATA));uni++ )
	{
	    *((unsigned char *)&Powerdown_Save_Data.Pre_Save_Data + uni)=*((unsigned char *)&This_Month_Data.Energy_Record.Pre_Save_Data+uni);
	}
//	for(uni = 0; uni < 6; uni++)
//	{
//		Powerdown_Save_Data.date[uni]=*((unsigned char*)&softdate + uni);
//	}
	Powerdown_Save_Data.date = softdate;
	Powerdown_Save_Data.fee=TRAFF_RATE;
	for(uni=0;uni<8;uni++)
	  Powerdown_Save_Data.PdEventFlag[uni]=Event_Power_Net_Flag.byte[uni];
	Powerdown_Save_Data.crc_cal = CRC((unsigned char*)&Powerdown_Save_Data,
	                               sizeof(struct POWERDOWN_SAVE_DATA) - 2);
	
	
//	sum=sizeof(struct POWERDOWN_SAVE_DATA)-1;
//	cs=0;
//	for(uni=0;uni<sum;uni++)
//	{
//	   cs+=*((unsigned char *)&Powerdown_Save_Data+uni);
//	}
//	Powerdown_Save_Data.csadd=cs;
	WRLC256(POWERDOWN_SAVE_DATA_ROM,(unsigned char *)&Powerdown_Save_Data,sizeof(struct POWERDOWN_SAVE_DATA),0,0);
//	WRLC256(POWERDOWN_SAVE_DATA_ROM,(unsigned char *)&Powerdown_Save_Data,sizeof(struct POWERDOWN_SAVE_DATA),0,1);
	WRLC256(ENERGY_RAIL_DATA_ROM,(unsigned char *)&energy_rail,sizeof(struct ENERGY_RAIL_ADD_BUFFER),0,0);
//  AdjustMeterEvent(0xFF);  //add by pc 081201
//  PdSaveImBalanceData();   //add by pc 081214
  EventData_PowerDown_Save();  //add by pc 081020
//  PowerDownSaveMaxCurr();      //add by pc 090509
  //WRLC256(BEGIN_ROM4,(unsigned char *)&Freeze_Flag_DayHour[0],2,3,0);  //mw added 2009-02-14
     
        Alarm_Map_Flag[0].bit.b2=0;
        Alarm_Map_Flag[0].bit.b0=0; 
        Meter_States.Meter_Flag.bit.Battery3_Err= 0;  
	
	data[0]=data[1]=data[2]=0xA5;
	WRLC256(F_EEPROM_FLAG_ROM+3,(unsigned char *)&data,3,0,0);	
	WRLC256(F_EEPROM_FLAG_ROM+6,(unsigned char *)&data,3,0,0);

     if( 1 == O1ther_Meter_Parameter.ResetEventReport_flag )
     {
       WRLC256(EVENTREPORT_RUNTIME_ROM,(unsigned char *)&O1ther_Meter_Parameter.EventReport_RunTime,2,0,0);
     }
	
	
}
void CalPowerDownEnergy(void)
{     
  unsigned char i,j;
  unsigned long data1=0,data2=0;
//	  unsigned char a[2]={0,TRAFF_RATE};
//	  unsigned char b[2]={0,1};
//	  for(i=0;i<6;i++)
//	  	for(j=0;j<2;j++)
//	      Energy_Compare(((unsigned long *)&This_Month_Data+MAXTRIFF*i+a[j]),
//	                     ((unsigned long *)&Cal_PowerDown_Energy_add+2*i+b[j]),
//	                     ((unsigned int *)&Powerdown_Save_Data+2*i+b[j]));
 for(i=0;i<6;i++)
  {
  	 data1=*((unsigned long *)&This_Month_Data+MAXTRIFF*i+0);
     data2=*((unsigned long *)&Cal_PowerDown_Energy_add+2*i+0);
     
     if(data1>=data2)
      *((unsigned int *)&Powerdown_Save_Data+2*i+0)= (unsigned int)(data1-data2);
     else  
     	*((unsigned int *)&Powerdown_Save_Data+2*i+0)= (unsigned int)(999999999l+data1-data2); 
     
     data1=*((unsigned long *)&This_Month_Data+MAXTRIFF*i+TRAFF_RATE);
     data2=*((unsigned long *)&Cal_PowerDown_Energy_add+2*i+1); 
     
     if(data1>=data2)
      *((unsigned int *)&Powerdown_Save_Data+2*i+1)= (unsigned int)(data1-data2);
     else  
     	*((unsigned int *)&Powerdown_Save_Data+2*i+1)= (unsigned int)(999999999l+data1-data2);  
  }
}
//void  Energy_Compare(unsigned long *ComPtr1,unsigned long *ComPtr2, unsigned int *aimPtr )
//{
//     
//    (*ComPtr1 >=*ComPtr2) ? (*aimPtr=(unsigned int)(*ComPtr1 -*ComPtr2)) : (*aimPtr=(unsigned int)(Cal_EnergyLimit()+*ComPtr2-*ComPtr1));
//	 	 	 	
//}

/********************************************************************************/
//if(!IF_Powerup_Billdata)
	//      {	
	//         Dispose_Interrupt_for_PowerDown();
	//         Prepare_for_Wait();
	//         pdmode1=0;
	//         pdmode2=0;
	//         asm("FCLR I");
	//         
	//         prc0=1;	//CM1 write enable
	//         cm10=1;	/*"进入STOP模式"*/
	//         prc0=0;	//CM1 write disenable
	//      }	
	
void	Goto_StopMode(void)				
{
      asm("FSET	I");    
	 		//	asm("FCLR	I");
		 asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   
	   prc0=1;	//CM1 write enable
	   cm10=1;	/*"进入STOP模式"*/
	   prc0=0;	//CM1 write disenable
	      
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
	   asm("nop");
			
}	
	//////////////////////////
void	Enable_10MAnd125K_Clock(void)	
{
			prcr|=0x01;  //mw added 2010
			cm1|=0x20;
			
			prcr|=0x01;						//CM0 write enable
			
			cm0&=0xdf;						/*"打开主晶振"*/
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");			
			//prcr|=0x01;  //mw added 2010
			//cm0|=0x40;	//mw added 2010/*"主晶振8分频"*/	
			prcr|=0x01;  //mw added 2010
			cm0&=0xbf;	//mw added 2010/*"10M 全速跑"*/
			prcr|=0x01;  //mw added 2010
			cm1&=0x3f;				
			asm("nop");
			asm("nop");
			asm("nop");
											/*"打开远红外电源"*/
											/*"打开内卡电源"*/
			//PowerOn_PCF8576();				/*"打开LCD电源"*///2005.04.12
			prcr|=0x01;  //mw added 2010
			cm1&=0xfd;						/*"CM11=0,Main clock"*/
			prcr|=0x01;  //mw added 2010
			cm2&=0xfd;						/*"CM21=0,Main clock"*/
			prcr|=0x01;  //mw added 2010
			cm0&=0x7f;						
											

										
			prcr|=0x01;  //mw added 2010
			cm0&=0xef;	//mw added 2010/*"停止副晶振"*/
			prcr|=0x01;  //mw added 2010
			cm1&=0xef;	//mw added 2010/*"打开125K内部晶振"*/	

			
			prcr&=0xfe;						//CM0 write disable
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");
			asm("nop");		
}

#pragma INTERRUPT Ad_Converter_Int ///king chen add 121214
void Ad_Converter_Int(void)
{
    ///unsigned int  fix_ad_data = 0x0000;
    fix_ad_data = 0;
  if(0==IntoPowerDownFlag)  /*"正常上电执行，低功耗不执行"*/
  {
   if(ad_Flag==0)
   	{
        fix_ad_data = ad7;
       /// Voltage_ad_data[0]=fix_ad_data*460.0*3.0/(1023.0*2.04);
       ad_finish_Flag=1;///king chen add 121226
   	}
   else
   	{
       fix_ad_data = ad6; 
       ///Voltage_ad_data[1]=fix_ad_data*460.0*3.1/(1023.0*1.108);
	ad_finish_Flag=1;///king chen add 121226
   	}
  }
}


void FarWakeUpCheck(void)
{
	unsigned char result;
	unsigned char unc;
	struct DATEANDTIME_DEF	temptime;
	
	if(farwakeupreadyflag==0x33)
	{
		if(farwakeupreadytimes<FARWAKEUPLIMITTIMES)
		{
			ClockChipRead((unsigned char *)&temptime);
      if(((drop_shwo_history[0].NO+1)>MAX_DS_NUM)
        &&(ComTime((unsigned char *)&temptime,(unsigned char *)&drop_shwo_history[MAX_DS_NUM-1])<86400))
	    {
	       farwakeupreadyflag=0;
	    }
	    else
	    {
	    	farwakeupreadytimes++;
	    }
		}
		else
		{
			farwakeupreadyflag=0;
		}
	}
	
	if(farwakeupreadyflag!=0)
	{
		
		if((farwakeupreadyflag==0x33)&&(pdmode1==0)&&(pdmode2==0))
		{
			farwakeupreadyflag=0xaa;
			farwakeupreadycnt=0;
			Prepare_for_Wakeup(0);
			pd7_0=1; 
			p7_0=1;
			pd7_1=0;
			pd8_1=0;
			p7_3=1;   
	    Init_Comm(1);
	    s2ric=0x03;
		}
		
		result=0;
		if(farwakeupreadyflag==0xaa)
		{
			for(unc=0;unc<230;unc++)
			{
				if((CommB[1][unc]==0x68)&&(CommB[1][((unc+1)%230)]==0x11)&&(CommB[1][((unc+2)%230)]==0x04))
				{
					result=1;
					break;
				}
			}
		}
		
		if((farwakeupreadyflag!=0xaa)||(farwakeupreadycnt>FARWAKEUPRELAY)||(pdmode1!=0)||(pdmode2!=0))
		{
			farwakeupreadyflag=0;
			farwakeupreadycnt=0;
		}
		else
		{
			if(result==1)
		  {
			  farwakeupreadyflag=0;
			  farwakeupreadycnt=0;
			  
			  if(pdmode1==0)
			  {
					PowerdownDisplayCyleAdd=0;
	        PowerdownDisplayOverAdd=0;	
					key_flag.bit.b0=0;
					key_flag.bit.b1=1;
					pdmodekeyflag=0;
	        PowerdownStopKeyAdd=0;
	        pdmode1=0x33;
			  }
			  if(Meter_Parameter.parameter1.MeterMode[1].bit.b1)
	      {	     
	        if(pdmode2==0)
	        {
	        	pdmode2=0x33;
	          PowerdownStopCommAdd=0;                                
	        }
	      }
		  }
		}
		
	}
	
	if((farwakeupreadyflag==0)&&(pdmode1==0)&&(pdmode2==0))
	{
		 ta0s=0;
	   ta1s=0;
		 s2ric=0;
		 s2tic=0;
		 ta0ic=0;
		 u2mr=0;
		 pd7_0=1; 
		 p7_0=0;
		 pd7_1=1;
		 p7_1=0;
		 pd8_1=1;
		 p8_1=0;
		 pd7_2=1;
	   p7_2=0;
		 p7_3=0;
	}
	
}
