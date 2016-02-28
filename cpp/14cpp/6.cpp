#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void test01(void)
{
	vector<int> vec={1,2,3,4,5,6,7,8,9};
	int value=3;
	int cntLambdaCalled=0;
	int cnt=count_if(vec.cbegin(),vec.cend(),
			[=,&cntLambdaCalled](int i)->bool{++cntLambdaCalled;return i>value;});
	cout<<"The lambda expression was called "<<cntLambdaCalled
		<<" times. "<<endl;
	cout<<"Found "<<cnt<<" values > "<<value<<endl;
}
void test02(void)
{
	vector<int> v(20);
	int value=1;
	generate(v.begin(),v.end(),[&value]{value*=2;return value;});
	for(auto& i:v)
		cout<<i<<" ";
}
			
int main(void)
{
//	vector<int> vec={1,2,3,4,5,6,7,8,9};
//	int value=3;
//	int cnt=count_if(vec.begin(),vec.end(),
//			[=](int i){return i>value;});
//	cout<<"Found "<<cnt<<" values > "<<value<<endl;
//	test01();
	test02();
	return 0;
}

