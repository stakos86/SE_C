//
//  main.cpp
//  Работа в классе 03.04.24
//
//  Created by Станислав Егоров on 03.04.2024.
//

/*
 2024.04.03.01
 
 Создайте класс Human с полями Name и Surname типа string, Age типа int, Sex(пол) типа EnumMaleFemale {Male, Female}.

 В классе должны быть описаны все геттеры и сеттеры, пустой конструктор, параметризированный конструктор, конструктор копирования (тот что принимает на вход объект типа Human), должен быть метод GetString() - формирующий строку описания человека со всеми параметрами, и метод Print( )который выводит строку GetString на экран

 Создать в программе трёх случайных людей и вывести их на экран.
 
 Задача 2024.04.03.02
 
 В описанный выше класс добавьте счётчик всех людей, чтобы он был доступен каждому человеку и увеличивался на 1 при создании каждого человека. И геттер для него.
 
 Также всевозможные константные методы опишите константными.

 В программе после создания трёх случайных людей выведите на экран текущее значение количества созданных на данный момент людей.

 */

//#include <iostream>
//#include <string>
//
//enum class Gender {
//    male,
//    female
//};
//
//class Human {
//private:
//    std::string name;
//    std::string surname;
//    int age;
//    Gender sex;
//    static int counter;
//
//public:
//    Human () {}
//    
//    Human (const std::string& name, const std::string& surname, int age, Gender sex)
//    : name (name), surname (surname), age (age), sex (sex) {
//        ++ counter;
//    }
//    
//    Human (const Human& other)
//        : name(other.name), surname(other.surname), age(other.age), sex(other.sex) {
//            ++ counter;
//        }
//    
//    static int getCounter() {
//            return counter;
//        }
//    
//    std::string getName () const {
//        return name;
//    }
//    
//    void setName (const std::string& newName) {
//        name = newName;
//    }
//    
//    std::string getSurname() const {
//        return surname;
//    }
//    
//    void setSurname (const std::string& newSurname) {
//        surname = newSurname;
//    }
//    
//    int getAge () const {
//        return age;
//    }
//    
//    void setAge (int newAge) {
//        age = newAge;
//    }
//    
//    Gender getSex () const {
//        return sex;
//    }
//    
//    std::string getString() const {
//        std::string result = "Name: " + name + "\n";
//        result += "Surname: " + surname + "\n";
//        result += "Age: " + std::to_string(age) + "\n";
//        result += "Sex: ";
//        if (sex == Gender::male) {
//            result += "Male";
//        } else {
//            result += "Female";
//        }
//        return result;
//    }
//    
//    void print() const {
//        std::cout << getString() << std::endl;
//    }
//};
//
//int Human::counter = 0;
//
//int main() {
//    Human person1 ("Sarah", "Connor", 30, Gender::female);
//    Human person2 ("Sasha", "Grey", 25, Gender::female);
//    Human person3 (person2);
//    Human person4 ("John", "Connor", 15, Gender:: male);
//    std::cout << "Current number of created persons: " << Human::getCounter() << std::endl;
//    
//    person1.print();
//    person2.print();
//    person3.print();
//    person4.print();
//    
//    return 0;
//}

/*
 Задача 2024.04.03.03
 Опишите класс DoubleValue, у которого одно поле double mValue, описать его геттер и сеттер, пустой конструктор со значением по умолчанию, равным 0, параметризированный и конструктор копирования.

 А также перегрузите для него операторы +, -, *, /, <, >, == и <<

 В программе создайте два DoubleValue.

 Выведите на экран их сумму, разность, произведение и частное, а также сравнение >, < и ==

 */

#include <iostream>

class doublevalue {
private:
    double mvalue;
    
public:
    // Default constructor
    doublevalue() : mvalue(0) {}
    
    // Parameterized constructor
    doublevalue(double value) : mvalue(value) {}
    
    // Copy constructor
    doublevalue(const doublevalue& other) : mvalue(other.mvalue) {}
    
    // Getter
    double getValue() const {
        return mvalue;
    }
    
    // Setter
    void setValue(double value) {
        mvalue = value;
    }
    
    // Overloading + operator
    doublevalue operator+(const doublevalue& other) const {
        doublevalue result(mvalue + other.mvalue);
        return result;
    }
    
    // Overloading - operator
    doublevalue operator-(const doublevalue& other) const {
        doublevalue result(mvalue - other.mvalue);
        return result;
    }
    
    // Overloading * operator
    doublevalue operator*(const doublevalue& other) const {
        doublevalue result(mvalue * other.mvalue);
        return result;
    }
    
    // Overloading / operator
    doublevalue operator/(const doublevalue& other) const {
        if (other.mvalue != 0) {
            doublevalue result(mvalue / other.mvalue);
            return result;
        }
        throw "Division by zero error!";
    }
    
    // Overloading < operator
    bool operator<(const doublevalue& other) const {
        return mvalue < other.mvalue;
    }
    
    // Overloading > operator
    bool operator>(const doublevalue& other) const {
        return mvalue > other.mvalue;
    }
    
    // Overloading == operator
    bool operator==(const doublevalue& other) const {
        return mvalue == other.mvalue;
    }
    
    // Overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const doublevalue& dv) {
        os << dv.mvalue;
        return os;
    }
};

int main() {
    doublevalue dv1(5.5);
    doublevalue dv2(3.7);
    
    // Display the sum
    std::cout << "Sum: " << dv1 + dv2 << std::endl;
    
    // Display the difference
    std::cout << "Difference: " << dv1 - dv2 << std::endl;
    
    // Display the product
    std::cout << "Product: " << dv1 * dv2 << std::endl;
    
    // Display the quotient
    try {
        std::cout << "Quotient: " << dv1 / dv2 << std::endl;
    } catch (const char* error) {
        std::cout << "Error: " << error << std::endl;
    }
    
    // Check if dv1 is greater than dv2
    std::cout << "dv1 > dv2: " << (dv1 > dv2) << std::endl;
    
    // Check if dv1 is less than dv2
    std::cout << "dv1 < dv2: " << (dv1 < dv2) << std::endl;
    
    // Check if dv1 is equal to dv2
    std::cout << "dv1 == dv2: " << (dv1 == dv2) << std::endl;
    
    return 0;
}
