#include "format.h"
#include "c-impl.h"

int main() {
	char* dest = format("Hello %% %s %i %i %i %u", "World", 5, 6, 3, 7);
	println(dest);
	free(dest);
}
