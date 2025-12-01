#include <c++/heap.hpp>

extern int main(int argc, char **argv, char **envp);
extern "C" void libc_main(long argc, char **argv);
extern "C" void exit(int) __attribute__((noreturn));
extern char** environ;

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
	Heap heap;
	heap.set_global();
	int status = main(argc, argv, envp);
	heap.destroy();
	exit(status);
}
