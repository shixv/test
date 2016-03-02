#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1,99);
	auto gen=std::bind(dist,eng);
	vector<int> vec(10);
	generate(vec.begin(),vec.end(),gen);
	for(auto& i:vec)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
