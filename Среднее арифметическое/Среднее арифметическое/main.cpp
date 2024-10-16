//
//  main.cpp
//  Среднее арифметическое
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>

int main() {
    int sum = 0;
    int count = 0;
    int average = 0;

    for(int i = 1; i <= 1000; i++) {
        sum += i;
        count++;
    }

    average = sum / count;

    std::cout << "Среднее арифметическое всех целых чисел от 1 до 1000 равно: " << average << std::endl;

    return 0;
}
