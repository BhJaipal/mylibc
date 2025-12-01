#ifndef SYS_POLL_H
#define SYS_POLL_H

#include "../types.h"

/* Data structure describing a polling request.  */
struct pollfd {
    int fd;			/* File descriptor to poll.  */
    int16 events;		/* Types of events poller cares about.  */
	int16 revents;		/* Types of events that actually occurred.  */
};

extern int poll(struct pollfd *ufds, uint64 __nfds, int __timeout);

#endif // !SYS_POLL_H
