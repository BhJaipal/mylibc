#ifndef FILE_H
#define FILE_H
#include "types/struct_file.h"
#include "format.h"
#include "syscall.h"
#include "types.h"

EXPORT
File* fopen(char *path, char *modes);
int printf(const char *fmt, ...);
int fprintf(File *file, const char *fmt, ...);
void fwrite(File *file, const char *buffer, size_t n);
void fclose(File *file);
EXPORT_END

#endif // !FILE_H
