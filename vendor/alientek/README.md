# vendor_alientek

## Introduction

The repository is mainly developed by OpenHarmony community, rather than the typical certain manufacturer, mainly used for UniProton based kernel ability to test and verify.

## Software Architecture
```
//device/soc/st
  | stm32f407zg   --- Development board based on the UniProton kernel

//vendor/ohos
  | rtos_demo     --- Basic competence verification demo
  | rtos_demo_xts --- Basic competence verification xts demo
```

## Usage

The OpenHarmony uniproton kernel build system is a modular build system based on Generate Ninja (GN) and Ninja. It supports module-based configuration, tailoring, and assembling, and helps you build custom products. This document describes how to build a uniproton project based on GN and Ninja. For details about the methods such as GCC+gn, IAR, and Keil MDK, visit the community websites.

## Compilation and Building

### 1.Setting Up the Environment

Before setting up the environment for a development board, you must set up the basic system environment for OpenHarmony first. The basic system environment includes the OpenHarmony build environment and development environment. For details, see [Setting Up Development Environment](https://gitee.com/openharmony/docs/blob/HEAD/en/device-dev/quick-start/quickstart-lite-env-setup.md).

### 2.Obtaining the OpenHarmony Source Code

For details about how to obtain the source code, see [Source Code Acquisition](https://gitee.com/openharmony/docs/blob/HEAD/en/device-dev/get-code/sourcecode-acquire.md). This document assumes that the clone directory is ~/openHarmony after the complete OpenHarmony repository code is obtained.

### 3. Compile toolchain downloads

Install the GNU Arm Embedded Toolchain 32-bit compiler:

Download address: [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)，Specify version:10-2020-q4-major。

To install, refer to the following command:

```
tar -xvf gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2 -C /opt/tools
```

Note: After the installation is complete, add the installation directory to the ***environment variable PATH***.

### 4.Compilation

Execute in the source root directory:
```
hb set
```

Choice: alientek@rtos_demo

If you want to perform xts, then choose: alientek@rtos_demo_xts

Compile command:
```
hb build -f
```

## Contribution

[How to contribute](https://gitee.com/openharmony/docs/blob/HEAD/en/contribute/how-to-contribute.md)

## Repositories Involved

[device_soc_st](https://gitee.com/openharmony/device_soc_st)

[kernel_uniproton](https://gitee.com/openharmony-sig/kernel_uniproton)
