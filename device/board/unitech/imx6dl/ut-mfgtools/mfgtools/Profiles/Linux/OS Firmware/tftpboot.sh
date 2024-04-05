#!/bin/sh

# get ipaddr and serverip in uboot
ipaddr='fw_printenv ipaddr'
echo "ipaddr in uboot is: $ipaddr"
ifconfig eth0 $ipaddr

serverip='fw_printenv serverip'
echo "serverip in uboot is: $serverip"

# partition size in MB
BOOT_ROM_SIZE=10

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
${BOOT_ROM_SIZE}M,500M,0c
600M,,83
EOF

# tftp u-boot.bin from tftpserver
tftp -g -l /tmp/u-boot.imx -r u-boot.imx $serverip
if [$? -ne 0]; then
    echo "tftp u-boot.imx fail"
    exit 1
else
    echo "tftp u-boot.imx successed"
fi
