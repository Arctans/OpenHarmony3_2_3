@echo off
@title update firmware : dtb

SET root_dir=%~dp0
start %root_dir%\cfg\download.bat dtb

::延时10秒退出
timeout /T %sleep_time_s% /NOBREAK