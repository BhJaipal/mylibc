#include <c-impl.h>
#include <file.h>

int main(int argc, char **argv) {
	printf("[");
	for (int  i = 0; i < argc; i++) {
		printf("'%s'", argv[i]);
		if (i != argc-1) {
			printf(", ");
		}
	}
	println("]");

	print("Enter 3 numbers: ");
	// scanf not ready yet
	int a = read_int();
	int b = read_int();
	int c = read_int();
	int g;
	if (a > b) {
		if (a > c) g = a;
		else g = c;
	} else {
		if (b > c) g = b;
		else g = c;
	}
	printf("%i is greatest\n", g);
}
