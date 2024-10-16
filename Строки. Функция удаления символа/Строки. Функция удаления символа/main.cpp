//
//  main.cpp
//  Строки. Функция удаления символа
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <string>
using namespace std;

// Функция для удаления символа с заданным номером
string removeCharAt(string str, int index) {
  str.erase(index, 1);
  return str;
}

int main() {
  string str = "Hello, World!";
  str = removeCharAt(str, 7);
  cout << str << endl;
  return 0;
}
