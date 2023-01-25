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

@REM CALL release.bat

CALL :GetParametersRaw

CALL :AssertAndDefaultParameters


@REM curl ^
@REM   -X POST ^
@REM   -H "Accept: application/vnd.github+json" ^
@REM   -H "Authorization: Bearer %token%" ^
@REM   -H "X-GitHub-Api-Version: 2022-11-28" ^
@REM   https://api.github.com/repos/taljacob2/oop/releases ^
@REM   -d '{"tag_name":"v1.0.0","target_commitish":"master","name":"v1.0.0","body":"Description of the release","draft":false,"prerelease":false,"generate_release_notes":false}'



del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:GetParametersRaw
    :GetOptionParametersLoop
    IF NOT "%1"=="" (
        IF "%1"=="-token" (

            REM Required.
            REM A literal text. A GitHub token with a "push" access to the repository.
            SET token=%2
            SHIFT
        )
        IF "%1"=="-tagname" (

            REM Required.
            REM A literal text, that resembles an existing "tag" name to publish the release from.
            SET tagname=%2
            SHIFT
        )
        IF "%1"=="-name" (

            REM Optional. Defaults to `-tagname`'s value.
            REM A string, that will set the name of the release.
            SET name=%2
            SHIFT
        )
        IF "%1"=="-prerelease" (

            REM Optional. Defaults to `true`.
            REM A literal text. May be `true` or `false`.
            SET prerelease=%2
            SHIFT
        )

        SHIFT
        GOTO :GetOptionParametersLoop
    )
GOTO :EOF

:AssertAndDefaultParameters

    REM Assert `-token` parameter.
    if not defined token (

        REM Quit script with an errorlevel.
        echo ERROR: Missing "token" parameter. Please pass a GitHub token and try again. Do it like so: "-token <YOUR-TOKEN>".
        exit /b 1
    )

    REM Assert `-tagname` parameter.
    if not defined tagname (

        REM Quit script with an errorlevel.
        echo ERROR: Missing "tagname" parameter. Please pass an existing "tag" name and try again. Do it like so: "-tagname <EXISTING-TAG-NAME>".
        exit /b 2
    )

    REM Default `-name` parameter to `-tagname`'s value converted to string.
    if not defined name (
        SET name="%tagname%"
    )

    REM Default `-prerelease` parameter to `true`.
    if not defined prerelease (
        SET prerelease=true
    )
GOTO :EOF