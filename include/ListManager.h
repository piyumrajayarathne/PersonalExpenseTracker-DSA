#ifndef LISTMANAGER_H  //  prevent multiple inclusions
#define LISTMANAGER_H

#include "Transaction.h"  // Include the Transaction struct definition

void addTransaction();
void displayTransactions();

void deleteTransaction(int id); // Function to delete a transaction by ID
Transaction* getTransactions(); // Function to return the transactions array
int getCount(); //no. of transactions

void bubbleSortTransactions(); //sort amount, date ascending
void searchByCategory(string category); //search and display

void showHighestExpense(); //display highest expense transaction
void totalTransactions(); //total count

#endif //close

//function declarations - encapsulation(other files can call without knowing implementation)
