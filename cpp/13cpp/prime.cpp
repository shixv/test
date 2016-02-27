#include <vector>
#include <iostream>
#define ElemType int
using namespace std;

bool isPrime(vector<ElemType>& arr,ElemType n)
{
	if(n<2)
		return false;
	for(auto& i:arr){
		if(i*i>n)
			break;
		if(n%i==0)
			return false;
	}
	return true;
}
bool createPrime(ElemType n,vector<ElemType>& arr)
{
	if(n<1)
		return NULL;
	arr.clear();
	arr.reserve(1000000);
	int count=0;
	arr.push_back(2);
	auto ad=&arr[0];
	ElemType j=3;
	while(j<=n){
		if(isPrime(arr,j))
			arr.push_back(j);
		++j;
		if(ad!=&arr[0]){ad=&arr[0];count++;}
	}
	cout<<count<<endl;
	return true;
}
int main(int argc,char *argv[])
{
	vector<ElemType> array;
	createPrime(atoi(argv[1]),array);
	cout<<array.size()<<endl;
	return 0;
}
