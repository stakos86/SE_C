//
//  main.cpp
//  Работа с файлами
//
//  Created by Станислав Егоров on 10.12.2023.
//


#include <iostream>
/*
 наш файл с функциями
 для работы с массивом
*/
#include "array.h"

using namespace std;

int main() {
    const int size = 5;
    int arr[size] = { 8,44,67,12,13 };
    // показ массива
    ShowArray(arr, size);
    cout << endl;
    // минимум
    cout << "Minimum: " << GetMin(arr, size) << endl;
    // максимум
    cout << "Maximum: " << GetMax(arr, size) << endl;
    return 0;
}
