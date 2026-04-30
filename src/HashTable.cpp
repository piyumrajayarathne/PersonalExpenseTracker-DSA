#include <iostream>
#include "../include/HashTable.h"

using namespace std;

void showCategorySummary() {
    cout << "Category summary " << endl;
}

string categories[10];
float totals[10];
int sizeT = 0;

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
        totals[sizeT] = (type == "expense") ? amount : -amount;
        sizeT++;
    } else {
        totals[index] += (type == "expense") ? amount : -amount;
    }
}

void showCategorySummary() {
    for(int i = 0; i < sizeT; i++) {
        cout << categories[i] << " : " << totals[i] << endl;
    }
}
