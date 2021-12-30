/*********************
Name: Che Hyun Kim
Coding 03
Purpose: This is a revised program after finding/fixing problems such as bugs and logic errors in a given code.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    Stack s1;
    int num; //for pop() and peek()
    int inputNums[MAX * 2]; //test twice bigger than actual array size
    int sizeInt =(sizeof(inputNums)/sizeof(inputNums[0]));

    //test push
    for (int i = 0; i < sizeInt; i++) {
        bool status = s1.push(i);
        // expect s1.isEmpty() to be falsy
        if (i < MAX && !status) {
            // error
            cout<<"Push() return wrong bool(it should return true)\n";
        }
        
        if (i >= MAX && status) {
            cout<<"Push() return wrong bool(it should return false)\n";// error
        }
    }
    
    // test peek and isEmpty()
    for (int i = (sizeInt - 1); i > -(MAX * 2); i--) {
        bool status = s1.peek(&num);
        if (!s1.isEmpty() && !status) {
            cout<<"peek() return wrong bool when it's not empty";
        }
        if (!status){
            cout<<"peek() return wrong bool(it should return true)\n";
        }
        if (num != MAX-1) {
            cout<<"peek() return wrong int\n";
        }
        if (s1.isEmpty()) {
            cout<<"isEmpty() return wrong bool(it should return false)\n";
        }
    }

    // test pop and isEmpty()
    for (int i = (sizeInt) - 1; i > -(MAX * 2); i--) {
        bool status = s1.pop(&num);
        if ((i <= MAX-1) && status) {
            cout<<"pop() return wrong bool(it should return false)\n";
        }
        if (i >= MAX ) {
            if (!status) {
                cout<<"pop() return wrong bool(it should return true)\n";
            }
            if (num != i - MAX) {
                cout<<"pop() return wrong int\n";
            }
        }
        if (i <= MAX && !s1.isEmpty()) {
            cout<<"isEmpty() return wrong bool(it should return true)\n";
        }

        if (i > MAX && s1.isEmpty()) {
            cout<<"isEmpty() return wrong bool(it should return false)\n";
        }
    }
    
    return 0;
}
