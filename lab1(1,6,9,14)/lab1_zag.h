#pragma once
#include <iostream>
using namespace std;
void func1(void);

void func2(void);

void func3(void);

void func4(void);

class Complex;

ostream& operator<< (ostream& out, const Complex& c);

istream& operator>> (istream& in, Complex& c);