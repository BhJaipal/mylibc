#include <file.h>
#include <string.h>
#include "test.h"
#include <memory-arena.h>

TEST(arena)
	MemoryArena arena;
	arena_create(&arena);
	char *name = arena_alloc(&arena, 7);
	strcpy(name, "Jaipal");
	IS_NOT_NULL(name);
	EXPECT(!strcmp(name, "Jaipal"));
	
	int *a = arena_alloc(&arena, 4);
	IS_NOT_NULL(a);

	arena_dealloc(&arena, name);

	float *x = arena_alloc(&arena, sizeof(float));
	IS_NOT_NULL(x);
	printf("\t\t\e[36mLog:\e[0m %p %p\n", arena.head->ptr, x);
	EXPECT(arena.head->ptr == x);
	arena_dealloc(&arena, x);
	arena_dealloc(&arena, a);
	arena_destroy(&arena);
ENDTEST

ENABLE(arena_test)
