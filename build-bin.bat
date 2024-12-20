@echo off

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
echo Building config.bin for board 204
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-204.cvs .\build\config-204.bin 0x6000

echo Building config.bin for board 303
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-303.cvs .\build\config-303.bin 0x6000

echo Building config.bin for board 402
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-402.cvs .\build\config-402.bin 0x6000

echo Building config.bin for board 601
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-601.cvs .\build\config-601.bin 0x6000

echo Building config.bin for board 702
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-702.cvs .\build\config-702.bin 0x6000




echo Building config.bin for board 204-office
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-204-office.cvs .\build\config-204-office.bin 0x6000

echo Building config.bin for board 303-office
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-303-office.cvs .\build\config-303-office.bin 0x6000

echo Building config.bin for board 402-office
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-402-office.cvs .\build\config-402-office.bin 0x6000

echo Building config.bin for board 601-office
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-601-office.cvs .\build\config-601-office.bin 0x6000

echo Building config.bin for board 702-office
python.exe D:\esp\v5.3.1\esp-idf\components\nvs_flash\nvs_partition_generator\nvs_partition_gen.py generate .\config-702-office.cvs .\build\config-702-office.bin 0x6000



echo `
echo -----------------------------------
echo --------Building factory.bin-------
echo -----------------------------------
echo `
echo Building factory.bin for board 204
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-204.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-204.bin"

echo Building factory.bin for board 303
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-303.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-303.bin"

echo Building factory.bin for board 402
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-402.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-402.bin"

echo Building factory.bin for board 601
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-601.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-601.bin"

echo Building factory.bin for board 702
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-702.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-702.bin"



echo Building factory.bin for board 204-office
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-204-office.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-204-office.bin"

echo Building factory.bin for board 303-office
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-303-office.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-303-office.bin"

echo Building factory.bin for board 402-office
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-402-office.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-402-office.bin"

echo Building factory.bin for board 601-office
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-601-office.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-601-office.bin"

echo Building factory.bin for board 702-office
esptool.exe --chip esp32s3 merge_bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x9000 build/config-702-office.bin 0x10000 build/esp-miner.bin 0x410000 build/www.bin 0xf10000 build/ota_data_initial.bin -o "bin\esp-miner-factory-%VERSION%-TCH-All-in-one-702-office.bin"

xcopy %CURDIR%\build\esp-miner.bin %CURDIR%\bin /Y
xcopy %CURDIR%\build\www.bin %CURDIR%\bin /Y