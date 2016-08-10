/*"需量计算程序for DL645-2007 v2.0"*/
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
unsigned long  Last_Average_Value[MAX_DEMAND_TYPE][MAXTRIFF];/*"最终需量存储空间"*/


unsigned char demand_start;	
unsigned char demand_init;
                                               																		/*"0 正有功"*/
																								/*"1 反有功"*/
																								/*"2 1象限无功"*/
																								/*"3 2象限无功"*/
																								/*"4 3象限无功"*/
																								/*"5 4象限无功"*/ 
																								/*"6 组合无功1"*/
																								/*"7 组合无功2"*/
signed long	Current_Demand[2];								/*"当前需量存储空间"*/
																								/*"0 有功"*/
																								/*"1 无功"*/
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
/*"保存每分钟的电量值"*/
void Save_Min_Energy(void)
{
	unsigned char i;
	/*"尾指针移动"*/
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
/*"清楚保存每分钟的电量值的空间"*/
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
	/*"滑差"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	else
	/*"区间"*/
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
	
	if(time==0) return 0;/*"避免出现除0的情况出大需量"*/
		
if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"当需量周期小于15分钟时，采用功率累计计算当前需量方式"*/
	{
		
	  temp=energy/time;
	  temp1=energy%time;

	  ret=temp*1000l+(temp1*1000l+mantissa)/time;
	}
	else/*"当需量周期大于等于15分钟时，采用电量累计计算当前需量方式，提高需量示值误差"*/
	{
			time_div = 3600.0 / time;
	    ret=energy * time_div;
	}
	
	return ret;
}

	
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Demand_New_Main(void)
{/*"需量计算主函数，主循环每分钟调用"*/
	unsigned long Delta_num;
	unsigned char Head,temp,mode;	
	
	if(Meter_Parameter.parameter1.DemandSkipPeriod!=Meter_Parameter.parameter1.DemandPeriod)
	/*"滑差"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	else
	/*"区间"*/
		NEW645Meter_States.Meter_Status1.bit.Demand_Mode=0;
	for(mode=0;mode<2;mode++)
	{
		/*"时钟同步处理"*/
		if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==0)
		{	/*"时钟同步"*/
			temp=Demand_Data_New.Head[mode]%Meter_Parameter.parameter1.DemandSkipPeriod;
			if(temp==0)
				Head=Demand_Data_New.Head[mode];
			else
				Head=Demand_Data_New.Head[mode]-temp;
		}
		else
		{/*"分钟同步，不需要做处理"*/
			Head=Demand_Data_New.Head[mode];
		}
		if(Demand_Data_New.Rail[mode]>=Head)
			Delta_num=Demand_Data_New.Rail[mode]-Head;
		else
			Delta_num=Demand_Data_New.Rail[mode]+(MAX_DEMAND_AREA-Head);
		Delta_num++;/*"先计算，后保存电量的话，步长会少一个"*/	
		if(Delta_num==Meter_Parameter.parameter1.DemandPeriod)
		{
			Next_Period(mode);
			if(mode==0) Get_Current_Demand();
			/*"输出测速信号,这里是按需量周期出"*/
			if(mode==0)
				Output_On_3_In_1_Terminal_Set(2);  
		}
		else
		{/*"输出测速信号,这里是按滑差时间出"*/
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
/*"费率切换，分时启用新的需量周期"*/
void Demand_Triff_Change(void)
{
	unsigned long Delta_num;
	unsigned char Head,temp;	
	/*"对上个费率需量进行处理"*/
	/*"时钟同步处理"*/
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
	/*"分时头指针等于指向当前空间"*/		
	Demand_Data_New.Head[1]=Demand_Data_New.Rail[1];
	
	
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*"新的需量周期，可自动调用，也可以手动调用"*/
/*"Mode=0 总 mode=1分时"*/
void Next_Period(unsigned char mode)
{
	unsigned char temp;
	//////////////////////////////////////////////////////////////////
	/*"当前需量计算"*/
	Demand_Last_Averge_Value(mode,TRAFF_RATE*mode);/*"总"*/	
	////////////////////////////////////////////////////////////////////
	/*"比较最大需量"*/
	DemandCompare(TRAFF_RATE*mode);
	///////////////////////////////////////////////////////////////
	/*"头指针移动"*/

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
/*"当前需量计算 mode=0 计算总需量 mode=1 计算当前分时需量"*/	
void Demand_Last_Averge_Value(unsigned char mode,unsigned char Traff_ID)
{
	unsigned long Delta_Energy,Delta_Energy_Mantissa,Delta_time,Delta_num,Energy_Temp[4];
	unsigned char i,temp;	
		if(Demand_Data_New.Rail[mode]>=Demand_Data_New.Head[mode])
			Delta_num=Demand_Data_New.Rail[mode]-Demand_Data_New.Head[mode];
		else
			Delta_num=Demand_Data_New.Rail[mode]+(MAX_DEMAND_AREA-Demand_Data_New.Head[mode]);
		Delta_num++;/*"先计算，后保存电量的话，步长会少一个"*/	
		
		Delta_time=Demand_time_Delta(Demand_Data_New.Head[mode]);			
		if(Delta_num!=Meter_Parameter.parameter1.DemandPeriod)
		{/*"不完整的需量周期"*/
			Delta_time=Meter_Parameter.parameter1.DemandPeriod*60l;	
		}
		if(ABS(Delta_time-Meter_Parameter.parameter1.DemandPeriod*60l)>5)
		{	
			/*"次数差值超范围20%"*/
			Delta_time=Meter_Parameter.parameter1.DemandPeriod*60l;	
		}
		
		Delta_Energy_Mantissa = 0;
		for(i=0;i<6;i++)
		{
			
			Delta_Energy=Demand_Energy_Delta(Demand_Data_New.Head[mode],i,&Delta_Energy_Mantissa);
			if(Meter_Parameter.parameter1.DemandPeriod >= 15)/*"采用电量累计计算当前需量方式，需除电量换算系数"*/
			{
				Delta_Energy = Delta_Energy/3600;
			}
			Last_Average_Value[i][Traff_ID*mode]=Demand_Div(Delta_Energy,Delta_Energy_Mantissa,Delta_time);
		}
//		/*"计算组合无功的需量"*/
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
/*"最大需量计算"*/
void DemandCompare(unsigned char rTriffNo)
{
	unsigned char i,nDemandTime[5];
	unsigned int nAddrDemand,nAddrDemandTime;
	
	for(i=0;i<MAX_DEMAND_TYPE;i++)
	{	
		if(Last_Average_Value[i][rTriffNo]>This_Month_Data.Demand_Record.Value[i][rTriffNo].Demand)
		{/*"新的需量值大"*/
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
/*"需量复位"*/
/*"Mode =0 只清当前需量不清历史需量"*/
/*"Mode =1 只清当前需量也清历史需量"*/
int ClearDemandArea(unsigned char mode)
{
if(Meter_Parameter.parameter1.MeterMode[0].bit.b7==1)/*"分钟同步"*/
{
demand_init = 0;
demand_start= 0;
}
else                                                                              /*"时钟同步"*/
{
Demand_New_Init();
}	

	return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"函数名："*/
/*"用途：计算需量周期的电量增量，精确到0.000001kwh"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
unsigned long Demand_Energy_Delta(unsigned char head,unsigned char type,unsigned long *mantissa)
{
	signed long temp_l,temp_h,temp;
	unsigned long energy_mode_temp = 0;
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"采用功率累计计算当前需量方式，计算需量周期内功率累计差值"*/
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
	else/*"采用电量累计计算当前需量方式，计算需量周期内电量累计差值，此处为电量换算系数之前的值"*/
	{
			energy_mode_temp = Demand_Sum.energy_h[type]-Demand_Data_New.Demand_Area[head].energy_h[type];	
	    
	    return energy_mode_temp;
	}
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"函数名："*/
/*"用途：计算需量周期的时间差值，精确到0.000001kwh"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
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
/*"函数名："*/
/*"用途：计算当前需量，根据当前功率方向和象限计算当前的有功无功需量"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
void Get_Current_Demand(void)
{
	unsigned int quadrant[4];	                   //quadrant value(0~3) of Sum,A,B,C
	Get_Quadrant_Value(quadrant);	                 //get quadrant value(0~3) of Sum,A,B,C
	/*"当前有功需量"*/
	if((quadrant[0]==0)||(quadrant[0]==3))	                               /*"累加总/A/B/C正向有功电量中间单元"*/
		Current_Demand[0]=Last_Average_Value[0][0];
	else         
		Current_Demand[0]=0-Last_Average_Value[1][0];
	
	/*"当前无功需量"*/
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
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"采用功率累计计算当前需量方式，累计需量周期内功率值"*/
		{
			temp=Cal_EnergyLimit();
			*l+=val;
	    *h+=(*l/1000l);
	    *l%=1000l;
	    *h%=(temp+1);
		}
	else/*"采用电量累计计算当前需量方式，累计需量周期内电量值，此处电量为电量系数换算前的值"*/
		{
			*h+=val;
		}	
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*"============================================================"*/
/*"函数名："*/
/*"用途：按照功率累加需量累加空间"*/
/*"参数："*/
/*"返回："*/
/*"作者：trend 版本：1.00"*/
/*"============================================================"*/
void Demand_Accumulator(void)
{
	unsigned int quadrant[4];	                   //quadrant value(0~3) of Sum,A,B,C
	unsigned long ActiveTemp = 0;
	unsigned long ReActiveTemp = 0;
	
	Get_Quadrant_Value(quadrant);	 
	
	if(Meter_Parameter.parameter1.DemandPeriod < 15)/*"采用功率累计计算当前需量方式，累计需量周期内功率值"*/
	{
			ActiveTemp = Active_power[0];
			ReActiveTemp = Reactive_power[0];
	}
	else/*"采用电量累计计算当前需量方式，累计需量周期内电量值，此处电量为电量系数换算前的值"*/
	{
			ActiveTemp = Active_energy_per_sec;
			ReActiveTemp = Reactive_energy_per_sec;
	}
	if((quadrant[0]==0)||(quadrant[0]==3))
	{/*"正有功"*/
		Demand_Add_Accumulator(&Demand_Sum.energy_h[0],&Demand_Sum.energy_l[0],ActiveTemp);
	}
	else
	{
		/*"反有功"*/
		Demand_Add_Accumulator(&Demand_Sum.energy_h[1],&Demand_Sum.energy_l[1],ActiveTemp);
	}	
	/*"4象限无功"*/
	Demand_Add_Accumulator(&Demand_Sum.energy_h[2+quadrant[0]],&Demand_Sum.energy_l[2+quadrant[0]],ReActiveTemp); 	
	Demand_Sum.time++;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
