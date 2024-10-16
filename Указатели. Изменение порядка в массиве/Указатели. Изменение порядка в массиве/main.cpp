//
//  main.cpp
//  Указатели. Изменение порядка в массиве
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для переворота массива
void reverseArray(int* arr, int size) {
   int* start = arr;
   int* end = arr + size - 1;
   while (start < end) {
       int temp = *start;
       *start = *end;
       *end = temp;
       start++;
       end--;
   }
}

int main() {
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);
   reverseArray(arr, size);
   cout << "Перевернутый массив: ";
   for(int i = 0; i < size; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}
