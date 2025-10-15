#include <malloc.h>
#include "types.h"
#include <heap.hpp>

namespace std {
	template <class T>
	pointer_t<T> Heap::alloc(size_t size) {
		if (head == null) {
			void *ptr = mmap(null, size, prot_, flags_, fd_, 0);
			head = (Ptr *)mmap(null, sizeof(Ptr), (PageProtection)(PROT_READ | PROT_WRITE), (MapProps)(MAP_ANONYMOUS | MAP_PRIVATE), -1, 0);
			head->is_free = false;
			total_size += size;
			head->data_ = (char *)ptr;
			head->size_ = size;
			head->next = NULL;
			end = head;
			return pointer_t<T>(ptr, size);
		}

		Ptr* curr = head;
		while (curr->next) {
			if (curr->is_free && curr->size_ >= size) break;
			curr = curr->next;
		}
		if (curr->is_free) {
			if (curr->size_ - size) {
				Ptr *ptr_node = (Ptr *)mmap(null, sizeof(Ptr), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
				ptr_node->size_ = curr->size_ - size;
				ptr_node->data_ = curr->data_ + size;
				ptr_node->is_free = true;
				ptr_node->next = curr->next;
				curr->next = ptr_node;
			}
			curr->is_free = false;
			curr->size_ = size;
			return (pointer_t<T>)curr;
		}
		end->next = (Ptr *)mmap(null, sizeof(Ptr), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		void *ptr = mmap((int*)end->data_ + end->size_ + 1, size, prot_, flags_, fd_, 0);
		end->next->data_ = (char*)ptr;
		end->next->size_ = size;
		end->next->is_free = false;
		end->next->next = NULL;
		total_size += size;
		end = end->next;
		return pointer_t<T>(ptr, size);
	}

	void Heap::free(pointer_t<char> ptr) {
		Ptr* curr = head;
		while (curr->next) {
			if (curr->data_ == ptr.data_) break;
			curr = curr->next;
		}
		if (curr->data_ != ptr.data_) return;
		curr->is_free = true;
		if (curr->prev && curr->prev->is_free) {
			curr->prev->size_ += curr->size_;
			curr->prev->next = curr->next;
			if (curr->next) curr->next->prev = curr->prev;
			munmap(curr, sizeof(Ptr));
			return;
		}
		if (curr->next && curr->next->is_free) {
			curr->next->size_ += curr->size_;
			curr->next->prev = curr->prev;
			if (curr->prev) curr->next->prev = curr->prev;
			munmap(curr, sizeof(Ptr));
			return;
		}
	}

	template<class T>
	void pointer_t<T>::free() {
		heap_.free(this);
	}
	void Heap::free_all_memory() {
		munmap(head->data_, total_size);
		Ptr* curr = head, *prev = NULL;
		while (curr->next) {
			prev = curr;
			if (prev) munmap(prev, sizeof(Ptr));
			curr = curr->next;
		}
		munmap(curr, sizeof(Ptr));
	}
}
