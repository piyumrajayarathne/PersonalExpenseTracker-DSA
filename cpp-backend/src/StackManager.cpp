#include "../include/StackManager.h"

Transaction stackArr[100];
int top = -1;

void pushTransaction(Transaction t) {
    stackArr[++top] = t;
}

Transaction popTransaction() {
    return stackArr[top--];
}

bool isEmpty() {
    return top == -1;
}