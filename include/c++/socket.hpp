#pragma once

namespace libc {
namespace net {
#include "../types/struct_socket.h"
}
}
#include "../net/sock.h"
#include "file.hpp"

namespace std {
namespace net {
class Socket : public io::File {
	Socket(int fd_): io::File(fd_) {}

public:
	Socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol);
	int bind(libc::uint16 port);
	int listen(libc::size_t backlog);
	Socket accept();
};
}
}
