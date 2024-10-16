//
//  main.cpp
//  Указатель на динамический массив
//
//  Created by Станислав Егоров on 17.11.2023.
//
/*
 Написать функцию, которая
      
 получает указатель на динамический массив и его размер.
    Функция
 удаляет из массива все отрицательные числа и
 возвращает указатель на новый динамический массив.
 */
int * arrayAnalysis(int * a, int &size) {
    int counterNeg = 0; // <-- количество отрицательных чисел | размер нового массива
    
    /* считаем количество отрицательных элементов */
    for(int i = 0; i < size; i++)
        if(a[i] < 0)
            counterNeg++;
    
    int * b = new int[counterNeg]; // <-- создание нового динамического массива
    
    /* наполняем новый массив отрицательнми элементами исходного массива */
    int j = 0;
    for(int i = 0; i < size; i++)
        if(a[i] < 0) {
            b[j] = a[i];
            j++;
        }
    size = counterNeg;
    return b; // <--- возвращаем нвоый динамический массив
}

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int size = 20;
    int * arr = new int[size];
    
    cout << "Initial array: \n";
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 50 - 25;
        cout << i << ": " << arr[i] << " | ";
    }
    
    int * newArray = arrayAnalysis(arr, size);
    
    cout << "\n\nNew array: \n";
    for(int i = 0; i < size; i++){
        cout << i << ": " << newArray[i] << " | ";
    }
    return 0;
}
