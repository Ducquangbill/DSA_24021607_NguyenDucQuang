#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}

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
            if (this != nullptr) {
                this->prev = newNode;
            }
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
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        return 0;
    }

    int deleteElement(int position) {
        if (position == 0) {
            Node* temp = this;
            if (this->next != nullptr) {
                this->next->prev = nullptr;
            }
            delete temp;
            return 0;
        }
        Node* current = this;
        for (int i = 0; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            return -1;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        return 0;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;


    head->printList();
    head->insertElement(3, 1);
    head->printList();
    head->deleteElement(1);
    head->printList();
    
    return 0;
}