#include <heap.hpp>
#include <system.hpp>

extern "C" {
	void* heap_init();
	void set_global_heap(void *_heap);
	void global_heap_destroy();
	void libc_main(long argc, char **argv);
	char** environ;
}
extern int main(int argc, char **argv, char **envp);

extern "C" void _start() {
	asm(
		"pop %rdx\n"
		"pop %rdi\n"
		"mov %rsp, %rsi\n"
		"push %rdx\n"
		"call libc_main\n"
	);
}


void libc_main(long argc, char **argv) {
	char **envp = argv + argc + 1;
	environ = envp;
	set_global_heap(heap_init());
	int status = main(argc, argv, envp);
	libc::sys::exit(status);
}
