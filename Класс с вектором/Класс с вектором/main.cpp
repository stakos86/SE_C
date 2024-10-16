//
//  main.cpp
//  Класс с вектором
//
//  Created by Станислав Егоров on 27.02.2024.
//
/*
 
 Описать шаблон класса, который хранит вектор объектов.

 Описать в классе функцию, которая проверяет есть ли в векторе какой-то элемент, может его удалить, и может добавить элемент по номеру места в массиве. (вставить этот элемент на позицию 5)
 */
#include <vector>
#include <iostream>

template<typename T>
class VectorContainer {
private:
    std::vector<T> vec;

public:
    void addElement(const T& element) {
        vec.push_back(element);
    }

    bool containsElement(const T& element) {
        for (const auto& obj : vec) {
            if (obj == element) {
                return true;
            }
        }
        return false;
    }

    void removeElement(const T& element) {
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (*it == element) {
                vec.erase(it);
                break;
            }
        }
    }

    void insertElement(const T& element, const int pos) {
        vec.insert(vec.begin() + pos, element);
    }

    void printVector() {
        for (const auto& obj : vec) {
            std::cout << obj << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    VectorContainer<int> container;

    // Добавляем элементы в вектор
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);

    // Проверяем наличие элементов
    std::cout << "Vector contains 2: " << (container.containsElement(2) ? "yes" : "no") << std::endl;
    std::cout << "Vector contains 5: " << (container.containsElement(5) ? "yes" : "no") << std::endl;

    // Удаляем элемент
    container.removeElement(3);

    // Добавляем элемент на позицию 5
    container.insertElement(5, 2);

    // Выводим содержимое вектора
    container.printVector();

    return 0;
}
