#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test01(void)
{
	vector<int> vec={11,22,33,44};
	int index=0;
	for_each(vec.begin(),vec.end(),
			[&index](int i){cout<<"Value "<<(index++)<<": "<<i<<endl;});
}
int main(void)
{
	test01();
	return 0;
}
