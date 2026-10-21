#include <iostream>
#include "List.h"

using namespace std;

struct Stack {
    List list;

    void push(int element) {
        list.insertElement(element, 0);
    }

    void pop() {
        list.deleteElement(0);
    }

    bool isEmpty() {
         return list.size == 0;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.list.printArray();

    stack.pop();
    stack.list.printArray();

    return 0;
}