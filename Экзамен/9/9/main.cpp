//
//  main.cpp
//  9
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>
#include <vector>
#include <string>

class Fruit {
public:
    std::string name;
};

class Apple : public Fruit {
public:
    static int count;
    Apple() {
        count++;
    }
};

class Pear : public Fruit {
public:
    static int count;
    Pear() {
        count++;
    }
};

class Pineapple : public Fruit {
public:
    static int count;
    Pineapple() {
        count++;
    }
};

int Apple::count = 0;
int Pear::count = 0;
int Pineapple::count = 0;

class FruitsArray {
public:
    std::vector<Fruit*> fruits;

    void print() {
        for (Fruit* fruit : fruits) {
            std::cout << fruit->name << std::endl;
        }
    }

    int amount() {
        return fruits.size();
    }

    int amount(std::string name) {
        int count = 0;
        for (Fruit* fruit : fruits) {
            if (fruit->name == name) {
                count++;
            }
        }
        return count;
    }

    void add(Fruit* fruit) {
        fruits.push_back(fruit);
    }
};

int main() {
    srand(time(NULL));
    FruitsArray fruitsArray;

    for (int i = 0; i < 10; ++i) {
        int random = rand() % 3;
        Fruit* newFruit;
        if (random == 0) {
            newFruit = new Apple();
            newFruit->name = "Apple";
        } else if (random == 1) {
            newFruit = new Pear();
            newFruit->name = "Pear";
        } else {
            newFruit = new Pineapple();
            newFruit->name = "Pineapple";
        }
        fruitsArray.add(newFruit);
    }

    std::cout << "Все фрукты:" << std::endl;
    fruitsArray.print();
    std::cout << "Количество фруктов: " << fruitsArray.amount() << std::endl;
    std::cout << "Количество яблок: " << Apple::count << std::endl;
    std::cout << "Количество груш: " << Pear::count << std::endl;
    std::cout << "Количество ананасов: " << Pineapple::count << std::endl;

    return 0;
}
