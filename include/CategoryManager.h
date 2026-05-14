#ifndef CATEGORYMANAGER_H
#define CATEGORYMANAGER_H
#include <string>
using namespace std;

void showCategorySummary();
void updateCategory(string category, float amount, string type);

float getTotalIncome();
float getTotalExpense();
float getBalance();

#endif
