#include "cube.h"
#include <iostream>

using namespace std;
double Cube::getArea(void)
{
	return a*b*2+a*c*2+b*c*2;
}

double Cube::getVolume(void)
{
	return a*b*c;
}

void Cube::setabc(double x,double y,double z)
{
	a=x;
	b=y;
	c=z;
}

void Cube::getabc(double &x,double &y,double &z)
{
	x=a;
	y=b;
	z=c;
}

bool Cube::compare(Cube &cb)
{
	if(cb.a==a&&cb.b==b&&cb.c==c)
		return true;
	return false;
}
void Cube::printabc(void)
{
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}
