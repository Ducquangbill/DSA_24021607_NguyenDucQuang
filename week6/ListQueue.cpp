#include <iostream>
#include <List.h>

using namespace std;

struct Queue {
    List list;

    void enqueue(int element) {
        list.insertElement(element, list.size);
    }

    void dequeue() {
        list.deleteElement(0);
    }

    bool isEmpty() {
         return list.size == 0;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.list.printArray();
    
    queue.dequeue();
    queue.list.printArray();

    return 0;
}