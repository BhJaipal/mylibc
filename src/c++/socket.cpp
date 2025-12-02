#include <socket.hpp>
#include <system.hpp>
#include <types/struct_socket.h>

extern "C" {
#include <net/in.h>
}
#include <net/sock.h>
#include <syscall_enum.h>

namespace std {
	namespace net {
	int Socket::bind(libc::uint16 port) {
		libc::net::SocketAddrIn addr;
		addr.sin_family = PF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		return sys::syscall(SYS_bind, fd, (libc::size_t)&addr, sizeof(addr));
	}

	Socket::Socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol) {
		fd = sys::syscall(SYS_socket, domain, type, protocol);
		if (fd == -1) {
			stdout().write("Failed to connect socket\n");
			sys::syscall(SYS_exit, 1);
		}
	}
	int Socket::listen(libc::size_t backlog) {
		return sys::syscall(SYS_listen, fd, backlog);
	}
	Socket Socket::accept() {
		libc::net::SocketAddrIn client_Addr;
		socklen_t client_len = sizeof(client_Addr);
		int client = sys::syscall(SYS_accept, fd, (libc::size_t)&client_Addr, (libc::size_t)&client_len);
		return Socket(client);
	}
	}
}
