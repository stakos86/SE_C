//
//  main.cpp
//  Работа в классе 6
//
//  Created by Станислав Егоров on 29.01.2024.
//
/*
#include <iostream>
#include <string>
using namespace std;
class CPrinter {
    void PrintIntArray (int * array, int size){
        for (size_t i = 0, i < size, i++)
            cout << "[" << i << "]:" << array [i] << "\n";
    }
}
int main() {
    
    return 0;
}
*/

/*
 Напишите программу для хранения, наполнения случайными числами и сортировки массива.
 Программа запрашивает количество элементов.

 Далее создаёт массив, наполняет его случайными числами,
 выводит на экран и сортирует.

 Необходимо написать наиболее безопасную в плане памяти компьютера программу.
 */
/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int main() {
    
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    std::vector<int> arr(n);

    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::sort(arr.begin(), arr.end());

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
*/

/*
 то же самое, но с использованием конструктора
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Array {
private:
    int* data;
    int size;

public:
    Array(int size) : size(size) {
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    void fillRandom() {
        srand(time(0));
        for (int i = 0; i < size; i++) {
            data[i] = rand();
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int size;
    std::cout << "Введите количество элементов: ";
    std::cin >> size;

    Array array(size);
    array.fillRandom();

    std::cout << "Массив до сортировки: ";
    array.print();

    array.sort();

    std::cout << "Массив после сортировки: ";
    array.print();

    return 0;
}
