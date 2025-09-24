#include "format.h"
#include <string.h>
#include "test.h"

TEST({
	char* dest = format("Hello %% %s %i %p %o", "World", 5, 654, 654);
	EXPECT(!strcmp("Hello % World 5 0x28e 01216", dest), "Cannot format correctly");
	free(dest);
});
