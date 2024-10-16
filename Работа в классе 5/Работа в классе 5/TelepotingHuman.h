//
//  TelepotingHuman.h
//  Работа в классе 5
//
//  Created by Станислав Егоров on 29.01.2024.
//

#ifndef TelepotingHuman_h
#define TelepotingHuman_h
#include <iostream>
#include "FlyingHuman.h"
#include "QuackingHuman.h"
class CTelepotingHuman : public CFlyingHuman, public CQuackingHuman
{
public:
    void Teleport() {cout << "I can teleport";}
};

#endif /* TelepotingHuman_h */
