#include <iostream>
#include "cube.h"

using namespace std;

int main(void)
{
	Cube a;
	a.setabc(2.0,3.0,4.0);
	Cube b;
	b.setabc(3.0,4.0,5.0);
	double x,y,z;
	a.getabc(x,y,z);
	cout<<x<<y<<z<<endl;
	cout<<a.getArea()<<endl;
	cout<<a.getVolume()<<endl;
	cout<<a.compare(b)<<endl;
	x=3;
	a.printabc();


	return 0;
}
