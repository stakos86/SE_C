//
//  main.cpp
//  8
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>
#include <string>

class Base {
public:
    virtual void Do() = 0;
    virtual std::string Run() = 0;
};

class Sample : public Base {
public:
    void Do() override { std::cout << "Sample Do!" << std::endl; }
    std::string Run() override {
        std::cout << "Sample Run!" << std::endl;
        return "Sample Run!";
    }
};

class Foobar : public Sample {
public:
    void Do() override { std::cout << "Foobar Do" << std::endl; }
    std::string Run() override {
        std::cout << "Foobar Run" << std::endl;
        return "Foobar Run";
    }
};

int main()
{
    Sample sample;
    sample.Do();
    sample.Run();
    Foobar foobar;
    foobar.Do();
    foobar.Run();
}
