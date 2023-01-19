@echo off

SETLOCAL

REM IMPORT
SET CONFIG=../../../../config.bat
CALL %CONFIG%

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=AnonymousObject

CALL :CompileAllCFilesInCurrentDirectory
CALL :LibAllObjFilesInCurrentDirectory

REM Cleanup *.obj files.
del /F *.obj

GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
    CALL "%vcvars64%"
    for %%f in (*.c) do (
        CALL %CONFIG% :RunCl "/c %%f"
    )
GOTO :EOF

:LibAllObjFilesInCurrentDirectory
    CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib *.obj"
GOTO :EOF
