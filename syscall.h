#ifndef MY_SYSCALL_H
#define MY_SYSCALL_H
#include "types.h"

#define SYSCALL(NR, n, ...) syscall(NR, n, (size_t[n]){__VA_ARGS__})

size_t syscall(size_t rax, int nargs, size_t *args);

void exit(int status);

#endif // !MY_SYSCALL_H
