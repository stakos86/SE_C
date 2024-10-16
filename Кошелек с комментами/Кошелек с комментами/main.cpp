//
//  main.cpp
//  Кошелек с комментами
//
//  Created by Станислав Егоров on 27.02.2024.
//

#include <iostream> // Включение стандартного потока ввода-вывода
#include <string>   // Включение поддержки строк
#include <sstream>  // Включение поддержки строковых потоков

using namespace std; // Использование пространства имен std для упрощения кода

// Определение структуры SWallet
struct SWallet {
    // Поля структуры
    string mName; // Имя кошелька
    double mAmount; // Сумма в кошельке

    // Функция для преобразования числа в строку
    string Stringify(double value) {
        ostringstream ss; // Создание строкового потока
        ss << value; // Запись значения в поток
        return ss.str(); // Возвращение строки из потока
    }

    // Геттеры и сеттеры для полей
    void Name(string value) { mName = value; } // Сеттер для имени
    string Name() { return mName; } // Геттер для имени
    void Amount(double value) { mAmount = value; } // Сеттер для суммы
    double Amount() { return mAmount; } // Геттер для суммы
    string AmountString() { return Stringify(Amount()); } // Преобразование суммы в строку
    void AmountChangeBy(double value) { mAmount += value; } // Изменение суммы на заданное значение
    string GetString() { return Name() + ": " + AmountString(); } // Получение строкового представления кошелька

    // Вывод информации о кошельке
    void Print() { cout << GetString() << "\n"; }

    // Перевод средств между кошельками
    void TransfetTo(double amount, SWallet& to) {
        if (Amount() < amount) {
            cout << "Not enough money for transfer. Exitting..";
            return;
        }
        AmountChangeBy(-amount);
        to.AmountChangeBy(amount);
    }

    void TransferFrom(double amount, SWallet& from) {
        if (from.Amount() < amount) {
            cout << "Not enough money for transfer. Exitting..";
            return;
        }
        from.AmountChangeBy(-amount);
        AmountChangeBy(amount);
    }
};

// Функция для перевода средств между кошельками
void TransferFunds(double amount, SWallet& from, SWallet& to) {
    if (from.Amount() < amount) {
        cout << "Not enough money for transfer. Exitting..";
        return;
    }
    from.AmountChangeBy(-amount);
    to.AmountChangeBy(amount);
}

// Функция для создания нового кошелька
SWallet* CreateWallet(string name, double amount) {
    SWallet* result = new SWallet; // Создание нового кошелька
    result->Name(name); // Установка имени
    result->Amount(amount); // Установка суммы
    return result; // Возвращение указателя на кошелек
}

int main() {
    // Создание двух кошельков
    SWallet* walletOne = CreateWallet("Zarplata",  1000);
    SWallet* walletTwo = CreateWallet("Zanachka",  50000);

    // Вывод информации о кошельках
    walletOne->Print();
    walletTwo->Print();

    // Перевод  200 единиц из walletOne в walletTwo
    cout << "\nTrasferring  200 from walletOne to walletTwo\n";
    walletOne->TransfetTo(200, *walletTwo);

    // Вывод обновленной информации о кошельках
    walletOne->Print();
    walletTwo->Print();

    // Перевод  1000 единиц из walletTwo в walletOne
    cout << "\nTrasferring  1000 from walletTwo to walletOne\n";
    TransferFunds(1000, *walletTwo, *walletOne);

    // Вывод обновленной информации о кошельках
    walletOne->Print();
    walletTwo->Print();
}
