//
//  main.cpp
//  Справочник
//
//  Created by Станислав Егоров on 30.10.2023.
//

#include <iostream>
#include <algorithm>
using namespace std;

// Функция для сортировки массива
void sortArray(int array[], int size) {
    // Используем встроенную функцию sort для сортировки массива по возрастанию
    sort(array, array + size);
}

// Функция для вывода данных
void printData(int mobileNumbers[], int homeNumbers[], int size) {
    cout << "Мобильные номера: ";
    for (int i = 0; i < size; i++) {
        cout << mobileNumbers[i] << " ";
    }
    cout << endl;
    
    cout << "Домашние номера: ";
    for (int i = 0; i < size; i++) {
        cout << homeNumbers[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Введите количество контактов: ";
    cin >> size;
    
    int mobileNumbers[size];
    int homeNumbers[size];
    
    // Ввод номеров телефонов
    for (int i = 0; i < size; i++) {
        cout << "Введите мобильный номер для контакта " << i + 1 << ": ";
        cin >> mobileNumbers[i];
        
        cout << "Введите домашний номер для контакта " << i + 1 << ": ";
        cin >> homeNumbers[i];
    }
    
    int option;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Отсортировать по номерам мобильных" << endl;
        cout << "2. Отсортировать по домашним номерам телефонов" << endl;
        cout << "3. Вывести данные" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите опцию: ";
        cin >> option;
        
        switch (option) {
            case 1:
                sortArray(mobileNumbers, size);
                cout << "Массив с номерами мобильных отсортирован." << endl;
                break;
                
            case 2:
                sortArray(homeNumbers, size);
                cout << "Массив с номерами домашних телефонов отсортирован." << endl;
                break;
                
            case 3:
                printData(mobileNumbers, homeNumbers, size);
                break;
                
            case 4:
                cout << "Программа завершена." << endl;
                return 0;
                
            default:
                cout << "Выберите опцию из меню." << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}
