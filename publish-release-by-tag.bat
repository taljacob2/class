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
@REM SET ERRORLEVEL=0
SET ERRORLEVEL_NoToken=1
SET ERRORLEVEL_NoTagName=2
SET ERRORLEVEL_GetHelp=3


@REM CALL release.bat

CALL :GetParametersRaw %*

if %ERRORLEVEL%==%ERRORLEVEL_GetHelp% (

    REM `:GetHelp` was called. Quit script.
    exit /b %ERRORLEVEL_GetHelp%
)

CALL :AssertAndDefaultParameters

@REM CALL :PushRelease



del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:GetHelp
    echo Pushes an official release to the GitHub repository, so it will be displayed in `https://api.github.com/repos/taljacob2/oop/releases`.
    
    REM Quit script with an errorlevel.
    exit /b %ERRORLEVEL_GetHelp%
GOTO :EOF

:GetParametersRaw    
    :GetOptionParametersLoop
    IF NOT "%1"=="" (
        IF "%1"=="help" (
            CALL :GetHelp

            if %ERRORLEVEL%==%ERRORLEVEL_GetHelp% (

                REM `:GetHelp` was called. Quit script.
                exit /b %ERRORLEVEL_GetHelp%
            )
        )
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
        IF "%1"=="-body" (

            REM Optional. Defaults to an empty string `""`.
            REM A string, that will add a body description to the release.
            SET body=%2
            SHIFT
        )
        IF "%1"=="-draft" (

            REM Optional. Defaults to `false`.
            REM A literal text, that determines if the release will be set as a draft or not.
            SET draft=%2
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
        exit /b %ERRORLEVEL_NoToken%
    )

    REM Assert `-tagname` parameter.
    if not defined tagname (

        REM Quit script with an errorlevel.
        echo ERROR: Missing "tagname" parameter. Please pass an existing "tag" name and try again. Do it like so: "-tagname <EXISTING-TAG-NAME>".
        exit /b %ERRORLEVEL_NoTagName%
    )

    REM Defaults `-name` parameter to `-tagname`'s value converted to string.
    if not defined name (
        SET name="%tagname%"
    )

    REM Defaults `-prerelease` parameter to `true`.
    if not defined prerelease (
        SET prerelease=true
    )

    REM Defaults `-body` parameter to `""`.
    if not defined body (
        SET body=""
    )

    REM Defaults `-draft` parameter to `false`.
    if not defined draft (
        SET draft=false
    )
GOTO :EOF

:PushRelease
    curl ^
      -X POST ^
      -H "Accept: application/vnd.github+json" ^
      -H "Authorization: Bearer %token%" ^
      -H "X-GitHub-Api-Version: 2022-11-28" ^
      https://api.github.com/repos/taljacob2/oop/releases ^
      -d '{"tag_name":"%tagname%","target_commitish":"master","name":"%name%","body":%body%,"draft":%draft%,"prerelease":%prerelease%,"generate_release_notes":true}'
GOTO :EOF
