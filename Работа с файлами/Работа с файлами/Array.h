#pragma once
#include<iostream>
using namespace std;

void ShowArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
int GetMax(int* arr, int size) {
    int temp = arr[0];
    for (int i = 1; i < size; i++) {
        if (temp < arr[i])
            temp = arr[i];
    }
    return temp;
}
int GetMin(int* arr, int size) {
    int temp = arr[0];
    for (int i = 1; i < size; i++) {
        if (temp > arr[i])
            temp = arr[i];
    }
    return temp;
}
