/*
#include <iostream>
#include "queueT.h"
#include <queue>
#include <stdexcept>
#include <cassert>

using namespace std;

enum Commands
{
    ADD = 1, //Добавить элемент в очередь.
    DELETE = 2, //Удалить  элемент в очереди.
    SHOW = 3, //Показать элемент из очереди.
    SHOW_ALL, // показать все элменты в очереди.
    EXIT,
};

int main() {
    setlocale(LC_ALL, "rus");
    int M;
    double a;
    int command;
    cout << "Введи максимальное количество элементов:";
    queueT <double> Q1;
    cin >> M;
    Q1.selectM(M);

    while (true) {
        cout << "1.Добавить элемент в очередь. " << endl;
        cout << "2.Удалить очередь. " << endl;
        cout << "3.Показать первый элемент из очереди. " << endl;
        cout << "4.показать все элменты в очереди. " << endl;
        cout << "5.Выход из программы. " << endl;
        cin >> command;
        cout << endl;

        switch (command) {
        case ADD:
        { cout << "Введи элемент:";
        cin >> a;
        Q1.push(a);
        break;
        }

        case DELETE:
        {
            Q1.clear(); break;
        }
        case SHOW: {
            cout << "Первый элемент:" << Q1.GetItem();
            break;
        }
        case SHOW_ALL: {
            Q1.print("Q1");
            break;
        }
        case EXIT:
            return 0;
        default:
            cout << "Такой команды нет" << endl;
            cout << endl;
            break;

        }
        }



    }
*/