//
//  main.cpp
//  Занятие1
//
//  Created by Станислав Егоров on 23.10.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int mas[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i=9; i>=0; i--)
    {
        printf ("%d: %.d\n", i, mas[i]);
        //cout << i << ": " << mas[i] << endl; то же самое
    }
}
