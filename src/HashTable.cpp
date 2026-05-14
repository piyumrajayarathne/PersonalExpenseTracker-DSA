#include <iostream>
#include "../include/HashTable.h"

using namespace std;

string categories[10];
float expenseTotals[10];
float incomeTotals[10];
int sizeT = 0;      /*Number of categories stored*/

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
        expenseTotals[sizeT] = 0;
        incomeTotals[sizeT] = 0;
        index = sizeT;
        sizeT++;
    }

    if(type == "expense") {
        expenseTotals[index] += amount;     /*Total expense of each category*/
        totalExpense += amount;
    } else if(type == "income") {
        incomeTotals[index] += amount;     /*Total income of each category*/
        totalIncome += amount;
    }
}

void showCategorySummary() {
    cout << "\n======= CATEGORY SUMMARY =======\n\n";

    cout << "Category        Expense            Income             Total\n";
    cout << "----------------------------------------------------------------\n";

    float sumExpense = 0;
    float sumIncome = 0;


    for(int i = 0; i < sizeT; i++) {
        float total = expenseTotals[i] + incomeTotals[i];

        cout << categories[i];
        int space = 16 - categories[i].length();
        while(space-- > 0) cout << " ";

        cout << "Rs. "<< expenseTotals[i];
        int space2 = 15 - to_string((int)expenseTotals[i]).length();
        while(space2-- > 0) cout << " ";

        cout << "Rs. "<< incomeTotals[i];
        int space3 = 15 - to_string((int)incomeTotals[i]).length();
        while(space3-- > 0) cout << " ";

        cout << "Rs. "<< total << endl;

        sumExpense += expenseTotals[i];
        sumIncome += incomeTotals[i];
    }

    cout << "------------------------------------------------\n";

    cout << "Total";
    int space = 16 - 5;
    while(space-- > 0) cout << " ";

    cout << "Rs. "<< sumExpense;
    int spaceE = 15 - to_string((int)totalExpense).length();
    while(spaceE-- > 0) cout << " ";

    cout << "Rs. "<< sumIncome;
    int spaceI = 15 - to_string((int)totalIncome).length();
    while(spaceI-- > 0) cout << " ";

}

float getTotalIncome() {  
    return totalIncome;  
}  

float getTotalExpense() {  
    return totalExpense;  
}  

float getBalance() {  
    return totalIncome - totalExpense;  
}
