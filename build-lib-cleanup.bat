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

del /S/F %OUTPUT_LIB_PATH%\*.lib
del /S/F %OUTPUT_LIB_PATH%\*.obj
del /S/F shared-config-local-variables.bat

del /F shared-config-local-variables.bat
GOTO :EOF