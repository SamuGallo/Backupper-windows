::creating directory
if not exist "%1\%2" (
    mkdir "%1\%2"
)


:: creating info file

if not exist "%1\%2\backup-info.txt" (copy nul %1\%2\backup-info.txt)

if not exist "%1\%2\events.log" (copy nul %1\%2\events.log)


