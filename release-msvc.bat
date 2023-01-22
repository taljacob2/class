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

echo releasing msvc...

SET OOP_DIRECTORY=release/gcc/%OUTPUT_LIB_FILE_NAME%

CALL :CleanupAndPrepareDirectory

REM Build the static library.
CALL build-lib.bat

CALL :CopyHeaderFilesAndStaticLibrary

echo done.


del /F shared-config-local-variables.bat >NUL 2>&1

REM Instead of `GOTO :EOF` we execute `exit`, so this file would be able to be
REM executed as a thread.
exit

REM ------------------------------- Functions ----------------------------------

:CleanupAndPrepareDirectory

GOTO :EOF

:CopyHeaderFilesAndStaticLibrary

GOTO :EOF
