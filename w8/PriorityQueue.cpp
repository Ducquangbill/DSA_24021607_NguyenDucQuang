#include <iostream>
#include "heap.h"

using namespace std;

class PriorityQueue {
    maxHeap heap;

    public:
    void enqueue(int value) {
        heap.insert(value);
    }

    int dequeue() {
        return heap.extractMax();
    }

    bool isEmpty() {
        return heap.getHeap(0) == -1;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(2);
    pq.enqueue(9);
    pq.enqueue(1);
    pq.enqueue(5);
    pq.enqueue(6);

    while (!pq.isEmpty()) {
        cout << pq.dequeue() << " ";
    }
    cout << endl;

    return 0;
}