#include "test.h"
#include "malloc.h"
#include "string.h"

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

TEST(custom_heap)
	void *heap = heap_new(PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1);
	char *name = heap_malloc(heap, 5);
	strcpy(name, "Hema");
	name = heap_realloc(heap, name, 9);
	strcat(name, " bha");

	EXPECT(((Heap*)heap)->head->ptr == name);
	heap_free(heap, name);
	heap_destroy(heap);
	EXPECT(0);
	return 0;
}

ENABLE(custom_heap_test);
