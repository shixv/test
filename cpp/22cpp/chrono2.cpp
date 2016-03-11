#include <iostream>
#include <ratio>
#include <chrono>
using namespace std;
using namespace chrono;
int main(int argc,char* argv[])
{
	auto start=system_clock::now();
	system(argv[1]);
	auto end=system_clock::now();
	cout<<duration<double,ratio<1>>(end-start).count()<<"s"<<endl;
	cout<<time_point<steady_clock>::max().count()<<endl;
	return 0;
}
