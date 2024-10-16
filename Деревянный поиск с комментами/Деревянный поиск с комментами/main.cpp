//
//  main.cpp
//  Деревянный поиск с комментами
//
//  Created by Станислав Егоров on 04.03.2024.
//

#include <stdlib.h> // подключение библиотеки стандартных функций
#include <iostream> // подключение библиотеки для ввода-вывода

using namespace std; // использование пространства имен std

struct node { // объявление структуры узла
    int data; // данные узла
    node* left; // указатель на левый дочерний узел
    node* right; // указатель на правый дочерний узел
};

class binarysearchtree { // объявление класса бинарного дерева поиска
    node* root; // указатель на корень дерева
public:
    void addelement(int element) { // метод добавления элемента в дерево
        root = insert(root, element); // вызов функции вставки элемента
    }
};

// создание нового узла
node* addnode(int data) {
    node* result = new node; // выделение памяти под новый узел

    result->data = data; // присвоение значения узлу

    result->left = nullptr; // указатель на левый дочерний узел
    result->right = nullptr; // указатель на правый дочерний узел

    return result; // возвращение созданного узла
}

// обход дерева в прямом порядке
void traversepreorder(node* temp) {
    if (temp != nullptr) // если узел не пустой
    {
        cout << " " << temp->data; // вывод значения узла
        traversepreorder(temp->left); // рекурсивный вызов для левого дочернего узла
        traversepreorder(temp->right); // рекурсивный вызов для правого дочернего узла
    }
}

// обход дерева в порядке возрастания
void traverseinorder(node* temp) {
    if (temp != nullptr) // если узел не пустой
    {
        cout << " " << temp->data; // вывод значения узла
        traverseinorder(temp->left); // рекурсивный вызов для левого дочернего узла
        traverseinorder(temp->right); // рекурсивный вызов для правого дочернего узла
    }
}

// обход дерева в обратном порядке
void traversepostorder(node* temp) {
    if (temp != nullptr) // если узел не пустой
    {
        cout << " " << temp->data; // вывод значения узла
        traversepostorder(temp->left); // рекурсивный вызов для левого дочернего узла
        traversepostorder(temp->right); // рекурсивный вызов для правого дочернего узла
    }
}

// вставка узла
node* insert(struct node* node, int key) {
    if (node == nullptr) return addnode(key); // если дерево пустое, создать новый узел

    if (key < node->data) // если ключ меньше значения текущего узла
        node->left = insert(node->left, key); // рекурсивный вызов для левого дочернего узла
    else
        node->right = insert(node->right, key); // рекурсивный вызов для правого дочернего узла

    return node;
}

// поиск наименьшего значения в дереве
node* minvaluenode(node* node) {
    node* current = node; // присвоение значения текущему узлу

    while (current && current->left != nullptr) // пока текущий узел и его левый дочерний узел не пустые
        current = current->left; // переход к левому дочернему узлу

    return current; // возвращение наименьшего узла
}

// поиск элемента в дереве
node* findelement(node* node, int data) {
    if (node == nullptr) return nullptr; // если дерево пустое, вернуть нулевой указатель
    if (node->data == data) return node; // если значение узла равно искомому значению, вернуть указатель на этот узел

    if (data < node->data)
        return findelement(node->left, data); // рекурсивный вызов для левого дочернего узла

    return findelement(node->right, data); // рекурсивный вызов для правого дочернего узла
}


int main() {
    node* root = nullptr; // объявление корня дерева и инициализация его значением null
    root = insert(root, 8); // вставка нового узла в дерево
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 11);
    root = insert(root, 9); // последовательное добавление элементов в дерево

    node* three = findelement(root, 3); // поиск узла со значением 3 в дереве
    if (three == nullptr) // если узел не найден
    {
        std::cout << "\nelement 3 is not found\n"; // вывод сообщения об отсутствии элемента
    }
    else {
        std::cout << "\nelement 3 is at " << three << "\n"; // вывод информации о местоположении узла
    }
}
