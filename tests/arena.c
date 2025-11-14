#include <string.h>
#include "test.h"
#include <memory-arena.h>

TEST(arena)
	MemoryArena arena;
	arena_create(&arena);
	char *name = arena_alloc(&arena, 7);
	strcpy(name, "Jaipal");
	EXPECT(!strcmp(name, "Jaipal"));
ENDTEST

ENABLE(arena_test)
