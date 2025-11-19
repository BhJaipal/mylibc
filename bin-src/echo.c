#include "c-impl.h"
#include <file.h>

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	println("");
	return 0;
}
