#include <file.hpp>
#include <net/sock.h>
#include <socket.hpp>

int main (int argc, char *argv[]) {
	std::net::Socket server(PF_INET, SOCK_STREAM, PF_UNSPEC);
	if (server.bind(5173) < 0) {
		std::io::File::stdout().write("Failed to bind port to socket\n");
		return 1;
	}
	if (server.listen(5) < 0) {
		std::io::File::stdout().write("Failed to listen to server\n");
		return 1;
	}
	std::io::File::stdout().write("Server started at http://localhost:5173/\n");
	while (true) {
		std::net::Socket client = server.accept();
		char msg[50];
		int n;
		std::io::File::stdout().write("Client Request: \n");
		do {
            n = client.read(msg, 50);
			std::io::File::stdout().write(msg, n);
			std::io::File::stdout().fwrite("Read: %i\n", n);
        } while (n >= 49);
		client.read(msg, 0);

		char res[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello world\n";
		client.write(res);
		client.close();
	}
	return 0;
}
