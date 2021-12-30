/*********************
Name: Che Hyun Kim
Coding 04
Purpose: This assignment is to create a stack object that will work with a struct data type called Data, which contains an int and string.
**********************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

/*
 * write all your stack methods here
 */

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {
}

bool Stack::push (int ids, const string* info) {
    bool pushed = false;
    if (top < STACK_SIZE -1) {
        if(ids > 0 && info->size() > 0) {
            Data *data = new Data;
            data->id = ids;
            data->information = *info;
            top++;
            stack[top]= data;
            pushed = true;
        }
    }
    return pushed;
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::pop(Data* data) {
    bool popped = false;
    if(!isEmpty()) {
        data->id = stack[top]->id;
        data->information = stack[top]->information;
        delete stack[top];
        top--;
        popped = true;
    }
    else {
        data->id = -1;
        data->information = "";
        popped=false;
    }
    return popped;
}

bool Stack::peek(Data* data) {
    bool popped = false;
    if(!isEmpty()) {
        data->id = stack[top]->id;
        data->information = stack[top]->information;
        popped = true;
    }
    else {
        data->id = -1;
        data->information = "";
        popped=false;
    }
    return popped;
}
