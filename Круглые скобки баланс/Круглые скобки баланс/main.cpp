//
//  main.cpp
//  Круглые скобки баланс
//
//  Created by Станислав Егоров on 17.01.2024.
//

#include <iostream>
#include <string>

bool validateBrackets(const std::string& str) {
    int balance = 0;
    for (char c : str) {
        if (c == '(') {
            ++balance;
        } else if (c == ')') {
            --balance;
        }
        // Если баланс стал отрицательным, значит закрывающих скобок больше
        if (balance < 0) {
            return false;
        }
    }
    // В конце баланс должен быть равен нулю, если открывающих и закрывающих скобок поровну
    return balance == 0;
}

int main() {
    std::string input;
    std::cout << "Введите строку из круглых скобок: ";
    std::cin >> input;

    if (validateBrackets(input)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
