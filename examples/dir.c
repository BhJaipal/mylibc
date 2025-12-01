#include <file.h>

int main() {
	int fd = open("bin", O_RDONLY | __O_DIRECTORY);
	char dir[100];
	int len = read(fd, dir, 100);
	write(1, dir, len);
	write(1, "\n", 1);
	return 0;
}
