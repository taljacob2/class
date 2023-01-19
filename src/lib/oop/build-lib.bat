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

for /f %%f in ('dir /s/b/a:d') do (

    REM Initialize with nothing.
    SET SUB_LIB_NAME=""

    @REM @REM REM DEBUG
    @REM echo %%f

	cd "%%f"

    @REM REM DEBUG
    @REM cd

    REM DEBUG
    dir /b | findstr /e .lib

    REM See https://stackoverflow.com/a/57802962/14427765
    FOR /F %%i IN ('dir /b ^| findstr /e .lib') DO (
        SET SUB_LIB_NAME=%%i

        REM DEBUG
        echo %SUB_LIB_NAME%
    )
    @REM SET SUB_LIB_NAME='dir /b ^| findstr /e .lib'

    REM DEBUG
    @REM SET SUB_LIB_NAME=dir /b | findstr /e .lib
    @REM echo %SUB_LIB_NAME%
	cd ..

    REM add `%%f%/%SUB_LIB_NAME%` to `subLibList`. Notice the preceeding `' '`.
    @REM SET subLibList=%subLibList% %%f\%SUB_LIB_NAME%
    SET subLibList=hey

    REM DEBUG
    echo %subLibList%
)


@REM REM DEBUG
@REM echo %subLibList%

@REM CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib %subLibList%"