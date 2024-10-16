//
//  main.cpp
//  Буква, цифра, символ
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
#include <cctype> // Для функций isalpha, isdigit, ispunct
using namespace std;

int main() {
    char input;
    cout << "Введите символ: ";
    cin >> input;
    
    if (isalpha(input))
        cout << "Это буква.\n";
    else if (isdigit(input))
        cout << "Это цифра.\n";
    else if (ispunct(input))
        cout << "Это знак препинания.\n";
    else
        cout << "Это другой символ.\n";

    return 0;
}
