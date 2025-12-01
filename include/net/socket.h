#ifndef NET_SOCkET_H
#define NET_SOCkET_H
#include "sock.h"
#include "../types/struct_socket.h"

int socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol);
int bind(int sockfd, const SocketAddr *addr, socklen_t len);
int listen(int sockfd, int backlog);
int accept(int sockfd, const SocketAddr *addr, socklen_t *len);


#endif // !NET_SOCkET_H
