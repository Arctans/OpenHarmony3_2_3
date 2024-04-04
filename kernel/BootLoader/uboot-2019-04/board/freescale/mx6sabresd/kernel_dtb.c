/******************************************************************************
版权所有   : 优特电力科技股份有限公司
文 件 名   : kernel_dtb.c
版 本 号   : V1.00
作    者   : chenhongsheng
创建日期   : 2023年11月09日
功能描述   : 导入kernel的设备树的函数，该设备树用于uboot自身初始化和内核启动时
其他说明   :
修改记录   :
******************************************************************************/

/*------------------------------- 头文件 ------------------------------------*/
#include <fs.h>
#include <linux/errno.h>
#include <stdio.h>
#include <fdtdec.h>
#include <common.h>
#include <linux/libfdt.h>

/*------------------------------- 宏定义 ------------------------------------*/
/*do_load 函数调用的环境变量名字宏定义,add by chenhongsheng 2023.11.09*/
#define ARGV0  "do_load"                /*调用的函数do_load自身的函数名*/
#define ARGV1  "mmc"                    /*导入fdt文件的来源设备类型*/
#define ARGV2  "2:1"                    /*mmc 设备的mmcdev：mmcpart*/
#define ARGV3  "0x18000000"             /*kernel fdt导入到内存中的位置，与bootenv设置一致*/
#define ARGV4  "/imx6dl-sabresd.dtb"     /*kernel fdt的dtb文件名称*/

/*-------------------------------全局变量-----------------------------------*/
DECLARE_GLOBAL_DATA_PTR;     /*声明全局变量gd*/

/******************************************************************************
函 数 名  : check_file_size
函数版本  : V1.00
作    者  : chenhongsheng
日    期  : 2023-11-09
函数说明  : 导入kennel的设备树到指定的内存地址中
输入      : 无
输出      : ret 
返 回 值  : 0:成功；其他:失败,负值表示错误码
修改记录  :
********************************************************************************/
static loff_t check_file_size(void)
{
    int flag = 0;
    char * const argv[5] = {ARGV0, ARGV1, ARGV2, ARGV3, ARGV4};
    /* int fstype = FS_TYPE_FAT; */
    int fstype = FS_TYPE_EXT;
    int ret = -ENODEV;
	loff_t size;


	if (fs_set_blk_dev(argv[1], argv[2], fstype))
	{
		return -1;
	}

	if (fs_size(argv[4], &size) < 0)
	{
		return -1;
	}

	return size;
}

/******************************************************************************
函 数 名  : init_kernel_dtb
函数版本  : V1.00
作    者  : chenhongsheng
日    期  : 2023-11-09
函数说明  : 导入kennel的设备树到指定的内存地址中
输入      : 无
输出      : ret 
返 回 值  : 0:成功；其他:失败,负值表示错误码
修改记录  :
********************************************************************************/
int init_kernel_dtb(void)
{
    cmd_tbl_t *cmdtp = NULL;
    int flag = 0;
    int argc = 5;
    void * fdt_load_addr = (void *)0x18000000;
    char * const argv[5] = {ARGV0, ARGV1, ARGV2, ARGV3, ARGV4};
    /* int fstype = FS_TYPE_FAT; */
    int fstype = FS_TYPE_EXT;
    int ret = -ENODEV;
	loff_t size;

	size = check_file_size();
	if(size <= 0)
	{
        printf("Kernel dtb not exit!\n");
		return ret;
	}
    /*将fdt文件导入到内存中ARGV3处*/
    ret = do_load(cmdtp, flag, argc ,argv, fstype);
    if(ret == 0)
    {
        printf("Kernel load dtb success!\n");
        
        /*检查dtb文件头部信息是否正确*/
        if (!fdt_load_addr || ((uintptr_t)fdt_load_addr & 3) ||
            fdt_check_header(fdt_load_addr)) 
        {
            printf("fdt fdt check is error\n");
            ret = -1;
        }
        else
        {
            printf("kernel fdt check is ok\n");
            gd->fdt_blob = fdt_load_addr;
        }
    }
    return ret;
}
/******************************************************************************
函 数 名  : show_kernel_dtb_model
函数版本  : V1.00
作    者  : 卢文龙
日    期  : 2023-11-28
函数说明  : 显示内核设备树model 信息
输入      : 无
输出      : ret 
返 回 值  : 0:成功；其他:失败,负值表示错误码
修改记录  :
********************************************************************************/
int show_kernel_dtb_model(void)
{
	DECLARE_GLOBAL_DATA_PTR;
	const char *model;

	model = fdt_getprop(gd->fdt_blob, 0, "model", NULL);

	if (model)
		printf("KERNEL_DTB: %s\n", model);

	return 0;
}
/*------------------------------ 文件结束 -------------------------------------*/
