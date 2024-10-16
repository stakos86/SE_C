//
//  main.cpp
//  Вася программист
// не работает
//  Created by Станислав Егоров on 24.10.2023.
//

#include <iostream>

using namespace std;

int main() {
    int choice;
    double desiredIncome, desiredSalary, linesOfCode;
    int lateCount;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Calculate lines of code to write\n";
        cout << "2. Calculate how many times Vasya can be late\n";
        cout << "3. Calculate Vasya's salary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the desired income: ";
                cin >> desiredIncome;
                cout << "Enter the number of times late: ";
                cin >> lateCount;
                linesOfCode = (desiredIncome + lateCount * 20) / 50;
                cout << "Vasya needs to write " << linesOfCode << " lines of code.\n";
                break;
            case 2:
                cout << "Enter the number of lines of code: ";
                cin >> linesOfCode;
                cout << "Enter the desired salary: ";
                cin >> desiredSalary;
                lateCount = (linesOfCode * 50 - desiredSalary) / 20;
                cout << "Vasya can be late " << lateCount << " times.\n";
                break;
            case 3:
                cout << "Enter the number of lines of code: ";
                cin >> linesOfCode;
                cout << "Enter the number of times late: ";
                cin >> lateCount;
                double salary = linesOfCode * 50 - lateCount * 20;
                if (salary > 0) {
                    cout << "Vasya will be paid " << salary << " dollars.\n";
                } else {
                    cout << "Vasya will not be paid.\n";
                }
                break;
        }
    }
}
