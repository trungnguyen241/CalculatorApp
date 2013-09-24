#include <stdio.h>
//#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "inc/types.h"
#include "inc/blockgroup_descriptor.h"
#include "inc/directoryentry.h"
#include "inc/inode.h"
#include "inc/superblock.h"
#include "inc/ext2access.h"
#include "inc/testcode.h"

// Usage:  ext2reader diskfile_name
int main(int argc, char **argv) {
  int temp = 0;
  int temp1 = 0;
  int offset_num1 = 0;
  int offset_num2 = 0;
  int InodesBeginBlock;
  char *tempName;
  int i = 0, j = 1;
  char *name[10];
  //name[0] = "X";
  //strcpy (name[1], "nothing");
  double numberBlocks = 0.0;

  char buf[1024];
  int remain_blocks =0;
  char *tempPath = (char*)malloc (100*sizeof(char));

  tempName = (char *)malloc(100*sizeof(char));

  name[0] = (char *)malloc(100*sizeof(char));
	printf("%d, pathname = %s\n", argc, argv[2]);
	tempPath = strtok(argv[2], "/");
	strcpy(name[0], tempPath);
	printf("name[0] = %s\n",name[0]);

  while(tempPath){
	  tempPath = strtok(0,"/");
	  if(tempPath != NULL){
		  name[j] = (char *)malloc(100*sizeof(char));
		  strcpy(name[j], tempPath);
		  printf("name[%d] = %s\n",j,name[j]);
		  j++;
	  }
  }

  // open up the disk file
  //if (argc != 2) {
  //  printf("usage:  ext2reader diskfile_name\n");
  //  return -1;
  //}

  //int fd = open(argv[1], O_RDONLY);

  int fd = open("diskimage", O_RDONLY);
  if (fd == -1) {
    printf("couldn't open file \"%s\"\n", argv[1]);
    return -1;
  }

  // read the superblock off the disk and into memory.  you get
  // to implement this function in file ext2_access.c.
  struct os_superblock_t *superblock = read_superblock(fd);
  //check_superblock(superblock);  // our test code

  printf ("************ super block info: ************\n");
  printf ("inode_count: %d\n", superblock->s_inodes_count);
  printf ("block_count: %d\n", superblock->s_blocks_count);
  printf ("r_blocks_count: %d\n", superblock->s_r_blocks_count);
  printf ("free_blocks_count: %d\n", superblock->s_free_blocks_count);
  printf ("free_inodes_count: %d\n", superblock->s_free_inodes_count);
  printf ("log_block_count: %d\n", superblock->s_log_block_size);
  printf ("first_data_block: %d\n", superblock->s_first_data_block);
  printf ("magic number: %x\n", superblock->s_magic);
  printf ("rev_level: %d\n", superblock->s_rev_level);
  printf ("inode_size: %d\n", superblock->s_inode_size);
  printf ("block_gourp_nr: %d\n", superblock->s_block_group_nr);
  temp = superblock->s_log_block_size;
  temp = (temp + 1) * 1024;
  printf ("log_block_size: %d\n", temp); // check
  printf ("inode_per_group: %d\n", superblock->s_inodes_per_group);

  struct os_blockgroup_descriptor_t *bgdt1 = read_bgdt1(fd);

  printf ("************ Group 0 info: ************\n");
  printf ("Blocks bitmap block: %d\n", bgdt1->bg_block_bitmap);
  printf ("Inodes bitmap block: %d\n", bgdt1->bg_inode_bitmap);
  printf ("Inodes table block: %d\n", bgdt1->bg_inode_table);
  printf ("Free blocks count: %d\n", bgdt1->bg_free_blocks_count);
  printf ("Free inodes count: %d\n", bgdt1->bg_free_inodes_count);
  printf ("Directory count: %d\n", bgdt1->bg_used_dirs_count);
  printf ("inodes_start: %d\n", bgdt1->bg_inode_table);


  InodesBeginBlock = bgdt1->bg_inode_table;

  struct os_inode_t *dataBlock = read_dataBlock(fd, InodesBeginBlock);	//inode bitmap

  printf("************ root inode info: ************\n ");
  printf("File mode: %x\n", dataBlock->i_mode);
  temp = dataBlock->i_size;
  temp = (temp + 1) * 1024;
  printf("Size in bytes: %d\n", temp); // check
  printf("Blocks count: %x\n", dataBlock->i_blocks);

  offset_num2 = bgdt1->bg_inode_table + (superblock->s_inodes_count / 8);
  printf("block[0] = %d\n",offset_num2);

  printf("************ root dir entries: ************\n");
  printf("block = %d\n",offset_num2);
  printf ("i_number      rec_le       name_len     name\n");

  while (offset_num1 < 1024)
  {
  	  struct os_direntry_t *dirblock = read_dirBlock(fd, offset_num1, offset_num2);
  	  strncpy (tempName, dirblock->file_name, dirblock->name_len);
  	  tempName[dirblock->name_len] = '\0';
  	  printf ("%5d%13d%14d\t%s\n", dirblock->inode, dirblock->rec_len, dirblock->name_len, tempName);
  	  offset_num1 = offset_num1 + dirblock->rec_len;
  	  if (strcmp(name[0], tempName) == 0){
  		  temp = dirblock->inode;
  	  }
  }

  if (temp == 0)
  {
	  printf ("Unable to find %s", name[0]);
	  return 0;
  }

  printf("Found %s: ino = %d\n", name[0], temp);
  printf("===============================================\n");

  if (strcmp(name[1], "") != 0)
  {
	  temp = (offset_num2 - 1) + ((temp - 1) % 8);
	  temp = search (fd, temp, name[1]);

	  if (temp == 0)
	  {
		  printf ("Unable to find %s", name[1]);
		  return 0;
	  }
	  offset_num1 = ((temp - 1) / 8) + InodesBeginBlock;
	  offset_num2 = (temp - 1) % 8;
	  dataBlock = read_dataBlock2(fd, offset_num1, offset_num2);
  }

  offset_num1 = ((temp - 1) / 8) + InodesBeginBlock;
  offset_num2 = (temp - 1) % 8;
  dataBlock = read_dataBlock2(fd, offset_num1, offset_num2);

  //numberBlocks = ((double)dataBlock->i_size / 1024.0);
  //numberBlocks = ceil(numberBlocks);
  numberBlocks = 432;
  printf ("size: %d   blocks: %.0lf\n", dataBlock->i_size, numberBlocks);

  printf ("************ DISK BlOCKS ************\n");
  while (dataBlock->i_block[i] != 0){
	  printf("block[%d]: %d\n", i, dataBlock->i_block[i]);
	  i++;
  }

  printf ("============ DIRECT BLOCKS ============\n");
  i = 0;
  while (i < 12){
	  printf("  %d", dataBlock->i_block[i]);
	  if (dataBlock->i_block[i] == 0)
		  break;
	  i++;
	  if ((i % 10) == 0)
	  {
		  printf("\n");
	  }
  }
  //need to calculate numberBlocks

  if (dataBlock->i_block[12] != 0){
	  remain_blocks = numberBlocks -i; //NEED TO ADD BLOCK
	  printf ("\nBlock remains: %d\n", remain_blocks);
	  printf ("============ INDIRECT BLOCKS ============\n");
	  temp = 0;
	  if (dataBlock->i_block[13] != 0)
	  {
		  temp1 = dataBlock->i_block[13] -1;
	  }
	  else
	  {
		  temp1 = remain_blocks;
	  }

	  for (i = 1; temp < temp1; i++)
	  {
		  temp = dataBlock->i_block[12]  + i;
		  printf ("%d \t", temp);
		  if ((i % 10) == 0)
		  {
			  printf("\n");
		  }
	  }
	  remain_blocks = remain_blocks - i;
	  printf ("\nBlock remains: %d\n", remain_blocks + 1);
  }

  if (dataBlock->i_block[13] != 0)
  {
	  temp = 0;
	  printf ("\n============ DOUBLE INDIRECT BLOCKS ============\n");
	  for (i = 1; i <= remain_blocks; i++)
	  {
		  temp = dataBlock->i_block[13]  + i + 1;
		  printf ("%d \t", temp);
		  if ((i % 10) == 0)
		  {
			  printf("\n");
		  }
	  }
	  printf ("\nBlock remains: %d\n", remain_blocks - i +1);
  }
  close(fd);
  return 0;
}
