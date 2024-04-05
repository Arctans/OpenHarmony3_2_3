@echo off
@title update firmware : rootfs_eglfs

SET root_dir=%~dp0
start %root_dir%\cfg\download.bat rootfs_eglfs

::延时10秒退出
timeout /T %sleep_time_s% /NOBREAK