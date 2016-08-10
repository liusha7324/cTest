#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"
 
 
 
 
 

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"
  









#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defmcro.h"
  








#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 



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



 
#line 10 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defmcro.h"

 
 


 



 	 






 


 




















































































 

 


 

 
 



    

 






			








		








	
	
	








	
	
	








	
	
	








	
	
	








	
	
	

















	                        
	
 





















































 

   












 
 

















































































 
 
 
 






 

















































 
                            
                            
                        
#line 11 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/eventdatadef.h"



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
 
 

 
#line 12 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/eventnew.h"
  





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

 

 
#line 13 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_Base_fun.h"



 
 

 
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
 




 






















 




 














































 




























    
#line 14 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"


 
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


 
 
#line 7 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Interrupt.h"



extern volatile unsigned long TimeCount5ms;
extern volatile unsigned char FirstInterPowerDown;
extern unsigned char pdmode1,pdmode2;
extern unsigned char pdmode3; 
extern volatile  unsigned int PowerdownDisplayCyleAdd;
extern volatile unsigned int  PowerdownDisplayOverAdd;   
extern volatile unsigned int  PowerdownStopCommAdd;      
extern volatile unsigned char IntoPowerDownFlag;
extern volatile unsigned char Valid_IntoPowerdown_Flag[8]; 
 
 
extern unsigned char keykick;    

 
extern void PowerDownDisplayInit(void);
extern void ClearDatePoerDown(void);                
extern void TimerA2_Int_Interrupt(void);
extern volatile union BYTE_BIT TimeChontrolBeginFlag;   
extern void Ad_Converter_Int(void); 
extern volatile unsigned  char pdmodekeyflag; 
extern volatile unsigned  char PowerdownStopKeyAdd; 
extern volatile unsigned int Powerdown_TempTimeAdd;
extern volatile unsigned char pdopencoverintflag[2];
extern volatile unsigned char farwakeupreadyflag;
extern volatile unsigned char farwakeupreadycnt; 

#line 8 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/eeprom.h"
   








 
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 
 

 















































 

 

 


 


 
 
 

 







 

          







 




 






























 






 





















 
 
 
 
 
 
 











 
 
 
 
 
 
 











 
 
 
 
 
 
 












 
 
 
 
 



















 




 



 





























 



























 

 






















                     
















               
 


















































 













 
 
 
 
 







 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 






 


































 























                                                                                                               








 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 
 


 





























































                                                                                                            
 

 




 
 
















































 
















 



  
#line 9 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/I2C_operation.h"


					 				
 
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

#line 10 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/comm.h"


  


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


 
#line 11 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/ram.h"
  








#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 10 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/ram.h"



 
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



  
#line 12 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_Showmain.h"
 
 
 
 
 








 



















 
 
extern  char Show_Main(unsigned long show_code,char *show_buffer,unsigned long user_code,unsigned char user_code_len);
extern int Show_Initialize(char flag);
extern char Show_Char_Main(char show_char,char On_Off);
extern void clear_show_lcd(void);
extern void tr_show_wait(int time);
extern void cursor_flash(int cursor);
extern char show_on_lcd(char* show_ram,int start_add,int len);
extern char conver_data(char* show_data,char* show_ram,int start_add,int len);
extern char reconver_char(char show_val,char addr);
extern char lcd_special_cortrol(char cortrol_code);
extern void Lcd_Power_On(void);
extern void Lcd_Power_Off(void);
extern char show_on_lcd_only_send_data(char* show_ram,int start_add,int len);
extern int bcd_un_zip(char* input,char* output,int len); 
extern char conver_data0(char* show_data,char* show_ram,int start_add,int len);
 
 

































 
 
extern char vram[1 +3][10 ];
extern const unsigned char FILE_DATE[3];

 

struct Show_falg_bit_def {
	char I:1;                        
	char XY:1;			 
	char IV:1;			 
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

	char II:1;			 
	char III:1;                    
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;
	char Base:1;		 

	char Carrier_Wave:1;	     		
	char BT:1;                        
	char RS1:1;                      
	char RS2:1;                      
	char :1;
	char :1;
	char :1;
	char :1;

	char Signal4:1;	 
	char Signal3:1;	 
	char Signal2:1;	 
	char Signal1:1;	 
	char :1;
	char :1;
	char :1;
	char :1;

	char Break_switch:1;	       		
	char Overdraft:1;                   
	char Stock_up:1;			  
	char BATTERIES2:1;		 
	char :1;
	char :1;
	char :1;
	char :1;
	
	char Fail:1;   		 
	char Recharge:1;	 
	char _Ic:1;		  
	char Ib:1; 		 
	char :1;
	char :1;
	char :1;
	char :1; 

   	char One:1;		 
	char Two :1;		 
 	char Ic:1;		 
	char BATTERIES1:1; 		 
	char :1;
	char :1;
	char :1;
	char :1;

    	char Read_card:1;		 
	char :1;		
	char _Ia:1; 		 
	char :1;
	char :1;
	char :1;
	char :1;
	char :1;

    	char Success:1;	 
	char Ing:1;		 
	char Ia:1;		 
	char _Ib:1;		 
	char :1;
	char :1;
	char :1;
	char :1;

	char Bell:1;                          
	char Home:1;		               
	char lock:1;                         
	char keystoke:1;                 
	char :1;
	char :1;				
	char :1;			
	char :1;				

	char Ua:1;		 
	char Ub:1;		 	
	char Uc:1;		 
	char Athwart:1;	             			
	char :1;			
	char :1;			
	char :1;			
	char :1;	

	char :1;			
	char :1;	
  	char A_S:1;		
	char B_S:1;		
	char C_S:1;		
	char North:1;
	char key:1;
	char flash_flag:1;

 
 
 
 
 
 
 
};

union Show_falg_word_def{
	struct 	Show_falg_bit_def bit;
	char	byte[13];
};

struct Show_Err_Flag_def
{
    char CLK_BATTER_LOW:1;
    char ENERGY_DIRECT_CHANGE:1;
    char CLK_BATTER_TIME_LIMIT:1;
    char PROG_ERR:1;
    char CLK_ERR:1;
    char MEM_ERR:1;
    char UNDEF1:1;
    char UNDEF2:1;
};

union Show_Err_Code
{
    struct Show_Err_Flag_def bit;
    char byte;
};

extern unsigned char show_mode1; 
extern unsigned char show_leaf_flag;
 
extern unsigned char fshow_flag;
extern  char ret_flag;                                     
extern  char leaf_flag;                           
extern union Show_falg_word_def Show_flag;			 
extern union Show_falg_word_def Show_flash_falg; 	  
extern union Show_Err_Code Err_Code;
extern unsigned char set_cycle_num;;

 
extern unsigned long dispCardDataTime;
extern unsigned long dispCardDataTimeLen;
extern unsigned int meterDispErr_ID;         		  
extern union BYTE_BIT dispPaymentFlag;
extern union BYTE_BIT dispCharFlag[];

























extern void displayReadCard(unsigned char mode);
extern void displayCharTimeLen(unsigned char mode,unsigned char timeLen,unsigned char flag);
extern void displayCharOnOff(unsigned char mode,unsigned char onOff,unsigned char flash);
extern void dispPaymentChar(void);
extern void Disp_Char_Clear(void);

#line 13 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Measure_Interface.h"




#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 5 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Measure_Interface.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/RN8302B_Meter.h"
 
 
 
 
 
 
 
 


 
 
 
 
  



 
 
 
typedef unsigned char BOOL;            
typedef unsigned char UINT8;           
typedef signed char SINT8;              
typedef unsigned int UINT16;          
typedef signed int SINT16;              
typedef unsigned long UINT32;        
typedef signed long SINT32;            
typedef unsigned long long UINT64;    
typedef signed long long SINT64;        
typedef float FP32;        
typedef double FP64;     










 
 
 






 



 
 
 
 




 

 


 
 
 
typedef struct _stMeter_Data_Buffer
{
    UINT32 dwVolt[3];   
    UINT32 dwCurr[3];  

    UINT32 dwNCurr;   
    UINT32 dwNCurrCal;   

    UINT8 bPowerDir;   
    UINT32 dwP[4];    
    UINT32 dwQ[4];    
    UINT32 dwS[4];    

    UINT32 dwFre[3];   

    UINT32 dwUAngle[3];    
	UINT32 dwIAngle[3];    
    UINT32 dwPAngle[3];   

    UINT32 dwPF[4];   

    SINT32 lTemp;   

    UINT8 bState0;
    UINT8 bState1;
    UINT8 bState2;

    BOOL fgNoLoad ;   

    UINT32 dwActEnergy[4];   
    UINT32 dwReActEnergy[4];   



}stMeter_Data_Buffer;


 
 
 
 
enum
{
    POWERDIR_REACT_POWER_A,
    POWERDIR_REACT_POWER_B,
    POWERDIR_REACT_POWER_C,
    POWERDIR_REACT_POWER_SUM,
    POWERDIR_ACT_POWER_A,
    POWERDIR_ACT_POWER_B,
    POWERDIR_ACT_POWER_C,
    POWERDIR_ACT_POWER_SUM
};

 
 
 











 
 
 
enum
{
    STATE0_RESERVED0,
    STATE0_RESERVED1,
    STATE0_VOLT_PHASE_SEQU,    
    STATE0_CURR_PHASE_SEQU,    
    STATE0_RESERVED4,
    STATE0_RESERVED5,
    STATE0_RESERVED6,
    STATE0_RESERVED7
};

 
 
 
typedef struct _stMeter_State_Buffer
{
    UINT32 dwVersion;

    UINT8 bCalState;

    BOOL fgPraLoadOk;
    BOOL fgDataReady;

    UINT8 bRstType;
    UINT16 wRstCnt;

    UINT8 bICPraChkState;
    UINT8 bICPraErrCnt;

    UINT8 bDataRdErrCnt;
    UINT8 bDataValErrCnt;

}stMeter_State_Buffer;

 
 
 
 
enum
{
    METER_RST_TYPE_PWRUP,
    METER_RST_TYPE_PWRDOWN,

    METER_RST_TYPE_PRAERR,
    METER_RST_TYPE_RDERR,
    METER_RST_TYPE_VALERR,

    METER_RST_TYPE_MAX
};

 
enum
{
    PM_SLEEP,
    PM_NORMAL
};

 
enum
{
    READ_ENERGY_ACT,
    READ_ENERGY_REACT,



    READ_ENERGY_MAX
};

enum
{
    READ_ENERGY_NORMAL,
    READ_ENERGY_PD
};

 
enum
{
    IC_PRA_CHK_STATE_CONFIG,    
    IC_PRA_CHK_STATE_EXTRA,      
    IC_PRA_CHK_STATE_MEAS,        
    IC_PRA_CHK_STATE_POWER,     
    IC_PRA_CHK_STATE_OTHER       
};

 



 



 



 








 
 
 

struct stMeter_Config_Pra     
{ 
    UINT16 bWMSW; 
	UINT16 bModeSel; 
    UINT16 wAdcCfg;
    UINT16 HFConst1;
    UINT16 wPStart_PS;
	UINT16 wPStart_Q;
};




struct stMeter_Meas_Pra      
{ 
    UINT16 wUGainA;
    UINT16 wUGainB;
    UINT16 wUGainC;
    UINT16 wIGainA;
    UINT16 wIGainB;
    UINT16 wIGainC;
};


struct stMeter_Power_Pra    
{ 
	UINT16 wPGainA;
    UINT16 wPGainB;
    UINT16 wPGainC;
    UINT16 wPhiA;
    UINT16 wPhiB;
    UINT16 wPhiC;
	UINT16 wPoffsetAL;
    UINT16 wPoffsetBL;
    UINT16 wPoffsetCL;
	UINT16 wQoffsetAL;
    UINT16 wQoffsetBL;
    UINT16 wQoffsetCL;
};


struct stMeter_Extra_Pra     
{ 
    UINT32 dwEMUCfg;
    UINT32 dwEMUCtrl;
    UINT32 dwCFCfg;

};

struct stMeter_Spec_Pra    
{
    UINT32 dwVoltSpec;        
    UINT32 dwCurrSpec;        
    UINT32 dwPwrLimit;           
    UINT32 dwEngLimit;                
    UINT32 dwCFConstH;
	UINT32 dwVoltRatio;
	UINT32 dwCurrRatio;


    UINT32 dwGainOffsetNode;
    UINT32 dwGainAOffsetVal;
    UINT32 dwGainBOffsetVal;
    UINT32 dwGainCOffsetVal;

    UINT32 dwPhiOffsetNode;
    UINT32 dwPhiAOffsetVal;
    UINT32 dwPhiBOffsetVal;
    UINT32 dwPhiCOffsetVal;





};

 
typedef struct _stMeter_JustPraDef
{
    UINT16 rMeter_Meas_Pra_Init[(sizeof(struct stMeter_Meas_Pra)/2) ];
    UINT16 rMeter_Power_Pra_Init[(sizeof(struct stMeter_Power_Pra)/2) ];
    UINT16 rMeter_Config_Pra_Init[(sizeof(struct stMeter_Meas_Pra)/2) ];
    UINT32 rMeter_Extra_Pra_Init[(sizeof(struct stMeter_Extra_Pra)/4) ];
    UINT32 rMeter_Spec_Pra_Init[(sizeof(struct stMeter_Spec_Pra)/4)                                          ];
}stMeter_JustPraDef;




typedef struct _stMeter_ErrOffset_Pra
{
    UINT16 wGainAVal;
    UINT16 wGainBVal;
    UINT16 wGainCVal;

    UINT16 wPhiAVal;
    UINT16 wPhiBVal;
    UINT16 wPhiCVal;

}stMeter_ErrOffset_Pra;

extern stMeter_ErrOffset_Pra _rMeter_ErrOffset_Pra;



 
 
 
 
extern stMeter_Data_Buffer  _rMeter_Data_Buffer;
extern stMeter_State_Buffer  _rMeter_State_Buffer;

extern const stMeter_JustPraDef _rMeter_JustPraDef;

extern void vDelay_Us(UINT16 wCnt);
extern void vDelay_Ms(UINT16 wCnt);
extern void vMeter_Version(void);
extern void vMeter_Init(UINT8 bType);

extern BOOL fgMeter_Para_Init(void);
extern BOOL fgMeter_Function(void);
extern BOOL fgMeter_Com_JustParaSet(UINT8 bCommAddr,UINT32 dwCalData);
extern BOOL fgMeter_Para_Load(void);    
extern BOOL fgMeter_ICPraOk(void);
 
extern BOOL fgMeter_GetVolt(void);
extern BOOL fgMeter_GetCurr(void);
extern BOOL fgMeter_GetEnergy_Pd(void);


extern void vMeter_ErrOffsetPraSave(void);
extern void vMeter_ErrOffsetPraSave1(UINT8 bIndex);
extern void vMeter_ErrOffsetAdjust(BOOL fgInCal);





#line 6 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Measure_Interface.h"













 
struct JUSTMETER_PARAMETER
{
    struct stMeter_Meas_Pra   rMeter_Meas_Pra;
    struct stMeter_Power_Pra  rMeter_Power_Pra;
    struct stMeter_Config_Pra  rMeter_Config_Pra;
    struct stMeter_Extra_Pra   rMeter_Extra_Pra;

    struct stMeter_Spec_Pra   rMeter_Spec_Pra;

    UINT16  wResv;         
    UINT16  wPraCrc;     
};











extern struct JUSTMETER_PARAMETER   JustMeter_Parameter;

extern UINT32 angle[3];

extern UINT8 auxiliary_power_flag;  

extern union byte_def flag_communication_with_measuring_board;




extern volatile UINT32 temperatrue;

extern BOOL _fgMeter_Noload;
extern UINT8 Pulse_Constant_Writting;

extern UINT8 Volt_Region;
extern UINT8 Curr_Region;



extern UINT8 load_flag;        

extern void vMeter_RstDir(BOOL fgDir);
extern void vMeter_RstOut(BOOL fgLevel);
extern void vMeter_SleepDir(BOOL fgDir);
extern void vMeter_SleepOut(BOOL fgLevel);

extern void vMeter_SPI_Init(void);
extern BOOL vMeter_SPI_WriteReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen);
extern BOOL vMeter_SPI_ReadReg(UINT16 bAddr,UINT8 *pdwData,UINT8 bLen);

extern void Deal_PulseConst_Init(void);
extern UINT8 fgMeter_Com_Process(UINT8 *commad_addr, UINT8 *reg_addr, 
                                 UINT8 *sour_addr, UINT8 *des_addr);
extern BOOL fgMeter_PowerOn_Init(void);
extern void vMeter_VoltCurrSpecInit(void);
extern void Measure_Deal_Every_Second(void);
extern void Energy_Accumulation_Unit_10Wh(void);
extern void Middle_Energy_Accumulation_PerSecond_Main_Program(void);
extern void Get_Quadrant_Value(UINT16 *Quadrant_P);
extern UINT8 Send_Pulse_Constant_Data_to_Meter(UINT8 kind,UINT32 Acconst);
extern UINT8 Check_RAM_CRC(UINT8 *source_addr, UINT16 comp_value, UINT16 crc_len);
extern void Delay_Wait(UINT16 unit_10_uS);
extern void Just_meter_PD(void);
extern void Init_Relation_Meter_Apply(void);
extern UINT32 Get_Max_Value(UINT32 X,UINT32 Y,UINT32 Z);
extern void Just_para_Power_on(void);
extern void Check_If_Writting_Pulse_Constant_To_Card(void);
extern void Voltage_Phase_Deal(void);
extern BOOL fgJustParaRamCrcOk(void);
extern BOOL fgJustParaHandler(void);

extern void vMeter_ResInterface(void);
extern BOOL fgJustParaPDLoad(void);



#line 14 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Energy_Del.H"



extern union BYTE_DEF gPD_Data_valid_flag; 
                                           
                                           
                                           

extern void Check_Energy_main(unsigned char kind);
extern void Write_TO_Cal_PowerDown_Energy_add(void);



#line 15 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Pay_def.h"




#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/pay_Mac.h"
 
 
union Pay_For_Users_Flag1
    {
    struct
        {
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM1:1;     
        unsigned char FIRST_REMAIN_MONEY_LOW_ALARM2:1;     
        unsigned char FIRST_REMAIN_MONEY_LOW_ZERO:1;       
        unsigned char FIRST_REMAIN_MONEY_LOW_TICK:1;       
        unsigned char REMAIN_MONEY_OPEN_SWITCH:1;          
        unsigned char STEP1_OR_STEP2:1;						 
        unsigned char REMAIN_MONEY_LOW_ZERO_FREE:1;        
        unsigned char REMAIN_MONEY_LOW_ALARM2_FREE:1;      
        }bit;
    unsigned char  intd;
    };








 
 
union Pay_For_Users_Flag2
    {
    struct
        {
        unsigned char REMAIN_MONEY_LOW_ZERO_SWITCH:1;       
        unsigned char REMAIN_MONEY_LOW_ALARM2_SWITCH:1;     
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char REMAIN_MONEY_LOW_ALARM1_SHOW:1;        
        }bit;
    unsigned char  intd;
    };


 
 

 
 
union Pay_For_Users_Flag3
    {
    struct
        {
        unsigned char CLOSE_KEY_NE_RELAY:1;	  
        unsigned char FRIEND_DAY_CLOSE:1;		  
        unsigned char PUBLIC_CONTROL_RELAY:1;	  
        unsigned char CLOSE_KEY_WAI_RELAY:1;	  
        unsigned char WAION_ESAM:1;    			  
        unsigned char :1;
        unsigned char Fay_30ALimit:1;			  
        unsigned char Local_30ALimit:1;      	  
        }bit;
    unsigned char  intd;
    };





 


 
 
union Pay_For_Users_Flag4
    {
    struct
        {
        unsigned char SWITCH_ERR:1;				 	 
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B1:1;
        unsigned char SpicReq_SC:1;		 	 
        }bit;
    unsigned char  intd;
    };


 

 
 
union Pay_For_Users_Flag5
    {
    struct
        {
        unsigned char FRIEND_SUNDAY:1;                 
        unsigned char FRIEND_MONDAY:1;                 
        unsigned char FRIEND_TUSEDAY:1;                
        unsigned char FRIEND_WEDNESDAY:1;              
        unsigned char FRIEND_THURSDAY:1;               
        unsigned char FRIEND_FRIDAY:1;                 
        unsigned char FRIEND_SATURDAY:1;                
        unsigned char :1;
        }bit;
    unsigned char  intd;
    };







 

 
 
union Pay_For_Users_Flag6
    {
    struct
        {
        unsigned char FAY_CTL_RES:1;       			 
        unsigned char Curr_30A_Flg:1;				 
        unsigned char Curr_30A_Start_Cnt:1;			 
        unsigned char :1;
        unsigned char :1;
        unsigned char Pay_Buy_Money_Flg:1;			 
        unsigned char RecFlg:1;						 
        unsigned char COMM_ALL_AA:1;				 
        }bit;
    unsigned char  intd;
    };



 
 



 
 
union Pay_For_Users_Flag7
    {
    struct
        {
        unsigned char OVER_POWER_CLUE:1;                 
        unsigned char REMAIN_MONEY_LOW_ALARM1_CLUE:1;     
        unsigned char REMAIN_MONEY_LOW_ALARM2_CLUE:1;     
        unsigned char REMAIN_MONEY_LOW_ZERO_CLUE:1;      
        unsigned char REMAIN_MONEY_LOW_TICK_CLUE:1;      
        unsigned char SWITCH_ERR_CLUE:1;                 
        unsigned char ESAM_ERR:1;						 
        unsigned char Wai_SWITCH_ERR:1;					 
        }bit;
    unsigned char  intd;
    };








 
 
union Pay_For_Users_Flag8
    {
    struct
        {
        unsigned char BuyCountZero:1;		 
        unsigned char :1;
        unsigned char :1;	 
        unsigned char :1;	 
        unsigned char :1;    
        unsigned char :1;	 
        unsigned char SWITCH_PROHIBIT_ACT:1;	 
        unsigned char SWITCH_PREPARE_STATE:1;	 
        }bit;
    unsigned char  intd;
    };
 
 
 
 
 
 


 
 
union _FAY_CTL_RES_ERR
    {
    struct
        {
        unsigned char Hang:1;       	 
        unsigned char MacErr:1;			 
	    unsigned char PassErr:1;		 
        unsigned char NoIden:1;			 
        unsigned char TimeErr:1;		 
        unsigned char OpenFriErr:1;		 
        unsigned char WarnFriErr:1;		 
        unsigned char WarnTimeErr:1;	 		
		unsigned char WarnOpenErr:1;	 
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B15:1;
        }bit;
    unsigned int  intd;
    };

 
 
 
 
 
 
 
 
 
union _FAY_CTL_RES_OK
    {
    struct
        {
        unsigned char DirCls:1; 	 
        unsigned char AllowCls:1;	 
        unsigned char DirOpen:1;	 
        unsigned char DelayOpen:1;	 
        unsigned char Warn:1;		 
        unsigned char CurrDelay:1;	 
        unsigned char :1;
        unsigned char :1;
        unsigned char Friend:1;		 
        unsigned char FriFree:1;	 
        unsigned char Alarm:1;		 
        unsigned char AlarmFree:1;	 
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char B15:1;
        }bit;
    unsigned int  intd;
    };
 
 
union Pay_For_Users_Flag10
    {
    struct
        {
        unsigned char RELAY_ORDER_STATE:1;          
        unsigned char RELAY_CURR_STATE:1;           
        unsigned char SWITCH_MODE:1;					 
        unsigned char button_free_far_alarm_cmd:1;           
        unsigned char button_free_low_zero_alarm:1;          
        unsigned char button_free_low_alarm2:1;              
        unsigned char :1;
        unsigned char :1;
        unsigned char ALARM_ORDER_STATE:1;           
        unsigned char ALARM_CURR_STATE:1;            
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;       
        }bit;
    unsigned int  intd;
    };




 
 
 
 
 
 
 
 
 
 
union Pay_For_Users_Flag11
    {
    struct
        {
        unsigned char REALY_ON_OFF_KIND:1;         
        unsigned char LCD_TRIFF_SLOT:1;               
        unsigned char EVENT_REPORT_MODE_SELECT:1;   
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        unsigned char :1;
        }bit;
    unsigned char  intd;
    };




 
 
 
 
 
 
 
 
 
union Pay_For_Users_Flag12
    {
    struct
        {
        unsigned char TRIFF_SWITCH_FLAG:1;         
        unsigned char STEP_SWITCH_FLAG:1;          
        unsigned char FAR_OPEN_PREPARE:1;     
        unsigned char Wai_SWITCH_CLOSE:1;	 
        unsigned char FAR_OPEN_SWITCH:1;  	 
        unsigned char NOT_CLOSE_BY_30A:1; 	 
        unsigned char FAR_OPEN_ALARM:1;    	 
        unsigned char FAR_CLOSE_ALARM:1;  		 
        }bit;
    unsigned char  intd;
    };









 
 
union Pay_For_Users_Flag13
    {
    struct
        {
        unsigned char METER_IN_FRIEND_DAY:1; 
        unsigned char REMAIN_MONEY_OVER_CLUB:1;
		unsigned char FAR_WARN_1D:1;		 
		unsigned char FAR_WARN_1E:1;   		 
	 	unsigned char FAR_OPEN_CMD:1;    		 
        unsigned char FAR_OPRATE_ID:1;		 
        unsigned char OPRATE_ID_CLOSE:1;	 
        unsigned char SWITCH_ALLOW_CLOSE:1;	 
        }bit;
    unsigned char  intd;
    };









 
 
union Pay_For_Users_Flag14
    {
    struct
        {
        unsigned char FAR_OPEN_RECORD:1;
        unsigned char FAR_CLOSE_RECORD:1;
        unsigned char SWITCH_FACT:1;		 
        unsigned char FUN_BUY_FLAG:1;
        unsigned char FRIEND_RELEASE_SWITCH_FLAG:1;
        unsigned char DIRECT_CLOSE_SWITCH:1;
        unsigned char is_year_bill:1;        
        unsigned char CREATE_ZERO:1;		  
        }bit;
    unsigned char  intd;
    };













 
 
union Pay_For_Users_Flag15
    {
    struct
        {
        unsigned char LocalOpen:1;				 
        unsigned char FarOpen:1;				 
        unsigned char RelayErrFlag:1;			 
        unsigned char RelayErrCheck:1;			 		
        unsigned char :1;
        unsigned char :1;
        unsigned char PowerOnYearBill_flag:1;
        unsigned char to_upd_psw:1;
        }bit;
    unsigned char  intd;
    };




 
 



 
 
 
 
 
 
 
 
 
 
union Pay_For_Users_Flag16
    {
    struct
        {
        unsigned char REMAIN_BAG_DOING:1;		 
        unsigned char EVENT_OCCUR:1;			 
        unsigned char WAI_RELAY_PULSE_DOING:1;	 
        unsigned char LCD_Triff_Flag:1;			 
        unsigned char LCD_Step_Flag:1;				
        unsigned char :1;
        unsigned char Bill_Date_Change_Switch:1;	 
        unsigned char Bill_Date_Change_Modify:1;	 
        }bit;
    unsigned char  intd;
    };





 




 


#line 5 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Pay_def.h"
























 







 
 


	 


	 











union Int_To_Char
    {
    unsigned int U_int;
    unsigned char U_char[2];
    };
union Long_To_Char
    {
    unsigned long U_long;
    unsigned int U_int[2];
    unsigned char U_char[4];
    };    

struct FARCONTROLEVENT
{
	unsigned long farSwitch_Ticks;
	unsigned long farClose_Ticks;
};






 
struct YEAR_BILLDATE_DEF				 
{
       unsigned char Month;
       unsigned char Day;
	   unsigned char Hour;
};


 
struct PRE_YEAR_BILLDATE_DEF				 
{
       unsigned char YEAR;
       unsigned char Month;
	   unsigned char Day;
	   unsigned char Hour;
};

struct PRE_MONTH_BILLDATE_DEF
{
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Min;
};

 
 


 
 
 
 
 
 
 
 
 
 
 
 


 
 
 
struct _Pre_Payment_Data
    {
    unsigned long Last_Buy_Money;			   		 
    unsigned long Total_Buy_Money;			  		 
	unsigned long Bef_Month_Total_Energy;			 	
	unsigned long Bef_Year_Total_Energy[4];			 
	struct  PRE_YEAR_BILLDATE_DEF Year_Total_Energy_Date;    
	struct  PRE_YEAR_BILLDATE_DEF Pre_Year_BillDate[4];		 
	unsigned char oprateCode[4];
	unsigned long CurrMoneyT;						 
	unsigned char HangMeterNum;						 
	unsigned int  OPCard_StatusByte;				 
	unsigned char Esam_Identity[5];					 
    unsigned char OverPowerSw_Time;					 
	unsigned char Reserve_User[4];					 
	
	unsigned char Year_Bill_Point;					 
	
	struct FARCONTROLEVENT FARCONTROLEVENT;			 
	unsigned long TriffProgNum;						 
	unsigned long StepProgNum;						 
	unsigned long Relay_Error_Num;					 
    unsigned long Back_Money_Count;            		 
    unsigned long Far_Key_Updata_Count;            	 
	unsigned long OPCard_Error_Num;					 
    unsigned long Unlawful_Card_Count;            	 

 
 
 
 
 
 
 
 
 
 
 
 
 

    unsigned int    Crc_Cs;                          
    };


























 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
struct _Pre_Payment_Para
    {
    unsigned long Base_Money;                          
    unsigned long Hire_Money;                          
    unsigned long Remain_Money_Alarm1_Limit;           
    unsigned long Remain_Money_Alarm2_Limit;           
    unsigned long Remain_Money_Tick_Limit;             
    unsigned long Remain_Money_Hoard_Limit;            
    unsigned long Triff[2][32            ];                
    unsigned long Multiple;                            
    unsigned long C_T;                                 
    unsigned long P_T;                                 
    unsigned char SysID[6];                            
    unsigned char UserID[6];                           
    unsigned char MeterID[6];                          
    unsigned char CardID;                         		 
	unsigned char User_Kind;                           
    struct DATEANDTIME_DEF TriffSwitchDate;            
    struct DATEANDTIME_DEF StepSwitchDate;             
    unsigned char Meter_Run_State;                     	
    unsigned char Money_Point;                         
    unsigned long Buy_Count;                           
    unsigned char Step_Num[2];                         
    unsigned long Energy_Step[2][6			  ];                   
    unsigned long Triff_Step[2][6			  +1];                    

	struct YEAR_BILLDATE_DEF  Year_BillDate[2][4]; 			 		 

	
    union Pay_For_Users_Flag1  Pay_For_Users_Flag1;    
    union Pay_For_Users_Flag2  Pay_For_Users_Flag2;    
    union Pay_For_Users_Flag3  Pay_For_Users_Flag3;    
    union Pay_For_Users_Flag4  Pay_For_Users_Flag4;    
    union Pay_For_Users_Flag5  Pay_For_Users_Flag5;    
	union Pay_For_Users_Flag11 Pay_For_Users_Flag11;   
    union Pay_For_Users_Flag12 Pay_For_Users_Flag12;   
    union Pay_For_Users_Flag13 Pay_For_Users_Flag13;   
    union Pay_For_Users_Flag14 Pay_For_Users_Flag14;   
    union Pay_For_Users_Flag15 Pay_For_Users_Flag15;   

 
 
 
	unsigned char InfrIdenTime;                   
	unsigned char Switch_Test_Num;			 
	unsigned long Far_Key_StatusByte;        	 	 
 
 
 

	unsigned long Para_Card_Version;            
	unsigned int CurrLimitProTime;                  
	 

	unsigned char PassWord_Kind;                  
	unsigned long Close_Switch_Limit;            
	unsigned char TriffPriceNum;           		 
	unsigned char Far_Day_Follow;			 
	unsigned char Card_Reset_Inf[8];            
	unsigned int Far_Open_Delay;			  
	unsigned int Far_Close_Delay;			  
	unsigned int RelayActTime;			 	 
	unsigned int RelayActEnergy;			  
	unsigned long CurrLimit;			 		 

	unsigned char PassWord_Num;				  		 
	unsigned char psw_status;				  

	unsigned int ID_Ins_Time;				 

	unsigned long SendBack_Money;			 

    unsigned int  Crc_Cs;                              
    };








































	
	 
	 
	 




	


	










	





	
 
 
 
struct _Pay_For_Event_Point
    {
    unsigned char Buy_Event_P;                              
    unsigned char Far_Control_Event_P;                      
    unsigned char Far_Control_Free_Event_P;                 
    unsigned char Triff_Switch_Event_P;                     
    unsigned char Step_Switch_Event_P;                      
    unsigned char Remain_Money_Alarm1_Event_P;              
    unsigned char Remain_Money_Alarm2_Event_P;              
    unsigned char Remain_Money_Zero_Event_P;                
    unsigned char Remain_Money_Tick_Event_P;                
    unsigned char Money_Balance_Event_P;                    
    unsigned char Triff_Updata_Event_P;                     
    unsigned char Step_Updata_Event_P;                      
    unsigned char Far_Key_Updata_Event_P;              	 	
	unsigned char OPCard_Error_Event_P;					 	 
	unsigned char Refundment_Event_P;						 		 
	unsigned char RelayErr_Event_P;						 	
	unsigned char YearBillDate_Event_P;					 		 
	unsigned char ProgramTriff_Event_P;						 	
	unsigned char ProgramStep_Event_P;						 	
	unsigned char E_Burse_Event_P;							 
	unsigned char Month_Bill_Event_P;							 
    unsigned int  Crc_Cs;                                   
    };























 





















 
 
 
 
 



 
 













 



 
 
 





 
 

 
 
 
 
 
 
 



 







 
 


 
 
 
 
struct DATEANDTIME_6BYTE_DEF
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Min;
	unsigned char Sec;
};


struct _OPCard_Error_format
{
	 
	 
	unsigned char				   CMD[5];
	unsigned char				   Response[2];
};


 

struct upd_psw_info
{
	unsigned char psw_info[32         ][(36 + 4)  ];    
    unsigned long upd_flg;   
    unsigned char pwd_stat;  
    unsigned char seq_num ;  
};







 
 
 
 
 

struct _Pay_Eeprom_Define
    {
	struct _Pre_Payment_Data               Pre_Payment_Data;               
    struct _Pre_Payment_Para               Pre_Payment_Para;                
    struct _Pay_For_Event_Point            Pay_For_Event_Point;            
	unsigned char       					RelayErr_Area[29];     	  
	struct upd_psw_info 				psw_info;   			 
	unsigned char    					Pre_Tmp[29];		 	
    };












 
 
struct Event_format
    {
    unsigned char * Addr;
    unsigned int Length;
    };
struct Event_format_d
    {
    unsigned char format;
 
 
 
 
 
 
 
 
    unsigned char format1;
    };

typedef void (* Event_Spec_Deal)(unsigned char *);
typedef unsigned char  (* Event_Spec_Deal_R)(unsigned char *);

 
 
struct Pay_Period_Event_format
    {
    const unsigned char *Data_Point;          
    const unsigned char *Data_Point_Format;   
    unsigned int Head_File_Addr;              
    unsigned int Event_Record_Number;         
    unsigned int EE3_Addr;                    
    unsigned char Event_Point_Offset;         
    Event_Spec_Deal Period_Event_Spec_Deal;   
    };

 
 
struct Pay_Time_Drop_Event_format
    {
    const unsigned char *Data_Point;          
    unsigned int Head_File_Addr;              
    unsigned int Event_Record_Number;         
    unsigned char Event_Point_Offset;         
    Event_Spec_Deal Drop_Event_Spec_Deal;     
    };

 
 
struct Check_format
    {
    unsigned int Eeprom_Addr;
    unsigned char * Addr;
    unsigned int Length;
    unsigned char Flag;      
    };














#line 16 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Ex_Cpucard_Driver.h"
 
 
 

 
 

 
 
 
 
 
 
 
 
 
 

 
  
 

 
 
 
 

 
 
 

 
 
 













 
 













 
 









 
 





 
 











 
 

extern void Receive_Data_To_Cpucard(void);             

extern unsigned char Check_CPU_Occur(void);            
                                                       
extern void CPU_VCC_Control(unsigned char );           
                                                       
extern void CPU_CLK_Control(unsigned char );           
                                                       
extern void CPU_RST_Control(unsigned char );           
                                                       

extern void ESAM_VCC_Control(unsigned char );          
                                                       
extern void ESAM_CLK_Control(unsigned char );          
                                                       
extern void ESAM_RST_Control(unsigned char );          
                                                       

extern void CPU_ESAM_CARD_Control(unsigned char);      


extern void Cpu_Card_IO_Init(void);                    
extern void Cpu_Card_IO_Reset(void);                   

extern void Cpu_PowOff(void);                          
extern void Cpu_Reset_Cool(void);                      

extern void Esam_PowOff(void);                         
extern void Esam_Reset_Cool(void);                     

extern void Enable_Serial_Receive(void);               
extern void Enable_Serial_Send(void);                  
extern unsigned char Wait_Receive(unsigned char );     
                                                
                                                
extern unsigned char Cpucard_Atr(void);                
extern unsigned char Esamcard_Atr(void);               

 

extern unsigned char Internal_Auth(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                                
extern unsigned char External_Auth(unsigned char ,unsigned char ,unsigned char *);
                                                
extern unsigned char Cpucard_Esamcard_Internal_Auth(unsigned char );   
                                                
                                                
extern unsigned char Cpucard_External_Auth(void);      
                                                

extern unsigned char Select_File(unsigned char ,unsigned char ,unsigned char );
                                                
                                                
extern unsigned char Read(unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char );
                                                
extern unsigned char Write(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char *);
                                                

extern unsigned char Card_Write(unsigned char,unsigned char *,unsigned char,unsigned char  );
                                                
                                                
extern unsigned char Cpu_card_Block_Write(unsigned char ,unsigned char *,unsigned char ,unsigned int  );

extern unsigned char Card_Read(unsigned char ,unsigned char *,unsigned char,unsigned char  );
                                                
                                                

extern void My_Memcpy(unsigned char *,unsigned char *,unsigned char);  
extern unsigned char My_Memcmp(unsigned char *,unsigned char *,unsigned char);  

extern void Pay_IO_Init(void);
extern void Cpu_Card_IO_Powerdown(void);                        

extern unsigned char Remain_Money_Moneybag_Add(unsigned char ,unsigned char,unsigned char *);
extern unsigned char Remain_Money_Moneybag_Step(unsigned char ,unsigned char );
extern unsigned char Remain_Money_Moneybag_Init(void);
extern unsigned char Esam_File_Updata(unsigned char ,unsigned char ,unsigned char ,
									  unsigned char ,unsigned char ,unsigned char *);
extern unsigned char Cpu_File_Updata(unsigned char ,unsigned char ,unsigned char ,
							   		unsigned char ,unsigned char );
extern unsigned char Remain_Money_Moneybag_To_Cpu(void);
extern unsigned char Read_Esam_Moneybag_File(unsigned char * );

extern unsigned char Esam_Remain_Money_Dec(void);
extern void Esam_Remain_Money_Do(unsigned char );
extern unsigned char  CPU_Card_Driver(const unsigned char *,unsigned char ,unsigned char *,unsigned char,unsigned char,unsigned char);
extern unsigned char Get_File_Data(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char * );
extern unsigned char CPU_Counter_Dec(unsigned char ,unsigned char );
extern unsigned char PassWord_Updata(unsigned char);
extern void Cpucard_Serial_Init(void); 
extern void cpucard_serial_release(void);
extern unsigned char Judge_Return_Flag(void);
extern void Receive_Data_To_Cpucard_CPU(void);
extern void Receive_Data_To_Cpucard(void);

 
 
extern unsigned int receive_data_length;       
extern unsigned char cpucard_number[8];         
extern unsigned int press_card_state;            
extern unsigned char receive_send_buffer[];  
extern unsigned char CommunicationPortMode;
extern unsigned char Far_Comm_Init_NO;

extern unsigned char Esam_Err_Count;
extern unsigned long Reamin_Money_ESAM_Dec_Time;


#line 17 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Ex_Pay_For_Fun.h"

 

extern struct _Pre_Payment_Data            Pre_Payment_Data;
extern struct _Pre_Payment_Para            Pre_Payment_Para;
extern struct _Pay_For_Event_Point         Pay_For_Event_Point;          

extern unsigned char Buy_ID; 
extern unsigned char Relay_Alarm_SWitch_Flag[2][2];
extern unsigned char Buzzer_Alarm_SWitch_Flag;
extern union  BYTE_BIT Buzzer_Alarm_Control;
extern unsigned long Curr_Money;                                  
extern unsigned long Curr_Money_T;                              
extern unsigned long Curr_Money_S;                              
extern unsigned char relayPlusTime;			 
extern unsigned char relayPlusCnt;			 
extern unsigned char R_CARD_ERROR_INFO;

extern union Pay_For_Users_Flag6  Pay_For_Users_Flag6;    
extern union Pay_For_Users_Flag7  Pay_For_Users_Flag7;    
extern union Pay_For_Users_Flag8  Pay_For_Users_Flag8;    
extern union Pay_For_Users_Flag16 Pay_For_Users_Flag16;   
extern union Pay_For_Users_Flag10 Pay_For_Users_Flag10;
extern union _FAY_CTL_RES_ERR 	Fay_Ctl_Res_Err;
extern union _FAY_CTL_RES_OK 	Fay_Ctl_Res_Ok;



extern unsigned char Curr_Step_Triff;   
extern unsigned char Curr_Step_Triff_1;   
extern unsigned long Nei_Relay_Do_Energy;
extern unsigned long Nei_Relay_Do_Time;

extern unsigned char Curr_Period_Flag;  


 
extern unsigned int Prepare_CRC_Check(unsigned char * ,unsigned int );


extern void My_Memcpy(unsigned char *,unsigned char *,unsigned char);  

extern unsigned char Pay_EE_W(unsigned int,unsigned char * ,unsigned int,
                              unsigned char,unsigned char *,unsigned int,unsigned int);

extern unsigned char ClearPaymentEventRecord(unsigned long ,unsigned long );
extern void Pay_Money_Clear(void);
extern void Pay_Data_Clear(void);
extern void Pay_Data_All_Clear(void);
extern void Pre_Moneth_Updata(void);
extern void Pre_Bill(unsigned char *);


extern unsigned char is_year_bill_date(struct DATEANDTIME_DEF *cur);
extern int Pre_Duct_Data_Clear(void);
 
 
extern void Buzzer_Init(void);
extern void Buzzer_Second_Active(void);
extern unsigned char Buzzer_Active(void);
extern void Buzzer_Pay_Cortrol(unsigned int,unsigned char,unsigned char);
extern void Inttupt_Buzzer_Deal(void);
 
extern void Relay_Deal_Init(void);
extern void Drive_Act_Repair(void);
extern void Relay_Deal(unsigned char);
 
extern void Lcd_Light_Control(void);
extern void Pay_Led(void);

 
extern void Card_Alarm_Switch(void);

 
extern void Remain_Money_Duct(unsigned char);

 
extern void Remain_Money_Alarm_Judge(void);

 
extern void Pay_For_Para_Init(void);
extern void Pay_For_Para_Read(void);

 
extern void Pay_For_Para_Down_Save(void);
extern void Pay_For_Data_Save(void);
extern void Pay_For_Para_Down_Check(void);
extern void Pay_Event_Record_Data(void);

extern void Pay_Event_Record_Clear(void);

extern void Find_Step_Curr_Triff_2(void);


 
 
extern void Pay_For_Event_Dot(const unsigned char * );
extern const struct Pay_Time_Drop_Event_format Buy_Event;
extern const struct Pay_Time_Drop_Event_format Far_On_Event;
extern const struct Pay_Time_Drop_Event_format Far_OFF_Event;
extern const struct Pay_Time_Drop_Event_format Triff_Switch_Event;
extern const struct Pay_Time_Drop_Event_format Triff_Updata_Event;
extern const struct Pay_Time_Drop_Event_format Step_Switch_Event;
extern const struct Pay_Time_Drop_Event_format Step_Updata_Event;
extern const struct Pay_Time_Drop_Event_format Far_Key_Updata_Event;
extern const struct Pay_Time_Drop_Event_format OPCardErr_Event;		 
extern const struct Pay_Period_Event_format RelayErr_Event;
extern const struct Pay_Time_Drop_Event_format ProgramTriff_Event;
extern const struct Pay_Time_Drop_Event_format ProgramStep_Event;
extern const struct Pay_Time_Drop_Event_format E_Burse_Event;
extern const struct Pay_Time_Drop_Event_format Refundment_Event;



	
 
extern void Pay_For_Event_Period(const unsigned char * ,unsigned char );


 
extern void Run_Triff_Switch(unsigned char);


 
extern void Pay_Real_Flag_Updata(void);

 
extern void Hour_Freeze_Run(void);

extern void lxrBcd_Hex(unsigned char ,unsigned char *);

extern void Find_Curr_Money(void);
extern void Switch_Plus_Start(unsigned char);
extern void Switch_Plus_Drive(void);
extern void Button_Alarm_Switch(void);
extern void switch_year_stage_mouth_stage(void);
extern unsigned char get_run_step_num(void);

extern void Current_Over_30A_Function(void);

#line 18 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.h"
 





 
 
struct Authentication_Instruction
{
	unsigned char cryptograph1[8];								 
	unsigned char	random_number1[8];							 
	unsigned char disperse_gene[8];							 
};

struct Authentication_Responsion
{
	unsigned char	random_number2[4];							 
	unsigned char	esam_serial_number[8];						 	
};

struct Far_Identity_Authentication_Define
{
	struct Authentication_Instruction Instruction;					 
	struct Authentication_Responsion Responsion;					 
};

struct Far_Buy_Money_Data_Define
{
	unsigned long buy_money;									 
	unsigned long buy_count;									 
	unsigned char mac1[4];									 
	unsigned char disperse_gene[8];							 
	unsigned char user_id[6];									 
	unsigned char mac2[4];									 
};

struct Open_Close_Switch_Command_Define
{
	unsigned char open_close_switch_control;					 
	unsigned int  open_close_switch_report_emergency_time;	 
	unsigned int open_close_switch_enable_time;				 
	unsigned char Year;										 
    unsigned char Month;
    unsigned char Day;
    unsigned char Hour;
    unsigned char Min;
    unsigned char Sec;		
};

union SECURITY_AUTH_ERR_INFORMATION
{
    struct
      {  
	unsigned char OTHER_ERR:1;		 
	unsigned char REPEAT_INCREASE_ERR:1;		 
	unsigned char ESAM_AUTH_ERR:1;	 
	unsigned char IDENTITY_AUTH_ERR:1;	 
	unsigned char CLIENT_ID_ERR:1;			 
	unsigned char BUY_COUNT_ERR:1;			 
	unsigned char BUY_MONEY_OVER_ERR:1;				 
	unsigned char addr_err:1;			 
	unsigned char HANG_ERR:1;						 
	unsigned char :1;						 
	unsigned char :1;						 
	unsigned char :1;						 
	unsigned char :1;						 
	unsigned char :1;						 
	unsigned char :1;						 
	unsigned char :1;						 
      }bit;
      unsigned int intd;  
}; 










 
struct cmd_plaintext {
    unsigned char code;          
    unsigned char rsv;           
    struct DATA_TIME deadline;   
};

 
 
 
 
 
 
 
 
 
 
extern struct _Pre_Payment_Para            Pre_Payment_Para;
 
extern struct _Pre_Payment_Data            Pre_Payment_Data;
extern struct Far_Identity_Authentication_Define Far_Identity_Auth_Data;		 
extern unsigned char Far_Identity_Auth_Ok_Flag;						 	 
extern unsigned long Far_Identity_Auth_Ok_Time;						 	 
extern unsigned int Esam_Far_Identity_Auth_Valid_Time;						 
extern unsigned char Far_Spec_Order_Flag;
extern unsigned int  R_ID_Remain_Time;
extern unsigned char Far_InfraredFlag; 
extern unsigned int  R_Infrared_Remain_Time;
extern unsigned long Far_Infrared_Auth_Ok_Time;
extern unsigned long FarOpenTime;
 


extern unsigned char Far_Password_Check(unsigned char *  ,unsigned char *  ,unsigned char *);

 
extern void Far_Prepayment_Read_Write(unsigned char );			 
extern void Far_Control(unsigned char );	
extern void Far_Switch_Control(unsigned char);

extern unsigned char cmd_0x98_mode_decipher(unsigned char uartx, unsigned char cmd_code);
extern void clear_psw_upd_info(void);
extern void get_meter_para_from_esam(void);
extern unsigned char check_and_update_psw_to_esam(void);
extern unsigned char get_psw_status_wd_from_esam(void);
extern void record_esam_oprate_err(void);
extern void end_infrared_auth(void);
extern unsigned char is_test_psw_status(void);


extern unsigned char refund_money(signed long money);

 



#line 19 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/ICcard.h"
 







 





 
 





 














 



























 
 
 



 






















 




 































































 







 

 

 
 
 
 
 



 
 
 


union ICcard_Flag1
    {
    struct
        {
        unsigned char DISP_SIGN_FLAG:1;			 
		 unsigned char DISP_MONEY_FLAG:1;		 
        unsigned char DISP_PLUS_FLAG:1;			 
        unsigned char DISP_NEGA_FLAG:1;			 
        unsigned char DISP_MYRIAD_FLAG:1;		 
        unsigned char GPRS_MODEL:1;			  	
        unsigned char CARRIER_MODEL:1;		  	
        unsigned char SWITCH_ACT_MODE:1;	  	
        }bit;
    unsigned char  intd;
    };
extern union ICcard_Flag1 ICcard_Flag1;










struct CardErrId
{
	unsigned int oldID;
	unsigned char newID;
};


 
struct USECARD_INFOR_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char syeID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long triffBottom[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char buyTime[6];
	unsigned char triffSwitchDate[4];
	unsigned char	Cs;
	unsigned char End;
};

struct PARACARD_INFOR_FILE
{
  	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char triffSwitchDate[4];
	unsigned char Cs;
	unsigned char End;
};

struct RIFFCARD_TIMEZONE_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char yearSlotNumble;
	unsigned char yearTable[4][4];
	unsigned char dailySlotTableNumble;
	unsigned char dayTable[4][12][3];
	unsigned char holiday[13][3];
	unsigned char weekEndTable;
	unsigned char Cs;
	unsigned char End;
};

struct ADDCARD_COMMAND_FILE
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char userID[5];
	long               buyMoney;
	unsigned int    buyCount;
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE1
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char userID[5];
	unsigned char oldMeterID[5];
	unsigned char newMeterID[5];
	unsigned char meterRunstate;
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE2
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
	unsigned char cardID;
	unsigned long triff[4];
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTimeLimit;
	unsigned char overPowerOpenSwTime;
	unsigned char overPowerCloseSwTime;
	unsigned char triffSwitchDate[4];
	unsigned char Cs;
	unsigned char End;
};

struct CHANGE_INIT_FILE3
{
	unsigned char Start;
	unsigned char Command;
	unsigned char Len;
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long buyMoney;
	unsigned int   	buyCount;
	unsigned long triffEnergy[5];
	unsigned long tickMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowerSwTime;
	unsigned char unlawfulCardCount;
	unsigned char Cs;
	unsigned char End;	  
};

 
struct User_Back_Infor
{
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long lastBuyMoney;
	unsigned int 	buyCount;
	unsigned long triffEnergy[5];
	unsigned long overZeroMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowSwTime;
	unsigned char unlawfulCardCount;
};

struct Check_Back_Infor
{
	unsigned char sysID[2];
	unsigned char userID[5];
	unsigned char meterID[5];
		signed long remainMoney;
	unsigned long totalBuyMoney;
	unsigned long lastBuyMoney;
	unsigned int 	buyCount;
	unsigned long triffEnergy[5];
	unsigned long triff[4];
	unsigned long overZeroMoney;
	unsigned long lastMonthFreezeEnergy;
	unsigned long moneyLimit[2];
	unsigned long moneyHoard;
	unsigned char overPowerPlusLimit[3];
	unsigned char powerPeriod;
	unsigned char overPowSwTime;
	unsigned char unlawfulCardCount;
	unsigned char meterStatus;
	unsigned char writeBackTime[6];
};

 
extern char maxSetpNum;
extern unsigned char display_Remain_Flag;		 
extern unsigned char Card_Type;
extern signed long Remain_Money_Temp;
extern unsigned long Remain_Money_Plus;
extern unsigned long Remain_Money_Nega;
extern unsigned long Power_Plus_Number;			 
extern unsigned long Power_Count_Time;			 
 
extern unsigned char Card_WR_Buff[512];
extern unsigned char Dir_Return_Flag;                       
extern unsigned char Para_Updata_Flag;               
extern unsigned char Para_Updata_Flag_Suc;
extern unsigned char Meter_Ins_Flag;
extern unsigned long buyBeforMoney;					 
extern unsigned long Remain_Money_Plus;			 
extern unsigned long Remain_Money_Nega;		 
extern unsigned char eventReportTime;			 
extern unsigned char clearFlag;
extern union ID CurrReadId;				 	
 
extern unsigned char RunStepNum;			 
extern unsigned char G_Rec_Disp_Flg;

 
extern void ICcard_Main(void);
extern void Pre_Init(void);
extern void Pre_Display(unsigned char );
extern void Pre_Display_Char_Flash(void);
extern void Pay_Minute_Act(void);
extern void Find_PassInf_Status(void);
extern unsigned char Pre_Static_Display_Remain(void);
extern void Pre_Get_OverZero_Money(void);
extern void FarSwitchControl(unsigned char uartx);
extern void buy_money_event(unsigned char *);
extern void far_conrol_event(unsigned char *);
extern void far_close_event(unsigned char *);
extern int Get_Pay_Flag(void);
extern int Get_FarControl_Flag(void);
extern int Get_Payment_Flag(void);
extern int Set_PayMod2(void);
extern int Set_CT(void);
extern int Set_PT(void);
extern int Set_Triff_Price(void);
extern int Set_Step_Price(void);
extern int  Set_TriffPrice_Num(unsigned char num);
extern int Set_Step_Num(void);
extern int Set_PassNumber(void);
extern int Get_Plus_Money(void);
extern int Get_Nega_Money(void);
extern int Get_Remain_Money(void);
extern int Get_Remain_Energy(void);
extern int Get_OPCard_StatusByte(void);
extern int Get_Month_Energy(void);
extern int Get_Year_Energy(void);
extern int Get_OpCardErr_ID(void);
extern int Get_OpCardErr_ID2(void);
extern int Get_OpCardErr_Cmd(void);
extern int Get_OpCardErr_Cmd2(void);

extern int Get_Pre_UserD(void);
extern int Set_Pre_UserD(void);
extern int Get_Money_Flag(void);
extern int Get_Energy_Flag(void);
extern int Get_Current_Triff(void);
extern int Set_Bak_Setp_Para(void);
extern int Set_Bak_Setp_Para(void);
extern int Get_Meter_ID(void);
extern int Set_Meter_ID(void);
extern void getRelayType(void);
extern void getCarrierGprs(void);
extern int Set_PaySwitchDate(void);
extern int Set_Ne_RelayActTime(void);
extern int Set_InfaIdenTime(void);
extern int Set_PassWord(void);
extern int Set_Wai_RelayActEnergy(void);
extern unsigned char getCardErrConver(unsigned char inData);
extern unsigned char Cal_Add_CS(unsigned char * ,unsigned char );
extern void Reverse_data(unsigned char *, unsigned int );
extern void My_memcpyRev(unsigned char *to,unsigned char *from,unsigned char len);
extern unsigned char Judge_Remain_Money_Over(unsigned long );
extern void Meter_Money_And_Count_Updata( unsigned long ,unsigned long );
extern unsigned char Updata_Esam_Return_File(unsigned char Order_Kind, unsigned long ,unsigned long);
extern unsigned char GetRelayPort_Status(void);
extern void Pay_For_Event_Period(const unsigned char * Para_Point ,unsigned char mode );
extern unsigned char F_E_BurseFreezeData(void);
extern int Get_TriffPrice2(void);
extern int Set_TriffPrice2(void);
extern int Set_Yer_Bill_Data(void);
extern int Refundmentment_Money(void);

 
extern int Get_Current_Triff(void);
extern int Get_cur_which_step(void);


#line 20 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/645_2007.h"
 
 
 
 
 
 






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

 

#line 21 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Card_File.h"
 
 
 
 
 
 
 
 
 
 













 





 



 




 








 




 


 

 

 

 
 
struct Triff_Data
	{
	unsigned long Triff[32];         
	unsigned long Grads_Value[6];   		 
	unsigned long Grads_Price[7];   		 
	unsigned char Bill_Date[4][3];	    		 
	unsigned char Grad_Switch_Date[5];	  	
	};







  

 
struct Moneybag_Data
	{
	unsigned long Remain_Money;
	unsigned long Buy_Count;
	};





 
 
 
 
 
 
struct Para_Table1
	{
	unsigned char Card_Kind;                  
	unsigned char Client_ID[6];               
	unsigned char Meter_ID[6];                
	};

 
struct Para_Table2
	{
	unsigned char User_Kind;                   
	unsigned char Para_UpData_Flag;           
	};

 
struct Para_Table3
	{
	unsigned long Remain_Money_Alarm1_Limit;  
	unsigned long Remain_Money_Alarm2_Limit;  
	unsigned char Current_CT[3];              
	unsigned char Voltage_PT[3];              
	};

 
struct Para_Table4
	{
	unsigned char Triff_Switch_Time[5];       
	};

 
struct Para_Table5
	{
	unsigned long Para_Card_Version;       
	};

 
struct Para_Table6
	{
	unsigned int  Identity_Auth_Time;        
	};

 
 
 
 
struct Run_Inf_Data
	{	
	unsigned char User_Kind;					 
	unsigned char Current_CT[3];				 
	unsigned char Voltage_PT[3];				 	
	unsigned char Meter_ID[6];					 
	unsigned char Client_ID[6];				 
	unsigned long Remain_Money;				 
	unsigned long Buy_Count;					 
	unsigned long Low_Zero_Money;				 
	unsigned char Password_Info[4];			 
	unsigned char Unlawful_Card_Count[3];		 
	unsigned char Return_DT[5];				 
	};

 
 
 
 
 
 
struct Esam_Para_Inf_File
	{
	unsigned char User_Kind;                  
	unsigned char Para_UpData_Flag;           
	unsigned long Para_Card_Version;       
	unsigned char Triff_Switch_Time[5];       
	unsigned char No_Use;                       
	unsigned long Remain_Money_Alarm1_Limit;  
	unsigned long Remain_Money_Alarm2_Limit;  
	unsigned char Current_CT[3];              
	unsigned char Voltage_PT[3];              
	unsigned char Meter_ID[6];                
	unsigned char Client_ID[6];               
	unsigned char Card_Kind;                  
	unsigned int  Identity_Auth_Time;        
	};















 
 
 
struct Buy_Para_Inf_File
	{
	unsigned char User_Kind;                  
	unsigned char Para_UpData_Flag;           
	unsigned char No_Use0[4];       
	unsigned char Triff_Switch_Time[5];       
	unsigned char No_Use1;                       
	unsigned long Remain_Money_Alarm1_Limit;  
	unsigned long Remain_Money_Alarm2_Limit;  
	unsigned char Current_CT[3];              
	unsigned char Voltage_PT[3];              
	unsigned char Meter_ID[6];                
	unsigned char Client_ID[6];               
	unsigned char Card_Kind;                  
	};
















 
 
 
 
struct Password_Inf_File
	{
	unsigned char Start_Byte;
	unsigned char Order_Byte;
	unsigned int 	File_Length;
	unsigned char Password_Info[4];           
	unsigned char Add_CS;
	unsigned char End_Byte;
	};
 
struct Password_File
	{
	unsigned char Start_Byte;
	unsigned char Order_Byte;
	unsigned int 	File_Length;
	unsigned char New_Password[4][32];
	unsigned char Add_CS;
	unsigned char End_Byte;
	};	
 
 
 
struct Set_Para_Inf_File
	{
	unsigned char User_Kind;                  
	unsigned char Para_UpData_Flag;           
	unsigned long Para_Card_Version;       
	unsigned char Triff_Switch_Time[5];       
	unsigned char No_Use1;                       
	};







 
 
 
 
 
 
 
struct Init_Para_Inf_File
	{
	unsigned char User_Kind;                  
	unsigned char Para_UpData_Flag;           
	unsigned long Para_Card_Version;       
	unsigned char Triff_Switch_Time[5];       
	unsigned char No_Use1;                       
	unsigned long Remain_Money_Alarm1_Limit;  
	unsigned long Remain_Money_Alarm2_Limit;  
	unsigned char Current_CT[3];              
	unsigned char Voltage_PT[3];              
	};











 
 
 
 
struct MeterID_Para_Inf_File
	{
	unsigned char Start_Byte;
	unsigned char Order_Byte;
	unsigned int 	File_Length;
	unsigned char Start_Meter_ID[6];
	unsigned char End_Meter_ID[6];	
	unsigned char Add_CS;
	unsigned char End_Byte;
	};
 
struct MeterID_Return_Inf_File
	{
	unsigned char Start_Byte;
	unsigned char Order_Byte;
	unsigned int 	File_Length;
	unsigned char NO_Use[26];
	unsigned char Next_Meter_ID[6];
	unsigned char Add_CS;
	unsigned char End_Byte;
	};



 
 
 
 
struct Add_Money_Para_Inf_File
	{
	unsigned char Start_Byte;
	unsigned char Order_Byte;
	unsigned int  File_Length;
	unsigned long Buy_Money;
	unsigned long Buy_Money_Count;	
	unsigned char Add_CS;
	unsigned char End_Byte;
	};



 
 
 
 
 
#line 22 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/ICcard.h"
 








































































































































































































































































































































































































































































































#line 23 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_Keymain.h"
 
 
 
 
 
 






typedef void (* TOn_Key_Click)(char keyval,long time);
typedef void (* TOn_Set_key_Click)(void);




 
 
extern void Key_Initialize(TOn_Key_Click On_Click_Fun);
extern void Set_key_Event( TOn_Set_key_Click On_Set_key_fun);
extern char Key_Main(void);
extern void key_interrupts(void);
 
extern char Drop_Key_Main(void);
extern void Drop_Key_Initialize(TOn_Key_Click On_Click_Fun,unsigned char kind);
extern void Exit_Normal_Show(void);
extern void Enter_Dorp_Show(void);
extern void Set_show_code_list(int id);

extern void	Goto_Wait_Exit_Wait(void);
extern void	Prepare_for_Wait(void);
extern void	Prepare_for_Wakeup(unsigned char);
extern void IR_Set_show_code(long code);
extern void show_clear_char(void);

extern void IR_interrupts(void);
extern void IR_Timer(void);
extern void Init_IR_Ctrl(void);
#pragma INTERRUPT key_interrupts();
#pragma INTERRUPT IR_interrupts();
#pragma INTERRUPT IR_Timer();

 
 
 
struct SHOW_CODE_TABLE1 {
	          unsigned long default_code;	          
	          unsigned char flag;                            
            };
struct SHOW_CODE_TABLE2 {
              unsigned long user_code;
	          unsigned char user_code_len;
            };
 
struct FAIL_ABNORMAL_BIT_DEF
{
	char CtrCircleErr:1; 
	char EsamErr:1;
	char EepromInitErr:1;
	char ClockBatErr:1;
	char ProgramErr:1;
	char MemoryErr:1;
	char :1;
	char ClockErr:1;
};
union FAIL_ABNORMALl{
	struct FAIL_ABNORMAL_BIT_DEF bit;
	unsigned char byte;
};

struct EVENT_ABNORMAL_BIT_DEF{
	char :1;
	char OverLoad:1;
	char CurrentImbalance:1;
	char OverVoltage:1;
	char OverPowerFactor:1;
	char OverActiveDemandAlarm:1;
	char EnergyDirectChange:1;
	char :1;
};
union EVENT_ABNORMAL{
	struct EVENT_ABNORMAL_BIT_DEF bit;
	unsigned char byte;
};
 
extern struct SHOW_CODE_TABLE1 User_Defind_Table1;
extern struct SHOW_CODE_TABLE2 User_Defind_Table2;
extern union byte_def key_flag;

extern unsigned char pdmode1;
extern unsigned long show_code,user_defind_code;
extern int cyc_show_num;
extern unsigned char user_defind_code_len;
extern unsigned long cyc_show_time;

extern unsigned long Full_show_time;
extern unsigned long Full_show_time_Limit;

extern struct SHOW_CODE_TABLE1 User_Choose_Table;	
extern unsigned char  LCD_Check_State;
extern unsigned char  LCD_Check_Second;	
extern unsigned long HZ_show_start_time;
extern unsigned char light_AlarmSwitchLED;
extern unsigned char light_backled_flag;

extern unsigned long pd_now_show_code;
extern unsigned char pd_time_show_cnt;

extern void show_build_char(void); 
 extern void show_rebuild_char(void);
 extern void LCDREAD(unsigned char flag,unsigned char num); 

 extern void  SHOW_ABC_SEG(unsigned char SEGFLAG ); 
 
 
 
 
 
 
 
extern union FAIL_ABNORMALl Fail_abnormal;
extern union EVENT_ABNORMAL Event_abnormal;
extern union FAIL_ABNORMALl failabnormalshow;
extern union EVENT_ABNORMAL eventabnormalshow;
extern union BYTE_BIT   Abnormal_Show_Mode;
extern char Check_Show_Flash_Data(unsigned char ,unsigned char ,unsigned char ,unsigned char *);
extern char Check_Event_Show_Data(unsigned char );
extern char Poweron_Event_Show_Data(void);

extern void Pd_Refresh_TimeShow_PerSec(void);

extern void OutCardInCycshow(void);


#line 24 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Flash_API_M16C.h"
 

















 



 
extern unsigned char FlashErase( unsigned char block );
extern unsigned char FlashWrite( unsigned char far *  flash_addr,
                          unsigned char far *		     buffer_addr,
                          unsigned int    bytes);
extern unsigned char FlashRead ( unsigned char far * flash_addr,
						  unsigned char far *		  buffer_addr,
						  unsigned int bytes);

                          
 














 













 
 






 







 
 
 
 
 
 
 
 


 












 
















 


 
 
 
 
 
 
 
 
 
 
 

 
 
 
































 
unsigned char FlashEraseEW1 ( unsigned char block );

unsigned char FlashWriteEW1 (	unsigned char far * flash_addr,
							unsigned char far *		    buffer_addr,
							unsigned int   bytes);
							
unsigned char FlashReadEW1  (	unsigned char far * flash_addr,
							unsigned char far *		  buffer_addr,
							unsigned int bytes);

 
 
 





























 
 
 























 
 
 


 


 









 



 






#line 25 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"


#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Multi.h"



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

#line 27 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Far_pay.c"


 
 














 
 
union SECURITY_AUTH_ERR_INFORMATION Far_Security_Auth_Err_Info;	 
struct Far_Identity_Authentication_Define Far_Identity_Auth_Data;			 
unsigned int Esam_Far_Identity_Auth_Valid_Time;					 
unsigned char Far_Identity_Auth_Ok_Flag;						 		 
unsigned long Far_Identity_Auth_Ok_Time;						 		 
unsigned char *far_data_p;											 
unsigned char esam_number[8];										 

unsigned char Far_Spec_Order_Flag;
unsigned long FarOpenTime=0;
unsigned long FarCloseTime=0;
unsigned long Remain_Money_Bag_Do_Time;

unsigned char Far_InfraredFlag = 0;            
unsigned long Far_Infrared_Auth_Ok_Time = 0;	 	

unsigned int  R_ID_Remain_Time=0; 				 
unsigned int  R_Infrared_Remain_Time=0; 	 

unsigned char Far_Read_Esam(unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char *);
 
unsigned char Far_Deal_Order_0x03(unsigned char *,unsigned char  );
unsigned char Far_Deal_Control(unsigned char *);
 
 
extern unsigned char Relay_Alarm_SWitch_Flag[2][2];

extern unsigned long    Clear_all_oper_code;
extern unsigned long    Clear_demand_oper_code;
extern unsigned char    buy_money_OK_flag;

extern unsigned char oprateCode[];

 unsigned char rand4[4];

 
 
void Far_Prepayment_Read_Write(unsigned char );				 
unsigned char Far_TransferData_New(union ID id,unsigned char *, unsigned int ,unsigned char formatdata,unsigned char ,unsigned char ,unsigned char );
unsigned char Far_Init_Esam(void);  
unsigned char Far_Esamcard_Internal_Auth(unsigned char *); 
unsigned char Far_Read_Esam(unsigned char ,unsigned char ,unsigned char ,
			unsigned char ,unsigned char ,unsigned char * );
unsigned char Far_Write_Esam(unsigned char ,unsigned char ,unsigned char ,
			unsigned char ,unsigned char ,unsigned char *,unsigned char  ); 
unsigned char Find_Do_Money_Bag(void);
unsigned char Find_T1_Para(unsigned char * );
void invalid_psw_upd_flag(void);
unsigned char write_psw_status_wd_to_esam(unsigned long psw);
unsigned char CheckCmdTime(unsigned char * Point);

 

 
 
extern void My_memcpyRev(unsigned char *,unsigned char *,unsigned char );
extern void tr_show_wait(int time);
 
 
void My_Memcpy_Dec_0x33(	unsigned char * To_Point, unsigned char * From_Point, 
								unsigned char Offset,unsigned char Length,unsigned char Max_Limit)
	{
	unsigned char i;
	for(i=0;i<Length;i++) 
		{
		*(To_Point+i)=*(From_Point+Offset)-0x33;
		Offset++;
		if(Offset>=Max_Limit) 
			Offset=0;	    
		}
	}

 
void record_esam_oprate_err(void)
{
	if (Show_flag.bit.Ing)	 
		return;

    if (Pre_Payment_Data.HangMeterNum < 0xff) {
	    Pre_Payment_Data.HangMeterNum++;
        Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			  ,(unsigned char *)&(Pre_Payment_Data.HangMeterNum),1,3,
                (unsigned char *)&(Pre_Payment_Data),sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
    }
	if (Pre_Payment_Data.HangMeterNum >= 200       ) {
		Far_Security_Auth_Err_Info.bit.HANG_ERR =1;
	}
}

 
 
 
unsigned char cmd_0x98_mode_decipher(unsigned char uartx, unsigned char cmd_code)
{
	unsigned char ok, i;
	struct FindCommand_Result *pc;
    struct cmd_plaintext *cmd;
    unsigned char expire;
    unsigned char file;
    unsigned char plain_len;

    if ((uartx == 1             ) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0;
    }

    if (Far_Identity_Auth_Ok_Flag != 0xFF) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0;
    }
    
    if(Pre_Payment_Data.HangMeterNum >= 200       ) {
		Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
		return 0;
	}

	Meter_States.ErrOfInformation.byte=0;
	
	pc = CurrPC;
	far_data_p = CommBP;
	

     
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p, pc->addr, pc->len, 200				  );
     
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
	My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);

	press_card_state = 0xFFFF             ;	 

	ok = 0;
	Cpucard_Serial_Init();	 
	if(Far_Init_Esam() != 0x00 ) {
        Meter_States.ErrOfInformation.bit.Invalid_Data = 1;
        return 0;
	}

    if (cmd_code == 0x1A) {
         
        file = 0x94;
    } else {
         
        file = 0x97;
    }
    cmd = (struct cmd_plaintext *)(WriteDateBuff + 8);
	if( pc->len == 28 ) { 
		Reverse_data(WriteDateBuff+8,20);
		if( Write(0x04,0xD6,file,0x00,0x14,WriteDateBuff+8) == 0x00 ) { 
            if (cmd_code == 0x1B) {
                plain_len = 12;
            } else {
                plain_len = 8;
            }
            if( Read(0,0xb0       ,file,0,plain_len) == 0x00 ) {
                if (cmd_code == 0x1B) { 
                    My_memcpyRev(far_data_p + pc->addr + 8,receive_send_buffer + 2, 10);
                    for (i = 0; i < 10; i++) {
                        far_data_p[pc->addr + 8 + i] += 0x33;
                    }
                    pc->len = 18; 
                }
				My_Memcpy(WriteDateBuff+8,receive_send_buffer, plain_len);
                cmd = (struct cmd_plaintext *)(WriteDateBuff + 8);
				ok = 0xff;
            }
        } else {
			 
             
			 
        }
    }
	cpucard_serial_release();
    if (ok) {
         
        expire = CheckCmdTime(WriteDateBuff + 8);
        if ((cmd->code != cmd_code) || expire) {
            if (expire) {
                Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
            } else {
                Meter_States.ErrOfInformation.bit.Invalid_Data = 1;
            }
            return 0;
        }
        return 1;
    }
    Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
    return 0;
}

 
void Far_Prepayment_Read_Write(unsigned char uartx)
{  
	unsigned char mode;
	struct FindCommand_Result *pc;
	unsigned char i_ret;
	
	AppointTrasfPortBuff(uartx);
	pc = CurrPC;
	far_data_p = CommBP;

 
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p,pc->addr,pc->len,200				  );
 
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
    My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);
    
 
	My_Memcpy((unsigned char*)&(pc->id.d), WriteDateBuff, 4);

  
	pc->idt.l=pc->id.l;  
	
	press_card_state = 0xFFFF             ;	 
	Far_Security_Auth_Err_Info.intd = 0;		 
    Far_Security_Auth_Err_Info.bit.OTHER_ERR = 1;
    if (IntoPowerDownFlag) {
        if ((pc->idt.l == 0x078003ff) || (pc->idt.l == 0x070003ff)) {
            pc->ct=0xc3; 
            Co.c.len=2;
            pc->lena=2;
            memcpy((unsigned char *)&far_data_p[10], (unsigned char *)&Far_Security_Auth_Err_Info.intd, 2);
        } else {
            pc->ct = 0;
        }
        return;
    }

     mode = 0;
     
    if ((pc->idt.l == 0x078003ff) || (pc->idt.l == 0x070003ff)) {
        if (uartx == 1             ) { 
            i_ret = Far_TransferData_New(pc->idt,WriteDateBuff,0,0xfe ,mode,pc->len,uartx);
        } else {
            i_ret = 0xFF ;
        }
    } else if( ( Far_Identity_Auth_Ok_Flag==0xFF ) || ( pc->idt.l == 0x70000FF )) {
        if ((uartx == 1             ) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)) {
            Far_Security_Auth_Err_Info.bit.IDENTITY_AUTH_ERR = 1;
            i_ret = 0xFF ;
        } else {
             
            if( ( Far_Identity_Auth_Ok_Flag == 0xFF ) && ( pc->idt.l == 0x70000FF ) ) {
                Event_Power_Net_Flag.bit.ProgrammeEvent = 0;
            }
             
			 
			 
			 
            i_ret=Far_TransferData_New(pc->idt,WriteDateBuff,0,0xfe ,mode,pc->len,uartx);
        }
    } else {
		i_ret=0xFF ;
		Far_Security_Auth_Err_Info.bit.IDENTITY_AUTH_ERR = 1;
		 
		 
		 
    }
		
	if(i_ret==0x00 ) 	 
		{
		pc->ct=0x83; 										
		pc->lena=Co.c.len;
		return;
		}
	

	pc->ct=0xc3; 
	Co.c.len=2;
	pc->lena=2;
	if(( Far_Security_Auth_Err_Info.intd & 0xFFFE ) != 0 )
		Far_Security_Auth_Err_Info.intd &= 0xFFFE;
	memcpy((unsigned char *)&far_data_p[10], (unsigned char *)&Far_Security_Auth_Err_Info.intd, 2);
	return;
}

 
void Far_Control(unsigned char uartx)
{
	unsigned char mode, ok;
	struct FindCommand_Result *pc;
	unsigned char i_ret;
	 

	AppointTrasfPortBuff(uartx);
	pc = CurrPC;
	far_data_p = CommBP;

 
	My_Memcpy_Dec_0x33(WriteDateBuff, far_data_p,pc->addr,pc->len,200				  );
 
	My_Memcpy((unsigned char*)&(pc->Programer_code), WriteDateBuff+4, 4);
	My_Memcpy((unsigned char*)&(Pre_Payment_Data.oprateCode[0]), WriteDateBuff+4, 4);
 
	 

	press_card_state = 0xFFFF             ;	 
	Far_Security_Auth_Err_Info.intd=0;		 

	Pay_For_Users_Flag6.bit.FAY_CTL_RES =0;
	Fay_Ctl_Res_Ok.intd=0;
	Fay_Ctl_Res_Err.intd=0;
	ok = 0;
	 
	if (WriteDateBuff[0] == 0x98)
		{
		if (WriteDateBuff[3]==1)	 
			Pay_For_Users_Flag6.bit.FAY_CTL_RES =1;

		if ((!Meter_Parameter.parameter1.MeterTypeMode.bit.b5 ) || ((uartx == 1             ) && (Far_InfraredFlag == 0) && (Meter_Parameter.parameter1.LocalFunctionMode.bit.b6 == 0)))
			 Fay_Ctl_Res_Err.bit.PassErr=1;
		else if (Far_Identity_Auth_Ok_Flag!=0xFF)
			Fay_Ctl_Res_Err.bit.NoIden=1;
		else if (Pre_Payment_Data.HangMeterNum >= 200       )
			Fay_Ctl_Res_Err.bit.Hang=1;
		else
			{
			Cpucard_Serial_Init();	 
			if(Far_Init_Esam()==0x00 )
				{
				if( pc->len == 28 )
					{
					Reverse_data(WriteDateBuff+8,20);
					if( Write(0x04,0xD6,0x88,0x00,0x14,WriteDateBuff+8)==0x00 )
						{
						if( Read(0,0xb0       ,0x88,0,8) == 0x00 )
							{
							My_Memcpy(WriteDateBuff+8,receive_send_buffer, 8);
							ok = 0xff;
							}
						}
					else
						{
							if (R_CARD_ERROR_INFO==10				  )	 
								Fay_Ctl_Res_Err.bit.MacErr=1;
							else
								Fay_Ctl_Res_Err.bit.PassErr=1;		 
							Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR =1;
						}
					}
				}
			cpucard_serial_release();
			if( ok !=0 )
				ok = Far_Deal_Control(WriteDateBuff+8);
			}
		}
	 
	 
	else if (Meter_Parameter.parameter1.MeterTypeMode.bit.b5 &&((WriteDateBuff[0]==0x02)||(WriteDateBuff[0]==0x04)))	 
	{
		 
 
		ok = 2;

		 
		 
		 
		
		if (!O1ther_Meter_Parameter.WorkRoomState)
			{
			ok=CheckPasswordRight((unsigned char *)&WriteDateBuff[0]);
			 
			if (ok<=9)	 
				{
				if (!(Other_Data.PasswordErr[ok].flag))
					{
					 
					Clear_PasswordErr(1,ok);		    
					ok=0xff;
					}
				else		 
					{
					ok=0;
					}
				}
			else 	 
				{
				if(ok!=0xff)	 
					CheckPasswoerErr(ok&0x7f);
				ok=0;
				Fay_Ctl_Res_Err.bit.PassErr=1;
				}
			}
 
		if( ok !=0 )
			{
			Reverse_data(WriteDateBuff+10, 6);
			if (O1ther_Meter_Parameter.WorkRoomState || WriteDateBuff[8]==0x1B || WriteDateBuff[8]==0x1C)	 
				{
				ok = Far_Deal_Control(WriteDateBuff+8 );
				}
			else
				{
				Fay_Ctl_Res_Err.bit.PassErr=1;
				ok=0;
				}
			}
		}
		else
		{
		Fay_Ctl_Res_Err.bit.PassErr=1;
		}

	if( ok != 0 )
		{
		pc->ct=0x9C;
		Co.c.len=0;
		pc->lena=0;
		if (Pay_For_Users_Flag6.bit.FAY_CTL_RES )
		{
			far_data_p[10]=Fay_Ctl_Res_Ok.intd&0xFF;
			far_data_p[11]=Fay_Ctl_Res_Ok.intd>>8;
			Co.c.len+=2;
			pc->lena+=2;
		}
		}
	else
		{
		pc->ct=0xDC;
		if (Pay_For_Users_Flag6.bit.FAY_CTL_RES )
			{
			if (Fay_Ctl_Res_Err.intd==0)
				Fay_Ctl_Res_Err.bit.PassErr=1;
			far_data_p[10]=Fay_Ctl_Res_Err.intd&0xFF;
			far_data_p[11]=Fay_Ctl_Res_Err.intd>>8;
			Co.c.len=2;
			pc->lena=2;			
			}
		else
			{
			Co.c.len=1;
			pc->lena=1;
			if(Meter_States.ErrOfInformation.byte==0)
				{
				if (Fay_Ctl_Res_Err.intd)
					Meter_States.ErrOfInformation.bit.Invalid_Password=1;
				else
					Meter_States.ErrOfInformation.bit.Invalid_Data=1;
				}
			far_data_p[10]=Meter_States.ErrOfInformation.byte;
			}
		}
	
	return ;
}

 
unsigned char Far_TransferData_New (union ID id,unsigned char *P_in, unsigned int L,
                         unsigned char formatdata,unsigned char mode,unsigned char data_len,unsigned char uartx)
{
	unsigned int ret;

	ret = 0x00 ;
	Cpucard_Serial_Init();	 
     
	if( (id.l == 0x70000FF) || ((id.l == 0x078003ff) && (Far_Identity_Auth_Ok_Flag == 0)))
		{
		if( Esamcard_Atr() != 0x00 )
			{
			ret = 0xFF ;
			}
		else
			memcpy(esam_number,receive_send_buffer+5,8);
		}

	if( ret==0x00 )
		{
		Far_Init_Esam();
		if (Pay_For_Users_Flag6.bit.COMM_ALL_AA 
			&& (id.l!=0x070000FF) 	 
			&& (id.l!=0x070002FF)	 
			&& (id.l!=0x078001FF) 	 
			&& (id.l!=0x078102FF) 	 
			&& (id.l!=0x078003FF) 	 
			&& (id.l!=0x070003FF)	 
			&& (id.l!=0x078002FF))	 
			ret = 0xFF ;
		else
			ret =  Far_Deal_Order_0x03(P_in,data_len) ;
		}
	cpucard_serial_release();	 
	return ret;
}

 
unsigned char Far_Init_Esam(void)
{
	unsigned char ret;

	CPU_ESAM_CARD_Control(2 );
 
 	



	return 0x00 ;
}

void get_meter_para_from_esam(void)
{
    unsigned char ret;
    unsigned char BcdMeterID[6];
    unsigned long psw;

    ret = 0x00 ;

	if (IntoPowerDownFlag) {
		return;
	}
    CPU_ESAM_CARD_Control(2 );
    Cpucard_Serial_Init();
    ret = Esamcard_Atr();
    if (ret != 0x00 ) {
        Cpu_Card_IO_Reset();
        return;
    }
	if( Select_File(0,0x3F,00) != 0x00 ) {
        Cpu_Card_IO_Reset();
	    return;
	}
    ret = Get_File_Data(2 ,0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							  ,6, BcdMeterID);
    if (ret == 0x00 ) {
        if (My_Memcmp(&Meter_Parameter.parameter2.BcdMeterID[0] ,BcdMeterID, 6) != 0) {
            My_Memcpy(&Meter_Parameter.parameter2.BcdMeterID[0] ,BcdMeterID, 6);
            Write_Read_FM24C256 (0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER) + sizeof(struct PARAMETER1)    +32    +6    +6    +6    +4    +4    +10    +10 +16+32   +32+32                            +1  +1   +1  +2             ,(unsigned char*)&Meter_Parameter.parameter2.BcdMeterID[0],6,0,0);
        	Set_Meter_para_Deal(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER) + sizeof(struct PARAMETER1)    +32    +6    +6    +6    +4    +4    +10    +10 +16+32   +32+32                            +1  +1   +1  +2             );
        }
    }
    






















    ret = Get_File_Data(2 ,0x05 ,0,4, (unsigned char *)&psw); 
    if (ret != 0x00 ) {
        Cpu_Card_IO_Reset();
        return;
    }









    Reverse_data((unsigned char *)&psw, 4);
    if (Pre_Payment_Para.Far_Key_StatusByte != psw) {
        Pre_Payment_Para.Far_Key_StatusByte = psw;
        Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Far_Key_StatusByte),4,3,
                (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
    }
    Cpu_Card_IO_Reset();
}

unsigned char write_psw_status_wd_to_esam(unsigned long psw)
{
    unsigned char ret;
    unsigned char buf[4];

    My_memcpyRev(buf, (unsigned char *)&psw, 4);
    ret = Write(0,0xd6      ,0x80+0x05 ,0,4, buf);
    if (ret == 0xFF ) {
         
         
    }
    return ret;
}




 
unsigned char Far_Esamcard_Internal_Auth(unsigned char *Point)   
{
    unsigned long long factor;
    unsigned char meter_id[8];
    unsigned char ok;	

    factor = *(unsigned long long *)(Point+16); 
    Reverse_data(Point+16, 8);                  
    meter_id[0] = 0;
    meter_id[1] = 0;
    My_Memcpy(&meter_id[2], (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
    My_Memcpy((unsigned char *)&Far_Identity_Auth_Data.Instruction.cryptograph1[0], Point, sizeof(struct Authentication_Instruction));
     
    if (My_Memcmp(Point + 18, meter_id + 2, 6) != 0) {
        if (O1ther_Meter_Parameter.WorkRoomState) {
            if (factor == 0x0000000000000001ULL || factor == 0x0ULL) {
                 
                My_Memcpy(meter_id, Point + 16, 8);
            }
        } else {
            return 0xFF ;
        }
    }
    
	My_memcpyRev(Card_WR_Buff+110, Point, 8);            
	My_memcpyRev(Card_WR_Buff+100, Point+8, 8);          
	 

	CPU_ESAM_CARD_Control(2 );       
	ok = Internal_Auth(0x80,0xfa,0,3,8, meter_id);  
	if( ok != 0x00 )
		return 0xFF ;

	ok = Internal_Auth(0x80,0xfa,0,0,8,Card_WR_Buff+100);  
	if( ok != 0x00 )
		return 0xFF ;

	if(My_Memcmp(Card_WR_Buff+110,receive_send_buffer,8))  
		{
		 
		return 0xFF ;      
		}
	return 0x00 ;     
}


 
unsigned char Far_Read_Esam(unsigned char cla,unsigned char ins,unsigned char t_p1,
              unsigned char t_p2,unsigned char lc,unsigned char *address)
{
	unsigned char Order_Head[4];

    
    My_memcpyRev((unsigned char *)&Card_WR_Buff, (unsigned char *)&Far_Identity_Auth_Data.Instruction.random_number1[4], 4);
	 
	Card_WR_Buff[4]=0x04;
	Card_WR_Buff[5]=0xd6;
	Card_WR_Buff[6]=0x86;
	if( ins == 0xb2                        ) {
		Card_WR_Buff[7]=0;
        Card_WR_Buff[8] = lc+12;	 
    } else {
		Card_WR_Buff[7]=t_p2;
        Card_WR_Buff[8]=lc+12;	 
    }
	
	 
    Card_WR_Buff[9] = 0x00;
    Card_WR_Buff[10] = 0x00;
    My_Memcpy(Card_WR_Buff + 11, (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
    Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,0x11,Card_WR_Buff,0,CommunicationPortMode,lc+4)!= 0x00 ) {
		Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR =1;
	    return 0xFF ;
    }

	return 0x00 ;
}


 
 
unsigned char Far_Write_Esam(unsigned char cla,unsigned char ins,unsigned char t_p1,
			unsigned char t_p2,unsigned char lc,unsigned char *address,unsigned char Flag )
{
	unsigned char i;   
	unsigned char Order_Head[4];

	CPU_ESAM_CARD_Control(2 );

    switch (Flag) {
    case 0: 
        My_memcpyRev((unsigned char *)&Card_WR_Buff[0], address,lc);
	    My_memcpyRev((unsigned char *)&Card_WR_Buff[lc], address+lc,4); 
        break;
    case 1:
        My_memcpyRev((unsigned char *)&Card_WR_Buff[0], address,lc+4);
        break;
    case 2: 
        break;
    default:
        return 0xFF ;
    }

	Order_Head[0] = cla;
	Order_Head[1] = ins;
	Order_Head[2] = t_p1;
	Order_Head[3] = t_p2;
	if( CPU_Card_Driver((const unsigned char *)Order_Head,lc+4,Card_WR_Buff,0,CommunicationPortMode,0)!= 0x00 )
		{
		Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR =1;
		 
         
		return 0xFF ;
		}
    
	return 0x00 ;
}


struct Far_645_Frame_0x03
	{
	unsigned char Data_ID[4];
 
	unsigned char Do_man[4];
	};


 
 
 
 
 
 
struct Far_Read_078001FF_Format
	{
	unsigned int	Data_Length;
	unsigned int	Data_Start_Addr;
	unsigned int	File;
	unsigned int	Name;
	};


 
unsigned char Far_Deal_078001FF(unsigned char *Data_Point )
	{
	struct Far_Read_078001FF_Format	* Far_Read_078001FF_Format;
	unsigned char * Point;
	unsigned char Offset;

 
	Far_Read_078001FF_Format = (struct Far_Read_078001FF_Format	*)Data_Point;

 
 
    if( Find_Do_Money_Bag() ) {
        Esam_Remain_Money_Dec();
        Updata_Esam_Return_File(0x11,0,0);
    }
	if( Far_Read_078001FF_Format->File == 0x01 )
		{
 
 
 
 
		if(Far_Read_Esam(0x04,0xb2                        ,0x01,0x0C,0x04,Data_Point)!=0x00 )
			return 0xFF ;
		My_Memcpy(far_data_p+14, Data_Point, sizeof( struct Far_Read_078001FF_Format ) );
		My_memcpyRev( far_data_p+22,receive_send_buffer,4 );
		My_memcpyRev( far_data_p+26,receive_send_buffer+4,4 );
		

		if(Far_Read_Esam(0x04,0xb2                        ,0x03,0x0C,0x04,Data_Point)!=0x00 )
			return 0xFF ;	
		My_memcpyRev( far_data_p+30,receive_send_buffer,4 );
		My_memcpyRev( far_data_p+34,receive_send_buffer+4,4 );
		Co.c.len = 24;
		
		}
	else
		{
 


		if(Far_Read_Esam(0x04,0xb0       ,0x80+(unsigned char)(Far_Read_078001FF_Format->File),
											 (unsigned char)(Far_Read_078001FF_Format->Data_Start_Addr),
											 (unsigned char)(Far_Read_078001FF_Format->Data_Length), 
											 Data_Point)!=0x00 )
			return 0xFF ;
 
		My_Memcpy(far_data_p+14, Data_Point, sizeof( struct Far_Read_078001FF_Format ) );
		My_memcpyRev( far_data_p+22,receive_send_buffer,((unsigned char)(Far_Read_078001FF_Format->Data_Length)) );
		My_memcpyRev( far_data_p+22+((unsigned char)(Far_Read_078001FF_Format->Data_Length)),receive_send_buffer+((unsigned char)(Far_Read_078001FF_Format->Data_Length)), 4);
 

		Co.c.len = ((unsigned char)(Far_Read_078001FF_Format->Data_Length))+12;
		}
	
 
 
 
	return 0x00 ;
	}


 
 
 
 
 
 
struct Far_Read_07810201_Format
	{
	unsigned long	Remain_Money;
	unsigned char	Remain_Money_Mac[4];
	unsigned long	Buy_Count;
	unsigned char	Buy_Count_MAC[4];
	unsigned char Client_ID[6];
	unsigned long psw_stat_word;
	};

 
unsigned char Far_Deal_07810201(unsigned char *Data_Point )
	{
	struct Far_Read_07810201_Format	*Far_Read_07810201_Format;

	Far_Read_07810201_Format = (struct Far_Read_07810201_Format *)(far_data_p+14);

	if( Find_Do_Money_Bag() ) {
		Esam_Remain_Money_Dec();
        Updata_Esam_Return_File(0x11,0,0);
	}

	if(Far_Read_Esam(0x04,0xb2                        ,1,0x0c,4,0)!=0x00 )
		return 0xFF ;
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Remain_Money), receive_send_buffer,4);
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Remain_Money_Mac[0]), receive_send_buffer+4,4);
	
	if(Far_Read_Esam(0x04,0xb2                        ,3,0x0c,4,0)!=0x00 )
		return 0xFF ;
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Buy_Count), receive_send_buffer,4);
	My_memcpyRev((unsigned char *)&(Far_Read_07810201_Format->Buy_Count_MAC[0]), receive_send_buffer+4,4);

     
    if( Get_File_Data(2 ,0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  ,6,(unsigned char *)&(Far_Read_07810201_Format->Client_ID[0])) != 0x00 )
		return 0xFF ;
	 
	 

	Reverse_data((unsigned char *)&(Far_Read_07810201_Format->Client_ID[0]),6);
    if( Get_File_Data(2 ,0x05 ,0,4, (unsigned char *)&Far_Read_07810201_Format->psw_stat_word) != 0x00 ) {
        return 0xFF ;
    }
    Reverse_data((unsigned char *)&Far_Read_07810201_Format->psw_stat_word, 4);
	 
	
	Co.c.len = sizeof( struct Far_Read_07810201_Format ) ;
	return 0x00 ;
	}
 
 
 
 
 
 
unsigned char Far_Deal_078102FF(unsigned char * Data_Point )
	{
	return Far_Deal_07810201(Data_Point);
	}


 
unsigned char read_esam_serial_num(unsigned char *esam_number)
{
    if (Read(0,0xb0       ,0x99,1,8) == 0x00 ) {
        memcpy(esam_number,receive_send_buffer,8);
        return 0x00 ;
    } else {
        return 0xFF ;
    }
}

 
 
 
 
 
 
struct Far_Read_070000FF_Format_In
	{
	unsigned char cryptograph1[8];								 
	unsigned char	random_number1[8];							 
	unsigned char disperse_gene[8];								 
	};

 
struct Far_Read_070000FF_Format_Out
	{
	unsigned char	random_number2[4];							 
	unsigned char	esam_serial_number[8];						 	
	};

 
unsigned char Far_Deal_070000FF(unsigned char * Data_Point )
{
	struct Far_Read_070000FF_Format_In	* Far_Read_070000FF_Format_In;
	struct Far_Read_070000FF_Format_Out	Far_Read_070000FF_Format_Out;

	Far_Read_070000FF_Format_In = (struct Far_Read_070000FF_Format_In *)Data_Point;

 
 
 
 
 
 
	
 
 
 
 
	
	if(Far_Esamcard_Internal_Auth(Data_Point)==0x00 ) {
		if( Read(0,0x84                    ,0,0,4) != 0x00 ) {
			return 0xFF ;
        }
		My_memcpyRev(far_data_p+14,receive_send_buffer,4);       
        My_Memcpy(rand4,receive_send_buffer,4);
        
        if (read_esam_serial_num(esam_number) != 0x00 ) {
			return 0xFF ;
        }
		My_memcpyRev(far_data_p+18,esam_number,8);      
         
		

 
		Far_Identity_Auth_Ok_Flag=0xFF;	
		Far_Identity_Auth_Ok_Time=GetNowTime();
		 
		 
		 
		 
		Esam_Far_Identity_Auth_Valid_Time=Pre_Payment_Para.ID_Ins_Time;

		if(Esam_Far_Identity_Auth_Valid_Time==0)
			Esam_Far_Identity_Auth_Valid_Time=5;

        R_ID_Remain_Time = Esam_Far_Identity_Auth_Valid_Time;

         
		
		Co.c.len = sizeof( struct Far_Read_070000FF_Format_Out ) ;
		return 0x00 ;
    }
    
	Far_Security_Auth_Err_Info.bit.IDENTITY_AUTH_ERR = 1;
	 
     
     
	return 0xFF ;
}


 
 
 
 
 
struct Far_Deal_070001FF_format
	{
	unsigned int Identity_Limit;
	unsigned char Identity_Limit_Mac[4];
	};

 
unsigned char Far_Deal_070001FF(unsigned char * Data_Point )
	{
	struct Far_Deal_070001FF_format  *Far_Deal_070001FF_format;

	Far_Deal_070001FF_format = (struct Far_Deal_070001FF_format  *)Data_Point;
	
 
 

    if(Pre_Payment_Data.HangMeterNum >= 200       ) {
		Far_Security_Auth_Err_Info.bit.HANG_ERR = 1;
		return 0xFF ;
	}

	if( Far_Deal_070001FF_format->Identity_Limit == 0 ) {
		return 0xFF ;
	}

	if( Far_Write_Esam(0x04,0xd6      ,0x80+0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								 +6							 +1							  ,0x02,Data_Point,0)!=0x00 )
		{
		return 0xFF ;
		}
 
	if(Far_Read_Esam(04,0xb0       ,0x80+0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								 +6							 +1							  , 2, 0)!=0x00 )
		return 0xFF ;
    
	Far_Identity_Auth_Ok_Time=GetNowTime();
	lxrBcd_Hex(2,(unsigned char *) &receive_send_buffer[0]);
	My_memcpyRev((unsigned char *)&Esam_Far_Identity_Auth_Valid_Time, (unsigned char *)&receive_send_buffer[0], 2);
	if(Esam_Far_Identity_Auth_Valid_Time==0)
		Esam_Far_Identity_Auth_Valid_Time=5;

	Pre_Payment_Para.ID_Ins_Time=Esam_Far_Identity_Auth_Valid_Time;
	Pay_EE_W(((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1+1+1+1+4+4+2 +1+4+1+1+8+2+2+2+2+4				 +1)+1)	  ,(unsigned char *)&(Pre_Payment_Para.ID_Ins_Time),2,3,
			   (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
	
	Co.c.len = 0;
	
	return 0x00 ;
	}


 
 
 
 
 
 
struct Far_Deal_07000201_format
	{
	unsigned char Client_ID[6];
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned long psw_stat_word;
	};

unsigned char Far_Deal_07000201(unsigned char * Data_Point )
	{
	struct Far_Deal_07000201_format * Far_Deal_07000201_format;
	Far_Deal_07000201_format = (struct Far_Deal_07000201_format *)(far_data_p+14);

	if( Find_Do_Money_Bag() )
		Esam_Remain_Money_Dec();

	if(Far_Read_Esam(0x04,0xb2                        ,1,0x0c,4,0)!=0x00 )
		return 0xFF ;
	My_memcpyRev((unsigned char *)&(Far_Deal_07000201_format->Remain_Money), receive_send_buffer,4);
	
	if(Far_Read_Esam(0x04,0xb2                        ,3,0x0c,4,0)!=0x00 )
		return 0xFF ;
	My_memcpyRev((unsigned char *)&(Far_Deal_07000201_format->Buy_Count), receive_send_buffer,4);

	if( Get_File_Data(2 ,0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  ,6,(unsigned char *)&(Far_Deal_07000201_format->Client_ID[0])) != 0x00 )
		return 0xFF ;

	Reverse_data((unsigned char *)&(Far_Deal_07000201_format->Client_ID[0]),6);
    
     
     
    if( Get_File_Data(2 ,0x05 ,0,4, (unsigned char *)&Far_Deal_07000201_format->psw_stat_word) != 0x00 ) {
        return 0xFF ;
    }
    Reverse_data((unsigned char *)&Far_Deal_07000201_format->psw_stat_word, 4);

    
	Far_Identity_Auth_Ok_Flag=0;
    R_ID_Remain_Time = 0;
	Esam_PowOff();
 
	
	Co.c.len = sizeof(struct Far_Deal_07000201_format) ;
	return 0x00 ;
	}
 
 
 
 
 
 
unsigned char Far_Deal_070002FF(unsigned char * Data_Point )
	{
	return Far_Deal_07000201(Data_Point);
	}




 
unsigned char Far_Deal_write_info_file(unsigned char * Data_Point)
{
    unsigned char file, ok;
    unsigned int off;
    unsigned char dat_len;

    file = Data_Point[0    ];
    off = Data_Point[1    ] | (Data_Point[1    + 1] << 8);
    dat_len = CurrPC->len - sizeof(struct Far_645_Frame_0x03) - 7; 

    if (Select_File(0, 0, file) != 0x00 ) {
        return 0xFF ;
    }
    Reverse_data(Data_Point + 3    , dat_len); 
    Reverse_data(Data_Point + 3    + dat_len, 4); 
     
    ok = Write(0x04, 0xd6      , (unsigned char)(off>>8), (unsigned char)off, dat_len + 4, Data_Point + 3    );
    if (ok != 0x00 ) {
        return 0xFF ;
    }
 




    Co.c.len = 0;
    return 0x00 ;
}































 
 

 
 
 
struct Far_Deal_070101FF_format
	{
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned char BagMoney_Mac[4];
	unsigned char Client_ID[6];
	unsigned char Client_ID_Mac[4];
	};

unsigned char Far_Deal_070101FF(unsigned char * Data_Point )
{
    unsigned char Client_ID[6];
	struct Far_Deal_070101FF_format * Far_Deal_070101FF_format;
	struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= 200       ) {
		Far_Security_Auth_Err_Info.bit.HANG_ERR = 1;
		return 0xFF ;
	}

	if(!Meter_Parameter.parameter1.MeterMode[1].bit.b5 )
		return 0xFF ;

    if (!O1ther_Meter_Parameter.WorkRoomState && is_test_psw_status()) {
        return 0xFF ;
    }

	Far_Deal_070101FF_format = (struct Far_Deal_070101FF_format *)Data_Point;

     
    if (Pre_Payment_Para.Pay_For_Users_Flag15.bit.FarOpen || Pre_Payment_Para.Pay_For_Users_Flag15.bit.LocalOpen ) {
        if(Far_Read_Esam(04,0xb0       ,0x80+0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  , 6, 0)!=0x00 ) {
            return 0xFF ;
        }
        My_memcpyRev(Client_ID, receive_send_buffer, 6);
        if (My_Memcmp(Far_Deal_070101FF_format->Client_ID, Client_ID, 6) != 0) {
            Far_Security_Auth_Err_Info.bit.CLIENT_ID_ERR = 1;
            return 0xFF ;
        }
    }

    if( Far_Deal_070101FF_format->Buy_Count != 0 &&  Far_Deal_070101FF_format->Buy_Count != 1) {
        Far_Security_Auth_Err_Info.bit.BUY_COUNT_ERR = 1;
        return 0xFF ;
    }

	 
	 
 
	if( Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data) != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
		return 0xFF ;
	}

    if (Far_Deal_070101FF_format->Buy_Count != Moneybag_Data.Buy_Count) {
        if( Far_Deal_070101FF_format->Buy_Count != (Moneybag_Data.Buy_Count + 1)) {
             
            Far_Security_Auth_Err_Info.bit.BUY_COUNT_ERR = 1;
             
            return 0xFF ;
        }
         
    	if( Judge_Remain_Money_Over( Far_Deal_070101FF_format->Remain_Money ) != 0x00 ) {
    		Far_Security_Auth_Err_Info.bit.BUY_MONEY_OVER_ERR =1;
             
    		return 0xFF ;
        }

        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Remain_Money), 4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Buy_Count), 4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->BagMoney_Mac[0]), 4);
         
        if( Write(0x84,0x32      ,0x01,0x0C,0x0C,((unsigned char *)&Far_Deal_070101FF_format->Remain_Money)) != 0x00 ) {
            return 0xFF ;
        }
        
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Remain_Money),4);
        Reverse_data((unsigned char *)&(Far_Deal_070101FF_format->Buy_Count),4);
        Meter_Money_And_Count_Updata(Far_Deal_070101FF_format->Remain_Money,Far_Deal_070101FF_format->Buy_Count );
		Pay_For_Users_Flag6.bit.Pay_Buy_Money_Flg =1;	 
    }
	
     
	if( Far_Write_Esam(0x04,0xd6      ,0x80+0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  ,0x06,(Far_Deal_070101FF_format->Client_ID),0)!=0x00 ) {
		return 0xFF ;
	}
	
	Pre_Payment_Para.Pay_For_Users_Flag15.bit.FarOpen = 1;
	Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
			(unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );

	
     
	My_memcpyRev(Pre_Payment_Para.UserID,Far_Deal_070101FF_format->Client_ID,6);
	Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6 ,(unsigned char *)&(Pre_Payment_Para.UserID[0]),6,3,
		          (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
	Pre_Payment_Para.Meter_Run_State = 0x03;
	Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF) ,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
		           (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
	Co.c.len = 0;
	return 0x00 ;
}

 
 
 

 
 
struct Far_Deal_070102FF_format
	{
	unsigned long	Remain_Money;
	unsigned long	Buy_Count;
	unsigned char BagMoney_Mac[4];
	unsigned char Client_ID[6];
	unsigned char Client_ID_Mac[4];
	};

unsigned char Far_Deal_070102FF(unsigned char * Data_Point )
	{
	struct Far_Deal_070102FF_format  * Far_Deal_070102FF_format;
	struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= 200       ) {
		Far_Security_Auth_Err_Info.bit.HANG_ERR = 1;
		return 0xFF ;
	}

	if(!Meter_Parameter.parameter1.MeterMode[1].bit.b5 )
		return 0xFF ;
    
    if (!O1ther_Meter_Parameter.WorkRoomState && is_test_psw_status()) {
        return 0xFF ;
    }

	if( Pre_Payment_Para.Meter_Run_State!=3 ) 	
		return 0xFF ;

	if( Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data) != 0x00 )
		return 0xFF ;

	Far_Deal_070102FF_format = (struct Far_Deal_070102FF_format  *)Data_Point;

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Client_ID[0]),6);

	if( My_Memcmp(Pre_Payment_Para.UserID,&Far_Deal_070102FF_format->Client_ID[0],6) != 0 )
		{
		Far_Security_Auth_Err_Info.bit.CLIENT_ID_ERR = 1;
		return 0xFF ;
		}

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Client_ID[0]),6);

	CPU_ESAM_CARD_Control(2 );
	if( Far_Write_Esam(0x04,0xd6      ,0x80+0x02 ,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  ,0x06,(Far_Deal_070102FF_format->Client_ID),0)!=0x00 )
		return 0xFF ;

	if( Far_Deal_070102FF_format->Buy_Count == Moneybag_Data.Buy_Count)
		{
		Far_Security_Auth_Err_Info.bit.REPEAT_INCREASE_ERR = 1;
		return 0xFF ;
		}
	
	if( Far_Deal_070102FF_format->Buy_Count != (Moneybag_Data.Buy_Count+1))
		{
		Far_Security_Auth_Err_Info.bit.BUY_COUNT_ERR = 1;
		return 0xFF ;
		}

	 
	if( Judge_Remain_Money_Over(Far_Deal_070102FF_format->Remain_Money) != 0x00 )
		{
		Far_Security_Auth_Err_Info.bit.BUY_MONEY_OVER_ERR =1;
		return 0xFF ;
		}

	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Remain_Money),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Buy_Count),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->BagMoney_Mac[0]),4);

	if( Write(0x84,0x32      ,0x01,0x0C,0x0C,((unsigned char *)&Far_Deal_070102FF_format->Remain_Money))!=0x00 )
		{
		return 0xFF ;
		}
     
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Remain_Money),4);
	Reverse_data((unsigned char *)&(Far_Deal_070102FF_format->Buy_Count),4);
	Meter_Money_And_Count_Updata(Far_Deal_070102FF_format->Remain_Money,Far_Deal_070102FF_format->Buy_Count );
	Pay_For_Users_Flag6.bit.Pay_Buy_Money_Flg =1;	 

	Co.c.len = 0;
	return 0x00 ;
	}

 
 
 
 
 
 
struct Far_Deal_070103FF_format
{
	unsigned long	Remain_Money;
	unsigned char   Remain_Mac1[4];
	unsigned long	Buy_Count;
	unsigned char   Buy_Count_Mac[4];
};

unsigned char Far_Deal_070103FF(unsigned char * Data_Point )
{
    struct Far_Deal_070103FF_format *data;
    struct Moneybag_Data Moneybag_Data;

    if(Pre_Payment_Data.HangMeterNum >= 200       ) {
		Far_Security_Auth_Err_Info.bit.HANG_ERR = 1;
		return 0xFF ;
	}
    
    if (Meter_Parameter.parameter1.MeterMode[1].bit.b5 == 0) { 
        return 0xFF ;
    }

    if ((!O1ther_Meter_Parameter.WorkRoomState)&&Pre_Payment_Para.Far_Key_StatusByte) { 
        return 0xFF ;
    }
    data = (struct Far_Deal_070103FF_format *)Data_Point;
    if (data->Buy_Count != 0) {
        Far_Security_Auth_Err_Info.bit.BUY_COUNT_ERR = 1;
        return 0xFF ;
    }

    Reverse_data((unsigned char *)&(data->Remain_Money),4);
    Reverse_data((unsigned char *)&(data->Remain_Mac1[0]),4);
    Reverse_data((unsigned char *)&(data->Buy_Count),4);
    Reverse_data((unsigned char *)&(data->Buy_Count_Mac[0]),4);
    CPU_ESAM_CARD_Control(2 );
    if( Write(0x04,0xDC,0x01,0x0C,0x08,((unsigned char *)&data->Remain_Money))!=0x00 )
    {
        return 0xFF ;
    }

    data->Buy_Count = 0;     
    if( Write(0x04,0xDC,0x03,0x0C,0x08,((unsigned char *)&data->Buy_Count))!=0x00 )
    {
        return 0xFF ;
    }
    Reverse_data((unsigned char *)&(data->Remain_Money),4);
    Reverse_data((unsigned char *)&(data->Buy_Count),4);        

     
     
     
    Clear_all_oper_code = CurrPC->Programer_code;
    memcpy(&oprateCode[0], (unsigned char *)&Clear_all_oper_code, 4);
	clearFlag=0;
	Pay_Money_Clear();
    Pay_Data_All_Clear();
    clearFlag = 3;	 

    This_Month_Data.Energy_Record.Pre_Save_Data .Remain_Money = 0;
    Meter_Money_And_Count_Updata(data->Remain_Money, data->Buy_Count );

    Set_which_Responsion_Flag(0, 0xff);

 
 
 
 
 
 
 
 
 

     
     
     
    Pre_Payment_Para.Meter_Run_State=0;
    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF) ,(unsigned char *)&(Pre_Payment_Para.Meter_Run_State),1,3,
               (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );

	 
	 
	 
	if( Pre_Payment_Para.Pay_For_Users_Flag13.bit.REMAIN_MONEY_OVER_CLUB )
	{
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.REMAIN_MONEY_OVER_CLUB = 0;
		Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag13),1,3,
		           (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
		Relay_Alarm_SWitch_Flag[0][0] &= 0xEF;
        Relay_Alarm_SWitch_Flag[1][0] &= 0xEF;
	}
	Remain_Money_Alarm_Judge();	 
	Card_Alarm_Switch();		 

    Co.c.len = 0;
	return 0x00 ;
}

 
 
 
 
 
 
struct Far_Deal_070301FF_format
{
	unsigned char sum;       
    unsigned char rsv;       
    unsigned char number;    
    unsigned char status;    
	unsigned char PassWord[32];
};


 
void clear_psw_upd_info(void)
{
    unsigned long upd_flg;
    unsigned char pwd_stat;
    unsigned char seq_num;

    upd_flg = 0;
    pwd_stat = 0;
    seq_num = 0;
    Write_Read_FM24C256 (((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + 32         * (36 + 4) ) , (unsigned char *)(&upd_flg), 4, 0, 0 );
     
    
}

 
 
unsigned char is_test_psw_status(void)
{
    unsigned long psw_msk;

    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);

    if ((Pre_Payment_Para.Far_Key_StatusByte & psw_msk) == psw_msk) {
        return 0;
    } else {
        return 1; 
    }
}

 
unsigned char check_collected_psw_info(void)
{
    unsigned char i;
    unsigned char ret;
    unsigned char status;
    struct Far_Deal_070301FF_format  *p_psw_info;
    unsigned char psw_data[4];

    status = 0;
    ret = 0x00 ;
    p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
    
    for (i = 0; i < Pre_Payment_Para.PassWord_Num; i++) {
		Write_Read_FM24C256 ((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + i * (36 + 4)  , psw_data, 4, 0, 1 );
        if (i == 0) {
            status = p_psw_info->status;
        }
        if (p_psw_info->status != status || p_psw_info->sum != Pre_Payment_Para.PassWord_Num
            || p_psw_info->number != i) {
            ret = 0xFF ;
            break;
        }
    }

    return ret;
}


unsigned char updata_all_psw_info(void)
{
    unsigned char i;
    unsigned char para2;
    unsigned char psw_data[(36 + 4)  ];
    struct Far_Deal_070301FF_format  *p_psw_info;
    unsigned long upd_flg;
    unsigned long psw_msk;

    if (check_collected_psw_info() != 0x00 ) {
        return 0xFF ;
    }

	My_Memcpy(&Co.b[500],(unsigned char *)&Pre_Payment_Para.Far_Key_StatusByte,4);	 
    CPU_ESAM_CARD_Control(2 );
    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);
    p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
    for (i = 0; i < Pre_Payment_Para.PassWord_Num; i++) {
		Write_Read_FM24C256 ((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + i * (36 + 4)  , psw_data, 36        , 0, 1 );
        p_psw_info = (struct Far_Deal_070301FF_format  *)psw_data;
         
        if (i == 0) {
            para2 = 0;
        } else {
            para2 = 0xFF;
        }
        if (Write(0x84,0xd4      ,0x01,para2,32, psw_data + 4) != 0x00 ) {
            if (i != 0) {
                break;
            }
        }

         
        if (p_psw_info->status) {
            Pre_Payment_Para.Far_Key_StatusByte |= (0x1UL << i);
             

        } else {
            Pre_Payment_Para.Far_Key_StatusByte &= ~(0x1UL << i);
             
        }
    }
     
    clear_psw_upd_info();

     
    if (Pre_Payment_Para.psw_status != p_psw_info->status) {
         
         
        Pre_Payment_Para.psw_status = p_psw_info->status;
        Pay_EE_W((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1+1+1+1+4+4+2 +1+4+1+1+8+2+2+2+2+4				 +1) ,(unsigned char *)&(Pre_Payment_Para.psw_status),1,3,
                    (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
    }
    Pre_Payment_Para.Far_Key_StatusByte &= psw_msk;
    write_psw_status_wd_to_esam(Pre_Payment_Para.Far_Key_StatusByte);
    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1+1+1+1 ,(unsigned char*)&Pre_Payment_Para.Far_Key_StatusByte,4,3,
        (unsigned char*)&Pre_Payment_Para,sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );

    Pre_Payment_Data.Far_Key_Updata_Count++;
    if (Pre_Payment_Data.Far_Key_Updata_Count>999999)
        Pre_Payment_Data.Far_Key_Updata_Count=0;
    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		 +4	 +4	  ,(unsigned char*)&Pre_Payment_Data.Far_Key_Updata_Count,4,3,(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   ); 
    Pay_For_Event_Dot((const unsigned char *)&Far_Key_Updata_Event);
    	if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x80) 
    	{
       EventReportState_Expand(1, 7, 0);  
      Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1   + 1   + 1  + 1  + 1  + 1  + 1  + 1 + 1 + 1 + 1 , (unsigned char *)&Event_Report_Status_Times.PSWUpdate_times);
    	}
        FeedWatchdog();
        
    return 0x00 ;
}

 
unsigned char check_and_update_psw_to_esam(void)
{
    unsigned long upd_flg;
    unsigned long psw_msk;
    unsigned char ret;

	if (IntoPowerDownFlag)
		return 0x00 ;

    ret = 0x00 ;
    if (Pre_Payment_Para.Pay_For_Users_Flag15.bit.to_upd_psw ) {
        CPU_ESAM_CARD_Control(2 );
        Cpucard_Serial_Init();
        if (Far_Identity_Auth_Ok_Flag == 0) {
            ret = Esamcard_Atr();
        }
        ret = updata_all_psw_info();
        cpucard_serial_release();
        
        Pre_Payment_Para.Pay_For_Users_Flag15.bit.to_upd_psw = 0;
        Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
               (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
    }
    
    return ret;
}

















unsigned char Far_PassWord_Updata_all(unsigned char *Data_Point)
{
    struct Far_Deal_070301FF_format  *psw_upd_info;
    unsigned char PassWord_Inf[4],PassWord_Inf_T,Addr_Ctrl,ClearVerFlg;
    unsigned char i, j;
    unsigned char buf[48];
    unsigned char *psw_info;
    unsigned char num_cur; 
    unsigned char *psw_data;
    unsigned long upd_flg;
    unsigned char pwd_stat; 
    unsigned long psw_msk;

    psw_msk = ((1UL << Pre_Payment_Para.PassWord_Num) - 1UL);

    psw_upd_info  =  (struct Far_Deal_070301FF_format  *)Data_Point;
     

    num_cur = (CurrPC->len - 8 - 4) / 36        ;  
    if (num_cur == 0) {
        return 0xFF ;  
    }
    for (i = 0; i < num_cur; i++) {
        Reverse_data((unsigned char *)&psw_upd_info[i], 36);
    }
    Reverse_data((unsigned char *)(psw_upd_info + i), 4); 
    
    pwd_stat = psw_upd_info[0].status;

















    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = 0;
    }

    psw_info = buf + 8;
    for (i = 0; i < num_cur; i++) {
         
        if (psw_upd_info[i].status != pwd_stat || psw_upd_info[i].sum != Pre_Payment_Para.PassWord_Num
            || psw_upd_info[i].number >= Pre_Payment_Para.PassWord_Num) {
             
             
             
            return 0xFF ;     
        }
         
        for(j=0; j<36        ; j++) {
			psw_info[j] ^= *((unsigned char *)(&psw_upd_info[i]) + j);
		}









    }

    My_Memcpy(psw_info + 36        , (unsigned char *)(psw_upd_info + i), 4); 
    
     
     
	 
     
	My_Memcpy(buf+2, (unsigned char *)&Meter_Parameter.parameter2.BcdMeterID[0],6);
     
    CPU_ESAM_CARD_Control(2 );
    if (Write(0x04,0xd6      ,0x96,0x00,0x30,buf) != 0x00 ) {
		if (pwd_stat == 0)
		{
			My_Memcpy(buf, 0, 8);
			buf[7] = 1;
			if (Write(0x04,0xd6      ,0x96,0x00,0x30,buf) != 0x00 )
			{
				Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
	        	return 0xFF ;	
			}
		}
		else
		{
	        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
	        return 0xFF ;
		}
    }

     
    Write_Read_FM24C256 (((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + 32         * (36 + 4) ) , (unsigned char *)(&upd_flg), 4, 0, 1 );
    for (i = 0; i < num_cur; i++) {
         
		Write_Read_FM24C256 ((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + psw_upd_info[i].number * (36 + 4)  , (unsigned char *)(&psw_upd_info[i]), 36, 0, 0 ); 
        upd_flg |= (1UL << psw_upd_info[i].number);
    }
    Write_Read_FM24C256 (((0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point )+29) + 32         * (36 + 4) ) , (unsigned char *)(&upd_flg), 4, 0, 0 );
    if ((upd_flg == psw_msk) && (check_collected_psw_info() == 0x00 )) {
        Pre_Payment_Para.Pay_For_Users_Flag15.bit.to_upd_psw = 1;
        Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag15),1,3,
               (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
    }

    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
        (unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
    
     
     
     
     
    
    Co.c.len = 0;
    return 0x00 ;
}

 
void end_infrared_auth(void)
{
    Far_InfraredFlag = 0;
    Far_Infrared_Auth_Ok_Time = 0;
    R_Infrared_Remain_Time = 0;
}

 
unsigned char Far_Deal_07800301(unsigned char *Data_Point)
{
    unsigned char ret;

    end_infrared_auth();
    My_memcpyRev(far_data_p+14,Meter_Parameter.parameter2.BcdMeterID,6);      


    CPU_ESAM_CARD_Control(2 );       
    if (read_esam_serial_num(esam_number) != 0x00 ) {
    	return 0xFF ;
    }
    My_memcpyRev(far_data_p+20,esam_number,8);      

    Card_WR_Buff[0] = 0;
    Card_WR_Buff[1] = 0;
    My_Memcpy(&Card_WR_Buff[2], &Meter_Parameter.parameter2.BcdMeterID[0], 6);

	ret = Internal_Auth(0x80,0xfa,0,3,8, Card_WR_Buff);  
    if (ret != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
        return 0xFF ;
    }

    Reverse_data(Data_Point, 8);
	ret = Internal_Auth(0x80,0xfa,0,0,8,Data_Point);  
    if (ret != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
        return 0xFF ;
    }
    My_memcpyRev(far_data_p+28,receive_send_buffer,8);      

     
	if( Read(0,0x84                    ,0,0,8) != 0x00 ) {
    	return 0xFF ;
	}
    My_memcpyRev(far_data_p+36,receive_send_buffer,8);      

    Co.c.len = 30;
    return 0x00 ;
}

 
unsigned char Far_Deal_07000301(unsigned char *Data_Point)
{

    if (IntoPowerDownFlag) {
		return 0xFF ;
	}
    Reverse_data(Data_Point, 8);
    if (External_Auth(8, 8, Data_Point) != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
    	return 0xFF ;
    }
    
    Far_InfraredFlag = 1;
    Far_Infrared_Auth_Ok_Time = GetNowTime();
    R_Infrared_Remain_Time = Pre_Payment_Para.InfrIdenTime;

     
    Far_Identity_Auth_Ok_Flag = 0;
    R_ID_Remain_Time = 0;
    
    Co.c.len = 0;
    return 0x00 ;
}



 



 



 





static unsigned char check_compare_addr(unsigned long factor_addr, unsigned long data_addr)
{
     
    if ( ((factor_addr >= 0xE000UL && factor_addr < 0x14000UL ) || (factor_addr >= 0xC0000UL    && factor_addr < 0x100000UL )) 
        && ((data_addr >= 0xE000UL && data_addr < 0x14000UL ) || (data_addr >= 0xC0000UL    && data_addr < 0x100000UL )) ){
        return 0x00 ;
    } else {
        return 0xFF ;
    }
 











}


 
unsigned char Far_Deal_078002FF(unsigned char * Data_Point)			
{
    unsigned int i, j;
    unsigned char ok, ret;
    unsigned char psw_idx;
    unsigned long factor_addr;
    unsigned long data_addr;
    unsigned char factor[16];
    unsigned int factor_rd_len;
    unsigned int data_rd_len;

    psw_idx = Data_Point[1];
    factor_addr = (unsigned long)Data_Point[2] | (((unsigned long)Data_Point[3])<<8) | (((unsigned long)Data_Point[4])<<16) | (((unsigned long)Data_Point[5])<<24);
    data_addr = (unsigned long)Data_Point[6] | (((unsigned long)Data_Point[7])<<8) | (((unsigned long)Data_Point[8])<<16) | (((unsigned long)Data_Point[9])<<24);

    if (check_compare_addr(factor_addr, data_addr) != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.addr_err = 1;
        return 0xFF ;    
    }

    factor_rd_len = 16 ;
 





    if (((factor_addr + 16 - 1) >= 0x14000UL ) && (factor_addr < 0x14000UL )) {
        factor_rd_len = 0x14000UL - factor_addr;
    }
	if (((factor_addr + 16 - 1) >= 0x100000UL ) && (factor_addr < 0x100000UL )) {
        factor_rd_len = 0x100000UL - factor_addr;
    }

    data_rd_len = 256 ;
 




    if (((data_addr + 256 - 1) >= 0x14000UL ) && (data_addr < 0x14000UL )) {
        data_rd_len = 0x14000UL - data_addr;
    }
	if (((data_addr + 256 - 1) >= 0x100000UL ) && (data_addr < 0x100000UL )) {
        data_rd_len = 0x100000UL - data_addr;
    }

    ret = FlashReadEW1  ((unsigned char far * )factor_addr,(unsigned char far *		  )factor, factor_rd_len);
    if (ret) {
        return 0xFF ; 
    }
    ret = FlashReadEW1  ((unsigned char far * )data_addr,(unsigned char far *		  )Card_WR_Buff, data_rd_len);
    if (ret) {
        return 0xFF ; 
    }
     
     

     
    if (factor_rd_len < 16 ) {
        factor[factor_rd_len] = 0x80;
        for (i = factor_rd_len + 1; i<16 ; i++) {
            factor[i] = 0x0;
        }
    }
     
    if (data_rd_len < 256 ) {
        Card_WR_Buff[data_rd_len] = 0x80;
        for (i = data_rd_len + 1; i<256 ; i++) {
            Card_WR_Buff[i] = 0x0;
        }
    }

    for (i=0; i<8; i++) {
        factor[i] ^= factor[8 + i];
    }
    for (i=1; i<4; i++) {
        for (j=0; j<64; j++) {
            Card_WR_Buff[j] ^= Card_WR_Buff[64 * i + j];
        }
    }

    ok = Write(0x80, 0xfa, 0x00, psw_idx, 8, factor);
    if (ok != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
        return 0xFF ;
    }

    ok = Write(0x80, 0xfa, 0x01, 0x00, 64, Card_WR_Buff);
    if (ok != 0x00 ) {
        Far_Security_Auth_Err_Info.bit.ESAM_AUTH_ERR = 1;
        return 0xFF ;
    }

    My_memcpyRev(far_data_p+14, receive_send_buffer, 64); 
     
    Co.c.len = 64;
    return 0x00 ;
}




































































































































#pragma SECTION program ROM_PRG2
 
unsigned char Far_Deal_Refundment(unsigned char * Data_Point)
{
    signed long money;
    unsigned char Order_Head[4];
    signed long Remain_Money;
	struct Moneybag_Data Moneybag_Data;

    if (Pre_Payment_Para.Pay_For_Users_Flag14.bit.FUN_BUY_FLAG == 0) {
        return 0xFF ;
    }

    Esam_Remain_Money_Dec();
    Pre_Get_OverZero_Money();
    buyBeforMoney = Remain_Money_Plus;

    Read_Esam_Moneybag_File((unsigned char *)&Moneybag_Data);
    
    if( Far_Write_Esam(0x04,0xd6      ,0x8c,0x00,0x10,Data_Point,0) != 0x00 ) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0xFF ;
    }

    if( Read(0,0xb0       ,0x8c,0,8) != 0x00 ) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
        return 0xFF ;
    }

    My_memcpyRev((unsigned char *)&money, receive_send_buffer, 4);
    My_memcpyRev(Data_Point, receive_send_buffer, 4);
    My_Memcpy(Card_WR_Buff, receive_send_buffer, 8);

    if (money > Moneybag_Data.Remain_Money) {
        return 0xFF ;
    }

    Order_Head[0] = 0x84;
	Order_Head[1] = 0x30;
	Order_Head[2] = 0x02;
	Order_Head[3] = 0x0C;
	if( CPU_Card_Driver((const unsigned char *)&Order_Head[0],8, Card_WR_Buff,0,CommunicationPortMode,0) != 0x00 ) {
        Meter_States.ErrOfInformation.bit.Invalid_Password = 1;
		return 0xFF ;
	}

    Pre_Payment_Para.SendBack_Money = money;
     
    This_Month_Data.Energy_Record.Pre_Save_Data .Remain_Money -= money;
    Pay_For_Data_Save();
    Pre_Get_OverZero_Money();
    
    Pre_Payment_Data.Back_Money_Count++;
    if (Pre_Payment_Data.Back_Money_Count > 999999)
        Pre_Payment_Data.Back_Money_Count = 0;
    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		 +4	  ,(unsigned char*)&Pre_Payment_Data.Back_Money_Count,4,3,(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );     
    Pay_For_Event_Dot((const unsigned char *)&Refundment_Event);
    
    Pre_Payment_Para.Pay_For_Users_Flag14.bit.FUN_BUY_FLAG = 0;
    Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag14),1,3,
             (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );

	Pay_For_Users_Flag6.bit.Pay_Buy_Money_Flg =1;	 

    return 0x00 ;
}


 
 
 
 
 

struct Far_645_Frame_Flag_0x03
	{
	unsigned char Data_ID[4];
	unsigned char Source_Length;				 
	Event_Spec_Deal_R Far_645_Order_0x03;     
	};



const struct Far_645_Frame_Flag_0x03  Far_645_Frame_Flag_0x03_List[]=
	{
	0xFF,0x01,0x80,0x07,16,Far_Deal_078001FF, 

	0x01,0x02,0x81,0x07,8,Far_Deal_07810201, 
	0xFF,0x02,0x81,0x07,8,Far_Deal_078102FF,     

	0xFF,0x00,0x00,0x07,32,Far_Deal_070000FF, 

	0xFF,0x01,0x00,0x07,14,Far_Deal_070001FF, 

	0x01,0x02,0x00,0x07,8,Far_Deal_07000201, 
	0xFF,0x02,0x00,0x07,8,Far_Deal_070002FF, 

    0xFF,0x04,0x00,0x07,0xff,Far_Deal_write_info_file, 
    0xFF,0x05,0x00,0x07,0xff,Far_Deal_write_info_file, 

	0xFF,0x01,0x01,0x07,30,Far_Deal_070101FF, 

	0xFF,0x02,0x01,0x07,30,Far_Deal_070102FF, 


	0xFF,0x01,0x03,0x07,0xff,Far_PassWord_Updata_all, 
	
	0xFF,0x03,0x01,0x07,24,Far_Deal_070103FF,			 

	 
	0xFF,0x03,0x80,0x07,16,Far_Deal_07800301,			 

	 
	0xFF,0x03,0x00,0x07,16,Far_Deal_07000301,			 

    0xFF,0x02,0x80,0x07,18,Far_Deal_078002FF,			 
     
	
	};

 
 

unsigned char Far_Deal_Order_0x03(unsigned char * Data_Point ,unsigned char Source_Length)
	{
	unsigned int Length;
	unsigned char i;
	struct Far_645_Frame_Flag_0x03  Far_645_Frame_Flag_0x03;
	struct Far_645_Frame_0x03         *Far_645_Frame_0x03;

	Far_645_Frame_0x03 = (struct Far_645_Frame_0x03 *)Data_Point;

	Length = sizeof(Far_645_Frame_Flag_0x03_List) ;
	Length/=sizeof(struct Far_645_Frame_Flag_0x03) ;

	for( i=0;i<Length;i++ )
		{
		if(	(Far_645_Frame_Flag_0x03_List[i].Data_ID[0] == Far_645_Frame_0x03->Data_ID[0] )&& 
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[1] == Far_645_Frame_0x03->Data_ID[1] )&&
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[2] == Far_645_Frame_0x03->Data_ID[2] )&&
			(Far_645_Frame_Flag_0x03_List[i].Data_ID[3] == Far_645_Frame_0x03->Data_ID[3] ) ) 
			break;
		}
	if( i==Length )
		return 0xFF ;


	if( Source_Length != Far_645_Frame_Flag_0x03_List[i].Source_Length 
        && Far_645_Frame_Flag_0x03_List[i].Source_Length != 0xff) 
		return 0xFF ;			
	if( Far_645_Frame_Flag_0x03_List[i].Far_645_Order_0x03 !=0 )
		{
		if( Far_645_Frame_Flag_0x03_List[i].Far_645_Order_0x03(Data_Point+sizeof(struct Far_645_Frame_0x03) ) == 0x00 )
			return 0x00 ;
		}
	return 0xFF ;
	}

 
 
 
 
 
 
 
 
 
struct Far_645_Frame_T1
	{
 
	unsigned char PassWord[4];
	unsigned char Do_man[4];
	};

 
 
struct Far_Deal_Para_Flag_T1
	{
	unsigned char Data_ID[4];
	unsigned char Esam_File;
	unsigned int  Esam_Offset;
	unsigned char Esam_Length;
	};

 
 
#pragma SECTION rom UserROMData
const struct Far_Deal_Para_Flag_T1 Far_Deal_Para_List_T1[] = 
	{
	0x08,0x01,0x00,0x04, 0x02,4						 +1							 +1						 +4					  ,0x05,    
    0x09,0x01,0x00,0x04, 0x04,((((4 + 32*4) + 6*4) + 7*4) + 12)       ,0x05,    
	0x06,0x03,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			  ,0x03,    
	0x07,0x03,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							  ,0x03,    
    0x02,0x04,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							  ,0x06,    
	0x0E,0x04,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								 +4			 +4			 +3							 +3							 +6								  ,0x06,    
	0x01,0x10,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								  ,0x04,    
	0x02,0x10,0x00,0x04, 0x02,4						 +1							 +1						 +4					 +5 					 +1								 +4			  ,0x04,    

     
	 
	 
	 
    0xFF,0x01,0x05,0x04, 0x03,4 ,128,    

     
	 
	 
	 
	0xFF,0x02,0x05,0x04, 0x04,4 ,128,    

 
    
	 
	 
	 
	 
     
     
    0xFF,0x04,0x06,0x04, 0x03,(4 + 32*4) ,64,     

	 
	 
	 
	 
     
     
     
 

	 
	 
	 
	 
     
     
    0xFF,0x05,0x06,0x04, 0x04,(4 + 32*4) ,64,     

	 
	 
	 
	 
     
     
     
 

     

	};


#pragma SECTION program ROM_PRG2

























 
unsigned char is_T1_para(unsigned char * id)
{
    unsigned char i;
    unsigned int Length;
    unsigned char res;

    Length = sizeof(Far_Deal_Para_List_T1 ) ;
    Length /= sizeof(struct Far_Deal_Para_Flag_T1) ;

    res = 0;
    for(i = 0;i < Length; i++ ) {
        if( Far_Deal_Para_List_T1[i].Data_ID[0] == id[0] && 
            Far_Deal_Para_List_T1[i].Data_ID[1] == id[1] &&
            Far_Deal_Para_List_T1[i].Data_ID[2] == id[2] &&
            Far_Deal_Para_List_T1[i].Data_ID[3] == id[3] ) {
            res = 1;
            break;
        }
    }
     
     
    if ((id[1] == 0x01 || id[1] == 0x02) &&  id[2] == 0x05 && id[3] == 0x04) {
        res = 1;
    }
     
     
    
     
    if ((id[1] == 0x04 || id[1] == 0x05) &&  id[2] == 0x06 && id[3] == 0x04) {
        res = 1;
    }
     
     
     
     
    return res;
}

unsigned char is_T3_para(unsigned char * id)
{
    unsigned char res;

    res = 0;
     
    if( (id[0] == 0x01 && id[1] == 0x13 &&  id[2] == 0x00 && id[3] == 0x04) ||(id[0] == 0x03 && id[1] == 0x15 &&  id[2] == 0x00 && id[3] == 0x04)) {
        res = 1;
    }
    return res;
}


unsigned char Far_Deal_Para_T1(unsigned char * ID_Point,unsigned char * Data_Point ,unsigned char *Source_Length)
{
	unsigned char i,j;
	unsigned int Length;
	struct Far_Deal_Para_Flag_T1  Far_Deal_Para_Flag_T1;
	struct Far_645_Frame_T1  * Far_645_Frame_T1;
    unsigned char *data;
    unsigned long id;
    unsigned char last;
    unsigned char *dst;

 
 
	dst = Card_WR_Buff;
	Far_645_Frame_T1 = (struct Far_645_Frame_T1  *)Data_Point;

	Length = sizeof(Far_Deal_Para_List_T1 ) ;
	Length/=sizeof(struct Far_Deal_Para_Flag_T1) ;

	for( i=0;i<Length;i++ )
	{
		if(	Far_Deal_Para_List_T1[i].Data_ID[0] == *(ID_Point+0) && 
			Far_Deal_Para_List_T1[i].Data_ID[1] == *(ID_Point+1) &&
			Far_Deal_Para_List_T1[i].Data_ID[2] == *(ID_Point+2) &&
			Far_Deal_Para_List_T1[i].Data_ID[3] == *(ID_Point+3) ) 
		{
			break;
		}
	}
	if( i==Length )
		return 0xFF ;

	for( j=0;j<sizeof(struct Far_Deal_Para_Flag_T1) ;j++ )
		*(((unsigned char *)(&Far_Deal_Para_Flag_T1))+j) = *(((const unsigned char *)&Far_Deal_Para_List_T1[i])+j);

    id = *(unsigned long far*)Far_Deal_Para_List_T1[i].Data_ID;

    switch (id) {
     
    case 0x040502ff: 
        if( ( *Source_Length) % 4 != 0 || ( *Source_Length) < 16) {
            return 0xFF ;	
        }
        Far_Deal_Para_Flag_T1.Esam_Length = *Source_Length - 16; 
        data = Data_Point + sizeof(struct Far_645_Frame_T1 ) ;
        for (j=0; j < Far_Deal_Para_Flag_T1.Esam_Length / 4; j++) {
            My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        }
        My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        if(Far_Write_Esam(0x04,0xd6      ,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Card_WR_Buff, 2)!=0x00 ) {
    		 
    		return 0xFF ;
	    } 
        last = j - 1; 
        if (last < 31) {
            for (j; j < 32; j++) {
               data[ 4 * j + 0] = data[ 4 * last + 0];
               data[ 4 * j + 1] = data[ 4 * last + 1];
               data[ 4 * j + 2] = data[ 4 * last + 2];
               data[ 4 * j + 3] = data[ 4 * last + 3];
            }
            *Source_Length += (4 * (31 - last));
        }
        break;
     
    case 0x040605FF: 
        if( ( *Source_Length) != (Far_Deal_Para_List_T1[i].Esam_Length+16) )
    		return 0xFF ;	
        
        data = Data_Point + sizeof(struct Far_645_Frame_T1 ) ;
        for (j=0; j < 6 + 7; j++) { 
            My_memcpyRev(dst + 4 * j, data + 4 * j, 4);
        }
        dst = dst + 4 * j;
        data = data + 4 * j;
        for (j=0; j < 4; j++) { 
            My_memcpyRev(dst + 3 * j, data + 3 * j, 3);
             





        }

        My_memcpyRev(dst + 3 * j, data + 3 * j, 4);
        if(Far_Write_Esam(0x04,0xd6      ,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Card_WR_Buff, 2)!=0x00 ) {
    		 
    		return 0xFF ;
	    } 
        break;
    case 0x0400040E: 
        if (Meter_Parameter.parameter1.MeterMode[1].bit.b5 ) { 
             
            return 0xFF ;
        }
         
    case 0x04000402: 
        if (Pre_Payment_Para.Far_Key_StatusByte) { 
             
            return 0xFF ;
        }
         
    default:
        if( ( *Source_Length) != (Far_Deal_Para_List_T1[i].Esam_Length+16) )
    		return 0xFF ;	
        if(Far_Write_Esam(0x04,0xd6      ,0x80+Far_Deal_Para_Flag_T1.Esam_File,
										(unsigned char)Far_Deal_Para_Flag_T1.Esam_Offset,
										Far_Deal_Para_Flag_T1.Esam_Length,
										Data_Point+sizeof(struct Far_645_Frame_T1 ) ,0)!=0x00 ) {
		     
		    return 0xFF ;
	    }    
    }	


















 
	( *Source_Length)-=0x04;
	return 0x00 ;
}


 
 
 
 
 
 
 
 
 
 
struct Far_645_Frame_T2
	{
 
 
	unsigned char PassWord[4];
	unsigned char Do_man[4];
	};

 
 
struct Far_Deal_Para_Flag_T2
	{
	unsigned char Data_ID[4];
	unsigned char Source_Length;				 
	unsigned char TX_Length;					 
	};


 
 
 
 
 
 
#pragma SECTION rom UserROMData
const unsigned char Data_ID_Offset[]=
{0x09,0x10,0x11,0x12,0x13};
unsigned char Far_Deal_Para_T2(unsigned char * ID_Point,unsigned char * Data_Point,unsigned char *Soure_Length )
	{
	unsigned char i,j,Block_Flag, blk_sz;
	unsigned char commaFlg;			 		 
	struct Far_Deal_Para_Flag_T2  Far_Deal_Para_Flag_T2;
	struct Far_645_Frame_T2  * Far_645_Frame_T2;
	unsigned char ID_a,ID_b,ID_c,ID_d;
    unsigned long id;
    signed long money;

    if (is_T1_para(ID_Point) || is_T3_para(ID_Point)) {
         
        return 0xFF ;
    }

	Far_645_Frame_T2 = (struct Far_645_Frame_T2  *)Data_Point;

    id = *(unsigned long *)ID_Point;
	ID_a = *(ID_Point+3 );
	ID_b = *(ID_Point+2 );
	ID_c = *(ID_Point+1 );
	ID_d = *(ID_Point+0 );
	Block_Flag = 0x00;

	Far_Deal_Para_Flag_T2.Data_ID[0] = *(ID_Point+0 );	
	Far_Deal_Para_Flag_T2.Data_ID[1] = *(ID_Point+1 );
	Far_Deal_Para_Flag_T2.Data_ID[2] = *(ID_Point+2 );
	Far_Deal_Para_Flag_T2.Data_ID[3] = *(ID_Point+3 );

    commaFlg = 0;
    blk_sz = 0;
    Block_Flag = 0;
	 
	 
	 
	 
	 
     
    if (ID_a==0x04 &&  ( ID_b>=0x01 && ID_b<=0x02 ) && ID_c==0x00 && ID_d<=0x08) { 
        blk_sz = 3;
		Block_Flag = 0xFF;
    } else if (ID_a == 0x0E && ID_b == 0x00 &&  ( ID_c >= 0x03 && ID_c <= 0x08 )  && ID_d == 0xff) { 
        blk_sz = 4;
		Block_Flag = 0xFF;
		}
	else if ((ID_a==0x04) && (ID_b==0x04) && (ID_c>=0x01 && ID_c<=0x04) && (ID_d>=0x01 && ID_d<=0x78))    
		{
		commaFlg=1;
		}

	Far_Deal_Para_Flag_T2.Source_Length = ( *Soure_Length)-16; 

 	i = *(ID_Point+2 );
	i%=5;
	j = Data_ID_Offset[i];
	if ((ID_a==0x04) && (ID_b==0x80) && (ID_c==0x00) && (ID_d<=0x03))			   	 
		j=Data_ID_Offset[0];	

    if (id == 0x04001006) { 
        if (Far_Deal_Refundment(Data_Point + sizeof(struct Far_645_Frame_T2 ) ) == 0x00 ) {
            ( *Soure_Length) = 12;
            return 0x00 ;
        } else {
            return 0xFF ;
        }
    } 
   
	if( Far_Write_Esam(0x04,0xd6      ,0x80+j,0x00,Far_Deal_Para_Flag_T2.Source_Length,Data_Point+sizeof(struct Far_645_Frame_T2 ) ,0)!=0x00 )
	{
	 
	return 0xFF ;
	}
    
	if( Read(0x00, 0xb0       , 0x80+j, 0x00, 1) != 0x00 )
		return 0xFF ;

	Far_Deal_Para_Flag_T2.TX_Length = receive_send_buffer[0]-4; 
    if (Far_Deal_Para_Flag_T2.TX_Length > 192) { 
        return 0xFF ;
    }
	if( Read(0x00, 0xb0       , 0x80+j, 0x00, Far_Deal_Para_Flag_T2.TX_Length+5) != 0x00 )
		return 0xFF ;

	Reverse_data(receive_send_buffer+1,4); 
	if( My_Memcmp(receive_send_buffer+1,Far_Deal_Para_Flag_T2.Data_ID,4) != 0 )
		return 0xFF ;

	if (commaFlg)						 		 	 
	{
		My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) , receive_send_buffer+5, 4);
		memcpy(Data_Point+sizeof(struct Far_645_Frame_T2 ) +4, receive_send_buffer+5+4, 1);
	}
	 
	 
	 
	 
	 
	 
	else if( Block_Flag == 0 )			 	
	{
		My_Memcpy(Data_Point+sizeof(struct Far_645_Frame_T2 ) , 0, 32);
        switch (id) {
        case 0x0400040F: 
            My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) , receive_send_buffer+5, 4);
            My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) + 4, receive_send_buffer + 9, 4);
            My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) + 8, receive_send_buffer+ 13, 3);
            break;
        case 0x0e000005:
        case 0x0e00000c:
        case 0x0e00000d:
             
            My_Memcpy(Data_Point+sizeof(struct Far_645_Frame_T2 ) , receive_send_buffer+5, Far_Deal_Para_Flag_T2.TX_Length);
            break;
        default:
		    My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) , receive_send_buffer+5, Far_Deal_Para_Flag_T2.TX_Length);
            break;                
        }
	}
	else								 	
	{
		Block_Flag = Far_Deal_Para_Flag_T2.TX_Length/blk_sz;
		for( i=0;i<Block_Flag;i++ )
			{
			My_memcpyRev(Data_Point+sizeof(struct Far_645_Frame_T2 ) +i*blk_sz, receive_send_buffer+5+i*blk_sz, blk_sz);
			}
	}
    
	( *Soure_Length) =Far_Deal_Para_Flag_T2.TX_Length+12;
	return 0x00 ;
	}


 
unsigned char Far_Password_Check(unsigned char * ID_Point,unsigned char * Point ,unsigned char *Length)
	{
	unsigned char ret;

	ret = 0x00 ;
	Far_Spec_Order_Flag = 0;

	My_Memcpy(&oprateCode[0], Point+4, 4);

	if( *(Point)==0x99  || *(Point)==0x98 )
		{
		if(Pre_Payment_Data.HangMeterNum >= 200       ) {
             
			return 0xFF ;
		}
		if( Far_Identity_Auth_Ok_Flag != 0xFF ) {
             
			return 0xFF ;
		}
		
		Cpucard_Serial_Init();	 

 
 
		Far_Spec_Order_Flag  = 0xFF;

		if( *(Point)==0x99 )
			{
			ret = Far_Deal_Para_T1(ID_Point,Point ,Length) ;
			}
		else
			{
			ret = Far_Deal_Para_T2(ID_Point,Point ,Length);
			}
	
		cpucard_serial_release();	 
		*(Point)=0x04;
		My_Memcpy(Point+1, &Meter_Parameter.parameter1.ClearPassword[3][1], 3);
		}
	else
		{
            if (is_T3_para(ID_Point)) {
                    ret = 0x00 ;
            } else {
    		 if (O1ther_Meter_Parameter.WorkRoomState)
    		 	ret = 0x00 ;
    		 else
    		 	ret = 0xFF ;
            }
		}
	return ret;
	}

 
unsigned char CheckCmdTime(unsigned char * Point)
{
	if ((*(Point+2)==0x99)&&(*(Point+3)==0x99)&&(*(Point+4)==0x99)&&(*(Point+5)==0x99)&&(*(Point+6)==0x99)&&(*(Point+7)==0x99))
	{
		;
	}
	else	 
	{
		if ((0==CheckTime(Point+2))||(My_Memcmp(Point+2,&(MainSoftDate .Year),6)==2))	 
		{
			return 0xFF ;
		}
	}
	return 0x00 ;
}

 
unsigned char Far_Deal_Control(unsigned char * Point)
	{
	unsigned char ok;
	unsigned char Control_Flag;
	 

	ok = 0xFF;
	Control_Flag = (* Point);

	if (CheckCmdTime(Point)==0xFF )
		{
		Fay_Ctl_Res_Err.bit.TimeErr=1;
		return 0;
		}
		
	if( Control_Flag==0x1A )	
		{
		if ((!Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY ))			 
			{
			if (!Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH )				 
			{
				if (!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID )				 
				{
					Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =1;				 
					Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
						(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
				}
			}
			else
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =0;
			 
			 
			Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE =1;
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPEN_CMD =1;
			FarOpenTime=GetNowTime();
			 
			if( Control_Flag==0x1A )							 
			 	Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPEN_CMD =1;							 
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D =0;	 
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E =0;
			 
			if (Pre_Payment_Para.Far_Open_Delay)		 
				Fay_Ctl_Res_Ok.bit.DelayOpen=1;
			else
				{
				if (Pay_For_Users_Flag6.bit.Curr_30A_Flg )
					Fay_Ctl_Res_Ok.bit.CurrDelay=1;
				else
					Fay_Ctl_Res_Ok.bit.DirOpen=1;
				}
			}
		else
			{
			ok = 0;
			Fay_Ctl_Res_Err.bit.OpenFriErr=1;
			}
		}
	else if( Control_Flag==0x1B || Control_Flag==0x1C )	 
		{
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =0;
		if ( (Relay_Alarm_SWitch_Flag[1][0]&0x60)	 
			|| ( (Relay_Alarm_SWitch_Flag[1][0] & 0x0c)  && ( Control_Flag == 0x1C )))
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.OPRATE_ID_CLOSE =1;
		if (Pre_Payment_Para.Pay_For_Users_Flag13.bit.OPRATE_ID_CLOSE )
			{
			if (!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID )
				{
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =1;
				Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
					(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
				}
			}
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH = 0;
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE =0;
		 
		 
		 
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPEN_CMD =0;

		if( Control_Flag==0x1C )
		{
			if( Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT )			 
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.SWITCH_ALLOW_CLOSE = 1;	 
			Fay_Ctl_Res_Ok.bit.DirCls=1;
			Card_Alarm_Switch(); 
		}
		else
			Fay_Ctl_Res_Ok.bit.AllowCls=1;
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D =0;	 
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E =0;
		}
	else if( Control_Flag==0x2A )					 
		{
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_ALARM = 1;
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_CLOSE_ALARM = 0;
		Fay_Ctl_Res_Ok.bit.Alarm=1;
		}
	else if( Control_Flag==0x2B )					 
		{
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_ALARM = 0;
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_CLOSE_ALARM = 1;
		Fay_Ctl_Res_Ok.bit.AlarmFree=1;
		}
	else if( Control_Flag==0x3A )					 
		{
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =0;
		if (Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT )						 
			{
			if (!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID )				 
				{
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =1;
				Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
					(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
				}
			}
		else
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =0;
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY = 1;				 
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE =0;
		if (!Pre_Payment_Para.Pay_For_Users_Flag3.bit.FRIEND_DAY_CLOSE )
			{
			Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH = 0;
			 
			}
		 
		else
		{             
			if (Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH  )  
				Pre_Payment_Para.Pay_For_Users_Flag14.bit.FRIEND_RELEASE_SWITCH_FLAG = 1;
		}
		Fay_Ctl_Res_Ok.bit.Friend=1;
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D =0;	 
		Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E =0;
		}
	else if( Control_Flag==0x3B )					 
		{
		if (Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY )
			{
			if ((!Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT )&&(Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE ||Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH ))
				{
				if (!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID )
					{
					Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =1;
					Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
						(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
					}
				}
			else
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =0;
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY = 0;
		  
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPEN_CMD =0;
			if ( Pre_Payment_Para.Pay_For_Users_Flag3.bit.FRIEND_DAY_CLOSE )        
				{
					if(  Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH  )   
					{
						 
						 
						Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH = 0;
						Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE =1;
						FarOpenTime=GetNowTime();
					}
				}
		  
			}
		Fay_Ctl_Res_Ok.bit.FriFree=1;
		}
	else if ((Control_Flag==0x1D)||(Control_Flag==0x1E)) 
		{
		if (Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY )
			{
			Fay_Ctl_Res_Err.bit.WarnFriErr=1;
			ok=0;
			}
		else if (Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE || (Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT &&(!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D )&&(!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E )))	 	 
			{
			Fay_Ctl_Res_Err.bit.WarnOpenErr=1;	 
			ok=0;
			}
		else if (0==*(Point+1))
			{
			Fay_Ctl_Res_Err.bit.WarnTimeErr=1;
			ok=0;
			}
		else
			{
			if (Control_Flag==0x1D)
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D =1;	 
			else
				Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D =0;	 
			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1E =!Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_WARN_1D ;
			Pre_Payment_Para.Far_Close_Delay=*(Point+1);
			Pre_Payment_Para.Far_Close_Delay*=5;	 
            Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1+1+1+1+1+1+1+4+4+2 +1+4+1+1+8+2 ,(unsigned char *)&(Pre_Payment_Para.Far_Close_Delay),2,3,
                               (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
            FarOpenTime=GetNowTime();	 
			if (Pay_For_Users_Flag6.bit.Curr_30A_Flg )
				Fay_Ctl_Res_Ok.bit.CurrDelay=1;
			else
				Fay_Ctl_Res_Ok.bit.Warn=1;

			Pre_Payment_Para.Pay_For_Users_Flag13.bit.FAR_OPRATE_ID =1;
			Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	  ,(unsigned char*)&Pre_Payment_Data.oprateCode[0],4,3,
				(unsigned char*)&Pre_Payment_Data,sizeof( struct _Pre_Payment_Data ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )   );
			}
		}
	else
		{
		ok = 0;
		Fay_Ctl_Res_Err.bit.PassErr=1;
		}
	 
	 Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),2,3,
		 	    (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );

	Far_Switch_Control(1);
	Drive_Act_Repair();
	
	return ok;
	}

 
 
 
 
 
 
 
void Far_Switch_Control(unsigned char kind)
{
	if (kind)
		{
		 
		if ((!Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT ) && (!Pre_Payment_Para.Pay_For_Users_Flag13.bit.METER_IN_FRIEND_DAY )
			&& (Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE ||(Pay_For_Users_Flag6.bit.Curr_30A_Flg && Relay_Alarm_SWitch_Flag[1][0])))
			displayCharOnOff(24		  ,1,1);
		else
			{
			displayCharOnOff(24		  ,0,1);
			 
			if (Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT && Pay_For_Users_Flag8.bit.SWITCH_PREPARE_STATE )
				displayCharOnOff(24		  ,1,0);
			else
				displayCharOnOff(24		  ,0,0);
			}
		 
		if((Displayfinish_flag==1)&&(light_AlarmSwitchLED==0)) 
		{		
		if (Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT &&(!Pay_For_Users_Flag8.bit.SWITCH_PREPARE_STATE ))
			p1_addr.bit.b6				      =!p1_addr.bit.b6				      ;
		else
			{
			p1_addr.bit.b6				      =NEW645Meter_States.Meter_Status3.bit.Relay_Status;
			 
			 
			 
			 
			}
		}
		}

	if (IntoPowerDownFlag)
		return;
	if (!Meter_Parameter.parameter1.MeterTypeMode.bit.b5 )
		return;
	
	if (((kind==1) && Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE && (!GetTimeCount(FarOpenTime,Pre_Payment_Para.Far_Open_Delay*60000)))
		||((kind==0) && Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE )
		|| (Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT && Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE ))
		{
		 
		Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_PREPARE =0;
		if( !Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH  )
			{
			Pre_Payment_Para.Pay_For_Users_Flag12.bit.FAR_OPEN_SWITCH = 1;
			 
		 	 
			}
		 Pay_EE_W(0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+4+4+4+4+4+4+(32           )*4+(32           )*4+4+4+4+6+6+6+1+1    +sizeof(struct DATEANDTIME_DEF)+sizeof(struct DATEANDTIME_DEF)+1 +1+4+2+(6			 *4)+(6			 *4)+((6			 +1)*4)+((6			 +1)*4)		 +12	+12		 +1+1+1+1+1+1 ,(unsigned char *)&(Pre_Payment_Para.Pay_For_Users_Flag12),1,3,
	 	    (unsigned char *)&(Pre_Payment_Para),sizeof( struct _Pre_Payment_Para ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data ) );
		}
}

unsigned char Find_Do_Money_Bag(void)
	{	
	unsigned char Result;

	Result = 0x00;
	if( Pay_For_Users_Flag16.bit.REMAIN_BAG_DOING    ==0)
		{
		Pay_For_Users_Flag16.bit.REMAIN_BAG_DOING    = 1;
		Remain_Money_Bag_Do_Time = GetNowTime();
		Reamin_Money_ESAM_Dec_Time=GetNowTime();
		Result = 0xFF;
		}
	else
		{
		if(GetTimeCount(Remain_Money_Bag_Do_Time,900000l)==0)
			{
			Result = 0xFF;
			Pay_For_Users_Flag16.bit.REMAIN_BAG_DOING    = 0;
			Remain_Money_Bag_Do_Time = GetNowTime();
			Reamin_Money_ESAM_Dec_Time=GetNowTime();
			}
		}
	return Result;
	}





