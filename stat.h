#ifndef STAT_H
#include "libc_struct/stat.h"

/* stat() and fstatat() retrieve information about the file pointed
       to by path;*/
extern int stat(const char* path, Stat *statbuf);

/* fstat() is identical to stat(), except that the file about which
       information is to be retrieved is specified by the file descriptor
       fd.*/
extern int fstat(int fd, Stat *statbuf);

/* lstat() is identical to stat(), except that if path is a symbolic
       link, then it returns information about the link itself, not the
       file that the link refers to.*/
extern int lstat(const char* path, Stat *statbuf);
extern int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf);

#endif // !STAT_H
