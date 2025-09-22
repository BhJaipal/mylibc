#include "file.h"
#include "c-impl.h"
#include "libc_struct/file.h"
#include "libc_struct/stat.h"
#include "syscall.h"
#include "syscall_enum.h"
#include "types.h"
#include "stat.h"
#include <string.h>

#define ST (size_t)

void read(int fd, char *msg, int len) {
	SYSCALL(SYS_read, 3, fd, ST msg, len);
}
void write(int fd, uint8 *msg, int len) {
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

File* fopen(char *path, FileOpenFlags flags, ...) {
	long fd;
	if (!(flags & O_CREAT)) {
		fd = SYSCALL(SYS_open, 3, ST path, flags, 0444);
	} else {
		fd = SYSCALL(SYS_open, 3, ST path, flags, fd);
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
	size_t args[] = {get_value(2), get_value(3), get_value(4), get_value(5), get_value(6)};
	char *out = format_args(fmt, args);
	print(out);
	free(out);
}
void fprintf(File *file, const char *fmt, ...) {
	size_t args[] = {get_value(3), get_value(4), get_value(5), get_value(6)};
	char *out = format_args(fmt, args);
	size_t out_len = strlen(out);
	write(file->fd, (uint8*)out, out_len);
	file->file_size = out_len;
	free(file->file_start);
	file->file_start = out;
	file->current_pos = out;
}
void fwrite(File *file, uint8 *buffer, size_t n) {
	write(file->fd, buffer, n);
}
void fclose(File *file) {
	close(file->fd);
	free(file->file_start);
	free(file);
	file = null;
}
