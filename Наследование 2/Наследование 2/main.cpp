//
//  main.cpp
//  Наследование 2
//
//  Created by Станислав Егоров on 15.02.2024.
//
/*
 Создайте класс Животное, оно хранит имя.

 Создайте класс Летающее, оно умеет летать.

 Создайте класс Водоплавающее, оно умеет плавать в воде.

 Создайте класс Яйцекладущее, оно откладывает яйца.

 Создайте класс Водоплавающее летающее животное.

 Создайте класс Водоплавающее Яйцекладущее животное.

 Создайте класс Летающего Водоплавающего Яйцекладщего животного.

 Создайте объекты последних трёх классов.
 */

#include <iostream>
#include <string>

using namespace std;

// класс Животное
class Animal {
public:
    string name;

    Animal(string name) {
        this->name = name;
    }
};

// класс Летающее
class Flying {
public:
    void fly() {
        cout << "Я умею летать!" << endl;
    }
};

// класс Водоплавающее
class Waterfowl {
public:
    void swim() {
        cout << "Я умею плавать в воде!" << endl;
    }
};

// класс Яйцекладущее
class EggLaying {
public:
    void layEgg() {
        cout << "Я откладываю яйца!" << endl;
    }
};

// класс Водоплавающее летающее животное
class WaterflyingAnimal : public Animal, public Flying, public Waterfowl {
public:
    WaterflyingAnimal(string name) : Animal(name) {}
};

// класс Водоплавающее яйцекладущее животное
class WatereggLayingAnimal : public Animal, public Waterfowl, public EggLaying {
public:
    WatereggLayingAnimal(string name) : Animal(name) {}
};

// класс Летающее водоплавающее яйцекладущее животное
class FlyingwaterEggLayingAnimal : public Animal, public Flying, public Waterfowl, public EggLaying {
public:
    FlyingwaterEggLayingAnimal(string name) : Animal(name) {}
};

int main() {
    // создание объектов последних трех классов
    WaterflyingAnimal animal1("Водоплавающее Летающее Животное");
    WatereggLayingAnimal animal2("Водоплавающее Яйцекладущее Животное");
    FlyingwaterEggLayingAnimal animal3("Летающее Водоплавающее Яйцекладущее Животное");

    // использование методов объектов
    animal1.fly();
    animal1.swim();

    animal2.swim();
    animal2.layEgg();

    animal3.fly();
    animal3.swim();
    animal3.layEgg();

    return 0;
}
