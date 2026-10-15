#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertElement(Node*& head, int element, int position) {
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

void deleteElement(Node*& head, int position) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    if (position == 0) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete current;
        return;
    }
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

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    printList(head);

    insertElement(head, 3, 1);
    printList(head);

    deleteElement(head, 1);
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}