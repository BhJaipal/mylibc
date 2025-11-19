#include <sys/wait.h>
#include <syscall_enum.h>
#include <syscall.h>

pid_t wait4(pid_t pid, int *status, int options, struct rusage *ru) {
	SYSCALL(return , SYS_wait4, pid, (size_t)status, options, (size_t)ru);
}
