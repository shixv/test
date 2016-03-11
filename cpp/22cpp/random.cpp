#include <iostream>
#include <random>
using namespace std;
int main(void)
{
	random_device rnd;
	cout<<"entropy: "<<rnd.entropy()<<endl;
	cout<<"Min value: "<<rnd.min()
		<<", Max value: "<<rnd.max()<<endl;
	cout<<"Random number: "<<rnd()<<endl;
	return 0;
}
