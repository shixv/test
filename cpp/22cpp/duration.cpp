#include <iostream>
#include <ratio>
#include <chrono>
using namespace std;
using namespace chrono;
int main(void)
{
	duration<long,ratio<60>> d1(123);
	cout<<d1.count()<<endl;

	duration<double> d2;
	d2=d2.min();
	cout<<d2.count()<<endl;

	duration<long,ratio<60>> d3(10);
	duration<long,ratio<1>> d4(14);

	if(d3>d4)
		cout<<"d3>d4"<<endl;
	else
		cout<<"d3<=d4"<<endl;

	++d4;
	d4*=2;
	cout<<d4.count()<<endl;
	
	return 0;
}
