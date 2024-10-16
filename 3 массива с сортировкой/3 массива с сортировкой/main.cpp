//
//  main.cpp
//  Создать три (4) массива из 10, 20 и 30 (4) целых чисел, заполнить их случайными числами. && Написать функцию ,которая принимает имя массива и его размер, и сортирует его методом супер пузырька
//
//  Created by Станислав Егоров on 30.10.2023.
//

#include <iostream>
#include <ctime>
using namespace std;
int total;
void printArray(int array[], int size) {
    for(int i = 0; i < size; i++)
        printf("[%d]: %d ", i, array[i]);
    printf ("\n\n");
}

void fillArray(int array[], int size) {
    for(int i = 0; i < size; i++)
        array[i] = rand() % 10;
    
}

void fillAndPrintArray(int array[], int size)
{
    fillArray(array, size);
    printArray(array, size);
}
void puzirkoff (int array [], int size)
                {
                    for (int i = 0; i < size-1; i++)
                    {
                        int counter = 0;
                        {
                            {
                                for (int j = 0; j < size-1-i; j++) // -i убирает последнее сравнение
                                    if (array[j] > array[j+1])
                                    {
                                        int temp;
                                        temp = array[j+1]; // можно использовать swap
                                        array[j+1] = array[j];
                                        array[j] = temp;
                                        counter++;
                                    }
                                total++;
                                if (counter == 0)
                                break;
                            }
                        }
                        
                        printf ("\n");
                    }
    cout << "Сравнений: " << total << "\n";
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", array[i]);
    }
                }
int main()
{
    int sizeA = 10,
        sizeB = 20,
        sizeC = 30,
        sizeD = 4;
        
    int a[sizeA],
        b[sizeB],
        c[sizeC],
        d[sizeD];
        
    srand(time(0));
    
    fillAndPrintArray(a, sizeA);
    fillAndPrintArray(b, sizeB);
    fillAndPrintArray(c, sizeC);
    fillAndPrintArray(d, sizeD);
    puzirkoff (a, sizeA);
    return 0;
}
