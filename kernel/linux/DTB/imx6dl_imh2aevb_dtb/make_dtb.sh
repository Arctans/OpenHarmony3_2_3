#! /bin/bash

TAERGET="imx6dl-sabresd.dts"
device=${TAERGET%%.*}
src_dts=$device.dts
tmp_dts=$device.tmp.dts
dst_dtb=imx6dl-sabresd.dtb

cpp -nostdinc -I. -undef -x assembler-with-cpp $src_dts > $tmp_dts

./dtc -I dts -O dtb -b 0 \
-W no-unit_address_vs_reg \
-W no-address_cells_is_cell \
-W no-graph_endpoint \
-W no-graph_child_address \
-W no-graph_port \
-o $dst_dtb $tmp_dts 
	
rm $tmp_dts
cp imx6dl-sabresd.dtb ../../../../out/imx6dl/packages/phone/images/

