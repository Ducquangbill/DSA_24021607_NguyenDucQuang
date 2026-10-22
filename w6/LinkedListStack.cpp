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

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.list.printList();
    
    stack.pop();
    stack.list.printList();

    return 0;
}