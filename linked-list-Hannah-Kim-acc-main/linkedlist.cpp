/*********************
Name: Che Hyun Kim
Coding 05
Purpose:  A fully functional doubly linked list class and a linked list object are created.
**********************/
#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addMiddle(Node* current, int ids, string *info) {
    Node *node = new Node;
    node -> data.id = ids;
    node -> data.data = *info;

    node -> next = current;
    node -> prev = current -> prev;
    current -> prev -> next = node;
    current->prev = node;
    
    return true;
}

Node* LinkedList::makeNode(int ids, string *info){
    
    Node *node = new Node;
    node -> data.id = ids;
    node -> data.data = *info;
    
    return node;
}

bool LinkedList::addNode(int ids, string *info){
    bool added = false;

    if (ids>0 && *info !=""){
        Node *current = head;
        if (head == NULL ) {
            //add node when list is empty
            Node *node = makeNode(ids, info);

            node -> prev = NULL;
            node -> next = NULL;
            head = node;
            
            added = true;
        }
        else if(ids < current->data.id){
            //add new head
            Node *node = makeNode(ids, info);

            head->prev = node;
            node->next = head;
            node->prev = NULL;
            head = node;
            
            added = true;
        }
        current = head;
        while ((current->next != NULL) && !added) {
            if (ids > current->data.id) {
                current = current -> next;
            }
            else if (ids != current -> data.id){
                //add general
                added = addMiddle(current, ids, info);
            }
            else if(ids == current->data.id) {break;}
        }
        //add general, second from the last
        if (current ->next == NULL && ids != current -> data.id && ids < current->data.id ) {
            //add general, second from the last
            added = addMiddle(current, ids, info);
        }
        else if (ids != current -> data.id && current ->next == NULL ) {
            //add tail
            Node *node = makeNode(ids, info);
            
            node->next = NULL;
            node->prev = current;
            current->next = node;
            
            added = true;
        }
    }
    return added;
}

bool LinkedList::deleteNode(int ids){
    bool deleted = false;
    Node *current = head;
   if (ids>0 && current !=NULL ){
        Node *current = head;
        if (ids == current ->data.id) {
            if (current -> next == NULL) {
                current = NULL;
                head = NULL;
                delete current;
                deleted = true;
            }
            else {
                current -> next -> prev = NULL;
                head = current -> next;
                delete current;
                deleted = true;
            }
        }
        else {
            while ((current->next != NULL) && !deleted){
            if (current->data.id == ids) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                deleted = true;
            }
            current = current ->next;
            }
            if (ids == current -> data.id) {
                current -> prev -> next = NULL;
                delete current;
                deleted = true;
            }
        }
    }
    return deleted;
}

bool LinkedList::getNode(int ids, Data* tempData){
    bool gotData =false;
    Node *current = head;
    while (!gotData && current) {
        if (ids == current-> data.id) {
            tempData->id = current->data.id;
            tempData->data = current -> data.data;
            gotData = true;
        }
        current = current -> next;
    }
    return gotData;
}

void LinkedList::printList(bool backward){
    Node *current = head;
    if (!backward) {
        if (current == NULL ) {
            cout<<"\tList is empty"<<endl;
        }
        while(current){
            cout << "\t"<<current->data.id << ": " << current->data.data << endl;
            current = current->next;
        }
    }
    else {
        current = head;
        bool tail = false;
        while(current && !tail){
            if (current->next){
                current = current->next;
            }
            else {
                tail = true;
            }
        }
        while(current){
            cout << "\t"<<current->data.id << ": " << current->data.data << endl;
            current = current->prev;
        }
    }
}
int LinkedList::getCount(){
    int count = 0;
    Node *current = head;
    while(current){
        count ++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList(){
    bool cleared = false;
    Node *current = head;

    while (current) {
        deleteNode(current->data.id);
        current = current -> next;
    }
    return cleared;
}
bool LinkedList::exists(int ids){
    bool gotData =false;
    Node *current = head;
    while (!gotData && current) {
        if (ids == current-> data.id) {
            gotData = true;
        }
        current = current -> next;
    }
    return gotData;
}

