//
//  main.cpp
//  Меню
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
#include <ctime>
using namespace std;

int randomDigit(int limit, int shift = 0) {
    return rand() % limit + shift;
}

int randomPlayerChoice(int limit, int shift) {
    cout << "Вы выбрали случайный выбор. Мы сгенерируем случайное число от " << shift <<
            " до " << limit + shift << endl;
    int playerScore = randomDigit(limit, shift);
    int computerScore = randomDigit(limit, shift);

    cout << "У пользователя выпало: " << playerScore << endl;
    cout << "У компьютера выпало: " << computerScore << endl;

    int result = playerScore > computerScore ? 1 : 2;
    string resultStr = playerScore > computerScore ? "пользователь" : "компьютер";
    cout << "Значит первым ходит: " << resultStr;
    return result;
}

int gameMenu(int limit, int shift) {
    int choice = 0;
    cout << "Кто ходит первым: \n\n" <<
            "[1] - пользователь\n" <<
            "[2] - компьютер\n" <<
            "[3] - случайный выбор\n" <<
            "[0] - выход\n\n"
            "Ваш вариант: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Ходит пользователь.";
        return 1;
        break;
    case 2:
        cout << "Ходит компьютер.";
        return 2;
        break;
    case 3:
        return randomPlayerChoice(100, 0);
        break;
    case 0:
        return 0;
    default:
        cout << "Мы просили ввести 0, 1, 2 или 3 ,а вы ввели " << choice <<
                "\nКонец программы.";
        break;
    }
    return 0;
}

int main() {
    srand(time(0));
    gameMenu(100, 0);
}
