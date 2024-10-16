//
//  main.cpp
//  Односвязный список и массив
//
//  Created by Станислав Егоров on 25.03.2024.
//
/*
 Добавьте в классы односвязного списка и массива целых чисел в конструктор булевый параметр, которым можно контролировать, заполнять ли весь массив или список случайными числами при создании массива или нет.

 И пропишите заполнение массива и списка случайными числами на случайн если это параметр установлен как true, по умолчанию он должен быть false.
 */
#include <iostream>
#include <ctime>

struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    bool fillRandomly;

public:
    LinkedList(bool fillRandom = false) : head(nullptr), fillRandomly(fillRandom) {}
    
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


class Array {
private:
    int* arr;
    int size;
    bool fillRandomly;
    
public:
    Array(int arrSize, bool fillRandom = false) : size(arrSize), fillRandomly(fillRandom), arr(new int[arrSize]) {
        if (fillRandomly) {
            srand(time(nullptr));
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100; // диапазон случайных чисел [0, 99]
            }
        }
    }
    
    ~Array() {
        delete[] arr;
    }
    
    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list1(true); // создание списка со случайным заполнением
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list1.printList(); // напечатает случайные числа (если параметр fillRandomly установлен как true)

    LinkedList list2; // создание списка без случайного заполнения
    list2.addNode(4);
    list2.addNode(5);
    list2.addNode(6);
    list2.printList(); // напечатает значения, добавленные вручную

    Array array1(5, true); // создание массива со случайным заполнением
    array1.printArray(); // напечатает случайные числа (если параметр fillRandomly установлен как true)

    Array array2(3); // создание массива без случайного заполнения
    array2.printArray(); // напечатает значения по умолчанию (ноль)

    return 0;
}
