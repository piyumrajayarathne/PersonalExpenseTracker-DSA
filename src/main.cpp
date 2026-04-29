#include <iostream>
#include "../include/ListManager.h"

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
            case 1:
                addTransaction();
                break;

            case 2:
                displayTransactions();
                break;
        }

    } while(choice != 0);

    return 0;
}