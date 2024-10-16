//
//  main.cpp
//  Массив с сортировкой пузырьком
//
//  Created by Станислав Егоров on 25.10.2023.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int size = 10;
    int temp = 0;
    int arr[size];
          for (int i = 0; i < size; i++)
    {
        arr [i] = rand () % 90000 + 10000;
        printf ("%d ", arr[i]);
    }
    printf ("\n сортируем\n");
    /*
     1. два цикла от 0 до size
     2. если левое больше правого,
     3. то меняем местами
     
     */
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
            if (arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
   
    }
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
    // и в обратную сторону от большего к меньшему
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
            if (arr[j] < arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
   
    }
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", arr[i]);
    }
    return 0;
}
