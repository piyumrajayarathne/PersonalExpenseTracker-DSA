#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

struct Transaction {
    int id;
    float amount;
    string category;
    string date;
    string type;
};

#endif