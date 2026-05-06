#include <iostream>
#include <string>
#include "../include/ListManager.h"

using namespace std;

Transaction transactions[100];
int countT = 0;

void addTransaction() {
    Transaction t;
    t.id = countT + 1;

    do {
        cout << "Enter amount: ";
        cin >> t.amount;

        if(cin.fail() || t.amount <= 0) {
            cout << "Invalid amount! Enter a positive number.\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while(cin.fail() || t.amount <= 0);

    cout << "Enter category: ";
    cin >> t.category;

    cout << "Enter date: ";
    cin >> t.date;

    do {
        cout << "Enter type (income/expense): ";
        cin >> t.type;

        if(t.type != "income" && t.type != "expense") {
            cout << "Invalid type! Enter only income or expense.\n";
        }

    } while(t.type != "income" && t.type != "expense");

    transactions[countT++] = t;

    cout << "Transaction added successfully!\n";
}

string padRight(string text, int width) {
    if(text.length() >= width) {
        return text.substr(0, width - 1) + " ";
    }

    return text + string(width - text.length(), ' ');
}

void displayTransactions() {

    if(countT == 0) {
        cout << "\nNo transactions available.\n";
        return;
    }

    cout << padRight("\nID", 5);
    cout << padRight("Amount", 10);
    cout << padRight("Category", 15);
    cout << padRight("Date", 15);
    cout << padRight("Type", 10) << endl;

    cout << "-----------------------------------------------------------\n";

    for(int i = 0; i < countT; i++) {

        cout << padRight(to_string(transactions[i].id), 5);

        cout << padRight(
            to_string((int)transactions[i].amount), 10
        );

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
        cout << "Transaction not found!\n";
        return;
    }

    for(int i = index; i < countT - 1; i++) {
        transactions[i] = transactions[i + 1];
    }

    countT--;

    cout << "Transaction deleted successfully!\n";
}