#!/bin/sh

## partition size in MB
#BOOT_ROM_START=10
#IMAGE_SIZE=500
#ROOTFS_START=510
#ROOTFS_SIZE=5120
#IMAGE_START=5630
#
## wait for the SD/MMC device node ready
#while [ ! -e $1 ]
#do
#sleep 1
#echo “wait for $1 appear”
#done
#
## call sfdisk to create partition table
## destroy the partition table
#node=$1
#dd if=/dev/zero of=${node} bs=1024 count=1
#
#sfdisk --force ${node} << EOF
#${BOOT_ROM_START}M,${IMAGE_SIZE}M,0c
#${ROOTFS_START}M,${ROOTFS_SIZE}M,83
#${IMAGE_START}M,,83
#EOF

# partition size in MB
BOOT_ROM_START=10
KERNEL_UBOOT_SIZE=100
ROOTFS_START=110
ROOTFS_SIZE=2000
IMAGE_START=2110
IMAGE_SIZE=2000
USER_START=4110

#BOOT_ROM_START=10
#KERNEL_UBOOT_SIZE=500
#ROOTFS_START=510
#ROOTFS_SIZE=1300
#IMAGE_START=1810
#IMAGE_SIZE=1300
#USER_START=3110

# wait for the SD/MMC device node ready
while [ ! -e $1 ]
do
sleep 1
echo “wait for $1 appear”
done

# call sfdisk to create partition table
# destroy the partition table
node=$1
dd if=/dev/zero of=${node} bs=1024 count=1

sfdisk --force ${node} << EOF
${BOOT_ROM_START}M,${KERNEL_UBOOT_SIZE}M,0c
${ROOTFS_START}M,${ROOTFS_SIZE}M,83
${IMAGE_START}M,${IMAGE_SIZE}M,83
${USER_START}M,,83
EOF