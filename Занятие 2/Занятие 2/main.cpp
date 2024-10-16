//
//  main.cpp
//  Занятие 2
//
//  Created by Станислав Егоров on 23.10.2023.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int sizeX = 15;
    int sizeY = 10;
    int x[sizeX][sizeY];
    
    // заполянем массив
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++) {
            x[i][j] = rand() % -100 + 1000;
        }
    }

    // выводим массив
    for (int i = 0; i < sizeX; i++)
    {
        for(int j=0; j < sizeY; j++) {
            printf("%3d ", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}
