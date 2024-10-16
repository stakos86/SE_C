//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>


using namespace std;

class Tictactoe
{
    char* field;
    int size;
public:
    //конструктор
    Tictactoe(int sies)
    {     size=sies;
              // выделяем память под массив из size указателей на массивы
        field=new char[size*size];
        
    }
    //деструктор
    ~Tictactoe()
    {
        delete[] field;
    }
    // перегрузка оператора [] сделано для более быстрой работы массива при вводе очень большой размерности поля
    // принцип выделения памяти как при создании обычного двумерного массива только без массы циклов
    char* operator[](int row)
    {
        return field+row*size;
    }
    
    // функция вывода поля
    // передаем в функцию наше поле обьявленное в main (оно может называться в маине не только field, в данном случае это та переменная которая использыется только в этой функции)
void print(Tictactoe &field) {

    // очистка экрана
    system("clear");

    // верхняя граница поля
    for (int j = 0; j < size; j++) {
        cout<<"--";

    }
    cout<<"-\n";


    // выводим по очереди все ряды и деления
    for (int i = 0; i < size; i++) {

        // ряд символов
        for (int j = 0; j < size; j++) {
            cout<<"|"<<field [i][j];
        }
            cout<<"|\n";


        // деление
        for (int j = 0; j < size; j++) {
            cout<<"--";
        }
        cout<<"-\n";
    }
}

/*
если один из игроков заполнил всю горизонталь / вертикаль / диагональ,
возвращает символ, которым он играет

если никто еще на заполнил линию, возвращает пробел
*/
// функция проверки на победителя (принцип передачи переменной такой же как и у функции print)
int check(Tictactoe &field) {
    // первый символ по горизонтали и первый по вертикали
    int g, v;
    // диагонали
    int d1, d2;

    // начинается цикл в n заходов, n равно размеру поля
    for (int i = 0; i < size; i++) {
        // ПРОВЕРКА ПО ГОРИЗОНТАЛИ
        // запоминаем символ из начала i строки поля
        g = field[i][0];

        // проходимся по i строке поля
        for (int j = 0; j < size; j++) {
            // если натенемся на несовпадение с первым символом
            // или если первый символ был пробелом, то
            if (field[i][j] != g || g == ' ') {
                // забиваем на проверку, записываем в g символ ' '
                g = ' ';
                // и выходим цикла принудительно
                break;
            }
        }

        // если в g хранится символ, отличный от пробела, это значит что в начале
        // строки был крестик или нолик, и проходя по всей строке (в цикле выше)
        // мы не наткнулись на символ, отличающийся от того, что в начале
        // иными словами, один из игроков заполнил всю строку одним символом
        // и выйграл
        if (g != ' ') {
            // если это условие выполнено, просто возвращаем символ, которым
            // заполнена вся строка
            return g;
        }

        // ПРОВЕРКА ПО ВЕРТИКАЛИ
        // записываем символ из начала i столбца поля
        v = field[0][i];

        // проходим по i столбцу
        for (int j = 0; j < size; j++) {
            // если натенемся на несовпадение с первым символом
            // или если первый символ был пробелом, то
            if (field[j][i] != v || v == ' ') {
                // забиваем на проверку, записываем в v символ ' '
                v = ' ';
                // и выходим цикла принудительно
                break;
            }
        }

        // если в v хранится символ, отличный от пробела, это значит что в начале
        // строки был крестик или нолик, и проходя по всей строке (в цикле выше)
        // мы не наткнулись на символ, отличающийся от того, что в начале
        // иными словами, один из игроков заполнил всю строку одним символом
        // и выйграл
        if (v != ' ') {
            // в таком случае возвращаем этот символ
            // это означает, что игрок с этим символом выйграл
            return v;
        }
    }

    // Записываем, какие символы в начале основной и побочной диагонали
    d1 = field[0][0];
    d2 = field[0][size - 1];

    // проверка по основной диагонали
    // ?##
    // #?#
    // ##?
    for (int i = 0; i < size; i++) {
        // если наткнемся на несовпадение
        if (field[i][i] != d1) {
            // забиваем на проверку, записываем в d1 символ ' '
            d1 = ' ';
            // принудительно выходим их цикла
            break;
        }
    }

    // если все знаки на диагонали одинаковые, и знак не пробел, возвращаем знак
    if (d1 != ' ') {
        return d1;
    }

    // проверка по побочной диагонали
    // ##?
    // #?#
    // ?##
    for (int i = 0; i < size; i++) {
        // если наткнемся на несовпадение
        if (field[i][size - 1 - i] != d2) {
            // забиваем на проверку, записываем в d1 символ ' '
            d2 = ' ';
            // принудительно выходим их цикла
            break;
        }
    }

    // если все знаки на диагонали одинаковые, и знак не пробел, возвращаем знак
    if (d2 != ' ') {
        return d2;
    }

    // если ни одна из полос не заполнена, возвращаем пробел
    return ' ';
}

// функция самой игры  (принцип передачи переменной такой же как и у функции print)
void game(Tictactoe &field)
{
          // текущий игрок
    int player = 'x';

    // результат проверки игрового поля на заполнение полосы
    char result;

    // индикатор работы игры
    int running = 1;

 int i = 0,j = 0;
 bool vvod = true;
    // пока игра продолжается
    while (running) {
        do {
          if(vvod == false){
            cout<<"Повтрорите ввод\n";
          }
            // выводим поле
            field.print(field);

            // выводим чей ход
            if (player == 'x') {
                cout<<"игрок X ходит\n";
            }
            else {
                cout<<"игрок O ходит\n";

            }
        
        
            // вводим координаты хода (от 1 до size)
            cout<<"Введите координаты хода x y (через пробел): ";
            cin >> i >> j;
      
      vvod = false;

            // если пользователь введет что-то неправильно, цикл продолжается
            // и спрашивает заново
            // как только игрок введет координаты правильно, цикл остановится
        } while (i > size || j > size || i < 0 || j < 0 || field[i - 1][j - 1] != ' ');

     vvod = true;
        // зачеркиваем ячейку поля
        field[i - 1][j - 1] = player;

        // проверяем поле
        result = field.check(field);

        // если result не пробел, значит кто-то выйграл
        if (result != ' ') {
            // выводим символ победителя (хранится в result)
            cout<<result<<" выиграл!";

            // останавливаем игру
            running = 0;
        }

        // передаем ход другому игроку
        if (player == 'x') {
            player = 'o';
        }
        else {
            player = 'x';
        }
    }
    
}

};

int main()
{
  setlocale(LC_ALL, "Rus"); // включаем русский язык
  
  int size;
  // вводим размер поля
     cout<<"Введите размер поля: ";
     cin >> size;
  
  // создаем поле(название field, размер size)
  // (для сестренки) тип поля КЛАСС
  Tictactoe field(size);
  
   // заполняем каждую ячейку поля пробелом
    for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++)
                field[i][j] = ' ';
    }
    
    // запускаем игру
    field.game(field);
    
    
  
  return 0;
}
