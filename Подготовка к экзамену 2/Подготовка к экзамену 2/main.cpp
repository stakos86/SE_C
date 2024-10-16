//
//  main.cpp
//  Подготовка к экзамену 2
//
//  Created by Станислав Егоров on 18.12.2023.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    setlocale(LC_ALL, "");
    
    int a;
    cout << "Введите переменную a: \n";
    cin >> a;
    for (int i = 0; i < 5; i++) {
        cout << a << " ";
    }
    cout << "a = " << a;
    double b;
    cout << "\nВведите переменную b: \n";
    cin >> b;
    for (int i = 0; i < 5; i++) {
        cout << b << " ";
    }
    cout << "b = " << b;
    char c;
    cout << "\nВведите знаковую переменную c: \n";
    cin >> c;
    for (int i = 0; i < 5; i++) {
        cout << c << " ";
    }
    cout << "c = " << c;
    string d;
    cout << "\nВведите строковую переменную d: \n";
    cin >> d;
    for (int i = 0; i < 5; i++) {
        cout << d << " ";
    }
    cout << "d = " << d;
    long e;
    cout << "\nВведите переменную e: \n";
    cin >> e;
}
