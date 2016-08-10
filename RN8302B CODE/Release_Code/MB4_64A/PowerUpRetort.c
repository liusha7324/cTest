
#include "PowerUpRetort.h"
#include "defdata.h"
#include "eeprom.h"
#include "ram.h"
#include "I2C_operation.h"
#include "initram.h" 
#include "multi.h"  
#include "MB_BASE_FUN.h"
#include "Freeze.h"  
#include "Measure_Interface.h" 
#include "Ex_Pay_For_Fun.h"
#include "Comm.h"
#include "Pay_def.h"
#include "Ex_Pay_For_Fun.h"


#define  MAX_BILLDATE_POWERUP_STRIDE    12       /*"�ϵ粹�¶������ݵ�������"*/

struct DATEANDTIME_DEF BillDay_Dot[3];/*"���õĵ���������"*/

struct DATEANDTIME_DEF Year_BillDay_Dot[4];/*""*/
struct DATEANDTIME_DEF YearBill_NoIterance_Dot[4];/*"���õ����ظ�ʱ���������"*/

 
struct DATEANDTIME_DEF StrideBill_Dot_List[4][MAX_BILLDATE_POWERUP_STRIDE];///king chen debug


void Sort_By_Ascend(TDateTime* array,unsigned int n) ;
void Sort_By_Decline(TDateTime*array,unsigned int n) ;

unsigned char Check_Billdate_Validity_and_Ascending(void);


unsigned char Check_YearBilldate_Validity_and_Ascending(void);
unsigned char Check_YearBilldate_Validity(struct DATEANDTIME_DEF *address);
unsigned char Check_Offset(unsigned char billdate_flag_low);
unsigned char CheckIterance_YearBillDate(unsigned char billdate_flag);


void PowerUpRetort(void);
void PowerUpYearBill(void);				//Li Update 20130309
void DelSameElement(TDateTime*array,unsigned int *nSize);///king chen debug

/*"============================================================"*/
/*"��������PowerUpRetort"*/
/*"��;���ϵ粹������½�����"*/
/*"��������"*/
/*"����ֵ����"*/
/*"���ߣ�king chen �汾��1.00"*/
/*"============================================================"*/

void PowerUpRetort(void)
{

unsigned char billdate_setting_ok=0;///king chen modify 130315

 ///unsigned char cross_billdate;
 unsigned int billday_num;
  unsigned int stridebill_dot_num=0;
  unsigned int stridebill_num[3];
  unsigned char billdate_num;
  unsigned char num;
  unsigned char billdate_result[3]={12, 6, 4};
  unsigned char billdate_single_num;
  int billdate_result_num;
   unsigned char temp;
   
  struct DATEANDTIME_DEF Now_time;/*"�ϵ�ʱ��ʱ��"*/
  struct DATEANDTIME_DEF LastEnergyBillDate_temp;///king chen add 130319
  struct DATEANDTIME_DEF LastEnergyBillDate_powerup;/*"�ϵ粹����Ŀ�ʼʱ��"*/
    
    Now_time = softdate;
  
    for(num=0;num<3; num++)
    	{
    	  BillDay_Dot[num].Year = 0x99;
    	  BillDay_Dot[num].Month= 0x99;
    	  BillDay_Dot[num].Day= Meter_Parameter.parameter1.AutoBillDayHour[num].Day;
    	  BillDay_Dot[num].Hour= Meter_Parameter.parameter1.AutoBillDayHour[num].Hour;
    	  BillDay_Dot[num].Min= 0;
    	  BillDay_Dot[num].Sec = 0;
    	  BillDay_Dot[num].Week= 0;
    	}

  billdate_setting_ok =Check_Billdate_Validity_and_Ascending();
   if(!billdate_setting_ok)
         return ;
///   if(ComparentTime((unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate, (unsigned char *)&Powerdown_Save_Data.date)==ResultLarger)///king chen mark 130319
///                return ;
///   else
     LastEnergyBillDate_powerup=O1ther_Meter_Parameter.LastEnergyBillDate;

      if(O1ther_Meter_Parameter.PowerOnRetort_flag!=4)
 	{
  	 LastEnergyBillDate_temp =LastEnergyBillDate_powerup ;
 	 LastEnergyBillDate_powerup = Powerdown_Save_Data.date;
   	}

   	if((!CheckTime((unsigned char *)&Now_time)) ||(!CheckTime((unsigned char *)&LastEnergyBillDate_powerup )))
        return ;
     ///if(!CheckTime((unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate))	
    /// {  																					
    ///    Meter_Parameter.bill_state.LastEnergyBillDate=softdate;
    ///    WRLC256(LASTENERGYBILLDATE_ROM,(unsigned char *)&Meter_Parameter.bill_state.LastEnergyBillDate,7,0,0);
   ///     Set_Meter_para_Deal(LASTENERGYBILLDATE_ROM); 
   ///     return;
   ///  }  
     
     ///cross_billdate=12L*(OB_H(softdate.Year)-OB_H(Meter_Parameter.bill_state.LastEnergyBillDate.Year))+OB_H(softdate.Month)-OB_H(Meter_Parameter.bill_state.LastEnergyBillDate.Month);

     ///if(cross_billdate>12)/*"�ϵ粹����ȡ������12���¾Ͳ���������"*/  
	/// return ;
	 
	 stridebill_dot_num=0;
        billdate_single_num=billdate_result[billdate_setting_ok -1];
	
   if((0==O1ther_Meter_Parameter.PowerOnRetort_flag) || (4==O1ther_Meter_Parameter.PowerOnRetort_flag))
   	{
   	WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen modify 130228
	if(Meter_Parameter.parameter1.MeterMode[2].bit.b6)/*"����ģʽ��3��BIT6Ϊ�ϵ粹�������λ"*/
	   {
		for(billdate_num =0;billdate_num< billdate_setting_ok;billdate_num++)///king chen debug
                      {
                       billdate_result_num = GetSkipedTimeFlags((TDateTime *)&LastEnergyBillDate_powerup, (TDateTime *)&Now_time, 
		                                                   (TDateTime *)&(BillDay_Dot[billdate_num]), (TDateTime *)&(StrideBill_Dot_List[billdate_num]), billdate_single_num);
                    if(billdate_result_num>0)
                    {
                        for(billday_num=0;billday_num<billdate_result_num;billday_num++)
                      	{
			          StrideBill_Dot_List[3][stridebill_dot_num++]=StrideBill_Dot_List[billdate_num][billday_num];  
                      	}
                    }
                      }
		
		 if((stridebill_dot_num<MAX_BILLDATE_POWERUP_STRIDE)&&(O1ther_Meter_Parameter.PowerOnRetort_flag!=4))///king chen modify 130422
			{
			  temp=Powerdown_Save_Data.date.Min;///king chen add 130325
			  Powerdown_Save_Data.date.Min=0;
			    for(num=0;num<3;num++)
                           {   
				if((Powerdown_Save_Data.date.Hour==Meter_Parameter.parameter1.AutoBillDayHour[num].Hour)
				&&(Powerdown_Save_Data.date.Day==Meter_Parameter.parameter1.AutoBillDayHour[num].Day)
				&&(ComparentTime((unsigned char *)&LastEnergyBillDate_temp, (unsigned char *)&Powerdown_Save_Data.date)!=ResultEqual)
				&&(0==temp)&&(Powerdown_Save_Data.date.Sec<=2))///king chen add 130510
				{
				stridebill_dot_num+=1;
				StrideBill_Dot_List[3][stridebill_dot_num-1]=Powerdown_Save_Data.date;
				StrideBill_Dot_List[3][stridebill_dot_num-1].Min=0;
				StrideBill_Dot_List[3][stridebill_dot_num-1].Sec=0;
				StrideBill_Dot_List[3][stridebill_dot_num-1].Week= 0;
				break;				
				}

			     }
			  Powerdown_Save_Data.date.Min=temp;
			}
         
		 if(stridebill_dot_num>MAX_BILLDATE_POWERUP_STRIDE)
                   return ;
                      Sort_By_Ascend((TDateTime *)&(StrideBill_Dot_List [3]),stridebill_dot_num);
                      
			 for(billday_num = 0; billday_num < stridebill_dot_num; billday_num++)
    	                {
    	
                           for(num=0;num<3;num++)
                           {        
                                if((Meter_Parameter.parameter1.AutoBillDayHour[num].Hour==StrideBill_Dot_List[3][billday_num].Hour)
                               &&(Meter_Parameter.parameter1.AutoBillDayHour[num].Day==StrideBill_Dot_List[3][billday_num].Day))
                                {  
					  if (num==0 )		//payment
					  	{
					  	if (YEAR_BILL_FLAG)
					 	 	Pre_Moneth_Updata();
						else
				         	       Pre_Bill((unsigned char *)(StrideBill_Dot_List[3]+ billday_num));
					  	}
					  Retort_New(num,(unsigned char *)(StrideBill_Dot_List[3]+ billday_num)); 
					  O1ther_Meter_Parameter.PowerOnRetort_flag=4;/*"�½������ٲ���һ��"*/
					  WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322
					break;
                               }
                            }     	
    	                }
		}
           O1ther_Meter_Parameter.PowerOnRetort_flag=1;/*"�½����Ѿ����"*/
           WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322
   	}
}


/*"============================================================"*/
/*"��������Check_Billdate_Validity_and_Ascending"*/
/*"��;�������½����յ���Ч��"*/
/*"��������"*/
/*"����ֵ��"*/
/*"0 ��ʾ��Ч�����ո�����0; "*/
/*"1��ʾ�ҵ�1�������գ������ǵ�һ��������Ч; "*/
/*"2��ʾ�ҵ�2�������գ����ҵ�һ�͵ڶ���������Ч��2�������մ�С��������; "*/
/*"3��ʾ�ҵ�3�������գ�����3�������մ�С��������;"*/
/*"���ߣ�king chen �汾��1.00"*/
/*"============================================================"*/

unsigned char Check_Billdate_Validity_and_Ascending(void)
{
   unsigned char  billdate_flag;
   unsigned char billdate_flag_high;
   unsigned char billdate_flag_low;
   ///unsigned char billdate_smaller;
   unsigned char billdate_is_ok;

   unsigned int num,uni;///king chen add 130315
   ///unsigned char billdate_num;
   
   struct DATEANDTIME_DEF BillDay_Dot_temp[3]={0};/*"������������յ���ʱ����"*/

   billdate_flag=Check_Billdate_Validity(0,0xff);
   
   billdate_flag_high=billdate_flag>>4;
   
   billdate_flag_low=billdate_flag&0x0f;
   
   num=0;
   for(uni=0; uni<3; uni++)
   	if(billdate_flag_low&(1<<uni))
		BillDay_Dot_temp[num++]=BillDay_Dot[uni];
	
   Sort_By_Ascend((TDateTime *)&BillDay_Dot_temp[0], num);
   
   DelSameElement((TDateTime *)&BillDay_Dot_temp[0], &num);
   
    for(uni=0;uni<3; uni++)
    	{
    	  BillDay_Dot[uni].Year = 0;
    	  BillDay_Dot[uni].Month= 0;
    	  BillDay_Dot[uni].Day= 0;
    	  BillDay_Dot[uni].Hour=0;
    	  BillDay_Dot[uni].Min= 0;
    	  BillDay_Dot[uni].Sec = 0;
    	  BillDay_Dot[uni].Week= 0;
    	}
 
  for(uni=0; uni<num; uni++)
  	BillDay_Dot[uni]=BillDay_Dot_temp[uni];
   return num;

}

/*"============================================================"*/
/*"��������Sort_By_Ascend"*/
/*"��;�����鰴�����������"*/
/*"������array:  ����������׵�ַ,n: ����ĳ���"*/
/*"����ֵ����"*/
/*"���ߣ�king chen �汾��1.00"*/
/*"============================================================"*/
void Sort_By_Ascend(TDateTime*array,unsigned int n) 
{
  unsigned int  i,j,k;
  TDateTime temp;
  if(n!=0)
  {
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)/*"����i��Ԫ��������Ԫ�رȽ�"*/
    if(ComparentTime((unsigned char *)(array+j),(unsigned char *)(array+i))==ResultSmaller)///king chen modify 130316
    	{
         temp=*(array+i);
         *(array+i)=*(array+j);
         *(array+j)=temp;     
    	}
 }
  }
}



/*"============================================================"*/
//Function:			   Sort_By_Decline
//Description:			/*"�Ӵ�С��"*/
//Parameter:
//Author:					LiYuehao
//Update Time:		       20130319
/*"============================================================"*/
void Sort_By_Decline(TDateTime*array,unsigned int n) 
{
  unsigned int  i,j,k;
  TDateTime temp;
  if(n !=0)
  {
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)/*"����i��Ԫ��������Ԫ�رȽ�"*/
    if(ComparentTime((unsigned char *)(array+j),(unsigned char *)(array+i))==ResultLarger)///king chen modify 130316
    	{
         temp=*(array+i);
         *(array+i)=*(array+j);
         *(array+j)=temp;     
    	}
 }
  }
}



//*****************************************************************************************************//

/*"============================================================"*/
//Function:			   PowerUpYearBill
//Description:			   /*"�����"*/
//Parameter:
//Author:					LiYuehao
//Update Time:		       20130309
/*"============================================================"*/
void PowerUpYearBill(void)
{
	unsigned char billdate_setting_ok=0;
	signed  int  billday_num=0;
	signed  int   billdate_result_num=0;
	unsigned int  stridebill_dot_num=0;
	unsigned char billdate_num=0;
	unsigned char num=0;
	unsigned char billdate_result[4]={5,3,2,2};	/*"��¼��������,�û���ֵ*��Чֵ����"*/
	unsigned char l_return_num=0,l_error_num=0;
	struct DATEANDTIME_DEF l_templist[4][4];		/*"[N][M]����:  [N]:Ҫ�ҵĵڼ�����Ч����ʱ��;  [M]:��ʱ�䣬�ڵ��ϵ�ʱ������ҵ��ķ���Ҫ���ʱ��"*/
	struct DATEANDTIME_DEF l_judge_templist[8];		/*"���������ҳ�ʱ���ʱ���ʱ��"*/
	struct DATEANDTIME_DEF l_save_templist[5];		/*"����������ʱ�����4��Ҫ��¼��ʱ���ʱ��"*/
	struct DATEANDTIME_DEF Now_time;					/*"�ϵ�ʱ��ʱ��"*/
	unsigned char temp;
    unsigned char Year_Bill_Point_temp;
    struct DATEANDTIME_DEF LastYearBillDate_temp={0};
	
	//--------------------------------------------------------//
	/*"01.�������õ���Чʱ��,ת�����ʹ�ñ���"*/
	//--------------------------------------------------------//
	Now_time = softdate;									/*"Li_����ϵͳʱ��"*/
	for(num=0;num<4; num++)									/*"Li_���õĵ�ǰ�����ʱ�丳ֵ"*/
	{
		 Year_BillDay_Dot[num].Year = 0x99;				/*"Li_��ݲ���ͨ���"*/
		 Year_BillDay_Dot[num].Month=Pre_Payment_Para.Year_BillDate[0][num].Month;
		 Year_BillDay_Dot[num].Day= 	 Pre_Payment_Para.Year_BillDate[0][num].Day;
		 Year_BillDay_Dot[num].Hour=  Pre_Payment_Para.Year_BillDate[0][num].Hour;
		 Year_BillDay_Dot[num].Min=   0;
		 Year_BillDay_Dot[num].Sec =  0;
		 Year_BillDay_Dot[num].Week=  0;
	}
	My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot[0],0,sizeof(struct DATEANDTIME_DEF)*4 );	/*"Li_����"*/
	My_Memcpy((unsigned char *)&l_judge_templist[0],0,sizeof(struct DATEANDTIME_DEF)*8 );
	My_Memcpy((unsigned char *)&l_save_templist[0],0,sizeof(struct DATEANDTIME_DEF)*5 );
	
    //---------------------------------------------------//
	/*"02.ȷ���Ƿ������Ч�ı�׼(��С����)"*/
	//---------------------------------------------------//
	  if(!CheckDateTime((TDateTime *)&Powerdown_Save_Data.date))	/*"Li_������һ�ν���ʱ��Ϸ����ж�"*/
	 	return;
	  if(!CheckDateTime((TDateTime *)&Now_time))
	 	return;
	billdate_setting_ok =Check_YearBilldate_Validity_and_Ascending();	/*"Li_�ж����õ������ʱ���м�����Ч"*/
	if(!billdate_setting_ok)												/*"Li_������õ�ȫ����Ч,���˳�"*/
		return;

	
	//--------------------------------------------------------//
	/*"03.�������õ���Чʱ��,ת�����ʹ�ñ���"*/
	//--------------------------------------------------------//
	l_return_num=billdate_result[billdate_setting_ok -1];						/*"Li_�����¼�Ĵ����Ļ���,������Ŀ"*/
	for(billdate_num =0; billdate_num<billdate_setting_ok; billdate_num++)   	/*"Li_billdate_setting_ok��ʾ��Ч�ĸ���"*/
	{
		 billdate_result_num = GetSkipedTimeFlags((TDateTime *)&Powerdown_Save_Data.date, (TDateTime *)&Now_time, 
							(TDateTime *)(YearBill_NoIterance_Dot + billdate_num), (TDateTime *)(l_templist [billdate_num]), l_return_num);
		if( (billdate_result_num!=0) && (billdate_result_num!= -1) )
		{
			for(billday_num=0; billday_num<billdate_result_num; billday_num++)		/*"Li_�ж�ĳ����Ч��ֵ,��¼��ʱ��,�м���ֵ���¼"*/
			{
				if(stridebill_dot_num<8)
					l_judge_templist[stridebill_dot_num++]=l_templist[billdate_num][billday_num];  	/*"Li_��ֵ��һά����,�Ա�֮��ȫ����������"*/
				else
					break;
			}
		}
		else
			l_error_num++;
	}

	if(stridebill_dot_num<5)
	{
		temp=Powerdown_Save_Data.date.Min;
		Powerdown_Save_Data.date.Min=0;
		if(Pre_Payment_Data.Year_Bill_Point)
			 Year_Bill_Point_temp=Pre_Payment_Data.Year_Bill_Point-1;
		else
			 Year_Bill_Point_temp=3;
			  
        LastYearBillDate_temp.Year= Pre_Payment_Data.Pre_Year_BillDate[Year_Bill_Point_temp].YEAR;
        LastYearBillDate_temp.Month=Pre_Payment_Data.Pre_Year_BillDate[Year_Bill_Point_temp].Month;
        LastYearBillDate_temp.Day=Pre_Payment_Data.Pre_Year_BillDate[Year_Bill_Point_temp].Day;
        LastYearBillDate_temp.Hour=Pre_Payment_Data.Pre_Year_BillDate[Year_Bill_Point_temp].Hour;

		for(num=0;num<4;num++)
		{
			if((Powerdown_Save_Data.date.Month==Pre_Payment_Para.Year_BillDate[0][num].Month)
	              &&(Powerdown_Save_Data.date.Day==Pre_Payment_Para.Year_BillDate[0][num].Day)
				  &&(Powerdown_Save_Data.date.Hour==Pre_Payment_Para.Year_BillDate[0][num].Hour)
				  &&(ComparentTime((unsigned char *)&LastYearBillDate_temp, (unsigned char *)&Powerdown_Save_Data.date)!=ResultEqual)
				  &&(0==temp)&&(Powerdown_Save_Data.date.Sec<=2))
			{
				  stridebill_dot_num+=1;
			      l_judge_templist[stridebill_dot_num-1]=Powerdown_Save_Data.date;
				  l_judge_templist[stridebill_dot_num-1].Min=0;
				  l_judge_templist[stridebill_dot_num-1].Sec=0;
				  l_judge_templist[stridebill_dot_num-1].Week= 0;
		          l_error_num=0;      
				  break;				
			}
		}
		Powerdown_Save_Data.date.Min=temp;
	}	

	if(l_error_num<billdate_setting_ok)			/*"���ظ��Ϸ�ʱ����ҳ��Ĵ������<���ظ��Ϸ�ʱ������"*/
	{
		//-----------------------------------------------------//
		/*"04.���ҳ����ļ�¼��,�ٰ�ʱ��˳������"*/
		//-----------------------------------------------------//
		Sort_By_Decline((TDateTime *)&(l_judge_templist),stridebill_dot_num);		/*"Li_����ʱ��Ӵ�С����"*/
		My_Memcpy((unsigned char *)&l_save_templist[0],(unsigned char *)&l_judge_templist[0],sizeof(struct DATEANDTIME_DEF)*5);		/*"Li_����ǰ5��ʱ��(ֻҪ��¼4��)�������������"*/
		//----------------------------------------------------//
		/*"05.��ʼ��¼�������ݺ�ÿ�������ʱ��"*/
		//----------------------------------------------------//
		for(billday_num=4; billday_num>=0; billday_num--)
		{  
		  	if( CheckDateTime((TDateTime *)&(l_save_templist+billday_num)) )
				Pre_Bill((unsigned char *)&(l_save_templist+billday_num));	//payment  
		}
        POWERONYEARBILL_FLAG_DEFINE=1;
        Pay_EE_W(PAY_FOR_USERS_FLAG15_EE,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
               (unsigned char *)&(Pre_Payment_Para),LENGTH_PRE_PAYMENT_PARA,PRE_PAYMENT_PARA_EE);
	}
	
}





/*"============================================================"*/
//Function:			   Check_YearBilldate_Validity_and_Ascending
//Description:			/*"�ж������ʱ�����Ч��"*/
//Parameter:
//Author:					LiYuehao
//Update Time:		       20130309
/*"============================================================"*/
unsigned char Check_YearBilldate_Validity_and_Ascending(void)
{
   unsigned char  billdate_flag;
   unsigned char  billdate_is_ok;

   
   billdate_flag=Check_YearBilldate_Validity(Year_BillDay_Dot);
   Sort_By_Ascend((TDateTime *)&(Year_BillDay_Dot),4);	 /*"Li_����Ч����ʱ�䰴��С��������"*/

   
   if(billdate_flag==0)										/*"Li_���4�������ʱ��ȫ����Ч"*/
   {
   		return 0;
   }
   else
   {
	   billdate_is_ok=CheckIterance_YearBillDate(billdate_flag);
	   return billdate_is_ok;
   }
   
}


/*"============================================================"*/
//Function:			   Check_YearBilldate_Validity
//Description:			
//Parameter:
//Author:					LiYuehao
//Update Time:		       20130309
/*"============================================================"*/
unsigned char Check_YearBilldate_Validity(struct DATEANDTIME_DEF *address)
{
    unsigned char num,add=0; 
	for(num=0;num<4;num++)
	{
		if(!CheckDateTime( (TDateTime *)(address+num) ) || ( ((address+num)->Day)>0x28))
		{
			/*"Li_��Ч�����,��Ӧ����"*/
			My_Memcpy((unsigned char *)&(Year_BillDay_Dot+num),0,sizeof(struct DATEANDTIME_DEF) );
		}
		else
		{
			add++;							/*"Li_��Ч���ܸ���"*/
		}
	}
	return add;

}



/*"============================================================"*/
//Function:			   
//Description:			/*"Li_�Ƚ��ظ���"*/	
//Parameter:			 	 
//Author:					     LiYuehao
//Update Time:		            20130315
/*"============================================================"*/
unsigned char CheckIterance_YearBillDate(unsigned char billdate_flag)
{
	unsigned char  l_num=0;
	unsigned char  i=0,j=0,k=0,l_result=0;
	unsigned char  billdate_is_ok=0;

	if(billdate_flag==1)
	{
		My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot,(unsigned char *)&(Year_BillDay_Dot+3), sizeof(struct  DATEANDTIME_DEF) );
	}
	else if(billdate_flag>1)						/*"����1����Чֵ,�Ų�"*/
	{
		
		/*"02.�Ƚ��ظ���"*/
		for(i=0; i<3; i++)		/*"��Ϊ�Ѿ��Ǵ�С����˳��,ֻҪ�Ƚ��ٽ��Ƿ��ظ�����,����ȥ����С�����"*/
		{
			l_result=ComparentTime((unsigned char *)(Year_BillDay_Dot+i), (unsigned char *)(Year_BillDay_Dot +(i+1))  );
			if(l_result==ResultSmaller)
			{
		  		if( CheckDateTime((TDateTime *)&(Year_BillDay_Dot+i)) )
				{
					My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot[k],(unsigned char *)&Year_BillDay_Dot[i], sizeof(struct  DATEANDTIME_DEF) );
					k++;
				}
		  		if( CheckDateTime((TDateTime *)&(Year_BillDay_Dot+(i+1))) )
				{
					My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot[k],(unsigned char *)&Year_BillDay_Dot[i+1], sizeof(struct  DATEANDTIME_DEF) );
				}
			}
			else if(l_result==ResultEqual)
			{
		  		if( CheckDateTime((TDateTime *)&(Year_BillDay_Dot+i)) )
				{
					My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot[k],(unsigned char *)&Year_BillDay_Dot[i], sizeof(struct  DATEANDTIME_DEF) );		
				}
			}
		}
	}

	for(i=0; i<4; i++)
	{
		if( CheckDateTime((TDateTime *)&(YearBill_NoIterance_Dot+i)) )
			billdate_is_ok++;	
	}
	return billdate_is_ok;						/*"���ط�0   ���ظ�����Чֵ����"*/
}
/*"============================================================"*/







/*"============================================================"*/
/*"��������DelSameElement"*/
/*"������array�����׵�ַ,nSize Ϊ���鳤��"*/
/*"��;������������ظ�����ɾ�������������ǰ�ƣ������������Ч������Ӧ��С"*/
/*"����ԭ������Ϊarray[3]={1,1,2}�����������Ϊarray[3]={1,2,2}�����Ǵ�ʱ�����鳤��(nSize)��Чֵ��Ϊ2"*/
/*"���أ���"*/
/*"�汾��1.00"*/
/*"============================================================"*/
void DelSameElement(TDateTime*array,unsigned int *nSize)
{
    unsigned int  i = 1;
    unsigned int  j = 0;
    TDateTime temp;
    unsigned int  k = 0;
	     
    for (;i<*nSize; i++)
    {
       temp = *(array+i - 1);
       j = i;
       while (j<*nSize)
       {
            if (ComparentTime((unsigned char *)&temp,(unsigned char *)(array+j))==ResultEqual)///king chen modify 130316
            {
                k = j;
                while (k<*nSize-1)
                {
                     *(array+k)=*(array+k+1);
                     ++k;
                }
                     --*nSize; 
             }
             else
                ++j;
          }
     }
}

