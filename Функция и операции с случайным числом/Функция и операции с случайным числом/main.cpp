//
//  main.cpp
//  Функция и операции с случайным числом
//
//  Created by Станислав Егоров on 29.01.2024.
//

#include <iostream>
#include <cstdlib>

int generateRandomNumber()
{
    return rand();
}

void printNumber(int number)
{
    if (number % 2 == 0)
    {
        std::cout << number + 1;
    }
    else
    {
        std::cout << number;
    }
    std::cout << "\n";
}

void printNumberFormat(int number)
{
    std::cout << "число: " << number << "\n";
}

int main()
{
    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        int randomNumber = generateRandomNumber();
        printNumberFormat(randomNumber);
    }

    return 0;
}
