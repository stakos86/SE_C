//
//  main.cpp
//  Сортировка массивов
//
//  Created by Станислав Егоров on 27.10.2023.
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
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        arr [i] = rand () % 100 + 100;
        printf ("%d ", arr[i]);
    }
    printf ("\n");
    for (int i = 1; i < size; i++)
    {
        int counter = 0;
        {
            {
                for (int j = 0; j < size-1-i; j++) // -i убирает последнее сравнение
                    if (arr[j] > arr[j+1])
                    {
                        temp = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = temp;
                        counter++;
                    }
                total++;
                if (counter == 0)
                break;
            }
        }
        
        printf ("\n");
        printf ("\n");
    }
    cout << total;
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", arr[i]);
    }
        return 0;

}
