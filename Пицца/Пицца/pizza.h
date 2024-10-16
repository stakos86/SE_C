//
//  pizza.h
//  Пицца
//
//  Created by Станислав Егоров on 22.05.2024.
//

#ifndef PIZZA_H
#define PIZZA_H

#include <string>

class Pizza {
public:
    // Конструктор класса
    Pizza(const std::string& typeOfDough, const std::string& typeOfTopping);

    // Метод для отображения информации о пицце
    void display() const;

private:
    std::string m_typeOfDough;
    std::string m_typeOfTopping;
};

#endif // PIZZA_H

