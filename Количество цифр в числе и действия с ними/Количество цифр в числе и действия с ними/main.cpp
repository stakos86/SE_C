//
//  main.cpp
//  Количество цифр в числе и действия с ними
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number, digit, sum = 0, count = 0, zeroes = 0;

    cout << "Введите число: ";
    cin >> number;

    while (number != 0) {
        digit = number % 10;
        sum += digit;
        count++;
        if (digit == 0) {
            zeroes++;
        }
        number /= 10;
    }

    cout << "Количество цифр: " << count << endl;
    cout << "Сумма цифр: " << sum << endl;
    cout << "Среднее арифметическое: " << static_cast<double>(sum) / count << endl;
    cout << "Количество нулей: " << zeroes << endl;

    return 0;
}
