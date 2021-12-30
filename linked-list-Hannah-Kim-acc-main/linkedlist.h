/*********************
Name: Che Hyun Kim
Coding 05
Purpose:  A fully functional doubly linked list class and a linked list object are created.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;


class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    
private:
    Node *head;
    bool addMiddle(Node*, int, string*);
    Node* makeNode(int, string*);
};

#endif
