// Lab_prog_4.cpp : 
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "Base.h"
#include "parallelogram.h"
#include "ellipse.h"
using namespace std;

enum Commands
{
	ADD = 1, //Добавтить новую фигуру 
	SHOW_ALL, //Показать их
	SUM_PERIMETERS, //Сложить периметры 
	SUM_AREAS,      //Сложить площади 
	CENTRE_MASS,  //Центр масс всей системы 
	MEMORY,     //Память занимаемая всеми экземплярами классов
	SORT,       //Сортировка фигур между сообой по массе 
	EXIT
};
enum Figure
{
	ELLIPSE = 1,
	PARALLELOGRAM = 2,
};
                       
int main() { //Опишем весь функцианал 


	vector<IFigure*> system;
	int command;
	double x, y, sumP, sumS, massAll;
	CVector2D centerMass;

	while (true) {
		cout << "1. Add figure " << endl;
		cout << "2. Show all figures" << endl;
		cout << "3. Sum all perimeters" << endl;
		cout << "4. Sum all areas" << endl;
		cout << "5. System weight center" << endl;
		cout << "6. Show figures memory" << endl;
		cout << "7. Sort" << endl;
		cout << "8. Exit" << endl;
		cout << "Add command: ";
		cin >> command;
		cout << endl;

		switch (command) {
		case ADD:                    //Далее идёт выбор фигуры которую мы хотим добавить, после этого нам будет предложено ввести данные фигуры.
			cout << "\t1. ellipse" << endl;
			cout << "\t2. parallelogram" << endl;
			cout << "\tAdd command: ";
			cin >> command;
			cout << endl;

			switch (command)
			{
			case ELLIPSE:            
				system.push_back(new ellipse());
				break;
			case PARALLELOGRAM:
				system.push_back(new parallelogram());
				break;
			default:
				cout << "\tFigure not found" << endl;
				break;
			}
			break;
		case SHOW_ALL:
			for (auto& figure : system)
				figure->draw();
			break;
		case SUM_PERIMETERS:
			sumP = 0;
			for (auto& figure : system)
				sumP += figure->perimeter();
			cout << "Perimeter system: " << sumP << endl;
			cout << endl;
			break;
		case SUM_AREAS:
			sumS = 0;
			for (auto& figure : system)
				sumS += figure->square();
			cout << "Area system: " << sumS << endl;
			cout << endl;
			break;
		case CENTRE_MASS:
			massAll = 0;
			x = 0;
			y = 0;
			for (auto& figure : system) {
				x += figure->position().x * figure->mass();
				y += figure->position().y * figure->mass();
				massAll += figure->mass();
			}
			centerMass.x = x / massAll;
			centerMass.y = y / massAll;
			cout << "Center weight coords: " << centerMass << endl;
			cout << endl;
			break;
		case MEMORY:
			cout << "Figures memory: ";
			for (auto& figure : system)
				cout << figure->size() << " ";
			cout << endl;
			cout << endl;
			break;
		case SORT:
			sort(system.begin(), system.end(), [](IFigure* x, IFigure* y) {return *x < *y; });
			cout << "Successes" << endl;
			cout << "Figures weight: ";
			for (auto& figure : system)
				cout << figure->mass() << " ";
			cout << endl;
			cout << endl;
			break;
		case EXIT:
			return 0;
		default:
			cout << "Command not found" << endl;
			cout << endl;
			break;
		}
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
