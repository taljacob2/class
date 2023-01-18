$PATH_TO_VISUAL_STUDIO="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE"

$vcvars64="$PATH_TO_VISUAL_STUDIO\..\..\VC\Auxiliary\Build\vcvars64.bat"

$cl64="$PATH_TO_VISUAL_STUDIO\..\..\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe"

# --------------------------------

$LIBRARY_NAME="Object"

& $vcvars64

Get-ChildItem -Path .\ -Filter *.c -File -Name | ForEach-Object {

    # Compile .c to .obj.
    & $cl64 /c "$_"

    Write-Output "$_"
}

