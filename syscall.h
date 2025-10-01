#ifndef MY_SYSCALL_H
#define MY_SYSCALL_H
#include "types.h"

#define SYSCALL(ret, rax, ...) \
	size_t argv[] = {__VA_ARGS__, 0, 0, 0, 0, 0};\
	ret syscall(rax, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);

size_t syscall(long rax, long rdi, long rsi, long rdx, long r10, long r8, long r9);

extern void exit(int status);
extern int kill(int pid, int sig);
extern int getpid();
extern int pause();
extern int alarm(uint32 seconds);
extern int vfork();
extern int fork();
extern int execve(const char *filename, const char *const *argv, const char *const *envp);

/* Data structure describing a polling request.  */
struct pollfd {
    int fd;			/* File descriptor to poll.  */
    int16 events;		/* Types of events poller cares about.  */
	int16 revents;		/* Types of events that actually occurred.  */
};

extern int poll(struct pollfd *ufds, uint64 __nfds, int __timeout);
extern int lseek(uint64 fd, int64 offset, uint32 whence);

#if defined __x86_64 || defined __x86_64__
#define RAX "rax"
#define RDI "rdi"
#define RSI "rsi"
#define RDX "rdx"
#define R10 "r10"
#define R8   "r8"
#define R9   "r9"
#define SYSCALL_EXEC asm("syscall\n");
#else
#define RAX "eax"
#define RDI "ebx"
#define RSI "ecx"
#define RDX "edx"
#define R10 "esi"
#define R8  "edi"
#define R9  "ebp"
#define SYSCALL_EXEC asm("\nint 0x80\n");
#endif

#define MOV(dest_reg, src_val) \
	asm("mov %0, %%" dest_reg "\n"::"r"(src_val));

#endif // !MY_SYSCALL_H
