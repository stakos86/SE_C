//
//  main.cpp
//  Бинарный поиск заданного ключа в одномерном массиве
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using namespace std;

// Функция бинарного поиска
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Если элемент присутствует в середине
        if (arr[m] == x)
            return m;
 
        // Если x больше, игнорируем левую половину
        if (arr[m] < x)
            l = m + 1;
 
        // Если x меньше, игнорируем правую половину
        else
            r = m - 1;
    }
 
    // Если мы добрались до сюда, то элемента нет в массиве
    return -1;
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Элемента нет в массиве" : cout << "Элемент присутствует в индексе " << result;
    return 0;
}
