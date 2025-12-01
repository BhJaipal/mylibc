#include <system.hpp>

int main (int argc, char *argv[]) {
	std::sys::syscall(1, 60);
	return 0;
}
