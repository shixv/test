#include <iostream>
#include <ratio>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace chrono;
int main(void)
{
	minutes m(1);
	seconds s(m);
//	cout<<s.count()<<endl;
	system_clock::time_point tpoint=system_clock::now();
	time_t tt=system_clock::to_time_t(tpoint);
	tm* t=localtime(&tt);
	cout<<put_time(t,"%H:%M:%S")<<endl;
	return 0;
}
