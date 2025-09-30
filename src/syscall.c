#include "syscall.h"
#include "syscall_enum.h"

size_t syscall(long rax, long rdi, long rsi, long rdx, long r10, long r8, long r9) {
	asm("mov %0, %%"RDI"\n"::"r"(rdi));
	asm("mov %0, %%"RSI"\n"::"r"(rsi));
	asm("mov %0, %%"RDX"\n"::"r"(rdx));
	asm("mov %0, %%"R10"\n"::"r"(r10));
	asm("mov %0, %%"R8"\n"::"r"(r8));
	asm("mov %0, %%"R9"\n"::"r"(r9));

	size_t out;
	asm("mov %0, %%"RAX"\n"::"r"(rax));
	SYSCALL_EXEC;
	asm("mov %%"RAX", %0\n":"=r"(out));
	return out;
}

#define SYSCALL(ret, rax, ...)				\
	size_t argv[] = {__VA_ARGS__};			\
	size_t n = sizeof(argv)/sizeof(size_t); \
	if (n > 0) MOV(RDI, argv[0])			\
	if (n > 1) MOV(RSI, argv[1])			\
	if (n > 2) MOV(RDX, argv[2])			\
	if (n > 3) MOV(R10, argv[3])			\
	if (n > 4) MOV(R8, argv[4]) 			\
	if (n > 5) MOV(R9, argv[5]) 			\
	size_t __rax = rax; 					\
	asm("mov %0, %%"RAX::"r"(__rax));		\
	SYSCALL_EXEC							\
	size_t _out;							\
	asm("mov %%"RAX", %0\n":"=r"(_out));	\
	ret _out;

void exit(int status) {
	SYSCALL(, SYS_exit, status);
	__builtin_unreachable();
}
int poll(struct pollfd *ufds, uint64 __nfds, int __timeout) {
	SYSCALL(return, SYS_poll, (size_t)ufds, __nfds, __timeout);
}
int lseek(uint64 fd, int64 offset, uint32 whence) {
	SYSCALL(return, SYS_lseek, fd, offset, whence);
}

int vfork() {
	SYSCALL(return, SYS_vfork);
}

int fork() {
	SYSCALL(return, SYS_fork);
}
int alarm(uint32 seconds) {
	SYSCALL(return, SYS_alarm, seconds);
}
int pause() {
	SYSCALL(return, SYS_pause);
}

int getpid() {
	SYSCALL(return, SYS_getpid);
}

int kill(int pid, int sig) {
	SYSCALL(return, SYS_kill, pid, sig);
}
