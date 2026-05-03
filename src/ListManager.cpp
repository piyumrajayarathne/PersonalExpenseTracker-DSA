#include <iostream>
#include <string>
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
string padRight(string text, int width) {
    if (text.length() >= width) {
        return text.substr(0, width - 1) + " ";
    }
    return text + string(width - text.length(), ' ');
}

void displayTransactions() {
    cout << padRight("\nID", 5);
    cout << padRight("Amount", 10);
    cout << padRight("Category", 15);
    cout << padRight("Date", 15);
    cout << padRight("Type", 10) << endl;

    cout << "------------------------------------------------\n";
    
    for(int i = 0; i < countT; i++) {
        cout << padRight(to_string(transactions[i].id), 5);
        cout << padRight(to_string((int)transactions[i].amount), 10);
        cout << padRight(transactions[i].category, 15);
        cout << padRight(transactions[i].date, 15);
        cout << padRight(transactions[i].type, 10) << endl;
    }
}

Transaction* getTransactions() {
    return transactions;
}

int getCount() {
    return countT;
}

void deleteTransaction(int id) {
    int index = -1;

    for(int i = 0; i < countT; i++) {
        if(transactions[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout << "Transaction not found\n";
        return;
    }

    for(int i = index; i < countT - 1; i++) {
        transactions[i] = transactions[i + 1];
    }

    countT--;
}

