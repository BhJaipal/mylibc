#ifndef MY_FORMAT_H
#define MY_FORMAT_H

#include "c-impl.h"
#include "malloc.h"
#include "stdarg.h"
#include "syscall.h"

EXPORT
char* format(const char *str, ...);
char* format_args(const char *str, va_list args);
char* formatn(const char *str, size_t n, ...);
char* formatn_args(const char *str, size_t n, va_list args);
// use for va_args
size_t get_value(int loc);
EXPORT_END

#endif // !MY_FORMAT_H
