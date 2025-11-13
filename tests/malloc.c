#include "test.h"
#include "string.h"

TEST(malloc)
	char *name = malloc(sizeof(char[5]));
	EXPECT(name);
	strncpy(name, "Jai\n", 5);
	return 0;
}
ENABLE(malloc_test)
