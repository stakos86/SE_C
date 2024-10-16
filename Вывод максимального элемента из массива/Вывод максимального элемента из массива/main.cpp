//
//  main.cpp
//  Вывод максимального элемента из массива
//
//  Created by Станислав Егоров on 30.10.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
int size1 = 5;
int maxdigit = 0;
void fillarray (int array [], int size)
{
    for(int i = 0; i < size; i++){
            array [i] = rand() % 100 + 100;
    }
    int maxdigit = array [0];
}
void printarray (int array [], int size)
{
    for (int i = 0; i < size; i++)
    {
        maxdigit = INT_MIN;
            printf("%3d ", array[i]);
            if(array[i]>maxdigit)
            {
                maxdigit = array[i];
            }
                
            }
        cout << " | " << maxdigit << endl;;
        }
                


int main()
{
    int array [size1];
    srand(time(0));
    fillarray(array, size1);
    printarray(array, size1);
}
