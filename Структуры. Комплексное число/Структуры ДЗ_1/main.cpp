//
//  main.cpp
//  Структуры ДЗ_1
//
//  Created by Станислав Егоров on 30.11.2023.
//
/*
 
 Создайте структуру, описывающую комплексное число. Реализуйте арифметические операции с комплекс- ными числами: сумму, разность, умножение, деление.
 
 */
#include <iostream>

struct Complex {
    double real;
    double imag;

    Complex operator+(const Complex& b) {
        return Complex{real + b.real, imag + b.imag};
    }

    Complex operator-(const Complex& b) {
        return Complex{real - b.real, imag - b.imag};
    }

    Complex operator*(const Complex& b) {
        return Complex{real * b.real - imag * b.imag, real * b.imag + imag * b.real};
    }

    Complex operator/(const Complex& b) {
        double denom = b.real * b.real + b.imag * b.imag;
        return Complex{(real * b.real + imag * b.imag) / denom, (imag * b.real - real * b.imag) / denom};
    }
};

int main() {
    Complex a = {3, 2};
    Complex b = {1, 7};

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    std::cout << "Sum: " << sum.real << " + " << sum.imag << "i\n";
    std::cout << "Difference: " << diff.real << " + " << diff.imag << "i\n";
    std::cout << "Product: " << prod.real << " + " << prod.imag << "i\n";
    std::cout << "Quotient: " << quot.real << " + " << quot.imag << "i\n";

    return 0;
}
