#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool isNumber(const string& s)
{
	auto end=s.end();
	auto it=find_if(s.begin(),end,
			[](char c){return !isdigit(c);});
	return it==end;
}
int main(void)
{
	string str="1221x412904801294";
	cout<<isNumber(str)<<endl;
	return 0;
}
