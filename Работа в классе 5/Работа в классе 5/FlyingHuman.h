//
//  FlyingHuman.h
//  Работа в классе 5
//
//  Created by Станислав Егоров on 29.01.2024.
//

#ifndef FlyingHuman_h
#define FlyingHuman_h
#include <iostream>
#include "BaseHuman.h"
class CFlyingHuman: public CBaseHuman
{
public:
    void Fly() {cout << "I can fly";}
};



#endif /* FlyingHuman_h */
