/********************************************************************************************************
* Programmer: Trung Nguyen																				*
* Class: Cpt S 122, Spring 2012																			*	
* Programming Assignment 02: gital Music Manager & Doubly Linked Lists									*	
* Date: February 03, 2012																				*
* Description: This program consists of link lists of songs. Each song will contain these				*
*				fields: artist, album title, song title, genre, the lenght of song in minute			*
*				and second, the times the song played, and the song rating.								*
*																										*
*				This program will display and let you choose the option from the menu:					*
*				1.Load: load the list of songs from the file and display it to the screen				*
*				2.Insert: allow user to input information to the song and then insert it to the list	*
*				3.Delete: allow user to find a specific song by any fields in the song and				*
*						  delete the song from the list													*
*				4.Edit: allow user to search for a specific song and edit the information within		*
*						that song																		*	
*				5.Seach: allow user to search for a song in the list by any information and then		*
*						 display the found song															*
*				6.Print: display all the songs in the list												*
*				7.Store: store the list of songs to the file											*	
*				8.Exit: save the list of songs to the file and exit the program							*	
*********************************************************************************************************/

#include "music.h"

#define ARTIST 0
#define ALBUM 1
#define TITLE 2
#define GENRE 3	

/*********************************************************************************************************
 * Function: display_option ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: Display the option to a user to screen
 * Input parameters : none
 * Output parameters: the option from user
 * Returns: none                                     
 * Preconditions: none
 * Postconditions: option been send out                     
 ***********************************************************************************************************/
void display_option(int *option)
{
	puts("Please choose the option below:\n");
	puts("1.Load the record from the file");
	puts("2.Insert and sort a song to the list");
	puts("3.Delete a song from a list");
	puts("4.Edit a song");
	puts("5.Seach a song");
	puts("6.Print the list of songs");
	puts("7.Store the record list to the file");
	puts("8.Exit");
	printf("---> ");
	scanf("%d", option);
}

/*********************************************************************************************************
 * Function: initRecord ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: initialize the empty list
 * Input parameters : none
 * Output parameters: Node point to *pList
 * Returns: none                                     
 * Preconditions: none
 * Postconditions: pList been initialize to empty                     
 ***********************************************************************************************************/
void initRecord(Node **pList)
{
	*pList = NULL;
}

/*********************************************************************************************************
 * Function: isEmpty ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: perfrom a check if a list is empty
 * Input parameters : Node point to pList
 * Output parameters: none
 * Returns: 1 if the list is empty; 0 otherwise                                     
 * Preconditions: *pList hass been read in
 * Postconditions: value 1 or 0 indicate the status of list                     
 ***********************************************************************************************************/
int isEmpty(Node *pList)
{
	return (pList == NULL);
}

/*********************************************************************************************************
 * Function: getSongData ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: get information of song from user
 * Input parameters : none
 * Output parameters: none
 * Returns: information of song through the node
 * Preconditions: none
 * Postconditions: none
 ***********************************************************************************************************/
Node *getSongData(void)
{
	char *artist, *albumTitle, *songTitle, *genre;
	Length songLength = {0,0};
	int timesPlayed = 0, rating = 0;
	Node *pSong = NULL;

	artist = (char *) malloc(sizeof (strlen(artist)));
	albumTitle = (char *) malloc(sizeof (strlen(albumTitle)));
	songTitle = (char *) malloc(sizeof (strlen(songTitle)));
	genre = (char *) malloc(sizeof (strlen(genre)));

	pSong = (Node *) malloc(sizeof (Node));
	
	fflush(stdin);
	printf("Input the artist name: ");
	gets(artist);
	printf("Input the album title: ");
	gets(albumTitle);
	printf("Input the song title: ");
	gets(songTitle);
	printf("Input the genre: ");
	gets(genre);
	printf("Input the length of song in minute: ");
	scanf("%d", &songLength.minute);
	printf("Input the length of song in second: ");
	scanf("%d", &songLength.second);
	printf("Input the number of time played: ");
	scanf("%d", &timesPlayed);
	do
	{
		printf("Input the song rating: ");
		scanf("%d", &rating);
		
		if((rating < 1) || (rating > 5))
			printf("Invalid rating, please input again\n");
	}while((rating < 1) || (rating > 5));



	strcpy(pSong->data.artist, artist);
	strcpy(pSong->data.albumTitle, albumTitle);
	strcpy(pSong->data.songTitle, songTitle);
	strcpy(pSong->data.genre, genre);

	pSong->data.songLength.minute = songLength.minute;
	pSong->data.songLength.second = songLength.second;
	pSong->data.timesPlayed = timesPlayed;
	pSong->data.rating = rating;

	return pSong;
}

/*********************************************************************************************************
 * Function: printRecord ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: display the list of song to the screen
 * Input parameters : Node point to pList
 * Output parameters: none
 * Returns: none
 * Preconditions: *pList has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void printRecord(Node *pList)
{
	printf("Record--> \n");

	while(!isEmpty(pList))
	{
		printf("Artist name : %s\n", pList->data.artist);
		printf("Album title : %s\n", pList->data.albumTitle);
		printf("Song title  : %s\n", pList->data.songTitle);
		printf("Genre       : %s\n", pList->data.genre);
		printf("Song length : %d:%d\n", pList->data.songLength.minute, pList->data.songLength.second);
		printf("Times played: %d\n", pList->data.timesPlayed);
		printf("Rating      : %d\n", pList->data.rating);
		printf("<-->\n");

		pList = pList->pNext;
	}

	printf("NULL\n");
}

/*********************************************************************************************************
 * Function: insertSong ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: search and edit a specific song from information form user input
 * Input parameters : Node point to *pList and Node point to newSong
 * Output parameters: none
 * Returns: pList, the first of the list
 * Preconditions: **pList and *newSong has been read in
 * Postconditions: pList is send out
 ***********************************************************************************************************/
void insertSong(Node **pList, Node *newSong, int sortOption)
{
	Node *curSong = NULL;
	Node *next = NULL;

	curSong = *pList;


	 if ((*pList) == NULL)
	 {
		 *pList = newSong;
		 (*pList)->pNext = NULL;
		 (*pList)->pPrev = NULL;
	 }
	 else
	 {		 
		 switch(sortOption)
		 {
			case 2:
				while((curSong->pNext != NULL) && (strcmp(newSong->data.genre, curSong->data.genre)) == 1)
			curSong = curSong->pNext;

				break;

			case 3:
				while((curSong->pNext != NULL) && (newSong->data.rating > curSong->data.rating))
			curSong = curSong->pNext;

				break;

			default:
				while((curSong->pNext != NULL) && (strcmp(newSong->data.artist, curSong->data.artist)) == 1)
			curSong = curSong->pNext;
				break;
		 }

		  /*insert at end*/
		 if (curSong->pNext == NULL)
		 {
			 newSong->pPrev = curSong;
			 newSong->pNext = curSong->pNext;
			 curSong->pNext = newSong;
		 }
		 /*insert at beginning*/
		else if (curSong == *pList) 
		 {
			 newSong->pPrev = curSong->pPrev; 
			 newSong->pNext = curSong;
			 curSong->pPrev = newSong;
			 *pList = newSong;
		 }
		 /*insert between 2 songs*/
		 else
		 {
			 newSong->pPrev = curSong->pPrev;
			 newSong->pNext = curSong;
			 curSong->pPrev->pNext = newSong;
			 curSong->pPrev = newSong;
		 }
	 }
}

/*********************************************************************************************************
 * Function: deleteSong ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: delete a specific song from list
 * Input parameters : Node point to *pList
 * Output parameters: none
 * Returns: pList, the head of the list
 * Preconditions: **pList has been read in
 * Postconditions: pList been send out
 ***********************************************************************************************************/
void deleteSong(Node **pList)
{
	Node *pTemp = NULL;
	char *deleteSongTitle;
	
	deleteSongTitle = (char *) malloc(sizeof (char));

	printf("Input the song title to delete: ");
	fflush(stdin);
	gets(deleteSongTitle);
	printf("The song to be deleted is: %s\n", deleteSongTitle);
		
	if(*pList != NULL)
	{
		/*delete first node*/
		if (strcmp((*pList)->data.songTitle, deleteSongTitle) == 0)
		 {	 
			 pTemp = *pList;
			 *pList = (*pList)->pNext;
			 free(pTemp);
		 }
		 /*find the node*/
		 else 
		 {
			 pTemp = (*pList)->pNext;
			 while((!isEmpty(pTemp)) && (strcmp(pTemp->data.songTitle, deleteSongTitle) != 0))
				 pTemp = pTemp ->pNext;
			 
			 if (pTemp == NULL)
				puts("Song title not found");
			 else
			 {
				 pTemp-> pPrev-> pNext = pTemp-> pNext;
				 if (pTemp-> pNext)
					pTemp-> pNext-> pPrev = pTemp-> pPrev;
				 free(pTemp);
			 }
		 }
	}
	else
		puts("No data to be deleted");
}

/*********************************************************************************************************
 * Function: search()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: search for a specific song in the list
 * Input parameters : Node point to pList
 * Output parameters: status of search
 * Returns: foundNode - the song that is found if exist
 * Preconditions: *pList has been read in
 * Postconditions: status of search been send out
 ***********************************************************************************************************/
Node *search(Node *pList, int *status)
{
	int option = 0, data = 0, minute = 0, second = 0;
	char *string;
	Node *foundNode = NULL;
	
	string = (char*) malloc(sizeof(strlen(string))); 
	foundNode = (Node *)malloc(sizeof(Node));	
	*status = 0;

	
	printf("Please input search field option:\n1.Artist\n2.Albulm\n3.Song\n4.Genre\n5.Length of song\n6.Number of times played song\n7.Rating of song\n--> ");
	scanf("%d", &option);

	fflush(stdin);

	switch(option)
	{
		case 1:
			printf("Input the artist name to search: ");
			gets(string);
			while((pList != NULL) && strcmp(pList->data.artist,string) != 0)
				pList = pList->pNext;
			break;
		case 2:
			printf("Input the album name to search: ");
			gets(string);
			while((pList != NULL) && strcmp(pList->data.albumTitle,string) != 0)
				pList = pList->pNext;
			break;
		case 3:
			printf("Input the song title to search: ");
			gets(string);
			while((pList != NULL) && strcmp(pList->data.songTitle,string) != 0)
				pList = pList->pNext;
			break;
		case 4:
			printf("Input the genre type to search: ");
			gets(string);
			while((pList != NULL) && strcmp(pList->data.genre,string) != 0)
				pList = pList->pNext;
			break;
		case 5:
			printf("Please choose option:\n1.Search by minute\n2.Search by second\n--> ");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("Input the length in minute: ");
				scanf("%d", &minute);
				while((pList != NULL) && (pList->data.songLength.minute != minute))
					pList = pList->pNext;
			}
			else if(option == 2)
			{
				printf("Input the length in second: ");
				scanf("%d", &second);
				while((pList != NULL) && (pList->data.songLength.second != second))
					pList = pList->pNext;
			}
			else
				puts("Error in input");
			break;
		case 6:
			printf("Input the times played song to search: ");
			scanf("%d", &data);
			while((pList != NULL) && (pList->data.timesPlayed != data))
				pList = pList->pNext;
			break;
		case 7:
			printf("Input the song rating to search: ");
			scanf("%d", &data);
			while((pList != NULL) && (pList->data.rating != data))
				pList = pList->pNext;
			break;
		default:
			puts("Error in input\n");
			break;
		}

	if(pList != NULL)
	{
		puts("Data found: \n");

		*status = 1;

		strcpy(foundNode->data.artist,pList->data.artist);
		strcpy(foundNode->data.albumTitle,pList->data.albumTitle);
		strcpy(foundNode->data.songTitle,pList->data.songTitle);
		strcpy(foundNode->data.genre,pList->data.genre);
		foundNode->data.songLength.minute = pList->data.songLength.minute;
		foundNode->data.songLength.second = pList->data.songLength.second;
		foundNode->data.timesPlayed = pList->data.timesPlayed;
		foundNode->data.rating = pList->data.rating;
	}
	else
		puts("No data found\n");

	return foundNode;
}

/*********************************************************************************************************
 * Function: printSearchNode ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: display the found song from search
 * Input parameters : Node point to foundNode, and the status of search song
 * Output parameters: none
 * Returns: none
 * Preconditions: *foundNode and status has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void printSearchNode(Node *foundNode, int status)
{
	if(status == 1)
	{
		
		printf("Artist name : %s\n", foundNode->data.artist);
		printf("Album title : %s\n", foundNode->data.albumTitle);
		printf("Song title  : %s\n", foundNode->data.songTitle);
		printf("Genre       : %s\n", foundNode->data.genre);
		printf("Song length : %d:%d\n", foundNode->data.songLength.minute, foundNode->data.songLength.second);
		printf("Times played: %d\n", foundNode->data.timesPlayed);
		printf("Rating      : %d\n", foundNode->data.rating);
	}
}

/*********************************************************************************************************
 * Function: getSongFromString()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: get for the information of song from a file
 * Input parameters : the buff[BUFFER_LEN] of the file
 * Output parameters: none
 * Returns: a Node newSong 
 * Preconditions: buff[BUFFER_LEN] has been read in
 * Postconditions: a newSong has send out
 ***********************************************************************************************************/
Node* getSongFromString(char buff[BUFFER_LEN])
{
	char* buffer[4];
	Node* newSong = NULL;
	int minute = 0, second = 0, timesPlayed = 0, rating = 0;

	buffer[ARTIST] = strtok(buff,",");
	buffer[ALBUM] = strtok(0,",");
	buffer[TITLE] = strtok(0,",");
	buffer[GENRE] = strtok(0,",");
	minute = strtok(0,":");
	second = strtok(0,",");
	timesPlayed = strtok(0,",");
	rating = strtok(0,",");

	minute = atoi(minute);
	second = atoi(second);
	timesPlayed = atoi(timesPlayed);
	rating = atoi(rating);

	newSong = makeNode(buffer[ARTIST], buffer[ALBUM], buffer[TITLE], buffer[GENRE], minute, second, timesPlayed, rating);

	return newSong;
}

/*********************************************************************************************************
 * Function: makeNode ()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: create a node from parameter information
 * Input parameters : the string of artist, album title, song title, genre, and minute, second, 
 *					  the times song played, and song rating as integer
 * Output parameters: none
 * Returns: the newNode with new information
 * Preconditions: string of artist, album title, song title, genre, and minute, second, 
 *				  the times song played, and song ratinghas been read in
 * Postconditions: none
 ***********************************************************************************************************/
Node* makeNode(char artist[ARTIST_LEN], char albumTitle[ALBUM_LEN], char songTitle[TITLE_LEN], char genre[GENRE_LEN], int minute, int second, int timesPlayed, int rating)
{
	Node *newSong = NULL;
	
	newSong = (Node *)malloc(sizeof(Node));

	strcpy(newSong->data.artist,artist);
	strcpy(newSong->data.albumTitle,albumTitle);
	strcpy(newSong->data.songTitle,songTitle);
	strcpy(newSong->data.genre,genre);
	newSong->data.songLength.minute = minute;
	newSong->data.songLength.second = second;
	newSong->data.timesPlayed = timesPlayed;
	newSong->data.rating = rating;

	return newSong;
}

/*********************************************************************************************************
 * Function: load()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: load song information from a file
 * Input parameters : the name of the file
 * Output parameters: none
 * Returns: a Node newNode 
 * Preconditions: the name of the file has been read in
 * Postconditions: none
 ***********************************************************************************************************/
Node* load(char* filename, int sortOption)
{
	FILE* inPtr = fopen(filename,"r");
	Node* head = 0;
	Node* newNode = 0;
	char buffer[BUFFER_LEN];
	if(inPtr != 0)
	{
		while(!feof(inPtr))
		{	
			if(fgets(buffer,BUFFER_LEN,inPtr) > 0)
			{
				newNode = getSongFromString(buffer);
				if(newNode == 0)
				{
					printf("\nMEMORY ALLOCATION ERROR\n");
					break;
				}
				insertSong(&head,newNode, sortOption);
			}
		}
	}
	
	fclose(inPtr);

	return head;
}

/*********************************************************************************************************
 * Function: store()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: store the list of songs into a file
 * Input parameters : the name of the file and Node point to pList
 * Output parameters: none
 * Returns: none
 * Preconditions: the name of the file and pList has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void store(char* filename,Node* pList)
{
	FILE *outPtr = fopen(filename,"w");
	char number[10], second[10], timesPlayed[10], rating[10];

	while(pList != 0)
	{
		itoa(pList->data.songLength.minute, number, 10);
		itoa(pList->data.songLength.second, second, 10);
		itoa(pList->data.timesPlayed, timesPlayed, 10);
		itoa(pList->data.rating, rating, 10);

	
		fprintf(outPtr,"%s,%s,%s,%s,%s:%s,%s,%s \n",pList->data.artist, pList->data.albumTitle, pList->data.songTitle, pList->data.genre, number, second, timesPlayed, rating);
			pList = pList->pNext;

		
	}
	
	fclose(outPtr);
}

/*********************************************************************************************************
 * Function: editSong()                                    
 * Date Created: Jan 29, 2012                          
 * Date Last Modified: Feb 03, 2012                    
 * Description: edit the information of the song
 * Input parameters : none
 * Output parameters: *pList
 * Returns: none 
 * Preconditions: **pList has been read in 
 * Postconditions: *pList been send out
 ***********************************************************************************************************/
int editSong(Node **pList)
{
	Node *pTemp = NULL, *newSong = NULL;
	char editSongTitle[TITLE_LEN];
	int status = 0;
	
	printf("Input the song title to edit: ");
	scanf("%s", editSongTitle);
		
	if(*pList != NULL)
	{
		/*delete first node*/
		if (strcmp((*pList)->data.songTitle, editSongTitle) == 0)
		 {	 
			 pTemp = *pList;
			 *pList = (*pList)->pNext;
			 free(pTemp);

			 status = 1;
		 }
		 else /*find the node*/
		 {
			 pTemp = (*pList)->pNext;
			 while((!isEmpty(pTemp)) && (strcmp(pTemp->data.songTitle, editSongTitle) != 0))
				 pTemp = pTemp ->pNext;
			 
			 if (pTemp == NULL)
				puts("Not found");
			 else
			 {
				 pTemp-> pPrev-> pNext = pTemp-> pNext;
				 if (pTemp-> pNext)
					pTemp-> pNext-> pPrev = pTemp-> pPrev;
				 free(pTemp);

				 status = 1;
			 }
		 }
	}
	else
		puts("No song to be edit");

	return status;
}


int getSortOption(void)
{
	int sortOption = 0;

	puts("Please choose sort option:");
	puts("1.Sort by artist name");
	puts("2.Sort by song genre");
	puts("3.Sort by song rating");
	printf("--> ");
	scanf("%d", &sortOption);
	puts("Please input song information to insert:");
	
	return sortOption;
}
