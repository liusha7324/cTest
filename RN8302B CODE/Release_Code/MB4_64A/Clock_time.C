//clock and time deal file

#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "comm.h"
#include "initram.h"
#include "initcpu.h"
#include "Powerdown_LDH.h"
#include "Measure_Interface.h" 
#include "I2C_operation.h"
#include "eventnew.h"
#include "MB_Keymain.h"
#include "MB_Showmain.h"
#include "multi.h"
#include "interrupt.h"
#include "Freeze.h"
#include "Energy_Del.h"
#include "Pay_def.h"			//payment
#include "ICcard.h"
#include "Ex_Pay_For_Fun.h"
#include "BackLight_Ctrl.h"
#include "MB_BASE_FUN.h"


unsigned char AddTime(void);
unsigned char PowerUp_Init_RTC(unsigned char neweeprom, double long *datatime);
void          ReadRTC(void); 
unsigned char CheckRamTime(void);

unsigned char Powerup_Check_RTC(void);

volatile union BYTE_BIT TimeChontrolBeginFlag;  /*"时间点到中间单元"*/

volatile unsigned  long TimeCount5ms;   /*"毫秒累加器"*/
unsigned long softtimeadd;    /*"主晶振监控时钟上限"*/
unsigned long ppttimeadd;     /*"秒脉冲监控下限"*/     
unsigned char firstsofttimeadd;  /*"第一次秒脉冲，不判时间"*/
unsigned char tnum1,tnum2,tnum3;        /*"tnum1:30分钟；tnum1:10分钟。tnum3-5秒"*/
unsigned int time500add;    /*"500毫秒定时器"*/

#define OneMinuteb                TimeChontrolBeginFlag.bit.b0
#define OneSecondb                TimeChontrolBeginFlag.bit.b1
#define TenMinuteb                TimeChontrolBeginFlag.bit.b2
#define ThirtydMinuteb            TimeChontrolBeginFlag.bit.b3
#define TwoMinuteb                TimeChontrolBeginFlag.bit.b4
#define OneMinuteThirtSb          TimeChontrolBeginFlag.bit.b5
#define FiveSecond                TimeChontrolBeginFlag.bit.b6
#define FiveSecondb               TimeChontrolBeginFlag.bit.b7

unsigned char ReadRTC_Err_Num1;/*"读时钟出错分钟数"*/
unsigned char ReadRTC_Err_Num2;/*"读时钟出错小时数"*/

unsigned long rtc_lossvolt_flag;
unsigned char rtc_lossdata_flag;/*"时钟芯片丢失时间标志"*/

/*"时钟秒脉冲中断"*/
#pragma INTERRUPT Int0_Int
void  Int0_Int(void)
{
	if(ir_int0ic)
	   ir_int0ic=0;
	
	if(!firstsofttimeadd)  /*"上电第一次"*/
	{
	   softtimeadd=0;
	   Meter_States.Meter_Flag.bit.Rtc_Err1=0;
	   firstsofttimeadd=0xFF;
	   AddTime();
	}
	else
	{
	   if(ppttimeadd>750)
	   {
	       softtimeadd=0;
	       ppttimeadd=0;
	       AddTime();
	   }
	}
}


#pragma INTERRUPT TimerA0_Int
void  TimerA0_Int(void)
{
  //asm("	FSET I");

  TimeCount5ms+=5;
  softtimeadd+=5;
  ppttimeadd+=5;
  time500add+=5;
  if(!pdmode1 && !pdmode2)
  {
    if(time500add>500)
    { 
       Time500flag=1;
       time500add=0;
    } 
    
    if(softtimeadd>500)
	  {
	   if(OneSecondb)
	   {
	      OneSecond=1;
	      OneSecondb=0;
	   }
	   if(FiveSecondb)
	   {
	      FiveSecond=1;
	      FiveSecondb=0;
	   }
	   if(OneSecond_Eventb)
	   {
	      OneSecond_Event=1;
	      OneSecond_Eventb=0;
	   }
	   if(OneMinute_Eventb && (softdate.Sec>0x50))
     {
        OneMinute_Event=1;
        OneMinute_Eventb=0;
     }
     if(TenMinuteb && (softdate.Sec>0x30))
     {
        TenMinute=1;
        TenMinuteb=0;
     }
     
     if(OneMinuteThirtSb && (softdate.Sec>0x30))
     {
        OneMinuteThirtS=1;
        OneMinuteThirtSb=0;
     }
     
     if(ThirtydMinuteb && (softdate.Sec>0x30))
     {
        ThirtydMinute=1;
        ThirtydMinuteb=0;
     }
	 }
	 if(softtimeadd>=1500)
	 {
	    softtimeadd=500;
	    AddTime();
	 } 
	 
	Inttupt_Buzzer_Deal();		//payment
	Switch_Plus_Drive();
	#ifdef  BACK_LIGHT_BLINK_MODE
       BackLightBlink();
       #endif
 }
 	
}
/********************************************************
*     1. soft timer                                     *
*     2.                                                *
*********************************************************/
unsigned char AddTime(void)
{
   unsigned char data[6];
   unsigned char uni=0;
   
   
   for(uni=0;uni<6;uni++)
      data[uni]=OB_H(*((unsigned char *)&softdate+uni));
      
   OneSecondb=1;
   OneSecond_Eventb=1;
   tnum3++;
      
   if(data[5]<59)
   {
      data[5]++;  
   }                    /*"到整分"*/
   else
   {
      data[5]=0;
      OneMinute=1;
      OneMinuteThirtSb=1; 
      OneMinute_Eventb=1;
      tnum2++;
      tnum1++;
      if(data[4]<59)
      {
         data[4]++;
      } 
      else                                     /*"到整小时"*/
      {
      	 data[4]=0;
      	 if(data[3]<23)
      	 {
      	    data[3]++;
      	 }
      	 else                                /*"到0点"*/
      	 {
      	    data[3]=0;
      	    if( data[2]<CalDay(data[0],data[1]) )
      	    {
      	    	data[2]++;
      	    }
      	    else                            /*"到月末"*/                              
      	    {
      	    	data[2]=1;
      	    	if(data[1]<12)               
      	    	{
      	    	   data[1]++;
      	    	}
      	    	else                        /*"到年末"*/
      	    	{
      	    	   data[1]=1; 
      	    	   data[0]++;
      	    	}
      	    }
      	 }
      } 

      if(tnum2>=10)
      {
      	 tnum2=0;
         TenMinuteb=1; 
      }
      
      if(tnum1>=30)
      {
      	 tnum1=0;
         ThirtydMinuteb=1; 
      }             
   }
   
   if(tnum3>=5)
      {
      	 tnum3=0;
      	 FiveSecondb=1;
      }

   for(uni=0;uni<6;uni++)
      *((unsigned char *)&softdate+uni)=OH_B(data[uni]);
      
   return 1;   
}


/*"============================================================
函数说明：上电时钟处理
输入参数：neweeprom           
输出参数：datatime          上电时间－掉电时间值
返    回：ret_value         // b0  RTC TIME            0  ERR  1 OK
	                          // b1  powerdown save time 0  err  1 ok
	                          // b2  soft-powerdowntime  0  err  1 ok
	                          // b3  reset               0  err  1 ok
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char PowerUp_Init_RTC(unsigned char neweeprom, double long *datatime)
{
	struct DATEANDTIME_DEF tdate1;
	unsigned int uni=0;
	unsigned char result=0;
	unsigned char err_code = 0;
	
	union BYTE_DEF ret_value; // b0  RTC TIME            0  ERR  1 OK
	                          // b1  powerdown save time 0  err  1 ok
	                          // b2  soft-powerdowntime  0  err  1 ok
	                          // b3  reset               0  err  1 ok
	
	ret_value.byte = 0;
	
	for(uni=0;uni<7;uni++)
	{
	  *((unsigned char *)&tdate1+uni)=0;
	}
	
  CheckPowerDown(); 
  
  ClockChipInit(1);
  
  CheckPowerDown(); 
  
  if(neweeprom)
  {
     CheckPowerDown();      
     ret_value.bit.b0 = 0;
  }
  else
  {   
    ret_value.bit.b0 = Powerup_Check_RTC();

    ClockChipRead((unsigned char *)&tdate1);

    if( CheckTime((unsigned char *)&Powerdown_Save_Data.date))
    	{
    		ret_value.bit.b1 = 1;
    	}
  }    
  
  if((ret_value.byte&0x03) == 0x02)//RTC time err  powerdown time 0k
  {
      CheckPowerDown();  
      //Write_Date_AndOr_Time((unsigned char *)&Powerdown_Save_Data.date,0,2);
      ClockChipWrite((unsigned char *)&Powerdown_Save_Data.date);
      MainSoftDate=Powerdown_Save_Data.date;  
      result=0xff;
      err_code=0x01;       
  }  
  else if((ret_value.byte&0x03) == 0)//both err
  {
    CheckPowerDown(); 
    softdate.Year=  0x05;  
	  softdate.Month= 0x01;  
	  softdate.Day=   0x20;  
	  softdate.Hour=  0x00;  
	  softdate.Min=   0x00;  
	  softdate.Sec=   0x00;  
	  softdate.Week=  0x04;  
    //Write_Date_AndOr_Time((unsigned char *)&softdate,0,2);
    ClockChipWrite((unsigned char *)&softdate); 
    result=0xff;
    err_code=0x02;
   }
  IsNormalResetWrite();
  if(neweeprom)///king chen add 130302
  	{
           O1ther_Meter_Parameter.DayFreezeReferenceDate=softdate;
           O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
           WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); 	
      }
  
	if((ret_value.byte&0x03) == 0x03)//both ok
	{	  
	   (*datatime)=ComTime( (unsigned char *)&softdate,(unsigned char *)&Powerdown_Save_Data.date);     
	   if((*datatime) > 0) // 
	   {
	      if(IsNormalReset(0))
	      {	         			
          //VoltStatisticCheck();

               CheckPowerDown(); ///king chen add 121214  
               PowerUpDayFreeze();			/*"上电补日冻结函数"*/
               CheckPowerDown();  
			   
               ret_value.bit.b3 = 1;
	      }
	      ret_value.bit.b2 = 1;
	   }
	   else
	   {
	      CheckPowerDown();  
        //Write_Date_AndOr_Time((unsigned char *)&Powerdown_Save_Data.date,0,2);
        ClockChipWrite((unsigned char *)&Powerdown_Save_Data.date);
        MainSoftDate=Powerdown_Save_Data.date; 
        result=0xff;
        err_code=0x04;   
	   }
	}
	
	if(result)
	{
	    for(uni=0;uni<5;uni++)
	    {
	        Co.b[405+uni]=*((unsigned char *)&tdate1+uni);
	    } 
	    Co.b[410]=err_code;
	    PowerUpClockErrorRecord();  //change by pc 081214
	}
	
  FeedWatchdog();
      
	MainRamDate2=MainRamDate1=MainSoftDate;
	
	return (ret_value.byte);
}

/*" 每分钟读时钟"*/
void ReadRTC(void)
{
  struct DATEANDTIME_DEF time1;
  double long data=0;
  unsigned char uni=0;
	
	for(uni=0;uni<7;uni++)
	{
	        *((unsigned char *)&time1+uni)=0;
	}
		
  //Read_Date_And_Time((unsigned char *)&time1,0);//softdate,0);
  ClockChipRead((unsigned char *)&time1);
  if(CheckTime((unsigned char *)&time1))
  {
     data=ComTime( (unsigned char *)&softdate,(unsigned char *)&time1 );     
     if(ABS(data)<50)
     {
        softdate=time1;
        ReadRTC_Err_Num1=0;
	      if(ReadRTC_Err_Num2>=2)
          ReadRTC_Err_Num2=0;
        Meter_States.Meter_Flag.bit.Rtc_Err1=0;
        EventReportState_Expand(3, 4, 1);
     }
     else
     {
     	ReadRTC_Err_Num1++; 
     } 
  }
  else 
  {
  	ReadRTC_Err_Num1++;
  }
      
  if(ReadRTC_Err_Num1>=60)
  {
     //Co.b[310]=Init_DS1375();  
     ClockChipInit(1);   
     //Write_Date_AndOr_Time((unsigned char *)&softdate,0,2);
     ClockChipWrite((unsigned char *)&softdate);
     ReadRTC_Err_Num1=0;
     ReadRTC_Err_Num2++;
    
     if(ReadRTC_Err_Num2>=2)  /*" 连续连续两小时出错，报警且记事件记录"*/
     {
       Meter_States.Meter_Flag.bit.Rtc_Err1=1;
	     for(uni=0;uni<5;uni++)
	     {
	        Co.b[405+uni]=*((unsigned char *)&time1+uni);
	     }
	     //Event_Meter_Program_Flag.RunClockError=1;
	     //Event1(0);
	     RunClockErrorRecord();  //add by pc 081214     
     }
  }
      
  MainRamDate2=MainRamDate1=MainSoftDate;    
}

/********************************************************
*     Check Ram Time                                    *
*                                                       *
*********************************************************/
/*"每妙种，或每分钟读时钟芯片调用"*/
unsigned char  CheckRamTime(void)
{
  unsigned char m1=0xff,m2=0xff,m3=0xff; /*"数据正确性"*/
  signed long td1=0,td2=0,td3=0;         /*"时间差"*/
  unsigned char n1=0xff,n2=0xff,n3=0xff; /*"时间差正确性"*/
  struct DATEANDTIME_DEF time1;          /*"时钟正确性"*/
  unsigned char result=0xff;
  
  
  if(!CheckTime((unsigned char *)&MainSoftDate))
     m1=0x00;
  if(!CheckTime((unsigned char *)&MainRamDate1))
     m2=0x00;
  if(!CheckTime((unsigned char *)&MainRamDate2))
     m3=0x00;   
  
  if(!m1)
  {
     if(m2)
       MainSoftDate=MainRamDate2=MainRamDate1;
     else if(m3)   
       MainSoftDate=MainRamDate1=MainRamDate2;
     else
     {
         //Read_Date_And_Time((unsigned char *)&time1,0);
         ClockChipRead((unsigned char *)&time1);
         if(CheckTime((unsigned char *)&time1)) 
         {
            MainSoftDate=MainRamDate2=MainRamDate1=time1;
         }
         result=0;
     }  
  }   
  else if(m1 && m2 && m3)
  {
     td1=ComTime((unsigned char *)&MainSoftDate,(unsigned char *)&MainRamDate1);  
     td2=ComTime((unsigned char *)&MainSoftDate,(unsigned char *)&MainRamDate2);  
     td3=ComTime((unsigned char *)&MainRamDate1,(unsigned char *)&MainRamDate2);     
     if(ABS(td1)>50)
        n1=0;
     if(ABS(td2)>50)
        n2=0;   
     if(ABS(td3)>50)
        n3=0;   
     if(((!n1) || (!n2)) && n3)
        MainSoftDate=MainRamDate2=MainRamDate1;
     else if(((!n1) || (!n3)) && n2)
        MainRamDate2=MainRamDate1=MainSoftDate;   
     else if(((!n2) || (!n3)) && n1)
        MainRamDate2=MainRamDate1=MainSoftDate;
     else if((!n2) && (!n3) && (!n1))
     {
         //Read_Date_And_Time((unsigned char *)&time1,0);
         ClockChipRead((unsigned char *)&time1);
         if(CheckTime((unsigned char *)&time1)) 
         {
            MainSoftDate=MainRamDate2=MainRamDate1=time1;
         }
         result=0;
     }
     else if((n2) && (n3) && (n1))
     {
         MainRamDate2=MainRamDate1=MainSoftDate;  
     }           
  }    
  else
  {
     MainRamDate2=MainRamDate1=MainSoftDate;
  }
  
  return result;
}



unsigned char TimeUPLimit(void)
{
    unsigned char i;
    struct DATEANDTIME_DEF  Limit={0x99,0x12,0x31,0x23,0x59,0x59,4};
    for(i=0;i<7;i++)
    {
         if (*((unsigned char *)&softdate+i)!=*((unsigned char *)&Limit+i) )
             return 0;
    }
    return 1;	     	
}

void ResetTime(void)
{
  struct DATEANDTIME_DEF  start={0,1,1,0,0,0,1};
  
  int2ic &= 0xf8;
  softdate=start;
	MainRamDate2=MainRamDate1=MainSoftDate;
  //Write_Date_AndOr_Time((unsigned char*)&MainSoftDate,0,2);
  ClockChipWrite((unsigned char *)&MainSoftDate);
	int2ic |= 0x01;
}

/*"============================================================
函数说明：上电检查时钟芯片是否工作正常
          从时钟芯片先后两次读取时钟进行比较
输入参数：无 
输出参数：无
返    回：ret_value  0 err  1  ok  
作    者：GANJP  版本：1.00
============================================================"*/
unsigned char Powerup_Check_RTC(void)
{
	unsigned char ret_value = 1;
	struct DATEANDTIME_DEF tdate1;
	unsigned char num = 0;
	unsigned char uni = 0;
	do
  {   
  	 ret_value = 1;
     CheckPowerDown();   
     //Read_Date_And_Time((unsigned char *)&tdate1,0);
     ClockChipRead((unsigned char *)&tdate1);     
     CheckPowerDown(); 
    
     MainSoftDate=tdate1;
     //Read_Date_And_Time((unsigned char *)&tdate1,0);  
     ClockChipRead((unsigned char *)&tdate1);  
     
     for(uni=0;uni<7;uni++)
     {
     	 if(*((unsigned char *)&MainSoftDate+uni)!=*((unsigned char *)&tdate1+uni))
     	 	{
     	 		ret_value = 0;
     	 		break;
     	 	}          	     
     }
     
     if(ret_value)
     {
     	   if(! CheckTime((unsigned char *)&tdate1) )
     	   {
     	   	   ret_value = 0;	       	   	     
     	   }
     }  
     
     num++; 
                    
  }while((!ret_value) && num<=100); 
  
  if(ret_value)/*"没有电池时,时间满足格式但是可能是个乱值"*/
  {
    if(Meter_Parameter.parameter1.MeterMode[2].bit.b1==1)/*"打开纠错功能"*/
    {
  	  if(((gPD_Data_valid_flag.byte & 0x0f) == 0x0f)&&(CheckTime((unsigned char *)&Powerdown_Save_Data.date)))/*"掉电时间正确"*/
  	  {
  	  	if((OB_H(tdate1.Year)>(OB_H(Powerdown_Save_Data.date.Year)+15))
  	  	   ||(OB_H(tdate1.Year)<OB_H(Powerdown_Save_Data.date.Year)))/*"掉电时间超过15年或者掉电时间为负"*/
  	  	{
  	  		if(rtc_lossvolt_flag==0xa5a5)/*"时钟芯片失压标志有效"*/
  	  		{
  	  			 ret_value=0;
  	  		}
  	  	}
  	  }
    }
  }
  rtc_lossvolt_flag=0;
  
  if((ret_value==0)&&(Meter_Parameter.parameter1.MeterMode[2].bit.b1==1))/*"打开纠错功能"*/
  {
  	rtc_lossdata_flag=0x5a;
  }
  
  return (ret_value);
}
