//
//  main.cpp
//  Массив и вывод второй трети
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void improvedBubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        bool swapped = false;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    const int size = 50;
    int arr[size];

    std::srand(std::time(nullptr));

    // Заполнение массива случайными числами
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100; // генерируем случайное число от 0 до 99
    }

    // Сортировка массива усовершенствованным пузырьком
    improvedBubbleSort(arr, size);

    // Вывод второй трети массива
    int start = size / 3;
    int end = start + size / 3;
    for (int i = start; i < end; i++) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
