#include <limits>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
void print(int n)
{
	cout<<n<<" ";
}
int main(void)
{
#if 0
	vector<double> doubleVector(10);
	//Initialize max to smallest number
	double max=numeric_limits<double>::lowest();
	cout<<max<<endl;
	for(size_t i=0;i<10;i++){
		doubleVector[i]=0.0;
	}
	for(size_t i=0;i<10;i++){
		cout<<"Enter score "<<i+1<<": ";
		cin>>doubleVector[i];
		if(doubleVector[i]>max){
			max=doubleVector[i];
		}
	}
	max/=100.0;
	for(size_t i=0;i<10;i++){
		doubleVector[i]/=max;
		cout<<doubleVector[i]<<" ";
	}
#endif
	shared_ptr<vector<int>> pVec(new vector<int>(10));
	pVec->assign(10,5);	
	cout<<*(pVec->begin())<<endl;
	for_each(pVec->begin(),pVec->end(),print);
	cout<<endl;
	for(auto& i:*pVec)cout<<i<<" ";
	cout<<endl;
	cout<<"------------------------"<<endl;

	vector<int> vOne(10,0);
	vector<int> vTwo(10,0);
	if(vOne==vTwo){
		cout<<"equal!"<<endl;
	}else{
		cout<<"not equal"<<endl;
	}
	vOne[3]=50;
	if(vOne>vTwo){
		cout<<"One>Two"<<endl;
	}else{
		cout<<"One<Two"<<endl;
	}

	return 0;
}
