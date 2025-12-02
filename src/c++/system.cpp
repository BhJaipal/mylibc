#include <system.hpp>

libc::size_t std::sys::syscall(libc::size_t rax) {
	return libc::sys::syscall(0, 0, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi) {
	return libc::sys::syscall(rdi, 0, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi, libc::size_t rsi) {
	return libc::sys::syscall(rdi, rsi, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi, libc::size_t rsi, libc::size_t rdx) {
	return libc::sys::syscall(rdi, rsi, rdx, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10) {
	return libc::sys::syscall(rdi, rsi, rdx, r10, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8) {

	return libc::sys::syscall(rdi, rsi, rdx, r10, r8, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rax, libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8, libc::size_t r9) {
	return libc::sys::syscall(rdi, rsi, rdx, r10, r8, r9, rax);
}
