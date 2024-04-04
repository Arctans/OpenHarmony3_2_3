#!/bin/bash
##########################################################################
# File Name: make_my_mode_print.sh
# Author: Arctan
# Created Time: 2024年02月01日 星期四 16时59分28秒
#########################################################################

meson setup --prefix=/home/ut-e05857/workspace/OpenHarmony/harmony3_2_3/harmony3_2_3/third_party/libdrm.bak/musl_install --cross-file cross_file.txt cross_build

cd cross_build/
ninja
cd ../
