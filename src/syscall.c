#include <syscall.h>
#include <sys/poll.h>
#include "syscall_enum.h"
#include <net/socket.h>
#define ST (size_t)

size_t syscall(long rdi, long rsi, long rdx, long r10, long r8, long r9, long rax) {
	asm("mov %0, %%"R10"\n"::"r"(r10));

	asm("mov %0, %%"RAX"\n"::"r"(rax));
	SYSCALL_EXEC;
	size_t out;
	asm("mov %%"RAX", %0\n":"=r"(out));
	return out;
}
size_t syscall_ptr(const void *rdi, const void *rsi, const void *rdx, const void *r10, const void *r8, const void *r9, long rax) {
	return syscall((size_t)rdi, (size_t)rsi, (size_t)rdx, (size_t)r10, (size_t)r8, (size_t)r9, rax);
}

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
	SYSCALL(return, SYS_vfork, 0);
}

int fork() {
	SYSCALL(return, SYS_fork, 0);
}
int alarm(uint32 seconds) {
	SYSCALL(return, SYS_alarm, seconds);
}
int pause() {
	SYSCALL(return, SYS_pause, 0);
}

int getpid() {
	SYSCALL(return, SYS_getpid, 0);
}

int kill(int pid, int sig) {
	SYSCALL(return, SYS_kill, pid, sig);
}

int socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol) {
	SYSCALL(return, SYS_socket, domain, type, protocol);
}
int bind(int sockfd, const SocketAddr *addr, socklen_t len) {
	SYSCALL(return, SYS_bind, sockfd, (size_t) addr, len);
}
int listen(int sockfd, int backlog) {
	SYSCALL(return, SYS_listen, sockfd, backlog);
}
int accept(int sockfd, const SocketAddr *addr, socklen_t *len) {
	SYSCALL(return, SYS_accept, sockfd, (size_t) addr, (size_t) len);
}
int execve(const char *filename, const char *const *argv, const char *const *envp) {
	return syscall_ptr(filename, argv, envp, 0, 0, 0, SYS_execve);
}

