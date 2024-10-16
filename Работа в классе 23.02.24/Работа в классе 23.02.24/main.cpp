//
//  main.cpp
//  Работа в классе 23.02.24
//
//  Created by Станислав Егоров on 23.02.2024.
//
/*
 Написать шаблон функции для поиска среднего арифметического значений массива.
 */
/*
#include <iostream>
using namespace std;


template <class T, int Size>
void findArithmeticMean(T* arr)
{
    T result = 0;
    for (size_t i = 0; i < Size; i++)
    {
        result += arr[i];
    }
    result /= Size;
    cout <<"Array arithmetic mean: " << result << "\n";
}



int main()
{
    const int size = 5;
    double array[size]{ 50,200,388,4009,58876 };
    double* p = array;
    findArithmeticMean <double, size> (array);
}
*/

/*
 Написать шаблон функции для поиска минимального элемента из двух.

 Проверить на элементах Double, Int, Char и String.
 Задача 2024.02.23.03
 */
/*
#include <iostream>
using namespace std;

template <typename T>
T findMin(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 10;
    int b = 5;
    int min = findMin<int>(a, b);
    cout << "Min: " << min << endl;
    
    double x = 49.5;
    double y = 3.14;
    double minDouble = findMin<double>(x, y);
    cout << "Min double: " << minDouble << endl;
    
    string a1 = "adfg";
    string a2 = "ajhfjgfa";
    string minstring = findMin<string>(a1, a2);
    cout << "Min string: " << minstring << endl;
    
    char x1 = ']';
    char y1 = ')';
    char minchar = findMin<char>(x1, y1);
    cout << "Min char: " << minchar << endl;
    
    return 0;
}
*/

/*
 Описать три примитивных класса
 Point
 Circle
 House

 с минимальным набором параметров, геттерами, сеттерами и выводом на экран.

 Описать шаблон класса для хранения двух массивов объектов двух разных типов. но одного размера.

 Внутри класса описать функцию для заполнения массива случайными значениями. (тут небольшой подвох. надо подумать)
 И описать функцию вывода обоих массивов на экран
 */
/*
#include <iostream>
#include <cstdlib>
#include <ctime>

// Класс Point для представления точек в двумерном пространстве
class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}

    // Геттеры и сеттеры
    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    // Вывод точки на экран
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Класс Circle для представления окружности
class Circle {
private:
    Point center;
    double radius;

public:
    Circle() : center(Point()), radius(0) {}

    Circle(const Point& center, double radius) : center(center), radius(radius) {}

    // Геттеры и сеттеры
    Point getCenter() const {
        return center;
    }

    void setCenter(const Point& center) {
        this->center = center;
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    // Вывод окружности на экран
    void print() const {
        std::cout << "Circle with center ";
        center.print();
        std::cout << "and radius " << radius << std::endl;
    }
};

// Класс House для представления дома
class House {
private:
    int floors;
    int rooms;

public:
    House() : floors(0), rooms(0) {}

    House(int floors, int rooms) : floors(floors), rooms(rooms) {}

    // Геттеры и сеттеры
    int getFloors() const {
        return floors;
    }

    void setFloors(int floors) {
        this->floors = floors;
    }

    int getRooms() const {
        return rooms;
    }

    void setRooms(int rooms) {
        this->rooms = rooms;
    }

    // Вывод дома на экран
    void print() const {
        std::cout << "House with " << floors << " floors and " << rooms << " rooms" << std::endl;
    }
};

// Шаблон класса для хранения двух массивов объектов двух разных типов, но одного размера
template<typename T1, typename T2>
class TwoArrays {
private:
    T1* array1;
    T2* array2;
    int size;

public:
    TwoArrays(int size) : size(size) {
        array1 = new T1[size];
        array2 = new T2[size];
    }

    ~TwoArrays() {
        delete[] array1;
        delete[] array2;
    }

    // Функция для заполнения массивов случайными значениями
    void fillArrays() {
        std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
        for (int i = 0; i < size; i++) {
            array1[i] = static_cast<T1>(std::rand());
            array2[i] = static_cast<T2>(std::rand());
        }
    }

    // Функция вывода обоих массивов на экран
    void printArrays() const {
        for (int i = 0; i < size; i++) {
            std::cout << "Array 1[" << i << "]: ";
            std::cout << array1[i] << std::endl;
            std::cout << "Array 2[" << i << "]: ";
            std::cout << array2[i] << std::endl;
        }
    }
};

int main() {
    // Создаем объекты трех классов
    Point p(5, 10);
    Circle c(Point(0, 0), 5);
    House h(2, 4);

    // Выводим объекты на экран
    p.print();
    c.print();
    h.print();

    // Создаем объект класса TwoArrays с размером 5 и заполняем массивы случайными значениями
    TwoArrays<int, double> arrays(5);
    arrays.fillArrays();

    // Выводим массивы на экран
    arrays.printArrays();

    return 0;
}
*/
/*
 
 */
