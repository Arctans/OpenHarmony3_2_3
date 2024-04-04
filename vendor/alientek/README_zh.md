# vendor_alientek

## 简介

该仓库托管OpenHarmony社区开发的，而非某个厂商单独开发的典型产品样例代码，主要用于基于UniProton内核的能力验证。

## 软件架构
```
//device/soc/st
  | stm32f407zg   --- 基于UniProton内核的单板

//vendor/ohos
  | rtos_demo     --- 基础能力验证demo
  | rtos_demo_xts --- xts
```

## 使用说明

OpenHarmony的uniproton内核的编译构建系统是一个基于gn和ninja的组件化构建系统，支持按组件配置、裁剪和拼装，按需构建出定制化的产品。本文主要介绍如何基于gn和ninja编译uniproton工程，GCC+gn、IAR、Keil MDK等编译方式可以参考社区爱好者贡献的站点。

## 编译构建指导

### 1.搭建系统基础环境

在搭建各个开发板环境前，需要完成OpenHarmony系统基础环境搭建。系统基础环境主要是指OpenHarmony的编译环境和开发环境，详细介绍请参考官方站点[开发环境准备](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/device-dev/quick-start/quickstart-lite-env-setup.md)。开发者需要根据环境搭建文档完成环境搭建。

### 2.获取OpenHarmony源码

详细的源码获取方式，请见[源码获取](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/device-dev/get-code/sourcecode-acquire.md)。获取OpenHarmony完整仓代码后，假设克隆目录为`~/openHarmony`。

### 3.编译工具链下载

安装GNU Arm Embedded Toolchain 32位编译器:

官方下载地址为: [GNU Arm Embedded Toolchain编译器](https://developer.arm.com/downloads/-/gnu-rm)，指定版本:10-2020-q4-major。

安装参考以下命令:

```
tar -xvf gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2 -C /opt/tools
```

注意: 安装完成后需要将安装目录加入***环境变量***中。

### 4.编译

在源码根目录执行:
```
hb set
```

选择: alientek@rtos_demo

执行xts测试用例，则选择: alientek@rtos_demo_xts

编译执行命令:
```
hb build -f
```

## 贡献

[如何参与](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

## 相关仓

[device_soc_st](https://gitee.com/openharmony/device_soc_st)

[kernel_uniproton](https://gitee.com/openharmony-sig/kernel_uniproton)
