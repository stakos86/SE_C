//
//  main.cpp
//  Морской бой
//
//  Created by Станислав Егоров on 06.11.2023.
//

/*
 #include <iostream>
#include <iomanip>
using namespace std;
void tablica(const int a, const int b, char c, int d, const int x, const int y, const int oldX, const int oldY) {
    cout << '%';
    for (int i = 1; i < b; ++i) {
        cout << setw(3) << c;
        ++c;
    }
    for (int i = 1; i < b; ++i) {
        cout << endl << d;
        ++d;
        for (int z = 1; z < a; z++) {
            if ((z == x && i == y) || (z == oldX && i == oldY)) cout << setw(3) << 'X';
            else cout << setw(3) << '.';
        }
    }
}

int main() {
    int q, q1;
    const int a = 10, b = 10, d = 1;
    char c = 'A';
    while (cin >> q >> q1 && (q != 0 || q1 != 0) && q < a && q1 < b) {
        static int x = q, y = q1;
        tablica(a, b, c , d, x, y, q, q1);
    }
    return 0;
}

#include <string>

void InputControl(std::string input) {
    if (input.length() == 2 &&
        input[0] >= 'A' && input[0] <= 'H' &&
        input[1] >= '1' && input[1] <= '8') {}
    else 
    if (input == "s" || input == "stop") {
    }
    else
    if (input == "q" || input == "quit") {
    }
    else
    if (input == "n" || input == "new") {
    }
    else {
    }
}
*/

#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
 
using namespace std;
 
const int N = 10;
int my_map[N][N] = {0};
char comp_map[N][N] = {0};
int x, y;
 
 
void  setup()
{
    srand(time(0));
    //Размещение однопалубных кораблей
    for (int i = 0; i < 4; i++)
        {
            x = rand() % N;
            y = rand() % N;
            comp_map[x][y] = 98;
        }
 
}
 
void draw()
{
    //Отрисовка моего поля
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (my_map[j][i]==0)
            {
                cout << "-";
            }
            else
            {
                cout << my_map[j][i];
            }
        }
        cout << endl;
    }
    cout << endl;
 
    //Отрисовка поля для компа
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (comp_map[j][i] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << comp_map[j][i];
            }
        }
        cout << endl;
    }
}
 
void logic()
{
    //Стрельба по однопалубным кораблям
    while (true)
    {
        cout << "Введите координаты вражеского корабля по оси X" << endl;
        cin >> x;
        cout << "Введите координаты вражеского корабля по оси Y" << endl;
        cin >> y;
 
        if (comp_map[x][y] == 98)
        {
            cout << "Попал." << endl;
            comp_map[x][y] = 0;
 
            //Счётчик обнаружения кораблей
            bool detect = false;
 
            //Поиск подбитых кораблей
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (comp_map[i][j] == 98)
                    {
                        detect = true;
                    }
                }
            }
 
            //Заканчивает игру
            if (detect == false)
            {
                cout << "вы победили!!" << endl;
                break;
            }
            //cout << detect;
        }
        else
        {
            cout << "Промах." << endl;
        }
        
    }
}
 
void input()
{
    
}
 
void main()
{
    setlocale(LC_ALL, "rus");
 
    setup();
    draw();
    logic();
}
