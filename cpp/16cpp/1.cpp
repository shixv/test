#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> squares(100);
	for(size_t i=0;i<squares.size();i++)
		squares[i]=i*i;
	for(size_t i=0;i<squares.size();i++)
		cout<<i<<" "<<squares[i]<<endl;
	return 0;
}
