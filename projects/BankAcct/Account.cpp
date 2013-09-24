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

#include "Account.h"

/*********************************************************************************************************
 * Function: Account ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: constructor for class account
 * Input parameters : none
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
Account::Account()
{
	this-> mBalance = 0.0;
	this-> mAccountNo = 0;
	this-> mName = '\0';
	this-> mDate = '\0';
	this-> mNextPtr = NULL;
}

/*********************************************************************************************************
 * Function: Account ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: constructor for class account 
 * Input parameters : initBalance, accountNo, name, date
 * Output parameters: none
 * Returns:none                                                    
 ***********************************************************************************************************/
Account::Account(double initBalance, int accountNo, string name, string date)
{
	this->mBalance = initBalance;

	if(initBalance < 0){
		this->mBalance = 0;
		cout<<"Error!!! Initial balance can not negative!"<<std::endl;
	}

	this->mAccountNo = accountNo;
	this->mName = name;
	this->mDate = date;
	this->mNextPtr = NULL;
}

//Account::Account(Account &newAccount)
//{
//	this->mAccountNo = newAccount.getAccNo();
//	this->mBalance = newAccount.getBalance();
//	this->mDate = newAccount.getDate();
//	this->mName = newAccount.getName();
//	this->mNextPtr = newAccount.getNextPtr();
//}

//destructor
Account::~Account()
{
}

/*********************************************************************************************************
 * Function: setBalance ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the balance 
 * Input parameters : newBalance
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Account::setBalance(double newBalance){
	this->mBalance = newBalance;
}

/*********************************************************************************************************
 * Function: setAccNo ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the account number 
 * Input parameters : newAccNo
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Account::setAccNo(int newAccNo){
	this->mAccountNo = newAccNo;
}

/*********************************************************************************************************
 * Function: setName ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the name 
 * Input parameters : newName
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Account::setName(string newName){
	this->mName = newName;
}

/*********************************************************************************************************
 * Function: setDate ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the date 
 * Input parameters : newDate
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Account::setDate(string newDate){
	this->mDate = newDate;
}

/*********************************************************************************************************
 * Function: setNextPtr ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: setter for the next pointer 
 * Input parameters : nextPtr
 * Output parameters: none
 * Returns: none                                                 
 ***********************************************************************************************************/
void Account::setNextPtr(Account *nextPtr){
	this->mNextPtr = nextPtr;
}

/*********************************************************************************************************
 * Function: getBalance ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the balance 
 * Input parameters : none
 * Output parameters: none
 * Returns: the new balance                                                 
 ***********************************************************************************************************/
double Account::getBalance(){
	return (this->mBalance);
}

/*********************************************************************************************************
 * Function: getAccNo ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the account number 
 * Input parameters : none
 * Output parameters: none
 * Returns: the new account number                                                 
 ***********************************************************************************************************/
int Account::getAccNo(){
	return (this->mAccountNo);
}

/*********************************************************************************************************
 * Function: getName ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the name 
 * Input parameters : none
 * Output parameters: none
 * Returns: the new name                                                 
 ***********************************************************************************************************/
string Account::getName(){
	return (this->mName);
}

/*********************************************************************************************************
 * Function: getDate ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the date 
 * Input parameters : none
 * Output parameters: none
 * Returns: the new datw                                                 
 ***********************************************************************************************************/
string Account::getDate(){
	return (this->mDate);
}

/*********************************************************************************************************
 * Function: getNextPtr ()                                    
 * Date Created: Feb 26, 2012                          
 * Date Last Modified: Feb 20, 2012                    
 * Description: getter for the next pointer 
 * Input parameters : none
 * Output parameters: none
 * Returns: the new next pointer                                                 
 ***********************************************************************************************************/
Account *Account::getNextPtr(){
	return (this->mNextPtr);
}

/*********************************************************************************************************
Overloading operator = to assign the value on the rhs to the lhs , and return 'this' object           
 ***********************************************************************************************************/
Account & Account::operator =(Account &rhs)
{
	if(this != &rhs)
	{
		this->mAccountNo = rhs.getAccNo();
		this->mBalance = rhs.getBalance();
		this->mDate = rhs.getDate();
		this->mName = rhs.getName();
		this->mNextPtr = rhs.getNextPtr();
	}

	return *this;
}

/*********************************************************************************************************
Overloading operator << to output the class Account, and return the output stream                                      
 ***********************************************************************************************************/
ostream &operator<<(ostream &output, Account* &rhs)
{
	output<<"Name    : "<< rhs->getName();
	output<<"\n AccNo  : "<< rhs->getAccNo();
	output<<"\n Balance: "<< rhs->getBalance();
	output<<"\n Date   : "<< rhs->getDate();
	output<<"\n";

	return output;
}

