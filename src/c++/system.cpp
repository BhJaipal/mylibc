#include <system.hpp>

libc::size_t syscall_cpp_impl(libc::size_t rdi , libc::size_t rsi , libc::size_t rdx , libc::size_t r10 , libc::size_t r8 , libc::size_t r9 , libc::size_t rax) {
	asm("mov %rcx, %r10\n");
	asm("mov %0, %%rax\n"::"r"(rax));
	asm("syscall\n");
	libc::size_t out;
	asm("mov %%rax, %0\n":"=r"(out));
	return out;
}

libc::size_t std::sys::syscall(libc::size_t rax) {
	return syscall_cpp_impl(0, 0, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rax) {
	return syscall_cpp_impl(rdi, 0, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rax) {
	return syscall_cpp_impl(rdi, rsi, 0, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t rax) {
	return syscall_cpp_impl(rdi, rsi, rdx, 0, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t rax) {
	return syscall_cpp_impl(rdi, rsi, rdx, r10, 0, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8, libc::size_t rax) {

	return syscall_cpp_impl(rdi, rsi, rdx, r10, r8, 0, rax);
}
libc::size_t std::sys::syscall(libc::size_t rdi, libc::size_t rsi, libc::size_t rdx, libc::size_t r10, libc::size_t r8, libc::size_t r9, libc::size_t rax) {
	return syscall_cpp_impl(rdi, rsi, rdx, r10, r8, r9, rax);
}

