	.file	"getint.c"
	.text
	.globl	getint
	.type	getint, @function
getint:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	nop
.L2:
	call	__ctype_b_loc@PLT
	movq	(%rax), %rbx
	call	getch@PLT
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	cltq
	addq	%rax, %rax
	addq	%rbx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$8192, %eax
	testl	%eax, %eax
	jne	.L2
	call	__ctype_b_loc@PLT
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L3
	cmpl	$-1, -24(%rbp)
	je	.L3
	cmpl	$43, -24(%rbp)
	je	.L3
	cmpl	$45, -24(%rbp)
	je	.L3
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	ungetch@PLT
	movl	$0, %eax
	jmp	.L4
.L3:
	cmpl	$45, -24(%rbp)
	jne	.L5
	movl	$-1, %eax
	jmp	.L6
.L5:
	movl	$1, %eax
.L6:
	movl	%eax, -20(%rbp)
	cmpl	$43, -24(%rbp)
	je	.L7
	cmpl	$45, -24(%rbp)
	jne	.L8
.L7:
	call	getch@PLT
	movl	%eax, -24(%rbp)
.L8:
	movq	-40(%rbp), %rax
	movl	$0, (%rax)
	jmp	.L9
.L10:
	movq	-40(%rbp), %rax
	movl	(%rax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-24(%rbp), %eax
	subl	$48, %eax
	addl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	call	getch@PLT
	movl	%eax, -24(%rbp)
.L9:
	call	__ctype_b_loc@PLT
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L10
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	imull	-20(%rbp), %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	cmpl	$-1, -24(%rbp)
	je	.L11
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	ungetch@PLT
.L11:
	movl	-24(%rbp), %eax
.L4:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	getint, .-getint
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
