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
		return sys::syscall(fd, (libc::size_t)&addr, sizeof(addr), SYS_bind);
	}

	Socket::Socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol) {
		fd = sys::syscall(domain, type, protocol, SYS_socket);
		if (fd == -1) {
			stdout().write("Failed to connect socket\n");
			sys::syscall(1, SYS_exit);
		}
	}
	int Socket::listen(libc::size_t backlog) {
		return sys::syscall(fd, backlog, SYS_listen);
	}
	Socket Socket::accept() {
		libc::net::SocketAddrIn client_Addr;
		socklen_t client_len = sizeof(client_Addr);
		int client = sys::syscall(fd, (libc::size_t)&client_Addr, (libc::size_t)&client_len, SYS_accept);
		return Socket(client);
	}
	}
}
