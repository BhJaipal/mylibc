#ifndef TYPES_H
#define TYPES_H

#define INT_TYPE(T, BITS) \
	typedef T int##BITS;  \
	typedef unsigned T uint##BITS;

INT_TYPE(char, 8);
INT_TYPE(short, 16);
INT_TYPE(int, 32);
INT_TYPE(long, 64);
#define true 1
#define false 0

typedef unsigned long size_t;

typedef int pid_t;
typedef int64 time_t;
typedef int64 suseconds_t;
struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};
struct timespec {
  long tv_sec;		/* Seconds.  */
  long tv_nsec;	/* Nanoseconds.  */
};

#define null (void*)0

#endif // !TYPES_H
