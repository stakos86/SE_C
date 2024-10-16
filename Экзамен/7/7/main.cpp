//
//  main.cpp
//  7
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>
#include <vector>

// Базовый класс Batya
class Batya {
public:
    virtual void Do() {
        std::cout << "Do like Batya" << std::endl;
    }
};

// Класс Son, наследник Batya
class Son : public Batya {
public:
    void Do() override {
        std::cout << "Do like Son" << std::endl;
    }
};

int main() {
    // Создание вектора указателей на базовый класс Batya
    std::vector<Batya*> vec;

    // Заполнение вектора объектами Batya и Son в зависимости от четности индекса
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            vec.push_back(new Batya());
        } else {
            vec.push_back(new Son());
        }
    }

    // Вызов метода Do() для каждого объекта в векторе
    for (auto& obj : vec) {
        obj->Do();
    }

    // Освобождение памяти
    for (auto& obj : vec) {
        delete obj;
    }

    return 0;
}
