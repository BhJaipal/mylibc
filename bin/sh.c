#include "types.h"
#include <syscall.h>
#include <file.h>
#include <string.h>
#include <syscall_enum.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		while (1) {
			char buff[200] = "";
			write(1, "$ ", 2);
			fork();
			int readed = read(0, buff, 200);
			buff[readed-1] = 0;

			char argv[10][100] = {};
			int argc = 0;
			int argv_start = 0;
			for (int i = 0; i < readed; i++) {
				if (buff[i] == ' ') {
					argv_start = i+1;
					break;
				}
			}
			char path[40] = "/bin/";
			buff[argv_start-1] = 0;
			strcat(path, buff);

			int i = 0;
			int len = 0;
			while (buff[i + argv_start]) {
				if (buff[i] == ' ') {
					argc++;
					len = 0;
					argv_start = i + 1;
				}
				argv[argc][len] = buff[i];

				len++;
				i++;
			}
			argv[argc + 1][0] = 0;
			return syscall(SYS_execve, (size_t)path, 0, 0, 0, 0, 0);
		}
	}
	return 0;
}
