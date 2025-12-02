#pragma once
#include "libc.hpp"

namespace libc::sys {
extern "C" {
#include "../syscall.h"
#include "../unistd.h"
}
}

namespace std::sys {
libc::size_t syscall(libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8, libc::size_t rax);
libc::size_t syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8, libc::size_t r9, libc::size_t rax);
}
