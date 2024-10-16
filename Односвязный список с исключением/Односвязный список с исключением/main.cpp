//
//  main.cpp
//  Односвязный список с исключением
//
//  Created by Станислав Егоров on 25.03.2024.
//
/*
 Опишем класс Односвязный список. При создании сохраняем в него лимит количества элементов. при добавлении элементов выше лимита - выкидываем исключение "Превышен лимит количества элементов", но не прекращаем работу программы.

 У списка есть функции добавить элемент в конец списка, удалить из конца списка, из начала списка, очистить список, проверка полон ли и пуст ли список
 */
#include <iostream>
#include <stdexcept>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    int limit;
    int size;

public:
    LinkedList(int limit) : head(nullptr), limit(limit), size(0) {}

    void addElement(int data) {
        if (size >= limit) {
            throw std::out_of_range("Превышен лимит количества элементов");
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    void removeLastElement() {
        if (size == 0) {
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            size--;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    }

    void removeFirstElement() {
        if (size == 0) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void clear() {
        while (head != nullptr) {
            removeFirstElement();
        }
    }

    bool isFull() const {
        return size >= limit;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    LinkedList list(5);

    try {
        for (int i = 1; i <= 10; i++) {
            list.addElement(i);
            std::cout << "Добавлен элемент " << i << std::endl;
        }
    } catch (std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    while (!list.isEmpty()) {
        list.removeLastElement();
        std::cout << "Удален последний элемент" << std::endl;
    }

    return 0;
}
