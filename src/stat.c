#include "stat.h"
#include "syscall_enum.h"
#include "syscall.h"
#define ST (size_t)

int stat(const char* path, Stat *statbuf) {
	return SYSCALL(SYS_stat, 2, ST path, ST statbuf);
}
int fstat(int fd, Stat *statbuf) {
	return SYSCALL(SYS_fstat, 2, fd, ST statbuf);
}
int lstat(const char* path, Stat *statbuf) {
	return SYSCALL(SYS_lstat, 2, ST path, ST statbuf);
}

int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf) {
	return SYSCALL(SYS_statx, 5, dirfd, ST pathname, flags, mask, ST statbuf);
}
