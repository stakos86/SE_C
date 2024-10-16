/*
Создать функцию, которая
1. на вход принимает 4 целочисленных переменных: кол-во однокомнатных, двухкомнатных, трехкомнатных и четырехкомнатных квартир и ссылку на массив из квартир и
2. наполняет массив случайными квартирами, которые будут в указанном количестве с указанным количеством квартир.
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

void GenerateFlat(Flat& flat, bool toPrint = false, int amountOfRooms = 0) {
    flat.mAmountOfRooms = amountOfRooms == 0 ? rand() % 5 : amountOfRooms;
    flat.mSquareFootage = rand() % 30 + 100;
    flat.mNumber = rand() % 90;
    flat.mResidents = rand() % 10;
    flat.mBalcony = rand() % 2 ? true : false;
    if (toPrint)
        flat.PrintFlat();
}

Flat* GenerateFloorOfFlats(int Ones, int Twos, int Threes, int Fours, bool toPrint = false) {
    int size = Ones + Twos + Threes + Fours;
    Flat* result = new Flat[size];
    for (size_t i = 0; i < size; i++)
    {
        int amount = i < Ones ? 1 : i < Ones + Twos ? 2 : i < Ones + Twos + Threes ? 3 : 4;
        GenerateFlat(result[i], toPrint, amount);
    }
    return result;
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    Flat* flats = GenerateFloorOfFlats(2, 0, 2, 0);

    return 0;
}
