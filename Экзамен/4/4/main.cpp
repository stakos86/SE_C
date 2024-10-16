//
//  main.cpp
//  4
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    // С целыми числами
    int num1 = 5, num2 = 10;
    std::cout << "Сумма целых чисел: " << sum(num1, num2) << std::endl;

    // С дробными числами
    double d1 = 3.587, d2 = 276.599;
    std::cout << "Сумма дробных чисел: " << sum(d1, d2) << std::endl;

    // С объектами типа double
    double doubleValue1 = 10.589, doubleValue2 = 20.522;
    std::cout << "Сумма объектов double: " << sum(doubleValue1, doubleValue2) << std::endl;

    return 0;
}
