//
//  main.cpp
//  Функция работы с динамическим массивом
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
using std::cout;

int main()
{
    int m1 = 5,     // <-- количество строк
        m2 = 5,     // <-- количество столбцов
        m3 = 5;     // <-- глубина
        
    int*** pArr = new int** [m1]; // <-- массив указателей на массивы указателей на массивы
    // запускаем цикл по i от 0 до m1 (количество строк)
    for (int i = 0; i < m1; i++){
        pArr[i] = new int*[m2];
        // запускаем цикл по j от 0 до m2 (количество столбцов)
        for(int j = 0; j < m2; j++)
            pArr[i][j] = new int[m3];
    }
    
    pArr[2][2][2] = 17;
    cout << pArr[2][2][2] << "\n";
 
    // удаляем массив массивов массивов
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < m2; j++)
            delete [] pArr[i][j];
        delete [] pArr[i];
    }
    delete[] pArr;
    
    cout << "ok";
    
    return 0;
}
