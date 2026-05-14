#include <iostream>
#include <string>
#include <utility> //std::swap
#include "../include/ListManager.h"

using namespace std;

Transaction transactions[100]; //transaction object array
int countT = 0;  // counts Transactions

bool isValidDate(string date) {    // Validate date format YYYY-MM-DD
    if(date.length() != 10) return false;

    if(date[4] != '-' || date[7] != '-') return false;  //array indexing

    for(int i = 0; i < date.length(); i++) {
        if(i == 4 || i == 7) continue; //jump to next iteration
        if(!isdigit(date[i])) return false;  //isdigit standard library included in iostream
    }

    return true;
}

void addTransaction() {  //uses arrays
    Transaction t;  //local transaction object
    t.id = countT + 1;  //assigns id=unique value

    do {
        cout << "Enter amount: ";
        cin >> t.amount;  //float

        if(cin.fail() || t.amount <= 0) {  //cin.fail() checks if input is not a valid float
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

    if(!isValidDate(t.date)) {   // Validate date format with boolean function
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

string padRight(string text, int width) {   //table formatting
    if(text.length() >= width) {
        return text.substr(0, width - 1) + " "; //take width-1 char substring 
    }                                           //returns trimmed text

    return text + string(width - text.length(), ' '); 
}  // if text is shorter than width

void displayTransactions() {

    if(countT == 0) {
        cout << "\nNo transactions available.\n";
        return;
    }

    cout << padRight("\nID", 6);  //calls padRight function
    cout << padRight("Amount", 14);
    cout << padRight("Category", 17);
    cout << padRight("Date", 14);
    cout << padRight("Type", 10) << endl;

    cout << "-----------------------------------------------------------\n";

    for(int i = 0; i < countT; i++) { //loop through transactions array 

        cout << padRight(to_string(transactions[i].id), 5);  //number to string

        cout << "Rs. "<< padRight(
            to_string((int)transactions[i].amount), 10
        );

        cout << padRight(transactions[i].category, 15);

        cout << padRight(transactions[i].date, 15);

        cout << padRight(transactions[i].type, 10) << endl;
    }
}

Transaction* getTransactions() {
    return transactions;   //returns pointer to transactions array
}

int getCount() {
    return countT;  //returns transaction count
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

    for(int i = 0; i < countT - 1; i++) { //how many passes needed

        for(int j = 0; j < countT - i - 1; j++) { //check each pair

            bool shouldSwap = false;  //bool variable

            if(transactions[j].amount >
               transactions[j + 1].amount) {

                shouldSwap = true;
            }else if(
                transactions[j].amount ==
                transactions[j + 1].amount
            ) {

                if(transactions[j].date >
                   transactions[j + 1].date) {

                    shouldSwap = true;
                }
            }

            if(shouldSwap) {

                swap(
                    transactions[j],
                    transactions[j + 1]
                );
            }
        }
    }
    cout << "\nTransactions Sorted Successfully.\n";
}


void searchByCategory(string category) {

    bool isFound = false;

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

            isFound = true;
        }
    }

    if(!isFound) {

        cout << "No Transactions Found.\n";
    }
}

void showHighestExpense() {

    if(countT == 0) {
        cout << "\nNo Transactions Available.\n";
        return;
    }

    int highestIndex = -1;

    for(int i = 0; i < countT; i++) {

        if(transactions[i].type == "expense") {

             if(highestIndex == -1 ||
               transactions[i].amount > transactions[highestIndex].amount) {
                highestIndex = i;
            }
        }
    }

    if(highestIndex == -1) {
        cout << "\nNo Expense Transactions Found.\n";
        return;
    }

    cout << "\n===== HIGHEST EXPENSE =====\n\n";

    cout << "ID: "
         << transactions[highestIndex].id << endl;

    cout << "Amount: Rs. "
         << transactions[highestIndex].amount << endl;

    cout << "Category: "
         << transactions[highestIndex].category << endl;

    cout << "Date: "
         << transactions[highestIndex].date << endl;
}

void totalTransactions() {

    cout << "\nTotal Transactions: "
         << countT << endl;
}