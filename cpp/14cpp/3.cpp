#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
	int num;
	vector<int> myVector;
	while(true){
		cout<<"Enter a number to add (0 to stop): ";
		cin>>num;
		if(num==0){
			break;
		}
		myVector.push_back(num);
	}
	while(true){
		cout<<"Enter a number to lookup (0 to stop): ";
		cin>>num;
		if(num==0){
			break;
		}
		auto end=myVector.end();
		auto it=find(myVector.begin(),end,num);
		if(it==end){
			cout<<"Could not find "<<num<<endl;
		}else{
			cout<<"Found "<<*it<<endl;
		}
	}
	return 0;
}
