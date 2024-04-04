# Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

CIPHER_DRV_OBJS += drv/cipher_v1.0/compat/hi_drv_compat.o
CIPHER_DRV_OBJS += drv/cipher_v1.0/compat/drv_klad.o
CIPHER_DRV_OBJS += drv/cipher_v1.0/compat/hal_efuse.o
CIPHER_DRV_OBJS += drv/cipher_v1.0/compat/hal_otp.o

CIPHER_DRV_CFLAGS += -I$(CIPHER_BASE_DIR)/drv/cipher_v1.0/compat

