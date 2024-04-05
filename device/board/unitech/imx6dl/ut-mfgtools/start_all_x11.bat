@echo off
@title update firmware : all_x11

SET root_dir=%~dp0
start %root_dir%\cfg\download.bat all_x11

::延时10秒退出
timeout /T %sleep_time_s% /NOBREAK