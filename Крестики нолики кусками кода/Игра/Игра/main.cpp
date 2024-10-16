//
//  main.cpp
//  Игра
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
using namespace std;

// ПЛАН

// главная функция, которая определяет победил ли какой-то игрок,
// в зависимости от его кода >> [1] или [2] >> x или o
bool isWinnerInString(int array[3][3], int code) {
    for (size_t i = 0; i < 3; i++)
    {
        if(array[i][0] == code && array[i][1] == code && array[i][2] == code)
            return true;
    }
    return false;
}

bool isWinnerInColumns(int array[3][3], int code) {
    for (size_t i = 0; i < 3; i++)
        if (array[0][i] == code && array[1][i] == code && array[2][i] == code)
        return true;
    return false;
}

bool isWinnerInDiagonals(int array[3][3], int code) {
    return (array[0][0] == code && array[1][1] == code && array[2][2] == code) ||
           (array[0][2] == code && array[1][1] == code && array[2][0] == code);
}


bool isWinner(int array[3][3], int code) {
    return isWinnerInString(array, code) || isWinnerInColumns(array, code) || isWinnerInDiagonals(array, code);
}

int main() {
    int noWinner[3][3]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int OneWinnerInString[3][3]{{1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
    int OneWinnerInColumn[3][3]{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    int OneWinnerInDiagonal[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int TwoWinnerInString[3][3]{{0, 0, 0}, {0, 0, 0}, {2, 2, 2}};

    cout << "one winner in string is " << isWinner(OneWinnerInString, 1) << endl;
    cout << "one winner in column is " << isWinner(OneWinnerInColumn, 1) << endl;
    cout << "one winner in diagonal is " << isWinner(OneWinnerInDiagonal, 1) << endl;
    cout << "no winner is " << isWinner(noWinner, 1) << endl;
    cout << "two winner in string is " << isWinner(TwoWinnerInString, 2) << endl;
}
