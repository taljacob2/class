@echo off

REM ---------------------------------- Code ------------------------------------

REM       ------------ Visual Studio Environment Variables ------------

REM               --------- START: Edit to you liking ---------

REM SET PATH_TO_VISUAL_STUDIO=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE
SET PATH_TO_VISUAL_STUDIO=D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE

REM Comment out the following line, to set it to 32 bits. Else, 64 will be set.
SET IS_USER_MACHINE_64_BIT=.

REM               --------- END: Edit to you liking ---------

SET vcvars64=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars64.bat
SET vcvars32=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars32.bat

if defined IS_USER_MACHINE_64_BIT (
    SET vcvars=%vcvars64%
) else (
    SET vcvars=%vcvars32%
)

REM       ----------------------- Path Variables ----------------------

SET OUTPUT_LIB_FILE_NAME=oop

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM See https://stackoverflow.com/a/57802962/14427765
for /f %%i in ('cd') do (
    SET ROOT_PATH=%%i
)

SET SRC_PATH=%ROOT_PATH%\src
SET MAIN_PATH=%SRC_PATH%\main
SET TEST_PATH=%SRC_PATH%\test
SET LIB_PATH=%SRC_PATH%\lib
SET OUTPUT_LIB_PATH=%LIB_PATH%\oop

REM -------------------------------- Code End ----------------------------------

CALL %*

CALL :SetLocalVariablesAsGlobal

GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:RunCl
    @REM for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%cl%" %~1
    cl %~1
GOTO :EOF

:RunLib
    @REM for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%lib%" %~1
    lib %~1
GOTO :EOF

:RunLink
    @REM for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%link%" %~1
    link %~1
GOTO :EOF

:SetLocalVariablesAsGlobal
    REM Writes the local variables to an external batch file.
    REM The user should `CALL %FILE_NAME%` to use the external batch file.
    REM
    REM See https://superuser.com/a/1389294
    REM See https://www.tutorialspoint.com/batch_script/batch_script_appending_files.htm

    SET FILE_NAME=shared-config-local-variables.bat

    echo @echo off> %FILE_NAME%
    echo.>> %FILE_NAME%
    echo SET ROOT_PATH=%ROOT_PATH%>> %FILE_NAME%
    echo SET SRC_PATH=%SRC_PATH%>> %FILE_NAME%
    echo SET MAIN_PATH=%MAIN_PATH%>> %FILE_NAME%
    echo SET TEST_PATH=%TEST_PATH%>> %FILE_NAME%
    echo SET LIB_PATH=%LIB_PATH%>> %FILE_NAME%
    echo SET OUTPUT_LIB_PATH=%OUTPUT_LIB_PATH%>> %FILE_NAME%
    echo.>> %FILE_NAME%
    echo CALL "%vcvars%">> %FILE_NAME%
    echo.>> %FILE_NAME%
    echo GOTO :EOF>> %FILE_NAME%
GOTO :EOF
