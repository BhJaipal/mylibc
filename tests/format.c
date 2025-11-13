#include "format.h"
#include <string.h>
#include "c-impl.h"
#include "test.h"

TEST(format)
	char* dest = format("Hello %% %s %i %p %o", "World", 5, 654, 654);
	EXPECT(!strcmp("Hello % World 5 0x28e 01216", dest));
	free(dest);
	return 0;
}
ENABLE(format_test)
