/*********************
Name: Che Hyun Kim
Coding 07
Purpose: This assignment is to create a Binary Search Tree object that will work with the struct Data (contains  int id and string information) and struct Node (contains data *right, *left.)
**********************/


#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"

#include <iostream>
using std::cout; using std::endl;

#include <algorithm>
using std::max;

class BinTree {
public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();
    
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    DataNode *root;
    int count;
    
    //private overloads
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    DataNode* minValueNode(DataNode*);
    
};


#endif /* BINTREE_BINTREE_H */

