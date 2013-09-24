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

/*********************************************************************************************************
Overloading operator << to output the class Bank, and return the output stream                                      
 ***********************************************************************************************************/
ostream &operator<< (ostream &output, Bank &rhs)
{
	Account *tempPtr = rhs.getStartPtr();

	while(tempPtr != NULL)
	{
		output<<"Name    : "<< tempPtr->getName();
		output<<"\n AccNo  : "<< tempPtr->getAccNo();
		output<<"\n Balance: "<< tempPtr->getBalance();
		output<<"\n Date   : "<< tempPtr->getDate();
		output<<"\n-->\n";

		tempPtr = tempPtr->getNextPtr();
	}

	output<<" NULL\n";

	return output;
}

/*********************************************************************************************************
 * Function: Bank ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: constructor for class account
 * Input parameters : none
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
Bank::Bank()
{
	this->mStartPtr = NULL;
}

//destructor
Bank::~Bank()
{
	deleteList();
}

/*********************************************************************************************************
 * Function: setStartPtr ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the start pointer 
 * Input parameters : startPtr
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Bank::setStartPtr(Account *startPtr)
{
	this->mStartPtr = startPtr;
}

/*********************************************************************************************************
 * Function: getStartPtr ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the start poiter 
 * Input parameters : none
 * Output parameters: none
 * Returns: start poiter                                                 
 ***********************************************************************************************************/
Account* Bank::getStartPtr()
{
	return (this->mStartPtr);
}

/*********************************************************************************************************
 * Function: createAccount ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: create the new account
 * Input parameters : none
 * Output parameters: none
 * Returns: the new account that is created                                                 
 ***********************************************************************************************************/
Account* Bank::createAccount()
{
	Account *newAcc;

	newAcc = new Account();

	cout<<"Please enter name: ";
	getline(cin, newAcc->mName);
	cout<<"Please enter account number: ";
	cin>> newAcc->mAccountNo;
	cout<<"Please enter initial balance: ";
	cin>> newAcc->mBalance;
	fflush(stdin);
	cout<<"Please enter the date account open: ";
	getline(cin, newAcc->mDate);

	cout<<"-->Created Account Info:\n Name: "<<newAcc->mName<<"||\tAccNo: "<<newAcc->mAccountNo<<"||\tInitBal: "<<newAcc->mBalance<< "||\tDate: "<<newAcc->mDate<<"\n"<<endl;

	return newAcc;
}

/*********************************************************************************************************
 * Function: searchAccount ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: search for the account
 * Input parameters : none
 * Output parameters: none
 * Returns: the account that is found                                                 
 ***********************************************************************************************************/
Account* Bank::searchAccount(bool *error)
{
	Account *foundAccount;
	string accName;

	foundAccount = new Account();
	*error = false;

	foundAccount = mStartPtr;
	cout<<"Please input the account name to be searched: ";
	cin>>accName;

	while((foundAccount != NULL) && (foundAccount->getName() != accName))
			foundAccount = foundAccount->getNextPtr();
		
		if(foundAccount != NULL)
			cout<<"Account Found!!!\n";
		else
		{
			*error = true;
			cout<<"No account found!!!\n"<<endl;
		}

		fflush(stdin);

	return foundAccount;
}

/*********************************************************************************************************
 * Function: creditAccount ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: adding money to the account
 * Input parameters : the account to input money
 * Output parameters: none
 * Returns: the account after the money is credited                                                 
 ***********************************************************************************************************/
Account* Bank::creditAccount(Account *acc)
{
	cout<<"Please input the amount of credit to add: ";
	double amountCredit;
	cin>>amountCredit;
		
	acc->mBalance = acc->mBalance + amountCredit;
	cout<<"New account balance after deposit is: "<<acc->mBalance<<endl;

	return acc;
}

/*********************************************************************************************************
 * Function: debitAccount ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: withdraw money to the account
 * Input parameters : the account to withdraw money
 * Output parameters: none
 * Returns: the account after the money is debited                                                 
 ***********************************************************************************************************/
Account* Bank::debitAccount(Account *acc)
{
	double amountDebit;
	bool error;

	cout<<"Please input the amount you want to withdraw: ";
	
	do{
		error = false;
		cin>>amountDebit;

		if(amountDebit > acc->mBalance){
			cout<<"Your balance is not sufficient to withdraw!!!\nYour balance will remain the same.\nPlease input again: "<<endl;
			error = true;
		}
		else{
			acc->mBalance = acc->mBalance - amountDebit;
		cout<<"New balance after withdraw is: "<<acc->mBalance<<endl;
		}
	}while(error);

	return acc;
}

/*********************************************************************************************************
 * Function: insertFront ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: insert the account class into the bank class
 * Input parameters : the account to be inserted
 * Output parameters: none
 * Returns: boolean value 1 or 0 indicate success or faliure                                                 
 ***********************************************************************************************************/
bool Bank::insertFront(Account *newAccount)
{
	bool success = true;

	if(newAccount == NULL)
		success = false;
	else
	{
		if(mStartPtr == NULL)
			mStartPtr = newAccount;
		else
		{
			newAccount->setNextPtr(mStartPtr);
			mStartPtr = newAccount;
		}
	}

	return success;
}

/*********************************************************************************************************
 * Function: deleteNode ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: delete the account class from the bank class
 * Input parameters : the account to be delete
 * Output parameters: none
 * Returns: boolean value 1 or 0 indicate success or faliure                                                 
 ***********************************************************************************************************/
bool Bank::deleteNode(Account *searchAccount)
{
	Account *currPtr = NULL, *prevPtr = NULL;
	bool success;

	currPtr = mStartPtr;

	if(mStartPtr != NULL)
	{
		while((currPtr != NULL) && (currPtr->getName() != searchAccount->getName()))
		{
			prevPtr = currPtr;
			currPtr = currPtr->getNextPtr();
		}

		if(currPtr != NULL)
		{
			if(prevPtr == NULL)
				mStartPtr = currPtr->getNextPtr();
			else
				prevPtr->setNextPtr(currPtr->getNextPtr());
		
			cout<<"The account '"<<currPtr->mName<<"' is deleted\n"<<endl;
			delete currPtr;
			success = true;
		}
	}
	else
		cout<<"The account name is not found. No account is deleted\n"<<endl;

	return success;
}

/*********************************************************************************************************
 * Function: modifyAccount ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: modify the account 
 * Input parameters : the account to be modify
 * Output parameters: none
 * Returns: the account after being modified                                             
 ***********************************************************************************************************/
Account* Bank::modifyAccount(Account *account)
{
	Account temp;

	cout<<"Modify the account of "<<account->mName<<"\n"<<endl;

	cout<<"Please enter new name: ";
	getline(cin, account->mName);
	cout<<"Please enter new account number: ";
	cin>> account->mAccountNo;
	cout<<"Please enter new initial balance: ";
	cin>> account->mBalance;
	fflush(stdin);
	cout<<"Please enter the new date account open: ";
	getline(cin, account->mDate);

	return account;
}

/*********************************************************************************************************
 * Function: display_menu ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: display menu to the screen
 * Input parameters : none
 * Output parameters: none
 * Returns: the user answer                                             
 ***********************************************************************************************************/
int Bank::display_menu()
{
	cout<<"********************************************\n";
	cout<<"1. Create new Account\n";
	cout<<"2. Debit money to Account\n";
	cout<<"3. Credit money from Account\n";
	cout<<"4. Modify the Account\n";
	cout<<"5. Delete the Account\n";
	cout<<"6. Print out the list of account\n";
	cout<<"7. Exit\n";
	cout<<"********************************************\n-->";

	int option;
	cin>>option;

	return option;
}

/*********************************************************************************************************
 * Function: deleteList ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: delete all the account in the bank
 * Input parameters : none
 * Output parameters: none
 * Returns: boolean value 1 or 0 indicate success or faliure                                                 
 ***********************************************************************************************************/
bool Bank::deleteList ()
{
	Account *tempPtr = NULL, *deletePtr = NULL;
	bool success = false;

	tempPtr = this -> mStartPtr;

	while (tempPtr != NULL)
	{
		deletePtr = tempPtr;
		tempPtr = tempPtr -> getNextPtr ();
		delete deletePtr;
		success = true;
	}

	return success;
}