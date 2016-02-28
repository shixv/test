#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	vector<char> vec(10);
	iota(vec.begin(),vec.end(),'a');
	for(auto& i:vec)cout<<i<<" ";
}
