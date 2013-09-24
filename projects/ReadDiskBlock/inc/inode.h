// Copyright 2009 Steve Gribble (gribble [at] cs.washington.edu)
// May 22nd, 2009
//
// This file defines the structure of an ext2 inode.
//
// Quoting from http://www.nongnu.org/ext2-doc/ext2.html:
//
//// The inode (index node) is a fundamental concept in the ext2
//// filesystem. Each object in the filesystem is represented by an
//// inode. The inode structure contains pointers to the filesystem
//// blocks which contain the data held in the object and all of the
//// metadata about an object except its name.
////
//// There are pointers to the first 12 blocks which contain the
//// file's data in the inode. There is a pointer to an indirect block
//// (which contains pointers to the next set of blocks), a pointer to
//// a doubly-indirect block (which contains pointers to indirect
//// blocks) and a pointer to a trebly-indirect block (which contains
//// pointers to doubly-indirect blocks). 
////
//// All the inodes are stored in inode tables, with one inode table
//// per block group. 

#ifndef EXT2READER_INC_INODE_H
#define EXT2READER_INC_INODE_H

#include "types.h"


// These constants define the inode number of various special
// inodes (such as the inode of the root directory) within an
// ext2 file system.  You'll only need to understand and use
// EXT2_ROOT_INO.

#define EXT2_BAD_INO          1  // Bad blocks inode
#define EXT2_ROOT_INO         2  // Root directory inode
#define EXT2_ACL_IDX_INO      3  // ACL index inode (deprecated)
#define EXT2_ACL_DATA_INO     4  // ACL data inode (deprecated)
#define EXT2_BOOT_LOADER_INO  5  // boot loader inode
#define EXT2_UNDEL_DIR_INO    6  // undelete directory inode

// Here are other constants used within the inode structure itself.

#define EXT2_S_IFSOCK 0xC000
#define EXT2_S_IFLNK  0xA000
#define EXT2_S_IFREG  0x8000
#define EXT2_S_IFBLK  0x6000
#define EXT2_S_IFDIR  0x4000
#define EXT2_S_IFCHR  0x2000
#define EXT2_S_IFIFO  0x1000
#define EXT2_S_ISUID  0x0800
#define EXT2_S_ISGID  0x0400
#define EXT2_S_ISVTX  0x0200
#define EXT2_S_IRUSR  0x0100
#define EXT2_S_IWUSR  0x0080
#define EXT2_S_IXUSR  0x0040
#define EXT2_S_IRGRP  0x0020
#define EXT2_S_IWGRP  0x0010
#define EXT2_S_IXGRP  0x0008
#define EXT2_S_IROTH  0x0004
#define EXT2_S_IWOTH  0x0002
#define EXT2_S_IXOTH  0x0001

// This structure represents an inode.  In ext2, an inode is 128 bytes.

struct os_inode_t {
	unsigned short i_mode;          // will be explained in detail
	os_uint16_t  i_uid;                       // ownerID
	os_uint32_t  i_size;                    // file size in bytes
	os_uint32_t  i_atime;                   // time fields
	os_uint32_t  i_ctime;
	os_uint32_t  i_mtime;
	os_uint32_t  i_dtime;
	  os_uint16_t  i_gid;                     // groupID
	  os_uint16_t  i_links_count;             // link count
	  os_uint32_t  i_blocks;                  // IGNORE
	  os_uint32_t  i_flags;                   // IGNORE
	  os_uint32_t  i_reserved1;               // IGNORE
	  os_uint32_t  i_block[15];               // See details below

	  // IGNORE THE FOLLOWING
	  os_uint32_t  i_version;
	  os_uint32_t  i_file_acl;
	  os_uint32_t  i_dir_acl;
	  os_uint32_t  i_faddr;
	    os_uint8_t   i_frag;
	    os_uint8_t   i_fsize;
	    os_uint16_t  i_pad1;
	    os_uint32_t  i_reserved2[2];

};

#endif // EXT2READER_INC_INODE_H
