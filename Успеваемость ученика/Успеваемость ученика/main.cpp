//
//  main.cpp
//  Успеваемость ученика
//
//  Created by Станислав Егоров on 25.10.2023.
//

/*
Написать программу «успеваемость».

Пользователь вводит 10 оценок студента.
Реализовать меню для пользователя

■ Вывод оценок (вывод содержимого массива);
■ Пересдача экзамена (пользователь вводит номер эле-
мента массива и новую оценку);
■ Выходит ли стипендия (стипендия выходит, если
средний бал не ниже 4.7).
*/

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int marks[10];
    int choice = 0;
    int index = 0;
    int newMark = 0;
    double summ = 0;
    bool goOut = false;
    bool hasScholarship = false;
    
    for (int i = 0; i < 10; i++) {
        printf("Введите %d оценку: ", i);
        cin >> marks[i];
    }
    while (true) {
        printf("[1] - вывод оценок\n[2] - исправить оценку\n[3] - будет ли стипендия\n[4] - выход\nВаш выбор: ");
        cin >> choice;
        
        switch (choice) {
            case 1:
                for(int i = 0; i < 10; i++)
                    printf("%d \n", marks[i]);
                break;
            case 2:
                printf("Какую оценку вы хотите исправить: ");
                cin >> index;
                printf("На какую оценку исправить: ");
                cin >> newMark;
                marks[index] = newMark;
                printf("Теперь оценка с индексом %d: %d\n", index, marks[index]);
                break;
            case 3:
                // средняя оценка больше чем 4.7
                for(int i = 0; i < 10; i++){
                    summ += marks[i];
                }
                hasScholarship = summ / 10 > 4.7;
                printf("Стипендия %sбудет выплачена\n", hasScholarship ? "" : "не ");
                break;
            case 4:
                goOut = true;
                break;
            default:
                printf("Вы должны были ввести 1, 2 или 3, а ввели %d.\n", choice);
                break;
        }
        if(goOut)
            break;
    }
}
