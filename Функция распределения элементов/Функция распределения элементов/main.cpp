//
//  main.cpp
//  Функция распределения элементов
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция для проверки, является ли число положительным, отрицательным или нулем
string checkNumber(int num) {
   if (num > 0) return "positive";
   if (num < 0) return "negative";
   return "zero";
}

// Функция для распределения элементов массива по типам
void distributeArray(int* array, int size, int*& positive, int*& negative, int*& zero, int& positiveSize, int& negativeSize, int& zeroSize) {
   positive = new int[size];
   negative = new int[size];
   zero = new int[size];
   positiveSize = 0;
   negativeSize = 0;
   zeroSize = 0;
   for (int i = 0; i < size; i++) {
       if (checkNumber(array[i]) == "positive") {
           positive[positiveSize] = array[i];
           positiveSize++;
       }
       else if (checkNumber(array[i]) == "negative") {
           negative[negativeSize] = array[i];
           negativeSize++;
       }
       else {
           zero[zeroSize] = array[i];
           zeroSize++;
       }
   }
}

int main() {
   int array[] = {1, -2, 0, 3, -4, 0, 5};
   int size = sizeof(array) / sizeof(array[0]);
   int* positive, *negative, *zero;
   int positiveSize, negativeSize, zeroSize;
   distributeArray(array, size, positive, negative, zero, positiveSize, negativeSize, zeroSize);
   cout << "Positive numbers: ";
   for (int i = 0; i < positiveSize; i++) {
       cout << positive[i] << " ";
   }
   cout << endl;
   cout << "Negative numbers: ";
   for (int i = 0; i < negativeSize; i++) {
       cout << negative[i] << " ";
   }
   cout << endl;
   cout << "Zeros: ";
   for (int i = 0; i < zeroSize; i++) {
       cout << zero[i] << " ";
   }
   cout << endl;
   delete[] positive;
   delete[] negative;
   delete[] zero;
   return 0;
}
