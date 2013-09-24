
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[64];
	char type;
	struct node *childPtr;
	struct node *siblingPtr;
	struct node *parentPtr;
}NODE;

//Global Variables:
	NODE *root=0, *cwd=0;
	char command[16], pathname[64];
	char dirname[64], basename[64];
	char line[128];

void initialize();
void pathBreak();
NODE *makeNode();
NODE * freeNode(NODE *node);
char *strReverse(char *str);
NODE* checkDir(NODE **node);

int mkdir(char nodeType);
int rmdir();
NODE *cd();
int ls();
void pwd();
int save (NODE *temp);
void reload(char *filename);
void quit();
///char* save(NODE *node, char *str);


int main(void)
{
	NODE *temp;
	char *buffer, *str;

	str = (char *)malloc(100*sizeof(char));
	str[0] = '\0';

	initialize();

	do{
		printf("Input a command: ");
		fflush(stdin);
		gets(line);


		//printf("-->%s", line);
		buffer = strtok (line," /");
		strcpy(command, buffer);
		//printf ("Command = %s\n",command);

		buffer= strtok (NULL, " ");

		if(buffer == '\0')
			strcpy(pathname, "");
		else
			strcpy(pathname, buffer);

		//printf ("Pathname: %s\n",pathname);


		if(strcmp(command, "mkdir") == 0)
			mkdir('D');
		else if (strcmp(command, "rmdir") == 0)
			rmdir();
		else if (strcmp(command, "cd") == 0)
			cd();
		else if (strcmp(command, "ls") == 0)
			ls();
		else if (strcmp(command, "pwd") == 0)
			pwd();
		else if (strcmp(command, "creat") == 0)
			mkdir('F');
		else if (strcmp(command, "rm") == 0)
			rmdir("F");
		else if (strcmp(command, "save") == 0)
		{
			temp = root;
			save(temp);
		}
		else if (strcmp(command, "reload") == 0)
			reload("inp.txt");
		else if (strcmp(command, "quit") == 0)
			quit();
		else
			printf("Invalid command\n");

	}while(strcmp(line, "quit") != 0);

	//trial input
	/*strcpy(pathname, "/1");		mkdir('D');
	strcpy(pathname, "/2");		mkdir('D');
	strcpy(pathname, "/3");		mkdir('D');
	strcpy(pathname, "/4");		mkdir('D');
	strcpy(pathname, "/1/5");	mkdir('D');
	strcpy(pathname, "/1/6");	mkdir('D');
	strcpy(pathname, "/1/7");	mkdir('D');
	strcpy(pathname, "/1/5/10");	mkdir('D');
	strcpy(pathname, "/1/5/11");	mkdir('D');
	strcpy(pathname, "/1/7/12");	mkdir('D');
	strcpy(pathname, "/3/8");		mkdir('D');
	strcpy(pathname, "/3/9");		mkdir('D');
	strcpy(pathname, "/3/9/13");	mkdir('D');
	strcpy(pathname, "/3/9/14");	mkdir('D');
	strcpy(pathname, "/3/9/14/16");	mkdir('D');
	strcpy(pathname, "/c");			mkdir('F');
	strcpy(pathname, "/1/a");		mkdir('F');
	strcpy(pathname, "/1/17");		mkdir('D');
	strcpy(pathname, "/1/5/10/b");	mkdir('F');*/



	/*strcpy(pathname, "/2");		rmdir();
	strcpy(pathname, "/3/8");		rmdir();
	strcpy(pathname, "/1/7/12");	rmdir();
	strcpy(pathname, "/c");		rmdir();
	strcpy(pathname, "/1/a");		rmdir();
	strcpy(pathname, "/1/5/10/b");	rmdir();

	strcpy(pathname, "/3/9/14/16");	ls();
	strcpy(pathname, "..");			ls();
	strcpy(pathname, "/3/8");		ls();
	strcpy(pathname, "..");			ls();
	strcpy(pathname, "");			ls();
	strcpy(pathname, "..");			ls();
	strcpy(pathname, "/1/5/10");	ls();
	strcpy(pathname, "..");			ls();
	strcpy(pathname, "/1/a");		ls();
	strcpy(pathname, "..");			ls();
	strcpy(pathname, "/1");			ls();
	strcpy(pathname, "..");			ls();*/

	//reload("inp.txt");

	//strcpy(pathname, "/3/9/14/16");	cd();
	//strcpy(pathname, "\b");	cd();

	//temp = makeNode();
	//temp = root;


	//str = save(temp,str);
	//save(temp);

	//puts(str);
	//pwd();

	return 0;
}
/*void  save(NODE *temp){
	NODE *curNode = root;

	if(temp == root)
	{
		printf("/\n");
	}
	else
	{
		//temp = temp->parentPtr;

		if(temp->parentPtr == root)
		{
			printf("/%s\n", temp->name);
		}
		else
		{
			while(strcmp(curNode->name, temp->name) != 0)
			{
				printf("%s/", curNode->name);
				curNode = curNode->childPtr;
			}
			//printf("\n");
		}
	}

	if(temp->childPtr != NULL)
		save(temp->childPtr);
	else if(temp->siblingPtr != NULL)
		save(temp->siblingPtr);

}*/

void quit()
{
	NODE *temp = root;
	save(temp);
}
void pwd(){
	NODE *temp = cwd;
	char *str;

	str = (char *)malloc(100*sizeof(char));
	str[0] = '\0';

	printf("PWD of node %s = ", temp->name);
	while(strcmp(temp->name, "/") != 0)
	{
		strcat(str, "/");
		strcpy(str, str);
		strcat(str, temp->name);
		strcpy(str, str);
		temp = temp->parentPtr;
	}

	str = strReverse(str);
}

char *strReverse(char *str){
	int lengthStr = 0, i = 0, lengthDest;
	char *name, *destStr;

	destStr = (char *)malloc(100*sizeof(char));
	destStr[0] = '\0';

	lengthStr = strlen(str);

	destStr[lengthStr + 1] = '\n';
	destStr[lengthStr] = '/';
	lengthStr = lengthStr - 1;
	i = lengthStr;
	name = strtok(str, "/");
	while (name != NULL)
	{
		lengthDest = strlen(name) - 1;
		for(; lengthDest >= 0; lengthDest--)
		{
			destStr[i] = name[lengthDest];
			  i--;
		}
		destStr[i] = '/';
		i--;
		name = strtok(NULL, "/");
	}
	puts (destStr);

	return destStr;
}

int save(NODE *node){

	if(strcmp(node->name, "/") != 0)
	{
		printf("/%s\n", node->name);
	}

	if(node == root)
	{
		printf("%s\n", node->name);
		//strcat(str, "/");
		save(node->childPtr);
	}
	else if(node->childPtr != NULL)
	{
		printf("%s", node->name);
		//strcat(str, "/");
		//strcat(str, node->name);

		node = node->childPtr;
		/*strcat(str, "/");
		strcat(str, node->name);*/
		save(node);
	}
	else if(node->siblingPtr != NULL)
	{
		//strcat(str, "/");
		//strcat(str, node->name);

		printf("%s", node->parentPtr->name);
		node = node->siblingPtr;
		save(node);
	}
	else if(node->childPtr == NULL)			//if no child
	{
		while(node->parentPtr == node->parentPtr->childPtr->parentPtr)		//check if still under parent
		{
			if(cwd == root)
			{
				if(strcmp(node->parentPtr->name, "/") == 0)
					return 0;
			}
			else if(strcmp(node->parentPtr->name, "/") == 0)		//if in the root
				return 0;

			if(node->parentPtr->siblingPtr != NULL)			//if there is a sibling
			{
				node = node->parentPtr->siblingPtr;

				//strcat(str, "/");
				//strcat(str, node->name);

				printf("%s", node->parentPtr->name);
				break;
			}
			else											//is no sibling
			{
				node = node->parentPtr;
			}
		}
		save(node);
	}
	else if(node->siblingPtr == NULL)
	{
		while(node->parentPtr->siblingPtr == NULL)
		{
			node = node->parentPtr;
			if(strcmp(node->parentPtr->name, "/") == 0)
				break;
		}
		node = node->parentPtr->siblingPtr;
		save(node);
	}


	return 0;
}
void reload(char *filename){
	FILE* inPtr = fopen(filename,"r");
	char line[64];
	char *buffer;

	if(inPtr != 0)
	{
		while(!feof(inPtr))
		{
			if(fgets(line,64,inPtr) > 0)
			{
				printf("-->%s", line);
				buffer = strtok (line," ");
				strcpy(command, buffer);
				printf ("Command = %s\n",command);

				buffer= strtok (0, "\r");

				if(buffer == '\0')
					strcpy(pathname, "");
				else
					strcpy(pathname, buffer);

				printf ("Pathname: %s\n",pathname);


				if(strcmp(command, "mkdir") == 0)
					mkdir('D');
				else if (strcmp(command, "rmdir") == 0)
					rmdir();
				else if (strcmp(command, "cd") == 0)
					cd();
				else if (strcmp(command, "ls") == 0)
					ls();
				else if (strcmp(command, "creat") == 0)
					mkdir('F');
				else if (strcmp(command, "rm") == 0)
					rmdir();
			}
		}
	}

	fclose(inPtr);
}
int ls(){
	NODE *temp = makeNode();
	//pathBreak();
	if(strcmp(pathname, "") ==0)
	{
		temp = root;
		printf("Cwd = %s\n", temp->name);
		//return 0;
	}
	else
		temp = cd();

	temp = temp->childPtr;
	printf("%c\t%s\n", temp->type, temp->name);
	while(temp->siblingPtr != NULL)
	{
		temp = temp->siblingPtr;
		printf("%c\t%s\n", temp->type, temp->name);
	}
	puts("\n");
	return 1;
}
NODE *cd(){
	NODE *temp = makeNode();
	pathBreak();

	if(strcmp(pathname, "") == 0)		//no pathname
	{
		printf("Cwd = root\n\n");
		return root;
	}
	else								//temp is cwd
		temp = cwd;

	if(strcmp(pathname, "/") != 0)	//if not root then search dir
	{
		temp = checkDir(root);

		if(strcmp(pathname, "..") != 0)
			printf("Return node %s\n", temp->name);

		if(temp == NULL)			//not found dir
			return temp;
	}

	if(strcmp(pathname, "..") == 0)
	{
		temp = temp->parentPtr->childPtr;
		if(strcmp(temp->name, cwd->name) == 0)			//mean only child has no sibling
		{
			cwd = temp->parentPtr;
			printf("Return node %s\n\n", cwd->name);
			return cwd;
		}

		while(strcmp(temp->siblingPtr->name, cwd->name) != 0)
			temp = temp->siblingPtr;
		cwd = temp;
		printf("---->return %s\n\n", cwd->name);
		return cwd;
	}

	if(temp->childPtr != NULL)		//then go to sibling
	{
		temp = temp->childPtr;
		while(temp != NULL)
		{
			cwd = temp;
			if(strcmp(cwd->name, basename) == 0)
				break;
			temp = temp->siblingPtr;
		}
	}
	else							//then go to child
	{
		cwd = temp->childPtr;
	}

	printf("Cwd = %s\n", cwd->name);
	puts("\n");
	return cwd;
}
NODE* checkDir(NODE **node){
	int i = 0;
	NODE *curNode;
	char *name;

	curNode = node;

	if(strcmp(pathname, "..") == 0)
		return cwd;

	if((strcmp(dirname, "/") == 0) || (strcmp(dirname, cwd->name) == 0))
		return curNode;

	curNode = curNode ->childPtr;

	name = strtok(dirname, "/");

	while (name != NULL)
	{
		while (curNode != NULL)
		{
			if(strcmp(curNode->name, name) == 0)
				break;

			curNode = curNode->siblingPtr;
		}
		if (curNode == NULL)
		{
			printf ("No dir found\n");
			return curNode;
		}
		else
		{
			name = strtok(NULL, "/");
			if (name == NULL)
				return curNode;

			curNode = curNode->childPtr;
		}

	}
}


NODE *makeNode()
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	strcpy(temp->name,"");
	temp->type = '\0';
	temp->parentPtr=temp->siblingPtr=temp->childPtr=NULL;
	return temp;
}

int mkdir(char nodeType){
	NODE *newNode = makeNode(), *curNode = makeNode(), *temp = makeNode();

	pathBreak();

	if(strcmp(dirname, "/") == 0)		//temp is root
		temp = root;
	else								//temp is cwd
		temp = cwd;

	if(strcmp(basename, "") == 0)
	{
		strcpy(basename, dirname);
		strcpy(dirname, temp->name);
	}

	if(strcmp(dirname, "/") != 0)	//if not root then search dir
	{
		temp = checkDir(temp);
		printf("Return node %s\n", temp->name);

		if(temp == NULL)			//not found dir
			return 0;
		else if(temp->type != 'D')
		{
			printf("%s is not a dir. Can not insert\n\n", temp->name);
			return 0;
		}
	}

	strcpy(newNode->name,basename);
	if(nodeType == 'D')
		newNode->type = 'D';
	else
		newNode->type = 'F';

	if(temp->childPtr != NULL)		//then go to sibling
	{
		temp = temp->childPtr;
		while(temp != NULL)
		{
			curNode = temp;
			temp = temp->siblingPtr;

			if(strcmp(curNode->name, newNode->name) == 0)
			{
				printf("Dir already exits\n");
				return 0;
			}
		}

		//add to sibling
		curNode->siblingPtr = newNode;
		newNode->parentPtr = curNode->parentPtr;
		printf("Insert sibling %s NEXT %s\n", newNode->name, curNode->name);

	}
	else							//then go to child
	{
		if(temp->type != 'F')		//node is not a file
		{
			temp->childPtr = newNode;
			newNode->parentPtr = temp;
			printf("Insert child %s IN %s\n", newNode->name, temp->name);
		}
		else
		{
			printf("Can not add dir In a file\n");
			return 0;
		}
	}
	puts("\n");

	return 1;
}

int rmdir(){
	NODE *newNode, *temp = NULL, *curNode = NULL;

	pathBreak();

	if (strcmp(dirname, "/") == 0)
		temp = root;
	else
		temp = cwd;

	if (strcmp(dirname, "/")  != 0)
	{
		temp = checkDir (temp);
		if (temp == NULL)
			return 0;
	}
	else if(temp->childPtr == NULL)
	{
		printf ("At root, can not delete\n\n");
		return 0;
	}

	curNode = temp;
	temp = temp->childPtr;

	if(temp == NULL)
	{
		printf ("Dir/file not found\n\n");
		return 0;
	}

	if(strcmp(temp->name, basename) == 0)
	{
		/*if (temp->type == 'D'){
			printf ("/%s is not a file type\n", temp->name);
			return 0;
		}
		else*/ if(temp->siblingPtr != NULL || temp->childPtr != NULL)
		{
			printf("Node %s is not empty. Can not delete\n\n", temp->name);
			return 0;
		}

		curNode->childPtr = temp->siblingPtr;
		printf("Delete node %s\n\n" ,temp->name);
		free(temp);
		return 1;
	}

	while (temp != NULL)
	{

		if(strcmp(temp->name, basename) == 0)		//then delete sibling
		{
			/*if (temp->type == 'D')
			{
				printf ("/%s is not a file type\n", temp->name);
				return 0;
			}
			else*/ if(temp->siblingPtr != NULL || temp->childPtr != NULL)
			{
				printf("Node %s is not empty. Can not delete\n\n", temp->name);
				return 0;
			}

			newNode->siblingPtr = temp->siblingPtr;
			printf("Delete node %s\n\n" ,temp->name);
			free(temp);
			return 1;
		}
		else
		{
			newNode = temp;
			temp = temp->siblingPtr;
		}
	}

	printf ("File Not Exist\n\n");
	return 0;
}

void initialize(){
	root = malloc(sizeof(NODE));
	cwd = malloc(sizeof(NODE));

	strcpy(root->name, "/");
	root->type = 'D';
	root->parentPtr = NULL;
	root->siblingPtr = NULL;
	root->childPtr = NULL;

	cwd = root;
}

NODE* freeNode(NODE *node){
	strcpy(node->name,NULL);
	node->type = '\0';
	node->parentPtr = node->siblingPtr = node->childPtr = NULL;
	return node;
}

void pathBreak(){
	int dir = 0, path = 0, base = 0;

	while(pathname[dir] != '\0')
	{
		dirname[dir] = pathname[dir];
		if (pathname[dir] == '/')
			path = dir;

		dir++;
	}

	dirname[path+1] = '\0';

	while (pathname[path] != '\0')
	{
		basename[base] = pathname[path+1];
		base++;
		path++;
	}

	printf ("Dirname: %s\n",dirname);
	printf ("Basename: %s\n",basename);
}
