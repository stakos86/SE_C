//
//  main.cpp
//  1
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>
#include <string>

enum class Gender {
    male,
    female
};

class Human {
private:
    std::string name;
    std::string surname;
    int age;
    Gender sex;

public:
    Human () {}
    
    Human (const std::string& name, const std::string& surname, int age, Gender sex)
    : name (name), surname (surname), age (age), sex (sex) {}
    
    Human (const Human& other)
        : name(other.name), surname(other.surname), age(other.age), sex(other.sex) {}
    
    std::string getName () const {
        return name;
    }
    
    void setName (const std::string& newName) {
        name = newName;
    }
    
    std::string getSurname() const {
        return surname;
    }
    
    void setSurname (const std::string& newSurname) {
        surname = newSurname;
    }
    
    int getAge () const {
        return age;
    }
    
    void setAge (int newAge) {
        age = newAge;
    }
    
    Gender getSex () const {
        return sex;
    }
    
    std::string getString() const {
        std::string result = "Name: " + name + "\n";
        result += "Surname: " + surname + "\n";
        result += "Age: " + std::to_string(age) + "\n";
        result += "Sex: ";
        if (sex == Gender::male) {
            result += "Male";
        } else {
            result += "Female";
        }
        return result;
    }
    
    void print() const {
        std::cout << getString() << std::endl;
    }
};

int main() {
    Human person1 ("Sarah", "Connor", 30, Gender::female);
    Human person2 ("Sasha", "Grey", 25, Gender::female);
    Human person3 (person2);
    Human person4 ("John", "Connor", 15, Gender:: male);
    
    person1.print();
    person2.print();
    person3.print();
    person4.print();
    
    return 0;
}
