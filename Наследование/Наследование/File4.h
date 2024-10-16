//
//  File4.h
//  Наследование
//
//  Created by Станислав Егоров on 24.01.2024.
//

#ifndef File4_h
#define File4_h

#pragma once
#include <string>

using namespace std;

class Cwallet
{
    string mName;
    double mAmount;

public:
    Cwallet();
    ~Cwallet();

    double Amount() { return mAmount; }

private:

};

Cwallet::Cwallet()
{
    cout << "Объект создался";
}

Cwallet::~Cwallet()
{
    cout << "Объект удалился";
}
#endif /* File4_h */
