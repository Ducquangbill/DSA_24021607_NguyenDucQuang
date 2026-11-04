#include <vector>

using namespace std;

class maxHeap {
    int heap[100];
    int size;

    public:
    int getHeap(int i) {
        return heap[i];
    }

    void swim(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void insert(int value) {
        heap[size] = value;
        size++;
        swim(size - 1);
    }

    void sink(int i) {
        while (i < size) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int largest = i;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i    = largest;
            } else {
                break;
            }
        }
    }

    int extractMax() {
        if (size == 0) return -1;
        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        sink(0);
        return maxValue;
    }
};