//
//  main.cpp
//  Указатели. Копирование массива
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для копирования одного массива в другой
void copyArray(int* src, int* dest, int size) {
   for(int i = 0; i < size; i++) {
       *(dest + i) = *(src + i);
   }
}

int main() {
   int src[] = {1, 2, 3, 4, 5};
   int dest[1];
   int size = sizeof(src) / sizeof(src[0]);
   copyArray(src, dest, size);
   cout << "Скопированный массив: ";
   for(int i = 0; i < size; i++) {
       cout << dest[i] << " ";
   }
   cout << endl;
   return 0;
}
