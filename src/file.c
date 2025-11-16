#include "file.h"
#include "syscall.h"
#include "syscall_enum.h"
#include "stat.h"
#include <string.h>
#include <stdarg.h>

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

File* fopen(char *path, char *modes) {
	FileOpenFlags flags;
	for (size_t i = 0; i < strlen(modes); i++) {
		if (modes[i] == 'r') {
			if (flags & O_WRONLY) {
				flags = O_RDWR & O_CREAT;
			} else if (flags & O_APPEND) {
				flags |= O_RDONLY;
			} else {
				flags = O_RDONLY;
			}
		} else if (modes[i] == 'w') {
			if (flags & O_RDONLY) {
				flags = O_RDWR | O_CREAT;
			} else {
				flags = O_CREAT | O_WRONLY;
			}
		} else if (modes[i] == 'a') {
			if (flags & O_RDONLY) {
				flags = O_APPEND | O_CREAT | O_RDONLY;
			} else {
				flags = O_CREAT | O_APPEND;
			}
		} else if (modes[i] == '+') {
			if (flags & O_RDONLY) {
				flags = O_RDWR | O_CREAT | O_RDONLY;
			} else {
				flags = O_CREAT | O_APPEND | O_RDONLY;
			}
		}
	}

	long fd;
	SYSCALL(fd = , SYS_open, ST path, flags, 0444, 0, 0, 0);
	if (fd < 0) return null;

	File *file = malloc(sizeof(File));
	file->fd = fd;
	Stat statb;
	fstat(fd, &statb);

	file->file_size = statb.st_size;
	read(fd, file->file_start, statb.st_size);
	file->current_pos = file->file_start;
	return file;
}
void printf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char *out = format_args(fmt, args);
	va_end(args);
	print(out);
	free(out);
}
void dprintf(int fd, const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char *out = format_args(fmt, args);
	va_end(args);
	size_t out_len = strlen(out);
	write(fd, out, out_len);
}
void fprintf(File *file, const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char *out = format_args(fmt, args);
	va_end(args);
	size_t out_len = strlen(out);
	write(file->fd, out, out_len);
	file->file_size = out_len;
	free(file->file_start);
	file->file_start = out;
	file->current_pos = out;
}
void fwrite(File *file, const char *buffer, size_t n) {
	write(file->fd, buffer, n);
}
void fclose(File *file) {
	close(file->fd);
	free(file->file_start);
	free(file);
	file = null;
}
