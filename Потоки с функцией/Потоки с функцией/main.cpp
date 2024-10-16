//
//  main.cpp
//  Потоки с функцией
//
//  Created by Станислав Егоров on 11.12.2023.
//

#include <iostream>
#include <string>  // <--- нужно для работы функции getline
#include <fstream> // <--- нужно для работы с потоками файлов

/*

поток для чтения из файла » input file stream » ввод файл поток
использую ">>" или "getline"
создаю объект типа ifstream

поток для записи в файл » output file stream » вывод файл поток
использую "<<"
создаю объект типа ofstream

*/

/*
пишем функцию для записи в файл
она принимает на вход название файла
она ничего ен возвращает
*/

void WriteFile(std::string FileName) {
    //std::ofstream out{ FileName }; // инструмент для записи информации в файл
    std::ofstream out{ FileName, std::ios::app }; //не обнуляет предыдущие значения

    if (!out) {
        std::cerr << "Couldn't open file: " << FileName;
        return;
    }

    out << "Some info\n";
}

/*
пишем функцию которая читает из файла
она принимает на вход название файла
она ничего не возвращает
*/

void ReadFile(std::string FileName) {
    std::ifstream in{ FileName };

    if (!in)
    {
        std::cerr << "Couldn't open file: " << FileName;
        return;
    }

    while (in) {
        std::string input;
        std::getline(in, input);
        std::cout << input << "\n";
    }
}

int main() {
    const char* name = "outfile.txt";
    WriteFile(name);
    ReadFile(name);
}
