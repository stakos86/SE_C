//
//  main.cpp
//  Векторы с замещением
//
//  Created by Станислав Егоров on 04.04.2024.
//
/*
 Создать вектор из значений {2, 3, 0, 7, 2, 4, 11}
 Создать пустой вектор и инициализировать его значениями с 1 по 5 элемент предыдущего вектора. Вывести его на экран.
 */
#include <iostream>
#include <vector>

int main() {
    std::vector<int> originalVector = {2, 3, 0, 7, 2, 4, 11};
    
    std::vector<int> newVector;
    for (int i = 1; i <= 5; i++) {
        newVector.push_back(originalVector[i]);
    }
    
    for (int num : newVector) {
        std::cout << num << " ";
    }
    
    return 0;
}
