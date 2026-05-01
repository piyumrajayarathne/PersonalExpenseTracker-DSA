#include <iostream>
#include "../include/ListManager.h"
#include "../include/StackManager.h"
#include "../include/HashTable.h"

using namespace std;

int main() {
    int choice;

    do {
       cout << "\n1. Add Transaction";
cout << "\n2. Display Transactions";
cout << "\n3. Delete Transaction";
cout << "\n4. Undo Last Transaction";
cout << "\n5. Category Summary";
cout << "\n0. Exit";

cout << "\nEnter choice: ";
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
            case 3: {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    deleteTransaction(id);
    break;
}
            case 4: {
    if(!isEmpty()) {
        Transaction t = popTransaction();
        deleteTransaction(t.id);
    }
    break;
}
            case 5:
    showCategorySummary();
    break;
            case 0:
    cout << "Exiting...";
    break;

default:
    cout << "Invalid choice!";
        }
    

    } while(choice != 0);

    return 0;
}