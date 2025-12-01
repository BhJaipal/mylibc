#pragma once

#include "libc.hpp"
typedef unsigned long size_t;
#include "../string.h"

namespace libc {
namespace io {
extern "C" {
#include "../io.h"
}
}
#include "../format.h"
}
#include "system.hpp"
#include "../syscall_enum.h"

namespace std {
namespace io {
class File {
protected:
	libc::size_t fd;
	bool closable;
	File& closable_(bool val) {
		closable = val; return *this;
	}
	File() { closable = true; }

public:
	static File stdout() {
		return File(1).closable_(false);
	}
	static File stdin() {
		return File(0).closable_(false);
	}
	static File stderr() {
		return File(2).closable_(false);
	}

	File(libc::size_t fd_): fd(fd_) { closable = true; }
	int write(const char *msg, libc::size_t n = INT64_MAX) {
		if (n == INT64_MAX) {
			return libc::io::write(fd, msg, strlen(msg));
		} else return libc::io::write(fd, msg, n);
	}
	int read(char *msg, libc::size_t n = INT64_MAX) {
		if (n == INT64_MAX) {
			return libc::io::read(fd, msg, strlen(msg));
		} else return libc::io::read(fd, msg, n);
	}
	int fwrite(const char *fmt, ...) {
		libc::va_list args;
		va_start(args, fmt);
		char* out = libc::format_args(fmt, args);
		va_end(args);
		return write(out);
	}
	void close() {
		if (closable) sys::syscall(fd, SYS_close);
		else {
			stderr().write("\e[31mError:\e[0m This file is cannot be closed\b");
		}
	}
};
}
}
