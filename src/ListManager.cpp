#include <iostream>
#include <string>
#include <utility>
#include "../include/ListManager.h"

using namespace std;

Transaction transactions[100];
int countT = 0;

bool isValidDate(string date) {
    if(date.length() != 10) return false;

    if(date[4] != '-' || date[7] != '-') return false;

    for(int i = 0; i < date.length(); i++) {
        if(i == 4 || i == 7) continue;
        if(!isdigit(date[i])) return false;
    }

    return true;
}

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
    do {
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> t.date;

    if(!isValidDate(t.date)) {
        cout << "Invalid date format!\n";
    }

    } while(!isValidDate(t.date));

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

    cout << padRight("\nID", 6);
    cout << padRight("Amount", 14);
    cout << padRight("Category", 17);
    cout << padRight("Date", 14);
    cout << padRight("Type", 10) << endl;

    cout << "-----------------------------------------------------------\n";

    for(int i = 0; i < countT; i++) {

        cout << padRight(to_string(transactions[i].id), 5);

        cout << "Rs. "<< padRight(
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

void bubbleSortTransactions() {

    for(int i = 0; i < countT - 1; i++) {

        for(int j = 0; j < countT - i - 1; j++) {

            if(transactions[j].amount >
               transactions[j + 1].amount) {

                swap(transactions[j],
                     transactions[j + 1]);
            }
        }
    }

    cout << "\nTransactions Sorted Successfully.\n";
}

void searchByCategory(string category) {

    bool found = false;

    cout << "\n===== SEARCH RESULTS =====\n\n";

    for(int i = 0; i < countT; i++) {

        if(transactions[i].category == category) {

            cout << "ID: "
                 << transactions[i].id << endl;

            cout << "Amount: Rs. "
                 << transactions[i].amount << endl;

            cout << "Category: "
                 << transactions[i].category << endl;

            cout << "Date: "
                 << transactions[i].date << endl;

            cout << "Type: "
                 << transactions[i].type << endl;

            cout << "---------------------\n";

            found = true;
        }
    }

    if(!found) {

        cout << "No Transactions Found.\n";
    }
}


