#ifndef FILE_H
#define FILE_H
#include "libc_struct/file.h"
#include "format.h"
#include "syscall.h"
#include "types.h"

EXPORT
typedef enum {
	O_ACCMODE= 0003,
	O_RDONLY= 00,
	O_WRONLY= 01,
	O_RDWR= 02,
	O_CREAT= 0100,
	O_EXCL= 0200,
	O_NOCTTY= 0400,
	O_TRUNC= 01000,
	O_APPEND= 02000,
	O_NONBLOCK= 04000,
	O_NDELAY= O_NONBLOCK,
	O_SYNC= 04010000,
	O_FSYNC= O_SYNC,
	O_ASYNC= 020000,
	__O_LARGEFILE= 0100000,
	__O_DIRECTORY= 0200000,
	__O_NOFOLLOW= 0400000,
	__O_CLOEXEC= 02000000,
	__O_DIRECT= 040000,
	__O_NOATIME= 01000000,
	__O_PATH= 010000000,
	__O_DSYNC= 010000,
	__O_TMPFILE= (020000000 | __O_DIRECTORY)
} FileOpenFlags;


int read(int fd, char *msg, int len);
int write(int fd, const char *msg, int len);
int open(const char *path, FileOpenFlags flags, ...);
void close(int fd);
int pread(unsigned int fd, char *buf, size_t count, size_t pos);
int pwrite(unsigned int fd, char *buf, size_t count, size_t pos);

void dprintf(int fd, const char *fmt, ...);
File* fopen(char *path, char *modes);
void printf(const char *fmt, ...);
void fprintf(File *file, const char *fmt, ...);
void fwrite(File *file, const char *buffer, size_t n);
void fclose(File *file);
EXPORT_END

#endif // !FILE_H
