//
//  main.cpp
//  Оладьи
//
//  Created by Станислав Егоров on 06.11.2023.
// Тут совсем непонятно. Делала нейросеть полностью.

#include <iostream>
#include <vector>
#include <algorithm>

// Функция, меняющая порядок оладий над лопаткой на обратный
void flipPancakes(std::vector<int>& pancakes, int i) {
    int start = 0;
    while (start < i) {
        std::swap(pancakes[start], pancakes[i]);
        start++;
        i--;
    }
}

// Функция, которая сортирует стопку оладий
void sortPancakes(std::vector<int>& pancakes) {
    int n = pancakes.size();
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int max_index = std::max_element(pancakes.begin(), pancakes.begin() + curr_size) - pancakes.begin();
        if (max_index != curr_size - 1) {
            flipPancakes(pancakes, max_index);
            flipPancakes(pancakes, curr_size - 1);
        }
    }
}

int main() {
    std::vector<int> pancakes = {5, 7, 2, 8, 1, 9};
    
    std::cout << "Original stack of pancakes: ";
    for (int pancake : pancakes) {
        std::cout << pancake << " ";
    }
    std::cout << std::endl;
    
    sortPancakes(pancakes);
    
    std::cout << "Sorted stack of pancakes: ";
    for (int pancake : pancakes) {
        std::cout << pancake << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
