//
//  main.cpp
//  Работа в классе 01.04.24
//
//  Created by Станислав Егоров on 01.04.2024.
//
/*
 Создать словарь типа <int, int> для хранения номеров квартиры и количества проживающих в них людей.

 Словарь о доме из 100 квартир. В каждой может проживать от 0 до 12 человек.
 */
/*
#include <iostream>
#include <map>
#include <ctime>
using namespace std;

int main()
{
    srand (time(0));
    map <int, int> house;
    for (size_t i = 1; i < 101; i++) {
        house [i] = rand() % 13;
    }
    for (auto [key,value] : house) {
        cout << "квартира: " << key << " | жильцы: " << value << endl;
    }
}
*/

/*
 Прокомментировать код
 */
/*
 #include <iostream>//подключаем библиотеку для ввода и вывода
 #include <map>//подключаем библиотеку для использования структуры словаря
 #include <string>//подключаем библиотеку для работы со строками
 //главная функция
 int main() {
     std::map<std::string, std::string> m;//создание словаря
     m.insert(std::make_pair("f", "++--"));//вносим значения в словарь

     std::string keyToCheck = "f";//объявление и инициализация переменной
     //ищем значение по переменной
     if (m.find(keyToCheck) != m.end()) {//если текущее значение не равно значению конца
         std::cout << "Key is present in the map." << std::endl;//то выводим эту строку
     }
     else {//при ином исходе событий
         std::cout << "Key is not present in the map." << std::endl;//выводим эту строку
     }

     return 0;//ничего не возвращаем
 }
 */
/*
#include <iostream>
#include <map>
#include <string>
bool keyexists(std::map <int, int> m, int k) {
    return m.find(k) != m.end();
}

int main() {
    std::map <int, int> m;
        m.insert (std::make_pair (1, 1000));
        m.insert (std::make_pair (2, 2000));
        
        int keytocheck;
    std::cout << "Че ищем?" << std::endl;
        std::cin >> keytocheck;
        if (keyexists(m, keytocheck)) {
            std::cout << "Все огонь!" << std::endl;
        } else {
            std::cout << "Человек, пробуй еще!" << std::endl;
        }

        return 0;
}
*/
/*
 Создать последовательность из 1000 строчных букв.

 Создать словарь из символов и целых чисел, где будет описано сколько раз какой символ встречается в последовательности.
 */
#include <iostream>
#include <map>
#include <string>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis (97, 122);
    uniform_int_distribution<> disDigits (48, 57);
    string sequence;
       for (int i = 0; i < 1000; ++i) {
           char c = static_cast <char>(disDigits(gen));
           sequence += c;
       }
    
    map <char, int> frequency;
    for (char a : sequence) {
        frequency [a]++;
    }
    
    for (auto it = frequency.begin(); it != frequency.end(); it++) {
        cout << "Символ '" << it->first << "' встречается " << it->second << " раз" << endl;
    }
    
    return 0;
}
