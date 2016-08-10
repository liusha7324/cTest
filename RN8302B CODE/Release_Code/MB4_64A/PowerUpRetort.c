
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


#define  MAX_BILLDATE_POWERUP_STRIDE    12       /*"上电补月冻结数据点最大个数"*/

struct DATEANDTIME_DEF BillDay_Dot[3];/*"设置的第三结算日"*/

struct DATEANDTIME_DEF Year_BillDay_Dot[4];/*""*/
struct DATEANDTIME_DEF YearBill_NoIterance_Dot[4];/*"设置的无重复时间年结算日"*/

 
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
/*"函数名：PowerUpRetort"*/
/*"用途：上电补跨过的月结算日"*/
/*"参数：无"*/
/*"返回值：无"*/
/*"作者：king chen 版本：1.00"*/
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
   
  struct DATEANDTIME_DEF Now_time;/*"上电时刻时间"*/
  struct DATEANDTIME_DEF LastEnergyBillDate_temp;///king chen add 130319
  struct DATEANDTIME_DEF LastEnergyBillDate_powerup;/*"上电补冻结的开始时间"*/
    
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

     ///if(cross_billdate>12)/*"上电补结算取消大于12个月就不补的条件"*/  
	/// return ;
	 
	 stridebill_dot_num=0;
        billdate_single_num=billdate_result[billdate_setting_ok -1];
	
   if((0==O1ther_Meter_Parameter.PowerOnRetort_flag) || (4==O1ther_Meter_Parameter.PowerOnRetort_flag))
   	{
   	WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen modify 130228
	if(Meter_Parameter.parameter1.MeterMode[2].bit.b6)/*"增加模式字3的BIT6为上电补结算控制位"*/
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
					  O1ther_Meter_Parameter.PowerOnRetort_flag=4;/*"月结算至少补了一个"*/
					  WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322
					break;
                               }
                            }     	
    	                }
		}
           O1ther_Meter_Parameter.PowerOnRetort_flag=1;/*"月结算已经完成"*/
           WRLC256(POWERONRETORT_FLAG_ROM,(unsigned char *)&O1ther_Meter_Parameter.PowerOnRetort_flag,1,0,0); ///king chen add 130322
   	}
}


/*"============================================================"*/
/*"函数名：Check_Billdate_Validity_and_Ascending"*/
/*"用途：查找月结算日的有效性"*/
/*"参数：无"*/
/*"返回值："*/
/*"0 表示有效结算日个数是0; "*/
/*"1表示找到1个结算日，并且是第一结算日有效; "*/
/*"2表示找到2个结算日，并且第一和第二结算日有效，2个结算日从小到大排列; "*/
/*"3表示找到3个结算日，并且3个结算日从小到大排列;"*/
/*"作者：king chen 版本：1.00"*/
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
   
   struct DATEANDTIME_DEF BillDay_Dot_temp[3]={0};/*"存放三个结算日的临时变量"*/

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
/*"函数名：Sort_By_Ascend"*/
/*"用途：数组按升序进行排序"*/
/*"参数：array:  传输数组的首地址,n: 数组的长度"*/
/*"返回值：无"*/
/*"作者：king chen 版本：1.00"*/
/*"============================================================"*/
void Sort_By_Ascend(TDateTime*array,unsigned int n) 
{
  unsigned int  i,j,k;
  TDateTime temp;
  if(n!=0)
  {
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)/*"将第i个元素与其后各元素比较"*/
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
//Description:			/*"从大到小排"*/
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
    for(j=i+1;j<n;j++)/*"将第i个元素与其后各元素比较"*/
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
//Description:			   /*"年结算"*/
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
	unsigned char billdate_result[4]={5,3,2,2};	/*"记录的最大次数,该基数值*有效值个数"*/
	unsigned char l_return_num=0,l_error_num=0;
	struct DATEANDTIME_DEF l_templist[4][4];		/*"[N][M]含义:  [N]:要找的第几个有效结算时间;  [M]:该时间，在掉上电时间段内找到的符合要求的时标"*/
	struct DATEANDTIME_DEF l_judge_templist[8];		/*"用来保存找出时候的时标点时间"*/
	struct DATEANDTIME_DEF l_save_templist[5];		/*"用来最后结算时保存的4个要记录的时标点时间"*/
	struct DATEANDTIME_DEF Now_time;					/*"上电时刻时间"*/
	unsigned char temp;
    unsigned char Year_Bill_Point_temp;
    struct DATEANDTIME_DEF LastYearBillDate_temp={0};
	
	//--------------------------------------------------------//
	/*"01.将所设置的有效时间,转入参数使用变量"*/
	//--------------------------------------------------------//
	Now_time = softdate;									/*"Li_最新系统时间"*/
	for(num=0;num<4; num++)									/*"Li_设置的当前年结算时间赋值"*/
	{
		 Year_BillDay_Dot[num].Year = 0x99;				/*"Li_年份补成通配符"*/
		 Year_BillDay_Dot[num].Month=Pre_Payment_Para.Year_BillDate[0][num].Month;
		 Year_BillDay_Dot[num].Day= 	 Pre_Payment_Para.Year_BillDate[0][num].Day;
		 Year_BillDay_Dot[num].Hour=  Pre_Payment_Para.Year_BillDate[0][num].Hour;
		 Year_BillDay_Dot[num].Min=   0;
		 Year_BillDay_Dot[num].Sec =  0;
		 Year_BillDay_Dot[num].Week=  0;
	}
	My_Memcpy((unsigned char *)&YearBill_NoIterance_Dot[0],0,sizeof(struct DATEANDTIME_DEF)*4 );	/*"Li_清零"*/
	My_Memcpy((unsigned char *)&l_judge_templist[0],0,sizeof(struct DATEANDTIME_DEF)*8 );
	My_Memcpy((unsigned char *)&l_save_templist[0],0,sizeof(struct DATEANDTIME_DEF)*5 );
	
    //---------------------------------------------------//
	/*"02.确定是否符合有效的标准(从小到大)"*/
	//---------------------------------------------------//
	  if(!CheckDateTime((TDateTime *)&Powerdown_Save_Data.date))	/*"Li_对月上一次结算时间合法性判断"*/
	 	return;
	  if(!CheckDateTime((TDateTime *)&Now_time))
	 	return;
	billdate_setting_ok =Check_YearBilldate_Validity_and_Ascending();	/*"Li_判断设置的年结算时间有几个有效"*/
	if(!billdate_setting_ok)												/*"Li_如果设置的全部无效,则退出"*/
		return;

	
	//--------------------------------------------------------//
	/*"03.将所设置的有效时间,转入参数使用变量"*/
	//--------------------------------------------------------//
	l_return_num=billdate_result[billdate_setting_ok -1];						/*"Li_算出记录的次数的基数,返回数目"*/
	for(billdate_num =0; billdate_num<billdate_setting_ok; billdate_num++)   	/*"Li_billdate_setting_ok表示有效的个数"*/
	{
		 billdate_result_num = GetSkipedTimeFlags((TDateTime *)&Powerdown_Save_Data.date, (TDateTime *)&Now_time, 
							(TDateTime *)(YearBill_NoIterance_Dot + billdate_num), (TDateTime *)(l_templist [billdate_num]), l_return_num);
		if( (billdate_result_num!=0) && (billdate_result_num!= -1) )
		{
			for(billday_num=0; billday_num<billdate_result_num; billday_num++)		/*"Li_判断某个有效的值,记录的时候,有几个值需记录"*/
			{
				if(stridebill_dot_num<8)
					l_judge_templist[stridebill_dot_num++]=l_templist[billdate_num][billday_num];  	/*"Li_赋值到一维数组,以便之后全部进行排序"*/
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

	if(l_error_num<billdate_setting_ok)			/*"无重复合法时间点找出的错误个数<无重复合法时间点个数"*/
	{
		//-----------------------------------------------------//
		/*"04.将找出来的记录点,再按时间顺序排序"*/
		//-----------------------------------------------------//
		Sort_By_Decline((TDateTime *)&(l_judge_templist),stridebill_dot_num);		/*"Li_按照时间从大到小排序"*/
		My_Memcpy((unsigned char *)&l_save_templist[0],(unsigned char *)&l_judge_templist[0],sizeof(struct DATEANDTIME_DEF)*5);		/*"Li_复制前5个时间(只要记录4个)到保存的数组里"*/
		//----------------------------------------------------//
		/*"05.开始记录电量数据和每个结算点时间"*/
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
//Description:			/*"判断年结算时间的有效性"*/
//Parameter:
//Author:					LiYuehao
//Update Time:		       20130309
/*"============================================================"*/
unsigned char Check_YearBilldate_Validity_and_Ascending(void)
{
   unsigned char  billdate_flag;
   unsigned char  billdate_is_ok;

   
   billdate_flag=Check_YearBilldate_Validity(Year_BillDay_Dot);
   Sort_By_Ascend((TDateTime *)&(Year_BillDay_Dot),4);	 /*"Li_把有效设置时间按从小到大排序"*/

   
   if(billdate_flag==0)										/*"Li_如果4个年结算时间全部无效"*/
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
			/*"Li_无效的情况,相应清零"*/
			My_Memcpy((unsigned char *)&(Year_BillDay_Dot+num),0,sizeof(struct DATEANDTIME_DEF) );
		}
		else
		{
			add++;							/*"Li_有效的总个数"*/
		}
	}
	return add;

}



/*"============================================================"*/
//Function:			   
//Description:			/*"Li_比较重复性"*/	
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
	else if(billdate_flag>1)						/*"大于1个有效值,才补"*/
	{
		
		/*"02.比较重复性"*/
		for(i=0; i<3; i++)		/*"因为已经是从小到大顺序,只要比较临近是否重复即可,而且去掉大到小的情况"*/
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
	return billdate_is_ok;						/*"返回非0   无重复的有效值个数"*/
}
/*"============================================================"*/







/*"============================================================"*/
/*"函数名：DelSameElement"*/
/*"参数：array数组首地址,nSize 为数组长度"*/
/*"用途：将数组里的重复数据删除后面的数据向前移，并且数组的有效长度相应减小"*/
/*"比如原来数组为array[3]={1,1,2}，输出的数组为array[3]={1,2,2}，但是此时的数组长度(nSize)有效值变为2"*/
/*"返回：无"*/
/*"版本：1.00"*/
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

