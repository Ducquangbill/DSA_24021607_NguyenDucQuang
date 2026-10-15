#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}

    int printList() {
        Node* current = this;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int insertElement(int element, int position) {
        Node* newNode = new Node(element);
        if (position == 0) {
            newNode->next = this;
            return 0;
        }
        Node* current = this;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            delete newNode;
            return -1;
        }
        newNode->next = current->next;
        current->next = newNode;
        return 0;
    }

    int deleteElement(int position) {
        if (position == 0) {
            Node* temp = this;
            delete temp;
            return 0;
        }
        Node* current = this;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            return -1;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return 0;
    }
};

int main() {
    Node* head = new Node(10);
    head->insertElement(20, 1);
    head->printList();
    head->insertElement(30, 2);
    head->printList();
    head->deleteElement(1);
    head->printList();

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}