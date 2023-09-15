@echo off

::setting arguments as variables
set backup_source_dir=%1
set backup_dest_dir=%2

set logfile=%backup_dest_dir%\events.log

::moving to source directory

cd %backup_source_dir%

7z u -y %backup_dest_dir%\data.7z * >> %logfile%
