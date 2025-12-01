#include "malloc.h"
#include "syscall.h"
#include "syscall_enum.h"
#include "types.h"
#define ST (size_t)

void *mmap (void *addr, size_t len, PageProtection prot,
		   MapProps flags, int fd, long offset) {
	SYSCALL(size_t ptr = , SYS_mmap, ST addr, len, prot, flags, fd, offset);
	return ptr == -1 ? null : (void*)ptr;
}
int mprotect(void *addr, size_t len, PageProtection prot) {
	SYSCALL(return, SYS_mprotect, ST addr, len, prot);
}
void munmap(void *ptr, size_t size) {
	SYSCALL(, SYS_munmap, ST ptr, size);
}

typedef enum {
	HeapAlloc,
	HeapDealloc,
} HeapEvent;

typedef struct Ptr Ptr;
struct Ptr {
	Ptr *next;
	void *ptr;
	size_t size;
};
typedef struct {
	Ptr *head;
	Ptr *end;
	size_t node_size;
	PageProtection prot;
	MapProps flags;
	int fd;
} Heap;


Heap* heap_init() {
	Heap *heap = mmap(null, sizeof(Heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	heap->head = null;
	heap->node_size = sizeof(Ptr);
	return heap;
}
void heap_destroy(void *_heap) {
	if (!_heap) {
		munmap(_heap, sizeof(Heap));
		return;
	}
	Heap *heap = _heap;
	Ptr *head = heap->head;
	Ptr *prev = null;

	while (head) {
		prev = head;
		head = head->next;
		munmap(prev->ptr, prev->size);
		munmap(prev, heap->node_size);
	}
	munmap(heap, sizeof(Heap));
}
void heap_add_node(Heap *heap, void *ptr, size_t size) {
	if (!heap->head) {
		heap->head = mmap(null, heap->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		heap->head->ptr = ptr;
		heap->head->size = size;
		heap->head->next = null;
		heap->end = heap->head;
		return;
	}
	Ptr *next = mmap(null, heap->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	next->ptr = ptr;
	next->size = size;
	next->next = null;

	heap->end->next = next;
	heap->end = next;
}
void heap_delete_node(Heap *heap, void *val) {
	Ptr *head = heap->head;
	if (!head) return;
	Ptr *prev = null;

	while (head->ptr != val) {
		prev = head;
		head = head->next;
	}
	if (prev)
		prev->next = head->next;
	munmap(head->ptr, head->size);
	munmap(head, heap->node_size);
	if (prev)
		prev->next = null;
	else {
		heap->head = null;
	}
}

static Heap* access_global_heap(char is_write, Heap *new_heap) {
	static Heap *heap = null;
	if (is_write) {
		heap = new_heap;
	}
	return heap;
}
void set_global_heap(void *_heap) {
	access_global_heap(1, _heap);
}
void global_heap_destroy() {
	heap_destroy(access_global_heap(0, null));
}

void heap_update(Heap *heap, HeapEvent event, void *ptr, size_t len) {
	switch (event) {
		case HeapAlloc:
			heap_add_node(heap, ptr, len);
			break;
		case HeapDealloc:
			heap_delete_node(heap, ptr);
			break;
	}
}

void* memcpy(uint8 *dest, const uint8 *src, size_t n) {
	for (size_t i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	return dest;
}

void* heap_new(PageProtection prot, MapProps flags, int fd) {
	Heap *heap = heap_init();
	heap->fd = fd;
	heap->prot = prot;
	heap->flags = flags;
	return heap;
}

void* heap_malloc(void *heap, size_t size) {
	void *ptr = mmap(0, size, ((Heap*)heap)->prot,
				  ((Heap*)heap)->flags, ((Heap*)heap)->fd, 0);
	heap_update(heap, HeapAlloc, ptr, size);
	return ptr;
}
void* malloc(size_t size) {
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	heap_update(access_global_heap(0, null), HeapAlloc, ptr, size);
	return ptr;
}
void* heap_realloc(void *heap, void *ptr, size_t size) {
	void *new_ptr = mmap(0, size, ((Heap*)heap)->prot,
				  ((Heap*)heap)->flags, ((Heap*)heap)->fd, 0);

	Ptr *head = ((Heap*)heap)->head;
	size_t len;
	while (head) {
		if (head->ptr != ptr)
			head = head->next;
		else {
			len = head->size;
			head->ptr = new_ptr;
			head->size = size;
			break;
		}
	}
	memcpy(new_ptr, ptr, len);
	munmap(ptr, len);
	return new_ptr;
}
void* realloc(void *ptr, size_t size) {
	void *new_ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	Ptr *head = access_global_heap(0, null)->head;
	size_t len;
	while (head) {
		if (head->ptr != ptr)
			head = head->next;
		else {
			len = head->size;
			head->ptr = new_ptr;
			head->size = size;
			break;
		}
	}
	memcpy(new_ptr, ptr, len);
	munmap(ptr, len);
	return new_ptr;
}
void heap_free(void *heap, void *ptr) {
	heap_delete_node(heap, ptr);
}

void free(void *ptr) {
	heap_delete_node(access_global_heap(0, null), ptr);
}
