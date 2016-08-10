echo Encypt Step 1

rem *************************Set Path**************************************************
set RELEASE_PATH=Release_Code\MB4_64A
set INTERNAL_PATH=Internal_Code\HT7038_Meter\HT7038_Meter


rem *************************Copy HT7038_Meter.c**************************************
copy /y %RELEASE_PATH%\HT7038_Meter.c    %INTERNAL_PATH%\HT7038_Meter.c  

rem *************************Copy Header Files ****************************************
copy /y %RELEASE_PATH%\HT7038_Meter.h     %INTERNAL_PATH%\HT7038_Meter.h  
copy /y %RELEASE_PATH%\defmcro.h           %INTERNAL_PATH%\defmcro.h  
copy /y %RELEASE_PATH%\ram.h                %INTERNAL_PATH%\ram.h  
copy /y %RELEASE_PATH%\interrupt.h          %INTERNAL_PATH%\interrupt.h  
copy /y %RELEASE_PATH%\defdata.h            %INTERNAL_PATH%\defdata.h  
copy /y %RELEASE_PATH%\sfr64a.h            %INTERNAL_PATH%\sfr64a.h 
copy /y %RELEASE_PATH%\Multi.h              %INTERNAL_PATH%\Multi.h  
copy /y %RELEASE_PATH%\Measure_Interface.h  %INTERNAL_PATH%\Measure_Interface.h 
copy /y %RELEASE_PATH%\eventdatadef.h      %INTERNAL_PATH%\eventdatadef.h  
copy /y %RELEASE_PATH%\eventnew.h          %INTERNAL_PATH%\eventnew.h   
copy /y %RELEASE_PATH%\MB_Base_fun.h       %INTERNAL_PATH%\MB_Base_fun.h  