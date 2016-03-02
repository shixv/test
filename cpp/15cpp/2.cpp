#include <iostream>
#include <random>
using namespace std;
int main(void)
{
	random_device rnd;
	cout<<"Entropy: "<<rnd.entropy()<<endl;
	cout<<"Min value: "<<rnd.min()
		<<", Max value: "<<rnd.max()<<endl;
	cout<<"Random number: "<<rnd()<<endl;
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1,99);
	cout<<dist(eng)<<endl;
	return 0;
}
