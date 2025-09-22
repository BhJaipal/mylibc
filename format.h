#ifndef MY_FORMAT_H
#define MY_FORMAT_H

#include "c-impl.h"
#include "malloc.h"
#include "stdarg.h"

extern char* format(const char *str, ...);
extern char* format_args(const char *str, va_list args);
extern char* formatn(const char *str, size_t n, ...);
extern char* formatn_args(const char *str, size_t n, va_list args);
// use for va_args
extern size_t get_value(int loc);

#endif // !MY_FORMAT_H
