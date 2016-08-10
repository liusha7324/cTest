/******************************************************************************************
*                      fine:      seg.c                                                  *
*                      function:  find seg                                           *
*******************************************************************************************/  

#include "defdata.h"
#include "eeprom.h"
#include "comm.h"
#include "ram.h"
#include "initcpu.h"
#include "interrupt.h"
#include "I2C_operation.h"
#include "att7022_operation.h"
#include "initram.h"
#include "Demand.h"
#include "MB_Showmain.h"
#include "MB_Keymain.h"
#include "Measure_Interface.h" 

#include "pay_def.h"
#include "Ex_Pay_For_Fun.h"


unsigned long NowSegParameter;   /*"上次查询的时段信息：0字节：费率套；1字节：时段表"*/
                                 /*"2字节：时段号；3字节费率号"*/



void Seg(void);
unsigned char  FindSlot(unsigned int,unsigned char,unsigned char);






/*"上电、设置参数、广播较时和每分钟调用"*/
void Seg(void)
{
        
        unsigned char slotnumber=0,Dailyslotnumber=0;  /* "默认第一套费率"  */
        unsigned int  yeareaddr;
        unsigned int  holdayeaddr;
        unsigned int  dayeaddr;
        unsigned char table;
        unsigned char weekslot;
        
        
      if(Meter_Parameter.parameter1.TriffSwitch.SwitchDate.Month==0x99)
			{
				Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow=0; 						 
			}
			if(Meter_Parameter.parameter1.DailySlotSwitch.SwitchDate.Month==0x99)
			{
				Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow=0;				 
			}
        
	    if(Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow<2)
		    slotnumber=Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow;
	    else  Meter_Parameter.parameter1.TriffSwitch.WhitchSlotIsNow=0;   /* "出错处理" */


	    if(Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow<2) 
			Dailyslotnumber=Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow;
	    else  Meter_Parameter.parameter1.DailySlotSwitch.WhitchSlotIsNow=0;   /* "出错处理" */
				
		if(!slotnumber)     
        {
           yeareaddr=YEARSLOT_ROM;
           //dayeaddr=DAILYSLOT_ROM;
           //holdayeaddr=HOLIDAYSLOT_ROM;
        }
        else
        {
           yeareaddr=YEARSLOT2_ROM;
           //dayeaddr=DAILYSLOT2_ROM;
           //holdayeaddr=HOLIDAYSLOT_ROM; 
        }	
        
        if(!Dailyslotnumber)     
        {
             dayeaddr=DAILYSLOT_ROM;
        }
        else
        {
             dayeaddr=DAILYSLOT2_ROM;
        }
		holdayeaddr=HOLIDAYSLOT_ROM; 
		
        *((unsigned  char *)&NowSegParameter+0)=((slotnumber<<4)&0xf0)+(Dailyslotnumber&0x0f);
        if(!Meter_Parameter.parameter1.SlotParemeter[0].HollidayNumble)//slotnumber->0 fxf 090120
           table=0;
        else table=FindSlot(holdayeaddr,Meter_Parameter.parameter1.SlotParemeter[0].HollidayNumble,3);
        if(!table)
        {
           table=0x01;
           table=(table<<softdate.Week);
           if(table & (~Meter_Parameter.parameter1.SlotParemeter[0].Week_Status.byte))
           {
               table=Meter_Parameter.parameter1.SlotParemeter[0].WeekEndTable;
           }
           else
           {
               table=FindSlot(yeareaddr,Meter_Parameter.parameter1.SlotParemeter[0].YearSlotNumble,1); 
           }
        }
        if((table>Meter_Parameter.parameter1.SlotParemeter[0].DailySlotTableNumble)||(table==0))
           table=1;

		Curr_Period_Flag =  table-1;
		if (Curr_Period_Flag>7)
			Curr_Period_Flag=0;
		
        *((unsigned  char *)&NowSegParameter+1)=table;    
        TRAFF_RATE=FindSlot(dayeaddr+(table-1)*MAXDAILYSLOT*3,Meter_Parameter.parameter1.SlotParemeter[0].DailySlotNumble,2);  
        if(TRAFF_RATE > (MAXTRIFF - 1))
           TRAFF_RATE=1; 
        *((unsigned  char *)&NowSegParameter+3)=TRAFF_RATE;  
        
        if(NowSegParameter!=O1ther_Meter_Parameter.OldSegParameter)
        {
           Output_On_3_In_1_Terminal_Set(1);    
           O1ther_Meter_Parameter.OldSegParameter=NowSegParameter;
           WRLC256(OLDSEGPARAMETER_ROM,(unsigned char *)&O1ther_Meter_Parameter.OldSegParameter,4,0,0);
           ///Set_Meter_para_Deal(OLDSEGPARAMETER_ROM);
          // WRLC256(OLDSEGPARAMETER_ROM,(unsigned char *)&Meter_Parameter.OldSegParameter,4,1,0);
           //Write_FM24C256_MULTI(OLDSEGPARAMETER_ROM,(unsigned char *)&Meter_Parameter.bill_state.OldSegParameter,4,FM24C256_1AND2);
           /*"费率切换时需量处理 trend 2008-10-29 15:58:57"*/
           Demand_Triff_Change();
	    //Event_Meter_Program_Flag.FreezeData_YueDing=1; //added by mw070510
	    //Event1(0); 		   
        }
        
        if(!TRAFF_RATE)   TRAFF_RATE=1;

		Max_Triff_Current=Meter_Parameter.parameter1.SlotParemeter[0].TriffNumble; //add by fxf  090227	
        
        //FindTriff();  /*"费率变化后，备份电量"*/
}

 /* "result=0,对于节假日，表示没有；对于年时区和日时段表示错误" */
 /*" sort=1:年时区查询；sort=2：日时段查询；sort=3:节假日查询；"*/
unsigned char  FindSlot(unsigned int eaddr,unsigned char maxnumber,unsigned char sort)
{
        unsigned int dated;
        unsigned int ddt[2];
        unsigned char number;
        unsigned char datat[3];
        unsigned int uni;
        unsigned char result=0; 
        unsigned int i,j,eeaddr;
        
        if(!maxnumber)  /*"输入个数为0时，返回0"*/
           return 0;

        
        if(sort==1 || sort==3)
        {
            *((unsigned char *)&dated+0)=softdate.Day;
            *((unsigned char *)&dated+1)=softdate.Month;
        }
        else 
        {
            *((unsigned char *)&dated+0)=softdate.Min;
            *((unsigned char *)&dated+1)=softdate.Hour;
        }
        
        if(sort!=3)
        {
           WRLC256(eaddr,Co.b,maxnumber*3,0,1);/*"edit by trend 2009-1-2 11:28:56"*/
           for(i=0;i<maxnumber-1;i++)   /*"排序"*/
           {
              for(j=i+1;j<maxnumber;j++)
              {
                 // *((unsigned char *)&ddt[0]+0)=Co.b[i*3+1];
                 // *((unsigned char *)&ddt[0]+1)=Co.b[i*3+2];
                 // *((unsigned char *)&ddt[1]+0)=Co.b[j*3+1];
                 // *((unsigned char *)&ddt[1]+1)=Co.b[j*3+2];
                 ddt[0]=*(unsigned int*)&Co.b[i*3+1];
		             ddt[1]=*(unsigned int*)&Co.b[j*3+1];
                  if(ddt[0]>ddt[1])
                  {
                      for(uni=0;uni<3;uni++)
                      {
                          datat[uni]=Co.b[i*3+uni]; 
                          Co.b[i*3+uni]=Co.b[j*3+uni]; 
                          Co.b[j*3+uni]=datat[uni]; 
                      }
                  }
              }
           }
           for(i=0;i<maxnumber-1;i++) /*"查找"*/
           {
                
             // *((unsigned char *)&ddt[0]+0)=Co.b[i*3+1];
             // *((unsigned char *)&ddt[0]+1)=Co.b[i*3+2];
             // *((unsigned char *)&ddt[1]+0)=Co.b[(i+1)*3+1];
             // *((unsigned char *)&ddt[1]+1)=Co.b[(i+1)*3+2];  
             ddt[0]=*(unsigned int*)&Co.b[i*3+1];
		         ddt[1]=*(unsigned int*)&Co.b[(i+1)*3+1];
              if(dated>=ddt[0] &&
                 dated< ddt[1])
              {
                 result=Co.b[i*3]; 
                 break;   
              }
           }
           if(i==maxnumber-1)   /*"查找到最后一个，或只有一个时区或时段"*/
           {
              result=Co.b[(maxnumber-1)*3];  
           }
           
           if(sort==2)
              *((unsigned  char *)&NowSegParameter+2)=i; 
        }
        else   /*"查找节假日"*/
        {
            eeaddr=eaddr;
        	for(i=0;i<maxnumber;)
          {    
              if(i+100<maxnumber)
              	uni=100;
              else
              	uni=maxnumber-i;
              WRLC256(eeaddr,Co.b,uni*4,0,1);
              for(j=0;j<uni;j++)
              {                  
                  *((unsigned char *)&ddt[0]+0)=Co.b[j*4+1];// 3->4 fuxf 081209
                  *((unsigned char *)&ddt[0]+1)=Co.b[j*4+2]; // 3->4 fuxf 081209
                  if((dated==ddt[0])&&((Co.b[j*4+3]==0xff)||(Co.b[j*4+3]==softdate.Year)))
                  {
                      result=Co.b[j*4];// 3->4 fuxf 081209
                      break;
                  }
              }
              if(result!=0)  break;
              i+=uni;
              eeaddr+=uni*4;
        	}
        }
        
        return result;  
} 
