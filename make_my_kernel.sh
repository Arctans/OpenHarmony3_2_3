#!/bin/bash
##########################################################################
# File Name: make_my_kernel.sh
# Author: Arctan
# Created Time: 2024年01月25日 星期四 11时20分37秒
#########################################################################
./build.sh --product-name qemu-arm64-linux-min --build-target build_kernel --gn-args linux_kernel_version=\"linux-5.10\"

#应用进程支持gdb 调试
#./build.sh --product-name qemu-arm64-linux-min --gn-args="is_debug=true use_unstripped_as_runtime_outputs=true"
