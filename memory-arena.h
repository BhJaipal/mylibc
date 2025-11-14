#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H
#include "malloc.h"
#include "types.h"

typedef struct _pointer_t {
	void *ptr;
	size_t size;
	char in_use;
	struct _pointer_t *prev, *next;
} *pointer_t;

typedef struct _MemoryArena {
	int fd;
	MapProps flags;
	PageProtection prot;
	/* these are set automatic */
	pointer_t head;
	size_t inuse_sz, total_sz;
	char auto_defrag;
} MemoryArena;

/**
 * @brief It is 1st function to be called to setup memory arena values
 */
void arena_init(MemoryArena *arena);

/** @brief uses both arena_init and arena_heap_as_default */
void arena_create(MemoryArena *arena);
/**
 * @brief Set up flags as heap's default flags
 */
void arena_heap_as_default(MemoryArena *arena);

/** sets arena.auto_defrag as you wish, default is true, auto defragmentation is done after each memory free */
inline void set_auto_defrag(MemoryArena *arena, char auto_defrag);

/** @brief allocate memory in arena */
void *arena_alloc(MemoryArena *arena, size_t size);

/** WARN: Not implemented yet */
void arena_dealloc(MemoryArena *arena, void *ptr);

/** WARN: Not implemented yet */
void arena_defrag(MemoryArena *arena);

void arena_destroy(MemoryArena *arena);

#endif // !MEMORY_POOL_H
