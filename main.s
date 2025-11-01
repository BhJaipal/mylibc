	.file	"main.cpp"
	.text
	.section	.text._ZNSt4HeapC2Eiii,"axG",@progbits,_ZNSt4HeapC5Eiii,comdat
	.align 2
	.weak	_ZNSt4HeapC2Eiii
	.type	_ZNSt4HeapC2Eiii, @function
_ZNSt4HeapC2Eiii:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movl	-16(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 4(%rax)
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	_ZNSt4HeapC2Eiii, .-_ZNSt4HeapC2Eiii
	.weak	_ZNSt4HeapC1Eiii
	.set	_ZNSt4HeapC1Eiii,_ZNSt4HeapC2Eiii
	.section	.rodata
.LC0:
	.string	"Jai\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	$5, -4(%rbp)
	leaq	-48(%rbp), %rax
	movl	$-1, %ecx
	movl	$34, %edx
	movl	$3, %esi
	movq	%rax, %rdi
	call	_ZNSt4HeapC1Eiii@PLT
	leaq	-80(%rbp), %rax
	leaq	-48(%rbp), %rcx
	movl	$5, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4Heap5allocIcEESt9pointer_tIT_Em@PLT
	leaq	-80(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt9pointer_tIcE9overwriteEPKc@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9pointer_tIcE11raw_mut_ptrEv@PLT
	movq	%rax, %rdi
	call	print@PLT
	movl	$3, %edi
	call	exit@PLT
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.section	.text._ZNSt9pointer_tIcE9overwriteEPKc,"axG",@progbits,_ZNSt9pointer_tIcE9overwriteEPKc,comdat
	.align 2
	.weak	_ZNSt9pointer_tIcE9overwriteEPKc
	.type	_ZNSt9pointer_tIcE9overwriteEPKc, @function
_ZNSt9pointer_tIcE9overwriteEPKc:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_ZNSt9pointer_tIcE9overwriteEPKc, .-_ZNSt9pointer_tIcE9overwriteEPKc
	.section	.text._ZNSt9pointer_tIcE11raw_mut_ptrEv,"axG",@progbits,_ZNSt9pointer_tIcE11raw_mut_ptrEv,comdat
	.align 2
	.weak	_ZNSt9pointer_tIcE11raw_mut_ptrEv
	.type	_ZNSt9pointer_tIcE11raw_mut_ptrEv, @function
_ZNSt9pointer_tIcE11raw_mut_ptrEv:
.LFB17:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	_ZNSt9pointer_tIcE11raw_mut_ptrEv, .-_ZNSt9pointer_tIcE11raw_mut_ptrEv
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
