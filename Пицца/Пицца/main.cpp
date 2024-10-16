//
//  main.cpp
//  Пицца
//
//  Created by Станислав Егоров on 22.05.2024.
//

#include "pizza.h"
#include <iostream>

// Реализация конструктора и метода display()
void Pizza::display() const {
    std::cout << "Pizza with TypeOfDough: " << m_typeOfDough << " and TypeOfTopping: " << m_typeOfTopping << std::endl;
}

int main() {
    // Создание двух объектов класса Pizza
    Pizza pizza1("Thin", "Mushrooms");
    Pizza pizza2("Thick", "Pepperoni");

    // Вызов метода display() для каждого объекта
    pizza1.display();
    pizza2.display();

    return 0;
}
