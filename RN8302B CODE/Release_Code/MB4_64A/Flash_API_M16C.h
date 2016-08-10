/******************************************************************************
File: Flash_API_M16C.h

CPU Re-write functions for M16C.
Version 2.4

Revision History  
DD.MM.YYYY OSO-UID Description

08.07.2004 RTA-CBB (Rev 2.1) Combined multiple files into one
02.02.2006 RTA-CBB (Rev 2.2) Added R8C dervitives
29.03.2006 RTA-CBB (Rev 2.3) Modified order of _near & _far specifiers
03.12.2007 RTA-CBB (Rev 2.4) Added new M16C parts. Renamed to xxx_M16C.h
******************************************************************************/

#ifndef _FLASH_API_H
#define _FLASH_API_H

/* Paramter Types */
#define FLASH_PTR_TYPE unsigned char far *
#define   BUF_PTR_TYPE unsigned char far *		/* Can be changed to "near" if buffers will only bein RAM */

// [ Availible Functions for M16C ]
extern unsigned char FlashErase( unsigned char block );
extern unsigned char FlashWrite( FLASH_PTR_TYPE  flash_addr,
                          BUF_PTR_TYPE    buffer_addr,
                          unsigned int    bytes);
extern unsigned char FlashRead ( FLASH_PTR_TYPE flash_addr,
						  BUF_PTR_TYPE buffer_addr,
						  unsigned int bytes);

                          
/********************************
 * SPECIFY YOUR CLOCK SPEED     *
 ********************************
 * You need to specify the speed of your system bus clock (BCLK)
 * so that the correct programming speed can be calculated
 * for communicating to the flash controller
 * The value should be in Hertz
 * Alternatively, you could define your Clock Speed in your Hew project settings
 *________________________________________________________________________*/
#define BCLK_FREQUENCY 10000000

#if !defined(BCLK_FREQUENCY)
  "ERROR !!! You must specify the Clock Frequency (BCLK_FREQUENCY) in Flash_API_M16C.h first !!!";
#endif

/********************************
 * SELECT EW0 or EW1 Flash MODE *
 ********************************
 * You may select to use Erase-Write Mode 0 or Erase-Write Mode 1
 * for sending commands to the flash sequencer. Note EW0 mode
 * executes the flash commands to RAM and waits for the flash
 * operation to complete, where EW1 mode sends commands while
 * executing out of flash, but the MCU going into a hold state till
 * the flash operation is complete. 
 * It is recomended to use use EW1 mode.
 *
 * Alternatively, you could define this in your Hew project settings
 * Select only one.
 *________________________________________________________________________*/
//#define EW_MODE 0
//    or
#define EW_MODE 1

#if !defined(EW_MODE)
 "ERROR !!! You must specify the Flash Mode (EW_MODE = 0 or 1) in Flash_API_M16C.h first !!!"
#endif

/********************************
 * SELECT YOUR MCU              *
 ********************************							
 * Select your desired device by removing the comment markers
 * from the beginging of the line. 
 * Alternatively, you could define your MCU in your Hew project settings
 * Select only one.
 *________________________________________________________________________*/
//#define M16C_1N2 1
//#define M16C_26  1
//#define M16C_26A 1
//#define M16C_28  1
//#define M16C_29  1
//#define M16C_6N4 1
//#define M16C_6N5 1
//#define M16C_62P 1
#define M16C_64  1

/*********************************************
 * SPECIFY EW0 MODE RAM CODE SIZE/ALLOCATION *
 *********************************************
 * If using Erase-Write Mode 0, code will need to be executed out
 * of RAM when sending commands to the Flash controller. The following
 * lets you specify the size and allocation of that RAM area.
 *________________________________________________________________________
 * MAX_RAM_CODE_SIZE - This is the size in bytesof the RAM area that will be 
 *                     allocated and used for both the Erase and Write routines.
 *                     Note that when determining this size, the FlashWrite 
 *                     routine will require more space. */
#define RAM_CODE_SIZE 120

/* STATIC_RAM_CODE - With this option, you can specify if you want the RAM
 *                   code area to be statically allocated, or allocated on
 *                   the stack when an Erase or Write function is called.
 *                   A value of '1' will allocate RAM as a static array.
 *                   A value of '0' will dynamically allocate RAM on the stack. */
#define STATIC_RAM_CODE 1











/* !!!!! DO NOT MODIFY BELOW THIS LINE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


// ======== #define values ==========
//
// M16C_FLASH values
//  1: Standard lock functions
//  2: M16C/2X series with fmr16 protect functions
//  3: M16C/Next series
//
//
// PROTECT_BITS values
//  0: Flash does NOT has protect bits
//  1: Flash has protect bits

// EXTRA_PROTECT_BITS values
//  0: Flash does NOT has protect bits
//  1: Flash has protect bits

#if   defined(M16C_62P)
 #define M16C_FLASH 1
#elif defined(M16C_64)
 #define M16C_FLASH 3
#elif defined(M16C_6N4)
 #define M16C_FLASH 1
#elif defined(M16C_6N5)
 #define M16C_FLASH 1
#elif defined(M16C_1N2)
 #define M16C_FLASH 2
#elif defined(M16C_26)
 #define M16C_FLASH 2
#elif defined(M16C_26A)
 #define M16C_FLASH 2
#elif defined(M16C_28)
 #define M16C_FLASH 2
#elif defined(M16C_29)
 #define M16C_FLASH 2
#else
 #error "!!! You must specify your device in Flash_API_M16C.h first !!!"
#endif

#if   (EW_MODE == 0)
 #define FlashErase FlashEraseEW0
 #define FlashWrite FlashWriteEW0
#elif (EW_MODE == 1)
 #define FlashErase FlashEraseEW1
 #define FlashWrite FlashWriteEW1
 #define FlashRead  FlashReadEW1 
#endif

/* Function Prototypes */
unsigned char FlashErase( unsigned char block );

unsigned char FlashWrite(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE   buffer_addr,
							unsigned int   bytes);
							
unsigned char FlashRead(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes);

/***************************************************************/
/* M16C/62P, M16C/6N4, M16C/6N5                                */
/***************************************************************/
#if (M16C_FLASH == 1)

/* Flash protect bits */
#define EXTRA_PROTECT_BITS 0

/* User Block Area */
#define BLOCK_0 0		/*  4KB: FF000 - FFFFF */
#define BLOCK_1 1		/*  4KB: FE000 - FEFFF */
#define BLOCK_2 2		/*  8KB: FC000 - FDFFF */
#define BLOCK_3 3		/*  8KB: FA000 - FBFFF */
#define BLOCK_4	4		/*  8KB: F8000 - F9FFF */
#define BLOCK_5	5		/* 32KB: F0000 - F7FFF */
#define BLOCK_6 6		/* 64KB: E0000 - EFFFF */
#define BLOCK_7	7		/* 64KB: D0000 - DFFFF */
#define BLOCK_8	8		/* 64KB: C0000 - CFFFF */
#define BLOCK_9	9		/* 64KB: B0000 - BFFFF */
#define BLOCK_10 10		/* 64KB: A0000 - AFFFF */
#define BLOCK_11 11		/* 64KB: 90000 - 9FFFF */
#define BLOCK_12 12		/* 64KB: 80000 - 8FFFF */

/* Data Block Area */
#define BLOCK_A 13		/* 4KB: F000 - FFFF */

/* Defines an array of highest even addresses for each block */
#define DEFINE_ADDR_LOOKUP const unsigned long block_addresses[14] = {0xFFFFE,0xFEFFE,0xFDFFE,0xFBFFE,0xF9FFE,0xF7FFE,0xEFFFE,0xDFFFE,0xCFFFE,0xBFFFE,0xAFFFE,0x9FFFE,0x8FFFE,0xFFFE };

#endif	/* M16C_FLASH == 1 */


/***************************************************************/
/* M16C/26, M16C/26A, M16C/28, M16C/29, M16C/1N2               */
/***************************************************************/
#if (M16C_FLASH == 2)

/* Flash protect bits */
#define EXTRA_PROTECT_BITS 1

/* User Block Area */
#define BLOCK_0 0		/*   8KB: FE000 - FFFFF */
#define BLOCK_1 1		/*   8KB: FC000 - FDFFF */
#define BLOCK_2 2		/*  16KB: F8000 - FBFFF */
#define BLOCK_3 3		/*  32KB: F0000 - F7FFF */
#define BLOCK_4 4		/*  32KB: E8000 - EFFFF */
#define BLOCK_5 5		/*  32KB: E0000 - E7FFF */

/* Data Block Area */
#define BLOCK_A 6		/* 2KB: F800 - FFFF */
#define BLOCK_B 7		/* 2KB: F000 - F7FF */

/* Defines an array of highest even addresses for each block */
#define DEFINE_ADDR_LOOKUP const unsigned long block_addresses[8] = {0xFFFFE,0xFDFFE,0xFBFFE,0xF7FFE,0xEFFFE,0xE7FFE,0xFFFE,0xF7FE };

#endif	/* M16C_FLASH == 2 */


/***************************************************************/
/* M16C/64                                                     */
/***************************************************************/
#if (M16C_FLASH == 3)

/* Flash protect bits */
#define EXTRA_PROTECT_BITS 1

/* User Block Area */
#define BLOCK_0 0		/*  32KB: F0000 - FFFFF */
#define BLOCK_1 1		/*  32KB: E0000 - EFFFF */
#define BLOCK_2 2		/*  32KB: D0000 - DFFFF */
#define BLOCK_3 3		/*  32KB: C0000 - CFFFF */
#define BLOCK_4 4		/*  32KB: B0000 - BFFFF */
#define BLOCK_5 5		/*  32KB: A0000 - AFFFF */
#define BLOCK_6 6		/*  32KB: 90000 - 9FFFF */
#define BLOCK_7 7		/*  32KB: 80000 - 8FFFF */

/* Data Block Area */
#define BLOCK_A 8		/* 4KB: E000 - EFFF */
#define BLOCK_B 9		/* 4KB: F000 - FFFF */

/* Defines an array of highest even addresses for each block */
#define DEFINE_ADDR_LOOKUP const unsigned long block_addresses[10] = {0xFFFFE,0xEFFFE,0xDFFFE,0xCFFFE,0xBFFFE,0xAFFFE,0x9FFFE,0x8FFFE,0xEFFE,0xFFFE };

#endif	/* M16C_FLASH == 2 */


#endif /* _FLASH_API_H (END OF FILE) */
