extern void* heap_init();
extern void set_global_heap(void *_heap);
extern void global_heap_destroy();
extern int main(int argc, char **argv);
extern void libc_main(long argc, char **argv);
extern void exit(int) __attribute__((noreturn));

void _start() {
	asm(
		"pop %rdx\n"
		"pop %rdi\n"
		"mov %rsp, %rsi\n"
		"push %rdx\n"
		"call libc_main\n"
	);
}

void libc_main(long argc, char **argv) {
	set_global_heap(heap_init());
	int status = main(argc, argv);
	global_heap_destroy();
	exit(status);
}
