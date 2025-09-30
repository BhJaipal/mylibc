	.file	"syscall.c"
	.text
.Ltext0:
	.file 0 "/home/jaipal001/myglibc" "src/syscall.c"
	.globl	syscall
	.type	syscall, @function
syscall:
.LFB0:
	.file 1 "src/syscall.c"
	.loc 1 7 84
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	%r9, -64(%rbp)
	.loc 1 8 2
	movq	-32(%rbp), %rax
#APP
# 8 "src/syscall.c" 1
	mov %rax, %rdi

# 0 "" 2
	.loc 1 9 2
#NO_APP
	movq	-40(%rbp), %rax
#APP
# 9 "src/syscall.c" 1
	mov %rax, %rsi

# 0 "" 2
	.loc 1 10 2
#NO_APP
	movq	-48(%rbp), %rax
#APP
# 10 "src/syscall.c" 1
	mov %rax, %rdx

# 0 "" 2
	.loc 1 11 2
#NO_APP
	movq	-56(%rbp), %rax
#APP
# 11 "src/syscall.c" 1
	mov %rax, %r10

# 0 "" 2
	.loc 1 12 2
#NO_APP
	movq	-64(%rbp), %rax
#APP
# 12 "src/syscall.c" 1
	mov %rax, %r8

# 0 "" 2
	.loc 1 13 2
#NO_APP
	movq	16(%rbp), %rax
#APP
# 13 "src/syscall.c" 1
	mov %rax, %r9

# 0 "" 2
	.loc 1 17 2
#NO_APP
	movq	-24(%rbp), %rax
#APP
# 17 "src/syscall.c" 1
	mov %rax, %rax

# 0 "" 2
	.loc 1 18 2
# 18 "src/syscall.c" 1
	
syscall

# 0 "" 2
	.loc 1 19 2
# 19 "src/syscall.c" 1
	mov %rax, %rax

# 0 "" 2
#NO_APP
	movq	%rax, -8(%rbp)
	.loc 1 25 9
	movq	-8(%rbp), %rax
	.loc 1 26 1
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	syscall, .-syscall
	.globl	syscall_rax
	.type	syscall_rax, @function
syscall_rax:
.LFB1:
	.loc 1 27 22
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 29 2
#APP
# 29 "src/syscall.c" 1
	
syscall

# 0 "" 2
	.loc 1 34 2
# 34 "src/syscall.c" 1
	mov %rax, %rax

# 0 "" 2
#NO_APP
	movq	%rax, -8(%rbp)
	.loc 1 35 9
	movq	-8(%rbp), %rax
	.loc 1 36 1
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	syscall_rax, .-syscall_rax
	.globl	exit
	.type	exit, @function
exit:
.LFB2:
	.loc 1 50 23
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$24, %rsp
	movl	%edi, -20(%rbp)
	.loc 1 51 2
	movl	-20(%rbp), %eax
	cltq
	movq	%rax, -16(%rbp)
	movq	$1, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L6
	.loc 1 51 2 is_stmt 0 discriminator 1
	movq	-16(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %rdi

# 0 "" 2
#NO_APP
.L6:
	.loc 1 51 2 discriminator 3
	cmpq	$1, -8(%rbp)
	jbe	.L7
	.loc 1 51 2 discriminator 4
	movq	-8(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %rsi

# 0 "" 2
#NO_APP
.L7:
	.loc 1 51 2 discriminator 6
	cmpq	$2, -8(%rbp)
	jbe	.L8
	.loc 1 51 2 discriminator 7
	movq	0(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %rdx

# 0 "" 2
#NO_APP
.L8:
	.loc 1 51 2 discriminator 9
	cmpq	$3, -8(%rbp)
	jbe	.L9
	.loc 1 51 2 discriminator 10
	movq	8(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %r10

# 0 "" 2
#NO_APP
.L9:
	.loc 1 51 2 discriminator 12
	cmpq	$4, -8(%rbp)
	jbe	.L10
	.loc 1 51 2 discriminator 13
	movq	16(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %r8

# 0 "" 2
#NO_APP
.L10:
	.loc 1 51 2 discriminator 15
	cmpq	$5, -8(%rbp)
	jbe	.L11
	.loc 1 51 2 discriminator 16
	movq	24(%rbp), %rax
#APP
# 51 "src/syscall.c" 1
	mov %rax, %r9

# 0 "" 2
#NO_APP
.L11:
	.loc 1 51 2 discriminator 18
	movl	$60, %eax
#APP
# 51 "src/syscall.c" 1
	mov $%eax, %rax

# 0 "" 2
#NO_APP
	movl	$0, %eax
	call	syscall_rax
	.cfi_endproc
.LFE2:
	.size	exit, .-exit
	.globl	poll
	.type	poll, @function
poll:
.LFB3:
	.loc 1 54 61 is_stmt 1
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$24, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	.loc 1 55 9
	movl	-20(%rbp), %eax
	movslq	%eax, %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movq	%rax, %rsi
	movl	$7, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 56 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	poll, .-poll
	.globl	lseek
	.type	lseek, @function
lseek:
.LFB4:
	.loc 1 57 51
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$24, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	.loc 1 58 9
	movl	-20(%rbp), %ecx
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movq	%rax, %rsi
	movl	$8, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 59 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	lseek, .-lseek
	.globl	vfork
	.type	vfork, @function
vfork:
.LFB5:
	.loc 1 61 13
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 62 9
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$58, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 63 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	vfork, .-vfork
	.globl	fork
	.type	fork, @function
fork:
.LFB6:
	.loc 1 65 12
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 66 9
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$57, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 67 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	fork, .-fork
	.globl	alarm
	.type	alarm, @function
alarm:
.LFB7:
	.loc 1 68 27
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
	.loc 1 69 9
	movl	-4(%rbp), %eax
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$37, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 70 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	alarm, .-alarm
	.globl	pause
	.type	pause, @function
pause:
.LFB8:
	.loc 1 71 13
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 72 9
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$34, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 73 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	pause, .-pause
	.globl	getpid
	.type	getpid, @function
getpid:
.LFB9:
	.loc 1 75 14
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 76 9
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$39, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 77 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	getpid, .-getpid
	.globl	kill
	.type	kill, @function
kill:
.LFB10:
	.loc 1 79 28
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	.loc 1 80 9
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4(%rbp), %eax
	cltq
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movq	%rax, %rsi
	movl	$62, %edi
	call	syscall
	addq	$8, %rsp
	.loc 1 81 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	kill, .-kill
.Letext0:
	.file 2 "./types.h"
	.file 3 "./syscall.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x35d
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0x9
	.long	.LASF34
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF2
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF3
	.uleb128 0x4
	.long	.LASF6
	.byte	0x9
	.byte	0x1
	.long	0x47
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0xa
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x4
	.long	.LASF7
	.byte	0xa
	.byte	0x1
	.long	0x67
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF8
	.uleb128 0x4
	.long	.LASF9
	.byte	0xb
	.byte	0x1
	.long	0x79
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF10
	.uleb128 0x4
	.long	.LASF11
	.byte	0xb
	.byte	0x1
	.long	0x8b
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF12
	.uleb128 0x4
	.long	.LASF13
	.byte	0xd
	.byte	0x17
	.long	0x8b
	.uleb128 0xb
	.long	.LASF35
	.byte	0x8
	.byte	0x3
	.byte	0x10
	.byte	0x8
	.long	0xcf
	.uleb128 0xc
	.string	"fd"
	.byte	0x3
	.byte	0x11
	.byte	0x9
	.long	0x55
	.byte	0
	.uleb128 0x8
	.long	.LASF14
	.byte	0x12
	.byte	0xb
	.long	0x3c
	.byte	0x4
	.uleb128 0x8
	.long	.LASF15
	.byte	0x13
	.byte	0x8
	.long	0x3c
	.byte	0x6
	.byte	0
	.uleb128 0x5
	.long	.LASF18
	.byte	0x4f
	.long	0x55
	.quad	.LFB10
	.quad	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.long	0x10c
	.uleb128 0x1
	.string	"pid"
	.byte	0x4f
	.byte	0xe
	.long	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1
	.string	"sig"
	.byte	0x4f
	.byte	0x17
	.long	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x6
	.long	.LASF16
	.byte	0x4b
	.long	0x55
	.quad	.LFB9
	.quad	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x6
	.long	.LASF17
	.byte	0x47
	.long	0x55
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x5
	.long	.LASF19
	.byte	0x44
	.long	0x55
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x173
	.uleb128 0x3
	.long	.LASF20
	.byte	0x44
	.byte	0x12
	.long	0x5c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xd
	.long	.LASF36
	.byte	0x1
	.byte	0x41
	.byte	0x5
	.long	0x55
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x6
	.long	.LASF21
	.byte	0x3d
	.long	0x55
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x5
	.long	.LASF22
	.byte	0x39
	.long	0x55
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x1f7
	.uleb128 0x1
	.string	"fd"
	.byte	0x39
	.byte	0x12
	.long	0x80
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3
	.long	.LASF23
	.byte	0x39
	.byte	0x1c
	.long	0x6e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3
	.long	.LASF24
	.byte	0x39
	.byte	0x2b
	.long	0x5c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.byte	0
	.uleb128 0x5
	.long	.LASF25
	.byte	0x36
	.long	0x55
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x242
	.uleb128 0x3
	.long	.LASF26
	.byte	0x36
	.byte	0x19
	.long	0x242
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3
	.long	.LASF27
	.byte	0x36
	.byte	0x26
	.long	0x80
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3
	.long	.LASF28
	.byte	0x36
	.byte	0x32
	.long	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.byte	0
	.uleb128 0xe
	.byte	0x8
	.long	0x9d
	.uleb128 0xf
	.long	.LASF29
	.byte	0x1
	.byte	0x32
	.byte	0x6
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x290
	.uleb128 0x3
	.long	.LASF30
	.byte	0x32
	.byte	0xf
	.long	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x10
	.long	.LASF31
	.byte	0x1
	.byte	0x33
	.byte	0x2
	.long	0x290
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x7
	.string	"n"
	.byte	0x33
	.byte	0x2
	.long	0x92
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x11
	.long	0x92
	.long	0x2a0
	.uleb128 0x12
	.long	0x8b
	.byte	0
	.byte	0
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.byte	0x1b
	.byte	0x8
	.long	0x92
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x2d1
	.uleb128 0x7
	.string	"out"
	.byte	0x21
	.byte	0x9
	.long	0x92
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x14
	.long	.LASF33
	.byte	0x1
	.byte	0x7
	.byte	0x8
	.long	0x92
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1
	.string	"rax"
	.byte	0x7
	.byte	0x15
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x1
	.string	"rdi"
	.byte	0x7
	.byte	0x1f
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x1
	.string	"rsi"
	.byte	0x7
	.byte	0x29
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1
	.string	"rdx"
	.byte	0x7
	.byte	0x33
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x1
	.string	"r10"
	.byte	0x7
	.byte	0x3d
	.long	0x79
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x1
	.string	"r8"
	.byte	0x7
	.byte	0x47
	.long	0x79
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x1
	.string	"r9"
	.byte	0x7
	.byte	0x50
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.string	"out"
	.byte	0xf
	.byte	0x9
	.long	0x92
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 2
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 3
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x87
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF16:
	.string	"getpid"
.LASF13:
	.string	"size_t"
.LASF29:
	.string	"exit"
.LASF33:
	.string	"syscall"
.LASF19:
	.string	"alarm"
.LASF11:
	.string	"uint64"
.LASF28:
	.string	"__timeout"
.LASF26:
	.string	"ufds"
.LASF30:
	.string	"status"
.LASF3:
	.string	"unsigned char"
.LASF36:
	.string	"fork"
.LASF6:
	.string	"int16"
.LASF12:
	.string	"long unsigned int"
.LASF5:
	.string	"short unsigned int"
.LASF18:
	.string	"kill"
.LASF22:
	.string	"lseek"
.LASF14:
	.string	"events"
.LASF7:
	.string	"uint32"
.LASF25:
	.string	"poll"
.LASF8:
	.string	"unsigned int"
.LASF15:
	.string	"revents"
.LASF35:
	.string	"pollfd"
.LASF2:
	.string	"char"
.LASF21:
	.string	"vfork"
.LASF27:
	.string	"__nfds"
.LASF20:
	.string	"seconds"
.LASF32:
	.string	"syscall_rax"
.LASF24:
	.string	"whence"
.LASF23:
	.string	"offset"
.LASF4:
	.string	"short int"
.LASF17:
	.string	"pause"
.LASF31:
	.string	"argv"
.LASF10:
	.string	"long int"
.LASF9:
	.string	"int64"
.LASF34:
	.string	"GNU C17 13.3.0 -mtune=generic -march=x86-64 -g -fasynchronous-unwind-tables -fstack-clash-protection -fcf-protection"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/jaipal001/myglibc"
.LASF0:
	.string	"src/syscall.c"
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
