@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

CALL %CONFIG% :RunCl "^
/Fe:%MAIN_PATH%\main.exe ^
%MAIN_PATH%\main.c ^
%MAIN_PATH%\Circle.c ^
%MAIN_PATH%\CircleV2.c ^
%MAIN_PATH%\CircleV3.c ^
%MAIN_PATH%\CircleV4.c ^
%MAIN_PATH%\CircleV5.c ^
%MAIN_PATH%\CircleV6.c ^
%MAIN_PATH%\CircleV7.c ^
%MAIN_PATH%\CircleV8.c ^
%OUTPUT_LIB_PATH%\%OUTPUT_LIB_FILE_NAME%.lib ^
"


del /F shared-config-local-variables.bat
GOTO :EOF
