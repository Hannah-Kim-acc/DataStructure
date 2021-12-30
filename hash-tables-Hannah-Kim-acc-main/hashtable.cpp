/*********************
Name: Che Hyun Kim
Coding 06
Purpose:  To create a Hash Table class/object with struct (a struct with an int id and string data).
**********************/

#include "hashtable.h"

//private

int Hashtable::hash(int id) {
    return id % HASHTABLESIZE;
}

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = nullptr;
    }
}

Hashtable::~Hashtable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        delete hashtable[i];
    }
}

bool Hashtable::insertEntry(int id, string* info) {
    bool inserted = false;
    int position = hash(id);
    
    if (hashtable[position] == nullptr) {
        hashtable[position] = new LinkedList;
        inserted = hashtable[position]->addNode(id, info);
        if (inserted){
            count++;
        }
    }
    else {
        inserted =hashtable[position]->addNode(id, info);
        if (inserted){
            count++;
        }
    }
    return inserted;
}

string Hashtable::getData(int id) {
    int position = hash(id);
    string data;
    Data tempData;
    if (hashtable[position]!= nullptr && hashtable[position]->getNode(id,&tempData)) {
        data = tempData.data;
    }
    else {
        data = "";
    }
    
    return data;
}

bool Hashtable::removeEntry(int id) {
    bool removed = false;
    int position = hash(id);
    removed = hashtable[position]->deleteNode(id);
    if (removed) {
        count--;
    }
    return removed;
}

int Hashtable::getCount() {
    return count;
}

void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE ; i ++) {
        cout<<"Entry"<<i+1<<": ";
        if (hashtable[i]) {
            hashtable[i]->printList();
        }else {cout<<"EMPTY";}
        cout<<endl;
    }
}

