#include "Circle.h"

void Circle::setR(double r)
{
	R=r;
}

double Circle::getR()
{
	return R;
}

double Circle::getArea()
{
	return R*R*3.14;
}

double Circle::getGirth()
{
	return 2*3.14*R;
}
