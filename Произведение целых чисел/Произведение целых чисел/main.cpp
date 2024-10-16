//
//  main.cpp
//  Произведение целых чисел
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Введите значение переменной a: ";
    cin >> a;
    
    if (a < 1 || a > 20) {
        cout << "Ошибка! Значение переменной a должно быть от 1 до 20." << endl;
        return 0;
    }
    
    long long product = 1;
    
    for (int i = a; i <= 20; i++) {
        product *= i;
    }
    
    cout << "Произведение всех целых чисел от " << a << " до 20: " << product << endl;
    
    return 0;
}
