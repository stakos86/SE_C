//
//  main.cpp
//  Класс служащий с наследованием
//
//  Created by Станислав Егоров on 13.03.2024.
//
/*
 Создать абстрактный базовый класс Employer (слу-
 жащий) с чисто виртуальной функцией Print() Соз-
 дайте три производных класса: President, Manager,
 Worker Переопределите функцию Print() для вывода
 информации, соответствующей каждому типу слу-
 жащего
 */
#include <iostream>
using namespace std;

// Абстрактный базовый класс Employer
class Employer {
public:
    virtual void print() const = 0; // Чисто виртуальная функция print
};

// Класс President, производный от Employer
class President : public Employer {
public:
    void print() const override {
        cout << "This is the President." << endl;
    }
};

// Класс Manager, производный от Employer
class Manager : public Employer {
public:
    void print() const override {
        cout << "This is a Manager." << endl;
    }
};

// Класс Worker, производный от Employer
class Worker : public Employer {
public:
    void print() const override {
        cout << "This is a Worker." << endl;
    }
};

int main() {
    Employer* emp1 = new President();
    emp1->print();

    Employer* emp2 = new Manager();
    emp2->print();

    Employer* emp3 = new Worker();
    emp3->print();

    return 0;
}
