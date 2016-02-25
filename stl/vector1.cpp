#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v;
	int *addr=&v[0];
	int count=0;
//	v.reserve(100000);
	for(int i=0;i<100000;i++)
	{
		v.push_back(i);
		if(addr!=&v[0])
		{
			count++;
			addr=&v[0];
		}
	}
	cout<<count<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
}
