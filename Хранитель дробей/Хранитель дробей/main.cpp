//
//  main.cpp
//  Хранитель дробей
//
//  Created by Станислав Егоров on 15.02.2024.
//
/*
 Создайте класс Хранитель дробей.

 Поля: массив ссылок на объекты класса Дробь. (можно вектор)

 Методы:
 - GetFractionByIndex(int index), которых возвращает дробь по номеру index
 - MaxFraction(), возвращает наибольшую дробь
 - MinFraction(), возвращает наименьшую дробь
 - GetAllCorrectFractions() - выводит на экран все правильные дроби
 - GetAllNotCorrectFractions() - выводит на экоран все не правильные дроби
 - GetAllFractionsLessThan(double value) - выводит на экран все дроби меньше, чем value
 - GetAllFractionsMoreThan(double value) - выводит на экран все дроби больше, чем value
 */

#include <iostream>
#include <vector>
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

class FractionHolder {
private:
    std::vector<Fraction*> fractions;

public:
    ~FractionHolder() {
        for (Fraction* fraction : fractions) {
            delete fraction;
        }
    }

    void addFraction(Fraction& fraction) {
        fractions.push_back(&fraction);
    }

    Fraction& getFractionByIndex(int index) {
        return *fractions[index];
    }

    Fraction& maxFraction() {
        Fraction* max = fractions[0];
        for (Fraction* fraction : fractions) {
            if (fraction->getValue() > max->getValue()) {
                max = fraction;
            }
        }
        return *max;
    }

    Fraction& minFraction() {
        Fraction* min = fractions[0];
        for (Fraction* fraction : fractions) {
            if (fraction->getValue() < min->getValue()) {
                min = fraction;
            }
        }
        return *min;
    }

    void getAllCorrectFractions() {
        for (Fraction* fraction : fractions) {
            if (fraction->getNumerator() < fraction->getDenominator()) {
                fraction->print();
            }
        }
    }

    void getAllNotCorrectFractions() {
        for (Fraction* fraction : fractions) {
            if (fraction->getNumerator() >= fraction->getDenominator()) {
                fraction->print();
            }
        }
    }

    void getAllFractionsLessThan(double value) {
        for (Fraction* fraction : fractions) {
            if (fraction->getValue() < value) {
                fraction->print();
            }
        }
    }

    void getAllFractionsMoreThan(double value) {
        for (Fraction* fraction : fractions) {
            if (fraction->getValue() > value) {
                fraction->print();
            }
        }
    }
};
