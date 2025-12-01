#include <syscall.h>
#include <syscall_enum.h>
#include <io.h>

#define ST (size_t)

int read(int fd, char *msg, int len) {
	SYSCALL(return , SYS_read, fd, ST msg, len);
}
int write(int fd, const char *msg, int len) {
	SYSCALL(return , SYS_write, fd, ST msg, len);
}
int pread(unsigned int fd, char *buf, size_t count, size_t pos) {
	SYSCALL(return, SYS_pread64, fd, ST buf, count, pos);
}
int pwrite(unsigned int fd, char *buf, size_t count, size_t pos) {
	SYSCALL(return, SYS_pwrite64, fd, ST buf, count, pos);
}
int open(const char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		SYSCALL(fd = , SYS_open, ST path, flags, 0444);
	} else {
		SYSCALL(fd = , SYS_open, ST path, flags, fd);
	}
	return fd;
}
void close(int fd) {
	 SYSCALL(, SYS_close, fd);
}
