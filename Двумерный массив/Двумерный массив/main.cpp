//
//  main.cpp
//  Двумерный массив
//
//  Created by Станислав Егоров on 23.10.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
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
            x[i][j] = rand() % 100 + 100;
        }
    }
    int mindigit = x[0][0];
    int maxdigit = x[0][0];
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int index4 = 0;

    // выводим массив
    for (int i = 0; i < sizeX; i++)
    {
        for(int j=0; j < sizeY; j++) {
            printf("%3d ", x[i][j]);
            if(x[i][j]>maxdigit)
            {
                maxdigit = x[i][j];
                index1 = i;
                index2 = j;
                
        }
            if(x[i][j]<mindigit)
            {
                mindigit = x[i][j];
                index3 = i;
                index4 = j;
                
            }
       
        }
        printf("\n");
            
        
    }
    cout << "Наибольшее число: " << maxdigit << "\n" << "Расположение: " << index1 << ":" << index2 << endl;
    cout << "Наименьшее число: " << mindigit << "\n" << "Расположение: " << index3 << ":" << index4 << endl;
    return 0;
}
