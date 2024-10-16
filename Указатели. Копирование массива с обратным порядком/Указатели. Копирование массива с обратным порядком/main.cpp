//
//  main.cpp
//  Указатели. Копирование массива с обратным порядком
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для копирования одного массива в другой в обратном порядке
void copyAndReverseArray(int* src, int* dest, int size) {
  for(int i = 0; i < size; i++) {
      *(dest + size - i - 1) = *(src + i);
  }
}

int main() {
  int src[] = {1, 2, 3, 4, 5};
  int dest[1];
  int size = sizeof(src) / sizeof(src[0]);
  copyAndReverseArray(src, dest, size);
  cout << "Скопированный и перевернутый массив: ";
  for(int i = 0; i < size; i++) {
      cout << dest[i] << " ";
  }
  cout << endl;
  return 0;
}
