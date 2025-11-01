#include <syscall.h>

extern "C" {
void* heap_init();
void set_global_heap(void *_heap);
void global_heap_destroy();
int main(int argc, char **argv);
void _libc_main(long argc, char **argv);
}

void _libc_main(long argc, char **argv) {
	set_global_heap(heap_init());
	int status = main(argc, argv);
	global_heap_destroy();
	exit(status);
}
