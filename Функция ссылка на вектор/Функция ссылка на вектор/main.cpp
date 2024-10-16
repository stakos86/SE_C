//
//  main.cpp
//  Функция ссылка на вектор
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num) {
  if (num <= 1) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (int i = 3; i <= sqrt(num); i += 2) {
      if (num % i == 0) return false;
  }
  return true;
}

// Функция для удаления простых чисел из вектора
vector<int>& removePrimes(vector<int>& vec) {
  for (auto it = vec.begin(); it != vec.end();) {
      if (isPrime(*it)) {
          it = vec.erase(it);
      } else {
          ++it;
      }
  }
  return vec;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5};
  vec = removePrimes(vec);
  for (int num : vec) {
      cout << num << " ";
  }
  cout << endl;
  return 0;
}
