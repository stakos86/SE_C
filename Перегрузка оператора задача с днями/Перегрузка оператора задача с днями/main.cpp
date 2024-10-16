//
//  main.cpp
//  Перегрузка оператора задача с днями
//
//  Created by Станислав Егоров on 12.02.2024.
//

#include <iostream>
#include <array>

class Date {
    int day;
    int month;
    int year;
public:
 
    Date(int d, int m, int y)
        : day(d), month(m), year(y) {}

    // Перегрузка оператора вычитания для вычисления разницы в днях
    int operator-(const Date& other) const {
        auto totalDaysThis = (year *  365) + (month *  30) + day;
        auto totalDaysOther = (other.year *  365) + (other.month *  30) + other.day;

        return totalDaysThis - totalDaysOther;
    }

    // Перегрузка оператора увеличения для добавления дней к дате
    Date& operator+=(int days) {
        day += days;
        // Обновляем месяц и год при необходимости
        while (day >  30) { // Предполагаем, что все месяцы имеют  30 дней
            month++;
            day -=  30;
        }
        while (month >  12) {
            year++;
            month -=  12;
        }
        return *this;
    }

};

int main() {
    Date date1 (15, 2, 2004);
    Date date2 (1, 3, 2024);

    int daysDifference = date1 - date2;
    std::cout << "Разница между датами составляет " << daysDifference << " дней." << std::endl;

    date2 +=  45;
    std::cout << "Дата после добавления  45 дней: " << date2.day << "/" << date2.month << "/" << date2.year << std::endl;

    return  0;
}
