//
//  main.cpp
//  Работа с файлами общая
//
//  Created by Станислав Егоров on 29.03.2024.
//
/*
 Создать программу, которая создаст 3 файла Surnames.txt, Names.txt, PhoneNumbers.txt и которая запишет в эти файлы по 10 строк значений: фамилии, имена и телефоны.
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

std::string FormatPersonInfo(std::string& name, std::string& surname, std::string& phoneNumber) {
    std::stringstream ss;
    ss << surname << ":" << name << ":" << phoneNumber;
    return ss.str();
}

bool ParseStringToPersonInfo(const std::string& input,  std::string& surname, std::string& name, std::string& phoneNumber) {
    std::stringstream ss(input);
    return std::getline(ss, surname, ' ') && std::getline(ss, name, ' ') && std::getline(ss, phoneNumber, ' ');
}

void saveToText(std::string& input) {
    std::ofstream surnamesFile, namesFile, phoneNumbersFile;

    surnamesFile.open("Surnames.txt", std::ios::app);
    namesFile.open("Names.txt", std::ios::app);
    phoneNumbersFile.open("PhoneNumbers.txt", std::ios::app);
    std::string name, surname, phoneNumber;
    if (ParseStringToPersonInfo(input, surname, name, phoneNumber))
    {
        surnamesFile << surname << std::endl;
        namesFile << name << std::endl;
        phoneNumbersFile << phoneNumber << std::endl;
    }
    else std::cout << "Failed to parse the string." << std::endl;

    surnamesFile.close();
    namesFile.close();
    phoneNumbersFile.close();

    std::cout << "Files created successfully." << std::endl;
}

int main() {
    std::string input;
    int i = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Введите Фамилия, Имя, телефон #" << i + 1 << "\n";
        std::getline(std::cin, input);
        saveToText(input);
    }

    return 0;
}
