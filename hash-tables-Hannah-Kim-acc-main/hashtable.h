/*********************
Name: Che Hyun Kim
Coding 06
Purpose:  To create a Hash Table class/object with struct (a struct with an int id and string data).
**********************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "data.h"

#include <iostream>
using std::endl; using std::cout;

#define HASHTABLESIZE 15

class Hashtable : public LinkedList {
public:
    
    Hashtable();
    ~Hashtable();
    
    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();
    
private:
    
    int hash(int);
    LinkedList *hashtable[HASHTABLESIZE];
    int count;
    
};

#endif //HASHTABLE_H
