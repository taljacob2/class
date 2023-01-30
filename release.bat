@REM @echo off

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

REM - Run all threads.
REM - Wait for all threads to finish before continuing.
REM See https://stackoverflow.com/a/33586872/14427765
REM See https://stackoverflow.com/a/56381920/14427765
(
    start /B /I cmd /c release-msvc.bat
    start /B /I wsl -e ./release-gcc.sh
) | SET /P "="


del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF
