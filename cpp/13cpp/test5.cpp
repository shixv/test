#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> v{1,2,3,4,5};
	auto it=v.begin()+1;
	v.insert(it,10);
	for(auto& i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<*it<<endl;
	return 0;
}
