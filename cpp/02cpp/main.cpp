#include <iostream>
#include "Circle.h"

using namespace std;

int main(void)
{
	Circle a;
	a.setR(12.0);
	cout<<a.getR()<<a.getArea()<<a.getGirth()<<endl;
	return 0;
}
