#pragma once

template <class T>
void *operator new(long unsigned len, T expression = nullptr);
void *operator new(long unsigned len);

void operator delete(void *ptr, unsigned long a) noexcept;
void operator delete(void *ptr) noexcept;
