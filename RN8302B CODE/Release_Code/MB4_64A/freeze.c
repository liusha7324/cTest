/*"������� for DL645-2007"*/
/*"creat by trend "*/
/*"ver 1.0 2008-10-25 10:54:27"*/
#include  "defmcro.h"
#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "Freeze.h"
#include "File_System.h"   //mw added 2009-02-12
#include "Multi.h"
#include "Measure_Interface.h" 
#include "ICcard.h"
#include "645_2007.h"
#include "pay_def.h"
#include "Ex_Pay_For_Fun.h"
#include "LoadRecord.h"

#define  MAX_DAYFREEZE_POWERUP_STRIDE    7       /*"�ϵ粹�ն������ݵ�������"*/


///unsigned char DayFreezePowerupComplete;        /*"�ϵ粹�ն���������ɱ�־"*/
///unsigned int stridebill_dot_num = 0;/*""*/
///unsigned int stridefreeze_dot_num = 0;/*""*/
///unsigned int stridefreezePrebill_dot_num = 0;/*""*/

//#pragma SECTION rom UserROMData
const unsigned char DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned long DateToDays(TDateTime* rpDateTime);
unsigned char DateTimeToInt(TDateTime* rpDateTime, unsigned long *pSeconds);
void IntToDate(unsigned long rInt, TDate* rpDate);
void IntToDateTime(unsigned long rInt, TDateTime* rpDateTime);
signed int GetSkipedTimeFlags(TDateTime* rpTime1, TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax);
void PowerUpDayFreeze(void);
///void Dayfreeze_Recompense(TDateTime * StrideFreeze_Dot_List, unsigned char demand_zero_flag,unsigned int stridebill_dot_start_num,unsigned int freezeday_num );///king chen add 130105
void Dayfreeze_Recompense(unsigned char  demand_flag, unsigned char * StrideFreeze_Dot);///king chen modify 130609
unsigned char ComparentTime(unsigned char *t1, unsigned char *t2);///king chen add 130302

void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime);///king chen modify 130609
void Day_freeze(unsigned char sort);
void FreezeDateProgram_HourOrDay(unsigned char kind1,unsigned char  kind2,unsigned char  sort);
void Clear_HDFreezeData(void);
void PoweronFreeze_Deal(void);
void Freeze_Period(void);
void Freeze_Day(void);
void Clear_Freeze_Period(void);
void ClearFreezeCommDeal(unsigned long Data_ID);

//#pragma SECTION program program_protect

//unsigned char  Freeze_Flag_DayHour[2];	

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"============================================================"*/
/*"��������Freeze_Main"*/
/*"��;������ģ��������"*/
/*"��������"*/
/*"���أ���"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
void Freeze_Main(void)
{
    unsigned char pointer=0;	
	if(IntoPowerDownFlag==0)     /*"�����ϵ�ִ�У��͹��Ĳ�ִ��"*/
	{
		 if(((Meter_Parameter.freeze_parameter.FreezeDate[3]==softdate.Month)||(Meter_Parameter.freeze_parameter.FreezeDate[3]==0x99))
		 	&&((Meter_Parameter.freeze_parameter.FreezeDate[2]==softdate.Day)||(Meter_Parameter.freeze_parameter.FreezeDate[2]==0x99))
		 	&&((Meter_Parameter.freeze_parameter.FreezeDate[1]==softdate.Hour)||(Meter_Parameter.freeze_parameter.FreezeDate[1]==0x99)) 
		 	&& (Meter_Parameter.freeze_parameter.FreezeDate[0]==softdate.Min))
	   {  	                		  	
         	
         	ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr
	        ,FREEZE_TIME_SORT_START_FILE);/*"���������жϴ���"*/
         			
         	pointer=O1ther_Meter_Parameter.FreezeData_Time_addr;
		   		FreezeDateProgram(FREEZE_TIME_SORT_START_FILE+pointer, 1, (unsigned char *)&softdate);///king chen modify 130609
		   	  pointer++;
		   		pointer%=MAX_NUMBER_FREEZE_TIME;
					O1ther_Meter_Parameter.FreezeData_Time_addr=pointer;
				  WRLC256(FREEZE_TIME_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr,1,0,0);
				  ////Set_Meter_para_Deal(FREEZE_TIME_ADDR_ROM);
				  FeedWatchdog(); 
	       
	   } 
	            	  
	   Freeze_Period();
	   Freeze_Day();
    }
}

/*"============================================================"*/
/*"��������Freeze_Period"*/
/*"��;�����ڶ���������"*/
/*"��������"*/
/*"���أ���"*/
/*"���ߣ�fuxf �汾��1.00"*/
/*"============================================================"*/
void Freeze_Period(void)
{
        unsigned int  uni,freeze_interval,pointer=0;				
		struct DATEANDTIME_DEF		temp_date;		
		signed long  long time1;	

        //if((Meter_Parameter.New645_Freeze_Period_Mode.byte&0x03)==0)
        //    return ;

        Meter_Parameter.freeze_parameter.Freeze_Period_Date.Sec=0;
        if(CheckTime((unsigned char *)&Meter_Parameter.freeze_parameter.Freeze_Period_Date)==0)
            return ;

		if((Meter_Parameter.freeze_parameter.Freeze_Period_Interval==0)||(Meter_Parameter.freeze_parameter.Freeze_Period_Interval>60))
			  freeze_interval=60; 			 
		else 		
		    freeze_interval=Meter_Parameter.freeze_parameter.Freeze_Period_Interval;

		temp_date=softdate;
		temp_date.Sec=Meter_Parameter.freeze_parameter.Freeze_Period_Date.Sec;
		time1=ComTime((unsigned char *)&temp_date,(unsigned char *)&Meter_Parameter.freeze_parameter.Freeze_Period_Date);

		time1=time1/60;
		if((time1>=0)&&((time1%freeze_interval)==0))
		{
			        pointer=O1ther_Meter_Parameter.FreezeData_Period_addr;
	            for(uni=0;uni<5;uni++) 		   				 
	               *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)&softdate+uni);	    
						
				      *((unsigned long *)&Co.b[300+5])=This_Month_Data.Energy_Record.Plus_Active[0];   
				      *((unsigned long *)&Co.b[300+9])=This_Month_Data.Energy_Record.Nega_Active[0];   
				      WRLC256(FREEZEDATA_PERIOD_ROM+pointer*13,(unsigned char *)&Co.b[300],13,0,0);
                      CheckPowerDown();
                      
					    pointer++;
		   				pointer%=MAX_NUMBER_FREEZE_PERIOD;
							O1ther_Meter_Parameter.FreezeData_Period_addr=pointer;
		   				WRLC256(FREEZE_PERIOD_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Period_addr,1,0,0);
		   				///Set_Meter_para_Deal(FREEZE_PERIOD_ADDR_ROM);
		   	            FeedWatchdog(); 			
		}
		
		return ;
}

/*"============================================================================="*/
/*"�������� 2008-7-9 15:31:06"*/
/*"  --------------------------------------------------------------------------"*/
/*"    kind1: 1 ˲ʱ����2  ʱ���л�,3 ��ʱ�α��л�   ��"*/
/*"   *  kind2:  POINT  ��ǰ�����ָ��*"*/
/*"   *  kind3: ��ʾ���ڿ�����FLASH *"*////king chen mark 130609
/*"   *  demand_zero_flag:  1 ��ʾ������ʵ������, 0��ʾ����ֵ���� *"*/
/*"   *  freezetime: ��ʾ�����ʱ�� *"*/
/*"    * ������ֻ������MAXTRIFF <=15������*"*/
/*"��������е��粻��!added by fxf	2009-07-10"*/
/*"============================================================================="*/
void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime)///king chen modify 130609
{
     unsigned int uni,i,addr;
     unsigned int data_length;
	   struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
	   struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
	   
 	   p3_2=1;

	  data_length=5+sizeof(struct  FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA)+sizeof(struct FREEZE_POWER_DATA); 
   
      for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;   
	   /*"����ʱ��"*/   
	  for(uni=0;uni<5;uni++) 
	       ////*((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)&softdate+uni);
               *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)freezetime+uni);
		
	  /*"���������"*/   
	  for(i=0;i<6;i++)
	  {
	        for(uni=0;uni<MAXTRIFF;uni++)
				*((unsigned long *)&Co.b[300+5]+MAXTRIFF*i+uni)=*((unsigned long *)&This_Month_Data.Energy_Record.Plus_Active[0]+MAXTRIFF*i+uni);
      }

		/*"��������"*/	
	  addr=5+sizeof(struct  FREEZE_ENERGY_DATA);						 
	  Freeze_Demand_Data=(struct FREEZE_DEMAND_DATA *)&Co.b[300+addr];
      
 if(demand_zero_flag)
   {
     for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].Demand;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].Demand;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].time[i];
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].time[i];
    	}
     }
  }
 else
 {
     for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=0x00000000;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=0x00000000;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=0x00;
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=0x00;
    	}
     }
}
     /*"�������"*/
	  addr=5+sizeof(struct	FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA);						
	  Freeze_Power_Data=(struct FREEZE_POWER_DATA *)&Co.b[300+addr];
		 	
	  for(uni=0;uni<4;uni++)
	  {
	     	Freeze_Power_Data->Active_power_t[uni]=COMM_Active_power[uni];
			Freeze_Power_Data->Reactive_power_t[uni]=COMM_Reactive_power[uni];				 
	  }
	  
	 CheckPowerDown();
	
	 Write_File(file_name,0,data_length,&Co.b[300]);

	 /*"����Ǯ������"*/
	 if((file_name>=FREEZE_DAY_START_FILE)&&(file_name<(FREEZE_DAY_START_FILE+MAX_NUMBER_FREEZE_DAY)))								/*"Li_�ն������Ч"*/		//Li Update 20130506
		 F_E_BurseFreezeData();			//Li Update 20130320

     FeedWatchdog();     
	 CheckPowerDown();  
}


/*"============================================================"*/
/*"��������Freeze_Day"*/
/*"��;���ն���"*/
/*"��������"*/
/*"���أ���"*/
/*"//added by fxf	2009-09-10"*/
/*"============================================================"*/
void Freeze_Day(void)
{
  unsigned int pointer;
  
	if((Meter_Parameter.freeze_parameter.FreezeDay_Hour==softdate.Hour)&&(Meter_Parameter.freeze_parameter.FreezeDay_Min==softdate.Min))
	{		
      ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr
	    ,FREEZE_DAY_START_FILE);/*"���������жϴ���"*/ 
	     
	    pointer=O1ther_Meter_Parameter.FreezeData_Day_Addr;
	    FreezeDateProgram(FREEZE_DAY_START_FILE+pointer, 1, (unsigned char *)&softdate);///king chen modify 130609
  	  pointer++;
  	  pointer%=MAX_NUMBER_FREEZE_DAY;	
      O1ther_Meter_Parameter.FreezeData_Day_Addr=pointer;
      WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr,1,0,0); 
      ///Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
      
	    O1ther_Meter_Parameter.DayFreezeReferenceDate=softdate;///king chen add 130302
	    O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
	    WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); 
  }
      
}
/*"============================================================"*/
/*"��������Clear_Freeze"*/
/*"��;���嶳������"*/
/*"��������"*/
/*"���أ���"*/
/*"NOTE��freeze.c",Initram.c,Interrupt.c,main.c,comm.c,comm.h,AllVoltageloss.c*/

/*"//added by FXF	2009-03-12"*/
/*"============================================================"*/




unsigned char  Clear_Freeze(void)
{ 	
		unsigned int i,length;
		CheckPowerDown();
	 	O1ther_Meter_Parameter.FreezeData_Time_addr=EVENT_CLAER_STATUS;	
		O1ther_Meter_Parameter.FreezeData_Moment_addr=EVENT_CLAER_STATUS; 	
		Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr=EVENT_CLAER_STATUS;				
		Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr=EVENT_CLAER_STATUS;		
		O1ther_Meter_Parameter.FreezeData_Period_addr=0; 	
		O1ther_Meter_Parameter.FreezeData_Day_Addr=EVENT_CLAER_STATUS; 
		WRLC256(FREEZE_TIME_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr,4,0,0);
		WRLC256(FREEZE_DALIYSLOT_ADDR_ROM,(unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr,1,0,0);
		WRLC256(FREEZE_TRIFF_ADDR_ROM,(unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr,1,0,0);
		
		///Set_Meter_para_Deal(FREEZE_TIME_ADDR_ROM);
		Set_Meter_para_Deal(FREEZE_DALIYSLOT_ADDR_ROM);

		Event_Meter_Pro_Pointer.Energypasszero_P=EVENT_CLAER_STATUS;		
		WRLC256(ENERGYPASSZERO_P_ROM,(unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P,1,0,0);
		FeedWatchdog(); 

		Pay_For_Event_Point.Triff_Switch_Event_P = EVENT_CLAER_STATUS;
		Pay_For_Event_Point.Step_Switch_Event_P = EVENT_CLAER_STATUS;
		Pay_For_Event_Point.E_Burse_Event_P = EVENT_CLAER_STATUS;
		WRLC256(TRIFF_SWITCH_EVENT_P_EE,(unsigned char *)&Pay_For_Event_Point.Triff_Switch_Event_P,2,0,0);
		WRLC256(E_BURSE_EVENT_P_EE,(unsigned char *)&Pay_For_Event_Point.E_Burse_Event_P,1,0,0);

        //Delete_File(FREEZE_TIME_SORT_START_FILE);
        //Delete_File(FREEZE_MOMENT_SORT_START_FILE);
        //Delete_File(FREEZE_TRIFF_CHANGE_SORT_START_FILE);
        //Delete_File(FREEZE_DAILYSLOT_CHANGE_START_FILE);
        //Delete_File(FREEZE_DAY_START_FILE);
        //Delete_File(FREEZE_ENERGYPASSZERO_START_FILE);		

        Clear_Freeze_Period();
            
		return 0xff;
}


void  Clear_Freeze_Period(void)
{ 	
		/*""unsigned int i,length;

		for(i=0;i<254;i++)
				Co.b[400+i]=0xFF;

		for(i=0;i<13;i++)
		{
		       WRLC256(FREEZEDATA_PERIOD_ROM+i*254,(unsigned char *)&Co.b[400],254,0,0);		
		       FeedWatchdog(); 
               CheckPowerDown();
		}
"*/
		WRLC256(FREEZEDATA_PERIOD_ROM, 0, 13 * 254, 0, 0);
}

/*"******************************************************************************"*/
/*"�� �� ����DateToDays"*/
/*"��    �ܣ�����ת���ɾ���2000��1��1�յ�����"*/
/*" ˵    ������Ҫ�ȶ����ڵĺϷ��Խ��м��	"*/
/*" ��ڲ�����"*/
/*"	rpDateTime: ����ʱ������"*/
/*" �� �� ֵ:"*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2011-11-11"*/
/*"******************************************************************************"*/



unsigned long DateToDays(TDateTime* rpDateTime)
{
	unsigned char nYear;
	unsigned char nMonth;
	unsigned char nDay;	
	unsigned long nDays;
	int i;
	
	nYear  = OB_H(rpDateTime->Year);
	nMonth = OB_H(rpDateTime->Month);
	nDay   = OB_H(rpDateTime->Day);
	
	nDays = ((365 << 2) + 1) * (nYear >> 2);
	nYear &= 0x03;
	
	nDays += nYear * 365;
	
	for(i=0; i<nMonth-1; i++)
	{
		nDays += DaysOfMonth[i];
	}
	
	nDays += nDay;
	
	if((nYear > 0) || (nMonth > 2))
	{
		nDays++;
	}
	
	return nDays-1;
}


/*"******************************************************************************"*/
/*" �� �� ����DateTimeToInt"*/
/*" ��    �ܣ�����ʱ������ת��Ϊ����2000��1��1��0ʱ0��0�������"*/
/*" ˵    ������Ҫ�ȶ����ڵĺϷ��Խ��м��	"*/
/*" ��ڲ�����"*/
/*"	rpDateTime: ����ʱ������"*/
/*" �� �� ֵ:"*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2011-11-11"*/
/*"******************************************************************************"*/
unsigned char DateTimeToInt(TDateTime* rpDateTime, unsigned long *pSeconds)
{
	if(0 == CheckDateTime(rpDateTime))
	{
	    return 0;
	}
	*pSeconds = DateToDays(rpDateTime) * 24L * 60L * 60L;
	*pSeconds += OB_H(rpDateTime->Hour) * 60L * 60L;
	*pSeconds += OB_H(rpDateTime->Minute) * 60L;
	*pSeconds += OB_H(rpDateTime->Second);
	
	return 1;
}





/*"******************************************************************************"*/
/*" �� �� ����CheckDateTime"*/
/*" ��    �ܣ�������������Ƿ�Ϸ�"*/
/*" ˵    �����������ʱ�������Ƿ�ΪBCD�룬��������ȷ�����ж������Ƿ�������һ�£�����24Сʱ��"*/
/*"     �������ֻ����һ���ֽڣ�����00��ֻ��2000��Ч��2100~2900����д"*/
/*" ��ڲ�����"*/
/*" rpDateTime: ����ʱ������"*/
/*" �� �� ֵ:"*/
/*"  TRUE-���ݺϷ�"*/
/*"  FALSE-���Ϸ�"*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2011-11-11"*/
/*"******************************************************************************"*/
unsigned char CheckDateTime(TDateTime* rpDateTime)					//HeZhaoHui    20131010
{
 unsigned char nMaxDay; 
  
 if(OB_H(rpDateTime->Second) > 99 || OB_H(rpDateTime->Minute) > 99
   || OB_H(rpDateTime->Hour) > 99 || OB_H(rpDateTime->Day) > 99
     || OB_H(rpDateTime->Month) > 99 || OB_H(rpDateTime->Year) > 99
	   || OB_H(rpDateTime->Week) > 7)
 {
  return 0;
 }

 
 if(rpDateTime->Hour > 0x23 || rpDateTime->Minute > 0x59 || rpDateTime->Second > 0x59)
 {
  return 0;
 }
 
 if(rpDateTime->Month < 1 || rpDateTime->Month > 0x12)
 {
  return 0;
 }
 
 nMaxDay = DaysOfMonth[OB_H(rpDateTime->Month)-1]; 
 if(((rpDateTime->Year & 0x13) == 0 || (rpDateTime->Year & 0x13) == 0x12) && rpDateTime->Month == 0x02) 
 {
  nMaxDay++;
 }
 if((0 == rpDateTime->Day) || (OB_H(rpDateTime->Day) > nMaxDay))
 {
  return 0;
 }
  
 return 1;
}





/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����IntToDate"*/
/*" ��    �ܣ�����2000��1��1�յ�����ת����������"*/
/*" ˵    ����	   "*/
/*" ��ڲ�����"*/
/*"	rInt������2000��1��1�յ�����"*/
/*"	rpDate�� ����ʱ������"*/
/*" �� �� ֵ:"*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2011-11-11"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
void IntToDate(unsigned long rInt, TDate* rpDate)
{
	unsigned long tmp1;
	unsigned long tmp2;
	unsigned char nFlag;
	
	int i;
	
	
	tmp1 = rInt / (365*3+366);
	tmp2 = rInt % (365*3+366);
	rpDate->Year = (tmp1 << 2);
	
	nFlag = 0;
	
	if (tmp2 > (31 + 28 - 1))
	{
		tmp2--;
		nFlag = 1;
	}
	
	
	tmp1 = tmp2 / 365L;
	tmp2 = tmp2 % 365L;
	rpDate->Year += tmp1;
	
	tmp2++;
	
	
	for(i=0; i<12; i++)
	{
		if(tmp2 > DaysOfMonth[i])
		{
			tmp2 -= DaysOfMonth[i];
		}
		else
		{
			break;
		}
	}
	rpDate->Month = i+1;
	
	
	rpDate->Day = tmp2;
	
	
	if(nFlag && rpDate->Month == 2 && (rpDate->Year & 0x03) == 0)
	{
		rpDate->Day++;
	}
	
	
	rpDate->Year = OH_B(rpDate->Year);
	rpDate->Month = OH_B(rpDate->Month);
	rpDate->Day = OH_B(rpDate->Day);
}
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����IntToDateTime"*/
/*" ��    �ܣ�����2000��1��1��0��0��0�������ת����������ʱ����"*/
/*" ˵    ������ȷ���������ݵ���ȷ�ԣ������������ж�"*/
/*" ��ڲ�����"*/
/*"    rInt������2000��1��1��0��0��0�������"*/
/*"    rpDateTime�� ����ʱ������"*/
/*" �� �� ֵ:"*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2011-11-11"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
void IntToDateTime(unsigned long rInt, TDateTime* rpDateTime)
{
    TDate nDate;
    unsigned long nRemainSeconds;
    unsigned long nDays;     
    nDays = rInt / (60L*60L*24L);
    nRemainSeconds = rInt % (60L*60L*24L);     
    IntToDate(nDays, &nDate);
    rpDateTime->Year  = nDate.Year;
    rpDateTime->Month = nDate.Month;
    rpDateTime->Day   = nDate.Day;     
    rpDateTime->Week = (nDays - 6) % 7;     
    rpDateTime->Hour = nRemainSeconds / 3600L;
    nRemainSeconds = nRemainSeconds % 3600L;
    rpDateTime->Minute = nRemainSeconds / 60L;
    rpDateTime->Second = nRemainSeconds % 60L;     // transform hour, minute and second to BCD
    rpDateTime->Hour = OH_B(rpDateTime->Hour);
    rpDateTime->Minute = OH_B(rpDateTime->Minute);
    rpDateTime->Second = OH_B(rpDateTime->Second);
}

/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����GetSkipedTimeFlags"*/
/*" ��    �ܣ���������ʱ���֮���Խ���趨ʱ����������ȡ�������ʱ����������ɸ���ʱ�꼯����ʱ���Ⱥ�  ���� ���� "*/
/*" ˵    ����"*/
/*"    ��ʼʱ�䡢����ʱ�䡢�趨ʱ�����ΪBCD��"*/
/*"    ����ʱ����������ʱ��㣬����������ʼʱ��㣬�翪ʼʱ��Ϊ2012-12-19 00:00:00������ʱ��Ϊ2012-12-20 00:00:00"*/
/*"    ����趨ʱ��Ϊ99-99-99 00:00:00�������չ���㣬���ҵ�2012-12-20 00:00:00һ��ʱ���"*/
/*" ��ڲ�����"*/
/*"    rpTime1: ��ʼʱ�� week��0"*/
/*"    rpTime2: ����ʱ�� week��0"*/
/*"    rpTimeFlag: �趨ʱ�꣬99����ͨ�䣬����λ��ͨ���ʱ����λ�Զ�ͨ�� "*/
/*"    rpResult: ���صĲ��ҵ���ʱ�꼯����ʱ���Ⱥ�  ���� ���� "*/
/*"    rMax:     rpResult����󷵻ظ��� "*/
/*" �� �� ֵ:"*/
/*"    ���ҵ���ʱ������� 0����û���ҵ���-1��������������� "*/
/*" ��   �ƣ�Hezhaohui             ����ʱ��: 2012-12-20"*/
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
int GetSkipedTimeFlags(TDateTime* rpTime1,TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax)
{
    unsigned long nTime1;
    unsigned long nTime2;
    unsigned long nDateTimeInt; /*"�������ҵ�ʱ�䣬��������"*/
    
    int nCount; //count of results
    int nRunTimes; // count of while loops
    int i;
    
    unsigned char nMode; /*"ʱ������"*/
    TDateTime nDateTime; /*"�������ҵ�ʱ�䣬�ṹ������"*/    

    // check input parameters
    if(0 == DateTimeToInt(rpTime1, &nTime1))
    {
        return -1;
    }
    if(0 == DateTimeToInt(rpTime2, &nTime2))
    {
        return -1;
    }       
   
    // find out time flag type
    for(nMode = 6; nMode > 0; nMode--)
    {
        if(*(((unsigned char*) rpTimeFlag) + nMode - 1) == 0x99)
        {
            break;
        }
    }

    // check valitation of rpTimeFlag    
    nDateTime = *rpTimeFlag;
    switch(nMode)
    {
        case 6:
            nDateTime.Second= 0;
        case 5:
            nDateTime.Minute = 0;
        case 4:
            nDateTime.Hour = 0;
        case 3:
            nDateTime.Day = 1;
        case 2:
            nDateTime.Month = 1;
        case 1:
            nDateTime.Year = 1;
        default:
            break;
    }
    nDateTime.Week = 0;
    if(0 == CheckTime((unsigned char *)&nDateTime))
    {
        return -1;
    }

    //if start time larger than end time, return error flag
    if(nTime1 > nTime2)
    {
        return 0;///king chen modify 130609
    }
    
    // make a time with 99 replaced by time2
    for(i = 6; i > nMode; i--)
    {
        *(((unsigned char*) &nDateTime) + i - 1) = *(((unsigned char*) rpTimeFlag) + i - 1);
    }
    for(i = nMode; i > 0; i--)
    {
        *(((unsigned char*) &nDateTime) + i - 1) = *(((unsigned char*) rpTime2) + i - 1);
    }    
    nDateTime.Week = 0;

    //if combined time invalid, return error flag
    if(0 == DateTimeToInt(&nDateTime, &nDateTimeInt))
    {
        return -1;
    }

    
    nCount = 0;
    nRunTimes = 0;
    while((nDateTimeInt > nTime1) && (nCount < rMax))// decrease result time to find out all time-flags
    {
        unsigned long nInterval;
        IntToDateTime(nDateTimeInt, &nDateTime);
        if(nDateTimeInt <= nTime2)
        {
            rpResult->Year = nDateTime.Year;
            rpResult->Month = nDateTime.Month;
            rpResult->Day = nDateTime.Day;
            rpResult->Hour = nDateTime.Hour;
            rpResult->Minute = nDateTime.Minute;
            rpResult->Second = nDateTime.Second;
            rpResult->Week = 0;
            rpResult++;
            nCount++;
        }
        switch(nMode)
        {
        case 6:
            nInterval = 1;
            break;
        case 5:
            nInterval = 60L;
            break;
        case 4:
            nInterval = (60L * 60L);
            break;
        case 3:
            nInterval = (24L * 60L * 60L);
            break;
        case 2:
        {
            unsigned char nYear = OB_H(nDateTime.Year);
            unsigned char nMonth = OB_H(nDateTime.Month);
            if(nMonth == 1)
            {
                nMonth = 12;
            } else
            {
                nMonth--;
            }
            nInterval = DaysOfMonth[nMonth - 1];
            if((nMonth == 2) && ((nYear & 0x03) == 0))
            {
                nInterval++;
            }
            nInterval *= (24L * 60L * 60L);
        }
            break;
        case 1:
        {
            unsigned char nYear = OB_H(nDateTime.Year);
			unsigned char nMonth = OB_H(nDateTime.Month); 
			unsigned char nDay = OB_H(nDateTime.Day); 
            nInterval = 365;
			if((((nYear & 0x03) == 0) && ((nMonth > 2)|| ((nMonth==0x02) && (nDay == 29)) )) ||(((nYear & 0x03) == 0x01) && (nMonth < 3))) 		//HeZhaoHui 20131009
			{
                nInterval++;
            }
            nInterval *= (24L * 60L * 60L);
        }
            break;
        case 0:
            nInterval = nTime2 - nTime1;
            break;
        }
        nDateTimeInt -= nInterval;

        nRunTimes++;
        if(nRunTimes > (rMax + 1))
        {
            break;       
        }
    }
    
    return nCount;
}


#pragma SECTION program ROM_PRG2

void PowerUpDayFreeze(void)
{
 ///unsigned int uni,addr;
 ///unsigned int file_name=0,data_length=0;
 ///unsigned int pointer=0;

///unsigned char DayFreezePowerupComplete;        /*"�ϵ粹�ն���������ɱ�־"*/
 int stridebill_dot_num = 0;/*""*/
 int stridefreeze_dot_num = 0;/*""*/
 int stridefreezePrebill_dot_num = 0;/*""*/

 
 unsigned int freezeday_num;
 unsigned int stridebill_dot_start_num;///king chen add 130105
 
  unsigned char billdaygreater_flag=0;///king chen add 130228
  ///unsigned char FlashIsEmpty=0;///king chen mark 130302
  
  struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
  struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
  
 struct DATEANDTIME_DEF LastDayfreezeTime_temp;///king chen add 130319
 struct DATEANDTIME_DEF LastDayfreezeTime;/*"���һ���ն���ʱ��"*/
 struct DATEANDTIME_DEF Now_time;/*"�ϵ�ʱ��ʱ��"*/
 struct DATEANDTIME_DEF DayFreeze_Dot;/*"���õ��ն����"*/
 struct DATEANDTIME_DEF FirstBillDay_Dot;/*"���õĵ�һ������"*/
 struct DATEANDTIME_DEF StrideBill_Dot_List[12];/*"�����ڼ����ĵ�һ������ʱ����б����������12��"*/
 struct DATEANDTIME_DEF StrideFreeze_Dot_List[MAX_DAYFREEZE_POWERUP_STRIDE];
 struct DATEANDTIME_DEF StrideFreezePreBill_Dot_List[MAX_DAYFREEZE_POWERUP_STRIDE];

    Now_time = softdate;
/*"�ն������ݵ�ʱ�����"*/   
    DayFreeze_Dot.Year = 0x99;
    DayFreeze_Dot.Month= 0x99;
    DayFreeze_Dot.Day= 0x99;
    DayFreeze_Dot.Hour= Meter_Parameter.freeze_parameter.FreezeDay_Hour;
    DayFreeze_Dot.Min= Meter_Parameter.freeze_parameter.FreezeDay_Min;
    DayFreeze_Dot.Sec = 0;
    DayFreeze_Dot.Week= 0;
/*"��һ���������ݵ�ʱ�����"*/
    FirstBillDay_Dot.Year = 0x99;
    FirstBillDay_Dot.Month= 0x99;
    FirstBillDay_Dot.Day= Meter_Parameter.parameter1.AutoBillDayHour[0].Day;
    FirstBillDay_Dot.Hour= Meter_Parameter.parameter1.AutoBillDayHour[0].Hour;
    FirstBillDay_Dot.Min= 0;
    FirstBillDay_Dot.Sec = 0;
    FirstBillDay_Dot.Week= 0;
   #if 0  
    ///WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,1); 
     LastDayfreezeTime=O1ther_Meter_Parameter.DayFreezeReferenceDate;///king chen add 130302
	 
/// if((Check_Data_valid(&Co.b[300],data_length)==-1) && (Meter_Parameter.freeze_parameter.FreezeData_Day_Addr==0))
/// 	{
//// 	stridefreeze_dot_num = GetSkipedTimeFlags((TDateTime *)&Powerdown_Save_Data.date, (TDateTime *)&Now_time, 
///		                                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreeze_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE);
/// 	FlashIsEmpty=1;
///	LastDayfreezeTime=Powerdown_Save_Data.date;
	
 ///      	if( (stridefreeze_dot_num<MAX_DAYFREEZE_POWERUP_STRIDE)&&(Powerdown_Save_Data.date.Hour==Meter_Parameter.freeze_parameter.FreezeDay_Hour)
///				&&(Powerdown_Save_Data.date.Min>=Meter_Parameter.freeze_parameter.FreezeDay_Min)
///				&&(Powerdown_Save_Data.date.Min<=(Meter_Parameter.freeze_parameter.FreezeDay_Min+2))
///				&&(O1ther_Meter_Parameter.Dayfreeze_flag==0))
///				{				
///				stridefreeze_dot_num+=1;
///				StrideFreeze_Dot_List[stridefreeze_dot_num-1]=Powerdown_Save_Data.date;	   
///				}	
 ///	}

 if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))
	{
         pointer=Meter_Parameter.freeze_parameter.FreezeData_Day_Addr;///king chen add 130302
         if(pointer==0)
             pointer=MAX_NUMBER_FREEZE_DAY -1;
         else
             pointer=pointer -1;
 
         file_name=FREEZE_DAY_START_FILE+pointer;
         data_length=5;
         for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;
         Read_File(file_name, 0,data_length,&Co.b[300]);
 
         LastDayfreezeTime.Year=Co.b[300];
         LastDayfreezeTime.Month=Co.b[301];
         LastDayfreezeTime.Day=Co.b[302];
         LastDayfreezeTime.Hour=Co.b[303];
         LastDayfreezeTime.Min=Co.b[304];
         LastDayfreezeTime.Sec=0;
         LastDayfreezeTime.Week=0;
		 
	  if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))
		return ;
	}
 #endif
 
  
 
  LastDayfreezeTime=O1ther_Meter_Parameter.DayFreezeReferenceDate;///king chen add 130302
  
 /// if(ComparentTime((unsigned char *)&LastDayfreezeTime, (unsigned char *)&Powerdown_Save_Data.date)==ResultLarger)///king chen mark 130319
/// 	      return ;
///  else
      if(O1ther_Meter_Parameter.PowerOnDayfreeze_flag!=4)///king chen add 130322
 	{
 	 LastDayfreezeTime_temp=LastDayfreezeTime;
 	 LastDayfreezeTime = Powerdown_Save_Data.date;
  	}
 ///if(0 == CheckTime((unsigned char *)&LastDayfreezeTime))///king chen add 130422
 ///{
 ///   LastDayfreezeTime=softdate;
///    WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); ///king chen add 130422
///    return ;
 ///}
if((!CheckTime((unsigned char *)&Now_time)) ||(!CheckTime((unsigned char *)&LastDayfreezeTime)))
        return ;	
 
if((0 == O1ther_Meter_Parameter.PowerOnDayfreeze_flag) ||(4 == O1ther_Meter_Parameter.PowerOnDayfreeze_flag))/*"POWER UP DAY FREEZE NOT COMPLETE"*/
{
 ///O1ther_Meter_Parameter.PowerOnDayfreeze_flag=0;
 WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen modify 130228

   stridebill_dot_num = GetSkipedTimeFlags((TDateTime *)&LastDayfreezeTime, (TDateTime *)&Now_time, 
		                                                   (TDateTime *)&FirstBillDay_Dot, (TDateTime *)&StrideBill_Dot_List[0], 2);
  
  stridefreeze_dot_num = GetSkipedTimeFlags((TDateTime *)&LastDayfreezeTime, (TDateTime *)&Now_time, 
		                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreeze_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE);
  
 if((stridefreeze_dot_num>=0)&& (stridefreeze_dot_num<MAX_DAYFREEZE_POWERUP_STRIDE)&&(O1ther_Meter_Parameter.PowerOnDayfreeze_flag!=4)
                            &&(Powerdown_Save_Data.date.Hour==Meter_Parameter.freeze_parameter.FreezeDay_Hour)
				&&(Powerdown_Save_Data.date.Min==Meter_Parameter.freeze_parameter.FreezeDay_Min)
				&&(ComparentTime((unsigned char *)&LastDayfreezeTime_temp, (unsigned char *)&Powerdown_Save_Data.date)!=ResultEqual)
				&&(Powerdown_Save_Data.date.Sec<=2)) ///king chen add 130510
				{
				stridefreeze_dot_num+=1;
				StrideFreeze_Dot_List[stridefreeze_dot_num-1]=Powerdown_Save_Data.date;///king chen modify 130105				
				}
 
if(stridefreeze_dot_num>MAX_DAYFREEZE_POWERUP_STRIDE)	
    return ;

if((stridebill_dot_num > 0)&&(stridefreeze_dot_num>0))/*"�����ڼ�����1�ο����һ������"*/
    {
    /*"���ҵ�һ������ǰ���ն����"*/
    if((stridefreeze_dot_num)&&(Meter_Parameter.parameter1.MeterMode[2].bit.b6))///king chen modify 130313
       stridefreezePrebill_dot_num = GetSkipedTimeFlags((TDateTime *)&StrideFreeze_Dot_List[stridefreeze_dot_num-1], (TDateTime *)&StrideBill_Dot_List[stridebill_dot_num-1], 
		                                                   (TDateTime *)&DayFreeze_Dot, (TDateTime *)&StrideFreezePreBill_Dot_List[0], MAX_DAYFREEZE_POWERUP_STRIDE) ;
    if(stridefreezePrebill_dot_num )/*"GetSkipedTimeFlags()���Һ���:����ʱ����������ʱ��㣬����������ʼʱ��㣬��������ҵ���Ҫ��1"*/
		  stridefreezePrebill_dot_num +=1;///king chen add 130105
    else if(0==stridefreezePrebill_dot_num )///king chen add 130228
    	{
    	if((stridefreeze_dot_num)&&(Meter_Parameter.parameter1.MeterMode[2].bit.b6))///king chen modify 130316
    	{
    	 
    	  billdaygreater_flag=ComparentTime( (unsigned char *)&StrideBill_Dot_List[stridebill_dot_num-1],(unsigned char *)&StrideFreeze_Dot_List[stridefreeze_dot_num-1]); 
	 
    	  if((billdaygreater_flag==ResultLarger) || (billdaygreater_flag==ResultEqual))
    	       stridefreezePrebill_dot_num=1;
    	  else if(billdaygreater_flag==ResultSmaller)
    	       stridefreezePrebill_dot_num=0;    	
    	}
    	}
	
    if(stridefreezePrebill_dot_num > 0)/*"���ն������ݵ��п����һ������"*/
    {    
    if(stridefreeze_dot_num >= stridefreezePrebill_dot_num)
    {
    	CheckPowerDown();
    for(freezeday_num = 0; freezeday_num < stridefreezePrebill_dot_num; freezeday_num++)/*"��һ������ǰ���ն����"*/
    	{
    	/*"���ն������ݣ���������ȡ�ϵ�ʱ�̵�ǰ����ֵ"*/
    	/*"�ն�������ʱ��ΪStrideFreezePreBill_Dot_List�б�������洢"*/
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 0,stridebill_dot_start_num, freezeday_num);	
        stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
        Dayfreeze_Recompense(1,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);
    	}    
    for(freezeday_num = 0;freezeday_num< (stridefreeze_dot_num - stridefreezePrebill_dot_num); freezeday_num++)/*"��һ�����պ���ն����"*/
    	{
    	/*"���ն������ݣ��������ݲ�0ֵ"*/
    	/*"�ն�������ʱ��ΪStrideFreeze_Dot_List�б�������洢"*/
    	////stridebill_dot_start_num=stridefreeze_dot_num - stridefreezePrebill_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 1,stridebill_dot_start_num, freezeday_num);	
       stridebill_dot_start_num=stridefreeze_dot_num - stridefreezePrebill_dot_num - freezeday_num -1;
        Dayfreeze_Recompense(0,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);
    	}
    }    
    }
    else/*"���ն������ݵ�û�п����һ�����գ������ڵ�һ�����պ���"*/
    {
    CheckPowerDown();
    /*"���ն������ݣ��������ݲ�0ֵ"*/
      for(freezeday_num = 0; freezeday_num< stridefreeze_dot_num; freezeday_num++)/*"��һ������ǰ���ն����"*/
    	{
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 1,stridebill_dot_start_num, freezeday_num);	
    	stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
    	Dayfreeze_Recompense(0,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);	
    	}
    }
   }
    else if((stridebill_dot_num == 0)&&(stridefreeze_dot_num>0))/*"�����ڼ�û�п����һ�����գ��������ݲ��ϵ�ʱ�̵�ǰ����ֵ"*/
    {
    CheckPowerDown();
    /*"���ն������ݣ���������ȡ�ϵ�ʱ�̵�ǰ����ֵ"*/
  for(freezeday_num= 0; freezeday_num< stridefreeze_dot_num; freezeday_num++)/*"��һ������ǰ���ն����"*/
    	{
    	///stridebill_dot_start_num=stridefreeze_dot_num;
    	///Dayfreeze_Recompense((TDateTime *)&StrideFreeze_Dot_List[0], 0,stridebill_dot_start_num, freezeday_num);	
    	stridebill_dot_start_num=stridefreeze_dot_num - freezeday_num -1;
    	Dayfreeze_Recompense(1,(unsigned char *)&StrideFreeze_Dot_List[stridebill_dot_start_num]);	
    	}
   }
 O1ther_Meter_Parameter.PowerOnDayfreeze_flag=1;
 WRLC256(POWERONDAYFREEZE_FLAG_ROM ,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen modify 130228	
}


}



 #if 0 
/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����Dayfreeze_Recompense"*/
/*" ��    �ܣ��ϵ粹�ն������� "*/
/*" ˵    ����"*/
/*" ��ڲ�����"*/
/*"    StrideFreeze_Dot_List: ���ҵ���ʱ�꼯����ʱ���Ⱥ�  ���� ���� "*/
/*"    demand_zero_flag: �ն�����������ı�־������ʱ��Ϊ1������Ϊ0"*/
/*"    stridebill_dot_start_num: ���β��ն������ݵĵ�һ�����ݵ���ʼ��"*/
/*"    freezeday_num: �ն��Ჹ���ĵ�ǰ�� "*/
///king chen add 130105
   
void Dayfreeze_Recompense(TDateTime * StrideFreeze_Dot_List, unsigned char demand_zero_flag,unsigned int stridebill_dot_start_num,unsigned int freezeday_num )
{

   unsigned int uni,i,addr;
   unsigned int  file_name=0,data_length=0;
   unsigned int pointer=0;
   
  struct  FREEZE_DEMAND_DATA    *Freeze_Demand_Data;
  struct  FREEZE_POWER_DATA     *Freeze_Power_Data;
  
    	/*"���ն������ݣ���������ȡ�ϵ�ʱ�̵�ǰ����ֵ"*/
	/*"�ն�������ʱ��ΪStrideFreezePreBill_Dot_List�б�������洢"*/
       p3_2=1;

       pointer=Meter_Parameter.freeze_parameter.FreezeData_Day_Addr;

       file_name=FREEZE_DAY_START_FILE+pointer;
       data_length=5+sizeof(struct  FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA)+sizeof(struct FREEZE_POWER_DATA); 
   
       for(uni=0;uni<data_length;uni++)
	      	Co.b[300+uni]=0;   
	   /*"����ʱ��"*/   

               {
                for(uni=0;uni<3;uni++) 
	        *((unsigned char *)&Co.b[300]+uni)=*((unsigned char *)StrideFreeze_Dot_List+(stridebill_dot_start_num-1 -freezeday_num)*7 + uni);
	        
		 Co.b[303]=Meter_Parameter.freeze_parameter.FreezeDay_Hour;
		 Co.b[304]=Meter_Parameter.freeze_parameter.FreezeDay_Min;
               }
       
               {
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Year=Co.b[300];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Month=Co.b[301];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Day=Co.b[302];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Hour=Co.b[303];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Min=Co.b[304];
		 O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
               O1ther_Meter_Parameter.DayFreezeReferenceDate.Week=0;
	       }
	   
	       	
	  /*"���������"*/   
  	     for(i=0;i<6;i++)
  	     {
	        for(uni=0;uni<MAXTRIFF;uni++)
				*((unsigned long *)&Co.b[300+5]+MAXTRIFF*i+uni)=*((unsigned long *)&This_Month_Data.Energy_Record.Plus_Active[0]+MAXTRIFF*i+uni);
  	     }

		/*"��������"*/	
	  addr=5+sizeof(struct  FREEZE_ENERGY_DATA);						 
	  Freeze_Demand_Data=(struct FREEZE_DEMAND_DATA *)&Co.b[300+addr];
   if(!demand_zero_flag)
   {
    for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].Demand;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].Demand;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Plus_Active[uni].time[i];
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=This_Month_Data.Demand_Record.Demand.Nega_Active[uni].time[i];
    	}
     }
    }
    else
    {
    for(uni=0;uni<MAXTRIFF;uni++)
     {
    	Freeze_Demand_Data->Plus_Active_Demand[uni]=0x00;
    	Freeze_Demand_Data->Nega_Active_Demand[uni]=0x00;
    	for(i=0;i<5;i++)
    	{
    		 Freeze_Demand_Data->Plus_Active_Demand_Time[uni][i]=0x00;
    		 Freeze_Demand_Data->Nega_Active_Demand_Time[uni][i]=0x00;
    	}
     }
    }
     /*"�������"*/
	  addr=5+sizeof(struct	FREEZE_ENERGY_DATA)+sizeof(struct FREEZE_DEMAND_DATA);						
	  Freeze_Power_Data=(struct FREEZE_POWER_DATA *)&Co.b[300+addr];

	
	  for(uni=0;uni<4;uni++)
	  {
	     	///Freeze_Power_Data->Active_power_t[uni]=COMM_Active_power[uni];///king  chen mark 121214
	     	///Freeze_Power_Data->Reactive_power_t[uni]=COMM_Reactive_power[uni];
	     	Freeze_Power_Data->Active_power_t[uni]=0x00;///king chen modify 130228
	     	Freeze_Power_Data->Reactive_power_t[uni]=0x00;
	  }
	
	 	
	 {
	     Write_File(file_name,0,data_length,&Co.b[300]);
	 }

	 O1ther_Meter_Parameter.PowerOnDayfreeze_flag=4;/*"��ʾ���粹�ն����Ѿ���ʼ�����������ǲ���һ���ն���"*/
	 WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen add 130322


	 /*"����Ǯ������"*/
	 F_E_BurseFreezeData();			//Li Update 20130319
	 
	 FeedWatchdog(); 
	 pointer++;
	 pointer%=MAX_NUMBER_FREEZE_DAY;	
        Meter_Parameter.freeze_parameter.FreezeData_Day_Addr=pointer;
        WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&Meter_Parameter.freeze_parameter.FreezeData_Day_Addr,1,0,0); 
        
	 WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); ///king chen add 130302
		
	Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
	 FeedWatchdog();
    
}
     #endif
///#pragma SECTION program ROM_PRG2
/*""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����Dayfreeze_Recompense"*/
/*" ��    �ܣ��ϵ粹�ն������� "*/
/*" ˵    ����"*/
/*" ��ڲ�����"*/
/*"    demand_zero_flag: �ն�����������־��������ʵ��ֵʱΪ1����������ʱ��Ϊ0"*/
/*"    StrideFreeze_Dot: ���ҵ���ʱ�꼯����ʱ���Ⱥ�  ���� ���� "*/
void Dayfreeze_Recompense(unsigned char  demand_flag, unsigned char * StrideFreeze_Dot)///king chen modify 130609
{
    unsigned char pointer;
    
    ClearEvent_EventBegin((unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr
	  ,FREEZE_DAY_START_FILE);/*"���������жϴ���"*/ 
    
    pointer=O1ther_Meter_Parameter.FreezeData_Day_Addr;
	  FreezeDateProgram(FREEZE_DAY_START_FILE+pointer,demand_flag, (unsigned char *)StrideFreeze_Dot);
  	pointer++;
  	pointer%=MAX_NUMBER_FREEZE_DAY;	
    O1ther_Meter_Parameter.FreezeData_Day_Addr=pointer;
    WRLC256(FREEZE_DAY_ADDR_ROM,(unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr,1,0,0); 
   /// Set_Meter_para_Deal(FREEZE_DAY_ADDR_ROM);
    
    O1ther_Meter_Parameter.PowerOnDayfreeze_flag=4;/*"��ʾ���粹�ն����Ѿ���ʼ�����������ǲ���һ���ն���"*/
	  WRLC256(POWERONDAYFREEZE_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnDayfreeze_flag,1,0,0); ///king chen add 130322
	  O1ther_Meter_Parameter.DayFreezeReferenceDate=(*((struct DATEANDTIME_DEF *)StrideFreeze_Dot));///king chen add 130302
	  O1ther_Meter_Parameter.DayFreezeReferenceDate.Sec=0;
	  WRLC256(DAYFREEZEREFERENCEDATE_ROM,(unsigned char *)&O1ther_Meter_Parameter.DayFreezeReferenceDate,7,0,0); 

}
/*"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*" �� �� ����ComparentTime"*/
/*" ��    �ܣ��Ƚ�t1,t2����ʱ��Ĵ�С,�Ƚϵ�����Ϊֹ,ʹ��ʱ��ע���Լ��Ƚϵ�ʱ���Ƿ���Ҫ�Ƚϵ�����"*/
/*" ˵    ����	   "*/
/*" ��ڲ�����"*/
/*"	t1��ʱ��1"*/
/*"	t2��ʱ��2"*/
/*" �� �� ֵ:ResultSmaller, t1<t2;ResultLarger ,t1>t2;ResultEqual, t1=t2"*/
unsigned char ComparentTime(unsigned char *t1, unsigned char *t2)
{
  unsigned char uni;
  
   for(uni=0;uni<5;uni++)
  	{
  	   if(*t1<*t2)
		return ResultSmaller;
	   else if(*t1>*t2)
		return ResultLarger;
	   t1++;
	   t2++;
  	}

    return ResultEqual;

}
//-------------------------------------------------------------------------------------//
#define   NULL  (void*)0
const unsigned long Clearfreeze_ID[9]={0x0500FFFF,          /*"��ʱ����"*/
                                                             0x0501FFFF,          /*"˲ʱ����"*/
                                                             0x0502FFFF,          /*"ʱ���л�����"*/
                                                             0x0503FFFF,          /*"ʱ�α��л�����"*/
                                                             0x0506FFFF,          /*"�ն���"*/
								     0x0512FFFF,          /*"������ת����"*/
								     0x0505FFFF,          /*"��ʱ�����л�����"*/
								     0x0507FFFF,		/*"�����ݶ��л�����"*/
								     0x050802FF};      	/*"ʣ�����ն���"*/
const struct CLEARFREEZE_STRU  ClearFreeze_Leaf[9]={
		       {FREEZE_TIME_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Time_addr, FREEZE_TIME_SORT_START_FILE},
			{FREEZE_MOMENT_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Moment_addr, FREEZE_MOMENT_SORT_START_FILE},
			{FREEZE_TRIFF_ADDR_ROM, (unsigned char *)&Meter_Parameter.parameter1.TriffSwitch.FreezeData_addr, FREEZE_TRIFF_CHANGE_SORT_START_FILE},
			{FREEZE_DALIYSLOT_ADDR_ROM, (unsigned char *)&Meter_Parameter.parameter1.DailySlotSwitch.FreezeData_addr, FREEZE_DAILYSLOT_CHANGE_START_FILE},
			{FREEZE_DAY_ADDR_ROM, (unsigned char *)&O1ther_Meter_Parameter.FreezeData_Day_Addr, FREEZE_DAY_START_FILE},
			{ENERGYPASSZERO_P_ROM, (unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P, FREEZE_ENERGYPASSZERO_START_FILE},
			{TRIFF_SWITCH_EVENT_P_EE, (unsigned char *)&Pay_For_Event_Point.Triff_Switch_Event_P, TRIFF_SWITCH_EVENT_FILE},
			{STEP_SWITCH_EVENT_P_EE, (unsigned char *)&Pay_For_Event_Point.Step_Switch_Event_P, STEP_SWITCH_EVENT_FILE},
			{E_BURSE_EVENT_P_OFFSET, (unsigned char *)&Pay_For_Event_Point.E_Burse_Event_P, E_BURSE_EVENT_FILE}
                                                                                     };
void ClearFreezeCommDeal(unsigned long Data_ID)
{
unsigned char uni = 0;
const struct CLEARFREEZE_STRU *Freeze_Node;
unsigned char search_ok = 0;

if(IntoPowerDownFlag == 0xff)/*"Ϊ��ֹ�͹�����ʾ���룬����ֻ�������ʶ������FLASH����������"*/
{
return;
}

/*"������������ֽ�ƥ��������ݱ�ʶ"*/
for(uni = 0; uni < ((sizeof(Clearfreeze_ID)) / sizeof(unsigned long)); uni++)
{
if((Clearfreeze_ID[uni] & 0xffff0000) == (Data_ID & 0xffff0000))
{
Freeze_Node=( const struct CLEARFREEZE_STRU *)&ClearFreeze_Leaf[uni];
search_ok = 0xff;
break;
}
}


if(search_ok == 0xff)/*"�������ݱ�ʶ�ɹ�"*/
{
if((Freeze_Node->Pointer) != NULL)/*"�¼�ָ�벻Ϊ��"*/
{
CheckPowerDown();
if((*(Freeze_Node->Pointer)) == EVENT_CLAER_STATUS)/*"�¼�ָ��Ϊ����״̬��������¼�FLASH�б�������"*/
	{
	Delete_File(Freeze_Node->Filename_begin);
	if ((Data_ID & 0xffff0000)==0x05080000)		/*"ʣ�����ն�����64���ļ�"*/
		{
		Delete_File(Freeze_Node->Filename_begin+32);
		Delete_File(Freeze_Node->Filename_begin+64);
		}		
	*(Freeze_Node->Pointer) = 0;
	WRLC256((Freeze_Node->Pointer_addr),0,1,0,0);
	Set_Meter_para_Deal(Freeze_Node->Pointer_addr);
	}
}
}
}
//------------------------------------------------------------------------------
