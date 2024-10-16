//
//  main.cpp
//  Классная работа 18.03.24
//
//  Created by Станислав Егоров on 18.03.2024.
//

/*
 Опишите любой класс со статической переменной. Инициализируйте её, и выведите на экран.
 */
/*
#include <iostream>
using namespace std;

class MyClass {
public:
    static int staticVar;

    MyClass() {
        
    }
};

int MyClass::staticVar = 10;

int main() {
    cout << "Значение статической переменной: " << MyClass::staticVar << endl;
    return 0;
}
*/

/*
 Создайте пространство имён Polite, с функцией Print, которая на вход принимает строку и вы водит её как часть строки Hello sir, this is what I'd like to print: str

 Также создайте пространство имён NotPolite, с функцией Print, которая на вход принимает строку и выводит её как часть строки Here is your string, pal: str

 В main()  вызовите обе функции,
 */
/*
#include <iostream>

namespace polite {
    void print(const std::string& str) {
        std::cout << "Hello sir, this is what I'd like to print: " << str << std::endl;
    }
}

namespace notpolite {
    void print(const std::string& str) {
        std::cout << "Here is your string, pal: " << str << std::endl;
    }
}

int main() {
    std::string str = "Hello, world!";
    polite::print(str);
    notpolite::print(str);
    
    return 0;
}
*/

#include <iostream>
#include <fstream>

namespace DataStorage {
    // Функция сохраняет данные в файл
    void save(std::string data) {
        std::ofstream file("data.txt");
    }

    // Функция ищет значение в файле или базе данных
void find(std::string value) {
    std::ifstream file("data.txt");
    }

    // Функция читает данные из файла или базы данных
    void read() {
        std::ifstream file("data.txt");
    }
}
namespace DataStorage2 {
    // Функция сохраняет данные в файл
    void save() {
    }

    // Функция ищет значение в файле или базе данных
void find() {
    }

    // Функция читает данные из файла или базы данных
    void read() {
    }
}

int main() {
    using namespace DataStorage;
    using namespace DataStorage2;
    DataStorage::save("Hello, World!");
    DataStorage::read();
    DataStorage::find("World");
    DataStorage2::save("Hello, World!");
    DataStorage2::read();
    DataStorage2::find("World");

    return 0;
}
