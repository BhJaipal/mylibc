#include <fs.h>
#include <string.h>
#include <io.h>
#include <file.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
	int                  fd;
	char                 buf[BUF_SIZE];
	long                 nread;
	linux_dirent64 *d;

	fd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
	if (fd == -1) {
		dprintf(2, "directory does not exist\n");
	}
	int i = 0;
	for (;;) {
		nread = getdents64(fd, (linux_dirent64*)buf, BUF_SIZE);
		if (nread == -1)
			break;

		if (nread == 0)
			break;

		for (size_t bpos = 0; bpos < nread;) {
			d = (linux_dirent64*)(buf + bpos);
			switch (d->d_type) {
				case DT_DIR:
					printf("\e[94m%s", d->d_name);
					break;
				case DT_CHR:
					printf("\e[93m%s", d->d_name);
					break;
				case DT_LNK:
					printf("\e[95m%s", d->d_name);
					break;
				default:
					printf("%s", d->d_name);
					break;
			}
			write(1, "\e[0m", 4);
			for (int i = strlen(d->d_name); i <= 20; i++) {
				write(1, " ", 1);
			}
			if (strlen(d->d_name) >= 20) write(1, "  ", 2);
			bpos += d->d_reclen;
			if (!((i+1) % 10)) printf("\n");
			i++;
		}
	}
	if (i % 10) printf("\n");
}
