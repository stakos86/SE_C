//
//  main.cpp
//  Студент
//
//  Created by Станислав Егоров on 29.01.2024.
//
/*
 Реализуйте класс “Студент”.

 Необходимо хранить в переменных-членах класса:
 ФИО,
 дату рождения,
 контактный телефон,
 город,
 страну,
 название учебного заведения,
 номер группы.

 Реализуйте функции-члены класса для
 ввода данных,
 вывода данных,
 реализуйте аксессоры для доступа к отдельным переменным-членам
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string fio;
    string birthDate;
    string phoneNumber;
    string city;
    string country;
    string university;
    string groupNumber;

public:

    void inputData() {
        cout << "Введите ФИО: ";
        cin >> fio;
        cout << "Введите дату рождения: ";
        cin >> birthDate;
        cout << "Введите контактный телефон: ";
        cin >> phoneNumber;
        cout << "Введите город: ";
        cin >> city;
        cout << "Введите страну: ";
        cin >> country;
        cout << "Введите название университета: ";
        cin >> university;
        cout << "Введите номер группы: ";
        cin >> groupNumber;
    }


    void outputData() {
        cout << "ФИО: " << fio << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Контактный телефон: " << phoneNumber << endl;
        cout << "Город: " << city << endl;
        cout << "Страна: " << country << endl;
        cout << "Университет: " << university << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }
    
    string getfio() { return fio; }
    string getBirthDate() { return birthDate; }
    string getPhoneNumber() { return phoneNumber; }
    string getCity() { return city; }
    string getCountry() { return country; }
    string getUniversity() { return university; }
    string getGroupNumber() { return groupNumber; }
    string PH = phoneNumber;
    
    void setphonenumber (string value){
        phoneNumber = value;
    }
    
};

int main() {
    Student student;
    student.inputData();
    student.outputData();
    //student.setphonenumber("234567890");
    cout << student.getPhoneNumber();
    
    return 0;
}
