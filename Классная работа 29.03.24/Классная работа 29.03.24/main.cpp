//
//  main.cpp
//  Классная работа 29.03.24
//
//  Created by Станислав Егоров on 29.03.2024.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


int main() {
    srand(time(0));
    std::string name[10]{ "Павел", "Мария", "Александра", "Владислав", "Марина", "Михаил", "Радик", "Антонина", "Дамир", "Станислав" };
    std::string surname[10]{ "Молошный", "Васянович", "Франчук", "Еголин", "Основина", "Шихарев", "Алдакимов", "Марговская", "Безуглов", "Раев" };
    std::string phoneNumber[10]{ "123456789", "321654987", "789456123", "102030456", "405060789","708090123", "741085209", "789123045", "654123789", "965132478" };
    int age;

    std::ofstream text1("Surnames.txt");
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 10;
        text1 << surname[n] << "\n";
    }

    std::ofstream text2("Names.txt");
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 10;
        text2 << name[n] << "\n";
    }
    std::ofstream text3("PnoneNumbers.txt");
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 10;
        text3 << phoneNumber[n] << "\n";
    }
    return 0;
}
