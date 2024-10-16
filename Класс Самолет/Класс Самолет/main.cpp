//
//  main.cpp
//  Класс Самолет
//
//  Created by Станислав Егоров on 27.02.2024.
//
/*
 Cоздать класс Airplane (самолет)
 С помощью перегрузки операторов реализовать:
 ■ Проверка на равенство типов самолетов (операция = =)
 ■ Увеличение и уменьшение пассажиров в салоне самолета
 (операции ++ и - - в префиксной форме)
 ■ Сравнение двух самолетов по максимально возможному ко-
 личеству пассажиров на борту (операция>)
 */
#include <iostream>

class Airplane {
public:
    Airplane() : passengers(0), maxPassengers(0) {}
    Airplane(int maxPassengers) : passengers(0), maxPassengers(maxPassengers) {}

    bool operator==(const Airplane& other) {
        return maxPassengers == other.maxPassengers;
    }

    Airplane& operator++() {
        if (passengers < maxPassengers) {
            passengers++;
        }
        return *this;
    }

    Airplane& operator--() {
        if (passengers > 0) {
            passengers--;
        }
        return *this;
    }

    bool operator>(const Airplane& other) {
        return maxPassengers > other.maxPassengers;
    }

    int getMaxPassengers() const {
        return maxPassengers;
    }

    int getPassengers() const {
        return passengers;
    }

private:
    int passengers;
    int maxPassengers;
};

int main() {
    Airplane a1(100);
    Airplane a2(200);

    if (a1 == a2) {
        std::cout << "Airplanes have the same maximum number of passengers." << std::endl;
    } else {
        std::cout << "Airplanes do not have the same maximum number of passengers." << std::endl;
    }

    ++a1;
    --a2;

    if (a1 > a2) {
        std::cout << "a1 has more passengers than a2." << std::endl;
    } else {
        std::cout << "a1 does not have more passengers than a2." << std::endl;
    }

    std::cout << "a1 max passengers: " << a1.getMaxPassengers() << std::endl;
    std::cout << "a1 current passengers: " << a1.getPassengers() << std::endl;

    std::cout << "a2 max passengers: " << a2.getMaxPassengers() << std::endl;
    std::cout << "a2 current passengers: " << a2.getPassengers() << std::endl;

    return 0;
}
