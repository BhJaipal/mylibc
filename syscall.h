#ifndef MY_SYSCALL_H
#define MY_SYSCALL_H
#include "types.h"

size_t syscall(long rax, long rdi, long rsi, long rdx, long r10, long r8, long r9);

void exit(int status);

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
#else
#define RAX "eax"
#define RDI "ebx"
#define RSI "ecx"
#define RDX "edx"
#define R10 "esi"
#define R8  "edi"
#define R9  "ebp"
#endif

#endif // !MY_SYSCALL_H
