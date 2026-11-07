#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""rbfwalk.py DISK.dsk    list the files of an OS-9 (RBF) disk image: d/- , path, size, attributes (the byte of the file descriptor).
Used by fpga/tn9k/scripts/bigd1.sh to copy the files of an old /d1 to a bigger one."""
import sys
S=256
def walk(path):
    d=open(path,'rb').read()
    def fdinfo(lsn):
        fd=d[lsn*S:(lsn+1)*S]
        size=int.from_bytes(fd[9:13],'big')
        segs=[(int.from_bytes(fd[16+5*i:19+5*i],'big'),int.from_bytes(fd[19+5*i:21+5*i],'big')) for i in range(48) if fd[16+5*i:21+5*i]!=bytes(5)]
        return fd[0],size,segs
    def data(lsn):
        att,size,segs=fdinfo(lsn)
        b=b''.join(d[a*S:(a+n)*S] for a,n in segs)
        return att,b[:size]
    out=[]
    def rec(lsn,prefix):
        att,b=data(lsn)
        for off in range(0,len(b),32):
            e=b[off:off+32]
            if e[0]==0: continue
            nm=bytes(c&0x7f for c in e[:29]).rstrip(b'\x00').decode('latin1')
            l=int.from_bytes(e[29:32],'big')
            if nm in ('.','..'): continue
            a2,size,_=fdinfo(l)
            isdir=bool(a2&0x80)
            out.append((prefix+nm,isdir,size,a2))
            if isdir: rec(l,prefix+nm+'/')
    rec(int.from_bytes(d[8:11],'big'),'')
    return out
if __name__=='__main__':
    for p,isdir,size,a in walk(sys.argv[1]): print(('d ' if isdir else '- '),p,size,hex(a))
