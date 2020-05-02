#include "ellipse.h"
#include <corecrt_math_defines.h>
#include <iostream>
const double pi = M_PI;
ellipse::~ellipse() = default;
ellipse::ellipse()
{
	this->ellipse::initFromDialogue();
}
double ellipse::square()
{
    return pi * (a.x * b.x);
}
double ellipse::perimeter()
{
	return 2 * pi * sqrt((pow(a.x,2)+pow(b.x,2)/2));
}
double ellipse::mass() const
{
	return weight;
}
CVector2D ellipse::position() const
{
	return center;
}

bool ellipse::operator==(const IPhysObject & object) const
{
	return mass() == object.mass();
}

bool ellipse::operator<(const IPhysObject & object) const
{
	return mass() < object.mass();
}

void ellipse::draw()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Position: " << center << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "Size: " << size() << std::endl;
	std::cout << std::endl;
}
void ellipse::initFromDialogue()
{
	std::cout << "\t\tAdd center coords: ";
	std::cin >> center;
	std::cout << "\t\t (a)Add the length of the larger half-axis of the ellipse: ";
	std::cin >> a;
	std::cout << "\t\t (b)add the length of the smaller half-axis of the ellipse: ";
	std::cin >> b;
	std::cout << "\t\tAdd weight: ";
	std::cin >> weight;
	std::cout << std::endl;
}
const char* ellipse::className()
{
	return name;
}

unsigned ellipse::size()
{
	return sizeof(*this);
}