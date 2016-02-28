#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
void testCallback(const vector<int>& vec,
		const function<bool(int)>& callback)
{
	for(auto i:vec){
		//Call callback. If it returns false, stop iteration.
		if(!callback(i))
			break;
		//Callback did not stop iteration, so print value
		cout<<i<<" ";
	}
	cout<<endl;
}
function<int(void)> lambdaf(int x)
{
	return [=]()->int{return 2*x;};
}
int main(void)
{
	[]{cout<<"fuck you !!"<<endl;}();
	string result=[](const string& str)->string{return "Hello from "+str;}("second Lambda");
	cout<<"Recult: "<<result<<endl;
	auto fn=[](const string& str){return "Hello from" +str;};
	cout<<fn("call 1")<<endl;
	cout<<fn("call 2")<<endl;
	int a=2;
	int b=3;
	[=]()mutable {int t=a;a=b;b=t;}();
	cout<<a<<" "<<b<<endl;
	auto fn1=lambdaf(5);
	cout<<fn1()<<endl;
	vector<int> vec(10);
	int index=0;
	generate(vec.begin(),vec.end(),[&index]{return ++index;});
	for_each(vec.begin(),vec.end(),[](int i){cout<<i<<" ";});
	cout<<endl;
	testCallback(vec,[](int i){return i<6;});
	return 0;
}
