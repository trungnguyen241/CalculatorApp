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

#ifndef BANK_H
#define BANK_H

#include "Account.h"

class Bank
{
	friend ostream &operator<<(ostream &output, Bank &rhs);

	public:
		Bank();
		~Bank();

		void setStartPtr(Account *startPtr);
		Account *getStartPtr();
		int display_menu();

		Account* createAccount();
		Account* searchAccount(bool *error);
		Account* creditAccount(Account *acc);
		Account* debitAccount(Account *acc);

		bool insertFront(Account *newAccount);
		bool deleteNode(Account *searchAccount);
		bool deleteList();
		Account* modifyAccount(Account *account);

	private:
		Account *mStartPtr;

};

#endif