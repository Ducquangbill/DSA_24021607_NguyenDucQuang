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
         return list.getHead() == nullptr;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.list.printList();
    
    queue.dequeue();
    queue.list.printList();

    return 0;
}