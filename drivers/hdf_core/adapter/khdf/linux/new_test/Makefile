#
# Copyright (c) 2020-2022 Huawei Device Co., Ltd.
#
# This software is licensed under the terms of the GNU General Public
# License version 2, as published by the Free Software Foundation, and
# may be copied, distributed, and modified under those terms.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
#

ccflags-$(CONFIG_DRIVERS_HDF_PLATFORM_NEW_TEST) += \
			-I$(srctree)/drivers/hdf/framework/include \
            -I$(srctree)/drivers/hdf/framework/include/osal \
            -I$(srctree)/drivers/hdf/framework/include/utils \
            -I$(srctree)/drivers/hdf/framework/utils/include \
            -I$(srctree)/drivers/hdf/framework/include/core \
            -I$(srctree)/drivers/hdf/framework/core/host/include \
            -I$(srctree)/drivers/hdf/framework/core/manager/include \
            -I$(srctree)/drivers/hdf/framework/core/shared/include \
            -I$(srctree)/drivers/hdf/framework/core/common/include/host \
            -I$(srctree)/drivers/hdf/framework/core/common/include/manager \
            -I$(srctree)/drivers/hdf/framework/core/adapter/vnode/include \
            -I$(srctree)/drivers/hdf/khdf/network/include \
            -I$(srctree)/drivers/hdf/khdf/osal/include \
            -I$(srctree)/include/hdf/wifi \
            -I$(srctree)/include/hdf/utils \
            -I$(srctree)/include/hdf/osal \
            -I$(srctree)/bounds_checking_function/include
obj-$(CONFIG_DRIVERS_HDF_PLATFORM_NEW_TEST)  += new_test.o 
