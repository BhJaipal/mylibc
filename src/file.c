#include "file.h"
#include "syscall.h"
#include "syscall_enum.h"
#define ST (size_t)

void read(int fd, char *msg, int len) {
	SYSCALL(SYS_read, 3, fd, ST msg, len);
}
void write(int fd, const char *msg, int len) {
	SYSCALL(SYS_write, 3, fd, ST msg, len);
}
int open(const char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		fd = SYSCALL(SYS_open, 3, ST path, flags, 0444);
	} else {
		fd = SYSCALL(SYS_open, 3, ST path, flags, fd);
	}
	return fd;
}
void close(int fd) {
	SYSCALL(SYS_close, 1, fd);
}
