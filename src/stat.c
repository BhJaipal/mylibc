#include "stat.h"
#include "syscall_enum.h"
#include "syscall.h"
#define ST (size_t)

int stat(const char* path, Stat *statbuf) {
	SYSCALL(return, SYS_stat, ST path, ST statbuf);
}
int fstat(int fd, Stat *statbuf) {
	SYSCALL(return, SYS_fstat, fd, ST statbuf);
}
int lstat(const char* path, Stat *statbuf) {
	SYSCALL(return, SYS_lstat, ST path, ST statbuf);
}

int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf) {
	SYSCALL(return, SYS_statx, dirfd, ST pathname, flags, mask, ST statbuf);
}
