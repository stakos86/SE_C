//
//  main.cpp
//  Функция счастливое число
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для проверки, является ли число "счастливым"
bool isLucky(int num) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 6; ++i) {
        if (i < 3)
            sum1 += num % 10;
        else
            sum2 += num % 10;
        num /= 10;
    }
    return sum1 == sum2;
}

// Функция для поиска "счастливых" чисел в заданном диапазоне
void findLuckyNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (isLucky(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start, end;
    cout << "Введите начальное число диапазона: ";
    cin >> start;
    cout << "Введите конечное число диапазона: ";
    cin >> end;
    cout << "Счастливые числа в диапазоне от " << start << " до " << end << ": ";
    findLuckyNumbers(start, end);
    return 0;
}
