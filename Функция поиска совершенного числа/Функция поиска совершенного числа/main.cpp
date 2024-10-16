//
//  main.cpp
//  Функция поиска совершенного числа
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для проверки, является ли число совершенным
bool isPerfect(int n) {
    int sum = 0;  // Инициализация суммы делителей
    // Находим все делители числа и суммируем их
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    // Если сумма делителей равна числу, то число совершенное
    return sum == n;
}

// Функция для поиска совершенных чисел в заданном диапазоне
void findPerfectNumbers(int start, int end) {
    for(int i = start; i <= end; i++) {
        if(isPerfect(i)) {
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
    cout << "Совершенные числа в диапазоне от " << start << " до " << end << ": ";
    findPerfectNumbers(start, end);
    return 0;
}
