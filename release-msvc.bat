@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET MSVC_DIRECTORY=release/msvc
SET OOP_DIRECTORY=%MSVC_DIRECTORY%/%OUTPUT_LIB_FILE_NAME%

echo releasing msvc...

CALL :CleanupAndPrepareDirectory

REM Build the static library.
CALL build-lib.bat

CALL :CopyHeaderFilesAndStaticLibrary

@REM REM Cleanup the static library build.
@REM CALL cleanup.bat

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
    xcopy /Y /E "%OUTPUT_LIB_PATH%\%OUTPUT_LIB_FILE_NAME%.lib" "%OOP_DIRECTORY%" >NUL 2>&1
    xcopy /Y /E "%OUTPUT_LIB_PATH%\*.h" "%OOP_DIRECTORY%" >NUL 2>&1
    xcopy /Y /E "%OUTPUT_LIB_PATH%\*.r" "%OOP_DIRECTORY%" >NUL 2>&1
GOTO :EOF
