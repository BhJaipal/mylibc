#ifndef FILE_H
#define FILE_H
#include "libc_enum.h"
#include "libc_struct/file.h"
#include "format.h"
#include "types.h"

extern void read(int fd, char *msg, int len);
extern void write(int fd, uint8 *msg, int len);
extern int open(const char *path, FileOpenFlags flags, ...);
extern void close(int fd);

extern File* fopen(char *path, FileOpenFlags flags, ...);
extern void printf(const char *fmt, ...);
extern void fprintf(File *file, const char *fmt, ...);
extern void fwrite(File *file, uint8 *buffer, size_t n);
extern void fclose(File *file);

#endif // !FILE_H
