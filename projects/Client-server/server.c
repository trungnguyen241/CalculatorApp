// This is the echo SERVER server.c
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fcntl.h>

#include <sys/socket.h>
#include <netdb.h>

#define  MAX 1024

// Define variables:
struct sockaddr_in  server_addr, client_addr, name_addr;
struct hostent *hp;

int  sock, newsock;                  // socket descriptors
int  serverPort;                     // server port number
int  r, length, n;                   // help variables

// Server initialization code:

int server_init(char *name)
{
   printf("==================== server init ======================\n");
   // get DOT name and IP address of this host

   printf("1 : get and show server host info\n");
   hp = gethostbyname(name);
   if (hp == 0){
      printf("unknown host\n");
      exit(1);
   }
   printf("    hostname=%s  IP=%s\n",
               hp->h_name,  inet_ntoa(*(long *)hp->h_addr));

   //  create a TCP socket by socket() syscall
   printf("2 : create a socket\n");
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock < 0){
      printf("socket call failed\n");
      exit(2);
   }

   printf("3 : fill server_addr with host IP and PORT# info\n");
   // initialize the server_addr structure
   server_addr.sin_family = AF_INET;                  // for TCP/IP
   server_addr.sin_addr.s_addr = htonl(INADDR_ANY);   // THIS HOST IP address
   server_addr.sin_port = 0;   // let kernel assign port

   printf("4 : bind socket to host info\n");
   // bind syscall: bind the socket to server_addr info
   r = bind(sock,(struct sockaddr *)&server_addr, sizeof(server_addr));
   if (r < 0){
       printf("bind failed\n");
       exit(3);
   }

   printf("5 : find out Kernel assigned PORT# and show it\n");
   // find out socket port number (assigned by kernel)
   length = sizeof(name_addr);
   r = getsockname(sock, (struct sockaddr *)&name_addr, &length);
   if (r < 0){
      printf("get socketname error\n");
      exit(4);
   }

   // show port number
   serverPort = ntohs(name_addr.sin_port);   // convert to host ushort
   printf("    Port=%d\n", serverPort);

   // listen at port with a max. queue of 5 (waiting clients)
   printf("5 : server is listening ....\n");
   listen(sock, 5);
   printf("===================== init done =======================\n");
}

/**********************************MAIN********************************/
main(int argc, char *argv[])
{
	/******************Variable declaration*********************/
   char *hostname;
   char line[MAX];

   //char buf[MAX] ,inputLine[50],outputLine[50];
   //char buf2[MAX];
   char inputLine[50],outputLine[50];
   	int index,indexFile,indexArgv,inputFile,outputFile,bufLength;
   	pid_t pid;
   	int option;

   	int pipeServer[2];

   	const char *PathString = getenv ("PATH");;
   	int indexTrial = 0, cmd_index = 0;
   	char *tempString;

   	typedef char * string;
   	string cmd[30];
   	char tempCmd[30];
   	char *env[] = { "HOME=/usr/home", "LOGNAME=NMT", (char *)0 };

   	char *subString, pathname[64], command[16];
   	subString = (char *)malloc(100*sizeof(char));
   	char *tempStr1 = (char *)malloc(100*sizeof(char));
   	const char* HomeEnv = getenv("HOME");
   	
int fd;
FILE * textfile;
char contents[1000];   	
char *pwd = (char *)malloc(100*sizeof(char));
char buf3 [MAX] = {0};

   			/***************************************/
	
strcpy(pwd, HomeEnv);
printf("pwd = %s\n", pwd);	

   if (argc < 2)
      hostname = "localhost";
   else
      hostname = argv[1];

   server_init(hostname);

   // Try to accept a client request
   while(1){
	   
	 if (pipe (pipeServer) < 0)
	 {
		perror("can't make pipe");
		exit(1);
	 } 
	   
     printf("server: accepting new connection ....\n");

     // Try to accept a client connection as descriptor newsock
     length = sizeof(client_addr);
     newsock = accept(sock, (struct sockaddr *)&client_addr, &length);
     if (newsock < 0){
        printf("server: accept error\n");
        exit(1);
     }
     printf("server: accepted a client connection from\n");
     printf("-----------------------------------------------\n");
     printf("        IP=%s  port=%d\n", inet_ntoa(client_addr.sin_addr.s_addr),
                                        ntohs(client_addr.sin_port));
     printf("-----------------------------------------------\n");


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
     	
     
     	

     while(1){
		 
	   char buf [MAX] = {0};
	   char buf2 [MAX] = {0};
       n = read(newsock, buf, MAX);
       
       if (n==0){
           printf("server: client died, server loops\n");
           close(newsock);
           break;
      }

      // show the line string
      printf("server: read  n=%d bytes; buf=[%s]\n", n, buf);//line);
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

			if(strcmp(pathname, "") == 0)
			{
				if(chdir(HomeEnv) < 0)
				{
					printf("Error, can not change directory\n");
					sprintf(buf2, "Error, can not change directory\n");
					write(newsock, buf2, MAX);
				}
				else
				{
					setenv("PWD", HomeEnv, 1);
					printf("Directory change to %s\n", HomeEnv);
					sprintf(buf2, "Directory change to %s\n", HomeEnv);
					write(newsock, buf2, MAX);
					
					strcpy(pwd, HomeEnv);
				}
			}
			
			else
			{
				if(chdir(pathname) == 0)
				{
					setenv("PWD", HomeEnv, 1);
					printf("Directory change to %s\n", pathname);
					sprintf(buf2, "Directory change to %s\n", pathname);
					write(newsock, buf2, MAX);
					
					strcpy(pwd, pathname);
				}
				else
					printf("Error, can not change directory\n");
			}

			strcpy(pathname, "");
			
			printf("pwd = %s\n\n", pwd);
			
			strcpy(buf3, pwd);
			//n = write(newsock, pwd, MAX);
			printf("server: wrote n=%d bytes; ECHO=[%s]\n\n", n, pwd);
		}
		else
		{
		  pid = fork();
		  
		  if( pid < 0 )
		  {
			 printf("Fork fail!!!\n");
			 exit (1);
		  }

		  //fork sucess, now child process
		  else if( pid == 0)
		  {
			 
			 if (strcmp(buf, "ls") == 0 || buf[3] == '-' || strcmp(buf, "cd") == 0 || strcmp(buf, "pwd") == 0){
			 	 close (pipeServer[0]); //WORKING
			 	 dup2(pipeServer[1], STDOUT_FILENO);
			 	 dup2(pipeServer[1], STDERR_FILENO);
			 	 close(pipeServer[1]);
			 }
				
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
				else if(buf[index] == '>' )
				{
					if(buf[index + 1] == '>')
					{
					   index += 2;
					 
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
			 indexTrial = 0;


		
			 while(indexTrial != cmd_index)
			 {

				 strcpy(tempCmd, "");
				 strcpy(tempCmd, cmd[indexTrial]);
				 strcat(tempCmd,"/");
				 strcat(tempCmd,argv[0]);
				 printf("command is: %s", tempCmd);
				 
				 execve(tempCmd, argv, NULL);
				 indexTrial++;
			 }

			 printf("Execute error !!!\n");

			 exit(127);
		  }

		  //this is parent process
		  else
		  {
			 
			 if (strcmp(buf, "ls") == 0 || buf[3] == '-' || strcmp(buf, "cd") == 0 || strcmp(buf, "pwd") == 0){
				 pid = waitpid(pid, &option, 0); 
				 read(pipeServer[0], buf2, MAX);
			 }
			 else {
				 sprintf(buf2, "Sucess execute %s\n", buf);
			 }
			 
			 printf("\nbuf2 is: %s", buf2);
			 write(newsock, buf2, MAX);
			 	
			 //if(strcmp(buf, "get") == 0)
			// {
			 	printf("\nPWD = %s\n", pwd);
				textfile = fopen("trial.txt", "r");
	 			printf("open file trial\n");
				while(fgets(contents,1000,textfile) != NULL)
				{
					printf("%s",contents);	
					write(newsock, buf2, MAX);
				}
							

				//n = write(newsock, pwd, MAX);
				//printf("server: wrote n=%d bytes; ECHO=[%s]\n\n", n, pwd);
			// }
			 

			 
			 if( pid < 0 )
			 {
				printf("Error!!!\n");
				exit(1);
			 }
			 fflush(stdout);
			 fflush(stdin);
		  }
		}
      printf("\nServer: ready for next request\n");
    }
 }
}
