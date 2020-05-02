/*
#include <iostream>
#include "queueT.h"
#include <queue>
#include <stdexcept>
#include <cassert>

using namespace std;

enum Commands
{
    ADD = 1, //�������� ������� � �������.
    DELETE = 2, //�������  ������� � �������.
    SHOW = 3, //�������� ������� �� �������.
    SHOW_ALL, // �������� ��� ������� � �������.
    EXIT,
};

int main() {
    setlocale(LC_ALL, "rus");
    int M;
    double a;
    int command;
    cout << "����� ������������ ���������� ���������:";
    queueT <double> Q1;
    cin >> M;
    Q1.selectM(M);

    while (true) {
        cout << "1.�������� ������� � �������. " << endl;
        cout << "2.������� �������. " << endl;
        cout << "3.�������� ������ ������� �� �������. " << endl;
        cout << "4.�������� ��� ������� � �������. " << endl;
        cout << "5.����� �� ���������. " << endl;
        cin >> command;
        cout << endl;

        switch (command) {
        case ADD:
        { cout << "����� �������:";
        cin >> a;
        Q1.push(a);
        break;
        }

        case DELETE:
        {
            Q1.clear(); break;
        }
        case SHOW: {
            cout << "������ �������:" << Q1.GetItem();
            break;
        }
        case SHOW_ALL: {
            Q1.print("Q1");
            break;
        }
        case EXIT:
            return 0;
        default:
            cout << "����� ������� ���" << endl;
            cout << endl;
            break;

        }
        }



    }
*/