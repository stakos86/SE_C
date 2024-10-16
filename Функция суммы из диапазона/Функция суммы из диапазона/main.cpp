//
//  main.cpp
//  Функция суммы из диапазона
//
//  Created by Станислав Егоров on 24.11.2023.
//
#include <iostream>
using namespace std;

// Функция для вычисления суммы чисел в заданном диапазоне
int sumInRange(int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int start, end;
    cout << "Введите начальное число: ";
    cin >> start;
    cout << "Введите конечное число: ";
    cin >> end;
    cout << "Сумма чисел в диапазоне: " << sumInRange(start, end) << endl;
    return 0;
}
