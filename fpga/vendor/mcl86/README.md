# MCL86 (MicroCore Labs) - the 8088 core of the Tang Nano 20K machine

Cycle accurate Intel 8088 core by Ted Fried, MicroCore Labs.

* Source: https://github.com/MicroCoreLabs/Projects (directory `MCL86/Core`, commit `78f3fb0eb230e014f4a53397d8577c3570681b9d`, read 2026-11-12)
  and https://hackaday.io/project/188412-mcl86-cycle-accurate-intel-8088-fpga-core
* Files here, unchanged: `eu.v` (execution unit, a microsequencer), `biu_min.v` (bus interface unit, minimum mode 8088 pins).
* `mcl86_ucode.hex`: the microcode ROM, from `MCL86_Microcode_Xilinx_Version_4.coe` (4096 words of 32 bit, one hex word per line; the .coe
  header is left out).  Loaded by `fpga/rtl/eu4kx32.v`.
* License: the repository has no LICENSE file, but every RTL file carries the notice "Copyright (c) 2020 Ted Fried" with the MIT license
  text (permission to use, copy, modify, merge, publish, distribute, sublicense and sell, provided that the copyright notice and the permission
  notice are included in all copies).  Both files keep that notice.  The microcode is part of the same project.
