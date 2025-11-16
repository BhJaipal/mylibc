#include <unistd.h>

int main() {
	char b[100];
	write(1, "$ ", 2);
	int a = read(0, b, 100);
	write(1, "\n", 1);
	b[a-1] = 0;
	write(1, b, a);

	return execve(b, 0, 0);
}
