#include "file.h"
#include "syscall.h"
#include "syscall_enum.h"
#include "stat.h"
#include <string.h>
#include <stdarg.h>

#define ST (size_t)

void read(int fd, char *msg, int len) {
	syscall(SYS_read, fd, ST msg, len, 0, 0, 0);
}
void write(int fd, const char *msg, int len) {
	syscall(SYS_write, fd, ST msg, len, 0, 0, 0);
}
int open(const char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		fd = syscall(SYS_open, ST path, flags, 0444, 0, 0, 0);
	} else {
		fd = syscall(SYS_open, ST path, flags, fd, 0, 0, 0);
	}
	return fd;
}
void close(int fd) {
	syscall(SYS_close, fd, 0, 0, 0, 0, 0);
}

File* fopen(char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		fd = syscall(SYS_open, ST path, flags, 0444, 0, 0, 0);
	} else {
		fd = syscall(SYS_open, ST path, flags, fd, 0, 0, 0);
	}
	if (fd) return null;

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
