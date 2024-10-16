/*
вводим n

в k записываем случайное число от 0 до n-1

строим двумерный массив размером n*n и заполяем его символом "-"
и столбец с номером k заполяем "*"

*/
#include <iostream>
//#include <ctime>
using namespace std;

int main() {
    int n{8};
//    int m{8};
    char arr[n][n];
/*
    for(int i=0; i < n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i][j] = (i == n || j == m ? '*' : '-');
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
 */
    for (int i = 0; i < n; i++)
         for (int j = 0; i < n; i++)
                if (j >= i)
                   n = "* ";
              else
    cout << " ";
    printf("%c ", arr[n][n]);
    cout << "\n";
    return 0;
}
