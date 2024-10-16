//
//  main.cpp
//  Указатель на массив
//
//  Created by Станислав Егоров on 17.11.2023.
//
/*
 Написать функцию, которая получает указатель на массив и его размер,
      и возвращает сумму и произведение его элементов в двух
      параметрах-указателях.
 */

#include <iostream>
#include <ctime>
using namespace std;

void calc(int * a, int size, int &sum, int &mul) {
    for(int i = 0; i < size; i++){
        sum += a[i];
        mul *= a[i];
    }
}

int main()
{
    int size = 10, sum = 0, mul = 1;
    int * arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 7 + 1;
        cout << i << ": " << arr[i];
    }
    
    calc(arr, size, sum, mul);
    
    cout << "\nsum: " << sum << " | mul: " << mul;
    
    return 0;
}
