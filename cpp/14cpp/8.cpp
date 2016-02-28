#include <iostream>
#include <functional>
#include <vector>
using namespace std;
void test01(void)
{
	auto end=myVector.end();
	auto it=find_if(myVector.begin(),end,
			bind(greater_equal<int>(),placeholders::_1,100));
	if(it==end){
		cout<<"No perfect scores"<<endl;
	}else{
		cout<<"Found a \"perfect\" score of "<<*it<<endl;
	}
}
void findEmptyString(const vector<string>& strings)
{
	auto end=strings.end();
	auto it=find_if(strings.begin(),end,
			[](const string& str){return str.empty();});
	//Remaining of function omitted because it is the same as earlier
}
int main(void)
{
	return 0;
}
