#pragma once

namespace libc {
namespace net {
#include "../net/sock.h"
#include "../net/in.h"
#include "../types/struct_socket.h"
}
}
#include "file.hpp"
#include "system.hpp"

#include "../syscall_enum.h"

namespace std {
namespace net {
using libc::net::in_addr_t;
class Socket : io::File {
	Socket(int fd_): io::File(fd_) {}

public:
	Socket(libc::net::ProtocolFamily domain, libc::net::SocketType type, libc::net::ProtocolFamily protocol) {
		fd = sys::syscall(domain, type, protocol, SYS_socket);
	}
	int bind(libc::uint16 port) {
		libc::net::SocketAddrIn addr;
		addr.sin_family = libc::net::PF_INET;
		addr.sin_port = libc::net::htons(5173);
		addr.sin_addr.s_addr = libc::net::htonl(INADDR_ANY);
		return sys::syscall(fd, (libc::size_t)&addr, sizeof(addr), SYS_bind);
	}
	int listen(libc::size_t backlog) {
		return sys::syscall(fd, backlog, SYS_listen);
	}
	Socket accept() {
		libc::net::SocketAddrIn client_Addr;
		libc::net::socklen_t client_len = sizeof(client_Addr);
		int client = sys::syscall(fd, (libc::size_t)&client_Addr, (libc::size_t)&client_len, SYS_accept);
		return Socket(fd);
	}
};
}
}
