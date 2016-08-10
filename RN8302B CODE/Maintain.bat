echo Maintain

rem *************************Set Path**************************************************
set RELEASE_PATH=Release_Code\MB4_64A
set INTERNAL_PATH=Internal_Code\HT7038_Meter\HT7038_Meter

rem *************************Copy Meter Driver to Realse Path**************************
copy /y %INTERNAL_PATH%\HT7038_Meter.c  %RELEASE_PATH%\HT7038_Meter.c 
copy /y %INTERNAL_PATH%\HT7038_Meter.h  %RELEASE_PATH%\HT7038_Meter.h 

rem *************************Delete HT7038_Meter.lib**********************************
@if exist %RELEASE_PATH%\HT7038.lib  del %RELEASE_PATH%\HT7038_Meter.lib