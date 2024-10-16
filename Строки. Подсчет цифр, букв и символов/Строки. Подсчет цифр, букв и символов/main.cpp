//
//  main.cpp
//  Строки. Подсчет цифр, букв и символов
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string str;
   cout << "Введите строку: ";
   getline(cin, str);

   int letters = 0;
   int digits = 0;
   int others = 0;

   for (char c : str) {
       if (isalpha(c)) {
           letters++;
       } else if (isdigit(c)) {
           digits++;
       } else {
           others++;
       }
   }

   cout << "Количество букв: " << letters << std::endl;
   cout << "Количество цифр: " << digits << std::endl;
   cout << "Количество других символов: " << others << std::endl;

   return 0;
}
