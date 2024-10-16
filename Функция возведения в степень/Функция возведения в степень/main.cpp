//
//  main.cpp
//  Функция возведения в степень
//
//  Created by Станислав Егоров on 15.11.2023.
//
/*
 Написать функцию, которая принимает два параметра: основание степени и показатель степени, и вычисляет степень числа на основе полученных данных.

 */

#include <cmath>

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

// или

double power(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
