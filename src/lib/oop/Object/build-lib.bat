@echo off

REM IMPORT
CALL ../../../../config.bat

SETLOCAL

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME="Object"

CALL :CompileAllCFilesInCurrentDirectory
EXIT /B %ERRORLEVEL% 

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
CALL "%vcvars64%"
for %%f in (*.c) do (
    CALL :RunCl "/c %%f"
)
EXIT /B 0

:RunCl
for /D %%I in ("%cl_BASE_PATH%") do "%%~I%cl64%" %~1
EXIT /B 0
