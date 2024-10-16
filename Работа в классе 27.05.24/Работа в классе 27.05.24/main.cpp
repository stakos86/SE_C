//
//  main.cpp
//  Работа в классе 27.05.24
//
//  Created by Станислав Егоров on 27.05.2024.
//

//Опишите класс Человек, у которого внутри есть статическая переменная "количество созданных людей" и метод создания, который увеличивает этот счетчика на один.

#include <iostream>
#include "OnlyHuman.hpp"
class Person {
private:
    static int count;

public:
    Person() {
        count++;
    }

    static int getNumberOfPeople() {
        return count;
    }
};

int Person::count {0};

int main() {
    Person leather_bag1;
    Person leather_bag2;
    Person leather_bag3;

    std::cout << "Людишек создано: " << Person::getNumberOfPeople() << std::endl;

    return 0;
}

//Переделать класс Logger таким образом чтобы:
//он хранил указатель currentLogger на первый созданный объект этого класса.
//имел метод getLogger, который 2.1 создавал объект если хранимый указатель currentLogger пустой, или2.2 возвращал значение currentLogger

//#include <iostream>
//
//class Logger {
//public:
//    virtual void log(const std::string& message) const = 0;
//};
//
//class Person {
//private:
//    static int count;
//    static Logger* currentLogger;
//
//public:
//    Person(Logger* logger = nullptr) : logger(logger) {
//        count++;
//        if (!currentLogger && logger!= nullptr) {
//            currentLogger = logger;
//        }
//    }
//
//    static int getNumberOfPeople() {
//        return count;
//    }
//
//    static Logger* getLogger() {
//        return currentLogger;
//    }
//
//    void setLogger(Logger* newLogger) {
//        if (newLogger!= nullptr &&!currentLogger) {
//            currentLogger = newLogger;
//        }
//    }
//
//private:
//    Logger* logger; // Указатель на объект Logger для текущего человека
//};
//
//int Person::count {0};
//Logger* Person::currentLogger {nullptr}; // Инициализация статического указателя
//
//int main() {
//    Person p1(new Logger()); // Создаем объект класса Logger и передаем его в конструктор Person
//    Person p2(new Logger());
//    Person p3(new Logger());
//
//    std::cout << "Number of people created: " << Person::getNumberOfPeople() << std::endl;
//
//    // Пример использования getLogger
//    Logger* logger = Person::getLogger();
//    if (logger!= nullptr) {
//        logger->log("Three persons have been created.");
//    } else {
//        std::cout << "No logger has been set." << std::endl;
//    }
//
//    return 0;
//}
//
//// Реализация простого класса Logger для демонстрации
//class SimpleLogger : public Logger {
//public:
//    void log(const std::string& message) const override {
//        std::cout << "Log: " << message << std::endl;
//    }
//};

//Создать класс OnlyHuman, В котором будет храниться значение адреса единственного созданного человека в переменной instance
//
//Также есть метод Print() который выводит на печать instance
//и getHuman() который создаёт OnlyHuman и кладёт его в  instance если instance пустой, или возвращает instance
//
//В main() создать три объекта OnlyHuman и "распечатать" их

//#include <iostream>
//class OnlyHuman {
//private:
//    static OnlyHuman* instance;
//public:
//    static OnlyHuman* getHuman() {
//        if (instance == nullptr) {
//            instance = new OnlyHuman();
//        }
//        return instance;
//    }
//    void Print() const {
//        std::cout << "This is a humanoid." << std::endl;
//    }
//};
//OnlyHuman* OnlyHuman::instance = nullptr;
//int main() {
//    OnlyHuman::getHuman()->Print();
//    OnlyHuman::getHuman()->Print();
//    OnlyHuman::getHuman()->Print();
//    return 0;
//}
