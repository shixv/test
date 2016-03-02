#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	template<typename T>
void Shellsort(vector<T>& source,vector<int>& gap)
{
	sort(gap.begin(),gap.end(),[](T a,T b)->bool{return a>b;});
	for(auto& i:gap){
		for(int j=i;j<source.size();j++){
			T tmp=source[j];
			int k=j;
			for(;k>=i&&tmp<source[k-i];k-=i)
				source[k]=source[k-i];
			source[k]=tmp;
		}
	}
}
int main(void)
{
	vector<int> gap{1,3,5,7,9};
	vector<int> source{9,2,4,2,3,5,7,5,4,2};
	Shellsort(source,gap);
	for(auto& i:gap)
		cout<<i<<" ";
	cout<<endl;
	for(auto& i:source)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
