/*******************************************************************************
*
* Device     : R5F364AxxFx(M16C/64A group)
*
* File Name  : sfr64a.h
*
* Abstract   : Definition of I/O Register.
*
* History    : 1.00  (2009-02-13)  [Hardware Manual Revision : 1.01]
*
* Copyright(c) 2009 Renesas Technology Corp.
*               And Renesas Solutions Corp.,All Rights Reserved. 
*
*******************************************************************************/

/******************************************************************************/
/*  Definition of access type                                                 */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/*  Common body definition of BYTE(8bit) type                                 */
/*----------------------------------------------------------------------------*/
#ifndef SFR64A_H   //for 64A
#define SFR64A_H   //for 64A

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

/*----------------------------------------------------------------------------*/
/*  Common body definition of WORD(16bit) type                                */
/*----------------------------------------------------------------------------*/
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
        unsigned char   low;                            /* low  8 bit */
        unsigned char   high;                           /* high 8 bit */
    } byte;
    unsigned short  word;
};

/*----------------------------------------------------------------------------*/
/*  Common body definition of DWORD(32bit) type                               */
/*----------------------------------------------------------------------------*/
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
        unsigned char   low;                            /* low  8 bit */
        unsigned char   mid;                            /* mid  8 bit */
        unsigned char   high;                           /* high 8 bit */
        unsigned char   nc;                             /* non use    */
    } byte;
    unsigned long   dword;
};
/********************************************************
*	declare SFR bit										*
********************************************************/
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
/******************************************************************************/
/*  Definition of SFR                                                         */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/*  Processor Mode Register 0                                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pm0_addr		0004h
union BYTE_DEF	pm0_addr;
#define		pm0				pm0_addr.byte

#define		pm00			pm0_addr.bit.b0				/* Processor mode bit */
#define		pm01			pm0_addr.bit.b1				/* Processor mode bit */
#define		pm02			pm0_addr.bit.b2				/* R/W mode select bit */
#define		pm03			pm0_addr.bit.b3				/* Software reset bit */
#define		pm04			pm0_addr.bit.b4				/* Multiplexed bus space select bit */
#define		pm05			pm0_addr.bit.b5				/* Multiplexed bus space select bit */
#define		pm06			pm0_addr.bit.b6				/* Port P4_0 to P4_3 function select bit */
#define		pm07			pm0_addr.bit.b7				/* BCLK output disable bit */

/*----------------------------------------------------------------------------*/
/*  Processor Mode Register 1                                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pm1_addr		0005h
union BYTE_DEF	pm1_addr;
#define		pm1				pm1_addr.byte

#define		pm10			pm1_addr.bit.b0				/* CS2~ area switch bit(data flash enable bit) */
#define		pm11			pm1_addr.bit.b1				/* Port P3_7 to P3_4 function select bit */
#define		pm12			pm1_addr.bit.b2				/* Watchdog timer function select bit */
#define		pm13			pm1_addr.bit.b3				/* Internal reserved area expansion bit */
#define		pm14			pm1_addr.bit.b4				/* Memory area expansion bit */
#define		pm15			pm1_addr.bit.b5				/* Memory area expansion bit */
#define		pm17			pm1_addr.bit.b7				/* Wait bit */

/*----------------------------------------------------------------------------*/
/*  System Clock Control Register 0                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cm0_addr		0006h
union BYTE_DEF	cm0_addr;
#define		cm0				cm0_addr.byte

#define		cm00			cm0_addr.bit.b0				/* Clock output function select bit(valid in single-chip mode only) */
#define		cm01			cm0_addr.bit.b1				/* Clock output function select bit(valid in single-chip mode only) */
#define		cm02			cm0_addr.bit.b2				/* Wait mode peripheral function clock stop bit */
#define		cm03			cm0_addr.bit.b3				/* XCIN-XCOUT drive capacity select bit */
#define		cm04			cm0_addr.bit.b4				/* Port XC select bit */
#define		cm05			cm0_addr.bit.b5				/* Main clock stop bit */
#define		cm06			cm0_addr.bit.b6				/* Main clock division select bit 0 */
#define		cm07			cm0_addr.bit.b7				/* System clock select bit */

/*----------------------------------------------------------------------------*/
/*  System Clock Control Register 1                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cm1_addr		0007h
union BYTE_DEF	cm1_addr;
#define		cm1				cm1_addr.byte

#define		cm10			cm1_addr.bit.b0				/* All clock stop control bit */
#define		cm11			cm1_addr.bit.b1				/* System clock select bit 1 */
#define		cm13			cm1_addr.bit.b3				/* XIN-XOUT feedback register select bit */
#define		cm14			cm1_addr.bit.b4				/* 125kHz on-chip oscillator stop bit */
#define		cm15			cm1_addr.bit.b5				/* XIN-XOUT drive capacity select bit */
#define		cm16			cm1_addr.bit.b6				/* Main clock division select bit 1 */
#define		cm17			cm1_addr.bit.b7				/* Main clock division select bit 1 */

/*----------------------------------------------------------------------------*/
/*  Chip Select Control Register                                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		csr_addr		0008h
union BYTE_DEF	csr_addr;
#define		csr				csr_addr.byte

#define		cs0				csr_addr.bit.b0				/* CS0~ output enable bit */
#define		cs1				csr_addr.bit.b1				/* CS1~ output enable bit */
#define		cs2				csr_addr.bit.b2				/* CS2~ output enable bit */
#define		cs3				csr_addr.bit.b3				/* CS3~ output enable bit */
#define		cs0w			csr_addr.bit.b4				/* CS0~ wait bit */
#define		cs1w			csr_addr.bit.b5				/* CS1~ wait bit */
#define		cs2w			csr_addr.bit.b6				/* CS2~ wait bit */
#define		cs3w			csr_addr.bit.b7				/* CS3~ wait bit */

/*----------------------------------------------------------------------------*/
/*  Protect Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		prcr_addr		000Ah
union BYTE_DEF	prcr_addr;
#define		prcr			prcr_addr.byte

#define		prc0			prcr_addr.bit.b0			/* Protect bit 0 */
#define		prc1			prcr_addr.bit.b1			/* Protect bit 1 */
#define		prc2			prcr_addr.bit.b2			/* Protect bit 2 */
#define		prc3			prcr_addr.bit.b3			/* Protect bit 3 */
#define		prc6			prcr_addr.bit.b6			/* Protect bit 6 */

/*----------------------------------------------------------------------------*/
/*  Data Bank Register                                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dbr_addr		000Bh
union BYTE_DEF	dbr_addr;
#define		dbr				dbr_addr.byte

#define		ofs				dbr_addr.bit.b2				/* Offset bit */
#define		bsr0			dbr_addr.bit.b3				/* Bank select bit */
#define		bsr1			dbr_addr.bit.b4				/* Bank select bit */
#define		bsr2			dbr_addr.bit.b5				/* Bank select bit */

/*----------------------------------------------------------------------------*/
/*  Oscillation Stop Detection Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cm2_addr		000Ch
union BYTE_DEF	cm2_addr;
#define		cm2				cm2_addr.byte

#define		cm20			cm2_addr.bit.b0				/* Oscillator stop/restart detect enable bit */
#define		cm21			cm2_addr.bit.b1				/* System clock select bit 2 */
#define		cm22			cm2_addr.bit.b2				/* Oscillator stop/restart detect flag */
#define		cm23			cm2_addr.bit.b3				/* XIN monitor flag */
#define		cm27			cm2_addr.bit.b7				/* Operation select bit(when an oscillator stop/restart is detected) */

/*----------------------------------------------------------------------------*/
/*  Program 2 Area Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		prg2c_addr		0010h
union BYTE_DEF	prg2c_addr;
#define		prg2c			prg2c_addr.byte

#define		prg2c0			prg2c_addr.bit.b0			/* Program ROM 2 disable bit */

/*----------------------------------------------------------------------------*/
/*  Peripheral Clock Select Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pclkr_addr		0012h
union BYTE_DEF	pclkr_addr;
#define		pclkr			pclkr_addr.byte

#define		pclk0			pclkr_addr.bit.b0			/* Timers A and B clock select bit */
#define		pclk1			pclkr_addr.bit.b1			/* SI/O clock select bit */
#define		pclk5			pclkr_addr.bit.b5			/* Clock output function extension bit(valid in single-chip mode) */

/*----------------------------------------------------------------------------*/
/*  Clock Prescaler Reset Flag                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cpsrf_addr		0015h
union BYTE_DEF	cpsrf_addr;
#define		cpsrf			cpsrf_addr.byte

#define		cpsr			cpsrf_addr.bit.b7			/* Clock prescaler reset flag */

/*----------------------------------------------------------------------------*/
/*  Reset Source Determine Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rstfr_addr		0018h
union BYTE_DEF	rstfr_addr;
#define		rstfr			rstfr_addr.byte

#define		cwr				rstfr_addr.bit.b0			/* Cold start-up/warm start-up discrimination flag */
#define		hwr				rstfr_addr.bit.b1			/* Hardware reset detection flag */
#define		swr				rstfr_addr.bit.b2			/* Software reset detection flag */
#define		wdr				rstfr_addr.bit.b3			/* Watchdog timer reset detection flag */
#define		lvd1r			rstfr_addr.bit.b4			/* Voltage monitor 1 reset detection flag */
#define		lvd2r			rstfr_addr.bit.b5			/* Voltage monitor 2 reset detection flag */
#define		osdr			rstfr_addr.bit.b6			/* Oscillator stop detect reset detect flag */

/*----------------------------------------------------------------------------*/
/*  Voltage Detector 2 Flag Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vcr1_addr		0019h
union BYTE_DEF	vcr1_addr;
#define		vcr1			vcr1_addr.byte

#define		vc13			vcr1_addr.bit.b3			/* Low-voltage monitor flag */

/*----------------------------------------------------------------------------*/
/*  Voltage Detector Operation Enable Register                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vcr2_addr		001Ah
union BYTE_DEF	vcr2_addr;
#define		vcr2			vcr2_addr.byte

#define		vc25			vcr2_addr.bit.b5			/* Voltage detector 0 enable bit */
#define		vc26			vcr2_addr.bit.b6			/* Voltage detector 1 enable bit */
#define		vc27			vcr2_addr.bit.b7			/* Voltage detector 2 enable bit */

/*----------------------------------------------------------------------------*/
/*  Chip Select Expansion Control Register                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cse_addr		001Bh
union BYTE_DEF	cse_addr;
#define		cse				cse_addr.byte

#define		cse00w			cse_addr.bit.b0				/* CS0~ wait expansion bit */
#define		cse01w			cse_addr.bit.b1				/* CS0~ wait expansion bit */
#define		cse10w			cse_addr.bit.b2				/* CS1~ wait expansion bit */
#define		cse11w			cse_addr.bit.b3				/* CS1~ wait expansion bit */
#define		cse20w			cse_addr.bit.b4				/* CS2~ wait expansion bit */
#define		cse21w			cse_addr.bit.b5				/* CS2~ wait expansion bit */
#define		cse30w			cse_addr.bit.b6				/* CS3~ wait expansion bit */
#define		cse31w			cse_addr.bit.b7				/* CS3~ wait expansion bit */

/*----------------------------------------------------------------------------*/
/*  PLL Control Register 0                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		plc0_addr		001Ch
union BYTE_DEF	plc0_addr;
#define		plc0			plc0_addr.byte

#define		plc00			plc0_addr.bit.b0			/* PLL multiplying factor select bit */
#define		plc01			plc0_addr.bit.b1			/* PLL multiplying factor select bit */
#define		plc02			plc0_addr.bit.b2			/* PLL multiplying factor select bit */
#define		plc04			plc0_addr.bit.b4			/* Reference frequency counter set bit */
#define		plc05			plc0_addr.bit.b5			/* Reference frequency counter set bit */
#define		plc07			plc0_addr.bit.b7			/* Operation enable bit */

/*----------------------------------------------------------------------------*/
/*  Processor Mode Register 2                                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pm2_addr		001Eh
union BYTE_DEF	pm2_addr;
#define		pm2				pm2_addr.byte

#define		pm21			pm2_addr.bit.b1				/* System clock protection bit */
#define		pm24			pm2_addr.bit.b4				/* NMI~ interrupt enable bit */
#define		pm25			pm2_addr.bit.b5				/* Peripheral clock fC provide bit */

/*----------------------------------------------------------------------------*/
/*  Voltage Monitor Function Select Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vwce_addr		0026h
union BYTE_DEF	vwce_addr;
#define		vwce			vwce_addr.byte

#define		vw12e			vwce_addr.bit.b0			/* Voltage detectors 1 and 2 enable bit */

/*----------------------------------------------------------------------------*/
/*  Voltage Detector 1 Level Select Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vd1ls_addr		0028h
union BYTE_DEF	vd1ls_addr;
#define		vd1ls			vd1ls_addr.byte

#define		vd1ls0			vd1ls_addr.bit.b0			/* Vdet1 Select Bit */
#define		vd1ls1			vd1ls_addr.bit.b1			/* Vdet1 Select Bit */
#define		vd1ls2			vd1ls_addr.bit.b2			/* Vdet1 Select Bit */
#define		vd1ls3			vd1ls_addr.bit.b3			/* Vdet1 Select Bit */

/*----------------------------------------------------------------------------*/
/*  Voltage Monitor 0 Control Register                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vw0c_addr		002Ah
union BYTE_DEF	vw0c_addr;
#define		vw0c			vw0c_addr.byte

#define		vw0c0			vw0c_addr.bit.b0			/* Voltage monitor 0 reset enable bit */
#define		vw0c1			vw0c_addr.bit.b1			/* Voltage monitor 0 digital filter disable mode select bit */
#define		vw0f0			vw0c_addr.bit.b4			/* Sampling clock select bit */
#define		vw0f1			vw0c_addr.bit.b5			/* Sampling clock select bit */

/*----------------------------------------------------------------------------*/
/*  Voltage Monitor 1 Control Register                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vw1c_addr		002Bh
union BYTE_DEF	vw1c_addr;
#define		vw1c			vw1c_addr.byte

#define		vw1c0			vw1c_addr.bit.b0			/* Voltage monitor 1 interrupt/reset enable bit */
#define		vw1c1			vw1c_addr.bit.b1			/* Voltage monitor 1 digital filter disable mode select bit */
#define		vw1c2			vw1c_addr.bit.b2			/* Voltage change detection flag */
#define		vw1c3			vw1c_addr.bit.b3			/* Voltage detector 1 signal monitor flag */
#define		vw1f0			vw1c_addr.bit.b4			/* Sampling clock select bit */
#define		vw1f1			vw1c_addr.bit.b5			/* Sampling clock select bit */
#define		vw1c6			vw1c_addr.bit.b6			/* Voltage monitor 1 mode select bit */
#define		vw1c7			vw1c_addr.bit.b7			/* Voltage monitor 1 interrupt/reset generation condition select bit */

/*----------------------------------------------------------------------------*/
/*  Voltage Monitor 2 Control Register                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		vw2c_addr		002Ch
union BYTE_DEF	vw2c_addr;
#define		vw2c			vw2c_addr.byte

#define		vw2c0			vw2c_addr.bit.b0			/* Voltage monitor 2 interrupt/reset enable bit */
#define		vw2c1			vw2c_addr.bit.b1			/* Voltage monitor 2 digital filter disable mode select bit */
#define		vw2c2			vw2c_addr.bit.b2			/* Voltage change detection flag */
#define		vw2c3			vw2c_addr.bit.b3			/* WDT detection flag */
#define		vw2f0			vw2c_addr.bit.b4			/* Sampling clock select bit */
#define		vw2f1			vw2c_addr.bit.b5			/* Sampling clock select bit */
#define		vw2c6			vw2c_addr.bit.b6			/* Voltage monitor 2 mode select bit */
#define		vw2c7			vw2c_addr.bit.b7			/* Voltage monitor 2 interrupt/reset generation condition select bit */

/*----------------------------------------------------------------------------*/
/*  INT7~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int7ic_addr		0042h
union BYTE_DEF	int7ic_addr;
#define		int7ic			int7ic_addr.byte

#define		ilvl0_int7ic	int7ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int7ic	int7ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int7ic	int7ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int7ic		int7ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int7ic		int7ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT6~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int6ic_addr		0043h
union BYTE_DEF	int6ic_addr;
#define		int6ic			int6ic_addr.byte

#define		ilvl0_int6ic	int6ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int6ic	int6ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int6ic	int6ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int6ic		int6ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int6ic		int6ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT3~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int3ic_addr		0044h
union BYTE_DEF	int3ic_addr;
#define		int3ic			int3ic_addr.byte

#define		ilvl0_int3ic	int3ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int3ic	int3ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int3ic	int3ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int3ic		int3ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int3ic		int3ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B5 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb5ic_addr		0045h
union BYTE_DEF	tb5ic_addr;
#define		tb5ic			tb5ic_addr.byte

#define		ilvl0_tb5ic		tb5ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb5ic		tb5ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb5ic		tb5ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb5ic		tb5ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer B4 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb4ic_addr		0046h
union BYTE_DEF	tb4ic_addr;
#define		tb4ic			tb4ic_addr.byte

#define		ilvl0_tb4ic		tb4ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb4ic		tb4ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb4ic		tb4ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb4ic		tb4ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1bcnic_addr	0046h
union BYTE_DEF	u1bcnic_addr;
#define		u1bcnic			u1bcnic_addr.byte

#define		ilvl0_u1bcnic	u1bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_u1bcnic	u1bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_u1bcnic	u1bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_u1bcnic		u1bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer B3 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb3ic_addr		0047h
union BYTE_DEF	tb3ic_addr;
#define		tb3ic			tb3ic_addr.byte

#define		ilvl0_tb3ic		tb3ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb3ic		tb3ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb3ic		tb3ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb3ic		tb3ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0bcnic_addr	0047h
union BYTE_DEF	u0bcnic_addr;
#define		u0bcnic			u0bcnic_addr.byte

#define		ilvl0_u0bcnic	u0bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_u0bcnic	u0bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_u0bcnic	u0bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_u0bcnic		u0bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  SI/O4 Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s4ic_addr		0048h
union BYTE_DEF	s4ic_addr;
#define		s4ic			s4ic_addr.byte

#define		ilvl0_s4ic		s4ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s4ic		s4ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s4ic		s4ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s4ic			s4ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_s4ic		s4ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT5~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int5ic_addr		0048h
union BYTE_DEF	int5ic_addr;
#define		int5ic			int5ic_addr.byte

#define		ilvl0_int5ic	int5ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int5ic	int5ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int5ic	int5ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int5ic		int5ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int5ic		int5ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  SI/O3 Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s3ic_addr		0049h
union BYTE_DEF	s3ic_addr;
#define		s3ic			s3ic_addr.byte

#define		ilvl0_s3ic		s3ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s3ic		s3ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s3ic		s3ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s3ic			s3ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_s3ic		s3ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT4~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int4ic_addr		0049h
union BYTE_DEF	int4ic_addr;
#define		int4ic			int4ic_addr.byte

#define		ilvl0_int4ic	int4ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int4ic	int4ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int4ic	int4ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int4ic		int4ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int4ic		int4ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		bcnic_addr		004Ah
union BYTE_DEF	bcnic_addr;
#define		bcnic			bcnic_addr.byte

#define		ilvl0_bcnic		bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_bcnic		bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_bcnic		bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_bcnic		bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  DMA0 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm0ic_addr		004Bh
union BYTE_DEF	dm0ic_addr;
#define		dm0ic			dm0ic_addr.byte

#define		ilvl0_dm0ic		dm0ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_dm0ic		dm0ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_dm0ic		dm0ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_dm0ic		dm0ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  DMA1 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm1ic_addr		004Ch
union BYTE_DEF	dm1ic_addr;
#define		dm1ic			dm1ic_addr.byte

#define		ilvl0_dm1ic		dm1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_dm1ic		dm1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_dm1ic		dm1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_dm1ic		dm1ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Key Input Interrupt Control Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		kupic_addr		004Dh
union BYTE_DEF	kupic_addr;
#define		kupic			kupic_addr.byte

#define		ilvl0_kupic		kupic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_kupic		kupic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_kupic		kupic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_kupic		kupic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  A/D Conversion Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		adic_addr		004Eh
union BYTE_DEF	adic_addr;
#define		adic			adic_addr.byte

#define		ilvl0_adic		adic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_adic		adic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_adic		adic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_adic			adic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s2tic_addr		004Fh
union BYTE_DEF	s2tic_addr;
#define		s2tic			s2tic_addr.byte

#define		ilvl0_s2tic		s2tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s2tic		s2tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s2tic		s2tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s2tic		s2tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s2ric_addr		0050h
union BYTE_DEF	s2ric_addr;
#define		s2ric			s2ric_addr.byte

#define		ilvl0_s2ric		s2ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s2ric		s2ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s2ric		s2ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s2ric		s2ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s0tic_addr		0051h
union BYTE_DEF	s0tic_addr;
#define		s0tic			s0tic_addr.byte

#define		ilvl0_s0tic		s0tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s0tic		s0tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s0tic		s0tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s0tic		s0tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s0ric_addr		0052h
union BYTE_DEF	s0ric_addr;
#define		s0ric			s0ric_addr.byte

#define		ilvl0_s0ric		s0ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s0ric		s0ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s0ric		s0ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s0ric		s0ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s1tic_addr		0053h
union BYTE_DEF	s1tic_addr;
#define		s1tic			s1tic_addr.byte

#define		ilvl0_s1tic		s1tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s1tic		s1tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s1tic		s1tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s1tic		s1tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s1ric_addr		0054h
union BYTE_DEF	s1ric_addr;
#define		s1ric			s1ric_addr.byte

#define		ilvl0_s1ric		s1ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s1ric		s1ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s1ric		s1ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s1ric		s1ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer A0 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta0ic_addr		0055h
union BYTE_DEF	ta0ic_addr;
#define		ta0ic			ta0ic_addr.byte

#define		ilvl0_ta0ic		ta0ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_ta0ic		ta0ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_ta0ic		ta0ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_ta0ic		ta0ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer A1 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta1ic_addr		0056h
union BYTE_DEF	ta1ic_addr;
#define		ta1ic			ta1ic_addr.byte

#define		ilvl0_ta1ic		ta1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_ta1ic		ta1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_ta1ic		ta1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_ta1ic		ta1ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer A2 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta2ic_addr		0057h
union BYTE_DEF	ta2ic_addr;
#define		ta2ic			ta2ic_addr.byte

#define		ilvl0_ta2ic		ta2ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_ta2ic		ta2ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_ta2ic		ta2ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_ta2ic		ta2ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer A3 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta3ic_addr		0058h
union BYTE_DEF	ta3ic_addr;
#define		ta3ic			ta3ic_addr.byte

#define		ilvl0_ta3ic		ta3ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_ta3ic		ta3ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_ta3ic		ta3ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_ta3ic		ta3ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer A4 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta4ic_addr		0059h
union BYTE_DEF	ta4ic_addr;
#define		ta4ic			ta4ic_addr.byte

#define		ilvl0_ta4ic		ta4ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_ta4ic		ta4ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_ta4ic		ta4ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_ta4ic		ta4ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer B0 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb0ic_addr		005Ah
union BYTE_DEF	tb0ic_addr;
#define		tb0ic			tb0ic_addr.byte

#define		ilvl0_tb0ic		tb0ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb0ic		tb0ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb0ic		tb0ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb0ic		tb0ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer B1 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb1ic_addr		005Bh
union BYTE_DEF	tb1ic_addr;
#define		tb1ic			tb1ic_addr.byte

#define		ilvl0_tb1ic		tb1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb1ic		tb1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb1ic		tb1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb1ic		tb1ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Timer B2 Interrupt Control Register                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb2ic_addr		005Ch
union BYTE_DEF	tb2ic_addr;
#define		tb2ic			tb2ic_addr.byte

#define		ilvl0_tb2ic		tb2ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_tb2ic		tb2ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_tb2ic		tb2ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_tb2ic		tb2ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  INT0~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int0ic_addr		005Dh
union BYTE_DEF	int0ic_addr;
#define		int0ic			int0ic_addr.byte

#define		ilvl0_int0ic	int0ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int0ic	int0ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int0ic	int0ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int0ic		int0ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int0ic		int0ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT1~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int1ic_addr		005Eh
union BYTE_DEF	int1ic_addr;
#define		int1ic			int1ic_addr.byte

#define		ilvl0_int1ic	int1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int1ic	int1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int1ic	int1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int1ic		int1ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int1ic		int1ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  INT2~ Interrupt Control Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		int2ic_addr		005Fh
union BYTE_DEF	int2ic_addr;
#define		int2ic			int2ic_addr.byte

#define		ilvl0_int2ic	int2ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_int2ic	int2ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_int2ic	int2ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_int2ic		int2ic_addr.bit.b3			/* Interrupt request bit */
#define		pol_int2ic		int2ic_addr.bit.b4			/* Polarity select bit */

/*----------------------------------------------------------------------------*/
/*  DMA2 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm2ic_addr		0069h
union BYTE_DEF	dm2ic_addr;
#define		dm2ic			dm2ic_addr.byte

#define		ilvl0_dm2ic		dm2ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_dm2ic		dm2ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_dm2ic		dm2ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_dm2ic		dm2ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  DMA3 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm3ic_addr		006Ah
union BYTE_DEF	dm3ic_addr;
#define		dm3ic			dm3ic_addr.byte

#define		ilvl0_dm3ic		dm3ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_dm3ic		dm3ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_dm3ic		dm3ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_dm3ic		dm3ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5bcnic_addr	006Bh
union BYTE_DEF	u5bcnic_addr;
#define		u5bcnic			u5bcnic_addr.byte

#define		ilvl0_u5bcnic	u5bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_u5bcnic	u5bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_u5bcnic	u5bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_u5bcnic		u5bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  CEC1 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cec1ic_addr		006Bh
union BYTE_DEF	cec1ic_addr;
#define		cec1ic			cec1ic_addr.byte

#define		ilvl0_cec1ic	cec1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_cec1ic	cec1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_cec1ic	cec1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_cec1ic		cec1ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s5tic_addr		006Ch
union BYTE_DEF	s5tic_addr;
#define		s5tic			s5tic_addr.byte

#define		ilvl0_s5tic		s5tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s5tic		s5tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s5tic		s5tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s5tic		s5tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  CEC2 Interrupt Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cec2ic_addr		006Ch
union BYTE_DEF	cec2ic_addr;
#define		cec2ic			cec2ic_addr.byte

#define		ilvl0_cec2ic	cec2ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_cec2ic	cec2ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_cec2ic	cec2ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_cec2ic		cec2ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s5ric_addr		006Dh
union BYTE_DEF	s5ric_addr;
#define		s5ric			s5ric_addr.byte

#define		ilvl0_s5ric		s5ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s5ric		s5ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s5ric		s5ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s5ric		s5ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6bcnic_addr	006Eh
union BYTE_DEF	u6bcnic_addr;
#define		u6bcnic			u6bcnic_addr.byte

#define		ilvl0_u6bcnic	u6bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_u6bcnic	u6bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_u6bcnic	u6bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_u6bcnic		u6bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Periodic Interrupt Control Register                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtctic_addr		006Eh
union BYTE_DEF	rtctic_addr;
#define		rtctic			rtctic_addr.byte

#define		ilvl0_rtctic	rtctic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_rtctic	rtctic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_rtctic	rtctic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_rtctic		rtctic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s6tic_addr		006Fh
union BYTE_DEF	s6tic_addr;
#define		s6tic			s6tic_addr.byte

#define		ilvl0_s6tic		s6tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s6tic		s6tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s6tic		s6tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s6tic		s6tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Compare Interrupt Control Register                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccic_addr		006Fh
union BYTE_DEF	rtccic_addr;
#define		rtccic			rtccic_addr.byte

#define		ilvl0_rtccic	rtccic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_rtccic	rtccic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_rtccic	rtccic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_rtccic		rtccic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s6ric_addr		0070h
union BYTE_DEF	s6ric_addr;
#define		s6ric			s6ric_addr.byte

#define		ilvl0_s6ric		s6ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s6ric		s6ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s6ric		s6ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s6ric		s6ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Bus Collision Detection Interrupt Control Register                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7bcnic_addr	0071h
union BYTE_DEF	u7bcnic_addr;
#define		u7bcnic			u7bcnic_addr.byte

#define		ilvl0_u7bcnic	u7bcnic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_u7bcnic	u7bcnic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_u7bcnic	u7bcnic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_u7bcnic		u7bcnic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Remote Control Signal Receiver 0 Interrupt Control Register               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0ic_addr		0071h
union BYTE_DEF	pmc0ic_addr;
#define		pmc0ic			pmc0ic_addr.byte

#define		ilvl0_pmc0ic	pmc0ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_pmc0ic	pmc0ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_pmc0ic	pmc0ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_pmc0ic		pmc0ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Transmit Interrupt Control Register                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s7tic_addr		0072h
union BYTE_DEF	s7tic_addr;
#define		s7tic			s7tic_addr.byte

#define		ilvl0_s7tic		s7tic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s7tic		s7tic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s7tic		s7tic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s7tic		s7tic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  Remote Control Signal Receiver 1 Interrupt Control Register               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1ic_addr		0072h
union BYTE_DEF	pmc1ic_addr;
#define		pmc1ic			pmc1ic_addr.byte

#define		ilvl0_pmc1ic	pmc1ic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_pmc1ic	pmc1ic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_pmc1ic	pmc1ic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_pmc1ic		pmc1ic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Receive Interrupt Control Register                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s7ric_addr		0073h
union BYTE_DEF	s7ric_addr;
#define		s7ric			s7ric_addr.byte

#define		ilvl0_s7ric		s7ric_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_s7ric		s7ric_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_s7ric		s7ric_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_s7ric		s7ric_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  I2C-bus Interface Interrupt Control Register                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		iicic_addr		007Bh
union BYTE_DEF	iicic_addr;
#define		iicic			iicic_addr.byte

#define		ilvl0_iicic		iicic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_iicic		iicic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_iicic		iicic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_iicic		iicic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  SCL/SDA Interrupt Control Register                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		scldaic_addr	007Ch
union BYTE_DEF	scldaic_addr;
#define		scldaic			scldaic_addr.byte

#define		ilvl0_scldaic	scldaic_addr.bit.b0			/* Interrupt priority level select bit */
#define		ilvl1_scldaic	scldaic_addr.bit.b1			/* Interrupt priority level select bit */
#define		ilvl2_scldaic	scldaic_addr.bit.b2			/* Interrupt priority level select bit */
#define		ir_scldaic		scldaic_addr.bit.b3			/* Interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  DMA0 Source Pointer                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		sar0_addr		0180h
union DWORD_DEF	sar0_addr;
#define		sar0			sar0_addr.dword
#define		sar0l			sar0_addr.byte.low			/* DMA0 Source Pointer(low 8bit) */
#define		sar0m			sar0_addr.byte.mid			/* DMA0 Source Pointer(mid 8bit) */
#define		sar0h			sar0_addr.byte.high			/* DMA0 Source Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA0 Destination Pointer                                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dar0_addr		0184h
union DWORD_DEF	dar0_addr;
#define		dar0			dar0_addr.dword
#define		dar0l			dar0_addr.byte.low			/* DMA0 Destination Pointer(low 8bit) */
#define		dar0m			dar0_addr.byte.mid			/* DMA0 Destination Pointer(mid 8bit) */
#define		dar0h			dar0_addr.byte.high			/* DMA0 Destination Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA0 Transfer Counter                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tcr0_addr		0188h
union WORD_DEF	tcr0_addr;
#define		tcr0			tcr0_addr.word
#define		tcr0l			tcr0_addr.byte.low			/* DMA0 Transfer Counter(low 8bit) */
#define		tcr0h			tcr0_addr.byte.high			/* DMA0 Transfer Counter(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA0 Control Register                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm0con_addr		018Ch
union BYTE_DEF	dm0con_addr;
#define		dm0con			dm0con_addr.byte

#define		dmbit_dm0con	dm0con_addr.bit.b0			/* Transfer unit bit select bit */
#define		dmasl_dm0con	dm0con_addr.bit.b1			/* Repeat transfer mode select bit */
#define		dmas_dm0con		dm0con_addr.bit.b2			/* DMA request bit */
#define		dmae_dm0con		dm0con_addr.bit.b3			/* DMA enable bit */
#define		dsd_dm0con		dm0con_addr.bit.b4			/* Source address direction select bit */
#define		dad_dm0con		dm0con_addr.bit.b5			/* Destination address direction select bit */

/*----------------------------------------------------------------------------*/
/*  DMA1 Source Pointer                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		sar1_addr		0190h
union DWORD_DEF	sar1_addr;
#define		sar1			sar1_addr.dword
#define		sar1l			sar1_addr.byte.low			/* DMA1 Source Pointer(low 8bit) */
#define		sar1m			sar1_addr.byte.mid			/* DMA1 Source Pointer(mid 8bit) */
#define		sar1h			sar1_addr.byte.high			/* DMA1 Source Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA1 Destination Pointer                                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dar1_addr		0194h
union DWORD_DEF	dar1_addr;
#define		dar1			dar1_addr.dword
#define		dar1l			dar1_addr.byte.low			/* DMA1 Destination Pointer(low 8bit) */
#define		dar1m			dar1_addr.byte.mid			/* DMA1 Destination Pointer(mid 8bit) */
#define		dar1h			dar1_addr.byte.high			/* DMA1 Destination Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA1 Transfer Counter                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tcr1_addr		0198h
union WORD_DEF	tcr1_addr;
#define		tcr1			tcr1_addr.word
#define		tcr1l			tcr1_addr.byte.low			/* DMA1 Transfer Counter(low 8bit) */
#define		tcr1h			tcr1_addr.byte.high			/* DMA1 Transfer Counter(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA1 Control Register                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm1con_addr		019Ch
union BYTE_DEF	dm1con_addr;
#define		dm1con			dm1con_addr.byte

#define		dmbit_dm1con	dm1con_addr.bit.b0			/* Transfer unit bit select bit */
#define		dmasl_dm1con	dm1con_addr.bit.b1			/* Repeat transfer mode select bit */
#define		dmas_dm1con		dm1con_addr.bit.b2			/* DMA request bit */
#define		dmae_dm1con		dm1con_addr.bit.b3			/* DMA enable bit */
#define		dsd_dm1con		dm1con_addr.bit.b4			/* Source address direction select bit */
#define		dad_dm1con		dm1con_addr.bit.b5			/* Destination address direction select bit */

/*----------------------------------------------------------------------------*/
/*  DMA2 Source Pointer                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		sar2_addr		01A0h
union DWORD_DEF	sar2_addr;
#define		sar2			sar2_addr.dword
#define		sar2l			sar2_addr.byte.low			/* DMA2 Source Pointer(low 8bit) */
#define		sar2m			sar2_addr.byte.mid			/* DMA2 Source Pointer(mid 8bit) */
#define		sar2h			sar2_addr.byte.high			/* DMA2 Source Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA2 Destination Pointer                                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dar2_addr		01A4h
union DWORD_DEF	dar2_addr;
#define		dar2			dar2_addr.dword
#define		dar2l			dar2_addr.byte.low			/* DMA2 Destination Pointer(low 8bit) */
#define		dar2m			dar2_addr.byte.mid			/* DMA2 Destination Pointer(mid 8bit) */
#define		dar2h			dar2_addr.byte.high			/* DMA2 Destination Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA2 Transfer Counter                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tcr2_addr		01A8h
union WORD_DEF	tcr2_addr;
#define		tcr2			tcr2_addr.word
#define		tcr2l			tcr2_addr.byte.low			/* DMA2 Transfer Counter(low 8bit) */
#define		tcr2h			tcr2_addr.byte.high			/* DMA2 Transfer Counter(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA2 Control Register                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm2con_addr		01ACh
union BYTE_DEF	dm2con_addr;
#define		dm2con			dm2con_addr.byte

#define		dmbit_dm2con	dm2con_addr.bit.b0			/* Transfer unit bit select bit */
#define		dmasl_dm2con	dm2con_addr.bit.b1			/* Repeat transfer mode select bit */
#define		dmas_dm2con		dm2con_addr.bit.b2			/* DMA request bit */
#define		dmae_dm2con		dm2con_addr.bit.b3			/* DMA enable bit */
#define		dsd_dm2con		dm2con_addr.bit.b4			/* Source address direction select bit */
#define		dad_dm2con		dm2con_addr.bit.b5			/* Destination address direction select bit */

/*----------------------------------------------------------------------------*/
/*  DMA3 Source Pointer                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		sar3_addr		01B0h
union DWORD_DEF	sar3_addr;
#define		sar3			sar3_addr.dword
#define		sar3l			sar3_addr.byte.low			/* DMA3 Source Pointer(low 8bit) */
#define		sar3m			sar3_addr.byte.mid			/* DMA3 Source Pointer(mid 8bit) */
#define		sar3h			sar3_addr.byte.high			/* DMA3 Source Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA3 Destination Pointer                                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dar3_addr		01B4h
union DWORD_DEF	dar3_addr;
#define		dar3			dar3_addr.dword
#define		dar3l			dar3_addr.byte.low			/* DMA3 Destination Pointer(low 8bit) */
#define		dar3m			dar3_addr.byte.mid			/* DMA3 Destination Pointer(mid 8bit) */
#define		dar3h			dar3_addr.byte.high			/* DMA3 Destination Pointer(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA3 Transfer Counter                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tcr3_addr		01B8h
union WORD_DEF	tcr3_addr;
#define		tcr3			tcr3_addr.word
#define		tcr3l			tcr3_addr.byte.low			/* DMA3 Transfer Counter(low 8bit) */
#define		tcr3h			tcr3_addr.byte.high			/* DMA3 Transfer Counter(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  DMA3 Control Register                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm3con_addr		01BCh
union BYTE_DEF	dm3con_addr;
#define		dm3con			dm3con_addr.byte

#define		dmbit_dm3con	dm3con_addr.bit.b0			/* Transfer unit bit select bit */
#define		dmasl_dm3con	dm3con_addr.bit.b1			/* Repeat transfer mode select bit */
#define		dmas_dm3con		dm3con_addr.bit.b2			/* DMA request bit */
#define		dmae_dm3con		dm3con_addr.bit.b3			/* DMA enable bit */
#define		dsd_dm3con		dm3con_addr.bit.b4			/* Source address direction select bit */
#define		dad_dm3con		dm3con_addr.bit.b5			/* Destination address direction select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B0-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb01_addr		01C0h
union WORD_DEF	tb01_addr;
#define		tb01			tb01_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B1-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb11_addr		01C2h
union WORD_DEF	tb11_addr;
#define		tb11			tb11_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B2-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb21_addr		01C4h
union WORD_DEF	tb21_addr;
#define		tb21			tb21_addr.word

/*----------------------------------------------------------------------------*/
/*  Pulse Period/Pulse Width Measurement Mode Function Select Register 1      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ppwfs1_addr		01C6h
union BYTE_DEF	ppwfs1_addr;
#define		ppwfs1			ppwfs1_addr.byte

#define		ppwfs10			ppwfs1_addr.bit.b0			/* Timer B0 pulse period/pulse width measurement mode function select bit */
#define		ppwfs11			ppwfs1_addr.bit.b1			/* Timer B1 pulse period/pulse width measurement mode function select bit */
#define		ppwfs12			ppwfs1_addr.bit.b2			/* Timer B2 pulse period/pulse width measurement mode function select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B Count Source Select Register 0                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tbcs0_addr		01C8h
union BYTE_DEF	tbcs0_addr;
#define		tbcs0			tbcs0_addr.byte

#define		tcs0_tbcs0		tbcs0_addr.bit.b0			/* TB0 count source select bit */
#define		tcs1_tbcs0		tbcs0_addr.bit.b1			/* TB0 count source select bit */
#define		tcs2_tbcs0		tbcs0_addr.bit.b2			/* TB0 count source select bit */
#define		tcs3_tbcs0		tbcs0_addr.bit.b3			/* TB0 count source option specified bit */
#define		tcs4_tbcs0		tbcs0_addr.bit.b4			/* TB1 count source select bit */
#define		tcs5_tbcs0		tbcs0_addr.bit.b5			/* TB1 count source select bit */
#define		tcs6_tbcs0		tbcs0_addr.bit.b6			/* TB1 count source select bit */
#define		tcs7_tbcs0		tbcs0_addr.bit.b7			/* TB1 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  Timer B Count Source Select Register 1                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tbcs1_addr		01C9h
union BYTE_DEF	tbcs1_addr;
#define		tbcs1			tbcs1_addr.byte

#define		tcs0_tbcs1		tbcs1_addr.bit.b0			/* TB2 count source select bit */
#define		tcs1_tbcs1		tbcs1_addr.bit.b1			/* TB2 count source select bit */
#define		tcs2_tbcs1		tbcs1_addr.bit.b2			/* TB2 count source select bit */
#define		tcs3_tbcs1		tbcs1_addr.bit.b3			/* TB2 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  Timer A Count Source Select Register 0                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tacs0_addr		01D0h
union BYTE_DEF	tacs0_addr;
#define		tacs0			tacs0_addr.byte

#define		tcs0_tacs0		tacs0_addr.bit.b0			/* TA0 count source select bit */
#define		tcs1_tacs0		tacs0_addr.bit.b1			/* TA0 count source select bit */
#define		tcs2_tacs0		tacs0_addr.bit.b2			/* TA0 count source select bit */
#define		tcs3_tacs0		tacs0_addr.bit.b3			/* TA0 count source option specified bit */
#define		tcs4_tacs0		tacs0_addr.bit.b4			/* TA1 count source select bit */
#define		tcs5_tacs0		tacs0_addr.bit.b5			/* TA1 count source select bit */
#define		tcs6_tacs0		tacs0_addr.bit.b6			/* TA1 count source select bit */
#define		tcs7_tacs0		tacs0_addr.bit.b7			/* TA1 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  Timer A Count Source Select Register 1                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tacs1_addr		01D1h
union BYTE_DEF	tacs1_addr;
#define		tacs1			tacs1_addr.byte

#define		tcs0_tacs1		tacs1_addr.bit.b0			/* TA2 count source select bit */
#define		tcs1_tacs1		tacs1_addr.bit.b1			/* TA2 count source select bit */
#define		tcs2_tacs1		tacs1_addr.bit.b2			/* TA2 count source select bit */
#define		tcs3_tacs1		tacs1_addr.bit.b3			/* TA2 count source option specified bit */
#define		tcs4_tacs1		tacs1_addr.bit.b4			/* TA3 count source select bit */
#define		tcs5_tacs1		tacs1_addr.bit.b5			/* TA3 count source select bit */
#define		tcs6_tacs1		tacs1_addr.bit.b6			/* TA3 count source select bit */
#define		tcs7_tacs1		tacs1_addr.bit.b7			/* TA3 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  Timer A Count Source Select Register 2                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tacs2_addr		01D2h
union BYTE_DEF	tacs2_addr;
#define		tacs2			tacs2_addr.byte

#define		tcs0_tacs2		tacs2_addr.bit.b0			/* TA4 count source select bit */
#define		tcs1_tacs2		tacs2_addr.bit.b1			/* TA4 count source select bit */
#define		tcs2_tacs2		tacs2_addr.bit.b2			/* TA4 count source select bit */
#define		tcs3_tacs2		tacs2_addr.bit.b3			/* TA4 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  16-Bit Pulse Width Modulation Mode Function Select Register               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmfs_addr		01D4h
union BYTE_DEF	pwmfs_addr;
#define		pwmfs			pwmfs_addr.byte

#define		pwmfs1			pwmfs_addr.bit.b1			/* Timer A1 programmable output mode select bit */
#define		pwmfs2			pwmfs_addr.bit.b2			/* Timer A2 programmable output mode select bit */
#define		pwmfs4			pwmfs_addr.bit.b4			/* Timer A4 programmable output mode select bit */

/*----------------------------------------------------------------------------*/
/*  Timer A Waveform Output Function Select Register                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tapofs_addr		01D5h
union BYTE_DEF	tapofs_addr;
#define		tapofs			tapofs_addr.byte

#define		pofs0			tapofs_addr.bit.b0			/* TA0OUT output polar control bit */
#define		pofs1			tapofs_addr.bit.b1			/* TA1OUT output polar control bit */
#define		pofs2			tapofs_addr.bit.b2			/* TA2OUT output polar control bit */
#define		pofs3			tapofs_addr.bit.b3			/* TA3OUT output polar control bit */
#define		pofs4			tapofs_addr.bit.b4			/* TA4OUT output polar control bit */

/*----------------------------------------------------------------------------*/
/*  Timer A Output Waveform Change Enable Register                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		taow_addr		01D8h
union BYTE_DEF	taow_addr;
#define		taow			taow_addr.byte

#define		ta1ow			taow_addr.bit.b1			/* Timer A1 output waveform change enable bit */
#define		ta2ow			taow_addr.bit.b2			/* Timer A2 output waveform change enable bit */
#define		ta4ow			taow_addr.bit.b4			/* Timer A4 output waveform change enable bit */

/*----------------------------------------------------------------------------*/
/*  Three-phase Protect Control Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tprc_addr		01DAh
union BYTE_DEF	tprc_addr;
#define		tprc			tprc_addr.byte

#define		tprc0			tprc_addr.bit.b0			/* Three-phase protect control bit */

/*----------------------------------------------------------------------------*/
/*  Timer B3-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb31_addr		01E0h
union WORD_DEF	tb31_addr;
#define		tb31			tb31_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B4-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb41_addr		01E2h
union WORD_DEF	tb41_addr;
#define		tb41			tb41_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B5-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb51_addr		01E4h
union WORD_DEF	tb51_addr;
#define		tb51			tb51_addr.word

/*----------------------------------------------------------------------------*/
/*  Pulse Period/Pulse Width Measurement Mode Function Select Register 2      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ppwfs2_addr		01E6h
union BYTE_DEF	ppwfs2_addr;
#define		ppwfs2			ppwfs2_addr.byte

#define		ppwfs20			ppwfs2_addr.bit.b0			/* Timer B3 pulse period/pulse width measurement mode function select bit */
#define		ppwfs21			ppwfs2_addr.bit.b1			/* Timer B4 pulse period/pulse width measurement mode function select bit */
#define		ppwfs22			ppwfs2_addr.bit.b2			/* Timer B5 pulse period/pulse width measurement mode function select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B Count Source Select Register 2                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tbcs2_addr		01E8h
union BYTE_DEF	tbcs2_addr;
#define		tbcs2			tbcs2_addr.byte

#define		tcs0_tbcs2		tbcs2_addr.bit.b0			/* TB3 count source select bit */
#define		tcs1_tbcs2		tbcs2_addr.bit.b1			/* TB3 count source select bit */
#define		tcs2_tbcs2		tbcs2_addr.bit.b2			/* TB3 count source select bit */
#define		tcs3_tbcs2		tbcs2_addr.bit.b3			/* TB3 count source option specified bit */
#define		tcs4_tbcs2		tbcs2_addr.bit.b4			/* TB4 count source select bit */
#define		tcs5_tbcs2		tbcs2_addr.bit.b5			/* TB4 count source select bit */
#define		tcs6_tbcs2		tbcs2_addr.bit.b6			/* TB4 count source select bit */
#define		tcs7_tbcs2		tbcs2_addr.bit.b7			/* TB4 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  Timer B Count Source Select Register 3                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tbcs3_addr		01E9h
union BYTE_DEF	tbcs3_addr;
#define		tbcs3			tbcs3_addr.byte

#define		tcs0_tbcs3		tbcs3_addr.bit.b0			/* TB5 count source select bit */
#define		tcs1_tbcs3		tbcs3_addr.bit.b1			/* TB5 count source select bit */
#define		tcs2_tbcs3		tbcs3_addr.bit.b2			/* TB5 count source select bit */
#define		tcs3_tbcs3		tbcs3_addr.bit.b3			/* TB5 count source option specified bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Function Select Register 0                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0con0_addr	01F0h
union BYTE_DEF	pmc0con0_addr;
#define		pmc0con0		pmc0con0_addr.byte

#define		en_pmc0con0		pmc0con0_addr.bit.b0		/* PMC0 operation enable bit */
#define		sinv_pmc0con0	pmc0con0_addr.bit.b1		/* Input signal polarity invert bit */
#define		fil_pmc0con0	pmc0con0_addr.bit.b2		/* Filter enable bit */
#define		ehold_pmc0con0	pmc0con0_addr.bit.b3		/* Error flag hold bit */
#define		hden_pmc0con0	pmc0con0_addr.bit.b4		/* Header pattern enable bit */
#define		sden_pmc0con0	pmc0con0_addr.bit.b5		/* Special data pattern enable bit */
#define		drint0_pmc0con0	pmc0con0_addr.bit.b6		/* Receive interrupt control bit */
#define		drint1_pmc0con0	pmc0con0_addr.bit.b7		/* Receive interrupt control bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Function Select Register 1                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0con1_addr	01F1h
union BYTE_DEF	pmc0con1_addr;
#define		pmc0con1		pmc0con1_addr.byte

#define		typ0_pmc0con1	pmc0con1_addr.bit.b0		/* Receive mode select bit */
#define		typ1_pmc0con1	pmc0con1_addr.bit.b1		/* Receive mode select bit */
#define		css_pmc0con1	pmc0con1_addr.bit.b2		/* Counter start control bit */
#define		exsden_pmc0con1	pmc0con1_addr.bit.b6		/* Special pattern detect block select bit */
#define		exhden_pmc0con1	pmc0con1_addr.bit.b7		/* Header pattern detect block select bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Function Select Register 2                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0con2_addr	01F2h
union BYTE_DEF	pmc0con2_addr;
#define		pmc0con2		pmc0con2_addr.byte

#define		enflg_pmc0con2	pmc0con2_addr.bit.b0		/* PMC0 status flag */
#define		inflg_pmc0con2	pmc0con2_addr.bit.b3		/* Input signal flag */
#define		ceflg_pmc0con2	pmc0con2_addr.bit.b4		/* Counter overflow flag */
#define		ceint_pmc0con2	pmc0con2_addr.bit.b5		/* Counter overflow interrupt enable bit */
#define		psel0_pmc0con2	pmc0con2_addr.bit.b6		/* Input pin select bit */
#define		psel1_pmc0con2	pmc0con2_addr.bit.b7		/* Input pin select bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Function Select Register 3                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0con3_addr	01F3h
union BYTE_DEF	pmc0con3_addr;
#define		pmc0con3		pmc0con3_addr.byte

#define		cre_pmc0con3	pmc0con3_addr.bit.b0		/* Mode select bit */
#define		cfr_pmc0con3	pmc0con3_addr.bit.b1		/* Mode select bit */
#define		cst_pmc0con3	pmc0con3_addr.bit.b2		/* Mode select bit */
#define		pd_pmc0con3		pmc0con3_addr.bit.b3		/* Mode select bit */
#define		csrc0_pmc0con3	pmc0con3_addr.bit.b4		/* Clock source select bit */
#define		csrc1_pmc0con3	pmc0con3_addr.bit.b5		/* Clock source select bit */
#define		cdiv0_pmc0con3	pmc0con3_addr.bit.b6		/* Count source divisor select bit */
#define		cdiv1_pmc0con3	pmc0con3_addr.bit.b7		/* Count source divisor select bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Status Register                                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0sts_addr	01F4h
union BYTE_DEF	pmc0sts_addr;
#define		pmc0sts			pmc0sts_addr.byte

#define		cpflg_pmc0sts	pmc0sts_addr.bit.b0			/* Compare match flag */
#define		reflg_pmc0sts	pmc0sts_addr.bit.b1			/* Receive error flag */
#define		drflg_pmc0sts	pmc0sts_addr.bit.b2			/* Data receiving flag */
#define		bfulflg_pmc0sts	pmc0sts_addr.bit.b3			/* Receive buffer full flag */
#define		pthdflg_pmc0sts	pmc0sts_addr.bit.b4			/* Header pattern match flag */
#define		ptd0flg_pmc0sts	pmc0sts_addr.bit.b5			/* Data 0 pattern match flag */
#define		ptd1flg_pmc0sts	pmc0sts_addr.bit.b6			/* Data 1 pattern match flag */
#define		sdflg_pmc0sts	pmc0sts_addr.bit.b7			/* Special pattern match flag */

/*----------------------------------------------------------------------------*/
/*  PMC0 Interrupt Source Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0int_addr	01F5h
union BYTE_DEF	pmc0int_addr;
#define		pmc0int			pmc0int_addr.byte

#define		cpint_pmc0int	pmc0int_addr.bit.b0			/* Compare match flag interrupt enable bit */
#define		reint_pmc0int	pmc0int_addr.bit.b1			/* Receive error flag interrupt enable bit */
#define		drint_pmc0int	pmc0int_addr.bit.b2			/* Data reception complete interrupt enable bit */
#define		bfulint_pmc0int	pmc0int_addr.bit.b3			/* Receive buffer full flag interrupt enable bit */
#define		pthdint_pmc0int	pmc0int_addr.bit.b4			/* Header match flag interrupt enable bit */
#define		ptdint_pmc0int	pmc0int_addr.bit.b5			/* Data 0/1 match flag interrupt enable bit */
#define		timint_pmc0int	pmc0int_addr.bit.b6			/* Timer measure interrupt enable bit */
#define		sdint_pmc0int	pmc0int_addr.bit.b7			/* Special data match flag interrupt enable bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Compare Control Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0cpc_addr	01F6h
union BYTE_DEF	pmc0cpc_addr;
#define		pmc0cpc			pmc0cpc_addr.byte

#define		cpn0			pmc0cpc_addr.bit.b0			/* Compare bit specified bit */
#define		cpn1			pmc0cpc_addr.bit.b1			/* Compare bit specified bit */
#define		cpn2			pmc0cpc_addr.bit.b2			/* Compare bit specified bit */
#define		cpen			pmc0cpc_addr.bit.b4			/* Compare enable bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Compare Data Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0cpd_addr	01F7h
union BYTE_DEF	pmc0cpd_addr;
#define		pmc0cpd			pmc0cpd_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Function Select Register 0                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1con0_addr	01F8h
union BYTE_DEF	pmc1con0_addr;
#define		pmc1con0		pmc1con0_addr.byte

#define		en_pmc1con0		pmc1con0_addr.bit.b0		/* PMC1 operation enable bit */
#define		sinv_pmc1con0	pmc1con0_addr.bit.b1		/* Input signal polarity invert bit */
#define		fil_pmc1con0	pmc1con0_addr.bit.b2		/* Filter enable bit */
#define		hden_pmc1con0	pmc1con0_addr.bit.b4		/* Header pattern enable bit */

/*----------------------------------------------------------------------------*/
/*  PMC1 Function Select Register 1                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1con1_addr	01F9h
union BYTE_DEF	pmc1con1_addr;
#define		pmc1con1		pmc1con1_addr.byte

#define		typ0_pmc1con1	pmc1con1_addr.bit.b0		/* Receive mode select bit */
#define		typ1_pmc1con1	pmc1con1_addr.bit.b1		/* Receive mode select bit */

/*----------------------------------------------------------------------------*/
/*  PMC1 Function Select Register 2                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1con2_addr	01FAh
union BYTE_DEF	pmc1con2_addr;
#define		pmc1con2		pmc1con2_addr.byte

#define		enflg_pmc1con2	pmc1con2_addr.bit.b0		/* PMC1 status flag */
#define		inflg_pmc1con2	pmc1con2_addr.bit.b3		/* Input signal flag */
#define		ceflg_pmc1con2	pmc1con2_addr.bit.b4		/* Counter overflow flag */
#define		ceint_pmc1con2	pmc1con2_addr.bit.b5		/* Counter overflow interrupt enable bit */
#define		psel0_pmc1con2	pmc1con2_addr.bit.b6		/* Input pin select bit */
#define		psel1_pmc1con2	pmc1con2_addr.bit.b7		/* Input pin select bit */

/*----------------------------------------------------------------------------*/
/*  PMC1 Function Select Register 3                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1con3_addr	01FBh
union BYTE_DEF	pmc1con3_addr;
#define		pmc1con3		pmc1con3_addr.byte

#define		cre_pmc1con3	pmc1con3_addr.bit.b0		/* Mode select bit */
#define		cfr_pmc1con3	pmc1con3_addr.bit.b1		/* Mode select bit */
#define		cst_pmc1con3	pmc1con3_addr.bit.b2		/* Mode select bit */
#define		pd_pmc1con3		pmc1con3_addr.bit.b3		/* Mode select bit */
#define		csrc0_pmc1con3	pmc1con3_addr.bit.b4		/* Clock source select bit */
#define		csrc1_pmc1con3	pmc1con3_addr.bit.b5		/* Clock source select bit */
#define		cdiv0_pmc1con3	pmc1con3_addr.bit.b6		/* Count source divisor select bit */
#define		cdiv1_pmc1con3	pmc1con3_addr.bit.b7		/* Count source divisor select bit */

/*----------------------------------------------------------------------------*/
/*  PMC1 Status Register                                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1sts_addr	01FCh
union BYTE_DEF	pmc1sts_addr;
#define		pmc1sts			pmc1sts_addr.byte

#define		reflg_pmc1sts	pmc1sts_addr.bit.b1			/* Receive error flag */
#define		drflg_pmc1sts	pmc1sts_addr.bit.b2			/* Data receiving flag */
#define		pthdflg_pmc1sts	pmc1sts_addr.bit.b4			/* Header pattern match falg */
#define		ptd0flg_pmc1sts	pmc1sts_addr.bit.b5			/* Data 0 pattern match flag */
#define		ptd1flg_pmc1sts	pmc1sts_addr.bit.b6			/* Data 1 pattern match flag */

/*----------------------------------------------------------------------------*/
/*  PMC1 Interrupt Source Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1int_addr	01FDh
union BYTE_DEF	pmc1int_addr;
#define		pmc1int			pmc1int_addr.byte

#define		reint_pmc1int	pmc1int_addr.bit.b1			/* Receive error flag interrupt enable bit */
#define		drint_pmc1int	pmc1int_addr.bit.b2			/* Data reception complete interrupt enable bit */
#define		pthdint_pmc1int	pmc1int_addr.bit.b4			/* Header match flag interrupt enable bit */
#define		ptdint_pmc1int	pmc1int_addr.bit.b5			/* Data 0/1 match flag interrupt enable bit */
#define		timint_pmc1int	pmc1int_addr.bit.b6			/* Timer measure interrupt enable bit */

/*----------------------------------------------------------------------------*/
/*  Interrupt Source Select Register 3                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ifsr3a_addr		0205h
union BYTE_DEF	ifsr3a_addr;
#define		ifsr3a			ifsr3a_addr.byte

#define		ifsr30			ifsr3a_addr.bit.b0			/* INT6~ interrupt polarity select bit */
#define		ifsr31			ifsr3a_addr.bit.b1			/* INT7~ interrupt polarity select bit */
#define		ifsr33			ifsr3a_addr.bit.b3			/* Interrupt request source select bit */
#define		ifsr34			ifsr3a_addr.bit.b4			/* Interrupt request source select bit */
#define		ifsr35			ifsr3a_addr.bit.b5			/* Interrupt request source select bit */
#define		ifsr36			ifsr3a_addr.bit.b6			/* Interrupt request source select bit */

/*----------------------------------------------------------------------------*/
/*  Interrupt Source Select Register 2                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ifsr2a_addr		0206h
union BYTE_DEF	ifsr2a_addr;
#define		ifsr2a			ifsr2a_addr.byte

#define		ifsr22			ifsr2a_addr.bit.b2			/* Interrupt request source select bit */
#define		ifsr23			ifsr2a_addr.bit.b3			/* Interrupt request source select bit */
#define		ifsr24			ifsr2a_addr.bit.b4			/* Interrupt request source select bit */
#define		ifsr25			ifsr2a_addr.bit.b5			/* Interrupt request source select bit */
#define		ifsr26			ifsr2a_addr.bit.b6			/* Interrupt request source select bit */
#define		ifsr27			ifsr2a_addr.bit.b7			/* Interrupt request source select bit */

/*----------------------------------------------------------------------------*/
/*  Interrupt Source Select Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ifsr_addr		0207h
union BYTE_DEF	ifsr_addr;
#define		ifsr			ifsr_addr.byte

#define		ifsr0			ifsr_addr.bit.b0			/* INT0~ interrupt polarity select bit */
#define		ifsr1			ifsr_addr.bit.b1			/* INT1~ interrupt polarity select bit */
#define		ifsr2			ifsr_addr.bit.b2			/* INT2~ interrupt polarity select bit */
#define		ifsr3			ifsr_addr.bit.b3			/* INT3~ interrupt polarity select bit */
#define		ifsr4			ifsr_addr.bit.b4			/* INT4~ interrupt polarity select bit */
#define		ifsr5			ifsr_addr.bit.b5			/* INT5~ interrupt polarity select bit */
#define		ifsr6			ifsr_addr.bit.b6			/* Interrupt request source select bit */
#define		ifsr7			ifsr_addr.bit.b7			/* Interrupt request source select bit */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Enable Register                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		aier_addr		020Eh
union BYTE_DEF	aier_addr;
#define		aier			aier_addr.byte

#define		aier0			aier_addr.bit.b0			/* Address match interrupt 0 enable bit */
#define		aier1			aier_addr.bit.b1			/* Address match interrupt 1 enable bit */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Enable Register 2                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		aier2_addr		020Fh
union BYTE_DEF	aier2_addr;
#define		aier2			aier2_addr.byte

#define		aier20			aier2_addr.bit.b0			/* Address match interrupt 2 enable bit */
#define		aier21			aier2_addr.bit.b1			/* Address match interrupt 3 enable bit */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Register 0                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rmad0_addr		0210h
union DWORD_DEF	rmad0_addr;
#define		rmad0			rmad0_addr.dword
#define		rmad0l			rmad0_addr.byte.low			/* Address Match Interrupt Register 0(low 8bit) */
#define		rmad0m			rmad0_addr.byte.mid			/* Address Match Interrupt Register 0(mid 8bit) */
#define		rmad0h			rmad0_addr.byte.high		/* Address Match Interrupt Register 0(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Register 1                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rmad1_addr		0214h
union DWORD_DEF	rmad1_addr;
#define		rmad1			rmad1_addr.dword
#define		rmad1l			rmad1_addr.byte.low			/* Address Match Interrupt Register 1(low 8bit) */
#define		rmad1m			rmad1_addr.byte.mid			/* Address Match Interrupt Register 1(mid 8bit) */
#define		rmad1h			rmad1_addr.byte.high		/* Address Match Interrupt Register 1(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Register 2                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rmad2_addr		0218h
union DWORD_DEF	rmad2_addr;
#define		rmad2			rmad2_addr.dword
#define		rmad2l			rmad2_addr.byte.low			/* Address Match Interrupt Register 2(low 8bit) */
#define		rmad2m			rmad2_addr.byte.mid			/* Address Match Interrupt Register 2(mid 8bit) */
#define		rmad2h			rmad2_addr.byte.high		/* Address Match Interrupt Register 2(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  Address Match Interrupt Register 3                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rmad3_addr		021Ch
union DWORD_DEF	rmad3_addr;
#define		rmad3			rmad3_addr.dword
#define		rmad3l			rmad3_addr.byte.low			/* Address Match Interrupt Register 3(low 8bit) */
#define		rmad3m			rmad3_addr.byte.mid			/* Address Match Interrupt Register 3(mid 8bit) */
#define		rmad3h			rmad3_addr.byte.high		/* Address Match Interrupt Register 3(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  Flash Memory Control Register 0                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		fmr0_addr		0220h
union BYTE_DEF	fmr0_addr;
#define		fmr0			fmr0_addr.byte

#define		fmr00			fmr0_addr.bit.b0			/* RY/BY~ status flag */
#define		fmr01			fmr0_addr.bit.b1			/* CPU rewrite mode select bit */
#define		fmr02			fmr0_addr.bit.b2			/* Lock bit disable select bit */
#define		fmstp			fmr0_addr.bit.b3			/* Flash memory stop bit */
#define		fmr06			fmr0_addr.bit.b6			/* Program status flag */
#define		fmr07			fmr0_addr.bit.b7			/* Erase Status Flag */

/*----------------------------------------------------------------------------*/
/*  Flash Memory Control Register 1                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		fmr1_addr		0221h
union BYTE_DEF	fmr1_addr;
#define		fmr1			fmr1_addr.byte

#define		fmr11			fmr1_addr.bit.b1			/* Write to FMR6 register enable bit */
#define		fmr16			fmr1_addr.bit.b6			/* Lock bit status flag */
#define		fmr17			fmr1_addr.bit.b7			/* Data flash wait bit */

/*----------------------------------------------------------------------------*/
/*  Flash Memory Control Register 2                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		fmr2_addr		0222h
union BYTE_DEF	fmr2_addr;
#define		fmr2			fmr2_addr.byte

#define		fmr22			fmr2_addr.bit.b2			/* Slow read mode enable bit */
#define		fmr23			fmr2_addr.bit.b3			/* Low-current consumption read mode enable bit */

/*----------------------------------------------------------------------------*/
/*  Flash Memory Control Register 6                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		fmr6_addr		0230h
union BYTE_DEF	fmr6_addr;
#define		fmr6			fmr6_addr.byte

#define		fmr60			fmr6_addr.bit.b0			/* EW1 mode select bit */
#define		fmr61			fmr6_addr.bit.b1			/* Reserved bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0smr4_addr		0244h
union BYTE_DEF	u0smr4_addr;
#define		u0smr4			u0smr4_addr.byte

#define		stareq_u0smr4	u0smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u0smr4	u0smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u0smr4	u0smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u0smr4	u0smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u0smr4		u0smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u0smr4		u0smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u0smr4	u0smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u0smr4		u0smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART0 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0smr3_addr		0245h
union BYTE_DEF	u0smr3_addr;
#define		u0smr3			u0smr3_addr.byte

#define		ckph_u0smr3		u0smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u0smr3		u0smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u0smr3		u0smr3_addr.bit.b5			/* SDA0 digital delay setup bit */
#define		dl1_u0smr3		u0smr3_addr.bit.b6			/* SDA0 digital delay setup bit */
#define		dl2_u0smr3		u0smr3_addr.bit.b7			/* SDA0 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0smr2_addr		0246h
union BYTE_DEF	u0smr2_addr;
#define		u0smr2			u0smr2_addr.byte

#define		iicm2_u0smr2	u0smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u0smr2		u0smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u0smr2		u0smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u0smr2		u0smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u0smr2		u0smr2_addr.bit.b4			/* UART0 initialization bit */
#define		swc2_u0smr2		u0smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u0smr2		u0smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0smr_addr		0247h
union BYTE_DEF	u0smr_addr;
#define		u0smr			u0smr_addr.byte

#define		iicm_u0smr		u0smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u0smr		u0smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u0smr		u0smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u0smr		u0smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u0smr		u0smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u0smr		u0smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0mr_addr		0248h
union BYTE_DEF	u0mr_addr;
#define		u0mr			u0mr_addr.byte

#define		smd0_u0mr		u0mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u0mr		u0mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u0mr		u0mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u0mr		u0mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u0mr		u0mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u0mr		u0mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u0mr		u0mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u0mr		u0mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0brg_addr		0249h
union BYTE_DEF	u0brg_addr;
#define		u0brg			u0brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART0 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0tb_addr		024Ah
union WORD_DEF	u0tb_addr;
#define		u0tb			u0tb_addr.word
#define		u0tbl			u0tb_addr.byte.low			/* UART0 Transmit Buffer Register(low 8bit) */
#define		u0tbh			u0tb_addr.byte.high			/* UART0 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART0 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0c0_addr		024Ch
union BYTE_DEF	u0c0_addr;
#define		u0c0			u0c0_addr.byte

#define		clk0_u0c0		u0c0_addr.bit.b0			/* U0BRG count source select bit */
#define		clk1_u0c0		u0c0_addr.bit.b1			/* U0BRG count source select bit */
#define		crs_u0c0		u0c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u0c0		u0c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u0c0		u0c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u0c0		u0c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u0c0		u0c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u0c0		u0c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0c1_addr		024Dh
union BYTE_DEF	u0c1_addr;
#define		u0c1			u0c1_addr.byte

#define		te_u0c1			u0c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u0c1			u0c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u0c1			u0c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u0c1			u0c1_addr.bit.b3			/* Receive complete flag */
#define		u0lch			u0c1_addr.bit.b6			/* Data logic select bit */
#define		u0ere			u0c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART0 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u0rb_addr		024Eh
union WORD_DEF	u0rb_addr;
#define		u0rb			u0rb_addr.word
#define		u0rbl			u0rb_addr.byte.low			/* UART0 Receive Buffer Register(low 8bit) */
#define		u0rbh			u0rb_addr.byte.high			/* UART0 Receive Buffer Register(high 8bit) */

#define		abt_u0rb		u0rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u0rb		u0rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u0rb		u0rb_addr.bit.b13			/* Framing error flag */
#define		per_u0rb		u0rb_addr.bit.b14			/* Parity error flag */
#define		sum_u0rb		u0rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  UART Transmit/Receive Control Register 2                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ucon_addr		0250h
union BYTE_DEF	ucon_addr;
#define		ucon			ucon_addr.byte

#define		u0irs			ucon_addr.bit.b0			/* UART0 transmit interrupt source select bit */
#define		u1irs			ucon_addr.bit.b1			/* UART1 transmit interrupt source select bit */
#define		u0rrm			ucon_addr.bit.b2			/* UART0 continuous receive mode enable bit */
#define		u1rrm			ucon_addr.bit.b3			/* UART1 continuous receive mode enable bit */
#define		clkmd0			ucon_addr.bit.b4			/* UART1 CLK, CLKS select bit 0 */
#define		clkmd1			ucon_addr.bit.b5			/* UART1 CLK, CLKS select bit 1 */
#define		rcsp			ucon_addr.bit.b6			/* Separate UART0 CTS~/RTS~ bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1smr4_addr		0254h
union BYTE_DEF	u1smr4_addr;
#define		u1smr4			u1smr4_addr.byte

#define		stareq_u1smr4	u1smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u1smr4	u1smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u1smr4	u1smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u1smr4	u1smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u1smr4		u1smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u1smr4		u1smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u1smr4	u1smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u1smr4		u1smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART1 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1smr3_addr		0255h
union BYTE_DEF	u1smr3_addr;
#define		u1smr3			u1smr3_addr.byte

#define		ckph_u1smr3		u1smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u1smr3		u1smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u1smr3		u1smr3_addr.bit.b5			/* SDA1 digital delay setup bit */
#define		dl1_u1smr3		u1smr3_addr.bit.b6			/* SDA1 digital delay setup bit */
#define		dl2_u1smr3		u1smr3_addr.bit.b7			/* SDA1 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1smr2_addr		0256h
union BYTE_DEF	u1smr2_addr;
#define		u1smr2			u1smr2_addr.byte

#define		iicm2_u1smr2	u1smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u1smr2		u1smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u1smr2		u1smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u1smr2		u1smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u1smr2		u1smr2_addr.bit.b4			/* UART1 initialization bit */
#define		swc2_u1smr2		u1smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u1smr2		u1smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1smr_addr		0257h
union BYTE_DEF	u1smr_addr;
#define		u1smr			u1smr_addr.byte

#define		iicm_u1smr		u1smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u1smr		u1smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u1smr		u1smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u1smr		u1smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u1smr		u1smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u1smr		u1smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1mr_addr		0258h
union BYTE_DEF	u1mr_addr;
#define		u1mr			u1mr_addr.byte

#define		smd0_u1mr		u1mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u1mr		u1mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u1mr		u1mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u1mr		u1mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u1mr		u1mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u1mr		u1mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u1mr		u1mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u1mr		u1mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1brg_addr		0259h
union BYTE_DEF	u1brg_addr;
#define		u1brg			u1brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART1 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1tb_addr		025Ah
union WORD_DEF	u1tb_addr;
#define		u1tb			u1tb_addr.word
#define		u1tbl			u1tb_addr.byte.low			/* UART1 Transmit Buffer Register(low 8bit) */
#define		u1tbh			u1tb_addr.byte.high			/* UART1 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART1 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1c0_addr		025Ch
union BYTE_DEF	u1c0_addr;
#define		u1c0			u1c0_addr.byte

#define		clk0_u1c0		u1c0_addr.bit.b0			/* U1BRG count source select bit */
#define		clk1_u1c0		u1c0_addr.bit.b1			/* U1BRG count source select bit */
#define		crs_u1c0		u1c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u1c0		u1c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u1c0		u1c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u1c0		u1c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u1c0		u1c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u1c0		u1c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1c1_addr		025Dh
union BYTE_DEF	u1c1_addr;
#define		u1c1			u1c1_addr.byte

#define		te_u1c1			u1c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u1c1			u1c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u1c1			u1c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u1c1			u1c1_addr.bit.b3			/* Receive complete flag */
#define		u1lch			u1c1_addr.bit.b6			/* Data logic select bit */
#define		u1ere			u1c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART1 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u1rb_addr		025Eh
union WORD_DEF	u1rb_addr;
#define		u1rb			u1rb_addr.word
#define		u1rbl			u1rb_addr.byte.low			/* UART1 Receive Buffer Register(low 8bit) */
#define		u1rbh			u1rb_addr.byte.high			/* UART1 Receive Buffer Register(high 8bit) */

#define		abt_u1rb		u1rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u1rb		u1rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u1rb		u1rb_addr.bit.b13			/* Framing error flag */
#define		per_u1rb		u1rb_addr.bit.b14			/* Parity error flag */
#define		sum_u1rb		u1rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  UART2 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2smr4_addr		0264h
union BYTE_DEF	u2smr4_addr;
#define		u2smr4			u2smr4_addr.byte

#define		stareq_u2smr4	u2smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u2smr4	u2smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u2smr4	u2smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u2smr4	u2smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u2smr4		u2smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u2smr4		u2smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u2smr4	u2smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u2smr4		u2smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART2 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2smr3_addr		0265h
union BYTE_DEF	u2smr3_addr;
#define		u2smr3			u2smr3_addr.byte

#define		ckph_u2smr3		u2smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u2smr3		u2smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u2smr3		u2smr3_addr.bit.b5			/* SDA2 digital delay setup bit */
#define		dl1_u2smr3		u2smr3_addr.bit.b6			/* SDA2 digital delay setup bit */
#define		dl2_u2smr3		u2smr3_addr.bit.b7			/* SDA2 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2smr2_addr		0266h
union BYTE_DEF	u2smr2_addr;
#define		u2smr2			u2smr2_addr.byte

#define		iicm2_u2smr2	u2smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u2smr2		u2smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u2smr2		u2smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u2smr2		u2smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u2smr2		u2smr2_addr.bit.b4			/* UART2 initialization bit */
#define		swc2_u2smr2		u2smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u2smr2		u2smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2smr_addr		0267h
union BYTE_DEF	u2smr_addr;
#define		u2smr			u2smr_addr.byte

#define		iicm_u2smr		u2smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u2smr		u2smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u2smr		u2smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u2smr		u2smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u2smr		u2smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u2smr		u2smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2mr_addr		0268h
union BYTE_DEF	u2mr_addr;
#define		u2mr			u2mr_addr.byte

#define		smd0_u2mr		u2mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u2mr		u2mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u2mr		u2mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u2mr		u2mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u2mr		u2mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u2mr		u2mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u2mr		u2mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u2mr		u2mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2brg_addr		0269h
union BYTE_DEF	u2brg_addr;
#define		u2brg			u2brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART2 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2tb_addr		026Ah
union WORD_DEF	u2tb_addr;
#define		u2tb			u2tb_addr.word
#define		u2tbl			u2tb_addr.byte.low			/* UART2 Transmit Buffer Register(low 8bit) */
#define		u2tbh			u2tb_addr.byte.high			/* UART2 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART2 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2c0_addr		026Ch
union BYTE_DEF	u2c0_addr;
#define		u2c0			u2c0_addr.byte

#define		clk0_u2c0		u2c0_addr.bit.b0			/* U2BRG count source select bit */
#define		clk1_u2c0		u2c0_addr.bit.b1			/* U2BRG count source select bit */
#define		crs_u2c0		u2c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u2c0		u2c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u2c0		u2c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u2c0		u2c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u2c0		u2c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u2c0		u2c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2c1_addr		026Dh
union BYTE_DEF	u2c1_addr;
#define		u2c1			u2c1_addr.byte

#define		te_u2c1			u2c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u2c1			u2c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u2c1			u2c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u2c1			u2c1_addr.bit.b3			/* Receive complete flag */
#define		u2irs			u2c1_addr.bit.b4			/* UART2 transmit interrupt source select bit */
#define		u2rrm			u2c1_addr.bit.b5			/* UART2 continuous receive mode enable bit */
#define		u2lch			u2c1_addr.bit.b6			/* Data logic select bit */
#define		u2ere			u2c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART2 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u2rb_addr		026Eh
union WORD_DEF	u2rb_addr;
#define		u2rb			u2rb_addr.word
#define		u2rbl			u2rb_addr.byte.low			/* UART2 Receive Buffer Register(low 8bit) */
#define		u2rbh			u2rb_addr.byte.high			/* UART2 Receive Buffer Register(high 8bit) */

#define		abt_u2rb		u2rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u2rb		u2rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u2rb		u2rb_addr.bit.b13			/* Framing error flag */
#define		per_u2rb		u2rb_addr.bit.b14			/* Parity error flag */
#define		sum_u2rb		u2rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  SI/O3 Transmit/Receive Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s3trr_addr		0270h
union BYTE_DEF	s3trr_addr;
#define		s3trr			s3trr_addr.byte

/*----------------------------------------------------------------------------*/
/*  SI/O3 Control Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s3c_addr		0272h
union BYTE_DEF	s3c_addr;
#define		s3c				s3c_addr.byte

#define		sm30			s3c_addr.bit.b0				/* Internal synchronous clock select bit */
#define		sm31			s3c_addr.bit.b1				/* Internal synchronous clock select bit */
#define		sm32			s3c_addr.bit.b2				/* SOUT3 output disable bit */
#define		sm33			s3c_addr.bit.b3				/* SI/O3 port select bit */
#define		sm34			s3c_addr.bit.b4				/* CLK polarity select bit */
#define		sm35			s3c_addr.bit.b5				/* Bit order select bit */
#define		sm36			s3c_addr.bit.b6				/* Synchronous clock select bit */
#define		sm37			s3c_addr.bit.b7				/* SOUT3 initial output set bit */

/*----------------------------------------------------------------------------*/
/*  SI/O3 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s3brg_addr		0273h
union BYTE_DEF	s3brg_addr;
#define		s3brg			s3brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  SI/O4 Transmit/Receive Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s4trr_addr		0274h
union BYTE_DEF	s4trr_addr;
#define		s4trr			s4trr_addr.byte

/*----------------------------------------------------------------------------*/
/*  SI/O4 Control Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s4c_addr		0276h
union BYTE_DEF	s4c_addr;
#define		s4c				s4c_addr.byte

#define		sm40			s4c_addr.bit.b0				/* Internal synchronous clock select bit */
#define		sm41			s4c_addr.bit.b1				/* Internal synchronous clock select bit */
#define		sm42			s4c_addr.bit.b2				/* SOUT4 output disable bit */
#define		sm43			s4c_addr.bit.b3				/* SI/O4 port select bit */
#define		sm44			s4c_addr.bit.b4				/* CLK polarity select bit */
#define		sm45			s4c_addr.bit.b5				/* Bit order select bit */
#define		sm46			s4c_addr.bit.b6				/* Synchronous clock select bit */
#define		sm47			s4c_addr.bit.b7				/* SOUT4 initial output set bit */

/*----------------------------------------------------------------------------*/
/*  SI/O4 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s4brg_addr		0277h
union BYTE_DEF	s4brg_addr;
#define		s4brg			s4brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  SI/O3, 4 Control Register 2                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s34c2_addr		0278h
union BYTE_DEF	s34c2_addr;
#define		s34c2			s34c2_addr.byte

#define		sm26			s34c2_addr.bit.b6			/* SOUT3 output control bit */
#define		sm27			s34c2_addr.bit.b7			/* SOUT4 output control bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5smr4_addr		0284h
union BYTE_DEF	u5smr4_addr;
#define		u5smr4			u5smr4_addr.byte

#define		stareq_u5smr4	u5smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u5smr4	u5smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u5smr4	u5smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u5smr4	u5smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u5smr4		u5smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u5smr4		u5smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u5smr4	u5smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u5smr4		u5smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART5 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5smr3_addr		0285h
union BYTE_DEF	u5smr3_addr;
#define		u5smr3			u5smr3_addr.byte

#define		ckph_u5smr3		u5smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u5smr3		u5smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u5smr3		u5smr3_addr.bit.b5			/* SDA5 digital delay setup bit */
#define		dl1_u5smr3		u5smr3_addr.bit.b6			/* SDA5 digital delay setup bit */
#define		dl2_u5smr3		u5smr3_addr.bit.b7			/* SDA5 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5smr2_addr		0286h
union BYTE_DEF	u5smr2_addr;
#define		u5smr2			u5smr2_addr.byte

#define		iicm2_u5smr2	u5smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u5smr2		u5smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u5smr2		u5smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u5smr2		u5smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u5smr2		u5smr2_addr.bit.b4			/* UART5 initialization bit */
#define		swc2_u5smr2		u5smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u5smr2		u5smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5smr_addr		0287h
union BYTE_DEF	u5smr_addr;
#define		u5smr			u5smr_addr.byte

#define		iicm_u5smr		u5smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u5smr		u5smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u5smr		u5smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u5smr		u5smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u5smr		u5smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u5smr		u5smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5mr_addr		0288h
union BYTE_DEF	u5mr_addr;
#define		u5mr			u5mr_addr.byte

#define		smd0_u5mr		u5mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u5mr		u5mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u5mr		u5mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u5mr		u5mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u5mr		u5mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u5mr		u5mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u5mr		u5mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u5mr		u5mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5brg_addr		0289h
union BYTE_DEF	u5brg_addr;
#define		u5brg			u5brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART5 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5tb_addr		028Ah
union WORD_DEF	u5tb_addr;
#define		u5tb			u5tb_addr.word
#define		u5tbl			u5tb_addr.byte.low			/* UART5 Transmit Buffer Register(low 8bit) */
#define		u5tbh			u5tb_addr.byte.high			/* UART5 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART5 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5c0_addr		028Ch
union BYTE_DEF	u5c0_addr;
#define		u5c0			u5c0_addr.byte

#define		clk0_u5c0		u5c0_addr.bit.b0			/* U5BRG count source select bit */
#define		clk1_u5c0		u5c0_addr.bit.b1			/* U5BRG count source select bit */
#define		crs_u5c0		u5c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u5c0		u5c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u5c0		u5c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u5c0		u5c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u5c0		u5c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u5c0		u5c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5c1_addr		028Dh
union BYTE_DEF	u5c1_addr;
#define		u5c1			u5c1_addr.byte

#define		te_u5c1			u5c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u5c1			u5c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u5c1			u5c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u5c1			u5c1_addr.bit.b3			/* Receive complete flag */
#define		u5irs			u5c1_addr.bit.b4			/* UART5 transmit interrupt source select bit */
#define		u5rrm			u5c1_addr.bit.b5			/* UART5 continuous receive mode enable bit */
#define		u5lch			u5c1_addr.bit.b6			/* Data logic select bit */
#define		u5ere			u5c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART5 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u5rb_addr		028Eh
union WORD_DEF	u5rb_addr;
#define		u5rb			u5rb_addr.word
#define		u5rbl			u5rb_addr.byte.low			/* UART5 Receive Buffer Register(low 8bit) */
#define		u5rbh			u5rb_addr.byte.high			/* UART5 Receive Buffer Register(high 8bit) */

#define		abt_u5rb		u5rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u5rb		u5rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u5rb		u5rb_addr.bit.b13			/* Framing error flag */
#define		per_u5rb		u5rb_addr.bit.b14			/* Parity error flag */
#define		sum_u5rb		u5rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  UART6 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6smr4_addr		0294h
union BYTE_DEF	u6smr4_addr;
#define		u6smr4			u6smr4_addr.byte

#define		stareq_u6smr4	u6smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u6smr4	u6smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u6smr4	u6smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u6smr4	u6smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u6smr4		u6smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u6smr4		u6smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u6smr4	u6smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u6smr4		u6smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART6 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6smr3_addr		0295h
union BYTE_DEF	u6smr3_addr;
#define		u6smr3			u6smr3_addr.byte

#define		ckph_u6smr3		u6smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u6smr3		u6smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u6smr3		u6smr3_addr.bit.b5			/* SDA6 digital delay setup bit */
#define		dl1_u6smr3		u6smr3_addr.bit.b6			/* SDA6 digital delay setup bit */
#define		dl2_u6smr3		u6smr3_addr.bit.b7			/* SDA6 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6smr2_addr		0296h
union BYTE_DEF	u6smr2_addr;
#define		u6smr2			u6smr2_addr.byte

#define		iicm2_u6smr2	u6smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u6smr2		u6smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u6smr2		u6smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u6smr2		u6smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u6smr2		u6smr2_addr.bit.b4			/* UART6 initialization bit */
#define		swc2_u6smr2		u6smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u6smr2		u6smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6smr_addr		0297h
union BYTE_DEF	u6smr_addr;
#define		u6smr			u6smr_addr.byte

#define		iicm_u6smr		u6smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u6smr		u6smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u6smr		u6smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u6smr		u6smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u6smr		u6smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u6smr		u6smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6mr_addr		0298h
union BYTE_DEF	u6mr_addr;
#define		u6mr			u6mr_addr.byte

#define		smd0_u6mr		u6mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u6mr		u6mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u6mr		u6mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u6mr		u6mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u6mr		u6mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u6mr		u6mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u6mr		u6mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u6mr		u6mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6brg_addr		0299h
union BYTE_DEF	u6brg_addr;
#define		u6brg			u6brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART6 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6tb_addr		029Ah
union WORD_DEF	u6tb_addr;
#define		u6tb			u6tb_addr.word
#define		u6tbl			u6tb_addr.byte.low			/* UART6 Transmit Buffer Register(low 8bit) */
#define		u6tbh			u6tb_addr.byte.high			/* UART6 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART6 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6c0_addr		029Ch
union BYTE_DEF	u6c0_addr;
#define		u6c0			u6c0_addr.byte

#define		clk0_u6c0		u6c0_addr.bit.b0			/* U6BRG count source select bit */
#define		clk1_u6c0		u6c0_addr.bit.b1			/* U6BRG count source select bit */
#define		crs_u6c0		u6c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u6c0		u6c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u6c0		u6c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u6c0		u6c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u6c0		u6c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u6c0		u6c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6c1_addr		029Dh
union BYTE_DEF	u6c1_addr;
#define		u6c1			u6c1_addr.byte

#define		te_u6c1			u6c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u6c1			u6c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u6c1			u6c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u6c1			u6c1_addr.bit.b3			/* Receive complete flag */
#define		u6irs			u6c1_addr.bit.b4			/* UART6 transmit interrupt source select bit */
#define		u6rrm			u6c1_addr.bit.b5			/* UART6 continuous receive mode enable bit */
#define		u6lch			u6c1_addr.bit.b6			/* Data logic select bit */
#define		u6ere			u6c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART6 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u6rb_addr		029Eh
union WORD_DEF	u6rb_addr;
#define		u6rb			u6rb_addr.word
#define		u6rbl			u6rb_addr.byte.low			/* UART6 Receive Buffer Register(low 8bit) */
#define		u6rbh			u6rb_addr.byte.high			/* UART6 Receive Buffer Register(high 8bit) */

#define		abt_u6rb		u6rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u6rb		u6rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u6rb		u6rb_addr.bit.b13			/* Framing error flag */
#define		per_u6rb		u6rb_addr.bit.b14			/* Parity error flag */
#define		sum_u6rb		u6rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  UART7 Special Mode Register 4                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7smr4_addr		02A4h
union BYTE_DEF	u7smr4_addr;
#define		u7smr4			u7smr4_addr.byte

#define		stareq_u7smr4	u7smr4_addr.bit.b0			/* Start condition generate bit */
#define		rstareq_u7smr4	u7smr4_addr.bit.b1			/* Restart condition generate bit */
#define		stpreq_u7smr4	u7smr4_addr.bit.b2			/* Stop condition generate bit */
#define		stspsel_u7smr4	u7smr4_addr.bit.b3			/* SCL, SDA output select bit */
#define		ackd_u7smr4		u7smr4_addr.bit.b4			/* ACK data bit */
#define		ackc_u7smr4		u7smr4_addr.bit.b5			/* ACK data output enable bit */
#define		sclhi_u7smr4	u7smr4_addr.bit.b6			/* SCL output stop enable bit */
#define		swc9_u7smr4		u7smr4_addr.bit.b7			/* SCL wait bit 3 */

/*----------------------------------------------------------------------------*/
/*  UART7 Special Mode Register 3                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7smr3_addr		02A5h
union BYTE_DEF	u7smr3_addr;
#define		u7smr3			u7smr3_addr.byte

#define		ckph_u7smr3		u7smr3_addr.bit.b1			/* Clock phase set bit */
#define		nodc_u7smr3		u7smr3_addr.bit.b3			/* Clock output select bit */
#define		dl0_u7smr3		u7smr3_addr.bit.b5			/* SDA7 digital delay setup bit */
#define		dl1_u7smr3		u7smr3_addr.bit.b6			/* SDA7 digital delay setup bit */
#define		dl2_u7smr3		u7smr3_addr.bit.b7			/* SDA7 digital delay setup bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Special Mode Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7smr2_addr		02A6h
union BYTE_DEF	u7smr2_addr;
#define		u7smr2			u7smr2_addr.byte

#define		iicm2_u7smr2	u7smr2_addr.bit.b0			/* I2C mode select bit 2 */
#define		csc_u7smr2		u7smr2_addr.bit.b1			/* Clock synchronization bit */
#define		swc_u7smr2		u7smr2_addr.bit.b2			/* SCL wait output bit */
#define		als_u7smr2		u7smr2_addr.bit.b3			/* SDA output stop bit */
#define		stac_u7smr2		u7smr2_addr.bit.b4			/* UART7 initialization bit */
#define		swc2_u7smr2		u7smr2_addr.bit.b5			/* SCL wait output bit 2 */
#define		sdhi_u7smr2		u7smr2_addr.bit.b6			/* SDA output disable bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Special Mode Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7smr_addr		02A7h
union BYTE_DEF	u7smr_addr;
#define		u7smr			u7smr_addr.byte

#define		iicm_u7smr		u7smr_addr.bit.b0			/* I2C mode select bit */
#define		abc_u7smr		u7smr_addr.bit.b1			/* Arbitration lost detect flag control bit */
#define		bbs_u7smr		u7smr_addr.bit.b2			/* Bus busy flag */
#define		abscs_u7smr		u7smr_addr.bit.b4			/* Bus collision detect sampling clock select bit */
#define		acse_u7smr		u7smr_addr.bit.b5			/* Auto clear function select bit of transmit enable bit */
#define		sss_u7smr		u7smr_addr.bit.b6			/* Transmit start condition select bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Transmit/Receive Mode Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7mr_addr		02A8h
union BYTE_DEF	u7mr_addr;
#define		u7mr			u7mr_addr.byte

#define		smd0_u7mr		u7mr_addr.bit.b0			/* Serial I/O mode select bit */
#define		smd1_u7mr		u7mr_addr.bit.b1			/* Serial I/O mode select bit */
#define		smd2_u7mr		u7mr_addr.bit.b2			/* Serial I/O mode select bit */
#define		ckdir_u7mr		u7mr_addr.bit.b3			/* Internal/external clock select bit */
#define		stps_u7mr		u7mr_addr.bit.b4			/* Stop bit length select bit */
#define		pry_u7mr		u7mr_addr.bit.b5			/* Odd/even parity select bit */
#define		prye_u7mr		u7mr_addr.bit.b6			/* Parity enable bit */
#define		iopol_u7mr		u7mr_addr.bit.b7			/* TXD, RXD I/O polarity reverse bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Bit Rate Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7brg_addr		02A9h
union BYTE_DEF	u7brg_addr;
#define		u7brg			u7brg_addr.byte

/*----------------------------------------------------------------------------*/
/*  UART7 Transmit Buffer Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7tb_addr		02AAh
union WORD_DEF	u7tb_addr;
#define		u7tb			u7tb_addr.word
#define		u7tbl			u7tb_addr.byte.low			/* UART7 Transmit Buffer Register(low 8bit) */
#define		u7tbh			u7tb_addr.byte.high			/* UART7 Transmit Buffer Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  UART7 Transmit/Receive Control Register 0                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7c0_addr		02ACh
union BYTE_DEF	u7c0_addr;
#define		u7c0			u7c0_addr.byte

#define		clk0_u7c0		u7c0_addr.bit.b0			/* U7BRG count source select bit */
#define		clk1_u7c0		u7c0_addr.bit.b1			/* U7BRG count source select bit */
#define		crs_u7c0		u7c0_addr.bit.b2			/* CTS~/RTS~ function select bit */
#define		txept_u7c0		u7c0_addr.bit.b3			/* Transmit register empty flag */
#define		crd_u7c0		u7c0_addr.bit.b4			/* CTS~/RTS~ disable bit */
#define		nch_u7c0		u7c0_addr.bit.b5			/* Data output select bit */
#define		ckpol_u7c0		u7c0_addr.bit.b6			/* CLK polarity select bit */
#define		uform_u7c0		u7c0_addr.bit.b7			/* Bit order select bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Transmit/Receive Control Register 1                                 */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7c1_addr		02ADh
union BYTE_DEF	u7c1_addr;
#define		u7c1			u7c1_addr.byte

#define		te_u7c1			u7c1_addr.bit.b0			/* Transmit enable bit */
#define		ti_u7c1			u7c1_addr.bit.b1			/* Transmit buffer empty flag */
#define		re_u7c1			u7c1_addr.bit.b2			/* Receive enable bit */
#define		ri_u7c1			u7c1_addr.bit.b3			/* Receive complete flag */
#define		u7irs			u7c1_addr.bit.b4			/* UART7 transmit interrupt source select bit */
#define		u7rrm			u7c1_addr.bit.b5			/* UART7 continuous receive mode enable bit */
#define		u7lch			u7c1_addr.bit.b6			/* Data logic select bit */
#define		u7ere			u7c1_addr.bit.b7			/* Error signal output enable bit */

/*----------------------------------------------------------------------------*/
/*  UART7 Receive Buffer Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		u7rb_addr		02AEh
union WORD_DEF	u7rb_addr;
#define		u7rb			u7rb_addr.word
#define		u7rbl			u7rb_addr.byte.low			/* UART7 Receive Buffer Register(low 8bit) */
#define		u7rbh			u7rb_addr.byte.high			/* UART7 Receive Buffer Register(high 8bit) */

#define		abt_u7rb		u7rb_addr.bit.b11			/* Arbitration lost detect flag */
#define		oer_u7rb		u7rb_addr.bit.b12			/* Overrun error flag */
#define		fer_u7rb		u7rb_addr.bit.b13			/* Framing error flag */
#define		per_u7rb		u7rb_addr.bit.b14			/* Parity error flag */
#define		sum_u7rb		u7rb_addr.bit.b15			/* Error sum flag */

/*----------------------------------------------------------------------------*/
/*  I2C0 Data Shift Register                                                  */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s00_addr		02B0h
union BYTE_DEF	s00_addr;
#define		s00				s00_addr.byte

/*----------------------------------------------------------------------------*/
/*  I2C0 Address Register 0                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s0d0_addr		02B2h
union BYTE_DEF	s0d0_addr;
#define		s0d0			s0d0_addr.byte

#define		sad0_s0d0		s0d0_addr.bit.b1			/* Slave Address */
#define		sad1_s0d0		s0d0_addr.bit.b2			/* Slave Address */
#define		sad2_s0d0		s0d0_addr.bit.b3			/* Slave Address */
#define		sad3_s0d0		s0d0_addr.bit.b4			/* Slave Address */
#define		sad4_s0d0		s0d0_addr.bit.b5			/* Slave Address */
#define		sad5_s0d0		s0d0_addr.bit.b6			/* Slave Address */
#define		sad6_s0d0		s0d0_addr.bit.b7			/* Slave Address */

/*----------------------------------------------------------------------------*/
/*  I2C0 Control Register 0                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s1d0_addr		02B3h
union BYTE_DEF	s1d0_addr;
#define		s1d0			s1d0_addr.byte

#define		bc0				s1d0_addr.bit.b0			/* Bit counter(number of transmitted/received bits) */
#define		bc1				s1d0_addr.bit.b1			/* Bit counter(number of transmitted/received bits) */
#define		bc2				s1d0_addr.bit.b2			/* Bit counter(number of transmitted/received bits) */
#define		es0				s1d0_addr.bit.b3			/* I2C-bus interface enable bit */
#define		als				s1d0_addr.bit.b4			/* Data format select bit */
#define		ihr				s1d0_addr.bit.b6			/* I2C-bus interface reset bit */
#define		tiss			s1d0_addr.bit.b7			/* I2C-bus interface pin input level select bit */

/*----------------------------------------------------------------------------*/
/*  I2C0 Clock Control Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s20_addr		02B4h
union BYTE_DEF	s20_addr;
#define		s20				s20_addr.byte

#define		ccr0			s20_addr.bit.b0				/* Bit rate control bit */
#define		ccr1			s20_addr.bit.b1				/* Bit rate control bit */
#define		ccr2			s20_addr.bit.b2				/* Bit rate control bit */
#define		ccr3			s20_addr.bit.b3				/* Bit rate control bit */
#define		ccr4			s20_addr.bit.b4				/* Bit rate control bit */
#define		fastmode		s20_addr.bit.b5				/* SCL mode select bit */
#define		ackbit			s20_addr.bit.b6				/* ACK bit */
#define		ackclk			s20_addr.bit.b7				/* ACK clock bit */

/*----------------------------------------------------------------------------*/
/*  I2C0 Start/Stop Condition Control Register                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s2d0_addr		02B5h
union BYTE_DEF	s2d0_addr;
#define		s2d0			s2d0_addr.byte

#define		ssc0			s2d0_addr.bit.b0			/* Start/stop condition setting bit */
#define		ssc1			s2d0_addr.bit.b1			/* Start/stop condition setting bit */
#define		ssc2			s2d0_addr.bit.b2			/* Start/stop condition setting bit */
#define		ssc3			s2d0_addr.bit.b3			/* Start/stop condition setting bit */
#define		ssc4			s2d0_addr.bit.b4			/* Start/stop condition setting bit */
#define		sip				s2d0_addr.bit.b5			/* SCL/SDA interrupt pin polarity select bit */
#define		sis				s2d0_addr.bit.b6			/* SCL/SDA interrupt pin select bit */
#define		stspsel			s2d0_addr.bit.b7			/* Start/stop condition generation select bit */

/*----------------------------------------------------------------------------*/
/*  I2C0 Control Register 1                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s3d0_addr		02B6h
union BYTE_DEF	s3d0_addr;
#define		s3d0			s3d0_addr.byte

#define		sim				s3d0_addr.bit.b0			/* Stop condition detect interrupt enable bit */
#define		wit				s3d0_addr.bit.b1			/* Data receive interrupt enable bit */
#define		ped				s3d0_addr.bit.b2			/* SDAMM/port function select bit */
#define		pec				s3d0_addr.bit.b3			/* SCLMM/port function select bit */
#define		sdam			s3d0_addr.bit.b4			/* Internal SDA output monitor bit */
#define		sclm			s3d0_addr.bit.b5			/* Internal SCL output monitor bit */
#define		ick0			s3d0_addr.bit.b6			/* I2C-bus system clock select bit */
#define		ick1			s3d0_addr.bit.b7			/* I2C-bus system clock select bit */

/*----------------------------------------------------------------------------*/
/*  I2C0 Control Register 2                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s4d0_addr		02B7h
union BYTE_DEF	s4d0_addr;
#define		s4d0			s4d0_addr.byte

#define		toe				s4d0_addr.bit.b0			/* Timeout detect function enable bit */
#define		tof				s4d0_addr.bit.b1			/* Timeout detect flag */
#define		tosel			s4d0_addr.bit.b2			/* Timeout detect time select bit */
#define		ick2			s4d0_addr.bit.b3			/* I2C-bus system clock select bit */
#define		ick3			s4d0_addr.bit.b4			/* I2C-bus system clock select bit */
#define		ick4			s4d0_addr.bit.b5			/* I2C-bus system clock select bit */
#define		mslad			s4d0_addr.bit.b6			/* Slave address compare bit */
#define		scpin			s4d0_addr.bit.b7			/* Stop condition detect interrupt request bit */

/*----------------------------------------------------------------------------*/
/*  I2C0 Status Register 0                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s10_addr		02B8h
union BYTE_DEF	s10_addr;
#define		s10				s10_addr.byte

#define		lrb				s10_addr.bit.b0				/* Last receive bit */
#define		adr0			s10_addr.bit.b1				/* General call detection flag */
#define		aas				s10_addr.bit.b2				/* Slave address compare flag */
#define		al				s10_addr.bit.b3				/* Arbitration lost detection flag */
#define		pin				s10_addr.bit.b4				/* I2C-bus interface interrupt request bit */
#define		bb				s10_addr.bit.b5				/* Bus busy flag */
#define		trx				s10_addr.bit.b6				/* Communication mode select bit 0 */
#define		mst				s10_addr.bit.b7				/* Communication mode select bit 1 */

/*----------------------------------------------------------------------------*/
/*  I2C0 Status Register 1                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s11_addr		02B9h
union BYTE_DEF	s11_addr;
#define		s11				s11_addr.byte

#define		aas0			s11_addr.bit.b0				/* Slave address 0 compare flag */
#define		aas1			s11_addr.bit.b1				/* Slave address 1 compare flag */
#define		aas2			s11_addr.bit.b2				/* Slave address 2 compare flag */

/*----------------------------------------------------------------------------*/
/*  I2C0 Address Register 1                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s0d1_addr		02BAh
union BYTE_DEF	s0d1_addr;
#define		s0d1			s0d1_addr.byte

#define		sad0_s0d1		s0d1_addr.bit.b1			/* Slave Address */
#define		sad1_s0d1		s0d1_addr.bit.b2			/* Slave Address */
#define		sad2_s0d1		s0d1_addr.bit.b3			/* Slave Address */
#define		sad3_s0d1		s0d1_addr.bit.b4			/* Slave Address */
#define		sad4_s0d1		s0d1_addr.bit.b5			/* Slave Address */
#define		sad5_s0d1		s0d1_addr.bit.b6			/* Slave Address */
#define		sad6_s0d1		s0d1_addr.bit.b7			/* Slave Address */

/*----------------------------------------------------------------------------*/
/*  I2C0 Address Register 2                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		s0d2_addr		02BBh
union BYTE_DEF	s0d2_addr;
#define		s0d2			s0d2_addr.byte

#define		sad0_s0d2		s0d2_addr.bit.b1			/* Slave Address */
#define		sad1_s0d2		s0d2_addr.bit.b2			/* Slave Address */
#define		sad2_s0d2		s0d2_addr.bit.b3			/* Slave Address */
#define		sad3_s0d2		s0d2_addr.bit.b4			/* Slave Address */
#define		sad4_s0d2		s0d2_addr.bit.b5			/* Slave Address */
#define		sad5_s0d2		s0d2_addr.bit.b6			/* Slave Address */
#define		sad6_s0d2		s0d2_addr.bit.b7			/* Slave Address */

/*----------------------------------------------------------------------------*/
/*  Timer B3/B4/B5 Count Start Flag                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tbsr_addr		0300h
union BYTE_DEF	tbsr_addr;
#define		tbsr			tbsr_addr.byte

#define		tb3s			tbsr_addr.bit.b5			/* Timer B3 count start flag */
#define		tb4s			tbsr_addr.bit.b6			/* Timer B4 count start flag */
#define		tb5s			tbsr_addr.bit.b7			/* Timer B5 count start flag */

/*----------------------------------------------------------------------------*/
/*  Timer A1-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta11_addr		0302h
union WORD_DEF	ta11_addr;
#define		ta11			ta11_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A2-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta21_addr		0304h
union WORD_DEF	ta21_addr;
#define		ta21			ta21_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A4-1 Register                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta41_addr		0306h
union WORD_DEF	ta41_addr;
#define		ta41			ta41_addr.word

/*----------------------------------------------------------------------------*/
/*  Three-Phase PWM Control Register 0                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		invc0_addr		0308h
union BYTE_DEF	invc0_addr;
#define		invc0			invc0_addr.byte

#define		inv00			invc0_addr.bit.b0			/* ICTB2 count condition select bit */
#define		inv01			invc0_addr.bit.b1			/* ICTB2 count condition select bit */
#define		inv02			invc0_addr.bit.b2			/* Three-phase motor control timer function enable bit */
#define		inv03			invc0_addr.bit.b3			/* Three-phase motor control timer output control bit */
#define		inv04			invc0_addr.bit.b4			/* High- and low-side simultaneous turn-on disable bit */
#define		inv05			invc0_addr.bit.b5			/* High- and low-side simultaneous turn-on detect flag */
#define		inv06			invc0_addr.bit.b6			/* Modulation mode select bit */
#define		inv07			invc0_addr.bit.b7			/* Software trigger select bit */

/*----------------------------------------------------------------------------*/
/*  Three-Phase PWM Control Register 1                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		invc1_addr		0309h
union BYTE_DEF	invc1_addr;
#define		invc1			invc1_addr.byte

#define		inv10			invc1_addr.bit.b0			/* Timer A1, A2, and A4 start trigger select bit */
#define		inv11			invc1_addr.bit.b1			/* Timer A1-1, A2-1 and A4-1 control bit */
#define		inv12			invc1_addr.bit.b2			/* Dead time timer count source select bit */
#define		inv13			invc1_addr.bit.b3			/* Carrier wave rise/fall detect flag */
#define		inv14			invc1_addr.bit.b4			/* Active level control bit */
#define		inv15			invc1_addr.bit.b5			/* Dead time disable bit */
#define		inv16			invc1_addr.bit.b6			/* Dead time timer trigger select bit */

/*----------------------------------------------------------------------------*/
/*  Three-Phase Output Buffer Register 0                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		idb0_addr		030Ah
union BYTE_DEF	idb0_addr;
#define		idb0			idb0_addr.byte

#define		du0				idb0_addr.bit.b0			/* U-phase output buffer 0 */
#define		dub0			idb0_addr.bit.b1			/* U~-phase output buffer 0 */
#define		dv0				idb0_addr.bit.b2			/* V-phase output buffer 0 */
#define		dvb0			idb0_addr.bit.b3			/* V~-phase output buffer 0 */
#define		dw0				idb0_addr.bit.b4			/* W-phase output buffer 0 */
#define		dwb0			idb0_addr.bit.b5			/* W~-phase output buffer 0 */

/*----------------------------------------------------------------------------*/
/*  Three-Phase Output Buffer Register 1                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		idb1_addr		030Bh
union BYTE_DEF	idb1_addr;
#define		idb1			idb1_addr.byte

#define		du1				idb1_addr.bit.b0			/* U-phase output buffer 1 */
#define		dub1			idb1_addr.bit.b1			/* U~-phase output buffer 1 */
#define		dv1				idb1_addr.bit.b2			/* V-phase output buffer 1 */
#define		dvb1			idb1_addr.bit.b3			/* V~-phase output buffer 1 */
#define		dw1				idb1_addr.bit.b4			/* W-phase output buffer 1 */
#define		dwb1			idb1_addr.bit.b5			/* W~-phase output buffer 1 */

/*----------------------------------------------------------------------------*/
/*  Dead Time Timer                                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dtt_addr		030Ch
union BYTE_DEF	dtt_addr;
#define		dtt				dtt_addr.byte

/*----------------------------------------------------------------------------*/
/*  Timer B2 Interrupt Generation Frequency Set Counter                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ictb2_addr		030Dh
union BYTE_DEF	ictb2_addr;
#define		ictb2			ictb2_addr.byte

/*----------------------------------------------------------------------------*/
/*  Position-Data-Retain Function Control Register                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pdrf_addr		030Eh
union BYTE_DEF	pdrf_addr;
#define		pdrf			pdrf_addr.byte

#define		pdrw			pdrf_addr.bit.b0			/* W-phase position data retain bit */
#define		pdrv			pdrf_addr.bit.b1			/* V-phase position data retain bit */
#define		pdru			pdrf_addr.bit.b2			/* U-phase position data retain bit */
#define		pdrt			pdrf_addr.bit.b3			/* Retain-trigger polarity select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B3 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb3_addr		0310h
union WORD_DEF	tb3_addr;
#define		tb3				tb3_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B4 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb4_addr		0312h
union WORD_DEF	tb4_addr;
#define		tb4				tb4_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B5 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb5_addr		0314h
union WORD_DEF	tb5_addr;
#define		tb5				tb5_addr.word

/*----------------------------------------------------------------------------*/
/*  Port Function Control Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pfcr_addr		0318h
union BYTE_DEF	pfcr_addr;
#define		pfcr			pfcr_addr.byte

#define		pfc0			pfcr_addr.bit.b0			/* Port P8_0 output function select bit */
#define		pfc1			pfcr_addr.bit.b1			/* Port P8_1 output function select bit */
#define		pfc2			pfcr_addr.bit.b2			/* Port P7_2 output function select bit */
#define		pfc3			pfcr_addr.bit.b3			/* Port P7_3 output function select bit */
#define		pfc4			pfcr_addr.bit.b4			/* Port P7_4 output function select bit */
#define		pfc5			pfcr_addr.bit.b5			/* Port P7_5 output function select bit */

/*----------------------------------------------------------------------------*/
/*  Timer B3 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb3mr_addr		031Bh
union BYTE_DEF	tb3mr_addr;
#define		tb3mr			tb3mr_addr.byte

#define		tmod0_tb3mr		tb3mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb3mr		tb3mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb3mr		tb3mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb3mr		tb3mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb3mr		tb3mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb3mr		tb3mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb3mr		tb3mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B4 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb4mr_addr		031Ch
union BYTE_DEF	tb4mr_addr;
#define		tb4mr			tb4mr_addr.byte

#define		tmod0_tb4mr		tb4mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb4mr		tb4mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb4mr		tb4mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb4mr		tb4mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb4mr		tb4mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb4mr		tb4mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb4mr		tb4mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B5 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb5mr_addr		031Dh
union BYTE_DEF	tb5mr_addr;
#define		tb5mr			tb5mr_addr.byte

#define		tmod0_tb5mr		tb5mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb5mr		tb5mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb5mr		tb5mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb5mr		tb5mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb5mr		tb5mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb5mr		tb5mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb5mr		tb5mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Count Start Flag                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tabsr_addr		0320h
union BYTE_DEF	tabsr_addr;
#define		tabsr			tabsr_addr.byte

#define		ta0s			tabsr_addr.bit.b0			/* Timer A0 count start flag */
#define		ta1s			tabsr_addr.bit.b1			/* Timer A1 count start flag */
#define		ta2s			tabsr_addr.bit.b2			/* Timer A2 count start flag */
#define		ta3s			tabsr_addr.bit.b3			/* Timer A3 count start flag */
#define		ta4s			tabsr_addr.bit.b4			/* Timer A4 count start flag */
#define		tb0s			tabsr_addr.bit.b5			/* Timer B0 count start flag */
#define		tb1s			tabsr_addr.bit.b6			/* Timer B1 count start flag */
#define		tb2s			tabsr_addr.bit.b7			/* Timer B2 count start flag */

/*----------------------------------------------------------------------------*/
/*  One-Shot Start Flag                                                       */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		onsf_addr		0322h
union BYTE_DEF	onsf_addr;
#define		onsf			onsf_addr.byte

#define		ta0os			onsf_addr.bit.b0			/* Timer A0 one-shot start flag */
#define		ta1os			onsf_addr.bit.b1			/* Timer A1 one-shot start flag */
#define		ta2os			onsf_addr.bit.b2			/* Timer A2 one-shot start flag */
#define		ta3os			onsf_addr.bit.b3			/* Timer A3 one-shot start flag */
#define		ta4os			onsf_addr.bit.b4			/* Timer A4 one-shot start flag */
#define		tazie			onsf_addr.bit.b5			/* Z-phase input enable bit */
#define		ta0tgl			onsf_addr.bit.b6			/* Timer A0 event/trigger select bit */
#define		ta0tgh			onsf_addr.bit.b7			/* Timer A0 event/trigger select bit */

/*----------------------------------------------------------------------------*/
/*  Trigger Select Register                                                   */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		trgsr_addr		0323h
union BYTE_DEF	trgsr_addr;
#define		trgsr			trgsr_addr.byte

#define		ta1tgl			trgsr_addr.bit.b0			/* Timer A1 event/trigger select bit */
#define		ta1tgh			trgsr_addr.bit.b1			/* Timer A1 event/trigger select bit */
#define		ta2tgl			trgsr_addr.bit.b2			/* Timer A2 event/trigger select bit */
#define		ta2tgh			trgsr_addr.bit.b3			/* Timer A2 event/trigger select bit */
#define		ta3tgl			trgsr_addr.bit.b4			/* Timer A3 event/trigger select bit */
#define		ta3tgh			trgsr_addr.bit.b5			/* Timer A3 event/trigger select bit */
#define		ta4tgl			trgsr_addr.bit.b6			/* Timer A4 event/trigger select bit */
#define		ta4tgh			trgsr_addr.bit.b7			/* Timer A4 event/trigger select bit */

/*----------------------------------------------------------------------------*/
/*  Up/Down Flag                                                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		udf_addr		0324h
union BYTE_DEF	udf_addr;
#define		udf				udf_addr.byte

#define		ta0ud			udf_addr.bit.b0				/* Timer A0 up/down flag */
#define		ta1ud			udf_addr.bit.b1				/* Timer A1 up/down flag */
#define		ta2ud			udf_addr.bit.b2				/* Timer A2 up/down flag */
#define		ta3ud			udf_addr.bit.b3				/* Timer A3 up/down flag */
#define		ta4ud			udf_addr.bit.b4				/* Timer A4 up/down flag */
#define		ta2p			udf_addr.bit.b5				/* Timer A2 two-phase pulse signal processing select bit */
#define		ta3p			udf_addr.bit.b6				/* Timer A3 two-phase pulse signal processing select bit */
#define		ta4p			udf_addr.bit.b7				/* Timer A4 two-phase pulse signal processing select bit */

/*----------------------------------------------------------------------------*/
/*  Timer A0 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta0_addr		0326h
union WORD_DEF	ta0_addr;
#define		ta0				ta0_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A1 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta1_addr		0328h
union WORD_DEF	ta1_addr;
#define		ta1				ta1_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A2 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta2_addr		032Ah
union WORD_DEF	ta2_addr;
#define		ta2				ta2_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A3 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta3_addr		032Ch
union WORD_DEF	ta3_addr;
#define		ta3				ta3_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A4 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta4_addr		032Eh
union WORD_DEF	ta4_addr;
#define		ta4				ta4_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B0 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb0_addr		0330h
union WORD_DEF	tb0_addr;
#define		tb0				tb0_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B1 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb1_addr		0332h
union WORD_DEF	tb1_addr;
#define		tb1				tb1_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer B2 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb2_addr		0334h
union WORD_DEF	tb2_addr;
#define		tb2				tb2_addr.word

/*----------------------------------------------------------------------------*/
/*  Timer A0 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta0mr_addr		0336h
union BYTE_DEF	ta0mr_addr;
#define		ta0mr			ta0mr_addr.byte

#define		tmod0_ta0mr		ta0mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_ta0mr		ta0mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_ta0mr		ta0mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_ta0mr		ta0mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr2_ta0mr		ta0mr_addr.bit.b4			/* Function varies with the operation mode */
#define		mr3_ta0mr		ta0mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_ta0mr		ta0mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_ta0mr		ta0mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer A1 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta1mr_addr		0337h
union BYTE_DEF	ta1mr_addr;
#define		ta1mr			ta1mr_addr.byte

#define		tmod0_ta1mr		ta1mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_ta1mr		ta1mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_ta1mr		ta1mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_ta1mr		ta1mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr2_ta1mr		ta1mr_addr.bit.b4			/* Function varies with the operation mode */
#define		mr3_ta1mr		ta1mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_ta1mr		ta1mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_ta1mr		ta1mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer A2 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta2mr_addr		0338h
union BYTE_DEF	ta2mr_addr;
#define		ta2mr			ta2mr_addr.byte

#define		tmod0_ta2mr		ta2mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_ta2mr		ta2mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_ta2mr		ta2mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_ta2mr		ta2mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr2_ta2mr		ta2mr_addr.bit.b4			/* Function varies with the operation mode */
#define		mr3_ta2mr		ta2mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_ta2mr		ta2mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_ta2mr		ta2mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer A3 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta3mr_addr		0339h
union BYTE_DEF	ta3mr_addr;
#define		ta3mr			ta3mr_addr.byte

#define		tmod0_ta3mr		ta3mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_ta3mr		ta3mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_ta3mr		ta3mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_ta3mr		ta3mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr2_ta3mr		ta3mr_addr.bit.b4			/* Function varies with the operation mode */
#define		mr3_ta3mr		ta3mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_ta3mr		ta3mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_ta3mr		ta3mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer A4 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ta4mr_addr		033Ah
union BYTE_DEF	ta4mr_addr;
#define		ta4mr			ta4mr_addr.byte

#define		tmod0_ta4mr		ta4mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_ta4mr		ta4mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_ta4mr		ta4mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_ta4mr		ta4mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr2_ta4mr		ta4mr_addr.bit.b4			/* Function varies with the operation mode */
#define		mr3_ta4mr		ta4mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_ta4mr		ta4mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_ta4mr		ta4mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B0 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb0mr_addr		033Bh
union BYTE_DEF	tb0mr_addr;
#define		tb0mr			tb0mr_addr.byte

#define		tmod0_tb0mr		tb0mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb0mr		tb0mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb0mr		tb0mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb0mr		tb0mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb0mr		tb0mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb0mr		tb0mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb0mr		tb0mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B1 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb1mr_addr		033Ch
union BYTE_DEF	tb1mr_addr;
#define		tb1mr			tb1mr_addr.byte

#define		tmod0_tb1mr		tb1mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb1mr		tb1mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb1mr		tb1mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb1mr		tb1mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb1mr		tb1mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb1mr		tb1mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb1mr		tb1mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B2 Mode Register                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb2mr_addr		033Dh
union BYTE_DEF	tb2mr_addr;
#define		tb2mr			tb2mr_addr.byte

#define		tmod0_tb2mr		tb2mr_addr.bit.b0			/* Operation mode select bit */
#define		tmod1_tb2mr		tb2mr_addr.bit.b1			/* Operation mode select bit */
#define		mr0_tb2mr		tb2mr_addr.bit.b2			/* Function varies with the operation mode */
#define		mr1_tb2mr		tb2mr_addr.bit.b3			/* Function varies with the operation mode */
#define		mr3_tb2mr		tb2mr_addr.bit.b5			/* Function varies with the operation mode */
#define		tck0_tb2mr		tb2mr_addr.bit.b6			/* Count source select bit(Function varies with the operation mode) */
#define		tck1_tb2mr		tb2mr_addr.bit.b7			/* Count source select bit(Function varies with the operation mode) */

/*----------------------------------------------------------------------------*/
/*  Timer B2 Special Mode Register                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		tb2sc_addr		033Eh
union BYTE_DEF	tb2sc_addr;
#define		tb2sc			tb2sc_addr.byte

#define		pwcon			tb2sc_addr.bit.b0			/* Timer B2 reload timing switch bit */
#define		ivpcr1			tb2sc_addr.bit.b1			/* Three-phase output port SD~ control bit 1 */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Second Data Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtcsec_addr		0340h
union BYTE_DEF	rtcsec_addr;
#define		rtcsec			rtcsec_addr.byte

#define		sc00			rtcsec_addr.bit.b0			/* 1st digit of second count bit */
#define		sc01			rtcsec_addr.bit.b1			/* 1st digit of second count bit */
#define		sc02			rtcsec_addr.bit.b2			/* 1st digit of second count bit */
#define		sc03			rtcsec_addr.bit.b3			/* 1st digit of second count bit */
#define		sc10			rtcsec_addr.bit.b4			/* 2nd digit of second count bit */
#define		sc11			rtcsec_addr.bit.b5			/* 2nd digit of second count bit */
#define		sc12			rtcsec_addr.bit.b6			/* 2nd digit of second count bit */
#define		bsy				rtcsec_addr.bit.b7			/* Real-time clock busy flag */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Minute Data Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtcmin_addr		0341h
union BYTE_DEF	rtcmin_addr;
#define		rtcmin			rtcmin_addr.byte

#define		mn00			rtcmin_addr.bit.b0			/* 1st digit of minute count bit */
#define		mn01			rtcmin_addr.bit.b1			/* 1st digit of minute count bit */
#define		mn02			rtcmin_addr.bit.b2			/* 1st digit of minute count bit */
#define		mn03			rtcmin_addr.bit.b3			/* 1st digit of minute count bit */
#define		mn10			rtcmin_addr.bit.b4			/* 2nd digit of minute count bit */
#define		mn11			rtcmin_addr.bit.b5			/* 2nd digit of minute count bit */
#define		mn12			rtcmin_addr.bit.b6			/* 2nd digit of minute count bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Hour Data Register                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtchr_addr		0342h
union BYTE_DEF	rtchr_addr;
#define		rtchr			rtchr_addr.byte

#define		hr00			rtchr_addr.bit.b0			/* 1st digit of hour count bit */
#define		hr01			rtchr_addr.bit.b1			/* 1st digit of hour count bit */
#define		hr02			rtchr_addr.bit.b2			/* 1st digit of hour count bit */
#define		hr03			rtchr_addr.bit.b3			/* 1st digit of hour count bit */
#define		hr10			rtchr_addr.bit.b4			/* 2nd digit of hour count bit */
#define		hr11			rtchr_addr.bit.b5			/* 2nd digit of hour count bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Day Data Register                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtcwk_addr		0343h
union BYTE_DEF	rtcwk_addr;
#define		rtcwk			rtcwk_addr.byte

#define		wk0				rtcwk_addr.bit.b0			/* Day count bit */
#define		wk1				rtcwk_addr.bit.b1			/* Day count bit */
#define		wk2				rtcwk_addr.bit.b2			/* Day count bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Control Register 1                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccr1_addr		0344h
union BYTE_DEF	rtccr1_addr;
#define		rtccr1			rtccr1_addr.byte

#define		tcstf			rtccr1_addr.bit.b1			/* Real-time clock count status flag */
#define		toena			rtccr1_addr.bit.b2			/* RTCOUT pin output bit */
#define		rtcrst			rtccr1_addr.bit.b4			/* Real-time clock reset bit */
#define		rtcpm			rtccr1_addr.bit.b5			/* A.m./p.m. bit */
#define		h12h24			rtccr1_addr.bit.b6			/* Operating mode select bit */
#define		tstart			rtccr1_addr.bit.b7			/* Real-time clock count start bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Control Register 2                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccr2_addr		0345h
union BYTE_DEF	rtccr2_addr;
#define		rtccr2			rtccr2_addr.byte

#define		seie			rtccr2_addr.bit.b0			/* Periodic interrupt triggered every second enable bit */
#define		mnie			rtccr2_addr.bit.b1			/* Periodic interrupt triggered every minute enable bit */
#define		hrie			rtccr2_addr.bit.b2			/* Periodic interrupt triggered every hour enable bit */
#define		dyie			rtccr2_addr.bit.b3			/* Periodic interrupt triggered every day enable bit */
#define		wkie			rtccr2_addr.bit.b4			/* Periodic interrupt triggered every week enable bit */
#define		rtccmp0			rtccr2_addr.bit.b5			/* Compare mode select bit */
#define		rtccmp1			rtccr2_addr.bit.b6			/* Compare mode select bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Count source Select Register                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccsr_addr		0346h
union BYTE_DEF	rtccsr_addr;
#define		rtccsr			rtccsr_addr.byte

#define		rcs0			rtccsr_addr.bit.b0			/* Count source select bit */
#define		rcs1			rtccsr_addr.bit.b1			/* Count source select bit */
#define		rcs2			rtccsr_addr.bit.b2			/* Count source frequency select bit */
#define		rcs3			rtccsr_addr.bit.b3			/* Count source frequency select bit */
#define		rcs4			rtccsr_addr.bit.b4			/* Count source frequency select bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Second Compare data register                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccsec_addr	0348h
union BYTE_DEF	rtccsec_addr;
#define		rtccsec			rtccsec_addr.byte

#define		scmp00			rtccsec_addr.bit.b0			/* 1st digit of second compare data bit */
#define		scmp01			rtccsec_addr.bit.b1			/* 1st digit of second compare data bit */
#define		scmp02			rtccsec_addr.bit.b2			/* 1st digit of second compare data bit */
#define		scmp03			rtccsec_addr.bit.b3			/* 1st digit of second compare data bit */
#define		scmp10			rtccsec_addr.bit.b4			/* 2nd digit of second compare data bit */
#define		scmp11			rtccsec_addr.bit.b5			/* 2nd digit of second compare data bit */
#define		scmp12			rtccsec_addr.bit.b6			/* 2nd digit of second compare data bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Minute Compare data register                              */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtccmin_addr	0349h
union BYTE_DEF	rtccmin_addr;
#define		rtccmin			rtccmin_addr.byte

#define		mcmp00			rtccmin_addr.bit.b0			/* 1st digit of minute compare data bit */
#define		mcmp01			rtccmin_addr.bit.b1			/* 1st digit of minute compare data bit */
#define		mcmp02			rtccmin_addr.bit.b2			/* 1st digit of minute compare data bit */
#define		mcmp03			rtccmin_addr.bit.b3			/* 1st digit of minute compare data bit */
#define		mcmp10			rtccmin_addr.bit.b4			/* 2nd digit of minute compare data bit */
#define		mcmp11			rtccmin_addr.bit.b5			/* 2nd digit of minute compare data bit */
#define		mcmp12			rtccmin_addr.bit.b6			/* 2nd digit of minute compare data bit */

/*----------------------------------------------------------------------------*/
/*  Real-Time Clock Hour Compare data register                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		rtcchr_addr		034Ah
union BYTE_DEF	rtcchr_addr;
#define		rtcchr			rtcchr_addr.byte

#define		hcmp00			rtcchr_addr.bit.b0			/* 1st digit of hour compare data bit */
#define		hcmp01			rtcchr_addr.bit.b1			/* 1st digit of hour compare data bit */
#define		hcmp02			rtcchr_addr.bit.b2			/* 1st digit of hour compare data bit */
#define		hcmp03			rtcchr_addr.bit.b3			/* 1st digit of hour compare data bit */
#define		hcmp10			rtcchr_addr.bit.b4			/* 2nd digit of hour compare data bit */
#define		hcmp11			rtcchr_addr.bit.b5			/* 2nd digit of hour compare data bit */
#define		pmcmp			rtcchr_addr.bit.b6			/* A.m./p.m. compare bit */

/*----------------------------------------------------------------------------*/
/*  CEC Function Control Register 1                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cecc1_addr		0350h
union BYTE_DEF	cecc1_addr;
#define		cecc1			cecc1_addr.byte

#define		cecen			cecc1_addr.bit.b0			/* CEC enable bit */
#define		cclk0			cecc1_addr.bit.b1			/* Clock source select bit */
#define		cclk1			cecc1_addr.bit.b2			/* Clock source select bit */

/*----------------------------------------------------------------------------*/
/*  CEC Function Control Register 2                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cecc2_addr		0351h
union BYTE_DEF	cecc2_addr;
#define		cecc2			cecc2_addr.byte

#define		crrng			cecc2_addr.bit.b0			/* Receive edge detection select bit */
#define		ctnack			cecc2_addr.bit.b1			/* Transmit NACK(ACK) end select bit */
#define		ctacken			cecc2_addr.bit.b2			/* Transmit NACK(ACK) end control bit */
#define		crack			cecc2_addr.bit.b3			/* ACK output control bit */
#define		ctabts			cecc2_addr.bit.b4			/* Arbitration lost detect condition select bit */
#define		cfil			cecc2_addr.bit.b5			/* Digital filter enable bit */
#define		cstrrng			cecc2_addr.bit.b6			/* Start bit acceptable range select bit */
#define		cdatrng			cecc2_addr.bit.b7			/* Data bit acceptable range select bit */

/*----------------------------------------------------------------------------*/
/*  CEC Function Control Register 3                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cecc3_addr		0352h
union BYTE_DEF	cecc3_addr;
#define		cecc3			cecc3_addr.byte

#define		ctxden			cecc3_addr.bit.b0			/* Transmit enable bit */
#define		crxden			cecc3_addr.bit.b1			/* Receive enable bit */
#define		cregclr			cecc3_addr.bit.b2			/* Receive edge detect flag clear bit */
#define		ceomi			cecc3_addr.bit.b3			/* EOM disable bit */

/*----------------------------------------------------------------------------*/
/*  CEC Function Control Register 4                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cecc4_addr		0353h
union BYTE_DEF	cecc4_addr;
#define		cecc4			cecc4_addr.byte

#define		crise0			cecc4_addr.bit.b0			/* Rising timing select bit */
#define		crise1			cecc4_addr.bit.b1			/* Rising timing select bit */
#define		crise2			cecc4_addr.bit.b2			/* Rising timing select bit */
#define		cabten			cecc4_addr.bit.b3			/* Error low pulse output enabled bit */
#define		cfall0			cecc4_addr.bit.b4			/* Falling timing select bit */
#define		cfall1			cecc4_addr.bit.b5			/* Falling timing select bit */
#define		cregflg			cecc4_addr.bit.b6			/* Receive edge detect flag */
#define		cabtwen			cecc4_addr.bit.b7			/* Error low pulse output wait control bit */

/*----------------------------------------------------------------------------*/
/*  CEC Flag Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cecflg_addr		0354h
union BYTE_DEF	cecflg_addr;
#define		cecflg			cecflg_addr.byte

#define		crflg			cecflg_addr.bit.b0			/* Receive status flag */
#define		ctflg			cecflg_addr.bit.b1			/* Transmit status flag */
#define		crerrflg		cecflg_addr.bit.b2			/* Receive error detect flag */
#define		ctabtflg		cecflg_addr.bit.b3			/* Arbitration lost detect flag */
#define		ctnackflg		cecflg_addr.bit.b4			/* Transmit NACK detect flag */
#define		crd8flg			cecflg_addr.bit.b5			/* 8th bit of data receive flag */
#define		ctd8flg			cecflg_addr.bit.b6			/* 8th bit of data transmit flag */
#define		crstflg			cecflg_addr.bit.b7			/* Start bit detection */

/*----------------------------------------------------------------------------*/
/*  CEC Interrupt Source Select Register                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cisel_addr		0355h
union BYTE_DEF	cisel_addr;
#define		cisel			cisel_addr.byte

#define		crisel0			cisel_addr.bit.b0			/* 8th bit receive interrupt enable bit */
#define		crisel1			cisel_addr.bit.b1			/* 10th bit receive interrupt enable bit */
#define		crisel2			cisel_addr.bit.b2			/* Receive error interrupt enable bit */
#define		criselm			cisel_addr.bit.b3			/* Receive interrupt mode select bit */
#define		ctisel0			cisel_addr.bit.b4			/* 8th bit transmit interrupt enable bit */
#define		ctisel1			cisel_addr.bit.b5			/* 10th bit transmit interrupt enable bit */
#define		ctisel2			cisel_addr.bit.b6			/* Transmit error interrupt enable bit */
#define		crisels			cisel_addr.bit.b7			/* Reception start bit interrupt enable bit */

/*----------------------------------------------------------------------------*/
/*  CEC Transmit Buffer Register 1                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cctb1_addr		0356h
union BYTE_DEF	cctb1_addr;
#define		cctb1			cctb1_addr.byte

/*----------------------------------------------------------------------------*/
/*  CEC Transmit Buffer Register 2                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cctb2_addr		0357h
union BYTE_DEF	cctb2_addr;
#define		cctb2			cctb2_addr.byte

#define		cctbe			cctb2_addr.bit.b0			/* Transmit data EOM bit */
#define		cctba			cctb2_addr.bit.b1			/* Transmit data ACK input bit */

/*----------------------------------------------------------------------------*/
/*  CEC Receive Buffer Register 1                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ccrb1_addr		0358h
union BYTE_DEF	ccrb1_addr;
#define		ccrb1			ccrb1_addr.byte

/*----------------------------------------------------------------------------*/
/*  CEC Receive Buffer Register 2                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ccrb2_addr		0359h
union BYTE_DEF	ccrb2_addr;
#define		ccrb2			ccrb2_addr.byte

#define		ccrbe			ccrb2_addr.bit.b0			/* Receive data EOM bit */
#define		ccrbao			ccrb2_addr.bit.b1			/* Receive data ACK output bit */
#define		ccrbai			ccrb2_addr.bit.b2			/* Receive data ACK input bit */

/*----------------------------------------------------------------------------*/
/*  CEC Receive Follower Address Set Register 1                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cradri1_addr	035Ah
union BYTE_DEF	cradri1_addr;
#define		cradri1			cradri1_addr.byte

#define		cradri10		cradri1_addr.bit.b0			/* 0000b select bit */
#define		cradri11		cradri1_addr.bit.b1			/* 0001b select bit */
#define		cradri12		cradri1_addr.bit.b2			/* 0010b select bit */
#define		cradri13		cradri1_addr.bit.b3			/* 0011b select bit */
#define		cradri14		cradri1_addr.bit.b4			/* 0100b select bit */
#define		cradri15		cradri1_addr.bit.b5			/* 0101b select bit */
#define		cradri16		cradri1_addr.bit.b6			/* 0110b select bit */
#define		cradri17		cradri1_addr.bit.b7			/* 0111b select bit */

/*----------------------------------------------------------------------------*/
/*  CEC Receive Follower Address Set Register 2                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cradri2_addr	035Bh
union BYTE_DEF	cradri2_addr;
#define		cradri2			cradri2_addr.byte

#define		cradri20		cradri2_addr.bit.b0			/* 1000b select bit */
#define		cradri21		cradri2_addr.bit.b1			/* 1001b select bit */
#define		cradri22		cradri2_addr.bit.b2			/* 1010b select bit */
#define		cradri23		cradri2_addr.bit.b3			/* 1011b select bit */
#define		cradri24		cradri2_addr.bit.b4			/* 1100b select bit */
#define		cradri25		cradri2_addr.bit.b5			/* 1101b select bit */
#define		cradri26		cradri2_addr.bit.b6			/* 1110b select bit */
#define		cradri27		cradri2_addr.bit.b7			/* 1111b select bit */

/*----------------------------------------------------------------------------*/
/*  Pull-Up Control Register 0                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pur0_addr		0360h
union BYTE_DEF	pur0_addr;
#define		pur0			pur0_addr.byte

#define		pu00			pur0_addr.bit.b0			/* P0_0 to P0_3 pull-up */
#define		pu01			pur0_addr.bit.b1			/* P0_4 to P0_7 pull-up */
#define		pu02			pur0_addr.bit.b2			/* P1_0 to P1_3 pull-up */
#define		pu03			pur0_addr.bit.b3			/* P1_4 to P1_7 pull-up */
#define		pu04			pur0_addr.bit.b4			/* P2_0 to P2_3 pull-up */
#define		pu05			pur0_addr.bit.b5			/* P2_4 to P2_7 pull-up */
#define		pu06			pur0_addr.bit.b6			/* P3_0 to P3_3 pull-up */
#define		pu07			pur0_addr.bit.b7			/* P3_4 to P3_7 pull-up */

/*----------------------------------------------------------------------------*/
/*  Pull-Up Control Register 1                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pur1_addr		0361h
union BYTE_DEF	pur1_addr;
#define		pur1			pur1_addr.byte

#define		pu10			pur1_addr.bit.b0			/* P4_0 to P4_3 pull-up */
#define		pu11			pur1_addr.bit.b1			/* P4_4 to P4_7 pull-up */
#define		pu12			pur1_addr.bit.b2			/* P5_0 to P5_3 pull-up */
#define		pu13			pur1_addr.bit.b3			/* P5_4 to P5_7 pull-up */
#define		pu14			pur1_addr.bit.b4			/* P6_0 to P6_3 pull-up */
#define		pu15			pur1_addr.bit.b5			/* P6_4 to P6_7 pull-up */
#define		pu16			pur1_addr.bit.b6			/* P7_2 to P7_3 pull-up */
#define		pu17			pur1_addr.bit.b7			/* P7_4 to P7_7 pull-up */

/*----------------------------------------------------------------------------*/
/*  Pull-Up Control Register 2                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pur2_addr		0362h
union BYTE_DEF	pur2_addr;
#define		pur2			pur2_addr.byte

#define		pu20			pur2_addr.bit.b0			/* P8_0 to P8_3 pull-up */
#define		pu21			pur2_addr.bit.b1			/* P8_4 to P8_7 pull-up */
#define		pu22			pur2_addr.bit.b2			/* P9_0 to P9_3 pull-up */
#define		pu23			pur2_addr.bit.b3			/* P9_4 to P9_7 pull-up */
#define		pu24			pur2_addr.bit.b4			/* P10_0 to P10_3 pull-up */
#define		pu25			pur2_addr.bit.b5			/* P10_4 to P10_7 pull-up */

/*----------------------------------------------------------------------------*/
/*  Port Control Register                                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pcr_addr		0366h
union BYTE_DEF	pcr_addr;
#define		pcr				pcr_addr.byte

#define		pcr0			pcr_addr.bit.b0				/* Port P1 control bit */
#define		pcr4			pcr_addr.bit.b4				/* CEC output enable bit */
#define		pcr5			pcr_addr.bit.b5				/* INT6~ input enable bit */
#define		pcr6			pcr_addr.bit.b6				/* INT7~ input enable bit */
#define		pcr7			pcr_addr.bit.b7				/* Key input enable bit */

/*----------------------------------------------------------------------------*/
/*  NMI~/SD~ Digital Filter Register                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		nmidf_addr		0369h
union BYTE_DEF	nmidf_addr;
#define		nmidf			nmidf_addr.byte

#define		nmidf0			nmidf_addr.bit.b0			/* NMI~/SD~ filter sampling clock select bit */
#define		nmidf1			nmidf_addr.bit.b1			/* NMI~/SD~ filter sampling clock select bit */
#define		nmidf2			nmidf_addr.bit.b2			/* NMI~/SD~ filter sampling clock select bit */

/*----------------------------------------------------------------------------*/
/*  PWM Control Register 0                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmcon0_addr	0370h
union BYTE_DEF	pwmcon0_addr;
#define		pwmcon0			pwmcon0_addr.byte

#define		pwmsel0			pwmcon0_addr.bit.b0			/* PWM0 output pin select bit */
#define		pwmsel1			pwmcon0_addr.bit.b1			/* PWM1 output pin select bit */
#define		pwmclk0			pwmcon0_addr.bit.b6			/* PWM count source select bit */
#define		pwmclk1			pwmcon0_addr.bit.b7			/* PWM count source select bit */

/*----------------------------------------------------------------------------*/
/*  PWM0 prescaler                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmpre0_addr	0372h
union BYTE_DEF	pwmpre0_addr;
#define		pwmpre0			pwmpre0_addr.byte

/*----------------------------------------------------------------------------*/
/*  PWM0 register                                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmreg0_addr	0373h
union BYTE_DEF	pwmreg0_addr;
#define		pwmreg0			pwmreg0_addr.byte

/*----------------------------------------------------------------------------*/
/*  PWM1 prescaler                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmpre1_addr	0374h
union BYTE_DEF	pwmpre1_addr;
#define		pwmpre1			pwmpre1_addr.byte

/*----------------------------------------------------------------------------*/
/*  PWM1 register                                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmreg1_addr	0375h
union BYTE_DEF	pwmreg1_addr;
#define		pwmreg1			pwmreg1_addr.byte

/*----------------------------------------------------------------------------*/
/*  PWM Control Register 1                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pwmcon1_addr	0376h
union BYTE_DEF	pwmcon1_addr;
#define		pwmcon1			pwmcon1_addr.byte

#define		pwmen0			pwmcon1_addr.bit.b0			/* PWM0 output enable bit */
#define		pwmen1			pwmcon1_addr.bit.b1			/* PWM1 output enable bit */
#define		pwmport0		pwmcon1_addr.bit.b2			/* PWM0 port switch bit */
#define		pwmport1		pwmcon1_addr.bit.b3			/* PWM1 port switch bit */

/*----------------------------------------------------------------------------*/
/*  Count Source Protection Mode Register                                     */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		cspr_addr		037Ch
union BYTE_DEF	cspr_addr;
#define		cspr			cspr_addr.byte

#define		cspro			cspr_addr.bit.b7			/* Count source protection mode select bit */

/*----------------------------------------------------------------------------*/
/*  Watchdog Timer Reset Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		wdtr_addr		037Dh
union BYTE_DEF	wdtr_addr;
#define		wdtr			wdtr_addr.byte

/*----------------------------------------------------------------------------*/
/*  Watchdog Timer Start Register                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		wdts_addr		037Eh
union BYTE_DEF	wdts_addr;
#define		wdts			wdts_addr.byte

/*----------------------------------------------------------------------------*/
/*  Watchdog Timer Control Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		wdc_addr		037Fh
union BYTE_DEF	wdc_addr;
#define		wdc				wdc_addr.byte

#define		wdc0			wdc_addr.bit.b0				/* Higher-order bits (b14 to b10) of the watchdog timer can be read */
#define		wdc1			wdc_addr.bit.b1				/* Higher-order bits (b14 to b10) of the watchdog timer can be read */
#define		wdc2			wdc_addr.bit.b2				/* Higher-order bits (b14 to b10) of the watchdog timer can be read */
#define		wdc3			wdc_addr.bit.b3				/* Higher-order bits (b14 to b10) of the watchdog timer can be read */
#define		wdc4			wdc_addr.bit.b4				/* Higher-order bits (b14 to b10) of the watchdog timer can be read */
#define		wdc7			wdc_addr.bit.b7				/* Prescaler select bit */

/*----------------------------------------------------------------------------*/
/*  DMA2 Source Select Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm2sl_addr		0390h
union BYTE_DEF	dm2sl_addr;
#define		dm2sl			dm2sl_addr.byte

#define		dsel0_dm2sl		dm2sl_addr.bit.b0			/* DMA request source select bit */
#define		dsel1_dm2sl		dm2sl_addr.bit.b1			/* DMA request source select bit */
#define		dsel2_dm2sl		dm2sl_addr.bit.b2			/* DMA request source select bit */
#define		dsel3_dm2sl		dm2sl_addr.bit.b3			/* DMA request source select bit */
#define		dsel4_dm2sl		dm2sl_addr.bit.b4			/* DMA request source select bit */
#define		dms_dm2sl		dm2sl_addr.bit.b6			/* DMA request source expansion select bit */
#define		dsr_dm2sl		dm2sl_addr.bit.b7			/* Software DMA request bit */

/*----------------------------------------------------------------------------*/
/*  DMA3 Source Select Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm3sl_addr		0392h
union BYTE_DEF	dm3sl_addr;
#define		dm3sl			dm3sl_addr.byte

#define		dsel0_dm3sl		dm3sl_addr.bit.b0			/* DMA request source select bit */
#define		dsel1_dm3sl		dm3sl_addr.bit.b1			/* DMA request source select bit */
#define		dsel2_dm3sl		dm3sl_addr.bit.b2			/* DMA request source select bit */
#define		dsel3_dm3sl		dm3sl_addr.bit.b3			/* DMA request source select bit */
#define		dsel4_dm3sl		dm3sl_addr.bit.b4			/* DMA request source select bit */
#define		dms_dm3sl		dm3sl_addr.bit.b6			/* DMA request source expansion select bit */
#define		dsr_dm3sl		dm3sl_addr.bit.b7			/* Software DMA request bit */

/*----------------------------------------------------------------------------*/
/*  DMA0 Source Select Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm0sl_addr		0398h
union BYTE_DEF	dm0sl_addr;
#define		dm0sl			dm0sl_addr.byte

#define		dsel0_dm0sl		dm0sl_addr.bit.b0			/* DMA request source select bit */
#define		dsel1_dm0sl		dm0sl_addr.bit.b1			/* DMA request source select bit */
#define		dsel2_dm0sl		dm0sl_addr.bit.b2			/* DMA request source select bit */
#define		dsel3_dm0sl		dm0sl_addr.bit.b3			/* DMA request source select bit */
#define		dsel4_dm0sl		dm0sl_addr.bit.b4			/* DMA request source select bit */
#define		dms_dm0sl		dm0sl_addr.bit.b6			/* DMA request source expansion select bit */
#define		dsr_dm0sl		dm0sl_addr.bit.b7			/* Software DMA request bit */

/*----------------------------------------------------------------------------*/
/*  DMA1 Source Select Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dm1sl_addr		039Ah
union BYTE_DEF	dm1sl_addr;
#define		dm1sl			dm1sl_addr.byte

#define		dsel0_dm1sl		dm1sl_addr.bit.b0			/* DMA request source select bit */
#define		dsel1_dm1sl		dm1sl_addr.bit.b1			/* DMA request source select bit */
#define		dsel2_dm1sl		dm1sl_addr.bit.b2			/* DMA request source select bit */
#define		dsel3_dm1sl		dm1sl_addr.bit.b3			/* DMA request source select bit */
#define		dsel4_dm1sl		dm1sl_addr.bit.b4			/* DMA request source select bit */
#define		dms_dm1sl		dm1sl_addr.bit.b6			/* DMA request source expansion select bit */
#define		dsr_dm1sl		dm1sl_addr.bit.b7			/* Software DMA request bit */

/*----------------------------------------------------------------------------*/
/*  Open-Circuit Detection Assist Function Register                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ainrst_addr		03A2h
union BYTE_DEF	ainrst_addr;
#define		ainrst			ainrst_addr.byte

#define		ainrst0			ainrst_addr.bit.b4			/* Open-circuit detection assist function enable bit */
#define		ainrst1			ainrst_addr.bit.b5			/* Open-circuit detection assist function enable bit */

/*----------------------------------------------------------------------------*/
/*  SFR Snoop Address Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		crcsar_addr		03B4h
union WORD_DEF	crcsar_addr;
#define		crcsar			crcsar_addr.word
#define		crcsarl			crcsar_addr.byte.low		/* SFR Snoop Address Register(low 8bit) */
#define		crcsarh			crcsar_addr.byte.high		/* SFR Snoop Address Register(high 8bit) */

#define		crcsar0			crcsar_addr.bit.b0			/* SFR snoop address bit */
#define		crcsar1			crcsar_addr.bit.b1			/* SFR snoop address bit */
#define		crcsar2			crcsar_addr.bit.b2			/* SFR snoop address bit */
#define		crcsar3			crcsar_addr.bit.b3			/* SFR snoop address bit */
#define		crcsar4			crcsar_addr.bit.b4			/* SFR snoop address bit */
#define		crcsar5			crcsar_addr.bit.b5			/* SFR snoop address bit */
#define		crcsar6			crcsar_addr.bit.b6			/* SFR snoop address bit */
#define		crcsar7			crcsar_addr.bit.b7			/* SFR snoop address bit */
#define		crcsar8			crcsar_addr.bit.b8			/* SFR snoop address bit */
#define		crcsar9			crcsar_addr.bit.b9			/* SFR snoop address bit */
#define		crcsr			crcsar_addr.bit.b14			/* Snoop-on-read enable bit */
#define		crcsw			crcsar_addr.bit.b15			/* Snoop-on-write enable bit */

/*----------------------------------------------------------------------------*/
/*  CRC Mode Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		crcmr_addr		03B6h
union BYTE_DEF	crcmr_addr;
#define		crcmr			crcmr_addr.byte

#define		crcps			crcmr_addr.bit.b0			/* CRC polynomial select bit */
#define		crcms			crcmr_addr.bit.b7			/* CRC mode select bit */

/*----------------------------------------------------------------------------*/
/*  CRC Data Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		crcd_addr		03BCh
union WORD_DEF	crcd_addr;
#define		crcd			crcd_addr.word
#define		crcdl			crcd_addr.byte.low			/* CRC Data Register(low 8bit) */
#define		crcdh			crcd_addr.byte.high			/* CRC Data Register(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  CRC Input Register                                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		crcin_addr		03BEh
union BYTE_DEF	crcin_addr;
#define		crcin			crcin_addr.byte

/*----------------------------------------------------------------------------*/
/*  A/D Register 0                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad0_addr		03C0h
union WORD_DEF	ad0_addr;
#define		ad0				ad0_addr.word
#define		ad0l			ad0_addr.byte.low			/* A/D Register 0(low 8bit) */
#define		ad0h			ad0_addr.byte.high			/* A/D Register 0(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 1                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad1_addr		03C2h
union WORD_DEF	ad1_addr;
#define		ad1				ad1_addr.word
#define		ad1l			ad1_addr.byte.low			/* A/D Register 1(low 8bit) */
#define		ad1h			ad1_addr.byte.high			/* A/D Register 1(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 2                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad2_addr		03C4h
union WORD_DEF	ad2_addr;
#define		ad2				ad2_addr.word
#define		ad2l			ad2_addr.byte.low			/* A/D Register 2(low 8bit) */
#define		ad2h			ad2_addr.byte.high			/* A/D Register 2(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 3                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad3_addr		03C6h
union WORD_DEF	ad3_addr;
#define		ad3				ad3_addr.word
#define		ad3l			ad3_addr.byte.low			/* A/D Register 3(low 8bit) */
#define		ad3h			ad3_addr.byte.high			/* A/D Register 3(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 4                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad4_addr		03C8h
union WORD_DEF	ad4_addr;
#define		ad4				ad4_addr.word
#define		ad4l			ad4_addr.byte.low			/* A/D Register 4(low 8bit) */
#define		ad4h			ad4_addr.byte.high			/* A/D Register 4(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 5                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad5_addr		03CAh
union WORD_DEF	ad5_addr;
#define		ad5				ad5_addr.word
#define		ad5l			ad5_addr.byte.low			/* A/D Register 5(low 8bit) */
#define		ad5h			ad5_addr.byte.high			/* A/D Register 5(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 6                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad6_addr		03CCh
union WORD_DEF	ad6_addr;
#define		ad6				ad6_addr.word
#define		ad6l			ad6_addr.byte.low			/* A/D Register 6(low 8bit) */
#define		ad6h			ad6_addr.byte.high			/* A/D Register 6(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Register 7                                                            */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		ad7_addr		03CEh
union WORD_DEF	ad7_addr;
#define		ad7				ad7_addr.word
#define		ad7l			ad7_addr.byte.low			/* A/D Register 7(low 8bit) */
#define		ad7h			ad7_addr.byte.high			/* A/D Register 7(high 8bit) */

/*----------------------------------------------------------------------------*/
/*  A/D Control Register 2                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		adcon2_addr		03D4h
union BYTE_DEF	adcon2_addr;
#define		adcon2			adcon2_addr.byte

#define		adgsel0			adcon2_addr.bit.b1			/* A/D input group select bit */
#define		adgsel1			adcon2_addr.bit.b2			/* A/D input group select bit */
#define		cks2			adcon2_addr.bit.b4			/* Frequency select bit 2 */

/*----------------------------------------------------------------------------*/
/*  A/D Control Register 0                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		adcon0_addr		03D6h
union BYTE_DEF	adcon0_addr;
#define		adcon0			adcon0_addr.byte

#define		ch0				adcon0_addr.bit.b0			/* Analog input pin select bit */
#define		ch1				adcon0_addr.bit.b1			/* Analog input pin select bit */
#define		ch2				adcon0_addr.bit.b2			/* Analog input pin select bit */
#define		md0				adcon0_addr.bit.b3			/* A/D operation mode select bit 0 */
#define		md1				adcon0_addr.bit.b4			/* A/D operation mode select bit 0 */
#define		trg				adcon0_addr.bit.b5			/* Trigger select bit */
#define		adst			adcon0_addr.bit.b6			/* A/D conversion start flag */
#define		cks0			adcon0_addr.bit.b7			/* Frequency select bit 0 */

/*----------------------------------------------------------------------------*/
/*  A/D Control Register 1                                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		adcon1_addr		03D7h
union BYTE_DEF	adcon1_addr;
#define		adcon1			adcon1_addr.byte

#define		scan0			adcon1_addr.bit.b0			/* A/D sweep pin select */
#define		scan1			adcon1_addr.bit.b1			/* A/D sweep pin select */
#define		md2				adcon1_addr.bit.b2			/* A/D operation mode select bit 1 */
#define		cks1			adcon1_addr.bit.b4			/* Frequency select bit 1 */
#define		adstby			adcon1_addr.bit.b5			/* A/D standby bit */
#define		adex0			adcon1_addr.bit.b6			/* Extended pin select bit */
#define		adex1			adcon1_addr.bit.b7			/* Extended pin select bit */

/*----------------------------------------------------------------------------*/
/*  D/A0 Register                                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		da0_addr		03D8h
union BYTE_DEF	da0_addr;
#define		da0				da0_addr.byte

/*----------------------------------------------------------------------------*/
/*  D/A1 Register                                                             */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		da1_addr		03DAh
union BYTE_DEF	da1_addr;
#define		da1				da1_addr.byte

/*----------------------------------------------------------------------------*/
/*  D/A Control Register                                                      */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		dacon_addr		03DCh
union BYTE_DEF	dacon_addr;
#define		dacon			dacon_addr.byte

#define		da0e			dacon_addr.bit.b0			/* D/A 0 output enable bit */
#define		da1e			dacon_addr.bit.b1			/* D/A 1 output enable bit */

/*----------------------------------------------------------------------------*/
/*  Port P0 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p0_addr			03E0h
union BYTE_DEF	p0_addr;
#define		p0				p0_addr.byte

#define		p0_0			p0_addr.bit.b0				/* Port P0_0 bit */
#define		p0_1			p0_addr.bit.b1				/* Port P0_1 bit */
#define		p0_2			p0_addr.bit.b2				/* Port P0_2 bit */
#define		p0_3			p0_addr.bit.b3				/* Port P0_3 bit */
#define		p0_4			p0_addr.bit.b4				/* Port P0_4 bit */
#define		p0_5			p0_addr.bit.b5				/* Port P0_5 bit */
#define		p0_6			p0_addr.bit.b6				/* Port P0_6 bit */
#define		p0_7			p0_addr.bit.b7				/* Port P0_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P1 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p1_addr			03E1h
union BYTE_DEF	p1_addr;
#define		p1				p1_addr.byte

#define		p1_0			p1_addr.bit.b0				/* Port P1_0 bit */
#define		p1_1			p1_addr.bit.b1				/* Port P1_1 bit */
#define		p1_2			p1_addr.bit.b2				/* Port P1_2 bit */
#define		p1_3			p1_addr.bit.b3				/* Port P1_3 bit */
#define		p1_4			p1_addr.bit.b4				/* Port P1_4 bit */
#define		p1_5			p1_addr.bit.b5				/* Port P1_5 bit */
#define		p1_6			p1_addr.bit.b6				/* Port P1_6 bit */
#define		p1_7			p1_addr.bit.b7				/* Port P1_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P0 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd0_addr		03E2h
union BYTE_DEF	pd0_addr;
#define		pd0				pd0_addr.byte

#define		pd0_0			pd0_addr.bit.b0				/* Port P0_0 direction bit */
#define		pd0_1			pd0_addr.bit.b1				/* Port P0_1 direction bit */
#define		pd0_2			pd0_addr.bit.b2				/* Port P0_2 direction bit */
#define		pd0_3			pd0_addr.bit.b3				/* Port P0_3 direction bit */
#define		pd0_4			pd0_addr.bit.b4				/* Port P0_4 direction bit */
#define		pd0_5			pd0_addr.bit.b5				/* Port P0_5 direction bit */
#define		pd0_6			pd0_addr.bit.b6				/* Port P0_6 direction bit */
#define		pd0_7			pd0_addr.bit.b7				/* Port P0_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P1 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd1_addr		03E3h
union BYTE_DEF	pd1_addr;
#define		pd1				pd1_addr.byte

#define		pd1_0			pd1_addr.bit.b0				/* Port P1_0 direction bit */
#define		pd1_1			pd1_addr.bit.b1				/* Port P1_1 direction bit */
#define		pd1_2			pd1_addr.bit.b2				/* Port P1_2 direction bit */
#define		pd1_3			pd1_addr.bit.b3				/* Port P1_3 direction bit */
#define		pd1_4			pd1_addr.bit.b4				/* Port P1_4 direction bit */
#define		pd1_5			pd1_addr.bit.b5				/* Port P1_5 direction bit */
#define		pd1_6			pd1_addr.bit.b6				/* Port P1_6 direction bit */
#define		pd1_7			pd1_addr.bit.b7				/* Port P1_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P2 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p2_addr			03E4h
union BYTE_DEF	p2_addr;
#define		p2				p2_addr.byte

#define		p2_0			p2_addr.bit.b0				/* Port P2_0 bit */
#define		p2_1			p2_addr.bit.b1				/* Port P2_1 bit */
#define		p2_2			p2_addr.bit.b2				/* Port P2_2 bit */
#define		p2_3			p2_addr.bit.b3				/* Port P2_3 bit */
#define		p2_4			p2_addr.bit.b4				/* Port P2_4 bit */
#define		p2_5			p2_addr.bit.b5				/* Port P2_5 bit */
#define		p2_6			p2_addr.bit.b6				/* Port P2_6 bit */
#define		p2_7			p2_addr.bit.b7				/* Port P2_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P3 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p3_addr			03E5h
union BYTE_DEF	p3_addr;
#define		p3				p3_addr.byte

#define		p3_0			p3_addr.bit.b0				/* Port P3_0 bit */
#define		p3_1			p3_addr.bit.b1				/* Port P3_1 bit */
#define		p3_2			p3_addr.bit.b2				/* Port P3_2 bit */
#define		p3_3			p3_addr.bit.b3				/* Port P3_3 bit */
#define		p3_4			p3_addr.bit.b4				/* Port P3_4 bit */
#define		p3_5			p3_addr.bit.b5				/* Port P3_5 bit */
#define		p3_6			p3_addr.bit.b6				/* Port P3_6 bit */
#define		p3_7			p3_addr.bit.b7				/* Port P3_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P2 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd2_addr		03E6h
union BYTE_DEF	pd2_addr;
#define		pd2				pd2_addr.byte

#define		pd2_0			pd2_addr.bit.b0				/* Port P2_0 direction bit */
#define		pd2_1			pd2_addr.bit.b1				/* Port P2_1 direction bit */
#define		pd2_2			pd2_addr.bit.b2				/* Port P2_2 direction bit */
#define		pd2_3			pd2_addr.bit.b3				/* Port P2_3 direction bit */
#define		pd2_4			pd2_addr.bit.b4				/* Port P2_4 direction bit */
#define		pd2_5			pd2_addr.bit.b5				/* Port P2_5 direction bit */
#define		pd2_6			pd2_addr.bit.b6				/* Port P2_6 direction bit */
#define		pd2_7			pd2_addr.bit.b7				/* Port P2_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P3 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd3_addr		03E7h
union BYTE_DEF	pd3_addr;
#define		pd3				pd3_addr.byte

#define		pd3_0			pd3_addr.bit.b0				/* Port P3_0 direction bit */
#define		pd3_1			pd3_addr.bit.b1				/* Port P3_1 direction bit */
#define		pd3_2			pd3_addr.bit.b2				/* Port P3_2 direction bit */
#define		pd3_3			pd3_addr.bit.b3				/* Port P3_3 direction bit */
#define		pd3_4			pd3_addr.bit.b4				/* Port P3_4 direction bit */
#define		pd3_5			pd3_addr.bit.b5				/* Port P3_5 direction bit */
#define		pd3_6			pd3_addr.bit.b6				/* Port P3_6 direction bit */
#define		pd3_7			pd3_addr.bit.b7				/* Port P3_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P4 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p4_addr			03E8h
union BYTE_DEF	p4_addr;
#define		p4				p4_addr.byte

#define		p4_0			p4_addr.bit.b0				/* Port P4_0 bit */
#define		p4_1			p4_addr.bit.b1				/* Port P4_1 bit */
#define		p4_2			p4_addr.bit.b2				/* Port P4_2 bit */
#define		p4_3			p4_addr.bit.b3				/* Port P4_3 bit */
#define		p4_4			p4_addr.bit.b4				/* Port P4_4 bit */
#define		p4_5			p4_addr.bit.b5				/* Port P4_5 bit */
#define		p4_6			p4_addr.bit.b6				/* Port P4_6 bit */
#define		p4_7			p4_addr.bit.b7				/* Port P4_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P5 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p5_addr			03E9h
union BYTE_DEF	p5_addr;
#define		p5				p5_addr.byte

#define		p5_0			p5_addr.bit.b0				/* Port P5_0 bit */
#define		p5_1			p5_addr.bit.b1				/* Port P5_1 bit */
#define		p5_2			p5_addr.bit.b2				/* Port P5_2 bit */
#define		p5_3			p5_addr.bit.b3				/* Port P5_3 bit */
#define		p5_4			p5_addr.bit.b4				/* Port P5_4 bit */
#define		p5_5			p5_addr.bit.b5				/* Port P5_5 bit */
#define		p5_6			p5_addr.bit.b6				/* Port P5_6 bit */
#define		p5_7			p5_addr.bit.b7				/* Port P5_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P4 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd4_addr		03EAh
union BYTE_DEF	pd4_addr;
#define		pd4				pd4_addr.byte

#define		pd4_0			pd4_addr.bit.b0				/* Port P4_0 direction bit */
#define		pd4_1			pd4_addr.bit.b1				/* Port P4_1 direction bit */
#define		pd4_2			pd4_addr.bit.b2				/* Port P4_2 direction bit */
#define		pd4_3			pd4_addr.bit.b3				/* Port P4_3 direction bit */
#define		pd4_4			pd4_addr.bit.b4				/* Port P4_4 direction bit */
#define		pd4_5			pd4_addr.bit.b5				/* Port P4_5 direction bit */
#define		pd4_6			pd4_addr.bit.b6				/* Port P4_6 direction bit */
#define		pd4_7			pd4_addr.bit.b7				/* Port P4_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P5 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd5_addr		03EBh
union BYTE_DEF	pd5_addr;
#define		pd5				pd5_addr.byte

#define		pd5_0			pd5_addr.bit.b0				/* Port P5_0 direction bit */
#define		pd5_1			pd5_addr.bit.b1				/* Port P5_1 direction bit */
#define		pd5_2			pd5_addr.bit.b2				/* Port P5_2 direction bit */
#define		pd5_3			pd5_addr.bit.b3				/* Port P5_3 direction bit */
#define		pd5_4			pd5_addr.bit.b4				/* Port P5_4 direction bit */
#define		pd5_5			pd5_addr.bit.b5				/* Port P5_5 direction bit */
#define		pd5_6			pd5_addr.bit.b6				/* Port P5_6 direction bit */
#define		pd5_7			pd5_addr.bit.b7				/* Port P5_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P6 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p6_addr			03ECh
union BYTE_DEF	p6_addr;
#define		p6				p6_addr.byte

#define		p6_0			p6_addr.bit.b0				/* Port P6_0 bit */
#define		p6_1			p6_addr.bit.b1				/* Port P6_1 bit */
#define		p6_2			p6_addr.bit.b2				/* Port P6_2 bit */
#define		p6_3			p6_addr.bit.b3				/* Port P6_3 bit */
#define		p6_4			p6_addr.bit.b4				/* Port P6_4 bit */
#define		p6_5			p6_addr.bit.b5				/* Port P6_5 bit */
#define		p6_6			p6_addr.bit.b6				/* Port P6_6 bit */
#define		p6_7			p6_addr.bit.b7				/* Port P6_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P7 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p7_addr			03EDh
union BYTE_DEF	p7_addr;
#define		p7				p7_addr.byte

#define		p7_0			p7_addr.bit.b0				/* Port P7_0 bit */
#define		p7_1			p7_addr.bit.b1				/* Port P7_1 bit */
#define		p7_2			p7_addr.bit.b2				/* Port P7_2 bit */
#define		p7_3			p7_addr.bit.b3				/* Port P7_3 bit */
#define		p7_4			p7_addr.bit.b4				/* Port P7_4 bit */
#define		p7_5			p7_addr.bit.b5				/* Port P7_5 bit */
#define		p7_6			p7_addr.bit.b6				/* Port P7_6 bit */
#define		p7_7			p7_addr.bit.b7				/* Port P7_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P6 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd6_addr		03EEh
union BYTE_DEF	pd6_addr;
#define		pd6				pd6_addr.byte

#define		pd6_0			pd6_addr.bit.b0				/* Port P6_0 direction bit */
#define		pd6_1			pd6_addr.bit.b1				/* Port P6_1 direction bit */
#define		pd6_2			pd6_addr.bit.b2				/* Port P6_2 direction bit */
#define		pd6_3			pd6_addr.bit.b3				/* Port P6_3 direction bit */
#define		pd6_4			pd6_addr.bit.b4				/* Port P6_4 direction bit */
#define		pd6_5			pd6_addr.bit.b5				/* Port P6_5 direction bit */
#define		pd6_6			pd6_addr.bit.b6				/* Port P6_6 direction bit */
#define		pd6_7			pd6_addr.bit.b7				/* Port P6_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P7 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd7_addr		03EFh
union BYTE_DEF	pd7_addr;
#define		pd7				pd7_addr.byte

#define		pd7_0			pd7_addr.bit.b0				/* Port P7_0 direction bit */
#define		pd7_1			pd7_addr.bit.b1				/* Port P7_1 direction bit */
#define		pd7_2			pd7_addr.bit.b2				/* Port P7_2 direction bit */
#define		pd7_3			pd7_addr.bit.b3				/* Port P7_3 direction bit */
#define		pd7_4			pd7_addr.bit.b4				/* Port P7_4 direction bit */
#define		pd7_5			pd7_addr.bit.b5				/* Port P7_5 direction bit */
#define		pd7_6			pd7_addr.bit.b6				/* Port P7_6 direction bit */
#define		pd7_7			pd7_addr.bit.b7				/* Port P7_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P8 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p8_addr			03F0h
union BYTE_DEF	p8_addr;
#define		p8				p8_addr.byte

#define		p8_0			p8_addr.bit.b0				/* Port P8_0 bit */
#define		p8_1			p8_addr.bit.b1				/* Port P8_1 bit */
#define		p8_2			p8_addr.bit.b2				/* Port P8_2 bit */
#define		p8_3			p8_addr.bit.b3				/* Port P8_3 bit */
#define		p8_4			p8_addr.bit.b4				/* Port P8_4 bit */
#define		p8_5			p8_addr.bit.b5				/* Port P8_5 bit */
#define		p8_6			p8_addr.bit.b6				/* Port P8_6 bit */
#define		p8_7			p8_addr.bit.b7				/* Port P8_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P9 Register                                                          */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p9_addr			03F1h
union BYTE_DEF	p9_addr;
#define		p9				p9_addr.byte

#define		p9_0			p9_addr.bit.b0				/* Port P9_0 bit */
#define		p9_1			p9_addr.bit.b1				/* Port P9_1 bit */
#define		p9_2			p9_addr.bit.b2				/* Port P9_2 bit */
#define		p9_3			p9_addr.bit.b3				/* Port P9_3 bit */
#define		p9_4			p9_addr.bit.b4				/* Port P9_4 bit */
#define		p9_5			p9_addr.bit.b5				/* Port P9_5 bit */
#define		p9_6			p9_addr.bit.b6				/* Port P9_6 bit */
#define		p9_7			p9_addr.bit.b7				/* Port P9_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P8 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd8_addr		03F2h
union BYTE_DEF	pd8_addr;
#define		pd8				pd8_addr.byte

#define		pd8_0			pd8_addr.bit.b0				/* Port P8_0 direction bit */
#define		pd8_1			pd8_addr.bit.b1				/* Port P8_1 direction bit */
#define		pd8_2			pd8_addr.bit.b2				/* Port P8_2 direction bit */
#define		pd8_3			pd8_addr.bit.b3				/* Port P8_3 direction bit */
#define		pd8_4			pd8_addr.bit.b4				/* Port P8_4 direction bit */
#define		pd8_5			pd8_addr.bit.b5				/* Port P8_5 direction bit */
#define		pd8_6			pd8_addr.bit.b6				/* Port P8_6 direction bit */
#define		pd8_7			pd8_addr.bit.b7				/* Port P8_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P9 Direction Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd9_addr		03F3h
union BYTE_DEF	pd9_addr;
#define		pd9				pd9_addr.byte

#define		pd9_0			pd9_addr.bit.b0				/* Port P9_0 direction bit */
#define		pd9_1			pd9_addr.bit.b1				/* Port P9_1 direction bit */
#define		pd9_2			pd9_addr.bit.b2				/* Port P9_2 direction bit */
#define		pd9_3			pd9_addr.bit.b3				/* Port P9_3 direction bit */
#define		pd9_4			pd9_addr.bit.b4				/* Port P9_4 direction bit */
#define		pd9_5			pd9_addr.bit.b5				/* Port P9_5 direction bit */
#define		pd9_6			pd9_addr.bit.b6				/* Port P9_6 direction bit */
#define		pd9_7			pd9_addr.bit.b7				/* Port P9_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  Port P10 Register                                                         */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		p10_addr		03F4h
union BYTE_DEF	p10_addr;
#define		p10				p10_addr.byte

#define		p10_0			p10_addr.bit.b0				/* Port P10_0 bit */
#define		p10_1			p10_addr.bit.b1				/* Port P10_1 bit */
#define		p10_2			p10_addr.bit.b2				/* Port P10_2 bit */
#define		p10_3			p10_addr.bit.b3				/* Port P10_3 bit */
#define		p10_4			p10_addr.bit.b4				/* Port P10_4 bit */
#define		p10_5			p10_addr.bit.b5				/* Port P10_5 bit */
#define		p10_6			p10_addr.bit.b6				/* Port P10_6 bit */
#define		p10_7			p10_addr.bit.b7				/* Port P10_7 bit */

/*----------------------------------------------------------------------------*/
/*  Port P10 Direction Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pd10_addr		03F6h
union BYTE_DEF	pd10_addr;
#define		pd10			pd10_addr.byte

#define		pd10_0			pd10_addr.bit.b0			/* Port P10_0 direction bit */
#define		pd10_1			pd10_addr.bit.b1			/* Port P10_1 direction bit */
#define		pd10_2			pd10_addr.bit.b2			/* Port P10_2 direction bit */
#define		pd10_3			pd10_addr.bit.b3			/* Port P10_3 direction bit */
#define		pd10_4			pd10_addr.bit.b4			/* Port P10_4 direction bit */
#define		pd10_5			pd10_addr.bit.b5			/* Port P10_5 direction bit */
#define		pd10_6			pd10_addr.bit.b6			/* Port P10_6 direction bit */
#define		pd10_7			pd10_addr.bit.b7			/* Port P10_7 direction bit */

/*----------------------------------------------------------------------------*/
/*  PMC0 Header Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0hdpmin_addr	0D080h
union WORD_DEF	pmc0hdpmin_addr;
#define		pmc0hdpmin		pmc0hdpmin_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC0 Header Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0hdpmax_addr	0D082h
union WORD_DEF	pmc0hdpmax_addr;
#define		pmc0hdpmax		pmc0hdpmax_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC0 Data 0 Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0d0pmin_addr	0D084h
union BYTE_DEF	pmc0d0pmin_addr;
#define		pmc0d0pmin		pmc0d0pmin_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Data 0 Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0d0pmax_addr	0D085h
union BYTE_DEF	pmc0d0pmax_addr;
#define		pmc0d0pmax		pmc0d0pmax_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Data 1 Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0d1pmin_addr	0D086h
union BYTE_DEF	pmc0d1pmin_addr;
#define		pmc0d1pmin		pmc0d1pmin_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Data 1 Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0d1pmax_addr	0D087h
union BYTE_DEF	pmc0d1pmax_addr;
#define		pmc0d1pmax		pmc0d1pmax_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Measurements Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0tim_addr	0D088h
union WORD_DEF	pmc0tim_addr;
#define		pmc0tim			pmc0tim_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC0 Counter Value Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0bc_addr		0D08Ah
union WORD_DEF	pmc0bc_addr;
#define		pmc0bc			pmc0bc_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 0                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat0_addr	0D08Ch
union BYTE_DEF	pmc0dat0_addr;
#define		pmc0dat0		pmc0dat0_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 1                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat1_addr	0D08Dh
union BYTE_DEF	pmc0dat1_addr;
#define		pmc0dat1		pmc0dat1_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 2                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat2_addr	0D08Eh
union BYTE_DEF	pmc0dat2_addr;
#define		pmc0dat2		pmc0dat2_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 3                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat3_addr	0D08Fh
union BYTE_DEF	pmc0dat3_addr;
#define		pmc0dat3		pmc0dat3_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 4                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat4_addr	0D090h
union BYTE_DEF	pmc0dat4_addr;
#define		pmc0dat4		pmc0dat4_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Data Store Register 5                                        */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0dat5_addr	0D091h
union BYTE_DEF	pmc0dat5_addr;
#define		pmc0dat5		pmc0dat5_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC0 Receive Bit Count Register                                           */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc0rbit_addr	0D092h
union BYTE_DEF	pmc0rbit_addr;
#define		pmc0rbit		pmc0rbit_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Header Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1hdpmin_addr	0D094h
union WORD_DEF	pmc1hdpmin_addr;
#define		pmc1hdpmin		pmc1hdpmin_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC1 Header Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1hdpmax_addr	0D096h
union WORD_DEF	pmc1hdpmax_addr;
#define		pmc1hdpmax		pmc1hdpmax_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC1 Data 0 Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1d0pmin_addr	0D098h
union BYTE_DEF	pmc1d0pmin_addr;
#define		pmc1d0pmin		pmc1d0pmin_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Data 0 Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1d0pmax_addr	0D099h
union BYTE_DEF	pmc1d0pmax_addr;
#define		pmc1d0pmax		pmc1d0pmax_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Data 1 Pattern Set Register (MIN)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1d1pmin_addr	0D09Ah
union BYTE_DEF	pmc1d1pmin_addr;
#define		pmc1d1pmin		pmc1d1pmin_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Data 1 Pattern Set Register (MAX)                                    */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1d1pmax_addr	0D09Bh
union BYTE_DEF	pmc1d1pmax_addr;
#define		pmc1d1pmax		pmc1d1pmax_addr.byte

/*----------------------------------------------------------------------------*/
/*  PMC1 Measurements Register                                                */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1tim_addr	0D09Ch
union WORD_DEF	pmc1tim_addr;
#define		pmc1tim			pmc1tim_addr.word

/*----------------------------------------------------------------------------*/
/*  PMC1 Counter Value Register                                               */
/*----------------------------------------------------------------------------*/
#pragma ADDRESS		pmc1bc_addr		0D09Eh
union WORD_DEF	pmc1bc_addr;
#define		pmc1bc			pmc1bc_addr.word

#endif   //for 64A
/*** EOF **********************************************************************/
