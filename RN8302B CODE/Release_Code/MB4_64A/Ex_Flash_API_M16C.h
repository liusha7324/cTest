#ifndef _EX_FLASH_API_H
#define _EX_FLASH_API_H

#include "Flash_API_M16C.h"

extern unsigned char FlashEraseEW1( unsigned char block );
extern unsigned char FlashWriteEW1(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes);
extern unsigned char FlashReadEW1(	FLASH_PTR_TYPE flash_addr,
							BUF_PTR_TYPE buffer_addr,
							unsigned int bytes);
#endif