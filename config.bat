@echo off
CALL %*

REM ---------------------------------- Code ------------------------------------

REM       ------------ Visual Studio Environment Variables ------------

REM SET PATH_TO_VISUAL_STUDIO=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE
SET PATH_TO_VISUAL_STUDIO=D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE

SET vcvars64=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars64.bat
SET vcvars32=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars32.bat

SET TOOLS_BASE_PATH=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Tools\MSVC\*
SET cl64=\bin\Hostx64\x64\cl.exe
SET cl32=\bin\Hostx86\x86\cl.exe
SET lib64=\bin\Hostx64\x64\lib.exe
SET lib32=\bin\Hostx86\x86\lib.exe
SET link64=\bin\Hostx64\x64\link.exe
SET link32=\bin\Hostx86\x86\link.exe

REM       ----------------------- Path Variables ----------------------

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
SET ROOT_PATH=!ROOT_PATH!

REM DEBUG
echo %ROOT_PATH%

SET SRC_PATH=%ROOT_PATH%\src

REM DEBUG
echo %SRC_PATH%

SET MAIN_PATH=%SRC_PATH%\main
SET TEST_PATH=%SRC_PATH%\test
SET LIB_PATH=%SRC_PATH%\lib
SET OUTPUT_LIB_PATH=%LIB_PATH%\oop

SET OUTPUT_LIB_FILE_NAME=oop

REM -------------------------------- Code End ----------------------------------

GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:RunCl
    for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%cl64%" %~1
GOTO :EOF

:RunLib
    for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%lib64%" %~1
GOTO :EOF

:RunLink
    for /D %%I in ("%TOOLS_BASE_PATH%") do "%%~I%link64%" %~1
GOTO :EOF
