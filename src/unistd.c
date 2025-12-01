#include "types/struct_stat.h"
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <syscall_enum.h>
#include <unistd.h>
#include <syscall.h>

pid_t wait4(pid_t pid, int *status, int options, struct rusage *ru) {
	SYSCALL(return , SYS_wait4, pid, (size_t)status, options, (size_t)ru);
}

char* getcwd(char *buf, size_t size) {
	char tmp[buf ? 1 : PATH_MAX];
	if (!buf) {
		buf = tmp;
		size = sizeof tmp;
	} else if (!size) {
		return 0;
	}
	SYSCALL(long ret = , SYS_getcwd, (size_t)buf, size);
	if (ret <= 0)
		return 0;

	return buf == tmp ? strdup(buf) : buf;
}
int chdir(const char *path) {
	SYSCALL(return , SYS_chdir, (size_t)path);
}

char *get_current_dir_name(void) {
	Stat a, b;
	char *res = getenv("PWD");
	if (res && *res && !stat(res, &a) && !stat(".", &b)
	    && (a.st_dev == b.st_dev) && (a.st_ino == b.st_ino))
		return strdup(res);
	return getcwd(0, 0);
}
