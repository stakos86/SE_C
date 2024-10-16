//
//  main.cpp
//  Создатель
//
//  Created by Станислав Егоров on 17.06.2024.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CCreature {
protected:
    string mName;
public:
    string Name() { return mName; }
    void Name(string value) { mName = value; }

    CCreature(string n) : mName(n) { };

    void Move() { cout << "Creature with name " << mName << " moved\n"; }
};

string StartNames[3] = { "Семко", "Павдю", "Аули" };
string MiddleNames[3] = { "влюх", "бубон", "пицкос" };
string EndNames[3] = { "илия", "арус", "енций" };

string GetRandomCreatureName(vector<string>& usedNames) {
    string val = "";
    int start, middle, end;
    do {
        start = rand() % 3;
        middle = rand() % 3;
        end = rand() % 3;
        val = to_string(start) + to_string(middle) + to_string(end);
    } while (find(usedNames.begin(), usedNames.end(), val)!= usedNames.end());

    usedNames.push_back(val);
    return StartNames[start] + MiddleNames[middle] + EndNames[end];
}

// Добавьте здесь объявление и определение для Species и Characteristics

class CSpecies {
private:
    vector<CCreature> mCreatures;
    string mName;
public:
    vector<string> usedRandomNames;
    void Name(string value) { mName = value; }
    string Name() { return mName; }

    void Add(CCreature &creature) { mCreatures.push_back(creature); }
    void PrintAll();

    void RandomFill(int n) {
        if (mCreatures.size() >= n) {
            cout << "Cannot fill more than existing creatures.\n";
            return;
        }
        for (int i = 0; i < n - mCreatures.size(); ++i) {
            CCreature creature(GetRandomCreatureName(usedRandomNames));
            Add(creature);
        }
    }
};

void CSpecies::PrintAll() {
    for (CCreature c : mCreatures) {
        cout << Name() << ": " << c.Name() << "\n";
    }
}

int main() {
    srand((unsigned)time(nullptr));

    CSpecies species;
    species.Name("SomeSpecies");
    CCreature creature(GetRandomCreatureName(species.usedRandomNames));
    species.Add(creature);
    species.RandomFill(15);
    species.PrintAll();

    return 0;
}



