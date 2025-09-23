#include "format.h"
#include "c-impl.h"

int main() {
	char* dest = format("Hello %% %s %i %p %o", "World", 5, 654, 654);
	println(dest);
	free(dest);
}
