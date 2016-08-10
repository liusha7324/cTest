/*"�����������for DL645-2007 v2.0"*/
/*"creat by trend 2008-10-28 11:23:12"*/


#include "sfr64a.h"
#include "defdata.h"
#include "MB_BASE_FUN.h"
#include "EEPROM.h"
#include "I2C_operation.h"
#include "RAM.h"
#include "Comm.h"
#include "att7022_operation.h"
#include "Demand.h"
#include "eventnew.h"
#include "645_2007.h"
#include "Measure_Interface.h" 
#include "Multi.h"


unsigned char DemandputoutNum=0;
unsigned char DemandOutPutflagdata=0;

struct DEMAND_DATA_NEW Demand_Data_New;
struct DEMAND_AREA Demand_Sum;
unsigned long  Last_Average_Value[MAX_DEMAND_TYPE][MAXTRIFF];/*"���������洢�ռ�"*/


unsigned char demand_start;	
unsigned char demand_init;
                                               																		/*"0 ���й�"*/
																								/*"1 ���й�"*/
																								/*"2 1�����޹�"*/
																								/*"3 2�����޹�"*/
																								/*"4 3�����޹�"*/
																								/*"5 4�����޹�"*/ 
																								/*"6 ����޹�1"*/
																								/*"7 ����޹�2"*/
signed long	Current_Demand[2];								/*"��ǰ�����洢�ռ�"*/
																								/*"0 �й�"*/
																								/*"1 �޹�"*/
//struct DEMAND_CONTROL GDemandControl; //control information for demand
//
//struct DEMAND_DATA DemandData;


	


void Demand_Last_Averge_Value(unsigned char mode,unsigned char Traff_ID);
void Next_Period(unsigned char mode);
void Demand_New_Main(void);
void Demand_New_Init(void);
void DemandCompare(unsigned char rTriffNo);
int ClearDemandArea(unsigned char mode);
unsigned long Demand_Energy_Delta(unsigned char head,unsigned char type,unsigned long *mantissa);
unsigned long Demand_time_Delta(unsigned char head);
void Get_Current_Demand(void);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*unsigned char Get_Demand_Data_New_Cs(void)
{
	unsigned int i;
	unsigned char sum,*p;
	p=(unsigned char *)&Demand_Data_New;
	sum=0;
	for(i=0;i<sizeof(struct DEMAND_DATA_NEW)-1;i++)
	{
		sum+=*(p+i);
	}
	return sum;
}
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"����ÿ���ӵĵ���ֵ"*/
void Save_Min_Energy(void)
{
	unsigned char i;
	/*"βָ���ƶ�"*/
	Demand_Data_New.Rail[0]++;
	Demand_Data_New.Rail[0]%=MAX_DEMAND_AREA;
	Demand_Data_New.Rail[1]=Demand_Data_New.Rail[0];
	
	memcpy((unsigned char *)&Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]],(unsigned char *)&Demand_Sum,sizeof(struct DEMAND_AREA));
//	Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_l[0]=Powerdown_Save_Data.Rail_Plus_Active[0];
//	Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_h[0]=This_Month_Data.Energy_Record.Plus_Active[0];
//	Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_l[1]=Powerdown_Save_Data.Rail_Nega_Active[0];
//	Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_h[1]=This_Month_Data.Energy_Record.Nega_Active[0];
//	for(i=2;i<6;i++)
//	{	
//		Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_l[i]=Powerdown_Save_Data.Rail_Quad_Reactive[0][i-2];
//		Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].energy_h[i]=This_Month_Data.Energy_Record.Quad_Reactive[i-2][0];
//	}	
//	Demand_Data_New.Demand_Area[Demand_Data_New.Rail[0]].time=GetNowTime();
	//Demand_Data_New.CheckSum=Get_Demand_Data_New_Cs();
	
	
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�������ÿ���ӵĵ���ֵ�Ŀռ�"*/
unsigned char Clear_Min_Energy(unsigned char min)
{
	unsigned char i,j;
	if(min>60) return 0xff;
	for(j=0;j<min;j++)
	{
		memcpy((unsigned char *)&Demand_Data_New.Demand_Area[j],(unsigned char *)&Demand_Sum,sizeof(struct DEMAND_AREA));
		
	}
	//Demand_Data_New.CheckSum=Get_Demand_Data_New_Cs();
	
	return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Demand_New_Init(void)
{
	unsigned char i,j,nMinute;
	BCD2Byte(softdate.Min, &nMinute);
	for(i=0;i<6;i++)	
	{
		Demand_Sum.energy_l[i]=0l;
		Demand_Sum.energy_h[i]=0l;
	}
	Demand_Sum.time=0l;
	Clear_Min_Energy(MAX_DEMAND_AREA);	
		
	Demand_Data_New.Head[0]=nMinute;	
	Demand_Data_New.Head[1]=nMinute;
	
	Demand_Data_New.Rail[0]=nMinute;
	Demand_Data_New.Rail[1]=nMinute;
	
	//Demand_Data_New.CheckSum=Get_Demand_Data_New_Cs();
	if(Meter_Parameter.parameter1.DemandSkipPeriod!=Meter_Parameter.parameter1.DemandPeriod)
	/*"����"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	else
	/*"����"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
		
	for(i=0;i<MAX_DEMAND_TYPE;i++)
	 for(j=0;j<MAXTRIFF;j++)
		Last_Average_Value[i][j]=0L;
	Get_Current_Demand();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned long Demand_Div(unsigned long energy,unsigned long mantissa,unsigned long time)
{
	unsigned long temp,temp1,ret;
	float time_div = 0.0;
	
	if(time==0) return 0;/*"������ֳ�0�������������"*/
		
if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"����������С��15����ʱ�����ù����ۼƼ��㵱ǰ������ʽ"*/
	{
		
	  temp=energy/time;
	  temp1=energy%time;

	  ret=temp*1000l+(temp1*1000l+mantissa)/time;
	}
	else/*"���������ڴ��ڵ���15����ʱ�����õ����ۼƼ��㵱ǰ������ʽ���������ʾֵ���"*/
	{
			time_div = 3600.0 / time;
	    ret=energy * time_div;
	}
	
	return ret;
}

	
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Demand_New_Main(void)
{/*"������������������ѭ��ÿ���ӵ���"*/
	unsigned long Delta_num;
	unsigned char Head,temp,mode;	
	
	if(Meter_Parameter.parameter1.DemandSkipPeriod!=Meter_Parameter.parameter1.DemandPeriod)
	/*"����"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	else
	/*"����"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	for(mode=0;mode<2;mode++)
	{
		/*"ʱ��ͬ������"*/
		if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==0)
		{	/*"ʱ��ͬ��"*/
			temp=Demand_Data_New.Head[mode]%Meter_Parameter.parameter1.DemandSkipPeriod;
			if(temp==0)
				Head=Demand_Data_New.Head[mode];
			else
				Head=Demand_Data_New.Head[mode]-temp;
		}
		else
		{/*"����ͬ��������Ҫ������"*/
			Head=Demand_Data_New.Head[mode];
		}
		if(Demand_Data_New.Rail[mode]>=Head)
			Delta_num=Demand_Data_New.Rail[mode]-Head;
		else
			Delta_num=Demand_Data_New.Rail[mode]+(MAX_DEMAND_AREA-Head);
		Delta_num++;/*"�ȼ��㣬�󱣴�����Ļ�����������һ��"*/	
		if(Delta_num==Meter_Parameter.parameter1.DemandPeriod)
		{
			Next_Period(mode);
			if(mode==0) Get_Current_Demand();
			/*"��������ź�,�����ǰ��������ڳ�"*/
			if(mode==0)
				Output_On_3_In_1_Terminal_Set(2);  
		}
		else
		{/*"��������ź�,�����ǰ�����ʱ���"*/
			if((Meter_Parameter.parameter1.MeterMode[2].bit.b4==0)&&(mode==0))
			{
				if((Delta_num%Meter_Parameter.parameter1.DemandSkipPeriod)==0)
					Output_On_3_In_1_Terminal_Set(2);  
			}
		}
	}
	Save_Min_Energy();

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�����л�����ʱ�����µ���������"*/
void Demand_Triff_Change(void)
{
	unsigned long Delta_num;
	unsigned char Head,temp;	
	/*"���ϸ������������д���"*/
	/*"ʱ��ͬ������"*/
		temp=Demand_Data_New.Head[1]%Meter_Parameter.parameter1.DemandSkipPeriod;
		if(temp==0)
			Head=Demand_Data_New.Head[1];
		else
			Head=Demand_Data_New.Head[1]-temp;
		
		if(Demand_Data_New.Rail[1]>Head)
			Delta_num=Demand_Data_New.Rail[1]-Head;
		else
			Delta_num=Demand_Data_New.Rail[1]+(MAX_DEMAND_AREA-Head);
			
		if(Delta_num==Meter_Parameter.parameter1.DemandPeriod)
		{
			Next_Period(1);
		}
	/*"��ʱͷָ�����ָ��ǰ�ռ�"*/		
	Demand_Data_New.Head[1]=Demand_Data_New.Rail[1];
	
	
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�µ��������ڣ����Զ����ã�Ҳ�����ֶ�����"*/
/*"Mode=0 �� mode=1��ʱ"*/
void Next_Period(unsigned char mode)
{
	unsigned char temp;
	//////////////////////////////////////////////////////////////////
	/*"��ǰ��������"*/
	Demand_Last_Averge_Value(mode,TRAFF_RATE*mode);/*"��"*/	
	////////////////////////////////////////////////////////////////////
	/*"�Ƚ��������"*/
	DemandCompare(TRAFF_RATE*mode);
	///////////////////////////////////////////////////////////////
	/*"ͷָ���ƶ�"*/

	//modified by ganjp 20111025
	temp = 0;
	if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==0)
	{
	temp=Demand_Data_New.Head[mode]%Meter_Parameter.parameter1.DemandSkipPeriod;
	}	
	
	Demand_Data_New.Head[mode]+=(Meter_Parameter.parameter1.DemandSkipPeriod-temp);
	
	Demand_Data_New.Head[mode]%=MAX_DEMAND_AREA;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"��ǰ�������� mode=0 ���������� mode=1 ���㵱ǰ��ʱ����"*/	
void Demand_Last_Averge_Value(unsigned char mode,unsigned char Traff_ID)
{
	unsigned long Delta_Energy,Delta_Energy_Mantissa,Delta_time,Delta_num,Energy_Temp[4];
	unsigned char i,temp;	
		if(Demand_Data_New.Rail[mode]>=Demand_Data_New.Head[mode])
			Delta_num=Demand_Data_New.Rail[mode]-Demand_Data_New.Head[mode];
		else
			Delta_num=Demand_Data_New.Rail[mode]+(MAX_DEMAND_AREA-Demand_Data_New.Head[mode]);
		Delta_num++;/*"�ȼ��㣬�󱣴�����Ļ�����������һ��"*/	
		
		Delta_time=Demand_time_Delta(Demand_Data_New.Head[mode]);			
		if(Delta_num!=Meter_Parameter.parameter1.DemandPeriod)
		{/*"����������������"*/
			Delta_time=Meter_Parameter.parameter1.DemandPeriod*60l;	
		}
		if(ABS(Delta_time-Meter_Parameter.parameter1.DemandPeriod*60l)>5)
		{	
			/*"������ֵ����Χ20%"*/
			Delta_time=Meter_Parameter.parameter1.DemandPeriod*60l;	
		}
		
		Delta_Energy_Mantissa = 0;
		for(i=0;i<6;i++)
		{
			
			Delta_Energy=Demand_Energy_Delta(Demand_Data_New.Head[mode],i,&Delta_Energy_Mantissa);
			if(Meter_Parameter.parameter1.DemandPeriod >= 15)/*"���õ����ۼƼ��㵱ǰ������ʽ�������������ϵ��"*/
			{
				Delta_Energy = Delta_Energy/3600;
			}
			Last_Average_Value[i][Traff_ID*mode]=Demand_Div(Delta_Energy,Delta_Energy_Mantissa,Delta_time);
		}
//		/*"��������޹�������"*/
//		for(i=0;i<4;i++)
//		{
//			Energy_Temp[i]=Demand_Energy_Delta(Demand_Data_New.Head[mode],Demand_Data_New.Rail[mode],i+2);			
//		}
//		Ram_math((unsigned char *)&Energy_Temp[0],(unsigned char *)&Delta_Energy,Meter_Parameter.REActivem_Erengy_1_Mode.byte,SIGNED_LONG,4,4);
//		Last_Average_Value[6][Traff_ID*mode]=Demand_Div(Delta_Energy,Delta_time);
//		Ram_math((unsigned char *)&Energy_Temp[0],(unsigned char *)&Delta_Energy,Meter_Parameter.REActivem_Erengy_2_Mode.byte,SIGNED_LONG,4,4);
//		Last_Average_Value[7][Traff_ID*mode]=Demand_Div(Delta_Energy,Delta_time);
	
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"�����������"*/
void DemandCompare(unsigned char rTriffNo)
{
	unsigned char i,nDemandTime[5];
	unsigned int nAddrDemand,nAddrDemandTime;
	
	for(i=0;i<MAX_DEMAND_TYPE;i++)
	{	
		if(Last_Average_Value[i][rTriffNo]>This_Month_Data.Demand_Record.Value[i][rTriffNo].Demand)
		{/*"�µ�����ֵ��"*/
			This_Month_Data.Demand_Record.Value[i][rTriffNo].Demand=Last_Average_Value[i][rTriffNo];
			memcpy(nDemandTime,(unsigned char *)&softdate.Year,5);
			memcpy(This_Month_Data.Demand_Record.Value[i][rTriffNo].time,nDemandTime,5);
			nAddrDemand = THIS_MONTH_DATA_ROM + sizeof(struct ENERGY_RECORD)
					+ i * MAXTRIFF * 9 + rTriffNo * 9;
			nAddrDemandTime = nAddrDemand+4;
			
			//save demand to FM256
			/*Write_Read_FM24C256(nAddrDemand, (unsigned char *)&Last_Average_Value[i][rTriffNo], 4, 0, 0);
			Write_Read_FM24C256(nAddrDemand, (unsigned char *)&Last_Average_Value[i][rTriffNo], 4, 1, 0);
			
			//save demand time to FM256
			Write_Read_FM24C256(nAddrDemandTime, nDemandTime, 5, 0, 0);
			Write_Read_FM24C256(nAddrDemandTime, nDemandTime, 5, 1, 0);
			*/
			WRLC256(nAddrDemand,(unsigned char *)&Last_Average_Value[i][rTriffNo], 4,0,0);
			
			WRLC256(nAddrDemandTime, nDemandTime, 5, 0,0);
			
			//save history
			nAddrDemand = DEMAND_RECORD_ROM 
				+ sizeof(struct DEMAND_RECORD) * O1ther_Meter_Parameter.Bill_DM_Addr
				+ i * MAXTRIFF * 9 + rTriffNo * 9;
			
			nAddrDemandTime = nAddrDemand+4;		
    			/*
			Write_Read_FM24C256(nAddrDemand, (unsigned char *)&Last_Average_Value[i][rTriffNo], 4, 0, 0);
			Write_Read_FM24C256(nAddrDemand, (unsigned char *)&Last_Average_Value[i][rTriffNo], 4, 1, 0);
    	
			Write_Read_FM24C256(nAddrDemandTime, nDemandTime, 5, 0, 0);
			Write_Read_FM24C256(nAddrDemandTime, nDemandTime, 5, 1, 0);
			*/
			WRLC256(nAddrDemand,(unsigned char *)&Last_Average_Value[i][rTriffNo], 4,0,0);
			
			WRLC256(nAddrDemandTime, nDemandTime, 5, 0,0);
		}	
		
		
	}	
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"������λ"*/
/*"Mode =0 ֻ�嵱ǰ����������ʷ����"*/
/*"Mode =1 ֻ�嵱ǰ����Ҳ����ʷ����"*/
int ClearDemandArea(unsigned char mode)
{
if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==1)/*"����ͬ��"*/
{
demand_init = 0;
demand_start= 0;
}
else                                                                              /*"ʱ��ͬ��"*/
{
Demand_New_Init();
}	

	return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������"*/
/*"��;�������������ڵĵ�����������ȷ��0.000001kwh"*/
/*"������"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
unsigned long Demand_Energy_Delta(unsigned char head,unsigned char type,unsigned long *mantissa)
{
	signed long temp_l,temp_h,temp;
	unsigned long energy_mode_temp = 0;
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"���ù����ۼƼ��㵱ǰ������ʽ���������������ڹ����ۼƲ�ֵ"*/
	{
		temp_l=Demand_Sum.energy_l[type]-Demand_Data_New.Demand_Area[head].energy_l[type];
	  temp_h=Demand_Sum.energy_h[type]-Demand_Data_New.Demand_Area[head].energy_h[type];
	
	  if(temp_h<0)
		  temp=Cal_EnergyLimit()+1+temp_h;
	  else
		  temp=temp_h;
	
	  while (temp_l<0)
	  {
		  temp--;
		  temp_l+=1000l;
	  }
	  *mantissa=temp_l;
	  return temp;
	}
	else/*"���õ����ۼƼ��㵱ǰ������ʽ���������������ڵ����ۼƲ�ֵ���˴�Ϊ��������ϵ��֮ǰ��ֵ"*/
	{
			energy_mode_temp = Demand_Sum.energy_h[type]-Demand_Data_New.Demand_Area[head].energy_h[type];	
	    
	    return energy_mode_temp;
	}
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������"*/
/*"��;�������������ڵ�ʱ���ֵ����ȷ��0.000001kwh"*/
/*"������"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
unsigned long Demand_time_Delta(unsigned char head)
{
	signed long temp;	
	temp=Demand_Sum.time-Demand_Data_New.Demand_Area[head].time;
	if(temp<0)
		temp+=0xffffffff;
	return temp;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������"*/
/*"��;�����㵱ǰ���������ݵ�ǰ���ʷ�������޼��㵱ǰ���й��޹�����"*/
/*"������"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
void Get_Current_Demand(void)
{
	unsigned int quadrant[4];	                   //quadrant value(0~3) of Sum,A,B,C
	Get_Quadrant_Value(quadrant);	                 //get quadrant value(0~3) of Sum,A,B,C
	/*"��ǰ�й�����"*/
	if((quadrant[0]==0)||(quadrant[0]==3))	                               /*"�ۼ���/A/B/C�����й������м䵥Ԫ"*/
		Current_Demand[0]=Last_Average_Value[0][0];
	else         
		Current_Demand[0]=0-Last_Average_Value[1][0];
	
	/*"��ǰ�޹�����"*/
if((quadrant[0]==0)||(quadrant[0]==1))	   
	Current_Demand[1]=Last_Average_Value[2+quadrant[0]][0];
else	
	Current_Demand[1]=0-Last_Average_Value[2+quadrant[0]][0];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Demand_Add_Accumulator(unsigned long *h,unsigned long *l,unsigned long val)
{
	unsigned long temp;
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"���ù����ۼƼ��㵱ǰ������ʽ���ۼ����������ڹ���ֵ"*/
		{
			temp=Cal_EnergyLimit();
			*l+=val;
	    *h+=(*l/1000l);
	    *l%=1000l;
	    *h%=(temp+1);
		}
	else/*"���õ����ۼƼ��㵱ǰ������ʽ���ۼ����������ڵ���ֵ���˴�����Ϊ����ϵ������ǰ��ֵ"*/
		{
			*h+=val;
		}	
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"��������"*/
/*"��;�����չ����ۼ������ۼӿռ�"*/
/*"������"*/
/*"���أ�"*/
/*"���ߣ�trend �汾��1.00"*/
/*"============================================================"*/
void Demand_Accumulator(void)
{
	unsigned int quadrant[4];	                   //quadrant value(0~3) of Sum,A,B,C
	unsigned long ActiveTemp = 0;
	unsigned long ReActiveTemp = 0;
	
	Get_Quadrant_Value(quadrant);	 
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"���ù����ۼƼ��㵱ǰ������ʽ���ۼ����������ڹ���ֵ"*/
	{
			ActiveTemp = Active_power[0];
			ReActiveTemp = Reactive_power[0];
	}
	else/*"���õ����ۼƼ��㵱ǰ������ʽ���ۼ����������ڵ���ֵ���˴�����Ϊ����ϵ������ǰ��ֵ"*/
	{
			ActiveTemp = Active_energy_per_sec;
			ReActiveTemp = Reactive_energy_per_sec;
	}
	if((quadrant[0]==0)||(quadrant[0]==3))
	{/*"���й�"*/
		Demand_Add_Accumulator(&Demand_Sum.energy_h[0],&Demand_Sum.energy_l[0],ActiveTemp);
	}
	else
	{
		/*"���й�"*/
		Demand_Add_Accumulator(&Demand_Sum.energy_h[1],&Demand_Sum.energy_l[1],ActiveTemp);
	}	
	/*"4�����޹�"*/
	Demand_Add_Accumulator(&Demand_Sum.energy_h[2+quadrant[0]],&Demand_Sum.energy_l[2+quadrant[0]],ReActiveTemp); 	
	Demand_Sum.time++;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
