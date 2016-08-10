#include        "defmcro.h"
#include	"ram.h"
#include	"eeprom.h"
#include	"comm.h"
#include        "Demand.h"
#include	"Init_program_LDH.H"
#include	"I2C_operation.h"
#include	"MB_Showmain.h"
#include	"interrupt.h"
#include "Measure_Interface.h" 

#include "pay_def.h"
#include	"iccard.h"		//payment
#include	"Ex_Pay_For_Fun.h"
#include "Far_pay.h"	//farpayment 
#include "BackLight_Ctrl.h"
#include "eventnew.h"
#include "multi.h"

#define	SECOND_EN                p3_6	
#define	SECOND_EN_DIR            pd3_6	
#define	DEMAND_TIME_SW           p3_7	//Demand_cycle/TIME SWITCH
#define	DEMAND_TIME_SW_DIR       pd3_7	

extern union  BYTE_BIT     LossVoltage_Display_Flag;
extern union  BYTE_BIT     LossCurrent_Display_Flag;

extern unsigned char Light_Back_Up_Flag;
extern void Light_Back_Led(void);

void	Toggle_Loudspeaker(void);		/*"�Ƿ��б������Ƿ����������"*/
//void	Toggle_ALARM_LED(void);

///void	Flash_Led_Pannel(void);							//flash P+,P-,Q+,Q-,Alarm,Battery,Phase_Break,Current_Lose on LED_PANNEL///king chen mark 121214
void	Set_or_Clear_LCD_Flash_Flag(void);				/*"��LCD��ʾ��־����ǰ���ޡ�������������ʧѹʧ����𡢵�ر���"*/
void	Set_or_Clear_LCD_Current_Flash_Flag(void);		/*"�õ��������Ia,Ib,Ic��˸��־"*/
void	Clear_LCD_Current_Flash_Flag(void);				/*"����������Ia,Ib,Ic��˸��־"*/
void	Set_or_Clear_LCD_Voltage_Flash_Flag(void);		/*"��ʧѹ�����ʱUa,Ub,Uc��˸��־"*/
void	Set_or_Clear_LCD_Battery_Flag(void);			/*"��LCD�ϵ����ʾ��־"*/
unsigned char	LCD_LED_Speaker_Terminal_ALARM_Condition_Test(unsigned char);	/*"��ǰ״̬�뱨��ģʽ��ƥ��,0:���������1:�������"*/
void	Set_or_Clear_LCD_Alarm_Flag(void);				/*"��LCD�ϱ�����־"*/

void	Output_On_3_In_1_Terminal_Set(unsigned char Call_Condition);	
		/*"����һ�������������λ","�˺���Ӧ����������µ��ã������л�(Call_Condition=1)���������ڵ�(Call_Condition=2)��
		  �ϵ���޸�����һ��������ģʽ��(Call_Condition=0)"*/
//void	Output_On_3_In_1_Terminal_Reset(void);	
		/*"����һ�������������λ","�˺���Ӧ����ѭ���е���"*/
		
/*"Ԥ���ѱ����������ʱ������������״̬��������"*/		
void	Prepay_Overpower_Alarm(unsigned char Call_Condition);
//unsigned char Check_Voltage(void);	/*"���331��A,C��341��A,B,C�ĵ�ѹΪ0,�򷵻�0"*/
void	Check_If_Reset_Terminal_Alarm(void);		/*"����Ƿ�ȡ���������ӱ������"*/
void SoundAlarmEventCheck(unsigned char);  //add by pc 090824
void SoundAlarmEndCheck(void);  //add by pc 090824
void SoundAlarmInit(void);  //add by pc 090824
/*--------------------------------------------------------------------------*/

//unsigned long	Alarm_Terminal_Set_Starting_Time,Alarm_Demand_Set_Starting_Time;								/*"�����������ӿ�ʼ��λ��ʱ��"*/

unsigned char	VoltageGreaterThanThreshold_Flag;
unsigned char	VoltageGreaterThanCritical_Flag;  //add by pc 081227
union  LCD_LED_Speaker_Terminal_ALARM_FLAG  SoundAlarmFlag;  //add by pc 090824
union  LCD_LED_Speaker_Terminal_ALARM_FLAG  SoundAlarmEventFlag;  //add by pc 090824
union  LCD_LED_Speaker_Terminal_ALARM_FLAG  TempSoundAlarmEventFlag;  //add by pc 090824
union  TERMINALALARMFLAG  terminalalarmc[3]; 
unsigned char	VoltageGreaterThanICcard_Flag;	//payment

#define	Pulse_Width_of_3_in_1_Terminal			80		/*"����һ�����������������"*/	
/*---------------------------------------------- */
void	Toggle_Loudspeaker(void)	/*"�Ƿ��б������Ƿ����������"*/ 
{
			
			LCD_LED_Speaker_Terminal_ALARM_Condition_Test(3);
			SoundAlarmEventCheck(0);  //add by pc 090824
			if(VoltageGreaterThanThreshold_Flag==0)     /*"�������ѹ�Ƿ�����ż��ı�־"*/
              ALARM_SND=0;
              //LDH20060711
           else //LDH20060711
           {    //LDH20060711
			if(((((SoundAlarmFlag.Alarm_Flag)&(Meter_Parameter.parameter1.MeterMode_SpeakerAlarm_Flag.Alarm_Flag))!=0)&&(((Meter_Parameter.parameter1.MeterMode[3].byte)&0x04)!=0))
			    ||(Meter_States.Meter_Flag.bit.Energymodule_Err))   /*"����ģ���������������"*/
				{
					Buzzer_Alarm_SWitch_Flag |= 0x01;	//payment
					//if(ALARM_SND==0)
					//	ALARM_SND=1;
					//else
					//	ALARM_SND=0;
				}
			else
				Buzzer_Alarm_SWitch_Flag &= 0xFE;
				//ALARM_SND=0;
			} //LDH20060711
}

/*---------------------------------------------- */		
//int Get_LostVoltage_EventIndex(struct EVENT_POWER_NET_FLAG Event)
//{
//      if((Event.LostVoltage_A)||(Event.LostVoltage_B)||(Event.LostVoltage_C)||(Event.LostVoltage_AB)||
//	 (Event.LostVoltage_AC)||(Event.LostVoltage_BC)||(Event.LostVoltage_ABC))
//            return 1;
//      else
//	    return 0;
//}

/*---------------------------------------------- */		
//int Get_LostCurrent_EventIndex(struct EVENT_POWER_NET_FLAG Event)
//{
//      if((Event.LostCurrent_A)||(Event.LostCurrent_B)||(Event.LostCurrent_C)||(Event.LostCurrent_AB)||
//	 (Event.LostCurrent_AC)||(Event.LostCurrent_BC)||(Event.TotalLostCurrent))
//            return 1;
//      else
//            return 0;
//}


//int		Get_ReversePower_EventIndex(struct EVENT_POWER_NET_FLAG Event)
//		{
//			/*
//			if(Event.PowerReverse_T) return 1;
//			if(Event.PowerReverse_A) return 2;
//			if(Event.PowerReverse_B) return 3;
//			if(Event.PowerReverse_C) return 4;
//			*/
//			if((Event.PowerReverse_T)||(Event.PowerReverse_A)||(Event.PowerReverse_B)||(Event.PowerReverse_C))
//				return 1;
//			else
//				return 0;
//		}

/*---------------------------------------------- */			
#define	P_Current_Ratio		1.0/1000.0			//If Imax>=In*1/1000,P flashes.
#define	Q_Current_Ratio		1.0/1000.0			//If Imax>=In*1/1000,Q flashes.
//#pragma SECTION rom UserROMData
//const unsigned long P_Flash_Current_Threshold[10]= //	1.5(6)A                 1(2)A
//												{15000*P_Current_Ratio,10000*P_Current_Ratio,
//												  //	5(10)A                  10(40)A
//												 50000*P_Current_Ratio,100000*P_Current_Ratio,
//												  // 	0.3(1.2)A               5(6)A
//												 3000*P_Current_Ratio,15000*P_Current_Ratio,
//												  // 	5(50)A                 10(100)A
//												 50000*P_Current_Ratio,100000*P_Current_Ratio,
//												 // 	5(20)A                 30(100)A
//												 50000*P_Current_Ratio,300000*P_Current_Ratio};
												 
												 
//const unsigned long Q_Flash_Current_Threshold[8]= //	1.5(6)A                 1(2)A
//												{15000*Q_Current_Ratio,10000*Q_Current_Ratio,
//												  //	5(20)A                  10(40)A
//												  // 	0.3(1.2)A               5(6)A
//												 3000*Q_Current_Ratio,15000*Q_Current_Ratio,
//												  // 	15(60)A                 20(80)A
//												 150000*Q_Current_Ratio,200000*Q_Current_Ratio};

/*----------------------------------------------*/
	
void	Set_or_Clear_LCD_Flash_Flag(void)				/*"��LCD��ʾ��־:��ǰ���ޡ�������������ʧѹʧ����𡢵�ر���"*/
		{	
		       Set_or_Clear_LCD_Current_Flash_Flag();	/*"�õ�ǰ���ޡ����������Ia,Ib,Ic��˸��־"*/	
			Set_or_Clear_LCD_Voltage_Flash_Flag();		/*"��ʧѹ�����ʱUa,Ub,Uc��˸��־"*/
			Set_or_Clear_LCD_Battery_Flag();			/*"��LCD�ϵ����ʾ��־"*/	
			Set_or_Clear_LCD_Alarm_Flag();				/*"��LCD�ϱ�����־"*/	
			Toggle_Loudspeaker();	                        /*"�Ƿ��б������Ƿ����������"*/
		}


/*-----------------------------------------------------------------------------*/		
void	Set_or_Clear_LCD_Current_Flash_Flag(void)		/*"�õ��������Ia,Ib,Ic��˸��־"*/
		{
			unsigned long I_startup,Imax;
			unsigned int quadrant[4];					//quadrant value(0~3) of Sum,A,B,C	
			unsigned char dis_In;
			
			Get_Quadrant_Value(quadrant);				//get quadrant value(0~3) of Sum,A,B,C
			dis_In=Meter_Parameter.parameter1.DISP_In;
			I_startup=(Meter_Parameter.parameter1.EventJudgeIn*dis_In)/1000L;
			
					/*"��������ʾ�ñ�־"*/
			Imax=Get_Max_Value(Curr[0],Curr[1],Curr[2]);
					
			Show_flag.bit.I=0;				/*"һ����"*/
			Show_flag.bit.II=0;				/*"������"*/
			Show_flag.bit.III=0;				/*"������"*/
			Show_flag.bit.IV=0;				/*"������"*/
			if(Imax>=I_startup)
			{
					switch(quadrant[0])
						{
							case 0:				/*"һ����"*/
								Show_flag.bit.I=1;
								break;
							case 1:				/*"������"*/
							       Show_flag.bit.II=1;								
								break;
							case 2:				/*"������"*/
								Show_flag.bit.III=1;
								break;
							case 3:				/*"������"*/
								Show_flag.bit.IV=1;								
								break;
							default:
								break;
						}
			}
	
					//((Meter_States.Meter_Status2.bit.ActiveDirection_A)&&(Curr[0]>=I_startup)&&(Volt[0]>100000))
					if(Event_Power_Net_Flag.bit.PowerReverse_A==1)
						Show_flag.bit._Ia=1;
					else
						Show_flag.bit._Ia=0;
					
					//((Meter_States.Meter_Status2.bit.ActiveDirection_B)&&(Curr[1]>=I_startup)&&(Volt[1]>100000))
					if(Event_Power_Net_Flag.bit.PowerReverse_B==1)
						Show_flag.bit._Ib=1;
					else
						Show_flag.bit._Ib=0;
						
					//((Meter_States.Meter_Status2.bit.ActiveDirection_C)&&(Curr[2]>=I_startup)&&(Volt[2]>100000))
					if(Event_Power_Net_Flag.bit.PowerReverse_C==1)
						Show_flag.bit._Ic=1;
					else
						Show_flag.bit._Ic=0;
								 	
	        if((Event_Power_Net_Flag.bit.FailCurrent_A==1)
	          ||(Event_Power_Net_Flag.bit.BreakPhase_A==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	           Show_flag.bit.Ia=0;
	        else
	           Show_flag.bit.Ia=1;
	        
	        //mw modified 2009-10-09
					if(Event_Power_Net_Flag.bit.LostCurrent_A==1)
			 				Show_flash_falg.bit.Ia=1;								
					else						
							Show_flash_falg.bit.Ia=0;
						
						
					if((V_REGION==1)||(V_REGION==2))
					{
						   
	            if((Event_Power_Net_Flag.bit.FailCurrent_B==1)
	              ||(Event_Power_Net_Flag.bit.BreakPhase_B==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	              Show_flag.bit.Ib=0;
	            else
	              Show_flag.bit.Ib=1;
	            						
							if(Event_Power_Net_Flag.bit.LostCurrent_B==1)
			 					Show_flash_falg.bit.Ib=1;
							else								
								Show_flash_falg.bit.Ib=0;
											
					}
					else
					{
						Show_flag.bit.Ib=0;
						Show_flash_falg.bit.Ib=0;
					}
				
	        if((Event_Power_Net_Flag.bit.FailCurrent_C==1)
	         ||(Event_Power_Net_Flag.bit.BreakPhase_C==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	           Show_flag.bit.Ic=0;
	        else
	           Show_flag.bit.Ic=1;
	        	
	        //mw modified 2009-10-09	
					if(Event_Power_Net_Flag.bit.LostCurrent_C==1)
			 			 Show_flash_falg.bit.Ic=1;
					else					
						 Show_flash_falg.bit.Ic=0;										
			
		}
		
/*-----------------------------------------------------------------------------*/
#pragma SECTION rom UserROMData
const unsigned long Voltage_table_20[4]={200000L,440000L,115400L,760000L};
void	Set_or_Clear_LCD_Voltage_Flash_Flag(void)
{
	//unsigned char auxiliary_power_flag=0;
	if(Volt[0]<Voltage_table_20[V_REGION]&&
	Volt[1]<Voltage_table_20[V_REGION]&&
	Volt[2]<Voltage_table_20[V_REGION])
	{
	auxiliary_power_flag=1;
	///closebacklight_flag=0x00;///king chen add 130228
	}
	else
	{
	auxiliary_power_flag=0;
	///closebacklight_flag |=0x0f; ///king chen debug
	}

	/*" modified by Fuxf 2009-7-15 15:29:13 for Q/GDW "*/
	if((Event_Power_Net_Flag.bit.BreakPhase_A==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	 	 Show_flag.bit.Ua=0;
	else
	   Show_flag.bit.Ua=1;			
	
       //mw modified 2009-10-09 
	if((Event_Power_Net_Flag.bit.LostVoltage_A==1)||(Event_Power_Net_Flag.bit.Phase3LostVolt==1))
	 	 Show_flash_falg.bit.Ua=1;
	else
	   Show_flash_falg.bit.Ua=0;	
	
	if((V_REGION==1)||(V_REGION==2))
	{
	  if((Event_Power_Net_Flag.bit.BreakPhase_B==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	 	    Show_flag.bit.Ub=0;
	  else
	      Show_flag.bit.Ub=1;	
	  //mw modified 2009-10-09  
	  if((Event_Power_Net_Flag.bit.LostVoltage_B==1)||(Event_Power_Net_Flag.bit.Phase3LostVolt==1))
	 	   Show_flash_falg.bit.Ub=1;
	  else
	     Show_flash_falg.bit.Ub=0;
	}
	else
	{
		Show_flag.bit.Ub=0;
		Show_flash_falg.bit.Ub=0;
	}

	if((Event_Power_Net_Flag.bit.BreakPhase_C==1)||(Event_Power_Net_Flag.bit.PowerDownEvent==1))
	 	 Show_flag.bit.Uc=0;
	else
	   Show_flag.bit.Uc=1;	
	//mw modified 2009-10-09  
	if((Event_Power_Net_Flag.bit.LostVoltage_C==1)||(Event_Power_Net_Flag.bit.Phase3LostVolt==1))
	 	 Show_flash_falg.bit.Uc=1;
	else
	   Show_flash_falg.bit.Uc=0;
	
	if((Event_Power_Net_Flag.bit.VoltageReserve)||(Event_Power_Net_Flag.bit.CurrReverse))         /*"������"*/
	    Show_flash_falg.bit.Athwart=1;
	else
	    Show_flash_falg.bit.Athwart=0;
	    
}

/*-----------------------------------------------------------------------------*/
unsigned char rtcbatterydelay;
unsigned char pdbatterydelay;

void	Set_or_Clear_LCD_Battery_Flag(void)		/*"��LCD�ϵ����ʾ��־"*/
{   
			if(VB3_OK1==0)				//LDH20051208
			{
				Show_flag.bit.BATTERIES2=1;
				Meter_States.Meter_Flag.bit.Battery3_Err=1;
			}
			else
			{
				Show_flag.bit.BATTERIES2=0;
				Meter_States.Meter_Flag.bit.Battery3_Err=0;                
			}
				
			if(VB1_OK==0)						/*"��ʱ�ӵ��Ƿѹ"*/
			{
				Show_flag.bit.BATTERIES1=1;
				Meter_States.Meter_Flag.bit.Battery1_Err=1;
			}
			else
			{
				Show_flag.bit.BATTERIES1=0;
				Meter_States.Meter_Flag.bit.Battery1_Err=0;                
			}
	 
	 /*"ʱ�ӵ��"*/
	 if(Alarm_Map_Flag[0].bit.b2==0)
	 {
	 	 if(VB1_OK==0) /*"Ƿѹ"*/
	 	 {
	 	 	 rtcbatterydelay++;
	 	 	 if(rtcbatterydelay>=60)
	 	 	 {
	 	 	  rtcbatterydelay=0;
	 	 	  Alarm_Map_Flag[0].bit.b2=1;
	 	 	 }
	 	 }
	 	 else
	 	 {
	 	 	 rtcbatterydelay=0;
	 	 }
	 }
	 else
	 {
	 	  if(VB1_OK==1) /*"��Ƿѹ"*/
	 	  {
	 	 	  rtcbatterydelay++;
	 	 	  if(rtcbatterydelay>=60)
	 	 	  {
	 	 	    rtcbatterydelay=0;
	 	 	    Alarm_Map_Flag[0].bit.b2=0;
	 	 	  }
	 	  }
	 	  else
	 	  {
	 	 	  rtcbatterydelay=0;
	 	  }
	 }

if(Meter_Parameter.parameter1.EventReportMode.byte[0] & 0x08)
{
   if((!EventStatus_flag.bit.Clock_Battery_Volt_low)&&(Alarm_Map_Flag[0].bit.b2))/*"�����ϱ�����ʱ�ӵ��Ƿѹ"*/
   {
      EventReportState_Expand(3, 5, 0);  
      if(Event_Report_Status_Times.Clock_Battery_Volt_low_times != 255)
      {
         Event_Report_Status_Times.Clock_Battery_Volt_low_times = 255;
         Save_EventReportTimes(CLOCK_BATTERY_VOLT_LOW_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.Clock_Battery_Volt_low_times);
      }	
   }
}
   if(Alarm_Map_Flag[0].bit.b2==0)
   {
   	 EventReportState_Expand(3, 5, 1);
   }
   
   
   
   /*"�͹��ĵ��"*/
   if(Alarm_Map_Flag[0].bit.b0==0)
   {
   	 if(VB3_OK1==0) /*"Ƿѹ"*/
	 	 {
	 	 	 pdbatterydelay++;
	 	 	 if(pdbatterydelay>=60)
	 	 	 {
	 	 	   pdbatterydelay=0;
	 	 	   Alarm_Map_Flag[0].bit.b0=1;
	 	 	 }
	 	 }
	 	 else
	 	 {
	 	 	 pdbatterydelay=0;
	 	 }
   }
   else
   {
   	 if(VB3_OK1==1) /*"��Ƿѹ"*/
	 	 {
	 	 	 pdbatterydelay++;
	 	 	 if(pdbatterydelay>=60)
	 	 	 {
	 	 	  pdbatterydelay=0;
	 	 	  Alarm_Map_Flag[0].bit.b0=0;
	 	 	 }
	 	 }
	 	 else
	 	 {
	 	 	 pdbatterydelay=0;
	 	 }
   }

if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x01)
{
   if((!EventStatus_flag.bit.LowPower_Battery_Volt_low)&&(Alarm_Map_Flag[0].bit.b0)&&Meter_Parameter.parameter1.EventReportMode.bit.LowPower_Battery_Volt_low)/*"�����ϱ�����͹��ĵ��Ƿѹ"*/
   {
     EventReportState_Expand(3, 6, 0);  
     if(Event_Report_Status_Times.LowPower_Battery_Volt_low_times != 255)
     {
        Event_Report_Status_Times.LowPower_Battery_Volt_low_times = 255; 
        Save_EventReportTimes(LOWPOWER_BATTERY_VOLT_LOW_TIMES_ROM,(unsigned char *)&Event_Report_Status_Times.LowPower_Battery_Volt_low_times);
     } 	
   }
}
   if(Alarm_Map_Flag[0].bit.b0==0)
   {
   	 EventReportState_Expand(3, 6, 1);
   }
   
   ClockBatteryDisplayBattery_Event();
}
		

/*-----------------------------------------------------------------------------*/
void	Set_or_Clear_LCD_Alarm_Flag(void)		/*"��LCD�ϱ�����־"*/
		{
			if(((LCD_LED_Speaker_Terminal_ALARM_Condition_Test(1)==1)&&(((Meter_Parameter.parameter1.MeterMode[3].byte)&0x02)!=0))
			    ||(Meter_States.Meter_Flag.bit.Energymodule_Err))   /*"����ģ���������������"*/
			{	
				Show_flash_falg.bit.Bell=1;				/*"LCD �ı�����־��˸"*/
			 // if(BACK_LIGHT_ON==0)
			 /// {
			///  	Light_Back_Up_Flag=0x11;
         /// Light_Back_Led();
			///  }
			BackLight_Ctrl(CONTINUOUS_LIGHT_MODE,0,0,EVENT);///king chen add 130304
			}
			else
			{
				 Show_flash_falg.bit.Bell=0;
				 
				/// if(Light_Back_Up_Flag==0x11)
				///   Light_Back_Up_Flag=0xaa;
				BackLight_Ctrl(CLOSE_MODE,0,0,EVENT);///king chen add 130304
			}
			if(O1ther_Meter_Parameter.WorkRoomState)												/*"J1�̽�"*/
				{
					if(Event_Power_Net_Flag.bit.OpenCoverEvent == 1 ||
						 Event_Power_Net_Flag.bit.OpenBoxEvent == 1)
						{
							Show_flash_falg.bit.Home=1;			/*"���Ǳ�־"*/
							//Show_flag.bit.Home=0;
						}
					else
						{
							Show_flash_falg.bit.Home=0;
							//Show_flag.bit.Home=1;
						}					
				}
				
			else
			//	{
					//if(Show_flag.bit.North==0)
					  Show_flash_falg.bit.Home=0;			/*"���Ǳ�־"*/
			//		  Show_flag.bit.Home=0;
			//	}
		}

	
/*------------------ Display LED_Pannel Program ----------------------------*/
///king chen mark 121214
///void	Flash_Led_Pannel(void)	//flash P+,P-,Q+,Q-,Alarm,Battery,Phase_Break,Current_Lose on LED_PANNEL
///{
//	/*----------- Flash ALARM ---------------------*/
//	/*"��ǰ״̬�뱨��ģʽ��ƥ��,0:���������1:�������"*/
///	if ((pay_Led_Alarm())	//payment
///	||((LCD_LED_Speaker_Terminal_ALARM_Condition_Test(2)==2)&&(((Meter_Parameter.parameter1.MeterMode[3].byte)&0x02)!=0))
///	||(Meter_States.Meter_Flag.bit.Energymodule_Err))   /*"����ģ���������������"*/	
///	{	///*"����ⱨ��"*/����flash ALARM
///		LED_ALARM=1;
///	}
///	else	//turn off ALARM
///		LED_ALARM=0;
///}

unsigned char	LCD_LED_Speaker_Terminal_ALARM_Condition_Test(unsigned char callcondition)	/*"��ǰ״̬�뱨��ģʽ��ƥ��,0:�����������1:�������"*/
{

			unsigned char	meter_type_331,meter_type_TF;
      union LCD_LED_Speaker_Terminal_ALARM_FLAG     alarm_current_status;
			
			if((V_REGION==0)||(V_REGION==3))
				meter_type_331=1;				/*"331��"*/
			else
				meter_type_331=0;				/*"341��"*/				
			if(((Meter_Parameter.parameter1.MeterMode[0].byte)&0x40)!=0)			/*"ģʽ��1�������ģʽ��"*/
				meter_type_TF=1;				/*"�������"*/
			else
				meter_type_TF=0;				/*"˫�����"*/
				
			alarm_current_status.Alarm_Flag=0;

           alarm_current_status.bit.ClockBatteryEvent=Alarm_Map_Flag[0].bit.b2;/*"ʱ�ӵ�ع���"*/
           alarm_current_status.bit.DisplayBatteryEvent=Alarm_Map_Flag[0].bit.b0;/*"�͹��ĵ�ع���"*/
	        alarm_current_status.bit.RunClockError=Meter_States.Meter_Flag.bit.Rtc_Err1;/*"����ʱ����"*/
           alarm_current_status.bit.Eeprom_Err=Meter_States.Meter_Flag.bit.Eeprom_Err1;/*"�ڿ�����"*/
           alarm_current_status.bit.OpenBoxEvent=Event_Power_Net_Flag.bit.OpenBoxEvent;
           alarm_current_status.bit.OpenCoverEvent=Event_Power_Net_Flag.bit.OpenCoverEvent;
           alarm_current_status.bit.OverFactor=(0 !=((Event_Power_Net_Flag.byte[5] & (0x02))  | (Event_Power_Net_Flag.byte[4] & (0x20|0x40|0x80))));//(Event_Power_Net_Flag.bit.OverFactor|Event_Power_Net_Flag.bit.OverFactor_A|Event_Power_Net_Flag.bit.OverFactor_B|Event_Power_Net_Flag.bit.OverFactor_C);
	    alarm_current_status.bit.VoltageReserve=Event_Power_Net_Flag.bit.VoltageReserve;
           alarm_current_status.bit.CurrReverse=Event_Power_Net_Flag.bit.CurrReverse;
           if(meter_type_TF)
           {
              if((eventstatusinfo.bit.powertreverse)||(Event_Power_Net_Flag.byte[2] & (0x01|0x02|0x04)))//(Event_Power_Net_Flag.bit.PowerReverse_A)||(Event_Power_Net_Flag.bit.PowerReverse_B)||(Event_Power_Net_Flag.bit.PowerReverse_C))
                alarm_current_status.bit.PowerReverse=1;	
           }  
           alarm_current_status.bit.OverPaADemand=Event_Power_Net_Flag.bit.OverPaADemand;
           alarm_current_status.bit.OverNeADemand=Event_Power_Net_Flag.bit.OverNeADemand;
           alarm_current_status.bit.LostVoltage=(0 !=(Event_Power_Net_Flag.byte[0] & (0x01|0x02|0x04)));//((Event_Power_Net_Flag.bit.LostVoltage_A)|| (Event_Power_Net_Flag.bit.LostVoltage_B)|| (Event_Power_Net_Flag.bit.LostVoltage_C));
           alarm_current_status.bit.BreakPhase= (0!=(Event_Power_Net_Flag.byte[1] & (0x01|0x02|0x04)));//((Event_Power_Net_Flag.bit.BreakPhase_A)||(Event_Power_Net_Flag.bit.BreakPhase_B)|| (Event_Power_Net_Flag.bit.BreakPhase_C));
           alarm_current_status.bit.OverVoltage=(0!= (Event_Power_Net_Flag.byte[2] & (0x08|0x10|0x20)));//((Event_Power_Net_Flag.bit.OverVoltage_A)||(Event_Power_Net_Flag.bit.OverVoltage_B)|| (Event_Power_Net_Flag.bit.OverVoltage_C)) ;     
           alarm_current_status.bit.VoltageDown=(0!=(Event_Power_Net_Flag.byte[1] & (0x08|0x10|0x20)));//((Event_Power_Net_Flag.bit.VoltageDown_A)||(Event_Power_Net_Flag.bit.VoltageDown_B)|| (Event_Power_Net_Flag.bit.VoltageDown_C));

           alarm_current_status.bit.VoltImBalance=Event_Power_Net_Flag.bit.VoltImBalanceEvent;
           alarm_current_status.bit.CurrImBalance=Event_Power_Net_Flag.bit.CurrImBalanceEvent;
           alarm_current_status.bit.CurrFarImBalance=Event_Power_Net_Flag.bit.CurrFarImB;
           alarm_current_status.bit.LostCurrent=(0!=(Event_Power_Net_Flag.byte[0] & (0x20|0x40|0x80)));//((Event_Power_Net_Flag.bit.LostCurrent_A)||(Event_Power_Net_Flag.bit.LostCurrent_B)||(Event_Power_Net_Flag.bit.LostCurrent_C));
           alarm_current_status.bit.OverCurrent=(0!=(Event_Power_Net_Flag.byte[3] & (0x01|0x02|0x04)));//((Event_Power_Net_Flag.bit.OverCurrent_A)||(Event_Power_Net_Flag.bit.OverCurrent_B)||(Event_Power_Net_Flag.bit.OverCurrent_C));
           alarm_current_status.bit.FailCurrent=(0!=(Event_Power_Net_Flag.byte[5] & (0x08|0x10|0x20)));//((Event_Power_Net_Flag.bit.FailCurrent_A)||(Event_Power_Net_Flag.bit.FailCurrent_B)||(Event_Power_Net_Flag.bit.FailCurrent_C));
           alarm_current_status.bit.UpLoad=(0!=(Event_Power_Net_Flag.byte[3] & (0x08|0x10|0x20)));//((Event_Power_Net_Flag.bit.UpLoad_A)||(Event_Power_Net_Flag.bit.UpLoad_B)||(Event_Power_Net_Flag.bit.UpLoad_C));
           alarm_current_status.bit.Programme=Event_Power_Net_Flag.bit.ProgrammeEvent;
           
           alarm_current_status.bit.OverReDemand=(0!=(Event_Power_Net_Flag.byte[7] & (0x08|0x10|0x20 |0x40)));//(Event_Power_Net_Flag.bit.Over1RDemand|Event_Power_Net_Flag.bit.Over2RDemand|Event_Power_Net_Flag.bit.Over3RDemand|Event_Power_Net_Flag.bit.Over4RDemand);
           alarm_current_status.bit.ConstMagnet=Event_Power_Net_Flag.bit.ConstantMagnet;
           alarm_current_status.bit.EsamErr=ESAM_ERR_DEFINE;
     	   alarm_current_status.bit.CtrCircleErr=SWITCH_ERR_CLUE_DEFINE || Wai_SWITCH_ERR_DEFINE;

          TempSoundAlarmEventFlag.Alarm_Flag=alarm_current_status.Alarm_Flag;
          
          if(callcondition==4)
          {
            terminalalarmc[2].Alarm_Flag=alarm_current_status.Alarm_Flag;
            terminalalarmc[2].bit.OverPowerAlarm=Event_Power_Net_Flag.bit.OverPowerAlarm;
          }  
			
			if((callcondition==1)&&(alarm_current_status.Alarm_Flag&(Meter_Parameter.parameter1.MeterMode_Alarm_Flag.Alarm_Flag)))            /*"   Һ������   "*/
				return 1;
          if((callcondition==2)&&(alarm_current_status.Alarm_Flag&(Meter_Parameter.parameter1.MeterMode_LedAlarm_Flag.Alarm_Flag)))        /*"   �ƹⱨ��   "*/
				return 2;
          if((callcondition==3)&&(alarm_current_status.Alarm_Flag&(Meter_Parameter.parameter1.MeterMode_SpeakerAlarm_Flag.Alarm_Flag))) /*"  �� ����   "*/
				return 3;
      //    if((callcondition==4)&&(alarm_current_status.Alarm_Flag&(Meter_Parameter.parameter1.MeterMode_TerminalAlarm_Flag.Alarm_Flag))) /*"   �������ӱ���   "*/
			//	return 4;
			//else
				return 0;
}
		
/*--------------------------------------------------------------------------------*/
#define	Four_In_1_EN	p3_5

void	Output_On_3_In_1_Terminal_Set(unsigned char Call_Condition)	
		/*"�ĺ�һ�������������λ","�˺���Ӧ����������µ��ã������л�(Call_Condition=1)���������ڵ�(Call_Condition=2)"*/
		/*"�ϵ���޸��ĺ�һ��������ģʽ��(Call_Condition=0)"*/
		/*"Call_Condition=3:Ƿ�ѱ�����Call_Condition=4:ȡ��Ƿ�ѱ���"*/
		/*"Call_Condition=5:���ر�����Call_Condition=6:ȡ�����ر���"*/
		/*"Call_Condition=7:�������״̬����"*/
		{
	if(Call_Condition<3)
	{


		 	switch(O1ther_Meter_Parameter.OutputModel)
			{
				case 1:/*"��������"*/
					DEMAND_TIME_SW_DIR = 1;//OUTPUT
					SECOND_EN_DIR = 1;     //OUTPUT
					SECOND_EN = 1;         //HIGH
					if(Call_Condition==2)
					{
						DEMAND_TIME_SW = 0;
						//Alarm_Demand_Set_Starting_Time=GetNowTime();/*"�����������ӿ�ʼ��λ��ʱ��"*/
						tabsr|=0x20;	
					}
					else
					{
						DEMAND_TIME_SW = 1;
					}
				break;
				case 2:/*"ʱ��Ͷ��"*/
					DEMAND_TIME_SW_DIR = 1;//OUTPUT
					SECOND_EN_DIR = 1;     //OUTPUT
					SECOND_EN = 1;         //HIGH
					if(Call_Condition==1)
					{
						DEMAND_TIME_SW = 0;		//payment
						//Alarm_Demand_Set_Starting_Time=GetNowTime();/*"�����������ӿ�ʼ��λ��ʱ��"*/						
						tabsr|=0x20;	
					}
					else
					{
						DEMAND_TIME_SW = 1;
					}
				break;
				
				case 0:/*"������"*/
					DEMAND_TIME_SW_DIR = 0;//input
					DEMAND_TIME_SW = 0;    //low
					SECOND_EN_DIR = 1;     //OUTPUT
					SECOND_EN = 0;     //LOW
				break;
			}   	
//		}
//		else
//		{
//			switch(Call_Condition)
//			{
//			
//				case 1:    /*"ʱ��Ͷ��"*/                   	
//					TIME_SW=0;
//					Alarm_Terminal_Set_Starting_Time=GetNowTime();/*"�����������ӿ�ʼ��λ��ʱ��"*/
//				break;
//				case 2:  /*"��������"*/
//					DEMAND=0;
//					Alarm_Demand_Set_Starting_Time=GetNowTime();/*"�����������ӿ�ʼ��λ��ʱ��"*/
//				break;
//				case 0: /*"������"*/               	
//					SECOND_EN=0;
//				break;
//			}
//		}
	}
	else
	{/*"�������"*/
		
		LCD_LED_Speaker_Terminal_ALARM_Condition_Test(4);
		SoundAlarmEventCheck(1);
		
		if(Meter_States.Meter_Status4.bit.OweFee_Alarm && Meter_Parameter.parameter1.MeterMode[1].bit.b5)
		{
			
		}
		else
		{
			if(terminalalarmc[0].bit.OverPowerAlarm && Meter_Parameter.parameter1.MeterMode[1].bit.b4)
			{
				Relay_Alarm_SWitch_Flag[0][0] |= 0x01;
			}
			else
			{
				Relay_Alarm_SWitch_Flag[0][0] &= 0xFE;
				if(((Meter_Parameter.parameter1.MeterMode[3].byte)&0x01))	/*"ģʽ��4�������ģʽ��:����������������"*/
				{
					if((((Meter_Parameter.parameter1.MeterMode_TerminalAlarm_Flag.Alarm_Flag)&(0x7fffffff)
					&(terminalalarmc[0].Alarm_Flag))!=0)	/*"��ǰ״̬�뱨��ģʽ��ƥ��,0:�����������1:�������"*/
	    		||(Meter_States.Meter_Flag.bit.Energymodule_Err))   /*"����ģ���������������"*/
						Relay_Alarm_SWitch_Flag[0][0] |= 0x02; 
						//ALARM=1;
					else    
						Relay_Alarm_SWitch_Flag[0][0] &= 0xFD;
						//ALARM=0;		
				}
				else    
					Relay_Alarm_SWitch_Flag[0][0] &= 0xFD;
			}
		}
	}
}

/*--------------------------------------------------------------------------------*/
/*"Ԥ���ѱ����������ʱ������������״̬��������"*/		
#if 0
void	Prepay_Overpower_Alarm(unsigned char Call_Condition)
		{
			
						if(((Meter_Parameter.parameter1.MeterMode[1].byte)&0x10)!=0)	/*"ģʽ��2�������ģʽ��:ѡ�񸺺ɿ��ƹ���"*/
						{
							SECOND_EN=1;				/*"p36�ø�ѡ��"��������/ʱ���л�/����"�������"*/
							Four_In_1_EN=1;				/*"4��1���ʹ��"*/

							//TimeOrDemandCycle=0;
							if(Event_Power_Net_Flag.bit.OverPowerAlarm)
								ALARM=1;		/*"p37�ø�������ɿ��Ʊ���"*/
							else
								ALARM=0;		/*"p37�õ�ȡ�����ɿ��Ʊ���"*/
						}
			
						else
							{
								if(((Meter_Parameter.parameter1.MeterMode[3].byte)&0x01))	/*"ģʽ��4�������ģʽ��:����������������"*/
									{
										SECOND_EN=1;				/*"p36�ø�ѡ��"��������/ʱ���л�/����"�������"*/
										Four_In_1_EN=1;				/*"4��1���ʹ��"*/
										//TimeOrDemandCycle=0;
										if((LCD_LED_Speaker_Terminal_ALARM_Condition_Test(4)==4)	/*"��ǰ״̬�뱨��ģʽ��ƥ��,0:�����������1:�������"*/
										    ||(Meter_States.Meter_Flag.bit.Energymodule_Err))   /*"����ģ���������������"*/
											ALARM=1;		/*"p37�ø��������"*/
										else
											ALARM=0;		/*"p37��ȡ������"*/										
									}
							}
		}
#endif
			



///////////
#define Voltage_Ratio  85
#pragma SECTION rom UserROMData
const unsigned long Voltage_table[4]={1000000L,2200000L,577000L,3800000L};

void Check_Voltage_Threshold(void)	/*"ֻ���������е���ߵ�ѹ����75��Unʱ�ŵ�������"*/
{
		    unsigned long Voltage_Parameter,Voltage_Max;		    
		    Voltage_Parameter=Voltage_table[V_REGION];
		    Voltage_Max=Get_Max_Value(Volt[0],Volt[1],Volt[2]);		    
		    if((Voltage_Max*100L)>=(Voltage_Parameter*Voltage_Ratio) ||
		    	(((Volt[0]*100l)>=(Voltage_Parameter*80)) 
		    && ((Volt[2]*100l)>=(Voltage_Parameter*80))
		    && (((Volt[1]*100l)>=(Voltage_Parameter*80)) || ((V_REGION==0)||(V_REGION==3)))))	
		   {
		    	  VoltageGreaterThanThreshold_Flag=1;                          /*"�������ѹ�Ƿ�����ż��ı�־"*/
		    	  ///closebacklight_flag=0x00;///king chen add 130228
			}
		    else
		    {
		    	  VoltageGreaterThanThreshold_Flag=0; 
		    	  ///closebacklight_flag|=0xf0; ///king chen debug
		    }
      if((Voltage_Max*100L)>=(Voltage_Parameter*60l))	
        VoltageGreaterThanCritical_Flag=1;
      else
        VoltageGreaterThanCritical_Flag=0;  //add by pc 081227            


	if((Voltage_Max*100L)>=(Voltage_Parameter*79L))		//payment 	/*"�������ѹ�Ƿ����ṩIC���ȶ���Դ"*/
        VoltageGreaterThanICcard_Flag=1;
      else
        VoltageGreaterThanICcard_Flag=0;
}


//------  Sound Alarm  ------//
void SoundAlarmEventCheck(unsigned char checkkind)
{
  unsigned char i;
  unsigned long *tempunlpointer[3];
  unsigned long value;
  
  value=1;
  
  switch(checkkind)
  {
  	case 0x01:
  	  tempunlpointer[0]=&(terminalalarmc[0].Alarm_Flag);
  	  tempunlpointer[1]=&(terminalalarmc[1].Alarm_Flag);
  	  tempunlpointer[2]=&(terminalalarmc[2].Alarm_Flag);
  	break;
  	default:
  	  tempunlpointer[0]=&(SoundAlarmFlag.Alarm_Flag);
  	  tempunlpointer[1]=&(SoundAlarmEventFlag.Alarm_Flag);
  	  tempunlpointer[2]=&(TempSoundAlarmEventFlag.Alarm_Flag);
  	break;
  }
  
	for(i=0;i<32;i++)
	{
	    if((((*tempunlpointer[1])&value)==0)&& (((*tempunlpointer[2])&value)!=0) )
	    {
	        (*tempunlpointer[1])|=value;//set 1
	        (*tempunlpointer[0])|=value;//set 1
	    }
	    if((((*tempunlpointer[1])&value)!=0) && (((*tempunlpointer[2])&value)==0))
	    {
	       (*tempunlpointer[1])&=~value;//set 0
	       (*tempunlpointer[0])&=~value;//set 0
	    }
      value<<=1;
	}	
}

void SoundAlarmEndCheck(void){
	
	if ((SoundAlarmFlag.Alarm_Flag!=0) || Buzzer_Alarm_Control.byte ||(terminalalarmc[0].Alarm_Flag!=0))
	{
		if(((KEY1)==0)||((KEY3)==0)){
			Delay(5);
			if(((KEY1)==0)||((KEY3)==0))
			{
				SoundAlarmFlag.Alarm_Flag=0;
				Buzzer_Alarm_Control.byte=0;	//payment
				terminalalarmc[0].Alarm_Flag=0;
			}
		}
	}
	
}

void SoundAlarmInit(void){
	
	SoundAlarmFlag.Alarm_Flag=0;
	SoundAlarmEventFlag.Alarm_Flag=0;
	TempSoundAlarmEventFlag.Alarm_Flag=0;
	terminalalarmc[0].Alarm_Flag=0;
	terminalalarmc[1].Alarm_Flag=0;
	terminalalarmc[2].Alarm_Flag=0;
	
}
//------  Sound Alarm  ------//
