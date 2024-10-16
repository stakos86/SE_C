//
//  main.cpp
//  Функция степень числа
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для вычисления степени числа
double power(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    double base;
    int exponent;
    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите показатель степени: ";
    cin >> exponent;
    cout << "Результат: " << power(base, exponent) << endl;
    return 0;
}
