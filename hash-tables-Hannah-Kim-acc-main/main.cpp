/*********************
Name: Che Hyun Kim
Coding 06
Purpose:  To create a Hash Table class/object with struct (a struct with an int id and string data).
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    
    cout <<endl<< "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl<< endl;

    // create your hash table object here
    cout << "creating the hashtable...";
    Hashtable hashtable;
    cout << "done" << endl << endl;

    // show it is empty by calling getCount and printTable
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl<<endl;
    
    cout << "Testing insert operations." << endl;
    cout << "====================================================="<<endl;
    cout << endl;
    
    /*
     * Insert all data to hash table
     */
    
    // try and put ALL the test data into the table and show what happens
    
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.insertEntry(ids[i], &strs[i])){
            cout << "success. "<< ids[i]<<" entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl<<endl;
        } else {
            cout << "failed. input id "<<ids[i]<<" is likely invalid." << endl<<endl;
        }
    }
    cout << endl;
    
    cout << "Retrieving Test Data one at a time..." << endl;
    string temp = "";
    for (int i = 0; i < testdatasize; i++) {
        temp = hashtable.getData(ids[i]);
        
        if (temp != "") {
            cout << "success: " << ids[i] << ": " << temp << endl;
        } else {
            cout << "failed: " << ids[i] << " is not in the table." << endl;
        }
    }
    cout << endl;
    
    cout << "Hash Table Traversal..." << endl;
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl;

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
    cout << "Testing remove operations." << endl;
    cout << "====================================================="<<endl<<endl;
    /*
     * Remove the first, middle
     * test data ids and one non-existent id
     */
    cout << "Deleting Test Data..." << endl;

    cout << "Trying: " << ids[0] << "..." << endl;

    if (hashtable.removeEntry(ids[0])) {
        cout << "  success. "<< ids[0]<<" entry removed." << endl<<endl;
    } else {
        cout << "  failed. input id "<<ids[0]<<" is likely invalid." << endl<<endl;
    }

    cout << "Trying: " << ids[(int) (testdatasize - 1) / 2] << "..." << endl;

    if (hashtable.removeEntry(ids[(int) (testdatasize - 1) / 2])) {
        cout << "  success. "<< ids[(int) (testdatasize - 1) / 2]<<" entry removed." << endl<<endl;
    } else {
        cout << "  failed. input id "<<ids[(int) (testdatasize - 1) / 2]<<" is likely invalid." << endl<<endl;
    }
    
    cout << "Trying: " << ids[testdatasize - 1] << "..." << endl;
    if (hashtable.removeEntry(ids[testdatasize - 1] )) {
        cout << "  Success: " << ids[testdatasize - 1] << " removed" << endl<<endl;
    } else {
        cout << "  Failed " << ids[testdatasize - 1] << " was not removed" << endl<<endl;
    }
      //remove the whole data
      
      for (int i = 0; i < testdatasize; i++) {
          if (hashtable.removeEntry(ids[i])) {
              cout << "success. "<< ids[i]<<" entry removed." << endl;
              cout << "There are " << hashtable.getCount() << " entries in the table." << endl<<endl;
          } else {
              cout << "failed. input id "<<ids[i]<<" is likely invalid." << endl<<endl;
          }
      }
      cout << endl;
      
      cout << "Hash Table Traversal..." << endl;
      cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
      hashtable.printTable();
      cout << endl;

      cout << "Testing complete." << endl;
    
    return 0;
}
