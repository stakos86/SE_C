//
//  main.cpp
//  Сумма целых чисел
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
using namespace std;

int main()
{
    int a;
    int sum = 0;

    cout << "Введите число a: ";
    cin >> a;

    for (int i = a; i <= 500; i++)
    {
        sum += i;
    }

    cout << "Сумма чисел от a до 500 = " << sum << endl;

    return 0;
}
