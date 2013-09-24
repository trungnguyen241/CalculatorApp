#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct stat myST;
    char buf[1024];
    ssize_t len;

   if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   if (stat(argv[1], &myST) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    
   if(lstat(argv[1], &myST) == 0)		//sucess
	   if  ((myST.st_mode & 0120000) == 0120000) //==> symbolic link
	   	   printf("File type is LNK\n");   
   else if ((myST.st_mode & 0100000) == 0100000) 		//==> REG
	   printf("File type is regular FILE\n");
   else if ( (myST.st_mode & 0040000) == 0040000) //==> DIR
	   printf("File type is DIR\n");
   else
	   printf("Unknown\n");

   if ( (myST.st_mode & (1 << 8)) ) 			//==> Owner can r
	   printf("Owner can R\n");
   else if ( (myST.st_mode & (1 << 7)) ) 		//==> Owner can w
	   printf("Owner can W\n");
   else if ( (myST.st_mode & (1 << 6)) ) 		//==> Owner can x
	   printf("Owner can X\n");
   else if ( (myST.st_mode & (1 << 5)) ) 		//==> Group can r
   	   printf("Group can R\n");
   else if ( (myST.st_mode & (1 << 4)) ) 		//==> Group can w
	   printf("Group can W\n");
   else if ( (myST.st_mode & (1 << 3)) ) 		//==> Group can x
	   printf("Group can X\n");
   else if ( (myST.st_mode & (1 << 2)) ) 		//==> Other can r
	   printf("Other can R\n");
   else if ( (myST.st_mode & (1 << 1)) ) 		//==> Other can w
	   printf("Other can W\n");
   else if ( (myST.st_mode & (1 << 0)) ) 		//==> Other can x
	   printf("Other can X\n");

   printf("UID : \t %ld\n", (long) myST.st_uid);
   printf("File size:\t %lld bytes\n",(long long) myST.st_size);

   printf("Last status change:\t %s", ctime(&myST.st_ctime));
   printf("Last file access:\t %s", ctime(&myST.st_atime));
   printf("Last file modification:t\ %s", ctime(&myST.st_mtime));


   DIR *dp = opendir(argv[1]);      //opens a DIR (for R/W)
   struct dirent * ep;

   if ( (myST.st_mode & 0040000) == 0040000)	//DIR
   {
		if(dp)
		{
			printf("output:\n");
			while(ep = readdir(dp))
			{
			   printf("%s\n", ep->d_name);
			}
			closedir(dp);
		}
		else
			printf("Can not open directory '%s'\n", ep);
   }
   else if  ((myST.st_mode & 0120000) == 0120000) //==> symbolic link
   {
   		len = readlink(argv[1], buf, sizeof(buf) - 1);
   		
	   if( len == -1)
		   printf("readlink error\n");
	   else
	   {
	   		buf[len] = '\0';
		   printf("readlink() returned '%s' for '%s'\n", buf, argv[1]);
		   
		   while(ep = readdir(dp))
		   		printf("%s\n", ep->d_name);
	   }
	   unlink(argv[1]);
   }

   exit(EXIT_SUCCESS);
}
