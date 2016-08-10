#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"
   






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



 
#line 8 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/ram.h"
  








#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"
  









#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defmcro.h"
  








#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
#line 10 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defmcro.h"

 
 


 



 	 






 


 




















































































 

 


 

 
 



    

 






			








		








	
	
	








	
	
	








	
	
	








	
	
	








	
	
	

















	                        
	
 





















































 

   












 
 

















































































 
 
 
 






 

















































 
                            
                            
                        
#line 11 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"

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
 
 

 
#line 12 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"

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

 

 
#line 13 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"

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
 




 






















 




 














































 




























    
#line 14 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"


 
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



  
#line 9 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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

#line 10 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 11 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Eeprom.h"
   








 
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 
 

 















































 

 

 


 


 
 
 

 







 

          







 




 






























 






 





















 
 
 
 
 
 
 











 
 
 
 
 
 
 











 
 
 
 
 
 
 












 
 
 
 
 



















 




 



 





























 



























 

 






















                     
















               
 


















































 













 
 
 
 
 







 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 






 


































 























                                                                                                               








 
 
 
 
 



 
 
 
 




 
 
 
 
 
 
 
 
 

 




 
 
 
 


 





























































                                                                                                            
 

 




 
 
















































 
















 



  
#line 12 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Comm.h"


  


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


 
#line 13 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/att7022_operation.h"
 
extern void	Set_or_Clear_LCD_Flash_Flag(void);				 
extern void	Toggle_Loudspeaker(void);		 
extern void	Output_On_3_In_1_Terminal_Set(unsigned char Call_Condition);	
		 

 
		 
extern void	Calculate_Arccos_FA(void);		 
extern void	Clear_LCD_Current_Flash_Flag(void);		 
extern void	Check_If_Reset_Terminal_Alarm(void);		 

extern void SoundAlarmEndCheck(void);   
extern void SoundAlarmInit(void);   

extern void Check_Voltage_Threshold(void);

extern 	union byte_def Alarm_SwitchToggle_Terminal;









extern 	unsigned long	Alarm_Terminal_Set_Starting_Time;						 
extern unsigned char auxiliary_power_flag;

extern unsigned char	VoltageGreaterThanThreshold_Flag;
extern unsigned char	VoltageGreaterThanCritical_Flag;   
extern unsigned char	VoltageGreaterThanICcard_Flag;	 
extern const unsigned long P_Flash_Current_Threshold[10];
#line 14 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/initcpu.h"
extern void	InitPort(void);
 
extern void     IniUART(void);
extern void	IniSIMCard(void);  
extern void	IniBoad(void);   
 
extern void     InitTimeA0(void);
extern void     InitMainRegeist(void);   
extern void     InitInterrupt(void);  
extern void     InitTimeA2_PowerDown(void);
extern void    CheckEeprom(void);
extern void 	InitTimeA3(void);	 


extern  unsigned char PDFlagRam1[15]; 
extern  union  BYTE_BIT Eeprom_Flag;

    
#line 15 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/multi.h"



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

#line 16 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/File_System.h"
 














 





 
struct Fs_Node
{
	unsigned char dat[64];     
	unsigned int  next;                          
};

 
struct Fs_BitFlag
{
	char init_flag:1;
	char bad_flag:1;
	char end_flag:1;
	char del_flag:1;
	char alt_flag:1;
	char :1;
	char :1;
	char :1;
};

 
struct Fs_variable_def
{
     unsigned int Corrcet_Err_StartPage;
     unsigned int SEC_Backup_1_Page;
     unsigned int SEC_Backup_2_Page;
     unsigned int Good_Block_Num;
     unsigned int Bad_Block_Num;
     unsigned int SEC_Backup_3_Page;
     unsigned int SEC_Backup_4_Page;
};

extern int Fs_Init(void);                                
extern unsigned int Write_File(unsigned int file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Read_File(unsigned int  file_name,unsigned int addr,unsigned int offset,unsigned char * buff);
extern unsigned int Delete_File(unsigned int file_name);
extern void Fs_Rename(unsigned int src_filename,unsigned int dest_filename);
extern int Free_List_Rebuild(void);          

#line 17 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Demand.h"




#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/sfr64a.h"
 














 
 
 
 
 
 























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
#line 5 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Demand.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/defdata.h"
  




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
 
#line 6 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Demand.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_BASE_FUN.h"














































































 
 
 
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
 




 






















 




 














































 




























    
#line 7 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Demand.h"




 
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

 
#line 18 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/datachange.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_Base_Fun.h"














































































 
 
 
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
 




 






















 




 














































 




























    
#line 2 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/datachange.h"





 
 
 
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





#line 19 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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



#line 20 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/initram.h"
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


#line 21 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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


#line 22 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"


#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/pay_def.h"




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





 




 


#line 5 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/pay_def.h"
























 







 
 


	 


	 











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














#line 24 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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

#line 25 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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

 



#line 26 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

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


#line 27 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/AllVoltageLoss.h"
 









extern	void	AllVoltageLoss_WakingUp_Counter_Updating(void);	 
 
extern	void	Get_AllVoltageLoss_Event_Address_Times(unsigned int *Event_Pointer,				 
											   unsigned char *Event_Number,					 

											   unsigned long *AllVoltageLoss_Minute_Time);	 

extern void	AllVoltageLoss_SecondCounter_Updating(void);	 

extern unsigned char Check_PD_Curr_Vality(void); 
extern struct	ALLVOLTAGELOSS_STRUCTURE AllVoltageLoss_Structure;	
extern void AllVoltageLoss_init_Measure(void); 
extern void AllVoltageLoss_Close_Measure(void); 
extern void Read_Curr_Powerdown(void); 
extern unsigned char Check_Open_power(void);
extern unsigned char Check_All_lossvoltage_Start(void);


extern volatile unsigned long PD_max_curr; 
extern unsigned char Curr_Valid_flag; 
extern unsigned long AllVoltageLoss_counter; 
extern unsigned char Curr_RD_flag;
extern struct   PD_CURRENT_STRUCT  PD_curr; 
extern unsigned char L_PD_Last_T; 
extern unsigned char lastpdreadcurrtime;   
 

extern void Read_Volt_Powerdown(void);

extern struct	PDVOLT_STRUCTURE  pdvoltdata;


#line 28 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Energy_Del.h"



extern union BYTE_DEF gPD_Data_valid_flag; 
                                           
                                           
                                           

extern void Check_Energy_main(unsigned char kind);
extern void Write_TO_Cal_PowerDown_Energy_add(void);



#line 29 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/interrupt.h"



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

#line 30 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/freeze.h"
 
 
 

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/datachange.h"

#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/MB_Base_Fun.h"














































































 
 
 
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
 




 






















 




 














































 




























    
#line 2 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/datachange.h"

























#line 5 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/freeze.h"



extern void Freeze_Main(void);
extern void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime); 
extern void Record_HDFreeze(void); 
extern void Day_freeze(unsigned char sort);
extern void Clear_HDFreezeData(void);
extern void PoweronFreeze_Deal(void);
extern unsigned char  Clear_Freeze(void);
extern void  Clear_Freeze_Period(void);	
extern void PowerUpDayFreeze(void); 

extern unsigned char ComparentTime(unsigned char *t1, unsigned char *t2); 

extern void ClearFreezeCommDeal(unsigned long Data_ID);









typedef struct _DATE_TIME
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
	unsigned char Week;
}TDateTime, *PDateTime;

typedef struct _DATE
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
}TDate, *PDate;

struct FREEZE_ENERGY_DATA
{
	unsigned long  Plus_Active[9        ]; 
	unsigned long  Nega_Active[9        ];
	
	unsigned long  Quad_Reactive[4][9        ];
};
struct FREEZE_DEMAND_DATA
{
	unsigned long  Plus_Active_Demand[9        ];
	unsigned char  Plus_Active_Demand_Time[9        ][5];
	unsigned long  Nega_Active_Demand[9        ];
	unsigned char  Nega_Active_Demand_Time[9        ][5];

};
struct FREEZE_POWER_DATA
{
	signed long Active_power_t[4];
	signed long Reactive_power_t[4];
};
struct FREEZE_DATA 
{
	unsigned char  Time[5];
	struct FREEZE_ENERGY_DATA Energy;
	struct FREEZE_DEMAND_DATA Demand;
	struct FREEZE_POWER_DATA Power;
};

struct CLEARFREEZE_STRU
{
unsigned int     Pointer_addr;                    
unsigned char    *Pointer;  		                  
unsigned int     Filename_begin;                  
};
extern const unsigned long Clearfreeze_ID[9];



int GetSkipedTimeFlags(TDateTime* rpTime1, TDateTime* rpTime2, TDateTime* rpTimeFlag, TDateTime* rpResult, unsigned char rMax); 
unsigned char CheckDateTime(TDateTime* rpDateTime);				 

#line 31 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"


#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Measure_Interface.h"




































































































#line 33 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"


#line 1 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/Clock_time.H"



extern unsigned char AddTime(void);
extern unsigned char PowerUp_Init_RTC(unsigned char neweeprom, double long *datatime);
extern void ReadRTC(void); 
extern unsigned char  CheckRamTime(void);

extern unsigned long rtc_lossvolt_flag;
extern unsigned char rtc_lossdata_flag;



#line 35 "D:/TEST/12、RN8302B/2016-6-29/RN8302B CODE_2016-6-29/RN8302B CODE/Release_Code/MB4_64A/EVENTNEW.C"

 
 

 
 
 

 
 

union  BYTE_BIT     ProgramFlag[2];            
struct EVENT_POWER_NET_POINTER   Event_N;      											 
union  EVENT_POWER_NET_FLAG      Event_B;      													 
union  EVENT_POWER_NET_FLAG      Event_S;      

 
 
 
 
 
 
 
 
struct DATEANDTIME_DEF OverPowerAlarmTime;   
unsigned  char OverPowerAlarmFlag;         
unsigned  char Clear_Demand_Mode;          
 

 

 

 
unsigned char EventCriticalVoltage_Flag=0;
unsigned char EventDataValid_Flag=0;
unsigned char EventTimeTicksValid_Flag=0;   
unsigned char EventEnergyValid_Flag=0;
unsigned char currimbalancecs=0;
unsigned char voltimbalancecs=0;
unsigned long EventUn=0;
unsigned long EventIb=0;

struct PowerDown_EventSave_Data  PdEventData;

 
 
 
unsigned char TempEventData[400]={0};
 
 
unsigned long lostvoltenergyall[2];
unsigned long lostvoltenergy[6];
 
 

struct VoltStatistic_Data VoltStat[4];   
unsigned long Event_AmpHour[3];
 
unsigned long Event0BeginAmpHour[36];
unsigned int CrcEvent0Flag;
unsigned int CrcEventPowerDownData;
unsigned int CrcVoltStatData;
unsigned int CrcEventTimeTicks;   
unsigned long maximbalancerate[3];   


unsigned long savemaximbalancerate[3];   
unsigned char VoltStatTimeCounter;

extern unsigned char Read_event_first_flag;
 

struct	PDOPENCOVER_STRUCTURE  pdopencovercheckdata[2];

struct DEMAND_DATA_FORM overdemandmaxdemand[6];

unsigned char powerreversetflag[2];
unsigned char powerreversetcnt[2];

unsigned long eventmaxvolt;
unsigned long eventminvolt;
unsigned long eventmaxcurr;
unsigned long eventmincurr;
unsigned long eventavgcurr;

union EVENTSTATUS eventstatusinfo;

struct	RST90E36_STRUCTURE rst90e36info;

unsigned char lostvoltagetime[3][2];

 
 
 
 
void EventTimeAdd(void);
 
 
 
 
extern void FreezeDateProgram(unsigned int file_name,unsigned char demand_zero_flag , unsigned char *freezetime); 
 
void New2007_Event(void);
void InitNew2007Event(void);
 
unsigned int EventData_crc(void); 
void EventData_PowerDown_Save(void);
unsigned char EventData_PowerOn_Check(void);
unsigned char EventRecord_Poweron_Check(void);
void LostVoltageEvent(void);
 
 
 
void PowerDownEvent_OnCheck(void);
unsigned int ProgrammeEvent(unsigned long,unsigned long);
void ProgrammeEventEnd_Check(void);
void ProgrammeEventEnd_Check_Payment(void);
unsigned int ClearMeterRecord(unsigned long);
 
void VoltStatisticEvent(void);
void VoltStatisticFunc(void);
void VoltStatSetDefault(void);
void VoltStatInit(void);
void VoltStatisticCheck(void);
void VoltStatisticBill(void);
 
 
 
void LostCurrentEvent(void);
void BreakPhaseEvent(void);
 
 
 
void VoltReverseEvent(void);

void OverDemandEvent(void);
void PrepOverDemandFirstEventData(unsigned long);

void PowerReverseEvent(void);
void ALLPowerReverseEvent(void);
unsigned int AdjustTimeRecord(unsigned long);
unsigned int ClearDemandRecord(unsigned long);
unsigned int ClearEventRecord(unsigned long,unsigned long);
unsigned int ProgWeekRecord(unsigned long,unsigned char);
 
 
 
unsigned int ProgBillDayRecord(unsigned long,unsigned char *);
unsigned int ProgYearSlotRecord(unsigned long);
unsigned int ProgDailySlotRecord(unsigned long);
 
 
void OverVoltageEvent(void);
unsigned char ClearNewEventRecord(unsigned long,unsigned long);
void Phase3LostVoltEvent(void);
void OverDemandAlarmEvent(void);
 
 
 
int PrepVoltStatReadData(void);
void ResetCpuEvent_OnCheck(void);
void RunClockErrorRecord(void);
void PowerUpClockErrorRecord(void);
void EepromErrorRecord(void);
void EnergyPassZeroRecord(void);
void SetPrimaryRecord(void);
void EepromEventSetDefault(void);
void EMeterPowerdownRecord(void);
void VoltageDownEvent(void);
void OverCurrentEvent(void);
void SaveLostVoltTime(unsigned int,unsigned char);
void LostVoltEnergyAdd(unsigned int,unsigned char);
int   PrepLostVoltEnergyData(unsigned long);
void UpLoadEvent(void);
void CurrReverseEvent(void);
void OverFactorEvent(void);
void FailCurrentEvent(void);
unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times);

void OpenBoxCoverEvent_Check(void);
void ClockBatteryDisplayBattery_Event(void);
void CurrVoltImBalance_Event(void);
void Save_SignalPhase_Statistic(unsigned char* Statistic,
											    unsigned char* DataBuff,
											    unsigned int FOffset);
void Clear_SignalPhase_VoltStatistic_Data(unsigned char*  SignaPhase);
unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,
															unsigned char  progoldvaluep,unsigned char sort);
void Copy_ENERGY_TO_CO(unsigned int startIndex); 
 
 
 
 
 
 
 
void EventFlagPowerOnInit(void);
unsigned char PrepEvent0Data(unsigned int);
unsigned long Cal_LastTime(unsigned char* eventbegintimepointer, unsigned char* eventendtimepointer);
void SaveEvent0LastTime(unsigned int,unsigned char,unsigned char*,unsigned int,unsigned long*);
void SaveEvent0BeginAmpHour(unsigned char);
void Cal_AmpHour_poweron(unsigned int eventaddr, unsigned char kind);
void SaveEvent0EndAmpHour(unsigned char);
void ClearEvent0Flag(unsigned char,unsigned char);
void MoveEventData2Flash(unsigned int,unsigned int,unsigned char *,unsigned char);
void AdjustMeterRecord(void);
void AdjustMeterRecordEndCheck(void);
unsigned char PrepLostVoltFirstEventData(unsigned int,unsigned char,unsigned char,unsigned char);
unsigned char PrepNewFirstEventData(unsigned long);
void Write_File_PdEvent(unsigned int,unsigned int,unsigned char,unsigned char *);
unsigned long  Prepare_For_EventLastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer);
 
void Refresh_EventData(unsigned long eventcode);
unsigned char Refresh_AddTime(unsigned long eventcode);
void SaveEvent0LastTime_Other(unsigned int eventlasttimeaddr,
	unsigned long* eventlasttimepointer);   
void ClearEventDate_BatteryPowerOn(void);
void Check_Max_Imbalance_Rate(void);

void ConstantMagnetEventCheck(void);

void PowerAbnormalEventCheck(void);

void PdOpenCoverCheckInit(unsigned char);
void PdOpenCoverCheck(void);
unsigned char CheckOpenCoverDataValid(unsigned char);
void PdOpenCoverCheckPowerUpDeal(void);
unsigned char CheckOpenCoverState(unsigned char);

unsigned char ClearProgDailySlotRecord(unsigned long,unsigned long);
unsigned char ClearEventAddEnergy(unsigned int eventeepromaddr);
void ClearEventAll(void);
void ClearEventCommDeal(unsigned long eventID);
void ClearEventDataPowerOn(void);
void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file);

void Rst90E36Event(void);

unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times);

void Save_Event_StartData_Flash(unsigned char *eventp,unsigned int eventpaddr,
                                unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                                unsigned long *eventtimes,unsigned int eventtimesaddr);

void Save_Event_EndData_Flash(unsigned char eventp,
                              unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                              unsigned long *eventtimeticks,unsigned int eventtimeticksaddr);
                              
void Save_Record_Data_Flash(unsigned char *eventp,unsigned int eventpaddr,
                            unsigned int filename,unsigned char fileendaddr,
                            unsigned long *eventtimes,unsigned int eventtimesaddr);

void Save_Event_StartData_Eeprom(unsigned char *eventp,unsigned int eventpaddr,
                                 unsigned int eepromaddr,unsigned char len,
                                 unsigned long *eventtimes,unsigned int eventtimesaddr);

void CloseOverPowerAlarmSwitch(void);



 
#pragma SECTION rom UserROMData
const struct CLEAREVENT_STRU  ClearEvent_Leaf[]={
{0,0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                      ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)              ,(void*)0  ,(void*)0  ,(void*)0  ,&Event_Power_Net_Times.LostVoltage_A_Times,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,0,12,0,0,0x41},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                    ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                      ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)              ,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_A_Times,&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks,0x01,255,0L ,10,0x9E},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1                ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                  ,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_B_Times,&Event_Power_Net_Timeticks.LostVoltage_B_Times_Ticks,0x02,255,32L ,21,0x9E},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1    ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4 ,(unsigned char *)&Event_Power_Net_Pointer.LostVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostVoltage_C_Times,&Event_Power_Net_Timeticks.LostVoltage_C_Times_Ticks,0x04,255,64L ,32,0x9E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_A_Times,&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks,0x08,0,1024L ,368,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_B_Times,&Event_Power_Net_Timeticks.OverVoltage_B_Times_Ticks,0x10,0,1056L ,379,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4     ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4  ,(unsigned char *)&Event_Power_Net_Pointer.OverVoltage_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.OverVoltage_C_Times,&Event_Power_Net_Timeticks.OverVoltage_C_Times_Ticks,0x20,0,1088L ,390,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L            ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)         ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4    ,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_A_Times,&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks,0x01,0,416L ,159,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1        ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4   ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4         ,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_B_Times,&Event_Power_Net_Timeticks.BreakPhase_B_Times_Ticks,0x02,0,448L ,170,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1      ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4         ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4 ,(unsigned char *)&Event_Power_Net_Pointer.BreakPhase_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.BreakPhase_C_Times,&Event_Power_Net_Timeticks.BreakPhase_C_Times_Ticks,0x04,0,480L ,181,0x1E},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.Phase3LostVolt_Times,&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,0x10,16,1120L ,401,0x9E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4    ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4 ,(unsigned char *)&Event_Power_Net_Pointer.VoltageReserve_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.VoltageReserve_Times,&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks,0x08,0,512L ,192,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4 ,(unsigned char *)&Event_Power_Net_Pointer.VoltImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.VoltImBalanceEvent_Times,&Event_Power_Net_Timeticks.VoltImBalanceEvent_Times_Ticks,0x80,0,1376L ,522,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1)  ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4)  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4 ,(unsigned char *)&Event_Power_Net_Pointer.CurrImBalanceEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.CurrImBalanceEvent_Times,&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks,0x40,0,1344L ,511,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                      ,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_A_Times,&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks,0x20,0,320L ,126,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                     ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4               ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                     ,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_B_Times,&Event_Power_Net_Timeticks.LostCurrent_B_Times_Ticks,0x40,0,352L ,137,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1       ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4     ,(unsigned char *)&Event_Power_Net_Pointer.LostCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[0],(unsigned char*)&PdEventData.eventflag[6].byte,&Event_Power_Net_Times.LostCurrent_C_Times,&Event_Power_Net_Timeticks.LostCurrent_C_Times_Ticks,0x80,0,384L ,148,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_A_Times,&Event_Power_Net_Timeticks.PowerReverse_A_Ticks,0x01,0,608L ,225,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_B_Times,&Event_Power_Net_Timeticks.PowerReverse_B_Ticks,0x02,0,640L ,236,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[2],(unsigned char*)&PdEventData.eventflag[8].byte,&Event_Power_Net_Times.PowerReverse_C_Times,&Event_Power_Net_Timeticks.PowerReverse_C_Ticks,0x04,0,672L ,247,0x1E},
{((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],(void*)0  ,(void*)0  ,(void*)0  ,0x01,0,224L ,89,0x24},
{((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data) ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],(void*)0  ,(void*)0  ,(void*)0  ,0x08,1,256L ,102,0x24},
{((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data) ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],(void*)0  ,(void*)0  ,(void*)0  ,0x01,2,288L ,115,0x24},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4  ,0,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.PowerDown_Times,(void*)0  ,0x40,12,96L ,43,0x8E},
{0,0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4 ,(void*)0  ,(void*)0  ,(void*)0  ,&Event_Power_Net_Times.OverPaADemand_Times,&Event_Power_Net_Timeticks.OverPaADemand_Times_Ticks,0,8,0,0,0x01},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.OverPaADemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,(void*)0  ,(void*)0  ,0x40,0,544L ,203,0x06},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.OverNeADemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,(void*)0  ,(void*)0  ,0x80,0,576L ,214,0x06},
{((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4 ,0,(unsigned char *)&Event_Power_Net_Pointer.ProgrammeEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(unsigned char*)&PdEventData.eventflag[10].byte,&Event_Power_Net_Times.ProgrammeEvent_Times,(void*)0  ,0x10,50,128L ,54,0x8E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ClearDemandRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ClearDemandRecord_Times,(void*)0  ,0,0,736L ,269,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.AdjustTimeRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.AdjustTimeRecord_Times,(void*)0  ,0,0,704L ,258,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgWeekRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgWeekRecord_Times,(void*)0  ,0,0,800L ,291,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgAEModeRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgAEModeRecord_Times,(void*)0  ,0,0,832L ,302,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgNEMode1Record_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgNEMode1Record_Times,(void*)0  ,0,0,864L ,313,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgNEMode2Record_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgNEMode2Record_Times,(void*)0  ,0,0,896L ,324,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgBillDayRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgBillDayRecord_Times,(void*)0  ,0,0,928L ,335,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4 ,0,(unsigned char *)&Event_Meter_Pro_Pointer.ProgYearSlotRecord_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.ProgYearSlotRecord_Times,(void*)0  ,0,0,960L ,346,0x0C},
 
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4 ,0,(unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OpenCoverEvent_Times,(void*)0  ,0x40,60,192L ,76,0x8E},
{(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4     ,0,(unsigned char *)&Event_Power_Net_Pointer.OpenBoxEvent_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OpenBoxEvent_Times,(void*)0  ,0x80,60,992L ,357,0x8E},
 
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4 ,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_A_Times,&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks,0x08,0,1440L ,840,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_B_Times,&Event_Power_Net_Timeticks.VoltageDown_B_Times_Ticks,0x10,0,1472L ,851,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.VoltageDown_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[1],(unsigned char*)&PdEventData.eventflag[7].byte,&Event_Power_Net_Times.VoltageDown_C_Times,&Event_Power_Net_Timeticks.VoltageDown_C_Times_Ticks,0x20,0,1504L ,862,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_A_Times,&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks,0x01,0,1536L ,873,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_B_Times,&Event_Power_Net_Timeticks.OverCurrent_B_Times_Ticks,0x02,0,1568L ,884,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.OverCurrent_C_Times,&Event_Power_Net_Timeticks.OverCurrent_C_Times_Ticks,0x04,0,1600L ,895,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_A_Times,&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks,0x08,0,1632L ,906,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_B_Times,&Event_Power_Net_Timeticks.UpLoad_B_Times_Ticks,0x10,0,1664L ,917,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.UpLoad_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[3],(unsigned char*)&PdEventData.eventflag[9].byte,&Event_Power_Net_Times.UpLoad_C_Times,&Event_Power_Net_Timeticks.UpLoad_C_Times_Ticks,0x20,0,1696L ,928,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.CurrReverse_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.CurrReverse_Times,&Event_Power_Net_Timeticks.CurrReverse_Times_Ticks,0x01,0,1728L ,939,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.OverFactor_Times,&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,0x02,0,1760L ,950,0x1E},
{0,(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1)  ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4   ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_A_Times,&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks,0x08,0,1792L ,961,0x1E},
{0,(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4  +4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_B_Times,&Event_Power_Net_Timeticks.FailCurrent_B_Times_Ticks,0x10,0,1824L ,972,0x1E},
{0,(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4  +4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.FailCurrent_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(unsigned char*)&PdEventData.eventflag[11].byte,&Event_Power_Net_Times.FailCurrent_C_Times,&Event_Power_Net_Timeticks.FailCurrent_C_Times_Ticks,0x20,0,1856L ,983,0x1E},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1+1+1+1  ,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) ,0,(unsigned char *)&Event_Meter_Pro_Pointer.OverPowerCloseSwitch_P,(void*)0  ,(void*)0  ,&Event_Meter_Pro_Times.OverPowerCloseSwitch_Times,(void*)0  ,0,0,1184L ,456,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over1RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],(void*)0  ,(void*)0  ,(void*)0  ,0x08,0,2176L ,2207,0x06},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over2RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],(void*)0  ,(void*)0  ,(void*)0  ,0x10,0,2208L ,2239,0x06},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over3RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],(void*)0  ,(void*)0  ,(void*)0  ,0x20,0,2240L ,2271,0x06},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.Over4RDemand_P,(unsigned char*)&Event_Power_Net_Flag.byte[7],(void*)0  ,(void*)0  ,(void*)0  ,0x40,0,2272L ,2303,0x06},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_A_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(void*)0  ,&Event_Power_Net_Times.OverFactor_A_Times,&Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks,0x20,0,2304L ,2335,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_B_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(void*)0  ,&Event_Power_Net_Times.OverFactor_B_Times,&Event_Power_Net_Timeticks.OverFactor_B_Times_Ticks,0x40,0,2336L ,2367,0x1E},
{0,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4 ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.OverFactor_C_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(void*)0  ,&Event_Power_Net_Times.OverFactor_C_Times,&Event_Power_Net_Timeticks.OverFactor_C_Times_Ticks,0x80,0,2368L ,2399,0x1E},
{0,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1)  ,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)   ,0,(unsigned char *)&Event_Power_Net_Pointer.ConstantMagnet_P,(unsigned char*)&Event_Power_Net_Flag.byte[6],(void*)0  ,&Event_Power_Net_Times.ConstantMagnet_Times,(void*)0  ,0x40,0,2432L ,2463,0x0E},
{0,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   ,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  ,0,(unsigned char *)&Event_Power_Net_Pointer.PowerAbnormal_P,(void*)0  ,(void*)0  ,&Event_Power_Net_Times.PowerAbnormal_Times,(void*)0  ,0,0,2464L ,2495,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1      ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4    ,0,(unsigned char *)&Event_Power_Net_Pointer.PowerReverse_T_P,(void*)0  ,(void*)0  ,&Event_Power_Net_Times.PowerReverse_T_Times,(void*)0  ,0,0,2400L ,2431,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1 ,0,0,(unsigned char *)&Event_Power_Net_Pointer.VoltStatistic_T_P,(void*)0  ,(void*)0  ,(void*)0  ,(void*)0  ,0,0,2496L ,2527,0x04},
{0,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1)  ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)   ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4 ,(unsigned char *)&Event_Power_Net_Pointer.CurrFarImB_P,(unsigned char*)&Event_Power_Net_Flag.byte[5],(void*)0  ,&Event_Power_Net_Times.CurrFarImB_Times,&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks,0x04,0,2528L ,2559,0x1E},
 
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	  ,0,(unsigned char *)&Pay_For_Event_Point.Far_Control_Event_P,0,0,&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks,(void*)0  ,0,0,((2560L)											 +32L			 )									  ,0,0x0C},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	  +4,0,(unsigned char *)&Pay_For_Event_Point.Far_Control_Free_Event_P,0,0,&Pre_Payment_Data.FARCONTROLEVENT.farClose_Ticks,(void*)0  ,0,0,(((2560L)											 +32L			 )									 +32L)				  ,0,0x0C},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		 +4	 +4	  ,0,(unsigned char *)&Pay_For_Event_Point.Far_Key_Updata_Event_P,0,0,&Pre_Payment_Data.Far_Key_Updata_Count,(void*)0  ,0,0,((((2560L)											 +32L			 )									 +32L)				 +32L)	  ,0,0x0C},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		 +4	 +4	 +4  ,0,(unsigned char *)&Pay_For_Event_Point.OPCard_Error_Event_P,0,0,&Pre_Payment_Data.OPCard_Error_Num,(void*)0  ,0,0,(((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		  ,0,0x0C},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		 +4	  ,0,(unsigned char *)&Pay_For_Event_Point.Refundment_Event_P,0,0,&Pre_Payment_Data.Back_Money_Count,(void*)0  ,0,0,((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		  ,0,0x0C},
{0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point ) ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		 +4		  ,0,(unsigned char *)&Pay_For_Event_Point.RelayErr_Event_P,&Pre_Payment_Para.Pay_For_Users_Flag15.intd,0,&Pre_Payment_Data.Relay_Error_Num,(void*)0  ,0x04,0,(((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				  ,0,0x0E},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	  ,0,(unsigned char *)&Pay_For_Event_Point.ProgramTriff_Event_P,0,0,&Pre_Payment_Data.TriffProgNum,(void*)0  ,0,0,3408L	 		  ,0,0x0C},
{0,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	 +8	 +4		  ,0,(unsigned char *)&Pay_For_Event_Point.ProgramStep_Event_P,0,0,&Pre_Payment_Data.StepProgNum,(void*)0  ,0,0,((((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				 +32L)					  ,0,0x0C},
{0,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4  ,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4        ,(unsigned char *)&Event_Power_Net_Pointer.OverPowerAlarm_P,(unsigned char*)&Event_Power_Net_Flag.byte[4],(void*)0  ,&Event_Power_Net_Times.OverPowerAlarm_Times,&Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,0x01,0,1152L ,1183,0x1E}
};

 

const unsigned long Clearevent_ID[74]={0x1000FFFF,0x1001FFFF,0x1002FFFF,0x1003FFFF,0x1201FFFF,
								     0x1202FFFF,0x1203FFFF,0x1301FFFF,0x1302FFFF,0x1303FFFF,
								     0x030500FF,0x1400FFFF,0x1600FFFF,0x1700FFFF,0x1801FFFF,
								     0x1802FFFF,0x1803FFFF,0x1B01FFFF,0x1B02FFFF,0x1B03FFFF,
								     0x031001FF,0x031002FF,0x031003FF,0x031100FF,0x031200FF,
								     0x031201FF,0x031202FF,0x033000FF,0x033002FF,0x033004FF,
								     0x033007FF,0x033009FF,0x03300AFF,0x03300BFF,0x03300CFF,
								     0x033006FF,0x03300DFF,0x03300EFF,
								     0x1101FFFF,0x1102FFFF,0x1103FFFF,0x1901FFFF,0x1902FFFF,
								     0x1903FFFF,0x1C01FFFF,0x1C02FFFF,0x1C03FFFF,0x1500FFFF,
								     0x1F00FFFF,0x1A01FFFF,0x1A02FFFF,0x1A03FFFF,0x034201FF,
								     0x031203FF,0x031204FF,0x031205FF,0x031206FF,
								     0x1F01FFFF,0x1F02FFFF,0x1F03FFFF,
								     0x033500FF,
								     0x033700FF,
								     0x210000FF,
								     0x031000FF,
								     0x2000FFFF,
								     0x1D00FFFF,0x1E00FFFF,0x033012FF,0x033013FF,
								     0x033400FF,0x033600FF,0x03300FFF,0x033010FF,
								     0x034200FF};

          
const unsigned long Voltage_table1[4]={1000000L,2200000L,577000L,3800000L};

union  BYTE_BIT VoltCheck_N[3][2];
 
 
 
 
 
 
 
 
void EventTimeAdd()
{
	unsigned int i,j;
	unsigned char mask=0;
	
	 for(i=0;i<6;i++)   
	 {
		mask=*((unsigned char *)&Event_Power_Net_Flag.byte[i]);  
		for(j=0;j<8;j++)
		{
			if((mask & 0x01)!= 0)
			{
				(*((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+j+i*8L))++; 
				 
			}
			mask >>= 1;
		}  
	 }
	 
	
	 
	 
}                                                                    
                                          
 
 
#pragma SECTION rom UserROMData  
const unsigned long Vn[4]={1000000L,2200000L,577000L,3800000L};
 
void New2007_Event(void){
	
	int2ic_addr.byte &= 0xf8;
	InitNew2007Event();
	int2ic_addr.byte |= 0x01;
   
  Phase3LostVoltEvent();
   
  VoltReverseEvent();
   
  CurrReverseEvent();
   
  LostVoltageEvent();
   
  LostCurrentEvent();
   
  BreakPhaseEvent();
   
  PowerReverseEvent();
  ALLPowerReverseEvent();
   
  int2ic_addr.byte &= 0xf8;
  VoltStatisticEvent();
  int2ic_addr.byte |= 0x01;
   
  OverVoltageEvent();
   
  OverDemandAlarmEvent();
   
  int2ic_addr.byte &= 0xf8;
  AdjustMeterRecordEndCheck();
  int2ic_addr.byte |= 0x01;
   
  CurrVoltImBalance_Event();
   
  VoltageDownEvent();
   
  OverCurrentEvent();
   
  UpLoadEvent();
   
  OverFactorEvent();
   
  FailCurrentEvent();
  
  OverDemandEvent();
  
  ConstantMagnetEventCheck();
  
  OpenCoverCheck();
  
  int2ic_addr.byte &= 0xf8;
  Rst90E36Event();
  int2ic_addr.byte |= 0x01;
	
}

void InitNew2007Event(void)
{
	unsigned char unc;
	unsigned long tempangleac;
	
	EventUn=1000000;
	EventIb=Meter_Parameter.parameter1.EventJudgeIn;
	 
	if(((Volt_Region      <=3))&&(Curr_Region  <=9))
	{
		EventUn=Vn[Volt_Region      ];
	}
	
	eventmaxvolt=Volt[0];
	eventminvolt=Volt[0];
	eventmaxcurr=Curr[0];
	eventmincurr=Curr[0];
	for(unc=1;unc<3;unc++)
	{
		if((Volt_Region      ==0 || Volt_Region      ==3)&&(unc==1))
		  continue;
		
		if(eventmaxvolt<Volt[unc])
		  eventmaxvolt=Volt[unc];
		  
		if(eventminvolt>Volt[unc])
		  eventminvolt=Volt[unc];
		
		if(eventmaxcurr<Curr[unc])
		  eventmaxcurr=Curr[unc];
		  
		if(eventmincurr>Curr[unc])
		  eventmincurr=Curr[unc];
	}
	
	flag_communication_with_measuring_board.bit.b7    =0;
	if(Volt_Region      ==0 || Volt_Region      ==3)
	{
	  tempangleac=angle[1];
	  if(tempangleac>18000)
	    tempangleac=36000-tempangleac;
	  
	  if(flag_communication_with_measuring_board.bit.b7    ==0)
	  {
	  	if((ProgramRunPhaseFlag.bit.b3     !=0)||((tempangleac>7400)&&(Volt[0] > 100000)&&(Volt[2] > 100000)))
	      flag_communication_with_measuring_board.bit.b7    =1;
	  }
	  else
	  {
	  	if((ProgramRunPhaseFlag.bit.b3     ==0)&&(tempangleac<7400))
	  	  flag_communication_with_measuring_board.bit.b7    =0;
	  }
	  
	  eventavgcurr=(Curr[0]+Curr[2])/2;
	}
	else
	{
		flag_communication_with_measuring_board.bit.b7    =0;
		
		eventavgcurr=(Curr[0]+Curr[1]+Curr[2])/3;
	}
		
}

 






unsigned int EventData_crc(void)
{
	unsigned char unc;
	unsigned int crc_value;
	
	for(unc=0;unc<3;unc++)
	{
	  *((unsigned long *)&Co.b[300]+unc)=Event_AmpHour[unc];
	  *((unsigned long *)&Co.b[456]+unc)=maximbalancerate[unc];
	}
	for(unc=0;unc<36;unc++)
	  *((unsigned long *)&Co.b[312]+unc)=Event0BeginAmpHour[unc];
	  
	crc_value = CRC(&Co.b[300],168);
	
	return (crc_value);
}

void EventData_PowerDown_Save(void){
	
	CrcEvent0Flag=CRC(&Event_Power_Net_Flag.byte[0],8);
	
	CrcEventTimeTicks=CRC((unsigned char *)&Event_Power_Net_Timeticks,192);   
	
  CrcEventPowerDownData = EventData_crc();
  
	CrcVoltStatData=CRC((unsigned char*) &VoltStat[0],192);
	
}

unsigned char EventData_PowerOn_Check(void){
	unsigned char res=0;
	unsigned char unc=0;
	unsigned int tempuni,tempcrc;   
	
	FeedWatchdog();
	CheckPowerDown();
	EventDataValid_Flag=0;
	EventEnergyValid_Flag=0;
	
	EventTimeTicksValid_Flag=0;   
	tempcrc=0;
	tempcrc=CRC((unsigned char*)&Event_Power_Net_Timeticks,192);
	if(tempcrc==CrcEventTimeTicks)
	{
		EventTimeTicksValid_Flag=0xFF;  
	}
	else
	{
	  	EventTimeTicksValid_Flag=0;   
		ReadBlock((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)   ,(unsigned char *)&Event_Power_Net_Timeticks,
			sizeof(struct EVENT_POWER_NET_TIMETICKS),0);
		FeedWatchdog();
		
	}

	
	tempuni=CRC(&Event_Power_Net_Flag.byte[0],8);
	if(tempuni==CrcEvent0Flag){
		EventDataValid_Flag=0xFF;
	}
	else{
	   res=0;
     
     if((gPD_Data_valid_flag.byte & 0x09) == 0x09)
     	{
     		unc = ReadBlock((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64) , &Co.b[300], sizeof(struct POWERDOWN_SAVE_DATA),0);
     		if(unc)
     			{
     				tempuni=sizeof(struct ENERGY_POWERDOWN)+sizeof(struct DATEANDTIME_DEF)+1;
     	      for(unc=0;unc<8;unc++)
     	        Event_Power_Net_Flag.byte[unc]=Co.b[300+tempuni+unc];
     	      CrcEvent0Flag=CRC(&Event_Power_Net_Flag.byte[0],8);
     	      res=0xFF;
     			} 
     			
     			    	  
     	}
     
     if(res==0){
     	 for(unc=0;unc<8;unc++)
	      Event_Power_Net_Flag.byte[unc]=0;
	     CrcEvent0Flag=0xFF;
     }
  }
  
	tempuni=EventData_crc();
	
	if(tempuni!=CrcEventPowerDownData){
		for(unc=0;unc<3;unc++)
		{
	    Event_AmpHour[unc]=0xFFFFFFFF;
	    maximbalancerate[unc]=0xFFFFFFFF;
	  }
	  for(unc=0;unc<36;unc++)
	    Event0BeginAmpHour[unc]=0xFFFFFFFF;
	  
    CrcEventPowerDownData = EventData_crc();
	}
  
	return 0;
}

unsigned char EventRecord_Poweron_Check(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int uni;
	union EVENTPOWERONDEALFLAG eventdealflag;
	unsigned char calamphourkind;
	unsigned char calamphouraddrkind;
	unsigned int eventdatakind;
	unsigned int eventdataaddr;
	unsigned char eventdataaddradjust;
	unsigned char eventdatalength;
	unsigned char eventdatafileadjust;
	unsigned char eventtimetickskind;
	unsigned int eventtimeticksaddr;
	unsigned long *eventtimetickspointer;
	unsigned int tempeventaddr0;   
	unsigned int tempeventaddr1;   
	
	FeedWatchdog();
	CheckPowerDown();
	
	if(IsNormalReset(0))
	{
		for(unc=0;unc<6;unc++)
		  Co.b[600+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		
		if((CheckTime(&Co.b[600])!=0xff))
	  {
	    for(unc=0;unc<6;unc++)
		    Co.b[600+unc]=0xff;
		  
	  }
		
		PdOpenCoverCheckPowerUpDeal();
        
		Event_Report_Status_Chk(0);
                      
		for(unc=0;unc<8;unc++)
		{
			for(und=0;und<8;und++)
			{
				if(((Event_Power_Net_Flag.byte[unc])&(0x01<<und))!=0)
				{
					eventdealflag.intd=0;
					uni=unc;
					uni=((uni<<8)|und);
					switch(uni)
					{
						case 0x0000:
						case 0x0001:
						case 0x0002:   
						  eventdealflag.bit.b0=1;
						  calamphourkind=und;
	            calamphouraddrkind=0;
	            eventdealflag.bit.b1=1;
	            eventdatakind=0x004E;
	            eventdataaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +((unsigned int)255)*und;
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdatafileadjust=0;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)              +((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
	            eventdealflag.bit.b4=1;
	            tempeventaddr0=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 +((unsigned int)8)*und;
	            eventdealflag.bit.b5=1;
	            tempeventaddr1=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L +((unsigned int)12)*und+6;
						break;
						
						case 0x0003:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=512L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.VoltageReserve_P;
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4 ;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0005:
						case 0x0006:
						case 0x0007:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=320L +((unsigned int)32)*(und-5);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.LostCurrent_A_P+(und-5));
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                      +((unsigned int)4)*(und-5);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks)+(und-5);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0100:
						case 0x0101:
						case 0x0102:   
	            eventdealflag.bit.b0=1;
						  calamphourkind=9+und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=416L +((unsigned int)32)*(und);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.BreakPhase_A_P+und);
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4    +((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0103:
						case 0x0104:
						case 0x0105:   
						  eventdealflag.bit.b0=1;
						  calamphourkind=und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=1440L +((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.VoltageDown_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4 +((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0106:
						case 0x0107:   
						  eventdealflag.bit.b7=1;
						  tempeventaddr0=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8 +((unsigned int)(und-6))*sizeof(struct DEMAND_DATA_FORM);
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0102;
	            eventdataaddr=544L +((unsigned int)32)*(und-6);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverPaADemand_P+(und-6));
	            eventdataaddradjust=6;
	            eventdatalength=15;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0200:
						case 0x0201:
						case 0x0202:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=608L +((unsigned int)32)*und;
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.PowerReverse_A_P+und);
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4 +((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.PowerReverse_A_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0203:
						case 0x0204:
						case 0x0205:   
						  eventdealflag.bit.b0=1;
						  calamphourkind=3+und;
	            calamphouraddrkind=1;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x004E;
	            eventdataaddr=1024L +((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverVoltage_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=114;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4 +((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0206:
						case 0x0207:   
						  eventdealflag.bit.b8=1;
						  tempeventaddr0=und-6;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x001E;
	            eventdataaddr=1344L +((unsigned int)32)*(und-6);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.CurrImBalanceEvent_P+(und-6));
	            eventdataaddradjust=102;
	            eventdatalength=106;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4 +((unsigned int)4)*(und-6);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks)+(und-6);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0300:
						case 0x0301:
						case 0x0302:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=1536L +((unsigned int)32)*und;
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverCurrent_A_P+und);
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4 +((unsigned int)4)*und;
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks)+und;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0303:
						case 0x0304:
						case 0x0305:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=1632L +((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.UpLoad_A_P+(und-3));
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4 +((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0400:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0002;
	            eventdataaddr=1152L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.OverPowerAlarm_P;
	            eventdataaddradjust=14;
	            eventdatalength=6;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4        ;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;












						case 0x0405:
						case 0x0406:
						case 0x0407:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=2304L +((unsigned int)32)*(und-5);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverFactor_A_P+(und-5));
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4 +((unsigned int)4)*(und-5);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks)+(und-5);
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0500:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=1728L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.CurrReverse_P;
	            eventdataaddradjust=102;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4 ;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.CurrReverse_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0501:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=1760L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.OverFactor_P;
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4 ;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.OverFactor_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0502:   
						  eventdealflag.bit.b8=1;
						  tempeventaddr0=2;
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x001E;
	            eventdataaddr=2528L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.CurrFarImB_P;
	            eventdataaddradjust=102;
	            eventdatalength=106;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4 ;
	            eventtimetickspointer=&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks;
	            eventdealflag.bit.b3=1;
						break;
						
						case 0x0503:
						case 0x0504:
						case 0x0505:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x000E;
	            eventdataaddr=1792L +((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.FailCurrent_A_P+(und-3));
	            eventdataaddradjust=141;
	            eventdatalength=102;
	            eventdealflag.bit.b2=1;
	            eventtimetickskind=0xff;
	            eventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4+4 +((unsigned int)4)*(und-3);
	            eventtimetickspointer=(&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks)+(und-3);
	            eventdealflag.bit.b3=1;
						break;
			
						case 0x0606:   
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0006;
	            eventdataaddr=2432L ;
	            eventdatafileadjust=Event_Power_Net_Pointer.ConstantMagnet_P;
	            eventdataaddradjust=30;
	            eventdatalength=30;
	            eventdealflag.bit.b3=1;
						break;
			
						case 0x0703:
						case 0x0704:
						case 0x0705:
						case 0x0706:   
						  eventdealflag.bit.b7=1;
						  tempeventaddr0=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8 +((unsigned int)(und-1))*sizeof(struct DEMAND_DATA_FORM);
	            eventdealflag.bit.b6=1;
	            eventdatakind=0x0102;
	            eventdataaddr=2176L +((unsigned int)32)*(und-3);
	            eventdatafileadjust=*(&Event_Power_Net_Pointer.OverPaADemand_P+(und-1));
	            eventdataaddradjust=6;
	            eventdatalength=15;
	            eventdealflag.bit.b3=1;
						break;
						
						default:
						break;
					}
					if(eventdealflag.intd!=0)
					{
						FeedWatchdog();
						CheckPowerDown();
						if(eventdealflag.bit.b0!=0)
						{
							if((calamphouraddrkind==0)||((calamphouraddrkind==1)&&(eventdatafileadjust<32)))
							{
							  if(EventDataValid_Flag==0xFF)
		  	        {
		  		         SaveEvent0EndAmpHour(calamphourkind);
		  	        }
		            else
		  	        {
		  		         Cal_AmpHour_poweron(eventdataaddr+eventdatafileadjust,calamphouraddrkind);
		  	        }
		  	      }
						}
						
						if(eventdealflag.bit.b7!=0)
						{
							Write_Read_FM24C256 (tempeventaddr0,&Co.b[626],sizeof(struct DEMAND_DATA_FORM),0,1);
						}
						
						if(eventdealflag.bit.b8!=0)
						{
							if(maximbalancerate[tempeventaddr0]==0xffffffff)
                Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L +tempeventaddr0*4,(unsigned char *)&Co.b[606],4,0,1);
              else
                *((unsigned long *)&Co.b[606])=maximbalancerate[tempeventaddr0];
						}
						
						if(eventdealflag.bit.b1!=0)
						{
							PrepEvent0Data(eventdatakind);
		          Write_Read_FM24C256 (eventdataaddr+eventdataaddradjust,&Co.b[300],eventdatalength,0,0);
						}
						
						if(eventdealflag.bit.b6!=0)
						{
							PrepEvent0Data(eventdatakind);
							
							if(eventdatafileadjust<32)
		            Write_File_PdEvent(eventdataaddr+eventdatafileadjust,eventdataaddradjust,eventdatalength,&Co.b[300]);
						}
						
						if(eventdealflag.bit.b2!=0)
						{
							if((eventtimetickskind==0)||((eventtimetickskind==0xff)&&(eventdatafileadjust<32)))
							{
							   SaveEvent0LastTime(eventdataaddr+eventdatafileadjust,eventtimetickskind,&Co.b[600],eventtimeticksaddr,
			                              eventtimetickspointer);
			        }
						}
						
						if(eventdealflag.bit.b3!=0)
						{
							ClearEvent0Flag(unc,(~(0x01<<und)));
						}
						
						if(eventdealflag.bit.b4!=0)
						{
							LostVoltEnergyAdd(tempeventaddr0,0xff);
						}
						
						if(eventdealflag.bit.b5!=0)
						{
							Write_Read_FM24C256 (tempeventaddr1,&Co.b[600],6,0,0);
						}
						
					}
				}
			}
		}		
	} 
  
  for(unc=0;unc<=2;unc++){
	  Event_AmpHour[unc]=0;
	}
	
	CheckPowerDown();
	FeedWatchdog();
	return 0xFF;
} 
 


 
 
 
 
 
 
 
 
 
void LostVoltageEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned char lowvoltflag;
	unsigned int uni;
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
   
  for(und=0;und<3;und++)   
  {
	   if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))		
		   continue;
	   
	   int2ic_addr.byte &= 0xf8;
	   
	   lowvoltflag=EventCriticalVoltage_Flag;
	   if(Meter_Parameter.parameter1.MeterMode[3].bit.b7==1)
	     lowvoltflag=Event_Power_Net_Flag.bit.PowerDownEvent;
	   
  	if((Event_Power_Net_Flag.byte[0]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeLostVoltSV!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeLostVoltSV*1000l) 
	      &&(Curr[und]>Meter_Parameter.event_parameter.JudgeLossVoltage)&&(lowvoltflag==0))
	    {
		    (*((unsigned char*)&Event_N.LostVoltage_A_P+und))++;
		    if((*((unsigned char*)&Event_N.LostVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
		    {
				  (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;
				  
				  CheckPowerDown();
				  MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +255L*und,(0L +und*32L),((unsigned char *)&Event_Power_Net_Pointer.LostVoltage_A_P+und),255);
				  
				  PrepEvent0Data(0x002D);
		      
				  Save_Event_StartData_Eeprom((&Event_Power_Net_Pointer.LostVoltage_A_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                    +und),
                                      ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +255L*und),141,
                                      ((unsigned long *)&Event_Power_Net_Times.LostVoltage_A_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                      +und*4L));
				  
				  SaveEvent0BeginAmpHour(und);
				  SaveLostVoltTime(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L +und*12L,0xFF);
				  SaveLostVoltTime(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6 +und*12L,0);
				  lostvoltagetime[und][0]=This_Month_Data.Energy_Record.EnergyPassMAXTimes[0];
			    lostvoltagetime[und][1]=This_Month_Data.Energy_Record.EnergyPassMAXTimes[1];
			    Write_Read_FM24C256 ( ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4 +2L*und,(unsigned char*)&lostvoltagetime[und][0],2,0,0);
			    
				  Event_Power_Net_Flag.byte[0]|=offset[und];   
				  if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x01) 
				  Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1 +und*16),((unsigned char *)&Event_Report_Status_Times.LostVolt_A_times+und*16));			  
		     }
	     }
	     else
	     {
		     (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;	
	     }
	  }
	  else
	  { 		
	   if((Meter_Parameter.event_parameter.JudgeLostVoltSV==0)||(Volt[und]>Meter_Parameter.event_parameter.JudgeLostVoltEV*1000l)
	     ||(lowvoltflag!=0))
	   {	
		   (*((unsigned char*)&Event_N.LostVoltage_A_P+und))++;
			 if((Meter_Parameter.event_parameter.JudgeLostVoltSV==0)
			   ||((*((unsigned char*)&Event_N.LostVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
			   ||(lowvoltflag!=0))	
		   {
		   	 (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;
			   SaveEvent0EndAmpHour(und);
		     PrepEvent0Data(0x004D);
		     Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +255L*und+141L,&Co.b[300],114,0,0);
		     		  
		     SaveEvent0LastTime_Other((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)              +4L*und,
			   ((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+und));	
		     LostVoltEnergyAdd(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 +und*8L,0xff);
		     SaveLostVoltTime(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6 +und*12L,0xFF);
		     
		     Event_Power_Net_Flag.byte[0]&=(~offset[und]);
		   }
	    }
	    else
	    {  
		   (*((unsigned char*)&Event_N.LostVoltage_A_P+und))=0;		   
	    }
	   }
	   int2ic_addr.byte |= 0x01;
	   FeedWatchdog();
  }
  
}
 

 
void PowerDownEvent_OnCheck(void)
{
	unsigned char unc;
	unsigned char result0;
	unsigned char result1;
	unsigned int uni;
	unsigned long tempunl;
	double long temptimedt;
	
	FeedWatchdog();
	
	if((Event_Power_Net_Flag.bit.Phase3LostVolt==0)&&(Event_Power_Net_Flag.bit.PowerDownEvent==0))
	{
		CheckPowerDown();
		
		result0=0;
		
		for(unc=0;unc<6;unc++)
		  Co.b[400+unc]=*(&Powerdown_Save_Data.date.Year+unc);
	  
	  if((CheckTime(&Co.b[400])!=0xff)) 
	  {
	     result0=1;
	     for(unc=0;unc<6;unc++)
		     Co.b[400+unc]=0xff;
	  }
	  else if(rtc_lossdata_flag==0x5a) 
	  {
	  	result0=1;
	  }
	  else
	  {
	  	temptimedt=ComTime((unsigned char *)&MainSoftDate ,&Co.b[400]);
	  	if(temptimedt>=60)
	  	  result0=1;
	  }
		
		if(result0==1)
		{
			result1=1;
			
			if(Check_PD_Curr_Vality()==1)
			{
				if(PD_curr.Pd_Max_curr*20l>Meter_Parameter.parameter1.EventJudgeIn)
				  result1=2;
			}
			
			CheckPowerDown();
	    if(result1==2)
	    {
	    	MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,1120L ,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,16);
	    	
	    	*((unsigned long *)&Co.b[306])=PD_curr.Aver_curr;
		    for(unc=0;unc<6;unc++)
		    {
	        Co.b[300+unc]=Co.b[400+unc];
	        Co.b[310+unc]=0;
	      }
		    
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.Phase3LostVolt_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,
                                    (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,16,
                                    &Event_Power_Net_Times.Phase3LostVolt_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4 );
			  
			  Event_Power_Net_Flag.bit.Phase3LostVolt=1;
        if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x04)
        Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.AllLostVoltage_times);
	    }
	    else
	    {
  	    MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,96L ,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,12);
  	    
  	    for(unc=0;unc<6;unc++)
		    {
	        Co.b[300+unc]=Co.b[400+unc];
	        Co.b[306+unc]=0;
	      }
  	    
  	    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.PowerDown_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1  ,
                                    (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,12,
                                    &Event_Power_Net_Times.PowerDown_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4  );
	      
	      Event_Power_Net_Flag.bit.PowerDownEvent=1;
          if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x20)
        Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.PowerDown_event_times);
	    }
	    CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
		
	  }
	}
	
	if(Event_Power_Net_Flag.bit.Phase3LostVolt==1)
	{
	  CheckPowerDown();
	  unc=ReadBlock((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4 ,(unsigned char *)&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks,4,0);
    
    if(unc)
    {
	  	Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,&Co.b[300],6,0,1);
	  	
	  	for(unc=0;unc<6;unc++)
	        Co.b[410+unc]=*((unsigned char *)&MainSoftDate +unc);
		  
		  tempunl=Cal_LastTime(&Co.b[300], &Co.b[410]);
		  tempunl=tempunl/60;
		  Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks=Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks+tempunl;	
		}
	}
	
	for(unc=0;unc<sizeof(struct	PD_CURRENT_STRUCT);unc++)
		 *((unsigned char *)&PD_curr+unc)=0;
	FeedWatchdog();
	
}

 

 
unsigned int ProgrammeEvent(unsigned long progman,unsigned long progdata)
{
	unsigned char unc;
	unsigned int uni;
	
	FeedWatchdog();
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==0)
	{
		MoveEventData2Flash(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) ,128L ,(unsigned char *)&Event_Power_Net_Pointer.ProgrammeEvent_P,50);
		
		for(unc=0;unc<6;unc++)
	    Co.b[300+unc]=*((unsigned char *)&MainSoftDate +unc);
	  (*((unsigned long *)&Co.b[306]))=progman;
	  (*((unsigned long *)&Co.b[310]))=progdata;
	  for(unc=0;unc<=8;unc++)
	    (*((unsigned long *)&Co.b[314]+unc))=0xffffffff;
	  
	  Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.ProgrammeEvent_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1 ,
                                 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) ,50,
                                 &Event_Power_Net_Times.ProgrammeEvent_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4 );
	  
	  Event_Power_Net_Flag.bit.ProgrammeEvent=1; 
       if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x01)
       Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6 , (unsigned char *)&Event_Report_Status_Times.Program_event_times);
      
	  Other_Data.ProgramDate=MainSoftDate ; 
    Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10              +4    +4 +5	  *sizeof(struct PASSWORDERR) +1+sizeof(struct DATEANDTIME_DEF)  +sizeof(struct DATEANDTIME_DEF)    +1   ,(unsigned char *)&Other_Data.ProgramDate,sizeof(struct DATEANDTIME_DEF),0,0);   
	}
	else
	{
		Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) +10,&Co.b[304],40,0,1);
		(*((unsigned long *)&Co.b[300]))=progdata;
		Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) +10,&Co.b[300],40,0,0);	
	}
	FeedWatchdog();
	return 0xFFFF;
}

void ProgrammeEventEnd_Check(void){
	
	int2ic_addr.byte &= 0xf8;
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==1){
	  if((!O1ther_Meter_Parameter.WorkRoomState)&&(!Far_Identity_Auth_Ok_Flag)){
		  Event_Power_Net_Flag.bit.ProgrammeEvent=0;
	  }
  }
	int2ic_addr.byte |= 0x01;
}
void ProgrammeEventEnd_Check_Payment(void){
	
	if(Event_Power_Net_Flag.bit.ProgrammeEvent==1)
	{
		 Event_Power_Net_Flag.bit.ProgrammeEvent=0;
  }
	
}

void EventFlagPowerOnInit(void)
{
	unsigned char unc;
	unsigned char clearflagvalue[8]={0x10,0,0,0xc0,0x16,0x40,0x00,0};
	
  for(unc=0;unc<8;unc++)
    Event_Power_Net_Flag.byte[unc]=(Event_Power_Net_Flag.byte[unc]&clearflagvalue[unc]);
  
  for(unc=0;unc<sizeof(struct PDVOLT_STRUCTURE);unc++)
	   *((unsigned char *)&pdvoltdata+unc)=0;
	
	for(unc=0;unc<sizeof(struct	PDOPENCOVER_STRUCTURE)*2;unc++)
		 *(((unsigned char *)&pdopencovercheckdata[0])+unc)=0;
	
	for(unc=0;unc<sizeof(struct	PD_CURRENT_STRUCT);unc++)
		 *((unsigned char *)&PD_curr+unc)=0;
  
  Alarm_Map_Flag[0].bit.b2=Event_Power_Net_Flag.bit.ClockBatteryEvent;
   
  Alarm_Map_Flag[0].bit.b0=Event_Power_Net_Flag.bit.DisplayBatteryEvent;
   
  
  FeedWatchdog();
	
}
 
 
unsigned int ClearMeterRecord(unsigned long progman)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	 
	Copy_ENERGY_TO_CO(410);
	   
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearMeterRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1 ,
                         160L ,106,
                         &Event_Meter_Pro_Times.ClearMeterRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4 );
  
	return 0xFFFF;
}
 

 
 
 
	
void VoltStatisticEvent(void){
	unsigned char unc;
	unsigned char und;
	unsigned long tempminvolt;
	unsigned long tempmaxvolt;
	unsigned long voltstatlimitv[4];
	unsigned char eventflagm[3]={6,6,7};
	unsigned char eventflagn[3][3]={{0x01,0x02,0x04},{0x08,0x10,0x20},{0x01,0x02,0x04}};
	
	voltstatlimitv[0]=Meter_Parameter.event_parameter.VoltageCheck_DownSet*1000l;
	voltstatlimitv[1]=Meter_Parameter.event_parameter.VoltageHealth_DownSet*1000l;
	voltstatlimitv[2]=Meter_Parameter.event_parameter.VoltageHealth_UpSet*1000l;
	voltstatlimitv[3]=Meter_Parameter.event_parameter.VoltageCheck_UpSet*1000l;
	
	for(und=0;und<3;und++)
	{
		if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
	  {			
		  continue;
	  }
		
		if((Volt[und]>voltstatlimitv[2]) && (Volt[und]<voltstatlimitv[3]))
	  {
	        VoltCheck_N[und][0].byte=0x61;
	  }
	  else if((Volt[und]>=voltstatlimitv[1]) && (Volt[und]<=voltstatlimitv[2]))
	  {
	        VoltCheck_N[und][0].byte=0x52;
	  }
	  else if((Volt[und]>voltstatlimitv[0]) && (Volt[und]<voltstatlimitv[1]))
	  {
	        VoltCheck_N[und][0].byte=0x34;
	  }
	  else 
	  {
	        VoltCheck_N[und][0].byte=0x70;
	  }
	  
	  if((!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][1]))) 
	  && (!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][0]))) 
	  &&(!((Event_Power_Net_Flag.byte[eventflagm[und]])&(eventflagn[und][2]))))
	  {
	     if(VoltCheck_N[und][0].byte&0x07)
	     {
		      if((!(Event_B.byte[eventflagm[und]])&(eventflagn[und][1]))
		      ||((VoltCheck_N[und][0].byte&0x07)!=(VoltCheck_N[und][1].byte&0x07)))
		      {
		        *(&Event_N.VoltStatistic_A_P+und)=0;
		        VoltCheck_N[und][1]=VoltCheck_N[und][0];
		      }
		      Event_B.byte[eventflagm[und]]|=eventflagn[und][1];   
		      Event_S.byte[eventflagm[und]]&=(~eventflagn[und][1]);
		      (*(&Event_N.VoltStatistic_A_P+und))+=1;  
		      if((*(&Event_N.VoltStatistic_A_P+und))>30)
		      {
		        if(VoltCheck_N[und][0].bit.b0) 
		        {   
		          Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][1];
		        }
		        else if(VoltCheck_N[und][0].bit.b1) 
		        {   
		          Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][0]; 
		        }
		        else if(VoltCheck_N[und][0].bit.b2) 
		        {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]|=eventflagn[und][2];
		        }
		      }
	     }
	     else
	     {
		      Event_B.byte[eventflagm[und]]&=(~eventflagn[und][1]);   
	     }
	  }
	  else
	  {
	     if(VoltCheck_N[und][0].byte&0x70)
	     {
		     if((!(Event_S.byte[eventflagm[und]]&eventflagn[und][1])) 
		     || ((VoltCheck_N[und][0].byte&0x70)!=(VoltCheck_N[und][1].byte&0x70)))
		     {
		       *(&Event_N.VoltStatistic_A_P+und)=0;
		       VoltCheck_N[und][1]=VoltCheck_N[und][0];
		     }
		     Event_S.byte[eventflagm[und]]|=eventflagn[und][1];  
		     Event_B.byte[eventflagm[und]]&=(~eventflagn[und][1]);
		     if((*(&Event_N.VoltStatistic_A_P+und))<50)
		       (*(&Event_N.VoltStatistic_A_P+und))+=1;     
		     if((*(&Event_N.VoltStatistic_A_P+und))>30)
		     {
		      if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][1])!=0) 
		      && (VoltCheck_N[und][0].bit.b4)) 
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][1]);     
		      }
		      else if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][0])!=0) 
		      &&(VoltCheck_N[und][0].bit.b5))  
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][0]);     
		      }
		      else if(((Event_Power_Net_Flag.byte[eventflagm[und]]&eventflagn[und][2])!=0) 
		      && (VoltCheck_N[und][0].bit.b6)) 
		      {   
		         Event_Power_Net_Flag.byte[eventflagm[und]]&=(~eventflagn[und][2]);     
		      }
		     }
	     }
	     else
	     {
		     Event_S.byte[eventflagm[und]]&=(~eventflagn[und][1]);
	     }
	  }
	  
	}
	 
	 
	for(und=0;und<4;und++)   
	{
		if(((Volt_Region      ==0) || (Volt_Region      ==3))&&(und==1))
		  continue;
		
		if(und<3)
		{
			tempminvolt=Volt[und];
			tempmaxvolt=Volt[und];
		}
		else
		{
			tempminvolt=eventminvolt;
			tempmaxvolt=eventmaxvolt;
		}
		
		if((tempmaxvolt<voltstatlimitv[3])&&(tempminvolt>voltstatlimitv[0])){
			
			if(VoltStat[und].checkvolt[0]==0xFFFFFFFF){
				VoltStat[und].checkvolt[0]=tempminvolt;
				for(unc=0;unc<6;unc++)
	        VoltStat[und].checkvolttime[0][unc]=*((unsigned char *)&MainSoftDate +unc);
			}
			else{
				if(VoltStat[und].checkvolt[0]>tempminvolt){
					VoltStat[und].checkvolt[0]=tempminvolt;
				  for(unc=0;unc<6;unc++)
	          VoltStat[und].checkvolttime[0][unc]=*((unsigned char *)&MainSoftDate +unc);
				}
			}
			
			if(VoltStat[und].checkvolt[1]==0xFFFFFFFF){
				VoltStat[und].checkvolt[1]=tempmaxvolt;
				for(unc=0;unc<6;unc++)
	        VoltStat[und].checkvolttime[1][unc]=*((unsigned char *)&MainSoftDate +unc);
			}
			else{
				if(VoltStat[und].checkvolt[1]<tempmaxvolt){
					VoltStat[und].checkvolt[1]=tempmaxvolt;
				  for(unc=0;unc<6;unc++)
	          VoltStat[und].checkvolttime[1][unc]=*((unsigned char *)&MainSoftDate +unc);
				}
			}
		}
	}
	
	FeedWatchdog();
	
}

void VoltStatisticBill(void)
{
	unsigned char unc;
	unsigned int tempfilename[4]={224L ,256L ,
	                              288L ,2496L };
	
	PrepVoltStatReadData();
	
	for(unc=0;unc<4;unc++)
	{
		Save_SignalPhase_Statistic((&Event_Power_Net_Pointer.VoltStatistic_A_P+unc),
											         (unsigned char*) &VoltStat[unc],
											          tempfilename[unc]);
		*((unsigned long *)&Event_Power_Net_Times.VoltStatistic_A_Times + unc) += 1;
		Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1 +unc,(&Event_Power_Net_Pointer.VoltStatistic_A_P+unc),1,0,0);	
		Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4 + 4 * unc,
			        ((unsigned char *)&Event_Power_Net_Times.VoltStatistic_A_Times+ 4 * unc), 4, 0, 0);	
		Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L +unc*sizeof(struct VoltStatistic_Data),
		       (unsigned char *)&VoltStat[unc],sizeof(struct VoltStatistic_Data),0,0);
		
		FeedWatchdog();
	}
	
}

 
void VoltStatisticFunc(void)
{
	unsigned char unc;
	unsigned int uni;
	
	int2ic_addr.byte &= 0xf8;
	FeedWatchdog();
	
	VoltStatTimeCounter=(VoltStatTimeCounter+1)%60;
	
	if((0x01==MainSoftDate .Day)&&(0x00==MainSoftDate .Hour)&&(0x00==MainSoftDate .Min))
	{
		VoltStatisticBill();
	}
	else
	{
		 
		VoltStat[0].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)
			VoltStat[0].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)
			VoltStat[0].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)
			VoltStat[0].checktime[3]++;
		 
		VoltStat[1].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_B==1)
			VoltStat[1].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_B==1)
			VoltStat[1].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_B==1)
			VoltStat[1].checktime[3]++;
		 
		VoltStat[2].checktime[0]++;
		if(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1)
			VoltStat[2].checktime[1]++;
		if(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1)
			VoltStat[2].checktime[2]++;
		if(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1)
			VoltStat[2].checktime[3]++;
		 
		if((Volt_Region      ==1) || (Volt_Region      ==2))
	  {
		  if(((Event_Power_Net_Flag.byte[6]&0x07)!=0)&&((Event_Power_Net_Flag.byte[6]&0x38)!=0)
		  &&((Event_Power_Net_Flag.byte[7]&0x07)!=0))
		  {
		    VoltStat[3].checktime[0]++;
		  
		    if((Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)&&(Event_Power_Net_Flag.bit.OkVoltageCheck_B==1)
		    &&(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1))
			    VoltStat[3].checktime[1]++;
			  
		    if((Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.UpVoltageCheck_B==1)
		    ||(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1))
			    VoltStat[3].checktime[2]++;
			  
		    if((Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.DownVoltageCheck_B==1)
		    ||(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1))
			    VoltStat[3].checktime[3]++;
		  }
	  }
	  else
	  {
	  	if(((Event_Power_Net_Flag.byte[6]&0x07)!=0)&&((Event_Power_Net_Flag.byte[7]&0x07)!=0))
		  {
		    VoltStat[3].checktime[0]++;
		  
		    if((Event_Power_Net_Flag.bit.OkVoltageCheck_A==1)&&(Event_Power_Net_Flag.bit.OkVoltageCheck_C==1))
			    VoltStat[3].checktime[1]++;
			  
		    if((Event_Power_Net_Flag.bit.UpVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.UpVoltageCheck_C==1))
			    VoltStat[3].checktime[2]++;
			  
		    if((Event_Power_Net_Flag.bit.DownVoltageCheck_A==1)||(Event_Power_Net_Flag.bit.DownVoltageCheck_C==1))
			    VoltStat[3].checktime[3]++;
		  }
	  }
		
		if(VoltStatTimeCounter==0)
		  Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L ,(unsigned char *)&VoltStat[0],192,0,0);
	}
	FeedWatchdog();
	int2ic_addr.byte |= 0x01;
	
}

 
void VoltStatSetDefault(void)
{
	unsigned char unc;
	
	FeedWatchdog();
	
	for(unc=0;unc<4;unc++)
		Clear_SignalPhase_VoltStatistic_Data((unsigned char*)&VoltStat[unc]); 
	
	Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L ,(unsigned char *)&VoltStat[0],sizeof(struct VoltStatistic_Data)*4,0,0);
	
	FeedWatchdog();
}

 
void VoltStatInit(void){
	unsigned char unc;
	unsigned char res;
	unsigned int uni;
	
	FeedWatchdog();
	uni=Crc16l((unsigned char*) &VoltStat[0],192);
	if(uni!=CrcVoltStatData){
	  res=0;
	  for(unc=0;unc<5;unc++){
		  
		  FeedWatchdog();
		  
	    res=Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L ,(unsigned char *)&VoltStat[0],
	    4*sizeof(struct VoltStatistic_Data),0,1);
	  
	    if(res==0xFF)
	      break;
	  
    }
  
    if(res!=0xFF){
  	  for(unc=0;unc<4;unc++)
		    Clear_SignalPhase_VoltStatistic_Data((unsigned char*)&VoltStat[unc]);
    }
    CrcVoltStatData=Crc16l((unsigned char*) &VoltStat[0],192);
  }
	FeedWatchdog();  
}

 
void VoltStatisticCheck(void)
{
	unsigned char unc;
	unsigned int Num_Month;
	
	FeedWatchdog();
	
	if((Powerdown_Save_Data.date.Year!=MainSoftDate .Year)||(Powerdown_Save_Data.date.Month!=MainSoftDate .Month))
	{
		Num_Month=( OB_H(MainSoftDate .Year)-OB_H(Powerdown_Save_Data.date.Year) )*12
		          +OB_H(MainSoftDate .Month)-OB_H(Powerdown_Save_Data.date.Month);
	}
	else
	{
		Num_Month=0;
	}
	if(Num_Month>0)
	{
		if(Num_Month>14)
		{
		  	Num_Month=14;
		}
		for(unc=0;unc<Num_Month;unc++)
		{
			CheckPowerDown();
			VoltStatisticBill();
		}
	}
}
 
 
 
 
 
 
void Save_SignalPhase_Statistic(unsigned char* Statistic,
											    unsigned char* DataBuff,
											    unsigned int FOffset)
{
	unsigned int uni;
       ClearEvent_EventBegin(Statistic, FOffset); 
	FeedWatchdog();
	CheckPowerDown();
	if((*(Statistic))<31)
		(*(Statistic))++;
	else
		*(Statistic)=0;
	uni=FOffset+(*(Statistic));
	Write_File(uni,0,48,DataBuff);
	Clear_SignalPhase_VoltStatistic_Data(DataBuff);
}

 
 
 
 
void Clear_SignalPhase_VoltStatistic_Data(unsigned char*  SignaPhase)
{
	unsigned int uni,BuffSize;
	unsigned char* TempStatictis;

	TempStatictis = SignaPhase;
	BuffSize =	sizeof(struct VoltStatistic_Data);
	for(uni=0;uni < BuffSize; uni++)
	{
		if(uni <16)
			*(TempStatictis + uni) = 0;
		else
			*(TempStatictis + uni) = 0xFF;
	}
}
 
 
 
 
 
 
 
 
 
void LostCurrentEvent(void)
{
	unsigned int uni;	
	unsigned char und;		
  unsigned char offset1[3]= {1,0,0};	
  unsigned char offset2[3]= {2,2,1};			
  unsigned char offset3[3]= {0x20,0x40,0x80};
	
	for(und=0;und<3;und++)
	{
		if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
		{		
			continue;
		}
		
		int2ic_addr.byte &= 0xf8;
		
		if((Event_Power_Net_Flag.byte[0]&offset3[und])==0)
		{
	     if((Meter_Parameter.event_parameter.JudgeLostCurr_I[0]!=0)&&(Curr[und]<Meter_Parameter.event_parameter.JudgeLostCurr_I[0])
	       &&(eventmaxcurr>Meter_Parameter.event_parameter.JudgeLostCurr_I[1])
	       &&(Volt[und]>Meter_Parameter.event_parameter.JudgeLostCurrSV*1000l))
	     {	
		     (*((unsigned char *)&Event_N.LostCurrent_A_P+und))++;
		     if((*((unsigned char *)&Event_N.LostCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeLostCurr_T)
		     {
				   (*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
				   
				   Save_Event_StartData_Flash((&Event_Power_Net_Pointer.LostCurrent_A_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                 +und),
                                      (320L +und*32L),0,141,0x002D,
                                      ((unsigned long *)&Event_Power_Net_Times.LostCurrent_A_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4 +und*4L));
				   
				   Event_Power_Net_Flag.byte[0]|=offset3[und];   
				   if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x08)     
				   Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 +und*16),((unsigned char *)&Event_Report_Status_Times.LossCurr_A_times+und*16));
		   }
	   }
	   else
	   {
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
	   }
	}
	else
	{
	   if((Curr[und]>=Meter_Parameter.event_parameter.JudgeLostCurr_I[0])||(Meter_Parameter.event_parameter.JudgeLostCurr_I[0]==0))
	   {
			(*((unsigned char *)&Event_N.LostCurrent_A_P+und))++;
			if(((*((unsigned char *)&Event_N.LostCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeLostCurr_T)
			||(Meter_Parameter.event_parameter.JudgeLostCurr_I[0]==0))
			{
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
			  
			  Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.LostCurrent_A_P+und)),
                                 (320L +und*32L),141,102,0x000D,
                                 ((unsigned long *)&Event_Power_Net_Timeticks.LostCurrent_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                      +4L*und));
			  				
				Event_Power_Net_Flag.byte[0]&=(~offset3[und]);   
			}
	   }
	   else
	   {
				(*((unsigned char *)&Event_N.LostCurrent_A_P+und))=0;
	   }
	}
	int2ic_addr.byte |=0x01;
	FeedWatchdog();
	}
	
}
 

 
 
void BreakPhaseEvent(void){
	unsigned char unc;
	unsigned char und;
	unsigned int uni;
	unsigned char offset[3]= {0x01,0x02,0x04};
	
	 
	for(und=0;und<3;und++)
	{
	  if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))		
		  continue;   
	  
	  int2ic_addr.byte &= 0xf8;
	  
  	if((Event_Power_Net_Flag.byte[1]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeBreakPhaseV!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeBreakPhaseV*1000l)
	      &&(Curr[und]<Meter_Parameter.event_parameter.JudgeBreakPhaseI)
	    	&&(EventCriticalVoltage_Flag==0))	    
	    {
			  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))++;
	   	  if((*((unsigned char *)&Event_N.BreakPhase_A_P+und))>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
	   	  {
				  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
				  
				  Save_Event_StartData_Flash((&Event_Power_Net_Pointer.BreakPhase_A_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L            +und),
                                     (416L +und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)         +und*4L));
				  
				  SaveEvent0BeginAmpHour(9+und);
				  
				  Event_Power_Net_Flag.byte[1]|=offset[und];   
				  if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x80)   	  
				  Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1 +und*16),((unsigned char *)&Event_Report_Status_Times.BreakPhase_A_event_times+und*16));
	   	  }
	    }
	    else
	    {
	   	 (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
	    }
	  }
	  else
	  {
	   if((Meter_Parameter.event_parameter.JudgeBreakPhaseV==0)||(Volt[und]>=Meter_Parameter.event_parameter.JudgeBreakPhaseV*1000l)
	     ||(Curr[und]>=Meter_Parameter.event_parameter.JudgeBreakPhaseI)||(EventCriticalVoltage_Flag!=0))	   
	   {	
			 (*((unsigned char *)&Event_N.BreakPhase_A_P+und))++;
	   	 if((Meter_Parameter.event_parameter.JudgeBreakPhaseV==0)
	   	   ||((*((unsigned char *)&Event_N.BreakPhase_A_P+und))>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
	   	 	 ||(EventCriticalVoltage_Flag!=0))			
			 {
				(*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;	
				
				 SaveEvent0EndAmpHour(9+und);
				 Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P+und)),
                                  (416L +und*32L),141,114,0x004D,
                                  ((unsigned long *)&Event_Power_Net_Timeticks.BreakPhase_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4    +4L*und));
							
				 Event_Power_Net_Flag.byte[1]&=(~offset[und]);   
			 }
	    }
	    else
	    {
	   	  (*((unsigned char *)&Event_N.BreakPhase_A_P+und))=0;
	    }
	   }
	   int2ic_addr.byte |= 0x01;
	   FeedWatchdog();
	}
	
}
 
 
void VoltReverseEvent(void)
{
  int2ic_addr.byte &= 0xf8;
  if(Event_Power_Net_Flag.bit.VoltageReserve==0)
	{
	   if((flag_communication_with_measuring_board.bit.b6    !=0)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage)&&(EventCriticalVoltage_Flag==0))
	   {
		   Event_N.VoltageReserve_P++;
		   if(Event_N.VoltageReserve_P>=60)
		   {
		     Event_N.VoltageReserve_P=0;
			   
			   Save_Event_StartData_Flash((&Event_Power_Net_Pointer.VoltageReserve_P),(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1  ,
                                    512L ,0,102,0x000D,
                                   (&Event_Power_Net_Times.VoltageReserve_Times),(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4    );
			   
			   Event_Power_Net_Flag.bit.VoltageReserve=1;
         if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x01)   	    
         Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 ,(unsigned char *)&Event_Report_Status_Times.VoltReverse_times);
		   }
	   }
	   else
	   {
		   Event_N.VoltageReserve_P=0;
	   }
	}
	else
	{
	   if(((flag_communication_with_measuring_board.bit.b6    ==0)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage))
	   ||(EventCriticalVoltage_Flag!=0))
	   {
		   Event_N.VoltageReserve_P++;
		   if((Event_N.VoltageReserve_P>=60)||(EventCriticalVoltage_Flag!=0))
		   {
		     Event_N.VoltageReserve_P=0;
			   
			   Save_Event_EndData_Flash(Event_Power_Net_Pointer.VoltageReserve_P,
                                  512L ,102,102,0x000D,
                                 ((unsigned long *)&Event_Power_Net_Timeticks.VoltageReserve_Times_Ticks),(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4 );
			   				 
         Event_Power_Net_Flag.bit.VoltageReserve=0;
		   }
	   }
	   else
	   {
		   Event_N.VoltageReserve_P=0;
	   }
	}
	
	int2ic_addr.byte |= 0x01;
	FeedWatchdog();
	
}
 

 
void OverDemandEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int  uni;
	unsigned char eventflag[6]={1,1,7,7,7,7};
	unsigned char offset[6]={0x40,0x80,0x08,0x10,0x20,0x40};
	unsigned int  eventfilename[6]={544L ,576L ,
	              2176L ,2208L ,2240L ,2272L };
	unsigned long overdemandjudgep;
	
	for(und=0;und<6;und++)
	{
		
	  int2ic_addr.byte &= 0xf8;
	  
	  if(und<2)
	    overdemandjudgep=Meter_Parameter.event_parameter.JudgeOverDemandP*100l;
	  else
	    overdemandjudgep=Meter_Parameter.event_parameter.JudgeOverDemandN*100l;
	  
	  if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])==0)
	  {
	  	if((overdemandjudgep!=0)&&(Last_Average_Value[und][0]>overdemandjudgep))
	    {
	    	(*(&Event_N.OverPaADemand_P+und))++;
	    	if((*(&Event_N.OverPaADemand_P+und))>=Meter_Parameter.event_parameter.JudgeOverDemandT)
	    	{
	    	  (*(&Event_N.OverPaADemand_P+und))=0;
	    	
	    	  overdemandmaxdemand[und].Demand=Last_Average_Value[und][0];
		      for(unc=0;unc<5;unc++)
	           overdemandmaxdemand[und].time[unc]=*((unsigned char *)&MainSoftDate +unc);
	        Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8 +((unsigned int)und)*sizeof(struct DEMAND_DATA_FORM),
	        (unsigned char *)&overdemandmaxdemand[und],sizeof(struct DEMAND_DATA_FORM),0,0);
	        
			    Save_Event_StartData_Flash((&Event_Power_Net_Pointer.OverPaADemand_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1 +((unsigned int)und)),
                                      eventfilename[und],0,6,0x0001,
                                     (&Event_Power_Net_Times.OverPaADemand_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4  +und*4L));
			  
			    Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]|offset[und];
          if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x40)
          Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.OverDemand_times);
			  }
	    }
	    else
	    {
	    	(*(&Event_N.OverPaADemand_P+und))=0;
	    }
	  }
	  else
	  {
	  	if((overdemandjudgep==0)||(Last_Average_Value[und][0]<=overdemandjudgep))
	  	{
	  		(*(&Event_N.OverPaADemand_P+und))++;
	  		if(((*(&Event_N.OverPaADemand_P+und))>=Meter_Parameter.event_parameter.JudgeOverDemandT)||(overdemandjudgep==0))
	    	{
	  		  (*(&Event_N.OverPaADemand_P+und))=0;
	  		
	  		  if((*(&Event_Power_Net_Pointer.OverPaADemand_P+und))>31)
		     	  (*(&Event_Power_Net_Pointer.OverPaADemand_P+und))=0;
		      uni=eventfilename[und]+(*(&Event_Power_Net_Pointer.OverPaADemand_P+und));
		      *((unsigned long *)&Co.b[626])=overdemandmaxdemand[und].Demand;
		      for(unc=0;unc<5;unc++)
	           Co.b[630+unc]=overdemandmaxdemand[und].time[unc];
	        PrepEvent0Data(0x0101);
		      Write_File(uni,6,15,&Co.b[300]);
		    
          Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]&(~offset[und]);
        }
	  	}
	  	else
	  	{
	  		if(overdemandmaxdemand[und].Demand<Last_Average_Value[und][0])
	  		{
	  			overdemandmaxdemand[und].Demand=Last_Average_Value[und][0];
		      for(unc=0;unc<5;unc++)
	           overdemandmaxdemand[und].time[unc]=*((unsigned char *)&MainSoftDate +unc);
	        Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8 +((unsigned int)und)*sizeof(struct DEMAND_DATA_FORM),
	        (unsigned char *)&overdemandmaxdemand[und],sizeof(struct DEMAND_DATA_FORM),0,0);
	  		}
	  		(*(&Event_N.OverPaADemand_P+und))=0;
	  	}
	  }
	  
	  int2ic_addr.byte |= 0x01;
	  FeedWatchdog();
	}
	
}


void PrepOverDemandFirstEventData(unsigned long tempunl)
{
	unsigned char eventflag;
	unsigned char offset;
	unsigned int  eventfilename;
	unsigned char und;
	unsigned char unc;
	
	switch(tempunl)
	{
			case 0x03120101:
			 eventflag=1;
			 offset=0x40;
			 eventfilename=544L ;
			break;
			case 0x03120201:
			 eventflag=1;
			 offset=0x80;
			 eventfilename=576L ;  
			break;
			case 0x03120301:
			 eventflag=7;
			 offset=0x08;
			 eventfilename=2176L ;
			break;
			case 0x03120401:
			 eventflag=7;
			 offset=0x10;
			 eventfilename=2208L ;  
			break;
			case 0x03120501:
			 eventflag=7;
			 offset=0x20;
			 eventfilename=2240L ;
			break;
			case 0x03120601:
			 eventflag=7;
			 offset=0x40;
			 eventfilename=2272L ;  
			break;
	}
	und=(unsigned char)((tempunl>>8)&0xff);
	und--;
	
	if((*(&Event_Power_Net_Pointer.OverPaADemand_P+und))>31)
		(*(&Event_Power_Net_Pointer.OverPaADemand_P+und))=0;
	eventfilename=eventfilename+(*(&Event_Power_Net_Pointer.OverPaADemand_P+und));
	
	Read_File(eventfilename,0,21,&TempEventData[0]);
		
	if((Event_Power_Net_Flag.byte[eventflag]&offset)!=0)
	{
	  *((unsigned long *)&Co.b[626])=overdemandmaxdemand[und].Demand;
		for(unc=0;unc<5;unc++)
	    Co.b[630+unc]=overdemandmaxdemand[und].time[unc];
	  PrepEvent0Data(0x0101);
	  for(unc=0;unc<6;unc++)
			 Co.b[300+unc]=0;
		for(unc=0;unc<15;unc++)
			 TempEventData[6+unc]=Co.b[300+unc];	
	}
	
}
 

 
 
 
 
 
 
 
 
void PowerReverseEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;	
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
	for(und=0;und<3;und++)
	{
		if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
		{		
			continue;
		}
		
		int2ic_addr.byte &= 0xf8;
		
		if((Event_Power_Net_Flag.byte[2]&offset[und])==0)
		{
		   if((Meter_Parameter.event_parameter.JudgeABCPowerReverseP!=0)
		   &&(Meter_States.Meter_Status2.byte&offset[und])&& (Volt[und]>100000l)
			 &&(Active_power[und+1]>Meter_Parameter.event_parameter.JudgeABCPowerReverseP*100l))
		   {
				
				(*((unsigned char *)&Event_N.PowerReverse_A_P+und))++;
				
				if((*((unsigned char *)&Event_N.PowerReverse_A_P+und))>=Meter_Parameter.event_parameter.JudgeABCPowerReverseT)
				{
					(*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
					
					Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1 +und),
                                     (608L +und*32L),0,102,0x000D,
                                     ((unsigned long *)&Event_Power_Net_Times.PowerReverse_A_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4 +und*4L));
					Event_Power_Net_Flag.byte[2]|=offset[und];
					if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x40)   
					Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1 +und*16),((unsigned char *)&Event_Report_Status_Times.PowerReserve_A_times+und*16));
				}
		   }
		   else
		   {
          (*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
		   }
		}
		else
		{
		   if((((Meter_States.Meter_Status2.byte&offset[und])==0)&& (Volt[und]>100000l))
		   ||(Meter_Parameter.event_parameter.JudgeABCPowerReverseP==0))
		   {			   
				
				(*((unsigned char *)&Event_N.PowerReverse_A_P+und))++;
				
				if(((*((unsigned char *)&Event_N.PowerReverse_A_P+und))>=Meter_Parameter.event_parameter.JudgeABCPowerReverseT)
				||(Meter_Parameter.event_parameter.JudgeABCPowerReverseP==0))
				{
					(*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;
				  
				  Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.PowerReverse_A_P+und)),
                                   (608L +und*32L),102,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.PowerReverse_A_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4 +und*4L));
				  				  
					Event_Power_Net_Flag.byte[2]&=(~offset[und]);			
				}
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.PowerReverse_A_P+und))=0;			   
		   }
		}
	  int2ic_addr.byte |=0x01;
	  FeedWatchdog();	
	}
	
}


void ALLPowerReverseEvent(void)
{
	unsigned int  uni;
	unsigned long judgepowerreversep;
	
	int2ic_addr.byte &= 0xf8;
	
	judgepowerreversep=Meter_Parameter.event_parameter.JudgePowerReverseP*100l;
	
	if(judgepowerreversep==0)
	{
		powerreversetflag[0]=0;
		powerreversetflag[1]=0;
		powerreversetcnt[0]=0;
		powerreversetcnt[1]=0;
		eventstatusinfo.bit.powertreverse=0;
		return;
	}
	
	if((Meter_States.Meter_Status2.bit.ActiveDirection_T==0)&&(Active_power[0]>judgepowerreversep))
	{
		powerreversetcnt[0]++;
		powerreversetcnt[1]=0;
		if(powerreversetcnt[0]>=Meter_Parameter.event_parameter.JudgePowerReverseT)
		{
			powerreversetflag[0]=1;
			powerreversetcnt[0]=0;
		}
	}
	else if((Meter_States.Meter_Status2.bit.ActiveDirection_T==1)&&(Active_power[0]>judgepowerreversep))
	{
		powerreversetcnt[0]=0;
		powerreversetcnt[1]++;
		if(powerreversetcnt[1]>=Meter_Parameter.event_parameter.JudgePowerReverseT)
		{
			powerreversetflag[0]=0xff;
			powerreversetcnt[1]=0;
		}
	}
	else
	{
		powerreversetcnt[0]=0;
		powerreversetcnt[1]=0;
	}
	
	if((powerreversetflag[0]!=0)&&(powerreversetflag[1]!=0)&&(powerreversetflag[0]!=powerreversetflag[1]))
	{
		Save_Event_StartData_Flash(&Event_Power_Net_Pointer.PowerReverse_T_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1      ,
                                2400L ,0,103,0x040D,
                                &Event_Power_Net_Times.PowerReverse_T_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4    );
                                
		eventstatusinfo.bit.powertreverse=0;
		if(powerreversetflag[0]==0xff)
		  eventstatusinfo.bit.powertreverse=1;
       if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x02)
            {
		EventReportState_Expand(2, 3,0);
		Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 ,(unsigned char *)&Event_Report_Status_Times.TotalPowerReverse_times);
            }
	}
	
	if((powerreversetflag[0]==0xff)&&(powerreversetflag[1]==0))
	{
		  eventstatusinfo.bit.powertreverse=1;
	}
	
	powerreversetflag[1]=powerreversetflag[0];
	
	FeedWatchdog();
	int2ic_addr.byte |=0x01;
}
 
 
unsigned int AdjustTimeRecord(unsigned long progman)
{
	
	(*((unsigned long *)&Co.b[400]))=progman;
        
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.AdjustTimeRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1 ,
                         704L ,16,
                         &Event_Meter_Pro_Times.AdjustTimeRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4 );
  		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x10)
  		 {
  		 EventReportState_Expand(0, 4, 0);
  		 Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.AdjustTime_event_times);
  		 }
  
	return 0xFFFF;
}
 

 
unsigned int ClearDemandRecord(unsigned long progman)
{
	unsigned char unc;
	unsigned int uni;
	
	for(unc=0;unc<226;unc++)
	{
	  Co.b[400+unc]=0xFF;
	}
	for(unc=0;unc<=5;unc++)
	{
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	}
	(*((unsigned long *)&Co.b[406]))=progman;
	(*((unsigned long *)&Co.b[410]))=This_Month_Data.Demand_Record.Demand.Plus_Active[0].Demand;
	(*((unsigned long *)&Co.b[414]))=This_Month_Data.Demand_Record.Demand.Nega_Active[0].Demand;
	(*((unsigned long *)&Co.b[418]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[0][0].Demand;
	(*((unsigned long *)&Co.b[422]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[1][0].Demand;
	(*((unsigned long *)&Co.b[426]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[2][0].Demand;
	(*((unsigned long *)&Co.b[430]))=This_Month_Data.Demand_Record.Demand.Quad_Reactive[3][0].Demand;
	for(unc=0;unc<=4;unc++)
	{
	  Co.b[506+unc]=This_Month_Data.Demand_Record.Demand.Plus_Active[0].time[unc];
	  Co.b[511+unc]=This_Month_Data.Demand_Record.Demand.Nega_Active[0].time[unc];
	  Co.b[516+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[0][0].time[unc];
	  Co.b[521+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[1][0].time[unc];
	  Co.b[526+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[2][0].time[unc];
	  Co.b[531+unc]=This_Month_Data.Demand_Record.Demand.Quad_Reactive[3][0].time[unc];
	}
	 
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearDemandRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1 ,
                         736L ,226,
                         &Event_Meter_Pro_Times.ClearDemandRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4 );
 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x04)
 {
  EventReportState_Expand(0, 2, 0);
  Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.Demand_clear_times);
 }
	return 0xFFFF;
}
 

 
unsigned int ClearEventRecord(unsigned long progman,unsigned long progflag)
{
	unsigned char unc;
	unsigned int uni;
	
	show_clear_char();	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	(*((unsigned long *)&Co.b[410]))=progflag;
  
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ClearEventRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1 ,
                          768L ,14,
                          &Event_Meter_Pro_Times.ClearEventRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4 );
	
	return 0xFFFF;
}
 

 
unsigned int ProgWeekRecord(unsigned long progman,unsigned char progoldvalue)
{
	unsigned char unc;
	unsigned int uni;
	
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	Co.b[410]=progoldvalue;
	     
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgWeekRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1 ,
                         800L ,11,
                         &Event_Meter_Pro_Times.ProgWeekRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4 );
      if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x80) 
      {
      EventReportState_Expand(0, 7, 0);
      Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1   + 1   + 1 , (unsigned char *)&Event_Report_Status_Times.ProgWeek_times);
      }
	return 0xFFFF;
}
 

 
 
unsigned int ProgAEMode_NEMode1_NEMode2_Record(unsigned long progman,unsigned char  progoldvaluep,unsigned char sort)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char * Epointer;
	unsigned int EOffset,EEROM1,EEROM2;
	unsigned long * Temp_times;
	unsigned char offset[3]={0x02,0x04,0x08};
	
	Temp_times=((unsigned long*)&Event_Meter_Pro_Times.ProgAEModeRecord_Times+sort);
	EEROM1=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1 +sort;
	EEROM2=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4 +sort*4L;
	Epointer=((unsigned char*)&Event_Meter_Pro_Pointer.ProgAEModeRecord_P+sort);
	EOffset=832L +sort*32L;
	
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	Co.b[410]=(progoldvaluep);
	
	Save_Record_Data_Flash(Epointer,EEROM1,
                         EOffset,11,
                         Temp_times,EEROM2);
      if(((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x02) &&(0==sort)) 
        ||((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x04) &&(1==sort))
        ||((Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x08) &&(2==sort)))
      {
      EventStatus_flag.byte[1] |= offset[sort];
      Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L +1),(unsigned char *)&EventStatus_flag.byte[1],1,0,0);
      Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1   + 1   + 1  + 1  + 1 + sort), ((unsigned char *)&Event_Report_Status_Times.ProgAEMode_times + sort));
      }
	return 0xFFFF;
}

 
unsigned int ProgBillDayRecord(unsigned long progman,unsigned char * progoldvaluep)
{
	unsigned char unc;
	unsigned int uni;
  
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	for(unc=0;unc<=5;unc++)
	  Co.b[410+unc]=*(progoldvaluep+unc);
	   
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgBillDayRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1 ,
                         928L ,16,
                         &Event_Meter_Pro_Times.ProgBillDayRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4 );
if(Meter_Parameter.parameter1.EventReportMode.byte[7] & 0x10) 
{
  EventReportState_Expand(1, 4, 0);
  Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1   + 1   + 1  + 1  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.ProgBillDay_times);
}
	return 0xFFFF;
}
 

 
unsigned int ProgYearSlotRecord(unsigned long progman)
{
	unsigned char unc;
	unsigned int uni;
  
	for(unc=0;unc<=5;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[406]))=progman;
	FeedWatchdog();
	Write_Read_FM24C256 (0+10+24*9     ,&Co.b[410],42,0,1);
	FeedWatchdog();
	Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT) ,&Co.b[452],42,0,1);
  if(Comm_DailyOrYear_Slot==1||Comm_DailyOrYear_Slot==2)
  {
     for(unc=0;unc<42;unc++)
       Co.b[410+unc+(Comm_DailyOrYear_Slot-1)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
	 
  Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ProgYearSlotRecord_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1 ,
                         960L ,94,
                         &Event_Meter_Pro_Times.ProgYearSlotRecord_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4 );
  if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x40) 
  {
  EventReportState_Expand(0, 6, 0);
  Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1   + 1 , (unsigned char *)&Event_Report_Status_Times.ProgYearSlot_times);
  }
	return 0xFFFF;
}
 

 
unsigned int ProgDailySlotRecord(unsigned long progman){
	unsigned char unc=0;
	unsigned int uni=0;

	ClearEvent_EventBegin((unsigned char *)&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P, 
						    2016L ); 
	FeedWatchdog();
	if(Event_Meter_Pro_Pointer.ProgDailySlotRecord_P<31)
		Event_Meter_Pro_Pointer.ProgDailySlotRecord_P++;
	else
		Event_Meter_Pro_Pointer.ProgDailySlotRecord_P=0;
	for(unc=0;unc<=5;unc++)
	  Co.b[300+unc]=*((unsigned char *)&MainSoftDate +unc);
	(*((unsigned long *)&Co.b[306]))=progman;
	Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT) ,&Co.b[310],210,0,1);
    if((Comm_DailyOrYear_Slot>0)&&(Comm_DailyOrYear_Slot<=5))
    {
        for(unc=0;unc<42;unc++)
            Co.b[310+unc+(Comm_DailyOrYear_Slot-1)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
    }
	 
	uni=2016L +Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,220,&Co.b[300]);
  FeedWatchdog();
  Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT) +210,&Co.b[300],126,0,1);
  if((Comm_DailyOrYear_Slot>5)&&(Comm_DailyOrYear_Slot<=8))
  {
        for(unc=0;unc<42;unc++)
            Co.b[300+unc+(Comm_DailyOrYear_Slot-6)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
  Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT) ,&Co.b[426],126,0,1);
  if((Comm_DailyOrYear_Slot>8)&&(Comm_DailyOrYear_Slot<=11))
  {
        for(unc=0;unc<42;unc++)
            Co.b[426+unc+(Comm_DailyOrYear_Slot-9)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
   
  uni=2016L +32L+Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,252,&Co.b[300]);
  FeedWatchdog();
  Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT) +126,&Co.b[300],210,0,1);
  if((Comm_DailyOrYear_Slot>11)&&(Comm_DailyOrYear_Slot<=16))
  {
        for(unc=0;unc<42;unc++)
            Co.b[300+unc+(Comm_DailyOrYear_Slot-12)*42]=Comm_Firrespon_SecDispos_Buff[unc];                
  }
   
  uni=2016L +64L+Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
  FeedWatchdog();
  Write_File(uni,0,210,&Co.b[300]);
  FeedWatchdog();
  	 
	Save_EventTimesANDPointer_4byte((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1+1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4+4 ,
	((unsigned char *)&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P),
	(&Event_Meter_Pro_Times.ProgDailySlotRecord_Times)); 
   
   
   
	FeedWatchdog();
  		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x20)
  		 {
  		 EventReportState_Expand(0, 5, 0);
  		 Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.ProgDailySlot_times);
  		 }
	return 0xFFFF;
}
 

 
 





void OpenBoxCoverEvent_Check(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[2]= {0x40,0x80};	
	unsigned int Filename[2]= {192L ,992L };	  
	
	
	FeedWatchdog();
	
	for(und=0;und<2;und++)
	{
	  int2ic_addr.byte &= 0xf8;
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)			
	    {
             if(((und==0)&&(p8_addr.bit.b3				  ==0))||((und==1)&&(p2_addr.bit.b5				  ==0)))
             {
                 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))++;
		   if((*((unsigned char *)&Event_N.OpenCoverEvent_P+und))>1)
		   {
		      *((unsigned char *)&Event_N.OpenCoverEvent_P+und)=0;
		      
		      MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +und*60L,Filename[und],((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P + und),60);
				  
				  PrepEvent0Data(0x0005);
		      
		      Save_Event_StartData_Eeprom(((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1 +und),
                                      ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +und*60L),30,
                                      ((unsigned long *)&Event_Power_Net_Times.OpenCoverEvent_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4 +und*4L));
		      
		      Event_Power_Net_Flag.byte[3]|=offset[und];   
		      if(((Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x04)&&(0==und))  
		      ||((Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x08)&&(1==und)))
		         Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1 +und),((unsigned char *)&Event_Report_Status_Times.Open_Meter_Cover_times+und));
		   }
             }
             else
             {
		  (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
             }
	    }
	else
	    {
		  if(((und==0)&&(p8_addr.bit.b3				  ==1))||((und==1)&&(p2_addr.bit.b5				  ==1)))
		   {
			(*((unsigned char *)&Event_N.OpenCoverEvent_P+und))++;
			if((*((unsigned char *)&Event_N.OpenCoverEvent_P+und))>1)
			{
				 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
				 PrepEvent0Data(0x0005);
				 Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +und*60L+30L,&Co.b[300],30,0,0);
				 Event_Power_Net_Flag.byte[3]&=(~offset[und]);   
			}
		   }
                else
                {
				 (*((unsigned char *)&Event_N.OpenCoverEvent_P+und))=0;
                }
	    }
    	 int2ic_addr.byte |=0x01;
	 FeedWatchdog();
	}
}
 

 
 
 
 
 
 
 
 
 
void OverVoltageEvent(void)
{
	unsigned char unc;
	unsigned char und;	
	unsigned int uni;
  unsigned char offset[3]= {0x08,0x10,0x20};
	
	for(und=0;und<3;und++)
	{
	  if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
	  {		
		  continue;
	  }
	  
	  int2ic_addr.byte &= 0xf8;
	  
	  if((Event_Power_Net_Flag.byte[2]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeOverVolt_V!=0)&&(Volt[und]>Meter_Parameter.event_parameter.JudgeOverVolt_V*1000l))
	    {
			
			  (*((unsigned char *)&Event_N.OverVoltage_A_P+und))++;
			  
			  if((*((unsigned char *)&Event_N.OverVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverVoltT)
			  {
				  *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
				  
				  Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1 +und),
                                     (1024L +und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.OverVoltage_A_Times+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4 +und*4L));
				  SaveEvent0BeginAmpHour(6+und);
				  Event_Power_Net_Flag.byte[2]|=offset[und];
			        if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x04)  			  
				  Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 +und*16),((unsigned char *)&Event_Report_Status_Times.OverVolt_A_times+und*16));
			}
	   }
	   else
	   {
	   	  *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
		 }
	 }
	 else
	 {
	   if((Volt[und]<=Meter_Parameter.event_parameter.JudgeOverVolt_V*1000l)||(Meter_Parameter.event_parameter.JudgeOverVolt_V==0))
	   {
				
			 (*((unsigned char *)&Event_N.OverVoltage_A_P+und))++;
			
			 if(((*((unsigned char *)&Event_N.OverVoltage_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverVoltT)
			 ||(Meter_Parameter.event_parameter.JudgeOverVolt_V==0))
			 {
				 *((unsigned char *)&Event_N.OverVoltage_A_P+und)=0;
				 
				 SaveEvent0EndAmpHour(6+und);
				 Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.OverVoltage_A_P+und)),
                                  (1024L +und*32L),141,114,0x004D,
                                  ((unsigned long *)&Event_Power_Net_Timeticks.OverVoltage_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4 +und*4L));				
				 
				 Event_Power_Net_Flag.byte[2]&=(~offset[und]);
			 }
	   }
	   else
	   {
			   (*((unsigned char *)&Event_N.OverVoltage_A_P+und))=0;	
	   }
	 }
	 int2ic_addr.byte |=0x01;
	 FeedWatchdog();
	}
	
}
 
 
const struct VOLTCHECK_STRU  VoltCheck_ABC[]={
  {(unsigned char*)&VoltCheck_N[0][0].byte,(unsigned char*)&VoltCheck_N[0][1].byte},
  {(unsigned char*)&VoltCheck_N[1][0].byte,(unsigned char*)&VoltCheck_N[1][1].byte},
  {(unsigned char*)&VoltCheck_N[2][0].byte,(unsigned char*)&VoltCheck_N[2][1].byte},  
};

 
 
 
 
 
unsigned char ClearNewEventRecord(unsigned long cleareventman,unsigned long cleareventflag)
{
	const struct CLEAREVENT_STRU *Event_Node1;
	const struct VOLTCHECK_STRU *Temp_p;	
	union BYTE_BIT   Dispose_clearevent_flag;  
	unsigned int uni=0;
	unsigned char result_findOK=0;
	unsigned char result=0;
	unsigned int   unc=0;
	unsigned char mask=0;
    	union EVENT_REPORT_STATUS ResetEventReportStatus;
        
	Dispose_clearevent_flag.byte=0;
	
	FeedWatchdog();
	CheckPowerDown();	
		for(uni=0;uni<((sizeof(Clearevent_ID))/sizeof(unsigned long));uni++)          
		{
			if(cleareventflag==0xFFFFFFFF)
			{
				result_findOK=0x11;   
				break;
			}
		 	else if(Clearevent_ID[uni]==cleareventflag)
		 	{
				result_findOK=0x01;   
				Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[uni];
				break;
		 	}			
		}
        
            if(cleareventflag==0xFFFFFFFF)
            {
                for(uni=0; uni<12; uni++)
                {
                ResetEventReportStatus.byte[uni]=0x00;
                }
                ResetEventReportStatus.byte[10]=0x0A; 
                Clear_EventReportStatus_And_Times(ResetEventReportStatus);
   
                for(uni=0 ; uni<5; uni++)
                {
                if(0 != EventStatus_flag.byte[uni])
                {
                EventStatus_flag.byte[uni]=0;
                Write_Read_FM24C256 ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L +uni),(unsigned char *)&EventStatus_flag.byte[uni],1,0,0);
                }
                }
            }
            
		 
		if(result_findOK) 
		{
			 
			for(unc=0;unc<((sizeof(Clearevent_ID))/sizeof(unsigned long));unc++)
			{
					if(result_findOK==0x11)    
					{
						 
						Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[unc];
					}
					Dispose_clearevent_flag.byte=Event_Node1->Dispose_flag;
					 
					if((Dispose_clearevent_flag.bit.b0)==1)    
					{
							 
							CheckPowerDown();  
							result=0xFF;
							if(((Event_Node1->Times)!=(void*)0  )&&((Event_Node1->Ticks)!=(void*)0  ))  
							{
								for(uni=0;uni<((Event_Node1->Length)/4);uni++)
								{
									*((Event_Node1->Times)+uni)=0;  
									*((Event_Node1->Ticks)+uni)=0;  
								}		
							}
							Write_Read_FM24C256 ((Event_Node1->Times_addr),0,(Event_Node1->Length),0,0);
							Write_Read_FM24C256 ((Event_Node1->Ticks_addr),0,(Event_Node1->Length),0,0);
							FeedWatchdog();			
					}
					if((Dispose_clearevent_flag.bit.b1)==1)  
					{
							 
							CheckPowerDown();  
							result=0xFF;
							if(((Event_Node1->Flag)!=(void*)0  ))
							{
								(*(Event_Node1->Flag))&=(~(Event_Node1->Offset));   
								 
							}
		
					}
					if((Dispose_clearevent_flag.bit.b2)==1)   
					{
						 
						result=0xFF;  
						if((Event_Node1->Pointer)!=(void*)0  )
						{
							*(Event_Node1->Pointer)=0;
							Write_Read_FM24C256 ((Event_Node1->Pointer_addr),0,1,0,0);
						}
						 
						 
							FeedWatchdog();
							CheckPowerDown();
							uni=(Event_Node1->Filename_begin);
							Delete_File(uni);
						 
						FeedWatchdog();					
					}
					if((Dispose_clearevent_flag.bit.b3)==1)   
					{
						 
						result=0xFF;
						if((Event_Node1->Times)!=(void*)0  )
						{
							*(Event_Node1->Times)=0; 
						}
						Write_Read_FM24C256 ((Event_Node1->Times_addr),0,4,0,0);		
					}	
					if((Dispose_clearevent_flag.bit.b4)==1)   
					{
						 
						result=0xFF;
						if((Event_Node1->Ticks)!=(void*)0  )
						{
							*(Event_Node1->Ticks)=0; 
							Write_Read_FM24C256 ((Event_Node1->Ticks_addr),0,4,0,0);		
						}
					}					
					if((Dispose_clearevent_flag.bit.b5)==1)   
					{
						 
						CheckPowerDown();   
						Temp_p=( const struct VOLTCHECK_STRU *)&VoltCheck_ABC[Event_Node1->Length];
						result=0xFF;
						mask=(Event_Node1->Offset);
						if((Event_Node1->Flag)!=(void*)0  )
						{
							for(uni=0;uni<3;uni++)     
							{
								(*(Event_Node1->Flag))&=(~mask);   
								mask <<= 1;
							}	
						}
						if(((Temp_p->Flag1)!=(void*)0  )&&((Temp_p->Flag2)!=(void*)0  ))
						{
						*(Temp_p->Flag1)=0;  
						*(Temp_p->Flag2)=0;  	
						}
						Clear_SignalPhase_VoltStatistic_Data((unsigned char*) &VoltStat[(Event_Node1->Length)]);
						Write_Read_FM24C256 ((Event_Node1->Eeprom_addr),(unsigned char *)&VoltStat[(Event_Node1->Length)],48,0,0);
						FeedWatchdog();		
					}
					if((Dispose_clearevent_flag.bit.b6)==1)   
					{
						 
						result=0xFF;
						for(uni=0;uni<36;uni++)  
						  TempEventData[uni]=0xFF;
						Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L ,&TempEventData[0],36,0,0);
						 
						FeedWatchdog();		
					}
					if((Dispose_clearevent_flag.bit.b7)==1)   
					{
						 
						FeedWatchdog();
						for(uni=0;uni<255;uni++)  
						  TempEventData[uni]=0xFF;	
						Write_Read_FM24C256 ((Event_Node1->Eeprom_addr),&TempEventData[0],(Event_Node1->Length),0,0);	
						FeedWatchdog();	
						result=0xFF;
					}
					
					 
					if(result_findOK==0x01)  
					break;
			}
				
		 
                 
		}
		 
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x034200FF))
			CloseOverPowerAlarmSwitch();
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033005FF))
			result=ClearProgDailySlotRecord(cleareventman,cleareventflag);	
			
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x033002FF))
		{
			for(uni=0;uni<sizeof(struct DATEANDTIME_DEF);uni++)  
				*((unsigned char *)&Other_Data.LastClearDemandDateCM+uni)=0;		
			 
			FeedWatchdog();
 	 		Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10              +4    +4 +5	  *sizeof(struct PASSWORDERR) +1+sizeof(struct DATEANDTIME_DEF)  +sizeof(struct DATEANDTIME_DEF)    +1  +sizeof(struct DATEANDTIME_DEF)     ,
				(unsigned char *)&Other_Data.LastClearDemandDateCM,sizeof(struct DATEANDTIME_DEF),0,0);
                        FeedWatchdog(); 
 
 
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x031200FF))
		{
			for(uni=0;uni<4;uni++)
			  (*(&Event_Power_Net_Times.Over1RDemand_Times+uni))=0;			
			Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4 ,(unsigned char *)&Event_Power_Net_Times.Over1RDemand_Times,16,0,0);
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x031000FF))
		{
			Clear_SignalPhase_VoltStatistic_Data((unsigned char*) &VoltStat[3]);
			Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data) ,(unsigned char *)&VoltStat[3],48,0,0);
			FeedWatchdog();
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x210000FF))
		{
			powerreversetflag[0]=0;
	    powerreversetflag[1]=0;
	    powerreversetcnt[0]=0;
	    powerreversetcnt[1]=0;
	    eventstatusinfo.bit.powertreverse=0;
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x03300DFF))
		{
			eventstatusinfo.bit.powerdownopencover=0;
		}
		
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x03300EFF))
		{
			eventstatusinfo.bit.powerdownopenbox=0;
		}
		
       if(cleareventflag==0x1000FFFF)
       {
		     Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 ,0,24,0,0);
	         FeedWatchdog();
       }
    	if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1001FFFF))
			ClearEventAddEnergy(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 );
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1002FFFF))
			ClearEventAddEnergy(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8 );
		if((cleareventflag==0xFFFFFFFF)||(cleareventflag==0x1003FFFF))
			ClearEventAddEnergy(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8 );
		
		if (!clearFlag)
		{
			ClearPaymentEventRecord(cleareventman,cleareventflag);		 
			result=0xFF; 
		}
			
		if(result==0xFF)
		Check_Show_Flash_Data(0xff,0,0xff,0);	
		 
		 if(Meter_Parameter.parameter1.EventReportMode.byte[6] & 0x08)
		 {
		        EventReportState_Expand(0, 3, 0);
                     Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 6  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.Event_clear_times);
		 }
		return result;			
}

 
unsigned char ClearProgDailySlotRecord(unsigned long cleareventman,unsigned long cleareventflag)
{
	
	Delete_File(2016L );
	Delete_File(2016L +32L);
	Delete_File(2016L +64L);
	Event_Meter_Pro_Times.ProgDailySlotRecord_Times=0;
	Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4+4 ,0,4,0,0);
	Event_Meter_Pro_Pointer.ProgDailySlotRecord_P=0;
	Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1+1 ,&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P,1,0,0);
	FeedWatchdog();

	return 0xFF;	
}
 

unsigned char ClearEventAddEnergy(unsigned int eventeepromaddr){
	
	Write_Read_FM24C256 (eventeepromaddr,0,8,0,0);
	FeedWatchdog();
	return 0xFF;
}


 
 
void Phase3LostVoltEvent(void){
	unsigned char unc;
	unsigned char lowvoltflag;
	unsigned int uni;
	
	int2ic_addr.byte &= 0xf8;
	FeedWatchdog();
	
	lowvoltflag=0;
	if(eventmaxvolt*100l<Meter_Parameter.event_parameter.CriticalVoltage*EventUn)
	  lowvoltflag=1;
	
  if(Event_Power_Net_Flag.bit.Phase3LostVolt==0)
	{
	   if((lowvoltflag==1)&&(eventmaxcurr*20>EventIb)
	     &&(Event_Power_Net_Flag.bit.PowerDownEvent==0))
	   {
		   Event_N.Phase3LostVolt_P++;
		   if(Event_N.Phase3LostVolt_P>=60)
		   {
		    Event_N.Phase3LostVolt_P=0;
			  
		    MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,1120L ,(unsigned char *)&Event_Power_Net_Pointer.Phase3LostVolt_P,16);
		    
	      *((unsigned long *)&Co.b[622])=eventavgcurr;
	      PrepEvent0Data(0x0081);
	      
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.Phase3LostVolt_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1 ,
                                    (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,10,
                                    &Event_Power_Net_Times.Phase3LostVolt_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4 );
		    
		    Event_Power_Net_Flag.bit.Phase3LostVolt=1; 
                if(Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x04)
                Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 ,(unsigned char *)&Event_Report_Status_Times.AllLostVoltage_times);
		   }
	    }
	    else
	    {
		   Event_N.Phase3LostVolt_P=0;
	    }
	}
	else
	{
	   if(lowvoltflag==0)
	   {
		   Event_N.Phase3LostVolt_P++;		 
		   if(Event_N.Phase3LostVolt_P>=Meter_Parameter.event_parameter.JudgeLossVoltageSecond)
		   {
		    Event_N.Phase3LostVolt_P=0;
		    
		    PrepEvent0Data(0x0001);
				Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L +10L,&Co.b[300],6,0,0);
				
				SaveEvent0LastTime_Other((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4 ,
			  ((unsigned long *)&Event_Power_Net_Timeticks.Phase3LostVolt_Times_Ticks));
			  				
		    Event_Power_Net_Flag.bit.Phase3LostVolt=0;
		   }
	   }
	   else
	   {
		   Event_N.Phase3LostVolt_P=0;
	   }
	}
	FeedWatchdog();
	if(Event_Power_Net_Flag.bit.PowerDownEvent==0)
	{
	   if((lowvoltflag==1)&&(eventmaxcurr*20<=EventIb)
	   &&(Event_Power_Net_Flag.bit.Phase3LostVolt==0))
	   {
		   Event_N.PowerDown_P++;
		   if(Event_N.PowerDown_P>=60)
		   {
		    Event_N.PowerDown_P=0;
			  
		    MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,96L ,(unsigned char *)&Event_Power_Net_Pointer.PowerDown_P,12);
		    
	      PrepEvent0Data(0x0001);
		    
		    Save_Event_StartData_Eeprom(&Event_Power_Net_Pointer.PowerDown_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1  ,
                                    (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,6,
                                    &Event_Power_Net_Times.PowerDown_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4  );
		    
		    Event_Power_Net_Flag.bit.PowerDownEvent=1;
        if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x20)
        Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1 ,(unsigned char *)&Event_Report_Status_Times.PowerDown_event_times);
		   }
	    }
	    else
	    {
		   Event_N.PowerDown_P=0;
	    }
	}
	else
	{
	   if(lowvoltflag==0)
	   {
		   Event_N.PowerDown_P++;		 
		   if(Event_N.PowerDown_P>=Meter_Parameter.event_parameter.JudgeBreakPhaseSecond)
		   {
		    Event_N.PowerDown_P=0;
		    
		    PrepEvent0Data(0x0001);
	      Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L +6L,&Co.b[300],6,0,0);
	      
		    Event_Power_Net_Flag.bit.PowerDownEvent=0;
		   }
	   }
	   else
	   {
		   Event_N.PowerDown_P=0;
	   }
	}
	
	
	EventCriticalVoltage_Flag=0;
	if((Event_Power_Net_Flag.bit.Phase3LostVolt!=0)||(Event_Power_Net_Flag.bit.PowerDownEvent!=0))
		EventCriticalVoltage_Flag=0xFF;
	
	int2ic_addr.byte |= 0x01;	
	FeedWatchdog();
	
}
 
 
void OverDemandAlarmEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	
	int2ic_addr.byte &= 0xf8;
	if(Meter_Parameter.parameter1.UserClass[0]==2 || Meter_Parameter.parameter1.UserClass[0]==3)
  {
	   if(!Event_Power_Net_Flag.bit.OverPowerAlarm )
	   {
	      if(VoltageGreaterThanThreshold_Flag)
	      {	
	        if(((Last_Average_Value[0][0]>Meter_Parameter.event_parameter.PaADemandLimit*100l)||(Last_Average_Value[1][0]>Meter_Parameter.event_parameter.NeADemandLimit*100l)))
	        {
	        
	           *((unsigned long *)&Co.b[635])=Last_Average_Value[0][0];
	           *((unsigned long *)&Co.b[639])=Last_Average_Value[1][0];
			       Save_Event_StartData_Flash(&Event_Power_Net_Pointer.OverPowerAlarm_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1  ,
                                        1152L ,0,14,0x0201,
                                        (&Event_Power_Net_Times.OverPowerAlarm_Times),(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4  );
			       Event_Power_Net_Flag.bit.OverPowerAlarm=1; 
	   	       
	   	       Output_On_3_In_1_Terminal_Set(5);
	   	       OverPowerAlarmTime=MainSoftDate ;
	        }
	      }
	   }
	   else
	   {
	      if(((Last_Average_Value[0][0]<=Meter_Parameter.event_parameter.PaADemandLimit*100l)&&(Last_Average_Value[1][0]<=Meter_Parameter.event_parameter.NeADemandLimit*100l))
	      ||(!VoltageGreaterThanThreshold_Flag))
	      {
	        Save_Event_EndData_Flash(Event_Power_Net_Pointer.OverPowerAlarm_P,
                                   1152L ,14,6,0x0001,
                                   &Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4        );			
		      Event_Power_Net_Flag.bit.OverPowerAlarm=0;
		      
	   	    Output_On_3_In_1_Terminal_Set(6);
	   	    OverPowerAlarmTime=MainSoftDate ; 
	      }
	   }
	   
	   if(Meter_Parameter.parameter1.UserClass[0]==3)
	   {
	      FeedWatchdog();
	      if(Event_Power_Net_Flag.bit.OverPowerAlarm)
	      {
	          if(!OverPowerAlarmFlag)
	          {    
	              if(ComTime((unsigned char *)&MainSoftDate ,(unsigned char *)&OverPowerAlarmTime)>Meter_Parameter.parameter2.OpenSwitchDelayTime*60l)
	              {
	              	   if(Meter_Parameter.parameter1.MeterMode[1].bit.b4)
	              	   {
	                      OverPowerAlarmFlag=0xff;
	                      Relay_Alarm_SWitch_Flag[1][0] |= 0x01;	 
				                Pre_Payment_Data.OverPowerSw_Time++;	 
	    			            *((unsigned long *)&Co.b[635])=Last_Average_Value[0][0];
	                      *((unsigned long *)&Co.b[639])=Last_Average_Value[1][0];
			                  Save_Event_StartData_Flash(&Event_Meter_Pro_Pointer.OverPowerCloseSwitch_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1+1+1+1  ,
                                                   1184L ,0,14,0x0201,
                                                   &Event_Meter_Pro_Times.OverPowerCloseSwitch_Times,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) );
	                   }
	              }
	          }
	      }
	      else
	      {
	          if(OverPowerAlarmFlag)
	          {
	              if((ComTime((unsigned char *)&MainSoftDate ,(unsigned char *)&OverPowerAlarmTime)>Meter_Parameter.parameter2.CloseSwitchDelayTime*60l) 
	              ||(!VoltageGreaterThanThreshold_Flag))
	              {
	                   CloseOverPowerAlarmSwitch();
	              }
	          }
	      }
	   }
	   else
	   {
	      CloseOverPowerAlarmSwitch();
	   }
  }
  
  if(Meter_Parameter.parameter1.UserClass[0]==1)
	{
	    if(Event_Power_Net_Flag.bit.OverPowerAlarm)
	    {
	      ClearEvent_EventBegin((unsigned char *)&Event_Power_Net_Pointer.OverPowerAlarm_P, 1152L ); 		  
	      Save_Event_EndData_Flash(Event_Power_Net_Pointer.OverPowerAlarm_P,
                                 1152L ,14,6,0x0001,
                                 &Event_Power_Net_Timeticks.OverPowerAlarm_Times_Ticks,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4        );
		    Event_Power_Net_Flag.bit.OverPowerAlarm=0;
	   	  Output_On_3_In_1_Terminal_Set(6);
	   	  OverPowerAlarmTime=MainSoftDate ;
	    } 
	    CloseOverPowerAlarmSwitch();
	}
	
	if(!Meter_Parameter.parameter1.MeterMode[1].bit.b4)
	{
	   CloseOverPowerAlarmSwitch();
	}
	
	int2ic_addr.byte |= 0x01;
	FeedWatchdog();
	
}

void CloseOverPowerAlarmSwitch(void)
{
	if(OverPowerAlarmFlag)
	{  
	   OverPowerAlarmFlag=0; 
	   Relay_Alarm_SWitch_Flag[1][0] &= 0xFE;	 
	}
}

 
 
 
 
 
 
 
 
 
void ClockBatteryDisplayBattery_Event(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[2]= {0x02,0x04};	
  unsigned char offset1[2]= {0x04,0x01};	
		
	FeedWatchdog();

	for(und=0;und<2;und++)
	{
		if((Event_Power_Net_Flag.byte[4]&offset[und])==0)
		{
			if((Alarm_Map_Flag[0].byte&offset1[und])!=0) 
			{
		     Save_Event_StartData_Flash((((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und)),(((((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1+1+1)  +und),
                                    (1216L +32L*und),0,6,0x0001,
                                    ((unsigned long *)&Event_Power_Net_Times.ClockBatteryEvent_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4  +4+4+4  +und*4L));
			   Event_Power_Net_Flag.byte[4]|=offset[und];   
			}
		}
		else
		{
			if((Alarm_Map_Flag[0].byte&offset1[und])==0)
			{
		    if((*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und))>31)
		    	(*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und))=0;
		    uni=1216L +32L*und+(*((unsigned char*)&Event_Power_Net_Pointer.ClockBatteryEvent_P+und));
		    PrepEvent0Data(0x0001);
		    Write_File(uni,6,6,&Co.b[300]);
			  Event_Power_Net_Flag.byte[4]&=(~offset[und]);   
			  if(und==1)
			  {
				  Other_Data.BatteryWorkTime1=0;
				  Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10               ,(unsigned char *)&Other_Data.BatteryWorkTime1,4,0,0);	
			  }
			}
		}
		FeedWatchdog();
	}
	
}
 
 
 
 
void AdjustMeterRecord(void)
{
	unsigned char unc;
	
	if((Event_Power_Net_Flag.bit.AdjustMeterEvent==0)&&(JustMeterFlag==0xFF))
	{
		for(unc=0;unc<5;unc++)
	    Co.b[400+unc]=*((unsigned char *)&JustMeterDateFlag+unc);
	  Co.b[405]=JustMeterDataFlag.byte;
	  
		Save_Record_Data_Flash(&Event_Power_Net_Pointer.AdjustMeterEvent_P,((((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1+1+1) +1+1 ,
                            1280L ,6,
                            &Event_Power_Net_Times.AdjustMeterEvent_Times,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4  +4+4+4 +4+4 );
	  Event_Power_Net_Flag.bit.AdjustMeterEvent=1;
	}
}

void AdjustMeterRecordEndCheck(void){
	
	if(Event_Power_Net_Flag.bit.AdjustMeterEvent==1){
		
		if(ComTime((unsigned char *)&MainSoftDate ,(unsigned char *)&JustMeterDateFlag)>300){
			JustMeterFlag=0;
	    JustMeterDataFlag.byte=0;
	    Event_Power_Net_Flag.bit.AdjustMeterEvent=0;
		}
		
	}
	
}
 
 
int  PrepVoltStatReadData(void){
	unsigned char unc;
	unsigned long tempunl;
	unsigned long tempunl0;
	unsigned long tempunl1;
	unsigned char *tempuncpointer0;
	unsigned char *tempuncpointer1;
	
	for(unc=0;unc<4;unc++){
		
		if(unc<3)
		{
			tempunl1=VoltStat[unc].checktime[1]+VoltStat[unc].checktime[2]+VoltStat[unc].checktime[3];
			tempunl0=VoltStat[unc].checktime[2]+VoltStat[unc].checktime[3];
			tempuncpointer0=(unsigned char *)&VoltStat[unc].voltratebcd[1];
			tempuncpointer1=(unsigned char *)&VoltStat[unc].voltratebcd[0];
		}
		else
		{
			tempunl1=VoltStat[unc].checktime[0];
			tempunl0=VoltStat[unc].checktime[1];
			tempuncpointer0=(unsigned char *)&VoltStat[unc].voltratebcd[0];
			tempuncpointer1=(unsigned char *)&VoltStat[unc].voltratebcd[1];
		}
		
		if(tempunl1!=0){
			tempunl=(tempunl0*10000l)/tempunl1;
			tempunl0=(tempunl0*10000l)%tempunl1;
			tempunl0=(tempunl0*10l)/tempunl1;
			if(tempunl0>=5)
				tempunl++;
			HexToBcd(3,(unsigned char *)&tempunl,tempuncpointer0);
			if(tempunl<=10000l){
				tempunl=10000l-tempunl;
				HexToBcd(3,(unsigned char *)&tempunl,tempuncpointer1);
			}
			else{
				VoltStat[unc].voltratebcd[0]=0xFFFFFFFF;
			  VoltStat[unc].voltratebcd[1]=0xFFFFFFFF;
			}	
		}
		else{
			VoltStat[unc].voltratebcd[0]=0xFFFFFFFF;
			VoltStat[unc].voltratebcd[1]=0xFFFFFFFF;
		}
		
		if(VoltStat[unc].checkvolt[0]==0xFFFFFFFF){
			VoltStat[unc].checkvoltbcd[0]=0xFFFF;
		}
		else{
			tempunl=VoltStat[unc].checkvolt[0]/1000l;
			HexToBcd(2,(unsigned char *)&tempunl,(unsigned char *)&VoltStat[unc].checkvoltbcd[0]);
		}
		if(VoltStat[unc].checkvolt[1]==0xFFFFFFFF){
			VoltStat[unc].checkvoltbcd[1]=0xFFFF;
		}
		else{
			tempunl=VoltStat[unc].checkvolt[1]/1000l;
			HexToBcd(2,(unsigned char *)&tempunl,(unsigned char *)&VoltStat[unc].checkvoltbcd[1]);
		}
	}
	return  0;
}
 
 
void ResetCpuEvent_OnCheck(void)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	  Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.ResetCPU_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)            ,
                         1312L ,6,
                         &Event_Meter_Pro_Times.ResetCPU_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)            );
	
}
 
 
void RunClockErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.RunClockError_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1 ,
                         1920L ,sizeof(struct RUNCLOCKERROR_DATA),
                         &Event_Meter_Pro_Times.RunClockError_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4 );

 if(Meter_Parameter.parameter1.EventReportMode.byte[0] & 0x80)   
    {
    if(!EventStatus_flag.bit.Clock_err )
    {
     EventReportState_Expand(3, 4, 0);  
     if(Event_Report_Status_Times.Clock_err_times !=255)
     {
       Event_Report_Status_Times.Clock_err_times =255;
       Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 ,(unsigned char *)&Event_Report_Status_Times.Clock_err_times);
     }
    }
    }
}
 
 
void PowerUpClockErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.PowerUpClockError_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1 ,
                         1952L ,sizeof(struct POWERUPCLOCKERROR_DATA),
                         &Event_Meter_Pro_Times.PowerUpClockError_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4 );
	
}
 
 
void EepromErrorRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[400+unc]=*((unsigned char *)&MainSoftDate +unc);
	Co.b[405]=Eeprom_Flag.byte;
	
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.EepromErr_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1 ,
                         1984L ,sizeof(struct EEPROMERR_DATA),
                         &Event_Meter_Pro_Times.EepromErr_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4 );
	
}
 
 
void EnergyPassZeroRecord(void)
{
	
	FeedWatchdog();
	
	ClearEvent_EventBegin((unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P
	,3392L     ); 
	
	if(Event_Meter_Pro_Pointer.Energypasszero_P>15)
		Event_Meter_Pro_Pointer.Energypasszero_P=0;
		
	FreezeDateProgram(3392L     +Event_Meter_Pro_Pointer.Energypasszero_P,1, (unsigned char *)&MainSoftDate ); 
       
	if(Event_Meter_Pro_Pointer.Energypasszero_P<=14)
		Event_Meter_Pro_Pointer.Energypasszero_P++;
	else
		Event_Meter_Pro_Pointer.Energypasszero_P=0;
	
	Save_EventTimesANDPointer_4byte((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1 ,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4 ,
	((unsigned char *)&Event_Meter_Pro_Pointer.Energypasszero_P),
	(&Event_Meter_Pro_Times.Energypasszero_Times));  	
	
	FeedWatchdog();
}
 
 
 
 
 
 
 
 
 
void CurrVoltImBalance_Event(void)
{
	unsigned char und;
	unsigned char eventflag;
	unsigned char offset;
	unsigned char *judgeimbalancedelay;
	unsigned char *eventfilenameoffset;
	unsigned int  eventfilenameoffsetaddr;
	unsigned int  eventfilename;
	unsigned long *imbalanceeventtimes;
	unsigned int  imbalanceeventtimesaddr;
	unsigned long *imbalanceeventtimeticks;
	unsigned int  imbalanceeventtimeticksaddr;
	unsigned long judgeimbalancerate;
	unsigned char judgeimbalancetime;
	unsigned long tempimbalancerate;
	unsigned long tempmaxvalue;
	unsigned long tempminvalue;

       unsigned char eventreportflag;
       
  for(und=0;und<3;und++)
  {
    int2ic_addr.byte &= 0xf8;
    
    switch(und)
    {
    	case 0:
    	  eventflag=2;
    	  offset=0x40;
    	  eventreportflag=1;
          
    	  judgeimbalancedelay=&Event_N.CurrImBalanceEvent_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.CurrImBalanceEvent_P;
    	  eventfilenameoffsetaddr=((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1)  ;
    	  
    	  eventfilename=1344L ;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.CurrImBalanceEvent_Times;
    	  imbalanceeventtimesaddr=((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4)  ;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.CurrImBalanceEvent_Times_Ticks;
    	  imbalanceeventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4 ;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeCurrImBalanceN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeCurrImBalanceT;
    	  
    	  tempmaxvalue=eventmaxcurr;
    	  tempminvalue=eventmincurr;
    	break;
    	
    	case 1:
    	  eventflag=2;
    	  offset=0x80;
         eventreportflag=0;
         
    	  judgeimbalancedelay=&Event_N.VoltImBalanceEvent_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.VoltImBalanceEvent_P;
    	  eventfilenameoffsetaddr=((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1 ;
    	  
    	  eventfilename=1376L ;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.VoltImBalanceEvent_Times;
    	  imbalanceeventtimesaddr=((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4 ;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.VoltImBalanceEvent_Times_Ticks;
    	  imbalanceeventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4 ;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeVoltImBalanceN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeVoltImBalanceT;
    	  
    	  tempmaxvalue=eventmaxvolt;
    	  tempminvalue=eventminvolt;
    	break;
    	
    	default:
    	  eventflag=5;
    	  offset=0x04;
    	  eventreportflag=6;
          
    	  judgeimbalancedelay=&Event_N.CurrFarImB_P;
    	  
    	  eventfilenameoffset=&Event_Power_Net_Pointer.CurrFarImB_P;
    	  eventfilenameoffsetaddr=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1)  ;
    	  
    	  eventfilename=2528L ;
    	  
    	  imbalanceeventtimes=&Event_Power_Net_Times.CurrFarImB_Times;
    	  imbalanceeventtimesaddr=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)   ;
    	  
    	  imbalanceeventtimeticks=&Event_Power_Net_Timeticks.CurrFarImB_Times_Ticks;
    	  imbalanceeventtimeticksaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4 ;
    	  
    	  judgeimbalancerate=Meter_Parameter.event_parameter.JudgeCurrFarImBN;
    	  judgeimbalancetime=Meter_Parameter.event_parameter.JudgeCurrFarImBT;
    	  
    	  tempmaxvalue=eventmaxcurr;
    	  tempminvalue=eventmincurr;
    	break;
    }
    
    tempimbalancerate=0;
    if((tempmaxvalue!=0)&&(tempmaxvalue>tempminvalue))
    {
     	if(((und==1)&&(tempmaxvalue*100l>Meter_Parameter.event_parameter.CriticalVoltage*EventUn))
     	||((und!=1)&&((tempmaxvalue*100l)>=(EventIb*5))))
     	{
  	   tempminvalue=(tempmaxvalue-tempminvalue)*100l;
  	   tempimbalancerate=tempminvalue/tempmaxvalue;
  	   tempminvalue=tempminvalue%tempmaxvalue;
  	   tempminvalue=(tempminvalue*100l)/tempmaxvalue;
  	   tempimbalancerate=tempimbalancerate*100l+tempminvalue;
  	  }
    }  
  
    if((Event_Power_Net_Flag.byte[eventflag]&offset)==0)
	  {
	    if((judgeimbalancerate!=0)&&(tempimbalancerate>=judgeimbalancerate))
	    {
			  (*judgeimbalancedelay)++;
			  if((*judgeimbalancedelay)>=judgeimbalancetime)
		   	{
				  (*judgeimbalancedelay)=0;
				  
				  Save_Event_StartData_Flash(eventfilenameoffset,eventfilenameoffsetaddr,
                                     eventfilename,0,102,0x000D,
                                     imbalanceeventtimes,imbalanceeventtimesaddr);
				  
				  maximbalancerate[und]=tempimbalancerate;
				  savemaximbalancerate[und]=maximbalancerate[und];
          Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L +und*4L,(unsigned char *)&savemaximbalancerate[und],4,0,0);
					
				  Event_Power_Net_Flag.byte[eventflag]|=offset;   
                  		if(((Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x04) &&(0==eventreportflag))
                            ||((Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x08)&&(1==eventreportflag))
                            ||((Meter_Parameter.parameter1.EventReportMode.byte[5] & 0x01)&&(6==eventreportflag)))
				  Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1 +eventreportflag),((unsigned char *)&Event_Report_Status_Times.VoltImbalance_times+eventreportflag));
		    }
	    }
	    else
	    { 
			   (*judgeimbalancedelay)=0;
		  }
	  }
	  else
	  {
	   if((judgeimbalancerate==0)||(tempimbalancerate<judgeimbalancerate))
	   {
			 (*judgeimbalancedelay)++;
			 if((judgeimbalancerate==0)||((*judgeimbalancedelay)>=judgeimbalancetime))
			 {
				 (*judgeimbalancedelay)=0;
				 
				 *((unsigned long *)&Co.b[606])=maximbalancerate[und];
				 Save_Event_EndData_Flash((*eventfilenameoffset),
                                  eventfilename,102,106,0x001D,
                                  imbalanceeventtimeticks,imbalanceeventtimeticksaddr);				
				 
				 Event_Power_Net_Flag.byte[eventflag]&=(~offset);   
			 }
	   }
	   else
	   {
		    (*judgeimbalancedelay)=0;
		    
		    if(maximbalancerate[und]<tempimbalancerate)
		      maximbalancerate[und]=tempimbalancerate;
	   }
	 }
	 FeedWatchdog();
	 int2ic_addr.byte |=0x01;	
 }
  
}


void Check_Max_Imbalance_Rate(void)
{
   unsigned char und;
   unsigned char eventflag[3]={2,2,5};
	 unsigned char offset[3]={0x40,0x80,0x04};
   
   for(und=0;und<3;und++)
   {
     if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])!=0)
	   {
       if(savemaximbalancerate[und]<maximbalancerate[und])
	     {
		      savemaximbalancerate[und]=maximbalancerate[und];
          Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L +und*4L,(unsigned char *)&savemaximbalancerate[und],4,0,0);
          FeedWatchdog();
	     }
	   }
   }
   
}

 
void SetPrimaryRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<5;unc++)
	 Co.b[300+unc]=*((unsigned char *)&MainSoftDate +unc);
	
  Save_Event_StartData_Flash(&Event_Meter_Pro_Pointer.SetPrimary_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1 ,
                             1888L ,0,sizeof(struct SETPRIMARY_DATA),0x0000,
                             &Event_Meter_Pro_Times.SetPrimary_Times,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4 );
                     
}
 
 
void EepromEventSetDefault(void)
{
	FeedWatchdog();
	Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) , 0,  ((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L ) -((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) )), 0, 0);
	FeedWatchdog();
}
 

 
unsigned char PrepLostVoltFirstEventData(unsigned int eventaddr,unsigned char eventaddrkind,
                                         unsigned char eventamphourkind,unsigned char eventbeginflag){
   unsigned char unc;
   
   if(eventaddrkind==0){
  	 Write_Read_FM24C256 (eventaddr,&TempEventData[0],255,0,1);
   }
   else{
   		if(IntoPowerDownFlag)
   		{
   			Show_ID_vatiy=0xFF;
			return 0;
   		} 
     		Read_File(eventaddr,0,255,&TempEventData[0]);
   }
   if(eventbeginflag!=0){
   	 SaveEvent0EndAmpHour(eventamphourkind);
		 PrepEvent0Data(0x004D);
		 for(unc=0;unc<6;unc++)
		   Co.b[300+unc]=0;
		 for(unc=0;unc<96;unc++)
		   Co.b[306+unc]=0xFF;
		 for(unc=0;unc<114;unc++)
		   TempEventData[141+unc]=Co.b[300+unc];
   }
   return 0xFF;
}

unsigned char PrepNewFirstEventData(unsigned long eventcode)
{
   unsigned char unc;
   unsigned char result;
   unsigned int uni;
   union ID id;
   
   result=0xff;
   id.l=eventcode;
   eventcode=eventcode&0xFFFF00FF;
   
   if((id.d[3]>=0x10)&&(id.d[1]==0))
   {
   	 return 0;
   }
   
   switch(eventcode)
   {
   	 case 0x10010001:
   	 case 0x10020001:
   	 case 0x10030001:
   	  PrepLostVoltFirstEventData((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +((unsigned int)255)*(id.d[2]-1),0,(id.d[2]-1),((Event_Power_Net_Flag.byte[0]>>(id.d[2]-1))&0x01));
   	 break; 
   	 
   	 case 0x13010001:
   	 case 0x13020001:
   	 case 0x13030001:
   	  uni=416L +32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.BreakPhase_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+8),((Event_Power_Net_Flag.byte[1]>>(id.d[2]-1))&0x01));
   	 break; 
   	 
   	 case 0x12010001:
   	 case 0x12020001:
   	 case 0x12030001:
   	  uni=1024L +32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.OverVoltage_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+5),((Event_Power_Net_Flag.byte[2]>>(id.d[2]+2))&0x01));
   	 break; 
   	 
   	 case 0x11010001:
   	 case 0x11020001:
   	 case 0x11030001:
   	  uni=1440L +32*(id.d[2]-1)+(*(&Event_Power_Net_Pointer.VoltageDown_A_P+(id.d[2]-1))%32);
   	  result=PrepLostVoltFirstEventData(uni,0xFF,(id.d[2]+2),((Event_Power_Net_Flag.byte[1]>>(id.d[2]+2))&0x01));
   	 break; 
   	 
   	 case 0x16000001:
   	 case 0x17000001:
   	  if(IntoPowerDownFlag)
			{
				Show_ID_vatiy=0xFF;
				return 0;
			}
   	  
		  uni=1344L +32*(1-(id.d[3]-0x16))+(*(&Event_Power_Net_Pointer.CurrImBalanceEvent_P+(1-(id.d[3]-0x16))))%32;	  
		  Read_File(uni,0,208,&TempEventData[0]);
			if(((Event_Power_Net_Flag.byte[2]>>(7-(id.d[3]-0x16)))&0x01)!=0)
			{
				 for(unc=0;unc<102;unc++)
				 {
			    TempEventData[102+unc]=0;
			   }
				 *((unsigned long *)&TempEventData[204])=maximbalancerate[(1-(id.d[3]-0x16))];
			}
		  
   	 break; 
   	 
   	 case 0x20000001:
   	  if(IntoPowerDownFlag)
			{
				Show_ID_vatiy=0xFF;
				return 0;
			}
   	  
		  uni=2528L +Event_Power_Net_Pointer.CurrFarImB_P%32;	  
		  Read_File(uni,0,208,&TempEventData[0]);
			if(Event_Power_Net_Flag.bit.CurrFarImB)
			{
				  for(unc=0;unc<102;unc++)
				  {
			      TempEventData[102+unc]=0;
			    }
				  *((unsigned long *)&TempEventData[204])=maximbalancerate[2];
			}
   	 break; 
   	 
   	 case 0x03120001:
		  if((id.l>=0x03120101)&&(id.l<=0x03120601))
		  {
		  	if(IntoPowerDownFlag)
			  {
				  Show_ID_vatiy=0xFF;
				  return 0;
			  }
			  PrepOverDemandFirstEventData(id.l);
		  }
		  else
		  {
		  	 result=0;
		  }
   	 break; 
   	 
   	 case 0x03050001:
   	  Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L ,&TempEventData[0],16,0,1);
   	  if(Event_Power_Net_Flag.bit.Phase3LostVolt)
   	  {
   	  	for(unc=0;unc<6;unc++)
   	  	  TempEventData[10+unc]=0;
   	  }
   	 break; 
   	 
   	 case 0x03110001:
   	  Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L ,&TempEventData[0],12,0,1);
   	  if(Event_Power_Net_Flag.bit.PowerDownEvent)
   	  {
   	  	for(unc=0;unc<6;unc++)
   	  	  TempEventData[6+unc]=0;
   	  }
   	 break; 
   	 
   	 case 0x03300001:
   	  switch(id.d[1])
   	  {
   	  	case 0x00:
   	  	 Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L) ,&TempEventData[0],50,0,1);
   	  	break; 
   	  	
   	  	case 0x0d:
   	  	case 0x0e:
   	  	 Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +60*(id.d[1]-0x0d),&TempEventData[0],60,0,1);
   	     if(((Event_Power_Net_Flag.byte[3]>>(6+(id.d[1]-0x0d)))&0x01)!=0)
   	     {
   	  	   for(unc=0;unc<30;unc++)
   	  	    TempEventData[30+unc]=0;
   	     }
   	  	break; 
   	  	
   	  	default:
   	  	 result=0;
   	  	break;
   	  }
   	 break;
   	 
   	 case 0x03360001:
   	  if(Pre_Payment_Para.Pay_For_Users_Flag15.bit.RelayErrFlag )
		  {
		    Write_Read_FM24C256 (0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point ) ,&TempEventData[0],21,0,1);
		    for(unc=0;unc<6;unc++)
		      TempEventData[6+unc]=0;
		    for(unc=0;unc<8;unc++)
		      TempEventData[21+unc]=0;
		  }
		  else
		  {
		  	result=0;
		  }
   	 break; 
   	 
   	 default:
   	  result=0;
   	 break;
   }
   
   if((Show_ID_vatiy==0xFF)&&(IntoPowerDownFlag))
   {
			result=0;
   }
   
   return result;
}
 
 
  


































 
 
void EMeterPowerdownRecord(void)
{
	unsigned char unc;
	
	for(unc=0;unc<6;unc++)
	{
		  Co.b[400+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		  Co.b[406+unc]=*((unsigned char *)&MainSoftDate +unc);
  }
	if((CheckTime(&Co.b[400])!=0xff))
	{
	  for(unc=0;unc<6;unc++)
		  Co.b[400+unc]=0xff;
	}
	
	CheckPowerDown();
	Save_Record_Data_Flash(&Event_Meter_Pro_Pointer.AdjustTimeOverT_P,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 ,
                         1408L ,12,
                         &Event_Meter_Pro_Times.AdjustTimeOverT_Times,((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   );
	
}
 
 
 
void VoltageDownEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	
	
	 
	for(und=0;und<3;und++)
	{
	  if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
	  {			
		  continue;
	  }
	  
	  int2ic_addr.byte &=0xf8;
	  
	  if((Event_Power_Net_Flag.byte[1]&offset[und])==0)
	  {
	    if((Meter_Parameter.event_parameter.JudgeVoltDown_V!=0)&&(Volt[und]<Meter_Parameter.event_parameter.JudgeVoltDown_V*1000l))
	    {
	   	   
	   	   (*((unsigned char *)&Event_N.VoltageDown_A_P+und))++;
	   	   	 
	   	   if((*((unsigned char *)&Event_N.VoltageDown_A_P+und))>=Meter_Parameter.event_parameter.JudgeVoltDownT)
	   	   {
	   	 	    (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
			      
		        Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1 +und),
                                       (1440L +und*32L),0,141,0x002D,
                                       ((unsigned long *)&Event_Power_Net_Times.VoltageDown_A_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4 +und*4L));
		        SaveEvent0BeginAmpHour(3+und);
		        Event_Power_Net_Flag.byte[1]|=offset[und];
		        if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x02)  
		        Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 +und*16), ((unsigned char *)&Event_Report_Status_Times.LowVolt_A_times+und*16));
	   	   }
	   }
	   else
	   {
			  (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
	   }
	 }
	 else
	 {
	   if((Volt[und]>=Meter_Parameter.event_parameter.JudgeVoltDown_V*1000l)||(Meter_Parameter.event_parameter.JudgeVoltDown_V==0))
	   {
		   	
		   (*((unsigned char *)&Event_N.VoltageDown_A_P+und))++;
		   		 	
	   	 if(((*((unsigned char *)&Event_N.VoltageDown_A_P+und))>=Meter_Parameter.event_parameter.JudgeVoltDownT)
	   	 ||(Meter_Parameter.event_parameter.JudgeVoltDown_V==0))
	   	 {
	   	    (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;
	   	    
				  SaveEvent0EndAmpHour(3+und);			  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.VoltageDown_A_P+und)),
                                   (1440L +und*32L),141,114,0x004D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.VoltageDown_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4 +und*4L));
		      Event_Power_Net_Flag.byte[1]&=(~offset[und]); 
	   	 }
	   }
	   else
	   {
	   	 (*((unsigned char *)&Event_N.VoltageDown_A_P+und))=0;	
	   }
	 }
	 int2ic_addr.byte |=0x01;
	 FeedWatchdog();
	}
	
}
 

 
 
void OverCurrentEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x01,0x02,0x04};	
	
	 
	for(und=0;und<3;und++)
	{
	  if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
	  {			
		  continue;   
	  }
	  
	  int2ic_addr.byte &=0xf8;
	  
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)
	  {
	   if((Meter_Parameter.event_parameter.JudgeOverCurrentI!=0)&&(Curr[und]>Meter_Parameter.event_parameter.JudgeOverCurrentI*1000l))
	   {
			 (*((unsigned char *)&Event_N.OverCurrent_A_P+und))++;
		   if((*((unsigned char *)&Event_N.OverCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverCurrentT)
		   {
		      *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
		      
		      Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1 +und),
                                     (1536L +und*32L),0,141,0x002D,
                                     ((unsigned long *)&Event_Power_Net_Times.OverCurrent_A_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4 +und*4L));
		      Event_Power_Net_Flag.byte[3]|=offset[und];   
		      if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x10)   
		      Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1 +und*16), ((unsigned char *)&Event_Report_Status_Times.OverCurr_A_times+und*16));
		   }
	   }
	   else
	   {
			*((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
	   }
	 }
	 else
	 {
	   if((Curr[und]<=Meter_Parameter.event_parameter.JudgeOverCurrentI*1000l)||(Meter_Parameter.event_parameter.JudgeOverCurrentI==0))
	   {	
			 (*((unsigned char *)&Event_N.OverCurrent_A_P+und))++;
			 
		   if(((*((unsigned char *)&Event_N.OverCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeOverCurrentT)
		   ||(Meter_Parameter.event_parameter.JudgeOverCurrentI==0))
		   {
		      *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;
		      				  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.OverCurrent_A_P+und)),
                                   (1536L +und*32L),141,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.OverCurrent_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4 +und*4L));
          Event_Power_Net_Flag.byte[3]&=(~offset[und]);
		   }
	   }
	   else
	   {
		   *((unsigned char *)&Event_N.OverCurrent_A_P+und)=0;	
	   }
	  }
    int2ic_addr.byte |=0x01;
	  FeedWatchdog();
	}
	
}
 
 
void SaveLostVoltTime(unsigned int tempeepromaddr,unsigned char savetimekind){
	unsigned char unc=0;
	unsigned char tempdate[6];
	
	if(savetimekind==0xFF){
	  for(unc=0;unc<=5;unc++)
	    tempdate[unc]=*((unsigned char *)&MainSoftDate +unc);
	}
	else{
		for(unc=0;unc<=5;unc++)
	    tempdate[unc]=0xFF;
	}
	Write_Read_FM24C256 (tempeepromaddr,&tempdate[0],6,0,0);
	
}
 
void LostVoltEnergyAdd(unsigned int eventeepromaddr,unsigned char storekind)
{
	unsigned char tempunc=0;
	unsigned int tempuni=0,tempunj=0,tempunk=0;
	unsigned long tempunl=0,tempdata0=0;

  if(eventeepromaddr==((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 )
  {
      Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS) +6,(unsigned char*)&lostvoltenergy[0],8,0,1);
      tempunj=0;            
  }
  else  if(eventeepromaddr==((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8 )
  {
      Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L +6,(unsigned char*)&lostvoltenergy[2],8,0,1);
      tempunj=2;
  }
  else  if(eventeepromaddr==((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8 )
  {
      Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L +6,(unsigned char*)&lostvoltenergy[4],8,0,1);
      tempunj=4;
  }
  else
     return ;
       
  for(tempuni=0;tempuni<=1;tempuni++)
  {
     tempunk=tempunj+tempuni;
     
	   tempdata0=(*((unsigned long *)&This_Month_Data.Energy_Record+tempuni*9        ));
	   if(tempdata0>=lostvoltenergy[tempunk])
	   {
		     lostvoltenergy[tempunk]=tempdata0-lostvoltenergy[tempunk];
		 }
	   else
	   {
		     Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4 +tempunj,(unsigned char*)&lostvoltagetime[tempunj/2][0],2,0,1);
		     if(lostvoltagetime[tempunj/2][tempuni]<This_Month_Data.Energy_Record.EnergyPassMAXTimes[tempuni])   
		        lostvoltenergy[tempunk]= 999999999l-lostvoltenergy[tempunk]+tempdata0+1;
		 }
		 
		 tempunc=Write_Read_FM24C256 (eventeepromaddr+tempuni*4,(unsigned char *)&tempunl,4,0,1);
		 if(tempunc==0xFF)
		 {
				lostvoltenergy[tempunk]=tempunl+lostvoltenergy[tempunk];
				if(lostvoltenergy[tempunk]>999999999l)
					 lostvoltenergy[tempunk]=lostvoltenergy[tempunk]-999999999l;
        if(storekind ==0xff)
				   Write_Read_FM24C256 (eventeepromaddr+tempuni*4,(unsigned char *)&lostvoltenergy[tempunk],4,0,0);
		 }
	}  
	
}
 
int  PrepLostVoltEnergyData(unsigned long eventcode)
{
	unsigned char unc=0;
	unsigned char eventflag=0;
	unsigned int uni=0;
	unsigned int unj=0;
  
	if((eventcode==0x10010003)||(eventcode==0x10010004))
	{
		unc=0;
		uni=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 ;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x01);
	}
	else if((eventcode==0x10020003)||(eventcode==0x10020004))
	{
		unc=1;
		uni=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8 ;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x02);
	}
	else if((eventcode==0x10030003)||(eventcode==0x10030004))
	{
		unc=2;
		uni=((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8 ;
		eventflag=(Event_Power_Net_Flag.byte[0]&0x04);
	}
	else
	{
	  return -1;
  }
  
  if(unc<3)
  {
  	if(eventflag!=0)
  	{
      LostVoltEnergyAdd(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6 +(unc*8l),0);
    }
    else
    {
	     Write_Read_FM24C256 (uni,(unsigned char *)&lostvoltenergy[unc*2],8,0,1);  
    }

    return 0;
  }
  
  return -1;	
}
 
 
 
 
void UpLoadEvent(void)
{
	unsigned char unc;
	unsigned int uni;
	unsigned long judgeuploadn;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	
	
	 
	judgeuploadn=Meter_Parameter.event_parameter.JudgeUpLoadP*100l;
	for(und=0;und<3;und++)
	{
	  if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
	  {			
		  continue; 
	  }
	  
	  int2ic_addr.byte &= 0xf8;
	  
	  if((Event_Power_Net_Flag.byte[3]&offset[und])==0)
	  {
	   if((Meter_Parameter.event_parameter.JudgeUpLoadP!=0)&&(Active_power[und+1]>judgeuploadn))
	   {
		   
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))++;
		      
		   if((*((unsigned char *)&Event_N.UpLoad_A_P+und))>=Meter_Parameter.event_parameter.JudgeUpLoadT)
		   {
		     (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;
			   
			   Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1 +und),
                                    (1632L +und*32L),0,102,0x000D,
                                    ((unsigned long *)&Event_Power_Net_Times.UpLoad_A_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4 +und*4L));
			   Event_Power_Net_Flag.byte[3]|=offset[und];
			   if(Meter_Parameter.parameter1.EventReportMode.byte[2] & 0x20)   
			   Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 +und*16), ((unsigned char *)&Event_Report_Status_Times.UpLoad_A_event_times+und*16));
		   }
	   }
	   else
	   {
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;
	   }
	  }
	  else
	  {
	   if((Active_power[und+1]<=judgeuploadn)||(Meter_Parameter.event_parameter.JudgeUpLoadP==0))
	   {
		   	
			 (*((unsigned char *)&Event_N.UpLoad_A_P+und))++;
			 
		   if(((*((unsigned char *)&Event_N.UpLoad_A_P+und))>=Meter_Parameter.event_parameter.JudgeUpLoadT)
		   ||(Meter_Parameter.event_parameter.JudgeUpLoadP==0))
		   {
		      (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;			
		      			  
		      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.UpLoad_A_P+und)),
                                   (1632L +und*32L),102,102,0x000D,
                                   ((unsigned long *)&Event_Power_Net_Timeticks.UpLoad_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4 +und*4L));
          Event_Power_Net_Flag.byte[3]&=(~offset[und]);
		    }
	   }
	   else
	   {
		   (*((unsigned char *)&Event_N.UpLoad_A_P+und))=0;		
	   }
	  }
	  int2ic_addr.byte |= 0x01;
	  FeedWatchdog();
	}
	
}
 
 
void CurrReverseEvent(void)
{
	unsigned int uni;
  
  int2ic_addr.byte &= 0xf8;
  if(Event_Power_Net_Flag.bit.CurrReverse==0)
	{
	   if((flag_communication_with_measuring_board.bit.b5 !=0)&&(eventmincurr*20>EventIb)&&(eventminvolt*100>EventUn*Meter_Parameter.event_parameter.CriticalVoltage)
	   &&(EventCriticalVoltage_Flag==0))
	   {
		   Event_N.CurrReverse_P++;
		   if(Event_N.CurrReverse_P>=60)
		   {
		     Event_N.CurrReverse_P=0;
		     
			   Save_Event_StartData_Flash(&Event_Power_Net_Pointer.CurrReverse_P,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1 ,
                                    1728L ,0,102,0x000D,
                                    &Event_Power_Net_Times.CurrReverse_Times,((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4 );
			   Event_Power_Net_Flag.bit.CurrReverse=1;
         if(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x02)  	   
         Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1 ,(unsigned char *)&Event_Report_Status_Times.CurrReverse_event_times);
		   }
	   }
	   else
	   {
		   Event_N.CurrReverse_P=0;
	   }
	}
	else
	{
	   if((flag_communication_with_measuring_board.bit.b5 ==0)||(EventCriticalVoltage_Flag!=0))
	   {
		   Event_N.CurrReverse_P++;
		   if((Event_N.CurrReverse_P>=60)||(EventCriticalVoltage_Flag!=0))
		   {
		     Event_N.CurrReverse_P=0;
		     
				 Save_Event_EndData_Flash(Event_Power_Net_Pointer.CurrReverse_P,
                                  1728L ,102,102,0x000D,
                                  &Event_Power_Net_Timeticks.CurrReverse_Times_Ticks,(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4 );				 
		     
         Event_Power_Net_Flag.bit.CurrReverse=0;
		   }
	   }
	   else
	   {
		   Event_N.CurrReverse_P=0;
	   }
	}
	int2ic_addr.byte |= 0x01;
	FeedWatchdog();
	
}
 
 
void OverFactorEvent(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned int  uni;
	unsigned char eventflag[4]={5,4,4,4};
	unsigned char offset[4]={0x02,0x20,0x40,0x80};
	unsigned char eventtimeticksoffset[4]={41,37,38,39};
	unsigned int  eventfilename[4]={1760L ,2304L ,2336L ,2368L };
	unsigned long *eventtimeticksramaddr[4]={&Event_Power_Net_Timeticks.OverFactor_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_A_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_B_Times_Ticks,
	                                         &Event_Power_Net_Timeticks.OverFactor_C_Times_Ticks};
	unsigned int  eventtimetickseepromaddr[4]={(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4 ,
	                                           (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4 ,
	                                           (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4 ,
	                                           (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4 };
	unsigned long judgeoverfactorn;
	unsigned long tempcurr;
	
	judgeoverfactorn=Meter_Parameter.event_parameter.JudgeOverFactorN*1000l;
	for(und=0;und<4;und++)
	{
		if((und>0)&&((Volt_Region      ==0)||(Volt_Region      ==3)))
      break;
		
		int2ic_addr.byte &= 0xf8;
      
    if(und==0)
      tempcurr=eventmaxcurr;
    else
      tempcurr=Curr[und-1];
		
		if((Event_Power_Net_Flag.byte[eventflag[und]]&offset[und])==0)
		{
			if((judgeoverfactorn!=0)&&(tempcurr*20>EventIb)&&(Factor[und]<judgeoverfactorn))
			{
				(*(&Event_N.OverFactor_P+und))++;
				if((*(&Event_N.OverFactor_P+und))>=Meter_Parameter.event_parameter.JudgeOverFactorT)
				{
					(*(&Event_N.OverFactor_P+und))=0;
					
			    Save_Event_StartData_Flash((&Event_Power_Net_Pointer.OverFactor_P+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1 +((unsigned int)und)),
                                     eventfilename[und],0,30,0x0005,
                                     (&Event_Power_Net_Times.OverFactor_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4 +und*4L));
			    
			    Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]|offset[und];
          if((0 == und)&&(Meter_Parameter.parameter1.EventReportMode.byte[4] & 0x80))
          {
             Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1 + 1  + 8  + 1  + 1  + 1  + 1   + 1  + 1  + 1   + 1  + 8 + 1    + 1  + 1  + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.Factor_Low_times);
          }
				}
			}
			else
			{
				*(&Event_N.OverFactor_P+und)=0;
			}
		}
		else
		{
			if((judgeoverfactorn==0)||(Factor[und]>=judgeoverfactorn))
			{
				(*(&Event_N.OverFactor_P+und))++;
				if(((*(&Event_N.OverFactor_P+und))>=Meter_Parameter.event_parameter.JudgeOverFactorT)||(judgeoverfactorn==0))
				{
					(*(&Event_N.OverFactor_P+und))=0;
								 
		      Save_Event_EndData_Flash((*(&Event_Power_Net_Pointer.OverFactor_P+und)),
                                   eventfilename[und],30,30,0x0005,
                                   eventtimeticksramaddr[und],eventtimetickseepromaddr[und]);
          Event_Power_Net_Flag.byte[eventflag[und]]=Event_Power_Net_Flag.byte[eventflag[und]]&(~offset[und]);
				}
			}
			else
			{
				*(&Event_N.OverFactor_P+und)=0;
			}
		}
		FeedWatchdog();
		int2ic_addr.byte |= 0x01;
	}
	
}

 
 
 
void FailCurrentEvent(void)
{
	
	unsigned int uni;
	unsigned char und;
  unsigned char offset[3]= {0x08,0x10,0x20};	

	 
	for(und=0;und<3;und++)
	{
		if((Volt_Region      ==0 || Volt_Region      ==3)&&(und==1))
		{			
			continue;
		}
		int2ic_addr.byte &= 0xf8;
		if((Event_Power_Net_Flag.byte[5]&offset[und])==0)
		{
		   if((Meter_Parameter.event_parameter.JudgeFailCurrI!=0)&&(Curr[und]<Meter_Parameter.event_parameter.JudgeFailCurrI)
		      &&(Volt[und]>Meter_Parameter.event_parameter.JudgeFailCurrSV*1000l))
		   {
				 (*((unsigned char *)&Event_N.FailCurrent_A_P+und))++;
			   if((*((unsigned char *)&Event_N.FailCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeFailCurrT)
			   {
			       
			      (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;
			      
		     		Save_Event_StartData_Flash(((unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P+und),((((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   + 1) +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1)  +und),
                                       (1792L +und*32L),0,141,0x002D,
                                       ((unsigned long *)&Event_Power_Net_Times.FailCurrent_A_Times+und),(((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  + 4) +4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4   +und*4L));
		     		Event_Power_Net_Flag.byte[5]|=offset[und];
		     		if(Meter_Parameter.parameter1.EventReportMode.byte[3] & 0x01)   
		     		Save_EventReportTimes((((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1  + 1   + 1 + 1  + 1   + 1 +und*16), ((unsigned char *)&Event_Report_Status_Times.BreakCurr_A_times+und*16));
			   }
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;		   
		   }
		}
		else
		{
		   if((Curr[und]>=Meter_Parameter.event_parameter.JudgeFailCurrI)||(Meter_Parameter.event_parameter.JudgeFailCurrI==0))
		   {	
				 (*((unsigned char *)&Event_N.FailCurrent_A_P+und))++;
			   if(((*((unsigned char *)&Event_N.FailCurrent_A_P+und))>=Meter_Parameter.event_parameter.JudgeFailCurrT)
			   ||(Meter_Parameter.event_parameter.JudgeFailCurrI==0))
			   {
			        (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;
			        
				      Save_Event_EndData_Flash((*((unsigned char *)&Event_Power_Net_Pointer.FailCurrent_A_P+und)),
                                       (1792L +und*32L),141,102,0x000D,
                                       ((unsigned long *)&Event_Power_Net_Timeticks.FailCurrent_A_Times_Ticks+und),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)             +4                 +4+4+4+4                     +4                    +4    +4   +4        +4+4+4+4+4+4+4+4+4+4+4+4 +4+4+4+4+4+4+4+4+4+4+4       +4+4+4+4+4+4+4+4+4+4+4 +und*4L));					
		      		Event_Power_Net_Flag.byte[5]&=(~offset[und]);
			   }
		   }
		   else
		   {
			   (*((unsigned char *)&Event_N.FailCurrent_A_P+und))=0;	
		   }
		}
	  int2ic_addr.byte |= 0x01;		
	  FeedWatchdog();
	}

}
 

void ConstantMagnetEventCheck(void)
{
	unsigned int  uni;
	
	int2ic_addr.byte &= 0xf8;
	
		
	if(Event_Power_Net_Flag.bit.ConstantMagnet==0)
	{
			if(p2_addr.bit.b1				 	  ==0)
			{
				Event_N.ConstantMagnet_P++;
				if(Event_N.ConstantMagnet_P>=5)
				{
					Event_N.ConstantMagnet_P=0;
					
			    Save_Event_StartData_Flash(&Event_Power_Net_Pointer.ConstantMagnet_P,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1)  ,
                                     2432L ,0,30,0x0005,
                                     &Event_Power_Net_Times.ConstantMagnet_Times,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)   );
			    Event_Power_Net_Flag.bit.ConstantMagnet=1;
          if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x10)          		      
          Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.ConstantMagnet_event_times);
				}
			}
			else
			{
				Event_N.ConstantMagnet_P=0;
			}
	}
	else
	{
			if(p2_addr.bit.b1				 	  !=0)
			{
				Event_N.ConstantMagnet_P++;
				if(Event_N.ConstantMagnet_P>=5)
				{
					Event_N.ConstantMagnet_P=0;
					
					if(Event_Power_Net_Pointer.ConstantMagnet_P>31)
					  Event_Power_Net_Pointer.ConstantMagnet_P=0;
		      uni=2432L +Event_Power_Net_Pointer.ConstantMagnet_P;
		      PrepEvent0Data(0x0005);
		      Write_File(uni,30,30,&Co.b[300]);
					
				  Event_Power_Net_Flag.bit.ConstantMagnet=0;
				}
			}
			else
			{
				Event_N.ConstantMagnet_P=0;
			}
	}
	FeedWatchdog();
	int2ic_addr.byte |= 0x01;
	
}

void PowerAbnormalEventCheck(void)
{
	unsigned char unc;
	unsigned int  uni;
	
	
	for(unc=0;unc<8;unc++)
	{
		if(pdvoltdata.validflag[unc]!=unc)
		  break;
	}
	if((unc>=8)&&(!((ICcard_Flag1.bit.SWITCH_ACT_MODE ==0)&&(Pre_Payment_Para.Pay_For_Users_Flag14.bit.SWITCH_FACT !=0))))
	{
		unc=Volt_Region      ;
		unc=unc%4;
		if((pdvoltdata.maxvolt*100)>(Vn[unc]*80))
		{
			CheckPowerDown();
			
			PrepEvent0Data(0x0005);
			for(unc=0;unc<6;unc++)
			{
		    Co.b[330+unc]=*(&Powerdown_Save_Data.date.Year+unc);
		  }
	    if((CheckTime(&Co.b[330])!=0xff))
	    {
	     for(unc=0;unc<6;unc++)
		      Co.b[330+unc]=0xff;
	    }
	    for(unc=0;unc<36;unc++)
			{
		    Co.b[400+unc]= Co.b[300+unc];
		  }
	    
			Save_Record_Data_Flash(&Event_Power_Net_Pointer.PowerAbnormal_P,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1+1+1+1) +1) +1   ,
                             2464L ,36,
                             &Event_Power_Net_Times.PowerAbnormal_Times,(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4+4    +4+4)  +4)  +4  );
        if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x20)   
        {
           EventReportState_Expand(0, 0, 0);
           Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1  + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.PowerAbnormal_event_times);
        }
        }
	}
	pdvoltdata.maxvolt=0;
	FeedWatchdog();
	
}

 
unsigned char PrepEvent0Data(unsigned int eventkind){
	unsigned char unc;
	unsigned char eventlength;
	unsigned long tempunl;
	
	eventlength=0;
	 
	if((eventkind&0x0001)!=0){
		 
	  for(unc=0;unc<=5;unc++)
	    Co.b[300+eventlength+unc]=*((unsigned char *)&MainSoftDate +unc);
	  eventlength=eventlength+6;
	}
	 
	if((eventkind&0x0002)!=0){
		 
	  for(unc=0;unc<=5;unc++)
	    Co.b[300+eventlength+unc]=Co.b[600+unc];
	  eventlength=eventlength+6;
	}
	 
	if((eventkind&0x0004)!=0){
		 
		for(unc=0;unc<=5;unc++)
	    *((unsigned long *)&Co.b[300+eventlength]+unc)=*((unsigned long *)&This_Month_Data.Energy_Record+unc*9        );
	  eventlength=eventlength+24;
	}
	 
	if((eventkind&0x0008)!=0){
		 
		for(unc=0;unc<=17;unc++)
	    *((unsigned long *)&Co.b[300+eventlength]+unc)=*((unsigned long *)&This_Month_Data.Energy_Record+6*9        +unc);
	  eventlength=eventlength+72;
	}
	 
	if((eventkind&0x0010)!=0){
		 
	  for(unc=0;unc<=3;unc++)
	    Co.b[300+eventlength+unc]=Co.b[606+unc];
	  eventlength=eventlength+4;
	}
	 
	if((eventkind&0x0020)!=0){
		 
	  for(unc=0;unc<=2;unc++){
	    tempunl=Volt[unc]/1000l;
	    HexToBcd(2,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    eventlength=eventlength+2;
	  }
	   
	  for(unc=0;unc<=2;unc++){
	    tempunl=Curr[unc]/10l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Curr[unc]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);    
	    eventlength=eventlength+3;
	  }
	   
	  for(unc=0;unc<=2;unc++){
	    tempunl=Active_power[unc+1]/100l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Active_power[unc+1]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);     
	    eventlength=eventlength+3;
	  }
	   
	  for(unc=0;unc<=2;unc++){
	    tempunl=Reactive_power[unc+1]/100l;
	    HexToBcd(3,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Reactive_power[unc+1]<0)
	      Co.b[302+eventlength]=(Co.b[302+eventlength]|0x80);     
	    eventlength=eventlength+3;
	  }
	   
	  for(unc=0;unc<=2;unc++){
	    tempunl=Factor[unc+1]/1000l;
	    HexToBcd(2,(unsigned char *)&tempunl,&Co.b[300+eventlength]);
	    if(COMM_Factor[unc+1]<0)
	      Co.b[301+eventlength]=(Co.b[301+eventlength]|0x80);      
	    eventlength=eventlength+2;
	  }
	}
	 
	if((eventkind&0x0040)!=0){
		 
	  for(unc=0;unc<12;unc++)
	    Co.b[300+eventlength+unc]=Co.b[610+unc];
	  eventlength=eventlength+12;
	}
	 
	if((eventkind&0x0080)!=0){
		 
	  for(unc=0;unc<4;unc++)
	    Co.b[300+eventlength+unc]=Co.b[622+unc];
	  eventlength=eventlength+4;
	}
	 
	if((eventkind&0x0100)!=0){
		 
	  for(unc=0;unc<9;unc++)
	    Co.b[300+eventlength+unc]=Co.b[626+unc];
	  eventlength=eventlength+9;
	}
	 
	if((eventkind&0x0200)!=0){
		 
	  for(unc=0;unc<8;unc++)
	    Co.b[300+eventlength+unc]=Co.b[635+unc];
	  eventlength=eventlength+8;
	}
	 
	if((eventkind&0x0400)!=0){
	  Co.b[300+eventlength]=Meter_States.Meter_Status2.bit.ActiveDirection_T;
	  eventlength=eventlength+1;
	}
	return eventlength;
	
}
 




unsigned long Cal_LastTime(unsigned char* eventbegintimepointer, unsigned char* eventendtimepointer)
{
	unsigned char unc,uni;
  unsigned long result;
  unsigned long tempunl;
  struct DATA_TIME tempdate;    
  
  result=0;
  for(uni = 0; uni < 6; uni++)
  {
  	*((unsigned char *)&tempdate + uni) = *eventendtimepointer++;
  }
	unc=TimeToLong(tempdate,&result);
	if(unc==0xFF)
		result=0xFFFFFFFF;
		
	tempunl=0;
	for(uni = 0; uni < 6; uni++)
  {
  	*((unsigned char *)&tempdate + uni) = *eventbegintimepointer++;
  }
	unc=TimeToLong(tempdate,&tempunl);
	if(unc==0xFF)
		tempunl=0xFFFFFFFF;
		
  if((result!=0xFFFFFFFF)&&(tempunl!=0xFFFFFFFF)&&(result>tempunl))
  	{
  	  result=result-tempunl;  	  
    }
   else
   	{
   		result = 0;
   	}
    
  return (result);
}
 
 
void SaveEvent0LastTime_Other(unsigned int eventlasttimeaddr,unsigned long* eventlasttimepointer)
{
   
  unsigned long result;

  
   
   
   
   
   
   

    
    
    	 
    	 
  	    Write_Read_FM24C256 (eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
    	 
}
 
void SaveEvent0LastTime(unsigned int eventaddr,unsigned char eventaddrkind,
                        unsigned char* eventendtimepointer,unsigned int eventlasttimeaddr,
                        unsigned long* eventlasttimepointer){
   
  unsigned long result;
  
  
 
 	 
	if(EventTimeTicksValid_Flag==0xFF)  
	{
		FeedWatchdog();
		Write_Read_FM24C256 (eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
	}
	else   
	{
		  if(eventaddrkind==0){
		  	Write_Read_FM24C256 (eventaddr,&Co.b[300],6,0,1);
		  }
		  else{
		    Read_File(eventaddr,0,6,&Co.b[300]);
		  }
		    result = Cal_LastTime(&Co.b[300], eventendtimepointer);
		    if(result)
		    	{
		    		(*eventlasttimepointer)=(*eventlasttimepointer)+(result/60l);
		  	    Write_Read_FM24C256 (eventlasttimeaddr,(unsigned char *)eventlasttimepointer,4,0,0);
		    	}  	
	}
}
 
 
void SaveEvent0BeginAmpHour(unsigned char eventkind){
	unsigned char unc;
	
	if(eventkind<12){
		for(unc=0;unc<3;unc++)
		  Event0BeginAmpHour[eventkind*3l+unc]=Event_AmpHour[unc];
	}
	
}
 








void Cal_AmpHour_poweron(unsigned int eventaddr, unsigned char kind)
{
	unsigned long curr_temp[3] = {0, 0, 0};
	unsigned long last_time = 0;
	unsigned char uni, unc;
	unsigned long AMP_temp = 0;
	if(kind==0)
		{
			Write_Read_FM24C256 (eventaddr,&Co.b[300],141,0,1);
		}
  else
    {
      Read_File(eventaddr,0,141,&Co.b[300]);
    }
	
	last_time = Cal_LastTime(&Co.b[300], (unsigned char *)&Powerdown_Save_Data.date);
	
 
 
 
	
	for(uni = 0; uni < 3; uni++)
	{
		for(unc = 0; unc < 3; unc++)
		{
			*((unsigned char *)&curr_temp[uni] + unc) = Co.b[408 + uni * 3 + unc];
			if(unc==2)
	    	{
	   		  *((unsigned char *)&curr_temp[uni] + unc) =((*((unsigned char *)&curr_temp[uni] + unc) )&0x7F);	 
	   		}
		}
		if(curr_temp[uni] > 20l * Meter_Parameter.parameter1.EventJudgeIn)
			break;
	}
	if(uni == 3)
		{
			for(uni = 0; uni < 3; uni++)
			{
				 
				BcdToHex(4, (unsigned char *)&curr_temp[uni], (unsigned char *)&AMP_temp);
				(*((unsigned long *)&Co.b[610]+uni)) = ((AMP_temp * last_time)/3600l + 5)/10l;
			}			
		}	
}
void SaveEvent0EndAmpHour(unsigned char eventkind){
	unsigned char unc;
	unsigned long tempdata0;
	unsigned long tempdata1;
	
	if(eventkind<12){
		for(unc=0;unc<=2;unc++){
	    tempdata0=Event0BeginAmpHour[eventkind*3l+unc];
	    tempdata1=Event_AmpHour[unc];
	    if((tempdata1>=tempdata0)&&(tempdata0!=0xFFFFFFFF)&&(tempdata1!=0xFFFFFFFF)){
	    	if((tempdata1-tempdata0)<=99999999l)
	    	  tempdata0=tempdata1-tempdata0;
	    	else
	    		tempdata0=99999999l;
	    }
	    else{
	    	tempdata0=0xFFFFFFFF;
	    }
	    (*((unsigned long *)&Co.b[610]+unc))=tempdata0;
	  }
	}
	
}
 
 
void ClearEvent0Flag(unsigned char eventflagn,unsigned char eventflagm){
	
	if(eventflagn<8){
		Event_Power_Net_Flag.byte[eventflagn]=Event_Power_Net_Flag.byte[eventflagn]&eventflagm;
		CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
	}
	
}
 
 
void MoveEventData2Flash(unsigned int eventeepromaddr,unsigned int eventfilename,unsigned char *eventfilep,unsigned char eventlength)
{
	unsigned int uni;
	
	ClearEvent_EventBegin(eventfilep,eventfilename);
	
  uni=eventfilename+(*eventfilep)%32;
  
	Write_Read_FM24C256 (eventeepromaddr,&Co.b[300],eventlength,0,1);
	
	Write_File(uni,0,eventlength,&Co.b[300]);
	
}
 
 
void Write_File_PdEvent(unsigned int eventfilename,unsigned int eventfilestartaddr,
                        unsigned char eventfileoffset,unsigned char *eventfilebuff){
    unsigned char unc;
    unsigned char res;
    unsigned int uni;
    uni=Read_File(eventfilename,eventfilestartaddr,eventfileoffset,&Co.b[800]);
    res=0xFF;
    if(uni==eventfileoffset){
    	for(unc=0;unc<eventfileoffset;unc++){
    		if(Co.b[800+unc]!=0xFF){
    			res=0;
    			break;
    		}
    	}
    }
    if(res==0xFF)
      Write_File(eventfilename,eventfilestartaddr,eventfileoffset,eventfilebuff);
    
}
 
 
 
unsigned char Save_EventTimesANDPointer_4byte(unsigned int Pointer_Addr,	
									unsigned int Times_Addr,	
							 		unsigned char *Event_Pointer,	
						 	 		unsigned long* Event_times)	
{
     Write_Read_FM24C256 (Pointer_Addr,(unsigned char *)Event_Pointer,1,0,0);
     (*(Event_times))++;
     Write_Read_FM24C256 (Times_Addr,(unsigned char *)Event_times,4,0,0);

}


 
void Copy_ENERGY_TO_CO(unsigned int startIndex)
{ 
    unsigned char unc;
    unsigned long *ptr=(unsigned long *)&Co.b[startIndex];
     for(unc=0;unc<=5;unc++)
	  *ptr++=*((unsigned long *)&This_Month_Data.Energy_Record+unc*9        );
	for(unc=0;unc<=17;unc++)
	  *ptr++=*((unsigned long *)&This_Month_Data.Energy_Record+6*9        +unc);
}
 









































 










 





















 

 
				 
			   

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
  	
 
void ClearEventDate_BatteryPowerOn(void)
{
	unsigned int i,j;
	
	 
	 
	CrcEventTimeTicks=0;
	 for(i=0;i<6;i++)  
	 {
		for(j=0;j<8;j++)
		{
		(*((unsigned long *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+j+i*8L))=0; 
		}  
	 }
	 

}

 

unsigned char CheckOpenCoverState(unsigned char kind)
{
	unsigned char unc;
	unsigned char coveropennum;
	unsigned char coverclosenum;
	unsigned char result;
	
	result=0xff;
	
	if(pdopencovercheckdata[kind].recordnum>0)
	{
		unc=(pdopencovercheckdata[kind].recordnum-1)%3;
		if(pdopencovercheckdata[kind].startrecord[unc].opencoverflag==2)
		{
			if(((kind==0)&&(p8_addr.bit.b3				  ==0))||((kind==1)&&(p2_addr.bit.b5				  ==0)))
			{
				  Delay(10);
				
				if(((kind==0)&&(p8_addr.bit.b3				  ==0))||((kind==1)&&(p2_addr.bit.b5				  ==0)))
				  result=1;
			}
		}
		else
		{
			if(((kind==0)&&(p8_addr.bit.b3				  ==1))||((kind==1)&&(p2_addr.bit.b5				  ==1)))
			{
				  Delay(10);
				
				if(((kind==0)&&(p8_addr.bit.b3				  ==1))||((kind==1)&&(p2_addr.bit.b5				  ==1)))
				  result=2;
			}
		}
	}
	else
	{
	  coveropennum=0;
	  coverclosenum=0;
	  
	  for(unc=0;unc<3;unc++)
	  {
		  if(((kind==0)&&(p8_addr.bit.b3				  ==0))||((kind==1)&&(p2_addr.bit.b5				  ==0)))
		    coveropennum++;
		  else
		    coverclosenum++;
		  
		  if(unc<2)
				Delay(10);
	  }
	
	  result=1;
	  if(coveropennum<coverclosenum)
	    result=2;
	}
	return result;
}

void PdOpenCoverCheckInit(unsigned char kind)
{
	unsigned char unc;
	unsigned char und;
	struct DATEANDTIME_DEF Opencover_DateAndTime;
	
	if(kind==0)
	{
	  for(unc=0;unc<sizeof(struct	PDOPENCOVER_STRUCTURE)*2;unc++)
	  {
		  *(((unsigned char *)&pdopencovercheckdata[0])+unc)=0;
	  }
	  pdopencoverintflag[0]=0;
	  pdopencoverintflag[1]=0;
	}
	else
	{
	  ClockChipRead((unsigned char *)&Opencover_DateAndTime);
	  for(und=0;und<2;und++)
	  {
	  	pdopencovercheckdata[und].startrecord[0].opencoverflag=CheckOpenCoverState(und);
	  	pdopencovercheckdata[und].startrecord[0].startyear=Opencover_DateAndTime.Year;
		  pdopencovercheckdata[und].startrecord[0].startmonth=Opencover_DateAndTime.Month;
			pdopencovercheckdata[und].startrecord[0].startday=Opencover_DateAndTime.Day;
			pdopencovercheckdata[und].startrecord[0].starthour=Opencover_DateAndTime.Hour;
			pdopencovercheckdata[und].startrecord[0].startmin=Opencover_DateAndTime.Min;
			pdopencovercheckdata[und].startrecord[0].startsec=Opencover_DateAndTime.Sec;
	  	pdopencovercheckdata[und].recordnum=1;
	  	for(unc=0;unc<8;unc++)
	  	  pdopencovercheckdata[und].validflag[unc]=unc;
	  }
  }
}

void PdOpenCoverCheck(void)
{
	unsigned char unc;
	unsigned char und;
	unsigned char tempcoverstatus;
	unsigned char tempreadtimeflag;
	struct DATEANDTIME_DEF Opencover_DateAndTime;
	
	tempreadtimeflag=0;
	for(unc=0;unc<2;unc++)
	{
		if(pdopencoverintflag[unc]==0x33)
		{
			pdopencoverintflag[unc]=0;
			
			if(pdopencovercheckdata[unc].recordnum<3)
			{
				tempcoverstatus=CheckOpenCoverState(unc);
				
				if((tempcoverstatus==1)||(tempcoverstatus==2))
				{
				  und=pdopencovercheckdata[unc].recordnum%3;
				  pdopencovercheckdata[unc].startrecord[und].opencoverflag=tempcoverstatus;
				  
					if(tempreadtimeflag==0)
					{
					    ClockChipRead((unsigned char *)&Opencover_DateAndTime);
					    tempreadtimeflag=1;
					}
					pdopencovercheckdata[unc].startrecord[und].startyear=Opencover_DateAndTime.Year;
					pdopencovercheckdata[unc].startrecord[und].startmonth=Opencover_DateAndTime.Month;
					pdopencovercheckdata[unc].startrecord[und].startday=Opencover_DateAndTime.Day;
					pdopencovercheckdata[unc].startrecord[und].starthour=Opencover_DateAndTime.Hour;
					pdopencovercheckdata[unc].startrecord[und].startmin=Opencover_DateAndTime.Min;
					pdopencovercheckdata[unc].startrecord[und].startsec=Opencover_DateAndTime.Sec;
				  
				  pdopencovercheckdata[unc].recordnum++;
			  }
			}
			
			if(pdopencovercheckdata[unc].recordnum>=3)
			{
				if(unc==0)
					int1ic_addr.byte &=0xF8;
					    
			  if(unc==1)
					int7ic_addr.byte &=0xF8;
			}
		}
	}
	
	NEW645Meter_States.Meter_Status7.bit.OpenBox=0;
	if(p2_addr.bit.b5				  ==0)
	  NEW645Meter_States.Meter_Status7.bit.OpenBox=1;
	
	
  NEW645Meter_States.Meter_Status7.bit.OpenCover=0;
	if(p8_addr.bit.b3				  ==0)
	  NEW645Meter_States.Meter_Status7.bit.OpenCover=1;
	
}

unsigned char CheckOpenCoverDataValid(unsigned char kind)
{
	unsigned char result;
	unsigned char unc;
	
	result=1;
	
	for(unc=0;unc<8;unc++)
	{
		if(pdopencovercheckdata[kind].validflag[unc]!=unc)
		{
			result=0;
			break;
		}
	}
	
	if(pdopencovercheckdata[kind].recordnum>3)
	  result=0;
	
	return result;
	
}

void PdOpenCoverCheckPowerUpDeal(void)
{
	unsigned char unc;
	unsigned char unc1;
	unsigned char und;
	unsigned char result;
	unsigned char tempnum[2]={0,0};
	unsigned int uni;
	unsigned char offset[2]={0x40,0x80};
	unsigned int Filename[2]={192L ,992L };
	
	for(unc=0;unc<2;unc++)
	{
		if(CheckOpenCoverDataValid(unc)==1)
		{
			if((Event_Power_Net_Flag.byte[3]&offset[unc])==0)
			{
				result=0;
				for(und=0;und<(pdopencovercheckdata[unc].recordnum%4);und++)
				{
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==1)
					{
						result=1;
						tempnum[0]=und;
					}
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==2)
					{
						if(result==1)
						{
						  result=2;
						  tempnum[1]=und;
						  break;
						}
					}
				}
				if(result!=0)
				{
					CheckPowerDown();
				  FeedWatchdog();
				  MoveEventData2Flash((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +unc*60L,Filename[unc],((unsigned char *)&Event_Power_Net_Pointer.OpenCoverEvent_P+unc),60);
				  
				  for(unc1=0;unc1<6;unc1++)
				  {
	    	    Co.b[300+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[tempnum[0]].startyear)+unc1);
	    		  *((unsigned long *)&Co.b[306]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*9        );
	    		  Co.b[330+unc1]=0;
	    		  *((unsigned long *)&Co.b[336]+unc1)=0xffffffff;
	    		  if(result==2)
	    		  {
	    		  	Co.b[330+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[tempnum[1]].startyear)+unc1);
	    		    *((unsigned long *)&Co.b[336]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*9        );
	    		  }
	    	  }
		      
		      Save_Event_StartData_Eeprom((&Event_Power_Net_Pointer.OpenCoverEvent_P+unc),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L           +1       +1     +1                   +1               +1   +1                +1                    +1      +1     +1+1+1	 +1 +1 +1+1 +1+1 +1+1+1+1+1+1+1+1+1+1+1+1 +unc),
                                      ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +unc*60L),60,
                                      ((unsigned long *)&Event_Power_Net_Times.OpenCoverEvent_Times+unc),((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)        +4  +4        +4                     +4                 +4+4+4              +4+4   +4+4+4+4 +4   +4+4+4    +4 +4+4+4+4+4 + 4 +4+4+4+4+4+4 +unc*4L));
		    
		      if(result==1)
		      {
		        Event_Power_Net_Flag.byte[3]|=offset[unc];
		        CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
	    	  }
	    	  
	    	  if(unc==0)
	    	  {
	    	    eventstatusinfo.bit.powerdownopencover=1;
                if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x04)
                Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1 , (unsigned char *)&Event_Report_Status_Times.Open_Meter_Cover_times);
	    	  }
	    	  else
	    	  {
	    	    eventstatusinfo.bit.powerdownopenbox=1;
                if(Meter_Parameter.parameter1.EventReportMode.byte[1] & 0x08)                                
                Save_EventReportTimes(((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L+60L+60L+16L+12L)+50L+6+6+6+6+6+6+8+8+8+sizeof(struct DEMAND_DATA_FORM)*6L + 4 + 4 + 4+6L+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+sizeof(struct VoltStatistic_Data)+64L+sizeof(union EVENTSTATUS_FLAG) + sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS)+sizeof(union EVENT_REPORT_STATUS) + 1 + 1 +1 +1 + 1+2 + 1 + 1 + 1  + 1 , (unsigned char *)&Event_Report_Status_Times.Open_Rail_Cover_times);
	    	  }
	    	  
				}
			}
			else
			{
				for(und=0;und<(pdopencovercheckdata[unc].recordnum%4);und++)
				{
					if(pdopencovercheckdata[unc].startrecord[und].opencoverflag==2)
					{
						CheckPowerDown();
				    FeedWatchdog();
						
						for(unc1=0;unc1<6;unc1++)
				    {
	    	      Co.b[300+unc1]=*((unsigned char *)&(pdopencovercheckdata[unc].startrecord[und].startyear)+unc1);
	    		    *((unsigned long *)&Co.b[306]+unc1)= *((unsigned long *)&This_Month_Data.Energy_Record+unc1*9        );
	    	    }
						Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)  +sizeof(struct EVENT_POWER_NET_TIMETICKS)+255L+255L+255L +unc*60L+30L,&Co.b[300],30,0,0);
						
		        Event_Power_Net_Flag.byte[3]&=(~offset[unc]);
		        CrcEvent0Flag=Crc16l(&Event_Power_Net_Flag.byte[0],8);
		        
		        break;
					}
				}
			}
			
			for(und=0;und<sizeof(struct	PDOPENCOVER_STRUCTURE);und++)
	    {
		    *(((unsigned char *)&pdopencovercheckdata[unc])+und)=0;
	    }
			
		}
	}
	
}
 
 
 
 
 
 
 
 
 
 
void ClearEventAll(void)
{
unsigned int uni = 0;
unsigned char eventflagmask[8]={0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00};

 
for(uni = 0; uni < 8; uni++)
{
Event_Power_Net_Flag.byte[uni] = (Event_Power_Net_Flag.byte[uni]&eventflagmask[uni]);
}
 
  
 
  
for(uni = 0; uni < 55; uni++)
{
if(((*((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times + uni)) != 0) ||
    (*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) != 0)) 
{
*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) = 0xa5 ;
*((unsigned long *)&Event_Power_Net_Times.BreakPhase_A_Times + uni) = 0;
}
else
{
  if((*((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni)) != 0xa5 )
    *((unsigned char *)&Event_Power_Net_Pointer.BreakPhase_A_P + uni) = 0;
}
}
Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L         , (unsigned char *)&Event_Power_Net_Pointer, 
	         sizeof(struct EVENT_POWER_NET_POINTER), 0, 0);
Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)      , (unsigned char *)&Event_Power_Net_Times, 
	         sizeof(struct EVENT_POWER_NET_TIMES), 0, 0);

 
for(uni = 10 ; uni <= 21      ; uni++)
{
if(((*((unsigned long *)&Event_Meter_Pro_Times.ResetCPU_Times+ uni)) != 0) ||
      (*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P + uni) != 0)) 
{
*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni) = 0xa5 ;
*((unsigned long *)&Event_Meter_Pro_Times.ResetCPU_Times+ uni) = 0;
}
else
{
  if((*((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni)) != 0xa5 )
    *((unsigned char *)&Event_Meter_Pro_Pointer.ResetCPU_P+ uni) = 0;
}
}

FeedWatchdog();
Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)      , (unsigned char *)&Event_Meter_Pro_Pointer, 
	         sizeof(struct EVENT_METER_PRO_POINTER), 0, 0);
Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)          , (unsigned char *)&Event_Meter_Pro_Times, 
	         sizeof(struct EVENT_METER_PRO_TIMES), 0, 0);
FeedWatchdog();
 
for(uni = 0; uni < sizeof(struct EVENT_POWER_NET_TIMETICKS); uni++)
{
*((unsigned char *)&Event_Power_Net_Timeticks.LostVoltage_A_Times_Ticks+ uni) = 0;
}

Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)         +sizeof(struct EVENT_METER_PRO_TIMES)   , (unsigned char *)&Event_Power_Net_Timeticks, 
	         sizeof(struct EVENT_POWER_NET_TIMETICKS), 0, 0);

  VoltStatSetDefault();
  EepromEventSetDefault();

for(uni = 0; uni < 2; uni++)
{
VoltCheck_N[0][uni].byte = 0;
VoltCheck_N[1][uni].byte = 0;
VoltCheck_N[2][uni].byte = 0;
powerreversetflag[uni]=0;
powerreversetcnt[uni]=0;	   
}
eventstatusinfo.byte=0; 


 
for(uni = 0; uni < sizeof(struct DATEANDTIME_DEF); uni++)
{
 *((unsigned char *)&Other_Data.ProgramDate + uni)=0;
 *((unsigned char *)&Other_Data.LastClearDemandDateCM + uni)=0;
}
 
 Write_Read_FM24C256 (0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10              +4    +4 +5	  *sizeof(struct PASSWORDERR) +1+sizeof(struct DATEANDTIME_DEF)  +sizeof(struct DATEANDTIME_DEF)    +1   , (unsigned char *)&Other_Data.ProgramDate,2 * sizeof(struct DATEANDTIME_DEF),0,0);

 

 
 
for(uni = 0; uni < 9; uni++)
{
*((unsigned long *)&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks + uni) = 0;
}
Write_Read_FM24C256 (0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  			 +4			 +4		 +4	 +4*4 +4	 +4*4	 +4			 +4			 +1			 +2	 +5		 +1	 +4		 +1	  , (unsigned char *)&Pre_Payment_Data.FARCONTROLEVENT.farSwitch_Ticks, 36, 0, 0);

 
for(uni = 1; uni < sizeof( struct _Pay_For_Event_Point ) -1; uni++)
{
*((unsigned char *)&Pay_For_Event_Point.Buy_Event_P+ uni) = 0xa5 ;
}
Write_Read_FM24C256 (0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para ) , (unsigned char *)&Pay_For_Event_Point, sizeof( struct _Pay_For_Event_Point ) , 0, 0);

 
Write_Read_FM24C256 (0x7fe0   - sizeof(struct JUSTMETER_PARAMETER) - sizeof(struct METER_PARAMETER)-sizeof( struct _Pay_Eeprom_Define )  +sizeof( struct _Pre_Payment_Data )+sizeof( struct _Pre_Payment_Para )+sizeof( struct _Pay_For_Event_Point ) ,0,29,0,0);

 CloseOverPowerAlarmSwitch();

}
 
 
 
 
 
 
 
 
 
void ClearEventCommDeal(unsigned long eventID)
{
  unsigned char uni;
  const struct CLEAREVENT_STRU *Event_Node1;
  unsigned char search_ok = 0;
  unsigned long tempidmask;
  unsigned char dealkind;
  unsigned int  filename;
  unsigned char *eventp;
  unsigned int  eventpaddr;
  
  dealkind=0;
  filename=0;
  eventpaddr=0;

  if(IntoPowerDownFlag == 0xff) 
  {
    return;
  }
  
  for(uni = 0; uni < ((sizeof(Clearevent_ID)) / sizeof(unsigned long)); uni++)         
  {
  	tempidmask=0xffffff00;
  	if((Clearevent_ID[uni] & 0x0000ff00) == 0x0000ff00)
  	{
  	   tempidmask=0xffff0000;
  	}
  	
    if((Clearevent_ID[uni] & tempidmask) == (eventID & tempidmask))
    {
       Event_Node1=( const struct CLEAREVENT_STRU *)&ClearEvent_Leaf[uni];
       search_ok = 0xff;
       break;
    }
  }

if(search_ok == 0xff) 
{
  if((Event_Node1->Pointer) != (void*)0  ) 
  {
    if((*(Event_Node1->Pointer)) == 0xa5 ) 
    {
      CheckPowerDown();
      Delete_File(Event_Node1->Filename_begin);
      *(Event_Node1->Pointer) = 0;
      Write_Read_FM24C256 ((Event_Node1->Pointer_addr),0,1,0,0);
    }
  }
}
else
{
	CheckPowerDown();
	 
	switch(eventID & 0xffffff00)
	{
		case 0x03300300:
		 dealkind=1;
     filename=768L ;
     eventp=&Event_Meter_Pro_Pointer.ClearEventRecord_P;
     eventpaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1 ;
		break;
		
		case 0x03300500:
		 dealkind=1;
     filename=2016L ;
     eventp=&Event_Meter_Pro_Pointer.ProgDailySlotRecord_P;
     eventpaddr=(0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1+1+1+1+1+1+1+1+1+1+1+1 ;
     if(Event_Meter_Pro_Pointer.ProgDailySlotRecord_P == 0xa5 )
     {
       Delete_File(2016L +32L);
       Delete_File(2016L +64L);
     }
		break;
	}
	if(dealkind==1)
	{
		if(*eventp == 0xa5 )
    {
      Delete_File(filename);
      *eventp = 0;
      Write_Read_FM24C256 (eventpaddr,eventp,1,0,0);
    }
	}
}
}
 
 
 
 
 
 
 
 
 
void ClearEventDataPowerOn(void)
{
unsigned char uni = 0;

for(uni = 0; uni < ((sizeof(Clearevent_ID)) / sizeof(unsigned long)); uni++)
{
ClearEventCommDeal(Clearevent_ID[uni]);
}
ClearEventCommDeal(0x03300500);
ClearEventCommDeal(0x03300300);

for(uni = 0; uni < ((sizeof(Clearfreeze_ID)) / sizeof(unsigned long)); uni++)
{
ClearFreezeCommDeal(Clearfreeze_ID[uni]);
}
}
 
 
 
 
 
 
 
 
 
 
void ClearEvent_EventBegin(unsigned char *pEventPoint, unsigned int begin_file)
{
if((*pEventPoint) == 0xa5 ) 
	{
	if(begin_file == 2016L )
	{
		Delete_File(2016L );
		Delete_File(2016L + 32l);
		Delete_File(2016L + 64l);
	}
	else if (begin_file == (((((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				 +32L)					 +32L)		  )	 
	{
		Delete_File((((((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				 +32L)					 +32L)		  );
		Delete_File((((((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				 +32L)					 +32L)		  + 32L);
		Delete_File((((((((((2560L)											 +32L			 )									 +32L)				 +32L)	 +32L)		 +32L	)		 +32L)				 +32L)					 +32L)		  + 64L);
	}
	else
	{
		Delete_File(begin_file);
	}
	*pEventPoint = 0;
	}
}



void Rst90E36Event(void)
{
	unsigned char i;
	
	if(rst90e36info.totalnum<_rMeter_State_Buffer.wRstCnt)
	{
		rst90e36info.totalnum=_rMeter_State_Buffer.wRstCnt;
		
		switch(_rMeter_State_Buffer.bRstType)
		{
			case METER_RST_TYPE_PRAERR:
			  rst90e36info.praerrnum++;
			break;
			
			case METER_RST_TYPE_RDERR:
			  rst90e36info.rderrnum++;
			break;
			
			case METER_RST_TYPE_VALERR:
			  rst90e36info.valerrnum++;
			break;
		}
	}
	
	if(rst90e36info.beginflag==0)
	{
		if(((rst90e36info.praerrnum+rst90e36info.rderrnum+rst90e36info.valerrnum)>0))
		{
			rst90e36info.beginflag=1;
			rst90e36info.counter=0;
			for(i=0;i<5;i++)
			{
				rst90e36info.time[i]=*((unsigned char *)&MainSoftDate +i);
			}
		}
	}
	else
	{
		rst90e36info.counter++;
		if(rst90e36info.counter>3600)
		{
			rst90e36info.beginflag=0;
			
			FeedWatchdog();
  	  Event_Meter_Pro_Pointer.Rst90E36_P=(Event_Meter_Pro_Pointer.Rst90E36_P+1)%24 ;
      Write_File((3464L +Event_Meter_Pro_Pointer.Rst90E36_P),0,11,&rst90e36info.time[0]);
      Write_Read_FM24C256 ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)           +1+1+1+1+1+1 + 1+1 ,&Event_Meter_Pro_Pointer.Rst90E36_P,1,0,0);
      
      Event_Meter_Pro_Times.Rst90E36_Times=Event_Meter_Pro_Times.Rst90E36_Times+rst90e36info.praerrnum+rst90e36info.rderrnum+rst90e36info.valerrnum;
      Write_Read_FM24C256 (((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD)+ (64 - ((0+10+24*9    +sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct HOLIDAYSLOT)+sizeof(struct YEARSLOT)+sizeof(struct DAILYSLOT)+sizeof(struct CYCLEDISPLAYTABLE_A)+sizeof(struct CYCLEDISPLAYTABLE_B)+10 +sizeof(struct OTHER_DATA)+sizeof(struct ENERGY_RECORD)*14 +sizeof(struct DEMAND_RECORD)*14    +4*14 +sizeof(struct THIS_MONTH_DATA_EEPROM)+14           +492*6L)+sizeof(struct Show_Powerdown_Data_Struct)*99+sizeof(struct Show_Powerdown_Data_Struct)*120  +sizeof(struct OTHER_METER_PARAMETER)+sizeof(struct ENERGY_RECORD))%64)+sizeof(struct POWERDOWN_SAVE_DATA)+sizeof(struct ENERGY_RAIL_ADD_BUFFER)+64L        +sizeof(struct EVENT_POWER_NET_POINTER)     +sizeof(struct EVENT_METER_PRO_POINTER)     +sizeof(struct EVENT_POWER_NET_TIMES)           +4+4+4+4+4+4)   + 4+4 ,(unsigned char *)&Event_Meter_Pro_Times.Rst90E36_Times,4,0,0);
      
	    for(i=0;i<11;i++)
	    {
	    	*(&rst90e36info.time[0]+i)=0;
	    }
		}
	}
	
}

unsigned char Save_EventReportTimes(unsigned int Times_Addr, unsigned char *EventReport_times)
{
    if((*(EventReport_times))<255)
	{
           (*(EventReport_times))+=1;
	}
    else
	{
          (*(EventReport_times))=255;
	}
     Write_Read_FM24C256 (Times_Addr,(unsigned char *)EventReport_times,1,0,0);
}

void Save_Event_StartData_Flash(unsigned char *eventp,unsigned int eventpaddr,
                                unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                                unsigned long *eventtimes,unsigned int eventtimesaddr)
{
	ClearEvent_EventBegin(eventp,filename);		
	(*eventp)=((*eventp)+1)%32;
	filename=filename+(*eventp);
  PrepEvent0Data(datakind);
	Write_File(filename,filestartaddr,fileendaddr,&Co.b[300]);
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
}

void Save_Event_EndData_Flash(unsigned char eventp,
                              unsigned int filename,unsigned char filestartaddr,unsigned char fileendaddr,unsigned int datakind,
                              unsigned long *eventtimeticks,unsigned int eventtimeticksaddr)
{
	if(eventp>31)
		eventp=0;
	filename=filename+eventp;
	PrepEvent0Data(datakind);
	Write_File(filename,filestartaddr,fileendaddr,&Co.b[300]);
	SaveEvent0LastTime_Other(eventtimeticksaddr,eventtimeticks);
}

void Save_Record_Data_Flash(unsigned char *eventp,unsigned int eventpaddr,
                            unsigned int filename,unsigned char fileendaddr,
                            unsigned long *eventtimes,unsigned int eventtimesaddr)
{
	FeedWatchdog();
	ClearEvent_EventBegin(eventp,filename);		
	(*eventp)=((*eventp)+1)%32;
	filename=filename+(*eventp);
	Write_File(filename,0,fileendaddr,&Co.b[400]);
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
	FeedWatchdog();
}

void Save_Event_StartData_Eeprom(unsigned char *eventp,unsigned int eventpaddr,
                                 unsigned int eepromaddr,unsigned char len,
                                 unsigned long *eventtimes,unsigned int eventtimesaddr)
{		
	Write_Read_FM24C256 (eepromaddr,&Co.b[300],len,0,0);
	(*eventp)=((*eventp)+1)%32;
	Save_EventTimesANDPointer_4byte(eventpaddr,eventtimesaddr,eventp,eventtimes);
	FeedWatchdog();
}

