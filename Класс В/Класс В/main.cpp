//
//  main.cpp
//  Класс В
//
//  Created by Станислав Егоров on 27.02.2024.
//
/*
 Создать класс B

 с полями
 string name
 int age

 Описать три контсруктора:
 параметризированный
 по умолчанию
 получающий на вход только string имя (№3)

 Создать функцию вывода на экран объекта класса B DisplayB(),
 который на вход волучает ссылку на константый объект класса B
 и выводит его на экран в формате "имя: возраст"

 Конструктор описать таким образом чтобы вызов функции
 DisplayB("Bob") не работал.

 Чтобы нельзя было использовать конструктор №3 не преобразовывал объект string в тип B
 */

#include <iostream>
#include <string>

class B {
private:
    std::string name;
    int age;

public:
    // Параметризованный конструктор
    B(const std::string& name, int age) : name(name), age(age) {}

    // Конструктор по умолчанию
    B() : name(""), age(0) {}

    // Конструктор, получающий только имя
    explicit B(const std::string& name) : name(name), age(0) {
        std::cout << "Cannot create object using constructor 3" << std::endl;
    }

    // Функция вывода на экран объекта класса B
    void displayb(const B& obj) const {
        std::cout << "Имя: " << obj.name << ", Возраст: " << obj.age << std::endl;
    }
};

int main() {
    B b1("John", 25);  // Параметризованный конструктор
    b1.displayb(b1);

    B b2;  // Конструктор по умолчанию
    b2.displayb(b2);

    // B b3("Bob");  // Конструктор 3 - вызов недопустим
    return 0;
}
