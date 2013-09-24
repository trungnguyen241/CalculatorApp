#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char buf[1000],inputLine[50],outputLine[50];
	char *argv[50];
	int index,indexFile,indexArgv,inputFile,outputFile,bufLength;
	pid_t pid;
	int option;

    char *PathString = getenv ("PATH");;
	int indexTrial = 0, cmd_index = 0;
	char *tempString;

	typedef char * string;
	string cmd[30];
	char tempCmd[30];
	char *env[] = { "HOME=/usr/home", "LOGNAME=NMT", (char *)0 };

	char *subString, pathname[64], command[16];
	subString = (char *)malloc(100*sizeof(char));
	const char* HomeEnv = getenv("HOME");
	char *pwd = (char *)malloc(100*sizeof(char));
	strcpy(pwd, HomeEnv);
	printf("pwd = %s\n", pwd);


	for(index = 0; index < 30; ++index)
		cmd[index] = (string) malloc(400);

	if (PathString == NULL)
		return 0;

	tempString = strtok (PathString, ":");
	strcpy(cmd[cmd_index], tempString);
	printf("\nPATHNAME: %s\t", cmd[cmd_index]);

	while(tempString)
	{
		strcpy(cmd[cmd_index], tempString);
		printf("%s\t", cmd[cmd_index]);
		cmd_index++;
		tempString = strtok(0, ":");
	}

   printf("\n[TrungSH]$ ");
   fflush(stdout);


   while(  fgets(buf,1000,stdin) != NULL )
   {

		if( buf[ strlen(buf) - 1 ] == '\n' )
			buf[ strlen(buf) - 1 ] ='\0';

		if(strcmp( buf , "exit" ) == 0)
		{
			printf("Exit now \n");
			break;
		}

		//if simple command cd
		if(buf[0] == 'c' && buf[1] == 'd')
		{
		    printf("buf = %s\n", buf);

		    if (buf[3] == '/')
		    	strcpy(pathname, "/");
			else
			{
				buf[2] = '/';
				strcpy(pathname, getenv("PWD"));
				strcat(pathname, "/");
			}

		    subString = strtok (buf,"/");
		    printf ("Process simple command %s\n",subString);

			subString= strtok (NULL, " ");

			if(subString == '\0')
				strcpy(pathname, "");
			else
				//strcpy(pathname, subString);
				strcat(pathname, subString);

			printf ("Try to cd to pathname %s...\n",pathname);

			//no pathname, cd to home dir
			if(strcmp(pathname, "") == 0)
			{
				if(chdir(HomeEnv) < 0)
					printf("Error, can not change directory\n");
				else
				{
					setenv("PWD", HomeEnv, 1);
					printf("HomeEnv = %s\n", HomeEnv);

					strcpy(pwd, HomeEnv);
					printf("pwd = %s\n", pwd);
				}
			}
			//cd to pathname dir
			else
			{
				if(chdir(pathname) == 0)
				{
					setenv("PWD", HomeEnv, 1);
					printf("pathname = %s\n", pathname);

					strcpy(pwd, pathname);
					printf("pwd = %s\n", pwd);
				}
				else
					printf("Error, can not change directory\n");
			}

			strcpy(pathname, "");
			printf("\n[TrungSH]$ ");
		}
		//not a simple command
		else
		{
		  pid = fork();

		  //fork fail
		  if( pid < 0 )
		  {
			 printf("Fork fail!!!\n");
			 exit (1);
		  }

		  //fork sucess, now child process
		  else if( pid == 0)
		  {
			 printf("child sh %d process\n\n", getpid());

			 index = 0;
			 indexFile = 0;
			 indexArgv = 0;
			 bufLength=strlen(buf);

			 //parsing the command
			 while( index < bufLength )
			 {
				//case there is a  space, keep going
				if( ' ' == buf[index] )
				   index++;
				//case inp or outp redirection, then jump out
				if( '<' == buf[index] || '>' == buf[index] )
				   break;

				//case command has argument
				if( '-' == buf[index] || isalpha(buf[index]) )
				{
				   argv[indexArgv++] = &buf[index];
				   index++;

				   while( ' ' !=  buf[index]  && '<' != buf[index] &&
						   '>' != buf[index] && index < bufLength)
					  index++;

				   if( index == bufLength )
					  break;
				   else
				   {
					  index++;
					  buf[index - 1]='\0';
					  continue;
				   }
				}
			 }

			 argv[indexArgv]=NULL;

			 //redirection to input file
			 if(index < bufLength)
			 {
				if( '<' == buf[index] )
				{
				   index++;
				   indexFile = 0;
				   if( ' ' == buf[index] )
					  index++;

				   while( ' ' != buf[index] && index < bufLength )
					  inputLine[indexFile++] = buf[index++];

				   inputLine[indexFile]='\0';

				   if ( ( inputFile = open(inputLine,0) ) < 0 )
				   {
					  printf("Error when process input file\n");
					  exit( 1 );
				   }

				   close(0);
				   dup(inputFile);
				}
				//redirection to output file
				else if(buf[index] == '>' )
				{
					if(buf[index + 1] == '>')
					{
					   index += 2;
					   //indexFile = 0;
					   if( ' ' == buf[index] )
						  index++;

					   while( ' ' != buf[index] && index < bufLength )
						  outputLine[indexFile++] = buf[index++];

					   outputLine[indexFile]='\0';


					   if ( ( outputFile = open(outputLine,O_APPEND) ) < 0 )
					   {
						  printf("Error when process append output file\n");
						  exit( 1 );
					   }
					}
					else
					{
					   index++;
					   indexFile = 0;


					   if( ' ' == buf[index] )
						  index++;

					   while( ' ' != buf[index] && index < bufLength )
						  outputLine[indexFile++] = buf[index++];

					   outputLine[indexFile]='\0';


					   if ( ( outputFile = open(outputLine,1) ) < 0 )
					   {
						  printf("Error when process output file\n");
						  exit( 1 );
					   }
					}

				   close(1);
				   dup(outputFile);
				}
			 }

			 //Execute command
			 indexTrial = 0;
			 //try execute command in each Path dir
			 while(indexTrial != cmd_index)
			 {
				 strcpy(tempCmd, "");
				 strcpy(tempCmd, cmd[indexTrial]);
				 strcat(tempCmd,"/");
				 strcat(tempCmd,argv[0]);
				 printf("Trial = %d\ttempCmd: %s\n", indexTrial, tempCmd);

				 printf("HomeEnv = %s\n", HomeEnv);
				 printf("pathname = %s\n", pathname);
				 printf("pwd = %s\n", pwd);

				 execve( tempCmd, argv, NULL);
				 indexTrial++;
			 }

			 printf("Execute error !!!\n");

			 exit(127);
		  }

		  //this is parent process
		  else
		  {
			 printf("parent sh %d folk\n", getpid());
			 printf("Parent sh %d wait\n", getpid());

			 //wait for the pid
			 pid = waitpid(pid, &option, 0);

			 printf("child sh %d died\n\n", pid);

			 if( pid < 0 )
			 {
				printf("Error!!!\n");
				exit(1);
			 }

			 printf("[TrungSH]$ ");
			 fflush(stdout);
		  }
		}
   }
   return 0;
}

