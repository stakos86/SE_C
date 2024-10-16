//
//  main.cpp
//  Структуры. Автомобиль
//
//  Created by Станислав Егоров on 30.11.2023.
//

#include <iostream>
#include <string>

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    std::string color;
    std::string transmissionType;
};

void setValues(Car& car, double length, double clearance, double engineVolume, double enginePower, double wheelDiameter, std::string color, std::string transmissionType) {
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

void displayValues(const Car& car) {
    std::cout << "Length: " << car.length << "\n";
    std::cout << "Clearance: " << car.clearance << "\n";
    std::cout << "Engine Volume: " << car.engineVolume << "\n";
    std::cout << "Engine Power: " << car.enginePower << "\n";
    std::cout << "Wheel Diameter: " << car.wheelDiameter << "\n";
    std::cout << "Color: " << car.color << "\n";
    std::cout << "Transmission Type: " << car.transmissionType << "\n";
}

double findValue(const Car& car, std::string attribute) {
    if (attribute == "length") return car.length;
    if (attribute == "clearance") return car.clearance;
    if (attribute == "engineVolume") return car.engineVolume;
    if (attribute == "enginePower") return car.enginePower;
    if (attribute == "wheelDiameter") return car.wheelDiameter;
    return -1;
}

int main() {
    Car myCar;
    setValues(myCar, 4.2, 0.15, 2.0, 150, 0.5, "Red", "Manual");
    displayValues(myCar);
    std::cout << "Engine Power: " << findValue(myCar, "enginePower") << "\n";

    return 0;
}
