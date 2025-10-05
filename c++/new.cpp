#include "../malloc.h"

void *operator new(size_t len) {
	void *ptr = malloc(len);
	return ptr;
}
void operator delete(void *ptr) noexcept {
	free(ptr);
}

void operator delete(void *ptr, unsigned long a) noexcept {
	free(ptr);
}

void * __gxx_personality_v0=0;
void * _Unwind_Resume =0;
