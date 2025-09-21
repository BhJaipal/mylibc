#ifndef STAT_H

#include "types.h"

typedef struct {
	uint32 st_dev;		/* Device */
	uint64 st_ino;		/* File serial number */

    uint64 st_nlink;	/* Link count.  */
    uint64 st_mode; 	/* File mode.  */

    uint32 st_uid;		/* User ID of the file's owner.	*/
    uint32 st_gid;		/* Group ID of the file's group.*/
	int __pad0;

    uint32 st_rdev; 	/* Device number, if device.  */
    int64 st_size;			/* Size of file, in bytes.  */

    int64 st_blksize;	/* Optimal block size for I/O.  */
    int64 st_blocks;		/* Number 512-byte blocks allocated. */

    struct timespec st_atim;			/* Time of last access.  */
    struct timespec st_mtim;			/* Time of last modification.  */
    struct timespec st_ctim;			/* Time of last status change.  */

	int __glibc_reserved[3];
} Stat;

/* stat() and fstatat() retrieve information about the file pointed
       to by path;*/
int stat(const char* path, Stat *statbuf);

/* fstat() is identical to stat(), except that the file about which
       information is to be retrieved is specified by the file descriptor
       fd.*/
int fstat(int fd, Stat *statbuf);

/* lstat() is identical to stat(), except that if path is a symbolic
       link, then it returns information about the link itself, not the
       file that the link refers to.*/
int lstat(const char* path, Stat *statbuf);

struct statx_timestamp {
	int64 tv_sec;    /* Seconds since the Epoch (UNIX time) */
	uint32 tv_nsec;   /* Nanoseconds since tv_sec */
};
typedef struct {
	uint32 stx_mask;        /* Mask of bits indicating
		           filled fields */
	uint32 stx_blksize;     /* Block size for filesystem I/O */
	uint64 stx_attributes;  /* Extra file attribute indicators */
	uint32 stx_nlink;       /* Number of hard links */
	uint32 stx_uid;         /* User ID of owner */
	uint32 stx_gid;         /* Group ID of owner */
	uint16 stx_mode;        /* File type and mode */
	uint64 stx_ino;         /* Inode number */
	uint64 stx_size;        /* Total size in bytes */
	uint64 stx_blocks;      /* Number of 512B blocks allocated */
	uint64 stx_attributes_mask;
	/* Mask to show what's supported
	in stx_attributes */

	/* The following fields are file timestamps */
	struct statx_timestamp stx_atime;  /* Last access */
	struct statx_timestamp stx_btime;  /* Creation */
	struct statx_timestamp stx_ctime;  /* Last status change */
	struct statx_timestamp stx_mtime;  /* Last modification */

	/* If this file represents a device, then the next two
	   fields contain the ID of the device */
	uint32 stx_rdev_major;  /* Major ID */
	uint32 stx_rdev_minor;  /* Minor ID */

	/* The next two fields contain the ID of the device
	   containing the filesystem where the file resides */
	uint32 stx_dev_major;   /* Major ID */
	uint32 stx_dev_minor;   /* Minor ID */

	uint64 stx_mnt_id;      /* Mount ID */

	/* Direct I/O alignment restrictions */
	uint32 stx_dio_mem_align;
	uint32 stx_dio_offset_align;
	uint64 stx_subvol;      /* Subvolume identifier */

	/* Direct I/O atomic write limits */
	uint32 stx_atomic_write_unit_min;
	uint32 stx_atomic_write_unit_max;
	uint32 stx_atomic_write_segments_max;

	/* File offset alignment for direct I/O reads */
	uint32 stx_dio_read_offset_align;

	/* Direct I/O atomic write max opt limit */
	uint32 stx_atomic_write_unit_max_opt;
} Statx;
int statx(int dirfd, char *pathname, int flags, uint32 mask, Statx *statbuf);

#endif // !STAT_H
