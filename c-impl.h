#ifndef C_IMPL
#define C_IMPL

#include "types.h"

extern int rev_d(int x);
extern char* i64to_str(int64 x, uint8 size, char *out);
extern uint32 rev_u(uint32 x);
extern char* u64to_str(uint64 x, uint8 size, char *out);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(uint32 x);
extern uint32 read_uint();
extern void write_int(int x);
extern int read_int();

extern void print(const char *str);

extern void println(const char *str);

#endif // !C_IMPL
