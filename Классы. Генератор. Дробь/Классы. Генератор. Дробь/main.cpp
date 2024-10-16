//
//  main.cpp
//  Классы. Генератор. Дробь
//
//  Created by Станислав Егоров on 15.02.2024.
//
/*
 Создайте функцию Генератор объектов класса дробь.

 Она ничего не принимает на вход, но генерирует случайную Дробь и возвращает ссылку на неё.
 */

#include <iostream>
#include <random>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {}

    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    double getValue() {
        return static_cast<double>(numerator) / denominator;
    }
};

Fraction& generateFraction() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numDist(1, 10); // случайное числитель от 1 до 10
    std::uniform_int_distribution<> denDist(1, 10); // случайный знаменатель от 1 до 10

    int num = numDist(gen);
    int den = denDist(gen);

    Fraction* fraction = new Fraction(num, den);
    return *fraction;
}
