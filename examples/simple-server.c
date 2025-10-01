#include "net/in.h"
#include <net/socket.h>
#include <file.h>

int main() {
	int server = socket(PF_INET, SOCK_STREAM, PF_UNSPEC);
	if (server < -1) {
		printf("Can't create socket\n");
		return 1;
	}
	SocketAddrIn addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(5173);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server, (SocketAddr *)&addr, sizeof(addr)) < 0) {
		printf("Failed to bind socket at port %x\n", htons(5173));
		return 1;
	}
	if (listen(server, 5) < 0) {
		printf("Failed to listen\n");
		return 1;
	}
	printf("Server started at http://localhost:5173/\n");
	while (1) {
		SocketAddrIn client_Addr;
		socklen_t client_len = sizeof(client_Addr);
		int client = accept(server, (SocketAddr *)&client_Addr, &client_len);
		write(client, "HTTP/1.1 200 OK\r\nContent-type: text-plain\r\n\r\nHello World\n", 57);
		close(client);
	}
	return 0;
}
