//
//  main.cpp
//  Високосный год
//
//  Created by Станислав Егоров on 24.10.2023.
//
#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    if (year % 400 == 0) {
        cout << "YES";
    }
    else if (year % 100 == 0) {
        cout << "NO";
    }
    else if (year % 4 == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
