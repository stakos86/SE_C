//
//  main.cpp
//  Строки. Функция удаления символов
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Функция для удаления всех вхождений символа из строки
string removeChar(string str, char ch) {
 str.erase(remove(str.begin(), str.end(), ch), str.end());
 return str;
}

int main() {
 string str = "Hello, World!";
 str = removeChar(str, 'l');
 cout << str << endl;
 return 0;
}
