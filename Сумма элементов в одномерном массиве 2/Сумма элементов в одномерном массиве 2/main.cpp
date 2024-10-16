//
//  main.cpp
//  Сумма элементов в одномерном массиве 2
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Установка генератора случайных чисел на основе текущего времени
    srand(time(0));
    
    int n, range, target;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    std::cout << "Введите диапазон случайных чисел (от 1 до ...): ";
    std::cin >> range;
    std::cout << "Введите значение, меньше которого нужно найти сумму: ";
    std::cin >> target;
    
    int* arr = new int[n];
    
    // Заполнение массива случайными числами
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range + 1;
    }
    
    // Вывод массива на экран
    std::cout << "Массив:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    
    int sum = 0;
    
    // Поиск суммы элементов, значения которых меньше указанного числа
    for (int i = 0; i < n; i++) {
        if (arr[i] > target) {
            sum += arr[i];
        }
    }
    
    std::cout << "Сумма элементов, значения которых больше " << target << ": " << sum << std::endl;
    
    delete[] arr;
    
    return 0;
}
