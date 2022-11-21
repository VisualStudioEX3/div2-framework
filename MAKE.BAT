:: ----------------------------------------------------------------------------
:: BAT command to compile a DLL project and copy to BIN folder.
:: (C) VisualStudioEX3, José Miguel Sánchez Fernández - 2022
:: DIV Games Studio 2 (C) Hammer Technologies - 1998, 1999
:: ----------------------------------------------------------------------------
::
:: Syntax:
:: MAKE.BAT %project_name%
::
:: Set DIV2_DLL_PATH environment variable to setup the DIV Games Studio 2 DLL
:: folder path to able copy the compiled DLL to it.

echo off
cd %1

echo:
echo ^> Compiling %1.DLL...
call MAKE.BAT

echo:
echo ^> Copy %1.DLL to BIN folder...
copy %1.DLL ..\..\BIN\ /y

if "%DIV2_DLL_PATH%"=="" goto clean_folder else goto copy_to_div2_dll_folder

:copy_to_div2_dll_folder
echo:
echo ^> Copy %1.DLL to DIV Games Studio 2 DLL folder (%DIV2_DLL_PATH%)...
copy %1.DLL %DIV2_DLL_PATH% /y

:clean_folder
echo:
echo ^> Clean %1 project folder...
if exist *.dll del /f /q *.dll
if exist *.obj del /f /q *.obj
if exist *.err del /f /q *.err

cd ..

echo --------------------------------------------------------------------------------

echo off
