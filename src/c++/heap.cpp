#include <heap.hpp>

template<class T>
T* Heap::malloc(libc::size_t size) {
	void *ptr = mmap(0, size, prot, flags, fd, 0);
	if (!head) {
		head = (Ptr*)libc::mmap(null, node_size, libc::PROT_READ | libc::PROT_WRITE, libc::MAP_ANONYMOUS | libc::MAP_PRIVATE, -1, 0);
		head->ptr = ptr;
		head->size = size;
		head->next = (Ptr*)null;
		end = head;
		return (T*)ptr;
	}
	Ptr *next = (Ptr*)libc::mmap(null, node_size, libc::PROT_READ | libc::PROT_WRITE, libc::MAP_ANONYMOUS | libc::MAP_PRIVATE, -1, 0);
	next->ptr = ptr;
	next->size = size;
	next->next = (Ptr*)null;

	end->next = next;
	end = next;
	return (T*)ptr;
}


template<class T>
void Heap::free(T *ptr) {
	Ptr *head = this->head;
	if (!head) return;
	Ptr *prev = (Ptr*)null;

	while (head->ptr != ptr) {
		prev = head;
		head = head->next;
	}
	if (prev)
		prev->next = head->next;
	libc::munmap(head->ptr, head->size);
	libc::munmap(head, node_size);
	if (prev)
		prev->next = (Ptr*)null;
	else {
		head = (Ptr*)null;
	}
}

template<class T, class U>
T *Heap::realloc(U *ptr, libc::size_t size) {
	void *new_ptr = mmap(0, size, prot,
				  flags, fd, 0);

	Ptr *head = this->head;
	libc::size_t len;
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
	return (T*)new_ptr;
}

Heap *heap;
void Heap::set_global() {
	heap = this;
}
void Heap::set_global(Heap* heap_) {
	heap = heap_;
}
void Heap::set_global(Heap& heap_) {
	heap = &heap_;
}
void Heap::destroy() {
	Heap *heap = this;
	Ptr *head = heap->head;
	Ptr *prev = (Ptr*)null;

	while (head) {
		prev = head;
		head = head->next;
		libc::munmap(prev->ptr, prev->size);
		libc::munmap(prev, heap->node_size);
	}
}

template<class T>
void free(T *ptr) {
	heap->free<T>(ptr);
}

template<class T, class U>
T *realloc(U *ptr, libc::size_t size) {
	return heap->realloc<T, U>(ptr, size);
}

template<class T>
T* malloc(libc::size_t size) {
	return heap->malloc<T>(size);
}
