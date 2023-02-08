@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=config.bat %1
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET OOP_DIRECTORY=%MSVC_DIRECTORY%/%OUTPUT_LIB_FILE_NAME_PURE_CONST%

echo releasing msvc...

CALL :CleanupAndPrepareDirectory

REM Build the static library.
CALL build-lib.bat
CALL build-lib.bat 32

CALL :CopyHeaderFilesAndStaticLibrary

@REM REM Cleanup the static library build.
@REM CALL cleanup.bat

CALL :ArchiveStaticLibrary

echo done.


del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CleanupAndPrepareDirectory

    REM Cleaup last release.
    rmdir /S/Q "%MSVC_DIRECTORY%" >NUL 2>&1

    REM Make sure there is an empty directory for the relaese.
    if not exist "%OOP_DIRECTORY%" ( 
        mkdir "%OOP_DIRECTORY%"
    )
GOTO :EOF

:CopyHeaderFilesAndStaticLibrary
    xcopy /Y /E "%OUTPUT_LIB_PATH%\%OUTPUT_LIB_FILE_NAME_64_BIT_CONST%.lib" "%OOP_DIRECTORY%" >NUL 2>&1
    xcopy /Y /E "%OUTPUT_LIB_PATH%\%OUTPUT_LIB_FILE_NAME_32_BIT_CONST%.lib" "%OOP_DIRECTORY%" >NUL 2>&1
    xcopy /Y /E "%OUTPUT_LIB_PATH%\*.h" "%OOP_DIRECTORY%" >NUL 2>&1
    xcopy /Y /E "%OUTPUT_LIB_PATH%\*.r" "%OOP_DIRECTORY%" >NUL 2>&1
GOTO :EOF

:ArchiveStaticLibrary
    for /f %%i in ('cd') do (
        SET THIS_PATH=%%i
    )

    REM Zip `OOP_DIRECTORY`.
    REM Starting windows 10 build 17063, you can use TAR.
    cd "%MSVC_DIRECTORY%"
    tar -cf "%MSVC_RELEASE_NAME%" "%OUTPUT_LIB_FILE_NAME%"
    cd "%THIS_PATH%"    
GOTO :EOF
