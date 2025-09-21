#include "c-impl.h"
#include "stat.h"
#include "file.h"

int main() {
	int fd = open("./data.out", O_RDWR);
	write_int(fd);
	println(" ");
	char data[21];
	read(fd, data, 20);
	data[20] = 0;

	println(data);
	Stat statb;
	fstat(fd, &statb);
	write_uint(statb.st_dev);
	print(" ");
	write_uint(statb.st_size);
	println(" ");
	close(fd);
}
