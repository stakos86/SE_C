//
//  main.cpp
//  Двумерный массив с заполнением 2
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    
    int arr[n][n];
    int num;
    cout << "Введите число: ";
    cin >> num;
    
    // Заполнение массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = num;
            num++;
        }
    }
    
    // Вывод массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
