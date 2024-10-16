//
//  main.cpp
//  Сортировка массива по условию
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <algorithm>

void reverseArray(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void sortArray(int* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double avg = sum / n;

    int first_third = n / 3;
    int two_thirds = 2 * n / 3;

    if (avg > 0) {
        std::sort(arr, arr + two_thirds);
    } else {
        std::sort(arr, arr + first_third);
    }

    reverseArray(arr, two_thirds, n - 1);
}

int main() {
    int arr[] = {3, -2, 1, 5, -4, 2, 7, -6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
