//
//  main.cpp
//  Двумерный массив с максимальным элементом
//
//  Created by Станислав Егоров on 25.10.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

int main()
{
    srand(time(0));
    int sizeX = 10;
    int sizeY = 10;
    
    int x[sizeX][sizeY];
    
    // заполянем массив
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++) {
            x[i][j] = rand() % 10000 + 10000;
        }
    }
    int maxdigit = x[0][0];


    // выводим массив
    for (int i = 0; i < sizeX; i++)
    {
        maxdigit = INT_MIN;
        for(int j=0; j < sizeY; j++) {
            printf("%3d ", x[i][j]);
            if(x[i][j]>maxdigit)
            {
                maxdigit = x[i][j];
            }
                
            }
        cout << " | " << maxdigit << endl;;
        }
            
        
    }
