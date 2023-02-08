@echo off

REM ---------------------------------- Code ------------------------------------

REM       ------------ Visual Studio Environment Variables ------------

REM               --------- START: Edit to your liking ---------

REM SET PATH_TO_VISUAL_STUDIO=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE
SET PATH_TO_VISUAL_STUDIO=D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE

REM Comment out the following line, to set it to RELEASE Mode. Else, DEBUG Mode Will be set.
REM SET IS_DEBUG_MODE=.

REM               --------- END: Edit to your liking ---------

SET vcvars64=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars64.bat
SET vcvars32=%PATH_TO_VISUAL_STUDIO%\..\..\VC\Auxiliary\Build\vcvars32.bat

if defined IS_DEBUG_MODE (
    SET clOptions=^
    /JMC /permissive- /GS /W3 /Zc:wchar_t ^
    /ZI /Gm- /Od /sdl ^
    /Zc:inline /fp:precise ^
    /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt ^
    /WX- /Zc:forScope /RTC1 /Gd /MDd /FC /EHsc /nologo /diagnostics:column
) else (
    SET clOptions=^
    /permissive- /GS /GL /W3 /Gy /Zc:wchar_t /Zi ^
    /Gm- /O2 /sdl /Zc:inline /fp:precise ^
    /D "NDEBUG" /D "_CONSOLE" /D "_WINDLL" /D "_UNICODE" /D "UNICODE" ^
    /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /MD /FC ^
    /EHsc /nologo ^
    /diagnostics:column
)

REM       ----------------------- Path Variables ----------------------

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM Export `%*` with a `shift` of `1` to `%argv%`.
CALL :SetArgv 2 %*

REM TODO: DEBUG PRINT
echo %argv%
echo %*
echo %1

SET OUTPUT_LIB_FILE_NAME_PURE_CONST=oop
SET OUTPUT_LIB_FILE_NAME_64_BIT_CONST=%OUTPUT_LIB_FILE_NAME_PURE_CONST%
SET OUTPUT_LIB_FILE_NAME_32_BIT_CONST=%OUTPUT_LIB_FILE_NAME_PURE_CONST%32

CALL :GetParametersRaw %1

if "%BITS%"=="32" (
    SET vcvars=%vcvars32%
) else (
    SET vcvars=%vcvars64%
)
CALL "%vcvars%" >NUL 2>&1

SET MSVC_DIRECTORY=release/msvc
SET MSVC_RELEASE_NAME=%OUTPUT_LIB_FILE_NAME_PURE_CONST%-msvc.zip
SET MSVC_RELEASE_PATH=%MSVC_DIRECTORY%/%MSVC_RELEASE_NAME%

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

echo argv %argv%
CALL %argv%

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

:GetParametersRaw

    REM Default is 64 bit. Thus, set `BITS` value to `64` by default.
    SET BITS=64
    SET OUTPUT_LIB_FILE_NAME=%OUTPUT_LIB_FILE_NAME_64_BIT_CONST%
    :GetOptionParametersLoop
    IF NOT "%1"=="" (
        IF "%1"=="32" (

            REM Optional. Defaults to `64`.
            REM A literal text. May be `32` or `64`.
            SET BITS=32
            SET OUTPUT_LIB_FILE_NAME=%OUTPUT_LIB_FILE_NAME_32_BIT_CONST%
            SHIFT
        )
        IF "%1"=="64" (

            REM Optional. Defaults to `64`.
            SHIFT
        )

        SHIFT
        GOTO :GetOptionParametersLoop
    )
GOTO :EOF

:SetArgv
    REM Stores the given arguments to an output variable (i.e. `%argv%`), so you
    REM would be able to shift them as you like.
    REM
    REM - The result is stored into the `%argv%` variable.
    REM - The count of `%argv%` is stored into the `%argc%` variable.
    REM
    REM - In case `%1` was non-numeric:
    REM   `%argv%` is SET to `%*`.
    REM - In case `%1` was numeric:
    REM   `%argv%` is SET to be all the arguments to the right of it.
    REM   (i.e. `%*` with a shift of `1`.)
    REM
    REM ## Usage Examples:
    REM
    REM - Begin parsing the arguments from `%1`:
    REM   ```
    REM   CALL :SetArgv 1 hello world
    REM   ```
    REM   REM `%argv%` is `hello world`
    REM   REM `%argc%` is `2`
    REM
    REM - Begin parsing the arguments from `%2`:
    REM   ```
    REM   CALL :SetArgv 2 hello world
    REM   ```
    REM   REM `%argv%` is `world`
    REM   REM `%argc%` is `1`
    REM   REM (same as calling `shift`)
    REM
    REM - Begin parsing the arguments from `%1`:
    REM   ```
    REM   CALL :SetArgv hello world
    REM   ```
    REM   REM `%argv%` is `hello world`
    REM   REM `%argc%` is `2`
    REM
    REM ## After calling `:SetArgv` you would be able to use all of the
    REM    following code examples:
    REM
    REM - View all arguments at once (starts with a leading "space"):
    REM   ```
    REM   echo %argv%
    REM   ```
    REM
    REM - Loop for each argument:
    REM   ```
    REM   for %%a in (%argv%) do (
    REM       echo %%a
    REM   )
    REM   ```
    REM
    REM - View the count of `%argv%` at the `%argc%` variable:
    REM   ```
    REM   echo %argc%
    REM   ```
    REM
    REM ## Program Example
    REM ```
    REM @echo off
    REM SETLOCAL EnableDelayedExpansion
    REM 
    REM CALL :SetArgv %*
    REM echo %argv%
    REM 
    REM GOTO :EOF
    REM ```

    REM See https://stackoverflow.com/a/17584764/14427765
    SET "var="&for /f "delims=0123456789" %%i in ("%1") do SET var=%%i
    if defined var (

        REM echo %1 NOT numeric

        REM Save the result in `%argv%`.
        SET argv=%*
    ) else (

        REM echo %1 numeric

        SET START_ARG_IDX=%1
        
        REM Shift `%*` by `1`, and store in `%allArgsShiftOne%`.
        SET allArgsShiftOne=
        SET /a idx=0
        for %%a in (%*) do (

            REM TODO: DEBUG
            echo aToAdd %%a

            if !idx! geq 1 SET allArgsShiftOne=!allArgsShiftOne! %%a
            SET /a "idx+=1"
        )

        REM TODO: DEBUG
        echo allArgsShiftOne !allArgsShiftOne!
        echo %*

        SET newArgv=
        SET /a idx=0
        for %%a in (!allArgsShiftOne!) do (

            REM TODO: DEBUG
            echo argToAdd %%a

            if !idx! geq !START_ARG_IDX! SET newArgv=!newArgv! %%a
            SET /a "idx+=1"
        )

        REM TODO: DEBUG
        echo newArgvExclamationMark !newArgv!
        echo newArgvPercent %newArgv%

        REM Save the result in `%argv%`.
        SET argv=!newArgv!
    )

    REM Save the count of `%argv%` in `%argc%`.
    SET argc=0
    for %%I in (%argv%) do SET /a "argc+=1"
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
        echo SET OUTPUT_LIB_FILE_NAME_PURE_CONST=%OUTPUT_LIB_FILE_NAME_PURE_CONST%
        echo SET OUTPUT_LIB_FILE_NAME_64_BIT_CONST=%OUTPUT_LIB_FILE_NAME_64_BIT_CONST%
        echo SET OUTPUT_LIB_FILE_NAME_32_BIT_CONST=%OUTPUT_LIB_FILE_NAME_32_BIT_CONST%
        echo SET OUTPUT_LIB_FILE_NAME=%OUTPUT_LIB_FILE_NAME%
        echo SET MSVC_DIRECTORY=%MSVC_DIRECTORY%
        echo SET MSVC_RELEASE_NAME=%MSVC_RELEASE_NAME%
        echo SET MSVC_RELEASE_PATH=%MSVC_RELEASE_PATH%
        echo SET ROOT_PATH=%ROOT_PATH%
        echo SET SRC_PATH=%SRC_PATH%
        echo SET MAIN_PATH=%MAIN_PATH%
        echo SET TEST_PATH=%TEST_PATH%
        echo SET LIB_PATH=%LIB_PATH%
        echo SET OUTPUT_LIB_PATH=%OUTPUT_LIB_PATH%
        echo.
        echo GOTO :EOF
    )
GOTO :EOF
