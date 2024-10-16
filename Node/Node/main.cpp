//
//  main.cpp
//  Node
//
//  Created by Станислав Егоров on 28.02.2024.
//

#include <iostream>

class Node {        // <--- узел состоит из
public:
    int value;      // <--- значения
    Node* next;     // <--- и адреса следующего элемента
};

class LinkedList {  // <--- односвязный список состоит из
    Node* head;     // <--  указателя на первый элемент списка и
    Node* tail;     // <--- указателя на последний элемент списка
public:
    LinkedList() : head(nullptr), tail(nullptr) { };    // в конструкторе мы зануляем оба указателя.
    void CreateNode(int value);
    void Print();
};

void LinkedList::Print() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->value << "\n";
        current = current->next;
    }
}

void LinkedList::CreateNode(int value) {
    Node* newNode = new Node; // <--- создаём пустой новый узел
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) // <--- когда нам только что добавили первый элемент
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; // куда указывает tail сейчас
        tail = newNode; // и куда указывается сейчас
    }
}

int main () {
    LinkedList myList;
    
    for (int i = 0; i < 10; i++) {
        char randomChar = 'A' + rand() % 26; // генерация случайной буквы от A до Z
        myList.CreateNode(randomChar);
    }
    
    myList.Print();

    return 0;
}
