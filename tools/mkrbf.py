#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""mkrbf.py OUT.dsk [SECTORS [CLUSTER [NAME]]]   make an empty OS-9 (RBF) disk image of any size (256 byte sectors).

  SECTORS  size in sectors (default 262144 = 64 MB; at most 2^24).  CLUSTER  sectors per cluster, a power of 2 (default 1).
  NAME     the name of the volume (default d1).

The allocation map of an RBF volume may fill many sectors (LSN 1 ...): DD.MAP is its size in bytes, so its high byte is
the number of sectors (255 at most).  tools/growdisk.py of sim09 knows only a map of one sector (2048 clusters); this
tool writes the map, the root directory and LSN 0 for a volume that works like a hard disk (docs/DESIGN.md 14.4):
  LSN 0           DD.* fields (the same as the floppy volumes of sim09: DD.FMT 2, 18 sectors per track, DD.OPT copied)
  LSN 1 ...       the allocation map (one bit per cluster, 1 = used)
  after the map   the file descriptor of the root directory, then its first cluster ('..' and '.')
The volume is checked with `dcheck` of OS-9 (tests/matenro_test.py: os9_bigdisk)."""
import os
import sys
import time

SEC = 256
OPT = bytes.fromhex('01010020010028')          # DD.OPT of the floppy volumes of sim09 (a copy of the options of the descriptor)


def make(sectors=262144, cluster=1, name='d1', when=None):
    assert 0 < sectors < (1 << 24)
    assert cluster in (1, 2, 4, 8, 16, 32, 64, 128), 'cluster: a power of 2'
    clusters = (sectors + cluster - 1) // cluster
    mapbytes = (clusters + 7) // 8
    mapsec = (mapbytes + SEC - 1) // SEC
    assert mapsec <= 255, 'too big: the map is at most 255 sectors (use a bigger cluster)'
    mapbytes = mapsec * SEC                    # the map fills whole sectors; the bits past the end are marked used
    fd = 1 + mapsec                            # LSN of the file descriptor of the root directory
    dirlsn = fd + 1                            # its data: one cluster
    used = dirlsn + cluster                    # sectors 0 ... used - 1 are in use (LSN 0, the map, the FD, the directory)
    t = time.localtime(when)
    date5 = bytes([t.tm_year - 1900, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min])
    img = bytearray(sectors * SEC)
    # LSN 0
    l0 = bytearray(SEC)
    l0[0:3] = sectors.to_bytes(3, 'big')                # DD.TOT
    l0[3] = 18                                          # DD.TKS
    l0[4:6] = mapbytes.to_bytes(2, 'big')               # DD.MAP: bytes of the allocation map
    l0[6:8] = cluster.to_bytes(2, 'big')                # DD.BIT: sectors per cluster
    l0[8:11] = fd.to_bytes(3, 'big')                    # DD.DIR: the file descriptor of the root directory
    l0[13] = 0xFF                                       # DD.ATT
    l0[14:16] = (int.from_bytes(os.urandom(2), 'big') or 1).to_bytes(2, 'big')    # DD.DSK: the disk id
    l0[16] = 2                                          # DD.FMT
    l0[17:19] = (18).to_bytes(2, 'big')                 # DD.SPT
    l0[26:31] = date5                                   # DD.DAT
    nm = name.encode('ascii')
    l0[31:31 + len(nm)] = nm[:-1] + bytes([nm[-1] | 0x80])      # DD.NAM: the last character has bit 7 set
    l0[63:63 + len(OPT)] = OPT                          # DD.OPT
    img[0:SEC] = l0
    # the allocation map: the used clusters, and the bits behind the last cluster
    bits = bytearray(mapbytes)
    for c in range((used + cluster - 1) // cluster):
        bits[c // 8] |= 0x80 >> (c % 8)
    for c in range(clusters, mapbytes * 8):
        bits[c // 8] |= 0x80 >> (c % 8)
    img[SEC:SEC + mapbytes] = bits
    # the file descriptor of the root directory: a directory (D, owner and public read / write / execute), 2 links
    f = bytearray(SEC)
    f[0] = 0xBF
    f[3:8] = date5
    f[8] = 2                                            # FD.LNK
    f[9:13] = (64).to_bytes(4, 'big')                   # FD.SIZ: '..' and '.'
    f[13:16] = date5[:3]                                # FD.CRE
    f[16:19] = dirlsn.to_bytes(3, 'big')                # the first segment: LSN and size in sectors
    f[19:21] = cluster.to_bytes(2, 'big')
    img[fd * SEC:(fd + 1) * SEC] = f
    # the root directory: '..' and '.' both point to the file descriptor of the root
    d = bytearray(SEC)
    d[0:2] = b'.' + bytes([ord('.') | 0x80])
    d[29:32] = fd.to_bytes(3, 'big')
    d[32] = ord('.') | 0x80
    d[61:64] = fd.to_bytes(3, 'big')
    img[dirlsn * SEC:(dirlsn + 1) * SEC] = d
    return bytes(img)


def main():
    if len(sys.argv) < 2 or len(sys.argv) > 5:
        sys.exit(__doc__)
    sectors = int(sys.argv[2]) if len(sys.argv) > 2 else 262144
    cluster = int(sys.argv[3]) if len(sys.argv) > 3 else 1
    name = sys.argv[4] if len(sys.argv) > 4 else 'd1'
    open(sys.argv[1], 'wb').write(make(sectors, cluster, name))
    print('%s: %d sectors (%d KB), %d sectors per cluster' % (sys.argv[1], sectors, sectors // 4, cluster))


if __name__ == '__main__':
    main()
