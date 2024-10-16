//
//  main.cpp
//  Работа в классе 2
//
//  Created by Станислав Егоров on 27.11.2023.
//

/* #include <iostream>
 using namespace std;
 void f1()    // Определение f1.
{
     cout << "Load f1()\n";
 }
 void f2()    // Определение f2.
{
     cout << "Load f2()\n";
 }
int main()
 {
     void (*ptr)(); // ptr — указатель на функцию.
     ptr = f2; // Присваивается адрес f2().
     (*ptr)(); // Вызов f2() по ее адресу.
     ptr = f1; // Присваивается адрес f1().
     (*ptr)(); // Вызов f1() по ее адресу.
     ptr(); // Вызов эквивалентен (*ptr)();
return 0; }
*/


/*
 #include <iostream>
 using namespace std;
 int add(int n, int m)
{
return n + m;
}
 int division(int n, int m)
{
return n / m;
}
 int mult(int n, int m)
{
return n * m; }
 int subt(int n, int m)
{
return n - m; }
int main()
{
    int (*par)(int, int); // Указатель на функцию.
    int a = 6, b = 2;
    char c = '+';
    par = add;
    while (c!= ' ')
    {
        cout << "\n Arguments: a = " << a << ", b = "
        << b;
        cout << ". Result for c = \'" << c << "\':";
        switch (c)
        {
            case '+':
            {
                par = add;
                c = '/';
            }   break;
            case '-':
            {
                par = subt;
                c = ' ';
            }   break;
            case '*':
            {
                par = mult;
                c = '-';
            }   break;
            case '/':
            {
                par = division;
                c = '*';
                break; }
        }
        a = (*par)(a, b);// Вызов по адресу
                 cout << a << "\n";
             }
        return 0; }
*/

/*
 #include <iostream>
 using std::cout;

 int main()
 {
     int m1 = 5,     // <-- количество строк
         m2 = 5,     // <-- количество столбцов
         m3 = 5;     // <-- глубина
         
     int*** pArr = new int** [m1]; // <-- массив указателей на массивы указателей на массивы
     // запускаем цикл по i от 0 до m1 (количество строк)
     for (int i = 0; i < m1; i++){
         pArr[i] = new int*[m2];
         // запускаем цикл по j от 0 до m2 (количество столбцов)
         for(int j = 0; j < m2; j++)
             pArr[i][j] = new int[m3];
     }
     
     pArr[2][2][2] = 17;
     cout << pArr[2][2][2] << "\n";
  
     // удаляем массив массивов массивов
     for(int i = 0; i < m1; i++){
         for(int j = 0; j < m2; j++)
             delete [] pArr[i][j];
         delete [] pArr[i];
     }
     delete[] pArr;
     
     cout << "ok";
     
     return 0;
 }
 */


/*
--------------------------------------------------------
 Добавить в одномерный динамический массив новый элемент

 в начало
 в конец
 в указанную позицию
 */

/*
 #include <iostream>
 using std::cout;

 void PrintArray(int* array, int size) {
     for (size_t i = 0; i < size; i++)
         cout << array[i] << " ";
     cout << "\n";
 }


 int main()
 {
     // нужно вставить элемент в начало
     int* a = new int[5] {1, 2, 3, 4, 5};
     int x = 5;
     cout << "array a: ";
     PrintArray(a, 5);

     int* b = new int[6];

     b[0] = x;
     for (size_t i = 1; i < 6; i++)
     {
         b[i] = a[i - 1];
     }
     cout << "array b: ";
     PrintArray(b, 6);

     // нужно вставить элемент в конец
     int* c = new int[6];
     c[5] = x;
     for (size_t i = 0; i < 5; i++)
     {
         c[i] = a[i];
     }
     cout << "array c: ";
     PrintArray(c, 6);

     // нужно вставить элемент в указанную позицию
     int index = 3;
     int* d = new int[6];


     for (size_t i = 0; i < index; i++)
     {
         d[i] = a[i];
     }
     d[index] = x;
     for (size_t i = index + 1; i < 6; i++)
     {
         d[i] = a[i - 1];
     }

     cout << "array d: ";
     PrintArray(d, 6);

     return 0;
 }
 */

/*
 #include <iostream>
#include <string>


struct Date {
    int day;
    int month;
    std::string monthName;
    int year;
    int weekday;
};

int main() {
    Date date1;
    date1.day = 29;
    date1.month = 11;
    date1.monthName = "November";
    date1.year = 2023;
    date1.weekday = 3;

    Date* date2 = new Date;
    date2->day = 30;
    date2->month = 11;
    date2->monthName = "November";
    date2->year = 2023;
    date2->weekday = 4;

    std::cout << "Date 1: " << date1.day << " " << date1.monthName << " " << date1.year << " Day of the week: " << date1.weekday << std::endl;
    std::cout << "Date 2: " << date2->day << " " << date2->monthName << " " << date2->year << " Day of the week: " << date2->weekday << std::endl;

    delete date2;  // обязательно удалите динамически выделенный объект

    return 0;
}
*/
//----------------------------СТРУКТУРЫ----------------------------
/*
 #include <iostream>

 struct Date {
     int day;
     int month;
     int year;
     int weekDay;
     std::string getMonthName() {
         std::string months[] = { "", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
         if (month >= 1 && month <= 12)
             return months[month];
         else
             return "Неверный номер месяца";
     }

     std::string getWeekDayNameOfDate() {
         std::string months[] = { "", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
         if (weekDay >= 1 && weekDay <= 7)
             return months[month];
         else
             return "Неверный номер дня недели";
     }
 };

 struct Person {
     char name[30];
     Date birthDate;
     Date hireDate;
 };


 std::string getMonthName(int monthNumber) {
     std::string months[] = { "", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
     if (monthNumber >= 1 && monthNumber <= 12)
         return months[monthNumber];
     else
         return "Неверный номер месяца";
 }

 std::string getMonthNameOfDate(Date &date) {
     std::string months[] = { "", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
     if (date.month >= 1 && date.month <= 12)
         return months[date.month];
     else
         return "Неверный номер месяца";
 }

 std::string getWeekDayNameOfDate(Date& date) {
     std::string months[] = { "", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
     if (date.weekDay >= 1 && date.weekDay <= 7)
         return months[date.month];
     else
         return "Неверный номер дня недели";
 }


 int main()
 {
     setlocale(LC_ALL, "");
     Date birthDate{2, 2, 1984, 4};
     Date hireDate{2, 6, 2004, 4};
     Person Nick{ "Nick", birthDate, hireDate };
     std::cout << "birthdate month " << birthDate.getMonthName() <<"\n";
     std::cout << "hiredate month " << getMonthNameOfDate(Nick.hireDate) << "\n";
     std::cout << "birthdate week day name " << Nick.birthDate.getWeekDayNameOfDate() << "\n";
     std::cout << "hiredate week day name " << getWeekDayNameOfDate(Nick.hireDate) << "\n";
 }
 */

/*
 #include <iostream>
#include <string>

struct Dog {
    std::string name;
    std::string breed;
    
    void printdetails() {
        std::cout << "имя: " << name << ", порода: " << breed << std::endl;
    }
    
    void printName() {
        std::cout << "Имя: " << name << std::endl;
    }

    void printBreed() {
        std::cout << "Порода: " << breed << std::endl;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    void setBreed(const std::string& newBreed) {
        breed = newBreed;
    }
};

int main() {
    Dog Sobaka1, Sobaka2;
    Sobaka1.setName("Сосиска");
    Sobaka1.setBreed("Такса");
    Sobaka1.printdetails();
    Sobaka2.setName("Тайсон");
    Sobaka2.setBreed("Боксер");
    Sobaka2.printdetails();
    return 0;
}
*/

/*
 Написать функцию. которая принимает на вход два объекта Dog
 и вводит имя той, в имени и породе которой больше согласных.
 */

#include <iostream>
using std::string;
using std::cout;


struct Dog {
    string name;
    string breed;

    void printName() {
        cout << "Имя: " << name << "\n";
    }

    void printBreed() {
        cout << "Порода: " << breed << "\n";
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    void setBreed(const std::string& newBreed) {
        breed = newBreed;
    }

    void Print() {
        cout << "Имя: " << name << " | Порода: " << breed << "\n";
    }
};


int GetAmountOfConsonantsInStrign(string word) {
    int result = 0; // счётчик согласных
    string s = "BCDFGHJKLMNPQRSTVWXYZ";
    for (auto& symbol : word)
        for (auto& x : s)
            if (symbol == tolower(x))
                result++;
    return result;
}

string MaxConsonantsName(Dog& dog1, Dog& dog2) {
    int dog1Result = 0;
    int dog2Result = 0;
    dog1Result = GetAmountOfConsonantsInStrign(dog1.breed) + GetAmountOfConsonantsInStrign(dog1.name);
    dog2Result = GetAmountOfConsonantsInStrign(dog2.breed) + GetAmountOfConsonantsInStrign(dog2.name);
    return dog1Result > dog2Result ? dog1.name : dog2.name;
}

int main()
{
    setlocale(LC_ALL, "");
    Dog Sobaka1, Sobaka2;

    Sobaka1.setName("Sosika");
    Sobaka1.setBreed("Taxa");
    Sobaka1.Print();

    Sobaka2.setName("Tyson");
    Sobaka2.setBreed("Boxer");
    Sobaka2.Print();

    cout << "Больше всего согласных в имени и породе собаки по имени: " << MaxConsonantsName(Sobaka1, Sobaka2);
}
