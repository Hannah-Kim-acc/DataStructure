/*********************
Name: Che Hyun Kim
Coding 06
Purpose:  To create a Hash Table class/object with struct (a struct with an int id and string data).
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
