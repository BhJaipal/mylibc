#include "file.h"
#include "tests/test.h"

int test_count = 0;
char test_name[20] = "";
int (*tests[10])(int, char**) = {0};
void enable();

int main(int argc, char *argv[]) {
	enable();
	for (size_t i = 0; i < test_count; i++) {
		if (!tests[i](argc, argv)) {
			printf("\e[92m[%s] passed\n\e[0m", test_name);
		} else
			printf("\e[91m[%s] failed\n\e[0m", test_name);
	}
}
