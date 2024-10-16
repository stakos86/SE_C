//
//  OnlyHuman.hpp
//  Работа в классе 27.05.24
//
//  Created by Станислав Егоров on 27.05.2024.
//

#ifndef OnlyHuman_hpp
#define OnlyHuman_hpp

#include <stdio.h>
#include <iostream>
class OnlyHuman {
private:
    static OnlyHuman* instance;
public:
    static OnlyHuman* getHuman() {
        if (instance == nullptr) {
            instance = new OnlyHuman();
        }
        return instance;
    }
    void Print() const {
        std::cout << "This is a humanoid." << std::endl;
    }
};
OnlyHuman* OnlyHuman::instance = nullptr;
#endif /* OnlyHuman_hpp */
