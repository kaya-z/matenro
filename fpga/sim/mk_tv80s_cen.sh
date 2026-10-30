#!/bin/sh
# SPDX-License-Identifier: MIT
# Make tv80s_cen.v (tv80s with the clock enable as a port, cen_i) from the tv80s.v of TV80 (hutch31/tv80, MIT) by sed.
#   fpga/sim/mk_tv80s_cen.sh <tv80 dir> <output.v>
sed -e 's/^module tv80s /module tv80s_cen /' \
    -e 's/reset_n, clk, wait_n, int_n/reset_n, clk, cen_i, wait_n, int_n/' \
    -e 's/^  input         clk; *$/  input         clk;\n  input         cen_i;/' \
    -e 's/^  assign    cen = 1;/  assign    cen = cen_i;/' "$1/tv80s.v" > "$2"
grep -q 'cen = cen_i' "$2" && grep -q 'input         cen_i' "$2" && grep -q 'module tv80s_cen' "$2" && grep -q 'clk, cen_i, wait_n' "$2"
