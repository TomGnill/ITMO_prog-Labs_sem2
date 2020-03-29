#include <iostream>
#include "lab1zag.h"
#include "complex_los.h"


using namespace std;

void  func1(void) {                                              //Task#1
    int per1, per2;


  cout << "Введите per1:";
    cin >> per1;
    cout << "Введите per2:";
    cin >> per2;
    swap(per1, per2);
    cout << per1 << " " << per2;
};

void func3(void) {                                              //task#9
    double a;

    cout << "Введите вещественное число(формат: x, y):";
    cin >> a;
    a = round(a);
    cout << a << endl;
}

void func4(void) {                                              //task#14
    const int n = 3, m = 3;

    int matrix[n][m];

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Введи элемент [" << i + 1 << "][" << j + 1 << "]:";
            cin >> matrix[i][j];
        }
    };
    int transp_matrix[3][3];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transp_matrix[i][j] = matrix[j][i];

            cout << transp_matrix[i][j] << " ";
        }
        cout << endl;
    }
}