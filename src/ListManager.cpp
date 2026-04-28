#include <iostream>
#include "../include/ListManager.h"
using namespace std;

Transaction transactions[100];
int countT = 0;

void addTransaction() {
    Transaction t;
    t.id = countT + 1;

    cout << "Enter amount: ";
    cin >> t.amount;

    cout << "Enter category: ";
    cin >> t.category;

    cout << "Enter date: ";
    cin >> t.date;

    cout << "Enter type (income/expense): ";
    cin >> t.type;

    transactions[countT++] = t;
}

void displayTransactions() {
    for(int i = 0; i < countT; i++) {
        cout << transactions[i].id << " "
             << transactions[i].amount << " "
             << transactions[i].category << " "
             << transactions[i].date << " "
             << transactions[i].type << endl;
    }
}
