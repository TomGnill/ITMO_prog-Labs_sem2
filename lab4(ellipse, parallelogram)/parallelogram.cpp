#include "parallelogram.h"
#include <iostream>
parallelogram::~parallelogram() = default;
parallelogram::parallelogram()
{
	this->parallelogram::initFromDialogue();
}
double parallelogram::square()
{
	return (D.x-A.x)*(B.y-A.y);
}
double parallelogram::perimeter()
{
	return 2 * sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2)) + sqrt(pow((D.x - B.x), 2) + pow((D.y - B.y), 2));
}
double parallelogram::mass() const
{
	return weight;
}
CVector2D parallelogram::position() const
{
	CVector2D center;
	center.x = (A.x + B.x + C.x+B.x) / 4;
	center.y = (A.y + B.y + C.y+B.y) / 4;
	return center;
}

bool parallelogram::operator==(const IPhysObject & object) const
{
	return mass() == object.mass();
}

bool parallelogram::operator<(const IPhysObject & object) const
{
	return mass() < object.mass();
}
void parallelogram::draw()

{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Position: " << position() << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "Size: " << size() << std::endl;
	std::cout << std::endl;
}

void parallelogram::initFromDialogue()
{
	std::cout << "\t\tAdd a coords: ";
	std::cin >> A;
	std::cout << "\t\tAdd b coords: ";
	std::cin >> B;
	std::cout << "\t\tAdd c coords: ";
	std::cin >> C;
	std::cout << "\t\tAdd d coords: ";
	std::cin >> D;
	std::cout << "\t\tAdd weight: ";
	std::cin >> weight;
}

const char* parallelogram::className()
{
	return name;
}

unsigned parallelogram::size()
{
	return sizeof(*this);
}