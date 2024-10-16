//
//  main.cpp
//  Класс Human с перегрузкой
//
//  Created by Станислав Егоров on 04.04.2024.
//

#include <iostream>
#include <string>
#include <map>
#include <random>

// Перегрузка оператора << для класса Human
std::ostream& operator<<(std::ostream& os, const Human& human) {
    os << "Name: " << human.name << ", Surname: " << human.surname << ", Age: " << human.age << ", Sex: " << (human.sex ? "Male" : "Female");
    return os;
}

class Human {
public:
    std::string name;
    std::string surname;
    int age;
    bool sex; // true для мужчины, false для женщины

    Human(const std::string& name, const std::string& surname, int age, bool sex)
        : name(name), surname(surname), age(age), sex(sex) {}
};

int main() {
    std::map<std::string, Human> people;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disAge(18, 65); // Возраст от 18 до 65 лет
    std::uniform_int_distribution<> disSex(0, 1); // Пол: 0 - мужчина, 1 - женщина

    for (int i = 0; i < 30; ++i) {
        std::string key;
        if (disSex(gen) == 0) {
            key = "man-" + std::to_string(i + 1);
        } else {
            key = "woman-" + std::to_string(i + 1);
        }

        std::string name = "Name" + std::to_string(i + 1);
        std::string surname = "Surname" + std::to_string(i + 1);
        int age = disAge(gen);
        bool sex = disSex(gen) == 0;

        people[key] = Human(name, surname, age, sex);
    }

    // Вывод информации о людях
    for (const auto& pair : people) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
