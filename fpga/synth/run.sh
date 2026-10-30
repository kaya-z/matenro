#!/bin/sh
# SPDX-License-Identifier: MIT
# Synthesize a module with the Gowin IDE (command line, synthesis only) and print the resource usage.
#   fpga/synth/run.sh 9k|20k top_module file.v [file.v ...]
set -e
IDE=${GOWIN_IDE:-/usr/local/IDE}
DEV=$1; TOP=$2; shift 2
case $DEV in
9k)  PART="-name GW1NR-9C GW1NR-LV9QN88PC6/I5" ;;
20k) PART="-name GW2AR-18C GW2AR-LV18QN88C8/I7" ;;
*) echo "device 9k or 20k"; exit 1 ;;
esac
B=$(cd "$(dirname "$0")" && pwd)/build/${TOP}_$DEV
mkdir -p "$B"
{
  echo "set_device $PART"
  for f in "$@"; do echo "add_file -type verilog $(readlink -f "$f")"; done
  echo "set_option -top_module $TOP"
  echo "set_option -verilog_std sysv2017"
  echo "set_option -output_base_name $TOP"
  echo "run syn"
  echo "exit"
} > "$B/syn.tcl"
cd "$B"
env -u DISPLAY QT_QPA_PLATFORM=offscreen "$IDE/bin/gw_sh" syn.tcl > syn.log 2>&1 || { tail -20 syn.log; exit 1; }
python3 - "$B" "$TOP" <<'PY'
import re, sys, html, glob
b, top = sys.argv[1:3]
f = glob.glob(b + '/impl/gwsynthesis/*_syn_resource.html')[0]
t = open(f, encoding='utf-8', errors='replace').read()
t = re.sub(r'<(script|style).*?</\1>', '', t, flags=re.S)
t = re.sub(r'<[^>]+>', ' ', t); t = html.unescape(t); t = re.sub(r'\s+', ' ', t)
print(t[t.index('MODULE NAME'):][:1500])
PY
