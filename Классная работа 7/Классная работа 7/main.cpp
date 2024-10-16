//
//  main.cpp
//  Классная работа 7
//
//  Created by Станислав Егоров on 13.03.2024.
//
/*
#include <iostream>
int main() {
    int a, b, result;
    std::cout << "Введите делимое: ";
    std::cin >> a;
    std::cout << "Введите делитель: ";
    std::cin >> b;
    if (b == 0) {
           std::cout << "Ошибка: деление на ноль недопустимо!" << std::endl;
           return 0;
       }
    result = a / b;
    std::cout << "Результат: " << result << std::endl;
    std::cout << "Программа закончена" << std::endl;

    return 0;
}
*/

/*
#include <iostream>

int main() {

    int a, b, result;

    std::cout << "Введите делимое: ";
    std::cin >> a;

    std::cout << "Введите делитель: ";
    std::cin >> b;

    try {
        if (b == 0)
        {
            throw 100;
        }
        result = a / b;
    }

    catch (int e) {
        if (e == 100)
        {
            std::cout << "ZeroDivisionError";
            return 0;
        }
    }

    std::cout << "Результат: " << result << std::endl;
    std::cout << "Программа закончена" << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int main() {
    setlocale(LC_ALL, "");

    int a=0, b=0, result=0;

    std::cout << "Введите делимое: ";
    std::cin >> a;

    std::cout << "Введите делитель: ";
    std::cin >> b;

    try {
        if (b == 0)
        {
            throw 2.5;
        }
        result = a / b;
    }

    catch (double e) {
        if (e == 2.5)
        {
            std::cout << "ZeroDivisionError";
           // return 0;
        }
    }

    std::cout << "Результат: " << result << std::endl;
    std::cout << "Программа закончена" << std::endl;
    return 0;
    
}
*/

/*
#include <iostream>

int main() {

    int a=0, b=0, result=0;

    std::cout << "Введите делимое: ";
    std::cin >> a;

    std::cout << "Введите делитель: ";
    std::cin >> b;

    

    
    try {
        if (b == 0)
        {
            throw 2.5;
        }

        if (b == 1)
        {
            throw "It is one";
        }


        if (b == 2)
        {
            throw 100;
        }
        result = a / b;
    }

    catch (double e) {
        if (e == 2.5)
        {
            std::cout << "ZeroDivisionError";
            // return 0;
        }
    }
    

    catch (const char* e) {
        if (e == "It is one")
        {
            std::cout << "We got the ONE!";
            // return 0;
        }
    }

    std::cout << "Результат: " << result << std::endl;
    std::cout << "Программа закончена" << std::endl;
    return 0;
    
}
*/
/*
#include <iostream>
using namespace std;

class ZeroDivisionException {};
class DivisibleIsTwoException {};
class DivisibleIsOneException {};

int main()
{

    int a, b, result=0;

    cout << "Введите делимое: ";
    cin >> a;
    cout << "Введите делитель: ";
    cin >> b;

    try {
        if (a == 2)
        {
            throw DivisibleIsTwoException();
        }

        if (a == 1)
        {
            throw DivisibleIsOneException();
        }
        if (b == 0) {
            throw ZeroDivisionException(); // тип double
        }
        result = a / b;
    }

    catch (ZeroDivisionException& e) {
        std::cout << "ZeroDivisionError" << endl;
    }

    catch (DivisibleIsOneException& e) {
        std::cout << "We got the divisible as ONE!";
    }

    catch (DivisibleIsTwoException& e) {
        std::cout << "We got the divisible as TWO!";
    }

    catch (...) {
        std::cout << "Unknown exception\n";
    }

    cout << "Результат деления: " << result << endl;
    cout << "Программа закончена." << endl;

    return 0;
}
*/
/*
#include <iostream>

struct WrongAgeException {
    int age;
};

int main() {
    int age;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    try {
        if (age > 200) {
            throw WrongAgeException{age};
        } else {
            std::cout << "Ваш возраст: " << age << std::endl;
        }
    }
    catch (WrongAgeException& e) {
        std::cout << "Неправильный возраст: " << e.age << std::endl;
    }
    return 0;
}
*/

#include <iostream>
#include <cstdlib>

int main() {
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        try {
            int number = rand() % 97 + 3;
            std::cout << number << std::endl;
            if (number == 17) {
                throw 17;
            }
            if (number % 2 != 0) {
                throw "нечётное!";
            }
        }

        catch (int err) {
            std::cerr << "Число 17!" << std::endl;
            return 0;
        }
        catch (const char* err) {
            std::cerr << err << std::endl;
        }
    }
    return 0;
}
