#ifndef MY_STDARG_H
#define MY_STDARG_H

#define va_start(...) __builtin_va_start(__VA_ARGS__)
#define va_arg(v, l) __builtin_va_arg(v, l)
#define va_end(v) __builtin_va_end(v)
typedef __builtin_va_list va_list;

#endif // !MY_STDARG_H
