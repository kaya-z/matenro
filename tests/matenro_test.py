#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Integration tests of the Matenro machine: MC6809 + Z80 / 8088 sharing the RAM.

  python3 tests/matenro_test.py            (make test-mh)

The 6809 test programs are assembled with a09 of the sbc09 project (tools only, read only):
set A09=/path/to/a09 if it is not in the default place.
"""
import os, subprocess, sys, tempfile, shutil

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SIM = os.path.join(ROOT, 'matenro')
A09 = os.environ.get('A09', '/export/nas/archives/MC6809/new-sbc09/tools/a09')
OS9 = os.environ.get('OS9DIR', '/export/nas/archives/MC6809/new-sbc09/os9')
HERE = os.path.join(ROOT, 'tests')
fails = 0
total = 0


def check(name, ok, detail=''):
    global fails, total
    total += 1
    if not ok:
        fails += 1
    print('%s %s' % ('ok  ' if ok else 'FAIL', name))
    if not ok and detail:
        print('     ' + str(detail).encode('ascii', 'replace').decode().replace('\n', '\n     '))


def run(cmd, timeout=60, **kw):
    env = dict(os.environ, LC_ALL='C')
    return subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=timeout, env=env, **kw)


def chunk(phys, data):
    lines = ['        fcb $%02X,$%02X,$%02X' % (phys >> 16, (phys >> 8) & 255, phys & 255),
             '        fdb %d' % len(data)]
    for i in range(0, len(data), 16):
        lines.append('        fcb ' + ','.join('$%02X' % b for b in data[i:i + 16]))
    return '\n'.join(lines)


def asm6809(src, out):
    r = run([A09, '-o', out, src])
    if r.returncode != 0 or b'0 Pass 2 errors' not in r.stdout:
        raise RuntimeError('a09 failed: ' + r.stdout.decode())


def z80_program():
    sys.path.insert(0, os.path.join(ROOT, 'os9', 'sub'))
    import sumz80
    return sumz80.chunks()


def i8088_program(tmp):
    asm = os.path.join(ROOT, 'os9', 'sub', 'sum8088.asm')
    out = os.path.join(tmp, 'sub8088.bin')
    r = run(['nasm', '-f', 'bin', asm, '-o', out])
    if r.returncode:
        raise RuntimeError(r.stdout.decode())
    code = open(out, 'rb').read()
    stub = bytes([0xEA, 0x00, 0x04, 0x00, 0x00])           # JMP FAR 0000:0400 at the reset vector FFFF0
    return [(0x100400, code), (0x1FFFF0, stub)]


def integration(cpu, chunks, tmp):
    n = {'z80': 1, '8088': 2}[cpu]
    src = open(os.path.join(HERE, 'mh', 'xlink_test.asm')).read()
    src = src.replace('@SUBID@', str(n)).replace('@CHUNKS@', '\n'.join(chunk(p, d) for p, d in chunks))
    sp = os.path.join(tmp, 'it_%s.asm' % cpu)
    rom = os.path.join(tmp, 'it_%s.rom' % cpu)
    open(sp, 'w').write(src)
    asm6809(sp, rom)
    r = run([SIM, '-max', '-m', '1M', '-rom', rom, '-sub', cpu], timeout=60)
    check('6809 <-> %s : mailbox, doorbell interrupts, shared RAM, window, SMMU' % cpu,
          b'PASS' in r.stdout and r.returncode == 0, r.stdout.decode(errors='replace') + ' rc=%d' % r.returncode)


def standalone(cpu, tmp):
    # a 6809 ROM that does nothing; the sub CPU runs from -xload
    sp = os.path.join(tmp, 'idle.asm')
    rom = os.path.join(tmp, 'idle.rom')
    open(sp, 'w').write('        org $E000\nstart   bra start\n        org $FFFE\n        fdb start\n')
    asm6809(sp, rom)
    if cpu == 'z80':
        msg = b'hello from the Z80\n\0'
        code = bytes([0x21, 0x12, 0x00,                    # 0000 LD HL,msg (0012h)
                      0x7E,                                # 0003 loop: LD A,(HL)
                      0xB7,                                # 0004 OR A
                      0x28, 0x06,                          # 0005 JR Z,end (000Dh)
                      0xD3, 0x0E,                          # 0007 OUT (0E),A
                      0x23,                                # 0009 INC HL
                      0x18, 0xF7,                          # 000A JR loop (0003h)
                      0x00,                                # 000C
                      0x3E, 0xA5,                          # 000D end: LD A,A5h
                      0xD3, 0x0F,                          # 000F OUT (0F),A
                      0x76]) + msg                         # 0011 HALT ; msg at 0012h
        binf = os.path.join(tmp, 'hello_z80.bin')
        open(binf, 'wb').write(code)
        xl = [binf + '@0']
        want = b'hello from the Z80'
    else:
        asm = os.path.join(HERE, 'hello8088.asm')
        binf = os.path.join(tmp, 'hello8088.bin')
        r = run(['nasm', '-f', 'bin', asm, '-o', binf])
        if r.returncode:
            raise RuntimeError(r.stdout.decode())
        stub = os.path.join(tmp, 'stub8088.bin')
        open(stub, 'wb').write(bytes([0xEA, 0x00, 0x04, 0x00, 0x00]))
        xl = [binf + '@400', stub + '@FFFF0']
        want = b'hello from the 8088'
    con = os.path.join(tmp, 'xcon_%s.txt' % cpu)
    trace = os.path.join(tmp, 'xt_%s.txt' % cpu)
    cmd = [SIM, '-max', '-m', '1M', '-rom', rom, '-sub', cpu, '-xrun', '-xcon', con, '-xt', trace]
    for x in xl:
        cmd += ['-xload', x]
    r = run(cmd, timeout=60)
    out = open(con, 'rb').read() if os.path.exists(con) else b''
    check('standalone %s from -xload: debug console and power off' % cpu, want in out and r.returncode == 0,
          'console=%r rc=%d %s' % (out, r.returncode, r.stdout.decode(errors='replace')))
    tr = open(trace).read().splitlines() if os.path.exists(trace) else []
    check('%s instruction trace (-xt)' % cpu, len(tr) > 10 and ('PC=' in tr[0] or 'IP=' in tr[0]), tr[:2])


def os9_regression(tmp):
    if not os.path.isdir(OS9):
        print('skip OS-9 regression (no %s)' % OS9)
        return
    d = os.path.join(tmp, 'os9')
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
    script = os.path.join(d, 'script.txt')
    open(script, 'w').write('timeout 30000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                            'send "mdir\\r"\nexpect "OS9:"\nsend "date\\r"\nexpect "OS9:"\nquit\n')
    for sub in (None, 'z80', '8088'):
        cmd = [SIM, '-max', '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
               '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
        if sub:
            cmd += ['-sub', sub, '-m', '1M']
        r = run(cmd, timeout=120)
        out = r.stdout.decode(errors='replace')
        check('OS-9 Level 2 boots%s and lists its modules' % (' with an idle %s sub CPU' % sub if sub else ''),
              'Krn' in out and 'SysGo' in out and out.count('OS9:') >= 4, out[-400:])


def os9_xrun(tmp):
    """OS-9 Level 2 user program xrun: load a sub CPU program from /v0 and talk to it"""
    if not os.path.isdir(OS9):
        return
    defs = os.path.join(OS9, 'nitros9-code', 'defs') + '/'
    xrun = os.path.join(tmp, 'xrun')
    r = run([A09, '-I', defs, '-o', xrun, os.path.join(ROOT, 'os9', 'xrun.asm')], cwd=os.path.join(ROOT, 'os9'))
    if r.returncode != 0 or b'0 Pass 2 errors' not in r.stdout:
        check('assemble os9/xrun.asm', False, r.stdout.decode(errors='replace'))
        return
    sys.path.insert(0, os.path.join(ROOT, 'os9', 'sub'))
    import sumz80
    for cpu, binname in (('z80', 'sumz80.bin'), ('8088', 'sum8088.bin')):
        d = os.path.join(tmp, 'x_' + cpu)
        os.mkdir(d)
        for f in ('OS9.dsk', 'WORK.dsk'):
            shutil.copy(os.path.join(OS9, f), d)
        shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
        shutil.copy(xrun, os.path.join(d, 'v0', 'cmds', 'xrun'))
        if cpu == 'z80':
            open(os.path.join(d, 'v0', binname), 'wb').write(sumz80.image())
        else:
            r = run(['nasm', '-f', 'bin', os.path.join(ROOT, 'os9', 'sub', 'sum8088.asm'), '-o', os.path.join(d, 'v0', binname)])
            assert r.returncode == 0, r.stdout
        script = os.path.join(d, 'script.txt')
        open(script, 'w').write('timeout 30000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\n'
                                'send "xrun /v0/%s 100\\r"\nexpect "OS9:"\nsend "xrun /v0/%s 10\\r"\nexpect "OS9:"\nquit\n' % (binname, binname))
        cmd = [SIM, '-max', '-m', '1M', '-sub', cpu, '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
               '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
        r = run(cmd, timeout=120)
        out = r.stdout.decode(errors='replace')
        check('OS-9 Level 2: xrun loads and talks to the %s (100 -> 5050 = BA 13, then 10 -> 55 = 37 00)' % cpu,
              'reply: BA 13 00 00' in out and 'reply: 37 00 00 00' in out and
              out.index('reply: BA 13') < out.index('reply: 37 00'), out[-600:])


def build_cpm(tmp):
    """assemble the OS-9 commands cpm, xrun and cpp (tools/build_cpm.sh); returns the output directory"""
    out = os.path.join(tmp, 'cpmbuild')
    r = run([os.path.join(ROOT, 'tools', 'build_cpm.sh'), out])
    if r.returncode != 0 or r.stdout.count(b'0 Pass 2 errors') != 6:
        raise RuntimeError('build_cpm.sh failed: ' + r.stdout.decode(errors='replace'))
    return out


def z80_com(name, tmp):
    """assemble tests/cpm/<name>.asm with tools/z80asm.py -> bytes"""
    sys.path.insert(0, os.path.join(ROOT, 'tools'))
    import z80asm
    base, img = z80asm.assemble(open(os.path.join(HERE, 'cpm', name + '.asm'), encoding='utf-8').read())
    assert base == 0x100, hex(base)
    return img


def os9_session(tmp, tag, cpu, files, script_lines, timeout=180, driver=False):
    """boot OS-9 Level 2 with the sub CPU `cpu`, /v0 holds the cmds directory and `files`; run the script; return the output"""
    d = os.path.join(tmp, 'sess_' + tag)
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(d, 'v0', 'cmds'))
    for n in ('cpm', 'xrun', 'cpp', 'xlink', 'x0'):
        shutil.copy(os.path.join(tmp, 'cpmbuild', n), os.path.join(d, 'v0', 'cmds', n))
    for n, data in files.items():
        open(os.path.join(d, 'v0', n), 'wb').write(data)
    script = os.path.join(d, 'script.txt')
    pre = 'send "load xlink\\r"\nexpect "OS9:"\nsend "load x0\\r"\nexpect "OS9:"\n' if driver else ''
    open(script, 'w').write('timeout 60000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "chd /v0\\r"\nexpect "OS9:"\n' + pre
                            + '\n'.join(script_lines) + '\nquit\n')
    cmd = [SIM, '-max'] + ([] if driver else ['-m', '1M']) + ['-sub', cpu, '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
           '-1', os.path.join(d, 'WORK.dsk'), '-v', os.path.join(d, 'v0'), '-script', script]
    r = run(cmd, timeout=timeout)
    return r.stdout.decode(errors='replace'), d


def os9_cpm80(tmp):
    """CP/M-80 programs on the Z80, started from OS-9 with the command cpm"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.com': z80_com(n, tmp) for n in ('hello', 'fileio', 'line', 'stk6')}
    out, d = os9_session(tmp, 'cpm80', 'z80', files, [
        'send "cpm hello.com abc def\\r"', 'expect "OS9:"',
        'send "cpm fileio.com\\r"', 'expect "OS9:"',
        'send "cpm line.com\\r"', 'expect "Name? "', 'send "xyz\\r"', 'expect "]"', 'send "q"', 'expect "OS9:"',
        'send "cpm stk6.com\\r"', 'expect "OS9:"', 'send "cpm stk6.com\\r"', 'expect "OS9:"', 'send "cpm hello.com again\\r"', 'expect "OS9:"'])
    check('CP/M-80: stack at (6), JP 0 ends the program; later runs are not disturbed', out.count('stack at (6) ok') == 2 and 'AGAIN' in out, out[-600:])
    check('CP/M-80 on the Z80 from OS-9: BDOS 9/2, command tail', 'Hello from CP/M-80 on the Z80' in out and ' ABC DEF' in out, out[-800:])
    check('CP/M-80: file I/O (make, write, open, read, EOF, random, size, search, delete)', 'FILEIO OK' in out, out[-800:])
    check('CP/M-80: console buffer (BDOS 10), BDOS 1 and 6', '[xyz]' in out and 'key=q' in out, out[-800:])


def cmd86(name, tmp):
    """tests/cpm/<name>.asm (nasm, 8080 model) -> .CMD bytes"""
    b = os.path.join(tmp, name + '.bin')
    c = os.path.join(tmp, name + '.cmd')
    r = run(['nasm', '-f', 'bin', os.path.join(HERE, 'cpm', name + '.asm'), '-o', b])
    assert r.returncode == 0, r.stdout
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkcmd.py'), '8080', b, c])
    assert r.returncode == 0, r.stdout
    return open(c, 'rb').read()


def cmd86_small(tmp):
    out = {}
    for n in ('small86_code', 'small86_data'):
        r = run(['nasm', '-f', 'bin', os.path.join(HERE, 'cpm', n + '.asm'), '-o', os.path.join(tmp, n + '.bin')])
        assert r.returncode == 0, r.stdout
    c = os.path.join(tmp, 'small86.cmd')
    r = run([sys.executable, '-I', os.path.join(ROOT, 'tools', 'mkcmd.py'), 'small', os.path.join(tmp, 'small86_code.bin'),
             os.path.join(tmp, 'small86_data.bin'), c])
    assert r.returncode == 0, r.stdout
    return open(c, 'rb').read()


def os9_cpm86(tmp):
    """CP/M-86 programs on the 8088, started from OS-9 with the command cpm"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.cmd': cmd86(n, tmp) for n in ('hello86', 'fileio86', 'line86')}
    files['small86.cmd'] = cmd86_small(tmp)
    out, d = os9_session(tmp, 'cpm86', '8088', files, [
        'send "cpm hello86.cmd abc def\\r"', 'expect "OS9:"',
        'send "cpm small86.cmd\\r"', 'expect "OS9:"',
        'send "cpm fileio86.cmd\\r"', 'expect "OS9:"',
        'send "cpm line86.cmd\\r"', 'expect "Name? "', 'send "xyz\\r"', 'expect "]"', 'send "q"', 'expect "OS9:"'])
    check('CP/M-86 on the 8088 from OS-9: 8080 model, BDOS 9/2, command tail',
          'Hello from CP/M-86 on the 8088' in out and ' ABC DEF' in out, out[-800:])
    check('CP/M-86: small model (code + data group), RETF, version', 'Hello from the small model' in out and 'version ok, RETF ends' in out, out[-800:])
    check('CP/M-86: file I/O (make, write, open, read, EOF, random, size, search, delete)', 'FILEIO86 OK' in out, out[-800:])
    check('CP/M-86: console buffer (BDOS 10), BDOS 1 and 6', '[xyz]' in out and 'key=q' in out, out[-800:])


def os9_cpm80_text(tmp):
    """text files, STDIN / STDOUT, redirection, the tool directory (-p=) and the default extension"""
    if not os.path.isdir(OS9):
        return
    files = {n + '.com': z80_com(n, tmp) for n in ('tcat', 'tcount', 'hello', 'twrite')}
    files['in.txt'] = b'aaa\rbbb\rccc\r'                    # OS-9 line ends
    files['lf.txt'] = b'one\ntwo\n'                         # host line ends
    out, d = os9_session(tmp, 'cpm80text', 'z80', files, [
        'send "cpm tcount.com\\r"', 'expect "OS9:"',                     # IN.TXT = in.txt: 3 lines
        'send "list lf.txt !cpm tcat.com >copy.txt\\r"', 'expect "OS9:"',      # an OS-9 pipe into a CP/M filter
        'send "copy out.txt out1.txt\\r"', 'expect "OS9:"', 'send "del out.txt\\r"', 'expect "OS9:"',
        'send "cpm twrite.com\\r"', 'expect "OS9:"',
        'send "makdir tools\\r"', 'expect "OS9:"', 'send "copy hello.com tools/hello.com\\r"', 'expect "OS9:"',
        'send "del hello.com\\r"', 'expect "OS9:"',
        'send "cpm -p=tools hello x\\r"', 'expect "OS9:"'])
    check('CP/M-80 text files: OS-9 CR line ends are seen as CR LF', 'CR=03 LF=03' in out, out[-600:])
    names = {n.lower(): n for n in os.listdir(os.path.join(d, 'v0'))}
    got = lambda n: open(os.path.join(d, 'v0', names[n]), 'rb').read() if n in names else None
    check('OS-9 pipe -> CP/M filter (STDIN / STDOUT FCBs) -> redirect: host LF text -> OS-9 text', got('copy.txt') == b'one\rtwo\r', repr(got('copy.txt')))
    check('a text file written by CP/M (CR LF, ^Z) has OS-9 line ends; the filter also wrote OUT.TXT', got('new.txt') == b'ab\rcd\r' and got('out1.txt') == b'one\rtwo\r',
          repr((got('new.txt'), got('out1.txt'))))
    check('cpm -p=dir: program and default extension found in the tool directory', 'Hello from CP/M-80 on the Z80' in out, out[-600:])


def os9_cpp(tmp):
    """the C preprocessor written for OS-9 (os9/cpp/cpp.asm): macros, conditionals, expressions, #include, -D"""
    if not os.path.isdir(OS9):
        return
    files = {n: open(os.path.join(HERE, 'cpp', n), 'rb').read() for n in ('t1.c', 't1.h', 't2.c', 't3.c', 't4.c')}
    out, d = os9_session(tmp, 'cpp', 'z80', files, [
        'send "cpp t1.c >t1.o\\r"', 'expect "OS9:"', 'send "cpp t2.c >t2.o\\r"', 'expect "OS9:"',
        'send "cpp t3.c >t3.o\\r"', 'expect "OS9:"', 'send "cpp t4.c >t4.o\\r"', 'expect "OS9:"', 'send "cpp -DFOO=5 -DBAR t1.c >t1d.o\\r"', 'expect "OS9:"'])
    names = {n.lower(): n for n in os.listdir(os.path.join(d, 'v0'))}
    def words(n):
        if n not in names:
            return None
        return [l.strip() for l in open(os.path.join(d, 'v0', names[n]), 'rb').read().decode('latin-1').split('\r') if l.strip()]
    t1 = words('t1.o')
    check('cpp: #include, object and function-like macros, nested arguments, strings, comments, #undef',
          t1 is not None and 'int x = 2 + 1;' in t1 and 'int y = ((2)+(((1)+(2))));' in t1 and
          'char *s = "not /* a comment */ TWO";' in t1 and 'int z = TWO;' in t1 and 'int w = (5) * 2;' in [' '.join(l.split()) for l in t1], repr(t1))
    check('cpp: #if / #ifdef / #ifndef / #elif / defined', t1 is not None and all(x in t1 for x in ('int nofoo;', 'int nobar;', 'int calc_ok;', 'int elif_ok;', 'int either;')), repr(t1))
    t2 = words('t2.o')
    check('cpp: #if expressions and function-like macro calls in text',
          t2 is not None and t2[-1] == '((1)+(2)) ((((1)+(2)))*(((1)+(2)))) ((3)+(((2)*(2))))' and
          all(x in t2 for x in ('a1', 'b0', 'and_ok', 'eq_ok', 'arith_ok', 'or_ok', 'def_ok', 'tern_ok', 'num_ok', 'op_ok', 'cmp_ok', 'elif_ok')), repr(t2))
    t3 = words('t3.o')
    check('cpp: operators (division, shifts, bit operations, 16 bit constants, ?:)',
          t3 == ['c1', 'c2', 'c3', 'c4', 'c5', 'c6', 'c7', 'c8', 'c9', 'c10', 'c11', 'c13'], repr(t3))
    t4 = words('t4.o')
    check('cpp: # (stringify) and ## (paste), arguments expanded first except next to # and ##',
          t4 == ['char *a = "hello world";', 'char *b = "\\"q\\\\\\"uote\\" \'c\' \\n";', 'int foobar = 1;', 'int x_y = 12;',
                 'char *c = "abc" " done";', 'char *d = "42";', 'char *e = "VAL";', 'int f = VAL1;'], repr(t4))
    t1d = words('t1d.o')
    check('cpp: -Dname=value and -Dname',
          t1d is not None and 'int foo = 5;' in t1d and 'int calc_bad;' in t1d and 'int nobar;' not in t1d, repr(t1d))


def os9_cc80(tmp):
    """OS-9 cpp -> HI-TECH C passes on the Z80 -> a CP/M-80 program, started by cc80.  The compiler is not part of
    this project: set MATENRO_HTC to a directory with P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB and the headers."""
    htc = os.environ.get('MATENRO_HTC')
    if not os.path.isdir(OS9):
        return
    if not htc or not os.path.isdir(htc):
        print('skip cc80 (set MATENRO_HTC to the HI-TECH C directory)')
        return
    d = os.path.join(tmp, 'sess_cc80')
    os.mkdir(d)
    for f in ('OS9.dsk', 'WORK.dsk'):
        shutil.copy(os.path.join(OS9, f), d)
    v0 = os.path.join(d, 'v0')
    shutil.copytree(os.path.join(OS9, 'level2', 'cmds'), os.path.join(v0, 'cmds'))
    for n in ('cpm', 'cpp', 'cc80'):
        shutil.copy(os.path.join(tmp, 'cpmbuild', n), os.path.join(v0, 'cmds', n))
    os.mkdir(os.path.join(v0, 'htc'))
    for n in os.listdir(htc):
        if n.upper().endswith(('.COM', '.OBJ', '.LIB', '.H')):
            shutil.copy(os.path.join(htc, n), os.path.join(v0, 'htc', n))
    shutil.copy(os.path.join(HERE, 'cpp', 'demo.c'), v0)
    script = os.path.join(d, 'script.txt')
    open(script, 'w').write('timeout 3000000\nexpect "OS9:"\nsend "chx /v0/cmds\\r"\nexpect "OS9:"\nsend "chd /v0\\r"\nexpect "OS9:"\n'
                            'send "cc80 -r demo.c\\r"\nexpect "OS9:"\nsend "cc80 -r -DSMALL demo.c\\r"\nexpect "OS9:"\nquit\n')
    r = run([SIM, '-max', '-m', '1M', '-sub', 'z80', '-rom', os.path.join(OS9, 'os9v2.rom'), '-0', os.path.join(d, 'OS9.dsk'),
             '-1', os.path.join(d, 'WORK.dsk'), '-v', v0, '-script', script], timeout=900)
    out = r.stdout.decode(errors='replace')
    check('cc80: cpp on OS-9 -> HI-TECH C on the Z80 -> program runs (macros, #if, -D)', 'big 36' in out and 'small 36' in out, out[-800:])


def os9_driver(tmp):
    """the xlink driver (os9/xlink): the sub CPU memory comes from OS-9's own RAM (no -m 1M), the doorbell is an interrupt"""
    if not os.path.isdir(OS9):
        return
    f80 = {n + '.com': z80_com(n, tmp) for n in ('hello', 'fileio')}
    out, d = os9_session(tmp, 'drv80', 'z80', f80, [
        'send "cpm hello.com abc\\r"', 'expect "OS9:"', 'send "cpm fileio.com\\r"', 'expect "OS9:"',
        'send "cpm hello.com again\\r"', 'expect "OS9:"'], driver=True)
    check('xlink driver, Z80: memory from OS-9 (2MB machine), three runs in a row (allocate / free)',
          out.count('Hello from CP/M-80 on the Z80') == 2 and 'FILEIO OK' in out and ' AGAIN' in out, out[-700:])
    out, d = os9_session(tmp, 'drvstress', 'z80', {'bstress.com': z80_com('bstress', tmp)}, [
        'send "cpm bstress.com\\r"', 'expect "DONE"', 'expect "OS9:"'], driver=True, timeout=240)
    run_out = out.split('DONE')[0].rsplit('cpm bstress.com', 1)[-1]
    check('xlink driver, Z80: 3000 rounds of memory work and BDOS calls (tests/cpm/bstress.asm), no E',
          'DONE' in out and run_out.count('.') >= 3000 and 'E' not in run_out, out[-300:])
    f86 = {'hello86.cmd': cmd86('hello86', tmp), 'small86.cmd': cmd86_small(tmp)}
    out, d = os9_session(tmp, 'drv86', '8088', f86, [
        'send "cpm hello86.cmd abc\\r"', 'expect "OS9:"', 'send "cpm small86.cmd\\r"', 'expect "OS9:"'], driver=True)
    check('xlink driver, 8088: 32 blocks, the reset vector block mapped', 'Hello from CP/M-86 on the 8088' in out and 'Hello from the small model' in out, out[-700:])


def memtest():
    """power-on memory test of the sim09 board: "Memory " + 24 x ">" + " OK 2048K" / " NG @aaaaaa" """
    rom = os.path.join(OS9, 'os9v2.rom')
    if not os.path.exists(rom):
        print('skip memtest (no %s)' % rom)
        return
    base = [SIM, '-max', '-nt', '-maxcount', '10', '-rom', rom]
    out = run(base).stdout.decode(errors='replace')
    check('memory test: Memory %s OK 2048K' % ('>' * 24), out.startswith('Memory ' + '>' * 24 + ' OK 2048K\r\n'), out[:80])
    out = run(base + ['-memfault', '123456']).stdout.decode(errors='replace')
    check('memory test: a stuck bit is reported with its address', out.startswith('Memory ' + '>' * 24 + ' NG @123456\r\n'), out[:80])
    out = run(base + ['-nomemtest']).stdout.decode(errors='replace')
    check('memory test: -nomemtest prints nothing', not out.startswith('Memory'), out[:80])
    out = run(base + ['-L1', '-rom', os.path.join(OS9, 'v09.rom')]).stdout.decode(errors='replace')
    check('memory test: Level 1 tests its 64KB', out.startswith('Memory >>> OK 64K\r\n'), out[:80])


def main():
    if not os.path.exists(SIM):
        print('build first: make')
        return 2
    tmp = tempfile.mkdtemp(prefix='mh_')
    try:
        memtest()
        integration('z80', z80_program(), tmp)
        integration('8088', i8088_program(tmp), tmp)
        standalone('z80', tmp)
        standalone('8088', tmp)
        os9_regression(tmp)
        build_cpm(tmp)
        os9_xrun(tmp)
        os9_cpm80(tmp)
        os9_cpm80_text(tmp)
        os9_cpm86(tmp)
        os9_cpp(tmp)
        os9_cc80(tmp)
        os9_driver(tmp)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print('%d tests, %d failed' % (total, fails))
    return 1 if fails else 0


if __name__ == '__main__':
    sys.exit(main())
