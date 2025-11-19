#ifndef SYS_WAIT_H
#define SYS_WAIT_H

#include "../types.h"

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
	/* linux extentions, but useful */
	long	ru_maxrss;
	long	ru_ixrss;
	long	ru_idrss;
	long	ru_isrss;
	long	ru_minflt;
	long	ru_majflt;
	long	ru_nswap;
	long	ru_inblock;
	long	ru_oublock;
	long	ru_msgsnd;
	long	ru_msgrcv;
	long	ru_nsignals;
	long	ru_nvcsw;
	long	ru_nivcsw;
	/* room for more... */
	long    __reserved[16];
};

pid_t wait4(pid_t pid, int *status, int options, struct rusage *ru);
inline pid_t waitpid(pid_t pid, int *status, int options) {
	return wait4(pid, status, options, 0);
}
inline pid_t wait(int *status) {
	return wait4((pid_t)-1, status, 0, 0);
}

#endif // !SYS_WAIT_H
