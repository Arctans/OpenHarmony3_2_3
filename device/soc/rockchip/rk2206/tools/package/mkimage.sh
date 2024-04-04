#
# Copyright (c) 2022 FuZhou Lockzhiner Electronic Co., Ltd. All rights reserved.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

BOARD=$(hb env | grep "board:" | awk -F' ' '{print $4}')
PRODUCT=$(hb env | grep "product:" | awk -F' ' '{print $4}')
ROOT_DIR=$(hb env | grep "root path" | awk -F' ' '{print $5}')
SDK_DIR=${ROOT_DIR}/device/soc/rockchip/rk2206/sdk_liteos
OUT_DIR=${ROOT_DIR}/out/${BOARD}/${PRODUCT}
IMAGE_DIR=${OUT_DIR}/images
TOOLS_DIR=${SDK_DIR}/../tools/package
LOADER_DIR=${SDK_DIR}/loader

# Partitions address, unit: blocks (1 block = 512B)
# System partition
PART_SYSTEM_OFFSET=0x00
PART_SYSTEM_BLOCKS=$1
# UserPart1 for loader
PART_LOADER_OFFSET=$[${PART_SYSTEM_OFFSET} + ${PART_SYSTEM_BLOCKS}]
PART_LOADER_BLOCKS=$2
# UserPart2 for liteos
PART_LITEOS_OFFSET=$[${PART_LOADER_OFFSET} + ${PART_LOADER_BLOCKS}]
PART_LITEOS_BLOCKS=$3
# UserPart3 for rootfs
PART_ROOTFS_OFFSET=$[${PART_LITEOS_OFFSET} + ${PART_LITEOS_BLOCKS}]
PART_ROOTFS_BLOCKS=$4
# UserPart4 for userfs
PART_USERFS_OFFSET=$[${PART_ROOTFS_OFFSET} + ${PART_ROOTFS_BLOCKS}]
PART_USERFS_BLOCKS=$5

LOADER1_BIN=rk2206_psram.bin
LOADER2_BIN=rk2206_loader.bin
LITEOS_BIN=liteos.bin
ROOTFS_BIN=rootfs_vfat.img
USERFS_BIN=userfs_vfag.img

LOADER_IMAGE=${LOADER_DIR}/rk2206_db_loader.bin
FIRMWARE_IMAGE=${OUT_DIR}/Firmware.img
FIRMWARE_MD5=${OUT_DIR}/Firmware.md5

SETTING_INI=${OUT_DIR}/setting.ini
CONFIG_JSON=${OUT_DIR}/config.json
function make_setting_ini()
{
    echo "[System]"
    echo "FwVersion=1.0"
    echo "Gpt_Enable="
    echo "Backup_Partition_Enable="
    echo "Nano="
    echo "Loader_Encrypt=0"
    echo "Chip="
    echo "Model="
    echo "[UserPart1]:"
    echo "Name=IDBlock"
    echo "Type=0x2"
    echo "PartOffset=${PART_LOADER_OFFSET}"
    echo "PartSize=${PART_LOADER_BLOCKS}"
    echo "Flag="
    echo "File=${LOADER_DIR}/${LOADER1_BIN},${LOADER_DIR}/${LOADER2_BIN}"
    echo "[UserPart2]"
    echo "Name=liteos"
    echo "Type=0x8"
    echo "PartOffset=${PART_LITEOS_OFFSET}"
    echo "PartSize=${PART_LITEOS_BLOCKS}"
    echo "Flag="
    echo "File=${OUT_DIR}/${LITEOS_BIN}"
    echo "[UserPart3]"
    echo "Name=rootfs"
    echo "Type="
    echo "PartOffset=${PART_ROOTFS_OFFSET}"
    echo "PartSize=${PART_ROOTFS_BLOCKS}"
    echo "Flag=1"
    echo "File=${OUT_DIR}/${ROOTFS_BIN}"
    echo "[UserPart4]"
    echo "Name=userfs"
    echo "Type="
    echo "PartOffset=${PART_USERFS_OFFSET}"
    echo "PartSize=${PART_USERFS_BLOCKS}"
    echo "Flag=1"
    echo "File=${OUT_DIR}/${USERFS_BIN}"
}

function make_config_json()
{
    echo "{"
    echo "  \"MAGIC\": \"RESC\","
    echo "  \"CHIP\": \"rk2206\","
    echo "  \"MODEL\": \"${PRODUCT}\","
    echo "  \"DESC\": \"rk2206 OpenHarmony\","
    echo "  \"VERSION\": \"2.00.0000\","
    echo "  \"DIGEST\": \"JSHASH\""
    echo "}"
}

function main()
{
    mkdir -p ${IMAGE_DIR}

    make_config_json > ${CONFIG_JSON}
    make_setting_ini > ${SETTING_INI}
    ${TOOLS_DIR}/resource_header_tool pack --json ${CONFIG_JSON} ${OUT_DIR}/${LITEOS_BIN}
    ${TOOLS_DIR}/firmware_merger -p ${SETTING_INI} ${IMAGE_DIR}
    cp ${LOADER_IMAGE} ${IMAGE_DIR}/
}

if [ $# -ne 5 ]; then
    echo Please input partitions block size!
    exit 1
fi

if [ ! -d ${ROOT_DIR} ] || [ ! -d ${OUT_DIR} ] || [ ! -d ${SDK_DIR} ]; then
    echo Root/out/board directions are not exist!
    exit 1
fi

main "$@"

