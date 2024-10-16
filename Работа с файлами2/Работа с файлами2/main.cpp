//
//  main.cpp
//  Работа с файлами2
//
//  Created by Станислав Егоров on 11.12.2023.
//

#include <iostream>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;
/*

Запроcить размер и сделать массив динамическим.

*/

int main()
{
    srand(time(0));
    int size = 5;
    std::cout << "Enter array size: ";
    std::cin >> size;
    int * arr = new int[size];
    FILE* out;
    const char* path = "outfile.txt";

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    if ((fopen(&out, path, "w")) != NULL)
        cout << "The file could not be created";
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(out, "%3d ", arr[i]);
            fprintf(out, "\n");
        }
        fclose(out);
    }
    return 0;
}
