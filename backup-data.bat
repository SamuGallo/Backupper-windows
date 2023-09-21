@echo off

::setting arguments as variables
set backup_source_dir=%1
set backup_dest_dir=%2

set logfile=%backup_dest_dir%\events.log

echo on

robocopy %backup_source_dir% %backup_dest_dir%\data  /MIR /LOG+:%logfile% /tee /COPY:DAT

