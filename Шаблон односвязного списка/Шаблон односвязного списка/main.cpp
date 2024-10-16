//
//  main.cpp
//  Шаблон односвязного списка
//
//  Created by Станислав Егоров on 28.02.2024.
//

#include <iostream>

template<typename T>
class Node {
public:
    T value;
    Node<T>* next;

    Node(T val) {
        value = val;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void createNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    void print() {
        Node<T>* curr = head;

        while (curr != nullptr) {
            std::cout << curr->value << "\n";
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList<int> list1;
    list1.createNode(5);
    list1.createNode(10);
    list1.createNode(15);
    list1.print();

    LinkedList<char> list2;
    list2.createNode('*');
    list2.createNode('&');
    list2.createNode('^');
    list2.print();

    return 0;
}
