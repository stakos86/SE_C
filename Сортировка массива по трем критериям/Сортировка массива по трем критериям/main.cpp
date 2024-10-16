//
//  main.cpp
//  Сортировка массива по трем критериям
//
//  Created by Станислав Егоров on 27.10.2023.
//

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    
    const int size = 10; // Размер массива
    int arr[size]; // Объявление массива
    int result[size];
    int indexOfResult = 0;
    
    // Заполнение массива случайными числами от -30 до 30
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 61 - 30; // Генерация случайного числа от -30 до 30
        cout << arr[i] << " ";
}
         printf ("\n");
    
         // Положительные числа
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            result[indexOfResult] = arr[i];
            indexOfResult++;// проходим дальше по массиву
        }
    }
    printf ("\n");
         
         // Нули
    for (int i = 0; i < size; i++) {
        if (arr[i]== 0) {
            result[indexOfResult] = arr[i];
            indexOfResult++;
        }
    }
    printf ("\n");
         
         // Отрицательные числа
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            result[indexOfResult] = arr[i];
            indexOfResult++;
        }
    }
    printf ("\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

 return 0;
}
