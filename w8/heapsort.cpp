#include <iostream>
#include "heap.h"

using namespace std;

void heapSort(vector<int>& arr) {
    maxHeap heap;
    for (int value : arr) {
        heap.insert(value);
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = heap.getHeap(0);
        heap.extractMax();
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    heapSort(arr);

    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}