@echo off

REM ---------------------------------- Code ------------------------------------

REM       ------------ Visual Studio Environment Variables ------------

REM               --------- START: Edit to you liking ---------

REM SET PATH_TO_VISUAL_STUDIO=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE
SET PATH_TO_VISUAL_STUDIO=D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE

REM Comment out the following line, to set it to 32 bits. Else, 64 will be set.
SET IS_USER_MACHINE_64_BIT=.

REM Comment out the following line, to set it to RELEASE Mode. Else, DEBUG Mode Will be set.
SET IS_DEBUG_MODE=.

REM               --------- END: Edit to you liking ---------

SET vcvars64=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars64.bat
SET vcvars32=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars32.bat

if defined IS_USER_MACHINE_64_BIT (
    SET vcvars=%vcvars64%
) else (
    SET vcvars=%vcvars32%
)

if defined IS_DEBUG_MODE (
    SET clOptions=^
    /JMC /permissive- /GS /W3 /Zc:wchar_t ^
    /ZI /Gm- /Od /sdl ^
    /Fd"this.pdb" ^
    /Zc:inline /fp:precise ^
    /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt ^
    /WX- /Zc:forScope /RTC1 /Gd /MDd /FC /EHsc /nologo /diagnostics:column
) else (
    SET clOptions=^
    /permissive- /GS /GL /W3 /Gy /Zc:wchar_t /Z7 ^
    /Gm- /O2 /sdl /Fd"this.pdb" /Zc:inline /fp:precise ^
    /D "NDEBUG" /D "_CONSOLE" /D "_WINDLL" /D "_UNICODE" /D "UNICODE" ^
    /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /MD /FC ^
    /EHsc /nologo ^
    /diagnostics:column
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
    REM See warning levels: https://learn.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=msvc-170
    REM `/W3` is the default warning level for the Visual Studio IDE.
    REM See warning levels of all warning codes: https://learn.microsoft.com/en-us/cpp/preprocessor/compiler-warnings-that-are-off-by-default?view=msvc-170
    REM See All warnings https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-by-compiler-version?view=msvc-170
    REM See All compiler warnings https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-c4800-through-c4999?view=msvc-170
    REM See https://github.com/taljacob2/oop/issues/65

    cl %clOptions% /D "_CRT_SECURE_NO_WARNINGS" %~1
GOTO :EOF

:RunLib
    lib /LTCG /NOLOGO %~1
GOTO :EOF

:RunLink
    link %~1
GOTO :EOF

:SetLocalVariablesAsGlobal
    REM Writes the local variables to an external batch file.
    REM The user should `CALL %FILE_NAME%` to use the external batch file.
    REM
    REM See https://superuser.com/a/1389294
    REM See https://www.tutorialspoint.com/batch_script/batch_script_appending_files.htm
    REM See https://stackoverflow.com/a/14604414/14427765

    SET FILE_NAME=shared-config-local-variables.bat

    >%FILE_NAME% (
        echo @echo off
        echo.
        echo SET ROOT_PATH=%ROOT_PATH%
        echo SET SRC_PATH=%SRC_PATH%
        echo SET MAIN_PATH=%MAIN_PATH%
        echo SET TEST_PATH=%TEST_PATH%
        echo SET LIB_PATH=%LIB_PATH%
        echo SET OUTPUT_LIB_PATH=%OUTPUT_LIB_PATH%
        echo.
        echo CALL "%vcvars%" ^>NUL 2^>^&1
        echo.
        echo GOTO :EOF
    )
GOTO :EOF
