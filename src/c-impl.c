#include "c-impl.h"
#include "file.h"
#include "types.h"
#include <syscall.h>
#include "string.h"

#define ST (size_t)
inline void putchar(char c) {
	write(1, &c, 1);
}

int pow(int b, int e) {
	int out = 1;
	for (unsigned i = 0; i < e; i++) {
		out *= b;
	}
	return out;
}

void write_uint(uint32 x) {
	x = rev_u(x);
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}

	while (x) {
		putchar(x % 10 + 0x30);
		x /= 10;
	}
}
char* u64to_str(uint64 x, uint8 size, char *out) {
	size_t out_len = 0;
	if (x < 10) {
		out[0] = x + 0x30;
		out[1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		out[out_len] = (x % 10 + 0x30);
		x /= 10;
		out_len++;
	}
	out[out_len] = 0;
	
	for (size_t i = 0; i < out_len / 2; i++) {
		out[i] ^= out[out_len - i -1];
		out[out_len - i - 1] ^= out[i];
		out[i] ^= out[out_len - i -1];
	}
	return out;
}

char* ptr_to_str(void *ptr, char *out) {
	size_t x = (size_t)ptr;
	strcpy(out, "0x");
	size_t out_len = 2;
	if (x < 16) {
		out[0] = x + 0x30;
		out[1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		uint8 o = x % 16;
		if (o <= 9 && o >= 0)
			out[out_len] = o + 0x30;
		else
			out[out_len] = o - 10 + 0x61;
		x /= 16;
		out_len++;
	}
	out[out_len] = 0;
	
	char *str_start = out + 2;
	size_t s_len = strlen(str_start);
	
	for (size_t i = 0; i < s_len / 2; i++) {
		str_start[i] ^= str_start[s_len - i -1];
		str_start[s_len - i - 1] ^= str_start[i];
		str_start[i] ^= str_start[s_len - i -1];
	}
	return out;
}
char* octal_to_str(size_t x, char *out) {
	size_t out_len = 0;
	if (x < 8) {
		out[0] = x + 0x30;
		out[1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		uint8 o = x % 8;
		out[out_len] = o + 0x30;
		x /= 8;
		out_len++;
	}
	out[out_len] = 0;
	
	char *str_start = out;
	size_t s_len = strlen(str_start);
	
	for (size_t i = 0; i < s_len / 2; i++) {
		str_start[i] ^= str_start[s_len - i -1];
		str_start[s_len - i - 1] ^= str_start[i];
		str_start[i] ^= str_start[s_len - i -1];
	}
	return out;
}

char* hex_lower_to_str(size_t x, char *out) {
	size_t out_len = 0;
	if (x < 16) {
		out[0] = x + 0x30;
		out[1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		uint8 o = x % 16;
		if (o <= 9 && o >= 0)
			out[out_len] = o + 0x30;
		else
			out[out_len] = o - 10 + 0x61;
		x /= 16;
		out_len++;
	}
	out[out_len] = 0;
	
	for (size_t i = 0; i < out_len / 2; i++) {
		out[i] ^= out[out_len - i -1];
		out[out_len - i - 1] ^= out[i];
		out[i] ^= out[out_len - i -1];
	}
	return out;
}

char* hex_upper_to_str(size_t x, char *out) {
	size_t out_len = 0;
	if (x < 16) {
		out[0] = x + 0x30;
		out[1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		uint8 o = x % 16;
		if (o <= 9 && o >= 0)
			out[out_len] = o + 0x30;
		else
			out[out_len] = o - 10 + 0x41;
		x /= 16;
		out_len++;
	}
	out[out_len] = 0;
	
	char *str_start = out + 2;
	size_t s_len = strlen(str_start);
	
	for (size_t i = 0; i < out_len / 2; i++) {
		out[i] ^= out[out_len - i -1];
		out[out_len - i - 1] ^= out[i];
		out[i] ^= out[out_len - i -1];
	}
	return out;
}
uint32 read_uint() {
	uint32 x = 0;
	char num[11];
	for (int i = 0; i < 11;i++) {
		read(1, num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (num[i] <= '0' || num[i] >= '9') {
			write(1, "\e[91mERROR: \e[0m", 17);
			write(1, "Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		x *= 10;
		x += num[i] - 0x30;
	}
	return x;
}
void write_int(int x) {
	x = rev_d(x);
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}
	while (x) {
		putchar(x % 10 + 0x30);
		x /= 10;
	}
}
char* i64to_str(int64 x, uint8 size, char *out) {
	size_t out_len = 0;
	char is_neg;
	if (x < 0) {
		*out = '-';
		x = -x;
		is_neg = 1;
		out_len++;
	}
	if (x < 10) {
		out[out_len] = x + 0x30;
		out[out_len + 1] = 0;
		out_len++;
		return out;
	}
	while (x) {
		out[out_len] = (x % 10 + 0x30);
		x /= 10;
		out_len++;
	}
	out[out_len] = 0;

	char *str_start = out + 1;
	size_t s_len = strlen(str_start);
	
	for (size_t i = 0; i < s_len / 2; i++) {
		str_start[i] ^= str_start[s_len - i -1];
		str_start[s_len - i - 1] ^= str_start[i];
		str_start[i] ^= str_start[s_len - i -1];
	}
	return out;
}

int read_int() {
	int x = 0;
	char num[11];
	for (int i = 0; i < 11; i++) {
		read(1, num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		else if (i == 0 && num[i] == '-')
			continue;
		else if (num[i] <= '0' || num[i] >= '9') {
			write(1, "\e[91mERROR: \e[0m", 17);
			write(1, "Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (i == 0 && num[0] == '-')
			continue;
		x *= 10;
		x += num[i] - 0x30;
	}
	if (num[0] == '-')
		x = -x;
	return x;
}

void print(const char *str) {
	unsigned i = strlen(str);
	write(1, str, i);
}

void println(const char *str) {
	write(1, str, strlen(str));
	putchar(10);
}

int rev_d(int x) {
	if (x < 10 && x > -10) return x;
	char neg=0;
	if (x<0) {
		neg=1;
		x = -x;
	}
	int a = 0;
	int ex = 0;
	while (x) {
		a *= 10;
		a += x % 10;
		x /= 10;
	}
	return neg ? -a : a;
}
uint32 rev_u(uint32 x) {
	if (x < 10) return x;
	int a = 0;
	int ex = 0;
	while (x) {
		a *= 10;
		a += x % 10;
		x /= 10;
	}
	return a;
}

