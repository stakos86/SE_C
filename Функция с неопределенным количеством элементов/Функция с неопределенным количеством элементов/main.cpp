//
//  main.cpp
//  Функция с неопределенным количеством элементов
//
//  Created by Станислав Егоров on 21.02.2024.
//

#include <cstdarg>
#include <iostream>

void simple_printf(const char* fmt, ...) // C-style "const char* fmt, ..." is also valid
{
    va_list args; // <-- создаём список аргументов
    va_start(args, fmt); //

    while (*fmt != '\0')
    {
        if (*fmt == 'd')
        {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        }
        else if (*fmt == 'c')
        {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        }
        else if (*fmt == 'f')
        {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }

    va_end(args);
}

int main()
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
}
