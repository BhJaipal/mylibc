#ifndef NET_SOCkET_H
#define NET_SOCkET_H

#include "../libc_struct/socket.h"

typedef enum {
  SOCK_STREAM = 1,  	/* Sequenced, reliable, connection-based
 			   byte streams.  */
  SOCK_DGRAM = 2, 	/* Connectionless, unreliable datagrams
 			   of fixed maximum length.  */
  SOCK_RAW = 3, 		/* Raw protocol interface.  */
  SOCK_RDM = 4, 		/* Reliably-delivered messages.  */
  SOCK_SEQPACKET = 5,	/* Sequenced, reliable, connection-based,
 			   datagrams of fixed maximum length.  */
  SOCK_DCCP = 6,	/* Datagram Congestion Control Protocol.  */
  SOCK_PACKET = 10, 	/* Linux specific way of getting packets
 			   at the dev level.  For writing rarp and
 			   other similar things on the user level. */
  /* Flags to be ORed into the type parameter of socket and socketpair and
     used for the flags parameter of paccept.  */
  SOCK_CLOEXEC = 02000000, /* Atomically set close-on-exec flag for the
 			   new descriptor(s).  */
  SOCK_NONBLOCK = 00004000 /* Atomically mark descriptor(s) as
 			   non-blocking.  */
} SocketType;

/* Protocol families.  */
typedef enum {
	PF_UNSPEC= 0,	/* Unspecified.  */
	PF_LOCAL= 1,	/* Local to host (pipes and file-domain).  */
	PF_UNIX= 	PF_LOCAL, /* POSIX name for PF_LOCAL.  */
	PF_FILE= 	PF_LOCAL, /* Another non-standard name for PF_LOCAL.  */
	PF_INET= 	2,	/* IP protocol family.  */
	PF_AX25= 	3,	/* Amateur Radio AX.25.  */
	PF_IPX= 	4,	/* Novell Internet Protocol.  */
	PF_APPLETALK= 5,	/* Appletalk DDP.  */
	PF_NETROM= 6,	/* Amateur radio NetROM.  */
	PF_BRIDGE= 7,	/* Multiprotocol bridge.  */
	PF_ATMPVC= 8,	/* ATM PVCs.  */
	PF_X25= 	9,	/* Reserved for X.25 project.  */
	PF_INET6= 10,	/* IP version 6.  */
	PF_ROSE= 	11,	/* Amateur Radio X.25 PLP.  */
	PF_DECnet= 12,	/* Reserved for DECnet project.  */
	PF_NETBEUI= 13, 	/* Reserved for 802.2LLC project.  */
	PF_SECURITY= 14,	/* Security callback pseudo AF.  */
	PF_KEY= 	15,	/* PF_KEY key management API.  */
	PF_NETLINK= 16,
	PF_ROUTE= PF_NETLINK, /* Alias to emulate 4.4BSD.  */
	PF_PACKET= 17,	/* Packet family.  */
	PF_ASH= 	18,	/* Ash.  */
	PF_ECONET= 19,	/* Acorn Econet.  */
	PF_ATMSVC= 20,	/* ATM SVCs.  */
	PF_RDS= 	21, 	/* RDS sockets.  */
	PF_SNA= 	22, 	/* Linux SNA Project */
	PF_IRDA= 	23, 	/* IRDA sockets.  */
	PF_PPPOX= 24,	/* PPPoX sockets.  */
	PF_WANPIPE= 25, 	/* Wanpipe API sockets.  */
	PF_LLC= 	26, 	/* Linux LLC.  */
	PF_IB= 	27, 	/* Native InfiniBand address.  */
	PF_MPLS= 	28, 	/* MPLS.  */
	PF_CAN= 	29, 	/* Controller Area Network.  */
	PF_TIPC= 	30, 	/* TIPC sockets.  */
	PF_BLUETOOTH= 31,	/* Bluetooth sockets.  */
	PF_IUCV= 	32, 	/* IUCV sockets.  */
	PF_RXRPC= 33,	/* RxRPC sockets.  */
	PF_ISDN= 	34, 	/* mISDN sockets.  */
	PF_PHONET= 35,	/* Phonet sockets.  */
	PF_IEEE802154= 36,	/* IEEE 802.15.4 sockets.  */
	PF_CAIF= 	37, 	/* CAIF sockets.  */
	PF_ALG= 	38, 	/* Algorithm sockets.  */
	PF_NFC= 	39, 	/* NFC sockets.  */
	PF_VSOCK= 40,	/* vSockets.  */
	PF_KCM= 	41, 	/* Kernel Connection Multiplexor.  */
	PF_QIPCRTR= 42, 	/* Qualcomm IPC Router.  */
	PF_SMC= 	43, 	/* SMC sockets.  */
	PF_XDP= 	44, 	/* XDP sockets.  */
	PF_MCTP= 	45, 	/* Management component transport protocol.  */
	PF_MAX= 	46, 	/* For now..  */
} ProtocolFamily;

typedef unsigned in_addr_t;
typedef unsigned socklen_t;

/* Address to accept any incoming messages.  */
#define	INADDR_ANY		((in_addr_t) 0x00000000)
/* Address to send to all hosts.  */
#define	INADDR_BROADCAST	((in_addr_t) 0xffffffff)
/* Address indicating an error return.  */
#define	INADDR_NONE		((in_addr_t) 0xffffffff)
/* Dummy address for source of ICMPv6 errors converted to IPv4 (RFC
   7600).  */
#define	INADDR_DUMMY		((in_addr_t) 0xc0000008)

/* Network number for local host loopback.  */
#define	IN_LOOPBACKNET		127
/* Address to loopback in software to local host.  */
#ifndef INADDR_LOOPBACK
# define INADDR_LOOPBACK	((in_addr_t) 0x7f000001) /* Inet 127.0.0.1.  */
#endif

/* Defines for Multicast INADDR.  */
#define INADDR_UNSPEC_GROUP	((in_addr_t) 0xe0000000) /* 224.0.0.0 */
#define INADDR_ALLHOSTS_GROUP	((in_addr_t) 0xe0000001) /* 224.0.0.1 */
#define INADDR_ALLRTRS_GROUP    ((in_addr_t) 0xe0000002) /* 224.0.0.2 */
#define INADDR_ALLSNOOPERS_GROUP ((in_addr_t) 0xe000006a) /* 224.0.0.106 */
#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff) /* 224.0.0.255 */

int socket(ProtocolFamily domain, SocketType type, ProtocolFamily protocol);
int bind(int sockfd, const SocketAddr *addr, socklen_t len);
int listen(int sockfd, int backlog);
int accept(int sockfd, const SocketAddr *addr, socklen_t *len);


#endif // !NET_SOCkET_H
