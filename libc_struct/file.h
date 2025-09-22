#ifndef LIBC_STRUCT_H
#define LIBC_STRUCT_H
#include "../types.h"

typedef struct {
	int fd;
	char *file_start;
	char *current_pos;
	size_t file_size;
} File;

#endif // !LIBC_STRUCT_H
