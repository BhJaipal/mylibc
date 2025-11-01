#include "c-impl.h"
#include "heap.hpp"
#include <file.h>
#include <syscall.h>

int main() {
	int c = 5;
	Heap heap;
	auto ptr = heap.alloc<char>(5);
	ptr.overwrite("Jai\n");
	ptr.realloc(8);
	print(ptr.raw_mut_ptr());
}
