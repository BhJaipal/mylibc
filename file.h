#ifndef FILE_H
#define FILE_H
#include "libc_struct/file.h"
#include "format.h"
#include "types.h"

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


extern void read(int fd, char *msg, int len);
extern void write(int fd, const char *msg, int len);
extern int open(const char *path, FileOpenFlags flags, ...);
extern void close(int fd);
extern int pread(unsigned int fd, char *buf, size_t count, size_t pos);
extern int pwrite(unsigned int fd, char *buf, size_t count, size_t pos);

extern void dprintf(int fd, const char *fmt, ...);
extern File* fopen(char *path, char *modes);
extern void printf(const char *fmt, ...);
extern void fprintf(File *file, const char *fmt, ...);
extern void fwrite(File *file, const char *buffer, size_t n);
extern void fclose(File *file);

#endif // !FILE_H
