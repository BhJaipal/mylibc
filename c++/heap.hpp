#pragma once
#include "malloc.h"
#include <types.h>

namespace std {
class Heap;

template <class T>
class pointer_t {
protected:
	T *data_;
	size_t size_;

	friend class Heap;
	Heap& heap_;
	pointer_t(T *data, size_t size): data_(data), size_(size) {}
public:
	pointer_t(pointer_t&&) = default;
	pointer_t(pointer_t&) = default;
	pointer_t() = default;
	size_t size() { return size_; }
	const T* operator*() {
		return *data_;
	}
	template <class U>
	void just_do_it(pointer_t<U> data) {
		(U *)data_ = data.data_;
		size_ = data.size();
	}
	template <class U>
	void write_anyways(U value) {
		*(U *)data_ = value;
	}
	T *raw_mut_ptr() {
		return data_;
	}
	T& read_as_mut() {
		return *data_;
	}
	void write(T data) {
		*data_ = data;
	}
	void overwrite(T* data) {
		data_ = data;
	}
	void free();
	template <class U>
	operator pointer_t<U>() {
		return pointer_t<U>(data_, size_);
	}
};
#define NULL (Ptr *)0

class Heap {
	PageProtection prot_;
	MapProps flags_;
	int fd_;
	size_t total_size = 0;

	struct Ptr: public pointer_t<char> {
		Ptr *next;
		Ptr *prev;
		bool is_free;
	};
	Ptr *head, *end;

	void free_all_memory();

public:
	Heap(int prot = PROT_READ | PROT_WRITE, int flags = MAP_ANONYMOUS | MAP_PRIVATE, int fd = -1): prot_((PageProtection)prot), flags_((MapProps)flags), fd_(fd) {}
	Heap(Heap&&) = delete;
	Heap(Heap&) = delete;

	void free(pointer_t<char> ptr);

	template <class T>
	pointer_t<T> alloc(size_t size = 1);

	void defragment(size_t minimum = 15);

	void destroy() {
		if (fd_ >= 0) fd_ = -1;
		free_all_memory();
	}
};
}
