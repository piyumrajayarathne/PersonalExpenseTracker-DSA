#include <iostream>
#include "../include/ListManager.h"
#include "../include/StackManager.h"
#include "../include/HashTable.h"

using namespace std;

void showBalance() {
    cout << "\n===== BALANCE SUMMARY =====\n\n";

    cout << "Item            Amount\n";
    cout << "----------------------------\n";

    cout << "Total Income";
    int space1 = 16 - 12;
    while(space1-- > 0) cout << " ";
    cout << getTotalIncome() << endl;

    cout << "Total Expense";
    int space2 = 16 - 13;
    while(space2-- > 0) cout << " ";
    cout << getTotalExpense() << endl;

    cout << "----------------------------\n";

    cout << "Net Balance";
    int space3 = 16 - 11;
    while(space3-- > 0) cout << " ";
    cout << getBalance() << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== PERSONAL EXPENSE TRACKER =====\n";
        cout << "\n1. Add Transaction";
        cout << "\n2. Display Transactions";
        cout << "\n3. Delete Transaction";
        cout << "\n4. Undo Last Transaction";
        cout << "\n5. Category Summary";
        cout << "\n6. Show Balance";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";

    do {
        cin >> choice;

        if(cin.fail() || choice < 0 || choice > 6) {
            cout << "Invalid choice! Please enter a number between 0 and 6.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while(cin.fail() || choice < 0 || choice > 6);

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
                if(getCount() == 0) {
                    cout << "No transactions to delete!\n";
                    break;
                }
                int id;

                do {
                    cout << "Enter ID to delete: ";
                    cin >> id;

                    if(cin.fail() || id <= 0) {
                    cout << "Invalid ID! Enter a valid number.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    }

                } while(cin.fail() || id <= 0);

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

            case 6: 
                showBalance();
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