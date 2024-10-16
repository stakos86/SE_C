//
//  main.cpp
//  Двумерный массив со сдвигом
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <iomanip>
#include <random>

// Функция для генерации случайного числа в заданном диапазоне
// используя генератор случайных чисел std::random_device
int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

void fillArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = getRandomNumber(0, 9);
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void shiftArray(int** arr, int rows, int cols, int shifts, std::string direction) {
    if (direction == "вправо") {
        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < shifts; ++k) {
                int temp = arr[i][cols - 1];
                for (int j = cols - 1; j > 0; --j) {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = temp;
            }
        }
    } else if (direction == "влево") {
        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < shifts; ++k) {
                int temp = arr[i][0];
                for (int j = 0; j < cols - 1; ++j) {
                    arr[i][j] = arr[i][j + 1];
                }
                arr[i][cols - 1] = temp;
            }
        }
    } else if (direction == "вверх") {
        for (int k = 0; k < shifts; ++k) {
            int temp = arr[0][0];
            for (int i = 0; i < rows - 1; ++i) {
                arr[i][0] = arr[i + 1][0];
            }
            for (int j = 0; j < cols - 1; ++j) {
                arr[rows - 1][j] = arr[rows - 1][j + 1];
            }
            arr[rows - 1][cols - 1] = temp;
        }
    } else if (direction == "вниз") {
        for (int k = 0; k < shifts; ++k) {
            int temp = arr[rows - 1][cols - 1];
            for (int i = rows - 1; i > 0; --i) {
                arr[i][cols - 1] = arr[i - 1][cols - 1];
            }
            for (int j = cols - 1; j > 0; --j) {
                arr[0][j] = arr[0][j - 1];
            }
            arr[0][0] = temp;
        }
    }
}

int main() {
    const int rows = 2;
    const int cols = 5;
    
    // Создание двумерного массива
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    
    // Заполнение массива случайными числами и его вывод
    fillArray(arr, rows, cols);
    std::cout << "Исходный массив: " << std::endl;
    printArray(arr, rows, cols);
    
    // Получение от пользователя количества сдвигов и положения
    int shifts;
    std::string direction;
    std::cout << "Введите количество сдвигов: ";
    std::cin >> shifts;
    std::cout << "Введите положение (влево, вправо, вверх, вниз): ";
    std::cin >> direction;
    
    // Выполнение сдвига массива и вывод результата
    shiftArray(arr, rows, cols, shifts, direction);
    std::cout << "Результат сдвига: " << std::endl;
    printArray(arr, rows, cols);
    
    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
