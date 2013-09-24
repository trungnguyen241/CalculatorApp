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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
	friend class Bank;
	friend ostream &operator<<(ostream &output, Account* &rhs);

	public:
		Account();
		Account(double initBalance, int accountNo, string name, string date);
		//Account (Account &newAccount);
		~Account();

		void setBalance(double newBalance);
		void setAccNo(int newAccNo);
		void setName(string newName);
		void setDate(string newDate);
		void setNextPtr(Account *nextPtr);

		double getBalance();
		int getAccNo();
		string getName();
		string getDate();
		Account *getNextPtr();

		Account & operator= (Account &rhs);		

	private:
		double mBalance;
		int mAccountNo;
		string mName;
		string mDate;
		Account *mNextPtr;
};

#endif