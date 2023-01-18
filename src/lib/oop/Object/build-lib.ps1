$LIBRARY_NAME="Object"
$cl="D:\Tal\Visual Studio - Community 2019\IDE - Installation\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe"

$vcvars64="D:\Tal\Visual Studio - Community 2019\IDE - Installation\VC\Auxiliary\Build\vcvars64.bat"

& $vcvars64

Get-ChildItem -Path .\ -Filter *.c -File -Name | ForEach-Object {

    # Compile .c to .obj.
    & $cl /c "$_"

    Write-Output "$_"
}

