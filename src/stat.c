#include "stat.h"
#include "syscall.h"
#define ST (size_t)

int stat(const char* path, Stat *statbuf) {
	return SYSCALL(4, 2, ST path, ST statbuf);
}
int fstat(int fd, Stat *statbuf) {
	return SYSCALL(5, 2, fd, ST statbuf);
}
int lstat(const char* path, Stat *statbuf) {
	return SYSCALL(6, 2, ST path, ST statbuf);
}

int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf) {
	return SYSCALL(3, 5, dirfd, ST pathname, flags, mask, ST statbuf);
}
