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

int main(void)
{
	Node *pList = NULL, *newSong = NULL, *foundNode = NULL;
	int option = 0, status = 0, sortOption = 0;
	char answer = '\0';

	initRecord(&pList);

	do
	{
		display_option(&option);
		switch (option)
		{
			case 1:									//load songs from file
				pList = load("inp.txt", sortOption);
				printRecord(pList);
				break;
			case 2:									//insert and sort song to list
				sortOption = getSortOption();
				newSong = getSongData();
				insertSong(&pList, newSong, sortOption);
				store("inp.txt",pList);
				pList = load("inp.txt", sortOption);
				//sort node here
				printRecord(pList);

				break;
			case 3:									//delete a song from list
				deleteSong(&pList);
				break;
			case 4:									//edit a song from list
				status = editSong(&pList);
				if(status == 1)
				{
					newSong = getSongData();
					insertSong(&pList, newSong, sortOption);
					store("inp.txt",pList);
				}
				break;
			case 5:									//search for a song from list
				foundNode = search(pList, &status);
				printSearchNode(foundNode, status);
				break;			
			case 6:
				printRecord(pList);
				break;
			case 7:									//store list to the file
				store("inp.txt",pList);
				break;
			case 8:									//save list and exit
				store("inp.txt",pList);
				exit(system);
				break;
	}

	fflush(stdin);
	printf("Do you want to continue?\n-->");
	answer = getchar();
	system ("cls");
	}while(answer == 'Y' || answer == 'y');
		
	return 0;
}
