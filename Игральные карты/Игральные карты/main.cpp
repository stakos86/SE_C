//
//  main.cpp
//  Игральные карты
//
//  Created by Станислав Егоров on 09.11.2023.
//

#include <iostream>
#include <format>
using namespace std;

string getMastjByNumber(int number) {
    /*
    крести 0
    буби 1
    червы 2
    пики 3
    */
    switch (number)
    {
    case 0:
        return "крести";
    case 1:
        return "  буби";
    case 2:
        return " червы";
    case 3:
        return "  пики";
    default:
        break;
    }
    return "";
}

string getNameOfCardByNumber(int number){
    switch (number)
    {
    case 1:
        return "   туз";
    case 2:
        return "двойка";
    case 3:
        return "тройка";
    case 4:
        return "  4-ка";
    case 5:
        return "  5-ка";
    case 6:
        return "  6-ка";
    case 7:
        return "  7-ка";
    case 8:
        return "  8-ка";
    case 9:
        return "  9-ка";
    case 10:
        return " 10-ка";
    case 11:
        return " валет";
    case 12:
        return "  дама";
    case 13:
        return "король";
    default:
        break;
    }
    return "";
}



string DrawCard(int nameNumber, int mastjNumber) {
    string result = "******************\n* ";
    result += getNameOfCardByNumber(nameNumber);
    result += " ";
    result += getMastjByNumber(mastjNumber);
    result += "  *\n******************\n";
    return result;
}

int main() {
    /*
    крести +
    буби x
    червы &
    пики %

    карта 6 крести
    ******************\n*      6 крести  *\n******************
    */
    // тесты
    // туз буби - 1,1
    cout << DrawCard(1, 1);
    // король червы
    cout << DrawCard(13, 2);
}
