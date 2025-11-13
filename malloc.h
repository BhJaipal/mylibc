#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#include "types.h"
#include "syscall.h"

typedef enum {
	PROT_READ = 0x1,		/* Page can be read.  */
	PROT_WRITE= 0x2,		/* Page can be written.  */
	PROT_EXEC = 0x4,		/* Page can be executed.  */
	PROT_NONE = 0x0,		/* Page can not be accessed.  */
	PROT_GROWSDOWN =	0x01000000, /* Extend change to start of growsdown vma (mprotect only).  */
	PROT_GROWSUP	=	0x02000000, /* Extend change to start of growsup vma (mprotect only).  */
} PageProtection;

/* Sharing types (must choose one and only one of these).  */
typedef enum {
	MAP_SHARED =	0x01,		/* Share changes.  */
	MAP_PRIVATE=	0x02,		/* Changes are private.  */
	MAP_FIXED = 	0x10,		/* Interpret addr exactly.  */
	MAP_ANONYMOUS = 0x20,		/* Don't use a file.  */
} MapProps;

void *mmap (void *addr, size_t len, PageProtection prot,
		   MapProps flags, int fd, long offset);
int mprotect(void *__addr, size_t __len, PageProtection __prot);
void munmap(void *ptr, size_t size);


void* malloc(size_t size);
void* realloc(void *ptr, size_t size);
void free(void *ptr);

void memcpy(uint8 *dest, const uint8 *src, size_t n);
/*  @brief Use this if you want to create your own heap allocator */
void* heap_new(PageProtection prot, MapProps flags, int fd);
/* @brief malloc that can be used with your custom heap */
void* heap_malloc(void *heap, size_t size);
/* @brief realloc that can be used with your custom heap */
void* heap_realloc(void *heap, void *ptr, size_t size);
/* @brief free that can be used with your custom heap */
void heap_free(void *heap, void *ptr);
/* @brief Destroy the heap */
void heap_destroy(void* heap);


#endif // !MY_MALLOC_H
