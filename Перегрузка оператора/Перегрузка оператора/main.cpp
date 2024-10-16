//
//  main.cpp
//  Перегрузка оператора
//
//  Created by Станислав Егоров on 12.02.2024.
//

#include <iostream>
using namespace std;
class CFraction {
    int nominator;
    int denominator;
public:
    CFraction (int n, int d) : nominator(n), denominator(d) {}
    CFraction () : CFraction (1, 1) {};
    ~CFraction () {};
    
    int Nominator () const {return nominator;}
    int Denominator () const {return denominator;}
    void Print () {cout << nominator << "/" << denominator << "\n";}
    friend bool operator==(const CFraction& fr1, const CFraction& fr2) {
        return fr1.Nominator() == fr2.Nominator() && fr1.Denominator() == fr2.Denominator();
    }
};



    int main() {
        CFraction fr1 (4, 5);
        CFraction fr2 (5, 5);
        cout << (fr1 == fr2 ? "true" : "false") << endl;
        return 0;
    }
