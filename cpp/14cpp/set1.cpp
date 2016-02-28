#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class Greater{
	public:
		bool operator()(int a,int b)const{return a>b;}
};
int main(void)
{
	set<int,Greater> s{2,3,4,5,6,7,8,9,10};
	for_each(s.begin(),s.end(),[&](int n){cout<<n<<" ";});
	return 0;
}
