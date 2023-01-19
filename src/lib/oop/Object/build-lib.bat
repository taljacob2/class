@echo off
SETLOCAL

REM SET PATH_TO_VISUAL_STUDIO=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE
SET PATH_TO_VISUAL_STUDIO=D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE

SET vcvars64=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars64.bat
SET vcvars32=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars32.bat

SET cl_BASE_PATH=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Tools\MSVC\*
SET cl64=\bin\Hostx64\x64\cl.exe
SET cl32=\bin\Hostx86\x86\cl.exe

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME="Object"

CALL :ComipleAllCFilesInCurrentDirectory
EXIT /B %ERRORLEVEL% 

REM ------------------------------- Functions ----------------------------------

:ComipleAllCFilesInCurrentDirectory
for %%f in (*.c) do (
    CALL :RunCl "/c %%f"
)
EXIT /B 0

:RunCl
for /D %%I in ("%cl_BASE_PATH%") do "%%~I%cl64%" %~1
EXIT /B 0
