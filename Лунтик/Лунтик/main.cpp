//
//  main.cpp
//  Лунтик
//
//  Created by Станислав Егоров on 05.02.2024.
//
/*
 Создать класс Лунтик
 у которого есть имя и цвет и количество всех созданных лунтиков
 При создании Лунтик пишет "Я n-й Лунтик на Земле". (n - это количество Лунтиков на Земле)

 В программе
 Запросить количество попыток созданий лунтиков
 На каждую попытку подбрасывать монетку и если решка то создавать Лунтика,
 если орел то не создавать.
 */


#include <iostream>
#include <string>
#include <random>

class Luntik {
private:
    std::string name;
    std::string color;
    static int LuntikCount;

public:
    Luntik(const std::string& name, const std::string& color)
        : name(name), color(color) {
        LuntikCount++;
        std::cout << "Я " << LuntikCount << "-й Лунтик на Земле.\n";
    }

    ~Luntik() {
        LuntikCount--;
    }

    void PrintDetails() const {
        std::cout << "Имя: " << name << ", Цвет: " << color << "\n";
    }
};

// Статическая переменная должна быть инициализирована за пределами класса
int Luntik::LuntikCount = 0;

int main() {
    int attempts;
    std::cout << "Введите количество попыток создания лунтиков: ";
    std::cin >> attempts;

    std::mt19937 engine; // Генератор случайных чисел
    std::uniform_int_distribution<> distr(0, 1); // Распределение для "решки" или "орел"

    for (int i = 0; i < attempts; ++i) {
        if (distr(engine)) { // Если выпадает "решка", создаём лунтика
            Luntik* luntik = new Luntik("Лунтик" + std::to_string(i+1), "Цвет" + std::to_string(i+1));
            luntik->PrintDetails();
        } else {
            std::cout << "Орел, лунтик не создан.\n";
        }
    }

    return 0;
}
