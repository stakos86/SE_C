//
//  main.cpp
//  Работа с файлами. Подсчет элементов
//
//  Created by Станислав Егоров on 12.12.2023.
//
/*
 Дан текстовый файл. Необходимо создать
 новый файл и записать в него следующую статистику по
 исходному файлу:
 ■ Количество символов;
 ■ Количество строк;
 ■ Количество гласных букв;
 ■ Количество согласных букв;
 ■ Количество цифр.
 */
#include <fstream>
#include <iostream>
#include <string>

int main() {
   std::ifstream inputFile("input.txt");
   std::ofstream outputFile("output.txt");

   if (!inputFile.is_open() || !outputFile.is_open()) {
       std::cerr << "Не удалось открыть один из файлов" << std::endl;
       return 1;
   }

   std::string line;
   int charCount = 0;
   int lineCount = 0;
   int vowelCount = 0;
   int consonantCount = 0;
   int digitCount = 0;

   while (std::getline(inputFile, line)) {
       lineCount++;
       for (char c : line) {
           charCount++;
           if (isalpha(c)) {
               if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                  vowelCount++;
               } else {
                  consonantCount++;
               }
           } else if (isdigit(c)) {
               digitCount++;
           }
       }
   }

   outputFile << "Количество символов: " << charCount << std::endl;
   outputFile << "Количество строк: " << lineCount << std::endl;
   outputFile << "Количество гласных букв: " << vowelCount << std::endl;
   outputFile << "Количество согласных букв: " << consonantCount << std::endl;
   outputFile << "Количество цифр: " << digitCount << std::endl;

   inputFile.close();
   outputFile.close();
   return 0;
}
