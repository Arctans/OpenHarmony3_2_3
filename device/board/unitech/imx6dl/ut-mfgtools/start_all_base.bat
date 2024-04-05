@echo off
@title update firmware : all_base

SET root_dir=%~dp0
start %root_dir%\cfg\download.bat all_base

::延时10秒退出
timeout /T %sleep_time_s% /NOBREAK