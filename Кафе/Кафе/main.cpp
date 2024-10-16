//
//  main.cpp
//  Кафе
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Меню
    map<string, int> menu = {{"кофе", 30}, {"чай", 20}, {"торт", 100}};
    int people;

    cout << "Введите количество людей: ";
    cin >> people;

    int total = 0;
    for (int i = 0; i < people; ++i) {
        cout << "Меню: " << endl;
        for (auto& item : menu) {
            cout << item.first << " - " << item.second << " руб." << endl;
        }

        cout << "Введите свои заказы (например, кофе): ";
        string order;
        cin >> order;

        for (char& item : order) {
            item = tolower(item);
        }

        int sum = 0;
        for (char& item : order) {
            if (menu.count(string(1, item))) {
                sum += menu[string(1, item)];
            }
        }
        total += sum;
        cout << "Ваш заказ: " << sum << " руб." << endl;
    }

    cout << "Общая сумма заказа: " << total << " руб." << endl;

    return 0;
}
