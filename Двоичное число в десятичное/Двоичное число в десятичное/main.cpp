//
//  main.cpp
//  Двоичное число в десятичное
//
//  Created by Станислав Егоров on 12.11.2023.
//

#include <iostream>
#include <cmath>
int size;

int main()
{
    int arr [size];
    int binaryNumber;

    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    std::cout << "Decimal representation of " << binaryNumber << " is " << binaryToDecimal(binaryNumber);

    return 0;
}
