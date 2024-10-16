//
//  main.cpp
//  Поиск заданного ключа в одномерном массиве
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция линейного поиска
int linearSearch(int arr[], int n, int key) {
    // Проходим по всему массиву
    for(int i = 0; i < n; i++) {
        // Если находим ключевое значение, возвращаем его индекс
        if(arr[i] == key)
            return i;
    }
    // Если ключевое значение не найдено, возвращаем -1
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int key = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(arr, n, key);
    if(index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found in the array";
    return 0;
}
