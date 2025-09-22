#include "c-impl.h"
#include "types.h"
#include "string.h"
#include "malloc.h"

size_t get_value(int loc) {
	size_t out;
	if (loc == 0) {
		asm("mov %%rax, %0":"=r"(out));
	} else if (loc == 1) {
		asm("mov %%rdi, %0":"=r"(out));
	} else if (loc == 2) {
		asm("mov %%rsi, %0":"=r"(out));
	} else if (loc == 3) {
		asm("mov %%rdx, %0":"=r"(out));
	} else if (loc == 4) {
		asm("mov %%rcx, %0":"=r"(out));
	} else if (loc == 5) {
		asm("mov %%r8, %0":"=r"(out));
	} else if (loc == 6) {
		asm("mov %%r9, %0":"=r"(out));
	}
	return out;
}

char* format(const char *str, ...) {
	asm("pop %rax");
	size_t loc = 0;
	size_t args[] = {get_value(2), get_value(3), get_value(4), get_value(5), get_value(6)};
	size_t str_len = strlen(str);
	char mod = 0;
	size_t dest_len = 0;
	char uint_t = 0;
	char long_t = 0;
	char short_t = 0;

	size_t dest_alloc_len = 50;
	char *dest = malloc(dest_alloc_len);

	for (size_t i = 0; i < str_len; i++) {
		if (dest_alloc_len - dest_len <= 10) {
			dest = realloc(dest, dest_alloc_len + dest_len);
		}
		if (mod) {
			if (str[i] == '%') {
				dest[dest_len] = '%';
				dest_len++;
				mod = 0;
				continue;
			} else if (str[i] == 'c') {
				dest[dest_len] = (uint8)args[loc];
				dest_len++;
			} else if (str[i] == 's') {
				const char *out = (const char*)args[loc];
				strcat(dest, out);
				dest_len += strlen(out);
			} else if (str[i] == 'h') {
				short_t++;
				continue;
			} else if (str[i] == 'l') {
				long_t = 1;
				continue;
			} else if (str[i] == 'i') {
				char *st;
				if (short_t == 2) {
					st = i32to_str((int8)args[loc]);
					short_t = 0;
				} else if (short_t == 1) {
					st = i32to_str((int16)args[loc]);
					short_t = 0;
				} else if (long_t) {
					st = i32to_str((int64)args[loc]);
					long_t = 0;
				} else {
					st = i32to_str((int64)args[loc]);
				}
				strcat(dest, st);
				dest_len += strlen(st);
				free(st);
			} else if (str[i] == 'u') {
				char *st;
				if (short_t == 2) {
					st = u32to_str((uint8)args[loc]);
					short_t = 0;
				} else if (short_t == 1) {
					st = u32to_str((uint16)args[loc]);
					short_t = 0;
				} else if (long_t) {
					st = u32to_str((uint64)args[loc]);
					long_t = 0;
				} else {
					st = u32to_str((uint64)args[loc]);
				}
				dest_len += strlen(st);
				strcat(dest, st);
				free(st);
			}
			loc++;
			mod = 0;
		} else {
			if (str[i] == '%') {
				mod = 1;
				continue;
			}
			dest[dest_len] = str[i];
			dest_len++;
		}
	}
	return dest;
}
char* formatn(const char *str, uint64 n, ...) {
	size_t loc = 0;
	size_t args[] = {get_value(3), get_value(4), get_value(5), get_value(6)};
	size_t str_len = strlen(str);
	char mod = 0;
	size_t dest_len = 0;
	char uint_t = 0;
	char long_t = 0;
	char short_t = 0;

	char *dest = malloc(n);

	for (size_t i = 0; i < str_len; i++) {
		if (n == dest_len) {
			break;
		}
		if (mod) {
			if (str[i] == '%') {
				dest[dest_len] = '%';
				dest_len++;
				mod = 0;
				continue;
			} else if (str[i] == 'c') {
				dest[dest_len] = (uint8)args[loc];
				dest_len++;
			} else if (str[i] == 's') {
				const char *out = (const char*)args[loc];
				strcat(dest, out);
				dest_len += strlen(out);
			} else if (str[i] == 'h') {
				short_t++;
				continue;
			} else if (str[i] == 'l') {
				long_t = 1;
				continue;
			} else if (str[i] == 'i') {
				char *st;
				if (short_t == 2) {
					st = i32to_str((int8)args[loc]);
					short_t = 0;
				} else if (short_t == 1) {
					st = i32to_str((int16)args[loc]);
					short_t = 0;
				} else if (long_t) {
					st = i32to_str((int64)args[loc]);
					long_t = 0;
				} else {
					st = i32to_str((int64)args[loc]);
				}
				strcat(dest, st);
				dest_len += strlen(st);
				free(st);
			} else if (str[i] == 'u') {
				char *st;
				if (short_t == 2) {
					st = u32to_str((uint8)args[loc]);
					short_t = 0;
				} else if (short_t == 1) {
					st = u32to_str((uint16)args[loc]);
					short_t = 0;
				} else if (long_t) {
					st = u32to_str((uint64)args[loc]);
					long_t = 0;
				} else {
					st = u32to_str((uint64)args[loc]);
				}
				dest_len += strlen(st);
				strcat(dest, st);
				free(st);
			}
			loc++;
			mod = 0;
		} else {
			if (str[i] == '%') {
				mod = 1;
				continue;
			}
			dest[dest_len] = str[i];
			dest_len++;
		}
	}
	return dest;
}
