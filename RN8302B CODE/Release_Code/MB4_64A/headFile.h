/*"
所有的头文件都放在这里,所有的C文件都只引用这个头文件,
所有的头文件都需要加防重复编译机制.
"*/
//--------headFile.h------------

#ifndef HEAD_FILE_H
#define HEAD_FILE_H

#include "defdata.h"
#include "initcpu.h"
#include "initram.h"
#include "interrupt.h"
#include "seg.h" 
#include "multi.h"
#include "comm.h"
#include "freeze.h"
#include "eeprom.h"
#include "showcfg.h"
#include "645Data.h"
#include "Demand.h"
#include "645_2007.h"
#include "LoadRecord.h"
#include "File_System.h"
#include "MB_Keymain.h"
#include "MB_Showmain.h"
#include "I2C_operation.h"
#include "Measure_Interface.h" 
#include "att7022_operation.h"
#include "datachange.h"

#include <math.h>
#include <float.h>

//payment
#include "ICcard.h"
#include "pay_def.h"
#include "Card_File.h"
#include "Pay_For_Fun.h"
#include "Cpucard_Driver.h"
#include "Far_pay.h"
#include "Ex_Card_Data.h"
#include "Ex_Cpucard_Driver.h"
#include "Ex_Pay_For_Fun.h"

#endif

