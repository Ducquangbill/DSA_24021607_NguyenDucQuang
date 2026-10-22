#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Queue {
    LinkedList list;

    void enqueue(int element) {
        list.insertElement(element, list.size());
    }

    void dequeue() {
        list.deleteElement(0);
    }

    bool isEmpty() {
         return list.head == nullptr;
    }
};