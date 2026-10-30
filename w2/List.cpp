#include <iostream>

using namespace std;

struct List {
    int arr[100];
    int size;

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void insertElement(int value, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        size++;
    }

    void deleteElement(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};

int main() {
    List list;
    list.size = 0;

    list.insertElement(10, 0);
    list.insertElement(20, 1);
    list.insertElement(30, 2);
    list.printArray();
    list.deleteElement(1);
    list.printArray();
    list.insertElement(40, 1);
    list.printArray();
}