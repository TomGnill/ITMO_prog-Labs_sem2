// lab2.var1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;


class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы

    Complex()
    {

    };

    Complex(double r)
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    Complex(const Complex& c)  
    {
        re = c.re;
        im = c.im;
    }


    // деструктор
    ~Complex()
    {
      
    }

    // алг.функции

    // Модуль 
    double abs()
    {
        return sqrt(re * re + im * im);
    }

    //присваиваниe
    Complex& operator = (Complex& c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }

    //  +=
    Complex& operator += (Complex& c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // сложениe
    Complex operator + (const Complex& c)
    {
        return Complex(re + c.re, im + c.im);
    }

    //  вычитаниe
    Complex operator - (const Complex& c)
    {
        return Complex(re - c.re, im - c.im);
    }

    //  умножениe
    Complex operator * (const Complex& c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // делениe
    Complex operator / (const Complex& c)
    {
        Complex temp;

        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;

        return temp;
    }
    // укажем дружественные операторы, которым мы разрешаем доступ
   // к личным (private) данным
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

};

// перегрузка оператора <<
ostream& operator<< (ostream& out, const Complex& c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}

// перегрузка оператора >>
istream& operator>> (istream& in, Complex& c)
{
    in >> c.re >> c.im;
    return in;
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
