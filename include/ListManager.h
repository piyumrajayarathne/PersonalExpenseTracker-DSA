#ifndef LISTMANAGER_H
#define LISTMANAGER_H

#include "Transaction.h"

void addTransaction();
void displayTransactions();

void deleteTransaction(int id);
Transaction* getTransactions();
int getCount();


#endif
