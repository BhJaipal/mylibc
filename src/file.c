#include "file.h"
#include "syscall.h"
#define ST (size_t)

void read(int fd, char *msg, int len) {
	SYSCALL(0, 3, fd, ST msg, len);
}
void write(int fd, const char *msg, int len) {
	SYSCALL(1, 3, fd, ST msg, len);
}
int open(const char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		fd = SYSCALL(2, 3, ST path, flags, 0444);
	} else {
		fd = SYSCALL(2, 3, ST path, flags, fd);
	}
	return fd;
}
void close(int fd) {
	SYSCALL(3, 1, fd);
}
