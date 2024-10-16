//
//  main.cpp
//  Класс Яблоко
//
//  Created by Станислав Егоров on 04.03.2024.
//
/*
 Опишите класс Яблоко

 С параметрами вес и цвет.

 С геттерами, сеттерами, конструктором по умолчанию и параметризированным.

 Если объект строится по умолчанию - заполнить его случайным цветом из массива цветом и случайным весом в рамках среднего веса яблока.

 В мэйн создать и вывести на экран 10 яблок: создавать как с передачей параметров, та к и без.
 */

#include <iostream>
#include <random>
#include <string>

class Apple {
private:
    double weight;
    std::string colour;

public:
    Apple() : weight(0), colour("") {}

    Apple(double weight, const std::string& colour) : weight(weight), colour(colour) {}

    double getWeight() const {
        return weight;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }

    std::string getColour() const {
        return colour;
    }

    void setColour(const std::string& colour) {
        this->colour = colour;
    }

    void generateRandomApple() {
        std::string colours[] = {"Red", "Green", "Yellow"};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> colourDist(0, 2);
        std::uniform_real_distribution<double> weightDist(0, 0.3);

        int randomColourIndex = colourDist(gen);
        double randomWeight = weightDist(gen);

        weight = randomWeight;
        colour = colours[randomColourIndex];
    }
};

int main() {
    Apple apples[10];

    for (int i = 0; i < 10; i++) {
        if (apples[i].getWeight() == 0 && apples[i].getColour() == "") {
            apples[i].generateRandomApple();
        }
        
        std::cout << "Apple " << i+1 << ": " << "Weight - " << apples[i].getWeight() << ", Colour - " << apples[i].getColour() << std::endl;
    }

    return 0;
}
