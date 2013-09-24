
//************ CLIENT CODE **********************
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fcntl.h>

#include <sys/socket.h>
#include <netdb.h>

#define MAX 1024

// Define variables
struct hostent *hp;
struct sockaddr_in  server_addr;

int sock, r;
int SERVER_IP, SERVER_PORT;

// clinet initialization code

int client_init(char *argv[])
{
  printf("======= client init ==========\n");

  printf("1 : get server info\n");
  hp = gethostbyname(argv[1]);
  if (hp==0){
     printf("unknown host %s\n", argv[1]);
     exit(1);
  }

  SERVER_IP   = *(long *)hp->h_addr;
  SERVER_PORT = atoi(argv[2]);

  printf("2 : create a TCP socket\n");
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock<0){
     printf("socket call failed\n");
     exit(2);
  }

  printf("3 : fill server_addr with server's IP and PORT#\n");
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = SERVER_IP;
  server_addr.sin_port = htons(SERVER_PORT);

  // Connect to server
  printf("4 : connecting to server ....\n");
  r = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (r < 0){
     printf("connect failed\n");
     exit(1);
  }

  printf("5 : connected OK to \007\n");
  printf("---------------------------------------------------------\n");
  printf("hostname=%s  IP=%s  PORT=%d\n",
          hp->h_name, inet_ntoa(SERVER_IP), SERVER_PORT);
  printf("---------------------------------------------------------\n");

  printf("========= init done ==========\n");
}

main(int argc, char *argv[ ])
{
	/**********************************/
	int n;
	char line[MAX];
  
	char buf[MAX],inputLine[50],outputLine[50];
	//char inputLine[50],outputLine[50];
	//char *buf = (char*) malloc (64);
   	int index,indexFile,indexArgv,inputFile,outputFile,bufLength;
   	pid_t pid;
   	int option;

   	const char *PathString = getenv ("PATH");;
   	int indexTrial = 0, cmd_index = 0;
   	char *tempString = (char*)malloc(64);
   	char tempStr[64];

   	typedef char * string;
   	string cmd[30];
   	char tempCmd[30];
   	char *env[] = { "HOME=/usr/home", "LOGNAME=NMT", (char *)0 };

   	char *subString, pathname[64], command[16];
   	subString = (char *)malloc(100*sizeof(char));
   	const char* HomeEnv = getenv("HOME");
   	
   	
FILE *inFile;
char content[1000];
	/**********************************/
	  if (argc < 3){
		 printf("Usage : client ServerName SeverPort\n");
		 exit(1);
	  }

	  client_init(argv);
	  
	  for(index = 0; index < 30; ++index)
     		cmd[index] = malloc(400);

     if (PathString == NULL)
     	return 0;
     tempString = strtok (PathString, ":");
     strcpy(cmd[cmd_index], tempString);
	 while(tempString)
     {
     	strcpy(cmd[cmd_index], tempString);
     	cmd_index++;
     	tempString = strtok(0, ":");
     }

	 printf("********  processing loop  *********\n");
	 while (1)
	 {
		printf("********************** menu *********************\n");
		printf("* get  put  ls   cd   pwd   mkdir   rmdir   rm  *\n");
		printf("* lcat     lls  lcd  lpwd  lmkdir  lrmdir  lrm  *\n");
		printf("*************************************************\n");
		printf("Input a command: ");
		
		char ans[MAX] = {0};
		bzero(line, MAX);                // zero out line[ ]
		fgets(line, MAX, stdin);         // get a line (end with \n) from stdin

		strcpy(tempStr, line);
		
		tempString = strtok(tempStr, " ");
		
		if (tempString[strlen(tempString) - 1] == '\n')
			tempString[strlen(tempString) - 1] = '\0';
		
		if ((strcmp(tempString, "lcat") == 0) || (strcmp(tempString, "lls") == 0) 
		||(strcmp(tempString, "lcd") == 0) || (strcmp(tempString, "lmkdir") == 0) 
		||(strcmp(tempString, "lrmdir") == 0) || (strcmp(tempString, "lpwd") == 0) 
		|| (strcmp(tempString, "lrm") == 0)){
			strcpy (tempString, line);
			tempString++;
			
			if (tempString[strlen(tempString) - 1] == '\n')
				tempString[strlen(tempString) - 1] = '\0';
			
			strcpy(buf, tempString);
			printf("ECHO = [%s]\n", buf);
			
			if(strcmp( buf , "exit" ) == 0)
			{
				printf("Exit now \n");
				break;
			}

			//if simple command cd
			if(buf[0] == 'c' && buf[1] == 'd')
			{
				if (buf[3] == '/')
					strcpy(pathname, "/");
				else
				{
					buf[2] = '/';
					strcpy(pathname, getenv("PWD"));
					strcat(pathname, "/");
				}

				subString = strtok (buf,"/");

				subString= strtok (NULL, " ");

				if(subString == '\0')
					strcpy(pathname, "");
				else
					strcat(pathname, subString);

				//printf ("Try to cd to pathname %s...\n",pathname);

				//no pathname, cd to home dir
				if(strcmp(pathname, "") == 0)
				{
					if(chdir(HomeEnv) < 0)
						printf("Error, can not change directory\n");
					else
					{
						setenv("PWD", HomeEnv, 1);
						printf("Directory change to %s\n", HomeEnv);
					}
				}
				//cd to pathname dir
				else
				{
					if(chdir(pathname) == 0)
					{
						setenv("PWD", HomeEnv, 1);
						printf("Directory change to %s\n", pathname);
					}
					else
						printf("Error, can not change directory\n");
				}

				strcpy(pathname, "");
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
				 
		printf("PWD = %s\n", pathname);
				 //try execute command in each Path dir
				 while(indexTrial != cmd_index)
				 {
					 strcpy(tempCmd, "");
					 strcpy(tempCmd, cmd[indexTrial]);
					 strcat(tempCmd,"/");
					 strcat(tempCmd,argv[0]);

					 execve( tempCmd, argv, NULL);
					 indexTrial++;
				 }

				 printf("Execute error !!!\n");

				 exit(127);
			  }

			  //this is parent process
			  else
			  {
				 pid = waitpid(pid, &option, 0);

				 if( pid < 0 )
				 {
					printf("Error!!!\n");
					exit(1);
				 }
				 fflush(stdout);
			  }
			}			
		}
		else{
			line[strlen(line)-1] = 0;        // kill \n at end
			if (line[0]==0)                  // exit if NULL line
			   exit(0);
	
			// Send ENTIRE line to server
			n = write(sock, line, MAX);
			printf("client: wrote n=%d bytes; command=(%s)\n", n, line);
			
			n = read(sock, ans, MAX);
			printf("client: read  n=%d bytes; echo=(%s)\n",n, ans);
			
			
			
/*			strcat(ans, "/trial.txt");*/
/*			printf("pathname = %s\n", ans);*/
/*			inFile = fopen(ans, "r"); */
/*			*/
/*			while ( fgets( content, 1000, inFile ) != NULL ) */
/*        		fputs( content, stdout );*/
/*			*/
/*			close(inFile);*/


			fflush(stdout);
			fflush(stdin);
		}
	  }
}

