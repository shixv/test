#include <iostream>
#include <ctime>

void wait(double secs);
int main(void)
{
	using namespace std;
	cout<<"Enter the delay timem in seconds: ";
	float secs;
	cin>>secs;
	cout<<"starting\a\n";
	wait(secs);
	cout<<"done.\a\n";
	return 0;
}

void wait(double secs)
{
	clock_t delay=secs*CLOCKS_PER_SEC;
	clock_t start=clock();
	while(clock()-start<delay);
}
