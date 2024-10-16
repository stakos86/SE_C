/*
Создать функцию, которая создаёт массив, элементом которого является один этаж.

На вход она получает
количество этажей, и
кол-во однокомнатных, двухкомнатных, трехкомнатных и четырехкомнатных квартир на каждом этаже.
*/

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

struct Flat {
    int mAmountOfRooms;
    double mSquareFootage;
    int mNumber;
    int mResidents;
    bool mBalcony{ false };

    void AmountOfRooms(int value) { mAmountOfRooms = value; } // <--- устанавливает значение m_amountOfRooms
    int AmountOfRooms() { return mAmountOfRooms; } // <--- возвращает его
    void SquareFootage(double value) { mSquareFootage = value; }
    double SquareFootage() { return mSquareFootage; }
    void Number(int value) { mNumber = value; }
    int Number() { return mNumber; }
    void Residents(int value) { mResidents = value; }
    int Residents() { return mResidents; }
    void Balcony(bool value) { mBalcony = value; }
    bool Balcony() { return mBalcony; }


    string FlatString() {
        return "количество комнат: " + to_string(AmountOfRooms()) +
            " | метраж: " + Stringify(SquareFootage()) +
            "м2 | номер квартиры: " + to_string(Number()) +
            " | количество жильцов: " + to_string(Residents()) +
            " | наличие балкона: " + (Balcony() ? " есть " : " нет") + "\n";
    }
    void PrintFlat() {
        cout << FlatString();
    }
    string Stringify(double value) {
        ostringstream ss;
        ss << value;
        return ss.str();
    }
};

void GenerateFlat(Flat& flat, int amountOfRooms = 0) {
    flat.mAmountOfRooms = amountOfRooms == 0 ? rand() % 5 : amountOfRooms;
    flat.mSquareFootage = rand() % 30 + 100;
    flat.mNumber = rand() % 90;
    flat.mResidents = rand() % 10;
    flat.mBalcony = rand() % 2 ? true : false;
}

void PrintFloor(Flat* floor, int size) {
    for (size_t i = 0; i < size; i++)
    {
        floor[i].PrintFlat();
    }
}

void PrintParadnaya(Flat** paradnaya, int size, int * floorsSize) {
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "\nfloor #" << i + 1 << "\n";
        PrintFloor(paradnaya[i], floorsSize[i]);
    }
}

Flat* GenerateFloorOfFlats(int& size, int Ones, int Twos, int Threes, int Fours) {
    size = Ones + Twos + Threes + Fours;
    Flat* result = new Flat[size];
    for (size_t i = 0; i < size; i++)
    {
        int amount = i < Ones ? 1 : i < Ones + Twos ? 2 : i < Ones + Twos + Threes ? 3 : 4;
        GenerateFlat(result[i], amount);
    }
    return result;
}

Flat** GenerateParadnaya(int floors, int * floorsSize, int ones, int twos, int threes, int fours) {
    Flat** paradnaya = new Flat * [floors];
    for (size_t i = 0; i < floors; i++)
    {

        paradnaya[i] = GenerateFloorOfFlats(floorsSize[i], ones, twos, threes, fours);
    }
    return paradnaya;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));

    int* floorsSize = new int[3];
    Flat** paradnaya = GenerateParadnaya(3, floorsSize, 3, 2, 1, 1);
    PrintParadnaya(paradnaya, 3, floorsSize);

    return 0;
}
