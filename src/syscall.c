#include "syscall.h"
#include "syscall_enum.h"

void exit(int status) {
	syscall(SYS_exit, status, 0, 0, 0, 0, 0);
	__builtin_unreachable();
}
size_t syscall(long rax, long rdi, long rsi, long rdx, long r10, long r8, long r9) {
	asm("mov %0, %%"RDI"\n"::"r"(rdi));
	asm("mov %0, %%"RSI"\n"::"r"(rsi));
	asm("mov %0, %%"RDX"\n"::"r"(rdx));
	asm("mov %0, %%"R10"\n"::"r"(r10));
	asm("mov %0, %%"R8"\n"::"r"(r8));
	asm("mov %0, %%"R9"\n"::"r"(r9));

	size_t out;
#if defined __x86_64 || defined __x86_64__
	asm("mov %0, %%rax\n"::"r"(rax));
	asm("\nsyscall\n");
	asm("mov %%rax, %0\n":"=r"(out));
#else
	asm("mov %0, %%eax\n"::"r"(rax));
	asm("\nint 0x80\n");
	asm("mov %%eax, %0\n":"=r"(out));
#endif
	return out;
}
int poll(struct pollfd *ufds, uint64 __nfds, int __timeout) {
	return syscall(SYS_poll, (size_t)ufds, __nfds, __timeout, 0, 0, 0);
}
int lseek(uint64 fd, int64 offset, uint32 whence) {
	return syscall(SYS_lseek, fd, offset, whence, 0, 0, 0);
}
