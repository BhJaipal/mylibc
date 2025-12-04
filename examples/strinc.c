#include <string.h>
#include <io.h>
#include <file.h>
int main(int argc, char *argv[]) {
	if (argc < 3) {
		write(2, "Not enough arguments\n", 21);
		return 1;
	}
	printf("%i\n", strinclude(argv[1], argv[2]));
	return 0;
}
