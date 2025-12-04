#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#include "types.h"
#include "syscall.h"
#include "sys/mman.h"

void* malloc(size_t size);
void* realloc(void *ptr, size_t size);
void free(void *ptr);

void memset(void *dest, uint8 byte, size_t n);
void* memcpy(void *dest, const void *src, size_t n);
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
