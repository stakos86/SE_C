//
//  main.cpp
//  3
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>

class doublevalue {
private:
    double mvalue;
    
public:
    // Конструктор по умолчанию
    doublevalue() : mvalue(0) {}
    
    // Конструктор с параметром
    doublevalue(double value) : mvalue(value) {}
    
    // Копирование
    doublevalue(const doublevalue& other) : mvalue(other.mvalue) {}
    
    // Геттер
    double getValue() const {
        return mvalue;
    }
    
    // Сеттер
    void setValue(double value) {
        mvalue = value;
    }
    
    // Перегрузка 1
    doublevalue operator+(const doublevalue& other) const {
        doublevalue result(mvalue + other.mvalue);
        return result;
    }
    
    // Перегрузка 2
    doublevalue operator-(const doublevalue& other) const {
        doublevalue result(mvalue - other.mvalue);
        return result;
    }
    
    // Перегрузка 3
    doublevalue operator*(const doublevalue& other) const {
        doublevalue result(mvalue * other.mvalue);
        return result;
    }
    
    // Перегрузка 4
    doublevalue operator/(const doublevalue& other) const {
        if (other.mvalue != 0) {
            doublevalue result(mvalue / other.mvalue);
            return result;
        }
        throw "Деление на ноль!";
    }
    
    // Перегрузка 4
    bool operator<(const doublevalue& other) const {
        return mvalue < other.mvalue;
    }
    
    // Перегрузка 5
    bool operator>(const doublevalue& other) const {
        return mvalue > other.mvalue;
    }
    
    // Перегрузка 6
    bool operator==(const doublevalue& other) const {
        return mvalue == other.mvalue;
    }
    
    // Перегрузка 7
    friend std::ostream& operator<<(std::ostream& os, const doublevalue& dv) {
        os << dv.mvalue;
        return os;
    }
};

int main() {
    doublevalue dv1(15.59);
    doublevalue dv2(103.17);
    
    // Сумма
    std::cout << "Сумма: " << dv1 + dv2 << std::endl;
    
    // Разница
    std::cout << "Разница: " << dv1 - dv2 << std::endl;
    
    // Произведение
    std::cout << "Произведение: " << dv1 * dv2 << std::endl;
    
    // Деление
    try {
        std::cout << "Результат деления: " << dv1 / dv2 << std::endl;
    } catch (const char* error) {
        std::cout << "Ошибка: " << error << std::endl;
    }
    
    // Больше
    std::cout << "dv1 > dv2: " << (dv1 > dv2) << std::endl;
    
    // Меньше
    std::cout << "dv1 < dv2: " << (dv1 < dv2) << std::endl;
    
    // Равенство
    std::cout << "dv1 == dv2: " << (dv1 == dv2) << std::endl;
    
    return 0;
}
