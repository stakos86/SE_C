//
//  main.cpp
//  Указатель на массив 2
//
//  Created by Станислав Егоров on 17.11.2023.
//
/*
 Написать функцию, которая получает указатель на массив и его размер,

     и возвращает
     
количество отрицательных,
положительных и
нулевых элементов массива
 */
#include <iostream>
#include <ctime>
using namespace std;

void calc(int * a, int size, int &neg, int &pos, int &zeros) {
    for(int i = 0; i < size; i++){
        if(a[i] > 0)
            pos++;
        else if(a[i] < 0)
                neg++;
            else if(a[i] == 0)
                zeros++;
    }
}

int main()
{
    srand(time(0));
    int size = 20, posCounter = 0, negCounter = 0, zeroCounter = 0;
    int * arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 50 - 25;
        cout << i << ": " << arr[i] << " | ";
    }
    
    calc(arr, size, posCounter, negCounter, zeroCounter);
    
    cout << "\n\nposCounter: " << posCounter << " | negCounter: " << negCounter <<
            " | zeroCounter: " << zeroCounter;
    
    return 0;
}
