//
//  main.cpp
//  Работа в классе 4
//
//  Created by Станислав Егоров on 15.01.2024.
//

/*
 #include <iostream>
 #include <string>
 using namespace std;
 
 int main() {
 int choice;
 
 while (true) {
 cout << "ещё раз?\n[1] - да | [2] - нет\n";
 cin >> choice;
 
 if (cin.fail()) {
 char invalidinput[256];
 cin.clear();
 cin.getline(invalidinput, 256);
 cout << "ошибка! вы ввели \"" << invalidinput << "\", а нужно было ввести 1 или 2.\n";
 continue;
 }
 
 if (choice == 1) {
 cout << "введите целое число от 1 до 50: ";
 int num;
 cin >> num;
 
 if (cin.fail() || num < 1 || num > 50) {
 cout << "ошибка! введено некорректное число.\n";
 continue;
 }
 
 cout << "введите строку для повторения: ";
 string str;
 cin.ignore();
 getline(::cin, str);
 
 for (int i = 0; i < num; ++i) {
 cout << str << "\n";
 }
 } else if (choice == 2) {
 cout << "сообщение: программа закончена. выход из программы.\n";
 break;
 } else {
 cout << "ошибка! вы ввели " << choice << ", а нужно было 1 или 2.\n";
 }
 }
 
 return 0;
 }
 */
/*
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Apartment {
    int numberOfRooms;
    double area;
    int number;
    int people;
    bool hasBalcony;
};

void printApartmentDetails(const Apartment& apt) {
    std::cout << "количество комнат: " << apt.numberOfRooms << std::endl;
    std::cout << "метраж: " << apt.area << " квадратных метров" << std::endl;
    std::cout << "номер: " << apt.number << std::endl;
    std::cout << "количество жильцов: " << apt.people << std::endl;
    std::cout << "наличие балкона: " << (apt.hasBalcony ? "да" : "нет") << std::endl;
}

void setNumberOfRooms(Apartment& apt, int numberOfRooms) {
    apt.numberOfRooms = numberOfRooms;
}

int getNumberOfRooms(const Apartment& apt) {
    return apt.numberOfRooms;
}

void setArea(Apartment& apt, double area) {
    apt.area = area;
}

double getArea(const Apartment& apt) {
    return apt.area;
}

void setNumber(Apartment& apt, int number) {
    apt.number = number;
}

int getNumber(const Apartment& apt) {
    return apt.number;
}

void setNumberOfPeople(Apartment& apt, int numberOfTenants) {
    apt.people = numberOfTenants;
}

int getNumberOfPeople(const Apartment& apt) {
    return apt.people;
}

void setHasBalcony(Apartment& apt, bool hasBalcony) {
    apt.hasBalcony = hasBalcony;
}

bool getHasBalcony(const Apartment& apt) {
    return apt.hasBalcony;
}

Apartment generateApartment() {
    Apartment apt;
    
    srand(static_cast<unsigned int>(time(0)));
    
    apt.numberOfRooms = rand() % 5 + 1;
    apt.area = (rand() % 100 + 1);
    apt.number = rand() % 100 + 1;
    apt.people = rand() % 3 + 1;
    apt.hasBalcony = rand() % 2 == 0;
    
    return apt;
}


int main() {
    Apartment apt;

    setNumberOfRooms(apt, 3);
    setArea(apt, 75.5);
    setNumber(apt, 101);
    setNumberOfPeople(apt, 2);
    setHasBalcony(apt, true);

    printApartmentDetails(apt);
    
    Apartment randomApt = generateApartment();
        
        std::cout << "\nСгенерированная квартира:\n";
    printApartmentDetails(randomApt);

        return 0;
    }
*/

/*
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

string MaleNames[5] = { "Александр", "Михаил", "Максим", "Артём", "Лев" };
string FemaleNames[5] = { "Софья", "Мария", "Ева", "Виктория", "Анна" };
string MaleSurnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов",
                        "Лебедев", "Козлов", "Новиков", "Морозов", "Петров" };
enum GenderType {
    male,   // 0 - false
    female, // 1 - true
    totalGender
};
string GenderStrings[2] = { "Male", "Female" };

struct Human {
    double mHeight{ 0 };        // member height
    double mWeight{ 0 };        // member weight
    string mName{ "" };        // member name
    string mSurname{ "" };        // member name
    GenderType mGender{ male };

    // getter and setter
    double Height() { return mHeight; }             // <--- getter

    void Height(double value) { mHeight = value; }  // <--- setter
    double Weight() { return mWeight; }             // <--- getter
    void Weight(double value) { mWeight = value; }  // <--- setter
    string Name() { return mName; }                 // <--- getter
    void Name(string value) { mName = value; }      // <--- setter
    string Surname() { return mSurname; }                 // <--- getter
    void Surname(string value) { mSurname = value; }      // <--- setter
    GenderType Gender() { return mGender; }
    void Gender(GenderType value) { mGender = value; }

    //--- string functions
    string WeightString() {
        std::ostringstream ss;
        ss << mWeight;
        return ss.str();
    }
    string HeightString() {
        std::ostringstream ss;
        ss << mHeight;
        return ss.str();
    }

    //--- conditional functions
    bool IsMale() { return mGender == male; }
    bool IsFemale() { return mGender = female; }

    //--- get string function
    string GetString() {
        // Фамилия Имя | вес: 90 кг | рост: 175 см
        string result = Surname() + " " + Name() +
            " | вес: " + WeightString() +
            " кг | рост: " + HeightString() +
            " см | пол: " + GenderStrings[Gender()];
        return result;
    }
    //--- print function
    void Print() {
        std::cout << GetString();
    }
};

Human GenerateHuman() {
    GenderType gender = rand() % 2 ? female : male; // rand() %2 вернёт либо 0 либо 1, в случае 0 будет male, 1 - female
    string name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
    string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "a";
    double height = rand() % 40 + 140;
    double weight = rand() % 40 + 80;

    Human human{ height, weight, name, surname, gender };
    return human;
}

void fillHumanArray(vector<Human>& humanArray, int size)
{
    for (int i = 0; i < size; i++)
        humanArray.push_back(GenerateHuman());
}

void printHumanArray(vector<Human>& humanArray)
{
    for (Human human : humanArray)
        cout << human.GetString() << endl;
}

double AverageWeight(vector<Human>& humanArray) {
    double result = 0;

    for (Human human : humanArray)
        result += human.Weight();

    result /= humanArray.size();
    return result;
}

double AverageHeight(vector<Human>& humanArray) {
    double result = 0;

    for (Human human : humanArray)
        result += human.Height();

    result /= humanArray.size();
    return result;
}

int main()
{
    srand(time(0)); // <--- настройка генератора случайных чисел
    setlocale(LC_ALL, "");

    cout << "Enter amount of people: ";
    int size = 0;
    cin >> size;

    vector<Human> humanArray;

    fillHumanArray(humanArray, size);
    printHumanArray(humanArray);
    cout << "\nСредний вес: " << AverageWeight(humanArray);
    cout << "\nСредний рост: " << AverageHeight(humanArray);
}
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int generaterandomint() {
    srand(time(0));

    int randomNumber = rand();

    return randomNumber;
}

int main() {
    int randomInt = generaterandomint();
    std::cout << "Случайное число: " << randomInt << std::endl;

    return 0;
}
