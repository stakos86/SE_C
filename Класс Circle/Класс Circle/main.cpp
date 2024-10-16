//
//  main.cpp
//  Класс Circle
//
//  Created by Станислав Егоров on 27.02.2024.
//
/*
 Создайте класс Circle (окружность):
 ■ Реализуйте через перегруженные операторы;
 ■ Проверка на равенство радиусов двух окружностей (
 операция = =);
 ■ Сравнения длин двух окружностей (операция >).
 Пропорциональное изменение размеров окружности, путем
 изменения ее радиуса (операция += и -=)
 */
#include <iostream>

class Circle {

public:
    double radius;
    
    Circle(double r) : radius(r) {}

    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    bool operator>(const Circle& other) const {
        return 2 * 3.14159 * radius > 2 * 3.14159 * other.radius;
    }

    Circle& operator+=(double increment) {
        radius += increment;
        return *this;
    }

    Circle& operator-=(double decrement) {
        radius -= decrement;
        return *this;
    }
};

int main() {
    Circle c1(5.0);
    Circle c2(7.0);

    if (c1 == c2) {
        std::cout << "Радиусы одинаковые" << std::endl;
    } else {
        std::cout << "Радиусы разные" << std::endl;
    }

    if (c1 > c2) {
        std::cout << "Длина первой окружности больше" << std::endl;
    } else {
        std::cout << "Длина второй окружности больше" << std::endl;
    }

    c1 += 2.0;
    std::cout << "Новый радиус c1: " << c1.radius << std::endl;

    c2 -= 1.5;
    std::cout << "Новый радиус c2: " << c2.radius << std::endl;

    return 0;
}
