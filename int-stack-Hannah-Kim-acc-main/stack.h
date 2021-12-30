/*********************
Name: Che Hyun Kim
Coding 03
Purpose: This is a revised program after finding/fixing problems such as bugs and logic errors in a given code.
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define MAX 10

class Stack {
private:
    int top;
    int stack[MAX];
    
public:
    Stack();
    
    bool push(int);
    bool pop(int*);
    bool isEmpty();
    bool peek(int *);
};

#endif //STACK_STACK_H
