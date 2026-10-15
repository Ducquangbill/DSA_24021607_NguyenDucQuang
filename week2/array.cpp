#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int element, int position) {
    if (position < 0 || position > size) {
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;

    printArray(array, size);

    insertElement(array, size, 10, 2);
    printArray(array, size);

    deleteElement(array, size, 3);
    printArray(array, size);
}