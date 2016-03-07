#include <iostream>
#include <ios>
#include <iomanip>
#include <chrono>
using namespace std;
int main(void)
{
	int i=1234;
	cout<<"This should be '***123': "<<setfill('*')<<setw(6)<<i<<endl;
	cout<<setfill(' ');

	double db1=1.452;
	double db12=5;
	cout<<"This should be ' 5': "<<setw(2)<<noshowpoint<<db12<<endl;
	cout<<"This should be @@1.452: "<<setw(7)<<setfill('@')<<db1<<endl;

	cout.imbue(locale(""));
	cout<<"This is 1234567 formated according to your location: "<<1234567<<endl;

	cout<<"This should be a money amount of 1200, "
		<<"formatted according to your location: "
		<<put_money("120000")<<endl;

	time_t tt;
	time(&tt);
	tm t;
	t=*(localtime(&tt));
	cout<<"This should be the current date and time "
		<<"formatted according to your location: "
		<<put_time(&t,"%c")<<endl;
	return 0;
}
