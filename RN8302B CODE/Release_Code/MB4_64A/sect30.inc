;***************************************************************************
; C Compiler for R8C/Tiny, M16C/60,30,20,10
; Copyright(C) 1999(2000-2006). Renesas Technology Corp.
; and Renesas Solutions Corp., All rights reserved.
;
; sect30.inc : section definition for M16C family
;
; $Date: 2007/11/29 09:01:46 $
; $Revision: 1.1.4.1.8.1 $
;***************************************************************************

;=====================================================================
;
; 	Arrangement of section
;
;---------------------------------------------------------------------
; Near RAM data area
;---------------------------------------------------------------------
; SBDATA area
		.section	data_SE,DATA
		.org		400H
data_SE_top:

		.section	bss_SE,DATA,ALIGN
bss_SE_top:

		.section	data_SO,DATA
data_SO_top:

		.section	bss_SO,DATA
bss_SO_top:

; SBDATA area definition
		.glb		__SB__
__SB__	.equ		data_SE_top

; near RAM area
		.section	data_NE,DATA,ALIGN
data_NE_top:

		.section	bss_NE,DATA,ALIGN
bss_NE_top:

		.section	data_NO,DATA
data_NO_top:

		.section	bss_NO,DATA
bss_NO_top:

;---------------------------------------------------------------------
; Stack area
;---------------------------------------------------------------------
		.section	istack,DATA,ALIGN
		.blkb		__ISTACKSIZE__
istack_top:

.if __STACKSIZE__ != 0
		.section	stack,DATA,ALIGN
		.blkb		__STACKSIZE__
stack_top:
.endif

;---------------------------------------------------------------------
; heap section
;---------------------------------------------------------------------
.if __HEAPSIZE__ != 0
		.section	heap,DATA
heap_top:
		.blkb		__HEAPSIZE__
.endif

;---------------------------------------------------------------------
; Near ROM data area
;---------------------------------------------------------------------
.if __NEAR_ROM_FLG__ != 0
		.section	rom_NE,ROMDATA,ALIGN
rom_NE_top:

		.section	rom_NO,ROMDATA
rom_NO_top:
.endif

;---------------------------------------------------------------------
; Far RAM data area
;---------------------------------------------------------------------
.if __FAR_RAM_FLG__ != 0
		.section	data_FE,DATA
		.org		10000H
data_FE_top:

		.section	bss_FE,DATA,ALIGN
bss_FE_top:

		.section	data_FO,DATA
data_FO_top:

		.section	bss_FO,DATA
bss_FO_top:
.endif

		.section	UserROMData_FE,ROMDATA   ;;added by mw 2010-01-05 Begin 
		.org		00f000H   
		.section	UserROMData_FO,ROMDATA   ;;added by mw 2010-01-05 End 
		
		.section	ROM_PRG2,CODE          ;;added by mw 2011-03-19 
		.org		010000H
ROM2_top:	

		.section	ROM_PRGNOUSE,CODE          ;;added by mw 2011-08-31
		.org		014000H
ROMNOUSE_top:	
;---------------------------------------------------------------------
; Far ROM data area
;---------------------------------------------------------------------
		.section	rom_FE,ROMDATA
		.org		__ROM_TOPADR__
rom_FE_top:

		.section	rom_FO,ROMDATA
rom_FO_top:

;---------------------------------------------------------------------
; Initial data of 'data' section
;---------------------------------------------------------------------
		.section	data_SEI,ROMDATA,ALIGN
data_SEI_top:

		.section	data_SOI,ROMDATA
data_SOI_top:

		.section	data_NEI,ROMDATA,ALIGN
data_NEI_top:
 
		.section	data_NOI,ROMDATA
data_NOI_top:

.if __FAR_RAM_FLG__ != 0
		.section	data_FEI,ROMDATA,ALIGN
data_FEI_top:

		.section	data_FOI,ROMDATA
data_FOI_top:
.endif

;---------------------------------------------------------------------
; Switch Table Section
;---------------------------------------------------------------------
;		.section	switch_table,ROMDATA
;switch_table_top:

;---------------------------------------------------------------------
; code area
;---------------------------------------------------------------------
		.section	program,CODE,ALIGN
		.section	interrupt,CODE,ALIGN
		.section	program_S,CODE,ALIGN

;---------------------------------------------------------------------
; variable vector section
;---------------------------------------------------------------------
		.section	vector,ROMDATA
		.org		__VECTOR_ADR__

;;.if	0 ; mw closed 2009-12-23
		.lword	dummy_int		; vector  0  BRK
		.lword	dummy_int		; vector  1
		;.lword	dummy_int		; vector  2
		;.lword	dummy_int		; vector  3
		;.lword	dummy_int		; vector  4
		
		;;mw modified 2009-12-24 begin
		
		.org	(__VECTOR_ADR__ +8)							;mw  2012.02.02  INT7
		.glb	_Int7_Int	
		.lword	_Int7_Int	
		
		.org	(__VECTOR_ADR__ +12)	;mw  2012.02.02  INT6
		.lword	dummy_int
		 
		.org	(__VECTOR_ADR__ +16)							;ADDED BY LDH/*INT3--全失压中断服务程序*/
		.glb	_AllVoltageLoss_WakingUp_Counter_Updating	;ADDED BY LDH
		.lword	_AllVoltageLoss_WakingUp_Counter_Updating	;ADDED BY LDH
		
		.org	(__VECTOR_ADR__ +20)
		.glb	_TimerB5_Int
		.lword	_TimerB5_Int
		
		.org	(__VECTOR_ADR__ +24)
		.glb	_TimerB4_Int
		.lword	_TimerB4_Int
		
		.org	(__VECTOR_ADR__ +28)							;ADDED BY LDH/*INT3--TB3中断服务程序*/
		;.glb	_TB3_Int									;ADDED BY LDH
		;.lword	_TB3_Int									;ADDED BY LDH	
		.lword	dummy_int   ;mw added 2008-11-08
		
		.org	(__VECTOR_ADR__ +32)	;ADDED BY LDH			/*INT5--激光点亮中断服务程序*/
		.glb	_Laser_Wakeup_Int	;ADDED BY LDH
		.lword	_Laser_Wakeup_Int	;ADDED BY LDH
		
		.org	(__VECTOR_ADR__ +36)	;ADDED BY LDH
		.lword	dummy_int
		;;.glb		_SIO3_Receive_Int	;ADDED BY LDH
		;;.lword	_SIO3_Receive_Int	;ADDED BY LDH
		
		.lword	dummy_int		; vector 10  (for user) Bus collision detection
		;;mw reserved 2009-12-23
		
		.org	(__VECTOR_ADR__ +44)
		.lword	dummy_int		; DMA0 (for user)
		.lword	dummy_int 		; DMA1 2 (for user)
		;.lword	dummy_int		; input key (for user)
		.glb _key_interrupts
		.lword _key_interrupts
		;.lword	dummy_int		; AD Convert (for user)
		.glb _Ad_Converter_Int
		.lword _Ad_Converter_Int
		
		.org	(__VECTOR_ADR__ +60)
		.glb    _Uart2T_Int
		.lword	_Uart2T_Int
		;.lword	dummy_int		; uart2 trance (for user)
		.glb    _Uart2R_Int
		.lword	_Uart2R_Int
		;.lword	dummy_int		; uart2 receive (for user)
		.glb    _Uart0T_Int
		.lword	_Uart0T_Int
		;.lword	dummy_int		; uart0 trance (for user)
		.glb    _Uart0R_Int
		.lword	_Uart0R_Int
		;.lword	dummy_int		; uart0 receive (for user)
		.glb    _Uart1T_Int
		.lword	_Uart1T_Int
		;.lword 0FCB6Bh  		; uart1 trance (for user)
		.glb    _Uart1R_Int
		.lword	_Uart1R_Int
		;.lword 0FCB6Bh     	        ; uart1 receive (for user)
		
		
		.glb    _TimerA0_Int
		.lword	_TimerA0_Int
		;.lword	dummy_int		; TIMER A0 (for user)
		.lword	dummy_int		; TIMER A1 (for user)
		;.lword	dummy_int		; TIMER A2 (for user)
		.org	(__VECTOR_ADR__ +92)
		.glb    _TimerA2_Int
		.lword	_TimerA2_Int
		;.lword	dummy_int		; TIMER A3 (for user)
		.org	(__VECTOR_ADR__ +96)
		.glb    _TimerA3_Int
		.lword	_TimerA3_Int	
		;.lword  dummy_int		; TIMER A4 (for user) (vector 25)
		.org	(__VECTOR_ADR__ +100)
		.glb    _IR_interrupts	;/*"遥控器用计数中断"*/
		.lword	_IR_interrupts	
		.org	(__VECTOR_ADR__ +104)
		.glb    _TB0_Int	;/*"遥控器用计数中断"*/
		.lword	_TB0_Int
		;;;.lword	dummy_int		; TIMER B0 (for user) (vector 26)
		.org	(__VECTOR_ADR__+108)	;ADDED BY LDH
		.glb	_TB1_Int		;/*"TB1定时器中断服务程序(fc32,1秒)"*/
		.lword	_TB1_Int		; TIMER B1 (for user) (vector 27)
		;.lword	dummy_int		; TIMER B2 (for user) (vector 28)
		.org	(__VECTOR_ADR__+112)	;ADDED BY LDH
		.glb    _IR_Timer		;/*"遥控器用定时中断"*/
		.lword	_IR_Timer
		;.lword	dummy_int		; INT0 (for user) (vector 29)
		.org	(__VECTOR_ADR__+116)	;ADDED BY LDH
		.glb    _Int0_Int
		.lword  _Int0_Int
		;.lword	dummy_int		; INT1 (for user) (vector 30)
		
		.org	(__VECTOR_ADR__+120)	;INT1 (for user) (vector 30)
		.glb	_Int1_Int		;ADDED BY LDH
		.lword	_Int1_Int		;ADDED BY LDH
		
		;.lword	dummy_int		; INT2 (for user) (vector 31)
		.org	(__VECTOR_ADR__+124)	;ADDED BY LDH
		.glb    _Int2_Int		;/*"掉电中断服务程序"*/
		.lword  _Int2_Int

;                                   .lword	dummy_int		; vector 32  (for user or MR30)
		.org	(__VECTOR_ADR__+188)	;ADDED BY LDH
		.glb    _Uart6T_Int		;/*"UART6发送"*/
		.lword  _Uart6T_Int

;                               .lword	dummy_int		; vector 33  (for user or MR30)
		.org	(__VECTOR_ADR__+192)	;ADDED BY LDH;
		.glb    _Uart6R_Int		;/*"UART6接收"*/
		.lword  _Uart6R_Int	

	        .lword	dummy_int

;                                   .lword	dummy_int		; vector 32  (for user or MR30)
		.org	(__VECTOR_ADR__+200)	;ADDED BY LDH
		.glb    _Uart7T_Int		;/*"UART7发送"*/
		.lword  _Uart7T_Int


;                               .lword	dummy_int		; vector 33  (for user or MR30)
		.org	(__VECTOR_ADR__+204)	;ADDED BY LDH
		.glb    _Uart7R_Int		;/*"UART7接收"*/
		.lword  _Uart7R_Int		
		
		
		.lword	dummy_int		; vector 34  (for user or MR30)
		.lword	dummy_int		; vector 35  (for user or MR30)
		.lword	dummy_int		; vector 36  (for user or MR30)
		.lword	dummy_int		; vector 37  (for user or MR30)
		.lword	dummy_int		; vector 38  (for user or MR30)
		.lword	dummy_int		; vector 39  (for user or MR30)
		.lword	dummy_int		; vector 40  (for user or MR30)
		.lword	dummy_int		; vector 41  (for user or MR30)
		.lword	dummy_int		; vector 42  (for user or MR30)
		.lword	dummy_int		; vector 43  (for user or MR30)
		.lword  dummy_int		; vector 44  (for user or MR30)
		.lword	dummy_int		; vector 45  (for user or MR30)
		.lword	dummy_int		; vector 46  (for user or MR30)
		.lword	dummy_int 		; vector 47  (for user or MR30)
		.lword	dummy_int 		; vector 48
		.lword	dummy_int 		; vector 49
		.lword	dummy_int 		; vector 50
		.lword	dummy_int 		; vector 51
		.lword	dummy_int 		; vector 52
		.lword	dummy_int 		; vector 53
		.lword	dummy_int 		; vector 54
		.lword	dummy_int 		; vector 55
		.lword	dummy_int 		; vector 56
		.lword	dummy_int 		; vector 57
		.lword	dummy_int 		; vector 58
		.lword	dummy_int 		; vector 59
		.lword	dummy_int 		; vector 60
		.lword	dummy_int 		; vector 61
		.lword	dummy_int 		; vector 62
		.lword	dummy_int 		; vector 63
		
		;;mw modified 2009-12-24 begin 
		
;;.endif

;---------------------------------------------------------------------
; fixed vector section
;---------------------------------------------------------------------
		.section	fvector,ROMDATA
		.org		0fffdcH
UDI:
		.lword		dummy_int
OVER_FLOW:
		.lword		dummy_int
BRKI:
		.lword		dummy_int
ADDRESS_MATCH:
		.lword		dummy_int
SINGLE_STEP:
		.lword		dummy_int
WDT:
		.lword		dummy_int
DBC:
		.lword		dummy_int
NMI:
		.lword		dummy_int
RESET:
		.lword	start

;=====================================================================
; ID code & ROM code protect
;---------------------------------------------------------------------
; ID code check function
		.id "#FFFFFFFFFFFFFF"

; ROM code protect control address
		; .protect 00H

;=====================================================================
; Initialize Macro declaration
;---------------------------------------------------------------------
N_BZERO	.macro		TOP_,SECT_
		mov.b		#00H,R0L
		mov.w		#(TOP_ & 0FFFFH),A1
		mov.w		#sizeof SECT_,R3
		sstr.b
		.endm

N_BCOPY .macro		FROM_,TO_,SECT_
		mov.w		#(FROM_ & 0FFFFH),A0
		mov.b		#(FROM_ >> 16),R1H
		mov.w		#TO_,A1
		mov.w		#sizeof SECT_,R3
		smovf.b
		.endm

BZERO	.macro		TOP_,SECT_
		push.w		#sizeof SECT_ >> 16
		push.w		#sizeof SECT_  & 0ffffh
		pusha		TOP_ >> 16
		pusha		TOP_ & 0ffffh
		.stk		8           ;;question4 Ask Renesas mw recorded 2009-12-03
		.glb		_bzero
		.call		_bzero,G    ;;question5 Ask Renesas mw recorded 2009-12-03
		jsr.a		_bzero
		.endm

BCOPY	.macro		FROM_ ,TO_ ,SECT_
		push.w		#sizeof SECT_  >> 16
		push.w		#sizeof SECT_  & 0ffffh
		pusha		TO_ >> 16
		pusha		TO_  & 0ffffh
		pusha		FROM_ >> 16
		pusha		FROM_  & 0ffffh
		.stk		12
		.glb		_bcopy
		.call   	_bcopy,G
		jsr.a		_bcopy
		.endm

;***************************************************************************
;	C Compiler for R8C/Tiny, M16C/60,30,20,10
; Copyright(C) 1999(2000-2006). Renesas Technology Corp.
; and Renesas Solutions Corp., All rights reserved.
;***************************************************************************
