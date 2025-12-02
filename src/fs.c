#include <fs.h>
#include <syscall_enum.h>
#include <syscall.h>

size_t getdents64(int fd, linux_dirent *dirp, size_t count) {
	SYSCALL(return , SYS_getdents64, fd, (size_t)dirp, count);
}

size_t getdents(int fd, linux_dirent *dirp, size_t count) {
	SYSCALL(return , SYS_getdents, fd, (size_t)dirp, count);
}
