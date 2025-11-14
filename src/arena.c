#include "types.h"
#include <memory-arena.h>
#include <malloc.h>

void arena_init(MemoryArena *arena) {
	arena->auto_defrag = true;
	arena->head = null;
	arena->inuse_sz = 0;
	arena->total_sz = 0;
}
void pointer_defaults_on(pointer_t ptr) {
	ptr->prev = null;
	ptr->next = null;
	ptr->in_use = 1;
	ptr->ptr = null;
	ptr->size = 0;
}

void arena_create(MemoryArena *arena) {
	arena_init(arena);
	arena_heap_as_default(arena);
}
void arena_heap_as_default(MemoryArena *arena) {
	arena->fd = -1;
	arena->prot = PROT_READ|PROT_WRITE;
	arena->flags = MAP_ANONYMOUS|MAP_PRIVATE;
}
void *arena_alloc(MemoryArena *arena, size_t size) {
	if (!arena->head) {
		arena->head = mmap(null, sizeof(struct _pointer_t), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
		pointer_defaults_on(arena->head);
		arena->head->size = size;
		arena->head->ptr = mmap(null, size, arena->prot, arena->flags, arena->fd, 0);
		arena->inuse_sz = size;
		arena->total_sz = size;
		return arena->head->ptr;
	}

	pointer_t curr = arena->head;
	while (curr->next) {
		if (!(curr->size < size || curr->in_use)) {
			break;
		}
		curr = curr->next;
	}
	if (!curr->next && (curr->size < size || curr->in_use)) {
		curr->next = mmap(null, sizeof(struct _pointer_t), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
		pointer_defaults_on(curr->next);
		curr->next->size = size;
		curr->next->ptr = mmap(curr->ptr + curr->size, size, arena->prot, arena->flags, arena->fd, 0);
		curr->next->prev = curr;
		arena->inuse_sz += size;
		arena->total_sz += size;
		return curr->next->ptr;
	}
	pointer_t next = curr->next;
	if (curr->size - size) {
		pointer_t new = mmap(null, sizeof(struct _pointer_t), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
		pointer_defaults_on(new);
		new->in_use = false;
		new->size = curr->size - size;

		new->next = next;
		next->prev = new;
		curr->next = new;
	}
	curr->in_use = true;
	curr->size -= size;
	return curr->ptr;
}


void arena_destroy(MemoryArena *arena) {
	munmap(arena->head->ptr, arena->total_sz);
	pointer_t curr = arena->head;
	if (!curr) return;

	while (curr->next) {
		curr = curr->next;
		munmap(curr->prev, sizeof(struct _pointer_t));
	}
	munmap(curr, sizeof(struct _pointer_t));

	arena->head = null;
	arena->inuse_sz = 0;
	arena->total_sz = 0;
}

void arena_dealloc(MemoryArena *arena, void *ptr) {
	pointer_t curr = arena->head;
	if (!curr) return;

	while (curr->next && curr->ptr != ptr) {
		curr = curr->next;
	}
	if (curr->ptr != ptr) return;
	curr->in_use = false;

	arena->inuse_sz -= curr->size;

	if (arena->auto_defrag) arena_auto_defrag(arena);
}

void arena_auto_defrag(MemoryArena *arena) {
	pointer_t curr = arena->head;
	if (!curr) return;

	while (curr->next) {
		while (!curr->in_use && !curr->next->in_use) {
			if (!curr->next) break;
			curr->size += curr->next->size;
			pointer_t new_nx = curr->next->next;
			munmap(curr->next, sizeof(struct _pointer_t));
			curr->next = new_nx;
			if (!new_nx) break;
			new_nx->prev = curr;
		}
		curr = curr->next;
	}
}
void arena_defrag(MemoryArena *arena) {}
