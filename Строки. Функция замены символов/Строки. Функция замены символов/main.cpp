//
//  main.cpp
//  Строки. Функция замены символов
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   string str;
   cout << "Enter a string: ";
   getline(cin, str);

   replace(str.begin(), str.end(), '.', '!');

   cout << "Modified string: " << str << endl;

   return 0;
}
