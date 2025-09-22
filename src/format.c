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
extern char* format_args(const char *str, size_t *args) {
	size_t loc = 0;
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
				char st[24];
				if (short_t == 2) {
					i64to_str((int8)args[loc], 5, st);
					short_t = 0;
				} else if (short_t == 1) {
					i64to_str((int16)args[loc], 7, st);
					short_t = 0;
				} else if (long_t) {
					i64to_str((int64)args[loc], 22, st);
					long_t = 0;
				} else {
					i64to_str((int32)args[loc], 13, st);
				}
				strcat(dest, st);
				dest_len += strlen(st);
			} else if (str[i] == 'u') {
				char st[22];
				if (short_t == 2) {
					u64to_str((uint8)args[loc], 4, st);
					short_t = 0;
				} else if (short_t == 1) {
					u64to_str((uint16)args[loc], 6, st);
					short_t = 0;
				} else if (long_t) {
					u64to_str((uint64)args[loc], 22, st);
					long_t = 0;
				} else {
					u64to_str((uint32)args[loc], 13, st);
				}
				dest_len += strlen(st);
				strcat(dest, st);
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

char* format(const char *str, ...) {
	size_t args[] = {get_value(2), get_value(3), get_value(4), get_value(5), get_value(6)};
	return format_args(str, args);
}

char* formatn_args(const char *str, size_t n, size_t *args) {
	size_t loc = 0;
	size_t str_len = strlen(str);
	char mod = 0;
	size_t dest_len = 0;
	char uint_t = 0;
	char long_t = 0;
	char short_t = 0;

	char *dest = malloc(n);

	for (size_t i = 0; i < str_len; i++) {
		if (n <= dest_len) {
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
				char st[22];
				if (short_t == 2) {
					i64to_str((int8)args[loc], 5, st);
					short_t = 0;
				} else if (short_t == 1) {
					i64to_str((int16)args[loc], 7, st);
					short_t = 0;
				} else if (long_t) {
					i64to_str((int64)args[loc], 22, st);
					long_t = 0;
				} else {
					i64to_str((int32)args[loc], 13, st);
				}
				strcat(dest, st);
				dest_len += strlen(st);
			} else if (str[i] == 'u') {
				char st[22];
				if (short_t == 2) {
					u64to_str((uint8)args[loc], 4, st);
					short_t = 0;
				} else if (short_t == 1) {
					u64to_str((uint16)args[loc], 6, st);
					short_t = 0;
				} else if (long_t) {
					u64to_str((uint64)args[loc], 22, st);
					long_t = 0;
				} else {
					u64to_str((uint32)args[loc], 13, st);
				}
				dest_len += strlen(st);
				strcat(dest, st);
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
	size_t args[] = {get_value(3), get_value(4), get_value(5), get_value(6)};
	return formatn_args(str, n, args);
}
