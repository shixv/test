#include <iostream>

using namespace std;
void print(initializer_list<int> vals)
{
	for(auto p=vals.begin();p!=vals.end();++p)
	{
		cout<<*p<<endl;
	}
}

int main(void)
{
	auto i=40;
	cout<<i<<endl;
	int j{2};
	cout<<j<<endl;
//	int j1{5.0};
	print({1,2,3,4,5});
	return 0;
}
