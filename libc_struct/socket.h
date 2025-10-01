#ifndef STRUCT_SOCKET_H
#define STRUCT_SOCKET_H

typedef unsigned short sa_family_t;

typedef struct {
	unsigned s_addr;
} InAddr;

typedef struct {
    union {
		unsigned char	__u6_addr8[16];
		sa_family_t __u6_addr16[8];
		unsigned __u6_addr32[4];
    } __in6_u;
#define s6_addr			__in6_u.__u6_addr8
#define s6_addr16		__in6_u.__u6_addr16
#define s6_addr32		__in6_u.__u6_addr32
} InAddr6;

#define SOCKADDR_COMMON_SIZE sizeof(sa_family_t)
#define SOCKADDR_COMMON(prefix) sa_family_t prefix##family

typedef struct {
	SOCKADDR_COMMON(sa_);
	char sa_data[14];
} SocketAddr;

typedef struct {
	SOCKADDR_COMMON(sin_);
	sa_family_t sin_port;
	InAddr sin_addr;
	unsigned char sin_zero[sizeof(SocketAddr) 
		- SOCKADDR_COMMON_SIZE
		- sizeof(sa_family_t) 
		- sizeof(InAddr) 
	];
} SocketAddrIn;

typedef struct {
	SOCKADDR_COMMON(sin6_);
	sa_family_t sin6_port;
	unsigned sin6_flowinfo;
	InAddr6 sin6_addr;
	unsigned sin6_scope_id;
} SocketAddrIn6;

#endif // !STRUCT_SOCKET_H
