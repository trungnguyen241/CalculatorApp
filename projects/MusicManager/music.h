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

#ifndef PA2_H
#define PA2_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ARTIST_LEN 20
#define ALBUM_LEN 20
#define TITLE_LEN 20
#define GENRE_LEN 100
#define BUFFER_LEN 200


//define struct for length of song
typedef struct length
{
	int second;
	int minute;
}Length;

//define struct for song
typedef struct record
{
	char artist[ARTIST_LEN];
	char albumTitle[ALBUM_LEN];
	char songTitle[TITLE_LEN];
	char genre[GENRE_LEN];
	Length songLength;
	int timesPlayed;
	int rating;
}Record;

//define a node struct
typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;


void display_option(int *option);
void initRecord(Node **pList);
int isEmpty(Node *pList);
Node *getSongData(void);
void printRecord(Node *pList);
int getSortOption(void);
void insertSong(Node **pList, Node *newSong, int sortOption);
void deleteSong(Node **pList);
Node *search(Node *pList, int *status);
void printSearchNode(Node *foundNode, int status);
int editSong(Node **pList);
Node* getSongFromString(char buff[BUFFER_LEN]);
Node* load(char* filename, int sortOption);
void store(char* filename,Node* pList);
Node* makeNode(char artist[ARTIST_LEN], char albumTitle[ALBUM_LEN], char songTitle[TITLE_LEN], char genre[GENRE_LEN], int minute, int second,int timesPlayed, int rating);

#endif