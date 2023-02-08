@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=../../../../config.bat %1
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=AnonymousObject

CALL :CompileAllCFilesInCurrentDirectory
CALL :LibAllObjFilesInCurrentDirectory

REM Cleanup temp files.
del /F *.obj >NUL 2>&1
del /F *.idb >NUL 2>&1

del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
    CALL %CONFIG% :RunCl "/c /I%LIBRARY_NAME%.h *.c"
GOTO :EOF

:LibAllObjFilesInCurrentDirectory
    CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib *.obj"
GOTO :EOF
