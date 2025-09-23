#include "stat.h"
#include "syscall_enum.h"
#include "syscall.h"
#define ST (size_t)

int stat(const char* path, Stat *statbuf) {
	return syscall(SYS_stat, ST path, ST statbuf, 0, 0, 0, 0);
}
int fstat(int fd, Stat *statbuf) {
	return syscall(SYS_fstat, fd, ST statbuf, 0, 0, 0, 0);
}
int lstat(const char* path, Stat *statbuf) {
	return syscall(SYS_lstat, ST path, ST statbuf, 0, 0, 0, 0);
}

int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf) {
	return syscall(SYS_statx, dirfd, ST pathname, flags, mask, ST statbuf, 0);
}
