#include <iostream>

using namespace std;

struct List {
    int array[100];
    int size;

    int printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int insertElement(int element, int position) {
        if (position < 0 || position > size || size >= 100) {
            return -1;
        }
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = element;
        size++;
    }

    int deleteElement(int position) {
        if (position < 0 || position >= size) {
            return -1;
        }
        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
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