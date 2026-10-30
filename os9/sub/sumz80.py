#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""sumz80 - Z80 demo program for the Matenro machine (hand assembled, no Z80 assembler needed).

Protocol (the same as sum8088.asm): after the start it rings the 6809 ("ready"), then waits for the
doorbell interrupt (IM 1, RST 38), reads n from mailbox byte 0 of the 6809, computes 1+2+..+n, stores
the 16 bit result at address $0100 of the shared RAM and in S2M[0..1] (low, high), acknowledges the
6809 doorbell and rings the 6809.

    0000  LD SP,4000h        0003  IM 1               0005  EI
    0006  XOR A              0007  OUT (03),A  ack    0009  OUT (02),A  ready
    000B  HALT               000C  JR 000Bh
    0038  PUSH AF,BC,HL      003B  IN A,(04)         003D  LD C,A      003E  LD HL,0
    0041  LD B,0             0043  ADD HL,BC         0044  DEC C       0045  JR NZ,0043h
    0047  LD (0100h),HL      004A  LD A,L ; OUT (08),A   LD A,H ; OUT (09),A
    0050  LD A,0 ; OUT (03),A ; OUT (02),A      POP HL,BC,AF ; EI ; RETI

  python3 os9/sub/sumz80.py out.bin     writes the image ($5C bytes, load address 0)
"""
import sys

MAIN = bytes([0x31, 0x00, 0x40, 0xED, 0x56, 0xFB, 0xAF, 0xD3, 0x03, 0xD3, 0x02, 0x76, 0x18, 0xFD])
ISR = bytes([0xF5, 0xC5, 0xE5, 0xDB, 0x04, 0x4F, 0x21, 0x00, 0x00, 0x06, 0x00, 0x09, 0x0D, 0x20, 0xFC,
             0x22, 0x00, 0x01, 0x7D, 0xD3, 0x08, 0x7C, 0xD3, 0x09, 0x3E, 0x00, 0xD3, 0x03, 0xD3, 0x02,
             0xE1, 0xC1, 0xF1, 0xFB, 0xED, 0x4D])


def chunks(base=0x100000):
    """[(physical address, bytes)] for the window loader; the sub CPU address 0 is at physical `base`"""
    return [(base, MAIN), (base + 0x38, ISR)]


def image():
    img = bytearray(0x38 + len(ISR))
    img[0:len(MAIN)] = MAIN
    img[0x38:] = ISR
    return bytes(img)


if __name__ == '__main__':
    open(sys.argv[1] if len(sys.argv) > 1 else 'sumz80.bin', 'wb').write(image())
