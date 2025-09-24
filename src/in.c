#include <net/in.h>

long htonl(long l) {
	long out = ((l & 0xff) << (8 * 7));
	out |= (((l >> 8) & 0xff) << (8 * 6));
	out |= (((l >> (8 * 2)) & 0xff) << (8 * 5));
	out |= (((l >> (8 * 3)) & 0xff) << (8 * 4));
	out |= (((l >> (8 * 4)) & 0xff) << (8 * 3));
	out |= (((l >> (8 * 5)) & 0xff) << (8 * 2));
	out |= (((l >> (8 * 6)) & 0xff) << (8));
	out |= (((l >> (8 * 7)) & 0xff) << (0));
	return out;
}
short htons(short l) {
	short out = ((l & 0xff) << (8 * 3));
	out |= (((l >> 8) & 0xff) << (8 * 2));
	out |= (((l >> (8 * 2)) & 0xff) << (8));
	out |= (((l >> (8 * 3)) & 0xff) << (0));
	return out;
}
