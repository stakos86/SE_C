//
//  main.cpp
//  Перевод двоичного числа в десятичное
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <cmath>
using namespace std;

// Функция для перевода числа из двоичного в десятичное представление
int binaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0) {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main() {
    long long n;
    cout << "Введите двоичное число: ";
    cin >> n;
    cout << "Десятичное представление числа: " << binaryToDecimal(n) << endl;
    return 0;
}
