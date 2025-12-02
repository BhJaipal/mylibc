#include <file.hpp>
#include <system.hpp>
#include <syscall_enum.h>

extern "C" {
#include <string.hpp>
namespace libc {
#include <format.h>
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
