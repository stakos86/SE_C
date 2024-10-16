//
//  main.cpp
//  Работа в классе 30.05..02
//
//  Created by Станислав Егоров on 29.05.2024.
//

#include <iostream>
using namespace std;

class Example {};

int main() {

    Example obj1;
    Example obj2;
    Example obj3;
    Example obj4;
    Example obj5;

    cout << "Адрес объекта 1: " << &obj1 << endl;
    cout << "Адрес объекта 2: " << &obj2 << endl;
    cout << "Адрес объекта 3: " << &obj3 << endl;
    cout << "Адрес объекта 4: " << &obj4 << endl;
    cout << "Адрес объекта 5: " << &obj5 << endl;

    return 0;
}
