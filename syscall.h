#ifndef MY_SYSCALL_H
#define MY_SYSCALL_H
#include "types.h"

#define SYSCALL(NR, n, ...) syscall(NR, n, (size_t[n]){__VA_ARGS__})

size_t syscall(size_t rax, int nargs, size_t *args);

void exit(int status);

/* Data structure describing a polling request.  */
struct pollfd {
    int fd;			/* File descriptor to poll.  */
    int16 events;		/* Types of events poller cares about.  */
	int16 revents;		/* Types of events that actually occurred.  */
};

extern int poll(struct pollfd *ufds, uint64 __nfds, int __timeout);
extern int lseek(uint64 fd, int64 offset, uint32 whence);

#endif // !MY_SYSCALL_H
