//
//  main.cpp
//  Классы. Статический и динамический массивы
//
//  Created by Станислав Егоров on 26.02.2024.
//

/*
 Опишите два класса StaticArray и DynamicArray.

 StaticArray хранит статический массив, а DynamicArray - динамический.

 Описать конструкторы и деструкторы, и инициализировать оба в main().
 */

#include <iostream>
using namespace std;

class StaticArray {
private:
    int arr[10];
public:
    StaticArray() {}
    ~StaticArray() {}
};

class DynamicArray {
private:
    int* arr2;
    int size2;

public:
    DynamicArray(int s2) {
        size2 = s2;
        arr2 = new int[size2];
    }

    ~DynamicArray() {
        delete[] arr2;
    }
};

int main() {
    StaticArray StaticArr();
    DynamicArray DynamicArr(10);

    return 0;
}
