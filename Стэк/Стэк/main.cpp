//
//  main.cpp
//  Стэк
//
//  Created by Станислав Егоров on 27.02.2024.
//

#include <iostream>
#include <vector>

// Шаблон класса Stack
template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Добавление элемента на вершину стека
    void push(const T& item) {
        elements.push_back(item);
    }

    // Удаление элемента с вершины стека
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    // Получение элемента с вершины стека
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    // Проверка, пуст ли стек
    bool empty() const {
        return elements.empty();
    }

    // Получение размера стека
    size_t size() const {
        return elements.size();
    }
};

int main() {
    // Создание стеков для разных типов данных
    Stack<int> intStack;
    Stack<std::string> stringStack;

    // Добавление элементов в стек intStack
    intStack.push(7);
    intStack.push(13);
    std::cout << "Верхний элемент стека intStack: " << intStack.top() << std::endl;

    // Добавление элементов в стек stringStack
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Верхний элемент стека stringStack: " << stringStack.top() << std::endl;

    // Удаление элементов из стеков
    intStack.pop();
    stringStack.pop();

    // Проверка размеров стеков
    std::cout << "Размер стека intStack: " << intStack.size() << std::endl;
    std::cout << "Размер стека stringStack: " << stringStack.size() << std::endl;

    return  0;
}
