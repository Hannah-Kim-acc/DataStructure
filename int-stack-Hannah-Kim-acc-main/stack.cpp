/*********************
Name: Che Hyun Kim
Coding 03
Purpose: This is a revised program after finding/fixing problems such as bugs and logic errors in a given code.
**********************/

#include "stack.h"

Stack::Stack() {
    top = -1;
}

bool Stack::push(int x) {
    bool toReturn = false;
    if(top < (MAX-1)) {
        stack[++top] = x;
        toReturn = true;
    }
    return toReturn;
}

bool Stack::pop(int *intPtr) {
    bool toReturn = false;
    if (top>-1) {
        *intPtr = stack[top--];
        toReturn = true;
    }
    return toReturn;
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::peek(int *intPtr) {
    bool toReturn = false;
    if (top !=-1) {
        *intPtr = stack[top];
        toReturn = true;
    }
    return toReturn;
}
