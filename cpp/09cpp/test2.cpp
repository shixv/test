#include <iostream>
#include <memory>

using namespace std;

template<class T>
T ai(T a){return a;}
int main(void)
{
	cout<<ai(9384L)<<endl;
	return 0;
}
