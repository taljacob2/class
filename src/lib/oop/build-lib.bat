@echo off

SETLOCAL

REM IMPORT
SET CONFIG=../../../config.bat
CALL %CONFIG%

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=%OUTPUT_LIB_FILE_NAME%

@REM CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib dir /s/b *.lib"

REM See https://stackoverflow.com/a/2423969/14427765
REM See https://www.geeksforgeeks.org/batch-script-iterating-over-an-array/

REM Initialize with nothing.
SET subLibList=

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

for /f %%f in ('dir /s/b/a:d') do (
	cd "%%f"

    REM See https://stackoverflow.com/a/57802962/14427765
    for /f %%i in ('dir /b ^| findstr /e .lib') do (
        SET SUB_LIB_NAME=%%i
    )
    REM DEBUG    
    echo !SUB_LIB_NAME!

	cd ..

    @REM REM add `%%f%/%SUB_LIB_NAME%` to `subLibList`. Notice the preceeding `' '`.
    @REM SET subLibList=%subLibList% %%f\!SUB_LIB_NAME!
    @REM @REM SET subLibList=hey

    @REM REM DEBUG
    @REM echo !subLibList!
)


@REM REM DEBUG
@REM echo %subLibList%

@REM CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib %subLibList%"