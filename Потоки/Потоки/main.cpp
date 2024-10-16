//
//  main.cpp
//  Потоки
//
//  Created by Станислав Егоров on 11.12.2023.
//

#include <fstream>
#include <string>
#include <iostream>
int counter {0};

using namespace std;

int main() {
    //ofstream out{ "outfile.txt" }; // Output File STREAM >> O F STREAM >> ofstream

    ifstream in{ "outfile.txt" }; // Input File STREAM >> I F STREAM >> iftream

    // проверяем открылся ли файл
    if (!in) {
        std::cerr << "Could not open file outfile.txt";
        return 1;
    }
    
    while (in) {
        std::string input;
        in >> input;
        counter++;
    }
    std::cout << counter;
}
//посчитали количество букв в тексте файла через потоки
