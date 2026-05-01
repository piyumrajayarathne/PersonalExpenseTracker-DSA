#include <iostream>
#include "../include/ListManager.h"
#include "../include/StackManager.h"
#include "../include/HashTable.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Add Transaction\n";
        cout << "2. Display Transactions\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
    addTransaction();

    Transaction* t = getTransactions();
    int c = getCount();

    pushTransaction(t[c-1]);
    updateCategory(t[c-1].category, t[c-1].amount, t[c-1].type);

    break;
}

            case 2:
                displayTransactions();
                break;
        }

    } while(choice != 0);

    return 0;
}