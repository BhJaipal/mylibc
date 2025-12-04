#ifndef UNISTD_H
#define UNISTD_H

#include "types.h"

extern char **environ;

extern void exit(int status);
extern int kill(int pid, int sig);
extern int getpid();
extern int pause();
extern int alarm(uint32 seconds);
extern int vfork();
extern int fork();
extern int execve(const char *filename, const char *const *argv, const char *const *envp);

# define SEEK_SET	0	/* Seek from beginning of file.  */
# define SEEK_CUR	1	/* Seek from current position.  */
# define SEEK_END	2	/* Seek from end of file.  */
extern int lseek(uint64 fd, int64 offset, uint32 whence);

extern int chdir(const char *path);
extern char* getcwd(char *buf, size_t size);
extern char* getenv(char *key);

#endif // !UNISTD_H
