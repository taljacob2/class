@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=config.bat %1
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET RunClArgs=^
/Fe:%TEST_PATH%\main.exe ^
%TEST_PATH%\main.c ^
%OUTPUT_LIB_PATH%\%OUTPUT_LIB_FILE_NAME%.lib

CALL %CONFIG% :RunCl "%RunClArgs%"

REM Cleanup *.obj files.
del /F *.obj

del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF
