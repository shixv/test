#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <typename InputIterator, typename Predicate>
	vector<InputIterator>
find_all(InputIterator first, InputIterator last, Predicate pred)
{
	vector<InputIterator> res;
	while(true){
		//Find the next match in the current range.
		first=find_if(first,last,pred);
		//chech if find_if failed to find a match
		if(first==last){
			break;
		}
		//Store this match.
		res.push_back(first);
		//Shorten the range to start at one past the current match
		++first;
	}
	return res;
}
int main(void)
{
	vector<int> a{1,2,3,4,5,6,7,8,9};
	auto b=find_all(a.begin(),a.end(),[](int n){return n>5;});
	for(auto& i:b)
		cout<<*i<<" ";
	cout<<endl;
	return 0;
}
