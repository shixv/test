#include <tuple>
#include <iostream>
using namespace std;
int main(void)
{
	typedef tuple<int,bool,char> HEHE;
	HEHE a(1,true,'a');
	cout<<get<0>(a)<<endl;
	cout<<get<1>(a)<<endl;
	cout<<get<2>(a)<<endl;
	return 0;
}
