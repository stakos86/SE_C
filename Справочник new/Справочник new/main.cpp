//
//  main.cpp
//  Справочник new
//
//  Created by Станислав Егоров on 25.03.2024.
//
/*
 1. Создать класс СПРАВОЧНИК со следующими полями:
 а) Название фирмы;
 б) Владелец;
 в) Телефон;
 г) Адрес;
 д) Род деятельности

 2. Реализовать следующие возможности:
 ■ Поиск по названию;
 ■ Поиск по владельцу;
 ■ Поиск по номеру телефона;
 ■ Показ всех записей и добавление
 */
#include <iostream>
#include <map>
#include <string>

class Directory {
public:
    std::string name;
    std::string owner;
    std::string phone;
    std::string address;
    std::string activity;

    Directory(const std::string& name, const std::string& owner, const std::string& phone, const std::string& address, const std::string& activity)
        : name(name), owner(owner), phone(phone), address(address), activity(activity) {}
};

class DirectoryManager {
private:
    std::map<std::string, Directory> directories;

public:
    void addDirectory(const std::string& name, const std::string& owner, const std::string& phone, const std::string& address, const std::string& activity) {
        directories[name] = Directory(name, owner, phone, address, activity);
    }

    void showAllDirectories() {
        for (const auto& dir : directories) {
            std::cout << "Название: " << dir.second.name << ", Владелец: " << dir.second.owner << ", Телефон: " << dir.second.phone << ", Адрес: " << dir.second.address << ", Род деятельности: " << dir.second.activity << std::endl;
        }
    }

    void searchByName(const std::string& name) {
        auto it = directories.find(name);
        if (it != directories.end()) {
            std::cout << "Название: " << it->second.name << ", Владелец: " << it->second.owner << ", Телефон: " << it->second.phone << ", Адрес: " << it->second.address << ", Род деятельности: " << it->second.activity << std::endl;
        } else {
            std::cout << "Не найдено" << std::endl;
        }
    }

    // Дополнительные методы поиска по владельцу и номеру телефона можно реализовать аналогично
};

int main() {
    DirectoryManager manager;
    manager.addDirectory("Фирма А", "Иванов Иван", "1234567890", "ул. Примерная, 1", "Торговля");
    manager.addDirectory("Фирма Б", "Петров Петр", "0987654321", "ул. Примерная, 2", "Строительство");

    manager.showAllDirectories();
    manager.searchByName("Фирма А");

    return 0;
}
