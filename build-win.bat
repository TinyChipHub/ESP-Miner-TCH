@echo off
setlocal EnableExtensions EnableDelayedExpansion

set VERSION=%1
set CURDIR=%CD%
echo ***************************************
echo *                                     *
echo Building BIN files for version: %VERSION%
echo *                                     *
echo ***************************************
echo `

echo Current DIR: %CURDIR%
if exist ".\bin" GOTO steptwo
echo `
echo -----------------------------------------
echo --------Creating bin files folder--------
echo -----------------------------------------
mkdir %CURDIR%\bin

:steptwo
echo `
echo -----------------------------------
echo --------Building config.bin--------
echo -----------------------------------
echo `
for %%F in (config-*.cvs) do (
    set "CFG_NAME=%%~nF"
    set "CFG_NUM=!CFG_NAME:config-=!"
    echo Building config.bin for board !CFG_NUM!
    python.exe C:\esp\v6.0.2\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate "%%F" ".\build\!CFG_NAME!.bin" 0x6000
)





echo `
echo -----------------------------------
echo --------Building factory.bin-------
echo -----------------------------------
echo `

for %%F in (config-*.cvs) do (
    set "CFG_NAME=%%~nF"
    set "CFG_NUM=!CFG_NAME:config-=!"
    echo Building factory.bin for board !CFG_NUM!
    esptool.exe --chip esp32s3 merge-bin --flash-mode dio --flash-size 16MB --flash-freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 ".\build\!CFG_NAME!.bin" 0x10000 build/esp-miner.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-!CFG_NUM!.bin"
)



xcopy "%CURDIR%\build\esp-miner.bin" "%CURDIR%\bin" /Y
if exist "%CURDIR%\build\www.bin" xcopy "%CURDIR%\build\www.bin" "%CURDIR%\bin" /Y