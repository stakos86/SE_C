//
//  main.cpp
//  Двумерный массив с заполнением
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>

int main() {
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    
    int array[3][3];
    array[0][0] = n;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            array[i][j] = array[i-1][j] * 2;
        }
    }
    
    std::cout << "Результирующий массив:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
