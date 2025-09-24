#ifndef MY_TEST_H
#define MY_TEST_H

#include "c-impl.h"
#include "file.h"

#define EXPECT(condition, statement) \
	if (!(condition)) {\
		print("\t\e[91m[Error]\e[0m: ");\
		println(statement);				\
		printf("At %s.c\n", file);\
		return 1;						\
	}

#define TEST(body)  \
	int do_test(int argc, char **argv) {\
		char *file = argv[1];			\
		body;							\
		return 0;						\
}

#endif // !MY_TEST_H
