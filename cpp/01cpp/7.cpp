#include <iostream>

using namespace std;

int main(void)
{
	const int &re=10000000;
	cout<<sizeof(re)<<endl;
	cout<<&re<<endl;
	return 0;
}
