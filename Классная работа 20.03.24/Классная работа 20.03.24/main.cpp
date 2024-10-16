#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

class Яблоко {
private:
    string color;
    double weight;

public:
    Яблоко() {
        color = randomColor();
        weight = randomWeight();
    }

    Яблоко(double w, const string& c) : weight(w), color(c) {}

    static string randomColor() {
        string availableColors[] = { "Красный", "Зеленый", "Желтый", "Оранжевый" };
        return availableColors[rand() % 4];
    }

    static double randomWeight() {
        return 150.0 + (rand() % 1000) / 1000.0 * 30.0 - 15.0;
    }

    void printInfo() const {
        cout << "Яблоко: вес = " << weight << " грамм, цвет = " << color << endl;
    }
};

void createAndPrintApples(int count) {
    vector<Яблоко> apples(count);
    for (int i = 0; i < count; ++i) {
        apples[i].printInfo();
    }
}

int main() {

    setlocale(LC_ALL, "");

    srand(time(0));

    auto start = chrono::high_resolution_clock::now();

    createAndPrintApples(1000);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
