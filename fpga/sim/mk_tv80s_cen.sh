#!/bin/sh
# SPDX-License-Identifier: MIT
# Make tv80s_cen.v from the tv80s.v of TV80 (hutch31/tv80, MIT): the clock enable of the core is a port (cen_i), and the
# registers of the bus wrapper (RD, WR, MREQ, IORQ, the data latch) change only when upd_i is set.
#   fpga/sim/mk_tv80s_cen.sh <tv80 dir> <output.v>
python3 -c '
import sys
s = open(sys.argv[1], encoding="utf-8").read()
def rep(a, b):
    global s
    assert s.count(a) == 1, a
    s = s.replace(a, b)
rep("module tv80s ", "module tv80s_cen ")
rep("reset_n, clk, wait_n, int_n", "reset_n, clk, cen_i, upd_i, wait_n, int_n")
rep("  input         clk;", "  input         clk;\n  input         cen_i;\n  input         upd_i;")
rep("  assign    cen = 1;", "  assign    cen = cen_i;")
rep("      else\n        begin\n          rd_n <= `TV80DELAY 1\x27b1;", "      else if (upd_i)\n        begin\n          rd_n <= `TV80DELAY 1\x27b1;")
open(sys.argv[2], "w", encoding="utf-8").write(s)
' "$1/tv80s.v" "$2"
