#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = createNode(data);
        if (!newNode) return;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void prepend(int data) {
        Node* newNode = createNode(data);
        if (!newNode) return;

        newNode->next = head;
        head = newNode;
    }

    void insertAt(int index, int data) {
        if (index < 0) {
            std::cout << "Invalid index\n";
            return;
        }
        if (index == 0) {
            prepend(data);
            return;
        }

        Node* newNode = createNode(data);
        if (!newNode) return;

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Index out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int getAt(int index) {
        if (index < 0) {
            std::cout << "Invalid index\n";
            return -1;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Index out of bounds\n";
            return -1;
        }
        return temp->data;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.prepend(5);
    list.insertAt(1, 15);

    list.printList();

    std::cout << "Item at index 2: " << list.getAt(2) << "\n";

    std::cout << "Length: " << list.length() << "\n";

    return 0;
}
