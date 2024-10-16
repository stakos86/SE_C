//
//  main.cpp
//  Функции с динамическими массивами
//
//  Created by Станислав Егоров on 24.11.2023.
//



Функция распределения динамической памяти:
int* allocateArray(int size) {
   return new int[size];
}
Функция инициализации динамического массива:
void initializeArray(int* array, int size, int value) {
   for(int i = 0; i < size; i++) {
       array[i] = value;
   }
}
Функция печати динамического массива:
void printArray(int* array, int size) {
   for(int i = 0; i < size; i++) {
       cout << array[i] << " ";
   }
   cout << endl;
}
Функция удаления динамического массива:
void deleteArray(int* array) {
   delete[] array;
}
Функция добавления элемента в конец массива:
void appendElement(int* &array, int &size, int value) {
   int* newArray = new int[size + 1];
   for(int i = 0; i < size; i++) {
       newArray[i] = array[i];
   }
   newArray[size] = value;
   delete[] array;
   array = newArray;
   size++;
}
Функция вставки элемента по указанному индексу:
void insertElement(int* &array, int &size, int index, int value) {
   int* newArray = new int[size + 1];
   for(int i = 0; i < index; i++) {
       newArray[i] = array[i];
   }
   newArray[index] = value;
   for(int i = index; i < size; i++) {
       newArray[i + 1] = array[i];
   }
   delete[] array;
   array = newArray;
   size++;
}
Функция удаления элемента по указанному индексу:
void deleteElement(int* &array, int &size, int index) {
   int* newArray = new int[size - 1];
   for(int i = 0; i < index; i++) {
       newArray[i] = array[i];
   }
   for(int i = index; i < size - 1; i++) {
       newArray[i] = array[i + 1];
   }
   delete[] array;
   array = newArray;
   size--;
}
