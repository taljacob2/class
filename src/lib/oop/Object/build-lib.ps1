# $PATH_TO_VISUAL_STUDIO="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE"
$PATH_TO_VISUAL_STUDIO="D:\Tal\Visual Studio - Community 2019\IDE - Installation\Common7\IDE"

$vcvars64=$(Get-ChildItem "$PATH_TO_VISUAL_STUDIO\..\..\VC\Auxiliary\Build\vcvars64.bat")
$vcvars32=$(Get-ChildItem "$PATH_TO_VISUAL_STUDIO\..\..\VC\Auxiliary\Build\vcvars32.bat")

$cl64=$(Get-ChildItem "$PATH_TO_VISUAL_STUDIO\..\..\VC\Tools\MSVC\*\bin\Hostx64\x64\cl.exe")
$cl32=$(Get-ChildItem "$PATH_TO_VISUAL_STUDIO\..\..\VC\Tools\MSVC\*\bin\Hostx86\x86\cl.exe")

# --------------------------------

$LIBRARY_NAME="Object"

& $vcvars64

Get-ChildItem -Path .\ -Filter *.c -File -Name | ForEach-Object {

    # Compile .c to .obj.
    & $cl64 /c "$_"
}

