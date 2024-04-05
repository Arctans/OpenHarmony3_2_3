@echo off
@title update firmware : kernel

SET root_dir=%~dp0
start %root_dir%\cfg\download.bat kernel

::延时10秒退出
timeout /T %sleep_time_s% /NOBREAK