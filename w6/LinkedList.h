#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* tail;
    Node(int val) : data(val), next(nullptr), tail(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;

    public:

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    Node* getHead() const {
        return head;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

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
        if (current->next == nullptr) {
            tail = current->next;
        }
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
};