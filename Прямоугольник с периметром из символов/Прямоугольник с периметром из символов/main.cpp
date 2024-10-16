//
//  main.cpp
//  Прямоугольник с периметром из символов
//
//  Created by Станислав Егоров on 25.10.2023.
//

#include <iostream>

int main() {
    int height = 10;
    int width = 15;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
