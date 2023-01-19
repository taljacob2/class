@echo off

SETLOCAL

REM IMPORT
SET CONFIG=../../../../config.bat
CALL %CONFIG%

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME="Object"

CALL :CompileAllCFilesInCurrentDirectory
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
    CALL "%vcvars64%"
    for %%f in (*.c) do (
        CALL %CONFIG% :RunCl "/c %%f"
    )
GOTO :EOF
