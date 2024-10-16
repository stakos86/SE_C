//
//  main.cpp
//  Возведение в степень
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y;
    cout << "Введите число x: ";
    cin >> x;
    cout << "Введите число y: ";
    cin >> y;
    double result = pow(x, y);
    cout << "Результат: " << result << endl;
    return 0;
}
