@echo off
@title copy sth to current filepath
mode con lines=23 cols=100

set mode=%1%  

::�˳��ӳ�ʱ��
SET sleep_time_s=10
::�쳣�˳���ʶ
set file_error_exit=0
set work_mode=0
set fs_type=0

SET temp_root_dir=%~dp0
SET root_dir=%temp_root_dir%..\
SET tool_dir=%root_dir%mfgtools

::����Դ�ļ�
SET firmware_src_dir=%root_dir%firmware\
SET firmware_src_boot=%firmware_src_dir%u-boot.imx
SET firmware_src_dtb=%firmware_src_dir%imx6dl-sabresd.dtb
SET firmware_src_rootfs_base=%firmware_src_dir%imx6dl_emmc_rootfs.ext4
SET firmware_src_rootfs_x11=%firmware_src_dir%imx6dl_emmc_rootfs_x11.ext4
SET firmware_src_rootfs_eglfs=%firmware_src_dir%imx6dl_emmc_rootfs_eglfs.ext4
SET firmware_src_zImage=%firmware_src_dir%zImage

::����Ŀ���ļ�
SET firmware_dst_dir=%tool_dir%\Profiles\Linux\OS Firmware\firmware
SET firmware_dst_boot=%firmware_dst_dir%\u-boot.imx
SET firmware_dst_dtb=%firmware_dst_dir%\imx6dl-sabresd.dtb
SET firmware_dst_rootfs=%firmware_dst_dir%\
SET firmware_dst_zImage=%firmware_dst_dir%\zImage

::�ж���θ���
for %%a in (%*) do set /a para_num+=1
::������
call:func_main

::����������
:func_main
::��ȡ��������ģʽ
call:func_get_mode
::������ģʽ����ļ�
call:func_check_firmware
::����Ƿ�ִ�д����˳�
call:func_check_err_exit
::������������
call:func_start_app
::��ʱ�˳�
call:func_sleep
exit

::������ģʽ����ļ���������
:func_check_firmware
if %work_mode% equ 0 (
	call:func_check_boot
	call:func_check_dtb
	call:func_check_kernel

	if %fs_type% equ 0 (
		call:func_check_rootfs_base
	)else if %fs_type% equ 1 (
		call:func_check_rootfs_x11
	) else if %fs_type% equ 2 (
		call:func_check_rootfs_eglfs
	)
) else if %work_mode% equ 1 (
	call:func_check_boot
) else if %work_mode% equ 2 (
	call:func_check_dtb
) else if %work_mode% equ 3 (
	call:func_check_kernel	
) else if %work_mode% equ 4 (
	if %fs_type% equ 0 (
		call:func_check_rootfs_base
	)else if %fs_type% equ 1 (
		call:func_check_rootfs_x11
	) else if %fs_type% equ 2 (
		call:func_check_rootfs_eglfs
	)
)
goto:eof

::�����˳���������
:func_check_err_exit
if %file_error_exit% equ 1 (
	call:func_sleep
	exit
)
goto:eof

::���uboot�ļ���������
:func_check_boot
if not exist %firmware_src_boot% (	
	echo "ȱ���ļ�:%firmware_src_boot%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_boot%" "%firmware_dst_boot%" /y
)
goto:eof

::���dtb�ļ���������
:func_check_dtb
if not exist %firmware_src_dtb% (	
	echo "ȱ���ļ�:%firmware_src_dtb%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_dtb%" "%firmware_dst_dtb%" /y
)
goto:eof

::���rootfs(base)�ļ���������
:func_check_rootfs_base
if not exist %firmware_src_rootfs_base% (
	echo "ȱ���ļ�:%firmware_src_rootfs_base%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_rootfs_base%" "%firmware_dst_rootfs%" /y
)
goto:eof

::���rootfs(x11)�ļ���������
:func_check_rootfs_x11
if not exist %firmware_src_rootfs_x11% (
	echo "ȱ���ļ�:%firmware_src_rootfs_x11%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_rootfs_x11%" "%firmware_dst_rootfs%" /y
)
goto:eof

::���rootfs(eglfs)�ļ���������
:func_check_rootfs_eglfs
if not exist %firmware_src_rootfs_eglfs% (
	echo "ȱ���ļ�:%firmware_src_rootfs_eglfs%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_rootfs_eglfs%" "%firmware_dst_rootfs%" /y
)
goto:eof

::���kernel�ļ���������
:func_check_kernel
if not exist %firmware_src_zImage% (
	echo "ȱ���ļ�:%firmware_src_zImage%"
	set /a file_error_exit=1
) else (	
	echo f | xcopy  "%firmware_src_zImage%" "%firmware_dst_zImage%" /y
)
goto:eof

::��ȡ��������ģʽ��������
:func_get_mode
if defined para_num (
	echo ������ %para_num% ������
	echo ===%mode%
	echo %mode%| findstr "uboot" >nul && (
		echo uboot����
		set work_mode=1
		goto:eof
	)
	
	echo %mode%| findstr "dtb" >nul && (
		echo dtb����
		set work_mode=2
		goto:eof
	)
	
	echo %mode%| findstr "kernel" >nul && (
		echo kernel����
		set work_mode=3
		goto:eof
	)
	
	echo %mode%| findstr "rootfs_base" >nul && (
		echo rootfs_base����
		set work_mode=4
		goto:eof
	)
	
	echo %mode%| findstr "rootfs_x11" >nul && (
		echo rootfs_x11����
		set work_mode=4
		set fs_type=1
		goto:eof
	)
	
	echo %mode%| findstr "rootfs_eglfs" >nul && (
		echo rootfs_eglfs����
		set work_mode=4
		set fs_type=2
		goto:eof
	)
	
	echo %mode%| findstr "all_base" >nul && (
		echo ȫ��rootfs_base����
		set work_mode=0
		goto:eof
	)
	
	echo %mode%| findstr "all_x11" >nul && (
		echo ȫ��rootfs_x11����
		set work_mode=0
		set fs_type=1
		goto:eof
	)
	
	echo %mode%| findstr "all_eglfs" >nul && (
		echo ȫ��rootfs_eglfs����
		set work_mode=0
		set fs_type=2
		goto:eof
	)
) else (
	echo ȫ��rootfs_base����
	set work_mode=0
)
goto:eof

::������������������
:func_start_app
tasklist |findstr /i "MfgTool"
if %errorlevel%==0 (
	taskkill /f /im MfgTool2.exe
)
::else (
::	echo no find MfgTool task
::)  

echo "MfgTool starting..."

if %work_mode% equ 0 (
	if %fs_type% equ 0 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-all-base" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	)else if %fs_type% equ 1 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-all-x11" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	) else if %fs_type% equ 2 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-all-eglfs" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	)
) else if %work_mode% equ 1 (
	start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-Boot" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
) else if %work_mode% equ 2 (
	start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-Dtb" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
) else if %work_mode% equ 3 (
	start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-Kernel" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
) else if %work_mode% equ 4 (
	if %fs_type% equ 0 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-rootfs-base" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	)else if %fs_type% equ 1 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-rootfs-x11" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	) else if %fs_type% equ 2 (
		start %tool_dir%\mfgtool2.exe -c "linux" -l "eMMC-rootfs-eglfs" -s "board=sabresd" -s "sxdtb=sdb" -s "mmc=2"
	)
)
goto:eof

::��ʱ��������
:func_sleep
::��ʱ10���˳�
timeout /T %sleep_time_s% /NOBREAK
goto:eof