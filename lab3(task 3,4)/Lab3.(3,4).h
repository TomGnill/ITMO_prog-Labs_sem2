#pragma once
#include<iostream>
#include <cmath>

class matrix;
matrix operator + (const matrix& c);
matrix operator - (const matrix& c);
matrix operator * (const matrix& c);
bool operator == (matrix&, matrix&);
bool operator > (matrix&, matrix&);
bool operator < (matrix&, matrix&);
void operator +=(matrix&, matrix&);


std::ostream& operator<< (std::ostream& out, const matrix& c);
std::istream& operator>> (std::istream& in, matrix& c);
class delta;

std::ostream& operator<< (std::ostream& out, const delta& c);
std::istream& operator>> (std::istream& in, delta& c);
struct vector;
void operator += (const vector& ,delta&);
bool operator < (const delta&, const delta&);
bool operator > (const delta&, const delta&);
bool operator != (const delta& ,const delta&);
bool operator == (const delta& ,const delta&);

