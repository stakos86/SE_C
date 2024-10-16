//
//  main.cpp
//  Стэк Яблоко с измерителем
//
//  Created by Станислав Егоров on 20.03.2024.
//

#include <iostream>
#include <stack>
#include <chrono>

// Класс измеритель времени
class TimeMeasure {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

public:
    void Start() {
        start = std::chrono::high_resolution_clock::now();
    }

    void Stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    double Duration() {
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        return duration.count();
    }
};

int main() {
    TimeMeasure timer;
    std::stack<int> appleStack;

    timer.Start(); // Начало измерения

    // Создание стека из 1000 яблок
    for (int i = 0; i < 1000; ++i) {
        appleStack.push(i);
    }

    timer.Stop(); // Конец измерения

    std::cout << "Время создания стека: " << timer.Duration() << " микросекунд\n";

    timer.Start();
    // Вывод стека на экран
    std::cout << "Содержимое стека:\n";
    while (!appleStack.empty()) {
        std::cout << appleStack.top() << " ";
        appleStack.pop();
    }
    std::cout << std::endl;
    timer.Stop(); // Конец измерения
    
    std::cout << "Время вывода стека на экран: " << timer.Duration() << " микросекунд\n";

    return 0;
}
