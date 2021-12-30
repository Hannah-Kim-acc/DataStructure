/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);
    
    for (int i = 0; i < number_test_cases; i++) {
        delete data[i];
    }
    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    
    
    cout <<endl<< "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;
    
    Data tempData;
    //test peek() and pop() on empty stack
    if(stack.peek(&tempData)){
        cout << "peeked id: "<<tempData.id<<" and data: "<<tempData.information<<endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    if(stack.pop(&tempData)){
        cout << "popped id: "<<tempData.id<<endl<<" and data: "<<tempData.information<<endl;
    } else {
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */
    
    cout << "Testing full operations." << endl;
    cout << "====================================================="<<endl;
    
    
    cout << "Filling stack..." << endl;
    // testing filling the stack and overflow
    string strData;

    int number_multiplied_test_cases =  MULTIPLIER*STACK_SIZE;

    //making test case parallel arrays to hold overflow test data
    int ids_test[number_multiplied_test_cases];
    char *data_test[number_multiplied_test_cases];
    for (int i = 0; i < number_multiplied_test_cases; i++) {
        data_test[i] = new char[BUFFER_SIZE];
    }

    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        ids_test[i] = rand() % MAX_ID + 1;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data_test[i][j] = 'a' + i;
        }
        data_test[i][BUFFER_SIZE - 1] = '\0';
    }

    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        strData = data_test[i];
        if (stack.push(ids_test[i],&strData)) {
            cout << "pushed id: "<<ids_test[i]<<" and data: "<<strData<< endl;
        } else {
            cout << "overflow error: " <<ids_test[i]<<" and "<<strData<< " not pushed" << endl;
        }
    }
    cout << endl;
    
    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;
    
    //testing negative ids and empty string on full stack
    //negative ids only
    int negative_ids;
    string empty_string = "";
    
    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        negative_ids = rand() % MIN_INT + MIN_INT;
        strData = data_test[i];
        if (stack.push(negative_ids,&strData)) {
            cout << "pushed negative id and normal data: "<<endl;
        } else {
            cout << "overflow error: " <<negative_ids<<" and "<<strData<< " not pushed" << endl;
        }
    }
    cout << endl;
    
    //empty string only
    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        if (stack.push(ids_test[i],&empty_string)) {
            cout << "pushed negative id and empty data: "<<endl;
        } else {
            cout << "overflow error: " <<ids_test[i]<<" and (empty string) "<<empty_string<< " not pushed" << endl;
        }
    }
    cout << endl;

    // testing peek() and pop() on full stack
    if(stack.peek(&tempData)){
        cout << "peeked id: "<<tempData.id<<" and data: "<<tempData.information<< endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    if(stack.pop(&tempData)) {
        cout << "popped id: "<<tempData.id<<" and data: "<<tempData.information<< endl;
    } else{
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;
    
    // testing emptying the stack and underflow
    
    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack
    
    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        if(stack.peek(&tempData)){
            cout << "peeked id: "<<tempData.id<<" and data: "<<tempData.information<< endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        if(stack.pop(&tempData)) {
            cout << "popped id: "<<tempData.id<<" and data: "<<tempData.information<< endl;
        } else{
            cout << "pop underflow error: stack is empty" << endl;
        }
    }
    
    cout << endl;
    
    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;
    
    //testing negative ids and empty string on empty stack
    
    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        negative_ids = rand() % MIN_INT + MIN_INT;
        strData = data_test[i];
        if (stack.push(negative_ids,&strData)) {
            cout << "pushed negative id and normal data: "<<endl;
        } else {
            cout << "overflow error: " <<negative_ids<<" and "<<strData<< " not pushed" << endl;
        }
    }
    cout << endl;
    //empty string only
    for (int i = 0; i < MULTIPLIER*STACK_SIZE; i++) {
        if (stack.push(ids_test[i],&empty_string)) {
            cout << "pushed negative id and empty data: "<<endl;
        } else {
            cout << "overflow error: " <<ids_test[i]<<" and (empty string) "<<empty_string<< " not pushed" << endl;
        }
    }
    cout << endl;
    
    //test peek() and pop() on empty stack
    if(stack.peek(&tempData)){
        cout << "peeked id: "<<tempData.id<<" and data: "<<tempData.information<<endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    if(stack.pop(&tempData)){
        cout << "popped id: "<<tempData.id<<endl<<" and data: "<<tempData.information<<endl;
    } else {
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;
    
    //random testing
    
    cout << "Random testing..." << endl;
    // filling the stack half way with random int and string to begin random tests

    for (int i = 0; i <(STACK_SIZE / 2); i++) {
        strData = data_test[i];
        if (stack.push(ids_test[i],&strData)) {
            cout << "pushed id: "<<ids_test[i]<<" and data: "<<strData<< endl;
        } else {
            cout << "overflow error: " <<ids_test[i]<<" and "<<strData<< " not pushed" << endl;
        }
    }
    cout << endl;
    
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_TRIES; i++) {
        switch (choice) {
            case 1:
            case 2:
                // push
                
                ids_test[i] = (rand() % MAX_INT) + 1;
                if (stack.push(ids_test[i],&strData)) {
                    cout << "pushed id: "<<ids_test[i]<<" and data: "<<strData<< endl;
                } else {
                    cout << "overflow error: " <<ids_test[i]<<" and "<<strData<< " not pushed" << endl;
                }
                break;
            case 3:
            case 4:
                // pop
                if(stack.pop(&tempData)){
                    cout << "popped id: "<<tempData.id<<endl<<" and data: "<<tempData.information<<endl;
                } else {
                    cout << "pop underflow error: stack is empty" << endl;
                }
                break;
            case 5:
                // peek
                if(stack.peek(&tempData)){
                    cout << "peeked id: "<<tempData.id<<" and data: "<<tempData.information<<endl;
                } else {
                    cout << "peek underflow error: stack is empty" << endl;
                }

                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;
    }
    cout << endl;
    for (int i = 0; i < number_multiplied_test_cases; i++) {
        delete data_test[i];
    }
    cout << "Testing complete." << endl;
    return 0;
}
