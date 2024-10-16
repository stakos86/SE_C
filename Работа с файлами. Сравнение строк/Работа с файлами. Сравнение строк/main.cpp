//
//  main.cpp
//  Работа с файлами. Сравнение строк
//
//  Created by Станислав Егоров on 12.12.2023.
//
/*
 Дано два текстовых файла. Выяснить, совпадают ли их строки. Если нет, то вывести несовпадающую
 строку из каждого файла.
 */
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file1("file1.txt"), file2("file2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Не удалось открыть один из файлов" << std::endl;
        return 1;
    }

    std::string line1, line2;
    int lineNum = 0;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        lineNum++;
        if (line1 != line2) {
            std::cout << "Строки " << lineNum << " не совпадают." << std::endl;
            std::cout << "Файл 1: " << line1 << std::endl;
            std::cout << "Файл 2: " << line2 << std::endl;
        }
    }

    // Проверяем, если один из файлов еще не кончился
    if (std::getline(file1, line1) || std::getline(file2, line2)) {
        std::cout << "Один из файлов больше другого." << std::endl;
    }

    file1.close();
    file2.close();
    return 0;
}
