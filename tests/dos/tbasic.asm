; SPDX-License-Identifier: MIT
; TBASIC.COM: a small Tiny BASIC for MS-DOS 1.25 / 2.0 (8086, one .COM file, only INT 21h AH=2,9,0Ah,2Ch and INT 20h).
;   nasm -f bin tests/dos/tbasic.asm -o tbasic.com
; Line numbers 1..65535, 26 integer variables A-Z (16 bit, signed).
; Commands:  NEW  LIST  RUN  BYE            (a line with a number is stored, a line number alone deletes it)
; Statements: PRINT "text"; expr, ...   [LET] v=expr   INPUT v   IF expr rel expr [THEN] stmt|line
;             GOTO expr   GOSUB expr   RETURN   END   REM
; Expressions: + - * / ( ) unary -, numbers, variables, RND(n) (0..n-1).  rel: = < > <= >= <>
	cpu	8086
	org	100h

PROGMAX	equ	0E000h

section .text
start:	cld
	mov	[mainsp],sp
	mov	ah,2Ch
	int	21h
	mov	[seed],dx
	call	newprog
	mov	si,s_banner
	call	puts
main:	mov	sp,[mainsp]
	mov	word [curnum],0
	mov	al,'>'
	call	putc
	mov	dx,ibuf
	mov	ah,0Ah
	int	21h
	mov	al,10
	call	putc
	xor	bh,bh
	mov	bl,[ibuf+1]
	mov	byte [ibuf+2+bx],0
	mov	si,ibuf+2			; upper case outside of quotes
	xor	dl,dl
.u:	mov	al,[si]
	or	al,al
	jz	.ud
	cmp	al,'"'
	jne	.u2
	xor	dl,1
	jmp	short .un
.u2:	test	dl,dl
	jnz	.un
	cmp	al,'a'
	jb	.un
	cmp	al,'z'
	ja	.un
	sub	al,20h
	mov	[si],al
.un:	inc	si
	jmp	.u
.ud:	mov	si,ibuf+2
	call	skipsp
	mov	al,[si]
	or	al,al
	jz	main
	cmp	al,'0'
	jb	.imm
	cmp	al,'9'
	ja	.imm
	call	getnum
	call	skipsp
	call	editline
	jmp	main
.imm:	mov	ax,[progend]
	mov	[nextp],ax
	call	stmt
run:	mov	bx,[nextp]
	cmp	bx,[progend]
	jae	main
	mov	[cur],bx
	mov	ax,[bx]
	mov	[curnum],ax
	add	bx,[bx+2]
	mov	[nextp],bx
	mov	si,[cur]
	add	si,4
	call	stmt
	jmp	run

; ---------------------------------------------------------------- output
putc:	push	ax
	push	dx
	mov	dl,al
	mov	ah,2
	int	21h
	pop	dx
	pop	ax
	ret
puts:	lodsb
	or	al,al
	jz	.r
	call	putc
	jmp	puts
.r:	ret
crlf:	mov	al,13
	call	putc
	mov	al,10
	jmp	putc
pnum:	push	ax			; AX signed -> decimal
	push	bx
	push	cx
	push	dx
	test	ax,ax
	jns	.p
	push	ax
	mov	al,'-'
	call	putc
	pop	ax
	neg	ax
.p:	xor	cx,cx
	mov	bx,10
.d:	xor	dx,dx
	div	bx
	push	dx
	inc	cx
	test	ax,ax
	jnz	.d
.o:	pop	ax
	add	al,'0'
	call	putc
	loop	.o
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	ret

; ---------------------------------------------------------------- errors
syntax:	mov	si,e_syntax
	jmp	short error
divzero: mov	si,e_div
	jmp	short error
undef:	mov	si,e_undef
	jmp	short error
nomem:	mov	si,e_mem
	jmp	short error
stkerr:	mov	si,e_stack
error:	mov	sp,[mainsp]
	mov	al,'?'
	call	putc
	call	puts
	mov	ax,[curnum]
	or	ax,ax
	jz	.e
	mov	si,s_in
	call	puts
	call	pnum
.e:	call	crlf
	jmp	main

; ---------------------------------------------------------------- scanning
skipsp:	cmp	byte [si],' '
	jne	.r
	inc	si
	jmp	skipsp
.r:	ret
getnum:	xor	ax,ax			; decimal number at SI -> AX, carry set if there is none
	xor	bx,bx
.l:	mov	cl,[si]
	sub	cl,'0'
	cmp	cl,9
	ja	.e
	mov	dx,10
	mul	dx
	xor	ch,ch
	add	ax,cx
	inc	si
	inc	bx
	jmp	.l
.e:	cmp	bx,1			; carry if BX = 0
	cmc
	cmc
	ret

; ---------------------------------------------------------------- expressions
expr:	call	term
.l:	call	skipsp
	mov	dl,[si]
	cmp	dl,'+'
	je	.a
	cmp	dl,'-'
	je	.s
	ret
.a:	inc	si
	push	ax
	call	term
	pop	bx
	add	ax,bx
	jmp	.l
.s:	inc	si
	push	ax
	call	term
	pop	bx
	xchg	ax,bx
	sub	ax,bx
	jmp	.l
term:	call	factor
.l:	call	skipsp
	mov	dl,[si]
	cmp	dl,'*'
	je	.m
	cmp	dl,'/'
	je	.d
	ret
.m:	inc	si
	push	ax
	call	factor
	pop	bx
	imul	bx
	jmp	.l
.d:	inc	si
	push	ax
	call	factor
	mov	bx,ax
	pop	ax
	test	bx,bx
	jz	divzero
	cmp	bx,-1
	jne	.q
	neg	ax
	jmp	.l
.q:	cwd
	idiv	bx
	jmp	.l
factor:	call	skipsp
	mov	al,[si]
	cmp	al,'-'
	jne	.1
	inc	si
	call	factor
	neg	ax
	ret
.1:	cmp	al,'('
	jne	.2
	inc	si
	call	expr
	call	skipsp
	cmp	byte [si],')'
	jne	syntax
	inc	si
	ret
.2:	cmp	al,'0'
	jb	.3
	cmp	al,'9'
	ja	.3
	jmp	getnum
.3:	cmp	al,'R'
	jne	.4
	cmp	word [si],'RN'
	jne	.4
	cmp	byte [si+2],'D'
	jne	.4
	add	si,3
	call	skipsp
	cmp	byte [si],'('
	jne	syntax
	inc	si
	call	expr
	call	skipsp
	cmp	byte [si],')'
	jne	syntax
	inc	si
	mov	bx,ax
	mov	ax,[seed]
	mov	dx,25173
	mul	dx
	add	ax,13849
	mov	[seed],ax
	shr	ax,1
	test	bx,bx
	jle	syntax
	xor	dx,dx
	div	bx
	mov	ax,dx
	ret
.4:	cmp	al,'A'
	jb	syntax
	cmp	al,'Z'
	ja	syntax
	inc	si
	sub	al,'A'
	xor	ah,ah
	shl	ax,1
	mov	bx,ax
	mov	ax,[vars+bx]
	ret

; ---------------------------------------------------------------- program store
newprog: mov	word [progend],prog
	mov	word [nextp],prog
	mov	word [gsp],0
	ret
findline: mov	bx,prog			; AX = line number -> BX = the line, or error
.l:	cmp	bx,[progend]
	jae	undef
	cmp	[bx],ax
	je	.f
	ja	undef
	add	bx,[bx+2]
	jmp	.l
.f:	ret
editline:				; AX = number, SI = text (maybe empty): store, replace or delete
	mov	dx,ax
	mov	bx,prog
.f:	cmp	bx,[progend]
	jae	.f2
	cmp	[bx],dx
	jae	.f2
	add	bx,[bx+2]
	jmp	.f
.f2:	cmp	bx,[progend]
	jae	.ins
	cmp	[bx],dx
	jne	.ins
	push	si			; delete the old line
	mov	cx,[bx+2]
	mov	di,bx
	mov	si,bx
	add	si,cx
	push	cx
	mov	cx,[progend]
	sub	cx,si
	rep	movsb
	pop	cx
	sub	[progend],cx
	pop	si
.ins:	cmp	byte [si],0
	je	.done
	mov	di,si
	xor	cx,cx
.len:	cmp	byte [di],0
	je	.l2
	inc	di
	inc	cx
	jmp	.len
.l2:	inc	cx			; with the 0
	mov	ax,cx
	add	ax,4			; size of the entry
	mov	di,[progend]
	add	di,ax
	cmp	di,PROGMAX
	ja	nomem
	push	si
	push	cx
	mov	cx,[progend]
	sub	cx,bx
	mov	si,[progend]
	dec	si
	mov	di,si
	add	di,ax
	std
	rep	movsb
	cld
	pop	cx
	pop	si
	mov	[bx],dx
	mov	[bx+2],ax
	lea	di,[bx+4]
	rep	movsb
	add	[progend],ax
.done:	ret

; ---------------------------------------------------------------- statements
stmt:	call	skipsp
	cmp	byte [si],0
	je	.r
	mov	bx,kwtab
.n:	mov	di,[bx]
	test	di,di
	jz	do_let
	push	si
.c:	mov	al,[di]
	or	al,al
	jz	.hit
	cmp	al,[si]
	jne	.no
	inc	si
	inc	di
	jmp	.c
.no:	pop	si
	add	bx,4
	jmp	.n
.hit:	pop	ax
	call	[bx+2]
.r:	ret

do_let:	call	skipsp
	mov	al,[si]
	cmp	al,'A'
	jb	syntax
	cmp	al,'Z'
	ja	syntax
	inc	si
	sub	al,'A'
	xor	ah,ah
	shl	ax,1
	push	ax
	call	skipsp
	cmp	byte [si],'='
	jne	syntax
	inc	si
	call	expr
	pop	bx
	mov	[vars+bx],ax
	ret

do_print:
.l:	call	skipsp
	mov	al,[si]
	or	al,al
	jz	.nl
	cmp	al,'"'
	jne	.e
	inc	si
.q:	lodsb
	or	al,al
	jz	.nl
	cmp	al,'"'
	je	.sep
	call	putc
	jmp	.q
.e:	call	expr
	call	pnum
.sep:	call	skipsp
	mov	al,[si]
	cmp	al,';'
	je	.s
	cmp	al,','
	jne	.nl
	mov	al,' '
	call	putc
.s:	inc	si
	call	skipsp
	cmp	byte [si],0
	je	.r
	jmp	.l
.nl:	call	crlf
.r:	ret

do_input:
	call	skipsp
	mov	al,[si]
	cmp	al,'A'
	jb	syntax
	cmp	al,'Z'
	ja	syntax
	inc	si
	sub	al,'A'
	xor	ah,ah
	shl	ax,1
	push	ax
	push	si
	mov	al,'?'
	call	putc
	mov	al,' '
	call	putc
	mov	dx,ibuf2
	mov	ah,0Ah
	int	21h
	mov	al,10
	call	putc
	xor	bh,bh
	mov	bl,[ibuf2+1]
	mov	byte [ibuf2+2+bx],0
	mov	si,ibuf2+2
	call	expr
	pop	si
	pop	bx
	mov	[vars+bx],ax
	ret

do_if:	call	expr
	push	ax
	call	skipsp
	xor	dx,dx
.r:	mov	al,[si]
	cmp	al,'='
	jne	.1
	or	dl,1
	jmp	short .n
.1:	cmp	al,'<'
	jne	.2
	or	dl,2
	jmp	short .n
.2:	cmp	al,'>'
	jne	.3
	or	dl,4
.n:	inc	si
	jmp	.r
.3:	test	dl,dl
	jz	syntax
	push	dx
	call	expr
	pop	dx
	pop	bx
	cmp	bx,ax
	mov	cl,1
	je	.t
	mov	cl,2
	jl	.t
	mov	cl,4
.t:	test	cl,dl
	jz	.false
	call	skipsp
	cmp	word [si],'TH'
	jne	.nt
	cmp	word [si+2],'EN'
	jne	.nt
	add	si,4
.nt:	call	skipsp
	mov	al,[si]
	cmp	al,'0'
	jb	stmt
	cmp	al,'9'
	ja	stmt
	call	getnum
	jmp	short goto
.false:	ret

do_goto: call	expr
goto:	call	findline
	mov	[nextp],bx
	ret
do_gosub: call	expr
	mov	di,ax
	mov	bx,[gsp]
	cmp	bx,32
	jae	stkerr
	mov	ax,[nextp]
	mov	[gstack+bx],ax
	add	word [gsp],2
	mov	ax,di
	jmp	goto
do_return: mov	bx,[gsp]
	or	bx,bx
	jz	stkerr
	sub	bx,2
	mov	[gsp],bx
	mov	ax,[gstack+bx]
	mov	[nextp],ax
	ret
do_end:	mov	ax,[progend]
	mov	[nextp],ax
	ret
do_rem:	ret
do_run:	mov	word [gsp],0
	mov	word [nextp],prog
	ret
do_new:	jmp	newprog
do_bye:	int	20h
do_list: mov	bx,prog
.l:	cmp	bx,[progend]
	jae	.r
	mov	ax,[bx]
	call	pnum
	mov	al,' '
	call	putc
	lea	si,[bx+4]
	call	puts
	call	crlf
	add	bx,[bx+2]
	jmp	.l
.r:	ret

section .data
s_banner: db	'TINY BASIC (8088) - NEW LIST RUN BYE',13,10,0
s_in:	db	' IN ',0
e_syntax: db	'SYNTAX ERROR',0
e_div:	db	'DIVIDE BY ZERO',0
e_undef: db	'UNDEFINED LINE',0
e_mem:	db	'OUT OF MEMORY',0
e_stack: db	'GOSUB/RETURN ERROR',0
k_print: db	'PRINT',0
k_let:	db	'LET',0
k_input: db	'INPUT',0
k_if:	db	'IF',0
k_goto:	db	'GOTO',0
k_gosub: db	'GOSUB',0
k_return: db	'RETURN',0
k_end:	db	'END',0
k_rem:	db	'REM',0
k_list:	db	'LIST',0
k_run:	db	'RUN',0
k_new:	db	'NEW',0
k_bye:	db	'BYE',0
kwtab:	dw	k_print, do_print
	dw	k_let, do_let
	dw	k_input, do_input
	dw	k_if, do_if
	dw	k_goto, do_goto
	dw	k_gosub, do_gosub
	dw	k_return, do_return
	dw	k_end, do_end
	dw	k_rem, do_rem
	dw	k_list, do_list
	dw	k_run, do_run
	dw	k_new, do_new
	dw	k_bye, do_bye
	dw	0, 0
ibuf:	db	78,0
	times 90 db 0
ibuf2:	db	78,0
	times 90 db 0

section .bss
mainsp:	resw	1
seed:	resw	1
cur:	resw	1
curnum:	resw	1
nextp:	resw	1
progend: resw	1
gsp:	resw	1
gstack:	resw	16
vars:	resw	26
prog:	resb	1
