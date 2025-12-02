#include <file.hpp>
#include <system.hpp>
#include <syscall_enum.h>

extern "C" {
#include <string.hpp>
namespace libc {
#include <format.h>
	namespace io {
		int read(int fd, char *msg, int len) {
			return std::sys::syscall(fd, (libc::size_t)msg, len, SYS_read);
		}
		int write(int fd, const char *msg, int len) {
			return std::sys::syscall(fd, (libc::size_t)msg, len, SYS_write);
		}
		int pread(unsigned int fd, char *buf, size_t count, size_t pos) {
			return std::sys::syscall(fd, (libc::size_t)buf, count, pos, SYS_pread64);
		}
		int pwrite(unsigned int fd, char *buf, size_t count, size_t pos) {
			return std::sys::syscall(fd, (libc::size_t)buf, count, pos, SYS_pwrite64);
		}
		int open(const char *path, FileOpenFlags flags, ...) {
			long fd;
			if (!(flags & O_CREAT)) {
				fd = std::sys::syscall((libc::size_t)path, flags, 044);
			} else {
				libc::va_list args;
				va_start(args, (int)flags);
				fd = std::sys::syscall((libc::size_t)path, flags, va_arg(args, int));
				va_end(args);
			}
			return fd;
		}
		void close(int fd) {
			std::sys::syscall(fd, SYS_close);
		}
		int dprintf(int fd, const char *fmt, ...) {
			libc::va_list args;
			va_start(args, fmt);
			char* out = libc::format_args(fmt, args);
			va_end(args);
			return write(fd, out, strlen(out));
		}
	}
}
}

namespace std {
	namespace io {
	int File::write(const char *msg, libc::size_t n) {
		if (n == INT64_MAX) {
			return libc::io::write(fd, msg, libc::strlen(msg));
		} else return libc::io::write(fd, msg, n);
	}
	int File::read(char *msg, libc::size_t n) {
		return libc::io::read(fd, msg, n);
	}

	int File::fwrite(const char *fmt, ...) {
		libc::va_list args;
		va_start(args, fmt);
		char* out = libc::format_args(fmt, args);
		va_end(args);
		return write(out);
	}

	void File::close() {
		if (closable) libc::io::close(fd);
		else {
			stderr().write("\e[31mError:\e[0m This file is cannot be closed\b");
		}
	}
	}
}
