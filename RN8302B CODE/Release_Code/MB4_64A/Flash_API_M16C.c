/*********************************************************************
* DISCLAIMER:                                                        *
* The software supplied by Renesas Technology America Inc. is        *
* intended and supplied for use on Renesas Technology products.      *
* This software is owned by Renesas Technology America, Inc. or      *
* Renesas Technology Corporation and is protected under applicable   *
* copyright laws. All rights are reserved.                           *
*                                                                    *
* THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, *
* IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED 		 *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE *
* APPLY TO THIS SOFTWARE. RENESAS TECHNOLOGY AMERICA, INC. AND       *
* AND RENESAS TECHNOLOGY CORPORATION RESERVE THE RIGHT, WITHOUT      *
* NOTICE, TO MAKE CHANGES TO THIS SOFTWARE. NEITHER RENESAS          *
* TECHNOLOGY AMERICA, INC. NOR RENESAS TECHNOLOGY CORPORATION SHALL, *
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR        *
* CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER ARISING OUT OF THE *
* USE OR APPLICATION OF THIS SOFTWARE.                               *
*********************************************************************/

/******************************************************************************
File: Flash_API_M16C.c

CPU Re-write functions for M16C.
Rev 2.4

Revision History  
DD.MM.YYYY OSO-UID Description

??.??.???? RTA-CBB
    Rev 1.0
    NOTE: Was originally multiple files like flash-62p-ew1, flash-62p-ew0,
    flash-26-ew0, flash-26-ew1, etc...
21.05.2004 RTA-CBB
    Rev 2.0
    Combined multiple different versions of this API for different 
    MCUs into this one combined source.
   	Added revision history and added tab setting at top of document
08.07.2004 RTA-CBB
    Rev 2.1
    Changed the way EW0 and EW1 Modes are defined.
    Got rid of all nested comments markers.
20.08.2004 RTA-CBB
    Rev 2.2
    Clear protect bits before R8C flash operations.
	R8C Data blocks A,B were in wrong order
16.09.2004 RTA-CBB
    Rev 2.3
    Added support for M32C/83
03.12.2007 RTA-CBB
    Rev 2.4
    Renamed to Flash_API_M16C.c.
    Removed all M32C and R8C code because this file is only for M16C.
    Added support for M16C/Next
    Erase retry count (3) matches the spec.
	Checks that EW0 re-write code will fit in allocated RAM size.
25.03.2008 RTA-CCB
    Rev 2.5
    Fixed bug: Does not erase when Optimization is turned on
******************************************************************************/

#include "Flash_API_M16C.h"
#include "sfr64a.h"
#include "defdata.h"
#include "eeprom.h"
#include "comm.h"

#define WAIT_TIME 10

#if ( M16C_FLASH == 1) || ( M16C_FLASH == 2)
  /* Flash Register addresses for M16C */
  #pragma ADDRESS		fmr0_addr	01B7H			/* Flash Memory Control Register 0 */
  #pragma ADDRESS		fmr1_addr	01B5H			/* Flash Memory Control Register 1 */
  #pragma ADDRESS		fmr2_addr	0000H			/* Does not exist */
  #pragma ADDRESS		fmr6_addr	0000H			/* Does not exist */
#elif (M16C_FLASH == 3)
  /* Flash Register addresses for M16C Next */
  #pragma ADDRESS		fmr0_addr	0220H			/* Flash Memory Control Register 0 */
  #pragma ADDRESS		fmr1_addr	0221H			/* Flash Memory Control Register 1 */
  #pragma ADDRESS		fmr2_addr	0222H			/* Flash Memory Control Register 2 */
  #pragma ADDRESS		fmr6_addr	0230H			/* Flash Memory Control Register 6 */
#else
  #error "!!! ERROR Flash_API_M16C is only for M16C parts !!!!"
#endif

/* declare SFR bit */
//struct bit_def {
//	char	b0:1;
//	char	b1:1;
//	char	b2:1;
//	char	b3:1;
//	char	b4:1;
//	char	b5:1;
//	char	b6:1;
//	char	b7:1;
//};
//union byte_def {
//	struct bit_def bit;
//	char	byte;
//};

/* Flash memory control register 0 */
//union byte_def fmr0_addr;
//#define		fmr0			fmr0_addr.byte

//#define		fmr00			fmr0_addr.bit.b0	/* RY/BY~ status flag */
//#define		fmr01			fmr0_addr.bit.b1	/* EW0 mode select bit */
//#define		fmr02			fmr0_addr.bit.b2	/* Lock bit disable bit */
//#define		fmr03			fmr0_addr.bit.b3	/* Flash memory reset bit or reserved */
//#define		fmr05			fmr0_addr.bit.b5	/* User ROM area select bit or reserved */
//#define		fmr06			fmr0_addr.bit.b6	/* Program status flag */
//#define		fmr07			fmr0_addr.bit.b7	/* Erase status flag */

//NOT NEED-GANJP 20100408
///* Flash memory control register 1 */
//union byte_def fmr1_addr;
//#define		fmr1			fmr1_addr.byte
//
//#define		fmr11			fmr1_addr.bit.b1	/* EW1 mode select bit */
//#define		fmr16			fmr1_addr.bit.b6	/* Lock bit status flag */
//#define		fmr17			fmr1_addr.bit.b7	/* DAta flashwait bit (M16C next only) */
//
///* Flash memory control register 2 */
//union byte_def fmr2_addr;
//#define		fmr2			fmr2_addr.byte
//#define		fmr22			fmr2_addr.bit.b2	/* Slow Read Mode Enable */
//
///* Flash memory control register 6 */
//union byte_def fmr6_addr;
//#define		fmr6			fmr6_addr.byte
//NOT NEED-GANJP 20100408
///* General Sytems Registers */
//#define pm0   *((char *)0x4)    /* Processor mode register 0 */
//#define pm1   *((char *)0x5)    /* Processor mode register 1 */
//#define cm0   *((char *)0x6)    /* System clock control register 0 */
//#define cm1   *((char *)0x7)    /* System clock control register 1 */
//#define prcr  *((char *)0xA)    /* Protect register */

/******************************************************************************
Global variables and functions private to the file
******************************************************************************/
static unsigned int near flags_reg;	/* For saving the Flags register (must be in near RAM) */
static unsigned char cm0_saved;			/* For saving the Clock Mode 0 register */
static unsigned char cm1_saved;			/* For saving the Clock Mode 1 register */
static unsigned char pm0_saved;			/* For saving the Processor Mode 0 register */
static unsigned char pm1_saved;			/* For saving the Processor Mode 1 register */
static unsigned char prcr_saved;        /*  Save Protection register */
static unsigned char fmr2_saved;        /*  Save Protection register */
static DEFINE_ADDR_LOOKUP;              /* This macro has been define in the h file and will create 
                                           an array called block_addresses. This array is made static
                                           in order for it to not show up in the debugger watch windows. */
#if (EW_MODE == 0)
static long EW0_RAM_CODE_ptr;	/* This will server as a pointer to the code to use */
								/* Note: 3 bytes needed for jmpi instruction */
unsigned char reflash_code_size;  /* For checking if we have enough RAM to hold our re-write code */
  #if (STATIC_RAM_CODE == 1)
/* Allocate RAM space statically to hold the CPU-Rewrite code. */
static unsigned char near EW0_RAM_CODE[ RAM_CODE_SIZE ];
  #endif
#endif

/* Prototypes of functions and macros only used by this file */
static void SlowMCUClock(void);
static void RestoreMCUClock(void);

/******************************************************************************
Macro definitions
******************************************************************************/
#define DISABLE_INTERRUPTS { asm("STC FLG,_flags_reg"); asm("FCLR I");}
#define RESTORE_INTERRUPTS { asm("LDC _flags_reg,FLG"); }

/*****************************************************************************
Name:	FlashEraseEW0 (Should be called using the name FlashErase)
Parameters:
		block
			The block number to erase (BLOCK_0, BLOCK_1, etc...)
Returns:
		0 = Erase Successful
		1 = Erase error reported by flash control
		2 = Command Sequence Error (locked block, incorrect command, etc)
        3 = Not enough RAM space allocated for re-write code
Description:
		Erases an entire flash block.
******************************************************************************/
#if (EW_MODE == 0)
unsigned char FlashEraseEW0( unsigned char block )
{
	volatile int far * flash_addr;
    unsigned char i, ret_value;

#if (STATIC_RAM_CODE == 0)
	/* Allocate RAM space to hold the CPU-Rewrite code on the stack. */
	unsigned char EW0_RAM_CODE[ RAM_CODE_SIZE ];
#endif

    /* Check if the RAM space is big enough to hold our re-write code */
   	asm("mov.w #((ERASE_CODE_END-ERASE_CODE_START+1)), _reflash_code_size");
    if( RAM_CODE_SIZE < reflash_code_size )
    {
        return 3;
    }

    	// Get highest even block address
	flash_addr = (int far *) block_addresses[ block ];

	DISABLE_INTERRUPTS;	// Turn off maskable interrupts

	/* Specify to the assemble code below the RAM code address */
	EW0_RAM_CODE_ptr = (long) EW0_RAM_CODE;

	/* Copy code to RAM using SMOVF instruction (faster than a loop in 'C') */
	/* Can use debugger to determine how big your RAM space needs to be */
	/* M16C instruction copy */
#pragma ASM
	pushm	R1,R3,A0,A1
	mov.w	#((ERASE_CODE_END-ERASE_CODE_START+1) / 2 ),R3	;// transfer count (number of words )
	mov.b	#((ERASE_CODE_START >> 16) & 0FFh),R1H	;// source address
	mov.w	#(ERASE_CODE_START & 0FFFFh),A0			;// source address
	mov.w	_EW0_RAM_CODE_ptr,A1					;// destination address (stored in EW0_RAM_CODE_ptr) 
	smovf.w											;// copy 16 bits at a time
	popm	R1,R3,A0,A1
#pragma ENDASM

	/* Must change main clock speed to meet flash requirements */
	SlowMCUClock();			

	/* Enter CPU-rewite mode */
	fmr01 = 0;
	fmr01 = 1;			// Set EW0 select bit

	/* !! DISABLE ALL FLASH MEMORY LOCK AND PROTECT FUNCTIONALITY !!
	 * NOTE: In order to use lock/protect bit functionality, please refer to
	 * the Flash Memory section in the data sheet for your specific device.
	 * Also note the that following bits clear back to 0 every time you enter
	 * CPU Rewrite Mode.
	 * Note that for some MCUs, if the lock bit is disabled, the error bits
	 * do not function.
	*/
	fmr02 = 0;			// Must write a 0 then a 1 in succession to SET
	fmr02 = 1;			// Disable use of lock bit for block protection

  #if (EXTRA_PROTECT_BITS)
	/* Some devices have an extra bit to unprotect all blocks */
	fmr16 = 0;          // Must write a 0 then a 1 in succession to SET
	fmr16 = 1;          // Disable use of lock bit for block protection
  #endif

	asm("jmpi.a _EW0_RAM_CODE_ptr");	// Jump into RAM routine spcified by EW0_RAM_CODE_ptr
	asm("ERASE_CODE_START:");		// Create an address label so we know where copy code from

    /* Attempt to erase flash up to 3 times before returning failed */
    for( i = 0; i<3; i++)
    {
    	*flash_addr = 0x50;		// Clear status register
    	*flash_addr = 0x20;		// Send erase command
    	*flash_addr = 0xD0;		// Send erase confirm command

    	/* Note: In EW0 Mode, we need to poll the Ready/Busy bit until the operation completed */
    	while(!fmr00)
        {
            // Wait for ready bit if executing in RAM for EW0 mode.
			// Perform other time critical operations such as "kicking" the watchdog timer.
        }

    	/* Check if operation was successful */
		if( !fmr07 )		        // Erasing Successful
        {
            break;
        }
    }

	*flash_addr = 0xFF;		// Send Read Array command in order to tell flash controller
							// to go back into Flash Read mode (as opposed to Read Status mode)

	/* Disable CPU rewriting commands by clearing EW entry bit */
	fmr0 = 0;
	asm("nop");
	asm("jmp.a ERASE_CODE_END");	// If in RAM, this will jump you back to flash memory
	asm("ERASE_CODE_END:");

	RestoreMCUClock();		// Restore clock back to original speed

    if( fmr06 && fmr07 )	// Command Sequence Error?
    {
        ret_value =  2;
    }
	else if( fmr07 )		// Erasing error?
	{
		ret_value =  1;
	}
    else                    // Erase Pass!!
    {
        ret_value =  0;          
    }

	RESTORE_INTERRUPTS;         // Restore I flag to previsous setting
	return ret_value;

}
#endif /* EW_MODE == 0*/

/*****************************************************************************
Name:	FlashWriteEW0 (Should be called using the name FlashWrite)
Parameters: 
		flash_addr
			Flash address location to write to. For M16C & M32C devices, this MUST 
			be an EVEN address. For R8C, odd address is OK.
		buffer_addr
			Address location of data buffer to write to flash
		bytes
			The number of bytes to write. For M16C devices, this MUST be an EVEN number
			because the M16C does word writes only. For R8C devices, an odd number is OK.
			For the M32C/83 only, the number MUST be a multiple of 256 bytes.
Returns:
		0 = Operation Successful
		1 = Write Error reported by flash control register
		2 = Invalid parameter passed
		3 = Command Sequence Error (locked block, incorrect command, etc)
        4 = Not enough RAM space allocated for re-write code
Description:
		Writes bytes into flash. The value of BUF_PTR_TYPE can be made a
		"far" pointer for M16C devices if you wish to pass a buffer address
		that is greater than 0xFFFF. This is set in the header file.
*****************************************************************************/
#if (EW_MODE == 0)
unsigned char FlashWriteEW0(FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes)
{
	unsigned char ret_value = 0;

#if (STATIC_RAM_CODE == 0)
	/* Allocate RAM space to hold the CPU-Rewrite code on the stack. */
	unsigned char EW0_RAM_CODE[ RAM_CODE_SIZE ];
#endif

    /* Check if the RAM space is big enough to hold our re-write code */
   	asm("mov.w #((WRITE_CODE_END-WRITE_CODE_START+1)), _reflash_code_size");
    if( RAM_CODE_SIZE < reflash_code_size )
    {
        return 4;
    }

#if (M16C_FLASH == 1) || (M16C_FLASH == 2)
	/* Check that an even number of bytes were passed */
	if( bytes & 1)
		return 2;	// ERROR!! You must always pass an even number of bytes.

	/* Check for odd address */
	if( (char)flash_addr & (char)1)
		return 2;	// ERROR!! You must always pass an even flash address

#elif (M16C_FLASH == 3)
	/* Check that the number of bytes is a multiple of 4 */
	if( bytes & 3)
		return 2;	// ERROR!! You must always pass a multiple of 4 bytes.

	/* Check for address on a 4byte boundry */
	if( (char)flash_addr & (char)3)
		return 2;	// ERROR!! You must always pass a flash address on a 4-byte boundry
#endif

	DISABLE_INTERRUPTS;	// Turn off maskable interrupts

	/* Specify to the assemble code below the RAM code address */
	EW0_RAM_CODE_ptr = (long) EW0_RAM_CODE;

	/* Copy code to RAM using SMOVF instruction (faster than a loop in 'C') */
	/* Can use debugger to determine how big your RAM space needs to be */
	/* M16C instruction copy */
#pragma ASM
	pushm	R1,R3,A0,A1
	mov.w	#((WRITE_CODE_END-WRITE_CODE_START+1) / 2 ),R3	;// transfer count (number of words )
	mov.b	#((WRITE_CODE_START >> 16) & 0FFh),R1H	;// source address
	mov.w	#(WRITE_CODE_START & 0FFFFh),A0			;// source address
	mov.w	_EW0_RAM_CODE_ptr,A1					;// destination address (stored in EW0_RAM_CODE_ptr) 
	smovf.w											;// copy 16 bits at a time
	popm	R1,R3,A0,A1
#pragma ENDASM

	/* Must change main clock speed to meet flash requirements */
	SlowMCUClock();			

	/* Enter CPU-rewite mode */
	fmr01 = 0;
	fmr01 = 1;				// Set EW0 select bit

	/* !! DISABLE ALL FLASH MEMORY LOCK AND PROTECT FUNCTIONALITY !!
	 * NOTE: In order to use lock/protect bit functionality, please refer to
	 * the Flash Memory section in the data sheet for your specific device.
	 * Also note the that following bits clear back to 0 every time you enter
	 * CPU Rewrite Mode.
	 * Note that for some MCUs, if the lock bit is disabled, the error bits
	 * do not function.
	 */
	fmr02 = 0;			// Must write a 0 then a 1 in succession to SET
	fmr02 = 1;			// Disable use of lock bit for block protection

#if (EXTRA_PROTECT_BITS)
	/* Some devices have an extra bit to unprotect all blocks */
	fmr16 = 0;          // Must write a 0 then a 1 in succession to SET
	fmr16 = 1;          // Disable use of lock bit for block protection
#endif

	asm("jmpi.a _EW0_RAM_CODE_ptr");	// Jump into RAM routine spcified by EW0_RAM_CODE_ptr
	asm("WRITE_CODE_START:");			// Create an address label so we know where copy code from

	*(int far *)flash_addr = 0x50;		// Clear status register
	while(bytes)
	{
#if (M16C_FLASH == 1) || (M16C_FLASH == 2)
		/* Write to the flash sequencer by writting to that area of flash memory */
		*(int far *)flash_addr = 0x40;				// Send write command
		*(int far *)flash_addr = *(int far *)buffer_addr;		// Write next word of data

		flash_addr += 2;			// Advance to next flash write address
		buffer_addr += 2;			// Advance to next data buffer address
		bytes -= 2;				// Subract 2 from byte counter
#endif
#if (M16C_FLASH == 3)
		/* M16C Next writes DWORD at a time */
		*(int far *)flash_addr = 0x41;						// Send write command
		*(long far *)flash_addr = *(long far *)buffer_addr;	// Write 32 bits of data

		flash_addr += 4;			// Advance to next flash write address
		buffer_addr += 4;			// Advance to next data buffer address
		bytes -= 4;				// Subract 2 from byte counter
#endif
		/* Note: In EW0 Mode, we need to poll the Ready/Busy bit until the operation completed */
    	while(!fmr00)
        {
            // Wait for ready bit if executing in RAM for EW0 mode.
			// Perform other time critical operations such as "kicking" the watchdog timer.
        }

		/* Read flash program status flag */
		if( fmr06 )		// Write error?
		{
            if( fmr07 ) // Command Sequence error ?
    			ret_value = 3;		// Signal a Command Sequence error
            else
    			ret_value = 1;		// Signal the flash would not write
			break;				// Break out of while loop
		}
	}

	*(int far *)flash_addr = 0xFF;		// Send Read Array command in order to tell flash controller
							// to go back into Flash Read mode (as opposed to Read Status mode)
	fmr0 = 0;				// disable EW mode by clearing EW entry bit
	asm("nop");

	asm("jmp.a WRITE_CODE_END");	// If in RAM, this will jump you back to flash memory
	asm("WRITE_CODE_END:");

	RestoreMCUClock();		// Restore clock back to original speed
	RESTORE_INTERRUPTS;	// Restore I flag to previous setting

	return ret_value;		// Return Pass/Fail
}
#endif /* EW_MODE == 0 */


/*****************************************************************************
Name:	FlashEraseEW1 (Should be called using the name FlashErase)
Parameters:
		block
			The block number to erase (BLOCK_0, BLOCK_1, etc...)
Returns:
		0 = Erase Successful
		1 = Erase error reported by flash control
		2 = Command Sequence Error (locked block, incorrect command, etc)
Description:
		Erases an entire flash block.
******************************************************************************/
#if ( EW_MODE == 1)
unsigned char FlashEraseEW1( unsigned char block )
{
	volatile int far * flash_addr;
    unsigned char i, ret_value;

	// Get highest even block address
	flash_addr = (int far *) block_addresses[ block ];

	DISABLE_INTERRUPTS;	// Turn off maskable interrupts

	/* Must change main clock speed to meet flash requirements */
	SlowMCUClock();			

	/* Enter CPU-rewite mode */
	fmr01 = 0;
	fmr01 = 1;				// Set EW0 select bit
	fmr11 = 0;
	fmr11 = 1;				// Set to EW1 mode
#if (M16C_FLASH == 3)
    fmr6 = 3;               // New EW1 setting bit for M16C/Next devices
	fmr11 = 0;              // Disable access to fmr6
#endif

	/* !! DISABLE ALL FLASH MEMORY LOCK AND PROTECT FUNCTIONALITY !!
	 * NOTE: In order to use lock/protect bit functionality, please refer to
	 * the Flash Memory section in the data sheet for your specific device.
	 * Also note the that following bits clear back to 0 every time you enter
	 * CPU Rewrite Mode.
	 * Note that for some MCUs, if the lock bit is disabled, the error bits
	 * do not function.
	 */
	fmr02 = 0;			// Must write a 0 then a 1 in succession to SET
	fmr02 = 1;			// Disable use of lock bit for block protection

  #if (EXTRA_PROTECT_BITS)
	/* Some devices have an extra bit to unprotect all blocks */
	fmr16 = 0;          // Must write a 0 then a 1 in succession to SET
	fmr16 = 1;          // Disable use of lock bit for block protection
  #endif

    /* Attempt to erase flash up to 3 times before returning failed */
    for( i = 0; i<3; i++)
    {
		*flash_addr = 0x50;		// Clear status register
		*flash_addr = 0x20;		// Send erase command
		*flash_addr = 0xD0;		// Send erase confirm command

		/* Note: In EW1 Mode, the MCU is suspended until the operation is completed */

        /* Check if operation was successful */
    	if( !fmr07 )		        // Erasing Successful
        {
            break;
        }
	}

	/* Disable CPU rewriting commands by clearing EW entry bit */
	fmr0 = 0;				// (must be 16-bit write for M32C while in EW1 Mode)

	RestoreMCUClock();		// Restore clock back to original speed

    if( fmr06 && fmr07 )	// Command Sequence Error?
    {
        ret_value =  2;
    }
	else if( fmr07 )		// Erasing error?
	{
		ret_value =  1;
	}
    else                    // Erase Pass!!
    {
        ret_value =  0;          
    }

	RESTORE_INTERRUPTS;         // Restore I flag to previsous setting
	  
	return ret_value;

}
#endif /* EW_MODE == 1*/

/*****************************************************************************
Name:	FlashWriteEW1 (Should be called using the name FlashWrite)
Parameters: 
		flash_addr
			Flash address location to write to. For M16C devices, this MUST be an EVEN 
			address. For R8C, odd address is OK.
		buffer_addr
			Address location of data buffer to write to flash
		bytes
			The number of bytes to write. For M16C devices, this MUST be an EVEN number
			because the M16C does word writes only. For R8C devices, an odd number is OK.
Returns:
		0 = Operation Successful
		1 = Write Error reported by flash control register
		2 = Invalid parameter passed
		3 = Command Sequence Error (locked block, incorrect command, etc)
Description:
		Writes bytes into flash. The value of BUF_PTR_TYPE can be made a
		"far" pointer for M16C devices if you wish to pass a buffer address
		that is greater than 0xFFFF. This is set in the header file.
*****************************************************************************/
#if ( EW_MODE == 1)
unsigned char FlashWriteEW1(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes)
{
	unsigned char ret_value = 0;
	unsigned char wait_time = 0;

#if (M16C_FLASH == 1) || (M16C_FLASH == 2)
	/* Check that an even number of bytes were passed */
	if( bytes & 1)
		return 2;	// ERROR!! You must always pass an even number of bytes.

	/* Check for odd address */
	if( (char)flash_addr & (char)1)
		return 2;	// ERROR!! You must always pass an even flash address

#elif (M16C_FLASH == 3)
	/* Check that the number of bytes is a multiple of 4 */
	if( bytes & 3)
		return 2;	// ERROR!! You must always pass a multiple of 4 bytes.

	/* Check for address on a 4byte boundry */
	if( (char)flash_addr & (char)3)
		return 2;	// ERROR!! You must always pass a flash address on a 4-byte boundry
#endif

	DISABLE_INTERRUPTS;	// Turn off maskable interrupts

	/* Must change main clock speed to meet flash requirements */
	SlowMCUClock();			

	/* Enter CPU-rewite mode */
	fmr01 = 0;
	fmr01 = 1;				// Set EW0 select bit
	fmr11 = 0;
	fmr11 = 1;				// Set to EW1 mode
#if (M16C_FLASH == 3)
    fmr6 = 3;               // New EW1 setting bit for M16C/Next devices
	fmr11 = 0;              // Disable access to fmr6
#endif

	/* !! DISABLE ALL FLASH MEMORY LOCK AND PROTECT FUNCTIONALITY !!
	 * NOTE: In order to use lock/protect bit functionality, please refer to
	 * the Flash Memory section in the data sheet for your specific device.
	 * Also note the that following bits clear back to 0 every time you enter
	 * CPU Rewrite Mode.
	 * Note that for some MCUs, if the lock bit is disabled, the error bits
	 * do not function.
	 */
	fmr02 = 0;			// Must write a 0 then a 1 in succession to SET
	fmr02 = 1;			// Disable use of lock bit for block protection

  #if (EXTRA_PROTECT_BITS)
	/* Some devices have an extra bit to unprotect all blocks */
	fmr16 = 0;          // Must write a 0 then a 1 in succession to SET
	fmr16 = 1;          // Disable use of lock bit for block protection
  #endif

	*(int far *)flash_addr = 0x50;		// Clear status register
	while(bytes)
	{
#if (M16C_FLASH == 1) || (M16C_FLASH == 2)
		/* Write to the flash sequencer by writting to that area of flash memory */
		*(int far *)flash_addr = 0x40;				// Send write command
		*(int far *)flash_addr = *(int far *)buffer_addr;		// Write next word of data

		/* Note: In EW1 Mode, the MCU is suspended until the operation completed */

		flash_addr += 2;			// Advance to next flash write address
		buffer_addr += 2;			// Advance to next data buffer address
		bytes -= 2;				// Subract 2 from byte counter
#endif
#if (M16C_FLASH == 3)
		/* M16C Next writes DWORD at a time */
		*(int far *)flash_addr = 0x41;						// Send write command
		*(long far *)flash_addr = *(long far *)buffer_addr;	// Write 32 bits of data

		/* Note: In EW1 Mode, the MCU is suspended until the operation completed */

		flash_addr += 4;			// Advance to next flash write address
		buffer_addr += 4;			// Advance to next data buffer address
		bytes -= 4;				// Subract 2 from byte counter
#endif
//protect added by ganjp
    for(wait_time = 0; wait_time < WAIT_TIME; wait_time++)
    {
    	if( fmr00 )
    		{
    			break;//Break out of for (wait) loop
    		}
    	else
    		{
    			continue;
    		}    		
    }
		/* Read flash program status flag */
		if( fmr06 )		// Write error?
		{
            if( fmr07 ) // Command Sequence error ?
    			ret_value = 3;		// Signal a Command Sequence error
            else
    			ret_value = 1;		// Signal the flash would not write
			break;				// Break out of while loop
		}
	}

	/* Disable CPU rewriting commands by clearing EW entry bit */
	fmr0 = 0;				// (must be 16-bit write for M32C while in EW1 Mode)

	RestoreMCUClock();		// Restore clock back to original speed
	RESTORE_INTERRUPTS;	// Restore I flag to previous setting
	  
	return ret_value;		// Return Pass/Fail
}
#endif /* EW_MODE == 1*/

/*****************************************************************************
Name:	FlashReadEW1 
Parameters: 
		flash_addr
			Flash address location to read to data buffer. 
		buffer_addr
			Address location of data buffer to read from flash.
		bytes
			The number of bytes to read.
Returns:
		0 = Operation Successful
Description:
		read bytes from flash. The value of BUF_PTR_TYPE can be made a
		"far" pointer for M16C devices if you wish to pass a buffer address
		that is greater than 0xFFFF. This is set in the header file.
*****************************************************************************/
#if ( EW_MODE == 1)
unsigned char FlashReadEW1(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes)
{
	unsigned char ret_value = 0;
    unsigned int tmp;

    if (bytes == 0) {
        return 1;
    }
	
	if( fmr00 == 0 )       //Flash busy now
		{
			ret_value = 1;
			
		}
	else
		{
//			*(int far *)flash_addr = 0xff;		// send read align command
         if ((unsigned long)flash_addr & 0x1) {/*" QQQ 地址不对齐 从地址减1处取16bit 再取其高8位 "*/
            tmp = *(int far *)(flash_addr - 1);
            buffer_addr[0] = (unsigned char)(tmp >> 8);
       
	     	flash_addr += 1;			// Advance to next flash Read address
	     	buffer_addr += 1;			// Advance to next data buffer address
	     	bytes -= 1;				// Subract 1 from byte counter
         }
			while(bytes)
	     {
            if (bytes == 1) {/*" 最后一字节，则从地址处取2字节，然后取低8位 "*/
                tmp = *(int far *)flash_addr;
                buffer_addr[0] = (unsigned char)(tmp & 0xff);
                break;
            }
	     	tmp = *(int far *)flash_addr;	// Read 16 bits of data
            buffer_addr[0] = (unsigned char)(tmp & 0xff);/*" 以字节的方式操作目的buffer 防止不对齐访问 "*/
            buffer_addr[1] = (unsigned char)(tmp >> 8);
            
	     	flash_addr += 2;			// Advance to next flash write address
	     	buffer_addr += 2;			// Advance to next data buffer address
	     	bytes -= 2;				// Subract 2 from byte counter
	     }
		}	
	return ret_value;		// Return Pass/Fail
}
#endif /* EW_MODE == 1*/

/*****************************************************************************
Name:       SlowMCUClock
Parameters: none                     
Returns:  nothing     
Description: Sets the processor mode for programming flash and saves current
             settings to restore later. You cannot run the processor faster
             than 10.0 MHz (with wait state) or 6.25MHz (without wait state)
             when sending commanads to the flash controller.
*****************************************************************************/
static void SlowMCUClock(void)
{
	/* Unprotect registers CM0 and CM1 and PM0 registers by writting to protection register */
	prcr_saved = prcr;      // Save Protection register
	prcr = 3;               // Allow writting to protected system registers

#if ( (EW_MODE == 1) && ((M16C_FLASH == 1) || (M16C_FLASH == 3)) )
	/* Force to Single chip mode for processors that have memory expansion mode */
	pm0_saved = pm0;				// Save pm0 register
	pm0 = pm0_saved & 0xFC;		    // bit 0 and 1 to zero
#endif


	/* For M16C Next Only */
#if (M16C_FLASH == 3)
	fmr2_saved = fmr2;    // Save fmr2 register
	fmr2 = 0;              // Disable slow read mode
#endif

	/***************************/
	/* Clock settings for M16C */
	/***************************/
    cm0_saved = cm0;		// Save cm0 register
    cm1_saved = cm1;		// Save cm1 register
	pm1_saved = pm1;		// Save pm1 register

	/* Insert Wait state for all bus access (needed for talking to the */
	/* internal flash controller) */
	asm("BSET	7,05h");		/* Set bit PM17 */

	/* Now slow the clock down to at least 10MHz */
    /*********************************************/
#if (BCLK_FREQUENCY <= 10000000)
	/* NO NEED TO SLOW DOWN CLOCK */
#elif (BCLK_FREQUENCY <= 20000000 )
/* Set main clock divide by 2 */
	asm("BSET	6,07h");		/* Set bit CM16 */	
	asm("BCLR	7,07h");		/* Clear bit CM17 */
	asm("BCLR	6,06h");		/* Clear bit CM06 */
#elif (BCLK_FREQUENCY <= 40000000)
	/* Set main clock divide by 4 */
	asm("BCLR	6,07h");		/* Clear bit CM16 */	
	asm("BSET	7,07h");		/* Set bit CM17   */
	asm("BCLR	6,06h");		/* Clear bit CM06 */
#else /* BCLK_FREQUENCY > 40000000 */
	/* Set main clock divide by 8 */
	asm("BSET	6,06h");		/* Set bit CM06 */
#endif /* BCLK_FREQUENCY */


}

/*****************************************************************************
Name:       RestoreMCUClock
Parameters: none                     
Returns:  	nothing
Description: Restores the processor mode back to original settings.
*****************************************************************************/
static void RestoreMCUClock(void)			
{
#if ( (EW_MODE == 1) && ((M16C_FLASH == 1) || (M16C_FLASH == 3)) )
	pm0 = pm0_saved;		// Restore pm0 register
#endif

	/* Clock settings for R8C and M16C */
    cm1 = cm1_saved;		// Restore cm1 register
    cm0 = cm0_saved;		// Restore cm0 register
    pm1 = pm1_saved;		// Restore pm1 register
	prcr = prcr_saved;	    // Protection back on

	/* For M16C Next Only */
#if (M16C_FLASH == 4)
	fmr2 = 0;      			// If setting fmr22, need to write a 0 first
	fmr2 = fmr2_saved;      // Restore fmr2 register
#endif

}





