echo Encypt Step 2

rem *************************Set Path****************************************************
set RELEASE_PATH=Release_Code\MB4_64A
set INTERNAL_PATH=Internal_Code\HT7038_Meter\HT7038_Meter


rem *************************Copy HT7038_Meter.lib**************************************
copy /y  %INTERNAL_PATH%\Debug\HT7038_Meter.lib    %RELEASE_PATH%\HT7038_Meter.lib 

rem *************************Delete HT7038_Meter.c**************************************
del %RELEASE_PATH%\HT7038_Meter.c

rem *************************Delete Header Files*****************************************

del   %INTERNAL_PATH%\ram.h  
del   %INTERNAL_PATH%\interrupt.h  
del   %INTERNAL_PATH%\defdata.h  
del   %INTERNAL_PATH%\sfr64a.h  
del   %INTERNAL_PATH%\Multi.h  
del   %INTERNAL_PATH%\Initcpu.h  
del   %INTERNAL_PATH%\Measure_Interface.h   
del   %INTERNAL_PATH%\eventnew.h  
del   %INTERNAL_PATH%\MB_Base_fun.h  
del   %INTERNAL_PATH%\eventdatadef.h  


