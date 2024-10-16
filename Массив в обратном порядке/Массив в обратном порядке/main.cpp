//
//  main.cpp
//  Массив в обратном порядке
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <cstdlib> // для функции rand()

int main() {
    const int size = 50;
    int arr[size];

    // Заполнение массива случайными числами
    for (int i = 0; i < size; ++i) {
        arr[i] = rand();
    }

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Обмен элементов массива в обратном порядке
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    // Вывод измененного массива
    std::cout << "Массив в обратном порядке: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
