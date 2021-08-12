@echo off

:: set lib path
set "PATH=%~dp0\lib;%PATH%"

setlocal EnableDelayedExpansion
set "ROOT_DIR=%~dp0"

set MSBUILD_BIN=
set VS_PATH=
set VS_VERSION=
set EXTRA_CMAKE_OPTS=


:: ####  my setting  ################################
set "SOLUTION_DIR64=out"
set VS_VERSION=2019
set "VS_PATH=D:\Program Files (x86)\VisualStudio\2019\Community"
set "MSBUILD_BIN=!VS_PATH!\MSBuild\Current\Bin\MSBuild.exe"
:: ####  my setting  ################################


:argParse
if not "%1" == "" (
    rem cmd.exe mangles -DENABLE_PYTHON=YES into -DENABLE_PYTHON YES,
    rem so it gets split into two arguments
    if "%1" == "-DENABLE_PYTHON" (
        set EXTRA_CMAKE_OPTS=%EXTRA_CMAKE_OPTS% %1=%2
        shift & shift
        goto argParse
    )

    if not "%VS_VERSION%" == "" (
        echo Unexpected argument: "%1"
        goto errorHandling
    )

    if "%1"=="VS2015" (
        set "VS_VERSION=2015"
    ) else if "%1"=="VS2017" (
        set "VS_VERSION=2017"
    ) else if "%1"=="VS2019" (
        set "VS_VERSION=2019"
    ) else (
        echo Unrecognized Visual Studio version specified: "%1"
        echo Supported versions: VS2015, VS2017, VS2019
        goto errorHandling
    )

    shift
    goto argparse
)


if "%PROCESSOR_ARCHITECTURE%" == "AMD64" (
    set "PLATFORM=x64"
) else (
    set "PLATFORM=Win32"
)

if "!MSBUILD_BIN!" == "" (
    if "!VS_VERSION!"=="2015" (
        if exist "C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" (
            set "MSBUILD_BIN=C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
            set "MSBUILD_VERSION=14 2015"
        )
    ) else if "!VS_VERSION!"=="2017" (
        if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin\MSBuild.exe" (
            set "MSBUILD_BIN=C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin\MSBuild.exe"
            set "MSBUILD_VERSION=15 2017"
        ) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\MSBuild.exe" (
            set "MSBUILD_BIN=C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\MSBuild.exe"
            set "MSBUILD_VERSION=15 2017"
        ) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" (
            set "MSBUILD_BIN=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe"
            set "MSBUILD_VERSION=15 2017"
        )
    )
) else (
    if not "!MSBUILD_BIN:2019=!"=="!MSBUILD_BIN!" set "MSBUILD_VERSION=16 2019"
    if not "!MSBUILD_BIN:2017=!"=="!MSBUILD_BIN!" set "MSBUILD_VERSION=15 2017"
    if not "!MSBUILD_BIN:2015=!"=="!MSBUILD_BIN!" set "MSBUILD_VERSION=14 2015"
)

if "!MSBUILD_BIN!" == "" (
    echo Build tools for Microsoft Visual Studio !VS_VERSION! cannot be found. If you use Visual Studio 2017, please download and install build tools from https://www.visualstudio.com/downloads/#build-tools-for-visual-studio-2017
    goto errorHandling
)




if exist "%SOLUTION_DIR64%\CMakeCache.txt" del "%SOLUTION_DIR64%\CMakeCache.txt"

echo Creating Visual Studio %MSBUILD_VERSION% %PLATFORM% files in %SOLUTION_DIR64%... && ^
cd "%ROOT_DIR%" && cmake -E make_directory "%SOLUTION_DIR64%"

cd "%SOLUTION_DIR64%" && cmake -G "Visual Studio !MSBUILD_VERSION!" -A %PLATFORM% "%ROOT_DIR%"

echo EXTRA_CMAKE_OPTS %EXTRA_CMAKE_OPTS%

echo.
echo ###############^|^| Build Inference Engine dll_sample using MS Visual Studio (MSBuild.exe) ^|^|###############
echo.
echo "!MSBUILD_BIN!" dll_sample.sln /p:Configuration=Release
"!MSBUILD_BIN!" dll_sample.sln /p:Configuration=Release
if ERRORLEVEL 1 goto errorHandling

echo Done.
goto :eof

:errorHandling
echo Error
exit /B 1
