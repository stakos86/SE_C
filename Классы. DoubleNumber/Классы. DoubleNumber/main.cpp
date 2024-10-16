//
//  main.cpp
//  Классы. DoubleNumber
//
//  Created by Станислав Егоров on 16.02.2024.
//
/*
 Создать класс DoubleNumber, который хранит действительное число.

 Описать для него
 конструкторы параметризированный и по умолчанию,
 геттер,
 сеттер,
 перегрузить для него +, -, * и /
 вывод на экран (Print)

 В main() создать два объекта и инициализировать их
 Создать третий и в него записывать значения арифметических операций с первыми двумя.
 */

#include <iostream>

class DoubleNumber {
private:
    double number;
public:
    // Параметризированный конструктор
    DoubleNumber(double num) {
        number = num;
    }

    // Конструктор по умолчанию
    DoubleNumber() {
        number = 0.0;
    }

    // Геттер
    double getNumber() {
        return number;
    }

    // Сеттер
    void setNumber(double num) {
        number = num;
    }

    // Перегрузка оператора +
    DoubleNumber operator+(const DoubleNumber& other) {
        DoubleNumber result;
        result.number = number + other.number;
        return result;
    }

    // Перегрузка оператора -
    DoubleNumber operator-(const DoubleNumber& other) {
        DoubleNumber result;
        result.number = number - other.number;
        return result;
    }

    // Перегрузка оператора *
    DoubleNumber operator*(const DoubleNumber& other) {
        DoubleNumber result;
        result.number = number * other.number;
        return result;
    }

    // Перегрузка оператора /
    DoubleNumber operator/(const DoubleNumber& other) {
        if (other.number != 0) {
            DoubleNumber result;
            result.number = number / other.number;
            return result;
        } else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return *this;
        }
    }

    // Вывод на экран
    void print() {
        std::cout << "Число: " << number << std::endl;
    }
};

int main() {
    // Создание двух объектов и инициализация их
    DoubleNumber num1(5.5);
    DoubleNumber num2(2.0);

    // Создание третьего объекта и запись значения арифметических операций с первыми двумя
    DoubleNumber num3;
    num3 = num1 + num2;

    // Вывод результатов
    num1.print();
    num2.print();
    num3.print();

    return 0;
}
