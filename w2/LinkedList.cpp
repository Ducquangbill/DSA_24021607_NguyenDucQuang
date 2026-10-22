#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* tail;
    Node(int val) : data(val), next(nullptr), tail(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    

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
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
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
        current->next = newNode;
    }

    void deleteElement(int position) {
        if (position == 0 && head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertElement(10, 0);
    list.insertElement(20, 1);
    list.insertElement(30, 2);
    list.printList();
    list.deleteElement(1);
    list.printList();

    while (list.head != nullptr) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }

    return 0;
}