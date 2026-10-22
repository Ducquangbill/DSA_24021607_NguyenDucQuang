#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

struct doublyLinkedList {
    Node* head;
    doublyLinkedList() : head(nullptr) {}

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insertElement(int element, int position) {
        Node* newNode = new Node(element);
        if (position == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            delete newNode;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void deleteElement(int position) {
        if (position == 0 && head != nullptr) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }
};

int main() {
    doublyLinkedList list;
    list.insertElement(10, 0);
    list.insertElement(20, 1);
    list.insertElement(30, 2);
    list.printList();
    list.deleteElement(1);
    list.printList();
    list.insertElement(40, 1);
    list.printList();

    while (list.head != nullptr) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }
    
    return 0;
}