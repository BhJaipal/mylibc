#ifndef FS_H
#define FS_H

#include "types.h"
/* File types for `d_type'.  */
enum {
    DT_UNKNOWN = 0, // The file type is unknown.
    DT_FIFO = 1,	// This is a named pipe (FIFO).
    DT_CHR = 2, 	// This is a character device.
    DT_DIR = 4, 	// This is a directory.
    DT_BLK = 6, 	// This is a block device.
    DT_REG = 8, 	// This is a regular file.
    DT_LNK = 10,	// This is a symbolic link.
    DT_SOCK = 12,	// This is a UNIX domain socket.
    DT_WHT = 14 	// whiteout
};

typedef struct {
	uint64 d_ino;
	long d_off;
	uint16 d_reclen;
	char d_type;
	char d_name[];
} linux_dirent;

typedef struct {
	unsigned long  d_ino;     /* Inode number */
	unsigned long  d_off;     /* Not an offset; see below */
	unsigned short d_reclen;  /* Length of this linux_dirent */
	unsigned char  d_type;
	char           d_name[];  /* Filename (null-terminated) */
						/* length is actually (d_reclen - 2 -
						offsetof(struct linux_dirent, d_name)) */
} linux_dirent64;

size_t getdents64(int fd, linux_dirent64 *dirp, size_t count);
size_t getdents(int fd, linux_dirent *dirp, size_t count);


extern char *get_current_dir_name(void);

#endif // !FS_H
