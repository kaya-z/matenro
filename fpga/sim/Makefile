# Verilator test of rtl/xlink.v   (make -C fpga/sim)
all: build/Vxlink
	build/Vxlink
build/Vxlink: ../rtl/xlink.v tb_xlink.cpp
	verilator -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-WIDTH --cc --exe --build -Mdir build ../rtl/xlink.v tb_xlink.cpp -o Vxlink
.PHONY: all
