@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=../../../../config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=Atomic

CALL :CompileAllCFilesInCurrentDirectory
CALL :LibAllObjFilesInCurrentDirectory

REM Cleanup temp files.
del /F *.obj
del /F *.idb
del /F *.pdb

del /F shared-config-local-variables.bat
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
    @REM for %%f in (*.c) do (
    @REM     CALL %CONFIG% :RunCl "/c %%f"
    @REM )
    CALL %CONFIG% :RunCl "/I"%LIBRARY_NAME%.h" *.c"
GOTO :EOF

:LibAllObjFilesInCurrentDirectory
    CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib *.obj"
GOTO :EOF
