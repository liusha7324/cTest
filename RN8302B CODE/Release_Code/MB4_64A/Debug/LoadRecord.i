#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"
 
 
 
 
 


#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/MB_BASE_FUN.h"



 
 

 
union WORD_DEF1
{
	unsigned short AsUShort;
	short AsShort;
	struct
	{
		unsigned char Byte0;
		unsigned char Byte1;
	}AsBytes;
};

union DWORD_DEF1
{
	unsigned long AsULong;
	long AsLong;
	struct
	{
		unsigned char Byte0;
		unsigned char Byte1;
		unsigned char Byte2;
		unsigned char Byte3;
	}AsBytes;
	struct
	{
		union WORD_DEF1 Word0;
		union WORD_DEF1 Word1;
	}AsWords;
};

struct Date
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Week;
};

struct Time
{
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
};

struct DATETIME
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Week;
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
};
struct DATA_TIME
{
  unsigned char Year;
  unsigned char Month;
  unsigned char Day;
  unsigned char Hour;
  unsigned char Min;
  unsigned char Sec;
};
 


 
int BCD2Byte(unsigned char src_data, unsigned char *dest_data);



 
 
 
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
 




 






















 




 














































 




























    
#line 8 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/eeprom.h"
   








 
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 
 

 















































 

 

 


 


 
 
 

 







 

          







 




 






























 






 





















 
 
 
 
 
 
 











 
 
 
 
 
 
 











 
 
 
 
 
 
 












 
 
 
 
 



















 




 



 





























 



























 

 






















                     
















               
 


















































 













 
 
 
 
 







 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 






 


































 























                                                                                                               








 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 
 


 





























































                                                                                                            
 

 




 
 
















































 
















 



  
#line 9 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"
  









#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defmcro.h"
  








#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 



union BYTE_DEF
{
    struct {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
    } bit;
    unsigned char   byte;
};

 
 
 
union WORD_DEF
{
    struct {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    b12:1;
        char    b13:1;
        char    b14:1;
        char    b15:1;
    } bit;
    struct {
        unsigned char   low;                             
        unsigned char   high;                            
    } byte;
    unsigned short  word;
};

 
 
 
union DWORD_DEF
{
    struct {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    b12:1;
        char    b13:1;
        char    b14:1;
        char    b15:1;
        char    b16:1;
        char    b17:1;
        char    b18:1;
        char    b19:1;
        char    b20:1;
        char    b21:1;
        char    b22:1;
        char    b23:1;
        char    b24:1;
        char    b25:1;
        char    b26:1;
        char    b27:1;
        char    b28:1;
        char    b29:1;
        char    b30:1;
        char    b31:1;
    } bit;
    struct {
        unsigned char   low;                             
        unsigned char   mid;                             
        unsigned char   high;                            
        unsigned char   nc;                              
    } byte;
    unsigned long   dword;
};
 


struct bit_def {
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
};
union byte_def{
	struct bit_def bit;
	char	byte;
};
 
 
 
 
 
 
#pragma ADDRESS		pm0_addr		0004h
union BYTE_DEF	pm0_addr;











 
 
 
#pragma ADDRESS		pm1_addr		0005h
union BYTE_DEF	pm1_addr;










 
 
 
#pragma ADDRESS		cm0_addr		0006h
union BYTE_DEF	cm0_addr;











 
 
 
#pragma ADDRESS		cm1_addr		0007h
union BYTE_DEF	cm1_addr;










 
 
 
#pragma ADDRESS		csr_addr		0008h
union BYTE_DEF	csr_addr;











 
 
 
#pragma ADDRESS		prcr_addr		000Ah
union BYTE_DEF	prcr_addr;








 
 
 
#pragma ADDRESS		dbr_addr		000Bh
union BYTE_DEF	dbr_addr;







 
 
 
#pragma ADDRESS		cm2_addr		000Ch
union BYTE_DEF	cm2_addr;








 
 
 
#pragma ADDRESS		prg2c_addr		0010h
union BYTE_DEF	prg2c_addr;




 
 
 
#pragma ADDRESS		pclkr_addr		0012h
union BYTE_DEF	pclkr_addr;






 
 
 
#pragma ADDRESS		cpsrf_addr		0015h
union BYTE_DEF	cpsrf_addr;




 
 
 
#pragma ADDRESS		rstfr_addr		0018h
union BYTE_DEF	rstfr_addr;










 
 
 
#pragma ADDRESS		vcr1_addr		0019h
union BYTE_DEF	vcr1_addr;




 
 
 
#pragma ADDRESS		vcr2_addr		001Ah
union BYTE_DEF	vcr2_addr;






 
 
 
#pragma ADDRESS		cse_addr		001Bh
union BYTE_DEF	cse_addr;











 
 
 
#pragma ADDRESS		plc0_addr		001Ch
union BYTE_DEF	plc0_addr;









 
 
 
#pragma ADDRESS		pm2_addr		001Eh
union BYTE_DEF	pm2_addr;






 
 
 
#pragma ADDRESS		vwce_addr		0026h
union BYTE_DEF	vwce_addr;




 
 
 
#pragma ADDRESS		vd1ls_addr		0028h
union BYTE_DEF	vd1ls_addr;







 
 
 
#pragma ADDRESS		vw0c_addr		002Ah
union BYTE_DEF	vw0c_addr;







 
 
 
#pragma ADDRESS		vw1c_addr		002Bh
union BYTE_DEF	vw1c_addr;











 
 
 
#pragma ADDRESS		vw2c_addr		002Ch
union BYTE_DEF	vw2c_addr;











 
 
 
#pragma ADDRESS		int7ic_addr		0042h
union BYTE_DEF	int7ic_addr;








 
 
 
#pragma ADDRESS		int6ic_addr		0043h
union BYTE_DEF	int6ic_addr;








 
 
 
#pragma ADDRESS		int3ic_addr		0044h
union BYTE_DEF	int3ic_addr;








 
 
 
#pragma ADDRESS		tb5ic_addr		0045h
union BYTE_DEF	tb5ic_addr;







 
 
 
#pragma ADDRESS		tb4ic_addr		0046h
union BYTE_DEF	tb4ic_addr;







 
 
 
#pragma ADDRESS		u1bcnic_addr	0046h
union BYTE_DEF	u1bcnic_addr;







 
 
 
#pragma ADDRESS		tb3ic_addr		0047h
union BYTE_DEF	tb3ic_addr;







 
 
 
#pragma ADDRESS		u0bcnic_addr	0047h
union BYTE_DEF	u0bcnic_addr;







 
 
 
#pragma ADDRESS		s4ic_addr		0048h
union BYTE_DEF	s4ic_addr;








 
 
 
#pragma ADDRESS		int5ic_addr		0048h
union BYTE_DEF	int5ic_addr;








 
 
 
#pragma ADDRESS		s3ic_addr		0049h
union BYTE_DEF	s3ic_addr;








 
 
 
#pragma ADDRESS		int4ic_addr		0049h
union BYTE_DEF	int4ic_addr;








 
 
 
#pragma ADDRESS		bcnic_addr		004Ah
union BYTE_DEF	bcnic_addr;







 
 
 
#pragma ADDRESS		dm0ic_addr		004Bh
union BYTE_DEF	dm0ic_addr;







 
 
 
#pragma ADDRESS		dm1ic_addr		004Ch
union BYTE_DEF	dm1ic_addr;







 
 
 
#pragma ADDRESS		kupic_addr		004Dh
union BYTE_DEF	kupic_addr;







 
 
 
#pragma ADDRESS		adic_addr		004Eh
union BYTE_DEF	adic_addr;







 
 
 
#pragma ADDRESS		s2tic_addr		004Fh
union BYTE_DEF	s2tic_addr;







 
 
 
#pragma ADDRESS		s2ric_addr		0050h
union BYTE_DEF	s2ric_addr;







 
 
 
#pragma ADDRESS		s0tic_addr		0051h
union BYTE_DEF	s0tic_addr;







 
 
 
#pragma ADDRESS		s0ric_addr		0052h
union BYTE_DEF	s0ric_addr;







 
 
 
#pragma ADDRESS		s1tic_addr		0053h
union BYTE_DEF	s1tic_addr;







 
 
 
#pragma ADDRESS		s1ric_addr		0054h
union BYTE_DEF	s1ric_addr;







 
 
 
#pragma ADDRESS		ta0ic_addr		0055h
union BYTE_DEF	ta0ic_addr;







 
 
 
#pragma ADDRESS		ta1ic_addr		0056h
union BYTE_DEF	ta1ic_addr;







 
 
 
#pragma ADDRESS		ta2ic_addr		0057h
union BYTE_DEF	ta2ic_addr;







 
 
 
#pragma ADDRESS		ta3ic_addr		0058h
union BYTE_DEF	ta3ic_addr;







 
 
 
#pragma ADDRESS		ta4ic_addr		0059h
union BYTE_DEF	ta4ic_addr;







 
 
 
#pragma ADDRESS		tb0ic_addr		005Ah
union BYTE_DEF	tb0ic_addr;







 
 
 
#pragma ADDRESS		tb1ic_addr		005Bh
union BYTE_DEF	tb1ic_addr;







 
 
 
#pragma ADDRESS		tb2ic_addr		005Ch
union BYTE_DEF	tb2ic_addr;







 
 
 
#pragma ADDRESS		int0ic_addr		005Dh
union BYTE_DEF	int0ic_addr;








 
 
 
#pragma ADDRESS		int1ic_addr		005Eh
union BYTE_DEF	int1ic_addr;








 
 
 
#pragma ADDRESS		int2ic_addr		005Fh
union BYTE_DEF	int2ic_addr;








 
 
 
#pragma ADDRESS		dm2ic_addr		0069h
union BYTE_DEF	dm2ic_addr;







 
 
 
#pragma ADDRESS		dm3ic_addr		006Ah
union BYTE_DEF	dm3ic_addr;







 
 
 
#pragma ADDRESS		u5bcnic_addr	006Bh
union BYTE_DEF	u5bcnic_addr;







 
 
 
#pragma ADDRESS		cec1ic_addr		006Bh
union BYTE_DEF	cec1ic_addr;







 
 
 
#pragma ADDRESS		s5tic_addr		006Ch
union BYTE_DEF	s5tic_addr;







 
 
 
#pragma ADDRESS		cec2ic_addr		006Ch
union BYTE_DEF	cec2ic_addr;







 
 
 
#pragma ADDRESS		s5ric_addr		006Dh
union BYTE_DEF	s5ric_addr;







 
 
 
#pragma ADDRESS		u6bcnic_addr	006Eh
union BYTE_DEF	u6bcnic_addr;







 
 
 
#pragma ADDRESS		rtctic_addr		006Eh
union BYTE_DEF	rtctic_addr;







 
 
 
#pragma ADDRESS		s6tic_addr		006Fh
union BYTE_DEF	s6tic_addr;







 
 
 
#pragma ADDRESS		rtccic_addr		006Fh
union BYTE_DEF	rtccic_addr;







 
 
 
#pragma ADDRESS		s6ric_addr		0070h
union BYTE_DEF	s6ric_addr;







 
 
 
#pragma ADDRESS		u7bcnic_addr	0071h
union BYTE_DEF	u7bcnic_addr;







 
 
 
#pragma ADDRESS		pmc0ic_addr		0071h
union BYTE_DEF	pmc0ic_addr;







 
 
 
#pragma ADDRESS		s7tic_addr		0072h
union BYTE_DEF	s7tic_addr;







 
 
 
#pragma ADDRESS		pmc1ic_addr		0072h
union BYTE_DEF	pmc1ic_addr;







 
 
 
#pragma ADDRESS		s7ric_addr		0073h
union BYTE_DEF	s7ric_addr;







 
 
 
#pragma ADDRESS		iicic_addr		007Bh
union BYTE_DEF	iicic_addr;







 
 
 
#pragma ADDRESS		scldaic_addr	007Ch
union BYTE_DEF	scldaic_addr;







 
 
 
#pragma ADDRESS		sar0_addr		0180h
union DWORD_DEF	sar0_addr;





 
 
 
#pragma ADDRESS		dar0_addr		0184h
union DWORD_DEF	dar0_addr;





 
 
 
#pragma ADDRESS		tcr0_addr		0188h
union WORD_DEF	tcr0_addr;




 
 
 
#pragma ADDRESS		dm0con_addr		018Ch
union BYTE_DEF	dm0con_addr;









 
 
 
#pragma ADDRESS		sar1_addr		0190h
union DWORD_DEF	sar1_addr;





 
 
 
#pragma ADDRESS		dar1_addr		0194h
union DWORD_DEF	dar1_addr;





 
 
 
#pragma ADDRESS		tcr1_addr		0198h
union WORD_DEF	tcr1_addr;




 
 
 
#pragma ADDRESS		dm1con_addr		019Ch
union BYTE_DEF	dm1con_addr;









 
 
 
#pragma ADDRESS		sar2_addr		01A0h
union DWORD_DEF	sar2_addr;





 
 
 
#pragma ADDRESS		dar2_addr		01A4h
union DWORD_DEF	dar2_addr;





 
 
 
#pragma ADDRESS		tcr2_addr		01A8h
union WORD_DEF	tcr2_addr;




 
 
 
#pragma ADDRESS		dm2con_addr		01ACh
union BYTE_DEF	dm2con_addr;









 
 
 
#pragma ADDRESS		sar3_addr		01B0h
union DWORD_DEF	sar3_addr;





 
 
 
#pragma ADDRESS		dar3_addr		01B4h
union DWORD_DEF	dar3_addr;





 
 
 
#pragma ADDRESS		tcr3_addr		01B8h
union WORD_DEF	tcr3_addr;




 
 
 
#pragma ADDRESS		dm3con_addr		01BCh
union BYTE_DEF	dm3con_addr;









 
 
 
#pragma ADDRESS		tb01_addr		01C0h
union WORD_DEF	tb01_addr;


 
 
 
#pragma ADDRESS		tb11_addr		01C2h
union WORD_DEF	tb11_addr;


 
 
 
#pragma ADDRESS		tb21_addr		01C4h
union WORD_DEF	tb21_addr;


 
 
 
#pragma ADDRESS		ppwfs1_addr		01C6h
union BYTE_DEF	ppwfs1_addr;






 
 
 
#pragma ADDRESS		tbcs0_addr		01C8h
union BYTE_DEF	tbcs0_addr;











 
 
 
#pragma ADDRESS		tbcs1_addr		01C9h
union BYTE_DEF	tbcs1_addr;







 
 
 
#pragma ADDRESS		tacs0_addr		01D0h
union BYTE_DEF	tacs0_addr;











 
 
 
#pragma ADDRESS		tacs1_addr		01D1h
union BYTE_DEF	tacs1_addr;











 
 
 
#pragma ADDRESS		tacs2_addr		01D2h
union BYTE_DEF	tacs2_addr;







 
 
 
#pragma ADDRESS		pwmfs_addr		01D4h
union BYTE_DEF	pwmfs_addr;






 
 
 
#pragma ADDRESS		tapofs_addr		01D5h
union BYTE_DEF	tapofs_addr;








 
 
 
#pragma ADDRESS		taow_addr		01D8h
union BYTE_DEF	taow_addr;






 
 
 
#pragma ADDRESS		tprc_addr		01DAh
union BYTE_DEF	tprc_addr;




 
 
 
#pragma ADDRESS		tb31_addr		01E0h
union WORD_DEF	tb31_addr;


 
 
 
#pragma ADDRESS		tb41_addr		01E2h
union WORD_DEF	tb41_addr;


 
 
 
#pragma ADDRESS		tb51_addr		01E4h
union WORD_DEF	tb51_addr;


 
 
 
#pragma ADDRESS		ppwfs2_addr		01E6h
union BYTE_DEF	ppwfs2_addr;






 
 
 
#pragma ADDRESS		tbcs2_addr		01E8h
union BYTE_DEF	tbcs2_addr;











 
 
 
#pragma ADDRESS		tbcs3_addr		01E9h
union BYTE_DEF	tbcs3_addr;







 
 
 
#pragma ADDRESS		pmc0con0_addr	01F0h
union BYTE_DEF	pmc0con0_addr;











 
 
 
#pragma ADDRESS		pmc0con1_addr	01F1h
union BYTE_DEF	pmc0con1_addr;








 
 
 
#pragma ADDRESS		pmc0con2_addr	01F2h
union BYTE_DEF	pmc0con2_addr;









 
 
 
#pragma ADDRESS		pmc0con3_addr	01F3h
union BYTE_DEF	pmc0con3_addr;











 
 
 
#pragma ADDRESS		pmc0sts_addr	01F4h
union BYTE_DEF	pmc0sts_addr;











 
 
 
#pragma ADDRESS		pmc0int_addr	01F5h
union BYTE_DEF	pmc0int_addr;











 
 
 
#pragma ADDRESS		pmc0cpc_addr	01F6h
union BYTE_DEF	pmc0cpc_addr;







 
 
 
#pragma ADDRESS		pmc0cpd_addr	01F7h
union BYTE_DEF	pmc0cpd_addr;


 
 
 
#pragma ADDRESS		pmc1con0_addr	01F8h
union BYTE_DEF	pmc1con0_addr;







 
 
 
#pragma ADDRESS		pmc1con1_addr	01F9h
union BYTE_DEF	pmc1con1_addr;





 
 
 
#pragma ADDRESS		pmc1con2_addr	01FAh
union BYTE_DEF	pmc1con2_addr;









 
 
 
#pragma ADDRESS		pmc1con3_addr	01FBh
union BYTE_DEF	pmc1con3_addr;











 
 
 
#pragma ADDRESS		pmc1sts_addr	01FCh
union BYTE_DEF	pmc1sts_addr;








 
 
 
#pragma ADDRESS		pmc1int_addr	01FDh
union BYTE_DEF	pmc1int_addr;








 
 
 
#pragma ADDRESS		ifsr3a_addr		0205h
union BYTE_DEF	ifsr3a_addr;









 
 
 
#pragma ADDRESS		ifsr2a_addr		0206h
union BYTE_DEF	ifsr2a_addr;









 
 
 
#pragma ADDRESS		ifsr_addr		0207h
union BYTE_DEF	ifsr_addr;











 
 
 
#pragma ADDRESS		aier_addr		020Eh
union BYTE_DEF	aier_addr;





 
 
 
#pragma ADDRESS		aier2_addr		020Fh
union BYTE_DEF	aier2_addr;





 
 
 
#pragma ADDRESS		rmad0_addr		0210h
union DWORD_DEF	rmad0_addr;





 
 
 
#pragma ADDRESS		rmad1_addr		0214h
union DWORD_DEF	rmad1_addr;





 
 
 
#pragma ADDRESS		rmad2_addr		0218h
union DWORD_DEF	rmad2_addr;





 
 
 
#pragma ADDRESS		rmad3_addr		021Ch
union DWORD_DEF	rmad3_addr;





 
 
 
#pragma ADDRESS		fmr0_addr		0220h
union BYTE_DEF	fmr0_addr;









 
 
 
#pragma ADDRESS		fmr1_addr		0221h
union BYTE_DEF	fmr1_addr;






 
 
 
#pragma ADDRESS		fmr2_addr		0222h
union BYTE_DEF	fmr2_addr;





 
 
 
#pragma ADDRESS		fmr6_addr		0230h
union BYTE_DEF	fmr6_addr;





 
 
 
#pragma ADDRESS		u0smr4_addr		0244h
union BYTE_DEF	u0smr4_addr;











 
 
 
#pragma ADDRESS		u0smr3_addr		0245h
union BYTE_DEF	u0smr3_addr;








 
 
 
#pragma ADDRESS		u0smr2_addr		0246h
union BYTE_DEF	u0smr2_addr;










 
 
 
#pragma ADDRESS		u0smr_addr		0247h
union BYTE_DEF	u0smr_addr;









 
 
 
#pragma ADDRESS		u0mr_addr		0248h
union BYTE_DEF	u0mr_addr;











 
 
 
#pragma ADDRESS		u0brg_addr		0249h
union BYTE_DEF	u0brg_addr;


 
 
 
#pragma ADDRESS		u0tb_addr		024Ah
union WORD_DEF	u0tb_addr;




 
 
 
#pragma ADDRESS		u0c0_addr		024Ch
union BYTE_DEF	u0c0_addr;











 
 
 
#pragma ADDRESS		u0c1_addr		024Dh
union BYTE_DEF	u0c1_addr;









 
 
 
#pragma ADDRESS		u0rb_addr		024Eh
union WORD_DEF	u0rb_addr;










 
 
 
#pragma ADDRESS		ucon_addr		0250h
union BYTE_DEF	ucon_addr;










 
 
 
#pragma ADDRESS		u1smr4_addr		0254h
union BYTE_DEF	u1smr4_addr;











 
 
 
#pragma ADDRESS		u1smr3_addr		0255h
union BYTE_DEF	u1smr3_addr;








 
 
 
#pragma ADDRESS		u1smr2_addr		0256h
union BYTE_DEF	u1smr2_addr;










 
 
 
#pragma ADDRESS		u1smr_addr		0257h
union BYTE_DEF	u1smr_addr;









 
 
 
#pragma ADDRESS		u1mr_addr		0258h
union BYTE_DEF	u1mr_addr;











 
 
 
#pragma ADDRESS		u1brg_addr		0259h
union BYTE_DEF	u1brg_addr;


 
 
 
#pragma ADDRESS		u1tb_addr		025Ah
union WORD_DEF	u1tb_addr;




 
 
 
#pragma ADDRESS		u1c0_addr		025Ch
union BYTE_DEF	u1c0_addr;











 
 
 
#pragma ADDRESS		u1c1_addr		025Dh
union BYTE_DEF	u1c1_addr;









 
 
 
#pragma ADDRESS		u1rb_addr		025Eh
union WORD_DEF	u1rb_addr;










 
 
 
#pragma ADDRESS		u2smr4_addr		0264h
union BYTE_DEF	u2smr4_addr;











 
 
 
#pragma ADDRESS		u2smr3_addr		0265h
union BYTE_DEF	u2smr3_addr;








 
 
 
#pragma ADDRESS		u2smr2_addr		0266h
union BYTE_DEF	u2smr2_addr;










 
 
 
#pragma ADDRESS		u2smr_addr		0267h
union BYTE_DEF	u2smr_addr;









 
 
 
#pragma ADDRESS		u2mr_addr		0268h
union BYTE_DEF	u2mr_addr;











 
 
 
#pragma ADDRESS		u2brg_addr		0269h
union BYTE_DEF	u2brg_addr;


 
 
 
#pragma ADDRESS		u2tb_addr		026Ah
union WORD_DEF	u2tb_addr;




 
 
 
#pragma ADDRESS		u2c0_addr		026Ch
union BYTE_DEF	u2c0_addr;











 
 
 
#pragma ADDRESS		u2c1_addr		026Dh
union BYTE_DEF	u2c1_addr;











 
 
 
#pragma ADDRESS		u2rb_addr		026Eh
union WORD_DEF	u2rb_addr;










 
 
 
#pragma ADDRESS		s3trr_addr		0270h
union BYTE_DEF	s3trr_addr;


 
 
 
#pragma ADDRESS		s3c_addr		0272h
union BYTE_DEF	s3c_addr;











 
 
 
#pragma ADDRESS		s3brg_addr		0273h
union BYTE_DEF	s3brg_addr;


 
 
 
#pragma ADDRESS		s4trr_addr		0274h
union BYTE_DEF	s4trr_addr;


 
 
 
#pragma ADDRESS		s4c_addr		0276h
union BYTE_DEF	s4c_addr;











 
 
 
#pragma ADDRESS		s4brg_addr		0277h
union BYTE_DEF	s4brg_addr;


 
 
 
#pragma ADDRESS		s34c2_addr		0278h
union BYTE_DEF	s34c2_addr;





 
 
 
#pragma ADDRESS		u5smr4_addr		0284h
union BYTE_DEF	u5smr4_addr;











 
 
 
#pragma ADDRESS		u5smr3_addr		0285h
union BYTE_DEF	u5smr3_addr;








 
 
 
#pragma ADDRESS		u5smr2_addr		0286h
union BYTE_DEF	u5smr2_addr;










 
 
 
#pragma ADDRESS		u5smr_addr		0287h
union BYTE_DEF	u5smr_addr;









 
 
 
#pragma ADDRESS		u5mr_addr		0288h
union BYTE_DEF	u5mr_addr;











 
 
 
#pragma ADDRESS		u5brg_addr		0289h
union BYTE_DEF	u5brg_addr;


 
 
 
#pragma ADDRESS		u5tb_addr		028Ah
union WORD_DEF	u5tb_addr;




 
 
 
#pragma ADDRESS		u5c0_addr		028Ch
union BYTE_DEF	u5c0_addr;











 
 
 
#pragma ADDRESS		u5c1_addr		028Dh
union BYTE_DEF	u5c1_addr;











 
 
 
#pragma ADDRESS		u5rb_addr		028Eh
union WORD_DEF	u5rb_addr;










 
 
 
#pragma ADDRESS		u6smr4_addr		0294h
union BYTE_DEF	u6smr4_addr;











 
 
 
#pragma ADDRESS		u6smr3_addr		0295h
union BYTE_DEF	u6smr3_addr;








 
 
 
#pragma ADDRESS		u6smr2_addr		0296h
union BYTE_DEF	u6smr2_addr;










 
 
 
#pragma ADDRESS		u6smr_addr		0297h
union BYTE_DEF	u6smr_addr;









 
 
 
#pragma ADDRESS		u6mr_addr		0298h
union BYTE_DEF	u6mr_addr;











 
 
 
#pragma ADDRESS		u6brg_addr		0299h
union BYTE_DEF	u6brg_addr;


 
 
 
#pragma ADDRESS		u6tb_addr		029Ah
union WORD_DEF	u6tb_addr;




 
 
 
#pragma ADDRESS		u6c0_addr		029Ch
union BYTE_DEF	u6c0_addr;











 
 
 
#pragma ADDRESS		u6c1_addr		029Dh
union BYTE_DEF	u6c1_addr;











 
 
 
#pragma ADDRESS		u6rb_addr		029Eh
union WORD_DEF	u6rb_addr;










 
 
 
#pragma ADDRESS		u7smr4_addr		02A4h
union BYTE_DEF	u7smr4_addr;











 
 
 
#pragma ADDRESS		u7smr3_addr		02A5h
union BYTE_DEF	u7smr3_addr;








 
 
 
#pragma ADDRESS		u7smr2_addr		02A6h
union BYTE_DEF	u7smr2_addr;










 
 
 
#pragma ADDRESS		u7smr_addr		02A7h
union BYTE_DEF	u7smr_addr;









 
 
 
#pragma ADDRESS		u7mr_addr		02A8h
union BYTE_DEF	u7mr_addr;











 
 
 
#pragma ADDRESS		u7brg_addr		02A9h
union BYTE_DEF	u7brg_addr;


 
 
 
#pragma ADDRESS		u7tb_addr		02AAh
union WORD_DEF	u7tb_addr;




 
 
 
#pragma ADDRESS		u7c0_addr		02ACh
union BYTE_DEF	u7c0_addr;











 
 
 
#pragma ADDRESS		u7c1_addr		02ADh
union BYTE_DEF	u7c1_addr;











 
 
 
#pragma ADDRESS		u7rb_addr		02AEh
union WORD_DEF	u7rb_addr;










 
 
 
#pragma ADDRESS		s00_addr		02B0h
union BYTE_DEF	s00_addr;


 
 
 
#pragma ADDRESS		s0d0_addr		02B2h
union BYTE_DEF	s0d0_addr;










 
 
 
#pragma ADDRESS		s1d0_addr		02B3h
union BYTE_DEF	s1d0_addr;










 
 
 
#pragma ADDRESS		s20_addr		02B4h
union BYTE_DEF	s20_addr;











 
 
 
#pragma ADDRESS		s2d0_addr		02B5h
union BYTE_DEF	s2d0_addr;











 
 
 
#pragma ADDRESS		s3d0_addr		02B6h
union BYTE_DEF	s3d0_addr;











 
 
 
#pragma ADDRESS		s4d0_addr		02B7h
union BYTE_DEF	s4d0_addr;











 
 
 
#pragma ADDRESS		s10_addr		02B8h
union BYTE_DEF	s10_addr;











 
 
 
#pragma ADDRESS		s11_addr		02B9h
union BYTE_DEF	s11_addr;






 
 
 
#pragma ADDRESS		s0d1_addr		02BAh
union BYTE_DEF	s0d1_addr;










 
 
 
#pragma ADDRESS		s0d2_addr		02BBh
union BYTE_DEF	s0d2_addr;










 
 
 
#pragma ADDRESS		tbsr_addr		0300h
union BYTE_DEF	tbsr_addr;






 
 
 
#pragma ADDRESS		ta11_addr		0302h
union WORD_DEF	ta11_addr;


 
 
 
#pragma ADDRESS		ta21_addr		0304h
union WORD_DEF	ta21_addr;


 
 
 
#pragma ADDRESS		ta41_addr		0306h
union WORD_DEF	ta41_addr;


 
 
 
#pragma ADDRESS		invc0_addr		0308h
union BYTE_DEF	invc0_addr;











 
 
 
#pragma ADDRESS		invc1_addr		0309h
union BYTE_DEF	invc1_addr;










 
 
 
#pragma ADDRESS		idb0_addr		030Ah
union BYTE_DEF	idb0_addr;









 
 
 
#pragma ADDRESS		idb1_addr		030Bh
union BYTE_DEF	idb1_addr;









 
 
 
#pragma ADDRESS		dtt_addr		030Ch
union BYTE_DEF	dtt_addr;


 
 
 
#pragma ADDRESS		ictb2_addr		030Dh
union BYTE_DEF	ictb2_addr;


 
 
 
#pragma ADDRESS		pdrf_addr		030Eh
union BYTE_DEF	pdrf_addr;







 
 
 
#pragma ADDRESS		tb3_addr		0310h
union WORD_DEF	tb3_addr;


 
 
 
#pragma ADDRESS		tb4_addr		0312h
union WORD_DEF	tb4_addr;


 
 
 
#pragma ADDRESS		tb5_addr		0314h
union WORD_DEF	tb5_addr;


 
 
 
#pragma ADDRESS		pfcr_addr		0318h
union BYTE_DEF	pfcr_addr;









 
 
 
#pragma ADDRESS		tb3mr_addr		031Bh
union BYTE_DEF	tb3mr_addr;










 
 
 
#pragma ADDRESS		tb4mr_addr		031Ch
union BYTE_DEF	tb4mr_addr;










 
 
 
#pragma ADDRESS		tb5mr_addr		031Dh
union BYTE_DEF	tb5mr_addr;










 
 
 
#pragma ADDRESS		tabsr_addr		0320h
union BYTE_DEF	tabsr_addr;











 
 
 
#pragma ADDRESS		onsf_addr		0322h
union BYTE_DEF	onsf_addr;











 
 
 
#pragma ADDRESS		trgsr_addr		0323h
union BYTE_DEF	trgsr_addr;











 
 
 
#pragma ADDRESS		udf_addr		0324h
union BYTE_DEF	udf_addr;











 
 
 
#pragma ADDRESS		ta0_addr		0326h
union WORD_DEF	ta0_addr;


 
 
 
#pragma ADDRESS		ta1_addr		0328h
union WORD_DEF	ta1_addr;


 
 
 
#pragma ADDRESS		ta2_addr		032Ah
union WORD_DEF	ta2_addr;


 
 
 
#pragma ADDRESS		ta3_addr		032Ch
union WORD_DEF	ta3_addr;


 
 
 
#pragma ADDRESS		ta4_addr		032Eh
union WORD_DEF	ta4_addr;


 
 
 
#pragma ADDRESS		tb0_addr		0330h
union WORD_DEF	tb0_addr;


 
 
 
#pragma ADDRESS		tb1_addr		0332h
union WORD_DEF	tb1_addr;


 
 
 
#pragma ADDRESS		tb2_addr		0334h
union WORD_DEF	tb2_addr;


 
 
 
#pragma ADDRESS		ta0mr_addr		0336h
union BYTE_DEF	ta0mr_addr;











 
 
 
#pragma ADDRESS		ta1mr_addr		0337h
union BYTE_DEF	ta1mr_addr;











 
 
 
#pragma ADDRESS		ta2mr_addr		0338h
union BYTE_DEF	ta2mr_addr;











 
 
 
#pragma ADDRESS		ta3mr_addr		0339h
union BYTE_DEF	ta3mr_addr;











 
 
 
#pragma ADDRESS		ta4mr_addr		033Ah
union BYTE_DEF	ta4mr_addr;











 
 
 
#pragma ADDRESS		tb0mr_addr		033Bh
union BYTE_DEF	tb0mr_addr;










 
 
 
#pragma ADDRESS		tb1mr_addr		033Ch
union BYTE_DEF	tb1mr_addr;










 
 
 
#pragma ADDRESS		tb2mr_addr		033Dh
union BYTE_DEF	tb2mr_addr;










 
 
 
#pragma ADDRESS		tb2sc_addr		033Eh
union BYTE_DEF	tb2sc_addr;





 
 
 
#pragma ADDRESS		rtcsec_addr		0340h
union BYTE_DEF	rtcsec_addr;











 
 
 
#pragma ADDRESS		rtcmin_addr		0341h
union BYTE_DEF	rtcmin_addr;










 
 
 
#pragma ADDRESS		rtchr_addr		0342h
union BYTE_DEF	rtchr_addr;









 
 
 
#pragma ADDRESS		rtcwk_addr		0343h
union BYTE_DEF	rtcwk_addr;






 
 
 
#pragma ADDRESS		rtccr1_addr		0344h
union BYTE_DEF	rtccr1_addr;









 
 
 
#pragma ADDRESS		rtccr2_addr		0345h
union BYTE_DEF	rtccr2_addr;










 
 
 
#pragma ADDRESS		rtccsr_addr		0346h
union BYTE_DEF	rtccsr_addr;








 
 
 
#pragma ADDRESS		rtccsec_addr	0348h
union BYTE_DEF	rtccsec_addr;










 
 
 
#pragma ADDRESS		rtccmin_addr	0349h
union BYTE_DEF	rtccmin_addr;










 
 
 
#pragma ADDRESS		rtcchr_addr		034Ah
union BYTE_DEF	rtcchr_addr;










 
 
 
#pragma ADDRESS		cecc1_addr		0350h
union BYTE_DEF	cecc1_addr;






 
 
 
#pragma ADDRESS		cecc2_addr		0351h
union BYTE_DEF	cecc2_addr;











 
 
 
#pragma ADDRESS		cecc3_addr		0352h
union BYTE_DEF	cecc3_addr;







 
 
 
#pragma ADDRESS		cecc4_addr		0353h
union BYTE_DEF	cecc4_addr;











 
 
 
#pragma ADDRESS		cecflg_addr		0354h
union BYTE_DEF	cecflg_addr;











 
 
 
#pragma ADDRESS		cisel_addr		0355h
union BYTE_DEF	cisel_addr;











 
 
 
#pragma ADDRESS		cctb1_addr		0356h
union BYTE_DEF	cctb1_addr;


 
 
 
#pragma ADDRESS		cctb2_addr		0357h
union BYTE_DEF	cctb2_addr;





 
 
 
#pragma ADDRESS		ccrb1_addr		0358h
union BYTE_DEF	ccrb1_addr;


 
 
 
#pragma ADDRESS		ccrb2_addr		0359h
union BYTE_DEF	ccrb2_addr;






 
 
 
#pragma ADDRESS		cradri1_addr	035Ah
union BYTE_DEF	cradri1_addr;











 
 
 
#pragma ADDRESS		cradri2_addr	035Bh
union BYTE_DEF	cradri2_addr;











 
 
 
#pragma ADDRESS		pur0_addr		0360h
union BYTE_DEF	pur0_addr;











 
 
 
#pragma ADDRESS		pur1_addr		0361h
union BYTE_DEF	pur1_addr;











 
 
 
#pragma ADDRESS		pur2_addr		0362h
union BYTE_DEF	pur2_addr;









 
 
 
#pragma ADDRESS		pcr_addr		0366h
union BYTE_DEF	pcr_addr;








 
 
 
#pragma ADDRESS		nmidf_addr		0369h
union BYTE_DEF	nmidf_addr;






 
 
 
#pragma ADDRESS		pwmcon0_addr	0370h
union BYTE_DEF	pwmcon0_addr;







 
 
 
#pragma ADDRESS		pwmpre0_addr	0372h
union BYTE_DEF	pwmpre0_addr;


 
 
 
#pragma ADDRESS		pwmreg0_addr	0373h
union BYTE_DEF	pwmreg0_addr;


 
 
 
#pragma ADDRESS		pwmpre1_addr	0374h
union BYTE_DEF	pwmpre1_addr;


 
 
 
#pragma ADDRESS		pwmreg1_addr	0375h
union BYTE_DEF	pwmreg1_addr;


 
 
 
#pragma ADDRESS		pwmcon1_addr	0376h
union BYTE_DEF	pwmcon1_addr;







 
 
 
#pragma ADDRESS		cspr_addr		037Ch
union BYTE_DEF	cspr_addr;




 
 
 
#pragma ADDRESS		wdtr_addr		037Dh
union BYTE_DEF	wdtr_addr;


 
 
 
#pragma ADDRESS		wdts_addr		037Eh
union BYTE_DEF	wdts_addr;


 
 
 
#pragma ADDRESS		wdc_addr		037Fh
union BYTE_DEF	wdc_addr;









 
 
 
#pragma ADDRESS		dm2sl_addr		0390h
union BYTE_DEF	dm2sl_addr;










 
 
 
#pragma ADDRESS		dm3sl_addr		0392h
union BYTE_DEF	dm3sl_addr;










 
 
 
#pragma ADDRESS		dm0sl_addr		0398h
union BYTE_DEF	dm0sl_addr;










 
 
 
#pragma ADDRESS		dm1sl_addr		039Ah
union BYTE_DEF	dm1sl_addr;










 
 
 
#pragma ADDRESS		ainrst_addr		03A2h
union BYTE_DEF	ainrst_addr;





 
 
 
#pragma ADDRESS		crcsar_addr		03B4h
union WORD_DEF	crcsar_addr;

















 
 
 
#pragma ADDRESS		crcmr_addr		03B6h
union BYTE_DEF	crcmr_addr;





 
 
 
#pragma ADDRESS		crcd_addr		03BCh
union WORD_DEF	crcd_addr;




 
 
 
#pragma ADDRESS		crcin_addr		03BEh
union BYTE_DEF	crcin_addr;


 
 
 
#pragma ADDRESS		ad0_addr		03C0h
union WORD_DEF	ad0_addr;




 
 
 
#pragma ADDRESS		ad1_addr		03C2h
union WORD_DEF	ad1_addr;




 
 
 
#pragma ADDRESS		ad2_addr		03C4h
union WORD_DEF	ad2_addr;




 
 
 
#pragma ADDRESS		ad3_addr		03C6h
union WORD_DEF	ad3_addr;




 
 
 
#pragma ADDRESS		ad4_addr		03C8h
union WORD_DEF	ad4_addr;




 
 
 
#pragma ADDRESS		ad5_addr		03CAh
union WORD_DEF	ad5_addr;




 
 
 
#pragma ADDRESS		ad6_addr		03CCh
union WORD_DEF	ad6_addr;




 
 
 
#pragma ADDRESS		ad7_addr		03CEh
union WORD_DEF	ad7_addr;




 
 
 
#pragma ADDRESS		adcon2_addr		03D4h
union BYTE_DEF	adcon2_addr;






 
 
 
#pragma ADDRESS		adcon0_addr		03D6h
union BYTE_DEF	adcon0_addr;











 
 
 
#pragma ADDRESS		adcon1_addr		03D7h
union BYTE_DEF	adcon1_addr;










 
 
 
#pragma ADDRESS		da0_addr		03D8h
union BYTE_DEF	da0_addr;


 
 
 
#pragma ADDRESS		da1_addr		03DAh
union BYTE_DEF	da1_addr;


 
 
 
#pragma ADDRESS		dacon_addr		03DCh
union BYTE_DEF	dacon_addr;





 
 
 
#pragma ADDRESS		p0_addr			03E0h
union BYTE_DEF	p0_addr;











 
 
 
#pragma ADDRESS		p1_addr			03E1h
union BYTE_DEF	p1_addr;











 
 
 
#pragma ADDRESS		pd0_addr		03E2h
union BYTE_DEF	pd0_addr;











 
 
 
#pragma ADDRESS		pd1_addr		03E3h
union BYTE_DEF	pd1_addr;











 
 
 
#pragma ADDRESS		p2_addr			03E4h
union BYTE_DEF	p2_addr;











 
 
 
#pragma ADDRESS		p3_addr			03E5h
union BYTE_DEF	p3_addr;











 
 
 
#pragma ADDRESS		pd2_addr		03E6h
union BYTE_DEF	pd2_addr;











 
 
 
#pragma ADDRESS		pd3_addr		03E7h
union BYTE_DEF	pd3_addr;











 
 
 
#pragma ADDRESS		p4_addr			03E8h
union BYTE_DEF	p4_addr;











 
 
 
#pragma ADDRESS		p5_addr			03E9h
union BYTE_DEF	p5_addr;











 
 
 
#pragma ADDRESS		pd4_addr		03EAh
union BYTE_DEF	pd4_addr;











 
 
 
#pragma ADDRESS		pd5_addr		03EBh
union BYTE_DEF	pd5_addr;











 
 
 
#pragma ADDRESS		p6_addr			03ECh
union BYTE_DEF	p6_addr;











 
 
 
#pragma ADDRESS		p7_addr			03EDh
union BYTE_DEF	p7_addr;











 
 
 
#pragma ADDRESS		pd6_addr		03EEh
union BYTE_DEF	pd6_addr;











 
 
 
#pragma ADDRESS		pd7_addr		03EFh
union BYTE_DEF	pd7_addr;











 
 
 
#pragma ADDRESS		p8_addr			03F0h
union BYTE_DEF	p8_addr;











 
 
 
#pragma ADDRESS		p9_addr			03F1h
union BYTE_DEF	p9_addr;











 
 
 
#pragma ADDRESS		pd8_addr		03F2h
union BYTE_DEF	pd8_addr;











 
 
 
#pragma ADDRESS		pd9_addr		03F3h
union BYTE_DEF	pd9_addr;











 
 
 
#pragma ADDRESS		p10_addr		03F4h
union BYTE_DEF	p10_addr;











 
 
 
#pragma ADDRESS		pd10_addr		03F6h
union BYTE_DEF	pd10_addr;











 
 
 
#pragma ADDRESS		pmc0hdpmin_addr	0D080h
union WORD_DEF	pmc0hdpmin_addr;


 
 
 
#pragma ADDRESS		pmc0hdpmax_addr	0D082h
union WORD_DEF	pmc0hdpmax_addr;


 
 
 
#pragma ADDRESS		pmc0d0pmin_addr	0D084h
union BYTE_DEF	pmc0d0pmin_addr;


 
 
 
#pragma ADDRESS		pmc0d0pmax_addr	0D085h
union BYTE_DEF	pmc0d0pmax_addr;


 
 
 
#pragma ADDRESS		pmc0d1pmin_addr	0D086h
union BYTE_DEF	pmc0d1pmin_addr;


 
 
 
#pragma ADDRESS		pmc0d1pmax_addr	0D087h
union BYTE_DEF	pmc0d1pmax_addr;


 
 
 
#pragma ADDRESS		pmc0tim_addr	0D088h
union WORD_DEF	pmc0tim_addr;


 
 
 
#pragma ADDRESS		pmc0bc_addr		0D08Ah
union WORD_DEF	pmc0bc_addr;


 
 
 
#pragma ADDRESS		pmc0dat0_addr	0D08Ch
union BYTE_DEF	pmc0dat0_addr;


 
 
 
#pragma ADDRESS		pmc0dat1_addr	0D08Dh
union BYTE_DEF	pmc0dat1_addr;


 
 
 
#pragma ADDRESS		pmc0dat2_addr	0D08Eh
union BYTE_DEF	pmc0dat2_addr;


 
 
 
#pragma ADDRESS		pmc0dat3_addr	0D08Fh
union BYTE_DEF	pmc0dat3_addr;


 
 
 
#pragma ADDRESS		pmc0dat4_addr	0D090h
union BYTE_DEF	pmc0dat4_addr;


 
 
 
#pragma ADDRESS		pmc0dat5_addr	0D091h
union BYTE_DEF	pmc0dat5_addr;


 
 
 
#pragma ADDRESS		pmc0rbit_addr	0D092h
union BYTE_DEF	pmc0rbit_addr;


 
 
 
#pragma ADDRESS		pmc1hdpmin_addr	0D094h
union WORD_DEF	pmc1hdpmin_addr;


 
 
 
#pragma ADDRESS		pmc1hdpmax_addr	0D096h
union WORD_DEF	pmc1hdpmax_addr;


 
 
 
#pragma ADDRESS		pmc1d0pmin_addr	0D098h
union BYTE_DEF	pmc1d0pmin_addr;


 
 
 
#pragma ADDRESS		pmc1d0pmax_addr	0D099h
union BYTE_DEF	pmc1d0pmax_addr;


 
 
 
#pragma ADDRESS		pmc1d1pmin_addr	0D09Ah
union BYTE_DEF	pmc1d1pmin_addr;


 
 
 
#pragma ADDRESS		pmc1d1pmax_addr	0D09Bh
union BYTE_DEF	pmc1d1pmax_addr;


 
 
 
#pragma ADDRESS		pmc1tim_addr	0D09Ch
union WORD_DEF	pmc1tim_addr;


 
 
 
#pragma ADDRESS		pmc1bc_addr		0D09Eh
union WORD_DEF	pmc1bc_addr;



 
#line 10 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defmcro.h"

 
 


 



 	 






 


 




















































































 

 


 

 
 



    

 






			








		








	
	
	








	
	
	








	
	
	








	
	
	








	
	
	

















	                        
	
 





















































 

   












 
 

















































































 
 
 
 






 

















































 
                            
                            
                        
#line 11 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/eventdatadef.h"



struct  BREAKPHASE_DATA    
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};            
           
struct  LOSTVOLTAGE_DATA               
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][6];  
        unsigned long amph[3];       
};
          
struct  TOTALLOSTVOLTAGE_DATA  
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  LOSTCURRENT_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][6];  
};
          
struct  TOTALLOSTCURRENT_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  POWERREVERSE_DATA              
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[4][2];  
};

	           
struct  VOLTAGECHECK_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char  voltage[3];
};

struct CURRENTIMBALANCE_DATA
{
	    unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned long energy[2];  
};          
     
struct  OVERPOWERALARM_DATA             
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char power[3];
};

struct  OVERPOWERCLOSESWITCH_DATA        
{
        unsigned char begindate[5];
        unsigned char power[3];
};

struct  OVERVISUALPOWER_DATA             
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
        unsigned char power[3];
};

struct  ENERGYCLEAR_DATA                 
{
        unsigned char begindate[5];
        unsigned long energy[6][9];
        
};

struct  DEMANDCLEAR_DATA                 
{
        unsigned char begindate[5];
        unsigned long demand[4];   
        unsigned char demandtime[4][5]; 
        unsigned char flag;
};

struct  LOSSVOLTAGELOSSCURRENTCLEAR_DATA 
{
        unsigned char begindate[5];
};

struct  LOSSVOLTAGECHECKHEALTHCLEAR_DATA 
{
        unsigned char begindate[5];
};

struct  UPDAWNPOWER_DATA                 
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  RESETCPU_DATA                    
{
        unsigned char begindate[5];
};

struct  SETPRIMARY_DATA                  
{
        unsigned char begindate[5];
        unsigned long energy[9        ];  
        unsigned long energy1[9        ];  
        unsigned char mode;
};
struct SETREACTIVEPRIMARY_DATA
{
        unsigned char begindate[5];
        unsigned long energy[4]; 
};

struct  PROGRAMME_DATA                  
{
        unsigned char begindate[5];
        unsigned char flag1;
        unsigned char flag2;
};

struct  OPENUPCOVER_DATA                               
{
        unsigned char begindate[5];
};

struct  CLOCKBATTERY_DATA               
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  DISPLAYBATTERY_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  ADJUSTCLOCK_DATA              
{
        unsigned char beforedate[5];
        unsigned char afterdate[5];
        
};

struct  RUNCLOCKERROR_DATA              
{
        unsigned char begindate[5];
        unsigned char beforedate[5];
        unsigned char flag;
};

struct  POWERUPCLOCKERROR_DATA          
{
        unsigned char begindate[5];
        unsigned char beforedate[5];
        unsigned char flag;
};

struct  ADJUSTENERGY_DATA             
{
        unsigned char begindate[5];
        unsigned char flag;
        unsigned long energy[2][6][9        ];
};

struct  EEPROMERR_DATA                   
{
        unsigned char begindate[5];
        unsigned char flag;
};

struct  ADJUSTMETER_DATA  
{
        unsigned char begindate[5];
        unsigned char flag;
};
struct  VOLTAGERESERVE_DATA            
{
        unsigned char begindate[5];
        unsigned char stopdate[5];
};

struct  FREEZEDATA_SD_DATA
{
	   unsigned char begindate[5];
	   unsigned long energy[6];
};
struct  FREEZEDATA_ZhiDing_DATA   
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};
struct  FREEZEDATA_ShunShi_DATA   
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};
struct  FREEZEDATA_YueDing_DATA   
{
	unsigned long  Plus_Active[5]; 
	unsigned long  Nega_Active[5];
	unsigned int   Volt[3];
	unsigned int   Curr[3];
	unsigned char  Active_power[4][3];
	unsigned int   Reactive_power[4];
	unsigned int   Factor[4];    
	unsigned int   Freq;  
	unsigned int   Phase_Angle[4];
	unsigned long  Quad_Reactive[4][5];
	unsigned char  date[5];
};

 
 
struct LostVoltageEvent_Data
{
	unsigned long beginvolt[3];
	signed long begincurr[3];
	signed long beginactivepower[3];
	signed long beginreactivepower[3];
	signed long beginfactor[3];
	unsigned long eventenergy[4][6];
	unsigned long eventamph[3];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct LostVoltageCard_Data
{
	struct LostVoltageEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
 

 
struct PowerDownEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];	
};
 

 
struct ProgrammeEvent_Data
{
	unsigned char begintime[6];
	unsigned long mancode;
	unsigned long datacode[10];	
};
 

 
struct OpenCoverEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long beginenergy[6];
	unsigned long endenergy[6];	
};
 

 
struct VoltStatistic_Data
{
	unsigned long checktime[4];   
	unsigned long checkvolt[2];   
	unsigned char checkvolttime[2][6];   
	unsigned long voltratebcd[2];   
	unsigned int  checkvoltbcd[2];   
};
 

 
struct LostCurrentEvent_Data
{
	unsigned long beginvolt[3];
	signed long begincurr[3];
	signed long beginactivepower[3];
	signed long beginreactivepower[3];
	signed long beginfactor[3];
	unsigned long eventenergy[4][6];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct LostCurrentCard_Data
{
	struct LostCurrentEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
 

 
struct VoltReverseEvent_Data
{
	unsigned long eventenergy[4][6];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};

struct VoltReverseCard_Data
{
	struct VoltReverseEvent_Data eventdata;
	unsigned char passzerotimes[6];
	unsigned char eventcs;	
};
 

 
struct OverDemandEvent_Data
{
	unsigned long maxdemand;
	unsigned char maxdemandtime[5];
	unsigned char endtime[6];
	unsigned char begintime[6];	
};
 
 
struct Phase3LostVoltEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	signed long begincurr;	
};
 
 
struct OverDemandAlarmEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long begindemand[2];	
};
 
 
struct ClockBatteryEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];	
};
 
 
struct CurrImBalanceEvent_Data
{
	unsigned char begintime[6];
	unsigned char endtime[6];
	unsigned long eventenergy[4][6];
	unsigned long maximbalancerate;	
};

struct CurrImBalanceCard_Data
{
	unsigned char passzerotimes[6];
	struct CurrImBalanceEvent_Data eventdata;
	unsigned char eventcs;	
};
 
 

 
#line 12 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/eventnew.h"
  





typedef unsigned char (*TSave_General_Event)(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char *tempdatep);
typedef unsigned char (*TSpec_Event)(unsigned int Card_Addr,		 
							 		unsigned char *DataPointer,	 
						 	 		unsigned int Data_Length,		 
						 	 		unsigned char DeviceName,		 
						 	 		unsigned char OperationType);
typedef unsigned char (*TGeneral_Event)(unsigned int eeprom_addr,unsigned int event_filename,unsigned char event_adjusteflag,unsigned char storekind);
extern unsigned  char Clear_Demand_Mode;
 
extern unsigned char EventEnergyValid_Flag;
extern unsigned long Event_AmpHour[3];
extern unsigned char EventCriticalVoltage_Flag;
extern unsigned char TempEventData[400];
extern unsigned long lostvoltenergyall[2];
extern unsigned long lostvoltenergy[6];
 
 
 

 
 
extern void EventTimeAdd(void);
 
 
extern void New2007_Event(void);
extern void EventRecordAdjustEnergy(void);
extern void EventData_PowerDown_Save(void);
extern unsigned char EventData_PowerOn_Check(void);
extern unsigned char EventRecord_Poweron_Check(void);
extern void PowerDownEvent_OnCheck(void);
extern unsigned int ProgrammeEvent(unsigned long,unsigned long);
extern unsigned int ClearMeterRecord(unsigned long);
 
extern void VoltStatSetDefault(void);
extern void VoltStatInit(void);
extern void VoltStatisticCheck(void);
extern void OverDemandEvent(void);
extern unsigned int AdjustTimeRecord(unsigned long);
extern unsigned int ClearDemandRecord(unsigned long);
extern unsigned int ProgWeekRecord(unsigned long,unsigned char);
extern unsigned int ProgAEModeRecord(unsigned long,unsigned char);
extern unsigned int ProgNEMode1Record(unsigned long,unsigned char);
extern unsigned int ProgNEMode2Record(unsigned long,unsigned char);
extern unsigned int ProgBillDayRecord(unsigned long,unsigned char *);
extern unsigned int ProgYearSlotRecord(unsigned long);
extern unsigned int ProgDailySlotRecord(unsigned long);
 
extern unsigned char ClearNewEventRecord(unsigned long,unsigned long);
 
extern int   PrepVoltStatReadData(void);
extern void ResetCpuEvent_OnCheck(void);
extern void RunClockErrorRecord(void);
extern void PowerUpClockErrorRecord(void);
extern void EepromErrorRecord(void);
extern void EnergyPassZeroRecord(void);
 
extern void SetPrimaryRecord(void);
extern void EepromEventSetDefault(void);
 
 
extern void EMeterPowerdownRecord(void);
extern unsigned int ClearEventRecord(unsigned long,unsigned long);
extern unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,
															unsigned char  progoldvaluep,unsigned char sort);
extern void OpenBoxCoverEvent_Check(void);
extern void EventFlagPowerOnInit(void);
extern void ProgrammeEventEnd_Check_Payment(void);
extern void ProgrammeEventEnd_Check(void);
extern void VoltStatisticFunc(void);
extern void AdjustMeterRecord(void);
extern unsigned char PrepNewFirstEventData(unsigned long);
extern unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times);
extern unsigned long  Prepare_For_EventLastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer);
 
extern void Refresh_EventData(unsigned long eventcode);
extern unsigned char Refresh_AddTime(unsigned long eventcode);
extern void ClearEventDate_BatteryPowerOn(void);
extern int PrepLostVoltEnergyData(unsigned long);

extern void PowerAbnormalEventCheck(void);

extern void ClockBatteryDisplayBattery_Event(void);

extern void PdOpenCoverCheckInit(unsigned char);
extern void PdOpenCoverCheck(void);
extern void PdOpenCoverCheckPowerUpDeal(void);

extern void ClearEventAll(void);
extern void ClearEventCommDeal(unsigned long eventID);
extern void ClearEventDataPowerOn(void);
extern void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file);

 

extern union  BYTE_BIT VoltCheck_N[3][2];
extern struct VoltStatistic_Data VoltStat[4];
 
 
 
extern const unsigned long Clearevent_ID[74];

extern struct	PDOPENCOVER_STRUCTURE  pdopencovercheckdata[2];

extern union EVENTSTATUS eventstatusinfo;

extern unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times);

 

 
#line 13 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/MB_Base_fun.h"














































































 
 
 
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
 




 






















 




 














































 




























    
#line 14 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"


 
struct BIT
{
       unsigned char b0:1;
       unsigned char b1:1;
       unsigned char b2:1;
       unsigned char b3:1;
       unsigned char b4:1;
       unsigned char b5:1;
       unsigned char b6:1;
       unsigned char b7:1;
};
 
union BYTE_BIT
{
       struct BIT bit;
       unsigned char byte;
};
 
struct  TIME_DEF
{
       unsigned char Hour;
       unsigned char Minute;
       unsigned char Second;
};
 
struct DATE_DEF
{
       unsigned char Year;
       unsigned char Month;
       unsigned char Day;
       unsigned char Week;
};
 
struct DATEANDTIME_DEF
{
       unsigned char Year;
       unsigned char Month;
       unsigned char Day;
       unsigned char Hour;
       unsigned char Min;
       unsigned char Sec;
       unsigned char Week;
};

 
union METERFLAG
{                    
     struct
     {
       unsigned char Eeprom_Err1:1;
       unsigned char Eeprom_Err2:1; 
       unsigned char Eeprom_Err3:1; 
       unsigned char Eeprom_Err4:1; 
       unsigned char Rtc_Err1:1; 
       unsigned char Rtc_Err2:1;  
       unsigned char Battery1_Err:1;		 
       unsigned char Battery2_Err:1;		 
       unsigned char Battery3_Err:1;		 
       unsigned char Energymodule_Err:1;
       unsigned char Comm_Module_Err:1; 
       unsigned char Boad_Module_Err:1;		 
       unsigned char Ic_Card_Err:1; 
       
       unsigned char Eeprom_Data_Err:1;
       unsigned char Timer_Data_Err:1;  
       unsigned char Parameter_Data_Err:1; 
       unsigned char Ic_Card_Data_Err:1; 
       unsigned char Boad_Data_Err:1;

      }bit;
      unsigned int  intd; 
};


union ERR_INFORM_FLG
{
	struct
	{
		unsigned char Eeprom_Err:1;
		unsigned char Eeprom_Data_Err:1;
		unsigned char BatteryClK_Err:1;
		unsigned char BatteryDIS_Err:1;
		unsigned char VoltageReserve:1;
		unsigned char LossVoltage:1;
		unsigned char OverVoltage:1;
		unsigned char LossCurrent:1;
		unsigned char :1;
		unsigned char BreakPhase:1;
		unsigned char :1;
		unsigned char OverPower:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char Rtc_Err:1;
	}bit;
	unsigned int intd;
};
 
 
 
union NEW645METERSTATUS1
{
       struct
       {
       unsigned char :1; 
       unsigned char Demand_Mode:1;
       unsigned char Battery1_Status:1;
       unsigned char Battery2_Status:1;
       unsigned char ActivePower_Direct:1;
       unsigned char ReActivePower_Direct:1;
       unsigned char :1;
       unsigned char :1;

       unsigned char CtrCircleErr:1;	 
       unsigned char EsamErr:1;		 
       unsigned char B10:1;
       unsigned char B11:1;
       unsigned char ProgrammeErr:1;
       unsigned char EepromErr:1;
       unsigned char Overdraft:1;		 
       unsigned char ClockErr:1;	   
       }bit;
       unsigned int  intd;                                          
}; 
 

union NEW645METERSTATUS2
{
     struct
     {
       unsigned char ActiveDirection_A:1;	
       unsigned char ActiveDirection_B:1;
       unsigned char ActiveDirection_C:1;
       unsigned char :1;
       unsigned char ReactiveDirection_A:1;
       unsigned char ReactiveDirection_B:1;
       unsigned char ReactiveDirection_C:1;              
       unsigned char :1;   

       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;		   
     }bit;
     unsigned int  intd;                               
};
 
union NEW645METERSTATUS3
{
     struct
       {
       unsigned char WhitchDialySlotIsNow:1;
       unsigned char Power_Mode1:1;
       unsigned char Power_Mode2:1;
       unsigned char Program_Allow:1;	 
       unsigned char Relay_Status:1;
       unsigned char WhitchSlotIsNow:1;
       unsigned char SwitchCommandStatus:1;    	 
       unsigned char SwitchAlarmStatus:1; 

       unsigned char MeterType_L:1;
       unsigned char MeterType_H:1;
       unsigned char WhitchTriffIsNow:1;
       unsigned char WhitchStepIsNow:1;
       unsigned char keep_power_status:1;    
       unsigned char Identity_Flg:1;			 
       unsigned char local_open_account:1;   
       unsigned char far_open_account:1;	    
       }bit;
       unsigned int  intd;                    
};
 
 
union NEW645METERSTATUS4
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
 
union NEW645METERSTATUS5
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
 
union NEW645METERSTATUS6
{
     struct
       {
       unsigned char LossVoltage:1;
       unsigned char FailVoltage:1;
       unsigned char OverVoltage:1;
       unsigned char LossCurrent:1;
       unsigned char OverCurrent:1;
       unsigned char OverLoad:1;
       unsigned char TideWay:1;              
       unsigned char BreakPhase:1; 

       unsigned char BreakCurrent:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
 
union NEW645METERSTATUS7
{
     struct
       {
       unsigned char VoltagePhaseRevers:1;
       unsigned char CurrentPhaseReverse:1;
       unsigned char VoltageImbalance:1;
       unsigned char CurrentImbalance:1;
       unsigned char AuxiliaryPower:1;
       unsigned char PowerDown:1;
       unsigned char OverDemand:1;              
       unsigned char OverFactor:1; 

       unsigned char CurrentGraveImbalance:1;
       unsigned char OpenCover:1;
       unsigned char OpenBox:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;	   
       }bit;
       unsigned int  intd;                    
};
 



 

 
union METERSTATUS1
{
       struct
       {
       unsigned char Bill_Mode:1;
       unsigned char Demand_Mode:1;
       unsigned char Battery_Status:1;
       unsigned char :1;
       unsigned char ActivePower_Direct:1;
       unsigned char ReActivePower_Direct:1;
       unsigned char :1;
       unsigned char :1;
       }bit;
       unsigned char byte;                                          
};  
 
 
union METERSTATUS2
{
     struct
     {
       unsigned char ActiveDirection_A:1;	
       unsigned char ActiveDirection_B:1;
       unsigned char ActiveDirection_C:1;
       unsigned char ActiveDirection_T:1;
       unsigned char ReactiveDirection_A:1;
       unsigned char ReactiveDirection_B:1;
       unsigned char ReactiveDirection_C:1;              
       unsigned char ReactiveDirection_T:1;       
     }bit;
     unsigned char byte;                               
};
   
 
union METERSTATUS3
{
     struct
       {
       unsigned char CurrentPhaseReverse:1;
       unsigned char VoltagePhaseRevers:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char LossCurrent_A:1;
       unsigned char LossCurrent_B:1;
       unsigned char LossCurrent_C:1;              
       unsigned char :1; 
       }bit;
       unsigned char byte;                    
};
 
 
union METERSTATUS4
{
    struct
      {
       unsigned char OverPower_Alarm:1;
       unsigned char OverPower_SwitchOff:1;
       unsigned char LowClockBattery:1;
       unsigned char :1;
       unsigned char OweFee_Alarm:1;
       unsigned char OweFee_SwitchOff:1;
       unsigned char LowBattery:1;              
       unsigned char :1;
      }bit;
      unsigned char byte;                                 
};
 
 
union METERSTATUS5
{
     struct
      { 
       unsigned char Cover_Open:1;
       unsigned char IC_Insert:1;
       unsigned char Cal_Meter:1;
       unsigned char Set_Parameter:1;
       unsigned char Selftest_Pass:1;
       unsigned char Powerup:1;     
       unsigned char :1;              
       unsigned char :1;
      }bit;
     unsigned char byte;                                 
};
   
 
union POWERNETSTATUS
{
      struct
      {
       unsigned char BreakPhase_A:1;
       unsigned char BreakPhase_B:1;
       unsigned char BreakPhase_C:1;
       unsigned char :1;
       unsigned char OverVoltage_A:1;
       unsigned char OverVoltage_B:1;
       unsigned char OverVoltage_C:1;
       unsigned char :1;
      }bit;
     unsigned char byte;                       
}; 
 

 
union EVENT_REPORT_MODE
{
      struct
      {
       unsigned char Switch_err:1; 
       unsigned char ESAM_err:1; 
       unsigned char Eeprom_init_err:1; 
       unsigned char Clock_Battery_Volt_low:1; 
       unsigned char Code_err:1; 
       unsigned char Memorizer_err:1; 
       unsigned char :1; 
       unsigned char Clock_err:1; 

	unsigned char LowPower_Battery_Volt_low:1; 
       unsigned char Overdraft:1; 
       unsigned char Open_Meter_Cover:1; 
       unsigned char Open_Rail_Cover:1; 
       unsigned char ConstantMagnet_event:1; 
       unsigned char PowerAbnormal_event:1; 
       unsigned char Switch_off:1; 
       unsigned char Switch_on:1; 

	unsigned char LostVolt:1; 
       unsigned char LowVolt:1; 
       unsigned char OverVolt:1; 
       unsigned char LossCurr:1; 
       unsigned char OverCurr:1; 
       unsigned char UpLoad:1; 
       unsigned char PowerReserve:1; 
       unsigned char BreakPhase:1; 

	unsigned char BreakCurr:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

	unsigned char VoltReverse:1; 
       unsigned char CurrReverse:1; 
       unsigned char VoltImbalance:1; 
       unsigned char CurrImbalance:1; 
       unsigned char AuxiliaryPower_event:1; 
       unsigned char PowerDown:1; 
       unsigned char OverDemand:1; 
       unsigned char Factor_Low:1; 

	unsigned char CurrCriticalImbalance:1; 
       unsigned char TotalPowerReverse:1; 
       unsigned char AllLostVoltage:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

       unsigned char Program_event:1; 
       unsigned char Meter_clear:1; 
       unsigned char Demand_clear:1; 
       unsigned char Event_clear:1; 
       unsigned char AdjustTime_event:1; 
       unsigned char ProgDailySlot:1; 
       unsigned char ProgYearSlot:1; 
       unsigned char ProgWeek:1; 

       unsigned char ProgHoliday:1; 
       unsigned char ProgAEMode:1; 
       unsigned char ProgNEMode1:1; 
       unsigned char ProgNEMode2:1; 
       unsigned char ProgBillDay:1; 
       unsigned char ProgTriffPrice:1; 
       unsigned char ProgStepPrice:1; 
       unsigned char PSWUpdate:1; 
      }bit;
	  
     unsigned char byte[8];                       
}; 

 
union EVENT_REPORT_STATUS
{
      struct
      {
       unsigned char Switch_err:1; 
       unsigned char ESAM_err:1; 
       unsigned char Eeprom_init_err:1; 
       unsigned char Clock_Battery_Volt_low:1; 
       unsigned char Code_err:1; 
       unsigned char Memorizer_err:1; 
       unsigned char :1; 
       unsigned char Clock_err:1; 

	unsigned char LowPower_Battery_Volt_low:1; 
       unsigned char Overdraft:1; 
       unsigned char Open_Meter_Cover:1; 
       unsigned char Open_Rail_Cover:1; 
       unsigned char ConstantMagnet_event:1; 
       unsigned char PowerAbnormal_event:1; 
       unsigned char Switch_off:1; 
       unsigned char Switch_on:1; 

	unsigned char LostVolt_A:1; 
       unsigned char LowVolt_A:1; 
       unsigned char OverVolt_A:1; 
       unsigned char LossCurr_A:1; 
       unsigned char OverCurr_A:1; 
       unsigned char UpLoad_A:1; 
       unsigned char PowerReserve_A:1; 
       unsigned char BreakPhase_A:1; 

	unsigned char BreakCurr_A:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

	unsigned char LostVolt_B:1; 
       unsigned char LowVolt_B:1; 
       unsigned char OverVolt_B:1; 
       unsigned char LossCurr_B:1; 
       unsigned char OverCurr_B:1; 
       unsigned char UpLoad_B:1; 
       unsigned char PowerReserve_B:1; 
       unsigned char BreakPhase_B:1; 

	unsigned char BreakCurr_B:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

	unsigned char LostVolt_C:1; 
       unsigned char LowVolt_C:1; 
       unsigned char OverVolt_C:1; 
       unsigned char LossCurr_C:1; 
       unsigned char OverCurr_C:1; 
       unsigned char UpLoad_C:1; 
       unsigned char PowerReserve_C:1; 
       unsigned char BreakPhase_C:1; 

	unsigned char BreakCurr_C:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

	unsigned char VoltReverse:1; 
       unsigned char CurrReverse:1; 
       unsigned char VoltImbalance:1; 
       unsigned char CurrImbalance:1; 
       unsigned char auxiliaryPower_event:1; 
       unsigned char PowerDown:1; 
       unsigned char OverDemand:1; 
       unsigned char Factor_Low:1; 

	unsigned char CurrCriticalImbalance:1; 
       unsigned char TotalPowerReverse:1; 
       unsigned char AllLostVoltage:1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 
       unsigned char :1; 

       unsigned char Program_event:1; 
       unsigned char Meter_clear:1; 
       unsigned char Demand_clear:1; 
       unsigned char Event_clear:1; 
       unsigned char AdjustTime_event:1; 
       unsigned char ProgDailySlot:1; 
       unsigned char ProgYearSlot:1; 
       unsigned char ProgWeek:1; 

       unsigned char ProgHoliday:1; 
       unsigned char ProgAEMode:1; 
       unsigned char ProgNEMode1:1; 
       unsigned char ProgNEMode2:1; 
       unsigned char ProgBillDay:1; 
       unsigned char ProgTriffPrice:1; 
       unsigned char ProgStepPrice:1; 
       unsigned char PSWUpdate:1; 
      }bit;
	  
     unsigned char byte[12];                       
}; 
 
union WEEKSTATUS
{
      struct
      {
       unsigned char Su:1;
       unsigned char Mo:1;
       unsigned char Tu:1;
       unsigned char We:1;
       unsigned char Th:1;
       unsigned char Fr:1;
       unsigned char Sa:1;
       unsigned char :1;
       
      }bit;
     unsigned char byte;  
};
 
 
union COMMRATE
{
     struct
       {
        unsigned char :1; 
        unsigned char B600:1;
	      unsigned char B1200:1;
        unsigned char B2400:1;
        unsigned char B4800:1;
        unsigned char B9600:1;
        unsigned char B19200:1;
	      unsigned char :1;
       }bit;
       unsigned char byte;
};
 
 
union ERRORINFORMATION
{
    struct
      {  
      	unsigned char Invalid_Data:1; 
      	unsigned char Invalid_OBIS:1; 
      	unsigned char Invalid_Password:1; 
        unsigned char Invalid_COMMRATE:1; 
        unsigned char OutYearZone:1; 
        unsigned char OutDailySlot:1;
        unsigned char OutTriff:1;
        unsigned char:1;
      }bit;
      unsigned char byte;  
}; 

 
 
struct METER_STATES
{
        union METERFLAG         Meter_Flag;
        union METERSTATUS1      Meter_Status1;
        union METERSTATUS2      Meter_Status2;
        union METERSTATUS3      Meter_Status3;
        union METERSTATUS4      Meter_Status4;
        union POWERNETSTATUS    PowerNet_Status;
        union ERRORINFORMATION  ErrOfInformation;
        union WEEKSTATUS        Week_Status;
        union METERSTATUS5      Meter_Status5;
        union COMMRATE          Comm_Rate[3];
        
        union BYTE_BIT          BatteryState;
        union BYTE_BIT          AlarmState;
        
        union ERR_INFORM_FLG    Err_Infor;
};

            
  

struct NEW645METER_STATES
{
        union NEW645METERSTATUS1      Meter_Status1;
        union NEW645METERSTATUS2      Meter_Status2;
        union NEW645METERSTATUS3      Meter_Status3;
        union NEW645METERSTATUS4      Meter_Status4;
        union NEW645METERSTATUS5      Meter_Status5;
        union NEW645METERSTATUS6      Meter_Status6;
        union NEW645METERSTATUS7      Meter_Status7;
        union BYTE_BIT                OpenCoverStates;
        unsigned long psw_status_word;   
};  

   
 
                                                           
 
 
     
 
union EVENT_POWER_NET_FLAG        
{
	struct                       
	{    
		unsigned char LostVoltage_A:1;                      
		unsigned char LostVoltage_B:1;                     
		unsigned char LostVoltage_C:1; 
		unsigned char VoltageReserve:1;
		unsigned char Phase3LostVolt:1;
		unsigned char LostCurrent_A:1;                     
		unsigned char LostCurrent_B:1;    
		unsigned char LostCurrent_C:1;    		
		 
		
		unsigned char BreakPhase_A:1;   
		unsigned char BreakPhase_B:1;         
		unsigned char BreakPhase_C:1;       
		unsigned char VoltageDown_A:1;
		unsigned char VoltageDown_B:1;
		unsigned char VoltageDown_C:1;
		unsigned char OverPaADemand:1;    
		unsigned char OverNeADemand:1;    
		 
		
		unsigned char PowerReverse_A:1;
		unsigned char PowerReverse_B:1;
		unsigned char PowerReverse_C:1;
		unsigned char OverVoltage_A:1;  
		unsigned char OverVoltage_B:1;  
		unsigned char OverVoltage_C:1;  
		unsigned char CurrImBalanceEvent:1;
		unsigned char VoltImBalanceEvent:1;	
		 
		
		unsigned char OverCurrent_A:1;
		unsigned char OverCurrent_B:1;
		unsigned char OverCurrent_C:1;	
		unsigned char UpLoad_A:1;
		unsigned char UpLoad_B:1;
		unsigned char UpLoad_C:1;	
		unsigned char OpenCoverEvent:1;  
		unsigned char OpenBoxEvent:1;      
		 
		
		unsigned char OverPowerAlarm:1;
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char AdjustMeterEvent:1;
		unsigned char ProgrammeEvent:1;
		unsigned char OverFactor_A:1;		
		unsigned char OverFactor_B:1;  
		unsigned char OverFactor_C:1;  
		  	    	
		 
		 
		
		unsigned char CurrReverse:1;
		unsigned char OverFactor:1;
		unsigned char CurrFarImB:1;
		unsigned char FailCurrent_A:1;
		unsigned char FailCurrent_B:1;
		unsigned char FailCurrent_C:1;		
		unsigned char PowerDownEvent:1;  
		unsigned char :1;  	
		 
		  		
		 
		
		unsigned char OkVoltageCheck_A:1;  
		unsigned char UpVoltageCheck_A:1;  
		unsigned char DownVoltageCheck_A:1;  
		unsigned char OkVoltageCheck_B:1;  
		unsigned char UpVoltageCheck_B:1;  
		unsigned char DownVoltageCheck_B:1;  
		unsigned char ConstantMagnet:1;   
		unsigned char PowerAbnormal:1;	
		 
		
		unsigned char OkVoltageCheck_C:1;  
		unsigned char UpVoltageCheck_C:1;  
		unsigned char DownVoltageCheck_C:1;   
		unsigned char Over1RDemand:1;
		unsigned char Over2RDemand:1;
		unsigned char Over3RDemand:1;
		unsigned char Over4RDemand:1;		
		unsigned char :1;
		 
	}bit;
	unsigned char byte[8]; 
};
                                                                                                                     
                                                           
                                                   
                                                           
                                                           
 
struct EVENT_POWER_NET_POINTER                             
{                                                          
    	unsigned char BreakPhase_A_P;    
    	unsigned char BreakPhase_B_P;          
    	unsigned char BreakPhase_C_P;                
                                                
    	unsigned char LostVoltage_A_P;                             
	unsigned char LostVoltage_B_P;                            
	unsigned char LostVoltage_C_P;                          
	                                              
	unsigned char LostCurrent_A_P;                            
	unsigned char LostCurrent_B_P;                            
	unsigned char LostCurrent_C_P;                 
	
	unsigned char PowerReverse_T_P;       
	unsigned char PowerReverse_A_P;       
	unsigned char PowerReverse_B_P;       
	unsigned char PowerReverse_C_P; 
	
	unsigned char OverPowerAlarm_P;       
	
	unsigned char VoltageReserve_P;       
	
	unsigned char OverVoltage_A_P;       
	unsigned char OverVoltage_B_P;        
	unsigned char OverVoltage_C_P;       
	 
  unsigned char PowerDown_P;       
  
  unsigned char ProgrammeEvent_P;       
  
  unsigned char VoltStatistic_A_P;       
  unsigned char VoltStatistic_B_P;       
  unsigned char VoltStatistic_C_P;       
  unsigned char VoltStatistic_T_P;       
  
  unsigned char OverPaADemand_P;       
  unsigned char OverNeADemand_P;       
  unsigned char Over1RDemand_P;       
  unsigned char Over2RDemand_P;       
  unsigned char Over3RDemand_P;       
  unsigned char Over4RDemand_P;        
  unsigned char OpenCoverEvent_P;         
  unsigned char OpenBoxEvent_P;       
  unsigned char Phase3LostVolt_P;   
  unsigned char CurrFarImB_P; 
  unsigned char ConstantMagnet_P;         
  unsigned char PowerAbnormal_P;    
  unsigned char CurrImBalanceEvent_P;       
  unsigned char VoltImBalanceEvent_P;       
  unsigned char VoltageDown_A_P;       
  unsigned char VoltageDown_B_P;       
  unsigned char VoltageDown_C_P;       
  unsigned char OverCurrent_A_P;       
  unsigned char OverCurrent_B_P;       
  unsigned char OverCurrent_C_P;       
  unsigned char UpLoad_A_P;       
  unsigned char UpLoad_B_P;       
  unsigned char UpLoad_C_P;       
  unsigned char CurrReverse_P;         
  unsigned char OverFactor_P;       
  unsigned char OverFactor_A_P;       
  unsigned char OverFactor_B_P;       
  unsigned char OverFactor_C_P;            
  unsigned char FailCurrent_A_P;       
  unsigned char FailCurrent_B_P;       
  unsigned char FailCurrent_C_P;       
  unsigned char ClockBatteryEvent_P;       
  unsigned char DisplayBatteryEvent_P;       
  unsigned char AdjustMeterEvent_P;     
       
      
};                                                         
                                                           
struct EVENT_METER_PRO_POINTER                             
{                                                           	
	unsigned char ResetCPU_P; 
	unsigned char SetPrimary_P; 
	unsigned char RunClockError_P; 
	unsigned char PowerUpClockError_P; 
	unsigned char AdjustEnergy_P; 
	unsigned char EepromErr_P; 
	unsigned char AdjustTimeOverT_P; 
	unsigned char Energypasszero_P; 
	unsigned char Rst90E36_P; 
	unsigned char ClearMeterRecord_P; 
	unsigned char AdjustTimeRecord_P; 
	unsigned char ClearDemandRecord_P; 
	unsigned char ClearEventRecord_P; 
	unsigned char ProgWeekRecord_P; 
	unsigned char ProgAEModeRecord_P; 
	unsigned char ProgNEMode1Record_P; 
	unsigned char ProgNEMode2Record_P; 
	unsigned char ProgBillDayRecord_P; 
	unsigned char ProgYearSlotRecord_P; 
	unsigned char ProgDailySlotRecord_P; 
	unsigned char ProgHolidayRecord_P; 	
	unsigned char OverPowerCloseSwitch_P; 
	                                   
}; 

struct EVENT_METER_PRO_TIMES                               
{                                                                                                                                  
	unsigned long ResetCPU_Times;          	
	unsigned long SetPrimary_Times;      		
	unsigned long RunClockError_Times;    
	unsigned long PowerUpClockError_Times;    
	unsigned long AdjustEnergy_Times;    
	unsigned long EepromErr_Times;	    	
	unsigned long AdjustTimeOverT_Times;     			
	unsigned long Energypasszero_Times;   
	unsigned long Rst90E36_Times;      	
	unsigned long ClearMeterRecord_Times;    
	unsigned long AdjustTimeRecord_Times;    
	unsigned long ClearDemandRecord_Times;    
	unsigned long ClearEventRecord_Times;    
	unsigned long ProgWeekRecord_Times;    
	unsigned long ProgAEModeRecord_Times;    
	unsigned long ProgNEMode1Record_Times;    
	unsigned long ProgNEMode2Record_Times;    
	unsigned long ProgBillDayRecord_Times;    
	unsigned long ProgYearSlotRecord_Times;    
	unsigned long ProgDailySlotRecord_Times;    
	unsigned long ProgHolidayRecord_Times;    	
	unsigned long OverPowerCloseSwitch_Times;  	
};



        
struct EVENT_POWER_NET_TIMES                               
{                                                          
  unsigned long BreakPhase_A_Times;    
  unsigned long BreakPhase_B_Times;          
  unsigned long BreakPhase_C_Times;                                               
  unsigned long LostVoltage_A_Times;                       
  unsigned long LostVoltage_B_Times;                      
  unsigned long LostVoltage_C_Times;  
  unsigned long LostCurrent_A_Times;                      
  unsigned long LostCurrent_B_Times;                      
  unsigned long LostCurrent_C_Times;           
  unsigned long PowerReverse_T_Times; 
  unsigned long PowerReverse_A_Times; 
  unsigned long PowerReverse_B_Times; 
  unsigned long PowerReverse_C_Times;	  	          	
  unsigned long OverPowerAlarm_Times;     
  unsigned long VoltageReserve_Times;    
  unsigned long OverVoltage_A_Times;    
  unsigned long OverVoltage_B_Times;    
  unsigned long OverVoltage_C_Times;      	                            
  unsigned long PowerDown_Times; 
  unsigned long ProgrammeEvent_Times; 
  unsigned long VoltStatistic_A_Times; 
  unsigned long VoltStatistic_B_Times; 
  unsigned long VoltStatistic_C_Times; 
  unsigned long VoltStatistic_T_Times; 
  unsigned long OverPaADemand_Times; 
  unsigned long OverNeADemand_Times; 
  unsigned long Over1RDemand_Times; 
  unsigned long Over2RDemand_Times; 
  unsigned long Over3RDemand_Times; 
  unsigned long Over4RDemand_Times; 
  unsigned long OpenCoverEvent_Times;      
  unsigned long OpenBoxEvent_Times; 
  unsigned long Phase3LostVolt_Times; 
  unsigned long CurrFarImB_Times; 
  unsigned long ConstantMagnet_Times; 
  unsigned long PowerAbnormal_Times;   
  unsigned long CurrImBalanceEvent_Times; 
  unsigned long VoltImBalanceEvent_Times; 
  unsigned long VoltageDown_A_Times; 
  unsigned long VoltageDown_B_Times; 
  unsigned long VoltageDown_C_Times; 
  unsigned long OverCurrent_A_Times; 
  unsigned long OverCurrent_B_Times; 
  unsigned long OverCurrent_C_Times; 
  unsigned long UpLoad_A_Times; 
  unsigned long UpLoad_B_Times; 
  unsigned long UpLoad_C_Times; 
  unsigned long CurrReverse_Times; 
  unsigned long OverFactor_Times; 
  unsigned long OverFactor_A_Times; 
  unsigned long OverFactor_B_Times; 
  unsigned long OverFactor_C_Times; 
  unsigned long FailCurrent_A_Times; 
  unsigned long FailCurrent_B_Times; 
  unsigned long FailCurrent_C_Times; 
  unsigned long ClockBatteryEvent_Times; 
  unsigned long DisplayBatteryEvent_Times; 
  unsigned long AdjustMeterEvent_Times; 
                         
};                                           

 
     
     
struct EVENT_POWER_NET_TIMETICKS                           
{   
		unsigned long LostVoltage_A_Times_Ticks;                      
		unsigned long LostVoltage_B_Times_Ticks;                     
		unsigned long LostVoltage_C_Times_Ticks; 
		unsigned long VoltageReserve_Times_Ticks; 
		unsigned long Phase3LostVolt_Times_Ticks; 
		unsigned long LostCurrent_A_Times_Ticks;                     
		unsigned long LostCurrent_B_Times_Ticks;                     
		unsigned long LostCurrent_C_Times_Ticks;
		
		unsigned long BreakPhase_A_Times_Ticks;   
		unsigned long BreakPhase_B_Times_Ticks;         
		unsigned long BreakPhase_C_Times_Ticks;  
		unsigned long VoltageDown_A_Times_Ticks;
		unsigned long VoltageDown_B_Times_Ticks;
		unsigned long VoltageDown_C_Times_Ticks;
		unsigned long OverPaADemand_Times_Ticks; 
		unsigned long OverNeADemand_Times_Ticks; 

		unsigned long PowerReverse_A_Ticks;
		unsigned long PowerReverse_B_Ticks;
		unsigned long PowerReverse_C_Ticks;
		unsigned long OverVoltage_A_Times_Ticks;
		unsigned long OverVoltage_B_Times_Ticks;
		unsigned long OverVoltage_C_Times_Ticks; 		
		unsigned long CurrImBalanceEvent_Times_Ticks;
		unsigned long VoltImBalanceEvent_Times_Ticks;

		unsigned long OverCurrent_A_Times_Ticks;
		unsigned long OverCurrent_B_Times_Ticks;
		unsigned long OverCurrent_C_Times_Ticks;
		unsigned long UpLoad_A_Times_Ticks;
		unsigned long UpLoad_B_Times_Ticks;
		unsigned long UpLoad_C_Times_Ticks; 
		unsigned long Nouse_0_Times_Ticks; 
		unsigned long Nouse_1_Times_Ticks;
		
		unsigned long OverPowerAlarm_Times_Ticks;
		unsigned long Nouse_2_Times_Ticks; 
		unsigned long Nouse_3_Times_Ticks; 
		unsigned long Nouse_4_Times_Ticks; 
		unsigned long Nouse_5_Times_Ticks;
		unsigned long OverFactor_A_Times_Ticks;
		unsigned long OverFactor_B_Times_Ticks; 
		unsigned long OverFactor_C_Times_Ticks;	

		unsigned long CurrReverse_Times_Ticks;   
		unsigned long OverFactor_Times_Ticks;
		unsigned long CurrFarImB_Times_Ticks;
		unsigned long FailCurrent_A_Times_Ticks;
		unsigned long FailCurrent_B_Times_Ticks;
		unsigned long FailCurrent_C_Times_Ticks;      
		unsigned long Nouse_15_Times_Ticks; 
		unsigned long Nouse_16_Times_Ticks;
		
		unsigned long OkVoltageCheck_A_Times_Ticks;          
		unsigned long UpVoltageCheck_A_Times_Ticks;  
		unsigned long DownVoltageCheck_A_Times_Ticks;  
		unsigned long OkVoltageCheck_B_Times_Ticks; 
		unsigned long UpVoltageCheck_B_Times_Ticks;  
		unsigned long DownVoltageCheck_B_Times_Ticks; 
		unsigned long Nouse_18_Times_Ticks;
		unsigned long Nouse_19_Times_Ticks;

		unsigned long OkVoltageCheck_C_Times_Ticks;  
		unsigned long UpVoltageCheck_C_Times_Ticks;  
		unsigned long DownVoltageCheck_C_Times_Ticks;  
		unsigned long Nouse_20_Times_Ticks;
		unsigned long Nouse_21_Times_Ticks;
		unsigned long Nouse_22_Times_Ticks;
		unsigned long Nouse_23_Times_Ticks; 
		unsigned long Nouse_24_Times_Ticks;	
		
};                                                                                                                      

struct SLOTPAREMETER
{
       unsigned     char             YearSlotNumble;
       unsigned     char             DailySlotTableNumble;
       unsigned     char             DailySlotNumble;
       unsigned     char             TriffNumble;
       unsigned      int             HollidayNumble;     
       unsigned     char             WeekEndTable;  
       union        WEEKSTATUS       Week_Status;
        
};

struct  DAYHOUR_DEF
{
    unsigned char Day;
    unsigned char Hour;
};
struct SWITCH_ITEM
{
	 unsigned     char             WhitchSlotIsNow;
   struct       DATEANDTIME_DEF  SwitchDate;
   unsigned     char             FreezeData_addr;         	
   unsigned     char             DropProtectFlag;
}; 

union LCD_LED_Speaker_Terminal_ALARM_FLAG      
{
	struct                       
	{    
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char RunClockError:1; 
       unsigned char Eeprom_Err:1;		
      	unsigned char OpenBoxEvent:1;      
		unsigned char OpenCoverEvent:1;  
		unsigned char OverFactor:1;
		unsigned char VoltageReserve:1;
    
		unsigned char CurrReverse:1;
		unsigned char PowerReverse:1;
       unsigned char OverPaADemand:1;   
       unsigned char OverNeADemand:1;          
       unsigned char LostVoltage:1;  
		unsigned char BreakPhase:1;   
		unsigned char OverVoltage:1;  
		unsigned char VoltageDown:1;
    
    	unsigned char VoltImBalance:1;	      
		unsigned char CurrImBalance:1;
		unsigned char CurrFarImBalance:1;
		unsigned char LostCurrent:1;                     
		unsigned char OverCurrent:1;
		unsigned char FailCurrent:1;
		unsigned char UpLoad:1;
		unsigned char Programme:1;

       
		unsigned char OverReDemand:1;                     
		unsigned char ConstMagnet:1; 
    unsigned char EsamErr:1;  
		unsigned char CtrCircleErr:1;  
       unsigned char :1;                     
		unsigned char :1; 
    	unsigned char :1;  
		unsigned char :1;  
	}bit;
    unsigned long Alarm_Flag;
};

union TERMINALALARMFLAG      
{
	struct                       
	{    
		unsigned char ClockBatteryEvent:1;
		unsigned char DisplayBatteryEvent:1;
		unsigned char RunClockError:1; 
    unsigned char Eeprom_Err:1;		
    unsigned char OpenBoxEvent:1;      
		unsigned char OpenCoverEvent:1;  
		unsigned char OverFactor:1;
		unsigned char VoltageReserve:1;
    
		unsigned char CurrReverse:1;
		unsigned char PowerReverse:1;
    unsigned char OverPaADemand:1;   
    unsigned char OverNeADemand:1;          
    unsigned char LostVoltage:1;  
		unsigned char BreakPhase:1;   
		unsigned char OverVoltage:1;  
		unsigned char VoltageDown:1;
    
    unsigned char VoltImBalance:1;	      
		unsigned char CurrImBalance:1;
		unsigned char CurrFarImBalance:1;
		unsigned char LostCurrent:1;                     
		unsigned char OverCurrent:1;
		unsigned char FailCurrent:1;
		unsigned char UpLoad:1;
		unsigned char Programme:1;

       
		unsigned char OverReDemand:1;                     
		unsigned char ConstMagnet:1; 
    unsigned char EsamErr:1;  
		unsigned char CtrCircleErr:1;  
    unsigned char :1;                     
		unsigned char :1; 
    unsigned char :1;  
		unsigned char OverPowerAlarm:1;  
	}bit;
  unsigned long Alarm_Flag;
};

 
struct PARAMETER1 
{
  unsigned     long             ActivePulseConst;
  unsigned     long             ReactivePulseConst;
 
 
  unsigned     char             BcdCommAddr[3][6];
  union        BYTE_BIT         MeterMode[4];
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_Alarm_Flag;  	
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_LedAlarm_Flag; 
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_SpeakerAlarm_Flag; 
  union LCD_LED_Speaker_Terminal_ALARM_FLAG      MeterMode_TerminalAlarm_Flag; 
  unsigned     char             DemandPeriod;
  unsigned     char             DemandSkipPeriod;
  unsigned     char             CycleDisplayTime;
  unsigned     char             DisplayNumber;
  struct       DAYHOUR_DEF      AutoBillDayHour[3];
  union        BYTE_BIT         Activem_Erengy_Mode;          		
	union        BYTE_BIT         REActivem_Erengy_1_Mode;   
	union        BYTE_BIT         REActivem_Erengy_2_Mode;    
	 
	union        BYTE_BIT         MeterTypeMode;
	union        BYTE_BIT         CarrierMode;
  union        COMMRATE         Commrate[4];     
  
  struct       SLOTPAREMETER    SlotParemeter[2];
  struct       SWITCH_ITEM      TriffSwitch;
	struct       SWITCH_ITEM      DailySlotSwitch;          
	unsigned     int              KeyDisplayNumber;
	unsigned     char             ClearPassword[5	   ][4];
  unsigned     char             UserClass[3];
  unsigned     long             EventJudgeIn;
  unsigned     char             DISP_In;  
  union EVENT_REPORT_MODE  EventReportMode; 
 union        BYTE_BIT             LocalFunctionMode;  
   unsigned     char             ResetReportTime;   
  unsigned     int              crc_cal;
               
};   

  
 
  
 


struct PARAMETER2 
{
 
	unsigned     char             AscII_MeterManage_Code[32];  
	unsigned     char             AscII_V_Regulation[6];  	
	unsigned     char             AscII_I_Regulation[6];  
	unsigned     char             AscII_MAX_I[6];  
	unsigned     char             AscII_Active_Accu[4];  
	unsigned     char             AscII_Reactive_Accu[4];  
	unsigned     char             AscII_Meter_Moder[10];  
	unsigned     char             AscII_Manufacture_Day[10];  
	unsigned     char             AscII_Protocol_Version[16];  	
	unsigned     char             AscII_Factory_Hardware_Version[32];  	
	unsigned     char             AscII_Factory_Sofeware_Version[32];  	
	unsigned     char             AscII_Factory_Number_Version[32];  		
	 
	unsigned     char             EnergyPoint;
  unsigned     char             PowerPoint;        
  unsigned     char             LoadDay;            
  unsigned     int              PulseWidth;
  unsigned     char             BcdMeterID[6];
  unsigned     char             BcdUserID[6];
  unsigned     char             BcdDeviceID[6]; 
  union        BYTE_BIT         LoadRecordMode;
  struct       DATEANDTIME_DEF  LoadRecoedBeginTime;
  unsigned     int              LoadRecordPeriod[6];
  
  
  unsigned     char             OpenSwitchDelayTime;
  unsigned     char             CloseSwitchDelayTime;
  
	unsigned     int              ShowNoKeyRetTime;   
  unsigned     char             Meterlocktimes;
  unsigned     long             PlusEnergyData;
  unsigned     long             NegaEnergyData;
  unsigned     int              ExitProgrameTime;
  unsigned     char             BroadcastJustTtimes;
  unsigned     char             JFPG_ExpressTriff[63];
  unsigned     char             PowerOnFullScreenTime; 
  signed       long             Longitude;
  signed       long             Latitude;
  signed       long             Height;
  unsigned     char             MeterSoftIdNumber[8];
  unsigned     int              crc_cal;
};   
struct EVENT_PARAMETER
{
	unsigned     long             VoltageHealth_UpSet;
  unsigned     long             VoltageHealth_DownSet;
  unsigned     long             VoltageCheck_UpSet;
  unsigned     long             VoltageCheck_DownSet;  
	unsigned     char             JudgeLossVoltageSecond;
  unsigned     char             JudgeBreakPhaseSecond;	
  unsigned     char             JudgeLostCurr_T;
  unsigned     long             JudgeLostCurr_I[2];
  unsigned     long             JudgeBreakPhaseI;
  unsigned     long             PaADemandLimit;
  unsigned     long             NeADemandLimit;
  unsigned     char             CriticalVoltage;
  unsigned     int              JudgeOverVolt_V;
  unsigned     long             JudgeCurrImBalanceN;
  unsigned     long             JudgeVoltImBalanceN;
  unsigned     long             JudgeLossVoltage;
  unsigned     char             JudgeLossVoltageNV;
  unsigned     int              JudgeVoltDown_V;
  unsigned     long             JudgeOverCurrentI;
	unsigned     int              JudgeLostVoltSV;
	unsigned     int              JudgeLostVoltEV;
	unsigned     char             JudgeVoltDownT;
	unsigned     char             JudgeOverVoltT;
	unsigned     int              JudgeBreakPhaseV;
	unsigned     char             JudgeVoltImBalanceT;
	unsigned     char             JudgeCurrImBalanceT;
	unsigned     int              JudgeLostCurrSV;
	unsigned     char             JudgeOverCurrentT;
	unsigned     long             JudgePowerReverseP;
	unsigned     char             JudgePowerReverseT;
	unsigned     long             JudgeUpLoadP;
	unsigned     char             JudgeUpLoadT;
	unsigned     long             JudgeOverDemandP;
	unsigned     int              JudgeOverFactorN;
	unsigned     char             JudgeOverFactorT;
	unsigned     int              JudgeCurrFarImBN;
	unsigned     char             JudgeCurrFarImBT;
	unsigned     int              JudgeFailCurrSV;
	unsigned     long             JudgeFailCurrI;
	unsigned     char             JudgeFailCurrT;	
  unsigned     long             JudgeOverDemandN;
  unsigned     char             JudgeOverDemandT;
  unsigned     long             JudgeCurrImBMinI;
  unsigned     long             JudgeABCPowerReverseP;
	unsigned     char             JudgeABCPowerReverseT;
    unsigned int                  AD_Sample_Vref; 
    unsigned int                  ClockBattery_volt_Low_Threshold; 
    unsigned int                  DisplayBattery_volt_Low_Threshold; 
  unsigned     int              crc_cal;
};   












struct FREEZE_PARAMETER
{
	unsigned     char             FreezeDate[4];
  unsigned     char             FreezeDateFlag;
	struct       DATEANDTIME_DEF  Freeze_Period_Date;		
	unsigned     char             Freeze_Period_Interval;
	unsigned     char             FreezeDay_Hour; 
  unsigned     char             FreezeDay_Min;
	union        BYTE_BIT         New645_Freeze_Time_Mode;
	union        BYTE_BIT         New645_Freeze_Moment_Mode;
	union        BYTE_BIT         New645_Freeze_Promise_Mode;
	union        BYTE_BIT         New645_Freeze_Period_Mode;
	union        BYTE_BIT         New645_Freeze_Day_Mode;
	unsigned     int              crc_cal;
};   

 
 
 
 
 
	
 
 
struct METER_PARAMETER
{
	struct PARAMETER1             parameter1;
	struct PARAMETER2             parameter2;
	struct EVENT_PARAMETER        event_parameter;
	struct FREEZE_PARAMETER       freeze_parameter;
 
};


struct COMMCLEARSTRDEF
{
    unsigned char    Clear_All_Flag; 
    unsigned char    Clear_Event_Flag; 
    unsigned char    Clear_Demand_Flag; 
    unsigned char    CommDailyProgFlag;
    unsigned char    CommYearProgFlag;    
    unsigned int     Comm_Clear_Crc_Data;     
};

    
struct OTHER_METER_PARAMETER
{
	unsigned     char             WorkRoomState;
	unsigned     char             WorkRoomFlag;
	struct       DATEANDTIME_DEF WorkRoomStateDate;
     
    unsigned     long             WorkRoom_RunTime; 
    unsigned     char             ProgramKeyStartFlag;
    unsigned     long             ProgramKeyTimeAdd;
     
    struct       COMMCLEARSTRDEF CommClearFlagCurrFF; 
  
    unsigned     char             JustMeter;
    unsigned     char             OutputModel;     

     
    unsigned     char             PowerOnDayfreeze_flag; 
    struct      DATEANDTIME_DEF  DayFreezeReferenceDate; 
    unsigned     char             PowerOnRetort_flag; 
    unsigned     int             EventReport_RunTime; 
    unsigned     char             ResetEventReport_flag; 
    
    unsigned     long             OldSegParameter;
    unsigned     char             Bill_Flag;				 
    unsigned     char             Bill_Addr;				 
    unsigned     char             Bill_DM_Flag;				 
    unsigned     char             Bill_DM_Addr;				 
    struct       DATEANDTIME_DEF  LastEnergyBillDate; 
    unsigned     char             FreezeData_Time_addr;        
    unsigned     char             FreezeData_Moment_addr;       
    unsigned     char             FreezeData_Period_addr;          
    unsigned     char             FreezeData_Day_Addr;	

    unsigned     char             SwitchOn_Report; 
    unsigned     char             SwitchOff_Report;  
 
};


 
struct       PASSWORDERR
{
  unsigned char flag;
  unsigned char num;
  struct DATEANDTIME_DEF firsttime;
  struct DATEANDTIME_DEF secondtime;
};

 
struct OTHER_DATA
{
  unsigned     long             BatteryWorkTime1; 
  unsigned     long             BatteryWorkTime2; 
 
 
 
 

  struct       PASSWORDERR      PasswordErr[5	   ];
	unsigned     char             Clear_PasswordErr_Flag;   

  struct       DATEANDTIME_DEF  LastClearDemandDate;
  struct       DATEANDTIME_DEF  LastJusttime;
  unsigned     char             JusttimesAdd;  
  struct       DATEANDTIME_DEF  ProgramDate;
  struct       DATEANDTIME_DEF  LastClearDemandDateCM;
	struct       COMMCLEARSTRDEF  CommClearFlagCurrEE;
 
};

struct PRE_SAVE_DATA		 
    {
	  signed long Remain_Money;                	 
	unsigned long Remain_Money_bottom;	 
	unsigned long Energy_Next_Step;      	 
	unsigned long Month_Total_Energy;     	 
	unsigned long Year_Total_Energy;			 
	unsigned char duct_eng; 
};

 
struct ENERGY_RECORD
{				
  unsigned long  Plus_Active[9        ]; 
	unsigned long  Nega_Active[9        ];
	
	unsigned long  Quad_Reactive[4][9        ];
    
  unsigned long  Phase_Plus_Active[3];
  unsigned long  Phase_Nega_Active[3];
  
  unsigned long  Phase_Reactive[3][4];
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
	  
 
	unsigned char EnergyPassMAXTimes[6];

       struct PRE_SAVE_DATA	   Pre_Save_Data;	 
	
	unsigned int   crc_cal;
	

}; 
 
struct MINUTE_COPY_ENERGY
{	
  struct ENERGY_RECORD      Energy_Record;	
  struct DATEANDTIME_DEF    date;                   	
	unsigned char             csadd;	
}; 


 
struct DEMAND_DATA_FORM
{
	unsigned long Demand;
	unsigned char time[5];
};

struct DEMAND_RECORD
{
	
        
      struct DEMAND_DATA_FORM  Plus_Active[9        ]; 
	    struct DEMAND_DATA_FORM  Nega_Active[9        ];
			struct DEMAND_DATA_FORM  Quad_Reactive[4][9        ];
 
 
			
			
       
	
};  

union DEMAND_TYPE
{
	struct DEMAND_RECORD Demand;
	struct DEMAND_DATA_FORM  Value[6][9        ];
};

 
struct ENERGY_POWERDOWN 
  {
	   unsigned int  Plus_Active[2]; 
	   unsigned int  Nega_Active[2];
	   unsigned int  Quad_Reactive[4][2];	    	
	   
     unsigned long  Phase_Plus_Active[3];
     unsigned long  Phase_Nega_Active[3];
     unsigned long  Phase_Reactive[3][4];
  };


  
struct POWERDOWN_SAVE_DATA 
{
	
	struct ENERGY_POWERDOWN  energy_powerdown;  
  struct   DATEANDTIME_DEF date;	    
	unsigned char            fee;	  
	unsigned char            PdEventFlag[8];
	struct PRE_SAVE_DATA	   Pre_Save_Data;	 
  unsigned int             crc_cal;   
            
};

struct ENERGY_RAIL_ADD_BUFFER
{
	unsigned long  Rail_Plus_Active[4];			 
	unsigned long  Rail_Nega_Active[4];			 
	
	unsigned long  Rail_Quad_Reactive[4][4];		 
	
	unsigned char  Total_Plus_Active_100mwh[9        ];			 
	unsigned char  Total_Nega_Active_100mwh[9        ];			 
	
	unsigned int crc_cal;
};

 
struct THIS_MONTH_DATA
{

	struct ENERGY_RECORD      Energy_Record;

	union DEMAND_TYPE      Demand_Record;

};     
 
struct THIS_MONTH_DATA_EEPROM
{

	struct ENERGY_RECORD      Energy_Record;

	struct DEMAND_RECORD      Demand_Record;

};     

 
struct EVENT_RECORD
{
	unsigned char Event_Recort [(sizeof(struct EVENT_POWER_NET_POINTER)*2
	                           +sizeof(struct EVENT_METER_PRO_POINTER))*11][9];
};

struct SINGLE_EVENT_ENERGE
{
  unsigned     long             P_Energy;	 
	unsigned     long             N_Energy;	 
	unsigned     long             R_Energy[4]; 
};


 
struct LOSSVOLTAGE_ENERGY
{
	struct SINGLE_EVENT_ENERGE      Single[4];
	unsigned     long               LossVoltageIH[3];		 
};
 
struct LOSSCURRENT_ENERGY
{        
	struct SINGLE_EVENT_ENERGE      Single[4];
};


struct POWERRESERVE_ENERGY_SING
{
  unsigned     long             P_PowerReserveEnergy;   
  unsigned     long             N_PowerReserveEnergy;    
};
 
struct POWERRESERVE_ENERGY
{
	struct POWERRESERVE_ENERGY_SING Sg[4];     
};

struct TOTAL_POWERRESERVE_ENERGY
{
  struct POWERRESERVE_ENERGY    Single[4];   
};

 
struct EVENT_ENERGY
{        
  struct LOSSVOLTAGE_ENERGY     Lossvoltage_Energy[7]; 
  
  struct LOSSCURRENT_ENERGY     LOSSCURRENT_ENERGY[6];
  
  struct POWERRESERVE_ENERGY    POWERRESERVE_ENERGY[4];
  
  struct POWERRESERVE_ENERGY_SING    CurrentImbalance_Energy[3];	
};

 
struct CLEAR_DEMAND_DATA
{
	struct DATEANDTIME_DEF    date;	
};
 
struct AC
{
	unsigned long  Plus_Active[9        ]; 
	unsigned long  Nega_Active[9        ];
	unsigned int   Volt[3];
  unsigned int   Curr[3];
  unsigned char  Active_power[4][3];
  unsigned int   Reactive_power[4];
  unsigned int   Factor[4];    
  unsigned int   Freq;  
  unsigned int   Phase_Angle[4];
  unsigned char  date[5];
};
struct RC
{
	unsigned long  Quad_Reactive[4][9        ];
  unsigned char  date[5];
};
 
 
 
 
 
 
 

 
struct YEARSLOT
{
	unsigned char YearSlot[14	     ][3];
};
 
struct DAILYSLOT
{
	unsigned char DailySlot[8 ][14	     *3];
};
 
struct HOLIDAYSLOT
{
	unsigned char HolidaySlot[254	  ][4];   
};
 
union ID
{
  unsigned char d[4];
  unsigned int  i;
  unsigned int  new_i[2]; 
  unsigned long l;
};
 
union NEW_ID
{
  unsigned char d[4];
  unsigned int  i[2];
  unsigned long l;
};
struct CYCLEDISPLAYTABLE1
{
	unsigned char flag; 
  unsigned char work[4];    
};
struct CYCLEDISPLAYTABLE2
{
	unsigned char code;
  unsigned char use[4];    
};
struct CYCLEDISPLAYTABLE_A
{
  struct CYCLEDISPLAYTABLE1 CycleDisplayTable1[99];
	struct CYCLEDISPLAYTABLE2 CycleDisplayTable2[99];
};
struct CYCLEDISPLAYTABLE_B
{
  struct CYCLEDISPLAYTABLE1 CycleDisplayTable1[120];
	struct CYCLEDISPLAYTABLE2 CycleDisplayTable2[120];
};

 
								
union CoBuff
{
	unsigned char b[1280];
	
	struct ENERGY_RECORD            Energy_Record;
	struct ENERGY_POWERDOWN         Energy_Powerdown;
	struct POWERDOWN_SAVE_DATA      Powerdown_Save_Data;
	struct METER_PARAMETER          Meter_Parameter;
	struct COMM
	{
	   unsigned char      num;             
	   union    BYTE_BIT  com;             
	   unsigned char*     addrr[4];        
	   unsigned int       addre[4];        
	   union    BYTE_BIT  flag1;           
	   unsigned char      format;          
	   unsigned char      rw;              
	   unsigned char      len;             
	   unsigned char*     addr5;           
	   unsigned char      condition;       
	   union    BYTE_BIT  flag2;           
	   union    BYTE_BIT  flag3;           
	   union    BYTE_BIT  flag4;           
	   unsigned char      calnumber;       
	   union DATA
	   {
	      unsigned   char      c[4];
	      unsigned   int       i[2];
	      signed     long      g;
	   }d;                                 
	   unsigned char Convert[12];          
	   unsigned char data[4][20];     
	   unsigned char f[50];
	   unsigned char h[50];
 
	}c;
	struct Event
	{
	   unsigned int addr;
	   unsigned char point;
	   unsigned char * eaddr;
	   unsigned int  len;
	   unsigned int elen;
	   
    }e;
	
};
 
struct FindCommand_Result
{
	unsigned char firstreceivecomm:1;  
	unsigned char havebackframe:1;  
	unsigned char sendbackframe:1;  
	                                
	unsigned char readloadrecord:1;
	unsigned char firstreadloadrecord:1;
	unsigned char lastreadloadrecord:1;
	unsigned char ZJ_Read_Big_Block:1;
	unsigned char ZJ_Read_Lit_Block:1;
	unsigned char ZJ_Read_Single:1;
	unsigned char ZJ_zerodata:1;
	unsigned char ZJ_overdata:1;
	unsigned char ZJ_firstzjto645:1;
	unsigned char BroadCasrAddress:1;
	unsigned char All_AA_Address; 
                                       	                               
	unsigned char model;   
	unsigned char c;       
	unsigned int  len;     
	unsigned char addr;    
	union    ID   id;      
	unsigned char* dataaddr;  
	
	union    ID   idt;     
	unsigned int  lent;    
	unsigned int  lena;    
	unsigned char ct;      
	union    ID   idd;     
	                       
	unsigned char ZJ_n;    
	unsigned char ZJ_len;  
	
	unsigned char uartx;   
	unsigned char sum;     
	
	unsigned char passerword; 

	unsigned char Frame_serial; 
  unsigned long Programer_code; 
		
	unsigned char command[10]; 
	
	
};

struct DEMAND_CONTROL
{
	unsigned char LastTriff;  
	unsigned char TriffCounter;  
	unsigned char Pointer;  
	unsigned char ClockAdjusted;  
	unsigned char TriffPointer;  
	
	unsigned long TriffRest[4];   
	unsigned char HaveRest;   
};


struct LOADRECORD                                                                                                 
{		                                                                                                        
  unsigned int        PageAddress;                                                              
	unsigned int        ByteAddress;    
  unsigned int        LastPageAddress;                                                
	unsigned int        LastByteAddress;        
  unsigned int        FirstPageAddress1[6];                                                
	unsigned int        FirstByteAddress1[6];     
  unsigned int        LastPageAddress1[6];                                                
	unsigned int        LastByteAddress1[6];     
  union    BYTE_BIT   First_Flag;                                           
	struct                                                                                                          
	{                                                                                                               
		unsigned int Last_Read_PageAddress;                                    
		unsigned int Last_Read_ByteAddress;                                    
		unsigned int Next_Read_PageAddress;                            
		unsigned int Next_Read_ByteAddress;                            
	}ReadHistory[3];                                                                                                
	                                                                                                                
	struct DATA_TIME    LastRecordTime;  
                                                                                                                      
                                                                                      
	                                                                                                                
	struct                                                                                                          
	{                                                                                                               
		char NeedSaveIndex:1;	 
		char reStart:1;			    
		char LoadRecoedBeginTime:1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
		char :1;                                                                                                
	}LoadRecordFlag;                                                                                                
	                                                                                                                
	                                                                                                                
	                                                                                                                
	unsigned int CurrentIndex;                                                                                      
	                                                                                                                
	struct DATEANDTIME_DEF            LastSaveDate;                                                                 
};   


struct	ALLVOLTAGELOSS_EVENT
{
	unsigned char Start_Second;   
	unsigned char Start_Minute;
	unsigned char Start_Hour;	
	unsigned char Start_Day;			
	unsigned char Start_Month;			
	unsigned char Start_Year;
	
	unsigned char End_Second;   
	unsigned char End_Minute;
	unsigned char End_Hour;	
	unsigned char End_Day;			
	unsigned char End_Month;			
	unsigned char End_Year;	
	unsigned long Curr_PD; 
};	
struct	ALLVOLTAGELOSS_STRUCTURE
{
	unsigned char	Valid_AllVoltageLoss_Flag[8];					 
	unsigned char	AllVoltageLoss_Start_Flag;						 
	 
	unsigned char	AllVoltageLoss_Counter_Before_Start;			 
	unsigned char	AllVoltageLoss_Counter_Before_End;				 
	unsigned char	AllVoltageLoss_WakingUp_Counter;				 
	unsigned char	AllVoltageLoss_Event_Pointer_in_Powerdown_Mode;	 
	
	unsigned int	AllVoltageLoss_Event_Times;						 
	unsigned long	AllVoltageLoss_Time_Seconds;					 
	unsigned long	AllVoltageLoss_Time_Seconds_Copy;				 
	struct        ALLVOLTAGELOSS_EVENT	AllVoltageLoss_Event[10];			 
};

 
 
 
 
struct PowerDown_EventSave_Data
{
	union BYTE_BIT eventflag[12];   
	unsigned long amphour[3];
	unsigned char eventflagcs;	
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
struct VoltStatisticStruct{
 union BYTE_BIT *VoltCheck;  
 unsigned char bytenum;
 unsigned char OkVoltage;
 unsigned char UpVoltage;
 unsigned char DownVoltage;
 unsigned char *VoltStatistic_P;
};   
 
 
 
 
 
 
 
 
struct PREPFIRSTEVENT_STRU    
{
		TGeneral_Event Function;          
		unsigned int   eeprom_addr;       
		unsigned char  *Flag;             
		unsigned char  *eventflag;        
		unsigned char  Offset;          
};
 
 
 
 
 
 
 
 

struct CLEAREVENT_STRU     
{
		unsigned int	   Eeprom_addr;                     
		unsigned int     Pointer_addr;                    
		unsigned int     Times_addr;                      
		unsigned int     Ticks_addr;		                  	
		unsigned char    *Pointer;  		                  
		unsigned char    *Flag;                           
		unsigned char    *Eventflag;                      
		unsigned long    *Times;                          
		unsigned long    *Ticks;	                        
		unsigned char    Offset; 		                      		
		unsigned char    Length;                          
		unsigned int     Filename_begin;                  
		unsigned int     Filename_end;  	                	
		 
		unsigned char    Dispose_flag;         			
}; 
struct REFRESHDATA_STRU     
{
		unsigned int	    EE_flash_addr;                     
		unsigned int        Ticks_addr;		                  	
		unsigned long     *Ticks;	                        
		unsigned char     *Pointer;  		                  		
		unsigned char     *Flag;                           		
		unsigned char     Offset; 		                      
		unsigned char     EE_File_Offset; 		                     
		unsigned char     EE_flash_select;                    		
		 
		 
}; 
struct VOLTCHECK_STRU     
{ 		
		unsigned char  *Flag1;            
		unsigned char  *Flag2;            		
}; 
struct PD_CURRENT_STRUCT
{
    unsigned long Pd_Max_curr;
	  unsigned long Aver_curr;
	  
	  unsigned char validflag[8];
};     
struct COM_SHOW_TABLE
{
   unsigned char  address0;                         
   unsigned int   address1;                         
};
struct Show_Powerdown_Data_Struct
{
    struct SHOW_POWEN_DATA_fLAG
    {
        unsigned char vatiryflag:1;
        unsigned char falshDatalen:7;
    }Show_FlashData_flag;
    unsigned char showbuff[6];
    struct  COM_SHOW_TABLE  Powerdown_show_table;
};

struct	PDOPENCOVERRECORD_STRUCTURE
{
	unsigned char startyear;
	unsigned char startmonth;
	unsigned char startday;	
	unsigned char starthour;			
	unsigned char startmin;			
	unsigned char startsec;
	
	unsigned char opencoverflag;	   
};

struct	PDOPENCOVER_STRUCTURE
{
	struct PDOPENCOVERRECORD_STRUCTURE startrecord[3];
	unsigned char recordnum;
	unsigned char validflag[8];	   
};

struct	PDVOLT_STRUCTURE
{
	unsigned long volt[3];
	unsigned long maxvolt;
	
	unsigned char validflag[8];	   
};

union EVENTSTATUS
{
   struct
   {
       unsigned char powertreverse:1;
       unsigned char powerdownopencover:1;
       unsigned char powerdownopenbox:1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
   }bit;
   unsigned char byte;                                          
};

struct	EVENTREADNODEALSTRUCTURE
{
	unsigned char id3minvalue;
	unsigned char	id3maxvalue;
	unsigned char id2minvalue;
	unsigned char	id2maxvalue;
	unsigned char id1minvalue;
	unsigned char	id1maxvalue;
	unsigned char id0minvalue;
	unsigned char	id0maxvalue;
	unsigned long *eventtimespointer;   
};

union EVENTPOWERONDEALFLAG
{
       struct
       {
         unsigned char b0:1;   
         unsigned char b1:1;   
         unsigned char b2:1;   
         unsigned char b3:1;   
         unsigned char b4:1;   
         unsigned char b5:1;   
         unsigned char b6:1;   
         unsigned char b7:1;   

         unsigned char b8:1;   
         unsigned char b9:1;
         unsigned char b10:1;
         unsigned char b11:1;
         unsigned char b12:1;
         unsigned char b13:1;
         unsigned char b14:1;
         unsigned char b15:1;	   
       }bit;
       unsigned int  intd;                                          
};

struct	RST90E36_STRUCTURE
{
	unsigned long totalnum;
	
	unsigned char beginflag;
	unsigned int  counter;
	
	unsigned char time[5];
	unsigned int praerrnum;
	unsigned int rderrnum;
	unsigned int valerrnum;   
};

struct EVENT_REPORT_STATUS_TIMES
      {
       unsigned char Switch_err_times; 
       unsigned char ESAM_err_times; 
       unsigned char Eeprom_init_err_times; 
       unsigned char Clock_Battery_Volt_low_times; 
       unsigned char Code_err_times; 
       unsigned char Memorizer_err_times; 
       unsigned char NO_Use0;
       unsigned char Clock_err_times; 

	unsigned char LowPower_Battery_Volt_low_times; 
       unsigned char Overdraft_times; 
       unsigned char Open_Meter_Cover_times; 
       unsigned char Open_Rail_Cover_times; 
       unsigned char ConstantMagnet_event_times; 
       unsigned char PowerAbnormal_event_times; 
       unsigned char Switch_off_times; 
       unsigned char Switch_on_times; 

	unsigned char LostVolt_A_times; 
       unsigned char LowVolt_A_times; 
       unsigned char OverVolt_A_times; 
       unsigned char LossCurr_A_times; 
       unsigned char OverCurr_A_times; 
       unsigned char UpLoad_A_event_times; 
       unsigned char PowerReserve_A_times; 
       unsigned char BreakPhase_A_event_times; 

	unsigned char BreakCurr_A_times; 
       unsigned char NO_Use1;
       unsigned char NO_Use2;
       unsigned char NO_Use3;
       unsigned char NO_Use4;
       unsigned char NO_Use5;
       unsigned char NO_Use6;
       unsigned char NO_Use7;

	unsigned char LostVolt_B_times; 
       unsigned char LowVolt_B_times; 
       unsigned char OverVolt_B_times; 
       unsigned char LossCurr_B_times; 
       unsigned char OverCurr_B_times; 
       unsigned char UpLoad_B_event_times; 
       unsigned char PowerReserve_B_times; 
       unsigned char BreakPhase_B_event_times; 

	unsigned char BreakCurr_B_times; 
       unsigned char NO_Use8;
       unsigned char NO_Use9;
       unsigned char NO_Use10;
       unsigned char NO_Use11;
       unsigned char NO_Use12;
       unsigned char NO_Use13;
       unsigned char NO_Use14;

	unsigned char LostVolt_C_times; 
       unsigned char LowVolt_C_times; 
       unsigned char OverVolt_C_times; 
       unsigned char LossCurr_C_times; 
       unsigned char OverCurr_C_times; 
       unsigned char UpLoad_C_event_times; 
       unsigned char PowerReserve_C_times; 
       unsigned char BreakPhase_C_event_times; 

	unsigned char BreakCurr_C_times; 
       unsigned char NO_Use15;
       unsigned char NO_Use16;
       unsigned char NO_Use17;
       unsigned char NO_Use18;
       unsigned char NO_Use19;
       unsigned char NO_Use20;
       unsigned char NO_Use21;

	unsigned char VoltReverse_times; 
       unsigned char CurrReverse_event_times; 
       unsigned char VoltImbalance_times; 
       unsigned char CurrImbalance_times; 
       unsigned char auxiliaryPower_event_times; 
       unsigned char PowerDown_event_times; 
       unsigned char OverDemand_times; 
       unsigned char Factor_Low_times; 

	unsigned char CurrCriticalImbalance_times; 
       unsigned char TotalPowerReverse_times; 
       unsigned char AllLostVoltage_times; 
       unsigned char NO_Use22;
       unsigned char NO_Use23;
       unsigned char NO_Use24;
       unsigned char NO_Use25;
       unsigned char NO_Use26;

       unsigned char Program_event_times; 
       unsigned char Meter_clear_times; 
       unsigned char Demand_clear_times; 
       unsigned char Event_clear_times; 
       unsigned char AdjustTime_event_times; 
       unsigned char ProgDailySlot_times; 
       unsigned char ProgYearSlot_times; 
       unsigned char ProgWeek_times; 

       unsigned char ProgHoliday_times; 
       unsigned char ProgAEMode_times; 
       unsigned char ProgNEMode1_times; 
       unsigned char ProgNEMode2_times; 
       unsigned char ProgBillDay_times; 
       unsigned char ProgTriffPrice_times; 
       unsigned char ProgStepPrice_times; 
       unsigned char PSWUpdate_times; 
      };
union EVENTSTATUS_FLAG
{
   struct
   {
       unsigned char PowerAbnormal_event:1;
       unsigned char Meter_clear:1;
       unsigned char Demand_clear:1;
       unsigned char Event_clear:1;
       unsigned char AdjustTime_event:1;
       unsigned char ProgDailySlot:1;
       unsigned char ProgYearSlot:1;
       unsigned char ProgWeek:1;
       
       unsigned char ProgHoliday:1;
       unsigned char ProgAEMode:1;
       unsigned char ProgNEMode1:1;
       unsigned char ProgNEMode2:1;
       unsigned char ProgBillDay:1;
       unsigned char ProgTriffPrice:1;
       unsigned char ProgStepPrice:1;
       unsigned char PSWUpdate:1;

       unsigned char auxiliaryPower_event:1;
       unsigned char Eeprom_init_err :1; 
       unsigned char Memorizer_err:1; 
       unsigned char powertreverse:1; 
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
        
       unsigned char Overdraft:1; 
       unsigned char Switch_on:1; 
       unsigned char ESAM_err:1; 
       unsigned char Switch_err:1; 
       unsigned char Clock_err:1; 
       unsigned char Clock_Battery_Volt_low :1; 
       unsigned char LowPower_Battery_Volt_low:1; 
       unsigned char Switch_off:1;
       
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
       unsigned char :1;
   }bit;
   unsigned char byte[5];                                          
};	  


 
 
#line 10 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/ram.h"
  








#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 10 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/ram.h"



 
extern volatile unsigned long                     Freq[4]; 
extern volatile unsigned long                     Volt[3];
extern volatile unsigned long                     Voltc[3];
extern volatile unsigned long                     Curr[3];
extern volatile unsigned long                     Factor[4];           
extern volatile unsigned long                     Active_power[4];
extern volatile unsigned long                     Reactive_power[4];
extern volatile unsigned long                     Active_energy_per_sec;
extern volatile unsigned long                     Reactive_energy_per_sec;
extern volatile unsigned long                     Visual_power[4];
extern volatile unsigned char                     Reactive_phase[4];
extern volatile unsigned long                     Phase_Angle[4];
extern volatile unsigned long                     N_Current;
 
extern volatile struct METER_STATES               Meter_States;

extern volatile struct NEW645METER_STATES             NEW645Meter_States; 

extern volatile struct METER_PARAMETER            Meter_Parameter;

extern union EVENT_POWER_NET_FLAG       Event_Power_Net_Flag;
 
 
extern struct EVENT_POWER_NET_POINTER    Event_Power_Net_Pointer;
extern struct EVENT_METER_PRO_POINTER    Event_Meter_Pro_Pointer;
extern struct EVENT_POWER_NET_TIMES      Event_Power_Net_Times;
extern struct EVENT_METER_PRO_TIMES      Event_Meter_Pro_Times;
extern struct EVENT_POWER_NET_TIMETICKS  Event_Power_Net_Timeticks;

extern struct POWERDOWN_SAVE_DATA        Powerdown_Save_Data;

extern struct ENERGY_RAIL_ADD_BUFFER     energy_rail;

extern struct THIS_MONTH_DATA            This_Month_Data;

 

extern struct OTHER_DATA                 Other_Data;

 

 

 

extern struct POWERRESERVE_ENERGY_SING   CurrentImbalance_Energy[3];

extern union  CoBuff                     Co; 

extern unsigned char                     WriteWhitchEeprom[3];

extern struct ENERGY_POWERDOWN           Cal_PowerDown_Energy_add;

extern union  BYTE_BIT                   TimeChontrolFlag;

extern union  BYTE_BIT                   ProgramRunPhaseFlag;

extern union  BYTE_BIT                   WriteTimeFlag;

extern union  BYTE_BIT                   Event_Time_Flag;
extern union  BYTE_BIT                   Alarm_Map_Flag[3];

extern struct DATEANDTIME_DEF            MainSoftDate;

extern struct DATEANDTIME_DEF            MainRamDate1;

extern struct DATEANDTIME_DEF            MainRamDate2;

extern struct OTHER_METER_PARAMETER      O1ther_Meter_Parameter;  
extern unsigned char                     Max_Triff_Current;  
extern volatile unsigned long         Active_power_Per_Mintue;     
 

extern volatile int Temperature_Current; 
extern struct Show_Powerdown_Data_Struct Show_Powerdown_Cyc_Data[99];
extern struct Show_Powerdown_Data_Struct Show_Powerdown_Key_Data[120];
extern unsigned char Show_ID_vatiy;
extern union EVENT_POWER_NET_FLAG       Show_Powerdown_Net_Flag_Backup; 
extern unsigned char Show_flash_poweron_vatiy;
extern unsigned char show_which_now;

 
 

 
extern void Check_Max_Imbalance_Rate(void);



  
#line 11 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
#line 12 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.h"
 
 




#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/MB_BASE_FUN.h"














































































 
 
 
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
 




 






















 




 














































 




























    
#line 7 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 8 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/ram.h"
  





































































































  
#line 9 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
#line 10 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.h"





 


 
struct DATE_TIMENOSEC_5BYTE
{
  unsigned char Year;    
  unsigned char Month;   
  unsigned char Day;     
  unsigned char Hour;    
  unsigned char Minute;  
};

union DATE_TIMENOSEC_4BYTE
{
	unsigned long l;
	struct 
	{
		unsigned long Year:7;    
		unsigned long Month:4;   
		unsigned long Day:5;     
		unsigned long Hour:5;    
		unsigned long Minute:6;  
		unsigned long :5;       
	}bit;
};


struct RECORD1
{
	unsigned char VA[3];
	unsigned char VB[3];
	unsigned char VC[3];
	unsigned char IA[3];
	unsigned char IB[3];
	unsigned char IC[3];
	unsigned char Freq[2];
};
struct RECORD2
{
	unsigned char ActiveFlag;
	unsigned char ReactiveFlag;
	unsigned char PA[3];
	unsigned char PB[3];
	unsigned char PC[3];
	unsigned char PAll[3];
	unsigned char RA[3];
	unsigned char RB[3];
	unsigned char RC[3];
	unsigned char RAll[3];
	unsigned char SA[3];
	unsigned char SB[3];
	unsigned char SC[3];
	unsigned char SALL[3];
	unsigned char no_ues[4];
};
struct RECORD3
{
	unsigned char Factor[2];
	unsigned char FactorA[2];
	unsigned char FactorB[2];
	unsigned char FactorC[2];
};
struct RECORD4
{
	unsigned long PP;
	unsigned long NP;
};
struct RECORD5
{
	unsigned long Quad1;
	unsigned long Quad2;
	unsigned long Quad3;
	unsigned long Quad4;
};
struct RECORD6
{
	unsigned char DemandActive[3];
	unsigned char DemandReactive[3];
};

struct RECORD
{
	union DATE_TIMENOSEC_4BYTE Save_DateTime;
	char Mode_Byte;
};

union LONG_BYTE
{
	long Long_data;
	unsigned char byte[4];
};

struct LOADINDEX
{
	unsigned int PageAddress : 12;
	unsigned int :2;
	unsigned int ByteAddress : 10;
};
struct MINUTE_POWER_DATA
{
	unsigned long Active_power_sum[4];
	unsigned long Reactive_power_sum[4];
	unsigned char Active_power_num[4];
	unsigned char Reactive_power_num[4];
	   signed long Active_power_last_data[4];
	   signed long Reactive_power_last_data[4];

};
struct  Sort_flag_bit_def
{
     char result:1;
     char equ:1;
     char big:1;
     char flag:1;
     char :1;
     char :1;
     char :1;
     char :1;
};
union Sort_flag_def
{
	struct  Sort_flag_bit_def bit;
	char	byte;
};

union FlashAddr32M
{
    unsigned long addr;
    struct 
	{
		unsigned char Byte0;
		unsigned char Byte1;
		unsigned char Byte2;
		unsigned char Byte3;
	}AsByte;
    struct 
	{
		unsigned long Pdummy:8;
		unsigned long Paddr:24;
	}PageAddr;
    struct 
	{
		unsigned long Sdummy:12;
		unsigned long Saddr:20;
	}SectorAddr;
};
union FLASH_ERR_STATUS_FLAG
{
    struct Flash_Err_Status_Un
    {
        char ChipEraseErr:1;
        char SectorEraseErr:1;
        char WritePageErr:1;
        char WriteEnableErr:1;
        char WriteDisableErr:1;
        char :1;
        char :1;
        char :1;
    }Flash_Err_Status_str;
    unsigned char Flash_Err_Status;
};





struct LOADRECORD_NEW                                                                                                 
{		                                                                                                        
        
       unsigned int BlockAddress;                                                                         
       unsigned int LastBlockAddress;                                                      
       unsigned int LastBlockAddress1[6];      
       struct DATA_TIME  LastRecordTime;      
       unsigned long LoadRecordPointer;  	    
        
       
        
       union    BYTE_BIT   First_Flag;   
       unsigned int FirstBlockAddress1[6];   
        
       
        
       struct                                                                                                          
	     {                                                                                                               
		     char NeedSaveIndex:1;	 
		     char reStart:1;			    
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
		     char :1;                                                                                                
	     }LoadRecordFlag;
	      
	     
	     struct                                                                                                          
	     {                                                                                                               
		     unsigned int Last_Read_BlockAddress;                           
       }ReadHistory[3];  	                                                                                                                
	                                                                    
};   
 
extern struct LOADRECORD_NEW LoadRecord;
extern struct DATETIME SoftDate;  
extern unsigned long FlashEaseTimes;

extern unsigned char user_req_pnt;

 
extern void SendByte(char *rData);

extern int WriteBuffer(unsigned int rStartAddr, unsigned int rLength, 
	unsigned char *rData);


extern unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag, struct DATA_TIME *rDate);

extern int SwitchPage(void);


extern void ReadBuffer(unsigned int rStartAddr, unsigned int rLen, 
	unsigned char * rData);


extern int SaveBuffer(unsigned int rPageAddress);

extern int LoadToBuffer(unsigned int rPageAddress);

extern unsigned char GetRecordLength(const unsigned char rMode);

extern int InitSIO4(void);

extern int FindRecord(struct DATA_TIME *rDate, unsigned int *rPage,unsigned char sort);

extern int SaveIndex(struct DATA_TIME *rDate);

extern int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx);
extern int InitLoadRecord(void);
extern void First_InitLoadRecord(void);

extern int SaveLoadRecord(void);


extern void Minute_Power(char channel);
extern void Write_Enable(void);
extern void Write_Disable(void);
extern unsigned char Read_Status_Register(void);
extern unsigned char Write_Status_Register(unsigned char status);
extern void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);
extern int  Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
extern unsigned char Continuously_Program(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
extern int  Chip_Erase(void);
extern int  Sector_Erase(unsigned long FlashAddr);
extern int Check_Sector_Have_Erased(unsigned long Faddr);
extern void FastRead_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);

extern void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4);
extern void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
extern signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);



extern int check_id_error(unsigned char di0, unsigned char di1);
extern int read_record_base_time_id(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
								char mode,unsigned char uartx);

extern void time_add_minute(struct DATA_TIME *req_tm, unsigned int len);
extern unsigned int get_hour_in_year(struct DATA_TIME *rDate);
int Save_5Min_Index(struct DATA_TIME *rDate);
int find_record_in_cur_5min_frm_min_idx(unsigned char st, struct DATA_TIME req_tm, unsigned char cmp,unsigned int min_blk, unsigned int *read_blk);
int get_5min_idx_by_time(struct DATA_TIME *rDate, unsigned int *blk);


 
#line 13 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/I2C_operation.h"


					 				
 
extern unsigned char Write_Read_FM24C256(unsigned int Card_Addr,	 
							 		unsigned char *DataPointer,		 
						 	 		unsigned int Data_Length,		 
						 	 		unsigned char DeviceName,		 
						 	 		unsigned char OperationType);	 
						 	 							 	 		
extern void	PowerOn_PCF8576(void);
extern void	PowerOff_PCF8576(void);
extern unsigned char IIC_SOFT_RESET(void);
extern void Check_IIC_State(void);
							 			
extern void ClockChipInit(unsigned char def);
extern void ClockChipRead(unsigned char *t);
extern void ClockChipWrite(unsigned char *t);
extern void ClockChipOpenSec(void);
extern void ClockChipCloseSec(void);
extern void IIC_Delay(int number);

#line 14 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/eventnew.h"
  





















































































































 

 
#line 15 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/COMM.h"


  


extern unsigned char CommB[3][230];
extern unsigned char ProgramEventFlag;
extern union  BYTE_BIT JustMeterDataFlag;
extern struct DATEANDTIME_DEF JustMeterDateFlag;    
extern unsigned char  JustMeterFlag;                
extern struct FindCommand_Result cx[4];            
extern unsigned char    Readdata_buff[32]; 
 
extern signed long     COMM_Curr[3]; 
extern signed long     COMM_Factor[4];            
extern signed long     COMM_Active_power[4]; 
extern signed long     COMM_Reactive_power[4]; 
extern signed long     COMM_Visual_power[4]; 
extern signed long	    COMM_Current_Demand[2]; 
extern unsigned char    Freeze_Flag_DayHour[2];																									 

extern unsigned char    Comm_DailyOrYear_Slot; 
extern unsigned char    Comm_Firrespon_SecDispos_Buff[42]; 																								 
extern unsigned char    Comm_Firrespon_SecDispos_Uart[3];

 
 
 
 


extern unsigned char GPRS_Status; 
                                           
extern  unsigned int  Voltage_ad_data[2]; 
extern unsigned char Displayfinish_flag; 
extern unsigned int  FullScreenTime; 
extern volatile unsigned  char ad_Flag;   
extern volatile unsigned  char ad_finish_Flag; 
extern unsigned long meter_model_ok; 
 
extern volatile unsigned int  fix_ad_data ; 

extern unsigned long comm_plus_energy_01wh[9        ][2];  
extern unsigned long comm_nega_energy_01wh[9        ][2];  

extern void Init_Comm(unsigned char);
extern void Interr_Comm_R(unsigned char);
extern void Interr_Comm_W(unsigned char);
extern void Communication(unsigned char,unsigned char,unsigned char);
extern unsigned char FindComCommand(unsigned char,unsigned char);
extern unsigned char AnswerComCommand(unsigned char,unsigned char);
extern signed int    TransferData(union ID ,unsigned char *,unsigned int,unsigned char,
                                  unsigned char*,unsigned char );
extern unsigned long GetNowTime(void);  
extern unsigned char GetTimeCount(unsigned long,unsigned long); 
extern unsigned char F_Ar(unsigned char,unsigned char);  
 
 
 
extern void ReadData(unsigned char);   
extern void WriteData(void);   
extern void BroadcastJustTime(void);
extern void WriteAddress(void);
extern void WriteBaud(void);    
extern void WritePassword(void);
extern void ClearDemand(void); 
extern unsigned char R_W_Data(void);
extern unsigned char ReadLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
extern unsigned char WriteLC256(unsigned int,unsigned char *,unsigned int,unsigned char);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void HexToACK(unsigned char *,unsigned char *,unsigned int );	   
extern void BcdToHex(unsigned int,unsigned char *,unsigned char * );	   
extern void ACKToHex(unsigned char *,unsigned char *,unsigned int );  
extern unsigned char GetRecordAddr(unsigned char,unsigned char,unsigned char);  
extern void Delay(unsigned int);
extern unsigned char CalDay(unsigned char,unsigned char);
extern double long ComTime(unsigned char *,unsigned char *);
 

extern unsigned char  ClearDemandCommAndKey(unsigned char ,unsigned char);
extern void Clear_PasswordErr(unsigned char,unsigned char );
extern void CheckProgramKeyState(void); 
extern void IC_Set_Program(void);
 

extern signed int FreezeEvent_Energy(unsigned char * ,unsigned char * );
 
extern int  Read_SystemTime_YMDH(void);
extern int  Read_SystemTime_HMS(void);
extern int  Set_SystemTime_YMDH(void);
extern int  Set_SystemTime_HMS(void);
extern int  Set_DemandPeriod(void);
extern int  Set_DemandSkipPeriod(void);
extern int  Set_Activem_Erengy_Mode(void);
extern int  Set_REActivem_Erengy_1_Mode(void);
extern int  Set_REActivem_Erengy_2_Mode(void);
extern int	Set_ActivePulseConst(void);
extern int  Set_Erengypoint(void);
extern int  Set_BILL_Day(void);
extern int  Set_SlotParemeter(void);
extern int  Set_YearSlot(void);
extern int  Set_ProgWeek(void);
extern int  Set_Holiday(void);
extern int  Set_DailySlot(void);
extern int  Set_LoadRecoedBeginTime(void);
extern int  Set_LoadRecoedPeriod(void);
extern int  Set_MeterMode(void);
extern int  Set_Meterlocktimes(void);
extern int  Set_OutputModel(void);
extern int  Exit_WorkRoomState(void);
extern int  Read_primary_energy(void);
extern int  Set_primary_energy(void);
extern int  Read_WorkRoomState(void);
extern int  Read_Freeze_Bit_0_data(void);
extern int  Read_Freeze_Bit_1_data(void);
extern int  Read_Freeze_Bit_2_data(void);
extern int  Read_Freeze_Bit_3_data(void);
extern int  Read_Freeze_Bit_4_data(void);
extern int  Read_Freeze_Bit_5_data(void);
extern int  Read_Freeze_Bit_6_data(void);
extern int  Read_Freeze_Bit_7_data(void);
extern int  Read_Freeze_Block_data(void);
extern int  Read_Meter_lock_times(void);
extern int  Check_Parameter_Len_IS_ok(unsigned char trans_format);
extern int  Pre_No_use_leaf_data(void);
extern int  Set_Display_Number(void);
extern int  Set_Commrate(void);
extern int  Read_Freeze_Date(void);
extern int  Set_CycleDisplayTime(void);
extern int  Read_Far_IR_Commate();
extern int  Set_CriticalVoltage(void);
extern int  Set_CommAddr(void);
extern int  Set_Show_USER_Code(void);
extern int  Read_Sign_Instance_Variable(void);
extern int  Read_Meter_Temperature(void);
extern int  Read_YearSlot_Table(void);
extern int  Read_DailySlot_Table(void);
extern int  Comm_Initialize_FLASH(void);
extern int  Read_Last_loss_voltage_start_time(void);
extern int  Read_Last_loss_voltage_end_time(void);
extern int Set_Freeze_Period_Begin_time(void);
extern int Set_Freeze_Period(void);
extern int Set_TriffSwitchDate(void);
extern int Set_Cycle_Key_Display(void);
extern int  Read_Meter_FILEDATE_VI(void);

extern unsigned char* CommBP;
extern struct FindCommand_Result * CurrPC;
extern unsigned char WriteDateBuff[];
extern int Set_ShowNoKeyRetTime(void);
extern unsigned char CheckPasswordRight(unsigned char *);
extern void CheckPasswoerErr(unsigned char );
extern void AppointTrasfPortBuff(unsigned char );
extern unsigned int Crc16l(unsigned char *ptr,unsigned char len);
extern void Set_which_Responsion_Flag(unsigned char Which,unsigned char flag);
extern int Set_JFPG_Triff(void);

extern void Set_Meter_para_Deal(unsigned int rom_addr);
extern int  Read_Display_Number(void);   

 
extern int Read_LostVoltEnergy(void);
extern int Read_LostVolt_AllEnergy(void);
extern void RTC_Init(void); 
extern void PowerOn_FullScreen_TimeDetection(void); 

extern int ReadClockBatteryVoltage(void);
extern int ReadDisplayBatteryVoltage(void);

extern int ReadEventReportInfo(void);
extern int GetEventReportMode(void);
extern int SetEventReportMode(void);

extern int SetPowerOnFullScreenTime(void);

extern int Set_SystemTime_YMDHHMS(void);

extern int GetMeterSoftIdNumber(void);
extern int SetMeterSoftIdNumber(void);

extern int GetNowMonthComActiveEnergy(void);
extern int GetLastMonthComActiveEnergy(void);

extern int Set_Freeze_Day(void);

extern int ReadEnergy01Wh(void);

extern int ResetEventReportInfo(void);
extern void Clear_EventReportStatus_And_Times(union EVENT_REPORT_STATUS EventReportStatus);
extern int Set_ResetReportTime(void);

extern int Set_Read_Block_Para(union ID id,unsigned char *rBuffer,unsigned char data_len,unsigned char mode);


 
#line 16 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/645_2007.h"
 
 
 
 
 
 






struct COMM_STAUT
{
	unsigned char password_level; 
	unsigned char meter_staut; 
};
struct ITERATE_TREE_FLAG{
 	
	unsigned int num; 
	unsigned int last_num; 
	union  BYTE_BIT flag; 
	unsigned int    File_name; 
	unsigned char Set_Prarmeter_flag; 
	unsigned char  Show_bit_flag; 
	unsigned int  Back_Flame_Serial; 
	unsigned int last_num_save; 
};
struct TREEADDR_FLASH
{
	 
	 
	 
	unsigned long  addr:12;
	unsigned long filename:16;
	unsigned long path:4;

};
struct TREEADDR_RAM
{
	 
	 
	unsigned long addr:28;
	unsigned long path:4;
};

union TREEADDR{
	unsigned long	val;
	struct TREEADDR_RAM ram; 	
	struct TREEADDR_RAM  eeprom;	
	struct TREEADDR_FLASH flash;	
};



extern struct ITERATE_TREE_FLAG Iterate_Tree_Flag[4];	
extern struct COMM_STAUT Comm_Staut;
extern unsigned int Leaf_num_now;
extern union ID Read_Com_ID;


extern signed int    TransferData_New(union ID id,unsigned char *P, unsigned int L,
                         unsigned char formatdata,unsigned char *format,unsigned char mode,
                         unsigned char data_len,unsigned char uartx);
 
 
 
extern unsigned char math_Add(unsigned char * startaddr,unsigned char * getbuff ,
							   unsigned char math_mode,unsigned char format,
							   unsigned char Ass_num,unsigned char Ass_addr, unsigned int  file_name);
 
 
 
 
 
 
 
extern unsigned char math_Demand(unsigned char * startaddr,unsigned char * getbuff ,
								    unsigned char math_mode,unsigned char format,
								    unsigned char Ass_num,unsigned char Ass_addr, unsigned int file_name);
 
 
 
 
extern int Check_Data_valid(unsigned char  *buff_t, unsigned char len);

 

#line 17 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/Demand.h"




#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
#line 5 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/Demand.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 6 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/Demand.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/MB_BASE_FUN.h"














































































 
 
 
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
 




 






















 




 














































 




























    
#line 7 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/Demand.h"




 
struct DATETIME_DEMAND
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Minute;
};

 
 
 
 
 
 
 
 
 

struct DEMAND_AREA
{
	unsigned long energy_l[6];
	unsigned long energy_h[6];
	unsigned long time;
	
};

struct DEMAND_DATA_NEW
{
	struct DEMAND_AREA Demand_Area[60 ]; 	
	unsigned char Head[2];
	unsigned char Rail[2];		
	unsigned char CheckSum;  
};
 
 
 




 

extern unsigned char TRAFF_RATE;  
extern struct DEMAND_DATA_NEW Demand_Data_New;
 

extern struct DEMAND_CONTROL GDemandControl;  
extern unsigned long  Last_Average_Value[8 ][9        ];   
extern signed long	Current_Demand[2];
 

 

extern unsigned char demand_start;	
extern unsigned char demand_init;


 


extern int ClearDemandArea(unsigned char mode);
extern void Demand_New_Init(void);
extern void Demand_New_Main(void);
extern void Demand_Accumulator(void);

extern unsigned char DemandputoutNum;
extern unsigned char DemandOutPutflagdata;
extern void Demand_Triff_Change(void);
extern unsigned long  Last_Average_Value[8][9        ];  

 
#line 18 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/datachange.h"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/MB_Base_Fun.h"














































































 
 
 
extern unsigned char OB_H(unsigned char bcd);
extern unsigned char OH_B(unsigned char hex);
extern unsigned char CheckTime(unsigned char *time);
extern unsigned char CheckBCD(unsigned char data);
extern unsigned char CheckBCD_NByte(unsigned char *input,unsigned char n);
extern unsigned long ABS(signed long rData);
extern signed long ten_seq(signed char seq);
extern void HexToBcd(unsigned int,unsigned char *,unsigned char *);	  
extern void BcdToHex(unsigned int,unsigned char *,unsigned char *);	
extern void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
extern int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
extern void HexToACK(unsigned char *point1,unsigned char *point2,unsigned int len);
extern void ACKToHex(unsigned char *point1,unsigned char *point2,unsigned int len);
extern unsigned long search_unit(unsigned char unit_flag);
extern void HexToBcdnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern void BcdToHexnByte(unsigned char n,unsigned char *src_data,unsigned char *dest_data);
extern unsigned char* memcpy(unsigned char *Dest,unsigned char *Src,unsigned char len);
extern signed long format_data(signed long input,unsigned char mode);
 




 






















 




 














































 




























    
#line 2 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/datachange.h"





 
 
 
extern unsigned char sizeof_format(unsigned char format);
extern unsigned char TimeToLong(struct DATA_TIME date,unsigned long *dest_data);
 
extern unsigned char data_change(unsigned char *src_data,unsigned char *dest_data,
                                 unsigned char in_format,unsigned char out_format,
				                         unsigned char in_unit,unsigned char out_unit,
					                       signed char in_exp,signed char out_exp);
extern unsigned long TimeIndex(unsigned char  *TimePtr);
extern unsigned char IsLeapYear(unsigned  char year);	  
extern void CalWeek(unsigned char *Addr); 
extern unsigned int  const       Not_Rong_Year[];  
extern unsigned int  const       Rong_Year[];  





#line 19 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/Multi.h"



struct ENERGY_BACK
{
    	    unsigned long  Plus_Active[9        ]; 
	    unsigned long  Nega_Active[9        ];
	
	    unsigned long  Quad_Reactive[4][9        ];
}; 
extern unsigned char TRAFF_RATE;
extern unsigned char OLD_TRAFF_RATE;
extern unsigned char ErrEnergyNumber;
extern unsigned char WriteEE_Or_F;     
extern struct ENERGY_BACK  energy_back;
extern unsigned char ClockBatteryClear_Flag[8];   
extern unsigned char ClockBatteryClearCounter;
extern unsigned char TempClockBatteryClearCounter;   

extern unsigned char Light_Back_Up_Flag; 
extern unsigned char   Event_Report_flag; 
extern unsigned char   open_cover_reported; 
extern unsigned char RamData_Valid_flag[16];
extern union EVENT_REPORT_STATUS  Event_Report_Status;
extern struct EVENT_REPORT_STATUS_TIMES Event_Report_Status_Times; 
extern union EVENTSTATUS_FLAG EventStatus_flag;
extern union EVENT_REPORT_STATUS  Event_Report_Status_Backup;
extern union EVENT_REPORT_STATUS  Event_Report_Status_communication;
extern unsigned char   Event_Report_Iterate_flag;
extern unsigned int  powerup_init_time;

extern void PowerUpProcese(void);
extern void FeedWatchdog(void);
extern void CheckPowerDown(void);
extern void Measure(void);
extern void OpenCoverCheck(void);
 
 
extern void ReadRTC(void);
extern void BackupDataToEeprom(void);
extern void FindTriff(void);
extern unsigned char BackUpEnergyToRam(void);
extern unsigned char  CheckRamTime(void);
extern void Monitor_Program(void);
extern void Light_Back_Led(void);
extern void Close_Back_Light(void);
 
extern void CheckChange(unsigned char kind,unsigned char type ); 
extern void CheckState(void);
extern void FreezeData_All(unsigned char ,unsigned char );
extern signed long Cal_EnergyLimit(void);
 
 
 
 
extern void Bill_New(void);
extern unsigned char Check_Billdate_Validity(unsigned char* date,unsigned char number);
extern void RailEnergyValidity(void); 
extern void CheckState_New645(void); 
extern void PowerUpLossTotalVoltage(void);

 
 

extern void Meter_Para_Check(void);
extern void Check_If_Clear_all(void);
extern void ClearClockBatteryTime(void);   
extern unsigned char IsChangeBattery(void); 
extern unsigned char  LastMouthDayNumber(void); 
extern unsigned char ISAutoBillDay(void); 

extern unsigned int CRC(unsigned char *startaddr, unsigned int len);
 
extern void Meter_Staut_Check_And_Count(void); 

extern void Event_Report_Status_Chk(unsigned char kind);
extern void Get_Event_Report_Status(union EVENT_REPORT_STATUS *EventReportStatus);

extern void Clear_ALLEventReportInfo_NO_ACK(void);
extern void EventReportState_Expand(unsigned char Nbyte, unsigned char n,unsigned char State);
extern void ESAM_ErrReport(void);
extern void SwitchOn_Report(void);
extern void SwitchOff_Report(void);
extern void Overdraft_Report(void);

#line 20 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"

#line 1 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/initram.h"
extern void	IniRam(void);
extern unsigned char CheckEnergyRom1AndRom2(unsigned char *ram1,unsigned char *ram2); 
extern unsigned char checkEnergyRight(unsigned char *scr_addr,unsigned char number,
                               unsigned char *des_addr,unsigned long range,
                               unsigned char comflag);
extern void Write_TO_Cal_PowerDown_Energy_add(void);      
extern void SetDefault(void);                         
extern void Retort_New(unsigned char,unsigned char*);

extern unsigned char TotalEnergyRight( struct ENERGY_RECORD *scr_addr,const unsigned char which);
extern unsigned char  ALL_TotalEnergyRight(struct ENERGY_RECORD *scr_addr);
extern unsigned char  EnergyAutoRectifyLevel1(void);
extern unsigned char EnergyAutoRectifyLevel2(void);
 
extern void Powerdown_to_ThisMonth(void);
 
extern unsigned char CheckEnergyPowerEnergy(struct ENERGY_POWERDOWN  *ram);
 
extern void ReadMeterPara(void);
extern unsigned char IsNormalReset(unsigned char type); 
extern unsigned char IsHaveSaveData(void);
extern void Clear_Savedata_flag(void);
extern unsigned char ReadEepromEnergy(void);
extern unsigned char ReadBlock(unsigned int Card_Addr,		 
							 		unsigned char *DataPointer,	 
						 	 		unsigned int Data_Length,		 
						 	 		unsigned char DeviceName); 
						 	 						 	 		
extern unsigned char IsNormalResetWrite(void);

extern void Check_New(void);
extern void Para_Process_main(void);
extern unsigned char ReadEeprom(void);
extern void Para_Process_run(void);
extern union   BYTE_DEF  Parameter_flag[5];  
                                      
                                      
                                      
                                      
                                      
                                      
                                      
extern unsigned int para_err_times;


#line 21 "D:/TEST/12、RN8302B/HT7038 CODE_backup20160225_2016-4-22/HT7038 CODE/Release_Code/MB4_64A/LoadRecord.c"


















 









 


 


 




 
 










 
 

extern unsigned char My_Memcmp(unsigned char *,unsigned char *,unsigned char);
extern void Byte2BCD(unsigned char src_data, unsigned char *dest_data);
 
 
int WriteBuffer(unsigned int rStartAddr, unsigned int rLength, unsigned char *rData);
void FormatBCD(unsigned long rSource, unsigned char *rDesc,unsigned char rLength);
unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag,struct DATA_TIME *rDate);
int SwitchPage(void);
int ReadData_To_Cob(unsigned int  *rPageAddr,unsigned char kind); 
void ReadBuffer(unsigned int rStartAddr, unsigned int rLen,unsigned char * rData);
int CompareBytes(unsigned char *rData1, unsigned char *rData2,unsigned char rLength);
int SaveBuffer(unsigned int rPageAddress);
int LoadToBuffer(unsigned int rPageAddress);
unsigned char GetRecordLength(const unsigned char rMode);
int InitSIO4(void);
int FindRecord(struct DATA_TIME *rDate, unsigned int *rpage,unsigned char sort);
int SaveIndex(struct DATA_TIME *rDate);
int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx);
int InitLoadRecord(void);
void First_InitLoadRecord(void);

void Minute_Power(char channel);
void Write_Enable(void);
void Write_Disable(void);
unsigned char Read_Status_Register(void);
unsigned char Write_Status_Register(unsigned char status);
void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen);
int  Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
unsigned char Continuously_Program(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen);
int  Chip_Erase(void);
int  Sector_Erase(unsigned long FlashAddr);
int  Check_Sector_Have_Erased(unsigned long Faddr);
int  Get_Physicaladdress_From_Block(unsigned int block,unsigned long *addr);
int  Get_Block_From_PhysicalAddress(unsigned int* block,unsigned long addr);

 
 
int Find_Next_Record(int channel,unsigned int *rblock, unsigned char sort);
int Find_Last_Record(int channel,unsigned int *rPage);
int Find_First_Record(unsigned int *rblock,unsigned char sort);
int Find_Near_Record(unsigned int *rblock,unsigned char sort);
int Find_Addr_Record(unsigned int *rPage, unsigned int *rByte, int addr);
int Find_Data_Record(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort);

int Get_Next_Record_Addr(unsigned int Page,unsigned int *rPage,unsigned char sort);
unsigned char Add_Addr( signed int num,unsigned int *rPage);
void Change_SortAddr(unsigned char rSaveFlag,unsigned int rPage);
int Get_SortAddr(unsigned int Page,unsigned int *rPage,unsigned char sort);
int Get_SortAddr1(unsigned int Page,unsigned int *rPage,unsigned char sort);
int Get_TotalAddr(unsigned int Page,unsigned int *rPage);
unsigned char Page_equal(unsigned int Page,unsigned int *rPage,unsigned char sort);
unsigned char Cover_Addr_Find(unsigned int nPage,unsigned int *rPage);
void Save_SortIndex(unsigned char rSaveFlag,unsigned int rblock);
int SaveLoadRecord(void);

extern void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len);
extern unsigned char Card_WR_Buff[512];


void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4);
void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5);
void ConverseString(unsigned char *p,unsigned char n);


void SaveDayIndex(struct DATA_TIME *rDate);
int ThisDayHaveRecord(struct DATA_TIME *rDate);
void AddOneDay(struct DATA_TIME *rDate);
void AddOneHour(struct DATA_TIME *rDate);
int Find_Data_Record_New(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort,unsigned char kind);

 
 
 
struct MINUTE_POWER_DATA Minute_Power_Data;
unsigned char Read_Count[3];
unsigned char Fs_Buff[528];         
unsigned char Dat_Num;
struct DATA_TIME  Set_LoadRecoed_Btime;

struct LOADRECORD_NEW LoadRecord;
unsigned char First_Sort[6];
union FLASH_ERR_STATUS_FLAG  FlashErrStatus;
unsigned long FlashEaseTimes=0;


unsigned char user_req_pnt;

const unsigned char BIT_UNC[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
#pragma SECTION rom UserROMData
const unsigned int day_num[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
	
 
void Write_Data(unsigned char wdata)
{
	s4trr_addr.byte = wdata;
	while((s4ic_addr.byte & 0x08) == 0);
	s4ic_addr.byte &= 0xF7;
}
void Read_Data(unsigned char *rdata)
{
    s4trr_addr.byte = 0xFF;
	while((s4ic_addr.byte & 0x08) == 0);
    *rdata=s4trr_addr.byte ;
	s4ic_addr.byte &= 0xF7;
}
void Write_Command(unsigned char command)
{
	 
	p0_addr.bit.b0				     = 0;
	 
	s4trr_addr.byte = command;
	while((s4ic_addr.byte & 0x08) == 0);
	s4ic_addr.byte &= 0xF7;
	p0_addr.bit.b0				     = 1;
}
 
void Write_Enable(void)
{
	union BYTE_BIT state;
    unsigned int Ndelay=0;

	Write_Command(0x06   );
    do
	{
		state.byte=Read_Status_Register();
		FeedWatchdog();
        Ndelay++;
	}while((!state.bit.b1)&&(Ndelay<1000));

}
 
void Write_Disable(void)
{
    union BYTE_BIT state;
    unsigned int Ndelay=0;

	Write_Command(0x04  );
    do
	{
		state.byte=Read_Status_Register();
		FeedWatchdog();
        Ndelay++;
	}while((state.bit.b1)&&(Ndelay<1000));
}
 
unsigned char Read_Status_Register(void)
{
	unsigned char RDSR;

    p0_addr.bit.b0				     =0;
    Write_Data(0x05   );	
    Read_Data(&RDSR);
	p0_addr.bit.b0				     =1;
	return RDSR;
}

 

unsigned char Write_Status_Register(unsigned char status)
{
	unsigned int unc=0;

    Write_Enable();    
	p0_addr.bit.b0				     =0;    
    Write_Data(0x01  );
    Write_Data(status);
    p0_addr.bit.b0				     =1;
    Write_Disable();
    return 1;
}
 
void Read_Data_Bytes(unsigned long FlashAddr, unsigned char *RcvBuff,unsigned int rlen)
{
	union FlashAddr32M addrUnion;
	unsigned int i;

    if((rlen==0)||(rlen>512))
    {
      return ;
    }
	 
	p0_addr.bit.b0				     = 0;

	 
    Write_Data(0x03   );
	
	addrUnion.addr= FlashAddr;
	 
	Write_Data(addrUnion.AsByte.Byte2);
	 
	Write_Data(addrUnion.AsByte.Byte1);
	 
	Write_Data(addrUnion.AsByte.Byte0);
	 
	for(i=0; i<rlen; i++)
	{   
        Read_Data(&RcvBuff[i]);
	}	

     
	p0_addr.bit.b0				     = 1;
}

 
int Write_Page(unsigned long FlashAddr, unsigned char *WriteBuff,unsigned int tlen)
{
	union FlashAddr32M addrUnion;
	unsigned int i;
	union BYTE_BIT state;
	unsigned char unc=0;
    unsigned int Ndelay=0;

    addrUnion.addr=FlashAddr;
    if(((addrUnion.AsByte.Byte0+tlen)>256)||(tlen==0))
    {
      return -1;
    }
	Write_Enable();

     
	p0_addr.bit.b0				     = 0;
    
	 
    Write_Data(0x02   );
	
	addrUnion.addr= FlashAddr;
	 
    Write_Data(addrUnion.AsByte.Byte2);
	 
    Write_Data(addrUnion.AsByte.Byte1);
	 
    Write_Data(addrUnion.AsByte.Byte0);

	 
	for(i=0; i<tlen; i++)
	{    
        Write_Data(WriteBuff[i]);
	}	
	 
	p0_addr.bit.b0				     = 1;    
    Delay(1);

	do
	{
		state.byte=Read_Status_Register();
        Ndelay++;
        FeedWatchdog();
	}while((state.bit.b0)&&(Ndelay<=50000));

     
    Write_Disable();
    
    if(Ndelay<50000)
        return 0;
    else
        return -1;
}
 


























































 





int Chip_Erase(void)
{
	union BYTE_BIT state;
    unsigned long Ndelay=0;

	Write_Enable();

    p0_addr.bit.b0				     =0;
    Write_Data(0x60   );
	p0_addr.bit.b0				     =1;
    
    Delay(5);
	do
	{
		state.byte=Read_Status_Register();
        Delay(1);
        Ndelay++;
        CheckPowerDown();
	}while((state.bit.b0)&&(Ndelay<=100000L));

    Write_Disable();

    if(Ndelay<100000L)
        return 0;
    else
        return -1;
    
}
 





int Sector_Erase(unsigned long FlashAddr)
{
	union FlashAddr32M addrUnion;
	union BYTE_BIT state;
    unsigned long Ndelay=0;

	Write_Enable();	
	
	p0_addr.bit.b0				     =0;
    Write_Data(0x20   );

	addrUnion.addr= FlashAddr;
	 
	 
    Write_Data(addrUnion.AsByte.Byte2);
	 
    Write_Data(addrUnion.AsByte.Byte1);
	 
    Write_Data(addrUnion.AsByte.Byte0);
	p0_addr.bit.b0				     =1;
    
    Delay(5);
	do
	{
		state.byte=Read_Status_Register();
        Delay(1);
        Ndelay++;
        CheckPowerDown(); 
        
    }while((state.bit.b0)&&(Ndelay<=500));

    Write_Disable();

    FlashEaseTimes++;
    
    if(Ndelay<500)
        return 0;
    else
        return -1;

}
 




void ReadID(unsigned char *ManufacturerID,unsigned char*DeviceID)
{
    unsigned int unc;

    p0_addr.bit.b0				     =0;

    for(unc=0;unc<255;unc++);
    Write_Data(0x9F   );
    Read_Data(ManufacturerID);
    Read_Data(DeviceID);

    p0_addr.bit.b0				     =1;
}
 

 
 
 
 

 
 
 
int ReadData_To_Cob(unsigned int* rblockAddr,unsigned char kind)
{
     unsigned char i,tmp,nLength;     
     unsigned int  nblock,mmblock;
     union FlashAddr32M FlashAddr;
     struct DATEANDTIME_DEF   recordtime;

     nblock=*rblockAddr;  
     
     if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddr.addr))
         return -1;

      
     nLength = (kind >= 2)?7:32  ;
     Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&Co.b[0],nLength); 
     DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&recordtime);
     recordtime.Sec=0;
     if((Co.b[0]!=0xaa)||(Co.b[1]>4)||(Co.b[1]==0)||(!CheckTime((unsigned char*)&recordtime.Year)))
		return -1;
     
     mmblock=nblock+Co.b[1];
     
     if(kind==0 || kind == 3) 
        return 0;

     
    if(kind==1) 
    {
        tmp=32  ;
        nblock++;
        for(i=1;i<Co.b[1];i++)
        {
              if(nblock>=62976  )
              {               
                 nblock=0;
                 FlashAddr.addr=0x00014000  ;
              }
             
              if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddr.addr))
                return -1;
              Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&Co.b[tmp],32  );
              tmp+=32  ;
              nblock++;
        }
        return 1;
    }
     
    if(mmblock>=62976  )
    {
         
        mmblock = mmblock % 62976  ;
    }    
   
    *rblockAddr=mmblock;
    FeedWatchdog();
	return 2;
}
 
 
unsigned char NeedToRecord(struct DATA_TIME *rTime)
{
	unsigned char mask;
	unsigned char i;
	unsigned char flag;
	unsigned int timeCounter;
	unsigned char temp;

	mask = 0x01;
	flag = 0;

	if(Meter_Parameter.parameter2.LoadRecordMode.byte==0)
	{
		return 0;
	}
	

	BCD2Byte(rTime->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(rTime->Min, &temp);
	timeCounter += temp;
	
	for(i=0; i<6; i++)
	{
		 
		{
			if(timeCounter % Meter_Parameter.parameter2.LoadRecordPeriod[i] == 0)
				flag |= mask;
		}
		mask <<= 1;
	}
    
	return (Meter_Parameter.parameter2.LoadRecordMode.byte & flag);
}

 
 
int ComposeRecord1(struct RECORD1 *rRecord)
{	
	unsigned int i;
	unsigned char* p;
     	
	p = (unsigned char*)&rRecord->VA[0];
	for(i=0; i<3; i++)
	{
		FormatBCD(Volt[i]/100, p, 3);
		p +=  3;
	}
	 
 	for(i=0; i<3; i++)
	{
		data_change((unsigned char *)&COMM_Curr[i],p,0x01 ,0x13 ,0,0,-4,-3);		
		p +=  3;
	}
    
	 
	FormatBCD(Freq[0]/10000, rRecord->Freq, 2); 
			
	return 0;
}

 
 
int ComposeRecord2(struct RECORD2 *rRecord)
{
       	
      unsigned char i;
      union byte_def temp_byte;
      unsigned char * pointer1;
      unsigned char* pointer2;
      unsigned char* SourceDP[4] = {0};      
	
	   
      temp_byte.bit.b0=Meter_States.Meter_Status2.bit.ActiveDirection_T;
      temp_byte.bit.b1=Meter_States.Meter_Status2.bit.ActiveDirection_A;
      temp_byte.bit.b2=Meter_States.Meter_Status2.bit.ActiveDirection_B;
      temp_byte.bit.b3=Meter_States.Meter_Status2.bit.ActiveDirection_C;
      rRecord->ActiveFlag=temp_byte.byte&0x0f;
      temp_byte.bit.b4=Meter_States.Meter_Status2.bit.ReactiveDirection_T;
      temp_byte.bit.b5=Meter_States.Meter_Status2.bit.ReactiveDirection_A;
      temp_byte.bit.b6=Meter_States.Meter_Status2.bit.ReactiveDirection_B;
      temp_byte.bit.b7=Meter_States.Meter_Status2.bit.ReactiveDirection_C;
      rRecord->ReactiveFlag=temp_byte.byte>>4;

      pointer1 = (unsigned char*)&Minute_Power_Data.Active_power_last_data[0];
      for(i=0;i<8;i++)
      {
            if(temp_byte.byte&(1<<i))
                  *((signed long*)pointer1) = 0 - (*((signed long*)pointer1));
            if(i==0)
                  pointer2 = rRecord->PAll;
            else if(i==4)
                   pointer2 = rRecord->RAll;
            else
                   pointer2 = rRecord->PA + (i-1)*3;
           data_change(pointer1,pointer2,0x01 ,0x13 ,0,0,-6,-4);
            pointer1+=4;
      }
      for(i=0; i<4; i++)
      {
            if(!i)
                   pointer2 = rRecord->SALL;
            else
                   pointer2 = rRecord->SA + (i-1)*3;
            FormatBCD(Visual_power[i]/100, pointer2, 3);
      }
      return 0;
}

 
 
int ComposeRecord3(struct RECORD3 *rRecord)
{
     
    int i;
	unsigned char* p;

	p = &rRecord->Factor[0];
	for(i=0; i<4; i++)
	{
		data_change((unsigned char *)&COMM_Factor[i],p,0x01 ,0x12 ,0,0,-6,-3);
		p += 2;
	}
	return 0;
}

 
 
int ComposeRecord4(struct RECORD4 *rRecord)
{
	rRecord->PP=This_Month_Data.Energy_Record.Plus_Active[0];
	rRecord->NP=This_Month_Data.Energy_Record.Nega_Active[0];	
	return 0;
}

 
 
int ComposeRecord5(struct RECORD5 *rRecord)
{
	rRecord->Quad1=This_Month_Data.Energy_Record.Quad_Reactive[0][0];
	rRecord->Quad2=This_Month_Data.Energy_Record.Quad_Reactive[1][0];
	rRecord->Quad3=This_Month_Data.Energy_Record.Quad_Reactive[2][0];
	rRecord->Quad4=This_Month_Data.Energy_Record.Quad_Reactive[3][0];
	return 0;
}

 
 
extern unsigned long  Last_Average_Value[8][9        ];   

int ComposeRecord6(struct RECORD6 *rRecord)
{
	unsigned long l_temp;
     
	data_change((unsigned char *)&Current_Demand[0],rRecord->DemandActive,0x01 ,0x13 ,0,0,-6,-4);	

     
	data_change((unsigned char *)&Current_Demand[1],rRecord->DemandReactive,0x01 ,0x13 ,0,0,-6,-4);	
	return 0;
}
 
 
 
 

 
 
 
int Get_Physicaladdress_From_Block(unsigned int block,unsigned long *addr)
{
    union FlashAddr32M FlashAddr;

    if(block>62976  )
        return 0;

     
    FlashAddr.addr=0x00014000  ;
    FlashAddr.SectorAddr.Saddr+=block/128  ;
     
    FlashAddr.SectorAddr.Sdummy=(block%128  )*32  ;

    *addr=FlashAddr.addr;    
    return 1;
}
 
 
 
 

 
 
 
int Get_Block_From_PhysicalAddress(unsigned int* block,unsigned long addr)
{
    union FlashAddr32M FlashAddr;
    unsigned int nnblock;

    FlashAddr.addr=addr;
    if((FlashAddr.addr<0x00014000  )||(FlashAddr.addr>0x001FFFFF  )||((FlashAddr.addr%32  )!=0))
        return -1;

    FlashAddr.addr-=0x00014000  ;
    nnblock=FlashAddr.SectorAddr.Saddr;
    nnblock*=128  ;
    nnblock+=FlashAddr.SectorAddr.Sdummy/32  ;

    if(nnblock>62976  )
        return -1;
    
    *block=nnblock;
    return 0;
}
 
 
 
int SaveLoadRecord(void)
{
	unsigned char nSaveFlag;  
	unsigned char *nRecord;
	unsigned char nLength;  
	unsigned int nPage; 
	unsigned int nByte; 
	signed int ret;
	unsigned char tmp;
	unsigned char nHour; 
	unsigned char nMinute; 
	struct DATA_TIME nDate;
    unsigned int oldblock,nblock,needsave; 
	unsigned int i;
	unsigned char nNeedSaveIndex; 
    union FlashAddr32M FlashAddre;

	
	 
	nDate.Year = MainSoftDate .Year;
	nDate.Month = MainSoftDate .Month;
	nDate.Day = MainSoftDate .Day;
	nDate.Hour = MainSoftDate .Hour;
	nDate.Min = MainSoftDate .Min;
       
     
    ret=CompareBytes((unsigned char *)&Meter_Parameter.parameter2.LoadRecoedBeginTime,(unsigned char *)&nDate, 5);
    if(ret==1)    
        return 0;

	 
	nSaveFlag = NeedToRecord(&nDate);
	if(nSaveFlag==0)
		return 0;
	
	ret=CompareBytes((unsigned char *)&LoadRecord.LastRecordTime,(unsigned char *)&nDate, 5);
	 
	if(ret >= 0)
	{    
		if(nDate.Min == 0)
		{
			LoadRecord.LoadRecordFlag.NeedSaveIndex = 1; 
		}
         
        Find_First_Record(&oldblock,0);
        ReadData_To_Cob(&oldblock,0);
        if(CompDateTime4ByteAnd5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&nDate)>0)
        {
           First_InitLoadRecord();
        }
	}
    
	oldblock = LoadRecord.BlockAddress;
	 
    
	 
	nRecord = (unsigned char *)&Co.b[2];
	Co.b[0]=0xAA;
	nLength=ComposeRecord(nRecord,nSaveFlag,&nDate);	
	nLength+=2;
	if(nLength%32  ==0)                       
		Co.b[1]=nLength/32  ;
	else
		Co.b[1]=nLength/32  +1;

     
    nblock=oldblock;    
    tmp=0;
    needsave=0xffff;
    for(i=0;i<Co.b[1];i++)
    {
        if(!Get_Physicaladdress_From_Block(nblock,(unsigned long *)&FlashAddre.addr))
            return -1;

        if(FlashAddre.SectorAddr.Sdummy==0)
        {      
            if(FlashAddre.addr>0x001FFFFF  ) 
            {
                nblock=0;
                FlashAddre.addr=0x00014000  ;
            }
            if((FlashAddre.addr==0x00014000  )&&(LoadRecord.LastBlockAddress!=0))
            {
                LoadRecord.LoadRecordFlag.reStart=1; 
                Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13         ,(unsigned char*)&LoadRecord.LoadRecordFlag,1    ,0,0);
            }
            Sector_Erase(FlashAddre.addr);
            needsave=nblock;
        }
        Write_Page(FlashAddre.addr,&Co.b[tmp],32  );
        tmp+=32  ;
        nblock++;
    }
  
    Change_SortAddr(nSaveFlag,oldblock);
		
	 
	if((nDate.Year != LoadRecord.LastRecordTime.Year)
        || (nDate.Month != LoadRecord.LastRecordTime.Month)
		|| (nDate.Day != LoadRecord.LastRecordTime.Day)
		|| (nDate.Hour != LoadRecord.LastRecordTime.Hour))
	{
		LoadRecord.LoadRecordFlag.NeedSaveIndex = 1;
	}

    LoadRecord.LastBlockAddress     = oldblock;
    if(nblock>=62976  )
    {
        nblock=0;
    }

    if ( (My_Memcmp(&nDate.Year, &LoadRecord.LastRecordTime.Year, 4) != 0) 
        || ((OB_H(nDate.Min)/5) != (OB_H(LoadRecord.LastRecordTime.Min)/5)))
    {
        Save_5Min_Index(&nDate);
    }

    LoadRecord.BlockAddress         = nblock;
    LoadRecord.LastRecordTime       = nDate;
    LoadRecord.LastRecordTime.Sec   = 0;


	 
	if(LoadRecord.LoadRecordFlag.NeedSaveIndex == 1)
	{
        LoadRecord.LoadRecordFlag.NeedSaveIndex = 0;
        SaveDayIndex(&nDate);






	}

  Save_SortIndex(nSaveFlag,needsave);
    
	LoadRecord.LoadRecordPointer++;
  i=(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L) ;
  if(LoadRecord.LoadRecordPointer%2==1)
    i=(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L  ;
	Write_Read_FM24C256 (i,(unsigned char*)&LoadRecord,26          ,0,0);
	
	return 0;
}


 
 
unsigned char ComposeRecord(unsigned char *rBuffer, unsigned char rSaveFlag, 
	struct DATA_TIME *rDate)
{
	unsigned char mask;
	unsigned char ind;
	unsigned char sum;
	unsigned char i;
	
	 
	DateTimeNoSec5ByteTo4Byte((struct DATE_TIMENOSEC_5BYTE *)rDate,(union DATE_TIMENOSEC_4BYTE *)&rBuffer[0]); 


	rBuffer[4] = rSaveFlag; 
								 
								 
								 
								 
								 
								 
								 
                                
	 
	 
		
	mask = 0x01;
	ind =5;
	while(mask < 0x40)
	{
		if((mask & rSaveFlag) != 0)
		{
			switch(mask)
			{
				case 0x01:
					ComposeRecord1((struct RECORD1*)&rBuffer[ind]);
					ind += sizeof(struct RECORD1);
					break;
				case 0x02:
					ComposeRecord2((struct RECORD2*)&rBuffer[ind]);
					ind += sizeof(struct RECORD2);
					break;
				case 0x04:
					ComposeRecord3((struct RECORD3*)&rBuffer[ind]);
					ind += sizeof(struct RECORD3);
					break;
				case 0x08:
					ComposeRecord4((struct RECORD4*)&rBuffer[ind]);
					ind += sizeof(struct RECORD4);                          
					mask <<= 1; 
				case 0x10:
					ComposeRecord5((struct RECORD5*)&rBuffer[ind]);
					ind += sizeof(struct RECORD5);                          
					break;
				default:
					ComposeRecord6((struct RECORD6*)&rBuffer[ind]);
					ind += sizeof(struct RECORD6);;
					break;
			}			
		}
		
		mask <<= 1;
	}

	 
	sum = 0;
	for(i=0; i<ind; i++)
	{
		sum += rBuffer[i];
	}
	rBuffer[ind] = sum;	
	
	return ind+1;
}


 
 
#pragma SECTION rom UserROMData
const unsigned char Clase_Length[6] = {6, 16, 8, 8, 42, 20};

unsigned char GetRecordLength(const unsigned char rMode)
{
	
	unsigned char nMask;
	unsigned char result=0;
	unsigned char i;
	
	result = 5;
	nMask=0x20;
	for(i=0; i<6; i++)
	{
		if((nMask & rMode) != 0)
		{
			result += Clase_Length[i];
		}
		nMask>>=1;
	}

    if((rMode&0x08)!=0&&(rMode&0x10)==0)
        result+=16;
	return result;
}


 
 
int InitSIO4(void)
{
	int result;
	unsigned char Status_Register;
    unsigned char ManufacturerID;
    unsigned char DeviceID;
	
	result = 0;
	
	prcr_addr.bit.b2			  = 1;
	s4c_addr.byte =0xE9;
	prcr_addr.bit.b2			  = 1;
	s4brg_addr.byte = 0x00;
	
	prcr_addr.bit.b2			  = 1;
	 
	pd0_addr.bit.b0				  = 1;

    Status_Register=Read_Status_Register();
    if(Status_Register&0x0c)
    Write_Status_Register(0x00);

    ReadID(&ManufacturerID,&DeviceID);
    
	return result;
}


 
 
 

int FindRecord(struct DATA_TIME *rDate, unsigned int *rPage,unsigned char sort)
{
    int ret;
    unsigned int min_blk;
    unsigned int nReadPage;
    struct DATA_TIME req_tm;
    unsigned char min;

    memcpy(&req_tm.Year, &rDate->Year, 6);
    min = OB_H(req_tm.Min);
    min = (min/5 ) * 5 ;
    nReadPage= 0xFFFF ;
    while (min < 60)
    {
        ret = get_5min_idx_by_time(&req_tm, &min_blk);
        if (ret == 0)
        {
            ret = find_record_in_cur_5min_frm_min_idx(sort, req_tm, 1, min_blk, &nReadPage);  
            if (ret == 0)
            {
                *rPage = nReadPage;
        	    return 0;
            }
        }

        min += 5 ;
        req_tm.Min = OH_B(min);
    }
    return -1;
}



















































































































unsigned int get_hour_in_year(struct DATA_TIME *rDate)
{
    unsigned int nHoursTotal;
	unsigned char tmp;
    
    nHoursTotal = 0;
    BCD2Byte(rDate->Month, &tmp);
    nHoursTotal += day_num[tmp-1] * 24;
    BCD2Byte(rDate->Day, &tmp);
    nHoursTotal += (tmp - 1) * 24;
    BCD2Byte(rDate->Hour, &tmp);
    nHoursTotal += tmp;                      

    return nHoursTotal;
}


int Save_5Min_Index(struct DATA_TIME *rDate)
{
    unsigned int nHoursTotal;
	 
	unsigned int nPage;
	unsigned int nByte;
    union FlashAddr32M FlashAddr, FlashAddrstart;
    
    unsigned char minute;
     
    unsigned int hour_sec;
    unsigned int hour_addr; 
    unsigned int min_addr;
    unsigned char part1;
    unsigned int nblock,mblock;

    nblock=LoadRecord.LastBlockAddress;
    
    nHoursTotal = get_hour_in_year(rDate);
    minute = OB_H(rDate->Min);
     
    
    hour_sec = nHoursTotal / 42   ;
    hour_addr = (nHoursTotal % 42   )*(12*2)  ;
    min_addr = hour_addr + (minute/5 )*2;
    
    FlashAddr.SectorAddr.Saddr = (0x300000UL/4096) + hour_sec;
    FlashAddr.SectorAddr.Sdummy = min_addr;

    if(FlashAddr.SectorAddr.Sdummy==0)
    {              
        Sector_Erase(FlashAddr.addr); 
    }
    else
    {
        Read_Data_Bytes(FlashAddr.addr,(unsigned char*)&mblock,2);
        if(mblock!=0xffff)
        {
            FlashAddrstart=FlashAddr;
            FlashAddrstart.SectorAddr.Sdummy=0;
            for(nByte=0;nByte<4;nByte++)
            {
                Read_Data_Bytes(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256);
                FlashAddrstart.addr+=256;
            }
            FeedWatchdog();
            CheckPowerDown();
            *((unsigned int*)&Co.b[FlashAddr.SectorAddr.Sdummy])=nblock;
            for(nByte=FlashAddr.SectorAddr.Sdummy+2;nByte<1024;nByte++)
                Co.b[nByte]=0xff;
            FlashAddrstart.SectorAddr.Sdummy=0;
            Sector_Erase(FlashAddr.addr); 
            for(nByte=0;nByte<4;nByte++)
            {
                if(Write_Page(FlashAddrstart.addr,(unsigned char*)&Co.b[FlashAddrstart.SectorAddr.Sdummy],256)==-1)
                    return -1;
                FlashAddrstart.addr+=256;
            }   
            return 0;
        }          
    }
    
    if(Write_Page(FlashAddr.addr,(unsigned char*)&nblock,2)==0)
        return 0;
    else
        return -1;
}

int get_5min_idx_by_time(struct DATA_TIME *rDate, unsigned int *blk)
{
    unsigned int nHoursTotal;
	 
	unsigned int nPage;
	unsigned int nByte;
    union FlashAddr32M FlashAddr, FlashAddrstart;
    
    unsigned char minute;
     
    unsigned int hour_sec;
    unsigned int hour_addr; 
    unsigned int min_addr;
    unsigned char part1;
    unsigned int nblock,mblock;

    nHoursTotal = get_hour_in_year(rDate);
    minute = OB_H(rDate->Min);
     
    
    hour_sec = nHoursTotal / 42   ;
    hour_addr = (nHoursTotal % 42   )*(12*2)  ;
    min_addr = hour_addr + (minute/5 )*2;
    
    FlashAddr.SectorAddr.Saddr = (0x300000UL/4096) + hour_sec;
    FlashAddr.SectorAddr.Sdummy = min_addr;

    Read_Data_Bytes(FlashAddr.addr,(unsigned char*)blk,2);
    if(*blk >= 62976  )
        return -1;
    else
        return 0;

}












































































 
 
 
int PrepareCommunication(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
												char mode,unsigned char uartx)
{
	unsigned char read_mode,Data_number,sum,read_class,read_addr;	
	unsigned int nReadPage; 
	unsigned int nReadByte; 
	unsigned int Sort_Len;
	int ret,i;
	struct DATA_TIME Read_Data;
	volatile struct RECORD *pRecord;
	volatile	struct RECORD1 *Record1;
	volatile	struct RECORD2 *Record2;
	volatile	struct RECORD3 *Record3;
	volatile	struct RECORD4 *Record4;
	volatile	struct RECORD5 *Record5;
	volatile	struct RECORD6 *Record6;
	unsigned char *pBuf,*temp_buf;
	union byte_def mode_word;
	signed long Power_temp;
	unsigned char mask;
	
	 
	
	if((LoadRecord.BlockAddress==0)&&(LoadRecord.LastBlockAddress==0))
	{
			return 0;
	}
	
	if (id.d[2] == 0x10)
	{
        return read_record_base_time_id(id, rCommand, rBuffer, mode, uartx);
	}
    
	 	
	read_mode=id.d[0];	 
								 
								 
								 
								 
								 
								 
	switch(id.d[2])
	{
		case 0:read_class=0x3f;break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:read_class= 1<<(id.d[2] -1);break;
		default: return 0;
	}
	if(mode==0)
	{				
		Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
		if(BCD2Byte(*(rCommand), &Read_Count[uartx])<0)
			return 0; 

        if(Read_Count[uartx]==0)
        {
            cx[3].readloadrecord=0;
            return 0;
        }

		switch(read_mode)
		{
			case 0x01:
				Read_Data.Sec = 0;
				Read_Data.Min=	*(rCommand+1);
				Read_Data.Hour=		*(rCommand+2);
				Read_Data.Day=		*(rCommand+3);
				Read_Data.Month=	*(rCommand+4);
				Read_Data.Year=		*(rCommand+5);
                if (CheckTime(&Read_Data.Year) == 0)
                {
                    cx[3].readloadrecord=0; 
                    return 0;
                }
				ret=Find_Data_Record_New(&nReadPage,&Read_Data,id.d[2],0);
				break;	
			case 0x03:
				ret=Find_Next_Record(uartx,&nReadPage,id.d[2]);
				break;	
			case 0x00:
				ret=Find_First_Record(&nReadPage,id.d[2]);
				break;	
			case 0x02:
				if(Read_Count[uartx]!=1)  { cx[3].readloadrecord=0; return 0;}
				ret=Find_Near_Record(&nReadPage,id.d[2]);			
				break;	
			case 0x04:
				ret=Find_Last_Record(uartx,&nReadPage);
				break;	
			case 0x05:
				ret=Find_Addr_Record(&nReadPage,&nReadByte,0);
				break;	
		}

		if(ret!=0) 
			return 0;
	}
	else
	{
		Data_number=*rCommand;
		if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1)==Data_number)
		{ 
			if(Read_Count[uartx]!=0)
				ret=Find_Next_Record(uartx,&nReadPage,id.d[2]);		
			else
				return 0x8000;
			if(ret!=0) return 0x8000;
		}
		else if(Iterate_Tree_Flag[uartx].Back_Flame_Serial==Data_number)
		{ 
			ret=Find_Last_Record(uartx,&nReadPage);
			if(ret!=0) return 0x8000;
				
		}
		else
		{
			return 0x8000;
		}
		
	}
	
	if(ReadData_To_Cob(&nReadPage,1)!=1)
	   return 0;	

	Sort_Len=Co.b[1]*32  ;
	if(Co.b[1]>4||Co.b[1]==0)
		return 0;
	if(id.d[2]!=0)
	{
		if((Co.b[6]&0x01<<id.d[2]-1)==0)
			return 0;
	}
    
  if(CompDateTime4ByteAnd5Byte((union DATE_TIMENOSEC_4BYTE*)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE*)&MainSoftDate )>0)
    return 0;
    
	LoadRecord.ReadHistory[uartx].Last_Read_BlockAddress=nReadPage;   
  Dat_Num=GetRecordLength(Co.b[6]);
	 	
	sum = 0;
	for(i=0; i<Dat_Num; i++)
	{
		sum += Co.b[i+2];
	}
	if(sum!=Co.b[Dat_Num+2]) 
	{
		pBuf=rBuffer;
		*(pBuf++)=0xE0;
		*(pBuf++)=0xE0;	
	}	
	else
	{
	
	
		pRecord=(struct RECORD *)&Co.b[2];
		
		pBuf=rBuffer;
		*(pBuf++)=0xA0;
		*(pBuf++)=0xA0;	
		pBuf++; 
		
		DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)pBuf);
		ConverseString(pBuf,5);
		pBuf+=5;
		
		read_addr=2+sizeof(struct RECORD);
		mask = 0x01;
		while(mask < 0x40)
		{
			if((mask&pRecord->Mode_Byte  ) != 0)
			{
				switch(mask)
				{
					case 0x01:
						Record1=(struct RECORD1 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD1);
						if((mask&read_class) != 0)
						{
							temp_buf=(unsigned char *)&Record1->VA[0];
							for(i=0;i<3;i++)
							{
								*pBuf = temp_buf[i*3]>>4;
								*pBuf |= (temp_buf[i*3+1]<<4);
								pBuf++;
								*pBuf = temp_buf[i*3+1]>>4;
								*pBuf |= (temp_buf[i*3+2]<<4);
								pBuf++;
							}
							temp_buf+=9;
							memcpy(pBuf, temp_buf, 11);
							pBuf += 11;
						}
						break;
					case 0x02:
						Record2=(struct RECORD2 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD2);
						if((mask&read_class) != 0)
						{					
							for(i=0;i<24;i++)
							{
								if(i==0)
									temp_buf=(unsigned char *)&Record2->PAll[0];
								else if(i==3)
									temp_buf=(unsigned char *)&Record2->PA[0];
								else if(i==12)
									temp_buf=(unsigned char *)&Record2->RAll[0];
								else if(i==15)
									temp_buf=(unsigned char *)&Record2->RA[0];
								*pBuf=*temp_buf;
								pBuf++;	
								temp_buf++;
							}
						}
						break;
					case 0x04:
						Record3=(struct RECORD3 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD3);
						if((mask&read_class) != 0)
						{
							memcpy(pBuf,(unsigned char *)&Record3->Factor[0], 8);
							pBuf += 8;
						}
						break;
					case 0x08:
						Record4=(struct RECORD4 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD4);
						Record5=(struct RECORD5 *)&Co.b[read_addr];
						if((mask&read_class) != 0)
						{
							FormatBCD(format_data(Record4->PP,0)/(10),pBuf,4);							
							pBuf+=4;
							FormatBCD(format_data(Record4->NP,0)/(10),pBuf,4);							
							pBuf+=4;
							for(i=0;i<2;i++)
							{
								if(!i)
									sum = Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte;
								else
									sum = Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte;
								math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
													sum,0x01 ,4,4, 0x8000   );
								FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

								if(Power_temp<0)
									*(pBuf+3)|=0x80;
								else
									*(pBuf+3)&=0x7f;

								pBuf+=4;
							}
						}
						break;
					case 0x10:
						Record5=(struct RECORD5 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD5);						
						if((mask&read_class) != 0)
						{
							for(i=0;i<4;i++)
							{
								FormatBCD(format_data(*((unsigned long *)Record5 +i),0)/(10),pBuf,4);							
								pBuf+=4;
							}
						}
						break;
					default:
						if((pRecord->Mode_Byte&0x08)!=0&&(pRecord->Mode_Byte&0x10)==0)
							read_addr+=16;
						Record6=(struct RECORD6 *)&Co.b[read_addr];
						read_addr+=sizeof(struct RECORD5);						
						if((mask&read_class) != 0)
						{
							memcpy(pBuf, (unsigned char *)&Record6->DemandActive[0], 6);
							pBuf += 6;
						}
						break;
				}			
			}
			 
			{			
				*pBuf=0xAA;
				pBuf++;
			}
			
			
			mask <<= 1;
		}
	}
	 
	*(rBuffer+2)=pBuf-rBuffer-3; 
	sum = 0;
	for(i=0; i<pBuf-rBuffer; i++)
	{
		sum += *(rBuffer+i);
	}
	*(pBuf++)=sum;
	*(pBuf++)=0xe5;

	if(mode!=0)
		{
			if(Iterate_Tree_Flag[uartx].Back_Flame_Serial!=Data_number)
			{	
				Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
				Read_Count[uartx]--;
			}
			 
		}
	else
		{
			Read_Count[uartx]--;
		}
	
	if(Read_Count[uartx]!=0)
	{
	  FeedWatchdog();
	  if(Find_Next_Record(uartx,&nReadPage,id.d[2])!=0)
	    Read_Count[uartx]=0;
  }

	if(Read_Count[uartx]!=0)
		return (pBuf-rBuffer)|0x8000;
	else
		return pBuf-rBuffer;
	
}
 
 
 
int InitLoadRecord(void)
{
	unsigned int i;
	unsigned char flag;
	struct LOADRECORD_NEW *pointer;
	
	CheckPowerDown();
	FeedWatchdog();
	
	flag=0;
	i=26          +13         +1    +64+26          ;
	
	if(ReadBlock((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L) ,&Co.b[300],i,0)!=0)
	{
		for(i=0;i<sizeof(struct LOADRECORD_NEW);i++)
		  *((unsigned char*)&LoadRecord+i)=0;
		for(i=0;i<(26          +13         +1    );i++)
		  *((unsigned char*)&LoadRecord+i)=Co.b[300+i];
		
		i=26          +13         +1    +64;
		pointer=(struct LOADRECORD_NEW *)(&Co.b[300+i]);
		
		if(((*pointer).LoadRecordPointer>LoadRecord.LoadRecordPointer)
		&&(!(((*pointer).BlockAddress >62976  )||(((*pointer).BlockAddress ==0)&&((*pointer).LastBlockAddress ==0)))))
		{
			for(i=0;i<26          ;i++)
		    *((unsigned char*)&LoadRecord+i)=*((unsigned char*)pointer+i);
		}
		
		if((LoadRecord.BlockAddress >62976  )||((LoadRecord.BlockAddress ==0)&&(LoadRecord.LastBlockAddress ==0))) 
		{
			flag=1;
		}
	}
	else
	{
		flag=1;
	}
	
	CheckPowerDown();
	FeedWatchdog();
	
	if(flag==1)
	{
		First_InitLoadRecord(); 
	}
	else
	{
	  LoadRecord.LoadRecordPointer=0;
	  Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L) ,(unsigned char*)&LoadRecord,26          ,0,0);
	  Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L  ,(unsigned char*)&LoadRecord,26          ,0,0);
	}
	
	for(i=0;i<sizeof(struct MINUTE_POWER_DATA);i++)
		*((unsigned char *)&Minute_Power_Data+i)=0;
 
	return flag;
}
 
 
 
int Get_Next_Record_Addr(unsigned int Page,unsigned int *rPage,unsigned char sort)
{
    unsigned int nnblock,startblock,endblock,checknum;
    union FlashAddr32M FlashAddr,FlashAddrstart,FlashAddrEnd;
    unsigned char uni,flag,sortemp,nSave;
    struct DATEANDTIME_DEF   recordtime;

    if((LoadRecord.LoadRecordFlag.reStart==0)&&(Page>=LoadRecord.LastBlockAddress))
        return -1;  

    recordtime = MainSoftDate ;
    flag       = 0;
    nnblock    = Page;    
    if(sort==0) 
    {
        if(0==LoadRecord.LoadRecordFlag.reStart) 
        {   
            if(ReadData_To_Cob(&nnblock,2)!=2)
                return -1;
        }
        else 
        {            
            checknum=LoadRecord.BlockAddress;
            if(checknum%128  ==0)
                endblock=LoadRecord.LastBlockAddress;
            else
                endblock=LoadRecord.BlockAddress;
            if(!Get_Physicaladdress_From_Block(endblock,(unsigned long*)&FlashAddrEnd.addr))
                return -1; 
            if(!Get_Physicaladdress_From_Block(nnblock,(unsigned long *)&FlashAddr.addr))
                return -1;   
            
            if(FlashAddr.SectorAddr.Saddr!=FlashAddrEnd.SectorAddr.Saddr)
            {  
                if(ReadData_To_Cob(&nnblock,2)!=2)
                        return -1;                   
            }
            else
            { 
                if(nnblock<LoadRecord.LastBlockAddress)
                {
                    if(ReadData_To_Cob(&nnblock,2)!=2)
                        return -1;          
                }
                else
                {
                    FlashAddr.SectorAddr.Saddr++;
                    if(FlashAddr.addr>=0x001FFFFF  )
                        FlashAddr.addr=0x00014000  ;
                    FlashAddr.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&startblock,FlashAddr.addr);
                    nnblock=startblock; 
                    for(uni=0;uni<4;uni++)
                    {
                       if(ReadData_To_Cob(&startblock,2)==2)                      
                       {
                           break;
                       }
                       startblock++;
                       nnblock=startblock;                   
                    }
                    if(uni==4)
                        return -1;
                }
            }
        }
     }
     else
     {
        checknum=LoadRecord.BlockAddress;
        if(checknum%128  ==0)
            endblock=LoadRecord.LastBlockAddress;
        else
            endblock=LoadRecord.BlockAddress;
        if(!Get_Physicaladdress_From_Block(endblock,(unsigned long *)&FlashAddrstart.addr))
             return -1;
        if(ReadData_To_Cob(&nnblock,2)!=2)
              return -1;    

        sortemp=0;
        endblock=nnblock;
        checknum=0;
        while(checknum<492  )
        {   
                if((0==LoadRecord.LoadRecordFlag.reStart)&&(endblock>LoadRecord.LastBlockAddress))
                    return -1;

                if(!Get_Physicaladdress_From_Block(endblock,(unsigned long *)&FlashAddrEnd.addr))
                            return -1;
                if(FlashAddrstart.SectorAddr.Saddr==FlashAddrEnd.SectorAddr.Saddr)
                { 
                    while(endblock<=LoadRecord.LastBlockAddress)
                    {
                        nnblock=endblock;
                        if(ReadData_To_Cob(&endblock,2)!=2)
                            return -1; 
                        sortemp=Co.b[6]&(0x01<<(sort-1));
                        if(sortemp!=0) 
                        {
                            *rPage=nnblock;
                            return 0;                     
                        }             
                    }
                    FlashAddrEnd=FlashAddrstart;
                    FlashAddrEnd.SectorAddr.Saddr++;
                    if(FlashAddrEnd.addr>=0x001FFFFF  )
                        FlashAddrEnd.addr=0x00014000  ;
                    FlashAddrEnd.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr); 
                }
                          
                nSave=0;
                startblock=endblock/128  ;
                Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14            +startblock*6+(sort-1),(unsigned char*)&nSave,1,0,1);

                if(nSave<128  )
                {
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr);  
                    nnblock=endblock;
                    if(ReadData_To_Cob(&endblock,2)!=2)
                        return -1; 
                    sortemp=Co.b[6]&(0x01<<(sort-1));
                    if(sortemp!=0) 
                    {
                      break;
                    }                    
                }
                else
                {
                    FlashAddrEnd.SectorAddr.Saddr++;
                    if(FlashAddrEnd.addr>=0x001FFFFF  )
                       FlashAddrEnd.addr=0x00014000  ;
                    FlashAddrEnd.SectorAddr.Sdummy=0;
                    Get_Block_From_PhysicalAddress(&endblock,FlashAddrEnd.addr);                    
                }             
                checknum++;
                FeedWatchdog();
         }
         if(checknum>=492  )
             return  -1;
     }   
     
     *rPage=nnblock;
     return 0;
}

 
 
 
int Find_Next_Record(int channel,unsigned int *rblock,unsigned char sort)
{
       	unsigned int nblock,nByte;

       	if(sort==0)
       	{
            	nblock=LoadRecord.LastBlockAddress;
       	}
       	else
       	{
            	nblock=LoadRecord.LastBlockAddress1[sort-1];
       	}
	
	if((LoadRecord.ReadHistory[channel].Last_Read_BlockAddress==nblock))
	{
		return -1;
	}	
	else
	{
		if(Get_Next_Record_Addr(LoadRecord.ReadHistory[channel].Last_Read_BlockAddress,rblock,sort)==-1)
		     return -1;	
	}
       
	return 0;
}
 
 
 
int Find_Last_Record(int channel,unsigned int *rPage)
{
	*rPage=LoadRecord.ReadHistory[channel].Last_Read_BlockAddress;
	return 0;
}
 
 
 
int Find_First_Record(unsigned int *rblock,unsigned char sort)
{
	unsigned int num;
	unsigned char ret;
    
	if(LoadRecord.LoadRecordFlag.reStart==0) 
	{
          if(sort==0)
          {
		      *rblock=0; 
          }
          else
          {        
              *rblock=LoadRecord.FirstBlockAddress1[sort-1];
          }
	}	
	else 
	{ 
	     if(Get_Next_Record_Addr(LoadRecord.LastBlockAddress,rblock,sort)==-1)
			     return -1;	
              
         
		 




















	}
	
	return 0;
}

 
 
 
int Find_Near_Record(unsigned int *rblock,unsigned char sort)
{
       if(sort==0)
       {
	        *rblock=LoadRecord.LastBlockAddress;
       }
       else
       {
            *rblock=LoadRecord.LastBlockAddress1[sort-1];
       }
	return 0;
}
 
 
 
 
int Find_Addr_Record(unsigned int *rPage, unsigned int *rByte,int addr)
{
	*rPage=56 +(addr/4);			
	*rByte=(addr%4)*131 ;
	return 0;	
}

























 
 
 
void First_InitLoadRecord(void)
{
    unsigned int unc;
    union FlashAddr32M Flashaddr;
    unsigned char saveflag[6];
    
	LoadRecord.LoadRecordFlag.reStart=0;
	LoadRecord.BlockAddress =0;
	LoadRecord.LastBlockAddress= 0;
	LoadRecord.LoadRecordPointer=0;
    
	LoadRecord.LastRecordTime.Year = 0x00;
	LoadRecord.LastRecordTime.Month = 0x01;
	LoadRecord.LastRecordTime.Day = 0x01;
	LoadRecord.LastRecordTime.Hour = 0x00;
	LoadRecord.LastRecordTime.Min = 0x00;
    
    LoadRecord.First_Flag.byte=0x3f;

	for(unc=0;unc<6;unc++)
	{
		LoadRecord.FirstBlockAddress1[unc]=0xFFFF ;
		LoadRecord.LastBlockAddress1[unc]=0;
	}
	
	
	Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L) ,(unsigned char*)&LoadRecord,26          +13         +1    ,0,0);
	
	Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L  ,(unsigned char*)&LoadRecord,26          ,0,0);
	
	for(unc=0;unc<6;unc++)
	{
    saveflag[unc]=0xff;
  }
	
  Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14            ,(unsigned char *)&saveflag[0],6,0,0);
  FeedWatchdog();
  
  Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L ,0,366,0,0);
	FeedWatchdog();	
    
}
 
 

 
 
void Minute_Power(char channel)
{
	int i;
	char c_temp;
	union byte_def temp_byte1;
	 
	unsigned long l_tmep;
	 

	for(i=0;i<4;i++)
	{
		c_temp=0x01;
		c_temp<<=i;
		 
		{
			
			Minute_Power_Data.Active_power_sum[i]+=Active_power[i];			
			Minute_Power_Data.Active_power_num[i]++;  
			
		}
		 
		{
			Minute_Power_Data.Reactive_power_sum[i]+=Reactive_power[i];
			Minute_Power_Data.Reactive_power_num[i]++;
		}
	}    

	if(channel!=0) 
	{
		for(i=0;i<4;i++)
		{
			l_tmep=Minute_Power_Data.Active_power_num[i];
			Minute_Power_Data.Active_power_last_data[i]=Minute_Power_Data.Active_power_sum[i]/l_tmep;
			l_tmep=Minute_Power_Data.Reactive_power_num[i];
			Minute_Power_Data.Reactive_power_last_data[i]=Minute_Power_Data.Reactive_power_sum[i]/l_tmep;
			Minute_Power_Data.Active_power_sum[i]=0;
			Minute_Power_Data.Reactive_power_sum[i]=0;
			Minute_Power_Data.Active_power_num[i]=0;  
			Minute_Power_Data.Reactive_power_num[i]=0;
		
		}
	}

	Active_power_Per_Mintue=ABS(Minute_Power_Data.Active_power_last_data[0]);
}



 
 
void Change_SortAddr(unsigned char rSaveFlag,unsigned int rblock)
{
       unsigned char unc,first,last,flag,pointer;

       flag=0;
       pointer=LoadRecord.First_Flag.byte;
       for(unc=0;unc<6;unc++)
       {
            first=LoadRecord.First_Flag.byte&(0x01<<unc);
            if((rSaveFlag&first)!=0)
            {
                 LoadRecord.FirstBlockAddress1[unc]=rblock;
                 pointer&=~(0x01<<unc);
                 flag=0xff;
            }
            last=rSaveFlag;
            if((last&(0x01<<unc))!=0)
            {
                LoadRecord.LastBlockAddress1[unc]=rblock;
            }
       }
       if(flag==0xff)
       {
            LoadRecord.First_Flag.byte=pointer;
            Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26          ,(unsigned char*)&LoadRecord.First_Flag.byte,13         ,0,0);
       }
}
 
 
 
 
void Save_SortIndex(unsigned char rSaveFlag,unsigned int rblock)
{
      unsigned char unc,flag=0,nSave[6];
      unsigned int temp,temp1;
      unsigned int nblock;
      char vd_check;

      vd_check=int2ic_addr.byte ;
      
      if(((LoadRecord.LastBlockAddress%128  )>(LoadRecord.BlockAddress%128  ))
        &&(LoadRecord.BlockAddress%128  !=0)) 
      {         
         nblock=LoadRecord.BlockAddress;
         temp=nblock/128  ;
         temp1=nblock%128  ;
         for(unc=0;unc<6;unc++)
            nSave[unc]=0xff; 
         flag=0xff;
      }
      else
      { 
         nblock=LoadRecord.LastBlockAddress;         
         temp=nblock/128  ;
         temp1=nblock%128  ;
         Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14            +temp*6,(unsigned char *)&nSave[0],6,0,1);
      }
      
       
      for(unc=0;unc<6;unc++)
      {
           if(((rSaveFlag&(0x01<<unc))!=0)&&(nSave[unc]==0xff))
           {
                nSave[unc]=temp1;
                flag=0xff;
           } 
      }
      
      if(flag==0xff)
      {
          Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14            +temp*6,(unsigned char *)&nSave[0],6,0,0);
      }
       
       

     int2ic_addr.byte =vd_check&0x1f;      
}

void DateTimeNoSec5ByteTo4Byte(struct DATE_TIMENOSEC_5BYTE *t5,union DATE_TIMENOSEC_4BYTE *t4)
{
	(*t4).bit.Year=OB_H((*t5).Year);
	(*t4).bit.Month=OB_H((*t5).Month);
	(*t4).bit.Day=OB_H((*t5).Day);
	(*t4).bit.Hour=OB_H((*t5).Hour);
	(*t4).bit.Minute=OB_H((*t5).Minute);
}

void DateTimeNoSec4ByteTo5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5)
{
	(*t5).Year=OH_B((*t4).bit.Year);
	(*t5).Month=OH_B((*t4).bit.Month);
	(*t5).Day=OH_B((*t4).bit.Day);
	(*t5).Hour=OH_B((*t4).bit.Hour);
	(*t5).Minute=OH_B((*t4).bit.Minute);
}

signed char CompDateTime4ByteAnd5Byte(union DATE_TIMENOSEC_4BYTE *t4,struct DATE_TIMENOSEC_5BYTE *t5)
{
	struct DATE_TIMENOSEC_5BYTE t;
	unsigned char result;
	
	DateTimeNoSec4ByteTo5Byte(t4,&t);
	
	result=CompareBytes((unsigned char *)&t,(unsigned char*)t5,5);
	
	return result;
}

void ConverseString(unsigned char *p,unsigned char n)
{
	unsigned char i;
	unsigned char j;
	
	for(i=0;i<n/2;i++)
	{
		j=p[i];
		p[i]=p[n-1-i];
		p[n-1-i]=j;
	}
	
}

int Find_Data_Record_New(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort,unsigned char kind)
{
	int ret;
	unsigned char findflag;
	unsigned int  i;
	
	if((ret=FindRecord(rDate,rPage,sort))==0)
	{	
		if(LoadRecord.LoadRecordFlag.reStart==0) 
		{
			if(*rPage>LoadRecord.LastBlockAddress)
			{
				return -1;		
			}				
		}		
	}
	
	if((Meter_Parameter.parameter1.LocalFunctionMode.bit.b3==0)&&(kind==0x00))
	{
		return ret;
	}
	
	findflag=0;
	
	if(ret!=0)
	{
		Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L ,&Co.b[300],366,0,1);
		FeedWatchdog();
		AddOneHour(rDate);
		for(i=0;i<366;i++)
		{
			if(ThisDayHaveRecord(rDate)==0)
			{
				findflag=1;
				break;
			}
			if(i<365)
			{
				AddOneDay(rDate);
			}
		}
		if(findflag==1)
		{
		  ret=FindRecord(rDate,rPage,sort);
		}
	}
	if(ret==0)
	{
		if(LoadRecord.LoadRecordFlag.reStart==0) 
		{
			if(*rPage>LoadRecord.LastBlockAddress)
			{
				return -1;		
			}				
		}	
	}
	
	return ret;	
}

int find_lst_record_frm_tm(unsigned int *rPage,struct DATA_TIME *rDate,unsigned char sort)
{
    struct DATA_TIME tm;
    unsigned int blk;
    unsigned int tmp_blk;
    unsigned char i;
    int ret;
    struct DATA_TIME  Date;
    unsigned char sz;

    *rPage = 0xFFFF ;
    memcpy(&tm.Year, &rDate->Year, 6);
    ret = Find_Data_Record_New(&blk, &tm, sort, 1);
    if (ret == 0)
    {
        tmp_blk = blk;
        for (i = 0; i < 8; i++)
        { 
            if (tmp_blk > 0)
            {
                tmp_blk--;
            }
            else
            {
                if(LoadRecord.LoadRecordFlag.reStart==0)
                { 
                    return -1;    
                }
                else
                {
                    tmp_blk = 62976  - 1;
                }
            }
            ret = ReadData_To_Cob(&tmp_blk, 3);
            if (ret == 0)
            {
                *rPage = tmp_blk;
                break;
            }
        }























    }
    else
    {
        Find_Near_Record(&blk, sort);
        ret = ReadData_To_Cob(&blk, 3);
        if (ret)
        {
            return -1;
        }
        DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
        if (My_Memcmp(&Date.Year, &rDate->Year, 5) == 2)
        { 
            *rPage = blk;
        }
    }

    if (*rPage == 0xFFFF )
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


void SaveDayIndex(struct DATA_TIME *rDate)
{
	unsigned char i;
	unsigned char savehoursflag;
	unsigned char nhours[3];
	unsigned char nyears;
	unsigned int  ndays;
  
	i=OB_H(rDate->Month);
	ndays=day_num[i-1]+OB_H(rDate->Day)-1;
	
	if(ndays<366)
	{
		FeedWatchdog();
		nyears=0;
		savehoursflag=0;
		Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L +ndays,&i,1,0,1);
		Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L + 366 +ndays*3,&nhours[0],3,0,1);
		if(i!=((rDate->Year)+1))
		{
			nyears=(rDate->Year)+1;
			nhours[0]=0;
			nhours[1]=0;
			nhours[2]=0;
		}
		i=OB_H(rDate->Hour);
		if(i<24)
		{
		  if((nhours[i/8]&BIT_UNC[i%8])==0)
		  {
		    nhours[i/8]=nhours[i/8]|BIT_UNC[i%8];
		    savehoursflag=1;
		  }
		}
		if(nyears!=0)
		{
			Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L +ndays,&nyears,1,0,0);
		}
		if(savehoursflag==1)
		{
			Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L + 366 +ndays*3,&nhours[0],3,0,0);
		}
	}
    
}


 
int ThisDayHaveRecord(struct DATA_TIME *rDate)
{
	unsigned char i;
	unsigned char nyears;
	unsigned int  ndays;
	unsigned char nhours[3];
	unsigned char starthour;
	unsigned char result;
  
  result=-1;
  
	i=OB_H(rDate->Month);
	ndays=day_num[i-1]+OB_H(rDate->Day)-1;
	starthour=OB_H(rDate->Hour);
	if(ndays<366)
	{
		FeedWatchdog();
		nyears=Co.b[300+ndays];
		if(nyears==((rDate->Year)+1))
		{
			Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(struct EVENT_REPORT_STATUS_TIMES) +64L)+26         +13        +1   +64L +26         +64L  +13*254L+64L + 366 +ndays*3,&nhours[0],3,0,1);
			if(starthour<24)
			{
				for(i=starthour;i<24;i++)
				{
					if((nhours[i/8]&BIT_UNC[i%8])!=0)
		      {
		        rDate->Hour=OH_B(i);
		        result=0;
		        break;
		      }
			 }
			}
		}
	}
	
	return result;
}


extern const unsigned char DaysOfMonth[12];
 
 
void time_add_minute(struct DATA_TIME *req_tm, unsigned int len)
{
    unsigned int timeCounter;
	unsigned char temp;
    unsigned char nMaxDay; 
    unsigned char min;
    unsigned char hour;
    unsigned char day;
    unsigned char month;
    unsigned char year;

     
     
     

    BCD2Byte(req_tm->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(req_tm->Min, &temp);
	timeCounter += temp;

    timeCounter += len;  
    hour = timeCounter/60;
    if (hour >= 24)
    {
         
        hour = hour % 24; 
        day = OB_H(req_tm->Day);
        day++;
        req_tm->Day = OH_B(day);
         
        nMaxDay = DaysOfMonth[OB_H(req_tm->Month)-1]; 
         if((req_tm->Year & 0x03) == 0  && req_tm->Month == 0x02) 
         {
          nMaxDay++;
         }
        if (req_tm->Day > OH_B(nMaxDay))
        {
            req_tm->Day = 0x01;
            month = OB_H(req_tm->Month);
            month++;
            req_tm->Month = OH_B(month);
             
            if(req_tm->Month > 0x12)
            {
                req_tm->Month = 0x01;
                year = OB_H(req_tm->Year);
                year++;
                req_tm->Year = OH_B(year);
                 
            }
        }
    }
    Byte2BCD(hour, &req_tm->Hour);
    min = timeCounter%60;
    Byte2BCD(min, &req_tm->Min);
}

 
unsigned int remain_skip_pnt; 
unsigned int sum_done_pnt;  
unsigned int next_record_block;  
unsigned int fst_not_rd_blk;  

 
 

 


unsigned char sort_base_type[9] = {0, 1, 1, 2, 2, 3, 4, 5, 6};
unsigned char last_frm_len;

static unsigned char sort;
static unsigned char per_len;
static unsigned int period;
unsigned char lst_pnt_data[16];


int check_id_error(unsigned char di0, unsigned char di1)
{
    int ret;

    ret = -1;
    switch(di1)
    {
    case 1:
        if((di0 > 0 && di0 < 4) || di0 == 0xFF)
            ret = 0;
        break;
    case 2:
        if((di0 > 0 && di0 < 4) || di0 == 0xFF)
            ret = 0;
        break;   
    case 3:
        if(( di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 4:
        if((di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 

    case 5:
        if((di0 < 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 6:
        if((di0 >= 1 && di0 <= 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 7:
        if((di0 >= 1 && di0 <= 4) || di0 == 0xFF)
            ret = 0;
        break; 
    case 8:
        if((di0 >= 1 && di0 <= 2) || di0 == 0xFF)
            ret = 0;
        break; 

    default:
        break;
    }  
    return ret;
}

unsigned char find_sort_off(unsigned char sort, unsigned char rMode)
{
	unsigned char nMask;
	unsigned char off;
	unsigned char i;
	
	off = 2+sizeof(struct RECORD);
	for(i=1; i<sort; i++)
	{
        nMask = (0x01 << (i - 1));
		if((nMask & rMode) != 0)
		{
			off += Clase_Length[6 - i];
		}
	}

    if(sort == 6 && (rMode&0x08)!=0 && (rMode&0x10)==0) 
        off+=16;
	return off;
}





































































 
unsigned char get_single_id_data_len(unsigned char di0, unsigned char di1)
{
    unsigned char len;
    
    switch(di1)
    {
    case 1:
        len = (di0 == 0xff)? 6: 2;
        break;
    case 2:
        len = (di0 == 0xff)? 9: 3;
        break;   
    case 3:
        len = (di0 == 0xff)? 12: 3;
        break; 
    case 4:
        len = (di0 == 0xff)? 12: 3;
        break;

    case 5:
        len = (di0 == 0xff)? 8: 2;
        break; 
    case 6:
        len = (di0 == 0xff)? 16: 4;
        break; 
    case 7:
        len = (di0 == 0xff)? 16: 4;
        break; 
    case 8:
        len = (di0 == 0xff)? 6: 3;
        break; 

    default:
        len = 0;
    }
    return len;
}

void get_data_from_cob_base_id(unsigned char di0, unsigned char di1, unsigned char *pBuf)
{
    unsigned char read_mode,Data_number,sum,read_class,read_addr;
    unsigned char *temp_buf;
    unsigned char i;
    unsigned char sort;
    volatile struct RECORD *pRecord;
	volatile	struct RECORD1 *Record1;
	volatile	struct RECORD2 *Record2;
	volatile	struct RECORD3 *Record3;
	volatile	struct RECORD4 *Record4;
	volatile	struct RECORD5 *Record5;
	volatile	struct RECORD6 *Record6;
    signed long Power_temp;
    unsigned char *src;

    src = pBuf;
    sort = sort_base_type[di1];

    pRecord = (struct RECORD *)&Co.b[2];
    read_addr = find_sort_off(sort, pRecord->Mode_Byte);
    switch(di1)
    {
    case 1:
        Record1=(struct RECORD1 *)&Co.b[read_addr];
        temp_buf=(unsigned char *)&Record1->VA[0];
        
        if (di0== 0XFF)
        {
    		for(i=0;i<3;i++) 
    		{
    			*pBuf = temp_buf[i*3]>>4;
    			*pBuf |= (temp_buf[i*3+1]<<4);
    			pBuf++;
    			*pBuf = temp_buf[i*3+1]>>4;
    			*pBuf |= (temp_buf[i*3+2]<<4);
    			pBuf++;
    		}
        }
        else
        {
            i = di0 - 1;
			*pBuf = temp_buf[i*3]>>4;
			*pBuf |= (temp_buf[i*3+1]<<4);
			pBuf++;
			*pBuf = temp_buf[i*3+1]>>4;
			*pBuf |= (temp_buf[i*3+2]<<4);
			pBuf++;
        }
        break;
    case 2:
        Record1=(struct RECORD1 *)&Co.b[read_addr];
        temp_buf=(unsigned char *)&Record1->IA[0];
        if (di0== 0XFF)
        {
    		memcpy(pBuf, temp_buf, 9); 
            pBuf += 9;
        }
        else
        {
            i = di0 - 1;
            memcpy(pBuf, temp_buf + i*3, 3);
            pBuf += 3;
        }
        break;   
    case 3: 
        Record2=(struct RECORD2 *)&Co.b[read_addr];		
        if (di0== 0XFF)
        {
            memcpy(pBuf, &Record2->PAll[0], 3); 
            memcpy(pBuf + 3, &Record2->PA[0], 3*3); 
        }
        else
        {
            if (di0 == 0x00)
            {
                memcpy(pBuf, &Record2->PAll[0], 3);
            }
            else
            {
                temp_buf = &Record2->PA[0];
                memcpy(pBuf, temp_buf + (di0 - 1)*3, 3);
            }
        }
        break; 
    case 4: 
        Record2=(struct RECORD2 *)&Co.b[read_addr];		
        if (di0== 0XFF)
        {
            memcpy(pBuf, &Record2->RAll[0], 3); 
            memcpy(pBuf + 3, &Record2->RA[0], 3*3); 
        }
        else
        {
            if (di0 == 0x00)
            {
                memcpy(pBuf, &Record2->RAll[0], 3);
            }
            else
            {
                temp_buf = &Record2->RA[0];
                memcpy(pBuf, temp_buf + (di0 - 1)*3, 3);
            }
        }
        break;

    case 5: 
        Record3=(struct RECORD3 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
            memcpy(pBuf,(unsigned char *)&Record3->Factor[0], 8);
        }
        else
        {
            temp_buf = &Record3->Factor[0];
            memcpy(pBuf, temp_buf + di0*2 , 2);
        }
        break; 
    case 6: 
        Record4=(struct RECORD4 *)&Co.b[read_addr];
		read_addr+=sizeof(struct RECORD4);
		Record5=(struct RECORD5 *)&Co.b[read_addr];
        if (di0 == 0XFF || di0 == 0x01)
        {
    		FormatBCD(format_data(Record4->PP,0)/(10),pBuf,4);	 						
    		pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x02)
        {
    		FormatBCD(format_data(Record4->NP,0)/(10),pBuf,4);	 						
    		pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x03)
        {
            sum = Meter_Parameter.parameter1.REActivem_Erengy_1_Mode.byte; 
            math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
								sum,0x01 ,4,4, 0x8000   );
			FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

			if(Power_temp<0)
				*(pBuf+3)|=0x80;
			else
				*(pBuf+3)&=0x7f;

			pBuf+=4;
        }
        if (di0 == 0XFF || di0 == 0x04)
        {
            sum = Meter_Parameter.parameter1.REActivem_Erengy_2_Mode.byte; 
            math_Add((unsigned char *)&Record5->Quad1,(unsigned char *)&Power_temp,
								sum,0x01 ,4,4, 0x8000   );
			FormatBCD(ABS((Power_temp)/(10)),pBuf,4);

			if(Power_temp<0)
				*(pBuf+3)|=0x80;
			else
				*(pBuf+3)&=0x7f;

			pBuf+=4;
        }
        break; 
    case 7: 
        Record5=(struct RECORD5 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
    		for(i=0;i<4;i++)
    		{
    			FormatBCD(format_data(*((unsigned long *)Record5 +i),0)/(10),pBuf,4);							
    			pBuf+=4;
    		}
        }
        else
        {
            FormatBCD(format_data(*((unsigned long *)Record5 +(di0 - 1)),0)/(10),pBuf,4);							
        }
        break; 
    case 8: 
		Record6=(struct RECORD6 *)&Co.b[read_addr];
        if (di0== 0XFF)
        {
            memcpy(pBuf, (unsigned char *)&Record6->DemandActive[0], 6);
        }
        else
        {
            memcpy(pBuf, &Record6->DemandActive[0] + (di0 - 1)*3, 3);
        }
        break; 

    default:
        break; 
    }
    if (di1 == 6 || di1 == 7)
    {
        memcpy(lst_pnt_data, src, per_len);
    }

}


void memset(unsigned char *dst, unsigned char data, unsigned char len)
{
    unsigned char i;

    for(i=0; i<len; i++)
    {
        dst[i] = data;
    }
    return;
}

void patch_no_data_pnt(unsigned char di0, unsigned char di1, unsigned char *pBuf, struct DATA_TIME *rDate)
{
    unsigned int blk;
    int ret;
    
    if (di1 == 6 || di1 == 7)
    {
        if (sum_done_pnt == 0)
        {
            ret = find_lst_record_frm_tm(&blk, rDate, sort);
            if (ret == 0)
            {
                ret = ReadData_To_Cob(&blk,1);
                get_data_from_cob_base_id(di0, di1, pBuf);
            }
            else
            {
                memcpy(pBuf, lst_pnt_data, per_len);
            }
        }
        else
        {
            memcpy(pBuf, lst_pnt_data, per_len);
        }
    }
    else
    {
        memset(pBuf, 0xFF, per_len);
    }
}




struct DATA_TIME lst_record_tm;
unsigned long l_lst_record;
unsigned char cur_hour_empty;
unsigned long rd_ld_time;




















































































































 

void AddOneHour(struct DATA_TIME *rDate)
{
	unsigned char data[4];
  unsigned char i;
   
  for(i=0;i<4;i++)
    data[i]=OB_H(*((unsigned char *)rDate+i));
  
  if(data[3]<23)
  {
     data[3]++;
  }
  else
  {
     data[3]=0;
     if( data[2]<CalDay(data[0],data[1]) )
     {
      	data[2]++;
     }
     else                        
     {
      	data[2]=1;
      	if(data[1]<12)               
      	{
      	   data[1]++;
      	}
      	else
      	{
      	   data[1]=1; 
      	   data[0]=(data[0]+1)%100;
      	}
     }
  }
              
  for(i=0;i<4;i++)
   *((unsigned char *)rDate+i)=OH_B(data[i]);
  rDate->Min=0;
  rDate->Sec=0;
}

void AddOneDay(struct DATA_TIME *rDate)
{
	unsigned char data[3];
  unsigned char i;
   
  for(i=0;i<3;i++)
    data[i]=OB_H(*((unsigned char *)rDate+i));

  if( data[2]<CalDay(data[0],data[1]) )
  {
     data[2]++;
  }
  else                        
  {
     data[2]=1;
     if(data[1]<12)               
     {
      	data[1]++;
     }
     else
     {
      	data[1]=1; 
      	data[0]=(data[0]+1)%100;
     }
  }

            
  for(i=0;i<3;i++)
   *((unsigned char *)rDate+i)=OH_B(data[i]);
  rDate->Hour=0;
  rDate->Min=0;
  rDate->Sec=0;
}



 
 
 
int find_record_in_cur_5min_frm_min_idx(unsigned char st, struct DATA_TIME req_tm, unsigned char cmp,unsigned int min_blk, unsigned int *read_blk)
{
    unsigned int  nblock,getblock, tmp_blk;
    unsigned char tmp;
    struct DATA_TIME  Date;
    unsigned char i;
    unsigned char res;
    int ret;
    unsigned char j;

    getblock = min_blk;
    nblock = min_blk;
    tmp = 0xff;

    for(i = 0; i < 5 ; i++)
    {
           FeedWatchdog();
           getblock = nblock;
           ret = ReadData_To_Cob(&nblock,2); 
























           if (ret != 2)
           {
			    return -1;
           }

           if(st != 0)
              tmp = Co.b[6]&(0x01<<(st - 1));

		    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&Date);
		    Date.Sec=0;

            if (My_Memcmp(&Date.Year, &req_tm.Year, 4) != 0) 
            {
                return -2;
            }

            res = My_Memcmp(&Date.Year, &req_tm.Year, 5);
            if( tmp != 0)
            {
                if ((res == 0) || ((res == 1) && (cmp == 1)))
                {
                    *read_blk = getblock;
                    return 0;   
                }
            }


             
           if((getblock>=LoadRecord.LastBlockAddress)&&(0==LoadRecord.LoadRecordFlag.reStart))
           {      
                return -1;
            }
    }
    
    return -1;
}

int read_n_pnt_record_from_time(struct DATA_TIME req_tm, unsigned char req_pnt, unsigned char need_tm, 
    union ID id,unsigned char *rCommand, unsigned char *rBuffer, char mode)
{
    unsigned int nReadPage, nblk; 
    unsigned int timeCounter;
    int ret;    
    unsigned char *pBuf;        
    unsigned char pnt;
    struct DATA_TIME this_tm;
    unsigned long l_this;
    unsigned long l_req;
    unsigned char cur_off, lst_off;
    unsigned int min_blk; 
    
    if (need_tm)
    {
        My_memcpyRev(rBuffer, (unsigned char *)&req_tm, 5);
        pBuf = rBuffer + 5; 
    }
    else
    {
        pBuf = rBuffer;
    }

    lst_off = 0xff;  
    for (pnt = 0; pnt < req_pnt; pnt++)
    {
        ret = CompareBytes((unsigned char *)&MainSoftDate,(unsigned char *)&req_tm, 5);
        if(ret == -1) 

        { 
            sum_done_pnt = user_req_pnt;
            break;
        }
        cur_off = OB_H(req_tm.Min)/5 ;
        if ((cur_off != lst_off) || (req_tm.Hour != lst_record_tm.Hour))
        {
            ret = get_5min_idx_by_time(&req_tm, &min_blk);
            if (ret < 0)
            {
                 
                min_blk = 0xFFFF ;
            }
            else
            {
                next_record_block = min_blk;
            }

            lst_off = cur_off;
        }
        
         
        if (min_blk != 0xFFFF )
        {
            ret = find_record_in_cur_5min_frm_min_idx(sort, req_tm, 0, next_record_block, &nReadPage);
            if (ret < 0)
            {
                patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
                 
            }
            else
            {
                ret = ReadData_To_Cob(&nReadPage,1);
                get_data_from_cob_base_id(id.d[0], id.d[1], pBuf);
                next_record_block = nReadPage  + Co.b[1];
                if(next_record_block >= 62976  )
                {
                    next_record_block = next_record_block % 62976  ;
                }
            }
        }
        else
        {    
            patch_no_data_pnt(id.d[0], id.d[1], pBuf, &req_tm);
        }
        
        memcpy(&lst_record_tm.Year, &req_tm.Year, 5);
         
        time_add_minute(&req_tm, period); 
        pBuf += per_len;
        sum_done_pnt++;
        if (!GetTimeCount(rd_ld_time, 500 ))
        {
            break;
        }
    }   
    if (pnt == 0)
    { 
        return 0;
    }
    else
    {
        return pBuf-rBuffer;
    }
}





























































































void time_align(struct DATA_TIME *tm)
{
    unsigned int timeCounter;
	unsigned char temp;
    unsigned int mod;
    
    BCD2Byte(tm->Hour, &temp);
	timeCounter = temp * 60;
	BCD2Byte(tm->Min, &temp);
	timeCounter += temp;

     
    mod = timeCounter % period;
    if(mod != 0)
    { 
        time_add_minute(tm, (period - mod));
    }

}

int check_time_pass_fst_record(struct DATA_TIME *req_tm)
{

    unsigned int blk;
    struct DATA_TIME this_tm;
    int ret;
    unsigned char reStart;
    struct DATA_TIME tm;
    
    unsigned long this_l;
    unsigned long req_l;
    unsigned char pnt;
    
    ret = Find_First_Record(&blk, 0);
    if(ret < 0)
    {
        return ret;
    }

    ret = ReadData_To_Cob(&blk, 3);
    if(ret < 0)
    {
        return ret;
    }
    this_tm.Sec = 0;
    DateTimeNoSec4ByteTo5Byte((union DATE_TIMENOSEC_4BYTE *)&Co.b[2],(struct DATE_TIMENOSEC_5BYTE *)&this_tm);
    time_align(req_tm);
    if (CompareBytes((unsigned char *)req_tm, (unsigned char *)&this_tm, 5) < 0)
    { 
        time_align(&this_tm);
        TimeToLong(this_tm, &this_l);

        memcpy(&tm.Year, &req_tm->Year,  6);
        TimeToLong(tm, &req_l);
        pnt = (this_l - req_l)/60UL/period;
        if (pnt >= user_req_pnt)
        {
            user_req_pnt = 0;
        }
        else
        {
            user_req_pnt -= pnt;
        }
        memcpy(&req_tm->Year, &this_tm.Year, 5);
    }
    
    
    return 0;
}




 
 
 
int read_record_base_time_id(union ID id,unsigned char *rCommand, unsigned char *rBuffer,
								char mode,unsigned char uartx)
{
    struct DATA_TIME req_tm;
    unsigned int timeCounter;
	unsigned char temp;
    unsigned char type;
    unsigned int mod;
    int ret;
    unsigned char max_pnt;
    unsigned char req_num;
    unsigned char seq;

    rd_ld_time = GetNowTime();
    type = id.d[1];
    sort = sort_base_type[type];
    if (LoadRecord.FirstBlockAddress1[sort - 1] == 0xFFFF )
    {
        return 0;
    }

    per_len = get_single_id_data_len(id.d[0], id.d[1]);
    if (mode == 0)
        max_pnt = (196    - 5) / per_len;
    else
        max_pnt = (196    - 1) / per_len;
    if (max_pnt > user_req_pnt)
    {
        max_pnt = user_req_pnt;
    }
     

    period = Meter_Parameter.parameter2.LoadRecordPeriod[sort - 1];
    
    if (mode == 0)
    {
        Iterate_Tree_Flag[uartx].Back_Flame_Serial=0;
        lst_record_tm.Sec = 0;
        req_tm.Sec = 0;
        req_tm.Min =	*(rCommand+1);
    	req_tm.Hour = *(rCommand+2);
    	req_tm.Day = *(rCommand+3);
    	req_tm.Month = *(rCommand+4);
    	req_tm.Year = *(rCommand+5);
        if (CheckTime(&req_tm.Year) == 0)
        {
            cx[3].readloadrecord=0; 
            return 0;
        }
        ret = check_time_pass_fst_record(&req_tm);
        if(ret < 0)
            return 0;
        if (user_req_pnt == 0)
        {
            return 0;
        }
        if (id.d[1] == 6 || id.d[1] == 7)
        {
            memset(lst_pnt_data, 0xFF, per_len);
        }





















        sum_done_pnt = 0;
        next_record_block = 0xFFFF ;
        fst_not_rd_blk = 0xFFFF ;
        req_num = (max_pnt > user_req_pnt)?user_req_pnt:max_pnt;
        ret = read_n_pnt_record_from_time(req_tm, req_num, 1, id, rCommand, rBuffer, mode);
        last_frm_len = ret&0xff;
        memcpy(&Card_WR_Buff[256], rBuffer, last_frm_len);
    }
    else
    {
        seq = *rCommand;
        if((Iterate_Tree_Flag[uartx].Back_Flame_Serial+1) == seq)
		{ 
            if(sum_done_pnt + max_pnt <= user_req_pnt)
            {
                req_num = max_pnt;
            }
            else
            {
                req_num = user_req_pnt - sum_done_pnt;
            }
            req_tm.Sec = 0;
            memcpy(&req_tm.Year, &lst_record_tm.Year, 5);
            time_add_minute(&req_tm, period); 
            ret = read_n_pnt_record_from_time(req_tm, req_num, 0, id, rCommand, rBuffer, mode); 
            last_frm_len = ret&0xff;
            memcpy(&Card_WR_Buff[256], rBuffer, last_frm_len);
		}
		else if(Iterate_Tree_Flag[uartx].Back_Flame_Serial == seq)
		{ 
			memcpy(rBuffer, &Card_WR_Buff[256],last_frm_len);
            ret = last_frm_len;
		}
		else
		{
			return 0x8000; 
		}

        if(Iterate_Tree_Flag[uartx].Back_Flame_Serial != seq)
		{	
			Iterate_Tree_Flag[uartx].Back_Flame_Serial++;
		}
                    
    }
    if (sum_done_pnt < user_req_pnt)
    {
        ret |= 0x8000;
    }
    return ret;
}





 
