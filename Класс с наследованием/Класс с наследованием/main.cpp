//
//  main.cpp
//  Класс с наследованием
//
//  Created by Станислав Егоров on 06.03.2024.
//
/*
 Создать Класс Batya, у которого всего один метод Do(), который выводит на экран слова Do like Batya

 И создать класс Son, наследник класса Batya, у которого перегружен метод Do() и он выводит на экран слова Do like Son

 В main создать объекты обоих классов и запустить их методы Do()
 В main запустить цикл от 0 до 10, и в нём добавлять в вектор объекты Batya или Son.

 если i - чётное - добавляем Batya, а если не чётное - добавляем Son.

 Для всех 10 элементов потом заустим функцию Do()

 */
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class batya {
public:
    string name;
    batya() {
        name = "batya";
    }
};

class son {
public:
    string name;
    son() {
        name = "son";
    }
};

int main() {
    vector<void*> objects;

    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            batya* b = new batya();
            objects.push_back(b);
        }
        else {
            son* s = new son();
            objects.push_back(s);
        }
    }

    for (int i = 0; i < objects.size(); i++) {
        cout << "[" << i << "]: " << typeid(*objects[i]).name() << " | " << objects[i] << endl;
    }

    return 0;
}
