#include <list>
#include <iostream>
#define FILENAME "prime.dat"
#define ElemType int
using namespace std;

bool isPrime(list<ElemType>& arr,ElemType n)
{
	if(n<2)return false;
	for(auto& i:arr){
		if(i*i>n)break;
		if(n%i==0)return false;
	}
	return true;
}
bool createPrime(ElemType n,list<ElemType>& arr)
{
	if(n<1)
		return NULL;
	arr.clear();
	arr.push_back(2);
	ElemType j=3;
	while(j<=n){
		if(isPrime(arr,j))arr.push_back(j);
		++j;
	}
	return true;
}
int main(int argc,char *argv[])
{
	list<ElemType> array;
	createPrime(atoi(argv[1]),array);
	cout<<array.size()<<endl;
	return 0;
}
