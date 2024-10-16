//
//  main.cpp
//  Перечисляемые типы
//
//  Created by Станислав Егоров on 27.11.2023.
//

#include <iostream>
using std::cout;

int main()
{
    enum WeekDays {Monday = 1, Tuesday, Wednesday, Thirsday, Friday, Saturday, Sunday};
    WeekDays day = Monday;
    cout << day << "\n";
    
}
