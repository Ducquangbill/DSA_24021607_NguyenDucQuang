#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
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
    current->next = newNode;
}

void deleteElement(Node*& head, int position) {
    if (head == nullptr) {
        return;
    }
    if (position == 0) {
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

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);

    insertElement(head, 10, 2);
    printList(head);

    deleteElement(head, 3);
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}