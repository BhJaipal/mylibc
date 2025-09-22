#include "syscall.h"
#include "syscall_enum.h"
size_t syscall(size_t rax, int nargs, size_t *args) {
#if defined __x86_64__ || defined __x86_64
	if (nargs >= 1) {
		asm("mov %0, %%rdi\n"::"r"(args[0]));
	}
	if (nargs >= 2) {
		asm("mov %0, %%rsi\n"::"r"(args[1]));
	}
	if (nargs >= 3) {
		asm("mov %0, %%rdx\n"::"r"(args[2]));
	}
	if (nargs >= 4) {
		asm("mov %0, %%r10\n"::"r"(args[3]));
	}
	if (nargs >= 5) {
		asm("mov %0, %%r8\n"::"r"(args[4]));
	}
	if (nargs >= 6) {
		asm("mov %0, %%r9\n"::"r"(args[5]));
	}
	size_t out;
	asm("mov %0, %%rax"::"r"(rax));
	asm("syscall\n");
	asm("mov %%rax, %0\n":"=r"(out));
#else
	if (nargs >= 1) {
		asm("mov %0, %%ebx\n"::"r"(args[0]));
	}
	if (nargs >= 2) {
		asm("mov %0, %%ecx\n"::"r"(args[1]));
	}
	if (nargs >= 3) {
		asm("mov %0, %%edx\n"::"r"(args[2]));
	}
	if (nargs >= 4) {
		asm("mov %0, %%esi\n"::"r"(args[3]));
	}
	if (nargs >= 5) {
		asm("mov %0, %%edi\n"::"r"(args[4]));
	}
	if (nargs >= 6) {
		asm("mov %0, %%ebp\n"::"r"(args[5]));
	}
	size_t out;
	asm("mov %0, %%eax"::"r"(rax));
	asm("int 0x80\n");
	asm("mov %%eax, %0\n":"=r"(out));
#endif
	return out;
}
int poll(struct pollfd *ufds, uint64 __nfds, int __timeout) {
	return SYSCALL(SYS_poll, 3, (size_t)ufds, __nfds, __timeout);
}
int lseek(uint64 fd, int64 offset, uint32 whence) {
	return SYSCALL(SYS_lseek, 3, fd, offset, whence);
}

void exit(int status) {
	SYSCALL(SYS_exit, 1, status);
	__builtin_unreachable();
}
