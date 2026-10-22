#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Stack {
    LinkedList list;

    void push(int element) {
        list.insertElement(element, 0);
    }

    void pop() {
        list.deleteElement(0);
    }

    bool isEmpty() {
         return list.head == nullptr;
    }
};

