#ifndef STACKMANAGER_H
#define STACKMANAGER_H

#include "Transaction.h"

void pushTransaction(Transaction t);
Transaction popTransaction();
bool isEmpty();

#endif