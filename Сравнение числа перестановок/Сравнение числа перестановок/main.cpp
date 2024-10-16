//
//  main.cpp
//  Сравнение числа перестановок
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <cstdlib>  // для генерации случайных чисел
#include <ctime>    // для использования текущего времени в качестве seed

// Функция для сортировки массива методом усовершенствованного "пузырька"
int bubbleSort(int arr[], int n) {
    int swaps = 0;
    bool swapped;

    for (int i = 0; i < n-1; i++) {
        swapped = false;

        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
                swaps++;
            }
        }

        if (!swapped) {
            break;  // если не было перестановок, то массив уже отсортирован
        }
    }

    return swaps;
}

// Функция для сортировки массива методом выбора
int selectionSort(int arr[], int n) {
    int swaps = 0;

    for (int i = 0; i < n-1; i++) {
        int min_index = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        std::swap(arr[i], arr[min_index]);
        swaps++;
    }

    return swaps;
}

int main() {
    const int SIZE = 1000;
    const int TESTS = 10;

    int bubbleSwapsTotal = 0;
    int selectionSwapsTotal = 0;

    srand(time(NULL));  // используем текущее время в качестве seed для генерации случайных чисел

    for (int t = 0; t < TESTS; t++) {
        int arr[SIZE];

        // Заполняем массив случайными числами
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand();
        }

        // Копируем массив для сортировки методом усовершенствованного "пузырька"
        int arrCopyBubble[SIZE];
        std::copy(arr, arr + SIZE, arrCopyBubble);

        // Копируем массив для сортировки методом выбора
        int arrCopySelection[SIZE];
        std::copy(arr, arr + SIZE, arrCopySelection);

        // Сортируем массивы и считаем число перестановок
        int bubbleSwaps = bubbleSort(arrCopyBubble, SIZE);
        int selectionSwaps = selectionSort(arrCopySelection, SIZE);

        bubbleSwapsTotal += bubbleSwaps;
        selectionSwapsTotal += selectionSwaps;
    }

    double bubbleAverage = static_cast<double>(bubbleSwapsTotal) / TESTS;
    double selectionAverage = static_cast<double>(selectionSwapsTotal) / TESTS;

    std::cout << "Среднее число перестановок для усовершенствованного пузырька: " << bubbleAverage << std::endl;
    std::cout << "Среднее число перестановок для метода выбора: " << selectionAverage << std::endl;

    return 0;
}
