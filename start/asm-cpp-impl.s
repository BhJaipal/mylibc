	.text
	.globl _start
	.type _start, @function

_start:
	pop %rdi
	mov %rsp, %rsi
	sub $0x18, %rsp
	call _Z10_libc_mainlPPc
