//
//  main.cpp
//  Ниндзя
//
//  Created by Станислав Егоров on 15.02.2024.
//
/*
 Создать класс Ninja, который
 1. генерирует массивы целых и дробных чисел
 2. сортирует массивы целых и дробных чисел
 3. выводит на экран массивы целых и дробных чисел

 в main()
 1. создать и вывести на экран массив из 15 целых чисел по возрастанию
 1. создать и вывести на экран массив из 20 целых чисел по убыванию
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Ninja {
private:
    std::vector<int> intArray;
    std::vector<double> doubleArray;

public:
    void generateIntegers(int size) {
        intArray.clear();
        for(int i = 0; i < size; i++) {
            intArray.push_back(i);
        }
    }

    void generateDoubles(int size) {
        doubleArray.clear();
        for(int i = 0; i < size; i++) {
            doubleArray.push_back(i + 0.5);
        }
    }

    void sortIntegers() {
        std::sort(intArray.begin(), intArray.end());
    }

    void sortDoubles() {
        std::sort(doubleArray.begin(), doubleArray.end());
    }

    void printIntegers() {
        for(const auto& num : intArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void printDoubles() {
        for(const auto& num : doubleArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Ninja myNinja;

    myNinja.generateIntegers(15);
    std::cout << "Array of 15 integers in ascending order:" << std::endl;
    myNinja.printIntegers();

    myNinja.generateIntegers(20);
    myNinja.sortIntegers();
    std::cout << "Array of 20 integers in descending order:" << std::endl;
    myNinja.printIntegers();

    return 0;
}
