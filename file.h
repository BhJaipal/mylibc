#ifndef FILE_H
#define FILE_H
#include "libc_enum.h"

void read(int fd, char *msg, int len);
void write(int fd, const char *msg, int len);
int open(const char *path, FileOpenFlags flags, ...);
void close(int fd);

#endif // !FILE_H
