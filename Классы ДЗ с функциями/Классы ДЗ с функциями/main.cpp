//
//  main.cpp
//  Классы ДЗ с функциями
//
//  Created by Станислав Егоров on 14.02.2024.
//
/*
 Создать класс Printer, который имеет
 1. функцию печати int переменной
 2. функцию печати дробного числа с указанием количества знаков после запятой
 3. функцию печати строковой переменной
 */

#include <iostream>
#include <string>
#include <iomanip>

class Printer {
public:
    void printint(int value) {
        std::cout << value << std::endl;
    }

    void printdouble(double value, int precision) {
        std::cout << std::fixed << std::setprecision(precision) << value << std::endl;
    }

    void printstring(const std::string& value) {
        std::cout << value << std::endl;
    }
};

int main() {
    
    Printer printer;
    printer.printint(100500);
    printer.printdouble(49.500000000, 8);
    printer.printstring("pikabu.dies");

    return 0;
}
