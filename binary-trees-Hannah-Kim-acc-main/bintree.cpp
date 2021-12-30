/*********************
Name: Che Hyun Kim
Coding 07
Purpose: This assignment is to create a Binary Search Tree object that will work with the struct Data (contains  int id and string information) and struct Node (contains data *right, *left.)
**********************/


#include "bintree.h"


BinTree::BinTree() {
    root = NULL;
    count = 0;
}

BinTree::~BinTree() {
    clear();
}

bool BinTree::isEmpty() {
    return root == NULL;
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data* node) {

    bool gotData = false;
    if (!isEmpty()) {
        node->id = root->data.id;
        node->information = root->data.information;
        gotData = true;
    } else {
        node->id = -1;
        node->information = "";
    }
    return gotData;
}

void BinTree::displayTree() {
    
    cout<<"DISPLAY TREE"<<endl;
    cout << "==============================================" << endl;
    if (isEmpty()){
        cout<<"Tree is empty"<<endl;
    } else {
        cout<<"Tree is NOT empty"<<endl;
    }
    cout<<"height "<<getHeight()<<endl<<"Node count: "<<count<<endl;
    
    cout<<endl<<"Pre-Order Traversal"<<endl;
    displayPreOrder();
    
    cout<<endl<<"In-Order Traversal"<<endl;
    displayInOrder();
    
    cout<<endl<<"Post-Order Traversal"<<endl;
    displayPostOrder();
    cout << "==============================================" << endl;
}

void BinTree::clear() {
    clear(root);
    root = NULL;
}

bool BinTree::addNode(int id, const string* info) {
    
    bool added = false;
    if (id > 0 && *info != "") {
        DataNode* node = new DataNode;
        node->data.id = id;
        node->data.information = *info;
        added = addNode(node, &root);
        if (added) {
            count ++;
        }
    }
    return added;
}

bool BinTree::removeNode(int id) {
    int tempcount = count;
    root = removeNode(id, root);
    
    return count < tempcount;
}


bool BinTree::getNode(Data* node, int id) {
    
    bool gotNode = false;
    if (id > 0) {
        gotNode = getNode(node, id, root);
    }
    return gotNode;
}


bool BinTree::contains(int id) {
    
    bool contained = false;
    if (id > 0) {
        contained = contains(id, root);
    }
    return contained;
}

int BinTree::getHeight() {
    return getHeight(root);
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}
void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}

//private overloads

void BinTree::clear(DataNode* temproot) {
    if(temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
//        delete temproot; if I use delete it creates a memory problem and I don't know why
        count--;
    }
}

bool BinTree::addNode(DataNode* node, DataNode** temproot) {
    bool added = false;
    if ((*temproot)){
        if (node->data.id < (*temproot)->data.id) {
            added = addNode(node, &(*temproot)->left);
        } else if (node->data.id >(*temproot)->data.id) {
            added = addNode(node, &(*temproot)->right);
        }
    } else {
        *temproot = node;
        added = true;
    }
    return added;
}


DataNode* BinTree::removeNode(int id, DataNode* temproot) {
    if (temproot) {
        if (id < temproot->data.id) {
            temproot->left = removeNode(id, temproot->left);
        } else if (id > temproot->data.id) {
            temproot->right = removeNode(id, temproot->right);
        } else {
            DataNode *temp = new DataNode;
            if (temproot->left == NULL) {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            } else if (temproot->right == NULL) {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            } else {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

bool BinTree::getNode(Data* node, int id, DataNode* temproot) {
    
    bool gotNode = false;
    if (temproot) {
        if (id == temproot->data.id) {
            node->id = temproot->data.id;
            node->information = temproot->data.information;
            gotNode = true;
        } else if (id < temproot->data.id) {
            gotNode = getNode(node, id, temproot->left);
        } else {
            gotNode = getNode(node, id, temproot->right);
        }
    }
    return gotNode;
}

bool BinTree::contains(int id, DataNode* temproot) {
    
    bool contained = false;
    if (temproot) {
        if (id == temproot->data.id) {
            contained = true;
        } else if (id < temproot->data.id) {
            contained = contains(id, temproot->left);
        } else {
            contained = contains(id, temproot->right);
        }
    }
    return contained;
}

int BinTree::getHeight(DataNode* temproot) {
    
    int lh = 0;
    int rh = 0;
    int height = 0;
    if (temproot) {
        if (temproot->left) {
            lh = getHeight(temproot->left);
        }
        if (temproot->right) {
            rh = getHeight(temproot->right);
        }
        
        height = max(lh, rh) + 1;
    }
    return height;
}



void BinTree::displayPreOrder(DataNode* temproot) {
    
    if (temproot) {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayPostOrder(DataNode* temproot) {
    
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
    return;
}

void BinTree::displayInOrder(DataNode *temproot) {
    
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
    return;
}


