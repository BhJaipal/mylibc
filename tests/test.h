#ifndef MY_TEST_H
#define MY_TEST_H

#include "c-impl.h"
#include "file.h"

struct testcase {
	char name[20];
	int(*fn)(int, char**);
};
extern int(*tests[10])(int, char**);
extern int test_count;
extern char test_name[20];

#define EXPECT(condition) \
	if (!(condition)) {\
		println("\t\e[91m[" #condition "]\e[0m: failed");\
		return 1;						\
	} else\
		println("\t\e[92m[" #condition "]\e[0m: passed");\
	next++;

#define TEST(name) \
	int name##_test(int argc, char **argv) {\
		strcpy(test_name, #name);\
		int next = 0;\
		println("Testing " #name);

#define ENDTEST return 0; }

#define STR(n) #n

#define ENABLE(...) \
		void enable() {\
		int (*tests_[])(int, char**) = {__VA_ARGS__};\
		for (size_t i = 0; i < sizeof(tests_)/sizeof(tests_[0]); i++) {\
			tests[i] = tests_[i];\
			test_count++;\
		}\
	}


#endif // !MY_TEST_H
