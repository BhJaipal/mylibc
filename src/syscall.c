#include "syscall.h"

void exit(int status) {
	SYSCALL(60, 1, status);
	__builtin_unreachable();
}
size_t syscall(size_t rax, int nargs, size_t *args) {
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
	return out;
}
