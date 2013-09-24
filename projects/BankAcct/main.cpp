/********************************************************************************************************
* Programmer: Trung Nguyen																				*
* Class: Cpt S 122, Spring 2012																			*	
* Programming Assignment 05: Basic Bank Application in C++												*	
* Date: February 29, 2012																				*
* Description: This program display the main menu for the bank application and do te flowwowing:		*
*				1. Create new Account: create the new account for the user								*
*				2. Debit money to Account: search for the specific account and withdraw money that		*
*											is not exceed the balance in the account					*
*				3. Credit money from Account: search for the specific account and add money				*
*											  into the account and store back to the balance			*
*				4. Modify the Account: search for the specific account and modify the account infomation*
*				5. Delete the Account: search and delete the account									*
*				6. Print out the list of account: print out the screen all the account in the bank		*
*				7. Exit: exit the program																*
*																										*	
*********************************************************************************************************/

#include "Bank.h"

int main(void)
{
	Account *account, *foundNode;
	Bank bank;
	int option;
	char answer;
	bool error;

	do
	{
		option = bank.display_menu();
		fflush(stdin);
		switch(option)
		{
			case 1:
				account = bank.createAccount();
				bank.insertFront(account);
				break;
			case 2:
				foundNode = bank.searchAccount(&error);
				if(!error)
				{
					account = bank.debitAccount(foundNode);
					cout<<foundNode<<endl;
				}
				break;
			case 3:
				foundNode = bank.searchAccount(&error);
				if(!error)
				{
					account = bank.creditAccount(foundNode);
					cout<<foundNode<<endl;
				}
				break;
			case 4:
				foundNode = bank.searchAccount(&error);
				if(!error)
				{
					cout<<foundNode<<endl;
					account = bank.modifyAccount(foundNode);
					cout<<account<<endl;
				}
					break;
			case 5:
				foundNode = bank.searchAccount(&error);
				if(!error)
				{
					bank.deleteNode(foundNode);
					cout<<bank<<endl;
				}
				break;
			case 6:
				cout<<bank<<endl;
				break;
			default:
				exit(1);
				break;
		}
		
		cout<<"Do you want to continue? <Y/N>: ";
		cin>> answer;
		system ("cls");

	}while((answer == 'y') || (answer == 'Y'));

	return 0;
}