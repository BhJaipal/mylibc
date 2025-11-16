#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H
#include "malloc.h"
#include "types.h"

#define MEMORYARENA_MAX_NODES 20

typedef struct _pointer_t _pointer_t;
typedef struct _pointer_t {
	void *ptr;
	size_t size;
	/* enable|in_use */
	char flags;
	struct _pointer_t *prev, *next;
} *pointer_t;

typedef struct _MemoryArena {
	int fd;
	MapProps flags;
	PageProtection prot;
	/* these are set automatic */
	_pointer_t head[MEMORYARENA_MAX_NODES];
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
inline void set_auto_defrag(MemoryArena *arena, char auto_defrag) {
	arena->auto_defrag = auto_defrag;
}

/** @brief allocate memory in arena */
void *arena_alloc(MemoryArena *arena, size_t size);

void arena_dealloc(MemoryArena *arena, void *ptr);

/** WARN: Not implemented yet */
void arena_defrag(MemoryArena *arena);
void arena_auto_defrag(MemoryArena *arena);

void arena_destroy(MemoryArena *arena);

#endif // !MEMORY_POOL_H
