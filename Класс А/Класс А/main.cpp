//
//  main.cpp
//  Класс А
//
//  Created by Станислав Егоров on 27.02.2024.
//
/*
 Создать класс A у которого есть поля int, double и string

 Добавить к классу все возможные и необходимые константые методы и
 три метода для изменения полей int, double и string принимающих на вход значения для присвоения.

 В программе создать константый и неконстантый объекты класса A.

 И вызвать все возможные методы для каждого из объектов.
 */
#include <iostream>
#include <string>

class A {
private:
    int intValue;
    double doubleValue;
    std::string stringValue;

public:
    // Конструктор
    A(int intValue, double doubleValue, std::string stringValue)
        : intValue(intValue), doubleValue(doubleValue), stringValue(stringValue) {}

    // Константные методы для получения значений полей
    int getIntValue() const {
        return intValue;
    }

    double getDoubleValue() const {
        return doubleValue;
    }

    std::string getStringValue() const {
        return stringValue;
    }

    // Методы для изменения значений полей
    void setIntValue(int newValue) {
        intValue = newValue;
    }

    void setDoubleValue(double newValue) {
        doubleValue = newValue;
    }

    void setStringValue(std::string newValue) {
        stringValue = newValue;
    }
};

int main() {
    // Создание неконстантного объекта класса A
    A obj1(10, 3.14, "Hello");

    // Вызов методов для неконстантного объекта
    std::cout << "Int value: " << obj1.getIntValue() << std::endl;
    std::cout << "Double value: " << obj1.getDoubleValue() << std::endl;
    std::cout << "String value: " << obj1.getStringValue() << std::endl;

    obj1.setIntValue(20);
    obj1.setDoubleValue(6.28);
    obj1.setStringValue("World");

    std::cout << "Changed int value: " << obj1.getIntValue() << std::endl;
    std::cout << "Changed double value: " << obj1.getDoubleValue() << std::endl;
    std::cout << "Changed string value: " << obj1.getStringValue() << std::endl;

    // Создание константного объекта класса A
    const A obj2(5, 2.71, "Const");

    // Вызов методов для константного объекта
    std::cout << "Int value (const): " << obj2.getIntValue() << std::endl;
    std::cout << "Double value (const): " << obj2.getDoubleValue() << std::endl;
    std::cout << "String value (const): " << obj2.getStringValue() << std::endl;

    // Нельзя вызывать методы для изменения полей константного объекта

    return 0;
}
