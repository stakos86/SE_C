//
//  main.cpp
//  Классы. Дробь
//
//  Created by Станислав Егоров on 15.02.2024.
//
/*
 Создайте класс Дробь.

 Поля: числитель, знаменатель.

 Методы:
 - конструктор
 - геттеры/сеттеры
 - GetString(), который возвращает строку "числитель/знаменатель"
 - Print(), который выводить GetString() на экран
 - IsCorrect(), который возвращает true если дробь правильная и false если не правильная
 - Value(), который возвращает действительное число полученное делением числителя на знаменатель.
 */

#include <iostream>
#include <string>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    // Геттеры и сеттеры
    int getNumerator() {
        return numerator;
    }

    void setNumerator(int num) {
        numerator = num;
    }
    
    int getDenominator() {
        return denominator;
    }

    void setDenominator(int denom) {
        denominator = denom;
    }

    // Методы для работы со строками
    std::string getString() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    void print() {
        std::cout << getString() << std::endl;
    }

    // Проверка на правильность дроби
    bool isCorrect() {
        return (numerator >= 0 && denominator >= 0 && numerator < denominator);
    }

    // Получение десятичного значения дроби
    double value() {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    Fraction fraction(3, 4);
    fraction.print();

    std::cout << "Is correct: " << std::boolalpha << fraction.isCorrect() << std::endl;
    std::cout << "Value: " << fraction.value() << std::endl;

    return 0;
}
