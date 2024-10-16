//
//  main.cpp
//  Работа в классе
//
//  Created by Станислав Егоров on 22.11.2023.
//
/*
 Задание 1.

 Создать массив символов без размера
 Создать массив символов с указанным размером
 Создать указатель на массив символов

 Присвоить им строки

 И вывести их на экран.
 */

/*
 #include <iostream>
using namespace std;

int main() {
    char arr1 [] = {'h', 'e', 'l', 'l', 'o'};
    char arr2 [6] = {'w', 'o', 'r', 'l', 'd'};
    //char *arr1 [5];
    cout << arr1 << endl;
    cout << arr2 << endl;
    
    return 0;
}
*/
/*
 Задание 2.

 Создать символьный массив.
 Запросит ьего ввод на экране
 Прочитать строку функцией gets()
 Вывести стркоу на экран циклом for
 */

/*
 #include <iostream>
#include <cstdio>
using namespace std;

int main() {
   char arr1 [128];
    fgets (arr1, 128, stdin);
    /*
    for (int i = 0; i <= 128; i++)
        cout << arr1 [i];
    */
//    fputs (arr1, stdout);
  //  cout << "\n" << strlen (arr1) - 1;
 //  return 0;
// }
/*
 Задание 3.

 Создать символьный массив размером 50 и сохранить в него строку "Hello "
 Создать символьный массив размером 25 и сохранит ьв него строку "World"
 Соединить эти строки функцией strcat();
 и вывести первый массив на экран функцией fputs();
 */
/*
 #include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char arr1 [50] = "Hello ";
    char arr2 [25] = "World";
    fputs (strcat (arr1, arr2), stdout);
    cout << endl;
    //cout << "\n" << strcat (arr1, arr2) << endl;
    return 0;
    
}
*/

/*
 
 */

#include <iostream>
 #include <string>
 #include <cstdio>
 using namespace std;
 int main()
 {
     char *filename = new char[128];
     cout << "Enter name of file: ";
     fgets (filename, 128, stdin);
     cout << "\nName of file: " << filename << "\n";
     if (strchr (filename,'.'))
         cout << "";
         else {
             cout << "Name has extension" << "\n";
             strcat (filename,".TXT");}
     cout << "Name of file: " << filename << "\n";
     delete [] filename;
}
