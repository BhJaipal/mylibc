#include <unistd.h>

int main(int c, char **v) {
	if (c == 1) return 0;
	return chdir(v[1]);
}
