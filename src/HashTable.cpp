#include <iostream>
#include "../include/HashTable.h"

using namespace std;

string categories[10];
float totals[10];
int sizeT = 0;

float totalIncome = 0;
float totalExpense = 0;

int findCategory(string c) {
    for(int i = 0; i < sizeT; i++) {
        if(categories[i] == c) return i;
    }
    return -1;
}

void updateCategory(string category, float amount, string type) {
    int index = findCategory(category);

    if(index == -1) {
        categories[sizeT] = category;
        totals[sizeT] = amount;
        sizeT++;
    } else {
        totals[index] += amount;
    }

    if(type == "income") {
        totalIncome += amount;
    } else if(type == "expense") {
        totalExpense += amount;
    }
}

void showCategorySummary() {
    cout << "\n===== CATEGORY SUMMARY =====\n\n";

    cout << "Category        Total\n";
    cout << "----------------------------\n";

    float total = 0;

    for(int i = 0; i < sizeT; i++) {
        cout << categories[i];
        int space = 16 - categories[i].length();
        while(space-- > 0) cout << " ";
        cout << totals[i] << endl;

        total += totals[i];
    }

    cout << "----------------------------\n";

    cout << "Total";

    int space = 16 - 5;
    while(space-- > 0) cout << " ";

    cout << total << endl;
}
