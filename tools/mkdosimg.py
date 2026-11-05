#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Make a FAT12 disk image for MS-DOS 1.25 (os9 command `dos`) and put files in the root directory.

  python3 tools/mkdosimg.py OUT.img FORMAT [file ...]       FORMAT: 160 (KB), 320, or 8192 (a 8 MB hard disk)

The formats (the disk parameter tables of docs/DESIGN.md 18.4; `dos` finds the format from the size of the file):
  160 KB   512 bytes/sector, 1 sector/cluster, 1 reserved sector, 2 FATs, 64 directory entries, 320 sectors
  320 KB   512, 2, 1, 2, 112, 640
  8 MB     512, 8, 1, 2, 512, 16384
A file is stored under its upper case name; the date and time are those of the file.  COMMAND.COM must be in the
image of drive A.
"""
import os
import sys
import time

FORMATS = {
    160: (512, 1, 1, 2, 64, 320, 0xFE),
    320: (512, 2, 1, 2, 112, 640, 0xFF),
    8192: (512, 8, 1, 2, 512, 16384, 0xF8),
}


def make(fmt, files):
    secsz, spc, res, nfat, ndir, nsec, media = FORMATS[fmt]
    dirsec = ndir * 32 // secsz
    fatsec = 1
    while True:                                       # the FAT must hold the entries of all clusters
        nclus = (nsec - res - nfat * fatsec - dirsec) // spc
        if (nclus + 2) * 3 // 2 + 1 <= fatsec * secsz:
            break
        fatsec += 1
    assert nclus < 4080
    img = bytearray(nsec * secsz)
    fat = [0] * (nclus + 2)
    fat[0] = 0xF00 | media
    fat[1] = 0xFFF
    cs = spc * secsz
    first = res + nfat * fatsec + dirsec              # the first sector of cluster 2
    entries = bytearray()
    nxt = 2
    for path in files:
        data = open(path, 'rb').read()
        base = os.path.basename(path).upper()
        name, _, ext = base.partition('.')
        assert len(name) <= 8 and len(ext) <= 3, base
        need = (len(data) + cs - 1) // cs
        assert nxt + need <= nclus + 2, 'the disk is full'
        chain = list(range(nxt, nxt + need))
        nxt += need
        for i, c in enumerate(chain):
            fat[c] = chain[i + 1] if i + 1 < len(chain) else 0xFFF
            off = (first + (c - 2) * spc) * secsz
            blk = data[i * cs:(i + 1) * cs]
            img[off:off + len(blk)] = blk
        t = time.localtime(os.path.getmtime(path))
        dtime = (t.tm_hour << 11) | (t.tm_min << 5) | (t.tm_sec // 2)
        ddate = (max(t.tm_year - 1980, 0) << 9) | (t.tm_mon << 5) | t.tm_mday
        e = bytearray(32)
        e[0:11] = name.ljust(8).encode('ascii') + ext.ljust(3).encode('ascii')
        e[22:24] = dtime.to_bytes(2, 'little')
        e[24:26] = ddate.to_bytes(2, 'little')
        e[26:28] = (chain[0] if chain else 0).to_bytes(2, 'little')
        e[28:32] = len(data).to_bytes(4, 'little')
        entries += e
    assert len(entries) <= ndir * 32, 'too many files'
    f = bytearray()
    for i in range(0, len(fat), 2):                   # two 12 bit entries in three bytes
        a = fat[i]
        b = fat[i + 1] if i + 1 < len(fat) else 0
        f += bytes([a & 0xFF, (a >> 8) | ((b & 0xF) << 4), b >> 4])
    f = f.ljust(fatsec * secsz, b'\0')
    for k in range(nfat):
        o = (res + k * fatsec) * secsz
        img[o:o + len(f)] = f
    o = (res + nfat * fatsec) * secsz
    img[o:o + len(entries)] = entries
    return bytes(img)


def main():
    if len(sys.argv) < 3 or int(sys.argv[2]) not in FORMATS:
        print(__doc__)
        return 2
    open(sys.argv[1], 'wb').write(make(int(sys.argv[2]), sys.argv[3:]))
    return 0


if __name__ == '__main__':
    sys.exit(main())
