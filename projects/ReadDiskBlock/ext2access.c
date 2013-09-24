// May 22nd, 2009.
//
// This file is where you'll finish the implementation of the various
// routines that understand and retrieve data from ext2's on-disk data
// structure.  Start from the project 3 light web page, and follow
// the directions on it to figure out what to do next.

#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "inc/types.h"
#include "inc/blockgroup_descriptor.h"
#include "inc/directoryentry.h"
#include "inc/ext2access.h"
#include "inc/inode.h"
#include "inc/superblock.h"

// Read the superblock from the disk image associated with 'fd' into
// memory, and returns a pointer to the superblock.
struct os_superblock_t *read_superblock(int fd) {
  // 1. Use malloc() to allocate enough space for an in-memory
  // representation of the superblock.  Be sure to verify that malloc
  // worked!
  struct os_superblock_t *sb = malloc(sizeof(struct os_superblock_t));
  assert(sb != NULL);

  // 2. Use lseek() and read() to read the superblock from disk
  // into the space you malloc'ed.
  assert(lseek(fd, (off_t) 1024, SEEK_SET) == (off_t) 1024);
  assert(read(fd, (void *) sb, sizeof(struct os_superblock_t)) ==
         sizeof(struct os_superblock_t));

  //  3. Return a pointer to the malloc'ed superblock.
  return sb;
}

struct os_superblock_t *read_bgdt1(int fd) {
  // 1. Use malloc() to allocate enough space for an in-memory
  // representation of the superblock.  Be sure to verify that malloc
  // worked!
  struct os_superblock_t *sb = malloc(sizeof(struct os_blockgroup_descriptor_t));
  assert(sb != NULL);

  // 2. Use lseek() and read() to read the superblock from disk
  // into the space you malloc'ed.
  assert(lseek(fd, (off_t) 2*1024, SEEK_SET) == (off_t) 2*1024);
  assert(read(fd, (void *) sb, sizeof(struct os_blockgroup_descriptor_t)) ==
         sizeof(struct os_blockgroup_descriptor_t));

  //  3. Return a pointer to the malloc'ed superblock.
  return sb;
}

struct os_inode_t *read_dataBlock(int fd, int offset) {
  // 1. Use malloc() to allocate enough space for an in-memory
  // representation of the superblock.  Be sure to verify that malloc
  // worked!
  struct os_inode_t *sb = malloc(sizeof(struct os_inode_t));
  assert(sb != NULL);

  offset = offset + 4;

  // 2. Use lseek() and read() to read the superblock from disk
  // into the space you malloc'ed.
  assert(lseek(fd, (off_t) (offset*1024), SEEK_SET) == (off_t) (offset*1024));
  assert(read(fd, (void *) sb, sizeof(struct os_inode_t)) ==
         sizeof(struct os_inode_t));

  //  3. Return a pointer to the malloc'ed superblock.
  return sb;
}

struct os_inode_t *read_dataBlock2(int fd, int offset1, int offset2) {

  struct os_inode_t *sb = malloc(sizeof(struct os_inode_t));
  assert(sb != NULL);

  assert(lseek(fd, (off_t) (offset1*1024 + offset2*128), SEEK_SET) == (off_t) (offset1*1024 + offset2*128));
  assert(read(fd, (void *) sb, sizeof(struct os_inode_t)) ==
        sizeof(struct os_inode_t));
  return sb;
}

struct os_direntry_t *read_dirBlock(int fd, int offset1, int offset2)
{
	  // 1. Use malloc() to allocate enough space for an in-memory
	  // representation of the superblock.  Be sure to verify that malloc
	  // worked!
	  struct os_direntry_t *sb = malloc(sizeof(struct os_direntry_t));
	  assert(sb != NULL);

	  // 2. Use lseek() and read() to read the superblock from disk
	  // into the space you malloc'ed.
	  assert(lseek(fd, (off_t) (offset2*1024 + offset1), SEEK_SET) == (off_t) (offset2*1024 + offset1));
	  read(fd, (void *) sb, 256);

	  return sb;
}

int search (int fd, int offset_num2, char name[10])
{
	int offset_num1 = 0;
	char *tempName;

	int templen1;
	int templen2;

	printf ("search for %s\n", name);
	tempName = (char *)malloc(512*sizeof(char));
	printf ("i_number      rec_le       name_len     name\n");
	while (offset_num1 < 1024)
	  {
	  	  struct os_direntry_t *dirblock = read_dirBlock(fd, offset_num1, offset_num2);
	  	  strncpy (tempName, dirblock->file_name, dirblock->name_len);
	  	  tempName[dirblock->name_len] = '\0';
	  	  printf ("%5d%13d%14d\t%s\n", dirblock->inode, dirblock->rec_len, dirblock->name_len, tempName);
	  	  offset_num1 = offset_num1 + dirblock->rec_len;

	  	  if (strncmp (name, tempName, dirblock->name_len) == 0)
	  	  {
	  		  printf ("Found %s: ino %d\n", dirblock->file_name, dirblock->inode);
	  		  return dirblock->inode;
	  	  }
	  }

	return 0;
}


