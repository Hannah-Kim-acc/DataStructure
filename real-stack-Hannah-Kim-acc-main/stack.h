/*********************
Name: Che Hyun Kim
Coding 04
Purpose: This assignment is to create a stack object that will work with a struct data type called Data, which contains an int and string.
**********************/


#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    Stack();
    ~Stack();
    
    bool push(int, const string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H
