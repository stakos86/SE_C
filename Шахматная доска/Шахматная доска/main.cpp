//
//  main.cpp
//  Шахматная доска
//
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите размер клетки: ";
    cin >> n;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                cout << "X";
            } else {
                cout << "-";
            }
            cout << setw (n);
        }
        cout << endl;
    }

    return 0;
}
