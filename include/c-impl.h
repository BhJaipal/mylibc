#ifndef C_IMPL
#define C_IMPL

#include "types.h"
#include "syscall.h"

EXPORT


int isspace(int a);
int isdigit(int a);
int atoi(const char *s);

int rev_d(int x);
char* i64to_str(int64 x, uint8 size, char *out);
uint32 rev_u(uint32 x);
char* u64to_str(uint64 x, uint8 size, char *out);
char* ptr_to_str(void *ptr, char *out);
char* hex_lower_to_str(size_t x, char *out);
char* hex_upper_to_str(size_t x, char *out);
char* octal_to_str(size_t x, char *out);

/* C implementation */
void putchar(char c);
int pow(int b, int e);
void write_uint(uint32 x);
uint32 read_uint();
void write_int(int x);
int read_int();

void print(const char *str);

void println(const char *str);
EXPORT_END

#endif // !C_IMPL
