//
//  main.cpp
//  Функция ссылка на вектор с распределением
//
//  Created by Станислав Егоров on 24.11.2023.
//

#include <iostream>
#include <vector>
using namespace std;

// Функция для проверки, является ли число положительным, отрицательным или нулем
string checkNumber(int num) {
  if (num > 0) return "positive";
  if (num < 0) return "negative";
  return "zero";
}

// Функция для распределения элементов вектора по типам
void distributeVector(vector<int>& vec, vector<int>& positive, vector<int>& negative, vector<int>& zero) {
  for (int num : vec) {
      if (checkNumber(num) == "positive") {
          positive.push_back(num);
      }
      else if (checkNumber(num) == "negative") {
          negative.push_back(num);
      }
      else {
          zero.push_back(num);
      }
  }
}

int main() {
  vector<int> vec = {1, -2, 0, 3, -4, 0, 5};
  vector<int> positive, negative, zero;
  distributeVector(vec, positive, negative, zero);
  cout << "Positive numbers: ";
  for (int num : positive) {
      cout << num << " ";
  }
  cout << endl;
  cout << "Negative numbers: ";
  for (int num : negative) {
      cout << num << " ";
  }
  cout << endl;
  cout << "Zeros: ";
  for (int num : zero) {
      cout << num << " ";
  }
  cout << endl;
  return 0;
}
