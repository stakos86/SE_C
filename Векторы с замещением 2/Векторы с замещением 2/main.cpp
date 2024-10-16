//
//  main.cpp
//  Векторы с замещением 2
//
//  Created by Станислав Егоров on 04.04.2024.
//
/*
 Создать вектор A из значений {2, 3, 0, 7, 2, 4, 11}
 Создать вектор B из 6 чисел 105.
 Сохранить вектор B в вектор A.

 Вывести все вектора на экран.
 */
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {2, 3, 0, 7, 2, 4, 11};
    std::vector<int> b(6, 105);

    a.insert(a.end(), b.begin(), b.end());

    std::cout << "Vector a: ";
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector b: ";
    for (int num : b) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
