#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int fd;
	if (argc > 1)
		fd = open(argv[1], O_RDWR);
	else
		fd = open(argv[0], O_RDWR);
	printf("%d ", fd);

	struct stat statb;
	fstat(fd, &statb);
	printf("%lu %ld\n", statb.st_dev, statb.st_size);
	close(fd);
}
