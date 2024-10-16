//
//  main.cpp
//  Пицца с паттерном
//
//  Created by Станислав Егоров on 22.05.2024.
//
#include <iostream>
#include <string>
using namespace std;

class Pizza
{

public:

    string mTypeOfDough;
    string mTypeOfTopping;
    string mTypeOfSauce;

    // Pizza(string d = "regular dough", string t = "no topings") :mTypeOfDough(d), mTypeOfTopping(t) {};
    ~Pizza() {};

    void Display() const {
        cout << "Pizza with " << mTypeOfDough << " and "
            << mTypeOfTopping << mTypeOfSauce << "\n";
    }
};

class PizzaBuilder {
    Pizza pizza;

public:
    Pizza build() {
        return pizza;
    }

    void SetTypeOfDough(string value) {
        pizza.mTypeOfDough = value;
    }

    void SetTypeOfTopping(string value) {
        pizza.mTypeOfTopping = value;
    }
    void SetTypeOfSauce(string value) {
        pizza.mTypeOfSauce = value;
    }
};

int main() {
    PizzaBuilder builder;

    builder.SetTypeOfDough("Thin");
    builder.SetTypeOfTopping("Pineapple");
    builder.SetTypeOfSauce("Chili sauce");

    Pizza pizza = builder.build();
    pizza.Display();
}
