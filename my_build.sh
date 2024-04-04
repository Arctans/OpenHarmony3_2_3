#!/bin/bash
##########################################################################
# File Name: my_build.sh
# Author: Arctan
# Created Time: 2024年03月21日 星期四 18时16分26秒
#########################################################################

# cpu=arm64
cpu=arm

record_file="./time_build.txt"

rm ${record_file} -rf

function record()
{
	time=$(date)
	echo " $1 $2 : ${time}" >>${record_file}
}

function hb_build()
{
	record start hb_${cpu}
	hb build --target-cpu ${cpu}
	record ended hb_${cpu}
}

function acts_build()
{
	record start acts_${cpu}
	cd test/xts/acts
	./build.sh product_name=rk3568 system_size=standard target_arch=${cpu}
	cd -
	record ended acts_${cpu}
}


function hats_build()
{
	record start hats_${cpu}
	cd test/xts/hats
	./build.sh product_name=rk3568 system_size=standard target_arch=${cpu}
	cd -
	record ended hats_${cpu}
}


function dcts_build()
{
	record start dcts_${cpu}
	cd test/xts/dcts
	./build.sh product_name=rk3568 system_size=standard target_arch=${cpu}
	cd -
	record ended dcts_${cpu}
}

hb_build
acts_build
hats_build
dcts_build

