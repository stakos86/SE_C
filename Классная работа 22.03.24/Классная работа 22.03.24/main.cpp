#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;
//Максимальная длина пути к файлу
#define MAX_PATH 260
//Количество столбцов на экране
#define NUM_COLS 18
//Количество строк на экране
#define NUM_ROWS 24
int main()
{
    char path[MAX_PATH];
    //Запрашиваем путь к файлу
    cout << "Input path to file: ";
    cin.getline(path, MAX_PATH);
    int counter = 0, i = 0, j = 0;
    char text[NUM_COLS];
    //Открытие файла в двоичном режиме
    ifstream input(path, ios::in | ios::binary);
    if (!input)
    {
        cout << "Cannot open file for display!" << endl;
        return;
    }
    //Режим отображения в верхнем регистре для
    //шестнадцатиричного вывода
    cout.setf(ios::uppercase);
    //Пока не конец файла, читаем из него данные
    //и производим форматированный вывод на экран
    while (!input.eof())
    {
        //Посимвольное чтение
        for (i = 0; (i < NUM_COLS && !input.eof()); i++)
            input.get(text[i]);
        if (i < NUM_COLS)
            i--;
        for (j = 0; j < i; j++)
            if ((unsigned)text[j] < 0x10)
                //Количество символов для отображения числа
                //меньше двух?
                cout << setw(2) << 0 << hex << (unsigned)text[j];
            else
                cout << setw(3) << hex << (unsigned)text[j];
        //Выравнивание для незавершенной строки
        for (; j < NUM_COLS; j++)
            cout << " ";
        cout << "\t";
        for (j = 0; j < i; j++)
            //Символ не является управляющим?
            if (text[j] > 31 && text[j] <= 255)
                cout << text[j];
            else
                cout << ".";
        cout << "\n";
        //Если экран уже заполнен,
        //производим остановку
        if (++counter == NUM_ROWS)
        {
            counter = 0;
            cout << "Press any key to continue..." <<
                flush;
            //Ожидаем нажатия любой клавиши
            getch();
            cout << "\n";
        }
    }
    //Закрываем файл
    input.close();
}
