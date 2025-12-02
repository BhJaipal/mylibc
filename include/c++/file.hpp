#pragma once

#include "libc.hpp"

namespace libc {
namespace io {
extern "C" {
typedef enum {
	O_ACCMODE= 0003,
	O_RDONLY= 00,
	O_WRONLY= 01,
	O_RDWR= 02,
	O_CREAT= 0100,
	O_EXCL= 0200,
	O_NOCTTY= 0400,
	O_TRUNC= 01000,
	O_APPEND= 02000,
	O_NONBLOCK= 04000,
	O_NDELAY= O_NONBLOCK,
	O_SYNC= 04010000,
	O_FSYNC= O_SYNC,
	O_ASYNC= 020000,
	__O_LARGEFILE= 0100000,
	__O_DIRECTORY= 0200000,
	__O_NOFOLLOW= 0400000,
	__O_CLOEXEC= 02000000,
	__O_DIRECT= 040000,
	__O_NOATIME= 01000000,
	__O_PATH= 010000000,
	__O_DSYNC= 010000,
	__O_TMPFILE= (020000000 | __O_DIRECTORY)
} FileOpenFlags;


int read(int fd, char *msg, int len);
int write(int fd, const char *msg, int len);
int open(const char *path, FileOpenFlags flags, ...);
void close(int fd);
int pread(unsigned int fd, char *buf, size_t count, size_t pos);
int pwrite(unsigned int fd, char *buf, size_t count, size_t pos);

int dprintf(int fd, const char *fmt, ...);
}
}
}

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
	int write(const char *msg, libc::size_t n = INT64_MAX);
	int read(char *msg, libc::size_t n = INT64_MAX);
	int fwrite(const char *fmt, ...);
	void close();
};
}
}
